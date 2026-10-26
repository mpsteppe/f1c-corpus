// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F1A60
// Canonical corpus name: LoopWithConditionalSubCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LoopWithConditionalSubCall_004f1a60.c

void UnknownObject::RunLoopWithConditionalSubCall()
{
    // Runs a fixed 4-iteration loop calling sub_4F18C0 on the this object with the loop index, the second argument a2 and a constant 0. After the loop, if the flag argument a3 is non-zero, invokes TireBrushModelForceSolver on the this object with 0. Called from five AI/vehicle-physics sites including AIMainUpdate, AISteeringRacingLineCorrection, PitStopOperationTimer and SuspensionAndWheelPhysics.
    // LOOP: Loop i from 0 to 3 inclusive, calling sub_4F18C0 with (this, i, a2, 0). [callee:0x004F18C0, source:raw]
    // GUARD: If a3 is non-zero, call TireBrushModelForceSolver with (this, 0). [callee:0x004E8010, source:raw]

    // Conservative worker pseudocode:
    //   for (i = 0; i < 4; ++i)
    //       sub_4F18C0(this, i, a2, 0);
    //   if (a3)
    //       TireBrushModelForceSolver(this, 0);
    // UNRESOLVED: Purpose of the 4-iteration sub_4F18C0 loop (per-wheel or per-subsystem setup) is not established by this packet's evidence.
    // UNRESOLVED: Meaning of the a2 argument and of the constant 0 passed to sub_4F18C0 is unknown.
    // UNRESOLVED: Meaning of the a3 flag and why TireBrushModelForceSolver is invoked only when it is set is unknown.
    // UNRESOLVED: Owner object is unconfirmed; evidence shows only a thiscalls convention and no owning class.
}
