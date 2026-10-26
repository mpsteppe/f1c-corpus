## __mbsrchr_005c9631 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** ___dtoxmode (005c0c6b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0080019c | dword_80019C | R | [LLM] |
| 008002a1 | byte_8002A1 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005c24b0 | _strrchr | [LLM] |
| 005c52b4 | CriticalSectionLazyInitEnter [structural] | [LLM] |
| 005c5315 | __unlock | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
