// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041FB10
// Canonical corpus name: MemoryAllocation_fb10
// Owner: RaceStandings [DERIVED]
// Raw source: functions/MemoryAllocation_fb10_0041fb10.c

void RaceStandings::DualStatusValidator()
{
    // Validates that a named entrant carries both standings status values 10 and 6 at a rank-derived offset (entry + 4*v3 + 212), where v3 comes from sub_4C2990 on the standings sort buffer. Scans the first standings entry and then every active entry (ActiveEntityCounter loop), each time filling an 80-byte scene-name buffer via SceneNameLookupBySeason and comparing it against the input name with sub_566810 before reading the status dword; returns true only when both status values 10 and 6 were observed for the matching entrant.
    // ASSIGNMENT: Initialize both status flags to false: v2 (status 10) = 0 and v11 (status 6) = 0. [source:raw]
    // CALL: sub_4C2990(&dword_7D2DB0) computes a rank-derived index v3 from the standings sort buffer; the index offsets the status dword read later. [callee:0x004C2990, global:0x007D2DB0, source:raw]
    // CALL: LinkedListDereference(&dword_7D2DB0) followed by FixedOffsetReturn resolves the first/base standings entry pointer. [callee:0x004C2850, callee:0x004C1390, global:0x007D2DB0, source:raw]
    // CALL: SceneNameLookupBySeason(v12, 80) fills the 80-byte scene/track name buffer used for the entrant-name comparison. [callee:0x004C0A20, source:raw]
    // GUARD: sub_566810(v12, this) compares the filled scene name against the input name; only matching entrants are status-evaluated. [callee:0x00566810, source:raw]
    // ASSIGNMENT: First-entry status capture: when the dword at (baseEntry + 4*v3 + 212) equals 10 set v2 = 1, else set v11 to whether the same dword equals 6. [source:raw]
    // CALL: LinkedListDereference(&dword_7D2DB0) re-reads the sort buffer and ActiveEntityCounter(v8) produces the active-entry count for the scan guard. [callee:0x004C2850, callee:0x004C1370, global:0x007D2DB0, source:raw]
    // GUARD: The all-entries scan runs only while the active-entry counter is greater than 0. [callee:0x004C1370, source:raw]
    // LOOP: do-while over v7 from 0 to activeCount-1, dereferencing the sort buffer each iteration and re-reading the active count as the loop condition. [callee:0x004C1370, callee:0x004C2850, global:0x007D2DB0, source:raw]
    // CALL: ShortComputation_13a0(v7) returns the standings entry pointer for the current loop index v7. [callee:0x004C13A0, source:raw]
    // CALL: Per-entry SceneNameLookupBySeason(v12, 80) plus sub_566810(v12, this) gate whether this entry's status is captured. [callee:0x004C0A20, callee:0x00566810, source:raw]
    // ASSIGNMENT: Per-entry status capture: set v2 = 1 when the dword at (entry(v7) + 4*v3 + 212) equals 10, and set v11 = 1 when it equals 6. [source:raw]
    // RETURN: Return v2 && v11: true only when both status values 10 and 6 were observed for the matching entrant across the first entry and the full scan. [function:0x0041FB10, source:raw]

    // Conservative worker pseudocode:
    //   bool DualStatusValidator(void *name) {
    //     bool hasStatus10 = false, hasStatus6 = false;
    //     int idx = sub_4C2990(&dword_7D2DB0);
    //     entry = FixedOffsetReturn(LinkedListDereference(&dword_7D2DB0));
    //     SceneNameLookupBySeason(buf, 80);
    //     if (sub_566810(buf, name)) {
    //       dword = *(DWORD*)(entry + 4*idx + 212);
    //       if (dword == 10) hasStatus10 = true; else hasStatus6 = (dword == 6);
    //     }
    //     for (n = 0; n < ActiveEntityCounter(LinkedListDereference(&dword_7D2DB0)); ++n) {
    //       SceneNameLookupBySeason(buf, 80);
    //       if (sub_566810(buf, name)) {
    //         e = ShortComputation_13a0(n);
    //         if (*(DWORD*)(e + 4*idx + 212) == 10) hasStatus10 = true;
    //         if (*(DWORD*)(e + 4*idx + 212) == 6) hasStatus6 = true;
    //       }
    //     }
    //     return hasStatus10 && hasStatus6;
    //   }
    // UNRESOLVED: The meaning of status values 10 and 6 at entry + 4*v3 + 212 (completed/retired vs active session) is inferred from the skeleton fill; not independently evidenced by this packet.
    // UNRESOLVED: sub_4C2990's contract is unknown; v3 being a rank-derived index is the skeleton fill's DERIVED reading, not proven here.
    // UNRESOLVED: The 80-byte scene-name buffer and sub_566810 name-comparison semantics are only partially evidenced.
    // UNRESOLVED: No callers are present in the packet, so the invocation context and the meaning of the input name are unresolved.
    // UNRESOLVED: The ABI module classification Memory_Allocation (LEGACY) does not match the standings-oriented behavior and is treated as an unverified label.
}
