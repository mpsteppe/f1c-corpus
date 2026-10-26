## TireTemperatureSimStep_004c77d0 — Tire temperature simulation step

**Summary:** Simulates tire temperature for a vehicle each frame: clamps temperature to [0, 5.0], subtracts cooling rate, applies recovery when temperature drops to zero, and updates car lighting render. Only runs for vehicle types 0 or 1 (human/primary).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** IterateVehicles (004b3ba0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32C8 | R | — | vehicle type/index; checked > 1 to skip |
| this | 0x4894 | R | — | team ID used in clamped physics scale computation |
| this | 0x48B8 | RW | — | tire temperature value, clamped [0, 5.0], cooled per frame |

**Written-by note (persistence):**
- this 0x48B8: updated every frame with simulated temperature; persists across frames as simulation state

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 0083ee60 | dword_83EE60 | RW | RingBufferCount [DERIVED] (also: ` -- ring buffer counter) |
| 008aae64 | dword_8AAE64 | RW | RingBufferWritePtr [DERIVED] (also: ` -- ring buffer offset) |
| 008afe90 | dbl_8AFE90 | R | EngineCoolingRate [DERIVED] (also: ` — cooling rate per frame) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461db0 | SessionStateCheckWrapper | check if session is in active state (returns 0 if not) |
| 00462ff0 | ClampedPhysicsScaleWithThreshold | compute clamped physics scale from vehicle/team data |
| 004c71c0 | SetupCarLightingAndRender | update car lighting and render with ring buffer entry |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x32C8 | > | 1 | vehicle type flag — only process vehicles of type 0 or 1 (human player or primary AI) |

**Guard interpretation:** BLOCKED (early return): vehicle type > 1 (non-primary/spectator vehicles). PASSES: type <= 1, session is active, proceeds to temperature simulation.
