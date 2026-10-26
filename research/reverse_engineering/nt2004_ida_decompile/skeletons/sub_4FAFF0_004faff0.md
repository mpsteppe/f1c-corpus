## sub_4FAFF0_004faff0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4DD350 (004dd350), sub_4FA450 (004fa450), sub_4FB930 (004fb930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x94 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x94: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005fd340 | NumOfElements | R | [LLM] |
| 0060fd10 | aGreenFlag | R | [LLM] |
| 00629328 | flt_629328 | R | [LLM] |
| 0075aad0 | dword_75AAD0 | R | [LLM] |
| 00764d68 | byte_764D68 | R | [LLM] |
| 0079fc40 | dword_79FC40 | RW | [LLM] |
| 007d3c44 | dword_7D3C44 | RW | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045d100 | sub_45D100 | [LLM] |
| 004d0d00 | sub_4D0D00 | [LLM] |
| 004dc260 | sub_4DC260 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Green Flag`
