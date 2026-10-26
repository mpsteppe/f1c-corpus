// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044C550
// Canonical corpus name: CollisionNormalFromFeature
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionNormalFromFeature_0044c550.c

void UnknownObject::CollisionNormalFromFeature()
{
    // Queries the spatial grid for the collision feature containing a2; when a feature is found, derives an oriented collision normal from the feature's plane coefficients and writes it into the output vector a3. Returns the spatial-grid query result. Used by suspension force, orientation, tire contact and particle collision paths.
    // CALL: SpatialGridQuery(this, a2) looks up the collision feature associated with the query position a2; a non-null result drives the normal computation. [callee:0x0044C4C0]
    // GUARD: The collision normal is computed only when the spatial-grid query returns a non-null feature pointer. [callee:0x0044C4C0, source:raw]
    // CALCULATION: Assemble plane coefficients from a2 components and result elements [0..4]: v6 = a2.x*result[0] + a2.x*result[0] + a2.z*result[2] + result[3]; v7 = a2.z*result[1] + a2.z*result[1] + a2.x*result[2] + result[4]. [source:raw]
    // CALCULATION: Normalization: v8 = 1.0 / sqrt(v7*v7 + v6*v6 + 1.0); the 1.0 constant is supplied by the read global dbl_59E420 (the only plausible consumer of that read). [global:0x0059E420, source:raw]
    // ASSIGNMENT: Write the normalized collision normal into a3: a3[0] = -(v8*v6), a3[1] = v8, a3[2] = -(v8*v7). [source:raw]
    // RETURN: Return the spatial-grid query result pointer (the feature, or NULL when no feature was found). [function:0x0044C550, source:raw]

    // Conservative worker pseudocode:
    //   double *CollisionNormalFromFeature(double *this, double *a2, float *a3) {
    //     double *result = SpatialGridQuery(this, a2);
    //     if (result) {
    //       double v6 = a2[0]*result[0] + a2[0]*result[0] + a2[2]*result[2] + result[3];
    //       double v7 = a2[2]*result[1] + a2[2]*result[1] + a2[0]*result[2] + result[4];
    //       double v8 = 1.0 / sqrt(v7*v7 + v6*v6 + 1.0);
    //       a3[0] = -(v8*v6);
    //       a3[1] = v8;
    //       a3[2] = -(v8*v7);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: dbl_59E420 is read somewhere in this function but does not appear by name in the decompiled arithmetic; the 1.0 normalization constant is the only visible candidate consumer -- unverified.
    // UNRESOLVED: The layout of the feature plane returned by SpatialGridQuery (elements result[0..4]) is not enumerated as packet fields.
}
