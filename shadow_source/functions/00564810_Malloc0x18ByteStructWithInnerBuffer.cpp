// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564810
// Canonical corpus name: Malloc0x18ByteStructWithInnerBuffer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Malloc0x18ByteStructWithInnerBuffer_00564810.c

void UnknownObject::Malloc0x18ByteStructWithInnerBuffer()
{
    // Allocates and returns a 24-byte (0x18) descriptor whose five dwords describe an inner buffer, and allocates that inner buffer. Calls MallocWrapperForNhMalloc(24) for the descriptor, defaults element size a2 to 8 when it is zero, stores element count a1 at dword index 2 (byte offset 0x8), zeroes dword index 0, stores a2 at dword indices 1 and 3 (byte offsets 0x4 and 0xC), stores a3 at dword index 4 (byte offset 0x10), then allocates the a2 * a1 byte inner buffer and stores it at dword index 5 (byte offset 0x14). Returns the descriptor pointer.
    // CALL: MallocWrapperForNhMalloc(24) allocates the 24-byte descriptor; its base is captured in v5/v6. [callee:0x0058A935, source:raw]
    // GUARD: If element size a2 is zero, default it to 8 before it is used to size the inner buffer. [source:raw]
    // ASSIGNMENT: Store the element count a1 at descriptor dword index 2 (byte offset 0x8). [source:raw]
    // ASSIGNMENT: Zero the descriptor's first dword (byte offset 0x0). [source:raw]
    // ASSIGNMENT: Store the element size a2 at dword indices 1 and 3 (byte offsets 0x4 and 0xC). [source:raw]
    // ASSIGNMENT: Store a3 at dword index 4 (byte offset 0x10). [source:raw]
    // CALL: MallocWrapperForNhMalloc(a2 * a1) allocates the inner buffer (a2 bytes per a1 element) and stores it at dword index 5 (byte offset 0x14). [callee:0x0058A935, source:raw]
    // RETURN: Return the fully initialized descriptor pointer v6. [function:0x00564810, source:raw]
    // CALL: Invoked by MemoryObjectAllocator (00562B50), DirectDrawDisplayModeInit (00563E00) and AllocateIntArrayViaFactory (005646D0) to build this descriptor. [caller:0x00562B50, caller:0x00563E00, caller:0x005646D0]

    // Conservative worker pseudocode:
    //   v5 = MallocWrapperForNhMalloc(24);
    //   v6 = v5;
    //   if (a2 == 0) a2 = 8;
    //   v5[2] = a1;
    //   v5[0] = 0;
    //   v5[1] = a2;
    //   v5[3] = a2;
    //   v5[4] = a3;
    //   v5[5] = MallocWrapperForNhMalloc(a2 * a1);
    //   return v6;
    // UNRESOLVED: The semantic roles of the five descriptor dwords (which index is count, capacity, kind, etc.) are only structurally inferred; the packet does not name the fields.
    // UNRESOLVED: The meaning of the a2-to-8 default when a2 is zero is not explained by the packet.
    // UNRESOLVED: Owner object identity is not established by the packet.
}
