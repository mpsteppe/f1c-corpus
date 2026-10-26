# map_RigidBodyConstraintSolve - `RigidBodyConstraintSolve` (GUESS name)

## Identity

- Address: `0x0043E4B0`; file `functions/RigidBodyConstraintSolve_0043e4b0.c`; 47 lines.
- Signature: `_DWORD *__thiscall sub_43E4B0(int this, double *a2, int a3)`.
- Callers (read-only corpus cache): `AIVehiclePathPositionTracking`.
- Callees (from `offsets_RigidBodyConstraintSolve.csv` CALL rows): none (CSV has only CALL rows of other forms or none).
- This is a terse phase-3 triage map; the name is a GUESS until reviewed.

## Inputs

| hex | dec | type | line | expr |
|---|---|---|---|---|
| 0x15F0 | 5616 | _DWORD | L23 | `v5 = *(_DWORD *)(this + 5616);` |
| 0x15FC | 5628 | double | L24 | `v6 = v12 * *(double *)(this + 5628) + v13 * *(double *)(this + 5636) +` |
| 0x1604 | 5636 | double | L24 | `v6 = v12 * *(double *)(this + 5628) + v13 * *(double *)(this + 5636) +` |
| 0x160C | 5644 | double | L24 | `v6 = v12 * *(double *)(this + 5628) + v13 * *(double *)(this + 5636) +` |
| 0x15FC | 5628 | double | L25 | `v7 = v15 * *(double *)(this + 5628) + v16 * *(double *)(this + 5636) +` |
| 0x1604 | 5636 | double | L25 | `v7 = v15 * *(double *)(this + 5628) + v16 * *(double *)(this + 5636) +` |
| 0x160C | 5644 | double | L25 | `v7 = v15 * *(double *)(this + 5628) + v16 * *(double *)(this + 5636) +` |
| 0x15FC | 5628 | double | L26 | `v11 = v18 * *(double *)(this + 5628) + v19 * *(double *)(this + 5636) ` |
| 0x1604 | 5636 | double | L26 | `v11 = v18 * *(double *)(this + 5628) + v19 * *(double *)(this + 5636) ` |
| 0x160C | 5644 | double | L26 | `v11 = v18 * *(double *)(this + 5628) + v19 * *(double *)(this + 5636) ` |
| 0x8 | 8 | double | L28 | `v10[1] = a2[1] - v7;` |
| 0x10 | 16 | double | L29 | `v10[2] = a2[2] - v11;` |

## Outputs

| hex | dec | type | line | expr |
|---|---|---|---|---|
| 0xB4 | 180 | _DWORD | L31 | `*(_DWORD *)(this + 180) = 0;` |
| 0x4 | 4 | _DWORD | L39 | `result[1] = -1048577;` |

## Constants

Every numeric literal except 0/1 in the quoted source lines below.

## Logic

```
       v4 = FPUControlWordMaskExtract(512);   [L21]
       EulerAnglesTo33RotationMatrix(a3);   [L22]
       v5 = *(_DWORD *)(this + 5616);   [L23]
       v6 = v12 * *(double *)(this + 5628) + v13 * *(double *)(this + 5636) + v14 * *(double *)(this + 5644);   [L24]
       v7 = v15 * *(double *)(this + 5628) + v16 * *(double *)(this + 5636) + v17 * *(double *)(this + 5644);   [L25]
       v11 = v18 * *(double *)(this + 5628) + v19 * *(double *)(this + 5636) + v20 * *(double *)(this + 5644);   [L26]
       v10[0] = *a2 - v6;   [L27]
       v10[1] = a2[1] - v7;   [L28]
       v10[2] = a2[2] - v11;   [L29]
       sub_56F100(v5, v10, a3, 0);   [L30]
       *(_DWORD *)(this + 180) = 0;   [L31]
       result = (_DWORD *)(this + 936);   [L32]
         *(result - 8) = -1;   [L36]
         *(result - 7) = -1048577;   [L37]
         *result = -1;   [L38]
         result[1] = -1048577;   [L39]
```

## Meaning (GUESS)

- GUESS Rigid-body constraint/wheel solve: transforms a point by the body rotation (Euler 3x3), calls sub_56F100 and resets four constraint blocks.
- GUESS AI relevance: none-low -- shared physics.

## Questions

- None for this triage map; name and meaning stay GUESS.
