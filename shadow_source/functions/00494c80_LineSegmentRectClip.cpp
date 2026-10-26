// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00494C80
// Canonical corpus name: F_2DLineRectClipping
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_2DLineRectClipping_00494c80.c

void UnknownObject::LineSegmentRectClip()
{
    // Clips a 2D line segment against an axis-aligned rectangle whose width and height are read from a1 + 28 and a1 + 32. Two passes process the segment against the X and Y clip bounds; out-of-bound point coordinates are clamped to the bound (or cleared to the zero threshold) with the clipped coordinate interpolated along the segment edge. Returns whether the clipped line retains a non-zero extent. Invoked by FloatVectorWithConditionalTransform (00494C20).
    // ASSIGNMENT: Reads the rectangle width from a1 + 28 and the height from a1 + 32 and casts them to floats as the clip bounds v22 / v23 (each reduced by 1) [source:raw]
    // LOOP: Outer two-pass loop (v20 = 0 then 1); the second pass restarts from the original segment start a2 after the first pass advanced the line [source:raw]
    // LOOP: Inner loop iterates the two segment points; each point is tested against one clip bound per pass [source:raw]
    // GUARD: Per-point axis test using the segment coordinates at this+0x0 / this+0x4 (start) and this+0xC / this+0x10 (end): a point coordinate v11 already within the current bound is left unchanged (continue); otherwise the crossing is resolved [field:this:0x00000000, field:this:0x00000004, field:this:0x0000000C, field:this:0x00000010, source:raw]
    // CALCULATION: Computes the clipped coordinate by linear interpolation along the segment edge: *v8 = v14 * (v16 / v15) + *v8 [source:raw]
    // ASSIGNMENT: Writes the clamp: the out-of-bound point coordinate is set to the bound value *v9, or cleared to 0.0 as the zero threshold (flt_59E440) [global:0x0059E440, source:raw]
    // RETURN: Returns whether the clipped line has non-zero extent: *a2 - a2[3] != 0.0 or a2[1] - a2[4] != 0.0 [source:raw, field:this:0x00000000, field:this:0x00000004]
    // CALL: Invoked by FloatVectorWithConditionalTransform (00494C20) [caller:0x00494C20, source:raw]

    // Conservative worker pseudocode:
    //   boundX = (float)(a1_width - 1);
    //   boundY = (float)(a1_height - 1);
    //   for (pass = 0; pass < 2; ++pass) {
    //     if (pass) advance the line start;
    //     for (i = 0; i < 2; ++i) {
    //       bound = (pass == 0) ? boundX : boundY;
    //       if (point coordinate <= bound) continue;
    //       interpolate the clipped coordinate along the segment edge;
    //       point coordinate = bound;   // or cleared to 0.0 for the zero threshold
    //     }
    //   }
    //   return (start.x != end.x) || (start.y != end.y);
    // UNRESOLVED: The two status flags v12 / v13 (packet-observed unsigned __int8 values) gate the clamp branch without being materialized in the raw C; their exact comparison source is not recoverable here
    // UNRESOLVED: The rectangle object's width field at a1 + 28 and height field at a1 + 32 are not exposed as packet fields
    // UNRESOLVED: The zero-threshold float flt_59E440 is a packet fact; its runtime identity is not proven from this function alone
}
