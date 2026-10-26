// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050C5BD
// Canonical corpus name: ThunkToThunkFUN0050c5b0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThunkToThunkFUN0050c5b0_0050c5bd.c

void UnknownObject::ThunkToIndirectViaDAT005d77f0()
{
    // Forwarding thunk on a rendering/color path: reads the function pointer stored in global off_5D77F0 (0x005D77F0) and calls it with no arguments, returning its int result unchanged. The actual callee is assigned to that global at runtime. Called by ColorMatrixTransformWithBlend (0x0050E9E6) and sub_50EB73 (0x0050EB73).
    // CALL: Indirect call through the function pointer held in global off_5D77F0 (0x005D77F0); the callee is resolved at runtime and invoked with no arguments. [source:raw, global:0x005D77F0]
    // RETURN: Return the callee's int result unchanged. [source:raw, function:0x0050C5BD]

    // Conservative worker pseudocode:
    //   int ThunkToIndirectViaDAT005d77f0() {
    //     return off_5D77F0();
    //   }
    // UNRESOLVED: The target of off_5D77F0 (0x005D77F0) is assigned elsewhere at runtime; its identity is unknown from this thunk alone.
    // UNRESOLVED: Callee prototype is unknown; the call is treated as an unprototyped function call with no arguments returning int.
    // UNRESOLVED: Callers ColorMatrixTransformWithBlend (0x0050E9E6) and sub_50EB73 (0x0050EB73) are not analyzed.
}
