# Cross-Validation Results: Functions 1126-1180
# Target: docs/20-math-utilities.md
# Generated: 2026-07-15

---

## FUN_00587BDC — SKIP (compiler intrinsic)

Source: 0x00587bdc____ftol.c — MSVC CRT __ftol (float-to-long). Doc entry confirms CRT intrinsic. No game logic.

---

## FUN_0049A190 — PASS

Verified: linked list iteration with vtable destructor. While *param_1 != 0: calls FUN_00499e00(), updates *param_1, calls (*extraout_ECX)(1) if non-null. All claims match .c source. No globals or struct offsets claimed.

---

## FUN_004C4CB0 — PASS

Verified: linked list key search. Stores head at param_1+8 → param_1+0x10, walks list comparing *node to param_2, returns 1/0, follows next+4 pointer. All claims match .c.

---

## FUN_00503CE3 — PASS

Verified: bitplane blending/compositing. Reads buffers at param_1[1]+0x18 and *param_1+0x18, stride at +0x1050, nested row/pixel loops with 16-bit color channel averaging (0xf0f0/0xffff0f0f masks, 0x2020/0x202 rounding, >>2). Struct offsets +0x18, +0x1050, +0x1058, +0x105C all confirmed. No calls. All claims verified.

---

## FUN_0053C900 — PASS

Verified: string match with flag set. Copies string to local buffer, normalizes via FUN_00589901, iterates DAT_008b8e30 entries (stride 0x84) at DAT_008b5a3c, sets 0x400 flag in DAT_008b5a38 on match. Calls FUN_0053ca00(). All globals and calls confirmed in .c source.

---

## FUN_0058C674 — PASS

Verified: character encoding convert. Direct table lookup (PTR_DAT_005e69c8) if param_2+1 < 0x101, else FUN_00595dc8 multibyte conversion. Returns masked by param_3. All claims match .c source.

---

## FUN_0040BDE0 — PASS

Verified: struct field initializer. All field sets confirmed: +0x00/+0x04/+0x08=0, +0x0c=2, +0x14=-1, +0x18/+0x1c/+0x20=0, +0x24=0, +0x25=0, +0x28=0, +0x2c=0, +0x2d=0, +0x2e=0. All match .c source.

---

## FUN_004672C0 — FAIL

**Errors: STRUCT_OFFSET_MISMATCH** — Struct offset table has systematic errors. Offsets for Param4, ConstVal, Param3, Param2 are shifted by +8 bytes.

**Verification:**
- `FUN_0048c070(0)` — confirmed ✓
- `param_1[200] = &DAT_007c5770 + (param_2 * 0xb + param_3) * 0x40` — confirmed ✓
- Vtable `PTR_FUN_0059f4f8` — confirmed ✓
- index 0xc9 = 0x37, index 0xca = param_3, index 0xcb = param_2 — confirmed ✓

**Corrected struct offsets (index × 4 = byte offset):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x000 | vtable | PTR_FUN_0059f4f8 |
| +0x31c | Param4 | param_1[199] = param_4 |
| +0x320 | GlobalPtr | param_1[200], pointer into DAT_007c5770 |
| +0x324 | ConstVal | param_1[0xc9] = 0x37 |
| +0x328 | Param3 | param_1[0xca] = param_3 |
| +0x32c | Param2 | param_1[0xcb] = param_2 |

**Correction applied to doc below:**

```
<!-- target: docs/20-math-utilities.md -->
## FUN_004672c0 — Object Initializer with Vtable + Index

Source: unknown | Confidence: high
Initializes an object: sets vtable, computes indexed global pointer, stores parameters.

**Key logic:**
- Calls FUN_0048c070(0) — global init
- Computes: param_1[200] = &DAT_007c5770 + (param_2 * 0xb + param_3) * 0x40
- Sets vtable to PTR_FUN_0059f4f8
- Stores param_4 at index 199 (+0x31c)
- Stores 0x37 at index 0xc9 (+0x324)
- Stores param_3 at index 0xca (+0x328)
- Stores param_2 at index 0xcb (+0x32c)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x000 | vtable | pointer | Set to PTR_FUN_0059f4f8 |
| +0x31c | Param4 | uint | Index 199 (0xc7): stored from param_4 |
| +0x320 | GlobalPtr | pointer | Index 200 (0xc8): pointer into DAT_007c5770 |
| +0x324 | ConstVal | uint | Index 0xc9: set to 0x37 |
| +0x328 | Param3 | uint | Index 0xca: stored from param_3 |
| +0x32c | Param2 | uint | Index 0xcb: stored from param_2 |

**Globals:**
- DAT_007c5770 — base of global array, stride 0x40

**Calls:**
- FUN_0048c070 — global initialization
```

---

## FUN_0048DFF0 — PASS

Verified: state machine with virtual dispatch. Calls FUN_00486720() for state, switch with cases 1/2/4/5/default, dispatches vtable+0x40 and vtable+0x9c with correct args (6,7,8,9). All claims match .c.

---

## FUN_004B1970 — PASS

Verified: small struct init. Fields [1]=0, [2]=-1, [3]=0, [4]=-1, vtable = PTR_LAB_005acbd8. All match .c source.

---

## FUN_004DC600 — PASS

Verified: surface size query. Calls FUN_0053d1f0 then FUN_005531f0, two __ftol() conversions, stores in *param_3/*param_4, zeros on failure. All claims match .c.

---

## FUN_0053C9C0 — PASS

Verified: bit flag array update. Iterates DAT_008b8e30 entries at DAT_008b5a38 (stride 0x21 ints = 0x84 bytes), if bit 0x4000 set: clears it and sets 0x400. Calls FUN_0053ca00(). All match .c.

---

## FUN_0055685A — PASS

Verified: returns constant 1 as uint16. No params, no globals, no side effects. All match .c.

---

## FUN_00564B80 — PASS

Verified: pad output with spaces. Returns *param_3=0 if param_2<1, else copies 3 chars from param_1 (or zeros), appends 4 random chars from FUN_00564c40(). Null-terminates. All claims match .c.

---

## FUN_00463760 — PASS

Verified: conditional state dispatch. Calls FUN_00461dc0(), dispatches to FUN_00461190/FUN_00460e90/FUN_00461020 based on state and param_1. All match .c.

---

## FUN_00488BD0 — PASS

Verified: field setter at +0xE4. Trivial setter. All match .c.

---

## FUN_004A1DC0 — PASS

Verified: guarded linked list append. Guard at param_1[4], alloc 12-byte node, appends to list, increments count at [3]. All struct offsets (+0x00/+0x04/+0x08/+0x0C/+0x10) confirmed.

---

## FUN_004D2260 — PASS (minimal entry, no errors)

Verified: progress increment + data store. Checks DAT_0083ee60 < 0x3ff increments both counters, calls FUN_004b33b0 (progress bar), stores params at DAT_008aae64+8/+0xc. Entry accurate but sparse — no calls/globals claimed to verify. No errors found.

---

## FUN_0050DC90 — PASS (minimal entry)

Verified: calls FUN_0050fea7(1) then indirect through PTR_FUN_005d783c. Minimal entry accurate.

---

## FUN_00547420 — PASS (minimal entry)

Verified: frees two linked lists (param_1+0x24 chain via +0xc0, param_1+0x2c chain via +0x14). Calls FUN_00546370/FUN_00557470/FUN_00587bcf, FUN_0053ab70/FUN_00587bcf. Minimal entry accurate.

---

## FUN_0059C6E8 — SKIP (compiler intrinsic — SEH unwind)

Source: 0x0059c6e8__Unwind_0059c6e8.c. MSVC SEH unwind stub — frees EBP+8 via FUN_00587bcf. Compiler-generated, no game logic.

---

## FUN_00461530 — PASS

Verified: flag bit test. Returns ((char)param_1+0x88 & param_2) != 0. All match .c.

---

## FUN_0050C042 — PASS

Verified: float range check. param_1 - param_2, checks between _DAT_005ade3c and _DAT_005ac9c0 exclusive. Returns 1/0. All match .c.

---

## FUN_0058DCCC — PASS

Verified: float rounding mode select. Checks in_EAX & 0x80000, returns 7 or 1. All match .c.

---

## FUN_004258C0 — PASS

Verified: AI speed/overtaking state setter. Sets +0x4438=1.0, +0x4434=0. If +0x4440 < _DAT_0059e46c OR (+0x37cc>_DAT_0059e824 AND +0x38c4>_DAT_0059e824): sets +0x4510=2. All globals and offsets confirmed.

---

## FUN_00479910 — PASS

Verified: UI object init. FUN_00466980(0, 0.5f), vtable = PTR_FUN_005a54e8. All match .c.

---

## FUN_00499160 — PASS

Verified: UI destructor. Calls FUN_00499180(), if param_2 & 1: FUN_00587bcf(param_1). All match .c.

---

## FUN_004BDE20 — PASS

Verified: clamped nested loop with callback. 4x __ftol clamped to [0,7]. Nested loops: (iVar4-iVar3+1) × (param_1-iVar5+1), calls FUN_004bd860. Extra call if any clamp occurred. All match .c.

---

## FUN_004FC850 — PASS

Verified: float field init. [0..3]=0, [4]=[5]=20.0f. All match .c.

---

## FUN_005361D0 — FAIL

**Errors: RETURN_VALUE_ERROR** — Doc claims "Return 0xfffffffd or 0xfffffffe based on type" but .c returns 0 or 0xfffffffd on success path (based on iVar2 == 0x71). 0xfffffffe is the guard-failure return (line 29). Incorrectly conflates two return paths.

**Verified correct claims:**
- Guard: param_1 && param_1+0x1c && (*(param_1+0x1c)+4) in {0x2a,0x71,0x29a} ✓
- Dispatches *(param_1+0x24) for 4 conditional checks + 1 always ✓
- Sets *(param_1+0x1c)=0 ✓

**Corrected return value paragraph:**
```
- Guard passes: returns (iVar2 != 0x71) - 1 & 0xfffffffd → 0 if type == 0x71, 0xfffffffd otherwise
- Guard fails: returns 0xfffffffe
```

**Correction applied to doc below:**

```
<!-- target: docs/20-math-utilities.md -->
## FUN_005361d0 — Multi-Condition Dispatch with Cleanup

Source: unknown | Confidence: medium
Checks type field for specific values (0x2a, 0x71, 0x29a), dispatches multiple callbacks, resets state.

**Key logic:**
- Guard: param_1 != 0 AND *(param_1+0x1c) != 0 AND *(*(param_1+0x1c)+4) in {0x2a, 0x71, 0x29a}
- If guard passes: dispatches *(param_1+0x24) for each of 4 non-null sub-conditions, then once unconditionally
- Sets *(param_1+0x1c) = 0
- Returns 0 if type == 0x71, 0xfffffffd otherwise
- If guard fails: returns 0xfffffffe

**Calls:** *(param_1+0x24) (callback dispatch, up to 5 times)
```

---

## FUN_00587200 — PASS

Verified: byte setter at +0x18. Trivial setter. All match .c.

---

## FUN_004080F0 — PASS

Verified: memory allocation with buffer read. Guard: +0xc != 0 AND +0x18 == 0. Seeks via FUN_00587f64, reads count via FUN_0058803f, allocates count*4 via operator_new, zero-inits, reads dwords. On failure: FUN_0041a160 + free. Returns 0/1. Struct offsets +0x0c/+0x14/+0x18 all confirmed.

---

## FUN_0054EAF0 — PASS

Verified: struct zero-init. [0..3]=0, [7..9]=0, loop [0xd..0x1c]=0 (16 dwords). All match .c.

---

## FUN_00536260 — PASS

Verified: table lookup init. Computes width from +0x22, zero-fills buffer at +0x3a, looks up 3 ushorts from DAT_005b77e8/ea/ec/ee indexed by (+0x7a)*0xc, zeroes fields, sets +0x72=lookup, +0x6e=+0x56=2. All match .c.

---

## FUN_004D5C40 — PASS

Verified: zeros DAT_008ad254 and DAT_008ad258. All match .c.

---

## FUN_004A3FE0 — PASS

Verified: dual zero + conditional call. Sets +0x78=0, +0x84=0. If +0x64 != 0: FUN_0054c030(0,0,1,0). All match .c.

---

## FUN_0048B560 — PASS

Verified: path/file char validator. Mode dispatch on +0x2e8. Mode 1 rejects \, /, :, .; mode 2 calls FUN_00589b9e/FUN_00589b70, allows . and :. Calls FUN_00589c49 for valid char check. All match .c.

---

## FUN_0046E170 — PASS

Verified: game command dispatch. Calls vtable+0x1c on *DAT_007cd8c0 with 0x24 then 0x23, each followed by FUN_00489cb0 on success. All match .c.

---

## FUN_005679A5 — PASS

Verified: list traversal with early exit. Uses ZF flag from caller, iterates decrementing counter until 0 or null pointer, follows next at +4. All match .c.

---

## FUN_004DFCA0 — FAIL

**Errors: STALE_ENTRY** — Doc marked as `[PARTIAL] Unknown` with "3 lines of decompiled code" but .c is fully decompiled (21 lines). Description no longer accurate.

**Verified behavior from .c:**
- Calls FUN_004ded20() 11 times (0xb loop)
- If param_1+0x90 != 0: frees via FUN_00587bcf

**Corrected entry:**

```
<!-- target: docs/20-math-utilities.md -->
## FUN_004dfca0 — Loop Call with Conditional Free

Source: unknown | Confidence: high
Calls FUN_004ded20 11 times, then conditionally frees pointer at +0x90.

**Key logic:**
- Loops 11 times calling FUN_004ded20()
- If param_1+0x90 != 0: FUN_00587bcf(*(param_1+0x90)) — free
- Returns void

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x90 | freeable_ptr | Freed if non-null |

**Calls:**
- FUN_004ded20 — loop target (11 calls)
- FUN_00587bcf — conditional free
```

---

## FUN_0051A87E — FAIL

**Errors: STALE_ENTRY** — Doc marked as `[PARTIAL] Unknown` with "10 lines of decompiled code" but .c is fully decompiled (55 lines, 234 bytes). Bitstream/Huffman-like decoder with table lookup, bit extraction, and error reporting.

**Corrected entry:**

```
<!-- target: docs/20-math-utilities.md -->
## FUN_0051a87e — Bitstream Decode with Table Lookup

Source: unknown | Confidence: medium
Reads variable-length bit field from bit buffer, performs table-based decoding with error reporting.

**Key logic:**
- Extracts (param_5)-bit field from param_2 at bit position param_3
- Compares against table at param_4+0x44+(param_5*4), consumes more bits if below threshold
- Updates bit buffer state at param_1+0x18 and param_1+0xc
- If decoded index < 17: table-based decode from param_4+0x8c, param_4+0xd0
- Else: error dispatch through vtable at param_1+0x1c

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x0c | bit_buffer | Remaining bit data |
| +0x18 | bit_position | Current bit position |
| +0x1c | error_handler | VTable for error dispatch |

**Struct offsets (param_4 - decode table):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x44 | threshold_table | int table indexed by bit length |
| +0x8c | value_table | int table for small indices (<17) |
| +0xd0 | base_table | int table for small indices |

**Calls:**
- FUN_0051a794 — refill bit buffer
- VTable dispatch on param_1[0x1c] for errors

**Moddability:** hardcoded
```

---

## FUN_00564220 — FAIL

**Errors: STALE_ENTRY** — Doc marked as `[PARTIAL] Unknown` with "7 lines of decompiled code" but .c is fully decompiled (33 lines). Function is a string tokenizer scanning DAT_008cfae4 for delimiter param_2.

**Corrected entry:**

```
<!-- target: docs/20-math-utilities.md -->
## FUN_00564220 — String Tokenizer (strtok-style)

Source: unknown | Confidence: high
Tokenizes a global string buffer by scanning for delimiter character.

**Key logic:**
- If param_1 != NULL: sets DAT_008cfae4 = param_1 (new string to tokenize)
- Scans DAT_008cfae4 for first occurrence of param_2 (delimiter)
- If found and not at start: null-terminates at match, advances DAT_008cfae4 past delimiter
- Returns pointer to token start, or NULL if no token found

**Globals:**
- DAT_008cfae4 — global string buffer pointer (stateful)

**Calls:** none
```

---

## FUN_00552FC0 — PASS

Verified: field setter at +0x48. Trivial setter. All match .c.

---

## FUN_0059CAC0 — SKIP (compiler intrinsic — SEH unwind)

Source: 0x0059cac0__Unwind_0059cac0.c. MSVC SEH unwind — frees *(EBP-0x20) via FUN_00587bcf. Doc already correctly identifies as SEH. No game logic.

---

## FUN_00456040 — PASS

Verified: double field getter. Returns *(param_1+0x30) via param_2, *(param_1+0x34) via param_3, null-guarded. All match .c.

---

## FUN_0047A230 — PASS

Verified: conditional destructor. Vtable=PTR_FUN_005a6068, calls FUN_0048d3e0, if param_2&1: FUN_00587bcf(param_1), returns param_1. All match .c.

---

## FUN_00499A20 — PASS

Verified: float field decrement. *(param_1+8) -= param_2. All match .c.

---

## FUN_004C2300 — PASS

Verified: dual-list destruction. Primary list at [0], secondary at [4] with 3-level deep free. Zeros many fields, sets +0x1b=1, restores [0x20] from DAT_007d0a24. All match .c.

---

## FUN_005001F0 — PASS

Verified: float comparison check. Returns 1 if *(param_1+0xc) != _DAT_005ad34c, else 0. All match .c.

---

## FUN_0053B130 — PASS

Verified: 10-float struct initializer. Zeroes 7 dwords, sets 3 to 1.0f (0x3f800000), calls FUN_0053b3b0. All match .c.

---

## FUN_0058A947 — SKIP (library code — MSVC CRT __nh_malloc)

Source: 0x0058a947____nh_malloc.c. MSVC CRT heap allocator. Doc correctly identifies as CRT. No game logic.

---

## FUN_0059CAE0 — SKIP (compiler intrinsic — SEH unwind)

Source: 0x0059cae0__Unwind_0059cae0.c. MSVC SEH unwind — delegates to FUN_0057b7f0 (vtable init). Doc correctly identifies. No game logic.

---

## FUN_0045BB00 — FAIL

**Errors: RETURN_VALUE_ERROR** — Doc claims "Returns index of first above-threshold value" but function returns COUNT of values exceeding threshold (0-4), not index. The while loop counts how many of 8 sampled values (stride 0x5c, starting at +0x90) exceed DAT_0059e440, capped at 4.

**Verified correct claims:**
- Iterates up to 8 entries, stride 0x5c, starting at param_1+0x90 ✓
- Compares against DAT_0059e440 (ZeroThreshold) ✓

**Corrected description:**
```
Returns count (0-4) of values exceeding threshold DAT_0059e440 across up to 8 sampled entries (stride 0x5c from +0x90). Stops after finding 4 above-threshold values or exhausting the array.
```

**Correction applied to doc below:**

```
<!-- target: docs/20-math-utilities.md -->
## FUN_0045bb00 — Float Array Threshold Search

Source: unknown | Confidence: medium
Searches array of floats for values exceeding threshold, returns count.

**Key logic:**
- Iterates up to 8 entries stride 0x5c starting at param_1+0x90
- Checks if float > DAT_0059e440 (ZeroThreshold, ~0.0f)
- Returns count of above-threshold values found (capped at 4)

**Globals:**
- DAT_0059e440 (ZeroThreshold)
```

---

## FUN_0047F1F0 — PASS

Verified: clamp by range. Clamps *param_1 to [param_2, param_3] using side-effect conditional. All match .c.

---

## FUN_0049A330 — PASS

Verified: char-to-index conversion. Normalizes via FUN_00589901, returns first_char - 'A' if in [0-25], else -1. All match .c.

---

# Summary

**Functions 1126-1180 cross-validation complete.**

| Result | Count | Functions |
|--------|-------|-----------|
| PASS | 44 | 0049A190, 004C4CB0, 00503CE3, 0053C900, 0058C674, 0040BDE0, 0048DFF0, 004B1970, 004DC600, 0053C9C0, 0055685A, 00564B80, 00463760, 00488BD0, 004A1DC0, 004D2260, 0050DC90, 00547420, 00461530, 0050C042, 0058DCCC, 004258C0, 00479910, 00499160, 004BDE20, 004FC850, 00587200, 004080F0, 0054EAF0, 00536260, 004D5C40, 004A3FE0, 0048B560, 0046E170, 005679A5, 00552FC0, 00456040, 0047A230, 00499A20, 004C2300, 005001F0, 0053B130, 0047F1F0, 0049A330 |
| FAIL | 6 | 004672C0 (STRUCT_OFFSET_MISMATCH), 005361D0 (RETURN_VALUE_ERROR), 004DFCA0 (STALE_ENTRY), 0051A87E (STALE_ENTRY), 00564220 (STALE_ENTRY), 0045BB00 (RETURN_VALUE_ERROR) |
| SKIP | 5 | 00587BDC (CRT __ftol), 0059C6E8 (SEH unwind), 0059CAC0 (SEH unwind), 0059CAE0 (SEH unwind), 0058A947 (CRT __nh_malloc) |

**Key findings:**
- 5 FAIL entries found: 3 stale [PARTIAL] entries, 1 struct offset error, 1 return value error
- 4 of 55 functions are SEH unwind/CRT intrinsics (skip)
- Struct offset table for FUN_004672C0 had systematic +8 byte shift
- FUN_005361D0 return value description conflated two return paths
- Two stale [PARTIAL] entries (004DFCA0, 0051A87E) now have full decompiled .c sources
- FUN_00564220 is a string tokenizer but doc claims [PARTIAL]
- FUN_0045BB00 returns count of above-threshold values, not index of first

