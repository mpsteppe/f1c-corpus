## sub_518AAA_00518aaa — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5119E9 (005119e9)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x58 | RW | — | [LLM] |
| this | 0x5D | RW | — | [LLM] |
| this | 0x104 | RW | — | [LLM] |
| this | 0x108 | RW | — | [LLM] |
| this | 0x10A | RW | — | [LLM] |
| this | 0x116 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x58: [LLM: once/conditional? does external poke survive?]
- this 0x5D: [LLM: once/conditional? does external poke survive?]
- this 0x104: [LLM: once/conditional? does external poke survive?]
- this 0x108: [LLM: once/conditional? does external poke survive?]
- this 0x10A: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005afc74 | aTruncatingInco | R | String_TruncatingInco [DERIVED] |
| 005afc9c | aInvalidPalette | R | aInvalidPalette [DERIVED] |
| 005afcb4 | aDuplicatePlteC | R | DuplicatePlteC [DERIVED] |
| 005afccc | aInvalidPlteAft | R | InvalidPlteAfterString [DERIVED] |
| 005afce4 | aMissingIhdrBef_0 | R | PNG_NoIHDRString [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00511869 | GuardedCallWithLongjmp | [LLM] |
| 00511887 | CallbackDispatch | [LLM] |
| 00513b12 | FlagSetterWithGuard | [LLM] |
| 00513c80 | sub_513C80 | [LLM] |
| 00517f58 | sub_517F58 | [LLM] |
| 00518828 | sub_518828 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x116 | != | 3 | [LLM] |
| this | 0x116 | == | 3 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
