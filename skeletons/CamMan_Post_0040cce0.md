## CamMan_Post_0040cce0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Post (0042da30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x18)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x1C)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x20)+0x0) | 0x0 | R | — | [LLM] |
| *(this+0x18) | 0x0 | R | — | [LLM] |
| *(this+0x1C) | 0x0 | R | — | [LLM] |
| *(this+0x20) | 0x0 | R | — | [LLM] |
| this | 0x8 | RW | 0 | [LLM] |
| this | 0x18 | RW | 0 | [LLM] |
| this | 0x1C | RW | 0 | [LLM] |
| this | 0x20 | RW | 0 | [LLM] |
| this | 0x2E | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x1C: [LLM: once/conditional? does external poke survive?]
- this 0x20: [LLM: once/conditional? does external poke survive?]
- this 0x2E: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be958 | aDDevF119992002_15 | R | AssertStr_SourcePath_15 [DERIVED] |
| 005be99c | aEnteredCammanP | R | String_EnteredCamManP [DERIVED] |
| 005ea4e8 | flt_5EA4E8 | R | RandomOffsetFlag [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004083e0 | StructInitWithConditionalNotify | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
