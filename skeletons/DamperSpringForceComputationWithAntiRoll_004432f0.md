## DamperSpringForceComputationWithAntiRoll_004432f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsIntegrationStep (00441d60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x15F0) | 0x1C | R | — | [LLM] |
| *(this+0x15F0) | 0x24 | R | — | [LLM] |
| *(this+0x15F0) | 0x2C | R | — | [LLM] |
| *(this+0x15F0) | 0x34 | R | — | [LLM] |
| *(this+0x15F0) | 0x3C | R | — | [LLM] |
| *(this+0x15F0) | 0x44 | R | — | [LLM] |
| *(this+0x15F0) | 0x4C | R | — | [LLM] |
| *(this+0x15F0) | 0x54 | R | — | [LLM] |
| *(this+0x15F0) | 0x5C | R | — | [LLM] |
| *(this+0x15F0) | 0x64 | R | — | [LLM] |
| *(this+0x15F0) | 0x6C | R | — | [LLM] |
| *(this+0x15F0) | 0x74 | R | — | [LLM] |
| *(this+0x15F0) | 0x7C | R | — | [LLM] |
| *(this+0x15F0) | 0x84 | R | — | [LLM] |
| *(this+0x15F0) | 0x8C | R | — | [LLM] |
| *(this+0x15F0) | 0x14C | RW | — | [LLM] |
| *(this+0x15F0) | 0x154 | RW | — | [LLM] |
| *(this+0x15F0) | 0x15C | RW | — | [LLM] |
| *(this+0x1F00) | 0xCD4 | R | — | [LLM] |
| *(this+0x1F00) | 0xD14 | R | — | [LLM] |
| *(this+0x1F00) | 0xD18 | R | — | [LLM] |
| *(this+0x1F00) | 0xD58 | R | — | [LLM] |
| *(this+0x1F00) | 0x3A64 | R | — | [LLM] |
| *(this+0x1F00) | 0x3A68 | R | — | [LLM] |
| *(this+0x1F00) | 0x3A6C | R | — | [LLM] |
| this | 0x15F0 | R | — | [LLM] |
| this | 0x16F0 | R | — | [LLM] |
| this | 0x16F8 | R | — | [LLM] |
| this | 0x1700 | R | — | [LLM] |
| this | 0x1708 | R | — | [LLM] |
| this | 0x1900 | R | — | [LLM] |
| this | 0x1908 | RW | 0 | [LLM] |
| this | 0x190C | RW | 0 | [LLM] |
| this | 0x1910 | R | — | [LLM] |
| this | 0x1914 | R | — | [LLM] |
| this | 0x1918 | R | — | [LLM] |
| this | 0x1920 | R | — | [LLM] |
| this | 0x1928 | R | — | [LLM] |
| this | 0x1930 | R | — | [LLM] |
| this | 0x1938 | R | — | [LLM] |
| this | 0x1940 | R | — | [LLM] |
| this | 0x19E0 | RW | — | [LLM] |
| this | 0x1A08 | R | — | [LLM] |
| this | 0x1A0C | R | — | [LLM] |
| this | 0x1A14 | R | — | [LLM] |
| this | 0x1AB4 | RW | — | [LLM] |
| this | 0x1ADC | R | — | [LLM] |
| this | 0x1AE4 | R | — | [LLM] |
| this | 0x1AEC | R | — | [LLM] |
| this | 0x1AF4 | R | — | [LLM] |
| this | 0x1AF8 | R | — | [LLM] |
| this | 0x1B9C | RW | — | [LLM] |
| this | 0x1BBC | R | — | [LLM] |
| this | 0x1BC0 | R | — | [LLM] |
| this | 0x1BC8 | R | — | [LLM] |
| this | 0x1BD0 | R | — | [LLM] |
| this | 0x1BD8 | R | — | [LLM] |
| this | 0x1BE0 | R | — | [LLM] |
| this | 0x1F00 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x15F0) 0x14C: recalc every frame — external poke does NOT persist
- *(this+0x15F0) 0x154: recalc every frame — external poke does NOT persist
- *(this+0x15F0) 0x15C: recalc every frame — external poke does NOT persist
- this 0x1908: recalc every frame — external poke does NOT persist
- this 0x190C: recalc every frame — external poke does NOT persist
- this 0x19E0: recalc every frame — external poke does NOT persist
- this 0x1AB4: recalc every frame — external poke does NOT persist
- this 0x1B9C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00435e00 | Matrix3x3VectorMultiply | [LLM] |
| 00436230 | QuadraticForm6x6 | [LLM] |
| 004388d0 | Mat3x3MulVec | [LLM] |
| 00443150 | WheelContactForceSolver | [LLM] |
| 00569ad0 | AccumulateAngularMomentum | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
