## ModeBasedDispatch_0049f790 — ModeBasedDispatch

**Summary:** Dispatches UI mode updates based on this+0x0 value and global feature flags. When in mode 1, checks audio/input/UI flags to advance selected index via sub_49F170 or decrement via IndexDecrementWithBoundsWrap.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_f070 (0049f070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Current UI mode index; mode 1 triggers index advance, other modes reset to 1 |
| this | 0x4 | R | — | Secondary index used by IndexDecrementWithBoundsWrap in mode 1 |

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
| 0049f150 | FunctionCallWrapper_f150 | Stores new mode index and updates session init complete flag |
| 0049f170 | sub_49F170 | Advances cyclic index (direction=1) to next valid vehicle slot |
| 004a5750 | UtilityFunction_5750 | Utility function processing secondary index |
| 004a57a0 | IndexDecrementWithBoundsWrap | Decrements secondary index with wrap-around |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | != | 1 | Mode is not 1 — PASSES: calls FunctionCallWrapper_f150(this, *this != 1) |
| this | 0x0 | == | 1 | Mode is 1 — PASSES: checks global flags for index advance direction |

**Guard interpretation:** When dword_7CC234 (UI feature flag) is zero, entire body BLOCKED. When this+0x0 != 1, dispatch sets mode to 1 via FunctionCallWrapper_f150. When this+0x0 == 1, checks global flags: dword_7CC28C triggers sub_49F170(forward), dword_7CC2B8 triggers sub_49F170(backward), dword_7CC2E4 triggers UtilityFunction_5750, dword_7CC310 triggers IndexDecrementWithBoundsWrap — first matching flag wins.
