// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005874D0
// Canonical corpus name: OperatorNewWithResultCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/OperatorNewWithResultCheck_005874d0.c

void UnknownObject::OperatorNewWithResultCheck()
{
    // __stdcall allocation wrapper: calls OperatorNewNhMallocWrapper with the requested size a1, stores the returned pointer through the caller-provided output parameter a2, and returns whether the allocation succeeded (pointer non-null). Lets callers that must grow or reallocate buffers detect allocation failure.
    // CALL: Call OperatorNewNhMallocWrapper(a1) to allocate the requested bytes, capturing the resulting pointer into the local v2. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Store the allocation result v2 through the output parameter a2 so the caller receives the new pointer. [source:raw]
    // RETURN: Return the success flag computed as (v2 != 0); a zero pointer reports allocation failure. [source:raw]

    // Conservative worker pseudocode:
    //   bool sub_5874D0(int a1, _DWORD* a2) {
    //     int v2 = OperatorNewNhMallocWrapper(a1);
    //     *a2 = v2;
    //     return v2 != 0;
    //   }
    // UNRESOLVED: The object type allocated for a1 bytes and how each caller interprets the success flag are not determinable from this packet.
}
