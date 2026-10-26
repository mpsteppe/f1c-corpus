// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046B5E0
// Canonical corpus name: VTableSetAndInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VTableSetAndInit_0046b5e0.c

void UnknownObject::VTableSetAndInit()
{
    // Object init entry: writes the vtable pointer off_59FA98 into this->vtable at offset 0x0, then delegates to the init wrapper FunctionCallWrapper_9440(this) and returns its result. Called from DestructorWithConditionalFree_b5c0 as the destruction/cleanup step for the season-database variant type.
    // ASSIGNMENT: Store the vtable pointer &off_59FA98 into this->vtable at offset 0x0. [field:this:0x00000000, global:0x0059FA98]
    // CALL: Call FunctionCallWrapper_9440(this) to perform further initialization and pass through its result. [source:raw]
    // RETURN: Return the value produced by FunctionCallWrapper_9440(this). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_46B5E0(void *this) {
    //     *(void **)this = &off_59FA98;
    //     return FunctionCallWrapper_9440(this);
    //   }
    // UNRESOLVED: FunctionCallWrapper_9440 has no callee record in this packet; its target address is unknown here.
    // UNRESOLVED: Object type owning the off_59FA98 vtable variant is unknown.
}
