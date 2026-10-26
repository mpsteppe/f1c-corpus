// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045F2A0
// Canonical corpus name: CollisionInvDistanceStore
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionInvDistanceStore_0045f2a0.c

void UnknownObject::StoreInverseDistance()
{
    // Writes the multiplicative inverse of parameter a2 (1.0 / a2) into the float field at this+0x4 of the object, interpreted as an inverse-distance store for collision work. Called by SessionTypeSetter.
    // CALCULATION: Computes 1.0 / a2, the reciprocal of the input value. [source:raw]
    // ASSIGNMENT: Stores the computed reciprocal into this[1], the float field at this+0x4. [field:this:0x00000004, source:raw]

    // Conservative worker pseudocode:
    //   this[1] = 1.0 / a2;
    // UNRESOLVED: Packet lists a read of global flt_59E43C, but the raw source text does not reference it; left unmodeled.
}
