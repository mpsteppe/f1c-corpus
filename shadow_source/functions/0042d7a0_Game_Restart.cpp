// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042D7A0
// Canonical corpus name: Game_Restart
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Game_Restart_0042d7a0.c

void UnknownObject::Game_Restart()
{
    // Game restart orchestrator: sets the game state flag this[0] to 4 (restart/loading phase), logs the restart entry when the device path matches, then invokes the restart/reset entry point of every engine subsystem in dependency order — synchronization, sound, memory/global zeroing, steward, special FX, hardware input, dynamics, camera, render, on-screen state, scoring, video, player file, and HUD — returning 0.
    // ASSIGNMENT: Write the restart/loading state value 4 into the game state flag this[0]. [field:this:0x00000000, source:raw]
    // GUARD: If StringSplitLoop(2, aDDevF119992002_11, 509) returns nonzero, log the restart entry message. [callee:0x004D7A50, global:0x005C3590, source:raw]
    // CALL: DebugLogWrite(&dword_8AD25C, aEnteredGameRes) writes the 'entered game (restart)' message to the debug log buffer. [callee:0x004D7AA0, global:0x008AD25C, global:0x005C3658, source:raw]
    // CALL: SynchronizeWithServer(&dword_7CD25C) synchronizes the game module manager with the server. [callee:0x00464290, global:0x007CD25C, source:raw]
    // CALL: Sound_Restart(&byte_8AC494) reinitializes the sound subsystem state block. [callee:0x004C8B20, global:0x008AC494, source:raw]
    // CALL: ArrayZeroInit(&unk_7CE2F0) zeroes the AI/session array block. [callee:0x004A40F0, global:0x007CE2F0, source:raw]
    // CALL: GlobalZeroInit(&unk_7CE24D) zeroes the session transition flag block. [callee:0x004A0FB0, global:0x007CE24D, source:raw]
    // CALL: Steward_Restart(&dword_8ACEE0) reinitializes the steward subsystem state. [callee:0x004D3CF0, global:0x008ACEE0, source:raw]
    // CALL: sub_4FCC30(&unk_8AFEC0) reinitializes its engine subsystem block. [callee:0x004FCC30, global:0x008AFEC0, source:raw]
    // CALL: SurfaceHeightfieldCollisionCallback((int)dword_5EA2C0) reconnects the scene setup pointer to the heightfield collision callback. [callee:0x00404250, global:0x005EA2C0, source:raw]
    // CALL: SpecialFX_Restart(&dword_8ACEA0) reinitializes the special-effects subsystem. [callee:0x004CFC90, global:0x008ACEA0, source:raw]
    // CALL: HWInput_Restart(&ppvOut) reinitializes hardware input using the module pointer array. [callee:0x00455DA0, global:0x007CA590, source:raw]
    // CALL: DynMan_Restart() reinitializes the dynamics manager. [callee:0x0042C3B0, source:raw]
    // CALL: CamMan_Restart((int)&dword_5EA510) reinitializes the camera manager session. [callee:0x0040C9E0, global:0x005EA510, source:raw]
    // CALL: Render_Restart(&byte_8AB678) reinitializes the renderer state block. [callee:0x004B4060, global:0x008AB678, source:raw]
    // CALL: OnScreen_Restart(&dword_7CE048) reinitializes the on-screen/race session state. [callee:0x0049F000, global:0x007CE048, source:raw]
    // CALL: sub_4BA460(&dword_8AB6E4) reinitializes the scoring gate block. [callee:0x004BA460, global:0x008AB6E4, source:raw]
    // CALL: VidMan_Restart(&unk_8AFE18) reinitializes the video manager state. [callee:0x004FA640, global:0x008AFE18, source:raw]
    // CALL: sub_4A1830(&unk_7CE2A4) reinitializes its session block. [callee:0x004A1830, global:0x007CE2A4, source:raw]
    // CALL: PlayerFile_Restart(&byte_7CE498) reinitializes the autoload config/player file block. [callee:0x004B18D0, global:0x007CE498, source:raw]
    // CALL: HUDDisplayDataReset(dword_5EB978) resets HUD display data using the game state array pointer. [callee:0x00418E50, global:0x005EB978, source:raw]
    // CALL: sub_4D7B00(&unk_8AD264) reinitializes its log/session block. [callee:0x004D7B00, global:0x008AD264, source:raw]
    // RETURN: Return 0 after the full restart sequence completes. [source:raw]

    // Conservative worker pseudocode:
    //   int Game_Restart(this) {
    //     this[0] = 4;
    //     if (StringSplitLoop(2, aDDevF119992002_11, 509)) DebugLogWrite(&dword_8AD25C, aEnteredGameRes);
    //     SynchronizeWithServer(&dword_7CD25C);
    //     Sound_Restart(&byte_8AC494);
    //     ArrayZeroInit(&unk_7CE2F0);
    //     GlobalZeroInit(&unk_7CE24D);
    //     Steward_Restart(&dword_8ACEE0);
    //     sub_4FCC30(&unk_8AFEC0);
    //     SurfaceHeightfieldCollisionCallback((int)dword_5EA2C0);
    //     SpecialFX_Restart(&dword_8ACEA0);
    //     HWInput_Restart(&ppvOut);
    //     DynMan_Restart();
    //     CamMan_Restart((int)&dword_5EA510);
    //     Render_Restart(&byte_8AB678);
    //     OnScreen_Restart(&dword_7CE048);
    //     sub_4BA460(&dword_8AB6E4);
    //     VidMan_Restart(&unk_8AFE18);
    //     sub_4A1830(&unk_7CE2A4);
    //     PlayerFile_Restart(&byte_7CE498);
    //     HUDDisplayDataReset(dword_5EB978);
    //     sub_4D7B00(&unk_8AD264);
    //     return 0;
    //   }
    // UNRESOLVED: unk_5EC6D0 is listed as an accessed global by the fact table but does not appear in the decompiled body; its role in the restart sequence is unknown.
    // UNRESOLVED: Ownership of this and the exact meaning of the state value 4 are not established; the caller GameMainEntry (0045b200) drives the game state machine.
}
