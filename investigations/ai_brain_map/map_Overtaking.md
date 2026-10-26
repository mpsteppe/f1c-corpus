# map_Overtaking — section-4 name `Overtaking`, declared `sub_42AF70`

## Identity

- Address: `0x42AF70`; file `functions/Overtaking_0042af70.c`; 67 lines.
- Signature: `int __thiscall sub_42AF70(float *this, float *a2, int a3)`.
- Callers: `AISteering` (`0x4270A0`) L1205, L1251 (`Overtaking(this, v86)`); grep `functions/` for `Overtaking(`
  -> `functions/AISteering_004270a0.c`; `inspect` agrees (caller `0x004270A0`).
- Callees (from `offsets_Overtaking.csv` CALL rows): `ReplayAIStateCheck`, `ServerSessionGateCheck` (`LODWORD` rows
  are macro artifacts, not calls).
- `this` = F1CVehicle; `a2` = other vehicle; `a3` = caller mode (`v86` from AISteering, values 1/2/7/8).
- Prior art: `S1-ai-interaction-target-not-overtake` (0x45FC interaction target and 0x4420 lateral written here and
  in OpponentProximityScanTeamRecognition; a target does NOT mean an overtake).
- Field names below marked "(inspect)" come from the navigation-only inspect view, not from a tier review.

## Inputs

| hex | dec | type | first line read | name |
|---|---|---|---|---|
| 0x450C | 17676 | float | L13 (`this[4419]`) | maxSharedSpeed (inspect) |
| 0x409C | 16540 | float | L25 (`this[4135]`) | bestLap (inspect) |
| 0x403C | 16444 | _DWORD | L32 (`*((_DWORD *)this + 4111)`) | lapNumber (inspect) |
| 0x45F8 | 17912 | float* | L41 (`*((float **)this + 4478)`) | currentOvertakeTarget (inspect) |
| 0x3D6C | 15724 | _DWORD | L56 (`*((_DWORD *)this + 3931)`) | carConditions (inspect) |
| 0x3984 | 14724 | float | L56 (`this[3681]`) | fuelRateFactor (inspect) |
| 0x48A8 | 18600 | _DWORD | L45 (`*(_DWORD *)(*(_DWORD *)this + 18600)`) | ? position/score field |

Other-vehicle inputs (base `a2`):

| hex | dec | type | first line read | name |
|---|---|---|---|---|
| 0x44C4 | 17604 | float | L13 (`a2[4401]`) | ? shared speed field |
| 0x409C | 16540 | float | L25 (`a2[4135]`) | bestLap (inspect) |
| 0x403C | 16444 | _DWORD | L33 (`*(_DWORD *)(*(_DWORD *)a2 + 16444)`) | lapNumber (inspect) |

Also read via `v7 = *a2` / `v9 = *this`: `*(LODWORD(v7) + 18600)` L45 (same 18600 field on the other car).

## Outputs

| hex | dec | type | first line written | name |
|---|---|---|---|---|
| 0x450C | 17676 | float | L17 | maxSharedSpeed (inspect) |
| 0x45FC | 17916 | _DWORD | L58 | interaction target (prior art) |
| 0x4420 | 17440 | float | L61, L64 | overtakeSpeedOffset / lateral bias (inspect, prior art) |

## Constants

Grouped by value; every numeric literal except 0/1 in `functions/Overtaking_0042af70.c`.

| value | lines | note |
|---|---|---|
| 7, 5 | L18, L20 | SessionType (`dword_7C56A4`) compares |
| 3 | L45 | lap-count advantage threshold (`v8 > 3`) |
| 3.0 | L61 | lateral bias for `a3 == 2` |
| -3.0 | L64 | lateral bias otherwise |
| 0.001 | L56 | fuelRateFactor activity floor |
| 4401, 4135, 4111, 4478, 4479, 3931, 3681, 4360 | L13-L64 | field indices |
| 3284, 3348, 3352, 3416, 18600 | L45-L51 | sub-object condition fields |
| 16444 | L33 | other-car lap number |

## Logic

NOTE: source uses scaled `this[N]`/`a2[N]` and `*((TYPE *)this + N)` indexing. The Logic keeps the source-literal
index; byte offsets are in the tables above. No hex tokens are used on scaled lines.

```
v4 = 0                                                             [L10]
if (ReplayAIStateCheck(this + 3)) return 0                         [L11,L12]
v6 = max(a2[4401], this[4419]); this[4419] = v6                    [L13,L14,L15,L16,L17]
if (SessionType != 7) {                                            [L18]
    if (SessionType == 5) {                                        [L20]
        if (ServerSessionGateCheck(this) || !ServerSessionGateCheck(a2)) return v4   [L22,L23]
    }
    else if (a2[4135] >= this[4135]) return v4                     [L25,L26,L27]
    goto LABEL_26                                                  [L29]
}
v7 = *a2; v8 = *((_DWORD *)this + 4111)                            [L31,L32]
if (*(_DWORD *)(*(_DWORD *)a2 + 16444) > v8)                       [L33]
LABEL_26/LABEL_27: v10 = a3; v4 = v10; goto LABEL_28               [L35,L36,L37,L38,L39]
if (*((float **)this + 4478) != a2) return v4                      [L41,L42]
v9 = *this; v10 = a3                                               [L43,L44]
if (*(_DWORD *)(*(_DWORD *)this + 18600) > *(_DWORD *)(LODWORD(v7) + 18600) && v8 > 3) v4 = a3   [L45,L46]
if ((v9 flags: [3284] && ![3348] || [3352] && ![3416])             [L47,L48]
    && (v7 flags: ![3284] || [3348]) && [3352] && ![3416])         [L49,L50,L51]
    goto LABEL_27                                                  [L53]
LABEL_28:
if (v4 && *((_DWORD *)this + 3931) != 2 && this[3681] > 0.001) {   [L56]
    *((_DWORD *)this + 4479) = a2                                  [L58]
    if (v10 == 2) { this[4360] = 3.0; return v4 }                  [L59,L61,L62]
    this[4360] = -3.0                                              [L64]
}
return v4                                                          [L66]
```

## Meaning (GUESS)

- GUESS Returns a pass/attempt decision `v4` for target `a2`; when accepted and `carConditions != 2` and
  `fuelRateFactor > 0.001`, records the interaction target at 0x45FC and writes a lateral bias of +3.0 (a3==2) or
  -3.0 (otherwise) at 0x4420 [L56-L64].
- GUESS 0x450C keeps the maximum of the two cars' 0x44C4 values (a shared-speed memory used by the caller) [L13-L17].
- GUESS Session gates: replay blocks everything; SessionType 5 requires both cars to pass ServerSessionGateCheck;
  SessionType 7 is a special branch using lap counts at sub-object 18600 and `v8 > 3`; other types reject when
  `a2[4135] >= this[4135]` [L11-L28].
- GUESS The 0x45F8 pointer must equal `a2` for the deeper lap/lap-distance checks; 3284/3348/3352/3416 form a
  two-car eligibility condition on `*this` and `*a2` sub-objects [L41-L53].
- GUESS `a3` is the AISteering mode that requested the pass (1/2/7/8); compare AISteering L1205 (modes 2/7) and
  L1251 (modes 1/8) [callers].

## Questions

- `v7 = *a2` and `v9 = *this` are first-dword pointers to sub-objects (car state?); the 3284/3348/3352/3416 fields
  need names.
- What is 0x44C4 in both cars (same offset read by AIRacingLine as a smoothing constant selector)?
- Is 0x4420 a lateral speed offset or a direction selector (+3/-3)?
- `LODWORD(v7)` is a decompiler artifact (float local reinterpreted as pointer); confirm the field is a pointer.
