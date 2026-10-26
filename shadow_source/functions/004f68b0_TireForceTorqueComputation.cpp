// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F68B0
// Canonical corpus name: TireForceTorqueComputation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TireForceTorqueComputation_004f68b0.c

void UnknownObject::TireForceTorqueComputation()
{
    // Tire force/torque computation: when the enable byte field this+0x1EC is set, computes torque *a5 from a bias-scaled quadratic model of inputs a2/a3 and three force components a4[0..2] (two absolute-value terms and one quadratic term); when disabled, zeroes all four outputs. Returns the force output pointer a4.
    // GUARD: Enable guard: byte field this+0x1EC non-zero selects the compute path, zero selects the zero-output path under the thiscall ABI lead. [abi:lead, field:this:0x000001EC, source:raw]
    // ASSIGNMENT: Torque output *a5 = (a3 + bias field this+0x2E8) * scale field this+0x228 + a2*a2*field this+0x220 + a2*field this+0x218 + field this+0x210 (quadratic + bias model). [field:this:0x000002E8, field:this:0x00000228, field:this:0x00000220, field:this:0x00000218, field:this:0x00000210, source:raw]
    // ASSIGNMENT: Force component a4[0] = fabs(field this+0x250). [field:this:0x00000250, source:raw]
    // ASSIGNMENT: Force component a4[1] = fabs(field this+0x288). [field:this:0x00000288, source:raw]
    // ASSIGNMENT: Force component a4[2] = a2*a2*field this+0x208 + a2*field this+0x200 + field this+0x1F8 (quadratic in a2). [field:this:0x00000208, field:this:0x00000200, field:this:0x000001F8, source:raw]
    // ASSIGNMENT: Disabled path: zero torque *a5 and all force components a4[0..2]. [field:this:0x000001EC, source:raw]
    // RETURN: Return a4 (the force output pointer). [source:raw]

    // Conservative worker pseudocode:
    //   float* sub_4F68B0(int this, float a2, float a3, float* a4, float* a5) {
    //     if (*(char*)(this + 0x1EC)) {
    //       *a5 = (a3 + *(double*)(this + 0x2E8)) * *(double*)(this + 0x228)
    //           + a2 * *(double*)(this + 0x220) * a2
    //           + a2 * *(double*)(this + 0x218)
    //           + *(double*)(this + 0x210);
    //       *a4 = fabs(*(double*)(this + 0x250));
    //       a4[1] = fabs(*(double*)(this + 0x288));
    //       a4[2] = a2 * *(double*)(this + 0x208) * a2 + a2 * *(double*)(this + 0x200) + *(double*)(this + 0x1F8);
    //     } else {
    //       *a5 = 0.0; *a4 = 0.0; a4[1] = 0.0; a4[2] = 0.0;
    //     }
    //     return a4;
    //   }
    // UNRESOLVED: Physical meaning of the model constants (fields 0x1F8-0x228, 0x250, 0x288, 0x2E8) as force/torque coefficients is inferred from caller names (WheelForceAggregate, CollisionEnergy, SuspensionAndWheelPhysics), not proven.
    // UNRESOLVED: Whether a2 represents a speed/slip quantity and a3 a load/vertical quantity is not established.
}
