// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00409970
// Canonical corpus name: ConditionalRenderPipelineDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalRenderPipelineDispatch_00409970.c

void UnknownObject::ConditionalRenderPipelineDispatch()
{
    // Conditional camera/render pipeline setup. When this[2] (offset 0x8) is non-null, converts two camera scale globals from degrees to radians (factor 0.01745433), applies them via sub_542050, sets the camera center via sub_541CA0(dword_7CF680), stores (sub_4099E0, 0) as a callback pair via PointerStorePair2, sets a float to 0.5 via ConditionalFloatSetter, and returns the result of Bit5FlagSetReset(dword_7CF6EC). On guard failure the decompiled return value is the uninitialized local result.
    // GUARD: Guard on this[2] (offset 0x8) being non-null; the whole pipeline setup runs only then. [field:this:0x00000008, source:raw]
    // CALCULATION: Scale factor Y: v3 = flt_7CF6C8 * 0.01745433 (degrees to radians). [global:0x007CF6C8, source:raw]
    // CALCULATION: Scale factor X: v2 = flt_7CF6A4 * 0.01745433 (degrees to radians). [global:0x007CF6A4, source:raw]
    // CALL: Apply the camera rotation/scaling from the radian factors: sub_542050(v2, v3, 1). [callee:0x00542050, source:raw]
    // CALL: Set the camera center/target from dword_7CF680: sub_541CA0(dword_7CF680). [callee:0x00541CA0, global:0x007CF680, source:raw]
    // CALL: Store the pipeline callback pair: PointerStorePair2(sub_4099E0, 0). [callee:0x00542540, global:0x004099E0, source:raw]
    // CALL: Set a float parameter to 0.5 via ConditionalFloatSetter(0.5). [callee:0x00542680, source:raw]
    // RETURN: Set/reset a bit flag on the camera value and return its result: Bit5FlagSetReset(dword_7CF6EC). [callee:0x00542650, global:0x007CF6EC, source:raw]
    // RETURN: When the guard fails, return the decompiled result local, which is uninitialized at that point. [source:raw]

    // Conservative worker pseudocode:
    //   int ConditionalRenderPipelineDispatch(int* this) {
    //     if (this[2]) {
    //       float v3 = flt_7CF6C8 * 0.01745433f;
    //       float v2 = flt_7CF6A4 * 0.01745433f;
    //       sub_542050(v2, v3, 1);
    //       sub_541CA0(dword_7CF680);
    //       PointerStorePair2(sub_4099E0, 0);
    //       ConditionalFloatSetter(0.5f);
    //       return Bit5FlagSetReset(dword_7CF6EC);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Global flt_59E65C is listed in the packet globals but is not referenced by this function's raw source; its role here is unknown.
    // UNRESOLVED: The guard-fail path returns the decompiler's uninitialized result local; the actual value depends on the caller's register state.
    // UNRESOLVED: Meaning of this[2] (rearview/camera data presence) and the callback pair (sub_4099E0, 0) is owner-dependent.
    // UNRESOLVED: This function is called by sub_409890; that caller's role is out of scope here.
}
