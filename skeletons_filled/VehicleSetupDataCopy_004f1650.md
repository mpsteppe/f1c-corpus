## VehicleSetupDataCopy_004f1650 — Vehicle Setup Data Copy & Render Transform

**Summary:** Copies vehicle setup data (position, velocity, orientation matrix) from multiple source buffers into this object, then performs 3x3 matrix-vector multiplications to compute transformed render coordinates. Vehicle physics / rendering system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsTimeStep (004c73f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34B0 | R | — | orientation matrix element [0][0] (from a4 memcpy block) |
| this | 0x34B4 | R | — | orientation matrix element [0][1] (from a4 memcpy block) |
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] |
| this | 0x34BC | R | — | orientation matrix element [1][0] (from a4 memcpy block) |
| this | 0x34C0 | R | — | orientation matrix element [1][1] (from a4 memcpy block) |
| this | 0x34C4 | R | — | orientation matrix element [1][2] (from a4 memcpy block) |
| this | 0x34C8 | R | — | orientation matrix element [2][0] (from a4 memcpy block) |
| this | 0x34CC | R | — | orientation matrix element [2][1] (from a4 memcpy block) |
| this | 0x34D0 | R | — | orientation matrix element [2][2] (from a4 memcpy block) |
| this | 0x34D4 | RW | — | source vector a2 component X (position offset) |
| this | 0x34D8 | RW | — | source vector a2 component Y |
| this | 0x34DC | RW | — | source vector a2 component Z |
| this | 0x34E0 | RW | — | source vector a3 component X (velocity/force) |
| this | 0x34E4 | RW | — | source vector a3 component Y |
| this | 0x34E8 | RW | — | source vector a3 component Z |
| this | 0x34EC | RW | — | source vector a5 component X |
| this | 0x34F0 | RW | — | RenderX [FACT] |
| this | 0x34F4 | RW | — | RenderY [FACT] |
| this | 0x34F8 | RW | — | RenderZ [FACT] |
| this | 0x34FC | RW | — | transformed vector result (matrix × a5) component Y |
| this | 0x3500 | RW | — | transformed vector result (matrix × a5) component Z |
| this | 0x3504 | RW | — | source vector a6 component X |
| this | 0x3508 | RW | — | source vector a6 component Y |
| this | 0x350C | RW | — | source vector a6 component Z |
| this | 0x3534 | RW | — | source vector a7 component X |
| this | 0x3538 | RW | — | source vector a7 component Y |
| this | 0x353C | RW | — | source vector a7 component Z |
| this | 0x3540 | RW | — | transformed vector result (matrix × a7) component X |
| this | 0x3544 | RW | — | transformed vector result (matrix × a7) component Y |
| this | 0x3548 | RW | — | transformed vector result (matrix × a7) component Z |
| this | 0x39F0 | RW | — | data flag / index value (from parameter a8) |

**Written-by note (persistence):**
- this 0x34D4: recalc every frame — external poke does NOT persist
- this 0x34D8: recalc every frame — external poke does NOT persist
- this 0x34DC: recalc every frame — external poke does NOT persist
- this 0x34E0: recalc every frame — external poke does NOT persist
- this 0x34E4: recalc every frame — external poke does NOT persist
- this 0x34E8: recalc every frame — external poke does NOT persist
- this 0x34EC: recalc every frame — external poke does NOT persist
- this 0x34F0: recalc every frame — external poke does NOT persist
- this 0x34F4: recalc every frame — external poke does NOT persist
- this 0x34F8: recalc every frame — external poke does NOT persist
- this 0x34FC: recalc every frame — external poke does NOT persist
- this 0x3500: recalc every frame — external poke does NOT persist
- this 0x3504: recalc every frame — external poke does NOT persist
- this 0x3508: recalc every frame — external poke does NOT persist
- this 0x350C: recalc every frame — external poke does NOT persist
- this 0x3534: recalc every frame — external poke does NOT persist
- this 0x3538: recalc every frame — external poke does NOT persist
- this 0x353C: recalc every frame — external poke does NOT persist
- this 0x3540: recalc every frame — external poke does NOT persist
- this 0x3544: recalc every frame — external poke does NOT persist
- this 0x3548: recalc every frame — external poke does NOT persist
- this 0x39F0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — function copies data and computes transforms unconditionally every call. No branching on input values.
