// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DCD60
// Canonical corpus name: ConditionalCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalCall_004dcd60.c

void UnknownObject::guardedDispatchWithFallback()
{
    // Guard-enabled dispatch: when this[0] (offset 0x0) is non-null, resolves a dispatch pointer from argument a2, substituting the global dword_8B8DC8 when a2 is null, and calls sub_553700 with it. No-op when this[0] is null.
    // GUARD: Guard on this[0] (offset 0x0) being non-null: the entire dispatch body is skipped when it is null. [source:raw, field:this:0x00000000]
    // ASSIGNMENT: Default the dispatch pointer to argument a2. [source:raw]
    // CALCULATION: When a2 is null, substitute the global dword_8B8DC8 (device/context fallback pointer) as the dispatch argument. [source:raw, global:0x008B8DC8]
    // CALL: Call sub_553700 with the resolved dispatch pointer. [source:raw]

    // Conservative worker pseudocode:
    //   if (this[0]) {
    //       p = a2;
    //       if (!a2) p = dword_8B8DC8;
    //       sub_553700(p);
    //   }
    // UNRESOLVED: Target sub_553700 is not present in the packet's static callee list; its contract (render/setup with a device pointer) is inferred from the callers and the fallback global, not confirmed.
    // UNRESOLVED: Semantics of this[0] (enable/guard field) and dword_8B8DC8 (device pointer) are DERIVED from usage, not confirmed.
    // UNRESOLVED: Callers are render-path functions: 0x0045B660, 0x0049B370, 0x0049F070.
}
