// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C2D30
// Canonical corpus name: sub_4C2D30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4C2D30_004c2d30.c

void UnknownObject::ScaledRunningAverageWithClamp()
{
    // Computes a running average of a per-call input scaled by 100.0, weighted by a sample count stored at this+0x28, and stores the result at this+0x4C. For count 0 the scaled input is stored directly; for count 1 the previous average is kept; for count > 1 a weighted ((count-1)*average + scaled_input)/count average is computed. The stored average is then post-processed through a compare-status branch against 100.0 that replaces it with a constant when the comparison is unordered or when it exceeds 100.0.
    // CALCULATION: v2 := sample count read from this+0x28 [field:this:0x00000028]
    // CALCULATION: v9 := a2 * 100.0 — input scaled by 100.0 [source:raw]
    // GUARD: Branch on count v2: if v2==0 seed v3 with scaled input v9; if v2==1 keep previous average at this+0x4C; if v2>1 use (v2-1) * previous average at this+0x4C [field:this:0x0000004C, source:raw]
    // ASSIGNMENT: if v2 <= 0: this+0x4C := v9 — count zero or negative stores the scaled input directly [field:this:0x0000004C, source:raw]
    // CALCULATION: v4 := v3 + v9; v5 := v4 / v2 — combine and divide by the sample count [source:raw]
    // ASSIGNMENT: this+0x4C := v5 — store the computed average [field:this:0x0000004C, source:raw]
    // GUARD: Compare v5 against 100.0: if the comparison status is unordered, this+0x4C := 1084227584; else if v5 > 100.0, this+0x4C := 1120403456 [field:this:0x0000004C, source:raw]
    // RETURN: Function completes without a return value; the updated average persists at this+0x4C [function:0x004C2D30, field:this:0x0000004C]

    // Conservative worker pseudocode:
    //   v2 = *(this + 40);
    //   v9 = a2 * 100.0;
    //   if (v2 <= 1) {
    //       if (v2 == 1) v3 = *(float*)(this + 76);
    //       else v3 = v9;
    //   } else {
    //       v3 = (double)(v2 - 1) * *(float*)(this + 76);
    //   }
    //   v4 = v3 + v9;
    //   if (v2 <= 0) *(float*)(this + 76) = v9;
    //   v5 = v4 / (double)v2;
    //   *(float*)(this + 76) = v5;
    //   if (compare_status_unordered) *(this + 76) = 1084227584;
    //   else if (v5 > 100.0) *(this + 76) = 1120403456;
    // UNRESOLVED: flt_59E6F8 (0x0059E6F8) and flt_59E7EC (0x0059E7EC) are data xrefs recorded by the fact table but absent from the raw source text; their runtime role in this function is not established.
    // UNRESOLVED: Literal 1084227584 has no float interpretation given in the packet; decoded as 5.0f it is applied only on the unordered compare branch, not as a symmetric lower clamp.
    // UNRESOLVED: The v7/v8 locals are decompiler artifacts of the final compare-status branch; the exact x87 flag mapping is unverified.
    // UNRESOLVED: The owner (UnknownObject) and the running-average purpose are DERIVED from structure and the legacy ABI label, not independently confirmed.
}
