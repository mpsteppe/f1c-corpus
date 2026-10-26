## _LangCountryEnumProc@4_005c729c — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ff248 | Locale | RW | [LLM] |
| 007ff24c | dword_7FF24C | R | [LLM] |
| 007ff250 | MaxCount | R | [LLM] |
| 007ff254 | dword_7FF254 | R | [LLM] |
| 007ff258 | dword_7FF258 | R | [LLM] |
| 007ff25c | dword_7FF25C | R | [LLM] |
| 007ff260 | dword_7FF260 | RW | [LLM] |
| 007ff261 | byte_7FF261 | W | [LLM] |
| 007ff264 | dword_7FF264 | W | [LLM] |
| 007ff268 | dword_7FF268 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005bf290 | __strcmpi | [LLM] |
| 005c5210 | _strlen | [LLM] |
| 005c76f0 | _TestDefaultCountry | [LLM] |
| 005c770f | _TestDefaultLanguage | [LLM] |
| 005c788d | _LcidFromHexString | [LLM] |
| 005ce1a0 | __strnicmp | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
