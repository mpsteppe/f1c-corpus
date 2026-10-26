## CollisionFaceVerticesGather_0044af20 — CollisionFaceVertexDataGather

**Summary:** Reads 6 coordinate/component values from three vertex sources referenced by input index array and writes them into output buffer; used by collision and tessellation subsystems to extract face vertex data.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_44B110 (0044b110), BezierPatchTessellation (0044b370)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output slot for first vertex value (from source 0, offset 0) |
| this | 0x4 | RW | — | Output slot for second vertex value (from source 0, offset 8) |
| this | 0x8 | RW | — | Output slot for third vertex value (from source 1, offset 8) |
| this | 0xC | RW | — | Output slot for fourth vertex value (from source 1, offset 16) |
| this | 0x10 | RW | — | Output slot for fifth vertex value (from source 2, offset 16) |
| this | 0x14 | RW | — | Output slot for sixth vertex value (from source 2, offset 0) |

**Written-by note (persistence):**
- this 0x0: overwritten every call — no persistence across calls
- this 0x4: overwritten every call — no persistence across calls
- this 0x8: overwritten every call — no persistence across calls
- this 0xC: overwritten every call — no persistence across calls
- this 0x10: overwritten every call — no persistence across calls
- this 0x14: overwritten every call — no persistence across calls

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — function has no branches or conditional checks; executes all reads/writes unconditionally.
