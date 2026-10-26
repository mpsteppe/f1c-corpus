## sub_5BDDD0_005bddd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x13 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x13: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d50d4 | __imp_GetTickCount | R | [LLM] |
| 005d5270 | QueryPerformanceCounter | R | [LLM] |
| 00624b54 | a0123456789abcd | R | [LLM] |
| ff00000000005e98 | byte_FF00000000005E98 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005bde70 | sub_5BDE70 | [LLM] |
| 005bde90 | sub_5BDE90 | [LLM] |
| 005c069b | _time | [LLM] |
| 005c28c5 | _clock | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ`
