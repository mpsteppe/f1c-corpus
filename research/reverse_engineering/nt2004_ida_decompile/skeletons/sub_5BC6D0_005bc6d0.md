## sub_5BC6D0_005bc6d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5B9D90 (005b9d90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | [LLM] |
| this | 0x4A0 | RW | — | [LLM] |
| this | 0x4A4 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4A0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4A4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00624b04 | aEchoTest | R | [LLM] |
| ff00000000005e85 | byte_FF00000000005E85 | W | [LLM] |
| ff00000000005e86 | byte_FF00000000005E86 | W | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005bc800 | sub_5BC800 | [LLM] |
| 005bdb70 | GetTickCount [exact] | [LLM] |
| 005d26c2 | htons [exact] | [LLM] |
| 005d26da | socket [exact] | [LLM] |
| 005d26e6 | sendto [exact] | [LLM] |
| 005d26f2 | setsockopt [exact] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `\echo\test`
