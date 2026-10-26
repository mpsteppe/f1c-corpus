// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052D8D0
// Canonical corpus name: ThreadedObjectCreatorWithSEH
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThreadedObjectCreatorWithSEH_0052d8d0.c

void UnknownObject::ThreadedObjectCreatorWithSEH()
{
    // Lazily allocates and constructs a RenderObject-sized (11584-byte) object into the output slot *this. Allocates 11584 bytes via OperatorNewNhMallocWrapper, constructs the object with RenderObjectConstructor_e170(a2, a3), stores the pointer into *this, then initializes it through the vtable dispatch at offset +4 with the argument a4; returns 1 when the dispatch result is not -1. On allocation failure or failed initialization, runs VirtualCleanup and returns 0. Skips all work when the output slot is already non-null.
    // GUARD: When *this is already non-null (object already created), skip construction and return 0. [field:this:0x00000000, source:raw]
    // CALL: OperatorNewNhMallocWrapper(11584) allocates the 11584-byte heap block for the object. [callee:0x00587C03, source:raw]
    // GUARD: Branch on whether the allocation returned a non-null pointer; a null result yields v5 = 0. [callee:0x00587C03, source:raw]
    // CALL: RenderObjectConstructor_e170(a2, a3) constructs the object at the allocated memory. [callee:0x0052E170, source:raw]
    // ASSIGNMENT: Store the constructed object pointer v5 into the output slot *this. [field:this:0x00000000, source:raw]
    // CALL: Call the vtable entry at offset +4 of the object: (*(vtable+4))(object, 0, a4) to initialize it. [source:raw]
    // GUARD: When the vtable dispatch result is not -1, return 1 (success). [source:raw]
    // CALL: VirtualCleanup(this) destroys the object via its vtable and nulls the slot after failed construction or initialization. [callee:0x0052D990, field:this:0x00000000, source:raw]
    // RETURN: Return 0 when the slot was already set, allocation failed, or initialization failed. [source:raw]

    // Conservative worker pseudocode:
    //   char ThreadedObjectCreatorWithSEH(void** this_, int a2, int a3, int a4) {
    //     if (*this_) return 0;
    //     int* v5;
    //     if (OperatorNewNhMallocWrapper(11584))
    //       v5 = RenderObjectConstructor_e170(a2, a3);
    //     else
    //       v5 = 0;
    //     *this_ = v5;
    //     if (((int (__thiscall**)(int, int, int))*(int*)v5)[1](v5, 0, a4) != -1)
    //       return 1;
    //     VirtualCleanup(this_);
    //     return 0;
    //   }
    // UNRESOLVED: The object type behind *this is unknown; the only recorded caller is BinaryDataDeserialization (0x004054E0).
    // UNRESOLVED: The SEH registration global SEH_52D8D0 is compiler-emitted and does not appear in the decompiled body, so its exact role here is not observable from this packet.
    // UNRESOLVED: The vtable entry at offset +4 and the meaning of the -1 failure sentinel are not established by the packet alone.
}
