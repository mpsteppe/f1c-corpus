// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00594BCD
// Canonical corpus name: CounterThreshold
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CounterThreshold_00594bcd.c

void UnknownObject::AllocatorPageCounterAndTrim()
{
    // Accumulates a byte value into a per-page counter of an allocator tracking array and triggers an allocator trim when thresholds are reached. Computes the page index from an address: (a2 - *(a1+16)) >> 12 (4096-byte pages), addressing an 8-byte-stride counter element at a1 + 24. Adds the input byte (*a3) to the counter, clears *a3, and writes the marker 241 into the element's second dword. When the counter equals 240 and the incremented global live-page counter dword_8D41B8 reaches 32, calls sub_594AB4(16) to trim/decommit allocator pages. Existing analysis labels it an allocator page counter and trim (DERIVED, not confirmed).
    // CALCULATION: Computes the page index (a2 - *(a1+16)) >> 12 using the page base stored at this+0x10, then indexes the 8-byte-stride counter array at a1+24. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Adds the unsigned byte value *a3 to the page counter and clears *a3 to 0. [source:raw]
    // ASSIGNMENT: Writes the marker value 241 into the counter element's second dword (v3[1]). [source:raw]
    // GUARD: Triggers the trim call only when the page counter equals 240 and the incremented global dword_8D41B8 equals 32. [global:0x008D41B8, source:raw]
    // CALL: Calls sub_594AB4(16), trimming/decommitting allocator pages with the given limit of 16. [callee:0x00594AB4, source:raw]

    // Conservative worker pseudocode:
    //   pageIndex = (a2 - *(a1 + 16)) >> 12;
    //   v3 = (_DWORD*)(a1 + 8*pageIndex + 24);
    //   *v3 += (unsigned char)*a3;
    //   *a3 = 0;
    //   v3[1] = 241;
    //   if (*v3 == 240 && ++dword_8D41B8 == 32)
    //       sub_594AB4(16);
    // UNRESOLVED: The allocator-context interpretation (page base, counter array, trim role of sub_594AB4) comes from existing analysis prose and is DERIVED, not confirmed.
    // UNRESOLVED: Meaning of the marker value 241 in the counter element's second dword is not established.
    // UNRESOLVED: Why the counter threshold is 240 while the trim marker is 241 is unexplained.
}
