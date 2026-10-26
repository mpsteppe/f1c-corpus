# Cross-Validation Audit: worker_Q_math1

Auditing 71 function entries from docs/20-math-utilities.md against .c sources.

---

## FUN_005934E1 — PASS

Exception dispatcher with SEH. Verified:
- Signature: `void FUN_005934e1(int *param_1, int param_2, undefined4 param_3, undefined4 param_4, int param_5, char param_6, undefined4 param_7, undefined4 param_8)` — matches source
- Magic number check: `*param_1 == -0x1f928c9d` — matches source line 25
- Magic number 3 and 0x19930520 at param_1[4] and param_1[5] — source lines 26, 46
- Handler iteration via FUN_0058a55a — source line 47
- Dispatch to FUN_00593839 — source line 64
- Falls to FUN_00593694 or FUN_00593c9c based on param_6 flag — source lines 80-84
- Size: 435 bytes — matches source header

---

## FUN_00582650 — PASS

Pool destructor. Verified:
- Signature: `void __fastcall FUN_00582650(undefined4 *param_1)` — matches source
- Virtual method call(1) on busy nodes — source line 23: `(*(code *)**(undefined4 **)*piVar3)(1)`
- Virtual method call(3) on free nodes — source line 38: `(*(code *)**(undefined4 **)*piVar2)(3)`
- Cleanup via FUN_00587bcf — source lines 25, 40, 42
- Size: 207 bytes — matches source header

---

## FUN_00586AA0 — PASS

Triage-only entry: bitmap blit/copy. Minimal claims — source shows bit operations on color planes, bitmask per channel, calls FUN_00585e80, FUN_00586f70, FUN_00586f40, FUN_00586fa0, FUN_00587500. Consistent with description. No detailed claims to fail.

---

## FUN_00582DC0 — FAIL

**Misclassification:** Doc says "Thread synchronization — create/signal/close event kernel object". Source shows it is a **linked list destructor**:
- Iterates linked list at param_1[4], calls FUN_00587bcf on each node — lines 22-29
- Iterates linked list at *param_1, calls FUN_0058a5f7 and FUN_00587bcf on each node — lines 36-48
- Zeros param_1[4..7] and *param_1..[3] — lines 31-34, 50-53
- Standard SEH pattern with ExceptionList — lines 18-19, 54

**Error tags:** `[MISCLASSIFICATION]` — function is a pool/collection destructor, not thread synchronization.

---

## FUN_0059807B — PASS

Triage-code-block entry. Source shows locale-aware string comparison (CompareStringW/A, GetCPInfo, DBCS handling). No detailed claims beyond the function signature and code block (minimal entry). Consistent.

---

## FUN_00552BA0 — PASS

Doc entry is decompiled code block only. No analysis claims to verify beyond the code itself. Source matches the doc's code block. PASS.

---

## FUN_0057CA10 — PASS

Doc entry is decompiled code block only. Source shows string copy (_strncpy) and comparison (FUN_005897ca). No analysis claims to verify beyond code. PASS.

---

## FUN_005572B0 — PASS

Doc entry is decompiled code block only. Source zeroes fields in 4 loops at offsets +0x1b4, +0x1c4, +0x1bc, +0x1cc with stride 0x84*4 = 0x210. Consistent. PASS.

---

## FUN_00550AD0 — PASS

Full entry with detailed claims. Verified:
- DAT_008b8f30 — source line 38: `DAT_008b8f30 = operator_new(...)`
- DAT_008b8f34 — source line 39: `DAT_008b8f34 = operator_new(uVar11)`
- FUN_0058ace6 (file size) — source lines 27, 29
- FUN_00587f64 (file seek) — source lines 28, 31
- FUN_0058803f (file read) — source lines 40, 56
- FUN_0059b260 (decompress?) — source line 46
- FUN_0054a5c0 (stream read) — source lines 63-67, 72, 94-97
- Two modes from param_1 flags (bit 0 = indexed, bit 1 = non-indexed) — source lines 70-71
- Stride 0x2c per vertex — source line 74: `operator_new(uVar11 * 0x2c + 4)`
- FUN_00589901 — source line 69
- _DAT_0059e43c scaling — source line 68: `*pfVar1 = _DAT_0059e43c / *pfVar1`
- FUN_00587bcf — source lines 42-43, 58
- All calls: FUN_0058ace6, FUN_00587f64, FUN_0058803f, FUN_0059b260, FUN_0054a5c0, FUN_00589901, FUN_00587bcf, FUN_005507e0 — verified in source

All claims verified. PASS.

---

## FUN_00598CDC — PASS

Full entry. Verified:
- MSVC CRT uflow — source has Library Function comment: `Visual Studio 2003 Release`
- Virtual call at vtable+0x10 — source line 19: `(**(code **)(*(int *)this + 0x10))()`
- Returns -1 on EOF — source line 20-21: `if (iVar1 == -1) { return -1; }`
- _Gninc call to advance get pointer — source line 23: `_Gninc(this)`
- Returns byte value — source line 24: `return (uint)*pbVar2`

All claims verified. PASS.

---

## FUN_0049A5A0 — PASS

Minimal entry. Verified:
- Checks param_1+0xc non-null: frees — source line 8-9
- Checks param_1+4 non-null: frees — source line 11-12
- Both use FUN_00587bcf — confirmed
- Size: 37 bytes — matches

---

## FUN_00540DA0 — PASS

Minimal entry. Verified:
- Check param_1 != 0 — source line 8
- param_2 & 4: calls FUN_00540f90(param_1+0x1c), zeros +0x20 — source lines 9-11
- param_2 & 8: calls FUN_005410f0(param_1+0x24), zeros +0x28 — source lines 13-15
- Size: 67 bytes — matches

---

## FUN_005930E8 — PASS

Full entry. Verified:
- GetModuleHandleA(NULL) — source line 12
- Checks DOS signature 0x5A4D ("MZ") — source line 13: `pHVar2->unused == 0x5a4d`
- Reads PE signature offset from DOS header e_lfanew (offset 0x3C) — source line 13: `pHVar2[0xf].unused`
- Extracts 2 bytes from PE header — source lines 14-15
- Stores result in *param_1 — source lines 14-15
- Size: 45 bytes — matches

---

## FUN_004630D0 — PASS

Full entry. Verified:
- Opens session via FUN_0057a880() — source line 14
- Calls FUN_0057a8e0() to check readiness — source line 15
- Calls FUN_0057a230(param_1, &local_4) — source line 18
- Checks local_4 == 0x80 — source line 19
- Returns 1 if 0x80 — source line 20
- Closes via FUN_0057a8b0 — source line 23
- All calls verified: FUN_0057a880, FUN_0057a8e0, FUN_0057a230, FUN_0057a8b0

---

## FUN_0059C428 — PASS

Full entry. Verified:
- MSVC CRT unwind handler — confirmed
- Reads pointer from stack EBP-0x10 — source line 10: `FUN_00587bcf(*(undefined4 *)(unaff_EBP + -0x10))`
- Calls FUN_00587bcf (free wrapper) — confirmed
- Size: 10 bytes — matches

---

## FUN_00499F00 — PASS

Full entry. Verified:
- Calls FUN_0049adb0() — source line 12
- If count > 2: reads channel 0 values — source lines 13-17
- Reads channel 1 values — source lines 19-22
- Stores int16 values through pointer params — source lines 16-17, 21-22
- Verified via FUN_0049aec0 with channel index 0, 1
- Signature matches source

---

## FUN_004C7DD0 — PASS

Minimal entry. Verified:
- Sets param_1+4 = 0 — source line 8
- Size: 8 bytes — matches

---

## FUN_0050D84A — PASS

Minimal entry. Verified:
- Calls FUN_0050fea7(1) — source line 10
- Indirect call via DAT_005d7860 — source line 13: `(*_DAT_005d7860)()`
- Size: 13 bytes — matches

---

## FUN_00548A30 — PASS

Full entry. Verified:
- srand(param_1 % 0xa55a) — source line 14
- Generates 4 chars — source lines 18, 31 (loop 4 times)
- Each char: (rand() & 0xff) % 0x4e + 0x30 — source line 20
- Clamped to 0x30-0x7e — source lines 22-27
- Null-terminates — source line 32

---

## FUN_0059D2BF — PASS

Minimal entry. Verified:
- Thunk to FUN_00598cc1 — source line 8
- Size: 8 bytes — matches

---

## FUN_0040B630 — PASS

Full entry. Verified:
- Reads count from param_1 + 0x10 — source line 18: `*(int *)(param_1 + 0x10)`
- Array at *(param_1 + 0xc) with stride 0xd0 — source line 21, 29: `iVar2 = iVar2 + 0xd0`
- Reads float at offset +0x8c — source line 21: `*(float *)(*(int *)(param_1 + 0xc) + 0x8c + iVar2)`
- Calls FUN_004579c0(param_2) — source line 22
- Computes absolute difference — source lines 23-24
- local_8 initialized to FLT_MAX (3.4028235e+38) — source line 16
- local_4 initialized to -1 — source line 17
- Outputs best index via *param_3 — source line 32
- Outputs best distance via *param_4 — source line 33

---

## FUN_0046A510 — PASS

Full entry. Verified:
- Calls FUN_0046a530() — source line 8
- If param_2 & 1: calls FUN_00587bcf(param_1) — source lines 9-11
- Returns param_1 — source line 12

---

## FUN_0048FEC0 — PASS

Full entry. Verified:
- Virtual dispatch at +0x40 — source line 8: `(**(code **)(*param_1 + 0x40))(param_1[0x38])`
- Calls FUN_004901a0() — source line 9
- Returns 0 — source line 10
- Signature matches

---

## FUN_004B8C40 — PASS

Full entry. Verified:
- Switch on denormalized float constants (1.4e-45, 2.8e-45, etc.) — source lines 29, 35, 41, 47, 53
- Each case: calls FUN_004b8790() — source lines 22, 31, 37, 42, 48
- References _DAT_008afe90 — source lines 23, 38, 43, 49
- References _DAT_005acb58 — source line 43
- References _DAT_005acd64 — source line 49
- Sets mode field at +0xf8c to 4-7 — source lines 28, 33, 39, 45, 50
- Calls FUN_004b86e0 — source lines 27, 32, 38, 43, 49
- Calls FUN_004c8d60/70/a0 — source lines 34, 54, 59, 60

---

## FUN_004F8330 — PASS

Full entry. Verified:
- Computes delta = +0x80 - +0x84 — source line 12
- If delta > DAT_0059e440 — source line 13
- Stores _DAT_0059e43c / delta at +0x88 — source line 14
- Else stores 0 — source line 17
- Both globals verified: DAT_0059e440, _DAT_0059e43c

---

## FUN_005355F0 — PASS

Full entry. Verified:
- Loop 4 times — source line 10-15: `iVar1 = 4`
- Calls FUN_00589898(param_2 & 0xff, param_1) — source line 12
- Shifts param_2 >>= 8 — source line 13
- Size: 39 bytes — matches

---

## FUN_0058BF45 — PASS

Full entry. Verified:
- Sign handling (checks for 0x2d = '-') — source line 19-22
- Date separator DAT_005e6bd8 — source line 33: `*puVar3 = DAT_005e6bd8`
- Padding with '0' via _memset — source line 40: `_memset(puVar3 + 1,0x30,param_2)`
- Calls FUN_0058c0d0 — source lines 24, 32, 39
- If length < 1: writes '0' — source lines 23-26
- If param_4 set and length-1 == param_2: appends '0' — source lines 13-16

---

## FUN_00415060 — PASS

Struct zero-init. Verified:
- Zeros param_1[0] through param_1[0xb] (offsets 0 through 0x2c) — source lines 8-19
- Size: 40 bytes — matches

---

## FUN_0049A9C0 — PASS

Struct field multi-setter. Verified:
- param_1+4 = param_2 — source line 10
- param_1+8 = param_3 — source line 11
- param_1+0xc = param_4 — source line 12
- param_1+0x10 = param_5 — source line 13
- Size: 31 bytes — matches

---

## FUN_00535620 — PASS

Struct reset + status check. Verified:
- Checks param_1 != 0 and inner pointer at param_1+0x1c non-null — source line 10
- Zeros param_1+0x14, +8, +0x18 — source lines 11-13
- Sets *inner_ptr = -(inner_ptr[3]!=0) & 7 — source line 14: `*puVar1 = -(uint)(puVar1[3] != 0) & 7`
- Calls FUN_00537000(0) — source line 15
- Returns 0 on success — source line 16
- Returns 0xfffffffe (-2) on invalid — source line 18

---

## FUN_0055FBC0 — PASS

Global data copy. Verified:
- Copies 40 dwords (0x28 iterations) from DAT_008b8f04 — source lines 11-16
- Source: DAT_008b8f04 — source line 11: `puVar2 = DAT_008b8f04`
- Size: 24 bytes — matches

---

## FUN_00411A50 — PASS

Short computation — multi-range switch/map. Verified:
- Range checks: param_1 < 0 or > 0x218 returns 0 — source line 10
- Special values return 0 or 0xffffffff — source lines 14, 19, 28, 34
- Falls through to FUN_00411650() — source line 37
- Size: 95 bytes — matches

---

## FUN_00471650 — PASS

Constructor: LED/Indicator setup. Verified:
- Calls FUN_00466d60(1) — source line 8
- Sets vtable pointer PTR_FUN_005a0fc0 — source line 9
- Sets multiple fields (position/size/color defaults) — source lines 10-15
- Calls FUN_00486f30, FUN_004670e0 — source lines 16-18
- Returns param_1 — source line 19

---

## FUN_00491CF0 — PASS

LinkedList: Follow +0x1c pointer. Verified:
- Reads from *param_1 + 0x1c — source line 10
- Writes to *param_1 + 0x24 — source line 11
- Returns *puVar1 (first value) — source line 13
- Returns 0 if null — source line 15

---

## FUN_004B4800 — PASS

Bitfield setter. Verified:
- Applies mask to target field in byte array — source lines 15-17
- Uses param_2 * 0xd + 0x35 + param_1 addressing — source lines 15-16
- Sets bit via OR with shifted 1 — source line 17

---

## FUN_004DF0A0 — PASS

Conditional render call. Verified:
- Checks flag at param_1 + 0x18 — source line 27
- If non-zero: calls FUN_004dedb0 — source line 28
- No other operations

---

## FUN_00535660 — PASS

Guarded function call + cleanup. Verified:
- Checks param_1 != 0, param_1+0x1c != 0, param_1+0x24 != 0 — source line 8
- If inner+0x14 != 0: calls FUN_00537ce0() — source lines 9-11
- Calls indirect through +0x24 — source line 12
- Zeroes +0x1c — source line 13
- Returns 0 on success — source line 14
- Returns 0xfffffffe (-2) on invalid — source line 16

---

## FUN_00591E57 — PASS

FPU Status Word Read. Verified:
- Reads in_FPUStatusWord — source line 8-10
- Returns status word as int — source line 10
- Size: 15 bytes — matches

---

## FUN_00479850 — PASS

Float constructor with range setup. Verified:
- Calls FUN_00466980(0xBF800000, 0x3F800000) = (-1.0f, 1.0f) — source line 8
- Sets vtable to PTR_FUN_005a5208 — source line 9
- Returns param_1 — source line 10
- Size: 28 bytes — matches

---

## FUN_004533A0 — PASS

Global state initializer with enum values. Verified:
- Calls FUN_00453370(index, 2) for indices 0-6 — source lines 11-17
- For indices 0x1a-0x21: conditional on DAT_007d1370 == 1 — source lines 19-28
  - If true: value=2, else value=0 — source lines 20-24
- Multiple hardcoded (index, value) pairs — source lines 29-57
- Total ~36 pairs initialized — matches

---

## FUN_00491300 — PASS

Multi-short struct writer. Verified:
- *param_1 = param_2, [1]=param_3, [2]=param_4, [3]=param_5 — source lines 10-13
- Zeroes param_1[6] (dword at offset +0xC) — source line 14: `*(undefined4 *)(param_1 + 6) = 0`
- Size: 47 bytes — matches

---

## FUN_004B3C60 — PASS

Deterministic hash/pseudo-random generator. Verified:
- Calls FUN_0055687b() — source line 16
- LCG: (param_1[0x201] + 2) * 0x35abd — source line 17
- Reads hash table at param_1[(*param_1 & 0xff) + 1] — source line 20
- Increments counter *param_1 — source line 21
- GetTickCount() — source line 22
- __ftol — source line 23
- _rand() — source line 24
- Returns combined value — source line 25

---

## FUN_004DD3A0 — PASS

Two-output passthrough. Verified:
- Calls FUN_004dc600(&param_6, &param_3, param_2, param_3) — source line 9
- If param_4 non-null: *param_4 = param_6 — source lines 10-11
- If param_5 non-null: *param_5 = param_3 — source lines 13-14
- Size: 82 bytes — matches

---

## FUN_005177B6 — PASS

4x4 Matrix multiply (float32). Verified:
- If param_3 == param_1: copies to local_44 temp buffer — source lines 17-49
- Standard row x column multiply with x87 float10 precision — source lines 27-31, 59-63
- No external calls (pure math) — confirmed
- Size: 227 bytes — matches

---

## FUN_0055BFC0 — PASS

Simple field getter. Verified:
- Returns *(param_1 + 4) — source line 8
- Size: 4 bytes — matches

---

## FUN_0059C85C — PASS

SEH unwind handler. Verified:
- Calls FUN_00581ad0() — source line 8
- Size: 14 bytes — matches

---

## FUN_00457B00 — PASS

State-activated position save/restore. Verified:
- If flag at +0x9c == 0 and param_2 == 1:
  - Copies +0x18 to +0x90, +0x1c to +0x94, +0x20 to +0x98 — source lines 9-12
  - Sets flag to 1 — source line 11
- If flag at +0x9c == 1 and param_2 == 0:
  - Calls FUN_00456130(+0x90) — source line 16
  - Resets flag to 0 — source line 17
- Size: 91 bytes — matches

---

## FUN_0047ABB0 — PASS

Return 0 stub. Verified:
- Empty function, returns 0 — source line 8
- Size: 3 bytes — matches

---

## FUN_00499CE0 — PASS

Destructor with multiple conditional frees. Verified:
- Sets *param_1 = PTR_FUN_005acaac — source line 8
- Calls FUN_00499da0(0) and FUN_0049af30 — source lines 9-10
- Frees pointers at indices 4,6,8,10,0xc,0xe,0x10,0x12,0x14,0x16 — source lines 11-40
- Each freed via FUN_00587bcf if non-null — confirmed
- Indices: 4 (+0x10), 6 (+0x18), 8 (+0x20), 10 (+0x28), 0xc (+0x30), 0xe (+0x38), 0x10 (+0x40), 0x12 (+0x48), 0x14 (+0x50), 0x16 (+0x58) — matches doc

---

## FUN_004C81F0 — PASS

Struct init with default. Verified:
- [0..3] = 0 — source lines 8-11
- byte at +4 cleared — source line 12: `*(undefined1 *)(param_1 + 4) = 0`
- [5] = 0 — source line 13
- [6] = 0x42c80000 (100.0f) — source line 14
- Size: 29 bytes — matches

---

## FUN_005160AD — PASS

Memory allocator with chunking. Verified:
- Computes max chunk: 0x3b9ac9f0 / param_3 — source line 14
- If zero: calls error handler — source lines 16-18
- Uses min(uVar1, param_4) as chunk size — source lines 20-22
- Calls FUN_00515f23 — source line 24
- Calls FUN_0051601f — source line 31
- Iterates to fill param_4 entries — source lines 26-37

---

## FUN_0058CC00 — PASS

Memory copy (forward/backward with alignment). Verified:
- If dest < src and src < dest+size: backward copy — source line 11
- Handles misaligned start: copies 1-3 bytes to reach alignment — source lines 46-99
- Main body in 4-byte chunks — source lines 15-22, 53-67
- Trailing 1-3 bytes via switch — source lines 23-31, etc.
- Returns dest pointer — source return param_1
- Size: 664 bytes — matches

---

## FUN_0059CF86 — PASS

SEH unwind (call FUN_00585f30). Verified:
- Calls FUN_00585f30() — source line 8
- Size: 14 bytes — matches

---

## FUN_00421A30 — PASS

Dual dispatch: process + path register. Verified:
- Calls FUN_00421890(param_1) — source line 8
- Calls FUN_00566650(param_1) — source line 9
- Size: 28 bytes — matches

---

## FUN_004782C0 — PASS

State sync with dirty flag. Verified:
- Virtual call on *DAT_007cd8c0+0x1C(0x10) — source line 10
- Compares param_1[0x3a] with *(iVar1 + 0x174) — source line 11
- Updates local copy on mismatch — source line 12
- Calls vtable+0x2C on *param_1 with arg 1 — source line 13
- Returns 0 — source line 14
- Globals: DAT_007cd8c0 confirmed

---

## FUN_00498880 — PASS

Dual field read. Verified:
- *param_2 = *(param_1 + 0x5C) — source line 8
- *param_3 = *(param_1 + 0x60) — source line 9
- Size: 21 bytes — matches

---

## FUN_004BBF20 — PASS

Progress bar increment. Verified:
- DAT_0083ee60 incremented and capped at 0x3ff — source lines 10-11
- DAT_008aae64 incremented by 0x1b0 — source line 12
- Calls FUN_004b33b0(4,0x18,0,...) — source line 14
- References _DAT_008afea0 — source line 14
- All globals confirmed

---

## FUN_004F9230 — PASS

Path dispatch. Verified:
- Calls FUN_004f9200(DAT_005ec48c) — source line 8
- Size: 12 bytes — matches

---

## FUN_00534AC0 — PASS

Callback registration. Verified:
- Calls FUN_00587b3e(&LAB_00534ad0) — source line 8
- Returns 0 — source line 9
- Size: 16 bytes — matches

---

## FUN_00583A80 — PASS

Destructor. Verified:
- Calls FUN_00583ae0() — source line 8
- If param_2 & 1: FUN_00587bcf(param_1) — source lines 9-11
- Returns param_1 — source line 12

---

## FUN_0059067E — PASS

__cintrindisp1 (CRT internal dispatch). Verified:
- Library Function comment: Visual Studio CRT — source lines 5-8
- Calls __trandisp1() — source line 13
- Calls FUN_0059070a() — source line 14
- Size: 61 bytes — matches

---

## FUN_004A0DA0 — PASS

Global flag setter. Verified:
- Sets DAT_007ce25d = 1 — source line 8
- Size: 8 bytes — matches

---

## FUN_0050CBB0 — PASS

Thunk to FUN_0050cba3. Verified:
- Thunk via PTR_FUN_005d77d4 — source line 10
- Size: 6 bytes — matches

---

## FUN_0040C520 — PASS

Linked list node swap (cross-link). Verified:
- *(*(param_1+0x20)+8) = *(param_1+0x1c) — source line 8
- *(*(param_1+0x1c)+8) = *(param_1+0x20) — source line 9
- No other calls — matches
- Size: 19 bytes — matches

---

## FUN_00467720 — PASS

UI object init with linked list cleanup. Verified:
- Calls FUN_00487ed0(0,0) — source line 12
- Zeros [0x3e]..[0x41] — source lines 13-16
- Zeros [0x39]..[0x3c] — source lines 18-21
- Sets vtable PTR_LAB_0059f5b8 — source line 17
- Walks linked list at [0x3e], frees data and nodes — source lines 22-33
- Additional zeroing: [0x3e]..[0x41] again, [0x42], +0x3d, +0xf5 — source lines 34-40

---

## FUN_0048E0D0 — PASS

UI destructor with conditional release. Verified:
- Sets *param_1 = PTR_FUN_005ac3e0 — source line 8
- If param_1[0x38] != 0: calls FUN_00551f80() — source lines 9-10
- If param_1[0x3a] != 0: calls FUN_00587bcf() — source lines 12-13
- Calls FUN_00485eb0() — source line 15
- All calls verified

---

## FUN_004B19D0 — PASS

Field init with defaults. Verified:
- param_1[1]=0 — source line 8
- param_1[2]=-1 — source line 9
- param_1[3]=0 — source line 10
- param_1[4]=-1 — source line 11
- *param_1 = &PTR_LAB_005acc2c — source line 12

---

## FUN_004D89D0 — PASS

Struct init with defaults. Verified:
- param_1[0..2] = -1 — source lines 11-13
- param_1[0x37] = DAT_005acf34 — source line 14
- byte at +0x38 = 1 — source line 15
- param_1[0x39] = 0x3f800000 (1.0f) — source line 16
- param_1[0x3a] = 0x3f800000 (1.0f) — source line 17
- param_1[3] = 0, [0x1d..0x1f] = 0 — source lines 18-21
- Loop: zero param_1[4..0x1c] (25 ints, 0x19 iterations) — source lines 22-26
- param_1[0x36] = 0 — source line 27
- Globals: DAT_005acf34 confirmed

---

## FUN_005123B3 — PASS

Byte swap by pairs. Verified:
- If *(param_1+9) == 0x10 — source line 11
- Loop: swaps param_2[i] with param_2[i+1], advances by 2 — source lines 13-16
- Iteration count: *(param_1+10) * *param_1 — source line 12
- Size: 45 bytes — matches

---

## FUN_0054EAC0 — PASS

Callback registration. Verified:
- Calls FUN_00587b3e(LAB_0054ead0) — source line 8
- Size: 12 bytes — matches

---

## FUN_0059987C — PASS

Locale function call wrapper. Verified:
- Calls FUN_00599c58(0, 1) — source line 8
- Size: 15 bytes — matches

---

# SUMMARY

**Total: 71 functions audited**
- **PASS: 70**
- **FAIL: 1**

**Failed function:**
- **FUN_00582DC0** — `[MISCLASSIFICATION]` Doc says "Thread synchronization — create/signal/close event kernel object". Source shows it is a linked list destructor (pool/collection cleanup pattern with FUN_00587bcf calls).

**Note:** Many entries (especially triage-only code-block entries) had minimal claims that were trivially verified. Full entries with specific globals, struct offsets, and calls were all verified against source code and found accurate.

