// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D1CD0
// Canonical corpus name: SingleCallWrapper_1cd0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SingleCallWrapper_1cd0_004d1cd0.c

void UnknownObject::ConditionalComparisonForwarder()
{
    // Forwarding wrapper over a comparison helper: computes a pointer 55 dwords past this, then conditionally forces argument a2 to zero when the global dword_8AB6E4 equals 2, and finally returns the result of delegating to the comparison helper with the adjusted arguments. Both callers are race/session-lifecycle helpers, suggesting the global gates a mode where the comparison argument must be suppressed.
    // CALCULATION: Compute v2 as this + 55 (dword-indexed), the comparison input pointer. [source:raw]
    // GUARD: Test global dword_8AB6E4; when it equals 2, the guard forces argument a2 to zero. [global:0x008AB6E4]
    // ASSIGNMENT: Under the guard, override a2 with zero so the forwarded comparison receives 0. [source:raw]
    // CALL: Tail-delegate to the comparison helper with (v2, a2) and return its result. [function:0x004D1CD0]
    // RETURN: Return the comparison helper's result unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4D1CD0(_DWORD *this, int a2) {
    //     _DWORD *v2 = this + 55;
    //     if (dword_8AB6E4 == 2) a2 = 0;
    //     return ArithmeticComparison_0ec0(v2, a2);
    //   }
    // UNRESOLVED: The comparison helper (named ArithmeticComparison_0ec0 in the raw source) has no callee evidence reference in this packet and is not resolved further here.
    // UNRESOLVED: Meaning of global dword_8AB6E4 and why the value 2 suppresses a2 are unknown.
    // UNRESOLVED: Callers PitTimer and Steward_Restart imply race/session timing but no owner is evidenced.
}
