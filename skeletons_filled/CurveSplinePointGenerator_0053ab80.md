## CurveSplinePointGenerator_0053ab80 — Spline curve table generator

**Summary:** Generates normalized spline curve values into a lookup table. For each step from 1 to size (this[0]), computes normalized position t = i/size, calls curve function sub_5881F0, stores float value and delta-difference in buffer at this[3]. Final entry is set to 1.0. Used for audio envelope/volume curve generation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SoundBufferAllocator (0053ab20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | table entry count / size (this[0]), loop bound |
| this | 0x8 | RW | — | parameter a2 stored at this[2] |
| this | 0xC | RW | 0 | buffer pointer at this[3], first two words initialized to 0 |
| this | 0x10 | RW | 0 | first float value in buffer (at this[3]+0), set to 0 |

**Written-by note (persistence):**
- this 0x8: written once by constructor call
- this 0xC: buffer contents filled with scale/delta float pairs
- this 0x10: overwritten on each generation

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (BaseDoubleConstant = 1.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005881f0 | sub_5881F0 | curve/spline evaluation function (applied to normalized position t) |

**Guard conditions:** Buffer at this[3] must be non-null; otherwise entire generation is skipped. Loop runs from v4=1 to v4 < this[0], computing t = v4/this[0] for each step.
