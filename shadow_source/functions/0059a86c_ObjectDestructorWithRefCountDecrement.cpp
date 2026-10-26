// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059A86C
// Canonical corpus name: ObjectDestructorWithRefCountDecrement
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectDestructorWithRefCountDecrement_0059a86c.c

void UnknownObject::ObjectDestructorWithRefCountDecrement()
{
    // Object destructor that installs its vtable pointer off_5B9D3C, decrements the object's reference count in the global byte_8D463C array indexed by v1[9], calls sub_59A980 for full cleanup when the count reaches zero or the index is null, and finally null-checks and dispatches the pointer at v2+8. Invoked from 0x0059A8BC.
    // ASSIGNMENT: Object destructor with ref-count decrement (ABI tag Object_Destructor_with_Ref_Count_Decrement); called from 0x0059A8BC, this=v1 is the object instance. [function:0x0059A86C, abi:lead, caller:0x0059A8BC]
    // CALL: SEHHandlerInit() sets up the SEH handler frame on the stack for the destructor body. [callee:0x0058A5D8, global:0x0059D4CB, source:raw]
    // ASSIGNMENT: Save this as v2, store v1 into the SEH frame slot at a1-16, install the vtable pointer off_5B9D3C at *v1, and zero the frame slot at a1-4. [global:0x005B9D3C, source:raw]
    // ASSIGNMENT: Read the ref-count index v3 = v1[9] (offset 0x24 of the object). [source:raw]
    // GUARD: If v3 is null, or decrementing byte_8D463C[v3] leaves the count at or below zero, call sub_59A980(v1) for full cleanup. [global:0x008D463C, callee:0x0059A980, source:raw]
    // CALL: NullCheckWithVirtualDispatch(v2 + 8): null-check the pointer at this+0x20 and perform the virtual dispatch. [callee:0x00598C70, source:raw]

    // Conservative worker pseudocode:
    //   void ObjectDestructorWithRefCountDecrement(int this) {
    //     SEHHandlerInit();
    //     int save = this;
    //     frame_slot(-16) = this;
    //     *(void**)this = &off_5B9D3C;
    //     int idx = ((int*)this)[9];
    //     frame_slot(-4) = 0;
    //     if (idx == 0 || --byte_8D463C[idx] <= 0)
    //       sub_59A980(this);
    //     NullCheckWithVirtualDispatch(save + 8);
    //   }
    // UNRESOLVED: Relationship between the object and the ref-count slot: v1[9] (offset 0x24) doubles as the array index into byte_8D463C.
    // UNRESOLVED: Purpose of NullCheckWithVirtualDispatch on v2+8 (offset 0x20) is unknown.
    // UNRESOLVED: Exact SEH landing-pad semantics tied to loc_59D4CB are not resolved.
}
