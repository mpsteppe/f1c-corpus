// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042DB20
// Canonical corpus name: GameExit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GameExit_0042db20.c

void UnknownObject::GameExit()
{
    // Full-game teardown entry point. Writes game state 7 (exiting) into this+0x0, emits an entry debug log, then shuts down every major subsystem in sequence: sound, special effects, scene/session stubs, hardware input, dynamic manager, scoring gate, on-screen display, video manager, game-module manager, and session. Emits a second exit debug log and returns CloseHandle(hObject).
    // ASSIGNMENT: Write literal 7 (exiting) into this+0x0 as the first action of teardown [field:this:0x00000000, source:raw]
    // GUARD: StringSplitLoop(2, aDDevF119992002_11, 678) gates the first debug write; when it returns non-zero, DebugLogWrite(&dword_8AD25C, aEnteredGameExi) logs entry into GameExit [callee:0x004D7A50, callee:0x004D7AA0, global:0x005C3590, global:0x005C36A8, global:0x008AD25C, source:raw]
    // CALL: Sound_Exit(&byte_8AC494) shuts down the sound subsystem [callee:0x004C8D00, global:0x008AC494, source:raw]
    // CALL: SpecialFX_Exit(&dword_8ACEA0) shuts down the special-effects subsystem [callee:0x004CFFF0, global:0x008ACEA0, source:raw]
    // CALL: EmptyStub_0170(dword_5EA2C0) and EmptyStub_0170(&unk_7CE24D) release the scene-setup pointer and the session-transition stub object [callee:0x004B0170, global:0x005EA2C0, global:0x007CE24D, source:raw]
    // CALL: HWInput_Exit(&ppvOut) shuts down the hardware-input subsystem [callee:0x00455F00, global:0x007CA590, source:raw]
    // CALL: DynMan_Exit() tears down the dynamic manager [callee:0x0042CA70, source:raw]
    // CALL: sub_4BA770(&dword_8AB6E4) releases the scoring-gate object [callee:0x004BA770, global:0x008AB6E4, source:raw]
    // CALL: OnScreen_Exit(&dword_7CE048) shuts down the on-screen display subsystem [callee:0x0049F120, global:0x007CE048, source:raw]
    // CALL: VidMan_Exit(&unk_8AFE18) shuts down the video-manager subsystem [callee:0x004FAD00, global:0x008AFE18, source:raw]
    // CALL: ConditionalObjectCleanup(&dword_7CD25C) conditionally destroys the game-module-manager object [callee:0x00464670, global:0x007CD25C, source:raw]
    // CALL: SessionReset() resets session/season state [callee:0x0042D350, source:raw]
    // GUARD: StringSplitLoop(2, aDDevF119992002_19, 433) gates the second debug write; on non-zero DebugLogWrite(&dword_8AD25C, aEnteredOsmanEx) logs entry into the OSMan exit path [callee:0x004D7A50, callee:0x004D7AA0, global:0x008AD25C, source:raw]
    // RETURN: CloseHandle(hObject) closes the game main handle and its result is returned; the function is invoked from GameMainEntry (0x0045B200) [caller:0x0045B200, source:raw]

    // Conservative worker pseudocode:
    //   this->state = 7;
    //   if (StringSplitLoop(2, aDDevF119992002_11, 678)) DebugLogWrite(&dword_8AD25C, aEnteredGameExi);
    //   Sound_Exit(&byte_8AC494);
    //   SpecialFX_Exit(&dword_8ACEA0);
    //   EmptyStub_0170(dword_5EA2C0);
    //   EmptyStub_0170(&unk_7CE24D);
    //   HWInput_Exit(&ppvOut);
    //   DynMan_Exit();
    //   sub_4BA770(&dword_8AB6E4);
    //   OnScreen_Exit(&dword_7CE048);
    //   VidMan_Exit(&unk_8AFE18);
    //   ConditionalObjectCleanup(&dword_7CD25C);
    //   SessionReset();
    //   if (StringSplitLoop(2, aDDevF119992002_19, 433)) DebugLogWrite(&dword_8AD25C, aEnteredOsmanEx);
    //   return CloseHandle(hObject);
    // UNRESOLVED: Globals unk_5EC6D0 and unk_7CE2A4 are flagged as read by the packet facts but never appear in the raw decompiled source for this function
    // UNRESOLVED: The final StringSplitLoop/DebugLogWrite pair references string literals (aDDevF119992002_19, aEnteredOsmanEx) that are not listed among the packet globals
}
