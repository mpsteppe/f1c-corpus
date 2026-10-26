// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041EF00
// Canonical corpus name: ArrayScanForValue10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayScanForValue10_0041ef00.c

void UnknownObject::ArrayContainsValue10()
{
    // Reads a count/index v3 from the standings node at dword_7D2DB0 via LinkedListDereference and FlagsGetter, then scans the caller's dword array `this` backward from byte offset 4*v3+216 (dword index v3+54) in 4-byte steps while the dword value differs from 10, aborting when v3 drops below 0. Returns 1 when a dword equal to 10 is found, otherwise 0; also returns 0 when `this` is null or v3 is negative.
    // GUARD: Return 0 immediately when the `this` pointer is null. [function:0x0041EF00, source:raw]
    // CALL: Dereference the standings node from dword_7D2DB0 via LinkedListDereference into v2. [callee:0x004C2850, global:0x007D2DB0]
    // CALL: Read the count/index v3 from the resolved node via FlagsGetter. [callee:0x004C11D0]
    // GUARD: Return 0 when the count/index v3 is negative. [source:raw]
    // LOOP: Starting at byte offset 4*v3+216 (dword index v3+54), step the scan pointer i downward by 4 bytes while the dword at i differs from 10; each step decrements v3 and returns 0 when v3 drops below 0. [source:raw]
    // RETURN: Return 1 as soon as a dword equal to 10 is found within the scanned window; return 0 when the window is exhausted without a match. [source:raw]

    // Conservative worker pseudocode:
    //   char ContainsValue10(char *this) {
    //     if (!this) return 0;
    //     int v2 = LinkedListDereference(&dword_7D2DB0);
    //     int v3 = FlagsGetter(v2);
    //     if (v3 < 0) return 0;
    //     char *i = &this[4 * v3 + 216];
    //     while (*(int *)i != 10) {
    //       if (--v3 < 0) return 0;
    //       i -= 4;
    //     }
    //     return 1;
    //   }
    // UNRESOLVED: The meaning of the literal 10 (a sentinel/flag value) and of the scanned window bounded by the count v3 is not established by this packet.
    // UNRESOLVED: The owning class of `this` and the layout of the dword array around index v3+54 are not described by any packet evidence.
    // UNRESOLVED: Why the window starts at dword index v3+54 and only ever scans downward is not explained here.
}
