// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00491680
// Canonical corpus name: sub_491680
// Owner: AxisAlignedBoundingBox [DERIVED]
// Raw source: functions/sub_491680_00491680.c

void AxisAlignedBoundingBox::AABBOverlapTest()
{
    // Axis-aligned bounding box overlap test. The this box is stored as four __int16 values: min X, min Y, width/span X (this+0x4), height/span Y (this+0x6); the query box is given as its min X, min Y, width and height as four int arguments. Both axes are clamped to the shared interval; if the clamped X span is non-positive the boxes cannot overlap, otherwise the function returns whether the clamped Y span is positive.
    // CALCULATION: Compute this box upper X bound: v6 = this[0] + this[2] (min X plus X span at this+0x4). [source:raw, field:this:0x00000000, field:this:0x00000004]
    // GUARD: Clamp lower X: v5 = max(this[0], a2); the shared lower bound cannot be below the query box lower X. [source:raw, field:this:0x00000000]
    // GUARD: Clamp upper X: v6 = min(this[0] + this[2], a2 + a4); the shared upper bound cannot exceed the query box upper X. [source:raw, field:this:0x00000004]
    // GUARD: Early-out: if v6 - v5 <= 0 the X intervals do not overlap; return false. [source:raw]
    // CALCULATION: Compute this box upper Y bound: v8 = this[1] + this[3] (min Y plus Y span at this+0x6). [source:raw, field:this:0x00000002, field:this:0x00000006]
    // GUARD: Clamp lower Y: v7 = max(this[1], a3); the shared lower bound cannot be below the query box lower Y. [source:raw, field:this:0x00000002]
    // GUARD: Clamp upper Y: v8 = min(this[1] + this[3], a3 + a5); the shared upper bound cannot exceed the query box upper Y. [source:raw, field:this:0x00000006]
    // RETURN: Return v8 - v7 > 0; both axes overlap only when the clamped Y span is also positive. [source:raw]

    // Conservative worker pseudocode:
    //   bool sub_491680(int16_t* this, int qMinX, int qMinY, int qW, int qH) {
    //     int minX = this[0];
    //     int maxX = minX + this[2];          /* this+0x4 * /
    //     if (minX <= qMinX) minX = qMinX;
    //     if (maxX >= qMinX + qW) maxX = qMinX + qW;
    //     if (maxX - minX <= 0) return false;
    //     int minY = this[1];
    //     int maxY = minY + this[3];         /* this+0x6 * /
    //     if (minY <= qMinY) minY = qMinY;
    //     if (maxY >= qMinY + qH) maxY = qMinY + qH;
    //     return maxY - minY > 0;
    //   }
    // UNRESOLVED: Field meaning of this[2] and this[3] as spans (width/height) is inferred from the addition to the minima; the AABB struct definition itself is not evidenced in the packet.
}
