## RideHeightDelta_004ef680 — RideHeightDeltaCompute

**Summary:** Computes average ride height delta (pitch component) from four corner ride heights and packs into a 3-vector with track Y position. Part of vehicle physics/suspension system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CoordinateTransformWithOffset (004ef6c0), AIVehiclePathPositionTracking (004ef7c0), F_3DTransformWithMatrixMultiplication (004efb20), RayTriangleIntersectionWithBarycentricCoordinate (004efbd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x74C | R | — | coordinatesInTrack.y (replay) [CONFIRMED] |
| this | 0x3590 | R | — | Front-left corner ride height |
| this | 0x3610 | R | — | Rear-left (or front-right) corner ride height |
| this | 0x3688 | R | — | Front-right corner ride height |
| this | 0x3708 | R | — | Rear-right corner ride height |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always computes and returns result.
