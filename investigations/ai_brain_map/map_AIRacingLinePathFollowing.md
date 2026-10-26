# map_AIRacingLinePathFollowing — section-3 name `AIRacingLinePathFollowing`, declared `sub_4E9CA0`

## Identity

- Address: `0x4E9CA0`; file `functions/AIRacingLinePathFollowing_004e9ca0.c`; 146 lines.
- Signature: `void __thiscall sub_4E9CA0(float *this)`.
- Caller: `sub_4BB8E0` (`0x4BB8E0`) L13 `AIRacingLinePathFollowing(v3 + 12)` where `v3 = *this_caller`; grep
  `functions/` -> `functions/sub_4BB8E0_004bb8e0.c` only; `inspect` agrees (callers: 1). The caller gates on
  `SessionType <= 6` and `*(v3 + 13000) <= 1`.
- Callees (from `offsets_AIRacingLinePathFollowing.csv` CALL rows): `sub_4BC340`, `sub_403640`,
  `F_3DTransformWithMatrixMultiplication`, `RenderCallWithGuard`, `CoordinateTransformWithOffset`,
  `EulerToRotationMatrix`, `SuspensionStateUpdate`, `VehicleBodyToWheelContactDistanceComputation`,
  `F_3x3MatrixTransformWithTranslation`, `BufferEntryClear`, `SceneNodeVisibilityToggle`, `UIFocusChange`.
- `this` = the object passed by the caller (`*sub_4BB8E0_this + 12`). Its kind is OPEN; it carries the same
  0x34xx pose block as a vehicle, but the caller does not prove it is one. `this[N]` byte offset = `N * 4`.
- Prior art: none specific (`evidence-query findings AIRacingLinePathFollowing` total 0).

## Inputs

| hex | dec | type | first line read | name |
|---|---|---|---|---|
| 0x3440 | 13376 | _BYTE | L73 | ? traversal mode flag (non-zero -> forward link chain) |
| 0x4040 | 16448 | _DWORD | L43 | ? target node id, via `*(_DWORD *)this + 16448` |

Node-record reads (base `v7`/`v21`, path/graph node, not `this`): `+0x44` (68, node id compared to 0x4040),
`+0x10C` (268, reverse link), `+0x110` (272, forward link), `+0x114` (276, alternate link), `+0x12C` (300, link
state; followed when `== 1`). Globals: `dword_5EA2C0` (graph manager passed to `sub_403640`), `dword_5EA3F0`
(iteration multiplier), `dword_8AD07C`/`dword_8AD080`/`dword_8AD084` (scene-node handles).

## Outputs

| hex | dec | type | first line written | name |
|---|---|---|---|---|
| 0x3A9C | 15004 | _DWORD | L41 | ? cached node pointer from `sub_403640` |
| 0x34D4 | 13524 | float | L96 | ? node pos X (`this[3381] = *v7`) |
| 0x34D8 | 13528 | float | L97 | ? node pos Y |
| 0x34DC | 13532 | float | L98 | ? node pos Z |
| 0x34E0 | 13536 | float | L88 | ? Euler X from transform (`v31[0]`) |
| 0x34E4 | 13540 | float | L89 | ? Euler Y from transform |
| 0x34E8 | 13544 | float | L90 | ? Euler Z from transform |
| 0x4094 | 16532 | _DWORD | L100 | per-iteration step flag = 1, via `*(_DWORD *)this + 16532` |

The 3x3 matrix written by `EulerToRotationMatrix(this + 3384, this + 3372)` [L91] lands at indices 3372..3380
(overlapping the node X at index 3381 per the source order).

## Constants

Grouped by value; every numeric literal except 0/1 in `functions/AIRacingLinePathFollowing_004e9ca0.c`.

| value | lines | note |
|---|---|---|
| 2 | L38, L39, L125 | iteration multiplier `2 * dword_5EA3F0`; chain state switch |
| 16436, 16448, 16532 | L32, L43, L100 | sub-object fields via `*(_DWORD *)this` |
| 17, 67, 68, 69, 75, 300 | L45-L139 | node-record field indices |
| 3381, 3382, 3383, 3384, 3385, 3386, 3372 | L88-L98 | pose indices / matrix output base |
| 13376 | L73 | mode flag byte |
| 0x8000000 (134217728) | L103, L135 | `BufferEntryClear` mask |
| 0.0, 1 | many | loop counters / flags |

## Logic

NOTE: source uses scaled `this[N]` and `*((TYPE *)base + N)` indexing. Logic keeps source-literal indices; byte
offsets are in the tables above. No hex tokens are used on scaled lines.

```
if (!sub_4BC340(*(_DWORD *)this + 16436)) return                      [L32]
F_3DTransformWithMatrixMultiplication(&v29, v31)                      [L34]
RenderCallWithGuard(*(_DWORD **)this, &v30, v32)                      [L35]
if (v3 | v4) return                                                   [L36,L144]
v5 = v25 = 2 * dword_5EA3F0                                           [L38,L39]
v6 = sub_403640(dword_5EA2C0, this + 3381, 0); this[3751] = v6; v7 = v6   [L40,L41,L42]
v8 = *(*(_DWORD *)this + 16448)                                       [L43]
while (v6[17] != v8) { v7 = v7[67]; if (++v9 > v25) return }          [L45-L56]
RenderCallWithGuard(*(_DWORD **)this, &v29, v31)                      [L57]
CoordinateTransformWithOffset(&v30, v32, &v28)                        [L58]
v11 = sub_403640(dword_5EA2C0, &v28, 0)                               [L59]
while (v14 | v15) { v11 = v11[67]; if (++v12 > v5) return }           [L61-L71]
if (*(this + 13376)) {                                                [L73]
    v21 = v7
    while (v21 != v11) {                                              [L76]
        if (!v21[75]) return                                          [L78]
        v21 = v21[68]; if (v20++ > v25) return                        [L80-L84]
    }
}
this[3384] = v31[0]; this[3385] = v31[1]; this[3386] = v31[2]         [L88-L90]
EulerToRotationMatrix(this + 3384, this + 3372)                       [L91]
v26 = 1; v27 = 0                                                      [L92,L93]
while (1) {
    this[3381] = *v7; this[3382] = v7[1]; this[3383] = v7[2]          [L96-L98]
    SuspensionStateUpdate(this); *(*(_DWORD *)this + 16532) = 1       [L99,L100]
    VehicleBodyToWheelContactDistanceComputation(this, 0)             [L101]
    F_3x3MatrixTransformWithTranslation(this)                         [L102]
    BufferEntryClear(buffer_mask)                                     [L103]
    if (dword_8AD07C) { SceneNodeVisibilityToggle(1); UIFocusChange(dword_8AD07C,1); SceneNodeVisibilityToggle(0) }   [L104-L109]
    if (dword_8AD080) { same }                                        [L110-L115]
    if (dword_8AD084) { same }                                        [L116-L121]
    if (v26 != 1) break                                               [L122,L123]
    if (v7 == v11) v26 = 2                                            [L124,L125]
    v23 = v7[69]                                                      [L126]
    if (!v23 || *(v23 + 300) != 1) goto LABEL_29                      [L127,L128]
    v7 = v7[69]; goto LABEL_30                                        [L129]
LABEL_29:
    v7 = v7[68]                                                       [L142]
LABEL_30:
    if (v27++ > v25) { BufferEntryClear(buffer_mask); return }        [L131-L137]
    if (v26 != 1 && !v7[17]) { BufferEntryClear(buffer_mask); return }  [L139,L140-L136]
}
```

## Meaning (GUESS)

- GUESS Walks the racing-line node chain from a cached node (0x3A9C) to a target node id (`obj + 0x4040`), using
  two position queries (`sub_403640` at the current pose, and at a transformed target pose), bounded by
  `2 * dword_5EA3F0` iterations [L38-L71].
- GUESS For each node it copies the node XYZ into the object pose 0x34D4..0x34DC, computes a rotation matrix from
  the transform result 0x34E0..0x34E8 into 0x34B0 (this+3372), and runs the physics/suspension/contact pipeline
  [L88-L102].
- GUESS It also toggles visibility of up to three global scene nodes (dword_8AD07C/80/84), so a render/visual
  component is involved — not only driving state [L104-L121].
- GUESS Chain direction: normally follows the alternate link `+0x114` when that link's `+300 == 1`, otherwise the
  forward link `+0x110`; the mode byte 0x3440 selects a pre-pass that requires each `+0x110` link's `+0x12C` to be
  non-zero [L73-L87, L126-L143].
- GUESS The caller (`sub_4BB8E0`) invokes this for session types <= 6 while `*(v3+13000) <= 1`, then also resets
  some callers state; this looks like a path-following/pose replay helper tied to the racing line data structure
  [caller L13, L6-L12].
- GUESS This function does not write throttle, brake or steering; it is not part of the per-tick AI pedal/steer
  chain (doc 54 pipeline) [whole body].

## Questions

- What object is `this`? The caller passes `*sub_4BB8E0_this + 12`; is that a vehicle (then all 0x34xx fields are
  vehicle 0x34xx + 0xC), a replay/ghost object, or a camera? `SessionType <= 6` and `+0x32C8 <= 1` gate it.
- Node record layout: is `+264` (0x108) or `+272` (0x110) the forward link and `+268` (0x10C) the previous link?
  The code uses `+268` as "previous" in the first scan and `+272`/`+276` as next/alternate later.
- What are `dword_5EA2C0` (graph manager) and `dword_5EA3F0` (multiplier) exactly?
- Do the three scene-node handles correspond to the followed car, its target, and the ghost?
- The `v3|v4` / `v14|v15` byte flags are decompiler artifacts of flag comparisons; which real conditions do they
  encode?
