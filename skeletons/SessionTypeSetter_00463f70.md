## SessionTypeSetter_00463f70 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Init (0042d6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x28 | RW | 1 | [LLM] |
| obj | 0x30 | RW | 0 | [LLM] |
| obj | 0x37C | RW | — | [LLM] |
| obj | 0x3FC4 | R | — | [LLM] |
| obj | 0x3FD8 | RW | 8 | [LLM] |
| obj | 0x3FD9 | RW | 0 | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x28: [LLM: once/conditional? does external poke survive?]
- obj 0x30: [LLM: once/conditional? does external poke survive?]
- obj 0x37C: [LLM: once/conditional? does external poke survive?]
- obj 0x3FD8: [LLM: once/conditional? does external poke survive?]
- obj 0x3FD9: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00464278 | jpt_464127 | R | [LLM] |
| 0059f0a8 | dword_59F0A8 | R | NetworkStateInt [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007c56a0 | dword_7C56A0 | W | MultiplayerFlags [DERIVED] |
| 007cd2a8 | dword_7CD2A8 | R | Unknown_Menu_Struct_7CD2A8 [DERIVED] |
| 007ce260 | byte_7CE260 | R | InitGuard_45d500 [DERIVED] (also: ` -- init guard flag) |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 007ce684 | dword_7CE684 | R | NationalityDataPath [DERIVED] (also: ` — nationality data pointer) |
| 007cfe0c | dword_7CFE0C | R | VehicleSkinOverridePath [DERIVED] |
| 007d0e50 | dword_7D0E50 | R | NetCommReadyFlag [DERIVED] (also: ` — readiness flag) |
| 007d0e88 | dword_7D0E88 | R | NetCommContextPtr [DERIVED] |
| 007d0e90 | dword_7D0E90 | R | Network_JoinState [DERIVED] |
| 007d0e98 | dword_7D0E98 | RW | Unknown_Flag_7D0E98 [DERIVED] |
| 007d0e9c | dword_7D0E9C | R | MessageBuffer7D0E9C [DERIVED] |
| 007d0ea0 | dword_7D0EA0 | R | NetworkSessionState [DERIVED] |
| 007d0ea4 | dword_7D0EA4 | R | UI_LapDisplayFlags [DERIVED] |
| 007d0eac | unk_7D0EAC | R | NetworkSessionStruct [DERIVED] |
| 007d0eb4 | unk_7D0EB4 | R | Network_SessionContext [DERIVED] |
| 007d0ebc | dword_7D0EBC | RW | Int_RaceSetupFuelStrat [DERIVED] |
| 007d0ec0 | dword_7D0EC0 | W | Unknown_Flag_7D0EC0 [DERIVED] |
| 007d0ec4 | dword_7D0EC4 | W | SessionConfigValue_7D0EC4 [DERIVED] |
| 007d0ec8 | dword_7D0EC8 | W | OptionFlagBuffer [DERIVED] |
| 007d0ee0 | dword_7D0EE0 | R | SessionMessageFlag [DERIVED] |
| 007d10ec | dword_7D10EC | R | NetworkJoinFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045d490 | GlobalFlagBasedStateSetter | [LLM] |
| 0045ecd0 | sub_45ECD0 | [LLM] |
| 0045f2a0 | CollisionInvDistanceStore | [LLM] |
| 00461470 | ThunkToFUN00461480 | [LLM] |
| 004623b0 | ShortComputation_23b0 | [LLM] |
| 00465150 | SingleCallWrapper | [LLM] |
| 00465160 | WheelSpeedConversionWithZeroGuard | [LLM] |
| 004b0390 | NameComparisonAt0x1b4 | [LLM] |
| 004b0b20 | sub_4B0B20 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 0057a750 | SingleFunctionCallWrapper_a750 | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
