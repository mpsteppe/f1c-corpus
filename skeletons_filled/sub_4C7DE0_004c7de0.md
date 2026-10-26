## sub_4C7DE0_004c7de0 — Render tick update with camera FOV and list iteration

**Summary:** Render tick processing: decrements a timer at +0x4 by a default return value; when timer goes below zero, calls UpdateCameraFOV (0.4 increment) and clamps timer to 0. If InitStatus is set, dispatches vtable call and iterates a linked list, calling sub_4C8FC0 on each entry.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RenderTickUpdate (004c8b70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xC)+0x0) | 0x0 | R | — | current linked list node pointer |
| *(*(this+0xC)+0x8) | 0x0 | R | — | first field of current node (vtable?) |
| *(*(this+0xC)+0x8) | 0x4 | R | — | next node pointer |
| *(this+0xC) | 0x0 | R | — | linked list head pointer |
| *(this+0xC) | 0x8 | RW | — | linked list cursor (reset to head each tick) |
| this | 0x4 | RW | 0 | timer/cooldown counter, decremented each tick |
| this | 0xC | R | — | linked list head pointer reference |

**Written-by note (persistence):**
- *(this+0xC) 0x8: reset to list head each tick; persists as iteration cursor
- this 0x4: decremented each tick, clamped to 0; persists as frame timer

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e8c8 | flt_59E8C8 | R | Physics_ConvergenceThreshold [DERIVED] (also: ` — convergence threshold (terminates iteration) |
| 008ac4c4 | dword_8AC4C4 | R | InitStatus [DERIVED] |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c7f30 | UpdateCameraFOV | update camera field of view with smooth interpolation |
| 004c8fc0 | sub_4C8FC0 | unknown per-node processing function |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0xC) | 0x0 | == | 0 | linked list head pointer — if NULL, skip all list processing |

**Guard interpretation:** BLOCKED: if *(this+0xC) is NULL (no list), skip entire body including timer decrement and camera update. PASSES: list exists, proceed with timer decrement, camera FOV update, and list iteration.
