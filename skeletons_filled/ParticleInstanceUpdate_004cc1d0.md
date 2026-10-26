## ParticleInstanceUpdate_004cc1d0 — ParticleInstanceUpdate

**Summary:** Core particle instance update function: iterates all active particles, checks lifetime (removes expired ones via swap-remove), interpolates position from velocity, handles vehicle collision detection (ray-sphere), updates texture layer position, computes alpha fade (early-life boost, mid-life sustain, late-life fade), and writes ARGB color. Flags check for scoring gate mode.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | Base position offset X added to interpolated particle position |
| this | 0x10 | R | — | Base position offset Y added to interpolated particle position |
| this | 0x14 | R | — | Base position offset Z added to interpolated particle position |
| this | 0x18 | R | — | Time-scaled position multiplier X for particle offset |
| this | 0x1C | R | — | Time-scaled position multiplier Y for particle offset |
| this | 0x20 | R | — | Time-scaled position multiplier Z for particle offset |
| this | 0x64 | R | — | Active particle count (number of elements in the particle array) |
| this | 0x68 | R | — | Pointer to particle array (array of particle instance descriptors) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005d3490 | flt_5D3490 | R | CockpitUIFloat [DERIVED] |
| 005d3494 | flt_5D3494 | R | PhysicsStepAccumulator [DERIVED] |
| 005ece1c | unk_5ECE1C | R | VEH[0].0x744 = coordinatesInTrack.x (replay) [CONFIRMED] |
| 007cf9ec | byte_7CF9EC | R | Byte_RendererFlag_F9EC [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ab6ec | dword_8AB6EC | R | ScoringDataPtr [DERIVED] |
| 008ac4e0 | flt_8AC4E0 | R | SceneObjectPool [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b9ce0 | Delegation | Updates scoring delegation when ScoringGate == 2 |
| 004c9c70 | FindDriversInRange | Finds nearby vehicle/driver objects for particle collision testing |
| 004cb5a0 | ArrayElementRemoval | Removes expired particles from array (swap-remove by index) |
| 004cbdd0 | RaySphereIntersection | Tests particle-vs-vehicle collision via ray-sphere intersection (sliding response) |
| 00558c60 | TextureLayerFlagSet | Sets the texture layer position for particle rendering |
| 00558cb0 | ArrayElementFlagSetWithBoundsCheck | Updates particle render flags (positional) with bounds checking |
| 00558cf0 | BoundsCheckedArrayWrite | Writes final ARGB color (with computed alpha in upper byte, 0xFFFFFF RGB) to particle |

**Guard conditions:** Checks ScoringGate global for mode selection. Per-particle lifetime check: if current time is outside particle's lifespan window (v5[2]..v5[3]), the particle is removed. Collision proximity check: only triggers RaySphereIntersection when within flt_5D3490 distance threshold and target ID differs. Alpha computation: branches on flags condition (early vs late life) then checks threshold (v28 <= v5[5]) for early-life boost.
