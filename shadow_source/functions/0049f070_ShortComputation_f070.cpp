// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049F070
// Canonical corpus name: ShortComputation_f070
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_f070_0049f070.c

void UnknownObject::ShortComputation_f070()
{
    // Per-frame post-update dispatcher: runs mode dispatch, clamps a camera-shake float, checks booted/kicked state, runs session-mode update, updates steering-wheel animation, conditionally dispatches a resource thunk when the scoring gate dword_8AB6E4 != 2, runs the post-frame sub-handler, then gates a position/speed overlay rendering path on the byte_7CE254 flag and session-state checks.
    // CALL: ModeBasedDispatch() runs the mode-specific update dispatch. [callee:0x0049F790]
    // CALL: FloatClampWithEventDispatch(&flt_5EA4E8) clamps the camera-shake multiplier stored in flt_5EA4E8. [callee:0x004082B0, global:0x005EA4E8]
    // CALL: YouHaveBeenBootedHandler(dword_7CD25C) checks whether the player was booted/kicked from the session. [callee:0x00461D20, global:0x007CD25C]
    // CALL: sub_4D8450(&dword_8AD298) runs the session-mode-specific update. [callee:0x004D8450, global:0x008AD298]
    // CALL: SteeringWheelAnimation(&dword_7CE058) updates the steering-wheel animation state. [callee:0x0049D070, global:0x007CE058]
    // GUARD: If dword_8AB6E4 != 2, call ThunkToFUN0045b840((int *)&dword_7CD204) to dispatch a resource load. [global:0x008AB6E4, global:0x007CD204, callee:0x0045BC00]
    // CALL: sub_49F870(this) runs the post-frame sub-handler on the object. [callee:0x0049F870]
    // GUARD: If byte_7CE254 is zero, evaluate the session-state overlay path; otherwise return early with v2 holding byte_7CE254. [source:raw]
    // GUARD: If SessionStateCheckWrapper(dword_7CD25C) returns non-zero, continue to the UI overlay path. [global:0x007CD25C, source:raw]
    // GUARD: Pass if SessionStateCheck(dword_7CD25C) == 3 or sub_462380(dword_7CD25C) > 1. [global:0x007CD25C, source:raw]
    // GUARD: Select the overlay trigger value v3: if ShortComputation_36e0(dword_7CD25C) is true use dword_7CE244; else if FloatComparisonAgainstThreshold(dword_7CD25C) is true use dword_7CE248; else if CollisionThresholdCheck(dword_7CD25C) is true use dword_7CE240, otherwise return v2. [global:0x007CD25C, source:raw]
    // GUARD: If the selected trigger v3 is non-zero, run the overlay rendering block. [source:raw]
    // CALCULATION: v4 = dword_5D6D64; v5 = dword_5D6D64 / 8 (integer division). [source:raw]
    // CALL: v6 = RandomColorGenerator(150994943, -1, 0.0) generates a color for the overlay. [source:raw]
    // CALL: PositionComputationWithAlignment(dword_5D6D60 - v5 - 4, v4 / 2 - v5 / 2, 1, 0) computes the overlay draw position. [source:raw]
    // CALL: TwoFieldSetterUpdate(v5, v5) sets two fields to the computed v5 size value. [source:raw]
    // CALL: FieldSetterCall_cf20(v6) writes the generated color. [source:raw]
    // CALL: LOBYTE(v2) = ConditionalCall(0) captures the final conditional-call result. [source:raw]
    // RETURN: Return v2 (derived from byte_7CE254, SessionStateCheckWrapper, or ConditionalCall). [source:raw]

    // Conservative worker pseudocode:
    //   ModeBasedDispatch()
    //   FloatClampWithEventDispatch(&flt_5EA4E8)
    //   YouHaveBeenBootedHandler(dword_7CD25C)
    //   sub_4D8450(&dword_8AD298)
    //   SteeringWheelAnimation(&dword_7CE058)
    //   if dword_8AB6E4 != 2: ThunkToFUN0045b840(&dword_7CD204)
    //   sub_49F870(this)
    //   if byte_7CE254: return byte_7CE254
    //   if SessionStateCheckWrapper(dword_7CD25C):
    //       if SessionStateCheck(dword_7CD25C) == 3 or sub_462380(dword_7CD25C) > 1:
    //           if ShortComputation_36e0(dword_7CD25C): v3 = dword_7CE244
    //           elif FloatComparisonAgainstThreshold(dword_7CD25C): v3 = dword_7CE248
    //           else:
    //               if not CollisionThresholdCheck(dword_7CD25C): return v2
    //               v3 = dword_7CE240
    //           if v3:
    //               v4 = dword_5D6D64; v5 = v4 / 8
    //               v6 = RandomColorGenerator(150994943, -1, 0.0)
    //               PositionComputationWithAlignment(dword_5D6D60 - v5 - 4, v4/2 - v5/2, 1, 0)
    //               TwoFieldSetterUpdate(v5, v5)
    //               FieldSetterCall_cf20(v6)
    //               v2 = ConditionalCall(0)
    //   return v2
    // UNRESOLVED: The packet records only 6 of the globals present in raw source (byte_7CE254, dword_7CE240, dword_7CE244, dword_7CE248, dword_5D6D60, dword_5D6D64 have no structured evidence refs); described via source:raw only.
    // UNRESOLVED: The packet records only 7 of the callees present in raw source (SessionStateCheckWrapper, SessionStateCheck, sub_462380, ShortComputation_36e0, FloatComparisonAgainstThreshold, CollisionThresholdCheck, RandomColorGenerator, PositionComputationWithAlignment, TwoFieldSetterUpdate, FieldSetterCall_cf20, ConditionalCall have no structured evidence refs); described via source:raw only.
    // UNRESOLVED: The exact meaning of the byte_7CE254 flag and the three dword_7CE24x trigger values is not established.
    // UNRESOLVED: The overlay block is inferred to be a position/speed UI overlay from the PositionComputationWithAlignment / TwoFieldSetterUpdate calls; not confirmed.
}
