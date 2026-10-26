## UIScrollWidgetUpdate_00488a30 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x18 | R | — | [LLM] |
| obj | 0x1C | R | — | [LLM] |
| obj | 0x24 | R | — | [LLM] |
| obj | 0x2C | R | — | [LLM] |
| obj | 0x98 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0xEC | R | — | [LLM] |
| this | 0xED | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0xED: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486600 | sub_486600 | [LLM] |
| 00488900 | DeltaBasedUpdate | [LLM] |
| 00498880 | DualFieldRead | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
