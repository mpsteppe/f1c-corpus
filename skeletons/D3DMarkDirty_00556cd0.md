## D3DMarkDirty_00556cd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NestedLinkedListTraversalWithDirtyMark (005570c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x44 | R | — | [LLM] |
| this | 0x4C | R | — | [LLM] |
| this | 0x204 | R | — | [LLM] |
| this | 0x224 | R | — | [LLM] |
| this | 0x228 | RW | — | [LLM] |
| this | 0x32C | R | — | [LLM] |
| this | 0x330 | R | — | [LLM] |
| this | 0x368 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x228: [LLM: once/conditional? does external poke survive?]
- this 0x368: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00556cd0 | D3DMarkDirty | [LLM] |
| 0055d720 | sub_55D720 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
