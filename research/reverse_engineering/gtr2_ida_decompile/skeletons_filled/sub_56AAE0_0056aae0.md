## sub_56AAE0_0056aae0 — Seed update records, then trigger full refresh

**Summary:** Bulk initializer for the structure owned by sub_56A0D0: copies a caller-supplied array (a2, stride 90 dwords) into the object in 36-byte blocks, stamping the double constant dbl_FB1D18 between blocks over two passes, copies a2[0] into this+0x18, sets this+0 = dbl_FB1D18 - 1.0, then calls sub_56A0D0 with scalar dbl_FB1D18 and index -1 to run a full update. Runs only at setup (no static callers), so it is an initialization/refresh entry point.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | time/threshold field: first set to dbl_FB1D18 - 1.0, then overwritten by sub_56A0D0, which stores its scalar argument there |
| this | 0x18 | RW | — | dword copied from a2[0] (source state value carried into the object) |
| this | 0x20 | RW | — | block boundary inside the destination region: 8-byte store of dbl_FB1D18 (next to a 36-byte copied block) |
| this | 0x44 | RW | — | block boundary: store of dbl_FB1D18 (one 36-byte record after 0x20) |
| this | 0x68 | RW | — | block boundary: store of dbl_FB1D18 |
| this | 0x8C | RW | — | block boundary: store of dbl_FB1D18 |
| this | 0xB0 | RW | — | block boundary: store of dbl_FB1D18 |
| this | 0xD4 | RW | — | block boundary: store of dbl_FB1D18 |
| this | 0xF8 | RW | — | block boundary: store of dbl_FB1D18 |
| this | 0x11C | RW | — | block boundary: store of dbl_FB1D18 |
| this | 0x140 | RW | — | block boundary: store of dbl_FB1D18 |
| this | 0x164 | RW | — | block boundary: store of dbl_FB1D18 (last stamped slot) |

**Written-by note (persistence):**
- this 0x0: written on every call (dbl_FB1D18 - 1.0, then the update call stores its argument); recalculation happens at each invocation, so an external poke would not survive a later call.
- this 0x18: written unconditionally from a2[0] on every call.
- this 0x20: written on every call with the same constant; part of a fixed initialization pattern.
- this 0x44: written on every call with the same constant.
- this 0x68: written on every call with the same constant.
- this 0x8C: written on every call with the same constant.
- this 0xB0: written on every call with the same constant.
- this 0xD4: written on every call with the same constant.
- this 0xF8: written on every call with the same constant.
- this 0x11C: written on every call with the same constant.
- this 0x140: written on every call with the same constant.
- this 0x164: written on every call with the same constant.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16b8 | flt_6F16B8 | R | float constant used by the initialization pattern (its exact role is inside the compiled math; not textually separable in the listing) |
| 00fb1d18 | dbl_FB1D18 | R | double sentinel stamped between the copied blocks at every 36-byte boundary, and passed as the scalar argument to sub_56A0D0 (with *this set one less, forcing the automatic-index path there) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0056a0d0 | sub_56A0D0 | performs the actual state/point update after initialization; here called with the dbl_FB1D18 scalar and index -1 (auto-select the record) |

**Guard conditions:** None on entry — no reads of existing state are tested. A fixed two-iteration loop (v4 = 2, decremented until zero) runs the copy/stamp pattern 18 times total; then this[0] = dbl_FB1D18 - 1.0 and the tail call to sub_56A0D0(this, dbl_FB1D18, -1) always executes. The `-1` argument makes the callee pick the start index itself rather than a caller-supplied one.
