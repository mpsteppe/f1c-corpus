// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B1A70
// Canonical corpus name: ShortConstructor_1a70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortConstructor_1a70_004b1a70.c

void UnknownObject::ShortConstructor()
{
    // 5-dword thiscall constructor. Stores vtable/interface pointer from off_5ACC68 into this[0], then initializes two range-bound pairs: this[1]/this[2] = 0/-1 and this[3]/this[4] = 0/-1. Called from UIControlWindowInitialization.
    // ASSIGNMENT: Store vtable/interface pointer from off_5ACC68 into this[0] (offset 0x0). [global:0x005ACC68, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Set this[1] (offset 0x4) to 0 - range pair 1 minimum bound. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Set this[2] (offset 0x8) to -1 (18446744073709551615) - range pair 1 maximum bound. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Set this[3] (offset 0xC) to 0 - range pair 2 minimum bound. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Set this[4] (offset 0x10) to -1 (18446744073709551615) - range pair 2 maximum bound. [field:this:0x00000010, source:raw]
    // RETURN: Return this (result = this). [source:raw]

    // Conservative worker pseudocode:
    //   this[0] = off_5ACC68;
    //   this[1] = 0;
    //   this[2] = -1;
    //   this[3] = 0;
    //   this[4] = -1;
    //   return this;
    // UNRESOLVED: Owner class unknown; vtable stored is off_5ACC68, whose object type is unconfirmed. Field pairs at 0x4/0x8 and 0xC/0x10 interpreted as (min, max) ranges from existing analysis (DERIVED).
}
