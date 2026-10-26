// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042BC10
// Canonical corpus name: ScoringGateCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ScoringGateCheck_0042bc10.c

void UnknownObject::ScoringGateCheck()
{
    // Session-scoring gate: returns TRUE only while the global dword_7D2E44 is zero and SessionStateCheck on the session state object at dword_7CD25C does not return 1. A non-zero dword_7D2E44 short-circuits the whole check to FALSE without consulting the session state. Reused as a shared 'is scoring allowed to proceed' predicate across configuration validation, restart, player file init, AI driver count setup, season scoring and telemetry callers.
    // GUARD: Read dword_7D2E44; when non-zero the gate closes immediately (expression is false) without evaluating the session state. [global:0x007D2E44, source:raw]
    // CALL: Invoke SessionStateCheck on the session state object located at dword_7CD25C and test whether its returned state is not equal to 1. [callee:0x00461CD0, global:0x007CD25C, source:raw]
    // RETURN: Return the conjunction: the gate passes only when dword_7D2E44 is zero and SessionStateCheck(&dword_7CD25C) differs from 1. [source:raw]

    // Conservative worker pseudocode:
    //   BOOL ScoringGateCheck() {
    //     if (dword_7D2E44 != 0) return FALSE;
    //     return SessionStateCheck(&dword_7CD25C) != 1;
    //   }
    // UNRESOLVED: The meaning of dword_7D2E44 (zero while the gate is open) and of the SessionStateCheck result value 1 (the state that blocks the gate) are not defined by this packet.
    // UNRESOLVED: Callers span divergent contexts (config validation, restart, player file init, AI driver count setup, season scoring, telemetry dump); the same predicate answers 'may scoring proceed' for each without per-caller qualification, so the triggering state value 1 is not pinned down here.
}
