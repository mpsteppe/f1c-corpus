// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00569410
// Canonical corpus name: InertiaTensorWorldSpaceTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InertiaTensorWorldSpaceTransform_00569410.c

void UnknownObject::InertiaTensorWorldSpaceTransform()
{
    // Computes world-space angular acceleration from a torque vector as R * diag(1/I) * R^T * T. Reads the torque vector (0x7C, 0x84, 0x8C), the 3x3 rotation matrix (doubles at 0x1C..0x5C) and the diagonal inertia reciprocals (0xBC, 0xC4, 0xCC); writes the result vector at 0x94, 0x9C, 0xA4.
    // CALCULATION: Load the 3x3 rotation matrix R (doubles at 0x1C, 0x24, 0x2C, 0x34, 0x3C, 0x44, 0x4C, 0x54, 0x5C), the input torque vector T (0x7C, 0x84, 0x8C) and the diagonal inertia reciprocals (0xBC, 0xC4, 0xCC). [field:this:0x0000001C, field:this:0x00000024, field:this:0x0000002C, field:this:0x00000034, field:this:0x0000003C, field:this:0x00000044, field:this:0x0000004C, field:this:0x00000054, field:this:0x0000005C, field:this:0x0000007C, field:this:0x00000084, field:this:0x0000008C, field:this:0x000000BC, field:this:0x000000C4, field:this:0x000000CC]
    // CALCULATION: Compute the body-frame angular acceleration terms: v3 = (R^T*T)[0] * invIxx, v1 = (R^T*T)[1] * invIyy, v2 = (R^T*T)[2] * invIzz, each dot product mixing R columns with the torque components then scaled by one reciprocal inertia diagonal. [field:this:0x0000001C, field:this:0x00000024, field:this:0x0000002C, field:this:0x00000034, field:this:0x0000003C, field:this:0x00000044, field:this:0x0000004C, field:this:0x00000054, field:this:0x0000005C, field:this:0x0000007C, field:this:0x00000084, field:this:0x0000008C, field:this:0x000000BC, field:this:0x000000C4, field:this:0x000000CC]
    // ASSIGNMENT: Write world-space angular acceleration X at 0x94 as R00*v3 + R10*v1 + R20*v2. [field:this:0x00000094, field:this:0x0000001C, field:this:0x00000024, field:this:0x0000002C]
    // ASSIGNMENT: Write world-space angular acceleration Y at 0x9C as R01*v3 + R11*v1 + R21*v2. [field:this:0x0000009C, field:this:0x00000034, field:this:0x0000003C, field:this:0x00000044]
    // ASSIGNMENT: Write world-space angular acceleration Z at 0xA4 as R02*v3 + R12*v1 + R22*v2. [field:this:0x000000A4, field:this:0x0000004C, field:this:0x00000054, field:this:0x0000005C]

    // Conservative worker pseudocode:
    //   // alpha_body = diag(1/I) * (R^T * T);  alpha_world = R * alpha_body
    //   // terms (v3, v1, v2) are the three body-frame accelerations; outputs are R applied to them.
    // UNRESOLVED: The interleaved register order of v1/v2/v3 makes the exact per-component mapping (which product scales which output) a DERIVED reconstruction, not a direct reading.
    // UNRESOLVED: The 0xBC/0xC4/0xCC factors are treated as inverse-inertia diagonals following the enclosing inertia-tensor subsystem; the raw multiplication alone does not prove they are reciprocals.
    // UNRESOLVED: The function returns void; all effects are the three output field writes.
}
