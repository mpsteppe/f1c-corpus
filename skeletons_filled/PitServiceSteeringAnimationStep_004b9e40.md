## PitServiceSteeringAnimationStep_004b9e40 — Pit service steering animation state machine

**Summary:** Advances the pit service steering animation by one step. State machine at offset 0xF8C drives direction/speed of steering wheel rotation using queue peek events and FloatAccumulator.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalMultiPathDispatcher (004ba180)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xF8C | RW | 5 | Animation step state (0-8); controls steering direction and speed |
| this | 0x0 | R | — | Pointer to pit service data block |

**Written-by note (persistence):**
- obj 0xF8C: set to 5 after states 0/1 complete; other states leave it unchanged for external progression

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004b9f48 | jpt_4B9E58 | R | Switch jump table for animation states |
| 0059e600 | flt_59E600 | R | SteeringForceThreshold [DERIVED] |
| 005acd14 | flt_5ACD14 | R | CameraMoveMultiplier [DERIVED] |
| 005acd18 | flt_5ACD18 | R | CameraZoomMult [DERIVED] |
| 008afe90 | dbl_8AFE90 | R | EngineCoolingRate (reused as animation speed base) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b86e0 | AngleClampWrap | Clamp/wrap steering angle to valid range |
| 004b87a0 | QueuePeek | Peek next item from input/event queue |
| 004b9d00 | FloatAccumulator | Accumulate float value (speed/position integrator) |

**Guard conditions:** Switch on state at *this+0xF8C. States 0-8 handled; default returns with no action. States 0/1 read queue then transition to state 5. States 2-8 drive FloatAccumulator with scaled rate.
