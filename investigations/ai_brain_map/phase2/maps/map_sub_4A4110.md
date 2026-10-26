# map_sub_4A4110 — `sub_4A4110`

## Identity

- Address: `0x4A4110`; file `functions/sub_4A4110_004a4110.c`; 274 lines.
- Signature: `char __thiscall sub_4A4110(float *this, int a2)`.
- `this` = global AI vehicle table `dword_7CE2F0` (typed caller `functions_typed_20260930/AIMainUpdate_00424e70.c`
  L286: `sub_4A4110((float *)dword_7CE2F0, (int)this)`); `a2` = the waiting vehicle. `dword_5C329C` is the table
  entry count (L46).
- Callers (grep `functions/` for `sub_4A4110(`): `AIMainUpdate` (`0x424E70`) L291, in the driverStatus 4/5
  (pit/garage wait) release check.
- Callees (from `offsets_sub_4A4110.csv` CALL rows): `LODWORD` L50, L60, L61, L85; `AIDelegateCall` L55;
  `SpeedDeltaComputation` L56; `StateFlagsLookup` L119, L208, L217; `RandLCGRandomNumberGenerator` L266;
  `CRTFtol` L267.
- Prior art (not re-derived here): `investigations/pitbox_standing_start/README.md` section 2.5 calls this the
  "lane-clear check" / game's green light for an AI pit exit.

## Inputs

| hex | dec | type | first line read | name |
|---|---|---|---|---|
| 0x4550 | 17744 | _DWORD | L53 (`*(v7 + 17744)`) | laneMode registry flag (0 clears the table slot) |
| 0x4588 | 17800 | _DWORD | L75 (`*(a2 + 17800)`) | ? release gate counter A |
| 0x45E0 | 17888 | _DWORD | L76 (`*(a2 + 17888)`) | ? release gate counter B |
| 0x403C | 16444 | int | L118 (`*(int *)(a2 + 16444)`) | ? position/team index (cast to float in v40/v41) |
| 0x48A4 | 18596 | _DWORD | L122 (`*(*(_DWORD *)a2 + 18596)`) | team index (via the `*(a2)` subobject; doc 54 mode 3) |
| 0x1A0 | 416 | float | L154 (`this[104]`) | ? last-release timestamp on the manager object |
| 0x409C | 16540 | float | L163 (`*(float *)(a2 + 16540)`) | ? distance-to-target scale |

`16 * (v13 + 1112)` (L163) selects a record on `a2` (unmatched by the extractor).

## Outputs

| hex | dec | type | first line written | name |
|---|---|---|---|---|
| 0x1A0 | 416 | float | L263 (`this[104] = v30 + 18.0`) | next allowed release timestamp (now + 18.0) |

Dynamic write: `this[i] = 0.0` (L68) clears table slots whose `+0x4550` is zero (offset `4*i`, not a single CSV
row). No integer bit-pattern is written into a float field (`this[i] = 0.0` is float).

## Constants

Grouped by value; every numeric literal except 0/1 in `functions/sub_4A4110_004a4110.c`.

| value | lines | note |
|---|---|---|
| 17800, 17888, 16444, 18596, 16540, 104, 1112 | L75, L76, L118, L122, L163, L154 | offsets/indices |
| 2.0 | L61 | speed gate on `v10 + 17472` |
| -55.0 | L57 | lower bound for `SpeedDeltaComputation` |
| 4, 5 | L61, L123, L231 | driverStatus values rejected/compared |
| 7 | L73, L267 | session type `dword_7C56A4` |
| 3, 4, 5 | L92 | session types using the 1/11 scale |
| 0.090909094 | L93 | per-car release factor (1/11) |
| 0.071428575 | L95 | per-car release factor (1/14) |
| 1.0 | L47, L64, L96, L105, L113, L181, L199, L205, L211 | default pass factor / window floors |
| 0.0099999998 | L97, L98, L147 | factor floor |
| 3600.0 | L100 | first time window (s) |
| 1300.0 | L240 | third time window (s) |
| 7200.0 | L166 | second time window (s) |
| 18.0 | L237, L263 | cooldown base (s) |
| 0.25 | L116, L132, L255 | early threshold / v35 numerator |
| 0.34999999 | L119 | team-index gate scale |
| 0.5 | L150, L208 | phase thresholds |
| 0.69999999 | L128, L217 | phase gate |
| 0.75 | L152 | phase threshold |
| 0.80000001 | L136, L138, L219, L221 | caps |
| 0.40000001 | L141, L224, L234 | caps |
| 0.85000002 | L126 | late-race cap |
| 0.66000003 | L232 | late-race cap |
| 0.2 | L226 | cap |
| 0.1 | L143 | cap |
| 0.001 | L239 | zero guard for v31 |
| 360.0 | L164, L165 | minimum distance |
| 16 | L163 | record selector scale |
| 0.0 | L57, L68, L238 | guards / table clears |

No non-trivial integer-to-float bit pattern: L68 stores float 0.0.

## Logic

NOTE: one block per top-level branch; hex offsets only where the cited source line carries the decimal value.

```
v2 = dword_5C329C; v3 = 1.0                                        [L46,L47]
for (i = 0; i < v2; ++i) {                                         [L48]
  v7 = LODWORD(this[i])                                            [L50]
  if (v7) {
    if (*(v7 + 0x4550)) {                                          [L53]
      v8 = AIDelegateCall(v7)                                      [L55]
      v9 = SpeedDeltaComputation((_DWORD *)a2, v8)                 [L56]
      if (v9 < 0.0 && v9 > -55.0) {                                [L57]
        v10 = this[i]; v11 = *(v10 + 0x4510)                       [L59,L60]
        if (v11 != 4 && v11 != 5 && *(float *)(v10 + 0x4440) > 2.0) return 0   [L61,L62]
      }
      v3 = 1.0                                                     [L64]
    } else {
      this[i] = 0.0                                                [L68]
    }
    v2 = dword_5C329C                                              [L70]
  }
}
if (dword_7C56A4 == 7) return 1                                    [L73,L74]
v13 = *(a2 + 0x4588)                                               [L75]
if (v13 <= *(a2 + 0x45E0)) return 0                                [L76,L77]
v14 = v2; v15 = 0; v44 = v2                                        [L78,L79,L80]
if (v2 > 0) {
  do { if (LODWORD(this[v15])) --v14; ++v15 } while (v15 < v2)     [L81,L83,L85,L86,L87,L89]
  v44 = v14                                                        [L90]
}
if (dword_7C56A4 == 3 || dword_7C56A4 == 4 || dword_7C56A4 == 5)
    v16 = v44 * 0.090909094 else v16 = v44 * 0.071428575           [L92,L93,L94,L95]
v37 = 1.0 - v16; if (v37 < 0.0099999998) v37 = 0.0099999998        [L96,L97,L98]
v38 = dbl_8AFEA0                                                   [L99]
v17 = flt_8ACF90 + 3600.0; v18 = min(v17, flt_8ACF94)              [L100,L101,L102,L103,L104]
v19 = (v18 - flt_8ACF90 >= 1.0) ? min(v17, flt_8ACF94) - flt_8ACF90 : 1.0     [L105,L106,L107,L108,L109,L110,L113,L114]
v20 = (v38 - flt_8ACF90) / v19                                     [L115]
if (v20 < 0.25) {                                                  [L116]
  v40 = (float)*(int *)(a2 + 0x403C)                               [L118]
  if (StateFlagsLookup((_DWORD *)a2) * 0.34999999 > v40) {         [L119]
    v21 = *(_DWORD *)(*(_DWORD *)a2 + 0x48A4)                      [L122]
    if (v21 >= 4) { if (v21 >= 8) v3 = 0.85000002 else v3 = 0.69999999 }
    else v3 = 0.25                                                 [L123,L124,L125,L126,L127,L128,L129,L130,L131,L132,L133]
    goto LABEL_88                                                  [L134]
  }
  if (v37 > 0.80000001) { v3 = 0.80000001; goto LABEL_88 }         [L136,L137,L138,L139,L140]
  if (v37 > 0.40000001) { v3 = 0.1; goto LABEL_88 }                [L141,L142,L143,L144,L145]
  v3 = 0.0099999998; goto LABEL_88                                 [L147,L148]
}
if (v20 >= 0.5) {                                                  [L150]
  if (v20 >= 0.75) {
    if (this[104] < (double)v38) { v30 = v38; goto LABEL_86 }      [L152,L153,L154,L155,L156,L157,L158]
  } else {
    v22 = *(_DWORD *)(a2 + 0x403C)                                 [L162]
    v23 = (double)(*(_DWORD *)(16 * (v13 + 1112) + a2) - v22) * *(float *)(a2 + 0x409C)   [L163]
    if (v23 < 360.0) v23 = 360.0                                   [L164,L165]
    v45 = flt_8ACF90 + 7200.0                                      [L166]
    v24 = min(flt_8ACF94, v45); v25 = (v24 - v38 >= 1.0) ? min(flt_8ACF94, v45) - v38 : 1.0   [L167,L182]
    v42 = (v23 <= v25) ? v23 / ((v27 - v38 >= 1.0) ? min(flt_8ACF94, v45) - v38 : 1.0) : 1.0   [L183,L206]
    v39 = (float)v22; v3 = (StateFlagsLookup(a2) * 0.5 <= v39) ? v42 : 1.0     [L207,L212]
  }
} else {
  v41 = (float)*(int *)(a2 + 0x403C)                               [L216]
  if (StateFlagsLookup(a2) * 0.69999999 <= v41) {
    if (v37 > 0.80000001) { v3 = 0.80000001; goto LABEL_88 }       [L219,L222]
    if (v37 > 0.40000001) { v3 = 0.2; goto LABEL_88 }              [L224,L228]
    goto LABEL_48  // v3 = 0.0099999998                            [L229,L147]
  }
  v3 = (*(int *)(*(_DWORD *)a2 + 0x48A4) >= 4) ? 0.66000003 : 0.40000001   [L231,L234]
}
LABEL_88:
v31 = v3 * v37 * 18.0; if (v31 == 0.0) v31 = 0.001                 [L237,L238,L239]
v32 = flt_8ACF90 + 1300.0; v33 = min(v32, flt_8ACF94)              [L240,L244]
v34 = (v33 - flt_8ACF90 >= 1.0) ? min(v32, flt_8ACF94) - flt_8ACF90 : 1.0     [L245,L254]
v35 = 0.25 / v31 * v34                                             [L255]
if (v35 < 1.0) {
  v30 = dbl_8AFEA0; if (dbl_8AFEA0 <= this[104]) return 0          [L257,L260]
  LABEL_86: this[104] = v30 + 18.0; return 1                       [L262,L264]
}
v36 = RandLCGRandomNumberGenerator(v14)                            [L266]
if (dword_7C56A4 == 7 || (v43 = v35, !(v36 % CRTFtol(v43)))) {     [L267]
  v30 = dbl_8AFEA0; if (dbl_8AFEA0 >= this[104]) goto LABEL_86     [L269,L271]
}
return 0                                                           [L273]
```

## Meaning (GUESS)

- GUESS This is the pit-box "go" check: `AIMainUpdate` calls it only in driverStatus 4/5 and, when it returns 1
  and ActiveFlag 0x45F4 is set, leaves the box (mode 5 -> 3 approach, else -> 0 follow); on 0 the retry timer is
  pushed 4 s [callers; prior art pitbox README section 2.5].
- GUESS Registry loop: entries whose `+0x4550` (laneMode) is 0 are cleared from the table; for in-lane cars it
  resolves the AI delegate and `SpeedDeltaComputation` against the waiting vehicle, and any car decelerating
  toward it (delta in (-55,0)) with driverStatus not 4/5 and speed > 2 m/s blocks the release (return 0)
  [L50-L68].
- GUESS In a race (`dword_7C56A4 == 7`) the lane check is skipped entirely (return 1) [L73,L74].
- GUESS Release pressure grows with race progress: `v20` = elapsed / window from `flt_8ACF90` (window min(limit,
  start+3600) or 1), and the phase factor `v3` steps from 0.25/0.01 up to 0.85/0.8/0.7 [L100-L148].
- GUESS `v37 = 1 - N_active * (1/11 or 1/14)` thins the per-car release rate as more cars wait
  [L92-L98].
- GUESS Later phases use per-car distance/identity gates (`a2+0x403C`, `*(a2)+0x48A4`, the
  `16*(v13+1112)+a2` record, `a2+0x409C`) to build `v42`, gated by `StateFlagsLookup(a2)` fractions
  [L150-L234].
- GUESS `v31 = v3*v37*18` is a cooldown; if `v35 = 0.25/v31 * window < 1` release immediately when
  `now > this[104]` and stamp `this[104] = now + 18`, otherwise release probabilistically
  (`RandLCG % CRTFtol(v35)`) [L237-L271].
- GUESS `this[104]` (manager+0x1A0) is the last-release timestamp; the same manager object holds the vehicle
  pointer table consumed at L50/L85 [L154,L263].

## Questions

- `this` is `dword_7CE2F0`, a pointer table of up to `dword_5C329C` vehicles, yet `this[104]` (0x1A0) is a float
  timestamp. Is the pointer table followed by scalar manager state, or is the typed call still mixing bases?
- Semantics of `a2+17800` vs `a2+17888`, `a2+16444` and the `16*(v13+1112)+a2` record (position? team table?).
- What does `StateFlagsLookup(a2)` return (state flags? count?) and what are its units?
- `!(v36 % CRTFtol(v43))` is a suspicious decompile (`CRTFtol` = float-to-long). Is the real code an integer
  modulo of the random value by a converted threshold?
- Why are `v3` values set at L47/L64 but only consumed after LABEL_88?
- `dword_7C56A4` values 3/4/5/7 (session types) still need a canonical mapping.
