## GameMainEntry_0045b200 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_58A19E (0058a19e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c5b2c | aIlya1011 | R | Ilya1011String [DERIVED] |
| 005ec3d0 | dword_5EC3D0 | R | SeasonParentPath [DERIVED] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007c56a0 | dword_7C56A0 | W | MultiplayerFlags [DERIVED] |
| 007c56ad | byte_7C56AD | W | SessionFlagByte [DERIVED] |
| 007c56b0 | dword_7C56B0 | W | SessionState_56B0 [DERIVED] |
| 007c56b4 | dword_7C56B4 | W | Session_SubState [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007ce2a0 | hinst | W | HInstance [DERIVED] (also: ` — DirectInput instance handle) |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00421cd0 | ConfigIniParser | [LLM] |
| 00423070 | sub_423070 | [LLM] |
| 0042d370 | Game_Enter | [LLM] |
| 0042d5d0 | Game_Setup | [LLM] |
| 0042d6b0 | Game_Init | [LLM] |
| 0042d7a0 | Game_Restart | [LLM] |
| 0042d8a0 | GamePostMainLoop | [LLM] |
| 0042da30 | Game_Post | [LLM] |
| 0042db20 | GameExit | [LLM] |
| 00463160 | NetCommParseCommandLine | [LLM] |
| 004a0d50 | sub_4A0D50 | [LLM] |
| 004b17f0 | sub_4B17F0 | [LLM] |
| 004d7a00 | sub_4D7A00 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
