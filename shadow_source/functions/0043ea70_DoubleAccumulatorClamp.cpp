// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0043EA70
// Canonical corpus name: DoubleAccumulatorClamp
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoubleAccumulatorClamp_0043ea70.c

void UnknownObject::DoubleAccumulatorClamp()
{
    // Accumulates a2 scaled by 0.37 into the accumulator at this+0x1BC0, then clamps the accumulator into the range [this+0x1C30, this+0x1C30 + 0.4]: values above the upper bound are capped, values below the reference are reset to the reference.
    // CALCULATION: Accumulate the input into the accumulator: this+0x1BC0 += a2 * 0.37. [field:this:0x00001BC0, source:raw]
    // CALCULATION: Compute the clamp bounds from the reference at this+0x1C30: v2 = this+0x1C30 (lower bound) and v3 = this+0x1C30 + 0.4 (upper bound). [field:this:0x00001C30, source:raw]
    // GUARD: When the accumulator this+0x1BC0 is below the reference this+0x1C30, reset the accumulator to this+0x1C30. [field:this:0x00001BC0, field:this:0x00001C30, source:raw]
    // GUARD: When the accumulator this+0x1BC0 exceeds the upper bound this+0x1C30 + 0.4, cap the accumulator at this+0x1C30 + 0.4. [field:this:0x00001BC0, field:this:0x00001C30, source:raw]

    // Conservative worker pseudocode:
    //   void DoubleAccumulatorClamp(double* this, double a2) {
    //     this[0x1BC0 / 8] += a2 * 0.37;
    //     double ref = this[0x1C30 / 8];
    //     if (ref <= this[0x1BC0 / 8]) {
    //       if (this[0x1BC0 / 8] > ref + 0.4) this[0x1BC0 / 8] = ref + 0.4;
    //     } else {
    //       this[0x1BC0 / 8] = ref;
    //     }
    //   }
    // UNRESOLVED: Globals dbl_59EC80 and dbl_59EC88 are listed as accessed by this function but do not appear in the raw source; their role (e.g. sources of the folded 0.37/0.4 constants) is unknown.
    // UNRESOLVED: The semantics of the accumulator (this+0x1BC0) and reference (this+0x1C30) in the vehicle physics context is DERIVED; the packet does not name them.
}
