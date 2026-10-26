## SkeletonBoneTransformConstruction_0050ee0b — Skeleton bone 4×4 transform matrix construction

**Summary:** Builds a 4×4 transformation matrix for a skeleton bone, with support for root/child bone modes (via `a3`), offset vector (`a2`), parent transform (`a4`), and additive translation offsets (`a5`/`a7`). Handles identity initialization, diagonal scale from parent, and negative offset for child bones.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Matrix row0 col0 (scale X — set to 1.0 or from a4) |
| this | 0x4 | RW | — | Matrix row1 col0 (XY shear, zeroed) |
| this | 0x8 | RW | — | Matrix row2 col0 (XZ shear, zeroed) |
| this | 0xC | RW | — | Matrix row3 col0 (homogeneous column 0, zeroed) |
| this | 0x10 | RW | — | Matrix row0 col1 (XY shear, zeroed) |
| this | 0x14 | RW | — | Matrix row1 col1 (scale Y — set to 1.0 or from a4) |
| this | 0x18 | RW | — | Matrix row2 col1 (YZ shear, zeroed) |
| this | 0x1C | RW | — | Matrix row3 col1 (homogeneous column 1, zeroed) |
| this | 0x20 | RW | — | Matrix row0 col2 (XZ shear, zeroed) |
| this | 0x24 | RW | — | Matrix row1 col2 (YZ shear, zeroed) |
| this | 0x28 | RW | — | Matrix row2 col2 (scale Z — set to 1.0 or from a4) |
| this | 0x2C | RW | — | Matrix row3 col2 (homogeneous column 2, zeroed) |
| this | 0x30 | RW | — | Matrix row0 col3 (translation X — set from a2 negated, then adjusted by a5/a7) |
| this | 0x34 | RW | — | Matrix row1 col3 (translation Y) |
| this | 0x38 | RW | — | Matrix row2 col3 (translation Z) |
| this | 0x3C | RW | — | Matrix row3 col3 (homogeneous w — set to 1.0) |

**Written-by note (persistence):**
- this 0x0: unconditional write (1.0 or from a4) — external poke does not survive
- this 0x4: unconditional write (0.0) — external poke does not survive
- this 0x8: unconditional write (0.0) — external poke does not survive
- this 0xC: unconditional write (0.0) — external poke does not survive
- this 0x10: unconditional write (0.0) — external poke does not survive
- this 0x14: unconditional write (1.0 or from a4) — external poke does not survive
- this 0x18: unconditional write (0.0) — external poke does not survive
- this 0x1C: unconditional write (0.0) — external poke does not survive
- this 0x20: unconditional write (0.0) — external poke does not survive
- this 0x24: unconditional write (0.0) — external poke does not survive
- this 0x28: unconditional write (1.0 or from a4) — external poke does not survive
- this 0x2C: unconditional write (0.0) — external poke does not survive
- this 0x30: conditional write (set from a2 negation, then potentially adjusted by a5/a7) — external poke does not survive
- this 0x34: conditional write — external poke does not survive
- this 0x38: conditional write — external poke does not survive
- this 0x3C: unconditional write (1.0) — external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050cbb0 | ThunkToFUN0050cba3 | Transform thunk called 2-3 times in child-bone path; once in offset-adjust path |
| 0050cdf9 | ThunkViaGlobalFunctionPointer | Called in child-bone path via global function pointer |
| 0050d857 | ThunkToIndirectCallViaDAT005d7860 | Called when a3 or a6 is set (indirect call for transform setup) |

**Guard conditions:** If `a4` is null, matrix is set to identity (1.0 diagonal, zeros elsewhere). If `a4` is non-null but `a3` is zero, matrix diagonal is copied from `a4`. If `a4` and `a3` are both set (child bone), translation is set to negated `a2`, thunks are called, then translation restored. If `a6` is set, additional offset adjustment via ThunkToIndirectCallViaDAT005d7860 is performed with `a5` as offset. If `a7` is non-null, its vector is added to the final translation.
