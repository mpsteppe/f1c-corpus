## ShortComputation_5b30_00495b30 — RenderQueueDrainLoop

**Summary:** Drains a render-queue list by repeatedly popping the tail node (via sub_495AE0) while the list has elements (tail at 0x18 is non-null) and a condition check (ShortComputation_8f70 returns 1) permits processing. Part of the UI sub-rectangle render dispatch system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18 | R | — | List tail pointer — loop condition: continues while non-null (list not empty) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00495ae0 | sub_495AE0 | Pop tail node and dispatch sub-rectangle render |
| 00498f70 | ShortComputation_8f70 | Check render-dispatch condition — loop only continues when return value == 1 |

**Guard conditions:** Loop continues while tail at 0x18 is non-null AND ShortComputation_8f70() returns 1. Either condition fails → BLOCKED (break/exit loop).
