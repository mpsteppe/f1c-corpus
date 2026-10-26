## PitStateSlotActivation_0041ab30 — PitStateSlotActivationTracker

**Summary:** Tracks pit state slot activation for up to 4 slots (flags at this+0xA44). Sets flag to 2 for given slot index, counts activated slots. If fewer than 3 activated, emits individual slot events (94/96/98/100). If 3+ activated, emits combined event (104). Analogue of AISessionPhaseCounter but for pit state.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleDynamicsForceAccumulatorIntegration (00438130)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA44 | RW | — | First of 4 pit-slot activation flags (slot[index] at this+0xA44 + index*4); set to 2 when slot activates |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0041ac3c | jpt_41ABBC | R | Jump table for switch on a2 (slot index 0-3 mapping to event IDs) |
| 0059e440 | flt_59E440 | R | Zero threshold constant (~0.0f) |
| 005ea618 | flt_5EA618 | R | Pointer to session event table |
| 007c56a8 | dword_7C56A8 | R | Race phase — must not be 8 (post-race) |
| 007cf3c8 | flt_7CF3C8 | R | Track condition state — must be nonzero |
| 007d0308 | dword_7D0308 | R | Race active flag — must be nonzero |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | Initializes local 8-DWORD struct with sentinel defaults |
| 004144f0 | DriverDataTableLookupAndTimeConversion | Fills local struct with event ID (94/96/98/100 per slot, or 104 for combined) |
| 00418560 | InsertDriverTableEntry | Inserts pit slot activation event into session event table |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xA44 | == | 2 | Slot activation value — each slot flag tested for == 2 (activated) during count loop |

**Guard interpretation:** dword_7D0308 (race active) nonzero, flt_7CF3C8 (track condition) != 0.0, dword_7C56A8 (race phase) != 8. The field check at this+0xA44 (and subsequent slots) tests each flag for value 2 to count activated slots — NOT an early-return guard, but determines individual vs combined event path. Default in switch (a2 out of 0-3 range) skips DriverDataTableLookupAndTimeConversion.
