## DirectXSurfaceFormatNegotiation_00502a15 — Texture Format Auto-Detection and Decoding Dispatcher

**Summary:** Attempts to decode raw image data by trying format decoders in priority order (BMP, TGA, DDS-header, generic, DDS-surface, PPM, DDS-validate). On success, populates an output descriptor struct with format info; on failure, cleans up allocations and tries the next decoder.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LockUnlockWrapper (005006d5), sub_5008E4 (005008e4)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4C) | 0x4C | R | — | linked-list node: next-node pointer (traversed in surface chain walk) |
| this | 0x0 | R | — | pixel format FourCC code (used as output format identifier) |
| this | 0x4 | RW | 0 | data buffer pointer 1 (allocated by decoder, freed on retry) |
| this | 0x8 | RW | 0 | data buffer pointer 2 (allocated by decoder, freed on retry) |
| this | 0xC | R | — | image width (populated by successful decoder) |
| this | 0x10 | R | — | image height (populated by successful decoder) |
| this | 0x14 | R | — | image depth / mip level count (populated by successful decoder) |
| this | 0x18 | RW | 0 | format flags field (set to 0 in output; also used as surface count init) |
| this | 0x1C | RW | 0 | mip count or surface array size (set to 1 base in output) |
| this | 0x20 | RW | — | output: width propagated from 0xC (copied in finalization loop) |
| this | 0x24 | RW | — | output: height propagated from 0x10 (copied in finalization loop) |
| this | 0x28 | RW | 0 | output: depth/stride zeroed (copied from 0x14 in finalization) |
| this | 0x2C | RW | — | output: format field propagated from 0x18 (copied in finalization) |
| this | 0x38 | RW | 0 | buffer 1 ownership flag (nonzero = caller must free; zeroed on retry) |
| this | 0x3C | RW | 0 | buffer 2 ownership flag (nonzero = caller must free; zeroed on retry) |
| this | 0x40 | RW | — | context/user-data parameter (a5 passed through to decoder) |
| this | 0x44 | RW | 3 | format sub-type / color model (written as 3 initially, then overwritten by decoder) |
| this | 0x48 | RW | — | format index: which decoder succeeded (from priority array v21) |
| this | 0x4C | RW | 0 | head pointer to linked list of surface nodes (zeroed on retry, walked for count) |
| this | 0x50 | RW | 0 | tail/aux pointer for linked list (zeroed on retry, walked in finalization) |
| this | 0x98 | R | — | surface list node: first dword of node (non-null check in linked-list traversal) |

**Written-by note (persistence):**
- this 0x4: written by decoder on success, zeroed on failure retry — external poke does NOT survive retry
- this 0x8: written by decoder on success, zeroed on failure retry — external poke does NOT survive retry
- this 0x18: written during output finalization — external poke does NOT persist across format negotiation
- this 0x1C: written during output finalization — external poke does NOT persist across format negotiation
- this 0x20: written during output finalization — external poke does NOT persist across format negotiation
- this 0x24: written during output finalization — external poke does NOT persist across format negotiation
- this 0x28: written during output finalization — external poke does NOT persist across format negotiation
- this 0x2C: written during output finalization — external poke does NOT persist across format negotiation
- this 0x38: zeroed on retry after failure — external poke does NOT survive retry
- this 0x3C: zeroed on retry after failure — external poke does NOT survive retry
- this 0x40: set to a5 each iteration — external poke does NOT persist
- this 0x44: set to 3 initially, overwritten by decoder — external poke does NOT persist
- this 0x48: set to priority array value each iteration — external poke does NOT persist
- this 0x4C: zeroed on retry — external poke does NOT survive retry
- this 0x50: zeroed on retry — external poke does NOT survive retry

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005006a4 | FourCCDecoder | maps pixel format FourCC integer to a format code for output descriptor |
| 00500fae | ShortComputation_0fae | deallocation/release helper for surface nodes |
| 00500fca | DDSTextureFormatValidationDecoding | DDS format validator (priority index 5, last resort decoder) |
| 00501722 | ImageTextureDecompressor | generic image/texture decompressor (priority index 1, e.g. TGA) |
| 00501992 | DDSHeaderParsing | DDS header parser (priority index 2) |
| 00501e39 | PPMP6ImageDecoder | PPM/P6 image decoder (priority index 6) |
| 0050210e | sub_50210E | unknown format decoder (priority index 3) |
| 005026a4 | DDSTextureSurfaceCreation | DDS surface creation/decoder (priority index 4) |
| 005029e5 | BMPHeaderValidation | BMP header validator and decoder (priority index 0, tried first) |
| 00587bcf | FreeWrapper_7bcf | memory deallocation wrapper (frees buffer 1 or buffer 2) |

**Guard conditions:** Loop iterates through 7 decoder indices [0,5,4,1,3,2,6] in priority order. Each decoder is called with the raw data; the decoder's return value (v13) is stored in v5. If `v5 >= 0`, the decoder succeeded → break out of loop (PASSES). If `v5 < 0` (BLOCKED), cleanup allocated buffers/surfaces, zero the relevant fields, and try the next decoder. If all 7 decoders fail (v22 == 7), returns error code -2005529767 (0x88880019). On success, populates optional output struct a4 and runs a finalization loop propagating format fields through the surface chain.
