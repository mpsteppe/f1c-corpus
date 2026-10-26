// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E5AE0
// Canonical corpus name: sub_4E5AE0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4E5AE0_004e5ae0.c

void UnknownObject::UpdateBrakeAndSuspensionDynamics()
{
    // Per-frame vehicle wheel, brake and suspension dynamics update. Rotates a timestep-scaled wheel torque direction vector into the chassis frame using the stored rotation matrix, integrates the accumulated angular-velocity and body-frame torque accumulators, transforms the torque vector through sub_567120 and adds gyroscopic torque terms, then projects body-frame torques to world space. Runs sub_4E43D0 once per wheel (four wheels, stride 62 floats), averages suspension/damper values by the brake-model selector at this+0x39B4 into this+0x3964, sets the brake torque target as the negated brake input product, and drives the brake-pressure state machine on this+0x3994 with a final clamp.
    // ASSIGNMENT: Scale the wheel torque direction vector: the magnitude at this+0x3518 times the direction components at this+0x354C/0x3550/0x3554 is written to the three-slot transform vector at this+0x3540/0x3544/0x3548. [field:this:0x00003518, field:this:0x0000354C, field:this:0x00003550, field:this:0x00003554, field:this:0x00003540, field:this:0x00003544, field:this:0x00003548, source:raw]
    // CALCULATION: Rotate the scaled vector into the chassis frame: the three result components at this+0x3534/0x3538/0x353C are each a dot product of one rotation-matrix row (this+0x34B0 .. this+0x34D0) with the transform vector. [field:this:0x00003534, field:this:0x00003538, field:this:0x0000353C, field:this:0x000034B0, field:this:0x000034B4, field:this:0x000034B8, field:this:0x000034BC, field:this:0x000034C0, field:this:0x000034C4, field:this:0x000034C8, field:this:0x000034CC, field:this:0x000034D0, source:raw]
    // CALCULATION: Integrate the angular-velocity accumulators this+0x34D4/0x34D8/0x34DC and the body-frame torque accumulators this+0x34EC/0x34F0/0x34F4 by adding the timestep this+0x34A8 times the corresponding rotated/scaled components. [field:this:0x000034D4, field:this:0x000034D8, field:this:0x000034DC, field:this:0x000034EC, field:this:0x000034F0, field:this:0x000034F4, field:this:0x000034A8, source:raw]
    // CALL: Build the dt-scaled torque vector at this+0x3504/0x3508/0x350C (products scaled by this+0x34A8), transform it through sub_567120 into the orientation result vector at this+0x34E0, then add further gyroscopic torque terms (products of this+0x3558/0x355C/0x3560/0x3564/0x3568/0x356C and this+0x3528/0x352C/0x3530 scaled by this+0x34A8) back into this+0x3504/0x3508/0x350C. [callee:0x00567120, field:this:0x00003504, field:this:0x00003508, field:this:0x0000350C, field:this:0x000034A8, field:this:0x00003528, field:this:0x0000352C, field:this:0x00003530, field:this:0x00003558, field:this:0x0000355C, field:this:0x00003560, field:this:0x00003564, field:this:0x00003568, field:this:0x0000356C, source:raw]
    // CALCULATION: Project the body-frame torques to world space: this+0x34F8/0x34FC/0x3500 = rotation-matrix rows (this+0x34B0 .. this+0x34D0) dotted with the torque accumulator this+0x34EC/0x34F0/0x34F4. [field:this:0x000034F8, field:this:0x000034FC, field:this:0x00003500, field:this:0x000034EC, field:this:0x000034F0, field:this:0x000034F4, field:this:0x000034B0, field:this:0x000034B4, field:this:0x000034B8, field:this:0x000034BC, field:this:0x000034C0, field:this:0x000034C4, field:this:0x000034C8, field:this:0x000034CC, field:this:0x000034D0, source:raw]
    // LOOP: Run sub_4E43D0 four times, once per wheel, over the per-wheel data blocks starting at this+0x3580 (13696) with stride 62 floats (0xF8 bytes). [callee:0x004E43D0, source:raw]
    // STATE_TRANSITION: Average suspension/damper values by the brake-model selector at this+0x39B4: 0 uses half the sum of this+0x3898 + this+0x37A0; 1 uses a quarter of this+0x3898 + this+0x37A0 + this+0x36A8 + this+0x35B0; 2 uses half the sum of this+0x36A8 + this+0x35B0. The selected average is written to this+0x3964. [field:this:0x000039B4, field:this:0x00003964, field:this:0x00003898, field:this:0x000037A0, field:this:0x000036A8, field:this:0x000035B0, source:raw]
    // ASSIGNMENT: Set the brake torque target this+0x3964 = -(brake input at this+0x39C8 times the averaged value this+0x3964). [field:this:0x00003964, field:this:0x000039C8, source:raw]
    // STATE_TRANSITION: Brake-pressure state machine on this+0x3994 (init 0): when this+0x3978 <= 0 or the pressure is already 0, clamp/re-zero the pressure (bias term this+0x39A0 times this+0x398C times the timestep this+0x34A8); otherwise drive the pressure from the damper/brake mode at this+0x39F0 (mode 1 additionally checks the byte flag at this+0x39EC and blends this+0x3990 toward this+0x399C with the slope at this+0x3570; mode 2 snaps to the torque target), then clamp the result into the bounds this+0x3998 .. this+0x399C. [field:this:0x00003994, field:this:0x00003978, field:this:0x000039A0, field:this:0x0000398C, field:this:0x000034A8, field:this:0x000039F0, field:this:0x000039EC, field:this:0x00003990, field:this:0x0000399C, field:this:0x00003998, field:this:0x00003570, source:raw]
    // CALL: Invoked from PhysicsIntegrationStateMachine (0x004E4E60) on the per-frame physics path. [caller:0x004E4E60, function:0x004E5AE0]
    // RETURN: Return void. [function:0x004E5AE0, source:raw]

    // Conservative worker pseudocode:
    //   // rotate dt-scaled wheel torque into chassis frame; integrate angular-velocity and torque accumulators
    //   // transform torque vector via sub_567120; add gyroscopic torque terms
    //   // project body-frame torques to world space
    //   // sub_4E43D0 per wheel (x4, stride 62 floats)
    //   // average suspension values by brake-model selector (this+0x39B4) into this+0x3964
    //   // brake torque target = -(brake input * this+0x3964)
    //   // brake-pressure state machine on this+0x3994 with final clamp [this+0x399C, this+0x3998]
    // UNRESOLVED: The three read-only globals listed by the fact table (flt_59E440, flt_59E450, flt_59E7F8) do not appear in the decompiled body; they are likely physics constants used by the sub_567120 / sub_4E43D0 helpers.
    // UNRESOLVED: sub_567120 and sub_4E43D0 are opaque callees whose bodies fall outside this function's evidence.
    // UNRESOLVED: The per-wheel data stride (this+0x3580, 62 floats per wheel) and the orientation result vector at this+0x34E0 are not part of the packet field table.
}
