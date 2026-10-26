## PositionIndexClamp_0042e290 — PositionIndexClamp

**Summary:** Maps a normalized double (0.0-1.0) to a clamped integer array index, with split at 0.5 for symmetrical (e.g., left/right) indexing. Used by pressure/force field mapping.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PressureForceFieldMapping (004313c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | Total range count (upper bound - 1) |
| this | 0x14 | RW | 0 | Computed output index, clamped to [0, total-1] |
| this | 0x18 | R | — | Midpoint offset dividing the range (split point) |

**Written-by note (persistence):**
- this 0x14: Overwritten each call with newly computed clamped index.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Guard: a2 < 0.5 → first half mapping (index = count * a2*2). a2 >= 0.5 → second half mapping (index = (total - midpoint - 1) * (a2*2 - 1) + midpoint). Final clamp: index < 0 → set to 0; index > total-1 → set to total-1.
