## ParticleCollisionSpawn_004c9fb0 — ParticleCollisionSpawnHandler

**Summary:** Handles particle collision events by spawning secondary particles — computes bounding-box center and half-extent at the collision point, randomizes spread direction/magnitude using a weather noise table, filters nearby packed-array elements, and allocates a collision result buffer with distance-squared data.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SpecialFX_Init (004cf070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | collision source / object pointer (set from a2 parameter) |
| this | 0x4 | RW | — | collision center X coordinate (world space) |
| this | 0x8 | RW | — | collision center Y coordinate (world space) |
| this | 0xC | RW | — | collision center Z coordinate (world space) |
| this | 0x10 | RW | — | collision bounding-sphere half-extent / radius |
| this | 0x18 | RW | — | particle scale multiplier (noise * 0.15 + 1.0) |
| this | 0x1C | RW | — | particle lifetime / size constant (set to 0.00094) |
| this | 0x20 | RW | — | angular velocity / spread rate (noise * 0.4 + 2.8 scaled by height) |
| this | 0x24 | RW | — | direction cosine component (cos of noise-derived angle) |
| this | 0x28 | RW | — | direction sine component (sin of noise-derived angle) |
| this | 0x2C | RW | — | direction vector weighted component X |
| this | 0x30 | RW | — | direction vector weighted component (cross-axis) |
| this | 0x34 | RW | — | count of filtered elements above collision height |
| this | 0x38 | RW | — | pointer to allocated buffer of filtered collision records |

**Written-by note (persistence):**
- this 0x0: write-once per collision event — external poke survives until next event
- this 0x4: write-once per collision event — external poke survives until next event
- this 0x8: write-once per collision event — external poke survives until next event
- this 0xC: write-once per collision event — external poke survives until next event
- this 0x10: write-once per collision event — external poke survives until next event
- this 0x18: write-once per collision event — external poke survives until next event
- this 0x1C: write-once per collision event — external poke survives until next event
- this 0x20: write-once per collision event — external poke survives until next event
- this 0x24: write-once per collision event — external poke survives until next event
- this 0x28: write-once per collision event — external poke survives until next event
- this 0x2C: write-once per collision event — external poke survives until next event
- this 0x30: write-once per collision event — external poke survives until next event
- this 0x34: write-once per collision event — external poke survives until next event
- this 0x38: write-once per collision event — external poke survives until next event

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |
| 0059e6e8 | flt_59E6E8 | R | TireDampingBlendFactor [DERIVED] |
| 0059e7e8 | flt_59E7E8 | R | TimeScalingConstant [DERIVED] |
| 0059e868 | flt_59E868 | R | SteeringResponseGain [DERIVED] |
| 0059e8c8 | flt_59E8C8 | R | Physics_ConvergenceThreshold [DERIVED] (also: ` — convergence threshold (terminates iteration) |
| 0059ed28 | dbl_59ED28 | R | PhysicsMinDeltaThreshold [DERIVED] |
| 005ace94 | flt_5ACE94 | R | ParticleSpreadScale [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008ab274 | flt_8AB274 | R | WeatherNoiseTable [DERIVED] (also: � random noise table (docs/12) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dd550 | BoundingBoxComputation | computes bounding box min/max coordinates for the collision volume |
| 0054b420 | TripleFieldQuery | reads three consecutive float fields from the collision struct |
| 0054c230 | LinkedListIndexedAccessor_c230 | retrieves the linked list head at index 0 for packed array access |
| 0054e100 | PackedArrayTotalSize | returns total number of elements in the packed array |
| 0054e120 | PackedArrayIndexLookup | looks up a packed array element by index |
| 00587c03 | OperatorNewNhMallocWrapper | heap allocation wrapper for the filtered collision record buffer |

**Guard conditions:** The entire function body is gated by `a2 != 0` — if no collision source object is provided, the function returns immediately without accessing any fields. The particle randomization block is additionally gated by the bounding-box height (`v31 - v28 > 0.0`), skipping spread calculations for degenerate/flat collisions.
