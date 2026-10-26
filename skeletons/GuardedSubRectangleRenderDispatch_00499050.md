## GuardedSubRectangleRenderDispatch_00499050 — Guarded sub-rectangle fill dispatch

**Summary:** Conditionally fills a sub-rectangle on the render surface when mode field equals 2. Part of render surface update system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MultiRegionOffsetAccumulationWithVTableDispatch (004869e0), GuardedConditionalRenderCall (00486f00), sub_495AE0 (00495ae0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x54 | R | — | pointer to sub-structure containing mode field |
| this | 0x7C | R | — | mode/type discriminator; compared against literal 2 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00490920 | Accessor | returns render surface/context pointer |
| 004918d0 | RenderSurfaceFillCopy | fills sub-rectangle on render surface |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x7C | == | 2 | mode discriminator — render fill type / pass ID |

**Guard interpretation:** PASSES when `this+0x7C == 2` — calls Accessor + RenderSurfaceFillCopy to fill sub-rectangle. BLOCKED when `this+0x7C != 2` — skips fill entirely, returns value - 2.
