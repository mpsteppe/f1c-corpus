// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BC2F0
// Canonical corpus name: ConditionalFieldSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalFieldSetter_004bc2f0.c

void UnknownObject::ConditionalFieldSetter()
{
    // Conditional AI-driver state setter: compares the current state stored at this+0x2C (this+44) with the incoming value a2. When they differ, it calls AIDriverStateTransition with the global state array dword_5EB978, the per-driver state pointer at this+0x0, and the old/new state pair, then writes a2 into this+0x2C. Equal states short-circuit with no transition notification.
    // ASSIGNMENT: Read current state value v3 from this+0x2C (this+44). [source:raw, field:this:0x0000002C]
    // GUARD: Guard: proceed only when v3 != a2; equal states skip the transition and the write. [source:raw]
    // CALL: Call AIDriverStateTransition(dword_5EB978, *(int **)this, v3, a2) to notify the state-transition system of the old -> new change, passing the global state array and the driver's state pointer at this+0x0. [source:raw, callee:0x00419120, global:0x005EB978, field:this:0x00000000]
    // ASSIGNMENT: Store the new state a2 into this+0x2C (this+44). [source:raw, field:this:0x0000002C]

    // Conservative worker pseudocode:
    //   void sub_4BC2F0(int this, int a2) {
    //     int cur = *(int *)(this + 44);
    //     if (cur != a2) {
    //       AIDriverStateTransition(dword_5EB978, *(int **)this, cur, a2);
    //       *(int *)(this + 44) = a2;
    //     }
    //   }
    // UNRESOLVED: Enum space and meaning of the state values compared at this+0x2C are unknown.
    // UNRESOLVED: Role of the global state array dword_5EB978 and the per-driver pointer at this+0x0 inside AIDriverStateTransition is not established by the packet.
    // UNRESOLVED: Object type owning this is unidentified (owner evidence empty in the packet).
}
