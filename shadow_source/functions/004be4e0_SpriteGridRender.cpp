// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BE4E0
// Canonical corpus name: SpriteGridRender
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SpriteGridRender_004be4e0.c

void UnknownObject::SpriteGridRender()
{
    // Renders a sprite footprint into an 8x8 proximity grid. Converts a world position (a3[0], a3[2]) with radius a4 into clamped grid cell ranges using grid origin (this+0x924 / this+0x92C) and grid scale (this+0x928 / this+0x930) via CRTFtol, then calls SphereProximityTag for every cell of the covered rectangle, tagging each cell with the tag-cursor field this+0x934. If any index clamped (grid overflow) it also tags an extra cell at this+0x900. Finally it bumps the tag cursor and returns it.
    // CALCULATION: Compute the minimum grid column: CRTFtol((a3[0] - a4 - grid_origin_x(this+0x924)) * grid_scale_x(this+0x928)), clamped into 0..7; clamping raises an out-of-range flag. [callee:0x00587BDC, field:this:0x00000924, field:this:0x00000928, source:raw]
    // CALCULATION: Compute the maximum grid column: CRTFtol((a3[0] + a4 - grid_origin_x(this+0x924)) * grid_scale_x(this+0x928)), clamped into 0..7. [callee:0x00587BDC, field:this:0x00000924, field:this:0x00000928, source:raw]
    // CALCULATION: Compute the minimum grid row: CRTFtol((a3[2] - a4 - grid_origin_y(this+0x92C)) * grid_scale_y(this+0x930)), clamped into 0..7. [callee:0x00587BDC, field:this:0x0000092C, field:this:0x00000930, source:raw]
    // CALCULATION: Compute the maximum grid row: CRTFtol((a3[2] + a4 - grid_origin_y(this+0x92C)) * grid_scale_y(this+0x930)), clamped into 0..7. [callee:0x00587BDC, field:this:0x0000092C, field:this:0x00000930, source:raw]
    // GUARD: Proceed with the grid iteration only when the column range is non-empty (minimum column <= maximum column). [source:raw]
    // LOOP: Outer loop over grid rows from the minimum to the maximum; each step advances the cell pointer by 72 dwords, one full row of eight 36-byte cells. [source:raw]
    // GUARD: Inner guard: iterate over cells only while the current column is within the computed row-range of columns. [source:raw]
    // LOOP: Inner loop over the covered columns, stepping 9 dwords (one 36-byte cell) per iteration and calling SphereProximityTag for each cell. [callee:0x004BDB10, field:this:0x00000934, source:raw]
    // CALL: SphereProximityTag(cell, tag_cursor, a2, a3, a4) tags the grid cell with the current value of the tag-cursor field this+0x934 plus caller context a2, position a3 and radius a4. [callee:0x004BDB10, field:this:0x00000934]
    // GUARD: If any computed index was clamped (grid range overflow), tag the extra cell at this+0x900 with the current tag cursor. [callee:0x004BDB10, field:this:0x00000934, source:raw]
    // ASSIGNMENT: Increment the tag-cursor field this+0x934 by one and hold the new value as the return value. [field:this:0x00000934, source:raw]
    // RETURN: Return the updated tag cursor (previous value plus one). [field:this:0x00000934]

    // Conservative worker pseudocode:
    //   gridMinX = clamp(CRTFtol((pos[0] - radius - originX) * scaleX), 0, 7);
    //   gridMaxX = clamp(CRTFtol((pos[0] + radius - originX) * scaleX), 0, 7);
    //   gridMinY = clamp(CRTFtol((pos[2] - radius - originY) * scaleY), 0, 7);
    //   gridMaxY = clamp(CRTFtol((pos[2] + radius - originY) * scaleY), 0, 7);
    //   for (row = gridMinX; row <= gridMaxX; ++row)
    //     for (col = gridMinY; col <= gridMaxY; ++col)
    //       SphereProximityTag(cell(col, row), tagCursor, a2, pos, radius);
    //   if (anyClamped) SphereProximityTag(extraCellAt0x900, tagCursor, a2, pos, radius);
    //   return ++tagCursor;
    // UNRESOLVED: The 36-byte cell and 72-dword row-stride geometry is inferred from the loop arithmetic; the grid array declaration is not evidenced.
    // UNRESOLVED: a3 is a float pointer of which only indices 0 and 2 are read; the exact position-vector layout is unknown.
    // UNRESOLVED: The purpose of the extra-cell tag at this+0x900 and the meaning of the tag cursor are not named by evidence.
}
