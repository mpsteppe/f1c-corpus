## sub_4FBF60_004fbf60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4E6E80 (004e6e80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x298) | 0x10 | R | — | [LLM] |
| obj | 0x4BC4 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x68 | R | — | [LLM] |
| this | 0x6C | R | — | [LLM] |
| this | 0x98 | R | — | [LLM] |
| this | 0xA0 | R | — | [LLM] |
| this | 0xAC | R | — | [LLM] |
| this | 0x168 | R | — | [LLM] |
| this | 0x16C | R | — | [LLM] |
| this | 0x1A8 | R | — | [LLM] |
| this | 0x1AC | R | — | [LLM] |
| this | 0x1E8 | R | — | [LLM] |
| this | 0x1EC | R | — | [LLM] |
| this | 0x228 | R | — | [LLM] |
| this | 0x22C | R | — | [LLM] |
| this | 0x268 | R | — | [LLM] |
| this | 0x26C | R | — | [LLM] |
| this | 0x298 | R | — | [LLM] |
| this | 0x2E8 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16bc | WindowName | R | [LLM] |
| 006f2378 | dbl_6F2378 | R | [LLM] |
| 006f2a98 | aS_2 | R | [LLM] |
| 006f3f90 | dbl_6F3F90 | R | [LLM] |
| 006f3fd0 | off_6F3FD0 | R | [LLM] |
| 006f6718 | aOk | R | [LLM] |
| 006f9398 | off_6F9398 | R | [LLM] |
| 006f939c | unk_6F939C | R | [LLM] |
| 006fb7f8 | aDS_1 | R | [LLM] |
| 0071333c | aD_6 | R | [LLM] |
| 00714aec | aSD_6 | R | [LLM] |
| 00714af4 | aDoNotRepair | R | [LLM] |
| 00714b04 | aRepair | R | [LLM] |
| 00714b0c | a8s_0 | R | [LLM] |
| 00714b14 | aDoNotReplace | R | [LLM] |
| 00714b24 | aReplace_0 | R | [LLM] |
| 00714b2c | aNoChange | R | [LLM] |
| 00714b38 | a41fS | R | [LLM] |
| 00731ce8 | String2 | R | [LLM] |
| 0091cc38 | byte_91CC38 | R | [LLM] |
| 00b72454 | dword_B72454 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041d840 | sub_41D840 | [LLM] |
| 00560800 | StringBasedLookup [exact] | [LLM] |
| 0063099c | __ftol2 | [LLM] |
| 00631761 | _sprintf | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x68 | == | 1 | [LLM] |
| this | 0x168 | == | 1 | [LLM] |
| this | 0x1A8 | == | 1 | [LLM] |
| this | 0x1E8 | == | 1 | [LLM] |
| this | 0x228 | == | 1 | [LLM] |
| this | 0x268 | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `N/A`
- `Yes`
- `%d%s`
- `/%d`
- `%s/%d`
- `Do Not Repair`
- `Repair`
- `%.8s`
- `Do Not Replace`
- `Do Not Replace`
- `Do Not Replace`
- `Do Not Replace`
- `Replace`
- `Replace`
- `Replace`
- `Replace`
- `No Change`
- `%4.1f%s`
