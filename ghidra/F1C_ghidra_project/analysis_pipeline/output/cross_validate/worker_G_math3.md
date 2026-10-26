# Cross-Validation Results: docs/20-math-utilities.md vs analyzed sources
# Auditor: Architect role, 2026-07-15

---

## FUN_00556220 — FAIL

**Doc title:** Arithmetic/Comparison (Struct Zero-Init 13 dwords)
**Source:** `0x00556220__FUN_00556220.c` (29 lines, 64 bytes)
**Mode:** __fastcall, returns undefined4*

### Doc claims vs source:

| Claim | Source truth | Match? |
|-------|-------------|--------|
| Calls FUN_0053c2a0() | Calls FUN_0053c2a0() | PASS |
| Zeroes 13 dwords | Zeroes 17 dwords (indices: 0,2,3,4,5,6,7,8,9,10,0xb,0xc,0xd,0xe,0xf,0x10,0x11) | **FAIL** |
| "param_1[0] through param_1[0x11]" | Index 1 skipped; range is non-contiguous | **Inaccurate** |

### Corrections needed:
1. Title: change "13 dwords" to "17 dwords (skips index 1)"
2. Key logic: list exact indices zeroed: 0,2,3,4,5,6,7,8,9,10,0xb,0xc,0xd,0xe,0xf,0x10,0x11
3. Note: index 1 is deliberately NOT zeroed

---

## FUN_0055f080 — PASS

**Doc title:** Struct Zero-Init Constructor (Large)
**Source:** `0x0055f080__FUN_0055f080.c` (27 lines, 70 bytes)
**Mode:** __fastcall, returns undefined4*

### Doc claims vs source:

| Claim | Source truth | Match? |
|-------|-------------|--------|
| Calls FUN_0053c2a0 (parent constructor) | Calls FUN_0053c2a0() | PASS |
| Zeros fields at indices [0],[1](byte),[9],[10],[0xb](byte),[0x13],[0x14],[0x15](byte),[0x1d],[0x1e],[0x1f],[0x20],[0x25],[0x26],[0x27] | All 15 fields match source exactly | PASS |
| Byte offsets: 0,4,0x24,0x28,0x2c,0x4c,0x50,0x54,0x74,0x78,0x7c,0x80,0x94,0x98,0x9c | All byte offsets verified correct | PASS |
| 3 byte-sized clears at +4,+0x2c,+0x54 | Source uses *(undefined1*) for these | PASS |

### No corrections needed.

---

## FUN_004766f0 — PASS

**Doc title:** Short Computation / Object Init with IDs
**Source:** `0x004766f0__FUN_004766f0.c` (17 lines, 55 bytes)
**Mode:** __thiscall, takes param_2

### Doc claims vs source:

| Claim | Source truth | Match? |
|-------|-------------|--------|
| Calls FUN_0048eaa0() | Calls FUN_0048eaa0() | PASS |
| Sets param_1[99] = -1 | param_1[99] = 0xffffffff | PASS |
| Sets [0x62] = 0 | param_1[0x62] = 0 | PASS |
| Sets [0x61] = -1 | param_1[0x61] = 0xffffffff | PASS |
| Sets *param_1 = vtable PTR_LAB_005a44a0 | *param_1 = &PTR_LAB_005a44a0 | PASS |
| Sets [0x60] = param_2 | param_1[0x60] = param_2 | PASS |

### No corrections needed.

---

## FUN_004d4a50 — PASS

**Doc title:** Short Computation / Struct Init (0, 4, 0)
**Source:** `0x004d4a50__FUN_004d4a50.c` (14 lines, 23 bytes)
**Mode:** __fastcall

### Doc claims vs source:

| Claim | Source truth | Match? |
|-------|-------------|--------|
| Sets param_1[0] = 0 | *param_1 = 0 | PASS |
| Sets param_1[1] = 4 | param_1[1] = 4 | PASS |
| Sets param_1[2] = 0 | param_1[2] = 0 | PASS |

### No corrections needed.

---

## FUN_00568e30 — PASS

**Doc title:** Short Computation / Struct Initializer
**Source:** `0x00568e30__FUN_00568e30.c` (16 lines, 34 bytes)
**Mode:** __fastcall, returns undefined4*

### Doc claims vs source:

| Claim | Source truth | Match? |
|-------|-------------|--------|
| Zeros *param_1 | *param_1 = 0 | PASS |
| Zeros param_1[0x8c] | param_1[0x8c] = 0 | PASS |
| Zeros param_1[0x8e] | param_1[0x8e] = 0 | PASS |
| Zeros param_1[0x90] | param_1[0x90] = 0 | PASS |
| Calls FUN_00568f20() | Calls FUN_00568f20() | PASS |
| "Zeros 4 fields of a struct then calls init function" | Exactly correct | PASS |

### No corrections needed.

---

## FUN_0059a854 — FAIL

**Doc title:** VTable Pointer Init
**Source:** `0x0059a854__FUN_0059a854.c` (13 lines, 24 bytes)
**Mode:** __thiscall, takes param_2

### Doc claims vs source:

| Claim | Source truth | Match? |
|-------|-------------|--------|
| Calls FUN_0059a781() | Calls FUN_0059a781(**param_2**) | **FAIL** — param_2 omitted |
| *param_1 = &PTR_FUN_005b7e34 (vtable) | *param_1 = &PTR_LAB_005b9ce4 | **FAIL** — wrong address! |
| Constructor calling FUN_0059a781 | Correct pattern | PASS |

### Corrections needed:
1. Fix vtable pointer: `&PTR_LAB_005b9ce4` not `&PTR_FUN_005b7e34`
2. Add param_2 to FUN_0059a781 call: `FUN_0059a781(param_2)`
3. Update confidence: description is correct but vtable address was garbled

---

## FUN_0045d240 — FAIL

**Doc title:** Conditional Flag Reset
**Source:** `0x0045d240__FUN_0045d240.c` (16 lines, 29 bytes)
**Mode:** __fastcall, returns undefined1 (always 1)

### Doc claims vs source:

| Claim | Source truth | Match? |
|-------|-------------|--------|
| Checks condition on param_1 field | Checks `*param_1 != '\0'` | PASS (vague but correct) |
| If true: clears flag bit at struct offset | Sets `*param_1 = '\0'` | PASS (vague but correct) |
| *(missing)* Returns 1 always | Returns 1 always | **FAIL** — omitted |
| *(missing)* Calls FUN_00561f60() | Calls FUN_00561f60() before clearing | **FAIL** — omitted |
| *(missing)* Calls FUN_00561f80() | Calls FUN_00561f80() before clearing | **FAIL** — omitted |

### Corrections needed:
1. Add "**Calls:** FUN_00561f60, FUN_00561f80" section
2. Add return value note: always returns 1
3. Improve key logic: "If *param_1 != 0: calls FUN_00561f60(), FUN_00561f80(), then sets *param_1 = 0"

---

## FUN_00486010 — FAIL

**Doc title:** Zero-Init Struct Fields
**Source:** `0x00486010__FUN_00486010.c` (28 lines, 97 bytes)
**Mode:** __fastcall, takes int param_1

### Doc claims vs source:

| Claim | Source truth | Match? |
|-------|-------------|--------|
| "Sets multiple int/float fields to 0" | 16 of 17 fields set to 0 | **FAIL** — one field set to 1 |
| "Covers specific offsets in struct" | True but extremely vague | PASS (vague) |

### Off-by-one analysis:
Source sets 17 fields total:
- 16 fields set to 0 (offsets: +0x6c, +100, +0x84, +0x88, +0x80, +0x8c, +0x90, +0x94, +0x98, +0x9c, +200, +0xcc, +0xd0, +0xd4, +0xd8, +0xdc)
- **1 field set to 1, not 0**: `*(undefined1 *)(param_1 + 0x65) = 1`

### Corrections needed:
1. Title should not say exclusively "Zero-Init" — one byte at +0x65 is set to 1
2. Key logic must note: "Sets byte at param_1 + 0x65 = 1 (non-zero sentinel/flag); all other fields zeroed"
3. Add struct offsets table showing all 17 fields with types (undefined1 vs undefined4)

---

## FUN_0049cfc0 — FAIL

**Doc title:** 5-Slot Render Target Setup
**Source:** `0x0049cfc0__FUN_0049cfc0.c` (33 lines, 172 bytes)
**Mode:** __fastcall, takes int param_1

### Doc claims vs source:

| Claim | Source truth | Match? |
|-------|-------------|--------|
| "Sets up 5 render target slots" | Conditionally calls FUN_0049f530 for 5 slots | **Speculative** — no render/DirectX evidence |
| "Sets size, format for each slot" | No size/format operations visible in source | **FAIL** — fabricated detail |
| "Likely for multi-target rendering (MRT)" | Possible but unsupported | Speculative (labeled "Likely") |

### Actual behavior:
- Reads 5 pointers at param_1+0x4c, +0x50, +0x54, +0x58, +0x5c
- For each non-null pointer: reads value at pointer+0x54, if non-null calls FUN_0049f530(index, param_1+buffer_offset, value)
- Slots: 0→+0x60, 1→+0xac, 2→+0xf8, 3→+0x144, 4→+400

### Corrections needed:
1. Remove unsupported "Sets size, format for each slot"
2. Describe actual logic: conditional dispatch to FUN_0049f530 for 5 slot descriptors
3. Add "**Calls:** FUN_0049f530" section
4. Add struct offset table for slot pointers and buffers
5. Lower confidence or rename to "5-Slot Descriptor Dispatch" unless other evidence supports render target claim

---

## FUN_004c8d80 — PASS

**Doc title:** Virtual Call on DAT_008ac4c4
**Source:** `0x004c8d80__FUN_004c8d80.c` (17 lines, 16 bytes)
**Mode:** __cdecl (no params)

### Doc claims vs source:

| Claim | Source truth | Match? |
|-------|-------------|--------|
| Calls virtual method on global DAT_008ac4c4 | Calls `(**(code **)(*DAT_008ac4c4 + 0x10))()` | PASS |
| Globals: DAT_008ac4c4 | DAT_008ac4c4 used | PASS |
| Null-check implied by "calls ... on global" | Explicit `if (DAT_008ac4c4 != (int *)0x0)` | PASS (implied correctly) |

### Minor improvement (not a failure):
- Doc could specify virtual call offset 0x10 for precision
- Doc could mention explicit null guard

### No corrections needed; entry is accurate.

---

# Summary

| Function | Result | Issues |
|----------|--------|--------|
| FUN_00556220 | FAIL | 13 dwords → 17 dwords; index 1 skipped |
| FUN_0055f080 | PASS | — |
| FUN_004766f0 | PASS | — |
| FUN_004d4a50 | PASS | — |
| FUN_00568e30 | PASS | — |
| FUN_0059a854 | FAIL | Wrong vtable address (005b7e34 vs 005b9ce4); param_2 omitted |
| FUN_0045d240 | FAIL | Two called functions omitted; return value omitted |
| FUN_00486010 | FAIL | Field at +0x65 set to 1, not 0 |
| FUN_0049cfc0 | FAIL | Fabricated "sets size/format"; speculative render target claim |
| FUN_004c8d80 | PASS | — |

**Overall: 6 PASS, 4 FAIL**
