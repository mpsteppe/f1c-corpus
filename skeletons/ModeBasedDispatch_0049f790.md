## ModeBasedDispatch_0049f790 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_f070 (0049f070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea518 | dword_5EA518 | R | ActiveControlProfilePtr [DERIVED] |
| 005ea528 | dword_5EA528 | R | AudioDeviceState [DERIVED] |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007cc234 | dword_7CC234 | R | GameUIFeatureFlag [DERIVED] |
| 007cc28c | dword_7CC28C | R | ScoringGateFlag [DERIVED] |
| 007cc2b8 | dword_7CC2B8 | R | AudioChannelBusyFlag [DERIVED] |
| 007cc2e4 | dword_7CC2E4 | R | AudioChannelGate [DERIVED] |
| 007cc310 | dword_7CC310 | R | ButtonStateFlag [DERIVED] |
| 007cf7ac | byte_7CF7AC | R | Byte_InputFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049f150 | FunctionCallWrapper_f150 | [LLM] |
| 0049f170 | sub_49F170 | [LLM] |
| 004a5750 | UtilityFunction_5750 | [LLM] |
| 004a57a0 | IndexDecrementWithBoundsWrap | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | != | 1 | [LLM] |
| this | 0x0 | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
