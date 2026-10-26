// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004ED710
// Canonical corpus name: Vec3Add
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Vec3Add_004ed710.c

void UnknownObject::Vector3Add()
{
    // Per-component 3-float vector addition: writes a3[0..2] = a1[0..2] + a2[0..2] and returns the output pointer a3. Invoked from vehicle geometry proximity and ray/triangle intersection paths.
    // ASSIGNMENT: Compute and store x component: a3[0] = a1[0] + a2[0]. [field:this:0x00000000]
    // ASSIGNMENT: Compute and store y component: a3[1] = a1[1] + a2[1]. [field:this:0x00000004]
    // ASSIGNMENT: Compute and store z component: a3[2] = a1[2] + a2[2]. [field:this:0x00000008]
    // RETURN: Return the output vector pointer a3. [source:raw]

    // Conservative worker pseudocode:
    //   a3[0] = a1[0] + a2[0];
    //   a3[1] = a1[1] + a2[1];
    //   a3[2] = a1[2] + a2[2];
    //   return a3;
    // UNRESOLVED: The raw source takes three separate float pointers; the packet records reads on this+0x0/0x4/0x8 only, so the containing object identity of a1/a2/a3 is unconfirmed.
    // UNRESOLVED: The prelabel identifies a structural twin via cluster_copy, but the cluster representative address is outside the packet evidence and is not asserted.
}
