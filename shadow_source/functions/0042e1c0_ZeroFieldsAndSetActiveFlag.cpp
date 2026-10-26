// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042E1C0
// Canonical corpus name: StructInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructInitializer_0042e1c0.c

void UnknownObject::ZeroFieldsAndSetActiveFlag()
{
    // Constructor/reset step: zeroes the first seven dword fields (offsets 0x0..0x18) of the object, sets the byte flag at offset 0x1C to 1, clears the bytes at offsets 0x1D and 0x1E, and returns this. Called by session, dynamics and loop initializers.
    // ASSIGNMENT: Zero the seven leading dword fields at offsets 0x0 through 0x18. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018]
    // ASSIGNMENT: Set the byte at offset 0x1C to 1 (enabled/initialized flag). [field:this:0x0000001C]
    // ASSIGNMENT: Set the byte at offset 0x1D to 0. [field:this:0x0000001D]
    // ASSIGNMENT: Set the byte at offset 0x1E to 0. [field:this:0x0000001E]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *reset(_DWORD *this) {
    //       this[0] = 0; this[1] = 0; this[2] = 0;
    //       this[3] = 0; this[4] = 0; this[5] = 0; this[6] = 0;
    //       *((BYTE *)this + 28) = 1;   // enabled/initialized flag
    //       *((BYTE *)this + 29) = 0;
    //       *((BYTE *)this + 30) = 0;
    //       return this;
    //   }
    // UNRESOLVED: Which concrete object this initializes, given session, dynamics and loop-init callers.
    // UNRESOLVED: Meaning of the enabled flag at offset 0x1C and of the cleared bytes at offsets 0x1D/0x1E.
}
