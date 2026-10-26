# Cross-Validation Results: worker_F

## FUN_0054A5C0 — PASS
All claims verified: global buffer DAT_008b8f3c read at +param_2, dword-aligned copy of param_3 bytes, advance pointer by param_3. Source matches doc exactly.

## FUN_005894A0 — PASS
Chain verified: calls FUN_0058dd28() then FUN_005894bd(). Doc correct.

## FUN_00453370 — PASS
Thunk to FUN_004530a0. Source matches doc.

## FUN_00479E30 — PASS
Constructor: vtable set (PTR_FUN_005a5e40), calls FUN_004668e0, zeros byte at +0x40. Doc correct.

## FUN_00499670 — PASS
Thunk: calls FUN_00587b3e(&LAB_00499680). Doc correct.

## FUN_004C13C0 — PASS
Season points total calculator verified: FUN_004c1370() count, loop 0..count, FUN_004c1390()/FUN_004c13a0() entries, FUN_004c0a20 buffer lookup, FUN_00566810 validity check, accumulate entry+0x198. Doc correct.

## FUN_004FF3A0 — PASS
3D Hermite spline interpolation verified: 4 control points + param_5 as t, Hermite basis functions with constants _DAT_0059e478, _DAT_0059e7ec, _DAT_0059e46c, _DAT_0059e800, _DAT_0059e450, compute x/y/z output. Doc correct.

## FUN_00548E20 — FAIL
[OFFSET-ERROR] Doc claims "param_1[4] = 0 — field at +0x10" but source writes `*(undefined4 *)(param_1 + 4) = 0` at byte offset +0x04, not +0x10. Also doc omits zero at byte offset +0x08. Rest of entry correct (FUN_0053c2a0 call, 24-dword loop at +0x1c, individual zeroes at +0x7c/+0x80/+0x84/+0x18/+0xe8/+0xec/+0xf0/+0xf4/+0xf8/+0xfc).

## FUN_00554260 — PASS
Enum-to-field-offset setter verified: switch on param_2 (1-6, 0xD, 0xE), int offsets 0,1,2,5,6,7,3,4. Write if *param_1 != param_3. Return 1 on change, 0 otherwise. Doc correct.

## FUN_00405410 — PASS
Multi-stage cleanup: FUN_004054a0(), FUN_004d4860(), thunk_FUN_0052d990(), conditional free at +0x4 via FUN_00587bcf. Doc correct.

## FUN_00462300 — PASS
Single function dispatch to FUN_0057a810(). Doc correct.

## FUN_00498FB0 — PASS
List iteration: walks list at param_1+0x4c, calls vtable+0x74 on each node, advances via FUN_00486320(), calls FUN_00499560() after. Doc correct.

## FUN_004BD9B0 — PASS
Dynamic array append: capacity at +0x18, count at +0x1c, data at +0x20. Realloc (capacity+8)*4 when full, copy, free old via FUN_00587bcf, append, increment count. Doc correct.

## FUN_004FB8F0 — PASS
Callback registration: FUN_00587b3e(&LAB_004fb900). Doc correct.

## FUN_005357C0 — PASS
Argument reorder: FUN_005356a0(param_2, param_3). Doc correct.

## FUN_00586EE0 — PASS
Callback registration: FUN_00587b3e(&LAB_00586ef0). Doc correct.

## FUN_004054A0 — PASS
Conditional cleanup: FUN_00405630(), if +0x0c non-null → free via FUN_00587d02 + zero, if +0x18 non-null → free via FUN_00587bcf, FUN_00405440(). Doc correct.

## FUN_00463750 — PASS
Constant offset accessor: return *param_1 + 0x1b0. Doc correct.

## FUN_00488BC0 — PASS
Simple setter: *(param_1 + 0xe0) = param_2. Doc correct.

## FUN_004A1DA0 — PASS
Flag setter: *(param_1+0x10) = param_2. DAT_007ce2e8 = -(param_2 != 0) & param_1. Doc correct.

## FUN_004D7CC0 — PASS
Three-way enum converter: 0→1, 1→2, 2→0, other→-1 (0xffffffff). Doc correct.

## FUN_00535E10 — PASS
Conditional multi-field reset: guards param_1, +0x1c, +0x20, +0x24. Resets multiple fields, sub-struct via +0x1c, calls FUN_00537e40() and FUN_00536260(). Returns 0 or -2. Doc correct.

## FUN_0059D4AC — PASS
SEH exception handler: reads exception pointer from EBP-0x10, calls exception::~exception(). Doc correct.

## FUN_00406700 — PASS
Mutex lock with timeout: WaitForSingleObject(handle at +0x50, timeout at +0x54), on success (0/0x80) writes param_2 to +0x4c, ReleaseMutex. Returns 1 or 0. Doc correct.

## FUN_0045D4E0 — PASS
String length dispatch: if empty return, if multi-char → FUN_00561e00(), single char → FUN_00561e20(). Doc correct.

## FUN_00486320 — PASS
Struct field accessor: returns *(param_1 + 0x8c). Doc correct.

## FUN_0049D440 — PASS
Format + register: FUN_0049c6d0(buf, 0xF), FUN_00553070(buf, 4, 0, *(*(param_1+0x10)+0x54)). Doc correct.

## FUN_004C8EE0 — PASS
Singleton init: first-call initializes DAT_008ac4dc flag, calls rand(), DAT_008ac4d8=1; subsequent calls increment counter. Doc correct.

## FUN_0050B3B5 — PASS
Render format constructor: FUN_00507496(param_2, 0x20, 2), vtable = PTR_FUN_005add2c. Doc correct.

## FUN_00541500 — PASS
Scene state setup: checks param_1[0x4f6] guard, zeros local array, if param_2==1 sets local[0]=3 and float constant 1e+12, else if param_2==2||4 sets local[0]=1 and sqrt constant. Vtable dispatch. Doc minimal but correct.

## FUN_0059801A — PASS
Bitfield manager: read byte from indexed array at (&DAT_008d4920)[param_1>>5] + 4 + (param_1&0x1f)*0x24, if param_2==0x8000 clear bit 7, if 0x4000 set bit 7, else return -1. Doc correct (get/set bit 7).

## FUN_00414160 — PASS
Global field selector: param_1==0→DAT_005bf8c8, param_1==1→DAT_005bf8d0, default→DAT_005bf8c8. Doc correct.

## FUN_004CE8D0 — PASS
Indexed array access stride 0x6c: returns param_1+0xc+param_2*0x6c if 0<=param_2<*(param_1+8), else 0. Doc correct.

## FUN_00587D7F — PASS
CRT stream getc with lock: FUN_0058c5ac() lock, FUN_0058c43c() read, FUN_0058c203() unlock. Doc correct.

## FUN_004190C0 — PASS
Linked list free: walks list at param_1+0x1a0, if flag byte at node[2] and data at node[0] non-null → free data via FUN_00587bcf, free node, zero head/tail/count/capacity (+0x1a0/+0x1a4/+0x1a8/+0x1ac). Doc correct.

## FUN_004750F0 — PASS
UI object init: FUN_004893c0() base init, param_1[0x5d]=0, param_1[0x5e]=0, byte at +0x5f=0, vtable = PTR_FUN_005a4370. Doc correct.

## FUN_00495AE0 — PASS
Resource unlink: if param_1+0x14 and *(param_1+0x14)+100 valid: unlink node at +0x18, update next/prev, callback FUN_00499050(node[1..4]), zero node fields. Doc correct.

## FUN_004BA770 — PASS
Single call wrapper: FUN_004b8010(). Doc correct.

## FUN_004F31F0 — PASS
6×6 array zero-init: loop 6 times zeroing 6 ints (36 ints total), plus zeroes at +0x90..+0xa4. Doc correct.

## FUN_0052765A — PASS
Async I/O/state reset handler: If param_3 store param_1[0xf]. If *param_1==4||5 dispatch callback at param_2+0x24. If *param_1==6 calls FUN_0052a090. Reset state machine fields. If param_1[0xe] callback. Doc correct.

## FUN_0056EB90 — PASS
Array-of-structs zero-init stride 0x244: for 0..*param_1-1 zero 12 ints at offsets 0x134..0x160 per element. Doc correct.

## FUN_00404B50 — PASS
Struct field zero via indirect: reads *param_1, zeroes bytes at +0x14/+0x15, dword at +0x1c. Doc correct.

## FUN_0059B758 — PASS
Struct field getter: returns *(param_1 + 0x10). Doc correct.

## FUN_005276C5 — PASS
Multi-block allocator: 3 allocs via vtable (0x40 header, 0x5a0 data, param_3 work). header[9]=data, header[10]=work, header[0]=0, header[0xb]=data+param_3, header[0xe]=param_2. Calls FUN_0052765a. Doc correct.

## FUN_00500170 — PASS
Struct init: param_1[0]=DAT_005ad344, param_1[1]=8, FUN_00500190(), FUN_005001b0(). Doc correct.

## FUN_0049F070 — PASS
Init chain: 5 sequential inits, conditional FUN_0045bc00() if DAT_008ab6e4 != 2, then 2 more inits. Doc correct.

## FUN_004870E0 — PASS
UI list position lookup: reads base from +0x4, count via FUN_0049adb0(), if param_2 < count lookup via FUN_0049aec0, returns (short)result+base. Else if +0xC8 (200) non-null same lookup. Returns -1 on fail. Doc correct.

## FUN_00466140 — PASS
VTable set + init calls: *param_1 = &PTR_FUN_0059f140, FUN_004662e0(), FUN_0048e670(). Doc correct.

## FUN_0055D200 — PASS
Struct zero-init with base: FUN_0053c2a0(), param_1[0]=0, indices 5..0xc zeroed. Doc correct.

## FUN_004DCBA0 — PASS (Partial)
Entry correctly self-identifies as [PARTIAL] Unknown with low confidence. Source is 57 lines with complex alloc/delegation logic. No incorrect factual claims.

## FUN_00520FC6 — PASS
SSE 3D vector normalization: PackedFloatingMUL/ADD/Accumulate for lenSq, threshold compare vs _PTR_DAT_005af970, RSQRT + Newton-Raphson refinement, FUN_00529000() sqrt for output length, _DAT_005af908 scale. FastExitMediaState. Doc correct.

## FUN_0057AE30 — PASS (Partial)
Entry correctly self-identifies as [PARTIAL] Unknown (1 line). Source is single call to FUN_00598815(). Doc correct.

## FUN_005679C0 — PASS
String-keyed linked list search: head at *(param_1+8), return 0 if param_2==0, iterate calling FUN_00499e20() + FUN_00588410() compare, follow next at node+4. Doc correct.

## FUN_0059D150 — PASS
SEH unwind handler: frees *(EBP-0x14) via FUN_00587bcf. Doc correct.

## FUN_0045E590 — PASS
Buffer fill 0xFFFFFFFF: 0x68 dwords starting at param_1+0x1d4. Doc correct.

## FUN_00486460 — PASS
Conditional delegation: if *(param_1+200) != 0 returns FUN_0049a150(), else 0. Doc correct.

## FUN_0049DA60 — PASS
Timestamped render: reads DAT_005ccbc0, DAT_007ce238, DAT_005ccbb8, DAT_005ccbbc. Calls FUN_0049e410. If param_1+8 non-null: FUN_0049c8f0 buffer format, FUN_0049c960 cleanup, FUN_0049f6a0 render ×2. Doc correct.

## FUN_004C91D0 — PASS
Triple vtable destructor: releases 3 interface pointers at +0x20, +0x24, +0x28 via vtable[0](1), zeros fields. Doc correct.

## FUN_0050B446 — PASS
Constructor: FUN_00507496(param_2, 0x10, 1), vtable = PTR_FUN_005add7c. Doc correct.

---

## Summary
- Total: 59 functions validated
- PASS: 58
- FAIL: 1 (FUN_00548E20 — OFFSET-ERROR)
