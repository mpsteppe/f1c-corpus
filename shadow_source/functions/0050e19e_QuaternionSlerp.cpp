// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050E19E
// Canonical corpus name: QuaternionSlerp
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QuaternionSlerp_0050e19e.c

void UnknownObject::QuaternionSlerp()
{
    // Spherical linear interpolation between quaternions a2 and a3 with factor a4 in [0,1], writing the result to a1 (x,y,z,w). Computes the dot product v7 = a2[0]*a3[0] + a2[2]*a3[2] + a2[1]*a3[1] + a2[3]*a3[3] and flips a3's sign (v14 = -1.0) when the dot is negative to take the shortest path. When 1.0 - |dot| <= 0.00000011920929 the quaternions are nearly parallel and the code falls back to linear interpolation weights v5 = 1 - a4 and v10 = a4; otherwise it computes theta = atan2(sqrt(1 - v8^2), v8) and the trig weights v5 = sin(theta*(1 - a4))/sin(theta), v10 = sin(theta*a4)/sin(theta). The final components are a1[i] = v5 * a2[i] + (v10 * v14) * a3[i]. All four output components are written unconditionally, so an external poke to the output does not persist.
    // CALCULATION: Compute the dot product v7 = a2[0]*a3[0] + a3[2]*a2[2] + a3[1]*a2[1] + a3[3]*a2[3]. [source:raw]
    // GUARD: Choose the shortest-path sign: v14 = -1.0 when v7 < 0.0, otherwise v14 = 1.0; then v8 = v14 * v7. [source:raw]
    // GUARD: When 1.0 - v8 <= 0.00000011920929 the quaternions are nearly parallel: skip the trigonometric branch and use linear-interpolation weights v5 = 1.0 - a4 and v10 = a4 to avoid dividing by near-zero sin(theta). [source:raw]
    // CALCULATION: Otherwise compute v9 = sqrt(1.0 - v8*v8), theta = atan2(v9, v8), v13 = 1.0 / v9, then the trig weights v5 = sin(theta * v5) * v13 and v10 = sin(theta * a4) * v13. [source:raw]
    // ASSIGNMENT: Write the interpolated components with v11 = v10 * v14: a1[0] = v5 * a2[0] + v11 * a3[0], a1[1] = v11 * a3[1] + v5 * a2[1], a1[2] = v11 * a3[2] + v5 * a2[2], a1[3] = v11 * a3[3] + v5 * a2[3]. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // RETURN: Return the output quaternion pointer a1. [function:0x0050E19E, source:raw]

    // Conservative worker pseudocode:
    //   float* QuaternionSlerp(float* a1, float* a2, float* a3, float t) {
    //     float dot = a2[0]*a3[0] + a2[1]*a3[1] + a2[2]*a3[2] + a2[3]*a3[3];
    //     float sign = (dot < 0.0f) ? -1.0f : 1.0f;
    //     float d = sign * dot;
    //     float wA, wB;
    //     if (1.0f - d <= 0.00000011920929f) {
    //       wA = 1.0f - t;
    //       wB = t;
    //     } else {
    //       float s = sqrt(1.0f - d*d);
    //       float theta = atan2(s, d);
    //       float invs = 1.0f / s;
    //       wA = sin(theta * (1.0f - t)) * invs;
    //       wB = sin(theta * t) * invs;
    //     }
    //     float wBs = wB * sign;
    //     a1[0] = wA*a2[0] + wBs*a3[0];
    //     a1[1] = wA*a2[1] + wBs*a3[1];
    //     a1[2] = wA*a2[2] + wBs*a3[2];
    //     a1[3] = wA*a2[3] + wBs*a3[3];
    //     return a1;
    //   }
    // UNRESOLVED: The packet lists read-only globals flt_59E43C (0x0059E43C), flt_59E440 (0x0059E440) and flt_5AC9C0 (0x005AC9C0); the raw source renders their loads as the folded literals 1.0, 0.0 and 0.00000011920929, but the exact global-to-literal mapping is DERIVED and unproven.
    // UNRESOLVED: This packet has no callees, so the trigonometric library functions (sin, cos, sqrt, atan2) called by the computation are not evidenced here.
    // UNRESOLVED: The shortest-path convention (negating a3 when the dot is negative) is inferred from the sign flip v14, not named by any packet evidence.
}
