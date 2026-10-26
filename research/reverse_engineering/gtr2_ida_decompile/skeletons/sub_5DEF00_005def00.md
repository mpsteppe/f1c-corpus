## sub_5DEF00_005def00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5DF0E0 (005df0e0), sub_5DF240 (005df240)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | [LLM] |
| this | 0x40C | RW | — | [LLM] |
| this | 0x80C | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x40C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x80C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16bc | WindowName | R | [LLM] |
| 006f30ac | asc_6F30AC | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00631c0d | __stricmp | [LLM] |
| 006331df | sub_6331DF | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
