// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A8B50
// Canonical corpus name: sub_4A8B50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A8B50_004a8b50.c

void UnknownObject::ObjectConstructor_4A8B50()
{
    // Straight-line constructor for a seven-DWORD object. Installs the vtable pointer off_5ACC14 at this+0x0 and initializes the fields at +0x4 (0), +0x8 (-1 sentinel), +0xC (0), +0x10 (89), +0x14 (0), +0x18 (89). Returns the this pointer. No branches, no calls.
    // ASSIGNMENT: Initialize this+0x4 (this[1]) to 0. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Initialize this+0x8 (this[2]) to -1, an empty/invalid sentinel value. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Initialize this+0xC (this[3]) to 0. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Initialize this+0x10 (this[4]) to 89. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Initialize this+0x14 (this[5]) to 0. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Initialize this+0x18 (this[6]) to 89. [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Install the vtable pointer: *this (this+0x0) = &off_5ACC14. [field:this:0x00000000, global:0x005ACC14, source:raw]
    // RETURN: Return the this pointer as the constructed object. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* ObjectConstructor_4A8B50(_DWORD* this) {
    //     this[1] = 0;
    //     this[2] = -1;
    //     this[3] = 0;
    //     this[4] = 89;
    //     this[5] = 0;
    //     this[6] = 89;
    //     this[0] = &off_5ACC14;
    //     return this;
    //   }
    // UNRESOLVED: Owning class is unnamed; constructor identity is inferred from the vtable install plus field initialization pattern.
    // UNRESOLVED: Meaning of the 89 values at +0x10 and +0x18 (possibly capacities or indices) is unknown.
    // UNRESOLVED: Meaning of the -1 sentinel at +0x8 (possibly an empty-slot marker) is GUESS.
    // UNRESOLVED: off_5ACC14 vtable target object is not described by packet evidence.
}
