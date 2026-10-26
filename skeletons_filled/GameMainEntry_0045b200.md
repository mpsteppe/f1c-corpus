## GameMainEntry_0045b200 — WinMainEntry

**Summary:** Main game entry point (WinMain equivalent). Initializes session globals (state, session flags, instance handle), parses command line and config, sets up networking, then runs main game lifecycle: enters session setup → initialization → restart/render loop with post-processing cleanup → exit.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_58A19E (0058a19e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c5b2c | aIlya1011 | R | Ilya1011String [DERIVED] — version/build identifier string |
| 005ec3d0 | dword_5EC3D0 | R | SeasonParentPath [DERIVED] — path to config directory |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] — game session type identifier |
| 007c56a0 | dword_7C56A0 | W | MultiplayerFlags [DERIVED] — set to 3 (multiplayer mode flags) |
| 007c56ad | byte_7C56AD | W | SessionFlagByte [DERIVED] — cleared to 0 |
| 007c56b0 | dword_7C56B0 | W | SessionState_56B0 [DERIVED] — set to 1065571320 (session state constant) |
| 007c56b4 | dword_7C56B4 | W | Session_SubState [DERIVED] — set to pointer to "Ilya1011" string |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007ce2a0 | hinst | W | HInstance [DERIVED] — set to a1 (Windows instance handle) |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00421cd0 | ConfigIniParser | parse .ini configuration file for game settings |
| 00423070 | sub_423070 | initialize game subsystem from command line a3 |
| 0042d370 | Game_Enter | enter game session; returns 0 on success |
| 0042d5d0 | Game_Setup | setup/reinitialize game state; returns 0 on success |
| 0042d6b0 | Game_Init | initialize game subsystems; returns 0 on success |
| 0042d7a0 | Game_Restart | run main game loop iteration; returns 0 to continue, non-zero to exit |
| 0042d8a0 | GamePostMainLoop | post-frame/session processing; returns non-zero when session should restart |
| 0042da30 | Game_Post | cleanup after main loop before re-entering setup phase |
| 0042db20 | GameExit | final cleanup and process exit |
| 00463160 | NetCommParseCommandLine | parse command line for network communication parameters |
| 004a0d50 | sub_4A0D50 | initialize with command line arguments |
| 004b17f0 | sub_4B17F0 | initialize with command line arguments |
| 004d7a00 | sub_4D7A00 | initialize with command line arguments |

**Guard conditions:** If Game_Enter() returns non-zero → skip to GameExit. If Game_Setup() returns non-zero → skip to GameExit. If Game_Init() returns non-zero → skip to GameExit. If Game_Restart() returns non-zero (loop exit condition) → break main loop. If GamePostMainLoop() returns non-zero → call Game_Post then Game_Setup and re-enter init loop at LABEL_3.
