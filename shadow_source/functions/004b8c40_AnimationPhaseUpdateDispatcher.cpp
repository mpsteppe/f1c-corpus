// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B8C40
// Canonical corpus name: sub_4B8C40
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B8C40_004b8c40.c

void UnknownObject::AnimationPhaseUpdateDispatcher()
{
    // Dispatches an animation/simulation phase update by a mode value (a2). Each mode fetches a base float via FloatGetter(this), adds or subtracts the cooling-rate global dbl_8AFE90 (with per-mode scalars 1.0, 0.083333336 or 3.3399999, or a floor clamp in mode 0), runs AngleClampWrap on the adjusted angle, writes a phase identifier (4-7) at an object+3980, and sets a scale factor (1065353216, 1056964608 or 1070973583). Modes 0/2/3/4 fall through to ShortComputation_8d70 and GuardedVirtualCall(v18); mode 1 returns ArithmeticComparison_8d60 early. Called by StateTriggerCheck (004b8ae0) and ConditionalMultiPathDispatcher (004ba180).
    // STATE_TRANSITION: Switch on LODWORD(a2) dispatches through the mode jump table global:0x004B8D8C (jpt_4B8C56), with a default that re-tests LODWORD(a2) == 1 [global:0x004B8D8C, source:raw]
    // CALCULATION: Mode 0: v19 = FloatGetter(this) - dbl_8AFE90; when a3 is clear and v19 is below the float at object+3976 it is clamped up to that floor value [callee:0x004B8790, global:0x008AFE90, source:raw]
    // CALL: AngleClampWrap clamps each mode's adjusted angle to the configured range [callee:0x004B86E0, source:raw]
    // ASSIGNMENT: Phase identifier writes: mode 0 writes 4 at object+3980, mode 1 writes 5 at object+3980, modes 2 and 3 write 6 at object+3980, mode 4 writes 7 at object+3980; all bases are uninitialized registers in the decompile [source:raw]
    // CALCULATION: Mode 1: v14 = FloatGetter(this); then returns ArithmeticComparison_8d60(&byte_8AC494) without reaching the shared tail [callee:0x004B8790, callee:0x004C8D60, global:0x008AC494, source:raw]
    // CALCULATION: Mode 2: v15 = FloatGetter(this) + dbl_8AFE90, then falls through to the shared tail [callee:0x004B8790, global:0x008AFE90, source:raw]
    // CALCULATION: Mode 3: v16 = FloatGetter(this) + dbl_8AFE90 * 0.083333336, and v18 is set to 1056964608 before the shared tail [callee:0x004B8790, global:0x008AFE90, source:raw]
    // CALCULATION: Mode 4: v17 = FloatGetter(this) + dbl_8AFE90 * 3.3399999, and v18 is set to 1070973583 before the shared tail [callee:0x004B8790, global:0x008AFE90, source:raw]
    // CALL: Shared tail (LABEL_6): ShortComputation_8d70(&byte_8AC494) runs, then GuardedVirtualCall(v18) dispatches with the mode scale factor and its result is returned [callee:0x004C8D70, callee:0x004C8DC0, global:0x008AC494, source:raw]
    // CALL: Invoked by StateTriggerCheck (004b8ae0) and ConditionalMultiPathDispatcher (004ba180) as an animation/simulation phase update dispatch [caller:0x004B8AE0, caller:0x004BA180, source:raw]

    // Conservative worker pseudocode:
    //   v18 = 1065353216;
    //   switch (LODWORD(a2)) {
    //     case 0:
    //       v19 = FloatGetter(this) - dbl_8AFE90;
    //       if (!a3 && v19 < *(float*)(v3 + 3976)) v19 = *(float*)(v3 + 3976);
    //       AngleClampWrap(v3, v19);
    //       *(int*)(v4 + 3980) = 4;
    //       break;
    //     case 1:
    //       v14 = FloatGetter(this);
    //       AngleClampWrap(v6, v14);
    //       *(int*)(v7 + 3980) = 5;
    //       return ArithmeticComparison_8d60(&byte_8AC494);
    //     case 2:
    //       v15 = FloatGetter(this) + dbl_8AFE90;
    //       AngleClampWrap(v8, v15);
    //       *(int*)(v9 + 3980) = 6;
    //       break;
    //     case 3:
    //       v16 = FloatGetter(this) + dbl_8AFE90 * 0.083333336;
    //       AngleClampWrap(v10, v16);
    //       *(int*)(v11 + 3980) = 6;
    //       v18 = 1056964608;
    //       break;
    //     case 4:
    //       v17 = FloatGetter(this) + dbl_8AFE90 * 3.3399999;
    //       AngleClampWrap(v12, v17);
    //       *(int*)(v13 + 3980) = 7;
    //       v18 = 1070973583;
    //       break;
    //     default:
    //       if (LODWORD(a2) == 1) return ArithmeticComparison_8d60(&byte_8AC494);
    //   }
    //   ShortComputation_8d70(&byte_8AC494);
    //   return GuardedVirtualCall(v18);
    // UNRESOLVED: The dword writes at object+3976 and object+3980 use uninitialized register-sourced base pointers (v3..v13), so the target object and field offsets are not established by this packet
    // UNRESOLVED: The phase identifiers (4-7) and scale factors (1065353216, 1056964608, 1070973583) are numeric literals whose semantic role is inferred from the existing analysis only
    // UNRESOLVED: The meaning of the byte_8AC494 global and the distinction between the ArithmeticComparison_8d60 and ShortComputation_8d70 paths is not documented in this function
    // UNRESOLVED: Two read-only globals flagged by packet facts (flt_5ACB58, flt_5ACD64) appear nowhere in the raw decompiled source; the skeleton fill labels them FloatConstantPair and GearRatioMultiplier, both unverifiable from this packet
}
