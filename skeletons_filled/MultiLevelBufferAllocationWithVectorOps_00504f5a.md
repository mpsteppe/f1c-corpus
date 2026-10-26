## MultiLevelBufferAllocationWithVectorOps_00504f5a — 3D texture downscale with 8-sample trilinear averaging

**Summary:** Downscales a 3D texture by 2× in each dimension using 8-sample trilinear float averaging (×0.125). Validates dimensions match half-size, ensures even alignment, allocates up to 4 staging buffers, reads 8 source texels per output via vtable method, averages floats, writes result to destination.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** D3DContextInit (005063a5)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005007ec | sub_5007EC | R | element constructor for vector init during buffer allocation |
| 0059c4be | loc_59C4BE | R | SEH jump target or exception handling label |
| 0059e4e0 | flt_59E4E0 | R | ForceIncrementClamp [DERIVED] — float constant (0.125) for 8-sample averaging |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005008c2 | sub_5008C2 | vector constructor for staging buffer elements |
| 00587bcf | FreeWrapper_7bcf | frees staging buffers |
| 00587c03 | OperatorNewNhMallocWrapper | allocates staging buffer memory |
| 0058a5d8 | SEHHandlerInit | initialises structured exception handler |

**Guard conditions:** If byte at offset 8 != 5 → returns -2147467259. If dest width != source_width>>1 (unless both 1) → returns -2147467259. If dest height != source_height>>1 (unless both 1) → returns -2147467259. If dest depth != source_depth>>1 → returns -2147467259. If odd width/height/depth > 1 → masked to even. If first staging buffer allocation fails → returns -2147024882. If second allocation fails → returns -2147024882.
