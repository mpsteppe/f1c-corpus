## TorqueForceProductComputation_00438100 — Torque-force product computation

**Summary:** Computes torque-force product for tire/wheel force application: multiplies a force by a moment arm and adds a bias torque. Single-step arithmetic operation. Part of the vehicle dynamics force accumulation system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleDynamicsForceAccumulatorIntegration (00438130), TireCompoundPerWheelPhysicsApplication (0043da10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x22C | RW | — | Accumulated torque output value |
| this | 0x364 | R | — | Force input value (force component) |
| this | 0x36C | R | — | Moment arm / multiplier input |
| this | 0x374 | RW | — | Intermediate torque-force product |
| this | 0x384 | R | — | Bias torque offset constant |
| this | 0x38C | R | — | Additional scaling factor |

**Written-by note (persistence):**
- this 0x22C: recalc every frame — external poke does NOT persist
- this 0x374: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always executes.
