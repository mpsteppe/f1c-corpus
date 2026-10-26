## ChampionshipStandingsReOrdering_00462a10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MultiplayerVehiclePlacement (0042cf10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x3E14 | R | — | [LLM] |
| obj | 0x3FD9 | RW | — | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x3FD9: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005f0730 | dword_5F0730 | RW | VEH[0].0x4058 = plannedPositionAtStart [CONFIRMED] |
| 007c9530 | dword_7C9530 | R | DriverTeamIndexTableEnd [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461530 | FlagBitTest | [LLM] |
| 004647d0 | LinkedListMergeSort_47d0 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x3E14 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
