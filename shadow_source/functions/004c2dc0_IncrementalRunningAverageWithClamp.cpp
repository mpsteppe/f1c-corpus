// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C2DC0
// Canonical corpus name: ArithmeticComparison_2dc0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_2dc0_004c2dc0.c

void UnknownObject::IncrementalRunningAverageWithClamp()
{
    // Computes an incremental running average: reads a counter at this+0x2C, increments it, accumulates old_count * previous_average(this+0x50) + input, then divides by the updated counter and stores the result at this+0x50. A counter-wrap guard resets the counter to 1 when the old value is -1 (i.e. the incremented value would be 0). The stored average is then post-processed through a compare-status branch against 120.0 that replaces it with a constant when the comparison is unordered or when it exceeds 120.0.
    // CALCULATION: v7 := counter at this+0x2C; store v7 + 1 back to this+0x2C — counter incremented each call [field:this:0x0000002C, source:raw]
    // CALCULATION: v2 := (double)v7 * average at this+0x50 + input a2 — accumulate old_count * old_average plus new input [field:this:0x00000050, source:raw]
    // GUARD: if v7 == -1: this+0x2C := 1 — reset counter when the increment would produce zero [field:this:0x0000002C, source:raw]
    // CALCULATION: v3 := v2 / (int)counter at this+0x2C; this+0x50 := v3 — compute and store the new running average [field:this:0x00000050, source:raw]
    // GUARD: Compare v3 against 120.0: if the comparison status is unordered, this+0x50 := 1116471296; else if v3 > 120.0, this+0x50 := 1123024896 [field:this:0x00000050, source:raw]
    // RETURN: Function completes without a return value; the updated average persists at this+0x50 [function:0x004C2DC0, field:this:0x00000050]

    // Conservative worker pseudocode:
    //   v7 = *(this + 44);
    //   *(this + 44) = v7 + 1;
    //   v2 = (double)v7 * *(float*)(this + 80) + a2;
    //   if (v7 == -1) *(this + 44) = 1;
    //   v3 = v2 / (double)*(int*)(this + 44);
    //   *(float*)(this + 80) = v3;
    //   if (compare_status_unordered) *(this + 80) = 1116471296;
    //   else if (v3 > 120.0) *(this + 80) = 1123024896;
    // UNRESOLVED: flt_59E968 (0x0059E968) and flt_5ACB00 (0x005ACB00) are data xrefs recorded by the fact table but absent from the raw source text; their runtime role in this function is not established.
    // UNRESOLVED: Literal 1116471296 has no float interpretation given in the packet; decoded as 64.0f it is applied only on the unordered compare branch, not as a symmetric lower clamp.
    // UNRESOLVED: The v5/v6 locals are decompiler artifacts of the final compare-status branch; the exact x87 flag mapping is unverified.
    // UNRESOLVED: The owner (UnknownObject) and the running-average purpose are DERIVED from structure and the legacy ABI label, not independently confirmed.
}
