## SceneGraphFlagPropagation_0054b2c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ClearBuffersLoop (00545850)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x214)+0x10) | 0x10 | R | — | [LLM] |
| *(*(this+0x214)+0x10) | 0x14 | RW | — | [LLM] |
| this | 0x3C | RW | — | [LLM] |
| this | 0x44 | R | — | [LLM] |
| this | 0x4C | R | — | [LLM] |
| this | 0x204 | R | — | [LLM] |
| this | 0x214 | R | — | [LLM] |
| this | 0x218 | RW | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0x214)+0x10) 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x3C: [LLM: once/conditional? does external poke survive?]
- this 0x218: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054b2c0 | SceneGraphFlagPropagation | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
