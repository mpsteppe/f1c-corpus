## sub_5A3FF0_005a3ff0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4AEA10 (004aea10), sub_4B2890 (004b2890), sub_4B4BC0 (004b4bc0), sub_4B4CA0 (004b4ca0), sub_4B4D00 (004b4d00), sub_4B4D40 (004b4d40), sub_4B5740 (004b5740), sub_501610 (00501610), sub_592E10 (00592e10), sub_5A41A0 (005a41a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | 0 | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x64 | R | — | [LLM] |
| this | 0x9C | R | — | [LLM] |
| this | 0xA0 | R | — | [LLM] |
| this | 0xA8 | R | — | [LLM] |
| this | 0x10B8 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x14: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007e6b48 | dword_7E6B48 | R | [LLM] |
| 007e8d04 | dword_7E8D04 | R | [LLM] |
| 007e8e5c | dword_7E8E5C | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005a3350 | sub_5A3350 | [LLM] |
| 005a8020 | sub_5A8020 | [LLM] |
| 005a80b0 | ArithmeticComparison_0f90 [exact] | [LLM] |
| 005a8250 | sub_5A8250 | [LLM] |
| 005ab360 | sub_5AB360 | [LLM] |
| 005ab3a0 | sub_5AB3A0 | [LLM] |
| 005b4cc0 | sub_5B4CC0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
