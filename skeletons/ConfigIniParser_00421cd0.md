## ConfigIniParser_00421cd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameMainEntry (0045b200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x68 | R | — | [LLM] |
| this | 0x70 | R | — | [LLM] |
| this | 0xA8 | R | — | [LLM] |
| this | 0xB8 | RW | — | [LLM] |
| this | 0xBC | RW | — | [LLM] |
| this | 0xC0 | RW | — | [LLM] |
| this | 0xC4 | RW | 0 | [LLM] |
| this | 0xC8 | RW | — | [LLM] |
| this | 0xCC | RW | — | [LLM] |
| this | 0xD0 | RW | — | [LLM] |
| this | 0xD4 | RW | — | [LLM] |
| this | 0xD5 | RW | — | [LLM] |
| this | 0xD6 | RW | — | [LLM] |
| this | 0xD8 | RW | — | [LLM] |
| this | 0xDC | RW | — | [LLM] |
| this | 0xE0 | RW | — | [LLM] |
| this | 0xE4 | RW | — | [LLM] |
| this | 0xE8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xB8: [LLM: once/conditional? does external poke survive?]
- this 0xBC: [LLM: once/conditional? does external poke survive?]
- this 0xC0: [LLM: once/conditional? does external poke survive?]
- this 0xC4: [LLM: once/conditional? does external poke survive?]
- this 0xC8: [LLM: once/conditional? does external poke survive?]
- this 0xCC: [LLM: once/conditional? does external poke survive?]
- this 0xD0: [LLM: once/conditional? does external poke survive?]
- this 0xD4: [LLM: once/conditional? does external poke survive?]
- this 0xD5: [LLM: once/conditional? does external poke survive?]
- this 0xD6: [LLM: once/conditional? does external poke survive?]
- this 0xD8: [LLM: once/conditional? does external poke survive?]
- this 0xDC: [LLM: once/conditional? does external poke survive?]
- this 0xE0: [LLM: once/conditional? does external poke survive?]
- this 0xE4: [LLM: once/conditional? does external poke survive?]
- this 0xE8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e19c | CopyFileA | R | [LLM] |
| 0059e254 | SHGetSpecialFolderPathA | R | [LLM] |
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
| 00404cc0 | QuickRace | [LLM] |
| 00404d30 | ShortComputation_4d30 | [LLM] |
| 00404d40 | StructFieldSetter | [LLM] |
| 00404d50 | ResourceListCleanup | [LLM] |
| 00404e60 | LinkedListNodeInsertion | [LLM] |
| 00404ef0 | SingleFunctionCallWrapper_4ef0 | [LLM] |
| 004218d0 | NameRegistrationDelegation | [LLM] |
| 004218f0 | StringCopyRealloc | [LLM] |
| 00421910 | DoubleDelegateCall | [LLM] |
| 00421930 | ChainedCall | [LLM] |
| 00421950 | StringWritePathRegister | [LLM] |
| 00421970 | DualFunctionCallChain | [LLM] |
| 00421990 | ShortComputation_1990 | [LLM] |
| 004219b0 | ShortComputation_19b0 | [LLM] |
| 004219d0 | sub_4219D0 | [LLM] |
| 004219f0 | DualFunctionDispatch | [LLM] |
| 00421a10 | DualRegistrationCall | [LLM] |
| 00421a30 | DualDispatchProcessPathRegister | [LLM] |
| 00421a50 | DualCallWrapper | [LLM] |
| 00421a70 | sub_421A70 | [LLM] |
| 00421a90 | ShortComputation_1a90 | [LLM] |
| 00421ab0 | FunctionCallWrapper_1ab0 | [LLM] |
| 00421ad0 | PathRegistrationWrapper | [LLM] |
| 00421af0 | DualDelegationWrapper | [LLM] |
| 00421b10 | FileEnumerationByExtension | [LLM] |
| 00422be0 | sub_422BE0 | [LLM] |
| 004230c0 | sub_4230C0 | [LLM] |
| 00423250 | WindowsAdminCheck | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 005651b0 | sub_5651B0 | [LLM] |
| 005654a0 | sub_5654A0 | [LLM] |
| 00565520 | sub_565520 | [LLM] |
| 00565760 | sub_565760 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587c20 | sub_587C20 | [LLM] |
| 00587ca0 | FileReadUntilNewline | [LLM] |
| 00587d02 | FileCloseWithLock | [LLM] |
| 00587db0 | sub_587DB0 | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |
| 005881c0 | __alloca_probe | [LLM] |
| 0058850f | sub_58850F | [LLM] |
| 00589671 | CreateDirectoryAWrapper | [LLM] |
| 0058ba75 | FileAttributeCheckWithErrorHandling | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
