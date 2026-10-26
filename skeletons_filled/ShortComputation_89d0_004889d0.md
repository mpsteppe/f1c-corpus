## ShortComputation_89d0_004889d0 — ScrollProgressFraction

**Summary:** Computes a scroll progress ratio: if (max - min) <= 0 returns 0.0, otherwise returns (stored offset at 0xE0) / (max - min) as a double. Used as normalized scroll position.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TimerBasedFloatDispatch (0047ca30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x18 | R | — | Virtual +24 — min position value |
| obj | 0x20 | R | — | Virtual +32 — max position value |
| this | 0x0 | R | — | Vtable pointer for virtual dispatch |
| this | 0xE0 | R | — | Stored scroll offset (numerator) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If (max - min) <= 0.0, returns 0.0 (blocked). Only when range is positive does it compute the fraction.
