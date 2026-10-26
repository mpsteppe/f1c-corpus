// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00596100
// Canonical corpus name: sub_596100
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_596100_00596100.c

void UnknownObject::aulldvrm()
{
    // MSVC CRT unsigned 64-bit division-with-remainder helper (__aulldvrm) returning the remainder a1 mod a2. Mirrors aulldiv's normalization path but reconstructs the full divisor*quotient product and returns a1 minus that product; the 32-bit-divisor fallback returns a 64/32 mod using the native div instruction.
    // GUARD: Branch on the high 32 bits of divisor a2 being nonzero; if set, take the full 64-bit normalization path. [source:raw]
    // LOOP: Normalize: shift the 64-bit divisor right one bit at a time while its high word is nonzero, rotating the low bits into v5; shift the dividend v6 right in lockstep. [source:raw]
    // CALCULATION: Estimate the quotient (v6 / v5) and compute the partial product v9 = (unsigned)a2 * (v6 / v5), then fold in the high-word contribution v8 = HIDWORD(a2) * (v6 / v5) with carry detection. [source:raw]
    // GUARD: If the product carried or the assembled 64-bit product v9 exceeds a1, subtract a2 once to correct the product. [source:raw]
    // CALCULATION: Return a1 - v9, the remainder of the unsigned 64-bit division. [source:raw]
    // CALCULATION: Fallback path when the divisor fits in 32 bits: build v2 from the low 32 bits of a1 and (HIDWORD(a1) mod (unsigned)a2) as the high word, then return v2 mod (unsigned)a2. [source:raw]

    // Conservative worker pseudocode:
    //   unsigned __int64 aulldvrm(unsigned __int64 a1, unsigned __int64 a2) {
    //     if (a2 >> 32) {
    //       unsigned int hd = a2 >> 32, ld = (unsigned int)a2;
    //       unsigned __int64 dd = a1;
    //       while (hd) { ld = (ld >> 1) | ((hd & 1) << 31); hd >>= 1; dd >>= 1; }
    //       unsigned __int64 q = dd / ld;
    //       unsigned __int64 p = q * a2;
    //       if (__CFADD__(HIDWORD(a2) * (unsigned int)q, HIDWORD(p))) p += (unsigned __int64)(HIDWORD(a2) * (unsigned int)q) << 32;
    //       if (p > a1) p -= a2;
    //       return a1 - p;
    //     }
    //     return a1 % (unsigned int)a2;
    //   }
    // UNRESOLVED: The single caller sub_58D04D context is not analyzed; the division operands (likely normalized time or physics values) are unknown.
    // UNRESOLVED: This is a compiler runtime helper, not game logic; proposed_name aulldvrm is the conventional CRT label.
}
