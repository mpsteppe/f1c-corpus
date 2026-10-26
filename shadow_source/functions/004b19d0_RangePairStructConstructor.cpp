// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B19D0
// Canonical corpus name: sub_4B19D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B19D0_004b19d0.c

void UnknownObject::RangePairStructConstructor()
{
    // Constructor for a small 5-dword object called from UIControlWindowInitialization. Sets the vtable/interface pointer at +0x00 from off_5ACC2C and initializes two range-bound pairs: first pair minimum 0 at +0x4 and maximum -1 at +0x8, second pair minimum 0 at +0xC and maximum -1 at +0x10. Returns the this pointer.
    // ASSIGNMENT: Store the vtable/interface pointer off_5ACC2C at this + 0x00. [source:raw, field:this:0x00000000, global:0x005ACC2C]
    // ASSIGNMENT: Initialize this + 0x4 to 0 (first range pair minimum bound). [source:raw, field:this:0x00000004]
    // ASSIGNMENT: Initialize this + 0x8 to -1 (first range pair maximum bound, unlimited). [source:raw, field:this:0x00000008]
    // ASSIGNMENT: Initialize this + 0xC to 0 (second range pair minimum bound). [source:raw, field:this:0x0000000C]
    // ASSIGNMENT: Initialize this + 0x10 to -1 (second range pair maximum bound, unlimited). [source:raw, field:this:0x00000010]
    // RETURN: Return the constructed this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   int* sub_4B19D0(int* this) {
    //     this[0] = off_5ACC2C;
    //     this[1] = 0;
    //     this[2] = -1;
    //     this[3] = 0;
    //     this[4] = -1;
    //     return this;
    //   }
    // UNRESOLVED: Object identity and the meaning of the two (min=0, max=-1) range-bound pairs.
    // UNRESOLVED: Interface type referenced by the vtable pointer off_5ACC2C.
}
