// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046E590
// Canonical corpus name: ProcessingDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ProcessingDispatch_0046e590.c

void UnknownObject::ProcessingDispatch()
{
    // Three-step processing chain: cleans up global device handle dword_7C73E8 via CleanupWrapper, accesses UI list element at index 0, and sets a path-register field with flag 0x40000000; returns 0.
    // CALL: Calls CleanupWrapper on global dword_7C73E8 to clean up the device identity handle. [callee:0x00433EB0, global:0x007C73E8, source:raw]
    // CALL: Calls UIListIndexedAccessor(this, 0) to fetch the UI list element at index 0. [callee:0x00487010, source:raw]
    // CALL: Calls PathRegisterFieldSet on the fetched element with flag 0x40000000. [callee:0x00498D00, source:raw]
    // RETURN: Returns 0. [source:raw]

    // Conservative worker pseudocode:
    //   CleanupWrapper(&dword_7C73E8);
    //   v2 = UIListIndexedAccessor(this, 0);
    //   PathRegisterFieldSet(v2, 0x40000000);
    //   return 0;
    // UNRESOLVED: Semantic role of flag 0x40000000 passed to PathRegisterFieldSet is unknown.
}
