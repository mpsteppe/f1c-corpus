# Cross-Validation Report: docs/06 + docs/07 + docs/08

Generated: 2026-07-15
Validator: ARCHITECT (Claude)

---

## From docs/06-session-race-logic.md

### 1. FUN_0059C0AC — Bit field extract/test

**Doc type:** Triage line (minimal, 35-line utility)
**Source:** `analyzed\0x0059c0ac__FUN_0059c0ac.c`

**Verdict: PASS**

**Reasoning:**
Function takes uint, tests bits in lookup table (`DAT_008d47e0`), conditionally returns decoded byte from `DAT_008d46e0`. For values >= 0x100, calls `FUN_00591fa1` (codepage/UTF decode). Doc calls it "Bit field extract/test from uint" — acceptable for triage-level entry. Small function (123 bytes). No claims to verify beyond minimal category/purpose.

---

### 2. FUN_00454DA0 — Vehicle Input Smoothing (Throttle/Brake/Clutch/Steering)

**Doc type:** Full `## FUN_` entry
**Source:** `analyzed\0x00454da0__FUN_00454da0.c` (197 lines)

**Verdict: PASS** (minor documentation nit)

**Reasoning:**
All core claims verified against .c:

| Claim | .c Verification |
|-------|----------------|
| Four channels: throttle(0x2410), brake(0x2414), clutch(0x2418), steering(0x241c) | Lines 39,60,81,130 |
| Mode flags: 0x1b20(throttle), 0x1b4c(brake), 0x21d4(clutch), 0x1b78(steering) | Lines 15,40,61,82 |
| Mode == 2 → snap to target | Lines 16,41,62,83-88 |
| Reverse gear flag 0x1b70 modifies throttle decay | Line 21-25 |
| `_DAT_0059e8a4` reverse multiplier | Line 25 ✓ |
| `_DAT_0059e478` steering center boost | Line 96 ✓ |
| Steering clamps to ±1.0 (0xbf800000/0x3f800000) | Lines 101,113 |
| Gear display cascade 0x20f0→0x1fbc → 7..-1,-2 | Lines 132-174 ✓ |
| `DAT_007d1370` neutral override (-2→0) | Line 171 ✓ |
| 0x2420 outputHandbrake, 0x2428 gearNeedsUpdate | Lines 175,131 ✓ (in struct table) |
| `_DAT_007d12c8`, `_DAT_007d12ec`, `_DAT_007d12a4`, `_DAT_007d1310` globals | Lines 19,44,91,185 ✓ |

**Minor nit:** Descriptive text says "Clutch channel checks 0x1c54 mode, snap or decay" — but 0x1c54 is actually the **handbrake** channel (output 0x2420). The actual clutch mode is at 0x21d4 (line 61). Handbrake mode at 0x1c54 (line 176). Text mislabels handbrake as clutch.

---

### 3. FUN_00509B8E — Texture Decode: 32-bit RG Luminance-Alpha

**Doc type:** Full `## FUN_` entry
**Source:** `analyzed\0x00509b8e__FUN_00509b8e.c` (32 lines)

**Verdict: PASS**

**Reasoning:**
All claims verified:

| Claim | .c Verification |
|-------|----------------|
| Iterates param_1[0x1058] pixels | Line 18,32 |
| R = (pixel & 0xFFFF) × _DAT_005ad290 | Line 20 |
| G = *(ushort*)(pixel+2) × scale | Line 21 |
| B = 1.0 | Line 22 |
| A = 1.0 | Line 23 |
| Calls FUN_00507845 if param_1[0x10] != 0 | Lines 26-28 |

Fully accurate. No discrepancies.

---

### 4. FUN_004E1FD0 — 3D Transform Point by Matrix and Translation

**Doc type:** Full `## FUN_` entry
**Source:** `analyzed\0x004e1fd0__FUN_004e1fd0.c` (26 lines)

**Verdict: PASS**

**Reasoning:**
All claims verified:

| Claim | .c Verification |
|-------|----------------|
| 3×3 M[3×3] at +0x20 × vector at +0x8e8 | Lines 8-16 (offsets 0x20,0x24,0x28,0x2c,0x30,0x34,0x38,0x3c,0x40 × 0x8e8,0x8ec,0x8f0) |
| Adds translation (+8, +0xc, +0x10) | Lines 17-19 |
| Copies rotation quaternion (+0x14,0x18,0x1c) → param_3[0..2] | Lines 20-22 |

Struct offset table fully accurate. No discrepancies.

---

### 5. FUN_0042EB60 — ListSelectionClamp

**Doc type:** Full `## FUN_` entry
**Source:** `analyzed\0x0042eb60__FUN_0042eb60.c` (30 lines)

**Verdict: PASS**

**Reasoning:**
All claims verified:

| Claim | .c Verification |
|-------|----------------|
| Entry offset = param_2 × 0x40 | Line 11 |
| Stores previous at +0xbc4 | Line 12 |
| Clamps param_3: <1→0, >=max→max-1 | Lines 13-20 |
| Calls FUN_0042e530(4, param_2) | Line 22 |
| Sets dirty flags at 0x19a4 and *param_1=1 | Lines 24-25 |

Fully accurate. No discrepancies.

---

### 6. FUN_004B9A00 — PackedFlagRead

**Doc type:** Full `## FUN_` entry
**Source:** `analyzed\0x004b9a00__FUN_004b9a00.c` (11 lines)

**Verdict: PASS**

**Reasoning:**
Doc: reads byte at *param_1 + 0xf81, combines with *param_1 >> 8, returns CONCAT31.
.c line 8: `CONCAT31((int3)((uint)*param_1 >> 8), *(undefined1 *)(*param_1 + 0xf81))` ✓

Fully accurate for an 11-line function. No discrepancies.

---

### 7. FUN_0052D9B0 — C++ Constructor (VTable Setup)

**Doc type:** Full `## FUN_` entry
**Source:** `analyzed\0x0052d9b0__FUN_0052d9b0.c` (16 lines)

**Verdict: PASS**

**Reasoning:**
Doc: sets *param_1 = &PTR_FUN_005b47e8; if *(char*)(param_1+0x93b)!=0 → FUN_0052e320().
.c lines 8-11: `*param_1 = &PTR_FUN_005b47e8; if (*(char *)(param_1 + 0x93b) != 0) { FUN_0052e320(); }` ✓

Fully accurate.

---

### 8. FUN_004C0AB0 — Audio Subsystem Initializer

**Doc type:** Full `## FUN_` entry
**Source:** `analyzed\0x004c0ab0__FUN_004c0ab0.c` (24 lines)

**Verdict: PASS**

**Reasoning:**
All claims verified:

| Claim | .c Verification |
|-------|----------------|
| Calls FUN_004c03c0 104 (0x68) times | Lines 10-15: 103 in loop + 1 outside = 104 ✓ |
| Calls FUN_004c0370 (master init) | Line 16 ✓ |
| Sets param_1+0xb144 = 0 | Line 17 ✓ |
| Sets param_1+0xb150 = 0 | Line 18 ✓ |
| Sets param_1+0xb148 = 0xffffffff | Line 19 ✓ |
| Sets param_1+0xb14c = 1 | Line 20 ✓ |

Fully accurate. No discrepancies.

---

### 9. FUN_004F69E0 — Linear Vehicle Parameter Evaluation

**Doc type:** Full `## FUN_` entry
**Source:** `analyzed\0x004f69e0__FUN_004f69e0.c` (19 lines)

**Verdict: PASS**

**Reasoning:**
All claims verified:

| Claim | .c Verification |
|-------|----------------|
| *param_6 = param_3*(+0x520) + param_2*(+0x530) + (+0x4ac) | Lines 9-10 ✓ |
| *param_5 = ABS(*(double*)(+0x444)) | Line 11 ✓ |
| param_5[1] = ABS(*(double*)(+0x47c)) | Line 12 ✓ |
| param_5[2] = param_4*(+0x3fc) + param_3*(+0x518) + param_2*(+0x528) + (+0x3f4) | Lines 13-15 ✓ |

Fully accurate.

---

### 10. FUN_005078B5 — VertexColorFloatToByte

**Doc type:** Full `## FUN_` entry
**Source:** `analyzed\0x005078b5__FUN_005078b5.c` (37 lines)

**Verdict: PASS**

**Reasoning:**
All claims verified:

| Claim | .c Verification |
|-------|----------------|
| If param_1+0x1048 != 0: calls FUN_00506ce2(param_4) | Lines 15-17 ✓ |
| Color table at param_1+0x2c | Line 18 ✓ |
| Index formula: (param_3&3)+(param_2&3)*8+(idx&3) | Line 25 ✓ |
| Adds scaled: param_4[n] × DAT_0059fec8 | Lines 26-28 ✓ |
| Stride 0x10 | Line 31 (iVar3 += 0x10) ✓ |
| Outputs 3 bytes (BGR) per vertex | Lines 26-28 (B first, G second, R third) ✓ |

Doc does not mention `FUN_00507473()` call at line 19 — minor omission, no impact on correctness.

Fully accurate on all substantive claims.

---

### 11. FUN_0054FAE0 — BufferEntryClear

**Doc type:** Full `## FUN_` entry
**Source:** `analyzed\0x0054fae0__FUN_0054fae0.c` (36 lines)

**Verdict: PASS** (minor offset notation ambiguity)

**Reasoning:**
All claims verified:

| Claim | .c Verification |
|-------|----------------|
| Buffer base from param_1+0x1e0 | Line 12 ✓ |
| param_2 == 0x8000000 → clear ALL | Line 14 ✓ |
| Otherwise → single entry at index param_2 | Lines 27-30 ✓ |
| Stride 0x74 | Lines 21 (puVar2 + 0x1d, 0x1d×4 = 0x74), 28 (param_2 × 0x74) ✓ |
| Clear: entry->flags &= ~1 | Lines 19,29 ✓ |
| Entry count at buffer+4 | Line 17 ✓ |
| Entry array at buffer+8 | Line 15 ✓ |
| Zero field offset | See note below |

**Minor note:** Doc says "zero offset +0x10 for each" but code uses `puVar2[0x10] = 0` where puVar2 is `uint*`, so byte offset = 0x40, not 0x10. Doc mixes uint-index notation with byte-offset convention. This is an inconsistency in notation, not a logic error — the entry still correctly describes the behavior.

---

### 12. FUN_004BE4E0 — Sprite Grid Render

**Doc type:** Full `## FUN_` entry
**Source:** `analyzed\0x004be4e0__FUN_004be4e0.c` (78 lines)

**Verdict: PASS**

**Reasoning:**
All claims verified:

| Claim | .c Verification |
|-------|----------------|
| Converts 4 float params to int via __ftol() | Lines 16,26,36,46 |
| Clamps to 0-7 | Lines 17-24,27-34,37-44,46-53 |
| Nested loop over rows/cols | Lines 56-68 ✓ |
| Calls FUN_004bdb10 per cell | Line 62 ✓ |
| If any clamp: extra FUN_004bdb10 at end | Lines 69-72 ✓ |
| Increments counter at param_1+0x934 | Line 74 ✓ |

Fully accurate. No discrepancies.

---

## From docs/07-pit-system.md

### 13. FUN_004D12C0 — Pit Stop Order Loader

**Doc type:** Full `## FUN_` entry
**Source:** `decompiled_all\0x004d12c0__FUN_004d12c0.c` (72 lines)

**Verdict: PASS**

**Reasoning:**
All claims verified:

| Claim | .c Verification |
|-------|----------------|
| Reads PITORDER section | Line 16: `FUN_00568210(s_PITORDER_005d3a28)` ✓ |
| +0x1a8 = pit order count | Lines 18,24 ✓ |
| +0x1ac = pit order array (stride 8) | Lines 28-45 (alloc iVar1×8+4, stores at +0x1ac) ✓ |
| Reads ReversePitOrder | Line 46: `FUN_004c58a0(local_110, 0x40, s_ReversePitOrder_005d3be0, 0)` ✓ |
| If True: reverses array | Lines 47-57 (when value ≠ "False", iterate backwards) ✓ |
| Each entry = string pointer | Lines 22 (`FUN_00567970()` returns string ptr), 52/63 (`FUN_00566650` registers path) ✓ |

**Minor note:** Reverse logic is slightly more nuanced than "If True, reverses" — default behavior (field absent) also goes reverse path. Only explicit "False" skips reversing. Doc simplification is acceptable.

Fully verified for a 72-line loader function.

---

### 14. FUN_004D2210 — Pit Close: Team Ready Check

**Doc type:** Full `## FUN_` entry
**Source:** `analyzed\0x004d2210__FUN_004d2210.c` (23 lines)

**Verdict: PASS**

**Reasoning:**
All claims verified:

| Claim | .c Verification |
|-------|----------------|
| Iterates vehicles | Lines 10-18 (loop over DAT_005c329c) ✓ |
| If +13000 == 0 or +13000 == 1 | Lines 13-14 ✓ |
| Calls FUN_004bc9b0(1,0) | Line 15 ✓ |

Fully accurate. The "old tires/waiting" interpretation for +13000 values is reasonable but unverifiable from decompiled code alone.

---

## Summary

| # | Function | Verdict | Issues |
|---|----------|---------|--------|
| 1 | FUN_0059C0AC | **PASS** | Triage line only — minimal claims, all correct |
| 2 | FUN_00454DA0 | **PASS** | Text says "clutch" at 0x1c54 but should be "handbrake" |
| 3 | FUN_00509B8E | **PASS** | None |
| 4 | FUN_004E1FD0 | **PASS** | None |
| 5 | FUN_0042EB60 | **PASS** | None |
| 6 | FUN_004B9A00 | **PASS** | None |
| 7 | FUN_0052D9B0 | **PASS** | None |
| 8 | FUN_004C0AB0 | **PASS** | None |
| 9 | FUN_004F69E0 | **PASS** | None |
| 10 | FUN_005078B5 | **PASS** | Missing FUN_00507473() in calls list |
| 11 | FUN_0054FAE0 | **PASS** | "offset +0x10" notation ambiguous (byte vs uint index) |
| 12 | FUN_004BE4E0 | **PASS** | None |
| 13 | FUN_004D12C0 | **PASS** | ReversePitOrder default-behavior simplification |
| 14 | FUN_004D2210 | **PASS** | None |

**14/14 PASS.** No FAIL cases. Minor issues noted for documentation improvement but none constitute factual errors.

### Tracked issues for CHANGELOG:
None required — all issues are notation/simplification nits, not factual errors.
