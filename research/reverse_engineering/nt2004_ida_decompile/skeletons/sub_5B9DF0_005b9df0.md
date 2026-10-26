## sub_5B9DF0_005b9df0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x60C | RW | 0 | [LLM] |
| this | 0x610 | RW | — | [LLM] |
| this | 0x614 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x60C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x610: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x614: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005b9ee0 | sub_5B9EE0 | [LLM] |
| 005bbb80 | sub_5BBB80 | [LLM] |
| 005bbd50 | sub_5BBD50 | [LLM] |
| 005bc930 | sub_5BC930 | [LLM] |
| 005bd910 | sub_5BD910 | [LLM] |
| 005bd940 | sub_5BD940 | [LLM] |
| 005bda10 | sub_5BDA10 | [LLM] |
| 005d26c2 | htons [exact] | [LLM] |
| 005d271c | inet_addr [exact] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
