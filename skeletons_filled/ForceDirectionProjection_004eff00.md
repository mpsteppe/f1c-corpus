## ForceDirectionProjection_004eff00 — ForceDirectionProjection

**Summary:** Normalizes a force direction vector and computes negated scalar projection of another vector onto it. Returns zero if direction vector is zero. Part of physics force system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4BCCC0 (004bccc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] |
| this | 0x34C4 | R | — | Vector Y component (projected onto direction) |
| this | 0x34D0 | R | — | Vector Z component (projected onto direction) |
| this | 0x34EC | R | — | Force direction X component |
| this | 0x34F0 | R | — | RenderX [FACT] |
| this | 0x34F4 | R | — | RenderY [FACT] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks if force direction vector (this+0x34EC through +0x34F4) is all zero. PASSES (computes projection) when nonzero. BLOCKED (returns 0.0) when direction is zero.
