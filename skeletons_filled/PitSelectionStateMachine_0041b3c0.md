## PitSelectionStateMachine_0041b3c0 — PitSelectionStateMachine

**Summary:** Complex state machine managing pit selection commentary events. Handles multiple states (0/2/3/5): deactivation with zone-aware dispatch, activation with zone-comparison logic, generic event 131, and player pit entry sub-types (123-125). Uses FloatRangeIndexLookup for zone indexing and StateCheckedVirtualDispatch for gated transitions. Part of AI race commentary system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4BCCC0 (004bccc0), sub_4D1730 (004d1730)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0041b8f0 | jpt_41B47F | R | Jump table for state switch (a2 = 0, 2, 3, 5) |
| 0059e440 | flt_59E440 | R | Zero threshold constant (~0.0f) |
| 0059e824 | flt_59E824 | R | AI dynamics threshold constant |
| 0059e828 | flt_59E828 | R | Float 1.0 constant |
| 005ea3fc | flt_5EA3FC | R | Track reference speed / waypoint accumulation weight — used to clamp a4 |
| 005ea618 | flt_5EA618 | R | Pointer to session event table (also used as context for StateCheckedVirtualDispatch) |
| 007c54e8 | dword_7C54E8 | R | Player vehicle pointer — used for zone projection and pit entry vehicle check |
| 007c56a4 | dword_7C56A4 | R | Session type — checked != 7 for specific state paths |
| 007c56a8 | dword_7C56A8 | R | Race phase — must not be 8 (post-race) |
| 007cf3c8 | flt_7CF3C8 | R | Track condition state — must be nonzero |
| 007d0308 | dword_7D0308 | R | Race active flag — must be nonzero |
| 008acee0 | dword_8ACEE0 | R | Force feedback base (unreferenced directly) |
| 008ad264 | dword_8AD264 | R | Penalty message queue (unreferenced directly) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | Initializes local 8-DWORD struct for event entry |
| 004144f0 | DriverDataTableLookupAndTimeConversion | Fills local struct with pit event code and computed time |
| 00418560 | InsertDriverTableEntry | Inserts pit event into session event table |
| 004189b0 | StateCheckedVirtualDispatch | Gated virtual dispatch for state transitions (events 134, 136, 138) |
| 004189f0 | ArraySearchReturningIndex | Searches and clears existing entries for given event IDs |
| 00418a20 | BooleanOROfTwoChecks | Fires Boolean OR checks for related pit events |
| 004d1ad0 | ScoringGateSelector | Returns gate value for zone-based state transitions |
| 004d7c10 | FloatRangeIndexLookup | Converts float to zone index (v7 = speed zone, v8 = player position zone) |
| 004d7cf0 | FloatWrapTableInterpolation | Interpolates float value with wrap table for zone comparison |
| 004f0050 | DistanceProjectionCalc | Computes distance projection for player vehicle position |

**Guard conditions:** dword_7D0308 (race active) nonzero, flt_7CF3C8 (track condition) != 0.0, byte at player vehicle + 13388 must be 0, dword_7C56A8 (race phase) != 8. a4 clamped to [0, flt_5EA3FC]. Each state case (0, 2, 3, 5) has internal sub-guards: case 0 checks this[v7+316] flag, ScoringGateSelector, and StateCheckedVirtualDispatch results; case 2 checks zone equality (v8==v7) and sub-zone conditions; case 5 only proceeds if player vehicle matches a5 and a6 is 1-3. Final insertion guard: event ID field must not be -1 (sentinel).
