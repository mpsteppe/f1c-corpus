## DirectXTextureSurfaceAllocation_0051629f — D3DTextureSurfaceAllocator

**Summary:** Allocates Direct3D texture surfaces by walking two linked lists of surface descriptors, computing total pixel area, determining a memory-budget scale factor, and allocating/clamping each surface's dimensions accordingly. Part of the DirectX texture/resource management system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x68) | 0x0 | RW | — | surface allocation pointer (set by MemoryAllocatorWithChunking; flag==0 means unallocated) |
| *(this+0x68) | 0x4 | R | — | original surface width in pixels |
| *(this+0x68) | 0x8 | R | — | surface height / row count |
| *(this+0x68) | 0xC | R | — | mip-level block divisor (used to compute effective resolution) |
| *(this+0x68) | 0x10 | RW | — | allocated surface width (capped to v14 * mip-divisor if original exceeds budget) |
| *(this+0x68) | 0x14 | RW | — | texture pixel format identifier (copied from parent descriptor field 0x4C) |
| *(this+0x68) | 0x18 | RW | 0 | allocation status or offset field (zeroed on alloc) |
| *(this+0x68) | 0x1C | RW | 0 | allocation status or offset field (zeroed on alloc) |
| *(this+0x68) | 0x21 | RW | 0 | boolean: secondary allocation flag (cleared on alloc) |
| *(this+0x68) | 0x22 | RW | 1 | boolean: surface downscaled flag (set to 1 when width is clamped below original) |
| *(this+0x68) | 0x24 | R | — | next-pointer in surface descriptor linked list (walked for iteration) |
| *(this+0x6C) | 0x0 | RW | — | surface allocation pointer for second surface list (allocated by ChunkedBufferAlloc) |
| *(this+0x6C) | 0x4 | R | — | original surface width (second list) |
| *(this+0x6C) | 0x8 | R | — | surface height / row count (second list) |
| *(this+0x6C) | 0xC | R | — | mip-level block divisor (second list) |
| *(this+0x6C) | 0x10 | RW | — | allocated surface width (second list, capped if exceeding budget) |
| *(this+0x6C) | 0x14 | RW | — | texture pixel format identifier (second list) |
| *(this+0x6C) | 0x18 | RW | 0 | allocation status field (second list, zeroed) |
| *(this+0x6C) | 0x1C | RW | 0 | allocation status field (second list, zeroed) |
| *(this+0x6C) | 0x21 | RW | 0 | boolean: secondary allocation flag (second list, cleared) |
| *(this+0x6C) | 0x22 | RW | 1 | boolean: surface downscaled flag (second list, set when clamped) |
| *(this+0x6C) | 0x24 | R | — | next-pointer in second surface descriptor linked list |
| this | 0x4 | R | — | pointer to texture-surface descriptor table (root of both linked lists) |
| this | 0x44 | R | — | second surface-list head pointer (v1[17]) |
| this | 0x48 | R | — | unknown (v1[18], read during second-list walk) |
| this | 0x4C | R | — | texture pixel format value (copied to each allocated surface descriptor) |
| this | 0x50 | R | — | unknown (read during allocation loop) |
| this | 0x8C | R | — | unknown (read during first-list walk) |

**Written-by note (persistence):**
- *(this+0x68) 0x0: written once during allocation — persists until surface is freed/reallocated
- *(this+0x68) 0x10: written once during allocation (may be clamped) — persists
- *(this+0x68) 0x14: written once during allocation — persists
- *(this+0x68) 0x18: written once during allocation — persists
- *(this+0x68) 0x1C: written once during allocation — persists
- *(this+0x68) 0x21: written once during allocation — persists
- *(this+0x68) 0x22: written once during allocation — persists
- *(this+0x6C) 0x0: written once during allocation — persists
- *(this+0x6C) 0x10: written once during allocation — persists
- *(this+0x6C) 0x14: written once during allocation — persists
- *(this+0x6C) 0x18: written once during allocation — persists
- *(this+0x6C) 0x1C: written once during allocation — persists
- *(this+0x6C) 0x21: written once during allocation — persists
- *(this+0x6C) 0x22: written once during allocation — persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005160ad | MemoryAllocatorWithChunking | allocate GPU-accessible surface memory with chunked allocation strategy |
| 0051613f | ChunkedBufferAlloc | allocate chunked buffer for second surface list |
| 0051935c | ShortComputation_935c | compute memory budget / scale factor from total pixel area |
| 00519361 | SurfaceMemoryAllocate | allocate Direct3D surface memory for downscaled surfaces |

**Guard conditions:** Allocation-flag guard: for each surface descriptor node, checks if flag at offset 0x0 is zero (unallocated) — PASSES into allocation path, non-zero (already allocated) BLOCKS and skips. Total-pixel-area guard: if v3 (total accumulated pixel area) > 0, proceeds with scale-factor computation and allocation; if <= 0 (no surfaces to allocate), skips entire allocation loop. Width-budget guard: if (original_width - 1) / mip_divisor + 1 > scale_factor_v14, clamps allocated width to v14 * mip_divisor and triggers SurfaceMemoryAllocate with downscale flag; otherwise uses original width.