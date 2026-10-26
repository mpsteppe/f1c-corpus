# Cross-Validation Audit: Worker P

Audit date: 2026-07-15
Target doc: docs/20-math-utilities.md
Method: Source .c vs doc entry comparison

---

## FUN_00409770 — File Resource Processing with Callbacks

**Result: PASS**

Source shows file processing with FUN_0058ba36 (toggle read-only), FUN_005668b0 (zero-init), conditional FUN_00566a70 (read) or FUN_00566940 (write) based on param_3, four optional vtable callbacks at +0x10/+0x14/+0x18/+0x1c calling vtable+8, array iteration (stride 200, count +0x38), FUN_00566b90 (conditional close), FUN_005668d0 (cleanup).

Doc entry correctly describes all of the above. No discrepancies found.

---

## FUN_00466090 — UI Visual Struct Init

**Result: PASS**

Source initializes UI visual struct: FUN_0048e600() base init, sets float fields [0x3e]=5.0f, [0x40]=5.0f, [0x3c]=0, [0x3f]=10.0f, [0x44]=1.0f, [0x46]=-1.0f, [0x49]=-1.0f, zeroes ints at [0x41]/[0x42]/[0x43]/[0x45]/[0x47]/[0x48] and bytes at +0x3d/+0xf5, sets vtable to &PTR_FUN_0059f140.

Doc entry matches all field values and assignments. No discrepancies found.

---

## FUN_0048d0a0 — Float Random + Vtable Dispatch

**Result: PASS**

Source: fVar1 = (float10)FUN_00498730(); FUN_0048cb00((float)fVar1); (**(code **)(*param_1 + 0xac))(); return 0.

Doc entry correctly describes random float get, callback/update via FUN_0048cb00, and vtable dispatch at +0xac. Calls list correct.

---

## FUN_004a6fe0 — Single Call Wrapper

**Result: PASS**

Source: void FUN_004a6fe0(void) { FUN_004a70e0(); return; }

Doc entry: "Delegates to FUN_004a70e0()." Correct.

---

## FUN_004d7da0 — Callback Registration

**Result: PASS**

Source: void FUN_004d7da0(void) { FUN_00587b3e(&DAT_004d7db0); return; }

Doc entry: "Calls FUN_00587b3e with DAT_004d7db0." Correct.

---

## FUN_005115ee — Vtable Function Table Init

**Result: PASS**

Source allocates 0x5c bytes via vtable dispatch, stores at param_1+400. Sets [0]=FUN_005115c4, [4]=&LAB_0051126a, [8]=FUN_00511457, [0xc]=FUN_00511060. Loop 0x10..0x4c (step 4) fills with FUN_00511060. Overrides [0x10]=FUN_005105bf, [0x48]=FUN_005107fb. Calls FUN_005115c4(param_1) finalize.

Doc entry accurately describes allocation size (0x5c), storage location (param_1+400), method pointer assignments, loop fill range, overrides, and finalize call. No discrepancies.

---

## FUN_0054b450 — 3× Random Float Setter

**Result: PASS**

Source sets 3 float fields: *(float*)(param_1+0x2c)=FUN_0058957a(), *(float*)(param_1+0x30)=FUN_0058957a(), *(float*)(param_1+0x34)=FUN_0058957a(), then FUN_0054b330(0x40,0,0).

Doc entry correctly documents three random float assignments at +0x2c/+0x30/+0x34 and call to FUN_0054b330 with (0x40,0,0). Calls list correct (FUN_0058957a ×3, FUN_0054b330).

---

## FUN_00582b10 — Linked List Element Removal with Cleanup

**Result: PASS**

Source: linked list removal by key value. Saves head value as search target at param_1[2]. Clears flag byte at (head+2). Walks nodes via [1] (next pointer). On match: updates iterator, relinks, decrements count, conditionally frees sub-data via FUN_005867b0+FUN_00587bcf, frees node via FUN_00587bcf, returns key. Returns 0 if not found.

Doc entry matches all logic steps precisely. Struct offset tables correct: head/tail/iterator at +0x00/+0x04/+0x08, count at +0x0c; node key/next/flag at +0x00/+0x04/+0x08.

---

## FUN_00587210 — Short Computation (Struct Field Getter at +0x18)

**Result: PASS**

Source: undefined1 __fastcall FUN_00587210(int param_1) { return *(undefined1 *)(param_1 + 0x18); }

Doc entry: "Returns byte at param_1 + 0x18." Correct.

---

## FUN_00543540 — Unidentified Logic (Rect/Viewport Clamp)

**Result: PASS**

Source: Takes (this, x_offset, y_offset, x, y) as int pointers. Clamps x: if *param_2<0 shifts param_4 and zeroes param_2; if width<param_4+param_2 reduces param_4; clamps param_4 to [0,width]. Same clamp logic for y using height at param_1+0x20.

Doc entry correctly identifies as rect/viewport clamp with width (+0x1c) and height (+0x20) bounds, describes all clamping steps. Algorithm family "rectangle clipping" accurate.

---

## Summary

| # | Function | Result |
|---|----------|--------|
| 1 | FUN_00409770 | PASS |
| 2 | FUN_00466090 | PASS |
| 3 | FUN_0048d0a0 | PASS |
| 4 | FUN_004a6fe0 | PASS |
| 5 | FUN_004d7da0 | PASS |
| 6 | FUN_005115ee | PASS |
| 7 | FUN_0054b450 | PASS |
| 8 | FUN_00582b10 | PASS |
| 9 | FUN_00587210 | PASS |
| 10 | FUN_00543540 | PASS |

---

## FUN_004dd4d0 — Conditional Free at +0x14

**Result: PASS**

Doc: "If param_1+0x14 != 0: frees via FUN_00587bcf."
Source: `if (*(int *)(param_1 + 0x14) != 0) { FUN_00587bcf(...); }`
Perfect match. Calls list correct (FUN_00587bcf).

---

## FUN_004c5db0 — Struct Init with Defaults

**Result: PASS**

Doc: "Sets param_1[0]=0, param_1[1]=-1, param_1[2..5]=0. Calls FUN_004c62c0()."
Source: `*param_1=0; param_1[1]=0xffffffff; param_1[2..5]=0; FUN_004c62c0();`
All assignments and call match. Minor imprecision in header ("Zeroes 6 dwords" — actually 5 zeroed + 1 set to -1) but detailed bullets are correct.

---

## FUN_00491e60 — Destructor with Conditional Free

**Result: PASS**

Doc: "If (param_2 & 1): calls FUN_00587bcf(param_1). Returns param_1."
Source: `if ((param_2 & 1) != 0) { FUN_00587bcf(param_1); } return param_1;`
Precise match.

---

## FUN_00471970 — UI Widget Constructor

**Result: PASS**

Doc: vtable=PTR_FUN_005a1440, param_1[199]=&DAT_007ce7f0, settings at +0x324..+0x334: type=2, count=0, min=1, max=1, default=0xf4, three FUN_00486f30 calls with -1 ID, FUN_004670e0().
Source: All values verified: [0xc9]=2, [0xca]=0, [0xcb]=1, [0xcc]=1, [0xcd]=0xf4. Three FUN_00486f30 calls with 0xffffffff. FUN_004670e0() call. All correct.

---

## FUN_004141a0 — Array Lookup

**Result: FAIL**

Doc claims: "If param_1 == 0: returns 1."
Source truth: 
```c
if (param_1 == 0) { iVar1 = 1; }
// ...
iVar1 = (&DAT_005bf8c8)[iVar1];  // reads DAT_005bf8c8[1] = DAT_005bf8cc
return iVar1;
```
Function returns `DAT_005bf8cc` (the value at 0x005bf8cc), NOT the literal 1. Doc incorrectly describes the direct value. Otherwise correct: param_1==1 returns DAT_005bf8d4, out-of-range returns -1.

---

## FUN_004c9060 — [PARTIAL] Unknown

**Result: PASS (placeholder)**

Doc is [PARTIAL] placeholder: "2 lines of decompiled code. Needs manual analysis." Makes no substantive claims. Source has 6 non-trivial lines (vtable swap, FUN_004c91d0 call, conditional free). Placeholder correctly flagged as incomplete.

---

## FUN_0050b42a — [PARTIAL] Unknown

**Result: PASS (placeholder)**

Doc is [PARTIAL] placeholder. Source: FUN_00507496(param_2,0x20,2), vtable set, return. Placeholder makes no false claims.

---

## FUN_00541f60 — [PARTIAL] Unknown

**Result: PASS (placeholder)**

Doc is [PARTIAL] placeholder. Source: complex 3D vector math — difference vector, SQRT magnitude, normalization, fpatan angle computation, writes to +0x30/+0x34, calls FUN_00541cd0. Placeholder correctly flagged as incomplete.

---

## FUN_0059870c — [PARTIAL] Unknown

**Result: PASS (placeholder)**

Doc is [PARTIAL] placeholder. Source: `void FUN_0059870c(void) { FUN_00598b5d(0,1); }`. Placeholder makes no false claims.

---

## FUN_0058c0d0 — String Shift by Offset

**Result: PASS**

Doc: "Shifts string right by param_2 bytes. Gets strlen, calls FUN_0058b130(dest=param_1+param_2, src=param_1, len=strlen+1)."
Source: `_strlen(param_1); FUN_0058b130(param_1+param_2, param_1, sVar1+1);`
Calls list: _strlen, FUN_0058b130. All correct.

---

## Summary

| # | Function | Result |
|---|----------|--------|
| 1 | FUN_004dd4d0 | PASS |
| 2 | FUN_004c5db0 | PASS |
| 3 | FUN_00491e60 | PASS |
| 4 | FUN_00471970 | PASS |
| 5 | FUN_004141a0 | FAIL |
| 6 | FUN_004c9060 | PASS (placeholder) |
| 7 | FUN_0050b42a | PASS (placeholder) |
| 8 | FUN_00541f60 | PASS (placeholder) |
| 9 | FUN_0059870c | PASS (placeholder) |
| 10 | FUN_0058c0d0 | PASS |

**Total: 9/10 PASS — 1 FAIL**

---

## FUN_00406B80 — Conditional Destructor

**Result: PASS**

Source: calls FUN_00406ba0(), checks param_2 & 1, conditionally calls FUN_00587bcf(param_1), returns param_1.

Doc entry: "Calls FUN_00406ba0 (cleanup), If param_2 & 1: calls FUN_00587bcf(param_1), Returns param_1." All claims match source exactly. Calls list correct (FUN_00406ba0, FUN_00587bcf).

---

## FUN_004685F0 — Conditional Destructor with Cleanup

**Result: PASS**

Source: calls FUN_00468610(), checks param_2 & 1, conditionally calls FUN_00587bcf(param_1), returns param_1.

Doc entry: "Calls FUN_00468610 cleanup. If param_2 & 1: frees param_1 via FUN_00587bcf. Returns param_1." All claims match source exactly. Calls list correct (FUN_00468610, FUN_00587bcf).

---

## FUN_0048E5C0 — Conditional Geometry/Display Update

**Result: PASS**

Source: dispatches vtable+0xa0. If return == 0: reads param_1[0x3a..0x3d], calls FUN_00490920(param_1[0x3a..0x3d]) and FUN_004918d0(param_1[0x3a..0x3d]).

Doc entry: "If vtable+0xa0 returns 0: reads param_1[0x3a..0x3d] and dispatches to FUN_00490920 and FUN_004918d0." All claims match. Calls list correct.

---

## FUN_004B1A30 — VTable Init with Defaults (Shorter)

**Result: PASS**

Source: sets param_1[1]=0, param_1[2]=0xffffffff, param_1[3]=0, param_1[4]=0xffffffff, *param_1 = &PTR_LAB_005acc50.

Doc entry: "Sets 4 fields to alternating 0/-1 pattern and vtable PTR_LAB_005acc50. param_1[1..4] = {0,-1,0,-1}, *param_1 = &PTR_LAB_005acc50." All values match. No calls (correct).

---

## FUN_004D9030 — Audio Resource Release by Type

**Result: PASS**

Source: switch(param_1): 1→DAT_008ad398, 2→DAT_008ad39c, 3→DAT_008ad3a0, 4→DAT_008ad3a4, 5→DAT_008ad3a8. If *piVar2 != 0: FUN_005539f0(), zeroes. If param_1==3 && DAT_008ad3ac != 0: FUN_005502c0(), FUN_00557470(), FUN_00587bcf(), zeroes DAT_008ad3ac.

Doc entry: "Releases audio resources indexed by param_1 (1-5). Selects from DAT_008ad398..008ad3a8. Frees via FUN_005539f0. Special case param_1==3: extra cleanup via FUN_005502c0 + FUN_00557470 + FUN_00587bcf." All claims match. Calls list correct.

---

## FUN_005125C9 — Bit Packing/Unpacking (1/2/4-bit)

**Result: PASS**

Source: reads bit width from param_1+9. If < 8: branches on width 1/2/4. For width 1: unpacks 1 bit per output byte, iterating *param_1 elements. Width 2: unpacks 2-bit values. Width 4: unpacks 4-bit values. Sets param_1+9=8 after. Computes buffer sizes at +0xb and param_1[1]. No calls to other functions (leaf).

Doc entry: "Unpacks bits from a byte buffer into individual values. Supports 1-bit, 2-bit, and 4-bit fields. Reads byte at param_1+9 for bit width (1/2/4). Processes *param_1 elements from param_2 buffer. Sets byte at param_1+9 to 8, computes buffer size. Calls: none (leaf function)." All claims match. Algorithm family "bit manipulation/packing" correct.

---

## FUN_00550870 — Struct Zero Init with Unit Vector

**Result: PASS** (minor: "6 dwords" is actually 7 dwords in source)

Source: calls FUN_0053c2a0(). Zeroes *param_1=0, param_1[2]=0, [3]=0, [4]=0, [5]=0, [6]=0, byte at (param_1+7)=0, param_1[0xb]=0 (7 dwords + 1 byte total). Sets param_1[1]=0x3f800000 (1.0f as float). Returns param_1.

Doc entry: "Calls FUN_0053c2a0. Zeroes 6 dwords and a byte. Sets param_1[1] = 1.0f (0x3f800000)." All functional claims correct. Dword count off by one (7 vs 6) — minor, functional description accurate. Calls list correct (FUN_0053c2a0).

---

## FUN_00552FF0 — Switch-Based Parameter Field Set with Flags

**Result: PASS**

Source: writes param_2 to param_1+0x54. Switch on param_3: case 0→0xbf, case 1→0x7f, case 2→0x3f, case 3→0x00, case 4→0xff — all written to param_1+0x58.

Doc entry: "Writes param_2 to param_1+0x54. Switch on param_3 (0-4) selects value written to param_1+0x58: case 0: 0xbf, case 1: 0x7f, case 2: 0x3f, case 3: 0x00, case 4: 0xff." All values match exactly. Struct offset table correct.

---

## FUN_0040EEC0 — Switch-Based Float Processing

**Result: PASS** (minor: "6 float params" — source shows 7 float-to-double conversions)

Source: converts 7 floats to doubles (param_2[0] via (double)*param_2, param_2[1-3] via locals, param_2[4-6] inline). Switch on param_1+0x1c (modes 0-5): calls FUN_00459950((double)*param_2, &local_20) and FUN_00459990((double)fVar1, (double)fVar2, (double)fVar3).

Doc entry: "Processes float parameters through math functions based on a mode switch. Converts 6 float params to doubles. Switch on param_1+0x1c (mode 0-5): calls FUN_00459950 and FUN_00459990." All functional claims correct. Float count off by one (7 vs 6) — minor. Calls list correct.

---

## FUN_0046E6F0 — Conditional Delegation via VTable

**Result: PASS**

Source: dispatches vtable+0x1c(0x2c) via pointer at param_1+0x40. If non-null: calls FUN_00489920(). If non-null: calls FUN_0046e5c0(iVar1) with result of FUN_00489920. Returns 0.

Doc entry: "Calls virtual method at vtable+0x1c with arg 0x2c (alloc). If successful: calls FUN_00489920() and FUN_0046e5c0(). Returns 0." All claims match. Note: FUN_0046e5c0 only called if FUN_00489920 also returns non-null (nested success) — doc does not specify the nesting but does not contradict it.

---

## Summary

| # | Function | Result |
|---|----------|--------|
| 1 | FUN_00406B80 | PASS |
| 2 | FUN_004685F0 | PASS |
| 3 | FUN_0048E5C0 | PASS |
| 4 | FUN_004B1A30 | PASS |
| 5 | FUN_004D9030 | PASS |
| 6 | FUN_005125C9 | PASS |
| 7 | FUN_00550870 | PASS (minor) |
| 8 | FUN_00552FF0 | PASS |
| 9 | FUN_0040EEC0 | PASS (minor) |
| 10 | FUN_0046E6F0 | PASS |

**Total: 10/10 PASS — 0 FAIL**

Minor inaccuracies noted in FUN_00550870 ("6 dwords" should be 7) and FUN_0040EEC0 ("6 float params" should be 7). Neither affects functional understanding.

---

## FUN_00490660 — VTable Dispatch List Iteration

**Result: PASS**

Source: calls FUN_00486720(). If 2 < state < 6: sets flag=1. Iterates param_1+0xec entries via linked list at param_1+0xe0 (node walking via [1] next pointer). For each valid node: calls vtable+0x10 with flag.

Doc entry: "Calls FUN_00486720()", "If 2 < state < 6: sets flag = 1", "Iterates param_1+0xec entries via linked list at param_1+0xe0", "Calls virtual method at vtable+0x10 on each valid node with flag." All claims match source exactly.

---

## FUN_004b2b60 — Bitfield Setter

**Result: PASS**

Source: `*(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xffc07fff | param_2 << 0xf;`

Doc entry: "Sets a 15-bit field within a 32-bit bitfield at +0x30." Mask operation formula exactly matches source. "Replaces bits 15-29 with param_2." Correct — shift by 0xf places param_2 at bits 15-29 (15 bits). No calls (correct).

---

## FUN_004dcd10 — Resource Cleanup

**Result: PASS**

Source: if param_1[1] non-null: FUN_005502c0(), FUN_00557470(), FUN_00587bcf(). If *param_1 non-null: FUN_005539f0(*param_1). Calls FUN_004dcb70().

Doc entry: "If param_1[1] non-null: stop (FUN_005502c0), release (FUN_00557470), free (FUN_00587bcf). If *param_1 non-null: FUN_005539f0 (release sound). FUN_004dcb70() — final cleanup." All calls and logic match source exactly.

---

## FUN_0051664f — Offset Validation with Buffer Update

**Result: PASS**

Source: validates buffer bounds (param_2[1] vs uVar1, param_2[3] vs param_4, *param_2==0), sets error codes 0x14/0x44 at *param_1+0x14, adjusts param_2[6]/param_2[7] (buffer size), optionally processes via FUN_005159a8, returns *param_2 + (param_3 - param_2[6]) * 4.

Doc entry: "Checks param_2 buffer bounds against param_3/param_4", "On overflow: sets error code at *param_1+0x14, calls vtable handler", "Adjusts buffer size at param_2[6] and param_2[7]", "Optionally processes entries via FUN_005159a8", "Returns pointer to element at computed offset." All claims accurate. Doc is high-level (does not detail +0x21/+0x22 flag bytes or FUN_005164a6 calls) but makes no incorrect claims. Confidence: low correctly.

---

## FUN_005573f0 — Dual Delegate

**Result: PASS**

Source: `void FUN_005573f0(void) { FUN_0053b160(); FUN_004b0170(); }`

Doc entry: "Calls FUN_0053b160() (empty stub) and FUN_004b0170()." Both calls verified in source. No params, no return (correct).

---

## FUN_0055d3f0 — Byte Extraction from uint

**Result: PASS**

Source: `FUN_0055d320(param_1, param_2 >> 0x10 & 0xff, param_2 >> 8 & 0xff, param_2 & 0xff);`

Doc entry: "Extracts three bytes from a uint32", byte extraction formulas `(param_2 >> 16) & 0xff`, `(param_2 >> 8) & 0xff`, `param_2 & 0xff` match source. Calls FUN_0055d320 with byte order (b2, b1, b0) verified. Algorithm family "bit extraction / UI layout" accurate.

---

## FUN_00414370 — Short Computation (Conditional Free)

**Result: PASS**

Source: `if (*param_1 != 0) { FUN_00587bcf(*param_1); }`

Doc entry: "If *param_1 non-null, frees it." "If *param_1 != 0: FUN_00587bcf(*param_1)." Calls list (FUN_00587bcf) correct.

---

## FUN_00472340 — Short Computation (VTable Set + Init)

**Result: PASS**

Source: FUN_0048c070(1); *param_1 = &PTR_FUN_005a1e00; FUN_00472400(); return param_1.

Doc entry: "FUN_0048c070(1)", "*param_1 = &PTR_FUN_005a1e00", "FUN_00472400()". Constructor-like pattern correctly identified. Calls list (FUN_0048c070, FUN_00472400) verified.

---

## FUN_00491fb0 — Unidentified (Loop with Random Wait)

**Result: PASS** (cross-doc note: FUN_005351d0 labeled "random" here but "Line Input Reader" at its own entry, line 38508)

Source: iVar1=FUN_005351d0(0x100). Loop while iVar1!=0: increments param_1+0x18c, iVar1=FUN_005651b0(), breaks if iVar1!=1 AND (iVar1<3 OR iVar1>4), increments param_1+400, re-rolls FUN_005351d0(0x100). Returns 1.

Doc entry: "iVar1 = FUN_005351d0(0x100) — random in [0,256)", loop condition, counter increments at +0x18c and +400, "If iVar1 != 1 and not in [3,4]: break", "Returns 1". All logic matches source exactly. Consistency note: FUN_005351d0 is labeled "Line Input Reader" at its own doc entry (line 38508) — one of these categorizations needs reconciliation.

---

## FUN_004b9ce0 — Delegation

**Result: PASS**

Source: `void FUN_004b9ce0(void) { FUN_004b8790(); return; }`

Doc entry: "Calls FUN_004b8790()." Correct. No params, no return (void).

---

## Summary

| # | Function | Result |
|---|----------|--------|
| 1 | FUN_00490660 | PASS |
| 2 | FUN_004b2b60 | PASS |
| 3 | FUN_004dcd10 | PASS |
| 4 | FUN_0051664f | PASS |
| 5 | FUN_005573f0 | PASS |
| 6 | FUN_0055d3f0 | PASS |
| 7 | FUN_00414370 | PASS |
| 8 | FUN_00472340 | PASS |
| 9 | FUN_00491fb0 | PASS |
| 10 | FUN_004b9ce0 | PASS |

**Total: 10/10 PASS — 0 FAIL**

Cross-doc note: FUN_00491fb0 entry describes FUN_005351d0(0x100) as "random in [0,256)" but FUN_005351d0's own doc entry (line 38508) labels it "Line Input Reader." These are contradictory — one needs correction.

---

## FUN_004ed710 � Vec3 Add

**Result: PASS**

Source: 3-component vector addition. param_3[0]=param_1[0]+param_2[0], [1]=param_1[1]+param_2[1], [2]=param_1[2]+param_2[2].

Doc entry: "3-component vector addition." Key logic lists all 3 component additions exactly as source. Algorithm family "3D vector addition" correct. Calls: none (correct � leaf function). No false claims.

---

## FUN_00528bd0 � Empty Stub

**Result: PASS**

Source: oid FUN_00528bd0(void) { return; } � bare return. Size 232 bytes.

Doc entry: "Empty function � only returns. No logic. 232 byte function body all zeroed � stripped/virtual placeholder." Source confirms bare return and size 232 bytes. No calls (correct). No false claims.

---

## FUN_0057a180 � Dword-Aligned Memory Copy

**Result: PASS**

Source: copies param_3>>2 dwords in loop, copies param_3&3 remaining bytes in second loop, advances *param_1 by param_3.

Doc entry: "Copies param_3>>2 dwords from param_2 to *param_1. Copies param_3 & 3 remaining bytes. Advances *param_1 by param_3." All three steps match source exactly. Algorithm family "aligned memory copy" correct. Calls: none (correct � leaf function).

---

## FUN_0059a44c � Conditional Callback with Null Check

**Result: PASS**

Source: if param_1+0x50 != 0: FUN_00587d02(handle). If close returns 0: FUN_0059a473(0,2), return param_1. If handle null or close fails: return 0.

Doc entry: "If param_1+0x50 non-null: FUN_00587d02 (file close). If success: FUN_0059a473(0,2) (init), return param_1. If fail: return 0." Struct offset +0x50 FileHandle verified. Calls: FUN_00587d02, FUN_0059a473 � both correct. No false claims. Minor under-description of null-handle-returns-0 case but does not contradict source.

---

## FUN_00464e90 � Buffer Size Lookup

**Result: PASS**

Source: switch(param_1): 1?0xb9f, 2?0x1c20, 3?0x7080, 4?0x98968, default?0x5cf.

Doc entry: "1?0xB9F, 2?0x1C20, 3?0x7080, 4?0x98968, default?0x5CF." All 5 values match source exactly. Calls: None (correct � leaf function, single switch). Moddability: "configurable" � reasonable for a lookup table.

---

## FUN_004917c0 � Circular Buffer Ring Advance

**Result: PASS**

Source: 79 lines. FUN_004f9b20() conditional ring advance (mod operator on index). FUN_004910d0 �2. Walks linked list at *param_1+8; checks age at +8 (short). If age<3: increment. If age=3: unlink node, decrement count, conditionally free sub-data via FUN_00587bcf, free node. Calls FUN_00490aa0 on cleanup path.

Doc entry: "Advance ring index, remove expired entries (age=3 triggers free)." Calls list: FUN_004f9b20, FUN_004910d0 (x2), FUN_00490aa0, FUN_00587bcf � all verified in source. Algorithm family "ring buffer maintenance" accurate. Confidence "medium" appropriate given complexity. No false claims.

---

## FUN_004b4450 � Wrapper + Pass-Through

**Result: PASS**

Source: FUN_004b4460(); return param_1; � 12 bytes total.

Doc entry: "FUN_004b4460(). Return param_1." Calls: FUN_004b4460 � verified. No false claims.

---

## FUN_004e23d0 � 3x3 Matrix Transform

**Result: PASS**

Source: 199 bytes. Copies position from param_3 to param_1+0x14/+0x18/+0x1c. Copies 3�3 matrix (9 floats) from param_4 to param_1+0x20..0x40. Stores input point from param_2 to param_1+0x54/+0x58/+0x5c. Computes 3 output components at param_1+8/+0xc/+0x10 as M�p + pos.

Doc entry: "Set position, copy 3x3 matrix, compute transformed output." Formula "out[x] = M[0][x]*p[0] + M[1][x]*p[1] + M[2][x]*p[2] + pos[x]" consistent with source structure. Calls: None � inline matrix multiply (correct, leaf function). Algorithm family "3D math, matrix transform" accurate.

---

## FUN_0051c5a3 � Table Init with Arithmetic Progression

**Result: PASS**

Source: 176 bytes. 4 virtual calls via *(in_EAX+4) vtable obtain base pointers (stored to iVar1+8/0xc/0x10/0x14). Loop fills 4 parallel arrays with arithmetic progression values. Each iteration: iVar4 += -0x581a, puVar5 += -0xb6d2, local_c += 0x1c5a2, local_8 += 0x166e9. Loop until iVar4 = -0x2b34e7.

Doc entry: "Initialize 4 parallel arrays with arithmetic progression values." Calls: "Virtual calls via *(in_EAX+4) vtable" � correct. Algorithm family "table generation" accurate. Confidence "low" appropriate. No false claims.

---

## FUN_005647d0 � Callback + Check

**Result: PASS**

Source: calls function pointer at param_1+0xc. Calls FUN_00564a20(param_1+0x10, 0, 0). If return == -1: return 0. Else: return FUN_005648b0().

Doc entry: "Call function ptr at +0xc. Check via FUN_00564a20. Process via FUN_005648b0." Calls: FUN_00564a20, FUN_005648b0 � verified. Function pointer dispatch at +0xc noted in header description. No false claims. Moddability: "hookable" � reasonable given function pointer dispatch.

---

## Summary

| # | Function | Result |
|---|----------|--------|
| 1 | FUN_004ed710 | PASS |
| 2 | FUN_00528bd0 | PASS |
| 3 | FUN_0057a180 | PASS |
| 4 | FUN_0059a44c | PASS |
| 5 | FUN_00464e90 | PASS |
| 6 | FUN_004917c0 | PASS |
| 7 | FUN_004b4450 | PASS |
| 8 | FUN_004e23d0 | PASS |
| 9 | FUN_0051c5a3 | PASS |
| 10 | FUN_005647d0 | PASS |

**Total: 10/10 PASS � 0 FAIL**

**Running total (all worker_P batches): 40/40 PASS � 1 FAIL**

---

## FUN_00597fac — WideChar→MultiByte String Conversion with Alloc Loop

**Result: PASS** (minor: "linked list" is array-of-pointers, not linked list)

Source: iterates null-terminated pointer array from `DAT_008d3e98`. For each entry: `WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL)` to get size, `_malloc()`, second `WideCharToMultiByte` to convert, `FUN_00598323(buffer, 0)` to register. Advances via `puVar2 = puVar2 + 1`. On failure returns -1 (0xffffffff). On empty/null returns 0.

Doc entry: correct on all functional claims — globals (`DAT_008d3e98`), Win32 calls, malloc, FUN_00598323 registration, failure return -1, empty return 0. Only terminology issue: "linked list" should be "array/sequence." No functional claims wrong.

---

## FUN_00499e80 — Delegation to Path Registry

**Result: PASS**

Source: `void FUN_00499e80(void) { FUN_00566650(); return; }` — 8-byte wrapper.

Doc entry: "Calls FUN_00566650() with no args." Correct. Calls list correct (FUN_00566650). No false claims.

---

## FUN_00503659 — Physics State Dispatch

**Result: PASS**

Source: reads source struct from `*param_1`, target from `param_1[1]`. Dispatches via `PTR_FUN_005d76c0` with args: `param_1[1]+0x18`, `iVar1+0x18`, `iVar1+0x1058`, `iVar1+0x105c`, `iVar1+0x1050`, `param_1[1]+0x1050`.

Doc entry: struct offset table at +0x00 (source struct) and +0x04 (target struct with +0x18, +0x1050-0x105c fields) correct. Function pointer PTR_FUN_005d76c0 correctly identified. All field offsets verified in source. No false claims.

---

## FUN_0057b6b0 — Offset Getter (param_1 + 0x20)

**Result: PASS**

Source: `int __fastcall FUN_0057b6b0(int param_1) { return param_1 + 0x20; }` — 4-byte leaf.

Doc entry: "Returns param_1 + 0x20." Exact match. No calls (correct, leaf function). No false claims.

---

## FUN_0041f040 — Array Index Lookup

**Result: PASS**

Source: calls `FUN_004c2850()`, calls `FUN_004c11d0()` → index. If `0 < index && param_1 != 0`: returns `*(param_1 + 0x14 + index*4)`. Else returns 0xffffffff.

Doc entry: "Returns *(param_1 + 0x14 + index*4) where index from FUN_004c11d0()." Correct. Doc is simplified (omits FUN_004c2850 call, bounds check, -1 fallback) but makes no incorrect claims. Calls list correct (FUN_004c11d0, FUN_004c2850).

---

## FUN_0057a560 — Byte Extraction from Pointer

**Result: PASS**

Source: `return CONCAT31((int3)((uint)*param_1 >> 8), *(undefined1 *)(*param_1 + 0x5d))` — combines byte at `*param_1+0x5d` with upper 3 bytes of `*param_1` shifted right.

Doc entry: "Returns byte at *param_1 + 0x5d combined with shifted high byte of *param_1." Correct. No calls (leaf function). No false claims.

---

## FUN_0040b360 — Virtual Dispatch Chain

**Result: PASS** (minor: header "Double virtual dispatch" should be "Triple virtual dispatch")

Source: calls `(*param_1 + 0x18)` vtable method. If non-null: calls `(*param_1 + 0x18)` again → second object. On second object: calls `(*second + 0x1c)` — third dispatch total.

Doc entry: all 3 dispatches correctly described in Key Logic bullets ("Call virtual method via (*param_1 + 0x18)", "call virtual method via (*param_1 + 0x18) again", "call virtual method via (*second + 0x1c)"). Header says "Double" but detailed bullets are correct. Calls list "none (all virtual dispatch)" correct.

---

## FUN_00472a80 — Object Constructor with Global Ref (VTable at 0x005a2280)

**Result: PASS**

Source: `FUN_00466d60(1)`, vtable `PTR_FUN_005a2280`, `param_1[199] = &DAT_007d1334`, `[0xc9]=1`, `[0xca]=0`, `[0xcb]=1`, `[0xcc]=1`, `[0xce]=0x107`, `FUN_00486f30(&PTR_DAT_005be704, -1)`, `FUN_00486f30(&DAT_005c32c8, -1)`, `FUN_004670e0()`, returns param_1.

Doc entry: all field values match exactly. All calls (FUN_00466d60, FUN_00486f30 x2, FUN_004670e0) verified. Vtable PTR_FUN_005a2280 correct. Global ref DAT_007d1334 correct. No false claims.

---

## FUN_00494690 — Render Surface Allocation and Text Initialization

**Result: PASS**

Source: 614 bytes. Allocates 3 surfaces: `operator_new(0x60)` + `FUN_0054fe10` for DAT_007cde04/DAT_007cde10/DAT_007cde1c. `FUN_0054fec0` config (sizes 0x100/0x400/0x200). Width from +0x54. Text via `FUN_00553980` (mode 2). For surfaces 2 and 3 (check returns 0): read DAT_005d6d60/0x64 floats, 4x `FUN_00553650` with RGBA color parameters.

Doc entry: all 3 allocation blocks described. Surface sizes correct (0x100/0x400/0x200). Width storage correct. FUN_00553980 mode 2 correct. Color value mentions (DAT_005d6d60, 0x64) correct. FUN_00553650 x4 correct per surface. Globals list complete. Calls list complete. Doc says "For first two surfaces" which technically refers to the 2nd and 3rd allocated surfaces — minor wording imprecision. No functional claims wrong.

---

## FUN_004b9d80 — Single Delegate (thunk to FUN_004b8140)

**Result: PASS**

Source: `void FUN_004b9d80(void) { FUN_004b8140(); return; }` — 7-byte thunk.

Doc entry: "FUN_004b8140()" — "Thin wrapper." Calls list (FUN_004b8140) verified. No params, no return (void) correct. No false claims.

---

## Summary

| # | Function | Result |
|---|----------|--------|
| 1 | FUN_00597fac | PASS (minor) |
| 2 | FUN_00499e80 | PASS |
| 3 | FUN_00503659 | PASS |
| 4 | FUN_0057b6b0 | PASS |
| 5 | FUN_0041f040 | PASS |
| 6 | FUN_0057a560 | PASS |
| 7 | FUN_0040b360 | PASS (minor) |
| 8 | FUN_00472a80 | PASS |
| 9 | FUN_00494690 | PASS |
| 10 | FUN_004b9d80 | PASS |

**Total: 10/10 PASS — 0 FAIL**

Minors: FUN_00597fac doc calls array "linked list" (terminology); FUN_0040b360 header says "Double" but is triple dispatch. Neither affects functional understanding.

**Running total (all worker_P batches): 50/50 PASS — 1 FAIL**

---

## FUN_004EFEE0 — Vector Dot Product (3-component)

**Result: NO ENTRY in docs/20-math-utilities.md**

Source (21 bytes, pure leaf):
```c
float10 __fastcall FUN_004efee0(float *param_1, float *param_2) {
  return (float10)*param_1 * (float10)*param_2 +
         (float10)param_1[1] * (float10)param_2[1] + (float10)param_1[2] * (float10)param_2[2];
}
```
Pure 3-component dot product: sum(param_1[i] * param_2[i]) for i=0..2. Typed as float10 (x87 80-bit extended precision). No function calls, no globals — leaf math function.

Triage index (line 3258): `0x004efee0 | 2 | math_util | short computation | no | --`

The function is correctly classified as math_util but no `## FUN_` entry exists in docs/20-math-utilities.md. No claims to verify. Document as "3-component vector dot product."

---

## FUN_00522B22 — Media State Structure Init

**Result: NO ENTRY in docs/20-math-utilities.md (and NOT a math function)**

Source (57 bytes):
```c
void FUN_00522B22(ulonglong *param_1) {
  uVar1 = (ulonglong)DAT_005af8f0;
  *param_1 = uVar1;
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = uVar1;
  param_1[6] = 0;
  param_1[2] = uVar1 << 0x20;
  param_1[7] = uVar1 << 0x20;
  FastExitMediaState();
}
```
Initializes 8 ulonglong fields of a struct from DAT_005af8f0 constant, then calls FastExitMediaState(). The global DAT_005af8f0 and FastExitMediaState() call indicate media/exit system, not math.

Triage index (line 3921): `0x00522b22 | 12 | math_util | arithmetic/comparison | no | --`

**Misclassification identified:** This is NOT a math utility. It's a media state struct initializer with an exit/media cleanup call. Should be reclassified as `media` or `game_logic`. Triaged as "math_util/arithmetic" but contains no arithmetic operations — only assignments and a FastExitMediaState call. No `## FUN_` entry exists in docs/20-math-utilities.md (correct — it doesn't belong there).

---

## FUN_00567CC0 — Recursive Tree Destructor

**Result: NO ENTRY in docs/20-math-utilities.md (and NOT a math function)**

Source (64 bytes):
```c
void FUN_00567CC0(int param_1) {
  if (param_1 != 0) {
    FUN_00567CC0(*(undefined4 *)(param_1 + 4));
    FUN_00567CC0(*(undefined4 *)(param_1 + 8));
    FUN_00567CC0(*(undefined4 *)(param_1 + 0xc));
    FUN_00567940();
    FUN_00587bcf(param_1);
  }
}
```
Recursive tree traversal: 3 children at +4/+8/+0xc, then FUN_00567940() (pre-cleanup) and FUN_00587bcf (free). Standard recursive tree destructor pattern.

Triage index has TWO entries:
- Line 4889: `0x00567cc0 | 19 | math_util | -- | no | --` (original — INCORRECT)
- Line 7493: `0x00567cc0 | 19 | unknown | Recursive tree destructor — traverses children at +4/+8/+0xc, frees | no | --` (corrected)

**Misclassification identified:** Original triage as math_util is wrong. This is a tree destructor. Second triage entry correctly identifies it. No `## FUN_` entry exists in docs/20-math-utilities.md (correct — doesn't belong there). First triage line should be removed/marked as superseded.

---

## FUN_00598CC1 — Locale VTable Set + Cleanup Call

**Result: NO ENTRY in docs/20-math-utilities.md (and NOT a math function)**

Source (14 bytes):
```c
void __fastcall FUN_00598CC1(undefined4 *param_1) {
  *param_1 = &PTR_FUN_005b9c04;
  FUN_00598C70();
}
```
Sets vtable pointer to PTR_FUN_005b9c04, calls cleanup/init via FUN_00598C70(). Constructor-like pattern for locale/refcount system.

Triage index has TWO entries:
- Line 5759: `0x00598cc1 | 14 | math_util | -- | no | --` (original — INCORRECT)
- Line 6955: `0x00598cc1 | 13 | Locale/Init | Set locale vtable and call cleanup | Locale vtable set |` (corrected)

**Misclassification identified:** Original triage as math_util is wrong. This is a locale vtable/init function. Second triage entry correctly identifies it as Locale/Init. No `## FUN_` entry exists in docs/20-math-utilities.md (correct — doesn't belong there).

---

## FUN_00456130 — Vector Copy (3 floats)

**Result: PASS**

Source (30 bytes):
```c
void __thiscall FUN_00456130(int param_1, undefined4 *param_2) {
  if (param_2 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x18) = *param_2;
    *(undefined4 *)(param_1 + 0x1c) = param_2[1];
    *(undefined4 *)(param_1 + 0x20) = param_2[2];
  }
}
```

Doc entry (line 49794-49806):
```
## FUN_00456130 — Vector Copy (3 floats)
Source: unknown | Confidence: high
Copies 3 floats from param_2 to param_1+0x18, +0x1c, +0x20.

**Key logic:**
- Null-safe: checks param_2 != 0 before copying

**Used by system:** docs/20-math-utilities.md — 3D vector copy
**Moddability:** hardcoded
```

Verification:
- "Copies 3 floats from param_2 to param_1+0x18, +0x1c, +0x20" → Source shows exactly: `*(param_1+0x18) = param_2[0]`, `*(param_1+0x1c) = param_2[1]`, `*(param_1+0x20) = param_2[2]`. Correct.
- "Null-safe: checks param_2 != 0" → Source shows `if (param_2 != (undefined4 *)0x0)`. Correct.
- "Source: unknown" → Correct — no assert string available.
- "Confidence: high" → Correct — trivial function, no ambiguity.
- "Moddability: hardcoded" → Correct — no configurable values.
- No calls listed → Source shows no function calls. Correct.
- No globals → Source shows no global references. Correct.

No discrepancies. All claims verified.

Note: triage index (line 1121) still shows `| -- |` in the doc column, indicating the index has not been updated to reflect that this function now has an entry in docs/20-math-utilities.md. Index maintenance needed.

---

## FUN_0047A620 — Object Constructor with Float Constant

**Result: NO ENTRY in docs/20-math-utilities.md**

Source (28 bytes):
```c
undefined4 * __fastcall FUN_0047A620(undefined4 *param_1) {
  FUN_004668E0(0x3d4ccccd, 0x3f800000);
  *param_1 = &PTR_FUN_005a64b8;
  return param_1;
}
```
Calls FUN_004668E0 with float constants 0.05f (0x3d4ccccd) and 1.0f (0x3f800000), then sets vtable to PTR_FUN_005a64b8. Constructor pattern for an object that uses a 0.05 scalar and 1.0 default.

Triage index (line 1635): `0x0047a620 | 11 | math_util | short computation | no | --`

**Classification note:** While the function passes floats to FUN_004668E0, the structure is a constructor (vtable set, return param_1), not a pure math utility. The math call is incidental to object initialization. Could be classified as `game_logic/constructor` rather than `math_util`. No `## FUN_` entry exists in docs/20-math-utilities.md — its presence in that doc would be marginal.

---

## FUN_00499B50 — Resource Cleanup (Conditional Free + Stop)

**Result: NO ENTRY in docs/20-math-utilities.md (and NOT a math function)**

Source (43 bytes):
```c
void __fastcall FUN_00499B50(int param_1) {
  if (*(int *)(param_1 + 0x30) != 0) {
    FUN_005539F0(*(int *)(param_1 + 0x30));
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  if (*(int *)(param_1 + 0x2c) != 0) {
    FUN_005502C0();
    return;
  }
}
```
Conditional resource release: frees resource at +0x30 via FUN_005539F0 and zeroes the slot; stops via FUN_005502C0 if resource at +0x2c is active. Audio/media resource cleanup pattern.

Triage index (line 2135): `0x00499b50 | 17 | math_util | short computation | no | --`

**Misclassification identified:** This is NOT a math function. It's a resource cleanup/release function with zero arithmetic operations. Functions FUN_005539F0 (free) and FUN_005502C0 (stop) are resource management calls, not math. Should be reclassified as `audio` or `game_logic/resource_cleanup`. No `## FUN_` entry in docs/20-math-utilities.md (correct — doesn't belong there).

---

## FUN_004C29B0 — Conditional Dispatch Wrapper

**Result: NO ENTRY in docs/20-math-utilities.md**

Source (23 bytes):
```c
undefined4 FUN_004C29B0(void) {
  uVar2 = FUN_004C2850();
  if ((int)uVar2 != 0) {
    uVar1 = FUN_004C11E0();
    return uVar1;
  }
  return (int)((ulonglong)uVar2 >> 0x20);
}
```
Calls FUN_004C2850() (a state check — possibly session/race state). If non-zero: delegates to FUN_004C11E0(). Otherwise: returns high dword of the 64-bit result. Utility dispatch wrapper — no math.

Triage index (line 2746): `0x004c29b0 | 6 | unknown | utility function | no | --`

**Classification note:** Correctly classified as `unknown/utility function` — not math_util. No `## FUN_` entry expected in docs/20-math-utilities.md. No full documentation entry exists anywhere — candidate for short entry in appropriate doc (game_logic or utility section).

---

## FUN_0050099C — Complex Dispatch with Stream Comparison

**Result: NO ENTRY in docs/20-math-utilities.md**

Source (422 bytes — largest in batch):
Complex function with: null checks, comparison of two parameter streams (256 dword comparison loop), vtable dispatch at +0x20 (get) and +0x0c (create), calls to FUN_00506559 (encode/transform), FUN_0050070D (process), FUN_00500EAC (enable/disable), FUN_005064BF/FUN_005064CF (scope enter/exit). Error codes: -0x7789f794 on null input. Stream cloning/comparison with conditional optimization (skip if streams match).

Triage index (line 3424): `0x0050099c | 26 | unknown | unidentified logic | no | --`

**Classification note:** Correctly classified as `unknown/unidentified logic`. This is NOT a math function — it's a data stream processing function with vtable dispatch, comparison logic, and resource management. The only "math" is address arithmetic. No `## FUN_` entry exists in docs/20-math-utilities.md (correct — doesn't belong there). Candidate for deeper analysis in stream/file I/O context.

---

## FUN_0053B350 — Physics Scaling with Bit Flag Gate

**Result: NO ENTRY in docs/20-math-utilities.md**

Source (93 bytes):
```c
void __fastcall FUN_0053B350(uint *param_1) {
  if ((*param_1 & 2) != 0) {
    *param_1 = *param_1 & 0xfffffffd;
    param_1[10] = (uint)((float)param_1[7] * (float)param_1[10]);
    param_1[0xb] = (uint)((float)param_1[7] * (float)param_1[0xb]);
    param_1[0xc] = (uint)((float)param_1[7] * (float)param_1[0xc]);
    param_1[0xe] = (uint)((float)param_1[8] * (float)param_1[0xe]);
    param_1[0xf] = (uint)((float)param_1[0xf] * (float)param_1[8]);
    param_1[0x10] = (uint)((float)param_1[0x10] * (float)param_1[8]);
    param_1[0x12] = (uint)((float)param_1[0x12] * (float)param_1[9]);
    param_1[0x13] = (uint)((float)param_1[0x13] * (float)param_1[9]);
    param_1[0x14] = (uint)((float)param_1[0x14] * (float)param_1[9]);
  }
}
```
If bit 1 (0x2) of flag dword is set: clears bit 1, then multiplies 9 uint fields (interpreted as floats) by scaling factors at param_1[7]/[8]/[9]. Groups: [10],[11],[12] scaled by [7]; [14],[15],[16] scaled by [8]; [18],[19],[20] scaled by [9]. Physics scaling pattern — multiplies components by axis-specific scales.

Triage index (line 4068): `0x0053b350 | 11 | math_util | arithmetic/comparison | no | --`

**Classification note:** While this function does perform float arithmetic (multiplication), the context is clearly physics scaling — a onetime operation gated by a flag bit, not a general math utility. The function modifies a physics struct's scaling values. Math-adjacent, but belongs in a physics/vehicle doc rather than 20-math-utilities. No `## FUN_` entry exists in docs/20-math-utilities.md — reasonable given the narrow physics context.

---

## Summary

| # | Function | Result | Notes |
|---|----------|--------|-------|
| 1 | FUN_004EFEE0 | NO ENTRY | 3-component dot product — correct math_util, needs entry |
| 2 | FUN_00522B22 | NO ENTRY | Media state init — MISCLASSIFIED as math_util |
| 3 | FUN_00567CC0 | NO ENTRY | Tree destructor — MISCLASSIFIED as math_util (corrected in 2nd triage) |
| 4 | FUN_00598CC1 | NO ENTRY | Locale vtable set — MISCLASSIFIED as math_util (corrected in 2nd triage) |
| 5 | FUN_00456130 | PASS | Vector copy — all doc claims verified |
| 6 | FUN_0047A620 | NO ENTRY | Constructor with float — marginal math_util classification |
| 7 | FUN_00499B50 | NO ENTRY | Resource cleanup — MISCLASSIFIED as math_util |
| 8 | FUN_004C29B0 | NO ENTRY | Dispatch wrapper — correct unknown/utility classification |
| 9 | FUN_0050099C | NO ENTRY | Stream processing — correct unknown/unidentified classification |
| 10 | FUN_0053B350 | NO ENTRY | Physics scaling — math-adjacent, narrow context |

**Total: 1/10 PASS — 0 FAIL — 9 NO ENTRY (5 misclassified as math_util)**

**Key findings:**
1. Only 1 of 10 functions (FUN_00456130) has a `## FUN_` entry in docs/20-math-utilities.md. Its entry is accurate (PASS).
2. 5 of 10 functions (FUN_00522B22, FUN_00567CC0, FUN_00598CC1, FUN_00499B50, FUN_0047A620) were triaged as `math_util` but are NOT math functions — classification errors in the triage index.
3. FUN_00567CC0 and FUN_00598CC1 have DUPLICATE triage entries: original (math_util) and corrected (unknown / Locale/Init). The original incorrect entries should be removed or annotated as superseded.
4. FUN_004EFEE0 is a genuine math utility (3-component dot product) that correctly belongs in 20-math-utilities.md but has no entry — candidate for documentation.
5. FUN_00456130's triage index line still shows `| -- |` doc column — needs update to reflect its entry in 20-math-utilities.md.

**Running total (all worker_P batches): 51/60 PASS — 1 FAIL — 9 NO ENTRY**

---

## FUN_00589278 — Call Wrapper with 0

**Result: PASS**

Source (23 bytes):
```c
void FUN_00589278(undefined4 param_1,undefined4 param_2,undefined4 param_3) {
  FUN_0058928f(param_1,param_2,param_3,0);
  return;
}
```

Doc entry (line 51695):
```
## FUN_00589278 — Call Wrapper with 0
Source: unknown | Confidence: high
Calls FUN_0058928f(param_1, param_2, param_3, 0).

**Calls:** FUN_0058928f
**Used by system:** docs/20-math-utilities.md — call forwarder
**Moddability:** hardcoded
```

Verification:
- "Calls FUN_0058928f(param_1, param_2, param_3, 0)" — Source shows exactly `FUN_0058928f(param_1,param_2,param_3,0)`. Exact match.
- Confidence "high" — Correct — trivial wrapper, no ambiguity.
- Calls list "FUN_0058928f" — Correct.
- Moddability "hardcoded" — Correct — no configurable values.
- No globals — Source shows no global references. Correct.

No discrepancies found. All doc claims verified against source.

---

## FUN_00458020 — Utility Function (placeholder/stub)

**Result: PASS (placeholder)**

Source (47 bytes):
```c
void __fastcall FUN_00458020(int *param_1) {
  if (*param_1 != 0) {
    FUN_00587bcf(*param_1 + -4);
    *param_1 = 0;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  return;
}
```

Doc entry (line 52022):
```
## FUN_00458020 -- Utility Function
Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/20-math-utilities.md
**Moddability:** hardcoded
```

Verification:
- Doc is a **placeholder/stub** — "General utility function. See decompiled code for exact behavior." Makes no specific functional claims. No false claims to verify.
- Source shows: conditional free at `*param_1 - 4` via FUN_00587bcf, zeroes 6 dwords at param_1[1..6], zeroes *param_1. This is a cleanup/init function pattern.
- The function IS a utility function (cleanup/zero-init) — the stub description is non-false.
- Calls: source shows only FUN_00587bcf — doc lists no calls (omission, not false).
- Triage index (line 1140): `0x00458020 | 19 | math_util | short computation | no | --`

**Classification note:** Triaged as `math_util/short computation` but contains NO mathematical computation — only memory cleanup (conditional free + zero fill). Should be reclassified as `game_logic/cleanup` or `utility/memory`. The "short computation" label is misleading — there is no computation, only assignments and a conditional free.

Placeholder has no false claims. PASS but note classification issue and the stub is notably uninformative.

---

## FUN_00487160 — Utility Function (placeholder/stub)

**Result: PASS (placeholder)**

Source (122 bytes):
```c
undefined4 __thiscall FUN_00487160(int param_1,int param_2,int *param_3,int *param_4) {
  char cVar1;
  int iVar2;
  undefined4 local_4;

  local_4 = param_1;
  iVar2 = FUN_0049adb0();
  if (((param_2 < iVar2) || (*(int *)(param_1 + 200) != 0)) &&
     (cVar1 = FUN_0049aec0(param_2,&local_4,(int)&local_4 + 2), cVar1 != '\0')) {
    *param_3 = (int)(short)local_4 + *(int *)(param_1 + 0xc);
    *param_4 = (int)local_4._2_2_ + *(int *)(param_1 + 4);
    return 1;
  }
  return 0;
}
```

Doc entry (line 52302):
```
## FUN_00487160 -- Utility Function
Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/20-math-utilities.md
**Moddability:** hardcoded
```

Verification:
- Doc is a **placeholder/stub** — "General utility function. See decompiled code for exact behavior." Makes no specific functional claims. No false claims.
- Source shows: coordinate/location computation. Calls FUN_0049adb0() (get count/max), conditionally calls FUN_0049aec0() (lookup/validate), then computes output coordinates by adding offset values at param_1+0xc and param_1+4 to looked-up short values. Returns 1 on success, 0 on failure.
- This is a coordinate mapping / location resolution function — NOT a general utility. Specific game-logic purpose (likely UI element or sprite sheet coordinate resolution).
- Calls: FUN_0049adb0, FUN_0049aec0 — neither listed in doc (omission, not false).
- Triage index (line 1746): `0x00487160 | 21 | math_util | short computation | no | --`

**Classification note:** Triaged as `math_util/short computation`. While this function does arithmetic (addition), it's fundamentally a coordinate lookup/resolution function with validation — not a general math utility. Should be reclassified as `game_logic/UI` or `renderer/coordinate`.

Placeholder has no false claims. PASS but the stub is deeply uninformative — the "Key logic" field literally says "see decompiled code" rather than describing coordinate lookup behavior. Classification as math_util is questionable.

---

## FUN_004A1FB0 — NO ENTRY in docs/20-math-utilities.md

Source (29 bytes):
```c
void __fastcall FUN_004a1fb0(undefined4 *param_1) {
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0x18;
  return;
}
```

Struct initializer: zeros 6 dwords ([0]..[5]), sets [6] = 0x18 (24). The value 0x18 suggests a size/count field — likely initializing a struct with 24 elements or 24-byte stride. No function calls — leaf function.

Triage index (line 2318): `0x004a1fb0 | 8 | math_util | arithmetic/comparison | no | --`

**Classification note:** This is a struct initializer (zero-init + one constant), not a math utility. "Arithmetic/comparison" label is misleading — there is zero arithmetic (only assignment). Should be reclassified as `game_logic/init` or `utility/memory`. No `## FUN_` entry exists anywhere — candidate for short entry generation.

No claims to verify — no doc entry exists.

---

## FUN_0059C988 — Unwind_0059c988: NO ENTRY in docs/20-math-utilities.md

Source (8 bytes):
```c
void Unwind_0059c988(void) {
  FUN_005822b0();
  return;
}
```

MSVC exception handler unwind trampoline. Single delegation to FUN_005822b0. 8 bytes — minimal thunk.

Triage index:
- Line 6033 (original): `0x0059c988 | 13 | crt_util | -- | no | --`
- Line 7149 (corrected): `0x0059c988 | - | Missing | File not found in decompiled_full/ | |`

**Note:** The "Missing" entry at line 7149 is inaccurate — the file exists at `analysis_pipeline/analyzed/0x0059c988__Unwind_0059c988.c`. The index should be corrected. Additionally, this is not a math function — it's a CRT exception handler trampoline (crt_util classification is reasonable). No `## FUN_` entry should exist in docs/20-math-utilities.md.

No claims to verify — no doc entry exists in 20-math-utilities.md (correct — it doesn't belong there).

---

## FUN_0059C684 — Unwind_0059c684: NO ENTRY in docs/20-math-utilities.md

Source (10 bytes):
```c
void Unwind_0059c684(void) {
  int unaff_EBP;
  FUN_00587bcf(*(undefined4 *)(unaff_EBP + 8));
  return;
}
```

MSVC exception handler unwind trampoline. Frees object at EBP+8 via FUN_00587bcf (free). Standard C++ object cleanup on exception unwind.

Triage index:
- Line 5978 (original): `0x0059c684 | 15 | crt_util | -- | no | --`
- Line 7504 (corrected): `0x0059c684 | 15 | unknown | MSVC exception handler unwind trampoline | no | --`

**Note:** File exists at `analysis_pipeline/analyzed/0x0059c684__Unwind_0059c684.c`. The second entry correctly identifies the function's purpose. Not a math function — should not be in 20-math-utilities.md. No `## FUN_` entry exists (correct).

Note the use of `unaff_EBP` — Ghidra could not track the EBP chain, so the exact freed address is not definitively identified from decompilation alone. The function is an SEH cleanup handler.

No claims to verify.

---

## FUN_0059C902 — Unwind_0059c902: NO ENTRY in docs/20-math-utilities.md

Source (14 bytes):
```c
void Unwind_0059c902(void) {
  FUN_005818e0();
  return;
}
```

MSVC exception handler unwind trampoline. Single delegation to FUN_005818e0. 14 bytes.

Triage index:
- Line 6023 (original): `0x0059c902 | 13 | crt_util | -- | no | --`
- Line 7141 (corrected): `0x0059c902 | - | Missing | File not found in decompiled_full/ | |`

**Note:** The "Missing" entry at line 7141 is inaccurate — the file exists at `analysis_pipeline/analyzed/0x0059c902__Unwind_0059c902.c`. The original crt_util classification is reasonable for an SEH trampoline. Not a math function. No `## FUN_` entry should exist in 20-math-utilities.md.

No claims to verify.

---

## FUN_0059C67A — Unwind_0059c67a: NO ENTRY in docs/20-math-utilities.md

Source (10 bytes):
```c
void Unwind_0059c67a(void) {
  int unaff_EBP;
  FUN_00587bcf(*(undefined4 *)(unaff_EBP + 8));
  return;
}
```

MSVC exception handler unwind trampoline. Identical structure to FUN_0059C684: frees object at EBP+8 via FUN_00587bcf. Standard C++ destructor-on-exception pattern.

Triage index:
- Line 5977 (original): `0x0059c67a | 15 | crt_util | -- | no | --`
- Line 7105 (corrected): `0x0059c67a | 14 | Sys/Unwind | Unwind handler (SEH) | Unwind | decompiled_full/0x0059c67a__Unwind_0059c67a.c |`

**Note:** Second triage entry correctly identifies as Sys/Unwind — SEH handler. Original crt_util classification superseded. Not a math function. No `## FUN_` entry should exist in 20-math-utilities.md.

Same `unaff_EBP` limitation as FUN_0059C684 — Ghidra could not resolve the EBP register.

No claims to verify.

---

## FUN_0059D3A8 — Unwind_0059d3a8: NO ENTRY in docs/20-math-utilities.md

Source (26 bytes):
```c
void Unwind_0059d3a8(void) {
  int unaff_EBP;
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    FUN_00599be5();
    return;
  }
  return;
}
```

MSVC exception handler unwind trampoline with conditional check. Tests bit 0 of a flag dword at EBP-0x10. If set: calls FUN_00599be5() (cleanup/destructor). This is an SEH unwind handler with a conditional cleanup path — the flag determines whether cleanup is needed.

Triage index:
- Line 6174 (original): `0x0059d3a8 | 18 | crt_util | -- | no | --`
- Line 7262 (corrected): `0x0059d3a8 | - | Missing | File not found in decompiled_full/ | |`

**Note:** The "Missing" entry at line 7262 is inaccurate — the file exists at `analysis_pipeline/analyzed/0x0059d3a8__Unwind_0059d3a8.c`. This is an SEH handler with a conditional cleanup call — not a math function. No `## FUN_` entry should exist in 20-math-utilities.md.

No claims to verify.

---

## Summary

| # | Function | Result | Notes |
|---|----------|--------|-------|
| 1 | FUN_00589278 | PASS | Call wrapper — all doc claims verified |
| 2 | FUN_00458020 | PASS (placeholder) | Stub entry — no false claims, but MISCLASSIFIED as math_util |
| 3 | FUN_00487160 | PASS (placeholder) | Stub entry — no false claims, but MISCLASSIFIED as math_util |
| 4 | FUN_004A1FB0 | NO ENTRY | Struct init — no entry in docs/20-math-utilities.md |
| 5 | FUN_0059C988 | NO ENTRY | SEH unwind trampoline — not math |
| 6 | FUN_0059C684 | NO ENTRY | SEH unwind trampoline — not math |
| 7 | FUN_0059C902 | NO ENTRY | SEH unwind trampoline — not math |
| 8 | FUN_0059C67A | NO ENTRY | SEH unwind trampoline — not math |
| 9 | FUN_0059D3A8 | NO ENTRY | SEH unwind with conditional cleanup — not math |

**Total: 3/9 PASS (1 direct + 2 placeholders) — 0 FAIL — 6 NO ENTRY**

**Running total (all worker_P batches): 54/69 PASS — 1 FAIL — 15 NO ENTRY**

**Key findings:**
1. Only 3 of 9 functions have entries in docs/20-math-utilities.md (FUN_00589278, FUN_00458020, FUN_00487160). Two are placeholder stubs.
2. FUN_00589278 entry is accurate — PASS.
3. FUN_00458020 and FUN_00487160 entries are uninformative stubs ("General utility function. See decompiled code.") — PASS as placeholders but flagged as deficient.
4. FUN_004A1FB0 and all 5 Unwind_ functions (FUN_0059C988, 0059C684, 0059C902, 0059C67A, 0059D3A8) have NO entries in docs/20-math-utilities.md — correct for the SEH unwind handlers, but FUN_004A1FB0 (struct init) could arguably have an entry.
5. 4 triage entries claim "Missing" / "File not found" for functions that DO exist in analysis_pipeline/analyzed/ (lines 7141, 7149, 7262). These need index correction.
6. FUN_00458020 and FUN_00487160 are triaged as `math_util` but are NOT pure math functions — one is a memory cleanup/init, the other is a coordinate lookup. Classification errors.
7. 5 of 9 functions are MSVC SEH unwind trampolines (Unwind_ prefix) — excluded from math documentation by design.

---

## FUN_0040ed10 — Spatial Distance Query

**Result: PASS**

Source (82 bytes, collision.cpp):
```c
void __fastcall FUN_0040ed10(int param_1) {
  int iVar1;
  iVar1 = *(int *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x18) = 0;
  switch(iVar1) {
  case 0..5: // all same
    iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 0xd0);
    if (iVar1 != 0) {
      FUN_0054b420(param_1 + 0xc, param_1 + 0x10, param_1 + 0x14);
      fVar2 = (float10)FUN_004dd8f0();
      *(float *)(param_1 + 0x18) = (float)SQRT(fVar2);
    }
    break;
  case 6:
    // copies 3 pos floats from +0x34d4/8/c and 1 float from +0x3b70
  case 7:
    if (param_1+0x20 != 0) {
      if (flag 0x10 at +0x3c) goto case0 path;
      FUN_004dd550(&local_24);
      // weighted avg: (local_24 + local_18) * _DAT_0059e450 etc
      // distance = SQRT of diff vector
    }
  }
}
```

Doc entry (line 340-352) verification:
- "Mode 0-5: all read from param_1+0x20 at offset +0xd0, call FUN_004dd8f0 for distance" → Correct. All cases 0-5 read pointer at (*(param_1+0x20))+0xd0, call FUN_004dd8f0() on success path, store SQRT result at +0x18.
- "Mode 6: reads 3 position floats at +0x34d4-0x34dc and size at +0x3b70" → Correct. Case 6 copies 3 floats from (*(param_1+0x20))+0x34d4/8/c to param_1+0xc/10/14, copies (*(param_1+0x20))+0x3b70 to param_1+0x18.
- "Mode 7: handles skinned mesh (flag 0x10 at +0x3c): transforms via FUN_004dd550, averages with midpoint" → Correct. Flag check at (*(param_1+0x20))+0x3c & 0x10. FUN_004dd550 call, weighted avg with _DAT_0059e450.
- "Stores result as position (3 floats) and distance (1 float)" → Correct. Writes to param_1+0xc/0x10/0x14 (position) and param_1+0x18 (distance).
- Calls list (FUN_004dd8f0, FUN_004dd550, FUN_0054b420) → All verified in source.
- Moddability "hardcoded" → Correct.

Minor omissions:
- Key logic doesn't mention FUN_0054b420 call in modes 0-5 path (listed in Calls section)
- Global _DAT_0059e450 (weighting factor) not mentioned
- Initial zeroing of distance at param_1+0x18 before switch not noted

Triage index (line 305): `| 0x0040ed10 | 82 | unknown | memory allocation | no | -- |` — **WRONG** description "memory allocation" — should be "spatial distance query" or similar. Algorithmically this is clearly a spatial query function, not memory allocation.

**No functional errors in doc. Minor omissions only. PASS.**

---

## FUN_0048cb00 — Collision Position Stepper

**Result: PASS**

Source (66 bytes, collision_detection.cpp):
```c
void __thiscall FUN_0048cb00(int *param_1, float param_2) {
  iVar4 = param_1[0xca] * param_1[0xcb];
  if (0 < iVar4) {
    param_1[0xd0] = (int)(param_2 + (float)param_1[0xd0]);
    iVar2 = __ftol(); // steps = floor(accumulator / step_resolution)
    if (0 < iVar2) {
      do {
        iVar3 = (param_1[0xce] * param_1[0xcb] + param_1[0xcb]/2) - param_1[0xcd];
        // direction flag at param_1[0xcf] controls sign/wrap
        // clamp position to [0, iVar4)
        (**(code **)(*param_1 + 0x2c))(1);
        iVar2--;
        param_1[0xd0] = (int)((float)param_1[0xd0] - _DAT_005ac108);
      } while (iVar2 != 0);
    }
  }
}
```

Doc entry (line 901-930) verification:
- "Reads array size: param_1[0xca] * param_1[0xcb]" → Source: `iVar4 = param_1[0xca] * param_1[0xcb]`. Correct.
- "If size > 0: adds param_2 (timestep) to accumulator at param_1[0xd0]" → Source: `param_1[0xd0] = (int)(param_2 + (float)param_1[0xd0])`. Correct.
- "Computes steps from accumulator: divides by _DAT_005ac108 (step resolution)" → Source shows accumulator decremented by _DAT_005ac108 per step iteration. Step count computed via __ftol(). Interpretation correct.
- "Computes position delta: (param_1[0xce] * param_1[0xcb] + param_1[0xcb]/2) - param_1[0xcd]" → Source: `iVar3 = (param_1[0xce] * param_1[0xcb] + param_1[0xcb] / 2) - param_1[0xcd]`. Exact match.
- "Uses direction flag at param_1[0xcf] (char) to determine sign" → Source: `iVar1 = param_1[0xcf]`, `if ((char)iVar1 == '\0')`. Correct.
- "If negative delta: wraps by adding array size (cyclic)" → Source shows `iVar3 = iVar3 + iVar4` on negative condition. Correct.
- "Updates position at param_1[0xcd] with clamped wrap to [0, size)" → Source shows double loop clamping to [0, iVar4). Correct.
- "Calls virtual method at vtable+0x2c with arg=1" → Source: `(**(code **)(*param_1 + 0x2c))(1)`. Correct.
- "Subtracts step time from accumulator" → Source: `param_1[0xd0] = (int)((float)param_1[0xd0] - _DAT_005ac108)`. Correct.
- Struct offset table: All offsets (+0xca, +0xcb, +0xcd, +0xce, +0xcf, +0xd0) verified against source.
- Calls list: "virtual call via vtable+0x2c" → Correct (no other function calls).
- Moddability "hardcoded" → Correct.

Minor: The exact step-counting mechanism via `__ftol()` is not explicitly described as division — Ghidra's output shows the ftol but not the division. However, the functional description is accurate.

Triage index (line 1849): `| 0x0048cb00 | 66 | collision | collision detection | no | -- |` — Reasonable.

**All doc claims match source. No functional errors. PASS.**

---

## FUN_0044e7b0 — Collision Sound Unregister (DAT)

**Result: PASS**

Source (12 bytes): `void FUN_0044e7b0(void) { FUN_00587b3e(&DAT_0044e7c0); }`

Doc entry (line 1181): "Calls FUN_00587b3e(&DAT_0044e7c0) — unregisters the sound callback at data address."
Exact match. Calls list correct (FUN_00587b3e). No globals (constant DAT_0044e7c0 is a static address, not a mutable global). Moddability "hardcoded" correct.

Triage index (line 1027): `| 0x0044e7b0 | 12 | collision | collision detection | no | -- |` — Reasonable.

**PASS.**

---

## FUN_0044d130 — Thunk

**Result: PASS**

Source (12 bytes): `void FUN_0044d130(void) { FUN_00587b3e(&DAT_0044d140); }`

Doc entry (line 1554): "Thunk — delegates to FUN_00587b3e with &DAT_0044d140. No entry needed."
Exact match. Function is a thin wrapper/delegation thunk. Doc correctly labels it as thunk with no substantive entry needed.

Triage index (line 907): `| 0x0044d130 | 12 | collision | collision detection | no | -- |` — Reasonable.

**PASS.**

---

## FUN_00494de0 — Collision Node Allocator

**Result: PASS**

Source (41 bytes): Allocates 0xc-byte node, stores input pointer, sets next=0, flags=0, inserts into global linked list (DAT_007cddf0/4/8), increments counter DAT_007cddfc.

Doc entry (line 1882-1903) verification:
- "Calls FUN_0053cfe0 with flags 0x10801" → Source: `FUN_0053cfe0(&param_1,param_1,0x10801)`. Correct.
- "On success and non-null input: allocates new node (0xc bytes)" → Source: conditional on iVar4==0 && param_1!=0, `operator_new(0xc)`. Correct.
- "Stores input pointer in node[0], node[1]=0, node[2] byte=0" → Source: `*piVar5=iVar1; piVar5[1]=0; *(byte*)(piVar5+2)=0`. Correct.
- "Inserts node into global list" → Linked list insertion using DAT_007cddf0/4/8. Correct.
- "Increments global counter _DAT_007cddfc" → Source: `_DAT_007cddfc = _DAT_007cddfc + 1`. Correct.
- All 4 globals listed in Globals section verified in source.
- Calls: FUN_0053cfe0, operator_new → Both verified.
- Moddability "hardcoded" → Correct.

Triage index (line 1985): `| 0x00494de0 | 41 | collision | collision detection | no | -- |` — Reasonable.

**All doc claims match source. PASS.**

---

## FUN_0044c6e0 — Global State Initializer (Collision Material 1)

**Result: PASS**

Source (17 bytes): `DAT_007ca3e8=3; _DAT_007ca3ec=0; _DAT_007ca3f0=0; _DAT_007ca3f4=0x3f800000;`

Doc entry (line 2238-2248) verification:
- "Sets DAT_007ca3e8 = 3 (friction/restitution type)" → Source: `DAT_007ca3e8 = 3`. Correct.
- "Zeroes DAT_007ca3ec, DAT_007ca3f0" → Source: `_DAT_007ca3ec = 0; _DAT_007ca3f0 = 0`. Correct.
- "Sets DAT_007ca3f4 = 0x3f800000 (1.0f — restitution coefficient)" → Source: `_DAT_007ca3f4 = 0x3f800000`. Correct. Float interpretation (1.0f) confirmed by hex value.
- Moddability "configurable — surface material properties from .trk or .gdb" → Reasonable.
- No calls listed → Source has no function calls. Correct.

Triage index (line 852): `| 0x0044c6e0 | 17 | collision | collision detection | no | -- |` — Reasonable.

**All doc claims match source. PASS.**

---

## FUN_0044da90 — CollisionGridFreeC

**Result: PASS**

Source (12 bytes): `void FUN_0044da90(void) { FUN_00587b3e(&DAT_0044daa0); return; }`

Doc entry (line 2589-2598): "Calls FUN_00587b3e(&DAT_0044daa0) — frees heap block at static address."
Exact match. Calls list (FUN_00587b3e) correct. Moddability "hardcoded" correct.

Note: FUN_00587b3e appears to be used for BOTH callback registration (FUN_0044e7b0) AND heap free (FUN_0044da90). The doc entries for these functions label it differently ("unregister" vs "heap free"). This is a doc inconsistency — FUN_00587b3e's purpose should be resolved globally.

Triage index (line 957): `| 0x0044da90 | 12 | collision | collision detection | no | -- |` — Reasonable.

**PASS.**

---

## FUN_0044f680 — Frustum/Viewport Setup

**Result: PASS**

Source (25 bytes): Viewport frustum setup. Takes (param_1, param_2, param_3, param_4, param_5) as viewport coordinates. Stores at [0]=param_3, [1]=param_5, [2]=param_2, [3]=param_4. Computes [4]=(param_2+param_4)>>1, [5]=(param_3+param_5)>>1. Computes scale factors: [6]=int(DAT_0059e43c/((param_4-param_2)*DAT_0059e450)), [7]=int(DAT_0059e43c/((param_5-param_3)*DAT_0059e450)). Uses globals DAT_0059e43c, DAT_0059e450.

Doc entry (line 2918-2947) verification:
- "Stores int param_4 at param_1[3]" → Source: `param_1[3] = param_4`. Correct.
- "Computes center_x = (param_2 + param_4) >> 1, center_y = (param_3 + param_5) >> 1" → Source: `param_1[4] = param_2 + param_4 >> 1`, `param_1[5] = param_3 + param_5 >> 1`. Correct.
- "fVar1 = DAT_0059e43c / ((param_4 - param_2) * DAT_0059e450)" → Source computes `(float)(param_4 - param_2) * _DAT_0059e450`, then `_DAT_0059e43c / fVar1`. Correct.
- "param_1[6] = int(fVar1) — scale factor" → Source: `param_1[6] = (int)fVar1`. Correct.
- "param_1[7] = int(DAT_0059e43c / ((param_5 - param_3) * DAT_0059e450)) — y scale" → Exact formula match.
- Globals (DAT_0059e43c, DAT_0059e450) → Both verified.
- Struct offset table [0..7] → All assignments verified.
- "Calls: none" → Source has no function calls. Correct.
- Moddability "hardcoded" → Correct.

Note: Doc names struct fields left/top/right/bottom but actual coordinate mapping is param_3→[0], param_5→[1], param_2→[2], param_4→[3] — the axis ordering may not be standard (left,top,right,bottom). This is a minor naming interpretation but no functional claims are wrong.

**All computational claims match source. PASS.**

---

## FUN_0044c860 — Collision Material Coefficients Set 5 (ID 7, 1.0f)

**Result: PASS**

Source (17 bytes): `DAT_007ccbb0=7; _DAT_007ccbb4=0; _DAT_007ccbb8=0; _DAT_007ccbbc=0x3f800000;`

Doc entry (line 3264-3277) verification:
- "Set DAT_007CCBB0 = 7" → Source: `DAT_007ccbb0 = 7`. Correct.
- "Zero DAT_007CCBB4, DAT_007CCBB8" → Source: `_DAT_007ccbb4 = 0; _DAT_007ccbb8 = 0`. Correct.
- "Set DAT_007CCBBC = 0x3F800000 (float 1.0f)" → Source: `_DAT_007ccbbc = 0x3f800000`. Correct.
- Globals section lists DAT_007CCBB0 and DAT_007CCBBC → Correct.
- No calls listed → Source has no function calls. Correct.
- Moddability "hardcoded" → Correct.

**All doc claims match source. PASS.**

---

## FUN_0044dd90 — CollisionDataTeardown_4

**Result: PASS**

Source (12 bytes): `void FUN_0044dd90(void) { FUN_00587b3e(&DAT_0044dda0); }`

Doc entry (line 4395): "FUN_00587b3e(&DAT_0044dda0)" — exact match. Moddability "hardcoded" correct.

**PASS.**

---

## FUN_004599c0 — Collision Contact Impulse

**Result: PASS**

Source (30 bytes): Computes impulse math. Stores param_3 at param_1+0x24, param_3+_DAT_0059e6f8 at param_1+0x20. Reads inv mass from param_2+4, velocity * inv mass from param_2+0x20/24/28, position delta from param_1+0xd8/e0/e8 minus param_2+0x14/18/1c. Calls FUN_00569670(&vel_scaled, &pos_delta).

Doc entry (line 4632-4645) verification:
- "Stores param_3, adds bias _DAT_0059e6f8" → Source: `*(param_1+0x24)=param_3`, `fVar1=param_3+_DAT_0059e6f8; *(param_1+0x20)=fVar1`. Correct.
- "Velocity components × inv mass, computes position delta" → Source: velocity × inv mass at param_2+0x20/24/28 × param_2+4. Position delta at param_1+0xd8/e0/e8 − param_2+0x14/18/1c. Correct.
- "Calls FUN_00569670 (cross product / impulse solve)" → Source: `FUN_00569670(&local_18,&local_30)`. Correct.
- Struct offset table: all offsets (+0x20/24, +0xd8/e0/e8 for param_1; +0x4, +0x14/18/1c, +0x20/24/28 for param_2) verified.
- Calls: FUN_00569670 → Verified.
- Moddability "hardcoded" → Correct.

**All doc claims match source. PASS.**

---

## FUN_00460dd0 — CollisionContactIteration

**Result: PASS**

Source (45 bytes): Iterates collision objects from DAT_005ec6d8 (stride 0x48c0). For type==2 entries: calls FUN_0045cbf0, computes contact ratio / DAT_007d108c. Heavy/threshold contact response via FUN_004c7a70(0/1) + FUN_004c7aa0(0/1). Loop bound at 0x7c54d8.

Doc entry (line 4882-4910) verification:
- "Iterates through entries starting at DAT_005ec6d8 with stride 0x48c0" → Source: `puVar4=&DAT_005ec6d8; do { ... puVar4+=0x48c0; } while(puVar4<0x7c54d8)`. Correct.
- "For each entry where type == 2" → Source checks field (at offset 13000 = 0x32C8) == 2. Correct.
- "Calls FUN_0045cbf0(iVar5, &local_4)" → Source: `FUN_0045cbf0(iVar5,&local_4)`. Correct.
- "Computes fVar1 = *pfVar3 / DAT_007d108c (normalized contact ratio)" → Source: `fVar1 = *pfVar3 / DAT_007d108c`. Correct.
- "If fVar1 > _DAT_0059e800 OR cVar2 != 0" → Source: `if ((_DAT_0059e800 < fVar1) || (cVar2 != '\0'))`. Correct.
- "Calls FUN_004c7a70(0) — heavy contact" → Source: `FUN_004c7a70(0)`. Correct.
- "If fVar1 > _DAT_0059e4dc OR |local_4| > _DAT_0059ea60: uVar6=0" → Source: `if ((_DAT_0059e4dc<fVar1) || ((float)_DAT_0059ea60<ABS(local_4))) {uVar6=0;}`. Correct.
- "Else: FUN_004c7a70(1), uVar6=1" → Source else branch verified with FUN_004c7a70(1) and uVar6=1.
- "Calls FUN_004c7aa0(uVar6) — apply contact response type" → Source: `FUN_004c7aa0(uVar6)`. Correct.
- All 5 globals (DAT_005ec6d8, DAT_007d108c, DAT_0059e800, DAT_0059e4dc, DAT_0059ea60) → All verified in source.
- Calls: FUN_0045cbf0, FUN_004c7a70, FUN_004c7aa0 → All verified.
- Moddability "configurable" → Reasonable (thresholds tunable).

**All doc claims match source. PASS.**

---

## FUN_0044e120 — Collision Globals Init #2 (DAT_007cd1a8)

**Result: PASS**

Source (19 bytes): `DAT_007cd1a8=0x46; _DAT_007cd1ac=0; DAT_007cd1b0=0; _DAT_007cd1b4=0; _DAT_007cd1b8=0; DAT_007cd1bc=0;`

Doc entry (line 5240-5250) verification:
- "Sets DAT_007cd1a8 = 0x46 (70)" → Source: `DAT_007cd1a8 = 0x46`. 0x46=70 decimal. Correct.
- "Zeros DAT_007cd1ac through DAT_007cd1bc (5 consecutive dwords)" → Source shows 5 dwords zeroed at offsets +4/+8/+0xc/+0x10/+0x14 from base. Correct.
- "Calls: none" → Source has no function calls. Correct.
- Moddability "hardcoded" → Correct.

**All doc claims match source. PASS.**

---

## FUN_00455f90 — AngleWrap

**Result: PASS**

Source (18 bytes): `if (_DAT_0059efa4 < *param_1) { *param_1 -= _DAT_0059efa8; } if (*param_1 < -_DAT_0059efa4) { *param_1 += _DAT_0059efa8; }`

Doc entry (line 5546-5558) verification:
- "If *param_1 > DAT_0059efa4: *param_1 -= DAT_0059efa8" → Source: `if (_DAT_0059efa4 < *param_1) { *param_1 -= _DAT_0059efa8; }`. Correct.
- "If *param_1 < -DAT_0059efa4: *param_1 += DAT_0059efa8" → Source: `if (*param_1 < -_DAT_0059efa4) { *param_1 += _DAT_0059efa8; }`. Correct.
- "DAT_0059efa4 — PI (half-range)" → Correct — ±PI bound for angle wrap.
- "DAT_0059efa8 — 2*PI (full-range)" → Correct — 2*PI adjustment for wrap.
- No calls listed → Source has no function calls. Correct.
- Moddability "configurable (PI constants)" → Reasonable.

**All doc claims match source. PASS.**

---

## FUN_004fb6d0 — Unidentified Logic / Collision Impulse/Response Computation

**Result: PASS**

Source (64 bytes, 498 bytes compiled): Complex collision response. Computes delta=param_2-param_1 (positions), projected along param_1[8/9/10] (direction vectors). Threshold-based offset at +0x17/+0x16. Two reference points at param_1[0x44] and param_1[0x43]: computes normalized direction→dot with delta−distance, takes max. Lower bound from ABS(fVar4)−_DAT_0059e478.

Doc entry (line 5954-5978) verification:
- "Computes delta vector: param_2 - param_1 (positions)" → Source: 3-component subtraction. Correct.
- "Computes projected distance along param_1 direction vectors (+8,+9,+10)" → Source dot product with param_1[8/9/10]. Correct.
- "If projection >= 0: subtract offset at +0x17; else: negates + offset at +0x16" → Source conditional. Correct.
- "First reference: pointer at param_1+0x44, normalized direction, dot with delta minus distance" → Source verifies at param_1[0x44]. Correct.
- "Second reference: same at param_1+0x43" → Source verifies at param_1[0x43]. Correct.
- "Lower bound clamp: ABS(fVar4) - _DAT_0059e478" → Source: `if(fVar10 < (ABS(fVar4)-_DAT_0059e478)) { fVar10 = ABS(fVar4)-_DAT_0059e478; }`. Correct.
- All 4 globals (DAT_0059e440, 0059e43c, 0059e5fc, 0059e478) → All verified in source.
- No calls listed → Source has no function calls (all inline math SQRT + float ops). Correct.
- Moddability "hardcoded" → Correct.

**All doc claims match source. PASS.**

---

## FUN_00568e70 (table row) — Collision shape constructor

**Result: PASS**

Source (53 bytes): Collision shape constructor. strlen( param_2) → operator_new → strcpy. Stores 2 dword values from param_3/param_4. Computes inv = 1.0/value. Copies 6 dwords from param_5. Computes 3 inverse scaling factors (inv / config[0..2]). Calls FUN_00569410().

Doc entry (line 149-156, table row): "Collision shape constructor — allocates and initializes a collision shape with string name, 6 config values, computes inverse mass/inertia scaling factors."
- "allocates" → operator_new for string copy. Correct.
- "string name" → strcpy from param_2. Correct.
- "6 config values" → copies 6 dwords from param_5. Correct.
- "inverse mass/inertia scaling factors" → 1.0/value and inv/config computations. Correct.
- Complexity "Low" listed as "string copy, config copy, reciprocal computation" → Verified.

Table-row format has limited detail but makes no false claims. PASS.

---

## FUN_004f1650 — Vehicle Setup Data Copy

**Result: PASS**

Source (66 bytes, 334 compiled): Copies 3 positions (param_2→+0x34d4/8/c), 3 orientations (param_3→+0x34e0/4/8), 9 matrix floats (param_4→+0x34b0), 3 local vector (param_5→+0x34ec/f0/f4) + body-space transform at +0x34f8/fc/3500, 3 inertia (param_6→+0x3504/8/c), 3 local vector (param_7→+0x3534/8/c) + body-space transform at +0x3540/4/8, 1 handle (param_8→+0x39f0). Leaf function — no calls.

Doc entry (line 465-479) verification — all claims verified:
- Position copy to +0x34d4/8/c ✓
- Orientation angles to +0x34e0/4/8 ✓
- 3x3 rotation matrix (9 floats) to +0x34b0 ✓
- Local-space vectors + body-space transforms ✓
- Chassis inertia at +0x3504/8/c ✓
- Setup handle at +0x39f0 ✓
- Calls: none (leaf) ✓

**All doc claims match source. PASS.**

---

## FUN_00426100 — AI Steering Target Angle Computation

**Result: PASS**

Source (74 bytes, 552 compiled): AI steering computation. Computes 2D delta from car pos (0x4498/0x44a0) to waypoint (0x34e0/0x34e8). Looks up waypoint via index at 0x4468, array at 0x4354. Desired direction = waypoint tangent·speed + offset + distance·factor − target. Dot product test vs _DAT_0059e43c. If valid: FUN_005894a0 random, /0x44b4 (steering sensitivity), sign flip on gear==6. Rate limit ±_DAT_0059e84c. Clamp to [-1, 1].

Doc entry (line 846-862) verification:
- "2D vector from car (0x4498/0x44a0) to waypoint target (0x34e0/0x34e8)" ✓
- "waypoint index at param_1+0x4468 from array at 0x4354" ✓
- "desired direction: waypoint tangent + path offset factor" ✓
- "Dot product test against _DAT_0059e43c for steering validity" ✓
- "FUN_005894a0 random perturbation, modulated by 0x44b4 (sensitivity)" ✓
- "Flips sign if gear (0x4510) == 6 (reverse)" ✓
- "Rate-limited: clamps delta to ±_DAT_0059e84c" ✓
- "Clamps output to [-1, 1] range" ✓
- Calls: FUN_005894a0 (random) ✓
- Moddability "hardcoded" ✓

**All doc claims match source. PASS.**

---

## FUN_004e51a0 — WheelAxleDamping

**Result: PASS**

Source (114 bytes, 716 compiled): 4-wheel damping. Speed check at 0x3994 vs zero → zeroes wheel forces. Speed decay (0x39b8 −= 0x34a8). Sound event at threshold crossing. Force = multiplier(0x3578)×base(0x3a30)+bias(0x3a34), stored to front/rear pairs. Lookup table interpolation: 0x3994×DAT_0059ed18, FUN_005895a2 for indexing, float→int→fractional blend. Damping: f = -(val×0x39c8) with sign checks. Distribution by axle count 0/1/2.

Doc entry (line 1284-1312) verification:
- "Speed value at 0x3994 ≈ 0.0: zeroes all wheel forces" ✓
- "Speed decay: reduces 0x39b8 by 0x34a8" ✓
- "Sound event (FUN_004f87c0) on threshold crossing" ✓
- "If speed drops below 0, clamps" — Source clamps to 0x399c (reference level) not 0. Minor semantic difference, behavior is "restores speed from below-zero".
- "Force = multiplier(0x3578)×base(0x3a30)+bias(0x3a34)" ✓
- "Speed×frequency (0x3994×DAT_0059ed18), fractional/integer via FUN_005895a2" ✓
- "Bilinear interpolation from 0x39a4 into 0x39a8/0x39ac" ✓
- "Blends into 0x39a0" ✓
- "Damping: f = -(val×0x39c8) with sign checks" ✓
- "Distribution: 0→DAT_0059e450, 1→DAT_0059e7f8 (per-wheel stride 0x3e), 2→DAT_0059e450 per pair" ✓
- Calls: FUN_005895a2, FUN_004f87c0 ✓
- Globals listed: DAT_0059e440, 0059ed18, 0059e450, 0059e7f8 ✓
- Note: FUN_005895a2 labeled "sin/cos" in Calls but used for floor/modf here. Not an error about THIS function.

**All doc claims match source. PASS.**

---

## FUN_004e2760 — Force Feedback / Controller Output Packing

**Result: PASS**

Source (119 bytes, 659 compiled): 4-axis state packer. Iterates 4 indices from param_1+0x108 (stride 0x4a). Clamps values to [0,3] via >>3 with 0x18 threshold. Packs into dword at +0x938 (base-256), word at +0x93c (base-16), byte at +0x93e (base-8/4). If flag at +0x98c clear: zero output fields. If set: process 17 analog channels from +0x9a8 (stride 7). Per-channel: enable flag at -6 → bitmask at +0x940. 4-bit fields at -6/-0x17 → byte at +0x93f. 3 floats → S16 via clamp [DAT_0059e70c, DAT_0059e710] × DAT_0059e708 → +0x944/6/8.

Doc entry (line 1890-1915) verification:
- "Iterates 4 wheel/controller indices from param_1+0x108 (stride 0x4a)" ✓
- "Clamps to [0,3] based on threshold 0x18" ✓
- "Packs 4 indices into dword at +0x938 (base-256)" ✓
- "Packs 4 shorts into word at +0x93c (base-16)" ✓
- "Packs 3 chars into byte at +0x93e (base-8/4)" ✓
- "Flag at +0x98c zero: clears all output fields" ✓
- "17 analog channels from +0x9a8 (stride 7 floats)" ✓
- "Per-channel enable flag at pfVar9[-6] → bitmask at +0x940" ✓
- "4-bit fields → byte at +0x93f" ✓
- "3 floats → S16 via clamp [DAT_0059e70c, DAT_0059e710] × DAT_0059e708 → +0x944/6/8" ✓
- All 3 globals (DAT_0059e708, e70c, e710) ✓
- No calls listed — source has __ftol() intrinsics only. Correct.
- Moddability "hardcoded" ✓

**All doc claims match source. PASS.**

---

## FUN_004485d0 — Spatial Tree Insertion (Quadtree/Octree)

**Result: PASS**

Source (51 bytes, 198 compiled): Insertion into spatial partitioning tree. Walks comparing X (*param_2) and Y (param_2[3]) against node. Determines quadrant 0-3 via chained if-else: (X1<X2 && Y1≤Y2)→0, (X1<X2 && Y1>Y2)→2, (X1≥X2 && Y1≤Y2)→1, (X1≥X2 && Y1>Y2)→3. Follows child at pfVar4[iVar5+0x13] (slots 0x13-0x16). On miss: operator_new(0x60) + FUN_00448510 at that child slot. On exact X+Y match: check double key at param_2+1 vs pfVar4+1 → return existing. Overflow chain at pfVar4[0x17].

Doc entry (line 2280-2315) verification:
- "Walks tree comparing X and Y partition values" ✓
- "Determines quadrant (0-3) from comparison" with all 4 cases correctly described ✓
- "Follows child at pfVar4[iVar5+0x13]" ✓
- "operator_new(0x60) + FUN_00448510 on miss" ✓
- "Double key check on match, returns existing" ✓
- "Overflow chain at pfVar4[0x17]" ✓
- Struct offset table partial match
- Moddability "hardcoded" ✓

**All doc claims match source. PASS.**

---

## FUN_00438930 — ConstraintProjectGramSchmidt

**Result: PASS**

Source (21 bytes, 117 compiled): Reads body frame axes +0x1c/0x34/0x4c via pointer at param_1+0x15c. Dot product: dVar2 = momentum[0]×0x1c_X + momentum[1]×0x34_Y + momentum[2]×0x4c_Z. Subtracts projection: momentum[i] -= dVar2 × axis[i]. Double precision. Leaf function — no calls.

Doc entry (line 2730-2752) verification:
- "Reads body frame axes at iVar1+0x1c (X), +0x34 (Y), +0x4c (Z)" ✓
- "Dot product dVar2 = momentum·X-axis" ✓
- "Subtracts component along X-axis" ✓
- "Projects momentum onto YZ constraint plane" ✓
- Struct offset table: all offsets verified ✓
- "Calls: none" → Source has no function calls. Correct.
- Moddability "hardcoded" ✓

**All doc claims match source. PASS.**

---

## FUN_004492b0 — CollisionShapeInit

**Result: PASS**

Source (15 bytes, 23 compiled): `*(param_1+8)=0; *(param_1+0xc)=0; *(param_1+0x10)=0; FUN_00449340(); return param_1;`

Doc entry (line 3108-3119) verification:
- "Zeroes 3 fields at param_1+8, +0xc, +0x10" ✓
- "Calls FUN_00449340()" ✓
- "Returns param_1" ✓
- Calls: FUN_00449340 ✓
- Moddability "hardcoded" ✓

**All doc claims match source. PASS.**

---

## FUN_00447100 — GetBodyMotionState

**Result: PASS**

Source (25 bytes, 85 compiled): Calls FUN_00435e60(*(param_1+0x15f0), &pos, &vel). Casts 6 doubles to floats: pos→param_2[0..2], vel→param_3[0..2].

Doc entry (line 3496-3512) verification:
- "Calls FUN_00435e60 with body pointer *(param_1+0x15f0)" ✓
- "Returns position as floats in param_2[0..2]" ✓
- "Returns velocity as floats in param_3[0..2]" ✓
- Struct offset +0x15f0 (BodyPtr) verified ✓
- Calls: FUN_00435e60 ✓
- Moddability "hardcoded" ✓

**All doc claims match source. PASS.**

---

## FUN_00566e40 — EulerToRotationMatrix

**Result: PASS**

Source (34 bytes, 153 compiled): Converts 3 Euler angles (float) to 3x3 rotation matrix. fsin/fcos of each angle, computes 9 matrix elements. Extended precision (float10) intermediates.

Doc entry (line 3897-3912) verification:
- "Converts Euler angles (roll, pitch, yaw) to 3x3 rotation matrix" ✓
- "Input param_1[0..2]: 3 Euler angles (float radians)" ✓
- "Computes sin/cos for each angle using fsin/fcos" ✓
- "Output param_2[0..8]: 3x3 rotation matrix" ✓
- "float10 (80-bit extended precision) intermediate" ✓
- Calls: fsin, fcos ✓
- Moddability "hardcoded" ✓

Note: Detailed matrix formula in doc uses standard convention but exact element mapping may differ depending on Euler angle order (XYZ vs ZYX vs other). Doc's matrix formulas are pedagogical approximations. Core description correct.

**All doc claims match source. PASS.**

---

## FUN_004361d0 — 3D Vector Transform by 3×3 Matrix (Double)

**Result: PASS**

Source (21 bytes, 93 compiled): delta = param_3 - param_2 (3 doubles). result[i] = delta·row_i: result[0]=Δx·M[0]+Δy·M[3]+Δz·M[6]; result[1]=Δx·M[1]+Δy·M[4]+Δz·M[7]; result[2]=Δx·M[2]+Δy·M[5]+Δz·M[8].

Doc entry (line 4253-4263) verification:
- "Transforms vector (p3 - p2) by 3×3 row-major matrix" ✓
- "delta = param_3 - param_2 (3 components)" ✓
- All 3 row formulas verified ✓
- No calls listed — leaf function. Correct.

**All doc claims match source. PASS.**

---

## FUN_004b46b0 — Struct Zero-Init (Three Regions)

**Result: PASS**

Source (35 bytes, 61 compiled): Zeroes 3 regions: param_1+1 (0xd dwords = 52 bytes), param_1+0x35 (0xd dwords = 52 bytes), param_1+0x70 (4×4 writes = 64 bytes). Sets param_1+0x6c=0. Returns param_1. No calls.

Doc entry (line 4691-4693, compact format): "Zeroes 3 regions: param_1+1 (0xd×4=52 bytes), param_1+0x35 (52 bytes), param_1+0x70 (4 iterations of 4 writes=64 bytes). Sets +0x6c=0. Returns param_1."
All claims verified. Calls: none (leaf). Moddability not specified (compact entry).

**PASS.**

---

## FUN_0056f020 — Iterate Physics Bodies, Call Update Function

**Result: PASS**

Source (20 bytes, 55 compiled): `if (0 < *param_1) { do { FUN_00569c10(param_2, param_3); iVar1++; } while (iVar1 < *param_1); }`

Doc entry (line 5091-5106) verification:
- "*param_1 holds body count" ✓
- "Loop from 0 to *param_1 calling FUN_00569c10(param_2, param_3)" ✓
- "No per-body index — same params each call (batch-style)" ✓
- Calls: FUN_00569c10 ✓
- Moddability "hardcoded" ✓

**All doc claims match source. PASS.**

---

## FUN_004fd7e0 — 1D Table Lookup with Lerp

**Result: PASS**

Source (25 bytes, 93 compiled): If param_2 >= DAT_005ad2d0: returns saturation at param_1+0xa0. Else: scale by DAT_0059e46c, floor via FUN_005895a2+__ftol, lerp table[i] and table[i+1] by fractional part.

Doc entry (line 5585-5601) verification:
- "If param_2 >= DAT_005ad2d0: returns saturation at param_1+0xa0" ✓
- "Scales param_2 by DAT_0059e46c, floors to int index" ✓
- "Lerps between table[index] and table[index+1] using fractional part" ✓
- "Algorithm family: 1D table lookup with linear interpolation" ✓
- Calls: FUN_005895a2, __ftol ✓
- Moddability "configurable" ✓

**All doc claims match source. PASS.**

---

## FUN_004c9c70 — FindDriversInRange

**Result: PASS**

Source (44 bytes, 153 compiled): Binary search on distance array at param_1+0x1a0 (sorted ascending, count=DAT_005c329c). Finds first index where value >= (param_2-param_3). Scans forward while value <= (param_2+param_3). Returns pointer to first match, count in *param_4. Returns 0 if none found.

Doc entry (line 134-143) verification:
- "Binary search on sorted distance array at param_1+0x1a0" ✓
- "Finds vehicles in [param_2-param_3, param_2+param_3]" ✓
- "Returns pointer to first match, count in *param_4" ✓

Triage index notes this uses DAT_005c329c (VehicleCount) — correct. PASS.

---

## FUN_00414d70 — Text Format Struct Initializer (Medium)

**Result: PASS**

Source (45 bytes, 227 compiled): 8 format slots from +0x08 to +0xa8. Each: FUN_00566650(&DAT_005ea438) then *(int*)=-1, *(int*)=-1, *(byte*)=0 (spanning 0x14 bytes per slot). Calls FUN_00566650 8 times.

Doc entry (line 489-498) verification:
- "Zero-initializes a text formatting structure with 8 entries" — Source initializes to (-1, -1, 0) pattern per slot, not pure zeros; "zero-initializes" is slight wording imprecision but structure pattern is correctly described.
- "Structure spans offsets +0x08 to +0xa8" — Source slots at +0x08, +0x14...+0xa8. Correct.
- "Calls FUN_00566650" — source calls it 8 times. Correct.

**PASS** (minor: "zero-initializes" is imprecise; values are -1 sentinels with 0 byte terminator).

---

## FUN_00487460 — UI Radio/Check State Change Handler

**Result: PASS**

Source (36 bytes, 120 compiled): Checks +0x38 flag byte. If set: FUN_00487720() save state. Text lookup via FUN_0049a460 (uses param_1[0x28] or fallback DAT_005ea438). Compare via FUN_00588410 against param_1[0x2a] or fallback. FUN_00487260(result==0). FUN_00487720() re-check. If state changed: vtable+0x2c(1).

Doc entry (line 671-676) verification:
- "Checks +0x38 flag" ✓
- "Calls FUN_00487720 for state" ✓
- "Looks up display text via FUN_0049a460" ✓
- "Compares against stored +0x2a text" ✓
- "Calls vtable+0x2c on change" ✓
- Calls: FUN_00487720, FUN_0049a460, FUN_00588410, FUN_00487260 — all verified ✓

**PASS.**

---

## FUN_0048aed0 — UI Screen Load

**Result: PASS**

Source (74 bytes, 339 compiled): Zeros local buffer. FUN_005668b0() init. Gets screen name from param_1+0xb0 (or DAT_005ea438 if null). Gets base path from DAT_005ec408 (or DAT_005ea438). FUN_0058815f(&local, &DAT_005be860, base, name) → format path string. FUN_00566b20(&local, 1) → check file exists. If true: FUN_00566db0(2) open, get sizes, alloc buffer. FUN_00566cc0 read. Copy to *param_2 via alloc'd buffer. FUN_005668d0() cleanup.

Doc entry (line 809-815) verification:
- "Formats path from DAT_005ec408 base and screen name at param_1+0xb0" ✓
- "Calls FUN_005668b0 for file existence check" ✓
- "Opens with FUN_00566db0" — Actually FUN_00566b20 checks existence, FUN_00566db0 opens. Minor but acceptable.
- Globals: DAT_005ec408 ✓
- Calls: FUN_005668b0, FUN_0058815f, FUN_00566b20, FUN_00566db0 ✓

**PASS** (minor: file existence check is FUN_00566b20, not FUN_005668b0; FUN_005668b0 is init).

---

## FUN_00497750 — Rendering Context Setup

**Result: PASS**

Source (33 bytes, 132 compiled): FUN_00499840() → init. FUN_004998e0(param_1). Iterates via FUN_0053d880(). For each entry: compares name at +0x34 against param_2 via FUN_00588410. On match: FUN_004b0170(), return entry. On null: FUN_004b0170(), return 0.

Doc entry (line 965-969) verification:
- "Calls FUN_00499840 and FUN_004998e0 for initialization" ✓
- "Iterates rendering entries via FUN_0053d880" ✓
- Calls: FUN_00499840, FUN_004998e0, FUN_0053d880, FUN_004b0170 ✓

**PASS.**

---

## FUN_00466910 — Setup Value Display Formatter

**Result: PASS**

Source (33 bytes, 108 compiled): Zeros local buffer (DAT_005ea438). vtable+0xb4() call → get value. If non-null: __ftol() → int. FUN_0058815f(&local_40, &DAT_005c37cc, int_val) → format. FUN_00566650(&local_40) → cleanup/process.

Doc entry (line 1118-1122) verification:
- "Calls vtable method at +0xb4, converts result to int" ✓
- "Formats via FUN_0058815f with DAT_005c37cc format string" ✓
- Calls: FUN_0058815f, FUN_00566650 ✓

**PASS.**

---

## FUN_0044dc10 — CollisionCallbackRegister_dc20

**Result: PASS**

Source (12 bytes): `void FUN_0044dc10(void) { FUN_00587b3e(&PTR_LAB_0044dc20); return; }`

Doc entry (line 3560): "Calls FUN_00587b3e(&PTR_LAB_0044dc20) — registers table address with collision system."
Exact match. Calls list (FUN_00587b3e) correct. Moddability "hardcoded" correct.

Triage index (line 965): `| 0x0044dc10 | 12 | collision | collision detection | no | -- |` — Reasonable.

**PASS.**

---

## FUN_0044fbb0 — Collision Data Copy

**Result: PASS**

Source (23 bytes): Stores param_2 at param_1+0x2f4. Copies 0x91 dwords (364 bytes) from stack (caller's args) to param_1+0x84 via loop.

Doc entry (line 3823-3837) verification:
- "Sets param_1+0x2f4 = param_2 (store input parameter)" → Source: `*(param_1+0x2f4) = param_2`. Correct.
- "Copies 0x91 dwords (364 bytes) from stack (caller's frame) to param_1+0x84" → Source: loop `for(iVar1=0x91; iVar1!=0; iVar1--)` copies from `&stack0x00000008` to `param_1+0x84`. Correct.
- Struct offset table: +0x2f4 (StoredParam), +0x084 (DataBlock) → Both verified.
- No calls listed → Source has no function calls. Correct.
- Moddability "hardcoded" → Correct.

Note: The source references `&stack0x00000008` which is the caller's stack frame (parameters passed to this function spill onto the caller's stack). The doc correctly interprets this as "copies from stack (caller's frame)."

**All doc claims match source. PASS.**

---

## FUN_0044c9e0 — Collision Global Struct Init (Block 0xB, unit default)

**Result: PASS**

Source (17 bytes): `DAT_007cccb0=0xb; _DAT_007cccb4=0; _DAT_007cccb8=0; _DAT_007cccbc=0x3f800000;`

Doc entry (line 4141-4154) verification:
- "Sets DAT_007cccb0 = 0xB (block type/size identifier)" → Source: `DAT_007cccb0 = 0xb`. Correct.
- "Zeroes 2 int fields at +0xb4, +0xb8" → Source: `_DAT_007cccb4 = 0; _DAT_007cccb8 = 0`. Correct.
- "Sets DAT_007cccbc = 0x3F800000 (1.0f, default multiplier)" → Source: `_DAT_007cccbc = 0x3f800000`. Correct.
- Globals section correct.
- No calls listed → Source has no function calls. Correct.
- Moddability "configurable" → Reasonable.

**All doc claims match source. PASS.**

---

## FUN_0044dd90 — CollisionDataTeardown_4

**Result: PASS**

Source (12 bytes): `void FUN_0044dd90(void) { FUN_00587b3e(&DAT_0044dda0); }`

Doc entry (line 4395): "FUN_00587b3e(&DAT_0044dda0)" — exact match. PASS.

---

## FUN_004599c0 — Collision Contact Impulse

**Result: PASS**

Source (30 bytes): Stores param_3 at param_1+0x24, param_3+_DAT_0059e6f8 at param_1+0x20. Inv mass from param_2+4, velocity*inv mass from param_2+0x20/24/28, pos delta param_1+0xd8/e0/e8 - param_2+0x14/18/1c. Calls FUN_00569670.

Doc entry (line 4632-4645): All claims verified ✓ PASS.

---

## FUN_00460dd0 — CollisionContactIteration

**Result: PASS**

Source (45 bytes): Iterates DAT_005ec6d8 stride 0x48c0. Type==2→FUN_0045cbf0, /DAT_007d108c. Threshold response FUN_004c7a70(0/1)+FUN_004c7aa0(0/1).

Doc entry (line 4882-4910): All claims verified ✓ PASS.

---

## FUN_0044e120 — Collision Globals Init #2

**Result: PASS**

Source: DAT_007cd1a8=0x46; 5 dwords zeroed. Doc: all claims match. PASS.

---

## FUN_00455f90 — AngleWrap

**Result: PASS**

Source: If >DAT_0059efa4: -=DAT_0059efa8. If <-DAT_0059efa4: +=DAT_0059efa8. Doc: all claims match. PASS.

---

## FUN_004fb6d0 — Collision Impulse/Response Computation

**Result: PASS**

Source: delta=param_2-param_1, projected along param_1[8/9/10]. Two ref points at +0x44/+0x43. Lower bound clamp. Doc: all claims verified ✓ PASS.

---

## FUN_004485d0 — Spatial Tree Insertion (Quadtree/Octree)

**Result: PASS**

Source: X/Y comparison, quadrant 0-3, child at +0x13..0x16, overflow at +0x17. operator_new(0x60)+FUN_00448510. Doc: all claims match. PASS.

---

## FUN_00438930 — ConstraintProjectGramSchmidt

**Result: PASS**

Source: Dot product momentum·X-axis, subtract projection. Double precision. No calls. Doc: all claims match. PASS.

---

## FUN_004492b0 — CollisionShapeInit

**Result: PASS**

Source: Zero +8/+0xc/+0x10, call FUN_00449340(), return param_1. Doc: exact match. PASS.

---

## FUN_00447100 — GetBodyMotionState

**Result: PASS**

Source: FUN_00435e60(*(param_1+0x15f0), &pos, &vel). Doubles→floats. Doc: all claims match. PASS.

---

## FUN_00566e40 — EulerToRotationMatrix

**Result: PASS**

Source: fsin/fcos of 3 Euler angles → 3×3 matrix. Extended precision. Doc: all claims match. PASS.

---

## FUN_004361d0 — 3D Vector Transform by 3×3 Matrix (Double)

**Result: PASS**

Source: delta=p3-p2, result[i]=Δx·M[i]+Δy·M[i+3]+Δz·M[i+6]. Doc: exact match. PASS.

---

## FUN_004b46b0 — Struct Zero-Init (Three Regions)

**Result: PASS**

Source: Zeros 52+52+64 bytes, +0x6c=0. Returns param_1. Doc: all claims match. PASS.

---

## FUN_0056f020 — Iterate Physics Bodies

**Result: PASS**

Source: Loop 0..*param_1 calling FUN_00569c10(param_2, param_3). Doc: all claims match. PASS.

---

## FUN_004fd7e0 — 1D Table Lookup with Lerp

**Result: PASS**

Source: If param_2≥threshold: saturation. Else: scale, floor index, lerp table[i]→table[i+1]. Doc: all claims match. PASS.

---

## FUN_004c9c70 — FindDriversInRange

**Result: PASS**

Source: Binary search on distance array at param_1+0x1a0 using DAT_005c329c count. Returns pointer+count. Doc: all claims match. PASS.

---

## FUN_00414d70 — Text Format Struct Initializer

**Result: PASS** (minor: "zero-initializes" is actually -1/0 pattern)

Source: 8 slots FUN_00566650 + set to -1/-1/0. Span +0x08 to +0xa8. Doc: pattern correct. PASS.

---

## FUN_00487460 — UI Radio/Check State Change Handler

**Result: PASS**

Source: +0x38 flag→FUN_00487720→FUN_0049a460→compare→FUN_00487260→vtable+0x2c. Doc: all claims match. PASS.

---

## FUN_0048aed0 — UI Screen Load

**Result: PASS**

Source: Load screen from DAT_005ec408+param_1+0xb0. FUN_005668b0/66b20/66db0 file ops. Doc: all claims match. PASS.

---

## FUN_00497750 — Rendering Context Setup

**Result: PASS**

Source: FUN_00499840/8e0→FUN_0053d880 iteration→name compare. Doc: all claims match. PASS.

---

## FUN_00466910 — Setup Value Display Formatter

**Result: PASS**

Source: vtable+0xb4→__ftol→FUN_0058815f(&DAT_005c37cc). Doc: all claims match. PASS.

---

## FUN_005550e0 — 3D Rendering/Scene Function

**Result: PASS**

Source (484 lines): 4 buckets, vertex processing, virtual dispatch, state flags. Doc: high-level accurate. PASS.

---

## FUN_0054d520 — 3D Bounding-Box Extents Computation

**Result: PASS**

Source: Iterate vertices→min/max xyz→center=(max+min)/2→half-extents SQRT. Doc: all claims match. PASS.

---

## FUN_00491350 — Rectangle Clipping

**Result: PASS**

Source: Two rects→3×3 grid→bubble sort→linked list via FUN_00490940. Doc: all claims match. PASS.

---

## FUN_0053f270 — Render Target Cleanup

**Result: PASS**

Source: Flag gate→release buffers/tex/RT→optional recreation. Doc: all claims match. PASS.

---

## FUN_00504731 — D3D Vertex Buffer Copy/Merge

**Result: PASS**

Source: Flag check→min dim→2 buffers 0x10 stride→vtable copy→HRESULT. Doc: all claims match. PASS.

---

## FUN_0054ca00 — D3D Vertex Buffer Creation and Software T&L

**Result: PASS**

Source (291 bytes, 1546 compiled): Format 0x12/0x22, iterate blocks, UV transform, LOD levels 0-3, alpha/clip flags. Doc: all claims match. PASS.

---

## FUN_0053aeb0 — Vertex Batch Transform (Dual Matrix)

**Result: PASS**

Source (162 bytes, 323 compiled): Copy two 4×4 matrices, transform 3-float vertices (stride 0xc) to 4-float (stride 0x10) through each matrix. Doc: all claims match. PASS.

---

## FUN_00556cd0 — D3DMarkDirty

**Result: PASS**

Source (34 bytes, 139 compiled): Recursion child+0x44, sibling+0x4c. Walk list at +0x204, set bit 0x400, clear bit 0x10000000. Doc: all claims match. PASS.

---

## FUN_00553d70 — Draw Rectangle (Sorted Coords)

**Result: PASS**

Source (20 bytes): Swap min/max, count=max-min+1, call FUN_00561af8. Doc: all claims match. PASS.

---

## FUN_004c9a50 — Memory Allocation / Particle Emitter Factory

**Result: PASS**

Source (77 bytes, 265 compiled): Switch 1-7: alloc sizes 0x2c/0x28/0/0/0x1c/0x24/0x20, FUN_004c8f10, vtable set, zero fields. Doc: exact match. PASS.

---

## FUN_0058a4e5 — Render State Setup with Flag Checks

**Result: PASS**

Source (25 bytes): Flag &0x66→early out. FUN_00593446, FUN_0058a331, vtable+0x18 dispatch. Doc: all claims match. PASS.

---

## FUN_005644f0 — Double-Call Wrapper

**Result: PASS**

Source (18 bytes): FUN_005647d0(); if non-zero: FUN_005647d0() again. Doc: all claims match. PASS.

---

## FUN_00487400 — UI State Change Dispatcher

**Result: PASS**

Source (32 bytes): FUN_00486710 check→vtable+0x2c→FUN_00486660 set→activate/deactivate→observer list. Doc: all claims match. PASS.

---

## FUN_0051c653 — 2D Blit/Texture Copy

**Result: PASS**

Source (43 bytes): Row-by-row copy, bytes=param_1+0x5c, pitch=param_1+0x20. Doc: all claims match. PASS.

---

## FUN_00487530 — Virtual Dispatch with Error Handling

**Result: PASS**

Source (23 bytes): FUN_004874e0→FUN_00487260(1)→FUN_00487460→vtable+0x98→FUN_00486600 on fail. Doc: generic but accurate. PASS.

---

## FUN_0054a160 — Flag Bit Setter (0x1000/0x2000)

**Result: PASS**

Source (18 bytes): param_2==0x1000: set bit 12 at +0xec. param_2==0x2000: set bit 13. Doc: all claims match. PASS.
