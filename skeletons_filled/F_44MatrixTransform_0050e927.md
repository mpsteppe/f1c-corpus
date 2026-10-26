## F_44MatrixTransform_0050e927 — 3D point transform by 4×4 matrix with perspective divide

**Summary:** Transforms 3D point `a2` by 4×4 column-major matrix `a3` to produce output point `a1`. Computes homogeneous (x,y,z,w), then optionally perspective-divides by w if w is not approximately 1.0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output point X (post-transform, optionally perspective-divided) |
| this | 0x4 | RW | — | Output point Y (post-transform, optionally perspective-divided) |
| this | 0x8 | RW | — | Output point Z (post-transform, optionally perspective-divided) |

**Written-by note (persistence):**
- this 0x0: unconditional write every call — external poke does not survive
- this 0x4: unconditional write every call — external poke does not survive
- this 0x8: unconditional write every call — external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050c042 | FloatRangeCheck | Checks if homogeneous w is approximately 1.0 to skip perspective divide |

**Guard conditions:** If `FloatRangeCheck(w, 1.0)` returns true (w ≈ 1.0), the (x,y,z) values are written verbatim without perspective correction. Otherwise each component is divided by w for proper projective mapping.
