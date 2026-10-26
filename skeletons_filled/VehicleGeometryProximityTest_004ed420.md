## VehicleGeometryProximityTest_004ed420 — vehicle geometry proximity test with collision response

**Summary:** Tests proximity of a point to vehicle geometry by transforming to local frame, checking distance against per-corner thresholds, and computing contact force with anisotropic triple product. Part of collision detection system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** F_3DCollisionDetectionWithAABBTestAndContactResp (004ea040), CollisionDetectionSystem (004ea970), VehicleYawRotationRecoveryController (004f1c40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x828 | R | — | start of 4-element int array, contact active pointer per corner |
| this | 0x868 | R | — | byte active flag at int array element+64 |
| this | 0x34B0 | R | — | rotation matrix row 0, col 0 |
| this | 0x34B4 | R | — | rotation matrix row 1, col 0 |
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] — rotation matrix row 2, col 0 |
| this | 0x34BC | R | — | rotation matrix row 0, col 1 |
| this | 0x34C0 | R | — | rotation matrix row 1, col 1 |
| this | 0x34C4 | R | — | rotation matrix row 2, col 1 |
| this | 0x34C8 | R | — | rotation matrix row 0, col 2 |
| this | 0x34CC | R | — | rotation matrix row 1, col 2 |
| this | 0x34D0 | R | — | rotation matrix row 2, col 2 |
| this | 0x3594 | R | — | corner 0 Z position (first element in per-float loop stride 0xF8) |
| this | 0x3610 | R | — | corner 0 contact detection radius/threshold (v18[31]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ea930 | sub_4EA930 | transforms position delta by subtracting current position |
| 004ed380 | AnisoVectorTripleProduct | computes anisotropic force triple product for contact response |
| 004ed710 | Vec3Add | adds two 3D vectors |
| 004ed750 | F_3DCrossProduct | computes 3D cross product |
| 004ed7b0 | F_33MatrixVectorMultiply | transforms contact response vector by matrix when a6 provided |

**Guard conditions:** Loop over 4 corners: if distance² >= v18[31]² (threshold) OR contact inactive → continue. PASSES: within radius AND active → compute contact force. BLOCKED at loop end with no hit → skip force computation.
