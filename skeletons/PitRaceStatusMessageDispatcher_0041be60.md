## PitRaceStatusMessageDispatcher_0041be60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_40DE60 (0040de60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0041c07c | jpt_41BEB4 | R | [LLM] |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e468 | flt_59E468 | R | BrakingZoneSpeedThreshold2 [DERIVED] |
| 0059e830 | dbl_59E830 | R | TempWarningThreshold [DERIVED] (also: ` — dot product comparison threshold) |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 007cf3c8 | flt_7CF3C8 | R | TrackConditionState [CONFIRMED] |
| 007d0308 | dword_7D0308 | R | RaceActiveFlag [FACT] |
| 008afec0 | unk_8AFEC0 | R | Unknown_Setup_FEC0 [DERIVED] |
| 008afee8 | flt_8AFEE8 | R | TrackGripBase [DERIVED] |
| 008afeec | flt_8AFEEC | R | TrackGripComparison [DERIVED] (also: ` — additive globals) |
| 008afef0 | flt_8AFEF0 | R | TemperatureOffset [CONFIRMED] (also: GlobalForceReference, ` — global force/torque reference) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | [LLM] |
| 004144f0 | DriverDataTableLookupAndTimeConversion | [LLM] |
| 00418560 | InsertDriverTableEntry | [LLM] |
| 004ff130 | sub_4FF130 | [LLM] |
| 004ff1d0 | AudioFilterParameterCalculation | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
