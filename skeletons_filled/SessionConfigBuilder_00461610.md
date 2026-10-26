## SessionConfigBuilder_00461610 — session configuration builder from global game state

**Summary:** Constructs a session configuration packet by reading global game state variables (track path, season, flags, player counts, network state, weather, settings) and packing them into a compact binary struct. Also calls a utility to finalize the config with session option flags.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** WeatherSurfaceUpdate (004628a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x60 | RW | — | UI percentage slider value (copied from flt_7D084C) |
| this | 0x64 | RW | — | game mode / player count (from dword_7D0A44) |
| this | 0x65 | RW | 0 | padding / reserved byte (always zeroed) |
| this | 0x66 | RW | — | race setup byte (from dword_7D0FC4) |
| this | 0x67 | RW | — | auto-reverse option (from dword_7D0C18) |
| this | 0x68 | RW | — | unknown flag byte (from dword_7D0D14) |
| this | 0x69 | RW | — | AI driver skill / game levels update (from dword_7D0014) |
| this | 0x6A | RW | — | race setting flag (from dword_7CEB10) |
| this | 0x6B | RW | — | clamped network session state value |
| this | 0x6C | RW | — | weather mode UI value (0-5, from dword_7CF134) |
| this | 0x6D | RW | — | option byte (from dword_7CF038) |
| this | 0x74 | RW | — | setup option flag word (from dword_7D0F4C) |
| this | 0x76 | RW | — | bit-packed flags word (input mode, vehicle mode, tire model, damage, penalties, etc.) |
| this | 0x78 | RW | — | recon pit open time (from dword_7CEC30) |
| this | 0x7A | RW | — | recon pit closed time (from dword_7CEC54) |
| this | 0x7C | RW | — | minimum penetration limit * 1000, clamped to [0, 65535] (from flt_7D108C) |

**Written-by note (persistence):**
- this 0x60: written every call — external poke does NOT persist
- this 0x64: written every call — external poke does NOT persist
- this 0x65: always set to 0 — external poke does NOT persist
- this 0x66: written every call — external poke does NOT persist
- this 0x67: written every call — external poke does NOT persist
- this 0x68: written every call — external poke does NOT persist
- this 0x69: written every call — external poke does NOT persist
- this 0x6A: written every call — external poke does NOT persist
- this 0x6B: written every call — external poke does NOT persist
- this 0x6C: written every call — external poke does NOT persist
- this 0x6D: written every call — external poke does NOT persist
- this 0x74: written every call — external poke does NOT persist
- this 0x76: written every call — external poke does NOT persist
- this 0x78: written every call — external poke does NOT persist
- this 0x7A: written every call — external poke does NOT persist
- this 0x7C: written every call — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004618b4 | jpt_461818 | R | jump table for switch dispatch on NetCommReadyFlag |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e874 | flt_59E874 | R | AITurnInSpeedThreshold [DERIVED] |
| 0059f120 | flt_59F120 | R | IntensityMultiplier [DERIVED] |
| 007ce5d0 | dword_7CE5D0 | R | CurrentTrackPath [DERIVED] |
| 007ce874 | byte_7CE874 | R | InputModeFlag [DERIVED] |
| 007ce88c | byte_7CE88C | R | VehicleModeFlag [DERIVED] (also: ` — mode flags) |
| 007ce958 | dword_7CE958 | R | TireModelMode [DERIVED] |
| 007ce97c | byte_7CE97C | R | TireModelFlag [DERIVED] |
| 007ceb10 | dword_7CEB10 | R | RaceSetting_Flag1 [DERIVED] |
| 007cec30 | dword_7CEC30 | R | ReconPitOpen [DERIVED] |
| 007cec54 | dword_7CEC54 | R | ReconPitClosed [DERIVED] |
| 007ced44 | dword_7CED44 | R | Flag_DamageDisplay [DERIVED] |
| 007cee40 | dword_7CEE40 | R | ConfigFieldHandler [DERIVED] |
| 007cef3c | dword_7CEF3C | R | PenaltyConfigFlag [DERIVED] |
| 007cf038 | dword_7CF038 | R | OptionByte_7CF038 [DERIVED] |
| 007cf134 | dword_7CF134 | R | WeatherModeUI (0-5) [DERIVED] |
| 007d0014 | dword_7D0014 | R | updateGameLevels [CONFIRMED] (also: Setup_AIDriverSkill) |
| 007d0134 | dword_7D0134 | R | SessionOptionFlags [DERIVED] |
| 007d0434 | dword_7D0434 | R | SeasonPath [DERIVED] |
| 007d084c | flt_7D084C | R | UIPercentageSlider [DERIVED] |
| 007d0a44 | dword_7D0A44 | R | GameModePlayerCount [DERIVED] |
| 007d0c18 | dword_7D0C18 | R | OptionAutoReverse [DERIVED] |
| 007d0d14 | dword_7D0D14 | R | Flag_Unknown_d14 [DERIVED] |
| 007d0e50 | dword_7D0E50 | R | NetCommReadyFlag [DERIVED] (also: ` — readiness flag) |
| 007d0e98 | dword_7D0E98 | W | Unknown_Flag_7D0E98 [DERIVED] |
| 007d0ea0 | dword_7D0EA0 | R | NetworkSessionState [DERIVED] |
| 007d0ea4 | dword_7D0EA4 | R | UI_LapDisplayFlags [DERIVED] |
| 007d0f4c | dword_7D0F4C | R | Setup_OptionFlag_0F4C [DERIVED] |
| 007d0f70 | dword_7D0F70 | R | SessionConfigByte [DERIVED] |
| 007d0fc4 | dword_7D0FC4 | R | RaceSetupByte_0FC4 [DERIVED] |
| 007d108c | flt_7D108C | R | MinPenetrationLimit [DERIVED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ac48c | dword_8AC48C | R | CurrentSceneIndex [DERIVED] (also: ` — module list index) |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00415c30 | NullSafePointerDereference | safely dereferences a pointer to get string (returns empty on null) |
| 004336d0 | SafeStringCopy | copies string with buffer size limit |
| 004615c0 | UtilityFunction_15c0 | finalizes/packs session config (called twice with different modes) |
| 004618d0 | ReversePathSearchForBackslash | finds last backslash in path string (extracts filename from path) |
| 004c5690 | SceneDataParser | parses scene/track data from file path string |
| 00587dd0 | sub_587DD0 | copies substring into buffer with length limit |

**Guard conditions:** No guard conditions that block/skip execution. The function always runs its full logic. Internal conditionals handle value clamping (0–65535 on penetration limit) and the net comm state switch dispatch, but neither blocks the main path.
