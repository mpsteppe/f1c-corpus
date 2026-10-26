## sub_4E6CD0_004e6cd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4E6570 (004e6570), sub_50B240 (0050b240), sub_50D130 (0050d130), sub_50D370 (0050d370)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x4CC | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x4CC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00610e1c | dword_610E1C | R | [LLM] |
| 00610e20 | byte_610E20 | R | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e6e00 | sub_4E6E00 | [LLM] |
| 005be8ae | sub_5BE8AE | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `.dds`
