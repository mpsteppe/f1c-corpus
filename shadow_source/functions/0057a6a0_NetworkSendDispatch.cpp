// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057A6A0
// Canonical corpus name: NetworkSendDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkSendDispatch_0057a6a0.c

void UnknownObject::NetworkSendDispatch()
{
    // Dispatches a network data send. Obtains a sender object through the vtable method at offset 0x58 on the object pointer stored at *this; if it is null, returns 10 (blocked). If a payload (a4) is present it is forwarded through a sub-object vtable call, otherwise a flag byte in that sub-object is set to 1. Then unconditionally calls sub_586800 with fixed first arguments and a5/a6/a7 as data, and SingleFunctionCallWrapper_6a00 with a2/a3. Finally routes through VTableDispatchWithConditionalCall or sub_585270 depending on a8, and returns 0.
    // CALL: Retrieve sender object v8 by invoking the vtable method at offset 0x58 through the object pointer stored at *this (COM-style handle). [field:this:0x00000000, field:obj:0x00000000, field:*(obj+0x0):0x00000058]
    // GUARD: If sender object v8 is null, return 10 to signal the send is blocked. [field:*(obj+0x0):0x00000058]
    // GUARD: If payload a4 is non-zero, call the vtable method at offset 0x20 on the sub-object at v8+72 passing a4 as the data; otherwise set the byte at offset 4 of that sub-object to 1. [field:*(obj+0x0):0x00000058]
    // CALL: Call sub_586800 with fixed leading arguments 1 and 0 plus a5, a6, a7 carrying the send data. [callee:0x00586800]
    // CALL: Call SingleFunctionCallWrapper_6a00 with a2 and a3. [callee:0x00586A00]
    // GUARD: If a8 is non-zero dispatch via VTableDispatchWithConditionalCall(v8); otherwise route through sub_585270(v8). [callee:0x00585380, callee:0x00585270]
    // RETURN: Return 0 on the successful dispatch path. [callee:0x00586800]

    // Conservative worker pseudocode:
    //   v8 = (*this)->vtbl[0x58]();
    //   if (!v8) return 10;
    //   if (a4) v8->sub_at_72->vtbl[0x20](a4); else v8->sub_at_72->flag_at_4 = 1;
    //   sub_586800(1, 0, a5, a6, a7);
    //   SingleFunctionCallWrapper_6a00(a2, a3);
    //   if (a8) VTableDispatchWithConditionalCall(v8); else sub_585270(v8);
    //   return 0;
    // UNRESOLVED: Role of the sub-object at v8+72 and its vtable method at offset 0x20 is unknown.
    // UNRESOLVED: Meaning of the block return value 10 and the meaning of the a8 dispatch split (VTableDispatchWithConditionalCall vs sub_585270) is unknown.
}
