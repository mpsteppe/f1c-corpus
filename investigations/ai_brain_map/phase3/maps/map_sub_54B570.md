# map_sub_54B570 - `sub_54B570` (GUESS name)

## Identity

- Address: `0x0054B570`; file `functions/sub_54B570_0054b570.c`; 123 lines.
- Signature: `int __thiscall sub_54B570(int this, float *a2, int a3)`.
- Callers (read-only corpus cache): `AnimationDispatchWithSkipFlag`, `SceneBatchRenderCheck`, `SceneNodeStateUpdateWithTransform`, `UIFocusChange`, `sub_54A870`.
- Callees (from `offsets_sub_54B570.csv` CALL rows): none (CSV has only CALL rows of other forms or none).
- This is a terse phase-3 triage map; the name is a GUESS until reviewed.

## Inputs

| hex | dec | type | line | expr |
|---|---|---|---|---|
| 0x3C | 60 | _DWORD | L28 | `if ( (*(_DWORD *)(this + 60) & 0x..) != 0 )` |
| 0x3C | 60 | _DWORD | L30 | `v4 = *(_DWORD *)(this + 60);` |
| 0x34 | 52 | float | L37 | `*(float *)(this + 48) = 3.1415927 - a2[13];` |
| 0x34 | 52 | float | L41 | `*(float *)(this + 48) = 3.1415927 - a2[13];` |
| 0x30 | 48 | float | L42 | `*(float *)(this + 44) = -a2[12];` |
| 0x38 | 56 | float | L43 | `*(float *)(this + 52) = -a2[14];` |
| 0x64 | 100 | float | L48 | `v5 = *(float *)(this + 100);` |
| 0x60 | 96 | float | L49 | `v6 = *(float *)(this + 96);` |
| 0x68 | 104 | float | L51 | `EulerAngleToRotationMatrix(this + 108, v6, v5, *(float *)(this + 104))` |
| 0x54 | 84 | _DWORD | L52 | `MultiFieldSetter((_DWORD *)(this + 108), *(_DWORD *)(this + 84), *(_DW` |
| 0x58 | 88 | _DWORD | L52 | `MultiFieldSetter((_DWORD *)(this + 108), *(_DWORD *)(this + 84), *(_DW` |
| 0x5C | 92 | _DWORD | L52 | `MultiFieldSetter((_DWORD *)(this + 108), *(_DWORD *)(this + 84), *(_DW` |
| 0x3C | 60 | _BYTE | L54 | `if ( (*(_BYTE *)(this + 60) & 1) != 0 )` |
| 0x40 | 64 | _DWORD | L61 | `else if ( *(_DWORD *)(this + 64) )` |
| 0x2C | 44 | float | L75 | `v11 = sin(*(float *)(this + 44));` |
| 0x2C | 44 | float | L76 | `v12 = cos(*(float *)(this + 44));` |
| 0x30 | 48 | float | L77 | `v13 = sin(*(float *)(this + 48));` |
| 0x30 | 48 | float | L78 | `v28 = cos(*(float *)(this + 48));` |
| 0x34 | 52 | float | L79 | `v14 = sin(*(float *)(this + 52));` |
| 0x34 | 52 | float | L80 | `v15 = cos(*(float *)(this + 52));` |
| 0x20 | 32 | _DWORD | L95 | `*(_DWORD *)v10 = *(_DWORD *)(this + 32);` |
| 0x24 | 36 | _DWORD | L96 | `*((_DWORD *)v10 + 1) = *(_DWORD *)(this + 36);` |
| 0x28 | 40 | _DWORD | L97 | `*((_DWORD *)v10 + 2) = *(_DWORD *)(this + 40);` |
| 0x3C | 60 | _DWORD | L99 | `*(_DWORD *)(this + 60) \|= 0x..u;` |
| 0x14 | 20 | _DWORD | L121 | `*(_DWORD *)(a3 + 20) &= 0x..;` |

## Outputs

| hex | dec | type | line | expr |
|---|---|---|---|---|
| 0x30 | 48 | float | L37 | `*(float *)(this + 48) = 3.1415927 - a2[13];` |
| 0x30 | 48 | float | L41 | `*(float *)(this + 48) = 3.1415927 - a2[13];` |
| 0x2C | 44 | float | L42 | `*(float *)(this + 44) = -a2[12];` |
| 0x34 | 52 | float | L43 | `*(float *)(this + 52) = -a2[14];` |
| 0x3C | 60 | _DWORD | L50 | `*(_DWORD *)(this + 60) = v4 & 0x..;` |
| 0xC | 12 | _DWORD | L81 | `*((_DWORD *)v7 + 3) = 0;` |
| 0x4 | 4 | float | L85 | `*((float *)v7 + 1) = v14 * v12;` |
| 0x8 | 8 | float | L86 | `*((float *)v7 + 2) = v22 * v11 - v15 * v13;` |
| 0xC | 12 | _DWORD | L87 | `*((_DWORD *)v8 + 3) = 0;` |
| 0x4 | 4 | float | L89 | `*((float *)v8 + 1) = v15 * v12;` |
| 0x8 | 8 | float | L90 | `*((float *)v8 + 2) = v14 * v13 + v23 * v11;` |
| 0xC | 12 | _DWORD | L91 | `*((_DWORD *)v9 + 3) = 0;` |
| 0x4 | 4 | float | L93 | `*((float *)v9 + 1) = -v11;` |
| 0x8 | 8 | float | L94 | `*((float *)v9 + 2) = v28 * v12;` |
| 0x4 | 4 | _DWORD | L96 | `*((_DWORD *)v10 + 1) = *(_DWORD *)(this + 36);` |
| 0x8 | 8 | _DWORD | L97 | `*((_DWORD *)v10 + 2) = *(_DWORD *)(this + 40);` |
| 0xC | 12 | _DWORD | L98 | `*((_DWORD *)v10 + 3) = 1065353216;` |

## Constants

Every numeric literal except 0/1 in the quoted source lines below.

## Logic

```
           *(float *)(this + 48) = 3.1415927 - a2[13];   [L37]
           *(float *)(this + 48) = 3.1415927 - a2[13];   [L41]
           *(float *)(this + 44) = -a2[12];   [L42]
         EulerAngleToRotationMatrix(this + 108, v6, v5, *(float *)(this + 104));   [L51]
       v11 = sin(*(float *)(this + 44));   [L75]
       v12 = cos(*(float *)(this + 44));   [L76]
       v13 = sin(*(float *)(this + 48));   [L77]
       v23 = v15 * v28;   [L82]
       *(float *)v7 = v13 * v11 * v14 + v23;   [L84]
       *((float *)v7 + 1) = v14 * v12;   [L85]
       *((float *)v7 + 2) = v22 * v11 - v15 * v13;   [L86]
       TransformationMatrixUpdate(0);   [L100]
```

## Meaning (GUESS)

- GUESS Scene-node transform update: builds the 4x4 rotation/translation matrix from Euler angles and copies it into the node's matrix block.
- GUESS AI relevance: none -- render/physics placement.

## Questions

- None for this triage map; name and meaning stay GUESS.
