## TorqueForceProductComputation_00438100 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleDynamicsForceAccumulatorIntegration (00438130), TireCompoundPerWheelPhysicsApplication (0043da10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x22C | RW | — | [LLM] |
| this | 0x364 | R | — | [LLM] |
| this | 0x36C | R | — | [LLM] |
| this | 0x374 | RW | — | [LLM] |
| this | 0x384 | R | — | [LLM] |
| this | 0x38C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x22C: recalc every frame — external poke does NOT persist
- this 0x374: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
