// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00474C50
// Canonical corpus name: ShortComputation_4c50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_4c50_00474c50.c

void UnknownObject::InitUiTextViewWithConditionalFree()
{
    // Thiscall wrapper that first initializes the object by calling ShortComputation_4c70 (0x00474C70), which assigns the vtable pointer off_5A4080 and runs VTableInit. Then, when the bit-0 of flag argument a2 is set, frees the object itself through FreeWrapper_7bcf(this). Always returns the original this pointer, even after it has been freed.
    // CALL: Call ShortComputation_4c70() to initialize the object (vtable assignment + VTableInit). The packet source shows the call without an explicit argument; as a __thiscall it is expected to use the enclosing this pointer. [callee:0x00474C70, source:raw]
    // GUARD: Guard on (a2 & 1) != 0; only when bit 0 of the flag argument is set does the function free the object. [source:raw]
    // CALL: Call FreeWrapper_7bcf(this) to free the object when the guard holds. [callee:0x00587BCF, source:raw]
    // RETURN: Return this regardless of whether the object was freed. [source:raw]

    // Conservative worker pseudocode:
    //   void *InitUiTextViewWithConditionalFree(void *this, char a2) {
    //     ShortComputation_4c70();
    //     if ((a2 & 1) != 0)
    //       FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: ShortComputation_4c70() is invoked with no explicit argument in the raw source although it is __thiscall(LPVOID *this); the ECX-receiver linkage to the outer this is inferred, not confirmed by the packet.
    // UNRESOLVED: Semantics of the a2 bit-0 flag (destructor vs. keep-alive contract) are caller-side and not established here.
    // UNRESOLVED: Returning this after a conditional free produces a dangling pointer; whether callers rely on that behavior is unknown.
}
