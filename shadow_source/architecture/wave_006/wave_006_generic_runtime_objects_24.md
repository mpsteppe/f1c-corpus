# GenericRuntimeObjectLayer

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Eighteen generic runtime objects for media/surface processing. PlaneVisibilityRangeSetup (0x0051B7CD) validates a per-plane visibility range configuration, fills a 256-byte-stride lookup table, and selects one of four plane decoder callbacks. A set of audio/ring-buffer objects cooperate: SoundEffectStateCallback (0x0051BE7D) installs operation pointers (BufferedDataReader 0x0051BDF1 for read, AudioRingBufferManager 0x0051BD61 for write, RenderCommandDispatch 0x0051BCFC for idle) into the ring control block installed by PlaybackBufferAlloc (0x0051BF23); AudioBufferMixing (0x0051BFC0) flushes and copies channel data; AudioSampleStream (0x0051CD53) streams samples with a pending-sample buffer. MediaAudioDecodeDispatch (0x0051C3E2) and allocateComboBoxBuffers (0x0051BC88) allocate descriptor/buffer memory and populate routine tables. TextureCodecModeDispatch (0x0051DFCB), textureContextInit (0x0051E0DC), BlockTextureDecompression (0x0051DCAA) and GridOccupancyBoundingBoxScan (0x0051D247) share a texture codec context at this+0x1A4. ImageResampleFilter (0x0051C2DB), IndexedSurfaceBlit (0x0051C94F) and PtrInitZero (0x0051C091) are pixel/routine helpers; CombinatorialPermutationGenerator (0x0051E1EF) builds mixed-radix permutations. All objects share an allocator vtable at this+0x4 and an error-reporting object via this+0x0; the shared this-relative layout is a hypothesis, not proven ownership.

## Function roles

- `0x0051B7CD` **MediaSurfaceObject** — Validates plane visibility range configuration, fills the 256-byte-stride per-plane lookup table, selects one of four decoder callbacks, and finalizes a decoder output object.
- `0x0051BC88` **MediaSurfaceObject** — Allocates a per-object dispatch state block and per-object 256-byte buffers through the allocator vtable.
- `0x0051BCFC` **RenderCommandDispatcher** — Render pipeline dispatcher: clamps the requested item count and dispatches process and output functions through two function tables.
- `0x0051BD61` **RingBufferManager** — Ring-buffer write path: lazily allocates the backing buffer, copies input samples, zero-fills newly covered regions and wraps on capacity.
- `0x0051BDF1` **RingBufferManager** — Ring-buffer read path: lazily allocates the read buffer, clamps the copy amount and advances/wraps the read position.
- `0x0051BE7D` **SoundPlaybackControl** — Sound-effect state-transition handler that installs ring-buffer operation pointers by state and resets position counters.
- `0x0051BF23` **SoundPlaybackControl** — Allocates the 28-byte playback ring-buffer control block and conditionally the audio data buffer (write or read variant).
- `0x0051BFC0` **MediaSurfaceObject** — Audio channel mixing: flushes active channels when the consumed count reaches the buffer total, then dispatches an indirect copy.
- `0x0051C091` **UnknownObject** — Trivial pointer-initializer helper: zeroes the dword at a4 and returns the pointer; a1/a2/a3 unused.
- `0x0051C2DB` **ImageResampler** — Vertical image resampler blending neighboring rows with a 3:1 weighted convolution; optional interior channel loop.
- `0x0051C3E2` **MediaSurfaceObject** — Allocates the per-surface decode descriptor and selects per-sub-surface copy routines by format flags, scale and channel count.
- `0x0051C94F` **MediaSurfaceObject** — Row-wise per-pixel color transform through four lookup tables; SIMD+scalar hybrid or pure scalar path selected by a global render-mode flag.
- `0x0051CD53` **MediaSurfaceObject** — Streams audio samples with a pending-sample buffer, flushing buffered samples through the block-copy routine or dispatching fresh sample pairs.
- `0x0051D247` **TextureProcessingContext** — Tightens an axis-aligned bounding box by scanning the 16-bit-cell occupancy grid and returns the occupied-cell count.
- `0x0051DCAA` **TextureProcessingContext** — Decompresses block-compressed texture rows with serpentine error diffusion driven by a dither error buffer.
- `0x0051DFCB` **TextureProcessingContext** — Selects and installs the texture codec dispatch pair on the context object and manages dirty-row and row-count clamps.
- `0x0051E0DC` **TextureProcessingContext** — Initializes the texture processing context: allocates the 44-byte context, row-buffer array, palette and dither buffers.
- `0x0051E1EF` **PermutationGenerator** — Generates and advances mixed-radix combinatorial permutations until the target count is exceeded, with optional index remap.

## Proposed classes

### MediaSurfaceObject

Large shared this-relative object behind the decoder/media-surface functions: plane visibility configuration, sub-surface descriptor array, lookup tables, stream sub-struct and texture context slots all live on this layout. The packet presents all of them as this-relative offsets (shared struct layout hypothesis); common ownership across every function is not proven.

Methods: `0x0051B7CD`, `0x0051BC88`, `0x0051BFC0`, `0x0051C3E2`, `0x0051C94F`, `0x0051CD53`

- `this+0x00000020` `int subObjectCount` (read, GUESS)
- `this+0x00000048` `byte blendFilterFlag` (read, GUESS)
- `this+0x0000004C` `int codecMode` (read_write, DERIVED)
- `this+0x00000054` `int pixelCount` (read, GUESS)
- `this+0x0000005A` `byte paletteFlag` (read, GUESS)
- `this+0x0000005C` `int rowWidth` (read, DERIVED)
- `this+0x00000064` `int channelMode` (read, GUESS)
- `this+0x00000070` `int rowCount` (read_write, DERIVED)
- `this+0x00000074` `void* paletteChannelTable0` (read, GUESS)
- `this+0x00000078` `void* paletteChannelTable1` (read, GUESS)
- `this+0x0000007C` `void* paletteChannelTable2` (read, GUESS)
- `this+0x0000008C` `void* planeLookupTableBase` (read, GUESS)
- `this+0x000000C4` `void** subSurfaceDescriptorArray` (read, DERIVED)
- `this+0x000000FC` `int storedResultValue` (read, GUESS)
- `this+0x00000108` `byte unsupportedFormatFlag` (read, GUESS)
- `this+0x0000010C` `int targetWidth` (read, GUESS)
- `this+0x00000110` `int targetHeight` (read, GUESS)
- `this+0x00000114` `int scaleFactor` (read, GUESS)
- `this+0x0000011C` `int paletteBaseOffset` (read, GUESS)
- `this+0x00000120` `int planeCount` (read, DERIVED)
- `this+0x00000124` `void** planeDescriptorArray` (read, DERIVED)
- `this+0x00000168` `int rangeStart` (read_write, DERIVED)
- `this+0x0000016C` `int rangeEnd` (read_write, DERIVED)
- `this+0x00000170` `int modeFlag` (read, DERIVED)
- `this+0x00000174` `int setValue` (read_write, DERIVED)
- `this+0x00000194` `void* decoderOutputObject` (read, GUESS)
- `this+0x00000198` `void* decoderCallbackSlot` (write, DERIVED)
- `this+0x000001A0` `void** copyFunctionTable` (read, GUESS)
- `this+0x000001A4` `void* textureContextPtr` (read, GUESS)
- `this+0x000001A8` `void* colorLookupTable0` (read, GUESS)
- `this+0x000001AC` `void* colorLookupTable1` (read, GUESS)
- `this+0x000001B0` `void* colorLookupTable2` (read, GUESS)
- `this+0x000001B4` `void* colorLookupTable3` (read, GUESS)
- `this+0x000001B8` `int* planeOutputSlotArray` (write, GUESS)
- `this+0x000001BC` `void** paletteGridTable` (read, GUESS)
- `this+0x000001C0` `byte contextDirtyFlag` (read_write, GUESS)
- `this+0x000001C4` `void* ditherErrorBuffer` (read, GUESS)
- `this+0x000001C8` `byte scanToggle` (read_write, GUESS)
- `this+0x000001CC` `void* channelOffsetTable` (read, GUESS)
- `this+0x000001DC` `int decodedValue` (write, GUESS)
- `this+0x000001F8` `int consumedCount` (read_write, GUESS)
- `this+0x000001FC` `int remainingCount` (read_write, GUESS)
- `*(this+0x124)+0x00000004` `int planeIndex` (read, DERIVED)
- `*(this+0x124)+0x00000014` `int paramIndexNoBitstream` (read, GUESS)
- `*(this+0x124)+0x00000018` `int paramIndexBitstream` (read, GUESS)
- `*(this+0xC4)+0x00000024` `int scaledWidth` (write, GUESS)
- `*(this+0xC4)+0x00000028` `int channelCount` (read, GUESS)
- `*(this+0xC4)+0x00000030` `byte elementFlag` (read, GUESS)
- `*(this+0xC4)+0x00000050` `void* elementBufferPtr` (write, GUESS)
- `*(this+0x19C)+0x00000004` `void* streamOpFnPtr` (read, GUESS)
- `*(this+0x19C)+0x0000000C` `void* sampleDispatchFnPtr` (read, GUESS)
- `*(this+0x19C)+0x00000020` `int* pendingSampleBuffer` (read_write, GUESS)
- `*(this+0x19C)+0x00000024` `byte pendingSampleFlag` (read_write, GUESS)
- `*(this+0x19C)+0x00000028` `int blockCopySize` (read, GUESS)
- `*(this+0x19C)+0x0000002C` `int streamRemainingCount` (read_write, GUESS)

### RingBufferManager

Read and write paths of the audio ring buffer. The 28-byte control block is reached at this+0x188 and also presented by the packet as this-relative slots (this+0x190..0x1A0); slot 1 holds the operation pointer installed by SoundEffectStateCallback.

Methods: `0x0051BD61`, `0x0051BDF1`

- `this+0x00000188` `void* ringControlBlockPtr` (read_write, DERIVED)
- `*(this+0x188)+0x00000004` `void* operationPtr` (read_write, GUESS)
- `*(this+0x188)+0x00000008` `int sizeHint` (read, GUESS)
- `*(this+0x188)+0x0000000C` `void* dataPtr` (read_write, GUESS)
- `*(this+0x188)+0x00000010` `int capacity` (read_write, GUESS)
- `*(this+0x188)+0x00000014` `int cursor` (read_write, GUESS)
- `*(this+0x188)+0x00000018` `int position` (read_write, GUESS)
- `this+0x00000190` `int ringSlotSizeHint` (read, GUESS)
- `this+0x00000194` `void* ringSlotDataPtr` (read_write, GUESS)
- `this+0x00000198` `int ringSlotCapacity` (read_write, GUESS)
- `this+0x0000019C` `int ringSlotCursor` (read_write, GUESS)
- `this+0x000001A0` `int ringSlotPosition` (read_write, GUESS)
- `this+0x00000060` `int perCallSizeCeiling` (read, GUESS)

### SoundPlaybackControl

Installs and allocates the playback ring-buffer control block: SoundEffectStateCallback selects the operation pointer by state and PlaybackBufferAlloc allocates the block and the audio data buffer.

Methods: `0x0051BE7D`, `0x0051BF23`

- `this+0x0000004A` `byte variantFlag` (read, GUESS)
- `this+0x0000005C` `int bufferBytes` (read, GUESS)
- `this+0x00000060` `int bufferSizeHint` (read, GUESS)
- `this+0x00000064` `int bufferMultiplier` (read, GUESS)
- `this+0x00000110` `int alignmentRequirement` (read, GUESS)

### RenderCommandDispatcher

Generic render pipeline dispatcher reading a render-state block at this+0x188 and dispatching through two function tables (process at this+0x19C, output at this+0x1A4); also installable as the idle ring-buffer operation pointer.

Methods: `0x0051BCFC`

- `this+0x00000188` `void* renderStateBlock` (read, GUESS)
- `*(this+0x188)+0x0000000C` `int dataIdentifier` (read, GUESS)
- `*(this+0x188)+0x00000010` `int maxPerCall` (read, GUESS)
- `this+0x0000019C` `void** processFnTable` (read, GUESS)
- `*(this+0x19C)+0x00000004` `void* processFn` (read, GUESS)
- `this+0x000001A4` `void** outputFnTable` (read, GUESS)
- `*(this+0x1A4)+0x00000004` `void* outputFn` (read, GUESS)

### TextureProcessingContext

44-byte texture codec context allocated at this+0x1A4 (DERIVED owner name from the packet): codec dispatch pair, row-buffer array, palette, dither buffer, toggle and symmetric-array slots. Also hosts the occupancy-grid row-array scan of GridOccupancyBoundingBoxScan.

Methods: `0x0051D247`, `0x0051DCAA`, `0x0051DFCB`, `0x0051E0DC`

- `*(this+0x1A4)+0x00000018` `void** rowTableArray` (read, DERIVED)
- `*(this+0x1C4)+0x00000000` `u16 ditherChannel0` (read_write, DERIVED)
- `*(this+0x1C4)+0x00000002` `u16 ditherChannel1` (read_write, GUESS)
- `*(this+0x1C4)+0x00000004` `u16 ditherChannel2` (read_write, GUESS)

### AllocatorProvider

Allocator object behind this+0x4 with a vtable whose entries 0, 1, 2, 4 and 7 are called with (this, 1, size) style arguments to allocate control blocks, arrays, aligned and flagged buffers.

Methods: 

- `this+0x00000004` `void* allocatorPtr` (read, DERIVED)
- `*(this+0x4)+0x00000000` `void* (*)(...) alloc` (read, DERIVED)
- `*(this+0x4)+0x00000004` `void* (*)(...) allocArray` (read, DERIVED)
- `*(this+0x4)+0x00000008` `void* (*)(...) allocAligned` (read, DERIVED)
- `*(this+0x4)+0x00000010` `void* (*)(...) allocWriteBuffer` (read, DERIVED)
- `*(this+0x4)+0x0000001C` `void* (*)(...) allocWithFlag` (read, DERIVED)

### ErrorReporter

Error-reporting object reached through this+0x0. On validation failure the caller writes an error code at obj+0x14 with detail arguments at obj+0x18..0x24 and dispatches through the obj+0x0 vtable (secondary dispatch via obj+0x4 used for decode-mismatch reports).

Methods: 

- `this+0x00000000` `void* errorReporterPtr` (read, DERIVED)
- `obj+0x00000000` `void** dispatchVtable` (read, DERIVED)
- `obj+0x00000004` `void** secondaryDispatchVtable` (read, GUESS)
- `obj+0x00000014` `int errorCode` (write, DERIVED)
- `obj+0x00000018` `int errorArg0` (write, DERIVED)
- `obj+0x0000001C` `int errorArg1` (write, GUESS)
- `obj+0x00000020` `int errorArg2` (write, GUESS)
- `obj+0x00000024` `int errorArg3` (write, GUESS)

### ImageResampler

Vertical image resampler blending consecutive pixel channel bytes with a 3:1 weighted convolution and an optional interior channel loop.

Methods: `0x0051C2DB`

- `obj+0x00000000` `byte pixelChannel0` (read, GUESS)
- `obj+0x00000001` `byte pixelChannel1` (read, GUESS)
- `obj+0x00000002` `byte pixelChannel2` (read, GUESS)
- `this+0x00000005` `byte channelByte5` (read, GUESS)
- `this+0x00000006` `byte channelByte6` (read, GUESS)

### PermutationGenerator

Mixed-radix combinatorial permutation generator: grows a factorial until the target count at this+0x54 is exceeded and advances positions until the total exceeds the target, with an optional global remap in mode 2.

Methods: `0x0051E1EF`

- `this+0x00000028` `int remapMode` (read, GUESS)
- `this+0x00000054` `int targetCount` (read, GUESS)
- `this+0x00000064` `int permutationBase` (read, GUESS)

## Compatibility contracts

- **RingBufferControlBlockLayout** — 28-byte ring control block at this+0x188: slot 0 state handler, slot 1 operation pointer, slot 2 size hint, slot 3 data pointer, slot 4 capacity, slot 5 cursor, slot 6 position/fill level. Presented by the packet both as block-relative (*(this+0x188)+0x04..0x18) and as this-relative (this+0x190..0x1A0).
- **AllocatorVtableSlots** — Allocator at this+0x4 with vtable entries 0, 1, 2, 4 and 7 (offsets 0x00, 0x04, 0x08, 0x10, 0x1C) called with a leading (this, 1) pair and a size argument.
- **ErrorReportingObjectProtocol** — Error reports are written as error code at obj+0x14 with up to four detail arguments at obj+0x18..0x24, then dispatched through the obj+0x0 vtable (secondary dispatch through obj+0x4).
- **PlaneLookupTableStride** — Per-plane lookup-table rows are 256-byte-stride (plane index shifted left by 8) anchored at this+0x8C and filled over the range this+0x168..this+0x16C with the set value at this+0x174.
- **TextureCodecContextLayout** — 44-byte texture codec context at this+0x1A4: +0x10 palette buffer, +0x14 pixel count, +0x18 row-buffer array (also occupancy-grid rows), +0x1C dirty/ready flag, +0x20 dither buffer, +0x24 toggle, +0x28 symmetric array. Sub-offsets map to this+0x1B4..0x1CC on the shared layout.
- **GlobalRenderModeFlag** — Global byte at 0x005D79DC selects between the SIMD+scalar hybrid path and the pure scalar path in IndexedSurfaceBlit.

## Unresolved

- Shared-layout hypothesis: the packet presents fields of several functions as this-relative offsets (0x48-0x64, 0x5C, 0xC4, 0x110-0x124, 0x168-0x174, 0x188-0x1DC). Equal this-relative offsets reused across different functions are not proof the functions share one object; MediaSurfaceObject groups them under an explicit hypothesis (per AudioBufferMixing's existing shared-struct-layout note).
- The error-reporting object at this+0x0 and the decoder output object at this+0x194 are distinct objects with similar field offsets; their type relationship is unknown.
- Error codes 14, 23, 37, 46, 49, 55, 56 and 111 have meanings outside this packet that are not established; error 55 is used both as an underflow clamp in textureContextInit and as a permutation-base error in CombinatorialPermutationGenerator.
- The ring control block is allocated as a separate 28-byte object by PlaybackBufferAlloc yet AudioRingBufferWrite and BufferedDataReader read its slots as this-embedded fields (this+0x190..0x1A0); which model holds is unresolved.
- this+0x19C is used both as a ring/stream sub-struct pointer and as a process function table (RenderCommandDispatcher) and as the write cursor slot; the dual-role aliasing of this+0x19C/0x1A4 across functions is unresolved.
- Mode flag (zero vs non-zero) and bitstream-absent flag semantics at the subsystem level are inferred from code shape, not confirmed.
- Decoder callback pairs (BitstreamDecoder/sub_51B154 and PlaneVisibilityTestWithBitfieldOutput/sub_51B45F) and the nine routine-table labels (VehicleStructFieldCopy, AudioBufferMixing, SetterReturnA4, PtrInitZero, TrackMapPixelFill, MonochromeBufferByteDuplicateCopy, BufferInterleaveCopy, PixelBlendFilterHorizontal, ImageResampleFilter) are corpus labels, not runtime-proven behavior.
- The 256-byte-stride per-plane lookup table layout and the 32-cell/64-byte occupancy grid geometry are inferred from pointer arithmetic, not confirmed by named structures.
- The meaning of the a2[6] scaled squared-extent formula (16/12/8 coefficients) in GridOccupancyBoundingBoxScan and the dword_5B06C8 remap table in CombinatorialPermutationGenerator are unknown.
- The concrete targets of the indirect copy/flush/dispatch calls (ring operation pointers, copy function tables, obj vtable entries) are not resolvable from this packet.
- The packet-internal literal discrepancy (obj+0x14 underflow value 55 vs 56) in TextureCodecModeDispatch is preserved unresolved.
- The allocator objects, the dispatch-state class seeded with FAILOverviewSaysFIRCrossfeedButDispatchesToIMDCT (0x0051BAD1), and the descriptor type behind *(this+0xC4) are not identified by packet evidence.
- Sub-surface descriptor element flag at +0x30 and channel count at +0x28 semantics, and the meaning of the -1 dispatch-slot initialization in allocateComboBoxBuffers, are not established.
- SymmetricArrayInit call target has no callee address evidence; obj+0x18 init_literal 256 field metadata appears mislabeled versus the raw allocator-result assignment.
- Plane pointer semantics of a2 in IndexedSurfaceBlit (three-plane source layout) and the color-space meaning of the four lookup tables are inferred, not confirmed.
- The exact block-compression palette-index transform and error-diffusion weights are recovered as arithmetic only; the intended visual algorithm is inferred.
- Why PtrInitZero receives unused parameters a1/a2/a3, and which caller object it serves, is unknown.
