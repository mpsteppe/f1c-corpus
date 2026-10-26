## sub_4FCB90_004fcb90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4302B0 (004302b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x108 | RW | 0 | [LLM] |
| this | 0x10C | RW | 0 | [LLM] |
| this | 0x110 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x108: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x10C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x110: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005fd340 | NumOfElements | R | [LLM] |
| 00611a24 | aDDevNascar2004_21 | R | [LLM] |
| 00611dd4 | aEnteredSteward_2 | R | [LLM] |
| 0075aad0 | dword_75AAD0 | R | [LLM] |
| 00766188 | byte_766188 | R | [LLM] |
| 007689cc | dword_7689CC | R | [LLM] |
| 0076bb28 | dword_76BB28 | R | [LLM] |
| 007d7920 | dword_7D7920 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00414bb0 | sub_414BB0 | [LLM] |
| 004dc3f0 | sub_4DC3F0 | [LLM] |
| 004e6000 | sub_4E6000 | [LLM] |
| 004fcc70 | sub_4FCC70 | [LLM] |
| 00500f90 | sub_500F90 | [LLM] |
| 00500fe0 | sub_500FE0 | [LLM] |
| 005be8ae | sub_5BE8AE | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `D:\dev\NASCAR_2004\Source\steward.cpp`
- `Entered Steward::Post()`
