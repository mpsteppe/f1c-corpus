// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00541F60
// Canonical corpus name: sub_541F60
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_541F60_00541f60.c

void UnknownObject::ComputeAimAnglesToTarget()
{
    // Computes pitch and yaw angles to face a target point. Computes the direction delta from the current position (this+0x24/0x28/0x2C) to the target (a2, a3, a4), normalizes by the Euclidean distance, stores the negated pitch at this+0x30 and the negated yaw (atan2 plus a 1.5707964 heading offset) at this+0x34, then builds the orientation delta between the current position and the reference position (this+0x3C/0x40/0x44, with the facing component at this+0x38) and finalizes orientation via UtilityFunction_1cd0. All work is skipped when the distance is zero.
    // CALCULATION: Compute the direction delta from the current position (this+0x24, this+0x28, this+0x2C) to the target components (a2, a3, a4). [field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, source:raw]
    // CALCULATION: Compute the Euclidean distance to the target as sqrt(dx*dx + dy*dy + dz*dz). [source:raw]
    // GUARD: Guard: when the computed distance equals the double zero constant at 0x0059E430, skip the entire orientation update. [global:0x0059E430]
    // CALL: Coerce the floating-point transform state via FloatConvertWrapper before deriving the angles. [callee:0x00588570]
    // CALCULATION: Compute the pitch from the normalized vertical delta and store its negation at this+0x30; compute the yaw as atan2 of the normalized horizontal components plus the 1.5707964 heading offset and store its negation at this+0x34. [field:this:0x00000030, field:this:0x00000034, global:0x0059F1F4]
    // CALCULATION: Build the orientation delta: negate the facing component at this+0x38 and subtract the current position from the reference position at this+0x3C, this+0x40 and this+0x44. [field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044]
    // CALL: Finalize the orientation by calling UtilityFunction_1cd0 with the orientation delta and the negated pitch, yaw and roll values. [callee:0x00541CD0]

    // Conservative worker pseudocode:
    //   dx = this[9] - target.x; dy = this[10] - target.y; dz = this[11] - target.z;
    //   dist = sqrt(dx*dx + dy*dy + dz*dz);
    //   if (dist != 0.0) {
    //     FloatConvertWrapper(this);
    //     pitch = -(dy / dist);
    //     yaw   = atan2(dz / dist, dx / dist) + 1.5707964;
    //     this[12] = -pitch;
    //     this[13] = -yaw;
    //     UtilityFunction_1cd0(this[9]-this[15], this[10]-this[16], this[11]-this[17], pitch, yaw, -this[14]);
    //   }
    // UNRESOLVED: The float constant at 0x0059E43C is read by this function but its exact role (distance epsilon vs. transform coefficient) is not evident from this body.
    // UNRESOLVED: The relationship between the stored angles (this+0x30/0x34) and the reference/ facing fields consumed by UtilityFunction_1cd0 depends on the caller sub_55A060 (0x0055A060).
}
