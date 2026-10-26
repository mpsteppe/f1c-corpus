# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

GUESS grouping of 61 validated functions in the generic_runtime_objects scope. Every owner is UNKNOWN in the packet; class boundaries are defensible functional groupings, not attested source layout. Twenty empty-body stubs (nullsub_93/94/95/96/97/99/100/101/102/104/130/131/199/200/201, EmptyStub_0000/EmptyStub, EmptyFunction, NoOpStub x2) form RuntimeStubSlot. Five constant-returning leaves (return 1/1/5/1/0) form TrivialConstantReturn; three identity/pass-through shims (return this / this / second argument) form IdentityPassThrough. Nine byte-level accumulators share a byte-add-into-field shape (ByteFieldAccumulator); two combine a byte increment with a forward call (ByteIncrementForwarder); three mutate an 8-byte-strided dword slot and tail-call an initializer (StridedSlotMutator); one writes four consecutive dword slots (DwordSlotBulkWriter). Small accessor/setter helpers cover ObjectFieldAccessor (this+0xE8), FieldReadWriteHelper (a3+0x64 read plus two out-slots) and PointerFieldSetter (*a4 = a3, return a4). Six thin wrappers each perform a single call to a routine named only in raw source (StringCopyWithBufferRealloc, FileSettingExistenceCheck, memset32, DoubleBufferFree, CallbackRegistration_8ce0, loc_4FF715+2) and form SingleCallWrapper. GuardedInitDelegate (0x004C7C10) delegates to a one-time initializer only when its argument equals 1 and is invoked by InitWithStatusCheck (0x004C82C0); HexStringParser (0x004CAD30) is a back-to-front hex parser used by MaterialShaderReactionEffectParser (0x004CA480); BoxFilterImageProcessor (0x0050368A) implements a 2x2 box filter over a packed 32-bit pixel buffer. Six JUMPOUT thunks (0x0051ECE0, 0x0051EDA0, 0x0051EE70, 0x0051EF50, 0x0051F0B0, 0x0051F7C0) transfer control to targets outside the packet. Notable decompiler-artifact hazards: huge decimal constants (1070395196, 1566442692, 963967804) and negative register-relative field offsets (a1-61, a1-1, a2-125) appear in the raw source under 'positive sp value' warnings and are not interpreted as valid object offsets.

## Function roles

- `0x0048D7C0` **RuntimeStubSlot** — Empty __stdcall stub accepting one integer argument and performing no operations; returns immediately. Likely a placeholder or intentionally disabled callback; caller and argument meaning unevidenced.
- `0x00494430` **ObjectFieldAccessor** — Thiscall accessor returning char* this + 232 (0xE8); no dereference occurs, exposing an embedded sub-object or buffer at a fixed displacement. Object type and pointed-to data unknown.
- `0x00494C15` **ByteFieldAccumulator** — Adds char a1 to the byte at a2 + 94 (0x5E), then returns the HGDIOBJ produced by GetStockObject((unsigned __int16)__ES__). Byte-increment shape plus legacy GDI-focus ABI name suggest font bitmap byte update, unverified; a3..a12 declared but unused.
- `0x0049A102` **FieldReadWriteHelper** — Field read/write helper: stores a1 into the dword pointed by a2, reads the dword at a3 + 100 (0x64), stores it into the dword pointed by a5, and returns it. Legacy Vtable_Field_Getter ABI lead unverified; a4 unused.
- `0x0049B050` **RuntimeStubSlot** — Empty stub (nullsub_94): no parameters, no calls, no field/global accesses, no recorded callers.
- `0x0049B070` **RuntimeStubSlot** — Empty stub (nullsub_95): no parameters, no calls, no field/global accesses, no recorded callers.
- `0x0049C486` **ByteFieldAccumulator** — Userpurge byte accumulator: adds the byte value `result` (AL) to the byte at address (a2 - 1070395196) and returns `result` unchanged. Constant preserved verbatim from positive-sp-flagged decompilation; not interpreted.
- `0x0049C898` **ByteFieldAccumulator** — Adds byte a1 to the byte at a2 + 51 (0x33); returns 0 unconditionally. a3/a4 unused by the body.
- `0x0049E663` **DwordSlotBulkWriter** — Bulk initializer: writes the same int value into four consecutive dword slots a2[20], a2[21], a2[22], a2[23] (offsets 0x50-0x5C) and returns that value.
- `0x004A0000` **RuntimeStubSlot** — Empty function stub (EmptyStub_0000) with a void body containing no statements; no fields, globals, guards or callees. Placeholder, alignment pad, or out-of-line no-op.
- `0x004A0020` **RuntimeStubSlot** — Empty stub (nullsub_199): no body, no parameters observed, no calls, no field/global accesses, no recorded callers.
- `0x004A0248` **ByteFieldAccumulator** — __usercall helper (StructByteCounterIncrement): treats ecx argument a1 as a base and adds a2 to the byte at a1 - 61. Counter 61 bytes below the base is an unusual register-relative artifact; owning struct layout unknown.
- `0x004A1969` **RuntimeStubSlot** — Empty stub (nullsub_96): no body, no parameters observed, no calls, no field/global accesses, no recorded callers.
- `0x004A196A` **TrivialConstantReturn** — Leaf function (AlwaysReturnTrue) taking no arguments, reading no state, returning the constant 1 unconditionally. Semantic meaning of the constant (boolean true, count, id) unknown.
- `0x004A1F50` **TrivialConstantReturn** — __stdcall leaf (AlwaysReturnTrueIgnoreArg) accepting one argument a1 but never reading it; returns the constant 1 unconditionally.
- `0x004A40B0` **RuntimeStubSlot** — Empty stub (EmptyStub) with a void body and no parameters; legacy ABI label Empty_Stub_4a40b0 confirms no-op intent. Whether the original ever performed work is unknown.
- `0x004A40D0` **RuntimeStubSlot** — Empty stub (nullsub_200): raw body contains only a null statement; performs no work when called.
- `0x004A4108` **ByteFieldAccumulator** — Byte-field modifier (ByteModifier): a1 in ecx, a2 in bl; adds byte a2 to the byte at a1 - 61. Negative register-relative offset is a decompiler artifact; owning class unknown.
- `0x004B19CA` **StridedSlotMutator** — Forwarding helper (sub_4B19CA): writes dword a1 into byte address a2 + 8*a3 - 1, then calls sub_4B19D0(a1) and returns its result. Minus-one adjustment makes the slot potentially unaligned; slot layout unproven.
- `0x004B1A2A` **StridedSlotMutator** — __usercall helper (a1 in ecx, a2 in ebp, a3 in esi): subtracts a1 from the dword at slot address a2 + 8*a3 - 1, then tail-calls VTableInitWithDefaults_1a30(a1) and propagates its result.
- `0x004B1A4A` **StridedSlotMutator** — __usercall helper (a1 in ecx, a2 in ebp, a3 in esi): ORs a1 into the dword at slot address a2 + 8*a3 - 1, then tail-calls InitWithSentinelPattern(a1) and propagates its result.
- `0x004B1BA6` **RuntimeStubSlot** — Empty stub (nullsub_97): no body, no parameters observed, no calls, no field/global accesses, no recorded callers.
- `0x004B1BAD` **IdentityPassThrough** — __thiscall identity thunk (ReturnThis) returning the receiver this pointer unchanged; single bare return, no state read or modified.
- `0x004B2C78` **RuntimeStubSlot** — Null-stub (EmptyFunction, nullsub_98): no-argument void function with an empty body; implicit bare return, no side effects.
- `0x004B9FA0` **SingleCallWrapper** — Trivial __stdcall passthrough (StringCopyReallocWrapper): forwards a1 to StringCopyWithBufferRealloc and returns the callee's integer result unchanged.
- `0x004BA770` **SingleCallWrapper** — Zero-argument single-call wrapper (FileSettingExistenceCheckWrapper) invoking FileSettingExistenceCheck() and returning its boolean result; only recorded caller is GameExit (0x0042DB20), suggesting an exit-path file-setting presence check.
- `0x004BBEC4` **SingleCallWrapper** — __usercall helper (Memset32WrapperWithByteAccumulator): adds char a3 to the byte at a2 + 10 (0x0A), calls memset32(a4, result, a2), and returns result unchanged. Positive-sp warning; a2 used both as object base and as memset byte count is likely a register-overlap artifact.
- `0x004BF092` **RuntimeStubSlot** — Empty stdcall stub (nullsub_99) taking two integer arguments and performing no operations; likely a replaced no-op or reserved callback slot.
- `0x004C0364` **RuntimeStubSlot** — Empty no-op stub (nullsub_100) accepting a single integer parameter a1 but reading or writing nothing.
- `0x004C2778` **RuntimeStubSlot** — Empty no-op stub (nullsub_101) taking no arguments; body performs no operations.
- `0x004C29EC` **IdentityPassThrough** — int __fastcall passthrough (ReturnSecondArgument) ignoring its first argument a1 and returning its second argument a2 unchanged; no state access.
- `0x004C4BA8` **ByteFieldAccumulator** — Corrupted function (corruptedByteAddStub, positive-sp flagged): appears to add result (al) to the byte at address a2 + 1566442692 and return result unchanged; the huge constant is not a valid object offset and the region may be misdecoded data.
- `0x004C7C00` **TrivialConstantReturn** — Trivial constant function (returnConstant5) returning the integer constant 5 with no arguments, side effects, or guards; called by SetupCarLightingAndRender (0x004C71C0).
- `0x004C7C10` **GuardedInitDelegate** — Guarded delegation (conditionalDelegateToInitializer): initializes result to 0, and only when the this/parameter equals 1 delegates to OneTimeInitializationWithAtexitStyleRegistration and returns its value; otherwise returns null. Called by InitWithStatusCheck (0x004C82C0).
- `0x004C8AAD` **RuntimeStubSlot** — Empty no-op stub (nullsub_102) taking one int argument under __stdcall; no body.
- `0x004CAD30` **HexStringParser** — Hex-string parser (HexStringParser): reads a hex digit string from the last character backwards, accumulating each valid nibble (0-9, a-f, A-F) as v8 << (4 * nibble_index); any non-hex character aborts with the partial result. Declared __thiscall but behaves as a free function; called by MaterialShaderReactionEffectParser (0x004CA480).
- `0x004D7DB0` **RuntimeStubSlot** — Empty no-op stub (nullsub_201) taking no arguments; no observable effect.
- `0x004D7F1A` **RuntimeStubSlot** — Empty no-op stub (NoOpStub, nullsub_103): empty body, performs no work, touches no memory.
- `0x004D82C4` **ByteIncrementForwarder** — Thunk (ByteIncrementJumpThunk, legacy name Thunk_with_Byte_Increment_Jump): increments the byte at a1 - 1 by char a2, then tail-calls loc_4D879C thiscall with a3 and returns its result; positive-sp warning and register layout suggest a hand-written thunk.
- `0x004DB4D0` **TrivialConstantReturn** — Trivial constant-returning stub (ReturnConstantOne): no arguments, returns integer constant 1 immediately.
- `0x004DB546` **ByteFieldAccumulator** — Byte increment on struct (ByteIncrementOnStructPARTIAL): adds char result to the byte at (a2 - 963967804) and returns result unchanged through al; constant preserved verbatim, positive-sp-flagged PARTIAL reconstruction.
- `0x004DBC85` **RuntimeStubSlot** — Empty stub (NullSub_130): decompiled body contains no statements; performs no observable work, returns void.
- `0x004DBF84` **RuntimeStubSlot** — Empty stub (NullSub_131): decompiled body contains no statements; performs no observable work, returns void.
- `0x004DCD06` **ByteFieldAccumulator** — Byte accumulator helper (ByteAccumAddWithReturn): adds the low byte of a1 to the byte at a2 + 94 (0x5E), then returns a1 unchanged; operates purely on caller registers.
- `0x004E0D68` **ByteIncrementForwarder** — Forwarder (ThunkWithByteIncrementForward): adds a1 to the byte at a2 - 125, then forwards a3 to ConditionalResourceRelease and returns that call's result; negative offset is a register-derived artifact.
- `0x004F1B04` **ByteFieldAccumulator** — Trivial byte helper (CharAdd): returns the char sum of two caller-supplied byte arguments (a1 in al, a2 in ch); no globals, callees, fields or control flow.
- `0x004F7000` **SingleCallWrapper** — This-call thunk (ThunkToFUN004f83b0) forwarding its `this` argument unchanged to DoubleBufferFree and returning the callee's int result; thunk itself adds no logic.
- `0x004F8CC5` **SingleCallWrapper** — Zero-argument jump thunk (j_CallbackRegistration_8ce0, IDA j_ prefix) forwarding to CallbackRegistration_8ce0 and returning its int result.
- `0x00500161` **SingleCallWrapper** — Parameter-reorder tailcall wrapper (ParameterReorderWrapper): tail-calls the stdcall target at loc_4FF715 + 2 with (a3, a2, a1, v6), reordering incoming parameters and passing the uninitialized stack slot v6 as the fourth argument; positive-sp warning makes the stack layout unreliable.
- `0x005007EC` **IdentityPassThrough** — __thiscall identity (identity) returning its this pointer unchanged; raw source is only 'return this;'.
- `0x0050368A` **BoxFilterImageProcessor** — C-level 2D box filter (F_2DImageBoxFilter) over a packed 32-bit pixel buffer: a row/column double loop averages each 2x2 neighborhood (four dword taps at offsets 0, +4, +row-stride, +row-stride+4) under the 0xFF00 and 0xFF00FF channel masks with additive rounding, re-masks with 0x3FC00 / 0x3FC03FC, shifts right by 2 and stores; output row span advances by a6 bytes while the input row span advances by 2*a5 dwords (half-span downsample). Returns 0.
- `0x00506CDF` **RuntimeStubSlot** — Empty __stdcall stub (nullsub_104) taking three arguments, none referenced; no body, returns immediately.
- `0x00519BAF` **TrivialConstantReturn** — Trivial stub (ReturnZeroStub) whose entire body is an unconditional return of the integer constant 0; no parameters, fields, globals, calls, or guards.
- `0x0051C086` **PointerFieldSetter** — Minimal four-argument setter (SetterReturnA4): stores a3 into the dword pointed by a4 and returns the a4 pointer unchanged; a1 and a2 unused by the body.
- `0x0051DFCA` **RuntimeStubSlot** — Null stub (NoOpStub) with an empty body; no parameters, fields, globals, guards, or callees; implicit void return.
- `0x0051ECE0` **JumpThunk** — Unconditional JUMPOUT thunk (JumpOutThunk51ECE0): single tail-jump to 0x51ECF1 with arguments a1/a2/a3 passed through; target body lies outside this packet.
- `0x0051EDA0` **JumpThunk** — Jump thunk (JumpThunkTo51EDB1): unconditional JUMPOUT to 0x51EDB1, forwarding __stdcall arguments a1/a2 unchanged.
- `0x0051EE70` **JumpThunk** — Jump thunk (JumpThunkTo51EE81): unconditional JUMPOUT to 0x51EE81, forwarding __stdcall arguments a1/a2 unchanged.
- `0x0051EF50` **JumpThunk** — Jump thunk (JumpThunkTo51EF61): unconditional JUMPOUT to 0x51EF61, forwarding __stdcall arguments a1/a2/a3 unchanged.
- `0x0051F0B0` **JumpThunk** — Unconditional forward-jump thunk (sub_51F0B0): single JUMPOUT(0x51F0C1) under a four-argument __stdcall signature; arguments forwarded untouched.
- `0x0051F7C0` **JumpThunk** — Unconditional forward-jump thunk (sub_51F7C0): single JUMPOUT(0x51F7D1) under a one-argument __stdcall signature; argument forwarded untouched.

## Proposed classes

### RuntimeStubSlot

Family of empty/no-op stub routines (nullsub_93/94/95/96/97/99/100/101/102/104/130/131/199/200/201, EmptyStub_0000, EmptyStub, EmptyFunction, NoOpStub x2) with empty or null-statement bodies. None touch state, parameters, globals, or callees; several declare arguments that are never read. Likely placeholder, callback-slot, or intentionally disabled routines; whether some addresses are disassembly artifacts (data misidentified as code) is unconfirmed.

Methods: `0x0048D7C0`, `0x0049B050`, `0x0049B070`, `0x004A0000`, `0x004A0020`, `0x004A1969`, `0x004A40B0`, `0x004A40D0`, `0x004B1BA6`, `0x004B2C78`, `0x004BF092`, `0x004C0364`, `0x004C2778`, `0x004C8AAD`, `0x004D7DB0`, `0x004D7F1A`, `0x004DBC85`, `0x004DBF84`, `0x00506CDF`, `0x0051DFCA`


### TrivialConstantReturn

Leaf routines that return a fixed integer constant (1, 5, 1, 1, 0) with no parameters read, no state access, and no calls; one member (0x004C7C00, returns 5) is invoked by the car-lighting render path SetupCarLightingAndRender. The semantic meaning of each constant (boolean, flag, count, id) is unevidenced.

Methods: `0x004A196A`, `0x004A1F50`, `0x004C7C00`, `0x004DB4D0`, `0x00519BAF`


### IdentityPassThrough

Trivial shims that return an incoming value unchanged: the __thiscall receiver (this) or the second argument of a fastcall signature. No reads, writes, or calls; typical uses include identity getters, virtual-override stubs, or forwarding targets, none attested by this packet.

Methods: `0x004B1BAD`, `0x004C29EC`, `0x005007EC`


### ByteFieldAccumulator

Heterogeneous byte-arithmetic helpers (grouped by shape, not by proven common class) that add a byte/char value into a byte field of a caller-supplied object, several returning the input value unchanged. Field displacements are mostly positive (a2+51, a2+94); several members (0x0049C486, 0x004C4BA8, 0x004DB546) carry huge decimal constants and positive-sp warnings, and two (0x004A0248, 0x004A4108) target a1-61, all treated as decompiler artifacts whose true targets are unknown. One member (0x00494C15) pairs the byte add with a GetStockObject call under a legacy GDI ABI name; one (0x004F1B04) is a pure char add with no memory access.

Methods: `0x00494C15`, `0x0049C486`, `0x0049C898`, `0x004A0248`, `0x004A4108`, `0x004C4BA8`, `0x004DB546`, `0x004DCD06`, `0x004F1B04`


### ByteIncrementForwarder

Thunks that mutate a byte near the start of a caller-supplied object (increment by a byte argument at negative register-relative offsets a1-1 / a2-125, likely decompiler artifacts) and then forward control to another routine, returning that routine's result. The forward targets (loc_4D879C, ConditionalResourceRelease) are not present as callee evidence in the packet.

Methods: `0x004D82C4`, `0x004E0D68`


### DwordSlotBulkWriter

Compact bulk-initializer writing one integer value into four consecutive dword slots (offsets 0x50-0x5C, i.e. array indices 20-23) of a caller-supplied object/array and returning the written value.

Methods: `0x0049E663`


### StridedSlotMutator

Indexed-slot mutators over a caller-supplied base with an 8-byte element stride (address expression a2 + 8*a3 - 1, the trailing minus-one being an unproven alignment artifact). Each mutates the dword slot (write, subtract, or bitwise-OR) and then tail-calls an initializer named only in the raw source (sub_4B19D0, VTableInitWithDefaults_1a30, InitWithSentinelPattern), propagating its result.

Methods: `0x004B19CA`, `0x004B1A2A`, `0x004B1A4A`


### ObjectFieldAccessor

Thiscall accessor exposing an embedded sub-object or buffer at a fixed displacement: returns char* this + 232 (0xE8) without dereferencing. The pointed-to type and the caller's intended read are unestablished.

Methods: `0x00494430`


### FieldReadWriteHelper

Named-input/out-param helper: stores an incoming value (a1) into an out slot (a2), reads a dword field from a3 + 100 (0x64), stores it into another out slot (a5), and returns it. Legacy Vtable_Field_Getter ABI lead is unverified; a4 is unused.

Methods: `0x0049A102`


### PointerFieldSetter

Minimal setter storing a value (a3) into a caller-supplied destination dword (a4) and returning the destination pointer unchanged; prototype arguments a1/a2 are unused. Which structure field a4 addresses is unevidenced.

Methods: `0x0051C086`


### SingleCallWrapper

Thin wrappers whose entire behavior is a single call or tail-call to a routine named in the raw source, returning the callee's result unchanged. Targets (StringCopyWithBufferRealloc, FileSettingExistenceCheck, memset32, DoubleBufferFree, CallbackRegistration_8ce0, loc_4FF715+2) have no callee-address evidence in this packet. One member (0x004BBEC4) additionally accumulates a byte into offset +10 (0x0A) before its memset call under a positive-sp warning; one (0x00500161) reorders parameters for its tail-call target under an uninitialized stack slot.

Methods: `0x004B9FA0`, `0x004BA770`, `0x004BBEC4`, `0x004F7000`, `0x004F8CC5`, `0x00500161`


### GuardedInitDelegate

Guarded delegation routine: initializes its result to null, and only when the this/parameter equals 1 delegates to a one-time-initialization routine (OneTimeInitializationWithAtexitStyleRegistration, named in source only); otherwise returns null. The comparison against (void*)1 suggests the argument is a flag or call-state rather than an object pointer. Called by InitWithStatusCheck (0x004C82C0).

Methods: `0x004C7C10`


### HexStringParser

Utility parser converting a hexadecimal digit string into an integer by walking the string from its last character and accumulating each nibble into its positional slot (v8 << (4 * nibble_index)); any non-hex character aborts with the partial result. Declared __thiscall but never references the receiver, so it behaves as a free function. Used by the material shader reaction-effect parser path (0x004CA480).

Methods: `0x004CAD30`


### JumpThunk

Unconditional JUMPOUT tail-jump thunks that transfer control to an absolute target address (0x51ECF1, 0x51EDB1, 0x51EE81, 0x51EF61, 0x51F0C1, 0x51F7D1) forwarding their __stdcall arguments unchanged; no local logic. The targets are not recorded as callees, so the real behavior lives outside this packet.

Methods: `0x0051ECE0`, `0x0051EDA0`, `0x0051EE70`, `0x0051EF50`, `0x0051F0B0`, `0x0051F7C0`


### BoxFilterImageProcessor

Image-processing routine implementing a 2D box filter over a packed 32-bit pixel buffer: a row/column double loop averages each 2x2 neighborhood (four dword taps under the 0xFF00 / 0xFF00FF channel masks) with additive rounding and a >>2 shift, and writes the result with an output row span about half the input span (2x2 downsample). The pixel-format split is inferred from the masks, not proven; no callers are recorded.

Methods: `0x0050368A`


## Compatibility contracts

- **ExitPathFileSettingCheck** — The GameExit path (0x0042DB20) invokes a zero-argument wrapper (0x004BA770) that calls FileSettingExistenceCheck() and returns its boolean result unchanged; a replacement exit path must preserve this file-setting presence check on game exit.
- **CarLightingConstantQuery** — SetupCarLightingAndRender (0x004C71C0) invokes a zero-argument routine (0x004C7C00) that returns the constant integer 5; a replacement rendering path that consumes this query must preserve the constant value.
- **ConditionalOneTimeInit** — InitWithStatusCheck (0x004C82C0) invokes a guarded routine (0x004C7C10) that, only when its argument equals 1, performs a one-time initialization and returns its result; otherwise it returns null. The delegated routine (OneTimeInitializationWithAtexitStyleRegistration) is named in source only and has no address evidence.
- **HexStringParseContract** — MaterialShaderReactionEffectParser (0x004CA480) relies on a hex-string-to-int parser (0x004CAD30) that reads hex digits back-to-front and aborts with the partial result on any non-hex character; a replacement must reproduce this parse semantics.
- **ByteAccumulatorAt0x5E** — Two byte-accumulator helpers (0x00494C15, 0x004DCD06) each read-modify-write a byte at displacement +94 (0x5E) of their caller-supplied object pointer; whether both refer to the same object type is not proven, but each requires a mutable byte at +94.
- **PixelBufferBoxFilter** — A 2D box filter (0x0050368A) averages each 2x2 neighborhood of a packed 32-bit pixel buffer under the 0xFF00 / 0xFF00FF channel masks with rounding and a >>2 shift, writing to an output whose row span is about half the input row span; a replacement image path must preserve this downsampling and channel-mask arithmetic to keep output pixels identical.

## Unresolved

- Nine per-function byte/dword field displacements observed in the IR (a2+0x5E, a2+0x33, a2[20..23]=0x50-0x5C, this+0xE8, a3+0x64, a2+0x0A) are NOT declared as class fields because the packet supplies no field: evidence refs and its allowed_evidence_refs list contains none; the offsets live only in the raw-source operations of the owning functions and cannot be grounded as class-owned fields here.
- All 61 functions have UNKNOWN owners in the packet; the fifteen class groupings above are defensible functional groupings (GUESS), not attested source layout, and equal byte displacements on unrelated register-derived bases (e.g. +94 on a2 in 0x00494C15 vs 0x004DCD06) are not proven to be the same object.
- Byte accumulator huge-constant members (0x0049C486 constant 1070395196, 0x004C4BA8 constant 1566442692, 0x004DB546 constant 963967804): the constants are preserved verbatim from 'positive sp value has been detected, the output may be wrong!' decompilation and are not valid object offsets; the true target addresses and the semantics of the byte accumulation are unrecoverable from this packet.
- Negative register-relative field offsets (a1-61 in 0x004A0248 / 0x004A4108, a1-1 in 0x004D82C4, a2-125 in 0x004E0D68) place the mutated byte before the base pointer, which is unusual; these are treated as decompiler artifacts and the owning struct layouts are unknown.
- GDIFontByteUpdate (0x00494C15): the __ES__ segment-register value feeding GetStockObject is a decompiler artifact and its intended stock-object argument is unknown; arguments a3 through a12 are declared but unused; the legacy GDI_font_byte_update ABI name has no independent evidence in this packet.
- StridedSlotMutator (0x004B19CA, 0x004B1A2A, 0x004B1A4A): the callees sub_4B19D0, VTableInitWithDefaults_1a30 and InitWithSentinelPattern are referenced only by name with no address evidence; the 8-byte stride with a trailing minus-one-byte adjustment is unproven; whether the mutators are method entries, callbacks, or vtable thunks is undetermined.
- SingleCallWrapper targets (StringCopyWithBufferRealloc, FileSettingExistenceCheck, memset32, DoubleBufferFree, CallbackRegistration_8ce0, loc_4FF715+2) are named in the raw source but have no callee-address evidence in this packet; their locations and exact contracts cannot be grounded here.
- Memset32WrapperWithByteAccumulator (0x004BBEC4): a2 is used both as the base of the byte accumulator (+10) and as the byte count for memset32, likely a register-overlap artifact under the positive-sp warning; no callers are recorded.
- ParameterReorderWrapper (0x00500161): v6 is an uninitialized stack slot passed as the fourth argument, and the tail-call target loc_4FF715 + 2 has no callee evidence; the parameter layout and the reason for the reordering are uncertain.
- BoxFilterImageProcessor (0x0050368A): the pixel-format split implied by the 0xFF00 / 0xFF00FF masks and the half-span output-buffer contract are inferred from the arithmetic, not stated by the packet; parameter units (a3 dword span, a5 vertical stride, a6 output byte pitch) are DERIVED; no callers are recorded.
- JumpThunk family (0x0051ECE0, 0x0051EDA0, 0x0051EE70, 0x0051EF50, 0x0051F0B0, 0x0051F7C0): targets (0x51ECF1, 0x51EDB1, 0x51EE81, 0x51EF61, 0x51F0C1, 0x51F7D1) are outside the packet; whether these are jump-table entries, tail-call shims, or packed stubs is unknown.
- IdentityPassThrough members (0x004B1BAD, 0x004C29EC, 0x005007EC) and PointerFieldSetter (0x0051C086): no callers are recorded, so whether these are genuine forwarding/identity shims or unfinished placeholders is unconfirmed; a1/a2 unused in 0x0051C086.
- VtableFieldGetter (0x0049A102): the legacy Vtable_Field_Getter ABI lead is unverified by any other packet evidence; a4 is declared but never used.
- ConditionalDelegateToInitializer (0x004C7C10): the this == (void*)1 comparison against a thiscall parameter is atypical; the argument may be a flag or call-state rather than an object pointer, and OneTimeInitializationWithAtexitStyleRegistration has no callee address record.
- The ABI-named legacy labels (GDIFontByteUpdate, VtableFieldGetter, ByteAccumulator, StructByteCounterIncrement, ByteModifier, SetterReturnA4, Single_Call_Wrapper_4b9fa0, Thunk_with_Byte_Increment_Jump, Parameter_Reorder_Wrapper) carry LEGACY trust and do not, on their own, establish caller contracts or owning classes.
- Whether the stub addresses (e.g. 0x004A0000, 0x004A40B0, 0x004C4BA8) are genuine empty functions or disassembly artifacts (data/padding misidentified as code) is unconfirmed; the corrupted 0x004C4BA8 region is explicitly flagged by the decompiler.
