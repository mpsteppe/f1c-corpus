# map_FindNearestVehicle — `sub_4A4710` (`FindNearestVehicle`)

## Identity

- Address: `0x4A4710`; file `functions/FindNearestVehicle_004a4710.c`; 48 lines.
- Signature: `int __thiscall sub_4A4710(_BYTE *this, int a2)`.
- Callers (grep `functions/` for `FindNearestVehicle(`): `OpponentProximityScanTeamRecognition` (`0x42A7D0`)
  L59: `v5 = (_DWORD *)FindNearestVehicle(*((_DWORD *)this + 1));`.
- Callees (from `offsets_FindNearestVehicle.csv` CALL rows): `AIDelegateCall` L25; `SpeedDeltaComputation`
  L26, L35.
- Signature/call mismatch: the callee declares `(this, a2)` but the only caller passes a single argument;
  `a2` selects the `this[4*a2]` element tested at L16 and used at L26/L35. See Questions.

## Inputs

| hex | dec | type | first line read | name |
|---|---|---|---|---|
| dynamic `4*a2` | — | _DWORD | L16, L26, L35 | ? `this[4*a2]` candidate vehicle pointer |
| dynamic (element of `this`) | — | _DWORD | L22 | ? `*(int *)((char *)v4 + v5)` candidate in the `this`-relative vehicle array |
| dynamic (element of `dword_7C54F0`) | — | int * | L33, L35, L39 | ? `*v4` global vehicle pointer array element |

`offsets_FindNearestVehicle.csv` contains only call rows and zero-row dynamic accesses, so the table above
carries the forms verbatim. Two offset-like lines with literals were **not** extracted (the unmatched file
is empty):
`*(_DWORD *)(*v4 + 13000)` (L33) and `*(_DWORD *)(*v4 + 15016)` (L35).

## Outputs

None. The function returns a vehicle pointer (`int`); it does not write a field.

## Constants

Grouped by value; every numeric literal except 0/1 in `functions/FindNearestVehicle_004a4710.c`.

| value | lines | note |
|---|---|---|
| 4 | L16, L26, L35 | `a2` element scale |
| 99999.0 | L14 | initial best distance |
| 13000 | L33 | offset on `*v4` (0x32C8; pass/state gate, cf. AIAbility header) |
| 15016 | L35 | offset on `*v4` (0x3AA8) |
| 0.0 | L27, L36 | lower bound for a valid delta |

## Logic

NOTE: variable offsets are shown in source form; literal offsets that the CSV did not extract are kept as
source decimals (no hex tokens).

```
result = 0; v10 = 99999.0; v11 = 0                                  [L13,L14,L15]
if (*(_DWORD *)&this[4 * a2] == 0) return result                    [L16,L46,L47]
v4 = dword_7C54F0; v5 = this - (_BYTE *)dword_7C54F0                [L18,L19]
do {                                                                [L20]
  v6 = *(int *)((char *)v4 + v5)                                    [L22]
  if (v6) {                                                         [L23]
    v7 = AIDelegateCall(v6)                                         [L25]
    v8 = SpeedDeltaComputation((_DWORD *)*(_DWORD *)&this[4 * a2], v7)   [L26]
    if (v8 < v10 && v8 > 0.0) { v10 = v8; v11 = *(int *)((char *)v4 + v5); }   [L27,L28,L29,L30,L31]
  } else if (*(_DWORD *)(*v4 + 13000) != 1) {                       [L33]
    v9 = SpeedDeltaComputation((_DWORD *)*(_DWORD *)&this[4 * a2], *(_DWORD *)(*v4 + 15016))  [L35]
    if (v9 < v10 && v9 > 0.0) { v10 = v9; v11 = *v4; }              [L36,L37,L38,L39,L40]
  }                                                                 [L32,L41]
  ++v4                                                              [L42]
} while ((int)v4 < (int)&byte_7C5690)                               [L43,L44]
return v11                                                          [L45]
```

## Meaning (GUESS)

- GUESS Scans the global vehicle pointer array `dword_7C54F0` up to `&byte_7C5690`
  (`VehiclePtrArray`, doc 12) and returns the vehicle with the smallest positive
  `SpeedDeltaComputation` result against the subject `this[4*a2]` [L18-L45].
- GUESS For vehicles whose `this`-relative slot is null (`v6 == 0`), it uses the global `*v4` directly and
  skips entries whose `*v4 + 13000` (0x32C8) equals 1 [L22,L33-L40].
- GUESS `AIDelegateCall(v6)` resolves a per-vehicle AI delegate/handle before the speed-delta comparison
  [L25].
- GUESS `SpeedDeltaComputation(subject, candidate)` is a signed gap along track; `> 0.0` keeps only
  candidates ahead of the subject, and the minimum positive gap is the "nearest vehicle ahead"
  [L26-L40].
- GUESS `99999.0` initialises the running minimum; if nothing qualifies, the function returns 0 (none)
  [L14,L13].
- GUESS The `this - dword_7C54F0` pointer-difference trick pairs the subject's own vehicle array with the
  global array at the same index (the array at `this` mirrors `dword_7C54F0`) [L19,L22].
- GUESS Caller `OpponentProximityScanTeamRecognition` uses the result as an already-known nearest vehicle
  (stores `*v5` into `*((_DWORD *)this + 4189)` at L63) [caller].

## Questions

- Signature mismatch: the only caller passes one argument. Which parameter receives it — `this` (ecx) or
  `a2` (stack)? If `a2` is uninitialised at the call site, the `this[4*a2]` indexing is suspect; confirm in
  the disassembly.
- The `13000` and `15016` literal offsets are real source reads but the CSV did not extract them and the
  unmatched file is empty; the extractor may not treat `*v4 + N` as a base. Confirm those struct fields
  (`0x32C8` and `0x3AA8`).
- What exactly does `SpeedDeltaComputation` return — distance gap, time gap, or speed delta? Units decide
  the `> 0.0` direction convention.
- `v6` is the `this`-relative slot while `*v4` is the global array element; why can they differ
  (one null, one non-null) for the same index?
- Does the loop update `v4` only (`++v4`) while comparing against the global array end — i.e. the
  `this`-relative array is guaranteed the same length?
