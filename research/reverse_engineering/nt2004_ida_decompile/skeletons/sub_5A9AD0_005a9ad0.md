## sub_5A9AD0_005a9ad0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4AB110 (004ab110), sub_4AB2E0 (004ab2e0), sub_5A98D0 (005a98d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x38 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x38: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0061bba4 | flt_61BBA4 | W | [LLM] |
| 0061bbc4 | flt_61BBC4 | W | [LLM] |
| 007e6b48 | dword_7E6B48 | R | [LLM] |
| 007e8ce8 | dword_7E8CE8 | R | [LLM] |
| 007e8cec | dword_7E8CEC | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005a9920 | sub_5A9920 | [LLM] |
| 005a9c30 | sub_5A9C30 | [LLM] |
| 005b47f0 | sub_5B47F0 | [LLM] |
| 005be8ae | sub_5BE8AE | [LLM] |
| 005be8bc | __ftol | [LLM] |
| 005be8e3 | ??2@YAPAXI@Z | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
