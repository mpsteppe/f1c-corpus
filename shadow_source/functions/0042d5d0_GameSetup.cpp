// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042D5D0
// Canonical corpus name: Game_Setup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Game_Setup_0042d5d0.c

void UnknownObject::GameSetup()
{
    // Master one-time game initialization sequence. Sets the receiver's state field to 2 (setup/loading phase), conditionally logs entry, then initializes subsystems in a fixed order: player file helper, hardware input, scoring gate, options, special effects, steward, dynamics manager, sound, on-screen display, a session sub-object, video manager, player file, and a module manager. Options_Setup and PlayerFile_Setup return 1 to signal an early-abort failure; the function returns 0 on success.
    // ASSIGNMENT: Set the receiver's dword field at offset 0 to 2, marking the setup/loading phase. [field:this:0x00000000, source:raw]
    // GUARD: If StringSplitLoop(2, aDDevF119992002_11, 430) is non-zero, write the entry message aEnteredGameSet to the debug buffer dword_8AD25C via DebugLogWrite. [callee:0x004D7A50, global:0x005C3590, callee:0x004D7AA0, global:0x008AD25C, global:0x005C3628]
    // CALL: Call UtilityFunction_9160 passing the player-file global dword_5EC488 as its argument. [callee:0x004F9160, global:0x005EC488]
    // CALL: Call HWInput_Setup with a pointer to the module pointer array ppvOut to initialize hardware input. [callee:0x00455C60, global:0x007CA590]
    // CALL: Call SimpleZeroInit on the scoring gate global dword_8AB6E4. [callee:0x004BA1E0, global:0x008AB6E4]
    // GUARD: Call Options_Setup with a pointer to unk_7CE24D; if it returns non-zero, fail out with return value 1. [callee:0x004A0EB0, global:0x007CE24D]
    // CALL: Call SpecialFX_Setup on the scoring grid base dword_8ACEA0. [callee:0x004CEEC0, global:0x008ACEA0]
    // CALL: Call Steward_Setup on the force-feedback base dword_8ACEE0. [callee:0x004D36D0, global:0x008ACEE0]
    // CALL: Call DynMan_Setup with no arguments to initialize the dynamics manager. [callee:0x0042C170]
    // CALL: Call Sound_Setup on the scene name buffer byte_8AC494. [callee:0x004C8AB0, global:0x008AC494]
    // CALL: Call OnScreen_Setup on the race session state global dword_7CE048. [callee:0x0049EF70, global:0x007CE048]
    // CALL: Call sub_4A1830 with a pointer to the session sub-object unk_7CE2A4. [callee:0x004A1830, global:0x007CE2A4]
    // CALL: Call VidMan_Setup on the race phase timer global unk_8AFE18. [callee:0x004FA2F0, global:0x008AFE18]
    // GUARD: Call PlayerFile_Setup with a pointer to the auto-load config flag byte_7CE498; if it returns non-zero, fail out with return value 1. [callee:0x004B1870, global:0x007CE498]
    // CALL: Call sub_463EF0 with a pointer to the game module manager global dword_7CD25C. [callee:0x00463EF0, global:0x007CD25C]
    // RETURN: Return 0 to signal successful initialization. [source:raw]

    // Conservative worker pseudocode:
    //   int GameSetup(int *this) {
    //     *this = 2;
    //     if (StringSplitLoop(2, aDDevF119992002_11, 430))
    //       DebugLogWrite(&dword_8AD25C, aEnteredGameSet);
    //     UtilityFunction_9160(dword_5EC488);
    //     HWInput_Setup(&ppvOut);
    //     SimpleZeroInit(&dword_8AB6E4);
    //     if (Options_Setup(&unk_7CE24D)) return 1;
    //     SpecialFX_Setup(&dword_8ACEA0);
    //     Steward_Setup(&dword_8ACEE0);
    //     DynMan_Setup();
    //     Sound_Setup(&byte_8AC494);
    //     OnScreen_Setup(&dword_7CE048);
    //     sub_4A1830(&unk_7CE2A4);
    //     VidMan_Setup(&unk_8AFE18);
    //     if (PlayerFile_Setup(&byte_7CE498)) return 1;
    //     sub_463EF0(&dword_7CD25C);
    //     return 0;
    //   }
    // UNRESOLVED: Global unk_5EC6D0 is listed in the packet globals but not referenced in the raw source text; its role here is unknown.
}
