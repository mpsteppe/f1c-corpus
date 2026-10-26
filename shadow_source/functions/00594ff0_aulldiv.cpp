// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00594FF0
// Canonical corpus name: sub_594FF0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_594FF0_00594ff0.c

void UnknownObject::aulldiv()
{
    // MSVC CRT unsigned 64-bit division helper (__aulldiv): returns a1 / a2 for 64-bit unsigned operands. When the divisor's high 32 bits are nonzero it normalizes both operands by right-shifting until the divisor fits a 32-bit register, performs a single 32-bit estimate division, then corrects the quotient if the full divisor*quotient product exceeds the dividend. When the divisor fits in 32 bits it falls back to a 64/32 division using the native div instruction.
    // GUARD: Branch on the high 32 bits of divisor a2 being nonzero; if set, take the full 64-bit normalization path. [source:raw]
    // LOOP: Normalize: shift the 64-bit divisor right one bit at a time while its high word is nonzero, rotating the low bits into the low 32-bit register v5 (v5 = (v5 >> 1) | (bit << 31)); shift the dividend v6 right in lockstep each iteration. [source:raw]
    // CALCULATION: Estimate the 32-bit quotient v8 = v6 / v5 using a single native division. [source:raw]
    // CALCULATION: Form the full product v9 = v8 * (unsigned)a2 and compare against the dividend: if v8 * HIDWORD(a2) overflows into the product's high word, or the assembled 64-bit product exceeds a1, decrement the quotient by one. [source:raw]
    // RETURN: Return the corrected quotient v8 as the division result. [source:raw]
    // CALCULATION: Fallback path when the divisor fits in 32 bits: build v3 from the low 32 bits of a1 and (HIDWORD(a1) mod (unsigned)a2) as the high word, then return v3 / (unsigned)a2. [source:raw]

    // Conservative worker pseudocode:
    //   unsigned int aulldiv(unsigned __int64 a1, unsigned __int64 a2) {
    //     if (a2 >> 32) {
    //       unsigned int hd = a2 >> 32, ld = (unsigned int)a2;
    //       unsigned __int64 dd = a1;
    //       while (hd) { ld = (ld >> 1) | ((hd & 1) << 31); hd >>= 1; dd >>= 1; }
    //       unsigned int q = (unsigned int)(dd / ld);
    //       if (__CFADD__(q * (a2 >> 32), ((q * a2) >> 32)) || ((q * a2) > a1)) --q;
    //       return q;
    //     }
    //     return (unsigned int)(a1 / (unsigned int)a2);
    //   }
    // UNRESOLVED: The single caller sub_58D04D context is not analyzed; the division operands (likely normalized time or physics values) are unknown.
    // UNRESOLVED: This is a compiler runtime helper, not game logic; proposed_name aulldiv is the conventional CRT label.
}
