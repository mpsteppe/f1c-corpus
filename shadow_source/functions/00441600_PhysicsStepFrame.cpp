// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00441600
// Canonical corpus name: PhysicsStepFrame
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsStepFrame_00441600.c

void UnknownObject::PhysicsStepFrame()
{
    // Executes one physics step frame for a vehicle: shifts wheel-state history, runs the suspension wheel dynamics solver with a step value a2, processes two batch-iteration helpers over a suspension workspace at this + 1387 dwords, performs a minimum-finding iteration using a2, then copies suspension data to the physics sub-objects. No branches; the full sequence always runs.
    // CALL: WheelStateHistoryShift(this) shifts the wheel state history buffers for this vehicle. [callee:0x004412F0]
    // CALL: SuspensionWheelDynamicsSolver(this, a2) solves wheel suspension dynamics for this vehicle using the step value a2. [callee:0x0043F7F0]
    // CALL: sub_56ECF0(this + 1387) is a batch-iteration helper applied to the suspension workspace located at this + 1387 dwords. [callee:0x0056ECF0, source:raw]
    // CALL: sub_56EE40(this + 1387) is a second batch-iteration helper applied to the same suspension workspace. [callee:0x0056EE40, source:raw]
    // CALL: IterateAndFindMinimumValueFromFunction(a2) performs a minimum-value search via an iteration function using the step value a2. [callee:0x0056F090]
    // CALL: PhysicsSubObjectFree(this) copies the suspension data into the physics sub-objects. [callee:0x00441450]
    // CALL: Invoked per-frame as the core physics step by VehiclePhysicsIntegrationStep (0x00441650). [caller:0x00441650]

    // Conservative worker pseudocode:
    //   void sub_441600(int *this, double a2) {
    //     WheelStateHistoryShift(this);
    //     SuspensionWheelDynamicsSolver((int)this, a2);
    //     sub_56ECF0(this + 1387);
    //     sub_56EE40(this + 1387);
    //     IterateAndFindMinimumValueFromFunction(a2);
    //     PhysicsSubObjectFree(this);
    //   }
    // UNRESOLVED: Identity and purpose of the two batch-iteration helpers sub_56ECF0 / sub_56EE40 and of IterateAndFindMinimumValueFromFunction are not recoverable from this packet.
    // UNRESOLVED: Exact meaning of the step value a2 (time delta or iteration count) is caller-defined and unknown here.
}
