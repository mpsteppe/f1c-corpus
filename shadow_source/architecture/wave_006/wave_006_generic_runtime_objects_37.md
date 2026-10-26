# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Proposes DERIVED grouping of fifteen infrastructure functions into nine small classes on a shared unknown-object runtime layer. All owner classes in the packet are UNKNOWN; the groupings below are structural proposals (field-offset and call-shape based), not recovered source types. The buffer pair, the two streambuf counter-pair families, the destructor thunks, the exception path, and the entry-point plugin bootstrap are the main clusters. Uncertain structure is left in unresolved rather than forced into a single clean design.

## Function roles

- `0x005992EF` **GrowableByteBuffer** — Growable-buffer append: validates overflow and region, fills append-length bytes with the fill value, advances the size, null-terminates, returns this
- `0x00599465` **StreambufReadState** — Streambuf putback: increment remaining count, decrement byte position counter, return decremented position
- `0x00599475` **StreambufReadState** — MSVC streambuf get-pointer increment (gninc): pre-decrement remaining count, return byte at read pointer, post-increment pointer
- `0x00599485` **WideStreamBufferState** — Paired-counter consume: pre-decrement remaining count, post-increment position counter, return previous position
- `0x00599534` **GrowableByteBuffer** — Buffer boundary marker check and set: validate marker byte at data[-1] when non-sentinel, re-arm 0xFF sentinel, return prior marker
- `0x005998E5` **BasicOStreamBaseCtor** — Constructor vtable fixup for std::basic_ostream base: read vcall offset from vtable slot 1, install ostream vftable, tail-jump to constructor continuation
- `0x0059A352` **ScalarDeletingDestructor** — This-adjusting scalar-deleting destructor thunk: adjust a1 by -8, run VTable fixup, conditionally free adjusted object, return it
- `0x0059A407` **StreambufReadState** — Wide putback: increment remaining count, step byte position back by two (one wide char), return adjusted position
- `0x0059A418` **StreambufReadState** — Wide get increment (gninc): decrement remaining count, read byte position, advance by two, return pre-adjustment position
- `0x0059A43C` **WideStreamBufferState** — Wide character consume: decrement remaining count, read char through position pointer, advance pointer by two, return char
- `0x0059AC46` **ScalarDeletingDestructor** — std::locale::facet destructor: reset vftable to facet vftable, conditionally free via FreeWrapper on flag bit, return this
- `0x0059B3B0` **SurfaceReallocAssign** — Surface copy-assign with realloc: reallocate pixel and clip-rect arrays when capacities fall short, then copy data, clip rects and scalar fields
- `0x0059BFC3` **ExceptionRaiseHelper** — Structured-exception raise from copied 8-dword template: overwrite slots 6-7 with params, RaiseException from template code/flags/count/argptr
- `0x0059CAA0` **SEHUnwindCleanupStub** — SEH unwind cleanup stub: forward to EmptyStub_aa60(), return nothing
- `0x008D8000` **ProgramEntryPoint** — Program entry: allocate working buffer, load and cache oph.dll / steeringwheel.dll exports, resolve IsDebuggerPresent probe, run main entry when no debugger

## Proposed classes

### GrowableByteBuffer

Growable byte buffer whose heap data block lives at this+0x4, with a size/end field at this+0x8 and a sentinel marker byte immediately before the data block; supports length-fill append with overflow and region validation, and boundary-marker check-and-rewrite.

Methods: `0x005992EF`, `0x00599534`

- `this+0x00000004` `pointer to heap byte buffer data_ptr` (read_write, DERIVED)
- `this+0x00000008` `dword size / buffer end pointer size_or_end_ptr` (read_write, GUESS)

### StreambufReadState

MSVC streambuf-style read state: this+0x1C holds a pointer to the current byte position and this+0x2C a pointer to the remaining-count dword. Byte (step 1) and wide (step 2) get/putback helpers operate on the same offset pair.

Methods: `0x00599465`, `0x00599475`, `0x0059A407`, `0x0059A418`

- `this+0x0000001C` `pointer to byte position counter read_position_ptr` (read_write, DERIVED)
- `this+0x0000002C` `pointer to dword counter remaining_count_ptr` (read_write, DERIVED)
- `*(this+0x1C)+0x00000000` `dword byte position counter position_counter` (read_write, GUESS)
- `*(this+0x2C)+0x00000000` `dword counter remaining_count` (read_write, GUESS)

### WideStreamBufferState

Wide-character stream buffer counter pair: this+0x20 points at the current position (dword counter or wide position pointer) and this+0x30 points at the remaining-count dword; consume/putback helpers step by two bytes per character.

Methods: `0x00599485`, `0x0059A43C`

- `this+0x00000020` `pointer to dword counter / wide position pointer position_field_ptr` (read_write, GUESS)
- `this+0x00000030` `pointer to dword counter remaining_count_ptr` (read_write, DERIVED)
- `*(this+0x20)+0x00000000` `dword counter position_counter` (read_write, GUESS)
- `*(this+0x30)+0x00000000` `dword counter remaining_count` (read_write, GUESS)

### BasicOStreamBaseCtor

Constructor-time vtable fixup for a std::basic_ostream base subobject: reads a vcall offset from vtable slot 1 and installs the basic_ostream<unsigned short> vftable at this+offset, then tail-jumps into the rest of the constructor chain.

Methods: `0x005998E5`

- `this+0x00000000` `vtable pointer vftable_ptr` (read_write, DERIVED)
- `obj+0x00000004` `dword vcall/base-class offset vcall_offset` (read, DERIVED)

### ScalarDeletingDestructor

Compiler-generated destructor helpers that reset or maintain the vftable and conditionally free the object through FreeWrapper_7bcf when the deleting-destructor flag bit is set; includes the this-adjusting thunk (a1-8) for a multiply-inherited base.

Methods: `0x0059A352`, `0x0059AC46`

- `this+0x00000000` `vtable pointer vftable_ptr` (read_write, GUESS)

### SurfaceReallocAssign

Copy-assign for a surface-like object: reallocate the pixel buffer and clip-rect array when the source's capacities are larger, zero the fresh clip-rect array, then copy pixel data, clip-rect data and scalar fields verbatim.

Methods: `0x0059B3B0`

- `this+0x00000000` `pointer to pixel data block pixel_buffer_ptr` (read_write, DERIVED)
- `this+0x00000004` `dword byte capacity pixel_capacity` (read_write, DERIVED)
- `this+0x00000008` `pointer to clip-rect array clip_rect_array_ptr` (read_write, DERIVED)
- `this+0x0000000C` `dword element count capacity clip_rect_capacity` (read_write, DERIVED)
- `this+0x00000010` `dword scalar, role unknown scalar_field` (read_write, UNKNOWN)
- `this+0x00000014` `dword used element count clip_rect_used_count` (read_write, DERIVED)
- `this+0x00000018` `dword surface width width` (read_write, GUESS)
- `this+0x0000001C` `dword surface height height` (read_write, GUESS)

### ExceptionRaiseHelper

Raises a structured exception by copying an 8-dword template from unk_5B9DE0, overwriting template slots 6-7 with the two caller parameters, and calling RaiseException with the template's code, flags, argument count and argument pointer.

Methods: `0x0059BFC3`


### SEHUnwindCleanupStub

Dedicated SEH unwind cleanup target that only forwards to EmptyStub_aa60(); exists so the structured-exception unwind path has a distinct call target with no other work.

Methods: `0x0059CAA0`


### ProgramEntryPoint

Program entry point: allocates the global working buffer, loads and initializes the oph.dll and steeringwheel.dll plugins (caching their exports in globals and invoking start routines), resolves IsDebuggerPresent, and runs the main application entry when no debugger is detected.

Methods: `0x008D8000`


## Compatibility contracts

- **PluginModuleExportContract** — Startup loads oph.dll and steeringwheel.dll by name via LoadLibraryA, resolves their start/port/ip exports with GetProcAddress, caches the results in globals 0x5C7520-0x5C7538, and invokes the start routine. A replacement must preserve the export names and the cache layout to keep the plugin ABI compatible. Export-name strings are inferred from globals only.
- **StructuredExceptionTemplateContract** — Raises a structured exception by copying the 8-dword template at unk_5B9DE0, overwriting slots 6-7 with caller parameters, and calling RaiseException with the template's exception code, flags, argument count and argument pointer. A replacement must reproduce the template layout and the RaiseException argument mapping.
- **FreeOnDeleteContract** — Destructor helpers and the surface copy-assign path release heap blocks through the single FreeWrapper_7bcf callee (0x00587BCF), paired with OperatorNewNhMallocWrapper (0x00587C03) for allocation. A replacement must keep the allocation/free pairing on the same callee surface.

## Unresolved

- All packet owner objects are UnknownObject; the class groupings here are structural proposals, not recovered source types.
- GrowableByteBuffer +0x8 is a size in 0x005992EF but is passed as the pointer argument to sub_599560 in 0x00599534; its exact role (size vs end pointer) is ambiguous.
- The 0 second argument to sub_599560 and the meaning of its non-zero return are unknown for both buffer functions.
- Global dword_5B9C38 is read by BufferAppendWithMemset but does not appear in its raw source text.
- sub_58BB10 is treated as a memset-like fill from its argument shape; its exact contract is unverified.
- StreambufReadState this+0x1C is a byte read pointer in 0x00599475 but a pointer to a byte-position dword in 0x00599465/0x0059A407/0x0059A418; equal offsets on related this pointers do not prove identical field semantics.
- WideStreamBufferState this+0x20 is a pointer to a dword counter in 0x00599485 (incrementing the value) but a wide position pointer advanced by 2 in 0x0059A43C; the two interpretations conflict and the owner is unproven.
- PointerOffsetAdjuster (0x0059A407) and StdGninc (0x0059A418) are prelabeled as a cluster copy; identical instruction shape is not proof of identical object semantics.
- The tail-jump target 0x599BE5 of VTableSetSubCall continues the constructor chain outside this packet.
- DestructorConditionalFree reads stack slots v6/v7/v8 uninitialized and its a2 argument meaning is unknown; no callers are recorded.
- StdLocaleFacetDestructor's FreeWrapper_7bcf allocation/free pairing and its caller chain are not evidenced.
- SurfaceReallocAssign scalar field +0x10 role is unknown; pixel format and clip-rect element layout are inferred from copy sizes only.
- SEHUnwindCallFUN0047aa60Cleanup's guarded scope and why its body is an empty stub are unknown.
- start's dword_5C7530 working-buffer ownership and the oph.dll / steeringwheel.dll export contracts are unproven; sub_58A19E is referenced by name only.
- CxxThrowException8's template-slot-to-parameter mapping (which slots are code/flags/count/argptr) is inferred from RaiseException argument order.
