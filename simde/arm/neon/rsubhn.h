/* SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Copyright:
 *   2023      Yi-Yen Chung <eric681@andestech.com> (Copyright owned by Andes Technology)
 *   2023      Chi-Wei Chu <wewe5215@gapp.nthu.edu.tw> (Copyright owned by NTHU pllab)
 */

#if !defined(SIMDE_ARM_NEON_RSUBHN_H)
#define SIMDE_ARM_NEON_RSUBHN_H

#include "sub.h"
#include "shr_n.h"
#include "movn.h"

#include "reinterpret.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x8_t
simde_vrsubhn_s16(simde_int16x8_t a, simde_int16x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vrsubhn_s16(a, b);
  #else
    simde_int16x8_private
      r_,
      a_ = simde_int16x8_to_private(a),
      b_ = simde_int16x8_to_private(b);
    int16_t round_cast = 1 << 7;
    #if defined(SIMDE_RISCV_V_NATIVE)
        r_.sv128 = __riscv_vadd_vx_i16m1(__riscv_vsub_vv_i16m1(a_.sv128, b_.sv128, 8), round_cast, 8);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = HEDLEY_STATIC_CAST(int16_t, a_.values[i] - b_.values[i] + round_cast);
      }
    #endif
    return simde_vmovn_s16(simde_vshrq_n_s16(simde_int16x8_from_private(r_), 8));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrsubhn_s16
  #define vrsubhn_s16(a, b) simde_vrsubhn_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x4_t
simde_vrsubhn_s32(simde_int32x4_t a, simde_int32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vrsubhn_s32(a, b);
  #else
    simde_int32x4_private
      r_,
      a_ = simde_int32x4_to_private(a),
      b_ = simde_int32x4_to_private(b);
    int round_cast = 1 << 15;
    #if defined(SIMDE_RISCV_V_NATIVE)
        r_.sv128 = __riscv_vadd_vx_i32m1(__riscv_vsub_vv_i32m1(a_.sv128, b_.sv128, 4), round_cast, 4);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] - b_.values[i] + round_cast;
      }
    #endif
    return simde_vmovn_s32(simde_vshrq_n_s32(simde_int32x4_from_private(r_), 16));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrsubhn_s32
  #define vrsubhn_s32(a, b) simde_vrsubhn_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x2_t
simde_vrsubhn_s64(simde_int64x2_t a, simde_int64x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vrsubhn_s64(a, b);
  #else
    simde_int64x2_private
      r_,
      a_ = simde_int64x2_to_private(a),
      b_ = simde_int64x2_to_private(b);
    #if defined(SIMDE_RISCV_V_NATIVE)
        r_.sv128 = __riscv_vadd_vx_i64m1(__riscv_vsub_vv_i64m1(a_.sv128, b_.sv128, 2), 0x80000000, 2);
        return simde_vmovn_s64(simde_vshrq_n_s64(simde_int64x2_from_private(r_), 32));
    #else
      int64_t round_cast = 1ll << 31;
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = ((a_.values[i] - b_.values[i] + round_cast) >> 32);
      }
      return simde_vmovn_s64(simde_int64x2_from_private(r_));
    #endif
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrsubhn_s64
  #define vrsubhn_s64(a, b) simde_vrsubhn_s64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x8_t
simde_vrsubhn_u16(simde_uint16x8_t a, simde_uint16x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vrsubhn_u16(a, b);
  #else
    simde_uint16x8_private
      r_,
      a_ = simde_uint16x8_to_private(a),
      b_ = simde_uint16x8_to_private(b);
    uint16_t round_cast = 1 << 7;
    #if defined(SIMDE_RISCV_V_NATIVE)
        r_.sv128 = __riscv_vadd_vx_u16m1(__riscv_vsub_vv_u16m1(a_.sv128, b_.sv128, 8), round_cast, 8);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = HEDLEY_STATIC_CAST(uint16_t, a_.values[i] - b_.values[i] + round_cast);
      }
    #endif
    return simde_vmovn_u16(simde_vshrq_n_u16(simde_uint16x8_from_private(r_), 8));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrsubhn_u16
  #define vrsubhn_u16(a, b) simde_vrsubhn_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4_t
simde_vrsubhn_u32(simde_uint32x4_t a, simde_uint32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vrsubhn_u32(a, b);
  #else
    simde_uint32x4_private
      r_,
      a_ = simde_uint32x4_to_private(a),
      b_ = simde_uint32x4_to_private(b);
    uint32_t round_cast = 1 << 15;
    #if defined(SIMDE_RISCV_V_NATIVE)
        r_.sv128 = __riscv_vadd_vx_u32m1(__riscv_vsub_vv_u32m1(a_.sv128, b_.sv128, 4), round_cast, 4);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] - b_.values[i] + round_cast;
      }
    #endif
    return simde_vmovn_u32(simde_vshrq_n_u32(simde_uint32x4_from_private(r_), 16));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrsubhn_u32
  #define vrsubhn_u32(a, b) simde_vrsubhn_u32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2_t
simde_vrsubhn_u64(simde_uint64x2_t a, simde_uint64x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vrsubhn_u64(a, b);
  #else
    simde_uint64x2_private
      r_,
      a_ = simde_uint64x2_to_private(a),
      b_ = simde_uint64x2_to_private(b);
    #if defined(SIMDE_RISCV_V_NATIVE)
        r_.sv128 = __riscv_vadd_vx_u64m1(__riscv_vsub_vv_u64m1(a_.sv128, b_.sv128, 2), 0x80000000, 2);
        return simde_vmovn_u64(simde_vshrq_n_u64(simde_uint64x2_from_private(r_), 32));
    #else
      uint64_t round_cast = 1ull << 31;
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = ((a_.values[i] - b_.values[i] + round_cast) >> 32);
      }
      return simde_vmovn_u64(simde_uint64x2_from_private(r_));
    #endif
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrsubhn_u64
  #define vrsubhn_u64(a, b) simde_vrsubhn_u64((a), (b))
#endif


SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_RSUBHN_H) */
