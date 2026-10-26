// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053BB30
// Canonical corpus name: ForceVectorComputationWithAccumulator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ForceVectorComputationWithAccumulator_0053bb30.c

void UnknownObject::ForceVectorComputationWithAccumulator()
{
    // Computes a 3-component vector as the product of direction-like components of a2 (indices 2..4) scaled by scalar a2[5], multiplied component-wise by a transform row read from a3 (indices 21..23); optionally adds an accumulator vector read from a1 at this+0x17C/0x180/0x184 when a1 is non-null; adds a second vector from a3 (indices 29..31); scales every lane by the constant 255.0f; stores the result into the output __m128 a4 and returns a4. SSE SIMD force/torque-style contribution computation.
    // CALCULATION: Build vector v4 from a2: lane0 = a2[4]*a2[5], lane1 = a2[3]*a2[5], lane2 = a2[2]*a2[5]; a2[5] acts as a common scalar magnitude scaling the three a2 components. [source:raw, function:0x0053BB30]
    // CALCULATION: Build vector v5 from a3: lane0 = a3[23], lane1 = a3[22], lane2 = a3[21]. [source:raw, function:0x0053BB30]
    // CALCULATION: Build vector v6 from a3: lane0 = a3[31], lane1 = a3[30], lane2 = a3[29]. [source:raw, function:0x0053BB30]
    // CALCULATION: Build constant vector v7 with all four lanes equal to 255.0f, from the packed literals 0x437F0000437F0000LL and 1132396544 (0x437F0000 = 255.0f). [source:raw, function:0x0053BB30]
    // CALCULATION: v8 = v4 * v5 via SSE component-wise multiply (_mm_mul_ps). [source:raw, function:0x0053BB30]
    // GUARD: If a1 is non-null, add the accumulator vector into v8: lane0 = a1[97] (this+0x184), lane1 = a1[96] (this+0x180), lane2 = a1[95] (this+0x17C). No accumulation is performed when a1 is null. [source:raw, function:0x0053BB30, field:this:0x0000017C, field:this:0x00000180, field:this:0x00000184]
    // ASSIGNMENT: Store the result into the output vector: *a4 = (v8 + v6) * v7, i.e. ((scaled direction * transform row) + optional accumulator + offset vector) scaled by 255.0f. [source:raw, function:0x0053BB30, abi:lead]
    // RETURN: Return the output vector pointer a4. [source:raw, function:0x0053BB30]

    // Conservative worker pseudocode:
    //   // ((dir * scale) .* row1) + (optional accumulator) + row2, then * 255.0f
    //   __m128 v4 = { a2[4]*a2[5], a2[3]*a2[5], a2[2]*a2[5], /* lane3 residue * / };
    //   __m128 v5 = { a3[23], a3[22], a3[21], /* lane3 residue * / };
    //   __m128 v6 = { a3[31], a3[30], a3[29], /* lane3 residue * / };
    //   __m128 v7 = { 255.0f, 255.0f, 255.0f, 255.0f };
    //   __m128 v8 = v4 * v5;
    //   if (a1) {
    //     v8 += { a1[97], a1[96], a1[95] }; // accumulator at this+0x184, +0x180, +0x17C
    //   }
    //   *a4 = (v8 + v6) * v7;
    //   return a4;
    // UNRESOLVED: Static facts list flt_59E440 (0x0059E440) and flt_59FEC8 (0x0059FEC8) as read globals, but neither appears in the raw function text; the 255.0f constant may be an inlined load from one of them, but which one (if either) cannot be established from this packet.
    // UNRESOLVED: The semantic meaning of the a3 inputs (indices 21..23 and 29..31) is not established; existing analysis labels the function a force/torque contribution using transform constants, but the mapping of indices to rotation/offset components is unproven.
    // UNRESOLVED: Lane 3 of the constructed __m128 vectors carries stack residue; the effective 3-component interpretation and the component-to-lane ordering are inferred from the field ordering in the existing analysis, not confirmed.
    // UNRESOLVED: Owner type and caller list are unknown; the function is top-level or reachable only indirectly.
}
