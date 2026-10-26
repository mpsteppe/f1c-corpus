// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048EA60
// Canonical corpus name: RectangleBoundsCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RectangleBoundsCheck_0048ea60.c

void UnknownObject::RectangleBoundsCheck()
{
    // __thiscall point-in-rectangle hit test. Reads the rectangle origin x (this+0x14) and y (this+0x18) and extents (this+0xC, this+0x10), then returns 1 when point (a2, a3) is strictly inside the axis-aligned rectangle (a2 > x, a2 < x + width, a3 > y, a3 < y + height); returns 0 otherwise. Existing analysis labels the fields as left (0x14), top (0x18), width (0xC), height (0x10).
    // ASSIGNMENT: Read the rectangle x origin v3 = this[5] at field this+0x14. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Seed the default result to 0. [source:raw]
    // GUARD: X-bounds guard: require a2 > v3 and a2 < v3 + this[3], where this[3] (field this+0xC) is the rectangle width; failure falls through to return 0. [field:this:0x00000014, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Read the rectangle y origin v4 = this[6] at field this+0x18. [field:this:0x00000018, source:raw]
    // GUARD: Y-bounds guard: require a3 > v4 and a3 < v4 + this[4], where this[4] (field this+0x10) is the rectangle height; failure falls through to return 0. [field:this:0x00000018, field:this:0x00000010, source:raw]
    // RETURN: Return 1 when the point is inside both x and y bounds. [source:raw]
    // RETURN: Return the pre-seeded result 0 when either guard fails. [source:raw]
    // UNKNOWN: Hit-test used by BoundsCheckWithPositionQuery (0x004773A0), UIWidgetProcessChildren (0x00490450) and PanelMouseInteractionHandler (0x00490550) for mouse/position hit testing. [caller:0x004773A0, caller:0x00490450, caller:0x00490550, source:raw]

    // Conservative worker pseudocode:
    //   bool RectangleBoundsCheck(int* this, int px, int py) {
    //     int x = this[5];  // this+0x14
    //     int y = this[6];  // this+0x18
    //     if (px > x && px < x + this[3] && py > y && py < y + this[4]) return true;
    //     return false;
    //   }
    // UNRESOLVED: Field semantics (left/top/width/height vs two corner points) come from existing analysis prose, not from the raw source; the raw source shows only that 0xC and 0x10 are added to the 0x14/0x18 origins.
    // UNRESOLVED: The bounds are exclusive on the upper edge (a2 < x+width), so an exact on-edge point is not inside.
    // UNRESOLVED: Owning object type and how the rectangle fields are initialized are unknown.
    // UNRESOLVED: The existing-analysis name PointInRectHitTest is not independently confirmed.
}
