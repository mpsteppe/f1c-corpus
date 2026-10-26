## TwoOutputPassthrough_004dd3a0 — Query text surface dimensions with font fallback

**Summary:** Queries rendered text surface dimensions (width, height) for a given string and scale via SurfaceSizeQuery; uses font from this+0x28 or global fallback byte_5EA438 if a7 is null; returns width/height via output pointers.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NormalizedCoordinateCalculator (004dd400)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x28 | R | — | Font/device string pointer (fallback for a7) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Default font/path buffer fallback |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dc600 | SurfaceSizeQuery | Query rendered text surface dimensions for given font and scale |

**Guard conditions:** Three independent null checks: (1) `a7` (font) — if null, substitute from this+0x28 then byte_5EA438; (2) `a5` (width output ptr) — if null, skip writing width; (3) `a6` (height output ptr) — if null, skip writing height.
