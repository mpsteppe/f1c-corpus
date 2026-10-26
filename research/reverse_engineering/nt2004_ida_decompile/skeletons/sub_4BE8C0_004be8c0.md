## sub_4BE8C0_004be8c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4BFD80 (004bfd80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC8 | RW | 18446744073709551615 | [LLM] |

**Written-by note (persistence):**
- this 0xC8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0060116c | aSSS_3 | R | [LLM] |
| 0060950c | aCmapsMas | R | [LLM] |
| 00609f24 | aCdbMas | R | [LLM] |
| 00609f2c | aPitsMas | R | [LLM] |
| 0060a008 | aPitanimsMas | R | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |
| 0062a068 | dword_62A068 | R | [LLM] |
| 0062a0b8 | dword_62A0B8 | R | [LLM] |
| 007da988 | dword_7DA988 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bd350 | sub_4BD350 | [LLM] |
| 005924d0 | sub_5924D0 | [LLM] |
| 00592750 | sub_592750 | [LLM] |
| 005beec8 | _sprintf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `%s%s%s`
- `%s%s%s`
- `CMAPS.MAS`
- `CDB.MAS`
- `PITS.MAS`
- `PITANIMS.MAS`
