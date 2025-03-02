// RUN: mlir-opt %s -test-transform-dialect-erase-schedule -convert-linalg-to-loops -convert-scf-to-cf -convert-linalg-to-llvm -expand-strided-metadata -lower-affine -convert-arith-to-llvm -convert-scf-to-cf --convert-memref-to-llvm -convert-func-to-llvm -reconcile-unrealized-casts | \
// RUN: mlir-cpu-runner -e main -entry-point-result=void \
// RUN:   -shared-libs=%mlir_lib_dir/libmlir_runner_utils%shlibext \
// RUN: | FileCheck %s

// RUN: mlir-opt %s -test-transform-dialect-interpreter -test-transform-dialect-erase-schedule -convert-linalg-to-loops -convert-scf-to-cf \
// RUN:   -convert-linalg-to-llvm -expand-strided-metadata -lower-affine -convert-arith-to-llvm -convert-scf-to-cf --convert-memref-to-llvm -convert-func-to-llvm -reconcile-unrealized-casts | \
// RUN: mlir-cpu-runner -e main -entry-point-result=void \
// RUN:   -shared-libs=%mlir_lib_dir/libmlir_runner_utils%shlibext \
// RUN: | FileCheck %s

func.func private @printMemrefF32(memref<*xf32>)

// Creates and returns 4-D buffer of size (%s1, %s2, %s3, %s4) filled with the value %f
func.func @alloc_4d_filled_f32(%s1 : index, %s2 : index, %s3 : index, %s4 : index, %f : f32) -> memref<?x?x?x?xf32> {
  %buf = memref.alloc(%s1, %s2, %s3, %s4) : memref<?x?x?x?xf32>
  linalg.fill ins(%f : f32) outs(%buf : memref<?x?x?x?xf32>)
  return %buf : memref<?x?x?x?xf32>
}

func.func @conv_2d_nhwc_hwcf(%arg0: memref<?x?x?x?xf32>, %arg1: memref<?x?x?x?xf32>, %arg2: memref<?x?x?x?xf32>) {
  linalg.conv_2d_nhwc_hwcf {dilations = dense<1> : tensor<2xi64>,
                          strides = dense<1> : tensor<2xi64>}
     ins (%arg0, %arg1: memref<?x?x?x?xf32>, memref<?x?x?x?xf32>)
    outs (%arg2: memref<?x?x?x?xf32>)
  return
}

transform.sequence failures(propagate) {
  ^bb0(%arg1: !pdl.operation):
    %0 = transform.structured.match ops{["linalg.conv_2d_nhwc_hwcf"]} in %arg1 : (!pdl.operation) -> !pdl.operation
    %1, %loops:4 = transform.structured.tile %0 [2, 3, 3, 2] : (!pdl.operation) -> (!pdl.operation, !pdl.operation, !pdl.operation, !pdl.operation, !pdl.operation)
}

func.func @main() {
  %c0 = arith.constant 0 : index
  %c1 = arith.constant 1 : index
  %c3 = arith.constant 3 : index
  %c6 = arith.constant 6 : index
  %c8 = arith.constant 8 : index
  %f10 = arith.constant 10.00000e+00 : f32
  %val = arith.constant 2.00000e+00 : f32
  %zero = arith.constant 0.00000e+00 : f32

  %filter2D_nhwc = call @alloc_4d_filled_f32(%c3, %c3, %c3, %c1, %val) :(index, index, index, index, f32) -> (memref<?x?x?x?xf32>)
  %in2D_nhwc = call @alloc_4d_filled_f32(%c3, %c8, %c8, %c3, %val) : (index, index, index, index, f32) -> (memref<?x?x?x?xf32>)
  %out2D_nhwc = call @alloc_4d_filled_f32(%c3, %c6, %c6, %c1, %zero) : (index, index, index, index, f32) -> (memref<?x?x?x?xf32>)

  memref.store %f10, %in2D_nhwc[%c0, %c0, %c3, %c0] : memref<?x?x?x?xf32>
  call @conv_2d_nhwc_hwcf(%in2D_nhwc, %filter2D_nhwc, %out2D_nhwc) : (memref<?x?x?x?xf32>, memref<?x?x?x?xf32>, memref<?x?x?x?xf32>) -> ()
  %out2D_nhwc_ = memref.cast %out2D_nhwc : memref<?x?x?x?xf32> to memref<*xf32>
  call @printMemrefF32(%out2D_nhwc_): (memref<*xf32>) -> ()

  memref.dealloc %filter2D_nhwc : memref<?x?x?x?xf32>
  memref.dealloc %in2D_nhwc : memref<?x?x?x?xf32>
  memref.dealloc %out2D_nhwc : memref<?x?x?x?xf32>
  return
}

// CHECK:       Unranked Memref {{.*}}
// CHECK-NEXT:  [
// CHECK-SAME:   [
// CHECK-SAME:    [
// CHECK-SAME:     [108],
// CHECK-COUNT-3:  [124],
// CHECK-COUNT-2:  [108]
// CHECK-SAME:    ],
// CHECK-NEXT:    [
// CHECK-COUNT-6:  [108]
// CHECK-SAME:    ],
// CHECK-NEXT:    [
// CHECK-COUNT-6:  [108]
// CHECK-SAME:    ],
// CHECK-NEXT:    [
// CHECK-COUNT-6:  [108]
// CHECK-SAME:    ],
// CHECK-NEXT:    [
// CHECK-COUNT-6:  [108]
// CHECK-SAME:    ],
// CHECK-NEXT:    [
// CHECK-COUNT-6:  [108]
// CHECK-SAME:    ]
// CHECK-SAME:   ],
// CHECK-NEXT:   [
// CHECK-SAME:    [
// CHECK-COUNT-6:  [108]
// CHECK-SAME:    ],
// CHECK-NEXT:    [
// CHECK-COUNT-6:  [108]
// CHECK-SAME:    ],
// CHECK-NEXT:    [
// CHECK-COUNT-6:  [108]
// CHECK-SAME:    ],
// CHECK-NEXT:    [
// CHECK-COUNT-6:  [108]
// CHECK-SAME:    ],
// CHECK-NEXT:    [
// CHECK-COUNT-6:  [108]
// CHECK-SAME:    ],
// CHECK-NEXT:    [
// CHECK-COUNT-6:  [108]
// CHECK-SAME:    ]
// CHECK-SAME:   ],
// CHECK-NEXT:   [
// CHECK-SAME:    [
// CHECK-COUNT-6:  [108]
// CHECK-SAME:    ],
// CHECK-NEXT:    [
// CHECK-COUNT-6:  [108]
// CHECK-SAME:    ],
// CHECK-NEXT:    [
// CHECK-COUNT-6:  [108]
// CHECK-SAME:    ],
// CHECK-NEXT:    [
// CHECK-COUNT-6:  [108]
// CHECK-SAME:    ],
// CHECK-NEXT:    [
// CHECK-COUNT-6:  [108]
// CHECK-SAME:    ],
// CHECK-NEXT:    [
// CHECK-COUNT-6:  [108]
// CHECK-SAME:    ]
// CHECK-SAME:   ]
// CHECK-SAME:  ]
