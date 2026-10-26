## RotatingIndexSearchWithThreshold_0045b500 — RotatingIndexSearchWithThreshold

**Summary:** Searches an 8-entry circular buffer for an available slot: first tries rotating scan for entry with lifetime/damage field <= 0, then falls back to finding the entry with minimum comparison value. Returns -1 if the best candidate's threshold exceeds caller's limit a2. Part of event/damage buffer management.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** UtilityFunction_b9c0 (0045b9c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xF0 | R | — | Comparison field base offset (this[60], start of 8-entry scan array with stride 23 DWORDs) |
| this | 0x31C | R | — | Circular buffer write cursor (starting index for rotating scan) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Rotating scan: PASS (return index) if entry's lifetime/flag field (float at 23*index + 36) <= 0.0. Fallback scan: finds minimum comparison value across 8 entries. If a2 (threshold limit) > entry threshold field (int at 23*result + 37), return -1 (block).
