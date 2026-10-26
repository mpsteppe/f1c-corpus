## AIRingBufferFieldInit_00424c80 — AIRingBufferFieldInit

**Summary:** Computes an oscillating noise value from a trig lookup table indexed by a ring buffer counter, combined with baseline offset and difficulty slider scaling. Stores result in this[4370] (offset 0x4448) to add frame-to-frame variability to AI behavior.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CameraViewportFrustumInitialization (00424b20), AIMainUpdate (00424e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4448 | RW | — | AI variability field: trig noise + baseline - difficulty term |

**Written-by note (persistence):**
- this 0x4448: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: ` — display message threshold) |
| 0059e868 | flt_59E868 | R | SteeringResponseGain [DERIVED] |
| 007d01a0 | dword_7D01A0 | R | AIDifficultySlider [CONFIRMED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter — incremented each frame, used as trig lookup index |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 — 256-entry sine/cosine lookup table |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — always executes.
