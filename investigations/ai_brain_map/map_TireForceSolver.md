# map_TireForceSolver — section-4 name `TireForceSolver`, declared `sub_4E8CE0`

## Identity

- Address: `0x4E8CE0`; file `functions/TireForceSolver_004e8ce0.c`; 230 lines.
- Signature: `double __thiscall sub_4E8CE0(float *this, float a2, float *a3, float a4, float a5)`.
- Callers: `SweptSuspensionCollisionDetection` (`0x401910`), `PhysicsNodePropagationWithDistanceFalloff`
  (`0x401C90`), `sub_426430` (`0x426430`), `AIComputePassScore` (`0x42A780`); grep `functions/` for
  `TireForceSolver(` -> `functions/SweptSuspensionCollisionDetection_00401910.c`,
  `functions/PhysicsNodePropagationWithDistanceFalloff_00401c90.c`, `functions/sub_426430_00426430.c`,
  `functions/AIComputePassScore_0042a780.c`; `inspect` agrees.
- Callees (from `offsets_TireForceSolver.csv` CALL rows): `sub_5895A2` (raw name), `sqrt`.
- `this` is a `float *` vehicle parameter; `this[N]` accesses use element size 4.

## Inputs

| hex | dec | type | first line read | name |
|---|---|---|---|---|
| 0x3514 | 13588 | float | L95 (this[3397]) | ? |
| 0x3A70 | 14960 | float | L95 (this[3740]) | ? |
| 0x3C3C | 15420 | float | L100 (this[3855]) | ? table selector (pos) |
| 0x3C40 | 15424 | float | L113 (this[3856]) | ? table base (pos) |
| 0x3C44 | 15428 | float | L114 (this[3857]) | ? table next row (pos) |
| 0x3C7C | 15484 | float | L123 (this[3871]) | ? table selector (neg) |
| 0x3C80 | 15488 | float | L136 (this[3872]) | ? table base (neg) |
| 0x3C84 | 15492 | float | L137 (this[3873]) | ? table next row (neg) |
| 0x3CFC | 15612 | float | L60 (this[3903]) | ? bracket scale |
| 0x3D00 | 15616 | float | L73 (this[3904]) | ? bracket table base |
| 0x3D04 | 15620 | float | L74 (this[3905]) | ? bracket table next row |

Also read as pointer arguments (bases `a3`): `a3[1]` L95/L147, `*a3` L96/L148.

## Outputs

None. The function returns a `double`; no `this` field is written.

## Constants

Grouped by value; every numeric literal except 0/1 in `functions/TireForceSolver_004e8ce0.c`.

| value | lines | note |
|---|---|---|
| 4.0 | L82, L83, L85 | initial bracket offset |
| 8.0 | L90 | fallback upper bracket |
| 13 | L70, L71, L110, L111, L133, L134, L162, L163, L185, L186 | table index clamp |
| 14 | L68, L108, L131, L160, L183 | table size |
| 128.0 | L80, L81, L203, L205, L206, L209, L210 | force/bracket cap |
| 3397 | L95, L96, L147, L148 | `this[3397]` |
| 3740 | L95, L147 | `this[3740]` |
| 3855 | L100, L152 | table selector |
| 3856, 3857 | L113, L114, L118, L165, L166, L170 | lookup table |
| 3871 | L123, L175 | table selector |
| 3872, 3873 | L136, L137, L141, L188, L189, L193 | lookup table |
| 3903 | L60 | bracket scale |
| 3904, 3905 | L73, L74, L78 | bracket table |
| 0.5 | L227 | midpoint fallback |
| 0.0 | L83, L89, L198, L200, L216, L217, L221, L222, L226 | comparisons |

## Logic

NOTE: source uses scaled `this[N]` indexing (Hex-Rays prints element index for `float *this`). The Logic keeps the
source-literal index; byte offsets are in the tables above. No hex tokens are used on scaled lines.

```
# initial bracket from |a4| and this[3903]/this[3904..3905]
v6 = |a4| * this[3903]; v46 = v6; sub_5895A2(v6); v59 = v6; v7 = (int)v59; v50 = v7   [L60-L65]
if (v7 >= 0)                                                    [L66]
    if (v7 >= 14) v7 = 13                                       [L68,L70]
    v9 = this[v7 + 3904]                                        [L73]
    v8 = v9 + (this[v7 + 3905] - v9) * (v46 - v50)              [L74]
else
    v8 = this[3904]                                             [L78]
if (v8 > 128.0) v8 = 128.0                                      [L80,L81]
v45 = v8 - 4.0                                                  [L82]
if (v8 - 4.0 >= 0.0) v44 = v8 + 4.0                             [L83,L85]
else { v45 = 0.0; v44 = 8.0 }                                   [L89,L90]

# bisection loop: evaluate force at lower (v45) and upper (v44) bracket ends
while (1)
    v10 = v45 * v45                                             [L94]
    lo_load = v10*this[3740] - (v10*a2 + a3[1])*this[3397]      [L95]
    lo_slip = (v10*a4 - *a3) * this[3397]                       [L96]
    if (flags v13 | v14)                                        [L98]
        il = (int)(lo_load * this[3855])                        [L100-L105]
        if (il < 0) v17 = this[3856] + lo_slip                  [L118]
        else { clamp 13; v17 = interp(this[3856],this[3857]) + lo_slip }   [L108-L114]
    else
        il = (int)(lo_load * this[3871])                        [L123-L128]
        if (il < 0) v17 = this[3872] - lo_slip                  [L141]
        else { clamp 13; v17 = interp(this[3872],this[3873]) - lo_slip }   [L131-L137]
    v54 = v17                                                   [L145]
    v23 = v44 * v44                                             [L146]
    hi_load = v23*this[3740] - (v23*a2 + a3[1])*this[3397]      [L147]
    hi_slip = (v23*a4 - *a3) * this[3397]                       [L148]
    if (flags v26 | v27)                                        [L150]
        ih = (int)(hi_load * this[3855])                        [L152-L157]
        if (ih < 0) v30 = this[3856] + hi_slip                  [L170]
        else { clamp 13; v30 = interp(this[3856],this[3857]) + hi_slip }   [L160-L166]
    else
        ih = (int)(hi_load * this[3871])                        [L175-L180]
        if (ih < 0) v30 = this[3872] - hi_slip                  [L193]
        else { clamp 13; v30 = interp(this[3872],this[3873]) - hi_slip }   [L183-L189]
    v36 = v54                                                   [L197]
    if (v30 * v54 <= 0.0) break                                 [L198]
    if (v36 >= 0.0)                                             [L200]
        if (flags v38 | v39) return 128.0                       [L202,L203]
        if (v44 >= 128.0) return 128.0                          [L205,L206]
        v44 = v44 + a5; if (v44 > 128.0) v44 = 128.0            [L207,L208,L209,L210]
    else
        if (flags v38 | v39) continue at cap check              [L214,L215]
        if (v45 <= 0.0) return 0.0                              [L216,L217]
        v41 = v45 - a5; v44 = v45; v45 = v41                    [L218,L219,L220]
        if (v41 < 0.0) v45 = 0.0                                [L221,L222]

# false-position interpolation at sign change
v43 = v36 - v30                                                 [L225]
if (v43 == 0.0) return 0.5 * (v44 - v45) + v45                  [L226,L227]
else return v54 / v43 * (v44 - v45) + v45                       [L229]
```

## Meaning (GUESS)

- GUESS Bisection/false-position solver for a tire force root: brackets [v45, v44] and evaluates the force
  function until it changes sign, then returns the linearly interpolated root [L92-L229].
- GUESS Initial bracket comes from `|a4| * this[3903]` through a 14-entry table this[3904]/this[3905], then
  widened by ±4.0 (fallback [0,8] when negative) [L60-L90].
- GUESS Force function = load term `x^2*this[3740] - (x^2*a2 + a3[1])*this[3397]` plus a slip term
  `(x^2*a4 - *a3)*this[3397]`, table-interpolated with positive/negative branches (same family as TireForce) [L94-L196].
- GUESS `a2` is a normal load/spring input, `a3[1]`/`*a3` are slip-vector components, `a4` a deformation factor,
  `a5` the bracket step (iteration granularity) [L60,L95,L96,L207,L218].
- GUESS Return 128.0 / 0.0 on cap or exhaustion, else interpolated force value; large 128 constants act as
  force saturation bounds [L80,L203,L206,L217].
- GUESS Called by both physics nodes and AI scoring (`AIComputePassScore`), so it likely resolves the same
  tire force used by grip computations [identity callers].

## Questions

- `v13 | v14`, `v26 | v27`, `v38 | v39` flag bytes are decompiler artifacts (uninitialized c0/c2 flags); exact
  sign comparisons lost by Hex-Rays — same pattern as TireForce.
- `sub_5895A2` raw name unknown.
- `a3` pointer array layout: only `*a3` and `a3[1]` used; is this a 2-component slip vector?
- Purpose of two nearly duplicated evaluation blocks (lower/upper bracket) could be factored; kept per source.
- Fields all `?`: this[3740], this[3397], this[3903..3905] also in TireForce/TireForceSolver/Aero — shared
  tire/aero parameter block; needs struct map.

## Claude review (dropped ST0, 2026-10-02)

Added by DeepSeek C9 per `REVIEW_11_C8.md` + `phase2/DROPPED_ST0_SCAN.md`; no existing tier is changed.

- All five `sub_5895A2` (`_frnd`) call sites (0x4E8D02/0x4E8DF7/0x4E8E63/0x4E8F11/0x4E8F7D) drop the return in the
  pseudo-code (`v59 = v6` etc.); the asm stores the rounded value and indexes the tables with it.
- `this` is `veh+0xC`; the selector/table fields run veh+0x3D08 / 0x3D0C..0x3D44 (`this[3903]`, `this[3904..3918]`).
