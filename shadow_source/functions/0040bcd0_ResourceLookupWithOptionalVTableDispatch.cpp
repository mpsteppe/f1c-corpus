// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040BCD0
// Canonical corpus name: ResourceLookupWithOptionalVTableDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ResourceLookupWithOptionalVTableDispatch_0040bcd0.c

void UnknownObject::ResourceLookupWithOptionalVTableDispatch()
{
    // Guarded resource-lookup on an object. Returns 0 immediately if the key a2 is null. Otherwise runs ShortComputation_b6c0(this, a2) and returns 0 if its result v4 is negative, then runs ShortComputation_b6f0(this, v4). If the boolean flag a3 is set, dispatches a virtual call through the object vtable (vtable pointer at this+0x0, target at vtable offset +0x10) on this. Returns 1 on success. Structural twin of a sibling lookup-with-callback helper per the DERIVED cluster prelabel.
    // GUARD: if (!a2) return 0; a null key short-circuits the lookup. [function:0x0040BCD0, source:raw]
    // CALL: v4 = ShortComputation_b6c0(this, a2); perform the first-stage computation/lookup with the key. [callee:0x0040B6C0, function:0x0040BCD0, source:raw]
    // GUARD: if (v4 < 0) return 0; a negative first-stage result aborts the lookup. [function:0x0040BCD0, source:raw]
    // CALL: ShortComputation_b6f0(this, v4); run the second-stage computation with the resolved first-stage result. [callee:0x0040B6F0, function:0x0040BCD0, source:raw]
    // GUARD: if (a3) — only dispatch the virtual callback when the flag is non-zero. [function:0x0040BCD0, source:raw]
    // CALL: Dispatch the virtual method at vtable offset +0x10: read the vtable pointer at this+0x0, fetch the entry at +0x10, and invoke it as a __thiscall on this. [field:this:0x00000000, field:obj:0x00000010, function:0x0040BCD0, source:raw]
    // RETURN: return 1; report success after a completed lookup. [function:0x0040BCD0, source:raw]

    // Conservative worker pseudocode:
    //   if (!a2) return 0;
    //   v4 = ShortComputation_b6c0(this, a2);
    //   if (v4 < 0) return 0;
    //   ShortComputation_b6f0(this, v4);
    //   if (a3)
    //     (this->vtable[0x10 / 4])(this);
    //   return 1;
    // UNRESOLVED: The two ShortComputation helpers and the virtual vtable+0x10 target are unnamed in the packet, so their concrete behavior is unknown.
    // UNRESOLVED: The owner object type is unidentified; the caller SessionPhaseDispatchWithCascadeChecks (0x0040D1B0) suggests a session/resource-management context but does not identify the class.
    // UNRESOLVED: The dual base names in the packet (field this+0x0 vs field obj+0x10) leave the exact object layout relationship unresolved.
}
