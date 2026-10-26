// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054D910
// Canonical corpus name: AABBFrustumVisibilityClassification
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AABBFrustumVisibilityClassification_0054d910.c

void UnknownObject::classifyAabbFrustumVisibility()
{
    // Classifies an axis-aligned bounding box against view-frustum planes. Clears the low 3 bits of the state word this[5] (offset 0x14) with mask 0xFFFFFFF8, then writes the result: 1 = fully visible, 2 = fully culled, 4 = intersecting. The AABB is represented by 8 corners (3 floats each) starting at a3+8; planes are 4 floats each starting at a2+260. When the plane count this[63] (offset 0xFC) is not positive the classification is skipped and the state defaults to visible. The independent skeleton analysis of sub_54D910 agrees on both field roles and the three result states.
    // ASSIGNMENT: Clear the low 3 bits of the state word this[5] (offset 0x14) via mask 0xFFFFFFF8, preserving the remaining high bits [field:this:0x00000014, source:raw]
    // GUARD: Guard on the frustum plane count this[63] (offset 0xFC): when it is not positive, skip the culling loop and default to the visible state (this[5] = state | 1) [field:this:0x000000FC, source:raw]
    // LOOP: Iterate over frustum planes, each represented by 4 floats at a2+260 + 4*plane [source:raw]
    // CALCULATION: For each of the 8 AABB corners (3 floats each at a3+8), evaluate the plane test -(nx*cx) - (ny*cy) - (nz*cz) > d and set bit i of the mask when the corner is outside the plane [source:raw]
    // STATE_TRANSITION: Break the plane loop on the first plane with any outside corner: mask == 255 (all 8 corners outside) selects state 2 (culled); a partial mask selects state 4 (intersecting); no outside corner on any plane keeps state 1 (visible) [source:raw]
    // ASSIGNMENT: Write the classification result back to the state word this[5] (offset 0x14) OR-ed onto the cleared bits [field:this:0x00000014, source:raw]
    // RETURN: Return 0 on every path after the state word is updated [source:raw]
    // CALL: Invoked by sub_556B10 (0x00556B10) as part of the visibility/culling decision [caller:0x00556B10]

    // Conservative worker pseudocode:
    //   state = this[5] & 0xFFFFFFF8;
    //   if (this[63] <= 0) { this[5] = state | 1; return 0; }
    //   for (plane = a2 + 260; ; plane += 4) {
    //     mask = 0;
    //     for (i = 0; i < 8; ++i)
    //       if (-plane[2]*corner[i].x - plane[1]*corner[i].y - plane[0]*corner[i].z > plane[3])
    //         mask |= 1 << i;
    //     if (mask == 0) continue;
    //     this[5] = state | (mask == 255 ? 2 : 4);
    //     return 0;
    //   }
    //   this[5] = state | 1;
    //   return 0;
    // UNRESOLVED: The owner object of the state word (offset 0x14) and plane count (offset 0xFC) is unknown; the packet carries no owner evidence
    // UNRESOLVED: The frustum layout (4 floats per plane at a2+260) and AABB corner layout (3 floats per corner at a3+8) are inferred from the raw source pointer arithmetic, not from named fields
    // UNRESOLVED: The meaning of the preserved high bits of the state word (mask 0xFFFFFFF8) is undocumented
}
