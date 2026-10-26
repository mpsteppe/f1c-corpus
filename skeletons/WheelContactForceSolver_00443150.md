## WheelContactForceSolver_00443150 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** DamperSpringForceComputationWithAntiRoll (004432f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x15F0 | R | — | [LLM] |
| this | 0x160C | R | — | [LLM] |
| this | 0x1614 | R | — | [LLM] |
| this | 0x161C | R | — | [LLM] |
| this | 0x1624 | R | — | [LLM] |
| this | 0x162C | R | — | [LLM] |
| this | 0x1634 | R | — | [LLM] |
| this | 0x163C | R | — | [LLM] |
| this | 0x1644 | R | — | [LLM] |
| this | 0x164C | R | — | [LLM] |
| this | 0x1654 | R | — | [LLM] |
| this | 0x165C | R | — | [LLM] |
| this | 0x1664 | R | — | [LLM] |
| this | 0x166C | R | — | [LLM] |
| this | 0x1674 | R | — | [LLM] |
| this | 0x167C | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00435e00 | Matrix3x3VectorMultiply | [LLM] |
| 004388d0 | Mat3x3MulVec | [LLM] |
| 00569ad0 | AccumulateAngularMomentum | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
