// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A3820
// Canonical corpus name: PhysicsChannelProcessingWithLocals
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsChannelProcessingWithLocals_004a3820.c

void UnknownObject::AnimationPhaseDistributor()
{
    // Computes time-phase subdivisions from the input value *a2 (0.0, *a2-3.5999999, *a2*0.5, *a2*0.25, *a2*0.75) into a local phase array, then distributes them to per-element sub-structures via RangeProportionInitializer. The outer loop walks this[3] elements starting at this[4] with a 120-byte stride; each element holds a 28-byte-stride sub-element array whose count lives at element+112. For each sub-element it reads a phase index at sub+24, computes target = sub[4] - sub[3] + phase[index], and calls RangeProportionInitializer(sub, phase[index], target). Returns the number of elements iterated. Prior analysis ties this to PitStopOperationTimer-driven multi-channel animation timing.
    // ASSIGNMENT: Initialize local state: v18[13] = 0.0, memset v18[15..17] to zero (12 bytes), and zero the v20/v24/v17 counters and result. [source:raw]
    // CALCULATION: Compute the offset phase value *a2 - 3.5999999 and store it into the local phase array at v18[14]. [source:raw]
    // CALCULATION: Derive proportional phases from *a2: v19 = v22 = *a2 * 0.5, v21 = *a2 * 0.25, v23 = *a2 * 0.75. [source:raw]
    // GUARD: Outer guard: only enter the element loop when the element count this[3] (this+0xC) is greater than zero. [field:this:0x0000000C, source:raw]
    // LOOP: Outer loop over this[3] elements, base pointer this[4] (this+0x10), advancing by a 120-byte stride each iteration. [field:this:0x00000010, source:raw]
    // GUARD: Inner guard: only process sub-elements when the per-element count at element+112 is greater than zero. [source:raw]
    // LOOP: Inner loop over the 28-byte-stride sub-elements of each 120-byte element, bounded by the count at element+112. [source:raw]
    // CALCULATION: For each sub-element: read the phase index v13 from sub+24, then compute target v16 = sub[4] - sub[3] + phase[v13]. [source:raw]
    // CALL: Call RangeProportionInitializer(sub, phase[v13], v16) to assign the range/proportion values onto the sub-element for animation tweening. [callee:0x004A1FD0, source:raw]
    // RETURN: Return result, the number of elements iterated (incremented once per outer-loop iteration). [source:raw, function:0x004A3820]

    // Conservative worker pseudocode:
    //   int sub_4A3820(_DWORD *this, float *a2) {
    //     float phase[18];
    //     double v2 = *a2 - 3.5999999;
    //     phase[13] = 0.0;
    //     phase[14] = v2;
    //     memset(&phase[15], 0, 12);
    //     float half = *a2 * 0.5;
    //     float quarter = *a2 * 0.25;
    //     float threeQuarter = *a2 * 0.75;
    //     int count = this[3];
    //     int result = 0;
    //     int elemIdx = 0;
    //     if (count > 0) {
    //       int off = 0;
    //       do {
    //         char *elem = (char *)this[4] + off;
    //         int subCount = *(int *)(elem + 112);
    //         int n = 0;
    //         if (subCount > 0) {
    //           int so = 0;
    //           do {
    //             float *fs = (float *)(elem + so);
    //             int idx = *(int *)(*(int *)(elem + so + 116) + so + 24);
    //             float target = fs[4] - fs[3] + phase[idx];
    //             RangeProportionInitializer(fs, phase[idx], target);
    //             ++n;
    //             so += 28;
    //           } while (n < *(int *)(elem + 112));
    //         }
    //         result = elemIdx + 1;
    //         ++elemIdx;
    //         off += 120;
    //       } while (elemIdx < count);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The 28-byte sub-element layout (indices 3/4 as float pair, phase index at +24, sub-array pointer at +116) is read via raw offsets and not defined in this function.
    // UNRESOLVED: Four read-only globals (flt_59E450, flt_59E7F8, flt_59E7FC, flt_5ACAF4) are flagged by packet facts but appear nowhere in the raw decompiled source; prior analysis labels them DegreesToRadians, AntiRollMixingFactor, BumpDampingConstant and PathLengthThreshold, all unverifiable from this packet.
    // UNRESOLVED: The semantics of the 3.5999999 offset and the 0.25/0.5/0.75 proportions depend on the caller's animation model (prior analysis: PitStopOperationTimer).
    // UNRESOLVED: The exact purpose of the values read at sub+24 and written through RangeProportionInitializer is not independently evidenced here.
}
