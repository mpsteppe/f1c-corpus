# map_SpatialTreeNearestNeighborSearch — declared `sub_403AA0`

## Identity

- Address: `0x403AA0`; file `functions/SpatialTreeNearestNeighborSearch_00403aa0.c`; 102 lines.
- Signature: `int __thiscall sub_403AA0(_DWORD *this, float *a2, int a3, int a4, char a5)`.
- Callers (grep `functions/` for `SpatialTreeNearestNeighborSearch(`): `AIDelegateCall` (`0x42ADD0`) L3;
  `AIDriverStructInit` (`0x424790`) L120; `AIRacingLine` (`0x425920`) L60; `AISteering` (`0x4270A0`)
  L309; `sub_426430` (`0x426430`) L113.
- Callees (from `offsets_SpatialTreeNearestNeighborSearch.csv` CALL rows):
  `SpatialNearestNeighborQueryWithPlaneTest` (`0x4038E0`) at L31, L62, L83, L95, L100.
- `this` = spatial container (same layout as `SpatialNearestNeighborQueryWithPlaneTest`); `a2` = query
  point; `a3` = entry node pointer; `a4` = node id filter; `a5` = enable final plane test.

## Inputs

| hex | dec | type | first line read | name |
|---|---|---|---|---|
| 0x12C | 300 | _DWORD | L32 (`a3 + 300`) | ? node id/type (compared with a4) |
| 0x114 | 276 | _DWORD | L34 (`a3 + 276`) | ? alternative entry node pointer |
| 0x10C | 268 | _DWORD | L44 (`v5 + 268`) | ? first linked node pointer (descend chain) |
| 0x94 | 148 | float | L45 (`v5 + 148`) | node position X |
| 0x4 | 4 | float | L46 (`a2[1]`) | query point Y |
| 0x98 | 152 | float | L46 (`v5 + 152`) | node position Y |
| 0x8 | 8 | float | L47 (`a2[2]`) | query point Z |
| 0x9C | 156 | float | L47 (`v5 + 156`) | node position Z |
| 0x110 | 272 | _DWORD | L68 (`v6 + 272`) | ? second linked node pointer (walk chain) |
| 0xAC | 172 | float | L96 (`v5 + 172`) | ? plane term B |
| 0xA4 | 164 | float | L96 (`v5 + 164`) | ? plane term A |

Query X is read as `*a2` (no offset row in the CSV). The +300/+276/+268/+272 fields are read on several
different node pointers (a3, v9, v10, v21, v5); the table lists the first line of each offset.

## Outputs

None (returns a node pointer).

## Constants

| value | lines | note |
|---|---|---|
| 300 | L32, L37, L56 | node id/type offset |
| 276 | L34, L39 | alternative entry offset |
| 268 | L44, L60 | first link offset |
| 272 | L68, L81, L97 | second link offset |
| 148, 152, 156 | L45-L47, L51-L53, L63-L65, L71-L73, L84-L86 | position offsets |
| 164, 172 | L96 | plane terms |
| 0.0 | L96 | plane-test compare |

## Logic

```
v5 = a3; v6 = a3                                                           [L28,L29]
if (!a3) return SpatialNearestNeighborQueryWithPlaneTest(this, a2, a4)     [L30,L31]
if (*(_DWORD *)(a3 + 0x12C) != a4) {                                       [L32]
    v9 = *(_DWORD *)(a3 + 0x114)                                           [L34]
    if (v9) {                                                              [L35]
        if (*(_DWORD *)(v9 + 0x12C) == a4) {                               [L37]
            v5 = *(_DWORD *)(a3 + 0x114); v6 = v5                          [L39,L40]
        }
    }
}
v10 = *(_DWORD *)(v5 + 0x10C)                                              [L44]
v11 = *a2 - *(float *)(v5 + 0x94)                                          [L45]
v12 = a2[1] - *(float *)(v5 + 0x98)                                        [L46]
v13 = a2[2] - *(float *)(v5 + 0x9C)                                        [L47]
v29 = v13 * v13 + v12 * v12 + v11 * v11                                    [L48]
if (v10) {                                                                 [L49]
    v14 = a2[1] - *(float *)(v10 + 0x98)                                   [L51]
    v15 = a2[2] - *(float *)(v10 + 0x9C)                                   [L52]
    v16 = *a2 - *(float *)(v10 + 0x94)                                     [L53]
    for (i = v15*v15 + v14*v14 + v16*v16; i < v29;                          [L54]
         i = v19*v19 + v18*v18 + v20*v20) {                                [L54]
        if (a4 != *(_DWORD *)(v10 + 0x12C)) break                          [L56,L57]
        v5 = v10; v29 = i                                                  [L58,L59]
        v10 = *(_DWORD *)(v10 + 0x10C)                                     [L60]
        if (!v10) return SpatialNearestNeighborQueryWithPlaneTest(this, a2, a4)   [L61,L62]
        v18 = a2[1] - *(float *)(v10 + 0x98)                               [L63]
        v19 = a2[2] - *(float *)(v10 + 0x9C)                               [L64]
        v20 = *a2 - *(float *)(v10 + 0x94)                                 [L65]
    }
}
v21 = *(_DWORD *)(v6 + 0x110)                                              [L68]
if (v21) {                                                                 [L69]
    v22 = a2[1] - *(float *)(v21 + 0x98)                                   [L71]
    v23 = a2[2] - *(float *)(v21 + 0x9C)                                   [L72]
    v24 = *a2 - *(float *)(v21 + 0x94)                                     [L73]
    v25 = v23 * v23 + v22 * v22 + v24 * v24                                [L74]
    if (v25 < v29) {                                                       [L75]
        do {
            v5 = v21; v30 = v25                                            [L79,L80]
            v21 = *(_DWORD *)(v21 + 0x110)                                 [L81]
            if (!v21) return SpatialNearestNeighborQueryWithPlaneTest(this, a2, a4)   [L82,L83]
            v26 = a2[1] - *(float *)(v21 + 0x98)                           [L84]
            v27 = a2[2] - *(float *)(v21 + 0x9C)                           [L85]
            v28 = *a2 - *(float *)(v21 + 0x94)                             [L86]
            v25 = v27 * v27 + v26 * v26 + v28 * v28                        [L87]
        } while (v25 < v30)                                                [L89]
    }
}
if (a5) {                                                                  [L92]
    if (!v5) return SpatialNearestNeighborQueryWithPlaneTest(this, a2, a4) [L94,L95]
    if (*(float *)(v5 + 0xAC) * (*(float *)(v5 + 0x9C) - a2[2])           [L96]
        + *(float *)(v5 + 0xA4) * (*(float *)(v5 + 0x94) - *a2) < 0.0)     [L96]
        v5 = *(_DWORD *)(v5 + 0x110)                                       [L97]
}
if (!v5) return SpatialNearestNeighborQueryWithPlaneTest(this, a2, a4)     [L99,L100]
return v5                                                                  [L101]
```

## Meaning (GUESS)

- GUESS Tree/list walk for the nearest node: start from entry `a3`; if `a3`'s id (+0x12C) does not match
  the filter `a4`, try the alternative pointer at `a3 + 0x114` and use it as both start and root when its
  id matches [L32-L43].
- GUESS It then measures the distance from the query `a2` to `v5`, and walks the +0x10C chain while the
  chain distance shrinks and node ids match `a4`, falling back to the linear scan
  `SpatialNearestNeighborQueryWithPlaneTest` whenever the chain ends [L44-L66].
- GUESS It next walks the +0x110 chain from `v6`, looking for an even closer node, again falling back to
  the linear scan at chain end [L68-L90].
- GUESS With `a5` set, if the winner's plane test (terms +0xAC/+0xA4 against node/query deltas) is
  negative, it steps to the winner's +0x110 neighbour; the final fallback covers a null winner
  [L92-L100].
- GUESS Caller context: waypoint locator `sub_426430`, AIRacingLine and AISteering look up the current
  racing-line node near a vehicle position [callers; doc 54 step 2].
- GUESS The +0x10C and +0x110 chains are two sibling/child links of an implicit spatial tree stored as
  linked lists inside the flat node array [L44,L68].

## Questions

- What are the +0x10C and +0x110 chains (previous/next along track, or child/alternative)? Which one is
  the descending branch?
- What is the +0x114 pointer (alternate root) and why is it swapped into both v5 and v6?
- Does the final plane test with `a5` belong to the same plane logic as
  `SpatialNearestNeighborQueryWithPlaneTest` (+0xA4/+0xAC terms)?
- The `for` loop condition is `i < v29` with update `i = v19*v19 + v18*v18 + v20*v20`; if the initial `i`
  is not smaller, the +0x10C walk is skipped — is that intended pruning?
- Node id +0x12C is compared with `a4` (same field as the companion scan); what values does it take
  (team/slot/type)?
- unmatched_ list is empty: no offset-like lines were dropped by the extractor.
