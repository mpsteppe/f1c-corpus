// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E4910
// Canonical corpus name: CollisionWrapperWithLock
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionWrapperWithLock_004e4910.c

void UnknownObject::CollisionWrapperWithLock()
{
    // Thin wrapper around the tire-brush force solver and physics-node propagation: acquires the tire-brush model lock (TireBrushModelForceSolver(1)), runs PhysicsNodePropagationWithDistanceFalloff over the physics node set dword_5EA2C0 with a distance value and context argument, then releases the lock (TireBrushModelForceSolver(0)) and returns the solver result.
    // CALL: Acquire the tire-brush model lock via TireBrushModelForceSolver(1). [callee:0x004E8010]
    // CALL: Propagate physics nodes with distance falloff via PhysicsNodePropagationWithDistanceFalloff on the node set dword_5EA2C0, passing the distance and context arguments. [callee:0x00401C90, global:0x005EA2C0]
    // CALL: Release the tire-brush model lock via TireBrushModelForceSolver(0). [callee:0x004E8010]
    // RETURN: Return the tire-brush solver result (value of the release call). [function:0x004E4910, source:raw]
    // UNRESOLVED: Semantics of the distance argument (st0) and context argument (ecx) passed to PhysicsNodePropagationWithDistanceFalloff not resolved.
    // UNRESOLVED: Return value purpose (the release call's result) not resolved.
}
