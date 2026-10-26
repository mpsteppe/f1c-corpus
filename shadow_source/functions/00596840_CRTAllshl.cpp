// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00596840
// Canonical corpus name: CRTAllshl
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CRTAllshl_00596840.c

void UnknownObject::CRTAllshl()
{
    // 64-bit left-shift helper identified by the ABI record as the CRT ___allshl routine. Shifts the 64-bit value a1 (edx:eax) left by the count a2 (cl): a count of at least 0x40 yields a zero result, a count in [0x20, 0x40) zeroes the low 32 bits of the result, and a smaller count returns a1 shifted by (a2 & 0x1F). Invoked by sub_58E4D2 as the 64-bit shift helper.
    // GUARD: If the shift count a2 is at least 0x40 the shift is out of range and the result is zero. [source:raw]
    // GUARD: Else if a2 is at least 0x20, only the low 32 bits of the result are zeroed (LODWORD(v2) = 0); the decompiled text shows no high-word assignment on this path. [source:raw]
    // CALCULATION: For a count below 0x20 the value is shifted by (a2 & 0x1F): a1 << (a2 & 0x1F). [source:raw]
    // RETURN: Return v2 on the count >= 0x20 paths; the ABI record identifies the routine as CRT ___allshl. [abi:lead, function:0x00596840, source:raw]
    // CALL: Invoked by sub_58E4D2 (0x0058E4D2) as the 64-bit left-shift helper. [caller:0x0058E4D2, source:raw]

    // Conservative worker pseudocode:
    //   __int64 CRTAllshl(__int64 a1, unsigned __int8 shift) {
    //     if (shift >= 0x40) return 0;
    //     if (shift >= 0x20) { LODWORD(v2) = 0; return v2; }  // high word not assigned in the decompiled text
    //     return a1 << (shift & 0x1F);
    //   }
    // UNRESOLVED: On the a2 in [0x20, 0x40) path the decompiled text zeroes only LODWORD(v2) and leaves the high dword uninitialized; canonical CRT ___allshl semantics would place the shifted low dword into the high dword, but this packet cannot confirm that transfer.
    // UNRESOLVED: Why this helper returns zero for counts in the [0x20, 0x40) range rather than the canonical high-dword result is not established by this packet alone.
}
