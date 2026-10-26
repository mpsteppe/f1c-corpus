## F_3x3MatrixInverseCoordinateTransform_0056d020 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsInitializer (00439210), SteeringGeometryUpdate (00442060), VehiclePhysicsJointSystemLoader (0056d930), BatchProcessingLoop3Passes (0056ec00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x28 | RW | — | [LLM] |
| this | 0x30 | RW | — | [LLM] |
| this | 0x38 | RW | — | [LLM] |
| this | 0x40 | RW | — | [LLM] |
| this | 0x48 | RW | — | [LLM] |
| this | 0x50 | RW | — | [LLM] |
| this | 0x58 | RW | — | [LLM] |
| this | 0x60 | RW | — | [LLM] |
| this | 0x68 | RW | — | [LLM] |
| this | 0x70 | RW | — | [LLM] |
| this | 0x78 | RW | — | [LLM] |
| this | 0x80 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x28: recalc every frame — external poke does NOT persist
- this 0x30: recalc every frame — external poke does NOT persist
- this 0x38: recalc every frame — external poke does NOT persist
- this 0x40: recalc every frame — external poke does NOT persist
- this 0x48: recalc every frame — external poke does NOT persist
- this 0x50: recalc every frame — external poke does NOT persist
- this 0x58: recalc every frame — external poke does NOT persist
- this 0x60: recalc every frame — external poke does NOT persist
- this 0x68: recalc every frame — external poke does NOT persist
- this 0x70: recalc every frame — external poke does NOT persist
- this 0x78: recalc every frame — external poke does NOT persist
- this 0x80: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00435e00 | Matrix3x3VectorMultiply | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
