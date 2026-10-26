# map_sub_4BE760 - `sub_4BE760` (GUESS name)

## Identity

- Address: `0x004BE760`; file `functions/sub_4BE760_004be760.c`; 91 lines.
- Signature: `void __thiscall sub_4BE760(int this, int a2, int a3, float a4)`.
- Callers (read-only corpus cache): `AIBehaviorInitialization`.
- Callees (from `offsets_sub_4BE760.csv` CALL rows): none (CSV has only CALL rows of other forms or none).
- This is a terse phase-3 triage map; the name is a GUESS until reviewed.

## Inputs

| hex | dec | type | line | expr |
|---|---|---|---|---|
| 0x409C | 16540 | float | L30 | `if ( *(float *)(v7 + 16540) > 1.0 && *(float *)(v7 + 16540) < (double)` |
| 0x32C8 | 13000 | _DWORD | L30 | `if ( *(float *)(v7 + 16540) > 1.0 && *(float *)(v7 + 16540) < (double)` |
| 0x409C | 16540 | float | L32 | `v15 = *(float *)(v7 + 16540);` |
| 0x360 | 864 | _DWORD | L33 | `if ( *(_DWORD *)(this + 864) == 7 )` |
| 0x44C4 | 17604 | float | L34 | `v17 = *(float *)(v7 + 17604);` |
| 0x44C0 | 17600 | float | L36 | `v17 = *(float *)(v7 + 17600);` |
| 0x409C | 16540 | float | L47 | `if ( *(float *)(v9 + 16540) > 0.0` |
| 0x409C | 16540 | float | L48 | `&& *(float *)(v9 + 16540) > (double)v16` |
| 0x409C | 16540 | float | L49 | `&& v15 * 1.15 > *(float *)(v9 + 16540)` |
| 0x32C8 | 13000 | _DWORD | L50 | `&& *(_DWORD *)(v9 + 13000) == 1 )` |
| 0x409C | 16540 | float | L52 | `v16 = *(float *)(v9 + 16540);` |
| 0x360 | 864 | _DWORD | L53 | `if ( *(_DWORD *)(this + 864) == 7 )` |
| 0x44C4 | 17604 | float | L54 | `v4 = *(float *)(v9 + 17604);` |
| 0x44C0 | 17600 | float | L56 | `v4 = *(float *)(v9 + 17600);` |
| 0x34C | 844 | float | L74 | `v14 = 0.15000001 * *(float *)(this + 844);` |
| 0x34C | 844 | float | L76 | `*(float *)(this + 844) = v14 * (1.0 - a4) + *(float *)(this + 844);` |

## Outputs

| hex | dec | type | line | expr |
|---|---|---|---|---|
| 0x34C | 844 | _DWORD | L20 | `*(_DWORD *)(this + 844) = 1142292480;` |
| 0x34C | 844 | float | L70 | `*(float *)(this + 844) = sub_58850F(v13);` |
| 0x348 | 840 | float | L73 | `*(float *)(this + 840) = a4;` |
| 0x342 | 834 | _BYTE | L75 | `*(_BYTE *)(this + 834) = 1;` |
| 0x34C | 844 | float | L76 | `*(float *)(this + 844) = v14 * (1.0 - a4) + *(float *)(this + 844);` |
| 0x342 | 834 | _BYTE | L83 | `*(_BYTE *)(this + 834) = 1;` |
| 0x34C | 844 | float | L86 | `*(float *)(this + 844) = v11;` |
| 0x34C | 844 | float | L89 | `*(float *)(this + 844) = v19;` |

## Constants

Every numeric literal except 0/1 in the quoted source lines below.

## Logic

```
       *(_DWORD *)(this + 844) = 1142292480;   [L20]
         if ( *(float *)(v7 + 16540) > 1.0 && *(float *)(v7 + 16540) < (double)v15 && *(_DWORD *)(v7 + 13000) == 1 )   [L30]
           v15 = *(float *)(v7 + 16540);   [L32]
             v17 = *(float *)(v7 + 17600);   [L36]
       if ( v15 >= 9000.0 )   [L41]
         if ( *(float *)(v9 + 16540) > 0.0   [L47]
           && v15 * 1.15 > *(float *)(v9 + 16540)   [L49]
             v4 = *(float *)(v9 + 17604);   [L54]
       if ( v16 <= 1.0 || v15 == v16 )   [L61]
             *(float *)(this + 844) = sub_58850F(v13);   [L70]
         *(float *)(this + 840) = a4;   [L73]
         v14 = 0.15000001 * *(float *)(this + 844);   [L74]
         *(float *)(this + 844) = v14 * (1.0 - a4) + *(float *)(this + 844);   [L76]
         v10 = v17 - v4;   [L80]
           v10 = 0.0099999998;   [L82]
         v11 = v15 - v18 / v10 * (1.0 - v17);   [L85]
         *(float *)(this + 844) = v11;   [L86]
         v19 = v15 * 0.97000003;   [L87]
         if ( v11 < v19 )   [L88]
           *(float *)(this + 844) = v19;   [L89]
```

## Meaning (GUESS)

- GUESS AI behaviour pace computation: scans the field for the slowest (field +16540) and fastest-within-1.15x driver entry with the qualifying flag (+13000 == 1), then computes the pace value at this+844 (0.97x floor, interpolated toward the slower car) or falls back to a season table lookup when no suitable pair exists.
- GUESS AI relevance: high -- called by AIBehaviorInitialization; looks like the per-session AI speed anchor / soft rubber-band term.
- GUESS fields +13000, +16540, +844 and the season-table fallback are unverified; this+844 holds a speed-like float.

## Questions

- None for this triage map; name and meaning stay GUESS.
