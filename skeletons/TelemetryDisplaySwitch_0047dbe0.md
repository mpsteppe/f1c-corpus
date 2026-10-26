## TelemetryDisplaySwitch_0047dbe0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xEC | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0047dcf4 | jpt_47DBFA | R | [LLM] |
| 005c5bcc | a13f | R | FormatString_1_3f [DERIVED] |
| 005c7370 | asc_5C7370 | R | EngineStalledString [DERIVED] |
| 005c7374 | aDS_7 | R | DS_7String [DERIVED] |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 008ab6ec | dword_8AB6EC | R | ScoringDataPtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00487010 | UIListIndexedAccessor | [LLM] |
| 00488b40 | UIStringComparison | [LLM] |
| 004b9c80 | RangeWidthGetter | [LLM] |
| 004b9cb0 | VehicleLifetimeAverageAccessor | [LLM] |
| 004b9ce0 | Delegation | [LLM] |
| 004b9e30 | VehicleDataAccessor | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
