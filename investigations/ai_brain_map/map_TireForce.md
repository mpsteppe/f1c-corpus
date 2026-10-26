# map_TireForce — section-4 name `TireForce`, declared `sub_4E9100`

## Identity

- Address: `0x4E9100`; file `functions/TireForce_004e9100.c`; 112 lines.
- Signature: `double __thiscall sub_4E9100(float *this, float a2, float a3, float *a4, float a5)`.
- Callers: `PhysicsNodePropagationWithDistanceFalloff` (`0x401C90`), `AIRacingLine` (`0x425920`);
  grep `functions/` for `TireForce(` -> `functions/AIRacingLine_00425920.c` L263,
  `functions/PhysicsNodePropagationWithDistanceFalloff_00401c90.c`; `inspect` agrees.
- Callees (from `offsets_TireForce.csv` CALL rows): `sub_5895A2` (raw name), `sqrt`.
- `this` is a `float *` vehicle parameter; all field accesses are `this[N]` (element size 4).
  Source prints the scaled array index, so the byte offsets below are `N * 4`.

## Inputs

| hex | dec | type | first line read | name |
|---|---|---|---|---|
| 0x3514 | 13588 | float | L33 (this[3397]) | ? |
| 0x3518 | 13592 | float | L102 (this[3398]) | ? |
| 0x3A70 | 14960 | float | L33 (this[3740]) | ? |
| 0x3BFC | 15356 | float | L88 (this[3839]) | ? |
| 0x3C00 | 15360 | float | L101 (this[3840]) | ? lookup table base |
| 0x3C04 | 15364 | float | L102 (this[3841]) | ? lookup table next row |
| 0x3C3C | 15420 | float | L38 (this[3855]) | ? table selector |
| 0x3C40 | 15424 | float | L46 (this[3856]) | ? table base (pos) |
| 0x3C44 | 15428 | float | L55 (this[3857]) | ? table next row |
| 0x3C7C | 15484 | float | L59 (this[3871]) | ? table selector (neg) |
| 0x3C80 | 15488 | float | L67 (this[3872]) | ? table base (neg) |
| 0x3C84 | 15492 | float | L76 (this[3873]) | ? table next row (neg) |
| 0x3D3C | 15676 | float | L109 (this[3919]) | ? output cap |
| 0x3D44 | 15684 | float | L111 (this[3921]) | ? final-term coefficient |

## Outputs

None. The function returns a `double`; no `this` field is written.

## Constants

Grouped by value; every numeric literal except 0/1 in `functions/TireForce_004e9100.c`.

| value | lines | note |
|---|---|---|
| 2 | L111 | `a4[2]` index |
| 13 | L51, L52, L72, L73, L98, L99 | table index clamp |
| 14 | L49, L70, L96 | table size |
| 3397 | L33, L34 | `this[3397]` |
| 3398 | L102, L106 | `this[3398]` |
| 3740 | L33 | `this[3740]` |
| 3839 | L88 | `this[3839]` |
| 3840, 3841 | L101, L102, L106 | lookup table |
| 3855 | L38 | table selector |
| 3856, 3857 | L46, L54, L55 | lookup table |
| 3871 | L59 | table selector |
| 3872, 3873 | L67, L75, L76 | lookup table |
| 3919 | L109, L110 | cap |
| 3921 | L111 | coefficient |
| 0.0 | L81, L83 | comparisons |

## Logic

NOTE: source uses scaled `this[N]` indexing (Hex-Rays prints element index for `float *this`). The Logic keeps the
source-literal index; the byte offsets are in the tables above. `verify_maps.py` checks hex tokens against the
decimal printed in the cited line, so no hex is used on these scaled lines.

```
v5 = a2 * a2; v27 = v5                                          [L31,L32]
v28 = v5*this[3740] - (v27*a3 + a4[1])*this[3397]               [L33]
v25 = |v27*a5 - *a4| * this[3397]                               [L34]
if (flags v10 | v11)                                            [L36]
    v12 = v28 * this[3855]; sub_5895A2(v12)                     [L38,L40]
    v31 = v12; v13 = (int)v31                                   [L41,L42]
    if (v13 < 0) { v14 = this[3856]; goto AFTER }               [L44,L46,L47]
    if (v13 >= 14) v13 = 13                                     [L49,L51]
    v15 = this[v13 + 3856]; v16 = this[v13 + 3857]              [L54,L55]
else
    v17 = v28 * this[3871]; sub_5895A2(v17)                     [L59,L61]
    v33 = v17; v18 = (int)v33                                   [L62,L63]
    if (v18 < 0) { v14 = this[3872]; goto AFTER }               [L65,L67,L68]
    if (v18 >= 14) v18 = 13                                     [L70,L72]
    v15 = this[v18 + 3872]; v16 = this[v18 + 3873]              [L75,L76]
v14 = v15 + (v16 - v15) * (v35 - v32)                           [L78]
AFTER:
v19 = v14*v14 - v25*v25                                         [L80]
if (v19 <= 0.0) { v22 = 0.0 }                                   [L81,L83]
else
    v26 = sqrt(v19) / v14                                       [L87]
    v20 = v28 * this[3839]; v34 = v20; sub_5895A2(v20)          [L88,L89,L90]
    v29 = v20; v21 = (int)v29                                   [L91,L92]
    if (v21 >= 0)                                               [L94]
        if (v21 >= 14) v21 = 13                                 [L96,L98]
        v23 = this[v21 + 3840]                                  [L101]
        v22 = (v23 + (this[v21+3841]-v23)*(v34-v30)) * this[3398] * v26   [L102]
    else
        v22 = this[3840] * this[3398] * v26                     [L106]
if (v22 > this[3919]) v22 = this[3919]                          [L109,L110]
return v22 + this[3921]*this[3398]*v27 + a4[2]                  [L111]
```

## Meaning (GUESS)

- GUESS Computes one tire's force from slip inputs (a2 speed-ish, a3, a4 slip vector, a5) using a friction-circle
  expression `v14^2 - v25^2` and a lookup over `this[3839]/this[3840..]` [L80-L110].
- GUESS `v14` is an interpolated table value chosen by sign-flag branch: positive/negative tables at
  this[3856..]/this[3872..], index clamped to 13 entries, linear interpolation between adjacent entries [L36-L78].
- GUESS `this[3397]` and `this[3398]` are unit/scale conversion factors applied to the force terms [L33,L34,L102].
- GUESS `this[3919]` caps the friction-force component; `this[3921]*this[3398]*v27` adds a speed-squared term
  and `a4[2]` a per-call base term [L109-L111].
- GUESS `sub_5895A2` is a rounding/truncation helper used before `(int)` casts (called on each table input) [L40,L61,L90].
- GUESS Table fields (this[3740], this[3839], this[3855], this[3871], this[3903]-style) are per-car tire model
  parameters; the two selector tables suggest positive/negative force asymmetry [L38,L59].

## Questions

- `sub_5895A2` raw name unknown; return unused in every call site.
- `a4` is a `float *` input array; `a4[1]`, `a4[2]` semantics unknown; `a2/a3/a5` semantics unknown.
- `v10 | v11` are uninitialized-looking flag bytes (`unsigned __int8 // c0/c2`); decompiler artifacts of a
  comparison that Hex-Rays lost; exact condition unknown (asked in review too).
- No `this` writes: function is pure given car parameter tables; confirm with callers.
- Field names all `?`: needs mapping to the tire-model struct.

## Claude review (dropped ST0, 2026-10-02)

Added by DeepSeek C9 per `REVIEW_11_C8.md` + `phase2/DROPPED_ST0_SCAN.md`; no existing tier is changed.

- The three `sub_5895A2` (`_frnd`, 0x5895A2) calls at 0x4E916B/0x4E91BE/0x4E924D drop their returns in the pseudo-code
  (`v31 = v12` etc.); the asm stores the rounded value (`fstp [esp+0x24]`) and uses it for the table index. The index is
  `(int)frnd(value)`, not `(int)value`; the Questions bullet "return unused in every call site" is disproved.
- `this` is `veh+0xC`: vehicle offsets are `N*4 + 0xC` (this[3397] -> veh+0x3520, this[3855] -> veh+0x3C48,
  this[3919] -> veh+0x3D48, ...).
- The `v10|v11` flags at L36 are the x87 comparison of `v25` against 0.0 (`fcomp [0x59e440]`; `test ah,5; jp`), not
  uninitialized bytes; the normal (`v25 >= 0`) path uses the 0x3C7C selector / 0x3C80 table.
- Python model: `phase2/analysis/tireforce.py`; its table inputs are listed in `phase2/RECORDER_REQUESTS.md` A5.
