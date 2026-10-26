## CodecModeSelect_0051ea90 — Mode-based codec/processor selector

**Summary:** Selects processing function pointer (assigned to sub-buffer+4) based on mode field at this+0x4C (values 0/1/2+) and channel count at this+0x64 (==3). Conditionally initializes sub-buffers via VirtualArrayFill, MemoryZeroFill, PerIndexTableGenerationWithDivision, and sub_51E3E7.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | obj = *this, base object pointer used for call (*obj)(this) in default path |
| obj | 0x14 | RW | 47 | obj+0x14: field set to 47 in default mode path |
| this | 0x0 | R | — | this pointer used as call target in default path |
| this | 0x4C | R | — | mode selector (0, 1, 2+) — controls which codec path is taken |
| this | 0x5C | R | — | size parameter — 2*field+4 used in MemoryZeroFill loop |
| this | 0x64 | R | — | channel count — checked == 3 for 3-channel vs other |
| this | 0x70 | RW | — | written from sub-buffer+20 (copy of mode info) |
| this | 0x74 | RW | — | written from sub-buffer+16 (copy of mode info) |
| this | 0x1A4 | R | — | sub-buffer pointer (v1 = a1[105]), read to access sub-fields |
| this | 0x1A8 | RW | — | unknown (not directly referenced in decomp) |
| this | 0x1B4 | R | — | unknown (not directly referenced in decomp) |
| this | 0x1B8 | R | — | unknown (not directly referenced in decomp) |
| this | 0x1C0 | R | — | unknown (not directly referenced in decomp) |
| this | 0x1D4 | RW | 0 | unknown (not directly referenced in decomp) |
| this | 0x1D8 | R | — | unknown (not directly referenced in decomp) |
| this | 0x1E8 | R | — | unknown (not directly referenced in decomp) |
| this | 0x1F8 | RW | 0 | unknown (not directly referenced in decomp) |

**Written-by note (persistence):**
- obj 0x14: written unconditionally in default mode path — survives as long as this object lives
- this 0x70: written once per call — overwritten on next call
- this 0x74: written once per call — overwritten on next call
- this 0x1A8: unknown — not visible in this decomp
- this 0x1D4: init 0 — not visible in this decomp
- this 0x1F8: init 0 — not visible in this decomp

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0051e5d7 | TableWeightedMix | R | function pointer — assigned to sub-buffer+4 for mode 0, non-3-channel |
| 0051e65f | ChecksumComputeType03Stream | R | function pointer — assigned to sub-buffer+4 for mode 0, 3-channel |
| 0051e6ec | ChecksumComputeType1 | R | function pointer — assigned to sub-buffer+4 for mode 1, non-3-channel |
| 0051e7d7 | AudioSynthesis3ChannelSampleGenerator | R | function pointer — assigned to sub-buffer+4 for mode 1, 3-channel |
| 0051e8d6 | PixelDataConvolutionViaLookupTable | R | function pointer — assigned to sub-buffer+4 for mode 2 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005159a8 | MemoryZeroFill | zero-fills each sub-buffer entry (size 2*(this+0x5C)+4) in mode 2 path |
| 0051e3e7 | sub_51E3E7 | conditional init in mode 1 when sub-buffer byte at offset +28 is 0 |
| 0051e512 | PerIndexTableGenerationWithDivision | conditional table setup in mode 1 when sub-buffer dword at offset +52 is 0 |
| 0051ea5a | VirtualArrayFill | conditional array fill in mode 2 when sub-buffer dword at offset +68 is 0 |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x64 | == | 3 | channel count — selects 3-channel vs other processor |
| this | 0x1C0 | == | 0 | unknown — not visible in decomp code |
| this | 0x1E8 | == | 0 | unknown — not visible in decomp code |

**Guard interpretation:** this+0x64 == 3 taken in mode 0 (→ ChecksumComputeType03Stream) and mode 1 (→ AudioSynthesis3ChannelSampleGenerator). When != 3, different processor assigned (TableWeightedMix, ChecksumComputeType1). Other two guards (0x1C0, 0x1E8) not visible in decompiled code — inferred from caller context.
