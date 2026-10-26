## sub_4D9EF0_004d9ef0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4054B0 (004054b0), sub_4DA5E0 (004da5e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x874 | RW | 6 | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x874: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004da044 | jpt_4D9F07 | R | [LLM] |
| 005d54e0 | flt_5D54E0 | R | [LLM] |
| 005fb7e8 | Format | R | [LLM] |
| 0060ffa4 | aAmbientReplayM | R | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |
| 0062a070 | dword_62A070 | R | [LLM] |
| 00767898 | flt_767898 | R | [LLM] |
| 007d6b78 | byte_7D6B78 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00405480 | sub_405480 | [LLM] |
| 004d7da0 | sub_4D7DA0 | [LLM] |
| 004d7f60 | sub_4D7F60 | [LLM] |
| 004d8080 | sub_4D8080 | [LLM] |
| 004d80f0 | sub_4D80F0 | [LLM] |
| 004d81d0 | sub_4D81D0 | [LLM] |
| 004ef930 | sub_4EF930 | [LLM] |
| 004efa70 | sub_4EFA70 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x874 | != | 5 | [LLM] |
| obj | 0x874 | == | 5 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `%s%s`
- `Ambient\replay.mp3`
