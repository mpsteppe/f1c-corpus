## SeasonSceneMatchByIndex_004c4ff0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TrackSceneConfigLoader (00477680)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x10) | 0x0 | R | — | [LLM] |
| *(this+0x8) | 0x0 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ac394 | dword_8AC394 | R | VehicleArray (stride 0x424) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588410 | sub_588410 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
