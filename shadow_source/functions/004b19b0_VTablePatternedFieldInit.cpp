// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B19B0
// Canonical corpus name: VTablePatternedFieldInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VTablePatternedFieldInit_004b19b0.c

void UnknownObject::VTablePatternedFieldInit()
{
    // Thiscall constructor for a 5-dword object: stores the vtable pointer from off_5ACC20 at +0x0, then initializes two range-bound pairs (this[1]=0/this[2]=-1 and this[3]=0/this[4]=-1). Unconditional, no branches, no callees. Called from UIControlWindowInitialization.
    // ASSIGNMENT: Store vtable/interface pointer from off_5ACC20 into *this (+0x0) [global:0x005ACC20, field:this:0x00000000, abi:lead, source:raw]
    // ASSIGNMENT: Initialize this[1] (+0x4) to 0 (first range pair minimum bound) [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Initialize this[2] (+0x8) to -1 (first range pair maximum bound / unlimited sentinel) [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Initialize this[3] (+0xC) to 0 (second range pair minimum bound) [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Initialize this[4] (+0x10) to -1 (second range pair maximum bound / unlimited sentinel) [field:this:0x00000010, source:raw]
    // RETURN: Return this (result = this) [function:0x004B19B0, source:raw]

    // Conservative worker pseudocode:
    //   this[1] = 0;
    //   this[2] = -1;
    //   this[3] = 0;
    //   this[4] = -1;
    //   *this = off_5ACC20;
    //   return this;
    // UNRESOLVED: Semantics of the 0/-1 field-pair pattern at +0x4..+0x10 not established from packet evidence
    // UNRESOLVED: Object type behind the vtable at off_5ACC20 not identified
}
