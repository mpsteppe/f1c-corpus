// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00459070
// Canonical corpus name: SuspensionWheelForceCalculation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SuspensionWheelForceCalculation_00459070.c

void UnknownObject::SuspensionWheelForceCalculation()
{
    // Per-wheel suspension force solver. Reads the wheel position vector (this+0x0C..0x14), the flags byte at this+0x74 and the initialization flag at this+0xCC. On first use (flag bit 1 of this+0x74 clear, this+0xCC zero) it determines the suspension direction by evaluating the suspension spline object at this+0xB0 via GuardedFunctionWithFlagSet at two parameters and picks the candidate direction vector nearest to the contact point a2, storing the direction sign at this+0xAC as the -1.0f or +1.0f constant. The normal path scales the contact velocity magnitude a3 by the spring scale this+0xA8, multiplies by the stored direction and the time delta a4, adds the bias this+0xBC, evaluates the suspension spline, writes the resulting force vector through F_3VectorCopyToStruct, and derives the velocity as the finite difference of the moved position over the time delta before copying it via StructFieldCopy.
    // ASSIGNMENT: Read the position vector at this+0x0C..0x14 into locals v34/v35/v36 and load the spring scale v5 from this+0xA8. [field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x000000A8, source:raw]
    // GUARD: Branch on flag byte this+0x74 bit 1: clear selects the first-call direction-determination path, set selects the normal per-frame force computation. [field:this:0x00000074, source:raw]
    // GUARD: The direction-determination path runs only while the initialization flag this+0xCC is zero. [field:this:0x000000CC, source:raw]
    // CALL: Evaluate the suspension spline object at this+0xB0 with GuardedFunctionWithFlagSet(0.0), negate the returned vector to form candidate direction vector A; read the second spline parameter at this+0xB8 and evaluate GuardedFunctionWithFlagSet again to form candidate direction vector B. [callee:0x004582C0, field:this:0x000000B8, source:raw]
    // CALCULATION: Form the difference vectors (candidateA - a2) and (candidateB - a2) and compare their summed squared lengths; the candidate nearer to the contact point a2 wins. [source:raw]
    // ASSIGNMENT: Store the chosen direction sign at this+0xAC: the -1.0f float constant when the second candidate is nearer, otherwise the +1.0f constant. [field:this:0x000000AC, source:raw]
    // CALL: Copy the winning direction vector into the struct with F_3VectorCopyToStruct(this, v31), then clear the scratch vector and copy it with StructFieldCopy(this, v31); return this. [callee:0x00456110, callee:0x00456150, source:raw]
    // CALCULATION: Normal path: v5 = sqrt(|a3|^2) * *(this+0xA8); spline input v38 = v5 * *(this+0xAC) * a4 + *(this+0xBC). [field:this:0x000000A8, field:this:0x000000AC, field:this:0x000000BC, source:raw]
    // CALL: Evaluate the suspension spline at this+0xB0 with GuardedFunctionWithFlagSet(v38) and copy the returned force vector into the struct with F_3VectorCopyToStruct(this, v31). [callee:0x004582C0, callee:0x00456110, source:raw]
    // GUARD: If the time delta a4 is zero or negative, output a zero velocity; otherwise compute velocity = (new position - previous position) / a4 component-wise. [field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, source:raw]
    // CALCULATION: Negate the computed velocity components and write them into the struct with StructFieldCopy(this, v31); return this. [callee:0x00456150, source:raw]

    // Conservative worker pseudocode:
    //   DWORD* SuspensionWheelForceCalculation(int this, float* contact, float* velocity, int dt) {
    //     float scale = *(float*)(this + 0xA8);
    //     float px = *(float*)(this + 0x0C), py = *(float*)(this + 0x10), pz = *(float*)(this + 0x14);
    //     if ((*(BYTE*)(this + 0x74) & 2) == 0) {
    //       if (!*(BYTE*)(this + 0xCC)) {
    //         float* A = (float*)GuardedFunctionWithFlagSet(this + 0xB0, 0.0f);
    //         float ax = -A[0], ay = -A[1], az = -A[2];
    //         float* B = (float*)GuardedFunctionWithFlagSet(this + 0xB8, *(float*)(this + 0xB8));
    //         float bx = -B[0], by = -B[1], bz = -B[2];
    //         if ((bz-contact[2])*(bz-contact[2]) + (by-contact[1])*(by-contact[1]) + (bx-contact[0])*(bx-contact[0]) <
    //             (az-contact[2])*(az-contact[2]) + (ay-contact[1])*(ay-contact[1]) + (ax-contact[0])*(ax-contact[0]))
    //           *(DWORD*)(this + 0xAC) = -1082130432;
    //         else
    //           *(DWORD*)(this + 0xAC) = 1065353216;
    //       }
    //     } else {
    //       scale = sqrt(velocity[0]*velocity[0] + velocity[1]*velocity[1] + velocity[2]*velocity[2]) * *(float*)(this + 0xA8);
    //     }
    //     float v38 = scale * *(float*)(this + 0xAC) * *(float*)&dt + *(float*)(this + 0xBC);
    //     float* out = (float*)GuardedFunctionWithFlagSet(this + 0xB0, v38);
    //     float v31[3] = { out[0], out[1], out[2] };
    //     F_3VectorCopyToStruct((DWORD*)this, v31);
    //     if (*(float*)&dt <= 0.0f) { v31[0] = v31[1] = v31[2] = 0.0f; }
    //     else {
    //       float inv = 1.0f / *(float*)&dt;
    //       v31[0] = inv * (v31[0] - px); v31[1] = inv * (v31[1] - py); v31[2] = inv * (v31[2] - pz);
    //       v31[0] = -v31[0]; v31[1] = -v31[1]; v31[2] = -v31[2];
    //     }
    //     return StructFieldCopy((DWORD*)this, v31);
    //   }
    // UNRESOLVED: The three globals flt_59E43C, flt_59E440 and flt_59E670 are recorded as referenced but do not appear in the decompiled body text; they are likely physics constants consumed through GuardedFunctionWithFlagSet or inlined by the compiler.
    // UNRESOLVED: The suspension spline object pointer at this+0xB0 (source offset this+176) is not in the packet field list; its concrete type is unknown.
    // UNRESOLVED: The exact contract of GuardedFunctionWithFlagSet (spline evaluation) and what F_3VectorCopyToStruct / StructFieldCopy write into the struct is not resolved here.
}
