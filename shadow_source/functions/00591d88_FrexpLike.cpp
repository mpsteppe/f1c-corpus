// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00591D88
// Canonical corpus name: sub_591D88
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_591D88_00591d88.c

void UnknownObject::FrexpLike()
{
    // Double splitter in the style of frexp: given a double a1, writes the base-2 exponent into *a2 and returns the normalized mantissa. Handles zero, subnormals (via an explicit normalization loop seeded at exponent -1021), and the normal branch (exponent recovered as (mantissa-field >> 4 & 0x7FF) - 1022). Both nonzero branches call FloatBitManipulation(a1, 0) to build the returned mantissa. Called by sub_5919DA.
    // GUARD: If a1 == 0.0, take the zero branch: exponent 0, mantissa 0.0. [source:raw, function:0x00591D88]
    // GUARD: If a1 is a subnormal (exponent field of a1 is 0 and the mantissa bits are nonzero), take the normalization branch. [source:raw]
    // CALCULATION: Seed v2 = -1021 for the subnormal branch and capture the sign of a1 (v3 = a1 < 0.0). [source:raw]
    // LOOP: While bit 4 of the upper mantissa byte is clear, double a1 (scaled) and decrement v2, normalizing the subnormal mantissa. [source:raw]
    // CALCULATION: Clear the normalization bit from a1's mantissa and restore the sign bit from v3. [source:raw]
    // CALL: Call FloatBitManipulation(a1, 0) to obtain the normalized mantissa v5. [callee:0x00591D05]
    // CALCULATION: Normal branch: v5 = FloatBitManipulation(a1, 0) and v2 = ((a1 mantissa-field >> 4) & 0x7FF) - 1022. [source:raw, callee:0x00591D05]
    // ASSIGNMENT: Write the exponent into the caller's slot: *a2 = v2. [source:raw]
    // RETURN: Return the normalized mantissa v5. [source:raw]

    // Conservative worker pseudocode:
    //   double sub_591D88(double a1, int *a2) {
    //     if (a1 == 0.0) {
    //       *a2 = 0;
    //       return 0.0;
    //     }
    //     if (a1 is subnormal) {
    //       int v2 = -1021;
    //       BOOL neg = a1 < 0.0;
    //       while (normalization bit not set) { a1_scaled *= 2; --v2; }
    //       clear normalization bit; if (neg) restore sign bit;
    //       *a2 = v2;
    //       return FloatBitManipulation(a1, 0);
    //     }
    //     *a2 = ((*(_DWORD *)((char *)&a1 + 6) >> 4) & 0x7FF) - 1022;
    //     return FloatBitManipulation(a1, 0);
    //   }
    // UNRESOLVED: Read-only global dbl_5B8CC8 is statically referenced by this function but does not appear in the recovered raw source; its role is unknown.
}
