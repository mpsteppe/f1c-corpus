## StateCleanupNotification_00489cb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MenuCommandDispatcher (004674e0), CareerModeDriverStatsReset (00468a00), PlayerStatsDisplayCleanup (00469d30), ResultsPageBuilder (00469fb0), StandingsDisplay (0046a560), SessionEntryListCleanup (0046ae60), sub_46B9B0 (0046b9b0), sub_46BA20 (0046ba20), sub_46BC20 (0046bc20), MultiplayerSessionJoinHandler (0046de10), ShortComputation_e170 (0046e170), HTMLSeasonOutput (0046ee60), ExtensionStripperForAllListEntries (0046f170), sub_470190 (00470190), sub_475150 (00475150), sub_47BF30 (0047bf30), sub_47C360 (0047c360), sub_47C6C0 (0047c6c0), sub_47D800 (0047d800), DriverCareerStatsHTMLWriter (0047dd10), sub_47E0A0 (0047e0a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x11C) | 0x8C | R | — | [LLM] |
| *(this+0x90) | 0x0 | R | — | [LLM] |
| obj | 0x2C | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x90 | RW | 0 | [LLM] |
| this | 0x94 | RW | 0 | [LLM] |
| this | 0x168 | RW | 18446744073709551615 | [LLM] |

**Written-by note (persistence):**
- this 0x90: [LLM: once/conditional? does external poke survive?]
- this 0x94: [LLM: once/conditional? does external poke survive?]
- this 0x168: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
