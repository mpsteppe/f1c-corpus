// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00448F00
// Canonical corpus name: TriangleEdgeHalfPlaneComputation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TriangleEdgeHalfPlaneComputation_00448f00.c

void UnknownObject::TriangleEdgeHalfPlaneComputation()
{
    // Computes, for each of the three edges of a triangle, the half-plane coefficients (nx, ny, d) of the edge line in the (x, z) plane: nx = v_start.z - v_end.z, ny = v_end.x - v_start.x, d = ny * v_start.z + v_start.x * nx, where v_start and v_end are consecutive triangle vertices read from the pointer array held by this (this[0], this[2], this[4]). When the remaining (previous) vertex v_prev lies on the negative side of the plane (v_prev.z * ny + v_prev.x * nx < d), all three coefficients are negated so the plane faces inward. Each edge's constant term is then expanded by the normal length scaled by 0.001 (constant dbl_59EA08), giving the plane a small outward bias. Each edge's triple of doubles is written to the output buffer at a2 + 24 * i. No return value. Invoked by SATEdgeSeparationTest (0x004491C0).
    // LOOP: Loops over the three triangle edges (i = 0, 1, 2), producing one half-plane triple of doubles per edge at a2 + 24 * i [source:raw]
    // ASSIGNMENT: Reads the three vertex pointers held by this: v3 = this[2 * i] (edge start), v5 = this[2 * ((i + 1) mod 3)] (edge end, wraps to this[0] for i == 2), v7 = this[2 * ((i + 2) mod 3)] (remaining vertex, wraps to this[4] for i == 0) [source:raw]
    // CALCULATION: Computes edge half-plane coefficients from the two edge vertices: *v8 = v3.z - v5.z (nx), v8[1] = v5.x - v3.x (ny), v8[2] = ny * v3.z + v3.x * nx (d) [source:raw]
    // GUARD: If the remaining vertex v7 lies on the negative side (v7.z * v8[1] + v7.x * v8[0] < v8[2]), negates all three coefficients so the half-plane faces the triangle interior [source:raw]
    // CALCULATION: Expands the constant term by the scaled normal length: v8[2] += sqrt(v8[0]^2 + v8[1]^2) * 0.001, using the 0.001 constant from dbl_59EA08 [global:0x0059EA08, source:raw]
    // RETURN: Returns void; each edge's plane triple is written through the output pointer a2 + 24 * i for the caller SATEdgeSeparationTest (0x004491C0) [caller:0x004491C0, function:0x00448F00, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   for (i = 0; i < 3; ++i) {
    //       float* start = this[2*i];
    //       float* end   = this[2*((i+1)%3)];
    //       float* prev  = this[2*((i+2)%3)];
    //       double* out  = (double*)(a2 + 24*i);
    //       out[0] = start[3] - end[3];
    //       out[1] = end[0] - start[0];
    //       out[2] = out[1]*start[3] + start[0]*out[0];
    //       if (prev[3]*out[1] + prev[0]*out[0] < out[2]) {
    //           out[0] = -out[0]; out[1] = -out[1]; out[2] = -out[2];
    //       }
    //       out[2] += sqrt(out[0]*out[0] + out[1]*out[1]) * 0.001;
    //   }
    // UNRESOLVED: The exact vertex component layout (which float indices map to x and z) is inferred from the plane arithmetic, not stated by the packet
    // UNRESOLVED: The role of the 0.001 normal-length bias (plane thickness or edge tolerance) is not determinable from this packet alone
}
