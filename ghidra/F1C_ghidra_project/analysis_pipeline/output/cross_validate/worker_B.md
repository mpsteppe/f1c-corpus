# Worker B — Cross-Validation Audit

## FUN_004C9FB0 — PASS

## FUN_00403640 — PASS

## FUN_0044E900 — PASS

## FUN_0044E1E0 — FAIL
Source: docs/17-physics-collision.md

**Errors:**
- [WRONG_MODDABILITY] Entry says `configurable` but no config string literal in .c; values are hardcoded constants

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
### FUN_0044e1e0 — Collision Material Init (Type 0x48)

Source: likely collision/materials.cpp. Initializes collision material properties with stride 0x48.

**Key logic:**
- Sets DAT_007ccf48 = 0x48 (material stride)
- Zeros 4 consecutive values starting at DAT_007ccf4c
- Sets DAT_007ccf5c = 18000 (restitution/elasticity threshold)

**Globals:**
- `DAT_007ccf48` — material stride (0x48 = 72 bytes per material entry)
- `DAT_007ccf4c` through `DAT_007ccf58` — material property fields (zeroed)
- `DAT_007ccf5c` — elasticity/restitution threshold (18000)

**Moddability:** `hardcoded`

## FUN_0049E5B0 — FAIL
Source: docs/17-physics-collision.md

**Errors:**
- [WRONG_MODDABILITY] Entry says `configurable` but no config string literal in .c; threshold globals are hardcoded constants

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
### FUN_0049e5b0 — Float Depth Quantization/Packing

Source: collision/terrain. Quantizes a float depth value into packed 32-bit format based on range thresholds.

**Key logic:**
- Compares `param_1` against cascade thresholds:
  - **If param_1 >= _DAT_0059e468:**
    - **If param_1 <= _DAT_005acb08:**
      - **If param_1 < _DAT_005acb00:** → falls through to default (below)
      - **If param_1 < _DAT_005acb04:** → `ftol()` → `result | 0xffff0000` (medium range)
    - **Else (param_1 > _DAT_005acb08):** → `(ftol() | 0xffffff00) << 8` (far range)
  - **Else (param_1 < _DAT_0059e468):** → `ftol() << 16 | 0xff0000ff` (near range, default)
- Converts float to int via `__ftol()` (MSVC inline) then packs with range-specific bit patterns

**Globals:**
- `_DAT_0059e468` — near->medium threshold
- `_DAT_005acb00` — medium sub-range low
- `_DAT_005acb04` — medium sub-range high
- `_DAT_005acb08` — medium->far threshold

**Calls:** __ftol (float-to-int truncation)

**Moddability:** `hardcoded`

## FUN_0044CE00 — PASS

## FUN_0044E1B0 — PASS

## FUN_0044D520 — PASS

## FUN_0044CF80 — FAIL
Source: docs/17-physics-collision.md

**Errors:**
- [WRONG_MODDABILITY] Entry says `configurable` but no config string literal in .c; values are hardcoded constants

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
### FUN_0044cf80 — Collision Region Init 6 (Type 39, -1.0f)

Source: likely_collision_region.cpp. Initializes global collision region with float sentinel.

**Key logic:**
- DAT_007ca480 = 0x27 (39) — region type
- DAT_007ca484 = 0
- DAT_007ca488 = 0xbf800000 (-1.0f) — sentinel/direction
- DAT_007ca48c = 0

**Globals:**
- `DAT_007ca480` — region type (39)
- `DAT_007ca488` — float -1.0f

**Moddability:** `hardcoded`

## FUN_0044E330 — PASS

## FUN_0044D6A0 — PASS

## FUN_0044D100 — PASS

## FUN_0044E4B0 — PASS

## FUN_00498740 — PASS

## FUN_0044D280 — PASS

## FUN_00459950 — PASS

## FUN_0044D010 — PASS

## FUN_004491C0 — PASS

## FUN_004038E0 — PASS

## FUN_00561660 — PASS
Note: Brief stub entry. Directionally correct.

## FUN_00496030 — PASS

## FUN_004D68A0 — FAIL
Source: docs/18-physics-dynamics.md

**Errors:**
- [WRONG_MODDABILITY] Entry says `configurable` but no config string literal in .c; all tire parameters are hardcoded constants

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
### FUN_004d68a0 — Tire Model Default Parameter Initialization

Source: tire_model.cpp. Initializes Pacejka magic formula coefficients and tire parameters with default values.

**Key logic:**
- Sets [0]: B (stiffness factor) = 0.4 (0x3fd4cccc...)
- Sets [1..3]: C (shape), D (peak), E (curvature) copied same values
- Sets [8..9]: vertical/lateral friction scale factors to 1.0
- Sets [12..13]: longitudinal friction coefficients
- Sets [30..31]: camber stiffness coefficients
- Sets [37..39]: relaxation length parameters
- Sets [44..47]: load sensitivity coefficients
- Sets [75..76]: max load and radius limits
- Defaults flags [76] to 0.5, [77] to 0xffffffff (disabled features)

**Calls:** none

**Moddability:** `hardcoded`

## FUN_004313C0 — PASS

## FUN_00448E50 — PASS

## FUN_00448F00 — PASS

## FUN_00431C00 — PASS

## FUN_004496D0 — PASS

## FUN_00434240 — PASS
Note: Script false positive for FUN_0043bbd0 (section boundary artifact, not part of entry)

## FUN_004414D0 — PASS

## FUN_004358F0 — PASS

## FUN_0040F550 — PASS

## FUN_004E7F39 — PASS

## FUN_004E2A00 — FAIL
Source: docs/18-physics-dynamics.md

**Errors:**
- [WRONG_MODDABILITY] Entry says `configurable` but no config string literal in .c; scaling factor is a function parameter, not config-driven

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
### FUN_004e2a00 — Vehicle Parameter Scaling Loop

Source: unknown | Confidence: high. Iterates vehicles, multiplies fields at +0xf4/+0xf8 by param_2. Loops if param_3 set.

**Key logic:**
- Iterates vehicle array, multiplies fields at +0xf4 and +0xf8 by param_2
- Repeats if param_3 is set

**Used by system:** docs/18-physics-dynamics.md — vehicle physics parameter scaling

**Moddability:** `hardcoded`

## FUN_004CBC50 — PASS

## FUN_0044C0E0 — PASS

## FUN_00488F40 — PASS

## FUN_0048E250 — PASS

## FUN_004CCB30 — PASS

## FUN_0047B850 — PASS

## FUN_0055C860 — PASS

## FUN_0049B370 — PASS

## FUN_00504508 — PASS

## FUN_00475A90 — PASS

## FUN_004CA2D0 — FAIL
Source: docs/19-renderer.md

**Errors:**
- [WRONG_MODDABILITY] Entry says `configurable` but no config string literal in .c; particle emission parameters are hardcoded

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
### FUN_004ca2d0 — Particle/Effect Emission

Source: likely particles.cpp. Emits particles triggered by spatial proximity.

**Key logic:**
- Computes squared distance from emitter (param_1+4,8,0xc) to target (param_3)
- Compares against threshold (param_4 + +0x10 radius)
- Accumulates time at +0x14
- Uses fsin/fcos for rotation angle from time * frequency (+0x20)
- Iterates children at +0x38, stride 0x14, setting position/scale
- Notifies vehicle system via FUN_0054c230 flag clear

**Globals:** _DAT_008afee4, _DAT_005ace98

**Moddability:** `hardcoded`

## FUN_0051E2BA — PASS

## FUN_0054D9F0 — PASS

## FUN_004CC500 — PASS

## FUN_00563E00 — PASS

## FUN_0050B813 — PASS

## FUN_00501722 — PASS

## FUN_0050427D — PASS

## FUN_0048FDB0 — PASS

## FUN_0040D090 — PASS

## FUN_004B2840 — PASS

## FUN_0055BBF0 — PASS

## FUN_00599ED6 — PASS

## FUN_0058B465 — PASS

## FUN_0058FCB0 — PASS

## FUN_00564C70 — PASS

## FUN_0055CF50 — PASS

## FUN_005665B0 — PASS

## FUN_005990AE — PASS

## FUN_00565400 — PASS

## FUN_004366E0 — PASS

## FUN_00407BE0 — PASS

## FUN_004C3890 — PASS

## FUN_00560FC0 — PASS

## FUN_00407C90 — PASS

## FUN_0046D360 — PASS

## FUN_00488900 — PASS

## FUN_004A2A40 — PASS

## FUN_004D82A0 — PASS

## FUN_00516C0C — PASS

## FUN_00561A15 — PASS

## FUN_0057B9F0 — PASS

## FUN_00414900 — FAIL
Source: docs/20-math-utilities.md

**Errors:**
- [WRONG_GLOBAL] Entry lists `DAT_00566650` as a global but source uses `FUN_00566650` (a called function, not a global)

**Corrected entry:**
<!-- target: docs/20-math-utilities.md -->
### FUN_00414900 — Short Computation (String Path Append with File Check)

Source: unknown | Confidence: medium. Appends extension/suffix to string, checks if resulting path exists.

**Key logic:**
- If param_1 non-null: copies up to 250 chars via _strncpy
- Finds end of string via null-terminator scan
- Appends DAT_005be868 (4 bytes) and DAT_005be86c (1 byte) — suffix/extension
- Calls FUN_0058ba36(path, 0x180) — toggle file read-only attribute via Win32 API
- If file exists (!= -1): registers path via FUN_00566650, initializes param_2 fields to -1/0, returns 0
- Returns 1 if param_1 null or file not found

**Globals:**
- `DAT_005be868` — 4-byte string suffix (not in docs/12)
- `DAT_005be86c` — 1-byte character (not in docs/12)

**Calls:**
- FUN_0058ba36 — toggle file read-only attribute via Win32 API
- FUN_00566650 — path registry / string set (docs/09)

**Moddability:** hardcoded

## FUN_00474C50 — PASS

## FUN_00498F60 — PASS

## FUN_004C03C0 — PASS

## FUN_0050B228 — PASS

## FUN_00546200 — PASS

## FUN_0059C5EE — PASS

## FUN_0045CF30 — PASS

## FUN_004B47A0 — PASS

## FUN_00548E00 — PASS

## FUN_00587250 — PASS

## FUN_00423DB0 — PASS

## FUN_00479820 — PASS

## FUN_00498F80 — PASS

## FUN_004BD970 — PASS

## FUN_004FB8E0 — PASS

## FUN_005473C0 — PASS

## FUN_00551F10 — PASS

## FUN_00486080 — PASS
Note: Script false positive for FUN_004fb2e0 (section boundary artifact, not part of entry)

## FUN_00461480 — PASS

## FUN_00498650 — PASS

## FUN_004BB950 — PASS

## FUN_004F91B0 — PASS

## FUN_005317C0 — PASS

## FUN_00583680 — PASS

## FUN_00404820 — PASS

## FUN_00462310 — PASS

## FUN_00487830 — PASS

## FUN_004A0D30 — PASS

## FUN_004D5960 — PASS

## FUN_0052D970 — PASS

## FUN_0059CD40 — PASS

## FUN_004054E0 — PASS

## FUN_0045BF50 — PASS

## FUN_00485630 — PASS

## FUN_0049AA70 — PASS

## FUN_004C8210 — PASS

## FUN_0050A8D9 — PASS

## FUN_0053D880 — PASS

## FUN_00594BCD — PASS

## FUN_00410AD0 — PASS

## FUN_004C9D50 — PASS

## FUN_00586CA0 — PASS

## FUN_00415700 — PASS

## FUN_00473BD0 — PASS

## FUN_00495080 — PASS

## FUN_004B9880 — PASS

## FUN_004E9537 — PASS

## FUN_0051EC00 — PASS

## FUN_00566DB0 — PASS

## FUN_0059083B — PASS

## FUN_0059985C — PASS

## FUN_0051EC40 — PASS

## FUN_004FC870 — PASS

## FUN_004BA780 — PASS

## FUN_00499910 — PASS

## FUN_0047A190 — PASS

## FUN_0050D0BC — PASS

## FUN_004D8FB0 — PASS

## FUN_005124D5 — PASS

## FUN_0054EB20 — PASS

## FUN_00401080 — PASS

## FUN_0059C4E6 — PASS

## FUN_0041E840 — PASS

## FUN_00475530 — PASS

## FUN_00496280 — PASS

## FUN_004BA7A0 — PASS

## FUN_004F6AF0 — PASS

## FUN_00527F21 — PASS

## FUN_0057AE40 — PASS

## FUN_00591CA1 — PASS

## FUN_00421AF0 — PASS

## FUN_00478E80 — PASS

## FUN_00498D20 — PASS

## FUN_004BC320 — PASS

## FUN_004F9B70 — PASS

## FUN_005351D0 — PASS

## FUN_00585440 — PASS

## FUN_0058E04B — PASS

## FUN_00456080 — PASS

## FUN_0047A3A0 — PASS

## FUN_00499A50 — PASS

## FUN_004C2FE0 — PASS

## FUN_00502EE5 — PASS

## FUN_0053D1D0 — PASS

## FUN_0058FB7E — PASS

## FUN_0040ACD0 — PASS

## FUN_00479A40 — PASS

## FUN_00499360 — PASS

## FUN_004BEA10 — FAIL
Source: docs/20-math-utilities.md

**Errors:**
- [WRONG_MODDABILITY] Entry says `configurable` but no config string literal in .c; randomized value computation uses hardcoded constants

**Corrected entry:**
<!-- target: docs/20-math-utilities.md -->
### FUN_004bea10 — Randomized Value Computation

Source: unknown | Confidence: medium. rand()-based noise: variation = (rand2%50)*0.02+0.7, clamped, multiplied by factors.

**Key logic:**
- Generates random variation using _rand()
- Variation = (rand % 50) * 0.02 + 0.7
- Clamps result
- Multiplies by factor constants

**Globals:** DAT_0059e444, DAT_0059e450, DAT_0059e43c, DAT_005acdb4, DAT_0059e7f8

**Calls:** _rand, FUN_005881f0

**Moddability:** `hardcoded`

## FUN_005006D5 — PASS

## FUN_0053B1D0 — PASS

## FUN_00595621 — PASS

## FUN_0040E1C0 — PASS

## FUN_004B1AB0 — PASS

## FUN_00529000 — PASS

## FUN_0059DA3A — PASS

## FUN_0049A490 — PASS

## FUN_0059DAB7 — PASS

## FUN_004234A0 — PASS

## FUN_0047A5E0 — PASS

## FUN_00499B10 — PASS

## FUN_004C3050 — PASS

## FUN_00503772 — PASS

## FUN_0053C590 — PASS

## FUN_0058B9FF — PASS

## FUN_00406020 — PASS

## FUN_00462FF0 — PASS

## FUN_004883A0 — PASS

## FUN_004A1A00 — PASS

## FUN_004D0B00 — PASS

## FUN_0050D728 — PASS

## FUN_00547280 — PASS

## FUN_0059DB88 — PASS

## FUN_00464BB0 — PASS

## FUN_0048FC10 — PASS

## FUN_004B41C0 — PASS

## FUN_0059CFCC — PASS

## FUN_0059D020 — PASS

## FUN_0059D0EB — PASS

## FUN_0059CB80 — PASS

## FUN_0059C770 — PASS

## FUN_00583F50 — PASS

## FUN_00581FD0 — PASS

## FUN_00532AA0 — PASS

## FUN_004072E0 — PASS

## FUN_00406E50 — PASS

## FUN_0057EDD0 — PASS

## FUN_00598642 — PASS

## FUN_0057A3F0 — PASS

## FUN_00564580 — PASS
