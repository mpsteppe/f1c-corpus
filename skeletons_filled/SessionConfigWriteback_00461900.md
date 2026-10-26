## SessionConfigWriteback_00461900 — MultiplayerSessionConfigDeserialize

**Summary:** Deserializes multiplayer session configuration from a received network struct and writes all values to global game-state variables. Parses scene data, AI config, track name, then maps byte/short/bitfield fields to clamped global settings (player count, weather, tire model, penalties, pit windows, damage, fuel, etc.), applying range clamping per field.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ClientGridDisplayTimer (00460380), AutoJoinRetryLoop (004637a0), GameMode (0046d6d0), MultiplayerSessionJoinHandler (0046de10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x60 | R | — | float: weather-mode UI slider value (written to flt_7D084C) |
| this | 0x64 | R | — | byte: game mode player count (written to dword_7D0A44) |
| this | 0x66 | R | — | byte: race setup config byte (written to dword_7D0FC4, clamped by dword_7D0FD0) |
| this | 0x67 | R | — | byte: auto-reverse option (written to dword_7D0C18, clamped by dword_7D0C24) |
| this | 0x68 | R | — | byte: unknown flag source (written to dword_7D0D14, clamped by dword_7D0D20) |
| this | 0x69 | R | — | byte: AI driver skill level (written to dword_7D0014, clamped by dword_7D0020) |
| this | 0x6A | R | — | byte: race setting flag 1 (written to dword_7CEB10, clamped by dword_7CEB1C) |
| this | 0x6B | R | — | byte: fuel strategy option (written to dword_7D0EBC, clamped by dword_7D0EC8) |
| this | 0x6C | R | — | byte: weather mode index 0-5 (written to dword_7CF134, clamped by dword_7CF140) |
| this | 0x6D | R | — | byte: option config byte (written to dword_7CF038, clamped by dword_7CF044) |
| this | 0x74 | R | — | short: session option flags source (written to dword_7D0F4C, clamped by dword_7D0F58) |
| this | 0x76 | R | — | word: bitfield flags — bit 0=input mode, bit 1=vehicle mode, bit 2=tire model, bit 3=tire option, bit 4=penetration, bit 6=input subflag, bit 7=vehicle subflag, bit 8=tire subflag, bit 9=tire option subflag, bit 10=damage display, bit 11=config handler, bit 12=penalty |
| this | 0x78 | R | — | short: pit window open timer value (written to dword_7CEC30, clamped by dword_7CEC3C) |
| this | 0x7A | R | — | short: pit window closed timer value (written to dword_7CEC54, clamped by dword_7CEC60) |
| this | 0x7C | R | — | unsigned short: min penetration limit source (scaled by 0.001, written to flt_7D108C) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e600 | flt_59E600 | R | SteeringForceThreshold [DERIVED] |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 007ce874 | byte_7CE874 | RW | InputModeFlag [DERIVED]: set from bitfield bit 0, subflag from bit 6 |
| 007ce876 | byte_7CE876 | R | Byte_WeatherFlag [DERIVED] |
| 007ce877 | byte_7CE877 | R | SessionConfigFlagByte [DERIVED]: input-mode clamp range |
| 007ce88c | byte_7CE88C | RW | VehicleModeFlag [DERIVED] (also: ` — mode flags): set from bitfield bit 1, subflag from bit 7 |
| 007ce88e | byte_7CE88E | R | AudioConfigFlag [DERIVED] |
| 007ce88f | byte_7CE88F | R | ConfigBitFlag [DERIVED]: vehicle-mode clamp range |
| 007ce958 | dword_7CE958 | RW | TireModelMode [DERIVED]: set from bitfield bit 2, subflag from bit 8 |
| 007ce960 | dword_7CE960 | R | ConfigFieldName_7CE960 [DERIVED] |
| 007ce964 | dword_7CE964 | R | TireModelModeTarget [DERIVED]: tire-model clamp range |
| 007ce97c | byte_7CE97C | RW | TireModelFlag [DERIVED]: set from bitfield bit 3, subflag from bit 9 |
| 007ce97e | byte_7CE97E | R | Setup_ExtraFlag2 [DERIVED] |
| 007ce97f | byte_7CE97F | R | TireModelOptionByte [DERIVED]: tire-option clamp range |
| 007ceb10 | dword_7CEB10 | RW | RaceSetting_Flag1 [DERIVED] |
| 007ceb18 | dword_7CEB18 | R | RaceSetupParam [DERIVED] |
| 007ceb1c | dword_7CEB1C | R | ReconSettings_e1c [DERIVED]: race-setting clamp range |
| 007cec30 | dword_7CEC30 | RW | ReconPitOpen [DERIVED]: pit open timer |
| 007cec38 | dword_7CEC38 | R | PitWindowTimerConfig [DERIVED] |
| 007cec3c | dword_7CEC3C | R | PitWindowTimer [DERIVED]: pit-open clamp range |
| 007cec54 | dword_7CEC54 | RW | ReconPitClosed [DERIVED]: pit closed timer |
| 007cec5c | dword_7CEC5C | R | NetSessionTimeout [DERIVED] |
| 007cec60 | dword_7CEC60 | R | PitWindowClosedTimer [DERIVED]: pit-closed clamp range |
| 007ced44 | dword_7CED44 | RW | Flag_DamageDisplay [DERIVED]: set from bitfield bit 10 |
| 007ced4c | dword_7CED4C | R | RaceSetupParam2 [DERIVED] |
| 007ced50 | dword_7CED50 | R | SessionInitFlags [DERIVED]: damage-display clamp range |
| 007cee40 | dword_7CEE40 | RW | ConfigFieldHandler [DERIVED]: set from bitfield bit 11 |
| 007cee48 | dword_7CEE48 | R | Config_FlagDWORD_02 [DERIVED] |
| 007cee4c | dword_7CEE4C | R | Setup_Option_7CEE4C [DERIVED]: config-handler clamp range |
| 007cef3c | dword_7CEF3C | RW | PenaltyConfigFlag [DERIVED]: set from bitfield bit 12 |
| 007cef44 | dword_7CEF44 | R | Unknown_Flag_7CEF44 [DERIVED] |
| 007cef48 | dword_7CEF48 | R | PenaltyTimeThreshold [DERIVED]: penalty clamp range |
| 007cf038 | dword_7CF038 | RW | OptionByte_7CF038 [DERIVED] |
| 007cf040 | dword_7CF040 | R | Unknown_Flag_7CF040 [DERIVED] |
| 007cf044 | dword_7CF044 | R | Flag7CF044 [DERIVED]: option-byte clamp range |
| 007cf134 | dword_7CF134 | RW | WeatherModeUI (0-5) [DERIVED] |
| 007cf13c | dword_7CF13C | R | Config_FlagDWORD_01 [DERIVED] |
| 007cf140 | dword_7CF140 | R | Weather_Config_7CF140 [DERIVED]: weather clamp range |
| 007d0014 | dword_7D0014 | RW | updateGameLevels [CONFIRMED] (also: Setup_AIDriverSkill) |
| 007d001c | dword_7D001C | R | SessionConfigField [DERIVED] |
| 007d0020 | dword_7D0020 | R | AI-driver-skill clamp range |
| 007d0134 | dword_7D0134 | RW | SessionOptionFlags [DERIVED]: set from BitFlagTestAt0x6E result |
| 007d013c | dword_7D013C | R | SessionConfigValue_7D013C [DERIVED] |
| 007d0140 | dword_7D0140 | R | Dword_GameOptions [DERIVED]: session-option clamp range |
| 007d084c | flt_7D084C | RW | UIPercentageSlider [DERIVED]: weather slider float |
| 007d0854 | flt_7D0854 | R | WeatherModeConfig [DERIVED]: weather-float min clamp |
| 007d0858 | flt_7D0858 | R | ServerAddressParam [DERIVED]: weather-float max clamp |
| 007d0a44 | dword_7D0A44 | RW | GameModePlayerCount [DERIVED] |
| 007d0a4c | dword_7D0A4C | R | RaceModeIndex [DERIVED] |
| 007d0a50 | dword_7D0A50 | R | TimeAccelSetting [DERIVED]: player-count clamp range |
| 007d0c18 | dword_7D0C18 | RW | OptionAutoReverse [DERIVED] |
| 007d0c20 | dword_7D0C20 | R | ConfigFieldName_7D0C20 [DERIVED] |
| 007d0c24 | dword_7D0C24 | R | TireWearMultTarget [DERIVED]: auto-reverse clamp range |
| 007d0d14 | dword_7D0D14 | RW | Flag_Unknown_d14 [DERIVED] |
| 007d0d1c | dword_7D0D1C | R | GameOptionConfigValue [DERIVED] |
| 007d0d20 | dword_7D0D20 | R | Setup_MaxVehicles [DERIVED]: unknown-d14 clamp range |
| 007d0ebc | dword_7D0EBC | RW | Int_RaceSetupFuelStrat [DERIVED] |
| 007d0ec4 | dword_7D0EC4 | R | SessionConfigValue_7D0EC4 [DERIVED] |
| 007d0ec8 | dword_7D0EC8 | R | OptionFlagBuffer [DERIVED]: fuel-strategy clamp range |
| 007d0f4c | dword_7D0F4C | RW | Setup_OptionFlag_0F4C [DERIVED] |
| 007d0f54 | dword_7D0F54 | R | NetQualifyingTime [DERIVED] |
| 007d0f58 | dword_7D0F58 | R | PitWindowTimer [DERIVED]: session-option clamp range |
| 007d0fc4 | dword_7D0FC4 | RW | RaceSetupByte_0FC4 [DERIVED] |
| 007d0fcc | dword_7D0FCC | R | PlayerConfigOption [DERIVED] |
| 007d0fd0 | dword_7D0FD0 | R | race-setup-byte clamp range |
| 007d108c | flt_7D108C | RW | MinPenetrationLimit [DERIVED]: set from unsigned short scaled by 0.001 |
| 007d1094 | flt_7D1094 | R | SessionConfigFloatPair [DERIVED]: penetration min clamp |
| 007d1098 | flt_7D1098 | R | Flt_7D1098_pair [DERIVED]: penetration max clamp |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004615f0 | BitFlagTestAt0x6E | Test bit flags in byte at this+0x6E (offset 110), return 1 or 0 based on bit 0 state |
| 004646c0 | FloatClamp | Clamp float value between min/max range bounds |
| 00464720 | ByteClamp | Clamp byte value to valid range using range globals |
| 0047f1f0 | ClampByRange | Clamp integer value using min/max range globals |
| 004b0ef0 | sub_4B0EF0 | Post-deserialization handler (called with arg 5 — likely commit/writeback trigger) |
| 004b1410 | NameCompareAndFormat | Parse and format track/season name string from config data at this+0x40 |
| 004c54f0 | AIW | Initialize AI driver waypoint data |
| 004c5690 | SceneDataParser | Parse scene/map data from config at this+0x20 |

**Guard conditions:** No branching guards — function unconditionally processes all fields. Bitfield extraction at this+0x76 uses individual bit tests (bits 0-4, 6-12) to gate specific global writes: bit 0 gates input mode (byte_7CE874 + ByteClamp), bit 1 gates vehicle mode (byte_7CE88C + ByteClamp), bit 2 gates tire model (dword_7CE958 + ClampByRange), bit 3 gates tire option (byte_7CE97C + ByteClamp), bit 4 gates penetration float (flt_7D108C + FloatClamp). Bits 10-12 always write (no bit test — uses shift extraction). All paths converge to sub_4B0EF0(5).
