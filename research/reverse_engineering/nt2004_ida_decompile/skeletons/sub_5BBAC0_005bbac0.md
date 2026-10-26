## sub_5BBAC0_005bbac0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5B99E0 (005b99e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x20 | RW | — | [LLM] |
| this | 0x24 | RW | 0 | [LLM] |
| this | 0x3C | RW | 0 | [LLM] |
| this | 0x40 | RW | — | [LLM] |
| this | 0x44 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x20: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x24: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x3C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x40: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x44: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005bbb10 | sub_5BBB10 | [LLM] |
| 005bdb90 | NetworkStartup [exact] | [LLM] |
| 005d26da | socket [exact] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
