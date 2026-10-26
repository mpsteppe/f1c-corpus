// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CBDD0
// Canonical corpus name: RaySphereIntersection
// Owner: CollisionMathUtility [DERIVED]
// Raw source: functions/RaySphereIntersection_004cbdd0.c

void CollisionMathUtility::RaySphereIntersection()
{
    // 3D ray-sphere collision routine with sliding response. Computes a vector from the ray point advanced by a3 along direction a2 to the sphere center a4, scaled by coefficient dword_5D3488. If the squared length of that vector is below threshold flt_5D348C, computes the ray-sphere intersection distance (sqrt of a discriminant minus a dot-product term) and, when it is positive, slides the ray origin a1 forward to the contact point by t_hit * a2. Operates on float triplets; returns void.
    // ASSIGNMENT: Scale direction components a2[1] and a2[2] by coefficient dword_5D3488 and subtract from sphere center a4 to form part of the relative vector. [global:0x005D3488, source:raw]
    // CALCULATION: Build relative vector v12/v14/v17 = advanced ray point (a1 moved by a3 * a2) minus the scaled sphere center a4. [global:0x005D3488, source:raw]
    // GUARD: If squared length of the relative vector (v17*v17 + v14*v14 + v12*v12) is not below flt_5D348C, skip the intersection test. [global:0x005D348C, source:raw]
    // CALCULATION: Compute t = dot(relative vector, direction a2). [source:raw]
    // CALCULATION: Compute discriminant v7 = flt_5D348C - squared perpendicular distance from the sphere center to the ray. [global:0x005D348C, source:raw]
    // GUARD: If discriminant v7 is not greater than 0.0, the ray misses the sphere; skip the slide. [source:raw]
    // CALCULATION: Compute intersection distance t_hit = sqrt(discriminant) - t. [source:raw]
    // GUARD: If t_hit is not greater than 0.0, the intersection lies behind the ray origin; skip the slide. [source:raw]
    // ASSIGNMENT: Slide ray origin a1 to the contact point: a1[0..2] += t_hit * a2[0..2], updating offsets 0x0, 0x4 and 0x8. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]

    // Conservative worker pseudocode:
    //   v13 = dword_5D3488 * a2[1];
    //   v15 = dword_5D3488 * a2[2];
    //   v21 = a4[2] - v15;
    //   v12 = a1[0] - a3*a2[0] - (a4[0] - dword_5D3488*a2[0]);
    //   v14 = a1[1] - a3*a2[1] - (a4[1] - v13);
    //   v17 = a1[2] - a3*a2[2] - v21;
    //   if (v17*v17 + v14*v14 + v12*v12 < flt_5D348C) {
    //     t = v17*a2[2] + v14*a2[1] + v12*a2[0];
    //     d = flt_5D348C - perp_dist_sq(v12, v14, v17, a2, t);
    //     if (d > 0.0) {
    //       t_hit = sqrt(d) - t;
    //       if (t_hit > 0.0) a1[0..2] += t_hit * a2[0..2];
    //     }
    //   }
    // UNRESOLVED: global:0x0059E440 (flt_59E440) is listed as a read global but does not appear in the raw source text; its role in this routine is unknown.
    // UNRESOLVED: Semantics of parameter a3 (advance amount along the ray) are inferred, not evidenced.
    // UNRESOLVED: Exact meaning of coefficient dword_5D3488 (restitution per existing analysis) is DERIVED only.
    // UNRESOLVED: Whether flt_5D348C is the sphere radius squared or a penetration threshold is unproven.
}
