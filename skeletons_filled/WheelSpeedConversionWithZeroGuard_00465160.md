## WheelSpeedConversionWithZeroGuard_00465160 — Wheel speed conversion with zero guard

**Summary:** Converts two speed inputs (a2, a3) to wheel speed units (1000*x/8) and stores to offsets +0x50 and +0x54, guarded against zero/negative values.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionTypeSetter (00463f70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x50 | RW | — | First wheel speed value (result of 1000*a2/8) |
| obj | 0x54 | RW | — | Second wheel speed value (result of 1000*a3/8) |
| this | 0x0 | R | — | Pointer to object (dereferenced for base address) |

**Written-by note (persistence):**
- obj 0x50: overwritten only when a2 > 0
- obj 0x54: overwritten only when a3 > 0

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks if a2 > 0 (as double). If true, stores converted value to offset +0x50 (PASSES). If a2 <= 0, skips (BLOCKED). Same for a3 to offset +0x54.
