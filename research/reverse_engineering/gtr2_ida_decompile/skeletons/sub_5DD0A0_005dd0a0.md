## sub_5DD0A0_005dd0a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4076B0 (004076b0), sub_60F3B0 (0060f3b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1B4 | R | — | [LLM] |
| this | 0x1BC | RW | — | [LLM] |
| this | 0x1C0 | R | — | [LLM] |
| this | 0x1C4 | R | — | [LLM] |
| this | 0x1CC | RW | — | [LLM] |
| this | 0x1D0 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x1BC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1CC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00fb27a4 | dword_FB27A4 | R | [LLM] |
| 00fb2d78 | dword_FB2D78 | R | [LLM] |
| 00fb2d80 | dword_FB2D80 | RW | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005dcff0 | sub_5DCFF0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
