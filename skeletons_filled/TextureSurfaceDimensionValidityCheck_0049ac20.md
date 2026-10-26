## TextureSurfaceDimensionValidityCheck_0049ac20 — TextureDimensionIsValid

**Summary:** Returns true only if both texture surface dimensions (height at 0x28, width at 0x2A) are positive. Used as a validity check before rendering or allocation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x28 | R | — | 16-bit height |
| this | 0x2A | R | — | 16-bit width |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x28 | > | 0 | 16-bit height |
| this | 0x2A | > | 0 | 16-bit width |

**Guard interpretation:** Only PASSES (returns true) if height > 0 AND width > 0. If either is <= 0, BLOCKED (returns false).
