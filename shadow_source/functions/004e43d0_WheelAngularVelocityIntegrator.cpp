// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E43D0
// Canonical corpus name: sub_4E43D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4E43D0_004e43d0.c

void UnknownObject::WheelAngularVelocityIntegrator()
{
    // Per-frame integrator over a float state vector (this), called from sub_4E5AE0. Accumulates rotation this+0x10 from a base value this+0x60 plus a bias this+0x34, then drives the velocity state this+0x30 toward a directional target built from this+0x54 and this+0x58 with gain this+0x6C and convergence factor this+0x70, folding the result into this+0x24. A sign-aware convergence test either steps or predicts-and-resets the state in one frame. If the magnitude of this+0x24 exceeds the 50.265484 threshold, it invokes InterruptDispatch on the value. The wheel/physics attribution comes from the existing analysis and is not independently confirmed.
    // ASSIGNMENT: Accumulate rotation: set this+0x10 to this+0x60 + this+0x34 (base rotation plus bias offset); runs unconditionally at entry. [function:0x004E43D0, field:this:0x00000010, field:this:0x00000060, field:this:0x00000034, caller:0x004E5AE0, source:raw]
    // CALCULATION: Build the directional delta: this+0x54 +/- this+0x58, with the sign chosen by whether this+0x30 is <= 0.0, then scale it by the gain this+0x6C. [field:this:0x00000054, field:this:0x00000058, field:this:0x00000030, field:this:0x0000006C, source:raw]
    // GUARD: When the scaled delta is exactly zero (zero threshold, backed by flt_59E440), take the simple-integration path with a zero step. [field:this:0x0000006C, global:0x0059E440, source:raw]
    // GUARD: Sign-aware convergence test: using the FPU flag pair from the comparison, check whether this+0x30 is on the near side of -step (this+0x30 < 0.0 || -step <= this+0x30, or the mirrored form); passing the test takes the simple-integration path, otherwise the predict-and-reset path runs. [field:this:0x00000030, field:this:0x0000006C, source:raw]
    // CALCULATION: Simple integration: this+0x24 += this+0x70 * this+0x30, then this+0x30 += step. [field:this:0x00000024, field:this:0x00000030, field:this:0x00000070, source:raw]
    // CALCULATION: Predict-and-reset path: compute the crossing fraction -(this+0x30 / delta), fold fraction * old this+0x30 into this+0x24, snap this+0x30 to 0.0, then recompute the residual gain this+0x70 - fraction. [field:this:0x00000024, field:this:0x00000030, field:this:0x00000070, source:raw]
    // CALCULATION: When |this+0x54| exceeds this+0x58, re-apply a scaled approach velocity: this+0x30 = residual_gain * this+0x6C * (this+0x54 +/- this+0x58, sign selected by this+0x54). [field:this:0x00000030, field:this:0x00000054, field:this:0x00000058, field:this:0x0000006C, field:this:0x00000070, source:raw]
    // GUARD: If |this+0x24| exceeds the 50.265484 clamp threshold (PhysicsMinDeltaThreshold/PositionClampMax, backed by dbl_59ED28 and flt_5AD180), invoke InterruptDispatch with the accumulated value and write it back to this+0x24. [field:this:0x00000024, callee:0x0058957A, global:0x0059ED28, global:0x005AD180, source:raw]

    // Conservative worker pseudocode:
    //   void WheelAngularVelocityIntegrator(float* this) {
    //     this[4] = this[24] + this[13];
    //     double delta = (this[12] <= 0.0f) ? (this[22] + this[21]) : (this[21] - this[22]);
    //     delta *= this[27];
    //     float step;
    //     if (delta == 0.0) {
    //       step = 0.0;
    //     } else {
    //       step = delta * this[28];
    //       if (sign_converged(this[12], step)) { /* near side of -step: integrate * /
    //         this[9] = this[28] * this[12] + this[9];
    //         this[12] = step + this[12];
    //         goto done;
    //       }
    //       // predict crossing and reset
    //       double t = -(this[12] / delta);
    //       this[9] = t * this[12] + this[9];  // uses pre-reset this[12]
    //       this[12] = 0.0;
    //       double gain = this[28] - t;
    //       if (fabs(this[21]) > this[22])
    //         this[12] = gain * this[27] * ((this[21] <= 0.0f) ? (this[22] + this[21]) : (this[21] - this[22]));
    //       goto done;
    //     }
    //     this[9] = this[28] * this[12] + this[9];
    //     this[12] = step + this[12];
    //   done:
    //     if (fabs(this[9]) > 50.265484f)
    //       InterruptDispatch(this[9]);
    //   }
    // UNRESOLVED: The 'wheel' attribution is DERIVED from existing analysis (caller sub_4E5AE0 vehicle context); the owner object type for this float state vector is unconfirmed, so it is left UnknownObject.
    // UNRESOLVED: Legacy ABI label 'Unidentified_Logic_4e43d0' provides no identity information.
    // UNRESOLVED: The exact physical meaning of the this+0x30 state, the this+0x54/0x58 bounds, and the 50.265484 threshold depends on the caller's vehicle model and is not determined here.
    // UNRESOLVED: The FPU flag-pair comparison (v7|v8) that selects the sign-aware branch is a compiler artifact of the double comparison, not a named source-level guard.
}
