// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050CBB0
// Canonical corpus name: ThunkToFUN0050cba3
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThunkToFUN0050cba3_0050cbb0.c

void UnknownObject::ThunkToFUN0050cba3()
{
    // Forwarding thunk. Calls the function pointer stored in the global off_5D77D4 with no arguments and returns its int result unchanged. All actual behavior lives in whatever function that global currently points to, which is assigned elsewhere at runtime. Called from TransformOffsetSetup, ColorMatrixTransformWithBlend, sub_50EB73, SkeletonBoneTransformConstruction, and sub_55CC20.
    // CALL: Indirect call through the function pointer in global off_5D77D4; the callee is resolved at runtime and called with no arguments. [source:raw, global:0x005D77D4]
    // RETURN: Return the callee's int result unchanged. [source:raw, function:0x0050CBB0]

    // Conservative worker pseudocode:
    //   int ThunkToFUN0050cba3() {
    //     return ((int (*)())off_5D77D4)();
    //   }
    // UNRESOLVED: The target of off_5D77D4 is set elsewhere at runtime; its identity is unknown from this function alone.
    // UNRESOLVED: Callee prototype is unknown; the call is treated as an unprototyped function call with no arguments.
}
