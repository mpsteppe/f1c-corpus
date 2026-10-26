// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004915A0
// Canonical corpus name: AABBOverlapTest
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AABBOverlapTest_004915a0.c

void UnknownObject::AABBContainmentCheck()
{
    // Returns 1 if the `this` AABB (x1, y1, width, height stored as four __int16) lies fully inside the boundary AABB given by (a2, a3, a4, a5): requires x1 >= a2 && x1 < a2+a4 and y1 >= a3 && y1 < a3+a5, then x1+width <= a2+a4 and y1+height <= a3+a5. Returns 0 otherwise. Called by sub_490D00 (00490D00) and CollisionBroadphaseTraversal (00491170), placing it in broadphase collision culling.
    // ASSIGNMENT: v5 = *this; load x1 from this+0x0; initialize result = 0. [field:this:0x00000000, function:0x004915A0, source:raw]
    // GUARD: If NOT (v5 >= a2 && v5 < a2 + a4) return 0; x1 must be within the boundary x-range. [field:this:0x00000000, function:0x004915A0, source:raw]
    // ASSIGNMENT: v6 = this[1]; load y1 from this+0x2. [field:this:0x00000002, function:0x004915A0, source:raw]
    // GUARD: If v6 >= a3 && v6 < a5 + a3 && v5 + this[2] <= a2 + a4 && v6 + this[3] <= a5 + a3, return 1; top-left inside boundary AND bottom-right not beyond boundary edges. [field:this:0x00000002, field:this:0x00000004, field:this:0x00000006, function:0x004915A0, source:raw]
    // RETURN: Return 0 when any containment condition fails. [function:0x004915A0, source:raw]

    // Conservative worker pseudocode:
    //   x1 = this[0];
    //   if (x1 < a2 || x1 >= a2 + a4)
    //     return 0;
    //   y1 = this[1];
    //   if (y1 >= a3 && y1 < a3 + a5
    //       && x1 + this[2] <= a2 + a4
    //       && y1 + this[3] <= a3 + a5)
    //     return 1;
    //   return 0;
    // UNRESOLVED: The caller sub_490D00 (00490D00) is unnamed; its role in the collision flow is unknown.
    // UNRESOLVED: Whether a4/a5 are widths or absolute right/bottom coordinates depends on the caller contract; the containment math uses them as widths (a2+a4).
}
