# map_AISteering_part4 — `AISteering` declared `sub_4270A0`, source L668-L1009 (4 m case + mode decision)

Part 4 of 5 (phase: handle an opponent within 4 m and select the per-opponent steering mode `v86`). Function:
address `0x4270A0`; file `functions/AISteering_004270a0.c`; 1314 lines. Caller: `AIMainUpdate` L247.

## Identity

- `this` = F1CVehicle; `v33` = proximity slot record; `v34` = opponent vehicle; `v35` = slot waypoint;
  `v93` = `v33[4189]` opponent vehicle pointer again; `v162` = slot team index `v33[4205]`.
- Names: 0x4480 = ? value compared by 0x42D8; 0x4468 = look-ahead index (doc 54); 0x4550 = waypoint set selector
  (typed); 0x454C = CallToBox (typed, AIRacingLine map); 0x4438 = brake candidate (doc 54); 0x4414/0x4418 =
  corridor bounds (prior art); 0x4579/0x456C/0x4570/0x4574/0x455C = latches/counters (part1-3); 0x42D4/0x42D8/
  0x42DC = per-opponent state.
- `v86` is the resulting steering mode for this opponent (1/2/3/4/5/7/8/16), passed to `Overtaking` in part5 or
  stored into the per-opponent mode 0x42D4.

## Inputs

| hex | dec | type | first line read | name |
|---|---|---|---|---|
| 0x4440 | 17472 | float | L689, L778 | Speed (CONFIRMED) |
| 0x4438 | 17464 | float | L689 | brake candidate (doc 54) |
| 0x4480 | 17536 | float | L805, L817 | ? per-opponent block reset value |
| 0x42D4 | 17108 | _DWORD | L802, L812, L927 | per-opponent mode |
| 0x4468 | 17512 | _DWORD | L775, L786 | look-ahead index (doc 54) |
| 0x4428 | 17448 | float | L819, L820, L938 | lateral position (doc 54) |
| 0x4414 | 17428 | float | L938 | corridor bound 1 (prior art) |
| 0x4418 | 17432 | float | L938 | corridor bound 2 (prior art) |
| 0x456C | 17772 | char | L910, L933 | ? avoidance latch |
| 0x4550 | 17744 | _DWORD | L922 | waypoint set selector (typed) |
| 0x454C | 17740 | _DWORD | L627 (part3) | CallToBox (typed) |
| 0x42DC | 17116 | float | L968 | per-opponent accumulator |

Opponent `v93` fields read: `+17476` (`v93[4369]`), `+17704` (`v93[4426]`), `+17708` (`v93[4427]`),
`+17776`/`+17780` (as ints, L871), `+17400` (`v93[4350]`), `+17404` (`v93[4351]`), `+13000`, `+17756`, `+17476`.

## Outputs

| hex | dec | type | first line written | name |
|---|---|---|---|---|
| 0x4418 | 17432 | float | L672 | corridor bound 2 |
| 0x4579 | 17785 | char | L671, L955, L1003, L1008 | ? latch set |
| 0x455C | 17756 | _DWORD | L670 | ? counter incremented |
| 0x4570 | 17776 | _DWORD | L676 | ? opponent id + 1 |
| 0x4574 | 17780 | _DWORD | L717 | ? opponent id + 1 |
| 0x42D4 | 17108 | _DWORD | L764 | per-opponent mode = 5 |
| 0x42D8 | 17112 | _DWORD | L803 | per-opponent block flag (-1.0 bits) |
| 0x456C | 17772 | char | L797 | ? avoidance latch set |

## Constants

Grouped by value; every numeric literal except 0/1 in L668-L1009.

| value | lines | note |
|---|---|---|
| 4.0 | L668, L762 | close-range gate |
| 2.0 | L677, L718, L947 | corridor +/-2 m; forced v154 = 2.0 |
| 1.0 | L681, L719, L796, L947 | +/-1 m; v163 = 1.0; v139 flag |
| 0.80000001 | L699, L740 | clamp scale |
| 0.1 | L689, L697, L730, L738, L929, L961 | brake gate |
| 0.5 | L696, L737, L875 | speed blend; surface factor |
| 1.25 | L755 | lateral gate for -5 m/s clamp |
| 5.0 | L757, L776, L787 | clamps |
| 1.2 | L767 | speed gate |
| 20.0 | L778, L789 | speed split |
| 0.050000001 | L779, L790 | speed scale |
| 15.0 | L799, L936, L957 | distance split |
| 3.0 | L802 | `fabs(v165) < 3.0` |
| -2.0 | L802 | `v33[4195] < -2.0` |
| 85.0 | L843, L869 | corridor penalty scale |
| 75.0 | L873, L874 | per-opponent counter scale |
| 300.0 | L878 | surface factor |
| 99999.0 | L897 | look-ahead distance sentinel |
| 95.0 | L919, L920 | teammate give-way |
| 400.0 | L924, L925, L940, L943 | pit/start offset |
| 550.0 | L839, L865 | default distance |
| 500.0 | L950, L968 | accumulator base |
| 0.300000011920929 | L979 | lateral decision threshold |
| 5.5 | L977 | distance branch |

## Logic

NOTE: source uses scaled `this[N]` / slot `v33[N]` forms; Logic keeps source-literal indices. `v69` is a
decompiler c0/c2 flag artifact from the preceding compare. No hex tokens used.

```
if (v33[4192] < 4.0 && v33[4192] >= 0.0) {                        [L668]
    ++this[4439]; this[17785] = 1; this[4418] = this[4418] + 1.0  [L670,L671,L672]
    if (v69) {  # "opponent on the left" branch
        if (!this[4444]) this[4444] = *(int *)(v34 + 17776) + 1   [L675,L676]
        v74 = v144 + 2.0; v172 = this[4362] - 1.0
        if (v74 <= v172) SignedIndexTableLookup(v172) else SignedIndexTableLookup(v74)   [L677-L687]
        v75 = this[28 * v33[4205] + 17096]
        v76 = (v75 <= -1 || this[4366] <= 0.1) ? this[4368]
             : (this[4 * v75 + 17316] + this[4368]) * 0.5        [L688-L692]
        v161 = -(v33[4192] / v33[4195])
        if (v74 / v76 < v161 && v161 > 0.0 && *(float *)(v34 + 17476) > 0.5 && this[4366] < 0.1)
            TrackParameterMinimumClamp(this[4368] * 0.8)          [L693-L701]
        v77 = (v144 + v167) * v158
        if (v77 > v146) { v146 = v77; v138 = 1 }
        if (v146 > v145) { v145 = v145 + 1.0; v146 = v145 }       [L702-L712]
    } else {
        if (!this[4445]) this[4445] = *(int *)(v34 + 17780) + 1   [L716,L717]
        v70 = v144 - 2.0; v171 = this[4362] + 1.0
        if (v70 >= v171) SignedIndexTableLookup(v171) else SignedIndexTableLookup(v70)   [L718-L728]
        v71 = this[28 * v33[4205] + 17096]
        v72 = (v71 <= -1 || this[4366] <= 0.1) ? this[4368]
             : (this[4 * v71 + 17316] + this[4368]) * 0.5        [L729-L733]
        v160 = -(v33[4192] / v33[4195])
        if (v70 / v72 < v160 && v160 > 0.0 && *(float *)(v34 + 17476) > 0.5 && this[4366] < 0.1)
            TrackParameterMinimumClamp(this[4368] * 0.8)          [L734-L742]
        v73 = (v144 - v167) * v168
        if (v73 < v145) { v145 = v73; v138 = 1 }
        if (v145 < v146) { v146 = v146 - 1.0; v145 = v146 }       [L743-L753]
    }
    if (fabs(v33[4190]) < 1.25) TrackParameterMinimumClamp(this[4368] - 5.0)   [L755-L759]
    continue                                                      [L760]
}
if (v33[4192] < 4.0 || v149 >= v177 || v149 < 0.0) {              [L762]
    this[28 * v33[4205] + 17108] = 5; continue                    [L764,L765]
}
if (v33[4201] < 1.0 && this[4368] > 1.2) {                        [L767]
    v168 = 1.0; v158 = 1.0                                        [L769,L770]
    if (!*(_BYTE *)(v34 + 17772)) {                               [L771]
        if (!v138) {
            v78 = min(*(float *)(this[4 * this[4378] + 17236] + 56) - v145, 5.0)
            v79 = (this[4368] <= 20.0) ? v78 * (1.0 - this[4368] * 0.050000001) : 0.0
            v145 = v145 + v79                                     [L773-L783]
        }
        if (!v140) {
            v80 = min(-*(float *)(this[4 * this[4378] + 17236] + 52) - v146, 5.0)
            v81 = (this[4368] <= 20.0) ? v80 * (1.0 - this[4368] * 0.050000001) : 0.0
            v146 = v146 + v81                                     [L784-L794]
        }
        v139 = 1                                                  [L795]
    }
    this[17772] = 1                                               [L797]
}
if (v33[4192] > 15.0) v165 = v33[4196] - this[4362]              [L799]
v82 = v33[4205]
if (this[28 * v82 + 17108] == 5 && fabs(v165) < 3.0 && v33[4195] < -2.0)
    this[28 * v82 + 17112] = -1.0                                 [L800-L803]
# decide mode v86 (reuse stored mode if unblocked)
if (!this[17544] || (v83 = &this[28 * v33[4205] + 17112], *v83 >= this[4384])) {   [L804,L805]
    v85 = this[28 * v33[4205] + 17112]
    if (v85 >= 0.0) { v86 = this[28 * v33[4205] + 17108]; goto LABEL_368 }   [L807-L813]
}
v86 = 0; *v83 = this[4384] + 1.0                                   [L816,L817]
v87 = min(v144 - v170, this[4362]); v152 = v87                     [L818,L819,L820,L821]
v88 = (v144 >= 0.0) ? *(float *)(v35 + 84) + 1.5 : -(*(float *)(v35 + 80) + 1.5)
if (v88 >= v144) { SignedIndexTableLookup(v152); v174 = v88 } else v174 = 550.0   [L822-L839]
v89 = v152 + v170; if (v89 < this[4362]) v174 -= (this[4362] - v89) * 85.0   [L841-L843]
v90 = max(v144 + v170, this[4362]); v153 = v90                     [L844-L847]
v91 = (v144 >= 0.0) ? *(float *)(v35 + 84) + 1.5 : -(*(float *)(v35 + 80) + 1.5)
if (v91 >= v144) { SignedIndexTableLookup(v153); v147 = v91 } else v147 = 550.0   [L848-L865]
v92 = v153 - v170; if (v92 > this[4362]) v147 -= (v92 - this[4362]) * 85.0   [L867-L869]
v93 = (float *)*((_DWORD *)v33 + 4189)                             [L870]
v173 = *((_DWORD *)v93 + 4445); v178 = *((_DWORD *)v93 + 4444)     [L871,L872]
v94 = v174 - v173 * 75.0; v148 = v147 - v178 * 75.0                [L873,L874]
if (v93[4369] <= 0.5) { v96 = (1.0 - v93[4369]) * 300.0; v94 += v96; v148 += v96 }   [L875-L883]
else { if (v93[4426] < 0.0) v94 -= v33[4201] * 5.0;
       if (v93[4427] < 0.0) v148 -= v33[4201] * 5.0 }              [L885-L889]
if (this[4444] && v165 > -2.0) v94 = 0.0                           [L891,L892]
if (this[4445] && v165 < 2.0) v148 = 0.0                           [L893,L894]
if (v139) v165 = v33[4190]                                         [L895,L896]
v99 = 99999.0; v162 = v33[4205]; v100 = 0; v101 = this + 17236     [L897-L900]
while (*v101 != *((_DWORD *)v93 + 4350)) { ++v100; ++v101; if (v100 >= 20) goto LABEL_283 }   [L901-L906]
v99 = (this[4 * v100 + 17316] + this[4368]) * 0.5                  [L908]
LABEL_283:
if ((v93[4351] > v99 || v178 > 0 || v173 > 0) && !this[17772]) { v148 = 0.0; v94 = 0.0 }   [L910-L914]
v102 = *v93
if (*(_DWORD *)(*(_DWORD *)this + 18596) == *(_DWORD *)(LODWORD(v102) + 18596)
    && *(_DWORD *)(*(_DWORD *)this + 18600) > *(_DWORD *)(LODWORD(v102) + 18600)) {
    v94 -= 95.0; v148 -= 95.0                                      [L915-L921]
}
if (this[4436] == 1) { v94 -= 400.0; v148 -= 400.0 }               [L922-L926]
v103 = this[28 * v162 + 17096]
v105 = (v103 <= -1 || this[4366] <= 0.1) ? this[4368]
       : (this[4 * v103 + 17316] + this[4368]) * 0.5               [L927-L932]
v106 = this[17772]; v154 = v148 / v105; v163 = -(v33[4192] / v33[4195])   [L933-L935]
if (v106 && v33[4192] < 15.0) {                                    [L936]
    if ((this[4357] + this[4358]) * 0.5 <= v33[4196]) { if (v94 <= 400.0) v94 = 400.0 }
    else if (v148 <= 400.0) v148 = 400.0                           [L938-L946]
    v154 = 2.0; v163 = 1.0                                         [L947,L948]
}
if ((i || v148 == 0.0 || v154 <= 0.0 || v163 <= 0.0 || v154 <= v163)
    && 500.0 - v104[4279] >= v148) goto LABEL_314                 [L950,L951]
if (v149 < v156 || v106) { v86 = 1; this[17785] = 1;
    LABEL_314: if (v106 && v33[4192] < 15.0) goto LABEL_321 }      [L952-L958]
v107 = this[28 * v33[4205] + 17096]
v108 = (v107 <= -1 || this[4366] <= 0.1) ? this[4368]
       : (this[4 * v107 + 17316] + this[4368]) * 0.5               [L960-L964]
v154 = v94 / v108                                                  [L965]
LABEL_321:
if ((i || v94 == 0.0 || v154 <= 0.0 || v163 <= 0.0 || v154 <= v163)
    && v94 <= 500.0 - this[28 * v33[4205] + 17116]
    || v149 >= v156 && !v106) {                                    [L967-L969]
    if (!v86) {
        if (v149 >= v156 && *(int *)(v34 + 17756) <= 2) v86 = 5    [L973,L975]
        else if (v139 || v33[4192] < 5.5) {
            if (fabs(v33[4190]) >= 0.300000011920929) { v111 = v33[4190]; v109 = v111 < 0; v110 = v111 == 0 }
            else { v109 = v94 < v148; v110 = v94 == v148 }          [L977-L989]
            if (v109 || v110) v86 = 8; else v86 = 7                 [L990-L993]
        } else v86 = 16                                            [L995,L997]
    }
} else if (v86 == 1 && v94 <= v148) { this[17785] = 1 }             [L1001,L1003]
else { v86 = 2; this[17785] = 1 }                                  [L1005-L1008]
```
(continued in part5 at L1010)

## Meaning (GUESS)

- GUESS The `< 4.0` branch handles an opponent almost alongside: it widens bound 0x4418, bumps counter 0x455C,
  stores direction-dependent lateral targets via SignedIndexTableLookup, applies a `speed * 0.8` clamp when the
  closing condition holds, and pulls the corridor bound by `(v144 +- v167) * scale` [L668-L760].
- GUESS The general branch first rejects opponents behind or beyond the 1.75 gap (`v33[4205]` mode = 5), then when
  opponent `v33[4201] < 1.0` and speed > 1.2 it adjusts the corridor bounds by up to 5 m (speed-scaled below
  20 m/s), marking latch 0x456C [L762-L799].
- GUESS Mode selection computes per-side distances `v94`/`v148` around the opponent's corridor, adjusts by the
  opponent's counters `+17776`/`+17780` (75/unit), teammate give-way (-95), pit selector 0x4550 (-400), and
  look-ahead waypoint speeds, then picks `v86`: 5 (follow), 16 (blocked/push), 7/8 (pass left/right), 1, or 2
  [L800-L1008].
- GUESS If the per-opponent state 0x42D8 is >= 0x4480 the stored mode 0x42D4 is reused, else the state is reset to
  0x4480+1 [L804-L817].

## Questions

- `v86` mode numbers: prior art and inspect name 1/2/7/8 as overtake modes, but 3/4/5/16 are not yet mapped; part5
  resolves 3/4/7/8/16.
- `v93[4369]` (opponent +17476) and `v93[4426]/[4427]` (+17704/+17708) semantics unknown; they shape the corridor.
- 0x4480 (this[4384]) is used as a per-opponent state reset value; name unknown.
- The `i ||` terms in the LABEL_314/LABEL_321 conditions skip the checks on the first loop iteration; why is the
  first ranked opponent special?
