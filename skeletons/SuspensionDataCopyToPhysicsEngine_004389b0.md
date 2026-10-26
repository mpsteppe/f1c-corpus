## SuspensionDataCopyToPhysicsEngine_004389b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsSubObjectFree (00441450)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xAC | R | — | [LLM] |
| this | 0xBC | R | — | [LLM] |
| this | 0x15C | R | — | [LLM] |
| this | 0x160 | R | — | [LLM] |
| this | 0x1C4 | R | — | [LLM] |
| this | 0x1C5 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005692a0 | F_3x3InertiaTensorTransform | [LLM] |
| 00569410 | InertiaTensorWorldSpaceTransform | [LLM] |
| 0056bd40 | EulerAnglesTo33RotationMatrix | [LLM] |
| 0056bde0 | sub_56BDE0 | [LLM] |
| 0056c2d0 | F_33RotationMatrixAroundXAxis | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
