// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D6830
// Canonical corpus name: CubicHermiteInterpolation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CubicHermiteInterpolation_004d6830.c

void UnknownObject::CubicHermiteInterpolation()
{
    // 1D cubic Hermite interpolation over a 32-byte-stride coefficient table. Computes the normalized parameter v7 = (a3 / a2) * *(double*)(this+8), converts it to a float index, clamps the index to the table entry count at this+16 (minus one), then evaluates ((c3*t + c2)*t + c1)*t + c0 with four double coefficients per entry starting at the table pointer this+20. Physics/vehicle subsystem on the per-frame path; called by CollisionContactGenerationAndFrictionResponse (00436870) and TireCompoundPerWheelPhysicsApplication (0043DA10).
    // CALCULATION: Compute the normalized parameter v7 = (a3 / a2) * *(double*)(this+8), scaling the input ratio by the table scale factor at offset 0x8 [field:this:0x00000008, source:raw]
    // CALL: sub_5895A2(v7) processes the parameter value; the float copy v8 = v7 is stored for index derivation [callee:0x005895A2, source:raw]
    // CALCULATION: Truncate the parameter to an unsigned table index v4 = (int)v8 [source:raw]
    // GUARD: Read the table entry count v5 = *(DWORD*)(this+16); if v4 >= v5, clamp v4 to v5 - 1 [field:this:0x00000010, source:raw]
    // CALCULATION: Evaluate the cubic polynomial ((c3*t + c2)*t + c1)*t + c0 from the 32-byte-stride coefficient table at *(DWORD*)(this+20), reading four doubles at table + 32*v4 + {0, 8, 16, 24} [field:this:0x00000014, source:raw]
    // RETURN: Return the cubic Hermite evaluation as a double [source:raw]

    // Conservative worker pseudocode:
    //   double CubicHermiteInterpolation(int this, double a2, double a3) {
    //       double v7 = (a3 / a2) * *(double*)(this + 8);
    //       sub_5895A2(v7);
    //       float v8 = (float)v7;
    //       unsigned int v4 = (unsigned int)v8;
    //       unsigned int v5 = *(DWORD*)(this + 16);
    //       if (v4 >= v5) {
    //           v4 = v5 - 1;
    //       }
    //       double* table = *(double**)(this + 20);
    //       double* row = table + 4 * v4;
    //       return (((row[0] * v7) + row[1]) * v7 + row[2]) * v7 + row[3];
    //   }
    // UNRESOLVED: The precise purpose of sub_5895A2 is unknown; the float copy v8 of v7 suggests a double-to-float narrowing used to obtain the integer index
    // UNRESOLVED: a2 (the denominator) has no zero guard in the raw source; the division a3 / a2 assumes a non-zero input
    // UNRESOLVED: The exact coefficient ordering (c0..c3) and the owning object type are unconfirmed
}
