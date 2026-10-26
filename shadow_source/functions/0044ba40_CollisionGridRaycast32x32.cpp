// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044BA40
// Canonical corpus name: CollisionGridRaycast32x32
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGridRaycast32x32_0044ba40.c

void UnknownObject::CollisionGridRaycast32x32()
{
    // Subdivides a collision grid into a fixed 32x32 cell raster. Computes each cell's world-space bounding box from the grid center (X at this+8, Z at this+24) and the reciprocal of each axis scale (this+16, this+32), queries the grid data pointer at this+4 via sub_44A880, and stores the returned pointer in a flat output array at this+40. Returns the last query result, or null when the grid pointer at this+4 is null.
    // GUARD: Load the collision grid data pointer at this+4; if it is null the function returns immediately without iterating. [field:this:0x00000004, source:raw]
    // CALCULATION: Compute the X-cell stride as the reciprocal of the X scale at this+16, substituting 0.0 when the scale is exactly 0.0 (guard against divide-by-zero). [field:this:0x00000010, global:0x0059E420, global:0x0059E430, source:raw]
    // CALCULATION: Compute the Z-cell stride as the reciprocal of the Z scale at this+32, substituting 0.0 when the scale is exactly 0.0 (guard against divide-by-zero). [field:this:0x00000020, global:0x0059E420, global:0x0059E430, source:raw]
    // LOOP: Outer do-while loop over 32 rows, tracking the current row index. [source:raw]
    // CALCULATION: Per row, derive the near and far X cell bounds from (row - 0.5) and (row + 0.5) scaled by the X stride. [field:this:0x00000010, global:0x0059E880, source:raw]
    // LOOP: Inner do-while loop over 32 columns, tracking the current column index. [source:raw]
    // CALCULATION: Build a 4-float cell bounding box: X bounds are the row bounds offset by the grid center X at this+8, Z bounds are (column - 0.5) and (column + 0.5) scaled by the Z stride and offset by the grid center Z at this+24. [field:this:0x00000008, field:this:0x00000018, global:0x0059E880, source:raw]
    // CALL: Call sub_44A880 with the grid data pointer and the cell bounding box; store the returned query pointer into the output array and advance the array cursor. [field:this:0x00000004, callee:0x0044A880, source:raw]
    // RETURN: Return the last grid query result pointer (or the uninitialized result when the grid pointer was null). [source:raw]

    // Conservative worker pseudocode:
    //   float* CollisionGridRaycast32x32::CollisionGridRaycast32x32(int this) {
    //     float* result = *(float**)(this + 4);
    //     if (result) {
    //       double invX = (*(double*)(this + 16) == 0.0) ? 0.0 : 1.0 / *(double*)(this + 16);
    //       double invZ = (*(double*)(this + 32) == 0.0) ? 0.0 : 1.0 / *(double*)(this + 32);
    //       float** out = (float**)(this + 40);
    //       for (int row = 0; row < 32; ++row) {
    //         double nearX = (row - 0.5) * invX;
    //         double farX = (row + 0.5) * invX;
    //         for (int col = 0; col < 32; ++col) {
    //           float box[4];
    //           box[0] = nearX + *(double*)(this + 8);
    //           box[1] = farX + *(double*)(this + 8);
    //           box[2] = (col - 0.5) * invZ + *(double*)(this + 24);
    //           box[3] = (col + 0.5) * invZ + *(double*)(this + 24);
    //           result = sub_44A880(*(float**)(this + 4), box);
    //           *out++ = result;
    //         }
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The layout and semantics of the structure sub_44A880 returns per cell are unknown; only the returned pointer is stored.
    // UNRESOLVED: The type of the this object (a collision grid description struct) has no confirmed name or runtime evidence.
    // UNRESOLVED: Global constant roles (0x0059E420, 0x0059E430, 0x0059E880) are inferred from the source literals 1.0, 0.0 and 0.5 and are not independently verified.
}
