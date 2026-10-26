// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00404CC0
// Canonical corpus name: QuickRace
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QuickRace_00404cc0.c

void UnknownObject::QuickRace()
{
    // Session-subsystem game-mode scan called from ConfigIniParser with argument a1: iterate index v1 over the 5-element pointer array at off_5BE6C4, calling sub_588410(a1, off_5BE6C4[v1]) at each step. While the callee returns nonzero the scan continues; if v1 reaches 5 the function returns 0; otherwise it returns the first index whose element makes sub_588410 return zero. ABI lead name QuickRace_Game_Mode_Lookup.
    // ASSIGNMENT: Initialize the scan index v1 to 0 before the loop. [source:raw]
    // CALL: Call sub_588410 with argument a1 and the v1-th element of the pointer array at off_5BE6C4 (read as *(&off_5BE6C4 + v1)). [callee:0x00588410, global:0x005BE6C4, source:raw]
    // LOOP: While sub_588410(a1, off_5BE6C4[v1]) is nonzero, increment v1 and repeat; the array holds 5 elements and the scan is bounded by the loop-exit check. [callee:0x00588410, global:0x005BE6C4, source:raw]
    // GUARD: If incrementing v1 makes it reach 5, the array is exhausted and the function returns 0. [source:raw]
    // RETURN: Return v1, the first array index whose element makes sub_588410 return zero; return 0 when the scan exhausts all five entries. [source:raw]

    // Conservative worker pseudocode:
    //   int QuickRace(int a1) {
    //       int v1 = 0;
    //       while (sub_588410(a1, off_5BE6C4[v1])) {
    //           if (++v1 >= 5) return 0;
    //       }
    //       return v1;
    //   }
    // UNRESOLVED: off_5BE6C4 is dereferenced as a 5-element dword pointer array; the packet does not state what the five entries point to.
    // UNRESOLVED: sub_588410's contract is not in this packet. Corpus-side IR (ir/functions/00588410.json) identifies it as a case-insensitive string compare returning strcmpi order; under that reading the loop returns the first array entry matching a1, and 0 means no match within five — this reading is DERIVED, not packet evidence.
    // UNRESOLVED: A no-match returns 0, identical to a match at index 0; the caller (ConfigIniParser, 0x00421CD0) disambiguates, but its config-token context is not in the packet.
    // UNRESOLVED: Owner is unknown; the raw source has no this pointer and no owning class is evidenced.
}
