## CollisionDetectionSystem_004ea970 — VehicleCollisionDetectionSystem

**Summary:** Per-frame collision detection system for a vehicle: iterates 13 contact-point slots, reads collision events from network packets, transforms contact points to world space, identifies colliding vehicle pairs, computes collision response (penetration depth, contact normal, impulse force), and dispatches force application to both vehicles.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ParticleEffectUpdateDispatch (004eb430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0xA4 | RW | — | max collision severity / impact force this frame |
| this | 0xA8 | RW | — | collision depth / normalized penetration ratio |
| this | 0xAC | RW | — | collision response impulse X component |
| this | 0xB0 | RW | — | collision response impulse Y component |
| this | 0xB4 | RW | — | collision response impulse Z component |
| this | 0xD0C | R | — | collision slot active flag (0 = slot disabled) |
| this | 0xD4C | R | — | vehicle body zone enable flag (0 = zone disabled) |
| this | 0x34B0 | R | — | vehicle orientation matrix [0][0] (X-axis world X) |
| this | 0x34B4 | R | — | vehicle orientation matrix [0][1] (X-axis world Y) |
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] |
| this | 0x34BC | R | — | vehicle orientation matrix [1][0] (Y-axis world X) |
| this | 0x34C0 | R | — | vehicle orientation matrix [1][1] (Y-axis world Y) |
| this | 0x34C4 | R | — | vehicle orientation matrix [1][2] (Y-axis world Z) |
| this | 0x34C8 | R | — | vehicle orientation matrix [2][0] (Z-axis world X) |
| this | 0x34CC | R | — | vehicle orientation matrix [2][1] (Z-axis world Y) |
| this | 0x34D0 | R | — | vehicle orientation matrix [2][2] (Z-axis world Z) |
| this | 0x34D4 | R | — | vehicle world position X |
| this | 0x34D8 | R | — | vehicle world position Y |
| this | 0x34DC | R | — | vehicle world position Z |
| this | 0x3590 | R | — | collision contact point X in local space |
| this | 0x3594 | R | — | collision contact point Y in local space |
| this | 0x3ABC | R | — | vehicle body vertex / geometry data start offset |
| this | 0x3AC0 | R | — | vehicle body vertex / geometry data stride |
| this | 0x3B74 | R | — | vehicle state flag (collision processing enabled) |

**Written-by note (persistence):**
- this 0xA4: recalc every frame — external poke does NOT persist
- this 0xA8: recalc every frame — external poke does NOT persist
- this 0xAC: recalc every frame — external poke does NOT persist
- this 0xB0: recalc every frame — external poke does NOT persist
- this 0xB4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e4dc | flt_59E4DC | R | FullResponseThreshold [DERIVED] (also: ` — full response threshold (float) |
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |
| 0059e774 | flt_59E774 | R | ShortToFloatScale [DERIVED] (also: ` — position scale factor) |
| 0059e77c | flt_59E77C | R | ShortVertexScale [DERIVED] (also: ` — short-to-float scale/conversion factor) |
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: ` — display message threshold) |
| 0059e940 | flt_59E940 | R | Flt_PhysicsLimit_9E940 [DERIVED] |
| 005ac988 | flt_5AC988 | R | UVCoordScaleFactor [DERIVED] (also: ` — UV coordinate scale factor) |
| 005ad1dc | flt_5AD1DC | R | SuspensionDampingMult [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea560 | dword_5EA560 | R | GlobalInstance_5EA560 [CONFIRMED] |
| 005ea570 | dword_5EA570 | R | InitStateFlag2 [DERIVED] |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00410b80 | ArrayOfStructLinearSearchByID | search game object array by ID for non-vehicle collision target |
| 0041ad80 | sub_41AD80 | apply collision impulse/force to both vehicles involved in contact |
| 004ea010 | ArithmeticComparison_a010 | allocate and initialize collision contact response data struct |
| 004ed420 | VehicleGeometryProximityTest | compute closest-approach distance and penetration between two surfaces |
| 00547390 | ArithmeticComparison_7390 | compute/compare arithmetic value for static world collision response |
| 0054fa90 | NetworkPacketDataReader | read collision event data from network packet buffer for given slot |
| 0054fae0 | BufferEntryClear | mark network packet buffer slot as processed/consumed |
| 005694e0 | VehicleProjectedPosition | project a 3D point onto a plane defined by origin and normal |

**Guard conditions:** no fixed field-vs-literal guard branches — function uses dynamic checks (vehicle ID matching, slot validity flags) within the main processing loop; early skip via `BufferEntryClear` when NetworkPacketDataReader returns 0 (no collision data for slot).
