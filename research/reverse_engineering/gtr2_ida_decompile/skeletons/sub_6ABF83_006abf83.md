## sub_6ABF83_006abf83 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0xFC | RW | — | [LLM] |
| this | 0x100 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xFC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x100: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006825a9 | sub_6825A9 | [LLM] |
| 006875a0 | sub_6875A0 | [LLM] |
| 00688bdf | sub_688BDF | [LLM] |
| 0068feca | sub_68FECA | [LLM] |
| 006a267e | sub_6A267E | [LLM] |
| 006a2906 | sub_6A2906 | [LLM] |
| 006bc1a9 | sub_6BC1A9 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
