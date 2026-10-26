## ParticleCollisionSpark_004cb620 — CollisionSparkParticleSpawn

**Summary:** Spawn a spark particle at a collision contact point. Allocates slot, sets position, velocity, size from collision data, computes spark color/intensity, flags texture layer. Called by collision dispatch when surface generates sparks.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CollisionEffectDispatch (004ce3e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | texture layer index for spark type |
| this | 0x10 | R | — | secondary texture parameter |
| this | 0x14 | R | — | tertiary texture parameter |
| this | 0x48 | R | — | threshold speed for spark size scaling |
| this | 0x4C | R | — | velocity scale divisor |
| this | 0x58 | R | — | buffer capacity / max slot count |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e708 | flt_59E708 | R | SoundVolumeLowThreshold [DERIVED] (also: ` — low threshold) |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: ` — display message threshold) |
| 005acea8 | flt_5ACEA8 | R | AudioNetworkTimingOffset [DERIVED] |
| 007c9360 | dbl_7C9360 | R | Unknown_Struct_7C9360 [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044c550 | CollisionNormalFromFeature | compute collision normal from feature data |
| 004cb540 | CircularBufferSlotAlloc | allocate particle slot from circular buffer |
| 00558c60 | TextureLayerFlagSet | set texture layer flag on particle |
| 00558cb0 | ArrayElementFlagSetWithBoundsCheck | set array element flag for texture layers |
| 00558cf0 | BoundsCheckedArrayWrite | write particle data to output buffer with bounds check |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x58 | > | 0 | slot capacity (must have available slots) |

**Guard interpretation:** Passes (spawns spark) when collision speed magnitude >= 1.0 AND particle slot capacity > 0. Blocked (no spark) when speed < 1.0 or no slots available.
