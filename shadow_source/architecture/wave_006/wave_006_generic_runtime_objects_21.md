# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

The packet resolves into fourteen defensible classes over seventeen functions, with all owner objects still UNKNOWN. TextureSurfaceManager (0x0051629F, 0x00516772, 0x00516853) allocates texture surfaces from two linked descriptor lists (node layout modeled as SurfaceDescriptorNode under bases *(this+0x68) and *(this+0x6C)), performs per-category free-list cleanup with a virtual-dispatch branch, and tears down the allocator state array; the exact mapping between the raw-source variables and the packet field bases is flagged unresolved by the packet itself. ChunkedArrayProcessor (0x0051641E, 0x005164A6) is a chunked iteration helper over an indexed element-pointer array, dispatching each boundary-clamped chunk to a cdecl callback selected by a flag. StreamResource (0x005179A2, 0x005179E0, 0x00517AC5) manages a buffer/resource pointer with allocator/free callback slots and a marker/size-validated init path. InflateStateMachine (0x00517ADC) drives the zlib-style header parse, block inflate, checksum finalize and stored-checksum compare states. The media/UI family MediaStreamPlayer (0x00516C0C, 0x00516C7B, 0x00516E28, 0x00516F76) initializes an identity-pattern buffer, configures a playback pipeline, constructs a UIControlStateMachine sub-object, and per tick dispatches seven control vtable slots; TextureFormatState (0x005169AC, 0x00516A1D) sizes texture-format entries via CeilingDivision and validates the resulting state against fixed constants through ComplexStateValidator. The remaining helpers CallbackOwnedResource (0x00516959) and NullGuardedDelegate (0x00517E85) are small teardown indirections.

## Function roles

- `0x0051629F` **TextureSurfaceManager** — Texture surface allocation under a memory budget: accumulates weighted area totals over two surface-descriptor lists, derives a budget scale factor from ShortComputation_935c, clamps per-node allocated widths and marks downscaled nodes, then allocates backing memory via MemoryAllocatorWithChunking / ChunkedBufferAlloc and initializes each node.
- `0x0051641E` **ChunkedArrayProcessor** — Chunked iteration over an indexed element-pointer array: walks the array in chunks clamped to this+0x14 and bounded by this+0x4/this+0x1C relative to index+this+0x18, dispatching each chunk to the cdecl callback at this+0x28 or this+0x2C selected by flag a3.
- `0x005164A6` **ChunkedArrayProcessor** — Chunked iteration twin with the element stride scaled by 2^7: structurally identical to the sibling helper except byte offsets use *(this+0x8) << 7; dispatches boundary-clamped chunks through the flag-selected cdecl callback.
- `0x00516772` **TextureSurfaceManager** — Per-category cleanup of the allocator's free lists: for category a2>=2 tags the vtable sub-object and virtual-dispatches; for category a2==1 drains two active-node lists invoking per-node cleanup callbacks, then frees both per-category free chains through FreeWrapper_9351 and decrements the allocation counter.
- `0x00516853` **TextureSurfaceManager** — Allocator-state teardown: runs sub_516772 for category indices 1 then 0, frees the state base block at offset 0x4 via FreeWrapper_9351, clears that pointer, and returns the result of EmptyStub_7b96.
- `0x00516959` **CallbackOwnedResource** — Cleanup-and-reset of a callback-owned sub-object: when this+0x4 is non-null invokes the cdecl callback at sub-object+0x28 with this, keeps its return value, then clears this+0x4 and this+0x10.
- `0x005169AC` **TextureFormatState** — Object-state validator: requires two byte flags clear, four dword enum/state fields equal 3/3/2/3, and the sub-object at this+0xC4 to match fixed constants plus three fields equal to the reference value from this+0x114; returns 1 only when every check passes.
- `0x00516A1D` **TextureFormatState** — Video texture format/scale setup: verifies stored width against constant 202, selects a power-of-two scale denominator from the raw width/height ratio, derives scaled allocation dimensions via CeilingDivision, sizes every format entry in the array at *(this+0xC4), resolves the output format count from the format mode, and validates via ComplexStateValidator.
- `0x00516C0C` **MediaStreamPlayer** — Identity-pattern buffer initialization: allocates a 1408-byte buffer through the allocator at this+0x4, stores base+256 at this+0x11C, zeroes the head, fills 256 identity bytes, 0x180 bytes of 0xFF, 0x180 bytes of 0x00 and a 0x80-byte copy; returns constant 0.
- `0x00516C7B` **MediaStreamPlayer** — Media stream/playback initialization constructor: captures the state-machine sub-object at this+0x17C, initializes the identity-pattern buffer, runs the enable-flag/state-machine branch (flags 0x58/0x59/0x5A), configures stream decoder or input bindings plus audio decode dispatch, allocates the playback/UI/media buffers, dispatches Huffman tree/context allocation, and sizes a child stream buffer while bumping the completion counter.
- `0x00516E28` **MediaStreamPlayer** — Per-tick update of a UI control state machine: consumes the transition flag at context+0x8 when set (dispatching main-logic/state-transition/action vtables), else under the activation gate selects the main-logic vtable from the context, then dispatches pre-update, update/render, conditional, post-input, main-logic, state-transition and action vtables, and finally updates the child control at this+0x8.
- `0x00516F76` **MediaStreamPlayer** — State-machine sub-object construction: allocates a 28-byte sub-object through the allocator at this+0x4, stores it at this+0x17C, zeroes its +8 flag, seeds its first dword with UIControlStateMachine (0x00516E28) and second with PhysicsStepCounterIncrement (0x00516F55), then delegates remaining initialization to sub_516C7B.
- `0x005179A2` **StreamResource** — Resource sub-object release via callback: validates the owner and the resource sub-object at this+0x1C, optionally hands off to sub_527EED, invokes the callback at this+0x24 with (this+0x28, this+0x1C), clears this+0x1C, and returns 0 on success or -2 on null guards.
- `0x005179E0` **StreamResource** — Stream resource initialization: validates a marker byte and size, installs default alloc/free callback wrappers when empty, allocates a 24-byte buffer via the allocator callback, configures signedness and bit-width exponent, builds a 1<<v6 resource table via sub_5276C5, resets the resource on success, and cleans up through sub_5179A2 with a negative error code on any failure.
- `0x00517AC5` **StreamResource** — Thin forwarding wrapper: calls sub_5179E0(a1, 15, a2, a3), inserting literal constant 15 as the second argument, and returns sub_5179E0's result; the constant is likely a mode/type selector.
- `0x00517ADC` **InflateStateMachine** — Inflate-block state-machine driver: parses the zlib/raw deflate header (method, window size, header check, optional 32-bit dictionary length), decompresses blocks via sub_527752, finalizes the checksum via sub_52765A and verifies the stored 4-byte checksum, dispatching through a state jump table at global 0x00517E0B.
- `0x00517E85` **NullGuardedDelegate** — Null-guarded delegation: when the pointer argument is non-null forwards it to sub_58AA6F and returns that call's result; used as a checked indirection step by object teardown paths.

## Proposed classes

### TextureSurfaceManager

Texture-surface allocator: walks two linked surface-descriptor lists to accumulate weighted area totals, derives a memory-budget scale factor, clamps per-node allocated widths, allocates node backing memory, and owns per-category free-list cleanup plus allocator-state teardown.

Methods: `0x0051629F`, `0x00516772`, `0x00516853`

- `this+0x00000000` `void** vtable_pointer` (read, DERIVED)
- `this+0x00000004` `dword* state_array_pointer` (read_write, DERIVED)
- `this+0x00000044` `ptr surface_list_head_1` (read_write, DERIVED)
- `this+0x00000048` `ptr surface_list_head_2` (read_write, DERIVED)
- `this+0x0000004C` `dword allocation_counter_or_format` (read_write, DERIVED)

### SurfaceDescriptorNode

Linked node of the two surface-descriptor lists walked by DirectXTextureSurfaceAllocation and drained by FreeListCleanupByCategory: carries area weight factors, a divisor/mip component, allocated width, format, per-node state fields, an allocation pointer, a next pointer, a downscale/active flag and a cleanup callback. Twin list; fields listed for both list bases.

Methods: 

- `*(this+0x68)+0x00000000` `ptr allocation_pointer` (read_write, DERIVED)
- `*(this+0x68)+0x00000004` `dword area_weight_width` (read, GUESS)
- `*(this+0x68)+0x00000008` `dword area_weight_height` (read, GUESS)
- `*(this+0x68)+0x0000000C` `dword divisor_or_mip_component` (read, GUESS)
- `*(this+0x68)+0x00000010` `dword allocated_width` (read_write, DERIVED)
- `*(this+0x68)+0x00000014` `dword surface_format` (read_write, DERIVED)
- `*(this+0x68)+0x00000018` `dword per_node_state_1` (read_write, GUESS)
- `*(this+0x68)+0x0000001C` `dword per_node_state_2` (read_write, GUESS)
- `*(this+0x68)+0x00000021` `byte byte_flag_cleared_on_alloc` (read_write, GUESS)
- `*(this+0x68)+0x00000022` `byte downscale_or_active_flag` (read_write, DERIVED)
- `*(this+0x68)+0x00000024` `ptr next_pointer` (read, DERIVED)
- `*(this+0x68)+0x00000030` `ptr cleanup_callback` (read, DERIVED)
- `*(this+0x6C)+0x00000000` `ptr allocation_pointer` (read_write, DERIVED)
- `*(this+0x6C)+0x00000004` `dword area_weight_width` (read, GUESS)
- `*(this+0x6C)+0x00000008` `dword area_weight_height` (read, GUESS)
- `*(this+0x6C)+0x0000000C` `dword divisor_or_mip_component` (read, GUESS)
- `*(this+0x6C)+0x00000010` `dword allocated_width` (read_write, DERIVED)
- `*(this+0x6C)+0x00000014` `dword surface_format` (read_write, DERIVED)
- `*(this+0x6C)+0x00000018` `dword per_node_state_1` (read_write, GUESS)
- `*(this+0x6C)+0x0000001C` `dword per_node_state_2` (read_write, GUESS)
- `*(this+0x6C)+0x00000021` `byte byte_flag_cleared_on_alloc` (read_write, GUESS)
- `*(this+0x6C)+0x00000022` `byte downscale_or_active_flag` (read_write, DERIVED)
- `*(this+0x6C)+0x00000024` `ptr next_pointer` (read, DERIVED)
- `*(this+0x6C)+0x00000030` `ptr cleanup_callback` (read, DERIVED)

### ChunkedArrayProcessor

Chunked iteration over an indexed element-pointer array: clamps each chunk to the chunk-size limit and to the bounds this+0x4/this+0x1C relative to index+this+0x18, computes byte offsets from the stride (optionally 2^7-scaled), and dispatches the chunk to a flag-selected cdecl callback.

Methods: `0x0051641E`, `0x005164A6`

- `this+0x00000000` `void** element_pointer_array` (read, DERIVED)
- `this+0x00000004` `dword chunk_lower_bound` (read, GUESS)
- `this+0x00000008` `dword element_stride_bytes` (read, DERIVED)
- `this+0x00000010` `dword total_element_count` (read, DERIVED)
- `this+0x00000014` `dword chunk_size_limit` (read, DERIVED)
- `this+0x00000018` `dword offset_boundary_value` (read, DERIVED)
- `this+0x0000001C` `dword chunk_upper_bound` (read, GUESS)
- `this+0x00000028` `ptr default_chunk_callback` (read, DERIVED)
- `this+0x0000002C` `ptr alternate_chunk_callback` (read, DERIVED)

### CallbackOwnedResource

Small teardown/reset wrapper: owns a sub-object pointer at this+0x4 carrying a cdecl cleanup callback at +0x28, invokes it with this when present, then clears this+0x4 and this+0x10.

Methods: `0x00516959`

- `this+0x00000004` `ptr owned_sub_object_pointer` (read_write, DERIVED)
- `this+0x00000010` `dword state_cleared_on_reset` (read_write, DERIVED)
- `*(this+0x4)+0x00000028` `ptr cleanup_callback` (read, DERIVED)

### TextureFormatState

Video texture format/scale state object: verifies the reference width, derives a power-of-two scale denominator, sizes format entries, resolves the output format count from the format mode, and validates the resulting state against fixed constants through ComplexStateValidator.

Methods: `0x005169AC`, `0x00516A1D`

- `this+0x00000000` `void** vtable_pointer` (read, DERIVED)
- `this+0x00000010` `dword expected_reference_width` (read, DERIVED)
- `this+0x00000018` `dword source_width_for_scaling` (read, DERIVED)
- `this+0x0000001C` `dword source_height_for_scaling` (read, DERIVED)
- `this+0x00000020` `dword format_entry_count` (read, DERIVED)
- `this+0x00000024` `dword state_enum_must_equal_3` (read, GUESS)
- `this+0x00000028` `dword format_mode` (read, DERIVED)
- `this+0x0000002C` `dword raw_width` (read, DERIVED)
- `this+0x00000030` `dword raw_height` (read, DERIVED)
- `this+0x00000048` `byte byte_flag_must_be_clear` (read, DERIVED)
- `this+0x0000004A` `byte byte_flag_selects_one_vs_count` (read, DERIVED)
- `this+0x0000005C` `dword scaled_allocation_width` (write, DERIVED)
- `this+0x00000060` `dword scaled_allocation_height` (write, DERIVED)
- `this+0x00000064` `dword resolved_format_count` (read_write, DERIVED)
- `this+0x00000068` `dword output_count` (write, DERIVED)
- `this+0x0000006C` `dword validated_result_value` (write, DERIVED)
- `this+0x000000C4` `void** format_entry_array_pointer` (read, DERIVED)
- `this+0x00000108` `byte second_byte_flag_must_be_clear` (read, DERIVED)
- `this+0x0000010C` `dword scale_bound_width` (read, DERIVED)
- `this+0x00000110` `dword scale_bound_height_or_stored_value` (read_write, DERIVED)
- `this+0x00000114` `dword scale_denominator_or_reference` (read_write, DERIVED)

### TextureFormatEntryArray

Sub-object/array at *(this+0xC4): per-entry width, winning scale, allocation width/height written by VideoTextureFormatSetup, and a set of fixed-constant state fields plus three fields validated against the reference value by ComplexStateValidator.

Methods: 

- `*(this+0xC4)+0x00000008` `dword state_enum_must_equal_2` (read, GUESS)
- `*(this+0xC4)+0x0000000C` `dword entry_width` (read, DERIVED)
- `*(this+0xC4)+0x00000024` `dword entry_scale_or_reference_field` (read_write, GUESS)
- `*(this+0xC4)+0x00000028` `dword allocation_width` (write, DERIVED)
- `*(this+0xC4)+0x0000002C` `dword allocation_height` (write, DERIVED)
- `*(this+0xC4)+0x0000005C` `dword state_constant_must_equal_1` (read, GUESS)
- `*(this+0xC4)+0x00000060` `dword state_constant_must_equal_1_alt` (read, GUESS)
- `*(this+0xC4)+0x00000078` `dword state_field_matches_reference` (read, GUESS)
- `*(this+0xC4)+0x000000B0` `dword state_constant_must_equal_1_b` (read, GUESS)
- `*(this+0xC4)+0x000000B4` `dword state_constant_must_equal_1_c` (read, GUESS)
- `*(this+0xC4)+0x000000CC` `dword state_field_matches_reference_alt` (read, GUESS)

### MediaStreamPlayer

Media stream/playback and UI-control object: initializes the identity-pattern buffer, runs the media setup state branch keyed on this+0x64==3, configures stream decoder or input bindings, allocates playback/UI/media buffers, dispatches Huffman tree/context allocation, constructs and drives a UIControlStateMachine context at this+0x17C, and per tick dispatches seven control vtable slots to its sub-objects.

Methods: `0x00516C0C`, `0x00516C7B`, `0x00516E28`, `0x00516F76`

- `this+0x00000000` `void** vtable_pointer` (read, DERIVED)
- `this+0x00000004` `void** allocator_sub_object_pointer` (read, DERIVED)
- `this+0x00000008` `void** child_stream_buffer_control` (read, DERIVED)
- `this+0x00000020` `dword count_for_buffer_sizing` (read, DERIVED)
- `this+0x00000040` `byte gate_byte_flag` (read, DERIVED)
- `this+0x00000041` `byte bypass_byte_flag` (read, DERIVED)
- `this+0x0000004A` `byte enable_byte_flag` (read, DERIVED)
- `this+0x00000050` `dword button_condition` (read, DERIVED)
- `this+0x00000058` `byte single_button_state_flag` (read_write, DERIVED)
- `this+0x00000059` `byte state_flag_input_via_74` (read_write, GUESS)
- `this+0x0000005A` `byte state_flag_input_via_50` (read_write, GUESS)
- `this+0x00000064` `dword state_enum_must_equal_3` (read, GUESS)
- `this+0x00000074` `dword counter` (read_write, DERIVED)
- `this+0x000000C8` `byte huffman_tree_flag` (read, GUESS)
- `this+0x000000C9` `byte huffman_context_or_vtable_flag` (read, GUESS)
- `this+0x00000118` `dword buffer_sizing_multiplier` (read, DERIVED)
- `this+0x0000011C` `void* identity_pattern_buffer_base` (read_write, DERIVED)
- `this+0x0000017C` `void** state_machine_context_pointer` (read_write, DERIVED)
- `this+0x00000180` `void** action_vtable_pointer` (read, DERIVED)
- `this+0x00000184` `void** update_render_vtable_pointer` (read, DERIVED)
- `this+0x00000188` `void** state_transition_vtable_pointer` (read, DERIVED)
- `this+0x0000018C` `void** playback_mode_sub_object_pointer` (read, DERIVED)
- `this+0x00000198` `void** pre_update_vtable_pointer` (read, DERIVED)
- `this+0x0000019C` `void** post_input_vtable_pointer` (read, DERIVED)
- `this+0x000001A0` `void** conditional_vtable_pointer` (read, DERIVED)
- `this+0x000001A4` `void** main_logic_vtable_pointer` (read_write, DERIVED)
- `*(this+0x4)+0x00000000` `ptr allocator_vtable_slot_0` (read, GUESS)
- `*(this+0x4)+0x00000018` `ptr allocator_vtable_slot_6` (read, GUESS)

### UIControlStateMachine

28-byte state-machine context constructed by ObjectConstructor_6f76 at this+0x17C: first dword seeded with UIControlStateMachine (0x00516E28) as its vtable/entry, second dword with PhysicsStepCounterIncrement (0x00516F55), then transition flag, data/completion counter, condition byte and two main-logic vtable pointers read/written by the per-tick update.

Methods: 

- `*(this+0x17C)+0x00000008` `byte transition_trigger_flag` (read_write, DERIVED)
- `*(this+0x17C)+0x0000000C` `dword context_data_or_completion_counter` (read_write, DERIVED)
- `*(this+0x17C)+0x00000010` `byte condition_byte` (read, DERIVED)
- `*(this+0x17C)+0x00000014` `void** main_logic_vtable_single_button` (read, DERIVED)
- `*(this+0x17C)+0x00000018` `void** main_logic_vtable_button_and_hold` (read, DERIVED)

### PlaybackModeControl

Sub-object at this+0x18C: virtual slot +8 whose result is returned by the media initialization, a flag byte at +0x10 that gates the final buffer sizing, and the source of the sub-object whose +0x10 flag is read per tick.

Methods: 

- `*(this+0x18C)+0x00000008` `ptr virtual_slot_8` (read, GUESS)
- `*(this+0x18C)+0x00000010` `byte flag_byte_gates_buffer_sizing` (read, GUESS)

### ChildStreamBuffer

Child stream-buffer control at this+0x8: buffer fields written during media initialization (size v6*multiplier, flags) and width/offset fields updated each tick from the state-machine context. The +0x11 gate byte is packet-labeled under this base although the raw source dereferences the *(this+0x18C) sub-object.

Methods: 

- `*(this+0x8)+0x00000004` `dword buffer_state_field` (write, GUESS)
- `*(this+0x8)+0x00000008` `dword buffer_byte_size` (write, DERIVED)
- `*(this+0x8)+0x0000000C` `dword width_copied_from_context` (read_write, DERIVED)
- `*(this+0x8)+0x00000010` `dword offset_state_field` (read_write, DERIVED)
- `*(this+0x8)+0x00000011` `byte gate_byte` (read, GUESS)

### StreamResource

Stream/resource object with allocator/free callback slots: validates a marker/size header, installs default callback wrappers when empty, allocates a 24-byte internal buffer through the allocator callback, configures signedness/bit-width and a resource table, resets the resource on success and releases it through the callback on teardown.

Methods: `0x005179A2`, `0x005179E0`, `0x00517AC5`

- `this+0x00000018` `dword reset_counter_or_state_flag` (write, DERIVED)
- `this+0x0000001C` `void* buffer_or_resource_pointer` (read_write, DERIVED)
- `this+0x00000020` `ptr allocator_callback` (read_write, DERIVED)
- `this+0x00000024` `ptr free_callback` (read, DERIVED)
- `this+0x00000028` `void* allocator_context` (read, DERIVED)
- `this+0x0000002C` `dword buffer_field_size_or_signedness` (read_write, GUESS)
- `this+0x00000030` `dword buffer_field_bit_width_exponent` (read_write, GUESS)

### InflateStateMachine

Zlib/raw-deflate inflate driver: a state machine (header parse, dictionary handling, block inflate, checksum finalize, stored-checksum compare) dispatching through a jump table at global 0x00517E0B, with error strings reported via this+0x18.

Methods: `0x00517ADC`

- `this+0x00000000` `dword state_selector` (read_write, DERIVED)
- `this+0x00000004` `dword input_accumulator` (read_write, DERIVED)
- `this+0x00000008` `dword window_size_or_dict_length` (read_write, DERIVED)
- `this+0x00000018` `char* error_message_string_pointer` (write, DERIVED)
- `this+0x00000024` `dword accumulated_checksum` (read, DERIVED)
- `this+0x00000028` `void* decompression_context_pointer` (read, DERIVED)
- `this+0x0000002C` `dword stored_expected_checksum` (read, DERIVED)
- `this+0x00000030` `void* window_pointer` (write, DERIVED)

### NullGuardedDelegate

Null-guarded cdecl indirection: forwards a non-null pointer argument to sub_58AA6F and returns its result; used by object teardown paths as a checked delegation step.

Methods: `0x00517E85`


### VTableErrorDispatch

Shared pattern object (base obj, the vtable struct reached through this+0x0): a dispatch code is written at +0x14, a payload value at +0x18, then the vtable[0] method is invoked with the owning object. Used by allocator cleanup, the video-texture error path, media initialization and the tick fallback.

Methods: 

- `obj+0x00000000` `void** vtable_pointer` (read, DERIVED)
- `obj+0x00000014` `dword dispatch_or_error_code` (write, DERIVED)
- `obj+0x00000018` `dword payload_value` (write, DERIVED)

## Compatibility contracts

- **TextureSurfaceBudgetScaling** — Texture-surface allocation must derive the per-surface scale factor as v14 = ShortComputation_935c(a1, v3, v4) when v3 > 0; when budget < v4 clamp v14 to max(budget/v3, 1), otherwise treat it as unlimited (1000000000). Per unallocated node, when (width - 1)/divisor + 1 exceeds v14, node+0x10 must be clamped to v14*divisor and byte node+0x22 set to 1 (downscaled), else node+0x10 keeps the original width.
- **SurfaceDescriptorNodeLayout** — Surface-descriptor nodes in both lists share one layout: allocation pointer at +0x0, area weight factors at +0x4/+0x8, divisor/mip component at +0xC, allocated width at +0x10, format at +0x14, zeroed state at +0x18/+0x1C, byte flag at +0x21, downscale/active flag at +0x22, next pointer at +0x24 and cleanup callback at +0x30.
- **FreeListAllocatorCategoryLifecycle** — Per-category teardown: category a2==1 drains the active-node lists (heads at this+0x44/this+0x48) invoking the cleanup callback at node+0x30 with (a1, node+0x28) for flagged nodes, then frees both per-category free chains through FreeWrapper_9351 and decrements the counter at this+0x4C by node[2]+node[1]+16; category a2>=2 tags the vtable sub-object (+0x14=12, +0x18=a2) and virtual-dispatches.
- **ChunkedIterationCallbackContract** — Chunked iteration must clamp each chunk to the chunk-size limit (this+0x14) and to the bounds this+0x4/this+0x1C relative to index+this+0x18, compute byte offsets as stride*index (stride = this+0x8, or <<7 for the scaled twin), and dispatch the selected cdecl callback at this+0x28/this+0x2C with (destination, state this+0x28, element pointer from *(this+0x0)+4*i, base byte offset, chunk byte count).
- **InflateHeaderAndChecksumContract** — Inflate must parse and validate the zlib/raw-deflate header (compression method == 8, window size bounds, header check byte mod 31, optional FDICT with 32-bit dictionary length), decompress blocks via sub_527752, finalize the checksum via sub_52765A, and compare the accumulated checksum (this+0x24) against the stored 4-byte checksum (this+0x2C); failures set state 13, store an error string at this+0x18 and return -3/-2.
- **StreamResourceMarkerAndAllocatorContract** — Stream resource init must reject null receiver (-2), validate the header (marker byte == 49 and size == 56, else -6), install default DelegationWrapper_803a / FreeWrapper_9351 when the allocator/free slots are empty, allocate a 24-byte buffer through the allocator callback (context this+0x28, 1, 24), build the 1<<v6 resource table via sub_5276C5, and on any failure clean up through sub_5179A2 returning -2/-4; teardown invokes the callback at this+0x24 with (this+0x28, this+0x1C) and clears this+0x1C.
- **MediaStreamVTableDispatchOrder** — Per tick, when the transition-trigger flag at context+0x8 is set the main-logic/state-transition/action vtables must be dispatched with arguments 0/2/2 and input logic skipped; otherwise, under the activation gate, the pre-update, update/render (slot 2), conditional (when context+0x10 clear), post-input, main-logic, state-transition (3 or 0) and action dispatches must run in that order, and the child control at this+0x8 updated last.

## Unresolved

- DirectXTextureSurfaceAllocation: the exact base mapping between the raw source variables (a1, v1 = a1[1], list heads v1[16]/v1[17]) and the packet field bases *(this+0x68), *(this+0x6C) and this is not established by the packet; node offsets follow the extraction labels.
- The first-list head (v1[16]) has no packet field evidence reference; only the second-list head (this+0x44) and the format source (this+0x4C) are represented in the field table. TextureSurfaceManager fields this+0x8C and this+0x50 have no grounded meaning.
- Interpretation of the accumulated list terms as pixel areas is DERIVED from the analysis fill, not independently evidenced; the destination of the two lists (texture surfaces versus another resource class) is unknown.
- FreeListAllocator cleanup: identity of the state array at *(this+0x4), the virtual method dispatched in the a2>=2 branch, and the semantics of the per-node size components (node[2]+node[1]+16) are unknown.
- VideoTextureFormatSetup: the legacy ABI label Audio_Sample_Rate_Conversion contradicts the video-texture semantics of the body (LEGACY trust, not reflected in the operation model); the validator argument v14 versus the stored count this+0x64, the dual role of this+0x110, and the meanings of the constants 1/2/3 are not grounded.
- The object behind this+0x0 used only on the 0x00516A1D width-mismatch error path has no type evidence.
- MediaStreamPlayer: the seven vtable-dispatched functions (this+0x180, 0x184 slot 2, 0x188, 0x198, 0x19C, 0x1A0, 0x1A4) and the virtual slots at +0x18 of the this+0x4 sub-object and +8 of the this+0x18C sub-object have no concrete targets or vtable identities; the allocator implementations are runtime-resolved.
- tick (0x00516E28) doubles as the vtable/entry address ObjectConstructor_6f76 writes into the first dword of the UIControlStateMachine context; whether its owner is the player or the context is ambiguous (assigned to MediaStreamPlayer in this proposal).
- Byte-gate read at *(this+0x8):0x00000011: the raw source dereferences the sub-object loaded from this+0x18C, but the packet labels the field base as *(this+0x8); kept as recorded.
- Semantics of the control flags this+0x40/0x41/0x4A/0x50/0x58/0x59/0x5A/0x74 and the state enum this+0x64 (guard compares ==3) in the media object are not evidenced.
- InitMediaStreamPlayback calls sub_516A1D with an uninitialized stack local v7; the intended argument is unevidenced, and why the byte at *(this+0x18C)+0x10 gates the final buffer sizing is unknown.
- StreamResourceInit: packet guard:1 is recorded against this+0x28 while the raw source guards the free-callback slot a1[9] (this+0x24); the buffer-internal field mapping (this+0x2C/0x30 versus buffer+12/16) and the role of buffer+20 are not proven.
- CleanupResourceWithCallback: field this+0x30 appears in the deterministic field facts but is absent from the decompiled source body; it may feed sub_527EED but is not grounded.
- InflateBlockProcessor: the field offsets mix the stream-wrapper array and the inner inflate state structure; the raw-source immediate state[5] (+0x14) passed to sub_527752 does not align with the fact-table 0x28/0x2C; the role of this+0x20 (initialized to 0) is unknown; sub_527752/sub_52765A argument layouts are unavailable.
- ForwardToSub5179E0WithConstantMode: the meaning of the literal constant 15 is not determinable from this packet.
- GuardedDelegate: identity/signature/behavior of the delegated target sub_58AA6F are outside this packet; whether the a1==null fall-through (uninitialized result) is reached by callers is unknown.
- TextureFormatEntryArray: the entry pointer +12 with stride 0x54 from VideoTextureFormatSetup does not reconcile cleanly with the fixed validation offsets (+0x8..+0xCC) read by ComplexStateValidator; treated as a single sub-object layout per packet labels, unproven.
- All owner objects remain UnknownObject; every class in this proposal is a DERIVED/GUESS grouping and no field, enum or vtable identity should be treated as CONFIRMED without independent static or runtime corroboration.
