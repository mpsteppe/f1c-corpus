// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587C03
// Canonical corpus name: OperatorNewNhMallocWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/OperatorNewNhMallocWrapper_00587c03.c

void UnknownObject::NhMallocWrapper()
{
    // Thin forwarding wrapper: returns NhMalloc(a1, 1) where a1 is the requested byte size and 1 is a fixed second argument. The legacy ABI label identifies it as operator new. Called from hundreds of allocation sites across the game (mesh, camera, physics buffer, linked-list node, network packet, string and texture allocations), including operator-new-style callers such as OperatorNewWithResultCheck.
    // CALL: Call NhMalloc with (a1, 1). [callee:0x0058A947, source:raw]
    // RETURN: Return the result of NhMalloc(a1, 1). [function:0x00587C03, source:raw]

    // Conservative worker pseudocode:
    //   return NhMalloc(a1, 1);
    // UNRESOLVED: Meaning of the fixed second argument 1 passed to NhMalloc (allocation tag or zero-init flag) is unknown.
    // UNRESOLVED: Relationship to the legacy 'operator_new' ABI label is unconfirmed by the raw source.
    // UNRESOLVED: Owner object is not applicable or unknown; the function is a free __cdecl wrapper.
}
