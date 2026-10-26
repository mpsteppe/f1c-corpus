// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BE1D0
// Canonical corpus name: NestedLoopRangeTraversal
// Owner: SpatialGridIndex [DERIVED]
// Raw source: functions/NestedLoopRangeTraversal_004be1d0.c

void SpatialGridIndex::InsertIntoGridCells()
{
    // Converts a float extent carried in a2 into four grid cell indices using `this`'s grid transform (offset 0x924/0x928 and 0x92C/0x930 act as per-axis origin and scale), clamps each index to 0..7, then appends the pointer a2 to the dynamic array of every cell in the resulting cell rectangle. If any conversion was clamped, a2 is also appended to a fallback array at this + 576 (byte offset 0x900). Returns the clamp/append status flag.
    // CALCULATION: Convert row lower bound: CRTFtol((a2[3] - a2[6] - this[585]) * this[586]) using grid origin this[0x924] and scale this[0x928]. [callee:0x00587BDC, field:this:0x00000924, field:this:0x00000928, source:raw]
    // CALCULATION: Convert row upper bound: CRTFtol((a2[6] + a2[3] - this[585]) * this[586]); clamp result into 0..7. [callee:0x00587BDC, field:this:0x00000924, field:this:0x00000928, source:raw]
    // CALCULATION: Convert column lower bound: CRTFtol((a2[5] - a2[6] - this[587]) * this[588]) using grid origin this[0x92C] and scale this[0x930]. [callee:0x00587BDC, field:this:0x0000092C, field:this:0x00000930, source:raw]
    // CALCULATION: Convert column upper bound: CRTFtol((a2[6] + a2[5] - this[587]) * this[588]); clamp result into 0..7. [callee:0x00587BDC, field:this:0x0000092C, field:this:0x00000930, source:raw]
    // STATE_TRANSITION: Set the clamped flag (v16) to 1 whenever any of the four float-to-int conversions required clamping out of the 0..7 range. [source:raw]
    // LOOP: Iterate rows row_min..row_max and columns col_min..col_max over the cell grid; for each cell at this + 72*row + 9*col (float units) call DynamicArrayAppendWithRealloc with a2. [callee:0x004BD9B0, source:raw]
    // CALL: If the clamped flag is set, append a2 to the fallback array at this + 576 (byte offset 0x900) via DynamicArrayAppendWithRealloc; otherwise return the flag. [callee:0x004BD9B0, source:raw]
    // RETURN: Return the clamp flag when unset, or the result of the final DynamicArrayAppendWithRealloc when set. [source:raw]

    // Conservative worker pseudocode:
    //   clamped = false;
    //   row_min = clamp(CRTFtol((a2[3] - a2[6] - this[0x924]) * this[0x928]), 0, 7);
    //   row_max = clamp(CRTFtol((a2[6] + a2[3] - this[0x924]) * this[0x928]), 0, 7);
    //   col_min = clamp(CRTFtol((a2[5] - a2[6] - this[0x92C]) * this[0x930]), 0, 7);
    //   col_max = clamp(CRTFtol((a2[6] + a2[5] - this[0x92C]) * this[0x930]), 0, 7);
    //   for row in row_min..row_max:
    //     for col in col_min..col_max:
    //       DynamicArrayAppendWithRealloc(&this[72*row + 9*col], a2);
    //   if clamped: return DynamicArrayAppendWithRealloc(this + 576, a2);
    //   return clamped;
    // UNRESOLVED: Exact meaning of a2[3], a2[5] and a2[6] (range extents) is inferred from arithmetic; the element layout of a2 is unproven.
    // UNRESOLVED: Fallback array at this + 576 (byte offset 0x900) is referenced in raw source but has no permitted field evidence ref; its exact role is unproven.
    // UNRESOLVED: Cell geometry (9 floats per cell, 72 floats per row) is inferred from the loop strides only.
    // UNRESOLVED: Grid purpose (spatial hash / tile index) and cluster relationship to sub_4BDE20 (004bde20) remain DERIVED.
}
