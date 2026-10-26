## VehicleProximity_004fb2e0 — ComputeVehicleProximityDistances

**Summary:** Computes closest-approach proximity distances between this vehicle and two other entities by projecting position+direction lines. Stores results to output fields, with FLT_MAX sentinels for parallel or non-intersecting cases.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MultiPhaseProcessingStateMachine (00404460), CountedLoopCallToElementUpdate (004047d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x10C) | 0x94 | R | — | own position offset X (from data block) |
| *(this+0x10C) | 0x9C | R | — | own position offset Y |
| *(this+0x10C) | 0xA4 | R | — | own direction vector X |
| *(this+0x10C) | 0xAC | R | — | own direction vector Y |
| *(this+0x110) | 0x94 | R | — | target1 position X |
| *(this+0x110) | 0x9C | R | — | target1 position Y |
| *(this+0x110) | 0xA4 | R | — | target1 direction vector X |
| *(this+0x110) | 0xAC | R | — | target1 direction vector Y |
| *(this+0x110) | 0x110 | R | — | target1 internal pointer |
| *(this+0x114) | 0x0 | R | — | target2 position X |
| *(this+0x114) | 0x8 | R | — | target2 position Y |
| this | 0x94 | R | — | own position offset X |
| this | 0x9C | R | — | own position offset Y |
| this | 0xA4 | R | — | own direction vector X |
| this | 0xAC | R | — | own direction vector Y |
| this | 0xB0 | RW | 0 | output proximity distance to target1 |
| this | 0xB4 | RW | 0 | output proximity distance to target2 |
| this | 0x10C | R | — | pointer to own data block |
| this | 0x110 | R | — | pointer to target1 vehicle struct |
| this | 0x114 | R | — | pointer to target2 entity struct |

**Written-by note (persistence):**
- this 0xB0: conditional — written when target1 exists and direction vectors not parallel; sentinel 0 for self, large float otherwise; external poke survives until next call
- this 0xB4: conditional — written when target2 exists and direction vectors not parallel; sentinel 0 for self, FLT_MAX for non-intersecting; external poke survives until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ad278 | dbl_5AD278 | R | FrictionAngleClampHigh [DERIVED] |
| 005ad280 | dbl_5AD280 | R | LineIntersectionThreshold [DERIVED] (also: ` — steering alignment lower threshold) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** *(this+0x10C) == NULL → skip entirely. *(this+0x110) == NULL → skip target1 proximity. *(target1+0x110) == NULL → skip target1 proximity. Dot product of direction vectors within epsilon (±0.00001) parallel → stop target1 calculation, set 0xB0=0 if self or large sentinel otherwise. *(this+0x114) == NULL → skip target2 proximity. Dot product near 0 (±0.00001) → parallel, set 0xB4=0 if self or FLT_MAX sentinel otherwise.
