## RaceStandingsRankingsComputation_004c0f60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalSeasonDataFree (004c2830)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1B0 | R | — | [LLM] |
| this | 0xB104 | R | — | [LLM] |
| this | 0xB108 | RW | — | [LLM] |
| this | 0xB11C | R | — | [LLM] |
| this | 0xB14C | R | — | [LLM] |
| this | 0xB150 | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0xB108: [LLM: once/conditional? does external poke survive?]
- this 0xB150: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c0910 | SeasonScoring | [LLM] |
| 004c11d0 | FlagsGetter | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xB14C | == | 7 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
