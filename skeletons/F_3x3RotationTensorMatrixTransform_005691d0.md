## F_3x3RotationTensorMatrixTransform_005691d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsStateVectorConversion (0040ef70), sub_438F00 (00438f00), VehiclePhysicsInitializer (00439210), sub_43C250 (0043c250), FloatDoubleCoordinateTransform (00459830), VehiclePhysicsJointSystemLoader (0056d930), sub_56F100 (0056f100)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x7C | RW | — | [LLM] |
| this | 0x84 | RW | — | [LLM] |
| this | 0x8C | RW | — | [LLM] |
| this | 0x94 | R | — | [LLM] |
| this | 0x9C | R | — | [LLM] |
| this | 0xA4 | R | — | [LLM] |
| this | 0xEC | R | — | [LLM] |
| this | 0xF4 | R | — | [LLM] |
| this | 0xFC | R | — | [LLM] |
| this | 0x104 | R | — | [LLM] |
| this | 0x10C | R | — | [LLM] |
| this | 0x114 | R | — | [LLM] |
| this | 0x11C | R | — | [LLM] |
| this | 0x124 | R | — | [LLM] |
| this | 0x12C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x7C: recalc every frame — external poke does NOT persist
- this 0x84: recalc every frame — external poke does NOT persist
- this 0x8C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005692a0 | F_3x3InertiaTensorTransform | [LLM] |
| 0056bd40 | EulerAnglesTo33RotationMatrix | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
