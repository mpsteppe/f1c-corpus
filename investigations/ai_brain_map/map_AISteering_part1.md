# map_AISteering_part1 — `AISteering` declared `sub_4270A0`, source L188-L303 (setup + corridor seeding)

Part 1 of 5. Split follows the top-level phases: setup/seeding (part1), opponent ranking (part2),
per-opponent decision loop (parts 3-4), overtake execution + epilogue (part5). Function: address `0x4270A0`;
file `functions/AISteering_004270a0.c`; 1314 lines. Caller: `AIMainUpdate` L247. Callees (whole function, from
`offsets_AISteering.csv` CALL rows): `SpatialTreeNearestNeighborSearch`, `BVHNearestNeighborQuery`,
`ShortComputation_3ca0`, `ShortComputation_3db0`, `VehicleDynamics`, `SignedIndexTableLookup`,
`TrackParameterMinimumClamp`, `Overtaking`, `fabs` (+ decompiler `LODWORD` artifacts).

## Identity

- `this` = F1CVehicle (char* base). Doc 54/live names used where established: 0x4408 = racing-line lateral position
  (published steering target); 0x440C = working candidate; 0x4414/0x4418 = corridor bounds (prior art
  `ai-pulloff-lateral-chain-v4-2026-10-02`); 0x4420 = target lateral request (prior art); 0x44F8 =
  TrackAggressionEffective (CONFIRMED); 0x4440 = Speed; 0x4428 = lateral position (doc 54); 0x4468 = look-ahead
  index (doc 54). Other names are `?`.

## Inputs

| hex | dec | type | first line read | name |
|---|---|---|---|---|
| 0x4354 | 17236 | _DWORD | L188 | CurrentWaypointPtr (typed, doc 54) |
| 0x456C | 17772 | char | L194 | ? avoidance/line-follow latch |
| 0x4579 | 17785 | char | L246 | ? corridor rate-limit latch |
| 0x4414 | 17428 | float | L208 | corridor bound 1 (prior art) |
| 0x4418 | 17432 | float | L209 | corridor bound 2 (prior art) |
| 0x441C | 17436 | float | L212 | ? corridor centre offset |
| 0x4420 | 17440 | float | L230 | target lateral request (prior art) |
| 0x4428 | 17448 | float | L277 | lateral position (doc 54) |
| 0x44FC | 17660 | _DWORD | L273 | ? race-start override selector (-1/0/+1) |
| 0x4468 | 17512 | _DWORD | L262 | look-ahead index (doc 54) |

Waypoint fields read via locals: `v2`/`v6`/`v10` are waypoint pointers (`wp+80`, `wp+84` widths). `this[4*idx +
17236]` (L262) addresses the look-ahead pointer array (index 0 points at 17236 = 0x4354; the pointer block
continues 17240.. and is listed in `unmatched_AISteering.txt`).

## Outputs

| hex | dec | type | first line written | name |
|---|---|---|---|---|
| 0x440C | 17420 | float | L231 | working lateral target (published at 0x4408 in part5) |
| 0x4428 | 17448 | float | - | (read only in this part) |
| 0x456C | 17772 | char | L299 | ? latch cleared |
| 0x4579 | 17785 | char | L294 | ? latch cleared |
| 0x4570 | 17776 | _DWORD | L295 | ? counter cleared |
| 0x4574 | 17780 | _DWORD | L296 | ? counter cleared |
| 0x455C | 17756 | _DWORD | L297 | ? counter cleared |
| 0x4554 | 17748 | _DWORD | L298 | ? set to 1 |

## Constants

Grouped by value; every numeric literal except 0/1 in L188-L303.

| value | lines | note |
|---|---|---|
| 2.0 | L234, L235 | corridor recentre half-width when bounds inverted |
| 0.2 | L248, L250, L253, L257 | corridor rate limit per tick |
| 6.5 | L260 | race-start window (s) |
| 2.5 | L271 | race-start window (s) |
| 1.0 | L210, L222, L264, L266, L277, L283 | factors / offsets |
| 99999.898 | L286-L300 | ranking sentinels |
| 0.5 | L211 | mid-width factor |
| 4309 | L188 | CurrentWaypointPtr index (17236) |
| 4357, 4358, 4359, 4360, 4355 | L208-L257 | corridor/working fields |
| 4362 | L277-L283 | lateral position field |

## Logic

NOTE: source uses scaled `this[N]` / local indices; Logic keeps source-literal forms. No hex tokens used.

```
v2 = *((_DWORD *)this + 4309)                                  [L188]
v3 = *(float *)(v2 + 80); v150 = *(float *)(v2 + 84)           [L189,L190]
v141 = 0; v140 = 0; v138 = 0; v142 = this[17772]               [L191,L192,L193,L194]
v4 = this + 17240                                              [L195]
repeat 5 {                                                     [L196,L197]
    v6 = *(_DWORD *)v4                                         [L199]
    if (*(float *)(v6 + 84) <= v150) v150 = *(float *)(v6 + 84)  [L200,L201]
    if (v3 >= *(float *)(v6 + 80)) v3 = *(float *)(v6 + 80)      [L202,L203]
    v4 += 4                                                    [L204]
}                                                              [L205,L206,L207]
v145 = *((float *)this + 4357); v146 = *((float *)this + 4358) [L208,L209]
v168 = 1.0; v157 = (v150 + v3) * 0.5                           [L210,L211]
v7 = v3 + *((float *)this + 4359)                              [L212]
if (v7 < v157) { if (v7 < 0.0) v7 = 0.0; v168 = v7 / v157 }    [L213,L214,L215,L216,L217]
v8 = v150 - *((float *)this + 4359)                            [L219]
if (v8 >= v157) v158 = 1.0                                     [L220,L221,L222]
else { if (v8 < 0.0) v8 = 0.0; v158 = v8 / v157 }              [L224,L225,L226,L227,L228]
v9 = *((float *)this + 4360); *((float *)this + 4355) = v9     [L230,L231]
if (v145 < v146) { v145 = v9 + 2.0; v146 = v9 - 2.0 }          [L232,L233,L234,L235]
if (v9 <= v145) { if (v9 < v146) *((float *)this + 4355) = v146 }   [L237,L238,L239,L240]
else *((float *)this + 4355) = v145                            [L242,L243,L244]
if (this[17785]) {                                             [L246]
    if (this[4355] - this[4360] >= -0.2) {                     [L248]
        if (this[4360] - this[4355] >= -0.2) this[4355] = this[4360]  [L250,L251]
        else this[4355] = this[4355] - 0.2                     [L253]
    } else this[4355] = this[4355] + 0.2                       [L257]
}
if (dbl_8AFEA0 < flt_8ACF90 + 6.5) {                           [L260]
    v10 = this[4 * this[4378] + 17236]                         [L262]
    if (this[4359] >= 0.0) v11 = wp84 / (cur84 + 1.0)
    else v11 = wp80 / (cur80 + 1.0)                            [L263,L264,L265,L266]
    if (v11 > 1.0) v11 = 1.0                                   [L267,L268]
    this[4355] = v11 * this[4359]                              [L269]
}
if (dbl_8AFEA0 < flt_8ACF90 + 2.5) {                           [L271]
    v12 = this[4415]                                           [L273]
    if (v12) { if (v12 == 2) this[4355] = this[4362] + 1.0; else this[4355] = this[4362] }  [L276,L277,L279]
    else this[4355] = this[4362] - 1.0                         [L283]
}
v180=v181=v182=v183=v184=99999.898; v185=v186=v187=v188=v189=-1; v13=-1   [L286-L293]
this[17785]=0; this[4444]=0; this[4445]=0; this[4439]=0; this[4437]=1; this[17772]=0   [L294-L299]
```

## Meaning (GUESS)

- GUESS Seeds the corridor: takes the minimum half-width among the current waypoint and 5 look-ahead waypoints
  (wp+80/wp+84), centres it with 0x441C and derives left/right scale factors v168/v158 used later to shrink
  avoidance offsets near the track edge [L188-L229].
- GUESS Initial working lateral target 0x440C = clamped target 0x4420 inside the corridor bounds 0x4414/0x4418; if
  the bounds are inverted it recentres them +-2.0 around the target; rate-limits any movement to 0.2/tick while the
  0x4579 latch is set [L230-L259].
- GUESS Two race-start phases: before `flt_8ACF90 + 6.5` s the target is scaled by the look-ahead waypoint width
  ratio (v11); before `+2.5` s it is forced to lateral 0x4428 +-1.0 depending on 0x44FC (0 -> -1, 2 -> +1, else
  exact) [L260-L285].
- GUESS Then resets the per-tick state: ranking sentinels, latches, counters, and sets 0x4554 = 1 [L286-L299].

## Questions

- Names of 0x441C (corridor centre offset), 0x44FC (start selector), 0x4554 (set to 1 each tick), 0x456C/0x4579
  latches, and counters 0x4570/0x4574/0x455C are unknown; inspect prose conflicts (see main map header).
- `flt_8ACF90` race-start reference and `dbl_8AFEA0` session time are globals; what sets flt_8ACF90?
- Is 0x4420 target lateral or an offset to 0x440C? Prior art (`ai-pulloff-lateral-chain-v4`) calls it a request
  that must ramp with 0x440C; part5 shows 0x4408 published from 0x440C.
