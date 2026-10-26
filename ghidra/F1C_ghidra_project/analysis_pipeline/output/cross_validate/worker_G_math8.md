# Cross-Validation Results: 20 Functions from docs/20-math-utilities.md
Generated: 2026-07-15

---

## 1. FUN_00487260 — State Machine with VTable

**Verdict: FAIL (minor correction needed)**

**Source:** `0x00487260__FUN_00487260.c`

**Issues:**
- **Case 4 logic incorrect.** Doc says "vtable call if both false" (FUN_00486710 AND FUN_00487740 both return false). Source shows: if FUN_00486710() returns false (0), then vtable[+0x40] is called REGARDLESS of FUN_00487740() result. FUN_00487740() is only called when FUN_00486710() returns false, and the vtable call happens on both branches (whether FUN_00487740 returns 0 or non-zero). Correct description: "Case 4: if FUN_00486710() returns non-zero → skip. Else: call FUN_00487740(), then call vtable[+0x40] regardless of result."

**Correction needed:** Fix Case 4 description in doc.

---

## 2. FUN_0049f750 — Center Calc

**Verdict: PASS**

**Source:** `0x0049f750__FUN_0049f750.c`

All claims verified:
- `if (param_4 != 0)` guard ✓
- `FUN_005531f0(param_1, &param_4, &param_1, 0)` ✓
- `*param_3 = param_2 - param_4 / 2` ✓
- Calls: FUN_005531f0 ✓

---

## 3. FUN_004cf040 — Repeated Call Loop

**Verdict: PASS**

**Source:** `0x004cf040__FUN_004cf040.c`

All claims verified:
- Count read from `param_1 + 0x10` ✓
- Loop `for i=0 to count-1` calling `FUN_004cb5e0()` ✓
- Calls: FUN_004cb5e0 (×N) ✓

---

## 4. FUN_0050d57f — Y-Axis Rotation Matrix

**Verdict: PASS**

**Source:** `0x0050d57f__FUN_0050d57f.c`

All claims verified:
- `fcos`/`fsin` for cosθ/sinθ ✓
- Row-major 4x4 Y-rotation matrix ✓
- cosθ at param_1[5] ([1][1]), sinθ at param_1[6] ([1][2]) ✓
- -sinθ at param_1[9] ([2][1]), cosθ at param_1[10] ([2][2]) ✓
- Calls: fcos, fsin ✓

---

## 5. FUN_00547af0 — String Dot Finder

**Verdict: PASS**

**Source:** `0x00547af0__FUN_00547af0.c`

All claims verified:
- Manual strlen loop ✓
- Iterates chars, finds first '.', replaces with '\0' ✓
- Returns 1 if '.' found, 0 if not ✓
- Calls: none ✓

---

## 6. FUN_0059d928 — Single Delegation Call

**Verdict: PASS**

**Source:** `0x0059d928__FUN_0059d928.c`

All claims verified:
- Delegates to FUN_0043ff3d() ✓
- Calls: FUN_0043ff3d ✓

---

## 7. FUN_00418940 — State Flag Check

**Verdict: PASS**

**Source:** `0x00418940__FUN_00418940.c`

All claims verified:
- Checks `param_1 + 0xaf4` non-null ✓
- If non-null: calls vtable[+8], checks return non-zero → return 1 ✓
- Falls through: checks `param_1 + 0x864 != -1` → return 1 ✓
- Otherwise return 0 ✓
- Offsets: +0x864 StateFlag, +0xaf4 SubsystemPtr ✓
- Calls: vtable[+8] ✓

---

## 8. FUN_00486500 — Linked List Tail Append

**Verdict: PASS**

**Source:** `0x00486500__FUN_00486500.c`

All claims verified:
- Reads list head from +0xd4 ✓
- If head null: sets head to param_2 ✓
- Walks via +0x18 (next pointer) to find tail ✓
- Appends param_2 at tail->next ✓
- Struct offset: +0xd4 ListHead ✓
- Calls: none ✓

---

## 9. FUN_0049e410 — Dual Text Display

**Verdict: PASS (minor note)**

**Source:** `0x0049e410__FUN_0049e410.c`

All claims verified:
- FUN_0049bb40(local_10, 0xf) — format init ✓
- FUN_0049f6a0 (called TWICE — once per text string) ✓
- FUN_0049bbb0(local_10, 0xf) — format finish ✓

**Note:** FUN_0049f6a0 is called ×2 in source, but doc lists it once. This is acceptable for a minimal entry; no correction needed.

---

## 10. FUN_004c92b0 — Object Property Setter

**Verdict: PASS**

**Source:** `0x004c92b0__FUN_004c92b0.c`

All claims verified:
- `param_1 + 0x1c = param_2` ✓
- `FUN_004c9260()` gets object ✓
- Null check on object ✓
- vtable[+4] call with multiple params ✓
- Calls: FUN_004c9260, vtable+4 ✓

---

## 11. FUN_0050c2a6 — DirectX Call Wrapper

**Verdict: PASS**

**Source:** `0x0050c2a6__FUN_0050c2a6.c`

All claims verified:
- `FUN_0050fea7(1)` ✓
- `(*_DAT_005d77e4)()` — indirect call ✓
- Global: DAT_005d77e4 ✓
- Calls: FUN_0050fea7, indirect call ✓

---

## 12. FUN_00544f50 — Two-Level Wide-String Search

**Verdict: PASS**

**Source:** `0x00544f50__FUN_00544f50.c`

All claims verified:
- Linked list from `param_1 + 0xf8` ✓
- Walks via +0x1b8 (next pointer) ✓
- Primary node compares wide string at +0x8c (2-byte comparison) ✓
- Secondary node at +0x1b0, also compares wide string at +0x8c ✓
- Returns matching node or 0 ✓
- Calls: none (inline string compare) ✓

---

## 13. FUN_0055bb50 — Dual Field Set to Same Value

**Verdict: PASS**

**Source:** `0x0055bb50__FUN_0055bb50.c`

All claims verified:
- `FUN_0053c2a0()` — parent init ✓
- `param_1 + 0x104 = param_2` ✓
- `param_1 + 0x108 = param_2` ✓
- Returns param_1 ✓
- Struct offsets: +0x104, +0x108 ✓
- Calls: FUN_0053c2a0 ✓

---

## 14. FUN_0045c780 — Bounded Byte Array Accessor

**Verdict: PASS**

**Source:** `0x0045c780__FUN_0045c780.c`

All claims verified:
- Bounds: `-1 < param_2 < 0x68` ✓
- Returns byte at `param_1 + 0x354 + param_2` ✓
- Returns 0 on out-of-bounds ✓
- Struct offset: +0x354 byte[104] ✓
- Calls: none ✓

---

## 15. FUN_004bd760 — Sentinel Slot Fill

**Verdict: PASS**

**Source:** `0x004bd760__FUN_004bd760.c`

All claims verified:
- Scans array at +0xe0 for first -1 slot ✓
- 10 elements ✓
- Writes value from `param_1 + 8` into the slot ✓
- Struct offsets: +0x08 (value), +0xe0 int[10] ✓
- Calls: none ✓

---

## 16. FUN_005471c0 — Simple Setter (+0xb0)

**Verdict: PASS**

**Source:** `0x005471c0__FUN_005471c0.c`

All claims verified:
- `param_1 + 0xb0 = param_2` ✓
- Calls: none ✓

---

## 17. FUN_0058c411 — CRT __freebuf (FILE Buffer Free)

**Verdict: FAIL**

**Source:** `0x0058c411____freebuf.c`

**Issues:**
- **Missing call in Calls section.** Doc says "Calls: none" but source calls `FUN_0058aa6f(_File->_base)` on line 14 to free the buffer. This function is part of the __freebuf implementation and must be listed.

**Correction needed:** Add `FUN_0058aa6f` to the Calls section.

All other claims verified:
- Flag check: `(_File->_flag & 0x83) != 0 && (_File->_flag & 8) != 0` ✓
- Frees `_File->_base` ✓
- Clears flags: `& 0xfbf7` ✓
- Nulls `_File->_ptr` and `_File->_base` ✓
- Zeros `_File->_cnt` ✓

---

## 18. FUN_004c7c30 — Single Function Call Wrapper

**Verdict: PASS**

**Source:** `0x004c7c30__FUN_004c7c30.c`

All claims verified:
- Calls `FUN_004bf630()` ✓
- Calls: FUN_004bf630 ✓

---

## 19. FUN_005864e0 — Conditional List Node Cleanup

**Verdict: PASS**

**Source:** `0x005864e0__FUN_005864e0.c`

All claims verified:
- Checks `param_1[2]` (byte at +0x08) non-zero ✓
- Checks `*param_1` (object ptr at +0x00) non-zero ✓
- Calls `FUN_005867b0()` ✓
- Calls `FUN_00587bcf(*param_1)` ✓
- Struct offsets: +0x00 ObjectPtr, +0x08 HasObject byte ✓
- Calls: FUN_005867b0, FUN_00587bcf ✓

---

## 20. FUN_0045c850 — Per-Element Array Reset

**Verdict: PASS**

**Source:** `0x0045c850__FUN_0045c850.c`

All claims verified:
- `param_1 + 0x14 + param_2*4 = 0` ✓
- `param_1 + 0x1b4 + param_2*4 = 0` ✓
- `param_1 + 0x354 + param_2` (byte) = 0 ✓
- `param_1 + 0x3bc + param_2` (byte) = 0 ✓
- Loop zeroing 8 dwords at `param_1 + 0x424 + param_2*0x20` ✓
- `param_1 + 0x12c4 + param_2*2` (short) = 0 ✓
- `param_1 + 0x1124 + param_2*4` = 0xbf800000 (-1.0f) ✓
- Calls: none ✓

---

## Summary

| # | Function | Verdict | Issue |
|---|----------|---------|-------|
| 1 | FUN_00487260 | **FAIL** | Case 4 logic incorrect |
| 2 | FUN_0049f750 | PASS | |
| 3 | FUN_004cf040 | PASS | |
| 4 | FUN_0050d57f | PASS | |
| 5 | FUN_00547af0 | PASS | |
| 6 | FUN_0059d928 | PASS | |
| 7 | FUN_00418940 | PASS | |
| 8 | FUN_00486500 | PASS | |
| 9 | FUN_0049e410 | PASS | (minor, no change needed) |
| 10 | FUN_004c92b0 | PASS | |
| 11 | FUN_0050c2a6 | PASS | |
| 12 | FUN_00544f50 | PASS | |
| 13 | FUN_0055bb50 | PASS | |
| 14 | FUN_0045c780 | PASS | |
| 15 | FUN_004bd760 | PASS | |
| 16 | FUN_005471c0 | PASS | |
| 17 | FUN_0058c411 | **FAIL** | Missing call to FUN_0058aa6f |
| 18 | FUN_004c7c30 | PASS | |
| 19 | FUN_005864e0 | PASS | |
| 20 | FUN_0045c850 | PASS | |

**Result: 18 PASS / 2 FAIL**

Corrections needed:
1. `docs/20-math-utilities.md` — FUN_00487260 Case 4: vtable call happens when FUN_00486710() returns false, regardless of FUN_00487740() result.
17. `docs/20-math-utilities.md` — FUN_0058c411: Add FUN_0058aa6f to Calls section.
