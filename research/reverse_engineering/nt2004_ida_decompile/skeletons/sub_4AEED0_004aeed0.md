## sub_4AEED0_004aeed0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x3C) | 0x0 | R | — | [LLM] |
| *(this+0x74) | 0x38 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x3C | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x3C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea264 | off_5EA264 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049ca20 | ?GetExecutionResourceId@VirtualProcessor@details@Concurrency@@QBEIXZ | [LLM] |
| 004af0a0 | sub_4AF0A0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
