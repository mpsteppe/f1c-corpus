// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00585DE0
// Canonical corpus name: QueueUserAPCAsyncProcedureCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QueueUserAPCAsyncProcedureCall_00585de0.c

void UnknownObject::QueueUserAPCAsyncProcedureCall()
{
    // Queues an asynchronous procedure call: QueueUserAPC(pfnAPC, dwData[1], (ULONG_PTR)dwData). The thread handle is read from this+0x4, the APC routine is the global pfnAPC (0x0041A160), and the ULONG_PTR APC parameter is the dwData pointer itself. Returns the QueueUserAPC result. No guards.
    // CALL: Call QueueUserAPC(pfnAPC, dwData[1], (ULONG_PTR)dwData): queue the global APC routine on the thread identified by the handle at this+0x4, passing this (dwData) as the ULONG_PTR APC parameter. [field:this:0x00000004, global:0x0041A160, global:0x0059E1F4, source:raw]
    // RETURN: Return the DWORD result of QueueUserAPC. [global:0x0059E1F4, source:raw]

    // Conservative worker pseudocode:
    //   DWORD sub_585DE0(HANDLE *dwData, int a2) {
    //     return QueueUserAPC(pfnAPC, dwData[1], (ULONG_PTR)dwData);
    //   }
    // UNRESOLVED: The identity and semantics of the global APC routine pfnAPC (0x0041A160) are unknown.
    // UNRESOLVED: The second parameter a2 is unused in the body; its role is unknown.
    // UNRESOLVED: Whether dwData[0] (this) is a distinct APC-parameter object and what it represents is unverified.
}
