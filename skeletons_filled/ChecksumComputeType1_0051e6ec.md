## ChecksumComputeType1_0051e6ec — ConvolutionChecksumCompute

**Summary:** Computes convolution-based pixel checksum across channels. For each pixel, clears output, accumulates values from lookup tables using rolling 4-bit phase counter, writes summed result, advances phase for next pixel.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5C | R | — | pixel width (stride per row) |
| this | 0x64 | R | — | channel count |
| this | 0x1A4 | R | — | context pointer |
| this | 0x1BC | R | — | context field |
| this | 0x1D4 | RW | — | phase counter (rolling 4-bit, incremented per pixel) |
| this | 0x1D8 | R | — | phase step value |

**Written-by note (persistence):**
- this 0x1D4: phase counter, updated every pixel; survives across calls as persistent state

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005159a8 | MemoryZeroFill | clears output pixel buffer to zero before accumulation |

**Guard conditions:** if a4 (pixel count) <= 0, skip outer loop. if v22 (channel count) > 0, process each channel's convolution (line 42). if v21 (width) > 0, process inner pixel loop (line 54). PASSES when all counts positive; BLOCKED when zero.
