## SweptSuspensionCollisionDetection_00401910 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsNodePropagationWithDistanceFalloff (00401c90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x130 | RW | — | [LLM] |
| this | 0x134 | RW | — | [LLM] |
| this | 0x138 | RW | — | [LLM] |

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
| 00401340 | VehicleSuspensionForceCalculation | [LLM] |
| 004e8ce0 | TireForceSolver | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x130 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
