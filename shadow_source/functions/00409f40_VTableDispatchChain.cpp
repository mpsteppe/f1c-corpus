// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00409F40
// Canonical corpus name: VTableDispatchChain
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VTableDispatchChain_00409f40.c

void UnknownObject::VTableDispatchChain()
{
    // Chained vtable dispatch. Reads this->vtable (pointer at +0x0) and calls the slot at vtable+0x18 (index 6) with this as argument; if the returned pointer is non-null, dispatches again through the result's own vtable at slot +0x1C (index 7) and returns that result, else returns the first result. Subsystem 'ai' per the packet. Structural twin of sub_404D20 (00404d20) per the DERIVED cluster prelabel.
    // CALL: result = (*(vtable + 0x18))(this); virtual call through the vtable pointer stored at this+0x0, slot offset +0x18. [field:this:0x00000000, field:obj:0x00000018, function:0x00409F40, source:raw]
    // GUARD: If result is non-null, dispatch again on the returned object; otherwise return result. [function:0x00409F40, source:raw]
    // CALL: Second virtual dispatch on the result object: call slot at (*(DWORD *)result + 0x1C) and return its result. [function:0x00409F40, source:raw]
    // RETURN: Return the second dispatch result when available, else the first call's result. [function:0x00409F40, source:raw]

    // Conservative worker pseudocode:
    //   result = (*(this->vtable + 0x18))(this);
    //   if (result)
    //     return (*(result->vtable + 0x1C))(result);
    //   return result;
    // UNRESOLVED: Second dispatch slot offset +0x1C is read but is not present as a packet field; described from raw source only.
    // UNRESOLVED: Virtual call targets and the concrete object types (vtable at this+0x0 and at result+0x0) are unresolved; subsystem is 'ai'.
}
