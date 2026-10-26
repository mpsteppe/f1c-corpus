# map_AIPushLap — declared `sub_42A180`

## Identity

- Address: `0x42A180`; file `functions/AIPushLap_0042a180.c`; 90 lines.
- Signature: `void __thiscall sub_42A180(float *this)`.
- Callers: `AIMainUpdate` (`0x424E70`) L191 (`AIPushLap(this);`) - manifest caller; grep `functions/` for
  `AIPushLap(` finds this occurrence only.
- Callees (from `offsets_AIPushLap.csv` CALL rows): `SLODWORD` (L40, pseudo), `LODWORD` (L40, pseudo),
  `ForcePitExit` (L41, L77, L87), `TireNameAccessor` (L42), `TireCompoundNameIDMapping` (L43).
- `this` = vehicle (`float *`). Scaled accesses use float indices; byte offsets are `index * 4`
  (column dec in the tables). `v2 = *this` is the vehicle pointer, used for `*(v2 + 16444)` at L40.

## Inputs

CSV access R rows, deduplicated.

| hex | dec | type | first line read | name |
|---|---|---|---|---|
| 0x32C8 | 13000 | _DWORD | L15 | vehicle flag (`*(_DWORD *)this + 13000` == 1 gate; AISteering part2 L368) |
| 0x403C | 16444 | _DWORD | L19 | lapNumber (inspect; `this[4111]`; `map_AIAbility.md`) |
| 0x44F4 | 17652 | float | L23 | ? ability floor (`this[4413]`; `map_AIAbility.md`) |
| 0x44D8 | 17624 | float | L23 | RaceAbility upper term (`this[4406]`; prior art `map_AIAbility.md`) |
| 0x453C | 17724 | float | L24 | AI pace multiplier (`this[4431]`; prior art CONFIRMED) |
| 0x44C8 | 17608 | float | L33 | ? (`this[4402]`; neighbor of the RaceAbility terms) |
| 0x454C | 17740 | _DWORD | L36 | branch id latch (`this[4435]`; `FIELD_GLOSSARY.md` 0x454C) |
| 0x4590 | 17808 | float | L40 | tire/setup float array element (`this[4*this[4472] + 4452]`) |
| 0x45E0 | 17888 | _DWORD | L40 | pit compound index (`this[4472]`; `map_AIAbility.md` L124) |
| 0x458C | 17804 | _DWORD | L46 | ? tire compound choice (`this[4451]`) |
| 0x3924 | 14628 | float | L86 | ? tire wear value 1 (`this[3657]`) |
| 0x382C | 14380 | float | L86 | ? tire wear value 2 (`this[3595]`) |
| 0x3734 | 14132 | float | L86 | ? tire wear value 3 (`this[3533]`) |
| 0x363C | 13884 | float | L86 | ? tire wear value 4 (`this[3471]`) |

The vehicle read `*(_DWORD *)(LODWORD(v2) + 16444)` at L40 has no CSV row (see Questions).

## Outputs

CSV access W rows.

| hex | dec | type | first line written | name |
|---|---|---|---|---|
| 0x453C | 17724 | float | L31 | AI pace multiplier (`this[4431]`) |
| 0x4580 | 17792 | float | L37 | corner-speed scale (`this[4448]`; `map_AIComputePassScore.md`) |

## Constants

Every numeric literal except 0/1.

| value | lines | note |
|---|---|---|
| 7 | L17 | `dword_7C56A4` (SessionType) branch |
| 10 | L20, L22, L26, L28 | lap delta cap (`v10`/`v11`) |
| 0.003 | L24, L29 | per-lap pace step |
| 1.0, 0.5 | L33-L35 | `v5 = 1.0 - flt_8AFEE8 * this[4402]`, floor 0.5 |
| 0.0099999998 | L44 | `flt_8AFEE8` threshold (1/100) |
| 0.33000001 | L49 | threshold for the `0.0099999998..0.33000001` band |
| 4, 5, 6 | L51, L71, L63 | target tire compound candidates |
| 0.2 | L52, L54 | wet-compound boundary |
| 0.66000003 | L61 | threshold for the `>= 0.66` band |
| 0.89999998 | L66, L86 | very-worn boundary / tire-wear average check |
| 0.55000001 | L74 | compound-4 boundary |
| 0.60000002 | L82 | compound-6 boundary |
| 0.25 | L86 | average of the four tire values |
| 4111, 4413, 4406, 4431, 4402, 4435, 4448, 4452, 4451, 4472, 3657, 3595, 3533, 3471 | L19-L86 | `this` float indices (see tables) |

## Logic

Scaled `this[idx]` forms keep the source index (no hex token); direct `+ N` forms keep hex names (decimal
present in the cited lines).

```
v2 = *this; if (*(*(_DWORD *)this + 0x32C8) == 1) {                       [L14,L15]
  if (dword_7C56A4 != 7) {                                                [L17]
    v3 = this[4111]                                                       [L19]
    v10 = 10; if (v3 <= 10) v10 = v3                                      [L20,L21,L22]
    v4 = this[4413] + this[4406]                                          [L23]
    if (v4 >= (double)v10 * 0.003 + this[4431]) {                         [L24]
      v11 = 10; if (v3 <= 10) v11 = v3                                    [L26,L27,L28]
      v4 = (double)v11 * 0.003 + this[4431]                               [L29]
    }    [L30]
    this[4431] = v4                                                       [L31]
  }    [L32]
  v5 = 1.0 - flt_8AFEE8 * this[4402]                                      [L33]
  if (v5 < 0.5) v5 = 0.5                                                  [L34,L35]
  v6 = this[4435]                                                         [L36]
  this[4448] = v5                                                         [L37]
  if (v6 != 1) {                                                          [L38]
    if (SLODWORD(this[4 * this[4472] + 4452]) <= *(_DWORD *)(LODWORD(v2) + 16444))    [L40]
      ForcePitExit(this)                                                  [L40,L41]
    v7 = TireNameAccessor(this + 3)                                       [L42]
    v8 = TireCompoundNameIDMapping(v7)                                    [L43]
    if (flt_8AFEE8 < 0.0099999998) { v9 = this[4451]; goto LABEL_17 }     [L44,L45,L46]
    if (flt_8AFEE8 < 0.33000001) {                                        [L49]
      v9 = 4                                                              [L51]
      if (v8 == 5 && flt_8AFEE8 > 0.2) goto LABEL_20                      [L52,L53]
      if (v8 == this[4451] && flt_8AFEE8 < 0.2) v9 = this[4451]           [L54,L55]
LABEL_17:                                                                [L56]
      if (v8 == v9 || !v9) goto LABEL_20                                  [L57,L58]
      goto LABEL_19                                                       [L59]
    }    [L60]
    if (flt_8AFEE8 >= 0.66000003) {                                       [L61]
      v9 = 6                                                              [L63]
      if (v8 != 5) goto LABEL_17                                          [L64,L65]
      if (flt_8AFEE8 >= 0.89999998) goto LABEL_19                         [L66,L67]
    } else {    [L69]
      v9 = 5                                                              [L71]
      if (v8 == 4) {                                                      [L72]
        if (flt_8AFEE8 < 0.55000001) goto LABEL_20                        [L74,L75]
LABEL_19:                                                                [L76]
        ForcePitExit(this)                                                [L77]
        goto LABEL_20                                                     [L78]
      }    [L79]
      if (v8 != 6) goto LABEL_17                                          [L80,L81]
      if (flt_8AFEE8 <= 0.60000002) goto LABEL_19                         [L82,L83]
    }    [L84]
LABEL_20:                                                                [L85]
    if ((this[3657] + this[3595] + this[3533] + this[3471]) * 0.25 < 0.89999998)    [L86]
      ForcePitExit(this)                                                  [L86,L87]
  }    [L88]
}    [L89]
```

## Meaning (GUESS)

- GUESS Per-lap pit/tire strategy: only for SessionType 7 with vehicle flag 0x32C8 == 1 [L15-L17].
- GUESS In non-race sessions (L17 branch) it advances the pace multiplier 0x453C by at most 10 laps of
  `0.003` toward `ability floor + RaceAbility term` (`this[4413] + this[4406]`), i.e. lap-by-lap
  speed convergence to the driver's ability ceiling [L19-L31].
- GUESS It computes `v5 = 1 - flt_8AFEE8 * this[4402]`, floors it at 0.5, and stores it to the
  AIComputePassScore corner-speed scale 0x4580 [L33-L37].
- GUESS 0x458C (`this[4451]`) is the current tire compound; 0x45E0 (`this[4472]`) indexes a per-compound
  array at 0x4590 whose element is compared with the vehicle lapNumber to force a pit exit when the
  compound is due [L40-L41].
- GUESS A wear-driven compound chooser: `flt_8AFEE8` (a wear/fuel-like fraction) selects target compounds
  4/5/6 with boundaries 0.01/0.33/0.55/0.60/0.66/0.90 and wet-compound (5) special cases, calling
  `ForcePitExit` whenever the current compound differs from the target [L44-L87].
- GUESS Final guard: if the average of four tire values (`this[3657]/[3595]/[3533]/[3471]`, stride 0x348
  bytes between them) is below 0.9, force the pit exit [L86-L87].
- GUESS The `v6 != 1` guard means laneMode/branch latch 0x454C == 1 (already pitting) suppresses all
  strategy checks [L36-L38].

## Questions

- The vehicle lapNumber read `*(_DWORD *)(LODWORD(v2) + 16444)` at L40 has no CSV row (extractor hit the
  `LODWORD` cast); `unmatched_AIPushLap.txt` only lists L42. Confirm it is 0x403C on the vehicle pointed
  to by `*this`.
- What are the four floats `this[3657]`, `this[3595]`, `this[3533]`, `this[3471]` (stride 0x348 = 840
  bytes)? Tire wear per wheel is a GUESS.
- What is `flt_8AFEE8` - remaining fuel fraction, tire wear fraction, or race distance fraction? The
  thresholds 0.01/0.33/0.55/0.60/0.66/0.90 suggest a wear/life normal.
- What are compounds 4, 5, 6 in `TireCompoundNameIDMapping` terms, and is 5 the wet tire? The `v8 == 5`
  special cases at L52/L64 look like interchangeability rules.
- `TireNameAccessor(this + 3)` receives a shifted base (vehicle + 12 bytes); confirm the intended object.
- Is `this[4448]` (0x4580) purely an output scale, or is it also read elsewhere before this write
  (`map_AIComputePassScore.md` reads it per corner)?
