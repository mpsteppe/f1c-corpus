// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E51A0
// Canonical corpus name: sub_4E51A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4E51A0_004e51a0.c

void UnknownObject::DistributeAntiRollBarForces()
{
    // Per-frame wheel axle damping update: clears the four per-wheel force accumulators, handles the not-moving idle path (reset travel accumulator, clamp normalized wheel travel, optionally fire HUD element 39), recomputes axle damping outputs from the damper scale factor, interpolates a damper velocity from a 8-byte-strided lookup table, combines it with the front/rear axle force terms, and distributes the resulting anti-roll force across one wheel pair or all four wheels depending on the stored distribution mode. Called each physics tick by PhysicsIntegrationStateMachine.
    // ASSIGNMENT: Snapshot normalized wheel travel (0x3994) then clear the four wheel-force accumulators 0x35D4, 0x36CC, 0x37C4, 0x38BC to zero. [field:this:0x00003994, field:this:0x000035D4, field:this:0x000036CC, field:this:0x000037C4, field:this:0x000038BC]
    // GUARD: Idle path guard: only when the snapshot of wheel travel is exactly 0.0 is the damper scale reset and the travel accumulator adjusted. [field:this:0x00003994]
    // ASSIGNMENT: Reset the damper scale factor 0x3578 to 1065353216 (1.0f) during the idle path. [field:this:0x00003578]
    // CALCULATION: When the travel accumulator 0x39B8 is above zero, subtract the current suspension travel 0x34A8 from it and store the result back. [field:this:0x000039B8, field:this:0x000034A8]
    // GUARD: If the accumulator crossed below threshold 0x39C4 (previous value above it) while wheel travel 0x3994 is below 0x399C, notify HUD element 39 via HUDElementConfig(39, 2, 1.0, 1.0). [field:this:0x000039B8, field:this:0x000039C4, field:this:0x00003994, field:this:0x0000399C, callee:0x004F87C0]
    // ASSIGNMENT: If the accumulator 0x39B8 reaches zero while wheel travel 0x3994 is below 0x399C, clamp normalized wheel travel up to 0x399C. [field:this:0x000039B8, field:this:0x00003994, field:this:0x0000399C]
    // CALCULATION: Compute damping term one: 0x3A30 * scale(0x3578) + 0x3A34 and store to both front axle outputs 0x35D8 and 0x36D0. [field:this:0x00003A30, field:this:0x00003578, field:this:0x00003A34, field:this:0x000035D8, field:this:0x000036D0]
    // CALCULATION: Compute damping term two: 0x3A44 * scale(0x3578) + 0x3A48 and store to both rear axle outputs 0x37C8 and 0x38C0. [field:this:0x00003A44, field:this:0x00003578, field:this:0x00003A48, field:this:0x000037C8, field:this:0x000038C0]
    // GUARD: When suspension stiffness field 0x3978 is not above zero, zero the leading force term 0x3570. [field:this:0x00003978, field:this:0x00003570]
    // CALCULATION: Scale wheel travel 0x3994 by 0.03125, hand the scaled value to sub_5895A2, and use it as an index into the 8-byte-strided damper lookup table whose pointer lives at 0x39A4; linearly interpolate between adjacent entries and store the two interpolated results at 0x39A8 and 0x39AC. [field:this:0x00003994, callee:0x005895A2, field:this:0x000039A4, field:this:0x000039A8, field:this:0x000039AC]
    // CALCULATION: Combine the interpolated damped velocity 0x39AC with the leading force term 0x3570 and the baseline 0x39A8, storing the resulting force at 0x39A0. [field:this:0x000039AC, field:this:0x00003570, field:this:0x000039A8, field:this:0x000039A0]
    // GUARD: Distribution guard: only when pointer/flag 0x39F0 is non-zero and wheel travel 0x3994 is above zero is the anti-roll force computed. A comparison of field 0x3964 against 0x3994 selects either the direct force path or the sign-driven zero-force path; the effective force is the negated product of 0x39A0 and factor 0x39C8. [field:this:0x000039F0, field:this:0x00003994, field:this:0x00003964, field:this:0x000039A0, field:this:0x000039C8]
    // CALCULATION: Distribution mode select on 0x39B4: mode 0 stores half the force into the rear pair 0x37C4 and 0x38BC; mode 1 loops four times writing a quarter of the force into all four accumulators 0x35D4, 0x36CC, 0x37C4, 0x38BC using the stride; mode 2 stores half into the front pair 0x35D4 and 0x36CC. [field:this:0x000039B4, field:this:0x000037C4, field:this:0x000038BC, field:this:0x000035D4, field:this:0x000036CC]

    // Conservative worker pseudocode:
    //   void sub_4E51A0(int this) {
    //     float travel = *f(this+0x3994);
    //     *f(this+0x35D4)=0; *f(this+0x36CC)=0; *f(this+0x37C4)=0; *f(this+0x38BC)=0;
    //     if (travel == 0.0f) {
    //       *f(this+0x3578) = 1.0f;
    //       if (*f(this+0x39B8) > 0.0f) {
    //         *f(this+0x39B8) -= *f(this+0x34A8);
    //         if (new <= *f(this+0x39C4) && old > *f(this+0x39C4) && travel < *f(this+0x399C))
    //           HUDElementConfig(39, 2, 1.0f, 1.0f);
    //         if (*f(this+0x39B8) <= 0.0f && travel < *f(this+0x399C)) *f(this+0x3994)=*f(this+0x399C);
    //       }
    //     }
    //     *f(this+0x35D8)=*f(this+0x36D0)=*f(this+0x3A30)*scale+*f(this+0x3A34);
    //     *f(this+0x37C8)=*f(this+0x38C0)=*f(this+0x3A44)*scale+*f(this+0x3A48);
    //     if (*f(this+0x3978) <= 0.0f) *f(this+0x3570)=0.0f;
    //     /* interpolate damper velocity from table at this+0x39A4, then distribute by mode 0x39B4 * /
    //   }
    // UNRESOLVED: The four read-only globals flt_59E440, flt_59E450, flt_59E7F8, flt_59ED18 are reported as referenced but do not appear in the reconstructed body; their exact role is unknown.
    // UNRESOLVED: Semantics of HUDElementConfig element 39 (call parameters 2, 1.0, 1.0) are not established from this function alone.
    // UNRESOLVED: The comparison of 0x3964 against 0x3994 feeding uninitialized status-flag state appears to be a degenerate/legacy branch; its intended condition is unclear.
    // UNRESOLVED: Distribution mode values of 0x39B4 are only partially observable here; the rear/front pair meaning is inferred from which accumulators each branch writes.
}
