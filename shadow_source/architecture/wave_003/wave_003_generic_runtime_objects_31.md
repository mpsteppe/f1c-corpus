# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Proposal for the generic_runtime_objects slice of Wave 3 packet 31. The functions cluster into: an MPEG-audio decoder object (0x52DE60 buffer/timing calculation, 0x52E2F0 tracking-state reset) whose open paths are shared by CMpegBase_Open and CMpegFilePlayer_Open; a file stream context with an ASCII mode byte at +0x5C (open 0x534B10, destructor 0x534EE0, buffered read 0x534F90, reset-to-read 0x5354E0); a 'w'-tagged buffered stream reader (0x535220, 0x5352D0) with offsets evidenced only from raw source; a string-keyed resource registry over the global list at dword_8B8E20 (lookup-or-create 0x53CFE0, match-and-cleanup 0x53D130); a global string buffer helper pair sharing byte_8B6AC8 (0x53C590 writes, 0x53C5B0 reads); a render compositor singleton (alloc-init 0x53B0D0 storing the instance in dword_8B8F18/dword_8B8F24, shutdown cleanup 0x53C4D0 freeing it among a batch of globals); a Direct3D8 render system (0x53D750 init, 0x540760 four-chain resource teardown gated by the shared +0x13DC enable flag) with the 0x540760 AudioStreamChainCleanup name contradicting its D3D-init caller role; and small generic helpers (static-init registrar 0x52E060, list unlink 0x53C630, pair init 0x53C6A0, allocation helper 0x53CAC0, cleanup helper 0x53CB90, list pruner 0x53CED0, video-system init wrapper 0x53D470). Ownership is largely UNKNOWN at the function-IR level, so most classes here are GUESS or DERIVED proposals, not confirmed identities.

## Function roles

- `0x0052DE60` **CMpegAudioDecoder** — MPEG audio buffer/timing calculation on the decoder object: derives the buffer size (768x or 2304x channel multiplier by the +0x2490 mono flag), computes the timing quotient/remainder from 28800 x (5 x +0x2494) / sample-rate (+0x2484), sets +0x24D4, the ready flag +0x24BC and +0x24E0, copies the buffer size into +0x249C, and returns constant 0. Invoked by CMpegBase_Open (0x52E090) and CMpegFilePlayer_Open (0x52E1D0) during decoder-open paths.
- `0x0052E060` **StaticInitializerRegistrar** — Minimal static-initialization registration wrapper: reads the sub_52E070 function pointer global at 0x0052E070, casts it to an int, and returns the normalized result of BooleanToIntConversion (0x587B3E). The target routine's behavior is not evidenced in this packet.
- `0x0052E2F0` **CMpegAudioDecoder** — MPEG audio tracking-state reset on the decoder object: copies the current buffer-level value from +0x249C into the tracking field +0x24E8, then zeroes the frame/stream bit positions, accumulated byte position and frame count (+0x24A8, +0x24AC, +0x24B4, +0x24E4). Returns constant 0. Invoked by CMpegBase_Open (0x52E090) and CMpegFilePlayer_Open (0x52E1D0).
- `0x00534B10` **CFileStreamContext** — File stream context open/constructor: validates the path and mode strings, allocates a 97-byte context, parses the mode characters ('r' read / 'w'/'a' write, 'f' flag=1, 'h' flag=2, digits skipped) into the mode byte at +0x5C, wires a memory-allocator object at +0x4C, copies the filename to +0x54, allocates the 0x4000 stream buffer, resolves the OS file handle (existing handle arg or path open), writes the 'CCCC' header in write mode and validates it in read mode via sub_534D50. On any failure the partial context is freed through FileHandleDestructorWithModeCheck and 0 is returned.
- `0x00534EE0` **CFileStreamContext** — File stream context destructor: returns -2 on a null pointer; frees the copied filename at +0x50, runs mode-appropriate stream cleanup ('w' -> sub_5361D0, 'r' -> GuardedFunctionCallCleanup) when the stream object at +0x1C is present, closes the OS file handle at +0x40 under lock unless the TLS error code is 29, propagates a stored negative error code at +0x38, then frees the write/read/allocator buffers (+0x44, +0x48, +0x54) and the object itself.
- `0x00534F90` **CFileStreamContext** — Buffered file read on the read-mode stream: returns -2 for a null stream or a mode byte at +0x5C != 'r' (114); gates on the state field at +0x38 (-3/-1 error, 1 EOF); drains the internal 0x4000 buffer, refills it from the OS handle via ThreadSafeReadWrapper_803f, advances the parse state through sub_5357E0, verifies integrity via F_4BitFieldPack against the count at +0x4C, finalizes the stream record through sub_534D50, tracks positions at +0x8/+0x14, sets the EOF flag at +0x3C, and returns the number of bytes read.
- `0x00535220` **CTaggedStreamBuffer** — Fill a tagged ('w') read buffer object up to a requested count: rejects null or non-'w' (119) tagged objects with -2; stores the request at +0x0/+0x4, loops reading 0x4000 bytes from the file handle at +0x48 into the staging buffer at +0x40 until staged bytes exist, consumes them through sub_535E80 recording progress at +0x38, records sub_536E90(a3) at +0x4C, and returns bytes actually consumed. Invoked by StringLengthDispatch, AudioStreamBufferRead, ConditionalDispatch_6bd0 and BufferWriteWithStringLengthCheck.
- `0x005352D0` **CTaggedStreamBuffer** — Buffered file read driver for the tagged ('w') stream: proceeds only when the stream is non-null and the type byte at +0x5C equals 'w' (119); resets the buffer at +0x4, tops up a 0x4000-byte buffer reading 1-byte units via FileReadWrapperWithLock from the handle at +0x48 into the buffer at +0x40, hands each chunk to sub_535E80, coerces the -5 status to 0 when the buffer is exactly full, and returns 0 when the final status is 1, otherwise the stored status at +0x38.
- `0x005354E0` **CFileStreamContext** — Reset the buffered file stream context back to read mode: returns -1 on a null this or when the mode byte at +0x5C != 'r' (114); saves the handle at +0x44, clears the remaining-bytes field at +0x38, the EOF/error flag at +0x3C and +0x4, resets the buffer position at +0x0 to the saved handle, reinitializes the allocator at +0x4C via sub_536E90(0), then either seeks to the data size at +0x5D (sub_587F64) or closes the handle (sub_58AFE1) when no seek is needed. Invoked from AudioStreamBufferRead (0x535390).
- `0x0053B0D0` **GlobalRenderCompositor** — Render compositor singleton alloc-init: allocates a 4-byte heap object via OperatorNewNhMallocWrapper(4), zero-initializes the body via GlobalZeroInit_c2a0, installs the data pointer off_5B8938 as the object's first field, and stores the instance pointer in globals dword_8B8F18 and dword_8B8F24. On allocation failure both globals are set to 0 and 0 is returned.
- `0x0053C4D0` **GlobalRenderCompositor** — Global resource shutdown cleanup: cleans pointer arrays via sub_55BF70, releases the sound-manager-style object referenced by dword_8B78A0 through a vtable call, then for each global (dword_8B8F2C, dword_8B8F04, dword_8B8F18, dword_8B8F1C, dword_8B8F20) runs an optional pre-cleanup handler, frees the heap block and zeroes the global. Returns 0.
- `0x0053C590` **GlobalStringBufferHelpers** — Copy a null-terminated string from source a2 into the global byte buffer byte_8B6AC8 including the terminating null, via a do-while loop indexed by the difference between the current source position and a2. Returns the source pointer advanced past the copied region. The int argument a1 is unused in the decompiled body.
- `0x0053C5B0` **GlobalStringBufferHelpers** — String relocation copy: when the caller-provided destination pointer a2 is non-null, copies the game-wide string stored at global byte_8B6AC8 into it via the CRT strcpy routine, then always returns 0. Its ten recorded callers are scene/asset loaders (CUBESceneLoaderEntry, PitCrewMeshLoader, VehicleGraphicsSceneLoader, VidMan_Init and others), consistent with a shared helper writing a hardcoded string into a freshly loaded object's buffer. The first parameter a1 is unused by the body.
- `0x0053C630` **DoublyLinkedNode** — Unlink a node from a doubly linked list whose prev/next links live at +0x1E4/+0x1E8: patches the reciprocal links, and when the global list head dword_8B8F28 equals the node, advances the head to the node's next which becomes the return value; otherwise the node itself is returned. Called from audio-engine paths AudioEngineInitialization (0x546010) and MutexSemaphoreCleanup (0x5461B0).
- `0x0053C6A0` **PairInitializer** — Trivial zero-initializer: writes 0 to the first dword at +0x0 and 0 to the byte at +0x4, then returns the object pointer. Called from two unrelated domains, SearchPathPrune (0x53CA00) and AudioMixerChannelInitializer (0x5435D0).
- `0x0053CAC0` **ObjectAllocationHelper** — Allocation wrapper (stdcall): allocates a 48-byte object through OperatorNewNhMallocWrapper, runs the MultiFieldZeroInitConstructor over it when the allocation succeeds (otherwise stores 0), writes the resulting pointer into the output slot at this+0x0, then returns a status derived from GuardedCallWithStatus(0) (0 when the guarded call is zero, -1 otherwise). Used by the audio mixer channel initializer path (0x5435D0).
- `0x0053CB90` **ObjectCleanupHelper** — Object teardown wrapper: unconditionally runs the first-phase cleanup sub_542E50(a1), then, only when a1 is non-null, runs the empty stub sub_57470 and a heap free via FreeWrapper_7bcf over the same pointer. Always returns 0. Callers (AVIPlayerCleanup, MultiStageCleanupWithRepeatedCallCycle, AudioResourceCleanup, sub_4F9480) all sit on cleanup paths.
- `0x0053CED0` **GlobalListPruner** — Walk the global doubly-linked list rooted at dword_8B8F14 (nodes linked through +0x12C prev / +0x130 next) and remove and free every node whose flag byte at +0x114 has bit 3 (value 8) set. Each removal unlinks the node with null-checked reciprocal patches, runs DualFieldCleanupWithNullChecks and EmptyStub_7470, frees it via FreeWrapper_7bcf and decrements the global node count dword_8B6AC0. A trailing check covers the final node the look-ahead loop skips. Returns 0.
- `0x0053CFE0` **ResourceRegistry** — String-keyed resource registry lookup-or-create: copies and transforms the filename (sub_589901), strips the file extension by scanning backward for '.', walks the global registry list headed at dword_8B8E20 comparing the stored name (node+20) with the stripped string (next pointer at node+2160), writes the matched node into *a1 and returns 0; on no match allocates a 2164-byte entry, initializes it with HashTable, registers it via sub_552470, appends via LinkedListAppend_d340 on success (returns 0) or cleans up with EmptyStub_7470 / FreeWrapper_7bcf and returns -1 on registration failure.
- `0x0053D130` **ResourceRegistry** — Registry name-match and cleanup: walks the registry linked list headed by dword_8B8E20 comparing each node's name string at offset +0x14 with a1's name via strcmp (next pointer at offset +2160). On match, unlinks a1 with DoublyLinkedListNodeRemoval_d3a0, calls AudioResourceCleanup (0x52760), and, when a1 is non-null, runs EmptyStub_7470 then frees the node via FreeWrapper_7bcf. Returns early without cleanup when the head is null or the list end is reached without a match.
- `0x0053D470` **VideoSystemInitHelper** — __fastcall allocation-and-init wrapper for the video system: allocates a 48-byte block via OperatorNewNhMallocWrapper, initializes it through EngineInitBlock, stores the resulting block pointer into the caller-provided output slot *a1, and on a valid block runs RenderUISystemGlobalInit returning 0 when it returns 0 (else -1); on allocation failure stores 0 and returns -1. Invoked by VidMan_Enter (0x4FA000).
- `0x0053D750` **D3DRenderSystem** — Direct3D8 rendering context initialization: releases any existing D3D and device interfaces held at +0x10FC/+0x1100 through vtable+8 calls, zeroes the device state block at +0x1104, resets render-state fields (+0x4, +0x8, +0x1138), creates a new D3D8 object via Direct3DCreate8(220) at +0x10FC, selects the render-mode flag at +0x13DC from the config value at +0x13E0, runs the setup/chain-reset helper 0x540760, zeroes the render-state block (+0x13E8..+0x1404, +0x14F0, +0x1518, +0x1580), and returns 0. On D3D8 creation failure reports the error string aErrorCreatingD through sub_53C590 and returns -1.
- `0x00540760` **D3DRenderSystem** — Four-chain resource teardown/reset gated by the enable flag at +0x13DC: walks four linked lists of resource nodes rooted at +0x1154/+0x115C/+0x1164/+0x116C, releases each node's nested object through vtable slot +8 resolved from the chain descriptors at +0x1170/+0x1178/+0x1180, frees every payload and head node with FreeWrapper_7bcf, and zeroes the four list slots. Always returns 0. The prelabel names it AudioStreamChainCleanup, but it is invoked by Direct3DInitialization (0x53D750) as a setup/cleanup step, by ObjectReleaseWithVtableCall (0x53D850) and by AudioNetworkStreamCleanup (0x544AF0).

## Proposed classes

### CMpegAudioDecoder

MPEG-audio decoder object holding buffer/timing and tracking state in the +0x2484..+0x24E8 range. Computes the audio buffer size and timing quotient/remainder from the sample rate and mode multiplier, and resets the frame/stream bit positions, byte position and frame count on open. The class name is inherited from prelabel/prose; the object type is not evidenced by raw bodies.

Methods: `0x0052DE60`, `0x0052E2F0`

- `this+0x00002484` `int sample_rate` (read, DERIVED)
- `this+0x0000248C` `int buffer_size` (write, DERIVED)
- `this+0x00002490` `byte mono_mode_flag` (read, DERIVED)
- `this+0x00002494` `int mode_multiplier` (read, DERIVED)
- `this+0x0000249C` `int buffer_size_copy` (read_write, DERIVED)
- `this+0x000024A8` `int frame_bit_position` (write, GUESS)
- `this+0x000024AC` `int stream_bit_position` (write, GUESS)
- `this+0x000024B4` `int accumulated_byte_position` (write, GUESS)
- `this+0x000024BC` `byte ready_flag` (write, DERIVED)
- `this+0x000024CC` `int channel_multiplier` (read, DERIVED)
- `this+0x000024D4` `int initial_timing_field` (write, GUESS)
- `this+0x000024D8` `int timing_quotient` (write, DERIVED)
- `this+0x000024DC` `int timing_remainder` (write, DERIVED)
- `this+0x000024E0` `int sample_rate_scaled` (write, DERIVED)
- `this+0x000024E4` `int frame_count` (write, GUESS)
- `this+0x000024E8` `int tracking_field` (write, GUESS)

### CFileStreamContext

File stream context with an ASCII mode byte at +0x5C selecting read ('r') or write ('w') behavior. Owns a copied filename (+0x50), an allocator object (+0x4C/+0x54), the OS file handle (+0x40), read/write stream buffers (+0x44/+0x48), a stream object (+0x1C), a stored error/state code (+0x38), an EOF/error flag (+0x3C) and a data size (+0x5D). Provides open, buffered read, reset-to-read and destructor operations.

Methods: `0x00534B10`, `0x00534EE0`, `0x00534F90`, `0x005354E0`

- `this+0x00000000` `pointer buffer_position` (read_write, DERIVED)
- `this+0x00000004` `int buffer_byte_count` (read_write, GUESS)
- `this+0x00000008` `int read_position` (read_write, GUESS)
- `this+0x0000001C` `pointer stream_object` (read, DERIVED)
- `this+0x00000038` `int stored_error_or_state` (read_write, DERIVED)
- `this+0x0000003C` `int eof_or_error_flag` (read_write, DERIVED)
- `this+0x00000040` `pointer file_handle` (read_write, DERIVED)
- `this+0x00000044` `pointer read_input_buffer` (read_write, GUESS)
- `this+0x00000048` `pointer write_output_buffer` (read_write, GUESS)
- `this+0x0000004C` `pointer allocator_object` (read_write, DERIVED)
- `this+0x00000050` `pointer copied_filename` (read, DERIVED)
- `this+0x00000054` `pointer allocator_pointer` (read, DERIVED)
- `this+0x0000005C` `byte mode_byte` (read, DERIVED)
- `this+0x0000005D` `int data_size` (read, DERIVED)

### CTaggedStreamBuffer

Tagged buffered stream object whose type byte at +0x5C must equal 'w' (119). Carries request destination/count at +0x0/+0x4, a status field at +0x38, a staging buffer at +0x40, the file handle at +0x48 and an accounting field at +0x4C (all with packet field evidence). The staged byte count at +0x10 appears in the raw-source bodies but has no packet field evidence and is tracked in unresolved. All offsets come from the raw decompiled source only; the packet carries no field evidence entries for them.

Methods: `0x00535220`, `0x005352D0`

- `this+0x00000000` `pointer request_dest` (write, GUESS)
- `this+0x00000004` `int request_count` (read_write, GUESS)
- `this+0x00000038` `int status` (read_write, GUESS)
- `this+0x00000040` `pointer staging_buffer` (read_write, GUESS)
- `this+0x00000048` `pointer file_handle` (read, GUESS)
- `this+0x0000004C` `int accounting_field` (write, GUESS)
- `this+0x0000005C` `byte type_byte` (read, GUESS)

### GlobalStringBufferHelpers

Two complementary module-level helpers over the single global byte buffer byte_8B6AC8: one copies an external string into it (returning the advanced source pointer), the other copies it out into a caller buffer via strcpy and always returns 0. Scene/asset loaders rely on the read side.

Methods: `0x0053C590`, `0x0053C5B0`


### GlobalRenderCompositor

Render compositor singleton lifecycle. Alloc-init installs the data pointer off_5B8938 into a minimal 4-byte object and publishes the instance into globals dword_8B8F18 and dword_8B8F24; shutdown cleanup releases a batch of global resources including dword_8B8F18, a sound-manager-style object at dword_8B78A0 and several other globals. The 'render compositor / NetConfigData / D3DDeviceWrapperPtr' identities are DERIVED from prior analysis, not independently evidenced.

Methods: `0x0053B0D0`, `0x0053C4D0`


### ResourceRegistry

String-keyed resource registry over the global linked list headed at dword_8B8E20. Nodes are 2164-byte allocations with the key name at node+20 (0x14) and the next pointer at node+2160 (0x870). Provides lookup-or-create with extension stripping and hashtable initialization, and name-match cleanup that unlinks and frees an entry.

Methods: `0x0053CFE0`, `0x0053D130`

- `this+0x00000000` `pointer output_slot` (write, DERIVED)

### D3DRenderSystem

Direct3D8 rendering system object. Holds the D3D8 object at +0x10FC and the device at +0x1100, a device state block at +0x1104, render-state fields, a config render-mode selector (+0x13E0) driving the enable flag (+0x13DC), and four resource chains (+0x1154/+0x115C/+0x1164/+0x116C) with chain descriptors (+0x1170/+0x1178/+0x1180). The 0x540760 method's prelabel 'AudioStreamChainCleanup' conflicts with its D3D-init caller role.

Methods: `0x0053D750`, `0x00540760`

- `this+0x00000000` `int device_render_handle` (read_write, GUESS)
- `this+0x00000004` `int render_state_a` (write, GUESS)
- `this+0x00000008` `int render_state_b` (write, GUESS)
- `this+0x000010FC` `pointer d3d8_object` (read_write, DERIVED)
- `this+0x00001100` `pointer d3d_device` (read_write, DERIVED)
- `this+0x00001138` `int render_state_c` (write, GUESS)
- `this+0x00001154` `pointer chain1_head` (read_write, DERIVED)
- `this+0x0000115C` `pointer chain2_head` (read_write, DERIVED)
- `this+0x00001164` `pointer chain3_head` (read_write, DERIVED)
- `this+0x0000116C` `pointer chain4_head` (read_write, DERIVED)
- `this+0x00001170` `pointer chain1_descriptor` (read, DERIVED)
- `this+0x00001178` `pointer chain2_descriptor` (read, DERIVED)
- `this+0x00001180` `pointer chain3_descriptor` (read, DERIVED)
- `this+0x000013DC` `byte enable_flag` (read_write, DERIVED)
- `this+0x000013E0` `int config_render_mode` (read, DERIVED)
- `this+0x000013E8` `int render_state_13E8` (write, GUESS)
- `this+0x000013EC` `int render_state_13EC` (write, GUESS)
- `this+0x000013F0` `int render_state_13F0` (write, GUESS)
- `this+0x000013F4` `int render_state_13F4` (write, GUESS)
- `this+0x000013F8` `int render_state_13F8` (write, GUESS)
- `this+0x000013FC` `int render_state_13FC` (write, GUESS)
- `this+0x00001400` `int render_state_1400` (write, GUESS)
- `this+0x00001404` `int render_state_1404` (write, GUESS)
- `this+0x000014F0` `int render_state_14F0` (write, GUESS)
- `this+0x00001518` `int render_state_1518` (write, GUESS)
- `this+0x00001580` `int render_state_1580` (write, GUESS)

### DoublyLinkedNode

Generic doubly linked list node with prev/next links at +0x1E4/+0x1E8 and a global list head at dword_8B8F28. Provides the reciprocal-patch unlink operation; used by audio-engine lifecycle paths. The owning object type is unknown.

Methods: `0x0053C630`

- `this+0x000001E4` `pointer prev_node` (read_write, DERIVED)
- `this+0x000001E8` `pointer next_node` (read_write, DERIVED)

### PairInitializer

Trivial two-field object initializer: zeroes a dword at +0x0 and a byte at +0x4, returning the object pointer. Reused by unrelated domains (search-path prune and audio-mixer channel init), so the concrete object type is unresolved.

Methods: `0x0053C6A0`

- `this+0x00000000` `int first_dword` (write, DERIVED)
- `this+0x00000004` `byte second_byte` (write, DERIVED)

### ObjectAllocationHelper

Generic 48-byte object allocation wrapper: allocates through OperatorNewNhMallocWrapper, zero-initializes via a multi-field constructor, publishes the pointer into the caller's output slot and returns a guarded-init status (0/-1). Used by the audio mixer channel initializer path.

Methods: `0x0053CAC0`

- `this+0x00000000` `pointer output_slot` (write, DERIVED)

### ObjectCleanupHelper

Generic object teardown helper: unconditionally runs a first-phase cleanup, then for a non-null pointer runs an empty-stub and a heap free, always returning 0. Shared by AVI, audio and multi-stage cleanup paths.

Methods: `0x0053CB90`


### GlobalListPruner

Pruner over the global doubly-linked list rooted at dword_8B8F14 (nodes linked through +0x12C/+0x130) that removes and frees every node whose flag byte at +0x114 has bit 3 set, decrementing the global node count at dword_8B6AC0. The head/count labels and link/flag roles are DERIVED from the traversal pattern, not confirmed by packet field evidence.

Methods: `0x0053CED0`


### StaticInitializerRegistrar

Static-initializer registration hook: reads the sub_52E070 function pointer global, casts it to an int and returns the normalized BooleanToIntConversion result. The registered routine's behavior is not evidenced in this packet; the static-init intent is carried only by the canonical/abi name.

Methods: `0x0052E060`


### VideoSystemInitHelper

__fastcall allocation-and-init wrapper on the video-manager entry path (VidMan_Enter): allocates a 48-byte block, initializes it through EngineInitBlock, publishes it into the caller's output slot and runs RenderUISystemGlobalInit, returning 0 on success and -1 on failure or allocation failure.

Methods: `0x0053D470`


## Compatibility contracts

- **FileStreamModeByteContract** — The byte at +0x5C encodes the stream mode: 114 ('r') selects read mode and 119 ('w') selects write mode. Read paths reject any stream whose mode byte is not 'r' with -2; the tagged-buffer functions require the byte to equal 'w'. A replacement must preserve this byte encoding and the -2 rejection behavior.
- **FileStreamStateContract** — The state field at +0x38 uses -3 (corrupt/integrity failure), -1 (error), 0 (ok/reading) and 1 (EOF); the EOF/error flag at +0x3C is set to 1 when nothing is read. Reset clears both to 0 before a seek-or-close. A replacement must preserve these state values.
- **FileStreamHeaderContract** — The stream carries a 4-byte 'CCCC' header: written through StringFormatWithNestedIO when opening for write and validated through sub_534D50 when opening for read, using the header literal global at 0x005DA788. Read mode then computes the data size as file size minus the stored offset.
- **ResourceRegistryLayoutContract** — Registry nodes are 2164-byte heap allocations with the key name at node+20 (0x14) and the next pointer at node+2160 (0x870); the list head is the global dword_8B8E20. Lookup compares stripped names; registration uses a hashtable init and an append helper. A replacement must preserve the node layout and the head global.
- **D3D8InterfaceContract** — The render system holds an IDirect3D8 object at +0x10FC and a device at +0x1100, created through the imported Direct3DCreate8 with SDK version 220 (callee 0x59B250) and released through vtable slot +8. A replacement must either provide equivalent D3D8 COM behavior or preserve the import surface.
- **MpegAudioTimingContract** — MPEG audio buffer/timing derived from the sample rate at +0x2484 and a 5x mode multiplier at +0x2494: timing quotient is (28800 x 5 x mode) / rate and the remainder is scaled down by 100; buffer size is 768x (mono flag +0x2490 == 1) or 2304x the channel multiplier at +0x24CC. Both derived values and the /100 scaling must be preserved.

## Unresolved

- The owners of most functions are UNKNOWN at the function-IR level; the class grouping above is a DERIVED/GUESS proposal, not a confirmed identity.
- CMpegAudioDecoder (0x52DE60, 0x52E2F0): the enclosing object type is not evidenced; the MPEG-audio naming is inherited from the prelabel and fill prose, not from the raw bodies. The exact role of +0x24D4 (set to 1) and the /100 scaling rationale are not evidenced.
- StaticInitializerRegistrar (0x52E060): the identity and purpose of sub_52E070 are unknown; the static-init intent is carried only by the canonical/abi name, and no caller evidence is recorded.
- CFileStreamContext: the destructor prose labels +0x44 as the write buffer and +0x48 as the read buffer, while the constructor allocates the read input buffer at +0x44 and the write output buffer at +0x48, and the reset reads +0x44 as the saved stream/handle. The mapping is inconsistent across the packet and is left unresolved.
- CFileStreamContext this+0x5C is asserted as the mode byte; the existing_analysis table additionally maps 0x5C to a decompression read buffer (lpMem[23]), which is not supported by the raw source.
- The meaning of TLS error code 29 and the precise free semantics of sub_58AA6F are not in this packet.
- The 'w' cleanup sub_5361D0 and 'r' cleanup GuardedFunctionCallCleanup (0x535660) are named from the packet callee list only; their internal behavior is out of scope.
- ReadBufferedFileBytes: the precise role of sub_5357E0 (state advance), the F_4BitFieldPack integrity comparison, and the semantics of the count at +0x4C are DERIVED from context.
- CTaggedStreamBuffer (0x535220, 0x5352D0): all object field offsets come from the raw decompiled source only; the packet carries no field evidence entries for them, and the layout may coincide with CFileStreamContext offsets without proven common ownership. The parse status constants (-5, 1, 2+) from sub_535E80 are not derivable from this packet.
- GlobalRenderCompositor: off_5B8938 is only evidenced as a data pointer installed in the object's first field; the render-compositor vtable claim and the NetConfigData / D3DDeviceWrapperPtr identities for dword_8B8F18/dword_8B8F24 are DERIVED. The instance is a minimal 4-byte object, and why two globals receive the same pointer is unknown.
- GlobalRenderCompositor shutdown (0x53C4D0): the exact resource kinds behind the globals (render handles, network config, sound manager) are labelled DERIVED; dword_8B78A0 is read indirectly and only its address is passed to the release call.
- GlobalListPruner (0x53CED0): the +0x12C/+0x130 link fields and the +0x114 flag byte are read from the raw source with decimal offsets; their roles (prev/next/flag) and the meaning of bit 3 (value 8) are DERIVED from the traversal pattern, not confirmed by packet field evidence. dword_8B8F14 as list head and dword_8B6AC0 as node count are DERIVED labels.
- ResourceRegistry: node layout is only partially evidenced (name at +20, next at +2160, total size 2164 bytes); the sub_589901 string transform and sub_552470 registration-check semantics are unconfirmed. The ABI lead name suggests extension fallback behavior but the raw source strips the extension before matching. The 0x53D130 ABI lead names the search 'matching wide string' while the code compares narrow strings with strcmp.
- D3DRenderSystem 0x540760: the prelabel AudioStreamChainCleanup contradicts its D3D-init caller role in 0x53D750; the chain descriptors at +0x1170/+0x1178/+0x1180 expose nested field evidence but the exact mapping between list slots and nested descriptor pointers is inferred from field bases and not independently verified. Chain 4 has no nested field evidence even though its node layout matches chain 3.
- D3DRenderSystem: the render-mode flag semantics at +0x13DC and the many zeroed render-state fields are inferred from call shape only; the exact render-state meanings are not established by this function alone.
- VideoSystemInitHelper (0x53D470): the pass-through arguments a2-a5 handed to RenderUISystemGlobalInit are unknown, and returning -1 on both init failure and allocation failure is inferred, not stated by evidence.
- ObjectCleanupHelper (0x53CB90): the relationship between the unconditional sub_542E50 phase and the null-guarded EmptyStub/Free phase is not established; the null check after sub_542E50 is unusual for a pure free path. The ABI record is LEGACY with no prototype.
- Globals dword_5DA780 and dword_5DA784 appear in the packet evidence but not in the raw function text; their roles are unidentified.
- ObjectAllocationHelper (0x53CAC0) and VideoSystemInitHelper (0x53D470) are structurally twin allocation-and-init wrappers (both allocate 48 bytes, zero-init, publish into *a1) but belong to different subsystems (audio mixer channel vs video manager); the parallel is noted without merging.
- The strcpy CRT call in 0x53C5B0 is not recorded in packet callees, so no callee evidence reference exists for it.
- The exact reason the DoublyLinkedListUnlink return value changes to the new head only in the head-removal case is not established by this packet.
- CFileStreamContext candidate fields +0x0C (dest cursor), +0x10 (remaining count), +0x14 (aux position) and +0x58 (stream control flag) were dropped from the class field table because the packet carries no matching field:this evidence refs for those offsets (they appear only in raw-source prose); their existence is asserted by the read-loop body of 0x534F90 but left unresolved rather than forced into the class.
- CTaggedStreamBuffer candidate fields +0x0C and +0x10 were dropped for the same reason as above (offsets appear only in raw-source prose of 0x535220/0x5352D0, no field:this evidence refs in the packet); the remaining +0x00/+0x04/+0x38/+0x40/+0x48/+0x4C/+0x5C fields were retained with their matching refs.
- ResourceRegistry node layout fields (name at node+0x14, next pointer at node+0x870) were dropped from the class field table because the packet's evidence refs carry no RegistryNode base; the node layout is asserted only in the 0x53CFE0/0x53D130 raw bodies and is tracked in the ResourceRegistryLayoutContract prose instead.
- GlobalListPruner node fields (+0x114 flag byte, +0x12C prev, +0x130 next) were dropped from the class field table because the packet's evidence refs carry no PruneNode base; the +0x12C/+0x130 link and +0x114 flag roles remain DERIVED from the traversal pattern in 0x53CED0 and are not confirmed by packet field evidence.
