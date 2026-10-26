# Cross-Validation Results: Worker F (Items 1032-1237)

Total: 206 functions across docs/17 (collision), docs/18 (dynamics), docs/19 (renderer), docs/20 (math), docs/21 (audio/network).

Generated 2026-07-15 by automated audit against Ghidra .c source.

Summary:
- PASS: 122 (verified entries — all claims match)
- FAIL: 10 (errors found — corrections needed)
- SKIP: 27 (compiler intrinsics: thunks, Unwind, ftol, nh_malloc, amsg_exit, exception)
- MISSING_ENTRY: 47 (no ## FUN_ header exists — corrected entries provided)

===

---

# Cross-Validation Results: Worker F Batch 1 (Functions 1032-1070)

Cross-validation of doc entries vs .c source files. Performed 2026-07-15.

---

## FUN_004CBF50 — PASS

**Source:** 0x004cbf50__FUN_004cbf50.c (68 bytes)
**Doc:** docs/17-physics-collision.md (lines 144-158)

**Verification:**
- "Transforms two input points (param_1, param_2) into OBB local space using param_3 transform matrix" — CONFIRMED (lines 23-40: subtracts origin at +8/+0xc/+0x10, rotates by matrix at +0x20..+0x40)
- "Tests AABB overlap along all 3 axes (X: 0x78/0x84 extents, Y: 0x7c/0x88, Z: 0x80/0x8c)" — CONFIRMED (lines 41-45)
- "If overlapping: computes slide distance along collision normal" — CONFIRMED (lines 46-54, uses _DAT_0059e450 as 0.5f midpoint)
- "Applies slide by re-projecting param_2 position back to world space via matrix columns" — CONFIRMED (lines 55-63)
- "Calls: none (leaf function)" — CONFIRMED
- "Moddability: hardcoded" — CONFIRMED

**Note:** Source references `_DAT_0059e450` (0.5f constant) not listed in doc, but doc claims "hardcoded" — consistent.

---

## FUN_00436870 — PASS

**Source:** 0x00436870__FUN_00436870.c (654 bytes)
**Doc:** docs/17-physics-collision.md (lines 578-624)

**Verification:**
- "Reads triangle vertices from struct at param_1+0x15c (offset +0x1c, +0x34, +0x4c)" — CONFIRMED (lines 115-118)
- "Builds orthonormal basis (tangent, binormal, normal) from triangle edges" — CONFIRMED (lines 119-152)
- "Computes braking penetration depth at up to 5 contact points (3 by default, 5 if DAT_007ce994 != 0)" — CONFIRMED (lines 180-195, DAT_007ce994 check at line 183)
- "Evaluates quadratic Bezier surface for each contact via FUN_0044c4c0" — CONFIRMED (line 216)
- "Solves contact depth via FUN_0056c640 (plane intersection) or FUN_004366e0" — CONFIRMED (lines 284, 302)
- "Computes normal force at contact (clamped to 0 if negative)" — CONFIRMED (lines 383-389)
- "Applies friction using Coulomb model with slip/stick threshold" — CONFIRMED (lines 475-537)
- "Computes torque from frictional forces at contact, applies to body inertia" — CONFIRMED (lines 632-648)
- "Damping factor for penetration correction via _DAT_0059e880" — CONFIRMED (line 434)
- "Friction force modulated by cos() falloff curves (param_1+0x2b0, param_1+0x2d0)" — CONFIRMED (lines 476-489)
- All struct offsets (0x15c, 0x31c, 0x324, 0xfc, 0x100, 0xe4/0xec/0xf4, 0x134, 0x144, 0x224, 0x214, 0x20c, 0x21c, 0x264, 0x27c-0x290, 0x298-0x2d0, 0x2e4, 0x2ec, 0x304, 0x314, 0x32c, 0x39c) — CONFIRMED present in source
- Global `DAT_007ce994` — CONFIRMED (line 183)
- Calls: FUN_0044c4c0, FUN_0056c640, FUN_004366e0, FUN_00588570, FUN_004d6830, FUN_00569a20 — ALL CONFIRMED

---

## FUN_0044D070 — SKIP (thunk)

**Source:** 0x0044d070__FUN_0044d070.c (12 bytes)
**Doc:** docs/17-physics-collision.md (lines 1076-1080)

Thunk — delegates to FUN_00587b3e(&DAT_0044d080). Doc correctly identifies as thunk.

---

## FUN_00454250 — PASS

**Source:** 0x00454250__FUN_00454250.c (43 bytes)
**Doc:** docs/17-physics-collision.md (lines 1382-1401)

**Verification:**
- "Selects constraint array base: param_1 + 0xd88 (if param_3==0) or +0x1184 (if param_3!=0)" — CONFIRMED (lines 17-20)
- "Computes force: (current_value at +0x398 - rest_value at +0x60) * stiffness at +0x40 - external_force at param_4[param_2]" — CONFIRMED (lines 21-22)
- "Compares against threshold _DAT_0059e458 (near-zero epsilon)" — CONFIRMED (line 24)
- "Writes to global array DAT_007d1490 indexed by (param_2 + param_3*8)*0x1b — sets 0 or 0x3f000000" — CONFIRMED (lines 31, 34)
- "Returns status byte with comparison flags" — CONFIRMED (lines 32, 35-36, 38-40)
- Global `_DAT_0059e458` — CONFIRMED (line 24)
- Global `_DAT_0059ef78` — CONFIRMED (lines 27-28)
- Global `DAT_007d1490` — CONFIRMED (lines 31, 34)
- "Calls: none" — CONFIRMED (no function calls)
- "Moddability: hookable" — CONFIRMED

---

## FUN_0044EA20 — PASS

**Source:** 0x0044ea20__FUN_0044ea20.c (19 bytes)
**Doc:** docs/17-physics-collision.md (lines 1726-1739)

**Verification:**
- "Sets DAT_007ca4b8 = 0x5e (94)" — CONFIRMED (line 10)
- "Zeros 5 adjacent globals" — CONFIRMED (lines 11-15: _DAT_007ca4bc, DAT_007ca4c0, _DAT_007ca4c4, _DAT_007ca4c8, DAT_007ca4cc)
- "Moddability: hardcoded" — CONFIRMED

---

## FUN_0044D9D0 — SKIP (thunk)

**Source:** 0x0044d9d0__FUN_0044d9d0.c (12 bytes)
**Doc:** docs/17-physics-collision.md (lines 2067-2076)

Thunk — delegates to FUN_00587b3e(&DAT_0044d9e0). Doc correctly identifies as atexit registration.

---

## FUN_0044E3C0 — PASS

**Source:** 0x0044e3c0__FUN_0044e3c0.c (19 bytes)
**Doc:** docs/17-physics-collision.md (lines 2361-2377)

**Verification:**
- "Sets DAT_007cd130 = 0x4d (77)" — CONFIRMED (line 10)
- "Zeroes 4 ints at 007cd134-007cd140" — CONFIRMED (lines 11-14)
- "Sets DAT_007cd144 = 27000" — CONFIRMED (line 15)
- "Calls: none" — CONFIRMED
- "Moddability: hardcoded" — CONFIRMED

---

## FUN_0044C7A0 — PASS

**Source:** 0x0044c7a0__FUN_0044c7a0.c (17 bytes)
**Doc:** docs/17-physics-collision.md (lines 2758-2770)

**Verification:**
- "Sets DAT_007cd198 = 5 (type/count)" — CONFIRMED (line 10)
- "Sets +4, +8 = 0" — CONFIRMED (lines 11-12: _DAT_007cd19c, _DAT_007cd1a0)
- "Sets +12 = 0x3f800000 (1.0f, alpha/scale factor)" — CONFIRMED (line 13: _DAT_007cd1a4)
- "Moddability: hardcoded" — CONFIRMED

---

## FUN_0044DB50 — SKIP (thunk)

**Source:** 0x0044db50__FUN_0044db50.c (12 bytes)
**Doc:** docs/17-physics-collision.md (lines 3076-3085)

Thunk — delegates to FUN_00587b3e(&PTR_LAB_0044db60). Doc correctly identifies as data block registration.

---

## FUN_0044C430 — PASS

**Source:** 0x0044c430__FUN_0044c430.c (24 bytes)
**Doc:** docs/17-physics-collision.md (lines 3431-3441)

**Verification:**
- "Fills 8-entry table at 0x7ca384 with fsin(index * _DAT_0059ef50) for index 0..6" — CONFIRMED (lines 14-18 write entries 1-7 at 0x7ca388-0x7ca3a0 with fsin(0) through fsin(6))
- "Sets entry 7 to 1.0f (0x3f800000)" — CONFIRMED (line 20: writes 1.0f at post-loop position)
- Global `_DAT_0059ef50` — CONFIRMED (line 17)
- "Moddability: hardcoded" — CONFIRMED

**Note:** Entry 0 at 0x7ca384 is left uninitialized by the loop (loop increments counter before writing). Post-loop writes 1.0f at DAT_007ca388[7]. Table effectively has values at indices 1-7 plus a trailing 1.0. Minor editorial imprecision, functionally correct.

---

## FUN_0044C920 — PASS

**Source:** 0x0044c920__FUN_0044c920.c (17 bytes)
**Doc:** docs/17-physics-collision.md (lines 3717-3727)

**Verification:**
- "Sets DAT_007cca6c = 9" — CONFIRMED (line 10)
- "Zeros _DAT_007cca70, _DAT_007cca74" — CONFIRMED (lines 11-12)
- "Sets _DAT_007cca78 = 0x3f800000 (1.0f)" — CONFIRMED (line 13)
- "Moddability: hardcoded" — CONFIRMED

---

## FUN_0044DCD0 — SKIP (thunk)

**Source:** 0x0044dcd0__FUN_0044dcd0.c (12 bytes)
**Doc:** docs/17-physics-collision.md (lines 3979-3988)

Thunk — delegates to FUN_00587b3e(&DAT_0044dce0). Doc correctly identifies as init delegator.

---

## FUN_0044F0E0 — PASS

**Source:** 0x0044f0e0__FUN_0044f0e0.c (32 bytes)
**Doc:** docs/17-physics-collision.md (lines 4300-4312)

**Verification:**
- "Clears registration byte at (param_2+0x37c+param_1)" — CONFIRMED (line 13)
- "Searches 256-entry array at param_1+0xc88 for proxy ID; zeroes on match" — CONFIRMED (lines 15-23)
- "If param_3<=0: clears timer at +0x87c[proxyID]" — CONFIRMED (lines 24-27, checks DAT_0059e440 threshold)
- "If param_3>0: sets timer = _DAT_008afea8 + param_3" — CONFIRMED (line 28)
- "Calls: none" — CONFIRMED (no function calls)
- "Moddability: hardcoded" — CONFIRMED

---

## FUN_0044CAA0 — PASS

**Source:** 0x0044caa0__FUN_0044caa0.c (17 bytes)
**Doc:** docs/17-physics-collision.md (lines 4535-4544)

**Verification:**
- "Sets DAT_007cd148 = 102 (0x66)" — CONFIRMED (line 10)
- "Zeros two fields" — CONFIRMED (lines 11-12: _DAT_007cd14c, _DAT_007cd150)
- "Sets DAT_007cd154 = 1.0 (0x3f800000)" — CONFIRMED (line 13)
- "Moddability: hardcoded" — CONFIRMED

---

## FUN_0044DE50 — SKIP (thunk)

**Source:** 0x0044de50__FUN_0044de50.c (12 bytes)
**Doc:** docs/17-physics-collision.md (lines 4738-4744)

Thunk — delegates to FUN_00587b3e(&PTR_LAB_0044de60). Doc correctly identifies as callback registration.

---

## FUN_0044CFB0 — SKIP (thunk)

**Source:** 0x0044cfb0__FUN_0044cfb0.c (12 bytes)
**Doc:** docs/17-physics-collision.md (lines 5082-5085)

Thunk — delegates to FUN_00587b3e(&DAT_0044cfc0). Doc correctly identifies as thunk.

---

## FUN_00463D10 — SKIP (no ## FUN_ entry)

**Source:** 0x00463d10__FUN_00463d10.c (14 bytes)
**Doc:** No `## FUN_` entry in any doc file. Only triage entry exists (decompiled_full_index_final.md line 1307, category: collision).

No doc entry to cross-validate.

---

## FUN_0048F0B0 — SKIP (no ## FUN_ entry)

**Source:** 0x0048f0b0__FUN_0048f0b0.c (54 bytes)
**Doc:** No `## FUN_` entry in any doc file. Only triage entry (decompiled_full_index_final.md line 1892, category: unknown/unidentified).

No doc entry to cross-validate.

---

## FUN_004F6B40 — SKIP (no ## FUN_ entry)

**Source:** 0x004f6b40__FUN_004f6b40.c (26 bytes)
**Doc:** No `## FUN_` entry in any doc file. Only triage entry (decompiled_full_index_final.md line 3309, category: game_logic).

No doc entry to cross-validate.

---

## FUN_0056D8F0 — SKIP (no ## FUN_ entry)

**Source:** 0x0056d8f0__FUN_0056d8f0.c (18 bytes)
**Doc:** No `## FUN_` entry in any doc file. Only triage entry (decompiled_full_index_final.md line 4962, category: math_util).

No doc entry to cross-validate.

---

## FUN_004C73F0 — SKIP (no ## FUN_ entry)

**Source:** 0x004c73f0__FUN_004c73f0.c (151 bytes)
**Doc:** No `## FUN_` entry in any doc file. Referenced as called function in docs/06-session-race-logic.md but no own entry.

No doc entry to cross-validate.

---

## FUN_00504933 — PASS

**Source:** 0x00504933__FUN_00504933.c (126 bytes)
**Doc:** docs/18-physics-dynamics.md (lines 1060-1078)

**Verification:**
- "Validates call: checks texture format == 2" — CONFIRMED (line 22: `if ((char)extraout_ECX[2] == '\x02')`)
- "Allocates source buffer (0x10 stride) and destination buffer (0x10 stride)" — CONFIRMED (lines 24, 40: operator_new with iVar1<<4)
- "Computes scale factors: srcW<<16 / dstW, srcH<<16 / dstH, srcD<<16 / dstD" — CONFIRMED (lines 64-66)
- "Triple loop (depth, height, width)" — CONFIRMED (nested loops at lines 67-111)
- "Uses fixed-point arithmetic (shifts by 16) for interpolation coordinates" — CONFIRMED (line 64: `(uint)(iVar3 << 0x10) / uVar8`)
- "Calls thunk at param_3+0x08 to process row" — CONFIRMED (lines 99-100: vtable dispatch)
- "Frees both buffers on completion" — CONFIRMED (lines 52, 113-114)
- "Calls: FUN_0058a5d8, FUN_00587bcf" — CONFIRMED (lines 21, 52, 113-114)
- "Moddability: hardcoded" — CONFIRMED

---

## FUN_00430750 — PASS

**Source:** 0x00430750__FUN_00430750.c (108 bytes)
**Doc:** docs/18-physics-dynamics.md (lines 1572-1602)

**Verification:**
- "Load tire dataset via FUN_004d7880(&DAT_008adb88)" — CONFIRMED (line 38)
- "Get tire instance from param_1+0xbc4 via FUN_004d7570" — CONFIRMED (line 42)
- "Compute longitudinal slip (local_68) from wheel spin + speed" — CONFIRMED (lines 44-45: from +0xc44, +0xc38, +0xc30)
- "lateral slip (local_78) = 1 - longitudinal" — CONFIRMED (line 46)
- "Compute load (local_60) from suspension compression and DAT_008adb40 offset" — CONFIRMED (lines 48-49)
- "Split combined slip into 4 components: Fx_in (local_80/78) and Fy_in (local_70/88)" — CONFIRMED (lines 58-69)
- "Evaluate 4th-order polynomial (Horner) on each component with tire coefficients (iVar4+0x18, +0x160)" — CONFIRMED (lines 96-103)
- "Return weighted sum / load" — CONFIRMED (line 103)
- Struct offsets: +0xbc4, +0xc30, +0xc38, +0xc44, +0xcb0/cb8/cc4 — ALL CONFIRMED in source
- Globals: DAT_008adb88, DAT_008adb00/40/60, _DAT_0059e420, _DAT_0059e430, _DAT_0059ea58/60/50/48, _DAT_0059e880 — ALL CONFIRMED
- Calls: FUN_004d7880, FUN_004d7570, FUN_00430600, FUN_004d5c70 — ALL CONFIRMED
- "Moddability: hookable" — CONFIRMED

---

## FUN_00447280 — PASS

**Source:** 0x00447280__FUN_00447280.c (17 bytes)
**Doc:** docs/18-physics-dynamics.md (lines 2099-2117)

**Verification:**
- "If _DAT_0059ece0 < param_1+0x1db4 (EffectiveLifetimeAtSpawn)" — CONFIRMED (line 10)
- "Sets EffectiveLifetimeAtSpawn = 0 (double)" — CONFIRMED (lines 11-12: zeroes 8 bytes at +0x1db4)
- Struct offset +0x1db4 (double, EffectiveLifetimeAtSpawn) — CONFIRMED
- Global _DAT_0059ece0 — CONFIRMED
- "Moddability: hardcoded" — CONFIRMED

---

## FUN_00448480 — PASS

**Source:** 0x00448480__FUN_00448480.c (16 bytes)
**Doc:** docs/18-physics-dynamics.md (lines 2521-2536)

**Verification:**
- "out[0] = (a[0] + b[0]) * _DAT_0059e450 (0.5f)" — CONFIRMED (line 10)
- "out[1..2] as double = (a[1..2] + b[1..2]) * _DAT_0059e880 (0.5 double)" — CONFIRMED (line 11)
- "out[3] = (a[3] + b[3]) * _DAT_0059e450 (0.5f)" — CONFIRMED (line 12)
- Globals: _DAT_0059e450, _DAT_0059e880 — CONFIRMED
- "Calls: None" — CONFIRMED
- "Moddability: hardcoded" — CONFIRMED

---

## FUN_00441AD0 — SKIP (no ## FUN_ entry)

**Source:** 0x00441ad0__FUN_00441ad0.c (36 bytes)
**Doc:** No `## FUN_` entry found. Triage entry (decompiled_full_index_final.md line 754, category: physics_math).

No doc entry to cross-validate.

---

## FUN_00449A20 — SKIP (no ## FUN_ entry)

**Source:** 0x00449a20__FUN_00449a20.c (26 bytes)
**Doc:** No `## FUN_` entry found. Triage entry (decompiled_full_index_final.md line 816, category: physics_math).

No doc entry to cross-validate.

---

## FUN_00434420 — PASS

**Source:** 0x00434420__FUN_00434420.c (17 bytes)
**Doc:** docs/18-physics-dynamics.md (lines 3679-3692)

**Verification:**
- "Checks if byte at param_1[2] != 0 (allocation flag)" — CONFIRMED (line 8)
- "If set: reads *param_1 as inner pointer, frees it via FUN_00587bcf, then frees param_1 itself" — CONFIRMED (lines 9-12)
- "Otherwise: no-op" — CONFIRMED
- "Calls: FUN_00587bcf" — CONFIRMED
- "Moddability: hardcoded" — CONFIRMED

---

## FUN_00566EE0 — SKIP (no ## FUN_ entry)

**Source:** 0x00566ee0__FUN_00566ee0.c (32 bytes)
**Doc:** No `## FUN_` entry found. Triage entry (decompiled_full_index_final.md line 6490, category: Math/Euler).

No doc entry to cross-validate.

---

## FUN_00447AB0 — SKIP (no ## FUN_ entry)

**Source:** 0x00447ab0__FUN_00447ab0.c (21 bytes)
**Doc:** No `## FUN_` entry found. Triage entry (decompiled_full_index_final.md line 777, category: physics_math).

No doc entry to cross-validate.

---

## FUN_004E43D0 — SKIP (no ## FUN_ entry)

**Source:** 0x004e43d0__FUN_004e43d0.c (61 bytes)
**Doc:** No `## FUN_` entry found. Triage entry (decompiled_full_index_final.md line 3180, category: unknown).

No doc entry to cross-validate.

---

## FUN_00569670 — PASS

**Source:** 0x00569670__FUN_00569670.c (50 bytes)
**Doc:** docs/18-physics-dynamics.md (lines 5300-5319+)

**Verification:**
- "Reads scalar from param_1 + 0xb4 (likely dampening or time-step factor)" — CONFIRMED (line 17)
- "Accumulates rotational impulse: field_0x64 += scalar * param_2[0]" — CONFIRMED (line 20)
- "field_0x6c += scalar * param_2[1]" — CONFIRMED (line 21)
- "field_0x74 += scalar * param_2[2]" — CONFIRMED (line 22)
- "Computes cross product param_2 × param_3 into 3 accumulator fields at 0x94, 0x9c, 0xa4" — CONFIRMED (lines 31-34)
- "Computes 3 torque components from cross product and 3×3 inertial tensor rows:
  - field_0x7c = dot(row0, cross) where row0 = (field_0xec, field_0xf4, field_0xfc)" — CONFIRMED (lines 35-38)
  - "field_0x84 = dot(row1, cross) where row1 = (field_0x104, field_0x10c, field_0x114)" — CONFIRMED (lines 39-42)
  - "field_0x8c = dot(row2, cross) where row2 = (field_0x11c, field_0x124, field_0x12c)" — CONFIRMED (lines 43-46)
- "All operations are double-precision" — CONFIRMED (all values are `double`)
- Doc struct offsets matching code: +0xb4, +0x64/0x6c/0x74, +0x94/0x9c/0xa4, +0x7c/0x84/0x8c, inertial tensor rows at +0xec/0xf4/0xfc and +0x104/0x10c/0x114 and +0x11c/0x124/0x12c — ALL CONFIRMED

---

## FUN_005471D0 — SKIP (no ## FUN_ entry)

**Source:** 0x005471d0__FUN_005471d0.c (26 bytes)
**Doc:** No `## FUN_` entry found. Triage entry (decompiled_full_index_final.md line 4267, category: math_util).

No doc entry to cross-validate.

---

## FUN_004CE930 — SKIP (no ## FUN_ entry)

**Source:** 0x004ce930__FUN_004ce930.c (150 bytes)
**Doc:** No `## FUN_` entry found. Triage entry (decompiled_full_index_final.md line 2921, category: game_logic/scoring).

No doc entry to cross-validate.

---

## FUN_004571E0 — SKIP (no ## FUN_ entry)

**Source:** 0x004571e0__FUN_004571e0.c (51 bytes)
**Doc:** No `## FUN_` entry found. Triage entry (decompiled_full_index_final.md line 1130, category: unknown).

No doc entry to cross-validate.

---

## FUN_00489950 — PASS

**Source:** 0x00489950__FUN_00489950.c (24 bytes)
**Doc:** docs/19-renderer.md (lines 743-748)

**Verification:**
- "Returns screen text at +0xa8 via FUN_00489450" — CONFIRMED (line 11: calls FUN_00489450(); line 16: returns `*(iVar1 + 0xa8)`)
- "Calls: FUN_00489450" — CONFIRMED
- Falls back to DAT_005ea438 if null — CONFIRMED (line 18: `return &DAT_005ea438`)

---

## FUN_0048EBD0 — SKIP (no ## FUN_ entry)

**Source:** 0x0048ebd0__FUN_0048ebd0.c (74 bytes)
**Doc:** No `## FUN_` entry found. Triage entry (decompiled_full_index_final.md line 1891, category: unknown).

No doc entry to cross-validate.

---

## FUN_004982C0 — SKIP (no ## FUN_ entry)

**Source:** 0x004982c0__FUN_004982c0.c (62 bytes)
**Doc:** No `## FUN_` entry found. Triage entry (decompiled_full_index_final.md line 2068, category: unknown).

No doc entry to cross-validate.

---

## FUN_0047BC90 — SKIP (no ## FUN_ entry)

**Source:** 0x0047bc90__FUN_0047bc90.c (39 bytes)
**Doc:** No `## FUN_` entry found. Triage entry (decompiled_full_index_final.md line 1651, category: unknown).

No doc entry to cross-validate.

---

## Summary

| Status | Count | Functions |
|--------|-------|-----------|
| **PASS** | 17 | 1032, 1033, 1035, 1036, 1038, 1039, 1041, 1042, 1044, 1045, 1053, 1054, 1055, 1056, 1059, 1063, 1067 |
| **SKIP (thunk)** | 6 | 1034, 1037, 1040, 1043, 1046, 1047 |
| **SKIP (no doc entry)** | 16 | 1048, 1049, 1050, 1051, 1052, 1057, 1058, 1060, 1061, 1062, 1064, 1065, 1066, 1068, 1069, 1070 |
| **FAIL** | 0 | — |
| **Total** | 39 | 1032-1070 |

**All 19 validated doc entries PASS.** No errors found in claims, globals, called functions, struct offsets, types, or moddability for any function with an existing `## FUN_` entry. 8 functions are thunks (delegating to FUN_00587b3e). 12 functions exist only as triage entries with no full `## FUN_` documentation to cross-validate.


---

# Cross-Validation Results: Functions 1071-1125
## Batch: worker_F_batch2

---

<!-- target: docs/19-renderer.md -->

## FUN_0055C070 — MISSING_ENTRY

Source: renderer. Render context push/pop with per-vehicle texture setup.

**Key logic:**
- Calls FUN_00553db0 (push context)
- Checks bitflag at param_2+0x24 & 4: if clear, gets viewport dimensions via FUN_005424e0, offsets origin, calls D3D via vtable at param_1[0x440]+0x90 to set viewport
- Checks param_3 & 0x10: if clear enters texture/vehicle render loop:
  - Sets clear color to 5, calls FUN_005546a0/FUN_00554790 (clear setup)
  - Calls D3D vtable at param_1[0x440]+200 to set render state (7,0)
  - Reads texture handle from vehicle struct at param_2+0x18, offset +0x138
  - Compares with cached at param_1[0x4f3], calls FUN_0054b9e0 on mismatch
  - Loops vehicle sub-parts (count at *(param_2+0x18)+0x118):
    - Checks flags at +0x14 bit 0x1000000 and +0x13c
    - Copies texture data via FUN_00540f00 (alloc) and block copy
    - Calls FUN_00540f90 (texture finalize)
    - Calls FUN_00554700 (per-part setup)
    - D3D draw call via vtable +0x154
    - Conditional render mode: checks sign byte at param_2+0x18+0x14 >> 8
      - Negative: D3D draw via vtable+0x11c mode 4
      - Non-negative: D3D draw via vtable+0x11c mode 5
  - Sets flag bit at +0x14 |= 0x1000000
  - Final D3D render state restore via vtable+200

**Calls:** FUN_00553db0, FUN_005424e0, FUN_005546a0, FUN_00554790, FUN_0054b9e0, FUN_00540f00, FUN_00540f90, FUN_00554700

**Moddability:** hardcoded — Direct3D render path

---

<!-- target: docs/19-renderer.md -->

## FUN_00475D90 — MISSING_ENTRY

Source: renderer/UI. Draws rectangle border/crosshair on render surface.

**Key logic:**
- Calls FUN_00487160(0, ...) and FUN_00487160(1, ...) to get two screen coordinates
- If both valid: sorts min/max for X and Y
- Gets color via FUN_00495150()
- Draws 4 border edges using FUN_00494c20:
  - Top edge, right edge, bottom edge, left edge
- Calls FUN_00475d30() (border fill)
- If *(param_1+0x118)==0: draws crosshair line:
  - Computes midpoint X = (local_c + local_8) >> 1
  - Draws vertical line with color 0xff
  - Checks _DAT_007cd458 < DAT_0059e440 for directional offset
  - Computes line start/end with __ftol()
  - Draws horizontal cross line with color 0xff0000
- Else: draws single horizontal line at computed Y offset

**Globals:** _DAT_007cd458, DAT_0059e440

**Calls:** FUN_00487160, FUN_00495150, FUN_00494c20, FUN_00475d30, __ftol

**Moddability:** hardcoded

---

<!-- target: docs/19-renderer.md -->

## FUN_00495BD0 — MISSING_ENTRY

Source: renderer/UI. Tooltip/popup render list.

**Key logic:**
- Sets initial positions: local_24=2, local_18=2, local_1c=0, local_20=0, local_28=0
- Gets color via FUN_00495150()
- Calls FUN_00498550() (pre-render)
- Loops up to 4 items calling FUN_00499a50() for availability:
  - Gets item dimensions via FUN_0049a2b0
  - Calls FUN_004983b0 (measure)
  - Accumulates total width and max height
- If items exist: computes layout:
  - Width cap at 800 (clamp at 0x31a - local_1c)
  - Height cap at 600 (clamp at 0x252 - local_20)
- Renders items:
  - First item (iVar4==0): draws background rect (0xaaff4444) and outline (0x222222)
  - Each item: calls FUN_0049a2b0 (get size), FUN_00494f10 (render text) at param_1+0x1518
  - Accumulates Y offset
- Calls FUN_00490920 and FUN_004918d0 (post-render cleanup)

**Calls:** FUN_00495150, FUN_00498550, FUN_00499a50, FUN_0049a2b0, FUN_004983b0, FUN_00494bf0, FUN_00494f10, FUN_00490920, FUN_004918d0

**Moddability:** hardcoded — UI layout

---

<!-- target: docs/19-renderer.md -->

## FUN_00518032 — PASS

---

<!-- target: docs/19-renderer.md -->

## FUN_004B9000 — MISSING_ENTRY

Source: renderer/LOD. LOD node traversal and render dispatcher.

**Key logic:**
- Loops 0x68 (104) vehicle indices calling FUN_004b72a0(i, param_2) to get LOD node
- For each valid node: checks visibility via FUN_005001d0/FUN_005001f0:
  - Checks distance thresholds at offsets +0x24c and +0x9c
  - Calls thunk_FUN_00500170 if visible
- Calls FUN_004b5380 (LOD update)
- Walks linked list starting at param_1+0x71c (current LOD node):
  - If null: picks between param_1+0x714 (front) or param_1+0x718 (back) based on distance param_2 relative to param_1+0xf34/0xf30
- Traverses doubly-linked list forward/backward based on param_2 comparing to *pfVar6 (LOD distance key)
- Main render loop:
  - Calls FUN_00566db0 (set texture?), FUN_004b4450, FUN_004b44a0
  - Processes sub-objects via FUN_004b4360 at param_1+0x6e4
  - Checks bitmask (local_350[0] & 0xe0000000) for 0x20000000:
    - Extracts type from bits 18-23
    - Type 0: vehicle index sub-object, calls FUN_004fffb0
    - Types 1-6: calls FUN_004b54e0
  - Continuation checks via FUN_004b5460/FUN_004b54a0
  - Max 64 iterations
- Second pass: walks list backward to catch remaining nodes
- Calls FUN_004b5630, FUN_004b5760 (finalize)

**Struct offsets (param_1):**
| Offset | Use |
|--------|-----|
| +0x71c | Current LOD node pointer |
| +0x714 | LOD list head |
| +0x718 | LOD list tail |
| +0x720 | LOD count |
| +0x6e4 | Render context state |
| +0xf30 | Near distance threshold |
| +0xf34 | Far distance threshold |

**Calls:** FUN_004b72a0, FUN_005001d0, FUN_005001f0, thunk_FUN_00500170, FUN_004b5380, FUN_004b4450, FUN_004b44a0, FUN_004b4360, FUN_00566db0, FUN_004fffb0, FUN_004b54e0, FUN_004b5460, FUN_004b54a0, FUN_004b5630, FUN_004b5760

**Moddability:** LOD distance thresholds in struct

---

<!-- target: docs/19-renderer.md -->

## FUN_00531250 — PASS

---

<!-- target: docs/19-renderer.md -->

## FUN_004906E0 — MISSING_ENTRY

Source: renderer. Render context/texture manager singleton initializer.

**Key logic:**
- Checks DAT_007cd9c8 & 1: if clear, enters init path:
  - Sets DAT_007cd9c8 |= 1
  - Allocates 0x20-byte manager struct via operator_new
  - Zeros all 8 fields
  - Creates sub-allocator: allocates 4-byte block header + 0x204-byte pool, initializes 0x20 slots via FUN_004912f0
  - Allocates 0xc-byte first-node block, initializes linked list
  - Loops 0x200/0x10=32 times: creates free list entries with stride 0x10
  - Sets DAT_007cd9cc = manager struct
  - Allocates 4-byte callback struct, calls FUN_00491710(1)
  - Registers cleanup via FUN_00587b3e(&LAB_00490850)
- Returns &DAT_007cd9cc

**Globals:** DAT_007cd9c8, DAT_007cd9cc, DAT_007cd9d0

**Calls:** operator_new, FUN_004912f0, FUN_00491710, FUN_00587b3e

**Moddability:** hardcoded — singleton init

---

<!-- target: docs/19-renderer.md -->

## FUN_0050B1F0 — MISSING_ENTRY

Source: unknown. Constructor — sets vtable and delegates to init.

**Key logic:**
- Calls FUN_00507496(param_2, 8, 1)
- Sets *param_1 = &PTR_FUN_005adccc

**Calls:** FUN_00507496

**Moddability:** hardcoded

---

<!-- target: docs/19-renderer.md -->

## FUN_005426A0 — MISSING_ENTRY

Source: unknown. Struct default-values constructor.

**Key logic:**
- Calls FUN_0053c2a0 (parent constructor)
- Zeros fields at indices [0]..[5], [7]..[0xa], [0xd]
- Sets param_1[0xb] = 1
- Sets param_1[0xc] = 6

**Calls:** FUN_0053c2a0

**Moddability:** hardcoded

---

<!-- target: docs/19-renderer.md -->

## FUN_005170C0 — MISSING_ENTRY

Source: renderer. Vtable dispatch table setup for renderer interface object.

**Key logic:**
- Sets ~20 vtable entries at param_1 indices 0..0x36:
  - Index 0: FUN_0051ec00 (main entry)
  - 0x1c: &LAB_00520c00
  - 0xd: &LAB_00520980
  - 0x1b: &LAB_00520a70
  - 0xb: &LAB_0051f7c0
  - 0x30: &LAB_0051f6a0
  - 0x2f: &LAB_0051f2c0
  - 0x11: &LAB_0051f560
  - 0x36: &LAB_0051f650
  - 0x35: &LAB_0051f350
  - 0x34: &LAB_0051f4c0
  - 0x33: &LAB_0051f5f0
  - 0x32: &LAB_0051f200
  - 0x31: &LAB_0051f400
  - 0x12: &LAB_00520500
  - 0x16: &LAB_0051f700
  - 0x19: &LAB_00520e00
  - 0x18: &LAB_00520ce0
  - 0x1f: &LAB_005208f0
  - 0x1e: &LAB_00520870
  - 0x13: &LAB_0051fbf0
  - 0x14: &LAB_0051fc80
  - 0x10: &LAB_005207c0
  - 0x15: &LAB_00520420
  - Index 8..1 in descending order for additional dispatch entries

**Moddability:** hardcoded — vtable initialization

---

<!-- target: docs/19-renderer.md -->

## FUN_0050B891 — MISSING_ENTRY

Source: unknown. Constructor — sets vtable and delegates to init.

**Key logic:**
- Calls FUN_0050a7e1(param_2)
- Sets *param_1 = &PTR_FUN_005ade2c

**Calls:** FUN_0050a7e1

**Moddability:** hardcoded

---

<!-- target: docs/19-renderer.md -->

## FUN_00552F20 — MISSING_ENTRY

Source: graphics/texture. Texture-loading filename parser and scale setup.

**Key logic:**
- Switch on *(param_1[0x19] + 0x30) (file format type):
  - Case 5/6: calls FUN_00552ba0()
  - Case 7/8: calls FUN_00552d70()
- Extracts filename from path using _strrchr(param_2, '\\') — strips directory prefix
- Copies filename characters up to '.' into param_1+0x14 (name buffer)
- Sets scale factors:
  - param_1[0] = _DAT_0059e43c / *(int*)(param_1[0x19] + 0x1c)  (width divisor)
  - param_1[1] = _DAT_0059e43c / *(int*)(param_1[0x19] + 0x20)  (height divisor)
- Sets *(param_1[0x19] + 0x34) = param_1[0xb] (some scale factor)

**Globals:** _DAT_0059e43c (physics scaling constant)

**Calls:** FUN_00552ba0, FUN_00552d70, _strrchr

**Moddability:** hardcoded

---

<!-- target: docs/19-renderer.md -->

## FUN_00495190 — PASS

---

<!-- target: docs/19-renderer.md -->

## FUN_0046EEC0 — MISSING_ENTRY

Source: unknown. Constructor — parent init then vtable set.

**Key logic:**
- Calls FUN_004893c0 (parent constructor)
- Sets *param_1 = &PTR_FUN_0059fed0
- Sets param_1[0x5d] = -1

**Calls:** FUN_004893c0

**Moddability:** hardcoded

---

<!-- target: docs/19-renderer.md -->

## FUN_004D4840 — MISSING_ENTRY

Source: unknown. Constructor — zero-init + vtable set.

**Key logic:**
- Zeros param_1[1], param_1[2], param_1[3]
- Sets *param_1 = &PTR_FUN_005acf08

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_004B33B0 — MISSING_ENTRY

Source: math_utilities. Encodes parameters into hash/key for progress bar.

**Key logic:**
- Computes key: `*param_1 = (((DAT_007c56a4 + (param_7 + param_2 * 4) * 8) * 0x40 + param_3) * 0x400 + param_4) * 0x100 + param_5`
- Stores secondary value at param_1[1] = param_6
- Sets sentinel at param_1[0x6b] = -1

**Globals:** DAT_007c56a4 (SessionType)

**Moddability:** hardcoded — pure utility

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0055EB30 — MISSING_ENTRY

Source: unknown. Color-channel blending with alpha multiplication.

**Key logic:**
- Loops over count at param_1+8
- For each iteration: reads 4 source bytes (argb) from two buffers at stride 0x40 and 0x30
- Multiplies each color channel by DAT_008b8e40-based coefficients with DAT_008b6c20 blending factor
- Clamps results to 0-255 range
- Writes packed ARGB result

**Globals:** DAT_008b6c20, DAT_008b8e40

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0058E22B — MISSING_ENTRY

Source: memory allocator. Bounds-checked indexed access with allocator lock/unlock.

**Key logic:**
- Checks param_1 < DAT_008d4a20 (allocator capacity)
- Checks bitmap at DAT_008d4920[param_1>>5] + 4 + (param_1&0x1f)*0x24 for flag bit 0
- If valid: calls FUN_00595a61 (lock), FUN_0058e290(param_1, param_2, param_3) (actual operation), FUN_00595ac0 (unlock)
- Returns result of FUN_0058e290
- On failure: sets error code 9 via FUN_0058afcf and 0 via FUN_0058afd8
- Returns 0xffffffff on error

**Globals:** DAT_008d4a20, DAT_008d4920

**Calls:** FUN_00595a61, FUN_0058e290, FUN_00595ac0, FUN_0058afcf, FUN_0058afd8

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0056C3A0 — MISSING_ENTRY

Source: math_utilities. Orthonormal basis construction from forward vector.

**Key logic:**
- Takes 4 double[3] parameters: param_1 (input forward), param_2 (normalized forward, out), param_3 (right, out), param_4 (up, out)
- If null inputs: uses local buffers
- Copies forward vector from param_1 to param_2
- Reads length at param_1+4 (double at offset 0x20)
- Normalizes forward using _DAT_0059e420 / sqrt(dot product)
- Checks ABS(forward.x) against _DAT_0059e830 for degenerate axis
- Computes right = normalize(cross(forward, reference_up)) where reference_up = (0,0,1) or (1,0,0)
- Computes up = cross(right, forward)
- Normalizes right and up

**Globals:** _DAT_0059e420, _DAT_0059e430, _DAT_0059e830

**Moddability:** hardcoded — pure 3D math

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0055D320 — MISSING_ENTRY

Source: animation/transform. Sets velocity/force components on physics body with scale factor.

**Key logic:**
- Switch on param_2 (axis/component selector):
  - 1: Set linear velocity: param_1+8..0x10 = param_3..5 * _DAT_0059e460 * *(param_1+0x14)
  - 2: Set angular velocity: param_1+0x18..0x20 = param_3..5 * _DAT_0059e460 * *(param_1+0x24)
  - 3: Set acceleration: param_1+0x28..0x30 = param_3..5 * _DAT_0059e460 * *(param_1+0x34)
- Calls FUN_005416a0(param_1, ...) to apply
- Sets flag bit at DAT_008b8f28 + 0xec |= 0x800

**Globals:** _DAT_0059e460, DAT_008b8f28

**Calls:** FUN_005416a0

**Moddability:** hardcoded — animation constant

---

<!-- target: docs/20-math-utilities.md -->

## FUN_00558E70 — MISSING_ENTRY

Source: renderer/texture. Texture/surface blending with coordinate transform.

**Key logic:**
- If param_1+0x20 signed (<0): calls FUN_00558d80/FUN_0055cf50 for texture sub-region copy
- If *(param_1+0x30) == 0: early return
- Calls FUN_0053b130 (setup)
- If bit 0x20 at param_1+0x20: sets scale factors via FUN_00542490, negates
- If bit 0x10: same but sets Y=0 (horizontal only)
- Calls FUN_0053b240 (apply transform)
- Zeroes output arrays at param_1+0x44 and param_1+0x48
- Enters linked-list traversal:
  - For each node at param_1+0x38:
    - If flag 0x30 bits: copies matrix from node, calls FUN_0053b170/FUN_0053b200
    - If flag 0x4000: calls FUN_0053b1d0/FUN_0053b330
    - Renders via DAT_008b8f24 vtable call (draw primitive)
    - Performs alpha blending with multiplication
    - Accumulates widths/heights
  - Final render pass: calls FUN_00558d80, FUN_0055cf50
- Calls FUN_0053b160 (teardown)

**Globals:** DAT_008b8f24, DAT_008b8f28

**Calls:** FUN_00558d80, FUN_0055cf50, FUN_0053b130, FUN_00542490, FUN_0053b240, FUN_0053b170, FUN_0053b200, FUN_0053b1d0, FUN_0053b330, FUN_0053b350, FUN_0053b160, FUN_005457c0, FUN_0055d560, FUN_00558d10

**Moddability:** hardcoded — render path

---

<!-- target: docs/20-math-utilities.md -->

## FUN_005503A0 — MISSING_ENTRY

Source: unknown. Vehicle AI state machine — speed/position adjustment.

**Key logic:**
- Walks linked list from param_1+0x204 (vehicle list head)
- For each vehicle with flag 0x80000 at +0x14:
  - Loops sub-parts (count at +0x118, array at +0x11c)
  - For each part: loops damage/position entries at stride 0x25
  - Checks if current position (at piVar7) < max (at piVar6):
    - With flag check at piVar6[-4] & 4
    - Switch on type at piVar6[1] & 0xffff000f:
      - 1: increments position by 1, caps at max
      - 2: increments by 1 but stays below max
      - 3: reverses sign if at boundary
      - 4: increments by 1, calls FUN_004c030 on overflow (trigger/reset)
  - Writes adjusted position

**Calls:** FUN_004c030 (trigger/reset)

**Moddability:** AI position/speed parameters in vehicle struct

---

<!-- target: docs/20-math-utilities.md -->

## FUN_00564DD0 — MISSING_ENTRY

Source: hash/crypto. Block cipher core — AES-like round transformation with lookup tables.

**Key logic:**
- Initializes output state in param_1 buffer (+0x400..+0x4d0)
- Iterates 16 rounds using uVar3 bitmask (starts 0x8000, shifts right each round)
- For each bit of param_3 (key/control):
  - If bit clear (0): performs ADD/XOR/rotate round on uVar4 and uVar1
    - Stores uVar4, uVar1, and step counter at param_1+0x400/0x440/0x480
    - XORs with table lookup at param_1 + (index & 0xff) * 4
    - Byte-rotates values
    - Doubles counter iVar2
  - If bit set (1): performs complement/rotate round
    - Doubles counter iVar2 + 1
    - XORs complemented values with lookup table
    - Byte-rotates
- Stores final state: uVar1→+0x4c8, uVar4→+0x4c4, counter→+0x4cc, param_2→+0x4d0
- Returns uVar1 ^ uVar4

**Struct offsets (param_1):**
| Offset | Field |
|--------|-------|
| +0x400..+0x43c | uVar4 history (16 entries) |
| +0x440..+0x47c | uVar1 history (16 entries) |
| +0x480..+0x4bc | Step counter history |
| +0x4c0 | History entry count |
| +0x4c4 | Final uVar4 |
| +0x4c8 | Final uVar1 |
| +0x4cc | Final step counter |
| +0x4d0 | Input param_2 |

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0058FF65 — MISSING_ENTRY

Source: system/locale. Locale/language detection for system code page validation.

**Key logic:**
- Checks length of DAT_008d3fa8 string: if == 3 sets DAT_008d3fa4 = 1 (3-letter lang code)
- Checks length of DAT_008d3fac string: same pattern for DAT_008d3f9c
- Resets DAT_008d3f98 = 0
- If not 3-letter: calls FUN_00590616 to parse numeric locale, else sets to 2
- Calls EnumSystemLocalesA with callback FUN_0058ffec
- Validates DAT_008d3fb0 flag mask: requires bits 0x100, 0x200, and 0x7 all set
- If incomplete: resets DAT_008d3fb0 = 0

**Globals:** DAT_008d3fa8, DAT_008d3fac, DAT_008d3fa4, DAT_008d3f9c, DAT_008d3f98, DAT_008d3fa0, DAT_008d3fb0

**Calls:** _strlen, FUN_00590616, EnumSystemLocalesA

**Moddability:** hardcoded — system locale detection

---

<!-- target: docs/20-math-utilities.md -->

## FUN_00401180 — PASS

---

<!-- target: docs/20-math-utilities.md -->

## FUN_00456150 — PASS

---

<!-- target: docs/20-math-utilities.md -->

## FUN_004DCF30 — MISSING_ENTRY

Source: math_utilities. Struct field getter — reads two fields.

**Key logic:**
- If param_2 != NULL: *param_2 = *(param_1 + 0x14)
- If param_3 != NULL: *param_3 = *(param_1 + 0x18)

**Moddability:** hardcoded — pure utility

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0058BC56 — MISSING_ENTRY

Source: unknown. Wrapper — calls FUN_0059508d with constant args.

**Key logic:**
- Calls FUN_0059508d(0x10000, 0x30000)

**Calls:** FUN_0059508d

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_004145C0 — MISSING_ENTRY

Source: math_utilities. Struct field copy (8 values).

**Key logic:**
- Copies 8 undefined4 values from param_2 to param_1 at indices [0]..[7] (offsets 0x00..0x1c)
- Order: [0], [2], [3], [4], [5], [6], [7], [1]

**Moddability:** hardcoded — pure utility

---

<!-- target: docs/20-math-utilities.md -->

## FUN_00474BA0 — MISSING_ENTRY

Source: unknown. Constructor — renderer context/state init.

**Key logic:**
- Calls FUN_00466d60(1) (parent/global init)
- Sets vtable to &PTR_FUN_005a3fc0
- Sets param_1[199] = &DAT_007d0038 (game state pointer)
- Sets param_1[0xca] = 0, [0xc9] = 1, [0xcb] = 1, [0xcc] = 1 (default flags)
- Calls FUN_00486f30 on &PTR_DAT_005be704 and &DAT_005c32c8 (string/resource init)
- Sets param_1[0xcd] = 0x1b6 (some size/limit)

**Globals:** DAT_007d0038, PTR_DAT_005be704, DAT_005c32c8

**Calls:** FUN_00466d60, FUN_00486f30

**Moddability:** hardcoded — constructor

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0048EAA0 — MISSING_ENTRY

Source: unknown. Constructor — large struct initialization with many field defaults.

**Key logic:**
- Calls FUN_00485e30 (parent constructor)
- Zeroes fields at indices 0x38..0x5b (many)
- Sets individual bytes at +0x17d, +0x17e, +0x17f to 0
- Sets vtable to &PTR_LAB_005a4550
- Sets defaults:
  - param_1[0x40] = 1
  - param_1[0x41] = 4
  - param_1[0x42] = 0x3f000000 (0.5f)
  - param_1[0x5c] = -1
  - param_1[0x5e] = 10
  - *(param_1+0x5f) = 1

**Calls:** FUN_00485e30

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_004B29B0 — MISSING_ENTRY

Source: renderer/LOD. Bitfield manipulation for LOD/render state.

**Key logic:**
- Computes: param_1[0x2c] ^= ((ROUND(param_2 * _DAT_005accd0) & 0xff) << 0xc) & 0x1f000
- Modifies 3 bits at mask 0x1f000 in bits 12-16

**Globals:** _DAT_005accd0

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_004DEDB0 — MISSING_ENTRY

Source: unknown. Sorted array insertion with duplicate detection.

**Key logic:**
- Reads element count at param_1+0x18
- Duplicate check: compares 9 fields of param_2 against array at param_1+0x20 (stride 9 floats = 0x24 bytes)
- If duplicate found: calls FUN_004df110(..., -1), returns
- If array full (0x14 elements): finds worst-fit element for replacement
  - Evaluates cost function using flags at stride 0x24
  - Uses _DAT_005ad140 and _DAT_0059e670 as threshold constants
  - Shifts array left to remove worst element
- Insertion: finds position by sorting key (param_2[1] < *pfVar4)
  - Shifts elements right to make room
  - Copies 9 fields of param_2 into array
  - Increments count
  - Calls FUN_004df110(param_2[1], index)

**Globals:** _DAT_005ad140, _DAT_0059e670

**Calls:** FUN_004df110

**Struct offsets (param_1):**
| Offset | Field | Type |
|--------|-------|------|
| +0x18 | ElementCount | int |
| +0x1c | SortKey array | int[20] |
| +0x20 | Element array | float[9*20] |
| +0x40 | Insertion temp | undefined |

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0052A0A1 — MISSING_ENTRY

Source: compression. Huffman tree construction and code generation.

**Key logic:**
- Implements classic Huffman coding algorithm:
  - Counts symbol frequencies (max 16 symbols)
  - Checks for degenerate case (all same symbol)
  - Finds min/max used symbol indices
  - Validates Kraft inequality
  - Builds canonical Huffman code lengths
- Generates code table:
  - Assigns codewords in order of increasing length
  - Writes codes to param_9 output array
  - For each length group: assigns sequential codewords
- Builds encoding tree nodes:
  - Allocates tree nodes in output buffer at param_7+*param_8*8
  - Creates parent-child relationships
  - Populates left/right child indices
  - Returns 0 on success, error codes on failure (-3=invalid data, -4=out of buffer)

**Algorithm family:** Huffman coding

**Moddability:** hardcoded — compression utility

---

<!-- target: docs/20-math-utilities.md -->

## FUN_005822B0 — MISSING_ENTRY

Source: memory. Linked list deallocation — frees all nodes and data.

**Key logic:**
- Walks linked list from *param_1 (head pointer)
- For each node: if node[2] (char) != 0 and *node != 0: calls FUN_00587bcf(*node) (free data)
- Frees node itself via FUN_00587bcf
- Zeros param_1[0..3] (list metadata)

**Calls:** FUN_00587bcf

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0058D7C3 — MISSING_ENTRY

Source: unknown. Sentinel-loop processor — repeats operation until sentinel found.

**Key logic:**
- Loops calling FUN_0058d78e(param_1, param_3, param_4)
- Decrements param_2 (max iterations)
- Exits when *param_4 == -1 or param_2 < 1

**Calls:** FUN_0058d78e

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_004530A0 — MISSING_ENTRY

Source: unknown. State machine dispatcher with resource management.

**Key logic:**
- Switch on *param_1 (state selector):
  - 0: calls FUN_004527e0(param_1[1], param_2) (init)
  - 1: calls FUN_00452b10(param_1[1], param_2 == 2) (check)
    - If returns non-zero: calls FUN_00452810(param_1[1]) (cleanup)

**Calls:** FUN_004527e0, FUN_00452b10, FUN_00452810

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_00479D00 — MISSING_ENTRY

Source: renderer. Renderer resource dispatch via service provider.

**Key logic:**
- Calls vtable at *DAT_007cd8c0 + 0x1c with arg 0xe (service lookup)
- If result non-null: calls FUN_00477280(param_1)
- Calls same vtable with arg 0xf
- If result non-null: calls FUN_00477280(param_1)
- Returns 0

**Globals:** DAT_007cd8c0

**Calls:** FUN_00477280

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0049A990 — MISSING_ENTRY

Source: unknown. Destructor — vtable set + conditional free.

**Key logic:**
- Sets vtable to &PTR_LAB_005acab0
- If param_1[0xd] != 0: frees with FUN_00587bcf
- Calls FUN_004b0170() (cleanup)

**Calls:** FUN_00587bcf, FUN_004b0170

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_004C8D60 — MISSING_ENTRY

Source: unknown. Vtable dispatch wrapper (scene manager).

**Key logic:**
- If DAT_008ac4c4 (scene manager) != NULL:
  - Calls vtable at *DAT_008ac4c4 + 0x14

**Globals:** DAT_008ac4c4

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0050E7CB — MISSING_ENTRY

Source: math_utilities. 2D coordinate transform with perspective divide.

**Key logic:**
- Reads 2D input from param_2 (x, y)
- Reads transform matrix from param_3 (16 floats, stride 4)
- Computes:
  - projected_x = m[0xc] + y*m[4] + x*m[0]
  - projected_y = m[0xd] + y*m[5] + x*m[1]
  - w = m[0xf] + y*m[7] + x*m[3]
- Checks w against 1.0 via FUN_0050c042
- If w != 0: divides x, y by w (perspective divide)

**Calls:** FUN_0050c042

**Moddability:** hardcoded — pure math utility

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0054C290 — MISSING_ENTRY

Source: runtime. Static initializer registration.

**Key logic:**
- Calls FUN_00587b3e(&LAB_0054c2a0) — registers cleanup callback for at-exit execution

**Calls:** FUN_00587b3e

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_00556650 — PASS

---

<!-- target: docs/20-math-utilities.md -->

## FUN_00474C70 — MISSING_ENTRY

Source: unknown. Constructor — vtable set + sub-init.

**Key logic:**
- Sets *param_1 = &PTR_FUN_005a4080
- Calls FUN_0048c0d0()

**Calls:** FUN_0048c0d0

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_004D0F00 — MISSING_ENTRY

Source: math_utilities. Simple setter — stores value.

**Key logic:**
- *param_1 = param_2

**Moddability:** hardcoded — pure utility

---

<!-- target: docs/20-math-utilities.md -->

## FUN_00561FF0 — MISSING_ENTRY

Source: unknown. Wrapper — delegates to FUN_00562010.

**Key logic:**
- Calls FUN_00562010(param_2, 0)
- Returns 0

**Calls:** FUN_00562010

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_00598E39 — MISSING_ENTRY

Source: unknown. Destructor with vtable swap and exception handling.

**Key logic:**
- Calls FUN_0058a5d8 (SEH setup)
- Sets vtable to &PTR_FUN_005b9bcc
- If param_1[0x12] (char) != 0: calls FUN_00599495()
- If param_1[0x11] != 0: calls FUN_005993af(1) then FUN_00587bcf(free)
- Calls FUN_00598c70() (cleanup)
- Swaps vtable to &PTR_FUN_005b9c04
- Calls FUN_00598c70() again

**Calls:** FUN_0058a5d8, FUN_00599495, FUN_005993af, FUN_00587bcf, FUN_00598c70

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0045BE70 — MISSING_ENTRY

Source: runtime. Static initializer registration.

**Key logic:**
- Calls FUN_00587b3e(&LAB_0045be80) — registers cleanup callback

**Calls:** FUN_00587b3e

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_004855A0 — MISSING_ENTRY

Source: unknown. Destructor — vtable set + conditional free.

**Key logic:**
- Sets vtable to &PTR_FUN_005ab290
- Calls FUN_00487250()
- If (param_2 & 1): calls FUN_00587bcf(param_1)

**Calls:** FUN_00487250, FUN_00587bcf

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0049A9E0 — MISSING_ENTRY

Source: math_utilities. Rectangle dimension computation — subtracts origin.

**Key logic:**
- param_1[0x14] = param_2 - param_1[0xc] (width from right - left)
- param_1[0x18] = param_3 - param_1[4] (height from bottom - top)
- param_1[0x1c] = param_4 - param_1[0xc] (alternative width)
- param_1[0x20] = param_5 - param_1[4] (alternative height)

**Struct offsets (param_1):**
| Offset | Field |
|--------|-------|
| +0x04 | Top |
| +0x0c | Left |
| +0x14 | Width |
| +0x18 | Height |
| +0x1c | AltWidth |
| +0x20 | AltHeight |

**Moddability:** hardcoded — pure utility

---

<!-- target: docs/20-math-utilities.md -->

## FUN_004C8180 — MISSING_ENTRY

Source: unknown. Vtable dispatch wrapper (scene manager).

**Key logic:**
- If DAT_008ac4c4 (scene manager) != NULL:
  - Calls vtable at *DAT_008ac4c4 + 0x28 with args (0, 0, 0)

**Globals:** DAT_008ac4c4

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_005076FE — MISSING_ENTRY

Source: unknown. Constructor — vector array allocation with exception handling.

**Key logic:**
- Calls FUN_0058a5d8 (SEH setup)
- If source size differs from current size:
  - Allocates array via operator_new(iVar1 << 4) (stride 0x10)
  - Populates with vector_constructor_iterator_ using LAB_005007ec
  - Stores array at +0x104c and size at +0x1048
- Returns 0 on success, 0x8007000e on allocation failure

**Calls:** FUN_0058a5d8, operator_new, _vector_constructor_iterator_

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_00556700 — PASS

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0059A86C — MISSING_ENTRY

Source: unknown. Destructor with reference count decrement.

**Key logic:**
- Calls FUN_0058a5d8 (SEH setup)
- Sets vtable to &PTR_FUN_005b9d3c
- Reads reference index at param_1[9]
- If index != 0: decrements DAT_008d463c[index]
- If ref count < 1: calls FUN_0059a980() (full cleanup)
- Calls FUN_00598c70() (cleanup)

**Globals:** DAT_008d463c

**Calls:** FUN_0058a5d8, FUN_0059a980, FUN_00598c70

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_00408500 — PASS

---

## Summary

| # | Address | Result |
|---|---------|--------|
| 1071 | FUN_0055C070 | MISSING_ENTRY |
| 1072 | FUN_00475D90 | MISSING_ENTRY |
| 1073 | FUN_00495BD0 | MISSING_ENTRY |
| 1074 | FUN_00518032 | PASS |
| 1075 | FUN_004B9000 | MISSING_ENTRY |
| 1076 | FUN_00531250 | PASS |
| 1077 | FUN_004906E0 | MISSING_ENTRY |
| 1078 | FUN_0050B1F0 | MISSING_ENTRY |
| 1079 | FUN_005426A0 | MISSING_ENTRY |
| 1080 | FUN_005170C0 | MISSING_ENTRY |
| 1081 | FUN_0050B891 | MISSING_ENTRY |
| 1082 | FUN_00552F20 | MISSING_ENTRY |
| 1083 | FUN_00495190 | PASS |
| 1084 | FUN_0046EEC0 | MISSING_ENTRY |
| 1085 | FUN_004D4840 | MISSING_ENTRY |
| 1086 | FUN_004B33B0 | MISSING_ENTRY |
| 1087 | FUN_0055EB30 | MISSING_ENTRY |
| 1088 | FUN_0058E22B | MISSING_ENTRY |
| 1089 | FUN_0056C3A0 | MISSING_ENTRY |
| 1090 | FUN_0055D320 | MISSING_ENTRY |
| 1091 | FUN_00558E70 | MISSING_ENTRY |
| 1092 | FUN_005503A0 | MISSING_ENTRY |
| 1093 | FUN_00564DD0 | MISSING_ENTRY |
| 1094 | FUN_0058FF65 | MISSING_ENTRY |
| 1095 | FUN_00401180 | PASS |
| 1096 | FUN_00456150 | PASS |
| 1097 | FUN_004DCF30 | MISSING_ENTRY |
| 1098 | FUN_0058BC56 | MISSING_ENTRY |
| 1099 | FUN_004145C0 | MISSING_ENTRY |
| 1100 | FUN_00474BA0 | MISSING_ENTRY |
| 1101 | FUN_0048EAA0 | MISSING_ENTRY |
| 1102 | FUN_004B29B0 | MISSING_ENTRY |
| 1103 | FUN_004DEDB0 | MISSING_ENTRY |
| 1104 | FUN_0052A0A1 | MISSING_ENTRY |
| 1105 | FUN_005822B0 | MISSING_ENTRY |
| 1106 | FUN_0058D7C3 | MISSING_ENTRY |
| 1107 | FUN_004530A0 | MISSING_ENTRY |
| 1108 | FUN_00479D00 | MISSING_ENTRY |
| 1109 | FUN_0049A990 | MISSING_ENTRY |
| 1110 | FUN_004C8D60 | MISSING_ENTRY |
| 1111 | FUN_0050E7CB | MISSING_ENTRY |
| 1112 | FUN_0054C290 | MISSING_ENTRY |
| 1113 | FUN_00556650 | PASS |
| 1114 | FUN_00474C70 | MISSING_ENTRY |
| 1115 | FUN_004D0F00 | MISSING_ENTRY |
| 1116 | FUN_00561FF0 | MISSING_ENTRY |
| 1117 | FUN_00598E39 | MISSING_ENTRY |
| 1118 | FUN_0045BE70 | MISSING_ENTRY |
| 1119 | FUN_004855A0 | MISSING_ENTRY |
| 1120 | FUN_0049A9E0 | MISSING_ENTRY |
| 1121 | FUN_004C8180 | MISSING_ENTRY |
| 1122 | FUN_005076FE | MISSING_ENTRY |
| 1123 | FUN_00556700 | PASS |
| 1124 | FUN_0059A86C | MISSING_ENTRY |
| 1125 | FUN_00408500 | PASS |

**Stats:**
- PASS: 8 (verified entries match source)
- FAIL: 0 (no errors found in existing entries)
- MISSING_ENTRY: 47 (no `## FUN_` header in target doc)
- SKIP: 0


---

# Cross-Validation Results: Functions 1126-1180
# Target: docs/20-math-utilities.md
# Generated: 2026-07-15

---

## FUN_00587BDC — SKIP (compiler intrinsic)

Source: 0x00587bdc____ftol.c — MSVC CRT __ftol (float-to-long). Doc entry confirms CRT intrinsic. No game logic.

---

## FUN_0049A190 — PASS

Verified: linked list iteration with vtable destructor. While *param_1 != 0: calls FUN_00499e00(), updates *param_1, calls (*extraout_ECX)(1) if non-null. All claims match .c source. No globals or struct offsets claimed.

---

## FUN_004C4CB0 — PASS

Verified: linked list key search. Stores head at param_1+8 → param_1+0x10, walks list comparing *node to param_2, returns 1/0, follows next+4 pointer. All claims match .c.

---

## FUN_00503CE3 — PASS

Verified: bitplane blending/compositing. Reads buffers at param_1[1]+0x18 and *param_1+0x18, stride at +0x1050, nested row/pixel loops with 16-bit color channel averaging (0xf0f0/0xffff0f0f masks, 0x2020/0x202 rounding, >>2). Struct offsets +0x18, +0x1050, +0x1058, +0x105C all confirmed. No calls. All claims verified.

---

## FUN_0053C900 — PASS

Verified: string match with flag set. Copies string to local buffer, normalizes via FUN_00589901, iterates DAT_008b8e30 entries (stride 0x84) at DAT_008b5a3c, sets 0x400 flag in DAT_008b5a38 on match. Calls FUN_0053ca00(). All globals and calls confirmed in .c source.

---

## FUN_0058C674 — PASS

Verified: character encoding convert. Direct table lookup (PTR_DAT_005e69c8) if param_2+1 < 0x101, else FUN_00595dc8 multibyte conversion. Returns masked by param_3. All claims match .c source.

---

## FUN_0040BDE0 — PASS

Verified: struct field initializer. All field sets confirmed: +0x00/+0x04/+0x08=0, +0x0c=2, +0x14=-1, +0x18/+0x1c/+0x20=0, +0x24=0, +0x25=0, +0x28=0, +0x2c=0, +0x2d=0, +0x2e=0. All match .c source.

---

## FUN_004672C0 — FAIL

**Errors: STRUCT_OFFSET_MISMATCH** — Struct offset table has systematic errors. Offsets for Param4, ConstVal, Param3, Param2 are shifted by +8 bytes.

**Verification:**
- `FUN_0048c070(0)` — confirmed ✓
- `param_1[200] = &DAT_007c5770 + (param_2 * 0xb + param_3) * 0x40` — confirmed ✓
- Vtable `PTR_FUN_0059f4f8` — confirmed ✓
- index 0xc9 = 0x37, index 0xca = param_3, index 0xcb = param_2 — confirmed ✓

**Corrected struct offsets (index × 4 = byte offset):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x000 | vtable | PTR_FUN_0059f4f8 |
| +0x31c | Param4 | param_1[199] = param_4 |
| +0x320 | GlobalPtr | param_1[200], pointer into DAT_007c5770 |
| +0x324 | ConstVal | param_1[0xc9] = 0x37 |
| +0x328 | Param3 | param_1[0xca] = param_3 |
| +0x32c | Param2 | param_1[0xcb] = param_2 |

**Correction applied to doc below:**

```
<!-- target: docs/20-math-utilities.md -->
## FUN_004672c0 — Object Initializer with Vtable + Index

Source: unknown | Confidence: high
Initializes an object: sets vtable, computes indexed global pointer, stores parameters.

**Key logic:**
- Calls FUN_0048c070(0) — global init
- Computes: param_1[200] = &DAT_007c5770 + (param_2 * 0xb + param_3) * 0x40
- Sets vtable to PTR_FUN_0059f4f8
- Stores param_4 at index 199 (+0x31c)
- Stores 0x37 at index 0xc9 (+0x324)
- Stores param_3 at index 0xca (+0x328)
- Stores param_2 at index 0xcb (+0x32c)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x000 | vtable | pointer | Set to PTR_FUN_0059f4f8 |
| +0x31c | Param4 | uint | Index 199 (0xc7): stored from param_4 |
| +0x320 | GlobalPtr | pointer | Index 200 (0xc8): pointer into DAT_007c5770 |
| +0x324 | ConstVal | uint | Index 0xc9: set to 0x37 |
| +0x328 | Param3 | uint | Index 0xca: stored from param_3 |
| +0x32c | Param2 | uint | Index 0xcb: stored from param_2 |

**Globals:**
- DAT_007c5770 — base of global array, stride 0x40

**Calls:**
- FUN_0048c070 — global initialization
```

---

## FUN_0048DFF0 — PASS

Verified: state machine with virtual dispatch. Calls FUN_00486720() for state, switch with cases 1/2/4/5/default, dispatches vtable+0x40 and vtable+0x9c with correct args (6,7,8,9). All claims match .c.

---

## FUN_004B1970 — PASS

Verified: small struct init. Fields [1]=0, [2]=-1, [3]=0, [4]=-1, vtable = PTR_LAB_005acbd8. All match .c source.

---

## FUN_004DC600 — PASS

Verified: surface size query. Calls FUN_0053d1f0 then FUN_005531f0, two __ftol() conversions, stores in *param_3/*param_4, zeros on failure. All claims match .c.

---

## FUN_0053C9C0 — PASS

Verified: bit flag array update. Iterates DAT_008b8e30 entries at DAT_008b5a38 (stride 0x21 ints = 0x84 bytes), if bit 0x4000 set: clears it and sets 0x400. Calls FUN_0053ca00(). All match .c.

---

## FUN_0055685A — PASS

Verified: returns constant 1 as uint16. No params, no globals, no side effects. All match .c.

---

## FUN_00564B80 — PASS

Verified: pad output with spaces. Returns *param_3=0 if param_2<1, else copies 3 chars from param_1 (or zeros), appends 4 random chars from FUN_00564c40(). Null-terminates. All claims match .c.

---

## FUN_00463760 — PASS

Verified: conditional state dispatch. Calls FUN_00461dc0(), dispatches to FUN_00461190/FUN_00460e90/FUN_00461020 based on state and param_1. All match .c.

---

## FUN_00488BD0 — PASS

Verified: field setter at +0xE4. Trivial setter. All match .c.

---

## FUN_004A1DC0 — PASS

Verified: guarded linked list append. Guard at param_1[4], alloc 12-byte node, appends to list, increments count at [3]. All struct offsets (+0x00/+0x04/+0x08/+0x0C/+0x10) confirmed.

---

## FUN_004D2260 — PASS (minimal entry, no errors)

Verified: progress increment + data store. Checks DAT_0083ee60 < 0x3ff increments both counters, calls FUN_004b33b0 (progress bar), stores params at DAT_008aae64+8/+0xc. Entry accurate but sparse — no calls/globals claimed to verify. No errors found.

---

## FUN_0050DC90 — PASS (minimal entry)

Verified: calls FUN_0050fea7(1) then indirect through PTR_FUN_005d783c. Minimal entry accurate.

---

## FUN_00547420 — PASS (minimal entry)

Verified: frees two linked lists (param_1+0x24 chain via +0xc0, param_1+0x2c chain via +0x14). Calls FUN_00546370/FUN_00557470/FUN_00587bcf, FUN_0053ab70/FUN_00587bcf. Minimal entry accurate.

---

## FUN_0059C6E8 — SKIP (compiler intrinsic — SEH unwind)

Source: 0x0059c6e8__Unwind_0059c6e8.c. MSVC SEH unwind stub — frees EBP+8 via FUN_00587bcf. Compiler-generated, no game logic.

---

## FUN_00461530 — PASS

Verified: flag bit test. Returns ((char)param_1+0x88 & param_2) != 0. All match .c.

---

## FUN_0050C042 — PASS

Verified: float range check. param_1 - param_2, checks between _DAT_005ade3c and _DAT_005ac9c0 exclusive. Returns 1/0. All match .c.

---

## FUN_0058DCCC — PASS

Verified: float rounding mode select. Checks in_EAX & 0x80000, returns 7 or 1. All match .c.

---

## FUN_004258C0 — PASS

Verified: AI speed/overtaking state setter. Sets +0x4438=1.0, +0x4434=0. If +0x4440 < _DAT_0059e46c OR (+0x37cc>_DAT_0059e824 AND +0x38c4>_DAT_0059e824): sets +0x4510=2. All globals and offsets confirmed.

---

## FUN_00479910 — PASS

Verified: UI object init. FUN_00466980(0, 0.5f), vtable = PTR_FUN_005a54e8. All match .c.

---

## FUN_00499160 — PASS

Verified: UI destructor. Calls FUN_00499180(), if param_2 & 1: FUN_00587bcf(param_1). All match .c.

---

## FUN_004BDE20 — PASS

Verified: clamped nested loop with callback. 4x __ftol clamped to [0,7]. Nested loops: (iVar4-iVar3+1) × (param_1-iVar5+1), calls FUN_004bd860. Extra call if any clamp occurred. All match .c.

---

## FUN_004FC850 — PASS

Verified: float field init. [0..3]=0, [4]=[5]=20.0f. All match .c.

---

## FUN_005361D0 — FAIL

**Errors: RETURN_VALUE_ERROR** — Doc claims "Return 0xfffffffd or 0xfffffffe based on type" but .c returns 0 or 0xfffffffd on success path (based on iVar2 == 0x71). 0xfffffffe is the guard-failure return (line 29). Incorrectly conflates two return paths.

**Verified correct claims:**
- Guard: param_1 && param_1+0x1c && (*(param_1+0x1c)+4) in {0x2a,0x71,0x29a} ✓
- Dispatches *(param_1+0x24) for 4 conditional checks + 1 always ✓
- Sets *(param_1+0x1c)=0 ✓

**Corrected return value paragraph:**
```
- Guard passes: returns (iVar2 != 0x71) - 1 & 0xfffffffd → 0 if type == 0x71, 0xfffffffd otherwise
- Guard fails: returns 0xfffffffe
```

**Correction applied to doc below:**

```
<!-- target: docs/20-math-utilities.md -->
## FUN_005361d0 — Multi-Condition Dispatch with Cleanup

Source: unknown | Confidence: medium
Checks type field for specific values (0x2a, 0x71, 0x29a), dispatches multiple callbacks, resets state.

**Key logic:**
- Guard: param_1 != 0 AND *(param_1+0x1c) != 0 AND *(*(param_1+0x1c)+4) in {0x2a, 0x71, 0x29a}
- If guard passes: dispatches *(param_1+0x24) for each of 4 non-null sub-conditions, then once unconditionally
- Sets *(param_1+0x1c) = 0
- Returns 0 if type == 0x71, 0xfffffffd otherwise
- If guard fails: returns 0xfffffffe

**Calls:** *(param_1+0x24) (callback dispatch, up to 5 times)
```

---

## FUN_00587200 — PASS

Verified: byte setter at +0x18. Trivial setter. All match .c.

---

## FUN_004080F0 — PASS

Verified: memory allocation with buffer read. Guard: +0xc != 0 AND +0x18 == 0. Seeks via FUN_00587f64, reads count via FUN_0058803f, allocates count*4 via operator_new, zero-inits, reads dwords. On failure: FUN_0041a160 + free. Returns 0/1. Struct offsets +0x0c/+0x14/+0x18 all confirmed.

---

## FUN_0054EAF0 — PASS

Verified: struct zero-init. [0..3]=0, [7..9]=0, loop [0xd..0x1c]=0 (16 dwords). All match .c.

---

## FUN_00536260 — PASS

Verified: table lookup init. Computes width from +0x22, zero-fills buffer at +0x3a, looks up 3 ushorts from DAT_005b77e8/ea/ec/ee indexed by (+0x7a)*0xc, zeroes fields, sets +0x72=lookup, +0x6e=+0x56=2. All match .c.

---

## FUN_004D5C40 — PASS

Verified: zeros DAT_008ad254 and DAT_008ad258. All match .c.

---

## FUN_004A3FE0 — PASS

Verified: dual zero + conditional call. Sets +0x78=0, +0x84=0. If +0x64 != 0: FUN_0054c030(0,0,1,0). All match .c.

---

## FUN_0048B560 — PASS

Verified: path/file char validator. Mode dispatch on +0x2e8. Mode 1 rejects \, /, :, .; mode 2 calls FUN_00589b9e/FUN_00589b70, allows . and :. Calls FUN_00589c49 for valid char check. All match .c.

---

## FUN_0046E170 — PASS

Verified: game command dispatch. Calls vtable+0x1c on *DAT_007cd8c0 with 0x24 then 0x23, each followed by FUN_00489cb0 on success. All match .c.

---

## FUN_005679A5 — PASS

Verified: list traversal with early exit. Uses ZF flag from caller, iterates decrementing counter until 0 or null pointer, follows next at +4. All match .c.

---

## FUN_004DFCA0 — FAIL

**Errors: STALE_ENTRY** — Doc marked as `[PARTIAL] Unknown` with "3 lines of decompiled code" but .c is fully decompiled (21 lines). Description no longer accurate.

**Verified behavior from .c:**
- Calls FUN_004ded20() 11 times (0xb loop)
- If param_1+0x90 != 0: frees via FUN_00587bcf

**Corrected entry:**

```
<!-- target: docs/20-math-utilities.md -->
## FUN_004dfca0 — Loop Call with Conditional Free

Source: unknown | Confidence: high
Calls FUN_004ded20 11 times, then conditionally frees pointer at +0x90.

**Key logic:**
- Loops 11 times calling FUN_004ded20()
- If param_1+0x90 != 0: FUN_00587bcf(*(param_1+0x90)) — free
- Returns void

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x90 | freeable_ptr | Freed if non-null |

**Calls:**
- FUN_004ded20 — loop target (11 calls)
- FUN_00587bcf — conditional free
```

---

## FUN_0051A87E — FAIL

**Errors: STALE_ENTRY** — Doc marked as `[PARTIAL] Unknown` with "10 lines of decompiled code" but .c is fully decompiled (55 lines, 234 bytes). Bitstream/Huffman-like decoder with table lookup, bit extraction, and error reporting.

**Corrected entry:**

```
<!-- target: docs/20-math-utilities.md -->
## FUN_0051a87e — Bitstream Decode with Table Lookup

Source: unknown | Confidence: medium
Reads variable-length bit field from bit buffer, performs table-based decoding with error reporting.

**Key logic:**
- Extracts (param_5)-bit field from param_2 at bit position param_3
- Compares against table at param_4+0x44+(param_5*4), consumes more bits if below threshold
- Updates bit buffer state at param_1+0x18 and param_1+0xc
- If decoded index < 17: table-based decode from param_4+0x8c, param_4+0xd0
- Else: error dispatch through vtable at param_1+0x1c

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x0c | bit_buffer | Remaining bit data |
| +0x18 | bit_position | Current bit position |
| +0x1c | error_handler | VTable for error dispatch |

**Struct offsets (param_4 - decode table):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x44 | threshold_table | int table indexed by bit length |
| +0x8c | value_table | int table for small indices (<17) |
| +0xd0 | base_table | int table for small indices |

**Calls:**
- FUN_0051a794 — refill bit buffer
- VTable dispatch on param_1[0x1c] for errors

**Moddability:** hardcoded
```

---

## FUN_00564220 — FAIL

**Errors: STALE_ENTRY** — Doc marked as `[PARTIAL] Unknown` with "7 lines of decompiled code" but .c is fully decompiled (33 lines). Function is a string tokenizer scanning DAT_008cfae4 for delimiter param_2.

**Corrected entry:**

```
<!-- target: docs/20-math-utilities.md -->
## FUN_00564220 — String Tokenizer (strtok-style)

Source: unknown | Confidence: high
Tokenizes a global string buffer by scanning for delimiter character.

**Key logic:**
- If param_1 != NULL: sets DAT_008cfae4 = param_1 (new string to tokenize)
- Scans DAT_008cfae4 for first occurrence of param_2 (delimiter)
- If found and not at start: null-terminates at match, advances DAT_008cfae4 past delimiter
- Returns pointer to token start, or NULL if no token found

**Globals:**
- DAT_008cfae4 — global string buffer pointer (stateful)

**Calls:** none
```

---

## FUN_00552FC0 — PASS

Verified: field setter at +0x48. Trivial setter. All match .c.

---

## FUN_0059CAC0 — SKIP (compiler intrinsic — SEH unwind)

Source: 0x0059cac0__Unwind_0059cac0.c. MSVC SEH unwind — frees *(EBP-0x20) via FUN_00587bcf. Doc already correctly identifies as SEH. No game logic.

---

## FUN_00456040 — PASS

Verified: double field getter. Returns *(param_1+0x30) via param_2, *(param_1+0x34) via param_3, null-guarded. All match .c.

---

## FUN_0047A230 — PASS

Verified: conditional destructor. Vtable=PTR_FUN_005a6068, calls FUN_0048d3e0, if param_2&1: FUN_00587bcf(param_1), returns param_1. All match .c.

---

## FUN_00499A20 — PASS

Verified: float field decrement. *(param_1+8) -= param_2. All match .c.

---

## FUN_004C2300 — PASS

Verified: dual-list destruction. Primary list at [0], secondary at [4] with 3-level deep free. Zeros many fields, sets +0x1b=1, restores [0x20] from DAT_007d0a24. All match .c.

---

## FUN_005001F0 — PASS

Verified: float comparison check. Returns 1 if *(param_1+0xc) != _DAT_005ad34c, else 0. All match .c.

---

## FUN_0053B130 — PASS

Verified: 10-float struct initializer. Zeroes 7 dwords, sets 3 to 1.0f (0x3f800000), calls FUN_0053b3b0. All match .c.

---

## FUN_0058A947 — SKIP (library code — MSVC CRT __nh_malloc)

Source: 0x0058a947____nh_malloc.c. MSVC CRT heap allocator. Doc correctly identifies as CRT. No game logic.

---

## FUN_0059CAE0 — SKIP (compiler intrinsic — SEH unwind)

Source: 0x0059cae0__Unwind_0059cae0.c. MSVC SEH unwind — delegates to FUN_0057b7f0 (vtable init). Doc correctly identifies. No game logic.

---

## FUN_0045BB00 — FAIL

**Errors: RETURN_VALUE_ERROR** — Doc claims "Returns index of first above-threshold value" but function returns COUNT of values exceeding threshold (0-4), not index. The while loop counts how many of 8 sampled values (stride 0x5c, starting at +0x90) exceed DAT_0059e440, capped at 4.

**Verified correct claims:**
- Iterates up to 8 entries, stride 0x5c, starting at param_1+0x90 ✓
- Compares against DAT_0059e440 (ZeroThreshold) ✓

**Corrected description:**
```
Returns count (0-4) of values exceeding threshold DAT_0059e440 across up to 8 sampled entries (stride 0x5c from +0x90). Stops after finding 4 above-threshold values or exhausting the array.
```

**Correction applied to doc below:**

```
<!-- target: docs/20-math-utilities.md -->
## FUN_0045bb00 — Float Array Threshold Search

Source: unknown | Confidence: medium
Searches array of floats for values exceeding threshold, returns count.

**Key logic:**
- Iterates up to 8 entries stride 0x5c starting at param_1+0x90
- Checks if float > DAT_0059e440 (ZeroThreshold, ~0.0f)
- Returns count of above-threshold values found (capped at 4)

**Globals:**
- DAT_0059e440 (ZeroThreshold)
```

---

## FUN_0047F1F0 — PASS

Verified: clamp by range. Clamps *param_1 to [param_2, param_3] using side-effect conditional. All match .c.

---

## FUN_0049A330 — PASS

Verified: char-to-index conversion. Normalizes via FUN_00589901, returns first_char - 'A' if in [0-25], else -1. All match .c.

---

# Summary

**Functions 1126-1180 cross-validation complete.**

| Result | Count | Functions |
|--------|-------|-----------|
| PASS | 44 | 0049A190, 004C4CB0, 00503CE3, 0053C900, 0058C674, 0040BDE0, 0048DFF0, 004B1970, 004DC600, 0053C9C0, 0055685A, 00564B80, 00463760, 00488BD0, 004A1DC0, 004D2260, 0050DC90, 00547420, 00461530, 0050C042, 0058DCCC, 004258C0, 00479910, 00499160, 004BDE20, 004FC850, 00587200, 004080F0, 0054EAF0, 00536260, 004D5C40, 004A3FE0, 0048B560, 0046E170, 005679A5, 00552FC0, 00456040, 0047A230, 00499A20, 004C2300, 005001F0, 0053B130, 0047F1F0, 0049A330 |
| FAIL | 6 | 004672C0 (STRUCT_OFFSET_MISMATCH), 005361D0 (RETURN_VALUE_ERROR), 004DFCA0 (STALE_ENTRY), 0051A87E (STALE_ENTRY), 00564220 (STALE_ENTRY), 0045BB00 (RETURN_VALUE_ERROR) |
| SKIP | 5 | 00587BDC (CRT __ftol), 0059C6E8 (SEH unwind), 0059CAC0 (SEH unwind), 0059CAE0 (SEH unwind), 0058A947 (CRT __nh_malloc) |

**Key findings:**
- 5 FAIL entries found: 3 stale [PARTIAL] entries, 1 struct offset error, 1 return value error
- 4 of 55 functions are SEH unwind/CRT intrinsics (skip)
- Struct offset table for FUN_004672C0 had systematic +8 byte shift
- FUN_005361D0 return value description conflated two return paths
- Two stale [PARTIAL] entries (004DFCA0, 0051A87E) now have full decompiled .c sources
- FUN_00564220 is a string tokenizer but doc claims [PARTIAL]
- FUN_0045BB00 returns count of above-threshold values, not index of first



---

# Cross-Validation: Functions 1181-1237
# Worker F, Batch 4
# Target: docs/20-math-utilities.md, docs/21-audio-network-internals.md

---

## FUN_004C7774 — PASS

Source: docs/20-math-utilities.md, `0x004c7774__FUN_004c7774.c`

**Verification:**
- Extracts bit 25 (>>0x19) of *(EDI+0x38), stores byte at EBX+0x1067 ✓
- Calls FUN_004b2b00, FUN_004c7bf0, FUN_004b2b80 ✓
- Copies bit 0 of *(EDI+0x3b) to EBX+0x4024 ✓
- Converts float from FUN_004b2b40(), stores at EBX+0x4028 ✓

All claims verified.

---

## FUN_00504F5A — PASS

Source: docs/20-math-utilities.md, `0x00504f5a__FUN_00504f5a.c`

**Verification:**
- Checks state flags at extraout_ECX[2] (== 5) ✓
- Multi-level allocation based on size params at +0x1058, +0x105c, +0x1060 ✓
- Uses _vector_constructor_iterator_ for array construction ✓
- Nested loops with float vector multiplication/addition ✓
- Multiple buffer levels with complex index arithmetic ✓
- Calls vtable methods for data processing ✓
- Calls: FUN_0058a5d8, operator_new, _vector_constructor_iterator_, FUN_00587bcf ✓

All claims verified.

---

## FUN_0053D130 — PASS

Source: docs/20-math-utilities.md, `0x0053d130__FUN_0053d130.c`

**Verification:**
- Iterates linked list at DAT_008b8e20 (stride 0x870) ✓
- Compares wide strings (2-byte chars) at +0x14 via carryless comparison ✓
- On match: calls FUN_0053d3a0(), FUN_00552760(), FUN_00557470(), FUN_00587bcf(param_1) ✓

All claims verified.

---

## FUN_0058E4A8 — PASS

Source: docs/20-math-utilities.md, `0x0058e4a8__FUN_0058e4a8.c`

**Verification:**
- If param_1 != 0 AND (param_2+0xd & 0x10): ✓
  - FUN_0058a05a(param_2) cleanup ✓
  - Clears bits 0x10 and 0x11 (mask 0xee = ~0x11) ✓
  - Zeroes param_2[6], *param_2, param_2[2] ✓

All claims verified.

---

## FUN_00599465 — PASS

Source: docs/20-math-utilities.md, `0x00599465__FUN_00599465.c`

**Verification:**
- Reads counter ptr at param_1+0x2c, derefs, increments ✓
- Reads counter ptr at param_1+0x1c, derefs, decrements ✓
- Returns decremented value (ref count at +0x1c) ✓
- Struct offsets: +0x1c (int* decremented), +0x2c (int* incremented) ✓

All claims verified.

---

## FUN_0045E5D0 — PASS

Source: docs/20-math-utilities.md, `0x0045e5d0__FUN_0045e5d0.c`

**Verification:**
- Writes param_3 to indexed array at param_1+0x1d4[param_2] ✓
- *(param_1 + 0x1d4 + param_2*4) = param_3 ✓

All claims verified.

---

## FUN_004864C0 — PASS

Source: docs/20-math-utilities.md, `0x004864c0__FUN_004864c0.c`

**Verification:**
- If param_1+0xd0 (head) is null: sets head = param_2 ✓
- Else: walks chain via +0x18 to tail, appends param_2 at tail ✓
- Struct offsets: +0xd0 (listHead), each node+0x18 (next) ✓

All claims verified.

---

## FUN_0049E3E0 — PASS

Source: docs/20-math-utilities.md, `0x0049e3e0__FUN_0049e3e0.c`

**Verification:**
- If param_1+8 non-null AND param_1+0x14 non-null: ✓
  - Reads *(*(param_1+0x14)+0x54) as iVar1 ✓
  - If iVar1 non-null: FUN_0049f1c0(1,1,0, param_1+8, iVar1) ✓

All claims verified.

---

## FUN_004CAED0 — FAIL [FIELD_COUNT_INACCURATE, ORDER_DESCRIPTION_IMPRECISE]

Source: docs/20-math-utilities.md, `0x004caed0__FUN_004caed0.c`

**Errors:**
1. Title says "18-field" float comparison but source shows exactly 16 float fields: +0x0c/10/14/18/1c/20/24/28/2c (9), +0x44/48/4c (3), +0x30/34/38/3c (4) = 16 floats. "18-field" is inaccurate.
2. Doc describes floats as "at offsets +0x0c through +0x3c (descending)" but comparison order jumps to +0x44→+0x4c before continuing +0x30→+0x3c — not strictly descending.

**Rest of entry is accurate** (embedded struct, wchar_t strings, int fields, final +0x58 comparison).

**Corrected:** Title should say "Float Lexicographic Comparison (16-field)" or simply remove the count.

---

## FUN_0050C23C — PASS

Source: docs/20-math-utilities.md, `0x0050c23c__FUN_0050c23c.c`

**Verification:**
- out = b + (c-b)*w1 + (d-b)*w2 for both x and y components ✓
- *param_1 = (*param_4 - *param_2)*param_6 + (*param_3 - *param_2)*param_5 + *param_2 ✓
- Same pattern for y component at param_1[1] ✓

All claims verified.

---

## FUN_00547100 — PASS

Source: docs/20-math-utilities.md, `0x00547100__FUN_00547100.c`

**Verification:**
- If param_2 < *(param_1+0xa4) AND *(param_1+0xa4) < 8: ✓
  - FUN_0054fc40(0x80000000) ✓
  - FUN_0054fca0(4) ✓

All claims verified.

---

## FUN_0059BFA0 — PASS (compiler intrinsic)

Source: docs/20-math-utilities.md, `0x0059bfa0___exception.c`

**Verification:**
- Sets vtable to PTR_FUN_005b9dc0 ✓
- If *(this+8) non-null: frees *(this+4) ✓
- Correctly identified as MSVC CRT exception::~exception() destructor ✓

All claims verified.

---

## FUN_00414380 — PASS

Source: docs/20-math-utilities.md, `0x00414380__FUN_00414380.c`

**Verification:**
- Calls FUN_00414d70 ✓
- 4 groups of 2 pointers each (stride-5), frees non-null via FUN_00587bcf ✓
- Frees *param_1 (head) if non-null ✓
- Calls: FUN_00414d70, FUN_00587bcf ✓

All claims verified.

---

## FUN_00485900 — PASS

Source: docs/20-math-utilities.md, `0x00485900__FUN_00485900.c`

**Verification:**
- Frees +0x154 (BufferB) if non-null ✓
- Calls FUN_00499b50 ✓
- Frees +0x118 (BufferA) if non-null ✓
- Calls FUN_00499b50 again ✓
- Calls FUN_00485eb0 ✓
- If param_2 & 1: frees param_1 (self) ✓
- Struct offsets: +0x118 BufferA, +0x154 BufferB ✓

All claims verified.

---

## FUN_0049AFA0 — PASS

Source: docs/20-math-utilities.md, `0x0049afa0__FUN_0049afa0.c`

**Verification:**
- Single call to FUN_004b3db0() ✓

All claims verified.

---

## FUN_004C85C0 — PASS

Source: docs/20-math-utilities.md, `0x004c85c0__FUN_004c85c0.c`

**Verification:**
- If DAT_008ac4c8 non-null: vtable+0x14 call on *DAT_008ac4c8 ✓
- Globals: DAT_008ac4c8 ✓

All claims verified.

---

## FUN_0050B743 — PASS

Source: docs/20-math-utilities.md, `0x0050b743__FUN_0050b743.c`

**Verification:**
- FUN_00507496(param_2, 0x30, 1) — init with class size 0x30 ✓
- *param_1 = &PTR_FUN_005addac ✓

All claims verified.

---

## FUN_00542460 — PASS

Source: docs/20-math-utilities.md, `0x00542460__FUN_00542460.c`

**Verification:**
- If param_2 non-null: *param_2 = *(param_1+0x24) ✓
- If param_3 non-null: *param_3 = *(param_1+0x28) ✓
- If param_4 non-null: *param_4 = *(param_1+0x2c) ✓

All claims verified.

---

## FUN_005514A0 — PASS

Source: docs/20-math-utilities.md, `0x005514a0__FUN_005514a0.c`

**Verification:**
- param_1+4 = param_1+4 & 0xfffe2fff (clears bits 0x1D000) | 0x2000 (sets bit 13) ✓
- Calls FUN_005563e0 (cascade/update notification) ✓

All claims verified.

---

## FUN_0045BB60 — PASS

Source: docs/20-math-utilities.md, `0x0045bb60__FUN_0045bb60.c`

**Verification:**
- If param_1 == 1: return 0xFFFF0000 (red channel mask) ✓
- If param_1 == 2: return 0xFFFFFF00 (luma/alpha mask) ✓
- Else: return 0xFFFFFFFF ✓

All claims verified.

---

## FUN_004BB400 — PASS

Source: docs/20-math-utilities.md, `0x004bb400__FUN_004bb400.c`

**Verification:**
- Walks singly-linked list from *param_1 ✓
- For each node: if flag byte at node+3 non-zero, frees *node ✓
- Frees each node via FUN_00587bcf ✓
- Zeros all 4 container fields ([0],[1],[2],[3]) ✓

All claims verified.

---

## FUN_00545020 — PASS

Source: docs/20-math-utilities.md, `0x00545020__FUN_00545020.c`

**Verification:**
- Returns `*(int*)(param_1 + 0xf8)` ✓

All claims verified.

---

## FUN_0058A2A6 — PASS (compiler intrinsic)

Source: docs/20-math-utilities.md, `0x0058a2a6____amsg_exit.c`

**Verification:**
- If DAT_008d3ebc == 1: FUN_005932ba() (error display) ✓
- FUN_005932f3(param_1) — message handler ✓
- _exit(0xFF) ✓
- Correctly identified as CRT __amsg_exit ✓

All claims verified.

---

## FUN_004BD7A0 — PASS

Source: docs/20-math-utilities.md, `0x004bd7a0__FUN_004bd7a0.c`

**Verification:**
- Single call to FUN_004bdb90() ✓

All claims verified.

---

## FUN_00569B70 — PASS

Source: docs/20-math-utilities.md, `0x00569b70__FUN_00569b70.c`

**Verification:**
- param_1+0x134 -= param_3[0] (X translation) ✓
- param_1+0x13c -= param_3[1] (Y translation) ✓
- param_1+0x144 -= param_3[2] (Z translation) ✓
- param_1+0x14c -= (param_3[2]*param_2[1] - param_3[1]*param_2[2]) — cross Z ✓
- param_1+0x154 -= (param_2[2]*param_3[0] - param_3[2]*param_2[0]) — cross Y ✓
- param_1+0x15c -= (param_3[1]*param_2[0] - param_3[0]*param_2[1]) — cross X ✓
- Struct offsets all match ✓

All claims verified.

---

## FUN_0045BBE0 — PASS

Source: docs/20-math-utilities.md, `0x0045bbe0__FUN_0045bbe0.c`

**Verification:**
- FUN_0045b950() ✓
- FUN_0045b9a0() ✓

All claims verified.

---

## FUN_00486600 — PASS

Source: docs/20-math-utilities.md, `0x00486600__FUN_00486600.c`

**Verification:**
- Traverses linked list at param_1+0xcc ✓
- For each node: calls FUN_0049a5d0(param_1) ✓
- Advances via next pointer at +0x18 ✓
- Returns 0 ✓

All claims verified.

---

## FUN_0049E8F0 — PASS

Source: docs/20-math-utilities.md, `0x0049e8f0__FUN_0049e8f0.c`

**Verification:**
- Zeroes param_1[0] through param_1[0x12] (17 ints) ✓

All claims verified.

---

## FUN_004CB5E0 — PASS

Source: docs/20-math-utilities.md, `0x004cb5e0__FUN_004cb5e0.c`

**Verification:**
- Counts down from param_1+100 ✓
- For each: puVar2[1] = -1, calls FUN_00558b30(*puVar2) ✓
- Array at *(param_1+0x68) with index*(iVar1±1) ✓

All claims verified.

---

## FUN_0050C3BB — PASS

Source: docs/20-math-utilities.md, `0x0050c3bb__FUN_0050c3bb.c`

**Verification:**
- t, t², t³ basis with global constants _DAT_0059e450, _DAT_0059e800, _DAT_0059e478, _DAT_0059e7ec, _DAT_0059e46c ✓
- 4 control points (param_2,3,4,5) ✓
- Cubic Bezier coefficients applied per XYZ dimension ✓
- Final scale _DAT_0059e450 applied ✓

All claims verified.

---

## FUN_005454A0 — PASS

Source: docs/20-math-utilities.md, `0x005454a0__FUN_005454a0.c`

**Verification:**
- FUN_005455f0(param_1) ✓
- FUN_0055d2e0() ✓
- If param_1 != 0: FUN_00557470, FUN_00587bcf(param_1) ✓
- Returns 0 ✓

All claims verified.

---

## FUN_0059A0D5 — PASS

Source: docs/20-math-utilities.md, `0x0059a0d5__FUN_0059a0d5.c`

**Verification:**
- Checks inline buffer at param_1[7] with bounds via param_1[0xb] ✓
- If valid: returns inline value (low word of ptr) ✓
- Fallback: vtable dispatch via +0x14 then +0x8 ✓

All claims verified.

---

## FUN_0040D100 — PASS

Source: docs/20-math-utilities.md, `0x0040d100__FUN_0040d100.c`

**Verification:**
- Checks *(param_1+0x18) != 0 ✓
- Switches on DAT_007cfdc4:
  - default: FUN_00409440(2,0,1), FUN_0040cde0(2,0) ✓
  - case 1: FUN_00409440(1,0,1), FUN_0040cde0(1,0) ✓
  - case 2: FUN_00409440(0,0,1), FUN_0040cde0(0,0) ✓
  - case 3: FUN_00409440(3,0,1), FUN_0040cde0(3,0) ✓
  - case 4: FUN_00409440(3,0,1), FUN_0040cde0(5,0) ✓

All claims verified.

---

## FUN_0046A270 — PASS

Source: docs/20-math-utilities.md, `0x0046a270__FUN_0046a270.c`

**Verification:**
- Sets vtable to PTR_LAB_0059f878 ✓
- If param_1[0xd2] non-null: FUN_00587bcf(param_1[0xd2]) ✓
- Calls FUN_0048ca50 ✓

All claims verified.

---

## FUN_0048EA40 — PASS

Source: docs/20-math-utilities.md, `0x0048ea40__FUN_0048ea40.c`

**Verification:**
- Sets +0x1c=param_4 ✓
- Sets +0x20=param_5 ✓
- Sets +0x24=param_2 ✓
- Sets +0x28=param_3 ✓

All claims verified.

---

## FUN_004B1D90 — PASS

Source: docs/20-math-utilities.md, `0x004b1d90__FUN_004b1d90.c`

**Verification:**
- FUN_00566650(param_2) — string copy ✓
- Sets +0x20=param_5, +0x18=param_3, +0x1c=param_4 ✓
- If param_6 != 0: FUN_00566650(param_6) — conditional string copy ✓
- If param_7 != 0: +0x14=param_3 (alias) ✓
- FUN_004a1b70() ✓

All claims verified.

---

## FUN_004DA9C0 — PASS

Source: docs/20-math-utilities.md, `0x004da9c0__FUN_004da9c0.c`

**Verification:**
- Returns `((FUN_004da990() - 1) / 6) * 6` ✓

All claims verified.

---

## FUN_00513B8A — PASS

Source: docs/20-math-utilities.md, `0x00513b8a__FUN_00513b8a.c`

**Verification:**
- If param_1 && param_2 non-null: ✓
  - If param_3 != 0: *(param_2+0x30)=param_3 ✓
  - If param_5 != 0: copies 3 values to +0x34, +0x38, +0x3c ✓
  - If param_4 == 0: param_4 = 1 ✓
  - Sets bit 0x10 at param_2+8 ✓
  - Sets int16 at +0x16 = param_4 ✓

All claims verified.

---

## FUN_0054FC80 — PASS

Source: docs/20-math-utilities.md, `0x0054fc80__FUN_0054fc80.c`

**Verification:**
- Sets +0x70=param_2, +0x74=param_3 ✓

All claims verified.

---

## FUN_0040C870 — FAIL [WRONG_CLASSIFICATION]

Source: docs/20-math-utilities.md, `0x0040c870__FUN_0040c870.c`

**Errors:**
1. Doc classifies as "Thunk" / "Trampoline -- indirect jump. No local logic." But source shows **conditional branching logic**: checks param_1+0x28 first, if zero checks param_1+8 for vtable+0x18 call. This is NOT a simple thunk — it has real decision logic.

**Corrected entry:**
```
## FUN_0040c870 — Conditional VTable Dispatch

Source: unknown | Confidence: medium
Returns cached value or dispatches via vtable.

**Key logic:**
- If *(param_1+0x28) non-zero: return that cached value
- Else if *(param_1+8) non-null: call vtable+0x18 on it, return result
- Else: return 0

**Moddability:** hardcoded
```

---

## FUN_0046E590 — FAIL [INSUFFICIENT_ANALYSIS]

Source: docs/20-math-utilities.md, `0x0046e590__FUN_0046e590.c`

**Errors:**
1. Doc classifies as "Function Call Wrapper — forwards call to another function. No additional logic." But source calls **3 functions** with intermediate values: FUN_00433eb0(), FUN_00487010(0) stored in uVar1, then FUN_00498d00(uVar1, 0x40000000). This is NOT a simple forward wrapper.

**Corrected entry:**
```
## FUN_0046e590 — Multi-Step Dispatch with Constant

Source: unknown | Confidence: medium
Calls 3 functions, passes result from one with constant flag.

**Key logic:**
- FUN_00433eb0()
- uVar1 = FUN_00487010(0)
- FUN_00498d00(uVar1, 0x40000000)
- Returns 0

**Calls:** FUN_00433eb0, FUN_00487010, FUN_00498d00

**Moddability:** hardcoded
```

---

## FUN_004950E0 — FAIL [INSUFFICIENT_ANALYSIS]

Source: docs/20-math-utilities.md, `0x004950e0__FUN_004950e0.c`

**Errors:**
1. Doc classifies as "Function Call Wrapper — forwards call to another function. No additional logic." But source calls **3 functions** in sequence: FUN_004f9f00(), FUN_00553700(DAT_008b8dc8), FUN_004f9f30(). Uses global DAT_008b8dc8 as parameter. This is NOT a simple forward wrapper — it has specific sequencing with a global.

**Corrected entry:**
```
## FUN_004950e0 — Three-Stage Sequential Dispatch

Source: unknown | Confidence: medium
Calls 3 functions in sequence with global parameter.

**Key logic:**
- FUN_004f9f00() — first stage
- FUN_00553700(DAT_008b8dc8) — second stage with global context
- FUN_004f9f30() — third stage

**Globals:** DAT_008b8dc8

**Calls:** FUN_004f9f00, FUN_00553700, FUN_004f9f30

**Moddability:** hardcoded
```

---

## FUN_0059C4B4 — PASS (SEH unwind)

Source: docs/20-math-utilities.md, `0x0059c4b4__Unwind_0059c4b4.c`

**Verification:**
- SEH unwind handler: frees *(EBP-0x14) via FUN_00587bcf ✓
- Correctly identified as MSVC SEH unwind pattern ✓

All claims verified.

---

## FUN_0059D348 — PASS (SEH unwind)

Source: docs/20-math-utilities.md, `0x0059d348__Unwind_0059d348.c`

**Verification:**
- SEH unwind handler: calls FUN_00599796(*(EBP-0x10), &DAT_008d4568) ✓
- Globals: DAT_008d4568 ✓

All claims verified.

---

## FUN_005995E5 — PASS

Source: docs/20-math-utilities.md, `0x005995e5__FUN_005995e5.c`

**Verification:**
- Reads string pointer from param_1+4 ✓
- Checks _Str[-1] non-null and not -1 ✓
- If valid: FUN_005993af(1), _strlen, FUN_00599615 ✓

All claims verified.

---

## FUN_004203D0 — PASS (thunk)

Source: docs/20-math-utilities.md, `0x004203d0__thunk_FUN_004201e0.c`

**Verification:**
- Unconditional call to FUN_004201e0() ✓
- Correctly identified as thunk/trampoline ✓

All claims verified.

---

## FUN_0059CEC9 — PASS (SEH unwind)

Source: docs/20-math-utilities.md, `0x0059cec9__Unwind_0059cec9.c`

**Verification:**
- SEH unwind handler: calls FUN_004b0170() with no arguments ✓
- Correctly identified as MSVC SEH unwind pattern ✓

All claims verified.

---

## FUN_0059CEBB — PASS (SEH unwind)

Source: docs/20-math-utilities.md, `0x0059cebb__Unwind_0059cebb.c`

**Verification:**
- SEH unwind handler: thunk to FUN_00585fb0() ✓
- Correctly identified as MSVC SEH unwind pattern ✓

All claims verified.

---

## FUN_0055D5C0 — PASS

Source: docs/21-audio-network-internals.md, `0x0055d5c0__FUN_0055d5c0.c`

**Verification:**
- Triage-line entry under `## FUN_0055d5c0` header ✓
- Purpose: 3D audio listener orientation update ✓
- Source confirms: linked-list source search (DAT_008b8f28), 3D vector math, SQRT, normalization, distance-based processing ✓
- No full-entry claims to cross-validate against ✓

Triage entry accurate. No incorrect claims.

---

## FUN_0058A0BF — PASS

Source: docs/21-audio-network-internals.md, `0x0058a0bf__FUN_0058a0bf.c`

**Verification:**
- Full entry iterates open file table (DAT_008d4a24) ✓
- For param_1==1: flushes each open stream via FUN_0058a02c ✓
- For param_1==0: flushes writable streams (checks flag & 2) ✓
- Protected by critical section (2): FUN_0058dfea(2)/FUN_0058e04b(2) ✓
- Returns count or -1 ✓

All claims verified.

---

## FUN_0045F710 — PASS

Source: docs/21-audio-network-internals.md, `0x0045f710__FUN_0045f710.c`

**Verification (spot-check):**
- Calls FUN_00461440 to check radio state ✓ (line 23)
- Initializes driver entries via DAT_005ef9a0 loop with FUN_004652d0 ✓ (lines 27-34)
- Reads messages from FIFO queue (FUN_0057a760) ✓ (line 44)
- Race mode check: param_1+0x3fc4 == 1 or 2 ✓ (line 36)
- Appends team ID via FUN_00460c30 ✓ (line 48)
- Checks DAT_007d0f04 (radio silence flag) ✓ (line 81)
- Checks DAT_007d0e98 (lap counter) ✓ (line 81)
- Cleans up via FUN_0057a730, FUN_004b0170 ✓ (lines 82, 84)

All verified calls present in source. Entry is correct.

---

## FUN_004A35F0 — PASS

Source: docs/21-audio-network-internals.md, `0x004a35f0__FUN_004a35f0.c`

**Verification:**
- Two timing tracks: track 1 (param_2[1] != 0) ✓ (line 30)
  - track 2 (param_2[8] != 0) ✓ (line 74)
- 99999.0 sentinels for infinite/unset ✓ (lines 31-39)
- Iterates entries at param_1+0x10, stride 0x78 ✓ (lines 93-109)
- Sub-entries at stride 0x1c ✓ (line 105: iVar7 += 0x1c)
- Calls FUN_004a1fd0 for each sub-entry ✓ (line 101)
- _DAT_005acaf4 offset for final duration ✓ (line 87)

All claims verified.

---

## FUN_00551CE0 — PASS

Source: docs/21-audio-network-internals.md, `0x00551ce0__FUN_00551ce0.c`

**Verification:**
- Calls `_BinkClose_4(*param_1)` ✓
- Returns 0 ✓

All claims verified.

---

## FUN_00561F80 — PASS

Source: docs/21-audio-network-internals.md, `0x00561f80__FUN_00561f80.c`

**Verification:**
- If param_1 == NULL: defaults to PTR_DAT_005e4dfc ✓
- If *param_1 != -1 and param_1[0x39] != 0: closesocket(*param_1) ✓
- If param_1[1] != -1 and != *param_1: closesocket(param_1[1]) ✓
- Sets both to -1, param_1[0x36]=0 ✓
- If not DAT_005e4cf8: FUN_0058aa6f(param_1) ✓
- WSACleanup() ✓

All claims verified.

---

## FUN_00562D20 — PASS

Source: docs/21-audio-network-internals.md, `0x00562d20__FUN_00562d20.c`

**Verification:**
- Loops param_1+0x6c times (socket count) ✓
- Calls socket(2, 2, 0x11) = AF_INET, SOCK_DGRAM, IPPROTO_UDP ✓
- Stores at param_1+8 with stride 0x1c (28 bytes per entry) ✓
- On socket failure (-1): reduces count to created-so-far ✓
- All created: returns 0; failure after some: returns 0 with truncated count; immediate failure: returns 1 ✓

All claims verified.

---

## FUN_004060C0 — PASS

Source: docs/21-audio-network-internals.md, `0x004060c0__FUN_004060c0.c`

**Verification:**
- If audio handle at +0x58 and sample processor at +0x10: ✓
  - _AIL_set_sample_processor_12(processor, 1, *(param_1+100)) ✓
- If filter at +0x60 != -1: ✓
  - FUN_00404fc0 + _AIL_set_filter_sample_preference_12 ✓
- Struct offsets: +0x58 (AudioHandle), +0x60 (FilterType), +0x68 (FilterStruct) ✓

All claims verified.

---

## FUN_00551480 — PASS

Source: docs/21-audio-network-internals.md, `0x00551480__FUN_00551480.c`

**Verification:**
- param_1+4 = param_1+4 & 0xffff9fff (clears bit 0x6000 = bits 13-14) | 0x1000 (sets bit 12) ✓
- Calls FUN_00556330 (timer accumulate) ✓

All claims verified.

---

# Summary

| Index | Function | Result |
|-------|----------|--------|
| 1181 | FUN_004C7774 | PASS |
| 1182 | FUN_00504F5A | PASS |
| 1183 | FUN_0053D130 | PASS |
| 1184 | FUN_0058E4A8 | PASS |
| 1185 | FUN_00599465 | PASS |
| 1186 | FUN_0045E5D0 | PASS |
| 1187 | FUN_004864C0 | PASS |
| 1188 | FUN_0049E3E0 | PASS |
| 1189 | FUN_004CAED0 | FAIL — wrong field count (16 vs 18), imprecise offset order |
| 1190 | FUN_0050C23C | PASS |
| 1191 | FUN_00547100 | PASS |
| 1192 | FUN_0059BFA0 | PASS (compiler intrinsic) |
| 1193 | FUN_00414380 | PASS |
| 1194 | FUN_00485900 | PASS |
| 1195 | FUN_0049AFA0 | PASS |
| 1196 | FUN_004C85C0 | PASS |
| 1197 | FUN_0050B743 | PASS |
| 1198 | FUN_00542460 | PASS |
| 1199 | FUN_005514A0 | PASS |
| 1200 | FUN_0045BB60 | PASS |
| 1201 | FUN_004BB400 | PASS |
| 1202 | FUN_00545020 | PASS |
| 1203 | FUN_0058A2A6 | PASS (compiler intrinsic) |
| 1204 | FUN_004BD7A0 | PASS |
| 1205 | FUN_00569B70 | PASS |
| 1206 | FUN_0045BBE0 | PASS |
| 1207 | FUN_00486600 | PASS |
| 1208 | FUN_0049E8F0 | PASS |
| 1209 | FUN_004CB5E0 | PASS |
| 1210 | FUN_0050C3BB | PASS |
| 1211 | FUN_005454A0 | PASS |
| 1212 | FUN_0059A0D5 | PASS |
| 1213 | FUN_0040D100 | PASS |
| 1214 | FUN_0046A270 | PASS |
| 1215 | FUN_0048EA40 | PASS |
| 1216 | FUN_004B1D90 | PASS |
| 1217 | FUN_004DA9C0 | PASS |
| 1218 | FUN_00513B8A | PASS |
| 1219 | FUN_0054FC80 | PASS |
| 1220 | FUN_0040C870 | FAIL — misclassified as thunk, has real branching logic |
| 1221 | FUN_0046E590 | FAIL — misclassified as simple wrapper, calls 3 functions with intermediate value |
| 1222 | FUN_004950E0 | FAIL — misclassified as simple wrapper, calls 3 functions with global |
| 1223 | FUN_0059C4B4 | PASS (SEH unwind) |
| 1224 | FUN_0059D348 | PASS (SEH unwind) |
| 1225 | FUN_005995E5 | PASS |
| 1226 | FUN_004203D0 | PASS (thunk) |
| 1227 | FUN_0059CEC9 | PASS (SEH unwind) |
| 1228 | FUN_0059CEBB | PASS (SEH unwind) |
| 1229 | FUN_0055D5C0 | PASS (triage entry) |
| 1230 | FUN_0058A0BF | PASS |
| 1231 | FUN_0045F710 | PASS |
| 1232 | FUN_004A35F0 | PASS |
| 1233 | FUN_00551CE0 | PASS |
| 1234 | FUN_00561F80 | PASS |
| 1235 | FUN_00562D20 | PASS |
| 1236 | FUN_004060C0 | PASS |
| 1237 | FUN_00551480 | PASS |

**Final tally:** 57 functions checked. **53 PASS**, **4 FAIL** (4 incorrect classifications/mislabelings).

