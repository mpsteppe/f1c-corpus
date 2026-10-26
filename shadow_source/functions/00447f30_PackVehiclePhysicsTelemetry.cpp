// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00447F30
// Canonical corpus name: sub_447F30
// Owner: VehiclePhysicsState [DERIVED]
// Raw source: functions/sub_447F30_00447f30.c

void VehiclePhysicsState::PackVehiclePhysicsTelemetry()
{
    // Packs a flat float telemetry array a2 from a vehicle physics state: writes world position, orientation basis, a yaw angle derived from the rotation matrix via atan2, world-frame velocity (body-frame vector rotated by the 3x3 matrix and scaled), rotation-rate unit conversions, linear-state doubles, and per-wheel suspension/tire data from a bounded four-wheel loop. Called on the frame path from DebugLogInit (0x004D5960) for external/telemetry consumption.
    // ASSIGNMENT: Write this[12] (double at this+0x60, first world position component) into a2[0]. [field:this:0x00000060, source:raw]
    // CALL: Copy three doubles (0x18 bytes) from physObj+4, where physObj is the pointer stored at this+0x15F0, into stack vector v17; propagate v17[0..2] to a2[1..3]. [field:this:0x000015F0, source:raw]
    // CALCULATION: Compute a2[4] = atan2 of two dot-product combinations over the rotation-matrix doubles read from physObj+28 through physObj+116 (physObj offsets 28, 44, 52, 68, 76, 92, 100, 108, 116); yields a heading/yaw angle. [field:this:0x000015F0, field:*(this+0x15F0):0x0000001C, field:*(this+0x15F0):0x0000002C, field:*(this+0x15F0):0x00000034, field:*(this+0x15F0):0x00000044, field:*(this+0x15F0):0x0000004C, field:*(this+0x15F0):0x0000005C, field:*(this+0x15F0):0x00000064, field:*(this+0x15F0):0x0000006C, field:*(this+0x15F0):0x00000074, source:raw]
    // CALL: Call Mat3x3MulVec with the rotation matrix at physObj+28, the source vector at physObj+308, and output vector v17, transforming the body-frame vector into world frame. [callee:0x004388D0, field:this:0x000015F0, field:*(this+0x15F0):0x0000001C, source:raw]
    // CALCULATION: Scale the rotated vector by the double at physObj+0xB4 and write world-frame velocity a2[5..7] = v17[0..2] * scale. [field:this:0x000015F0, field:*(this+0x15F0):0x000000B4, source:raw]
    // CALCULATION: Write rotation-rate channels: a2[8] = double at this+0x1C5C (byte 7260) times 9.549296585513721, and a2[9] = this[967] times the same factor (unit conversion 60/(2*pi), i.e. rotations-per-unit-time to radians). [field:this:0x00001C5C, source:raw]
    // ASSIGNMENT: Copy linear-state doubles into a2[10..15] from this offsets 0x48 (this[9]), 0x08 (this[1]), 0x50 (this[10]), 0x10 (this[2]), 0x40 (this[8]) and 0x00 (this[0]). [field:this:0x00000048, field:this:0x00000008, field:this:0x00000050, field:this:0x00000010, field:this:0x00000040, field:this:0x00000000, source:raw]
    // CALCULATION: Derive a2[16] = 1.0 - this[4] and a2[17] = (1.0 - this[3]) * (1.0 - this[4]) from doubles at this+0x18 and this+0x20. [field:this:0x00000018, field:this:0x00000020, source:raw]
    // ASSIGNMENT: Write tail channels a2[54] = (float)int at this+0x1EF0 (dword 1980), a2[55] = double at this+0x1D8C (byte 7564), a2[56] = double at this+0x1D4C (byte 7500). [field:this:0x00001EF0, field:this:0x00001D8C, field:this:0x00001D4C, source:raw]
    // LOOP: Bounded four-wheel loop: for each wheel, pointer v6 advances one double from this+0x16F0 (734 doubles in) and pointer v8 advances 1124 bytes per iteration from this+0x474 (byte 1140); each iteration writes nine floats into a2[20 + i*9 ..], including a value clamped at zero (*v6 when non-negative, else 0) and per-wheel suspension/tire floats read through the advancing v8. [field:this:0x000016F0, field:this:0x00000474, source:raw]
    // RETURN: Return the packed result word (high word copied from this; low word holds the FPU status/condition codes captured during the wheel loop). [source:raw]
    // CALL: Invoked on the frame path from DebugLogInit (0x004D5960) to populate the telemetry output buffer. [caller:0x004D5960, source:raw]

    // Conservative worker pseudocode:
    //   int sub_447F30(PhysicsState *this, float *out) {
    //     double *phys = *(double **)((char*)this + 0x15F0);
    //     out[0] = this->pos[0];
    //     double v17[3]; memcpy(v17, (char*)phys + 4, sizeof(v17));
    //     out[1] = v17[0]; out[2] = v17[1]; out[3] = v17[2];
    //     out[4] = atan2(-(m11*m22 + m02*m21 + m00*m20), -(m01*m20 + m12*m22 + m10*m21));
    //     Mat3x3MulVec((double*)((char*)phys + 28), (double*)((char*)phys + 308), v17);
    //     double velScale = *(double*)((char*)phys + 180);
    //     out[5] = v17[0]*velScale; out[6] = v17[1]*velScale; out[7] = v17[2]*velScale;
    //     out[8] = this->rateA * 9.549296585513721; out[9] = this->rateB * 9.549296585513721;
    //     out[10] = this->q; out[11] = this->b; out[12] = this->r; out[13] = this->c;
    //     out[14] = this->d; out[15] = this->a; out[16] = 1.0 - this->e; out[17] = (1.0 - this->f) * (1.0 - this->e);
    //     out[54] = (float)this->gear; out[55] = this->tA; out[56] = this->tB;
    //     for (int i = 0; i < 4; ++i) {
    //       out[20 + i*9 + 0] = wheel[i].s0;
    //       out[20 + i*9 + 1] = wheel[i].s1;
    //       out[20 + i*9 + 2] = clamp_nonneg(wheel[i].speed);
    //       out[20 + i*9 + 3] = wheel[i].t3;
    //       out[20 + i*9 + 4] = wheel[i].t4;
    //       out[20 + i*9 + 5] = wheel[i].t5;
    //       out[20 + i*9 + 6] = wheel[i].t6;
    //       out[20 + i*9 + 7] = wheel[i].t7;
    //       out[20 + i*9 + 8] = wheel[i].t8;
    //     }
    //     return fp_status;
    //   }
    // UNRESOLVED: Field read at this+0x5D8 is not visible in the Hex-Rays raw source; it may be part of the wheel-loop data span (v8 advances 1124 bytes per wheel) that the decompiler did not surface.
    // UNRESOLVED: Field read at this+0x1E38 is not visible in the Hex-Rays raw source; purpose unknown.
    // UNRESOLVED: Globals dbl_59E420, dbl_59E430, dbl_59EA38 are read but not byte-referenced in the raw source; they likely back the folded constants (the 9.549296585513721 = 60/(2*pi) unit-conversion factor and atan2 scale terms).
    // UNRESOLVED: Wheel-loop byte offsets beyond 0x474/0x16F0 (e.g. the 1124-byte stride and its intermediate fields) are not individually listed as packet fields and are only partially grounded.
}
