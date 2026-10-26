## SweptSuspensionCollisionDetection_00401910 — Sweep-strut contact solver

**Summary:** Advances wheel positions along velocity direction (Euler step), then performs swept collision detection for each suspension strut by sampling multiple travel positions and selecting the one with maximum contact force. Calls VehicleSuspensionForceCalculation and TireForceSolver at each sample to evaluate contact response.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsNodePropagationWithDistanceFalloff (00401c90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x130 | RW | — | number of suspension struts to process (iteration count) |
| this | 0x134 | RW | — | base pointer/offset to suspension strut data array |
| this | 0x138 | RW | — | unknown — incremented/decremented per strut processing |

**Written-by note (persistence):**
- this 0x130: recalc every frame — external poke does NOT persist
- this 0x134: recalc every frame — external poke does NOT persist
- this 0x138: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 0059e448 | flt_59E448 | R | TileSteppingMultiplier [DERIVED] |
| 0059e44c | flt_59E44C | R | Flt_CollisionTolerance [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00401340 | VehicleSuspensionForceCalculation | computes suspension contact forces at a given strut position |
| 004e8ce0 | TireForceSolver | computes tire contact force response from suspension force input |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x130 | > | 0 | strut count — number of active suspension struts |

**Guard interpretation:** If `this->count (0x130)` > 0, PASS — both the position-advancement loop and the swept-collision loop execute for that many struts. If count <= 0, BLOCKED — entire function body is skipped (early return).
