// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050CDF9
// Canonical corpus name: ThunkViaGlobalFunctionPointer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThunkViaGlobalFunctionPointer_0050cdf9.c

void UnknownObject::ThunkViaGlobalFunctionPointer()
{
    // Thunk that transfers control to the function held in the global function pointer off_5D785C and returns its result unchanged. No stack setup, argument marshalling or post-processing; a pure indirection shim. Invoked from SkeletonBoneTransformConstruction (0x0050EE0B) and sub_55CC20 (0x0055CC20).
    // CALL: Call the function stored in the global function pointer off_5D785C; the decompiled thunk passes no explicit arguments. [global:0x005D785C, abi:lead, source:raw]
    // RETURN: Return the result produced by the indirect call through off_5D785C. [source:raw]

    // Conservative worker pseudocode:
    //   int ThunkViaGlobalFunctionPointer() {
    //     return off_5D785C();
    //   }
    // UNRESOLVED: The concrete callee is resolved only at runtime through the global pointer off_5D785C; the static target is unknown.
    // UNRESOLVED: The two callers (SkeletonBoneTransformConstruction 0x0050EE0B, sub_55CC20 0x0055CC20) are known but the intended dispatch/owner object is unidentified.
    // UNRESOLVED: The ABI name Thunk_via_Global_Function_Pointer (LEGACY) matches the raw source but is not independently confirmed.
}
