// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FFFB0
// Canonical corpus name: ZoneThresholdComparisonWithConditionalAction
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ZoneThresholdComparisonWithConditionalAction_004fffb0.c

void UnknownObject::ZoneThresholdComparisonWithConditionalAction()
{
    // __thiscall zone-based comparison. Loads v3 = float at a3+4, then classifies it against an upper threshold (this+12, field evidence this+0xC) and a lower threshold (this+444, field evidence this+0x1BC). If v3 <= this+444 no action is taken (lower zone, blocked). If v3 is in (this+444, a2] ArithmeticComparison_3a90 is called with (this+440, a3). If v3 > a2 and v3 < this+12, ArithmeticComparison_3a90 is called with (this+8, a3). Used for zone/region state management; called by NetworkMessageDispatch (004b54e0) and sub_4B9000 (004b9000).
    // CALCULATION: v3 = float at a3+4; the incoming value being classified into a zone. [source:raw]
    // GUARD: Outer guard: if v3 > a2 OR v3 <= this+444 (field this+0x1BC) take the outer branch; otherwise (v3 in (this+444, a2]) take the inner else branch. When v3 <= this+444 no action is triggered (lower zone, blocked). [field:this:0x000001BC, source:raw]
    // GUARD: Inner guard (outer branch only): if v3 > a2 AND float at a3+4 < this+12 (field this+0xC), call ArithmeticComparison_3a90 with (this+8, a3). [field:this:0x0000000C, source:raw]
    // CALL: Call ArithmeticComparison_3a90((this+8), a3) when the value lies above a2 and below the upper threshold this+12 (field this+0xC). [callee:0x004B3A90, field:this:0x0000000C, source:raw]
    // CALL: Else branch: call ArithmeticComparison_3a90((this+440), a3) when v3 is in the middle zone (this+444, a2]. [callee:0x004B3A90, field:this:0x000001BC, source:raw]
    // CALL: Invoked by NetworkMessageDispatch (004b54e0). [caller:0x004B54E0]
    // CALL: Invoked by sub_4B9000 (004b9000). [caller:0x004B9000]

    // Conservative worker pseudocode:
    //   void ZoneThresholdComparisonWithConditionalAction(int this, float a2, int a3) {
    //     float v3 = *(float *)(a3 + 4);
    //     if (v3 > a2 || v3 <= *(float *)(this + 444)) {
    //       if (v3 > a2 && *(float *)(a3 + 4) < *(float *)(this + 12))
    //         ArithmeticComparison_3a90((int *)(this + 8), (int *)a3);
    //     } else {
    //       ArithmeticComparison_3a90((int *)(this + 440), (int *)a3);
    //     }
    //   }
    // UNRESOLVED: this+8 and this+440 are dereferenced only as the first argument to ArithmeticComparison_3a90; their field roles are not covered by packet field evidence.
    // UNRESOLVED: a3+4 is read for the comparison but no field evidence ref exists for it in the packet.
    // UNRESOLVED: The precise meaning of the a2 boundary relative to the two stored thresholds (this+12, this+444) is inferred from the guards, not proven by the packet.
}
