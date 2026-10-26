## EditBufferStringUpdate_0048b810 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RaceModeScreenSetup (004707c0), SessionSetupScreenSetup (00470960), RaceSessionModeDataLoader (00470f20), UIToggleIncrementDecrementHandler (004713e0), ModeSpecificScreenSetup (00471440), TransmissionAIDifficultyScreenSetup (00471dc0), VirtualFactoryPathFormat (00472400), sub_472510 (00472510), sub_472630 (00472630), sub_472930 (00472930), UIStringFormatDisplay (00472cc0), sub_4732D0 (004732d0), UIFrontendCounterDisplayUpdate (004735b0), sub_474510 (00474510), sub_474AB0 (00474ab0), UIFPSPerformanceSettingDisplay (0047c770), StringCursorReset (0048b950)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x2F0 | RW | 0 | [LLM] |
| this | 0x2F4 | RW | — | [LLM] |
| this | 0x2F5 | R | — | [LLM] |
| this | 0x2F8 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x2F0: [LLM: once/conditional? does external poke survive?]
- this 0x2F4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048b560 | sub_48B560 | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
