## UtilityFunction_2480_004b2480 — Float vector to int16 pack (scale 50)

**Summary:** Converts 3 float values to int16 by clamping to [-655.34, 655.34] range and scaling by 50.0. Packs vertex/vector data into compact int16 format. Inverse of ShortVectorToFloatWithScale.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleOrientationFromEulerAngles (004b2dd0), sub_4B32A0 (004b32a0), SetupCarLightingAndRender (004c71c0), VehicleContactForceAccumulation (004ebc60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1E | RW | — | Packed float 0 → int16 (scaled * 50, clamped ±32767) |
| this | 0x20 | RW | — | Packed float 1 → int16 (scaled * 50, clamped ±32767) |
| this | 0x22 | RW | 32767 | Packed float 2 → int16 (scaled * 50, clamped ±32767) |

**Written-by note (persistence):**
- this 0x1E: recalc every frame — external poke does NOT persist
- this 0x20: recalc every frame — external poke does NOT persist
- this 0x22: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e828 | flt_59E828 | R | FloatOneConstant [DERIVED] (also: ` — float 1.0 constant) |
| 005acc98 | flt_5ACC98 | R | FloatToShortClampMin [DERIVED] |
| 005acc9c | flt_5ACC9C | R | FloatClampHigh [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Float input values clamped to [-655.34003, 655.34003] before scaling — out-of-range values saturated to ±32767.
