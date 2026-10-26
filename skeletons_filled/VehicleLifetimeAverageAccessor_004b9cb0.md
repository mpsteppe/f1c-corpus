## VehicleLifetimeAverageAccessor_004b9cb0 — VehicleLifetimeAverageAccessor

**Summary:** Reads a float at offset 0xF30 from a dereferenced object. Returns the lower bound of the angle/range. Part of vehicle lifetime or telemetry data access.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_c940 (0047c940), CollisionSystemInit (0047c960), TelemetryDisplaySwitch (0047dbe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xF30 | R | — | lower bound of angle/range from dereferenced object |
| this | 0x0 | R | — | pointer to actual object |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always reads and returns the float.
