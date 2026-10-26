## sub_48CCB0_0048ccb0 — SpriteTileBatchRenderer

**Summary:** Renders a batch of sprite/tile objects by iterating a linked list, computing screen-space rects from object bounds and camera clip region, and issuing draw calls via F_10ParamForwarder. Handles clipping, wrapping, and sub-region rendering. Render system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x324)+0x4)+0xC) | 0x1C | R | — | nested: source texture width (from node→child→offset 0x1C) |
| *(*(this+0x324)+0x4) | 0xC | R | — | nested: child object pointer from list node |
| *(this+0x324) | 0x4 | R | — | list node: next pointer (traversal) |
| obj | 0x8 | R | — | external object: field at +0x8 (vtable or data ptr) |
| obj | 0xC | R | — | external object: field at +0xC |
| obj | 0x10 | R | — | external object: field at +0x10 |
| obj | 0x14 | R | — | external object: field at +0x14 |
| obj | 0x18 | R | — | external object: field at +0x18 |
| obj | 0x1C | R | — | external object: field at +0x1C |
| obj | 0x20 | R | — | external object: field at +0x20 |
| obj | 0x24 | R | — | external object: field at +0x24 |
| this | 0x0 | R | — | vtable pointer (used for get_width, get_left, get_height, get_top, etc.) |
| this | 0x4 | R | — | coordinate / dimension field |
| this | 0xC | R | — | coordinate / dimension field (this[3]) |
| this | 0x14 | R | — | clip rect left bound (-1 sentinel = unset) |
| this | 0x18 | R | — | clip rect top bound (-1 sentinel = unset) |
| this | 0x1C | R | — | clip rect right bound (-1 sentinel = unset) |
| this | 0x20 | R | — | clip rect bottom bound (-1 sentinel = unset) |
| this | 0x84 | R | — | get_width() vtable call result (right bound) |
| this | 0x88 | R | — | get_height() vtable call result (bottom bound) |
| this | 0x31C | R | — | current list position / stride accumulator |
| this | 0x324 | RW | 0 | linked list head pointer (current node in traversal) |
| this | 0x328 | R | — | list node count (total items) |
| this | 0x32C | R | — | stride/pitch per list element |
| this | 0x334 | R | — | list index offset (this[205]) |

**Written-by note (persistence):**
- this 0x324: written every call (list traversal cursor) — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cde00 | unk_7CDE00 | R | Unknown_Render_CDE00 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486460 | ConditionalDelegation_6460 | walks list to find target node at index this[33] for final render delegation |
| 00486830 | sub_486830 | checks render state / validity before committing draw calls |
| 00494a30 | F_10ParamForwarder | issues actual drawing command with source rect, dest rect, and surface handle |
| 00495150 | GlobalAccessor_5150 | retrieves global render context/surface from unk_7CDE00 |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x14 | != | 18446744073709551615 | clip rect left — if any clip bound is NOT -1, PASSES (clip rect defined, proceed) |
| this | 0x18 | != | 18446744073709551615 | clip rect top — same combined OR guard |
| this | 0x1C | != | 18446744073709551615 | clip rect right |
| this | 0x20 | != | 18446744073709551615 | clip rect bottom |
| this | 0x328 | > | 0 | list node count — if >0 PASSES (items to render); if 0 BLOCKED (return -1) |

**Guard interpretation:** Outer guard: if ALL clip rect fields (0x14, 0x18, 0x1C, 0x20) are -1 (sentinel), BLOCKED — returns -1 immediately (no render region defined). If any is not -1, PASSES. Inner guard: if this+0x328 (list count) <= 0, BLOCKED — returns -1 (empty list). Both must pass for rendering to proceed. Within the main loop, each list node is checked for non-NULL; if NULL, the loop breaks early.
