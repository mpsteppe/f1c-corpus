# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

This scope covers 41 validated functions spanning four runtime concerns. The largest family is 32 thiscall constructors of DirectX texture/surface/render-buffer objects, all invoked from DirectXTextureSurfaceFactoryDispatchingFourCCCod (0x0050B8A9) and each performing a shared base initialization through one of three helpers (DirectXTextureCreationWithMipmapChain 0x00507496, DirectXTextureSurfaceFormatInitialization 0x0050AFE2, or RenderBufferVertexAllocator 0x0050A7E1) followed by installation of a distinct vtable pointer at this+0x0. The distinct vtable per constructor implies a distinct (unnamed) class each, but only the shared construction pattern is evidenced. Two free CPU feature detectors (0x0050FD4E SSE/SSE2, 0x005171D0 MMX/3DNow-class/AMD) wrap CPUID in SEH; they use incompatible flag-bit schemes and are grouped only by shared concern. One size-parameterized zero-allocator (0x00517E43) dispatches request codes 1 and 2 to 412- and 64-byte blocks. The MPEG audio decoder open path (0x0052E090, name derived from the aCmpegbaseOpenG string, GUESS owner 'CMpegBase') performs deferred deactivation, sync-word storage, audio-device assertion and buffer timing/sizing. Four functions (0x00534D50, 0x00534E70, 0x00535560, 0x00535620) implement a buffered-stream block reader with byte reader, block-header parser, dword packer and per-frame context reset. A vtable-destructor thunk (0x0052D8C0) forwards to an un-evidenced VirtualCleanup. All grouping into classes is DERIVED/GUESS: no RTTI, vtable-member or runtime ownership evidence exists in this packet.

## Function roles

- `0x0050AB35` **DirectXTextureObject** — Variant texture constructor; delegates to DirectXTextureCreationWithMipmapChain (size 0x10, flag 1) then installs vtable 0x005ADC28 at this+0x0.
- `0x0050AE22` **DirectXTextureObject** — Texture constructor (size 0x10, flag 1); installs vtable 0x005ADC4C.
- `0x0050AE3E` **DirectXTextureObject** — Texture constructor (size 8, flag 1); installs vtable 0x005ADC5C.
- `0x0050AE5A` **DirectXTextureObject** — Texture constructor (size 8, flag 1); installs vtable 0x005ADC6C.
- `0x0050AE76` **DirectXTextureObject** — Texture constructor (size 0x10, flag 1); installs vtable 0x005ADC7C.
- `0x0050AE92` **DirectXTextureObject** — Texture/render constructor (size 0x10, flag 1); installs vtable 0x005ADC8C.
- `0x0050AF3B` **DirectXTextureObject** — Texture constructor (size 0x20, flag 1); installs vtable 0x005ADC9C.
- `0x0050AFC6` **DirectXTextureObject** — Texture constructor (size 0x20, flag 1); installs vtable 0x005ADCAC.
- `0x0050B1D4` **DirectXTextureObject** — Texture constructor (size 0x10, flag 1); installs vtable 0x005ADCBC.
- `0x0050B1F0` **DirectXTextureObject** — Constructor-style initializer (size 8, flag 1); installs vtable 0x005ADCCC.
- `0x0050B20C` **DirectXTextureObject** — Constructor-style initializer variant (size 8, flag 1); installs vtable 0x005ADCDC.
- `0x0050B228` **DirectXTextureObject** — Texture constructor (size 0x10, flag 1); installs vtable 0x005ADCEC.
- `0x0050B260` **DirectXTextureObject** — Texture constructor (size 8, flag 1); installs vtable 0x005ADCFC.
- `0x0050B37D` **DirectXTextureObject** — Constructor-style initializer (size 0x10, flag 2); installs vtable 0x005ADD0C.
- `0x0050B399` **DirectXTextureObject** — Render subsystem constructor (size 0x10, flag 2); installs vtable 0x005ADD1C.
- `0x0050B3B5` **DirectXTextureObject** — Render format constructor (size 0x20, flag 2); installs vtable 0x005ADD2C.
- `0x0050B3D1` **DirectXTextureObject** — Texture sub-constructor (size 0x20, flag 3); installs vtable 0x005ADD3C.
- `0x0050B3ED` **DirectXTextureObject** — Texture constructor (size 0x20, flag 2); installs vtable 0x005ADD4C.
- `0x0050B409` **DirectXTextureObject** — Texture sub-constructor (size 0x20, flag 2); installs vtable 0x005ADD5C.
- `0x0050B42A` **DirectXTextureObject** — Texture sub-constructor (size 0x20, flag 2); installs vtable 0x005ADD6C.
- `0x0050B446` **DirectXTextureObject** — Texture sub-constructor (size 0x10, flag 1); installs vtable 0x005ADD7C.
- `0x0050B462` **DirectXTextureObject** — Texture sub-constructor (size 0x10, flag 1); installs vtable 0x005ADD8C.
- `0x0050B727` **DirectXTextureObject** — Texture sub-constructor (size 0x20, flag 1); installs vtable 0x005ADD9C.
- `0x0050B743` **DirectXTextureObject** — Surface/texture sub-constructor (size 0x30, flag 1); installs vtable 0x005ADDAC.
- `0x0050B77B` **DirectXTextureObject** — Texture sub-constructor (size 0x40, flag 1); installs vtable 0x005ADDBC.
- `0x0050B797` **DirectXSurfaceFormatObject** — Surface-format sub-constructor; delegates to DirectXTextureSurfaceFormatInitialization then installs vtable 0x005ADDCC.
- `0x0050B7CB` **DirectXSurfaceFormatObject** — Surface-format sub-constructor; delegates to DirectXTextureSurfaceFormatInitialization then installs vtable 0x005ADDDC.
- `0x0050B7E3` **DirectXSurfaceFormatObject** — D3D texture2D sub-constructor; delegates to DirectXTextureSurfaceFormatInitialization then installs vtable 0x005ADDEC.
- `0x0050B7FB` **DirectXSurfaceFormatObject** — Surface sub-constructor; delegates to DirectXTextureSurfaceFormatInitialization then installs vtable 0x005ADDFC.
- `0x0050B813` **DirectXSurfaceFormatObject** — Surface sub-constructor; delegates to DirectXTextureSurfaceFormatInitialization then installs vtable 0x005ADE0C.
- `0x0050B879` **RenderBufferObject** — Sub-constructor; delegates to RenderBufferVertexAllocator then installs vtable 0x005ADE1C.
- `0x0050B891` **RenderBufferObject** — Shader/render sub-constructor; delegates to RenderBufferVertexAllocator then installs vtable 0x005ADE2C.
- `0x0050FD4E` **CpuCapabilityProbe** — SEH-guarded CPUID feature detection; returns flag bitmask with 0x4 (SSE) and 0x8 (SSE2); called by OSVersionDetection.
- `0x005171D0` **CpuCapabilityProbe** — Free-function CPUID vendor/MMX/3DNow-class detection with AMD-specific bits; separate flag-bit scheme; called by 0x005172A5.
- `0x00517E43` **free_function** — Sized zero-initializing allocator; dispatch code 1 -> 412-byte block, 2 -> 64-byte block, else NULL.
- `0x0052D8C0` **free_function** — Vtable-destructor thunk forwarding this to VirtualCleanup; returns its char result unchanged.
- `0x0052E090` **CMpegBase** — MPEG audio decoder open path: deferred deactivation, sync-word store, audio-device assert, decoder init, buffer timing/sizing.
- `0x00534D50` **BufferedStreamReader** — Block-header parser over buffered stream: magic bytes from 0x005DA780, type byte == 8, flags mask 0xE0, payload flags 0x2/0x4/0x8/0x10, status -3 on header failure.
- `0x00534E70` **BufferedStreamReader** — Single-byte buffered stream reader with TLS error slot, 16KB refill via 0x0058803F, EOF/error handling.
- `0x00535560` **BufferedStreamReader** — Reads four stream bytes and packs a little-endian dword; writes error -3 on fourth-byte EOF.
- `0x00535620` **BufferedStreamReader** — Per-frame context reset: null guards return -2, zeroes counters, seeds sub-context field, calls StateResetWithCallback.

## Proposed classes

### DirectXTextureObject

DirectX texture/surface objects constructed by base-init via DirectXTextureCreationWithMipmapChain (0x00507496) followed by per-variant vtable installation at this+0x0. The packet evidences 25 constructor variants with distinct vtable identities; the concrete class names behind those vtables are unknown.

Methods: `0x0050AB35`, `0x0050AE22`, `0x0050AE3E`, `0x0050AE5A`, `0x0050AE76`, `0x0050AE92`, `0x0050AF3B`, `0x0050AFC6`, `0x0050B1D4`, `0x0050B1F0`, `0x0050B20C`, `0x0050B228`, `0x0050B260`, `0x0050B37D`, `0x0050B399`, `0x0050B3B5`, `0x0050B3D1`, `0x0050B3ED`, `0x0050B409`, `0x0050B42A`, `0x0050B446`, `0x0050B462`, `0x0050B727`, `0x0050B743`, `0x0050B77B`

- `this+0x00000000` `void* vtable_ptr` (write, DERIVED)

### DirectXSurfaceFormatObject

DirectX surface-format objects constructed by base-init via DirectXTextureSurfaceFormatInitialization (0x0050AFE2) followed by per-variant vtable installation at this+0x0. Five variants with distinct vtable identities; concrete class names unknown.

Methods: `0x0050B797`, `0x0050B7CB`, `0x0050B7E3`, `0x0050B7FB`, `0x0050B813`

- `this+0x00000000` `void* vtable_ptr` (write, DERIVED)

### RenderBufferObject

Render-buffer/vertex objects constructed by RenderBufferVertexAllocator (0x0050A7E1) followed by vtable installation at this+0x0. Two variants with distinct vtable identities; concrete class names unknown.

Methods: `0x0050B879`, `0x0050B891`

- `this+0x00000000` `void* vtable_ptr` (write, DERIVED)

### BufferedStreamReader

Buffered binary stream reader with single-byte access, block-header parsing, dword packing and per-frame context reset. Shared fields: cursor, remaining/consumed counter, status/error code, mode/EOF flag, 16KB buffer pointer, stream handle.

Methods: `0x00534D50`, `0x00534E70`, `0x00535560`, `0x00535620`

- `this+0x00000000` `byte* buffer_cursor` (read_write, DERIVED)
- `this+0x00000004` `int32 remaining_or_consumed_counter` (read_write, DERIVED)
- `this+0x00000008` `int32 counter_a` (read_write, GUESS)
- `this+0x00000014` `int32 counter_b` (read_write, GUESS)
- `this+0x00000018` `int32 counter_c` (read_write, GUESS)
- `this+0x0000001C` `void* sub_context_ptr` (read, DERIVED)
- `this+0x00000028` `int32 mode_flag` (read, GUESS)
- `this+0x00000038` `int32 status_or_error_code` (read_write, DERIVED)
- `this+0x0000003C` `int32 mode_or_eof_flag` (read_write, GUESS)
- `this+0x00000040` `byte* buffer_ptr` (read, DERIVED)
- `this+0x00000044` `void* stream_handle` (read, DERIVED)
- `this+0x00000058` `int32 eof_or_error_flag` (write, DERIVED)

### CMpegBase

MPEG audio decoder base (name derived from the aCmpegbaseOpenG function-name string; owner is GUESS, not confirmed by vtable or RTTI evidence). The open path performs deferred deactivation, sync-word storage, audio-device validation and buffer timing/sizing.

Methods: `0x0052E090`

- `this+0x0000248C` `uint32 bytes_per_buffer_basis` (read, GUESS)
- `this+0x000024A0` `uint32 frames_per_buffer` (write, GUESS)
- `this+0x000024A4` `void* bitstream_buffer_ptr` (write, DERIVED)
- `this+0x000024B0` `uint32 total_buffer_bytes` (write, GUESS)
- `this+0x000024D4` `uint32 timing_numerator_scale` (read, GUESS)
- `this+0x000024D8` `uint32 timing_term_1` (read, GUESS)
- `this+0x000024DC` `uint32 timing_term_2` (read, GUESS)
- `this+0x000024E0` `uint32 timing_divisor` (read, GUESS)
- `this+0x000024EC` `uint8 deferred_deactivation_flag` (read_write, DERIVED)
- `this+0x000024F0` `uint32 sync_word` (write, DERIVED)

### CpuCapabilityProbe

x86 CPU instruction-set detection. Groups two free functions by shared concern only; each uses a different CPUID scheme and a different returned flag-bit encoding. No object state is evidenced.

Methods: `0x0050FD4E`, `0x005171D0`


## Compatibility contracts

- **DirectXTextureConstructionContract** — A replacement executable must reproduce the object-construction protocol used by DirectXTextureSurfaceFactoryDispatchingFourCCCod's callees: base initialization through one of three helpers (0x00507496, 0x0050AFE2, 0x0050A7E1) followed by installation of a specific vtable pointer at offset +0x0. Each of the 32 constructors binds a distinct vtable identity (0x005ADC28..0x005ADE2C range), so the replacement must preserve 32 distinguishable object types regardless of the concrete class names.
- **BufferedBlockFormat** — The block-header parser (0x00534D50) consumes a framed stream: up to two magic bytes matched against dword_5DA780; a type byte that must equal 8; a flags byte whose upper bits (mask 0xE0) must be clear; payload fields selected by flag bits 0x2/0x4/0x8/0x10; a -1 byte acts as an end marker; a malformed header sets status (this+0x38) to -3 and skips payload parsing. The byte reader (0x00534E70) signals EOF via the flag at this+0x3C and records error -1 in this+0x38 on a stream-status error.
- **CpuFeatureFlagEncoding** — Two independent CPUID-based detectors must keep their return encodings distinct: DetectCPUSSEFeatures (0x0050FD4E) returns a bitmask with 0x4 = SSE and 0x8 = SSE2, with CPUID execution protected by an SEH handler so feature detection degrades gracefully on CPUs without CPUID; DetectCpuCapabilities (0x005171D0) uses a separate scheme (0x02 baseline, 0x20 MMX-class, 0x04 extended-leaf presence, 0x80 3DNow-class, 0x100/0x200 AMD-specific) keyed off the 'AuthenticAMD' vendor match.
- **SizedZeroAllocatorContract** — AllocAndZeroInit (0x00517E43) accepts request codes 1 and 2 only: code 1 allocates and zeroes a 412-byte block, code 2 a 64-byte block; any other code returns NULL without allocating, and a failed allocation returns NULL without zeroing.
- **MpegOpenSequence** — CMpegBase::Open (0x0052E090) must: run deferred deactivation if the flag at this+0x24EC is set, clear the bitstream pointer (this+0x24A4), store the sync word (this+0x24F0), validate the audio device (failure asserts through the function-pointer table at off_5DA714 and returns -1), then re-initialize decoder internals, recompute network-buffer timing and frames-per-buffer sizing, and return 0 on success.

## Unresolved

- Each of the 32 DirectX constructors installs a distinct vtable pointer, which implies 32 distinct classes, but none of the class names, vtable member layouts, or RTTI is evidenced in this packet; they are grouped into three classes purely by shared base-init helper.
- Semantics of argument a2 forwarded to DirectXTextureCreationWithMipmapChain / DirectXTextureSurfaceFormatInitialization / RenderBufferVertexAllocator are caller-supplied and undefined in this packet.
- Meaning of the size literals (8, 0x10, 0x20, 0x30, 0x40) and flag literals (1, 2, 3) passed to 0x00507496 is decided inside that callee; whether size encodes object allocation size, surface dimension, or resource class is unresolvable here.
- Whether DirectXTextureObject, DirectXSurfaceFormatObject and RenderBufferObject share a common base class is not evidenced; equal offset +0x0 vtable slots across these bases are not proof of shared ownership.
- The single BufferedStreamReader class groups four functions by overlapping field usage, but object identity between the byte reader, block parser and context reset is inferred, not proven.
- Field this+0x3C is described as a mode flag by ReadBlockHeader and as the EOF flag by the byte reader; the exact dual role is unresolved.
- ResetContextStateWithCallback writes 7 or 0 into the sub-context object's field at offset +0xC based on that object's own field, while packet guard facts instead attribute the choice to the flag at this+0x28; raw source (the +0xC ternary) is kept primary and the 0x28 flag's role is unverified.
- The buffered-stream byte reader references a field at this+0x4C (allocator/uncompressed-size per prior analysis) that is not touched by any function in this packet.
- CMpegBase is a GUESS owner derived only from the aCmpegbaseOpenG string; the assert/abort targets behind off_5DA714 and off_5DA718 are not visible in the packet, and the 0x24D4/0x24D8/0x24DC/0x24E0/0x248C timing-field semantics are inferred from their arithmetic roles only.
- Global aSDS_0 (0x005DA564) participates in the Open extraction but does not appear in the raw decompiled text; its role is unresolved.
- AllocAndZeroInit's request codes 1 and 2 map to 412/64-byte blocks but the concrete objects they back depend on callers 0x005118E6 and 0x00513D3D, which are outside this packet.
- VTableDestructorWrapperWithNullCheck (0x0052D8C0) forwards to a VirtualCleanup routine whose address and owner are not evidenced; the name mentions a null check but the thunk body performs none.
- DetectCPUSSEFeatures and DetectCpuCapabilities use incompatible returned-flag encodings and appear in different call chains; their grouping into CpuCapabilityProbe is a GUESS by shared concern, not evidence of a common module.
- In DetectCPUSSEFeatures the 'GenuineIntel' literal is copied into a stack vendor buffer but no comparison against CPUID vendor registers is visible, so the buffer's consumer is unknown; the SEH filter/continuation targets 0x0050FD9A and 0x0059C724 are not modeled.
- F_4BitFieldPack (0x00535560) packs four stream bytes rather than bit fields; the canonical name is likely a legacy artifact, and signedness of the packed dword for callers is unknown.
- BufferedStreamByteReader's cursor reset reuses the stream-handle slot as a pointer seed; exact buffer ownership is unresolved.
