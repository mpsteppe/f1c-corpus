## ___dtoxmode_005c0c6b — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** __stat (005c0d23)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005f65d0 | aCom | R | [LLM] |
| 005f65d8 | aBat | R | [LLM] |
| 005f65e0 | aCmd | R | [LLM] |
| 005f65e8 | aExe | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005c949c | __mbsicmp | [LLM] |
| 005c9631 | __mbsrchr | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `.bat`
- `.cmd`
- `.exe`
