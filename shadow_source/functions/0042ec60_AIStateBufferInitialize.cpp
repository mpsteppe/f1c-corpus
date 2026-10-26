// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042EC60
// Canonical corpus name: AIStateBufferInitialize
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AIStateBufferInitialize_0042ec60.c

void UnknownObject::AIStateBufferInitialize()
{
    // Initializes the AI state buffer: left-shifts two history buffers by one entry so the oldest sample is discarded (first buffer: 4 groups of 11 entries at a 64-byte stride starting at byte offset 0xC4, each entry copied from its successor at +4; second buffer: 55 entries at a 64-byte stride starting at byte offset 0xBC4), sets the four float fields at 0x1CA8-0x1CB4 to 1056964608 (0.5f), and sets the activation/ready byte at this+0x0 to 1. Called by CleanupWrapper (0x00433EB0). Returns the literal 1056964608.
    // LOOP: Left-shift the first history buffer: iterate 4 times over 11 entries at a 64-byte stride beginning at byte offset 0xC4, copying each entry from its successor (source at 0xC8 and onward) so the oldest entry is overwritten. [field:this:0x000000C4, field:this:0x000000C8, source:raw]
    // LOOP: Left-shift the second history buffer: iterate 55 times at a 64-byte stride beginning at byte offset 0xBC4, copying each entry from its successor (source at 0xBC8 and onward). [field:this:0x00000BC4, field:this:0x00000BC8, source:raw]
    // ASSIGNMENT: Set the four float fields at byte offsets 0x1CA8, 0x1CAC, 0x1CB0 and 0x1CB4 to the literal 1056964608 (0.5f). [field:this:0x00001CA8, field:this:0x00001CAC, field:this:0x00001CB0, field:this:0x00001CB4, source:raw]
    // ASSIGNMENT: Set the activation/ready flag byte at this+0x0 to 1. [field:this:0x00000000, source:raw]
    // RETURN: Return the literal 1056964608. [function:0x0042EC60, source:raw]

    // Conservative worker pseudocode:
    //   // Left-shift each 64-byte history entry onto its predecessor, discarding the oldest.
    //   // First buffer: 4 groups x 11 entries, starting at byte offset 0xC4.
    //   // Second buffer: 55 entries, starting at byte offset 0xBC4.
    //   for (entry in buffers) { *(entry) = *(entry + 4); }
    //   this[1834] = 1056964608;  // 0.5f at 0x1CA8
    //   this[1835] = 1056964608;  // 0x1CAC
    //   this[1836] = 1056964608;  // 0x1CB0
    //   this[1837] = 1056964608;  // 0x1CB4
    //   *(BYTE*)this = 1;         // activation flag
    //   return 1056964608;
    // UNRESOLVED: The semantic meaning of the four float fields at 0x1CA8-0x1CB4 (weights/confidence per existing analysis) is not evidenced by this packet.
    // UNRESOLVED: The element type of the history buffers (64-byte stride, first element copied from its successor) is not established by the packet.
}
