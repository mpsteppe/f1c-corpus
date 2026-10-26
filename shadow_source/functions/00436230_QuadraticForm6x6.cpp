// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00436230
// Canonical corpus name: QuadraticForm6x6
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QuadraticForm6x6_00436230.c

void UnknownObject::QuadraticForm6x6()
{
    // Evaluates a 3-axis quadratic form: for each axis, selects one of two 3-element rows of the coefficient matrix `this` based on the sign of the input component a2[i], scales the row by a2[i]^2, and accumulates the result into a 3-element output copied to a4. Separately builds an anti-symmetric 3-element output a5 from coefficients this[18..20] scaled by a3[i]^2, negating each result when the corresponding a3 component is positive.
    // GUARD: Per axis, compare each a2[i] component against the zero literal (global 0x0059E430) to select the coefficient row: axis 0 picks row 0 or 1, axis 1 picks row 2 or 3, axis 2 picks row 4 or 5. [global:0x0059E430, source:raw]
    // CALCULATION: Accumulate a4 output: per axis, scale the selected 3-element row by a2[i]*a2[i] and sum the three axis contributions into the 3-element accumulator (offsets 0, 1, 2 within the local double[3]). [function:0x00436230, source:raw]
    // ASSIGNMENT: Copy the 3-element accumulator (0x18 bytes, 3 doubles) into the a4 output array via qmemcpy. [source:raw]
    // CALCULATION: Build a5 output: for each axis, a5[i] = this[18+i] * a3[i] * a3[i], then negate the stored value when a3[i] > 0.0, giving an anti-symmetric (sign-flipped) per-axis response. [field:this:0x00000090, field:this:0x00000098, field:this:0x000000A0, source:raw]

    // Conservative worker pseudocode:
    //   // sign-dependent quadratic form, 3-axis accumulation
    //   acc[0] = acc[1] = acc[2] = 0;
    //   for each axis i in 0..2:
    //       row = (a2[i] <= 0.0) ? this + 3*(2*i+1) : this + 3*(2*i);
    //       acc[0] += a2[i]*a2[i] * row[0];
    //       acc[1] += a2[i]*a2[i] * row[1];
    //       acc[2] += a2[i]*a2[i] * row[2];
    //   qmemcpy(a4, acc, 0x18);
    //   // anti-symmetric output
    //   for each axis i in 0..2:
    //       val = this[18+i] * a3[i] * a3[i];
    //       a5[i] = (a3[i] > 0.0) ? -val : val;
    // UNRESOLVED: Roles of a2/a3 and the physical meaning of the this+0x90/0x98/0xA0 coefficients (stiffness vs damping) are not grounded in the packet; the existing fill's 'compression stiffness' label for 0x90/0x98/0xA0 conflicts with their use as anti-symmetric a5 coefficients in the raw source.
    // UNRESOLVED: The coefficient rows this[0..17] are read by the raw source but have no packet field entries and therefore no evidence refs.
    // UNRESOLVED: Caller DamperSpringForceComputationWithAntiRoll confirms suspension-force context, but the exact frame usage is not derivable from this packet alone.
}
