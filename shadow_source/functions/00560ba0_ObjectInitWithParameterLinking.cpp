// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00560BA0
// Canonical corpus name: ObjectInitWithParameterLinking
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectInitWithParameterLinking_00560ba0.c

void UnknownObject::ObjectInitWithParameterLinking()
{
    // Object initializer (thiscall) that zero-initializes the receiver via GlobalZeroInit_c2a0, stamps a float default of 0.2f into word 0, clears the remaining scalar words, stores a2 at +0x18 and a3 at +0x28, sets the state word +0x24 to 2, and links the object into a2's child list by writing the receiver pointer through a2+312 to the child slot at offset 560. Invoked by LinkedListNodeInsert_5930 (00545930).
    // CALL: Zero-initializes the whole receiver object memory through GlobalZeroInit_c2a0 before any field is written [callee:0x0053C2A0, source:raw]
    // ASSIGNMENT: Writes literal 1045220557 (float 0.2f) into word this+0x0 as the object's float default [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Clears scalar words at this+0x4, this+0x8, this+0xC, this+0x10, this+0x14, this+0x1C, this+0x20, this+0x2C, this+0x30 and this+0x34 to 0 [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x0000001C, field:this:0x00000020, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, source:raw]
    // ASSIGNMENT: Stores parameter a2 (the parent object pointer) into word this+0x18 [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Links this into the parent child list: dereferences a2+312 to a child-array pointer and writes this into the child slot at offset 560 [field:this:0x00000018, source:raw]
    // STATE_TRANSITION: Sets word this+0x24 to literal 2 (state/flag value; semantics not established by this packet) [field:this:0x00000024, source:raw]
    // ASSIGNMENT: Stores parameter a3 into word this+0x28 as a stored configuration value [field:this:0x00000028, source:raw]
    // RETURN: Returns the initialized receiver pointer (this) [source:raw]
    // CALL: Called by LinkedListNodeInsert_5930 (00545930) as the object setup stage [caller:0x00545930, source:raw]

    // Conservative worker pseudocode:
    //   GlobalZeroInit_c2a0(this);
    //   this[0x0/4] = 1045220557;   // float 0.2f
    //   this[0x18/4] = a2;
    //   *(*(a2 + 312) + 560) = this;
    //   this[0x24/4] = 2;
    //   this[0x28/4] = a3;
    //   this[0x4/4] = this[0x8/4] = this[0xC/4] = this[0x10/4] = 0;
    //   this[0x14/4] = this[0x1C/4] = this[0x20/4] = 0;
    //   this[0x2C/4] = this[0x30/4] = this[0x34/4] = 0;
    //   return this;
    // UNRESOLVED: Purpose of the float default 0.2f at +0x0 and the state literal 2 at +0x24 is not established by this packet
    // UNRESOLVED: The child list layout behind a2+312 -> +560 is only reached as a raw dereference; element semantics unknown
    // UNRESOLVED: Semantics of a3 stored at +0x28 are not established
}
