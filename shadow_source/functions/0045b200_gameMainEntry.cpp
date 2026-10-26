// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045B200
// Canonical corpus name: GameMainEntry
// Owner: GameMainEntry [DERIVED]
// Raw source: functions/GameMainEntry_0045b200.c

void GameMainEntry::gameMainEntry()
{
    // Main game entry point (WinMain equivalent, __stdcall with instance handle a1). Initializes session globals (state constant 1065571320, substate pointer to the 'Ilya1011' version string, cleared flag byte, multiplayer flags set to 3, instance handle stored in hinst), initializes subsystems and parses the config .ini and networking command line, then drives the game lifecycle: Game_Enter, Game_Setup, Game_Init, and a restart loop running GamePostMainLoop per frame with Game_Post cleanup and re-setup on session end. Finishes with GameExit and returns 0.
    // ASSIGNMENT: Initialize session globals: set dword_7C56B0 to 1065571320 (session state constant) and dword_7C56B4 to the version/build identifier string aIlya1011. [global:0x007C56B0, global:0x007C56B4, global:0x005C5B2C]
    // ASSIGNMENT: Clear the session flag byte byte_7C56AD to 0 and set the multiplayer flags dword_7C56A0 to 3. [global:0x007C56AD, global:0x007C56A0]
    // ASSIGNMENT: Store the module/instance handle a1 into hinst. [global:0x007CE2A0]
    // CALL: Initialize the game subsystem from the command line a3 via sub_423070. [callee:0x00423070]
    // CALL: Parse the configuration .ini file via ConfigIniParser on the season parent path dword_5EC3D0. [callee:0x00421CD0, global:0x005EC3D0]
    // CALL: Command-line/config setup step sub_4D7A00(a3). [callee:0x004D7A00]
    // CALL: Initialization step sub_4A0D50(a3). [callee:0x004A0D50]
    // CALL: Initialization step sub_4B17F0(a3). [callee:0x004B17F0]
    // CALL: Parse networking command-line options via NetCommParseCommandLine(a3). [callee:0x00463160]
    // CALL: Enter the game session via Game_Enter on the session-type global dword_7C569C. [callee:0x0042D370, global:0x007C569C]
    // CALL: First Game_Setup invocation on dword_7C569C. [callee:0x0042D5D0, global:0x007C569C]
    // GUARD: Enter the init/restart block (LABEL_3) only when Game_Enter returns 0 and the first Game_Setup returns 0. [callee:0x0042D370, callee:0x0042D5D0]
    // CALL: Initialize the game via Game_Init on dword_7C569C. [callee:0x0042D6B0, global:0x007C569C]
    // GUARD: Proceed to the restart loop only when Game_Init returns 0. [callee:0x0042D6B0]
    // LOOP: Restart loop: continue while Game_Restart returns 0; run the per-frame main loop inside. [callee:0x0042D7A0]
    // CALL: Per-frame post-main-loop processing GamePostMainLoop on dword_7C569C. [callee:0x0042D8A0]
    // GUARD: When GamePostMainLoop returns nonzero (session finished), run Game_Post and then re-setup or break out of the restart loop. [callee:0x0042D8A0, callee:0x0042DA30, callee:0x0042D5D0]
    // CALL: Post-session cleanup Game_Post on dword_7C569C. [callee:0x0042DA30, global:0x007C569C]
    // GUARD: If Game_Setup returns 0 after Game_Post, jump back to LABEL_3 to restart the cycle; otherwise break out of the loop. [callee:0x0042D5D0]
    // CALL: Final game teardown GameExit on dword_7C569C. [callee:0x0042DB20, global:0x007C569C]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   dword_7C56B0 = 1065571320;
    //   dword_7C56B4 = (int)"Ilya1011";
    //   byte_7C56AD = 0;
    //   dword_7C56A0 = 3;
    //   hinst = a1;
    //   InitSubsystem(a3);
    //   ParseIni(dword_5EC3D0, 0);
    //   SetupStep_a(a3); SetupStep_b(a3); SetupStep_c(a3);
    //   NetCommParseCommandLine(a3);
    //   if (Game_Enter(&dword_7C569C) == 0 && Game_Setup(&dword_7C569C) == 0) {
    //   LABEL_3:
    //       if (Game_Init(&dword_7C569C) == 0) {
    //           while (Game_Restart(&dword_7C569C) == 0) {
    //               if (GamePostMainLoop(&dword_7C569C)) {
    //                   Game_Post(&dword_7C569C);
    //                   if (Game_Setup(&dword_7C569C) == 0) goto LABEL_3;
    //                   break;
    //               }
    //           }
    //       }
    //   }
    //   GameExit(&dword_7C569C);
    //   return 0;
    // UNRESOLVED: The meaning of the session-state constant 1065571320 stored in dword_7C56B0 is not named in the packet.
    // UNRESOLVED: Globals dword_7CD25C, unk_7CE24D, byte_7CE498 and dword_8AD25C are listed as read but do not appear in the raw source; their reads belong to called functions or are not materialized here.
    // UNRESOLVED: The identity of the a3 command-line pointer passed through the setup/init steps is only structural.
}
