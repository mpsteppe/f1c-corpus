// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00502C12
// Canonical corpus name: TripleDwordZeroInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TripleDwordZeroInit_00502c12.c

void UnknownObject::TripleDwordZeroInit()
{
    // Unconditional __thiscall initializer: writes 0 to three consecutive dwords at this (offsets 0x0, 0x4, 0x8) and returns the this pointer. No branches, no calls, no globals.
    // ASSIGNMENT: Write 0 to this+0x0 (first dword of the triple). [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write 0 to this+0x4 (second dword of the triple). [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write 0 to this+0x8 (third dword of the triple). [field:this:0x00000008, source:raw]
    // RETURN: Return the this pointer as the result. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* TripleDwordZeroInit(_DWORD* this) {
    //     this[0] = 0;
    //     this[1] = 0;
    //     this[2] = 0;
    //     return this;
    //   }
    // UNRESOLVED: Identity of the struct owning the three zeroed dwords is unknown; object type and the meaning of each field are not established.
}
