# Cross-Validation: docs/20-math-utilities.md — 15 Functions vs Source

## FUN_0050b260 — FAIL

**Issues:**
- Doc says `Calls FUN_00507496()` with empty parens. Source shows `FUN_00507496(param_2, 8, 1)` — 3 args: size=8, count=1. Doc omits these important init parameters.
- Doc says "Texture object constructor" but no texture-specific strings in source. The vtable `PTR_FUN_005adcfc` isn't confirmed as texture. Low-confidence naming.

**Corrections:**
```
**Key logic:**
- Calls FUN_00507496(param_2, 8, 1) — init with size=8, count=1
- *param_1 = &PTR_FUN_005adcfc (vtable)
- Returns param_1
```

## FUN_0055be20 — FAIL

**Issues:**
- **Function returns void**, not "Returns copy status" — doc claims return value that doesn't exist.
- "Copies string from source to dest" — partially correct. Source copies bytes from `param_1+4` (source) to address in `param_2` (dest), but the copy mechanism uses pointer arithmetic: `pcVar2 = param_1+4; param_2 -= (int)pcVar2;` then `pcVar2[param_2] = cVar1;` — effectively a relative self-copy from struct buffer to external buffer.
- "Sets output pointers (start, end, etc.)" is vague. Source sets `*param_3 = *(param_1+0x110)` and `*param_4 = *(param_1+0x114)` — these are specific struct field reads at offsets 0x110 and 0x114, not "start/end of string."

**Corrections:**
```
**Key logic:**
- void return (no return value)
- If param_2 != 0: copies string from param_1+4 buffer to address in param_2
- If param_3 != NULL: *param_3 = *(param_1 + 0x110) — outparam from struct field
- If param_4 != NULL: *param_4 = *(param_1 + 0x114) — outparam from struct field
```

## FUN_00465c70 — PASS

Accurate. Recursive merge sort on singly-linked list, float key at `*(*node + 4)`, next pointer at `node[1]`. Midpoint via traversal, standard merge logic. All details confirmed against source.

## FUN_0040bcd0 — PASS

Accurate within reasonable simplification.
- param_2 == 0 → return 0 ✓
- FUN_0040b6c0(param_2) resource lookup ✓
- If index >= 0: FUN_0040b6f0(index) validate ✓
- If param_3 != 0: vtable call at *param_1+0x10 ✓
- Return value is complex (CONCAT31) but described as "success status" acceptably.

## FUN_00596840 — PASS

Accurate. CRT __allshl 64-bit left shift. All 3 branches described correctly:
- shift > 63 → 0 ✓
- shift < 32 → (hi << shift) | (lo >> (32-shift)), lo << shift ✓
- shift >= 32 → lo << (shift-32) in high 32 bits ✓

## FUN_0049aa10 — PASS

Exact match. All 4 writes to consecutive struct offsets confirmed:
- param_1+0x14 = param_2 ✓
- param_1+0x18 = param_3 ✓
- param_1+0x1c = param_4 ✓
- param_1+0x20 = param_5 ✓

## FUN_004c81a0 — PASS (minor note)

Core logic accurate:
- List at param_1+0xc ✓
- Compares node data field at +4 to DAT_008acfcc ✓
- Sets node+0x18 = 0 on match ✓

*Minor:* The doc says "Follows next pointers at +8" but the actual traversal is more complex: a cursor at header+0x8 stores node pointers, and next links within nodes are at offset +4. This is a structural detail that doesn't affect correctness of the behavioral description.

## FUN_0050a7c5 — PASS

Exact match:
- FUN_00507496(param_2, 0x18, 1) ✓
- *param_1 = &PTR_FUN_005adba8 (vtable) ✓

## FUN_0053d4c0 — PASS

Exact match:
- Calls FUN_0053c4d0() ✓
- If test != 0 → return -1 (0xffffffff) ✓
- If *param_1 != 0 → FUN_00587bcf(*param_1) ✓
- Returns 0 ✓

## FUN_00593446 — FAIL

**Issues — Key Logic significantly incomplete:**
- Doc says "Checks param_1 flags & 0x66" then "Dispatches via vtable..." but misses that vtable dispatch has **two additional preconditions**: `*param_1 == -0x1f928c9d` AND `(uint)param_1[5] > 0x19930520`. Without these, vtable is NOT called and FUN_005934e1 fallback runs instead.
- Doc omits the **else-if branch entirely**: when flags & 0x66 != 0, the code checks `param_5[1] != 0 && param_6 == 0` and calls `FUN_0059379b` — a completely separate dispatch path.
- Calls section correctly lists all callees, but Key Logic doesn't explain the branching conditions.

**Corrections:**
```
**Key logic:**
- If param_5[0] != 0x19930520: calls FUN_00593cfd() (error)
- If (param_1 flags byte & 0x66) == 0:
  - If param_5[3] != 0:
    - If (*param_1 == -0x1f928c9d) AND (param_1[5] > 0x19930520) AND (vtable at param_1[7]+8 non-null):
      - Dispatch via vtable at param_1[7]+8
    - Else: call FUN_005934e1() fallback
- Else (flags & 0x66 != 0):
  - If param_5[1] != 0 AND param_6 == 0:
    - Call FUN_0059379b() — alternate handler
- Returns 1 (default)
```

## FUN_0040d470 — PASS

Exact match:
- *param_1 = param_2 ✓
- Calls FUN_0040d490() ✓
- Returns param_1 ✓

## FUN_0046a970 — PASS

Exact match:
- *param_1 = &PTR_FUN_0059f9e8 (vtable) ✓
- Calls FUN_00489440() ✓

## FUN_0048f590 — PASS

Accurate. All details confirmed:
- Index from param_1+0x174 ✓
- Bounds check against count at +0xfc ✓
- List head at +0xf0 ✓
- Walks via node[1] (next pointer) ✓
- Returns *node (first field) ✓
- Returns 0 if walk hits null ✓

## FUN_004b21c0 — PASS

Exact match. Single call to FUN_004b3ad0, no parameters, void return. ✓

## FUN_004dd400 — PASS

Accurate:
- Calls FUN_004dd3a0 with param_1, param_2, param_3 and reference args (&param_6, &param_3) ✓
- If param_4 != NULL: *param_4 = (float)param_6 / DAT_005d6d60 ✓
- If param_5 != NULL: *param_5 = (float)param_3 / DAT_005d6d64 ✓

---

## Summary

| # | Function | Result |
|---|----------|--------|
| 1 | FUN_0050b260 | **FAIL** — missing FUN_00507496 args (8,1) |
| 2 | FUN_0055be20 | **FAIL** — void return, not "returns copy status"; vague outparams |
| 3 | FUN_00465c70 | PASS |
| 4 | FUN_0040bcd0 | PASS |
| 5 | FUN_00596840 | PASS |
| 6 | FUN_0049aa10 | PASS |
| 7 | FUN_004c81a0 | PASS (minor) |
| 8 | FUN_0050a7c5 | PASS |
| 9 | FUN_0053d4c0 | PASS |
| 10 | FUN_00593446 | **FAIL** — missing preconditions on vtable dispatch, missing else-if branch |
| 11 | FUN_0040d470 | PASS |
| 12 | FUN_0046a970 | PASS |
| 13 | FUN_0048f590 | PASS |
| 14 | FUN_004b21c0 | PASS |
| 15 | FUN_004dd400 | PASS |

**12 PASS, 3 FAIL** — corrections provided above for each FAIL.
