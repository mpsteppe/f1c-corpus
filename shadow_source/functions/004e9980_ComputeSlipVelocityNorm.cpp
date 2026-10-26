// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E9980
// Canonical corpus name: ComputeSlipVelocityNorm
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ComputeSlipVelocityNorm_004e9980.c

void UnknownObject::ComputeSlipVelocityNorm()
{
    // Computes the slip-velocity norm. Builds the displacement between a reference point (this+0x3B60/0x3B64/0x3B68) and the current position (this+0x34D4/0x34D8/0x34DC), rotates it into the local frame via the 3x3 rotation matrix at this+0x34B0..0x34D0, takes the Euclidean norm, adds the bias literal 3.2, and clamps to the minimum threshold this+0x3B6C. Invoked by ParticleEffectUpdateDispatch (0x004EB430).
    // CALCULATION: Compute the displacement components between the reference point (this+0x3B60/0x3B64/0x3B68) and the current position (this+0x34D4/0x34D8/0x34DC) [field:this:0x000034D4, field:this:0x000034D8, field:this:0x000034DC, field:this:0x00003B60, field:this:0x00003B64, field:this:0x00003B68, source:raw]
    // CALCULATION: Rotate the displacement into the local frame by dotting it with the three rotation matrix rows at this+0x34B0..0x34D0, producing v6, v7 and v4 [field:this:0x000034B0, field:this:0x000034B4, field:this:0x000034B8, field:this:0x000034BC, field:this:0x000034C0, field:this:0x000034C4, field:this:0x000034C8, field:this:0x000034CC, field:this:0x000034D0, source:raw]
    // CALCULATION: Compute the slip-velocity norm as sqrt(v4*v4 + v7*v7 + v6*v6) plus the bias literal 3.2 [source:raw]
    // GUARD: Clamp: if the threshold field this+0x3B6C is greater than the computed norm, return the threshold value instead [field:this:0x00003B6C, source:raw]
    // RETURN: Return the computed slip-velocity norm; the function is invoked by ParticleEffectUpdateDispatch (0x004EB430) [function:0x004E9980, caller:0x004EB430, source:raw]

    // Conservative worker pseudocode:
    //   dx = this[0x3B60] - this[0x34D4];
    //   dy = this[0x3B64] - this[0x34D8];
    //   dz = this[0x3B68] - this[0x34DC];
    //   v6 = dz*this[0x34C8] + dy*this[0x34BC] + dx*this[0x34B0];
    //   v7 = dz*this[0x34CC] + dy*this[0x34C0] + dx*this[0x34B4];
    //   v4 = dz*this[0x34D0] + dy*this[0x34C4] + dx*this[0x34B8];
    //   norm = sqrt(v4*v4 + v7*v7 + v6*v6) + 3.2;
    //   if (this[0x3B6C] > norm) return this[0x3B6C];
    //   return norm;
    // UNRESOLVED: The packet facts flag flt_5AD1D8 (0x005AD1D8) as read-only, but the raw source references only the folded bias literal 3.2; the skeleton fill names it CollisionRadiusBias (DERIVED), and the relationship between that global and the literal cannot be confirmed from this packet
    // UNRESOLVED: The physical meaning of the 3.2 bias and of the clamp threshold at this+0x3B6C relative to tire slip is DERIVED from the caller context, not proven by this function
}
