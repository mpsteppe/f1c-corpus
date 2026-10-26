## sub_4EF3F0_004ef3f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4EFEF0 (004efef0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x4)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x4)+0x4) | 0x0 | R | — | [LLM] |
| *(*(this+0x4)+0x4) | 0x4 | R | — | [LLM] |
| *(this+0x4) | 0x0 | R | — | [LLM] |
| *(this+0x4) | 0x4 | RW | — | [LLM] |
| *(this+0x4) | 0x8 | R | — | [LLM] |
| this | 0x4 | RW | 0 | [LLM] |
| this | 0x8 | RW | 0 | [LLM] |
| this | 0xC | RW | 0 | [LLM] |
| this | 0x10 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- *(this+0x4) 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x10: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea79c | off_5EA79C | R | [LLM] |
| 00611130 | dword_611130 | R | [LLM] |
| 0061113c | off_61113C | RW | [LLM] |
| 00611260 | aMagicCarpetRid | R | [LLM] |
| 00611274 | aMp3 | R | [LLM] |
| 0061127c | aWav | R | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |
| 0062a0d8 | unk_62A0D8 | R | [LLM] |
| 007d3c50 | dword_7D3C50 | RW | [LLM] |
| 007d3c54 | flt_7D3C54 | R | [LLM] |
| 007d6bb0 | dword_7D6BB0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040d5b0 | sub_40D5B0 | [LLM] |
| 00410de0 | sub_410DE0 | [LLM] |
| 00410e00 | sub_410E00 | [LLM] |
| 00414410 | sub_414410 | [LLM] |
| 00414470 | ShortComputation_a780 [exact] | [LLM] |
| 00414480 | sub_414480 | [LLM] |
| 004192a0 | sub_4192A0 | [LLM] |
| 004667a0 | LinkedListDestructorWithData [structural] | [LLM] |
| 004db610 | ShortComputation_ac20 [exact] | [LLM] |
| 004dbcf0 | sub_4DBCF0 | [LLM] |
| 004ef7b0 | sub_4EF7B0 | [LLM] |
| 004ef7e0 | sub_4EF7E0 | [LLM] |
| 004f03b0 | sub_4F03B0 | [LLM] |
| 00578600 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 00579060 | sub_579060 | [LLM] |
| 005be8e3 | ??2@YAPAXI@Z | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4 | == | 0 | [LLM] |
| this | 0x10 | <= | 0 | [LLM] |
| this | 0x10 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Magic Carpet Ride`
- `*.mp3`
- `*.wav`
