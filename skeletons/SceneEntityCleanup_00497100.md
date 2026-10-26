## SceneEntityCleanup_00497100 — CleanupSceneEntityLists

**Summary:** Performs cleanup of two scene-entity linked lists when parameter a2 is non-zero. Traverses each list twice: first calls virtual method (vtable+0x44) on each item, then frees nodes with active flag (byte at node+12). Zeroes all list pointers. Always calls Accessor and CircularBufferRingAdvance.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CarCrashDamageProcessing (00496030), sub_496E90 (00496e90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x18BC)+0x0) | 0x0 | R | — | Item pointer from first list node |
| *(*(this+0x18BC)+0x0) | 0x44 | R | — | Virtual method at vtable+0x44 called on each first-list item |
| *(*(this+0x18CC)+0x0) | 0x0 | R | — | Item pointer from second list node |
| *(*(this+0x18CC)+0x0) | 0x44 | R | — | Virtual method at vtable+0x44 called on each second-list item |
| *(this+0x18BC) | 0x0 | R | — | First list head's item field |
| *(this+0x18C0) | 0x4 | R | — | First list next pointer (offset 4 in node) |
| *(this+0x18C8) | 0x0 | R | — | Second list head's item field |
| *(this+0x18CC) | 0x0 | R | — | First list head's item field (alias path) |
| *(this+0x18D0) | 0x4 | R | — | Second list next pointer (offset 4 in node) |
| *(this+0x18D8) | 0x0 | R | — | Second list head's item field (alias path) |
| this | 0x18BC | RW | 0 | First list head pointer |
| this | 0x18C0 | RW | 0 | Counter or secondary field for first list |
| this | 0x18C4 | RW | 0 | Current node pointer during first list traversal |
| this | 0x18C8 | RW | 0 | State flag for first list — zeroed after cleanup |
| this | 0x18CC | RW | 0 | Second list head pointer |
| this | 0x18D0 | RW | 0 | Counter or secondary field for second list |
| this | 0x18D4 | RW | 0 | Current node pointer during second list traversal |
| this | 0x18D8 | RW | 0 | State flag for second list — zeroed after cleanup |

**Written-by note (persistence):**
- this 0x18BC: Written conditionally (under if a2) to 0. External poke survives if a2=0.
- this 0x18C0: Written conditionally (under if a2) to 0. External poke survives if a2=0.
- this 0x18C4: Written conditionally (under if a2) to 0. External poke survives if a2=0.
- this 0x18C8: Written conditionally (under if a2) to 0. External poke survives if a2=0.
- this 0x18CC: Written conditionally (under if a2) to 0. External poke survives if a2=0.
- this 0x18D0: Written conditionally (under if a2) to 0. External poke survives if a2=0.
- this 0x18D4: Written conditionally (under if a2) to 0. External poke survives if a2=0.
- this 0x18D8: Written conditionally (under if a2) to 0. External poke survives if a2=0.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cde00 | unk_7CDE00 | R | Unknown_Render_CDE00 [DERIVED] |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00490920 | Accessor | Returns structure pointer for ring buffer advance |
| 004917c0 | CircularBufferRingAdvance | Advances ring buffer after cleanup |
| 004950e0 | RenderFrameWrapper | Wraps render frame before list processing |
| 004f9b30 | StateFlagComputation | Clears state flag to 0 |
| 00587bcf | FreeWrapper_7bcf | Frees node memory during list teardown |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x18C8 | == | 0 | First list empty indicator |
| this | 0x18D8 | == | 0 | Second list empty indicator |

**Guard interpretation:** Primary guard is parameter a2 — non-zero PASSES (enters cleanup block), zero BLOCKS (skips all list teardown). Fields at 0x18C8 and 0x18D8 being zero indicate respective lists are already empty.
