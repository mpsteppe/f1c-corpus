// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00491600
// Canonical corpus name: RectangleClampConstraint
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RectangleClampConstraint_00491600.c

void UnknownObject::RectClampToBounds()
{
    // Clamps a short[4] rectangle (x1=this+0x0, y1=this+0x2, width=this+0x4, height=this+0x6) in-place so it stays inside the boundary given by min (a2, a3) and max (a2+a4, a3+a5). When a corner moves inward the affected dimension shrinks; the right/bottom edges are additionally clamped to the bound, and the function returns the bottom bound.
    // GUARD: Clip the top edge: if y1 (this+0x2) < a3, reduce height (this+0x6) by (a3 - y1) and set y1 = a3. [field:this:0x00000002, field:this:0x00000006, source:raw]
    // GUARD: Clip the left edge: if x1 (this+0x0) < a2, reduce width (this+0x4) by (a2 - x1) and set x1 = a2. [field:this:0x00000000, field:this:0x00000004, source:raw]
    // CALCULATION: Clamp the right edge: if x1 + width + 1 (this+0x0 + this+0x4 + 1) exceeds a2 + a4 + 1, set width (this+0x4) to (a2 + a4 + 1) - x1. [field:this:0x00000000, field:this:0x00000004, source:raw]
    // CALCULATION: Clamp the bottom edge: if y1 + height (this+0x2 + this+0x6) exceeds a3 + a5, set height (this+0x6) to (a3 + a5) - y1. [field:this:0x00000002, field:this:0x00000006, source:raw]
    // RETURN: Return the bottom bound a3 + a5, already reduced to (a3 + a5) - y1 when the bottom edge was clamped. [source:raw, function:0x00491600]

    // Conservative worker pseudocode:
    //   void RectClampToBounds(__int16* rect, int a2, int a3, __int16 a4, int a5) {
    //     if (rect[1] < a3) { rect[3] -= a3 - rect[1]; rect[1] = (__int16)a3; }
    //     if (rect[0] < a2) { rect[2] -= a2 - rect[0]; rect[0] = (__int16)a2; }
    //     if (rect[0] + rect[2] + 1 > a2 + a4 + 1) rect[2] = (__int16)((a2 + a4 + 1) - rect[0]);
    //     int bottom = a3 + a5;
    //     if (rect[1] + rect[3] > bottom) { bottom -= rect[1]; rect[3] = (__int16)bottom; }
    //     return bottom;
    //   }
    // UNRESOLVED: The field semantics x1/y1/width/height are inferred from the clamp arithmetic; the short[4] struct's enclosing type is unknown.
    // UNRESOLVED: The a4/a5 extents are int arguments whose signedness and exact units are not established by this packet.
}
