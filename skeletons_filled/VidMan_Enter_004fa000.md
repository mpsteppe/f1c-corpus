## VidMan_Enter_004fa000 — VidMan_Enter

**Summary:** Video manager entry point — initializes the rendering subsystem by creating the game window, configuring graphics state, and initializing sub-modules. If the current working directory does not match the configured game directory, it relaunches the game executable via CreateProcessA in the correct directory. Part of the startup/initialization system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Enter (0042d370)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0d0 | CreateProcessA | R | IAT entry for CreateProcessA — used to re-launch the game in the correct directory |
| 0059e0ec | GetModuleFileNameA | R | IAT entry for GetModuleFileNameA — gets path to current EXE for relaunch |
| 005d6dc4 | aDDevF119992002_26 | R | PathPrefix — debug string prefix [DERIVED] |
| 005d6e50 | byte_5D6E50 | R | FlagByte_5D6E50 — command-line argument prefix bytes for relaunch [DERIVED] |
| 005d6e60 | byte_5D6E60 | R | AudioByteFlag — default directory path string when no player file is configured [DERIVED] |
| 005d6e6c | aEnteredVidmanE | R | EnteredVidmanEString — debug log message "Entered VidMan" [DERIVED] |
| 005ea438 | byte_5EA438 | R | Default application directory — fallback path when dword_5EC480 is null [DERIVED] |
| 005ec3d0 | dword_5EC3D0 | R | SeasonParentPath — used to set up working directory before relaunch [DERIVED] |
| 005ec480 | dword_5EC480 | R | Setup_DirectoryPtr_5EC480 — configured game directory path [DERIVED] |
| 005ec488 | dword_5EC488 | R | PlayerFile — player file handle/index used for directory lookup [DERIVED] |
| 005ec48c | dword_5EC48C | R | NetworkPortHandle — passed to GlobalGuardedFieldReader for resolution config [DERIVED] |
| 005ec4a4 | byte_5EC4A4 | RW | MessageActiveFlag — window mode flag; may be cleared to 0 if resolution unchanged [DERIVED] |
| 005ec4b4 | dword_5EC4B4 | R | Dword5EC4B4 — passed to GraphicsConfigStateSetter [DERIVED] |
| 007cde00 | unk_7CDE00 | R | Unknown_Render_CDE00 [DERIVED] |
| 007ce2a0 | hinst | R | HInstance — application instance handle [DERIVED] |
| 007ce2a4 | unk_7CE2A4 | R | Unknown_Session_7CE2A4 [DERIVED] |
| 007ce2dc | hWnd | R | HWnd — main window handle [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer — parsed by StringSplitLoop for debug logging [DERIVED] |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |
| 008afe74 | dword_8AFE74 | R | Net_PacketBufferIndex — passed to sub_4F9310 for network init [DERIVED] |
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |
| 008b8dc8 | dword_8B8DC8 | R | RenderDevicePtr (D3D device/renderer interface) [DERIVED] |
| ff000000000053de | byte_FF000000000053DE | W | unknown — address in non-standard memory space |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00422be0 | sub_422BE0 | Sets up working directory path before process relaunch |
| 00494690 | sub_494690 | Post-initialization subsystem setup |
| 004a1200 | sub_4A1200 | Creates the game window (CreateGameWindow) |
| 004d7a50 | StringSplitLoop | Parses debug message buffer — checks for path prefix match |
| 004d7aa0 | DebugLogWrite | Writes "Entered VidMan" to debug log |
| 004f9160 | UtilityFunction_9160 | Utility function operating on player file |
| 004f91b0 | GlobalGuardedFieldReader | Reads guarded global config fields (resolution, etc.) from network port handle |
| 004f9310 | sub_4F9310 | Initializes network/online subsystem; returns non-zero on failure |
| 004f9420 | sub_4F9420 | Initializes rendering subsystem with width, height, depth, refresh |
| 004f9f00 | ConditionalInit | Conditional initialization step |
| 004f9f30 | ConditionalStateReset | Conditional state reset step |
| 0053c680 | ThreeGlobalSetter | Sets three globals to hWnd, hWnd, hinst |
| 0053d470 | SystemInitAllocatorWrapper | Initializes system memory allocator; returns non-zero on failure |
| 0053d890 | IndexedArrayAccess_d890 | Indexed array access on player file — retrieves directory path entry |
| 0053d8e0 | sub_53D8E0 | Copies a string from array entry to Filename buffer |
| 005408f0 | GraphicsConfigStateSetter | Configures graphics state from dword_5EC4B4 |
| 005434a0 | sub_5434A0 | Render state setup — likely clear/set viewport with color (0,0,0,1,0) |
| 0055c060 | CallWrapper_c060 | Wrapper call — render present/flip |
| 0055c330 | sub_55C330 | Checks if resolution has changed; updates v10 and may clear byte_5EC4A4 |
| 00568be0 | QPCTimerInitialization | Initializes high-precision QPC timer |

**Guard conditions:** The `strcmp(Filename, v4)` at line 44 branches the entire function: if Filename matches the configured directory → proceed to create window and initialize renderer (return 0). If mismatch → call CreateProcessA to relaunch the EXE with the correct directory (return 1). The `v10 != v7` check at line 52 clears `byte_5EC4A4` if resolution changed.
