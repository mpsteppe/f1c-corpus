## PitRaceStatusMessageDispatcher_0041be60 — PitRaceStatusAnnouncer

**Summary:** Dispatches pit/race status audio messages (IDs 506-513) based on sector/phase classification from a pit condition structure, with additional temperature threshold and track-grip-average modifiers.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_40DE60 (0040de60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0041c07c | jpt_41BEB4 | R | Jump table for switch on pit status classification (cases 2-5) |
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
| 004144d0 | StructInitWithSentinelValues | Initialize driver table entry struct with sentinel/default values |
| 004144f0 | DriverDataTableLookupAndTimeConversion | Populate driver data entry with message ID, timing info, and driver indices |
| 00418560 | InsertDriverTableEntry | Insert populated entry into shared driver data table |
| 004ff130 | sub_4FF130 | Query pit condition structure for current sector/phase classification (returns 2-5) |
| 004ff1d0 | AudioFilterParameterCalculation | Compute sub-status qualifier from pit condition structure |

**Guard conditions:**
1. `dword_7D0308` (RaceActiveFlag) must be non-zero → PASSES: race active. BLOCKED: race inactive.
2. `flt_7CF3C8` (TrackConditionState) must not be 0.0 → PASSES: track condition initialized. BLOCKED: track condition zero.
3. Switch on `v0` (pit status classification):
   - Case 2: `v1` must equal 2 → PASSES: message 506 (plus 507 if `flt_8AFEF0 > 30.0`). BLOCKED: v1 != 2 → fallthrough to 512.
   - Case 3: `v1` is 2 or 3 → message 509; else → message 512. No BLOCK for insertion.
   - Case 4: `v1` must be 4 or 5 → PASSES: message 510. BLOCKED: v1 not 4 or 5 → 512.
   - Case 5: `v1` is 4 or 5 → PASSES: message 511 (plus 513 if grip average > 0.7). BLOCKED: v1 not 4 or 5 → 512.
   - Default: BLOCKED: no message inserted.
