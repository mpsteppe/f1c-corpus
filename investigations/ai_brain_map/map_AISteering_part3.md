# map_AISteering_part3 — `AISteering` declared `sub_4270A0`, source L441-L667 (per-opponent gap handling)

Part 3 of 5 (phase: iterate the ranked opponents and apply the close-range follow/avoidance gates). Function:
address `0x4270A0`; file `functions/AISteering_004270a0.c`; 1314 lines. Caller: `AIMainUpdate` L247.

## Identity

- `this` = F1CVehicle. `v33 = &this[68 * slot]` is the proximity slot record (see
  `map_OpponentProximityScanTeamRecognition.md`): +0x4174 vehicle ptr, +0x4180 [slot+12], +0x4184 [slot+16],
  +0x418C [slot+24], +0x4190 [slot+28], +0x41A4 [slot+48], +0x41A8 [slot+52 distance], +0x41AC [slot+56 resolved
  waypoint], +0x41B4 [slot+64 team index]. `v35` = slot waypoint pointer.
- Names: 0x44F8 = TrackAggressionEffective (CONFIRMED prior art); 0x4440 = Speed (CONFIRMED); 0x4428 = lateral
  position (doc 54); 0x4450 = ? waypoint lateral reference; 0x44A4 = ? look-ahead distance; 0x4438 = brake
  candidate (doc 54); 0x4468 = look-ahead index (doc 54); 0x4414/0x4418 = corridor bounds (prior art); 0x4420 =
  target lateral (prior art); 0x42D4/0x42D8/0x42DC = per-opponent state (mode / block flag / accumulator).

## Inputs

| hex | dec | type | first line read | name |
|---|---|---|---|---|
| 0x41A8 | 16808 | float | L448 (`this[v31 + 16808]`) | slot squared distance |
| 0x44F8 | 17656 | float | L455 | TrackAggressionEffective (CONFIRMED) |
| 0x4450 | 17488 | float | L476 | ? waypoint lateral reference |
| 0x44A4 | 17572 | float | L492 | ? look-ahead distance |
| 0x4440 | 17472 | float | L497 | Speed (CONFIRMED) |
| 0x4428 | 17448 | float | L515 | lateral position (doc 54) |
| 0x4438 | 17464 | float | L689 | brake candidate (doc 54) |
| 0x4544 | 17732 | _DWORD | L553 | ? gate flag |
| 0x456C | 17772 | char | L634 | ? avoidance latch (v142) |
| 0x4468 | 17512 | _DWORD | L775 | look-ahead index (doc 54) |
| 0x42D4 | 17108 | _DWORD | L534 (`this[v55]`) | per-opponent mode (read) |
| 0x42DC | 17116 | float | L611 (`this[28*idx+17116]`) | per-opponent accumulator |

Opponent (`v34`, slot vehicle ptr) fields read: +13000, +17680, +17756, +17776, +17780, +17476.
Waypoint (`v35`) fields read: +32/+40 (right vector), +52, +56, +72, +80/+84 (widths), +148/+156 (position),
+184 (angle), +272 (next).

## Outputs

| hex | dec | type | first line written | name |
|---|---|---|---|---|
| 0x42D4 | 17108 | _DWORD | L540 (`*v57 = 5`) | per-opponent mode |
| 0x42DC | 17116 | float | L611 | per-opponent accumulator (+/- 5.0, *v61) |
| 0x4418 | 17432 | float | L639 | corridor bound 2 |
| 0x4579 | 17785 | char | L638 | ? latch set |
| 0x455C | 17756 | _DWORD | L637 | ? counter incremented |
| 0x4570 | 17776 | _DWORD | L643 | ? opponent id + 1 |
| 0x4574 | 17780 | _DWORD | L656 | ? opponent id + 1 |
| 0x456C | 17772 | char | L797 | ? avoidance latch set |

## Constants

Grouped by value; every numeric literal except 0/1 in L441-L667.

| value | lines | note |
|---|---|---|
| 12000.0 | L451 | slot distance validity |
| 3.0 | L455 | `1.0 - 0x44F8 + 3.0` |
| 4.0 | L461, L554 | fallback v167; opponent counter gate |
| 0.5 | L477 | `flt_5EA3FC * 0.5` |
| 0.800000011920929 | L474 | heading mismatch gate (rad) |
| 3.141592653589793, 6.2831855 | L467-L472 | angle wrap |
| 125.0 | L497 | priority base |
| 0.00056000001 | L497 | speed scale |
| 1.3 | L500 | closing speed weight |
| 2.0, 5.0 | L500-L503 | gap terms |
| 0.15000001 | L504 | speed term |
| 20.0, 10.0 | L505 | gap floor `20 - 10*0x44F8` |
| 0.25 | L517 | slot offset scale |
| 1.75 | L536 | `v177 = v156 * 1.75` |
| 1.5 | L545, L548 | waypoint width margin |
| 0.75 | L555 | speed gate |
| 0.1, 0.30000001, 0.60000002 | L558-L560 | distance thresholds from speed |
| 6.0, 7.0 | L563-L566 | minimum thresholds |
| 10.0 | L567 | distance split |
| 0.80000001, 0.89999998 | L588, L596 | clamp scales |
| 450.0 (1138819072) | L626 | accumulator cap |
| 250.0 | L631 | accumulator cap when CallToBox 0x454C == 1 |
| -3.5 | L634 | gate range |
| 1.0, 2.0 | L644-L664 | gap factors |

## Logic

NOTE: source uses scaled `this[N]` / `v33[N]` forms; Logic keeps source-literal indices. `v40|v41`, `v48|v49`,
`v53|v54`, `v69` are decompiler c0/c2 flag artifacts (sign of the preceding float compare). No hex tokens used.

```
for (i = 0; i < 5; ++i) {                                         [L441,L442]
    v30 = *(&v185 + i); v139 = 0                                  [L443,L444]
    if (v30 == -1) continue                                       [L445,L446]
    v31 = 68 * v30; v32 = this[v31 + 16808]; v33 = &this[v31]     [L447,L448,L449]
    if (v32 >= 12000.0) continue                                  [L450,L451]
    v34 = *((_DWORD *)v33 + 4189)                                 [L452]
    if (*(_DWORD *)(v34 + 13000) == 1) v167 = 1.0 - this[4414] + 3.0   [L453,L455]
    else { v158 = 1.0; v168 = 1.0; v167 = 4.0 }                   [L458,L459,L460,L461]
    v35 = *((_DWORD *)v33 + 4203); v179 = v35                     [L463,L464]
    v170 = v167 - 1.0                                             [L465]
    v36 = *(float *)(curwp + 184) - *(float *)(v35 + 184)         [L466]
    wrap v36 into [-pi, pi]                                       [L467-L473]
    if (fabs(v36) > 0.800000011920929) continue                   [L474,L475]
    v37 = *(float *)(v35 + 72) - this[4372]                       [L476]
    if (flt_5EA3FC * 0.5 <= fabs(v37)) { v39 = flt_5EA3FC;
        v42 = (flag) ? v39 + v37 : v37 - v39; v149 = v42 }        [L477-L485]
    else v149 = v37                                               [L487,L488]
    if (v149 >= 0.0) { v43 = v149 - this[4393]; v149 = v43; if (v43 < 0.0) v149 = 0.0 }   [L490-L496]
    v44 = (125.0 - v149) * this[4368] * 0.00056000001;            [L497]
    if (v44 < 1.0) v44 = 1.0                                      [L498,L499]
    v156 = (1.0 - (v33[4201] - this[4368]) * 1.3) * (2.0 - this[4414]) * v44
         + (int)(v34 + 17756) + (int)(v34 + 17756)
         + (2.0 - this[4414]) * 5.0 + this[4368] * 0.15000001     [L500-L504]
    v45 = 20.0 - this[4414] * 10.0; if (v156 < v45) v156 = v45    [L505-L507]
    v143 = *(float *)(v35 + 40) * (*(float *)(v34 + 13544) - *(float *)(v35 + 156))
         + *(float *)(v35 + 32) * (*(float *)(v34 + 13536) - *(float *)(v35 + 148))   [L508,L509]
    v50 = (flag) ? v143 / *(float *)(v35 + 80) * *(float *)(*(_DWORD *)(v35 + 272) + 80)
                 : v143 / *(float *)(v35 + 84) * *(float *)(*(_DWORD *)(v35 + 272) + 84)   [L511-L514]
    if (fabs(v50 - this[4362]) < fabs(v143 - this[4362])) v143 = v50   [L515,L516]
    v51 = v33[4193] * 0.25                                        [L517]
    sign gate: keep v51 only if (flag ? v51 >= 0.0 : v51 <= 0.0), else v51 = 0.0   [L518-L527]
LABEL_112:
    v55 = 28 * (v33[4205] + 611); v144 = v51 + v143; v165 = v144 - this[4362]   [L529,L530,L531]
    v56 = *(_DWORD *)&this[v55]; v57 = &this[v55]                 [L532,L533]
    if (v56 != 5) v156 = v156 + 2.0                               [L534,L535]
    v177 = v156 * 1.75                                            [L536]
    if (v149 > v177) { *(_DWORD *)v57 = 5; continue }             [L537,L540,L541]
    if (v144 >= 0.0) { if (*(float *)(v35 + 84) + 1.5 < v144) goto LABEL_117 }   [L543-L546]
    else if (-(*(float *)(v35 + 80) + 1.5) > v144) goto LABEL_117   [L548,L550]
    if (v149 >= 0.0 && !this[4433] && *(int *)(v34 + 17680) < 4
        && this[4368] * 0.75 < -v33[4195] && -v33[4201] > 5.0) {  [L552-L556]
        v58 = max(this[4368]*0.1, 5.0); v159 = max(this[4368]*0.30000001, 6.0);
        v151 = max(this[4368]*0.60000002, 7.0)                    [L558-L566]
        if (v149 >= 10.0) {
            if (v149 < v58) { v59 = *(float *)(v34 + 17472); goto LABEL_134 }
            if (v149 < v159) { v60 = *(float *)(v34 + 17472); goto LABEL_137 }
            if (v149 < v151) TrackParameterMinimumClamp(*(float *)(v34 + 17472))   [L567-L580]
        } else if (v33[4192] > 0.0) {
            if (v58 > v33[4192]) { v59 = v33[4195] + this[4368];
                LABEL_134: TrackParameterMinimumClamp(v59 * 0.80000001); goto LABEL_146 }   [L582-L590]
            if (v33[4192] < v159) { v60 = v33[4195] + this[4368];
                LABEL_137: TrackParameterMinimumClamp(v60 * 0.89999998); goto LABEL_146 }   [L592-L598]
            if (v33[4192] < v151) TrackParameterMinimumClamp(v33[4195] + this[4368])   [L600-L604]
        }
    }
LABEL_146:
    if ((this[4414] + 1.0) * 20.0 <= v33[4192] || *(int *)(v34 + 17756) >= 4) {
        this[28 * v33[4205] + 17116] -= 5.0; if (< 0.0) = 0       [L608-L615]
    } else {
        v61 = -v33[4195]; if (v61 <= 1.0) v61 = 1.0;
        this[28 * v33[4205] + 17116] += v61 * this[4414]          [L619-L623]
        if (> 450.0) = 450.0 (bit 1138819072)                     [L625,L626]
        if (this[4435] == 1) { if (> 250.0) = 250.0 }             [L627-L631]
    }
    if (v33[4192] < 0.0 && v33[4192] > -3.5 && !v142) {           [L634]
        v65 = this[4418] + 1.0; ++this[4439]; this[17785] = 1; this[4418] = v65   [L636-L639]
        if (v33[4190] < 0.0) {
            if (!this[4444]) this[4444] = *(int *)(v34 + 17776) + 1   [L640-L643]
            v67 = (v144 + v167) * v158; if (v67 > v146) { v146 = v67; v138 = 1 }   [L644-L649]
            if (v146 > v145) v146 = v145                          [L650,L651]
        } else {
            if (!this[4445]) this[4445] = *(int *)(v34 + 17780) + 1   [L653-L656]
            v66 = (v144 - v167) * v168; if (v66 < v145) { v145 = v66; v138 = 1 }   [L657-L662]
            if (v145 < v146) v145 = v146                          [L663,L664]
        }
        continue                                                  [L666]
    }
```
(continued in part4 at L668)

## Meaning (GUESS)

- GUESS For each ranked opponent closer than 12000 (squared?): rejects cars with heading mismatch > 0.8 rad,
  computes a follow-gap `v156` from TrackAggression 0x44F8 (`20 - 10*0x44F8` floor), the speed difference, the
  opponent's own counters (`+17756`) and the look-ahead lateral term v149 [L451-L507].
- GUESS While the opponent is beside/inside the waypoint width +1.5 m, the corridor bounds 0x4414/0x4418 are pulled
  to `(v144 +- v167) * v158/v168`, and the per-opponent mode 0x42D4 is set to 5 when the gap exceeds
  `v156 * 1.75` [L511-L551].
- GUESS The 0x4420 target is clamped to the corridor distance (`v33[4195] + speed`) with 0.8/0.9 scale factors
  depending on the gap thresholds (off-line geometry) [L552-L606].
- GUESS The per-opponent accumulator 0x42DC decreases by 5 while far/slow (`(0x44F8+1)*20 <= v33[4192]` or
  opponent counter >= 4), otherwise accumulates `-v33[4195] * 0x44F8`, capped 450/250 [L608-L632].
- GUESS The 0x4180-in-[-3.5,0) case is "opponent just behind/beside": widens corridor bound 0x4418 by 1, bumps
  counter 0x455C, sets latch 0x4579, records the opponent id in 0x4570/0x4574 and updates the other bound
  [L634-L666].

## Questions

- `v33[4192]` (slot +0x4180/+12), `v33[4195]` (+0x418C/+24), `v33[4201]` (+0x41A4/+48), `v33[4203]` (+0x41AC/+56)
  semantics need names; parts 4-5 use them for mode decisions.
- `v34 + 17756` read as `(int)` from a float field is a decompile cast; is it a lap/position counter?
- `flt_5EA3FC` (waypoint accumulation weight, docs/12) and `dbl_8AFEA0`/`flt_8ACF90` globals need confirmation.
