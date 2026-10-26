# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

This packet covers a heterogeneous set of runtime helper functions and objects: (1) an MTS mesh/texture file loader cluster sharing a global read cursor (0x008B8F3C) and two default-header initializers; (2) four thunks funneling a function/global value through the shared BooleanToIntConversion helper (0x00587B3E); (3) three settings setters that dispatch value changes to the global game-device object (0x008B89A0) through vtable+252; (4) three distinct linked-list containers (scene-graph child list, resource list, scene-node named list) with incompatible node layouts; (5) four raster span-fill primitives and four transparent image/row-copy helpers sharing global mask state (0x005DD804 / 0x005DD814 / 0x005DD844); (6) a frustum-visibility classifier, a six-field record setter, several single-field getters/setters, and conditional-freed teardown helpers. No function owner is proven by the packet; all classes are GUESS groupings and the remaining functions keep UnknownObject ownership.

## Function roles

- `0x0054A580` **MtsReadBufferState** — Mode-based updater of the global read-cursor dword 0x008B8F3C (modes: 0=set, 1=add, 2=subtract-from 0x008B8F38).
- `0x0054A5B0` **MtsReadBufferState** — Getter returning the global read-cursor dword 0x008B8F3C, used as base cursor position by the MTS file parser.
- `0x0054A5F4` **UnknownObject** — Getter returning the dword at this+0x0; argument a2 unused.
- `0x0054AC30` **SceneGraphChildList** — Unlinks a node from the scene-graph child doubly linked list whose head is at this+0x204; node prev at +0x140, next at +0x10; advances the head on head removal.
- `0x0054C290` **UnknownObject** — Thunk calling BooleanToIntConversion with the address of InitializationLoop256 (0x0054C2A0) cast to int; returns its result.
- `0x0054C2F0` **UnknownObject** — Thunk calling BooleanToIntConversion with the global value at 0x0054C300 cast to int; returns its result.
- `0x0054C320` **MtsHeaderInitializer** — Default MTS texture-header initializer: copies the magic string from 0x005DBFC0 into the object, clears fixed field blocks and sets constant header values; called right after the loader allocates the output buffer.
- `0x0054D4E0` **SceneNodeOverrideFloats** — Conditional float setter: writes a2/a3 into this+0xF4/+0xF8 only when they differ from the -1.0 sentinel constant 0x0059E428.
- `0x0054D910` **FrustumVisibilityState** — Classifies an AABB against frustum planes and writes visibility state (1 visible / 2 culled / 4 intersecting) into the state word at this+0x14, gated on the plane count at this+0xFC.
- `0x0054E9A5` **UnknownObject** — Getter returning the dword at byte offset 4 of the object argument a2; a1 and a3 unused.
- `0x0054E9B0` **MtsHeaderInitializer** — Default MTS mesh-header initializer: copies the magic string from 0x005DBF50 into the object, clears fixed field blocks and sets constant header values; called right after the loader allocates the intermediate mesh buffer.
- `0x0054EAA0` **UnknownObject** — Loops 1024 times over 24-byte-strided slots of the buffer at 0x008C5F48, calling ShortComputation_8e00 on each slot; returns the last call's result.
- `0x0054EAC0` **UnknownObject** — Thunk calling BooleanToIntConversion with the global value at 0x0054EAD0 cast to int; returns its result.
- `0x0054FC50` **UnknownObject** — Scales float a2 by the 2.55 constant at 0x005B8988, rounds via CRTFtol, replicates the byte across all channels (16843009) and stores it at this+0x68.
- `0x0054FD46` **UnknownObject** — Stores argument a2 into the dword at this+0x60 and returns the stored value.
- `0x0054FE00` **UnknownObject** — Computes 1.0/a2 using the 1.0 constant at 0x0059E43C and stores the reciprocal at this+0x58.
- `0x00551790` **SceneNodeNamedChildList** — Walks the scene-node named-child list at this+0x13C; for each node whose name matches the key, clears bit 0x20000 on its flags and calls AudioFlagSet on the node.
- `0x00551CE0` **UnknownObject** — Calls BinkClose (imported at 0x0059E338) on the Bink handle stored at this+0x0 and returns 0.
- `0x00553CD0` **SpanFillPrimitives** — Orders span endpoints ascending and fills a 16-bit span via F_16BitShortArrayFill.
- `0x00553D00` **SpanFillPrimitives** — Orders span endpoints ascending and fills a strided span via ShortArrayFillWithStride.
- `0x00553D40` **SpanFillPrimitives** — Normalizes boundary arguments and fills a contiguous horizontal run via ArrayFillWithValue.
- `0x00553D70` **SpanFillPrimitives** — Normalizes boundary arguments and fills a strided horizontal pixel run via PixelFillWithStride.
- `0x005544C0` **GameDeviceSettingNotifier** — Maps enum a2 (0/1/2) to dispatch value (1/3/2) and calls the global object 0x008B89A0 through vtable+252 with (*this, 13, value); caches a2 in this+0x38.
- `0x00554510` **GameDeviceSettingNotifier** — Maps enum a2 (0/1/2) to dispatch value (1/3/2) and calls the global object 0x008B89A0 through vtable+252 with (*this, 14, value); caches a2 in this+0x3C.
- `0x005545E0` **GameDeviceSettingNotifier** — Change-guarded setter: when a2 differs from -1 and from this+0x2C, dispatches (*this, 11, a2) to global 0x008B89A0 vtable+252 and stores a2 in this+0x2C.
- `0x005567E1` **UnknownObject** — Scales a float argument by the global factor 0x005DC164 and casts the product to int (truncation toward zero).
- `0x005567F5` **UnknownObject** — CPUID/RDTSC probe: toggles EFLAGS ID bit to detect CPUID support, computes elapsed TSC into the caller dword pair *a1/*a2, and writes the CPUID leaf-0 vendor string to a3 when supplied.
- `0x005568D0` **UnknownObject** — Calls BooleanToIntConversion with the MainLoopHeartbeat512 address (0x005568E0) cast to int; candidate callback registration.
- `0x0055BB20` **SixFieldRecord** — Copies six DWORD/pointer arguments a2..a7 into consecutive fields this+0x4..this+0x18 and returns 0.
- `0x0055C2E0` **ResourceCascadeList** — Walks the resource list at this+0x1518, unlinks the node matching a2 (node prev at +0x1C, next at +0x20), and advances the head on a head removal.
- `0x0055D2E0` **UnknownObject** — Clears the byte flag at this+0x58 to 0 and returns 0; called by sub_5454A0.
- `0x0055F060` **UnknownObject** — Calls GlobalMemoryStatus with a 32-byte _MEMORYSTATUS buffer and discards the results; called during UI-system global initialization.
- `0x0055FBC0` **UnknownObject** — Copies a fixed 0xA0-byte block from global 0x008B8F04 into destination a1; returns void.
- `0x00560410` **ImageCopyEngine** — Row-wise keyed copy: stores the key word a7 to 0x005DD804; takes a fast block-copy path when a7 is 0xFFFF and row width is a multiple of 8, otherwise copies word-by-word skipping destination words equal to the key.
- `0x005608F6` **ImageCopyEngine** — 16-bit transparent blit: stores the transparent color to 0x005DD804; per-pixel path skips pixels equal to it, while the aligned 0xFFFF fast path copies 64-bit chunks.
- `0x005609DE` **ImageCopyEngine** — 24-bit transparent blit: stores the masked transparent color to 0x005DD804 and scanline byte width to 0x005DD814; bulk-copies whole scanlines when transparent color is 0xFFFFFF, else skips pixels equal to it.
- `0x00560A82` **ImageCopyEngine** — Mode-dependent row copy on the audio playback path: full block copy when a7 == -1, else copies dwords differing from the mask; records mode flag, mask and per-row count into 0x005DD844 / 0x005DD804 / 0x005DD814.
- `0x00560B30` **UnknownObject** — Conditional teardown: frees this+0x1AC via FreeWrapper_7bcf when non-null, zeroes the field, and returns the prior pointer; used in DirectX resource teardown.
- `0x00560B90` **UnknownObject** — Conditional single-field free: frees this+0x4 via FreeWrapper_7bcf when non-null and returns the wrapper result; used as a sub-object teardown step.

## Proposed classes

### MtsReadBufferState

Owns the global read-cursor dword 0x008B8F3C used while parsing MTS mesh/texture file payloads; provides a mode-based cursor updater and a cursor getter.

Methods: `0x0054A580`, `0x0054A5B0`


### MtsHeaderInitializer

Stamps default MTS texture/mesh headers after the loader allocates their buffers: copies the MTS magic string into the object start, clears fixed field blocks and sets constant header values (1065353216, 1176256512, 6).

Methods: `0x0054C320`, `0x0054E9B0`

- `this+0x00000000` `char[?] mts_magic` (write, GUESS)

### GameDeviceSettingNotifier

Settings setters that dispatch value changes for this object to the shared game-device object at 0x008B89A0 through its vtable entry +252, skipping no-change/-1 updates and caching the last accepted value per slot.

Methods: `0x005544C0`, `0x00554510`, `0x005545E0`

- `this+0x00000000` `int object_id` (read, GUESS)
- `this+0x0000002C` `int last_value_slot11` (read_write, GUESS)
- `this+0x00000038` `int last_value_param13` (read_write, GUESS)
- `this+0x0000003C` `int last_value_param14` (read_write, GUESS)

### SceneGraphChildList

Doubly linked child list of a scene-graph object; supports node unlink during scene-graph cleanup.

Methods: `0x0054AC30`

- `this+0x00000204` `void* child_list_head` (read_write, GUESS)

### ResourceCascadeList

Doubly linked resource list (head at this+0x1518) supporting unlink-by-pointer-match during resource cascade cleanup.

Methods: `0x0055C2E0`

- `this+0x00001518` `void* resource_list_head` (read_write, GUESS)
- `*(this+0x1538)+0x0000001C` `void* prev` (read_write, GUESS)
- `*(this+0x1538)+0x00000020` `void* next` (read_write, GUESS)

### SceneNodeNamedChildList

Named child list of a scene-node: string-keyed lookup that clears flag bit 0x20000 on matching nodes and triggers an audio flag update.

Methods: `0x00551790`

- `this+0x0000013C` `void* named_child_head` (read, GUESS)
- `this+0x00000164` `int node_flags_field` (read_write, GUESS)
- `this+0x0000017C` `char[?] node_name_buffer_a` (read, GUESS)
- `this+0x00000184` `char[?] node_name_buffer_b` (read, GUESS)

### SceneNodeOverrideFloats

Optional float override fields on a scene-node object; each override argument is honored only when it differs from the -1.0 sentinel.

Methods: `0x0054D4E0`

- `this+0x000000F4` `float override_float_a` (write, GUESS)
- `this+0x000000F8` `float override_float_b` (write, GUESS)

### FrustumVisibilityState

Per-object visibility state: the state word at this+0x14 records AABB-vs-frustum classification (1 visible / 2 culled / 4 intersecting), with the plane count at this+0xFC gating the culling pass.

Methods: `0x0054D910`

- `this+0x00000014` `int (bitfield state) visibility_state` (read_write, GUESS)
- `this+0x000000FC` `int frustum_plane_count` (read, GUESS)

### SpanFillPrimitives

Raster span/run fill primitives: normalize boundary endpoints to ascending order and delegate to 16-bit, strided or horizontal-run fill helpers.

Methods: `0x00553CD0`, `0x00553D00`, `0x00553D40`, `0x00553D70`


### SixFieldRecord

Generic record whose first six payload fields (offsets 0x4..0x18) are written in one call; exact meaning depends on caller 0x0055BC00.

Methods: `0x0055BB20`

- `this+0x00000004` `dword/ptr field_0x04` (write, UNKNOWN)
- `this+0x00000008` `dword/ptr field_0x08` (write, UNKNOWN)
- `this+0x0000000C` `dword/ptr field_0x0C` (write, UNKNOWN)
- `this+0x00000010` `dword/ptr field_0x10` (write, UNKNOWN)
- `this+0x00000014` `dword/ptr field_0x14` (write, UNKNOWN)
- `this+0x00000018` `dword/ptr field_0x18` (write, UNKNOWN)

### ImageCopyEngine

Image/row copy helpers sharing global transparent-color/mask state: 16/24-bit transparent blits, keyed row copy, and masked audio row copy, all driven through the shared globals 0x005DD804 / 0x005DD814 / 0x005DD844.

Methods: `0x00560410`, `0x005608F6`, `0x005609DE`, `0x00560A82`


## Compatibility contracts

- **MtsReadCursorGlobalSemantics** — Preserve the global read cursor at 0x008B8F3C with mode-based updates (0=set, 1=add, 2=subtract using the companion global 0x008B8F38); the MTS file load path reads it as the base cursor position while parsing mesh/texture payloads.
- **MtsDefaultHeaderValues** — MTS texture and mesh headers must default to: MTS magic string at offset 0, dword index 6 = 1065353216, dword index 62/38 = 1176256512, dword index 63/39 = 6, with fixed zeroed field blocks (texture: indices 55..81 plus regions at byte 28 and 124; mesh: indices 31..57 plus region at byte 28).
- **GameDeviceVtable252Dispatch** — The global game-device object at 0x008B89A0 must expose a callable vtable entry at offset +252 taking (object_id, param_id, value); param ids 13 and 14 encode enum 0/1/2 to dispatch values 1/3/2, and slot 11 carries generic value-change notifications.
- **TransparentImageCopySemantics** — 16/24-bit blit and row-copy helpers treat a pixel equal to the shared transparent color / mask (global 0x005DD804) as 'leave destination unchanged'; a transparent color of 0xFFFF (16-bit) or 0xFFFFFF (24-bit) with aligned width selects an unguarded bulk fast path; scanline width is stored at 0x005DD814 and the full-copy mode flag at 0x005DD844.
- **DoublyLinkedNodeLayouts** — Two distinct doubly linked list node layouts are evidenced and must not be unified: scene-graph child list (node prev at +0x140 / next at +0x10, container head at +0x204) and resource list (node prev at +0x1C / next at +0x20, container head at +0x1518).
- **DeallocationWrapperContract** — Teardown helpers release heap fields through the shared wrapper 0x00587BCF and null the field after freeing; callers depend on the freed-pointer return value.

## Unresolved

- Owners are UNKNOWN for most functions; the classes above are GUESS groupings based on shared globals, shared callers, or identical shapes, not proven C++ classes.
- Global 0x008B8F38 (cursor base used by GlobalStateVariableSetter mode 2) is read but its producer is unknown.
- Texture vs mesh MTS header layouts use different field indices (texture 55..81/62/63, mesh 31..57/38/39); whether they are two views of one struct or two distinct structs is unresolved.
- BooleanToIntConversion (0x00587B3E) thunks: whether 0x0054C2A0 / 0x0054C300 / 0x0054EAD0 / 0x005568E0 are function pointers or data values, and what the helper's side effects are, is unresolved.
- AABB corner and frustum plane layouts (corners at a3+8, planes at a2+260) are inferred from pointer arithmetic, not named fields.
- Scene-node named-list node layout (name at node[7]+28, next at node[9], flags at node[1]) is prose-mapped; the this-relative offsets 0x164 / 0x17C / 0x184 are not statically proven.
- The 0xFF00000000005412 global write is an extraction artifact of the GlobalMemoryStatus import thunk, not a real data write.
- this+0x58 is rewritten to 0 on every call of 0x0055D2E0, so an external poke does not persist.
- The three GameDeviceSettingNotifier methods may belong to different objects; common ownership is not proven by the packet.
- The 6-DWORD (24-byte) stride at 0x008C5F48 in F_1024xBatchCallLoop implies a fixed record whose layout is unconfirmed; only the last call's result is returned.
- Pixel format, stride units and the meaning of fill arguments (a1..a6) of the span/blit helpers depend on caller image layouts not present in this packet.
- QueryCpuTscDeltaAndVendor's prelabel 'structural twin of FloatClamp' (DERIVED) is not corroborated by the raw source, which is a CPUID/RDTSC probe.
- In KeyedRowCopy the general-path comparison key becomes 2*a5 when a7 == 0xFFFF; the reason is unresolved.
- The high bits of the frustum visibility state word (preserved by mask 0xFFFFFFF8) are undocumented.
- The -1.0 sentinel in SceneNodeOverrideFloats means 'leave the field unchanged' by inference from the guard structure; the caller's interpretation of the override values is not evidenced.
- Whether GetDwordFieldAtOffset0x4 and SixFieldRecord's field 0x4 refer to the same object type is not proven; offsets on unrelated bases are not merged.
