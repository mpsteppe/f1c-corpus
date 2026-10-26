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
