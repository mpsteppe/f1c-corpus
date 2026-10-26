## SurfaceHeightfieldCollisionCallback_00404250 — WheelSurfaceCollisionSolver

**Summary:** Solves wheel-surface contacts for vehicle. Computes grip-based friction scaling factor, runs per-wheel sub_4FB260 (friction) and sub_4FAF60 (suspension) callbacks, allocates memory, then performs spatial queries (SpatialNearestNeighborQueryWithPlaneTest) for each wheel to detect terrain collision and compute contact height and surface normal. Updates neighbor pointers and contact data at offset +276/+296.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Restart (0042d7a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | element count threshold for spatial query (compared to wheel node value at +300) |
| this | 0x130 | R | — | wheel array count (this[76]) |
| this | 0x134 | R | — | wheel array pointer (this[77]) |
| this | 0x170 | RW | — | contact progress counter (incremented, written with 0 and -1) |
| this | 0x174 | RW | 18446744073709551615 | phase state flag (-1 = idle) |

**Written-by note (persistence):**
- this 0x170: updated per collision pass — external poke persists until next pass
- this 0x174: updated per collision pass — external poke persists until next pass

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | float threshold for contact aging overflow |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 008afee8 | flt_8AFEE8 | R | TrackGripBase [DERIVED] |
| 008afeec | flt_8AFEEC | R | TrackGripComparison [DERIVED] (also: ` — additive globals) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004038e0 | SpatialNearestNeighborQueryWithPlaneTest | finds nearest surface triangle below wheel for collision height |
| 004046b0 | MemoryAllocation | wheel memory/state allocation for collision structures |
| 00404790 | ShortComputation_4790 | iterates wheels calling FAILNODOCENTRY (unregistered helper) |
| 004047d0 | CountedLoopCallToElementUpdate | updates all wheel elements in batch |
| 004faf60 | sub_4FAF60 | per-wheel suspension force callback |
| 004fb260 | sub_4FB260 | per-wheel friction force callback |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x130 | <= | 0 | wheel count == 0 — skip collision processing |
| this | 0x130 | > | 0 | wheel count > 0 — process per-wheel collisions |

**Guard interpretation:** If wheel count (this+0x130) > 0, runs friction/suspension callbacks, memory allocation, then iterates each wheel checking terrain contact. For each wheel, if node value at +300 >= threshold (this+0x10), queries terrain height; otherwise skips spatial query. PASSES: wheels processed with terrain contact data updated. BLOCKED: if count <= 0, only sets phase flag and returns.
