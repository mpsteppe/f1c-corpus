## SuspensionSpringDamperForceComputationWithClampi_00435e60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** GetBodyMotionState (00447100)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x34 | R | — | [LLM] |
| this | 0x3C | R | — | [LLM] |
| this | 0x44 | R | — | [LLM] |
| this | 0x64 | R | — | [LLM] |
| this | 0x68 | R | — | [LLM] |
| this | 0x6C | R | — | [LLM] |
| this | 0x74 | R | — | [LLM] |
| this | 0x7C | R | — | [LLM] |
| this | 0x80 | R | — | [LLM] |
| this | 0x84 | R | — | [LLM] |
| this | 0x8C | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 007cfb48 | flt_7CFB48 | R | CollisionForceClampFactor [DERIVED] |
| 007cfb6c | flt_7CFB6C | R | Flt_PhysicsClamp [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004361d0 | F_3DVectorTransformBy33Matrix | [LLM] |
| 0056c740 | F_33MatrixMultiply | [LLM] |
| 00588570 | FloatConvertWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
