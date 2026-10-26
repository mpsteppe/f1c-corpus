// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042D6B0
// Canonical corpus name: Game_Init
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Game_Init_0042d6b0.c

void UnknownObject::Game_Init()
{
    // Top-level game initialization orchestrator. Sets the game state to 3 (init phase), parses a device-initialization token string and logs when the split succeeds, then sequentially initializes all major subsystems: scoring gate setup, video manager (aborting with return 1 on failure), scene extent, physics/setup system, AI database, session transition flag, steward, hardware input, special effects, dynamics, camera manager, sound, render, UI buffers, on-screen system, and the session type. Returns 0 on success.
    // ASSIGNMENT: Write the game state field this[0] = 3, marking the init phase. [field:this:0x00000000]
    // GUARD: When StringSplitLoop(2, aDDevF119992002_11, 467) is non-zero, log that game.ini was entered. [callee:0x004D7A50, global:0x005C3590]
    // CALL: Call DebugLogWrite(&dword_8AD25C, aEnteredGameIni) to emit the entry log line. [callee:0x004D7AA0, global:0x008AD25C, global:0x005C3640]
    // CALL: Call sub_4BA1F0(&dword_8AB6E4) to set up the scoring gate module. [callee:0x004BA1F0, global:0x008AB6E4]
    // GUARD: When VidMan_Init(&unk_8AFE18) fails, abort immediately with return 1. [callee:0x004FA320, global:0x008AFE18]
    // CALL: Call SceneExtentComputation(&dword_8AB710) to compute the scene extent. [callee:0x004BDC10, global:0x008AB710]
    // CALL: Call sub_4FCAA0(&unk_8AFEC0) to initialize the physics/setup system. [callee:0x004FCAA0, global:0x008AFEC0]
    // CALL: Call AIDatabase_Init(dword_5EA2C0) to initialize the AI database. [callee:0x004040A0, global:0x005EA2C0]
    // CALL: Call EmptyStub_0170(&unk_7CE24D) on the session transition flag object. [callee:0x004B0170, global:0x007CE24D]
    // CALL: Call Steward_Init(&dword_8ACEE0) to initialize the race steward. [callee:0x004D38F0, global:0x008ACEE0]
    // CALL: Call HWInput_Init(&ppvOut) to initialize the hardware input module. [callee:0x00455D50, global:0x007CA590]
    // CALL: Call SpecialFX_Init(&dword_8ACEA0) to initialize special effects. [callee:0x004CF070, global:0x008ACEA0]
    // CALL: Call DynMan_Init() to initialize the dynamics manager. [callee:0x0042C1A0]
    // CALL: Call CamMan_Init(&dword_5EA510) to initialize the camera manager. [callee:0x0040C920, global:0x005EA510]
    // CALL: Call Sound_Init(&byte_8AC494) to initialize the sound module. [callee:0x004C8AE0, global:0x008AC494]
    // CALL: Call Render_Init(&byte_8AB678) to initialize the renderer. [callee:0x004B4030, global:0x008AB678]
    // CALL: Call LargeBufferZeroInit(&unk_7CE2F0) to zero a large session buffer. [callee:0x004A40E0, global:0x007CE2F0]
    // CALL: Call OnScreen_Init(&dword_7CE048) to initialize the on-screen system. [callee:0x0049EFA0, global:0x007CE048]
    // CALL: Call sub_4A1830(&unk_7CE2A4) on the session UI object. [callee:0x004A1830, global:0x007CE2A4]
    // CALL: Call SessionTypeSetter(&dword_7CD25C) to set up the session type module. [callee:0x00463F70, global:0x007CD25C]
    // RETURN: Return 0 after all subsystems initialized. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_42D6B0(_DWORD *this) {
    //     *this = 3;
    //     if (StringSplitLoop(2, aDDevF119992002_11, 467)) DebugLogWrite(&dword_8AD25C, aEnteredGameIni);
    //     sub_4BA1F0(&dword_8AB6E4);
    //     if (VidMan_Init(&unk_8AFE18)) return 1;
    //     SceneExtentComputation(&dword_8AB710);
    //     sub_4FCAA0(&unk_8AFEC0);
    //     AIDatabase_Init(dword_5EA2C0);
    //     EmptyStub_0170(&unk_7CE24D);
    //     Steward_Init(&dword_8ACEE0);
    //     HWInput_Init(&ppvOut);
    //     SpecialFX_Init(&dword_8ACEA0);
    //     DynMan_Init();
    //     CamMan_Init((int)&dword_5EA510);
    //     Sound_Init(&byte_8AC494);
    //     Render_Init(&byte_8AB678);
    //     LargeBufferZeroInit(&unk_7CE2F0);
    //     OnScreen_Init(&dword_7CE048);
    //     sub_4A1830(&unk_7CE2A4);
    //     SessionTypeSetter(&dword_7CD25C);
    //     return 0;
    //   }
    // UNRESOLVED: Global unk_5EC6D0 is referenced per the IDB but does not appear in the decompiled source text; sub_4FCAA0 receives &unk_8AFEC0 instead, so the role of unk_5EC6D0 here is unknown.
    // UNRESOLVED: ABI legacy name is Game_Init; the owning class of `this` is unconfirmed.
}
