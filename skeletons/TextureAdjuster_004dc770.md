## TextureAdjuster_004dc770 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D0110 (004d0110), sub_4D1450 (004d1450), PitCrewInstanceSetup (004ddad0), sub_4FC400 (004fc400)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d4b98 | aUnableToAdjust | R | String_UnableToAdjust [DERIVED] |
| 005d4be0 | aDDevF119992002_5 | R | DDevString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 004dc430 | ConditionalDispatchWithGlobalCheck | [LLM] |
| 004dc450 | StringCompareCopy | [LLM] |
| 00548890 | sub_548890 | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
