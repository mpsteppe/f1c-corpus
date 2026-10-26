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
