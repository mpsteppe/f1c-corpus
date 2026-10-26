## WheelContactTransform_004ef180 — wheel contact transform with collision feature query

**Summary:** Transforms per-corner vectors by 3x3 rotation matrix, adds offset, queries collision normal from feature, and updates surface friction for each of 4 wheel contacts. Part of wheel contact/collision system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ModeDispatchedRenderPhysicsCall (0040f300), PerVehicleCameraUpdateIterator (004109d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x704 | R | — | rotation matrix row 0, column 0 |
| this | 0x708 | R | — | rotation matrix row 0, column 1 |
| this | 0x70C | R | — | rotation matrix row 0, column 2 |
| this | 0x710 | R | — | directionInTrack.x [CONFIRMED] — rotation matrix row 1, col 0 |
| this | 0x714 | R | — | rotation matrix row 1, column 1 |
| this | 0x718 | R | — | directionInTrack.y [CONFIRMED] — rotation matrix row 1, col 2 |
| this | 0x71C | R | — | rotation matrix row 2, column 0 |
| this | 0x720 | R | — | rotation matrix row 2, column 1 |
| this | 0x724 | R | — | rotation matrix row 2, column 2 |
| this | 0x3668 | RW | — | per-corner collision normal pointer (array of 4, stride 62 floats = 0xF8) |

**Written-by note (persistence):**
- this 0x3668: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e448 | flt_59E448 | R | TileSteppingMultiplier [DERIVED] |
| 007c9360 | dbl_7C9360 | R | Unknown_Struct_7C9360 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044c550 | CollisionNormalFromFeature | queries collision normal from feature data for transformed contact point |
| 004ce110 | WheelSurfaceContactFriction | computes and applies surface friction for wheel contact |
| 004ec020 | F_3DVectorAddition | adds offset vector to transformed contact position |

**Guard conditions:** CollisionNormalFromFeature return == null → BLOCKED (skip surface friction update for this corner). PASSES: valid collision normal → update contact pointer and compute friction.
