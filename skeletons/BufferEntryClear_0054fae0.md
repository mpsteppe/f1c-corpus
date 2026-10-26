## BufferEntryClear_0054fae0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** FloatDoubleCoordinateTransform (00459830), VehiclePhysicsVelocityAngularVelocityIntegrator (00459ae0), TimerFrameRateThrottle (004d3740), TrackTemperatureDisplay (004d37b0), AIRacingLinePathFollowing (004e9ca0), CollisionDetectionSystem (004ea970)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1E8) | 0x0 | RW | — | [LLM] |
| *(this+0x1E8) | 0x40 | RW | 0 | [LLM] |
| this | 0x1E0 | R | — | [LLM] |
| this | 0x1E4 | R | — | [LLM] |
| this | 0x1E8 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x1E8) 0x0: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x40: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1E4 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
