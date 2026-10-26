# UiPlatformAndOptions

Scope: `ui_platform_and_options`  
Trust: `DERIVED`

19 functions in the ui_platform_and_options scope reconstruct as: (1) a DirectX renderer configuration object (GraphicsDeviceConfiguration) covering surface initialization 0x0053D4F0, device configuration 0x0053E070, format-aware surface blit 0x0053FD40 and device buffer creation 0x00540DF0, all sharing the this+0x10FC..0x1580 config region and the DirectX adapter/device callee set; (2) UI element operations (UiElement: 0x00543800 color, 0x00543870 position, 0x0055D410 property) and an element-list manager (UiSceneManager: 0x0054BDC0 bitfield state, 0x0054F7A0 focus/render) sharing the UI-root global 0x008B8F28; (3) standalone helpers with no this-field evidence: AudioResampleFilterTableBuilder 0x00502C28, StreamSerializationHelper 0x005355F0, GuidFormatter 0x0053D8E0, RotationMatrixBuilder 0x00541DB0, SparseMatrixPatternBuilder 0x0056C830; (4) synchronization objects: ThreadResumeController 0x00585680, MutexGuardedFieldWriter 0x00585CD0, LocaleFacet 0x00598C1C, ThreadSafeCounter 0x00598C4A. Every function owner is UnknownObject in the packet, so all class boundaries, method groupings and field names are GUESS synthesis; offsets, addresses, globals, callees and literals are taken verbatim from packet evidence.

## Function roles

- `0x00502C28` **AudioResampleFilterTableBuilder** — Builds a sample-rate-conversion filter table: guards a1/a2 nonzero, computes ratio a2/a1, estimates a size via CRTFtol (0x00587BDC), allocates via OperatorNewNhMallocWrapper (0x00587C03), then fills two-phase (source-index dword, weight float) record pairs per output position with clamp (a3==0) or wrap mode, writes per-phase byte lengths and the total table size at the end. Returns the table pointer, or null on guard/allocation failure.
- `0x005355F0` **StreamSerializationHelper** — Serializes the 32-bit value a2 as four least-significant-byte-first bytes through BufferedCharacterWriteWithOverflowHandling (0x00589898), shifting a2 right by 8 each iteration; returns the last write result. Called by StreamFileTypeCheckWithDispatch (0x005355A0).
- `0x0053D4F0` **GraphicsDeviceConfiguration** — Initializes the DirectX renderer configuration object: resets device globals 0x008B6AC8 / 0x008B6AB8, zero-initializes eight render-pass sub-structures via StructZeroInitConstructor (0x00553DE0) at 17-dword strides from dword index 1118, then applies fixed defaults: zeroed state, 8192/32768 buffer limits, identity 1.0f scales, debug color key 11513775, 640x480 viewport with 7680x1200 backing, and buffer parameters 512/6. Returns this.
- `0x0053D8E0` **GuidFormatter** — Formats a 16-byte GUID as the hyphenated hex string "%.8X-%.4X-%.4X-%.2X%.2X-%.2X%.2X%.2X%.2X%.2X%.2X" (format literal at 0x005DBC5C) via StringFormatWithBufferOverflowCheck (0x0058815F), reading Data1 (+0x0), Data2 (+0x4), Data3 (+0x6) and eight Data4 bytes (+0x8..+0xF). Called from VidMan_Enter (0x004FA000).
- `0x0053E070` **GraphicsDeviceConfiguration** — Configures the Direct3D device: releases prior renderer resources (0x0053EAD0), rebuilds device state when this+0x1100 is null (0x0053D970), creates three audio emitters at this+0x1524/0x1528/0x152C, negotiates display/backbuffer/depth-stencil formats and multisample modes through the adapter vtable, selects format codes, configures windowed/fullscreen present parameters, creates the device, sets the render target, configures the audio emitter device, extracts capability flags, and returns -1 on any setup failure (else the negated verification result of 0x0053EB70).
- `0x0053FD40` **GraphicsDeviceConfiguration** — Performs a format-aware surface blit: prepares a format buffer (0x0055C650), prepares/allocates the destination surface (0x0053F720), selects source/destination surfaces from the a2/a4 descriptors via the a3/a5 1/2/4/8 flag bits, blits via SurfaceBlitOperation (0x0050099C) with a fill color derived from a4[6], releases temporary surfaces through vtable+8, and optionally copies via D3DSurfaceCopyBlit (0x00500BC8) when a4[11]>1. Stores -1 in *this at the first failure; returns 0 on success; skips the pipeline when a6 & 0x1000000.
- `0x00540DF0` **GraphicsDeviceConfiguration** — Creates a device vertex/index buffer by invoking vtable slot 23 (byte offset 92) on the sub-object at this+0x1100, building a usage/format flag word from this+0x1138 and a2[0] bits, a size a2[2]*a2[3], descriptor a2[1]/mode/a2+8, and storing the handle in this+0x0. Returns 0 on success; logs aInvalidParamet / aErrorCreatingV and returns -1 otherwise.
- `0x00541DB0` **RotationMatrixBuilder** — Builds a 3x3 rotation matrix from Euler angles a2/a3/a4 (each passed through InterruptDispatch 0x0058957A), storing the angles at this+0x30/0x34/0x38, the matrix at this+0x15C..0x188 (4th column zeroed, 1.0f at 0x198), and transforms the orientation vector at this+0x24/0x28/0x2C into this+0x18C/0x190/0x194. Returns 0.
- `0x00543800` **UiElement** — Normalizes three 0-255 byte components to floats via 1/255 (global 0x0059E460) and stores them at this+0x17C/0x180/0x184, dispatches a packed color update through the object at global 0x008B78A0 via VTableDispatchWithFieldCheck (0x00541670), and ORs the 0x800 refresh flag into offset +0xEC of the UI root at global 0x008B8F28. Returns the UI root pointer.
- `0x00543870` **UiElement** — UI element position setter: writes 16-bit a2/a4/a3 into this+0x18C/0x188/0x18A and ORs bit 0x10000 into the flags field at this+0xEC to mark the update pending; returns the updated flags. No guard; always writes. Called by sub_4FCEE0 (0x004FCEE0).
- `0x0054BDC0` **UiSceneManager** — Walks the UI element linked list (head this+0x204, next element+0x10), rewriting each state entry as a2 | (~a3 & old) over the state-entry array (element+0x11C pointer, element+0x118 count). When a2 bit 5 is set, derives a color word from global counter 0x008B8F28+432 and applies it to sub-element color slots (SingleCallWrapper_e0e0 0x0054E0E0 / Wrapper_e0f0 0x0054E0F0); otherwise, when a3 bit 5 is set, dispatches state-change callbacks by the low 2 bits of the new state (0x0055D900 / 0x0055DA50 / 0x0055E320) plus 0x0055EB30 when the element flag 0x400000 is set.
- `0x0054F7A0` **UiSceneManager** — Per-frame scene focus and render update: guarded by a2 != this and a non-null render-state descriptor at this+0x1E0. Clears UI focus global 0x008C5F44, prepares the render batch transform (0x0054B570), sets busy bit 0x20000000 on the sub-object at this+0x204 and issues an indirect D3D wrapper call through global 0x008B8F24 vtable+4, then stores RenderListIteration (0x0054F710) into 0x008C5F40 and runs SceneBatchRenderCheck (0x0054F5C0).
- `0x00558310` **MeshIndexBufferBuilder** — Builds vertex/index buffer resources for the mesh object at this+0x50, dispatching on the mode word at this+0x32 (bit 0 vs bit 1 LOD layouts). Allocates and fills a 36-byte vertex-buffer descriptor (size 32, width this+0x2C*this+0x24, height this+0x2C*this+0x28, stride 64, format 1234) at *(this+0x50)+0x1C and a 28-byte index-buffer descriptor (count 2, mesh height) at *(this+0x50)+0x24, creates them via 0x00540DF0 / 0x00540FC0, writes UV pairs and triangle-strip index patterns, copies generated index data to *(this+0x50)+0x28, finalizes via 0x00540D40 / 0x00540DA0, and returns -1 with aErrorCreatingV on creation failure.
- `0x0055D410` **UiElement** — Stores integer a3 into one of three per-group alpha/scale fields selected by a2 (1->0x14, 2->0x24, 3->0x34), refreshes DirectX vertex-buffer texture coordinates via DirectXVertexBufferTextureCoordinateSetup (0x005416A0) using this+0x4 and the selected group mode, and sets the 0x800 dirty flag in the UI root at 0x008B8F28 (+0xEC). Returns the UI root pointer. Called by sub_4FCEE0 / sub_55A500.
- `0x0056C830` **SparseMatrixPatternBuilder** — Builds a CSR-like sparse-matrix symbolic pattern from the dense matrix a2 (dimension a4): normalizes non-zero entries, counts rows/entries, allocates four arrays into this+0x0/0x4/0x8/0xC (row starts, column indices, value offsets, packed column bytes), then fills row-start pointers, per-row column indices and packed value offsets. Returns a4. Frees prior storage via QuadPointerFree (0x0056CF10).
- `0x00585680` **ThreadResumeController** — Thread-management routine: while holding the mutex at this+0xD4 (timeout this+0xD8), computes a float on a sub-object via FloatAdditionReturnsFUN00568d90Param1 (0x00583680) / FloatSetWithTimingCall (0x00583660) and releases the mutex; then, if a thread handle exists at this+0x4, takes a second mutex at this+0x20 (timeout this+0x24) and, when the suspend flag at this+0x1C is set, resumes the thread up to 50 attempts with increasing sleeps until its suspend count drops below 2, clearing the flag. Returns 0 on resume failure, else 1.
- `0x00585CD0` **MutexGuardedFieldWriter** — Mutex-protected field write: when the mutex handle at this+0x5B8 is non-null and WaitForSingleObject(timeout this+0x5BC) returns 0 or 128, writes a2 through the field pointer at this+0x5B4 and releases the mutex; on guard failure the store dereferences null (a latent crash path). Returns the written field pointer.
- `0x00598C1C` **LocaleFacet** — Stores the locale-facet reference returned by sub_59AAB9 into this+0x0, then, under lock (sub_59A54D / sub_59A5E9), thread-safely increments the global reference counter 0x008D4650 via CounterIncrementThreadSafe (0x00598C4A). Returns this.
- `0x00598C4A` **ThreadSafeCounter** — Thread-safe increment of the counter field at this+0x4, guarded against the -1 sentinel: enters a critical section (sub_59A54D), increments unless the value is -1, leaves the critical section (sub_59A5E9), and returns its status.

## Proposed classes

### GraphicsDeviceConfiguration

DirectX renderer configuration object reconstructed from the DirectX device/surface path. 0x0053D4F0 applies the fixed surface configuration defaults (buffer limits, viewport, color key, identity scales, render-pass bookkeeping), 0x0053E070 negotiates formats and creates the device/audio emitters, 0x0053FD40 performs the format-aware surface blit, and 0x00540DF0 creates vertex/index buffers against the device sub-object. All packet owners are UnknownObject; the class boundary and field names are synthesis (GUESS), grounded only in the shared this-offset regions and callee set.

Methods: `0x0053D4F0`, `0x0053E070`, `0x0053FD40`, `0x00540DF0`

- `this+0x00000000` `dword device_result_handle` (read_write, DERIVED)
- `this+0x00000004` `dword bound_format_index` (write, DERIVED)
- `this+0x00000008` `dword head_state` (write, DERIVED)
- `this+0x000010FC` `ptr adapter_object` (read_write, DERIVED)
- `this+0x00001100` `ptr device_state` (read_write, DERIVED)
- `this+0x00001104` `dword configuration_block` (write, DERIVED)
- `this+0x00001108` `dword fixed_config` (write, DERIVED)
- `this+0x0000110C` `ptr format_descriptor` (read_write, DERIVED)
- `this+0x00001110` `dword enabled_flag` (write, DERIVED)
- `this+0x00001114` `dword multisample_count` (read_write, DERIVED)
- `this+0x00001118` `dword present_mode` (write, DERIVED)
- `this+0x0000111C` `dword persist_owner` (write, DERIVED)
- `this+0x00001120` `dword windowed_fullscreen` (write, DERIVED)
- `this+0x00001124` `dword reserved_zero` (write, DERIVED)
- `this+0x00001128` `dword refresh_rate` (write, DERIVED)
- `this+0x00001130` `dword present_param` (write, DERIVED)
- `this+0x00001134` `dword windowed_mode_flag` (write, DERIVED)
- `this+0x00001138` `dword usage_flag` (read_write, DERIVED)
- `this+0x000013A8` `dword capability_flags` (read_write, DERIVED)
- `this+0x000013AC` `dword capability_a` (write, DERIVED)
- `this+0x000013B0` `dword capability_b` (write, DERIVED)
- `this+0x000013B8` `dword multisample_enable` (read_write, DERIVED)
- `this+0x000013C8` `dword debug_color_key` (write, DERIVED)
- `this+0x000013D4` `dword config_state_a` (read, DERIVED)
- `this+0x000013D8` `dword config_state_b` (read_write, DERIVED)
- `this+0x000013E0` `dword vertex_mode` (read, DERIVED)
- `this+0x000013E8` `dword depth_stencil_format` (write, DERIVED)
- `this+0x000013EC` `dword backbuffer_format` (write, DERIVED)
- `this+0x000013F0` `dword display_format_b` (write, DERIVED)
- `this+0x000013F4` `dword display_format_c` (write, DERIVED)
- `this+0x00001400` `dword display_format_d` (write, DERIVED)
- `this+0x00001404` `dword display_format_e` (write, DERIVED)
- `this+0x00001508` `dword viewport_width` (write, DERIVED)
- `this+0x0000150C` `dword viewport_height` (write, DERIVED)
- `this+0x00001510` `dword backing_width` (write, DERIVED)
- `this+0x00001514` `dword backing_height` (write, DERIVED)
- `this+0x00001524` `ptr audio_emitter_0` (write, DERIVED)
- `this+0x00001528` `ptr audio_emitter_1` (write, DERIVED)
- `this+0x0000152C` `ptr audio_emitter_2` (write, DERIVED)
- `this+0x00001550` `dword buffer_count_limit` (write, DERIVED)
- `this+0x00001554` `dword buffer_param` (write, DERIVED)
- `this+0x00001558` `dword format_negotiation` (write, DERIVED)
- `this+0x00001580` `dword trailing_zero` (write, DERIVED)

### UiElement

UI element property setters sharing the element field regions this+0x14/0x24/0x34 (per-group alpha/scale), this+0x17C/0x180/0x184 (normalized color floats), this+0x188/0x18A/0x18C (16-bit position) and the flags field this+0xEC. All owners are UnknownObject; the grouping is synthesis (GUESS) from sibling UI element operations and the shared UI-root global 0x008B8F28.

Methods: `0x00543800`, `0x00543870`, `0x0055D410`

- `this+0x00000004` `dword vertex_buffer_id` (read, DERIVED)
- `this+0x00000014` `dword group_1_factor` (write, DERIVED)
- `this+0x00000024` `dword group_2_factor` (write, DERIVED)
- `this+0x00000034` `dword group_3_factor` (write, DERIVED)
- `this+0x000000EC` `dword flags` (read_write, DERIVED)
- `this+0x0000017C` `float color_r_float` (write, DERIVED)
- `this+0x00000180` `float color_g_float` (write, DERIVED)
- `this+0x00000184` `float color_b_float` (write, DERIVED)
- `this+0x00000188` `word position_y` (write, DERIVED)
- `this+0x0000018A` `word position_z` (write, DERIVED)
- `this+0x0000018C` `word position_x` (write, DERIVED)

### UiSceneManager

UI element-list manager reconstructed from 0x0054BDC0 (bitfield state rewrite across the linked element list headed at this+0x204) and 0x0054F7A0 (per-frame focus/render update over the same list head and the render-state descriptor this+0x1E0). The shared this+0x204 head and the element-link layout (element+0x10 next, element+0x118/0x11C state array) ground the grouping; owners are UnknownObject and the class is synthesis (GUESS).

Methods: `0x0054BDC0`, `0x0054F7A0`

- `this+0x000001E0` `ptr render_state_descriptor` (read, DERIVED)
- `this+0x00000204` `ptr element_list_head` (read_write, DERIVED)
- `this+0x0000032C` `dword state_count_guard` (read, DERIVED)
- `this+0x00000338` `dword subelement_guard` (read, DERIVED)

### RotationMatrixBuilder

Object whose Euler-angle input (this+0x30/0x34/0x38), orientation vector (this+0x24/0x28/0x2C), built 3x3 matrix (this+0x15C..0x198) and transformed result (this+0x18C/0x190/0x194) are all used by 0x00541DB0. The math content is grounded in the raw decompilation; the class boundary is synthesis (GUESS) because the packet owner is UnknownObject.

Methods: `0x00541DB0`

- `this+0x00000024` `float orientation_x` (read, DERIVED)
- `this+0x00000028` `float orientation_y` (read, DERIVED)
- `this+0x0000002C` `float orientation_z` (read, DERIVED)
- `this+0x00000030` `float euler_a` (write, DERIVED)
- `this+0x00000034` `float euler_b` (write, DERIVED)
- `this+0x00000038` `float euler_c` (write, DERIVED)
- `this+0x0000015C` `float matrix_row0` (write, DERIVED)
- `this+0x00000168` `float matrix_zero_col` (write, DERIVED)
- `this+0x00000198` `float scale_w` (write, DERIVED)
- `this+0x0000018C` `float result_x` (write, DERIVED)
- `this+0x00000190` `float result_y` (write, DERIVED)
- `this+0x00000194` `float result_z` (write, DERIVED)

### MeshIndexBufferBuilder

Mesh resource builder (0x00558310) that owns the mesh pointer this+0x50 and the mode/dimension words this+0x20..0x2C, and drives a mesh object with descriptors at *(this+0x50)+0x1C (vertex) and *(this+0x50)+0x24 (index) plus data fields at +0x14/+0x20/+0x28. Field bases follow the packet exactly (this and *(this+0x50)); the class boundary is synthesis (GUESS).

Methods: `0x00558310`

- `this+0x00000020` `dword mode_word` (read, DERIVED)
- `this+0x00000024` `dword columns` (read, DERIVED)
- `this+0x00000028` `dword rows` (read, DERIVED)
- `this+0x0000002C` `dword row_count` (read, DERIVED)
- `this+0x00000050` `ptr mesh_object_ptr` (read, DERIVED)
- `*(this+0x50)+0x00000000` `dword mesh_flags` (read, DERIVED)
- `*(this+0x50)+0x00000008` `dword mesh_width` (read_write, DERIVED)
- `*(this+0x50)+0x00000010` `dword mesh_height` (read_write, DERIVED)
- `*(this+0x50)+0x00000014` `ptr index_source` (read, DERIVED)
- `*(this+0x50)+0x0000001C` `ptr vertex_buffer_desc` (write, DERIVED)
- `*(this+0x50)+0x00000020` `ptr vertex_data` (write, DERIVED)
- `*(this+0x50)+0x00000024` `ptr index_buffer_desc` (write, DERIVED)
- `*(this+0x50)+0x00000028` `ptr index_dest` (write, DERIVED)
- `*(this+0x50)+0x00000038` `dword vertex_buffer_size` (read, DERIVED)
- `*(*(this+0x50)+0x1C)+0x00000000` `dword vb_size` (read, DERIVED)
- `*(*(this+0x50)+0x1C)+0x00000004` `dword vb_format` (read, DERIVED)
- `*(*(this+0x50)+0x1C)+0x00000008` `dword vb_stride` (read, DERIVED)
- `*(*(this+0x50)+0x1C)+0x0000000C` `dword vb_width` (read, DERIVED)
- `*(*(this+0x50)+0x24)+0x00000000` `dword ib_count` (read, DERIVED)
- `*(*(this+0x50)+0x24)+0x00000004` `dword ib_height` (read, DERIVED)

### SparseMatrixPatternBuilder

Holder of the four sparse-matrix arrays (this+0x0/0x4/0x8/0xC) allocated and filled by 0x0056C830 from a dense connectivity matrix. The CSR-like layout is DERIVED from the write pattern; the class boundary is synthesis (GUESS).

Methods: `0x0056C830`

- `this+0x00000000` `ptr row_starts` (write, DERIVED)
- `this+0x00000004` `ptr column_indices` (write, DERIVED)
- `this+0x00000008` `ptr value_offsets` (write, DERIVED)
- `this+0x0000000C` `ptr packed_columns` (write, DERIVED)

### ThreadResumeController

Object holding a thread handle (this+0x4), a suspend flag (this+0x1C) and two mutexes (this+0x20/0x24, this+0xD4/0xD8) used by 0x00585680 to resume a suspended thread under mutual exclusion. Field layout is DERIVED; the class boundary is synthesis (GUESS).

Methods: `0x00585680`

- `this+0x00000004` `ptr thread_handle` (read, DERIVED)
- `this+0x0000001C` `dword suspend_flag` (read_write, DERIVED)
- `this+0x00000020` `ptr mutex_b` (read, DERIVED)
- `this+0x00000024` `dword mutex_b_timeout` (read, DERIVED)
- `this+0x000000D4` `ptr mutex_a` (read, DERIVED)
- `this+0x000000D8` `dword mutex_a_timeout` (read, DERIVED)

### MutexGuardedFieldWriter

Object whose protected integer field this+0x5B4, mutex handle this+0x5B8 and timeout this+0x5BC are used by 0x00585CD0 for a mutex-guarded write. Field layout is DERIVED; the class boundary is synthesis (GUESS).

Methods: `0x00585CD0`

- `this+0x000005B4` `dword guarded_field` (write, DERIVED)
- `this+0x000005B8` `ptr mutex_handle` (read, DERIVED)
- `this+0x000005BC` `dword mutex_timeout` (read, DERIVED)

### LocaleFacet

Object whose offset 0x0 receives the locale-facet reference in 0x00598C1C before the global reference counter 0x008D4650 is incremented under lock. Single-field layout is DERIVED; the class boundary and the legacy ABI name are synthesis (GUESS).

Methods: `0x00598C1C`

- `this+0x00000000` `dword locale_facet_ref` (write, DERIVED)

### ThreadSafeCounter

Counter object at this+0x4 incremented by 0x00598C4A under a critical section, guarded against the -1 sentinel. Field layout is DERIVED; the class boundary is synthesis (GUESS).

Methods: `0x00598C4A`

- `this+0x00000004` `dword counter` (read_write, DERIVED)

### AudioResampleFilterTableBuilder

Free helper that allocates and fills a sample-rate conversion filter table (two-phase source-index/weight records plus per-phase byte lengths and a trailing total size). No this-struct fields are evidenced; the allocated table layout is inferred from the write pattern. Class is synthesis (GUESS).

Methods: `0x00502C28`


### StreamSerializationHelper

Free fastcall helper that emits a 32-bit value as four little-endian bytes through the BufferedCharacterWriteWithOverflowHandling sink (0x00589898). No fields are evidenced; used by StreamFileTypeCheckWithDispatch (0x005355A0). Class is synthesis (GUESS).

Methods: `0x005355F0`


### GuidFormatter

Free helper that formats a 16-byte GUID payload (Data1/Data2/Data3/Data4 at offsets +0x0..+0xF) into the canonical hyphenated hex string via StringFormatWithBufferOverflowCheck (0x0058815F). The GUID field layout is DERIVED; the class boundary is synthesis (GUESS).

Methods: `0x0053D8E0`

- `this+0x00000000` `dword data1` (read, DERIVED)
- `this+0x00000004` `word data2` (read, DERIVED)
- `this+0x00000006` `word data3` (read, DERIVED)
- `this+0x00000008` `byte data4_0` (read, DERIVED)
- `this+0x00000009` `byte data4_1` (read, DERIVED)
- `this+0x0000000A` `byte data4_2` (read, DERIVED)
- `this+0x0000000B` `byte data4_3` (read, DERIVED)
- `this+0x0000000C` `byte data4_4` (read, DERIVED)
- `this+0x0000000D` `byte data4_5` (read, DERIVED)
- `this+0x0000000E` `byte data4_6` (read, DERIVED)
- `this+0x0000000F` `byte data4_7` (read, DERIVED)

## Compatibility contracts

- **AudioResampleFilterTableLayout** — A replacement for 0x00502C28 must allocate a filter table whose per-output segment stores (source-index dword, weight float) record pairs plus per-phase byte lengths, with a trailing total byte size written before returning the table pointer, and must return null when either size is zero or the allocation fails. The clamp (a3==0) vs wrap behavior of source positions is part of the observable contract.
- **UInt32LittleEndianByteSerialization** — A replacement for 0x005355F0 must emit a 32-bit value as exactly four bytes in least-significant-byte-first order through the buffered character writer (0x00589898) and propagate the last write's result. StreamFileTypeCheckWithDispatch (0x005355A0) relies on the byte order.
- **DirectXDeviceSurfaceConfigurationDefaults** — A replacement for 0x0053D4F0 must reset the device globals 0x008B6AC8/0x008B6AB8, zero-initialize eight render-pass sub-structures (17-dword strides from dword index 1118), and apply the fixed defaults: 8192/32768 buffer limits, identity 1.0f scales, debug color key 11513775, 640x480 viewport with 7680x1200 backing, and buffer parameters 512/6. It must return this.
- **GuidHexStringFormat** — A replacement for 0x0053D8E0 must read the GUID payload at +0x0 (Data1 dword), +0x4 (Data2 word), +0x6 (Data3 word) and +0x8..+0xF (Data4 bytes) and format it with the literal "%.8X-%.4X-%.4X-%.2X%.2X-%.2X%.2X%.2X%.2X%.2X%.2X" (0x005DBC5C) via StringFormatWithBufferOverflowCheck into the caller's buffer, propagating its result.
- **UiElementPositionDirtyFlag** — A replacement for 0x00543870 must write the three 16-bit position values into this+0x188/0x18A/0x18C and OR bit 0x10000 into the flags word at this+0xEC, returning the updated flags value.
- **MeshVertexIndexBufferLayout** — A replacement for 0x00558310 must create a vertex buffer from a descriptor with size 32, width = this+0x2C*this+0x24, height = this+0x2C*this+0x28, stride 64 and format 1234 via 0x00540DF0, and an index buffer from a descriptor with count 2 and the mesh height via 0x00540FC0, then copy the generated index data and return -1 with the aErrorCreatingV path on creation failure.
- **ThreadResumeMutexProtocol** — A replacement for 0x00585680 must protect the value update with the mutex at this+0xD4 (accepting WAIT_OBJECT_0 or WAIT_ABANDONED from WaitForSingleObject), and when a thread handle exists at this+0x4, under the mutex at this+0x20, resume the thread until its suspend count is below 2 (up to 50 attempts with increasing sleeps) when the suspend flag at this+0x1C is set, returning 0 on resume failure and 1 otherwise.
- **MutexGuardedFieldWrite** — A replacement for 0x00585CD0 must, when the mutex handle at this+0x5B8 is non-null and WaitForSingleObject(timeout this+0x5BC) returns 0 or 128, store a2 into the field at this+0x5B4 and release the mutex, returning the field pointer. The unconditional store even on guard failure (null dereference) is part of the current behavior and should be preserved or explicitly decided.
- **LocaleRefcountIncrement** — A replacement for 0x00598C1C must store the locale-facet reference (from 0x0059AAB9) into the object's offset 0x0 and, under the lock pair 0x0059A54D/0x0059A5E9, increment the global reference counter 0x008D4650 via CounterIncrementThreadSafe (0x00598C4A), returning the object pointer.
- **ThreadSafeCounterIncrement** — A replacement for 0x00598C4A must enter the critical section, increment the counter at this+0x4 unless it holds the -1 sentinel, leave the critical section, and return the release status.

## Unresolved

- The five globals 0x0059E43C, 0x0059E440, 0x0059E450, 0x005AD260 and 0x005ADB14 are flagged as read by AudioResampleFilterTableBuild (0x00502C28) but do not appear in the raw decompiled source; their roles are unknown.
- Global dbl_5B8960 (0x005B8960) is absent from the raw body of 0x00541DB0; it may back the sin/cos constants but cannot be tied to a specific operation.
- Global dbl_59E430 (0x0059E430) is listed as read by 0x0056C830 but does not appear as an explicit name in the raw Hex-Rays body.
- The exact layout of the render-pass sub-structures zeroed by StructZeroInitConstructor (0x00553DE0) from dword index 1118 at 17-dword strides is unresolved; only the bookkeeping fields around this+0x10FC..0x1174 and this+0x1398..0x13E4 are evidenced.
- The meaning of format codes 20..25 and the five decimal format ids 827611204/844388420/861165636/877942852/894720068 used by 0x0053E070 is not established; they map to display/backbuffer/depth-stencil enumerants only by position.
- The a7 bit set 0x100560 and *a2 bit set 0x802E0 gate the multisample block of 0x0053E070; individual bit semantics (0x20/0x100/0x40/0x400/0x100000) are unknown.
- The a3/a5 flag bits (1/2/4/8) and the a2/a4 descriptor arrays used by 0x0053FD40 are caller-defined; the vtable methods at +8/+60 belong to an unidentified DirectDraw/D3D surface interface.
- The vtable method at byte offset 92 (slot 23) used by 0x00540DF0, and the usage/format flag semantics (8, 0x200, 0x210, base 16) and the this+0x13E0 mode values (0/1/2), are unnamed.
- Owners of all 19 packet functions are UnknownObject; every proposed class boundary, method-to-class mapping and field name is synthesis (GUESS), grounded only in shared field regions and callee sets.
- The exact rotation convention (axis order, handedness) of 0x00541DB0's matrix entries is not proven without an independent math check; InterruptDispatch's effect on the angles is undocumented.
- The object behind global 0x008B78A0 and the vtable method invoked by VTableDispatchWithFieldCheck (0x00541670) are unknown; whether a2/a3/a4 of 0x00543800 are color (R/G/B) rather than 3D position components is interpretation.
- The object behind global 0x008B8F28 (UI root) and the meanings of the 0x800/0x10000/0x20000000 flag bits used by the UI functions are not resolved.
- Element-linked offsets this+0x224, this+0x228, this+0x330 and this+0x350 (0x0054BDC0) and this+0x218 (0x0054F7A0) are read per packet facts but their writers and semantics are unresolved.
- The sparse-matrix normalization constants (1.0/2.0 via dwords 1072693248 and 0x40000000) in 0x0056C830 are inferred from IEEE-754 bit patterns only.
- The float computation performed on the sub-object by 0x00585680 (FloatAdditionReturnsFUN00568d90Param1 / FloatSetWithTimingCall) and why a wait timeout (128) is accepted on both mutex waits are not evidenced.
- Whether the null-target crash path of 0x00585CD0 is reachable in practice or always guarded by callers (0x0057BF00, 0x005804A0, 0x00584230) is unverified.
- The GUID's semantic role in VidMan_Enter (device identifier, adapter GUID, registry key) and the identity of the owning renderer class are unresolved.
