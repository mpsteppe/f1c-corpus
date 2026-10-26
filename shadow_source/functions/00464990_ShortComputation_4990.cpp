// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00464990
// Canonical corpus name: ShortComputation_4990
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_4990_00464990.c

void UnknownObject::ShortComputation_4990()
{
    // Computes the squared Euclidean distance between an entity's 3D position (read through this[0] at object offsets +0x75, +0x79, +0x7D) and a reference point addressed as a2[3384..3386]. Stores the squared magnitude into this[1] (offset +0x4) and returns the pointer value loaded from this[0]. Called by EntityVisibilityGridManager (00465460), consistent with a per-entity distance query against a grid reference.
    // CALCULATION: Loads the entity pointer from this[0] (offset +0x0) and computes three deltas: v3 = *(float*)(*this+0x75) - a2[3384], v4 = *(float*)(*this+0x79) - a2[3385], v5 = *(float*)(*this+0x7D) - a2[3386] [field:this:0x00000000, field:obj:0x00000075, field:obj:0x00000079, field:obj:0x0000007D, source:raw]
    // ASSIGNMENT: Stores the sum of squared deltas into this[1] (offset +0x4): this[1] = v5*v5 + v4*v4 + v3*v3 [field:this:0x00000004, source:raw]
    // RETURN: Returns the value previously loaded from this[0] (the entity pointer) as the function result [field:this:0x00000000, source:raw]
    // CALL: Invoked by EntityVisibilityGridManager (00465460) as a per-entity squared-distance query against the grid reference point [caller:0x00465460]

    // Conservative worker pseudocode:
    //   entity = this[0];
    //   dx = *(float*)(entity + 0x75) - a2[3384];
    //   dy = *(float*)(entity + 0x79) - a2[3385];
    //   dz = *(float*)(entity + 0x7D) - a2[3386];
    //   this[1] = dz*dz + dy*dy + dx*dx;
    //   return entity;
    // UNRESOLVED: The identity of the entity struct (offsets +0x75/+0x79/+0x7D) and of the object referenced by a2 (indices 3384..3386) is not established by this packet
    // UNRESOLVED: The semantic role of the returned entity pointer at the call site is unknown
}
