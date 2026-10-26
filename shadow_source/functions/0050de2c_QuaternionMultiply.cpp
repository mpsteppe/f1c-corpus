// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050DE2C
// Canonical corpus name: QuaternionMultiplication
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QuaternionMultiplication_0050de2c.c

void UnknownObject::QuaternionMultiply()
{
    // Quaternion Hamilton product: multiplies quaternion a3 (left) by quaternion a2 (right) and stores the result into a1, which is returned. Each operand is a float[4] in (x, y, z, w) layout with the scalar term at index 3; the result's scalar component a1[3] is a3[3]*a2[3] minus the vector dot product, matching a standard quaternion product. Straight-line __stdcall helper with no branches, globals, guards or calls.
    // CALCULATION: Compute output x component: a1[0] = a3[3]*a2[0] + a3[0]*a2[3] + a3[1]*a2[2] - a3[2]*a2[1] (Hamilton product vector x: w3*v2.x + w2*v3.x + (v3 cross v2).x). [field:this:0x00000000, source:raw]
    // CALCULATION: Compute output y component: a1[1] = a3[3]*a2[1] - a3[0]*a2[2] + a3[1]*a2[3] + a3[2]*a2[0] (Hamilton product vector y: w3*v2.y + w2*v3.y + (v3 cross v2).y). [field:this:0x00000004, source:raw]
    // CALCULATION: Compute output z component: a1[2] = a3[3]*a2[2] + a3[0]*a2[1] - a3[1]*a2[0] + a3[2]*a2[3] (Hamilton product vector z: w3*v2.z + w2*v3.z + (v3 cross v2).z). [field:this:0x00000008, source:raw]
    // CALCULATION: Compute output scalar component: a1[3] = a3[3]*a2[3] - a3[0]*a2[0] - a3[1]*a2[1] - a3[2]*a2[2] (w3*w2 minus the vector dot product). [field:this:0x0000000C, source:raw]
    // RETURN: Return a1, the output quaternion pointer (the this object). [function:0x0050DE2C, source:raw]

    // Conservative worker pseudocode:
    //   float *QuaternionMultiply(float *a1, const float *a2, const float *a3) {
    //     a1[0] = a3[3] * a2[0] + a3[0] * a2[3] + a3[1] * a2[2] - a3[2] * a2[1];
    //     a1[1] = a3[3] * a2[1] - a3[0] * a2[2] + a3[1] * a2[3] + a3[2] * a2[0];
    //     a1[2] = a3[3] * a2[2] + a3[0] * a2[1] - a3[1] * a2[0] + a3[2] * a2[3];
    //     a1[3] = a3[3] * a2[3] - a3[0] * a2[0] - a3[1] * a2[1] - a3[2] * a2[2];
    //     return a1;
    //   }
    // UNRESOLVED: Owner class or subsystem of this free __stdcall math helper is unknown; no class evidence in the packet.
    // UNRESOLVED: Quaternion interpretation (float[4] with scalar at index 3) is inferred from the arithmetic pattern; layout and whether a3/a2 are ordered (a3 then a2) is not independently confirmed.
    // UNRESOLVED: Callers and the coordinate/rotation convention in which these quaternions are used are unknown; no caller evidence in the packet.
    // UNRESOLVED: The packet prelabel relates this function to the F_4DAffineTransform cluster (0050c525); the affine-transform relationship is not confirmed by this function's arithmetic.
}
