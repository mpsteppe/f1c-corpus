// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C0B10
// Canonical corpus name: PitStopMemoryCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PitStopMemoryCleanup_004c0b10.c

void UnknownObject::PitStopMemoryCleanup()
{
    // Career-standings structure teardown. First frees two dynamically allocated pointers held at dword indices 11338 (byte 0xB128) and 11336 (byte 0xB120), each guarded against null. Then runs sub_49A270 once on the topmost per-driver block at dword index 11227 (byte 0xAF6C) and again on 103 further blocks stepping downward by 109 dwords (0x1B4 bytes), covering 104 contiguous blocks from byte 0 down to byte 0xAF6C. Called by DoubleListCleanup, LinkedListNodeRemovalWithCleanup, PlayerCareerStatsGameOptionsLoader, sub_4C1E20, GameOptionsWriter and DualListDestructionWithDeepCleanup.
    // GUARD: Guard on pointer at dword 11338 (byte 0xB128): freed only when non-null. [field:this:0x0000B128, source:raw]
    // CALL: FreeWrapper_7bcf frees the pointer at dword 11338 (byte 0xB128) when non-null. [callee:0x00587BCF, field:this:0x0000B128, source:raw]
    // GUARD: Guard on pointer at dword 11336 (byte 0xB120): freed only when non-null. [field:this:0x0000B120, source:raw]
    // CALL: FreeWrapper_7bcf frees the pointer at dword 11336 (byte 0xB120) when non-null. [callee:0x00587BCF, field:this:0x0000B120, source:raw]
    // ASSIGNMENT: Initialize the cleanup cursor v2 to this + dword 11227 (byte 0xAF6C), the first per-driver block. [source:raw]
    // CALL: sub_49A270 runs cleanup on the topmost block at dword 11227 (byte 0xAF6C). [callee:0x0049A270, source:raw]
    // LOOP: do-while counter v3 = 103: each iteration steps the cursor down by 109 dwords (0x1B4 bytes) and runs sub_49A270 on the next block, until the counter reaches zero; total 104 sub_49A270 invocations from dword 11227 down to dword 0. [callee:0x0049A270, source:raw]
    // RETURN: Return the result value carried from the last cleanup call. [source:raw]

    // Conservative worker pseudocode:
    //   void sub_4C0B10(void** this) {
    //     if (this[11338]) FreeWrapper_7bcf(this[11338]);
    //     if (this[11336]) FreeWrapper_7bcf(this[11336]);
    //     int* b = (int*)this + 11227;
    //     sub_49A270(b);
    //     int n = 103;
    //     do { b -= 109; sub_49A270(b); --n; } while (n);
    //   }
    // UNRESOLVED: The meaning of the two freed pointers (dword 11336 / 0xB120 and 11338 / 0xB128) is not established by this packet; existing analysis calls them pit-stop and driver-data allocations, unverified.
    // UNRESOLVED: The per-block layout torn down by sub_49A270 (109 dwords per block) is undefined here; only relative offsets are known.
    // UNRESOLVED: sub_49A270 is identified as a cleanup/release helper only by existing-analysis prose; the packet proves the call, not the purpose.
}
