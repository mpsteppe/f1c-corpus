// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D1AD0
// Canonical corpus name: ScoringGateSelector
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ScoringGateSelector_004d1ad0.c

void UnknownObject::ScoringGateSelector()
{
    // Scans a per-session gate array at this[68] (byte offset 0x110, 8-byte entries) over an index range computed from a2, and selects the highest-priority gate type with priority 3 > 8 > 2 > 0. Returns 3 immediately when an entry value of 3 is found; otherwise returns the best accumulated match (8, then 2), or 0 when the range is empty or nothing matches. Called by AISessionModeTransition and PitSelectionStateMachine.
    // CALL: v3 = ShortComputation_7bf0(a2); compute the starting index of the gate scan range. [callee:0x004D7BF0, source:raw]
    // CALL: v4 = ArrayAccessAt0xcIndex4(a2); compute the inclusive ending index of the gate scan range. [callee:0x004D7C00, source:raw]
    // ASSIGNMENT: result = 0; default selection is 'no gate selected'. [source:raw]
    // GUARD: If v3 > v4 the range is empty; skip the scan and return result (0). [source:raw]
    // LOOP: Iterate over gate entries starting at (this[68] + 8*v3) with an 8-byte stride, advancing the pointer i by 2 dwords each iteration. [field:this:0x00000110, source:raw]
    // GUARD: Read the first dword v7 of each entry; if v7 == 3, break out of the loop as the highest-priority gate was found. [source:raw]
    // ASSIGNMENT: When result != 8, set result = 8 if v7 == 8, else set result = 2 when result != 2 and v7 == 2; 8 outranks 2 and an already-set value is kept. [source:raw]
    // GUARD: If ++v3 > v4 after an entry, the range is exhausted; return the accumulated result. [source:raw]
    // RETURN: Return 3 when an entry value of 3 broke the loop, or the accumulated result (8, 2 or 0) at range end. [function:0x004D1AD0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4D1AD0(_DWORD *this, int a2) {
    //     int start = ShortComputation_7bf0(a2);
    //     int end = ArrayAccessAt0xcIndex4(a2);
    //     int result = 0;
    //     if (start <= end) {
    //       int *i = (int*)(this[68] + 8*start);
    //       for (;; i += 2) {
    //         int v7 = *i;
    //         if (v7 == 3) return 3;
    //         if (result != 8) {
    //           if (v7 == 8) result = 8;
    //           else if (result != 2 && v7 == 2) result = 2;
    //         }
    //         if (++start > end) return result;
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Global dword_8AD264 is listed as read evidence but does not appear in the raw source; its role here is unclear.
    // UNRESOLVED: Semantics of gate values 2/8/3 (penalty gate priority selector) are DERIVED from caller context, not proven.
    // UNRESOLVED: Callers AISessionModeTransition and PitSelectionStateMachine are the only known call sites.
}
