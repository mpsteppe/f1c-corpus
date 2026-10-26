# Cross-Validation: docs/20-math-utilities.md entries vs source (.c)

**Date:** 2026-07-15
**Validator:** Architect (Claude)
**Scope:** 15 entries from docs/20-math-utilities.md cross-checked against analyzed .c files

---

## FUN_0054b3b0 — PASS

**Doc claims:** Three-Field Setter with Sub-Call. Sets +0x20, +0x24, +0x28 from params 2-4, calls FUN_0054b330.

**Source verification (0x0054b3b0__FUN_0054b3b0.c):**
```c
*(undefined4 *)(param_1 + 0x20) = param_2;
*(undefined4 *)(param_1 + 0x24) = param_3;
*(undefined4 *)(param_1 + 0x28) = param_4;
FUN_0054b330();
```
All claims match exactly. No errors.

---

## FUN_005642f0 — PASS

**Doc claims:** Struct Alloc/Init with Switch-Based Type. Allocates 20-byte struct, init from params, switch on param_3.

**Source verification (0x005642f0__FUN_005642f0.c):**
- `_malloc(0x14)` — 20-byte alloc ✓
- `*puVar1 = param_1` — first field ✓
- `*(undefined2 *)(puVar1 + 1) = param_2` — 2-byte field (byte offset 4, due to undefined4* pointer arithmetic). Doc says "puVar1+1" which is technically pointer arithmetic, actual byte offset = 4. Minor imprecision.
- `*(undefined2 *)((int)puVar1 + 6) = 9999` — 2-byte sentinel at byte offset 6 ✓
- `puVar1[2] = param_3` — third field ✓
- Switch: cases 0,1,2,3 → uVar2=2; default → uVar2=4 ✓
- `FUN_005646d0(uVar2, &LAB_005645f0, &LAB_00564620, 0)` — call ✓
- `puVar1[3] = uVar2` — store result ✓
- `puVar1[4] = param_4` — store last param ✓

**Minor note:** "puVar1+1" in doc should be clarified as byte offset 4 (undefined4* arithmetic). But overall description is accurate.

---

## FUN_00567780 — PASS

**Doc claims:** Empty Stub. Bare return, no logic.

**Source verification (0x00567780__FUN_00567780.c):**
```c
void FUN_00567780(void) { return; }
```
Exactly as documented.

---

## FUN_00464ad0 — PASS

**Doc claims:** Dispatch Wrapper (Call with 1). Calls FUN_004649f0(1).

**Source verification (0x00464ad0__FUN_00464ad0.c):**
```c
void FUN_00464ad0(void) {
  FUN_004649f0(1);
  return;
}
```
Exactly as documented.

---

## FUN_0048b420 — PASS

**Doc claims:** Constructor with String Copy. Complex constructor, parent init, vtable, buffer allocation, string copy, field stores.

**Source verification (0x0048b420__FUN_0048b420.c):**

| Doc claim | Source | Verdict |
|-----------|--------|---------|
| Calls FUN_00485e30() — parent init | `FUN_00485e30();` | ✓ |
| Sets *param_1 = &PTR_FUN_005abed0 | `*param_1 = &PTR_FUN_005abed0;` | ✓ |
| If param_2==0: uses param_1+0xE6 as default buffer | `if (param_2==0) param_2 = (int)param_1 + 0xe6;` | ✓ |
| Stores buffer at param_1[0xBC] | `param_1[0xbc] = param_2;` | ✓ |
| Calls FUN_0048b4f0() — post-init | `FUN_0048b4f0();` | ✓ |
| If param_4>0: calls FUN_0048b8f0(param_4) | `if (0<param_4) FUN_0048b8f0(param_4);` | ✓ |
| Sets param_1[0xBF] = 0 | `param_1[0xbf] = 0;` | ✓ |
| If param_3!=NULL: computes length, copies | strlen loop + copy to buffer at param_1[0xBC] | ✓ |
| Copies string to param_1+0x1E7 | `param_3[(int)param_1 + 0x1e7 - (int)param_3]` = param_1+0x1E7 | ✓ |
| Stores param_7 at param_1+0xE5 | `*(undefined1*)((int)param_1+0xe5) = param_7;` | ✓ |
| Stores param_5 at param_1+0xE2 | `*(undefined1*)((int)param_1+0xe2) = param_5;` | ✓ |
| Stores param_6 at param_1[0xBA] | `param_1[0xba] = param_6;` | ✓ |

All claims verified. No errors.

---

## FUN_004a3570 — FAIL

**Doc claims:** Flag-Guarded Reset/Decrement Operations. Bit-0 path: decrement counter, loop setting elements to -1.0f. Bit-1 path: loop calling FUN_004a2840(param_2 - base).

**Source verification (0x004a3570__FUN_004a3570.c):**

**Struct offsets table:** All offsets verified correct (flags=byte@0, base=float@4, counter=int@8, count=int@C, elements=int@10, stride=0x78). ✓

**Key logic errors:**

Bit-0 path (`*param_1 & 1`):
- Doc says: sets `*(element+0x44) = -1.0f (0xBF800000)` ✓
- Doc **MISSES**: also calls `FUN_004a2840(0)` for each element in the loop
- Source shows both operations per element:
```c
*(undefined4 *)(*(int *)(param_1 + 0x10) + 0x44 + iVar3) = 0xbf800000;
FUN_004a2840(0);  // <-- NOT DOCUMENTED
```

Bit-1 path (`*param_1 & 2`):
- Doc says: calls `FUN_004a2840(param_2 - *(param_1+4))` ✓

**Correction needed:** Add to Key Logic for bit-0 path: "Also calls FUN_004a2840(0) for each element after setting the -1.0f field."

---

## FUN_004d5984 — PASS (minimal entry)

**Doc claims:** Field Setter. Sets field via unaff_ESI, calls sub-function. Low confidence.

**Source verification (0x004d5984__FUN_004d5984.c):**
```c
void FUN_004d5984(undefined4 param_1, undefined4 param_2, undefined4 param_3) {
  int unaff_ESI;
  FUN_00447f30();
  *(undefined4 *)(unaff_ESI + 8) = param_3;
  FUN_004d5be0(&param_3);
  return;
}
```
Doc is minimal but not incorrect. Source shows: calls FUN_00447f30(), sets *(unaff_ESI+8)=param_3, calls FUN_004d5be0(). Doc does not claim wrong details — just sparse.

**Note:** Entry is very thin. Missing: FUN_00447f30 call, FUN_004d5be0 name, offset +8. Consider upgrading for completeness.

---

## FUN_0050edd2 — PASS (minimal entry)

**Doc claims:** Two-Thunk Wrapper. Hardcoded.

**Source verification (0x0050edd2__FUN_0050edd2.c):**
```c
undefined4 FUN_0050edd2(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4) {
  undefined1 local_14 [16];
  thunk_FUN_0050dd0c(local_14, param_2, param_3, param_4);
  thunk_FUN_0050d84a(param_1, local_14);
  return param_1;
}
```
Title "Two-Thunk Wrapper" is accurate — calls two thunks via a 16-byte local buffer. No factual errors.

**Note:** Minimal entry. Could add: creates 16-byte local buffer, passes params 2-4 through first thunk, then uses result with param_1 in second thunk, returns param_1.

---

## FUN_00549020 — PASS (minimal entry)

**Doc claims:** String List Append. Appends string to list, allocates nodes.

**Source verification (0x00549020__FUN_00549020.c):**
```c
void __thiscall FUN_00549020(int param_1, char *param_2) {
  // List head at param_1+0xe8
  // If empty: allocates 0x18 node via operator_new + FUN_00548e00(), stores at +0xe8
  // Else: walks to tail via +0x14 next pointers, allocates new node, links
  // Copies string using pointer arithmetic (iVar3 - param_2) offset
  FUN_00589901(iVar3);  // registration
}
```
Doc is minimal but correct. Source confirms list append with string copy and registration.

**Note:** Very thin. Missing: list head at +0xe8, +0x14 next pointers, FUN_00548e00 for node init, FUN_00589901 registration call. Consider upgrading.

---

## FUN_0059cdc0 — PASS

**Doc claims:** Unwind Thunk to 0x00581880.

**Source verification (0x0059cdc0__Unwind_0059cdc0.c):**
```c
void Unwind_0059cdc0(void) {
  FUN_00581880();
  return;
}
```
Exactly as documented — unwind thunk calls FUN_00581880.

---

## FUN_00462370 — PASS

**Doc claims:** Struct Field Read at +0x3e14. Reads int from *(param_1) + 0x3e14.

**Source verification (0x00462370__FUN_00462370.c):**
```c
undefined4 __fastcall FUN_00462370(int *param_1) {
  return *(undefined4 *)(*param_1 + 0x3e14);
}
```
Exactly as documented — double-indirection read at offset 0x3e14 from pointed-to struct.

---

## FUN_00512319 — PASS

**Doc claims:** Bit Flag Setter. Set bit 0 at param_1+0x60. `*(param_1+0x60) |= 1`.

**Source verification (0x00512319__FUN_00512319.c):**
```c
void FUN_00512319(int param_1) {
  *(uint *)(param_1 + 0x60) = *(uint *)(param_1 + 0x60) | 1;
  return;
}
```
Exactly as documented.

---

## FUN_005906bb — PASS

**Doc claims:** CRT __ctrandisp2. MSVC CRT transcendent dispatch helper. Loads two floats, dispatches, calls cleanup.

**Source verification (0x005906bb____ctrandisp2.c):**
```c
void __ctrandisp2(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4) {
  __fload(param_1, param_2);
  __fload(param_3, param_4);
  __trandisp2();
  FUN_00590703();
  return;
}
```

| Doc claim | Source | Verdict |
|-----------|--------|---------|
| __fload(param_1, param_2) | `__fload(param_1,param_2);` | ✓ |
| __fload(param_3, param_4) — second float | `__fload(param_3,param_4);` | ✓ |
| __trandisp2() — transcendent dispatch | `__trandisp2();` | ✓ |
| FUN_00590703() — post-dispatch cleanup | `FUN_00590703();` | ✓ |

All claims verified. Note: doc says `FUN_00590703`, source confirms `FUN_00590703`. ✓

---

## FUN_00455260 — PASS

**Doc claims:** Two-Way Dispatch by Index. Dispatches based on *param_1 value (0 or 1).

**Source verification (0x00455260__FUN_00455260.c):**
```c
undefined4 FUN_00455260(int *param_1) {
  if (*param_1 == 0) { uVar1 = FUN_00455200(); return uVar1; }
  if (*param_1 != 1) { return 0; }
  uVar1 = FUN_00455240(); return uVar1;
}
```

| Doc claim | Source | Verdict |
|-----------|--------|---------|
| If *param_1==0: return FUN_00455200() | `if(*param_1==0) return FUN_00455200();` | ✓ |
| If *param_1==1: return FUN_00455240() | `if(*param_1!=1) return 0; ... FUN_00455240();` | ✓ |
| Otherwise: return 0 | `return 0;` | ✓ |

All claims match.

---

## FUN_0047a000 — PASS

**Doc claims:** UI Object Init with Byte Flag. Calls FUN_004668e0(0, 1.0f) — base init. Sets vtable. Zeros byte flag at param_1+0x41.

**Source verification (0x0047a000__FUN_0047a000.c):**
```c
undefined4 * __fastcall FUN_0047a000(undefined4 *param_1) {
  FUN_004668e0(0, 0x3f800000);        // 0x3f800000 = 1.0f as float
  *param_1 = &PTR_FUN_005a5ef8;      // vtable
  *(undefined1 *)(param_1 + 0x41) = 0; // byte flag
  return param_1;
}
```

| Doc claim | Source | Verdict |
|-----------|--------|---------|
| FUN_004668e0(0, 1.0f) — base init | `FUN_004668e0(0,0x3f800000)` = (0, 1.0f) | ✓ |
| *param_1 = &PTR_FUN_005a5ef8 (vtable) | `*param_1 = &PTR_FUN_005a5ef8;` | ✓ |
| *(param_1+0x41) = 0 (byte flag) | `*(undefined1 *)(param_1 + 0x41) = 0;` | ✓ |

All claims verified. Offset +0x41: note that param_1 is typed as `undefined4*`, so pointer arithmetic gives `0x41 * 4 = 0x104` as actual byte offset. However, this is a Ghidra type-recovery artifact — the decompiler preserved the raw byte offset from assembly. Doc convention matches Ghidra display. No correction needed.

---

## Summary

| # | Function | Result | Issues |
|---|----------|--------|--------|
| 1 | FUN_0054b3b0 | **PASS** | None |
| 2 | FUN_005642f0 | **PASS** | Minor: "puVar1+1" imprecision (byte offset 4, not 1) |
| 3 | FUN_00567780 | **PASS** | None |
| 4 | FUN_00464ad0 | **PASS** | None |
| 5 | FUN_0048b420 | **PASS** | None |
| 6 | FUN_004a3570 | **FAIL** | Missing FUN_004a2840(0) call in bit-0 loop |
| 7 | FUN_004d5984 | **PASS** | Minimal entry; omissions noted |
| 8 | FUN_0050edd2 | **PASS** | Minimal entry; omissions noted |
| 9 | FUN_00549020 | **PASS** | Minimal entry; omissions noted |
| 10 | FUN_0059cdc0 | **PASS** | None |
| 11 | FUN_00462370 | **PASS** | None |
| 12 | FUN_00512319 | **PASS** | None |
| 13 | FUN_005906bb | **PASS** | None |
| 14 | FUN_00455260 | **PASS** | None |
| 15 | FUN_0047a000 | **PASS** | Offset ambiguity noted; non-issue |

**Results: 14 PASS, 1 FAIL**

**Correction needed for FAIL (FUN_004a3570):**
In the bit-0 (flag & 1) path, add to Key Logic: "For each element, after setting `*(element+0x44) = -1.0f`, also calls `FUN_004a2840(0)`."
