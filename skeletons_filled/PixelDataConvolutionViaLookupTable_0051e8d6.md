## PixelDataConvolutionViaLookupTable_0051e8d6 — PixelConvolutionErrorDiffusion

**Summary:** Convolves pixel data through lookup tables with serpentine-scan error diffusion. Alternates left-to-right/right-to-left per row, accumulates convolution results from indexed table lookups, computes and distributes quantization error through feedback loop.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1E8) | 0x0 | RW | — | error diffusion buffer (accumulated per-channel error) |
| this | 0x5C | R | — | pixel width (stride) |
| this | 0x64 | R | — | channel count |
| this | 0x11C | R | — | unknown context field |
| this | 0x1A4 | R | — | context pointer |
| this | 0x1B4 | R | — | convolution table pointer |
| this | 0x1BC | R | — | context field |
| this | 0x1E8 | R | — | error diffusion buffer pointer |
| this | 0x1F8 | RW | — | scan-direction toggle (alternates per row) |

**Written-by note (persistence):**
- *(this+0x1E8) 0x0: error diffusion values, updated per pixel; survives across calls
- this 0x1F8: direction toggle flipped each row; survives between calls

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005159a8 | MemoryZeroFill | clears output pixel buffer before convolution |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1F8 | == | 0 | direction flag = forward (left-to-right) |

**Guard interpretation:** When this+0x1F8 == 0, scan direction is forward (left-to-right) with v24=+stride, v27=1 (line 63-66). When non-zero, direction is reverse (right-to-left) with v24=-stride, v27=-1 (lines 56-60). Flag toggled after each row at *(v4+84) = !*(v4+84) (line 101-104). PASSES: both directions proceed with convolution. BLOCKED: no direction blocking — both sides always execute.
