// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00491E60
// Canonical corpus name: ShortComputation_1e60
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_1e60_00491e60.c

void UnknownObject::ConditionalFreeOnFlag()
{
    // __thiscall teardown helper that frees its own object when the low bit of the flag argument a2 is set. If (a2 & 1) is non-zero it calls FreeWrapper_7bcf(this); it always returns this afterwards. Called by ResourceLinkedListTeardown (00490850) and MultiListDestruction (00490B90), consistent with a destructor-style cleanup path driven by a caller-supplied flag.
    // GUARD: Branch on the flag bit: if (a2 & 1) != 0 the object is freed. [source:raw]
    // CALL: Conditional branch: call FreeWrapper_7bcf (0x00587BCF) with this as the object to free. [callee:0x00587BCF, source:raw]
    // RETURN: Return this unconditionally after the conditional free. [source:raw]
    // CALL: Used by ResourceLinkedListTeardown (0x00490850) and MultiListDestruction (0x00490B90) as a per-node cleanup step. [caller:0x00490850, caller:0x00490B90, source:raw]

    // Conservative worker pseudocode:
    //   void* sub_491E60(void* this, char a2) {
    //     if ((a2 & 1) != 0) FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: Meaning of the flag bit a2 and the exact lifecycle contract (which caller sets it and why) is not established by this packet.
    // UNRESOLVED: FreeWrapper_7bcf is the only side effect; whether it also invalidates later users of this is unknown.
}
