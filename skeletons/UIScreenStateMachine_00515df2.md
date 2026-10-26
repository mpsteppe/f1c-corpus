## UIScreenStateMachine_00515df2 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | [LLM] |
| obj | 0x14 | RW | 58 | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x7C | R | — | [LLM] |
| this | 0x84 | RW | — | [LLM] |
| this | 0x18C | R | — | [LLM] |
| this | 0x190 | R | — | [LLM] |
| this | 0x194 | R | — | [LLM] |
| this | 0x19C | R | — | [LLM] |
| this | 0x19D | RW | 1 | [LLM] |
| this | 0x1A0 | RW | 0 | [LLM] |
| this | 0x1E1 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x84: [LLM: once/conditional? does external poke survive?]
- this 0x19D: [LLM: once/conditional? does external poke survive?]
- this 0x1A0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005159f5 | TextureSurfaceValidator | [LLM] |
| 00515db8 | VtableDelegateDispatch | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1A0 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
