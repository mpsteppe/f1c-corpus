## TrackParameterMinimumClamp_0042a740 — TrackParameterMinimumClamp

**Summary:** Clamps a track/steering parameter at this[0x4484] into [5.0, a2] range. If current value exceeds a2, clamps down; if below 5.0, clamps up. Used by AI steering subsystems to limit track correction values.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AISteeringCorrection (00426cf0), AISteering (004270a0), AISteeringRacingLineCorrection (0042b0e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4484 | RW | — | track/steering parameter value clamped to [5.0, a2] |

**Written-by note (persistence):**
- this 0x4484: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard at function level. Two conditional clamps: if value > a2, reduce to a2; if value < 5.0, raise to 5.0.
