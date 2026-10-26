// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040B360
// Canonical corpus name: VirtualDispatchChain
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VirtualDispatchChain_0040b360.c

void UnknownObject::VirtualDispatchChain()
{
    // Chained virtual dispatch: invokes the vtable slot at offset +24 on this; if the returned object is non-null, invokes the vtable slot at offset +28 on that object and returns its result, otherwise returns the first result.
    // CALL: Indirect thiscall through the vtable pointer read at this+0x0, dispatching the slot at vtable offset +24 (0x18) on this [field:this:0x00000000, field:obj:0x00000018, source:raw]
    // GUARD: If the first dispatch returned a non-zero object, perform a second dispatch chain on it [function:0x0040B360, source:raw]
    // CALL: Indirect thiscall through the vtable of the first result object (dispatch receiver field), dispatching the slot at vtable offset +28 on that object [field:obj:0x00000018, source:raw]
    // RETURN: Return the chained dispatch result when the guard passes, otherwise return the first dispatch result [function:0x0040B360, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   result = this->vtable[+24](this);
    //   if (result != 0)
    //     return result->vtable[+28](result);
    //   return result;
    // UNRESOLVED: The dispatched slots are reached by raw vtable offsets (+24, +28) and no concrete callee targets are listed, so the invoked methods are unknown
}
