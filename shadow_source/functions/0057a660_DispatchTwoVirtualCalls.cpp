// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057A660
// Canonical corpus name: DualVirtualDispatchWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualVirtualDispatchWrapper_0057a660.c

void UnknownObject::DispatchTwoVirtualCalls()
{
    // Reads the object pointer stored in this+0x0, then performs two sequential virtual calls through that object's vtable. First call: vtable entry at byte offset 0x74 (vtable+116), invoked with no extra arguments. Second call: vtable entry at byte offset 0x9C (vtable+156), invoked with two zero arguments. Returns the constant 1. The callees are indirect (virtual) so no static callee targets exist. Called by NetCommSessionMessageDispatcher (0045D890) and ShortComputation_3140 (00463140).
    // ASSIGNMENT: Loads the target object pointer from the pointer slot this+0x0 [field:this:0x00000000, source:raw]
    // CALL: First virtual dispatch: reads the object vtable pointer at obj+0x0 and calls the entry at vtable byte offset 0x74 (vtable+116) with no extra arguments [field:obj:0x00000000, field:*(obj+0x0):0x00000074, source:raw]
    // CALL: Second virtual dispatch: calls the vtable entry at byte offset 0x9C (vtable+156) on the same object with two zero arguments [field:obj:0x00000000, field:*(obj+0x0):0x0000009C, source:raw]
    // RETURN: Returns the constant 1 [source:raw, function:0x0057A660]
    // CALL: Invoked by NetCommSessionMessageDispatcher (0045D890) and ShortComputation_3140 (00463140) [caller:0x0045D890, caller:0x00463140]

    // Conservative worker pseudocode:
    //   obj = *(this + 0);
    //   (*obj->vtable[0x74 / 4])(obj);
    //   (*obj->vtable[0x9C / 4])(obj, 0, 0);
    //   return 1;
    // UNRESOLVED: Both called methods are indirect virtual entries; their concrete identities and callees are unknown without the target object's vtable layout
    // UNRESOLVED: The owner object type is unresolved (UnknownObject), so the two dispatched methods cannot be named
}
