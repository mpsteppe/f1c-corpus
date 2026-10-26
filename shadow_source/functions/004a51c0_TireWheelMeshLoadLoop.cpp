// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A51C0
// Canonical corpus name: sub_4A51C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A51C0_004a51c0.c

void UnknownObject::TireWheelMeshLoadLoop()
{
    // Loads tire and wheel graphics meshes by looping over file entries. Opens an audio stream for the tire sound handle a2, maps global detail level dword_7CF884 through jump table jpt_4A5216 to an LOD scale factor (3.0/2.0/1.0/0.0), then iterates data entries via ConditionalDispatchBasedOnFlag, resolving each name through global instance table aInstance and handing it to TireWheelGraphicsMeshLoader. Performs conditional handle cleanup and field-free return. Invoked by sub_4A4900.
    // CALL: Zero-initialize local file-handle state struct v7 via ZeroInitSmallStruct (function identity 0x004A51C0). [callee:0x005668B0, function:0x004A51C0, source:raw]
    // CALL: Open audio stream for tire sound using handle argument a2 and a constant flag argument 1 via AudioStreamOpen. [callee:0x00566B20, source:raw]
    // GUARD: Early return when v7[0] is zero (init/allocation result from ZeroInitSmallStruct), returning SubCallWithConditionalFieldFree(v7). [callee:0x005668D0, source:raw]
    // CALCULATION: Map global detail level dword_7CF884 (0..3) through jump table jpt_4A5216 to LOD scale factor v6 (3.0 for 0, 2.0 for 1, 1.0 for 2, 0.0 for 3; default 0.0). [global:0x007CF884, global:0x004A5314, source:raw]
    // ASSIGNMENT: Clear 384-byte buffer v15 and initialize locals v10=0, v12=0, v13=0, v14=0, v11=1. [source:raw]
    // LOOP: Iterate data entries while ConditionalDispatchBasedOnFlag(v15, 384) returns true. [callee:0x00566CC0, source:raw]
    // GUARD: Skip mesh load when sub_5651B0(v9) returns non-zero (file-entry load/parse result). [callee:0x005651B0, source:raw]
    // CALL: Resolve name key v8 against global instance table aInstance via sub_565520(aInstance, v8, 0). [callee:0x00565520, global:0x005CD620, source:raw]
    // CALL: Load tire/wheel graphics mesh via TireWheelGraphicsMeshLoader(this, v5, v7, v8, a3, v6) using the resolved name, entry handle and LOD scale factor. [callee:0x004A4ED0, source:raw]
    // CALL: Close file handle and dispatch on flag after the loop via ConditionalFileHandleCloseWithFlagDispatch(v7). [callee:0x00566B90, source:raw]
    // RETURN: Return conditional field-free result via SubCallWithConditionalFieldFree(v7); function is called by sub_4A4900. [callee:0x005668D0, caller:0x004A4900, source:raw]

    // Conservative worker pseudocode:
    //   // semantic reconstruction, not original source
    //   ZeroInitSmallStruct(v7);
    //   AudioStreamOpen(a2, 1);
    //   if (!v7[0]) return SubCallWithConditionalFieldFree(v7);
    //   v6 = 0.0;
    //   switch (dword_7CF884) { /* detail level -> LOD scale * /
    //     case 0: v6 = 3.0; break;
    //     case 1: v6 = 2.0; break;
    //     case 2: v6 = 1.0; break;
    //     case 3: v6 = 0.0; break;
    //   }
    //   memset(v15, 0, sizeof(v15));
    //   v10 = 0; v12 = 0; v13 = 0; v14 = 0; v11 = 1;
    //   while (ConditionalDispatchBasedOnFlag(v15, 384)) {
    //     if (!sub_5651B0(v9)) {
    //       if (sub_565520(aInstance, v8, 0)) {
    //         TireWheelGraphicsMeshLoader(this, v5, v7, v8, a3, v6);
    //       }
    //     }
    //   }
    //   ConditionalFileHandleCloseWithFlagDispatch(v7);
    //   return SubCallWithConditionalFieldFree(v7);
    // UNRESOLVED: Purpose of arguments a2/a3 and register value v5 (passed as entry handle to TireWheelGraphicsMeshLoader) is unaccounted for in packet evidence.
    // UNRESOLVED: Locals v10, v11, v12, v13, v14 are initialized but never referenced in the decompiled body.
    // UNRESOLVED: Whether sub_5651B0 returning zero indicates a successful parse (negative logic gate) is ambiguous from decompiler text.
    // UNRESOLVED: Exact meaning of the detail-level selector dword_7CF884 (e.g. threshold for pitcrew vs. car meshes) is not in packet evidence.
}
