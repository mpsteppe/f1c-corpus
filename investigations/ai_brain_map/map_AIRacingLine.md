# map_AIRacingLine — section-4 name `AIRacingLine`, declared `sub_425920`

## Corner speed and braking — one page (Claude review 2026-10-02, DERIVED — do not re-tier)

**Corner-speed limit per waypoint** (callee `AIComputePassScore` = `sub_42A780`; the name is wrong, it is no score):

```
v_corner(wp) = (TireForceSolver(wp) * veh[0x4504] + veh[0x4500]) * veh[0x4580] * veh[0x453C] * wp[0x84]
```

| input | hex | dec | meaning | status |
|---|---|---|---|---|
| TireForceSolver(wp) | - | - | tire force at the waypoint (same waypoint block and 16.0 cap AIRacingLine passes to `TireForce` at L263: wp+112/116/120) | callee GUESS |
| veh[4417] | 0x4504 | 17668 | force-to-speed coefficient | unnamed |
| veh[4416] | 0x4500 | 17664 | force-to-speed offset | unnamed |
| veh[4448] | 0x4580 | 17792 | scale | unnamed |
| veh[4431] | 0x453C | 17724 | AIAbility dynamic multiplier | named by prior art |
| wp[33] | wp+0x84 | 132 | per-waypoint factor | unnamed |

Inputs still unnamed: 0x4500, 0x4504, 0x4580, wp+0x84. 0x453C is named by prior art
(`f1c-redflag-no-overtake-was-cosmetic`, `ai-brain-corner-speed-braking-2026-10-02`).
0x4504/0x4500 have the same shape as `sub_426430`'s speed ratio (0x4504/0x4500, cap 75).

**Braking look-ahead** (the profile loop at L233-L295 is a braking projection, not "energy decay"):

- `v46` starts at current speed 0x4440 (L213). For each waypoint ahead, target `v50` = that waypoint's corner speed
  (L259/L261), or pit speed `flt_8ACFB4` when `wp+308 == 1` (L243-L245), or 12.0 at a branch (L255).
- Per segment: `v46 -= wp_len(wp+60) / v46 * 0x44CC * v50 * 0.915` (L264) - speed lost braking over that segment.
  Each projected speed is stored in the 20-slot profile 0x43A4..0x43F0 (`this+17316 + 4*i`, L230/L270).
- Loop stops when the projected speed would still be at/above a waypoint's target (`v46 >= v50`, L233-L234) = braking
  must start NOW: `v46 > 0` path -> brake 0x4438 = TireGripCoefficient (ramp +0.2/tick, L343-L346), throttle 0x4434 =
  0 (L347). If the projection reaches 0 first (every corner ahead is reachable): brake 0 (L306), throttle 0x4434 =
  1.0 / hold value / 0.4-0.5 off-line, ramped by `0.2 * 0x44B8` (race start) or `0.2 * 0x44C4` (L307-L336).
- 0x43F8 = limiting waypoint pointer (L298), 0x43FC = its target speed, 9999 = none (L226/L299). 0x44CC = braking
  decel factor (PassingNorm, prior art). 0x445C (17500) byte = car inside track width + 1.5 m (L302-L303).
- Callee renames from the same review: `TireGripCoefficient` (`0x4E88B0`, this = veh+0xC) = **brake amount**
  (GUESS name `AIBrakeAmount`); `BrakeThermalModel` (`0x4E87E0`, this = veh+0xC) = **throttle to hold speed**
  (GUESS name `AIHoldThrottle`). See `map_TireGripCoefficient.md` and `map_BrakeThermalModel.md`.

## Identity

- Address: `0x425920`; file `functions/AIRacingLine_00425920.c`; 349 lines.
- Callers: `AIMainUpdate` (`0x424E70`); grep `functions/` for `AIRacingLine(` -> `functions/AIMainUpdate_00424e70.c` L245; `inspect` agrees.
- Callees (from `offsets_AIRacingLine.csv` CALL rows): `SpatialTreeNearestNeighborSearch`,
  `F_3DTransformWithMatrixMultiplication`, `AerodynamicForceCalc`, `AIClearStateFlags`, `sub_426430`,
  `BrakeThermalModel`, `AIComputePassScore`, `TireForce`, `TireGripCoefficient`, `sqrt`.
- `this` = F1CVehicle, unchanged from `AIMainUpdate` (`inspect` object_kind CONFIRMED).
- Object fields accessed via pointers are not vehicle offsets (bases `v2`, `v5`, `v9`, `v15`, `v40` in this map).

## Inputs

| hex | dec | type | first line read | name |
|---|---|---|---|---|
| 0x4354 | 17236 | _DWORD | L63 | CurrentWaypointPtr (typed) |
| 0x4400 | 17408 | _DWORD / float* | L71 / L74 | ? (pointer to waypoint/lead data) |
| 0x4424 | 17444 | float | L85 | ? |
| 0x4428 | 17448 | float | L302 | lateral position (doc 54) |
| 0x4438 | 17464 | float | L58 | brake candidate (doc 54) |
| 0x443C | 17468 | _DWORD | L71 | ? |
| 0x4440 | 17472 | float | L79 | Speed (typed) |
| 0x445C | 17500 | _BYTE | L313 | ? |
| 0x446C | 17516 | _DWORD | L315 | ? |
| 0x44B8 | 17592 | float | L329 | ? |
| 0x44C4 | 17604 | float | L331 | ? |
| 0x44CC | 17612 | float | L264 | ? |
| 0x4524 | 17700 | float | L116 | ? |
| 0x454C | 17740 | _DWORD | L66 | CallToBox (typed) |
| 0x4550 | 17744 | _DWORD | L64 | WaypointSetSelector (typed) |
| 0x4554 | 17748 | float | L209 | ? |

## Outputs

| hex | dec | type | first line written | name |
|---|---|---|---|---|
| 0x34F8 | 13560 | float | L165 | RenderZ (typed) |
| 0x34FC | 13564 | float | L167 | ? |
| 0x3500 | 13568 | float | L166 | ? |
| 0x43A4 | 17316 | 20-float array via pointer | L270 (`*v31`, address built L230/L286) | ? speed-profile array |
| 0x43F8 | 17400 | _DWORD | L168 | ? |
| 0x43FC | 17404 | float | L226 | ? target speed |
| 0x4424 | 17444 | float | L104 | ? |
| 0x4434 | 17460 | float | L193 | throttle candidate (doc 54) |
| 0x4438 | 17464 | float | L175 | brake candidate (doc 54) |
| 0x443C | 17468 | _DWORD | L82 | ? |
| 0x445C | 17500 | _BYTE | L302 | ? |
| 0x4468 | 17512 | _DWORD | L133 | look-ahead index (doc 54) |
| 0x4510 | 17680 | _DWORD | L171 | driverStatus / mode (typed, doc 54) |
| 0x4524 | 17700 | float | L83 | ? |
| 0x454C | 17740 | _DWORD | L177 | CallToBox (typed) |
| 0x4550 | 17744 | _DWORD | L178 | WaypointSetSelector (typed) |
| 0x45F4 | 17908 | _BYTE | L163 | AIControlFlag (typed) |

## Constants

Grouped by value; every numeric literal except 0/1 in `functions/AIRacingLine_00425920.c`.

| value | lines | note |
|---|---|---|
| 2 | L54, L75 | array sizes / index 2 |
| 4 | L171, L220, L230, L286-L293 | driverStatus 4; pointer stride |
| 5 | L162, L173 | 5.0; driverStatus 5 |
| 7 | L170 | session type compare |
| 8 | L146 | waypoint field index |
| 12 | L56, L193, L309, L316, L343 | array size; `this+12` argument |
| 12.0 | L255 | fixed pass score when chain blocked |
| 17.0 | L126 | threshold base |
| 19.0 | L94 | threshold base |
| 20 | L222, L267, L279, L287 | profile length / loop bounds |
| 24 | L94, L102, L110, L126, L135, L142 | waypoint/car field |
| 25.0 | L320 | brake 0.4/0.5 speed split |
| 28.0 | L95, L96, L127, L128 | threshold cap |
| 60 | L264 | waypoint drag coefficient |
| 68, 69, 75 | L70, L69, L67 | waypoint link fields |
| 80 | L218, L303 | stride 80; waypoint width field |
| 84 | L302 | waypoint width field |
| 112, 116, 120 | L263 | TireForce args (`wp+112/116/120`) |
| 272, 276 | L68/L67, L238, L240, L249 | waypoint links |
| 300 | L69, L237, L252 | waypoint branch id field |
| 308, 312 | L206, L207, L243 | waypoint per-car mode fields |
| 0.2 | L332, L344, L345 | smoothing step / grip cap |
| 0.30000001 | L188, L190 | deceleration factor |
| 0.40000001 | L77, L322 | aero arg / brake value |
| 0.5 | L102, L135, L326 | half values |
| 0.67000002 | L97, L129 | threshold fraction |
| 0.69999999 | L189 | aero arg |
| 0.75 | L79 | aero arg |
| 0.91500002 | L264 | energy factor |
| 1.05 | L204 | pass-score comparison speed factor |
| 1.2 | L126 | threshold factor |
| 1.5 | L302, L303 | corridor margin |
| 1.8 | L293 | fixed profile decrement |
| 1065353216 | L175, L198 | float bit pattern = 1.0 |
| 1176255488 | L226 | float bit pattern = 9999.0 |
| 0.0 | L80, L85, L116, L159, L190, L227, L274, L304 | comparisons |

## Logic

NOTE: `verify_maps.py` checks every `0x…` token on a line against the decimal byte offset printed in the
cited source line. `this[N]`/`v6[N]` scaled array forms therefore remain source-literal; the byte offset is in
the tables above.

```
# setup: find nearest waypoint, resolve car chain
v52 = this->0x4438                                   [L58]
v2 = SpatialTreeNearestNeighborSearch(dword_5EA2C0, this+13536, this->0x4354, this->0x4550, 0)  [L60,L62,L63,L64]
v3 = this->0x454C                                    [L66]
wp = *(v2+276); if (!v3 || wp == 0 || v3 != wp[75]) wp = *(v2+272)   [L67,L68]
v5 = wp[69];    if (!v3 || v5 == 0 || v3 != *(v5+300)) v5 = wp[68]   [L69,L70]

# approach block A: lead object at this->0x4400 (active while 0x443C flag set) [L71]
if (this->0x443C != 0 && this->0x4400 != 0)          [L71]
    F_3DTransformWithMatrixMultiplication(v53, v55)   [L73]
    v6 = this->0x4400                                [L74]
    dist = sqrt((v54-v6[2])^2 + (v53[0]-v6[0])^2)    [L75,L76]
    v8 = 0.40000001 * dist; v45 = v8                 [L77,L78]
    AerodynamicForceCalc(this->0x4440, v45, 0.75)    [L79]
    if (v8 > 0.0) { this->0x443C = 0; this->0x4524 = dist }   [L80,L82,L83]
    if (this->0x4424 == 0.0)                         [L85]
        v9 = this->0x4400; v10 = *(v9+276)           [L87,L88]
        if (v10)
            d = sqrt(...car vs v10 pos...); thr = sqrt(v9[24]^2) + 19.0  [L91,L93,L94]
            if (thr > 28.0) thr = 28.0               [L95,L96]
            if (0.67000002*thr <= d)                 [L97]
                if (d < thr) { this->0x443C=0; this->0x4524=dist; this->0x4424=v9[24]*0.5 }  [L101,L103,L104]
            else { this->0x443C=0; this->0x4424=v9[24]; this->0x4524=dist }  [L109,L110,L111]

# approach block B: while 0x4524 set, re-measure and decide waypoint pass [L116]
if (this->0x4524 != 0.0)                             [L116]
    F_3DTransformWithMatrixMultiplication(v53, v55)   [L118]
    v15 = this->0x4400; v16 = *(v15+276)             [L119,L120]
    if (v16)
        thr2 = sqrt(v15[24]^2)*1.2 + 17.0; cap 28.0  [L125,L126,L127,L128]
        if (0.67000002*thr2 <= d2)                   [L129]
            if (d2 < thr2) { this->0x4468=0; this->0x443C=0; this->0x4424=v15[24]*0.5 }  [L133,L134,L135]
        else { this->0x4468=0; this->0x443C=0; this->0x4424=v15[24] }  [L140,L141,L142]
    v20 = *(v15+276); v23 = |car - v15.pos|          [L145,L146,L147,L148]
    if (v20) dot = (v15.x-v53[0])*(v20+12) + (v15.y-v54)*(v20+20)  [L151]
    else { if (v23 <= this->0x4524) goto CONSIDER; dot = v45 }     [L155,L157]
    if (dot <= 0.0)
RESET:
        if (v23 < 5.0) this->0x45F4 = 0              [L162,L163]
        this->0x443C = 0                             [L164]
        this->0x34F8 = 0; this->0x3500 = 0; this->0x34FC = 0   [L165,L166,L167]
        this->0x43F8 = 0                             [L168]
        AIClearStateFlags(this)                      [L169]
        this->0x4510 = (dword_7C56A4 == 7) ? 4 : 5   [L170,L171,L173]
        this->0x4524 = 0                             [L174]
        this->0x4438 = 1.0  (1065353216)             [L175]
        this->0x4434 = 0                             [L176]
        this->0x454C = 0                             [L177]
        this->0x4550 = 1                             [L178]
        this->0x4424 = 0                             [L179]
        sub_426430(this); return                     [L180,L181]
CONSIDER:
    if (v23 > 0.5)                                   [L184]
        v25 = this->0x4440; this->0x4524 = v23       [L186,L187]
        v44 = v23 * 0.30000001                       [L188]
        AerodynamicForceCalc(v25, v44, 0.69999999)   [L189]
        if (v23 * 0.30000001 <= 0.0)                 [L190]
            this->0x4438 = 0; this->0x4434 = BrakeThermalModel(this+12)  [L192,L193]
        else
            this->0x4434 = 0; this->0x4438 = 1.0     [L197,L198]
        return                                       [L200]
    goto RESET                                       [L202]

# main planning path (no active approach target)
v49 = this->0x4440 * 1.05                            [L204]
v26 = AIComputePassScore(v2) < v49 || AIComputePassScore(*(v2+272)) < v49   [L205]
if (*(v5+308) == 1) v27 = *(v5+312)                  [L206,L207]
else v27 = AIComputePassScore(v5) * this->0x4554     [L209]
v50 = v27; v28 = this->0x4354; v29 = 0; v46 = this->0x4440   [L210,L211,L212,L213]
if (v5 != this->0x4354)                              [L214]
    do { *(v28+80) = v46; ++v29; v28 += 4 } while (v29 < 20 && v5 != *v28)   [L218,L219,L220,L222]
    v51 = v29                                        [L223]
this->0x43F8 = 0; this->0x43FC = 9999.0 (1176255488) [L225,L226]
if (v46 <= 0.0) goto END                             [L227]
v30 = v51; v31 = (float *)(this + 4*v29 + 17316)     [L229,L230]

# speed-profile walk
while (1)
    v32 = v46                                        [L233]
    if (v46 >= v50) break                            [L234]
    v33 = this->0x454C                               [L236]
    if (v33 && (v34 = *(v5+276)) != 0 && v33 == *(v34+300)) v5 = *(v5+276)
    else v5 = *(v5+272)                              [L237,L238,L240]
    if (!v5) goto END                                [L241,L242]
    if (*(v5+308) == 1) v32 = flt_8ACFB4             [L243,L245]
    else
        v35 = *(v5+276)
        if (v35 && *(v35+300) == v33 && v33 != 1 && *(v35+300)) { v50 = 12.0; goto STEP }  [L249,L253,L255]
        v32 = AIComputePassScore(v5)                 [L259]
    v50 = v32                                        [L261]
STEP:
    TireForce(v46, *(v5+116), v5+120, *(v5+112))     [L263]
    if (v46 <= 1.0 || (v46 -= *(v5+60)/v46 * this->0x44CC * v32 * 0.91500002, v46 < 0.5))  [L264,L265]
        v46 = 0.0
    v30 = v51                                        [L266]
    if (v51 < 20) { v30 = v51+1; *v31 = v46; ++v51; ++v31 }   [L267,L269,L270,L271,L272]
    if (v46 <= 0.0) goto END                         [L274,L275]

# post-loop: pad shorter profiles with fixed deceleration
if (v30 >= 1) { if (v30 < 20) goto PAD } else { v30 = 1 }   [L277,L279,L284]
PAD:
    v37 = this + 4*v30 + 17316; v38 = 20 - v30       [L286,L287]
    do { v39 = *(v37-4); v37 += 4; *(v37-4) = v39 - 1.8; --v38 } while (v38)   [L290,L291,L293]
byte_5C3160 = 0; this->0x43F8 = v5; this->0x43FC = v50   [L297,L298,L299]

END:
v40 = this->0x4354                                   [L301]
this->0x445C = (v40[84]+1.5 > this->0x4428) && (v40[80]+1.5 > -this->0x4428)  [L302,L303]
if (v46 <= 0.0)                                      [L304]
    this->0x4438 = 0                                 [L306]
    if (v26) v42 = BrakeThermalModel(this+12)        [L307,L309]
    else
        if (this->0x445C) { v42 = this->0x446C ? BrakeThermalModel(this+12) : 1.0 }  [L313,L315,L318]
        else v42 = (this->0x4440 <= 25.0) ? 0.40000001 : 0.5   [L320,L322,L326]
        v43 = byte_5C3160 ? this->0x44B8 : this->0x44C4   [L328,L329,L331]
        v47 = v43 * 0.2                              [L332]
        if (v42 - this->0x4434 > v47) { this->0x4434 += v47; return }   [L333,L335,L336]
    this->0x4434 = v42                               [L339]
else
    v41 = TireGripCoefficient(this+12)               [L343]
    if (v41 - v52 > 0.2) v41 = v52 + 0.2             [L344,L345]
    this->0x4438 = v41; this->0x4434 = 0             [L346,L347]
```

## Meaning (GUESS)

> Claude review 2026-10-02: bullets below that describe "energy decay" and the
> `BrakeThermalModel`/`TireGripCoefficient` readings are superseded by the one-page section at the top of this map.
> The bullets stay as the original unreviewed transcription; they are not re-tiered here.

- GUESS Per-tick speed planner: builds a 20-slot speed profile over the waypoint chain and writes throttle/brake candidates 0x4434/0x4438 [L211-L347].
- GUESS Resolves the local waypoint chain from CurrentWaypointPtr 0x4354 via SpatialTreeNearestNeighborSearch, then follows links wp+272 / wp+276, preferring the branch whose id matches CallToBox 0x454C [L60-L70, L236-L240].
- GUESS Block at L71-L158 is a lead-car/avoidance stage: 0x4400 is a waypoint/car pointer; distance to it arms 0x4524 (recorded distance) and sets collision/avoidance distance 0x4424 to half or full car length [L74-L142].
- GUESS LABEL_38 reset = waypoint passed or overshoot recovery: zeroes velocity fields 0x34F8-0x3500, forces mode 0x4510 to 4/5, clears CallToBox 0x454C and sets WaypointSetSelector 0x4550=1, calls sub_426430 [L161-L180].
- GUESS v23 > 0.5 branch is "close to next waypoint": target speed = distance, full throttle unless closing rate requires brake thermal value [L184-L200].
- GUESS Profile loop: scores each next waypoint (AIComputePassScore, or fixed 12.0 when a linked car blocks the chain), consumes energy via TireForce and factor 0x44CC, decays v46 by `v46 -= wp[15]*0x44CC*v32*0.915/v46` until v46 < 0.5 [L249-L276].
- GUESS Remaining profile slots are filled with a fixed 1.8 m/s decrement [L286-L295].
- GUESS Throttle output path: positive profile -> TireGripCoefficient capped at previous+0.2; exhausted profile -> brake/thermal value smoothed by 0.2 * (0x44B8 or 0x44C4) [L339-L347].
- GUESS 0x445C = lateral-corridor test comparing waypoint half-width (wp[84], wp[80]) plus 1.5 m against lateral -0x4428 [L301-L303].
- GUESS 0x43FC = 9999.0 is the "no target speed yet" sentinel; 0x43F8 later receives the blocking car pointer v5 and 0x43FC its score v50 [L225-L226, L298-L299].

## Questions

- Address-only inputs not emitted as rows (listed in `unmatched_AIRacingLine.txt`): `(float *)(this + 13536)` L62 (world position to the spatial query), `v28 = this + 17236` L211, `BrakeThermalModel(this + 12)` L193/L309/L316, `TireGripCoefficient(this + 12)` L343. Byte offsets 13536/17236 are known; `this + 12` semantic unknown.
- Fields with `?` (0x4400, 0x4424, 0x443C, 0x445C, 0x446C, 0x44B8, 0x44C4, 0x44CC, 0x4524, 0x4554, 0x43F8, 0x43FC, 0x34FC, 0x3500) need names.
- `dword_7C56A4 == 7` selects mode 4 vs 5 (session-type dependency); needs session-type doc.
- `byte_5C3160` switch selects smoothing constant 0x44B8 vs 0x44C4; role unknown.
- `v10 | v11`-style flags do not appear here, but `v26` (pass-score boolean) and the `310`/`312` waypoint fields are unexplained.
- Why two nearly identical avoidance blocks (L71-L115 vs L116-L144)? GUESS different trigger sources; needs live confirmation.

## Claude review (dropped ST0, 2026-10-02)

Added by DeepSeek C9 per `REVIEW_11_C8.md` + `phase2/DROPPED_ST0_SCAN.md`; no existing tier is changed.

- The braking step at 0x425ED9 calls `TireForce` 0x4E9100 and multiplies by its dropped ST0 return (`fmul st(1)`, 0x425EFC):
  `v -= seg_len(wp+0x3C)/v * 0x44CC * TireForce(v, wp+116, wp+120, wp+112) * 0.915`. The `v50`/`v32` shown as the third
  factor in the L264 pseudo-code is the target, not the force (finding `ai-brain-braking-step-tireforce-correction-2026-10-02`).
- The two approach-block conditions at L80 and L190 compare the return of `AerodynamicForceCalc` 0x4E8B80 with 0.0
  (`fcomp [0x59E440]` directly after the calls at 0x425A19 and 0x425C8C), not `v8` / `v23*0.3` as the pseudo-code shows.
