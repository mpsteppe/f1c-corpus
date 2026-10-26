// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FDE00
// Canonical corpus name: sub_4FDE00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4FDE00_004fde00.c

void UnknownObject::ComputePiecewiseResponse()
{
    // Piecewise envelope computation on a float input a2 writing two scalars at this+32 (field 0x20) and this+36 (field 0x24). Below or at 0.60000002 both outputs are zeroed. Above the threshold the function selects one of three segments using FPU compare flags (v4 = c0, v5 = c3) and a 0.69999999 comparison: one branch stores a linear ramp (a2 - 0.60000002) * 20.000019 into field 0x20 with field 0x24 cleared; the middle branch saturates field 0x20 at 1065353216 and ramps field 0x24 toward 1065353216 with (a2 - 0.69999999) * 3.3333333 once a2 exceeds 1.0; the remaining branch stores 1065353216 / 0. The exact predicate of the v4|v5 flag test is ambiguous from the decompiler's FPU flag rendering. The legacy ABI lead names it Piecewise_Response_Curve.
    // GUARD: if (a2 > 0.60000002): values below the threshold take the else path and both outputs are zeroed. [abi:lead, source:raw]
    // ASSIGNMENT: Below threshold: *(int*)(this + 32) = 0 and *(int*)(this + 36) = 0 (fields 0x20 and 0x24). [field:this:0x00000020, field:this:0x00000024, source:raw]
    // GUARD: Above threshold: test the captured FPU flags v4 (c0) | v5 (c3) to choose the low segment; the exact predicate this flag test encodes is ambiguous. [source:raw]
    // ASSIGNMENT: Low segment: *(int*)(this + 36) = 0 and *(float*)(this + 32) = (v3 - 0.60000002) * 20.000019, a linear ramp on field 0x20 from the 0.60000002 threshold. [field:this:0x00000020, field:this:0x00000024, source:raw]
    // GUARD: else if (v3 > 0.69999999) with v3 = a2: mid/high segment; otherwise the final else stores the saturated state. [source:raw]
    // ASSIGNMENT: Mid/high segment: *(int*)(this + 32) = 1065353216 saturates field 0x20. [field:this:0x00000020, source:raw]
    // GUARD: if (a2 > 1.0): second output saturates instead of ramping. [source:raw]
    // ASSIGNMENT: Saturation branch: *(int*)(this + 36) = 1065353216 sets field 0x24 to the saturated value. [field:this:0x00000024, source:raw]
    // ASSIGNMENT: Ramp branch: *(float*)(this + 36) = (a2 - 0.69999999) * 3.3333333 ramps field 0x24 from the 0.69999999 threshold toward the saturated value. [field:this:0x00000024, source:raw]
    // ASSIGNMENT: Final else: *(int*)(this + 32) = 1065353216 and *(int*)(this + 36) = 0 (field 0x20 saturated, field 0x24 cleared). [field:this:0x00000020, field:this:0x00000024, source:raw]

    // Conservative worker pseudocode:
    //   void ComputePiecewiseResponse(int this, float a2) {
    //     double v3 = a2;
    //     if (a2 > 0.60000002) {
    //       if (v4 | v5) {
    //         *(int*)(this + 36) = 0;
    //         *(float*)(this + 32) = (v3 - 0.60000002) * 20.000019;
    //       } else if (v3 > 0.69999999) {
    //         *(int*)(this + 32) = 1065353216;
    //         if (a2 > 1.0)
    //           *(int*)(this + 36) = 1065353216;
    //         else
    //           *(float*)(this + 36) = (a2 - 0.69999999) * 3.3333333;
    //       } else {
    //         *(int*)(this + 32) = 1065353216;
    //         *(int*)(this + 36) = 0;
    //       }
    //     } else {
    //       *(int*)(this + 32) = 0;
    //       *(int*)(this + 36) = 0;
    //     }
    //   }
    // UNRESOLVED: The exact meaning of the FPU flag test (v4 | v5, i.e. c0 | c3) is ambiguous: the decompiler captured status-word flags whose producing comparison is not explicit in the text, so the segment boundaries at 0.69999999 may differ from the literal source condition.
    // UNRESOLVED: The literal 1065353216 is the IEEE-754 bit pattern for the float 1.0; this interpretation is DERIVED, not a packet fact.
    // UNRESOLVED: The six read-only float globals (0x0059E43C, 0x0059E4E8, 0x0059E6E8, 0x0059E8F8, 0x005AD304, 0x005AD308) are not visible in the decompiled text; they are presumed to be the float immediates (0.60000002, 0.69999999, 1.0, 20.000019, 3.3333333, 0.0) but the per-constant mapping is unknown.
    // UNRESOLVED: Field identity: the two writes at this+32 and this+36 have no confirmed class meaning; the equal offsets on this pointer do not identify a shared struct across callers.
    // UNRESOLVED: The existing-analysis prose (ramp 0 to 1 over 0.6 to 0.7) is not consistent with the code's 20.000019 slope; the code text is treated as authoritative.
}
