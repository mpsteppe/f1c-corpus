# map_AIDriverSorting - `AIDriverSorting` (GUESS name)

## Identity

- Address: `0x004BF390`; file `functions/AIDriverSorting_004bf390.c`; 80 lines.
- Signature: `int __stdcall sub_4BF390(int a1)`.
- Callers (read-only corpus cache): `AIBehaviorInitialization`, `AITickUpdate`, `EngineFailureCheck`.
- Callees (from `offsets_AIDriverSorting.csv` CALL rows): none (CSV has only CALL rows of other forms or none).
- This is a terse phase-3 triage map; the name is a GUESS until reviewed.

## Inputs

| hex | dec | type | line | expr |
|---|---|---|---|---|
| 0x4060 | 16480 | _DWORD | L21 | `v12 = *(_DWORD *)(a1 + 16480);` |
| 0x4060 | 16480 | _DWORD | L38 | `v7 = *(_DWORD *)(v6 + 16480);` |
| 0x403C | 16444 | _DWORD | L47 | `v8 = *(_DWORD *)(v6 + 16444);` |
| 0x403C | 16444 | _DWORD | L48 | `v9 = *(_DWORD *)(a1 + 16444);` |
| 0x4098 | 16536 | float | L49 | `if ( v8 >= v9 && (v8 != v9 \|\| *(float *)(a1 + 16536) >= (double)*(fl` |
| 0x409C | 16540 | float | L52 | `else if ( *(float *)(a1 + 16540) >= (double)*(float *)(v6 + 16540) && ` |
| 0x4060 | 16480 | _DWORD | L57 | `if ( *(_DWORD *)(a1 + 16480) - 1 == v7 )` |
| 0x4060 | 16480 | _DWORD | L61 | `ConditionalFieldSetter(v6 + 16436, *(_DWORD *)(v6 + 16480) + 1);` |
| 0x4060 | 16480 | _DWORD | L68 | `if ( v12 == *(_DWORD *)(v6 + 16480) )` |

## Outputs

None.

## Constants

Every numeric literal except 0/1 in the quoted source lines below.

## Logic

```
       result = dword_7C56A4;   [L16]
       v3 = dword_5C329C;   [L17]
       v12 = *(_DWORD *)(a1 + 16480);   [L21]
           v6 = dword_7C54F0[v5];   [L37]
           v7 = *(_DWORD *)(v6 + 16480);   [L38]
           if ( v7 == v13 )   [L39]
               if ( v11 == 7 )   [L45]
                 if ( v8 >= v9 && (v8 != v9 || *(float *)(a1 + 16536) >= (double)*(float *)(v6 + 16536)) )   [L49]
               if ( *(_DWORD *)(a1 + 16480) - 1 == v7 )   [L57]
               ConditionalFieldSetter(a1 + 16436, v7);   [L60]
               ConditionalFieldSetter(v6 + 16436, *(_DWORD *)(v6 + 16480) + 1);   [L61]
```

## Meaning (GUESS)

- GUESS Field-order updater: scans the driver array dword_7C54F0 keyed by session type dword_7C56A4, compares per-driver fields (+16444/0x403C lap, +16536/+16540, +16480/0x4060 position) and rewrites rank fields via ConditionalFieldSetter.
- GUESS AI relevance: high -- called by AIBehaviorInitialization, AITickUpdate and EngineFailureCheck; it establishes the order the AI set iterates.
- The sorting key depends on the session type (dword_7C56A4 == 7 special path); exact tie-break fields unverified.

## Questions

- None for this triage map; name and meaning stay GUESS.
