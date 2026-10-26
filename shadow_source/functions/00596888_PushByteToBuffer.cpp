// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00596888
// Canonical corpus name: sub_596888
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_596888_00596888.c

void UnknownObject::PushByteToBuffer()
{
    // Byte-push writer over an allocator-managed buffer descriptor a2 (current position, element count, allocation end, flag word). Rejects the sentinel input a1 == -1 and flag-state mismatches, lazily initializes the descriptor via MemoryAllocatorInit when no allocation exists, then either writes byte a1 at a decremented position or verifies it matches in match mode (flag 0x40). Returns the byte on success, -1 on failure.
    // GUARD: Reject the sentinel input: return -1 immediately when a1 == -1. [source:raw]
    // GUARD: Read the flag word a2[3]; return -1 when bit 0x1 is clear and (bit 0x80 is clear or bit 0x2 is set), i.e. the descriptor is not in a writable state. [source:raw]
    // CALL: Lazily initialize the descriptor: when the allocation pointer a2[2] is null, call MemoryAllocatorInit(a2). [callee:0x005957BD, source:raw]
    // GUARD: When the current position *a2 equals the allocation end a2[2]: reject if the element count a2[1] is nonzero, otherwise advance the current position. [source:raw]
    // STATE_TRANSITION: Match mode (flag 0x40 set): decrement the current position and compare the stored byte against a1; on mismatch restore the position and return -1. [source:raw]
    // ASSIGNMENT: Write mode (flag 0x40 clear): decrement the current position and store byte a1 there. [source:raw]
    // CALCULATION: Bump the element count a2[1] and update the flag word: a2[3] = (a2[3] & 0xEE) | 1. [source:raw]
    // RETURN: Return the written/verified byte as an unsigned char of a1. [source:raw]

    // Conservative worker pseudocode:
    //   int PushByteToBuffer(int value, unsigned *desc) {
    //     if (value == -1) return -1;
    //     if (!(desc[3] & 1) && ((desc[3] & 0x80) == 0 || (desc[3] & 2))) return -1;
    //     if (!desc[2]) MemoryAllocatorInit(desc);
    //     if (desc[0] == desc[2]) { if (desc[1]) return -1; ++desc[0]; }
    //     if (desc[3] & 0x40) { if (*(unsigned char*)--desc[0] != (unsigned char)value) { ++desc[0]; return -1; } }
    //     else *(unsigned char*)--desc[0] = (unsigned char)value;
    //     ++desc[1];
    //     desc[3] = (desc[3] & 0xEE) | 1;
    //     return (unsigned char)value;
    //   }
    // UNRESOLVED: The concrete class of descriptor a2 is unproven; MemoryAllocatorInit on it only proves it is allocator-managed.
    // UNRESOLVED: The semantics of the flag bits (0x1, 0x2, 0x40, 0x80) beyond the observed transitions are unproven.
    // UNRESOLVED: Whether a2[1] counts bytes or elements is undetermined.
}
