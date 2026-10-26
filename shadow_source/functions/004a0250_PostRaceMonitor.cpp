// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A0250
// Canonical corpus name: sub_4A0250
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A0250_004a0250.c

void UnknownObject::PostRaceMonitor()
{
    // Post-race session state transition handler. Cleans up the D3D resource list, shows the cursor, and - only when the session type is race (7) and the championship mode is not 6 - probes the post-race monitor state, optionally activates post-race monitor dispatch, or sets a session flag path. Then tears down a resource, sets global session state, conditionally closes the scoring gate and updates the scene render, runs two virtual calls on global objects, dispatches per-vehicle state handlers, and ends with a session-state dispatch chain and a zero-guarded division. Always returns 0.
    // CALL: Call D3DResourceListCleanup(dword_8AFE88) to release D3D resources held in the list rooted at dword_8AFE88. [callee:0x00554E10, global:0x008AFE88]
    // CALL: Loop calling ShowCursor(1) until its return count is > 0, forcing the system cursor to appear. [global:0x0059E2C4]
    // GUARD: Enter the post-race path only when dword_7C56A4 == 7 (race session) and dword_7D0410 != 6 (championship mode not 6). [global:0x007C56A4, global:0x007D0410]
    // CALL: Call sub_4D21D0(&dword_8ACEE0); the result flags whether the post-race monitor should activate. [callee:0x004D21D0, global:0x008ACEE0]
    // ASSIGNMENT: Record v1 = (dword_7D0410 == 5), distinguishing the 'mode 5' championship path. [global:0x007D0410]
    // GUARD: When the probe returned true and the player vehicle object pointer at dword_7C54E8 + 13000 is null, call sub_4BC060(1). [global:0x007C54E8, callee:0x004BC060]
    // GUARD: When the probe returned true and mode is not 5, build a post-race monitor object via the virtual interface at dword_7CD8C0 (vtable slot 28, called with 33). [global:0x007CD8C0, global:0x007D0410]
    // CALL: If the monitor object was created, call sub_46BA20(v2, 0) then FieldSetter(v3) on it. [callee:0x0046BA20, callee:0x0046C030]
    // CALL: Call LookupDispatch(dword_7CD8C0, aPostRaceMonito, -1), dispatching the string 'PostRaceMonito' on the command interface with the sentinel -1. [callee:0x00497940, global:0x007CD8C0, global:0x005CCFE8]
    // GUARD: Else branch of the probe: when mode is not 5 and dword_7CEC90 is zero, take the session-flag path. [global:0x007D0410, global:0x007CEC90]
    // CALL: Call GlobalFlagSetter(&unk_7CE24D), sub_42D210(&dword_7C569C, 1), and ArithmeticComparison_8d60(&byte_8AC494) to set up the non-monitor post-race state. [callee:0x004A0DA0, global:0x007CE24D, callee:0x0042D210, global:0x007C569C, callee:0x004C8D60, global:0x008AC494]
    // CALL: Call ResourceDestroy(&dword_8AD238) to release the session resource. [callee:0x004D5840, global:0x008AD238]
    // CALL: Call GlobalStateSetter(1) to advance the global session state. [callee:0x004A0D30]
    // GUARD: When ScoringGateCheck() succeeds, enter the gate-teardown block. [callee:0x0042BC10]
    // CALL: Call ConditionalGate(dword_7C54E8 + 12) then SceneRenderUpdate(0) to close the scoring gate and refresh the scene. [callee:0x004EFAC0, global:0x007C54E8, callee:0x004C6D90]
    // CALL: Call VirtualCallOnDAT008ac4c4_8d80(&byte_8AC494) and VirtualCallOnDAT008ac4c4(&flt_8AC4B0) on the two global objects. [callee:0x004C8D80, global:0x008AC494, callee:0x004C8180, global:0x008AC4B0]
    // LOOP: Loop over all vehicles with i from 0 to dword_5C329C. [global:0x005C329C]
    // GUARD: For each vehicle, if the byte at dword_7C54F0[i] + 196 is set, call StateHandlerDispatch(0). [global:0x007C54F0, callee:0x004F7010]
    // CALL: Call ShortComputation_d410(&dword_5EA510) and GameStateDispatchChain(&dword_5EA510, *(dword_7C54F0[dword_7C54E4] + 18580)) to dispatch the session state for the current vehicle. [callee:0x0040D410, global:0x005EA510, callee:0x0040D240, global:0x007C54F0, global:0x007C54E4]
    // CALL: Call SafeDivisionWithZeroGuard(&flt_5EA4E8, 0.0), a guarded computation using the float global. [callee:0x00408450, global:0x005EA4E8]
    // CALL: Call sub_4D8760(-1, 0). [callee:0x004D8760]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4A0250() {
    //     D3DResourceListCleanup(dword_8AFE88);
    //     while (ShowCursor(1) <= 0) {}
    //     if (dword_7C56A4 == 7 && dword_7D0410 != 6) {
    //       bool probe = sub_4D21D0(&dword_8ACEE0);
    //       bool isMode5 = (dword_7D0410 == 5);
    //       if (probe) {
    //         if (!*(int*)(dword_7C54E8 + 13000)) sub_4BC060(1);
    //         if (!isMode5) {
    //           void* mon = (*(void* (__thiscall**)(void*, int))**(int**)dword_7CD8C0)(dword_7CD8C0, 33);
    //           if (mon) { sub_46BA20(mon, 0); FieldSetter(mon); }
    //         }
    //         LookupDispatch((void*)dword_7CD8C0, aPostRaceMonito, -1);
    //       } else if (dword_7D0410 != 5 && !dword_7CEC90) {
    //         GlobalFlagSetter(&unk_7CE24D);
    //         sub_42D210(&dword_7C569C, 1);
    //         ArithmeticComparison_8d60(&byte_8AC494);
    //       }
    //     }
    //     ResourceDestroy(&dword_8AD238);
    //     GlobalStateSetter(1);
    //     if (ScoringGateCheck()) { ConditionalGate(dword_7C54E8 + 12); SceneRenderUpdate(0); }
    //     VirtualCallOnDAT008ac4c4_8d80(&byte_8AC494);
    //     VirtualCallOnDAT008ac4c4(&flt_8AC4B0);
    //     for (i = 0; i < dword_5C329C; ++i) if (*(char*)(dword_7C54F0[i] + 196)) StateHandlerDispatch(0);
    //     ShortComputation_d410((int)&dword_5EA510);
    //     GameStateDispatchChain(&dword_5EA510, *(int*)(dword_7C54F0[dword_7C54E4] + 18580));
    //     SafeDivisionWithZeroGuard((int)&flt_5EA4E8, 0.0);
    //     sub_4D8760(-1, 0);
    //     return 0;
    //   }
    // UNRESOLVED: Globals unk_5EC6D0, dword_8AD298 and dword_8B78A0 are listed as referenced by the IDB but do not appear in the decompiled source text; their role in this function is unknown.
    // UNRESOLVED: The ABI legacy name is Post_Race_Monitor; owner class is unconfirmed.
    // UNRESOLVED: The call through the virtual slot on dword_7CD8C0 has no resolved callee symbol.
}
