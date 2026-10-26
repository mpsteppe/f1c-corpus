// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00463D50
// Canonical corpus name: UtilityFunction_3d50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_3d50_00463d50.c

void UnknownObject::WheelCollisionAndIntegrationDispatcher()
{
    // Wheel collision dispatch: reads a per-wheel threshold parameter v9 from a global float array (unk_5F0708, stride 4656 per index a2), runs CollisionTestWithThreshold against it, and when the collision test succeeds dispatches PhysicsIntegrationStep_e620 on the target context *this plus PhysicsFloatUpdateWithCompare on the wheel state. Returns the collision-test result. Vehicle physics, on the per-frame path; called by TeamColorLoader (004F03E0).
    // CALCULATION: Read the per-wheel threshold v9 = *(float*)&unk_5F0708 + 4656*a2 from a global float array indexed by a2 with a 4656-byte stride [source:raw]
    // CALL: CollisionTestWithThreshold(a4, a2, a3, v9, 0) tests the collision against the threshold v9 at index a2; the result is stored in v7 [callee:0x00500560, source:raw]
    // GUARD: If v7 is non-zero (collision test succeeded), run the physics integration and float update steps [source:raw]
    // CALL: PhysicsIntegrationStep_e620(*this, v6, a3) performs the wheel physics integration step against the dereferenced target context [callee:0x0045E620, field:this:0x00000000, source:raw]
    // CALL: PhysicsFloatUpdateWithCompare(a3, v9) updates the wheel physics float state using the threshold value [callee:0x005000E0, source:raw]
    // RETURN: Return v7, the collision-test result that gated the physics dispatch [source:raw]

    // Conservative worker pseudocode:
    //   char WheelCollisionAndIntegrationDispatcher(int* this, int a2, int a3, float a4) {
    //       float v9 = *((float*)&unk_5F0708 + 4656 * a2);
    //       char v7 = CollisionTestWithThreshold(a4, a2, a3, v9, 0);
    //       if (v7) {
    //           PhysicsIntegrationStep_e620(*this, v6, a3);
    //           PhysicsFloatUpdateWithCompare(a3, v9);
    //       }
    //       return v7;
    //   }
    // UNRESOLVED: Global float array unk_5F0708 is referenced by the raw source but absent from the packet globals list, so it has no dedicated evidence ref; the 4656-byte stride implies a per-wheel/per-object packed record
    // UNRESOLVED: v6 (edx) is passed as the second argument to PhysicsIntegrationStep_e620 without any explicit initialization in the decompiled code; it is register-derived
    // UNRESOLVED: The caller label 'TeamColorLoader' (0x004F03E0) does not obviously match the collision-dispatch behaviour, so the object ownership and true call-path context remain unclear
}
