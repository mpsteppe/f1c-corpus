## ConstraintForceSolver_0043ba20 — Constraint force solver with velocity computation

**Summary:** Searches constraint element array for matching body pair, computes constraint force with velocity-dependent terms using matrix-vector transforms, then computes relative velocity. Part of the constraint force solving system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SolverDispatch (0043b930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x15C8) | 0x4 | R | — | First body identifier in constraint pair |
| *(this+0x15C8) | 0x8 | R | — | Pointer to constraint data array |
| *(this+0x15C8) | 0xC | R | — | Second body identifier in constraint pair |
| *(this+0x15C8) | 0x10 | R | — | Body matching ID |
| *(this+0x15C8) | 0x18 | RW | — | Computed constraint force component (output) |
| *(this+0x15C8) | 0x20 | R | — | Constraint force initial/previous value |
| *(this+0x15C8) | 0x28 | RW | — | Computed constraint force component (output) |
| *(this+0x15C8) | 0x30 | RW | — | Computed constraint force component (output) |
| *(this+0x15C8) | 0x38 | RW | — | Computed constraint force component (output) |
| *(this+0x15F0) | 0x1C | R | — | Body rotation matrix row 0, col 0 |
| *(this+0x15F0) | 0x24 | R | — | Body rotation matrix row 0, col 1 |
| *(this+0x15F0) | 0x2C | R | — | Body rotation matrix row 0, col 2 |
| *(this+0x15F0) | 0x34 | R | — | Body rotation matrix row 1, col 0 |
| *(this+0x15F0) | 0x3C | R | — | Body rotation matrix row 1, col 1 |
| *(this+0x15F0) | 0x44 | R | — | Body rotation matrix row 1, col 2 |
| *(this+0x15F0) | 0x4C | R | — | Body rotation matrix row 2, col 0 |
| *(this+0x15F0) | 0x54 | R | — | Body rotation matrix row 2, col 1 |
| *(this+0x15F0) | 0x5C | R | — | Body rotation matrix row 2, col 2 |
| this | 0x141C | R | — | Body identifier for constraint matching |
| this | 0x1420 | R | — | Time step delta for force accumulation |
| this | 0x15C4 | R | — | Number of constraint elements in array |
| this | 0x15C8 | R | — | Pointer to constraint element array (stride 72) |
| this | 0x15F0 | R | — | Pointer to body struct with rotation matrix |

**Written-by note (persistence):**
- *(this+0x15C8) 0x18: recalc every frame — external poke does NOT persist
- *(this+0x15C8) 0x28: recalc every frame — external poke does NOT persist
- *(this+0x15C8) 0x30: recalc every frame — external poke does NOT persist
- *(this+0x15C8) 0x38: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0056d1c0 | RelativeVelocityCompute | Computes relative velocity between constraint bodies |
| 0056d2d0 | sub_56D2D0 | Applies constraint correction or updates solver state |

**Guard conditions:** If element count (this+0x15C4) <= 0, skip entire loop. For each element, if body IDs don't match either order, skip (continue searching). If data pointers are null, skip.
