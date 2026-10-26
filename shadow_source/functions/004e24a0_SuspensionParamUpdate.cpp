// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E24A0
// Canonical corpus name: SuspensionParamUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SuspensionParamUpdate_004e24a0.c

void UnknownObject::SuspensionParamUpdate()
{
    // thiscall per-wheel suspension parameter update. For wheel index a2 (per-wheel stride 74 floats): computes the ride-height offset v5 = a3 - this[19] (offset 0x4C) and stores it into two per-wheel slots, computes the new damper angle a5 + this[74*a2+115], stores the steering angle a4 into the wheel state, and — only when the damper angle actually changed — saves the new angle and rebuilds the 3x3 rotation matrix via F_33RotationMatrixFromEulerAngles. Then copies a 0x24-byte block within the wheel state and returns RotationMatrixYAxisRotationEulerExtraction(a4, wheel_state+128). Called per wheel by VehiclePhysicsTimeStep and sub_4F0430.
    // CALCULATION: Compute ride-height offset v5 = a3 - this[19], reading the chassis reference height field at offset 0x4C. [field:this:0x0000004C, source:raw]
    // ASSIGNMENT: Store the ride-height offset v5 into two per-wheel slots: this[74*a2+83] and this[74*a2+100]. [source:raw]
    // CALCULATION: Compute the new damper angle v7 = a5 + this[74*a2+115] and stage it as v12. [source:raw]
    // GUARD: Set the change flag v9 = (v7 == this[74*a2+103]); when the new damper angle equals the stored angle, the rotation-matrix rebuild is skipped. [source:raw]
    // ASSIGNMENT: Store the steering angle a4 into this[74*a2+116]. [source:raw]
    // STATE_TRANSITION: When the damper angle changed (!v9): save the new angle this[74*a2+103] = v12 and rebuild the 3x3 rotation matrix from the damper Euler angles via F_33RotationMatrixFromEulerAngles(v12, this[74*a2+104]). [callee:0x005670D0, source:raw]
    // ASSIGNMENT: Copy a 0x24-byte block within the wheel state: qmemcpy(wheel_state+140, wheel_state+208, 0x24). [source:raw]
    // CALL: RotationMatrixYAxisRotationEulerExtraction(a4, wheel_state+128) extracts the Y-axis rotation Euler angle for the steering orientation. [callee:0x00567340, source:raw]
    // RETURN: Return the result of RotationMatrixYAxisRotationEulerExtraction. [callee:0x00567340, source:raw]
    // CALL: Invoked per wheel by VehiclePhysicsTimeStep and sub_4F0430. [caller:0x004C73F0, caller:0x004F0430]

    // Conservative worker pseudocode:
    //   v5 = a3 - this[19];
    //   this[74*a2 + 83]  = v5;
    //   this[74*a2 + 100] = v5;
    //   v7 = a5 + this[74*a2 + 115];
    //   v8 = (int)&this[74*a2 + 53];
    //   v12 = v7;
    //   v9 = (v7 == this[74*a2 + 103]);
    //   this[74*a2 + 116] = a4;
    //   if (!v9) { this[74*a2 + 103] = v12; F_33RotationMatrixFromEulerAngles(v12, this[74*a2 + 104]); }
    //   qmemcpy((void*)(v8 + 140), (const void*)(v8 + 208), 0x24);
    //   return RotationMatrixYAxisRotationEulerExtraction(a4, v8 + 128);
    // UNRESOLVED: The per-wheel stride (74 floats) and the relative offsets inside the wheel-state block (base this[74*a2+53], +103, +104, +115, +116, +128, +140, +208) are DERIVED from the raw source; the packet does not name the wheel-state fields.
    // UNRESOLVED: The semantic roles of a4 (steering angle) and a5 (damper angle increment) are DERIVED from the existing analysis; not independently evidenced by the packet.
    // UNRESOLVED: ABI lead is the legacy FAIL name; the owner object is unknown.
}
