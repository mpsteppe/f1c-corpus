// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050E055
// Canonical corpus name: RotationVectorToQuaternion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RotationVectorToQuaternion_0050e055.c

void UnknownObject::RotationVectorToQuaternion()
{
    // Converts a rotation vector a2 (3-vector plus angle magnitude in a2[3]) into a quaternion-shaped output a1 whose scalar part is always written as 0.0. For angle >= 1.0 or near-singular sin(angle) the vector part is copied verbatim; otherwise the vector part is scaled by angle/sin(angle).
    // GUARD: If a2[3] >= 1.0 (angle magnitude threshold), skip the sin-scaled path and copy the input vector part verbatim. [source:raw, function:0x0050E055]
    // CALL: FloatFunctionPassThrough() is invoked before computing sin(angle); its effect is not evident from the raw source. [callee:0x005894A0, source:raw]
    // CALCULATION: Compute v7 = sin(angle), then derive the scale factor v6 = angle / v7 when the near-zero check passes. [source:raw, function:0x0050E055]
    // GUARD: FloatRangeCheck(sin(angle), 0.0) detects a near-singular angle; when it reports the sine as zero, the vector part is copied verbatim instead of scaled. [callee:0x0050C042, source:raw]
    // ASSIGNMENT: Verbatim path: copy the input vector into the output a1[0]=a2[0], a1[1]=a2[1], a1[2]=a2[2]. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Scaled path: write the vector part of the output as angle/sin(angle) times the input vector (a1[0], a1[1], a1[2]). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // ASSIGNMENT: On both paths the scalar part of the output is written as a1[3] = 0.0. [field:this:0x0000000C, source:raw]
    // RETURN: Return the output pointer a1. [function:0x0050E055, source:raw]

    // Conservative worker pseudocode:
    //   float* RotationVectorToQuaternion(float* out, float* in) {
    //       float angle = in[3];
    //       float s;
    //       if (angle >= 1.0f) {
    //           out[0] = in[0]; out[1] = in[1]; out[2] = in[2];
    //       } else {
    //           FloatFunctionPassThrough();
    //           s = sin(angle);
    //           if (!FloatRangeCheck(s, 0.0)) {
    //               float scale = angle / s;
    //               out[0] = scale * in[0]; out[1] = scale * in[1]; out[2] = scale * in[2];
    //           } else {
    //               out[0] = in[0]; out[1] = in[1]; out[2] = in[2];
    //           }
    //       }
    //       out[3] = 0.0f;
    //       return out;
    //   }
    // UNRESOLVED: Global 0x0059E43C (flt_59E43C) is listed in the packet evidence but does not appear in the raw source text; its role in this function is unknown.
    // UNRESOLVED: FloatFunctionPassThrough is called immediately before sin() but its behavior is opaque in the raw source.
}
