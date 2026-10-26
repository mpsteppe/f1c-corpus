## DrawableObjectBatchProcessor_00519d51 — DrawableObjectBatchProcessor

**Summary:** Processes a batch of drawable sprite objects by waiting for position synchronization, allocating per-object buffers, and dispatching render calls for visible objects.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x184) | 0x48 | R | — | frame info field used as allocation index value for object's vtable slot |
| *(this+0x18C) | 0x0 | R | — | progress callback vtable entry, called during position wait |
| *(this+0x4) | 0x20 | R | — | sub-allocator vtable entry for buffer allocation |
| *(this+0xC4) | 0xC | R | — | sprite object width per row (multiplied by position for size) |
| *(this+0xC4) | 0x1C | R | — | sprite object stride (increment per row in output) |
| *(this+0xC4) | 0x20 | R | — | sprite object base Y offset |
| *(this+0xC4) | 0x24 | R | — | sprite object height count |
| *(this+0xC4) | 0x30 | R | — | sprite object Y stride in buffer |
| this | 0x4 | R | — | sub-allocator vtable pointer |
| this | 0x20 | R | — | number of sprite objects to process |
| this | 0x7C | R | — | current sub-position, checked against limit in wait loop |
| this | 0x80 | R | — | current scan position |
| this | 0x84 | R | — | sub-position limit (compared with 0x7C) |
| this | 0x88 | R | — | total position limit |
| this | 0xC4 | R | — | pointer to array of sprite object descriptors (84 bytes each) |
| this | 0x118 | R | — | line position limit (minus 1 used) |
| this | 0x184 | R | — | pointer to frame info struct |
| this | 0x18C | R | — | vtable pointer with progress callback (entry 0) |
| this | 0x198 | R | — | vtable pointer for render dispatch functions |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x20 | > | 0 | sprite object count |

**Guard interpretation:** this->0x20 > 0 PASSES (iterates object list for rendering). When 0, skips object processing entirely, only returns completion status. Before main loop, position synchronization loop checks if this->0x7C >= this->0x84 AND (this->0x7C != this->0x84 OR this->0x80 > this->0x88) — if true, BLOCKED (waits via callback until condition clears).
