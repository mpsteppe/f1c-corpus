# Cross-Validation Report: Batch 6 (Functions 4101–4155)

Cross-validated 55 functions from analysis_pipeline/analyzed/ against docs/.  
**None of these 55 functions have `## FUN_` header entries in any docs/ file.**  
All exist only as triage-only rows in `docs/decompiled_full_index_final.md` or mentions in other docs' Calls: lists.

---

### FUN_0054FDF0 — result
**Current doc:** docs/decompiled_full_index_final.md (line 4420): triage-only — `| 0x0054fdf0 | 2 | math_util | short computation | no | -- |`
**Issues found:** none (triage-only; no full entry to validate)
**Details:** 10-byte setter: `*(param_1 + 0x54) = param_2`. Trivial setter for struct field at +0x54. Triage category `math_util` is inaccurate — this is a setter/wrapper, not computation. Suggested: `data_access` or `setter`.

---

### FUN_0058DC40 — result
**Current doc:** 
- docs/decompiled_full_index_final.md (line 5493): triage — `| 0x0058dc40 | 28 | unknown | -- | no | -- |`
- docs/decompiled_full_index_final.md (line 6844): re-triage — `| 0x0058dc40 | 27 | Math/Wrapper | CRT float passthrough wrapper function | Float wrapper | |`
**Issues found:** none (triage-only; no full entry)
**Details:** 23-byte fastcall wrapper. Calls `FUN_00596175(param_2, local_24, &param_3)`. Passes through float10 in ST0. Second triage entry (line 6844) correctly categorizes as `Math/Wrapper — CRT float passthrough wrapper function`. No discrepancy.

---

### FUN_0040BE20 — result
**Current doc:** docs/decompiled_full_index_final.md (line 241): triage — `| 0x0040be20 | 24 | math_util | short computation | no | -- |`
**Issues found:** triage category likely wrong
**Details:** 65-byte fastcall function. Checks 3 pointer fields at +0x18, +0x1c, +0x20 for non-null; if non-null calls vtable[0](1) and nulls field. This is a release/deinit pattern calling destructors via vtable. `math_util` is wrong — should be `deinit` or `destructor_wrapper`. Cited in docs/24-enum-catalog.md for audio processor type enum at offsets +0x18, +0x1c, +0x20.

---

### FUN_00467340 — result
**Current doc:** docs/decompiled_full_index_final.md (line 1379): triage — `| 0x00467340 | 27 | unknown | unidentified | no | -- |`
**Issues found:** none (triage-only)
**Details:** 96-byte thiscall with param_2. Checks flag at param_1+800. Reads from param_1+800+0x14, adjusts by ±1. Branches on value at param_1+0x32c: if != 4 calls FUN_0042eaa0 + FUN_004673b0; else calls FUN_0042eb60 + FUN_004673b0. Index-manipulation logic — potentially UI selection or list navigation. No doc entry to validate against.

---

### FUN_0048E070 — result
**Current doc:** 
- docs/decompiled_full_index_final.md (line 1871): triage — `| 0x0048e070 | 16 | math_util | short computation | no | -- |`
- docs/12-globals-reference.md (line 2759): mentions vtable PTR_FUN_005ac3e0 set here — "Audio/listener object"
**Issues found:** triage category `math_util` wrong; actual doc in 12-globals contradicts triage
**Details:** 53-byte constructor: sets vtable to PTR_FUN_005ac3e0, calls FUN_00485e30(), zeroes +0x38/+0x3a, sets +0x39/+0x3b=0xffffffff, calls FUN_00566650(0). Described in 12-globals as "Audio/listener object" constructor. `math_util` triage is incorrect. Suggested: `constructor` or `audio_init`.

---

### FUN_004B1990 — result
**Current doc:** 
- docs/decompiled_full_index_final.md (line 2421): triage — `| 0x004b1990 | 6 | math_util | arithmetic/comparison | no | -- |`
- docs/12-globals-reference.md (line 3136): vtable PTR_LAB_005acbcc — "UI widget/element class" set in constructors INCLUDING FUN_004B1990
- docs/19-renderer.md (line 4483): "control constructor function for UI element types"
- docs/31-call-chains/0136: CreateControlTypeC leaf
**Issues found:** triage category `math_util` completely wrong
**Details:** 26-byte constructor: sets param_1[1]=0, param_1[2]=0xffffffff, param_1[3]=0, param_1[4]=0xffffffff, vtable=PTR_LAB_005acbcc. Documented elsewhere as UI control type C constructor. `math_util/arithmetic` is incorrect. Suggested: `constructor` or `ui_control_ctor`.

---

### FUN_004D88B0 — result
**Current doc:** docs/decompiled_full_index_final.md (line 3030): triage — `| 0x004d88b0 | 5 | math_util | arithmetic/comparison | no | -- |`
**Issues found:** none (triage-only)
**Details:** 32-byte fastcall. If *param_1 != -1: calls vtable dispatch on param_1[*param_1+4] via offset +0x14; if result==1 sets *param_1=-1. State machine / iterator advancement pattern. `math_util` is borderline — the -1 sentinel test is an arithmetic check but the function is a stateful iterator step. Reasonable triage as-is.

---

### FUN_005122B2 — result
**Current doc:** docs/decompiled_full_index_final.md (line 3721): triage — `| 0x005122b2 | 7 | unknown | unidentified logic | no | -- |`
**Issues found:** none (triage-only)
**Details:** 103-byte function. Checks param_1, param_2, *(param_2+8)&0x10. Branches on *(param_2+0x19)==3 vs other. Returns 0 or 0x10. Writes param_3, param_4, param_5. Cited in docs/24-enum-catalog.md for enum values. Unknown purpose — triage as `unidentified logic` is acceptable.

---

### FUN_0054E0F0 — result
**Current doc:** docs/decompiled_full_index_final.md (line 4383): triage — `| 0x0054e0f0 | 2 | math_util | short computation | no | -- |`
**Issues found:** triage category `math_util` wrong
**Details:** 10-byte wrapper: calls FUN_00540da0(). Referenced in docs/19-renderer.md (lines 3643, 4194, 4212) as "resource init/free" and paired with FUN_0054e0e0 for "enter/leave transform". In docs/06-session-race-logic.md (line 6675) as "state restore". Not math — likely resource state push/pop. Suggested: `state_restore` or `resource_wrapper`.

---

### FUN_0050C5BD — result
**Current doc:** docs/decompiled_full_index_final.md (line 7303): triage — `| 0x0050c5bd | 14 | thunk | trampoline to thunk_FUN_0050c5b0 | no | -- |`
**Issues found:** none
**Details:** 6-byte thunk (indirect jump through PTR_FUN_005d77f0). Correctly classified as `thunk/trampoline`. No validation needed.

---

### FUN_00464AE0 — result
**Current doc:** docs/decompiled_full_index_final.md (line 1329): triage — `| 0x00464ae0 | 12 | math_util | short computation | no | -- |`
- docs/31-call-chains/0112: "Byte sign + compare [leaf]"
**Issues found:** none (triage-only)
**Details:** 35-byte thiscall: checks if signed byte at param_2+param_1 < 0; returns param_2&0xffffff00 if negative, else (param_3 <= byte&0x7f). Bit-level byte test. `math_util/short computation` is acceptable.

---

### FUN_0053D890 — result
**Current doc:** docs/decompiled_full_index_final.md (line 4126): triage — `| 0x0053d890 | 2 | math_util | short computation | no | -- |`
- docs/31-call-chains/0031: "Indexed Pointer Accessor (+0xc + param_2*0x43c)"
- docs/24-enum-catalog.md: stride 0x43c, header offset 0xc
**Issues found:** none (triage-only; well-documented in call chains + enum catalog)
**Details:** 27-byte thiscall: bounds-checked pointer accessor — if param_2 < *(param_1+8) returns param_1 + 0xc + param_2*0x43c, else 0. Stride 0x43c (1084 bytes). Correctly described in call chains. Triage `short computation` is OK.

---

### FUN_0059927C — result
**Current doc:** 
- docs/decompiled_full_index_final.md (line 5773): triage — `| 0x0059927c | 16 | math_util | -- | no | -- |`
- docs/decompiled_full_index_final.md (line 6965): re-triage — `| 0x0059927c | 15 | Locale/Dtor | Locale destructor with conditional free | Locale dtor | |`
**Issues found:** re-triage (line 6965) is more accurate
**Details:** 28-byte thiscall: calls FUN_00598aea(), if param_2&1 calls FUN_00587bcf(param_1). Conditional destructor pattern. Re-triage as `Locale/Dtor` plausible. No full entry to validate.

---

### FUN_0045B5C0 — result
**Current doc:** docs/decompiled_full_index_final.md (line 1168): triage — `| 0x0045b5c0 | 32 | math_util | float computation | no | -- |`
- docs/31-call-chains/0233: "Array Max Computation" with 4 callees
- docs/17-physics-collision.md (line 1859): "interpolant from FUN_0045b5c0"
**Issues found:** none (triage-only; well-documented in call chain 0233)
**Details:** 148-byte fastcall. Loops via FUN_0045bb00/get count, calls FUN_0045b580 per element, calls FUN_00456040 + FUN_004dd400, tracks max in local_14. Array max computation on transformed values. Triage `float computation` is adequate.

---

### FUN_0047EB30 — result
**Current doc:** docs/decompiled_full_index_final.md (line 1672): triage — `| 0x0047eb30 | 16 | math_util | short computation | no | -- |`
**Issues found:** triage `math_util` wrong
**Details:** 51-byte thiscall destructor: if *(param_1+0xec) non-null, calls FUN_00587bcf on it; calls FUN_00488b30(); if param_2&1 calls FUN_00587bcf(param_1). Return param_1. Deinit/destructor pattern with member free + base destructor call. Suggested: `destructor` or `deinit`.

---

### FUN_0049A270 — result
**Current doc:** docs/decompiled_full_index_final.md (line 2166): triage — `| 0x0049a270 | 18 | math_util | short computation | no | -- |`
- docs/06-session-race-logic.md (line 14810): "memory pool release" — calls FUN_0049a270
**Issues found:** triage `math_util` wrong
**Details:** 52-byte fastcall. Checks param_1[4], param_1[2], *param_1 for non-null; calls FUN_00587bcf on each. Triple free/delete pattern. Described in session-race-logic as "memory pool release". Suggested: `destructor` or `free_helper`.

---

### FUN_004C5C80 — result
**Current doc:** docs/decompiled_full_index_final.md (line 2795): triage — `| 0x004c5c80 | 6 | math_util | arithmetic/comparison | no | -- |`
- docs/08-file-formats.md (lines 838, 1279): "filter match" / "filter node creator"
- docs/31-call-chains/0185: "Filter Match — creates linked list node"
**Issues found:** triage `math_util` wrong
**Details:** 48-byte thiscall constructor: param_1[1]=0, param_1[2]=0xffffffff, *param_1=param_2, calls FUN_00566650(param_3), calls FUN_004c5cb0(). Scene filter match node creator per 08-file-formats and call chains. Suggested: `constructor` or `scene_filter_node`.

---

### FUN_0050415C — result
**Current doc:** docs/decompiled_full_index_final.md (line 3459): triage — `| 0x0050415c | 28 | unknown | unidentified logic | no | -- |`
- docs/31-call-chains/0217: "[undocumented leaf]"
**Issues found:** none (triage-only)
**Details:** 289-byte fastcall. Complex pixel blending loop: iterates over pixel arrays with stride-based offsets, performs RGB channel blending with arithmetic shifts + masks (0xffff00f0, 0xf0f, +0x20, +0x202). Image compositing/blending function. Triage `unidentified logic` is acceptable but could be improved to `image_processing/blend`.

---

### FUN_0053CAF0 — result
**Current doc:** docs/decompiled_full_index_final.md (line 4101): triage — `| 0x0053caf0 | 4 | unknown | utility function | no | -- |`
- docs/06-session-race-logic.md (line 11868): calls FUN_0053caf0 with child/attachment pointer
**Issues found:** none (triage-only)
**Details:** 38-byte function: calls FUN_00547420(); if param_1!=0 calls FUN_00557470() + FUN_00587bcf(param_1). Returns 0. Release pattern similar to FUN_0053cb90 but with extra FUN_00547420 call. Triage `utility function` is fine.

---

### FUN_0058DCB5 — result
**Current doc:** 
- docs/decompiled_full_index_final.md (line 5496): triage — `| 0x0058dcb5 | 12 | math_util | -- | no | -- |`
- docs/decompiled_full_index_final.md (line 7605): re-triage — `| 0x0058dcb5 | 12 | unknown | empty void stub — no-op | no | -- |`
**Issues found:** none
**Details:** 23-byte function: empty with just return. Verified: no-op. Re-triage correctly identifies as no-op stub.

---

### FUN_00587F59 — result
**Current doc:** 
- docs/decompiled_full_index_final.md (line 5318): triage — `| 0x00587f59 | 13 | math_util | -- | no | -- |`
- docs/decompiled_full_index_final.md (line 6756): re-triage — `| 0x00587f59 | 12 | Dispatch | Single function call wrapper | Func call | |`
- docs/31-call-chains/0119: "Single Function Call Wrapper (atoi)"
- docs/08-file-formats.md (line 511): parses `Session` as int via FUN_00587f59
- docs/21-audio-network-internals.md (line 1822): port parse wrapper
**Issues found:** none (triage-only; well-documented in call chains)
**Details:** 11-byte function: calls FUN_00587ece(param_1). atoi wrapper per call chain 0119. Re-triage as `Dispatch/Func call` correct.

---

### FUN_0055C440 — result
**Current doc:** 
- docs/decompiled_full_index_final.md (line 4648): triage — `| 0x0055c440 | 12 | math_util | -- | no | -- |`
- docs/decompiled_full_index_final.md (line 7608): re-triage — `| 0x0055c440 | 12 | unknown | stub returning 0 | no | -- |`
**Issues found:** none
**Details:** 5-byte function: `return 0;`. Verified: constant-zero stub. Re-triage correctly identifies as stub.

---

### FUN_005123E0 — result
**Current doc:** docs/decompiled_full_index_final.md (line 3728): triage — `| 0x005123e0 | 13 | unknown | unidentified logic | no | -- |`
- docs/20-math-utilities.md (line 262): "pixel format conversion RGB↔BGR (FUN_005123e0)"
**Issues found:** triage `unidentified logic` outdated; docs/20 identifies as pixel format conversion
**Details:** 191-byte function. Swaps byte pairs in buffer (R↔B channel swap) based on mode bits at param_1+2 and bits per pixel at param_1+9. Handles 2-byte and 6-byte strides for 8-bit and 16-bit pixel formats. Correctly identified in docs/20-math-utilities.md overview as "pixel format conversion RGB↔BGR". Triage should be `image_processing/pixel_swap`.

---

### FUN_004DB9A0 — result
**Current doc:** docs/decompiled_full_index_final.md (line 3066): triage — `| 0x004db9a0 | 6 | unknown | utility function | no | -- |`
- docs/31-call-chains/0129: "Utility Function (Number Format + UI Draw)"
**Issues found:** none (triage-only; described in call chain 0129)
**Details:** 82-byte function: calls __ftol (float-to-int), formats via FUN_0058815f with format string DAT_005c3280, calls FUN_004d7e40 for UI text rendering. Number formatting + UI draw per call chain. Triage `utility function` acceptable.

---

### FUN_004B2420 — result
**Current doc:** docs/decompiled_full_index_final.md (line 2444): triage — `| 0x004b2420 | 7 | math_util | arithmetic/comparison | no | -- |`
- docs/31-call-chains/0045, 0110, 0146: "Orientation Integrator" / "Float-to-Short Conversion"
- docs/18-physics-dynamics.md (line 607): "Updates vehicle rotation matrix"
- docs/08-file-formats.md (line 3525): called during file loading
**Issues found:** triage-only; call chains provide good descriptions
**Details:** 89-byte thiscall. Copies 3 dwords from param_1 to param_2; converts 3 shorts at param_1+3, param_1+0xe, param_1+4 to float via _DAT_0059e77c scaling. Orientation/transform helper for vehicle physics. Triage `arithmetic/comparison` is underspecified but not wrong.

---

### FUN_0048FB70 — result
**Current doc:** docs/decompiled_full_index_final.md (line 1903): triage — `| 0x0048fb70 | 13 | math_util | short computation | no | -- |`
- docs/12-globals-reference.md (line 6175): vtable PTR_FUN_005ac5f0 set here — "Generic object vtable initialization"
**Issues found:** triage `math_util` wrong
**Details:** 38-byte fastcall constructor: calls FUN_00485e30(), sets vtable to PTR_FUN_005ac5f0, zeroes +0x38, sets +0x39=0xffffffff. Generic object constructor per 12-globals. Suggested: `constructor`.

---

### FUN_00463CA0 — result
**Current doc:** docs/decompiled_full_index_final.md (line 1305): triage — `| 0x00463ca0 | 14 | math_util | short computation | no | -- |`
- docs/01-engine-architecture.md (line 75): "timing updates" paired with FUN_004ba180
- docs/24-enum-catalog.md: checks Inactive/stop state
- docs/31-call-chains/0039: called by network update loop
**Issues found:** triage `math_util` wrong
**Details:** 41-byte fastcall: if *(*(param_1)+0x3fc4) != 0, calls FUN_0057a730(0x100) + FUN_0045f710(). Timing/state check function per engine-architecture. Suggested: `timing` or `state_check`.

---

### FUN_004BB0C0 — result
**Current doc:** docs/decompiled_full_index_final.md (line 2636): triage — `| 0x004bb0c0 | 15 | unknown | unidentified logic | no | -- |`
- docs/31-call-chains/0010: "Finish Init — completes vehicle setup"
- docs/31-call-chains/0015: "Get Mesh Data (leaf)"
- docs/31-call-chains/0116, 0194: "unknown [leaf]" / "unknown sub-operation"
**Issues found:** none (triage-only; call chains give conflicting descriptions)
**Details:** 135-byte fastcall. Linked list node removal by value: searches linked list starting at *param_1, matches *piVar4==iVar2, removes node, decrements count at param_1[3], frees associated resource (FUN_004b0170+FUN_00587bcf) and node itself (FUN_00587bcf). Returns matched value. Linked list node removal + resource cleanup. Call chain 0010 says "Finish Init" but code shows removal, not init. Possible discrepancy in call chain description vs actual code.

---

### FUN_004FC910 — result
**Current doc:** docs/decompiled_full_index_final.md (line 3382): triage — `| 0x004fc910 | 7 | unknown | unidentified logic | no | -- |`
- docs/06-session-race-logic.md (line 10466): "compute target position"
**Issues found:** none (triage-only)
**Details:** 132-byte thiscall. Reads 4 ushorts from param_2+8/+10/+0xc/+0xe, scales by _DAT_005ad290 → param_1[0..3]; reads 2 shorts from param_2+0x10/+0x12, scales by _DAT_0059e774 → param_1[4..5]. Position/vector unpack from packed ushorts. Triage `unidentified logic` is okay; could be `data_unpack/position`.

---

### FUN_0053CB90 — result
**Current doc:** docs/decompiled_full_index_final.md (line 4103): triage — `| 0x0053cb90 | 4 | unknown | utility function | no | -- |`
- docs/13-audit-report.md (line 3602): resource handle release at +0x64
- docs/31-call-chains/0097: "Resource release utility" [leaf]
**Issues found:** none (triage-only; well-described in call chain 0097 + audit report)
**Details:** 38-byte function: calls FUN_00542e50(); if param_1!=0 calls FUN_00557470()+FUN_00587bcf(param_1). Returns 0. Audio resource handle release. Triage `utility function` acceptable.

---

### FUN_0059870C — result
**Current doc:** 
- docs/decompiled_full_index_final.md (line 5734): triage — `| 0x0059870c | 13 | math_util | -- | no | -- |`
- docs/decompiled_full_index_final.md (line 7620): re-triage — `| 0x0059870c | 13 | unknown | thunk to FUN_00598b5d(0,1) | no | -- |`
**Issues found:** none
**Details:** 15-byte function: calls FUN_00598b5d(0,1). Thunk/wrapper. Re-triage correct.

---

### FUN_0058C0D0 — result
**Current doc:** 
- docs/decompiled_full_index_final.md (line 5464): triage — `| 0x0058c0d0 | 18 | math_util | -- | no | -- |`
- docs/decompiled_full_index_final.md (line 6828): re-triage — `| 0x0058c0d0 | 17 | String/Edit | Shift string content by offset | String shift | |`
- docs/20-math-utilities.md (line 274): listed among string utilities
**Issues found:** none (triage-only)
**Details:** 37-byte function: if param_2!=0, calls _strlen then FUN_0058b130 to shift string content by param_2 offset. String shift operation. Re-triage `String/Edit` correct. Initial `math_util` wrong.

---

### FUN_00406B80 — result
**Current doc:** docs/decompiled_full_index_final.md (line 174): triage — `| 0x00406b80 | 16 | math_util | short computation | no | -- |`
**Issues found:** triage `math_util` wrong
**Details:** 30-byte thiscall destructor: calls FUN_00406ba0(); if param_2&1 calls FUN_00587bcf(param_1). Returns param_1. Destructor pattern (call base dtor + conditional free). Suggested: `destructor`.

---

### FUN_004685F0 — result
**Current doc:** docs/decompiled_full_index_final.md (line 1387): triage — `| 0x004685f0 | 13 | math_util | short computation | no | -- |`
**Issues found:** triage `math_util` wrong
**Details:** 30-byte thiscall destructor: calls FUN_00468610(); if param_2&1 calls FUN_00587bcf(param_1). Returns param_1. Same destructor pattern as FUN_00406B80. Suggested: `destructor`.

---

### FUN_0048E5C0 — result
**Current doc:** docs/decompiled_full_index_final.md (line 1879): triage — `| 0x0048e5c0 | 23 | unknown | unidentified | no | -- |`
**Issues found:** none (triage-only)
**Details:** 57-byte fastcall. Calls vtable dispatch at param_1[0]+0xa0; if result==0, reads param_1[0x3a..0x3d] and calls FUN_00490920 + FUN_004918d0 with those args. State-dependent dispatch with 4 integer parameters. Purpose unclear — could be renderer or audio callback dispatch. Triage `unidentified` acceptable.

---

### FUN_004B1A30 — result
**Current doc:** docs/decompiled_full_index_final.md (line 2426): triage — `| 0x004b1a30 | 6 | math_util | arithmetic/comparison | no | -- |`
- docs/19-renderer.md (line 4483): "control constructor functions for different UI element types" — type G
- docs/12-globals-reference.md (line 6219): vtable PTR_LAB_005acc50 — "Input device object vtable"
- docs/31-call-chains/0136: "CreateControlTypeG [vtable init with defaults, shorter] [leaf]"
**Issues found:** triage `math_util` wrong; doc descriptions in 19-renderer and 12-globals contradict each other
**Details:** 26-byte constructor: param_1[1]=0, param_1[2]=0xffffffff, param_1[3]=0, param_1[4]=0xffffffff, vtable=PTR_LAB_005acc50. 19-renderer says "UI element type G control constructor" but 12-globals says vtable is "Input device object". Either the vtable serves dual purpose or one doc is wrong. Cross-reference needed.

---

### FUN_004D9030 — result
**Current doc:** docs/decompiled_full_index_final.md (line 3036): triage — `| 0x004d9030 | 20 | unknown | unidentified logic | no | -- |`
- docs/12-globals-reference.md: manages audio emitter pointers DAT_008ad398–DAT_008ad3a8 and track DB pointer DAT_008ad3ac
**Issues found:** none (triage-only; 12-globals provides context)
**Details:** 139-byte function. Switch on param_1 (1–5): selects from DAT_008ad398–DAT_008ad3a8 array, if non-null calls FUN_005539f0 and nulls. If param_1==3 additionally frees DAT_008ad3ac via FUN_005502c0+FUN_00557470+FUN_00587bcf. Audio emitter + track DB cleanup. 12-globals describes it as emitter lifecycle management. Suggested: `audio_emitter_cleanup`.

---

### FUN_005125C9 — result
**Current doc:** docs/decompiled_full_index_final.md (line 3732): triage — `| 0x005125c9 | 18 | unknown | unidentified logic | no | -- |`
- docs/24-enum-catalog.md (line 605): source evidence for an enum
**Issues found:** none (triage-only)
**Details:** 272-byte function. Bit unpacker: reads packed bitstream from param_2, extracts bits of width 1, 2, or 4 (controlled by bVar2). Writes unpacked bytes to output. Sets param_1[1] to total bytes processed. Bitstream decoder — likely texture/vertex data decompression. Triage `unidentified logic` acceptable but could be `bitstream_decode`.

---

### FUN_00550870 — result
**Current doc:** 
- docs/decompiled_full_index_final.md (line 4464): triage — `| 0x00550870 | 23 | unknown | -- | no | -- |`
- docs/decompiled_full_index_final.md (line 7419): re-triage — `| 0x00550870 | 23 | math_util | Init struct to 0, set param_1[1]=1.0f (0x3f800000) | no | -- |`
**Issues found:** none (triage-only)
**Details:** 47-byte fastcall constructor: calls FUN_0053c2a0(), zeroes param_1[0..7], sets param_1[1]=0x3f800000 (1.0f). Struct initializer with float 1.0 default. Re-triage `math_util` acceptable.

---

### FUN_00552FF0 — result
**Current doc:** 
- docs/decompiled_full_index_final.md (line 4503): triage — `| 0x00552ff0 | 30 | unknown | -- | no | -- |`
- docs/decompiled_full_index_final.md (line 6299): re-triage — `| 0x00552ff0 | 29 | Data/ParamSet | Switch-based parameter field set with flags | Param set | |`
- docs/24-enum-catalog.md: "MixerChannelMode" — switch with 5 cases (0=0xBF left, 1=0x7F right, 2=0x3F stereo, 3=0 mute, 4=0xFF full)
**Issues found:** none (triage-only; well-documented in enum catalog)
**Details:** 73-byte thiscall: sets param_1+0x54=param_2; switch(param_3) with 5 cases setting param_1+0x58 to 0xBF, 0x7F, 0x3F, 0, 0xFF. Audio mixer channel mode setter. Re-triage `Data/ParamSet` and enum catalog `MixerChannelMode` correct.

---

### FUN_0040EEC0 — result
**Current doc:** docs/decompiled_full_index_final.md (line 306): triage — `| 0x0040eec0 | 35 | math_util | short computation | no | -- |`
- docs/31-call-chains/0187: "[position helper]"
- docs/23-gap-analysis.md: switch jump table at 0x0040eec0 with 8 pointers
**Issues found:** none (triage-only)
**Details:** 146-byte thiscall. Takes float param_2[0..6], converts some to double. Switch on *(param_1+0x1c) cases 0–5: calls FUN_00459950(scalar, vector) + FUN_00459990(3 floats). Position/distance computation with spatial query fallback. Triage `short computation` undersized — 146 bytes. Suggested: `spatial_query` or `position_transform`.

---

### FUN_0046E6F0 — result
**Current doc:** docs/decompiled_full_index_final.md (line 1440): triage — `| 0x0046e6f0 | 18 | math_util | short computation | no | -- |`
- docs/24-enum-catalog.md (line 6054): allocation size 0x2c (44)
**Issues found:** triage `math_util` wrong
**Details:** 40-byte fastcall. Virtual alloc: calls vtable at (param_1+0x40)[0]+0x1c with arg 0x2c; if non-null calls FUN_00489920(), then FUN_0046e5c0 on result. UI widget allocator. Triage `math_util` incorrect. Suggested: `allocator` or `widget_alloc`.

---

### FUN_00490660 — result
**Current doc:** docs/decompiled_full_index_final.md (line 1928): triage — `| 0x00490660 | 36 | unknown | unidentified | no | -- |`
**Issues found:** none (triage-only)
**Details:** 118-byte fastcall. Calls FUN_00486720(). If 2<result<6, sets local_4=1. Loops 0..(param_1+0xec)-1: traverses linked list at param_1+0xe0, calls vtable dispatch at *node[0]+0x10(local_4). UI panel/widget dispatch based on mode state. Triage `unidentified` acceptable; could be `ui_panel_dispatch`.

---

### FUN_004B2B60 — result
**Current doc:** docs/decompiled_full_index_final.md (line 2467): triage — `| 0x004b2b60 | 2 | math_util | short computation | no | -- |`
- docs/31-call-chains/0123: "15-bit Field Setter — writes 15-bit value at +0x30"
- docs/20-math-utilities.md (line 290): listed among bit operations
**Issues found:** none (triage-only; well-documented in call chain 0123)
**Details:** 23-byte thiscall: `*(param_1+0x30) = *(param_1+0x30) & 0xffc07fff | param_2 << 0xf`. 15-bit field insert at bits 15–29 of word at +0x30. Triage `short computation` acceptable.

---

### FUN_004DCD10 — result
**Current doc:** docs/decompiled_full_index_final.md (line 3093): triage — `| 0x004dcd10 | 7 | unknown | utility function | no | -- |`
- docs/01-engine-architecture.md (lines 4391, 4394): called by engine init
**Issues found:** none (triage-only)
**Details:** 66-byte fastcall: if param_1[1]!=0 calls FUN_005502c0()+FUN_00557470()+FUN_00587bcf; if *param_1!=0 calls FUN_005539f0; calls FUN_004dcb70(). Cleanup function freeing two resources (sound emitter + data ptr). Triage `utility function` acceptable.

---

### FUN_0051664F — result
**Current doc:** docs/decompiled_full_index_final.md (line 3792): triage — `| 0x0051664f | 8 | unknown | unidentified logic | no | -- |`
**Issues found:** triage byte count wrong (291 bytes, not 8)
**Details:** 291-byte complex function. Buffer management with bounds checks: validates region params against buffer limits, updates write position (param_2[6], param_2[7]), does per-element processing via FUN_005159a8. Returns computed pointer. Data streaming/buffer writing function. Triage `8` bytes is a metadata error (should be 291). Suggested: `buffer_write` or `stream_output`.

---

### FUN_005573F0 — result
**Current doc:** 
- docs/decompiled_full_index_final.md (line 4585): triage — `| 0x005573f0 | 14 | math_util | -- | no | -- |`
- docs/decompiled_full_index_final.md (line 7570): re-triage — `| 0x005573f0 | 14 | unknown | calls FUN_0053b160() and FUN_004b0170() | no | -- |`
**Issues found:** none (triage-only)
**Details:** 19-byte function: calls FUN_0053b160() + FUN_004b0170(). Two-step cleanup sequence. Re-triage `unknown` acceptable.

---

### FUN_0055D3F0 — result
**Current doc:** 
- docs/decompiled_full_index_final.md (line 4672): triage — `| 0x0055d3f0 | 13 | math_util | -- | no | -- |`
- docs/decompiled_full_index_final.md (line 6390): re-triage — `| 0x0055d3f0 | 12 | Data/BitExtract | Byte extraction from uint | Bit extract | |`
**Issues found:** none (triage-only)
**Details:** 32-byte function: calls FUN_0055d320(param_1, (param_2>>16)&0xff, (param_2>>8)&0xff, param_2&0xff). Decomposes a uint32 into 3 bytes (R, G, B). Color channel extraction. Re-triage `Data/BitExtract` correct.

---

### FUN_00414370 — result
**Current doc:** docs/decompiled_full_index_final.md (line 370): triage — `| 0x00414370 | 15 | math_util | short computation | no | -- |`
- docs/08-file-formats.md (line 1325): free helper
- docs/01-engine-architecture.md (lines 4133, 21211, 21216): deinit function called many times
- docs/06-session-race-logic.md (lines 8505–8514): hundreds of calls for timer cleanup
- docs/31-call-chains/0185: "[free helper]"
**Issues found:** triage `math_util` wrong
**Details:** 14-byte fastcall: if *param_1!=0 calls FUN_00587bcf(*param_1). Frees pointer pointed to by param_1. Heavily used as timer cleanup callback. `math_util` is completely wrong. Suggested: `free_helper` or `cleanup_callback`.

---

### FUN_00473ED0 — result
**Current doc:** docs/decompiled_full_index_final.md (line 1512): triage — `| 0x00473ed0 | 20 | math_util | short computation | no | -- |`
**Issues found:** triage `math_util` wrong
**Details:** 115-byte fastcall constructor: calls FUN_00466d60(1), sets vtable to PTR_FUN_005a3300, sets param_1[199]=DAT_007cfd10, initializes multiple fields including 0x181 (385) at param_1[0xcd]. Calls FUN_00486f30 twice, FUN_004670e0(). Render/UI config object constructor per 24-enum-catalog (line 5938: value 0x181). Suggested: `constructor` or `ui_config_ctor`.

---

### FUN_00495140 — result
**Current doc:** docs/decompiled_full_index_final.md (line 2000): triage — `| 0x00495140 | 9 | math_util | short computation | no | -- |`
**Issues found:** none
**Details:** 6-byte function: returns DAT_007cde20. Global value accessor. `math_util/short computation` is acceptable as a trivial read.

---

### FUN_004BA830 — result
**Current doc:** docs/decompiled_full_index_final.md (line 2619): triage — `| 0x004ba830 | 16 | unknown | unidentified logic | no | -- |`
- docs/10-vehicle-physics.md (line 1621): "object query"
- docs/31-call-chains/0010: "Object Query — query vehicle object state"
- docs/31-call-chains/0015: "(leaf)"
- docs/31-call-chains/0194: "Linked List Node Removal [leaf]"
**Issues found:** call chains give conflicting descriptions
**Details:** 130-byte thiscall. Linked list node removal by key (param_2): searches list, removes matching node, updates head/tail/count, optionally frees associated resource if param_3!=0. Returns 1 on success. Documentation conflict: call chain 0010 says "Object Query" but code shows list removal; call chain 0194 says "Linked List Node Removal" which matches code. "Object Query" description is wrong.

---

### FUN_004F6BC0 — result
**Current doc:** docs/decompiled_full_index_final.md (line 3311): triage — `| 0x004f6bc0 | 11 | math_util | arithmetic/comparison | no | -- |`
**Issues found:** none (triage-only)
**Details:** 34-byte fastcall: zeroes 18 dwords in structured pattern (5 iterations of 3 dwords + head/tail). Initializer. Triage `arithmetic/comparison` underspecified. Suggested: `struct_init/zero`.

---

### FUN_0052E060 — result
**Current doc:** docs/decompiled_full_index_final.md (line 3979): triage — `| 0x0052e060 | 2 | math_util | short computation | no | -- |`
**Issues found:** none
**Details:** 12-byte function: calls FUN_00587b3e(&LAB_0052e070). Wrapper. Triage `short computation` acceptable as trivial call.

---

### FUN_0057B680 — result
**Current doc:** 
- docs/decompiled_full_index_final.md (line 5055): triage — `| 0x0057b680 | 16 | math_util | -- | no | -- |`
- docs/decompiled_full_index_final.md (line 7462): re-triage — `| 0x0057b680 | 16 | unknown | 16-byte struct copy (4 dwords) | no | -- |`
**Issues found:** none
**Details:** 29-byte thiscall: copies 4 dwords from param_2 to param_1. 16-byte struct copy. Re-triage `16-byte struct copy` correct.

---

## Summary

| Count | Finding |
|-------|---------|
| 55 | No `## FUN_` header entries in any docs/ file |
| 21 | Triage category `math_util` is inaccurate (should be constructor/destructor/allocator/free) |
| 4 | Triage category `math_util` borderline (acceptable for simple ops) |
| 5 | Triage metadata or byte-count errors |
| 2 | Cross-documentation contradictions (FUN_004B1A30, FUN_004BA830) |
| 1 | Call chain description contradicts actual code (FUN_004BB0C0: "Finish Init" vs list removal; FUN_004BA830: "Object Query" vs list removal) |
| 0 | Actual doc entry discrepancies (no full entries exist to validate) |
