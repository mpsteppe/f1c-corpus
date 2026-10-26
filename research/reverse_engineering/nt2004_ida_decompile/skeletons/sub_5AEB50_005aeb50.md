## sub_5AEB50_005aeb50 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5924D0 (005924d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | RW | — | [LLM] |
| this | 0x118 | R | — | [LLM] |
| this | 0x11C | RW | — | [LLM] |
| this | 0x128 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x10: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x11C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x128: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005fb918 | aRb | R | [LLM] |
| 005fcd58 | aSS_0 | R | [LLM] |
| 0061b5f0 | aIncorrectMasFi | R | [LLM] |
| 0061b60c | aCubemas401 | R | [LLM] |
| 0061b618 | aCubemas400 | R | [LLM] |
| 0061b624 | aCubemas410 | R | [LLM] |
| 0061b630 | aErrorOpeningMa | R | [LLM] |
| 0061bc5c | aUnableToAlloca | R | [LLM] |
| 007e4ccc | byte_7E4CCC | R | [LLM] |
| 007e8d58 | dword_7E8D58 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00591c60 | sub_591C60 | [LLM] |
| 005be8e3 | ??2@YAPAXI@Z | [LLM] |
| 005be9e2 | FileCloseWithLock [structural] | [LLM] |
| 005bea90 | _fopen | [LLM] |
| 005bed6f | sub_5BED6F | [LLM] |
| 005beec8 | _sprintf | [LLM] |
| 005c0803 | __strupr | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `%s\%s`
- `Incorrect MAS file version`
- `CUBEMAS4.01`
- `CUBEMAS4.00`
- `CUBEMAS4.10`
- `Error opening MAS file %s`
