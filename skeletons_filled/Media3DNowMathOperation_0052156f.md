## Media3DNowMathOperation_0052156f — 3DNow! parameterized media rotation/transform from lookup

**Summary:** Looks up a 12-byte entry (v7 + v8) from sub_5262C2 using index a2, scales input float a3 by 0.5 via 3DNow!, calls PackedFloatingPointMath for component expansion, then multiplies lookup entries with scaled components to produce output quaternion/vector in a1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | First half of output (xy of interpolated result) |
| this | 0x8 | R | — | Second half of output (zw of interpolated result) |

**Written-by note (persistence):**
- this 0x0: Written once at function end; purely output, no persistence.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af990 | qword_5AF990 | R | MMX_3DNow_QuadConstant_0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005262c2 | sub_5262C2 | Lookup table query: fills v7/v8 from index a2 (12 bytes of precomputed transform data) |
| 005295e0 | PackedFloatingPointMath | Component setup/expansion for 3DNow! arithmetic |

**Guard conditions:** None — no conditional branches; always executes full path.
