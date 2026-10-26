// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0043E980
// Canonical corpus name: ClampedSpringIntegrator
// Owner: ClampedSpringIntegrator [DERIVED]
// Raw source: functions/ClampedSpringIntegrator_0043e980.c

void ClampedSpringIntegrator::ClampedSpringIntegrator()
{
    // Integrates two spring accumulator slots (this+0x1808 and this+0x1818) with scaled input using the rates 0.23 and 0.18, clamps each accumulator into [reference, reference+offset] (offsets 0.25 and 0.2), then computes the spring-damper force via SpringDamperCompute using a selector at this+0x1C18. Part of the vehicle suspension spring force system.
    // ASSIGNMENT: Integrate accumulator 1: this[769] (this+0x1808) = this[769] + input * 0.23 [field:this:0x00001808, source:raw]
    // ASSIGNMENT: Integrate accumulator 2: this[771] (this+0x1818) = this[771] + input * 0.18 [field:this:0x00001818, source:raw]
    // GUARD: Clamp accumulator 1 into [reference, reference+0.25]; reference = this[900] (this+0x1C20) [field:this:0x00001C20, source:raw]
    // GUARD: Clamp accumulator 2 into [reference, reference+0.2]; reference = this[901] (this+0x1C28) [field:this:0x00001C28, source:raw]
    // CALL: Compute spring-damper force: SpringDamperCompute(this, this[899] selector at this+0x1C18) (0x0043BBD0) [callee:0x0043BBD0, field:this:0x00001C18, source:raw]
    // CALCULATION: Rate and clamp constants (0.23, 0.18, 0.25, 0.2) originate from the module double constants dbl_59EB28, dbl_59EB50, dbl_59EB58 and dbl_59EC78; the per-constant pairing is DERIVED [global:0x0059EB28, global:0x0059EB50, global:0x0059EB58, global:0x0059EC78, source:raw]

    // Conservative worker pseudocode:
    //   // this[769] = this[769] + input * 0.23
    //   // this[771] = this[771] + input * 0.18
    //   // clamp this[769] into [this[900], this[900]+0.25]
    //   // clamp this[771] into [this[901], this[901]+0.2]
    //   // SpringDamperCompute(this, this[899])
    // UNRESOLVED: Exact pairing of the module double constants to the 0.23/0.18 rates and the 0.25/0.2 clamp offsets is DERIVED; the raw source shows only the inlined literals
    // UNRESOLVED: Origin and writer of the reference values at this+0x1C20 and this+0x1C28 and of the selector at this+0x1C18 lie outside this function
}
