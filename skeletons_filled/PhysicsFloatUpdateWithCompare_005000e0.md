## PhysicsFloatUpdateWithCompare_005000e0 — Physics float update with spatial grid compare

**Summary:** Updates `a1[3]` (offset 0xC) by adding `a2` only if a spatial grid query succeeds and the new value exceeds the current value. Physics/collision system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** UtilityFunction_3d50 (00463d50), CollisionTestWithThreshold (00500560)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | Spatial query X position (a1[2]) |
| this | 0xC | RW | — | Float value being updated (a1[3]); compared against new sum |
| this | 0x10 | R | — | Spatial query Z position (a1[4]) |

**Written-by note (persistence):**
- this 0xC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c9360 | dbl_7C9360 | R | Spatial grid structure passed to SpatialGridQuery |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044c4c0 | SpatialGridQuery | Query spatial grid to check if area is valid for update |

**Guard conditions:** If `SpatialGridQuery` returns 0 → return 0 (query failed). If `v9 + a2 <= a1[3]` → return 0 (new value not greater than current). Otherwise set `a1[3] = v9 + a2` and return 1.
