// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B1A10
// Canonical corpus name: FunctionCallWrapper_1a10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FunctionCallWrapper_1a10_004b1a10.c

void UnknownObject::RangePairStructConstructor()
{
    // Constructor for a small 5-dword object. Stores the vtable/interface pointer at +0x00 from global off_5ACC44, then initializes two min/max range pairs: pair 1 (+0x04 min = 0, +0x08 max = -1) and pair 2 (+0x0C min = 0, +0x10 max = -1). Returns the this pointer. Called by UIControlWindowInitialization (0x004A70E0).
    // ASSIGNMENT: Store the vtable/interface pointer from global off_5ACC44 into field +0x00. [field:this:0x00000000, global:0x005ACC44]
    // ASSIGNMENT: Set +0x04 (range pair 1 minimum bound) to 0. [field:this:0x00000004]
    // ASSIGNMENT: Set +0x08 (range pair 1 maximum bound) to -1. [field:this:0x00000008]
    // ASSIGNMENT: Set +0x0C (range pair 2 minimum bound) to 0. [field:this:0x0000000C]
    // ASSIGNMENT: Set +0x10 (range pair 2 maximum bound) to -1. [field:this:0x00000010]
    // RETURN: Return the this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   void *sub_4B1A10(void *this) {
    //     this[0] = off_5ACC44;
    //     this[1] = 0;
    //     this[2] = -1;
    //     this[3] = 0;
    //     this[4] = -1;
    //     return this;
    //   }
    // UNRESOLVED: Object type and vtable identity behind off_5ACC44 are not resolved.
    // UNRESOLVED: Purpose of the two range pairs is not established.
    // UNRESOLVED: Caller UIControlWindowInitialization (0x004A70E0) is known statically; no frame-path evidence confirms runtime reachability.
}
