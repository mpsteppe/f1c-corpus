// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00489EE0
// Canonical corpus name: ShortComputation_9ee0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_9ee0_00489ee0.c

void UnknownObject::ResetScrollOffset()
{
    // Resets the scroll offset field this[0x14C] to 0, then, when the max scroll value this[0x160] is non-zero and the display size this[0x154] cast to double is above 0.0, stores the CRTFtol-truncated display size as the new scroll offset. Called by sub_489D00 and UIScrollListUpdate during UI list refresh.
    // ASSIGNMENT: Unconditionally zero the scroll offset field this[83] (byte offset 0x14C) before any guard. [field:this:0x0000014C, source:raw]
    // GUARD: Load this[88] (byte offset 0x160) as v1 and require it non-zero; otherwise the scroll offset stays 0. [field:this:0x00000160, source:raw]
    // CALCULATION: Read display size this[85] (byte offset 0x154), cast to int and then to double as v2. [field:this:0x00000154, source:raw]
    // GUARD: Guard: only proceed when v2 is greater than 0.0; otherwise the scroll offset stays 0. [source:raw]
    // CALL: Call CRTFtol(v2) to truncate the display-size double to a long integer. [callee:0x00587BDC, source:raw]
    // ASSIGNMENT: Store the truncation result into the scroll offset field this[83] (byte offset 0x14C). [field:this:0x0000014C, source:raw]
    // CALL: Invoked by sub_489D00 and UIScrollListUpdate (0048A8D0) as part of list scrolling. [caller:0x00489D00, caller:0x0048A8D0, source:raw]

    // Conservative worker pseudocode:
    //   void sub_489EE0(DWORD* this) {
    //     this[83] = 0;
    //     if (this[88]) {
    //       double v2 = (double)(int)this[85];
    //       if (v2 > 0.0) this[83] = CRTFtol(v2);
    //     }
    //   }
    // UNRESOLVED: Read-only globals flt_59E440 and flt_59E450 are flagged by packet facts but appear nowhere in the raw source; the skeleton fill labels them ZeroThreshold and DegreesToRadians, neither verifiable from this packet.
    // UNRESOLVED: Semantic role of the max-scroll guard (0x160) and display-size field (0x154) is inferred from the UI-list caller context, not proven.
}
