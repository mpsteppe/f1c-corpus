// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040D410
// Canonical corpus name: ShortComputation_d410
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_d410_0040d410.c

void UnknownObject::ShortComputation_d410()
{
    // Per-frame session/pit complementary action (__thiscall, void). Decodes the current session phase via SessionPhaseDecode(this); when the decoded phase is in [7, 10] it dispatches GameActionStateMachine with the action id read from this+0x10 and a zero argument. Unconditionally computes a safe reciprocal on flt_5EA4E8 via SafeDivisionWithZeroGuard (0.5 divisor) and clears the activity flag byte at this+0x24.
    // CALL: Decode the session phase: v2 = SessionPhaseDecode(this). [callee:0x0040CD60]
    // GUARD: Dispatch the game action only when the decoded phase v2 is in the closed range [7, 10]. [callee:0x0040CD60]
    // CALL: Dispatch the game action state machine: GameActionStateMachine(v3, *(this+16), 0) using the action id field at offset 0x10; the first argument v3 is an uninitialized register in the decompiled source. [callee:0x0040CDE0, field:this:0x00000010]
    // CALL: Compute a safe reciprocal: SafeDivisionWithZeroGuard((int)&flt_5EA4E8, 0.5) guarding division by zero. [callee:0x00408450, global:0x005EA4E8]
    // ASSIGNMENT: Clear the activity flag byte at this+0x24 to 0. [field:this:0x00000024]

    // Conservative worker pseudocode:
    //   void ShortComputation_d410(int this) {
    //     int phase = SessionPhaseDecode((_DWORD*)this);
    //     if (phase >= 7 && phase <= 10)
    //       GameActionStateMachine(v3, *(int*)(this + 16), 0);
    //     SafeDivisionWithZeroGuard((int)&flt_5EA4E8, 0.5);
    //     *(byte*)(this + 36) = 0;
    //   }
    // UNRESOLVED: First argument v3 to GameActionStateMachine is an uninitialized register in the decompilation; the real receiver is not established.
    // UNRESOLVED: Meaning of the decoded phase range [7, 10] and the action id at this+0x10 is not established here.
    // UNRESOLVED: What SafeDivisionWithZeroGuard writes through &flt_5EA4E8 and why a 0.5 divisor is used is unresolved.
    // UNRESOLVED: The flag byte cleared at this+0x24 is only described as an activity flag (recalculated every frame).
}
