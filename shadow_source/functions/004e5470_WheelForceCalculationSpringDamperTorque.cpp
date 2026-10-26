// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E5470
// Canonical corpus name: WheelForceCalculationSpringDamperTorque
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WheelForceCalculationSpringDamperTorque_004e5470.c

void UnknownObject::WheelForceCalculationSpringDamperTorque()
{
    // Per-frame suspension force/torque computation over all 4 wheels (stride 62 floats). Transforms per-wheel vectors through the wheel-space rotation matrix (this:0x34B0..0x34D0) plus the world-space position offset (this:0x34D4..0x34DC), computes steer cross products from the fields at float indices 3390..3395, derives cos/sin of the product this[3672] * this[3421] and stores them in several slots (this:0x363C/0x3640/0x3734/0x3738, plus the raw angle in this:0x35A8/0x36A0). Runs TireContactForceComputation and WheelSpringDamperForceAndSteering per wheel, applies a body-roll torque redistribution gated on this:0x34C0 > 0.69999999, damps per-wheel values, and accumulates forces/torques into this:0x354C..0x3560 which are then distributed back into per-wheel slots. Returns a pointer into the wheel array.
    // LOOP: Per-wheel loop (4 iterations, stride 62 floats): transform the wheel-space vector v4[1]/v4[22]/v4[3] (offsets this:0x358C, this:0x35E0, this:0x3594) through the rotation matrix v3 (this:0x34B0..0x34D0), then add the world-space offset v2 (this:0x34D4/0x34D8/0x34DC); write the result back into the per-wheel slot this:0x3588..0x35A0. Also compute steer cross products from the fields at float indices 3393/3394/3395 (this:0x3504/0x3508/0x350C) and float indices 3390/3391/3392 (this:0x34F8/0x34FC/0x3500) and store into this:0x3598/0x359C/0x35A0. [field:this:0x000035E0, field:this:0x000034B0, field:this:0x000034B4, field:this:0x000034B8, field:this:0x000034BC, field:this:0x000034C0, field:this:0x000034C4, field:this:0x000034C8, field:this:0x000034CC, field:this:0x000034D0, field:this:0x000034D4, field:this:0x000034D8, field:this:0x000034DC, field:this:0x000034F8, field:this:0x000034FC, field:this:0x00003500, field:this:0x00003504, field:this:0x00003508, field:this:0x0000350C, field:this:0x00003588, field:this:0x0000358C, field:this:0x00003594, field:this:0x00003598, field:this:0x0000359C, field:this:0x000035A0, function:0x004E5470, source:raw]
    // CALCULATION: v10 = this[3672] * this[3421] (offsets this:0x3960 * this:0x3574); store to this:0x35A8 (float 3434) and this:0x36A0 (float 3496); cos(v10) and sin(v10) are stored to this:0x363C/0x3640 (floats 3471/3472) and to this:0x3734/0x3738 (floats 3533/3534). [field:this:0x00003960, field:this:0x00003574, field:this:0x000035A8, field:this:0x000036A0, field:this:0x0000363C, field:this:0x00003640, field:this:0x00003734, field:this:0x00003738, function:0x004E5470, source:raw]
    // CALL: EmptyStubWithFlagCheck(2, 0); flag-gated stub call before the tire-contact pass. [callee:0x0053AC70, function:0x004E5470, source:raw]
    // LOOP: Per-wheel loop (4 iterations, stride 62 floats): TireContactForceComputation(v12 = this + float index 3424, v3, v2) computes tire contact forces from the wheel-space matrix (this:0x34B0) and world offset (this:0x34D4). [callee:0x004E3AA0, field:this:0x000034B0, field:this:0x000034D4, function:0x004E5470, source:raw]
    // CALL: EmptyStubWithFlagCheck(1, 0); flag-gated stub call after the tire-contact pass. [callee:0x0053AC70, function:0x004E5470, source:raw]
    // GUARD: If this[3376] > 0.69999999 (field this:0x34C0): v13 = (this[3437] - this[3499] + this[3561] - this[3623]) * this[3677], i.e. (this:0x35B4 - this:0x36AC + this:0x37A4 - this:0x389C) * this:0x3974; redistribute: this:0x35C4 += v13, this:0x36BC -= v13, this:0x37B4 += v13, this:0x38AC -= v13. [field:this:0x000034C0, field:this:0x000035B4, field:this:0x000036AC, field:this:0x000037A4, field:this:0x0000389C, field:this:0x00003974, field:this:0x000035C4, field:this:0x000036BC, field:this:0x000037B4, field:this:0x000038AC, function:0x004E5470, source:raw]
    // LOOP: Per-wheel loop (4 iterations, stride 62 floats) over this:0x35C4 (float 3441): if the value v14[12] (this:0x35F4) is negative, damp it — v16 = (v14[12] + 0.050000001) * 20.0 * *(v14 - 2), else v16 = *(v14 - 2); then *v14 = v16 * v14[15] (this:0x3600) + *v14; if *v14 < 0, *v14 *= 0.5. [field:this:0x000035C4, field:this:0x000035F4, field:this:0x00003600, function:0x004E5470, source:raw]
    // LOOP: Per-wheel loop (4 iterations, stride 62 floats): WheelSpringDamperForceAndSteering(v17 - 56, v3) computes spring/damper force and steering for the wheel (v17 starts at this + float index 3480, v17 - 56 = this + float index 3424); accumulate into this:0x354C (float 3411) and the cross-product torque terms into this:0x3550/0x3554/0x3558/0x355C/0x3560 (floats 3412-3416). [callee:0x004E3D00, field:this:0x000034B0, field:this:0x0000354C, field:this:0x00003550, field:this:0x00003554, field:this:0x00003558, field:this:0x0000355C, field:this:0x00003560, function:0x004E5470, source:raw]
    // LOOP: Per-wheel loop (4 iterations, stride 62 floats): distribute the accumulated torque (this:0x3550, this:0x3558, this:0x3560) into per-wheel slots through the weighting array at this + float index 3458; writes the scaled combination into each wheel's slot. [field:this:0x00003550, field:this:0x00003558, field:this:0x00003560, function:0x004E5470, source:raw]
    // LOOP: Per-wheel loop (4 iterations, stride 62 floats, result base = this + float index 3429): read v28 = result[12] (this:0x35C4); add v28 scaled force terms into this:0x354C/0x3550/0x3554 (floats 3411-3413) and cross-product torque terms into this:0x3558/0x355C/0x3560 (floats 3414-3416). [field:this:0x000035C4, field:this:0x0000354C, field:this:0x00003550, field:this:0x00003554, field:this:0x00003558, field:this:0x0000355C, field:this:0x00003560, function:0x004E5470, source:raw]
    // RETURN: Return result = this + float index 3429 (a pointer into the per-wheel array). [function:0x004E5470, source:raw]

    // Conservative worker pseudocode:
    //   v2 = this + 3381;  /* world-space wheel offset * /
    //   v3 = this + 3372;  /* wheel-space rotation matrix * /
    //   v4 = this + 3426;
    //   do {
    //     /* rotate per-wheel vector by matrix, then add world offset * /
    //     *(v4-2) = v4[22]*v3[1] + v4[3]*v3[2] + v4[1]*v3[0] + *v2;
    //     *(v4-1) = v4[1]*v3[3] + v4[3]*v3[5] + v4[22]*v3[4] + v2[1];
    //     *v4     = v4[1]*v3[6] + v4[22]*v3[7] + v4[3]*v3[8] + v2[2];
    //     /* steer cross products * /
    //     v4[4] = (v4[3]*this[3394] - v4[22]*this[3395]) + this[3390];
    //     v4[5] = (v4[1]*this[3395] - v4[3]*this[3393]) + this[3391];
    //     v4[6] = (v4[22]*this[3393] - v4[1]*this[3394]) + this[3392];
    //     v4 += 62;
    //   } while (--v5);
    //   v10 = this[3672] * this[3421];
    //   this[3434] = this[3496] = v10;
    //   this[3471] = this[3533] = cos(v10);
    //   this[3472] = this[3534] = sin(v10);
    //   EmptyStubWithFlagCheck(2, 0);
    //   per wheel: TireContactForceComputation(this + 3424, v3, v2);
    //   EmptyStubWithFlagCheck(1, 0);
    //   if (this[3376] > 0.69999999) {
    //     v13 = (this[3437] - this[3499] + this[3561] - this[3623]) * this[3677];
    //     this[3441] += v13; this[3503] -= v13;
    //     this[3565] += v13; this[3627] -= v13;
    //   }
    //   per wheel: damp this[3441] via this[3453] / this[3456];
    //   per wheel: WheelSpringDamperForceAndSteering(this + 3424, v3); accumulate this[3411..3416];
    //   per wheel: distribute accumulated torque through this + 3458;
    //   per wheel: accumulate force/torque into this[3411..3416];
    //   return this + 3429;
    // UNRESOLVED: All seven float/double constants listed as read in the packet (flt_59E440, flt_59E448, flt_59E450, flt_59E664, flt_59E6E8, flt_59E8EC, dword_8B8F24) do not appear in the raw source; they are likely tuning constants consumed inside the called force routines, but their exact role here is unknown.
    // UNRESOLVED: Several per-wheel bases are not packet fields and are inferred from the raw code only: this + float index 3424 (TireContactForceComputation / WheelSpringDamperForceAndSteering base), this + float index 3429 (return pointer), this + float index 3458 (torque weighting array), this + float index 3480 (spring/damper loop base), and the inner per-wheel sub-offsets (e.g. *(v14 - 2), v14[15], result[12]).
    // UNRESOLVED: The magic thresholds 0.69999999, 0.050000001, 20.0, 0.5 and the cos/sin pair are preserved verbatim from the raw source; their physical units are unverified.
    // UNRESOLVED: Caller PhysicsIntegrationStateMachine (0x004E4E60) is known but was not used in any operation.
}
