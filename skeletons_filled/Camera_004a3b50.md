## Camera_004a3b50 — CameraUpdate

**Summary:** Computes updated camera position and yaw rotation for a 3D object (pit crew member or vehicle camera). Reads current camera state via RenderCallWithGuard, computes view direction with optional weather noise perturbation, handles two code paths based on a mode flag (+0x12C in scene struct), and performs spatial grid collision query when sound source handle (0x64) is active.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4A00A0 (004a00a0), PitCrewAnimationMASSetup (004a3910)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x64 | R | — | guard: sound source handle, if non-null enables spatial collision query and bounding box computation |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e448 | flt_59E448 | R | TileSteppingMultiplier [DERIVED] |
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: ` — display message threshold) |
| 0059e8b4 | flt_59E8B4 | R | ClampUpperThreshold [DERIVED] |
| 0059e940 | flt_59E940 | R | Flt_PhysicsLimit_9E940 [DERIVED] |
| 005acb28 | flt_5ACB28 | R | AISteerAngleThreshold [DERIVED] |
| 005acb2c | flt_5ACB2C | R | LateralForceThreshold [DERIVED] |
| 005acb30 | flt_5ACB30 | R | PhysicsForceThreshold [DERIVED] |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007c9360 | dbl_7C9360 | R | Unknown_Struct_7C9360 [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008ab274 | flt_8AB274 | R | WeatherNoiseTable [DERIVED] (also: � random noise table (docs/12) |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00403640 | sub_403640 | queries scene setup struct for camera-related position/matrix data |
| 0044c4c0 | SpatialGridQuery | checks spatial collision grid to adjust camera Z position |
| 004a2800 | Vec3CopyToStruct | copies computed position and yaw offset to struct fields at 0x4C-0x60 |
| 004d1140 | RenderCallWithGuard | gets current camera/render state from player vehicle pointer |
| 004dd550 | BoundingBoxComputation | computes bounding box for spatial collision query |
| 00566e40 | EulerToRotationMatrix | converts Euler angles to rotation matrix (alt camera path) |

**Guard conditions:** Guard at this[0x64] (sound source handle): if non-null, calls BoundingBoxComputation then SpatialGridQuery for collision-aware position adjustment. If null, skip spatial query. Also, early mode check on sub_403640 result +0x12C: if == 1, enters standard camera calculation path with view-direction clamping and weather noise; otherwise enters alternate Euler-based camera path.
