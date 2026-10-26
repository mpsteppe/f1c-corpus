## AIDatabase_Init_004040a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Init (0042d6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x118 | RW | — | [LLM] |
| this | 0x11C | RW | — | [LLM] |
| this | 0x120 | RW | — | [LLM] |
| this | 0x124 | RW | — | [LLM] |
| this | 0x130 | RW | — | [LLM] |
| this | 0x134 | RW | — | [LLM] |
| this | 0x138 | RW | — | [LLM] |
| this | 0x148 | RW | — | [LLM] |
| this | 0x15C | RW | 1 | [LLM] |
| this | 0x160 | RW | 104 | [LLM] |
| this | 0x164 | RW | 52 | [LLM] |
| this | 0x168 | RW | 3 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x118: [LLM: once/conditional? does external poke survive?]
- this 0x11C: [LLM: once/conditional? does external poke survive?]
- this 0x120: [LLM: once/conditional? does external poke survive?]
- this 0x124: [LLM: once/conditional? does external poke survive?]
- this 0x130: [LLM: once/conditional? does external poke survive?]
- this 0x134: [LLM: once/conditional? does external poke survive?]
- this 0x138: [LLM: once/conditional? does external poke survive?]
- this 0x148: [LLM: once/conditional? does external poke survive?]
- this 0x15C: [LLM: once/conditional? does external poke survive?]
- this 0x160: [LLM: once/conditional? does external poke survive?]
- this 0x164: [LLM: once/conditional? does external poke survive?]
- this 0x168: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e448 | flt_59E448 | R | TileSteppingMultiplier [DERIVED] |
| 0059e474 | flt_59E474 | R | PhysicsConstant_59E474 [DERIVED] |
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |
| 005be41c | aDDevF119992002_14 | R | StrDevicePath [DERIVED] |
| 005be690 | aRt | R | Str_RT [DERIVED] |
| 005be694 | aAiDatabaseFile | R | Key_AIDatabaseFile [DERIVED] |
| 005be6a8 | aEnteredAidatab | R | EnteredAIDatabaseString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007ce608 | dword_7CE608 | R | [LLM] |
| 007d01a0 | dword_7D01A0 | R | AIDifficultySlider [CONFIRMED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00402690 | sub_402690 | [LLM] |
| 004c58a0 | StringCopyWithValidation | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 00587d02 | FileCloseWithLock | [LLM] |
| 00587db0 | sub_587DB0 | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
