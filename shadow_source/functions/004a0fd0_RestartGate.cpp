// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A0FD0
// Canonical corpus name: RestartGate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RestartGate_004a0fd0.c

void UnknownObject::RestartGate()
{
    // Session restart and main-menu transition gate polled by GamePostMainLoop. Priority-ordered flag evaluation: byte_7CE25D requests a mini-restart (cleanup pass over vehicle slots, then return 4); byte_7CE25E or byte_7CE260 request a full restart (return 6); dword_7CE264 in state 1 gates a restart on dword_7CE258. Otherwise it walks a restart decision via sub_404B60/sub_485B90, updates a countdown state machine (byte_7CE269 / dword_7CE26C / dword_7CE258), drives the session type/init-guard path (dword_7CE264 -> dword_7C569C = 6 or ConditionalInitGuard), scans the input action map for a menu transition, and finally returns the session-type global dword_7C569C.
    // GUARD: Guard on mini-restart flag byte_7CE25D; if set, take the cleanup path. [global:0x007CE25D]
    // ASSIGNMENT: Clear the mini-restart flag byte_7CE25D to 0. [global:0x007CE25D]
    // GUARD: Guard on session type dword_7C56A4 equal to 7 to select the vehicle cleanup loop. [global:0x007C56A4]
    // LOOP: Loop i from 0 while i < dword_5C329C, calling FieldCopy_c330 on each vehicle pointer dword_7C54F0[i] advanced by 16436 bytes. [global:0x005C329C, global:0x007C54F0, callee:0x004BC330]
    // CALL: If ScoringGateCheck() is true and the dword at player vehicle pointer dword_7C54E8 + 13000 equals 1, call SessionStateTransition on dword_7C54E8 + 12 with two zero arguments. [callee:0x0042BC10, global:0x007C54E8, callee:0x004EF5A0]
    // RETURN: Return 4 for the mini-restart request. [source:raw]
    // GUARD: Guard on full-restart flags byte_7CE25E or byte_7CE260; if either is set, clear byte_7CE25E and return 6. [global:0x007CE25E, global:0x007CE260]
    // ASSIGNMENT: Clear the full-restart flag byte_7CE25E to 0. [global:0x007CE25E]
    // RETURN: Return 6 for the full-restart request. [source:raw]
    // GUARD: Guard on dword_7CE264 equal to 1; if dword_7CE258 is also 1, return 6 immediately, otherwise continue at the shared label. [global:0x007CE264, global:0x007CE258]
    // CALL: Call sub_404B60 with a pointer to the session directory suffix global dword_5EA43C. [callee:0x00404B60, global:0x005EA43C]
    // GUARD: Guard on byte_7CE254; when it is zero, skip the sub_485B90 restart decision path. [global:0x007CE254]
    // ASSIGNMENT: Capture the post-increment value of the frame/counter global dword_7CE250 to pass as a tick argument. [global:0x007CE250]
    // CALL: Call sub_485B90 with the tick value and byte_7CE25F as arguments and store its result. [callee:0x00485B90, global:0x007CE25F]
    // GUARD: Guard on the sub_485B90 result equal to -1 or 3; either returns 6 for a full restart. [source:raw]
    // GUARD: Guard on the sub_485B90 result equal to 4; return that result directly. [source:raw]
    // CALCULATION: Countdown state machine: if byte_7CE269 is set, subtract the double constant dbl_8AFE98 from the float stored in dword_7CE26C and write the result back. [global:0x007CE269, global:0x007CE26C, global:0x008AFE98]
    // GUARD: When the countdown dword_7CE26C reaches zero or below, clear byte_7CE269, zero dword_7CE26C and set dword_7CE258 to 1. [global:0x007CE269, global:0x007CE26C, global:0x007CE258]
    // GUARD: When dword_7CE258 is not 1, if it equals 2 set it to 1 and continue at the shared label; otherwise proceed directly. [global:0x007CE258]
    // GUARD: Branch on dword_7CE264: when equal to 1 set dword_7C569C to 6, otherwise call ConditionalInitGuard. [global:0x007CE264, global:0x007C569C, callee:0x004A0CF0]
    // ASSIGNMENT: Set the session type global dword_7C569C to 6 to signal a restart/menu transition. [global:0x007C569C]
    // LOOP: When byte_7CE254 is zero and dword_7CB218 is positive, iterate the input action map word_7CB21C; for each element equal to 1, call ByteFieldExtractorWithShift on dword_5EA43C, and on success set dword_7C569C to 6 and call MainMenuTransition, otherwise set dword_7CE258 to 1. [global:0x007CE254, global:0x007CB218, global:0x007CB21C, callee:0x00404F00, global:0x005EA43C, global:0x007C569C, callee:0x00404F30, global:0x007CE258]
    // CALL: Call sub_4A0CB0 to complete the per-poll housekeeping. [callee:0x004A0CB0]
    // RETURN: Return the session type global dword_7C569C as the effective state request. [global:0x007C569C]

    // Conservative worker pseudocode:
    //   int RestartGate() {
    //     if (byte_7CE25D) {
    //       byte_7CE25D = 0;
    //       if (dword_7C56A4 == 7)
    //         for (i = 0; i < dword_5C329C; ++i)
    //           FieldCopy_c330(dword_7C54F0[i] + 16436);
    //       if (ScoringGateCheck() && *(dword_7C54E8 + 13000) == 1)
    //         SessionStateTransition(dword_7C54E8 + 12, 0, 0);
    //       return 4;
    //     }
    //     if (byte_7CE25E || byte_7CE260) { byte_7CE25E = 0; return 6; }
    //     if (dword_7CE264 == 1) { if (dword_7CE258 == 1) return 6; } else {
    //       sub_404B60(&dword_5EA43C);
    //       if (byte_7CE254) {
    //         v2 = dword_7CE250++;
    //         result = sub_485B90(v2, byte_7CE25F);
    //         if (result == -1 || result == 3) return 6;
    //         if (result == 4) return result;
    //       }
    //     }
    //     if (byte_7CE269 && (*(float*)&dword_7CE26C -= dbl_8AFE98) <= 0.0)
    //       { byte_7CE269 = 0; dword_7CE26C = 0; dword_7CE258 = 1; }
    //     else if (dword_7CE258 != 1)
    //       { if (dword_7CE258 == 2) dword_7CE258 = 1; }
    //     else {
    //       if (dword_7CE264 == 1) dword_7C569C = 6;
    //       else ConditionalInitGuard();
    //     }
    //     if (!byte_7CE254) {
    //       for (v4 = 0; v4 < dword_7CB218; ++v4)
    //         if (word_7CB21C[v4] == 1)
    //           if (ByteFieldExtractorWithShift(&dword_5EA43C))
    //             { dword_7C569C = 6; MainMenuTransition(&dword_5EA43C); }
    //           else dword_7CE258 = 1;
    //     }
    //     sub_4A0CB0();
    //     return dword_7C569C;
    //   }
    // UNRESOLVED: The purpose of the 16436-byte stride and the semantics of FieldCopy_c330's field copy are not established here.
    // UNRESOLVED: Globals flt_59E440, unk_5EC6D0 and unk_7CE24C are listed in the packet but do not appear in the raw source text; their role is unknown.
}
