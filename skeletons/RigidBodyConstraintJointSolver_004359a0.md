## RigidBodyConstraintJointSolver_004359a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsIntegrationStep (00441d60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | [LLM] |
| obj | 0xC | R | — | [LLM] |
| obj | 0x14 | R | — | [LLM] |
| obj | 0x64 | R | — | [LLM] |
| obj | 0x6C | R | — | [LLM] |
| obj | 0x74 | R | — | [LLM] |
| obj | 0x7C | R | — | [LLM] |
| obj | 0x84 | R | — | [LLM] |
| obj | 0x8C | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x98 | R | — | [LLM] |
| this | 0x9C | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00435e00 | Matrix3x3VectorMultiply | [LLM] |
| 00569ad0 | AccumulateAngularMomentum | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x98 | <= | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
