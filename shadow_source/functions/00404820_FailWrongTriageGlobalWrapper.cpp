// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00404820
// Canonical corpus name: SingleFunctionCallWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SingleFunctionCallWrapper_00404820.c

void UnknownObject::FailWrongTriageGlobalWrapper()
{
    // Single-call delegation wrapper. Passes the address of the global dword_5EA43C to FAILWRONGTRIAGE and returns that call's result unchanged. No local state, guards, or control flow; the entire function body is one forwarding call.
    // CALL: FAILWRONGTRIAGE(&dword_5EA43C) — invoke the named callee with the address of the global; FAILWRONGTRIAGE appears only in the raw source text and has no callee entry in the packet [global:0x005EA43C, source:raw]
    // RETURN: return the result of FAILWRONGTRIAGE directly; no transformation is applied [source:raw]

    // Conservative worker pseudocode:
    //   return FAILWRONGTRIAGE(&dword_5EA43C);
    // UNRESOLVED: FAILWRONGTRIAGE is referenced by name in the raw source but has no callee entry or address in the packet, so its identity and location are not available here
    // UNRESOLVED: the role of the pointed-to global dword_5EA43C (input, output, or scratch) is unknown
}
