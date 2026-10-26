# Cross-Validation: docs/20-math-utilities.md vs Source
# 2026-07-15 | 15 functions checked

---

## FUN_004998e0 — PASS

**Verdict:** Doc matches source accurately.

**Doc claims:**
- FUN_00499850() base init — ✓ source line 11
- extraout_ECX[3] = param_1 — ✓ line 12
- If param_1 != 0: *extraout_ECX = 0 — ✓ line 14
- extraout_ECX[2] = *(param_1+0x1c) — ✓ lines 15-16
- extraout_ECX[4] = 0, extraout_ECX[5] = 0 — ✓ lines 17-18
- If linked list empty: FUN_00499910() — ✓ lines 19-21

**Minor note:** `extraout_ECX` is a Ghidra decompiler artifact (uninitialized register variable). Likely `this` pointer from implicit __thiscall. Doc could clarify this but not incorrect.

---

## FUN_004c1e20 — PASS

**Verdict:** Doc matches source accurately.

**Doc claims:**
- FUN_004c0b10() cleanup — ✓ source line 8
- If (param_2 & 1): FUN_00587bcf(param_1) — ✓ lines 9-11
- Destructor with conditional free — matches pattern

**Minor note:** Function returns param_1 (line 12); doc does not mention return value. Omission only, not incorrect.

---

## FUN_00500161 — PASS

**Verdict:** Doc matches source accurately.

**Doc claims:**
- Calls func_0x004ff717(param_4, param_2) — ✓ source line 9
- Parameter reorder wrapper — accurate description

Source confirms __fastcall with 4 params, only param_4 and param_2 forwarded to 0x004ff717.

---

## FUN_0053ad50 — PASS

**Verdict:** Doc matches source accurately.

**Doc claims:**
- *param_1 = &PTR_LAB_005b8910 — ✓ source line 8
- FUN_00587bcf(param_1[4]) — ✓ line 9
- FUN_00587bcf(param_1[8]) — ✓ line 10
- FUN_00587bcf(param_1[0xc]) — ✓ line 11
- FUN_004b0170() base cleanup — ✓ line 12

All indices and calls confirmed.

---

## FUN_00587db0 — PASS

**Verdict:** Doc matches source accurately.

**Doc claims:**
- FUN_00587d7f(param_1, param_2, 0x40) — ✓ source line 8
- Fixed third arg 0x40 — confirmed

Trivial delegation wrapper. Correct.

---

## FUN_00409970 — FAIL

**Verdict:** Doc entry is completely wrong for this function.

**Doc claims:**
- "Copies float from param_1+0x18 to param_1+0x18 — self-copy (no-op or Ghidra artifact)"

**Source actually does:**
```c
if (*(int *)(param_1 + 8) != 0) {
    FUN_00542050(_DAT_007cf6a4 * _DAT_0059e65c, _DAT_007cf6c8 * _DAT_0059e65c, 1);
    FUN_00541ca0(DAT_007cf680);
    FUN_00542540(&LAB_004099e0, 0);
    FUN_00542680(0x3f000000);
    FUN_00542650(DAT_007cf6ec);
}
```

**Problems:**
1. No float copy at +0x18 exists in source — 0x18 is never accessed
2. Function is conditional (checks param_1+8) — doc claims no condition
3. Function calls 5 sub-functions with globals — doc says "Short Computation (Float Copy)"
4. Multiple DAT_ globals referenced (_DAT_007cf6a4, _DAT_0059e65c, _DAT_007cf6c8, DAT_007cf680, DAT_007cf6ec) — none documented

**Correction needed:** Rewrite entire entry. Function is a conditional multi-function call chain involving scaled values and multiple sub-calls. Looks like rendering/camera or physics update, not a float copy.

---

## FUN_005507a0 — FAIL

**Verdict:** Doc miscounts fields.

**Doc claims:**
- "Zeroes param_1[0..7] (7 dwords)"
- Title: "Struct Zero-Initializer (7 Fields)"

**Source actually zeroes indices: 0, 1, 2, 3, 4, 5, 6, 7 — that is 8 dwords, not 7:**
```c
param_1[4] = 0;
*param_1 = 0;       // [0]
param_1[3] = 0;
param_1[2] = 0;
param_1[1] = 0;
param_1[7] = 0;
param_1[6] = 0;
param_1[5] = 0;
```

**Problems:**
1. Title says "7 Fields" — source zeroes 8 fields (indices 0 through 7)
2. Body says "(7 dwords)" — should be 8

**Correction needed:** Change "7 Fields" to "8 Fields" and "(7 dwords)" to "(8 dwords)". The range [0..7] inclusive is 8 elements, not 7. Everything else (FUN_0053b490 called, zeroing pattern) is correct.

---

## FUN_0053b0d0 — PASS

**Verdict:** Doc matches source accurately.

**Doc claims:**
- Allocates 4 bytes via operator_new — ✓ source line 10
- If success: FUN_0053c2a0() — ✓ line 12
- Sets vtable PTR_LAB_005b8938 — ✓ line 13
- Stores in DAT_008b8f18 and DAT_008b8f24 — ✓ lines 14-15
- On failure zeros both globals — ✓ lines 18-19
- Singleton allocation pattern — accurate

---

## FUN_004d7dd0 — PASS

**Verdict:** Doc matches source accurately.

**Doc claims:**
- Calls FUN_004d89d0() — ✓ source line 8
- Call wrapper — accurate

---

## FUN_004a6ff0 — PASS

**Verdict:** Doc matches source accurately.

**Doc claims:**
- Calls FUN_00587b3e(&LAB_004a7000) — ✓ source line 8
- Callback registration — accurate description

---

## FUN_0048d0d0 — PASS

**Verdict:** Doc matches source accurately. Detailed analysis is correct.

**Doc claims vs source:**
- Gets page count via virtual slot 0x20 — ✓ line 14
- Gets current page via slot 0x18 — ✓ line 15
- If page_count > current_page — ✓ line 16
- Gets current page again — ✓ line 17
- Computes center offset via FUN_00498880 — ✓ line 18
- Computes new index = param_1[0xcd] + offset - (current + (page_count-current)/2) — ✓ lines 19-20
- Uses param_1[0xca] * param_1[0xcb] as grid dimensions — ✓ line 21
- Normalizes index modulo (cols*rows), divides by cols — ✓ lines 22-27
- Clamps to [0, cols-1] — ✓ lines 29-34
- Loops calling virtual slot 0xb8 until index matches param_1[0xce] — ✓ lines 36-38

**Minor:** Doc says bVar3 for loop arg; source uses `0 < iStack_8` (derived from comparison, not named bVar3). Inconsequential.

---

## FUN_00461560 — PASS

**Verdict:** Doc matches source accurately. Thorough breakdown is correct.

**Doc claims vs source:**
- Zeroes bytes at +0x00 — ✓ line 8
- Zeroes +0x20 — ✓ line 9
- Zeroes +0x40 — ✓ line 10
- Zeroes +0x64 (=100 decimal) — ✓ line 11
- Zeroes +0x65 — ✓ line 12
- Zeroes +0x6e — ✓ line 29
- Sets +0x66=0x10 — ✓ line 13
- +0x67=1 — ✓ line 14
- +0x68=1 — ✓ line 15
- +0x69=100 — ✓ line 16
- +0x6a=1 — ✓ line 17
- +0x6b=0 — ✓ line 18
- +0x6c=0 — ✓ line 19
- +0x6d=0 — ✓ line 20
- 4-byte zero at +0x60 — ✓ line 21
- 2-byte zero at +0x70, +0x72, +0x74, +0x76, +0x78, +0x7a — ✓ lines 22-27
- Sets +0x7c=200 — ✓ line 28

All offsets and values confirmed. Excellent documentation.

---

## FUN_004b9ac0 — PASS

**Verdict:** Doc matches source accurately.

**Doc claims vs source:**
- If param_3 == sentinel DAT_005acd04, replace with FUN_004b8790 result — ✓ lines 15-18
- Calls FUN_004b72a0(param_1, param_3) — ✓ line 19
- Three dispatch paths based on FUN_005001d0/FUN_005001f0 flag checks:
  - Path 1: FUN_005001d0() true AND FUN_005001f0() false → FUN_005000c0(param_3, iVar2+0x248, param_2) — ✓ lines 21-26
  - Path 2: FUN_005001d0() false AND FUN_005001f0() true → FUN_005000c0(param_3, iVar2+0x98, param_2) — ✓ lines 29-34
  - Path 3 (fallback): FUN_00500210(param_3, param_2) — ✓ line 37

All three paths, offsets (0x248, 0x98), and called functions confirmed.

---

## FUN_004ea930 — FAIL

**Verdict:** Doc is [PARTIAL] placeholder but source has clear, simple logic.

**Doc claims:**
- "1 lines of decompiled code. Needs manual analysis."
- Confidence: low, [PARTIAL] Unknown

**Source actually has 21+ lines of clear decompiled code implementing 3D vector subtraction:**

```c
void __fastcall FUN_004ea930(float *param_1, float *param_2, float *param_3)
{
    fVar1 = param_1[1];
    fVar2 = param_2[1];
    fVar3 = param_1[2];
    fVar4 = param_2[2];
    *param_3 = *param_1 - *param_2;
    param_3[1] = fVar1 - fVar2;
    param_3[2] = fVar3 - fVar4;
}
```

**Function is clearly:** `param_3 = param_1 - param_2` (3D vector subtraction with float components).

**Problems:**
1. "1 lines of decompiled code" is false — source has 21 executable lines
2. Needs manual analysis? It's trivially a vector subtraction
3. Confidence should be high, not low

**Correction needed:** Replace [PARTIAL] placeholder with proper entry:
- Name: "3D Vector Subtraction"
- Key logic: Subtracts two 3D float vectors: `param_3 = param_1 - param_2`
- Algorithm family: math_util — vector arithmetic
- Moddability: hardcoded

---

## FUN_00520fc6 — FAIL

**Verdict:** Doc is [PARTIAL] placeholder but source has complex but identifiable vector math.

**Doc claims:**
- "6 lines of decompiled code. Needs manual analysis."
- Confidence: low, [PARTIAL] Unknown

**Source actually has 55 lines with packed floating-point operations:**
```c
uVar3 = _DAT_005af8f0;
uVar4 = *param_1;
uVar1 = param_1[1];
uVar5 = PackedFloatingMUL(uVar4, uVar4);  // x*x
uVar2 = PackedFloatingMUL(uVar1, uVar1);  // y*y
uVar5 = PackedFloatingADD(uVar5, uVar2);   // x*x + y*y
uVar5 = PackedFloatingAccumulate(uVar5, uVar5);  // sum + sum (2 * sum)
uVar6 = PackedFloatingCompareGE(_PTR_DAT_005af970, uVar5);  // compare vs threshold
uVar2 = PackedFloatingReciprocalSQRAprox(uVar2, uVar5);  // 1/sqrt(x)
// If below threshold: normalize vector, store normalized in param_2
// If above threshold: return default direction
// Also computes magnitude via FUN_00529000() scaled by DAT_005af908 into param_3
```

**This is a 2D vector normalization with:**
1. Dot product computation (x² + y²)
2. Threshold comparison (if magnitude < threshold → normalize)
3. Reciprocal square root approximation
4. Final multiplication for unit vector
5. Optional magnitude output

**Problems:**
1. "6 lines of decompiled code" is false — source has 55 lines with rich SSE-style packed float ops
2. Not "needs manual analysis" — the algorithm is identifiable: dot product → rsqrt → normalize
3. Confidence should be medium, not low

**Correction needed:** Replace [PARTIAL] placeholder with proper entry:
- Name: "2D Vector Normalization with Threshold Check"
- Key logic: Computes squared magnitude of 2D vector, compares against threshold, normalizes if below threshold; optionally outputs unit vector + scaled magnitude
- Algorithm family: math_util — vector normalization with rsqrt
- Globals: DAT_005af8f0, DAT_005af908, DAT_005af970 — thresholds/scales
- Calls: FUN_00529000 (magnitude computation), packed float intrinsics
- Moddability: hardcoded

---

## Summary

| # | Function | Verdict | Key Issue |
|---|----------|---------|-----------|
| 1 | FUN_004998e0 | PASS | — |
| 2 | FUN_004c1e20 | PASS | — |
| 3 | FUN_00500161 | PASS | — |
| 4 | FUN_0053ad50 | PASS | — |
| 5 | FUN_00587db0 | PASS | — |
| 6 | FUN_00409970 | **FAIL** | Doc describes float copy; source has conditional multi-function call chain with 5 sub-calls |
| 7 | FUN_005507a0 | **FAIL** | Doc says "7 Fields" — source zeroes 8 dwords (indices 0-7) |
| 8 | FUN_0053b0d0 | PASS | — |
| 9 | FUN_004d7dd0 | PASS | — |
| 10 | FUN_004a6ff0 | PASS | — |
| 11 | FUN_0048d0d0 | PASS | — |
| 12 | FUN_00461560 | PASS | — |
| 13 | FUN_004b9ac0 | PASS | — |
| 14 | FUN_004ea930 | **FAIL** | [PARTIAL] placeholder with "1 line" — source has 21 lines of clear 3D vector subtraction |
| 15 | FUN_00520fc6 | **FAIL** | [PARTIAL] placeholder with "6 lines" — source has 55 lines of packed float 2D vector normalization |

**Pass rate:** 10/15 PASS (66.7%) — 5 FAILs requiring correction.
