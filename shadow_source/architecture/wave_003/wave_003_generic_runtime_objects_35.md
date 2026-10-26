# RuntimeAssetAndRenderObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

DERIVED grouping of 21 validated IR functions sharing the runtime asset/render object layer. (1) Mesh/animation loading and node lists: MeshDataFileLoader parses mesh files (or an embedded sub-block) into a header (flags/scale/dimension/name) plus material or texture/animation blocks; MeshNodeListInsertOrFind and unlinkAndFreeNode manage a doubly-linked mesh node list anchored at this+0x118 with the EmptyStub+Free teardown convention; AnimationNodeCreateFromDataBlocks builds a singly-linked node list at this+0x13C from 136-byte data blocks resolved against a parameter table; InterpolateAnimationTracks advances an animation state by slerping rotation and lerping translation/scale across tracks. (2) Font/render: LoadFontTextureAndInit, conditionalFreeByFlag, FieldSetterAt0x48 and FontStringRender share the this+0x24 flag word (bit 0x20000 selects the hardware vertex-buffer path) and the font texture at this+0x868; BitfieldPropertyUpdater and ResourceFactoryViaVTableDispatch dispatch queued property changes and resource creation to a device object at this+0x1100 through vtable+0xC8 and vtable+0x90. (3) Media: OpenBinkVideo drives the Bink runtime through registered media directories; BmpGrabScreenLoadAndDisplay exports GRAB_<seq>.BMP screenshots. (4) Audio/timing: AudioFlagSet accumulates a QPC timestamp, InitializeAudioSystemChannels inits a 35-element channel array, RDTSCTimestampRead is the __rdtsc leaf. (5) ObjectInitHelpers groups the five shared constructors that layer GlobalZeroInit_c2a0 / StructInitWithDefaultValues over explicit field writes. Contradiction kept explicit: equal field offsets (0x0/0x4/0x24/0x2C/0x30 and others) recur on different this bases and are never merged across bases; deep list-traversal chains through this+0x160 and this+0x148 are not correlated with the +0x13C/+0x118 list heads; aSS_3 (0x005C2D64) is used as a path format string despite the prior 'session config' label.

## Function roles

- `0x00550AD0` **MeshDataFile** — Loads a mesh data file (or an embedded sub-block of parent context a3 when header bit 0x10 at (a3+296)+((a3+292)<<8) is set) into the shared read buffer dword_8B8F30, parses the header into this+0x0 flags / this+0x4 scale (inverted to 1.0/scale) / this+0x8 dimension / name at this+28, then parses material blocks (flag bit 2: 12-byte descriptors, 36-byte elements) or texture/animation blocks (flag bit 1: 44-byte descriptors, 32-byte frames) via ArithmeticComparison_a5c0 buffer reads; returns 0 on success, -1 on short read, freeing the temporary buffers.
- `0x00551210` **AnimationState** — Advances an animation state by a time fraction: clamps to the duration, converts the time into start/follow frames (CRTFtol), walks every active track (skip state byte 255), slerps the quaternion rotation via 0x0053B490/0x0053B5B0/0x0053B4C0, lerps translation/scale into track offsets +52/+56/+60, marks the state dirty (0x10000 on this+0x4) and clears a caller-supplied bitmask at a2+312 via 0x0054B330.
- `0x00551480` **AudioTimer** — Sets audio timer flag bit 0x1000 (clearing bits 0x7000) on the dword flags at this+0x4, then accumulates a query-performance-counter timestamp at this+0x0 and returns the accumulated value. Unconditional; no branches or guards.
- `0x00551560` **AnimationNodeList** — Creates a new node in the singly-linked node list at this+0x13C, sizes its element/data-block array from the count at this+0x130, copies 136-byte source blocks from this+0x134, resolves each block name (block+68) against parameter table a2 (count a2+12, entries a2+16, stride 44) storing the entry value on match or -1 on no match, stores a2 at node+0x1C, and runs the sub-init chain via EntityFlagSetSubInitChain; a null count produces a single-element node.
- `0x005518A0` **MeshNodeList** — Allocates a 52-byte mesh node via 0x00587C03, initializes it with a unit-vector default via 0x00550870, loads the resource named by a3 via 0x005508A0 (failure path: EmptyStub_7470 + FreeWrapper_7bcf + null *a2 + return -1), then either appends the node to the caller's list head at this+0x118 (force-insert flag a4 low bit or empty list) or deduplicates by the node name string at node+28 via strcmp; a duplicate returns -2 and reuses the existing node.
- `0x005519E0` **MeshNodeList** — Unlinks a doubly-linked node (prev at +44, next at +48) from the list head at this+0x118: relinks predecessor/successor, advances the head when the removed node is the head, runs the cleanup callback 0x00550AC0, EmptyStub_7470 and FreeWrapper_7bcf, then frees the node and returns 0.
- `0x00551A30` **ObjectInitHelpers** — Struct initializer with a unit-scale default: GlobalZeroInit_c2a0, then explicit zero of this+0x0 and this+0x4 and 1.0f at this+0x10; returns this. Called by 0x00546450 and ObjectCreationWithRollbackOnFailure (0x00551F10).
- `0x00551A50` **BinkVideoPlayer** — Opens a .bik video: copies and normalizes the requested filename, appends the .bik extension when missing, selects the Miles (flag bit 1) or DirectSound (flag bit 2) sound system when a device is supplied, builds the BinkOpen flag word from flag bits, opens directly and retries through the registered media directory table (byte_8B5A3C, 132-byte stride, dword_8B8E30 count), stores the handle at this+0x0 and width/height at this+0x8/+0xC via BinkGetSummary; 0 on success, -1 with BinkGetError report on failure.
- `0x00551FD0` **ScreenGrabExporter** — Loads a GRAB_<seq>.BMP screenshot file (unique via the dword_8CBF48 counter, opened under the config directory unk_5C2AB0), reads the 14-byte file and 40-byte info headers, allocates 3-bytes-per-pixel staging and row-aligned buffers, creates and configures a render surface (format from this[12]), renders via ClippedRenderRegion, converts BMP pixels (RGB555/565/24/32 per this[12]) into the locked surface, tears the surface down, flips rows bottom-up, reads the pixel payload directly into the flipped buffer, closes the file and frees temporaries; 0 on success, -1 on file-open or surface-setup failure.
- `0x00552470` **FontTextureRenderer** — Loads and initializes a font texture from file a2 with flags a3: computes allocator flags, queries the display entry via dword_8B78A0 to force the low-resolution flag when the display is small, normalizes and validates the filename against the font-extension table 0x005CC79C, allocates/parses the source surface into this+0x64, rounds width/height up to a power of two in 32..2048, allocates a 96-byte font texture at this+0x868 via 0x0054FE10 and initializes it via 0x0054FEC0, renders the glyph sheet onto the texture surface at this+0x8BC via ClippedRenderRegion, then swaps the source surface pointer; returns 0 or -1.
- `0x005528B0` **FontTextureRenderer** — Guard-conditional surface cleanup: when flag bit 0x20000 of this+0x24 is set, resets the object pointer at this+0xC via ObjectResetWithVirtualRelease (manager/context dword_8B78A0), frees it via FreeWrapper_7bcf if non-null, then zeroes the pointer field; returns 0 always.
- `0x00552FC0` **FontTextureRenderer** — Trivial thiscall field setter on an unknown rendering object: writes a2 into the dword at offset 0x48 and returns a2. No guards or callees. Invoked by six text/HUD/scaled-texture render paths.
- `0x00553070` **FontTextureRenderer** — Renders a text string character by character via the per-glyph step 0x00552910. With flag bit 0x20000 of this+0x24 set it takes the hardware path: derives a byte count from the string length, locks/reuses the vertex buffer (write offset this+0x8, descriptor this+0xC) via 0x00540F00, stores the pointer at this+0x10, renders each character, finalizes via 0x00540F90 and configures via 0x00541120 with font texture this+0x868 and render-state fields this+0x4C/+0x50/+0x58 (VTableGetter/Dispatch wrappers when dword_8B8DF0 is clear). Without the flag it renders directly through 0x00552910 with no buffer setup.
- `0x005532A0` **ObjectInitHelpers** — Constructor/initializer: GlobalZeroInit_c2a0, sets this+0x0 to the marker 2, zeroes this+0x4 through this+0x10, allocates a 36-byte block via 0x00587C03, zero-fills it and stores it at this+0x14 (or null on failure), and zeroes this+0x18/0x1C/0x20 in both branches; returns this.
- `0x00553DB0` **ObjectInitHelpers** — Constructor-style initializer on a _DWORD this pointer: writes 7 to the field at byte offset 0x20 and zeroes the seven adjacent DWORD fields at 0x24, 0x28, 0x2C, 0x30, 0x34, 0x38 and 0x3C; returns this. Called by seven sites including AudioBufferFormatSetup and StructZeroInitConstructor.
- `0x00553DE0` **ObjectInitHelpers** — Thiscall constructor: GlobalZeroInit_c2a0, StructInitWithDefaultValues on the sub-object at this+1 (byte offset 0x4), then clears this[0] and this[9..16] (offsets 0x0, 0x24..0x40) to zero; returns this. Called by DirectXDeviceSurfaceInitialization (0x0053D4F0).
- `0x00554790` **RenderDeviceController** — Compares a new flags bitmask a2 against the current state at this+0x1174; for each changed bit it appends a (property ID, value) pair to a local change list (22, 29, 27, 19, 20, 24, 9, 15), updating the stored resolution dword at this+0x13BC and its low/high words at this+0x13BE and this+0x13C0, then dispatches every queued pair to the device object at this+0x1100 through its vtable+0xC8 method, accumulates each return into *this, and stores a2 as the new current flags.
- `0x00554B20` **RenderDeviceController** — Creates or reconfigures a resource through a virtual dispatch on a device object: extracts render parameters from a2 via 0x005424E0, conditionally clips a render region via ClippedRenderRegion when a2+416 holds a pointer and a3 is zero (region base this+0x1528), then dispatches to the device object's vtable+0x90 method with a mode selected by the byte flag at a2+128 (mode 3 with a2[124], or mode 2) and stores the returned handle at *this.
- `0x005566D0` **AudioChannelTable** — Stores the channel count 3 into dword_8B8E48, then runs a fixed 35-iteration do/while loop over the 76-byte-strided channel array at dword_8B6C28, calling 0x00556260 on each element with the literal argument 1; returns the final count dword_8B8E48 + 32 (35).
- `0x0055687B` **TimestampSource** — Leaf helper executing the RDTSC instruction via the __rdtsc intrinsic and writing the 64-bit result into the caller-supplied output pointer a2; the first argument a1 is accepted but never referenced. Invoked on the frame path by the high-resolution timer wrappers (QPC mode dispatch, start, accumulate, reset) and by the random-noise table and deterministic-hash generators as a timing seed.
- `0x00557240` **ObjectInitHelpers** — Object initializer: GlobalZeroInit_c2a0 zero-fills the whole object, then a do/while loop initializes 8 sub-struct slots starting at this+1 (byte offset 0x4) with StructInitWithDefaultValues, advancing the slot cursor 16 dwords (0x40 bytes) per iteration, and finally zeroes the three trailing dwords at 0x204/0x208/0x20C; returns this. Called by 0x00543FA0.

## Proposed classes

### MeshDataFile

Mesh data file loader/parser: reads a mesh data file (or embedded sub-block) into the shared read buffer dword_8B8F30 and parses the header (flags, inverted scale, dimension, name) plus material blocks (flag bit 2) or texture/animation blocks (flag bit 1). All header fields are directly evidenced.

Methods: `0x00550AD0`

- `this+0x00000000` `uint32_t flags` (read_write, DERIVED)
- `this+0x00000004` `float scale` (read_write, DERIVED)
- `this+0x00000008` `float dimension` (read_write, DERIVED)
- `this+0x0000000C` `uint32_t texture_block_count` (write, GUESS)
- `this+0x00000010` `void* texture_blocks` (write, GUESS)
- `this+0x00000014` `uint32_t material_block_count` (write, GUESS)
- `this+0x00000018` `void* material_blocks` (write, GUESS)
- `this+0x0000001C` `char[16] name` (write, GUESS)

### MeshNodeList

Owns the doubly-linked mesh node list head at this+0x118 and provides insert-or-find (0x005518A0) and unlink-and-free (0x005519E0) operations, both using the shared EmptyStub_7470 + FreeWrapper_7bcf teardown convention. The two methods share the list head field; the node layout lives on the MeshNode class.

Methods: `0x005518A0`, `0x005519E0`

- `this+0x00000118` `MeshNode* head` (read_write, DERIVED)

### MeshNode

The 52-byte mesh list node: name string at +28 used for deduplication, previous pointer at +44, next pointer at +48. Layout is DERIVED from the list operations in this scope only; no dedicated field evidence refs exist for these offsets.

Methods: 

- `this+0x0000001C` `char* name` (read_write, GUESS)
- `this+0x0000002C` `MeshNode* prev` (read_write, GUESS)
- `this+0x00000030` `MeshNode* next` (read_write, GUESS)

### AnimationNodeList

Builds animation/mesh data-block nodes appended to the singly-linked node list head at this+0x13C: sizes the element array from this+0x130, copies 136-byte source blocks from this+0x134, resolves block names against a parameter table, and runs the sub-init chain. Packet owner is UnknownObject; the class is a semantic grouping (GUESS).

Methods: `0x00551560`

- `this+0x00000130` `uint32_t data_block_count` (read, DERIVED)
- `this+0x00000134` `void* source_blocks` (read, DERIVED)
- `this+0x0000013C` `void* node_list_head` (read_write, DERIVED)

### AnimationState

Animation state advanced by InterpolateAnimationTracks: holds the descriptor pointer, duration, frame count and track list used to slerp rotation and lerp translation/scale, and a dirty flag on this+0x4. All listed fields are directly evidenced except the rotation output at +0x4C/+0x50/+0x54, which the packet itself flags as conflicting with the raw source routing.

Methods: `0x00551210`

- `this+0x00000004` `uint32_t dirty_flags` (write, DERIVED)
- `this+0x00000008` `int current_frame` (read_write, DERIVED)
- `this+0x00000014` `int track_count` (read, DERIVED)
- `this+0x00000018` `void* track_list` (read, DERIVED)
- `this+0x0000001C` `void* descriptor_ptr` (read, DERIVED)
- `this+0x00000024` `float duration` (read, DERIVED)
- `this+0x0000002C` `void* keyframe_base` (read, DERIVED)
- `this+0x00000030` `int frame_count` (read, DERIVED)
- `this+0x0000004C` `float rotation_out_x` (write, GUESS)
- `this+0x00000050` `float rotation_out_y` (write, GUESS)
- `this+0x00000054` `float rotation_out_z` (write, GUESS)

### ObjectInitHelpers

Shared struct-construction helpers that layer GlobalZeroInit_c2a0 and/or StructInitWithDefaultValues over explicit field writes: StructInitZeroWithUnitScale, ObjectAllocationWithZeroInit, StructInitWithDefaultValues, StructZeroInitConstructor and vertexBufferResourceInit. These act on different this bases with overlapping offsets, so no fields are merged here; grouping is GUESS (shared helper pattern only).

Methods: `0x00551A30`, `0x005532A0`, `0x00553DB0`, `0x00553DE0`, `0x00557240`


### BinkVideoPlayer

Bink (.bik) video opener: normalizes the filename, selects the Miles/DirectSound sound system by flag bits, builds the BinkOpen flag word, opens via the Bink runtime and retries through registered media directories, storing the handle and BinkGetSummary dimensions. Bink import globals 0x0059E350-0x0059E368 are the import thunk slots used here.

Methods: `0x00551A50`

- `this+0x00000000` `void* bink_handle` (write, DERIVED)
- `this+0x00000008` `int width` (write, DERIVED)
- `this+0x0000000C` `int height` (write, DERIVED)

### ScreenGrabExporter

GRAB_<seq>.BMP screenshot export: increments the unique counter, opens the bitmap under the config directory, reads headers, allocates staging buffers, builds a temporary render surface (pixel format from this+0x30), renders the region into it, converts the pixel payload into the locked surface, tears the surface down, flips the rows and frees temporaries. Packet owner is UnknownObject; the class is a semantic grouping (GUESS).

Methods: `0x00551FD0`

- `this+0x00000030` `int pixel_format` (read, DERIVED)

### FontTextureRenderer

Font texture loading and text rendering: LoadFontTextureAndInit, conditionalFreeByFlag, FieldSetterAt0x48 and FontStringRender share the this+0x24 flag word (bit 0x20000 selects the hardware vertex-buffer path, also the cleanup gate), the source surface at this+0x64 and the font texture at this+0x868. FieldSetterAt0x48's inclusion is loose (only offset 0x48 and render-path callers); render-state semantics at +0x4C/+0x50/+0x58 are passed through to the buffer format call.

Methods: `0x00552470`, `0x005528B0`, `0x00552FC0`, `0x00553070`

- `this+0x00000008` `int vertex_buffer_write_offset` (read_write, GUESS)
- `this+0x0000000C` `void* buffer_descriptor` (read_write, GUESS)
- `this+0x00000010` `void* locked_buffer_ptr` (write, GUESS)
- `this+0x00000024` `uint32_t flags` (read_write, DERIVED)
- `this+0x0000002C` `int render_param` (write, GUESS)
- `this+0x00000048` `int settable_value` (read_write, GUESS)
- `this+0x0000004C` `uint32_t render_state_a` (read, GUESS)
- `this+0x00000050` `uint32_t render_state_b` (read_write, GUESS)
- `this+0x00000058` `uint32_t render_state_c` (read, GUESS)
- `this+0x00000064` `void* source_surface` (read_write, DERIVED)
- `this+0x00000868` `void* font_texture` (write, DERIVED)
- `this+0x000008BC` `void* font_texture_surface` (write, DERIVED)
- `*(this+0x64)+0x0000001C` `int width` (read, DERIVED)
- `*(this+0x64)+0x00000020` `int height` (read, DERIVED)

### RenderDeviceController

Consumer object holding a render-device pointer at this+0x1100, the current device flags at this+0x1174, stored/pending resolution dwords (this+0x13A4, this+0x13BC/+0x13BE, this+0x13C0) and a clip region base at this+0x1528. BitfieldPropertyUpdater queues property changes and dispatches them to the device via vtable+0xC8; ResourceFactoryViaVTableDispatch creates resources via vtable+0x90.

Methods: `0x00554790`, `0x00554B20`

- `this+0x00000000` `int result` (write, GUESS)
- `this+0x00001100` `RenderDevice* device_ptr` (read, DERIVED)
- `this+0x00001174` `uint32_t current_flags` (read_write, DERIVED)
- `this+0x000013A4` `int stored_resolution` (read, GUESS)
- `this+0x000013BC` `uint16_t resolution_low_word` (read_write, GUESS)
- `this+0x000013BE` `uint16_t resolution_high_word` (read_write, GUESS)
- `this+0x000013C0` `int pending_resolution` (read_write, GUESS)
- `this+0x00001528` `void* clip_region_base` (read, GUESS)

### RenderDevice

Virtual dispatch target referenced by RenderDeviceController at this+0x1100. Two vtable slots are evidenced by usage: +0x90 (resource create/configure, invoked by ResourceFactoryViaVTableDispatch) and +0xC8 (property set, invoked by BitfieldPropertyUpdater). Only the vtable offsets are known; the device object layout and method signatures are not established.

Methods: 

- `*(this+0x1100)+0x00000090` `fnptr create_resource` (unknown, GUESS)
- `*(this+0x1100)+0x000000C8` `fnptr set_property` (unknown, GUESS)

### AudioTimer

Audio timer flag accumulator: sets flag bit 0x1000 (clearing 0x7000) on this+0x4 and accumulates a query-performance-counter timestamp at this+0x0. The timer-accumulate callee has no address in the packet, so the call is evidenced only by the raw source.

Methods: `0x00551480`

- `this+0x00000000` `int timer_accumulator` (read, GUESS)
- `this+0x00000004` `uint32_t flags` (read_write, GUESS)

### AudioChannelTable

Global audio channel table: fixed 35-element array at dword_8B6C28 (76-byte stride) initialized by 0x00556260, with the stored channel count 3 in dword_8B8E48. Global-based; no this fields are observable.

Methods: `0x005566D0`


### TimestampSource

Leaf timestamp helper executing RDTSC via __rdtsc into a caller-supplied output pointer. Invoked by the high-resolution timer wrappers and by the noise/hash initializers as a timing seed; the first argument is unused.

Methods: `0x0055687B`


## Compatibility contracts

- **MeshDataFileFormat** — Mesh data files parse a header (flags, scale inverted to 1.0/scale, dimension, 16-byte name) followed by material blocks (header flag bit 2: 12-byte descriptors with 36-byte elements) or texture/animation blocks (header flag bit 1: 44-byte descriptors with 32-byte frames) from the shared read buffer dword_8B8F30. Loader returns 0 on success and -1 on a short read, freeing the temporary buffers.
- **MeshNodeListSemantics** — The mesh node list at this+0x118 follows insert-or-find semantics: 0 = inserted, -2 = duplicate name found (existing node reused, new node freed), -1 = load failure. Unlink maintains the node prev/next pointers (+44/+48) and advances the head when the removed node is the head. Every freed node passes through EmptyStub_7470 (0x00557470) before FreeWrapper_7bcf (0x00587BCF).
- **BinkVideoRuntime** — Video playback requires the Bink runtime exports (BinkOpen, BinkGetSummary, BinkSetSoundSystem, BinkSetSoundTrack, BinkGetError) reached through import globals 0x0059E350-0x0059E368, the .bik extension convention, Miles (flag bit 1) or DirectSound (flag bit 2) sound-system selection, and a media-directory retry table at byte_8B5A3C (132-byte stride, dword_8B8E30 entries).
- **FontTexturePipeline** — Font textures are stored at this+0x868 with the glyph-sheet surface at this+0x8BC, source surface at this+0x64; width/height are rounded up to a power of two in 32..2048 and the glyph sheet is rendered onto the texture surface via ClippedRenderRegion (0x00543250). Flag bit 0x20000 of this+0x24 selects the hardware vertex-buffer path (lock via 0x00540F00, finalize via 0x00540F90, format via 0x00541120) versus the direct software render path.
- **AudioChannelInit** — The audio system initializes 35 channel objects (76-byte stride) in the array at dword_8B6C28, each via 0x00556260 with argument 1, and stores the channel count 3 in dword_8B8E48. The relationship between the count 3 and the fixed 32 bound is unresolved.
- **DevicePropertyProtocol** — Render-device property changes are queued as (property ID, value) pairs and dispatched to the device object at this+0x1100 through its vtable+0xC8 method; resource creation dispatches through vtable+0x90. The stored resolution dword at this+0x13BC uses the literal full-screen mode values 65538 and 131074.

## Unresolved

- Most function owners are UnknownObject/UNKNOWN in the packet; the class groupings (AnimationNodeList, ObjectInitHelpers, ScreenGrabExporter, AudioTimer, AudioChannelTable, TimestampSource, MeshNode) are semantic GUESS groupings, not proven object boundaries.
- Global 0x0059E43C is listed as a referenced global by MeshDataFileLoader but its role is not established; no operation in the packet names it.
- The deep list-traversal chains through this+0x160 (AnimationNodeCreateFromDataBlocks) and this+0x148 (MeshNodeListInsertOrFind) are not correlated with the +0x13C and +0x118 list heads respectively; both traversal bases are unresolved.
- ArithmeticComparison_a5c0 (0x0054A5C0) buffer-cursor-read semantics are inferred from its repeated use as the file-to-struct reader; not confirmed independently.
- MeshDataFileLoader's embedded sub-block path (context a3: data pointer at +296 combined with a byte index at +292<<8, header bit 0x10) and the 16-byte name string processed by 0x00589901 are unexplained.
- MeshDataFileLoader material element layout beyond the 12/8-byte descriptors and 36-byte elements is not established; the per-frame float fill (index * scale) overwriting file data is unresolved.
- InterpolateAnimationTracks: the packet lists rotation writes to this+0x4C/+0x50/+0x54 but the raw source routes rotation through a local buffer and track offsets +4; the 136-byte track element layout and 44-byte descriptor stride are read from raw arithmetic only.
- AudioFlagSet's timer-accumulate callee (TimerAccumulateViaQueryPerformanceCounter) has no address in the packet callee facts; the this+0x0 value type is unproven.
- AnimationNodeCreateFromDataBlocks parameter-table layout (a2: count at +12, entries at +16, stride 44, name compare at block+68) and the node block-array pointer are evidenced only by raw source.
- EmptyStub_7470's (0x00557470) purpose and the meaning of flag a4 in MeshNodeListInsertOrFind beyond its low force-insert bit are unknown.
- BinkVideoPlayer: the mapping of 0x005DC070 (aErrorSWhileSet_0) versus 0x005DC094 (aErrorSWhileSet) to the Miles versus DirectSound error branch is not determinable; aSS_3 (0x005C2D64) is used here as a directory path format string, conflicting with the packet's existing-analysis label 'Session config file path string'; the Bink import prototypes are not evidenced.
- ScreenGrabExporter: globals aSgrab3dBmp (0x005DC0E8) and aGrab3dBmp (0x005DC0F8) are listed as read globals but their literal strings do not appear in the raw body; the this[12] pixel-format enum (5=RGB555, 6=RGB565, 7=RGB24, 8=RGBA32) is derived from the switch structure only.
- LoadFontTextureAndInit a3 flag bits (0x2, 0x800, 0x10000, 0x20000) and the this[9]/this[11] semantics are DERIVED from callers; the dword_8B78A0 display-entry layout (+284/+288) and sub_54FEC0 argument semantics (texture type 5, depth 4) are DERIVED.
- FieldSetterAt0x48 (0x00552FC0) offset 0x48 semantic role is caller-dependent; the skeleton's 'diffuse color' reading is unverifiable here.
- FontStringRender sub_552910 (0x00552910) per-glyph advance-return claim is inferred from the accumulation pattern; the meaning of this+0x4C/+0x50/+0x58 render-state fields passed to 0x00541120 is not defined in this function.
- ObjectAllocationWithZeroInit marker value 2 at this+0x0 and the 36-byte block stored at this+0x14 have no reads within this function; their meaning is unresolved.
- StructInitWithDefaultValues literal 7 at offset 0x20 and the object type are unknown; only offsets 0x20-0x3C are touched.
- StructZeroInitConstructor's caller DirectXDeviceSurfaceInitialization (0x0053D4F0) suggests a DirectX device/surface subsystem, but the exact object type is not established.
- BitfieldPropertyUpdater property IDs (22, 29, 27, 19, 20, 24, 9, 15) and the device identity at this+0x1100 are external; the resolution constants 65538/131074 are inferred from literals, not a named field.
- ResourceFactoryViaVTableDispatch dispatch mode arguments (2 vs 3) and the literal 1065353216 are unexplained; a2 offsets 416/128/124 are consumed only via raw source.
- AudioChannelTable: the relationship between the stored count 3 and the fixed loop bound 32 (why 35 objects) is unresolved; the 76-byte channel object and sub_556260's argument 1 are undocumented.
- RDTSCTimestampRead argument a1 is declared but never referenced; its intended role is not evidenced. Whether callers treat the raw counter as relative or absolute is not established.
- vertexBufferResourceInit's 8 sub-struct slots (caller VertexBufferResourceAllocation suggests vertex-buffer resources) and the three trailing fields at 0x204/0x208/0x20C are DERIVED/GUESS.
- Equal field offsets (0x0, 0x4, 0x24, 0x2C, 0x30 and others) recur on different this bases (MeshDataFile vs AnimationState vs AudioTimer vs FontTextureRenderer vs RenderDeviceController vs ObjectInitHelpers); none are merged across bases because the packet does not prove common ownership.
