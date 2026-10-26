## SwitchBasedStateHandler_0040f380 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ProximityCheckWithTagUpdate (004bda20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x20) | 0x48BC | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0xF0 | R | — | [LLM] |
| this | 0x158 | R | — | [LLM] |
| this | 0x160 | R | — | [LLM] |
| this | 0x168 | R | — | [LLM] |
| this | 0x708 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040f484 | jpt_40F393 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e9a40 | VehicleBodyToWheelContactDistanceComputation | [LLM] |
| 004ea040 | F_3DCollisionDetectionWithAABBTestAndContactResp | [LLM] |
| 0054f7a0 | UIFocusChange | [LLM] |
| 0054fb40 | SceneNodeVisibilityToggle | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
