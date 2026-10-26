## FAILOverviewSaysFIRCrossfeedButDispatchesToIMDCT_0051bad1 — AudioProcessingModeDispatch

**Summary:** Dispatches per-object audio processing based on mode field (AudioSampleLookup, AudioFIRConvolutionFilter, FixedPointIDCT, render branch, audio mixing) and performs optional data transformation (copy, round-multiply, or float-multiply).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x114) | 0x0 | RW | — | output pointer written with selected function pointer |
| obj | 0x0 | R | — | vtable pointer for dispatch |
| obj | 0x14 | RW | 47 | vtable entry 5, written with error code 47 on unknown mode variant |
| obj | 0x18 | RW | — | vtable entry 6, written with offending mode value on error |
| this | 0x0 | R | — | main vtable pointer |
| this | 0x20 | R | — | number of objects to process |
| this | 0x44 | R | — | render mode variant selector (0, 1, 2 for mode==8 objects) |
| this | 0xC4 | R | — | pointer to array of sprite object descriptors |
| this | 0xE8 | R | — | per-object mode field (1=AudioSampleLookup, 2=AudioFIRConvolutionFilter, 4=IDCT, 8=render variant) |
| this | 0xF4 | R | — | per-object byte flag enabling data transformation step |
| this | 0x110 | R | — | per-object source data pointer for transformation |
| this | 0x114 | R | — | per-object destination pointer for output function table |
| this | 0x198 | R | — | pointer to internal dispatch state |
| this | 0x1C4 | RW | — | per-object transformation mode counter (v24, 0/1/2) |

**Written-by note (persistence):**
- *(this+0x114) 0x0: once, unconditional per object; set to selected function pointer; survives external poke
- obj 0x14: once, conditional on error; set to 47; survives external poke
- obj 0x18: once, conditional on error; set to mode value; survives external poke
- this 0x1C4: once, conditional per object; set to 0, 1, or 2; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0052804a | FixedPointIDCT | R | IDCT processing function (mode == 4) |
| 0052835f | AudioFIRConvolutionFilter | R | FIR convolution filter (mode == 2) |
| 0052851d | AudioSampleLookup | R | Audio sample lookup (mode == 1) |
| 0052855a | RenderingBranchOnDAT005d79dc | R | Render branch (mode == 8, variant 0) |
| 005285a6 | RenderModeBranch | R | Render mode branch (mode == 8, variant 1) |
| 005285f2 | AudioMixing | R | Audio mixing (mode == 8, variant 2) |
| 005b0508 | unk_5B0508 | R | Unk_ImageCodec [DERIVED] — source data for mode 1 transformation |
| 005b0588 | word_5B0588 | R | ImageDataBlock [DERIVED] — data block/boundary for transformation loops |
| 005b05c8 | dbl_5B05C8 | R | DriverTableSource [DERIVED] — float multiplier table for mode 2 transformation |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x20 | <= | 0 | object count |
| this | 0xE8 | != | 8 | mode field not matching 8 variant |
| this | 0xE8 | == | 1 | AudioSampleLookup mode |
| this | 0xE8 | == | 2 | AudioFIRConvolutionFilter mode |
| this | 0xE8 | == | 4 | FixedPointIDCT mode |

**Guard interpretation:** this->0x20 <= 0 BLOCKS entire processing. Mode field at object+0x24 (this->0xE8) selects handler: 4→IDCT, 2→FIR, 1→SampleLookup, 8→check this->0x44 variant (0→RenderingBranch, 1→RenderModeBranch, 2→AudioMixing, else→error 47), other→error 6. Byte flag at object+0x30 (this->0xF4) controls data transformation step after dispatch.
