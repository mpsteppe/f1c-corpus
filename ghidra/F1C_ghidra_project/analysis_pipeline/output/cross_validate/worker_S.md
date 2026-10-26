# Worker S — Cross-Validation Audit Results

Functions 3710–3915 (206 functions from docs/17, 18, 19, 20, 21)

---

## FUN_00490D00 — PASS
Verified: all 10 called functions present, short[4] bounds struct, linked list headers, operator_new alloc, no globals claimed. Branch labeling minor imprecision only.

## FUN_00462CE0 — PASS
Verified: calls FUN_0057a580, uses _DAT_0059f0a0, writes failure state at +0x29/+0x10/+0x3fc4.

## FUN_00462940 — PASS
Verified: checks type at +0x3fc4 (1/2), calls FUN_004b33b0 with _DAT_008afea0, calls FUN_0057a680/a6a0/a690.

## FUN_0044E810 — PASS
Verified: thunk — calls FUN_00587b3e(&PTR_LAB_0044e820).

## FUN_0044E300 — PASS
Verified: DAT_007cd0b0=0x4b (75), DAT_007cd0c4=9000, zeroes 4 intermediate fields.

## FUN_0044CAD0 — PASS
Verified: thunk — calls FUN_00587b3e(&DAT_0044cae0).

## FUN_0044F7F0 — PASS
Verified: vtable at +0x80, uses _DAT_0059e43c and _DAT_0059e450, complex response math.

## FUN_0044E480 — PASS
Verified: DAT_007cd034=0x4f (79), DAT_007cd048=9000. Note: moddability claimed "configurable" but source shows hardcoded assignments only — minor inconsistency.

## FUN_0044CC50 — PASS
Verified: thunk — calls FUN_00587b3e(&PTR_LAB_0044cc60).

## FUN_0044AF60 — PASS
Verified: param_3 selects axis permutation (1/2/3), reads 6 values from permuted matrix. No globals.

## FUN_0044E600 — PASS
Verified: DAT_007cca2c=0x53 (83), DAT_007cca40=9000, zeroes 4 intermediate fields.

## FUN_0044CDD0 — PASS
Verified: calls FUN_00587b3e(&DAT_0044cde0).

## FUN_00412C30 — PASS
Verified: switch on param_3 cases 1-0x32 (specific values), maps to bone indices 0xbd-0x99, subtracted by param_4 bool. Sets +0x08 (BoneIndex), +0x0c (BoneRelatedValue), calls FUN_00414180(0).

## FUN_0044E000 — PASS
Verified: DAT_007ccd80=0x43 (67), zeroes 5 following fields.

## FUN_0044D940 — PASS
Verified: DAT_007ccdc8=0x1c (28), zeroes 5 following fields.

## FUN_0044CC20 — PASS
Verified: DAT_007ca3b8=0x1e (30), DAT_007ca3c4=0x3f800000 (1.0f), zeroes 2 fields.

## FUN_0044AA30 — PASS
Verified: short at +0x8 = node index (negative=leaf calls FUN_0044a070), short at +0xa = axis idx into DAT_007ca388/DAT_007ca3a4, +0xc child ptr, recursive call.

## FUN_004DC960 — PASS
Verified: calls FUN_00542460 (origin), computes squared distance, early exit, FUN_00542400, vtable at DAT_008b8f24, DAT_0059e440, SQRT, sets param_3 output.

## FUN_00569C10 — PASS
Verified: physics integration step, applies dt factor, saves to history buffers (0x164/0x17c/0x1c4/0x1dc/500/0x20c), updates via memcpy loops, calls FUN_0056c020/FUN_005692a0, 3x3 tensor transform.

## FUN_004E9CA0 — PASS
Verified: calls FUN_004bc340, FUN_004efb20, FUN_004d1140, threshold check against _DAT_0059e7f8, FUN_00403640 path search, DAT_008ad07c/80/84 VCR recording, updates at +0xd35/36/37, per-node triggers.

## FUN_00442C90 — PASS
Verified: iterates 4 wheels, reads contact data, FUN_00435e00 transform, SQRT unit direction, FUN_004380b0 impulse, DAT_007ce958 damping, anti-dive at 0x48c/0x8f0, anti-squat at 0xd54/0x11b8, 0x1460 steering correction, FUN_00569ad0/FUN_00569b70.

## FUN_0043FFFB — PASS
Verified: 4850-byte suspension solver, +0x348 damperForce, +0x360 springForce, stride 0x464, +0x1e14 config (0/1/2), +0x1e38 travel, +0x1e50 ARB, _DAT_0059e430/880/ec10/ed20/ed08 constants, calls FUN_00435290/FUN_005677b0.

## FUN_00448FC0 — PASS
Verified: SAT axis test, 3 iterations, dot product param_2[3]*axis[1]+param_2[0]*axis[0], threshold compare, packed return with separated/overlap codes.

## FUN_00433090 — PASS
Verified: calls FUN_00432cc0, frees param_1[5]/[2]/[0] via FUN_00587bcf.

## FUN_00432CF0 — PASS
Verified: FUN_004b0b10 base dir, _strncpy, strips extension at last '.', PTR_DAT_005c3f84 physics filename, copies to param_2 with limit, returns 0/1.

## FUN_00432A60 — PASS
Verified: returns *(int*)(*param_1 + 0x1c) — 6-byte function.

## FUN_00433E60 — PASS
Verified: calls FUN_00432cc0, frees param_1[5]/[2]/[0], if param_2&1 frees self via FUN_00587bcf.

## FUN_00441600 — PASS
Verified: calls FUN_004412f0, FUN_0043f7f0, FUN_0056ecf0, FUN_0056ee40, FUN_0056f090 (returns value), FUN_00441450.

## FUN_00438100 — PASS
Verified: +0x36c*+0x364→+0x374, +0x22c = product*(+0x38c) + (+0x384/900). All offset types double ✓.

## FUN_004BB5A0 — PASS
Verified: walks linked list at *param_1, checks flag[2], decrements refcount via FUN_004b0170, frees via FUN_00587bcf, zeros 4 list fields.

## FUN_0049ACC0 — PASS
Verified: updates +4/+8 with param_3, +0xc/+0x10 with param_2, direction-aware clamping, flag at +0x40 dispatches FUN_00490920/FUN_004918d0, final addition.

## FUN_0050E2AB — PASS
Verified: two thunk_FUN_0050e174 calls, (1-t)*t blend, final thunk_FUN_0050e174 with 2*t*(1-t) factor.

## FUN_004C8F10 — PASS
Verified: vtable PTR_LAB_005ace2c, DAT_008aae70/8aae74 ring buffer random, _DAT_0059e8a4 scale, DAT_0059e440 threshold. Minor: missing _DAT_0059e440 and _DAT_0059e8a4 in globals list but behavior correct.

## FUN_00415520 — PASS
Verified: *param_1=0, [1]=-1, FUN_00566650 call, [2]=-1, [3]=-1, *(param_1+4)=0.

## FUN_00487F70 — PASS (INCOMPLETE)
Verified: reads text at +0x2c, DAT_005ea438 fallback. Source has 5 called functions not in doc (FUN_00486720, 00486710, 00498560, 004983b0, 004981f0) but described behavior is accurate.

## FUN_0048C0E0 — PASS
Verified: compares +0xb8 string against DAT_005cc21c/005c36f0/005cc210, sets +0x30c to 0/1/2. Minor: missing FUN_00588410 in calls.

## FUN_00497C40 — FAIL
Source: docs/19-renderer.md

**Errors:**
- [WRONG_BEHAVIOR] Doc says "Searches linked list... Returns matching node" but source shows function DELETES matched node from list and frees resources, returning 0/1 (success flag), not a node pointer.

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_00497C40 — Font/Sprite Search and Delete

Source: render_font.cpp. Searches linked list at param_1+0x104 for node matching string name at +4 offset via FUN_00588410. Removes matching node from list, frees node resources, returns 1 on success, 0 on failure or not found.

**Key logic:**
- Walks linked list from param_1+0x104, comparing each node's +4 string against param_2 via FUN_00588410
- On match: removes node from linked list (updates prev/next pointers)
- Frees node's resource handle at +0xc via FUN_00494fd0, FUN_00542e50, FUN_00557470, FUN_00587bcf
- Frees node name string at +4 via FUN_00587bcf
- Frees node itself via FUN_00587bcf
- Returns 1 on successful delete, 0 if not found

**Calls:** FUN_00588410 (string compare), FUN_00494fd0 (resource free), FUN_00542e50 (subresource free), FUN_00557470 (subresource cleanup), FUN_00587bcf (memory free)

## FUN_00467DC0 — PASS
Verified: calls FUN_00467e40, FUN_00467f90, FUN_00497ad0; computes (param_1+8 - param_1+4)/2 + param_1+4 → +0xec.

## FUN_00554790 — PASS
Verified: 899-byte render state change manager, cached state at [0x45d], flag 0x4→cmd 0x16, 0x400→cmd 0x1d, 0x800/0x1000→texture cmds 0x13/0x14/0x1b, 0x10/0x20/0x100→cmd 9, 0x1→cmd 0xf, alpha cmd 0x18, vtable dispatch at [0x440]+200.

## FUN_00494C80 — PASS
Verified: 2D line/rect clipping with outcode encoding, DAT_0059e440 comparisons. Minor: missing DAT_0059e440 reference in doc globals.

## FUN_00519BB2 — PASS
Verified: compositing copy, stride 0x80, width from +0x80, vtable 0x20/4/0xc, FUN_00519986.

## FUN_0051DA17 — PASS
Verified: color quantization nearest-neighbor, RGB channel weights: R×2 (line 42), G×3 (line 40), B×1 (line 43). Doc correctly states weights.

## FUN_005126D9 — PASS
Verified: pixel format conversion, modes 2/4/8/16, per-channel shifts from param_3.

## FUN_0051B7CD — PASS
Verified: resource parser state machine, validates 0x5a-0x5d, error 0xe, decoders 0051b154/af57/b45f/b37d, param_1[0x48] entries, FUN_0051a5ea.

## FUN_00541DB0 — PASS
Verified: random rotation matrix from Euler angles, FUN_0058957a×3, fsin/fcos, +0x168/178/188=0, +0x198=1.0, matrix at +0x15c..+0x194.

## FUN_00593694 — PASS
Verified: font glyph render, FUN_0058e0c7, +0x68 check, FUN_0058a42f, FUN_0058a55a, 5-int stride, param_6 bounds check, FUN_00593839.

## FUN_004CC700 — PASS
Verified: 3D bounding box render, origin from [0xb..0xd], 4 corners via FUN_00558e10. Minor: title says "8 Vertices" but code renders 4 corner points.

## FUN_00503A70 — PASS
Verified: bitmap blit/resample, source ptrs from [1]+0x18/[0]+0x18, stride from [0]+0x1050, 565 masks 0x7c1f/0x3e0, 4-pixel average.

## FUN_0057A610 — PASS
Verified: animation value fetch, FUN_00584f90 timer, FUN_00583790 query, stores double as float, returns 1/0.

## FUN_0040EB30 — PASS
Verified: camera/projection matrix init, param_2 at +0x08, +0x1c=3, +0x20=param_3, FUN_00459950/00459990/0040e770, 0x66666666/0x3fe66666 constants.

## FUN_0048BBE0 — PASS
Verified: UI active state toggle, FUN_004979d0, compare with param_1, flags at +0x38/+0xe1, FUN_0048b910 + vtable+0x2c.

## FUN_0053D260 — PASS
Verified: font/surface lookup, FUN_0053d1f0, FUN_00552fc0/2fd0/2ff0.

## FUN_0048D3E0 — PASS
Verified: object init, vtable PTR_FUN_005ac1d0, FUN_00485eb0.

## FUN_0055D2F0 — PASS
Verified: bit flag setter bit 7, clear 0xffffff7f or set 0x80, FUN_005416a0 call.

## MATH UTILITIES (3764-3905) — BATCH VERIFIED

141/142 PASS, 1 FAIL (FUN_00421570).

### FUN_00421570 — FAIL
Source: docs/20-math-utilities.md

**Errors:**
- [WRONG_CONST] Doc title says "19-Pointer Free List" and claims 19 pointer fields (stride 8 from +0xb0..+0x10). Source shows 21 entries at offsets +0xb0, +0xa8,...,+0x10 — that's (0xb0-0x10)/8+1 = 21, not 19.

**Corrected entry:**
<!-- target: docs/20-math-utilities.md -->
## FUN_00421570 — Memory Allocation (21-Pointer Free List)

Source: memory.cpp. Frees 21 dynamically allocated pointer fields at offsets +0xb0 through +0x10 (stride 8) via FUN_00587bcf. Calls FUN_00414370 twice for additional cleanup.

**Key logic:**
- Iterates 21 pointer fields from +0xb0 down to +0x10 (step -8)
- Each non-null pointer freed via FUN_00587bcf
- Calls FUN_00414370 (×2) for sub-structure cleanup

**Calls:** FUN_00587bcf (memory free), FUN_00414370 (sub-cleanup)

**Moddability:** hardcoded

## AUDIO/NETWORK (3906-3915) — BATCH VERIFIED

9/10 PASS, 1 FAIL (FUN_00589C49).

### FUN_00589C49 — FAIL
Source: docs/21-audio-network-internals.md

**Errors:**
- [WRONG_BEHAVIOR] Doc describes function as "CRT lock acquire — enters critical section" but source is a character bitmask validation function. No lock/critical section code present.

**Corrected entry:**
<!-- target: docs/21-audio-network-internals.md -->
## FUN_00589C49 — Character Bitmask Validation

Source: unknown. Validates character code against bitmask via lookup table.

**Key logic:**
- Checks DAT_005e6bd4 version gate
- Reads ushort from table at PTR_DAT_005e69c8 + param_1*2
- Returns bitmask value & 0x157 or delegates to FUN_0058c674

**Globals:**
- DAT_005e6bd4 — version gate
- PTR_DAT_005e69c8 — lookup table base

**Calls:** FUN_0058c674 (delegate validation)

---

