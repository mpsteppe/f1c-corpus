## VehicleClimbAdjust_004efa40 — VehicleClimbAdjust

**Summary:** Adjusts vehicle climb/throttle value with optional vibration noise from weather table when rigid body constraint is present. Part of vehicle suspension/climb control system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIMainUpdate (00424e70), AISteeringRacingLineCorrection (0042b0e0), sub_4A00A0 (004a00a0), sub_4C6B60 (004c6b60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32BC | R | — | Rigid body constraint pointer (validity check) |
| this | 0x3994 | RW | — | Climb/throttle value (clamped to minimum or left unchanged) |
| this | 0x399C | R | — | Minimum climb/throttle threshold |
| this | 0x39B8 | RW | — | Computed climb vibration level |
| this | 0x39BC | R | — | Climb vibration base offset |
| this | 0x39C0 | R | — | Weather noise scale factor |
| this | 0x39C4 | R | — | Weather noise add offset |

**Written-by note (persistence):**
- this 0x3994: recalc every frame — external poke does NOT persist
- this 0x39B8: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008ab274 | flt_8AB274 | R | WeatherNoiseTable [DERIVED] (also: � random noise table (docs/12) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks rigid body ptr (this+0x32BC). If zero (no rigid body), calls SuspensionVibration fallback (BLOCKED for main logic). If valid: when a2 is true, clamps climb value (this+0x3994) to minimum (this+0x399C). When a2 is false, computes vibration noise from weather table.
