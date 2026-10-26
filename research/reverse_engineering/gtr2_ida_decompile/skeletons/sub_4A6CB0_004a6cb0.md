## sub_4A6CB0_004a6cb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x30) | 0x1C | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f138c | ?GetChatRoomMessage@CINet@@QAEXPAD@Z | R | [LLM] |
| 006f1390 | ?GetPendingChat@CINet@@QAEXXZ | R | [LLM] |
| 006f13bc | ?JoinChatRoom@CINet@@QAEJPAD@Z | R | [LLM] |
| 006f13c4 | ?ChatTo@CINet@@QAEXPAD@Z | R | [LLM] |
| 006f16bc | WindowName | R | [LLM] |
| 006f5848 | aNewsLanguage | R | [LLM] |
| 006fbe80 | word_6FBE80 | R | [LLM] |
| 006fc0f4 | aChatbox | R | [LLM] |
| 006fef60 | word_6FEF60 | R | [LLM] |
| 006fef62 | byte_6FEF62 | R | [LLM] |
| 006fef64 | aSS_14 | R | [LLM] |
| 006fef6c | aMainNov | R | [LLM] |
| 006fef78 | aMainSp | R | [LLM] |
| 006fef80 | aMainSim | R | [LLM] |
| 0091cc38 | byte_91CC38 | R | [LLM] |
| 00b6cbb0 | dword_B6CBB0 | R | [LLM] |
| 00b71f90 | dword_B71F90 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041d840 | sub_41D840 | [LLM] |
| 004d0ac0 | sub_4D0AC0 | [LLM] |
| 00615860 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 00631761 | _sprintf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `NEWS_LANGUAGE`
- `NEWS_LANGUAGE`
- `CHATBOX - `
- `%s (%s)`
- `MAIN-NOV`
- `MAIN-SP`
- `MAIN-SIM`
