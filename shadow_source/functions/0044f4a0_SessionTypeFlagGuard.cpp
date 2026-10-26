// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044F4A0
// Canonical corpus name: SessionTypeFlagGuard
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SessionTypeFlagGuard_0044f4a0.c

void UnknownObject::SessionTypeFlagGuard()
{
    // Session/subsession flag guard (__thiscall): returns whether a per-session flag byte at this[a2 + 892] is non-zero, further gated by a global flag-latch check and a session-type value. Returns true when the global flag latch is clear, when the current session type (dword_7C569C) is not 5, or when index a2 is 1 — and the indexed session flag byte is set.
    // CALL: Query the global flag latch via ConditionalFlagReturn(&dword_5EA43C); its boolean result is the first term of the disjunction. [callee:0x00404F10, global:0x005EA43C]
    // GUARD: Evaluate the disjunction: proceed when the flag latch is clear, or when the current session type dword_7C569C is not 5, or when index a2 is 1. [global:0x007C569C, source:raw]
    // CALCULATION: Index the byte array owned by this at byte offset a2 + 892 to read the per-session flag byte. [source:raw]
    // GUARD: Final guard: the result is true only when the indexed session flag byte this[a2 + 892] is non-zero. [source:raw]
    // RETURN: Return the conjunction of the disjunction and the session-flag-byte test as a bool. [source:raw]

    // Conservative worker pseudocode:
    //   bool SessionTypeFlagGuard(byte* session, int a2) {
    //     bool allow = !ConditionalFlagReturn(&dword_5EA43C) || dword_7C569C != 5 || a2 == 1;
    //     return allow && session[a2 + 892] != 0;
    //   }
    // UNRESOLVED: Meaning of the 892-byte stride (a2 offset into the per-session flag array) and the flag values themselves are not determined here.
    // UNRESOLVED: Semantics of the session type compared against 5 in dword_7C569C depend on the session subsystem enum, not available in this packet.
    // UNRESOLVED: ConditionalFlagReturn's exact flag-latch semantics (0x00404F10) are resolved in its own function.
}
