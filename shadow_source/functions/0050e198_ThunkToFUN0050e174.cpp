// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050E198
// Canonical corpus name: ThunkToFUN0050e174
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThunkToFUN0050e174_0050e198.c

void UnknownObject::ThunkToFUN0050e174()
{
    // Thunk (stdcall) that forwards its four arguments (three ints and one float) unchanged to the function pointer stored in the global off_5D7854 and returns that call's result. The target is an indirect dispatch, so the concrete callee is resolved at runtime through the pointer table entry at 0x005D7854.
    // CALL: Dispatch the call through the global function pointer off_5D7854 with (a1, a2, a3, a4); this is the only body statement of the thunk. [global:0x005D7854, source:raw]
    // RETURN: Return the value produced by the indirect call through off_5D7854. [source:raw]
    // CALL: The thunk is invoked by QuadraticBezier (0x0050E2AB) and sub_50E342 (0x0050E342) as the shared dispatch hop for the routine stored at off_5D7854. [caller:0x0050E2AB, caller:0x0050E342, function:0x0050E198, source:raw]

    // Conservative worker pseudocode:
    //   int __stdcall ThunkToFUN0050e174(int a1, int a2, int a3, float a4) {
    //     return off_5D7854(a1, a2, a3, a4);
    //   }
    // UNRESOLVED: The concrete target behind the function pointer off_5D7854 is unknown from this packet; only its address slot (0x005D7854) is evidenced.
    // UNRESOLVED: Parameter semantics depend on the runtime-resolved target and on each caller's use; no field or named prototype is available here.
}
