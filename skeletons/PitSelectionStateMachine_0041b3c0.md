## PitSelectionStateMachine_0041b3c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4BCCC0 (004bccc0), sub_4D1730 (004d1730)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0041b8f0 | jpt_41B47F | R | [LLM] |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e824 | flt_59E824 | R | AIDynamicsThreshold [DERIVED] |
| 0059e828 | flt_59E828 | R | FloatOneConstant [DERIVED] (also: ` — float 1.0 constant) |
| 005ea3fc | flt_5EA3FC | R | TrackRefSpeed [DERIVED] (also: ` â€” waypoint accumulation weight) |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = ?) |
| 007cf3c8 | flt_7CF3C8 | R | TrackConditionState [CONFIRMED] |
| 007d0308 | dword_7D0308 | R | RaceActiveFlag [FACT] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |
| 008ad264 | dword_8AD264 | R | PenaltyMessageQueue [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | [LLM] |
| 004144f0 | DriverDataTableLookupAndTimeConversion | [LLM] |
| 00418560 | InsertDriverTableEntry | [LLM] |
| 004189b0 | StateCheckedVirtualDispatch | [LLM] |
| 004189f0 | ArraySearchReturningIndex | [LLM] |
| 00418a20 | BooleanOROfTwoChecks | [LLM] |
| 004d1ad0 | ScoringGateSelector | [LLM] |
| 004d7c10 | FloatRangeIndexLookup | [LLM] |
| 004d7cf0 | FloatWrapTableInterpolation | [LLM] |
| 004f0050 | DistanceProjectionCalc | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
