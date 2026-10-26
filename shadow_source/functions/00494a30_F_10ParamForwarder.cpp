// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00494A30
// Canonical corpus name: F_10ParamForwarder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_10ParamForwarder_00494a30.c

void UnknownObject::F_10ParamForwarder()
{
    // __stdcall forwarding wrapper: ignores its first parameter a1 and forwards the remaining nine arguments a2..a10 unchanged to ClippedRenderRegion (0x00543250), returning that call's result. Used by scrollbar, UI scroll view, text-box, text-input and bitmap-blit render paths.
    // CALL: Call ClippedRenderRegion(a2, a3, a4, a5, a6, a7, a8, a9, a10), forwarding every parameter except a1 unchanged. [callee:0x00543250, function:0x00494A30, source:raw]
    // RETURN: Return the result of the ClippedRenderRegion call unchanged. [callee:0x00543250, source:raw]

    // Conservative worker pseudocode:
    //   return ClippedRenderRegion(a2, a3, a4, a5, a6, a7, a8, a9, a10);
    // UNRESOLVED: Parameter a1 is received but never used; its purpose is unknown (possibly a dropped context/this parameter of the __stdcall forward).
    // UNRESOLVED: The exact meaning of each forwarded rectangle/draw argument depends on ClippedRenderRegion's own contract, which this packet does not establish.
}
