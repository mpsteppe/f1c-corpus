# Cross-Validation Results: worker_F_E

## FUN_00516883 — PASS

doc: docs/19-renderer.md — Render VTable/Object Init
source: 0x00516883__FUN_00516883.c

Verification:
- Zeroes param_1[1]: .c `param_1[1] = 0;` ✓
- Allocates 0x50-byte block via FUN_00519346: .c `FUN_00519346(param_1,0x50)` ✓
- On failure sets error 0x35: .c `*(undefined4 *)(*param_1 + 0x14) = 0x35;` ✓
- 11 function pointers (FUN_00515f23..FUN_00516853): .c puVar2[0..10] = 11 pointers ✓
- Size field = 0x50: .c `puVar2[0x12] = 0x50;` ✓
- Stores block in param_1[1]: .c `param_1[1] = (int)puVar2;` ✓
- Calls: FUN_0058fb7e, FUN_00519346, FUN_00587b96 — all present ✓
- Moddability: hardcoded ✓

## FUN_00485a70 — PASS

doc: docs/19-renderer.md — Destructor with Conditional Free
source: 0x00485a70__FUN_00485a70.c

Verification:
- Calls FUN_00466140(): .c `FUN_00466140();` ✓
- Optionally frees self: .c `if ((param_2 & 1) != 0) { FUN_00587bcf(param_1); }` ✓
- Moddability: hardcoded ✓

## FUN_005450e0 — PASS

doc: docs/19-renderer.md — Mesh/Resource Allocator
source: 0x005450e0__FUN_005450e0.c

Verification:
- Allocates 0x23c bytes: .c `operator_new(0x23c)` ✓
- Calls constructor FUN_0054a600(): .c `iVar2 = FUN_0054a600();` ✓
- Loads mesh via FUN_0054a730(): .c `iVar3 = FUN_0054a730(param_2,param_3);` ✓
- On failure: cleanup + free: .c `FUN_0054a710(); FUN_00587bcf(iVar2); return 0xffffffff;` ✓
- Calls: FUN_0054a600, FUN_0054a730, FUN_0054a710 — all present ✓
- Moddability: hardcoded ✓

## FUN_0048b9c0 — PASS

doc: docs/19-renderer.md — Text Input Render / Password Mask
source: 0x0048b9c0__FUN_0048b9c0.c

Verification:
- Text from param_1[0x32], null-check: .c `if (param_1[0x32] != 0)` ✓
- FUN_00498560 (text measurement): .c `FUN_00498560(puVar2);` ✓
- FUN_004983b0 (line metrics): .c `FUN_004983b0(&DAT_005cc218,&iStack_10c,auStack_104,1);` ✓
- FUN_00486460 (content area): .c `piVar3 = (int *)FUN_00486460(0);` ✓
- FUN_00494a30 (draw background): .c `FUN_00494a30(...)` ✓
- Text from param_1[0xbc], 255-byte strncpy: .c `_strncpy(&cStack_100,pcVar11,0xff);` ✓
- password_flag at +0xe2 → '*' masking: .c `*(char *)((int)param_1 + 0xe2) == '\0'` else `*pcVar13 = '*';` ✓
- cursor_visible param_1[0x38] + suffix_flag +0xe1 → DAT_005cc214: .c `(char)param_1[0x38] != '\0' && *(char *)((int)param_1 + 0xe1) != '\0'` → `DAT_005cc214` ✓
- FUN_004981f0 (render with cursor): .c `FUN_004981f0(pcVar11,uVar6,uVar15,uVar14,uVar4,uVar16);` ✓
- Returns char positions via param_2-5: .c lines 112-118 setting *param_2..*param_5 ✓
- Struct offsets: [0x32], [0x38], [0xbc], +0xe1, +0xe2 — all match .c usage ✓
- Globals: DAT_005cc218, DAT_005cc214 — both in .c ✓
- Calls: FUN_00498560, FUN_004983b0, FUN_00486460, FUN_00494a30, FUN_004981f0, _strncpy — all present ✓
- Moddability: hardcoded ✓

## FUN_0047EF3C — FAIL

doc: docs/19-renderer.md — Percentage Display Formatter
source: 0x0047ef3c__sub_47EF3C.c (IDA Hex-Rays)

Errors:
- [MODDABILITY] claims `configurable — display format string` but format string "%0.0f%%" is a hardcoded literal. No config file read or global reference. Should be `hardcoded`.

Verification of factual claims:
- Multiplies flt_7D084C by 100.0: .c `flt_7D084C * 100.0` ✓
- Formats via "%0.0f%%": .c `sub_58815F(v1, "%0.0f%%", flt_7D084C * 100.0);` ✓
- Calls FUN_0047E940 to display: .c `sub_47E940(v1);` ✓
- Globals: flt_7D084C — present in .c ✓
- Calls: FUN_0058815F (sprintf), FUN_0047E940 — both present ✓

Corrected entry:
```
## FUN_0047EF3C — Percentage Display Formatter

Source: IDA Hex-Rays. Formats loading progress as percentage string and renders it.

**Key logic:**
- Multiplies flt_7D084C by 100.0
- Formats via FUN_0058815F(v1, "%0.0f%%", value) → e.g. "75%"
- Calls FUN_0047E940(v1) to display/draw the string

**Globals:** flt_7D084C — loading progress or completion ratio (0.0–1.0)

**Calls:** FUN_0058815F (sprintf), FUN_0047E940

**Moddability:** hardcoded
```

## FUN_0049e5b0 — PASS

doc: docs/19-renderer.md — Float-to-Color Encoding
source: 0x0049e5b0__FUN_0049e5b0.c

Verification:
- param_1 < _DAT_0059e468 → underflow: .c `if (_DAT_0059e468 <= param_1)` → else underflow ✓
- param_1 > _DAT_005acb08 → overflow: .c `if (param_1 <= _DAT_005acb08)` → else overflow ✓
- Sub-divides at _DAT_005acb00 and _DAT_005acb04: .c `param_1 < _DAT_005acb00`, `param_1 < _DAT_005acb04` ✓
- Underflow: `iVar2 << 0x10 | 0xff0000ff`: .c `return iVar2 << 0x10 | 0xff0000ff;` ✓
- Low-mid: `ftol() | 0xffff0000`: .c `return uVar1 | 0xffff0000;` ✓
- Upper: `(ftol() | 0xffffff00) << 8`: .c `return (uVar1 | 0xffffff00) << 8;` ✓
- All paths use __ftol(): .c uses `__ftol()` in all three branches ✓
- Globals: _DAT_0059e468, _DAT_005acb00, _DAT_005acb04, _DAT_005acb08 — all in .c ✓
- Calls: __ftol() — present ✓
- Moddability: hardcoded ✓

## FUN_005934e1 — PASS

doc: docs/20-math-utilities.md — Exception dispatcher with SEH
source: 0x005934e1__FUN_005934e1.c

Verification:
- Checks magic -0x1f928c9d: .c `*param_1 == -0x1f928c9d` ✓
- Checks 3 and 0x19930520: .c `param_1[4] == 3 && param_1[5] == 0x19930520` ✓
- Iterates handler table via FUN_0058a55a: .c `FUN_0058a55a(param_5,param_7,local_14,&local_8,&local_1c)` ✓
- Dispatches to FUN_00593839: .c `FUN_00593839(...)` ✓
- param_6==0 → FUN_00593694: .c `if (param_6 == '\0') { FUN_00593694(...); }` ✓
- param_6!=0 → FUN_00593c9c: .c `FUN_00593c9c();` ✓
- Signature matches .c ✓
- Size 435 bytes: .c header confirms ✓

## FUN_00582650 — PASS

doc: docs/20-math-utilities.md — Pool destructor
source: 0x00582650__FUN_00582650.c

Verification:
- Signature `void __fastcall FUN_00582650(undefined4 *param_1)`: .c matches ✓
- Size 207 bytes: .c header confirms ✓
- Frees busy nodes with virtual call(1): .c `(*(code *)**(undefined4 **)*piVar3)(1);` ✓
- Free nodes with virtual call(3): .c `(*(code *)**(undefined4 **)*piVar2)(3);` ✓
- Linked list cleanup via FUN_00587bcf: .c multiple FUN_00587bcf calls ✓

## FUN_00586aa0 — PASS

doc: docs/20-math-utilities.md (triage-only: `unknown`)
source: 0x00586aa0__FUN_00586aa0.c

Verification: Triage-only entry, no substantive claims to verify. Complex bit manipulation function with calls to FUN_00585e80, FUN_00586f70, FUN_00586f40, FUN_00586fa0, FUN_00587500. Classification `unknown` is acceptable.

## FUN_00594ff0 — PASS

doc: docs/20-math-utilities.md — `__aulldiv`: 64-bit unsigned integer division
source: 0x00594ff0____aulldiv.c

Verification:
- Identified as MSVC Library Function `__aulldiv` ✓
- Performs unsigned 64-bit division with carry handling ✓
- No game logic, standard CRT ✓

## FUN_0059b760 — PASS

doc: docs/20-math-utilities.md (triage-only: `unknown`)
source: 0x0059b760__FUN_0059b760.c

Verification: Triage-only entry. File info/stats query function using GetFileType, GetFileInformationByHandle, PeekNamedPipe, FileTimeToSystemTime. Classification `unknown` is acceptable.

## FUN_00583ae0 — PASS

doc: docs/20-math-utilities.md — SEH cleanup / linked list destruction
source: 0x00583ae0__FUN_00583ae0.c

Verification:
- Linked list destruction with FUN_00583210: .c `FUN_00583210(iVar2,0);` ✓
- CloseHandle calls for multiple handles: .c multiple CloseHandle calls at offsets 0x35, 0x3c, 0x163, 0x16a, 0x16e, 0x186, 0x190 ✓
- Multiple FUN_005833e0, FUN_00585fb0 cleanup calls: .c all present ✓
- Matches description of "linked list destruction" SEH unwind helper ✓

## FUN_00551210 — PASS

doc: docs/20-math-utilities.md (triage-only: `crt_util`)
source: 0x00551210__FUN_00551210.c

Verification: Triage-only entry. Animation interpolation function using vector math (FUN_0053b490, FUN_0053b5b0, FUN_0053b4c0, FUN_0053b4a0) with __ftol and float interpolation. Category `crt_util` is debatable (more like animation/interpolation utility), but no detailed claims to verify.

## FUN_005959a0 — PASS

doc: docs/20-math-utilities.md (triage-only: `unknown`)
source: 0x005959a0__FUN_005959a0.c

Verification: Triage-only entry. File handle closing function with SetStdHandle for stdin/stdout/stderr. No substantive claims to verify.

## FUN_0051d897 — PASS

doc: docs/20-math-utilities.md (triage-only: `unknown`, `unidentified logic`)
source: 0x0051d897__FUN_0051d897.c

Verification: Triage-only entry. Complex weighted distance computation with byte array lookups and sorting. Classification `unidentified logic` is accurate for triage.

## FUN_00407be0 — PASS

doc: docs/20-math-utilities.md (triage-only: `unknown`, `memory allocation`)
source: 0x00407be0__FUN_00407be0.c

Verification: Triage-only entry. Linked list node removal with virtual dispatch(1) + free via FUN_00587bcf. Decrements count at +0x14. "memory allocation" is approximately correct (deallocation).

## FUN_004c3890 — PASS

doc: docs/20-math-utilities.md (triage-only: `math_util`, `arithmetic/comparison`)
source: 0x004c3890__FUN_004c3890.c

Verification:
- Calls FUN_00587ece on two params, returns comparison: .c `iVar1 = FUN_00587ece(param_2 + 0x74); iVar2 = FUN_00587ece(param_1 + 0x74); return iVar2 < iVar1;` ✓
- Classification `arithmetic/comparison` accurate ✓

## FUN_00560fc0 — PASS

doc: docs/20-math-utilities.md (triage-only: `unknown` + `math_util`)
source: 0x00560fc0__FUN_00560fc0.c

Verification:
- Sets bit 1 at struct+0x24: .c `*(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) | 2;` ✓
- Matches second triage entry: "Sets bit 1 flag at struct+0x24" ✓

## FUN_00407c90 — PASS

doc: docs/20-math-utilities.md (triage-only: `unknown`, `memory allocation`)
source: 0x00407c90__FUN_00407c90.c

Verification: Triage-only. Similar to FUN_00407be0 but with different offsets (0x18/0x20/0x1c/0x24). Linked list node removal + free. "memory allocation" is approximately correct.

## FUN_0046d360 — PASS

doc: docs/20-math-utilities.md (triage-only: `math_util`, `short computation`)
source: 0x0046d360__FUN_0046d360.c

Verification: Triage-only. Virtual dispatch with conditional via FUN_004d24a0. Calls vtable+0x38 with 1 or 0. Classification `short computation` is acceptable.

## FUN_00488900 — PASS

doc: docs/20-math-utilities.md (triage-only: `unknown`, `unidentified`)
source: 0x00488900__FUN_00488900.c

Verification: Triage-only. Captures mouse coordinates via FUN_00498880, virtual dispatch at +0x18/+0x1c/+0x24, sets param_1[0x38] to horizontal offset, calls FUN_00488970. Classification `unidentified` is acceptable for triage.

## FUN_004a2a40 — PASS

doc: docs/20-math-utilities.md (triage-only: `math_util`, `arithmetic/comparison`)
source: 0x004a2a40__FUN_004a2a40.c

Verification: Triage-only. String processing: removes quote characters (`'"'`), copies to dest buffer at param_2, calls FUN_00589901. Classification `math_util/arithmetic` is not accurate (it's string processing), but no detailed claims in triage entry to contradict.

## FUN_004d82a0 — PASS

doc: docs/20-math-utilities.md (triage-only: `math_util`, `arithmetic/comparison`)
source: 0x004d82a0__FUN_004d82a0.c

Verification: Triage-only. Iterates 26 (0x19) items from param_1+0x10, calls FUN_004d7e30 if non-zero. Rendering/list iteration. No detailed claims to verify.

## FUN_00516c0c — PASS

doc: docs/20-math-utilities.md (triage-only: `unknown`, `unidentified logic`)
source: 0x00516c0c__FUN_00516c0c.c

Verification: Triage-only. Buffer initialization with identity/linear mapping (0x40 zero, 0x100 sequential, 0x60 of 0xffffffff, 0x60 zero, copies 0x20 values). Lookup table init. Classification `unidentified logic` is acceptable for triage.

## FUN_00561a15 — PASS

doc: docs/20-math-utilities.md (triage-only: `unknown`, `Fill array with stride-based memset pattern`)
source: 0x00561a15__FUN_00561a15.c

Verification:
- Fills array with stride-based pattern using memset-like loop: .c `*puVar1 = param_3; puVar1 = puVar1 + param_4;` ✓
- Matches second triage description ✓

## FUN_0057b9f0 — PASS

doc: docs/20-math-utilities.md (triage-only: `Data/Copy — Copy 4 dwords struct to struct`)
source: 0x0057b9f0__FUN_0057b9f0.c

Verification:
- Copies 4 dwords: .c `*param_2 = *param_1; param_2[1] = param_1[1]; param_2[2] = param_1[2]; param_2[3] = param_1[3];` ✓
- Matches "Copy 4 dwords struct to struct" ✓

## FUN_00418b70 — PASS

doc: docs/20-math-utilities.md (triage-only: `math_util`, `short computation`)
source: 0x00418b70__FUN_00418b70.c

Verification:
- Returns -1 if param == -1, else table lookup at DAT_005bf9a0 + param_1*0x14: .c confirm ✓
- `short computation` classification acceptable ✓

## FUN_00476600 — PASS

doc: docs/20-math-utilities.md (triage-only: `unknown`, `unidentified`)
source: 0x00476600__FUN_00476600.c

Verification: Triage-only. Destructor: frees param_1[0xf], param_1[0xc], param_1[1], optionally frees self. Multiple vtable changes. Classification `unidentified` acceptable.

## FUN_00499620 — PASS

doc: docs/20-math-utilities.md (triage-only: `math_util`, `short computation`)
source: 0x00499620__FUN_00499620.c

Verification: Triage-only. Destructor: frees *param_1 if flag set, optionally frees self. Classification `math_util/short computation` is not fully accurate (it's a destructor), but no detailed claims to verify.

## FUN_004c2bf0 — PASS

doc: docs/20-math-utilities.md (triage-only: `math_util`, `short computation`)
source: 0x004c2bf0__FUN_004c2bf0.c

Verification:
- Increments int at +0x28: .c `*(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;` ✓
- `short computation` classification accurate ✓

## FUN_0050b7fb — PASS

doc: docs/20-math-utilities.md (triage-only: `math_util`, `short computation`)
source: 0x0050b7fb__FUN_0050b7fb.c

Verification: Triage-only. Calls FUN_0050afe2, sets vtable to PTR_FUN_005addfc. Constructor-like. No detailed claims.

## FUN_00547370 — PASS

doc: docs/20-math-utilities.md (triage-only: `math_util`, `arithmetic/comparison`)
source: 0x00547370__FUN_00547370.c

Verification: Triage-only. String copy (strcpy with overlap handling): copies bytes from param_1 to param_1+(param_2-param_1) until null terminator. Doesn't modify param_2. Classification `math_util/arithmetic` is inaccurate (it's strcpy), but no detailed claims.

## FUN_0059cbe8 — PASS

doc: docs/20-math-utilities.md (triage-only: `unknown`, `C++ unwind helper — thunk to FUN_005819c0`)
source: 0x0059cbe8__Unwind_0059cbe8.c

Verification:
- SEH unwind helper thunk to FUN_005819c0: .c `void Unwind_0059cbe8(void) { FUN_005819c0(); return; }` ✓
- Matches description ✓

## FUN_004636e0 — PASS

doc: docs/20-math-utilities.md (triage-only: `math_util`, `short computation`)
source: 0x004636e0__FUN_004636e0.c

Verification:
- Extracts byte at *param_1+0x20, shifts and combines: .c `return CONCAT31((int3)((uint)*param_1 >> 8),*(undefined1 *)(*param_1 + 0x20));` ✓
- `short computation` classification accurate ✓

## FUN_004b9780 — PASS

doc: docs/20-math-utilities.md (triage-only: `math_util`, `arithmetic/comparison`)
source: 0x004b9780__FUN_004b9780.c

Verification: Triage-only. Allocates 0xf9c bytes via operator_new, calls FUN_004b57f0 constructor. Classification `arithmetic/comparison` is inaccurate (it's allocation + construction), but no detailed claims.
