// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057A4F0
// Canonical corpus name: VirtualFunctionDispatchWithStackFrames
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VirtualFunctionDispatchWithStackFrames_0057a4f0.c

void UnknownObject::DispatchVirtualInitAllocFinalize()
{
    // Thiscall dispatcher that drives an object's vtable lifecycle around a context structure a14. It feeds a byte flag from context offset 0x2B into SingleFieldSetter and a vtable init call at vtable+0x68, forwards the incoming stack arguments (copied from a2 onward) to AllocationWrapper, calls a vtable finalize at vtable+0xC0, clears a flag byte at object offset 0x5D, and copies string parameter a15 via StringCopyToBufferWithLengthCap. Returns the context pointer a14.
    // ASSIGNMENT: Set v15 = a14, retaining the context pointer across the subsequent vtable and allocation calls. [source:raw]
    // CALL: Call SingleFieldSetter(*(unsigned __int8*)(a14 + 43)), pushing the context flag byte (offset 0x2B) into the single-field setter. [callee:0x00585860, source:raw]
    // CALL: Call the vtable entry at offset 0x68 on *this with (this, v15 + 8, *(unsigned __int8*)(v15 + 43)), an init-style call carrying the context pointer and its flag byte; store the result in v17. [field:*(obj+0x0):0x00000068, field:this:0x00000000, source:raw]
    // CALCULATION: Copy 12 dwords of the incoming stack arguments (a2 through a13) into local array v20 with qmemcpy(v20, &a2, sizeof(v20)). [source:raw]
    // ASSIGNMENT: Set a14 = v17, re-basing the context result on the vtable init call's return value. [source:raw]
    // CALL: Forward the 12 copied stack arguments v20[0..11] to AllocationWrapper. [callee:0x00585030, source:raw]
    // CALL: Call the vtable entry at offset 0xC0 on *this with (*this, v15), a finalize-style call for the retained context. [field:*(obj+0x0):0x000000C0, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Set v20[11] = a15, staging the string parameter for the copy call. [source:raw]
    // ASSIGNMENT: Clear the byte flag at object offset 0x5D to 0: *(_BYTE*)(v18 + 93) = 0 where v18 = *this. [field:obj:0x0000005D, field:this:0x00000000, source:raw]
    // CALL: Call StringCopyToBufferWithLengthCap(v20[11]) to copy the string parameter with a length cap. [callee:0x00584FF0, source:raw]
    // RETURN: Return a14, the (re-based) context pointer. [source:raw]

    // Conservative worker pseudocode:
    //   int DispatchVirtualInitAllocFinalize(void* this, char a2, int a3, int a4, int a5,
    //       int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15) {
    //     int ctx = a14;
    //     SingleFieldSetter(*(unsigned __int8*)(ctx + 43));
    //     int r = (*(vtable+0x68))(this, ctx + 8, *(unsigned __int8*)(ctx + 43));
    //     DWORD v20[12]; memcpy(v20, &a2, sizeof(v20));
    //     ctx = r;
    //     AllocationWrapper(v20[0], ..., v20[11]);
    //     (*(vtable+0xC0))(this, a14);
    //     *(BYTE*)(*this + 93) = 0;
    //     v20[11] = a15;
    //     StringCopyToBufferWithLengthCap(v20[11]);
    //     return ctx;
    //   }
    // UNRESOLVED: Relationship between the 'obj' and 'this' field bases is not proven; the vtable init/finalize entries and the cleared 0x5D byte may refer to the same dereferenced object.
    // UNRESOLVED: Semantics of the vtable entries at +0x68 and +0xC0 (exact init/finalize responsibilities) are caller-dependent and unknown.
    // UNRESOLVED: Meaning of the flag byte at context offset 0x2B and of AllocationWrapper's allocation parameters is not evidenced within this function.
    // UNRESOLVED: Identity of the string parameter a15's source and destination buffers is unknown.
}
