## SeasonSceneInitialization_00477720 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xF0)+0x3C) | 0x0 | R | — | [LLM] |
| *(this+0xF0) | 0x3C | R | — | [LLM] |
| obj | 0xA0 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0xF0 | R | — | [LLM] |
| this | 0xF8 | RW | — | [LLM] |
| this | 0xFC | R | — | [LLM] |
| this | 0x174 | RW | — | [LLM] |
| this | 0x184 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xF8: [LLM: once/conditional? does external poke survive?]
- this 0x174: [LLM: once/conditional? does external poke survive?]
- this 0x184: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface [DERIVED] (also: ` — game command dispatch interface pointer) |
| 007ce64c | dword_7CE64C | R | GameFilterDataPath [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00476660 | SeasonPathMatchSearch | [LLM] |
| 00476ec0 | SeasonSceneSearchByName | [LLM] |
| 00477810 | UtilityFunction_7810 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
