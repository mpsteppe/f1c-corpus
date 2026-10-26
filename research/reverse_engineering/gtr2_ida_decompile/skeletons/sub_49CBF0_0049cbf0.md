## sub_49CBF0_0049cbf0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x30 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f1014 | RegCreateKeyA | R | [LLM] |
| 006f1018 | RegCloseKey | R | [LLM] |
| 006f101c | RegQueryValueExA | R | [LLM] |
| 006f13d4 | ?SetServerName@CINet@@QAEXPAD@Z | R | [LLM] |
| 006f13d8 | ?SetDifficulty@CINet@@QAEXE@Z | R | [LLM] |
| 006f16bc | WindowName | R | [LLM] |
| 006f3b9c | aSerialnumber | R | [LLM] |
| 006f3bac | aSoftwareSbdtAb | R | [LLM] |
| 006f3bc8 | aSoftwareSbdtAb_1 | R | [LLM] |
| 006f3be0 | aSoftwareSbdtAb_0 | R | [LLM] |
| 006fbcb8 | aGtrOnlineLogin | R | [LLM] |
| 006fc374 | aPleaseWait | R | [LLM] |
| 006fda70 | aGtrOnlineCdkey | R | [LLM] |
| 006fda84 | aGarageonlinepa | R | [LLM] |
| 0091cc38 | byte_91CC38 | R | [LLM] |
| 00b6cbb0 | dword_B6CBB0 | R | [LLM] |
| 00b6cbbc | dword_B6CBBC | W | [LLM] |
| 00b6cbc0 | byte_B6CBC0 | R | [LLM] |
| 00b6cbc2 | byte_B6CBC2 | R | [LLM] |
| 00b6cbc3 | byte_B6CBC3 | R | [LLM] |
| 00b6dfd0 | byte_B6DFD0 | W | [LLM] |
| 00b71f90 | dword_B71F90 | R | [LLM] |
| 00b7384c | dword_B7384C | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041d840 | sub_41D840 | [LLM] |
| 004df020 | sub_4DF020 | [LLM] |
| 004e1810 | sub_4E1810 | [LLM] |
| 004eb900 | sub_4EB900 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `SerialNumber`
- `Software\SBDT AB\GTR2\Keys`
- `Software\SBDT AB\GTR2\Keys`
- `Software\SBDT AB\GTR2`
- `Software\SBDT AB`
- `GTR_ONLINE_LOGIN`
- `Please Wait...`
- `GTR_ONLINE_CDKEY`
- `GTR_ONLINE_CDKEY`
- `GARAGEONLINEPAGE`
