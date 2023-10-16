#define SIMDE_TEST_ARM_NEON_INSN cmla_rot180_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/cmla_rot180_lane.h"
#include "../../../simde/arm/neon/dup_n.h"

static int
test_simde_vcmla_rot180_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float16_t r_[4];
    simde_float16_t a[4];
    simde_float16_t b[4];
    const int lane;
    simde_float16_t r[4];
  } test_vec[] = {
    {
      { SIMDE_FLOAT16_VALUE(   -49.28), SIMDE_FLOAT16_VALUE(  -109.00), SIMDE_FLOAT16_VALUE(  -626.50), SIMDE_FLOAT16_VALUE(  -567.00) },
      { SIMDE_FLOAT16_VALUE(  -178.88), SIMDE_FLOAT16_VALUE(    10.22), SIMDE_FLOAT16_VALUE(  -228.12), SIMDE_FLOAT16_VALUE(   -31.19) },
      { SIMDE_FLOAT16_VALUE(    42.90), SIMDE_FLOAT16_VALUE(   -98.75), SIMDE_FLOAT16_VALUE(   350.00), SIMDE_FLOAT16_VALUE(   -48.00) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(  7624.00), SIMDE_FLOAT16_VALUE(  7564.00), SIMDE_FLOAT16_VALUE(  9160.00), SIMDE_FLOAT16_VALUE(  9224.00) } },
    { { SIMDE_FLOAT16_VALUE(   730.00), SIMDE_FLOAT16_VALUE(   103.12), SIMDE_FLOAT16_VALUE(  -381.25), SIMDE_FLOAT16_VALUE(   898.50) },
      { SIMDE_FLOAT16_VALUE(   293.00), SIMDE_FLOAT16_VALUE(   -14.06), SIMDE_FLOAT16_VALUE(  -137.62), SIMDE_FLOAT16_VALUE(   722.50) },
      { SIMDE_FLOAT16_VALUE(    -6.33), SIMDE_FLOAT16_VALUE(    61.38), SIMDE_FLOAT16_VALUE(   115.50), SIMDE_FLOAT16_VALUE(    70.38) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(-17248.00), SIMDE_FLOAT16_VALUE(-17872.00), SIMDE_FLOAT16_VALUE(  8064.00), SIMDE_FLOAT16_VALUE(  9344.00) } },
    { { SIMDE_FLOAT16_VALUE(  -210.88), SIMDE_FLOAT16_VALUE(  -430.75), SIMDE_FLOAT16_VALUE(   725.50), SIMDE_FLOAT16_VALUE(  -944.50) },
      { SIMDE_FLOAT16_VALUE(   142.00), SIMDE_FLOAT16_VALUE(  -966.00), SIMDE_FLOAT16_VALUE(  -131.50), SIMDE_FLOAT16_VALUE(   462.50) },
      { SIMDE_FLOAT16_VALUE(   -61.00), SIMDE_FLOAT16_VALUE(   185.62), SIMDE_FLOAT16_VALUE(    60.47), SIMDE_FLOAT16_VALUE(   749.50) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(  8448.00), SIMDE_FLOAT16_VALUE(  8232.00), SIMDE_FLOAT16_VALUE( -7296.00), SIMDE_FLOAT16_VALUE( -8968.00) } },
    { { SIMDE_FLOAT16_VALUE(    89.44), SIMDE_FLOAT16_VALUE(  -200.50), SIMDE_FLOAT16_VALUE(  -136.50), SIMDE_FLOAT16_VALUE(  -180.50) },
      { SIMDE_FLOAT16_VALUE(  -157.12), SIMDE_FLOAT16_VALUE(   129.00), SIMDE_FLOAT16_VALUE(    99.06), SIMDE_FLOAT16_VALUE(   -75.25) },
      { SIMDE_FLOAT16_VALUE(    32.59), SIMDE_FLOAT16_VALUE(   239.50), SIMDE_FLOAT16_VALUE(   -29.96), SIMDE_FLOAT16_VALUE(  -177.50) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( 37728.00), SIMDE_FLOAT16_VALUE( 37440.00), SIMDE_FLOAT16_VALUE(-23856.00), SIMDE_FLOAT16_VALUE(-23904.00) } },
    { { SIMDE_FLOAT16_VALUE(   167.25), SIMDE_FLOAT16_VALUE(    -1.52), SIMDE_FLOAT16_VALUE(   -63.38), SIMDE_FLOAT16_VALUE(    57.00) },
      { SIMDE_FLOAT16_VALUE(   191.75), SIMDE_FLOAT16_VALUE(  -197.00), SIMDE_FLOAT16_VALUE(   285.00), SIMDE_FLOAT16_VALUE(  -529.00) },
      { SIMDE_FLOAT16_VALUE(   -80.50), SIMDE_FLOAT16_VALUE(   375.50), SIMDE_FLOAT16_VALUE(  -206.00), SIMDE_FLOAT16_VALUE(   -75.25) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE( 15600.00), SIMDE_FLOAT16_VALUE( 15432.00), SIMDE_FLOAT16_VALUE( 22880.00), SIMDE_FLOAT16_VALUE( 22992.00) } },
    { { SIMDE_FLOAT16_VALUE(   -31.19), SIMDE_FLOAT16_VALUE(   -75.25), SIMDE_FLOAT16_VALUE(   -41.00), SIMDE_FLOAT16_VALUE(   285.00) },
      { SIMDE_FLOAT16_VALUE(    -1.52), SIMDE_FLOAT16_VALUE(    10.22), SIMDE_FLOAT16_VALUE(  -271.25), SIMDE_FLOAT16_VALUE(  -257.50) },
      { SIMDE_FLOAT16_VALUE(   -31.45), SIMDE_FLOAT16_VALUE(  -180.50), SIMDE_FLOAT16_VALUE(    69.62), SIMDE_FLOAT16_VALUE(   131.38) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(  -305.50), SIMDE_FLOAT16_VALUE(  -349.50), SIMDE_FLOAT16_VALUE(-48992.00), SIMDE_FLOAT16_VALUE(-48672.00) } },
    { { SIMDE_FLOAT16_VALUE(   205.75), SIMDE_FLOAT16_VALUE(  -247.00), SIMDE_FLOAT16_VALUE(    60.47), SIMDE_FLOAT16_VALUE(    17.94) }, 
      { SIMDE_FLOAT16_VALUE(  -397.75), SIMDE_FLOAT16_VALUE(   166.12), SIMDE_FLOAT16_VALUE(  -110.75), SIMDE_FLOAT16_VALUE(    18.20) },
      { SIMDE_FLOAT16_VALUE(    89.81), SIMDE_FLOAT16_VALUE(    59.75), SIMDE_FLOAT16_VALUE(  -113.25), SIMDE_FLOAT16_VALUE(    97.31) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE( 35936.00), SIMDE_FLOAT16_VALUE( 35488.00), SIMDE_FLOAT16_VALUE( 10008.00), SIMDE_FLOAT16_VALUE(  9968.00) } },
    { { SIMDE_FLOAT16_VALUE(  -869.50), SIMDE_FLOAT16_VALUE(  -710.00), SIMDE_FLOAT16_VALUE(   457.25), SIMDE_FLOAT16_VALUE(   579.00) },
      { SIMDE_FLOAT16_VALUE(   226.38), SIMDE_FLOAT16_VALUE(   178.88), SIMDE_FLOAT16_VALUE(   181.75), SIMDE_FLOAT16_VALUE(  -151.12) },
      { SIMDE_FLOAT16_VALUE(   121.50), SIMDE_FLOAT16_VALUE(   -78.44), SIMDE_FLOAT16_VALUE(    48.06), SIMDE_FLOAT16_VALUE(    75.88) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( 16880.00), SIMDE_FLOAT16_VALUE( 17040.00), SIMDE_FLOAT16_VALUE( 14712.00), SIMDE_FLOAT16_VALUE( 14832.00) } }
    
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t r_ = simde_vld1_f16(test_vec[i].r_);
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float16x4_t r;
    SIMDE_CONSTIFY_2_(simde_vcmla_rot180_lane_f16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f16(SIMDE_FLOAT16_VALUE(0.0))), test_vec[i].lane, r_, a, b);
    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
    
    // simde_float16x4_t r = simde_vcmla_rot180_lane_f16(r_, a, b, test_vec[i].lane);
    // simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  
  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t r_ = simde_test_arm_neon_random_f16x4(-1000.0f, 1000.0f);
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-1000.0f, 1000.0f);
    simde_float16x4_t b = simde_test_arm_neon_random_f16x4(-1000.0f, 1000.0f);
    simde_float16x4_t r = simde_vcmla_rot180_lane_f16(r_, a, b, lanes[i]);


    simde_test_arm_neon_write_f16x4(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmla_rot180_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t r_[2];
    simde_float32_t a[2];
    simde_float32_t b[2];
    const int lane;
    simde_float32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    83.21), SIMDE_FLOAT32_C(   417.90) },
      { SIMDE_FLOAT32_C(  -875.72), SIMDE_FLOAT32_C(   830.54) },
      { SIMDE_FLOAT32_C(  -633.53), SIMDE_FLOAT32_C(   832.17) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-554711.687500), SIMDE_FLOAT32_C(-554377.000000) } },
    { { SIMDE_FLOAT32_C(  -890.17), SIMDE_FLOAT32_C(   649.92) },
      { SIMDE_FLOAT32_C(  -111.22), SIMDE_FLOAT32_C(  -830.36) },
      { SIMDE_FLOAT32_C(    59.76), SIMDE_FLOAT32_C(   970.61) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(5756.336914), SIMDE_FLOAT32_C(7296.427246) } },
    { { SIMDE_FLOAT32_C(   522.31), SIMDE_FLOAT32_C(  -822.40) },
      { SIMDE_FLOAT32_C(   411.34), SIMDE_FLOAT32_C(  -692.35) },
      { SIMDE_FLOAT32_C(   648.71), SIMDE_FLOAT32_C(   385.20) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-266318.062500), SIMDE_FLOAT32_C(-267662.781250) } },
    { { SIMDE_FLOAT32_C(   479.18), SIMDE_FLOAT32_C(  -793.73) },
      { SIMDE_FLOAT32_C(  -740.26), SIMDE_FLOAT32_C(   245.04) },
      { SIMDE_FLOAT32_C(   229.26), SIMDE_FLOAT32_C(  -113.23) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(170191.187500), SIMDE_FLOAT32_C(168918.281250) } },
    { { SIMDE_FLOAT32_C(   331.48), SIMDE_FLOAT32_C(  -677.34) },
      { SIMDE_FLOAT32_C(    97.30), SIMDE_FLOAT32_C(   -52.10) },
      { SIMDE_FLOAT32_C(   239.17), SIMDE_FLOAT32_C(   469.68) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-22939.761719), SIMDE_FLOAT32_C(-23948.582031) } },
    { { SIMDE_FLOAT32_C(  -543.40), SIMDE_FLOAT32_C(   826.85) },
      { SIMDE_FLOAT32_C(   226.38), SIMDE_FLOAT32_C(   178.84) },
      { SIMDE_FLOAT32_C(   181.71), SIMDE_FLOAT32_C(   420.52) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-41678.914062), SIMDE_FLOAT32_C(-40308.664062) } },
    { { SIMDE_FLOAT32_C(  -698.84), SIMDE_FLOAT32_C(  -151.15) },
      { SIMDE_FLOAT32_C(  -388.27), SIMDE_FLOAT32_C(   350.81) },
      { SIMDE_FLOAT32_C(   890.40), SIMDE_FLOAT32_C(  -664.75) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(345016.781250), SIMDE_FLOAT32_C(345564.468750) } },
    { { SIMDE_FLOAT32_C(  -617.94), SIMDE_FLOAT32_C(   190.84) },
      { SIMDE_FLOAT32_C(   218.13), SIMDE_FLOAT32_C(  -328.97) },
      { SIMDE_FLOAT32_C(  -549.59), SIMDE_FLOAT32_C(  -459.89) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(119264.132812), SIMDE_FLOAT32_C(120072.914062) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t r_ = simde_vld1_f32(test_vec[i].r_);
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r = simde_vcmla_rot180_lane_f32(r_, a, b, 0);
    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
    // simde_float32x2_t r;
    // SIMDE_CONSTIFY_2_(simde_vcmla_rot180_lane_f32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f32(SIMDE_FLOAT32_C(0.0))), test_vec[i].lane, r_, a, b);
    // simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
    
  }
  
  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t r_ = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_vcmla_rot180_lane_f32(r_, a, b, lanes[i]);


    simde_test_arm_neon_write_f32x2(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


static int
test_simde_vcmla_rot180_laneq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float16_t r_[4];
    simde_float16_t a[4];
    simde_float16_t b[8];
    const int lane;
    simde_float16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(   816.50), SIMDE_FLOAT16_VALUE(   773.50), SIMDE_FLOAT16_VALUE(  -377.75), SIMDE_FLOAT16_VALUE(   544.50) },
      { SIMDE_FLOAT16_VALUE(  -188.38), SIMDE_FLOAT16_VALUE(   269.75), SIMDE_FLOAT16_VALUE(   115.62), SIMDE_FLOAT16_VALUE(  -544.00) },
      { SIMDE_FLOAT16_VALUE(    42.90), SIMDE_FLOAT16_VALUE(   924.50), SIMDE_FLOAT16_VALUE(   484.00), SIMDE_FLOAT16_VALUE(  -757.00),
        SIMDE_FLOAT16_VALUE(   730.00), SIMDE_FLOAT16_VALUE(   103.12), SIMDE_FLOAT16_VALUE(  -381.25), SIMDE_FLOAT16_VALUE(   898.50) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(  8896.00), SIMDE_FLOAT16_VALUE(  8856.00), SIMDE_FLOAT16_VALUE( -5340.00), SIMDE_FLOAT16_VALUE( -4416.00) } },
    { { SIMDE_FLOAT16_VALUE(   293.00), SIMDE_FLOAT16_VALUE(  -114.06), SIMDE_FLOAT16_VALUE(  -137.62), SIMDE_FLOAT16_VALUE(   722.50) },
      { SIMDE_FLOAT16_VALUE(    -6.33), SIMDE_FLOAT16_VALUE(   161.38), SIMDE_FLOAT16_VALUE(   115.50), SIMDE_FLOAT16_VALUE(    70.38) },
      { SIMDE_FLOAT16_VALUE(  -899.00), SIMDE_FLOAT16_VALUE(    32.51), SIMDE_FLOAT16_VALUE(   359.00), SIMDE_FLOAT16_VALUE(   342.25),
        SIMDE_FLOAT16_VALUE(   913.00), SIMDE_FLOAT16_VALUE(   740.50), SIMDE_FLOAT16_VALUE(  -436.25), SIMDE_FLOAT16_VALUE(  -904.00) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(   498.75), SIMDE_FLOAT16_VALUE(    91.62), SIMDE_FLOAT16_VALUE( -3892.00), SIMDE_FLOAT16_VALUE( -3032.00) } },
    { { SIMDE_FLOAT16_VALUE(  -335.25), SIMDE_FLOAT16_VALUE(  -252.38), SIMDE_FLOAT16_VALUE(   227.25), SIMDE_FLOAT16_VALUE(    -8.67) },
      { SIMDE_FLOAT16_VALUE(   490.50), SIMDE_FLOAT16_VALUE(   507.50), SIMDE_FLOAT16_VALUE(  -979.50), SIMDE_FLOAT16_VALUE(  -718.00) },
      { SIMDE_FLOAT16_VALUE(   -10.20), SIMDE_FLOAT16_VALUE(   205.75), SIMDE_FLOAT16_VALUE(  -797.50), SIMDE_FLOAT16_VALUE(   741.50),
        SIMDE_FLOAT16_VALUE(  -835.00), SIMDE_FLOAT16_VALUE(  -308.00), SIMDE_FLOAT16_VALUE(  -674.50), SIMDE_FLOAT16_VALUE(  -247.00) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(  4668.00), SIMDE_FLOAT16_VALUE(  4752.00), SIMDE_FLOAT16_VALUE( -9768.00), SIMDE_FLOAT16_VALUE(-10000.00) } },
    { { SIMDE_FLOAT16_VALUE(  -210.88), SIMDE_FLOAT16_VALUE(  -430.75), SIMDE_FLOAT16_VALUE(    25.50), SIMDE_FLOAT16_VALUE(   -44.50) },
      { SIMDE_FLOAT16_VALUE(   142.00), SIMDE_FLOAT16_VALUE(   -66.00), SIMDE_FLOAT16_VALUE(  -131.50), SIMDE_FLOAT16_VALUE(   462.50) },
      { SIMDE_FLOAT16_VALUE(  -361.00), SIMDE_FLOAT16_VALUE(    85.62), SIMDE_FLOAT16_VALUE(    60.47), SIMDE_FLOAT16_VALUE(   749.50),
        SIMDE_FLOAT16_VALUE(  -975.50), SIMDE_FLOAT16_VALUE(   383.50), SIMDE_FLOAT16_VALUE(   500.25), SIMDE_FLOAT16_VALUE(   517.00) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(-12368.00), SIMDE_FLOAT16_VALUE(-12592.00), SIMDE_FLOAT16_VALUE( 11288.00), SIMDE_FLOAT16_VALUE( 11216.00) } },
    { { SIMDE_FLOAT16_VALUE(   540.00), SIMDE_FLOAT16_VALUE(  -927.50), SIMDE_FLOAT16_VALUE(    17.94), SIMDE_FLOAT16_VALUE(   340.75) },
      { SIMDE_FLOAT16_VALUE(  -397.75), SIMDE_FLOAT16_VALUE(   166.12), SIMDE_FLOAT16_VALUE(   854.00), SIMDE_FLOAT16_VALUE(  -110.75) },
      { SIMDE_FLOAT16_VALUE(   -53.36), SIMDE_FLOAT16_VALUE(  -465.00), SIMDE_FLOAT16_VALUE(  -104.00), SIMDE_FLOAT16_VALUE(  -348.00),
        SIMDE_FLOAT16_VALUE(  -370.75), SIMDE_FLOAT16_VALUE(    18.20), SIMDE_FLOAT16_VALUE(  -209.25), SIMDE_FLOAT16_VALUE(  -856.00) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(-20688.00), SIMDE_FLOAT16_VALUE(-22160.00), SIMDE_FLOAT16_VALUE( 45600.00), SIMDE_FLOAT16_VALUE( 45920.00) } },
    { { SIMDE_FLOAT16_VALUE(   251.25), SIMDE_FLOAT16_VALUE(   523.50), SIMDE_FLOAT16_VALUE(   -62.34), SIMDE_FLOAT16_VALUE(  -412.00) },
      { SIMDE_FLOAT16_VALUE(   818.50), SIMDE_FLOAT16_VALUE(  -266.25), SIMDE_FLOAT16_VALUE(   558.50), SIMDE_FLOAT16_VALUE(  -474.75) },
      { SIMDE_FLOAT16_VALUE(   583.50), SIMDE_FLOAT16_VALUE(    58.66), SIMDE_FLOAT16_VALUE(   875.50), SIMDE_FLOAT16_VALUE(   382.50),
        SIMDE_FLOAT16_VALUE(  -535.00), SIMDE_FLOAT16_VALUE(   374.50), SIMDE_FLOAT16_VALUE(    89.81), SIMDE_FLOAT16_VALUE(   432.50) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(-47744.00), SIMDE_FLOAT16_VALUE(-47488.00), SIMDE_FLOAT16_VALUE(-32832.00), SIMDE_FLOAT16_VALUE(-33184.00) } },
    { { SIMDE_FLOAT16_VALUE(    83.19), SIMDE_FLOAT16_VALUE(   418.00), SIMDE_FLOAT16_VALUE(  -875.50), SIMDE_FLOAT16_VALUE(   830.50) },
      { SIMDE_FLOAT16_VALUE(  -633.50), SIMDE_FLOAT16_VALUE(   832.00), SIMDE_FLOAT16_VALUE(  -890.00), SIMDE_FLOAT16_VALUE(   650.00) },
      { SIMDE_FLOAT16_VALUE(   -31.19), SIMDE_FLOAT16_VALUE(  -830.50), SIMDE_FLOAT16_VALUE(    59.75), SIMDE_FLOAT16_VALUE(   970.50),
        SIMDE_FLOAT16_VALUE(   522.50), SIMDE_FLOAT16_VALUE(  -822.50), SIMDE_FLOAT16_VALUE(   411.25), SIMDE_FLOAT16_VALUE(  -692.50) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(-19680.00), SIMDE_FLOAT16_VALUE(-19344.00), SIMDE_FLOAT16_VALUE(-28640.00), SIMDE_FLOAT16_VALUE(-26928.00) } },
    { { SIMDE_FLOAT16_VALUE(   648.50), SIMDE_FLOAT16_VALUE(   385.25), SIMDE_FLOAT16_VALUE(   479.25), SIMDE_FLOAT16_VALUE(  -793.50) },
      { SIMDE_FLOAT16_VALUE(  -740.50), SIMDE_FLOAT16_VALUE(   245.00), SIMDE_FLOAT16_VALUE(   229.25), SIMDE_FLOAT16_VALUE(  -113.25) },
      { SIMDE_FLOAT16_VALUE(   331.50), SIMDE_FLOAT16_VALUE(   -75.25), SIMDE_FLOAT16_VALUE(    97.31), SIMDE_FLOAT16_VALUE(   -52.09),
        SIMDE_FLOAT16_VALUE(   239.12), SIMDE_FLOAT16_VALUE(   469.75), SIMDE_FLOAT16_VALUE(  -543.50), SIMDE_FLOAT16_VALUE(   827.00) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(-55072.00), SIMDE_FLOAT16_VALUE(-55328.00), SIMDE_FLOAT16_VALUE( 17728.00), SIMDE_FLOAT16_VALUE( 16464.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t r_ = simde_vld1_f16(test_vec[i].r_);
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    
    // simde_float16x4_t r = simde_vcmla_rot180_laneq_f16(r_, a, b, test_vec[i].lane);
    // simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);

    simde_float16x4_t r;
    SIMDE_CONSTIFY_2_(simde_vcmla_rot180_laneq_f16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f16(SIMDE_FLOAT16_VALUE(0.0))), test_vec[i].lane, r_, a, b);
    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }
  
  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t r_ = simde_test_arm_neon_random_f16x4(-1000.0f, 1000.0f);
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-1000.0f, 1000.0f);
    simde_float16x8_t b = simde_test_arm_neon_random_f16x8(-1000.0f, 1000.0f);
    simde_float16x4_t r = simde_vcmla_rot180_laneq_f16(r_, a, b, lanes[i]);


    simde_test_arm_neon_write_f16x4(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmla_rot180_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t r_[2];
    simde_float32_t a[2];
    simde_float32_t b[4];
    const int lane;
    simde_float32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -470.26), SIMDE_FLOAT32_C(    81.87) },
      { SIMDE_FLOAT32_C(    72.27), SIMDE_FLOAT32_C(  -992.59) },
      { SIMDE_FLOAT32_C(  -615.67), SIMDE_FLOAT32_C(   620.28), SIMDE_FLOAT32_C(  -606.51), SIMDE_FLOAT32_C(  -327.77) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(44024.207031), SIMDE_FLOAT32_C(44576.335938) } },
    { { SIMDE_FLOAT32_C(  -331.80), SIMDE_FLOAT32_C(  -605.94) },
      { SIMDE_FLOAT32_C(  -295.86), SIMDE_FLOAT32_C(  -275.42) },
      { SIMDE_FLOAT32_C(  -752.64), SIMDE_FLOAT32_C(    21.91), SIMDE_FLOAT32_C(   826.83), SIMDE_FLOAT32_C(   599.82) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(6150.492188), SIMDE_FLOAT32_C(5876.352051) } },
    { { SIMDE_FLOAT32_C(   -30.36), SIMDE_FLOAT32_C(   631.53) },
      { SIMDE_FLOAT32_C(   850.75), SIMDE_FLOAT32_C(  -263.55) },
      { SIMDE_FLOAT32_C(   139.96), SIMDE_FLOAT32_C(   859.14), SIMDE_FLOAT32_C(  -834.47), SIMDE_FLOAT32_C(   216.10) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-119101.335938), SIMDE_FLOAT32_C(-118439.445312) } },
    { { SIMDE_FLOAT32_C(   995.86), SIMDE_FLOAT32_C(   529.74) },
      { SIMDE_FLOAT32_C(    79.08), SIMDE_FLOAT32_C(   947.13) },
      { SIMDE_FLOAT32_C(   122.02), SIMDE_FLOAT32_C(  -250.00), SIMDE_FLOAT32_C(  -361.82), SIMDE_FLOAT32_C(   265.24) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(20765.861328), SIMDE_FLOAT32_C(20299.740234) } },
    { { SIMDE_FLOAT32_C(   275.71), SIMDE_FLOAT32_C(     2.71) },
      { SIMDE_FLOAT32_C(    99.79), SIMDE_FLOAT32_C(  -137.67) },
      { SIMDE_FLOAT32_C(  -761.19), SIMDE_FLOAT32_C(   813.19), SIMDE_FLOAT32_C(  -897.68), SIMDE_FLOAT32_C(   653.58) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(76234.859375), SIMDE_FLOAT32_C(75961.859375) } },
    { { SIMDE_FLOAT32_C(   396.02), SIMDE_FLOAT32_C(   413.06) },
      { SIMDE_FLOAT32_C(   514.09), SIMDE_FLOAT32_C(  -977.67) },
      { SIMDE_FLOAT32_C(  -671.79), SIMDE_FLOAT32_C(   -92.13), SIMDE_FLOAT32_C(  -441.32), SIMDE_FLOAT32_C(  -374.27) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(47759.132812), SIMDE_FLOAT32_C(47776.171875) } },
    { { SIMDE_FLOAT32_C(  -151.97), SIMDE_FLOAT32_C(   -79.55) },
      { SIMDE_FLOAT32_C(  -214.62), SIMDE_FLOAT32_C(  -614.75) },
      { SIMDE_FLOAT32_C(   678.79), SIMDE_FLOAT32_C(   783.83), SIMDE_FLOAT32_C(   493.05), SIMDE_FLOAT32_C(  -896.00) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(145529.937500), SIMDE_FLOAT32_C(145602.359375) } },
    { { SIMDE_FLOAT32_C(   104.13), SIMDE_FLOAT32_C(   278.54) },
      { SIMDE_FLOAT32_C(   171.54), SIMDE_FLOAT32_C(  -682.63) },
      { SIMDE_FLOAT32_C(   217.09), SIMDE_FLOAT32_C(    49.35), SIMDE_FLOAT32_C(   256.50), SIMDE_FLOAT32_C(   -92.04) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(-8361.368164), SIMDE_FLOAT32_C(-8186.958496) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t r_ = simde_vld1_f32(test_vec[i].r_);
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x2_t r;
    SIMDE_CONSTIFY_2_(simde_vcmla_rot180_laneq_f32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f32(SIMDE_FLOAT32_C(0.0))), test_vec[i].lane, r_, a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
    // simde_float32x2_t r = simde_vcmla_rot180_laneq_f32(r_, a, b, test_vec[i].lane);
    // simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  
  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t r_ = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_vcmla_rot180_laneq_f32(r_, a, b, lanes[i]);


    simde_test_arm_neon_write_f32x2(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmlaq_rot180_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float16_t r_[8];
    simde_float16_t a[8];
    simde_float16_t b[4];
    const int lane;
    simde_float16_t r[8];
  } test_vec[] = {
    
    { { SIMDE_FLOAT16_VALUE(   226.38), SIMDE_FLOAT16_VALUE(   178.88), SIMDE_FLOAT16_VALUE(   181.75), SIMDE_FLOAT16_VALUE(   420.50),
        SIMDE_FLOAT16_VALUE(  -699.00), SIMDE_FLOAT16_VALUE(  -151.12), SIMDE_FLOAT16_VALUE(  -388.25), SIMDE_FLOAT16_VALUE(   350.75) },
      { SIMDE_FLOAT16_VALUE(   890.50), SIMDE_FLOAT16_VALUE(  -665.00), SIMDE_FLOAT16_VALUE(  -618.00), SIMDE_FLOAT16_VALUE(   190.88),
        SIMDE_FLOAT16_VALUE(   218.12), SIMDE_FLOAT16_VALUE(  -329.00), SIMDE_FLOAT16_VALUE(  -549.50), SIMDE_FLOAT16_VALUE(  -460.00) },
      { SIMDE_FLOAT16_VALUE(   -49.28), SIMDE_FLOAT16_VALUE(  -695.50), SIMDE_FLOAT16_VALUE(   121.50), SIMDE_FLOAT16_VALUE(   -78.44) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE( 44096.00), SIMDE_FLOAT16_VALUE( 44064.00), SIMDE_FLOAT16_VALUE(-30272.00), SIMDE_FLOAT16_VALUE(-30032.00),
        SIMDE_FLOAT16_VALUE( 10048.00), SIMDE_FLOAT16_VALUE( 10600.00), SIMDE_FLOAT16_VALUE(-27472.00), SIMDE_FLOAT16_VALUE(-26736.00) } },
    { { SIMDE_FLOAT16_VALUE(  -869.50), SIMDE_FLOAT16_VALUE(  -710.00), SIMDE_FLOAT16_VALUE(   457.25), SIMDE_FLOAT16_VALUE(   579.00),
        SIMDE_FLOAT16_VALUE(  -786.50), SIMDE_FLOAT16_VALUE(  -974.00), SIMDE_FLOAT16_VALUE(  -570.50), SIMDE_FLOAT16_VALUE(   369.25) },
      { SIMDE_FLOAT16_VALUE(    48.06), SIMDE_FLOAT16_VALUE(   -40.00), SIMDE_FLOAT16_VALUE(   -52.00), SIMDE_FLOAT16_VALUE(    75.88),
        SIMDE_FLOAT16_VALUE(   352.25), SIMDE_FLOAT16_VALUE(   324.25), SIMDE_FLOAT16_VALUE(   485.50), SIMDE_FLOAT16_VALUE(    43.50) },
      { SIMDE_FLOAT16_VALUE(  -976.00), SIMDE_FLOAT16_VALUE(    89.44), SIMDE_FLOAT16_VALUE(  -100.62), SIMDE_FLOAT16_VALUE(  -463.75) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( -5168.00), SIMDE_FLOAT16_VALUE( -5008.00), SIMDE_FLOAT16_VALUE(  5108.00), SIMDE_FLOAT16_VALUE(  5228.00),
        SIMDE_FLOAT16_VALUE(-32288.00), SIMDE_FLOAT16_VALUE(-32480.00), SIMDE_FLOAT16_VALUE(-44000.00), SIMDE_FLOAT16_VALUE(-43040.00) } },
    { { SIMDE_FLOAT16_VALUE(  -973.00), SIMDE_FLOAT16_VALUE(  -159.62), SIMDE_FLOAT16_VALUE(  -377.00), SIMDE_FLOAT16_VALUE(  -853.00),
        SIMDE_FLOAT16_VALUE(   831.00), SIMDE_FLOAT16_VALUE(   661.00), SIMDE_FLOAT16_VALUE(  -717.00), SIMDE_FLOAT16_VALUE(   891.50) },
      { SIMDE_FLOAT16_VALUE(   535.50), SIMDE_FLOAT16_VALUE(   621.50), SIMDE_FLOAT16_VALUE(   578.50), SIMDE_FLOAT16_VALUE(   430.50),
        SIMDE_FLOAT16_VALUE(  -574.50), SIMDE_FLOAT16_VALUE(  -319.75), SIMDE_FLOAT16_VALUE(  -735.00), SIMDE_FLOAT16_VALUE(   248.50) },
      { SIMDE_FLOAT16_VALUE(    32.59), SIMDE_FLOAT16_VALUE(   192.38), SIMDE_FLOAT16_VALUE(   679.00), SIMDE_FLOAT16_VALUE(   502.25) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(-18432.00), SIMDE_FLOAT16_VALUE(-17616.00), SIMDE_FLOAT16_VALUE(-19232.00), SIMDE_FLOAT16_VALUE(-19712.00),
        SIMDE_FLOAT16_VALUE( 19552.00), SIMDE_FLOAT16_VALUE( 19392.00), SIMDE_FLOAT16_VALUE( 23232.00), SIMDE_FLOAT16_VALUE( 24848.00) } },
    { { SIMDE_FLOAT16_VALUE(  -618.50), SIMDE_FLOAT16_VALUE(   -70.81), SIMDE_FLOAT16_VALUE(  -596.50), SIMDE_FLOAT16_VALUE(   810.50),
        SIMDE_FLOAT16_VALUE(   863.50), SIMDE_FLOAT16_VALUE(   828.50), SIMDE_FLOAT16_VALUE(  -563.50), SIMDE_FLOAT16_VALUE(  -576.50) },
      { SIMDE_FLOAT16_VALUE(  -703.50), SIMDE_FLOAT16_VALUE(   384.00), SIMDE_FLOAT16_VALUE(  -772.50), SIMDE_FLOAT16_VALUE(   457.50),
        SIMDE_FLOAT16_VALUE(   296.00), SIMDE_FLOAT16_VALUE(   653.00), SIMDE_FLOAT16_VALUE(  -121.00), SIMDE_FLOAT16_VALUE(   945.50) },
      { SIMDE_FLOAT16_VALUE(  -280.75), SIMDE_FLOAT16_VALUE(   -31.45), SIMDE_FLOAT16_VALUE(   688.50), SIMDE_FLOAT16_VALUE(   192.00) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(-22752.00), SIMDE_FLOAT16_VALUE(-22192.00), SIMDE_FLOAT16_VALUE(-24896.00), SIMDE_FLOAT16_VALUE(-23488.00),
        SIMDE_FLOAT16_VALUE( 10176.00), SIMDE_FLOAT16_VALUE( 10136.00), SIMDE_FLOAT16_VALUE( -4368.00), SIMDE_FLOAT16_VALUE( -4384.00) } },
    { { SIMDE_FLOAT16_VALUE(  -523.00), SIMDE_FLOAT16_VALUE(  -323.75), SIMDE_FLOAT16_VALUE(  -888.00), SIMDE_FLOAT16_VALUE(  -283.75),
        SIMDE_FLOAT16_VALUE(  -117.75), SIMDE_FLOAT16_VALUE(  -841.50), SIMDE_FLOAT16_VALUE(   665.00), SIMDE_FLOAT16_VALUE(  -987.00) },
      { SIMDE_FLOAT16_VALUE(  -643.00), SIMDE_FLOAT16_VALUE(  -152.12), SIMDE_FLOAT16_VALUE(   964.00), SIMDE_FLOAT16_VALUE(   920.00),
        SIMDE_FLOAT16_VALUE(   630.50), SIMDE_FLOAT16_VALUE(  -669.50), SIMDE_FLOAT16_VALUE(   671.00), SIMDE_FLOAT16_VALUE(   257.00) },
      { SIMDE_FLOAT16_VALUE(    10.22), SIMDE_FLOAT16_VALUE(  -857.50), SIMDE_FLOAT16_VALUE(   334.75), SIMDE_FLOAT16_VALUE(  -617.50) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(  6048.00), SIMDE_FLOAT16_VALUE(  6248.00), SIMDE_FLOAT16_VALUE(-10736.00), SIMDE_FLOAT16_VALUE(-10136.00),
        SIMDE_FLOAT16_VALUE( -6560.00), SIMDE_FLOAT16_VALUE( -7284.00), SIMDE_FLOAT16_VALUE( -6192.00), SIMDE_FLOAT16_VALUE( -7844.00) } },
    { { SIMDE_FLOAT16_VALUE(  -439.50), SIMDE_FLOAT16_VALUE(   245.12), SIMDE_FLOAT16_VALUE(   111.06), SIMDE_FLOAT16_VALUE(   520.50),
        SIMDE_FLOAT16_VALUE(    85.50), SIMDE_FLOAT16_VALUE(   250.25), SIMDE_FLOAT16_VALUE(  -680.00), SIMDE_FLOAT16_VALUE(  -750.00) },
      { SIMDE_FLOAT16_VALUE(  -138.25), SIMDE_FLOAT16_VALUE(   -14.62), SIMDE_FLOAT16_VALUE(  -921.50), SIMDE_FLOAT16_VALUE(   225.88),
        SIMDE_FLOAT16_VALUE(   242.88), SIMDE_FLOAT16_VALUE(   869.50), SIMDE_FLOAT16_VALUE(   298.00), SIMDE_FLOAT16_VALUE(   105.69) },
      { SIMDE_FLOAT16_VALUE(  -722.50), SIMDE_FLOAT16_VALUE(    -8.75), SIMDE_FLOAT16_VALUE(  -245.75), SIMDE_FLOAT16_VALUE(   915.50) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( -1649.00), SIMDE_FLOAT16_VALUE(  -964.50), SIMDE_FLOAT16_VALUE( -7952.00), SIMDE_FLOAT16_VALUE( -7544.00),
        SIMDE_FLOAT16_VALUE(  2210.00), SIMDE_FLOAT16_VALUE(  2376.00), SIMDE_FLOAT16_VALUE(  1928.00), SIMDE_FLOAT16_VALUE(  1858.00) } },
    { { SIMDE_FLOAT16_VALUE(    54.19), SIMDE_FLOAT16_VALUE(  -928.00), SIMDE_FLOAT16_VALUE(   362.50), SIMDE_FLOAT16_VALUE(  -936.50),
        SIMDE_FLOAT16_VALUE(   185.88), SIMDE_FLOAT16_VALUE(  -244.38), SIMDE_FLOAT16_VALUE(   924.50), SIMDE_FLOAT16_VALUE(  -644.00) },
      { SIMDE_FLOAT16_VALUE(  -517.00), SIMDE_FLOAT16_VALUE(  -615.00), SIMDE_FLOAT16_VALUE(  -751.50), SIMDE_FLOAT16_VALUE(  -974.00),
        SIMDE_FLOAT16_VALUE(  -144.38), SIMDE_FLOAT16_VALUE(   338.25), SIMDE_FLOAT16_VALUE(   705.00), SIMDE_FLOAT16_VALUE(   116.88) },
      { SIMDE_FLOAT16_VALUE(    49.38), SIMDE_FLOAT16_VALUE(  -363.00), SIMDE_FLOAT16_VALUE(  -476.25), SIMDE_FLOAT16_VALUE(   106.69) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE( 25584.00), SIMDE_FLOAT16_VALUE( 24592.00), SIMDE_FLOAT16_VALUE( 37472.00), SIMDE_FLOAT16_VALUE( 36160.00),
        SIMDE_FLOAT16_VALUE(  7316.00), SIMDE_FLOAT16_VALUE(  6884.00), SIMDE_FLOAT16_VALUE(-33888.00), SIMDE_FLOAT16_VALUE(-35456.00) } },
    { { SIMDE_FLOAT16_VALUE(  -726.00), SIMDE_FLOAT16_VALUE(  -353.75), SIMDE_FLOAT16_VALUE(   268.50), SIMDE_FLOAT16_VALUE(   729.00),
        SIMDE_FLOAT16_VALUE(  -470.25), SIMDE_FLOAT16_VALUE(    81.88), SIMDE_FLOAT16_VALUE(    72.25), SIMDE_FLOAT16_VALUE(  -992.50) },
      { SIMDE_FLOAT16_VALUE(  -615.50), SIMDE_FLOAT16_VALUE(   620.50), SIMDE_FLOAT16_VALUE(  -606.50), SIMDE_FLOAT16_VALUE(  -327.75),
        SIMDE_FLOAT16_VALUE(  -331.75), SIMDE_FLOAT16_VALUE(  -606.00), SIMDE_FLOAT16_VALUE(  -295.75), SIMDE_FLOAT16_VALUE(  -275.50) },
      { SIMDE_FLOAT16_VALUE(  -752.50), SIMDE_FLOAT16_VALUE(    21.91), SIMDE_FLOAT16_VALUE(   827.00), SIMDE_FLOAT16_VALUE(   600.00) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( 12760.00), SIMDE_FLOAT16_VALUE( 13128.00), SIMDE_FLOAT16_VALUE( 13552.00), SIMDE_FLOAT16_VALUE( 14016.00),
        SIMDE_FLOAT16_VALUE(  6796.00), SIMDE_FLOAT16_VALUE(  7348.00), SIMDE_FLOAT16_VALUE(  6552.00), SIMDE_FLOAT16_VALUE(  5488.00) } }
    
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t r_ = simde_vld1q_f16(test_vec[i].r_);
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float16x8_t r;
    SIMDE_CONSTIFY_2_(simde_vcmlaq_rot180_lane_f16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f16(SIMDE_FLOAT16_VALUE(0.0))), test_vec[i].lane, r_, a, b);

    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
    // simde_float16x8_t r = simde_vcmlaq_rot180_lane_f16(r_, a, b, test_vec[i].lane);
    // simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  
  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t r_ = simde_test_arm_neon_random_f16x8(-1000.0f, 1000.0f);
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-1000.0f, 1000.0f);
    simde_float16x4_t b = simde_test_arm_neon_random_f16x4(-1000.0f, 1000.0f);
    simde_float16x8_t r = simde_vcmlaq_lane_f16(r_, a, b, lanes[i]);


    simde_test_arm_neon_write_f16x8(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmlaq_rot180_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t r_[4];
    simde_float32_t a[4];
    simde_float32_t b[2];
    const int lane;
    simde_float32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   301.65), SIMDE_FLOAT32_C(   490.71), SIMDE_FLOAT32_C(  -744.66), SIMDE_FLOAT32_C(  -738.17) },
      { SIMDE_FLOAT32_C(  -301.20), SIMDE_FLOAT32_C(  -904.34), SIMDE_FLOAT32_C(   771.98), SIMDE_FLOAT32_C(   233.71) },
      { SIMDE_FLOAT32_C(   830.18), SIMDE_FLOAT32_C(   979.39) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(250351.875000), SIMDE_FLOAT32_C(250540.937500), SIMDE_FLOAT32_C(-641627.000000), SIMDE_FLOAT32_C(-641620.500000) } },
    { { SIMDE_FLOAT32_C(   -38.01), SIMDE_FLOAT32_C(   151.61), SIMDE_FLOAT32_C(   201.45), SIMDE_FLOAT32_C(  -747.32) },
      { SIMDE_FLOAT32_C(  -331.17), SIMDE_FLOAT32_C(     7.62), SIMDE_FLOAT32_C(  -454.77), SIMDE_FLOAT32_C(  -381.81) },
      { SIMDE_FLOAT32_C(   236.39), SIMDE_FLOAT32_C(  -158.94) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(78247.265625), SIMDE_FLOAT32_C(78436.890625), SIMDE_FLOAT32_C(107704.531250), SIMDE_FLOAT32_C(106755.757812) } },
    { { SIMDE_FLOAT32_C(   605.85), SIMDE_FLOAT32_C(   244.27), SIMDE_FLOAT32_C(  -426.53), SIMDE_FLOAT32_C(  -969.18) },
      { SIMDE_FLOAT32_C(   322.13), SIMDE_FLOAT32_C(   863.77), SIMDE_FLOAT32_C(  -685.35), SIMDE_FLOAT32_C(  -710.70) },
      { SIMDE_FLOAT32_C(  -791.12), SIMDE_FLOAT32_C(   373.53) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(255449.343750), SIMDE_FLOAT32_C(255087.765625), SIMDE_FLOAT32_C(-542620.625000), SIMDE_FLOAT32_C(-543163.250000) } },
    { { SIMDE_FLOAT32_C(  -606.46), SIMDE_FLOAT32_C(  -507.55), SIMDE_FLOAT32_C(   -68.24), SIMDE_FLOAT32_C(  -823.05) },
      { SIMDE_FLOAT32_C(  -359.95), SIMDE_FLOAT32_C(   611.92), SIMDE_FLOAT32_C(   514.14), SIMDE_FLOAT32_C(  -660.86) },
      { SIMDE_FLOAT32_C(   181.81), SIMDE_FLOAT32_C(   115.86) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(64836.050781), SIMDE_FLOAT32_C(64934.960938), SIMDE_FLOAT32_C(-93544.031250), SIMDE_FLOAT32_C(-94298.843750) } },
    { { SIMDE_FLOAT32_C(   951.84), SIMDE_FLOAT32_C(  -864.96), SIMDE_FLOAT32_C(   970.59), SIMDE_FLOAT32_C(   769.97) },
      { SIMDE_FLOAT32_C(   609.64), SIMDE_FLOAT32_C(  -580.87), SIMDE_FLOAT32_C(   358.59), SIMDE_FLOAT32_C(   350.56) },
      { SIMDE_FLOAT32_C(    26.31), SIMDE_FLOAT32_C(   163.74) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-15087.788086), SIMDE_FLOAT32_C(-16904.587891), SIMDE_FLOAT32_C(-8463.912109), SIMDE_FLOAT32_C(-8664.532227) } },
    { { SIMDE_FLOAT32_C(  -636.68), SIMDE_FLOAT32_C(   554.68), SIMDE_FLOAT32_C(  -385.40), SIMDE_FLOAT32_C(  -565.95) },
      { SIMDE_FLOAT32_C(   129.69), SIMDE_FLOAT32_C(   961.79), SIMDE_FLOAT32_C(  -333.22), SIMDE_FLOAT32_C(    69.65) },
      { SIMDE_FLOAT32_C(   726.96), SIMDE_FLOAT32_C(   131.41) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-94916.125000), SIMDE_FLOAT32_C(-93724.765625), SIMDE_FLOAT32_C(241852.218750), SIMDE_FLOAT32_C(241671.671875) } },
    { { SIMDE_FLOAT32_C(  -211.91), SIMDE_FLOAT32_C(   829.24), SIMDE_FLOAT32_C(  -475.13), SIMDE_FLOAT32_C(   562.33) },
      { SIMDE_FLOAT32_C(   515.59), SIMDE_FLOAT32_C(  -290.69), SIMDE_FLOAT32_C(  -816.53), SIMDE_FLOAT32_C(    17.39) },
      { SIMDE_FLOAT32_C(   268.14), SIMDE_FLOAT32_C(   729.88) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-138462.234375), SIMDE_FLOAT32_C(-137421.078125), SIMDE_FLOAT32_C(218469.250000), SIMDE_FLOAT32_C(219506.703125) } },
    { { SIMDE_FLOAT32_C(  -894.99), SIMDE_FLOAT32_C(   516.42), SIMDE_FLOAT32_C(  -169.55), SIMDE_FLOAT32_C(   696.41) },
      { SIMDE_FLOAT32_C(  -388.51), SIMDE_FLOAT32_C(   987.71), SIMDE_FLOAT32_C(   -91.49), SIMDE_FLOAT32_C(  -970.85) },
      { SIMDE_FLOAT32_C(   357.28), SIMDE_FLOAT32_C(   -28.01) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(137911.859375), SIMDE_FLOAT32_C(139323.281250), SIMDE_FLOAT32_C(32517.996094), SIMDE_FLOAT32_C(33383.957031) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t r_ = simde_vld1q_f32(test_vec[i].r_);
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vcmlaq_rot180_lane_f32(r_, a, b, 0);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
    // simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
    
  }
  
  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t r_ = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_vcmlaq_lane_f32(r_, a, b, lanes[i]);


    simde_test_arm_neon_write_f32x4(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmlaq_rot180_laneq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float16_t r_[8];
    simde_float16_t a[8];
    simde_float16_t b[8];
    const int lane;
    simde_float16_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(   -30.36), SIMDE_FLOAT16_VALUE(   631.50), SIMDE_FLOAT16_VALUE(   851.00), SIMDE_FLOAT16_VALUE(  -263.50),
        SIMDE_FLOAT16_VALUE(   140.00), SIMDE_FLOAT16_VALUE(   859.00), SIMDE_FLOAT16_VALUE(  -834.50), SIMDE_FLOAT16_VALUE(   216.12) },
      { SIMDE_FLOAT16_VALUE(   996.00), SIMDE_FLOAT16_VALUE(   529.50), SIMDE_FLOAT16_VALUE(    79.06), SIMDE_FLOAT16_VALUE(   947.00),
        SIMDE_FLOAT16_VALUE(   122.00), SIMDE_FLOAT16_VALUE(  -250.00), SIMDE_FLOAT16_VALUE(  -361.75), SIMDE_FLOAT16_VALUE(   265.25) },
      { SIMDE_FLOAT16_VALUE(    58.66), SIMDE_FLOAT16_VALUE(     2.71), SIMDE_FLOAT16_VALUE(    99.81), SIMDE_FLOAT16_VALUE(  -137.62),
        SIMDE_FLOAT16_VALUE(  -761.00), SIMDE_FLOAT16_VALUE(   813.00), SIMDE_FLOAT16_VALUE(  -897.50), SIMDE_FLOAT16_VALUE(   653.50) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(-58464.00), SIMDE_FLOAT16_VALUE(-57792.00), SIMDE_FLOAT16_VALUE( -3786.00), SIMDE_FLOAT16_VALUE( -4900.00),
        SIMDE_FLOAT16_VALUE( -7016.00), SIMDE_FLOAT16_VALUE( -6296.00), SIMDE_FLOAT16_VALUE( 20384.00), SIMDE_FLOAT16_VALUE( 21440.00) } },
    { { SIMDE_FLOAT16_VALUE(   396.00), SIMDE_FLOAT16_VALUE(   413.00), SIMDE_FLOAT16_VALUE(   514.00), SIMDE_FLOAT16_VALUE(  -977.50),
        SIMDE_FLOAT16_VALUE(  -672.00), SIMDE_FLOAT16_VALUE(   -92.12), SIMDE_FLOAT16_VALUE(  -441.25), SIMDE_FLOAT16_VALUE(  -374.25) },
      { SIMDE_FLOAT16_VALUE(  -152.00), SIMDE_FLOAT16_VALUE(   -79.56), SIMDE_FLOAT16_VALUE(  -214.62), SIMDE_FLOAT16_VALUE(  -615.00),
        SIMDE_FLOAT16_VALUE(    79.00), SIMDE_FLOAT16_VALUE(    84.00), SIMDE_FLOAT16_VALUE(   493.00), SIMDE_FLOAT16_VALUE(   -96.00) },
      { SIMDE_FLOAT16_VALUE(   104.12), SIMDE_FLOAT16_VALUE(    78.50), SIMDE_FLOAT16_VALUE(   171.50), SIMDE_FLOAT16_VALUE(  -682.50),
        SIMDE_FLOAT16_VALUE(   217.12), SIMDE_FLOAT16_VALUE(    49.34), SIMDE_FLOAT16_VALUE(   256.50), SIMDE_FLOAT16_VALUE(   -92.06) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( 12328.00), SIMDE_FLOAT16_VALUE( 12344.00), SIMDE_FLOAT16_VALUE( 17360.00), SIMDE_FLOAT16_VALUE( 15872.00),
        SIMDE_FLOAT16_VALUE( -6872.00), SIMDE_FLOAT16_VALUE( -6292.00), SIMDE_FLOAT16_VALUE(-39136.00), SIMDE_FLOAT16_VALUE(-39072.00) } },
    { { SIMDE_FLOAT16_VALUE(  -728.00), SIMDE_FLOAT16_VALUE(  -108.38), SIMDE_FLOAT16_VALUE(   -77.88), SIMDE_FLOAT16_VALUE(  -353.00),
        SIMDE_FLOAT16_VALUE(  -239.00), SIMDE_FLOAT16_VALUE(   704.50), SIMDE_FLOAT16_VALUE(   914.00), SIMDE_FLOAT16_VALUE(  -211.12) },
      { SIMDE_FLOAT16_VALUE(  -473.25), SIMDE_FLOAT16_VALUE(    74.38), SIMDE_FLOAT16_VALUE(   904.50), SIMDE_FLOAT16_VALUE(  -290.50),
        SIMDE_FLOAT16_VALUE(  -796.00), SIMDE_FLOAT16_VALUE(   421.25), SIMDE_FLOAT16_VALUE(   215.75), SIMDE_FLOAT16_VALUE(   249.38) },
      { SIMDE_FLOAT16_VALUE(  -523.00), SIMDE_FLOAT16_VALUE(  -720.00), SIMDE_FLOAT16_VALUE(    32.75), SIMDE_FLOAT16_VALUE(  -487.75),
        SIMDE_FLOAT16_VALUE(  -705.50), SIMDE_FLOAT16_VALUE(  -468.00), SIMDE_FLOAT16_VALUE(  -789.00), SIMDE_FLOAT16_VALUE(  -866.00) },
       INT32_C(           2),
      { SIMDE_FLOAT16_VALUE( 14768.00), SIMDE_FLOAT16_VALUE( 15392.00), SIMDE_FLOAT16_VALUE(-29696.00), SIMDE_FLOAT16_VALUE(-29968.00),
        SIMDE_FLOAT16_VALUE( 25824.00), SIMDE_FLOAT16_VALUE( 26768.00), SIMDE_FLOAT16_VALUE( -6152.00), SIMDE_FLOAT16_VALUE( -7276.00) } },
    { { SIMDE_FLOAT16_VALUE(  -891.50), SIMDE_FLOAT16_VALUE(  -299.00), SIMDE_FLOAT16_VALUE(  -595.00), SIMDE_FLOAT16_VALUE(  -662.00),
        SIMDE_FLOAT16_VALUE(  -914.00), SIMDE_FLOAT16_VALUE(   674.50), SIMDE_FLOAT16_VALUE(   771.50), SIMDE_FLOAT16_VALUE(    14.33) },
      { SIMDE_FLOAT16_VALUE(   880.00), SIMDE_FLOAT16_VALUE(   767.00), SIMDE_FLOAT16_VALUE(  -738.50), SIMDE_FLOAT16_VALUE(   581.50),
        SIMDE_FLOAT16_VALUE(  -342.00), SIMDE_FLOAT16_VALUE(   580.50), SIMDE_FLOAT16_VALUE(   534.00), SIMDE_FLOAT16_VALUE(  -671.00) },
      { SIMDE_FLOAT16_VALUE(  -482.75), SIMDE_FLOAT16_VALUE(   382.25), SIMDE_FLOAT16_VALUE(   503.00), SIMDE_FLOAT16_VALUE(    35.00),
        SIMDE_FLOAT16_VALUE(   315.50), SIMDE_FLOAT16_VALUE(   -23.56), SIMDE_FLOAT16_VALUE(    53.88), SIMDE_FLOAT16_VALUE(   722.00) },
       INT32_C(           3),
      { SIMDE_FLOAT16_VALUE(-31696.00), SIMDE_FLOAT16_VALUE(-31104.00), SIMDE_FLOAT16_VALUE( 25248.00), SIMDE_FLOAT16_VALUE( 25184.00),
        SIMDE_FLOAT16_VALUE( 11056.00), SIMDE_FLOAT16_VALUE( 12648.00), SIMDE_FLOAT16_VALUE(-17920.00), SIMDE_FLOAT16_VALUE(-18672.00) } },
    { { SIMDE_FLOAT16_VALUE(   525.50), SIMDE_FLOAT16_VALUE(  -679.00), SIMDE_FLOAT16_VALUE(   491.50), SIMDE_FLOAT16_VALUE(  -505.00),
        SIMDE_FLOAT16_VALUE(   914.50), SIMDE_FLOAT16_VALUE(  -312.00), SIMDE_FLOAT16_VALUE(  -404.50), SIMDE_FLOAT16_VALUE(  -634.00) },
      { SIMDE_FLOAT16_VALUE(   -86.62), SIMDE_FLOAT16_VALUE(  -914.50), SIMDE_FLOAT16_VALUE(  -839.50), SIMDE_FLOAT16_VALUE(   817.50),
        SIMDE_FLOAT16_VALUE(  -187.25), SIMDE_FLOAT16_VALUE(   422.75), SIMDE_FLOAT16_VALUE(   604.50), SIMDE_FLOAT16_VALUE(  -735.00) },
      { SIMDE_FLOAT16_VALUE(   -21.31), SIMDE_FLOAT16_VALUE(   -29.59), SIMDE_FLOAT16_VALUE(  -725.00), SIMDE_FLOAT16_VALUE(  -503.00),
        SIMDE_FLOAT16_VALUE(   -75.56), SIMDE_FLOAT16_VALUE(   215.38), SIMDE_FLOAT16_VALUE(  -742.00), SIMDE_FLOAT16_VALUE(  -854.00) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE( -1321.00), SIMDE_FLOAT16_VALUE( -2526.00), SIMDE_FLOAT16_VALUE(-17408.00), SIMDE_FLOAT16_VALUE(-18400.00),
        SIMDE_FLOAT16_VALUE( -3076.00), SIMDE_FLOAT16_VALUE( -4304.00), SIMDE_FLOAT16_VALUE( 12480.00), SIMDE_FLOAT16_VALUE( 12248.00) } },
    { { SIMDE_FLOAT16_VALUE(  -618.50), SIMDE_FLOAT16_VALUE(   164.88), SIMDE_FLOAT16_VALUE(   304.75), SIMDE_FLOAT16_VALUE(  -530.50),
        SIMDE_FLOAT16_VALUE(  -603.50), SIMDE_FLOAT16_VALUE(   730.50), SIMDE_FLOAT16_VALUE(    46.66), SIMDE_FLOAT16_VALUE(   629.00) },
      { SIMDE_FLOAT16_VALUE(  -537.00), SIMDE_FLOAT16_VALUE(   637.00), SIMDE_FLOAT16_VALUE(   884.50), SIMDE_FLOAT16_VALUE(   378.25),
        SIMDE_FLOAT16_VALUE(   -10.17), SIMDE_FLOAT16_VALUE(  -730.00), SIMDE_FLOAT16_VALUE(  -981.50), SIMDE_FLOAT16_VALUE(   453.25) },
      { SIMDE_FLOAT16_VALUE(  -575.00), SIMDE_FLOAT16_VALUE(    12.88), SIMDE_FLOAT16_VALUE(  -667.50), SIMDE_FLOAT16_VALUE(   380.50),
        SIMDE_FLOAT16_VALUE(   374.75), SIMDE_FLOAT16_VALUE(  -222.50), SIMDE_FLOAT16_VALUE(   206.88), SIMDE_FLOAT16_VALUE(   502.25) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(  6300.00), SIMDE_FLOAT16_VALUE(  7084.00), SIMDE_FLOAT16_VALUE(-11088.00), SIMDE_FLOAT16_VALUE(-11928.00),
        SIMDE_FLOAT16_VALUE(  -472.50), SIMDE_FLOAT16_VALUE(   861.50), SIMDE_FLOAT16_VALUE( 12688.00), SIMDE_FLOAT16_VALUE( 13272.00) } },
    { { SIMDE_FLOAT16_VALUE(  -825.50), SIMDE_FLOAT16_VALUE(  -472.75), SIMDE_FLOAT16_VALUE(  -531.00), SIMDE_FLOAT16_VALUE(  -366.75),
        SIMDE_FLOAT16_VALUE(   143.12), SIMDE_FLOAT16_VALUE(   698.50), SIMDE_FLOAT16_VALUE(   700.00), SIMDE_FLOAT16_VALUE(   498.25) },
      { SIMDE_FLOAT16_VALUE(   908.00), SIMDE_FLOAT16_VALUE(   845.50), SIMDE_FLOAT16_VALUE(  -383.50), SIMDE_FLOAT16_VALUE(   383.50),
        SIMDE_FLOAT16_VALUE(   357.75), SIMDE_FLOAT16_VALUE(  -900.50), SIMDE_FLOAT16_VALUE(  -802.00), SIMDE_FLOAT16_VALUE(   966.50) },
      { SIMDE_FLOAT16_VALUE(  -993.00), SIMDE_FLOAT16_VALUE(   477.50), SIMDE_FLOAT16_VALUE(   -23.00), SIMDE_FLOAT16_VALUE(   102.38),
        SIMDE_FLOAT16_VALUE(   988.50), SIMDE_FLOAT16_VALUE(  -311.75), SIMDE_FLOAT16_VALUE(  -668.50), SIMDE_FLOAT16_VALUE(   148.25) },
       INT32_C(           2),
      { SIMDE_FLOAT16_VALUE( 20064.00), SIMDE_FLOAT16_VALUE( 20416.00), SIMDE_FLOAT16_VALUE( -9352.00), SIMDE_FLOAT16_VALUE( -9184.00),
        SIMDE_FLOAT16_VALUE(  8368.00), SIMDE_FLOAT16_VALUE(  8928.00), SIMDE_FLOAT16_VALUE(-17744.00), SIMDE_FLOAT16_VALUE(-17952.00) } },
    { { SIMDE_FLOAT16_VALUE(   213.88), SIMDE_FLOAT16_VALUE(   337.75), SIMDE_FLOAT16_VALUE(   330.50), SIMDE_FLOAT16_VALUE(   -88.56),
        SIMDE_FLOAT16_VALUE(   191.12), SIMDE_FLOAT16_VALUE(  -615.00), SIMDE_FLOAT16_VALUE(  -113.25), SIMDE_FLOAT16_VALUE(   775.50) },
      { SIMDE_FLOAT16_VALUE(   295.50), SIMDE_FLOAT16_VALUE(   687.00), SIMDE_FLOAT16_VALUE(   406.25), SIMDE_FLOAT16_VALUE(   439.50),
        SIMDE_FLOAT16_VALUE(  -827.50), SIMDE_FLOAT16_VALUE(   733.00), SIMDE_FLOAT16_VALUE(   499.00), SIMDE_FLOAT16_VALUE(   931.00) },
      { SIMDE_FLOAT16_VALUE(   790.00), SIMDE_FLOAT16_VALUE(  -979.00), SIMDE_FLOAT16_VALUE(    70.62), SIMDE_FLOAT16_VALUE(   -47.00),
        SIMDE_FLOAT16_VALUE(   228.50), SIMDE_FLOAT16_VALUE(  -233.50), SIMDE_FLOAT16_VALUE(  -467.50), SIMDE_FLOAT16_VALUE(   545.00) },
       INT32_C(           3),
      { SIMDE_FLOAT16_VALUE( 14104.00), SIMDE_FLOAT16_VALUE( 14224.00), SIMDE_FLOAT16_VALUE( 19424.00), SIMDE_FLOAT16_VALUE( 19008.00),
        SIMDE_FLOAT16_VALUE(-38688.00), SIMDE_FLOAT16_VALUE(-39520.00), SIMDE_FLOAT16_VALUE( 23344.00), SIMDE_FLOAT16_VALUE( 24224.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t r_ = simde_vld1q_f16(test_vec[i].r_);
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
     
    // simde_float16x8_t r = simde_vcmlaq_rot180_laneq_f16(r_, a, b, test_vec[i].lane);
    // simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);

    simde_float16x8_t r;
    SIMDE_CONSTIFY_4_(simde_vcmlaq_rot180_laneq_f16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f16(SIMDE_FLOAT16_VALUE(0.0))), test_vec[i].lane, r_, a, b);
    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }
  
  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 0, 1, 2, 3 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t r_ = simde_test_arm_neon_random_f16x8(-1000.0f, 1000.0f);
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-1000.0f, 1000.0f);
    simde_float16x8_t b = simde_test_arm_neon_random_f16x8(-1000.0f, 1000.0f);
    simde_float16x8_t r = simde_vcmlaq_laneq_f16(r_, a, b, lanes[i]);


    simde_test_arm_neon_write_f16x8(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmlaq_rot180_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t r_[4];
    simde_float32_t a[4];
    simde_float32_t b[4];
    const int lane;
    simde_float32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   355.18), SIMDE_FLOAT32_C(   169.63), SIMDE_FLOAT32_C(   116.87), SIMDE_FLOAT32_C(  -467.19) },
      { SIMDE_FLOAT32_C(  -513.94), SIMDE_FLOAT32_C(  -999.71), SIMDE_FLOAT32_C(  -285.25), SIMDE_FLOAT32_C(  -931.88) },
      { SIMDE_FLOAT32_C(  -839.57), SIMDE_FLOAT32_C(  -681.40), SIMDE_FLOAT32_C(  -117.60), SIMDE_FLOAT32_C(  -459.86) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-431133.437500), SIMDE_FLOAT32_C(-431318.968750), SIMDE_FLOAT32_C(-239370.468750), SIMDE_FLOAT32_C(-239954.531250) } },
    { { SIMDE_FLOAT32_C(   -57.67), SIMDE_FLOAT32_C(  -897.07), SIMDE_FLOAT32_C(   118.98), SIMDE_FLOAT32_C(  -387.92) },
      { SIMDE_FLOAT32_C(  -362.79), SIMDE_FLOAT32_C(   160.99), SIMDE_FLOAT32_C(    -2.72), SIMDE_FLOAT32_C(   206.65) },
      { SIMDE_FLOAT32_C(    49.34), SIMDE_FLOAT32_C(   511.85), SIMDE_FLOAT32_C(   547.20), SIMDE_FLOAT32_C(  -119.58) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(185636.390625), SIMDE_FLOAT32_C(184797.000000), SIMDE_FLOAT32_C(1511.212036), SIMDE_FLOAT32_C(1004.312012) } },
    { { SIMDE_FLOAT32_C(  -219.54), SIMDE_FLOAT32_C(  -959.14), SIMDE_FLOAT32_C(   943.92), SIMDE_FLOAT32_C(   628.48) },
      { SIMDE_FLOAT32_C(   446.65), SIMDE_FLOAT32_C(  -500.77), SIMDE_FLOAT32_C(  -347.79), SIMDE_FLOAT32_C(   813.11) },
      { SIMDE_FLOAT32_C(  -542.25), SIMDE_FLOAT32_C(   232.48), SIMDE_FLOAT32_C(   684.35), SIMDE_FLOAT32_C(   710.26) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(241976.421875), SIMDE_FLOAT32_C(241236.812500), SIMDE_FLOAT32_C(-187645.218750), SIMDE_FLOAT32_C(-187960.656250) } },
    { { SIMDE_FLOAT32_C(   783.09), SIMDE_FLOAT32_C(  -727.02), SIMDE_FLOAT32_C(  -586.46), SIMDE_FLOAT32_C(    64.33) },
      { SIMDE_FLOAT32_C(  -490.08), SIMDE_FLOAT32_C(   740.49), SIMDE_FLOAT32_C(  -591.56), SIMDE_FLOAT32_C(  -759.78) },
      { SIMDE_FLOAT32_C(  -380.84), SIMDE_FLOAT32_C(   993.01), SIMDE_FLOAT32_C(  -759.56), SIMDE_FLOAT32_C(   861.16) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(487437.437500), SIMDE_FLOAT32_C(485927.312500), SIMDE_FLOAT32_C(586838.562500), SIMDE_FLOAT32_C(587489.312500) } },
    { { SIMDE_FLOAT32_C(   998.31), SIMDE_FLOAT32_C(   538.40), SIMDE_FLOAT32_C(  -191.12), SIMDE_FLOAT32_C(  -434.48) },
      { SIMDE_FLOAT32_C(   592.83), SIMDE_FLOAT32_C(   820.32), SIMDE_FLOAT32_C(  -296.84), SIMDE_FLOAT32_C(  -612.30) },
      { SIMDE_FLOAT32_C(  -552.34), SIMDE_FLOAT32_C(   329.08), SIMDE_FLOAT32_C(   765.26), SIMDE_FLOAT32_C(  -531.08) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(328442.062500), SIMDE_FLOAT32_C(327982.156250), SIMDE_FLOAT32_C(-164147.734375), SIMDE_FLOAT32_C(-164391.093750) } },
    { { SIMDE_FLOAT32_C(    52.61), SIMDE_FLOAT32_C(   606.93), SIMDE_FLOAT32_C(  -894.22), SIMDE_FLOAT32_C(  -854.38) },
      { SIMDE_FLOAT32_C(   972.80), SIMDE_FLOAT32_C(  -807.39), SIMDE_FLOAT32_C(   668.59), SIMDE_FLOAT32_C(  -228.19) },
      { SIMDE_FLOAT32_C(  -528.51), SIMDE_FLOAT32_C(   730.93), SIMDE_FLOAT32_C(  -230.95), SIMDE_FLOAT32_C(  -140.17) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(-710996.062500), SIMDE_FLOAT32_C(-710441.750000), SIMDE_FLOAT32_C(-489586.718750), SIMDE_FLOAT32_C(-489546.875000) } },
    { { SIMDE_FLOAT32_C(   556.73), SIMDE_FLOAT32_C(  -701.90), SIMDE_FLOAT32_C(  -356.50), SIMDE_FLOAT32_C(  -532.42) },
      { SIMDE_FLOAT32_C(   856.94), SIMDE_FLOAT32_C(  -261.67), SIMDE_FLOAT32_C(  -208.07), SIMDE_FLOAT32_C(    27.93) },
      { SIMDE_FLOAT32_C(   924.32), SIMDE_FLOAT32_C(  -863.60), SIMDE_FLOAT32_C(  -687.65), SIMDE_FLOAT32_C(   238.39) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-791530.062500), SIMDE_FLOAT32_C(-792788.687500), SIMDE_FLOAT32_C(191966.765625), SIMDE_FLOAT32_C(191790.843750) } },
    { { SIMDE_FLOAT32_C(  -286.79), SIMDE_FLOAT32_C(   630.61), SIMDE_FLOAT32_C(  -989.22), SIMDE_FLOAT32_C(   223.21) },
      { SIMDE_FLOAT32_C(   812.31), SIMDE_FLOAT32_C(   667.33), SIMDE_FLOAT32_C(   841.41), SIMDE_FLOAT32_C(   735.52) },
      { SIMDE_FLOAT32_C(   308.52), SIMDE_FLOAT32_C(  -189.06), SIMDE_FLOAT32_C(   -63.33), SIMDE_FLOAT32_C(   837.76) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(153288.531250), SIMDE_FLOAT32_C(154205.937500), SIMDE_FLOAT32_C(158087.750000), SIMDE_FLOAT32_C(159300.171875) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t r_ = simde_vld1q_f32(test_vec[i].r_);
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r;
    SIMDE_CONSTIFY_2_(simde_vcmlaq_rot180_laneq_f32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f32(SIMDE_FLOAT32_C(0.0))), test_vec[i].lane, r_, a, b);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);

    // simde_float32x4_t r = simde_vcmlaq_rot180_laneq_f32(r_, a, b, test_vec[i].lane);
    // simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  
  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t r_ = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_vcmlaq_rot180_laneq_f32(r_, a, b, lanes[i]);


    simde_test_arm_neon_write_f32x4(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot180_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot180_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot180_laneq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot180_laneq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot180_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot180_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot180_laneq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot180_laneq_f32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"