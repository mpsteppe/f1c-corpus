# Worker J — Cross-Validation Audit Results

## FUN_0054A340 — FAIL
Source: docs/17-physics-collision.md

**Errors:**
- [MISSING_GLOBAL] .c references DAT_0059e430 (plane test epsilon) not mentioned in entry

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0054a340 — Spatial Nearest-Object Query Within Sphere

Source: scene_spatial.cpp. Finds nearest visible object within a sphere volume, using portal plane culling for BSP-like spatial subdivision.

**Key logic:**
- Takes query sphere center (param_2+0x24/0x28/0x2c) and radius (param_2+0x18)
- First checks cached result (param_1+0x1a4): if still within sphere, returns it
- Otherwise walks linked list via sibling pointer (offset 0x14) testing portal planes
- Portal test: dot(normal, point) + distance < epsilon (DAT_0059e430) → behind plane, reject
- All 6 portal planes must be passed (frustum-like visibility test)
- Falls back to full search from param_1+0x100 list (stride 0x104)
- Updates cache (param_1+0x1a4) with nearest visible node

**Globals:**
- DAT_0059e430 — plane test epsilon threshold

**Calls:** none

**Moddability:** hardcoded

## FUN_00401910 — FAIL
Source: docs/17-physics-collision.md

**Errors:**
- [WRONG_OFFSET] Entry claims Velocity at +0x08 but .c accesses at pfVar3[8] = byte offset +0x20

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_00401910 — Swept Collision Detection (Time-Stepped)

Source: collision. Detects and resolves collisions between a moving body and two connected bodies by sweeping through time steps.

**Key logic:**
- Iterates array at param_1+0x134 (count at +0x130, stride 0x13c)
- First pass: predicts positions via `pos = velocity * time + initialPos` (pfVar3[0x25-0x27])
- Second pass: for each element with two connected bodies (iVar5, iVar2 non-null):
  - Calls FUN_00401340 (geometry transform) on each body
  - Calls FUN_004e8ce0 with parameter 16.0 (0x41800000) to compute distance metric between bodies
  - Sweeps time from -_DAT_0059e44c to +_DAT_0059e448 in _DAT_0059e444 increments
  - At each step: repositions body by interpolating velocity*time, recomputes distances
  - Tracks best (maximum) collision depth across time steps
  - Finalizes position at best collision time

**Struct offsets (element at param_1+0x134, stride 0x13c):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | Position[0..2] | Body position (x,y,z) |
| +0x20 | Velocity[0..2] | Body velocity |
| +0x0c | Element index/stride | |
| +0x18 | TimeParam | Time scalar used in position prediction |
| +0x94-0x9c | PredictedPos[0..2] | Predicted position = time * velocity + position |
| +0x10c | ConnectedBodyA | Pointer to first connected body |
| +0x110 | ConnectedBodyB | Pointer to second connected body |

**Struct offsets (connected body, stride 0x88):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x70 | CollisionParamA | Distance function parameter |
| +0x74 | CollisionParamB | Distance function parameter |
| +0x78 | CollisionParamC | Distance function parameter |

**Globals:** DAT_0059e444 (time step), DAT_0059e448 (time sweep max), DAT_0059e44c (time sweep min)

**Calls:** FUN_00401340, FUN_004e8ce0 (distance computation)

**Moddability:** hardcoded

## FUN_00498720 — PASS

## FUN_0044E240 — FAIL
Source: docs/17-physics-collision.md

**Errors:**
- [WRONG_CONST] Entry says "Zeros 3 fields between" but .c zeros 4 fields (_DAT_007cd1dc, DAT_007cd1e0, _DAT_007cd1e4, _DAT_007cd1e8)
- [MISSING_GLOBAL] .c zeros _DAT_007cd1dc, DAT_007cd1e0, _DAT_007cd1e4, _DAT_007cd1e8 not mentioned in entry

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0044e240 — ConstraintSolverInit2

Initializes constraint solver global state set 2.

**Key logic:**
- Sets DAT_007cd1d8 = 0x49 (73 — max iterations or constraint count)
- Zeros 4 intermediate fields (_DAT_007cd1dc, DAT_007cd1e0, _DAT_007cd1e4, _DAT_007cd1e8)
- Sets DAT_007cd1ec = 27000 (Baumgarte stabilization factor or ERP)

**Globals:**
- `DAT_007cd1d8` — constraint count/size
- `DAT_007cd1dc` — zeroed
- `DAT_007cd1e0` — zeroed
- `_DAT_007cd1e4` — zeroed
- `_DAT_007cd1e8` — zeroed
- `DAT_007cd1ec` — constraint stabilization factor

**Calls:** none

**Moddability:** hardcoded — solver config

## FUN_0044CA10 — PASS

## FUN_0049B6D0 — PASS

## FUN_004628A0 — PASS

## FUN_0044D310 — PASS

## FUN_0045C7E0 — PASS

## FUN_0044ECC0 — PASS

## FUN_0044D4F0 — PASS

## FUN_0044B090 — PASS

## FUN_0049E520 — PASS

## FUN_0044D670 — PASS

## FUN_00498030 — FAIL
Source: docs/17-physics-collision.md

**Errors:**
- [WRONG_CONST] Entry says "if < _DAT_0059e43c→1.0" but .c shows if > _DAT_0059e43c → 1.0 (else branch)

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_00498030 — Color Alpha Clamp and Apply

Source: collision/renderer. Clamps collision color alpha and applies via vtable call.

**Key logic:**
- If param_1 != NULL: sets DAT_005cc9e0 = DAT_007cf2cc (input alpha)
- If input > _DAT_0059e43c: clamps to 1.0
- If input < DAT_0059e440: clamps to 0.0
- Between thresholds: keeps original value
- Calls vtable function with clamped alpha

**Globals:**
- `DAT_007cf2cc` — input alpha value
- `DAT_005cc9e0` — clamped alpha output

**Moddability:** hookable (vtable call)

## FUN_0045F2A0 — PASS

## FUN_0044CF50 — PASS

## FUN_00486830 — PASS

## FUN_00591727 — PASS

## FUN_004E49B0 — PASS

## FUN_004E4F40 — PASS

## FUN_004359A0 — PASS

## FUN_005267A7 — PASS

## FUN_00448570 — PASS

## FUN_005670D0 — PASS

## FUN_0043EC50 — PASS

## FUN_0043B930 — PASS

## FUN_004624E0 — PASS

## FUN_0043BB00 — PASS

## FUN_005694E0 — PASS

## FUN_0050E887 — PASS

## FUN_004DD8F0 — PASS

## FUN_004B3DC0 — PASS

## FUN_00411DB0 — PASS

## FUN_00486280 — PASS

## FUN_00489AB0 — PASS

## FUN_00494F10 — PASS

## FUN_00499A00 — PASS

## FUN_00560547 — PASS

## FUN_00547B40 — PASS

## FUN_0044B370 — PASS

## FUN_004CD6C0 — PASS

## FUN_0052804A — PASS

## FUN_0050AB51 — PASS

## FUN_00452810 — PASS

## FUN_00403350 — PASS

## FUN_00512093 — PASS

## FUN_00561AF8 — PASS

## FUN_00542950 — PASS

## FUN_00543250 — PASS

## FUN_004184F0 — PASS

## FUN_004C9310 — PASS

## FUN_004796C0 — PASS

## FUN_004F9F70 — PASS

## FUN_00581EE0 — PASS

## FUN_0057E570 — PASS

## FUN_0053A660 — PASS

## FUN_004EF2E0 — PASS

## FUN_0059868A — PASS

## FUN_00551DD0 — PASS

## FUN_0057C7B0 — PASS

## FUN_00566DF0 — PASS

## FUN_0050070D — PASS

## FUN_0059416F — PASS
## FUN_00591D88 — PASS
## FUN_00589BF3 — PASS
## FUN_00567B00 — PASS
## FUN_0058850F — PASS
## FUN_005919DA — PASS
## FUN_00592787 — PASS
## FUN_005531F0 — PASS
## FUN_00593DD3 — PASS
## FUN_00568BE0 — PASS
## FUN_004647D0 — PASS
## FUN_0052A090 — PASS
## FUN_004F7000 — PASS
## FUN_00423AD0 — PASS
## FUN_00479CD0 — PASS
## FUN_00494C20 — PASS
## FUN_004B9FA0 — PASS
## FUN_004FF0E0 — PASS
## FUN_0053B490 — PASS
## FUN_0058BDCD — PASS
## FUN_0059C972 — PASS
## FUN_0045CE30 — PASS
## FUN_00485E30 — PASS
## FUN_004A3320 — PASS
## FUN_004D7B00 — PASS
## FUN_00515E85 — PASS
## FUN_00565EB0 — PASS
## FUN_00587B97 — PASS
## FUN_0047C940 — PASS
## FUN_004FF2B0 — PASS
## FUN_0058BFEC — PASS
## FUN_00406250 — PASS
## FUN_004636F0 — PASS
## FUN_00488B00 — PASS
## FUN_004A1D10 — PASS
## FUN_004D1030 — PASS
## FUN_0050D96D — PASS
## FUN_005692A0 — PASS
## FUN_0046D680 — PASS
## FUN_0040FDD0 — PASS
## FUN_00487760 — PASS
## FUN_004A0D10 — PASS
## FUN_004CE380 — PASS
## FUN_0050C887 — PASS
## FUN_00546330 — PASS
## FUN_0059AE61 — PASS
## FUN_00414010 — PASS
## FUN_00471750 — PASS
## FUN_00491D30 — PASS
## FUN_004B48E0 — PASS
## FUN_004F2B50 — PASS
## FUN_005567D3 — PASS
## FUN_00590640 — PASS
## FUN_0040D490 — PASS
## FUN_0046A980 — PASS
## FUN_0048F5D0 — PASS
## FUN_004B21D0 — PASS
## FUN_004DB520 — PASS
## FUN_00513E2D — PASS
## FUN_0054FE00 — PASS
## FUN_005523E0 — PASS
## FUN_00486330 — PASS
## FUN_005490B0 — PASS
## FUN_0059A38D — PASS
## FUN_0045BFF0 — PASS
## FUN_00485690 — PASS
## FUN_0049AD50 — PASS
## FUN_004C82F0 — PASS
## FUN_0050A911 — PASS
## FUN_0053D8B0 — PASS
## FUN_0059508D — PASS
## FUN_00589D62 — PASS
## FUN_00563EB0 — PASS
## FUN_0051512C — PASS
## FUN_004DCB70 — PASS
## FUN_004B2B00 — PASS
## FUN_00490390 — PASS
## FUN_00464B40 — PASS
## FUN_004BC2D0 — PASS
## FUN_004F9B20 — PASS
## FUN_00534E70 — PASS
## FUN_005853B0 — PASS
## FUN_005679C0 — PASS
## FUN_0059D150 — PASS
## FUN_0045E590 — PASS
## FUN_00486460 — PASS
## FUN_0049DA60 — PASS
## FUN_004C91D0 — PASS
## FUN_0050B446 — PASS
## FUN_005423C0 — PASS
## FUN_00599904 — PASS
## FUN_004058D0 — PASS
## FUN_00462460 — PASS
## FUN_00487ED0 — PASS
## FUN_004A0FB0 — PASS
## FUN_004CF010 — PASS
## FUN_0050D563 — PASS
## FUN_005470A0 — PASS
## FUN_0059BF19 — PASS
## FUN_00408250 — PASS
## FUN_00464D30 — PASS
## FUN_0048B910 — PASS
## FUN_004A8B30 — PASS
## FUN_004D7E40 — PASS
## FUN_00513374 — PASS
## FUN_0054FB90 — PASS
## FUN_0057B630 — PASS
## FUN_00423250 — PASS
## FUN_00489500 — PASS
## FUN_004A2770 — PASS
## FUN_004D47E0 — PASS
## FUN_0050FA0E — PASS
## FUN_005493B0 — PASS
## FUN_00586F70 — PASS
## FUN_0047A580 — PASS
## FUN_004C7C10 — PASS
## FUN_0054FC40 — PASS
## FUN_0059A4C9 — PASS
## FUN_0051593F — PASS
## FUN_0058E1B0 — PASS
## FUN_00464F90 — PASS
## FUN_0048C070 — PASS
## FUN_004B01B0 — PASS
## FUN_004D7FE0 — PASS
## FUN_00511F23 — PASS
## FUN_0054C0E0 — PASS
## FUN_0059DB5B — PASS
## FUN_004144D0 — PASS
## FUN_00472BC0 — PASS
## FUN_00494A30 — PASS
## FUN_004B72A0 — PASS
## FUN_004E2AD0 — PASS
## FUN_0051CB6D — PASS
## FUN_00564A20 — PASS
## FUN_004141F0 — PASS
## FUN_00479970 — PASS
## FUN_004991E0 — PASS
## FUN_0059C65C — PASS
## FUN_0059D580 — PASS
## FUN_0059C40A — PASS
## FUN_0059CF2F — PASS
## FUN_0059D050 — PASS
## FUN_0059D594 — PASS

