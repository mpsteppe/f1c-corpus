// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00595733
// Canonical corpus name: AmsgExitRuntimeError
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AmsgExitRuntimeError_00595733.c

void UnknownObject::AmsgExitRuntimeError()
{
    // Thin runtime-error exit wrapper: calls CRTAmsgExit (0x0058A2A6) with the argument 2u and returns its result. No local state, no guards, no fields.
    // CALL: Call CRTAmsgExit (0x0058A2A6) with the argument 2u to trigger the amsg runtime error exit path. [callee:0x0058A2A6, source:raw]
    // RETURN: Return the result of CRTAmsgExit(2u). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_595733() {
    //     return CRTAmsgExit(2u);
    //   }
    // UNRESOLVED: Meaning of the exit argument 2u depends on the amsg runtime's contract; not evidenced in this packet.
}
