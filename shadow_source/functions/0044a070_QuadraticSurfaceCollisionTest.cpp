// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044A070
// Canonical corpus name: QuadraticSurfaceCollisionTest
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QuadraticSurfaceCollisionTest_0044a070.c

void UnknownObject::QuadraticSurfaceCollisionTest()
{
    // Tests a ray/query against a quadratic surface defined by six double coefficients (A x*x, B x*z, C z*z, D x, E z, F). First performs a three-axis slab cull: for each axis the dot product of query direction components against the slab normal read from the this float table is compared to the slab bound at this+0x38, returning 0 when it falls short. Then evaluates the conic surface equation at the query point, computes the residual v6 = surface value - query target, and accepts the hit only when v6 <= the max threshold at a2+24 and |v6| < the current best distance at a2+32. On acceptance it records |v6| into a2+32 (nearest-hit update), stores this as the hit object pointer at a2+48, stores the surface value at a2+40, and returns 1. Part of the collision detection system invoked by BVHTreeTraversal and SpatialGridQuery.
    // LOOP: Three-axis slab cull: iterate slab data in the this float table; per axis test directionDot(normal) against the bound stored at this+0x38 and return 0 when the test fails. [field:this:0x00000034, field:this:0x00000038, source:raw]
    // CALCULATION: Evaluate conic surface v5 = (z * this[0x10] + x * this[0x0] + this[0x18]) * x + (z * this[0x8] + this[0x20]) * z + this[0x28] using the six double coefficients and query x (a2+0) and z (a2+16). [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, field:this:0x00000018, field:this:0x00000020, field:this:0x00000028, source:raw]
    // CALCULATION: Compute residual v6 = v5 - query target value read from a2+8. [source:raw]
    // GUARD: Return 0 when v6 > max threshold read from a2+24. [source:raw]
    // GUARD: Compute v8 = fabs(v6) and return 0 when v8 >= current best distance read from a2+32. [source:raw]
    // ASSIGNMENT: Write v8 into a2+32, recording the improved nearest-hit distance. [source:raw]
    // ASSIGNMENT: Write this as the hit object pointer into a2+48. [source:raw]
    // ASSIGNMENT: Write the evaluated surface value v5 into a2+40. [source:raw]
    // RETURN: Return 1 on an accepted hit, 0 on any rejected cull/range test. [source:raw]
    // CALL: Invoked from the frame-path callers BVHTreeTraversal (0x0044AA30) and SpatialGridQuery (0x0044C4C0). [caller:0x0044AA30, caller:0x0044C4C0, source:raw]

    // Conservative worker pseudocode:
    //   int QuadraticSurfaceCollisionTest(double *this, int query) {
    //     float *slab = (float *)this + 13;
    //     for (int i = 0; i < 3; i++, slab += 3)
    //       if (*(double *)query * slab[-1] + *(double *)(query + 16) * slab[0] < slab[1])
    //         return 0;
    //     double x = *(double *)query;
    //     double z = *(double *)(query + 16);
    //     double v5 = (z * this[2] + x * this[0] + this[3]) * x
    //               + (z * this[1] + this[4]) * z + this[5];
    //     double v6 = v5 - *(double *)(query + 8);
    //     if (v6 > *(double *)(query + 24)) return 0;
    //     double v8 = fabs(v6);
    //     if (v8 >= *(double *)(query + 32)) return 0;
    //     *(double *)(query + 32) = v8;
    //     *(void **)(query + 48) = this;
    //     *(double *)(query + 40) = v5;
    //     return 1;
    //   }
    // UNRESOLVED: The query structure a2 layout (point x/z at +0/+16, target at +8, thresholds at +24/+32, result fields at +40/+48) is inferred from the raw source but has no independent field evidence.
    // UNRESOLVED: The slab cull also reads additional this-relative float entries beyond 0x34 and 0x38 in the raw source, but the packet field list only covers those two; the unlisted slab data has no evidence ref.
    // UNRESOLVED: Coefficient ordering (A x*x, B x*z, C z*z, D x, E z, F) is DERIVED from existing analysis prose; only the six double coefficient positions are FACT from raw source.
    // UNRESOLVED: The hit object type stored at a2+48 is unknown (owner UnknownObject).
}
