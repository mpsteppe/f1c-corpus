// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053BCE0
// Canonical corpus name: ForceScaleCalculation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ForceScaleCalculation_0053bce0.c

void UnknownObject::ForceScaleCalculation()
{
    // Computes a 4-lane SSE vector product and writes it to a3. Lane components are per-axis direction components of a1 scaled by the a1[9] magnitude (a1[6]/a1[7]/a1[8] multiplied by a1[9]), multiplied by per-axis constants from a2 (a2[17]/a2[18]/a2[19]) and by a fixed 255.0f (0x437F0000) scale constant, then packed-multiplied via _mm_mul_ps. Linear straight-line function: no branches, no calls, no guards. ABI name Force_Scale_Calculation suggests a physics force scaling role, but the true object layout of a1/a2/a3 and the output's semantic use are not established.
    // CALCULATION: Build constant vector v3 with every 32-bit lane equal to 255.0f (0x437F0000); v9 is initialized from it and keeps a constant 255.0f in its fourth lane throughout. [source:raw]
    // CALCULATION: Assemble v9 from a2 scale lanes: v9[0]=a2[19], v9[1]=a2[18], v9[2]=a2[17], fourth lane remains 255.0f; snapshot to v4 before overwrite. [source:raw]
    // CALCULATION: Scale direction components of a1 by its magnitude: v6 = a1[8] * a1[9] (field this+0x20 times this+0x24), v7 = a1[7] * a1[9] (this+0x1C times this+0x24), v8 = a1[6] * a1[9] (this+0x18 times this+0x24). [source:raw, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024]
    // CALCULATION: Reassemble v9 with v9[0]=v6, v9[1]=v7, v9[2]=v8 (low dword of high 64-bit lane), fourth lane still 255.0f. [source:raw]
    // CALCULATION: Write a3 = _mm_mul_ps(_mm_mul_ps(v9, v4), v3): per-lane product so lane0 = a1[8]*a1[9]*a2[19]*255, lane1 = a1[7]*a1[9]*a2[18]*255, lane2 = a1[6]*a1[9]*a2[17]*255, lane3 = 255^3. SSE intrinsic, not an external call. [source:raw]
    // RETURN: Return a3 (the output vector pointer) to the caller. [source:raw, function:0x0053BCE0]

    // Conservative worker pseudocode:
    //   // a1: per-axis direction/magnitude source (this base)
    //   // a2: per-axis scale constants (indices 17..19)
    //   // a3: output vector
    //   float k = 255.0f;                 // 0x437F0000, fixed scale constant
    //   float vx = a1[8] * a1[9];         // this+0x20 * this+0x24
    //   float vy = a1[7] * a1[9];         // this+0x1C * this+0x24
    //   float vz = a1[6] * a1[9];         // this+0x18 * this+0x24
    //   a3[0] = vx * a2[19] * k;
    //   a3[1] = vy * a2[18] * k;
    //   a3[2] = vz * a2[17] * k;
    //   a3[3] = k * k * k;
    //   return a3;
    // UNRESOLVED: Semantic purpose of the output vector (force scaling per ABI name Force_Scale_Calculation) is DERIVED from the ABI lead only; not independently confirmed.
    // UNRESOLVED: Static facts list globals flt_59E440 and flt_59FEC8 as read by this function, but the raw decompilation (source:raw) inlines every scaling constant as an immediate and shows no direct global access; the two globals are not attributed to any operation.
    // UNRESOLVED: Whether a1, a2 and a3 are vehicle-struct fields, per-driver buffers, or standalone arrays is unknown; only a1's float lanes map to field offsets this+0x18..0x24.
    // UNRESOLVED: Meaning of the fixed 255.0f scale constant is unknown; it may fold a 0-1 to 0-255 conversion but that is not evidenced.
    // UNRESOLVED: Purpose of the constant fourth lane (255.0f cubed) in a3 is unknown.
}
