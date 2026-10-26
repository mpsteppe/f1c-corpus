// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056C640
// Canonical corpus name: sub_56C640
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_56C640_0056c640.c

void UnknownObject::TriangleNormalCompute()
{
    // Computes the cross product of (a1 - a2) and (a3 - a2) into three doubles written to output a4, then normalizes by 1/sqrt(norm-squared). If norm-squared <= 0.0 (degenerate/collinear input) writes the double pattern 0.0, 1.0, 0.0 (1.0 encoded as dword 1072693248 at a4+12) and returns -1; otherwise returns 0. On the frame path, called by CollisionContactGenerationAndFrictionResponse (0x00436870) for collision contact face normal computation.
    // CALCULATION: v10 = *a1 - *a2, v11 = a1[1] - a2[1], v12 = a1[2] - a2[2]: per-component subtraction of the second triangle point (a2) from the first (a1), reading this+0x0, this+0x8, this+0x10 [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, source:raw]
    // CALCULATION: v13 = *a3 - *a2, v14 = a3[1] - a2[1], v15 = a3[2] - a2[2]: per-component subtraction of a2 from the third triangle point a3 [source:raw]
    // CALCULATION: Cross-product components stored to output: a4+0 = v4 = v11*v15 - v14*v12, a4+8 = v9 = v12*v13 - v10*v15, a4+16 = v5 = v14*v10 - v11*v13 [source:raw]
    // GUARD: v6 = v5*v5 + v9*v9 + v4*v4; if v6 <= 0.0 the three input points are degenerate/collinear (zero-sentinel constant dbl_59E430) [global:0x0059E430, source:raw]
    // STATE_TRANSITION: Degenerate branch: writes dwords a4+0=0, a4+4=0, a4+8=0, a4+12=1072693248, a4+16=0, a4+20=0 (doubles 0.0, 1.0, 0.0; 1.0 built from dbl_59E420) and returns -1 [global:0x0059E420, source:raw]
    // CALCULATION: Normalization: v8 = 1.0 / sqrt(v6) (1.0 from dbl_59E420); writes a4+0 = v4*v8, a4+8 = v9*v8, a4+16 = v5*v8 [global:0x0059E420, source:raw]
    // RETURN: Return 0 after successful normalization [source:raw]

    // Conservative worker pseudocode:
    //   v10 = a1[0] - a2[0]; v11 = a1[1] - a2[1]; v12 = a1[2] - a2[2];
    //   v13 = a3[0] - a2[0]; v14 = a3[1] - a2[1]; v15 = a3[2] - a2[2];
    //   out[0] = v11*v15 - v14*v12;
    //   out[1] = v12*v13 - v10*v15;
    //   out[2] = v14*v10 - v11*v13;
    //   v6 = out[0]*out[0] + out[1]*out[1] + out[2]*out[2];
    //   if (v6 <= 0.0) { out[0] = 0.0; out[1] = 1.0; out[2] = 0.0; return -1; }
    //   inv = 1.0 / sqrt(v6);
    //   out[0] *= inv; out[1] *= inv; out[2] *= inv;
    //   return 0;
    // UNRESOLVED: Degenerate-branch output is interpreted by existing analysis as an identity quaternion (0,0,0,1); the written byte pattern is doubles 0.0, 1.0, 0.0, so component ordering (x/y/z/w) is not established.
    // UNRESOLVED: dbl_59E420 / dbl_59E430 appear as constants in the decompiled body only indirectly (compiler literal pool); their binding here is DERIVED.
}
