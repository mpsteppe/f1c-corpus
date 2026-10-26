# map_ShortComputation_3ca0 — declared `sub_423CA0`

## Identity

- Address: `0x423CA0`; file `functions/ShortComputation_3ca0_00423ca0.c`; 49 lines.
- Signature: `void __thiscall sub_423CA0(float *this, float a2, int a3, float a4, float a5)`.
  `a3` is never used in the body.
- Callers (grep `functions/` for `ShortComputation_3ca0(`): `AISteering` (`0x4270A0`) L326
  (`ShortComputation_3ca0(v14, this[3390], this[3391], this[3392], this[4368])`; `v14` is a per-opponent
  slot whose first dword is a vehicle pointer, `this+3390..3392` = velocity X/Y/Z 0x34F8/0x34FC/0x3500,
  `this[4368]` = Speed 0x4440).
- Callees (from `offsets_ShortComputation_3ca0.csv` CALL rows): `sqrt` (CRT; rows L32, L34, L45, L47).
- `this` = an 8-byte-slot array whose first dword points at a vehicle; `this[N]` here is a float stride on
  the slot (`this[6]` = byte 0x18, `this[4]` = byte 0x10). `v5 = veh + 13560` is the vehicle velocity
  base (X), so `v5[2]` = veh + 13568 (Z).

## Inputs

| hex | dec | type | first line read | name |
|---|---|---|---|---|
| 0x3500 | 13568 | float | L27 (`*(float *)(*(_DWORD *)this + 13568)`) | velocity Z (doc 54 / FIELD_GLOSSARY) |
| 0x34F8 | 13560 | float | L21 (`v5 = (float *)(*(_DWORD *)this + 13560)`) | velocity X (doc 54 / FIELD_GLOSSARY) |
| 0x8 | 8 | float | L40 (`v5[2]`) | scalar index on v5 -> vehicle + 13568 (same field as 0x3500) |

## Outputs

| hex | dec | type | first line written | name |
|---|---|---|---|---|
| 0x18 | 24 | float | L35 (`this[6] = v12`) | ? slot output 1 (projected speed minus a5) |
| 0x10 | 16 | float | L48 (`this[4] = v18`) | ? slot output 2 (perpendicular magnitude) |

## Constants

| value | lines | note |
|---|---|---|
| 13560, 13568 | L21, L27 | vehicle byte offsets (velocity X / Z) |
| 2 | L40 | `v5[2]` index (8 bytes beyond v5) |
| 6 | L35, L36 | `this[N]` index (byte 0x18) |
| 4 | L48 | `this[N]` index (byte 0x10) |
| 0.0 | L24, L37 | divide-by-zero guards on the squared norm |

## Logic

```
veh = *(_DWORD *)this                                                  [L21]
v5 = (float *)(veh + 0x34F8)                                           [L21]
v6 = a4 * a4 + a2 * a2                                                 [L22]
v7 = 0.0                                                               [L24,L25]
if (v6 != 0.0)
    v7 = (a4 * *(float *)(veh + 0x3500) + a2 * *(float *)(veh + 0x34F8)) / v6   [L27]
v20 = a2 * v7                                                          [L28]
v22 = a4 * v7                                                          [L29]
v9 = v22 * v22 + v20 * v20                                             [L30]
v12 = (x87 c0|c3 flag) ? -sqrt(v9) : sqrt(v9)                          [L31,L32,L33,L34]
this[6] = v12                                                          [L35]
this[6] = this[6] - a5                                                 [L36]
v13 = 0.0                                                              [L37,L38]
if (v6 != 0.0)
    v13 = (a2 * v5[2] - a4 * *v5) / v6                                 [L40]
v21 = v13 * -a4                                                        [L41]
v23 = a2 * v13                                                         [L42]
v15 = v23 * v23 + v21 * v21                                            [L43]
v18 = (x87 c0|c3 flag) ? sqrt(v15) : -sqrt(v15)                        [L44,L45,L46,L47]
this[4] = v18                                                          [L48]
```

## Meaning (GUESS)

- GUESS Decomposes a 2D velocity into components relative to the direction vector (a2, a4): `v7` is the
  projection factor `dot((vx,vz),(a2,a4)) / |(a2,a4)|^2` using the vehicle velocity at 0x34F8/0x3500
  [L21-L27].
- GUESS The projection vector `(a2*v7, a4*v7)` gives output 1: `this[6] = ±sqrt(|projection|^2) - a5`
  (a5 = caller's Speed 0x4440), i.e. projected speed minus own speed [L28-L36].
- GUESS The cross term `v13 = (a2*vz - a4*vx) / |(a2,a4)|^2` and its perpendicular vector
  `(-a4*v13, a2*v13)` give output 2: `this[4] = ±sqrt(|perp|^2)`, a lateral/closing component
  [L40-L48].
- GUESS The x87 `c0|c3` sign branches select the sign from a comparison performed by the FBSTP/FCOMP
  sequence (decompiler flags); the exact predicate is lost but both outputs take a signed magnitude
  [L31-L34, L44-L47].
- GUESS Caller context: AISteering builds relative-speed components for each opponent slot (`v14[6]`,
  `v14[4]`) used later against this car's heading/velocity [caller L326-L340].

## Questions

- What is the x87 predicate behind `if (v10 | v11)` / `if (v16 | v17)`? No comparison is visible in the
  decompile — likely a sign test after `fcom`/`fchs`; cannot be reproduced exactly from this listing.
- Why is `a3` (third argument, `this[3391]` = velocity Y) unused? Is it retained for ABI/legacy reasons?
- Are `this[6]` and `this[4]` (slot +0x18 / +0x10) read by any other function as relative speed?
- What is the physical meaning of output 1 (projected speed minus own speed) vs output 2 (perp
  magnitude)?
- unmatched_ list has one entry: `L21: v5 = (float *)(*(_DWORD *)this + 13560);` (base pointer
  expression, not a scalar offset row).
