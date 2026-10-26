// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00438100
// Canonical corpus name: TorqueForceProductComputation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TorqueForceProductComputation_00438100.c

void UnknownObject::TorqueForceProductComputation()
{
    // Single-step torque-force product computation on a vehicle-dynamics object. Multiplies the double at this+0x36C by the double at this+0x364 to form v1, stores the product at this+0x374, then writes this+0x22C = v1 * (double at this+0x38C) + (double at this+0x384). No guards; always executes. Part of the vehicle dynamics force-accumulation path (both packet callers are force-accumulation functions).
    // CALCULATION: v1 = *(double*)(this+0x36C) * *(double*)(this+0x364): multiply the multiplier input by the force input [field:this:0x0000036C, field:this:0x00000364, source:raw]
    // ASSIGNMENT: *(double*)(this+0x374) = v1: store the intermediate torque-force product [field:this:0x00000374, source:raw]
    // ASSIGNMENT: *(double*)(this+0x22C) = v1 * *(double*)(this+0x38C) + *(double*)(this+0x384): scale the product by the additional factor and add the bias term into the accumulated torque output [field:this:0x0000022C, field:this:0x0000038C, field:this:0x00000384, source:raw]
    // CALL: Called per-frame from VehicleDynamicsForceAccumulatorIntegration (00438130) and TireCompoundPerWheelPhysicsApplication (0043DA10) [caller:0x00438130, caller:0x0043DA10]

    // Conservative worker pseudocode:
    //   void TorqueForceProductComputation(this) {
    //     double v1 = *(double*)(this + 0x36C) * *(double*)(this + 0x364);
    //     *(double*)(this + 0x374) = v1;
    //     *(double*)(this + 0x22C) = v1 * *(double*)(this + 0x38C) + *(double*)(this + 0x384);
    //   }
    // UNRESOLVED: Physical meaning of each member (force input, multiplier, scaling factor, bias, outputs) is inferred from the existing fill analysis; the packet types no names
    // UNRESOLVED: Both outputs this+0x22C and this+0x374 are recalulated every frame per the fill's persistence note, so external pokes do not persist
    // UNRESOLVED: Owner class identity is not established by the packet
}
