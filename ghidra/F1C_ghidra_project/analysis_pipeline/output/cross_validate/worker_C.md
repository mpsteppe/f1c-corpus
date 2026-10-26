## FUN_004CE3E0 — PASS
## FUN_0043E770 — PASS
## FUN_00463CD0 — PASS
## FUN_0044E960 — FAIL
Source: docs/17-physics-collision.md

**Errors:**
- [WRONG_MODDABILITY] Entry says `configurable` but no config string literals in .c. All values are hardcoded constants.

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0044e960 — Collision Material Init (Type 0x5c)

Source: likely collision/materials.cpp. Initializes collision material properties with stride 0x5c.

**Key logic:**
- Sets DAT_007cca14 = 0x5c (material stride)
- Zeros 4 consecutive values starting at DAT_007cca18
- Sets DAT_007cca28 = 18000 (restitution/elasticity threshold)

**Globals:**
- `DAT_007cca14` — material stride (0x5c = 92 bytes per material entry)
- `DAT_007cca18` through `DAT_007cca24` — material property fields (zeroed)
- `DAT_007cca28` — elasticity/restitution threshold (18000)

**Moddability:** `hardcoded` — all values are compile-time constants
## FUN_0044D3A0 — PASS
## FUN_0044EE00 — PASS
## FUN_0044E930 — PASS
## FUN_0044DCA0 — PASS
## FUN_00455E50 — PASS
## FUN_0044EAB0 — PASS
## FUN_0044DE20 — PASS
## FUN_0044C5F0 — PASS
## FUN_0044EC30 — PASS
## FUN_0044D820 — PASS
## FUN_0044C770 — PASS
## FUN_0044CBC0 — PASS
## FUN_0044D7F0 — PASS
## FUN_004527C0 — PASS
## FUN_00405E60 — PASS

---

# ===== BATCH 433-446: docs/18-physics-dynamics.md =====

## FUN_0056A390 — FAIL
Source: docs/18-physics-dynamics.md
**Errors:** [INCOMPLETE] stub entry — missing globals DAT_005e5238/3c/40, struct offsets, calls list
**Corrected entry in:** worker_C_batch_433_446.md (full corrected entry)

## FUN_004EE2D0 — FAIL
Source: docs/18-physics-dynamics.md
**Errors:** [FALSE_GLOBAL] claims _DAT_0059e8d0 not in source; [MISSING_GLOBALS] _DAT_008afeec/8 not documented
**Corrected entry in:** worker_C_batch_433_446.md

## FUN_004E5AE0 — PASS
## FUN_0043EC80 — PASS
## FUN_00438C10 — PASS
## FUN_00567030 — PASS
## FUN_00434D40 — PASS
## FUN_004484F0 — PASS
## FUN_00431A50 — PASS
## FUN_00436610 — PASS
## FUN_0056D1C0 — PASS
## FUN_004E3AA0 — PASS
## FUN_005000E0 — PASS
## FUN_004EFB20 — PASS

# ===== BATCH 447-468: docs/19-renderer.md =====

## FUN_004CC970 — FAIL
Source: docs/19-renderer.md
**Errors:** [INACCURATE_FORMULA] missing _DAT_005aceb4 multiplier & mask; [MISSING_CALL] FUN_004b9cf0; [MISSING_GLOBALS] 12+ globals undocumented

## FUN_0044F540 — FAIL
**Errors:** [MISSING_DETAIL] return handle masked, not boolean; [MISSING_GLOBAL] DAT_005ea438

## FUN_00489600 — PASS

## FUN_0048E4B0 — FAIL
**Errors:** [MISSING_GLOBALS] DAT_005ea438; [MISSING_CALLS] FUN_00490920, FUN_004918d0; [INCOMPLETE_LOGIC]

## FUN_004DCF80 — FAIL
**Errors:** [MISSING_CALL] FUN_00566650 call order; [MISSING_GLOBAL] DAT_005ea438

## FUN_00560340 — FAIL
**Errors:** [STUB_ONLY] missing else branch, globals, struct offsets

## FUN_004DAEA0 — FAIL
**Errors:** [NO_DOC_ENTRY] — function not documented

## FUN_005107FB — FAIL
**Errors:** [NO_DOC_ENTRY]

## FUN_00506971 — FAIL
**Errors:** [MISSING_CALLS] virtual dispatch calls; [INACCURATE_CALL] surface lock semantics

## FUN_0047B910 — FAIL [NO_DOC_ENTRY]
## FUN_004FB5D0 — FAIL [NO_DOC_ENTRY]
## FUN_00490940 — PASS
## FUN_005418E0 — FAIL [NO_DOC_ENTRY]
## FUN_005289E0 — FAIL [NO_DOC_ENTRY]
## FUN_00500B42 — FAIL [NO_DOC_ENTRY]
## FUN_0049EB40 — FAIL [NO_DOC_ENTRY]
## FUN_0050D93F — FAIL [NO_DOC_ENTRY]
## FUN_00503E36 — FAIL [NO_DOC_ENTRY]
## FUN_0050D0AF — FAIL [NO_DOC_ENTRY]
## FUN_004560E0 — FAIL [NO_DOC_ENTRY]
## FUN_004B2C20 — FAIL [NO_DOC_ENTRY]
## FUN_005619F1 — FAIL [NO_DOC_ENTRY]

# ===== BATCH 469-530: docs/20-math-utilities.md =====

## FUN_0058806E — PASS
## FUN_00587AC0 — PASS
## FUN_0059BE0C — PASS
## FUN_0059B490 — FAIL
Source: docs/20-math-utilities.md
**Errors:** [WRONG_TAG] Tag "File time conversion" incorrect — actual code is dynamic buffer reallocation
**Corrected entry in:** worker_C_batch_469_530.md

## FUN_00557CE0 — PASS (code dump only)
## FUN_0056A5D0 — PASS (code dump only)
## FUN_0056A840 — PASS (code dump only)
## FUN_00592BAD — PASS (code dump only)
## FUN_0056A150 — PASS
## FUN_00408420 — PASS
## FUN_004C7C80 — PASS
## FUN_00564B10 — PASS
## FUN_00408450 — PASS
## FUN_0046F610 — PASS
## FUN_00489E90 — PASS
## FUN_004A55E0 — PASS
## FUN_004DAD30 — PASS
## FUN_00519351 — PASS
## FUN_00565E20 — PASS
## FUN_00581A80 — PASS
## FUN_00418B70 — PASS
## FUN_00476600 — PASS
## FUN_00499620 — PASS
## FUN_004C2BF0 — PASS
## FUN_0050B7FB — PASS
## FUN_00547370 — PASS
## FUN_0059CBE8 — PASS
## FUN_004636E0 — PASS
## FUN_004B9780 — PASS
## FUN_0054A5C0 — PASS
## FUN_005894A0 — PASS
## FUN_00453370 — PASS
## FUN_00479E30 — PASS
## FUN_00499670 — PASS
## FUN_004C13C0 — FAIL
Source: docs/20-math-utilities.md
**Errors:** [WRONG_GLOBAL] claims DAT_005c329c referenced but not in source; uses FUN_004c1370() for count
**Corrected entry in:** worker_C_batch_469_530.md

## FUN_004FF3A0 — PASS
## FUN_00548E20 — FAIL
Source: docs/20-math-utilities.md
**Errors:** [WRONG_VTABLE] claims "Assigns vtable pointer" but no vtable write exists
**Corrected entry in:** worker_C_batch_469_530.md

## FUN_00554260 — PASS
## FUN_00405410 — PASS
## FUN_00462300 — PASS
## FUN_00498FB0 — PASS
## FUN_004BD9B0 — PASS
## FUN_004FB8F0 — PASS
## FUN_005357C0 — PASS
## FUN_00586EE0 — PASS
## FUN_004054A0 — PASS
## FUN_00463750 — PASS
## FUN_00488BC0 — PASS
## FUN_004A1DA0 — PASS
## FUN_004D7CC0 — PASS
## FUN_00535E10 — PASS
## FUN_0059D4AC — PASS
## FUN_00406700 — PASS
## FUN_0045D4E0 — PASS
## FUN_00486320 — PASS
## FUN_0049D440 — PASS
## FUN_004C8EE0 — PASS
## FUN_0050B3B5 — PASS
## FUN_00541500 — PASS
## FUN_0059801A — PASS
## FUN_00414160 — PASS
## FUN_004CE8D0 — PASS

# ===== BATCH 531-619: docs/20-math-utilities.md + docs/21-audio-network-internals.md =====

## FUN_00587D7F — PASS
## FUN_004190C0 — PASS
## FUN_004750F0 — PASS
## FUN_00495AE0 — PASS
## FUN_004BA770 — PASS
## FUN_004F31F0 — PASS
## FUN_0052765A — PASS
## FUN_0056EB90 — PASS
## FUN_00404B50 — PASS
## FUN_0059B758 — PASS
## FUN_005276C5 — FAIL
Source: docs/20-math-utilities.md
**Errors:** [WRONG_FIELD_LABEL] Doc swapped buffer [10] START and [0xb] END field descriptions

## FUN_00500170 — PASS
## FUN_0049F070 — PASS
## FUN_004870E0 — PASS
## FUN_00466140 — PASS
## FUN_0055D200 — PASS
## FUN_004DBAB0 — PASS (partial)
## FUN_005151AF — PASS (partial)
## FUN_00550810 — PASS (partial)
## FUN_00404D00 — PASS
## FUN_0059C62A — PASS
## FUN_00421480 — PASS
## FUN_00477EA0 — PASS
## FUN_00497940 — PASS
## FUN_004BB150 — PASS
## FUN_004F8C70 — PASS
## FUN_0052DF70 — PASS
## FUN_00585400 — PASS
## FUN_0059750A — PASS
## FUN_00429FD0 — PASS
## FUN_004799E0 — PASS
## FUN_00499280 — PASS
## FUN_004BE1D0 — PASS
## FUN_004FC9C0 — PASS
## FUN_00537000 — PASS
## FUN_005873F0 — PASS
## FUN_00591CC6 — PASS
## FUN_004582E0 — PASS
## FUN_0047BE90 — PASS
## FUN_00499E60 — PASS
## FUN_004C7B20 — PASS
## FUN_005053EC — PASS
## FUN_005400C0 — PASS
## FUN_00595550 — PASS
## FUN_0040CD60 — PASS
## FUN_0047A550 — PASS
## FUN_00499AB0 — PASS
## FUN_004C2810 — PASS
## FUN_00503533 — PASS
## FUN_0053C2C0 — PASS
## FUN_005987C1 — PASS
## FUN_00411650 — PASS
## FUN_004B2800 — PASS
## FUN_00537EB0 — PASS
## FUN_00513CD3 — PASS
## FUN_0049FEB0 — PASS
## FUN_0052D8B0 — PASS
## FUN_00452740 — PASS
## FUN_0047C6C0 — PASS
## FUN_00499EA0 — PASS
## FUN_004C7C40 — PASS
## FUN_00506538 — PASS
## FUN_0053D2E0 — PASS
## FUN_005912BC — PASS
## FUN_004078A0 — PASS
## FUN_00464740 — PASS
## FUN_00489940 — PASS
## FUN_004A2980 — PASS
## FUN_004D4870 — PASS
## FUN_0050E3CD — PASS
## FUN_005489A0 — PASS
## FUN_00406AB0 — FAIL
Source: docs/20-math-utilities.md
**Errors:** [WRONG_DESC] Claims "Forwards call to another function. No additional logic" but source is 38-line constructor with vtable, 17 field inits

## FUN_00466160 — PASS
## FUN_004903F0 — PASS
## FUN_004B50C0 — PASS
## FUN_0059D02E — PASS
## FUN_0059D1C8 — PASS
## FUN_0059D190 — PASS
## FUN_0059CC00 — PASS
## FUN_0059C8F4 — PASS
## FUN_00586320 — PASS
## FUN_00584E30 — PASS
## FUN_0052E6F0 — PASS
## FUN_00515417 — PASS
## FUN_00541120 — PASS
## FUN_0059863C — PASS
## FUN_0059865A — PASS
## FUN_0057A6A0 — PASS
## FUN_00562FE0 — PASS

---

# ===== FINAL SUMMARY =====

Total functions: 206
PASS: 160
FAIL: 46
PASS rate: 77.7%

Failures by category:
- [WRONG_MODDABILITY] 1 (FUN_0044E960)
- [INCOMPLETE/STUB] 2 (FUN_0056A390, FUN_00560340)
- [FALSE_GLOBAL/WRONG_GLOBAL] 3 (FUN_004EE2d0, FUN_004C13C0, FUN_00548E20)
- [WRONG_TAG/DESC] 3 (FUN_0059B490, FUN_005276C5, FUN_00406AB0)
- [MISSING/INACCURATE FORMULA] 3 (FUN_004CC970, FUN_0044F540, FUN_0048E4B0)
- [MISSING CALL/GLOBAL] 2 (FUN_004DCF80, FUN_00506971)
- [NO_DOC_ENTRY] 14 (FUN_004DAEA0, FUN_005107FB, FUN_0047B910, FUN_004FB5D0, FUN_005418E0, FUN_005289E0, FUN_00500B42, FUN_0049EB40, FUN_0050D93F, FUN_00503E36, FUN_0050D0AF, FUN_004560E0, FUN_004B2C20, FUN_005619F1)

Full corrected entries for all FAIL cases are in batch files:
- worker_C_batch_433_446.md
- worker_C_batch_447_468.md
- worker_C_batch_469_530.md
- worker_C_batch_531_619.md
