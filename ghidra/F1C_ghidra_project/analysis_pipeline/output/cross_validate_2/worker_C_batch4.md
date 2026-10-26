# Cross-Validation Results: docs/10, docs/17, docs/18

Date: 2026-07-15
Validator: ARCHITECT
Total: 25 functions (7 from docs/10, 13 from docs/17, 5 from docs/18)

---

## Overall Summary

| Result | Count |
|--------|-------|
| PASS | 6 |
| FAIL (no doc entry) | 19 |
| FAIL (content mismatch) | 0 |

**Only 6/25 functions have `## FUN_` or `### FUN_` doc entries to validate.**
Remaining 19 exist only as triage lines in `decompiled_full_index_final.md` — no full entry to cross-validate against.

---

## From docs/10-vehicle-physics.md

### 1. FUN_004DFCE0 — FAIL (NO DOC ENTRY)

**Expected source:** `decompiled_all\0x004dfce0__FUN_004dfce0.c`
**Doc:** No `## FUN_` or `### FUN_` entry exists in any `docs/` file.
**References found:** Only `docs/12-globals-reference.md` lines 4548-4549 (DAT_005D4DB4, DAT_005D4D14).
**Source analysis (391 lines):** Vehicle part instance setup. Registers wheel/spindle instances (LFTIRE, LFSPINDLE, RFTIRE, etc.), wing debris parts, cockpit/suspension/helmet/brakelight/headlight sub-parts. Allocates CATSTEER objects. Processes tire tread textures. Complex 4-wheel setup loop.
**Verdict:** FAIL — needs doc entry.

---

### 2. FUN_00432220 — SettingsCopy Setup File Copy — PASS

**Source:** `decompiled_all\0x00432220__FUN_00432220.c` (172 lines)
**Doc:** Lines 660-681 in `docs/10-vehicle-physics.md`

| Doc Claim | Source Verification | Result |
|-----------|-------------------|--------|
| Reads source setup name via FUN_00566650 | Line 40: `FUN_00566650(puVar4)` | ✓ |
| Iterates DAT_008ac488 (setup count), stride 0x18c | Line 50: `DAT_008ac488`, line 165: `local_320 + 0x18c` | ✓ |
| Gets setup name via FUN_004326a0 | Line 56: `FUN_004326a0()` | ✓ |
| Uses FUN_00423a00 to copy name to message buffer | Line 64: `FUN_00423a00(local_300, &DAT_005ec4cc)` | ✓ |
| DAT_007d03f8 flag filter | Line 77: `DAT_007d03f8 != '\0'` | ✓ |
| DAT_007ce5ec filter string | Line 79: `DAT_007ce5ec` | ✓ |
| Iterates available setups via FUN_005679c0 ("SettingsCopy") | Line 89: `FUN_005679c0(PTR_s_SettingsCopy_005c3fa8)` | ✓ |
| Calls FUN_00433b60 to copy setup data | Line 137: `FUN_00433b60(local_200, pcVar7, 0)` | ✓ |
| Calls FUN_00568b00 to finalize write | Lines 139, 152: `FUN_00568b00()` | ✓ |
| Returns 1 if processed, 0 if none | Line 169: `return local_333` | ✓ |

**Verdict:** PASS — all claims verified. Good entry.

---

### 3. FUN_004471F0 — FAIL (NO DOC ENTRY)

**Source:** `analyzed\0x004471f0__FUN_004471f0.c` (30 lines)
**Doc:** No entry exists in any `docs/` file.
**Source analysis:** Compares two doubles at param_1+0x1c5c and param_1+0x1c84. If param_2==0 and bVar1 true: sets param_1+0x1d10 via randomized formula with DAT_008ab274 table. If param_2!=0 and bVar1 true: copies values from +0x1c84/+0x1c88 to +0x1c5c/+0x1c60. Small vehicle physics threshold/state function.
**Verdict:** FAIL — needs doc entry.

---

### 4. FUN_004DB170 — FAIL (NO DOC ENTRY)

**Source:** `analyzed\0x004db170__FUN_004db170.c` (98 lines)
**Doc:** No entry exists in any `docs/` file.
**Source analysis:** HUD/text display function. Checks `_DAT_005ea4e8` timing threshold. Calls `FUN_00408490()` (timer). Performs string comparison via inline byte-by-byte compare. Copies string to DAT_005ec4cc. Calls `FUN_004d7e40` (text render). Loop rendering 0x29 (41) lines of colored text with DAT_005d4aec. Not physics-related — appears to be debug overlay or telemetry display.
**Verdict:** FAIL — needs doc entry.

---

### 5. FUN_004F8250 — FAIL (NO DOC ENTRY)

**Source:** `analyzed\0x004f8250__FUN_004f8250.c` (19 lines)
**Doc:** No entry exists in any `docs/` file.
**Source analysis:** (19 bytes) COM-like object destructor. Calls vtable+8 then vtable+0x18, then if non-null calls `(*vtable)(1)`. Nulls pointer. Simple cleanup/release function.
**Verdict:** FAIL — needs doc entry.

---

### 6. FUN_0054F5C0 — SceneBatchRenderCheck — PASS

**Source:** `analyzed\0x0054f5c0__FUN_0054f5c0.c` (65 lines)
**Doc:** Lines 2243-2262 in `docs/10-vehicle-physics.md` (`###` header, lightweight entry)

| Doc Claim | Source Verification | Result |
|-----------|-------------------|--------|
| Checks param_2+0x3c for flag bit 1; returns early | Line 18: `*(uint*)(param_2+0x3c) & 2` (bit 1 = value 2) | ✓ |
| Compares DAT_008c5f40 against capacity from param_1+0x1e0 | Line 19: `DAT_008c5f40 < *(int*)(*(int*)(param_1+0x1e0)+4)` | ✓ |
| Flag bit 4 → FUN_0054b570 reset batch state | Lines 21-22: `& 0x10` (bit 4) → `FUN_0054b570(0, iVar6)` | ✓ |
| Sets iVar6+0x14 bit 0x20000000 | Line 23-24: `*(uint*)(iVar6+0x14) \| 0x20000000` | ✓ |
| Calls D3D device transform via DAT_008b8f24 vtable+4 | Line 25: `(**(code**)(*DAT_008b8f24+4))(DAT_008b8f24, ...)` | ✓ |
| Flag 0x40 on iVar6 → distance check | Line 28: `*(byte*)(iVar6+0x14) & 0x40` | ✓ |
| Distance vector computed, squared < radius check | Lines 29-43 | ✓ |
| Dispatches to FUN_0054f2f0 (primary) or FUN_0054eed0 (alternate) | Lines 46/49 | ✓ |
| Returns 0 on success, 1 if capacity exceeded | Line 60: `uVar8 = 1` (capacity full) | ✓ |

**Minor note:** Doc says "flag bit 1" for early return. Code checks `& 2`, which IS bit 1 (0-indexed). Correct.
**Verdict:** PASS — all claims accurate.

---

### 7. FUN_004C71C0 — SetupCarLightingAndRender — PASS (structural offsets)

**Source:** `analyzed\0x004c71c0__FUN_004c71c0.c` (91 lines)
**User note:** Listed as from `docs/13-struct-offsets.md`. Main entry is in `docs/19-renderer.md` lines 172-188.
**Struct offset table:** `docs/13-struct-offsets.md` lines 4477-4484.

| Offset Claim | Doc Source | Source Verification | Result |
|-------------|-----------|-------------------|--------|
| +0x83c float[3]×4 WheelPositions stride 0x128 | 13-struct-offsets.md | Line 26: loop `iVar4 += 0x128` (4 iters), `*(float*)(iVar4 + param_1 + 0x83c)` | ✓ |
| +0x704 float[16] ViewMatrix | 13-struct-offsets.md | Line 19: `FUN_004b2310(param_1+0x704, param_1+0x744)` | ✓ |
| +0x744 float[16] WorldMatrix | 13-struct-offsets.md | Line 19: second arg to matrix multiply | ✓ |
| +0x34f8 float[4] DiffuseColor | 13-struct-offsets.md | Line 20: `FUN_004b2480(param_1+0x34f8)` | ✓ |
| +0x3510 float[4] SpecularColor | 13-struct-offsets.md | Line 21: `FUN_004b25d0(param_1+0x3510)` | ✓ |
| +0x3540 int EnvMapHandle | 13-struct-offsets.md | Line 22: `FUN_004b2750(param_1+0x3540)` | ✓ |

**Call list (docs/19-renderer.md line 184) vs source:**

| Doc Call | Source Line | Result |
|----------|------------|--------|
| FUN_004b33b0 | 18 | ✓ |
| FUN_004b2310 | 19 | ✓ |
| FUN_004b2480 | 20 | ✓ |
| FUN_004b25d0 | 21 | ✓ |
| FUN_004b2750 | 22 | ✓ |
| FUN_004b2840 | 26 | ✓ |
| FUN_004b2930 | 32 | ✓ |
| FUN_004b29b0 | 33 | ✓ |
| FUN_004b2a10 | 34 | ✓ |
| FUN_004b2a40 | 42 | ✓ |
| FUN_004b2aa0 | 46 | ✓ |
| FUN_004b2b10 | 84 | ✓ |
| FUN_004b2b60 | 85 | ✓ |
| FUN_004c7c00 | 86 | ✓ |
| FUN_004b2ae0 | 87 | ✓ |

**Struct offset table verified.** Call list matches.
**Verdict:** PASS for offset/call claims. Note: docs/19-renderer.md entry is sparse — only 5 lines of "Key logic" for a 91-line function. Missing bitflag manipulation (lines 35-83), DAT_007c54dc reference (line 85), FUN_004e18c0 call (line 45), wheel throttle array at +0x35bc (line 23). Entry is accurate but incomplete.

---

## From docs/17-physics-collision.md

### 8. FUN_004E96C0 — FAIL (NO DOC ENTRY)

**Source:** `analyzed\0x004e96c0__FUN_004e96c0.c` (147 lines)
**Doc:** No `## FUN_` or `### FUN_` entry. Only triage line at index line 3213: `game_logic | vehicle struct access`.
**Also found in:** `docs/19-renderer.md` line 3671 as a triage entry: `collision | vehicle position proximity check against track surface with per-wheel overlap test`.
**Source analysis:** Proximity/distance check. Computes position delta between two 3D points (param_1+0x3aac vs 0x34d4). Compares squared distance against `_DAT_005ad1d0` and `_DAT_005ad1c8` thresholds. Iterates 4 wheel objects (stride 0x4a = 74). Calls `FUN_004e9630` for additional object data. Performs dot-product overlap tests with min/max of per-wheel extents. Returns bit-encoded comparison results. This matches the 19-renderer.md triage description well.
**Verdict:** FAIL — needs full doc entry.

---

### 9. FUN_0044D070 — FAIL (NO DOC ENTRY)

**Source:** `analyzed\0x0044d070__FUN_0044d070.c` (12 bytes)
**Doc:** No entry. Index line 903: `collision | collision detection`.
**Source analysis:** Single call: `FUN_00587b3e(&DAT_0044d080)`. 12-byte thunk/delegate.
**Verdict:** FAIL — needs doc entry (can be minimal, thunk pattern).

---

### 10. FUN_0044BC10 — FAIL (NO DOC ENTRY)

**Source:** `analyzed\0x0044bc10__FUN_0044bc10.c` (64 bytes, 19 lines)
**Doc:** No entry. Index line 840: `collision | collision detection`.
**Source analysis:** Recursive function: if param_1 < 3 returns `(uint)(0 < param_1)` (i.e., 0→0, 1→1, 2→1). Otherwise calls `FUN_0044bc10(param_1 - param_1/2) + 1 + FUN_0044bc10(param_1/2)`. Returns count of tree nodes in a binary split — likely computes collision tree depth or node count. NOT "collision detection" — more like tree size computation.
**Index misclassification:** Should be `math_util` or `algorithm`, not `collision`.
**Verdict:** FAIL — needs doc entry with corrected classification.

---

### 11. FUN_0044D190 — FAIL (NO DOC ENTRY)

**Source:** `analyzed\0x0044d190__FUN_0044d190.c` (12 bytes)
**Doc:** No entry. Index line 909: `collision | collision detection`.
**Source analysis:** Single call: `FUN_00587b3e(&DAT_0044d1a0)`. 12-byte thunk.
**Verdict:** FAIL — needs doc entry.

---

### 12. FUN_0044D460 — FAIL (NO DOC ENTRY)

**Source:** `analyzed\0x0044d460__FUN_0044d460.c` (19 lines)
**Doc:** No entry. Index line 924: `collision | collision detection`.
**Source analysis:** Global state init: `DAT_007cccf0 = 0xf` (15); zeros `_DAT_007cccf4`, `DAT_007cccf8`, `_DAT_007cccfc`, `_DAT_007ccd00`, `_DAT_007ccd04`. Matches the "Global Init Set 0x0f" pattern (cf. FUN_0044d700 set 0x16, FUN_0044de80 set 0x37, etc.).
**Verdict:** FAIL — needs doc entry.

---

### 13. FUN_0044CB30 — FAIL (NO DOC ENTRY)

**Source:** `analyzed\0x0044cb30__FUN_0044cb30.c` (12 bytes)
**Doc:** No entry. Index line 875: `collision | collision detection`.
**Source analysis:** Single call: `FUN_00587b3e(&DAT_0044cb40)`. 12-byte thunk.
**Verdict:** FAIL — needs doc entry.

---

### 14. FUN_0045B840 — FAIL (NO DOC ENTRY)

**Source:** `analyzed\0x0045b840__FUN_0045b840.c` (59 lines)
**Doc:** No entry. Index line 1170: `collision | collision detection`.
**Also referenced in:** `docs/13-audit-report.md` line 789 (offset +0x31c type conflict).
**Source analysis:** Collision wheel/surface interaction function. Calls `FUN_0045bb00()` and `FUN_0045b660()`. Iterates 8 wheels (not 4!) with stride 0x5c. Checks `*(float*)(wheel_base + 0x90) > DAT_0059e440` threshold. Calls `FUN_004dd030` for visual/particle effect at wheel position. Decrements float at +0x90 by `_DAT_008afe90`. Up to 4 active contacts (line 48: `if (3 < local_14) return`). Calls `FUN_0045b430` per wheel. Matches collision detection pattern with visual feedback.
**Verdict:** FAIL — needs doc entry.

---

### 15. FUN_0044E4E0 — FAIL (NO DOC ENTRY)

**Source:** `analyzed\0x0044e4e0__FUN_0044e4e0.c` (19 lines)
**Doc:** No entry. Index line 1012: `collision | collision detection`.
**Source analysis:** Global state init: `DAT_007cd0c8 = 0x50` (80); zeros `_DAT_007cd0cc`, `DAT_007cd0d0`, `_DAT_007cd0d4`, `_DAT_007cd0d8`; `DAT_007cd0dc = 18000`. Same pattern as FUN_0044d700/FUN_0044de80/FUN_0044e600 — all collision global init functions.
**Verdict:** FAIL — needs doc entry.

---

### 16. FUN_0044CCB0 — FAIL (NO DOC ENTRY)

**Source:** `analyzed\0x0044ccb0__FUN_0044ccb0.c` (12 bytes)
**Doc:** No entry. Index line 883: `collision | collision detection`.
**Source analysis:** Single call: `FUN_00587b3e(&DAT_0044ccc0)`. 12-byte thunk.
**Verdict:** FAIL — needs doc entry.

---

### 17. FUN_00453100 — Collision Result Processing — PASS

**Source:** `analyzed\0x00453100__FUN_00453100.c` (51 lines)
**Doc:** Lines 3519-3535 in `docs/17-physics-collision.md`

| Doc Claim | Source Verification | Result |
|-----------|-------------------|--------|
| FUN_00404f10() + DAT_007c569c == 5 → zeros param_1[9], param_1[10] | Lines 15-19: `cVar3 = FUN_00404f10(); if (cVar3 && DAT_007c569c == 5) { param_1[9]=0; param_1[10]=0; return; }` | ✓ |
| Switch on param_1[0] (collision state) | Line 21: `iVar2 = *param_1` | ✓ |
| Case 0: FUN_0044f460(param_1[1]), byte result → param_1[9] | Lines 23-24: `uVar4 = FUN_0044f460(param_1[1]); uVar4 &= 0xff` | ✓ |
| Case 0: if 0 → DAT_0059e440 (0.0f), else _DAT_0059e43c (-1.0f) | Lines 43-47: `if (uVar4==0) param_1[10]=DAT_0059e440 else param_1[10]=_DAT_0059e43c` | ✓ |
| Case 1: reads uint from param_1[7]+0x10 | Line 40: `uVar4 = *(uint*)(param_1[7] + 0x10)` | ✓ |
| Case 2: ABS(fVar1), _DAT_0059e880 (0.5f) threshold | Lines 31-37: `ABS(fVar1) <= (float)_DAT_0059e880` | ✓ |
| Case 2: ≤0.5f → param_1[9]=0, else =1 | Lines 33-37 | ✓ |

**Verdict:** PASS — all claims verified. Entry is accurate.

---

### 18. FUN_0044C9E0 — FAIL (NO DOC ENTRY)

**Source:** `analyzed\0x0044c9e0__FUN_0044c9e0.c` (17 lines)
**Doc:** No entry. Index line 868: `collision | collision detection`.
**Source analysis:** Global init: `DAT_007cccb0 = 0xb` (11); zeros `_DAT_007cccb4`, `_DAT_007cccb8`; `_DAT_007cccbc = 0x3f800000` (1.0f). Another "Collision Global Init" in the series (set 0x0b). Note the float value 1.0f in last field — uniqueness among the init series.
**Verdict:** FAIL — needs doc entry.

---

### 19. FUN_0044DD90 — FAIL (NO DOC ENTRY)

**Source:** `analyzed\0x0044dd90__FUN_0044dd90.c` (12 bytes)
**Doc:** No entry. Index line 973: `collision | collision detection`.
**Source analysis:** Single call: `FUN_00587b3e(&DAT_0044dda0)`. 12-byte thunk.
**Verdict:** FAIL — needs doc entry.

---

### 20. FUN_00456F70 — FAIL (NO DOC ENTRY)

**Source:** `analyzed\0x00456f70__FUN_00456f70.c` (23 lines)
**Doc:** No entry. Index line 1127: `collision | collision detection`.
**Source analysis:** Computes a force/multiplier: `fVar1 = _DAT_0059ef9c` (or `_DAT_0059efa0` if param_3==1). If param_2==0, multiplies by `_DAT_0059e670`. Then: `FUN_00456fb0(fVar1 * param_4 + *(float*)(param_1+0xac))`. Applies parameterized force to an accumulator at param_1+0xac via FUN_00456fb0. This is likely a physics force application function, not just "collision detection".
**Index misclassification:** Too broad — should be `physics_math` or `dynamics`.
**Verdict:** FAIL — needs doc entry.

---

## From docs/18-physics-dynamics.md

### 21. FUN_0056ECF0 — FAIL (NO DOC ENTRY)

**Source:** `analyzed\0x0056ecf0__FUN_0056ecf0.c` (95 lines)
**Doc:** No entry in `docs/18-physics-dynamics.md`. Index line 4969: `unknown | --`.
**Referenced in:** `docs/30-impl-specs/17-physics-dynamics-and-vehicle-simulation-spec.md` lines 457, 788, 821 as "ForceClear".
**Source analysis:** Constraint solver force accumulator clear function. Takes a constraint system descriptor (`param_1` array). If `param_1[0xc]` (vtable) is null: clears matrix at `param_1[10]` (8-byte entries, [8]×[8] matrix), clears bias vector at `param_1[0xb]`. Calls `FUN_0056ec00()`. Then three loops for different constraint types (body constraints, joint constraints, contact constraints), each clearing force accumulators at offset +0x30/+0x31/+0x32. If vtable non-null: delegates to vtable+0x1c for custom clear, then vtable+0x14. Otherwise calls `FUN_0056cd70`. Matches "ForceClear" label.
**Verdict:** FAIL — needs full doc entry.

---

### 22. FUN_00496030 — Car Crash Damage Processing — PASS

**Source:** `analyzed\0x00496030__FUN_00496030.c` (117 lines)
**Doc:** Lines 549-564 in `docs/18-physics-dynamics.md`

| Doc Claim | Source Verification | Result |
|-----------|-------------------|--------|
| Returns early if impact speed (+0xdc) <= 0 | Line 17: `if (*(float*)(param_1+0xdc) <= DAT_0059e440) return 0` | ✓ |
| Impact speed threshold 0x3c23d70a → _rand() | Line 26: `if (*(int*)(param_1+0xdc) != 0x3c23d70a)`; Line 28: `_rand()` | ✓ |
| Sets X/Z impulse offsets (+0x1580/0x1584) | Lines 44-45 (and throughout switch): `param_1+0x1580` and `param_1+0x1584` | ✓ |
| 8 patterns for case 0 | Lines 42-75: 8 cases (0-7, includes default) | ✓ |
| 3 patterns for case 1 | Lines 77-91: 3 cases (0, 1, 2) | ✓ |
| Cases 2-4: clears damage flag at +0x18ec | Lines 92-97: case 2/3/4 fall through to line 95-96 | ✓ |
| Decrements speed via FUN_00498730 return | Lines 99-100: `fVar6 = FUN_00498730(); *(float*)(param_1+0xdc) -= fVar6` | ✓ |
| While speed > 0: sparks FUN_00498740 | Line 105: `FUN_00498740()` | ✓ |
| Effects FUN_00495dc0 | Line 106: `FUN_00495dc0(...)` | ✓ |
| Audio FUN_00497100 | Line 107: `FUN_00497100(param_2)` | ✓ |
| Audio FUN_00497250 | Line 108: `FUN_00497250(1)` | ✓ |
| Returns 1 (active) or 0 (inactive) | Line 17: `return 0`; lines 109/114: `return 1` | ✓ |

**Minor note:** Doc says "8 patterns for case 0, 3 for case 1" — code shows case 0 has default+7 explicit = 8; case 1 has 3 explicit cases (0,1,2). Correct.
**Verdict:** PASS — all claims verified.

---

### 23. FUN_00504933 — Direct3D Texture Resampling (Bilinear/Upscale) — PASS

**Source:** `analyzed\0x00504933__FUN_00504933.c` (126 lines)
**Doc:** Lines 978-996 in `docs/18-physics-dynamics.md`
**Note:** Ghidra decompilation is messy — function has no params in signature (`extraout_ECX` register tracking lost). Doc correctly interprets despite mangled decomp.

| Doc Claim | Source Verification | Result |
|-----------|-------------------|--------|
| Checks texture format == 2 | Line 22: `*(char*)(extraout_ECX[1]+2) == '\x02'` | ✓ (format check present) |
| Allocates source buffer (0x10 stride) | Lines 25-33: `operator_new(iVar1 << 4)` (×16 = 0x10 stride) | ✓ |
| Allocates destination buffer (0x10 stride) | Lines 40-49: same pattern | ✓ |
| Scale factors: srcW<<16 / dstW | Line 64: `(uint)(iVar3 << 0x10) / uVar8` | ✓ |
| Scale factors: srcH<<16 / dstH | Line 65: `(uint)(*(int*)(iVar1+0x105c)<<0x10) / uVar10` | ✓ |
| Scale factors: srcD<<16 / dstD | Line 66: `(uint)(*(int*)(iVar1+0x1060)<<0x10) / uVar4` | ✓ |
| Triple loop (depth, height, width) | Lines 67-111: outer Z, middle Y, inner X | ✓ |
| Fixed-point arithmetic (shifts by 16) | Lines 79-80: `uVar8 >> 0x10` | ✓ |
| Copies 4 dwords (16 bytes) per source pixel | Lines 92-95: 4 stores | ✓ |
| Calls thunk at param_3+0x08 for row processing | Lines 99-100: `(**(code**)(*(int*)extraout_ECX[1] + 8))(...)` | ✓ |
| Frees both buffers | Lines 113-114: `FUN_00587bcf(...)` for both | ✓ |
| FUN_0058a5d8 call | Line 21: `FUN_0058a5d8()` | ✓ |

**Doc accuracy:** The doc correctly characterizes this as "Direct3D Texture Resampling (Bilinear/Upscale)" despite Ghidra struggling with the decompilation. The triple-loop structure with fixed-point sub-pixel stepping, scale factor computation, and buffer management all match.
**Minor doc issue:** Doc calls the row callback a "thunk at param_3+0x08" — source shows `extraout_ECX[1] + 8` which is ambiguous due to decompilation quality.
**Verdict:** PASS — entry is accurate and correctly interprets mangled decomp.

---

### 24. FUN_0040EF70 — FAIL (NO DOC ENTRY IN docs/18)

**Source:** `analyzed\0x0040ef70__FUN_0040ef70.c` (81 lines)
**Doc in docs/18:** No entry.
**Index entries:** Line 307: `unknown | memory allocation`; also in `docs/10-vehicle-physics.md` line 1557 as triage: `camera mount position/rotation update with 13-float parameter set`.
**Source analysis:** Takes float array param_2 (13 floats). Switch on param_1+0x1c (6 cases 0-5, handled in pairs). Sets values at `*(int*)(param_1+0x20)+0x24` and `+0x20`. Stores floats to param_1+0x0c/0x10/0x14 (position?). Calls `FUN_0054b4d0` (likely D3D/transform). Converts floats to doubles, packs them back. Calls `FUN_005691d0`, `FUN_00569280`, `FUN_0040f0d0`. This is a camera mount transform update — reads 13 float params (position, orientation, FOV?), applies to mount. The docs/10 triage "camera mount position/rotation update" is accurate.
**Verdict:** FAIL — no entry in docs/18. Should be moved/copied from docs/10 triage to proper entry.

---

### 25. FUN_00448570 — PhysicsSubComponentDestroy — PASS

**Source:** `analyzed\0x00448570__FUN_00448570.c` (30 lines)
**Doc:** Lines 2025-2037 in `docs/18-physics-dynamics.md`

| Doc Claim | Source Verification | Result |
|-----------|-------------------|--------|
| Iterates array of 4 pointers at param_1+0x4c | Lines 11-21: `piVar2 = (int*)(param_1+0x4c)`, loop `iVar1 = 4` | ✓ |
| For each non-null: recursively calls FUN_00448570 | Line 15: `FUN_00448570()` (recursive call, no args) | ✓ |
| Then FUN_00587bcf (free/destroy) | Line 16: `FUN_00587bcf(*piVar2)` | ✓ |
| Nulls pointer | Line 17: `*piVar2 = 0` | ✓ |
| Destroys one additional component at param_1+0x5c | Lines 22-25: `if (*(int*)(param_1+0x5c) != 0) { FUN_00448570(); FUN_00587bcf(...); ... = 0; }` | ✓ |
| 4 iterations = 4 wheels | Line 13: `iVar1 = 4` | ✓ |

**Minor note:** Doc says "recursively calls FUN_00448570 then FUN_00587bcf". Source confirms recursive self-call before free. Doc says "4 iterations correspond to 4 vehicle wheels" — source confirms stride of 1 int (4 bytes) through pointer array, which is correct for pointer iteration.
**Verdict:** PASS — all claims verified.

---

## Summary of Issues Found

### Missing Doc Entries (19 functions):

**From docs/10-vehicle-physics.md:**
1. FUN_004DFCE0 (391 lines) — vehicle part setup, needs entry
2. FUN_004471F0 (30 lines) — physics threshold check
3. FUN_004DB170 (98 lines) — HUD/text display, NOT physics
4. FUN_004F8250 (19 lines) — COM destructor

**From docs/17-physics-collision.md:**
5. FUN_004E96C0 (147 lines) — proximity/overlap check
6. FUN_0044D070 (12 bytes) — thunk
7. FUN_0044BC10 (64 bytes) — recursive tree count (misclassified as "collision detection", should be math_util)
8. FUN_0044D190 (12 bytes) — thunk
9. FUN_0044D460 (38 bytes) — global init set 0x0f
10. FUN_0044CB30 (12 bytes) — thunk
11. FUN_0045B840 (270 bytes) — collision wheel/surface interaction
12. FUN_0044E4E0 (43 bytes) — global init set 0x50
13. FUN_0044CCB0 (12 bytes) — thunk
14. FUN_0044C9E0 (41 bytes) — global init set 0x0b (with 1.0f)
15. FUN_0044DD90 (12 bytes) — thunk
16. FUN_00456F70 (59 bytes) — physics force application

**From docs/18-physics-dynamics.md:**
17. FUN_0056ECF0 (336 bytes) — ForceClear (constraint solver)
18. FUN_0040EF70 (320 bytes) — camera mount transform update (in docs/10 triage only)

### Classification Issues:
- FUN_0044BC10: Index says `collision | collision detection`. Source reveals recursive tree-size computation. Should be `math_util`.
- FUN_00456F70: Index says `collision | collision detection`. Source reveals physics force application. Should be `physics_math` or `dynamics`.

### Thunk Pattern (12-byte, should be skip-pattern):
FUN_0044D070, FUN_0044D190, FUN_0044CB30, FUN_0044CCB0, FUN_0044DD90 — all identical pattern: single call to `FUN_00587b3e(&DAT_0044XXXX)`. These are delegate/thunk functions. The index marks them "no" for full entry, which is correct per skip-pattern rules for thunks.

However, they still show as FAIL in this cross-validation because the user explicitly requested them. If thunks are intentionally skipped, these are not truly "failures."
