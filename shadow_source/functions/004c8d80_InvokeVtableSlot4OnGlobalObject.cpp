// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C8D80
// Canonical corpus name: VirtualCallOnDAT008ac4c4_8d80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VirtualCallOnDAT008ac4c4_8d80_004c8d80.c

void UnknownObject::InvokeVtableSlot4OnGlobalObject()
{
    // Guarded indirect call: if the global object pointer dword_8AC4C4 is non-null, dereferences it as a polymorphic object, reads its vtable from the object start, calls the __thiscall slot at vtable offset +16 (index 4) with dword_8AC4C4 as 'this', and returns the call's result. When dword_8AC4C4 is null, control falls through and returns the (uninitialized) result register. Called from sub_46BF10, sub_46DC60, and sub_4A0250.
    // GUARD: Guard on dword_8AC4C4: the virtual call runs only while the global object pointer at 0x008AC4C4 is non-null. [global:0x008AC4C4, source:raw]
    // CALL: Indirect __thiscall: read the vtable pointer from *(dword_8AC4C4), take the function pointer at vtable offset +16 (slot index 4), and call it with dword_8AC4C4 as 'this'. [global:0x008AC4C4, function:0x004C8D80, source:raw]
    // RETURN: Return the virtual call's integer result when the guard passes. [source:raw]
    // RETURN: When dword_8AC4C4 is null, fall through and return the uninitialized result register. [global:0x008AC4C4, source:raw]
    // CALL: Invoked by sub_46BF10, sub_46DC60, and sub_4A0250. [caller:0x0046BF10, caller:0x0046DC60, caller:0x004A0250, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4C8D80() {
    //     if (dword_8AC4C4)
    //       return ((int (__thiscall *)(int)) *(*dword_8AC4C4 + 16))(dword_8AC4C4);
    //     return result;
    //   }
    // UNRESOLVED: The concrete type and interface behind dword_8AC4C4 and the semantics of vtable slot +16 are not evidenced.
    // UNRESOLVED: The null branch returns an uninitialized value; whether callers ignore it or treat it as an error is not established by the packet.
    // UNRESOLVED: The exact virtual-dispatch convention (offset +16 / slot 4) is inferred from the source expression '*(_DWORD *)dword_8AC4C4 + 16' only.
}
