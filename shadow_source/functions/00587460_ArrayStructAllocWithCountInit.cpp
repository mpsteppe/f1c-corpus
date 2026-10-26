// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587460
// Canonical corpus name: sub_587460
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_587460_00587460.c

void UnknownObject::ArrayStructAllocWithCountInit()
{
    // Allocate-and-init helper for a small buffer descriptor (likely { buffer pointer, element count, capacity }). Zeroes the three leading dwords at offsets 0x0, 0x4 and 0x8, then, when the requested count a2 is positive, allocates a2 elements through OperatorNewWithResultCheck into this and finally records the count a2 at offset 0x4 before returning the receiver.
    // ASSIGNMENT: Zero the three leading dwords at offsets 0x0, 0x4 and 0x8 of the receiver. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // GUARD: Allocation only runs when the requested count a2 is greater than 0; a zero count skips the allocation. [source:raw]
    // CALL: OperatorNewWithResultCheck(a2, this) allocates a2 elements and stores the resulting buffer pointer into the receiver. [callee:0x005874D0, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Record the requested element count a2 into the receiver at offset 0x4. [field:this:0x00000004, source:raw]
    // RETURN: Return the receiver pointer; used from sub_57BA10, SEHProtectedDirectXRenderStateSetup and ObjectInitWithVTableSetup init paths. [caller:0x0057BA10, caller:0x00586700, caller:0x00587030, source:raw]

    // Conservative worker pseudocode:
    //   // __thiscall: receiver is a small buffer descriptor { ptr, count, capacity }
    //   this[0] = 0;
    //   this[1] = 0;
    //   this[2] = 0;
    //   if (a2 > 0)
    //       OperatorNewWithResultCheck(a2, this);  // buffer ptr written into this[0]
    //   this[1] = a2;  // record the requested count
    //   return this;
    // UNRESOLVED: The descriptor's third dword at offset 0x8 is zeroed but never otherwise touched; its role (capacity or reserved field) is unknown.
    // UNRESOLVED: Whether a2 is an element count or a byte size, and the element size assumed by the allocator, are external to this function.
    // UNRESOLVED: OperatorNewWithResultCheck allocation and fill semantics are not visible here.
}
