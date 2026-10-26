# RuntimeUtilityShims

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Proposes generic_runtime_objects as a set of lightweight utility shims rather than a cohesive subsystem. Three wrapper families are recognizable by callee: CallbackRegistrationShim (seven functions passing routine addresses through BooleanToIntConversion 0x00587B3E), GlobalAddressPassthrough (three functions forwarding a global address to sub_4B3DB0), and EmptyStubWrapper (three functions calling the unresolved EmptyStub_0170). Four DebugLogLifecycleHook functions share the StringSplitLoop(2, source, n) + guarded DebugLogWrite pattern on the game enter/setup/exit/restart paths. GlobalFlagController groups four single-write flag shims. The remaining functions are single-method accessor/helper stubs on unidentified this objects (texture-dimension validity, string fallback accessor, destructor, bucket-list teardown, flag-field helper, UI string control, input-axis clamp, db-list reset). No cross-function class identity is proven; every grouping is a GUESS grounded in shared callees or shared field layout on the same this base.

## Function roles

- `0x0049A110` **LinkedChildContainer** — child-count traversal: skip up to a2 siblings via node+0x24, then count descendants via node+0x28
- `0x0049A2D0` **StringFallbackAccessor** — string pointer accessor with default-directory fallback on NULL
- `0x0049A990` **VTableDestructorObject** — destructor: install vtable off_5ACAB0 at this+0x0, conditionally free this+0x34, cleanup sub-object at this+9
- `0x0049AC20` **TextureSurfaceObject** — validity check: return true only when both 16-bit dimensions at this+0x28 and this+0x2A are positive
- `0x0049AFA0` **GlobalAddressPassthrough** — forward address of global dword_7CE048 to sub_4B3DB0 and return its result
- `0x0049AFB0` **CallbackRegistrationShim** — cleanup-callback registration: pass (int)CleanupCallbackRegister to BooleanToIntConversion
- `0x0049B060` **CallbackRegistrationShim** — free-callback registration: pass (int)nullsub_95 to BooleanToIntConversion
- `0x0049E8E8` **UnknownObject** — constant byte reader: ignore all five stdcall arguments and return global byte_5E000A4C
- `0x0049EF40` **DebugLogLifecycleHook** — game-enter onscreen debug-log hook: StringSplitLoop(2, path, 2604) then guarded DebugLogWrite
- `0x0049EF70` **DebugLogLifecycleHook** — game-setup onscreen debug-log hook: StringSplitLoop(2, path, 2610) then guarded DebugLogWrite
- `0x0049F120` **DebugLogLifecycleHook** — game-exit onscreen debug-log hook: StringSplitLoop(2, path, 2705) then guarded DebugLogWrite
- `0x0049FFC0` **GlobalAddressPassthrough** — forward address of global unk_7CE24D to sub_4B3DB0 and return its result
- `0x0049FFE0` **EmptyStubWrapper** — empty-stub invocation: call EmptyStub_0170 with no arguments
- `0x004A0010` **CallbackRegistrationShim** — at-exit callback registration: pass (int)nullsub_199 to BooleanToIntConversion
- `0x004A0CB0` **SessionRestartGuard** — restart-menu-mode guard: on four-pass guard call SessionMenuModeSwitch, always return 0
- `0x004A0D90` **GlobalFlagController** — set global byte flag: byte_7CE25C = 1; called from RaceModeSetup
- `0x004A0DB0` **GlobalFlagController** — set global byte flag: byte_7CE25E = 1; called from SessionScoringUpdate
- `0x004A0E68` **GlobalFlagController** — set global byte flag: byte_7CE25F = 1
- `0x004A11B0` **GlobalFlagController** — clear global dword flag: dword_7CE250 = 0; called from Game_Post
- `0x004A11D0` **GlobalAddressPassthrough** — forward address of global unk_7CE2A4 to sub_4B3DB0 and return its result
- `0x004A11E0` **CallbackRegistrationShim** — callback registration: pass (int)NoOpThunk to BooleanToIntConversion
- `0x004A11F0` **EmptyStubWrapper** — no-op thunk: pass address of global unk_7CE2A4 to EmptyStub_0170
- `0x004A1990` **HandleAndStringAccessor** — object-handle reader: store sub_587ECE(a1) into *a2, return constant 4
- `0x004A19D0` **HandleAndStringAccessor** — string compare vs default: *a2 = (strcmp(a1, global 0x005CD12C) != 0), return constant 1
- `0x004A1A00` **CrtStringAppendHelper** — append float: format %.5f (0x005CD130) via StringFormatWithBufferOverflowCheck then strcat; called by ConfigKeyValueWrite
- `0x004A1A60` **CrtStringAppendHelper** — append int: format %d (0x005C3280) via StringFormatWithBufferOverflowCheck then strcat; called by DebugLogFormat
- `0x004A1AC0` **CrtStringAppendHelper** — append 16-bit value as %d (0x005C3280) then strcat; called by UIConfigEntrySerialization
- `0x004A1B20` **CrtStringAppendHelper** — append selected text fragment (0x005CD138 default, 0x005CD12C when *a2==0) then strcat; called by ConfigKeyValueSerialize
- `0x004A1EA0` **UnknownObject** — stdcall wrapper: forward a1 to StringCopyWithBufferRealloc, discard result, return constant 1
- `0x004A1F60` **BucketListContainer** — zero-init four DWORD header fields this+0x0/+0x4/+0x8/+0xC; called by sub_4A4900
- `0x004A1F80` **BucketListContainer** — destroy four singly-linked lists: walk each head via node+0x44, free nodes with FreeWrapper_7bcf; called by sub_4A4900
- `0x004A3FE0` **SoundFlagFieldHelper** — reset fields this+0x78 and this+0x84 to 0; if this+0x64 non-zero call FlagFieldBitManipulation(0,0,1,0); called by PitCrewAnimationMASSetup
- `0x004A4000` **SoundFlagFieldHelper** — set this+0x78 to 1, this+0x84 to 0; if this+0x64 non-null call FlagFieldBitManipulation(1,1,1,0); called by sub_4A00A0
- `0x004A40C0` **CallbackRegistrationShim** — encode callback address: pass (int)nullsub_200 (0x004A40D0) to BooleanToIntConversion
- `0x004A46E4` **UnknownObject** — increment byte accumulator this+0x68 by a2 and clear caller buffer with memset; decompiler sp-warning makes prototype suspect
- `0x004A6FF0` **CallbackRegistrationShim** — encode config-init address: pass (int)AutoLoadConfigFileInit (0x004A7000) to BooleanToIntConversion
- `0x004A7040` **UnknownObject** — write two constant strings (0x005CD6B0 then 0x005C30B4) into buffer a1 via BufferWriteWithStringLengthCheck, return 0
- `0x004B1780` **InputAxisClamp** — input-axis clamp: read this+0x2988, after StateCheckWrapper(dword_7CD25C) pass clamp to [-1,1]; called by sub_4A1830
- `0x004B18D0` **DebugLogLifecycleHook** — game-restart player-file debug-log hook: StringSplitLoop(2, path, 2510) then guarded DebugLogWrite
- `0x004B1BB0` **UiStringControl** — slider clamp: parse a2 via ObjectHandleReader, store at this+0x14, clamp with this+0x1C/this+0x20 bounds
- `0x004B1C70` **UiStringControl** — copy byte this+0x15 into this+0x14 and return the copied byte
- `0x004B1FB0` **UiStringControl** — copy short this+0x16 into this+0x14 and return the copied short
- `0x004B2180` **DbListReset** — reset db list head: dword_7D2E50 = 0, point 0x83EE54/0x83EE58/0x83EE5C at unk_7D2E54, return &dword_7D2E50
- `0x004B2190` **CallbackRegistrationShim** — season-scoring db callback registration: pass (int)SeasonScoringDBCallback (0x004B21A0) to BooleanToIntConversion
- `0x004B21A0` **EmptyStubWrapper** — empty season-scoring db callback stub: body only calls EmptyStub_0170

## Proposed classes

### LinkedChildContainer

Container whose head is this+0x8 and whose traversal descends through child links; provides a skip-and-count operation over sibling and child links.

Methods: `0x0049A110`

- `this+0x00000008` `void* list_head` (read, GUESS)

### LinkedNode

Traversal node reached from the container via *(this+0x30); carries a next-sibling link at +0x24 and a child link at +0x28.

Methods: `0x0049A110`

- `*(*(this+0x30)+0x24)+0x00000024` `void* next_sibling` (read, GUESS)
- `*(this+0x30)+0x00000028` `void* child` (read, GUESS)

### StringFallbackAccessor

Accessor returning the string pointer at this+0x08, falling back to the default-directory constant when it is NULL.

Methods: `0x0049A2D0`

- `this+0x00000008` `char* string_ptr` (read, GUESS)

### VTableDestructorObject

Object with a destructor that installs vtable off_5ACAB0 at this+0x0, conditionally frees this+0x34 and cleans up a sub-object; owning class unknown.

Methods: `0x0049A990`

- `this+0x00000000` `void** vtable_ptr` (write, GUESS)
- `this+0x00000034` `void* conditional_free_ptr` (read, GUESS)

### TextureSurfaceObject

Object exposing two 16-bit texture-surface dimensions at +0x28 and +0x2A; validity is their combined positivity.

Methods: `0x0049AC20`

- `this+0x00000028` `unsigned short surface_dimension_1` (read, GUESS)
- `this+0x0000002A` `unsigned short surface_dimension_2` (read, GUESS)

### CallbackRegistrationShim

Family of thin wrappers that read a routine slot, cast its address to int and pass it to BooleanToIntConversion (0x00587B3E), returning the normalized result. Registration targets are not evidenced in the packet.

Methods: `0x0049AFB0`, `0x0049B060`, `0x004A0010`, `0x004A11E0`, `0x004A40C0`, `0x004A6FF0`, `0x004B2190`


### GlobalAddressPassthrough

Family of trivial wrappers that pass the address of a global (0x007CE048, 0x007CE24D, 0x007CE2A4) to sub_4B3DB0 and return its result unchanged.

Methods: `0x0049AFA0`, `0x0049FFC0`, `0x004A11D0`


### EmptyStubWrapper

Family of stubs whose bodies only call the unresolved EmptyStub_0170, with or without a global address argument.

Methods: `0x0049FFE0`, `0x004A11F0`, `0x004B21A0`


### DebugLogLifecycleHook

Lifecycle debug-log hooks on game enter/setup/exit/restart: run StringSplitLoop(2, source-path, size) as an assertion check and on success write an 'entered onscreen'/'entered playerf' message through DebugLogWrite.

Methods: `0x0049EF40`, `0x0049EF70`, `0x0049F120`, `0x004B18D0`


### GlobalFlagController

Single-write shims over adjacent global flag bytes/dword: sets 0x007CE25C, 0x007CE25E, 0x007CE25F to 1 and clears dword 0x007CE250 to 0 from Game_Post.

Methods: `0x004A0D90`, `0x004A0DB0`, `0x004A0E68`, `0x004A11B0`


### SessionRestartGuard

Guard shim on the session-restart path: when qualifying-DSQ and HUD-disable flags are clear, the session-mode identifier is unset (-1) and the player-vehicle field equals 1, it invokes SessionMenuModeSwitch; always returns 0.

Methods: `0x004A0CB0`


### CrtStringAppendHelper

CRT-style helpers that format a value into a local buffer via StringFormatWithBufferOverflowCheck (0x0058815F) or select a text fragment, append the result to the caller buffer with strcat, and return 0. Used by config-key and log serialization callers.

Methods: `0x004A1A00`, `0x004A1A60`, `0x004A1AC0`, `0x004A1B20`


### HandleAndStringAccessor

Standalone stdcall helpers: object-handle read into a caller output (via sub_587ECE, returns constant 4) and string-inequality-vs-default comparison writing a bool output.

Methods: `0x004A1990`, `0x004A19D0`


### BucketListContainer

Object holding four bucket/list head pointers at this+0x0/+0x4/+0x8/+0xC; provides zero-init and teardown that walks each non-null head freeing nodes (next link at node+0x44) via FreeWrapper_7bcf. Used from sub_4A4900.

Methods: `0x004A1F60`, `0x004A1F80`

- `this+0x00000000` `void* bucket_head_0` (read_write, GUESS)
- `this+0x00000004` `void* bucket_head_1` (read_write, GUESS)
- `this+0x00000008` `void* bucket_head_2` (read_write, GUESS)
- `this+0x0000000C` `void* bucket_head_3` (read_write, GUESS)

### SoundFlagFieldHelper

Helper pair writing fields this+0x78 and this+0x84 (reset, or set-to-1 and reset) then conditionally calling FlagFieldBitManipulation (0x0054C030) when this+0x64 is non-zero.

Methods: `0x004A3FE0`, `0x004A4000`

- `this+0x00000064` `unsigned int guard_field` (read, GUESS)
- `this+0x00000078` `unsigned int control_field_a` (read_write, GUESS)
- `this+0x00000084` `unsigned int control_field_b` (read_write, GUESS)

### UiStringControl

Unidentified UI control object: parses an input string to an int, stores and clamps it against bounds at +0x1C/+0x20, and has adjacent narrow fields +0x14/+0x15/+0x16 copied between one another.

Methods: `0x004B1BB0`, `0x004B1C70`, `0x004B1FB0`

- `this+0x00000014` `int (accessed at dword/byte/short width across methods) value_field` (read_write, UNKNOWN)
- `this+0x00000015` `unsigned char byte_source` (read, GUESS)
- `this+0x00000016` `unsigned short short_source` (read, GUESS)
- `this+0x0000001C` `int lower_clamp_bound` (read, GUESS)
- `this+0x00000020` `int upper_clamp_bound` (read, GUESS)

### DbListReset

Resets a small db-list/container: zeroes dword_7D2E50 and points three adjacent globals (0x83EE54/0x83EE58/0x83EE5C) at unk_7D2E54, returning the address of dword_7D2E50.

Methods: `0x004B2180`


### InputAxisClamp

Clamps an input value read from this+0x2988 to [-1,1] behind a StateCheckWrapper(dword_7CD25C) state check; on state-check failure the raw value is returned unclamped.

Methods: `0x004B1780`

- `this+0x00002988` `float input_axis_value` (read, GUESS)

## Compatibility contracts

- **OnScreenLogLifecycleSemantics** — Game enter/setup/exit and player-file-restart paths each run StringSplitLoop(2, source-path, size) as an assertion-style check and, when its low byte is non-zero, write an 'entered onscreen'/'entered playerf' message through DebugLogWrite to buffer 0x008AD25C. A replacement must retain a debug-log sink for these lifecycle messages and must preserve the assertion-gate semantics (no log when the check returns zero).
- **GlobalFlagLatchPattern** — Three adjacent global bytes 0x007CE25C, 0x007CE25E, 0x007CE25F are latched to 1 by dedicated setter shims (from RaceModeSetup, SessionScoringUpdate, and an unknown site) and dword 0x007CE250 is cleared to 0 from Game_Post. The flags' semantic meaning is not established; a replacement must preserve the write pattern (or the functions that encode it), not assume the flags are meaningless.
- **CallbackAddressConversionHelper** — Routine addresses at 0x0049AFC0, 0x0049B070, 0x004A0020, 0x004A11F0, 0x004A40D0, 0x004A7000 and 0x004B21A0 are read and passed as integer arguments to BooleanToIntConversion (0x00587B3E). A replacement must preserve whatever registration/encoding contract this helper mediates; the callback targets themselves are not evidenced.
- **SerializedValueFormatting** — Config and log serialization appends floats with '%.5f' (literal at 0x005CD130), integers with '%d' (literal at 0x005C3280), and selected text fragments (0x005CD138 / 0x005CD12C) onto caller-owned buffers via strcat after StringFormatWithBufferOverflowCheck (0x0058815F). A replacement must preserve the %.5f precision, the %d rendering, and the caller-buffer capacity contract.
- **LinkedNodeLinkLayout** — Container traversal reads the list head at this+0x8 and follows a next-sibling link at node+0x24 and a child link at node+0x28 on nodes reached from *(this+0x30). A replacement preserving this container must keep the node link offsets and the skip-count semantics (skip a2 siblings, then count descendants).

## Unresolved

- sub_4B3DB0 (callee of 0x0049AFA0, 0x0049FFC0, 0x004A11D0) is absent from the packet callee table; its signature and purpose are unknown, so GlobalAddressPassthrough is grouped only by shared call pattern.
- EmptyStub_0170 has no callee evidence entry; the EmptyStubWrapper class groups functions whose only observable body is that unresolved call.
- BooleanToIntConversion (0x00587B3E) is evidenced only as receiving routine addresses cast to int; whether it registers, encodes, or merely converts is not established.
- byte_5EA438 (0x005EA438) is treated as a default-directory path at DERIVED trust only; its exact role is not evidenced in the packet.
- Function 0x004A46E4 carries the decompiler warning 'positive sp value has been detected, the output may be wrong'; the memset length (4 * a1 using the this pointer value) is likely a misdecode and the whole prototype is suspect.
- Function 0x004A4000 returns an uninitialized local on the guard-false path; its return value there is undefined.
- The semantics of the flag globals 0x007CE25C, 0x007CE25E, 0x007CE25F and dword 0x007CE250 are unknown; only the write pattern is evidenced.
- The player-vehicle field at offset 16484 (0x40C4) checked by 0x004A0CB0 has no evidenced meaning.
- off_5ACAB0 is treated as a vtable pointer; its contents and the class owning 0x0049A990 are unknown.
- resetDbListHead (0x004B2180): the ABI lead labels it a thunk to FUN_004b3ad0, but the body is assignments, and globals 0x83EE54/0x83EE58/0x83EE5C plus unk_7D2E54 appear only in raw source text without structured evidence.
- UiStringControl offset 0x14 on base 'this' is accessed at three different widths (dword by 0x004B1BB0, byte by 0x004B1C70, short by 0x004B1FB0); the true field type is UNKNOWN and the grouping is a GUESS.
- Offsets 0x00 on base 'this' are written by both VTableDestructorObject (vtable) and BucketListContainer (head zero-init); common ownership of the two objects is not proven.
- StringSplitLoop numeric literals (2604, 2610, 2705, 2510) and the low-byte gate on its result are opaque without the callee's source.
- seasonScoringDbCallback (0x004B21A0) is an empty stub; its identity and the read of dword_7D2E50 flagged by the IDB (absent from the body) are unverified.
- ReverseDynamicsStub (0x004A1EA0) discards its callee result and returns constant 1; the meaning of a1 and of the constant is unexplained.
