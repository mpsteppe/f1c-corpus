// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004760D0
// Canonical corpus name: sub_4760D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4760D0_004760d0.c

void UnknownObject::UIDatabaseObjectInit()
{
    // Constructor for a UI database object. Calls the base UI object constructor UIObjectConstructor_fc50 (0048FC50), zeroes six fields at this+0x3C through this+0x50, sets this+0x54 to the sentinel value -1 (18446744073709551615 as unsigned dword), assigns the vtable off_5A4464 to this+0x0, and returns this.
    // CALL: Invokes the base UI object constructor UIObjectConstructor_fc50 before initializing this object's own state [callee:0x0048FC50, source:raw]
    // ASSIGNMENT: Zeroes the six consecutive fields this+0x3C, this+0x40, this+0x44, this+0x48, this+0x4C and this+0x50 [field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050, source:raw]
    // ASSIGNMENT: Sets this+0x54 to the sentinel value -1 (18446744073709551615 as an unsigned dword), the unset-record marker [field:this:0x00000054, source:raw]
    // ASSIGNMENT: Assigns the vtable pointer off_5A4464 to the object header this+0x0 [field:this:0x00000000, global:0x005A4464, source:raw]
    // RETURN: Returns the constructed object pointer this [source:raw]

    // Conservative worker pseudocode:
    //   UIObjectConstructor_fc50();
    //   this[15] = 0; this[16] = 0; this[17] = 0; this[18] = 0; this[19] = 0; this[20] = 0;
    //   this[21] = -1;
    //   *this = &off_5A4464;
    //   return this;
    // UNRESOLVED: The meaning of the zeroed fields this+0x3C through this+0x50 and the sentinel field this+0x54 is inferred only from constructor shape, not grounded in packet evidence
    // UNRESOLVED: The UI database object type is not identified; owner remains UnknownObject
}
