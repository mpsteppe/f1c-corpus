## MediaAudioDecodeDispatch_0051c3e2 — Media Decode Function Table Dispatcher

**Summary:** Allocates a decode descriptor table and populates it with function pointers selected based on media surface format, dimensions, and resampling requirements. Dispatches to the appropriate pixel copy/blend/filter routine (monochrome duplicate, interleave copy, pixel blend, image resample, or track map fill) for each sub-surface.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_516C7B (00516c7b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x0 | R | — | function pointer: allocator dispatch (called with a1, 1, 160) |
| *(this+0x4) | 0x8 | R | — | function pointer: secondary allocator for aligned buffer |
| *(this+0xC4) | 0x24 | R | — | sub-surface aligned width (pixels after ceiling division) |
| *(this+0xC4) | 0x28 | R | — | sub-surface pixel format / stride factor |
| *(this+0xC4) | 0x30 | R | — | sub-surface output stride flag |
| obj | 0x0 | R | — | vtable pointer for error callback |
| obj | 0x14 | RW | 37 | error code (23 = surface format error, 37 = non-integer scale) |
| this | 0x0 | R | — | vtable/object pointer (for error dispatch) |
| this | 0x4 | R | — | allocator vtable pointer |
| this | 0x20 | R | — | number of sub-surfaces |
| this | 0x48 | R | — | boolean: whether surface channel data is available |
| this | 0x5C | R | — | source image stride or alignment value |
| this | 0xC4 | R | — | pointer to sub-surface descriptor array |
| this | 0x108 | R | — | horizontal scale factor / pixel ratio |
| this | 0x10C | R | — | output surface aligned width |
| this | 0x110 | R | — | max horizontal scale factor (across sub-surfaces) |
| this | 0x114 | R | — | max vertical scale factor (across sub-surfaces) |
| this | 0x19C | RW | — | pointer to allocated decode descriptor table |

**Written-by note (persistence):**
- obj 0x14: written only on error path (conditional, set to 37) — if no error, external poke could persist
- this 0x19C: written once during allocation — external poke would NOT survive since it's re-allocated on next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0051bfa6 | VehicleStructFieldCopy | R | function pointer: simple struct field copy (passthrough identity) |
| 0051bfc0 | AudioBufferMixing | R | function pointer: audio buffer mixing/downsampling routine |
| 0051c086 | SetterReturnA4 | R | function pointer: setter that returns a4 register value |
| 0051c091 | PtrInitZero | R | function pointer: initializes pointer target to zero |
| 0051c099 | TrackMapPixelFill | R | function pointer: fills pixels with track map color data |
| 0051c176 | MonochromeBufferByteDuplicateCopy | R | function pointer: duplicates monochrome buffer by byte-doubling (horizontal 2x) |
| 0051c1cd | BufferInterleaveCopy | R | function pointer: interleaved buffer copy (2x2 upscale) |
| 0051c237 | PixelBlendFilterHorizontal | R | function pointer: horizontal pixel blend filter (for anti-aliased 2x upscale) |
| 0051c2db | ImageResampleFilter | R | function pointer: full image resample filter (2x2 with filtering) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00515927 | AlignUp | aligns value up to specified boundary |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0xC4) | 0x28 | > | 2 | sub-surface format/scale factor: if >2, selects filtered resample path |
| this | 0x20 | > | 0 | sub-surface count: if >0, iterates sub-surfaces; if 0, skips all processing |
| this | 0x114 | > | 1 | vertical scale factor: if >1, enables filtered/interpolated decode path |

**Guard interpretation:** PASSES when `this+0x20 > 0` (has sub-surfaces to process). For each sub-surface: if dimensions match exactly (no scaling), uses passthrough copy (SetReturnA4). If horizontal 2x scaling and vertical matches, selects MonochromeBufferByteDuplicateCopy or PixelBlendFilterHorizontal (when this+0x114 > 1). If 2x2 upscale, selects BufferInterleaveCopy or ImageResampleFilter. If non-integer scale factors, FAILS with error 37. If scale factors don't align, selects TrackMapPixelFill with byte-repeat factors. BLOCKED entire dispatch if this+0x48 flag set (calls error 23).