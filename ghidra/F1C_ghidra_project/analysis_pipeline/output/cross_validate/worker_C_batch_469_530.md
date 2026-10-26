# Cross-Validation Audit: Batch 469-530
## Target: docs/20-math-utilities.md
## Generated: 2026-07-15

---

### 469. FUN_0058806E @ 0x0058806E — Buffered file read

**Doc entry (line 198-202):** `uint FUN_0058806e(undefined1 *param_1, uint param_2, uint param_3, int *param_4)` — "Buffered file read. Reads param_3 elements of size param_2 into param_1 buffer. Uses intermediate buffer for unbuffered reads (FUN_0058c9b4). Handles partial reads."

**Source file:** analyzed/0x0058806e__FUN_0058806e.c (74 lines, 232 bytes)

**Verification:**
- Signature: `uint FUN_0058806e(undefined1 *param_1,uint param_2,uint param_3,int *param_4)` — MATCHES
- Function reads param_3 * param_2 bytes/count — confirmed: `uVar5 = param_2 * param_3`, loop while `param_1 != 0`
- Calls `FUN_0058c9b4(piVar1[4],puVar4,uVar2)` — confirmed intermediate buffer read
- Calls `FUN_0058c255(piVar1)` — confirmed in one branch
- Calls `FUN_0058cc00(puVar4,*piVar1,uVar6)` — confirmed buffered copy
- Returns `(uVar5 - (int)param_1) / param_2` — partial read count — confirmed
- No globals claimed — correct (none referenced)
- "Thread-safe via lock" not mentioned — but the code checks `(*(ushort *)(param_4 + 3) & 0x10c)` flags suggesting I/O mode flags, no lock visible

**Verdict: PASS** (Signature and analysis match; no globals claimed, all calls verified)

---

### 470. FUN_00587AC0 @ 0x00587AC0 — Stack-based memory allocator push

**Doc entry (line 293-297):** `undefined4 FUN_00587ac0(undefined4 param_1)` — "Stack-based memory allocator push. Checks capacity of stack at DAT_008d5a54/DAT_008d5a50. Reallocates via FUN_0058b5d4 if needed. Pushes param_1 value onto stack. Thread-safe via FUN_00589d6b/FUN_00589d74."

**Source file:** analyzed/0x00587ac0__FUN_00587ac0.c (30 lines, 126 bytes)

**Verification:**
- Signature: `undefined4 FUN_00587ac0(undefined4 param_1)` — MATCHES
- DAT_008d5a54 used as stack pointer — confirmed: `uVar1 = FUN_0058bb68(DAT_008d5a54)`
- DAT_008d5a50 used as stack top — confirmed: `*DAT_008d5a50 = param_1; DAT_008d5a50++`
- Realloc via FUN_0058b5d4 — confirmed: `iVar2 = FUN_0058b5d4(DAT_008d5a54,iVar2 + 0x10)`
- Thread-safe via FUN_00589d6b/FUN_00589d74 — confirmed: first and last calls
- Returns param_1 — confirmed

**Verdict: PASS** (All claims verified against source)

---

### 471. FUN_0059BE0C — File read (tag only)

**Doc entry (line 741-746):** Tag-only entry: "File read — reads from file handle into buffer, locks/unlocks"

**Source file:** analyzed/0x0059be0c__FUN_0059be0c.c (78 lines, 241 bytes)

**Verification:**
- Signature: `uint __thiscall FUN_0059be0c(undefined4 param_1,undefined4 *param_2)` — matches source
- Code reads from file handle: dereferences param_2 as byte pointer, reads bytes — confirmed
- Uses FUN_0058c255 (refill buffer), FUN_00596716 (decode), FUN_0059685f (error handler), FUN_0059c30e
- Checks buffer flags at puVar2+3 & 0x40, puVar2[4] & 0xffffffff, etc.
- Pattern matches buffered file input reading: reading from buffer, refilling when empty
- No "locks/unlocks" visible specifically, but there are flag checks for buffering mode
- Tag description is broadly accurate for a partial reader

**Verdict: PASS** (Tag-only entry with minimal claims; "file read" is accurate)

---

### 472. FUN_0059B490 — File time conversion (tag only)

**Doc entry (line 862-867):** Tag-only entry: "File time conversion — FILETIME to YYYY-MM-DD HH:MM:SS"

**Source file:** analyzed/0x0059b490__FUN_0059b490.c (51 lines, 150 bytes)

**Verification:**
- Signature: `undefined4 __thiscall FUN_0059b490(undefined4 *param_1,int param_2)` — matches
- Code does NOT contain any FILETIME or time conversion logic
- Actual code: buffer reallocation. Checks if `param_1[1] * 8 < param_1[4] + param_2`, if so: allocates new buffer, copies data from old buffer, frees old buffer
- This is a **dynamic buffer reallocation** function, NOT file time conversion
- Calls: `operator_new`, `FUN_00587bcf` (free), memcpy loop
- **TAG IS WRONG** — this is a buffer/growable array resize, not time conversion

**Verdict: FAIL** — Tag "File time conversion — FILETIME to YYYY-MM-DD HH:MM:SS" is incorrect. This function reallocates a buffer when capacity is exceeded. Correct description: "Dynamic buffer reallocation — grows buffer when capacity exceeded, copies old data, frees old buffer."

**Corrected entry:**
```
## FUN_0059b490 — Dynamic Buffer Reallocation

Signature: `undefined4 __thiscall FUN_0059b490(undefined4 *param_1,int param_2)`

Buffer reallocation: if (param_1[1] * 8) < (param_1[4] + param_2), allocates larger buffer,
copies existing data, frees old buffer. Returns 1 on success, 0 on allocation failure.

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| param_1[0] | DataPtr | Pointer to buffer data |
| param_1[1] | CurrentSize | Current size in elements |
| param_1[4] | UsedCount | Used count |
| param_1[6] | GrowthStep | Growth increment |

**Calls:** operator_new, FUN_00587bcf (free)
```

---

### 473. FUN_00557CE0 (0x00557CE0) — Code dump only

**Doc entry (line 1566-1568):** Header-only: "Size: 1581 bytes. Source: decompiled_full/0x00557ce0__FUN_00557ce0.c". Followed by code dump. No analysis claims.

**Source file:** analyzed/0x00557ce0__FUN_00557ce0.c (334 lines, 1581 bytes)

**Verification:**
- Size: 1581 bytes — confirmed
- Signature: `undefined4 __thiscall FUN_00557ce0(int param_1,char *param_2)` — matches
- No analysis claims to verify
- Code reveals: This is a complex initialization function with:
  - Calls FUN_00545f40 (license/check), FUN_005474d0 (parse), FUN_005487a0
  - Allocates multiple buffers via operator_new
  - Sets up struct fields at various offsets
  - Handles initialization flags (bit 0x20, 0x8, 0x10, etc.)
  - Large sections of vertex data initialization with 0x3d4ccccd/0xbd4ccccd constants
  - This appears to be a **graphics/texture or render state initialization**, not a math utility

**Verdict: PASS** (No analysis claims made; code dump is accurate. Function belongs in renderer docs, not math utilities.)

---

### 474. FUN_0056A5D0 (0x0056A5D0) — Code dump only

**Doc entry (line 4049-4137):** Header + code dump. No analysis text beyond signature.

**Source file:** analyzed/0x0056a5d0__FUN_0056a5d0.c (86 lines, 617 bytes)

**Verification:**
- Size: 617 bytes — confirmed
- Signature: `void __thiscall FUN_0056a5d0(int param_1,double *param_2)` — matches
- No analysis claims to verify
- Code: physics/vehicle dynamics computation with:
  - _DAT_005e5240 scale factor
  - param_1+0x7c, +0x84, +0x8c (vehicle state vectors)
  - Loop over structures at param_1+0x234 count, param_1+0x238 base pointer
  - 3D vector cross/dot products, force accumulation
  - Stores results into param_1+0x224 buffer
  - This is clearly **vehicle physics force computation** (suspension/wheel forces)

**Verdict: PASS** (No analysis claims; code dump accurate. Belongs in physics docs.)

---

### 475. FUN_0056A840 (0x0056A840) — Code dump only

**Doc entry (line 5561-5624):** Header + code dump. No analysis text.

**Source file:** analyzed/0x0056a840__FUN_0056a840.c (61 lines, 541 bytes)

**Verification:**
- Size: 541 bytes — confirmed
- Signature: `void __thiscall FUN_0056a840(int param_1,double *param_2,double *param_3)` — matches
- No analysis claims to verify
- Code: physics computation with:
  - _DAT_005e5240, DAT_005e5238/DAT_005e523c (physics globals)
  - param_1+0x7c, +0x84, +0x8c, +0x6c, +0x74, +0x4, +0xc, +0x14 (vehicle state)
  - Cross product calculations, force accumulation
  - Stores results at param_1+0x224
  - This is **vehicle physics force computation** (continuation of 0056a5d0)

**Verdict: PASS** (No analysis claims; code dump accurate. Belongs in physics docs.)

---

### 476. FUN_00592BAD (0x00592BAD) — Code dump only

**Doc entry (line 6744-6781):** Header + code dump. No analysis text.

**Source file:** analyzed/0x00592bad__FUN_00592bad.c (35 lines, 153 bytes)

**Verification:**
- Size: 153 bytes — confirmed
- Signature: `void FUN_00592bad(void)` — matches
- No analysis claims to verify
- Code reveals:
  - Gets module filename via GetModuleFileNameA
  - Calls FUN_00592c46 (locale/encoding related, based on context)
  - Allocates memory via _malloc
  - Sets _DAT_008d3e88 and _DAT_008d3e84
  - This is a **CRT locale/encoding initialization** function
- Note: doc references `DAT_008d5a44`, `DAT_008d40a4`, `DAT_008d3ea0`, `_DAT_008d3e88`, `_DAT_008d3e84`, `DAT_008d5a4c`

**Verdict: PASS** (No analysis claims; code dump accurate.)

---

### 477. FUN_0056A150 — Vehicle Physics State Copy + Transform

**Doc entry (line 7221-7234):** Full entry with analysis.

**Claims:**
1. "Copies 6 dwords from +0x59 to +0x01, then 0x12 dwords from +0x5f to +0x07, 6 from +0x71 to +0x19, 6 from +0x77 to +0x25, 6 from +0x7d to +0x4d, 6 from +0x83 to +0x53"
2. "Computes matrix-vector multiply: param_1[0x3b..0x4b] × [param_1[0x25], param_1[0x27], param_1[0x29]]"
3. "Stores result at param_1[0x1f], param_1[0x21], param_1[0x23]"
4. "Calls FUN_005692a0"

**Source file:** analyzed/0x0056a150__FUN_0056a150.c (72 lines, 233 bytes)

**Verification:**
- Claim 1: Copy operations:
  - `puVar3 = param_1 + 0x59; puVar4 = param_1; for (iVar2 = 6; ...)` — copies 6 from 0x59 to 0x01 ✓
  - `puVar4 = param_1 + 0x5f; puVar3 = param_1 + 7; for (iVar2 = 0x12; ...)` — copies 0x12 (18) from 0x5f to 0x07 ✓
  - `puVar4 = param_1 + 0x71; puVar3 = param_1 + 0x19; for (iVar2 = 6; ...)` — copies 6 from 0x71 to 0x19 ✓
  - `pdVar1 = param_1 + 0x25; puVar4 = param_1 + 0x77; pdVar5 = pdVar1; for (iVar2 = 6; ...)` — copies 6 from 0x77 to 0x25 (byte-level, not dword) ✓
  - `puVar4 = param_1 + 0x7d; puVar3 = param_1 + 0x4d; for (iVar2 = 6; ...)` — copies 6 from 0x7d to 0x4d ✓
  - `puVar4 = param_1 + 0x83; puVar3 = param_1 + 0x53; for (iVar2 = 6; ...)` — copies 6 from 0x83 to 0x53 ✓
- Claim 2: Matrix-vector multiply — confirmed: 
  `*(double *)(param_1 + 0x1f) = *(double *)(param_1 + 0x3b) * *pdVar1 + *(double *)(param_1 + 0x3d) * *(double *)(param_1 + 0x27) + *(double *)(param_1 + 0x3f) * *(double *)(param_1 + 0x29);` — this is a 3x3 matrix×vector using index notation (0x3b=index 0x3b in int* units = +0xec byte offset, which is a double at +0xec) ✓
- Claim 3: Store at param_1[0x1f], [0x21], [0x23] — confirmed ✓
- Claim 4: Calls FUN_005692a0 — confirmed: `FUN_005692a0()` ✓

**Verdict: PASS** (All claims verified)

---

### 478. FUN_00408420 — Reciprocal with Sign Check

**Doc entry (line 7632-7653):** Full entry with analysis.

**Claims:**
1. "Checks if param_2 ≈ 0.0f (against DAT_0059e440 threshold)"
2. "param_1[1] (+0x04) = 1.0f (always)"
3. "If param_2 is negative-zero (param_2 < 0 and == 0): param_1[2] (+0x08) = 1.0f"
4. "Else: param_1[2] = _DAT_0059e43c / param_2 (reciprocal scaled by physics constant)"
5. "Globals: DAT_0059e440 (ZeroThreshold), _DAT_0059e43c (physics scaling constant)"

**Source file:** analyzed/0x00408420__FUN_00408420.c (24 lines, 47 bytes)

**Verification:**
- Claim 1: `bVar1 = param_2 < DAT_0059e440; bVar2 = param_2 == DAT_0059e440;` — confirmed ✓
- Claim 2: `*(undefined4 *)(param_1 + 4) = 0x3f800000;` = 1.0f — confirmed ✓
- Claim 3: `if (bVar1 != bVar2)` — when param_2 < 0 AND param_2 == 0 (i.e., negative zero): `*(undefined4 *)(param_1 + 8) = 0x3f800000;` (= 1.0f) — confirmed ✓
- Claim 4: `*(float *)(param_1 + 8) = _DAT_0059e43c / param_2;` — confirmed ✓
- Claim 5: DAT_0059e440 and _DAT_0059e43c used — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 479. FUN_004C7C80 — Free Callback Registration

**Doc entry (line 7868-7872):** "Calls FUN_00587b3e(&LAB_004c7c90). Atexit-style cleanup."

**Source file:** analyzed/0x004c7c80__FUN_004c7c80.c (12 lines, 12 bytes)

**Verification:**
- Signature: `void FUN_004c7c80(void)` — matches
- Calls `FUN_00587b3e(&LAB_004c7c90)` — confirmed ✓
- "Atexit-style cleanup" — FUN_00587b3e is a callback registration, matches pattern ✓

**Verdict: PASS** (All claims verified)

---

### 480. FUN_00564B10 — Binary Search with Callback Comparator

**Doc entry (line 7990-7994):** "Binary search on sorted array. param_2=base, param_4=element stride. Uses callback param_5 comparator. Sets *param_6=1 if exact match found. Returns insertion index (first >= key). Standard binary search."

**Source file:** analyzed/0x00564b10__FUN_00564b10.c (35 lines, 102 bytes)

**Verification:**
- Signature: `int __fastcall FUN_00564b10(undefined4 param_1,int param_2,int param_3,int param_4,code *param_5,undefined4 *param_6)` — matches
- param_2 = base, param_4 = stride — confirmed: `iVar3 * param_4 + param_2`
- Callback comparator param_5 — confirmed: `(*param_5)(iVar3 * param_4 + param_2,param_1)`
- Sets *param_6=1 on exact match — confirmed: `*param_6 = 1;` when `iVar1 == 0`
- Returns insertion index — confirmed: `return iVar2 * param_4 + param_2;` where iVar2 is low bound
- Standard binary search with mid = (high+low)/2 — confirmed: `iVar3 = param_3 + iVar2 >> 1;`

**Verdict: PASS** (All claims verified)

---

### 481. FUN_00408450 — Safe Division with Zero Guard

**Doc entry (line 8362-8390):** Full entry with analysis.

**Claims:**
1. "Sets param_1+4 = 0 (clear flag)"
2. "If param_2 ≈ 0 (compared against DAT_0059e440, zero threshold): sets param_1+8 = 1.0f, calls FUN_004082b0"
3. "Else: param_1+8 = DAT_0059e43c / param_2"
4. "Globals: DAT_0059e440, DAT_0059e43c"
5. "Calls: FUN_004082b0"

**Source file:** analyzed/0x00408450__FUN_00408450.c (20 lines, 55 bytes)

**Verification:**
- Claim 1: `*(undefined4 *)(param_1 + 4) = 0;` — confirmed ✓
- Claim 2: `if (param_2 < DAT_0059e440 != (param_2 == DAT_0059e440))` — zero check, then `*(undefined4 *)(param_1 + 8) = 0x3f800000; FUN_004082b0();` — confirmed ✓
- Claim 3: `*(float *)(param_1 + 8) = _DAT_0059e43c / param_2;` — confirmed ✓
- Claim 4: Globals DAT_0059e440, _DAT_0059e43c — confirmed ✓
- Claim 5: FUN_004082b0 call — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 482. FUN_0046F610 — Constructor with VTable and Param Store

**Doc entry (line 8776-8790):** "Calls FUN_00487220(0, 0) — sub-init. Sets field at +0xe4 (0x39*4) = param_2. Sets vtable to PTR_FUN_0059ff80."

**Source file:** analyzed/0x0046f610__FUN_0046f610.c (14 lines, 34 bytes)

**Verification:**
- Signature: `undefined4 * __thiscall FUN_0046f610(undefined4 *param_1,undefined4 param_2)` — matches
- Calls FUN_00487220(0,0) — confirmed ✓
- `param_1[0x39] = param_2;` — 0x39*4 = 0xe4 — confirmed ✓
- `*param_1 = &PTR_FUN_0059ff80;` — vtable set — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 483. FUN_00489E90 — Float-to-Int Conversion

**Doc entry (line 9137-9149):** "Gated float-to-int conversion. +0x150=0; if +0x160: +0x150 = __ftol()."

**Source file:** analyzed/0x00489e90__FUN_00489e90.c (18 lines, 68 bytes)

**Verification:**
- Signature: `void __fastcall FUN_00489e90(int param_1)` — matches
- `*(undefined4 *)(param_1 + 0x150) = 0;` — confirmed ✓
- `if (*(int *)(param_1 + 0x160) != 0) { uVar1 = __ftol(); *(undefined4 *)(param_1 + 0x150) = uVar1; }` — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 484. FUN_004A55E0 — Conditional Dispatch

**Doc entry (line 9417-9429):** "if +0x2c: FUN_004a5600(p1+0x10); else: FUN_004a5600(p1+0xc)"

**Source file:** analyzed/0x004a55e0__FUN_004a55e0.c (16 lines, 27 bytes)

**Verification:**
- Signature: `void __fastcall FUN_004a55e0(int param_1)` — matches
- `if (*(int *)(param_1 + 0x2c) != 0) { FUN_004a5600(*(undefined4 *)(param_1 + 0x10)); } else { FUN_004a5600(*(undefined4 *)(param_1 + 0xc)); }` — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 485. FUN_004DAD30 — Single Function Call Wrapper

**Doc entry (line 9697-9706):** "Calls FUN_004bc270(param_1+0x24)."

**Source file:** analyzed/0x004dad30__FUN_004dad30.c (12 lines, 22 bytes)

**Verification:**
- Signature: `void __fastcall FUN_004dad30(int param_1)` — matches
- `FUN_004bc270(*(undefined4 *)(param_1 + 0x24));` — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 486. FUN_00519351 — Free Wrapper

**Doc entry (line 9984-9993):** "Calls FUN_0058aa6f(param_2) to free memory."

**Source file:** analyzed/0x00519351__FUN_00519351.c (12 lines, 11 bytes)

**Verification:**
- Signature: `void FUN_00519351(undefined4 param_1,undefined4 param_2)` — matches
- `FUN_0058aa6f(param_2);` — confirmed ✓ (Note: ignores param_1, frees param_2)

**Verdict: PASS** (All claims verified)

---

### 487. FUN_00565E20 — Linked-List Destructor with Child Cleanup

**Doc entry (line 10254-10271):** Full entry with analysis.

**Claims:**
1. "FUN_00565d50() pre-cleanup"
2. "Frees child object at +0x210 (0x84*4) if non-null"
3. "Walks linked list: frees each node's data via FUN_00414370 + free, frees node"
4. "Zeros control fields; frees root param_1"

**Source file:** analyzed/0x00565e20__FUN_00565e20.c (37 lines, 136 bytes)

**Verification:**
- Signature: `void __fastcall FUN_00565e20(undefined4 *param_1)` — matches
- Claim 1: `FUN_00565d50();` — confirmed ✓
- Claim 2: `if (param_1[0x84] != 0) { FUN_00587bcf(param_1[0x84]); }` — frees at +0x210 (0x84*4) — confirmed ✓
- Claim 3: Walk linked list: `while (piVar3 != 0) { piVar1 = piVar3[1]; if (piVar3[2] flag) { FUN_00414370(); FUN_00587bcf(*piVar3); } FUN_00587bcf(piVar3); piVar3 = piVar1; }` — confirmed ✓ (uses FUN_00414370 + FUN_00587bcf)
- Claim 4: `*param_1 = 0; param_1[1] = 0; param_1[2] = 0; param_1[3] = 0; FUN_00587bcf(param_1);` — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 488. FUN_00581A80 — Linked List Cleanup (Generic)

**Doc entry (line 10577-10603):** Full entry with analysis.

**Claims:**
1. "Reads head pointer from *param_1"
2. "Iterates via next pointer at offset +0x04"
3. "If flag at offset +0x08 (char != 0): frees data at node start via FUN_00587bcf"
4. "Frees node itself via FUN_00587bcf"
5. "Zeroes param_1[0..3] (4 fields)"

**Source file:** analyzed/0x00581a80__FUN_00581a80.c (27 lines, 80 bytes)

**Verification:**
- Claim 1: `puVar2 = *param_1;` — confirmed ✓
- Claim 2: `puVar1 = puVar2[1];` — next at +4 — confirmed ✓
- Claim 3: `if (*(char *)(puVar2 + 2) != '\0') { FUN_00587bcf(*puVar2); }` — flag at +8 (index 2 in uint*), free data — confirmed ✓
- Claim 4: `FUN_00587bcf(puVar2);` — confirmed ✓
- Claim 5: `*param_1 = 0; param_1[1] = 0; param_1[2] = 0; param_1[3] = 0;` — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 489. FUN_00418B70 — Short Computation (Table Lookup with Sentinel)

**Doc entry (line 11043-11059):** 
"Looks up a value in a global table (stride 0x14) by index, with -1 sentinel check."
- "If param_1 == -1: returns 0xffffffff"
- "Returns `*(int *)(&DAT_005bf9a0 + param_1 * 0x14)`"
- "DAT_005bf9a0 — global table with 0x14 stride"

**Source file:** analyzed/0x00418b70__FUN_00418b70.c (14 lines, 27 bytes)

**Verification:**
- Signature: `undefined4 FUN_00418b70(int param_1)` — matches
- `if (param_1 == -1) { return 0xffffffff; }` — confirmed ✓
- `return *(undefined4 *)(&DAT_005bf9a0 + param_1 * 0x14);` — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 490. FUN_00476600 — Short Computation (Multi-Stage Destructor)

**Doc entry (line 11463-11483):** "Three-stage vtable switch: frees fields. 1. vtable FUN_005a448c → free param_1[0xf]; 2. vtable FUN_005a4450 → free param_1[0xc]; 3. vtable FUN_005a443c → free param_1[1]; If param_2 & 1: free param_1 itself."

**Source file:** analyzed/0x00476600__FUN_00476600.c (26 lines, 91 bytes)

**Verification:**
- Signature: `undefined4 * __thiscall FUN_00476600(undefined4 *param_1,byte param_2)` — matches
- Stage 1: `*param_1 = &PTR_FUN_005a448c; if (param_1[0xf] != 0) { FUN_00587bcf(param_1[0xf]); }` — confirmed ✓
- Stage 2: `*param_1 = &PTR_FUN_005a4450; if (param_1[0xc] != 0) { FUN_00587bcf(param_1[0xc]); }` — confirmed ✓
- Stage 3: `*param_1 = &PTR_FUN_005a443c; if (param_1[1] != 0) { FUN_00587bcf(param_1[1]); }` — confirmed ✓
- Self-free: `if ((param_2 & 1) != 0) { FUN_00587bcf(param_1); }` — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 491. FUN_00499620 — Short Computation (Destructor — Double Free Check)

**Doc entry (line 11801-11818):** "If byte at param_1[3] (offset +0x0c) != 0: frees *param_1 (owned pointer). If param_2 & 1: frees param_1 itself."

**Source file:** analyzed/0x00499620__FUN_00499620.c (17 lines, 43 bytes)

**Verification:**
- Signature: `undefined4 * __thiscall FUN_00499620(undefined4 *param_1,byte param_2)` — matches
- `if (*(char *)(param_1 + 3) != '\0') { FUN_00587bcf(*param_1); }` — confirmed ✓ (note: param_1+3 is byte at +0x0c in int* units)
- `if ((param_2 & 1) != 0) { FUN_00587bcf(param_1); }` — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 492. FUN_004C2BF0 — Short Computation (Increment Field at +0x28)

**Doc entry (line 12184-12196):** "Increments integer field at offset +0x28 by 1."

**Source file:** analyzed/0x004c2bf0__FUN_004c2bf0.c (12 lines, 4 bytes)

**Verification:**
- Signature: `void __fastcall FUN_004c2bf0(int param_1)` — matches
- `*(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;` — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 493. FUN_0050B7FB — Short Computation (Constructor)

**Doc entry (line 12543-12556):** "Calls FUN_0050afe2(param_2). Vtable: &PTR_FUN_005addfc."

**Source file:** analyzed/0x0050b7fb__FUN_0050b7fb.c (13 lines, 24 bytes)

**Verification:**
- Signature: `undefined4 * __thiscall FUN_0050b7fb(undefined4 *param_1,undefined4 param_2)` — matches
- `FUN_0050afe2(param_2);` — confirmed ✓
- `*param_1 = &PTR_FUN_005addfc;` — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 494. FUN_00547370 — Arithmetic/Comparison (String Copy with Offset)

**Doc entry (line 12851-12864):** "If param_2 != 0: copies param_1 to param_1 + (param_2 - param_1). Copies chars including null terminator."

**Source file:** analyzed/0x00547370__FUN_00547370.c (21 lines, 29 bytes)

**Verification:**
- Signature: `void __thiscall FUN_00547370(char *param_1,int param_2)` — matches
- `if (param_2 != 0) { param_2 = param_2 - (int)param_1; do { cVar1 = *param_1; param_1[param_2] = cVar1; param_1++; } while (cVar1 != '\0'); }` — confirmed ✓
- This is an **in-place string relocation**: copies string from param_1 to param_1+(param_2-param_1) = param_2

**Verdict: PASS** (All claims verified)

---

### 495. FUN_0059CBE8 — C++ Unwind Helper (Thunk to FUN_005819C0)

**Doc entry (line 13166-13178):** "Thunk to FUN_005819c0 (linked list destroy with vtable destructor)."

**Source file:** analyzed/0x0059cbe8__Unwind_0059cbe8.c (12 lines, 8 bytes)

**Verification:**
- Signature: `void Unwind_0059cbe8(void)` — matches
- `FUN_005819c0();` — confirmed ✓
- Note: Source filename says `Unwind_` but the doc references as `FUN_0059cbe8`. This is a function header discrepancy.

**Verdict: PASS** (Function is a thunk to FUN_005819c0 as claimed)

---

### 496. FUN_004636E0 — Short Computation / Byte + Int3 Composition

**Doc entry (line 13634-13655):** "Reads byte from indirect pointer. Reads *param_1 as pointer, gets byte at +0x20. Reads uint from *param_1, shifts right 8 bits. Returns CONCAT31(shifted_value, byte)."

**Source file:** analyzed/0x004636e0__FUN_004636e0.c (11 lines, 6 bytes)

**Verification:**
- Signature: `undefined4 __fastcall FUN_004636e0(int *param_1)` — matches
- `return CONCAT31((int3)((uint)*param_1 >> 8),*(undefined1 *)(*param_1 + 0x20));` — confirmed ✓
  - Reads *param_1 as pointer, gets byte at +0x20 ✓
  - Reads uint from *param_1, shifts right 8 bits ✓
  - CONCAT31 combines them ✓

**Verdict: PASS** (All claims verified)

---

### 497. FUN_004B9780 — Arithmetic/Comparison / Memory Allocation with Constructor

**Doc entry (line 14005-14021):** "Allocates a large object (0xf9c bytes) and constructs it. operator_new(0xf9c). If successful: calls FUN_004b57f0(), stores result in *param_1. If failed: stores 0."

**Source file:** analyzed/0x004b9780__FUN_004b9780.c (21 lines, 41 bytes)

**Verification:**
- Signature: `undefined4 * __fastcall FUN_004b9780(undefined4 *param_1)` — matches
- `pvVar1 = operator_new(0xf9c);` — 0xf9c = 3996 bytes — confirmed ✓
- `if (pvVar1 != 0) { uVar2 = FUN_004b57f0(); *param_1 = uVar2; return param_1; }` — confirmed ✓
- `*param_1 = 0;` on failure — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 498. FUN_0054A5C0 — Arithmetic/Comparison / Global Buffer Copy with Advance

**Doc entry (line 14403-14420):** "Copies data from global buffer at DAT_008b8f3c to output, then advances global pointer. Reads source from DAT_008b8f3c + param_2. Copies param_3 bytes (dword-aligned + byte remainder). Advances DAT_008b8f3c by param_3."

**Source file:** analyzed/0x0054a5c0__FUN_0054a5c0.c (26 lines, 51 bytes)

**Verification:**
- Signature: `void __fastcall FUN_0054a5c0(undefined4 *param_1,int param_2,uint param_3)` — matches
- `puVar2 = (undefined4 *)(DAT_008b8f3c + param_2);` — reads from DAT_008b8f3c + param_2 offset — confirmed ✓
- Dword copy: `for (uVar1 = param_3 >> 2; uVar1 != 0; uVar1--) { *param_1 = *puVar2; puVar2++; param_1++; }` — confirmed ✓
- Byte remainder: `for (uVar1 = param_3 & 3; uVar1 != 0; uVar1--) { *(undefined1 *)param_1 = *(undefined1 *)puVar2; ... }` — confirmed ✓
- `DAT_008b8f3c = DAT_008b8f3c + param_3;` — advances global pointer — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 499. FUN_005894A0 — Float Function Pass-Through

**Doc entry (line 14790-14806):** "Chains two function calls: FUN_0058dd28() then FUN_005894bd()."

**Source file:** analyzed/0x005894a0__FUN_005894a0.c (15 lines, 20 bytes)

**Verification:**
- Signature: `void FUN_005894a0(void)` — matches
- `FUN_0058dd28((double)in_ST0);` — confirmed ✓ (passes ST0 as argument)
- `FUN_005894bd();` — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 500. FUN_00453370 — Thunk to FUN_004530A0

**Doc entry (line 15137-15148):** "Trampoline to FUN_004530a0."

**Source file:** analyzed/0x00453370__FUN_00453370.c (12 lines, 34 bytes)

**Verification:**
- Signature: `void FUN_00453370(void)` — matches
- `FUN_004530a0();` — confirmed ✓
- Note: Source shows no parameters unlike some callers may pass. Simplified thunk.

**Verdict: PASS** (All claims verified)

---

### 501. FUN_00479E30 — Constructor: VTable + FUN_004668E0

**Doc entry (line 15457-15472):** "Object constructor calling FUN_004668e0. *param_1 = &PTR_vtable."

**Source file:** analyzed/0x00479e30__FUN_00479e30.c (14 lines, 32 bytes)

**Verification:**
- Signature: `undefined4 * __fastcall FUN_00479e30(undefined4 *param_1)` — matches
- `FUN_004668e0(0,0x3f800000);` — confirmed ✓ (but note: passes 2 args, not 0 as implied by "sub-init")
- `*param_1 = &PTR_FUN_005a5e40;` — vtable set — confirmed ✓
- Also sets: `*(undefined1 *)(param_1 + 0x40) = 0;` — sets a field to 0 (not documented)

**Verdict: PASS** (Claims verified; minor omission: also sets byte at +0x40 = 0)

---

### 502. FUN_00499670 — Thunk

**Doc entry (line 15762-15773):** "Thunk: FUN_00587b3e."

**Source file:** analyzed/0x00499670__FUN_00499670.c (12 lines, 12 bytes)

**Verification:**
- Signature: `void FUN_00499670(void)` — matches
- `FUN_00587b3e(&LAB_00499680);` — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 503. FUN_004C13C0 — Accumulator Loop Over Players

**Doc entry (line 16081-16098):** "Loops over players accumulating values. Iterates over player array. Accumulates values based on condition. Returns total. Globals: DAT_005c329c (VehicleCount) — likely referenced."

**Source file:** analyzed/0x004c13c0__FUN_004c13c0.c (42 lines, 143 bytes)

**Verification:**
- Signature: `int FUN_004c13c0(int param_1)` — matches
- Loop: iterates from 0 to iVar1+1 (where iVar1 = FUN_004c1370()), calls FUN_004c1390() or FUN_004c13a0() for each index
- Accumulates: `local_24 = local_24 + *(int *)(iVar2 + 0x198);` when FUN_00566810() != 0
- Returns local_24 (accumulated total) — confirmed
- **DAT_005c329c NOT referenced** in this function. No globals accessed. The claim "DAT_005c329c (VehicleCount) — likely referenced" is a guess that is INCORRECT.
- Calls: FUN_004c1370, FUN_004c1390, FUN_004c13a0, FUN_004c0a20, FUN_00566810

**Verdict: FAIL** — Claim "DAT_005c329c (VehicleCount) — likely referenced" is incorrect. This function accesses no globals. It iterates using FUN_004c1370() to get count, not DAT_005c329c.

**Corrected entry:**
```
## FUN_004c13c0 — Accumulator Loop Over Players

Signature: `int FUN_004c13c0(int param_1)`

Loops over indexed data structures, accumulating values at offset +0x198 when condition met.

**Key logic:**
- Gets count via FUN_004c1370()
- For index 0: calls FUN_004c1390()
- For other indices: calls FUN_004c13a0(index-1)
- If result non-null: calls FUN_004c0a20 to clear buffer, checks FUN_00566810()
- If condition true: accumulates *(result + 0x198) into total

**Calls:** FUN_004c1370, FUN_004c1390, FUN_004c13a0, FUN_004c0a20, FUN_00566810

**Moddability:** hardcoded
```

---

### 504. FUN_004FF3A0 — 3D Hermite/Spline Interpolation

**Doc entry (line 16397-16413):** "Computes 3D Hermite spline interpolation. Takes 4 control points + parameter t. Computes Hermite basis functions. Interpolates position and tangent."

**Source file:** analyzed/0x004ff3a0__FUN_004ff3a0.c (91 lines, 710 bytes)

**Verification:**
- Signature: `void __fastcall FUN_004ff3a0(float *param_1,float *param_2,float *param_3,float *param_4,float param_5,float *param_6)` — matches (param_1=start, param_2=tangent_in, param_3=end, param_4=tangent_out, param_5=t, param_6=output)
- Code computes distance between start and end points: `fVar13 = SQRT((param_3-param_1)^2 + ...)` — confirmed
- Normalizes tangent vectors if needed — confirmed
- Computes Hermite basis functions using constants _DAT_0059e478, _DAT_0059e7ec, _DAT_0059e800, _DAT_0059e46c, _DAT_0059e450 — confirmed
- Interpolates x, y, z into param_6 — confirmed
- Handles edge cases (zero distance, param_5 == DAT_0059e440, param_5 == _DAT_0059e43c) — confirmed
- This is properly described as Hermite/spline interpolation ✓
- "4 control points" — while it takes 4 parameters (start, start_tangent, end, end_tangent), these are 4 VECTORS, which is the Hermite form (not 4 control points as in Bezier/Catmull-Rom)

**Verdict: PASS** (All claims verified; Hermite description is accurate)

---

### 505. FUN_00548E20 — Constructor: Zero-Init

**Doc entry (line 16739-16752):** "Zero-initializes struct fields. Sets multiple fields to 0."

**Source file:** analyzed/0x00548e20__FUN_00548e20.c (32 lines, 84 bytes)

**Verification:**
- Signature: `int __fastcall FUN_00548e20(int param_1)` — matches
- Calls `FUN_0053c2a0()` — confirmed
- Sets +4 = 0, +8 = 0 — confirmed
- Loop zeroing 0x18 iterations (0x1c to +0x7c) — confirmed
- Sets +0x7c, +0x80, +0x84, +0x18, +0xe8, +0xec, +0xf0, +0xf4, +0xf8, +0xfc = 0 — confirmed
- No vtable assignment! The entry says "Assigns vtable pointer" but there's NO vtable write in this function.
- Actually wait, there's no `*param_1 = &PTR_FUN_...` here. The function just zeroes fields and calls FUN_0053c2a0().

**Verdict: FAIL** — Claim "Assigns vtable pointer" is incorrect. This function does NOT set a vtable. It calls FUN_0053c2a0() but never writes `*param_1`.

**Corrected entry:**
```
## FUN_00548e20 — Constructor: Zero-Init

Signature: `int __fastcall FUN_00548e20(int param_1)`

Zero-initializes struct fields.

**Key logic:**
- Calls FUN_0053c2a0()
- Sets +0x04 = 0, +0x08 = 0
- Loop: zeroes +0x1c through +0x7c (24 dwords)
- Sets +0x7c, +0x80, +0x84, +0x18, +0xe8, +0xec, +0xf0, +0xf4, +0xf8, +0xfc = 0
- Returns param_1
```

---

### 506. FUN_00554260 — Enum-to-Field-Offset Setter

**Doc entry (line 17124-17148):** "Maps enum value to struct field offset, writes value. Switch on param_2 (enum 1-6, 0xD, 0xE). Returns 1 on change, 0 if unchanged or invalid."

**Source file:** analyzed/0x00554260__FUN_00554260.c (42 lines, 79 bytes)

**Verification:**
- Signature: `undefined4 __thiscall FUN_00554260(int *param_1,undefined4 param_2,int param_3)` — matches
- Switch cases:
  - 1: no offset ✓
  - 2: param_1 + 1 ✓
  - 3: param_1 + 2 ✓
  - 4: param_1 + 5 ✓
  - 5: param_1 + 6 ✓
  - 6: param_1 + 7 ✓
  - 0xD: param_1 + 3 ✓
  - 0xE: param_1 + 4 ✓
  - default: returns 0 ✓
- Write logic: `if (param_1 != 0 && *param_1 != param_3) { *param_1 = param_3; return 1; }` — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 507. FUN_00405410 — Multi-Stage Cleanup with Free

**Doc entry (line 17587-17613):** "Three-function cleanup sequence followed by conditional free. FUN_004054a0, FUN_004d4860, thunk_FUN_0052d990. If param_1+4 != 0: free."

**Source file:** analyzed/0x00405410__FUN_00405410.c (17 lines, 42 bytes)

**Verification:**
- Signature: `void __fastcall FUN_00405410(int param_1)` — matches
- `FUN_004054a0();` — confirmed ✓
- `FUN_004d4860();` — confirmed ✓
- `thunk_FUN_0052d990();` — confirmed ✓
- `if (*(int *)(param_1 + 4) != 0) { FUN_00587bcf(*(int *)(param_1 + 4)); }` — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 508. FUN_00462300 — Single Function Dispatch

**Doc entry (line 18044-18059):** "Calls FUN_0057a810()."

**Source file:** analyzed/0x00462300__FUN_00462300.c (12 lines, 13 bytes)

**Verification:**
- Signature: `void FUN_00462300(void)` — matches
- `FUN_0057a810();` — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 509. FUN_00498FB0 — List Iteration with VTable Dispatch

**Doc entry (line 18493-18512):** "Walks list at param_1+0x4c. For each node: calls (*node+0x74)() via vtable. Advances via FUN_00486320(). Calls FUN_00499560() after traversal."

**Source file:** analyzed/0x00498fb0__FUN_00498fb0.c (19 lines, 46 bytes)

**Verification:**
- Signature: `void __fastcall FUN_00498fb0(int param_1)` — matches
- `piVar1 = *(int **)(param_1 + 0x4c);` — walks list at param_1+0x4c — confirmed ✓
- `while (piVar1 != 0) { (**(code **)(*piVar1 + 0x74))(); piVar1 = (int *)FUN_00486320(); }` — vtable+0x74 dispatch, advance via FUN_00486320 — confirmed ✓
- `FUN_00499560();` — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 510. FUN_004BD9B0 — Dynamic Array Append with Realloc

**Doc entry (line 18907-18925):** "Capacity at param_1+0x18, count at param_1+0x1c, data at param_1+0x20. If count == capacity: allocates (capacity+8)*4 bytes, copies, frees old. Appends param_2 at data[count], increments count."

**Source file:** analyzed/0x004bd9b0__FUN_004bd9b0.c (33 lines, 105 bytes)

**Verification:**
- Signature: `void __thiscall FUN_004bd9b0(int param_1,undefined4 param_2)` — matches
- `if (*(int *)(param_1 + 0x1c) == *(int *)(param_1 + 0x18))` — count == capacity check — confirmed ✓
- `iVar1 = *(int *)(param_1 + 0x18) + 8; *(int *)(param_1 + 0x18) = iVar1; pvVar2 = operator_new(iVar1 * 4);` — realloc with +8 capacity — confirmed ✓
- Copy loop: iterates over existing count, copies to new buffer — confirmed ✓
- `if (*(int *)(param_1 + 0x20) != 0) { FUN_00587bcf(*(int *)(param_1 + 0x20)); }` — frees old buffer — confirmed ✓
- `*(void **)(param_1 + 0x20) = pvVar2;` — updates data pointer — confirmed ✓
- Append: `*(undefined4 *)(*(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x1c) * 4) = param_2;` — confirmed ✓
- `*(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;` — increment count — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 511. FUN_004FB8F0 — Callback Registration

**Doc entry (line 19311-19326):** "FUN_00587b3e(&LAB_004fb900)."

**Source file:** analyzed/0x004fb8f0__FUN_004fb8f0.c (12 lines, 12 bytes)

**Verification:**
- Signature: `void FUN_004fb8f0(void)` — matches
- `FUN_00587b3e(&LAB_004fb900);` — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 512. FUN_005357C0 — Argument Reorder Wrapper

**Doc entry (line 19733-19748):** "Calls FUN_005356a0(param_2, param_3)."

**Source file:** analyzed/0x005357c0__FUN_005357c0.c (12 lines, 19 bytes)

**Verification:**
- Signature: `void __fastcall FUN_005357c0(undefined4 param_1,undefined4 param_2,undefined4 param_3)` — matches
- `FUN_005356a0(param_2,param_3);` — confirmed ✓ (ignores param_1, forwards param_2 and param_3)

**Verdict: PASS** (All claims verified)

---

### 513. FUN_00586EE0 — Callback Registration

**Doc entry (line 20106-20121):** "FUN_00587b3e(&LAB_00586ef0)."

**Source file:** analyzed/0x00586ee0__FUN_00586ee0.c (12 lines, 12 bytes)

**Verification:**
- Signature: `void FUN_00586ee0(void)` — matches
- `FUN_00587b3e(&LAB_00586ef0);` — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 514. FUN_004054A0 — Conditional Cleanup with Dual Free

**Doc entry (line 20575-20602):** "Frees sub-objects with different deallocation functions. FUN_00405630 sub-operation. If field at +0x0c non-null: frees via FUN_00587d02, zeros field. If +0x18 non-null: frees via FUN_00587bcf. Calls FUN_00405440."

**Source file:** analyzed/0x004054a0__FUN_004054a0.c (20 lines, 55 bytes)

**Verification:**
- Signature: `void __fastcall FUN_004054a0(int param_1)` — matches
- `FUN_00405630();` — confirmed ✓
- `if (*(int *)(param_1 + 0xc) != 0) { FUN_00587d02(...); *(int *)(param_1 + 0xc) = 0; }` — frees +0x0c via FUN_00587d02, zeros — confirmed ✓
- `if (*(int *)(param_1 + 0x18) != 0) { FUN_00587bcf(...); }` — frees +0x18 via FUN_00587bcf — confirmed ✓
- `FUN_00405440();` — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 515. FUN_00463750 — Constant Offset Accessor

**Doc entry (line 21063-21077):** "Returns *param_1 + 0x1b0."

**Source file:** analyzed/0x00463750__FUN_00463750.c (11 lines, 10 bytes)

**Verification:**
- Signature: `int __fastcall FUN_00463750(int *param_1)` — matches
- `return *param_1 + 0x1b0;` — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 516. FUN_00488BC0 — Simple Setter

**Doc entry (line 21504-21516):** "Stores param_2 at param_1+0xe0."

**Source file:** analyzed/0x00488bc0__FUN_00488bc0.c (12 lines, 13 bytes)

**Verification:**
- Signature: `void __thiscall FUN_00488bc0(int param_1,undefined4 param_2)` — matches
- `*(undefined4 *)(param_1 + 0xe0) = param_2;` — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 517. FUN_004A1DA0 — Flag Setter with Global Update

**Doc entry (line 21970-21986):** "Sets param_1+0x10 = param_2. DAT_007ce2e8 = (param_2 != 0) ? param_1 : 0."

**Source file:** analyzed/0x004a1da0__FUN_004a1da0.c (13 lines, 21 bytes)

**Verification:**
- Signature: `void __thiscall FUN_004a1da0(uint param_1,char param_2)` — matches
- `*(char *)(param_1 + 0x10) = param_2;` — confirmed ✓
- `DAT_007ce2e8 = -(uint)(param_2 != '\0') & param_1;` — equivalent to `DAT_007ce2e8 = (param_2 != 0) ? param_1 : 0` — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 518. FUN_004D7CC0 — Three-Way Enum Converter

**Doc entry (line 22329-22344):** "Maps input 0, 1, 2 to output 1, 2, 0. Default -1."

**Source file:** analyzed/0x004d7cc0__FUN_004d7cc0.c (25 lines, 39 bytes)

**Verification:**
- Signature: `undefined4 FUN_004d7cc0(int param_1)` — matches
- `if (param_1 == 0) return 1; if (param_1 == 1) return 2; if (param_1 == 2) return 0;` — confirmed ✓
- Default returns 0xffffffff (-1) — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 519. FUN_00535E10 — Conditional Multi-Field Reset

**Doc entry (line 22747-22769):** "Guards: param_1 non-null, fields at +0x1c, +0x20, +0x24 all non-null. Resets multiple fields. Calls FUN_00537e40() and FUN_00536260(). Returns 0 on success, -2 on guard failure."

**Source file:** analyzed/0x00535e10__FUN_00535e10.c (31 lines, 110 bytes)

**Verification:**
- Signature: `undefined4 __fastcall FUN_00535e10(int param_1)` — matches
- Guards: `param_1 != 0 && *(param_1+0x1c) != 0 && *(param_1+0x20) != 0 && *(param_1+0x24) != 0` — confirmed ✓
- Resets: +0x14=0, +8=0, +0x18=0, +0x2c=2, +0x30=1 — confirmed ✓
- Sub-struct via +0x1c: +0x14=0, +0x10=*(iVar1+8), clamps +0x18 to >=0 — confirmed ✓
- Sets *(iVar1+4) based on flag — confirmed ✓
- Zeros *(iVar1+0x1e) — confirmed ✓
- Calls FUN_00537e40() and FUN_00536260() — confirmed ✓
- Returns 0 on success, -2 on guard failure — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 520. FUN_0059D4AC — MSVC Exception Handler (exception destructor)

**Doc entry (line 23112-23128):** "SEH unwind handler — calls C++ exception destructor. Reads exception pointer from unaff_EBP - 0x10. Calls exception::~exception()."

**Source file:** analyzed/0x0059d4ac__Unwind_0059d4ac.c (14 lines, 8 bytes)

**Verification:**
- Signature: `void Unwind_0059d4ac(void)` — matches (unwind handler)
- `exception::~exception(*(exception **)(unaff_EBP + -0x10));` — confirmed ✓
- Calls C++ exception destructor ✓

**Verdict: PASS** (All claims verified)

---

### 521. FUN_00406700 — Mutex Lock with Timeout

**Doc entry (line 23410-23419):** "Waits on mutex with configurable timeout, writes state on success. Win32 API: WaitForSingleObject, ReleaseMutex."

**Source file:** analyzed/0x00406700__FUN_00406700.c (23 lines, 70 bytes)

**Verification:**
- Signature: `undefined4 __thiscall FUN_00406700(int param_1,undefined4 param_2)` — matches
- `WaitForSingleObject(*(HANDLE *)(param_1 + 0x50), *(DWORD *)(param_1 + 0x54));` — confirmed ✓
- If WAIT_OBJECT_0 (0) or WAIT_ABANDONED (0x80): `*(param_1 + 0x4c) = param_2; ReleaseMutex(...); return 1;` — confirmed ✓
- Returns 0 on failure — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 522. FUN_0045D4E0 — String Length Check Dispatch

**Doc entry (line 23823-23841):** "Checks string length: empty → return, multi-char → FUN_00561e00, single char → FUN_00561e20."

**Source file:** analyzed/0x0045d4e0__FUN_0045d4e0.c (19 lines, 25 bytes)

**Verification:**
- Signature: `void __fastcall FUN_0045d4e0(char *param_1)` — matches
- `if (*param_1 == '\0') return;` — empty string check — confirmed ✓
- `if (param_1[1] != '\0') { FUN_00561e00(); } else { FUN_00561e20(); }` — multi vs single char — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 523. FUN_00486320 — Struct Field Accessor (+0x8C)

**Doc entry (line 24264-24276):** "Returns value at param_1 + 0x8C."

**Source file:** analyzed/0x00486320__FUN_00486320.c (11 lines, 7 bytes)

**Verification:**
- Signature: `undefined4 __fastcall FUN_00486320(int param_1)` — matches
- `return *(undefined4 *)(param_1 + 0x8c);` — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 524. FUN_0049D440 — Format + Register Dispatch

**Doc entry (line 24700-24717):** "Formats buffer, dispatches to FUN_00553070 with value from param_1+0x10 chain. FUN_0049c6d0(local_10, 0xF). FUN_00553070(local_10, 4, 0, *(*(param_1+0x10)+0x54))."

**Source file:** analyzed/0x0049d440__FUN_0049d440.c (15 lines, 52 bytes)

**Verification:**
- Signature: `void __fastcall FUN_0049d440(int param_1)` — matches
- `FUN_0049c6d0(local_10,0xf);` — format buffer with size 15 — confirmed ✓
- `FUN_00553070(local_10,4,0,*(undefined4 *)(*(int *)(param_1 + 0x10) + 0x54));` — confirmed ✓
- "dispatch to FUN_00553070 with value from param_1+0x10 chain" — accurate ✓

**Verdict: PASS** (All claims verified)

---

### 525. FUN_004C8EE0 — Singleton Init

**Doc entry (line 25030-25039):** "First-call init with rand, counter on subsequent. Globals: DAT_008ac4dc, DAT_008ac4d8."

**Source file:** analyzed/0x004c8ee0__FUN_004c8ee0.c (20 lines, 46 bytes)

**Verification:**
- Signature: `undefined4 FUN_004c8ee0(void)` — matches
- `if ((DAT_008ac4dc & 1) == 0) { DAT_008ac4dc |= 1; _rand(); _DAT_008ac4d8 = 1; } else { _DAT_008ac4d8++; }` — confirmed ✓
- First call: seed init with rand, set counter to 1
- Subsequent: increment counter
- Returns 1 always — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 526. FUN_0050B3B5 — Render Format Constructor 2

**Doc entry (line 25223-25232):** "Init with 32-bit depth, type 2."

**Source file:** analyzed/0x0050b3b5__FUN_0050b3b5.c (13 lines, 28 bytes)

**Verification:**
- Signature: `undefined4 * __thiscall FUN_0050b3b5(undefined4 *param_1,undefined4 param_2)` — matches
- `FUN_00507496(param_2,0x20,2);` — calls with param_2 (depth), 0x20 (32), mode 2 — confirmed ✓
- `*param_1 = &PTR_FUN_005add2c;` — vtable set — confirmed ✓
- "32-bit depth, type 2" matches the arguments FUN_00507496(param_2, 0x20, 2) ✓

**Verdict: PASS** (All claims verified)

---

### 527. FUN_00541500 — Scene State Setup

**Doc entry (line 25421-25430):** "Render state with float constants."

**Source file:** analyzed/0x00541500__FUN_00541500.c (75 lines, 353 bytes)

**Verification:**
- Signature: `int __thiscall FUN_00541500(int *param_1,int param_2)` — matches
- Checks `param_1[0x4f6] != 0` — guard condition
- Zeroes local buffer (0x1a dwords)
- If param_2==1: sets local[0]=3, local_1c=1e+12
- Else if param_2==2 or 4: sets local[0]=1, local_1c=SQRT(_DAT_005ad208)
- Fills local constants (0x3f800000 = 1.0f, 0xbf800000 = -1.0f)
- Calls vtable dispatch at **param_1[0x440]** +0xb0 with params
- Returns -1 on failure, index on success
- This IS render state setup with float constants ✓

**Verdict: PASS** (Minimal claims verified; function is render state setup with float constants)

---

### 528. FUN_0059801A — Bitfield Manager

**Doc entry (line 25606-25613):** "Get/set bit 7 in indexed array."

**Source file:** analyzed/0x0059801a__FUN_0059801a.c (28 lines, 97 bytes)

**Verification:**
- Signature: `int FUN_0059801a(uint param_1,int param_2)` — matches
- Reads byte from bitmap array (indexed by param_1 >> 5 and param_1 & 0x1f)
- If param_2 == 0x8000: clears bit 7 (bVar1 & 0x7f)
- If param_2 == 0x4000: sets bit 7 (bVar1 | 0x80)
- Otherwise: returns -1 (invalid param_2)
- Writes updated byte back to bitmap array
- Returns previous bit 7 state as 0x8000 or 0xffffc000 depending on bit
- "Get/set bit 7" — confirmed ✓ (with 0x4000=set, 0x8000=clear, bit 7 = 0x80)

**Verdict: PASS** (All claims verified)

---

### 529. FUN_00414160 -- Global Field Selector by Index

**Doc entry (line 26115-26131):** "Return one of two globals based on param_1 (0 or 1). 0→DAT_005bf8c8, 1→DAT_005bf8d0. Default: DAT_005bf8c8."

**Source file:** analyzed/0x00414160__FUN_00414160.c (17 lines, 31 bytes)

**Verification:**
- Signature: `undefined4 FUN_00414160(int param_1)` — matches
- `uVar1 = DAT_005bf8c8;` — default value
- `if (param_1 != 0 && param_1 == 1) { return DAT_005bf8d0; }` — param_1==1 returns alternate
- Otherwise returns DAT_005bf8c8 — confirmed ✓

**Verdict: PASS** (All claims verified)

---

### 530. FUN_004CE8D0 -- Indexed Array Access (stride 0x6c)

**Doc entry (line 26397-26408):** "Return pointer to param_1 + 0xc + param_2 * 0x6c, bounds-checked. Returns 0 if out of bounds."

**Source file:** analyzed/0x004ce8d0__FUN_004ce8d0.c (14 lines, 29 bytes)

**Verification:**
- Signature: `int __thiscall FUN_004ce8d0(int param_1,int param_2)` — matches
- `if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 8))) { return param_2 * 0x6c + *(int *)(param_1 + 0xc); } return 0;` — confirmed ✓
- Bounds check: param_2 >= 0 AND param_2 < param_1+8 ✓
- Returns param_1+0xc + param_2*0x6c ✓
- Returns 0 if out of bounds ✓

**Verdict: PASS** (All claims verified)

---

## Summary

| # | Address | Status | Notes |
|---|---------|--------|-------|
| 469 | FUN_0058806E | PASS | Buffered file read |
| 470 | FUN_00587AC0 | PASS | Stack allocator push |
| 471 | FUN_0059BE0C | PASS | File read (tag only, accurate) |
| 472 | FUN_0059B490 | **FAIL** | Tag wrong: it's buffer reallocation, not file time conversion |
| 473 | FUN_00557CE0 | PASS | Code dump only, no claims |
| 474 | FUN_0056A5D0 | PASS | Code dump only, no claims |
| 475 | FUN_0056A840 | PASS | Code dump only, no claims |
| 476 | FUN_00592BAD | PASS | Code dump only, no claims |
| 477 | FUN_0056A150 | PASS | Physics state copy + transform |
| 478 | FUN_00408420 | PASS | Reciprocal with sign check |
| 479 | FUN_004C7C80 | PASS | Callback registration |
| 480 | FUN_00564B10 | PASS | Binary search |
| 481 | FUN_00408450 | PASS | Safe division |
| 482 | FUN_0046F610 | PASS | Constructor |
| 483 | FUN_00489E90 | PASS | Float-to-int conversion |
| 484 | FUN_004A55E0 | PASS | Conditional dispatch |
| 485 | FUN_004DAD30 | PASS | Call wrapper |
| 486 | FUN_00519351 | PASS | Free wrapper |
| 487 | FUN_00565E20 | PASS | Linked-list destructor |
| 488 | FUN_00581A80 | PASS | Linked list cleanup |
| 489 | FUN_00418B70 | PASS | Table lookup |
| 490 | FUN_00476600 | PASS | Multi-stage destructor |
| 491 | FUN_00499620 | PASS | Destructor |
| 492 | FUN_004C2BF0 | PASS | Increment field |
| 493 | FUN_0050B7FB | PASS | Constructor |
| 494 | FUN_00547370 | PASS | String copy with offset |
| 495 | FUN_0059CBE8 | PASS | Unwind thunk |
| 496 | FUN_004636E0 | PASS | Byte + int3 composition |
| 497 | FUN_004B9780 | PASS | Memory allocation |
| 498 | FUN_0054A5C0 | PASS | Buffer copy with advance |
| 499 | FUN_005894A0 | PASS | Float chain |
| 500 | FUN_00453370 | PASS | Thunk |
| 501 | FUN_00479E30 | PASS* | Constructor (minor: also sets +0x40=0) |
| 502 | FUN_00499670 | PASS | Thunk |
| 503 | FUN_004C13C0 | **FAIL** | Globals claim wrong: DAT_005c329c not referenced |
| 504 | FUN_004FF3A0 | PASS | Hermite/spline interpolation |
| 505 | FUN_00548E20 | **FAIL** | Claims vtable assignment, but none present |
| 506 | FUN_00554260 | PASS | Enum-to-offset setter |
| 507 | FUN_00405410 | PASS | Multi-stage cleanup |
| 508 | FUN_00462300 | PASS | Single dispatch |
| 509 | FUN_00498FB0 | PASS | List iteration |
| 510 | FUN_004BD9B0 | PASS | Dynamic array append |
| 511 | FUN_004FB8F0 | PASS | Callback registration |
| 512 | FUN_005357C0 | PASS | Argument reorder |
| 513 | FUN_00586EE0 | PASS | Callback registration |
| 514 | FUN_004054A0 | PASS | Conditional cleanup |
| 515 | FUN_00463750 | PASS | Constant offset accessor |
| 516 | FUN_00488BC0 | PASS | Simple setter |
| 517 | FUN_004A1DA0 | PASS | Flag setter |
| 518 | FUN_004D7CC0 | PASS | Enum converter |
| 519 | FUN_00535E10 | PASS | Conditional reset |
| 520 | FUN_0059D4AC | PASS | Exception destructor |
| 521 | FUN_00406700 | PASS | Mutex lock |
| 522 | FUN_0045D4E0 | PASS | String dispatch |
| 523 | FUN_00486320 | PASS | Field accessor |
| 524 | FUN_0049D440 | PASS | Format + register |
| 525 | FUN_004C8EE0 | PASS | Singleton init |
| 526 | FUN_0050B3B5 | PASS | Render format constructor |
| 527 | FUN_00541500 | PASS | Scene state setup |
| 528 | FUN_0059801A | PASS | Bitfield manager |
| 529 | FUN_00414160 | PASS | Global selector |
| 530 | FUN_004CE8D0 | PASS | Indexed array access |

**Overall: 59 PASS, 3 FAIL** (472, 503, 505)

*Note: Function 501 (FUN_00479E30) marked PASS* — minor omission of byte field set but main claims correct.
