## DeltaBasedUpdate_00488900 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIScrollWidgetUpdate (00488a30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x18 | R | — | [LLM] |
| obj | 0x1C | R | — | [LLM] |
| obj | 0x24 | R | — | [LLM] |
| obj | 0x2C | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0xE0 | RW | — | [LLM] |
| this | 0xED | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xE0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00488970 | ShortComputation_8970 | [LLM] |
| 00498880 | DualFieldRead | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
