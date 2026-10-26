## UICustomRenderDispatch_00489fd0 — UI custom render element dispatcher (linked-list walk with string lookup)

**Summary:** Iterates a linked list of custom UI render elements, resolving each element's texture/driver path via string matching against a name array, then dispatches per-element rendering through virtual-method calls with viewport clipping.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** F_2DSurfaceBlitWithViewportClipping (0048a240)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x90)+0x8C)+0x0) | 0x34 | R | — | vtable dispatch slot 13 for render call (virtual method invoked on each node) |
| *(*(*(this+0x90)+0x8C)+0x8C) | 0x8C | R | — | sub-object pointer field of render-node inner struct |
| *(*(this+0x90)+0x8C) | 0x0 | R | — | base pointer of inner render-state sub-struct on node |
| *(*(this+0x90)+0x8C) | 0x8C | R | — | secondary render-context pointer from inner sub-struct |
| *(*(this+0x90)+0x8C) | 0xA0 | R | — | driver/path name string pointer from inner sub-struct |
| *(*(this+0x90)+0x8C) | 0xE4 | RW | — | byte flag mirroring this+0x131, written once per node during dispatch |
| *(this+0xC8) | 0x40 | R | — | fallback path string pointer in fallback render item struct |
| *(this+0xC8) | 0x48 | R | — | second fallback path string pointer in fallback render item |
| obj | 0x18 | R | — | virtual method at vtable slot 6: returns some dimension/status value |
| this | 0x0 | R | — | vtable pointer (slot 6 used for virtual dispatch at +0x18) |
| this | 0x4 | R | — | base Y coordinate for row position computation |
| this | 0xC | R | — | baseline offset added to v17 (from this+0x140 + this+0xC) |
| this | 0x10 | R | — | viewport dimension / clipping width used for render bounds |
| this | 0x40 | R | — | pointer to driver-name string array (input to DriverNameStringHandler and StringArrayMatchSearch) |
| this | 0x90 | R | — | head pointer of linked list of render-element nodes |
| this | 0xC8 | R | — | pointer to fallback/default render item (used when node has no driver name) |
| this | 0x131 | R | — | boolean flag byte that gets copied into each node at offset 0xE4 |
| this | 0x134 | R | — | position offset component A added to row computation |
| this | 0x13C | R | — | position offset component B added to row computation |
| this | 0x140 | R | — | viewport or baseline Y offset (v17) used in render-bounds calc |
| this | 0x14C | R | — | skip-count / linked-list position offset (how many nodes to skip from head) |
| this | 0x158 | R | — | row stride / spacing (multiplied by row index v25 in position calc) |
| this | 0x164 | R | — | remaining item count (v27, decremented each iteration) |
| this | 0x168 | R | — | target list index (v9 compared against to check if at desired position) |
| this | 0x16C | R | — | total item capacity / max count guard |

**Written-by note (persistence):**
- *(*(this+0x90)+0x8C) 0xE4: written once per node in the main render loop (line 104); value comes from this+0x131 and is overwritten on each dispatch pass — does not survive external pokes between calls

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00489d00 | sub_489D00 | pre-render setup/initialization of the UI dispatch context |
| 00497ec0 | DriverNameStringHandler | resolves/transforms a driver name string using the string array at this+0x40 |
| 00497f90 | StringArrayMatchSearch | looks up a string in the driver-name array at this+0x40, returns nonzero if found |
| 00498560 | sub_498560 | sets the active texture/resource path for the current render element |
| 0049a9c0 | ShortComputation_a9c0 | computes per-node render transform (position, scale) from row geometry and viewport params |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x158 | < | 1 | row stride / spacing — must be >= 1 to proceed |
| this | 0x16C | < | 1 | total item count — must be >= 1 to proceed |

**Guard interpretation:** Both this+0x158 (row spacing) and this+0x16C (total item count) must be >= 1 to pass the guard at line 48. If either is < 1 the function returns -1 immediately (BLOCKED). Additionally, within the main loop, if the remaining count v27 drops to <= 0 the function returns 0 early, and if the linked-list walk exhausts nodes (v8 becomes null) the loop exits.
