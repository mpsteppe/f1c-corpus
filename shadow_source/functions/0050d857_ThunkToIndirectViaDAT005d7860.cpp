// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050D857
// Canonical corpus name: ThunkToIndirectCallViaDAT005d7860
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThunkToIndirectCallViaDAT005d7860_0050d857.c

void UnknownObject::ThunkToIndirectViaDAT005d7860()
{
    // Forwarding thunk on a transform/skeleton path: reads the function pointer stored in global off_5D7860 (0x005D7860) and calls it with no arguments, returning its int result unchanged. The actual callee is assigned to that global at runtime. Called by TransformOffsetSetup (0x0050D9A5), TwoThunkWrapper (0x0050EDD2) and SkeletonBoneTransformConstruction (0x0050EE0B).
    // CALL: Indirect call through the function pointer held in global off_5D7860 (0x005D7860); the callee is resolved at runtime and invoked with no arguments. [source:raw, global:0x005D7860]
    // RETURN: Return the callee's int result unchanged. [source:raw, function:0x0050D857]

    // Conservative worker pseudocode:
    //   int ThunkToIndirectViaDAT005d7860() {
    //     return off_5D7860();
    //   }
    // UNRESOLVED: The target of off_5D7860 (0x005D7860) is assigned elsewhere at runtime; its identity is unknown from this thunk alone.
    // UNRESOLVED: Callee prototype is unknown; the call is treated as an unprototyped function call with no arguments returning int.
    // UNRESOLVED: Callers TransformOffsetSetup (0x0050D9A5), TwoThunkWrapper (0x0050EDD2) and SkeletonBoneTransformConstruction (0x0050EE0B) are not analyzed.
}
