// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A0C60
// Canonical corpus name: SessionMenuModeSwitch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SessionMenuModeSwitch_004a0c60.c

void UnknownObject::SessionMenuModeSwitch()
{
    // Session-to-menu mode switch called after race completion. Reads a shifted byte field from dword_5EA43C: if non-zero it forces dword_7C569C to 6 and calls MainMenuTransition to enter the main menu; otherwise, when dword_7CE814 is zero, it runs the post-race one-time init path (ReciprocalWithSignCheck on flt_5EA4E8 with 0.5, then GlobalStateOneTimeInitializer on unk_7CE24D). Both branches return 0.
    // GUARD: Entry branch on the shifted byte field extracted from dword_5EA43C; non-zero selects the main-menu transition path. [callee:0x00404F00, global:0x005EA43C, source:raw]
    // CALL: ByteFieldExtractorWithShift(&dword_5EA43C) reads and extracts a shifted byte field from dword_5EA43C (setup-directory suffix flag) to choose the menu mode path. [callee:0x00404F00, global:0x005EA43C, source:raw]
    // ASSIGNMENT: On the menu path, set dword_7C569C to 6 (session type). [global:0x007C569C, source:raw]
    // CALL: MainMenuTransition(&dword_5EA43C) transitions the game to the main menu screen. [callee:0x00404F30, global:0x005EA43C, source:raw]
    // GUARD: On the non-menu path, the post-race init sequence runs only when dword_7CE814 is zero (qualifying DSQ not enabled). [global:0x007CE814, source:raw]
    // CALL: ReciprocalWithSignCheck(&flt_5EA4E8, 0.5) computes a reciprocal with sign check on the post-race offset flag flt_5EA4E8. [callee:0x00408420, global:0x005EA4E8, source:raw]
    // CALL: GlobalStateOneTimeInitializer(&unk_7CE24D) performs one-time initialization of the session transition state. [callee:0x004A0D10, global:0x007CE24D, source:raw]
    // RETURN: Both control paths return 0. [function:0x004A0C60, source:raw]

    // Conservative worker pseudocode:
    //   int SessionMenuModeSwitch()
    //   {
    //     if (ByteFieldExtractorWithShift(&dword_5EA43C))
    //     {
    //       dword_7C569C = 6;
    //       MainMenuTransition(&dword_5EA43C);
    //       return 0;
    //     }
    //     if (!dword_7CE814)
    //     {
    //       ReciprocalWithSignCheck(&flt_5EA4E8, 0.5);
    //       GlobalStateOneTimeInitializer(&unk_7CE24D);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Enum meaning of the dword_7C569C value 6 and the exact semantics of the byte field extracted from dword_5EA43C are only context-derived.
    // UNRESOLVED: Identity and layout of flt_5EA4E8 and unk_7CE24D remain names-by-context; no field offsets are grounded here.
    // UNRESOLVED: Which caller (RaceFinishHandler, sub_4A0CB0, LapCompletion) triggers which branch is not resolvable from this function alone.
    // UNRESOLVED: Legacy ABI label Session_Menu_Mode_Switch is retained but not independently corroborated.
}
