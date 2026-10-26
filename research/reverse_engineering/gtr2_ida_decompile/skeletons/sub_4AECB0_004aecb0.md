## sub_4AECB0_004aecb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x30) | 0x4 | R | — | [LLM] |
| *(this+0x30) | 0x1C | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006e2aeb | SEH_4AECB0 | R | [LLM] |
| 006f16bc | WindowName | R | [LLM] |
| 006f1f34 | aSS | R | [LLM] |
| 006fd8c4 | aPlayernameneve | R | [LLM] |
| 006ff8bc | aProfileAlready | R | [LLM] |
| 0091cb00 | dword_91CB00 | R | [LLM] |
| 0091cc38 | byte_91CC38 | R | [LLM] |
| 00b6db18 | byte_B6DB18 | R | [LLM] |
| 00b6dc17 | byte_B6DC17 | R | [LLM] |
| 00b6dc18 | byte_B6DC18 | R | [LLM] |
| 00b6f135 | unk_B6F135 | R | [LLM] |
| 00b6f530 | byte_B6F530 | R | [LLM] |
| 00b763d5 | byte_B763D5 | RW | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041d840 | sub_41D840 | [LLM] |
| 004a5f80 | sub_4A5F80 | [LLM] |
| 004a6130 | sub_4A6130 | [LLM] |
| 004e1810 | sub_4E1810 | [LLM] |
| 004e23f0 | sub_4E23F0 | [LLM] |
| 004ea860 | sub_4EA860 | [LLM] |
| 00510770 | sub_510770 | [LLM] |
| 00510a30 | ?Create@PlayerFile@sbdt@@QAEJPAD@Z | [LLM] |
| 00510c90 | sub_510C90 | [LLM] |
| 00514f20 | sub_514F20 | [LLM] |
| 00519b50 | sub_519B50 | [LLM] |
| 006178e0 | ReplaceSpecialCharsWithUnderscoreHyphen [structural] | [LLM] |
| 00630739 | ??2@YAPAXI@Z | [LLM] |
| 006308d3 | j__free | [LLM] |
| 00631761 | _sprintf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `%s%s`
- `PlayerNameNeverUsed`
- `Profile already exists`
