// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00559330
// Canonical corpus name: SmallStructInitWithParentCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SmallStructInitWithParentCall_00559330.c

void UnknownObject::SmallStructInitWithParentCall()
{
    // Small-struct initializer. Calls GlobalZeroInit_c2a0 to zero the struct, then explicitly zeroes the first byte at offset 0 and three dwords at offsets 0x14, 0x18 and 0x1C before returning this. Called by three near-neighbor functions (sub_5594B0, sub_559570, LinkedListNodeSearchAllocation), suggesting a node-type object.
    // CALL: Call GlobalZeroInit_c2a0(this) to zero-fill the entire struct. [callee:0x0053C2A0, source:raw]
    // ASSIGNMENT: Write zero to the first byte at this+0x0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write zero to the dword at this+0x14 (dword slot 5) after the global zero-init. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Write zero to the dword at this+0x18 (dword slot 6) after the global zero-init. [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Write zero to the dword at this+0x1C (dword slot 7) after the global zero-init. [field:this:0x0000001C, source:raw]
    // RETURN: Return this pointer. [function:0x00559330, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *__thiscall SmallStructInitWithParentCall(_DWORD *this)
    //   {
    //     GlobalZeroInit_c2a0(this);
    //     *(_BYTE *)this = 0;
    //     this[5] = 0;
    //     this[6] = 0;
    //     this[7] = 0;
    //     return this;
    //   }
    // UNRESOLVED: Object type is unknown; caller addresses are all adjacent and the name LinkedListNodeSearchAllocation hints at a linked-list node, unconfirmed.
    // UNRESOLVED: Semantic role of the explicitly zeroed fields beyond GlobalZeroInit is not established.
}
