## ConfigIniParser_00421cd0 — ConfigIniFileParser

**Summary:** Parses the game's main .ini config file (config.ini): reads [Components], [Install], [Autolaunch], and [Version] sections, maps key-value pairs to struct fields (video settings, paths, ratings), and handles non-admin directory creation/copying on Windows XP/NT/2000.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameMainEntry (0045b200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | configFilePath (fallback when a2 is null: *this or byte_5EA438) |
| this | 0x40 | R | — | replayDirPath (this[16], used in replay directory creation) |
| this | 0x68 | R | — | logDirPath (this[26], used in log directory creation) |
| this | 0x70 | R | — | saveDirPath (this[28], used in save directory creation) |
| this | 0xA8 | R | — | basePathPrefix (this[42], common prefix for path construction) |
| this | 0xB8 | RW | — | videoDriverIndex (parsed from [Components] Videodriver) |
| this | 0xBC | RW | — | videoModeIndex (parsed from Videomode) |
| this | 0xC0 | RW | — | videoRefreshRate (parsed from Videorefresh) |
| this | 0xC4 | RW | 0 | gridSize (parsed from Gridsize, clamped 0-104) |
| this | 0xC8 | RW | — | cpuRating (parsed from Cpurating) |
| this | 0xCC | RW | — | systemRam (parsed from Systemram) |
| this | 0xD0 | RW | — | videoRam (parsed from Videoram) |
| this | 0xD4 | RW | — | windowedMode (byte flag from Windowedmode, stored at byte offset 0xD4) |
| this | 0xD5 | RW | — | runBenchmarks (byte bool from Runbenchmarks, stored at byte offset 0xD5) |
| this | 0xD6 | RW | — | vsyncEnabled (byte bool from Vsync, stored at byte offset 0xD6) |
| this | 0xD8 | RW | — | objDetailLevel (parsed from Objdetail) |
| this | 0xDC | RW | — | texDetailLevel (parsed from Texdetail) |
| this | 0xE0 | RW | — | fsaaLevel (parsed from Fsaa) |
| this | 0xE4 | RW | — | vbStrategy (parsed from Vbstrategy) |
| this | 0xE8 | RW | — | versionFloat (parsed from [Version] section, converted via sub_58850F) |

**Written-by note (persistence):**
- this 0xB8: written once during startup config parse — survives for session
- this 0xBC: written once during startup config parse — survives for session
- this 0xC0: written once during startup config parse — survives for session
- this 0xC4: written once during startup config parse — survives for session
- this 0xC8: written once during startup config parse — survives for session
- this 0xCC: written once during startup config parse — survives for session
- this 0xD0: written once during startup config parse — survives for session
- this 0xD4: written once during startup config parse — survives for session
- this 0xD5: written once during startup config parse — survives for session
- this 0xD6: written once during startup config parse — survives for session
- this 0xD8: written once during startup config parse — survives for session
- this 0xDC: written once during startup config parse — survives for session
- this 0xE0: written once during startup config parse — survives for session
- this 0xE4: written once during startup config parse — survives for session
- this 0xE8: written once during startup config parse — survives for session

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e19c | CopyFileA | R | Win32 CopyFile import (copies existing config to user directory) |
| 0059e254 | SHGetSpecialFolderPathA | R | Shell API: gets user documents folder path (CSIDL_PERSONAL=5) |
| 005be690 | aRt | R | Str_RT [DERIVED] |
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005c2aa0 | ExistingFileName | R | FileSearchPattern [DERIVED] |
| 005c2abc | aVersion_0 | R | VersionString [DERIVED] |
| 005c2ac4 | aVersion | R | VersionString [DERIVED] |
| 005c2ad0 | aIpaddress | R | IpAddressString [DERIVED] |
| 005c2adc | aVcrfile | R | String_Vcrfile [DERIVED] |
| 005c2ae4 | aVcrcycle | R | s_VcrCycle [DERIVED] |
| 005c2af0 | aLaunchtime | R | LaunchTime [DERIVED] |
| 005c2afc | aMode | R | ModeField [DERIVED] |
| 005c2b04 | aAutolaunch | R | AutoLaunchString [DERIVED] |
| 005c2b14 | aInstallto | R | InstalltoString [DERIVED] |
| 005c2b20 | aInstallfrom | R | InstallFromString [DERIVED] |
| 005c2b2c | aInstall | R | Str_Install [DERIVED] |
| 005c2b38 | aVbstrategy | R | StringVBStrategy [DERIVED] |
| 005c2b44 | aVsync | R | VsyncString [DERIVED] |
| 005c2b4c | aFsaa | R | FSAASettingString [DERIVED] |
| 005c2b54 | aRunbenchmarks | R | RunBenchmarksString [DERIVED] |
| 005c2b64 | aWindowedmode | R | WindowedModeString [DERIVED] |
| 005c2b74 | aVideorefresh | R | VideoRefreshString [DERIVED] |
| 005c2b84 | aVideomode | R | VideoModeField [DERIVED] |
| 005c2b90 | aVideodriver | R | Path_VideoDriver [DERIVED] |
| 005c2b9c | aVideoguid | R | String_VideoGuid [DERIVED] |
| 005c2ba8 | aTexdetail | R | TexDetailString [DERIVED] |
| 005c2bb4 | aObjdetail | R | ObjDetailString [DERIVED] |
| 005c2bc0 | aVideoram | R | VideoramString [DERIVED] |
| 005c2bcc | aSystemram | R | String_Systemram [DERIVED] |
| 005c2bd8 | aCpurating | R | s_CpuRating [DERIVED] |
| 005c2be4 | aGridsize | R | GridSize [DERIVED] |
| 005c2bf0 | aCameraeditorre | R | CameraEditorRecentString [DERIVED] |
| 005c2c08 | aSavedir | R | SaveDirString [DERIVED] |
| 005c2c10 | aLogdir | R | LogDirString [DERIVED] |
| 005c2c18 | aS_4 | R | FmtStr_PercentS [DERIVED] |
| 005c2c1c | aReplaydir | R | ReplayDirString [DERIVED] |
| 005c2c28 | aMusicdir | R | Str_MusicDir [DERIVED] |
| 005c2c34 | aDriversdir | R | StringDriversDir [DERIVED] |
| 005c2c40 | aVehiclesdir | R | VehiclesDirString [DERIVED] |
| 005c2c4c | aTracksdir | R | TracksDirString [DERIVED] |
| 005c2c58 | aMoviedir | R | MovieDirString [DERIVED] |
| 005c2c64 | aOptionsdir | R | OptionsDirString [DERIVED] |
| 005c2c70 | aOptionssounds | R | OptionsSoundsString [DERIVED] |
| 005c2c80 | aOptionsflags | R | OptionsFlagsField [DERIVED] |
| 005c2c90 | aOptionsanim | R | Path_OptionsAnim [DERIVED] |
| 005c2c9c | aVehiclesound | R | String_VehicleSound [DERIVED] |
| 005c2cac | aSounddir | R | SoundDirString [DERIVED] |
| 005c2cb8 | aSeasondir | R | SeasonDirString [DERIVED] |
| 005c2cc4 | aComponents | R | ComponentsString [DERIVED] |
| 005c2cd4 | aSuccessfullyCr | R | String_SuccessfullyCr [DERIVED] |
| 005c2d10 | aCouldNotCreate_0 | R | s_ErrorCouldNotCreate [DERIVED] |
| 005c2d34 | aDDevF119992002_10 | R | DevPath_F119992002 [DERIVED] |
| 005c2d5c | aSSS_1 | R | FormatCameraSSS [DERIVED] |
| 005c2d64 | aSS_3 | R | SessionConfigFile [DERIVED] |
| 005c2d6c | aF1Challenge990_0 | R | WindowTitle_F1999 [DERIVED] |
| 005c2d80 | aWindows2000 | R | String_Windows2000 [DERIVED] |
| 005c2d90 | aWindowsNt | R | sWindowsNt [DERIVED] |
| 005c2d9c | aWindowsXp | R | WindowsXPString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ea43c | dword_5EA43C | R | SetupDirSuffix [DERIVED] |
| 005ec3d0 | dword_5EC3D0 | R | SeasonParentPath [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404cc0 | QuickRace | Parses QuickRace mode string, returns mode index |
| 00404d30 | ShortComputation_4d30 | Stores parsed launch time float into setup struct |
| 00404d40 | StructFieldSetter | Sets struct field from parsed value |
| 00404d50 | ResourceListCleanup | Cleans up resource list with boolean flag |
| 00404e60 | LinkedListNodeInsertion | Inserts VCR file path into linked list |
| 00404ef0 | SingleFunctionCallWrapper_4ef0 | Stores IP address string via single function call |
| 004218d0 | NameRegistrationDelegation | Registers/delegates directory name (SeasonDir) |
| 004218f0 | StringCopyRealloc | Copies string with reallocation (SoundDir) |
| 00421910 | DoubleDelegateCall | Double delegation call (VehicleSound path) |
| 00421930 | ChainedCall | Chained call (OptionsAnim path) |
| 00421950 | StringWritePathRegister | Writes and registers path (OptionsFlags) |
| 00421970 | DualFunctionCallChain | Dual function call chain (OptionsSounds) |
| 00421990 | ShortComputation_1990 | Short computation for OptionsDir path |
| 004219b0 | ShortComputation_19b0 | Short computation for ReplayDir path |
| 004219d0 | sub_4219D0 | Sub-call for MovieDir path |
| 004219f0 | DualFunctionDispatch | Dual function dispatch for TracksDir path |
| 00421a10 | DualRegistrationCall | Dual registration for VehiclesDir path |
| 00421a30 | DualDispatchProcessPathRegister | Dual dispatch + process + register for DriversDir path |
| 00421a50 | DualCallWrapper | Dual call wrapper for LogDir path |
| 00421a70 | sub_421A70 | Sub-call for SaveDir path |
| 00421a90 | ShortComputation_1a90 | Short computation for MusicDir path |
| 00421ab0 | FunctionCallWrapper_1ab0 | Handles InstallFrom path |
| 00421ad0 | PathRegistrationWrapper | Registers InstallTo path |
| 00421af0 | DualDelegationWrapper | Dual delegation for CameraEditorRecent path |
| 00421b10 | FileEnumerationByExtension | Enumerates files by extension in source dir, copies to dest |
| 00422be0 | sub_422BE0 | Creates default config file if not found |
| 004230c0 | sub_4230C0 | Retrieves OS version string (Windows XP/NT/2000) |
| 00423250 | WindowsAdminCheck | Checks if running with administrator privileges |
| 004d7a50 | StringSplitLoop | String split loop for debug log check |
| 004d7aa0 | DebugLogWrite | Writes debug log message |
| 005651b0 | sub_5651B0 | Checks if line is section header or empty (returns 0/1/other) |
| 005654a0 | sub_5654A0 | Key-name match: compares line against section key string, extracts value |
| 00565520 | sub_565520 | Parses string value from key (for VideoGuid) |
| 00565760 | sub_565760 | Parses integer value from key with range/defaults |
| 00566650 | StringCopyWithBufferRealloc | Copies string with buffer reallocation |
| 00587c20 | sub_587C20 | Case-insensitive string prefix match (section/key detection) |
| 00587ca0 | FileReadUntilNewline | Reads one line from file handle into buffer |
| 00587d02 | FileCloseWithLock | Closes file handle with lock release |
| 00587db0 | sub_587DB0 | Opens file for reading, returns handle (or 0 if failed) |
| 00587dd0 | sub_587DD0 | Copies N bytes from source to dest buffer |
| 0058815f | StringFormatWithBufferOverflowCheck | snprintf-style format into buffer with overflow check |
| 005881c0 | __alloca_probe | Stack probe for alloca (large stack allocation) |
| 0058850f | sub_58850F | Converts version string to float value |
| 00589671 | CreateDirectoryAWrapper | Creates directory, with error handling |
| 0058ba75 | FileAttributeCheckWithErrorHandling | Checks file attributes (exists check), returns -1 if not found |

**Guard conditions:** OS version check: Windows XP, NT, or 2000 AND non-admin → enables v32 flag (non-admin mode), which triggers directory creation and file copying for replay/log/save dirs. Config file path: if a2 is null, falls back to *this or byte_5EA438 default. File not found by sub_587DB0: attempts sub_422BE0 to create default config, retries; if still not found, returns 0. GridSize: parsed value clamped to range [0, 104] — below 0 → 0, above 104 → 104. Section parsing: sub_5651B0 returns 0 for key lines, 1 for section end; non-zero exits inner while loop.
