## RacePhasePitEntryTrigger_00429eb0 — RacePhasePitEntryTrigger

**Summary:** Forces AI pit entry when fuel multiplier drops below 1, the pit-requested flag (this[0x4550]) is clear, and race phase is 5 (pit window). Calls FuelMultiplierValue and conditionally ForcePitExit.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIAbility (00429470)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4550 | R | — | pit-requested flag — if non-zero, pit has already been requested; skip |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (5 = pit window) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ad20 | FuelMultiplierValue | returns fuel level multiplier; values below 1 signal low fuel |

**Guard conditions:** BLOCKED (early return) if FuelMultiplierValue >= 1 (fuel OK), OR this[0x4550] non-zero (pit already requested), OR race phase != 5 (not in pit window). Pit forced only when all conditions align: fuel low, pit not yet requested, and phase is 5.
