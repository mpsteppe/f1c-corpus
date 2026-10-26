## SetupValueFormatWithOffset_0042f260 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SetupValueFormatDispatcher (0042f2f0), VehicleSetupValueFormatter (0042f470)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0xC70 | R | — | [LLM] |
| this | 0xC78 | R | — | [LLM] |
| this | 0xC84 | R | — | [LLM] |
| this | 0x199C | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059ea18 | dbl_59EA18 | R | TimeDisplayMultMs [DERIVED] |
| 0059ea20 | dbl_59EA20 | R | QREpsilonThreshold [DERIVED] |
| 005c36f4 | a1fS | R | IntFormatSpecifier [DERIVED] |
| 005c3780 | a3fS | R | FormatStr3fS [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
