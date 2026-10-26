## sub_5FFCF0_005ffcf0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5E6A50 (005e6a50), sub_6004D0 (006004d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0xAC | RW | 0 | [LLM] |
| this | 0xB0 | RW | — | [LLM] |
| this | 0xB4 | RW | 0 | [LLM] |
| this | 0xB8 | RW | — | [LLM] |
| this | 0x114 | R | — | [LLM] |
| this | 0x124 | R | — | [LLM] |
| this | 0x128 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xAC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xB0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xB4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xB8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005f5900 | sub_5F5900 | [LLM] |
| 005f5a20 | sub_5F5A20 | [LLM] |
| 005ff6f0 | sub_5FF6F0 | [LLM] |
| 00630739 | ??2@YAPAXI@Z | [LLM] |
| 006308d3 | j__free | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xAC | != | 0 | [LLM] |
| this | 0xB8 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
