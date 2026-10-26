## TransformOffsetSetup_0050d9a5 — Transform offset setup — build 4×4 affine matrix with optional offset handling

**Summary:** Builds a 4×4 transformation matrix with scale `a2` on diagonal and identity-like off-diagonal zeros. Optionally applies offset vector `a3` (subtract before transform, add back after) and/or additive offset `a5` to the translation row.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Matrix row0 col0 — scale X component |
| this | 0x4 | RW | — | Matrix row1 col0 — XY shear (zeroed) |
| this | 0x8 | RW | — | Matrix row2 col0 — XZ shear (zeroed) |
| this | 0xC | RW | — | Matrix row3 col0 — homogeneous column 0 (zeroed) |
| this | 0x10 | RW | — | Matrix row0 col1 — XY shear (zeroed) |
| this | 0x14 | RW | — | Matrix row1 col1 — scale Y component |
| this | 0x18 | RW | — | Matrix row2 col1 — YZ shear (zeroed) |
| this | 0x1C | RW | — | Matrix row3 col1 — homogeneous column 1 (zeroed) |
| this | 0x20 | RW | — | Matrix row0 col2 — XZ shear (zeroed) |
| this | 0x24 | RW | — | Matrix row1 col2 — YZ shear (zeroed) |
| this | 0x28 | RW | — | Matrix row2 col2 — scale Z component |
| this | 0x2C | RW | — | Matrix row3 col2 — homogeneous column 2 (zeroed) |
| this | 0x30 | RW | — | Matrix row0 col3 — translation X |
| this | 0x34 | RW | — | Matrix row1 col3 — translation Y |
| this | 0x38 | RW | — | Matrix row2 col3 — translation Z |
| this | 0x3C | RW | — | Matrix row3 col3 — homogeneous w (set to 1.0) |

**Written-by note (persistence):**
- this 0x0: unconditional write (a2) every call — external poke does not survive
- this 0x4: unconditional write (0.0) every call — external poke does not survive
- this 0x8: unconditional write (0.0) every call — external poke does not survive
- this 0xC: unconditional write (0.0) every call — external poke does not survive
- this 0x10: unconditional write (0.0) every call — external poke does not survive
- this 0x14: unconditional write (a2) every call — external poke does not survive
- this 0x18: unconditional write (0.0) every call — external poke does not survive
- this 0x1C: unconditional write (0.0) every call — external poke does not survive
- this 0x20: unconditional write (0.0) every call — external poke does not survive
- this 0x24: unconditional write (0.0) every call — external poke does not survive
- this 0x28: unconditional write (a2) every call — external poke does not survive
- this 0x2C: unconditional write (0.0) every call — external poke does not survive
- this 0x30: unconditional write (0.0) every call, then conditionally modified by a3/a5 — external poke does not survive
- this 0x34: unconditional write (0.0) every call, then conditionally modified by a3/a5 — external poke does not survive
- this 0x38: unconditional write (0.0) every call, then conditionally modified by a3/a5 — external poke does not survive
- this 0x3C: unconditional write (1.0) every call — external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050cbb0 | ThunkToFUN0050cba3 | Perform intermediate transform operation between offset subtraction and re-addition |
| 0050d857 | ThunkToIndirectCallViaDAT005d7860 | Unknown indirect call invoked when a4 is set, before offset handling |

**Guard conditions:** If `a4` is zero, the entire offset-transform branch (ThunkToIndirectCallViaDAT005d7860 and a3 handling) is skipped. If `a4` is nonzero but `a3` is NULL, only ThunkToFUN0050cba3 is called without offset adjustment. If `a5` is NULL, the final additive translation is skipped.
