// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00499AB0
// Canonical corpus name: StructInitPathRegistry
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructInitPathRegistry_00499ab0.c

void UnknownObject::StructInitPathRegistry()
{
    // Three-field object initializer. Zeroes the field at this+0x0, sets the sentinel field at this+0x4 to -1 (0xFFFFFFFF), copies a path/name string from parameter a2 via StringCopyWithBufferRealloc, then stores parameter a3 into the field at this+0x8. Returns this. Likely constructs a path/texture registry entry; invoked by BitmapLoader.
    // ASSIGNMENT: Zero the first dword field at this+0x0 [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Set the sentinel dword field at this+0x4 to -1 (0xFFFFFFFF) [field:this:0x00000004, source:raw]
    // CALL: Copy the string from parameter a2 with buffer reallocation via StringCopyWithBufferRealloc [callee:0x00566650, source:raw]
    // ASSIGNMENT: Store parameter a3 into the dword field at this+0x8 [field:this:0x00000008, source:raw]
    // RETURN: Return the initialized this pointer [function:0x00499AB0, source:raw]
    // CALL: Invoked by BitmapLoader to build a registry entry from a path string and identifier [caller:0x004979F0, source:raw]

    // Conservative worker pseudocode:
    //   DWORD* init(DWORD* this, const char* a2, DWORD a3) {
    //     this[0] = 0;
    //     this[1] = -1;
    //     StringCopyWithBufferRealloc(a2);
    //     this[2] = a3;
    //     return this;
    //   }
    // UNRESOLVED: The semantic meaning of the three fields (0x0 pointer/index, 0x4 sentinel -1, 0x8 stored identifier) is inferred from the initializer only and not independently confirmed.
    // UNRESOLVED: The destination of the string copy performed by StringCopyWithBufferRealloc (which buffer receives a2) is not visible in this function.
    // UNRESOLVED: Owner object identity is unknown.
}
