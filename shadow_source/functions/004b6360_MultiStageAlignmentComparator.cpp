// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B6360
// Canonical corpus name: sub_4B6360
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B6360_004b6360.c

void UnknownObject::MultiStageAlignmentComparator()
{
    // Validates that two input data blocks (a2 and a4, plus a third block a3) are aligned and consistent. First checks header fields of *a2 (top-bit tag and reserved bit mask), then optionally compares 14 flag bits of a2[2] against a4[2] when a difficulty selector this[0x9AC] is 3 or 4. Fills comparison intermediates via ArithmeticComparison helpers, then runs a two-stage pass: stage 0 compares per-component scalar differences through a difficulty-scaled speed/velocity threshold check, stage 1 wraps per-axis angle differences and verifies them pairwise through a steering-alignment tolerance check. Returns 1 when every stage passes, 0 on any failure.
    // GUARD: Validate header word *a2: its top three bits must equal 1 (value >> 29 != 1 returns 0). [source:raw]
    // GUARD: Validate reserved bits 18..23 of *a2: a non-zero (*a2 & 0xFC0000) returns 0. [source:raw]
    // CALCULATION: Read difficulty selector this[619] (byte offset 0x9AC); when it is 3 or 4 enable the strict flag-comparison stage. [field:this:0x000009AC, source:raw]
    // GUARD: When the strict stage is active, compare 14 bits of a2[2] against a4[2] via BitTest; any mismatch returns 0. [callee:0x004B2AD0, source:raw]
    // CALL: Populate comparison intermediates: ArithmeticComparison_3a90 on this+734 with a2, and on this+626 with a4. [callee:0x004B3A90, source:raw]
    // CALL: ArithmeticComparison_2420 on this+736 (output vector v42, scalar &v34) and on this+628 (output vector v39, scalar &v31). [callee:0x004B2420, source:raw]
    // CALL: Query playback state via AudioSamplePlaybackWithPitchModulationAndStereoP using the float at a3+4, storing its result into &v43. [callee:0x00500210, source:raw]
    // CALL: ArithmeticComparison_2420 on a3+8 (output vector v41, scalar &v28) and on local v44 (output vector v40, scalar &v25). [callee:0x004B2420, source:raw]
    // LOOP: Two-iteration outer loop over the two alignment stages (scalar/speed comparison first, steering-angle comparison second). [source:raw]
    // CALL: Stage 0: compare per-component differences (v39-v42 against v40-v41, doubling component index 1) through LapSpeedComparisonWithSwitchSelectableThresholds; a failed comparison aborts with 0. [callee:0x004B66E0, source:raw]
    // CALCULATION: Stage 1: compute per-axis angular differences between the stored scalars (|v34-v31|, |v25-v28|, |v35-v32|, |v26-v29|, |v36-v33|, |v27-v30|) and wrap any value above pi back into the valid angular range. [source:raw]
    // GUARD: Stage 1: verify each wrapped angular-difference pair through SteeringAlignmentToleranceCheck; any failure returns 0. [callee:0x004B67D0, source:raw]
    // RETURN: Return 1 when all stages and guards pass, otherwise return 0. [source:raw]

    // Conservative worker pseudocode:
    //   char MultiStageAlignmentComparator(int this, int* a2, int a3, int* a4) {
    //     if ((*a2 >> 29) != 1) return 0;
    //     if ((*a2 & 0xFC0000) != 0) return 0;
    //     int diff = this[619];
    //     if (diff >= 3 && diff <= 4) {
    //       for (int b = 0; b < 14; ++b)
    //         if (BitTest(a2 + 2, b) != BitTest(a4 + 2, b)) return 0;
    //     }
    //     ArithmeticComparison_3a90(this + 734, a2);
    //     ArithmeticComparison_3a90(this + 626, a4);
    //     ArithmeticComparison_2420(this + 736, v42, &v34);
    //     ArithmeticComparison_2420(this + 628, v39, &v31);
    //     AudioSamplePlaybackWithPitchModulationAndStereoP(*(float*)(a3 + 4), &v43);
    //     ArithmeticComparison_2420(a3 + 8, v41, &v28);
    //     ArithmeticComparison_2420(v44, v40, &v25);
    //     int iter = 0;
    //     do {
    //       if (iter) {
    //         if (!SteeringAlignmentToleranceCheck(wrap(|v25 - v28|), wrap(|v34 - v31|))) return 0;
    //         if (!SteeringAlignmentToleranceCheck(wrap(|v26 - v29|), wrap(|v35 - v32|))) return 0;
    //         if (!SteeringAlignmentToleranceCheck(wrap(|v27 - v30|), wrap(|v36 - v33|))) return 0;
    //       } else {
    //         int i = 0;
    //         do {
    //           float d = v40[i] - v41[i];
    //           float s = v39[i] - v42[i];
    //           if (i == 1) d += d;
    //           if (!LapSpeedComparisonWithSwitchSelectableThresholds(d, s)) return 0;
    //         } while (++i < 3);
    //       }
    //     } while (++iter < 2);
    //     return 1;
    //   }
    // UNRESOLVED: Global jump table jpt_4B6380 and double dbl_59E890 are recorded as read but do not appear in the decompiled body; they likely back the difficulty-scaled threshold selection and the angle tolerance.
    // UNRESOLVED: Semantics of the a2/a4 header words and the exact meaning of the 14-bit flag comparison are unknown.
    // UNRESOLVED: The AudioSamplePlaybackWithPitchModulationAndStereoP call is likely a misattributed generic helper name; its actual role at this site is unclear.
    // UNRESOLVED: this sub-object offsets this+734, this+736, this+626 and this+628 are dword-indexed fields whose layout is unknown.
}
