## DeltaUpdateTracking_0043bb00 — Delta update tracking with smoothing

**Summary:** Tracks a value's delta (change between frames), applies exponential smoothing, and accumulates the result. Used for smoothing physics parameters over time. Part of the physics update system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsInitializer (00439210), SolverDispatch (0043b930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xD4C | RW | — | Accumulated smoothed delta value |
| this | 0x1428 | RW | — | Previous frame value (for delta computation) |
| this | 0x1430 | R | — | Smoothing factor (coefficient for exponential smoothing) |

**Written-by note (persistence):**
- this 0xD4C: recalc every frame — external poke does NOT persist
- this 0x1428: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always executes.
