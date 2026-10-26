# Cross-Validation Audit: worker_Q_renderer
## Functions from docs/19-renderer.md

---

## FUN_004e0ed0 — PASS

All claims verified:
- Mode bit from VCAN+0x48bc bit1: confirmed at .c line 15 `(*(uint *)(*param_1 + 0x48bc) >> 1 & 1)`
- States 0/1/2/3 switch behavior matches .c case blocks
- Calls: FUN_0054c030 ✓, FUN_0054c1b0 ✓, FUN_0040cd60 ✓, FUN_004f7010 ✓ — all present in .c
- Globals referenced in .c (DAT_007ce254, DAT_007d0410, DAT_007c54f0, DAT_007cf860, DAT_007c54e0, DAT_005ea518, DAT_005ea528, DAT_007cf710) — not claimed in doc, no false claims
- Moddability: reasonable

---

## FUN_00414fe0 — PASS

All claims verified:
- 4 format slots: confirmed — 4 blocks initializing offsets +8/+14/+18/+1c, +28/+2c/+30, +3c/+40/+44, +50/+54/+58
- Structure spans +0x08 to +0x58: confirmed (highest write is +0x58)
- Calls FUN_00566650: confirmed in .c (called 4 times)
- Zero/-1 pattern: verified writes of 0xffffffff (-1) and 0

---

## FUN_004874e0 — PASS

All claims verified:
- Calls FUN_00486710: confirmed at .c line 14
- Flag at +0xe1 check: confirmed at .c line 18 `*(char *)(extraout_ECX + 0xe1)`
- Calls FUN_0049a460: confirmed at .c line 23
- Empty string check: confirmed (loop checking for null terminator, iVar4==-2 returns 0)
- Calls list complete and accurate

---

## FUN_0048b030 — PASS

All claims verified:
- Measures screen dimensions via FUN_00487060: confirmed at .c lines 36-38
- Measures screen dimensions via FUN_004870e0: confirmed at .c lines 39-40
- Full UI render pass with positioning: confirmed (renders all elements, walks linked list at +0xec, word wrapping logic)
- Calls FUN_00487060 and FUN_004870e0: correctly listed
- Additional rendering calls (FUN_00404f70, FUN_00587bcf, FUN_00498560, FUN_005665b0, FUN_004983b0, operator_new) are internal details

---

## FUN_00497980 — PASS

All claims verified:
- Returns name string at +0x50→+0x34: confirmed at .c line 16 `*(undefined1 **)(*(int *)(iVar1 + 0x50) + 0x34)`
- Guard conditions at +0x18 and +0x48: confirmed at .c lines 11-12
- Returns DAT_005ea438 if null: confirmed at .c line 18

---

## FUN_004669a0 — PASS

All claims verified:
- Calls vtable +0xb4: confirmed at .c line 24
- Formats via FUN_0058815f: confirmed at .c line 26
- Same as 00466910 but without return-if-zero guard: confirmed (no early return check in this function)
- Uses DAT_005c37cc format string: confirmed at .c line 26
- Calls FUN_00566650 for cleanup: confirmed at .c line 27

---

## FUN_0055e320 — PASS

All claims verified:
- 3D vertex transformation and lighting: confirmed (world/view transforms, lighting, fog)
- API calls at offset +0x18 (world transform): confirmed at .c line 117
- API calls at offset +0x14 (view transform): confirmed at .c line 118
- Uses DAT_008b8f24 for 3D API: confirmed
- Lighting calculation (diffuse + specular): confirmed at lines 120-122, 290-298
- SIMD-style packed short color operations (paddsw): confirmed at .c line 192
- Fog blending: confirmed at lines 183-206, 209-232
- Perspective divide and screen-space XYZ: confirmed
- Uses FUN_0053ac40 for lookup: confirmed at .c line 212
- Specular highlight from light vectors: confirmed at lines 290-298

---

## FUN_00507496 — PASS

All claims verified:
- Creates texture struct with mipmap chain: confirmed (initializes 0x100 mipmap elements with stride 0x10 via _vector_constructor_iterator_)
- Dimensions from param_2/param_3: confirmed (param_3 >> 3 at line 39, param_2 fields used)
- Initializes mipmap levels: confirmed (256-element array at +0xc with stride 0x10)
- Sets up color palette if needed: confirmed (format check for 0x29/0x28 at line 53, palette init at lines 55-79)
- Calls: none (leaf function) — confirmed, no FUN_ calls in .c

---

## FUN_0044fcc0 — PASS

All claims verified:
- Acquires D3D device from param_1+0x80: confirmed at .c line 28
- Vtable dispatch at offsets 0x24/0x1c/100: confirmed at lines 31, 34, 36
- Checks D3DERR codes (-0x7ff8fff4/-0x7ff8ffe2): confirmed at line 35
- Processes 8 constants (loop of 8): confirmed at lines 45-98
- Zero → -1 (DAT_0059e440 check): confirmed at line 55-56
- Clamps with _DAT_0059e43c: confirmed at lines 66, 82
- Color curve via lerp: confirmed at lines 69-71, 85-86

---

## FUN_00542200 — PASS

All claims verified:
- Input width/height as normalized 0-1 values: confirmed (param_4, param_5 floats)
- Scales by DAT_008b8dd8/DAT_008b8dd4: confirmed at lines 20, 22, 25
- Converts via __ftol: confirmed at lines 28, 50, 53, 55
- Stores width at +0x54: confirmed at lines 29, 39
- Stores height at +0x58: confirmed at line 51
- Center X = x + width/2 stored at +0x5c: confirmed at lines 56-57
- Center Y = y + height/2 stored at +0x60: confirmed at lines 60-61
- Pixel width float at +0x14: confirmed at line 58
- Pixel height float at +0x18: confirmed at line 62
- Aspect ratio = width/height at +0x74: confirmed at line 68
- Flip flag at +0x80 bit 4 negates projection (+0xc): confirmed at lines 69-70

---

## FUN_00510acc — PASS

All claims verified:
- Buffer refill callback: confirmed at lines 38, 54, 65, 82, 126
- Processes header with local_34 (1 byte) + 17-byte block (local_2c, local_28, local_24, local_20, local_1c): confirmed at lines 71, 80-94
- Decodes 256-byte color palette local_134[256]: confirmed at lines 134 (array declared at line 19)
- Status dispatch 0x4f (progress), 0x55 (block done), 0x1c/0x1d (error): confirmed at lines 73, 105, 116, 119, 151
- Copies 64 entries of 4 bytes each from palette to output: confirmed at lines 167-171 (loop 0x40 times, 4-byte copies)
- Output 0x200 bytes per block (256 palette + 64*4 indices): consistent with code structure

---

## FUN_00530840 — PASS

All claims verified:
- Bitstream state at +0x24a8 (bit position) and +0x24a4 (buffer pointer): confirmed
- Element count at +0x24b8: confirmed at line 23
- Variable-length code decoding via param_6 codebook: confirmed (param_6 array indexed by input char)
- Two modes at +0x24cc: 1=single channel, 2=dual channel: confirmed at line 82
- 3 output shorts at offsets -0x40, 0, +0x40: confirmed at lines 30-32
- 2nd channel at -0x20, +0x20, +0x60: confirmed at lines 86-88
- Palette lookup via param_2 (64-entry per row, 4 bytes each): confirmed at lines 39, 74-76
- Byte-reversal of bit data: confirmed at lines 45-46, 52-53, 59-60
- Jump-table dispatch via PTR_LAB_00531148: confirmed at line 151

---

## FUN_0054b570 — PASS

All claims verified:
- Dirty flags at +0x3c: 0x2100 triggers FUN_0054b330 reset: confirmed at lines 30-31
- 0x40 = already computed: confirmed at line 34
- param_2 (parent) copy inverted facing angles (0x2000=no pitch, 0x100=full): confirmed at lines 36-45
- sin/cos of yaw(+0x2c), pitch(+0x30), roll(+0x34): confirmed at lines 74-80
- Primary slot at 0x114/0x124/0x134/0x144: confirmed at lines 56-59
- Alternate slot at 0xd4/0xe4/0xf4/0x104: confirmed at lines 62-65
- Sets W=1 (0x3f800000): confirmed at line 96
- Sets computed flag 0x40: confirmed at line 97
- Backup at 0x154: confirmed at lines 99-113
- Calls FUN_0054b330 ✓, FUN_0053b240 ✓, FUN_0053b200 ✓, FUN_0054b770 ✓

---

## FUN_00554cc0 — PASS

All claims verified:
- Linked list from param_1+0x24 via +0xc0: confirmed at .c line 13
- Stride 0x25 (37 dwords): confirmed at .c line 31
- Flag bit 2 check: confirmed at .c line 18 `(*(byte *)(piVar4 + -0x13) & 2)`
- Calls FUN_0053f6e0 ✓, FUN_00557470 ✓, FUN_00587bcf ✓, FUN_00554d70 ✓

---

## FUN_0045bd10 — PASS

All claims verified:
- Checks DAT_007d02e4 (line count cap): confirmed at .c line 16
- param_3 == 0x1020304 → FUN_0045bb60: confirmed at lines 19-20
- Measures string length: confirmed at lines 24-31
- Copies up to 0x4f (79) chars via _strncpy: confirmed at line 36
- Trims trailing spaces from position 0x4e: confirmed at lines 38-48
- Calls FUN_0045b9c0 with DAT_0059f07c: confirmed at lines 33, 51
- Globals DAT_007d02e4 ✓, DAT_0059f07c ✓
- Calls FUN_0045bb60 ✓, FUN_0045b9c0 ✓, _strncpy ✓

---

## FUN_004cd8d0 — PASS

All claims verified:
- Multiplies param_2 by _DAT_005acec4: confirmed at .c line 14
- If rounded value == 0: calls FUN_004cb5e0 if count>0: confirmed at lines 15-18
- Count at +0x58 > 0 and count at +100 == 0 → FUN_004024f0: confirmed at lines 22-23
- Computes ROUND(param_2) * 0x1000000 + 0xffffff: confirmed at .c line 25
- Array at param_1+0x68, calls FUN_00558dc0(element, 0-3, iVar2) on 4 channels: confirmed at lines 29-33
- Calls FUN_004cb5e0 ✓, FUN_004024f0 ✓, FUN_00558dc0 ✓

---

## FUN_0057a5a0 — PASS

All claims verified:
- local_4 = param_1: confirmed at .c line 12
- FUN_00584f90() (mutex-guarded timer read): confirmed at .c line 13
- FUN_005836e0(&local_4, fVar2): confirmed at .c line 14
- VTable call at *param_1 + 0x58: confirmed at .c line 15
- FUN_00586800(0, 0xe, 0, 3, 500): confirmed at .c line 16
- Sets *(iVar1+0x48)+4 = 1: confirmed at .c line 17
- FUN_00586a00(&local_4, 4): confirmed at .c line 18
- FUN_00585380(iVar1): confirmed at .c line 19

---

## FUN_0055cee0 — PASS

All claims verified:
- param_1 == 6 (565 format): confirmed at .c line 11
- 565 formula ((R & 0xf8) << 5 | G & 0xfc) << 3 | B >> 3 & 0x1f: confirmed at .c line 12, param_2=R, param_3=G, param_4=B
- param_1 == 5 (555 format): confirmed at .c line 14
- 555 formula ((R & 0xf8) << 5 | G & 0xf8) << 2 | B >> 3 & 0x1f: confirmed at .c line 15
- Otherwise returns 0: confirmed at .c line 10, 17

---

## FUN_00488180 — PASS

All claims verified:
- Calls FUN_00485e30(): confirmed at .c line 8
- Calls FUN_00499b10(): confirmed at .c line 9
- Sets *param_1 = &PTR_FUN_005abb78 (vtable): confirmed at .c line 10
- Sets byte at param_1 + 0x45 = 1: confirmed at .c line 11
- Returns param_1: confirmed at .c line 12

---

## FUN_0052e170 — PASS

All claims verified:
- Calls FUN_0052d9f0(): confirmed at .c line 8
- param_1[0xb4d] = param_2 (property A at +0x2d34): confirmed at .c line 9
- param_1[0xb4e] = param_3 (property B at +0x2d38): confirmed at .c line 10
- Sets *param_1 = &PTR_LAB_005b4810 (vtable): confirmed at .c line 11
- Returns param_1: confirmed at .c line 12

---

## FUN_00489560 — PASS

All claims verified:
- Calls vtable+0x2c(1): confirmed at .c line 10
- Decrements counter [0x53] (+0x14c) by delta [0x59] (+0x164): confirmed at .c line 11
- Clamps to 0 on underflow: confirmed at .c line 13 (uVar1 & ((int)uVar1 < 0) - 1)
- Calls post-update (FUN_00489d00, FUN_00489e90): confirmed at lines 14-15

---

## FUN_0054fc50 — PASS

All claims verified:
- Takes __ftol() result: confirmed at .c line 10
- Multiplies by 0x1010101: confirmed at .c line 11
- Stores at param_1+0x68: confirmed at .c line 11
- RGBA color packing usage: confirmed by multiply pattern 0x1010101

---

## Summary

| Result | Count |
|--------|-------|
| **PASS** | **22/22** |
| **FAIL** | **0/22** |

All 22 function entries audited against their .c source files. Every claim verified — globals, struct offsets, called functions, constants, and logic descriptions match the decompiled source.

