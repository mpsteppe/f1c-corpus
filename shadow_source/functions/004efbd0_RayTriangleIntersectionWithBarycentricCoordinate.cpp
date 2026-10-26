// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004EFBD0
// Canonical corpus name: RayTriangleIntersectionWithBarycentricCoordinate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RayTriangleIntersectionWithBarycentricCoordinate_004efbd0.c

void UnknownObject::RayTriangleIntersectionWithBarycentricCoordinate()
{
    // Ray-triangle intersection test that produces a ride-height delta. Transforms a triangle vertex (selected from a per-index vertex array on this) into world space using the object's 3x3 orientation matrix and position offset, computes two candidate ray-hit distances (a plane intersection distance and a helper-based distance), takes the larger, clamps it to 0.025, and returns the rest height at this[3371] minus the clamped delta. Returns the unmodified rest height when the intersection is behind the ray or beyond the clamp threshold.
    // ASSIGNMENT: Load two input vectors from a2 into locals: v30..v32 from a2+36/40/44 and a second vector from a2+48/52/56, then compute v25 as their dot product. [source:raw]
    // CALCULATION: Select the triangle vertex at this[3758 + 3 * dword(a2+20)] and rotate it by the 3x3 orientation matrix stored at this[3372..3380]. [field:this:0x000034B0, field:this:0x000034B4, field:this:0x000034B8, field:this:0x000034BC, field:this:0x000034C0, field:this:0x000034C4, field:this:0x000034C8, field:this:0x000034CC, field:this:0x000034D0, source:raw]
    // ASSIGNMENT: Translate the rotated vertex by the position offset this[3381..3383] to obtain the world-space triangle corner v33..v35. [field:this:0x000034D4, field:this:0x000034D8, field:this:0x000034DC, source:raw]
    // CALL: F_3DCrossProduct(this+3393, v4, &v27) computes a cross product used for the triangle plane, copied into v36..v38. [callee:0x004ED750, source:raw]
    // CALL: Vec3Add(this+3390, &v36, v39) sums vectors; the result is copied into v27..v29. [callee:0x004ED710, source:raw]
    // CALCULATION: Compute the plane-intersection denominator v14 by rotating v27..v29 through the 3x3 matrix at this[3372..3380] and dotting with the ray direction v30..v32. [field:this:0x000034B0, field:this:0x000034B4, field:this:0x000034B8, field:this:0x000034BC, field:this:0x000034C0, field:this:0x000034C4, field:this:0x000034C8, field:this:0x000034CC, field:this:0x000034D0, source:raw]
    // GUARD: If v14 equals 0.0 use a zero distance; otherwise set the first candidate distance v40 = (v35*v32 + v34*v31 + v33*v30 - v25) / v14. [source:raw]
    // CALL: RideHeightDelta(this, &v33) adjusts the candidate triangle corner in place. [callee:0x004EF680, source:raw]
    // CALCULATION: Rotate v33..v35 by the 3x3 matrix into v36..v38, then F_3DVectorAddition(&v36, this+3381) applies the position offset. [callee:0x004EC020, field:this:0x000034B0, field:this:0x000034B4, field:this:0x000034B8, field:this:0x000034BC, field:this:0x000034C0, field:this:0x000034C4, field:this:0x000034C8, field:this:0x000034CC, field:this:0x000034D0, field:this:0x000034D4, field:this:0x000034D8, field:this:0x000034DC, source:raw]
    // CALL: Second F_3DCrossProduct(this+3393, &v33, v39); the result is copied back into v33..v35. [callee:0x004ED750, source:raw]
    // CALL: Second Vec3Add(this+3390, &v33, v39) into v27..v29, then F_33MatrixVectorMultiply(v3, &v27, v39) applies the 3x3 matrix. [callee:0x004ED710, callee:0x004ED7B0, source:raw]
    // CALL: sub_4EFEE0 computes two signed distances: v26 = sub_4EFEE0(&v36, &v30) - v25 and v22 = sub_4EFEE0(v39, &v30); the second candidate distance is v23 = v26/v22, or 0.0 when v22 equals 0.0. [callee:0x004EFEE0, source:raw]
    // CALCULATION: Take the maximum of the two candidate distances v40 and v23 as the final ride height delta. [source:raw]
    // GUARD: If the delta is negative the ray misses the surface; return the rest height this[3371]. [field:this:0x000034AC, source:raw]
    // RETURN: Return rest height minus the clamped delta: this[3371] - v23 when within 0.025, otherwise this[3371] - 0.025. [field:this:0x000034AC, source:raw]

    // Conservative worker pseudocode:
    //   // Compute ride height delta against one triangle of an indexed triangle fan.
    //   corner = transform(triangleVertex(dword(a2+20)), orientMatrix[this+3372], position[this+3381]);
    //   denom  = dot(rotate(dir, orientMatrix), rayDir);
    //   hit1   = denom == 0.0 ? 0.0 : (dot(corner, rayDir) - dot(vec2, rayDir)) / denom;
    //   RideHeightDelta(this, &corner);
    //   distA = sub_4EFEE0(transform(corner, orientMatrix, position), &rayVec) - dot(vec2, rayDir);
    //   distB = sub_4EFEE0(...);
    //   hit2   = distB == 0.0 ? 0.0 : distA / distB;
    //   delta  = max(hit1, hit2);
    //   if (delta < 0.0)       return this[3371];
    //   if (delta <= 0.025)    return this[3371] - delta;
    //   return this[3371] - 0.025;
    // UNRESOLVED: Semantic meaning of the global floats flt_59E440 and flt_59E87C (physics constants) is not directly visible in the raw source; they are likely consumed inside RideHeightDelta or sub_4EFEE0.
    // UNRESOLVED: Exact behavior of sub_4EFEE0 (presumed signed distance along the ray) is unverified.
    // UNRESOLVED: The a2 input structure is only partially mapped; offsets 20, 36..56 are read but their field names are unknown.
}
