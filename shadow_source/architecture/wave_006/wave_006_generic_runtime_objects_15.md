# SurfaceAndVertexColorPipeline

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

The packet resolves into two object families sharing a 'this' base with internally consistent fields, plus three free-standing functions whose owner object is unidentified. Family A (SurfaceFormatDecoder) owns format code at +0x0, pixel/palette buffers at +0x4/+0x8, dimensions at +0xC/+0x10, stride at +0x30, ownership flags at +0x38/+0x3C, the decode-request flag at +0x40, the descriptor/candidate fields at +0x44/+0x48, and a linked surface list rooted at +0x4C/+0x50; its methods are the DDS-header parser (0x00501992), the stream-based media-surface initializer (0x0050210E), the seven-candidate format negotiator (0x00502A15) and, with GUESS membership, the unconditional triple-dword initializer (0x00502C12). Family B (VertexColorEncoder) owns destination format selector at +0x8, state flag at +0x10, data pointer at +0x18, constant base at +0x2C, source format selector at +0x1048, output pointer at +0x104C, element count at +0x1058, and stride at +0x1064/+0x1068; its methods are the vertex-format converter (0x00506CE2), the temporary-state wrapper (0x00507779), and the RGB/ARGB color packers (0x005078B5 through 0x005082D1). A separate GUESS SurfaceNode layout describes the linked-list nodes finalized by the negotiator. Three functions resist family assignment: the render-feature dispatcher (0x005038C0) writes two global handler slots, ColorGlobalValueStore (0x00507473) is a free helper publishing the shared scratch global dword_8B009C, and ContactManifoldCleanup (0x00507845) scans a caller-provided record array against this+0x1C..0x28 — it shares the +0x1058 count offset with the encoder family but common ownership is not evidenced.

## Function roles

- `0x00501992` **SurfaceFormatDecoder** — DDS-style header decoder: validates a compact 18-byte header, resolves the internal surface format code from bit-depth bytes, optionally expands a palette into this+0x8, and either aliases (fast path, this+0x38=0) or allocates+decodes the surface row-by-row into this+0x4 (this+0x38=1).
- `0x0050210E` **SurfaceFormatDecoder** — Stream-based media-surface initializer: validates input, creates a versioned subsystem under a setjmp error frame, parses format metadata, maps raw format identifiers to internal codes and 16-bpp FOURCC literals, allocates the pixel-data buffer and row-pointer table, and for paletted formats builds a gamma-corrected 256-entry RGBA table.
- `0x00502A15` **SurfaceFormatDecoder** — Seven-candidate texture-format dispatcher: tries BMP, image-texture, DDS-header, stream, DDS-surface, PPM and DDS-validate decoders in priority order, frees buffers/surface nodes owned by this on failure, then populates the output descriptor and finalizes the linked surface list. Returns -2005529767 when all candidates fail.
- `0x00502C12` **SurfaceFormatDecoder** — Unconditional initializer writing zero to the first three dwords of the owning object and returning the this pointer; offset overlap with the format/buffer fields of SurfaceFormatDecoder is suggestive but the owning struct is unidentified (GUESS membership).
- `0x005038C0` **UnknownObject** — Render-feature dispatcher: selects one of two handler sets from a predicate call, installs the chosen handler into global dispatch slots off_5D76C0 and off_5D76C4, then invokes it and returns its result.
- `0x00506CE2` **VertexColorEncoder** — Per-vertex format converter: converts 4-float elements between normalized/signed/direct coordinate ranges based on the destination selector at this+0x8 and the source selector at this+0x1048; writes into this+0x104C and returns it.
- `0x00507473` **UnknownObject** — Shared color/texture scratch-store helper: publishes the incoming value into dword_8B009C and returns it; all static callers are color/texture conversion helpers that use it to publish a value to the shared global.
- `0x00507779` **VertexColorEncoder** — Temporary-vertex-state wrapper: saves element count, stride, data/constant pointers and flag, installs single-element temporary state, optionally runs DirectXVertexBufferFormatConversion, invokes two vtable methods (+8 and +4), then restores all saved fields and returns the saved flag.
- `0x00507845` **UnknownObject** — Contact-record scanner: zeroes every 16-byte record in the caller-provided array a2 whose four float components match the reference components at this+0x1C..0x28, bounded by the count at this+0x1058. Owner object unidentified; the shared +0x1058 offset with the encoder family is not proof of common ownership.
- `0x005078B5` **VertexColorEncoder** — Vertex-color to 8-bit RGB conversion: per vertex scales three float channels by 255.0 (with base offset) and writes consecutive R,G,B bytes; returns the shared scratch global.
- `0x005079A1` **VertexColorEncoder** — Vertex-color to packed 32-bit color conversion: per vertex scales four float channels by 255.0 and packs them into one 32-bit word; returns the shared scratch global.
- `0x00507AC4` **VertexColorEncoder** — Vertex-color to XRGB8888 packing: scales RGB channels by 255.0 with a cycling four-float bias and packs b|(g<<8)|(r<<16) per vertex; returns the shared scratch global.
- `0x00507CC6` **VertexColorEncoder** — Vertex-color to RGB555 packing: scales RGB channels by 31.0 with a cycling bias and packs r<<10|g<<5|b per vertex; returns the shared scratch global.
- `0x00507DC7` **VertexColorEncoder** — Vertex-color to ARGB1555 texture-word packing: scales RGB by 31.0, takes the alpha channel unscaled, and packs a<<15|r<<10|g<<5|b per vertex; returns the shared scratch global.
- `0x00507EE4` **VertexColorEncoder** — Vertex-color to ARGB4444 packing: scales all four channel floats by 15.0 with a base offset and packs four 4-bit fields per 16-bit word; returns the shared scratch global.
- `0x00508007` **VertexColorEncoder** — Vertex-color to RGB332 byte packing: scales R/G by 7.0 and B by 3.0 with a base offset and emits one packed byte per vertex; returns the shared scratch global.
- `0x00508105` **VertexColorEncoder** — Single-channel vertex color to byte conversion: scales the fourth channel float by 255.0, adds a base color, truncates, and writes one byte per vertex; returns the shared scratch global.
- `0x005081AE` **VertexColorEncoder** — Vertex-color to ARGB8332 packing: quantizes R/G by 7.0, B by 3.0 and A by 255.0 (each plus a per-vertex dither offset) and packs a 16-bit word per vertex; returns the shared scratch global.
- `0x005082D1` **VertexColorEncoder** — Vertex-color to 12-bit RGB packing: scales the first three channel floats by 15.0 with a base offset and packs three 4-bit fields per 16-bit word; returns the shared scratch global.

## Proposed classes

### SurfaceFormatDecoder

Decodes raw image/surface buffers into a normalized surface description: format code, pixel and palette buffers with ownership flags, dimensions, stride, a decode-request flag, and a linked surface list. Methods cover the DDS-header parser, the stream-based media-surface initializer, the seven-candidate format negotiator and, with GUESS membership, a triple-dword zero initializer.

Methods: `0x00501992`, `0x0050210E`, `0x00502A15`, `0x00502C12`

- `this+0x00000000` `int format_code` (read_write, DERIVED)
- `this+0x00000004` `void* pixel_buffer` (read_write, DERIVED)
- `this+0x00000008` `unsigned char* palette_buffer` (read_write, DERIVED)
- `this+0x0000000C` `unsigned int width` (read_write, DERIVED)
- `this+0x00000010` `unsigned int height` (read_write, DERIVED)
- `this+0x00000014` `unsigned int depth_or_surface_count` (read_write, GUESS)
- `this+0x00000018` `unsigned int zeroed_format_field` (write, GUESS)
- `this+0x0000001C` `unsigned int zeroed_format_field` (write, GUESS)
- `this+0x00000020` `unsigned int finalized_width` (write, DERIVED)
- `this+0x00000024` `unsigned int finalized_height` (write, DERIVED)
- `this+0x00000028` `unsigned int zeroed_format_field` (write, GUESS)
- `this+0x0000002C` `unsigned int saved_stride_or_mip` (write, GUESS)
- `this+0x00000030` `unsigned int row_stride` (write, DERIVED)
- `this+0x00000034` `unsigned int unknown_zero` (write, GUESS)
- `this+0x00000038` `unsigned int owns_pixel_buffer` (read_write, DERIVED)
- `this+0x0000003C` `unsigned int owns_palette` (read_write, DERIVED)
- `this+0x00000040` `unsigned int decode_surface_flag` (read_write, DERIVED)
- `this+0x00000044` `unsigned int descriptor_format_code` (read_write, DERIVED)
- `this+0x00000048` `unsigned int candidate_index` (read_write, DERIVED)
- `this+0x0000004C` `void* surface_head` (read_write, DERIVED)
- `this+0x00000050` `void* next_surface` (read_write, DERIVED)
- `this+0x00000098` `unsigned int unknown_read_field` (read, UNKNOWN)

### VertexColorEncoder

Converts per-vertex float color data between normalized/signed/direct coordinate ranges and packs the result into color words of several depths (RGB332, RGB555, ARGB1555, ARGB4444, ARGB8332, 12-bit RGB, 24-bit RGB bytes, 32-bit ARGB). All members share the format-conversion gate at +0x1048, the constant/color base at +0x2C, the element count at +0x1058, and the publish-to-global return convention.

Methods: `0x00506CE2`, `0x00507779`, `0x005078B5`, `0x005079A1`, `0x00507AC4`, `0x00507CC6`, `0x00507DC7`, `0x00507EE4`, `0x00508007`, `0x00508105`, `0x005081AE`, `0x005082D1`

- `this+0x00000000` `void* vtable_pointer` (read, UNKNOWN)
- `this+0x00000008` `unsigned int destination_format_selector` (read, DERIVED)
- `this+0x00000010` `unsigned int state_flag` (read_write, GUESS)
- `this+0x00000018` `void* data_pointer` (read_write, DERIVED)
- `this+0x0000002C` `float* constant_data_base` (read_write, DERIVED)
- `this+0x00001048` `unsigned int source_format_selector` (read_write, DERIVED)
- `this+0x0000104C` `void* output_buffer_pointer` (read_write, DERIVED)
- `this+0x00001058` `unsigned int element_count` (read, DERIVED)
- `this+0x00001064` `unsigned int row_stride` (read_write, DERIVED)
- `this+0x00001068` `unsigned int saved_stride` (read_write, GUESS)

### SurfaceNode

Linked-list node describing one decoded surface; its next pointer lives at +0x4C. The finalization loop in DirectXSurfaceFormatNegotiation copies +0xC/+0x10 to +0x20/+0x24, saves +0x14 into +0x2C, and zeroes +0x18/+0x1C/+0x28. The packet labels node accesses with the same 'this' base it uses for the decoder object, and the dereferenced next pointer is evidenced as field:*(this+0x4C):0x0000004C, so the node layout is modelled here on base 'this' as the decoder struct reused as a chained node (GUESS); no method of the packet operates as a SurfaceNode member.

Methods: 

- `this+0x0000000C` `unsigned int width` (read, DERIVED)
- `this+0x00000010` `unsigned int height` (read, DERIVED)
- `this+0x00000014` `unsigned int depth_or_count` (read, GUESS)
- `this+0x00000018` `unsigned int zeroed_field` (write, DERIVED)
- `this+0x0000001C` `unsigned int zeroed_field` (write, DERIVED)
- `this+0x00000020` `unsigned int finalized_width` (write, DERIVED)
- `this+0x00000024` `unsigned int finalized_height` (write, DERIVED)
- `this+0x00000028` `unsigned int zeroed_field` (write, DERIVED)
- `this+0x0000002C` `unsigned int saved_depth` (write, DERIVED)
- `this+0x0000004C` `void* next_node` (read_write, DERIVED)

## Compatibility contracts

- **SurfaceDecoderReturnCodeContract** — Each of the seven format candidates must return a non-negative status on success and a negative status on failure; the negotiator retries the next candidate on failure and returns -2005529767 when all seven fail. A replacement must preserve the >=0-success convention and the retry-until-success loop.
- **SurfaceBufferOwnershipDiscipline** — this+0x38/this+0x3C flag whether the pixel/palette buffers at this+0x4/this+0x8 are owned; the negotiator frees an owned buffer on failed decode and the DDS fast path aliases the caller's buffer with ownership cleared. A replacement must keep the ownership flags in lockstep with frees to avoid double-free or leak.
- **SharedColorScratchGlobal** — dword_8B009C is a shared scratch/state global written by ColorGlobalValueStore and returned by every vertex-color packer; a replacement exposing the same encoder cluster must preserve this publish-and-return convention so callers that read the global see the same value the packers published.
- **SurfaceFormatCodeTable** — The internal surface format codes 20/21/24/25/41/50/51 and the 16-bpp FOURCC-style literals 909201952/909201985/909200416/909200449 are written into the decoded object's format field and consumed by later stages; a replacement decoder/encoder pipeline must preserve the same code values.

## Unresolved

- DDS-header layout deviates from the standard 124-byte DDS header; the exact meanings of header bytes a2[0]/a2[1]/a2[2]/a2[3]/a2[5]/a2[7]/a2[16]/a2[17] are inferred from use, not confirmed.
- Internal format codes 20/21/24/25/41/50/51 (24bpp/32bpp/RGB565/RGB555/two block-compressed variants) are DERIVED from switch chains; their relation to standard DDS fourcc values is not established.
- this+0x34 is always written 0; its role is unknown. this+0x14 is set to 1; whether it is a surface count or mip count is unknown.
- this+0x40 is read-only inside DDSHeaderParsing and written by the negotiator; whether it selects surface/mip decoding is unknown.
- The DDS fast path leaves this+0x4 pointing into the caller's buffer with this+0x38==0; ownership discipline with the negotiator is not fully resolved.
- v39 = a2[2] & 8 is always 0 due to the header guard, so the run-length decode branch in DDSHeaderParsing is dead in practice; its intended semantics are unconfirmed.
- Seven read-only globals (0x0059E420, 0x0059E880, 0x005ADB58, 0x005ADB60, 0x005ADB68, 0x005ADB70, 0x005ADB78) are flagged by packet facts but appear nowhere in the raw decompiled source text of the stream initializer.
- The ABI lead name Graphics_Driver_Hardware_Cap_Detection (LEGACY) conflicts with the media-surface/stream semantics of InitializeMediaSurfaceFromStream and is treated as a stale label.
- The mode selector v55 and its match against the ShortComputation_2144 output are inferred from the dispatch/compare pattern only.
- The gamma scale floats at v57+304 and v57+308 are read via raw offsets with no named field references.
- The CameraRotationStateSetter name does not obviously match a call passing 2.2 and a converted double; the name may be stale.
- In the negotiator, semantics of this+0x18/0x1C/0x28 (zeroed during finalization) are unconfirmed; candidate 3 (sub_50210E) has no name and its decode role is unknown; the relationship between this+0x4C and this+0x50 chains is not fully resolved.
- TripleDwordZeroInit's owning struct is unidentified; membership in SurfaceFormatDecoder is GUESS based only on offset overlap.
- RenderFeatureDispatch: the roles of the two dispatch slots off_5D76C0 versus off_5D76C4 storing the same handler, and the meaning of the sub_50FC7D predicate, are unknown.
- ContactManifoldCleanup: the record array is passed in as a2 with no evidence of where it lives in the owning object; the 31 recorded texture/vertex-decoder callers look like a call-graph misjoin; the meaning of the four reference components at this+0x1C..0x28 (contact position versus RGB) is not evidenced; the shared +0x1058 count offset with the encoder family does not prove common ownership.
- ColorGlobalValueStore: v1 is an uninitialized stack local (register-passed parameter not recovered); the purpose of dword_8B009C is not determinable from this packet alone.
- processWithTemporaryVertexState: base 'obj' aliases 'this'; the two vtable methods at offsets +8 and +4 have no packet-resolved targets; the meaning of unk_5D76C8 and the stack-local buffer layout is unresolved.
- All color packers share the same uncertainties: the destination word/byte pointer is register-derived with no visible initialization, the float globals (0x0059E43C, 0x0059E450, 0x0059E800, 0x0059E478, 0x0059E864, 0x0059FEC8, 0x0059E8D8, 0x005ACCD0) are read but absent from the raw pseudocode and only suspected of supplying the scale constants, and the a2/a3 component-index semantics ((a3&3)+8*(a2&3)) are inferred only from mask/shift arithmetic.
- Channel ordering is inferred from statement order only: the packers write R,G,B consecutively and the shift order in the 32-bit packers fixes relative byte order, but which source float maps to which color channel is not confirmed statically.
- In TextureEncode16Bit the alpha channel is not scaled by 31.0; whether that is intentional (1-bit alpha) or a decompiler artifact is not evidenced.
- FloatVertexColorsToARGB8332's existing_analysis labels for the scale globals (SteeringCenterBoost, ColorQuantScale, AlphaChannelMultiplier) are DERIVED and unverified.
