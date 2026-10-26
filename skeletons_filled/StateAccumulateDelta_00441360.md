## StateAccumulateDelta_00441360 — StateAccumulateDelta

**Summary:** Shifts wheel state history, then for each wheel computes the delta between current and previous state (position and velocity vectors), accumulating the difference back into the previous state buffer. This stores the per-frame change for later interpolation. Part of vehicle wheel state management.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsIntegrationStep (00441650)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x15AC | R | — | current wheel state array pointer (48-byte stride) |
| this | 0x15B0 | R | — | previous wheel state array pointer (580-byte stride) |
| this | 0x162C | R | — | wheel state count (number of wheels to process) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004412f0 | WheelStateHistoryShift | shifts wheel state history buffers forward |
| 0056f060 | BatchIterationWithCounter | returns iteration count for wheel processing loop |

**Guard conditions:** if wheel count (this+0x162C) > 0, process each wheel; otherwise skip.
