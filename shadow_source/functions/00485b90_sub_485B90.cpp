// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00485B90
// Canonical corpus name: sub_485B90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_485B90_00485b90.c

void UnknownObject::sub_485B90()
{
    // Top-level menu init and game state machine. Sets session init state dword_5CC9E8 = 5 and branches: if the game interface (dword_7CD8C0) already exists it takes a fast re-entry path (menu state 2, show cursor, server/client session init), otherwise it runs full initialization (allocate and init the 8612-byte screen struct, renderer viewport, player profile, UI element tree, audio mixer, multiplayer auto-join retry). Afterwards it dispatches on dword_5CC9E8: -1 shutdown via GlobalManagerShutdownSequence, 2 session-host setup via sub_4A00A0, 1 game-start path (list traversal, hide cursor, scene match, leave session), and 5 -> sub_496E90 with reset to 0. a1 non-zero skips the re-entry UI frame; a2 non-zero forces shutdown.
    // ASSIGNMENT: Set the session init state dword_5CC9E8 = 5 (menu/init entry). [global:0x005CC9E8, function:0x00485B90, source:raw]
    // GUARD: Branch on whether the game interface dword_7CD8C0 is already allocated: non-null takes the re-entry path, null takes full initialization. [global:0x007CD8C0, source:raw]
    // STATE_TRANSITION: Re-entry path: skip ahead when a1 is non-zero; otherwise set menu state dword_5CC9E4 = 2 and show the cursor until ShowCursor(1) returns positive. [global:0x005CC9E4, global:0x0059E2C4, source:raw]
    // CALL: Re-entry session init: sub_4A0A80(&unk_7CE24C) when dword_7C569C == 5 (server), else SystemOSAPICall(&unk_7CE24C). [callee:0x004A0A80, callee:0x004A03F0, global:0x007C569C, global:0x007CE24C, source:raw]
    // CALL: Full-init path: allocate an 8612-byte screen struct via OperatorNewNhMallocWrapper, initialize it with ScreenDataStructInit and store into dword_7CD8C0 (0 on allocation failure). [callee:0x00587C03, callee:0x0047F370, global:0x007CD8C0, source:raw]
    // CALL: Renderer setup: Accessor(), SingleCallWrapper_1760(0, 0, 800, 600), sub_4944A0(screen, 0, 0, 1) and FieldSetter_63c0(screen). [callee:0x00490920, callee:0x00491760, callee:0x004944A0, callee:0x004963C0, global:0x007CD8C0, source:raw]
    // CALL: Load/read the player profile file (PlayerNameNeverUsedProfileFileCreateRead(&byte_7CE498)) and iterate-initialize the UI element tree (LinkedListSummationWithIterator(screen)). [callee:0x004B03F0, callee:0x00496840, global:0x007CE498, global:0x007CD8C0, source:raw]
    // ASSIGNMENT: Copy the DSP transform parameter into the UI color intensity field: dword_5CC9E0 = LODWORD(flt_7CF2CC). [global:0x005CC9E0, global:0x007CF2CC, source:raw]
    // CALL: Initialize the audio mixer device (AudioMixerDeviceInit(&byte_8AC494)) and run the short session init computation (ShortComputation_0ad0(&unk_7CE24C)), then show the cursor. [callee:0x004C85D0, callee:0x004A0AD0, global:0x008AC494, global:0x007CE24C, global:0x0059E2C4, source:raw]
    // CALL: Run the multiplayer auto-join retry (AutoJoinRetryLoop(dword_7CD25C)) and the post-join session init (sub_463BC0(dword_7CD25C)). [callee:0x004637A0, callee:0x00463BC0, caller:0x004637A0, global:0x007CD25C, source:raw]
    // RETURN: If dword_5CC9E8 became -1 during auto-join, return -1 immediately. [global:0x005CC9E8, source:raw]
    // CALL: Re-entry UI frame (also reached from the re-entry path): virtual call at vtable offset +36 of the screen struct, then Accessor(), SingleCallWrapper_1760(0, 0, 800, 600) and sub_491770. [callee:0x00490920, callee:0x00491760, callee:0x00491770, global:0x007CD8C0, source:raw]
    // GUARD: Profile popup gate: when byte_7D2E40 is set, clear it, dispatch the add-profile popup via LookupDispatch(aPopupAddprofil, -1) and show the dialog via sub_4988D0(aAddProfileForc). [callee:0x00497940, callee:0x004988D0, global:0x007D2E40, global:0x005C6B5C, global:0x005CC1FC, source:raw]
    // CALL: Render the large UI pass (UILargeRender(screen)) and play the sound effect (SoundAudioPlayback(-1.0)). [callee:0x00496930, callee:0x004C8650, global:0x007CD8C0, source:raw]
    // STATE_TRANSITION: When dword_5CC9E8 == 5: run sub_496E90(0); if the state is still 5 afterwards, reset it to 0. [callee:0x00496E90, global:0x005CC9E8, source:raw]
    // GUARD: When a2 is non-zero, force the session init state to -1 (shutdown). [global:0x005CC9E8, source:raw]
    // CALL: Shutdown path: GlobalManagerShutdownSequence() then return dword_5CC9E8 when the state is -1. [callee:0x00485DF0, global:0x005CC9E8, source:raw]
    // CALL: State == 2 path: session-host setup via sub_4A00A0(&unk_7CE24C), then return dword_5CC9E8. [callee:0x004A00A0, global:0x007CE24C, global:0x005CC9E8, source:raw]
    // CALL: State == 1 game-start path: LinkedListTraversalWithVirtualCall(screen), hide the cursor (ShowCursor(0)), then sub_47F230(), SceneFilenameMatchAgainstBasePath() and sub_4A0030(&unk_7CE24C), returning dword_5CC9E8. [callee:0x00496E40, callee:0x0047F230, callee:0x0047F300, callee:0x004A0030, global:0x007CD8C0, global:0x007CE24C, global:0x005CC9E8, global:0x0059E2C4, source:raw]
    // RETURN: Return dword_5CC9E8 on the remaining states (0 passthrough). [global:0x005CC9E8, source:raw]

    // Conservative worker pseudocode:
    //   int sub_485B90(int a1, char a2) {
    //     dword_5CC9E8 = 5;
    //     if (dword_7CD8C0) {
    //       if (a1) goto dispatch;
    //       dword_5CC9E4 = 2; while (ShowCursor(1) <= 0);
    //       if (dword_7C569C == 5) sub_4A0A80(&unk_7CE24C); else SystemOSAPICall(&unk_7CE24C);
    //       goto reentry_frame;
    //     }
    //     v4 = OperatorNewNhMallocWrapper(8612);
    //     dword_7CD8C0 = v4 ? (int)ScreenDataStructInit(v4) : 0;
    //     Accessor(); SingleCallWrapper_1760(0, 0, 800, 600);
    //     sub_4944A0(dword_7CD8C0, 0, 0, 1); FieldSetter_63c0(dword_7CD8C0);
    //     PlayerNameNeverUsedProfileFileCreateRead(&byte_7CE498); LinkedListSummationWithIterator(dword_7CD8C0);
    //     dword_5CC9E0 = LODWORD(flt_7CF2CC); AudioMixerDeviceInit(&byte_8AC494); ShortComputation_0ad0(&unk_7CE24C);
    //     while (ShowCursor(1) <= 0);
    //     AutoJoinRetryLoop(dword_7CD25C); sub_463BC0(dword_7CD25C);
    //     if (dword_5CC9E8 == -1) return -1;
    //     if (!a1) {
    //   reentry_frame:
    //       (*(void (__thiscall **)(int))(*(DWORD *)dword_7CD8C0 + 36))(dword_7CD8C0);
    //       Accessor(); SingleCallWrapper_1760(0, 0, 800, 600); sub_491770(Accessor());
    //     }
    //   dispatch:
    //     if (byte_7D2E40) { byte_7D2E40 = 0; LookupDispatch(aPopupAddprofil, -1); sub_4988D0(aAddProfileForc); }
    //     UILargeRender(dword_7CD8C0);
    //     if (dword_5CC9E8 == 5) { sub_496E90(0); if (dword_5CC9E8 == 5) dword_5CC9E8 = 0; }
    //     SoundAudioPlayback(-1.0);
    //     if (a2) dword_5CC9E8 = -1;
    //     if (dword_5CC9E8 == -1) { GlobalManagerShutdownSequence(); return dword_5CC9E8; }
    //     if (dword_5CC9E8 != 1) { if (dword_5CC9E8 == 2) { sub_4A00A0(&unk_7CE24C); return dword_5CC9E8; } return dword_5CC9E8; }
    //     LinkedListTraversalWithVirtualCall(dword_7CD8C0); while (ShowCursor(0) >= 0);
    //     sub_47F230(); SceneFilenameMatchAgainstBasePath(); sub_4A0030(&unk_7CE24C);
    //     return dword_5CC9E8;
    //   }
    // UNRESOLVED: The screen struct's vtable offset +36 virtual call target is not resolvable here; its role depends on the screen object layout.
    // UNRESOLVED: Other callers (Options_Setup, RestartGate) are external to this reconstruction; their invocation context is not modeled.
    // UNRESOLVED: ABI name is null in the packet; owner stays UNKNOWN.
}
