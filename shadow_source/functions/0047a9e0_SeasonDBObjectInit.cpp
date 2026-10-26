// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047A9E0
// Canonical corpus name: sub_47A9E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_47A9E0_0047a9e0.c

void UnknownObject::SeasonDBObjectInit()
{
    // Season database object initializer: calls the chained base constructor ShortComputation_5e30(this), installs the vtable off_5A66E0 at this+0x0, fills eleven DWORD fields (+0xE4..+0x100 and +0x110..+0x118) with the -1 sentinel value, and zeroes four fields (+0xE0, +0x104, +0x108, +0x10C). Returns the this pointer.
    // CALL: ShortComputation_5e30(this) chains the base-class constructor before any field is set here [callee:0x00485E30, source:raw]
    // ASSIGNMENT: Set DWORD fields +0xE4, +0xE8, +0xEC, +0xF0, +0xF4, +0xF8, +0xFC and +0x100 (this[57..64]) to -1 sentinel values [field:this:0x000000E4, field:this:0x000000E8, field:this:0x000000EC, field:this:0x000000F0, field:this:0x000000F4, field:this:0x000000F8, field:this:0x000000FC, field:this:0x00000100, source:raw]
    // ASSIGNMENT: Set DWORD fields +0x110, +0x114 and +0x118 (this[68..70]) to -1 sentinel values [field:this:0x00000110, field:this:0x00000114, field:this:0x00000118, source:raw]
    // ASSIGNMENT: Install the vtable by storing &off_5A66E0 into the vtable pointer at this+0x0 [field:this:0x00000000, global:0x005A66E0, source:raw]
    // ASSIGNMENT: Zero DWORD fields +0xE0, +0x104, +0x108 and +0x10C (this[56], this[65..67]) [field:this:0x000000E0, field:this:0x00000104, field:this:0x00000108, field:this:0x0000010C, source:raw]
    // RETURN: Return the this pointer; the caller SeasonDatabaseObjectFactory (0047f440) receives the fully initialized object [function:0x0047A9E0, caller:0x0047F440, source:raw]

    // Conservative worker pseudocode:
    //   ShortComputation_5e30(this);
    //   this[57] = this[58] = this[59] = this[60] = this[61] = this[62] = this[63] = this[64] = -1;
    //   this[68] = this[69] = this[70] = -1;
    //   this[0] = &off_5A66E0;
    //   this[56] = this[65] = this[66] = this[67] = 0;
    //   return this;
    // UNRESOLVED: The semantics of the -1 sentinel fields and the zeroed fields are not documented in this function; the caller's use in SeasonDatabaseObjectFactory (0047f440) is not visible from this packet
    // UNRESOLVED: No guards are recorded for this function; the -1 assignments are unconditional
}
