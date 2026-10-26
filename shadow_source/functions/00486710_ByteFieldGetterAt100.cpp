// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00486710
// Canonical corpus name: ByteFieldGetterAt100
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ByteFieldGetterAt100_00486710.c

void UnknownObject::ByteFieldGetterAt100()
{
    // Getter: reads and returns the byte stored at this+0x64 (this[100]). No side effects; single read of the field, no writes, no calls. Its callers are UI-oriented (UIStateChangeDispatcher, UIValueValidator, UIFieldRenderer, StateQueryDispatch, UIStateChangeDispatcher variants), suggesting the returned byte is a per-object UI state/flag, but the owning class and the field's meaning are not established.
    // RETURN: Return the byte value read at this+0x64 (this[100]). [source:raw, function:0x00486710, field:this:0x00000064]

    // Conservative worker pseudocode:
    //   char __thiscall ByteFieldGetterAt100(_BYTE* this) {
    //     return this[100];
    //   }
    // UNRESOLVED: The owning class is unknown (UnknownObject); the byte field at this+0x64 is untyped beyond 'byte'.
    // UNRESOLVED: Field semantics unknown; UI-oriented callers suggest a state/flag byte but this is not confirmed.
    // UNRESOLVED: No callees or globals, so no further structural context is available from this function alone.
}
