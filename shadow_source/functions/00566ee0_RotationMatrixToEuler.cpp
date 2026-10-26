// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00566EE0
// Canonical corpus name: RotationMatrixToEuler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RotationMatrixToEuler_00566ee0.c

void UnknownObject::RotationMatrixToEuler()
{
    // Extracts three Euler angles from a 3x3 row-major rotation matrix: writes the x-angle atan2(-a1[5], sqrt(a1[3]*a1[3] + a1[4]*a1[4])) to this+0, then branches on the FPU status flag (v2 & 0x4100) left by the sqrt. When the flag is set (near-zero cos component, gimbal lock), writes the y-angle atan2(-a1[6], a1[0]) to this+4 and zeroes this+8. Otherwise writes the y-angle atan2(a1[2], a1[8]) to this+4 and the z-angle atan2(a1[3], a1[4]) to this+8. Returns result = v2 & 0x4100 (non-zero when the singularity branch was taken).
    // CALCULATION: Writes the x-angle = atan2(-a1[5], sqrt(a1[3]*a1[3] + a1[4]*a1[4])) to the output buffer at this+0 [field:this:0x00000000, source:raw]
    // GUARD: Computes result = FPU status word & 0x4100 and branches when (v2 & 0x4100) != 0; the flag follows the sqrt in the x-angle computation and marks a near-zero cos component (gimbal lock) [source:raw]
    // ASSIGNMENT: Singularity branch: writes the y-angle = atan2(-a1[6], a1[0]) to this+4 and zeroes this+8 (z-angle) with a dword store [field:this:0x00000004, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Normal branch: writes the y-angle = atan2(a1[2], a1[8]) to this+4 and the z-angle = atan2(a1[3], a1[4]) to this+8 [field:this:0x00000004, field:this:0x00000008, source:raw]
    // RETURN: Returns result = v2 & 0x4100, non-zero when the singularity branch was taken [function:0x00566EE0, source:raw]

    // Conservative worker pseudocode:
    //   *(float *)(out + 0) = atan2(-m[5], sqrt(m[3]*m[3] + m[4]*m[4]));
    //   if (fpu_status & 0x4100) {
    //       *(float *)(out + 4) = atan2(-m[6], m[0]);
    //       *(unsigned int *)(out + 8) = 0;
    //   } else {
    //       *(float *)(out + 4) = atan2(m[2], m[8]);
    //       *(float *)(out + 8) = atan2(m[3], m[4]);
    //   }
    //   return fpu_status & 0x4100;
    // UNRESOLVED: Read global flt_5B8968 is listed in the packet but does not appear in the raw source text; its exact role (reported as EulerSingularityThreshold in the existing analysis) is unverified
    // UNRESOLVED: Axis-to-output mapping (which angle is pitch/yaw/roll) is inferred from the existing analysis, not from the raw source
}
