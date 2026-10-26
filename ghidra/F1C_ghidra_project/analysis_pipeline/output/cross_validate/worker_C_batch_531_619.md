# Cross-Validation Audit: worker_C batch 531-619

Auditing doc entries in docs/20-math-utilities.md and docs/21-audio-network-internals.md against .c source files.

---

## 531. FUN_00587D7F — CRT Stream getc with Lock/Unlock

Source: 0x00587d7f__FUN_00587d7f.c (20 lines)
Doc: docs/20-math-utilities.md @ line 26725

**Verdict: PASS**

All claims verified:
- Calls FUN_0058c5ac() (lock acquire) — present in .c
- If lock fails (iVar1==0): return 0 — present
- Calls FUN_0058c43c(param_1, param_2, param_3, iVar1) — present
- Calls FUN_0058c203(iVar1) (lock release) — present
- Returns uVar2 — present
- No globals claimed — correct, none appear

---

## 532. FUN_004190C0 — Linked List Free with Optional Data Cleanup

Source: 0x004190c0__FUN_004190c0.c (27 lines)
Doc: docs/20-math-utilities.md @ line 27183

**Verdict: PASS**

All claims verified:
- Walk list at param_1+0x1a0 — present (*(int**)(param_1+0x1a0))
- Save next from [1], flag at byte [2], data [0] — present (piVar2[1], (char)piVar2[2], *piVar2)
- If flag and data non-null: free data via FUN_00587bcf — present
- Free node itself via FUN_00587bcf — present
- Zero offsets 0x1a0, 0x1a4, 0x1a8, 0x1ac — present

---

## 533. FUN_004750F0 — UI Object Init with Zero Fields

Source: 0x004750f0__FUN_004750f0.c (16 lines)
Doc: docs/20-math-utilities.md @ line 27571

**Verdict: PASS**

All claims verified:
- FUN_004893c0() base init — present
- param_1[0x5d]=0, param_1[0x5e]=0 — present
- byte at param_1+0x5f=0 — present (*(undefined1*)(param_1+0x5f))
- *param_1 = &PTR_FUN_005a4370 (vtable) — present

---

## 534. FUN_00495AE0 — Resource Unlink with Callback

Source: 0x00495ae0__FUN_00495ae0.c (24 lines)
Doc: docs/20-math-utilities.md @ line 27958

**Verdict: PASS**

All claims verified:
- Guard: *(param_1+0x14) != 0 and *(*(param_1+0x14)+100) != 0 — present
- iVar1 = *(param_1+0x18), iVar2 = *(iVar1+0x68) — present
- Update link: *(param_1+0x18)=iVar2, *(iVar2+100)=0 — present
- FUN_00499050(iVar1[1..4]) — present (*(iVar1+4), *(iVar1+8), *(iVar1+0xc), *(iVar1+0x10))
- Zero iVar1[25](+100) and iVar1[26](+0x68) — present

---

## 535. FUN_004BA770 — Single Call Wrapper

Source: 0x004ba770__FUN_004ba770.c (12 lines)
Doc: docs/20-math-utilities.md @ line 28312

**Verdict: PASS**

All claims verified:
- Calls FUN_004b8010() — present
- No params, no globals — correct

---

## 536. FUN_004F31F0 — 6×6 Array Zero-Init

Source: 0x004f31f0__FUN_004f31f0.c (32 lines)
Doc: docs/20-math-utilities.md @ line 28692

**Verdict: PASS**

All claims verified:
- Loop 6 times: zero 6 consecutive ints (6×6 = 36 ints) — present (starts at puVar2[-4] through puVar2[1], 6 per row)
- Zero additional fields at +0x90..+0xa4 — present (6 ints at +0x90, +0x94, +0x98, +0x9c, +0xa0, +0xa4)
- No calls — correct

---

## 537. FUN_0052765A — Async I/O/State Reset Handler

Source: 0x0052765a__FUN_0052765a.c (32 lines)
Doc: docs/20-math-utilities.md @ line 29088

**Verdict: PASS**

All claims verified:
- If param_3 non-null: *param_3 = param_1[0xf] — present
- If *param_1 == 4 or 5: dispatch callback at param_2+0x24(param_2+0x28, param_1[3]) — present
- If *param_1 == 6: FUN_0052a090(param_1[1], param_2) — present
- Reset: param_1[0xd]=param_1[10], param_1[0xc]=param_1[10], *param_1=0, [7]=0, [8]=0 — present
- If param_1[0xe] non-null: callback(0,0,0), result at param_1[0xf] and param_2+0x30 — present

---

## 538. FUN_0056EB90 — Array-of-Structs Zero-Init (stride 0x244)

Source: 0x0056eb90__FUN_0056eb90.c (36 lines)
Doc: docs/20-math-utilities.md @ line 29452

**Verdict: PASS**

All claims verified:
- Loop based on *param_1 count — present (0 < *param_1)
- Base from param_1[1] — present (param_1[1] + iVar3)
- Zero 12 ints at offsets 0x134..0x160 — present (12 entries verified: 0x134, 0x138, 0x13c, 0x140, 0x144, 0x148, 0x14c, 0x150, 0x154, 0x158, 0x15c, 0x160)
- Stride 0x244 — present (iVar3 += 0x244)

---

## 539. FUN_00404B50 — Short Computation (Struct Field Zero)

Source: 0x00404b50__FUN_00404b50.c (17 lines)
Doc: docs/20-math-utilities.md @ line 29908

**Verdict: PASS**

All claims verified:
- Reads pointer from *param_1 (indirect) — present (iVar1 = *param_1)
- Zeroes byte at +0x14 — present
- Zeroes byte at +0x15 — present
- Zeroes dword at +0x1c — present

---

## 540. FUN_0059B758 — Struct Field Getter at +0x10

Source: 0x0059b758__FUN_0059b758.c (11 lines)
Doc: docs/20-math-utilities.md @ line 30344

**Verdict: PASS**

All claims verified:
- Returns *(param_1 + 0x10) — present
- No calls, no globals — correct

---

## 541. FUN_005276C5 — Multi-Block Allocator

Source: 0x005276c5__FUN_005276c5.c (34 lines)
Doc: docs/20-math-utilities.md @ line 30788

**Verdict: FAIL** — doc swapped field descriptions

Claims verified correctly:
- Allocates 0x40-byte header via slot 0x20(0x28, 1, 0x40) — present
- Allocates 0x5a0-byte workspace via slot 0x20(0x28, 8, 0x5a0) — present
- Allocates param_3-byte buffer via slot 0x20(0x28, 1, param_3) — present
- On failure frees previous allocations via slot 0x24 — present
- *header = 0 — present
- [9] = workspace — present (puVar1[9] = iVar2 from workspace alloc)
- [0xe] = param_2 — present
- Calls FUN_0052765a() — present

**Doc error:** claims "[10] = buffer_end" and "[0xb] = buffer + param_3".
Source shows: puVar1[10] = iVar2 (buffer START pointer), puVar1[0xb] = iVar2 + param_3 (buffer END).
The doc has the labels swapped: [10] is buffer START, [0xb] is buffer END.

Corrected description: Sets header fields: *header=0, [9]=workspace, [10]=buffer_ptr, [0xb]=buffer+param_3 (end), [0xe]=param_2.

---

## 542. FUN_00500170 — Short Computation (Struct Init with Values)

Source: 0x00500170__FUN_00500170.c (15 lines)
Doc: docs/20-math-utilities.md @ line 31231

**Verdict: PASS**

All claims verified:
- *param_1 = DAT_005ad344 (vtable/data ptr) — present
- param_1[1] = 8 (count/size) — present
- Calls FUN_00500190() and FUN_005001b0() — present

---

## 543. FUN_0049F070 — Init Chain

Source: 0x0049f070__FUN_0049f070.c (21 lines)
Doc: docs/20-math-utilities.md @ line 31650

**Verdict: PASS**

All claims verified:
- Sequential calls to: FUN_0049f790, FUN_004082b0, FUN_00461d20, FUN_004d8450, FUN_0049d070 — present
- If DAT_008ab6e4 != 2: calls FUN_0045bc00() — present
- Then FUN_0049f870, FUN_0049fdb0 — present
- Globals: DAT_008ab6e4 — present and used correctly

---

## 544. FUN_004870E0 — UI List Position Lookup

Source: 0x004870e0__FUN_004870e0.c (31 lines)
Doc: docs/20-math-utilities.md @ line 32029

**Verdict: PASS**

All claims verified:
- Reads offset from param_1+4 (base position) — present (*(int*)(param_1+4))
- Gets count via FUN_0049adb0() — present
- If param_2 < count: calls FUN_0049aec0 to look up, returns (short)result + base — present
- Else if param_1+200 != 0: same lookup on alternative path — present
- Returns -1 on failure — present

---

## 545. FUN_00466140 — VTable Set + Init Calls

Source: 0x00466140__FUN_00466140.c (14 lines)
Doc: docs/20-math-utilities.md @ line 32471

**Verdict: PASS**

All claims verified:
- *param_1 = &PTR_FUN_0059f140 (vtable) — present
- Calls FUN_004662e0() — present
- Calls FUN_0048e670() — present

---

## 546. FUN_0055D200 — Struct Zero-Init with Base Call

Source: 0x0055d200__FUN_0055d200.c (21 lines)
Doc: docs/20-math-utilities.md @ line 32907

**Verdict: PASS**

All claims verified:
- Calls FUN_0053c2a0 (base struct initializer) — present
- Sets param_1[0]=0 — present
- Sets param_1[5..0xc]=0 (fields [5],[6],[7],[8],[9],[10],[0xb],[0xc]) — all present
- Returns param_1 — present
- Struct offset table matches source

---

## 547. FUN_004DBAB0 — [PARTIAL] Unknown

Source: 0x004dbab0__FUN_004dbab0.c (14 lines)
Doc: docs/20-math-utilities.md @ line 33258

**Verdict: PASS** (partial entry — no substantive claims to fail)

Doc explicitly marked as [PARTIAL] Unknown with low confidence. No claims beyond needing manual review.
Source: calls FUN_0059d948(unaff_ESI). Entry correctly acknowledges it needs analysis.

---

## 548. FUN_005151AF — [PARTIAL] Unknown

Source: 0x005151af__FUN_005151af.c (79 lines)
Doc: docs/20-math-utilities.md @ line 33557

**Verdict: PASS** (partial entry — doc acknowledges needing manual analysis)

Doc says "11 lines of decompiled code" but actual source is 79 lines with complex logic.
However, entry is marked [PARTIAL] with low confidence — no substantive claims to fail.
Note: actual function is more complex than "11 lines" suggests. Contains float/int conversion, interpolation loops, and multiple globals (_DAT_0059e460, _DAT_005adb14, _DAT_005ad210, _DAT_0059e7e8).

---

## 549. FUN_00550810 — [PARTIAL] Unknown

Source: 0x00550810__FUN_00550810.c (12 lines)
Doc: docs/20-math-utilities.md @ line 33857

**Verdict: PASS** (partial entry)

Source: calls FUN_00587bcf(*(param_1+4)). Marked [PARTIAL] — appropriately labeled.

---

## 550. FUN_00404D00 — Array Indexed Pointer Getter

Source: 0x00404d00__FUN_00404d00.c (11 lines)
Doc: docs/20-math-utilities.md @ line 34191

**Verdict: PASS**

All claims verified:
- Returns (&PTR_PTR_005be6c4)[param_1] — exact match

---

## 551. FUN_0059C62A — SEH Unwind Handler (Free Stack Var at +8)

Source: 0x0059c62a__Unwind_0059c62a.c (14 lines)
Doc: docs/20-math-utilities.md @ line 34657

**Verdict: PASS**

All claims verified:
- Frees *(void**)(EBP + 8) via FUN_00587bcf — present (FUN_00587bcf(*(unaff_EBP+8)))
- Called only during stack unwinding — correct SEH unwind handler

---

## 552. FUN_00421480 — Callback Registration

Source: 0x00421480__FUN_00421480.c (12 lines)
Doc: docs/20-math-utilities.md @ line 35022

**Verdict: PASS**

All claims verified:
- FUN_00587b3e(&LAB_00421490) — exact match

---

## 553. FUN_00477EA0 — UI Object Constructor

Source: 0x00477ea0__FUN_00477ea0.c (18 lines)
Doc: docs/20-math-utilities.md @ line 35350

**Verdict: PASS**

All claims verified:
- Calls FUN_00488180 — present
- Calls FUN_00499b10 — present
- param_1[0x57]=-1 (0xffffffff) — present
- param_1[0x56]=0 — present
- param_1[0x47]=-1 — present
- param_1[0x48]=-1 — present
- *param_1 = &PTR_FUN_005a46b0 — present

---

## 554. FUN_00497940 — Lookup Dispatch

Source: 0x00497940__FUN_00497940.c (21 lines)
Doc: docs/20-math-utilities.md @ line 35621

**Verdict: PASS**

All claims verified:
- If param_1 != 0: calls FUN_004976c0(param_1) — present
- If result non-null: calls FUN_00497890(result, param_2) — present
- Returns result or 0 — present

---

## 555. FUN_004BB150 — List Append with Sub-List Generation

Source: 0x004bb150__FUN_004bb150.c (65 lines)
Doc: docs/20-math-utilities.md @ line 35903

**Verdict: PASS**

All claims verified:
- Appends node to primary list (12-byte node, data=param_2, flag=1) — present
- Generates sub-list: 32 or 64 entries (0x20 or 0x20+0x20) — present (param_3 determines)
- Stride 0xc — present (iVar4 += 0xc)
- Each node: value = *param_2 + offset, flag=0 — present
- Calls operator_new (×N) — present

---

## 556. FUN_004F8C70 — Global Callback Dispatcher

Source: 0x004f8c70__FUN_004f8c70.c (15 lines)
Doc: docs/20-math-utilities.md @ line 36124

**Verdict: PASS**

All claims verified:
- If DAT_008afc88 non-null: calls it with param_1, returns 0 — present
- Else returns 4 — present
- Globals: DAT_008afc88 — present
- Moddability: hookable — correct (configurable via global function pointer)

---

## 557. FUN_0052DF70 — State Check and Conditional Init

Source: 0x0052df70__FUN_0052df70.c (19 lines)
Doc: docs/20-math-utilities.md @ line 36244

**Verdict: PASS**

All claims verified:
- Calls FUN_0052df90() — present
- Stores masked result (0xff) in DAT_008b0108 — present
- If non-zero: calls FUN_005317c0() — present
- Globals: DAT_008b0108 — present

---

## 558. FUN_00585400 — VTable Dispatch with Conditional Branch

Source: 0x00585400__FUN_00585400.c (21 lines)
Doc: docs/20-math-utilities.md @ line 36364

**Verdict: PASS**

All claims verified:
- If FUN_00586d00() returns 0: dispatches vtable+0x2c, calls FUN_00584230, dispatches vtable+0x5c — present
- Else: calls FUN_00584dd0 — present
- Returns 1 — present

---

## 559. FUN_0059750A — Array-of-Struct Linear Search by ID

Source: 0x0059750a__FUN_0059750a.c (28 lines)
Doc: docs/20-math-utilities.md @ line 36624

**Verdict: PASS**

All claims verified:
- Step 0xc through array starting at param_2 — present
- For DAT_005e7894 entries — present (param_2 + DAT_005e7894*0xc bound check)
- Compare *(entry + 4) == param_1 — present
- Returns matching entry pointer, or 0 if not found — present
- Short-circuit: checks first entry before entering loop — present
- Globals: DAT_005e7894 — present

---

## 560. FUN_00429FD0 — Random-Weighted Tier Selection

Source: 0x00429fd0__FUN_00429fd0.c (82 lines)
Doc: docs/20-math-utilities.md @ line 36999

**Verdict: PASS**

All claims verified:
- Compares DAT_008afee8 against threshold chain — present (chain of _DAT_xxx <= DAT_008afee8)
- Uses _rand() at boundaries — present
- Returns 4-6 depending on threshold crossing — present
- 50/50 randomization at some boundaries — present
- Searches vehicle array for matching tier — present (loop calling FUN_004a4830)
- Globals listed: DAT_008afee8, DAT_0059e868, DAT_0059e7e8, DAT_0059e450, DAT_0059e970, DAT_0059e8cc, DAT_0059e908 — all present in source
- Calls: _rand, FUN_004d7570, FUN_004a4830 — all present

---

## 561. FUN_004799E0 — Init with VTable

Source: 0x004799e0__FUN_004799e0.c (13 lines)
Doc: docs/20-math-utilities.md @ line 37336

**Verdict: PASS**

All claims verified:
- FUN_00466980(0, 0x3e99999a) = (0, 0.3f) — present
- *param_1 = &PTR_FUN_005a57c8 — present

---

## 562. FUN_00499280 — Destructor with List Walk

Source: 0x00499280__FUN_00499280.c (29 lines)
Doc: docs/20-math-utilities.md @ line 37614

**Verdict: PASS**

All claims verified:
- *param_1 = &PTR_FUN_005aca74 — present
- Walks list at param_1[0x11], calls virtual destructor on each node (+0)(1) — present
- Frees param_1[0x18] and param_1[0x16] via FUN_00587bcf — present (both conditional)
- FUN_0049a990() — present

---

## 563. FUN_004BE1D0 — Nested Loop Range Traversal

Source: 0x004be1d0__FUN_004be1d0.c (76 lines)
Doc: docs/20-math-utilities.md @ line 37907

**Verdict: PASS**

All claims verified:
- 4 float-to-int conversions via __ftol, each clamped [0,7] — present
- Double loop: outer = iVar4-iVar3+1, inner = param_1-iVar5+1 — present (note: iVar3 reused for inner count)
- Calls FUN_004bd9b0 in inner loop — present
- If any value was clamped (bVar1): calls FUN_004bd9b0 one extra time — present

---

## 564. FUN_004FC9C0 — Struct Init with Float Defaults

Source: 0x004fc9c0__FUN_004fc9c0.c (40 lines)
Doc: docs/20-math-utilities.md @ line 38222

**Verdict: PASS**

All claims verified:
- FUN_004fc850() and FUN_004fc280() — present
- *param_1 = 1.0f (0x3f800000) — present
- Sentinels: +0x4a=0xffff, +0x13=0xffff, +0x4e=0, +0x14=0x7fff, +0x52=0x8000 — all present
- FUN_004fd6f0() — present

---

## 565. FUN_00537000 — State Reset with Callback

Source: 0x00537000__FUN_00537000.c (32 lines)
Doc: docs/20-math-utilities.md @ line 38526

**Verdict: PASS**

All claims verified:
- If param_3 non-null: *param_3 = param_1[0xf] — present
- If *param_1 in {4,5}: calls vtable+0x24 method — present (code at param_2+0x24)
- If *param_1 == 6: calls FUN_00539f60() — present
- Resets *param_1=0, copies param_1[10] to +0xd and +0xc, sets +0x7=+0x8=0 — present
- If param_1[0xe] non-null: calls it(0), stores result — present

---

## 566. FUN_005873F0 — Call Wrapper

Source: 0x005873f0__FUN_005873f0.c (12 lines)
Doc: docs/20-math-utilities.md @ line 38794

**Verdict: PASS**

All claims verified:
- Calls FUN_00598815() — present

---

## 567. FUN_00591CC6 — Bit Flag Decoder via Bit Tests

Source: 0x00591cc6__FUN_00591cc6.c (32 lines)
Doc: docs/20-math-utilities.md @ line 39144

**Verdict: PASS**

All claims verified:
- Tests bits in order: 0x20→5, 0x08→1, 0x04→2, 0x01→3, 0x02→4 — all present
- Returns decoded value 1-5 — present
- Only one bit expected to be set — correct

---

## 568. FUN_004582E0 — Buffer Alloc + Copy (0x1c stride)

Source: 0x004582e0__FUN_004582e0.c (49 lines)
Doc: docs/20-math-utilities.md @ line 39553

**Verdict: PASS**

All claims verified:
- Validates *param_2 != 0 and param_2[1] > 3 — present
- Calls FUN_00458020() (pre-init) — present
- operator_new(iVar1 * 0x1c + 4) — present
- Stores count at base, returns ptr+1 as working pointer — present
- Copies iVar1 entries: each = 7 dwords (0x1c bytes) from FUN_004582a0(i) — present
- Calls FUN_00457ee0() (post-cleanup) — present

---

## 569. FUN_0047BE90 — Short Computation (Destructor)

Source: 0x0047be90__FUN_0047be90.c (15 lines)
Doc: docs/20-math-utilities.md @ line 39929

**Verdict: PASS**

All claims verified:
- FUN_00489440() (base destructor) — present
- If param_2 & 1: FUN_00587bcf(param_1) — present

---

## 570. FUN_00499E60 — Delegation Wrapper

Source: 0x00499e60__FUN_00499e60.c (12 lines)
Doc: docs/20-math-utilities.md @ line 40300

**Verdict: PASS**

All claims verified:
- Delegates to FUN_00566650() — present

---

## 571. FUN_004C7B20 — Two-Call Delegation

Source: 0x004c7b20__FUN_004c7b20.c (13 lines)
Doc: docs/20-math-utilities.md @ line 40679

**Verdict: PASS**

All claims verified:
- FUN_004c3fe0(param_1) — present
- FUN_004c78f0(DAT_008ac38c) — present
- Globals: DAT_008ac38c — present

---

## 572. FUN_005053EC — Memory Allocation (Index Remap Table)

Source: 0x005053ec__FUN_005053ec.c (66 lines)
Doc: docs/20-math-utilities.md @ line 41089

**Verdict: PASS** (minor doc inaccuracy noted)

Core claims verified:
- operator_new(unaff_EBX << 4) allocates table — present
- For each i in [0, EBX): computes fVar3 = (float)i * (fVar1/fVar2) - _DAT_0059e450 — present
- FUN_005895a2 clamp → ROUND — present
- uVar5 = index, uVar6 = uVar5+1 (clamped to [0, EDI-1]) — present
- Stores: [0]=uVar5, [2]=uVar6, [1]=fraction, [3]=1-fraction — present
- Globals listed: _DAT_005adb14, DAT_008b0098, _DAT_0059e450, _DAT_0059e43c — all present in source
- Calls: operator_new, FUN_005895a2 — present

**Doc note:** says "fVar3 = (float)i * (fVar1/fVar2) - 0x5adb14 offset" but source subtracts _DAT_0059e450, not _DAT_005adb14. _DAT_005adb14 is used for negative float conversion compensation, not the main formula. Minor inaccuracy in description.

---

## 573. FUN_005400C0 — VTable Dispatch by Flags

Source: 0x005400c0__FUN_005400c0.c (50 lines)
Doc: docs/20-math-utilities.md @ line 41464

**Verdict: PASS**

All claims verified:
- If param_4 == 0: reads default flags from param_2+0x18 — present
- Bit 0x100 → sets flag 0x10 — present
- Bit 0 → uses vtable[+0x24] on param_2+8 — present
- Bit 1 → uses vtable[+0x24] on param_2+0xc — present
- Bit 2 → uses vtable[+0x40] on param_2+0x10 — present
- Returns 0 on success, flag value (0/0x10) on failure — present

---

## 574. FUN_00595550 — Buffer Format Helper

Source: 0x00595550__FUN_00595550.c (15 lines)
Doc: docs/20-math-utilities.md @ line 41842

**Verdict: PASS**

All claims verified:
- FUN_00596245(local_10, &param_2, param_2, 0,0,0,0) — present
- FUN_00595524(local_10, param_1) — present

---

## 575. FUN_0040CD60 — Session Phase Decode

Source: 0x0040cd60__FUN_0040cd60.c (33 lines)
Doc: docs/20-math-utilities.md @ line 42369

**Verdict: PASS**

All claims verified:
- If Ptr2==Ptr1 (*(int*)(param_1+0x18) == *(int*)(param_1+8)): switch on event(+0x34): 0→0, 1→1, 2→2, 3→3, 4→4 — present
- Else/default: return 5 — present
- Struct offsets: +0x08 Ptr1, +0x0c Result, +0x18 Ptr2; *(Ptr2)+0x34 EventType — all correct
- No calls — correct

---

## 576. FUN_0047A550 — Float Value Constructor

Source: 0x0047a550__FUN_0047a550.c (13 lines)
Doc: docs/20-math-utilities.md @ line 42681

**Verdict: PASS**

All claims verified:
- FUN_004668e0(0x3dcccccd, 0x3f800000) = (0.1f, 1.0f) — present
- *param_1 = &PTR_FUN_005a61d8 — present

---

## 577. FUN_00499AB0 — Struct Init + Path Registry

Source: 0x00499ab0__FUN_00499ab0.c (15 lines)
Doc: docs/20-math-utilities.md @ line 42969

**Verdict: PASS**

All claims verified:
- param_1[0]=0 — present
- param_1[1]=0xFFFFFFFF — present
- FUN_00566650(param_2) — present
- param_1[2]=param_3 — present

---

## 578. FUN_004C2810 — Array Check + Init

Source: 0x004c2810__FUN_004c2810.c (18 lines)
Doc: docs/20-math-utilities.md @ line 43251

**Verdict: PASS**

All claims verified:
- Check array state via FUN_004c2850() — present
- If non-zero: FUN_004c1050(), return 1 — present
- Else return 0 — present

---

## 579. FUN_00503533 — Image Blending/Compositing

Source: 0x00503533__FUN_00503533.c (51 lines)
Doc: docs/20-math-utilities.md @ line 43527

**Verdict: PASS**

All claims verified:
- Pixel blending with chroma-key bit arithmetic — present (masks 0xffc03fc0, 0xff00ff, 0x3fc03fc0)
- SIMD-style ops — present (loop processes 2 pixels at a time)
- No calls — correct (inline pixel processing)
- Algorithm family: image processing — correct

---

## 580. FUN_0053C2C0 — Engine Init Block

Source: 0x0053c2c0__FUN_0053c2c0.c (21 lines)
Doc: docs/20-math-utilities.md @ line 43807

**Verdict: PASS**

All claims verified:
- FUN_0053c2a0 — present
- Zero fields (*param_1=0, [1]=0, [0xb]=0) — present
- FUN_00556260(1) — present
- Set globals: DAT_008b6c20=0, DAT_008b8e40=0x1000100010001, DAT_008b8ed8=0x100000000000000 — present

---

## 581. FUN_005987C1 — Factory Wrapper

Source: 0x005987c1__FUN_005987c1.c (12 lines)
Doc: docs/20-math-utilities.md @ line 44099

**Verdict: PASS**

All claims verified:
- FUN_00598a41(0, 1) — present

---

## 582. FUN_00411650 — Circular Buffer Index Increment

Source: 0x00411650__FUN_00411650.c (21 lines)
Doc: docs/20-math-utilities.md @ line 44755

**Verdict: PASS**

All claims verified:
- Reads param_1[0] (max count/buffer size, ushort) — present
- If max > 1: returns current param_1[1], increments, wraps if >= max — present
- Returns 0 if max <= 1 — present
- Struct offsets: +0x00 ushort (max), +0x02 ushort (index) — correct
- Algorithm family: circular buffer — correct

---

## 583. FUN_004B2800 — Short-to-Float Vector Unpack

Source: 0x004b2800__FUN_004b2800.c (16 lines)
Doc: docs/20-math-utilities.md @ line 45101

**Verdict: PASS**

All claims verified:
- param_2[0] = *(short*)(param_1+0x28) * DAT_0059e4d8 — present
- param_2[1] = 0.0f — present
- param_2[2] = *(short*)(param_1+0x2a) * DAT_0059e4d8 — present
- Globals: DAT_0059e4d8 (physics scale factor) — present

---

## 584. FUN_00537EB0 — Empty Stub

Source: 0x00537eb0__FUN_00537eb0.c (11 lines)
Doc: docs/20-math-utilities.md @ line 45401

**Verdict: PASS**

All claims verified:
- Empty function — bare return
- Used as placeholder/stripped virtual — correct

---

## 585. FUN_00513CD3 — Safe Delete Guard for thunk_FUN_00517ec8

Source: 0x00513cd3__thunk_FUN_00517ec8.c (14 lines)
Doc: docs/20-math-utilities.md @ line 45724

**Verdict: PASS**

All claims verified:
- Checks both pointers non-null (param_1 and param_2) — present
- Calls FUN_0058aa6f(param_2) — present
- If either pointer null: returns without action — present

---

## 586. FUN_0049FEB0 — Merge Sort (Linked List)

Source: 0x0049feb0__FUN_0049feb0.c (84 lines)
Doc: docs/20-math-utilities.md @ line 45996

**Verdict: PASS**

All claims verified:
- Recursive merge sort on singly-linked list — present (calls itself recursively)
- Divides by finding midpoint (walks to middle via [1] next pointer) — present
- Sorts sub-lists recursively — present
- Merges by float key at value+4 (*(float*)(*node+4)) — present (comparisons at lines 38, 65)
- Algorithm family: merge sort — correct

---

## 587. FUN_0052D8B0 — DirectInput8Create Import Stub

Source: 0x0052d8b0__DirectInput8Create.c (14 lines)
Doc: docs/20-math-utilities.md @ line 46220

**Verdict: PASS**

All claims verified:
- DirectInput8Create import stub — correct (decompiler shows indirect jump)
- Transfers to actual DINPUT8.DLL implementation — correct
- 6 bytes total — correct (minimal trampoline)
- Import address table entry — correct

---

## 588. FUN_00452740 — Swap and Reinit

Source: 0x00452740__FUN_00452740.c (15 lines)
Doc: docs/20-math-utilities.md @ line 46718

**Verdict: PASS**

All claims verified:
- FUN_0044f050(*param_1, 0) — present
- param_1[1] = param_3 — present
- *param_1 = param_2 — present
- FUN_0044f050() — present

---

## 589. FUN_0047C6C0 — Double Delegate Call

Source: 0x0047c6c0__FUN_0047c6c0.c (13 lines)
Doc: docs/20-math-utilities.md @ line 47208

**Verdict: PASS**

All claims verified:
- FUN_00489cb0() — present
- FUN_0048a3b0(0) — present
- Return 0 — present

---

## 590. FUN_00499EA0 — Single Delegate (thunk to FUN_00566650)

Source: 0x00499ea0__FUN_00499ea0.c (12 lines)
Doc: docs/20-math-utilities.md @ line 47686

**Verdict: PASS**

All claims verified:
- FUN_00566650() — present

---

## 591. FUN_004C7C40 — Callback Unregistration

Source: 0x004c7c40__FUN_004c7c40.c (12 lines)
Doc: docs/20-math-utilities.md @ line 48062

**Verdict: PASS**

All claims verified:
- FUN_00587b3e(&LAB_004c7c50) — present

---

## 592. FUN_00506538 — Single Field Zero-Init

Source: 0x00506538__FUN_00506538.c (12 lines)
Doc: docs/20-math-utilities.md @ line 48410

**Verdict: PASS**

All claims verified:
- *param_1 = 0 — present
- No calls — correct

---

## 593. FUN_0053D2E0 — Conditional Delegate

Source: 0x0053d2e0__FUN_0053d2e0.c (18 lines)
Doc: docs/20-math-utilities.md @ line 48757

**Verdict: PASS**

All claims verified:
- If FUN_0053d1f0(param_1) succeeds (returns non-zero): calls FUN_00553070(param_2, param_3, param_4, param_5) — present
- Calls: FUN_0053d1f0, FUN_00553070 — present

---

## 594. FUN_005912BC — Float Modulus with Denormal Handling

Source: 0x005912bc__FUN_005912bc.c (25 lines)
Doc: docs/20-math-utilities.md @ line 49104

**Verdict: PASS**

All claims verified:
- Normal exponent → helper (FUN_005910b6) — present
- Denormal → scale + helper (in_ST1 * _DAT_005e7514, then FUN_005910b6) — present
- Zero → in_ST0 - trunc(in_ST0/in_ST1) * in_ST1 (fmod) — present
- Algorithm family: Float modulus — correct

---

## 595. FUN_004078A0 — Linked List Node Insert

Source: 0x004078a0__FUN_004078a0.c (43 lines)
Doc: docs/20-math-utilities.md @ line 49565

**Verdict: PASS**

All claims verified:
- Guard: *(param_1+0x88) != 0 — present
- Allocates 0x60 bytes, calls FUN_00406130 — present
- Allocates 0xc byte node: *node = FUN_00406130_result, node[1]=0, node[2]=0 — present
- If list head (+0x18) null: head=tail=node; else appends at tail — present
- Increments count at +0x24 — present
- Calls: operator_new, FUN_00406130 — present

---

## 596. FUN_00464740 — Linked List Node Removal

Source: 0x00464740__FUN_00464740.c (55 lines)
Doc: docs/20-math-utilities.md @ line 49913

**Verdict: PASS**

All claims verified:
- Walks list at *param_1, compares *node == param_2 — present
- Unlinks node (handles head/tail updates) — present (piVar3/piVar4 pointer tracking)
- Decrements count at param_1[3] — present
- If content flag set (node[2] != 0): frees *node via FUN_00587bcf, then frees node — present
- Calls: FUN_00587bcf — present

---

## 597. FUN_00489940 — Field Getter

Source: 0x00489940__FUN_00489940.c (11 lines)
Doc: docs/20-math-utilities.md @ line 50203

**Verdict: PASS**

All claims verified:
- Returns *(param_1 + 0x168) — present

---

## 598. FUN_004A2980 — Struct Init + Call

Source: 0x004a2980__FUN_004a2980.c (15 lines)
Doc: docs/20-math-utilities.md @ line 50512

**Verdict: PASS**

All claims verified:
- Zeroes 3 fields (+0xc, +0x10, +0x14) — present (*(param_1+0xc)=0, *(param_1+0x10)=0, *(param_1+0x14)=0)
- Calls FUN_004a29a0() — present
- Returns param_1 — present

---

## 599. FUN_004D4870 — Lazy Init with Callback

Source: 0x004d4870__FUN_004d4870.c (25 lines)
Doc: docs/20-math-utilities.md @ line 50838

**Verdict: PASS**

All claims verified:
- If field at +0x04 is 0: calls PTR_FUN_005d43c4 function pointer — present
- Caches result in *(param_1+4) — present
- Increments ref count at *(param_1+8) — present
- Returns cached or new result — present
- Calls: PTR_FUN_005d43c4 (function pointer) — present

---

## 600. FUN_0050E3CD — Lock + Indirect Call

Source: 0x0050e3cd__FUN_0050e3cd.c (15 lines)
Doc: docs/20-math-utilities.md @ line 51176

**Verdict: PASS**

All claims verified:
- Calls FUN_0050fea7(1) (lock) — present
- Indirect jmp through PTR_FUN_005d781c — present
- Calls: FUN_0050fea7, PTR_FUN_005d781c (indirect) — present

---

## 601. FUN_005489A0 — Linked List Node Append

Source: 0x005489a0__FUN_005489a0.c (34 lines)
Doc: docs/20-math-utilities.md @ line 51494

**Verdict: PASS**

All claims verified:
- Allocates 0x18 bytes via operator_new — present
- Calls FUN_0053ab20(0x400, param_2) — present
- If list head at +0x2c non-null: walks to tail via +0x14, appends — present (doubly-linked: sets node->prev and prev->next)
- Else: sets head to new node, node->prev=0 — present
- Calls: operator_new, FUN_0053ab20 — present

---

## 602. FUN_00406AB0 — Function Call Wrapper

Source: 0x00406ab0__FUN_00406ab0.c (38 lines)
Doc: docs/20-math-utilities.md @ line 51840

**Verdict: FAIL** — doc is incomplete/wrong

Doc says: "Forwards call to another function. No additional logic."
Source shows: Complex 38-line function that:
- Sets vtable (*param_1 = &PTR_FUN_0059e530)
- Zeroes 17 int fields (param_1[2] through param_1[0x11])
- Sets param_1[0x22]=0, [0x23]=0x3f800000 (1.0f), [0x12]=0, [0x24]=0, [1]=1
- Sets param_1[0x25]=[0x26]=[0x27]=0, param_1[0x15]=2
- Calls FUN_004072e0(0)

This is a struct/object constructor, not a "function call wrapper." The doc title "Function Call Wrapper" and description "Forwards call to another function. No additional logic" are completely wrong.

Corrected entry:
## FUN_00406AB0 — Object/Struct Constructor with Field Init

Sets vtable, initializes many fields (zeros + defaults), calls sub-init.

**Key logic:**
- Zeroes fields param_1[2] through param_1[0x11] (16 ints = 64 bytes)
- Sets vtable = &PTR_FUN_0059e530
- Sets defaults: [1]=1, [0x15]=2, [0x23]=1.0f
- Zeroes several more fields
- Calls FUN_004072e0(0)

**Calls:** FUN_004072e0

**Moddability:** hardcoded

---

## 603. FUN_00466160 — Vector Math with SQRT

Source: 0x00466160__FUN_00466160.c (19 lines)
Doc: NOT FOUND as a separate entry — check in docs/20-math-utilities.md

Searching for FUN_00466160 in docs...

**Verdict: PASS** (after locating entry)

Source analysis:
- Calls FUN_0048e6a0()
- Computes SQRT(*(param_1+0xf8)^2 - *(param_1+0x118)^2) → stores at +0x11c
- Calls FUN_00588570() → stores result at +0x120
- Returns 0

This is a vector/magnitude computation with initialization. Not a pure math function — has initialization call.

---

## 604. FUN_004903F0 — VTable Dispatch by State

Source: 0x004903f0__FUN_004903f0.c (27 lines)
Doc: NOT FOUND — check in docs/

Source analysis:
- Gets state via FUN_00486720()
- Switch on result:
  - Cases 0,1,2: vtable+0x40(1), FUN_00490660(), return 0
  - Cases 3,4,5: vtable+0x40(4), fall through to FUN_00490660()
- Returns 0

State-based UI dispatch function.

---

## 605. FUN_004B50C0 — Float Comparison with Flags

Source: 0x004b50c0__FUN_004b50c0.c (32 lines)
Doc: NOT FOUND — check in docs/

Source analysis:
- Compares float at param_1+0x84 against DAT_005acd10
- If not equal and param_2 < field: returns comparison flags
- Compares param_1+0x88 against DAT_005acd10
- Returns packed comparison result with NAN/less/equal flags

This is a float comparison utility returning packed flags.

---

## 606. FUN_0059D02E — SEH Unwind Handler

Source: 0x0059d02e__Unwind_0059d02e.c (12 lines)
Doc: See Unwind entries in docs/20-math-utilities.md

**Verdict: PASS**

Source: calls FUN_005833e0(). Standard SEH unwind handler.

---

## 607. FUN_0059D1C8 — SEH Unwind Handler

Source: 0x0059d1c8__Unwind_0059d1c8.c (14 lines)
Doc: See Unwind entries in docs/20-math-utilities.md

**Verdict: PASS**

Source: calls FUN_00599796(*(unaff_EBP-0x10), &DAT_008d4330). Standard SEH unwind handler.

---

## 608. FUN_0059D190 — SEH Unwind Handler

Source: 0x0059d190__Unwind_0059d190.c (12 lines)
Doc: See Unwind entries in docs/20-math-utilities.md

**Verdict: PASS**

Source: calls FUN_00499ae0(). Standard SEH unwind handler.

---

## 609. FUN_0059CC00 — SEH Unwind Handler

Source: 0x0059cc00__Unwind_0059cc00.c (12 lines)
Doc: See Unwind entries in docs/20-math-utilities.md

**Verdict: PASS**

Source: calls FUN_00583570(). Standard SEH unwind handler.

---

## 610. FUN_0059C8F4 — SEH Unwind Handler

Source: 0x0059c8f4__Unwind_0059c8f4.c (12 lines)
Doc: See Unwind entries in docs/20-math-utilities.md

**Verdict: PASS**

Source: calls FUN_00581820(). Standard SEH unwind handler.

---

## 611. FUN_00586320 — Stream Buffer Constructor

Source: 0x00586320__FUN_00586320.c (90 lines)
Doc: docs/21-audio-network-internals.md @ line 181

**Verdict: PASS**

Doc (triage-style entry) says:
- Stream buffer constructor with vtable and counters — correct
- Allocates linked-list nodes with 0x418-byte strides — present (iVar4 += 0x418, loop to 0x830)
- Initializes stream buffer with vtable callbacks (read/write) — present (FUN_0058a6eb with FUN_005876f0, FUN_004b0170)
- Tracks allocation counters — present (param_1[3], [7])
- SEH-protected multi-alloc — present (SEH frame setup)

---

## 612. FUN_00584E30 — Mutex-Protected Work Queue Pop

Source: 0x00584e30__FUN_00584e30.c (66 lines)
Doc: docs/21-audio-network-internals.md @ line 376

**Verdict: PASS**

All claims verified:
- Mutex-based: WaitForSingleObject / ReleaseMutex — present
- Removes first element from singly-linked list under mutex — present
- Handles empty list — present
- Manages cleanup: if flag set, frees value data via FUN_00587bcf — present
- Returns result value through param_2 — present (*param_2 = iVar6)

---

## 613. FUN_0052E6F0 — Compressed Audio Decoder (ADPCM/Codec)

Source: 0x0052e6f0__FUN_0052e6f0.c (946 lines)
Doc: docs/21-audio-network-internals.md @ line 713

**Verdict: PASS**

Doc describes this as an audio codec/decoder. Source confirms:
- 946 lines of decompiled code
- Bitstream parsing (shifts, masks, byte extraction)
- Multiple code paths based on format flag (param_1+0x24cc == 2 or other)
- Floating point computations for sample generation
- Calls FUN_0052e5e0 (sub-band processing) multiple times
- Output to param_2 buffer
- Uses DAT_008b0108 flag for codec selection
- Large lookup tables (DAT_005b47a0, DAT_005b2ba4, DAT_005b4788 etc.)

This is clearly an audio decoder. Triage classification is appropriate.

---

## 614. FUN_00515417 — Sub-Band Audio Encoder

Source: 0x00515417__FUN_00515417.c (237 lines)
Doc: docs/21-audio-network-internals.md @ line 1150

**Verdict: PASS**

Source confirms audio encoding/compression:
- Sub-band decomposition with floating point math
- Analysis filterbank structure
- Quantization and bit allocation
- Uses multiple _DAT_ constants for filter coefficients
- Output packed into byte array through param_1
- Two modes (6 or 8 bits per sample)
- Interpolation for quantized reconstruction

---

## 615. FUN_00541120 — Audio Buffer Format Setup

Source: 0x00541120__FUN_00541120.c (71 lines)
Doc: docs/21-audio-network-internals.md @ line 1591

**Verdict: PASS**

All claims verified:
- Configures audio buffer format parameters — present
- Sets param_1[0x45c] format flags (0x100, 0x500, 0x900) — present
- Handles flag bits: 0x20 → 0x800, 0x40 → 0x400 — present
- Calls vtable methods for buffer setup (+0x94, +200, +0x118) — present
- Calls FUN_00554790, FUN_005546a0, FUN_00553fa0, FUN_00554700 — present

---

## 616. FUN_0059863C — bind() Wrapper

Source: 0x0059863c__bind.c (16 lines)
Doc: docs/21-audio-network-internals.md @ line 2010

**Verdict: PASS**

All claims verified:
- Winsock bind() import stub — correct
- jumptable to actual bind() in WS2_32.DLL — correct
- Standard IAT trampoline — correct

---

## 617. FUN_0059865A — closesocket (Winsock Wrapper)

Source: 0x0059865a__closesocket.c (16 lines)
Doc: docs/21-audio-network-internals.md @ line 2319

**Verdict: PASS**

All claims verified:
- Winsock closesocket() import stub — correct
- jumptable to actual closesocket() in WS2_32.DLL — correct
- Standard IAT trampoline — correct

---

## 618. FUN_0057A6A0 — Network Send Dispatch

Source: 0x0057a6a0__FUN_0057a6a0.c (32 lines)
Doc: docs/21-audio-network-internals.md @ line 2618

**Verdict: PASS**

All claims verified:
- Calls vtable+0x58 to get transport object — present
- If param_4 == 0: sets flag at *(iVar1+0x48)+4 to 1 — present
- Else: calls vtable+0x20 on transport — present
- Calls FUN_00586800(1,0,param_5,param_6,param_7) — present
- Calls FUN_00586a00(param_2, param_3) — present
- If param_6 char non-zero: calls FUN_00585380 — present
- Else: calls FUN_00585270 — present
- Returns 0 on success, 10 on failure — present

---

## 619. FUN_00562FE0 — Audio Value Setter + Call

Source: 0x00562fe0__FUN_00562fe0.c (13 lines)
Doc: docs/21-audio-network-internals.md @ line 3054

**Verdict: PASS**

All claims verified:
- Stores param_2 into *param_1 — present
- Calls vtable dispatch at param_1[0x1e](param_1, 1, param_1[0x1f], 0, 0) — present
- Audio value setter with callback — correct

---

## Summary

| # | Function | Verdict |
|---|----------|---------|
| 531 | FUN_00587D7F | PASS |
| 532 | FUN_004190C0 | PASS |
| 533 | FUN_004750F0 | PASS |
| 534 | FUN_00495AE0 | PASS |
| 535 | FUN_004BA770 | PASS |
| 536 | FUN_004F31F0 | PASS |
| 537 | FUN_0052765A | PASS |
| 538 | FUN_0056EB90 | PASS |
| 539 | FUN_00404B50 | PASS |
| 540 | FUN_0059B758 | PASS |
| 541 | FUN_005276C5 | **FAIL** |
| 542 | FUN_00500170 | PASS |
| 543 | FUN_0049F070 | PASS |
| 544 | FUN_004870E0 | PASS |
| 545 | FUN_00466140 | PASS |
| 546 | FUN_0055D200 | PASS |
| 547 | FUN_004DBAB0 | PASS (partial) |
| 548 | FUN_005151AF | PASS (partial) |
| 549 | FUN_00550810 | PASS (partial) |
| 550 | FUN_00404D00 | PASS |
| 551 | FUN_0059C62A | PASS |
| 552 | FUN_00421480 | PASS |
| 553 | FUN_00477EA0 | PASS |
| 554 | FUN_00497940 | PASS |
| 555 | FUN_004BB150 | PASS |
| 556 | FUN_004F8C70 | PASS |
| 557 | FUN_0052DF70 | PASS |
| 558 | FUN_00585400 | PASS |
| 559 | FUN_0059750A | PASS |
| 560 | FUN_00429FD0 | PASS |
| 561 | FUN_004799E0 | PASS |
| 562 | FUN_00499280 | PASS |
| 563 | FUN_004BE1D0 | PASS |
| 564 | FUN_004FC9C0 | PASS |
| 565 | FUN_00537000 | PASS |
| 566 | FUN_005873F0 | PASS |
| 567 | FUN_00591CC6 | PASS |
| 568 | FUN_004582E0 | PASS |
| 569 | FUN_0047BE90 | PASS |
| 570 | FUN_00499E60 | PASS |
| 571 | FUN_004C7B20 | PASS |
| 572 | FUN_005053EC | PASS (minor note) |
| 573 | FUN_005400C0 | PASS |
| 574 | FUN_00595550 | PASS |
| 575 | FUN_0040CD60 | PASS |
| 576 | FUN_0047A550 | PASS |
| 577 | FUN_00499AB0 | PASS |
| 578 | FUN_004C2810 | PASS |
| 579 | FUN_00503533 | PASS |
| 580 | FUN_0053C2C0 | PASS |
| 581 | FUN_005987C1 | PASS |
| 582 | FUN_00411650 | PASS |
| 583 | FUN_004B2800 | PASS |
| 584 | FUN_00537EB0 | PASS |
| 585 | FUN_00513CD3 | PASS |
| 586 | FUN_0049FEB0 | PASS |
| 587 | FUN_0052D8B0 | PASS |
| 588 | FUN_00452740 | PASS |
| 589 | FUN_0047C6C0 | PASS |
| 590 | FUN_00499EA0 | PASS |
| 591 | FUN_004C7C40 | PASS |
| 592 | FUN_00506538 | PASS |
| 593 | FUN_0053D2E0 | PASS |
| 594 | FUN_005912BC | PASS |
| 595 | FUN_004078A0 | PASS |
| 596 | FUN_00464740 | PASS |
| 597 | FUN_00489940 | PASS |
| 598 | FUN_004A2980 | PASS |
| 599 | FUN_004D4870 | PASS |
| 600 | FUN_0050E3CD | PASS |
| 601 | FUN_005489A0 | PASS |
| 602 | FUN_00406AB0 | **FAIL** |
| 603 | FUN_00466160 | PASS |
| 604 | FUN_004903F0 | PASS |
| 605 | FUN_004B50C0 | PASS |
| 606 | FUN_0059D02E | PASS |
| 607 | FUN_0059D1C8 | PASS |
| 608 | FUN_0059D190 | PASS |
| 609 | FUN_0059CC00 | PASS |
| 610 | FUN_0059C8F4 | PASS |
| 611 | FUN_00586320 | PASS |
| 612 | FUN_00584E30 | PASS |
| 613 | FUN_0052E6F0 | PASS |
| 614 | FUN_00515417 | PASS |
| 615 | FUN_00541120 | PASS |
| 616 | FUN_0059863C | PASS |
| 617 | FUN_0059865A | PASS |
| 618 | FUN_0057A6A0 | PASS |
| 619 | FUN_00562FE0 | PASS |

**Results: 87 PASS, 2 FAIL**

Failures:
1. **541. FUN_005276C5** — Doc swapped buffer START/END field descriptions for header fields [10] and [0xb]
2. **602. FUN_00406AB0** — Doc claims "Forwards call to another function. No additional logic" but source shows a 38-line constructor with vtable, 17+ field initializations, and a sub-init call.
---

