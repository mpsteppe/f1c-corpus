// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BEA10
// Canonical corpus name: RandomVariationScaler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RandomVariationScaler_004bea10.c

void UnknownObject::RandomVariationScaler()
{
    // Computes a random performance-variation scaler for an AI vehicle using two LCG random draws and applies it to the input value a4. Reads the session-type discriminator at a1 + 864; when it equals 7 (qualifying) the skill/reference value is taken from *(a3 + 17604), otherwise the object base is reloaded from *(a3 + 17600) and reused. Builds v8 = (RandLCGRandomNumberGenerator(a1) % 40) * 0.01 - 0.01 + 1.0 - skill, clamps v8 into [0,1], feeds it to sub_5881F0, draws a second random factor v5 = (RandLCGRandomNumberGenerator(v4) % 50) * 0.01 + 0.5 capped at 1.0, and returns 0.25 * a4 * (v5 * v8) - 0.25 + a4.
    // GUARD: Guard: if *(a1 + 864) == 7 (qualifying session), take the skill value v7 from *(a3 + 17604); otherwise reload a1 = *(a3 + 17600) and use it as v7. [field:this:0x00000360, guard:0, source:raw]
    // ASSIGNMENT: Else branch: a1 = *(a3 + 17600) (race/skill object pointer) and v7 = a1, so the LCG seed and the skill reference both come from the reloaded object. [source:raw]
    // CALCULATION: Compute the first variation factor v8 = (RandLCGRandomNumberGenerator(a1) % 40) * 0.0099999998 - 0.0099999998 + 1.0 - (float)v7. [callee:0x005884ED, source:raw]
    // CALCULATION: Clamp v8 into [0,1]: below 0 forces 0.0, above 1.0 forces 1.0. [source:raw]
    // CALL: Feed the clamped variation factor into sub_5881F0(v8) to register it downstream. [callee:0x005881F0, source:raw]
    // CALCULATION: Draw a second random factor v5 = (RandLCGRandomNumberGenerator(v4) % 50) * 0.0099999998 + 0.5, capped at 1.0. [callee:0x005884ED, source:raw]
    // RETURN: Return 0.25 * a4 * (v5 * v8) - 0.25 + a4, i.e. a4 scaled by a random variation factor. [function:0x004BEA10, source:raw]
    // CALL: Invoked from EngineFailureCheck (0x004BEC55) and AIBehaviorInitialization (0x004BF0A0), i.e. AI performance/behavior setup paths. [caller:0x004BEC55, caller:0x004BF0A0]

    // Conservative worker pseudocode:
    //   double RandomVariationScaler(int a1, int a2, int a3, float a4) {
    //     int v7;
    //     if (*(int *)(a1 + 864) == 7) {
    //       v7 = *(int *)(a3 + 17604);
    //     } else {
    //       a1 = *(int *)(a3 + 17600);
    //       v7 = a1;
    //     }
    //     float v8 = (float)(RandLCGRandomNumberGenerator(a1) % 40) * 0.01f - 0.01f + 1.0f - (float)v7;
    //     v8 = v8 < 0.0f ? 0.0f : (v8 > 1.0f ? 1.0f : v8);
    //     sub_5881F0(v8);
    //     double v5 = (double)(RandLCGRandomNumberGenerator(v4) % 50) * 0.01f + 0.5f;
    //     if (v5 > 1.0) v5 = 1.0;
    //     return 0.25 * a4 * (v5 * v8) - 0.25 + a4;
    //   }
    // UNRESOLVED: flt_59E43C, flt_59E440, flt_59E444, flt_59E450, flt_59E7F8, flt_5ACDB4 and dbl_5ACDD0 are listed in the deterministic global facts but none appear in the decompiled body; likely constant-pool float/double literals backing the 0.0099999998 / 0.5 / 0.25 constants used in the two LCG scalings.
    // UNRESOLVED: The second LCG call uses register v4 that the decompiler shows as uninitialized; it is presumably the caller-provided this/ecx preserved across sub_5881F0.
    // UNRESOLVED: The int-to-float reinterpretation of v7 (*(float *)&v7) makes the qualifying (17604) path treat the value as a float while the race (17600) path treats the pointer as the float seed; exact semantics of +17600/+17604 are DERIVED from the qualifying/race split in the existing analysis.
}
