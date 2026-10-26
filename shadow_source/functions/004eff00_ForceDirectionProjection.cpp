// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004EFF00
// Canonical corpus name: ForceDirectionProjection
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ForceDirectionProjection_004eff00.c

void UnknownObject::ForceDirectionProjection()
{
    // Computes the negated scalar projection of a vector (this+0x34B8, +0x34C4, +0x34D0) onto the direction vector (this+0x34EC, +0x34F0, +0x34F4), scaled by the inverse direction magnitude. Returns 0.0 when the direction vector is entirely zero. No branches beyond the zero-guard, no callees; part of the physics force projection system. Invoked by sub_4BCCC0 (0x004BCCC0).
    // GUARD: If all three direction components at this+0x34EC, this+0x34F0, this+0x34F4 are zero, return 0.0 immediately [field:this:0x000034EC, field:this:0x000034F0, field:this:0x000034F4, source:raw]
    // CALCULATION: Compute the inverse direction magnitude as 1.0/sqrt(dirX^2 + dirY^2 + dirZ^2) using the three direction components [source:raw]
    // CALCULATION: Normalize the X and Y direction components by the inverse magnitude (v5 = dirX * invMag, v6 = dirY * invMag) [source:raw]
    // CALCULATION: Compute the negated dot product of the direction with the vector at this+0x34B8, this+0x34C4, this+0x34D0, scaled by the inverse magnitude [field:this:0x000034B8, field:this:0x000034C4, field:this:0x000034D0, source:raw]
    // RETURN: Return 0.0 when the direction vector is zero, otherwise return the negated projection value [source:raw]
    // CALL: Invoked by sub_4BCCC0 (0x004BCCC0) [caller:0x004BCCC0, source:raw]

    // Conservative worker pseudocode:
    //   double ForceDirectionProjection(float *this) {
    //     if (this[0x34EC/4] == 0.0 && this[0x34F0/4] == 0.0 && this[0x34F4/4] == 0.0)
    //       return 0.0;
    //     double inv = 1.0 / sqrt(this[0x34F4/4]*this[0x34F4/4]
    //                              + this[0x34F0/4]*this[0x34F0/4]
    //                              + this[0x34EC/4]*this[0x34EC/4]);
    //     double nx = this[0x34EC/4] * inv;
    //     double ny = this[0x34F0/4] * inv;
    //     return -(inv * this[0x34F4/4] * this[0x34D0/4]
    //              + ny * this[0x34C4/4]
    //              + nx * this[0x34B8/4]);
    //   }
    // UNRESOLVED: The two read-only globals flt_59E43C (0x0059E43C) and flt_59E440 (0x0059E440) are flagged by packet facts but appear nowhere in the raw decompiled source; their role in this function is unverifiable from this packet
    // UNRESOLVED: The semantic meaning of the projected vector (this+0x34B8/+0x34C4/+0x34D0) and the direction vector (this+0x34EC/+0x34F0/+0x34F4) within the physics object requires caller context
}
