## sub_4DADA0_004dada0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4DC3C0 (004dc3c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2F8 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006e5194 | SEH_4DADA0 | R | [LLM] |
| 00712824 | asc_712824 | R | [LLM] |
| 0071282c | aLostfocus | R | [LLM] |
| 00712838 | aFocus | R | [LLM] |
| 00712840 | aRelease | R | [LLM] |
| 00712848 | aClick | R | [LLM] |
| 00712850 | aSimulateclick | R | [LLM] |
| 00712860 | aExitGame | R | [LLM] |
| 0071286c | aDoLastPage | R | [LLM] |
| 0071287c | aDropPopups | R | [LLM] |
| 00712888 | aDoLayer | R | [LLM] |
| 00712894 | aDoPage | R | [LLM] |
| 0075ad58 | unk_75AD58 | R | [LLM] |
| 0075af70 | byte_75AF70 | R | [LLM] |
| 016c9484 | off_16C9484 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cd470 | sub_4CD470 | [LLM] |
| 004cd4b0 | sub_4CD4B0 | [LLM] |
| 004cd4f0 | sub_4CD4F0 | [LLM] |
| 004cd530 | sub_4CD530 | [LLM] |
| 004dac90 | sub_4DAC90 | [LLM] |
| 004e3b40 | F_7FieldSentineInit [exact] | [LLM] |
| 006131c0 | sub_6131C0 | [LLM] |
| 00615860 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 00630739 | ??2@YAPAXI@Z | [LLM] |
| 00630a80 | _strstr | [LLM] |
| 00631c0d | __stricmp | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `LOSTFOCUS`
- `FOCUS`
- `RELEASE`
- `CLICK`
- `SIMULATECLICK`
- `EXIT_GAME`
- `DO_LAST_PAGE`
- `DROP_POPUPS`
- `DO_LAYER`
- `DO_PAGE`
