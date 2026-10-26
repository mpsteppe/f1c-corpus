// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046C710
// Canonical corpus name: GlobalArrayScanForNegative
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalArrayScanForNegative_0046c710.c

void UnknownObject::GlobalArrayScanForNegative()
{
    // Scans one of two global 32-bit arrays looking for the first negative entry. The byte flag at this+0x174 selects the array: non-zero scans dword_7CD2B8..flt_7CD458 (exclusive), zero scans dword_7CD470..flt_7CD610 (exclusive). Returns the index of the first negative entry, or the full element count when no negative entry exists.
    // GUARD: Reads the flag byte at this+0x174; non-zero selects the dword_7CD2B8..flt_7CD458 array, zero selects the dword_7CD470..flt_7CD610 array [field:this:0x00000174, source:raw]
    // LOOP: Walks the selected array element by element (dword_7CD2B8..flt_7CD458 for the first branch, dword_7CD470..flt_7CD610 for the second), accumulating the scanned count [global:0x007CD2B8, global:0x007CD458, global:0x007CD470, global:0x007CD610, source:raw]
    // GUARD: Inside the loop, breaks as soon as the current array element is negative, freezing the accumulated count [global:0x007CD2B8, global:0x007CD470, source:raw]
    // RETURN: Returns the scanned count: the index of the first negative entry if the loop broke early, otherwise the full element count of the scanned array [function:0x0046C710, source:raw]

    // Conservative worker pseudocode:
    //   result = 0;
    //   if (this[0x174] != 0) {
    //     v2 = &dword_7CD2B8;
    //     do { if (*v2 < 0) break; ++v2; ++result; }
    //     while (v2 < &flt_7CD458);
    //   } else {
    //     v3 = &dword_7CD470;
    //     do { if (*v3 < 0) break; ++v3; ++result; }
    //     while (v3 < &flt_7CD610);
    //   }
    //   return result;
    // UNRESOLVED: The meaning of a negative entry (existing analysis proposes an empty/invalid slot in a collision/contact array, DERIVED only) is not proven by this packet
    // UNRESOLVED: The object owning the this+0x174 selection flag is unidentified
    // UNRESOLVED: Both array ranges end at a bound expressed through flt_7CD458 / flt_7CD610; whether those are true array ends or sentinel addresses is not established
}
