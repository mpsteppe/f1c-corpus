// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004EA040
// Canonical corpus name: F_3DCollisionDetectionWithAABBTestAndContactResp
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DCollisionDetectionWithAABBTestAndContactResp_004ea040.c

void UnknownObject::AABBTestAndContactResponse()
{
    // Per-vehicle 3D collision contact computation. Transforms the queried contact point into vehicle-local space, performs an AABB overlap test against the vehicle bounds, iterates the packed collision-geometry list to find the closest penetrating vertex, computes contact normal and penetration depth, and writes the assembled contact response into an outgoing collision buffer.
    // ASSIGNMENT: Read the collision-request block a2: capture the partner ids/geometry words at a2+12, a2+16, a2+20, a2+24 and the state word at a2+28 into locals. [source:raw]
    // CALL: Query the contact point via sub_4EA930(&v64) and take its x/y/z components. [callee:0x004EA930, source:raw]
    // CALCULATION: Transform the contact point into vehicle-local coordinates using the orientation matrix this[3372..3380] (this+0x34B0..0x34D0). [field:this:0x000034B0, field:this:0x000034B4, field:this:0x000034B8, field:this:0x000034BC, field:this:0x000034C0, field:this:0x000034C4, field:this:0x000034C8, field:this:0x000034CC, field:this:0x000034D0, source:raw]
    // CALCULATION: Build the AABB test volume by combining this[459..461] (this+0x72C..0x734) with this[465..470] (this+0x744..0x758) plus the half-extent at a2+24. [field:this:0x0000072C, field:this:0x00000730, field:this:0x00000734, field:this:0x00000744, field:this:0x00000748, field:this:0x0000074C, field:this:0x00000750, field:this:0x00000754, field:this:0x00000758, source:raw]
    // GUARD: AABB overlap test: reject the contact when the local contact point falls outside the box on any of the three axes. [source:raw]
    // CALL: Obtain the packed collision-geometry list handle via LinkedListIndexedAccessor_c230(0) and read its total size with PackedArrayTotalSize. [callee:0x0054C230, callee:0x0054E100, source:raw]
    // LOOP: Iterate every packed geometry vertex, fetching each entry with PackedArrayIndexLookup. [callee:0x0054E120, source:raw]
    // CALCULATION: Transform each vertex into vehicle-local space, test it inside the AABB, and track the closest vertex by minimum squared distance. [source:raw]
    // CALCULATION: Compute penetration depth from this+0x3B70 minus the closest distance, clamp at zero, and derive the contact normal from the closest vertex position. [field:this:0x00003B70, source:raw]
    // CALL: Acquire the outgoing collision buffer via ArithmeticComparison_a010 and store the contact state (negative marker, request pointer, state word) into it. [callee:0x004EA010, source:raw]
    // CALCULATION: Write the contact normal and direction into the buffer, rotating through the orientation matrix this+0x34B4..0x34DC, and normalize the resulting vector. [field:this:0x000034B4, field:this:0x000034B8, field:this:0x000034C0, field:this:0x000034C4, field:this:0x000034CC, field:this:0x000034D0, field:this:0x000034D4, field:this:0x000034D8, field:this:0x000034DC, source:raw]
    // CALL: Run VehicleGeometryProximityTest on the assembled contact point/normal in the buffer. [callee:0x004ED420, source:raw]
    // CALL: Run VehicleProjectedPosition to apply the projected-contact correction to the contact data. [callee:0x005694E0, source:raw]
    // CALCULATION: Compute the final contact response: clamp the normal component, apply the 0.2 restitution factor to the impulse, and normalize the resulting direction into the buffer. [source:raw]
    // UNKNOWN: Invocation context: called per-frame from SwitchBasedStateHandler; identity function:0x004EA040. [caller:0x0040F380, function:0x004EA040, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4EA040(F1CVehicle* this, Request* a2, int a3, Output* a4) {
    //     ContactPoint p = sub_4EA930(&q);
    //     pLocal = RotateInv(p, this.orientation[0x34B0..0x34D0]);
    //     box = { min = this[0x72C..0x734], ref = this[0x744..0x758], half = a2->half };
    //     if (!InsideAABB(pLocal, box)) return;
    //     list = LinkedListIndexedAccessor_c230(0);
    //     best = +inf;
    //     for (i = 0; i < PackedArrayTotalSize(list); i++) {
    //       v = PackedArrayIndexLookup(i);
    //       vLocal = RotateInv(v + a4->offset, this.orientation);
    //       if (InsideAABB(vLocal, box) && len2(vLocal) < best) best = len2(vLocal), closest = vLocal;
    //     }
    //     if (best != +inf) {
    //       depth = max(this[0x3B70] - sqrt(best), 0);
    //       buf = ArithmeticComparison_a010();
    //       WriteContactNormal(buf, closest, depth, this.orientation);
    //       VehicleGeometryProximityTest(buf.point, buf.normal, ...);
    //       VehicleProjectedPosition(...);
    //       ComputeImpulse(buf, 0.2f);
    //     }
    //   }
    // UNRESOLVED: The six float globals (dbl_59E420, flt_59E43C, flt_59E440, flt_59E7E8, flt_59E84C, flt_59EAE0) are recorded as read in the skeleton facts but do not appear as named references in the decompiled C body; their role is not visible in the raw source.
    // UNRESOLVED: The a4 output block layout (offsets +4, +12, +20, +28) is inferred from how it is read here, not from an independent source.
    // UNRESOLVED: The exact geometry-list contents behind LinkedListIndexedAccessor_c230/PackedArrayIndexLookup are not resolved in this function.
}
