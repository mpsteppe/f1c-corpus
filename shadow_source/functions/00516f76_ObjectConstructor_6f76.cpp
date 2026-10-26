// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00516F76
// Canonical corpus name: ObjectConstructor_6f76
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectConstructor_6f76_00516f76.c

void UnknownObject::ObjectConstructor_6f76()
{
    // Constructs a sub-object for the object at a1 (called from StateMachineWithDispatch 0x0050FB3B). Calls the first vtable entry of the allocator at this+0x4 with (a1, 1, 28) to obtain a 28-byte allocation, stores it at this+0x17C, zeroes a byte flag at sub-object +8, seeds the sub-object's first dword with UIControlStateMachine (0x00516E28) and its second dword with PhysicsStepCounterIncrement (0x00516F55), then delegates the remaining initialization to sub_516C7B and returns its result.
    // CALL: Call the first vtable entry of the allocator object at this+0x4 with (a1, 1, 28) to allocate the 28-byte sub-object. [field:*(this+0x4):0x00000000, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Store the allocated sub-object pointer at this+0x17C. [field:this:0x0000017C, source:raw]
    // ASSIGNMENT: Zero the byte flag at sub-object +8. [source:raw]
    // ASSIGNMENT: Write UIControlStateMachine (0x00516E28) into the first dword of the sub-object, i.e. its vtable pointer slot. [global:0x00516E28, source:raw]
    // ASSIGNMENT: Write PhysicsStepCounterIncrement (0x00516F55) into the second dword of the sub-object as a function pointer. [global:0x00516F55, source:raw]
    // CALL: Delegate the remaining initialization of the object to sub_516C7B(a1). [callee:0x00516C7B, source:raw]
    // RETURN: Return the result of sub_516C7B; the sole static caller is StateMachineWithDispatch (0x0050FB3B). [callee:0x00516C7B, caller:0x0050FB3B, source:raw]

    // Conservative worker pseudocode:
    //   int sub_516F76(int a1) {
    //     int obj = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 28);
    //     *(int *)(a1 + 380) = obj;
    //     *(char *)(obj + 8) = 0;
    //     *(int *)obj = UIControlStateMachine;
    //     *(int *)(obj + 4) = PhysicsStepCounterIncrement;
    //     return sub_516C7B(a1);
    //   }
    // UNRESOLVED: The concrete allocator behind the first vtable entry at this+0x4 is an indirect call resolved at runtime; the allocator implementation is unknown from this packet.
    // UNRESOLVED: The exact roles of UIControlStateMachine and PhysicsStepCounterIncrement inside the new sub-object are inferred from context, not proven.
    // UNRESOLVED: The meaning of the flag 1 passed to the allocator (type/count selector) is unknown.
}
