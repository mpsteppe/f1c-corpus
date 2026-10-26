// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D1180
// Canonical corpus name: sub_4D1180
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D1180_004d1180.c

void UnknownObject::RenderDispatchWithSessionGuard()
{
    // Session-gated render dispatch. When the session-type global dword_7C56A4 equals 7 and the phase global dword_7C56A8 is 2, 3 or 4, forwards the three arguments to SingleFunctionDispatch_10e0 (0x004D10E0) and returns 1; otherwise forwards them to RenderCallWithGuard (0x004D1140) and returns 0. Frame-path helper called by sub_4C6B60 (0x004C6B60) and SceneRenderUpdate (0x004C6D90).
    // GUARD: Dispatch-race guard: take the race-dispatch branch only when dword_7C56A4 == 7 and dword_7C56A8 is 2, 3 or 4; otherwise take the generic-render branch. [global:0x007C56A4, global:0x007C56A8, source:raw]
    // CALL: When the guard matches, call SingleFunctionDispatch_10e0(0x004D10E0) with (a1, a2, a3). [callee:0x004D10E0, source:raw]
    // RETURN: Return 1 on the race-dispatch path. [function:0x004D1180, source:raw]
    // CALL: When the guard does not match, call RenderCallWithGuard(0x004D1140) with (a1, a2, a3). [callee:0x004D1140, source:raw]
    // RETURN: Return 0 on the generic-render path. [function:0x004D1180, source:raw]

    // Conservative worker pseudocode:
    //   char RenderDispatchWithSessionGuard(_DWORD *a1, float *a2, _DWORD *a3) {
    //     if (dword_7C56A4 == 7 && (dword_7C56A8 == 2 || dword_7C56A8 == 3 || dword_7C56A8 == 4)) {
    //       SingleFunctionDispatch_10e0((int)a1, a2, a3);
    //       return 1;
    //     }
    //     RenderCallWithGuard(a1, a2, a3);
    //     return 0;
    //   }
    // UNRESOLVED: The semantic interpretation dword_7C56A4 == 7 as a race session type and dword_7C56A8 in {2, 3, 4} as active racing phases is taken from existing analysis prose; the raw source only grounds the literal comparisons.
    // UNRESOLVED: The distinct behavior of the two dispatch callees (SingleFunctionDispatch_10e0 vs RenderCallWithGuard) is not evidenced by this function.
}
