# map_F_3x3MatrixTransform - `F_3x3MatrixTransform` (GUESS name)

## Identity

- Address: `0x004E23D0`; file `functions/F_3x3MatrixTransform_004e23d0.c`; 31 lines.
- Signature: `float *__thiscall sub_4E23D0(_DWORD *this, float *a2, _DWORD *a3, const void *a4)`.
- Callers (read-only corpus cache): `SuspensionStateUpdate`, `VehiclePhysicsTimeStep`, `VehicleTelemetryPositionAccumulator`, `sub_4F0430`.
- Callees (from `offsets_F_3x3MatrixTransform.csv` CALL rows): none (CSV has only CALL rows of other forms or none).
- This is a terse phase-3 triage map; the name is a GUESS until reviewed.

## Inputs

| hex | dec | type | line | expr |
|---|---|---|---|---|
| 0x4 | 4 | _DWORD | L14 | `v5[1] = a3[1];` |
| 0x8 | 8 | _DWORD | L15 | `v5[2] = a3[2];` |
| 0x4 | 4 | _DWORD | L19 | `this[22] = *((_DWORD *)a2 + 1);` |
| 0x8 | 8 | _DWORD | L20 | `this[23] = *((_DWORD *)a2 + 2);` |
| 0x20 | 32 | float | L22 | `v12 = v6[8] * result[18] + v6[7] * result[17] + v6[6] * result[16];` |
| 0x48 | 72 | float | L22 | `v12 = v6[8] * result[18] + v6[7] * result[17] + v6[6] * result[16];` |
| 0x1C | 28 | float | L22 | `v12 = v6[8] * result[18] + v6[7] * result[17] + v6[6] * result[16];` |
| 0x44 | 68 | float | L22 | `v12 = v6[8] * result[18] + v6[7] * result[17] + v6[6] * result[16];` |
| 0x18 | 24 | float | L22 | `v12 = v6[8] * result[18] + v6[7] * result[17] + v6[6] * result[16];` |
| 0x40 | 64 | float | L22 | `v12 = v6[8] * result[18] + v6[7] * result[17] + v6[6] * result[16];` |
| 0x8 | 8 | float | L23 | `v9 = v6[2] * result[18] + v6[1] * result[17] + result[16] * *v6 + *a2;` |
| 0x48 | 72 | float | L23 | `v9 = v6[2] * result[18] + v6[1] * result[17] + result[16] * *v6 + *a2;` |
| 0x4 | 4 | float | L23 | `v9 = v6[2] * result[18] + v6[1] * result[17] + result[16] * *v6 + *a2;` |
| 0x44 | 68 | float | L23 | `v9 = v6[2] * result[18] + v6[1] * result[17] + result[16] * *v6 + *a2;` |
| 0x40 | 64 | float | L23 | `v9 = v6[2] * result[18] + v6[1] * result[17] + result[16] * *v6 + *a2;` |
| 0x14 | 20 | float | L24 | `v10 = v6[5] * result[18] + v6[4] * result[17] + v6[3] * result[16] + a` |
| 0x48 | 72 | float | L24 | `v10 = v6[5] * result[18] + v6[4] * result[17] + v6[3] * result[16] + a` |
| 0x10 | 16 | float | L24 | `v10 = v6[5] * result[18] + v6[4] * result[17] + v6[3] * result[16] + a` |
| 0x44 | 68 | float | L24 | `v10 = v6[5] * result[18] + v6[4] * result[17] + v6[3] * result[16] + a` |
| 0xC | 12 | float | L24 | `v10 = v6[5] * result[18] + v6[4] * result[17] + v6[3] * result[16] + a` |
| 0x40 | 64 | float | L24 | `v10 = v6[5] * result[18] + v6[4] * result[17] + v6[3] * result[16] + a` |
| 0x4 | 4 | float | L24 | `v10 = v6[5] * result[18] + v6[4] * result[17] + v6[3] * result[16] + a` |
| 0x8 | 8 | float | L25 | `v8 = v12 + a2[2];` |

## Outputs

| hex | dec | type | line | expr |
|---|---|---|---|---|
| 0x4 | 4 | _DWORD | L14 | `v5[1] = a3[1];` |
| 0x8 | 8 | _DWORD | L15 | `v5[2] = a3[2];` |
| 0x54 | 84 | _DWORD | L18 | `this[21] = *(_DWORD *)a2;` |
| 0x58 | 88 | _DWORD | L19 | `this[22] = *((_DWORD *)a2 + 1);` |
| 0x5C | 92 | _DWORD | L20 | `this[23] = *((_DWORD *)a2 + 2);` |
| 0x4 | 4 | float | L27 | `result[1] = v10;` |
| 0x8 | 8 | float | L29 | `result[2] = v11;` |

## Constants

Every numeric literal except 0/1 in the quoted source lines below.

## Logic

```
       v5 = this + 5;   [L12]
       *v5 = *a3;   [L13]
       v5[1] = a3[1];   [L14]
       v5[2] = a3[2];   [L15]
       v6 = (float *)(this + 8);   [L16]
       this[21] = *(_DWORD *)a2;   [L18]
       v12 = v6[8] * result[18] + v6[7] * result[17] + v6[6] * result[16];   [L22]
       v9 = v6[2] * result[18] + v6[1] * result[17] + result[16] * *v6 + *a2;   [L23]
       v10 = v6[5] * result[18] + v6[4] * result[17] + v6[3] * result[16] + a2[1];   [L24]
       v8 = v12 + a2[2];   [L25]
       *result = v9;   [L26]
       result[1] = v10;   [L27]
       v11 = v8;   [L28]
       result[2] = v11;   [L29]
```

## Meaning (GUESS)

- GUESS Builds a 3x4 transform: copies a 3-vector and a 0x24-byte matrix at this+8, then applies the rotation/translation to a point.
- GUESS AI relevance: none-low -- shared physics/render matrix math.

## Questions

- None for this triage map; name and meaning stay GUESS.
