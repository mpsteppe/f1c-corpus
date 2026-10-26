## __mbsicmp_005c949c — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** ___dtoxmode (005c0c6b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x1 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00800180 | dword_800180 | R | [LLM] |
| 0080019c | dword_80019C | R | [LLM] |
| 008001a0 | byte_8001A0 | R | [LLM] |
| 008002a1 | byte_8002A1 | R | [LLM] |
| 008003a4 | dword_8003A4 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005bf290 | __strcmpi | [LLM] |
| 005c52b4 | CriticalSectionLazyInitEnter [structural] | [LLM] |
| 005c5315 | __unlock | [LLM] |
| 005c924d | ___crtLCMapStringA | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
