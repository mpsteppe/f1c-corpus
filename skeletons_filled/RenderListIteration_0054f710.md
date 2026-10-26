## RenderListIteration_0054f710 — RenderListElementProcessor

**Summary:** Iterates over scene render list elements: for non-type-2 elements, applies D3D matrix transforms; counts type-2 elements. Returns type-2 count.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** UIFocusChange (0054f7a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1E8) | 0x0 | R | — | element type identifier (2 = count-only, other = transform) |
| this | 0x1E0 | R | — | pointer to render list descriptor (count at +4, array at +8) |
| this | 0x1E4 | R | — | number of elements in render list |
| this | 0x1E8 | R | — | pointer to render list element array |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x1E8) | 0x0 | == | 2 | element type identifier (2 means skip D3D transform, just count) |
| this | 0x1E4 | <= | 0 | element count in render list |

**Guard interpretation:** If element count <= 0, return 0 immediately (BLOCKED: empty list). Type 2 elements: PASS but only counted, no D3D transform applied. Non-type-2 elements: PASS with D3D matrix transform applied via device wrapper. Returns total count of type-2 elements.
