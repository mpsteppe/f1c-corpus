## ParticleTrailEmitter_004cbc50 — CollisionTrailParticleSpawn

**Summary:** Spawn a trail particle at a collision point. Allocates slot, sets position/velocity from collision data, applies noise, computes normal. Optionally adjusts Y position when a7 flag is set (surface offset mode).

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CollisionEffectDispatch (004ce3e0), ParticleCollisionEffect (004ce930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | texture layer index for trail type |
| this | 0x10 | R | — | secondary texture parameter |
| this | 0x14 | R | — | tertiary texture parameter |
| this | 0x1C | R | — | surface offset scale (used when a7 flag set) |
| this | 0x58 | R | — | buffer capacity / max slot count |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e708 | flt_59E708 | R | SoundVolumeLowThreshold [DERIVED] (also: ` — low threshold) |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
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

**Guard conditions:** this[0x58] > 0 — slot capacity. Passes (spawns trail) when capacity > 0. Blocked when capacity exhausted.
