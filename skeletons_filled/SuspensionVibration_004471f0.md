## SuspensionVibration_004471f0 — SuspensionVibrationUpdate

**Summary:** Updates suspension vibration state based on a vibration trigger flag (a2). In one mode, copies vibration state from source to destination. In the other mode (no trigger), computes a noise-based vibration value from a weather noise table lookup when vibration threshold is exceeded. Part of vehicle suspension vibration/feedback system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_42C440 (0042c440), Gearbox (00443b70), sub_447780 (00447780)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C59 | RW | 1 | active flag byte (set to 1 every call) |
| this | 0x1C5C | RW | — | vibration value (accumulated/destination) |
| this | 0x1C60 | RW | — | vibration rate/derivative |
| this | 0x1C84 | R | — | vibration threshold (compared against accumulator) |
| this | 0x1C88 | R | — | vibration source value |
| this | 0x1D10 | RW | — | vibration output accumulator |
| this | 0x1D18 | R | — | vibration noise scale factor |
| this | 0x1D20 | R | — | vibration offset constant |
| this | 0x1D28 | R | — | vibration addition constant |

**Written-by note (persistence):**
- this 0x1C59: recalc every frame — external poke does NOT persist
- this 0x1C5C: recalc every frame — external poke does NOT persist
- this 0x1C60: recalc every frame — external poke does NOT persist
- this 0x1D10: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008ab274 | flt_8AB274 | R | WeatherNoiseTable [DERIVED] (also: ` random noise table (docs/12) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** condition `v2 = *(double*)(this+0x1C5C) < *(double*)(this+0x1C84)` (vibration accumulator < threshold) determines which action is taken:
- If a2 (trigger) is non-zero AND vibration < threshold: copy source state (this+0x1C88) to accumulator (this+0x1C5C) and derivative (this+0x1C60).
- If a2 is zero AND vibration < threshold: compute noise-based vibration output from weather table lookup, scaled by factors at this+0x1D18, offset at this+0x1D20, and addition at this+0x1D28, storing to this+0x1D10.
- If vibration >= threshold: only set active flag, no state changes.
