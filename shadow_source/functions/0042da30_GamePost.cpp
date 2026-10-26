// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042DA30
// Canonical corpus name: Game_Post
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Game_Post_0042da30.c

void UnknownObject::GamePost()
{
    // Game post-frame dispatch. Sets the game state word *this to 6 (post-frame phase), conditionally logs 'entered game post' when StringSplitLoop(2, devicePath, 645) succeeds, then sequentially calls every engine subsystem's Post() hook — guarded dispatch, nested call loop, sound, FX delegation, special FX, scene setup, global flag clear, steward, hardware input, dynamics, camera, render, on-screen display, video manager, session object, player file and session state — and finally writes dword_7C56A0 = 3. Returns the SessionStateByte7CE25FSetter result.
    // ASSIGNMENT: *this = 6: set the game state/phase word to 6 (post-frame phase). [field:this:0x00000000, source:raw]
    // GUARD: If StringSplitLoop(2, aDDevF119992002_11, 645) returns non-zero, log DebugLogWrite(&dword_8AD25C, aEnteredGamePos). [callee:0x004D7A50, callee:0x004D7AA0, global:0x005C3590, global:0x005C3690, global:0x008AD25C, source:raw]
    // CALL: GuardedDispatchWithStateCheck(&dword_8AB6E4): guarded subsystem dispatch. [callee:0x004BA740, global:0x008AB6E4, source:raw]
    // CALL: F_65xNestedCallLoop(&dword_8AB710): nested call loop over the UI/widget list. [callee:0x004BDDE0, global:0x008AB710, source:raw]
    // CALL: Sound_Post(&byte_8AC494): sound subsystem post-frame hook. [callee:0x004C8CA0, global:0x008AC494, source:raw]
    // CALL: TwoCallDelegation_d6d0(&unk_8AFEC0): two-call delegation hook. [callee:0x004FD6D0, global:0x008AFEC0, source:raw]
    // CALL: SpecialFX_Post(&dword_8ACEA0): special FX subsystem post-frame hook. [callee:0x004CFED0, global:0x008ACEA0, source:raw]
    // CALL: ShortComputation_45f0((int)dword_5EA2C0): scene/setup-related computation on dword_5EA2C0. [callee:0x004045F0, global:0x005EA2C0, source:raw]
    // CALL: GlobalFlagClear(&unk_7CE24D): clear a session/transition flag. [callee:0x004A11B0, global:0x007CE24D, source:raw]
    // CALL: Steward_Post(&dword_8ACEE0): steward/race-rule subsystem post-frame hook. [callee:0x004D4600, global:0x008ACEE0, source:raw]
    // CALL: HWInput_Post(&ppvOut): hardware input subsystem post-frame hook. [callee:0x00455E70, global:0x007CA590, source:raw]
    // CALL: DynMan_Post(): dynamics manager post-frame hook (no argument). [callee:0x0042C9F0, source:raw]
    // CALL: CamMan_Post((int)&dword_5EA510): camera manager post-frame hook on the session manager object. [callee:0x0040CCE0, global:0x005EA510, source:raw]
    // CALL: Render_Post(&byte_8AB678): render subsystem post-frame hook. [callee:0x004B4170, global:0x008AB678, source:raw]
    // CALL: OnScreen_Post(&dword_7CE048): on-screen display/HUD post-frame hook. [callee:0x0049F0D0, global:0x007CE048, source:raw]
    // CALL: VidMan_Post(&unk_8AFE18): video manager post-frame hook. [callee:0x004FAC00, global:0x008AFE18, source:raw]
    // CALL: sub_4A1830(&unk_7CE2A4): session-object post-frame hook. [callee:0x004A1830, global:0x007CE2A4, source:raw]
    // CALL: PlayerFile_Post(&byte_7CE498): player-file subsystem post-frame hook. [callee:0x004B1900, global:0x007CE498, source:raw]
    // CALL: result = SessionStateByte7CE25FSetter(&dword_7CD25C): session-state post-frame hook; its return value is propagated. [callee:0x00464600, global:0x007CD25C, source:raw]
    // ASSIGNMENT: dword_7C56A0 = 3: set the multiplayer/flags global to 3. [global:0x007C56A0, source:raw]
    // RETURN: Return the SessionStateByte7CE25FSetter result. [function:0x0042DA30, source:raw]

    // Conservative worker pseudocode:
    //   *this = 6;
    //   if (StringSplitLoop(2, aDDevF119992002_11, 645)) DebugLogWrite(&dword_8AD25C, aEnteredGamePos);
    //   GuardedDispatchWithStateCheck(&dword_8AB6E4);
    //   F_65xNestedCallLoop(&dword_8AB710);
    //   Sound_Post(&byte_8AC494);
    //   TwoCallDelegation_d6d0(&unk_8AFEC0);
    //   SpecialFX_Post(&dword_8ACEA0);
    //   ShortComputation_45f0((int)dword_5EA2C0);
    //   GlobalFlagClear(&unk_7CE24D);
    //   Steward_Post(&dword_8ACEE0);
    //   HWInput_Post(&ppvOut);
    //   DynMan_Post();
    //   CamMan_Post((int)&dword_5EA510);
    //   Render_Post(&byte_8AB678);
    //   OnScreen_Post(&dword_7CE048);
    //   VidMan_Post(&unk_8AFE18);
    //   sub_4A1830(&unk_7CE2A4);
    //   PlayerFile_Post(&byte_7CE498);
    //   result = SessionStateByte7CE25FSetter(&dword_7CD25C);
    //   dword_7C56A0 = 3;
    //   return result;
    // UNRESOLVED: Global unk_5EC6D0 is flagged as read by the extractor but does not appear in the decompiled source text; its role here is unknown.
    // UNRESOLVED: The semantics of StringSplitLoop's return (why it gates the debug log) are outside this packet.
    // UNRESOLVED: Each _Post call receives a global object pointer but no owner evidence for those objects is present in this packet; subsystem role names come from callee names only.
}
