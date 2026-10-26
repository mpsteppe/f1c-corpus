## UICameraModeDispatchWithVehicleDataRead_0040f550 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ParticleEffectUpdateDispatch (004eb430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x20) | 0x34D4 | R | — | [LLM] |
| *(this+0x20) | 0x34D8 | R | — | [LLM] |
| *(this+0x20) | 0x34DC | R | — | [LLM] |
| this | 0xA | RW | 1 | [LLM] |
| this | 0xC | RW | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xA: recalc every frame — external poke does NOT persist
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x14: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040f5dc | jpt_40F55B | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00459a40 | PhysicsStateIntegration | [LLM] |
| 004ec080 | VehicleTelemetryPositionAccumulator | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
