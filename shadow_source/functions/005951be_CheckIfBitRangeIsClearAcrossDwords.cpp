// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005951BE
// Canonical corpus name: CheckIfBitRangeIsClearAcrossDwords
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CheckIfBitRangeIsClearAcrossDwords_005951be.c

void UnknownObject::CheckIfBitRangeIsClearAcrossDwords()
{
    // Tests a 3-DWORD (96-bit) bit array at a1 for clear bits. The start index a2 is split into a DWORD index (a2/32) and an intra-word offset (a2%32). A mask ~(-1 << (31 - a2%32)) covers bit positions 0 through 30 - (a2%32) of the starting DWORD; if that masked region is nonzero the function returns 0. Otherwise it scans every following DWORD (indices a2/32+1 through 2) and returns 1 only if they are all zero; the first nonzero DWORD yields 0, and scanning past index 2 yields 1.
    // CALCULATION: Split a2 into a DWORD index (a2/32) and an intra-DWORD offset (a2%32) that sizes the mask. [source:raw]
    // GUARD: Build mask ~(-1 << (31 - a2%32)); its set bits cover positions 0 through 30 - (a2%32). Branch: if the mask ANDed with the DWORD at a1 + 4*(a2/32) is nonzero, a set bit is present and the function returns 0. [source:raw, function:0x005951BE]
    // CALCULATION: v2 = a2/32 + 1: the index of the first DWORD after the starting one. [source:raw]
    // GUARD: If v2 is already >= 3, the starting DWORD is the last in the array and the remaining range is trivially clear, so return 1. [source:raw, function:0x005951BE]
    // LOOP: Walk DWORDs from index v2: while the current DWORD is zero, advance to the next DWORD and increment v2; if v2 reaches 3, return 1. The loop exits as soon as a nonzero DWORD is found. [source:raw, function:0x005951BE]
    // RETURN: Return 0 when a nonzero DWORD is found in the starting word's masked region or during the scan; return 1 only when all scanned DWORDs are clear. [source:raw, function:0x005951BE]

    // Conservative worker pseudocode:
    //   if ((~(-1 << (31 - a2 % 32)) & *(DWORD*)(a1 + 4*(a2/32))) != 0) return 0;
    //   v2 = a2/32 + 1;
    //   if (v2 >= 3) return 1;
    //   for (i = (DWORD*)(a1 + 4*v2); !*i; ++i) {
    //     if (++v2 >= 3) return 1;
    //   }
    //   return 0;
    // UNRESOLVED: The mask ~(-1 << (31 - a2%32)) tests the LOW bits (positions 0 through 30 - (a2%32)) of the starting DWORD and leaves the top a2%32 + 1 bits untested. The ABI name suggests a from-bit-position range check (bits a2%32..31), which the literal mask does not implement; whether the mask is a real quirk or the check is meant to cover a different range is unresolved.
    // UNRESOLVED: The caller BitArrayClearBitAndZeroFillSubsequentWords (0059525D) implies a bit-array helper, but the exact contract is outside the packet's evidence.
    // UNRESOLVED: That a1 points to exactly 3 DWORDs is inferred from the constant 3 and the ABI name, not proven by the packet.
}
