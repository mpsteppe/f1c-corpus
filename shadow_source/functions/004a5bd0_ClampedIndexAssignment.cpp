// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A5BD0
// Canonical corpus name: ClampedIndexAssignment
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ClampedIndexAssignment_004a5bd0.c

void UnknownObject::ClampedIndexAssignment()
{
    // Converts a float a2 into an integer index: computes CRTFtol((a2 - base) / step + 0.5) using the reference value at this+0x58 and the step size at this+0x60, clamps the result into [0, bound-1] using the upper bound at this+0x68, stores the clamped index at this+0x6C, and returns the unclamped computed index. Called from PitStopDecisionTireCompound for array indexing.
    // CALCULATION: Compute the raw index as CRTFtol((a2 - (double)this+0x58) / (double)this+0x60 + 0.5); this+0x58 is the reference/base value and this+0x60 the step/interval size. The computation also references the constant global dbl_59E880 (0x0059E880, DERIVED name HalfStep) whose exact role is not visible in the raw source. [field:this:0x00000058, field:this:0x00000060, global:0x0059E880, source:raw]
    // CALL: CRTFtol converts the scaled double expression into an integer index. [callee:0x00587BDC, source:raw]
    // GUARD: If the computed index is >= 0, clamp it into [0, bound-1]; otherwise the result < 0 branch forces the stored value to 0. [field:this:0x00000068, field:this:0x0000006C, source:raw]
    // ASSIGNMENT: Store the clamped index into this+0x6C: when result < this+0x68 store result, otherwise store this+0x68 - 1; the result < 0 branch stores 0. [field:this:0x00000068, field:this:0x0000006C, source:raw]
    // RETURN: Return the unclamped computed index (the CRTFtol result), not the stored clamped value. [function:0x004A5BD0, source:raw]

    // Conservative worker pseudocode:
    //   int ClampedIndexAssignment(void* this, float a2) {
    //     int idx = CRTFtol(((double)a2 - *(double*)(this+0x58)) / *(double*)(this+0x60) + 0.5);
    //     if (idx >= 0)
    //       *(int*)(this+0x6C) = (idx < *(int*)(this+0x68)) ? idx : *(int*)(this+0x68) - 1;
    //     else
    //       *(int*)(this+0x6C) = 0;
    //     return idx;
    //   }
    // UNRESOLVED: The exact role of global dbl_59E880 (DERIVED name HalfStep) is not visible in the raw source, which inlines the 0.5 rounding literal.
    // UNRESOLVED: The semantics of fields this+0x58 / this+0x60 / this+0x68 (base, step, upper bound) are DERIVED from usage, not independently confirmed.
}
