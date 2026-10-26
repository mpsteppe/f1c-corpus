# map_PitStopDecisionTireCompound — `sub_42A3D0` (`PitStopDecisionTireCompound`)

## Identity

- Address: `0x42A3D0`; file `functions/PitStopDecisionTireCompound_0042a3d0.c`; 132 lines.
- Signature: `char __thiscall sub_42A3D0(_DWORD *this)`.
- Callers (grep `functions/` for `PitStopDecisionTireCompound(`): `AIAbility` (`0x429470`) L123;
  `PitStopReadyCheck` (`0x4A6200`) L24 (`*((_BYTE *)this + 400) = PitStopDecisionTireCompound(*this);`).
- Callees (from `offsets_PitStopDecisionTireCompound.csv` CALL rows): `ConditionalGate` L47, L56;
  `PitStopBlockingCondition` L63; `SceneRenderUpdate` L66; `sub_4BC060` L72; `ClampedIndexAssignment` L84;
  `SpeedValueSetterWithGlobalMirror` L87; `LODWORD` L87 (macro artifact); `PostPitCleanup` L88;
  `StateTransition` L92; `IndexDecrementWithBoundsWrap` L120; `UtilityFunction_5750` L122.
- Unmatched offset-like lines (extractor did not parse): L45 (`*this + 3352`, `*this + 3416`),
  L47/L56 (`this + 3` pointer argument), L111 (`this + 4480`).
- `v11 = *this` at L90; the `v11 + 3348/3352/3416` reads at L91 are offsets on the sub-object pointer
  stored at `this[0]`. `*(_DWORD *)(*this + 3284)` is also read at L91 but is not in the CSV.

## Inputs

| hex | dec | type | first line read | name |
|---|---|---|---|---|
| 0x45E0 | 17888 | _DWORD | L22, L49, L58, L83 | ? pit compound index (`this[4472]`; map_AIAbility L44) |
| 0x4588 | 17800 | _DWORD | L23 | ? (`this[4450]`) |
| 0x403C | 16444 | _DWORD | L33, L48, L57 | lapNumber (inspect) |
| 0x4590 | 17808 | _DWORD | L37 | ? per-compound lap estimate (`this[4*v2+4452]`, dynamic index) |
| 0x45A0 | 17824 | _DWORD | L42 | ? per-compound lap estimate (`this[4*v2+4456]`, dynamic index) |
| 0x39FA | 14842 | _BYTE | L54 | ? flag (map_AIAbility L37) |
| 0x45E8 | 17896 | float | L79 | ? (`this[4474]`) |
| 0x3988 | 14728 | float | L80, L81 | ? speed cap (`this[3682]`; map_AIAbility L46) |
| 0x458C | 17804 | _DWORD | L108 | ? (`this[4451]`) |
| 0x3378 | 13176 | _DWORD | L116, L117 | ? pit table cursor/value (`this[3294]`) |
| 0xD14 | 3348 | _BYTE | L91 | ? (`v11 + 3348`, `v11 = *this`) |
| 0xD18 | 3352 | _DWORD | L91 | ? (`v11 + 3352`) |
| 0xD58 | 3416 | _BYTE | L91 | ? (`v11 + 3416`) |

Globals read: `dword_7C56A4` (L29, L45, L54, L63, L68; SessionType, `== 7` race), `dword_7C56A8` (L31;
RacePhase, `!= 8`), `dword_8ACF8C` (L33; TotalRaceLaps), `dbl_8AFEA0` (L67; SessionTime),
`flt_8AFEE8` (L93, L95, L98; doc 12 `TrackGripBase`, thresholds here look like a 0..1 fraction).

## Outputs

| hex | dec | type | first line written | name |
|---|---|---|---|---|
| 0x4548 | 17736 | _BYTE | L25 | ? override-enable byte = 1 (map_AIAbility L64) |
| 0x4584 | 17796 | _BYTE | L26, L32, L50, L59 | ? pit flag (0/1) |
| 0x4534 | 17716 | float | L67 | ? time stamp = `dbl_8AFEA0 + 180.0` (map_AIAbility L58) |
| 0x4410 | 17424 | _BYTE | L70 | ? = 1 |
| 0x45F4 | 17908 | _BYTE | L71 | ActiveFlag = 0 (FIELD_GLOSSARY) |
| 0x4590 + 16*this[4472] | dynamic | _DWORD | L51 | ? per-compound slot = `this[4111]` (via `this[v6]`) |

The two remaining per-compound writes use a base that is NOT in
`offsets_PitStopDecisionTireCompound.csv` (dynamic index); they are recorded in
the derived-slots section below.

## Per-compound slots (derived; base not in offsets CSV)

| source index | combined dec | type | first line written | name |
|---|---|---|---|---|
| `this[4*v5+4455]` (base this[4455]) | 17820 | _DWORD | L52, L61 | ? per-compound slot = 8 |
| `this[4*v5+4453]` (base this[4453]) | 17812 | float | L83 | ? per-compound speed = `v10` (map_AIAbility L45) |

## Constants

Grouped by value; every numeric literal except 0/1 in
`functions/PitStopDecisionTireCompound_0042a3d0.c`.

| value | lines | note |
|---|---|---|
| 1 | L24, L25, L32, L70 | initial `v16`, byte writes |
| 1.5 | L33, L42 | lap-deficit margins added |
| 7 | L29, L45, L54, L63, L68, L130 | SessionType compare / loop bound |
| 8 | L31, L52, L61, L123 | RacePhase compare / per-compound state / `i > 7` |
| 3.0 | L75, L78 | minimum compound life |
| 180.0 | L67 | time offset on `dbl_8AFEA0` |
| 4 | L103 | fallback compound id |
| 5 | L97 | compound id |
| 6 | L99 | compound id |
| 0.0099999998 | L93 | `flt_8AFEE8` threshold |
| 0.33000001 | L95 | `flt_8AFEE8` threshold |
| 0.66000003 | L98 | `flt_8AFEE8` threshold |
| 2 | L120, L122 | argument to per-index helpers |
| 1113 | L49, L58 | `4 * (this[4472] + 1113)` distribution |
| 4472, 4450, 4451, 4452, 4453, 4455, 4456, 4474, 3682, 4429, 3294, 4480, 4111 | L22-L108 | `this[N]` indices |

## Logic

NOTE: source uses scaled `this[N]` indexing and direct byte-offset pointer arithmetic; Logic keeps source
forms and no hex tokens. Byte offsets are in the tables above.

```
v2 = this[4472]; v3 = this[4450]; v16 = 1                                  [L22,L23,L24]
byte this+17736 = 1; byte this+17796 = 0                                   [L25,L26]
if (v2 + 1 > v3) {                                                         [L27,L28]
  if (dword_7C56A4 == 7) {                                                 [L29,L30]
    if (dword_7C56A8 != 8) byte this+17796 = 1                             [L31,L32]
    v4 = (double)(dword_8ACF8C - this[4111]) + 1.5                         [L33]
  } else {                                                                 [L34,L35]
    v4 = (double)(int)this[4*v2+4452] - (double)(int)this[4111]            [L37]
  }                                                                        [L38,L39]
} else {                                                                   [L40,L41]
  v4 = (double)(this[4*v2+4456] - this[4111]) + 1.5                        [L42]
}                                                                          [L43]
v17 = v4                                                                   [L44]
if (*(_DWORD *)(*this + 3352) && !*(_BYTE *)(*this + 3416) && dword_7C56A4 == 7) {   [L45,L46]
  ConditionalGate(this + 3)                                                [L47]
  v5 = this[4111]; v6 = 4 * (this[4472] + 1113)                            [L48,L49]
  byte this+17796 = 0                                                      [L50]
  this[v6] = v5                                                            [L51]
  this[4*this[4472]+4455] = 8                                              [L52]
}                                                                          [L53]
if (byte this+14842 && dword_7C56A4 == 7) {                                [L54,L55]
  ConditionalGate(this + 3)                                                [L56]
  v7 = this[4111]; v8 = 4 * (this[4472] + 1113)                            [L57,L58]
  byte this+17796 = 0                                                      [L59]
  this[v8] = v7                                                            [L60]
  this[4*this[4472]+4455] = 8                                              [L61]
}                                                                          [L62]
if (PitStopBlockingCondition(this) || dword_7C56A4 != 7) {                 [L63,L64]
  v16 = 0; SceneRenderUpdate(0)                                            [L65,L66]
  float this+17716 = dbl_8AFEA0 + 180.0                                    [L67]
  if (dword_7C56A4 == 7) {                                                 [L68,L69]
    byte this+17424 = 1; byte this+17908 = 0; sub_4BC060(1)                [L70,L71,L72]
  }                                                                        [L73]
}                                                                          [L74]
v9 = (v17 >= 3.0) ? v17 : 3.0                                              [L75,L76,L77,L78]
v10 = v9 * this[4474]                                                      [L79]
if (this[3682] < v10) v10 = this[3682]                                     [L80,L81]
v19 = v10                                                                  [L82]
float this[4*this[4472]+4453] = v10                                        [L83]
ClampedIndexAssignment(v19)                                                [L84]
if (!v16) { SpeedValueSetterWithGlobalMirror(LODWORD(v19)); PostPitCleanup(this) }   [L85,L87,L88]
v11 = *this                                                                [L90]
if ((*(_DWORD *)(*this + 3284) && !*(_BYTE *)(v11 + 3348)) || (*(_DWORD *)(v11 + 3352) && !*(_BYTE *)(v11 + 3416))) {   [L91]
  StateTransition(1)                                                       [L92]
}                                                                          [L92]
if (flt_8AFEE8 >= 0.0099999998) {                                          [L93,L94]
  if (flt_8AFEE8 >= 0.33000001) {                                          [L95,L96]
    v18 = 5                                                                [L97]
    if (flt_8AFEE8 >= 0.66000003) v18 = 6                                  [L98,L99]
  } else {                                                                 [L100,L101]
    v18 = 4                                                                [L103]
  }                                                                        [L104,L105]
} else {                                                                   [L106]
  v18 = this[4451]                                                         [L108]
}                                                                          [L109]
v12 = 0; v20 = this + 4480                                                 [L110,L111]
do {                                                                       [L112]
  if (*v20 == v18) {                                                       [L114]
    v13 = this[3294]                                                       [L116]
    for (i = 0; v13 != v12; v13 = this[3294]) {                            [L117]
      if (v13 >= v12) IndexDecrementWithBoundsWrap(2)                      [L119,L120]
      else UtilityFunction_5750(2)                                         [L122]
      if (++i > 7) break                                                   [L123,L124]
    }                                                                      [L125]
  }                                                                        [L113,L126]
  ++v12; ++v20                                                             [L127,L128]
} while (v12 < 7)                                                          [L129,L130]
return v16                                                                 [L131]
```

## Meaning (GUESS)

- GUESS Selects the tire compound for the upcoming pit stop[file name]; `this[4472]` is the pit/compound
  index and `this[4450]` the number of compound entries [L22,L23,L27].
- GUESS Computes `v17` = estimated laps of compound life left: race case uses
  `TotalRaceLaps - lapNumber + 1.5`, timed/special case subtracts the per-compound lap estimate, and the
  in-range case uses the next compound's estimate + 1.5 [L29-L42].
- GUESS Two conditions force the next compound state to 8 and copy `this[4111]` (lapNumber) into the
  per-compound slot: the `*this + 3352 && !(*this + 3416) && SessionType == 7` gate, and the
  `this+14842 && SessionType == 7` flag [L45-L61].
- GUESS When `PitStopBlockingCondition(this)` is true (or not a race), it sets `v16 = 0`, advances the
  scene, stamps `dbl_8AFEA0 + 180.0`, set `0x4410 = 1`, clears ActiveFlag `0x45F4`, and calls
  `sub_4BC060(1)` (pit animation/render?) [L63-L72].
- GUESS `v9 = max(v17, 3.0)` enforces a minimum life, then `v10 = min(v9 * this[4474], this[3682])` caps
  the target speed and stores it in the per-compound speed slot [L75-L83].
- GUESS When `!v16`, pushes the speed through `SpeedValueSetterWithGlobalMirror` and calls
  `PostPitCleanup(this)` (post-pit state reset) [L85-L88].
- GUESS `flt_8AFEE8` is a 0..1 fraction (doc 12 name `TrackGripBase` conflicts with these pit thresholds);
  it picks compound ids 4/5/6 by 0.01/0.33/0.66 thresholds, otherwise keeps `this[4451]` [L93-L108].
- GUESS The final loop scans seven per-opponent/per-compound slots at `this + 4480`, and for the slot
  equal to `v18` advances or decrements the pit table value `this[3294]` (helpers take `2`), up to 8
  iterations [L110-L130].
- GUESS The `char` return `v16` tells the caller (`PitStopReadyCheck` writes it to `*this + 400`, `AIAbility`
  L123 ignores it) whether the stop was blocked/advanced this tick [L131, callers].

## Questions

- `flt_8AFEE8`: doc 12 names it `TrackGripBase` (~0.5–1.0), but the 0.01/0.33/0.66 thresholds here select
  compound ids, which reads like a progress/fraction value. Which is right?
- What are compounds 4, 5, 6 and the `this[4451]` fallback? Is `this[4472]` the number of stops already
  made (tyre set index)?
- The loop at L112-L130 calls `IndexDecrementWithBoundsWrap(2)` / `UtilityFunction_5750(2)` only when
  `*v20 == v18`, with `v13 != v12` as loop condition and a `++i > 7` break; what data structure is
  `this + 4480` (seven slots) and what does the `2` select?
- `*(_DWORD *)(*this + 3284)` (L91) is read but not in the CSV; what is that sub-object field?
- `this + 3` is passed to `ConditionalGate` (L47/L56) — is that a sub-object base (byte offset 12)?
- `sub_4BC060`, `ConditionalGate`, `ClampedIndexAssignment`, `PitStopBlockingCondition`, `StateTransition`,
  `UtilityFunction_5750`, `IndexDecrementWithBoundsWrap`, `SceneRenderUpdate` are all unmapped here;
  semantics assumed from names.
- Why does the race branch use `(int)this[4*v2+4452]` (integer cast) while the in-range branch keeps floats
  at L42? Verify the two per-compound arrays' types.
