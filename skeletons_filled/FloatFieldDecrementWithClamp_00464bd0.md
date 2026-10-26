## FloatFieldDecrementWithClamp_00464bd0 — Decrement with clamp to [0, max]

**Summary:** Subtracts a2 from float field this[26], clamps result to range [0, a2]. If negative, set to 0; if above a2, set to a2.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** EntityVisibilityGridManager (00465460)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x68 | RW | — | Float field decremented by a2 and clamped to [0, a2] |

**Written-by note (persistence):**
- this 0x68: unconditionally modified each call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always decrements and clamps.
