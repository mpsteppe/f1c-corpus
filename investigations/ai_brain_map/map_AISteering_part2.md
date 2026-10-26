# map_AISteering_part2 — `AISteering` declared `sub_4270A0`, source L304-L440 (opponent ranking)

Part 2 of 5 (phase: rank the 5 proximity slots into the best-5 list). Function: address `0x4270A0`;
file `functions/AISteering_004270a0.c`; 1314 lines. Caller: `AIMainUpdate` L247.

## Identity

- `this` = F1CVehicle. Proximity slots come from `OpponentProximityScanTeamRecognition` (68-byte slots at 0x4174,
  distance at +0x34, team index at +0x40); this part re-scans each slot toward the current waypoint chain and ranks
  candidates by an arrival/priority value.
- Names: 0x4440 = Speed (CONFIRMED); 0x4468 = look-ahead index (doc 54); 0x4438 = brake candidate (doc 54);
  0x4550 = waypoint set selector (typed, shared with AIRacingLine); 0x41A8 = slot 0 squared distance (see
  `map_OpponentProximityScanTeamRecognition.md`); 0x42C8/0x42D8 = per-opponent state fields.

## Inputs

| hex | dec | type | first line read | name |
|---|---|---|---|---|
| 0x41A8 | 16808 | float | L307 (`v14[13]`, slot +52) | slot squared distance (slot 0) |
| 0x4354 | 17236 | _DWORD | L318, L321, L323, L341 | CurrentWaypointPtr / look-ahead ptr array (doc 54) |
| 0x34E0 | 13536 | float | L337 | self world X (slot vehicle pos at +0x34E0) |
| 0x34E4 | 13540 | _DWORD | L338 | self world Y |
| 0x34E8 | 13544 | float | L339 | self world Z |
| 0x34F8 | 13560 | float | L328 | velocity X |
| 0x34FC | 13564 | _DWORD | L329 | velocity Y |
| 0x3500 | 13568 | float | L330 | velocity Z |
| 0x4440 | 17472 | float | L331, L342 | Speed (CONFIRMED) |
| 0x448C | 17548 | float | L334 | heading X (doc 54) |
| 0x4490 | 17552 | _DWORD | L335 | heading Y |
| 0x4494 | 17556 | float | L336 | heading Z (doc 54) |
| 0x4438 | 17464 | float | L358 | brake candidate (doc 54) |
| 0x4468 | 17512 | _DWORD | L341 | look-ahead index (doc 54) |
| 0x4550 | 17744 | _DWORD | L313 | waypoint set selector (typed) |

Also read: slot vehicle fields `+13536` (X), `+17236` (its waypoint), `+13000` (L368), slot `+48` (v14[12]),
slot `+12` (v14[3]).

## Outputs

| hex | dec | type | first line written | name |
|---|---|---|---|---|
| 0x42C8 | 17096 | _DWORD | L346 | per-opponent waypoint index (28-byte records; -1 default) |
| 0x42D8 | 17112 | _DWORD | L371 | per-opponent block flag (float -1.0 bit pattern) |

Slot `+56` (`v14[14]`) receives the resolved waypoint pointer (L315, L324).

## Constants

Grouped by value; every numeric literal except 0/1 in L304-L440.

| value | lines | note |
|---|---|---|
| 12000.0 | L307 | slot distance validity bound |
| 0.0099999998 | L343, L344, L361, L362 | speed difference floor |
| 5.0 | L345, L360, L363 | distance offset |
| 20 | L354 | look-ahead pointer array length |
| 0.5 | L368 | speed gate for invalid-waypoint flag |
| -10000.0 | L370 | forced-minimum priority |
| -1082130432 | L371 | float bit pattern = -1.0 |
| 0.1 | L358 | brake gate |
| 13000 | L368 | slot vehicle flag offset |
| 99999.898 | - | ranking sentinels from part1 (L286-L300) |

## Logic

NOTE: source uses scaled `this[N]` / slot `v14[N]` forms; Logic keeps source-literal indices. No hex tokens used.

```
v14 = this + 16756 (first proximity slot)                        [L304]
repeat 5 {                                                       [L305,L437,L438,L439]
    if (v14[13] < 12000.0) {                                     [L307]
        v15 = SpatialTreeNearestNeighborSearch(dword_5EA2C0, slotcar+13536, slotcar+17236,
                                               this[4436], 0)     [L309,L310,L311,L312,L313,L314]
        v14[14] = v15                                            [L315]
        v16 = *(v15 + 300)                                       [L316]
        if (v16 != 1 || *(curwp + 300) || (v17 = *(v15+276)) != 0 && v17 != *(v17+272)) {   [L317,L318,L319]
            if (!v16 && *(curwp + 300) == 1) {
                v15 = BVHNearestNeighborQuery(slotcar+13536, curwp)   [L323]
                v14[14] = v15                                    [L324]
            }
            ShortComputation_3ca0(v14, this[3390], this[3391], this[3392], this[4368])   [L326-L331]
            ShortComputation_3db0(v14, this[4387], this[4388], this[4389],
                                  this[3384], this[3385], this[3386])   [L332-L339]
            VehicleDynamics(v18, v15, 0, 1)                      [L340]
            VehicleDynamics(v19, this[4 * this[4378] + 17236], 0, 0)   [L341]
            v20 = this[4368] - v14[12]                           [L342]
            if (v20 < 0.0099999998) v20 = 0.0099999998           [L343,L344]
            v21 = v14[3] - 5.0                                   [L345]
            this[28 * v14[16] + 17096] = -1                      [L346]
            v22 = v21 / v20; v23 = 0; v24 = this + 17236         [L347,L348,L349]
            while (*v24 != v15) { ++v23; ++v24; if (v23 >= 20) goto LABEL_61 }   [L350,L352,L353,L354,L355]
            this[28 * v14[16] + 17096] = v23                     [L357]
            if (v14[12] < this[4 * v23 + 17316] && this[4366] > 0.1) {   [L358]
                v25 = this[4 * v23 + 17316] - v14[12] + 5.0      [L360]
                if (v25 < 0.0099999998) v25 = 0.0099999998       [L361,L362]
                v22 = (v14[3] - 5.0) / v25                       [L363]
            }
LABEL_61:
            if (v22 < 0.0) v22 = 0.0                             [L366,L367]
            if (!*(slotcar + 13000) || v14[12] < 0.5 && this[4368] > 1.0) {   [L368]
                v22 = -10000.0                                   [L370]
                this[28 * v14[16] + 17112] = -1.0 (bit -1082130432)   [L371]
            }
            # ascending insert of v22 into v180..v184 with indices v185..v189 / v13
            if (v22 >= v180) {                                   [L373]
                if (v22 >= v181) {                               [L375]
                    if (v22 >= v182) {                           [L377]
                        if (v22 >= v183) {                       [L379]
                            if (v22 < v184) { v184 = v22; v189 = v166 }   [L381,L383,L384]
                        } else { v29 = v183; v183 = v22; v189 = v13; v13 = v166; v184 = v29 }   [L387-L394]
                    } else { v28 = v182; v182 = v22; v189 = v13; v13 = v187;
                             v184 = v183; v183 = v28; v187 = v166 }   [L396-L405]
                } else { v184 = v183; v27 = v181; v181 = v22; v183 = v182;
                         v189 = v13; v13 = v187; v187 = v186; v182 = v27; v186 = v166 }   [L407-L418]
            } else { v184=v183; v189=v13; v13=v187; v183=v182; v187=v186;
                     v26=v180; v180=v22; v182=v181; v186=v185; v181=v26; v185=v166 }   [L422-L432]
        }
    }
    v14 += 17; ++v166                                            [L436,L437]
}                                                                [L439]
v188 = v13                                                       [L440]
```

## Meaning (GUESS)

- GUESS For each of the 5 proximity slots, finds the nearest waypoint on that opponent's chain (spatial tree, BVH
  fallback when branch flags disagree with the current chain) and computes an arrival/priority value
  `v22 = (slot distance - 5) / max(speed difference, 0.01)`, then optionally `(dist - 5) / max(waypoint speed
  projection - slot speed + 5, 0.01)` [L309-L363].
- GUESS Blocked or invalid opponents get priority -10000 and their per-opponent flag 0x42D8 set to -1.0; the
  per-opponent waypoint index 0x42C8 is reset to -1 and set to the index in the 20-slot look-ahead array when
  found [L346-L371].
- GUESS Keeps the 5 smallest priority values ascending in v180..v184 with the slot numbers in v185..v189
  [L373-L433].
- GUESS These ranked opponents feed the per-opponent decision loop in parts 3 and 4.

## Questions

- What is `v14[3]` (slot +12, "time to opponent"?) and `v14[12]` (slot +48, relative speed?)? The priority formula
  mixes it with the distance.
- What does slot vehicle `+13000` flag mean (invalid/off-track)?
- `v14[14]` (slot +56) stores a per-slot waypoint pointer; who else reads it?
