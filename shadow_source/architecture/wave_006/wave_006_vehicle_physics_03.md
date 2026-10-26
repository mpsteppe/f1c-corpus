# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

Twenty-two validated functions proposed as seven GUESS classes. TireSystem groups tire physics state initialization (0x004F6F20) and per-tire configuration loading (0x004F70C0) over two 45-slot tire buffers at +0x694/+0x6D8. VehicleDataBuffer (0x00500190) resets a 0x1B0-byte data region and writes a negative-FLT_MAX sentinel. VehicleFrameContext (0x00516F55, 0x0051BFA6, 0x0051CD3E, 0x0051D80A, 0x0051DFA8, 0x0051E0CD) covers per-vehicle frame/render-buffer setup, step-counter increment, physics sub-object state propagation and a dirty-flag handshake on a shared render context. TextureAudioBufferTransform (0x0051378B) and PngDecodeContext (0x0051389E) are image/audio buffer transform clusters sharing the +0x60 flags and format-byte +0x116 pattern. VertexColorTransformContext (0x00507BC5, 0x005084F5, 0x005085C5, 0x005093F9) groups four per-vertex color-packing transforms that share the format-conversion flag at +0x1048, the vertex-data base at +0x2C, the vertex count at +0x1058, DirectXVertexBufferFormatConversion (0x00506CE2) and the returned conversion-state global 0x008B009C. Matrix4x4TransformBuilder (0x0050D9A5, 0x0050E9E6, 0x0050EE0B, 0x0050F0BF, 0x0050F199, 0x00522952, 0x005229B5) groups seven 4x4 matrix builders over a caller-provided output buffer. Every function owner is UNKNOWN in the packet; every class here is a GUESS grouping, and the decompiler-relative 'this' bases used for fields in different classes are not asserted to be the same object.

## Function roles

- `0x004F6F20` **TireSystem** — Tire physics state initializer: zeroes the leading scalar fields and two sub-structs via StructZeroInit helpers, runs a 45-iteration StructZeroInit_6f00 loop over a stride-32-dword sub-struct array, zeroes trailing fields including the slot buffers at +0x694/+0x6D8, and sets the float at +0xA0 to 1.0f. Invoked by the tire system constructor at 0x004E4500.
- `0x004F70C0` **TireSystem** — Loads and initializes per-tire configuration: allocates the 180-byte buffers at +0x694/+0x6D8 when absent, fills two 45-slot stacks from the global tire config tables, once pre-resolves the season sound directory, dispatches a conditional config entry and a season-entry handler, resolves each slot via switch/color-palette/string-match, writes reciprocal blend factors into the resolved records, frees temporary strings and returns 1 when the buffers were already allocated.
- `0x00500190` **VehicleDataBuffer** — Clears a 0x1B0-byte vehicle data buffer at this+110 floats (offset +0x1B8) to zero via memset, writes the -9.9999997e37 sentinel at this+111 floats (offset +0x1BC), and returns 0. Used during list-iteration reset by the caller at 0x004B5380.
- `0x00507BC5` **VertexColorTransformContext** — Transforms floating-point vertex colors into packed 16-bit RGB565 words: optional DirectX vertex-buffer format conversion when the flag at +0x1048 is set, per-vertex R/B scaled by 31.0 and G by 63.0, packed as (R<<11)|(G<<5)|B. Returns the global conversion state 0x008B009C.
- `0x005084F5` **VertexColorTransformContext** — Converts two float color channels per vertex into a packed 32-bit word with two 16-bit channels scaled by 65535.0; optional DirectX vertex-buffer format conversion on the flag at +0x1048. Returns the global conversion state 0x008B009C.
- `0x005085C5` **VertexColorTransformContext** — Per-vertex color transform scanning a 256-entry table anchored 14 dwords into this, keeping the last index where an FPU condition held, then emitting a 16-bit word combining that index with a per-vertex alpha value; optional DirectX vertex-buffer format conversion on the flag at +0x1048. Returns 0x008B009C. Low confidence on the scan condition because the FPU flag registers are never assigned in the decompiled text.
- `0x005093F9` **VertexColorTransformContext** — Per-vertex channel transform: after optional DirectX vertex-buffer format conversion and a per-sub-tile offset calculation, scales three float channels (B at +8, G at +4, R at 0, 16-byte stride) by 65535.0 and writes three consecutive 16-bit words per vertex. Returns 0x008B009C. Structural twin of 0x005084F5 despite the screen-coordinate ABI name.
- `0x0050D9A5` **Matrix4x4TransformBuilder** — Builds a 4x4 affine matrix in a 16-float output buffer: zeros the off-diagonal and translation-row entries, sets the diagonal scale to a2 and the homogeneous element to 1.0, and when the flag a4 is set applies an indirect transform thunk with optional offset-vector subtract/add-back; an optional a5 vector is added to the translation row. Returns the matrix pointer.
- `0x0050E9E6` **Matrix4x4TransformBuilder** — Transforms three color components through a flag-selected transform pipeline: a switch on the presence of flags a4/a5/a6 selects whether a conditional thunk runs zero, once or twice, an unconditional thunk always runs, and optional blend data a3 applies per-channel offset/scale blend. Returns the transformed color vector.
- `0x0050EE0B` **Matrix4x4TransformBuilder** — Builds a 4x4 transformation matrix for a skeleton bone: with a parent transform copies the parent diagonal scale (root mode) or negates an offset into the translation column and applies transform thunks (child mode); without a parent emits identity; an optional translate modifier subtracts/re-adds an offset around a thunk call; an optional final offset is added to the translation column.
- `0x0050F0BF` **Matrix4x4TransformBuilder** — Builds a 4x4 reflection/householder-style matrix: a thunk at 0x0050E3DA supplies four coefficients, the function forms the outer-product matrix with the dot product added on the diagonal, and returns the output matrix pointer.
- `0x0050F199` **Matrix4x4TransformBuilder** — Builds a 4x4 column-major transformation matrix from four parameters produced by a preliminary thunk call at 0x0050E3DA: rotation sub-block from quadratic products of the first three, translation row from doubled negative products scaled by the fourth, final row [0,0,0,1]. Returns the input matrix pointer unchanged.
- `0x0051378B` **TextureAudioBufferTransform** — Two-pass texture/audio data transformation on a shared buffer: pass 1 (gated by a bitmask from the address of global 0x00602000 against flags at +0x60) regenerates engine-sound wave tables then remaps RGB bytes at +0x104 through a lookup table at +0x138; pass 2 (flags bit 3 and format byte 3) right-shifts channels by 8 minus amplitude bytes at +0x150/+0x151/+0x152. Invoked by the audio buffer size calculator at 0x0051868C.
- `0x0051389E` **PngDecodeContext** — Applies the PNG row-transform pipeline to one decoded image row: gated by the transform-flag bytes at +0x60/+0x61 it sequentially invokes decompression, palette, expansion, dithering, background, unpacking, swapping and inversion subroutines, with two fatal longjmp guards (null row buffer at +0xDC, zero rowbytes output at +0xF4). Single caller at 0x00511B7C.
- `0x00516F55` **VehicleFrameContext** — Loads the step-counter sub-object from this+0x17C; when the flags byte at +0x4A is non-zero dispatches a virtual call through the function table at this+0x1A4 entry +8; unconditionally increments the step counter at *(this+0x17C)+0xC by one; returns the virtual-call result or this.
- `0x0051BFA6` **VehicleFrameContext** — Unconditional field-level copy: loads the target sub-struct pointer from this+0x19C, copies values from this+0x110 and this+0x60 into its fields at +0x5C and +0x60 (this+0x1F8 / this+0x1FC), and returns the value read from this+0x60.
- `0x0051CD3E` **VehicleFrameContext** — Loads the sub-object pointer at this+0x19C, clears its byte flag at +0x24 to 0, copies the dword at this+0x60 into its +0x2C, and returns the sub-object pointer.
- `0x0051D80A` **VehicleFrameContext** — Sets up a vehicle render buffer: allocates a bounding-box/region array through the allocator vtable at this+0x4, initializes it to full grid bounds, tightens it via a grid-occupancy scan, subdivides it into regions, computes weighted centroids, writes the region count to this+0x70, sets status 95 and the region count through the object vtable, and returns the result of a final vtable call.
- `0x0051DFA8` **VehicleFrameContext** — Per-vehicle render-buffer setup: reads the context pointer from this+0x1A4, copies the value at context+0x10 into this+0x74, calls VehicleRenderBufferSetup (0x0051D80A) with the value at context+0x14, sets the byte at context+0x1C to 1, and returns the setup result.
- `0x0051E0CD` **VehicleFrameContext** — Reads the context pointer from this+0x1A4, unconditionally sets the byte at context+0x1C to 1, and returns the context pointer; a dirty/render-refresh flag per the existing-analysis prose, not proven live.
- `0x00522952` **Matrix4x4TransformBuilder** — Builds a 4x4 transformation matrix from an angle parameter using 3DNow!/MMX packed arithmetic: the angle is expanded by a packed-math helper, distributed across eight matrix slots with identity, zero and homogeneous rows, then MMX state is reset. Returns the output pointer.
- `0x005229B5` **Matrix4x4TransformBuilder** — Builds a symmetric 4x4 transformation matrix from a packed parameter using 3DNow!/MMX: the low dword appears symmetrically, the high dword and its negation on the other axis, with identity and zero rows; MMX state is cleared on entry and exit. Returns the output pointer.

## Proposed classes

### TireSystem

Tire physics configuration state. Two 180-byte slot buffers at +0x694/+0x6D8 hold 45 dwords each resolved into per-tire float records. TireStateStructInit (0x004F6F20) zeroes the leading scalar region and the slot buffers and sets the blend default float at +0xA0 to 1.0f; TireConfigLoadAndInit (0x004F70C0) allocates the buffers when absent, fills 45-slot stacks from the global tire config tables, once pre-resolves the season sound directory, and resolves each slot with reciprocal blend factors. Ownership UNKNOWN in the packet; grouping GUESS.

Methods: `0x004F6F20`, `0x004F70C0`

- `this+0x00000000` `dword scalar_00` (read_write, GUESS)
- `this+0x00000004` `byte byte_04` (write, GUESS)
- `this+0x00000008` `dword scalar_08` (write, GUESS)
- `this+0x0000000C` `dword scalar_0C` (write, GUESS)
- `this+0x00000010` `dword scalar_10` (write, GUESS)
- `this+0x00000014` `dword scalar_14` (write, GUESS)
- `this+0x00000018` `dword scalar_18` (write, GUESS)
- `this+0x0000001C` `dword scalar_1C` (write, GUESS)
- `this+0x00000044` `dword scalar_44` (write, GUESS)
- `this+0x00000048` `dword scalar_48` (write, GUESS)
- `this+0x0000004C` `dword scalar_4C` (write, GUESS)
- `this+0x00000058` `dword scalar_58` (write, GUESS)
- `this+0x00000080` `dword scalar_80` (write, GUESS)
- `this+0x00000084` `dword scalar_84` (write, GUESS)
- `this+0x00000088` `dword scalar_88` (write, GUESS)
- `this+0x0000008C` `dword scalar_8C` (write, GUESS)
- `this+0x00000090` `dword scalar_90` (write, GUESS)
- `this+0x00000094` `dword scalar_94` (write, GUESS)
- `this+0x00000098` `byte byte_98` (write, GUESS)
- `this+0x0000009C` `dword scalar_9C` (write, GUESS)
- `this+0x000000A0` `float blend_default_one` (write, GUESS)
- `this+0x000000A4` `dword scalar_A4` (write, GUESS)
- `this+0x000000A8` `dword scalar_A8` (write, GUESS)
- `this+0x000000AC` `dword scalar_AC` (write, GUESS)
- `this+0x000000B0` `dword scalar_B0` (write, GUESS)
- `this+0x00000694` `dword_array tire_slot_buffer_a` (read_write, DERIVED)
- `this+0x000006D8` `dword_array tire_slot_buffer_b` (read_write, DERIVED)

### VehicleDataBuffer

Reset of a per-object vehicle data buffer: VehicleDataBufferClear (0x00500190) zero-fills the 0x1B0-byte region at +0x1B8 and writes the -9.9999997e37 sentinel at +0x1BC to mark reset during list-iteration. Ownership UNKNOWN; grouping GUESS.

Methods: `0x00500190`

- `this+0x000001BC` `float reset_sentinel` (write, DERIVED)

### VehicleFrameContext

Per-vehicle frame/render context. Holds the render context pointer at +0x1A4, a physics/vehicle sub-object pointer at +0x19C and a step-counter sub-object pointer at +0x17C. VehicleUpdateFrameSetup (0x0051DFA8) and SetVehicleDirtyFlag (0x0051E0CD) drive the dirty flag at *(this+0x1A4)+0x1C; IncrementPhysicsStepCounter (0x00516F55) increments the step counter at *(this+0x17C)+0xC and optionally dispatches a virtual call; CopyDimensionsToTarget (0x0051BFA6) and PhysicsObjectStateSetter (0x0051CD3E) propagate values into the sub-object; VehicleRenderBufferSetup (0x0051D80A) allocates and subdivides a grid-region array. Ownership UNKNOWN; grouping GUESS. The decompiler-relative 'this' base is not asserted to be shared with other classes' 'this'.

Methods: `0x00516F55`, `0x0051BFA6`, `0x0051CD3E`, `0x0051D80A`, `0x0051DFA8`, `0x0051E0CD`

- `this+0x00000004` `pointer allocator_vtable_ptr` (read, GUESS)
- `this+0x0000004A` `byte dispatch_flag` (read, GUESS)
- `this+0x00000060` `dword shared_value` (read, GUESS)
- `this+0x00000070` `dword region_count` (write, GUESS)
- `this+0x00000074` `dword working_slot` (write, GUESS)
- `this+0x00000110` `dword dimension_source` (read, GUESS)
- `this+0x0000017C` `pointer step_counter_obj_ptr` (read, GUESS)
- `this+0x0000019C` `pointer physics_subobject_ptr` (read, GUESS)
- `this+0x000001A4` `pointer render_context_ptr` (read, GUESS)
- `this+0x000001F8` `dword target_slot_1F8` (write, GUESS)
- `this+0x000001FC` `dword target_slot_1FC` (write, GUESS)
- `*(this+0x17C)+0x0000000C` `dword step_counter` (write, GUESS)
- `*(this+0x19C)+0x00000024` `byte state_flag` (write, GUESS)
- `*(this+0x19C)+0x0000002C` `dword state_value` (write, GUESS)
- `*(this+0x1A4)+0x00000008` `dword vtable_slot_8` (read, GUESS)
- `*(this+0x1A4)+0x00000010` `dword context_value_10` (read, GUESS)
- `*(this+0x1A4)+0x00000014` `dword context_value_14` (read, GUESS)
- `*(this+0x1A4)+0x0000001C` `byte dirty_flag` (write, GUESS)
- `*(this+0x4)+0x00000000` `dword allocator_alloc` (read, GUESS)
- `obj+0x00000004` `dword vtable_entry_1` (read, GUESS)
- `obj+0x00000014` `dword status_code` (write, GUESS)
- `obj+0x00000018` `dword region_count_slot` (write, GUESS)

### VertexColorTransformContext

Per-vertex color packing. Four transforms share the vertex-data base at +0x2C, the format-conversion flag at +0x1048, the vertex count at +0x1058, the optional DirectXVertexBufferFormatConversion (0x00506CE2) pre-pass, the utility call (0x00507473), and the returned global conversion-state 0x008B009C. Variants pack RGB565 (0x00507BC5), two 16-bit channels per word (0x005084F5), index/alpha words from a 256-entry table (0x005085C5), and three 16-bit channel words (0x005093F9). Ownership UNKNOWN; grouping GUESS.

Methods: `0x00507BC5`, `0x005084F5`, `0x005085C5`, `0x005093F9`

- `this+0x0000002C` `pointer vertex_data_base` (read, GUESS)
- `this+0x00001048` `dword format_conversion_flag` (read, GUESS)
- `this+0x00001058` `dword vertex_count` (read, GUESS)

### TextureAudioBufferTransform

Two-pass transform over a shared buffer for texture/audio data. Pass 1 (gated by a bitmask derived from the address of global 0x00602000 against flags at +0x60) regenerates engine-sound wave tables via EngineSoundWaveTableGenerator (0x00513482) then remaps RGB bytes at +0x104 through the lookup table at +0x138; pass 2 (flags bit 3 at +0x60 and format byte 3 at +0x116) right-shifts channels by 8 minus the amplitude bytes at +0x150/+0x151/+0x152. Ownership UNKNOWN; grouping GUESS. The +0x60/+0x116 pattern is shared with PngDecodeContext but common ownership is not proven.

Methods: `0x0051378B`

- `this+0x00000060` `dword transform_flags` (read, GUESS)
- `this+0x00000104` `pointer data_buffer_ptr` (read, GUESS)
- `this+0x00000108` `word pixel_count` (read, GUESS)
- `this+0x00000116` `byte format_code` (read, GUESS)
- `this+0x00000138` `pointer lookup_table_ptr` (read, GUESS)
- `this+0x00000150` `byte amplitude_red` (read, GUESS)
- `this+0x00000151` `byte amplitude_green` (read, GUESS)
- `this+0x00000152` `byte amplitude_blue` (read, GUESS)
- `*(this+0x104)+0x00000002` `byte first_pixel_blue` (write, GUESS)

### PngDecodeContext

PNG decode/transform context. PNGRowTransformPipeline (0x0051389E) applies the per-row PNG transform chain gated by the transform-flag bytes at +0x60/+0x61, with fatal longjmp guards on a null row buffer (+0xDC) and a zero rowbytes output (+0xF4). Accessed fields cover color type (+0xF8), pixel buffer (+0x104), palette (+0x138), bit depth (+0x11E) and row width (+0x10A). Ownership UNKNOWN; grouping GUESS. The +0x60/+0x116 pattern is shared with TextureAudioBufferTransform but common ownership is not proven.

Methods: `0x0051389E`

- `this+0x0000005C` `dword width` (read, GUESS)
- `this+0x00000060` `byte transform_flags_low` (read, GUESS)
- `this+0x00000061` `byte transform_flags_high` (read, GUESS)
- `this+0x000000DC` `pointer row_buffer_ptr` (read, GUESS)
- `this+0x000000F4` `dword rowbytes_out` (read, GUESS)
- `this+0x000000F8` `byte color_type` (read, GUESS)
- `this+0x00000104` `pointer pixel_buffer_ptr` (read, GUESS)
- `this+0x0000010A` `word row_width` (read, GUESS)
- `this+0x00000116` `byte format_code` (read, GUESS)
- `this+0x0000011E` `byte bit_depth` (read, GUESS)
- `this+0x0000012C` `pointer param_12C` (read, GUESS)
- `this+0x00000138` `pointer palette_ptr` (read, GUESS)
- `this+0x00000144` `dword param_144` (read, GUESS)
- `this+0x0000015C` `pointer param_15C` (read, GUESS)
- `this+0x00000174` `pointer param_174` (read, GUESS)
- `this+0x00000178` `pointer param_178` (read, GUESS)

### Matrix4x4TransformBuilder

Free 4x4 transformation-matrix construction over a caller-provided 16-float output buffer: scaled affine setup (0x0050D9A5), flag-selected color transform with blend (0x0050E9E6), parent/child bone transform (0x0050EE0B), reflection matrix (0x0050F0BF), quaternion-derived transform (0x0050F199), and two 3DNow!/MMX packed builders (0x00522952, 0x005229B5). All rely on indirect transform thunks (0x0050CBB0, 0x0050D857, 0x0050CDF9, 0x0050E3DA) or packed-math setup (0x005295E0) whose targets are unresolved. The matrix is a parameter buffer, not a class member, so no fields are declared. Ownership UNKNOWN; grouping GUESS.

Methods: `0x0050D9A5`, `0x0050E9E6`, `0x0050EE0B`, `0x0050F0BF`, `0x0050F199`, `0x00522952`, `0x005229B5`


## Compatibility contracts

- **TireConfigReentrancyContract** — TireConfigLoadAndInit (0x004F70C0) returns 1 when the 180-byte buffers at +0x694 and +0x6D8 are already allocated (skip path) and 0 otherwise; a replacement must preserve this guard so repeated loads are idempotent.
- **TireSlotBlendLayout** — Each of the 45 dwords at +0x694 and +0x6D8 is resolved to a per-tire float record whose indexes 7, 8 and 9 hold the blend scale, 1 minus scale times offset, and the color index respectively; the reciprocal-based computation depends on the global 1.0 constants. Record layout beyond those three indexes is not evidenced.
- **VehicleDataBufferSentinel** — VehicleDataBufferClear zeroes the 0x1B0-byte region at +0x1B8 then writes the -9.9999997e37 (negative FLT_MAX) sentinel at +0x1BC; consumers of the vehicle data buffer must treat that sentinel as the reset/invalid marker.
- **RenderFrameDirtyFlagHandshake** — VehicleUpdateFrameSetup (0x0051DFA8) and SetVehicleDirtyFlag (0x0051E0CD) both set the byte at *(this+0x1A4)+0x1C to 1; the flag is the render-state refresh marker that the frame-setup path clears. The clearing site is not evidenced here.
- **StepCounterIncrementContract** — Every call to IncrementPhysicsStepCounter (0x00516F55) unconditionally increments the dword at *(this+0x17C)+0xC by one regardless of the virtual dispatch guard; a replacement physics step counter must keep this always-increment behavior.
- **ColorTransformFormatGates** — ColorTransform (0x0051378B) requires the format byte at +0x116 equal to 3 and specific flags bits at +0x60 (bit 3 / 0x8 for pass 2) before transforming; pass-2 shifts are 8 minus the amplitude bytes at +0x150/+0x151/+0x152, clamped to 0 when the difference exceeds 8.
- **PngFatalErrorMessages** — PNGRowTransformPipeline (0x0051389E) aborts via GuardedCallWithLongjmp (0x00511869) with the literals 'NULL row buffer' (0x005AF474) and 'png_do_dither returned rowbytes=0' (0x005AF450) on a null row buffer or a zero rowbytes output.
- **VertexColorPackingScales** — ColorVertexTransform scales R/B by 31.0 and G by 63.0 and packs RGB565; Color565Transform and VertexCoordinateTransformToScreen scale channels by 65535.0 and emit 16-bit channel words; the vertex count at +0x1058 bounds each packing loop.

## Unresolved

- Every function owner is UNKNOWN in the packet; all seven classes and the interface are GUESS groupings, and the decompiler-relative 'this' base reused across classes is not evidence of shared object layout.
- Ambiguous float-constant globals that appear in packet facts but never in the raw decompiled bodies: 0x0059E43C, 0x0059E440, 0x0059E450, 0x0059E7F0, 0x0059EAE0, 0x0059FEC8, 0x0059F120, 0x005AD348, 0x005ADB14. Their exact load sites and roles (blend/scale/reciprocal constants, possibly consumed inside thunk callees) are positional or unconfirmed.
- Global 0x008AC388 has no visible use site in the raw source of TireConfigLoadAndInit; the existing-analysis VehicleFilePathBuffer label is not adopted here.
- The output-buffer pointers in the color transforms (v6/v7 read before any write in the decompiled text) mean the real output destinations are not evidenced.
- Purpose of UtilityFunction_7473 (0x00507473) and meaning of the returned global conversion-state 0x008B009C are unknown.
- In VertexColorTransform (0x005085C5) the FPU condition registers v11/v12 are never assigned, so the 256-entry scan condition and the nearest-index interpretation of the recorded value are inferred; the table anchored 14 dwords into this has an unconfirmed weight/lookup role.
- The ABI name Vertex_Coordinate_Transform_to_Screen (0x005093F9) implies a screen-coordinate transform but the body packs float RGB channels into 16-bit words; the naming mismatch is unresolved.
- In ColorMatrixTransformWithBlend (0x0050E9E6) the a3 blend record semantics and the meaning of the a4/a5/a6 flag combinations are unknown; parameter a2 is unused.
- The targets of the indirect transform thunks (0x0050CBB0, 0x0050CDF9, 0x0050D857, 0x0050E3DA) are unresolved; the geometric meaning of the subtract-before/add-back-after offset pattern is inferred.
- IncrementPhysicsStepCounter's virtual dispatch target is indirect with no static callee; the relationship between the dispatch at this+0x1A4 and the always-incremented counter is not documented.
- VehicleRenderBufferSetup (0x0051D80A) depends on sub_51D57F subdivision and status code 95 written to obj+0x14, neither documented; the bounding-box element layout is heap-local and unverified.
- The unnamed PNG transform-stage callees (sub_512E1A, sub_512ACC, sub_5126D9, sub_5123B3, sub_5123E0) implement individual PNG stages whose exact semantics are not independently confirmed; several pipeline call arguments lack packet field-table entries.
- The 3DNow!/MMX builders (0x00522952, 0x005229B5) have unresolved packed-parameter semantics; the exact contents of the SIMD constant globals 0x005AF950/0x005AF978/0x005AF9C0/0x005AF9C8 are not in the packet.
- TireConfigLoadAndInit reads a field at this+18196 (0x4704) beyond the two documented slot buffers for the conditional config dispatch; that field is outside the allowed evidence set and is not represented here.
