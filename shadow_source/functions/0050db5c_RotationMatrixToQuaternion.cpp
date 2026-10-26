// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050DB5C
// Canonical corpus name: RotationMatrixToQuaternion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RotationMatrixToQuaternion_0050db5c.c

void UnknownObject::RotationMatrixToQuaternion()
{
    // Converts a 3x3 rotation sub-matrix (upper-left of a 4x4 column-major matrix a2) into a unit quaternion written to a1[0..3] (x, y, z, w). Uses the standard trace-based algorithm: when the matrix trace is positive the direct branch computes w from sqrt(trace+1) and x/y/z from off-diagonal differences; when trace <= 0 the largest-diagonal branch picks the largest diagonal component, computes it from sqrt(maxdiag+1) and derives the other two components and w from off-diagonal sums/differences, avoiding numerical instability near 180-degree rotations.
    // CALCULATION: Compute matrix trace v3 = a2[5] + a2[0] + a2[10] (diagonal m11+m00+m22 of the 4x4 column-major matrix). [source:raw]
    // GUARD: Branch on v3 <= 0.0: positive trace takes the direct formula with w largest; non-positive trace takes the largest-diagonal fallback. [source:raw]
    // CALCULATION: Largest-diagonal branch: compute the three diagonal candidates d0 = a2[0]-a2[5]-a2[10], d1 = a2[5]-a2[0]-a2[10], d2 = a2[10]-a2[5]-a2[0] and store them as floats v22/v23/v24. [source:raw]
    // GUARD: Select the largest of d0/d1/d2 via comparisons (v6 < v23, then against v24), recording its index v8/v27 in {0,1,2}. [source:raw]
    // CALCULATION: Compute the chosen quaternion component magnitude v13 = 0.5 * sqrt(diag_largest + 1) and the scale factor v14 = 0.25 / v13. [source:raw]
    // ASSIGNMENT: Write the largest quaternion component a1[largest_index] = v13. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write the remaining two vector components from off-diagonal matrix sums times v14 (a1[v11] and a1[v26]). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write w = (off-diagonal difference) * v14 into a1[3]. [field:this:0x0000000C, source:raw]
    // CALCULATION: Direct branch (trace > 0): v5 = 0.5 * sqrt(v3 + 1); write a1[3] = v5 as w. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Direct branch: a1[0] = (a2[6] - a2[9]) * (0.25 / v5), a1[1] = (a2[8] - a2[2]) * (0.25 / v5), a1[2] = (a2[1] - a2[4]) * (0.25 / v5). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // RETURN: Return the output quaternion pointer a1 (result). [source:raw]

    // Conservative worker pseudocode:
    //   float *RotationMatrixToQuaternion(float *q, const float *m) {
    //     double tr = m[5] + m[0] + m[10];
    //     if (tr <= 0.0) {
    //       double d[3] = { m[0]-m[5]-m[10], m[5]-m[0]-m[10], m[10]-m[5]-m[0] };
    //       int i = d[0] < d[1] ? 1 : 0;
    //       if (d[i] < d[2]) i = 2;
    //       int perm[3] = {1, 2, 0};
    //       q[i] = 0.5 * sqrt(d[i] + 1);
    //       double s = 0.25 / q[i];
    //       q[perm[i]] = (m[perm[i]*4 + i] + m[i*4 + perm[i]]) * s;
    //       q[perm[perm[i]]] = (m[perm[perm[i]] + perm[i]*4] + m[perm[perm[i]] + i*4]) * s;
    //       q[3] = (m[perm[i] + perm[perm[i]]*4] - m[perm[i] + perm[perm[i]]*4]) * s;
    //     } else {
    //       q[3] = 0.5 * sqrt(tr + 1);
    //       q[0] = (m[6] - m[9]) * (0.25 / q[3]);
    //       q[1] = (m[8] - m[2]) * (0.25 / q[3]);
    //       q[2] = (m[1] - m[4]) * (0.25 / q[3]);
    //     }
    //     return q;
    //   }
    // UNRESOLVED: Exact off-diagonal index arithmetic in the largest-diagonal branch (v11/v16/v18/v20/v26 permutation indices) is expressed directly in the pseudocode from the packet; the final difference term for w needs review against the raw source before relying on it.
    // UNRESOLVED: Packet lists four globals (flt_59E43C, flt_59E440, flt_59E450, flt_59E7F8) but the raw source reads no globals; the attribution appears inherited from skeleton cross-reference data rather than from this function's body.
    // UNRESOLVED: Convention of the quaternion output (left-handed vs right-handed, w last) is implied by the source's a1[3] usage but not proven.
}
