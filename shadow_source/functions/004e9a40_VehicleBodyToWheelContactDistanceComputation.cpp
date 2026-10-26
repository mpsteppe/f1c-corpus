// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E9A40
// Canonical corpus name: VehicleBodyToWheelContactDistanceComputation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleBodyToWheelContactDistanceComputation_004e9a40.c

void UnknownObject::VehicleBodyToWheelContactDistanceComputation()
{
    // Computes the distance from the predicted vehicle body position to the wheel-contact reference and writes a 13-element contact array into the network packet. When the wheel-contact reference argument a2 is provided, the predicted body position is advanced by a2 scaled by 0.025 (flt_59E87C); otherwise the stored body position is used unchanged. The delta to the current body position is rotated into the vehicle local frame by the 3x3 rotation matrix at this+0x34B0..0x34D0, offset by the local contact anchor at this+0x72C..0x734, and the resulting local contact point is passed for each of the 13 elements to NetworkPacketDataWriter (0x0054FA00). Returns the norm of the local contact vector, clamped to the minimum wheel-contact distance stored at this[3803]. On the per-frame path; called from the switch-based state handler (0x0040F380), AI racing-line follower (0x004E9CA0) and particle-effect update dispatch (0x004EB430).
    // ASSIGNMENT: Read the three predicted-body-position components from this[3800..3802] (offsets 0x3B60/0x3B64/0x3B68) into locals. [field:this:0x00003B60, field:this:0x00003B64, field:this:0x00003B68, source:raw]
    // GUARD: When the wheel-contact reference a2 is non-null, add a2 scaled by 0.025 (flt_59E87C) to each predicted body-position component; otherwise keep the stored position. [global:0x0059E87C, source:raw]
    // CALCULATION: Compute the delta between the predicted body position and the current body position stored at this[3381..3383] (offsets 0x34D4/0x34D8/0x34DC). [field:this:0x000034D4, field:this:0x000034D8, field:this:0x000034DC, source:raw]
    // CALCULATION: Rotate the position delta into the vehicle local frame by multiplying with the 3x3 rotation matrix at this+0x34B0..0x34D0 (row/column elements this[3372..3380]). [field:this:0x000034B0, field:this:0x000034B4, field:this:0x000034B8, field:this:0x000034BC, field:this:0x000034C0, field:this:0x000034C4, field:this:0x000034C8, field:this:0x000034CC, field:this:0x000034D0, source:raw]
    // CALCULATION: Subtract the local contact anchor this[459..461] (offsets 0x72C/0x730/0x734) from the rotated components to obtain the local-frame contact point. [field:this:0x0000072C, field:this:0x00000730, field:this:0x00000734, source:raw]
    // LOOP: For each of the 13 contact elements, read the stored contact position from the contact data array starting at this+0x3ABC (this[3759..3760] area), subtract the local contact anchor, and hand the element and its index to NetworkPacketDataWriter (0x0054FA00). [field:this:0x00003ABC, field:this:0x00003AC0, field:this:0x0000072C, field:this:0x00000730, field:this:0x00000734, callee:0x0054FA00, source:raw]
    // CALCULATION: Compute the result as sqrt(localX^2 + localY^2 + localZ^2) over the un-anchored rotated components (v11/v13/v15). [source:raw]
    // GUARD: Clamp: when the stored minimum wheel-contact distance this[3803] (offset 0x3B6C) is larger than the computed norm, return the stored value instead. [field:this:0x00003B6C, source:raw]
    // RETURN: Return the computed norm, or the clamped stored distance when it is larger. [source:raw]

    // Conservative worker pseudocode:
    //   double VehicleBodyToWheelContactDistanceComputation(float *this, float *a2) {
    //     px = this[3800]; py = this[3801]; pz = this[3802];
    //     if (a2) {
    //       px += a2[0] * 0.025;
    //       py += a2[1] * 0.025;
    //       pz += a2[2] * 0.025;
    //     }
    //     dx = px - this[3381]; dy = py - this[3382]; dz = pz - this[3383];
    //     lx = dz * this[3378] + dy * this[3375] + dx * this[3372];
    //     ly = dz * this[3379] + dy * this[3376] + dx * this[3373];
    //     lz = dz * this[3380] + dy * this[3377] + dx * this[3374];
    //     local[0] = lx - this[459]; local[1] = ly - this[460]; local[2] = lz - this[461];
    //     for (i = 0; i < 13; i++) {
    //       local[3] = this[3758 + 3*i] - this[459];
    //       local[4] = this[3759 + 3*i] - this[460];
    //       local[5] = this[3760 + 3*i] - this[461];
    //       NetworkPacketDataWriter(local, i);
    //     }
    //     result = sqrt(lz*lz + ly*ly + lx*lx);
    //     if (this[3803] > result)
    //       return this[3803];
    //     return result;
    //   }
    // UNRESOLVED: The NetworkPacketDataWriter callee's full packet layout is outside this function; the exact wire meaning of the 13 written contact elements is not evidenced here.
    // UNRESOLVED: The 0.025 scale factor is backed by global flt_59E87C in the IDB but the decompiled source inlines the literal, so the constant-to-global binding is inferred rather than directly evidenced.
    // UNRESOLVED: The relation between the contact data array start offset 0x3ABC and the first written element (read from this[3758]) is not fully pinned by the packet field list.
}
