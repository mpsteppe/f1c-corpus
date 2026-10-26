# Cross-Validation Report: docs/20-math-utilities.md

**Date:** 2026-07-15
**Scope:** 20 functions, source vs doc entry verification

---

## 1. FUN_00567010 — [PARTIAL] Unknown

**Result: FAIL**

| Claim | Source | Verdict |
|-------|--------|---------|
| "1 lines of decompiled code" | 13 lines, 2 function calls | **WRONG** — body has `FUN_00566f40()` + `FUN_00566ee0()` |
| No calls listed | Calls FUN_00566f40, FUN_00566ee0 | **MISSING** |

**Corrections:**
- Replace doc with actual content:
```
## FUN_00567010 — Delegation Wrapper (Double Call)

Source: unknown | Confidence: high
Thin wrapper calling two subroutines sequentially.

**Key logic:**
- Calls FUN_00566f40()
- Calls FUN_00566ee0()

**Calls:** FUN_00566f40, FUN_00566ee0

**Moddability:** hardcoded
```

---

## 2. FUN_00559760 — UTF-16 String Search in Linked List

**Result: PASS**

| Claim | Source | Verdict |
|-------|--------|---------|
| Reads head from `*param_1` | Line 15: `pbVar2 = (byte *)*param_1;` | ✓ |
| Compares byte-by-byte in 2-byte strides | Lines 22-36: inner loop with +2 stride | ✓ |
| Returns -1/0/+1 via `iVar4` | Line 27: `(1-(uint)bVar6)-(uint)(bVar6!=0)` → -1/0/+1 | ✓ |
| Returns node on match (`iVar4==0`) | Lines 39-41: `if (iVar4==0) return pbVar2;` | ✓ |
| Follows `next` at node+0x1c | Line 42: `pbVar2 = *(byte**)(pbVar2 + 0x1c);` | ✓ |
| Returns null if exhausted | Lines 19-20: `if (pbVar2==0) return 0;` | ✓ |
| Calls: none (leaf) | No external calls in source | ✓ |
| Struct offset +0x1c = NextPtr | Confirmed at line 42 | ✓ |

---

## 3. FUN_0059cc9e — SEH Unwind Handler (Free Stack Var at -0x10)

**Result: PASS**

| Claim | Source | Verdict |
|-------|--------|---------|
| Frees EBP-0x10 via FUN_00587bcf | Line 10: `FUN_00587bcf(*(undefined4*)(unaff_EBP + -0x10));` | ✓ |
| Calls: FUN_00587bcf | Confirmed | ✓ |

---

## 4. FUN_004582a0 — Strided Array Element Pointer

**Result: PASS**

| Claim | Source | Verdict |
|-------|--------|---------|
| Bounds check: 0 <= param_2 < param_1[1] | Line 11: `if ((-1<param_2) && (param_2<param_1[1]))` | ✓ |
| Returns param_1[0] + param_2 * 0x1c | Line 12: `iVar1 = param_2 * 0x1c + *param_1;` | ✓ |
| Returns 0 (null) if out of bounds | Line 10: `iVar1 = 0;` — initialized to 0 | ✓ |
| Calls: none | No calls in source | ✓ |

---

## 5. FUN_0047be00 — Bounded Computation with Division

**Result: FAIL**

| Claim | Source | Verdict |
|-------|--------|---------|
| Reads fields at +0x114, +0x110, +0xec | Lines 12, 18, 15, 20-24: confirmed | ✓ |
| Computes `(val/2 + weight * (count-1)) / val` | Line 18: `(iVar1/2 + *(param_1+0x110) * iVar2) / iVar1` | ✓ |
| Clamps to [0, count-1] | Lines 20-25: clamp below 0 and above iVar2 (=count-1) | ✓ |
| "Calls FUN_0047bd90 if count exceeds val" | Line 26: `if (iVar2 < *(param_1+0x114))` where iVar2=count-1 | **WRONG** |
| Calls: FUN_0047bc90, FUN_0047bd90 | Lines 11, 27: confirmed | ✓ |

**Correction for condition:**
- Source condition: `(count-1) < val` → calls FUN_0047bd90 when `count <= val`
- Doc says "count exceeds val" (count > val) — this is **opposite**.
- Fix to: **"Calls FUN_0047bd90 if val >= count (i.e., count-1 < val)"**

---

## 6. FUN_00499e40 — Path Registry Wrapper

**Result: PASS**

| Claim | Source | Verdict |
|-------|--------|---------|
| Calls FUN_00566650 with no args | Line 8: `FUN_00566650();` | ✓ |

---

## 7. FUN_004c2fa0 — Delegation Wrapper

**Result: PASS**

| Claim | Source | Verdict |
|-------|--------|---------|
| Delegates to FUN_004b3db0 | Line 8: `FUN_004b3db0();` | ✓ |

---

## 8. FUN_00502bf4 — Dual VTable Destructor

**Result: PASS**

| Claim | Source | Verdict |
|-------|--------|---------|
| if param_1[1]!=0: vtable[0](1) | Lines 8-10: `if (param_1[1]) { (*(code**)**(param_1[1]))(1); }` | ✓ |
| if *param_1!=0: vtable[0](1) | Lines 11-13: `if (*param_1) { (*(code**)**(*param_1))(1); }` | ✓ |

---

## 9. FUN_0053c200 — Delegation Wrapper

**Result: PASS**

| Claim | Source | Verdict |
|-------|--------|---------|
| Calls FUN_0053d4f0() | Line 8: `FUN_0053d4f0();` | ✓ |

---

## 10. FUN_0058e0b4 — Two-Field Initializer

**Result: PASS**

| Claim | Source | Verdict |
|-------|--------|---------|
| Sets param_1+0x50 = &DAT_005e7810 | Line 8: `*(param_1+0x50) = &DAT_005e7810;` | ✓ |
| Sets param_1+0x14 = 1 | Line 9: `*(param_1+0x14) = 1;` | ✓ |
| Calls: none | No calls in source | ✓ |

---

## 11. FUN_0059ccc0 — SEH Unwind Helper

**Result: PASS**

| Claim | Source | Verdict |
|-------|--------|---------|
| Calls FUN_00583270() | Line 8: `FUN_00583270();` | ✓ |

---

## 12. FUN_0045c3d0 — Parser Dispatch Wrapper

**Result: PASS**

| Claim | Source | Verdict |
|-------|--------|---------|
| Calls FUN_00568a60(*(param_1+1), param_3) | Line 10: `FUN_00568a60(*(param_1+1), param_3);` | ✓ |
| If non-zero: returns 1 | Lines 11-12: `if (cVar1!=0) return 1;` | ✓ |
| Else: sets *param_3=0, returns 0 | Lines 14-15: `*param_3=0; return 0;` | ✓ |

---

## 13. FUN_00485870 — Destructor with Triple Free

**Result: PASS**

| Claim | Source | Verdict |
|-------|--------|---------|
| FUN_00499b50() | Line 8: confirmed | ✓ |
| Frees +0x128, +0x120, +0x118 via FUN_00587bcf if non-null | Lines 9-17: confirmed | ✓ |
| FUN_00499b50(), FUN_00485eb0() | Lines 18-19: confirmed | ✓ |
| If (param_2 & 1): FUN_00587bcf(param_1) | Lines 20-22: confirmed | ✓ |

---

## 14. FUN_0049aec0 — Linked List Indexed Field Reader

**Result: PASS**

| Claim | Source | Verdict |
|-------|--------|---------|
| If param_2 out of [0, param_1[3]) range: param_1[2]=0 | Lines 12-14: `if (param_2<0 || param_1[3]<=param_2) param_1[2]=0;` | ✓ |
| Walks linked list to Nth node | Lines 16-20: follows `+4` pointer (next) N times | ✓ |
| Reads two shorts from node data to *param_3, *param_4 | Lines 24-26: `*param_3=*puVar2; *param_4=puVar2[1];` | ✓ |
| Returns 1 on success, 0 on failure | Line 27: returns CONCAT31(highbyte, 1) → non-zero (success); line 31: returns 0 | ✓ |

---

## 15. FUN_004c8580 — VTable Method Guard

**Result: PASS**

| Claim | Source | Verdict |
|-------|--------|---------|
| If DAT_008ac4c8 non-null: call virtual at +8 | Lines 10-11: `if (DAT_008ac4c8) { iVar1 = (*(code**)(*DAT_008ac4c8+8))(); }` | ✓ |
| Returns 1 if result non-zero | Lines 12-14: `if (iVar1!=0) return 1;` | ✓ |
| Returns 0 otherwise | Line 16: `return 0;` | ✓ |

---

## 16. FUN_0050ae3e — Init with Class 8

**Result: PASS**

| Claim | Source | Verdict |
|-------|--------|---------|
| FUN_00507496(param_2, 8, 1) | Line 8: `FUN_00507496(param_2, 8, 1);` | ✓ |
| *param_1 = &PTR_FUN_005adc5c | Line 9: `*param_1 = &PTR_FUN_005adc5c;` | ✓ |

---

## 17. FUN_00540050 — Resource Load with Output

**Result: PASS**

| Claim | Source | Verdict |
|-------|--------|---------|
| FUN_005006d5(param_2, param_3, &local_1c) | Line 15: confirmed | ✓ |
| If error: sets *param_1, returns 0xffffffff | Lines 16-19: `*param_1 = iVar1; if (iVar1!=0) return 0xffffffff;` | ✓ |
| Optionally writes local_1c, local_18 to param_4, param_5 | Lines 20-25: confirmed | ✓ |
| If param_6 != 0: calls FUN_0055c450(local_c, 0, param_6) | Lines 26-28: confirmed | ✓ |

---

## 18. FUN_0059553a — Delegation with Static Data

**Result: PASS**

| Claim | Source | Verdict |
|-------|--------|---------|
| Calls FUN_005953b8(param_1, param_2, &DAT_005e99b8) | Line 8: confirmed | ✓ |

---

## 19. FUN_0059a43c — Stream Buffer Pointer Adjust

**Result: PASS**

| Claim | Source | Verdict |
|-------|--------|---------|
| Derefs ptr at +0x30, decrements by 1 | Line 8: `**(int**)(param_1+0x30) += -1;` | ✓ |
| Derefs ptr at +0x20, increments by 2 | Line 9: `**(int**)(param_1+0x20) += 2;` | ✓ |
| Struct offsets: +0x20 int*, +0x30 int* | Confirmed by lines 8-9 | ✓ |

---

## 20. FUN_00461c70 — Short Computation (Large Alloc + Init)

**Result: PASS**

| Claim | Source | Verdict |
|-------|--------|---------|
| operator_new(0x1ce60) ~118KB | Line 11: `operator_new(0x1ce60)` = 118,368 bytes ≈ 118KB | ✓ |
| Calls FUN_0045d530(param_1), stores result | Lines 13-15: `uVar2=FUN_0045d530(param_1); *param_1=uVar2;` | ✓ |
| On failure: stores 0 | Line 17: `*param_1 = 0;` | ✓ |

---

## Summary

| # | Function | Result |
|---|----------|--------|
| 1 | FUN_00567010 | **FAIL** — placeholder entry; missing 2 calls, wrong line count |
| 2 | FUN_00559760 | PASS |
| 3 | FUN_0059cc9e | PASS |
| 4 | FUN_004582a0 | PASS |
| 5 | FUN_0047be00 | **FAIL** — condition description inverted: calls FUN_0047bd90 when `count <= val`, not "count exceeds val" |
| 6 | FUN_00499e40 | PASS |
| 7 | FUN_004c2fa0 | PASS |
| 8 | FUN_00502bf4 | PASS |
| 9 | FUN_0053c200 | PASS |
| 10 | FUN_0058e0b4 | PASS |
| 11 | FUN_0059ccc0 | PASS |
| 12 | FUN_0045c3d0 | PASS |
| 13 | FUN_00485870 | PASS |
| 14 | FUN_0049aec0 | PASS |
| 15 | FUN_004c8580 | PASS |
| 16 | FUN_0050ae3e | PASS |
| 17 | FUN_00540050 | PASS |
| 18 | FUN_0059553a | PASS |
| 19 | FUN_0059a43c | PASS |
| 20 | FUN_00461c70 | PASS |

**Overall: 18/20 PASS, 2/20 FAIL**
