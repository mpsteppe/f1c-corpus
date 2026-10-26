// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FB8E0
// Canonical corpus name: ThunkToFUN004fc9c0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThunkToFUN004fc9c0_004fb8e0.c

void UnknownObject::CallStructInitWithFloatDefaults()
{
    // Thin wrapper: calls StructInitWithFloatDefaults with the global unk_8AFEC0 (0x008AFEC0) as its argument and returns the call's result unchanged. No local state, guards, or control flow; the entire function body is one forwarding call.
    // CALL: Invoke StructInitWithFloatDefaults passing the global unk_8AFEC0 (0x008AFEC0) as the argument. [global:0x008AFEC0, source:raw]
    // RETURN: Return the result of the StructInitWithFloatDefaults call. [source:raw]

    // Conservative worker pseudocode:
    //   int CallStructInitWithFloatDefaults() {
    //     return StructInitWithFloatDefaults(&unk_8AFEC0);
    //   }
    // UNRESOLVED: unk_8AFEC0 is unnamed; its type, content, and lifecycle are unknown.
    // UNRESOLVED: StructInitWithFloatDefaults is named only in the raw source text; it is absent from the packet callees list, so no callee address or semantic contract is available.
    // UNRESOLVED: The ABI lead name 'Thunk_to_FUN_004fc9c0' suggests a thunk to another function, but the raw source forwards to StructInitWithFloatDefaults; the thunk target and the callee name are not reconciled.
    // UNRESOLVED: No callers or owner evidence exist.
}
