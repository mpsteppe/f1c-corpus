## sub_4FD8B0_004fd8b0 — CameraOscillationGenerator

**Summary:** Generates a linked list of oscillation samples for camera sway/vehicle shake, using random noise values with multi-stage clamping, sinusoidal motion computation, and physics-constant-driven amplitude limits.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCAA0 (004fcaa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x44) | 0x0 | RW | — | accumulated position value in linked list node (float, starts at 0, incremented per node) |
| this | 0x38 | RW | — | pointer to current list node (traversal cursor) |
| this | 0x3C | RW | — | pointer to list head (first allocated node) |
| this | 0x40 | RW | 1058642330 → 0.6f | float threshold for mid-range value snapping (0.6f to 0.625f → 0.65f rounding) |
| this | 0x44 | RW | — | pointer to list head (dup, holds allocated FloatArrayInitializer result) |

**Written-by note (persistence):**
- *(this+0x44) 0x0: set once at list head creation, then updated per-node during traversal
- this 0x38: set each call to list head, then advanced per iteration through linked list
- this 0x3C: set each call to allocated list head pointer
- this 0x40: set each call to 0.6f threshold (constant init)
- this 0x44: set each call to allocated list head pointer

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e4e8 | flt_59E4E8 | R | PhysicsScale_E4E8 [DERIVED] (also: ` — physics/math scaling constant) |
| 0059e5fc | flt_59E5FC | R | FrameRateCorrectionFactor [DERIVED] (also:  â€” global frame-rate correction) |
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |
| 0059e7f0 | flt_59E7F0 | R | DefaultFromTableSentinel [DERIVED] (also: ` — sentinel value (use default from table) |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |
| 0059e814 | flt_59E814 | R | OscillationMax [DERIVED] |
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: ` — display message threshold) |
| 0059e868 | flt_59E868 | R | SteeringResponseGain [DERIVED] |
| 0059e8b4 | flt_59E8B4 | R | ClampUpperThreshold [DERIVED] |
| 0059e8c8 | flt_59E8C8 | R | Physics_ConvergenceThreshold [DERIVED] (also: ` — convergence threshold (terminates iteration) |
| 0059e8d8 | flt_59E8D8 | R | BrakingSpeedThreshold3 [DERIVED] |
| 0059e8f0 | flt_59E8F0 | R | AudioDopplerFactor [DERIVED] |
| 0059e8f8 | flt_59E8F8 | R | PhysicsConst_59E8F8 [DERIVED] |
| 0059e91c | flt_59E91C | R | ShortConversionMult [DERIVED] (also: conversion multipliers) |
| 0059e920 | flt_59E920 | R | SuspensionAntirollFactor [DERIVED] |
| 005acb0c | flt_5ACB0C | R | Flt_ViewportConstant [DERIVED] |
| 005ad148 | flt_5AD148 | R | ContactProximityThreshold [DERIVED] |
| 005ad184 | flt_5AD184 | R | SteeringFilterThreshold [DERIVED] |
| 005ad2b8 | dbl_5AD2B8 | R | SteeringNoise_dbl_5AD2B8 [DERIVED] |
| 005ad2d4 | flt_5AD2D4 | R | VehicleUpdateFloat [DERIVED] |
| 005ad2d8 | flt_5AD2D8 | R | WanderRandomScale [DERIVED] |
| 005ad2dc | flt_5AD2DC | R | SteeringPerturbThreshold [DERIVED] |
| 005ad2e0 | flt_5AD2E0 | R | Steering_NoiseScale [DERIVED] |
| 005ad2e4 | flt_5AD2E4 | R | ShakeAmplitudeConst [DERIVED] |
| 005ad2e8 | flt_5AD2E8 | R | CameraSwayScale [DERIVED] |
| 005ad2f0 | dbl_5AD2F0 | R | UnknownDoubleConst5 [DERIVED] |
| 005ad2f8 | flt_5AD2F8 | R | RainDropScale [DERIVED] |
| 005ad2fc | flt_5AD2FC | R | LowerClampNeg [DERIVED] |
| 005ad300 | flt_5AD300 | R | UpperClampNeg [DERIVED] |
| 008aae70 | dword_8AAE70 | R | RingBufferCounter (QA/weather noise) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b3ce0 | RandomNoiseValueGenerator | generates pseudo-random noise value using ring buffer counter for oscillation variation |
| 004fc9a0 | FloatArrayInitializer | initializes a 16-byte float array struct (4 floats) for linked list node |
| 004fd840 | DualLinkedListDestruction | destroys/cleans up existing linked list before rebuilding |
| 00587c03 | OperatorNewNhMallocWrapper | no-throw malloc/new wrapper for allocating 16-byte list nodes |
| 0058957a | InterruptDispatch | interrupt/synchronization dispatch, ensures thread-safe state during generation |

**Guard conditions:** no top-level early-return guard. Function always executes. Loop terminates when accumulated position exceeds threshold a3. Internal range checks for special case: if accumulated value at node+8 is between 0.6f and 0.65f, snaps to 0.625f (low) or 0.6f (high). Special distance case: if accumulated angle between 28800 and 57600, tightens oscillation amplitude range from ±900 to ±280.