## sub_5A6DF0_005a6df0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_59FCA0 (0059fca0), sub_5AEF20 (005aef20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00800000 | unk_800000 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053d49b | sub_53D49B | [LLM] |
| 0053d6e9 | sub_53D6E9 | [LLM] |
| 005a6610 | sub_5A6610 | [LLM] |
| 005b41c0 | sub_5B41C0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
