// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051F160
// Canonical corpus name: F_4ComponentVectorNormalize
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_4ComponentVectorNormalize_0051f160.c

void UnknownObject::Vec4NormalizeNewtonRaphson()
{
    // Unconditionally normalizes a 4-component float vector using a Newton-Raphson refined reciprocal square root. Computes the squared length of the input a2 over all four components, computes v6 = 1/sqrt(v5), applies the refinement v7 = (dword_5D8A40 - v5*v6*v6) * dword_5D8A30 * v6, scales every input component by v7 into the output a1, and returns a1. No threshold guard.
    // CALCULATION: Compute the squared length v5 = a2[0]*a2[0] + a2[1]*a2[1] + a2[2]*a2[2] + a2[3]*a2[3] [source:raw]
    // CALCULATION: Compute v6 = 1.0 / fsqrt(v5), the reciprocal square root of the squared length [source:raw]
    // CALCULATION: Newton-Raphson refinement: v7 = (dword_5D8A40 - v5 * v6 * v6) * dword_5D8A30 * v6 [global:0x005D8A30, global:0x005D8A40]
    // ASSIGNMENT: Scale every input component by v7 into the output vector: a1[0] = a2[0]*v7, a1[1] = a2[1]*v7, a1[2] = a2[2]*v7, a1[3] = a2[3]*v7 [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C]
    // RETURN: Return the output vector pointer a1 [function:0x0051F160, source:raw]

    // Conservative worker pseudocode:
    //   v5 = a2[0]*a2[0] + a2[1]*a2[1] + a2[2]*a2[2] + a2[3]*a2[3];
    //   v6 = 1.0f / fsqrt(v5);
    //   v7 = (dword_5D8A40 - v5 * v6 * v6) * dword_5D8A30 * v6;
    //   a1[0] = a2[0]*v7; a1[1] = a2[1]*v7; a1[2] = a2[2]*v7; a1[3] = a2[3]*v7;
    //   return a1;
    // UNRESOLVED: The two read-only globals dword_5D8A30 and dword_5D8A40 (refinement coefficients per the skeleton fill) have no documented values or ownership in this packet
    // UNRESOLVED: The caller context for this standalone SSE math helper is not provided by the packet (no abi field, no callers)
}
