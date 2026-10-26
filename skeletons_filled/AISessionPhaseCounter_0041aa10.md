## AISessionPhaseCounter_0041aa10 — SessionPhaseCompletionTracker

**Summary:** Tracks completion of up to 4 session phases per driver using flags at this+0xA44. Counts active flags; if fewer than 3 are set, emits an individual phase-event (95/97/99/101) based on phase index. If 3+ flags set, emits a combined event (105). Part of AI session event pipeline.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleDynamicsForceAccumulatorIntegration (00438130)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA44 | RW | — | First of 4 phase-completion flags (flag[index] at this+0xA44 + index*4); set to 1 when phase completes |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0041ab1c | jpt_41AA9C | R | Jump table for switch on a2 (phase index 0-3 mapping to event IDs) |
| 0059e440 | flt_59E440 | R | Zero threshold constant (~0.0f) |
| 005ea618 | flt_5EA618 | R | Pointer to session event table |
| 007c56a8 | dword_7C56A8 | R | Race phase — must not be 8 (post-race) |
| 007cf3c8 | flt_7CF3C8 | R | Track condition state — must be nonzero |
| 007d0308 | dword_7D0308 | R | Race active flag — must be nonzero |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | Initializes local 8-DWORD struct with sentinel defaults |
| 004144f0 | DriverDataTableLookupAndTimeConversion | Fills local struct with event ID (95/97/99/101 per phase, or 105 for combined) |
| 00418560 | InsertDriverTableEntry | Inserts phase completion event into session event table |

**Guard conditions:** dword_7D0308 (race active) nonzero, flt_7CF3C8 (track condition) != 0.0, dword_7C56A8 (race phase) != 8. If fewer than 3 phase flags are set, a2 must be 0-3 to emit individual event; default (a2 out of range) skips DriverDataTableLookupAndTimeConversion and inserts sentinel-only entry. If 3+ flags set, emits combined event 105 regardless of a2.
