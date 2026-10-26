// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044FEE0
// Canonical corpus name: CollisionImpulseAccumulator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionImpulseAccumulator_0044fee0.c

void UnknownObject::CollisionImpulseAccumulator()
{
    // Accumulates the six components of two input 3D vectors (a2 and a3) into six consecutive double accumulator fields on this (this[172..177], i.e. this+0x560..0x588). a2's three components are added to the first accumulator triple (0x560/0x568/0x570) and a3's three components to the second triple (0x578/0x580/0x588). Unconditional, no branches; returns a3.
    // ASSIGNMENT: this[172] (this+0x560) += *a2: add the X component of vector a2 to the first accumulator field. [field:this:0x00000560, source:raw]
    // ASSIGNMENT: this[173] (this+0x568) += a2[1]: add the Y component of vector a2. [field:this:0x00000568, source:raw]
    // ASSIGNMENT: this[174] (this+0x570) += a2[2]: add the Z component of vector a2. [field:this:0x00000570, source:raw]
    // ASSIGNMENT: this[175] (this+0x578) += *a3: add the X component of vector a3 to the second accumulator field. [field:this:0x00000578, source:raw]
    // ASSIGNMENT: this[176] (this+0x580) += a3[1]: add the Y component of vector a3. [field:this:0x00000580, source:raw]
    // ASSIGNMENT: this[177] (this+0x588) += a3[2]: add the Z component of vector a3. [field:this:0x00000588, source:raw]
    // RETURN: return result (a3): the function returns the second input vector pointer. [function:0x0044FEE0, source:raw]
    // CALL: Invoked by AccumulateAngularImpulse (0043E5D0) to fold contact impulse components into the accumulator. [caller:0x0043E5D0]

    // Conservative worker pseudocode:
    //   this[172] += a2[0];
    //   this[173] += a2[1];
    //   this[174] += a2[2];
    //   this[175] += a3[0];
    //   this[176] += a3[1];
    //   this[177] += a3[2];
    //   return a3;
    // UNRESOLVED: Whether a2 and a3 are specifically linear vs angular impulse vectors is inferred from the caller name AccumulateAngularImpulse; the packet raw source shows only unconditional accumulation of two generic 3-vectors.
    // UNRESOLVED: The six accumulator fields are assumed to be three consecutive doubles in each group (stride from double-indexing this[172..177]); contiguity is derived from the raw source, not separately evidenced.
    // UNRESOLVED: The legacy ABI label 'Collision_Impulse_Accumulator' (abi:lead) uses an underscore spelling; proposed_name adopts the canonical identifier CollisionImpulseAccumulator.
}
