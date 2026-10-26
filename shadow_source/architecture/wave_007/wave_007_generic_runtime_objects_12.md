# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Reconstruction of generic runtime objects from 43 validated function IR records. All owners are packet-UNKNOWN, so every class is a GUESS proposal and no DERIVED owner is claimed. Seven registration thunks (0x004D7DA0, 0x004D7DE0, 0x004DC2E0, 0x004DC320, 0x004F23B0, 0x004F8CE0, 0x004FB8F0) share the single conversion callee 0x00587B3E and are grouped as CallbackRegistrationThunks; 0x004F6AF0 and 0x004F6B80 are the same shape but their registered routines are named tire-wear-property cleanups, so they join 0x004F23A0 (tire-model data block init over dword_8ADB00) in a separate TireModelModule. Nine one-call wrappers (0x004D7DD0, 0x004D7DF0, 0x004DC2D0, 0x004DC2F0, 0x004DC310, 0x004DC330, 0x004F8CF0, 0x004F8CD0, 0x004FB8E0) forward a module-global object to a named allocation/destruction/init routine whose address is absent from the packet; they are grouped as GlobalForwardingWrapper by shape. The SlotObjectContainer groups 0x004F8030/0x004F81D0 (both called by sub_4F70C0) with 0x004F8370/0x004F83B0 (linked by a direct call edge and shared this+0x4/0x94/0x694/0x6D8 fields). The VFXModuleInterface groups the four late-bound dispatchers 0x004F8C00/0x004F8C50/0x004F8C70/0x004F8C90 over the adjacent global function-pointer slots 0x008AFC84/0x008AFC88/0x008AFC8C plus the module handle 0x008AFC78 and VFXClose slot 0x008AFC80. Screen-layout helpers 0x004DAC30 and 0x004DCC90 are grouped as ScreenLayoutHelper; float-constant initializers 0x004DB100/0x004DB120 as FloatFieldInitializer. The remaining functions (0x004DA080, 0x004DC250, 0x004DC430, 0x004DC446, 0x004DD467, 0x004DD6A0, 0x004DE590, 0x004E4590, 0x004F8B00, 0x004F8D10, 0x004F9F60, 0x004FA2F0) are singleton GUESS classes. Equal offsets on different bases are never merged (rule 8): 0x004DC446 writes a vtable into this+0x0 while 0x004DD467 writes a plain dword into this+0x0, and 0x004DB100/0x004DB120 share this+0x10 without proven common ownership.

## Function roles

- `0x004D7DA0` **CallbackRegistrationThunks** — Thin thiscall wrapper: casts the address of no-op callback nullsub_201 (0x004D7DB0) to int and returns the result of BooleanToIntConversion (0x00587B3E); because a valid function address is always non-null the result is effectively constant 1. The legacy ABI label Callback_Registration_4d7da0 hints at a callback-registration hook, but no registration side effect is visible in this body.
- `0x004D7DD0` **GlobalForwardingWrapper** — Thin wrapper: calls sub_4D89D0 with the address of global dword_8AD298 and returns its int result unchanged; dword_8AD298 is read only for its address. The callee's behavior and the caller context are not recorded in this packet.
- `0x004D7DE0` **CallbackRegistrationThunks** — Exit-registration thunk: calls BooleanToIntConversion (0x00587B3E, described as a critical-section-guarded push of its argument onto a global exit-callback list returning 0 on success or -1 on failure) with the address of cleanup routine sub_4D7DF0; the shape matches the MSVC atexit(...) idiom. The registered cleanup's own behavior lies outside this body.
- `0x004D7DF0` **GlobalForwardingWrapper** — Thin wrapper: calls sub_4D89D0 with the address of global dword_8AD298 and returns its int result unchanged; body identical to 0x004D7DD0, suggesting duplicated wrappers or distinct caller-dispatched thunks with no recorded link between them.
- `0x004DA080` **ReferenceTimeValidator** — Reference-time validation check: guards the gap float at this+0x14 (must be >= 0.0) and the stored reference time at this+0x1C (must be non-zero), selects a comparison slot of the player vehicle by the type-flag byte at this+0x18 (non-zero selects *(dword_7C54E0 + 16592), zero selects +16596), and returns 1 on a match else 0. Called by sub_4D9F80.
- `0x004DAC30` **ScreenLayoutHelper** — Mode-driven table lookup: given a mode selector a1 (1..5, default for anything else) fills the three output dwords a2/a3/a4 with a fixed per-mode size/offset tuple ((50,590,858),(50,590,898),(640,1230,818),(640,1230,858),(640,1230,898), default (50,590,818)) and returns a2. Dispatch through the jump table jpt_4DAC3D at 0x004DAD0C. Called by sub_4DA9E0.
- `0x004DB100` **FloatFieldInitializer** — Thiscall constant-field initializer: writes the raw float bit pattern 1082130432 (4.0f) into this[4] (dword at byte offset 0x10) and returns the same raw constant as the int result. No guards, no calls, no other field writes.
- `0x004DB120` **FloatFieldInitializer** — Trivial field initializer: writes the constant 1092616192 (IEEE-754 float 10.0) into the dword slot at this+0x10 (this[4]). No branches, no callees, no return value.
- `0x004DC250` **ScreenTextRenderHelper** — Retrieves a context/global object via SwitchBasedGlobalLookup (0x004D7FA0); when non-null it sets the object's color field at +72 to yellow (16776960) and renders a text string through sub_49F1C0 at fixed screen coordinates (880, 140) using the race-session global dword_7CE048 and the render-device global dword_8B8DC8; always returns 0. The rendered text and the looked-up object's identity are unknown.
- `0x004DC2D0` **GlobalForwardingWrapper** — One-call forwarding wrapper: passes the global dword_8AD3B4 as the single argument to StructZeroInit_7a00 and returns its result unchanged. The callee's effect on the global and the global's meaning are not recoverable from this packet.
- `0x004DC2E0` **CallbackRegistrationThunks** — Exit-registration thunk: calls BooleanToIntConversion (0x00587B3E) with the address of cleanup routine sub_4DC2F0 (described as destroying a linked list rooted at a module global); shape matches the MSVC atexit(...) idiom. Returns 0 on successful registration or -1 on failure per the described callee contract.
- `0x004DC2F0` **GlobalForwardingWrapper** — Thin wrapper: passes the global dword_8AD3B4 by value to LinkedListDestructorWithInnerFree (named in the raw source; no packet callee address) and returns the destructor's result. The named callee is described as freeing each linked-list node and its inner payload.
- `0x004DC310` **GlobalForwardingWrapper** — Thin wrapper: passes the address of the global dword_8AD3B0 to AllocateStructWithDefaultValues (named in the raw source; no packet callee address) and returns the freshly allocated, default-initialized struct pointer. The legacy ABI name Short_Computation_4dc310 is an auto-generated label with no prototype support.
- `0x004DC320` **CallbackRegistrationThunks** — Parameterless thunk that passes the address of sub_4DC330 (cast to int) to BooleanToIntConversion (0x00587B3E) and returns its result. Whether the callee registers sub_4DC330 as a callback or invokes it is not visible in this body.
- `0x004DC330` **GlobalForwardingWrapper** — Thin wrapper: passes the address of the global dword_8AD3B0 (cast to LPVOID****) to LinkedListDestructorWithChildCleanup (named in the raw source; no packet callee address) and returns its result; the named callee walks the list and cleans up each node's child objects. The same global is used as a default-value template by allocator 0x004DC310; how the two uses relate is not established.
- `0x004DC430` **ConditionalDispatchGetter** — Dispatch helper: returns ValueGetter(a1) when a1 is non-zero; otherwise reloads the pointer from global dword_8AFE88 and returns ValueGetter(global) when that global is non-zero, else returns 0. Called from TextureAdjuster (0x004DC770). ValueGetter is named only in the raw source (no callee address evidenced).
- `0x004DC446` **VtableInitializedObject** — Constructor stub that writes the address of the function-pointer table off_5AD11C into the vtable slot at this+0x0 of the object and returns the object pointer. The class identity and the vtable entries are not enumerated in this packet.
- `0x004DCC90` **ScreenLayoutHelper** — Converts screen-relative/proportional float parameters to integer coordinates using two screen-dimension globals: the width global dword_5D6D60 is widened to double and CRTFtol-converted twice (once scaled by a7), the height global dword_5D6D64 is converted to float, scaled by a8, and int-converted, and a6 is converted directly; then delegates to sub_4DCBA0 (0x004DCBA0) with the converted integers plus pass-through a2/a3/a9/a10. a4/a5 declared but unused. Called by UtilityFunction_cfb0 (0x004DCFB0).
- `0x004DD467` **ScreenCoordinateSetter** — Trivial setter under the __userpurge convention: writes argument a4 into the dword at the result pointer (object field offset 0x0) and returns that pointer unchanged. Arguments a2/a3/a5/a6/a7 are unused; the cluster prelabel suggesting a clamp family (structural twin of FloatClamp, cluster representative 0x004646C0) is not supported by this body, which contains no clamp arithmetic.
- `0x004DD6A0` **BoundingBoxSourceObject** — Expands a running axis-aligned bounding box: queries a 3-float offset via TripleFieldQuery (0x0054B420), computes the object's local min/max extents from a1+0x0/0x4/0x8 via BoundingBoxComputation (0x004DD550), translates both extents by the offset, and merges per-axis into the caller's running min bound a2 (per-axis min) and max bound a3 (per-axis max). Called from VehicleGraphicsSceneLoader (0x004DFCE0).
- `0x004DE590` **FloatFieldComparator** — Two-pointer qsort-style comparator: compares the float at offset 0xC of object a1 with the float at offset 0xC of object a2, returning 1 when a1's value is greater, 0 when equal, and -1 when less. The template prelabel describing a one-operand getter is superseded by the raw source.
- `0x004E4590` **FieldMirrorSynchronizer** — Propagates integer argument a2 into four mirrored fields of the this object at offsets 0x0, 0x8, 0x6E4 and 0x32C0, then returns a2. Called by LargeStructFieldSetterWithStoredReference (0x00424040) to synchronize a stored reference/int across the four related sub-structure slots.
- `0x004F23A0` **TireModelModule** — Thin wrapper: initializes the global tire-model data block dword_8ADB00 by delegating to TireModelDataInit (named in the raw source; no packet callee address) and forwards its result.
- `0x004F23B0` **CallbackRegistrationThunks** — Parameterless thunk that passes the address of sub_4F23C0 (cast to int) to BooleanToIntConversion (0x00587B3E) and returns its result; the only side effect of the thunk. Structural twin of the other short-computation thunks; the callee's register-vs-invoke role is unresolved.
- `0x004F6AF0` **TireModelModule** — Trivial registration stub: forwards the function pointer TireWearPropertyCleanup (0x004F6B00) through BooleanToIntConversion (0x00587B3E) and returns its result. No globals are written, no guards, no local state.
- `0x004F6B80` **TireModelModule** — Registration wrapper structurally identical to the neighboring callback registration stub: forwards the address of TireWearPropertyCleanup_6b90 (0x004F6B90) to BooleanToIntConversion (0x00587B3E) and returns the result. No writes to globals, no guards.
- `0x004F8030` **SlotObjectContainer** — Switch dispatch on the unsigned value of a1 through the jump table jpt_4F803D (0x004F8114): maps input case groups to a (write to *a2, write to *a3) flag combination and to one of a1/a2/a3 as the returned pointer. Case group {1,4,7,0x16,0x2B}, {0xA,0x19} and default write (*a2=1,*a3=0); the remaining groups write (*a2=0,*a3=0). Called from sub_4F70C0.
- `0x004F81D0` **SlotObjectContainer** — Looks up an object by string identifier: requires non-null output pointer a1 and string descriptor a2, uses *a2 as the lookup string (falling back to global byte_5EA438 when empty), short-circuits to (*a1 = 0, return 1) for an empty string, and when the global vtable object dword_8AC4C4 is non-null dispatches its vtable slot at +92 (__thiscall) with (a2, a3, a4), stores the returned handle in *a1, validates it by calling the handle's vtable slot at +20 (a zero return makes the function return 0), otherwise returns 1. Called from sub_4F70C0.
- `0x004F8370` **SlotObjectContainer** — Resets the container struct: frees the double-buffered object arrays via DoubleBufferFree (0x004F83B0), reinitializes the per-slot sub-structs via sub_4F70C0, resets the counter arrays at this+0x654 and this+0x698 through ArrayNonZeroCounter (0x004F6D60), clears this+0x94 to 0, sets the active flag byte this+0x4 to 1, and returns 0. Called from VehgenScnFileLoader (0x004C6C40).
- `0x004F83B0` **SlotObjectContainer** — Tears down two double-buffered 45-element object arrays: when the buffer pointer at this+0x694 is non-null, runs ObjectDestructor (0x004F8250) on each of 45 elements (4-byte stride over 180 bytes), frees the buffer via FreeWrapper_7bcf (0x00587BCF), and nulls this+0x694; repeats for the pointer at this+0x6D8; then clears the active flag byte this+0x4 to 0 and returns the last free result. Called from sub_4C6E80 (0x004C6E80) and StructReinitHelper (0x004F8370).
- `0x004F8B00` **HalfRangeAdjustObject** — Calls ArithmeticComparison_8c00 (0x004F8C00) with this+0xC, stores the comparison result at this+0x0, and when the result is zero subtracts 0x8000 from the three dword values at this+0x4/0x8/0xC (the existing fill suggests an unsigned 16-bit range to signed conversion); returns the comparison result. The legacy ABI label Screen_Coordinate_Clamp is LEGACY trust with no prototype support.
- `0x004F8C00` **VFXModuleInterface** — Maps a status result from the VFXGetTracking function-pointer global into fixed integer codes: returns 4 when the pointer at 0x008AFC8C is null, 0 for status 1, 7 for status 2 or 3, and 6 for any other status. Called by sub_4F8B00.
- `0x004F8C50` **VFXModuleInterface** — Late-bound stdcall callback dispatcher: if the global function pointer VFXZeroSet at 0x008AFC84 is null (not registered), returns 4; otherwise invokes it and returns 0. The non-null return of 4 signals that the callback is unavailable.
- `0x004F8C70` **VFXModuleInterface** — Late-bound __thiscall callback dispatcher: if the global function pointer VFXSetVideoMode at 0x008AFC88 is null, returns 4; otherwise invokes it, forwarding the receiver this pointer, and returns 0. Called by DualSourceAcquireWithFallback (0x004F8AE0).
- `0x004F8C90` **VFXModuleInterface** — Module teardown guard-and-release: returns 3 when the loaded-module handle hLibModule (0x008AFC78) is null; otherwise invokes VFXClose (function pointer at 0x008AFC80), releases the library via FreeLibrary (IAT slot 0x0059E0C4), clears hLibModule, and returns 0. Called by HWInput_Exit.
- `0x004F8CD0` **GlobalForwardingWrapper** — Delegation/accessor (cdecl): zero-initializes the global object at 0x008AFE18 via StructZeroInit_8ba0 (named only in the raw source; no packet callee address) and returns a pointer to that object. The caller receives the same global object that was just cleared.
- `0x004F8CE0` **CallbackRegistrationThunks** — Zero-argument stdcall wrapper that forwards the global callback pointer NullsubWrapper_8cf0 (0x004F8CF0) to BooleanToIntConversion (0x00587B3E) and returns the resulting int. The ABI name Callback_Registration_4f8ce0 suggests a callback-registration query, but the callee semantics are not established by this packet.
- `0x004F8CF0` **GlobalForwardingWrapper** — Thin wrapper: calls EmptyStub_7470 with the global unk_8AFE18 (0x008AFE18) as its argument and returns the call's result unchanged. The ABI lead name Nullsub_Wrapper_4f8cf0 is not corroborated: the raw source forwards to a real call.
- `0x004F8D10` **GlobalStateBlock** — Resets a sparse block of global state anchored at 0x008AFCA8: writes 0 to thirteen named members (dword_8AFCA8, dword_8AFCAC, unk_8AFCB0, unk_8AFCB4, unk_8AFCB8, unk_8AFCBC, unk_8AFCC0, unk_8AFCC4, unk_8AFCC8, unk_8AFCCC, unk_8AFCD0, unk_8AFCD4, unk_8AFD14) and returns the block base pointer &dword_8AFCA8. One-shot global-state clear used before first use; no arguments, no calls.
- `0x004F9F60` **TimeOffsetReader** — __thiscall double-valued getter: computes a scaled performance-counter difference from this via PerformanceCounterDiffWithScaling (0x00568D90), adds the read-only global double dbl_8AFEA0 (0x008AFEA0), and returns the sum. Called by SessionSynchronizer (0x0045F950); the time-offset reading rests on the caller context, not on this packet alone.
- `0x004FA2F0` **VidmanSetupLogger** — Startup logging helper for the VidMan (video manager) setup path: builds the debug message buffer at dword_8AD25C via StringSplitLoop (0x004D7A50) using the D:\Dev\F1 1999-2002 path-prefix literal and, when that succeeds, emits an 'entered VidMan' entry through DebugLogWrite (0x004D7AA0); always returns 0. Called by Game_Setup (0x0042D5D0).
- `0x004FB8E0` **GlobalForwardingWrapper** — Thin wrapper: calls StructInitWithFloatDefaults with the global unk_8AFEC0 (0x008AFEC0) as its argument and returns the call's result unchanged. The ABI lead name Thunk_to_FUN_004fc9c0 is not reconciled with the named callee.
- `0x004FB8F0` **CallbackRegistrationThunks** — Zero-argument stdcall wrapper that reads the code address sub_4FB900 (0x004FB900), casts it to int, passes it to BooleanToIntConversion (0x00587B3E) and returns the resulting int. The ABI name Callback_Registration_4fb8f0 suggests a callback-registration query keyed on the target routine address, but the callee semantics are not established by this packet.

## Proposed classes

### CallbackRegistrationThunks

Group of atexit-style callback/exit-registration thunks that forward a callback routine address (0x004D7DB0, 0x004D7DF0, 0x004DC2F0, 0x004DC330, 0x004F23C0, 0x004F8CF0, 0x004FB900) through the shared conversion/registration helper BooleanToIntConversion (0x00587B3E) and return its int result. Grouping is GUESS based on the single shared callee 0x00587B3E and the identical one-argument shape; no common owner class is evidenced.

Methods: `0x004D7DA0`, `0x004D7DE0`, `0x004DC2E0`, `0x004DC320`, `0x004F23B0`, `0x004F8CE0`, `0x004FB8F0`


### GlobalForwardingWrapper

One-call forwarding wrappers that pass a module-global object or pointer (dword_8AD298, dword_8AD3B4, dword_8AD3B0, unk_8AFE18, unk_8AFEC0) as the single argument to an allocation, destruction, or initialization routine named only in the raw source and return its result unchanged. Grouping is GUESS based on the shared one-call-to-a-global shape; no common owner or shared callee address is evidenced.

Methods: `0x004D7DD0`, `0x004D7DF0`, `0x004DC2D0`, `0x004DC2F0`, `0x004DC310`, `0x004DC330`, `0x004F8CF0`, `0x004F8CD0`, `0x004FB8E0`


### ReferenceTimeValidator

Validates a stored reference time against the current player vehicle pointer's comparison slots: requires the gap float at this+0x14 to be non-negative and the stored reference time at this+0x1C to be non-zero, then selects vehicle slot +16592 or +16596 by the type-flag byte at this+0x18 and returns 1 on a match else 0. Owner identity and the purpose of the two reference slots are not established by the packet.

Methods: `0x004DA080`

- `this+0x00000014` `float gap_guard_float` (read, GUESS)
- `this+0x00000018` `byte comparison_slot_type_flag` (read, GUESS)
- `this+0x0000001C` `dword stored_reference_time` (read, GUESS)

### ScreenLayoutHelper

Screen-space layout sizing helpers: SizeOffsetTableByMode fills three output dwords with a fixed per-mode size/offset tuple selected by a 1..5 mode selector through a jump table, and FloatToIntConversionDelegation converts proportional float parameters (scaled against the screen-dimension globals dword_5D6D60/dword_5D6D64) into integer coordinates via CRTFtol for a downstream layout initializer. Grouping is GUESS based on the shared screen-layout theme; the two functions do not share a this base or a caller.

Methods: `0x004DAC30`, `0x004DCC90`


### FloatFieldInitializer

Constant float field initializers that write a raw float constant (4.0f by 0x004DB100, 10.0f by 0x004DB120) into the object field at byte offset 0x10. Grouping is GUESS based on the shared this+0x10 write; common ownership of the offset-0x10 field across the two functions is not proven (rule 8).

Methods: `0x004DB100`, `0x004DB120`

- `this+0x00000010` `float constant_float_field` (write, GUESS)

### ScreenTextRenderHelper

Renders a yellow text string at a fixed screen position (880, 140): obtains a context/global object via SwitchBasedGlobalLookup, sets the object's color field at +72 to yellow, and renders through sub_49F1C0 using the race-session and render-device globals. The object identity and the rendered text are unknown.

Methods: `0x004DC250`


### ConditionalDispatchGetter

Dispatch helper that returns the value obtained through ValueGetter from either the supplied argument or, as a fallback, the global pointer dword_8AFE88, or 0 when both are null. ValueGetter is named only in the raw source and has no evidenced address.

Methods: `0x004DC430`


### VtableInitializedObject

Constructor-stub object whose virtual dispatch table is installed by writing the function-pointer table off_5AD11C into this+0x0. Class identity and the vtable's entries are not enumerated in this packet.

Methods: `0x004DC446`

- `this+0x00000000` `pointer vtable_ptr` (write, GUESS)

### ScreenCoordinateSetter

Single-dword setter under the __userpurge convention: writes an argument value into the dword at the result pointer (object field offset 0x0) and returns the pointer. The prelabel's clamp-family suggestion is not supported by the body.

Methods: `0x004DD467`

- `this+0x00000000` `dword stored_dword` (write, GUESS)

### BoundingBoxSourceObject

Source object for axis-aligned bounding-box expansion: its three float fields at a1+0x0/0x4/0x8 are read to compute local min/max extents, which are translated by a queried 3-float offset and merged into the caller's running min/max bounds. The object type and the world-frame meaning of the offset are unknown.

Methods: `0x004DD6A0`

- `this+0x00000000` `float local_extent_x` (read, GUESS)
- `this+0x00000004` `float local_extent_y` (read, GUESS)
- `this+0x00000008` `float local_extent_z` (read, GUESS)

### FloatFieldComparator

Two-pointer qsort-style ordering callback that compares the float at offset 0xC of two objects and returns 1 / 0 / -1 for greater / equal / less. Whether both pointers are instances of the same class is unproven.

Methods: `0x004DE590`

- `this+0x0000000C` `float compare_float` (read, GUESS)

### FieldMirrorSynchronizer

Synchronizes one value across four mirrored fields of a large object (offsets 0x0, 0x8, 0x6E4, 0x32C0), returning the input value. Called by LargeStructFieldSetterWithStoredReference (0x00424040); the semantic meaning of the four slots is not established (existing analysis suggests sub-structure synchronization within a physics/tire subsystem).

Methods: `0x004E4590`

- `this+0x00000000` `dword mirror_slot_0` (write, GUESS)
- `this+0x00000008` `dword mirror_slot_2` (write, GUESS)
- `this+0x000006E4` `dword mirror_slot_441` (write, GUESS)
- `this+0x000032C0` `dword mirror_slot_3248` (write, GUESS)

### TireModelModule

Tire-model runtime module: initializes the global tire-model data block dword_8ADB00 through a named init routine and registers tire-wear property cleanup routines (0x004F6B00, 0x004F6B90) through the shared registration helper 0x00587B3E. Grouping is GUESS based on the tire-model naming in the registered routines and the tire-model data block; the concrete tire-model semantics are not in this packet.

Methods: `0x004F23A0`, `0x004F6AF0`, `0x004F6B80`


### SlotObjectContainer

Scene/vehicle-generation slot object container: manages per-slot object sub-structures (switch-based parameter setting 0x004F8030 and string-based object lookup 0x004F81D0, both called by sub_4F70C0), holds two double-buffered 45-element object arrays at this+0x694/this+0x6D8, an active flag at this+0x4, and a reset counter at this+0x94, and supports full teardown (DoubleBufferFree) and reinit (StructReinitHelper) used by VehgenScnFileLoader. Grouping is GUESS: 0x004F8370 -> 0x004F83B0 is a direct evidenced call sharing this+0x4/0x694/0x6D8, and 0x004F8030/0x004F81D0 share the caller sub_4F70C0 which is itself called by 0x004F8370, but sub_4F70C0 is not in the packet.

Methods: `0x004F8030`, `0x004F81D0`, `0x004F8370`, `0x004F83B0`

- `this+0x00000004` `byte active_flag` (read_write, GUESS)
- `this+0x00000094` `dword reset_counter` (write, GUESS)
- `this+0x00000694` `pointer first_buffer_ptr` (read_write, GUESS)
- `this+0x000006D8` `pointer second_buffer_ptr` (read_write, GUESS)

### HalfRangeAdjustObject

Adjusts three dword fields by subtracting 0x8000 (suggested unsigned-to-signed 16-bit conversion) when the status mapped by ArithmeticComparison_8c00 over this+0xC is zero, storing the comparison result at this+0x0. The comparison-result semantics and the ABI label Screen_Coordinate_Clamp are both unconfirmed.

Methods: `0x004F8B00`

- `this+0x00000000` `dword comparison_result` (write, GUESS)
- `this+0x00000004` `dword range_adjust_0` (read_write, GUESS)
- `this+0x00000008` `dword range_adjust_1` (read_write, GUESS)
- `this+0x0000000C` `dword range_adjust_2` (read_write, GUESS)

### VFXModuleInterface

Late-bound interface over a cluster of global VFX function-pointer slots (hLibModule handle 0x008AFC78, VFXClose 0x008AFC80, VFXZeroSet 0x008AFC84, VFXSetVideoMode 0x008AFC88, VFXGetTracking 0x008AFC8C): each dispatcher returns 4 when its callback slot is null and invokes the callback otherwise, VFXGetTracking results are mapped to fixed codes, and ModuleUnload releases the module via FreeLibrary. Grouping is GUESS based on the adjacency of the global slots and the shared 4/0 return-code convention; no single owning object is evidenced.

Methods: `0x004F8C00`, `0x004F8C50`, `0x004F8C70`, `0x004F8C90`


### GlobalStateBlock

Sparse block of global state anchored at 0x008AFCA8 that is cleared to zero (thirteen members) in one shot and whose base pointer is returned. The identity and purpose of the block are unknown.

Methods: `0x004F8D10`


### TimeOffsetReader

__thiscall double-valued getter that returns a scaled performance-counter difference plus the read-only global double dbl_8AFEA0; the time-offset semantic rests on the caller SessionSynchronizer (0x0045F950), not on this packet.

Methods: `0x004F9F60`


### VidmanSetupLogger

Startup logging helper for the VidMan setup path that builds a debug message buffer via StringSplitLoop and writes an 'entered VidMan' entry through DebugLogWrite when the buffer build succeeds. The owning object is unknown.

Methods: `0x004FA2F0`


## Compatibility contracts

- **VFXCallbackDispatchContract** — The late-bound VFX callbacks (VFXZeroSet at 0x008AFC84, VFXSetVideoMode at 0x008AFC88, VFXGetTracking at 0x008AFC8C, VFXClose at 0x008AFC80, module handle hLibModule at 0x008AFC78) must be dispatched only when non-null, returning 4 when a callback slot is null and 0 after dispatch; the VFXGetTracking wrapper must map null pointer to 4, status 1 to 0, statuses 2/3 to 7 and any other status to 6; ModuleUnload must return 3 when hLibModule is null and otherwise call VFXClose, release the library via FreeLibrary (import slot 0x0059E0C4) and clear hLibModule.
- **SlotDoubleBufferContract** — The slot object container must keep two double-buffered 45-element object-array pointers at this+0x694 and this+0x6D8 and the active flag at this+0x4; teardown (0x004F83B0) must run ObjectDestructor (0x004F8250) on each of the 45 elements (4-byte stride over 180 bytes) of each non-null buffer, free it via FreeWrapper_7bcf (0x00587BCF), null the pointer, and clear the active flag; reinit (0x004F8370) must additionally reinitialize per-slot sub-structs via sub_4F70C0, reset the counter arrays via ArrayNonZeroCounter (0x004F6D60), clear this+0x94 and set the active flag back to 1.
- **CallbackRegistrationContract** — The callback/exit-registration thunks must forward a callback routine address through the shared helper 0x00587B3E, which the packet describes as a critical-section-guarded push onto a global exit-callback list returning 0 on success or -1 on failure; each thunk returns the helper's result unchanged. The helper's implementation is not grounded by this packet, so the atexit contract is a GUESS.
- **ReferenceTimeValidationContract** — The reference-time validator (0x004DA080) must proceed only when the gap float at this+0x14 is >= 0.0 and the stored reference time at this+0x1C is non-zero, then select the player-vehicle comparison slot at offset 16592 or 16596 of *(dword_7C54E0) according to the type-flag byte at this+0x18 (non-zero selects 16592, zero selects 16596) and return 1 on a match else 0.
- **ScreenLayoutSizeContract** — Screen-layout sizing must fill the three output dwords with the fixed per-mode size/offset tuple ((50,590,858),(50,590,898),(640,1230,818),(640,1230,858),(640,1230,898), default (50,590,818)) for mode selector 1..5 and return the first output pointer, and the proportional-coordinate conversion must scale the proportional parameters against the screen-dimension globals dword_5D6D60 (width) and dword_5D6D64 (height) and convert through CRTFtol before delegating to sub_4DCBA0.

## Unresolved

- 0x004D7DA0 (RegisterCallbackToBoolean): the legacy ABI label hints at callback registration but the raw body only converts the address of the no-op nullsub_201 to a boolean; the meaning of the returned value is unverified.
- 0x004D7DD0 / 0x004D7DF0: sub_4D89D0's behavior and the purpose of global dword_8AD298 are not recorded; the two bodies are identical (duplicate wrappers vs distinct thunks unresolved) and neither has recorded static callers.
- 0x004D7DE0 / 0x004DC2E0 / 0x004DC320 / 0x004F23B0 / 0x004F8CE0 / 0x004FB8F0 (CallbackRegistrationThunks): the semantics of BooleanToIntConversion 0x00587B3E (register-vs-invoke, the exit-callback-list reading) come from packet prose and prior analysis, not from an evidenced callee body; the owning objects are unknown.
- 0x004DA080 (ReferenceTimeValidator): flt_59E440 is packet-listed but the raw source compares this+0x14 only against a literal 0.0; the type-flag semantics (slot selection) are DERIVED from branch structure; the owner and the meaning of vehicle slots +16592/+16596 are not established.
- 0x004DAC30 (SizeOffsetTableByMode): the meaning of the three output values (x/y sizes and an offset) is not recoverable without the consuming caller sub_4DA9E0.
- 0x004DB100 / 0x004DB120 (FloatFieldInitializer): dword_5ACF5C is packet-listed for 0x004DB100 but absent from the decompiled body; the class owning the offset-0x10 field is unidentified, and common ownership of this+0x10 across the two functions is unproven (rule 8).
- 0x004DC250 (ScreenTextRenderHelper): the identity of the object returned by SwitchBasedGlobalLookup(0) and the exact rendered text are unknown; the color field at +72 belongs to the lookup result, not a typed owner field.
- 0x004DC2D0 / 0x004DC2F0 / 0x004DC310 / 0x004DC330 / 0x004F8CF0 / 0x004F8CD0 / 0x004FB8E0 (GlobalForwardingWrapper): every named callee (StructZeroInit_7a00, LinkedListDestructorWithInnerFree, AllocateStructWithDefaultValues, LinkedListDestructorWithChildCleanup, EmptyStub_7470, StructZeroInit_8ba0, StructInitWithFloatDefaults) is absent from the packet callee lists, so no callee address or contract is grounded; the LPVOID**** cast at dword_8AD3B0 and the relation between the allocator and destructor uses of dword_8AD3B0 are unresolved.
- 0x004DC430 (ConditionalDispatchGetter): ValueGetter is named only in the raw source with no evidenced address; whether the argument and dword_8AFE88 hold the same object type is unproven.
- 0x004DC446 (VtableInitializedObject): off_5AD11C is DERIVED as a vtable/function-pointer table but its entries are not enumerated; whether this runs as a direct constructor or through another is not visible.
- 0x004DCC90 (FloatToIntConversionDelegation): parameters a4/a5 are declared but unused; the roles of pass-through a2/a3/a9/a10 and of each converted coordinate in sub_4DCBA0 are defined only downstream.
- 0x004DD467 (ScreenCoordinateSetter): the __userpurge register routing is nonstandard and the written dword's role is unproven; the prelabel's clamp-family suggestion (cluster representative 0x004646C0) is not corroborated by the body.
- 0x004DD6A0 (BoundingBoxSourceObject): the object type of a1 is unknown; the source/world-frame meaning of the TripleFieldQuery offset is unknown; whether the min/max roles of the BoundingBoxComputation outputs are fixed or caller-conventional is not proven.
- 0x004DE590 (FloatFieldComparator): the template prelabel's one-operand getter reading is superseded by the raw two-pointer comparator; whether a1 and a2 are instances of one class is unproven.
- 0x004E4590 (FieldMirrorSynchronizer): the semantic meaning of the four mirrored fields (offsets 0x0, 0x8, 0x6E4, 0x32C0) and of the input value a2 depends on the caller at 0x00424040.
- 0x004F23A0 (TireModelModule): the callee TireModelDataInit is named only in the raw source; the structure of the global block dword_8ADB00 and the success/failure meaning of initialization are unknown.
- 0x004F8030 (switchBasedParamSetting): the domain meaning of the selector and the two boolean outputs is unknown; the jump table jpt_4F803D (0x004F8114) is referenced but its case-to-target mapping is not enumerated.
- 0x004F81D0 (FindObjectByString): the +92 lookup and +20 validation vtable slots depend on the runtime object behind global dword_8AC4C4, whose class identity is unknown; the meaning of a3/a4 and whether the returned handle is released are unresolved.
- 0x004F83B0 (DoubleBufferFree): the element type of the two 45-element arrays is unknown (ObjectDestructor is a generic vtable-destruction helper); whether 45 elements reflects a fixed slot count or a size coincidence is unconfirmed.
- 0x004F8B00 / 0x004F8C00 (HalfRangeAdjustObject / VFXModuleInterface): the meaning of the VFXGetTracking status codes 4/0/7/6 and of the VFXGetTracking input arguments is unknown; the 0x8000 subtraction as unsigned-to-signed conversion is only a DERIVED suggestion.
- 0x004F8C50 / 0x004F8C70 / 0x004F8C90: the registration path that fills the VFX callback slots is unknown (no callers for 0x004F8C50); the concrete signature of VFXZeroSet/VFXSetVideoMode/VFXClose and the module identity are not stated; the caller HWInput_Exit of ModuleUnload has no allowed evidence reference in this packet.
- 0x004F8D10 (ResetGlobalBlock): callee 0x00587B3E is listed by static facts but not invoked in the raw source; global 0x004F8D30 (loc_4F8D30) is a code location listed as a read global and not referenced by the raw source; the identity and purpose of the block anchored at 0x008AFCA8 are unknown.
- 0x004F9F60 (TimeOffsetReader): the meaning of the additive global dbl_8AFEA0 (session start time vs fixed offset vs per-session bias) is not determinable from this packet alone.
- 0x004FA2F0 (VidmanSetupLogger): the meaning of the literal 2 passed to StringSplitLoop and the exact StringSplitLoop contract are unknown; dword_8AD25C is packet-listed read-only yet passed as a written buffer; the owning object is unknown.
- General: equal offsets on different this bases are never merged into a shared type without packet proof of common ownership (rule 8); every class in this proposal is GUESS and no owner is DERIVED because the packet supplies no owner above UNKNOWN; worker agreement cannot create runtime truth.
- General: 0x004F8B00's legacy ABI label Screen_Coordinate_Clamp and 0x004DC310's Short_Computation_4dc310 are LEGACY auto-labels with no prototype support and cannot be promoted.
