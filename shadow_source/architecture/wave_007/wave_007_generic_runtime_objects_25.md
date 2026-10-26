# RuntimeObjectsAndCRTInfrastructure

Scope: `generic_runtime_objects`  
Trust: `GUESS`

The packet contains 41 functions that divide into two large, defensible MSVC CRT clusters and several small GUESS clusters of generic runtime-object plumbing. The MSVCRTExceptionHandler cluster (0x00588864-0x0058A3B6) is the CRT SEH/C++ exception core: RtlUnwind-based global unwind, a scope-table local-unwind walker, the _except_handler3/4-style frame processor, a flag-gated handler, a C++ frame-handler trampoline, and SEH forwarding thunks. The MSVCRTFloatDispatcher cluster (0x0058BD8F-0x005906BB) is CRT float-to-string formatting and FPU/FPE dispatch (trandisp1/2, cintrindisp1/2, fassign, cfltcvt, fsave/frstor wrappers). The remaining functions form GUESS clusters: per-type reference-count decrement wrappers reading flag bytes in the 0x008D3E30-0x008D3E3D region, callback pass-through wrappers into the shared BooleanToIntConversion routine, a copy-construct/vtable-install initializer with its field getters, a processor-capability probe pair (FDIV-bug check plus dynamic IsProcessorFeaturePresent), and string helpers. Two functions (MoveFileA error-handling wrapper 0x005898D3 and fixed-argument wrapper 0x0058BC56) are standalone with unknown owners. Most semantic ownership remains UNKNOWN; the CRT clusters are the only DERIVED-anchored structure.

## Function roles

- `0x00586F20` **CallbackRegistry** — Callback pass-through wrapper: forwards the code address of 0x00586F30 (cast to int) to the shared BooleanToIntConversion routine and returns its result.
- `0x00586F30` **ReferenceCountController** — Reference-count decrement wrapper forwarding to RefCountDecrementWithCheck; deterministic facts record a read of flag global 0x008D3E30 not visible in the raw body.
- `0x00587090` **ConfigCopyConstruct** — Copy-construct-style initializer: parses the source sub-structure at a2+4 via StructInitParse, copies three source fields into this+0x10/0x14/0x18, clears flag byte this+0x19, installs vtable 0x005B8C30 at this+0x0, returns this.
- `0x00587210` **ConfigCopyConstruct** — Byte getter returning this+0x18 unchanged; consumed by ShortComputation_a820 (0x0057A820).
- `0x0058730C` **ConfigCopyConstruct** — Thiscall getter returning the dword at this+0x10 (this[4]); no side effects.
- `0x00587410` **ReferenceCountController** — Reference-count decrement+cleanup wrapper forwarding to RefCountDecrementWithCleanup; reads flag global 0x008D3E35 per deterministic facts.
- `0x00587450` **ReferenceCountController** — Reference-count decrement+check wrapper forwarding to RefCountDecrementWithCheck; reads flag global 0x008D3E34 per deterministic facts.
- `0x005876A0` **ReferenceCountController** — Single-expression wrapper around RefCountDecrementWithCleanup; deterministic facts record a read of flag global 0x008D3E39.
- `0x005876E0` **ReferenceCountController** — Single-expression wrapper around RefCountDecrementWithCheck; deterministic facts record a read of flag global 0x008D3E38.
- `0x00587A70` **ReferenceCountController** — Single-expression wrapper around RefCountDecrementWithCleanup; deterministic facts record a read of flag global 0x008D3E3D.
- `0x00587AA0` **CallbackRegistry** — Callback pass-through wrapper: forwards the code address of 0x00587AB0 (cast to int) to the shared BooleanToIntConversion routine and returns its result.
- `0x00587AB0` **ReferenceCountController** — Reference-count decrement wrapper forwarding to RefCountDecrementWithCheck; read of flag global 0x008D3E3C is not visible in this body and likely occurs in the callee.
- `0x00588864` **MSVCRTExceptionHandler** — CRT global-unwind helper: calls RtlUnwind(TargetFrame, &loc_58887C, 0, 0); used by ScriptFrameProcessor (0x0058895C) and LongjmpMSVCCRT (0x0058A770).
- `0x00588884` **MSVCRTExceptionHandler** — Flag-gated SEH handler: reads dword at this+0x4, tests bitmask 6; on flag-set stores a2 into *a4 and returns 3, otherwise returns 1.
- `0x005888A6` **MSVCRTExceptionHandler** — CRT scope-table local-unwind core (_local_unwind): walks 3-dword scope entries from a1+0x8 with current trylevel a1+0xC, invoking each entry's registered unwind handler (guarded by a disposition word) until trylevel -1 or target a2.
- `0x0058890E` **MSVCRTExceptionHandler** — CRT abnormal-termination probe: reads the TEB exception list head and, only when the head handler equals FlagCheckHandler (0x00588884), reports whether the second registration links back into the handler's saved parameter block; defaults to 0.
- `0x00588931` **MSVCRTExceptionHandler** — Jump stub (JUMPOUT to 0x588944) forwarding argument a1; real implementation and the read of unk_5E63D0 (0x005E63D0) live at the jump target.
- `0x0058893A` **MSVCRTExceptionHandler** — State-recording helper (__userpurge): stores eax (a3) into unk_5E63D4, the dword at [a2+8] into unk_5E63D8, and frame pointer a2 into unk_5E63DC, then returns a3; reached from SEH/unwind paths.
- `0x0058895C` **MSVCRTExceptionHandler** — MSVCRT SEH frame processor (__except_handler3/4 style): on exception flags at a1+4 it unwinds unconditionally; otherwise walks the scope table, evaluates filters, and on a match performs global unwind (0x00588864), local unwind (0x005888A6) and catch dispatch (0x0058893A).
- `0x00588A19` **MSVCRTExceptionHandler** — _local_unwind dispatch wrapper: loads scope-frame pointer from this+0x18 and target trylevel from this+0x1C, passes both to MSVCRTSEHFrameUnwinder, returns its result.
- `0x005898D3` **UnknownObject** — Win32 MoveFileA wrapper with error handling: clears LastError on success, captures GetLastError on failure, routes the error through ErrorIDLookupTable (0x0058AF5C) and returns -1, else 0.
- `0x0058A380` **MSVCRTExceptionHandler** — MSVC C++ exception dispatch entry point (__usercall): forwards its arguments plus three zero tail values to sub_593446 and returns the result; compiler-emitted frame-handler trampoline.
- `0x0058A3B6` **MSVCRTExceptionHandler** — SEH exception-frame forwarding thunk: reorders five exception-frame arguments (a3, a1, a5) into sub_593C50 and returns its result; invoked from SEHWrapperAroundCRTFunctionCall (0x005938B4).
- `0x0058A870` **ScalarMathUtility** — Compiler helper for 64-bit logical right shift (value in edx:eax, count in cl): returns 0 for count >= 64, else a1 >> a2; invoked by TextureDecodeRGB16 (0x0050A6E5).
- `0x0058A88F` **ScalarMathUtility** — Finite/non-finite predicate on the upper 16 bits of a2: returns TRUE when (HIWORD(a2) & 0x7FF0) != 0x7FF0; a1 unused; guards degenerate FP inputs.
- `0x0058BC56` **UnknownObject** — Fixed-argument wrapper: forwards the constant literals 0x10000 and 196608 to sub_59508D and returns its result, likely configuring a fixed-size operation.
- `0x0058BC68` **ProcessorCapabilityProbe** — Constant-only FPU sanity probe computing 4195835.0 - (4195835.0 / 3145727.0) * 3145727.0 and returning (residual > 1.0); canonical Pentium FDIV-bug detection expression.
- `0x0058BCA6` **ProcessorCapabilityProbe** — Dynamic IsProcessorFeaturePresent query: resolves the kernel32 export via GetModuleHandleA/GetProcAddress and calls it with feature id 0, falling back to the internal FDIV probe (0x0058BC68) when resolution fails.
- `0x0058BD29` **CrtStringHelper** — Trims trailing zeros from the fractional part of a formatted float string and re-joins the exponent tail; uses the read-only decimal-separator global byte_5E6BD8.
- `0x0058BD77` **ScalarMathUtility** — Predicate returning TRUE when the double pointed to by the argument is >= 0.0 (compared against dbl_5B8CC8), else FALSE.
- `0x0058BD8F` **MSVCRTFloatDispatcher** — CRT long-double assignment helper (__fassign): on nonzero discriminator a1 materializes source a3 via BufferFormatHelper and stores both dwords; on zero parses in place via StringParseWithFormat and stores one dword; returns destination a2.
- `0x0058C07F` **MSVCRTFloatDispatcher** — CRT float-to-string format dispatcher (cfltcvt): 'e'/'E' (101/69) routes to FloatToStringWithSignWidth (0x0058BDCD), 'f' (102) to IntToStringWithSignPositionDraw (0x0058BEF0), anything else to UtilityFunction_bfec (0x0058BFEC).
- `0x0058D9BE` **ScalarMathUtility** — x87 assembler power primitive (LEGACY ABI lead x87_pow): compares |st0| against extended-precision constant tbyte_5E6C0E, branches on FPU status flags, applies f2xm1 on the non-compare path, returns result in st0.
- `0x0058DA01` **MSVCRTFloatDispatcher** — x87 rounding/FPU-state control helper (LEGACY FloatRoundControl): rounds st0 via frndint and, on an already-integral input, multiplies by dbl_5E6C22 and rounds again; returns the original st0.
- `0x0058DA35` **MSVCRTFloatDispatcher** — FPU-state wrapper: saves x87 state via fsave, calls sub_58DE2C with (a2, a1, buffer), restores via frstor, returns the first saved double, and calls SetByteFlag when the callee returned nonzero.
- `0x0058DA70` **MSVCRTFloatDispatcher** — CRT float-display control-word and dispatch helper (trandisp1): selects FPU control word from format-mode byte at this+0xE, builds a dispatch byte via the unk_5E6C6C xlat table, and calls through the vtable at a1+16.
- `0x0058DAD7` **MSVCRTFloatDispatcher** — Structural twin of trandisp1 with a double xlat dispatch index ((4 * v13) | _AL) into the vtable at a1+16; also records caller state and an x87-stack value.
- `0x0058FC60` **CrtStringHelper** — First-character-of-set helper: builds a 256-bit membership set from byte string a2 via _bittestandset, scans a1 via _bittest, and returns the first matching character (rendered by Hex-Rays as (byte)a1 - 1) or 0.
- `0x00590640` **MSVCRTFloatDispatcher** — CRT intrinsic/FPE dispatch wrapper (cintrindisp2): forwards register-carried caller state and a local savedregs buffer to sub_58DAD7, then returns the result of sub_59070A.
- `0x0059067E` **MSVCRTFloatDispatcher** — CRT intrinsic/FPE dispatch wrapper (cintrindisp1): forwards register-carried caller state and a local savedregs buffer to trandisp1 (0x0058DA70), then calls sub_59070A with the saved FPU state.
- `0x005906BB` **MSVCRTFloatDispatcher** — CRT float-display wrapper (ctrandisp2): loads two doubles via CRTFload, forwards register-carried state and x87-stack doubles to sub_58DAD7, then calls sub_590703 on the savedregs buffer and returns its result.

## Proposed classes

### MSVCRTExceptionHandler

MSVC CRT structured- and C++-exception handling infrastructure: global unwind via RtlUnwind, scope-table local unwind, _except_handler3/4-style frame processing, flag-gated handler, state recording, and SEH/C++ dispatch trampolines. Compiler-emitted, not game logic.

Methods: `0x00588864`, `0x00588884`, `0x005888A6`, `0x0058890E`, `0x00588931`, `0x0058893A`, `0x0058895C`, `0x00588A19`, `0x0058A380`, `0x0058A3B6`

- `this+0x00000004` `uint32 exception_record_flags` (read, DERIVED)
- `this+0x00000008` `uint32* scope_table` (read, DERIVED)
- `this+0x0000000C` `int32 current_trylevel` (read_write, DERIVED)
- `this+0x00000018` `void* scope_frame` (read, GUESS)
- `this+0x0000001C` `int32 target_trylevel` (read, GUESS)

### MSVCRTFloatDispatcher

MSVC CRT float-to-string formatting and FPU/FPE dispatch infrastructure: long-double assignment (fassign), float-format dispatch (cfltcvt), FPU control-word selection and vtable dispatch (trandisp1/2), FPU-state save/restore, and the intrinsic dispatch wrappers (cintrindisp1/2, ctrandisp2). Compiler/CRT machinery, not game logic.

Methods: `0x0058BD8F`, `0x0058C07F`, `0x0058DA01`, `0x0058DA35`, `0x0058DA70`, `0x0058DAD7`, `0x00590640`, `0x0059067E`, `0x005906BB`

- `this+0x0000000E` `byte format_mode` (read, DERIVED)

### ScalarMathUtility

Small scalar math helpers used across the binary: a 64-bit shift-right compiler helper, a finite/non-finite predicate, a non-negative-double predicate, and an x87 power primitive. Membership is by shape, not by proven common source ownership.

Methods: `0x0058A870`, `0x0058A88F`, `0x0058BD77`, `0x0058D9BE`


### ReferenceCountController

Per-type reference-count decrement wrappers that forward to shared RefCountDecrementWithCheck/Cleanup routines; each reads a per-type flag byte in the 0x008D3E30-0x008D3E3D region (flag reads attested by deterministic facts but not visible in the raw bodies).

Methods: `0x00586F30`, `0x00587410`, `0x00587450`, `0x005876A0`, `0x005876E0`, `0x00587A70`, `0x00587AB0`


### CallbackRegistry

Zero-argument wrappers that forward a target function's code address to the shared BooleanToIntConversion routine (0x00587B3E), consistent with a callback/registration pass-through; the semantic role of the shared callee is unconfirmed.

Methods: `0x00586F20`, `0x00587AA0`


### ConfigCopyConstruct

Object whose copy-construction copies a small config record (dwords at 0x10/0x14, bytes at 0x18/0x19) from a source object, parses an embedded sub-structure, and installs vtable 0x005B8C30; the two trivial getters read the same field offsets and are grouped here by shape with GUESS trust on common ownership.

Methods: `0x00587090`, `0x00587210`, `0x0058730C`

- `this+0x00000000` `void** vtable` (write, GUESS)
- `this+0x00000010` `uint32 config_dword_0x10` (read_write, GUESS)
- `this+0x00000014` `uint32 config_dword_0x14` (write, GUESS)
- `this+0x00000018` `byte config_byte_0x18` (read_write, GUESS)
- `this+0x00000019` `byte flag_byte_0x19` (write, GUESS)

### ProcessorCapabilityProbe

Processor-capability detection: the constant-only Pentium FDIV-bug probe (4195835.0 / 3145727.0 residual) and the dynamic IsProcessorFeaturePresent query that falls back to it. Grouped by the fallback relationship.

Methods: `0x0058BC68`, `0x0058BCA6`


### CrtStringHelper

Free string utilities: trailing-zero trim of a formatted float string (using the read-only decimal-separator global byte_5E6BD8) and a first-character-of-set search over two byte strings.

Methods: `0x0058BD29`, `0x0058FC60`

- `this+0x00000000` `char* string_buffer` (read, GUESS)
- `this+0x00000001` `char* fraction_tail` (read_write, GUESS)

## Compatibility contracts

- **CRTSehFrameContract** — MSVC _except_handler3/4 SEH frame layout must be preserved: exception-record flags at frame+0x4 (bits 1-2 trigger unconditional unwind), scope-table pointer at frame+0x8, current trylevel at frame+0xC (3-dword scope entries), and the RtlUnwind(TargetFrame, loc_58887C, 0, 0) global-unwind protocol. A replacement executable that wants to coexist with or replace this CRT path must match this layout and the -1/target-trylevel termination semantics.
- **CrtFpuControlWordSelection** — CRT float-display helpers install specific x87 control words selected by the format-mode byte at object+0xE (mode 5 selects control word 63, otherwise 4927) before vtable dispatch. Any replacement of the float-formatting path must reproduce this control-word selection and the unk_5E6C6C xlat-table dispatch so formatted output matches.
- **CrtFloatFormatDispatch** — Float-to-string conversion dispatches on the format code: 'e'/'E' to the scientific formatter, 'f' to the fixed-point formatter, everything else to the default helper. A replacement must preserve these format-code routing semantics to reproduce rendered float text.
- **ProcessorCapabilityDetection** — Initialization queries a processor feature flag via dynamically resolved IsProcessorFeaturePresent(feature id 0) and falls back to the constant-only FDIV probe (4195835.0 / 3145727.0 residual > 1.0). A replacement must reproduce the same capability signal so feature-dependent code paths behave identically.
- **MoveFileErrorContract** — The MoveFileA wrapper reports failures: returns 0 on success (LastError cleared), and on failure captures GetLastError, routes it through ErrorIDLookupTable, and returns -1. A replacement file-operation layer must preserve this success/error signalling contract for the caller at 0x004B0770.
- **RefCountPerTypeFlagRegion** — Seven per-type reference-count decrement wrappers read flag bytes in the contiguous 0x008D3E30-0x008D3E3D region. If these bytes gate reference-count semantics per object type, a replacement must reproduce the same per-type flag layout; the exact layout is unproven.

## Unresolved

- BooleanToIntConversion (0x00587B3E) applied to a function pointer is semantically unexplained; the callback-registration reading is a shape-based GUESS, not proven.
- RefCountDecrementWithCheck/Cleanup are named only in raw source text and absent from the packet callee list, so their target addresses and exact reference-counting semantics are unknown.
- The 0x008D3E30-0x008D3E3D byte flags form an apparent per-type refcount-flag region but their reads are recorded by deterministic facts, not visible in the raw bodies; the mechanism (argument setup, inlined prologue, thunk linkage) is unknown.
- The vtable installed at 0x005B8C30 is shared with ObjectInitWithVTableSetup (0x00587030, outside this packet); the class identity behind it is unverified.
- The copy-construct fields (this+0x10/0x14/0x18/0x19) have no confirmed semantics, and whether getters 0x00587210/0x0058730C belong to the same class is a GUESS based on shared offsets.
- StructInitParse (0x00587490) purpose is not in the packet.
- Global 0x0058A40A is flagged as read in 0x0058A3B6 but appears nowhere in its raw body; the read may belong to inlined or optimized-away code.
- dword_5E9AD0 (CrtFPEExceptionFlag, DERIVED) is read by the 0x00590640/0x0059067E dispatch paths but does not appear directly in their raw source snippets.
- The decompiler leaves registers v4 (edx) in 0x005906BB and v9 (ecx) in 0x0058895C uninitialized; the register-carrying contracts around them are not fully recovered.
- tbyte_5E6BF0 is referenced by X87Pow (0x0058D9BE) but has no packet globals entry or evidence ref; its value is unknown.
- The 257 code passed to sub_58893A and the disposition dword in the scope-table entry are unexplained; full scope-table layout is not established.
- FDIV-probe literal-to-global mapping (which double lives at 0x005B8C80/0x005B8D48/0x005B8D50) is not evidenced; the interpretation is DERIVED.
- FindFirstCharInSet's return value is a Hex-Rays degradation ((byte)a1 - 1) of an apparently pointer-returning strpbrk-like helper; its consumption by 0x00588A34 is unknown.
- The 0x0058FC60 field:this:0x00000000 prelabel is a spurious getter artifact; the function is __cdecl with two pointer arguments and no 'this' object.
- JumpStub 0x00588931 forwards to 0x588944 outside this packet; unk_5E63D0 (0x005E63D0) read is likely consumed at the jump target.
- The two adjacent globals stores of StoreInterpreterState (0x0058893A) form a small context record but their role and the object behind pointer a2 are unproven.
- Why fixed-argument wrapper 0x0058BC56 and query 0x0058BCA6 both route through InitWrapperCalling3Subroutines (0x00587B7F) is outside this packet.
- The purpose of literals 0x10000 and 196608 passed to sub_59508D is unknown.
- dbl_5E6C22 in FloatRoundControl and the FPU-control/rounding-state effect of that helper are unproven.
- Whether the FPU-state save/restore in 0x0058DA35 serves reentrancy or ABI isolation is unknown, and SetByteFlag's target flag is unidentified.
