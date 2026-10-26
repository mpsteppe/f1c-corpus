// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00567AF0
// Canonical corpus name: sub_567AF0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_567AF0_00567af0.c

void UnknownObject::forward_567B10()
{
    // Forwarding thunk (marked thunk in the raw source). Accepts two integer arguments a1 and a2, unconditionally forwards them to sub_567B10 and returns that call's result unchanged. No guards, local computation or side effects of its own. It is invoked by FileDataProcessor (0x00567FB0), so it appears to be a redirect shim on the file-data processing path.
    // CALL: Invoked by FileDataProcessor (0x00567FB0); forwards execution to sub_567B10 with both arguments a1 and a2 passed through unchanged. [caller:0x00567FB0, function:0x00567AF0, source:raw]
    // RETURN: Return the result of the sub_567B10(a1, a2) call as this function's own result. [function:0x00567AF0, source:raw]

    // Conservative worker pseudocode:
    //   int __stdcall forward_567B10(int a1, int a2) {
    //     return sub_567B10(a1, a2);
    //   }
    // UNRESOLVED: The identity and behaviour of the target sub_567B10 is not evidenced in this packet (no callee facts recorded); the thunk's purpose depends on that target.
    // UNRESOLVED: The owner class is unknown; FileDataProcessor (0x00567FB0) is the only recorded caller.
    // UNRESOLVED: Whether this is a genuine dispatch shim or an artefact of the decompiler's call-flagging is not established.
}
