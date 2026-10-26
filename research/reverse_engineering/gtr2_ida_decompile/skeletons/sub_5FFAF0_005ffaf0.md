## sub_5FFAF0_005ffaf0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5E5CC0 (005e5cc0), sub_5E66A0 (005e66a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0xF0 | RW | 64 | [LLM] |
| this | 0xF4 | RW | 64 | [LLM] |
| this | 0x10C | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xF0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xF4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x10C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006ece2b | SEH_5FFAF0 | R | [LLM] |
| 00fb272c | dword_FB272C | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005e2b30 | sub_5E2B30 | [LLM] |
| 005e38b0 | sub_5E38B0 | [LLM] |
| 005feb60 | sub_5FEB60 | [LLM] |
| 005ff750 | sub_5FF750 | [LLM] |
| 00630739 | ??2@YAPAXI@Z | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
