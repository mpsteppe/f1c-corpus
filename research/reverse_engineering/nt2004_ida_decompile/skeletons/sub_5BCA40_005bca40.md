## sub_5BCA40_005bca40 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 1 | [LLM] |
| this | 0x4A0 | RW | 18446744073709551615 | [LLM] |
| this | 0x4A4 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4A0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| ff00000000005e86 | byte_FF00000000005E86 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005ba500 | sub_5BA500 | [LLM] |
| 005ba5b0 | sub_5BA5B0 | [LLM] |
| 005ba600 | sub_5BA600 | [LLM] |
| 005bd910 | sub_5BD910 | [LLM] |
| 005bd940 | sub_5BD940 | [LLM] |
| 005bdb70 | GetTickCount [exact] | [LLM] |
| 005bdc00 | sub_5BDC00 | [LLM] |
| 005d26f8 | closesocket [exact] | [LLM] |
| 005d2704 | recvfrom [exact] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
