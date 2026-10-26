// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049AA30
// Canonical corpus name: OffsetAccumulator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/OffsetAccumulator_0049aa30.c

void UnknownObject::AccumulateOffset()
{
    // Offset accumulator: tracks the incoming primary value a2, stores its per-call delta into this+0x10, and separately accumulates a reference-value delta into this+0x8. Reads the prior primary baseline from this+0xC, stores a3 as the new reference baseline at this+0x4, and returns the primary-value delta (a2 - prior this+0xC). Structural twin of ShortComputation_a9c0 (0049a9c0) per prelabel cluster_copy.
    // CALCULATION: Read prior primary baseline v3 = this+0xC (this[3]). [source:raw, field:this:0x0000000C]
    // CALCULATION: Compute reference delta v4 = a3 - this+0x4 (this[1]) using the old reference baseline. [source:raw, field:this:0x00000004]
    // ASSIGNMENT: Store the incoming reference value into this+0x4 (this[1] = a3). [source:raw, field:this:0x00000004]
    // CALCULATION: Compute v5 = v4 + this+0x8 (this[2]), adding the reference delta to the running accumulation. [source:raw, field:this:0x00000008]
    // ASSIGNMENT: Store the running reference accumulation into this+0x8 (this[2] = v5). [source:raw, field:this:0x00000008]
    // CALCULATION: Compute result = a2 - v3, the delta of the primary value versus its prior baseline. [source:raw, field:this:0x0000000C]
    // ASSIGNMENT: Store the incoming primary value into this+0xC (this[3] = a2). [source:raw, field:this:0x0000000C]
    // CALCULATION: Read prior accumulated primary delta v6 = this+0x10 (this[4]). [source:raw, field:this:0x00000010]
    // ASSIGNMENT: Store result + v6 into this+0x10 (this[4]), accumulating the primary delta across calls. [source:raw, field:this:0x00000010]
    // RETURN: Return result, the per-call primary-value delta. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_49AA30(int a2, int a3) {
    //     int prevPrimary = this[3];
    //     int refDelta = a3 - this[1];
    //     this[1] = a3;
    //     this[2] = refDelta + this[2];
    //     int result = a2 - prevPrimary;
    //     this[3] = a2;
    //     this[4] = result + this[4];
    //     return result;
    //   }
    // UNRESOLVED: Semantics of the two accumulating fields (this+0x8 reference accumulation vs this+0x10 primary accumulation) and the relationship between a2 and a3 are caller-dependent.
    // UNRESOLVED: Owner class is unknown; no caller-visible contract links this helper to a named object.
    // UNRESOLVED: Twin relationship to 0049a9c0 is DERIVED from prelabel cluster_copy, not independently proven here.
}
