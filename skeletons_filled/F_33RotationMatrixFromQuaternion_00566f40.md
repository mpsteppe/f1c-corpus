## F_33RotationMatrixFromQuaternion_00566f40 — QuaternionToRotationMatrix

**Summary:** Converts a unit quaternion (a1[0]=w, a1[1]=x, a1[2]=y, a1[3]=z) to a 3x3 row-major rotation matrix (a2[0..8]). Standard quaternion-to-matrix formula with no branching.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_567010 (00567010)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | output matrix row 0 column 0 |
| this | 0x4 | RW | — | output matrix row 0 column 1 |
| this | 0x8 | RW | — | output matrix row 0 column 2 |
| this | 0xC | RW | — | output matrix row 1 column 0 |
| this | 0x10 | RW | — | output matrix row 1 column 1 |
| this | 0x14 | RW | — | output matrix row 1 column 2 |
| this | 0x18 | RW | — | output matrix row 2 column 0 |
| this | 0x1C | RW | — | output matrix row 2 column 1 |
| this | 0x20 | RW | — | output matrix row 2 column 2 |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x4: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x18: recalc every frame — external poke does NOT persist
- this 0x1C: recalc every frame — external poke does NOT persist
- this 0x20: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — pure computation with no branches or early returns.
