# map_AISteering_part5 — `AISteering` declared `sub_4270A0`, source L1010-L1314 (mode execution + epilogue)

Part 5 of 5 (phase: finish the per-opponent mode, execute overtaking, publish the lateral target). Function:
address `0x4270A0`; file `functions/AISteering_004270a0.c`; 1314 lines. Caller: `AIMainUpdate` L247.

## Identity

- `this` = F1CVehicle, declared `char *` (`sub_4270A0(char *this)`); float fields use `*((float *)this + N)`
  (byte offset `N * 4`), byte fields use `this[N]` (byte offset `N`). The Logic below keeps source-literal forms.
  `v33` = proximity slot record; `v34` = opponent; `v179` = slot waypoint. `v86` = steering
  mode for this opponent. This part calls `Overtaking(this, v86)` and writes the per-opponent state 0x42D4 and the
  class-level corridor fields.
- Names: 0x4408 = racing-line lateral position (published steering target, doc 54 live); 0x440C = working target;
  0x4414/0x4418 = corridor bounds (prior art); 0x4420 = target lateral request (prior art); 0x4424 = hard override;
  0x4548 = override-enable for request 0x4420 (Claude review, not "clear" flag); 0x4440 = Speed; 0x4428 = lateral
  position (doc 54); 0x4550 = waypoint set selector (typed); 0x42D4 = per-opponent mode; 0x42DC = per-opponent
  accumulator; 0x42C8 = per-opponent waypoint index; 0x4140 = outside-corridor flag (Claude review; inspect:
  collision-awareness); 0x4488 = waypoint re-scan flag read by `sub_426430` (Claude review), cleared every tick
  here; 0x4548 is NOT cleared here.

## Inputs

| hex | dec | type | first line read | name |
|---|---|---|---|---|
| 0x42D4 | 17108 | _DWORD | L1036, L1215, L1264 | per-opponent mode |
| 0x42DC | 17116 | float | L968 (part4), L1271 | per-opponent accumulator |
| 0x4440 | 17472 | float | L1143 | Speed (CONFIRMED) |
| 0x4428 | 17448 | float | L1210, L1254 | lateral position (doc 54) |
| 0x4418 | 17432 | float | L1135, L1204, L1248 | corridor bound 2 |
| 0x4550 | 17744 | _DWORD | L1117 | waypoint set selector (typed) |
| 0x440C | 17420 | float | L1293, L1295 | working lateral target |
| 0x4414 | 17428 | float | L1308 | corridor bound 1 |
| 0x4408 | 17416 | _DWORD | L1308, L1309 | published steering target |
| 0x4548 | 17736 | char | L1302 | ? override-to-0x4420 flag |
| 0x4424 | 17444 | float | L1306 | hard lateral override |

Opponent `v34` fields read: `+17756`, `+17476` (`+13700` via slot vehicle ptr).

## Outputs

| hex | dec | type | first line written | name |
|---|---|---|---|---|
| 0x4418 | 17432 | float | L1135 | corridor bound 2 |
| 0x455C | 17756 | _DWORD | L1144 | ? counter incremented |
| 0x42D4 | 17108 | _DWORD | L1218, L1224, L1269, L1277 | per-opponent mode (3/7/8/4) |
| 0x42DC | 17116 | float | L1271 | per-opponent accumulator `*= 0.5` |
| 0x440C | 17420 | float | L1296, L1300 | working lateral target |
| 0x4408 | 17416 | _DWORD | L1303, L1305, L1307 | published steering target |
| 0x4140 | 16704 | char | L1311 | ? clamp flag set |
| 0x4488 | 17544 | char | L1313 | ? loop-state flag cleared |

## Constants

Grouped by value; every numeric literal except 0/1 in L1010-L1314.

| value | lines | note |
|---|---|---|
| 1.0 | L1014, L1027, L1056, L1070, L1134, L1204, L1248 | mode/factor work |
| 2.0, 7.0, 8.0, 4.0, 16.0 | L1012-L1098 | mode numbers |
| 0.5 | L1221, L1266 | half-gap gates |
| 1.2, 1.5 | L1074, L1121 | clamp input scales |
| 10.0 | L1119, L1208, L1252 | distance gates |
| 20.0 | L1127 | distance gate |
| 0.30000001, 0.44999999, 0.64999998 | L1136-L1138 | gap fractions |
| 7.5, 10.0, 12.5 | L1145-L1150 | gap floors |
| 13700 | L1151 | opponent flag gate |
| 0.1 | L1151 | opponent flag threshold |
| 0.25, 1.2 | L1158, L1165 | v33[4195] gates/scale |
| 0.0099999998 | L1189 | quadratic scale |
| -4.0 | L1215, L1264 | `v33[4195]` gate |
| 0.85000002 | L1051 | accumulator scale |
| 3.0 | L1139 | `fabs(v33[4190])` gate |
| -2.0 | L1084 | decision threshold |
| 15.0 | L1077, L1106 | distance split |
| 400.0, 95.0 | L919-L946 (part4) | offsets used here via v94/v148 |

## Logic

NOTE: source uses scaled `this[N]` / slot `v33[N]` forms; Logic keeps source-literal indices. No hex tokens used.

```
if (!v106) {                                                    [L1010]
    if (v86 == 1) {
        if (*(float *)(v179 + 84) - (v144 + v167) >= 0.0) goto LABEL_356
        if (v165 <= 1.0) { v86 = 7; goto LABEL_356 }
        v86 = 2                                                 [L1012-L1021]
    } else if (v86 != 2) goto LABEL_356                         [L1023,L1025]
    if (v144 - v167 + *(float *)(v179 + 80) < 0.0) { v86 = 1; if (v165 >= -1.0) v86 = 8 }   [L1027-L1032]
}
LABEL_356:
v112 = &this[28 * v33[4205] + 17108]; v113 = *v112              [L1035,L1036]
if (*v112 != v86) {                                             [L1037]
    if (v113 == 2 && v86 == 16) v86 = 7                         [L1039,L1041]
    else if (v113 == 1 && v86 == 16) v86 = 8                    [L1043,L1045]
    *v112 = v86                                                 [L1047]
    if (v86 == 16) { this[28 * v33[4205] + 17116] *= 0.85000002; goto LABEL_365 }   [L1048-L1052]
}
LABEL_368:
if (v86 == 8 || v86 == 7) { v168 = 1.0; v158 = 1.0 }            [L1056-L1060]
if (v86 == 4) { v168 = 1.0; v158 = 1.0;
    TrackParameterMinimumClamp(v33[4195] * 1.2 + this[4368]); v86 = 2; goto LABEL_382 }   [L1061-L1068]
if (v86 == 3) { v168 = 1.0; v158 = 1.0;
    TrackParameterMinimumClamp(v33[4195] * 1.2 + this[4368]); v86 = 1; }   [L1070-L1076]
    LABEL_376: if (v33[4192] >= 15.0) { v117 = v144 + 2.0; v115 = v117 < this[4359]; v116 = v117 == this[4359] }
    else { v114 = v33[4190]; v115 = v114 < -2.0; v116 = v114 == -2.0 }
    if (!v115 && !v116) v86 = 8;                                [L1077-L1091]
    goto LABEL_387
LABEL_365:
if (v141) { v86 = 16; this[28 * v33[4205] + 17108] = 16; goto LABEL_387 }   [L1094-L1099]
if (v86 == 1) goto LABEL_376                                    [L1101,L1102]
if (v86 != 2) goto LABEL_387                                    [L1103,L1104]
LABEL_382:
if (v33[4192] >= 15.0) v118 = v144 - 2.0 < this[4359]; else v118 = v33[4190] < 2.0   [L1105-L1109]
if (v118) v86 = 7                                               [L1110,L1111]
LABEL_387:
if (v139) v165 = v144 - this[4362]                               [L1113,L1114]
if (v86 != 16 && v86 != 7 && v86 != 8) goto LABEL_434           [L1115,L1116]
if (this[4436] == 1 && fabs(v33[4190]) < 2.0) {                 [L1117]
    if (v33[4192] < 10.0) { v119 = this[4368] - 1.5; LABEL_398: TrackParameterMinimumClamp(v119); goto LABEL_399 }
    if (v33[4192] < 20.0) { v119 = this[4368] - 1.0; goto LABEL_398 }   [L1119-L1131]
}
LABEL_399:
v141 = 1; this[4418] = this[4418] + 1.0                         [L1134,L1135]
v120 = v156*0.30000001; v164 = v156*0.44999999; v155 = v156*0.64999998   [L1136-L1138]
if (*(int *)(v34 + 17756) >= 2 || fabs(v33[4190]) >= 3.0) {     [L1139,L1140]
    if (fabs(v33[4190]) < 2.0 || fabs(v165) < 2.0) {
        if (v156 + v156 > v33[4192]) ++this[4439]               [L1143,L1144]
        v120 = max(v120, 7.5); v164 = max(v164, 10.0); v155 = max(v155, 12.5)   [L1145-L1150]
        if (*(float *)(*((_DWORD *)v33 + 4189) + 13700) > 0.1 && v33[4195] > 0.0)
            v33[4195] = -1.0                                    [L1151,L1152]
        if (v149 < v120 && v33[4195] < 0.5) { v122 = v33[4195] - 10.0; goto LABEL_433 }   [L1153-L1157]
        if (v149 < v164 && v33[4195] < 0.25) { v122 = v33[4195] - 5.0; goto LABEL_433 }   [L1158-L1162]
        if (v149 < v155 && v33[4195] < 0.0) { v122 = v33[4195] * 1.2; goto LABEL_433 }    [L1163-L1167]
    }
} else {
    if (v156 + v156 > v33[4192]) ++this[4439]                   [L1172,L1173]
    if (v33[4192] < 10.0) {
        if (v33[4195] >= 0.0) TrackParameterMinimumClamp(this[4368])
        else TrackParameterMinimumClamp(this[4368] - 10.0)      [L1174-L1184]
    }
    v121 = max(v33[4192] - 10.0, 0.0)
    if (v121 * v121 * 0.0099999998 + v33[4201] < this[4 * this[28 * v33[4205] + 17096] + 17316]) {
        v122 = v33[4195] - 10.0;
        LABEL_433: v136 = v122 + this[4368]; TrackParameterMinimumClamp(v136)   [L1186-L1199]
    }
}
LABEL_434:
if (v86 == 2 || v86 == 7) {                                     [L1202]
    this[4418] = this[4418] + 1.0; Overtaking(this, v86)        [L1204,L1205]
    if (v33[4192] < 10.0 && fabs(v33[4190]) < 2.0) TrackParameterMinimumClamp(this[4368])   [L1206,L1207]
    if (v33[4192] < 10.0 || v33[4195] < 1.0) {
        v124 = (v165 - v167) * v168 + this[4362]                [L1210]
        if (v124 <= v146) {
            if (v140) {
                if (this[28 * v33[4205] + 17108] != 4 && v33[4195] > -4.0) {
                    ++this[4439]; this[28 * v33[4205] + 17108] = 3; goto LABEL_454 }   [L1215-L1219]
                if (v156 * 0.5 > v33[4192]) {
                    ++this[4439]; this[28 * v33[4205] + 17108] = 7; goto LABEL_453 }   [L1221-L1225]
            } else { ++this[4439]; v145 = v146; v138 = 1 }      [L1228-L1233]
        } else { ++this[4439]; if (v145 > v124) { v145 = v124; v138 = 1 } }   [L1235-L1243]
    }
} else if (v86 == 1 || v86 == 8) {                              [L1246]
    this[4418] = this[4418] + 1.0                               [L1248]
    if (v33[4192] < 10.0 && fabs(v33[4190]) < 2.0) TrackParameterMinimumClamp(this[4368])   [L1249,L1250]
    Overtaking(this, v86)                                       [L1251]
    if (v33[4192] < 10.0 || v33[4195] < 1.0) {
        v123 = (v165 + v167) * v158 + this[4362]                [L1254]
        if (v123 >= v145) {
            if (!v138) { ++this[4439]; v146 = v145; v140 = 1; continue }   [L1257-L1262]
            if (this[28 * v33[4205] + 17108] == 3 || v33[4195] <= -4.0) {
                if (v156 * 0.5 <= v33[4192]) continue
                ++this[4439]; this[28 * v33[4205] + 17108] = 8
                LABEL_453: this[28 * v33[4205] + 17116] *= 0.5   [L1264-L1272]
            } else { ++this[4439]; this[28 * v33[4205] + 17108] = 4 }   [L1274-L1278]
            LABEL_454: v137 = v33[4195] + this[4368]; TrackParameterMinimumClamp(v137); continue   [L1279-L1282]
        }
        ++this[4439]; if (v146 < v123) { v146 = v123; v140 = 1 }  [L1284-L1289]
    }
}
# end opponent loop
if (v145 >= this[4355]) { if (v146 > this[4355]) this[4355] = v146 } else this[4355] = v145   [L1293-L1300]
v125 = this[17736]; this[4354] = this[4355]                      [L1302,L1303]
if (v125) this[4354] = this[4360]                                [L1304,L1305]
if (this[4361] != 0.0) this[4354] = this[4361]                   [L1306,L1307]
if (this[4354] >= this[4357] || this[4354] <= this[4358]) this[16704] = 1   [L1308-L1311]
this[17544] = 0                                                  [L1313]
```

## Meaning (GUESS)

- GUESS Finalises the per-opponent mode: promotes 16 to 7/8 when the previous mode was 2/1, forces 7/8/16 when the
  geometry conditions hold, and stores the result in 0x42D4 [L1010-L1112].
- GUESS Modes 7/8/16 (overtake-attempt family) get a speed clamp `speed - 1.5/-1.0` while the waypoint selector
  0x4550 is 1, and corridor-bound 0x4418 grows by 1 per tick [L1117-L1135].
- GUESS Then the closing distance is trimmed in three bands (`< v156*0.30/0.45/0.65`, floors 7.5/10/12.5) and
  `TrackParameterMinimumClamp` is called with `v33[4195] +- speed` to force the AI's speed limit [L1136-L1199].
- GUESS Modes 2/7 (pass) and 1/8 (pass the other side) call `Overtaking(this, v86)` and update corridor bounds
  0x4414/0x4418; on success the per-opponent mode becomes 3/7/8/4 and the accumulator 0x42DC halves [L1202-L1289].
- GUESS Epilogue: 0x440C = max/min update from v145/v146 (corridor result); 0x4408 gets 0x440C, but byte 0x4548
  (enable) replaces it with the request 0x4420, and a non-zero float 0x4424 wins over both; raise the 0x4140 flag
  when the published target is outside 0x4414/0x4418 and clear 0x4488 [L1293-L1313].

## Claude review notes (2026-10-02, DERIVED — do not re-tier)

Source: `REVIEW_3_GROUP2.md`, from raw source L1293-L1313 (`this` is `char *`, float index *4):

- 0x440C: max/min update from v145/v146 (corridor result).
- 0x4408 = 0x440C bit-copied; **if byte 0x4548 != 0 then 0x4408 = 0x4420 (request used directly)**; if float
  0x4424 != 0 then 0x4408 = 0x4424 (last word). So 0x4548 is an override-enable, not an "unless" block, and
  0x4424 wins over both.
- If 0x4408 >= 0x4414 or <= 0x4418, byte 0x4140 = 1 (outside-corridor flag). Then byte 0x4488 = 0 (the waypoint
  re-scan flag used by `sub_426430`). 0x4548 is NOT cleared here.
- Source-literal mapping for the Logic below: `this[4355]`=0x440C, `this[4354]`=0x4408, `this[4360]`=0x4420,
  `this[4361]`=0x4424, `this[4357]`=0x4414, `this[4358]`=0x4418, `this[17736]`=0x4548 (byte),
  `this[16704]`=0x4140 (byte), `this[17544]`=0x4488 (byte).
- Question to carry: 0x4424 is also written in `AIRacingLine` L133-L142 (half/full of wp+24). Same meaning (a
  forced lateral)? Both writers are listed in `FIELD_GLOSSARY.md` (B5).

## Questions

- Modes 3/4 and 5/16 semantics are still open (3 = "pull out", 4 = "pull back"?); prior art names modes 1/2/7/8
  only.
- Why does the epilogue clamp `0x440C` with the `v145 >= target -> max(target, v146)` form (partially asymmetric)?
- 0x4140 (set when target outside corridor) is inspect-"collision-awareness flag"; who reads it?
- 0x4488 is read at L804 (part4) and cleared here every tick; Claude review: it is the waypoint re-scan flag used
  by `sub_426430`. Which part-4 branch consumes it?
