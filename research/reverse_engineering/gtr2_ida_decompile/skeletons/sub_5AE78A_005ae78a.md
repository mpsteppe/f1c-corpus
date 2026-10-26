## sub_5AE78A_005ae78a — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6477EA (006477ea), sub_64B29B (0064b29b), RenderFeatureDispatch [structural] (0064b2d5)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f1018 | RegCloseKey | R | [LLM] |
| 006f101c | RegQueryValueExA | R | [LLM] |
| 006f1054 | RegOpenKeyA | R | [LLM] |
| 006f11cc | GetSystemInfo | R | [LLM] |
| 00728fc0 | aSoftwareMicros | R | [LLM] |
| 00728fdc | aDisablemmx | R | [LLM] |
| 00904d48 | dword_904D48 | RW | [LLM] |
| ff0000000000a5a3 | byte_FF0000000000A5A3 | R | [LLM] |
| ff0000000000a5ac | byte_FF0000000000A5AC | R | [LLM] |
| ff0000000000a5b4 | byte_FF0000000000A5B4 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005ae762 | sub_5AE762 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `DisableMMX`
