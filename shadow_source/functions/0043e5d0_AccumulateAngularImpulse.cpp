// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0043E5D0
// Canonical corpus name: AccumulateAngularImpulse
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AccumulateAngularImpulse_0043e5d0.c

void UnknownObject::AccumulateAngularImpulse()
{
    // Vehicle collision-impulse accumulator. Reads the contact point position from the collision-contact struct pointed to by this+0x15F0, computes the relative position a2 minus contact point, forms the cross product of relative position with impulse a3 to get torque components, accumulates the impulse (a3) into this+0x1F04/0x1F0C/0x1F14 and the torque into this+0x1F1C/0x1F24/0x1F2C, then forwards both to CollisionImpulseAccumulator(a3, &torque). Called from VehicleContactForceAccumulation (0x004EBC60) on the per-frame path.
    // ASSIGNMENT: Read the contact point position (X at +0x4, Y at +0xC, Z at +0x14) from the contact-data struct pointed to by this+0x15F0, and form the relative position components v3/v4/v5 = a2 minus contact point. [field:this:0x000015F0, field:*(this+0x15F0):0x00000004, field:*(this+0x15F0):0x0000000C, field:*(this+0x15F0):0x00000014, source:raw]
    // CALCULATION: Compute torque components as the cross product of relative position v3/v4/v5 with impulse a3: v7 = v4*a3[2] - v5*a3[1], v8 = v5*a3[0] - v3*a3[2], v9 = v3*a3[1] - v4*a3[0]. [source:raw]
    // ASSIGNMENT: Accumulate the linear impulse a3 into this+0x1F04 (X), this+0x1F0C (Y), this+0x1F14 (Z). [field:this:0x00001F04, field:this:0x00001F0C, field:this:0x00001F14, source:raw]
    // ASSIGNMENT: Accumulate the computed torque into this+0x1F1C (X), this+0x1F24 (Y), this+0x1F2C (Z). [field:this:0x00001F1C, field:this:0x00001F24, field:this:0x00001F2C, source:raw]
    // CALL: Call CollisionImpulseAccumulator with the impulse a3 and the torque triple starting at v7. [callee:0x0044FEE0, source:raw]
    // RETURN: Return the result of CollisionImpulseAccumulator. [source:raw]

    // Conservative worker pseudocode:
    //   int AccumulateAngularImpulse(this, double* a2, double* a3) {
    //       double* contact = *(double**)(this + 0x15F0);
    //       double relX = a2[0] - contact[0];
    //       double relY = a2[1] - contact[1];
    //       double relZ = a2[2] - contact[2];
    //       double torX = relY * a3[2] - relZ * a3[1];
    //       double torY = relZ * a3[0] - relX * a3[2];
    //       double torZ = relX * a3[1] - relY * a3[0];
    //       *(double*)(this + 0x1F04) += a3[0];
    //       *(double*)(this + 0x1F0C) += a3[1];
    //       *(double*)(this + 0x1F14) += a3[2];
    //       *(double*)(this + 0x1F1C) += torX;
    //       *(double*)(this + 0x1F24) += torY;
    //       *(double*)(this + 0x1F2C) += torZ;
    //       return CollisionImpulseAccumulator(a3, &torX);
    //   }
    // UNRESOLVED: global unk_7CBB10 (0x007CBB10) is listed in the packet as read evidence but does not appear in the raw source text of this function; it may belong to a shared contact/collision context or be a packet-listing artifact.
    // UNRESOLVED: The roles of a2 and a3 are inferred (a2 = application point, a3 = impulse) from the arithmetic; the packet does not name them.
    // UNRESOLVED: The exact layout of the contact-data struct at this+0x15F0 beyond the three read doubles is not evidenced.
    // UNRESOLVED: Owner is unknown; the raw source has an implicit this but no owning class is evidenced.
}
