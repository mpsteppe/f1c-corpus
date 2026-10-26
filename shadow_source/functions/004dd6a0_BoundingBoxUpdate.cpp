// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DD6A0
// Canonical corpus name: BoundingBoxUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BoundingBoxUpdate_004dd6a0.c

void UnknownObject::BoundingBoxUpdate()
{
    // Expands a running axis-aligned bounding box: queries a 3-float offset via TripleFieldQuery, computes the object's local min/max extents via BoundingBoxComputation from a1+0x0/0x4/0x8, translates both extents by the offset, then merges them into the caller's min bound a2 (per-axis min) and max bound a3 (per-axis max). Scene bounding-volume update; called from VehicleGraphicsSceneLoader (004dfce0).
    // CALL: Query the 3-float position offset into locals v16/v17/v18: TripleFieldQuery(&v16, &v17, &v18). [callee:0x0054B420, source:raw]
    // CALL: Compute the object's local bounding-box extents from the 3-float fields at a1+0x0/0x4/0x8 into locals v13..v15 (min side) and v10..v12 (max side): BoundingBoxComputation(a1, &v13, &v10). [callee:0x004DD550, field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALCULATION: Translate both local extents by the queried offset: v5 = v16 + v13, v14 = v17 + v14, v15 = v18 + v15 (min side) and v10 = v16 + v10, v11 = v17 + v11, v12 = v18 + v12 (max side). [source:raw]
    // ASSIGNMENT: Merge the translated min extents into the running min bound a2 with per-axis minimum: a2[0] = min(a2[0], v5), a2[1] = min(a2[1], v14), a2[2] = min(a2[2], v15). [source:raw]
    // ASSIGNMENT: Merge the translated max extents into the running max bound a3 with per-axis maximum: a3[0] = max(a3[0], v10), a3[1] = max(a3[1], v11), a3[2] = max(a3[2], v12). [source:raw]
    // RETURN: Return void; all six bounds are updated in place through a2/a3. [source:raw, function:0x004DD6A0]

    // Conservative worker pseudocode:
    //   TripleFieldQuery(&off[0], &off[1], &off[2]);
    //   BoundingBoxComputation(a1, &minBox[0], &maxBox[0]);
    //   minBox[0] += off[0]; minBox[1] += off[1]; minBox[2] += off[2];
    //   maxBox[0] += off[0]; maxBox[1] += off[1]; maxBox[2] += off[2];
    //   a2[0] = fminf(a2[0], minBox[0]); a2[1] = fminf(a2[1], minBox[1]); a2[2] = fminf(a2[2], minBox[2]);
    //   a3[0] = fmaxf(a3[0], maxBox[0]); a3[1] = fmaxf(a3[1], maxBox[1]); a3[2] = fmaxf(a3[2], maxBox[2]);
    // UNRESOLVED: Object type and identity of a1 are not established by the packet; the owner is UnknownObject.
    // UNRESOLVED: Source and world-frame meaning of the TripleFieldQuery offset (world position vs translation) are unknown.
    // UNRESOLVED: The source branch `else a3[2] = a3[2];` is a decompiler artifact of the max-clamp; a self-assignment no-op.
    // UNRESOLVED: Whether the min/max roles of the two BoundingBoxComputation outputs are fixed by contract or caller convention is not proven by the packet.
}
