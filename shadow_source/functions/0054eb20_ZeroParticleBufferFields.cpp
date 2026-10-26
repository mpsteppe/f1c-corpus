// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054EB20
// Canonical corpus name: sub_54EB20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_54EB20_0054eb20.c

void UnknownObject::ZeroParticleBufferFields()
{
    // Constructor/initializer-style method: zeroes the first five dwords of the object (offsets 0x0, 0x4, 0x8, 0xC, 0x10) and returns the this pointer.
    // ASSIGNMENT: Set dword at this+0x0 to 0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Set dword at this+0x4 to 0. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Set dword at this+0x8 to 0. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Set dword at this+0xC to 0. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Set dword at this+0x10 to 0. [field:this:0x00000010, source:raw]
    // RETURN: Return the this pointer. [function:0x0054EB20, source:raw]

    // Conservative worker pseudocode:
    //   this[0] = 0;
    //   this[1] = 0;
    //   this[2] = 0;
    //   this[3] = 0;
    //   this[4] = 0;
    //   return this;
    // UNRESOLVED: Purpose of the five zeroed fields is unknown; called from VertexParticleBufferAllocator, suggesting an allocation-time reset, but the owning object type and field roles are not grounded in the packet.
}
