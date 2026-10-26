// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005912BC
// Canonical corpus name: sub_5912BC
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5912BC_005912bc.c

void UnknownObject::FloatModulusWithDenormalHandling()
{
    // Floating-point helper taking two doubles via the x87 ST0/ST1 stack. When the divisor exponent field is non-zero it forwards to sub_5910B6 with a fast-path flag; otherwise it detects zero/denormal inputs, scales both operands by dbl_5E7514, and forwards to sub_5910B6 with a scale flag. Matches the legacy ABI label Float_Modulus_with_Denormal_Handling.
    // ASSIGNMENT: Copy a1 into the 16-byte local v6 and a2 into the 20-byte local v4 so their raw bit patterns can be inspected. [source:raw, function:0x005912BC]
    // GUARD: Test the exponent bits of a2 (bits 0x7FFF0000 of the upper dword). Non-zero exponent takes the fast path. [source:raw, abi:lead]
    // CALL: Fast path: call sub_5910B6(0, a2 bit pattern, a2 upper dword, scratch, a1 bit pattern). [callee:0x005910B6, source:raw]
    // CALCULATION: Zero/denormal path: OR the low two dwords of a2 to detect an all-zero significand. [source:raw]
    // GUARD: If a2 is non-zero (denormal, not exact zero) proceed to the scaling path; otherwise return the combined significand result. [source:raw]
    // CALCULATION: Set scaleFlag to 2; if the exponent of a1 is <= 0x7FBE, set scaleFlag to 3 and pre-scale a1 by dbl_5E7514. Scale a2 by dbl_5E7514. [global:0x005E7514, source:raw]
    // CALL: Scaled path: call sub_5910B6(scaleFlag, scaled a2 bit pattern, a2 upper dword, scratch, scaled/raw a1 bit pattern). [callee:0x005910B6, global:0x005E7514, source:raw]
    // RETURN: Return the combined zero significand result when a2 is exactly zero. [source:raw, function:0x005912BC]

    // Conservative worker pseudocode:
    //   lhsBits = lhs;
    //   rhsBits = rhs;
    //   if ((rhsBits.exponent_dwords & 0x7FFF0000) != 0) return sub_5910B6(0, rhs, ..., lhs);
    //   result = low_dword(rhs) | high_dword(rhs);
    //   if (rhs != 0.0) {
    //       scaleFlag = 2;
    //       if (lhs.exponent16 <= 0x7FBE) { scaleFlag = 3; lhs = lhs * dbl_5E7514; }
    //       rhs = rhs * dbl_5E7514;
    //       return sub_5910B6(scaleFlag, rhs, ..., lhs);
    //   }
    //   return result;
    // UNRESOLVED: The exact division/modulus contract of sub_5910B6 and the meaning of its flags (0, 2, 3) are not established from this packet alone.
    // UNRESOLVED: The role of the 0x7FBE exponent threshold and the scaling constant dbl_5E7514 (likely 2^k for denormal normalization) is DERIVED, not confirmed.
    // UNRESOLVED: The unused stack value v5 (passed as an argument to sub_5910B6) is unaccounted for.
}
