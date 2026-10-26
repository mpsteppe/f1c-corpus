// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F9230
// Canonical corpus name: PathDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PathDispatch_004f9230.c

void UnknownObject::PathDispatch()
{
    // Reads the global path-dispatch value dword_5EC48C and hands it to GuardedFieldAccessor (0x004F9200), returning that callee's result unchanged. A zero-argument forwarder used by MaterialShaderReactionEffectParser (0x004CA480) to fetch a guarded field via the shared accessor.
    // CALL: GuardedFieldAccessor(dword_5EC48C) passes the global dword_5EC48C into the shared guarded-field accessor. [callee:0x004F9200, global:0x005EC48C, source:raw]
    // RETURN: Return the value returned by GuardedFieldAccessor without modification. [callee:0x004F9200, global:0x005EC48C, source:raw]
    // CALL: Called by MaterialShaderReactionEffectParser as part of the material/shader effect parsing path. [caller:0x004CA480, source:raw]

    // Conservative worker pseudocode:
    //   int PathDispatch() {
    //     return GuardedFieldAccessor(dword_5EC48C);
    //   }
    // UNRESOLVED: dword_5EC48C is read but its semantic role (which guarded field it selects) is not proven by the packet.
    // UNRESOLVED: Owner type remains UnknownObject; abi label Path_Dispatch is LEGACY trust and does not confirm a class membership.
}
