## sub_5F7EE0_005f7ee0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x24A8) | 0x150 | R | — | [LLM] |
| this | 0x24A0 | R | — | [LLM] |
| this | 0x24A8 | RW | — | [LLM] |
| this | 0x24AC | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x24A8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005f6680 | sub_5F6680 | [LLM] |
| 00631c0d | __stricmp | [LLM] |
| 00633686 | __strupr | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
