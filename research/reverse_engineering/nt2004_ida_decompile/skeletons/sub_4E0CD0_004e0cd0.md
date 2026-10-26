## sub_4E0CD0_004e0cd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_45AC00 (0045ac00), sub_516FF0 (00516ff0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x924 | R | — | [LLM] |
| this | 0x928 | R | — | [LLM] |
| this | 0x92C | R | — | [LLM] |
| this | 0x930 | R | — | [LLM] |
| this | 0x934 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x934: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e0300 | SphereProximityTag [structural] | [LLM] |
| 005be8bc | __ftol | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
