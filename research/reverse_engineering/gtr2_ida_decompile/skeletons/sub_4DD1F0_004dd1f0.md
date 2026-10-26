## sub_4DD1F0_004dd1f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4DD510 (004dd510)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2F8 | R | — | [LLM] |
| this | 0x2FE | R | — | [LLM] |
| this | 0x300 | R | — | [LLM] |
| this | 0x308 | R | — | [LLM] |
| this | 0x30C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x30C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006e535c | SEH_4DD1F0 | R | [LLM] |
| 006f4ed0 | aNormal | R | [LLM] |
| 00712824 | asc_712824 | R | [LLM] |
| 00712a88 | aSoundLostfocus | R | [LLM] |
| 00712a98 | aSoundFocus | R | [LLM] |
| 00712c78 | aName | R | [LLM] |
| 00712cdc | aGizmo | R | [LLM] |
| 00712d18 | aPage_0 | R | [LLM] |
| 00712d20 | aUndefinedLayer | R | [LLM] |
| 00712d38 | aModal | R | [LLM] |
| 0075ad58 | unk_75AD58 | R | [LLM] |
| 0075af70 | byte_75AF70 | R | [LLM] |
| 00b6e1a0 | String1 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dac90 | sub_4DAC90 | [LLM] |
| 004dbb40 | sub_4DBB40 | [LLM] |
| 004dbcd0 | sub_4DBCD0 | [LLM] |
| 004dc3c0 | sub_4DC3C0 | [LLM] |
| 004dce40 | sub_4DCE40 | [LLM] |
| 004df6c0 | sub_4DF6C0 | [LLM] |
| 004dff60 | sub_4DFF60 | [LLM] |
| 004dff90 | sub_4DFF90 | [LLM] |
| 004e03a0 | sub_4E03A0 | [LLM] |
| 004e2a80 | ShortComputation_a9c0 [exact] | [LLM] |
| 004e2b70 | sub_4E2B70 | [LLM] |
| 006131c0 | sub_6131C0 | [LLM] |
| 00630739 | ??2@YAPAXI@Z | [LLM] |
| 00630a80 | _strstr | [LLM] |
| 00631761 | _sprintf | [LLM] |
| 00631c0d | __stricmp | [LLM] |
| 00633686 | __strupr | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x300 | < | 4 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `NORMAL`
- `SOUND_LOSTFOCUS`
- `SOUND_FOCUS`
- `NAME`
- `GIZMO`
- `PAGE`
- `undefined layer type %s`
- `MODAL`
