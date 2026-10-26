## WheelRenderObjectPerFrameUpdate_004cb860 — WheelRenderObjectLifetimeAndVisibilityUpdater

**Summary:** Updates per-frame wheel render object positions, removes expired objects, checks ray-sphere intersections with player/AI vehicles for visibility, and applies texture/color flags. Part of the wheel render object management system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | vehicle world position X component (a1+12) |
| this | 0x10 | R | — | vehicle world position Y component (a1+16) |
| this | 0x14 | R | — | vehicle world position Z component (a1+20) |
| this | 0x18 | R | — | vehicle direction/scaled offset X (a1+24), multiplied by v5[26] |
| this | 0x1C | R | — | vehicle direction/scaled offset Y (a1+28), multiplied by v5[26] |
| this | 0x20 | R | — | vehicle direction/scaled offset Z (a1+32), multiplied by v5[26] |
| this | 0x24 | R | — | vehicle direction scale (a1+36), used for lateral offset |
| this | 0x28 | R | — | vehicle direction scale (a1+40), used for lateral offset |
| this | 0x2C | R | — | vehicle direction scale (a1+44), used for lateral offset |
| this | 0x40 | R | — | render scale factor (a1+64), multiplied with elapsed time |
| this | 0x64 | R | — | object list count (a1+100) |
| this | 0x68 | R | — | object list pointer (a1+104) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005d3490 | flt_5D3490 | R | CockpitUIFloat [DERIVED] |
| 005d3494 | flt_5D3494 | R | PhysicsStepAccumulator [DERIVED] |
| 007c54dc | dword_7C54DC | R | CurrentPlayerIndex [CONFIRMED] |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007cfa28 | dword_7CFA28 | R | AITargetSelection [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ab6ec | dword_8AB6EC | R | ScoringDataPtr [DERIVED] |
| 008ac4e0 | flt_8AC4E0 | R | SceneObjectPool [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b9ce0 | Delegation | delegates to scoring data when not in race mode (ScoringGate == 2) |
| 004c9c70 | FindDriversInRange | searches for AI drivers within a distance range from a 3D position |
| 004cb5a0 | ArrayElementRemoval | removes an expired wheel render object from the managed list |
| 004cbdd0 | RaySphereIntersection | tests ray-sphere intersection for visibility culling between vehicles |
| 00558c60 | TextureLayerFlagSet | sets texture layer/render flags on a render object using 3D position |
| 00558cb0 | ArrayElementFlagSetWithBoundsCheck | sets array element render flags with bounds validation using 3D position |
| 00558cf0 | BoundsCheckedArrayWrite | writes a packed color value (alpha in top byte) to render object array |
| 005881f0 | sub_5881F0 | transforms elapsed-time-scaled value, likely a render alpha or fade factor |

**Guard conditions:** 
- `ScoringGate == 2`: scoring/qualifying mode → delegates to scoring data; else uses session time. BLOCKED: use session time directly.
- `sessionTime > objectEndTime OR sessionTime < objectStartTime`: object outside lifetime window → remove from list. PASSES: deletion. BLOCKED: keep object and update position.
- `AITargetSelection == 1`: player-only collision query → check ray-sphere against player vehicle only. BLOCKED: skip single-player query.
- `AITargetSelection in [2,3]`: AI multi-vehicle → find nearby drivers and check ray-sphere for each, excluding self (v37 != vehicle id). BLOCKED: skip multi-vehicle query.
- Distance check for ray-sphere: `|worldX - objectX| < threshold AND |worldZ - objectZ| < threshold` (both X and Z within PhysicsStepAccumulator). PASSES: execute RaySphereIntersection. BLOCKED: skip.
- `x87 condition flags AND elapsed time <= v5[5]`: early lifetime phase → use linear ramp `v5[8] * elapsed * v5[10]` for alpha. Else -> mid phase: use constant `v5[10]` for alpha. Else (post-phase): use decay `(1.0 - (elapsed - v5[6]) * v5[9]) * v5[10]`.
