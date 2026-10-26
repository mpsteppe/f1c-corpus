// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FA640
// Canonical corpus name: VidMan_Restart
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VidMan_Restart_004fa640.c

void UnknownObject::VidMan_Restart()
{
    // Resets video-manager state on game restart. Logs an entry message through the debug-message buffer when StringSplitLoop succeeds, clears the session-type state via sub_42D210, then switches on the session type to set/clear three global flags (windowed vs fullscreen display modes). For session type 7, a guarded sub_42D210(...,1) re-arms the session state when scoring gate, setup-dir condition flag, HUD-disabled byte, and session-state check all permit. Ends by resetting the renderer state on `this`, zeroing the input axis dead zone and a race-dynamics value, initializing a display-list branch, and returning a float setter result. Called from Game_Restart (0x0042D7A0).
    // GUARD: If StringSplitLoop(dword_8AD25C, 2, aDDevF119992002_26, 1136) returns nonzero, the debug-message buffer was split on the path-prefix token; only then is the entry log written. [callee:0x004D7A50, global:0x008AD25C, global:0x005D6DC4, function:0x004FA640]
    // CALL: DebugLogWrite(dword_8AD25C, aEnteredVidmanR) writes the 'entered VidMan restart' message using the debug-message buffer and its log string. [callee:0x004D7AA0, global:0x008AD25C, global:0x005D6EB4]
    // CALL: sub_42D210(&dword_7C569C, 0) clears the session-type state variable to 0 before the switch. [callee:0x0042D210, global:0x007C569C]
    // STATE_TRANSITION: switch(dword_7C56A4) selects the display-mode flag configuration by session type; dispatch uses the jump table jpt_4FA689. Cases 0-4 clear flag 64 and set flag 128; case 5 sets flag 64 and clears flag 128; cases 6-7 set both flags 64 and 128; default clears both. [global:0x007C56A4, global:0x004FA7B8]
    // CALL: Cases 0-4 (falling through LABEL_6): GlobalFlagSetClear(64, 0) then GlobalFlagSetClear(128, 1), then GlobalFlagSetClear(256, 1). [callee:0x0054A200, global:0x007C56A4]
    // CALL: Case 5: GlobalFlagSetClear(64, 1), GlobalFlagSetClear(128, 0), then (LABEL_6) GlobalFlagSetClear(256, 1). [callee:0x0054A200, global:0x007C56A4]
    // CALL: Cases 6-7: GlobalFlagSetClear(64, 1), GlobalFlagSetClear(128, 1), GlobalFlagSetClear(256, 0). [callee:0x0054A200, global:0x007C56A4]
    // CALL: Default case: GlobalFlagSetClear(64, 0), GlobalFlagSetClear(128, 0), GlobalFlagSetClear(256, 0). [callee:0x0054A200, global:0x007C56A4]
    // GUARD: Only when dword_7C56A4 == 7, and dword_8AB6E4 != 2, and !ConditionalFlagReturn(&dword_5EA43C), and byte_7CE254, and !SessionStateCheckWrapper(dword_7CD25C) is sub_42D210 re-arm invoked. [global:0x007C56A4, global:0x008AB6E4, callee:0x00404F10, global:0x005EA43C, global:0x007CE254, callee:0x00461DB0, global:0x007CD25C]
    // CALL: sub_42D210(&dword_7C569C, 1) sets the session-type state variable to 1, re-arming the session after the guarded check. [callee:0x0042D210, global:0x007C569C]
    // CALL: sub_4F9FC0(this, 0.0) resets the video-manager object state on this instance. [callee:0x004F9FC0, function:0x004FA640]
    // ASSIGNMENT: dbl_8AFEA8 = 0.0 zeroes the input-axis dead zone threshold. [global:0x008AFEA8, function:0x004FA640]
    // ASSIGNMENT: dword_8AFE84 = 0 zeroes the race-dynamics value. [global:0x008AFE84, function:0x004FA640]
    // CALL: ConditionalInitBranch(&dword_8AFCA8, dword_8AFCAC) initializes the render display-list pointer branch with the value at dword_8AFCAC. [callee:0x004F8F10, global:0x008AFCA8, global:0x008AFCAC]
    // RETURN: return GlobalFloatSetter(0) — the function's result is the float-setter call outcome for literal 0. [callee:0x004F9F70]

    // Conservative worker pseudocode:
    //   if (StringSplitLoop(dword_8AD25C, 2, aDDevF119992002_26, 1136))
    //       DebugLogWrite(dword_8AD25C, aEnteredVidmanR);
    //   sub_42D210(&dword_7C569C, 0);
    //   switch (dword_7C56A4) {
    //     case 0..4: flags 64=0, 128=1, 256=1; break;
    //     case 5:    flags 64=1, 128=0, 256=1; break;
    //     case 6..7: flags 64=1, 128=1, 256=0;
    //                if (type==7 && dword_8AB6E4!=2 && !ConditionalFlagReturn(&dword_5EA43C)
    //                    && byte_7CE254 && !SessionStateCheckWrapper(dword_7CD25C))
    //                    sub_42D210(&dword_7C569C, 1); break;
    //     default:   flags 64=0, 128=0, 256=0;
    //   }
    //   sub_4F9FC0(this, 0.0);
    //   dbl_8AFEA8 = 0.0;
    //   dword_8AFE84 = 0;
    //   ConditionalInitBranch(&dword_8AFCA8, dword_8AFCAC);
    //   return GlobalFloatSetter(0);
    // UNRESOLVED: Semantic roles of flag values 64, 128, 256 are not confirmed by packet evidence; existing analysis suggests windowed/fullscreen display modes (DERIVED).
    // UNRESOLVED: Reason for numeric literal 1136 as the StringSplitLoop token limit is unknown.
    // UNRESOLVED: The semantic meaning of the two-argument vs single-argument GlobalFlagSetClear calls (set/clear pairs) is not confirmed.
    // UNRESOLVED: Sub_42D210's state variable at 0x007C569C is only partially identified (session-type-related).
}
