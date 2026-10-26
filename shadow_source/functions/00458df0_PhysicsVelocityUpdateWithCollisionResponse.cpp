// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00458DF0
// Canonical corpus name: sub_458DF0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_458DF0_00458df0.c

void UnknownObject::PhysicsVelocityUpdateWithCollisionResponse()
{
    // Performs a velocity/direction update on a physics object. Snapshots the previous state triple at this+0x18/+0x1C/+0x20, clears the reset flag at this+0xA0, optionally runs the suspension force calculation when this+0xB0 is non-zero, accumulates the input velocity delta (a2) into the position triple at this+0xC/+0x10/+0x14, optionally scales and writes two force-like outputs to this+0x38/+0x3C when flag bit 0 of this+0x74 is set, normalizes the resulting direction vector, computes a yaw angle from the normalized X/Z, applies the angular collision-response filter when this+0xA4 is positive, and copies the resulting triple back to the object head via VectorCopy.
    // ASSIGNMENT: Reads the previous state triple from this+0x18/+0x1C/+0x20 into the local v29 array [field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, source:raw]
    // STATE_TRANSITION: Reads the byte flag at this+0xA0; if non-zero, clears it to 0 (one-shot reset consumed on the current call) [field:this:0x000000A0, source:raw]
    // GUARD: When the dword flag at this+0xB0 is non-zero, calls SuspensionWheelForceCalculation with this, a2, a4 and the a6 value [field:this:0x000000B0, callee:0x00459070, source:raw]
    // CALCULATION: Accumulates the input delta into the position triple: X = this+0xC + a2[0], Y = this+0x10 + a2[1], Z = this+0x14 + a2[2] [field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, source:raw]
    // GUARD: When bit 0 of the byte flag at this+0x74 is set, reads two field values via DoubleFieldGetterAt0x300x34, computes the scaling factor 35.0/sqrt(X*X+Y*Y+Z*Z) clamped into the 0.1..1.0 range, and writes this+0x38 and this+0x3C as the two read values scaled by that factor [field:this:0x00000074, callee:0x00456040, field:this:0x00000038, field:this:0x0000003C, source:raw]
    // CALCULATION: When the squared magnitude X*X+Y*Y+Z*Z is positive, normalizes the direction vector by multiplying the X/Y/Z components by 1.0/sqrt(magnitude) [source:raw]
    // CALL: Runs FloatConvertWrapper on the computed Y component (decompiler COERCE artifact on v24) [callee:0x00588570, source:raw]
    // CALCULATION: Computes the yaw angle as 3.1415927 - atan2(-X, -Z) using the normalized components; when both X and Z are 0.0 the yaw is set to 0.0 [source:raw]
    // GUARD: When the float at this+0xA4 is greater than 0.0, calls CollisionResponseFilter with this, the computed vector, the previous state snapshot v29 and the scale value, then re-reads the filtered result into the X/Y/Z outputs [field:this:0x000000A4, callee:0x004584C0, source:raw]
    // CALL: Copies the final velocity/direction triple back to the object head via VectorCopy, then returns 0 [callee:0x00456130, source:raw]

    // Conservative worker pseudocode:
    //   old[0..2] = read this+0x18, this+0x1C, this+0x20;
    //   if (this+0xA0) this+0xA0 = 0;
    //   if (this+0xB0) SuspensionWheelForceCalculation(this, a2, a4, a6);
    //   X = this+0xC + a2[0]; Y = this+0x10 + a2[1]; Z = this+0x14 + a2[2];
    //   if (flag(this+0x74) & 1) {
    //     DoubleFieldGetterAt0x300x34(this, &out1, &out2);
    //     scale = 35.0 / sqrt(X*X + Y*Y + Z*Z);
    //     scale = clamp(scale, 0.1, 1.0);
    //     this+0x38 = out1 * scale;
    //     this+0x3C = scale * out2;
    //   }
    //   if (X*X + Y*Y + Z*Z > 0.0) {
    //     inv = 1.0 / sqrt(X*X + Y*Y + Z*Z);
    //     nX = X*inv; nY = Y*inv; nZ = Z*inv;
    //   }
    //   FloatConvertWrapper(nY);
    //   yaw = (nX == 0.0 && nZ == 0.0) ? 0.0 : 3.1415927 - atan2(-nX, -nZ);
    //   if (this+0xA4 > 0.0) {
    //     CollisionResponseFilter(this, &result, old, &scale, a6);
    //     result = (nX, nY, nZ);
    //   }
    //   VectorCopy(this, &result);
    //   return 0;
    // UNRESOLVED: Five read-only globals (flt_59E43C, flt_59E440, flt_59E6A4, flt_59E84C, flt_59EFA4) are flagged by packet facts but appear nowhere in the raw decompiled source; their roles cannot be verified from this packet
    // UNRESOLVED: VectorCopy writes the final triple to the object head (this+0x0/+0x4/+0x8), but those offsets are not part of this packet's field set
    // UNRESOLVED: The two values read by DoubleFieldGetterAt0x300x34 are written to this+0x38/+0x3C only when flag bit 0 of this+0x74 is set; the meaning of this+0x74's remaining bits is unknown
    // UNRESOLVED: The legacy ABI label Object_Camera_Target_Positioning conflicts with the physics-update behavior seen in the raw source; unverified
}
