## HWInput_Restart_00455da0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Restart (0042d7a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1F98 | R | — | [LLM] |
| this | 0x1F9C | R | — | [LLM] |
| this | 0x2428 | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x2428: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c56a4 | aDDevF119992002_13 | R | SourcePathFormatString [DERIVED] |
| 005c5700 | aEnteredHwinput_2 | R | EnteredHwinputString [DERIVED] |
| 005d6d60 | dword_5D6D60 | R | ScreenWidth [DERIVED] |
| 005d6d64 | dword_5D6D64 | R | ScreenWidth [DERIVED] (also: input device parameters) |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007d1ffc | dword_7D1FFC | R | AudioQualityLevel [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044f0a0 | BVHTreeNodeArrayInit | [LLM] |
| 0044f680 | FrustumViewportSetup | [LLM] |
| 0044ff50 | sub_44FF50 | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1F9C | == | 89 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
