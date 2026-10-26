// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00473650
// Canonical corpus name: ResourceCheckVirtualCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ResourceCheckVirtualCall_00473650.c

void UnknownObject::ResourceCheckVirtualCall()
{
    // Retrieves a resource object through the GameCommandDispatchInterface vtable (global dword_7CD8C0, virtual slot 28) using resource ID 19, optionally compares that object's name with `this` via ObjectNameComparison when the retrieved object is non-null, then unconditionally invokes the virtual method at vtable offset 172 on `this` and returns 0. The name comparison reads the retrieved object's +0xAC field.
    // CALL: Virtual dispatch through dword_7CD8C0 (GameCommandDispatchInterface) vtable slot 28 with arguments (dword_7CD8C0, 19); result is stored as v2. 19 is treated as a resource/object ID for retrieval. [global:0x007CD8C0, function:0x00473650, source:raw]
    // GUARD: If v2 (the retrieved resource object) is non-null, proceed to ObjectNameComparison; a null v2 skips the name comparison. [function:0x00473650, source:raw]
    // CALL: ObjectNameComparison(v2, this) compares the retrieved object's name (reading the +0xAC field of obj) with `this`. [callee:0x00477280, field:obj:0x000000AC, source:raw]
    // CALL: Virtual dispatch through the vtable at this+0x0, slot 172, called with (this); executes unconditionally after the guarded name comparison. [field:this:0x00000000, function:0x00473650, source:raw]
    // RETURN: Returns 0. [function:0x00473650, source:raw]

    // Conservative worker pseudocode:
    //   v2 = ((*dword_7CD8C0)->slot[28])(dword_7CD8C0, 19);
    //   if (v2) ObjectNameComparison(v2, this);
    //   (*this)->slot[172](this);
    //   return 0;
    // UNRESOLVED: The identity of the object type behind dword_7CD8C0 and the meaning of the virtual slot 28 retrieval call are not evidenced beyond the ID argument 19.
    // UNRESOLVED: The virtual method invoked at this+172 is unknown; no callee address is resolvable from the packet.
    // UNRESOLVED: The exact contract of ObjectNameComparison and whether a mismatch produces a side effect are outside this packet.
    // UNRESOLVED: The +0xAC field on obj is only evidenced as read during the name comparison; its semantics are not established.
    // UNRESOLVED: No static callers were found in the packet, so the purpose of the trailing virtual call (resource check then notify?) is unverified.
}
