## AIDelegateCall_0042add0 — SpatialNearestNeighborQuery

**Summary:** Calls `SpatialTreeNearestNeighborSearch` with vehicle position and struct parameters to find nearest spatial neighbor. Returns handle to nearest entity or zero.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4A4110 (004a4110), FindNearestVehicle (004a4710)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4354 | R | — | searchRadiusOrCount |
| this | 0x4550 | R | — | searchResultLimitOrFilter |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00403aa0 | SpatialTreeNearestNeighborSearch | Finds nearest neighbor in spatial tree given position and search parameters |

**Guard conditions:** None — always dispatches spatial query with struct fields.
