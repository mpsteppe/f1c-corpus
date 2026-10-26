## sub_49EEF0_0049eef0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34C | RW | — | [LLM] |
| this | 0x350 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x34C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x350: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00b72314 | dword_B72314 | R | [LLM] |
| 00b74f70 | dword_B74F70 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ce770 | sub_4CE770 | [LLM] |
| 004cfc00 | sub_4CFC00 | [LLM] |
| 00631761 | _sprintf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
