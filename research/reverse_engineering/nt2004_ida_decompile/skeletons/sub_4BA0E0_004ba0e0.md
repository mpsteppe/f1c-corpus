## sub_4BA0E0_004ba0e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4DD490 (004dd490)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 1 | [LLM] |
| this | 0x4 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005fb990 | aTrackside | R | [LLM] |
| 006291cc | dword_6291CC | R | [LLM] |
| 00629328 | flt_629328 | R | [LLM] |
| 0062bf64 | unk_62BF64 | R | [LLM] |
| 0075aacc | dword_75AACC | R | [LLM] |
| 0076693c | dword_76693C | R | [LLM] |
| 007d7978 | dword_7D7978 | R | [LLM] |
| 007d7988 | dword_7D7988 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c410 | sub_40C410 | [LLM] |
| 0041b080 | sub_41B080 | [LLM] |
| 0042dba0 | sub_42DBA0 | [LLM] |
| 004ba1a0 | sub_4BA1A0 | [LLM] |
| 004eed40 | sub_4EED40 | [LLM] |
| 00501f60 | sub_501F60 | [LLM] |
| 0051bc20 | sub_51BC20 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Trackside`
