# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Proposed architecture for 27 validated generic-runtime-object functions. Cohesive groups: a 3D sound-emitter class (SoundEmitter3D: init/aim/getter/color-pack, 0x005418E0/0x00541F60/0x00542490/0x005423E0) with a shared 3D position/orientation sub-object driven through UtilityFunction_1cd0; an audio ring-buffer class (SoundRingBuffer: SoundBufferAllocator 0x0053AB20 + AudioRingBufferCopy 0x0053A660) sharing the 0xC/0x10/0x14 write-pointer/remaining/total accounting layout; a surface-compositor class (SurfaceCompositor: 0x00540250/0x005404D0/0x00541670/0x005416A0) dispatching through a render-surface sub-object at this+0x1100; a display-enumeration context (DisplayEnumerationContext 0x0053DB90) querying a display sub-object at this+0x10FC through a vtable contract; and a string-keyed record class (StringKeyedRecord 0x00548E20/0x00548E80) sharing caller sub_55A790. The remaining functions are small generic helpers (factory, table lookup, stub, two-part string record, field getters, array append, flag toggle, list walk, channel float accessor, c-string copy, selector getter, dot finder, node reset) whose owners stay GUESS/UNKNOWN. All owners in the packet are UnknownObject; no class identity is promoted beyond DERIVED/GUESS. Field 0x7C semantics are contested (audio-session pointer vs packed color).

## Function roles

- `0x00539830` **SmallObjectFactory** — Allocate a small runtime object through the indirect allocator function pointer at descriptor a5+32 (payload a5+40, integer arguments 1 and 26), then, on success, initialize the new object header: zero dword +0, store byte a1 at +16, byte a2 at +17, dword a3 at +18, dword a4 at +22; return the object (null on allocation failure).
- `0x0053A660` **SoundRingBuffer** — Copy audio samples from a source ring buffer into the destination buffer, computing the contiguous segment to the ring boundary clamped to remaining capacity (this+0x10), updating the total-written accumulator (this+0x14), invoking an optional per-segment callback (result to this+0x30), handling wrap-around with a second segment, committing the advanced destination write pointer at this+0xC, and normalizing the -5 passthrough status to 0 when a segment was copied.
- `0x0053AB20` **SoundRingBuffer** — Sound buffer constructor: store size a2 at field 0x0, compute a log2-based index (__FYL2X__ product via CRTFtol) at field 0x4, allocate (8*a2+16) bytes into field 0xC, zero accounting fields 0x10/0x14, and call CurveSplinePointGenerator(a3); return this.
- `0x0053AC40` **ScaledLookupTable** — Table lookup: compute (int)((double)this[0] * a2), read the float at this[3] + 8*index (buffer at this+0xC), scale by 255.0 via flt_59FEC8, and return as double; no branches.
- `0x0053B160` **EmptyVirtualStub** — Empty stub (nullsub_6): performs no operations and returns void; called from seven sites, so it satisfies a virtual or hook-style entry that the build stubs out.
- `0x0053C6B0` **TwoPartStringRecord** — Copy a two-part structure (leading DWORD plus null-terminated byte string) from source a2 into this, byte-shifting the string (including terminator) from a2+4 to this+4 then copying *a2 into *this; null source clears this[0]/this[4].
- `0x0053D880` **FieldGetterUnknownObject** — Side-effect-free thiscall getter returning the dword at byte offset 0x8 of this as int; callers span rendering and memory-copy paths so the owner class is not established.
- `0x0053D8B0` **FixedSlotRecordArray** — Bounded append of a 0x43C-byte record into a fixed 4-slot array embedded in this: while count (this+8) is below capacity, copy 0x43C bytes from a2 into the slot at this + 3 dwords + 271 dwords * count, then increment the count; no-op at capacity; returns this.
- `0x0053DB90` **DisplayEnumerationContext** — Display adapter capability query for selected display a2[65]: dispatch surface-format and multisample capability tests through vtable slots +20/+24/+36/+44/+52 on the sub-object at this+0x10FC, accumulate a capability bitmask in *a2, then enumerate display modes (slots +32/+24/+28) and report modes passing the resolution window this+0x1508..this+0x1510 to sub_55BC00; log and return -1 on failure.
- `0x005400C0` **FlagDispatchHelper** — Flags-driven virtual dispatch through descriptor a2: resolve the flag word from a4 (or a2+24 default), derive a per-call argument flag (16 when bit 0x100 set else 0), select a method-holder pointer by flag bit (bit 1 -> a2+8, bit 2 -> a2+12, bit 4 -> *(a2+16)), invoke a stdcall vtable slot (36 for holders, 64 for the handler), store the result at this+0, and commit out-parameters v10[0]/v10[1] to a2+40 when the result is null.
- `0x00540250` **SurfaceCompositor** — 2D surface compositing: select source/destination surfaces from descriptor arrays a2/a5 using flag bitmasks at index 6 (bits 1/2 direct pointers, bits 4/8 acquire via vtable+60), run a clipped path through the this+0x1100 sub-object vtable slot +0x70 or a direct blit path (vtable+36, AudioPlaybackDispatcher, vtable+40 releases), clear bit 0x400 of a5[6], and return 0 or -1.
- `0x005404D0` **SurfaceCompositor** — 2D surface blit/fill dispatch: texture-blit path locks via sub_55CA90 and calls vtable slot +144 on the render surface at this+0x1100; otherwise select a lockable surface from descriptor flags, lock via vtable +36/+64, perform a row fill (32-bit RGBA via memset32 for format 8, 16-bit packed via RGBAByteExtraction otherwise, jump table at 0x540750), unlock via vtable +40/+68, clear flag 0x400, and return 0 or -1.
- `0x00541670` **SurfaceCompositor** — Guard-gated virtual dispatch: when this+0x13D8 is non-zero call the virtual method at vtable entry 0xC8 of the sub-object at this+0x1100 with arguments (139, a2), store the result at this+0, and return 0.
- `0x005416A0` **SurfaceCompositor** — Build a block of scaled texture-coordinate data from descriptor a2 (switch on the low 3 bits of the descriptor dword, scaled products of descriptor fields) and submit it via vtable slot 176 (0xB0) on the DirectX object at this+0x1100, optionally calling slot 184 (0xB8); guarded by this+0x13D8 and a4 != 1; store results at this+0, return -1 on failure else 0.
- `0x005418E0` **SoundEmitter3D** — Default-initialize a 3D sound-emitter instance: set volume 1.0 and max attenuation 1000.0, zero playback state / position / velocity, configure cone angles (90/75), store the sound name via strcpy, initialize the 3D position/orientation sub-object via UtilityFunction_1cd0, and return 0.
- `0x00541F60` **SoundEmitter3D** — Compute pitch/yaw to face target (a2,a3,a4) from the current position (this+0x24/0x28/0x2C): normalize by Euclidean distance, store the negated pitch at this+0x30 and negated yaw at this+0x34, build the orientation delta from the reference position (this+0x3C/0x40/0x44) and facing component (this+0x38), and finalize via UtilityFunction_1cd0; skipped when the distance is zero.
- `0x005423E0` **SoundEmitter3D** — Pack three byte-like components a2/a3/a4 into one dword as (a2 << 16) | (a3 << 8) | a4, store it at this+0x7C, and return it; unconditional.
- `0x00542490` **SoundEmitter3D** — Null-guarded three-field getter: write this+0x30 through *a2 when a2 is non-null, this+0x34 through *a3 when a3 is non-null, this+0x38 through *a4 when a4 is non-null; return a4.
- `0x00542650` **RenderStateFlagControl** — Set or clear bit 5 (0x20) of the dword at this+0x80 based on boolean a2, store the updated dword back, and return it; used by ConditionalRenderPipelineDispatch to toggle a render state flag.
- `0x00546200` **LinkedNodeListWalker** — Walk the singly-linked list seeded from global list head dword_8B8F28, following the next pointer at node offset +488, calling sub_557120 on every node; return 0.
- `0x005472D0` **ChannelFloatAccessor** — Channel-indexed float-to-int conversion: dispatch on a2 via jump table jpt_5472DB; for channels 1-4 with non-null output a3, write CRTFtol(field * 255.0) to *a3 (channel 1 -> this+0x60, 2 -> this+0x50, 3 -> this+0x70, 4 -> this+0x80); any other a2 returns a2-1.
- `0x00547370` **CStringBuffer** — Byte-string copy from this into destination a2 (guarded on non-null destination): forward-copy bytes one at a time through displacement a2-this until the null terminator is copied; return the source pointer advanced past the terminator.
- `0x00547390` **FieldSelectorObject** — Selector-style field getter: selector 4096 writes this+0x8C through *a2 and returns it; selector 0x2000 writes this+0x90 through *a2 and returns a2; otherwise returns the unmodified selector a3; used per-frame by the collision detection system.
- `0x00547AF0` **StringKeyNormalizer** — Truncate the string at its first dot character (ASCII 46) by replacing it with NUL; return 1 on truncation, 0 when the string is empty or contains no dot; used to normalize a key before comparison.
- `0x00548AA0` **NodeRecordObject** — Initializer: delegate to GlobalZeroInit_c2a0, then explicitly zero seven leading dword fields (0x0..0x18) of the object; return the object pointer.
- `0x00548E20` **StringKeyedRecord** — Constructor/initializer: run the base-class zero-initializer over the whole object, clear the byte at this+0x8, zero-fill the 0x60-byte block at this+0x1C, and clear scalar fields (this+0x4, this+0x18, this+0x7C, this+0x80, this+0x84, this+0xE8..this+0xFC); return this.
- `0x00548E80` **StringKeyedRecord** — Copy the character string at a2 into the internal buffer at this+8 (self-overlap-safe byte copy terminated on NUL), normalize via sub_589901, store a3 into the dword at this+4, and return a3.

## Proposed classes

### SoundEmitter3D

3D positional sound-emitter instance state: default initialization, aim-to-target orientation update, orientation-angle getter, and byte-component color packing. Owns playback/attenuation state and a 3D position/orientation layout driven through UtilityFunction_1cd0. Field 0x7C semantics are contested between an audio-session pointer (SoundInstanceInit) and a packed color (ColorPack).

Methods: `0x005418E0`, `0x00541F60`, `0x005423E0`, `0x00542490`

- `this+0x00000004` `float volume_or_gain` (write, GUESS)
- `this+0x00000008` `float max_attenuation_distance` (write, GUESS)
- `this+0x0000000C` `int playback_state` (write, UNKNOWN)
- `this+0x00000010` `int instance_id` (write, UNKNOWN)
- `this+0x00000014` `int priority` (write, UNKNOWN)
- `this+0x00000018` `int playback_cursor` (write, UNKNOWN)
- `this+0x0000001C` `int playback_flags` (write, UNKNOWN)
- `this+0x00000020` `int sound_group` (write, UNKNOWN)
- `this+0x00000024` `float position_x` (read, GUESS)
- `this+0x00000028` `float position_y` (read, GUESS)
- `this+0x0000002C` `float position_z` (read, GUESS)
- `this+0x00000030` `float pitch_angle` (read_write, GUESS)
- `this+0x00000034` `float yaw_angle` (read_write, GUESS)
- `this+0x00000038` `float facing_component` (read_write, GUESS)
- `this+0x0000003C` `float reference_position_x` (read_write, GUESS)
- `this+0x00000040` `float reference_position_y` (read_write, GUESS)
- `this+0x00000044` `float reference_position_z` (read_write, GUESS)
- `this+0x00000048` `float orientation_velocity_0` (write, UNKNOWN)
- `this+0x0000004C` `float orientation_velocity_1` (write, UNKNOWN)
- `this+0x00000050` `float orientation_velocity_2` (write, UNKNOWN)
- `this+0x00000054` `float orientation_velocity_3` (write, UNKNOWN)
- `this+0x00000058` `float orientation_velocity_4` (write, UNKNOWN)
- `this+0x0000005C` `float orientation_velocity_5` (write, UNKNOWN)
- `this+0x00000060` `float orientation_velocity_6` (write, UNKNOWN)
- `this+0x00000064` `float orientation_velocity_7` (write, UNKNOWN)
- `this+0x00000068` `float orientation_velocity_8` (write, UNKNOWN)
- `this+0x0000006C` `float cone_inner_angle` (write, GUESS)
- `this+0x00000070` `float cone_outer_angle` (write, GUESS)
- `this+0x00000074` `float cone_attenuation` (write, GUESS)
- `this+0x00000078` `int unresolved_dword_78` (write, UNKNOWN)
- `this+0x0000007C` `int audio_session_or_packed_color` (read_write, GUESS)
- `this+0x00000080` `int unresolved_dword_80` (write, UNKNOWN)
- `this+0x00000084` `int unassigned_handle` (write, GUESS)
- `this+0x00000088` `float unresolved_dword_88` (write, UNKNOWN)
- `this+0x0000019C` `int extended_instance_0` (write, UNKNOWN)
- `this+0x000001A0` `int extended_instance_1` (write, UNKNOWN)
- `this+0x000001A4` `int extended_instance_2` (write, UNKNOWN)
- `this+0x000001A8` `int extended_instance_3` (write, UNKNOWN)
- `this+0x000001AC` `int extended_instance_4` (write, UNKNOWN)
- `this+0x000001B0` `int extended_instance_5` (write, UNKNOWN)
- `this+0x000001B4` `int extended_instance_6` (write, UNKNOWN)
- `this+0x000001B8` `int extended_instance_7` (write, UNKNOWN)

### SoundRingBuffer

Audio ring-buffer object: constructor stores size and log2 index, allocates the (8*size+16)-byte sample buffer, and zeroes accounting fields; the copy method streams samples from an external source ring into the destination buffer while tracking remaining capacity and total written and committing the advanced write pointer.

Methods: `0x0053A660`, `0x0053AB20`

- `this+0x00000000` `int size_or_element_count` (read_write, GUESS)
- `this+0x00000004` `int log2_size_index` (read_write, GUESS)
- `this+0x0000000C` `pointer buffer_write_pointer` (read_write, GUESS)
- `this+0x00000010` `int remaining_capacity` (read_write, DERIVED)
- `this+0x00000014` `int total_written_accumulator` (read_write, DERIVED)
- `this+0x00000030` `int callback_result_storage` (write, GUESS)

### SmallObjectFactory

Factory helper that allocates a small runtime object through an indirect allocator function pointer on a descriptor (a5+32, payload a5+40, arguments 1/26) and initializes its header (zero dword +0, byte +16, byte +17, dword +18, dword +22); the allocated object's class is unknown. The header offsets are only evidenced by source:raw and are not enumerated as schema fields.

Methods: `0x00539830`


### ScaledLookupTable

Reusable curve-lookup helper that reads a float entry from a buffer through a size/index and scales it by 255.0; the table's semantic purpose (gamma/volume/alpha) is not established.

Methods: `0x0053AC40`

- `this+0x00000000` `float size_or_entry_count` (read, GUESS)
- `this+0x0000000C` `pointer table_buffer_pointer` (read, GUESS)

### EmptyVirtualStub

Empty stub (nullsub) invoked from seven call sites; likely satisfies a virtual or hook-style entry that the current build stubs out. No state.

Methods: `0x0053B160`


### TwoPartStringRecord

Two-part record (leading DWORD plus null-terminated byte string) copy helper; the meaning of the leading DWORD (length/type/count) and the owner class are caller-dependent and unknown.

Methods: `0x0053C6B0`

- `this+0x00000000` `int leading_dword` (read_write, GUESS)
- `this+0x00000004` `char[] string_bytes` (read_write, GUESS)

### FieldGetterUnknownObject

Side-effect-free getter for the dword at this+0x8; callers are heterogeneous (rendering and memory-copy paths) so the owner class is not established.

Methods: `0x0053D880`

- `this+0x00000008` `int field_at_8` (read, GUESS)

### FixedSlotRecordArray

Fixed-capacity (4-slot) array of 0x43C-byte records embedded in the object; appends are bounded by the element count at this+8. The 3-dword header and the record layout are not documented in the packet.

Methods: `0x0053D8B0`

- `this+0x00000008` `int element_count` (read_write, DERIVED)

### DisplayEnumerationContext

Display adapter capability and mode enumeration: queries surface formats, multisample types, and display modes through the display-query sub-object at this+0x10FC, accumulates a capability bitmask, filters modes by the resolution window this+0x1508..this+0x1510, and reports passing modes.

Methods: `0x0053DB90`

- `this+0x00000000` `int last_call_status` (read_write, GUESS)
- `this+0x000010FC` `pointer display_query_subobject` (read, DERIVED)
- `this+0x00001508` `int min_width` (read, GUESS)
- `this+0x0000150C` `int min_height` (read, GUESS)
- `this+0x00001510` `int max_dimension` (read, GUESS)

### FlagDispatchHelper

Flags-driven virtual dispatch through a caller-supplied descriptor (holders at a2+8/+12/+16, default flags at a2+24, out slot at a2+40; evidenced only by source:raw): selects a method-holder pointer and vtable slot by flag bits and commits out-parameters; a generic thunk used by ThunkWithArgReorder.

Methods: `0x005400C0`

- `this+0x00000000` `int dispatch_result_store` (read_write, GUESS)

### SurfaceCompositor

2D surface compositing/blit/fill dispatch over caller-supplied surface descriptors and a shared render-surface sub-object at this+0x1100; supports clipped and direct blit paths, texture-coordinate block submission, and guarded virtual dispatch. Guard flag at this+0x13D8 gates two of the four methods.

Methods: `0x00540250`, `0x005404D0`, `0x00541670`, `0x005416A0`

- `this+0x00000000` `int last_call_status` (read_write, GUESS)
- `this+0x00001100` `pointer render_surface_subobject` (read, DERIVED)
- `this+0x000013D8` `int dispatch_guard_flag` (read, DERIVED)

### RenderStateFlagControl

Set/clear a single bit (bit 5, value 0x20) of the flag dword at this+0x80; used by the conditional render pipeline dispatch to toggle a render-related state flag.

Methods: `0x00542650`

- `this+0x00000080` `int bit5_flag_dword` (read_write, DERIVED)

### LinkedNodeListWalker

Walks the global singly-linked list seeded from dword_8B8F28 (next pointer at node offset +488) and invokes a handler on every node. Node struct layout beyond the next pointer is unknown.

Methods: `0x00546200`


### ChannelFloatAccessor

Channel-indexed accessor converting one of four float fields to an int scaled by 255.0; the non-monotonic channel-to-field mapping (1->0x60, 2->0x50, 3->0x70, 4->0x80) and the meaning of the fields (color vs other normalized quantity) are unresolved.

Methods: `0x005472D0`

- `this+0x00000050` `float channel_2_float` (read, GUESS)
- `this+0x00000060` `float channel_1_float` (read, GUESS)
- `this+0x00000070` `float channel_3_float` (read, GUESS)
- `this+0x00000080` `float channel_4_float` (read, GUESS)

### CStringBuffer

Byte-string copy utility: copies the null-terminated string at this into a caller-supplied destination (unbounded, self-overlap-safe by displacement) and returns the advanced source pointer. this+0 is the source string buffer, not a getter field.

Methods: `0x00547370`

- `this+0x00000000` `char[] source_string_buffer` (read, GUESS)

### FieldSelectorObject

Selector-style field getter queried per-frame by the collision detection system: selectors 4096 and 0x2000 return this+0x8C and this+0x90 through the output pointer; the meaning of the selectors and fields is unknown.

Methods: `0x00547390`

- `this+0x0000008C` `int selector_4096_field` (read, GUESS)
- `this+0x00000090` `int selector_8192_field` (read, GUESS)

### StringKeyNormalizer

String key normalizer: truncates a key at its first dot character, used by the string-search linked-list path to normalize keys before comparison. Free-standing helper with no object state.

Methods: `0x00547AF0`


### NodeRecordObject

Node initialization/reset helper: delegates to GlobalZeroInit_c2a0 and then explicitly zeroes seven leading dword fields (0x0..0x18); called from the linked-list append path. Whether the caller treats this as constructor or reset is not established.

Methods: `0x00548AA0`

- `this+0x00000000` `int node_field_0` (write, UNKNOWN)
- `this+0x00000004` `int node_field_1` (write, UNKNOWN)
- `this+0x00000008` `int node_field_2` (write, UNKNOWN)
- `this+0x0000000C` `int node_field_3` (write, UNKNOWN)
- `this+0x00000010` `int node_field_4` (write, UNKNOWN)
- `this+0x00000014` `int node_field_5` (write, UNKNOWN)
- `this+0x00000018` `int node_field_6` (write, UNKNOWN)

### StringKeyedRecord

String-keyed record: constructor zeroes the object via GlobalZeroInit_c2a0 plus scalar/block resets, and the string setter copies a caller string into this+8 (normalized via sub_589901) with metadata at this+4. Two methods share caller sub_55A790.

Methods: `0x00548E20`, `0x00548E80`

- `this+0x00000004` `int metadata_dword` (read_write, GUESS)
- `this+0x00000008` `char[] string_buffer` (read_write, GUESS)
- `this+0x00000018` `int unresolved_dword_18` (write, UNKNOWN)
- `this+0x0000007C` `int unresolved_dword_7C` (write, UNKNOWN)
- `this+0x00000080` `int unresolved_dword_80` (write, UNKNOWN)
- `this+0x00000084` `int unresolved_dword_84` (write, UNKNOWN)
- `this+0x000000E8` `int unresolved_dword_E8` (write, UNKNOWN)
- `this+0x000000EC` `int unresolved_dword_EC` (write, UNKNOWN)
- `this+0x000000F0` `int unresolved_dword_F0` (write, UNKNOWN)
- `this+0x000000F4` `int unresolved_dword_F4` (write, UNKNOWN)
- `this+0x000000F8` `int unresolved_dword_F8` (write, UNKNOWN)
- `this+0x000000FC` `int unresolved_dword_FC` (write, UNKNOWN)

## Compatibility contracts

- **RingBufferCopyAccounting** — A replacement AudioRingBufferCopy must keep destination accounting consistent: subtract every copied segment from the remaining field (this+0x10) and add it to the total-written accumulator (this+0x14), handle ring wrap-around with a second segment, and normalize the -5 passthrough status to 0 whenever a segment is actually copied.
- **SurfaceDispatchResultContract** — Every vtable call in the surface compositing/blit/fill and guarded-dispatch paths stores its result into *this (offset 0x0) and failure paths return -1; the clipped/direct blit and lock/unlock calls must preserve this status propagation for a replacement executable.
- **DisplayCapabilityBitmaskContract** — QueryDisplayModeCapabilities accumulates a capability bitmask into the caller's *a2 from format-descriptor and multisample test outcomes (bits 0x20/0x40/0x80/0x200/0x80000 and 0x1000000..0x10000000) and reports only modes inside the resolution window this+0x1508..this+0x1510; the consumer DisplayModeEnumeratorWrapper depends on this bit layout.
- **SoundEmitterAngleOrientationContract** — Aim-to-target stores the negated pitch at this+0x30 and negated yaw at this+0x34 and finalizes orientation through UtilityFunction_1cd0 with the facing component at this+0x38 and reference position at this+0x3C..0x44; the getter reads the same three fields, so the replacement must keep these offsets consistent.
- **StringRecordCopyContract** — The two-part string record and the string-keyed record both copy a null-terminated byte string followed/preceded by a leading dword (offsets 0x0/0x4 and 0x4/0x8 respectively); a replacement must preserve terminator-inclusive copies and the caller metadata dword semantics at this+4.

## Unresolved

- Owner classes of every function are UnknownObject in the packet; all class names in this proposal are DERIVED or GUESS and do not claim recovered source types.
- SoundEmitter3D field 0x7C semantics are contested: SoundInstanceInit writes an audio-device/session pointer (dword_484848, after a 0 write in the cone block) while ColorPack stores a packed color there; the two interpretations cannot both hold on one field and are left unresolved.
- Whether SoundBufferAllocator (0x0053AB20) and AudioRingBufferCopy (0x0053A660) share one ring-buffer object (0xC buffer/write pointer, 0x10 remaining, 0x14 total-written) is inferred from overlapping field usage and a shared audio path; the union is not proven by the packet.
- The source ring-buffer layout (ring[10] start, ring[11] end, ring[12] read pointer, ring[13] boundary, ring[14] callback, ring[15] callback context) is read from raw source only and is not enumerated in the packet field evidence.
- Meaning of the -5 passthrough status code in AudioRingBufferCopy and its error/success contract with callers sub_537110 and sub_539870 is unknown.
- VTableDispatchByFlags descriptor layout (holder pointers at a2+8/+12/+16, default flags at +24, out slot at +40) and the derived per-call argument flag (0 or 16) are not documented in the packet.
- SurfaceCompositor surface-descriptor array layout (a2/a5 fields at indexes 2..6, 10, 12) and the depth thresholds (>8) are not established here.
- DisplayEnumerationContext format ids 20-25, the capability bitmask bit assignment, the stack-sentinel check (v42 == 4170) with StateIntSetter4 reset (1024, 768), the duplicate-resolution skips, and the unused a3 argument are DERIVED or unexplained.
- The concrete classes behind DisplayAdapterQueryInterface and RenderSurfaceDispatchInterface are unknown; the interfaces are contracts inferred solely from vtable slot access.
- EmptyVirtualStub's intended interface (seven call sites) and the per-node handler sub_557120 semantics are unknown.
- GlobalZeroInit_c2a0's base-class relationship to NodeRecordObject and StringKeyedRecord is not identifiable; the redundant explicit zeroing after the base zero-init is unexplained.
- Color channel order in ColorPack and the non-monotonic channel-to-field mapping (1->0x60, 2->0x50, 3->0x70, 4->0x80) in FloatToIntSwitch are unconfirmed.
- Field semantics of offsets +16/+17 (bytes) and +18/+22 (dwords) on the object allocated by allocAndInitFields are unknown, as is the allocator ABI (arguments 1 and 26: element count and size, unproven).
- The role of the float constant at 0x0059E43C read by ComputeAimAnglesToTarget is unresolved; global:0x0059E43C is carried in unresolved_evidence_refs.
- Equal byte offsets across distinct classes (0x0, 0x8, 0x80, 0x7C, etc.) are not merged; each base is treated as a distinct object unless the packet proves common ownership.
