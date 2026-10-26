// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0043E890
// Canonical corpus name: SuspensionDamperForceAccumulation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SuspensionDamperForceAccumulation_0043e890.c

void UnknownObject::SuspensionDamperForceAccumulation()
{
    // Accumulates scaled input into two damper force accumulators at this+0x17A8 (scale 0.23) and this+0x17C0 (scale 0.18), then clamps each accumulator into the interval [reference, reference + bound] where the references come from this+0x1C08 and this+0x1C10 with bounds 0.25 and 0.2. Finally evaluates the quadratic damper curve via QuadFunctionEval using the selector field at this+0x1C00.
    // CALCULATION: Accumulate the first damper force: this[0x17A8] = a2 * 0.23 + this[0x17A8]. [field:this:0x000017A8, source:raw]
    // CALCULATION: Accumulate the second damper force: this[0x17C0] = a2 * 0.18 + this[0x17C0]. [field:this:0x000017C0, source:raw]
    // GUARD: Clamp the first accumulator into [this[0x1C08], this[0x1C08] + 0.25]: if below the reference it is raised to the reference, if above reference + 0.25 it is capped there. [field:this:0x000017A8, field:this:0x00001C08, source:raw]
    // GUARD: Clamp the second accumulator into [this[0x1C10], this[0x1C10] + 0.2]: if below the reference it is raised to the reference, if above reference + 0.2 it is capped there. [field:this:0x000017C0, field:this:0x00001C10, source:raw]
    // CALL: QuadFunctionEval(this, this[0x1C00]) evaluates the quadratic force curve using the selector/argument field at this+0x1C00. [callee:0x0043BB30, field:this:0x00001C00, source:raw]

    // Conservative worker pseudocode:
    //   void SuspensionDamperForceAccumulation(double* this, double a2) {
    //     this[757] += a2 * 0.23;
    //     this[760] += a2 * 0.18;
    //     double ref1 = this[897];
    //     if (this[757] < ref1) this[757] = ref1;
    //     else if (this[757] > ref1 + 0.25) this[757] = ref1 + 0.25;
    //     double ref2 = this[898];
    //     if (this[760] < ref2) this[760] = ref2;
    //     else if (this[760] > ref2 + 0.2) this[760] = ref2 + 0.2;
    //     QuadFunctionEval(this, this[896]);
    //   }
    // UNRESOLVED: The globals dbl_59EB28, dbl_59EB50, dbl_59EB58 and dbl_59EC78 are listed as accessed but do not appear in the raw source; the compiler may have folded them into the inline literals (0.23/0.18/0.25/0.2), or the raw source rendering omitted them.
    // UNRESOLVED: The semantic identity of the accumulated damper forces and the quadratic curve selected by the field at this+0x1C00 is not established by the packet alone.
}
