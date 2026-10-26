// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00500560
// Canonical corpus name: CollisionTestWithThreshold
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionTestWithThreshold_00500560.c

void UnknownObject::CollisionTestWithThreshold()
{
    // Threshold-guarded collision sample handler on the per-frame path: two initialization guards (FloatComparisonCheck on the object, FieldCompareConstant on field this+444) gate a threshold branch that clamps the delta to [0.001, 0.5], then interpolates audio parameters (this+8) and cross-fades the collision sample (this+440); otherwise a direct parameter interpolation is performed. The arithmetic state at this+440 is always copied into the output buffer, and a float update is applied only when the interpolation result and flag a6 are both set. Vehicle audio/collision subsystem.
    // GUARD: FloatComparisonCheck(this) returns false -> early return with undefined v7; treats the object as uninitialized. [callee:0x005001F0, source:raw]
    // GUARD: Threshold branch condition: FieldCompareConstant (sentinel/init check of field this+0x1BC) succeeds and *(float*)(this + 444) < a2. [callee:0x005001D0, field:this:0x000001BC, source:raw]
    // CALCULATION: delta = a2 - *(float*)(this + 444); clamped to the range [0.001, 0.5] (0.001 floor, 0.5 ceiling). [source:raw]
    // CALCULATION: v15 = delta + a2; the target value passed to the parameter interpolator. [source:raw]
    // CALL: AudioParameterInterpolation(v15, this + 8, scratch buffer v16, 1.0) interpolates the audio parameter state toward the threshold-adjusted target. [callee:0x004FF680, source:raw]
    // CALL: AudioSampleCrossFadeInterpolation(this, a2, this + 440, scratch buffer v16, a4) cross-fades the collision sample; result stored in v12. [callee:0x004FF8F0, source:raw]
    // CALL: Else branch: AudioParameterInterpolation(a2, this + 8, output a4, 1.0) performs the direct parameter interpolation; result stored in v12. [callee:0x004FF680, source:raw]
    // CALL: ArithmeticComparison_3a90((_DWORD*)(this + 440), a4) copies/compares the arithmetic state between the source field and the output buffer in both branches. [callee:0x004B3A90, source:raw]
    // GUARD: When the interpolation result v13 is non-zero and flag a6 is set, PhysicsFloatUpdateWithCompare(a4, a5) updates the float value in the output. [callee:0x005000E0, source:raw]
    // RETURN: Return v13, the interpolation/cross-fade result byte. [source:raw]

    // Conservative worker pseudocode:
    //   if ( !FloatComparisonCheck(this) )
    //       return <undefined>;
    //   if ( FieldCompareConstant(this) && *(float *)(this + 444) < a2 ) {
    //       float delta = a2 - *(float *)(this + 444);
    //       if ( delta >= 0.001f ) { if ( delta > 0.5f ) delta = 0.5f; } else { delta = 0.001f; }
    //       AudioParameterInterpolation(delta + a2, this + 8, scratch, 1.0f);
    //       result = AudioSampleCrossFadeInterpolation(this, a2, this + 440, scratch, a4);
    //   } else {
    //       result = AudioParameterInterpolation(a2, this + 8, a4, 1.0f);
    //   }
    //   ArithmeticComparison_3a90((_DWORD *)(this + 440), a4);
    //   if ( result && a6 )
    //       PhysicsFloatUpdateWithCompare(a4, a5);
    //   return result;
    // UNRESOLVED: The exact struct behind this is unknown; fields at this+444 (sentinel-checked), this+440 (sample/arithmetic state) and this+8 (audio parameter state) have only DERIVED roles.
    // UNRESOLVED: Packet-attributed global reads flt_59E450 (0x0059E450) and flt_59E600 (0x0059E600) are not visible in the decompiled source text; their use at this site is unresolved.
    // UNRESOLVED: Parameter a2 is consumed as the bit pattern of a float (*(float *)&a2); the register holding a3 is never referenced in the body.
    // UNRESOLVED: The early-return value v7 is undefined when FloatComparisonCheck fails; the caller only consumes the result when the guards pass.
    // UNRESOLVED: Packet lists one caller, UtilityFunction_3d50 (0x00463D50); its calling convention and semantics are not independently verified here.
}
