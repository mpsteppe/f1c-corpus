// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005908B0
// Canonical corpus name: ExtendedPrecisionDivisionWithOverflowFixup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ExtendedPrecisionDivisionWithOverflowFixup_005908b0.c

void UnknownObject::ExtendedPrecisionDivisionWithOverflowFixup()
{
    // Performs 80-bit extended-precision (_TBYTE) division returning a double, with overflow fixup. The 64-bit mantissas of a1 and a2 are loaded as doubles (v3, v2). A loop normalizes a1 by scaling its mantissa with flt_5E74F8 until the mantissa integer bit is set, with guarded early returns when a1 is zero, a1/a2 exponents are in ordinary range, or a2 is infinite/NaN/denormal. After the loop, a synthesized index v4 = (2 * DWORD1(a1)) XOR 0xE000000 is tested against a 0xE000000 mask and then used to index the byte_5E74E0 lookup table; zero table entries or zero/infinity a1 exponents cause a direct return of v2 / v3. When the table accepts the range, both operands are scaled by flt_5E74F4 (a2 exponent field == 1) or flt_5E74F0 (otherwise) before dividing, so the quotient stays within double range. Called by DoubleArithmeticWrapper (0x005910A1).
    // ASSIGNMENT: Load v2 as the low 64 bits of operand a2 reinterpreted as a double (mantissa of a2). [source:raw, function:0x005908B0]
    // ASSIGNMENT: Load v3 as the low 64 bits of operand a1 reinterpreted as a double (mantissa of a1). [source:raw]
    // LOOP: While doubling DWORD1(a1), the high dword of a1's 64-bit mantissa, produces no carry (mantissa integer bit clear), keep normalizing a1: the loop body either returns early or scales the mantissa by flt_5E74F8. [source:raw, global:0x005E74F8]
    // GUARD: Inside loop: if a1's low 64 bits are zero, or a1's exponent field (HIWORD(a1) & 0x7FFF) is non-zero, return v2 / v3 directly (no normalization needed). [source:raw]
    // GUARD: Inside loop, a2 exponent non-zero branch: if a2's exponent field equals 0x7FFF (infinity/NaN) or doubling DWORD1(a2) produces no carry, return v2 / v3 directly. [source:raw]
    // GUARD: Inside loop, a2 exponent zero branch: if doubling DWORD1(a2) produces a carry (denormal a2), return v2 / v3 directly. [source:raw]
    // ASSIGNMENT: Scale a1's mantissa by flt_5E74F8 (normalization multiplier), store it back as the double mantissa of a1, and refresh v2 from a2; the loop repeats until the carry condition is met. [source:raw, global:0x005E74F8]
    // CALCULATION: After the loop: compute v4 = (2 * DWORD1(a1)) XOR 0xE000000; if (v4 & 0xE000000) is non-zero, return v2 / v3 directly (out-of-range exponent classification). [source:raw]
    // GUARD: If the byte_5E74E0 lookup-table entry at index (v4 >> 28) is zero, return v2 / v3 directly (unsupported exponent class). [global:0x005E74E0]
    // GUARD: If a1's exponent field is zero or 0x7FFF, return v2 / v3 directly (zero, infinity or NaN). [source:raw]
    // GUARD: Select the scaling constant from a2's exponent field: factor = flt_5E74F4 when the field is 1, otherwise factor = flt_5E74F0. [global:0x005E74F4, global:0x005E74F0]
    // RETURN: Return v2 * flt_5E74F4 / (v3 * flt_5E74F4) when a2's exponent field equals 1 (both operands scaled by flt_5E74F4 before division). [global:0x005E74F4]
    // RETURN: Return v2 * flt_5E74F0 / (v3 * flt_5E74F0) otherwise (both operands scaled by flt_5E74F0 before division). [global:0x005E74F0]

    // Conservative worker pseudocode:
    //   double ExtendedPrecisionDivisionWithOverflowFixup(_TBYTE a1, _TBYTE a2) {
    //     double v3 = *(double *)&a1;
    //     double v2 = *(double *)&a2;
    //     while (!__CFADD__(DWORD1(a1), DWORD1(a1))) {
    //       if (!*(_QWORD *)&a1 || (HIWORD(a1) & 0x7FFF) != 0)
    //         return v2 / v3;
    //       if ((HIWORD(a2) & 0x7FFF) != 0) {
    //         if ((HIWORD(a2) & 0x7FFF) == 0x7FFF || !__CFADD__(DWORD1(a2), DWORD1(a2)))
    //           return v2 / v3;
    //       } else if (__CFADD__(DWORD1(a2), DWORD1(a2))) {
    //         return v2 / v3;
    //       }
    //       *(double *)&a1 = v3 * flt_5E74F8;
    //       v2 = *(double *)&a2;
    //     }
    //     unsigned int v4 = (2 * DWORD1(a1)) ^ 0xE000000;
    //     if ((v4 & 0xE000000) != 0) return v2 / v3;
    //     if (!byte_5E74E0[v4 >> 28]) return v2 / v3;
    //     if ((HIWORD(a1) & 0x7FFF) == 0 || (HIWORD(a1) & 0x7FFF) == 0x7FFF) return v2 / v3;
    //     if ((HIWORD(a2) & 0x7FFF) == 1)
    //       return v2 * flt_5E74F4 / (v3 * flt_5E74F4);
    //     else
    //       return v2 * flt_5E74F0 / (v3 * flt_5E74F0);
    //   }
    // UNRESOLVED: The byte_5E74E0 lookup table (indexed by (2 * DWORD1(a1)) XOR 0xE000000) >> 28) and the meaning of its entries are not described by packet evidence.
    // UNRESOLVED: The exact numeric values and roles of the scaling constants flt_5E74F0, flt_5E74F4, flt_5E74F8 are absent from the packet; confirming the fixup math requires their values.
    // UNRESOLVED: The construction of index v4 and the meaning of the 0xE000000 mask (exponent/range classification) are not fully derivable from packet evidence alone.
    // UNRESOLVED: The owning module/class is unknown; the only linkage is the legacy ABI tag Extended_Precision_Division_with_Overflow_Fixup and the single caller DoubleArithmeticWrapper (0x005910A1).
}
