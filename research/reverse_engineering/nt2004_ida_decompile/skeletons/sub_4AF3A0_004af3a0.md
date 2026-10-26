## sub_4AF3A0_004af3a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x34) | 0x0 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x34 | RW | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x44 | R | — | [LLM] |
| this | 0x4C | R | — | [LLM] |
| this | 0x54 | R | — | [LLM] |
| this | 0x5C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x34: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea2b4 | off_5EA2B4 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049ca20 | ?GetExecutionResourceId@VirtualProcessor@details@Concurrency@@QBEIXZ | [LLM] |
| 004afee0 | sub_4AFEE0 | [LLM] |
| 005be8ae | sub_5BE8AE | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
