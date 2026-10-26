// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00404790
// Canonical corpus name: ShortComputation_4790
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_4790_00404790.c

void UnknownObject::WheelArrayIteratorUnregisteredCall()
{
    // Reads an entry count from this[0x130] and an array pointer from this[0x134], then iterates over that many entries (each 316 bytes apart), calling the unregistered helper 0x004FB5D0 with a pointer to each entry. Returns the entry count. When the count is not positive, the loop body never runs and the count is returned unchanged.
    // ASSIGNMENT: Load the entry count from this[0x130] as the result and loop bound. [field:this:0x00000130, source:raw]
    // GUARD: Guard: proceed only when the count in this[0x130] is greater than zero. [field:this:0x00000130, source:raw]
    // LOOP: do-while loop visiting each array entry, incrementing the visit counter until it reaches the stored count. [field:this:0x00000134, source:raw]
    // CALL: Call the unregistered helper 0x004FB5D0 with a pointer to the current entry (base this[0x134] plus index times stride). [callee:0x004FB5D0, source:raw]
    // CALCULATION: Advance the entry pointer by the 316-byte stride for the next iteration. [source:raw]
    // RETURN: Return the entry count (re-read from this[0x130] after the loop). [field:this:0x00000130, source:raw]

    // Conservative worker pseudocode:
    //   int sub_404790(int *this) {
    //     int count = this[76];
    //     int i = 0;
    //     if (count > 0) {
    //       int p = 0;
    //       do {
    //         sub_4FB5D0((char*)this[77] + p);
    //         count = this[76];
    //         ++i;
    //         p += 316;
    //       } while (i < count);
    //     }
    //     return count;
    //   }
    // UNRESOLVED: The helper 0x004FB5D0 is undocumented (FAILNODOCENTRY); its effect per entry is unknown.
    // UNRESOLVED: The element type of the this[0x134] array and the meaning of the 316-byte stride are caller-defined.
    // UNRESOLVED: The owning type of this object and the semantic role of the count field this[0x130] are not established.
}
