// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E4930
// Canonical corpus name: VehiclePhysicsModeDispatcher
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehiclePhysicsModeDispatcher_004e4930.c

void UnknownObject::VehiclePhysicsModeDispatcher()
{
    // Routes vehicle physics processing by the mode flag at this+0x32BC. Mode 0 runs full initialization: PitStateUpdateMachine, VehiclePhysicsIntegrationStep seeded with the global at 0x007C7428, writes the input time to this+0x34AC, then VehicleSetupInitialization. Mode 1 runs sub-step integration: PitStateUpdateMachine followed by PhysicsIntegrationStateMachine. Mode 2 only records the input time to this+0x34AC and calls TeamColorLoader. Called by SceneObjectLoaderStateMachine (0x0040F1C0) and MainGameTickUpdate (0x0042C690).
    // GUARD: Read the physics mode flag at this+0x32BC and branch: 0 -> full init path, 1 -> sub-step path, 2 -> team-color path, anything else returns without action. [field:this:0x000032BC, caller:0x0040F1C0, caller:0x0042C690]
    // CALL: Mode 0: update the pit state machine at this+0x32C0 with input a2. [callee:0x004A6E50, source:raw]
    // CALL: Mode 0: run the full vehicle physics integration step, reading the double global at 0x007C7428 and passing the input time a2. [callee:0x00441650, global:0x007C7428]
    // ASSIGNMENT: Mode 0: store the input time a2 at this+0x34AC. [field:this:0x000034AC, source:raw]
    // CALL: Mode 0: initialize the vehicle setup from configuration via VehicleSetupInitialization and return its result. [callee:0x004E49B0, source:raw]
    // CALL: Mode 1: update the pit state machine at this+0x32C0 with input a2. [callee:0x004A6E50, source:raw]
    // CALL: Mode 1: run the sub-step physics integration state machine on input a2 and return its result. [callee:0x004E4E60, source:raw]
    // ASSIGNMENT: Mode 2: store the input value a2 at this+0x34AC. [field:this:0x000034AC, source:raw]
    // CALL: Mode 2: load team color/livery data via TeamColorLoader, passing the input value a2 (bit-cast as float), and return its result. [callee:0x004F03E0, source:raw]
    // RETURN: Return without action when the mode flag is neither 0, 1, nor 2. [source:raw, function:0x004E4930]

    // Conservative worker pseudocode:
    //   mode = *(this + 0x32BC);
    //   if (mode == 0) {
    //     PitStateUpdateMachine(this + 0x32C0, a2);
    //     VehiclePhysicsIntegrationStep(&dbl_7C7428, a2);
    //     *(this + 0x34AC) = a2;
    //     return VehicleSetupInitialization(this);
    //   }
    //   if (mode == 1) {
    //     PitStateUpdateMachine(this + 0x32C0, a2);
    //     return PhysicsIntegrationStateMachine(a2);
    //   }
    //   if (mode == 2) {
    //     *(this + 0x34AC) = a2;
    //     return TeamColorLoader(a2);
    //   }
    //   return result;
    // UNRESOLVED: The decompiled source bit-casts the a2 pointer into a float before storing at this+0x34AC and before passing to TeamColorLoader; whether a2 is truly a session/race time scalar or a mis-typed pointer is unverified.
    // UNRESOLVED: this+0x32C0 (pit state machine sub-object) has no per-field evidence ref in the packet.
    // UNRESOLVED: The global at 0x007C7428 (dbl_7C7428) is passed by address to VehiclePhysicsIntegrationStep; its role as race-time elapsed is DERIVED from the fill, not packet-confirmed.
}
