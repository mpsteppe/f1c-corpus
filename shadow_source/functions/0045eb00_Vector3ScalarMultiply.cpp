// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045EB00
// Canonical corpus name: Vector3ScalarMultiply
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Vector3ScalarMultiply_0045eb00.c

void UnknownObject::Vector3ScalarMultiply()
{
    // Multiplies each of the three float components of the input vector (this+0, this+4, this+8) by a scalar a3 and stores the results into the output vector a2 (a2+0, a2+4, a2+8). Returns the output pointer a2. No guards, no calls. On the frame path; invoked by PhysicsIntegrationStep_e620 (0045E620) and VehicleContactForceAccumulation (004EBC60) as a vector scaling helper.
    // ASSIGNMENT: Compute the three scaled components from the input vector fields: v5 = a3 * this[0], v6 = a3 * this[1], v4 = a3 * this[2] [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write the scaled components into the output vector a2: *a2 = v5, a2[1] = v6, a2[2] = v7 [source:raw]
    // RETURN: Return result = a2, the pointer to the output vector [source:raw]
    // CALL: Invoked by PhysicsIntegrationStep_e620 (0045E620) and VehicleContactForceAccumulation (004EBC60); on the frame path [caller:0x0045E620, caller:0x004EBC60, source:raw]

    // Conservative worker pseudocode:
    //   float* Vector3ScalarMultiply(float* this, float* a2, float a3) {
    //     a2[0] = a3 * this[0];
    //     a2[1] = a3 * this[1];
    //     a2[2] = a3 * this[2];
    //     return a2;
    //   }
    // UNRESOLVED: this is read-only (the source vector) while a2 is the destination; whether callers ever alias them (in-place scale) is not resolvable from this packet
    // UNRESOLVED: The fields this+0/+4/+8 are the float components of a 3-vector; the component order (X/Y/Z) is not proven
    // UNRESOLVED: The FPU-only handling of the Z component (v4/v7) has no behavioral difference and is treated as a compiler artifact
}
