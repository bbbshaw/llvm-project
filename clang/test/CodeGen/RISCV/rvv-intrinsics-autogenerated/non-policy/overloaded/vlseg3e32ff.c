// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +experimental-zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: @test_vlseg3e32ff_v_f32mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x float>, <vscale x 1 x float>, <vscale x 1 x float>, i64 } @llvm.riscv.vlseg3ff.mask.nxv1f32.i64(<vscale x 1 x float> poison, <vscale x 1 x float> poison, <vscale x 1 x float> poison, ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x float>, <vscale x 1 x float>, <vscale x 1 x float>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x float> [[TMP1]], ptr [[V0:%.*]], align 4
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x float>, <vscale x 1 x float>, <vscale x 1 x float>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x float> [[TMP2]], ptr [[V1:%.*]], align 4
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x float>, <vscale x 1 x float>, <vscale x 1 x float>, i64 } [[TMP0]], 2
// CHECK-RV64-NEXT:    store <vscale x 1 x float> [[TMP3]], ptr [[V2:%.*]], align 4
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x float>, <vscale x 1 x float>, <vscale x 1 x float>, i64 } [[TMP0]], 3
// CHECK-RV64-NEXT:    store i64 [[TMP4]], ptr [[NEW_VL:%.*]], align 4
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg3e32ff_v_f32mf2_m(vfloat32mf2_t *v0, vfloat32mf2_t *v1, vfloat32mf2_t *v2, vbool64_t mask, const float *base, size_t *new_vl, size_t vl) {
  return vlseg3e32ff(v0, v1, v2, mask, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vlseg3e32ff_v_f32m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x float>, <vscale x 2 x float>, <vscale x 2 x float>, i64 } @llvm.riscv.vlseg3ff.mask.nxv2f32.i64(<vscale x 2 x float> poison, <vscale x 2 x float> poison, <vscale x 2 x float> poison, ptr [[BASE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x float>, <vscale x 2 x float>, <vscale x 2 x float>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 2 x float> [[TMP1]], ptr [[V0:%.*]], align 4
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x float>, <vscale x 2 x float>, <vscale x 2 x float>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 2 x float> [[TMP2]], ptr [[V1:%.*]], align 4
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 2 x float>, <vscale x 2 x float>, <vscale x 2 x float>, i64 } [[TMP0]], 2
// CHECK-RV64-NEXT:    store <vscale x 2 x float> [[TMP3]], ptr [[V2:%.*]], align 4
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 2 x float>, <vscale x 2 x float>, <vscale x 2 x float>, i64 } [[TMP0]], 3
// CHECK-RV64-NEXT:    store i64 [[TMP4]], ptr [[NEW_VL:%.*]], align 4
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg3e32ff_v_f32m1_m(vfloat32m1_t *v0, vfloat32m1_t *v1, vfloat32m1_t *v2, vbool32_t mask, const float *base, size_t *new_vl, size_t vl) {
  return vlseg3e32ff(v0, v1, v2, mask, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vlseg3e32ff_v_f32m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, i64 } @llvm.riscv.vlseg3ff.mask.nxv4f32.i64(<vscale x 4 x float> poison, <vscale x 4 x float> poison, <vscale x 4 x float> poison, ptr [[BASE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 4 x float> [[TMP1]], ptr [[V0:%.*]], align 4
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 4 x float> [[TMP2]], ptr [[V1:%.*]], align 4
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, i64 } [[TMP0]], 2
// CHECK-RV64-NEXT:    store <vscale x 4 x float> [[TMP3]], ptr [[V2:%.*]], align 4
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, i64 } [[TMP0]], 3
// CHECK-RV64-NEXT:    store i64 [[TMP4]], ptr [[NEW_VL:%.*]], align 4
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg3e32ff_v_f32m2_m(vfloat32m2_t *v0, vfloat32m2_t *v1, vfloat32m2_t *v2, vbool16_t mask, const float *base, size_t *new_vl, size_t vl) {
  return vlseg3e32ff(v0, v1, v2, mask, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vlseg3e32ff_v_i32mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i32>, <vscale x 1 x i32>, <vscale x 1 x i32>, i64 } @llvm.riscv.vlseg3ff.mask.nxv1i32.i64(<vscale x 1 x i32> poison, <vscale x 1 x i32> poison, <vscale x 1 x i32> poison, ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i32>, <vscale x 1 x i32>, <vscale x 1 x i32>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x i32> [[TMP1]], ptr [[V0:%.*]], align 4
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i32>, <vscale x 1 x i32>, <vscale x 1 x i32>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x i32> [[TMP2]], ptr [[V1:%.*]], align 4
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i32>, <vscale x 1 x i32>, <vscale x 1 x i32>, i64 } [[TMP0]], 2
// CHECK-RV64-NEXT:    store <vscale x 1 x i32> [[TMP3]], ptr [[V2:%.*]], align 4
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x i32>, <vscale x 1 x i32>, <vscale x 1 x i32>, i64 } [[TMP0]], 3
// CHECK-RV64-NEXT:    store i64 [[TMP4]], ptr [[NEW_VL:%.*]], align 4
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg3e32ff_v_i32mf2_m(vint32mf2_t *v0, vint32mf2_t *v1, vint32mf2_t *v2, vbool64_t mask, const int32_t *base, size_t *new_vl, size_t vl) {
  return vlseg3e32ff(v0, v1, v2, mask, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vlseg3e32ff_v_i32m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x i32>, <vscale x 2 x i32>, <vscale x 2 x i32>, i64 } @llvm.riscv.vlseg3ff.mask.nxv2i32.i64(<vscale x 2 x i32> poison, <vscale x 2 x i32> poison, <vscale x 2 x i32> poison, ptr [[BASE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i32>, <vscale x 2 x i32>, <vscale x 2 x i32>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 2 x i32> [[TMP1]], ptr [[V0:%.*]], align 4
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i32>, <vscale x 2 x i32>, <vscale x 2 x i32>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 2 x i32> [[TMP2]], ptr [[V1:%.*]], align 4
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 2 x i32>, <vscale x 2 x i32>, <vscale x 2 x i32>, i64 } [[TMP0]], 2
// CHECK-RV64-NEXT:    store <vscale x 2 x i32> [[TMP3]], ptr [[V2:%.*]], align 4
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 2 x i32>, <vscale x 2 x i32>, <vscale x 2 x i32>, i64 } [[TMP0]], 3
// CHECK-RV64-NEXT:    store i64 [[TMP4]], ptr [[NEW_VL:%.*]], align 4
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg3e32ff_v_i32m1_m(vint32m1_t *v0, vint32m1_t *v1, vint32m1_t *v2, vbool32_t mask, const int32_t *base, size_t *new_vl, size_t vl) {
  return vlseg3e32ff(v0, v1, v2, mask, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vlseg3e32ff_v_i32m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x i32>, <vscale x 4 x i32>, <vscale x 4 x i32>, i64 } @llvm.riscv.vlseg3ff.mask.nxv4i32.i64(<vscale x 4 x i32> poison, <vscale x 4 x i32> poison, <vscale x 4 x i32> poison, ptr [[BASE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i32>, <vscale x 4 x i32>, <vscale x 4 x i32>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 4 x i32> [[TMP1]], ptr [[V0:%.*]], align 4
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i32>, <vscale x 4 x i32>, <vscale x 4 x i32>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 4 x i32> [[TMP2]], ptr [[V1:%.*]], align 4
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 4 x i32>, <vscale x 4 x i32>, <vscale x 4 x i32>, i64 } [[TMP0]], 2
// CHECK-RV64-NEXT:    store <vscale x 4 x i32> [[TMP3]], ptr [[V2:%.*]], align 4
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 4 x i32>, <vscale x 4 x i32>, <vscale x 4 x i32>, i64 } [[TMP0]], 3
// CHECK-RV64-NEXT:    store i64 [[TMP4]], ptr [[NEW_VL:%.*]], align 4
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg3e32ff_v_i32m2_m(vint32m2_t *v0, vint32m2_t *v1, vint32m2_t *v2, vbool16_t mask, const int32_t *base, size_t *new_vl, size_t vl) {
  return vlseg3e32ff(v0, v1, v2, mask, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vlseg3e32ff_v_u32mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i32>, <vscale x 1 x i32>, <vscale x 1 x i32>, i64 } @llvm.riscv.vlseg3ff.mask.nxv1i32.i64(<vscale x 1 x i32> poison, <vscale x 1 x i32> poison, <vscale x 1 x i32> poison, ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i32>, <vscale x 1 x i32>, <vscale x 1 x i32>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x i32> [[TMP1]], ptr [[V0:%.*]], align 4
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i32>, <vscale x 1 x i32>, <vscale x 1 x i32>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x i32> [[TMP2]], ptr [[V1:%.*]], align 4
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i32>, <vscale x 1 x i32>, <vscale x 1 x i32>, i64 } [[TMP0]], 2
// CHECK-RV64-NEXT:    store <vscale x 1 x i32> [[TMP3]], ptr [[V2:%.*]], align 4
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x i32>, <vscale x 1 x i32>, <vscale x 1 x i32>, i64 } [[TMP0]], 3
// CHECK-RV64-NEXT:    store i64 [[TMP4]], ptr [[NEW_VL:%.*]], align 4
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg3e32ff_v_u32mf2_m(vuint32mf2_t *v0, vuint32mf2_t *v1, vuint32mf2_t *v2, vbool64_t mask, const uint32_t *base, size_t *new_vl, size_t vl) {
  return vlseg3e32ff(v0, v1, v2, mask, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vlseg3e32ff_v_u32m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x i32>, <vscale x 2 x i32>, <vscale x 2 x i32>, i64 } @llvm.riscv.vlseg3ff.mask.nxv2i32.i64(<vscale x 2 x i32> poison, <vscale x 2 x i32> poison, <vscale x 2 x i32> poison, ptr [[BASE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i32>, <vscale x 2 x i32>, <vscale x 2 x i32>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 2 x i32> [[TMP1]], ptr [[V0:%.*]], align 4
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i32>, <vscale x 2 x i32>, <vscale x 2 x i32>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 2 x i32> [[TMP2]], ptr [[V1:%.*]], align 4
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 2 x i32>, <vscale x 2 x i32>, <vscale x 2 x i32>, i64 } [[TMP0]], 2
// CHECK-RV64-NEXT:    store <vscale x 2 x i32> [[TMP3]], ptr [[V2:%.*]], align 4
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 2 x i32>, <vscale x 2 x i32>, <vscale x 2 x i32>, i64 } [[TMP0]], 3
// CHECK-RV64-NEXT:    store i64 [[TMP4]], ptr [[NEW_VL:%.*]], align 4
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg3e32ff_v_u32m1_m(vuint32m1_t *v0, vuint32m1_t *v1, vuint32m1_t *v2, vbool32_t mask, const uint32_t *base, size_t *new_vl, size_t vl) {
  return vlseg3e32ff(v0, v1, v2, mask, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vlseg3e32ff_v_u32m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x i32>, <vscale x 4 x i32>, <vscale x 4 x i32>, i64 } @llvm.riscv.vlseg3ff.mask.nxv4i32.i64(<vscale x 4 x i32> poison, <vscale x 4 x i32> poison, <vscale x 4 x i32> poison, ptr [[BASE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i32>, <vscale x 4 x i32>, <vscale x 4 x i32>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 4 x i32> [[TMP1]], ptr [[V0:%.*]], align 4
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i32>, <vscale x 4 x i32>, <vscale x 4 x i32>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 4 x i32> [[TMP2]], ptr [[V1:%.*]], align 4
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 4 x i32>, <vscale x 4 x i32>, <vscale x 4 x i32>, i64 } [[TMP0]], 2
// CHECK-RV64-NEXT:    store <vscale x 4 x i32> [[TMP3]], ptr [[V2:%.*]], align 4
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 4 x i32>, <vscale x 4 x i32>, <vscale x 4 x i32>, i64 } [[TMP0]], 3
// CHECK-RV64-NEXT:    store i64 [[TMP4]], ptr [[NEW_VL:%.*]], align 4
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg3e32ff_v_u32m2_m(vuint32m2_t *v0, vuint32m2_t *v1, vuint32m2_t *v2, vbool16_t mask, const uint32_t *base, size_t *new_vl, size_t vl) {
  return vlseg3e32ff(v0, v1, v2, mask, base, new_vl, vl);
}

