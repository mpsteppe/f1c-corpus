## ClearPitSelectionFlags_0041b910 — ClearPitSelectionFlags

**Summary:** Clears three pit-selection-related flags (offsets 123-125) on a pointer-table entry when race is active, track conditions exist, race phase is not 8, and action identifier equals 5. Called per-frame from AI pit logic.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4BCCC0 (004bccc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = pit-related or end) |
| 007cf3c8 | flt_7CF3C8 | R | TrackConditionState [CONFIRMED] |
| 007d0308 | dword_7D0308 | R | RaceActiveFlag [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00418a20 | BooleanOROfTwoChecks | Sets a flag/bit at the given offset within a pointer-table entry; used here to de-select pit flags |

**Guard conditions:** Early return (skip all flag clearing) if: dword_7D0308 == 0 (race not active), OR flt_7CF3C8 == 0.0 (track condition invalid/missing), OR dword_7C56A8 == 8 (race phase is 8, pit-related or end phase), OR a1 != 5 (action identifier not 5). Flag clearing only executes when ALL conditions are true.
