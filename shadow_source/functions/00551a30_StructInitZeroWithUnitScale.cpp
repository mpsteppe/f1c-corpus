// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00551A30
// Canonical corpus name: StructInitWithDefaultScale
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructInitWithDefaultScale_00551a30.c

void UnknownObject::StructInitZeroWithUnitScale()
{
    // Struct initialization with a unit scale default. First calls GlobalZeroInit_c2a0 (0053C2A0) to zero the whole struct, then explicitly zeros the leading two DWORD fields (this+0x0, this+0x4) and writes 1.0f to this+0x10, giving the struct a default scale of one. Returns the object pointer. Called by sub_546450 and ObjectCreationWithRollbackOnFailure.
    // CALL: GlobalZeroInit_c2a0 (0053C2A0) called first to zero-initialize the entire struct memory [callee:0x0053C2A0, source:raw]
    // ASSIGNMENT: Zeros this+0x0 (DWORD index 0) explicitly after the global zeroing [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Zeros this+0x4 (DWORD index 1) explicitly after the global zeroing [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Writes 1065353216 (1.0f as IEEE-754 single) to this+0x10, establishing a default scale factor of 1.0 [field:this:0x00000010, source:raw]
    // RETURN: Returns this (the object pointer) to the caller [source:raw]
    // CALL: Invoked by sub_546450 and ObjectCreationWithRollbackOnFailure during object construction [caller:0x00546450, caller:0x00551F10, source:raw]

    // Conservative worker pseudocode:
    //   GlobalZeroInit_c2a0(this);
    //   this[0] = 0;
    //   this[1] = 0;
    //   this[4] = 1065353216;
    //   return this;
    // UNRESOLVED: The purpose of the scale field (this+0x10) defaulting to 1.0f is not established from this packet alone
    // UNRESOLVED: Owner class and the scope of GlobalZeroInit_c2a0's zeroing are unknown from this packet
}
