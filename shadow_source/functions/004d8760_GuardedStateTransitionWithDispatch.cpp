// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D8760
// Canonical corpus name: sub_4D8760
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D8760_004d8760.c

void UnknownObject::GuardedStateTransitionWithDispatch()
{
    // Guarded state transition: given a target state id a2 and selector a3, verifies the candidate state object exists (this[a2+4] != 0), authorization passes (dword_7CF638 bypass or Return0Stub_9280(a2)), the move is forward-or-same in the IDToValueMapper ordering, and the ConditionalFlagReturn flag at dword_5EA43C is clear. On success writes 0 or 1056964608 (0.5f) to this[0xDC] per a3, stores the new state id in *this, and dispatches VTableDispatchWithFieldClear into the new object; returns 0. Otherwise returns 1, resetting *this to the -1 sentinel when the target id is itself the sentinel.
    // GUARD: State-object existence check: v10 = (this[a2 + 4] != 0); the candidate state object pointer stored at dynamic index (a2 + 4) must be non-null before a transition is allowed. [source:raw]
    // GUARD: Authorization check: transition is allowed when global dword_7CF638 is set (bypass) or Return0Stub_9280(a2) returns nonzero for the target id a2. [callee:0x004D9280, global:0x007CF638]
    // GUARD: Current-state sentinel check: the transition ordering logic only runs while *this != 0xFFFFFFFF (-1), the invalid/initial state id. [guard:0, field:this:0x00000000]
    // CALCULATION: State ordering comparison: v6 = IDToValueMapper(*this); the transition is rejected when v6 >= IDToValueMapper(a2) and the two ids differ, enforcing forward-or-same movement. [callee:0x004D91E0]
    // GUARD: Conditional flag check: ConditionalFlagReturn(&dword_5EA43C) must return false (flag clear) for the transition to proceed. [callee:0x00404F10, global:0x005EA43C]
    // STATE_TRANSITION: Set the state-transition field at offset 0xDC (this[55]): 0 when a3 == 1, otherwise 1056964608 (0.5f). [field:this:0x000000DC]
    // ASSIGNMENT: Write the new state id into the current-state slot: *this = a2. [field:this:0x00000000]
    // CALL: Dispatch into the new state object: VTableDispatchWithFieldClear(this[a2 + 4]) invoked with the candidate state-object pointer. [callee:0x004D7E30]
    // RETURN: Return 0 after a successful transition. [source:raw]
    // STATE_TRANSITION: Rejection path: when the target id is the sentinel (a2 == -1), reset the current state to the sentinel (*this = -1). [field:this:0x00000000]
    // RETURN: Return 1 when the transition was rejected (guards failed or target not the sentinel reset case). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4D8760(int *this, int a2, char a3) {
    //     bool exists = (this[a2 + 4] != 0);
    //     bool authorized = dword_7CF638 || Return0Stub_9280(a2);
    //     bool forward = true;
    //     if (*this != -1) {
    //       int cur = IDToValueMapper(*this);
    //       if (cur >= IDToValueMapper(a2) && *this != a2) forward = false;
    //     }
    //     bool blocked = ConditionalFlagReturn(&dword_5EA43C);
    //     if (exists && authorized && forward && !blocked) {
    //       this[55] = (a3 == 1) ? 0 : 1056964608;
    //       *this = a2;
    //       VTableDispatchWithFieldClear(this[a2 + 4]);
    //       return 0;
    //     }
    //     if (a2 == -1) *this = -1;
    //     return 1;
    //   }
    // UNRESOLVED: Global dword_5ACF34 is listed by the packet as a read global but never appears in the raw source; its role in this function is unclear.
    // UNRESOLVED: Semantics of the 1056964608 (0.5f) value written to offset 0xDC and of the a3 selector (0 vs 1) are caller-defined.
    // UNRESOLVED: The concrete class of the candidate state object at this[a2 + 4] and the target of the vtable dispatch depend on the caller-supplied state id a2.
}
