// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00567010
// Canonical corpus name: sub_567010
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_567010_00567010.c

void UnknownObject::QuaternionToEulerAngles()
{
    // Converts a quaternion held at this into a 3x3 rotation matrix via F_33RotationMatrixFromQuaternion (0x00566F40), then converts that matrix to Euler angles via RotationMatrixToEuler (0x00566EE0) and returns the result. A small math transform wrapper on the per-frame path, used by CollisionResponseFilter (0x004584C0) and AudioSampleCrossFadeInterpolation (0x004FF8F0).
    // CALL: Build a 3x3 rotation matrix v3[9] from the quaternion stored at this by calling F_33RotationMatrixFromQuaternion(this, v3). [callee:0x00566F40, source:raw]
    // CALL: Convert the rotation matrix v3 to Euler angles by calling RotationMatrixToEuler(v3, v1). [callee:0x00566EE0, source:raw]
    // RETURN: Return the Euler angle conversion result. [source:raw]
    // CALL: Called by CollisionResponseFilter (0x004584C0) and AudioSampleCrossFadeInterpolation (0x004FF8F0). [caller:0x004584C0, caller:0x004FF8F0, source:raw]

    // Conservative worker pseudocode:
    //   int QuaternionToEulerAngles(float *this) {
    //     float m[9];
    //     F_33RotationMatrixFromQuaternion(this, m);
    //     return RotationMatrixToEuler(m, /* arg2 uninitialized in raw source * / v1);
    //   }
    // UNRESOLVED: Second argument v1 to RotationMatrixToEuler is uninitialized in the raw decompiled source (decompiler artifact); the true parameter count and convention of RotationMatrixToEuler are unconfirmed.
    // UNRESOLVED: The packet's LEGACY ABI label File_Stream_Cleanup_Wrapper conflicts with the actual quaternion-to-Euler rotation content and is not reflected in the semantics.
}
