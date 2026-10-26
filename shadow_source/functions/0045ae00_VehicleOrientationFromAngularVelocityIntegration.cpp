// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045AE00
// Canonical corpus name: VehicleOrientationFromAngularVelocityIntegration
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleOrientationFromAngularVelocityIntegration_0045ae00.c

void UnknownObject::VehicleOrientationFromAngularVelocityIntegration()
{
    // Integrates vehicle angular velocity over an elapsed time step to update orientation. Guards on a per-object pointer/flag at offset 0xD0; when set, computes the time delta against a stored float timestamp at offset 0x24, scales it by three axis-input doubles at 0x138/0x140/0x148 and accumulates the result onto angular-velocity doubles at 0xD8/0xE0/0xE8, computes a second scaled rotation vector from doubles at 0x150/0x158/0x160, post-processes that vector via sub_56C020, extracts Euler angles from a rotation matrix copied from offset 240, and forwards the resulting body-state to sub_54B4D0. Returns the guard value unchanged when the guard is clear.
    // GUARD: Read the pointer/flag at this+0xD0; when zero, skip integration and return that value unchanged. [field:this:0x000000D0, source:raw]
    // CALCULATION: Compute elapsed time delta v3 = a2 (current time) minus the stored float timestamp at this+0x24. [field:this:0x00000024, source:raw]
    // CALCULATION: Scale the time delta by the three axis-input doubles at this+0x138, this+0x140 and this+0x148 into components v4/v15[1]/v15[2]. [field:this:0x00000138, field:this:0x00000140, field:this:0x00000148, source:raw]
    // CALCULATION: Accumulate the scaled components onto the angular-velocity doubles at this+0xD8, this+0xE0 and this+0xE8 into v16/v17/v18. [field:this:0x000000D8, field:this:0x000000E0, field:this:0x000000E8, source:raw]
    // CALCULATION: Compute a second scaled rotation vector v15[0..2] = time delta times the doubles at this+0x150, this+0x158 and this+0x160. [field:this:0x00000150, field:this:0x00000158, field:this:0x00000160, source:raw]
    // CALCULATION: Copy the 24-byte scaled vector into local buffer v20 and copy the 72-byte rotation matrix from this+240 into local buffer v19. [source:raw]
    // CALL: Call sub_56C020 on the scaled rotation vector buffer to post-process it. [callee:0x0056C020, source:raw]
    // CALCULATION: Read matrix element v19[5], negate it into v6, and invoke FloatConvertWrapper between the read and the subsequent angle extraction. [callee:0x00588570, source:raw]
    // GUARD: Gimbal-lock branch: when fabs(v19[5]) equals the 1.0 constant at 0x0059E420, extract pitch = atan2(-v19[6], v19[0]) and set yaw to the 0.0 constant at 0x0059E430. [global:0x0059E420, global:0x0059E430, source:raw]
    // CALCULATION: General branch: extract pitch = atan2(v19[2], v19[8]) and yaw = atan2(v19[3], v19[4]) from the rotation matrix. [source:raw]
    // CALL: Call sub_54B4D0 with the accumulated body-state floats v16/v17/v18 (as v9/v10/v11) and the extracted angles v12/v13/v14, forwarding the integrated orientation. [callee:0x0054B4D0, source:raw]
    // RETURN: Return the result of sub_54B4D0, or the guard value when the guard was clear. [source:raw]

    // Conservative worker pseudocode:
    //   int VehicleOrientationFromAngularVelocityIntegration(int this, float a2) {
    //     int result = *(int*)(this + 0xD0);
    //     if (result) {
    //       double d = a2 - *(float*)(this + 0x24);
    //       double v16 = d * *(double*)(this + 0x138) + *(double*)(this + 0xD8);
    //       double v17 = d * *(double*)(this + 0x140) + *(double*)(this + 0xE0);
    //       double v18 = d * *(double*)(this + 0x148) + *(double*)(this + 0xE8);
    //       double v[3];
    //       v[0] = d * *(double*)(this + 0x150);
    //       v[1] = d * *(double*)(this + 0x158);
    //       v[2] = d * *(double*)(this + 0x160);
    //       sub_56C020(v);
    //       double m[9]; qmemcpy(m, (const void*)(this + 240), sizeof(m));
    //       FloatConvertWrapper();
    //       double yaw, pitch;
    //       if (fabs(m[5]) == 1.0) { pitch = atan2(-m[6], m[0]); yaw = 0.0; }
    //       else { pitch = atan2(m[2], m[8]); yaw = atan2(m[3], m[4]); }
    //       return sub_54B4D0((int)v16, (int)v17, (int)v18, (int)-m[5], (int)pitch, (int)yaw);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Owner object class is unknown; all fields are accessed on this with no type evidence.
    // UNRESOLVED: Exact roles of sub_56C020 and FloatConvertWrapper (internal helpers) are not established.
    // UNRESOLVED: Meaning of the axis-input doubles at 0x138/0x140/0x148 versus the scaled rotation doubles at 0x150/0x158/0x160 is ambiguous.
    // UNRESOLVED: Whether sub_54B4D0 writes the orientation back to the same object is unproven.
    // UNRESOLVED: The rotation matrix copied from offset 240 has no packet field evidence ref; it is treated as part of the object's rotation state.
    // UNRESOLVED: The 1.0 and 0.0 constants referenced via dbl_59E420/dbl_59E430 are interpreted as gimbal-lock sentinels by reconstruction, not by direct evidence.
}
