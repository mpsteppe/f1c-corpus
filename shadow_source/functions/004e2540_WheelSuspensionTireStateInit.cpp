// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E2540
// Canonical corpus name: WheelSuspensionTireStateInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WheelSuspensionTireStateInit_004e2540.c

void UnknownObject::WheelSuspensionTireStateInit()
{
    // Wheel suspension/tire state initializer. For wheel index a2 on 'this', computes the wheel offset vector as a3 minus the chassis local origin (this[18], this[19], this[20] at offsets 0x48, 0x4C, 0x50), stores it into two per-wheel blocks (base this[74*a2+82], and relative +184/+188/+192 within the wheel state), then writes the suspension parameters a4, a5, a6 (e.g. +252, +248, +200, +196, +204), builds a 3x3 rotation matrix from Euler angles a5/a6 via F_33RotationMatrixFromEulerAngles (0x5670D0), copies a 0x24-byte block from this[74*a2+105] into the wheel state, and returns RotationMatrixYAxisRotationEulerExtraction(a4, wheel_state+128) (0x567340). Called by SuspensionAndWheelPhysics (0x4E5F60).
    // CALCULATION: Compute the wheel state base pointer: this[74 * a2 + 53] (element index 53 within the per-wheel stride of 74 floats). [source:raw]
    // CALCULATION: Compute the wheel offset from the chassis local origin: v11 = *a3 - this[18], v12 = a3[1] - this[19], v13 = a3[2] - this[20], reading origin fields at offsets 0x48, 0x4C, 0x50. [field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050, source:raw]
    // ASSIGNMENT: Store the computed offset vector into the first per-wheel block at this[74 * a2 + 82] (three consecutive floats). [source:raw]
    // ASSIGNMENT: Store the same offset vector into the wheel state block at relative +184/+188/+192. [source:raw]
    // ASSIGNMENT: Store suspension parameters into the wheel state block: a4 at +252, a5 at +248 and +200. [source:raw]
    // ASSIGNMENT: Zero the DWORD at relative +196 and store a6 at relative +204 within the wheel state block. [source:raw]
    // CALL: F_33RotationMatrixFromEulerAngles(a5, a6) builds the 3x3 rotation matrix from the supplied Euler angles. [callee:0x005670D0, source:raw]
    // ASSIGNMENT: Copy a 0x24-byte block from this[74 * a2 + 105] into the wheel state at relative +140 (qmemcpy). [source:raw]
    // CALL: RotationMatrixYAxisRotationEulerExtraction(a4, wheel_state + 128) extracts the Y-axis rotation Euler angle for steering orientation. [callee:0x00567340, source:raw]
    // RETURN: Return the result of RotationMatrixYAxisRotationEulerExtraction. [callee:0x00567340, source:raw]
    // CALL: Invoked per wheel by SuspensionAndWheelPhysics (004E5F60). [caller:0x004E5F60]

    // Conservative worker pseudocode:
    //   float *wheel = &this[74 * a2 + 53];
    //   dx = *a3 - this[18]; dy = a3[1] - this[19]; dz = a3[2] - this[20];
    //   w = &this[74 * a2 + 82]; w[0] = dx; w[1] = dy; w[2] = dz;
    //   wheel[46] = dx; wheel[47] = dy; wheel[48] = dz;
    //   wheel[63] = a4; wheel[62] = a5; wheel[50] = a5;
    //   *(int*)(wheel + 49) = 0; wheel[51] = a6;
    //   F_33RotationMatrixFromEulerAngles(a5, a6);
    //   memcpy(wheel + 35, &this[74 * a2 + 105], 0x24);
    //   return RotationMatrixYAxisRotationEulerExtraction(a4, (int)wheel + 128);
    // UNRESOLVED: The per-wheel block offsets (relative +140..+252 and the this[74*a2+82] and this[74*a2+105] bases) have no packet field evidence refs; the wheel-state layout is not defined here.
    // UNRESOLVED: Semantic roles of parameters a4, a5, a6 (fill suggests camber/toe/caster) are not evidenced by the packet.
}
