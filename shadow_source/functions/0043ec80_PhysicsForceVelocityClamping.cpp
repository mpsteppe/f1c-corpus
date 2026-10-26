// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0043EC80
// Canonical corpus name: PhysicsForceVelocityClamping
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsForceVelocityClamping_0043ec80.c

void UnknownObject::PhysicsForceVelocityClamping()
{
    // Vehicle wheel/tyre physics step on a single double-array state object. Clamps two velocity/state doubles (double index 757, byte 0x17A8; index 760, byte 0x17C0) onto their reference limits (index 897, byte 0x1C08; index 898, byte 0x1C10), evaluates a quadratic force via QuadFunctionEval using the reference input at index 896 (byte 0x1C00), applies three bias clamps (index 769 toward index 900 plus 0.15, index 771 toward index 901 plus 0.12, index 888 toward index 902 plus 0.25), computes a spring-damper component via SpringDamperCompute, clamps two further states (double index 763; double index 766) onto their references (index 904; index 905), and evaluates a quadratic torque via QuadraticForceTorqueCalculator.
    // ASSIGNMENT: Clamp primary state (double index 757, byte 0x17A8) onto the reference limit (double index 897, byte 0x1C08). Two-branch conditional write; net effect assigns the reference value into the state slot. [field:this:0x000017A8, field:this:0x00001C08, source:raw]
    // ASSIGNMENT: Clamp secondary state (double index 760, byte 0x17C0) onto the reference limit (double index 898, byte 0x1C10). Same two-branch clamp pattern. [field:this:0x000017C0, field:this:0x00001C10, source:raw]
    // CALL: Call QuadFunctionEval(this, this[896]) to evaluate a quadratic force component from the reference input at double index 896 (byte 0x1C00). [callee:0x0043BB30, field:this:0x00001C00, source:raw]
    // CALCULATION: Bias clamp: compute double index 900 plus 0.15 and clamp double index 769 toward that value. Global 0x0059EB50 is reported read; existing analysis labels it InputScaleFactor (DERIVED) and it likely backs the 0.15 literal, but the binding is unconfirmed (GUESS). [global:0x0059EB50, source:raw]
    // CALCULATION: Bias clamp: compute double index 901 plus 0.12 and clamp double index 771 toward that value. Global 0x0059EC60 is reported read; existing analysis labels it SuspensionTravelOffset (DERIVED) and it likely backs the 0.12 literal, but the binding is unconfirmed (GUESS). [global:0x0059EC60, source:raw]
    // CALL: Call SpringDamperCompute(this, this[899]) to compute a spring-damper force component using the value at double index 899. [callee:0x0043BBD0, source:raw]
    // CALCULATION: Bias clamp: compute double index 902 plus 0.25 and clamp double index 888 toward that value. Global 0x0059EC90 is reported read; existing analysis labels it WearAccumulationRate (DERIVED) and it likely backs the 0.25 literal, but the binding is unconfirmed (GUESS). [global:0x0059EC90, source:raw]
    // ASSIGNMENT: Clamp double index 763 onto the reference at double index 904 using the two-branch clamp pattern. [source:raw]
    // ASSIGNMENT: Clamp double index 766 onto the reference at double index 905 using the two-branch clamp pattern. [source:raw]
    // CALL: Call QuadraticForceTorqueCalculator(this, this[903]) to compute the quadratic force/torque output from the value at double index 903. [callee:0x0043BB80, source:raw]

    // Conservative worker pseudocode:
    //   void PhysicsForceVelocityClamping(double* this) {
    //       // clamp state to reference (this[757] <- this[897]; this[760] <- this[898])
    //       QuadFunctionEval(this, this[896]);
    //       // bias clamps: this[769] toward this[900]+0.15; this[771] toward this[901]+0.12
    //       SpringDamperCompute(this, this[899]);
    //       // bias clamp: this[888] toward this[902]+0.25; clamps: this[763] <- this[904]; this[766] <- this[905]
    //       QuadraticForceTorqueCalculator(this, this[903]);
    //   }
    // UNRESOLVED: Read-only globals 0x0059EB50, 0x0059EC60, 0x0059EC90 are reported referenced but do not appear in the inlined raw source (only the literals 0.15/0.12/0.25 do). Existing analysis assigns them DERIVED roles (InputScaleFactor, SuspensionTravelOffset, WearAccumulationRate); the exact static binding to the bias literals is unconfirmed.
    // UNRESOLVED: Semantic meaning of the clamped state/limit field pairs (double indices 757/897, 760/898, 763/904, 766/905) is not resolved beyond velocity/state clamping.
}
