## sub_4DA2E0_004da2e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4B9210 (004b9210)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005fbebc | word_5FBEBC | R | [LLM] |
| 0061005c | aReplayActivati | R | [LLM] |
| 00610070 | aRecordingOn | R | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |
| 0062a170 | dword_62A170 | R | [LLM] |
| 0062a17c | Destination | R | [LLM] |
| 0062a37b | byte_62A37B | W | [LLM] |
| 00761d78 | ppvOut | R | [LLM] |
| 00764d68 | byte_764D68 | R | [LLM] |
| 00764d70 | dword_764D70 | R | [LLM] |
| 0076a820 | dword_76A820 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041f230 | BinarySearchInStringTable [structural] | [LLM] |
| 00457840 | sub_457840 | [LLM] |
| 0045d100 | sub_45D100 | [LLM] |
| 00463490 | sub_463490 | [LLM] |
| 005beab0 | _strncpy | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Replay Activation`
- `Replay Activation`
- `Recording - On`
- `Recording - On`
