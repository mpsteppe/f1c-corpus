// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005170C0
// Canonical corpus name: sub_5170C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5170C0_005170c0.c

void UnknownObject::InitSSEMathFunctionTable()
{
    // Unconditional function-pointer table initializer for an SSE math dispatch table. Fills the 34 used dword slots of the table at a1 with SSE math routines: vector sums and normalization, linear/cubic/hermite/bezier/bilinear spline interpolation, Newton-Raphson reciprocal and normalize refinement, 3x3 rotation-matrix multiply, triangle closest-point or normal, and vector blend/lerp. No guards and no callees; returns the table pointer a1. Invoked by sub_50FEA7 during dispatch-table setup.
    // ASSIGNMENT: Write SSE math dispatch routine slot 0 (byte offset 0x0) of the function-pointer table to sub_51EC00. [field:this:0x00000000, global:0x0051EC00]
    // ASSIGNMENT: Write SSE math dispatch routine slot 1 (byte offset 0x4) of the function-pointer table to sub_51ECE0. [field:this:0x00000004, global:0x0051ECE0]
    // ASSIGNMENT: Write SSE math dispatch routine slot 2 (byte offset 0x8) of the function-pointer table to sub_520140. [field:this:0x00000008, global:0x00520140]
    // ASSIGNMENT: Write SSE math dispatch routine slot 3 (byte offset 0xC) of the function-pointer table to sub_520200. [field:this:0x0000000C, global:0x00520200]
    // ASSIGNMENT: Write SSE math dispatch routine slot 4 (byte offset 0x10) of the function-pointer table to sub_51EF50. [field:this:0x00000010, global:0x0051EF50]
    // ASSIGNMENT: Write SSE math dispatch routine slot 5 (byte offset 0x14) of the function-pointer table to SSEWeightedVectorSum. [field:this:0x00000014, global:0x0051ECA0]
    // ASSIGNMENT: Write SSE math dispatch routine slot 6 (byte offset 0x18) of the function-pointer table to sub_51FF80. [field:this:0x00000018, global:0x0051FF80]
    // ASSIGNMENT: Write SSE math dispatch routine slot 7 (byte offset 0x1C) of the function-pointer table to sub_520350. [field:this:0x0000001C, global:0x00520350]
    // ASSIGNMENT: Write SSE math dispatch routine slot 8 (byte offset 0x20) of the function-pointer table to F_4ComponentVectorNormalize. [field:this:0x00000020, global:0x0051F160]
    // ASSIGNMENT: Write SSE math dispatch routine slot 9 (byte offset 0x24) of the function-pointer table to sub_51EC40. [field:this:0x00000024, global:0x0051EC40]
    // ASSIGNMENT: Write SSE math dispatch routine slot 10 (byte offset 0x28) of the function-pointer table to sub_520040. [field:this:0x00000028, global:0x00520040]
    // ASSIGNMENT: Write SSE math dispatch routine slot 11 (byte offset 0x2C) of the function-pointer table to sub_51F7C0. [field:this:0x0000002C, global:0x0051F7C0]
    // ASSIGNMENT: Write SSE math dispatch routine slot 13 (byte offset 0x34) of the function-pointer table to sub_520980. [field:this:0x00000034, global:0x00520980]
    // ASSIGNMENT: Write SSE math dispatch routine slot 16 (byte offset 0x40) of the function-pointer table to sub_5207C0. [field:this:0x00000040, global:0x005207C0]
    // ASSIGNMENT: Write SSE math dispatch routine slot 17 (byte offset 0x44) of the function-pointer table to HermiteSplineBasis. [field:this:0x00000044, global:0x0051F560]
    // ASSIGNMENT: Write SSE math dispatch routine slot 18 (byte offset 0x48) of the function-pointer table to sub_520500. [field:this:0x00000048, global:0x00520500]
    // ASSIGNMENT: Write SSE math dispatch routine slot 19 (byte offset 0x4C) of the function-pointer table to RotMatrixMul3x3. [field:this:0x0000004C, global:0x0051FBF0]
    // ASSIGNMENT: Write SSE math dispatch routine slot 20 (byte offset 0x50) of the function-pointer table to VectorNormalizeWithNewtonRaphsonRefinement. [field:this:0x00000050, global:0x0051FC80]
    // ASSIGNMENT: Write SSE math dispatch routine slot 21 (byte offset 0x54) of the function-pointer table to sub_520420. [field:this:0x00000054, global:0x00520420]
    // ASSIGNMENT: Write SSE math dispatch routine slot 22 (byte offset 0x58) of the function-pointer table to NewtonRaphsonReciprocalWithVectorInterpolation. [field:this:0x00000058, global:0x0051F700]
    // ASSIGNMENT: Write SSE math dispatch routine slot 24 (byte offset 0x60) of the function-pointer table to TriangleClosestPointOrNormal. [field:this:0x00000060, global:0x00520CE0]
    // ASSIGNMENT: Write SSE math dispatch routine slot 25 (byte offset 0x64) of the function-pointer table to sub_520E00. [field:this:0x00000064, global:0x00520E00]
    // ASSIGNMENT: Write SSE math dispatch routine slot 27 (byte offset 0x6C) of the function-pointer table to sub_520A70. [field:this:0x0000006C, global:0x00520A70]
    // ASSIGNMENT: Write SSE math dispatch routine slot 28 (byte offset 0x70) of the function-pointer table to sub_520C00. [field:this:0x00000070, global:0x00520C00]
    // ASSIGNMENT: Write SSE math dispatch routine slot 30 (byte offset 0x78) of the function-pointer table to sub_520870. [field:this:0x00000078, global:0x00520870]
    // ASSIGNMENT: Write SSE math dispatch routine slot 31 (byte offset 0x7C) of the function-pointer table to sub_5208F0. [field:this:0x0000007C, global:0x005208F0]
    // ASSIGNMENT: Write SSE math dispatch routine slot 47 (byte offset 0xBC) of the function-pointer table to SSECubicSplineInterpolation. [field:this:0x000000BC, global:0x0051F2C0]
    // ASSIGNMENT: Write SSE math dispatch routine slot 48 (byte offset 0xC0) of the function-pointer table to SSELinearInterpolationBetweenTwoPoints. [field:this:0x000000C0, global:0x0051F6A0]
    // ASSIGNMENT: Write SSE math dispatch routine slot 49 (byte offset 0xC4) of the function-pointer table to CubicSpline. [field:this:0x000000C4, global:0x0051F400]
    // ASSIGNMENT: Write SSE math dispatch routine slot 50 (byte offset 0xC8) of the function-pointer table to SSEHermiteCubicInterp. [field:this:0x000000C8, global:0x0051F200]
    // ASSIGNMENT: Write SSE math dispatch routine slot 51 (byte offset 0xCC) of the function-pointer table to F_3VectorBlendLerp. [field:this:0x000000CC, global:0x0051F5F0]
    // ASSIGNMENT: Write SSE math dispatch routine slot 52 (byte offset 0xD0) of the function-pointer table to SSECubicBezierBernsteinPolynomialEvaluation. [field:this:0x000000D0, global:0x0051F4C0]
    // ASSIGNMENT: Write SSE math dispatch routine slot 53 (byte offset 0xD4) of the function-pointer table to SSECubicHermiteBasisFunctionEvaluation. [field:this:0x000000D4, global:0x0051F350]
    // ASSIGNMENT: Write SSE math dispatch routine slot 54 (byte offset 0xD8) of the function-pointer table to BilinearInterpolation_f650. [field:this:0x000000D8, global:0x0051F650]
    // RETURN: Return the table pointer (result is an alias of a1). [function:0x005170C0, source:raw]
    // CALL: Invoked by sub_50FEA7; the packet reports no per-frame tick-root path, so the table is prepared during setup rather than per frame. [caller:0x0050FEA7, source:raw]

    // Conservative worker pseudocode:
    //   table[0] = sub_51EC00;
    //   table[1] = sub_51ECE0;
    //   table[2] = sub_520140;
    //   table[3] = sub_520200;
    //   table[4] = sub_51EF50;
    //   table[5] = SSEWeightedVectorSum;
    //   table[6] = sub_51FF80;
    //   table[7] = sub_520350;
    //   table[8] = F_4ComponentVectorNormalize;
    //   table[9] = sub_51EC40;
    //   table[10] = sub_520040;
    //   table[11] = sub_51F7C0;
    //   table[13] = sub_520980;
    //   table[16] = sub_5207C0;
    //   table[17] = HermiteSplineBasis;
    //   table[18] = sub_520500;
    //   table[19] = RotMatrixMul3x3;
    //   table[20] = VectorNormalizeWithNewtonRaphsonRefinement;
    //   table[21] = sub_520420;
    //   table[22] = NewtonRaphsonReciprocalWithVectorInterpolation;
    //   table[24] = TriangleClosestPointOrNormal;
    //   table[25] = sub_520E00;
    //   table[27] = sub_520A70;
    //   table[28] = sub_520C00;
    //   table[30] = sub_520870;
    //   table[31] = sub_5208F0;
    //   table[47] = SSECubicSplineInterpolation;
    //   table[48] = SSELinearInterpolationBetweenTwoPoints;
    //   table[49] = CubicSpline;
    //   table[50] = SSEHermiteCubicInterp;
    //   table[51] = F_3VectorBlendLerp;
    //   table[52] = SSECubicBezierBernsteinPolynomialEvaluation;
    //   table[53] = SSECubicHermiteBasisFunctionEvaluation;
    //   table[54] = BilinearInterpolation_f650;
    //   return a1;
    // UNRESOLVED: The owning object and the exact dispatch convention of the table are not evidenced; slot roles are inferred from routine names only.
    // UNRESOLVED: The table is filled unconditionally, so there is no CPU-feature guard as in the neighbouring 3DNow initializer; whether this table is the SSE counterpart of another dispatch table is not determinable from this packet.
}
