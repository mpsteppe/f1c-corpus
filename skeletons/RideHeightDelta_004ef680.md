## RideHeightDelta_004ef680 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CoordinateTransformWithOffset (004ef6c0), AIVehiclePathPositionTracking (004ef7c0), F_3DTransformWithMatrixMultiplication (004efb20), RayTriangleIntersectionWithBarycentricCoordinate (004efbd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x74C | R | — | coordinatesInTrack.y (replay) [CONFIRMED] |
| this | 0x3590 | R | — | [LLM] |
| this | 0x3610 | R | — | [LLM] |
| this | 0x3688 | R | — | [LLM] |
| this | 0x3708 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
