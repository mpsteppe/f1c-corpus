## GuardedDrawRenderDispatch_00498fe0 — Guarded rectangle fill & render list dispatch

**Summary:** Conditionally fills a rectangular region on a render surface, then iterates two render lists calling draw methods. Guarded by enable flag at this+0x60 and a virtual method check at vtable[0x28]. Part of render subsystem.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x4C)+0x0) | 0x44 | R | — | vtable slot 0x44 of list node; draw virtual dispatched per node |
| *(this+0x4C) | 0x0 | R | — | vtable pointer of first list node |
| obj | 0x28 | R | — | vtable offset 0x28 virtual method — guard predicate |
| obj | 0x2C | R | — | vtable offset 0x2C virtual method — finalize call |
| this | 0x0 | R | — | vtable pointer |
| this | 0x4 | R | — | rect left (x1) |
| this | 0x8 | R | — | rect right (x2) |
| this | 0xC | R | — | rect top (y1) |
| this | 0x10 | R | — | rect bottom (y2) |
| this | 0x4C | R | — | linked list head for per-node virtual dispatch at vtable+0x44 |
| this | 0x50 | R | — | pointer passed to RenderDispatchWithIteration |
| this | 0x60 | R | — | enable/disable guard flag |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486320 | StructFieldAccessor | returns next linked list node (traversal link) |
| 00490920 | Accessor | returns render surface/context pointer for fill operation |
| 004918d0 | RenderSurfaceFillCopy | fills rectangular region on render surface |
| 004993d0 | RenderDispatchWithIteration | iterates secondary render list dispatching calls |

**Guard conditions:** Two guards. Guard 1: `this+0x60 != 0` — PASSES into function body, BLOCKED (early return to 0) if zero. Guard 2: virtual method at vtable[0x28] must return non-zero — PASSES executes rectangle fill; BLOCKED skips fill. List iteration and finalize vtable[0x2C] call always execute when guard 1 passes.
