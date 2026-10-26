## sub_4AF5C0_004af5c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4AD360 (004ad360)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x34 | RW | — | [LLM] |
| this | 0x48 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x34: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x48: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049ca20 | ?GetExecutionResourceId@VirtualProcessor@details@Concurrency@@QBEIXZ | [LLM] |
| 0049ca30 | FieldSetterAt0x8c [exact] | [LLM] |
| 0049d3d0 | sub_49D3D0 | [LLM] |
| 004af450 | sub_4AF450 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
