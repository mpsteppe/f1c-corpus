// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00475020
// Canonical corpus name: ConditionalFreeWithFlagCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalFreeWithFlagCheck_00475020.c

void UnknownObject::ConditionalFreeAfterVTableSetter()
{
    // Thiscall wrapper that first calls VTableSetterWithSubCall (0x00475040) to configure the object, then, when bit 0 of flag argument a2 is set, frees the object itself through FreeWrapper_7bcf(this). Always returns the original this pointer, even after it has been freed. Structurally mirrors the ShortComputation_4c50 wrapper with a different setup callee.
    // CALL: Call VTableSetterWithSubCall() to set up the object. The packet source shows the call without an explicit argument; as a thiscall-family call it is expected to use the enclosing this pointer. [callee:0x00475040, source:raw]
    // GUARD: Guard on (a2 & 1) != 0; only when bit 0 of the flag argument is set does the function free the object. [source:raw]
    // CALL: Call FreeWrapper_7bcf(this) to free the object when the guard holds. [callee:0x00587BCF, source:raw]
    // RETURN: Return this regardless of whether the object was freed. [source:raw]

    // Conservative worker pseudocode:
    //   void *ConditionalFreeAfterVTableSetter(void *this, char a2) {
    //     VTableSetterWithSubCall();
    //     if ((a2 & 1) != 0)
    //       FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: VTableSetterWithSubCall() is invoked with no explicit argument in the raw source; the receiver linkage to the outer this is inferred, not confirmed by the packet.
    // UNRESOLVED: What 0x00475040 configures (vtable assignment or other state) is not established by the packet.
    // UNRESOLVED: Semantics of the a2 bit-0 flag and the returned dangling this pointer are caller-side contracts not established here.
}
