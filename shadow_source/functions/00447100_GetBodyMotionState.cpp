// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00447100
// Canonical corpus name: GetBodyMotionState
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GetBodyMotionState_00447100.c

void UnknownObject::GetBodyMotionState()
{
    // Vehicle suspension query accessor. Calls SuspensionSpringDamperForceComputationWithClampi with the body pointer at this+0x1EC and the rigid-body state read from this+0x15F0, writing into two local result vectors v4 and v5. Copies v4 into output float array a2 and v5 into output float array a3, then returns a3. Called by sub_4F0430 (004F0430) on the per-frame path.
    // CALL: Call SuspensionSpringDamperForceComputationWithClampi with the body pointer (this+0x1EC), the rigid-body state dword read from this+0x15F0, and local result vectors v4/v5 [callee:0x00435E60, field:this:0x000015F0, source:raw]
    // ASSIGNMENT: a2[0..2] = v4[0..2]: copy the first three result elements into output array a2 [source:raw]
    // ASSIGNMENT: result = a3: set the return value to the second output array [source:raw]
    // ASSIGNMENT: a3[0..2] = v5[0..2]: copy the second three result elements into output array a3 [source:raw]
    // RETURN: Return result (output array a3) [source:raw]
    // CALL: Invoked from sub_4F0430 (004F0430) on the per-frame tick path [caller:0x004F0430]

    // Conservative worker pseudocode:
    //   float *GetBodyMotionState(int this, float *a2, float *a3) {
    //     double v4[3];
    //     long double v5[3];
    //     SuspensionSpringDamperForceComputationWithClampi((char *)(this + 492), *(_DWORD *)(this + 5616), v4, v5);
    //     a2[0] = v4[0]; a2[1] = v4[1]; a2[2] = v4[2];
    //     a3[0] = v5[0]; a3[1] = v5[1]; a3[2] = v5[2];
    //     return a3;
    //   }
    // UNRESOLVED: The body pointer at this+0x1EC (offset 492) is passed to the callee but is not a packet-listed field; only this+0x15F0 has field evidence.
    // UNRESOLVED: Whether v4 is a force vector and v5 a torque vector is DERIVED from the existing analysis; the raw source gives no semantic labels for the result vectors.
}
