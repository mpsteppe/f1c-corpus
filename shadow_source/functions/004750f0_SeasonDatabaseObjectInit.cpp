// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004750F0
// Canonical corpus name: sub_4750F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4750F0_004750f0.c

void UnknownObject::SeasonDatabaseObjectInit()
{
    // Initializes a season database object: calls the generic setup routine sub_4893C0, zeroes two DWORD fields at +0x174 and +0x178 and a BYTE field at +0x17C, installs the vtable pointer off_5A4370 at +0x0, and returns the object. No guards; the function always executes fully.
    // CALL: Call sub_4893C0 for the generic initialization/setup of the season database object. [callee:0x004893C0, source:raw]
    // ASSIGNMENT: Zero the DWORD field at this + 0x174 (index 93). [field:this:0x00000174, source:raw]
    // ASSIGNMENT: Zero the DWORD field at this + 0x178 (index 94). [field:this:0x00000178, source:raw]
    // ASSIGNMENT: Zero the single BYTE field at this + 0x17C (byte offset 380). [field:this:0x0000017C, source:raw]
    // ASSIGNMENT: Install the vtable pointer off_5A4370 into this + 0x0, identifying the object type. [field:this:0x00000000, global:0x005A4370, source:raw]
    // RETURN: Return the initialized object pointer. [function:0x004750F0, source:raw]

    // Conservative worker pseudocode:
    //   sub_4893C0();
    //   this[93] = 0;
    //   this[94] = 0;
    //   *(byte*)(this + 380) = 0;
    //   *this = &off_5A4370;
    //   return this;
    // UNRESOLVED: The meaning of the zeroed fields at +0x174, +0x178 and +0x17C (counters, indexes, flags) is not derivable from this packet.
    // UNRESOLVED: The exact role of sub_4893C0 (base-class init, allocator) is not established by the packet.
    // UNRESOLVED: The caller SeasonDatabaseObjectFactory is known but the call context is not present in the packet.
}
