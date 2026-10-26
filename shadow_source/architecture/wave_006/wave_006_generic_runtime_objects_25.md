# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

DERIVED proposal for 15 functions spanning three weakly-linked runtime clusters. Cluster 1 (CodecBufferObject: 0x51E2BA, 0x51E3E7, 0x51E512, 0x51E7D7, 0x51E8D6, 0x51EA90, 0x51EB6E) shares a common owner shape: this+0x64 channel count, this+0x4C mode selector, this+0x4 allocator vtable, this+0x1A4 sub-buffer context, and status writes to obj+0x14/obj+0x18 before virtual dispatch. Cluster 2 (PackedSIMDMath: 0x520C0E, 0x520CE0, 0x521895, 0x5219E1, 0x52266C, 0x52278B, 0x522A13) is straight-line packed-float math over global constant tables with no object state. Cluster 3 (ResourceStateStruct: 0x52765A) resets a resource-state struct and dispatches type handlers on state values 4/5/6. Owner identity for every function is UNKNOWN in the packet; class boundaries are DERIVED hypotheses and the obj-base/sub-buffer-base identity conflict is explicitly unresolved.

## Function roles

- `0x0051E2BA` **CodecBufferObject** — Fills the sub-buffer image buffer with per-channel stride gradient bytes: obtains a permutation count from CombinatorialPermutationGenerator over context+0x20, writes status (93 three-channel / 94 otherwise) and strides to the obj base, allocates the output buffer via the allocator vtable at this+0x4, fills per-channel gradient bytes, and persists the count and buffer pointer into the sub-buffer.
- `0x0051E3E7` **CodecBufferObject** — Builds per-channel lookup tables in an allocated output buffer: selects normal (0) or extended (510, mirrored across the 255 index) mode from this+0x4C, allocates via this+0x4 vtable slot +8, fills 256 entries per channel from a per-channel stride array with a stepped base value.
- `0x0051E512` **CodecBufferObject** — Builds a 1024-byte per-entry division lookup table array: for each of this+0x64 entries reads the descriptor from *(this+0x1A4)+0x20, reuses an existing table for an equal previously-seen descriptor, otherwise allocates via the allocator vtable at this+0x4 and fills (65025 - 510*byte)/((desc<<9)-512) over the global double table dbl_5B05C8..dword_5B06C8, storing pointers into context+0x34 slots.
- `0x0051E7D7` **CodecBufferObject** — Three-channel sample generator: loads the synthesis context at this+0x1A4, reads component table bases at context+0x18, and for each of a4 pixels advances a 4-bit phase counter at context+0x30, computes per-channel table bases by (phase<<6)+context+0x34/0x38/0x3C, and sums one byte per channel into the destination for each of this+0x5C samples.
- `0x0051E8D6` **CodecBufferObject** — Lookup-table convolution with 3/5/7 error diffusion over output rows: zero-fills each row via MemoryZeroFill, reads index tables on the context (context+16/+24/+68), convolves each byte with scaled error diffusion, and toggles the scan-direction byte (context+84) each row for serpentine scanning.
- `0x0051EA90` **CodecBufferObject** — Codec/processing mode selector: copies sub-buffer format fields into this+0x70/this+0x74, dispatches on this+0x4C (0/1/2/>=3), installs the matching codec function pointer into sub-buffer+4 (this+0x1A8), performs conditional sub-buffer initialization (sub_51E3E7, PerIndexTableGenerationWithDivision, VirtualArrayFill, MemoryZeroFill), and on unknown selectors sets error code 47 at obj+0x14 and invokes the virtual handler.
- `0x0051EB6E` **CodecBufferObject** — Sub-object setup with bounds checking: allocates an 88-byte sub-object via the factory pointer at this+0x4, stores it at this+0x1A4, installs CodecModeSelect/nullsub_4/VirtualCallWithIntegerSet and zeroes obj+0x34/obj+0x44, clamps bound/dimension fields (writes 54/4 when this+0x64>4, 56/256 when this+0x54>256) with a virtual dispatch, then drives ImageBufferStrideFill, sub_51E3E7 and conditionally VirtualArrayFill.
- `0x00520C0E` **PackedSIMDMath** — SSE quaternion-to-4x4-rotation-matrix conversion: loads two low floats of the input quaternion, clears sign bits with global 0x5D8D20, computes a sum-of-squares magnitude, refines an approximate reciprocal sqrt with one Newton-Raphson step (0x5D8D00/0x5D8D10), scales via 0x5D8CF0 and combines with row-bias constants 0x5D8CB0-0x5D8CE0 to write four SSE rows at a1+0x0/0x10/0x20/0x30. Straight-line, no calls.
- `0x00520CE0` **PackedSIMDMath** — Rotation-matrix-to-axis-angle conversion (third variant of the family, distinct constant set 0x8D6270-0x8D6298): computes the matrix trace, uses the trace formula when trace exceeds 0x8D627C, otherwise selects the largest diagonal via LUT 0x8D6270 and computes axis/angle from off-diagonal sums. No calls. Packet name TriangleClosestPointOrNormal is LEGACY and contradicts the observed algorithm.
- `0x00521895` **PackedSIMDMath** — 3DNow! normalization of a 4-component orientation vector: reads both 64-bit halves, extracts the 4th component, passes input through unchanged when it is >= 1.0, otherwise refines a reciprocal via SquareRootApproximation, sub_529700 and pfrcp/pfrcpit1/pfrcpit2 guarded by the packed threshold, scales both halves and writes the masked result.
- `0x005219E1` **PackedSIMDMath** — 3DNow! multi-quaternion composition: loads up to four input quaternions, performs shortest-path sign-flip selection via packed sum-vs-difference comparisons, normalizes a6 and two product pairs through reciprocal refinements with SquareRootApproximation/sub_529700/PackedFloatingPointMath, and writes three output quaternions (a2/a3/a4); a4 also receives the selected a7 components directly.
- `0x0052266C` **PackedSIMDMath** — 4x4 float matrix determinant via 3DNow! packed-float arithmetic: forms three 2x2 sub-determinants from shuffled packed pairs, accumulates a cofactor-weighted sum, flushes MMX state and returns the low 32 bits of the accumulate as a float. No guards, branches or calls.
- `0x0052278B` **PackedSIMDMath** — 3DNow! quaternion-from-angle matrix builder: normalizes the axis vector via F_3DVectorNormalize_7578 into a 16-byte working pair, combines it with a quaternion/vector pair using packed multiply/accumulate and a packed sign-flip mask (0x8000000080000000, tied to global 0x5AF9D0), and writes all 8 __m64 slots of the output forming a 4x4 rotation-style matrix. Straight-line, no branches.
- `0x00522A13` **PackedSIMDMath** — Decodes an encoded axis-angle parameter into a 4x4 matrix in an __m64 output buffer: expands the parameter via PackedFloatingPointMath, places it at a1[0], a negated reshuffled copy at a1[2], 1.0 identity elements at a1[5]/a1[7], and zeros elsewhere. Straight-line, no branches.
- `0x0052765A` **ResourceStateStruct** — Resource-state struct reset: optionally reports the previous callback slot to a3, dispatches type handlers on state 4/5 (indirect call at a2+36 with a2+40 and this+0xC) or 6 (IndirectCallDispatch with this+0x4 and a2), copies this+0x28 into tracking slots this+0x30/this+0x34, clears this+0x0/this+0x1C/this+0x20, and invokes the callback at this+0x38 with (0,0,0) storing its result to this+0x3C and a2+48.

## Proposed classes

### CodecBufferObject

Owner shape shared by the buffer-processing functions: carries a mode selector (this+0x4C), channel count (this+0x64), a per-pixel width/row count (this+0x5C), an allocator vtable pointer (this+0x4), and a sub-buffer context pointer (this+0x1A4) whose flattened offsets this+0x1A8..this+0x1F8 hold codec function pointers, results, stride arrays and init flags. Flattened field names are the extractor's this-based encoding of sub-buffer-relative offsets, not proof of a this-sized struct.

Methods: `0x0051E2BA`, `0x0051E3E7`, `0x0051E512`, `0x0051E7D7`, `0x0051E8D6`, `0x0051EA90`, `0x0051EB6E`

- `this+0x00000000` `void* vtable_object_base` (read, DERIVED)
- `this+0x00000004` `void** allocator_vtable_ptr` (read, DERIVED)
- `this+0x0000004C` `int mode_selector` (read, DERIVED)
- `this+0x00000054` `int upper_dimension_field` (read, GUESS)
- `this+0x0000005C` `int per_pixel_width` (read, DERIVED)
- `this+0x00000064` `int channel_count` (read, DERIVED)
- `this+0x00000070` `int format_copy_a` (write, GUESS)
- `this+0x00000074` `int format_copy_b` (write, GUESS)
- `this+0x0000011C` `int row_byte_stride` (read, DERIVED)
- `this+0x000001A4` `void* sub_buffer_context_ptr` (read_write, DERIVED)
- `this+0x000001A8` `void (*)() codec_fn_slot` (write, DERIVED)
- `this+0x000001B4` `void* sub_buffer_output_ptr` (write, DERIVED)
- `this+0x000001B8` `int sub_buffer_count` (write, DERIVED)
- `this+0x000001BC` `void* sub_buffer_table_ptr` (write, GUESS)
- `this+0x000001C0` `int sub_buffer_init_flag` (read, GUESS)
- `this+0x000001C4` `int* stride_array_0` (read, DERIVED)
- `this+0x000001C8` `int stride_array_1` (read, GUESS)
- `this+0x000001CC` `int stride_array_2` (read, GUESS)
- `this+0x000001D4` `int sub_buffer_zero_slot` (write, GUESS)
- `this+0x000001D8` `int sub_buffer_table_flag` (read, GUESS)
- `this+0x000001E8` `void** sub_buffer_virtual_array` (read, GUESS)
- `this+0x000001F8` `char scan_direction_toggle` (read_write, GUESS)

### CodecSubBuffer

The context object reached through this+0x1A4. Carries component/descriptor and phase-table state in +0x18..+0x3C and per-entry table-slot storage at +0x34. Layout evidence overlaps between functions (context+0x34 is both per-entry table slots and a phase-table base; context+0x20 is both a descriptor array base and a component offset), so field semantics beyond +0x30/+0x34 are GUESS.

Methods: 

- `*(this+0x1A4)+0x00000018` `void** component_table_base` (read, DERIVED)
- `*(this+0x1A4)+0x0000001C` `int component_offset_1` (read, GUESS)
- `*(this+0x1A4)+0x00000020` `int* component_offset_2_or_descriptor_array` (read, GUESS)
- `*(this+0x1A4)+0x00000030` `int phase_counter_4bit` (read_write, DERIVED)
- `*(this+0x1A4)+0x00000034` `void* phase_table_0_or_table_slots` (read_write, GUESS)
- `*(this+0x1A4)+0x00000038` `void* phase_table_1` (read, DERIVED)
- `*(this+0x1A4)+0x0000003C` `void* phase_table_2` (read, DERIVED)

### CodecObject

Object base reached through the vtable anchor (*this, base 'obj'). Receives status/error code writes (93/94/47/54/56) at +0x14, a count/bound value at +0x18, stride values at +0x1C..+0x24, and initialized handler pointers at +0x0 (CodecModeSelect), +0x8 (nullsub_4) and +0xC (VirtualCallWithIntegerSet). Whether 'obj' equals the sub-buffer at this+0x1A4 or the object at this+0x0 is unconfirmed; both are folded under one base by the extractor.

Methods: 

- `obj+0x00000000` `void (*)(void*) codec_mode_handler` (read_write, DERIVED)
- `obj+0x00000004` `void (*)() vtable_slot_1` (read, DERIVED)
- `obj+0x00000014` `int status_or_error_code` (write, DERIVED)
- `obj+0x00000018` `int count_or_bound_value` (write, DERIVED)
- `obj+0x0000001C` `int stride_0` (write, DERIVED)
- `obj+0x00000020` `int stride_1` (write, DERIVED)
- `obj+0x00000024` `int stride_2` (write, DERIVED)

### AllocatorVtable

Vtable object reached through this+0x4 whose entry 0 is an allocate function called with (owner, 1, size[, mode]); callers use the returned pointer as an output buffer or sub-object. Entry-0-only allocation shape is all that is evidenced.

Methods: 

- `*(this+0x4)+0x00000000` `void* (*)(void*, int, int) allocate_entry` (read, DERIVED)

### PackedSIMDMath

Stateless packed floating-point math collection (SSE and 3DNow!/MMX): quaternion/rotation conversions, axis-angle decoding, vector normalization, multi-quaternion composition and a 4x4 determinant. Straight-line bodies over global constant tables (0x5AF918-0x5B06E0, 0x5D8CB0-0x5D8D20, 0x8D6270-0x8D6298); no owning object state, no object fields.

Methods: `0x00520C0E`, `0x00520CE0`, `0x00521895`, `0x005219E1`, `0x0052266C`, `0x0052278B`, `0x00522A13`


### ResourceStateStruct

Resource-state struct processed by the reset callback: a type/state field at +0x0 dispatching type-specific handlers for values 4/5/6, a dispatch argument at +0x4, a source value at +0x28 mirrored into tracking slots +0x30/+0x34, state fields +0x1C/+0x20 cleared on reset, and a final callback pointer at +0x38 with its result stored at +0x3C. The companion a2 argument is an untyped callback-table holder (handler at a2+36/+40, result slot a2+48).

Methods: `0x0052765A`

- `this+0x00000000` `int type_state_field` (read_write, DERIVED)
- `this+0x00000004` `void* dispatch_argument` (read, DERIVED)
- `this+0x0000000C` `void* handler_argument` (read, DERIVED)
- `this+0x0000001C` `int cleared_state_field_a` (write, DERIVED)
- `this+0x00000020` `int cleared_state_field_b` (write, DERIVED)
- `this+0x00000028` `int source_value` (read, DERIVED)
- `this+0x00000030` `int tracking_slot_a` (write, DERIVED)
- `this+0x00000034` `int tracking_slot_b` (write, DERIVED)
- `this+0x00000038` `int (*)(int, int, int) final_callback_ptr` (read, DERIVED)
- `this+0x0000003C` `int final_callback_result` (write, DERIVED)

## Compatibility contracts

- **CodecProcessingSlot** — A caller configuring a codec/processing mode writes a function pointer into the sub-buffer slot at (this+0x1A4)+4 (flattened this+0x1A8). Installed handlers include ChecksumComputeType03Stream, TableWeightedMix, ChecksumComputeType1, AudioSynthesis3ChannelSampleGenerator and PixelDataConvolutionViaLookupTable; a replacement must install a compatible handler and invoke it with the owning object as the first argument.
- **AllocatorVtableShape** — The object at this+0x4 is a vtable whose entry 0 is an allocator invoked with (owner, 1, size[, mode]) and returning a writable buffer or sub-object. Replacements must provide this entry-0 allocate shape and keep the returned pointer live while the codec functions use it.
- **SubBufferContextLayout** — The context object at this+0x1A4 carries component/descriptor and phase-table state across +0x18..+0x3C and per-entry table slots at +0x34. The layout overlaps between functions and is not proven; a replacement relying on these offsets must verify them against the specific consumer.
- **StatusAndErrorCodeSlots** — Codec/processing objects report status through the object's +0x14 (status/error code) and +0x18 (count/bound) fields before a virtual dispatch. Observed codes: 47 (unknown mode), 54/56 with clamps 4/256 (bounds), 93/94 (image-fill status). A replacement must preserve these observable writes.

## Unresolved

- The packet folds the allocated child (stored at this+0x1A4) and the object referenced via this+0x0 under one 'obj' base; whether they are the same object is unconfirmed, so CodecObject and CodecSubBuffer are proposed as separate classes.
- CodecSubBuffer layout conflicts: context+0x34 is per-entry table-slot storage in PerIndexTableGenerationWithDivision but a phase-table base in GenerateThreeChannelTableSamples; context+0x20 is both the descriptor-array base and a component offset read through context+0x18. Neither interpretation is reconciled.
- this+0xC is declared by the facts for ImageBufferStrideFill and GeneratePerChannelTable but does not appear in their decompiled bodies; it is only a real field access in ResourceStateResetCallback.
- The per-channel stride array location differs between the packet naming (this+0x1C4 = context+0x20) and the raw source of GeneratePerChannelTable (context +32); not reconciled.
- LEGACY ABI names (ImageBufferStrideFill, Audio_Waveform_Table_Generator, Pixel_Data_Convolution_via_Lookup_Table, Codec_Mode_Select, TriangleClosestPointOrNormal, Normalize3DAudioListenerOrientation, ResourceStateResetCallback) are unverified; TriangleClosestPointOrNormal directly contradicts the observed rotation-matrix-to-axis-angle algorithm and the packet keeps the canonical name only.
- Codec mode/selector semantics (0/1/2 vs >=3) and the distinction between ChecksumComputeType03Stream and ChecksumComputeType1 are unknown beyond the observed dispatch; resource state values 4/5/6 are unknown beyond their handler dispatch.
- Contents of the packed/float constant globals (0x5AF918-0x5B06E0, 0x5D8CB0-0x5D8D20, 0x8D6270-0x8D6298) and the dword_8D6270 LUT are not decoded by the packet.
- The a2 argument of ResourceStateResetCallback is an untyped callback-table holder (handler at a2+36/+40, result slot a2+48); its class is unknown.
- Output-buffer allocation size policy is not visible; the 88-byte sub-object factory allocation in ObjectSetupWithBoundsCheck (literal parameters 1, 88) is unexplained.
- The source-array layout behind a2 of PixelDataConvolutionViaLookupTable is caller-defined and not recoverable from this function alone.
- The indirect vtable call at obj+0x4 in ImageBufferStrideFill and the virtual error handler on the mode>=3 path of CodecModeSelect have no identified callee targets.
- The obj+0x8 (nullsub_4), obj+0xC (VirtualCallWithIntegerSet), obj+0x34 and obj+0x44 handler/zeroed slots installed by ObjectSetupWithBoundsCheck are grounded in raw source and globals 0x0051DFCA/0x0051EB5A only; they have no allowed field evidence refs and are therefore not proposed as class fields.
- Matrix row-major/column-major layouts, the quaternion component layout for SSEReciprocalSquareRootWithNewtonRaphsonQuaterni, and the exact 4x4 element arrangement for F_4ElementDeterminant are not determined.
