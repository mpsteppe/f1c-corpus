// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049A9E0
// Canonical corpus name: RectangleEdgeOffsetCalculator
// Owner: RectangleRegionState [DERIVED]
// Raw source: functions/RectangleEdgeOffsetCalculator_0049a9e0.c

void RectangleRegionState::RectangleEdgeOffsetCalculator()
{
    // Computes the offsets of a rectangle, given as four input coordinates (a2..a5), relative to a reference point stored in `this` at offsets 0x4 (reference Y) and 0xC (reference X). Writes the four relative edge values into `this` at offsets 0x14 (left), 0x18 (top), 0x1C (right) and 0x20 (bottom), and returns the relative bottom edge. Straight-line arithmetic; no branches.
    // ASSIGNMENT: Load reference X coordinate from this[3] (offset 0xC). [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Load reference Y coordinate from this[1] (offset 0x4). [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write relative left edge into this[5] (offset 0x14) as a2 - ref_x. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Write relative top edge into this[6] (offset 0x18) as a3 - ref_y. [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Write relative right edge into this[7] (offset 0x1C) as a4 - ref_x. [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Write relative bottom edge into this[8] (offset 0x20) as a5 - ref_y; this value is also the return value. [field:this:0x00000020, source:raw]
    // RETURN: Return the computed relative bottom edge. [source:raw]

    // Conservative worker pseudocode:
    //   ref_x = this[0x0C];
    //   ref_y = this[0x04];
    //   this[0x14] = a2 - ref_x;   // left
    //   this[0x18] = a3 - ref_y;   // top
    //   this[0x1C] = a4 - ref_x;   // right
    //   this[0x20] = a5 - ref_y;   // bottom
    //   return this[0x20];
    // UNRESOLVED: Corner semantics of the four inputs a2..a5 are inferred from the relative edge names; not independently evidenced.
    // UNRESOLVED: Assignment of reference axes (this[0x4] = Y, this[0xC] = X) comes from existing analysis prose only.
    // UNRESOLVED: Single call site sub_492710 (00492710); its reason for calling this routine is unexamined.
}
