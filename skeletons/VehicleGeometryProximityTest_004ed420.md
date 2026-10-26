## VehicleGeometryProximityTest_004ed420 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** F_3DCollisionDetectionWithAABBTestAndContactResp (004ea040), CollisionDetectionSystem (004ea970), VehicleYawRotationRecoveryController (004f1c40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x828 | R | — | [LLM] |
| this | 0x868 | R | — | [LLM] |
| this | 0x34B0 | R | — | [LLM] |
| this | 0x34B4 | R | — | [LLM] |
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] |
| this | 0x34BC | R | — | [LLM] |
| this | 0x34C0 | R | — | [LLM] |
| this | 0x34C4 | R | — | [LLM] |
| this | 0x34C8 | R | — | [LLM] |
| this | 0x34CC | R | — | [LLM] |
| this | 0x34D0 | R | — | [LLM] |
| this | 0x3594 | R | — | [LLM] |
| this | 0x3610 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ea930 | sub_4EA930 | [LLM] |
| 004ed380 | AnisoVectorTripleProduct | [LLM] |
| 004ed710 | Vec3Add | [LLM] |
| 004ed750 | F_3DCrossProduct | [LLM] |
| 004ed7b0 | F_33MatrixVectorMultiply | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
