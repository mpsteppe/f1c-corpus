# map_SceneBatchRenderCheck - `SceneBatchRenderCheck` (GUESS name)

## Identity

- Address: `0x0054F5C0`; file `functions/SceneBatchRenderCheck_0054f5c0.c`; 78 lines.
- Signature: `int __thiscall sub_54F5C0(int this, int a2, int a3)`.
- Callers (read-only corpus cache): `UIFocusChange`.
- Callees (from `offsets_SceneBatchRenderCheck.csv` CALL rows): none (CSV has only CALL rows of other forms or none).
- This is a terse phase-3 triage map; the name is a GUESS until reviewed.

## Inputs

| hex | dec | type | line | expr |
|---|---|---|---|---|
| 0x3C | 60 | _DWORD | L18 | `v3 = *(_DWORD *)(a2 + 60);` |
| 0x1E0 | 480 | _DWORD | L22 | `if ( dword_8C5F40 >= *(_DWORD *)(*(_DWORD *)(this + 480) + 4) )` |
| 0x204 | 516 | _DWORD | L28 | `v6 = *(_DWORD *)(a2 + 516);` |
| 0x204 | 516 | _DWORD | L31 | `sub_54B570(a2, 0, *(_DWORD *)(a2 + 516));` |
| 0x14 | 20 | _DWORD | L32 | `v7 = *(_DWORD *)(v6 + 20);` |
| 0x14 | 20 | _BYTE | L43 | `if ( (*(_BYTE *)(v6 + 20) & 0x..) != 0 )` |
| 0x204 | 516 | float * | L45 | `v8 = *(float **)(this + 516);` |
| 0xF0 | 240 | float | L46 | `v9 = v8[60];` |
| 0x3C | 60 | _DWORD | L47 | `if ( (*(_DWORD *)(a2 + 60) & 0x..) != 0 )` |
| 0xF0 | 240 | float | L49 | `v10 = v9 - *(float *)(v6 + 240);` |
| 0xEC | 236 | float | L50 | `v11 = v8[59] - *(float *)(v6 + 236);` |
| 0xE8 | 232 | float | L51 | `v12 = v8[58] - *(float *)(v6 + 232);` |
| 0xE4 | 228 | float | L55 | `v10 = v9 - *(float *)(v6 + 228);` |
| 0xEC | 236 | float | L56 | `v11 = v8[59] - *(float *)(v6 + 224);` |
| 0xE0 | 224 | float | L56 | `v11 = v8[59] - *(float *)(v6 + 224);` |
| 0xE8 | 232 | float | L57 | `v12 = v8[58] - *(float *)(v6 + 220);` |
| 0xDC | 220 | float | L57 | `v12 = v8[58] - *(float *)(v6 + 220);` |
| 0x18 | 24 | float | L60 | `v14 = *(float *)(v6 + 24) + **(float **)(this + 480);` |
| 0x1E0 | 480 | float * | L60 | `v14 = *(float *)(v6 + 24) + **(float **)(this + 480);` |
| 0x3C | 60 | _DWORD | L63 | `v15 = (*(_DWORD *)(a2 + 60) & 0x..) != 0` |

## Outputs

| hex | dec | type | line | expr |
|---|---|---|---|---|
| 0x14 | 20 | _DWORD | L35 | `*(_DWORD *)(v6 + 20) = v7 \| 0x..;` |

## Constants

Every numeric literal except 0/1 in the quoted source lines below.

## Logic

```
       v3 = *(_DWORD *)(a2 + 60);   [L18]
       if ( (v3 & 2) == 0 )   [L20]
         if ( dword_8C5F40 >= *(_DWORD *)(*(_DWORD *)(this + 480) + 4) )   [L22]
           v6 = *(_DWORD *)(a2 + 516);   [L28]
             sub_54B570(a2, 0, *(_DWORD *)(a2 + 516));   [L31]
             v8 = *(float **)(this + 516);   [L45]
             v13 = v12 * v12 + v11 * v11 + v10 * v10;   [L59]
             v14 = *(float *)(v6 + 24) + **(float **)(this + 480);   [L60]
             if ( v13 < v14 * v14 && (a3 & 1) != 0 )   [L61]
                   : CollisionContactDetection((_DWORD *)this, a2, (_DWORD *)v6, a3);   [L65]
```

## Meaning (GUESS)

- GUESS Per-view render batch check: updates scene-node matrices, does bounding-sphere tests and dispatches collision detection.
- GUESS AI relevance: none -- render.

## Questions

- None for this triage map; name and meaning stay GUESS.
