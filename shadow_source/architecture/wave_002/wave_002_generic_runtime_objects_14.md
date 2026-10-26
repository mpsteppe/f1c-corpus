# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Reconstructs the generic runtime object layer from nineteen validated functions. One DERIVED class (CMpegFilePlayer, 0x0052E1D0) covers MPEG audio player open/init with buffer-size computation and stream activation. Four GUESS classes cover a 2D resource/renderer owner (0x0053EAD0/0x0053F270), a DirectX resource owner with multi-list and counted-pool teardown (0x00543BF0), an audio mixer channel constructor (0x005435D0), and a shared string registry (0x0053C800/0x0053C900). One GUESS loader class covers the .MAS cube-map file loader (0x0053CBC0). A GUESS interface IBlitFunctionTable captures the function-pointer table installed by 0x0051CB6D. Ten functions (input-binding config 0x0051CB6D, import thunk 0x0052D8B0, Huffman renderer 0x00530050, flag selector 0x0053AC70, global zero-init 0x0053C2A0, release wrappers 0x0053F6E0/0x00540DA0/0x00540EB0, bitmask dispatch 0x00540150, surface compositor 0x00543250, audio free 0x00540CB0) have UNKNOWN owners and are kept unowned or assigned to minimal owner classes where the packet's caller evidence is suggestive but not definitive. No state machine evidence was found; the switch dispatches in 0x00530050 and 0x0053CBC0 are treated as dispatch chains, not state machines. Field semantics and several owner identities remain unresolved and are preserved in the per-function evidence.

## Function roles

- `0x0051CB6D` **UnknownObject** — Rendering/configuration blit-table setup: allocates a 24-byte function-table substruct via the allocator at this+0x4, stores it at this+0x1A0, seeds slot 0 with nullsub_4, validates sub-mode this+0x24 against mode this+0x20, sets obj+0x14 to 8 and dispatches on mismatch, then selects the blit handler installed at v1[1] from this+0x28 (1 installs F_2DCopyDelegation, 2 and 4 install sub_51C94F / F_2DBlitTextureCopy or sub_51C6E1 / F_2DBlitTextureCopy with TableInitWithArithmeticProgression, fallback installs F_2DBlitTextureCopy), finalizes channel mode at this+0x64 and this+0x68, and returns the mode.
- `0x0052D8B0` **UnknownObject** — DirectInput8Create import thunk: forwards hinst, dwVersion, riidltf, ppvOut and punkOuter to the imported __imp_DirectInput8Create and returns its HRESULT.
- `0x0052E1D0` **CMpegFilePlayer** — MPEG audio file-player open/init: guards on the active flag this+0x24EC, sets it to 1, extracts encoding bits 6-7 of a file-header byte into this+0x24A4, validates the file magic via a byte-swapped ArithmeticComparison_de40 or through the virtual method at vtable+0xC (assert-failure paths call off_5DA714 and return -1), runs sub_52DA10 stream setup, AudioNetworkBufferTimingCalc, and LapPerformanceStateReset, computes buffer sizes through F_64BitIntegerDivision into this+0x24A0 and this+0x24B0, activates the audio stream through the device vtable+0xC, sets this+0x2D3C, and returns 0 on success.
- `0x00530050` **UnknownObject** — Huffman audio sample renderer: iterates granule/subband groups (this+0x24B8) and per-granule samples (this+0x24CC), decodes each Huffman symbol through dword_5B4788 while advancing the bit cursor this+0x24A8 over the input buffer this+0x24A4, writes three interleaved float samples via the DCT table flt_5B10A4 and scale-factor offsets dword_5DA738, zero-fills trailing output slots for the subband count, and for a channel count of 2 zero-fills the second stereo half; returns this+0x24CC.
- `0x0053AC70` **UnknownObject** — Short flag-gated __int16 selector: with flag bit 0x4 returns a1 | 0x3F (forces low six bits), with flag bit 0x8 returns a1 & 0xC0 (masks to high two bits), otherwise returns the input flag byte unchanged; caller list spans AI, scene, wheel, engine, camera and audio subsystems.
- `0x0053C2A0` **UnknownObject** — Trivial global zero-init helper: writes 0 to the global dword_8B6AB8 and 0 to the global byte_8B6AC8, then returns the (otherwise unused) this pointer unchanged; 36 recorded callers across engine, audio, input, hash-table and struct-init paths suggest a shared module/global zeroing routine.
- `0x0053C800` **StringRegistry** — String registry insert: copies the input string into a 256-byte stack buffer, normalizes it via sub_589901, dedupes with strcmp over the 32x132-byte records at byte_8B5A3C (count dword_8B8E30), and on a new entry shifts every existing record up one 132-byte slot (ArithmeticComparison_c6b0 indexed through dword_8B5A38), writes the new string into slot 0 and increments dword_8B8E30; returns 0 on duplicate or the copy index + 1 after an insert.
- `0x0053C900` **StringRegistry** — String registry lookup with flag set: copies the input string a2 into a stack buffer, normalizes via sub_589901, walks the 132-byte-strided records at byte_8B5A3C for dword_8B8E30 entries comparing with strcmp, sets the 0x400 flag on dword_8B5A38[33 * v4] on a match, and returns SearchPathPrune(this) for every search outcome; empty inputs return a2 unchanged.
- `0x0053CBC0` **CubeMapFileLoader** — .MAS cube-map file loader: uppercases the filename via sub_589901, opens the file directly or by retrying across the registered path-prefix array (dword_8B8E30 entries at byte_8B5A3C, stride 132) with an rb mode string, reads and validates the 12-byte header magic, and on the Cubemas410 magic allocates a 308-byte object, initializes it via sub_55FBE0, parses it via sub_55FC40, and links it into the singly linked list rooted at dword_8B8F14 (next at offset 304, back pointer at offset 300); other magics report an incorrect-file error and open failures report -2 through sub_53C590.
- `0x0053EAD0` **RendererResourceOwner** — Renderer resource teardown: calls RenderTargetCleanup(0), then releases three sub-resources at this+0x152C, this+0x1524 and this+0x1528 (first through sub_53F6E0, all through EmptyStub_7470 / FreeWrapper_7bcf, each nulled), then releases the sub-object at this+0x1100 through its vtable method at offset 8, stores the result into *this and nulls this+0x1100.
- `0x0053F270` **RendererResourceOwner** — Conditional render-target resource cleanup gated on the flag at this+0x13A8 having the 0x10000000 bit set: releases this+0x1140 / this+0x113C via ObjectResetWithVirtualRelease and this+0x1144 via a draining-loop finalizer, each freed and nulled; resets the state counter at this+0x13A0 to 1 and five state flags at this+0x14F0..0x1500 to 0; walks two linked lists (heads at this+0x1518 and this+0x1580) resetting children and running UICleanupIterator where a +84 flag is set; optionally cleans an audio/D3D object a2; then clears the 0x10000000 flag.
- `0x0053F6E0` **UnknownObject** — Sub-object release wrapper: reads the sub-object pointer at a2+12, invokes its __stdcall vtable method at offset 8, stores the result into this+0, nulls a2+12 on a zero result and returns 0; a non-zero result logs through sub_53C590 with the aInvalidParamet string and returns -1.
- `0x00540150` **UnknownObject** — Bitmask-based virtual dispatch to surface accessors: selects among sub-objects at a1+0x8, a1+0xC and a1+0x10 by the lower three bits of the selector (a3, or a1+0x18 when a3 is 0), calls the bit-1/bit-2 result through its vtable entry at offset 40, and dispatches the bit-4 path through vtable[17] of a1+0x10 with a2 as the argument; called by ArgumentReorderWrapper_3230.
- `0x00540CB0` **AudioResourceOwner** — Audio resource free: branches on the state flag at this+0x13DC to select the teardown path for the sub-resources of an audio object a2 (buffers at a2+28 and a2+36, flag/pointer fields at a2+44 and a2+48) - direct FreeWrapper_7bcf when the flag is set, or virtual release plus draining-loop finalizer when clear; returns 0 on both paths.
- `0x00540DA0` **UnknownObject** — Conditional bitmask cleanup: when a1 is non-null and bit 4 of a2 is set, calls ArithmeticComparison_0f90 on a1[7] (offset 0x1C) and clears a1[8] (offset 0x20); when bit 8 of a2 is set, calls GuardedVirtualDecrement on a1[9] (offset 0x24) and clears a1[10] (offset 0x28); returns the last release result; used by sub_557670 and sub_558310.
- `0x00540EB0` **UnknownObject** — Object reset paired with virtual release: when the secondary object a2 holds a releaseable resource at a2+0x20, repeatedly calls ArithmeticComparison_0f90(a2) while the reference count at a2+0x14 is positive, zeroes that count, invokes the resource object's vtable release method at offset 8 (stdcall), stores the result into this+0, and clears the resource slot a2+0x20; returns void and is called from eight teardown/cleanup routines.
- `0x00543250` **UnknownObject** — 2D surface region compositing with clipping: folds negative source extents (a5, a6) into the destination position, clips destination (a2, a3) and source (a5, a6) rectangles against the extent pair (a7, a8) via sub_543540, and when the clipped region is non-empty composites through F_2DSurfaceCompositing with the global surface context dword_8B78A0 and clears bit 0x400 on a4[6]; returns the region width a7 when no compositing occurs, otherwise the compositing result.
- `0x005435D0` **AudioMixerChannel** — Audio mixer channel constructor: zeroes the base object region via GlobalZeroInit_c2a0, initializes a two-byte sub-region at this+104 via TwoFieldInitializer, then explicitly writes 87 state fields (mixer dwords to 0, buffer size 0x2000 at this+0xEC, enable flag 1 at this+0x10C, sentinel 11513775 at this+0x154, three 1.0f gains at this+0x17C/0x180/0x184, layout words 180/160/160 at this+0x188/0x18A/0x18C, a 1000.0f limit at this+0x198 and a 1.0f factor at this+0x1D4), then initializes the sub-object at this+272 via ObjectAllocationWithInit and returns this; invoked by AudioEngineInitialization.
- `0x00543BF0` **DirectXResourceOwner** — DirectX/render resource owner teardown: walks each owned linked list and calls the per-node destructor (scene graph nodes via SceneGraphTreeDestructor, render objects via DestroyFree, 3D sound sources via F_3DSoundSourceDestructor, three resource arrays via sub_5454A0, and a doubly-linked node list), then frees counted arrays (528-byte and 56/24-byte element pools) element-by-element and releases their backing blocks, zeroes the emptied owner pointers, performs an audio-network-stream cleanup, frees a global render resource dword_8B8F2C via sub_5593D0, and returns -1 early when LinkedListWalkWithExitCheck aborts; invoked by MutexSemaphoreCleanup during shutdown.

## Proposed classes

### CMpegFilePlayer

MPEG audio file player: active-flag gating, file-magic validation, audio buffer-size computation via 64-bit integer division, stream/device setup, lap-performance-state reset, and audio-stream activation through the device vtable; opened/initialized by 0x0052E1D0.

Methods: `0x0052E1D0`

- `this+0x00000000` `void* vtable_ptr` (read, GUESS)
- `this+0x0000248C` `dword buffer_multiplier` (read, GUESS)
- `this+0x000024A0` `dword buffer_quotient` (write, GUESS)
- `this+0x000024A4` `dword encoding_format` (write, GUESS)
- `this+0x000024B0` `dword buffer_alloc_size` (write, GUESS)
- `this+0x000024D4` `dword buffer_size_operand_a` (read, GUESS)
- `this+0x000024D8` `dword buffer_size_operand_b` (read, GUESS)
- `this+0x000024DC` `dword buffer_size_operand_c` (read, GUESS)
- `this+0x000024E0` `dword buffer_size_operand_d` (read, GUESS)
- `this+0x000024EC` `dword player_active_flag` (read_write, GUESS)
- `this+0x00002D34` `void* audio_stream_device` (read, GUESS)
- `this+0x00002D38` `dword audio_stream_param` (read, GUESS)
- `this+0x00002D3C` `dword stream_active_flag` (write, GUESS)

### AudioMixerChannel

Audio mixer channel object: leading mixer-state dwords, a buffer-size field (0x2000 at +0xEC), an enable flag (+0x10C), a sentinel (+0x154), three 1.0f gain fields, width/height layout words 180/160/160, a 1000.0f limit, a 1.0f factor, and a sub-object initialized at +272; constructed by 0x005435D0 and invoked from AudioEngineInitialization.

Methods: `0x005435D0`

- `this+0x0000006C` `byte byte_flag` (write, GUESS)
- `this+0x000000EC` `dword buffer_size` (write, GUESS)
- `this+0x0000010C` `dword enable_flag` (write, GUESS)
- `this+0x00000154` `dword sentinel` (write, GUESS)
- `this+0x0000017C` `float gain_a` (write, GUESS)
- `this+0x00000180` `float gain_b` (write, GUESS)
- `this+0x00000184` `float gain_c` (write, GUESS)
- `this+0x00000188` `word layout_width` (write, GUESS)
- `this+0x0000018A` `word layout_height_a` (write, GUESS)
- `this+0x0000018C` `word layout_height_b` (write, GUESS)
- `this+0x00000198` `float gain_limit` (write, GUESS)
- `this+0x000001D4` `float gain_factor` (write, GUESS)

### StringRegistry

Shared fixed-capacity (32 entries x 132 bytes) most-recent-first string registry: insert with dedupe and slot shifting (0x0053C800) and lookup with a 0x400 flag write on match (0x0053C900); records live at byte_8B5A3C, count at dword_8B8E30, and a stride-indexed dword array at dword_8B5A38.

Methods: `0x0053C800`, `0x0053C900`

- `this+0x00000000` `char* input_string_ptr` (read, GUESS)

### CubeMapFileLoader

.MAS cube-map file loader: uppercases and opens the file (directly or via the registered path-prefix array), validates the 12-byte Cubemas410 magic, allocates and initializes a 308-byte object, parses the file, and links the object into the singly linked list rooted at dword_8B8F14 with count dword_8B6AC0; error paths report through sub_53C590.

Methods: `0x0053CBC0`

- `this+0x00000000` `void* output_object_ptr` (write, GUESS)

### RendererResourceOwner

2D renderer resource owner: teardown releases the +0x1100 sub-object via vtable[8] and the +0x1524/+0x1528/+0x152C pointers (0x0053EAD0); render-target cleanup is gated on the 0x10000000 flag at +0x13A8, releases the +0x113C/+0x1140/+0x1144 resources, resets +0x13A0 and the +0x14F0..0x1500 state flags, and walks the +0x1518 and +0x1580 child lists (0x0053F270).

Methods: `0x0053EAD0`, `0x0053F270`

- `this+0x00000000` `dword result_slot` (write, GUESS)
- `this+0x00001100` `void* release_sub_object` (read_write, GUESS)
- `this+0x0000113C` `void* render_target_resource_a` (read_write, GUESS)
- `this+0x00001140` `void* render_target_resource_b` (read_write, GUESS)
- `this+0x00001144` `void* render_target_resource_c` (read_write, GUESS)
- `this+0x000013A0` `dword state_counter` (write, GUESS)
- `this+0x000013A8` `dword cleanup_flag` (read_write, GUESS)
- `this+0x000014F0` `dword state_flag_0` (write, GUESS)
- `this+0x000014F4` `dword state_flag_1` (write, GUESS)
- `this+0x000014F8` `dword state_flag_2` (write, GUESS)
- `this+0x000014FC` `dword state_flag_3` (write, GUESS)
- `this+0x00001500` `dword state_flag_4` (write, GUESS)
- `this+0x00001504` `dword list_loop_seed` (write, GUESS)
- `this+0x00001518` `void* child_list_head_a` (read_write, GUESS)
- `this+0x00001524` `void* sub_resource_a` (read_write, GUESS)
- `this+0x00001528` `void* sub_resource_b` (read_write, GUESS)
- `this+0x0000152C` `void* sub_resource_c` (read_write, GUESS)
- `this+0x00001580` `void* child_list_head_b` (read, GUESS)

### AudioResourceOwner

Audio resource owner holding a state flag at +0x13DC that selects between direct-free and virtual-release teardown paths for an owned audio object's buffers (a2+28/+36/+44/+48); freed by 0x00540CB0.

Methods: `0x00540CB0`

- `this+0x000013DC` `dword teardown_mode_flag` (read, GUESS)

### DirectXResourceOwner

DirectX/render resource owner torn down by 0x00543BF0: scene-graph list (+0xF8), render-object list (+0x100), 3D-sound list (+0x108), audio network stream (+0x110), doubly-linked node list (+0x118), three resource-array lists (+0x120/+0x128/+0x130), 56-byte pool (+0x138) and 24-byte pools (+0x140/+0x150/+0x178), selective-free flag (+0x1AC), and four 528-byte pools (+0x1B8/+0x1C0/+0x1C8/+0x1D0), plus a global render resource dword_8B8F2C.

Methods: `0x00543BF0`

- `this+0x000000F8` `void* scene_graph_list_head` (read_write, GUESS)
- `this+0x00000100` `void* render_object_list_head` (read_write, GUESS)
- `this+0x00000108` `void* sound_source_list_head` (read_write, GUESS)
- `this+0x00000110` `void* audio_network_stream` (read, GUESS)
- `this+0x00000118` `void* node_list_head` (read_write, GUESS)
- `this+0x00000120` `void* resource_array_list_1` (read_write, GUESS)
- `this+0x00000128` `void* resource_array_list_2` (read_write, GUESS)
- `this+0x00000130` `void* resource_array_list_3` (read_write, GUESS)
- `this+0x00000138` `void* pool_56_byte` (read_write, GUESS)
- `this+0x00000140` `void* pool_24_byte_a` (read_write, GUESS)
- `this+0x00000150` `void* pool_24_byte_b` (read_write, GUESS)
- `this+0x00000178` `void* pool_24_byte_c` (read_write, GUESS)
- `this+0x000001AC` `dword selective_free_flag` (read, GUESS)
- `this+0x000001B8` `void* pool_528_byte_a` (read_write, GUESS)
- `this+0x000001C0` `void* pool_528_byte_b` (read_write, GUESS)
- `this+0x000001C8` `void* pool_528_byte_c` (read_write, GUESS)
- `this+0x000001D0` `void* pool_528_byte_d` (read_write, GUESS)

## Compatibility contracts

- **BlitFunctionTableInstall** — The rendering configuration setup (0x0051CB6D) must allocate a 24-byte function-table substruct through the allocator at this+0x4, store it at this+0x1A0, seed slot 0 with nullsub_4, validate the sub-mode this+0x24 against the mode this+0x20 (accepted for modes 1/3/4 or mode >= 1 for higher sub-modes, else obj+0x14 set to 8 and dispatch), select the handler installed at v1[1] by the blit type this+0x28 (1 -> F_2DCopyDelegation with 84-byte-strided channel clears, 2/4 -> sub_51C94F or sub_51C6E1 with TableInitWithArithmeticProgression, fallback -> F_2DBlitTextureCopy), and finalize this+0x64 and this+0x68 channel mode.
- **MpegFilePlayerOpen** — Opening the MPEG file player (0x0052E1D0) must guard on the active flag at +0x24EC, validate the file magic (byte-swapped ArithmeticComparison_de40 or the virtual open method at vtable+0xC), run stream/device setup (0x0052DA10), compute network buffer timing (0x0052DE60), reset lap-performance state (0x0052E2F0), compute buffer sizes via F_64BitIntegerDivision into +0x24A0/+0x24B0, and activate the audio stream through the device vtable+0xC before returning 0; failure paths emit AudioAssert through off_5DA714/off_5DA718 and return -1.
- **StringRegistryInsert** — Registering a string (0x0053C800) must normalize it via sub_589901, dedupe against the fixed 32x132-byte records at byte_8B5A3C, shift every existing record up one 132-byte slot when inserting (keeping the newest at slot 0), write the new record into slot 0, and increment the count dword_8B8E30.
- **MASCubeMapFileLoad** — Loading a .MAS cube-map file (0x0053CBC0) must uppercase-normalize the filename, open it directly or by retrying across the registered path-prefix array (dword_8B8E30 entries at byte_8B5A3C, stride 132), read and validate the 12-byte header magic, and for a Cubemas410 magic allocate a 308-byte object, initialize it via sub_55FBE0, parse it via sub_55FC40, and link it into the singly linked list rooted at dword_8B8F14; open failures must report -2 through sub_53C590.
- **RendererResourceTeardown** — Tearing down the renderer resource owner (0x0053EAD0) must first run RenderTargetCleanup(0), then free the +0x152C, +0x1524 and +0x1528 sub-resources (first through 0x0053F6E0, all via EmptyStub_7470 / FreeWrapper_7bcf), and release the +0x1100 sub-object through its vtable method at offset 8, storing the result into +0 and nulling +0x1100.
- **DirectXResourceTeardown** — Tearing down the DirectX resource owner (0x00543BF0) must walk the scene-graph, render-object, 3D-sound, resource-array and doubly-linked node lists calling each per-node destructor, free the counted arrays (528-byte, 56-byte and 24-byte element strides) element-by-element and release their backing blocks, zero the emptied owner pointers, perform an audio-network-stream cleanup, release the global render resource dword_8B8F2C, and return -1 early when LinkedListWalkWithExitCheck aborts.

## Unresolved

- 0x0051CB6D: the relationship between mode (this+0x20), sub-mode (this+0x24) and blit type (this+0x28) and real input-binding semantics is not established; the function is structurally a rendering configuration table installer and the owner class is unknown; the 8 versus 25 state values written to obj+0x14 are treated as error-versus-valid markers from existing analysis (DERIVED), not proven here.
- 0x0052D8B0: pure import thunk; no body-level logic beyond the forward call.
- 0x0052E1D0: offsets this+0x2533 and this+0x33 appear only in the raw decompiler text, not in the field table; sub_52E4E0 and HaltAssertHandler are listed as callees but not visible in the decompiled source (likely the targets behind the off_5DA714/off_5DA718 assert pointers, unproven); the exact file-format magic contract is not recoverable from this function alone.
- 0x00530050: the two jump tables jpt_5302EF and jpt_5304EA drive switch dispatch that Hex-Rays collapsed into fallthrough zero-fill chains and their exact mapping is not pinned down; the precise relationship between the -64/0/+64 output lane triplets and the subband/stereo layout of the output buffer is not confirmed.
- 0x0053AC70: meaning of flag bits 0x4 and 0x8 unknown; the caller list spans AI, scene, wheel, engine, camera and audio subsystems so the two transform paths likely serve different consumers; the char-result / __int16-return width mismatch and the default path returning the flag byte rather than a1 are unresolved.
- 0x0053C2A0: the this pointer is unused by the body; whether dword_8B6AB8 and byte_8B6AC8 are module state shared by all 36 callers is DERIVED from caller context only.
- 0x0053C800 / 0x0053C900: what sub_589901 does to the string (normalization, lowercasing, trimming) is unknown; the differing return values of 0x0053C800 (0 on duplicate vs index+1 on insert) have unclear consumer semantics; why the registry keeps the newest entry at slot 0 and who reads the entries is unknown; the 132-byte record stride versus the 33-dword dword_8B5A38 stride is consistent only arithmetically and the real layout is unverified; the meaning of the 0x400 flag on dword_8B5A38[33 * v4] is unknown.
- 0x0053CBC0: global aSS_3 (0x005C2D64) is listed in the packet globals but not referenced by the reconstructed source; sub_55FBE0 and sub_55FC40 (object construction and MAS parse) are only evidenced by their call signatures; sub_53C590 is treated as an error-reporting routine matching the ErrorHandlerSet label but its reporting channel is not evidenced.
- 0x0053EAD0: parameter a2 is present in the prototype but never used; the identities of the three freed resources (+0x1524/+0x1528/+0x152C) and of the sub-object at +0x1100 are not established; the semantic difference between sub_53F6E0 and EmptyStub_7470/FreeWrapper_7bcf is not established.
- 0x0053F270: the indirect device/sub-object fields reached through this+0x1580 (deref chain 0x868/0x870 and 0x54) and the sub-object vtable offsets 0x30/0x34/0x40 are flagged by packet facts but absent from the raw decompiled source and are attributed to D3D device release internals, unverifiable from this packet.
- 0x0053F6E0: the identity of the object type at a2+12 and the exact contract of vtable slot offset 8 are unknown (callers suggest a rendering/D3D resource, unconfirmed); why the release result is also mirrored into this+0 is not explained.
- 0x00540150: the owner type is unknown; the three sub-object pointers at a1+0x8, a1+0xC and a1+0x10 are only known as vtable-bearing objects; why the selector is reduced to its low byte and how the lower-3-bit mask maps to a documented surface bitfield is not determinable; the vtable[17] dispatch re-reads a1+0x10 rather than the prior result variable (two distinct objects or a decompiler artifact, unresolved).
- 0x00540CB0: the sub-resource layout at a2+28/+36/+44/+48 (buffer and flag/pointer pairs) is assumed and packet field evidence covers only this+0x13DC; why the two teardown paths diverge is not explained; the this+0x13DC flag setter is not visible here.
- 0x00540DA0: the exact object type holding the four pointer/result fields is unknown and the reference-count semantics of the two release routines are unconfirmed; bits other than 4 and 8 in the bitmask are not exercised.
- 0x00540EB0: the a2 object layout (resource pointer at +0x20, reference count at +0x14) is accessed by raw offsets and is not defined as packet fields; the resource object type behind the virtual release call (vtable entry 8) is unknown; the prelabel is a cluster_copy from structural twin 0x0040D470 (DERIVED) but owner trust stays UNKNOWN.
- 0x00543250: exact clipping semantics of sub_543540 (intersection versus clamp) are inferred, not evidenced; the meaning of a4[6] bit 0x400 and of a9/a10 is not visible; dword_8B78A0 (a global render surface/driver context) has no type evidence here.
- 0x005435D0: the TwoFieldInitializer target this+104 and the ObjectAllocationWithInit target this+272 are not enumerated among the packet field evidence so their byte-level layout is not represented; the meaning of the sentinel 11513775 at +0x154 and the 0x2000 buffer-size value depends on the mixer consumer, outside this packet; whether GlobalZeroInit_c2a0 also clears the sub-region set by TwoFieldInitializer is not verifiable.
- 0x00543BF0: seven this-relative offsets (0x148, 0x154, 0x18C, 0x194, 0x19C, 0x204, 0x2B0) appear in the packet field facts as base-pointer reads but never as this[N] accesses in the raw source; the paired node-relative facts do match the list-walk offsets, so they are likely the IDB names for the sub-object bases, but the mapping is not directly reconcilable from this packet; node-relative next/child offsets 440/260/76/108/48 and the counted-array strides 528/56/24 with the *(array - 4) element-count header are carried only by source:raw; EmptyStub_0170 (0x004B0170) is a stub and whether it performs real per-element destruction is not verifiable; the meaning of the global dword_8B8F2C is not established.
- No state-machine evidence was found: the switch dispatches in 0x00530050 (zero-fill chains keyed on this+0x24B8) and 0x0053CBC0 (parse-result dispatch on sub_55FC40) are dispatch chains, not persistent state machines, so state_machines is empty.
- Equal offsets on different bases are not merged: the this+0x24A4 encoding field of CMpegFilePlayer (0x0052E1D0) and the this+0x24A4 Huffman input buffer of 0x00530050 share a numeric offset but the latter's owner is UNKNOWN, so they are kept as separate base/offset field identities.
