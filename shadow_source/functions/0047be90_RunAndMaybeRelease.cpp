// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047BE90
// Canonical corpus name: ShortComputation_be90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_be90_0047be90.c

void UnknownObject::RunAndMaybeRelease()
{
    // Invokes FunctionCallWrapper on this, then conditionally calls FreeWrapper when flag bit 0 of the second argument is set. Returns this unchanged.
    // CALL: Call FunctionCallWrapper_9440 with this as its argument. [source:raw, callee:0x00489440]
    // GUARD: Guard on (a2 & 1) != 0 controlling whether the object is released. [source:raw]
    // CALL: Call FreeWrapper_7bcf with this as its argument when the guard passes. [source:raw, callee:0x00587BCF]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   void* RunAndMaybeRelease(void* this, char flags) {
    //     FunctionCallWrapper_9440(this);
    //     if ((flags & 1) != 0) FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: Identity of this object and what FunctionCallWrapper_9440 vs FreeWrapper_7bcf do.
    // UNRESOLVED: Meaning of flag bit 0 in the second argument.
}
