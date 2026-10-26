# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Proposed reconstruction of generic runtime objects in the 0x0044A880..0x0045CD50 band. The strongest clusters are: (a) an F3DSoundEmitter (vtable install, string realloc, spatial audio float defaults, destructor frees buffer at +0x4); (b) a camera/viewport configuration struct whose paired float fields +0x30..+0xC4 are read by a family of accessor getters and written by two deep-copy functions; (c) an on-screen overlay 8-entry circular buffer with 23-dword stride, rotating write cursor at +0x31C, free-slot search and per-index reset; (d) an AABB node tree with material-table scaling and planar child-bounds tests; (e) audio-channel initializer pair sharing the caller AudioChannelInit; plus smaller single-function objects (cursor handle store, force-feedback device stage, string resolution service) and ten functions whose owners remain UnknownObject. Contradictions: the camera/viewport config field range overlaps the F3DSoundEmitter field range on the same base 'this'; the getter helpers used by both copy functions are documented as callers of those copies, and the destination type identity is not proven. All claims are DERIVED/GUESS; no function in the packet carried a CONFIRMED or FACT owner.

## Function roles

- `0x0044A880` **CollisionAABBTree** — Descending containment search of an AABB node tree: leaf marker test on the node-type word at +0x8 (negative stops and returns current node), material-table scaling of the input point (table anchored by global unk_7CA3A4, index at +0xA), planar outside tests against the child bound buffer at +0xC (first-axis min/max +0x0/+0x4, second-axis +0x10/+0x14), descent to the child buffer (or child+4 floats when only the first axis was outside), 0 when outside on both axes.
- `0x0044ACB0` **UnknownObject** — Iterate the audio/animation network node list, select scene-graph children flagged bit 0x100 at +20, match camera-distance entry candidate names against a cached name buffer seeded from byte_5EA438, and for valid animation entries compute triangle normals, assemble vertex triples and call RecursiveTriangleEdgeSubdivisionForCollision (0x0044AAE0) to generate collision geometry. Returns the final node count.
- `0x0044BC10` **UnknownObject** — Self-recursive node/partition count for a halving decomposition: base case a1 < 3 returns a1 > 0; otherwise returns 1 + RecursiveNodeCount(a1 - a1/2) + RecursiveNodeCount(a1/2). Semantics of the counted nodes depend on caller sub_44BC50.
- `0x0044F540` **CursorHandleStore** — Load a cursor image from disk via LoadImageA (image type 2, load-from-file flag 0x10) using an override-or-default directory prefix, zero the selected five-dword slot in a slot-indexed handle array and store the handle, post-incrementing the cursor count at this[42] (+0xA8). Returns 0.
- `0x0044F7D0` **UnknownObject** — Read-and-clear accessor: read the one-shot contact/event flag dword at this[47] (+0xBC), clear it to 0 and return the prior value. Called by InitViewportDimensions (0x00498740) during viewport initialization.
- `0x0044F8F0` **ForceFeedbackDeviceConfigurator** — Configure a force-feedback/input device stage: reset stage control flags at +0x3F8, call the device vtable methods poll (+0x64), state read (+0x24) and query (+0xC, filling the parameter block at +0x2C8), set flags to 6271 and OR axis-count bits (0x80/0x100/0x200/0x400) from the axis count at +0x2DC, then when capability bit 0 at +0x2CC is set call CollisionResponseCompute (0x0044F7F0) once per axis (up to 8). Returns 0 on success, -1 on null device at +0x80 or device-call failure.
- `0x00452740` **UnknownObject** — Re-initialize a collision-node property pair: retire the old property value via CollisionNodePropertySetter(byte_7CA594, *this, 0), store the new pair (this[1] = a3, this[0] = a2), apply it via CollisionNodePropertySetter(byte_7CA594, a2, a3) and return that call's result.
- `0x00453370` **UnknownObject** — Per-slot dispatch for a global-state initialization step: build the object-side slot pointer &this[11*a2+1736] and the global-side slot pointer &dword_7D1B08[7*a2], forward both plus a3 to the ShortComputation helper and return its result. Called once per step by GlobalStateInitializerWithEnumValues (0x004533A0).
- `0x00455260` **StringResolutionService** — Two-way string-table lookup (stdcall): discriminate on the dword at +0x0 (0 selects table1 aPause_0/aEmpty_0, 1 selects table2 aEmpty, anything else returns null), index the selected table with the dword at +0x4, and fall back to the global byte_5EA438 base for out-of-range indexes. Used by MessageNameBufferUpdate (0x0046AD50) and sub_4B9FD0 (0x004B9FD0).
- `0x00455560` **StringResolutionService** — Bound-checked accessor over an embedded pointer array (44 entries, 2-dword index step from dword index 2220 = +0x22B0): read the entry for index a2, return the global byte_5EA438 when the entry is null, return 0 for an out-of-range index. Shared by MessageNameBufferUpdate (0x0046AD50), SessionEntryListCleanup (0x0046AE60) and KeyBindingUIPressKeyOrController (0x0046B0C0).
- `0x00455B30` **UnknownObject** — Translate a Windows virtual-key code into a character: lazy keyboard-layout cache guarded by the one-time flag byte_7CCC04, GetKeyboardState into KeyState, remap scan code 32825 to 57, MapVirtualKeyExA and ToAsciiEx with the cached layout, post-process via sub_455580 (0x00455580) and store the result in word_7CCBC0.
- `0x00456060` **CameraViewportConfig** — Getter reading two consecutive DWORD fields at +0x38 and +0x3C into caller-supplied output pointers (each store null-guarded); returns the second output pointer a3.
- `0x00456080` **CameraViewportConfig** — Getter copying DWORD fields at +0x40 and +0x44 into nullable output pointers *a2/*a3; returns a3. Used by eleven frame-path callers across camera and car-selection paths.
- `0x00456170` **F3DSoundEmitter** — Constructor/initializer for the 3D sound emitter: install the object vtable off_59EFAC at +0x0, copy the global default string byte_5EA438 into the string buffer via StringCopyWithBufferRealloc, zero state/ID/flag fields, zero a triple through TripleFieldSetter_6280 (0x00456280) and write the spatial audio float defaults 60.0/45.0/500.0/1.0/0.5 across +0x30..+0x58. Returns this.
- `0x004562A0` **F3DSoundEmitter** — Destructor-shaped cleanup: write the global pointer off_59EFCC into this[0], and when the heap buffer pointer at this[1] (+0x4) is non-null free it via FreeWrapper_7bcf (0x00587BCF). On the null-buffer path the raw source returns an uninitialized register.
- `0x00457000` **CameraViewportConfig** — Deep-copy a source struct into this: dereference the string pointer at source+4 (null-safe) and copy with reallocation, copy leading 3D vectors via the vector-copy helpers, pull float/dword/byte values through the paired accessor getters (0x00456040/0x00456060/0x00456080/0x004560A0/0x004560C0/0x004560E0) and store them at +0x30..+0x6C, then copy the raw dword tail +0x70..+0xC4. Returns this.
- `0x00458050` **UnknownObject** — Parse control-point records from a structured file stream: iterate a dispatch/read loop (ConditionalDispatchBasedOnFlag with flag 384, stream read sub_5651B0), parse records matching the aControlpoint label (0x005C5A70) via sub_565870 into 3 coordinate dwords, collect up to 20 points, and with >= 4 points call sub_457F90 (0x00457F90) to build the keyframe array. Returns 1 on parse failure or insufficient points, else the sub_457F90 result.
- `0x00459330` **CameraViewportConfig** — Copy a camera/viewport configuration struct from source a2 into this: string pointer copy with reallocation, 3-vector copies, paired float copies through the accessor getter family, direct float/byte copies, a squared-field computation, and an optional buffer copy via BufferAllocCopy (0x004582E0). Returns this.
- `0x004594D0` **UnknownObject** — Struct initializer: zero the low fields +0x4..+0x18, write the FLT_MAX sentinel bit pattern 2139095039 to +0x1C and +0x20, zero +0x24/+0x28, mix zeroed fields with float constants (3.75f, 3.25f, 1.75f, 0.814f, 0.7515f) and the integer literal -755914244 at +0x40/+0x48, and zero the high fields +0xC0..+0xD0. Returns 0.
- `0x0045B430` **OnScreenOverlayEntryBuffer** — Reset one indexed entry of an 8-entry circular buffer: clear the entry flag byte, write sentinel values -1, -1082130432 and 3 at entry base +80/+84/+88, and when the reset index equals the write cursor at +0x31C advance it modulo 8. Returns the cursor value.
- `0x0045B500` **OnScreenOverlayEntryBuffer** — Free-slot search over the 8-entry circular buffer: scan from the rotating cursor this[199] (+0x31C) accepting the first entry whose availability float (entry dword +36) is <= 0.0 (flt_59E440); fall back to scanning from this+0xF0 with the same 23-dword stride when nothing matches; gate the chosen entry against caller threshold a2 (entry int field at dword +37), returning -1 on threshold failure or the chosen index otherwise. Invoked by RegisterTextLineEntry (0x0045B9C0).
- `0x0045BBE0` **OnScreenOverlayEntryBuffer** — Post-init helper for a UI render object: call sub_45B950 (0x0045B950), dereference the object pointer at this+0x0, clear the dword at object offset +0x31C to zero, then loop exactly 8 times resetting the per-index sub-structures. Returns the last per-index reset result. Called by OnScreen_Init (0x0049EFA0).
- `0x0045BED6` **UnknownObject** — Teardown of an AVI playback struct at a2 (a1 is the sentinel test value): release the resource at +0x44 via sub_53CB90 (0x0053CB90) and free the pointer at +0x50 via FreeWrapper_7bcf (0x00587BCF) when each differs from the sentinel, zero-initialize the struct via WideStructZeroInit (0x0045BF10) and shut down the AVI file system with AVIFileExit.
- `0x0045C0A0` **AudioChannelStruct** — Straight-line initializer zeroing six fields: bytes at +0x0 and +0x1, then dwords at +0x4, +0x8, +0xC and +0x10. Returns this. Called once by AudioChannelInit (0x0045D530).
- `0x0045C240` **UnknownObject** — Reset a file-scan object: seed the two leading bytes with LCG-random values (RandLCGRandomNumberGenerator 0x005884ED), walk and free the linked list of previously scanned file entries (head at +0x4, nodes with next at +4 and flag byte at +8), zero the list metadata (+0x4 head, +0x8 tail, +0xC cached tail, +0x10 count), and invoke sub_45C0C0 (0x0045C0C0) three times to scan the selected directory (dword_5EC3D8 when set, else byte_5EA438) for .gdb (type 2), .hdv (type 1) and terrain.ini (type 0) files. Returns the last sub_45C0C0 result.
- `0x0045CD50` **AudioChannelStruct** — Constructor-style initializer writing byte +0x0 = 0, byte +0x1 = 1 and dwords +0x4/+0x8/+0xC = 0, returning the original this pointer. Plausibly an audio-channel sub-object (single known caller named AudioChannelInit, 0x0045D530).

## Proposed classes

### F3DSoundEmitter

3D sound emitter object with an installed vtable pointer at +0x0, a reallocated string buffer referenced from +0x4, zeroed state/ID fields, and a fixed spatial-audio parameter block with the observed float defaults (60.0, 45.0, 500.0, 1.0, 0.5). Constructor installs off_59EFAC; destructor writes off_59EFCC and frees the buffer at +0x4. Owner label DERIVED from the packet's constructor entry only.

Methods: `0x00456170`, `0x004562A0`

- `this+0x00000000` `ptr vtable_ptr` (write, DERIVED)
- `this+0x00000004` `ptr string_buffer_ptr` (read_write, DERIVED)
- `this+0x00000008` `s32 init_sentinel` (write, DERIVED)
- `this+0x0000000C` `u32 state_region_start` (write, DERIVED)
- `this+0x00000010` `u32 state_field` (write, GUESS)
- `this+0x00000014` `u32 state_field` (write, GUESS)
- `this+0x00000018` `u32 state_field` (write, GUESS)
- `this+0x0000001C` `u32 state_field` (write, GUESS)
- `this+0x00000020` `u32 state_field` (write, GUESS)
- `this+0x00000030` `f32 spatial_audio_param` (write, GUESS)
- `this+0x00000034` `f32 spatial_audio_param` (write, GUESS)
- `this+0x00000038` `f32 spatial_audio_param` (write, GUESS)
- `this+0x0000003C` `f32 spatial_audio_param` (write, GUESS)
- `this+0x00000040` `f32 spatial_audio_param` (write, GUESS)
- `this+0x00000044` `f32 spatial_audio_param` (write, GUESS)
- `this+0x00000048` `f32 spatial_audio_param` (write, GUESS)
- `this+0x0000004C` `f32 spatial_audio_param` (write, GUESS)
- `this+0x00000050` `f32 spatial_audio_param` (write, GUESS)
- `this+0x00000054` `f32 spatial_audio_param` (write, GUESS)
- `this+0x00000058` `f32 spatial_audio_param` (write, GUESS)
- `this+0x0000005C` `u32 zeroed_field` (write, GUESS)
- `this+0x00000060` `u8 zeroed_byte_field` (write, GUESS)

### CameraViewportConfig

Camera/viewport configuration struct copied between instances by two deep-copy functions and read through a family of small paired-field accessor getters. The getter family (0x00456040, 0x00456060, 0x00456080, 0x004560A0, 0x004560C0, 0x004560E0) reads paired float/dword fields; the copy functions write string, vector, paired fields and a raw dword tail. Field roles (clipping/FOV) are inferred from structure only. Layout overlaps F3DSoundEmitter's field range on the same base 'this'; common ownership is NOT established.

Methods: `0x00456060`, `0x00456080`, `0x00457000`, `0x00459330`

- `this+0x00000030` `f32 paired_field_0x30` (read_write, GUESS)
- `this+0x00000034` `f32 paired_field_0x34` (read_write, GUESS)
- `this+0x00000038` `f32 paired_field_0x38` (read_write, GUESS)
- `this+0x0000003C` `f32 paired_field_0x3C` (read_write, GUESS)
- `this+0x00000040` `f32 paired_field_0x40` (read_write, GUESS)
- `this+0x00000044` `f32 paired_field_0x44` (read_write, GUESS)
- `this+0x00000048` `f32 copied_float` (read_write, GUESS)
- `this+0x0000004C` `f32 paired_field_0x4C` (read_write, GUESS)
- `this+0x00000050` `f32 paired_field_0x50` (read_write, GUESS)
- `this+0x00000054` `f32 viewport_rect_field` (read_write, GUESS)
- `this+0x00000058` `f32 viewport_rect_field` (read_write, GUESS)
- `this+0x0000005C` `f32 copied_float` (read_write, GUESS)
- `this+0x00000060` `u8 copied_byte` (read_write, GUESS)
- `this+0x00000064` `f32 triple_field_0x64` (read_write, GUESS)
- `this+0x00000068` `u32 triple_field_0x68` (read_write, GUESS)
- `this+0x0000006C` `u32 triple_field_0x6C` (read_write, GUESS)
- `this+0x00000070` `u32 copied_dword` (read_write, GUESS)
- `this+0x00000074` `u32 copied_dword` (read_write, GUESS)
- `this+0x00000078` `u32 copied_dword` (read_write, GUESS)
- `this+0x0000007C` `u32 copied_dword` (read_write, GUESS)
- `this+0x00000080` `u32 copied_dword` (read_write, GUESS)
- `this+0x00000084` `u32 copied_dword` (read_write, GUESS)
- `this+0x00000088` `u32 copied_value` (read_write, GUESS)
- `this+0x0000008C` `f32 squared_field` (read_write, GUESS)
- `this+0x00000090` `f32 vector_component` (read_write, GUESS)
- `this+0x00000094` `f32 vector_component` (read_write, GUESS)
- `this+0x00000098` `f32 vector_component` (read_write, GUESS)
- `this+0x0000009C` `u32 copied_dword` (read_write, GUESS)
- `this+0x000000A0` `u32 copied_dword` (read_write, GUESS)
- `this+0x000000A4` `u32 copied_dword` (read_write, GUESS)
- `this+0x000000A8` `u32 copied_dword` (read_write, GUESS)
- `this+0x000000AC` `u32 copied_dword` (read_write, GUESS)
- `this+0x000000B0` `u32 copied_dword` (read_write, GUESS)
- `this+0x000000B4` `u32 copied_dword` (read_write, GUESS)
- `this+0x000000B8` `u32 copied_dword` (read_write, GUESS)
- `this+0x000000BC` `u32 copied_dword` (read_write, GUESS)
- `this+0x000000C0` `u32 copied_dword` (read_write, GUESS)
- `this+0x000000C4` `u32 copied_dword` (read_write, GUESS)

### OnScreenOverlayEntryBuffer

8-entry circular buffer of per-index sub-structures (23-dword = 92-byte stride beginning at entry base this+0x3C, i.e. dword index 15) with a rotating write cursor at +0x31C. Free-slot selection accepts an entry whose availability float (entry dword +36) is <= 0.0; resets write sentinel values -1, -1082130432 and 3 at entry base +80/+84/+88. The wrapper ResetPerIndexSubStructures operates on the object dereferenced at this+0x0, which the entry-base arithmetic shows to be the same object type. Invoked by RegisterTextLineEntry and OnScreen_Init on the frame path.

Methods: `0x0045B430`, `0x0045B500`, `0x0045BBE0`

- `this+0x00000000` `ptr object_ptr` (read, GUESS)
- `this+0x000000F0` `ptr fallback_scan_base` (read, GUESS)
- `this+0x0000031C` `s32 write_cursor` (read_write, DERIVED)
- `obj+0x0000031C` `s32 write_cursor` (write, GUESS)

### CollisionAABBTree

AABB node tree used for descending containment search. Internal nodes carry a node-type word at +0x8 (negative = leaf marker), a material-table index word at +0xA, and a child bounds buffer pointer at +0xC. The child bounds buffer holds two axis min/max pairs at +0x0/+0x4 and +0x10/+0x14. Scaling factors come from the material table anchored by global unk_7CA3A4.

Methods: `0x0044A880`

- `this+0x00000008` `s16 node_type_word` (read, DERIVED)
- `this+0x0000000A` `u16 material_table_index` (read, DERIVED)
- `this+0x0000000C` `ptr child_bounds_ptr` (read, DERIVED)
- `*(this+0xC)+0x00000000` `f32 axis0_min` (read, GUESS)
- `*(this+0xC)+0x00000004` `f32 axis0_max` (read, GUESS)
- `*(this+0xC)+0x00000010` `f32 axis1_min` (read, GUESS)
- `*(this+0xC)+0x00000014` `f32 axis1_max` (read, GUESS)

### AudioChannelStruct

Small audio-channel sub-state struct: a byte flag pair at +0x0/+0x1 and three (plus an extra +0x10) zero-initialized dwords. Two complementary initializers both invoked from AudioChannelInit (0x0045D530).

Methods: `0x0045C0A0`, `0x0045CD50`

- `this+0x00000000` `u8 flag_byte` (write, GUESS)
- `this+0x00000001` `u8 flag_byte` (write, GUESS)
- `this+0x00000004` `u32 state_dword` (write, GUESS)
- `this+0x00000008` `u32 state_dword` (write, GUESS)
- `this+0x0000000C` `u32 state_dword` (write, GUESS)
- `this+0x00000010` `u32 state_dword` (write, GUESS)

### CursorHandleStore

Cursor image resource store: loads cursor bitmaps via LoadImageA (image type 2, load-from-file flag 0x10) from an override-or-default directory prefix, zeroing a five-dword slot before storing the handle and post-incrementing a cursor count at +0xA8.

Methods: `0x0044F540`

- `this+0x000000A8` `s32 cursor_count` (read_write, GUESS)

### ForceFeedbackDeviceConfigurator

Configures a force-feedback/input device stage through a device vtable pointer stored at +0x80 (callable slots +0xC query, +0x24 state read into an 80-byte buffer, +0x64 poll/flush). Maintains stage control flags at +0x3F8 (base 6271 plus axis-count bits 0x80/0x100/0x200/0x400), the axis count at +0x2DC, and capability flags at +0x2CC (bit 0 gates per-axis CollisionResponseCompute).

Methods: `0x0044F8F0`

- `this+0x00000080` `ptr device_ptr` (read, DERIVED)
- `this+0x000002CC` `u32 capability_flags` (read, GUESS)
- `this+0x000002DC` `s32 axis_count` (read, GUESS)
- `this+0x000003F8` `u32 stage_control_flags` (read_write, DERIVED)
- `*(this+0x80)+0x00000000` `ptr device_vtable_ptr` (read, DERIVED)
- `*(*(this+0x80)+0x0)+0x0000000C` `fnptr query_slot` (read, GUESS)
- `*(*(this+0x80)+0x0)+0x00000024` `fnptr state_read_slot` (read, GUESS)
- `*(*(this+0x80)+0x0)+0x00000064` `fnptr poll_slot` (read, GUESS)

### StringResolutionService

Message/pause string resolution: a discriminated two-way string-table lookup (discriminator at +0x0, index at +0x4, byte_5EA438 fallback) and a bound-checked per-slot pointer accessor over an embedded 44-entry array. Both fall back to the global byte_5EA438 base. Shared by message-buffer, session-cleanup and key-binding UI paths.

Methods: `0x00455260`, `0x00455560`

- `this+0x00000000` `s32 table_discriminator` (read, DERIVED)
- `this+0x00000004` `s32 table_index` (read, DERIVED)

## Compatibility contracts

- **F3DSoundEmitterVtableAndLayout** — A replacement 3D-sound-emitter must install a vtable pointer at +0x0 (observed globals off_59EFAC on construction, off_59EFCC during teardown), keep a reallocated string buffer referenced from +0x4 (freed on teardown), and expose a spatial-audio parameter block +0x30..+0x58 that reads back the observed construction defaults 60.0, 45.0, 500.0, 1.0, 0.5.
- **DeviceStageVtableContract** — The object at +0x80 must expose a device vtable whose slots +0xC (query filling the parameter block at +0x2C8), +0x24 (state read into an 80-byte buffer) and +0x64 (poll/flush) are callable; the stage control flags at +0x3F8 are reset then set to 6271 and ORed with axis-count bits 0x80/0x100/0x200/0x400 derived from the axis count at +0x2DC; capability bit 0 at +0x2CC gates per-axis CollisionResponseCompute.
- **OnScreenEntryBufferContract** — An on-screen overlay keeps an 8-entry circular buffer of 92-byte (23-dword) entries beginning at entry base this+0x3C with a rotating write cursor at +0x31C; free-slot selection accepts an entry whose availability float (entry dword +36) is <= 0.0 (global flt_59E440); a per-index reset clears the entry flag byte and writes sentinels -1, -1082130432 and 3 at entry base +80/+84/+88; after init the cursor at +0x31C is cleared and all 8 entries reset.
- **KeyboardTranslationContract** — Virtual-key to character translation lazily caches the active keyboard layout (guarded by the one-time flag byte_7CCC04), calls GetKeyboardState, MapVirtualKeyExA and ToAsciiEx with that layout, remaps the scan code 32825 to 57, post-processes the character via sub_455580 and writes the result to word_7CCBC0.
- **CursorHandleContract** — Cursor images load via LoadImageA (image type 2, load-from-file flag 0x10) from an override directory (dword_5EC408 when set, else the byte_5EA438 default), using a formatted path built from a '%s%s' format string; successful loads store the handle into a five-dword slot and post-increment the cursor count at +0xA8.

## Unresolved

- AABB search (0x0044A880): the raw source reads dword_7CA388 in addition to the packet's table anchor unk_7CA3A4; exact meaning of the two scale factors, whether the four computed values are corners of an oriented quad or sign-variant samples, the role of the fourth input component a2[3], and the meaning of the two descent targets (child buffer vs child buffer + 4 floats) all remain unresolved.
- AnimationPlaybackSequence (0x0044ACB0): globals flt_59E440, dbl_59EA08 and dword_8ACEA0 are listed as read but none appears in the raw source text; child field bit 0x100 semantics, camera-distance entry selection, and the v30/v31 transform buffer layout shared by IndexedTransformRead and TriangleNormalComputation are unresolved; the packet names the sole caller CollisionGeometryOperationSelector (0x0044BB60), which is outside the allowed evidence set.
- RecursiveNodeCount (0x0044BC10): the semantics of the counted nodes (binary/halving tree vs hierarchy elements) depend on caller sub_44BC50, unconfirmed here.
- CursorLoadImageALoader (0x0044F540): receiver identity is unknown (packet names caller sub_44F4E0 outside allowed refs); the five dwords per handle slot and the meaning of the cursor count at this[42] are not grounded beyond handle storage.
- ContactFlagReadClear (0x0044F7D0): owning type of the one-shot flag at +0xBC unknown; event meaning supplied by caller InitViewportDimensions unconfirmed.
- D3DTextureStage (0x0044F8F0): jump-table global jpt_44F9BB (0x0044FA40) is listed but absent from the raw source (likely compiler-generated); device vtable slot semantics +0xC/+0x24/+0x64 and the layout of the parameter block at +0x2C8 unresolved.
- SwapAndReinit (0x00452740): global byte_7CA594 is flagged DERIVED as WheelBrakeBiasThreshold; the property-setter argument semantics (0 on retire, a3 on apply) and the object owning this+0/this+4 are caller-supplied context only.
- PerSlotShortComputationDispatch (0x00453370): identity and record layout of the object slot array at this[11*a2+1736] and the global dword_7D1B08 array unknown; meaning of a3 and the ShortComputation helper behavior not visible in this packet.
- StringTableLookupByType (0x00455260): identities of the two string tables (aEmpty, aPause_0, aEmpty_0) and the byte_5EA438 base pointer unresolved; discriminator values 0/1 (message vs pause) inferred from caller names only.
- NullCheckedSlotPointerAccessor (0x00455560): what the embedded array entries point at and the byte_5EA438 fallback meaning are not established; the caller mix (message buffer, session cleanup, key-binding UI) does not pin a single receiver type.
- TranslateVirtualKey (0x00455B30): the scan-code remap 32825 to 57 (a VK_SPACE value) is caller-specific; sub_455580 internals are defined in a separate function.
- F3DSoundEmitter ctor/dtor (0x00456170/0x004562A0): off_59EFAC and off_59EFCC are different vtable globals; the F3DSoundEmitter label is DERIVED from the packet's constructor entry only; the three fields written by TripleFieldSetter_6280 (0x00456280) are not enumerated in the packet.
- StructDeepCopyFromSource (0x00457000): source getter-helper field semantics are not visible here; the string-copy destination is assumed to be the destination struct; the leading vector fields below 0x30 are not in the packet field list; the dword slot between +0x78 and +0x80 is skipped by the tail copy and may be an intentional gap.
- TrackControlPointLoader (0x00458050): sub_5651B0 record status codes other than 0/2/4 are not established.
- copyViewportConfig (0x00459330): exact owning class unknown (legacy ABI Camera_Viewport_Parameter_Copy vs existing-analysis CameraViewConfigCopy agree only on camera/viewport copy); individually copied field roles (clipping planes, FOV) are inferred from the paired-getter structure, not proven. The destination field range overlaps F3DSoundEmitter's on the same base 'this'; common ownership is not established and this contradiction is preserved.
- StructInitWithFloatConstants (0x004594D0): object type unknown (single caller sub_40FE50 outside the function set); the +0x40/+0x48 literals are stored as raw decimal -755914244; the packet's synthesized IEEE float decodes are not asserted; the ABI trust value 'LEGACY' is not schema-valid so owner trust is retained as UNKNOWN.
- PerIndexStructFieldResetter (0x0045B430): sentinel values (-1, -1082130432, 3) and the entry fields written at entry base +80/+84/+88 are unknown; purpose of the 8-entry circular buffer and owning object unknown.
- RotatingIndexSearchWithThreshold (0x0045B500): the fallback scan compares each entry value against the running result index rather than a stored best value (possible decompiler artifact); roles of the float field at entry dword +36 and the int field at dword +37 are inferred from usage; record layout behind the 23-dword stride undefined.
- ResetPerIndexSubStructures (0x0045BBE0): PerIndexStructFieldResetter appears in the raw source text but has no callee address in the deterministic packet; meaning of the cleared dword at +0x31C and of the 8 per-index sub-structures not established.
- AVIPlayerCleanup (0x0045BED6): global dword_8AFE64 is flagged DERIVED as RaceTimeDelta but appears nowhere in the raw source; sentinel a1 identity and the resource types held at +0x44/+0x50 unknown; AVIFileExit is named by the raw source but has no callee entry in the packet.
- ZeroInit5FloatStruct (0x0045C0A0): the byte writes at +0x0/+0x1 overlap the low bytes of the dword at +0x0, so the true member layout (two bytes plus four dwords, or six overlapping fields) is unconfirmed; the prelabel 'float struct' semantics are unverified.
- FileScanner (0x0045C240): sub_45C0C0 internals (directory enumeration, list append) undocumented; meaning of the type codes 0/1/2 and the seeded bytes at +0x0/+0x1 inferred; RandLCGRandomNumberGenerator receives this as its first argument (possibly a decompiler artifact); the scanned-directory globals remain unnamed.
- InitializeAudioChannelStruct (0x0045CD50): field semantics unnamed; audio-channel association inferred only from the single known caller named AudioChannelInit (0x0045D530).
