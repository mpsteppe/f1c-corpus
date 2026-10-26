## VertexBufferAllocationAndStageTransformation_005058d2 — 3D trilinear texture resample with X/Y/Z coord tables

**Summary:** Performs full 3D trilinear texture resampling using coordinate tables from MemoryAllocation_53ec for all three dimensions. Allocates two staging buffers, reads 8 source texels per output, applies weighted float interpolation with 3-layer weighting, writes to destination. Frees 5 buffers on completion.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** D3DContextInit (005063a5)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005007ec | sub_5007EC | R | element constructor for vector init during staging buffer allocation |
| 0059c4fa | loc_59C4FA | R | SEH jump target or exception handling label |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005008c2 | sub_5008C2 | vector constructor for staging buffer elements |
| 005053ec | MemoryAllocation_53ec | builds X, Y, and Z interpolation coordinate tables |
| 00587bcf | FreeWrapper_7bcf | frees all buffers (3 coord tables, 2 staging buffers) |
| 00587c03 | OperatorNewNhMallocWrapper | allocates staging buffer memory |
| 0058a5d8 | SEHHandlerInit | initialises structured exception handler |

**Guard conditions:** If byte at v1[2] (offset 8) != 3 → returns -2147467259. If any of the 3 coordinate tables (X/Y/Z) returns NULL → jumps to cleanup returning -2147024882. If first staging buffer allocation fails → jumps to cleanup. If second staging buffer allocation fails → jumps to cleanup.
