// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050E491
// Canonical corpus name: RayPlaneIntersect
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RayPlaneIntersect_0050e491.c

void UnknownObject::RayPlaneIntersect()
{
    // Ray-plane intersection. a2 is a plane (XYZ normal plus a2[3] plane-distance term), a3 is the ray origin, a4 the ray target. Computes dot products to form a denominator; returns NULL when the ray is parallel to the plane (denominator 0.0) or when the resulting t-value fails validation via ArithmeticComparison_a88f. Otherwise writes the interpolated intersection point O + t*(P-O) into a1 (three consecutive floats) and returns a1.
    // CALCULATION: Compute v4 = dot(plane normal a2, ray origin a3) = a2[0]*a3[0] + a2[1]*a3[1] + a2[2]*a3[2]. [abi:lead, source:raw]
    // CALCULATION: Compute denominator v5 = v4 - dot(plane normal a2, ray target a4) = v4 - (a2[0]*a4[0] + a2[2]*a4[2] + a2[1]*a4[1]). [source:raw]
    // GUARD: If v5 == 0.0 (ray parallel to plane, zero denominator), return NULL (no intersection). [source:raw]
    // CALCULATION: Compute t-value v7 = (v4 + a2[3]) / v5, combining the plane-distance term a2[3] with the dot products. [source:raw]
    // CALL: Call ArithmeticComparison_a88f on the computed t-value v7 to validate it. [callee:0x0058A88F, source:raw]
    // GUARD: If ArithmeticComparison_a88f returns false for v7, return NULL (t-value rejected). [source:raw]
    // ASSIGNMENT: Write intersection X to a1[0] = (a4[0] - a3[0]) * v7 + a3[0]. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write intersection Y to a1[1] = (a4[1] - a3[1]) * v7 + a3[1]. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write intersection Z to a1[2] = (a4[2] - a3[2]) * v7 + a3[2]. [field:this:0x00000008, source:raw]
    // RETURN: Return the intersection point pointer a1 on success, or NULL on the two rejection paths. [function:0x0050E491, source:raw]

    // Conservative worker pseudocode:
    //   v4 = dot(plane_normal(a2), ray_origin(a3));
    //   v5 = v4 - dot(plane_normal(a2), ray_target(a4));
    //   if (v5 == 0.0)
    //       return NULL; /* ray parallel to plane * /
    //   t = (v4 + plane_distance(a2[3])) / v5;
    //   if (!ArithmeticComparison_a88f(t))
    //       return NULL; /* t rejected * /
    //   out = ray_origin(a3) + t * (ray_target(a4) - ray_origin(a3));
    //   return out;
    // UNRESOLVED: Exact predicate and accepted range of ArithmeticComparison_a88f (e.g. clamped [0,1] segment check) not established from the raw source.
    // UNRESOLVED: Sign convention of the plane-distance term a2[3] relative to the plane normal not proven.
    // UNRESOLVED: Global flt_59E440 appears in packet evidence but is not referenced in the raw function body; it may be consumed inside ArithmeticComparison_a88f.
    // UNRESOLVED: Ownership: no class or subsystem evidence links this function to a specific object.
}
