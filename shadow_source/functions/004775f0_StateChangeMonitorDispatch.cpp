// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004775F0
// Canonical corpus name: ShortComputation_75f0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_75f0_004775f0.c

void UnknownObject::StateChangeMonitorDispatch()
{
    // State-change monitor. Resolves a tracked object through UtilityFunction_7810 (00477810); if non-null, reads a dword from it (raw literal v2 + 372) and compares it to the cached copy at this[97] (offset 0x184). On a difference it re-caches the value and invokes a virtual callback at vtable offset 160 on this. Always returns 0.
    // CALL: Resolve tracked object: v2 = UtilityFunction_7810(this) (00477810) [callee:0x00477810, source:raw]
    // GUARD: Null guard: only proceed when v2 is non-null (tracked object exists) [source:raw]
    // CALCULATION: Read monitored value: v3 = *(_DWORD*)(v2 + 372) (dword at tracked-object offset 0x174 per the raw literal; the packet's deterministic facts declare the read field as obj offset 0xA0) [field:obj:0x000000A0, source:raw]
    // GUARD: Change detection: only act when v3 differs from the cached value at this[97] (offset 0x184) [field:this:0x00000184, source:raw]
    // ASSIGNMENT: Re-cache the monitored value: this[97] = v3 at offset 0x184 [field:this:0x00000184, source:raw]
    // CALL: Dispatch on change: invoke the virtual method at vtable offset 160, called with this as the receiver [field:this:0x00000000, source:raw]
    // RETURN: Return 0 on all paths [function:0x004775F0, source:raw]

    // Conservative worker pseudocode:
    //   v2 = UtilityFunction_7810(this);
    //   if (v2) {
    //     v3 = *(_DWORD*)(v2 + 372);
    //     if (v3 != this[97]) {
    //       this[97] = v3;
    //       (*(void (__thiscall **)(_DWORD*))(*this + 160))(this);
    //     }
    //   }
    //   return 0;
    // UNRESOLVED: Offset disagreement on the monitored read: the raw source literal is v2 + 372 (0x174) while the packet's deterministic field facts declare the read at obj offset 0xA0; both are retained as evidence and need independent corroboration
    // UNRESOLVED: The virtual dispatch target at vtable offset 160 is unresolved without the owning class's vtable
    // UNRESOLVED: The meaning of the monitored state cached at this[97] (offset 0x184) is external to this function
    // UNRESOLVED: Owner object type is unknown; no class can be proposed from this evidence alone
}
