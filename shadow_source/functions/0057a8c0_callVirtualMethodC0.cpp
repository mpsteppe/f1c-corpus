// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057A8C0
// Canonical corpus name: VirtualDispatchWrapper_a8c0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VirtualDispatchWrapper_a8c0_0057a8c0.c

void UnknownObject::callVirtualMethodC0()
{
    // COM-style virtual dispatch wrapper: dereferences the interface handle *this, loads the virtual method pointer at vtable offset 0xC0 (index 48), and invokes it thiscall with the interface pointer and the argument a2. Always returns 0. Called by BufferSendWithLocks (00462760).
    // CALL: Indirect thiscall: read the interface pointer stored at *this, load the virtual method pointer from vtable offset 0xC0, and call it with the interface pointer as this and a2 as the single argument [field:this:0x00000000, field:obj:0x00000000, field:*(obj+0x0):0x000000C0, source:raw]
    // RETURN: Return constant 0 after the virtual dispatch, unconditionally [source:raw]
    // CALL: Invoked by BufferSendWithLocks (00462760) to dispatch into a virtual method on the wrapped object [caller:0x00462760]

    // Conservative worker pseudocode:
    //   obj = *this;
    //   fn = *(obj + 0xC0);
    //   fn(obj, a2);
    //   return 0;
    // UNRESOLVED: The identity of the virtual method at vtable offset 0xC0 and the meaning of argument a2 are not established from this function alone
    // UNRESOLVED: The relationship of this wrapper to the buffer-send path in caller 00462760 is not further documented here
}
