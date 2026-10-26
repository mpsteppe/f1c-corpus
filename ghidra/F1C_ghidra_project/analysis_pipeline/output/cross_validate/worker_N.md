# Cross-Validation Audit — Worker N (Items 2680–2885)

## FUN_004DE610 — PASS

## FUN_0051D247 — PASS

## FUN_0044D8B0 — PASS

## FUN_0044F7D0 — PASS

## FUN_0044E870 — PASS

## FUN_0044E360 — FAIL
Source: docs/17-physics-collision.md

**Errors:**
- [WRONG_MODDABILITY] Entry claims `configurable` but source has no config/field-name string literal

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0044e360 — Global State Initializer (Collision Set 3)

Source: physics_globals.cpp. Initializes collision parameters with spring/damper defaults.

**Key logic:**
- Sets DAT_007cd118 = 0x4c (76)
- Zeroes DAT_007cd11c, DAT_007cd120, DAT_007cd124, DAT_007cd128
- Sets DAT_007cd12c = 18000 (max deformation/force limit)

**Moddability:** hardcoded

## FUN_0044CB30 — PASS

## FUN_0045B840 — PASS

## FUN_0044E4E0 — PASS

## FUN_0044CCB0 — PASS

## FUN_00453100 — PASS

## FUN_0044E660 — FAIL
Source: docs/17-physics-collision.md

**Errors:**
- [WRONG_MODDABILITY] Entry claims `configurable` but source has no config/field-name string literal

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0044e660 — Collision Global Struct Init (Block 0x54 with 18000)

Source: collision system. Initializes a global collision configuration block with a distance threshold.

**Key logic:**
- Sets DAT_007cd04c = 0x54 (block type/size identifier)
- Zeroes 4 consecutive int fields at offsets +0x50 through +0x5c
- Sets DAT_007cd060 = 18000 (distance/contact threshold in cm? = 180m)

**Globals:**
- `DAT_007cd04c` through `DAT_007cd060` — collision configuration variables

**Moddability:** hardcoded

## FUN_0044CE30 — PASS

## FUN_0044A700 — PASS

## FUN_0045C7C0 — PASS

## FUN_0044FBE0 — PASS

## FUN_0044D2E0 — PASS

## FUN_004BA140 — PASS

## FUN_0056CD70 — PASS

## FUN_004F1C40 — PASS

## FUN_00496560 — PASS

## FUN_004F01B0 — PASS

## FUN_00425670 — PASS

## FUN_00495440 — PASS

## FUN_0043E980 — PASS

## FUN_00448DA0 — PASS

## FUN_005674C0 — PASS

## FUN_00441360 — PASS

## FUN_00443AF0 — PASS

## FUN_004B2980 — PASS

## FUN_0053B5B0 — PASS

## FUN_004ED7B0 — PASS

## FUN_004C8B70 — PASS

## FUN_00413710 — PASS

## FUN_00486300 — PASS

## FUN_00489FD0 — PASS

## FUN_00497650 — PASS

## FUN_0045BC10 — PASS

## FUN_00560410 — PASS

## FUN_00543BF0 — PASS

## FUN_00513F7A — PASS

## FUN_00502F31 — PASS

## FUN_0051CE2A — PASS

## FUN_00495DC0 — PASS

## FUN_0051D6D2 — PASS

## FUN_0059B250 — PASS

## FUN_0051D80A — PASS

## FUN_004900A0 — PASS

## FUN_00558DC0 — PASS

## FUN_0050F0BF — PASS

## FUN_00485960 — PASS

## FUN_0050AE92 — PASS

## FUN_0047F3F0 — PASS

## FUN_005424C0 — PASS

## FUN_00596A2E — PASS

## FUN_0059C30E — PASS

## FUN_00566380 — PASS

## FUN_005609DE — PASS

## FUN_00595F11 — PASS

## FUN_00552910 — PASS

## FUN_0059070A — PASS

## FUN_005817A0 — PASS

## FUN_005903C0 — PASS

## FUN_00592A62 — PASS

## FUN_00494BF0 — PASS

## FUN_0053B3B0 — PASS

## FUN_00563DF0 — PASS

## FUN_0045CD50 — PASS

## FUN_00599689 — PASS

## FUN_00498F40 — PASS

## FUN_004C03A0 — PASS

## FUN_0050B20C — PASS

## FUN_00542680 — PASS

## FUN_0059A765 — PASS

## FUN_00406100 — PASS

## FUN_00464940 — PASS

## FUN_00489EE0 — PASS

## FUN_004B29F0 — PASS

## FUN_004DCFB0 — PASS

## FUN_00525E9A — PASS

## FUN_00586A90 — PASS

## FUN_00406230 — PASS

## FUN_00498F70 — PASS

## FUN_00513D2F — PASS

## FUN_0050B425 — PASS

## FUN_0040D410 — PASS

## FUN_0046A900 — PASS

## FUN_0048F300 — PASS

## FUN_004B2180 — PASS

## FUN_004DB070 — PASS

## FUN_00515F23 — PASS

## FUN_00587A50 — PASS

## FUN_00474F40 — PASS

## FUN_0041FDB0 — PASS

## FUN_0048D740 — PASS

## FUN_004B1950 — PASS

## FUN_004D8860 — PASS

## FUN_00512183 — PASS

## FUN_0054D4E0 — PASS

## FUN_00567700 — PASS

## FUN_00421A10 — PASS

## FUN_004782A0 — PASS

## FUN_00498730 — PASS

## FUN_004C16B0 — PASS

## FUN_005110FC — PASS

## FUN_00586FA0 — PASS

## FUN_0059C6DE — PASS

## FUN_00415680 — PASS

## FUN_00473B00 — PASS

## FUN_00495020 — PASS

## FUN_004B9860 — PASS

## FUN_004E4FB0 — PASS

## FUN_0051EA90 — PASS

## FUN_00566BD0 — PASS

## FUN_00569280 — PASS

## FUN_004998C0 — PASS

## FUN_0056D3E0 — PASS

## FUN_00406A70 — PASS

## FUN_00463C60 — PASS

## FUN_00488FB0 — PASS

## FUN_004A1F60 — PASS

## FUN_004D2DD0 — PASS

## FUN_0050DD0C — PASS

## FUN_00547670 — PASS

## FUN_0050CDF9 — PASS

## FUN_0057AE00 — PASS

## FUN_0053CB20 — PASS

## FUN_0050C0A6 — PASS

## FUN_004C1E40 — PASS

## FUN_0049D700 — PASS

## FUN_004863C0 — PASS

## FUN_0045D730 — PASS

## FUN_004C5DE0 — PASS

## FUN_005043C9 — PASS

## FUN_0053CB90 — PASS

## FUN_0058DD3E — PASS

## FUN_00586DE0 — PASS

## FUN_00404D10 — PASS

## FUN_00464BD0 — PASS

## FUN_0048B810 — PASS

## FUN_004A4030 — PASS

## FUN_004D5C70 — PASS

## FUN_0050F86A — PASS

## FUN_005492B0 — PASS

## FUN_0059D7EA — PASS

## FUN_0040C8D0 — PASS

## FUN_00468610 — PASS

## FUN_0048E650 — PASS

## FUN_004B1A50 — PASS

## FUN_004D90D0 — PASS

## FUN_00512850 — PASS

## FUN_0054EE90 — PASS

## FUN_0050E198 — PASS

## FUN_0040F0D0 — PASS

## FUN_0046E7D0 — PASS

## FUN_00490920 — PASS

## FUN_004B43E0 — PASS

## FUN_004DD7C0 — PASS

## FUN_0051C3E2 — PASS

## FUN_005645B0 — PASS

## FUN_00597CC0 — PASS

## FUN_0045E5F0 — PASS

## FUN_0048FD80 — PASS

## FUN_004B2750 — PASS

## FUN_004DBF90 — PASS

## FUN_00516853 — PASS

## FUN_00559350 — PASS

## FUN_00591E66 — PASS

## FUN_00498DF0 — PASS

## FUN_004F8D10 — PASS

## FUN_00567A30 — PASS

## FUN_00411680 — PASS

## FUN_00540240 — PASS

## FUN_00407810 — PASS

## FUN_0046EFE0 — PASS

## FUN_00490B00 — PASS

## FUN_004B44A0 — PASS

## FUN_004DE5D0 — PASS

## FUN_00517F58 — PASS

## FUN_0055EEAF — PASS

## FUN_005879F0 — PASS

## FUN_004234C0 — PASS

## FUN_00479730 — PASS

## FUN_00498E50 — PASS

## FUN_004BD7D0 — PASS

## FUN_004FAD80 — PASS

## FUN_00535550 — PASS

## FUN_00585E60 — PASS

## FUN_00421AB0 — PASS

## FUN_004856F0 — PASS

## FUN_0049ADC0 — PASS

## FUN_0059C8E6 — PASS

## FUN_00599D31 — PASS

## FUN_0059C6F2 — PASS

## FUN_0059C4A0 — PASS

## FUN_0059D2C7 — PASS

## FUN_0043EC00 — PASS

## FUN_00551EB0 — PASS

## FUN_00565080 — FAIL
Source: docs/21-audio-network-internals.md

**Errors:**
- [WRONG_DESCRIPTION] Entry claims "Audio DSP — applies volume ramp/pan to sample buffer" but source implements stream cipher key scheduling (RC4 KSA-like): zeroes 256 dwords, linear fill with `table[i] = table[i] * 0x100 + i`, two rounds of key-dependent permutation swaps, XOR self `table[i] = table[i] ^ i`, calls FUN_00564dd0(0)

**Corrected entry:**
<!-- target: docs/21-audio-network-internals.md -->
## FUN_00565080 — Stream Cipher Key Setup (RC4-like)

Source: unknown. Initializes 256-byte permutation table with key-dependent shuffling.

**Key logic:**
- Zeroes 0x400 bytes (256 dwords)
- Linear fill: `table[i] = table[i] * 0x100 + i`
- Two rounds of key-dependent permutation swaps
- XOR self: `table[i] = table[i] ^ i`
- Calls FUN_00564dd0(0)

**Calls:** FUN_00564dd0

**Moddability:** hardcoded

## FUN_00580C10 — PASS

## FUN_00537D10 — PASS

## FUN_0057AFA0 — PASS

## FUN_00566B20 — PASS

## FUN_00598654 — PASS

## FUN_0054FD50 — PASS

## FUN_00549440 — PASS
Source: docs/17-physics-collision.md

**Errors:**
- [WRONG_MODDABILITY] Entry claims `configurable` but source has no config/field-name string literal

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0044e660 — Collision Global Struct Init (Block 0x54 with 18000)

Source: collision system. Initializes a global collision configuration block with a distance threshold.

**Key logic:**
- Sets DAT_007cd04c = 0x54 (block type/size identifier)
- Zeroes 4 consecutive int fields at offsets +0x50 through +0x5c
- Sets DAT_007cd060 = 18000 (distance/contact threshold in cm? = 180m)

**Globals:**
- `DAT_007cd04c` through `DAT_007cd060` — collision configuration variables

**Moddability:** hardcoded
Source: docs/17-physics-collision.md

**Errors:**
- [WRONG_MODDABILITY] Entry claims `configurable` but source has no config/field-name string literal

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0044e360 — Global State Initializer (Collision Set 3)

Source: physics_globals.cpp. Initializes collision parameters with spring/damper defaults.

**Key logic:**
- Sets DAT_007cd118 = 0x4c (76)
- Zeroes DAT_007cd11c, DAT_007cd120, DAT_007cd124, DAT_007cd128
- Sets DAT_007cd12c = 18000 (max deformation/force limit)

**Moddability:** hardcoded
