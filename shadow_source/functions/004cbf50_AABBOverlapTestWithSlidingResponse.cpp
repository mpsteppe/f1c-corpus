// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CBF50
// Canonical corpus name: F_3DAABBOverlapTestWithSlidingResponse
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DAABBOverlapTestWithSlidingResponse_004cbf50.c

void UnknownObject::AABBOverlapTestWithSlidingResponse()
{
    // Line-segment versus oriented-box overlap test with a sliding response. Loads the box's local-space extents from a3[30..35], transforms both segment endpoints (a1 source, a2 target) into the box's local frame relative to its center (a3[2..4]) using the orientation matrix (a3[8..16]), then checks interval overlap on all three local axes. When the segment fully crosses the box it slides the target point a2 to the box surface along the first axis (v13) and writes the corrected point back in world space, re-adding the box center.
    // ASSIGNMENT: Load the box's local-space extents a3[30], a3[31], a3[32], a3[33], a3[34], a3[35] into locals v20, v21, v22, v23, v24, v25. [source:raw]
    // CALCULATION: Compute the source point (a1) displacement from the box center: v3 = a1[0] - a3[2], v4 = a1[1] - a3[3], v5 = a1[2] - a3[4]. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALCULATION: Rotate the source displacement into the box's local frame using the orientation matrix rows (a3[8..10], a3[11..13], a3[14..16]): v17, v18, v19. [source:raw]
    // CALCULATION: Compute the target point (a2) displacement from the box center: v6 = a2[0] - a3[2], v7 = a2[1] - a3[3], v8 = a2[2] - a3[4]. [source:raw]
    // CALCULATION: Rotate the target displacement into the box's local frame: v14, v15, v16. [source:raw]
    // GUARD: Test interval overlap of the two local-space points against the box extents on all three axes (v23/v20 with v17/v14, v25/v22 with v19/v16, v24/v21 with v18/v15); proceed only when every axis overlaps, meaning the segment crosses the box. [source:raw]
    // CALCULATION: On the first axis select the slide distance v13 so the target sits on the box face: when the FPU status compare flags (v10 & 0x41) are set, v13 = v14 - v17 + v23 if v17 <= v14 else v23; otherwise v13 = v20 if v17 <= v14 else v20 - (v17 - v14). [source:raw]
    // ASSIGNMENT: Transform the corrected local point back to world space and write it into a2: a2[0] = v15*a3[9] + v16*a3[10] + v13*a3[8]; a2[1] = v15*a3[12] + v16*a3[13] + v13*a3[11]; a2[2] = v15*a3[15] + v16*a3[16] + v13*a3[14]. [source:raw]
    // ASSIGNMENT: Re-add the box center to the result: a2[0] += a3[2]; a2[1] += a3[3]; a2[2] += a3[4]. [source:raw]

    // Conservative worker pseudocode:
    //   e0 = a3[30]; e1 = a3[31]; e2 = a3[32]; e3 = a3[33]; e4 = a3[34]; e5 = a3[35];
    //   sx = a1[0] - a3[2]; sy = a1[1] - a3[3]; sz = a1[2] - a3[4];
    //   v17 = sz*a3[14] + sy*a3[11] + sx*a3[8];
    //   v18 = sz*a3[15] + sy*a3[12] + sx*a3[9];
    //   v19 = sz*a3[16] + sy*a3[13] + sx*a3[10];
    //   tx = a2[0] - a3[2]; ty = a2[1] - a3[3]; tz = a2[2] - a3[4];
    //   v14 = tz*a3[14] + ty*a3[11] + tx*a3[8];
    //   v15 = tz*a3[15] + ty*a3[12] + tx*a3[9];
    //   v16 = tz*a3[16] + ty*a3[13] + tx*a3[10];
    //   if ((v17<e3 && v14>e0 || v17>e0 && v14<e3) &&
    //       (v19<e5 && v16>e2 || v19>e2 && v16<e5) &&
    //       (v18<e4 && v15>e1 || v18>e1 && v15<e4)) {
    //       if (v17 <= v14) v13 = (v10 & 0x41) ? (v14 - v17 + e3) : e0;
    //       else v13 = (v10 & 0x41) ? e3 : (e0 - (v17 - v14));
    //       a2[0] = v15*a3[9] + v16*a3[10] + v13*a3[8];
    //       a2[1] = v15*a3[12] + v16*a3[13] + v13*a3[11];
    //       a2[2] = v15*a3[15] + v16*a3[16] + v13*a3[14];
    //       a2[0] += a3[2]; a2[1] += a3[3]; a2[2] += a3[4];
    //   }
    // UNRESOLVED: Global flt_59E450 (0x0059E450) is listed as read by this function but never appears in the raw source; its role (suggested elsewhere as DegreesToRadians) is unestablished here.
    // UNRESOLVED: The grouping of a3 indices (center at [2..4], orientation at [8..16], extents at [30..35]) is inferred from usage in this function, not from named packet fields.
    // UNRESOLVED: The FPU status compare flags (v10 & 0x41) select which side of the box the target slides to; the polarity and the meaning of v10 are not independently confirmed.
    // UNRESOLVED: Callers ParticleEffectPhysics (0x004CCB30) and ParticleSystemUpdateWithWindAndDamping (0x004CD220) show this runs inside particle physics; the owning object and frame placement are unknown.
}
