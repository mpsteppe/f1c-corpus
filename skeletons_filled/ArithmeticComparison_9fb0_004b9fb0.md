## ArithmeticComparison_9fb0_004b9fb0 — VehicleTypeRangeValidator

**Summary:** Checks if vehicle type identifier is 2; if so, validates that the vehicle data value at offset 0xF8C is within range 6-8, returning false if outside.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** WheelSurfaceContactFriction (004ce110), CollisionEffectDispatch (004ce3e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | vehicle type identifier |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b9e30 | VehicleDataAccessor | retrieve vehicle data at offset 0xF8C for range check |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 2 | vehicle type identifier |

**Guard interpretation:** PASSES when *this != 2 (always returns 1). If *this == 2, PASSES only when VehicleDataAccessor result is in [6, 8] inclusive; BLOCKED (return 0) when value < 6 or > 8.
