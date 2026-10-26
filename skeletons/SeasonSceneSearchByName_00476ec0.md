## SeasonSceneSearchByName_00476ec0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SeasonSceneInitialization (00477720)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xF0)+0x4) | 0x0 | R | — | [LLM] |
| *(*(this+0xF0)+0x4) | 0x1 | R | — | [LLM] |
| *(this+0xF0) | 0x4 | R | — | [LLM] |
| obj | 0xA0 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0xF0 | R | — | [LLM] |
| this | 0xF8 | RW | — | [LLM] |
| this | 0xFC | R | — | [LLM] |
| this | 0x174 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xF8: [LLM: once/conditional? does external poke survive?]
- this 0x174: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007ce64c | dword_7CE64C | R | GameFilterDataPath [DERIVED] |
| 008ac388 | unk_8AC388 | R | VehicleFilePathBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c40b0 | ConditionalDispatch_40b0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
