## VehicleDynamics_00423b10 — RelativeSpeedComputation

**Summary:** Computes relative speed between two vehicles for AI steering. Two branches controlled by flag a4: when true computes longitudinal (closing) speed via dot product (stores result in this[9] and this[12]); when false computes lateral speed via 2D cross product (stores only in this[9]). Called per-frame from AISteering.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AISteering (004270a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x34E0 | R | — | target vehicle X position offset from this[0] dereference |
| obj | 0x34E8 | R | — | target vehicle Y position |
| obj | 0x34F8 | R | — | target vehicle X component of velocity/force |
| obj | 0x3500 | R | — | target vehicle Y component of velocity/force |
| this | 0x0 | R | — | indirection pointer to target vehicle object (dereferenced to access obj fields) |
| this | 0x24 | RW | — | signed relative speed result (longitudinal or lateral) |
| this | 0x30 | RW | — | normalized relative speed along direction (longitudinal branch only) |

**Written-by note (persistence):**
- this 0x24: recalc every frame — external poke does NOT persist
- this 0x30: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — both branches execute based on a4 flag. No early return path.
