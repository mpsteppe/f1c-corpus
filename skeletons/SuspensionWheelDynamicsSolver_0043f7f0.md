## SuspensionWheelDynamicsSolver_0043f7f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** WheelDataCopy (004414d0), PhysicsStepFrame (00441600)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1114) | 0x1C | R | — | [LLM] |
| *(this+0x1114) | 0x34 | R | — | [LLM] |
| *(this+0x1114) | 0x4C | R | — | [LLM] |
| *(this+0x141C) | 0x2C | R | — | [LLM] |
| *(this+0x141C) | 0x44 | R | — | [LLM] |
| *(this+0x141C) | 0x5C | R | — | [LLM] |
| *(this+0x141C) | 0x14C | RW | — | [LLM] |
| *(this+0x141C) | 0x154 | RW | — | [LLM] |
| *(this+0x141C) | 0x15C | RW | — | [LLM] |
| *(this+0x15F0) | 0x2C | R | — | [LLM] |
| *(this+0x15F0) | 0x44 | R | — | [LLM] |
| *(this+0x15F0) | 0x5C | R | — | [LLM] |
| *(this+0x15F0) | 0x14C | RW | — | [LLM] |
| *(this+0x15F0) | 0x154 | RW | — | [LLM] |
| *(this+0x15F0) | 0x15C | RW | — | [LLM] |
| *(this+0x3E8) | 0x1C | R | — | [LLM] |
| *(this+0x3E8) | 0x34 | R | — | [LLM] |
| *(this+0x3E8) | 0x4C | R | — | [LLM] |
| *(this+0x84C) | 0x1C | R | — | [LLM] |
| *(this+0x84C) | 0x34 | R | — | [LLM] |
| *(this+0x84C) | 0x4C | R | — | [LLM] |
| *(this+0xCB0) | 0x1C | R | — | [LLM] |
| *(this+0xCB0) | 0x34 | R | — | [LLM] |
| *(this+0xCB0) | 0x4C | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x348 | RW | 0 | [LLM] |
| this | 0x34C | RW | 0 | [LLM] |
| this | 0x360 | R | — | [LLM] |
| this | 0x364 | R | — | [LLM] |
| this | 0x368 | R | — | [LLM] |
| this | 0x3E8 | R | — | [LLM] |
| this | 0x3EC | R | — | [LLM] |
| this | 0x660 | RW | 0 | [LLM] |
| this | 0x664 | RW | 0 | [LLM] |
| this | 0x668 | R | — | [LLM] |
| this | 0x7AC | R | — | [LLM] |
| this | 0x7C4 | R | — | [LLM] |
| this | 0x84C | R | — | [LLM] |
| this | 0xC10 | R | — | [LLM] |
| this | 0xC28 | R | — | [LLM] |
| this | 0xC2C | R | — | [LLM] |
| this | 0xC30 | R | — | [LLM] |
| this | 0xCB0 | R | — | [LLM] |
| this | 0x1074 | R | — | [LLM] |
| this | 0x108C | R | — | [LLM] |
| this | 0x1114 | R | — | [LLM] |
| this | 0x141C | R | — | [LLM] |
| this | 0x15F0 | R | — | [LLM] |
| this | 0x1C5C | RW | — | [LLM] |
| this | 0x1C60 | RW | — | [LLM] |
| this | 0x1C74 | R | — | [LLM] |
| this | 0x1CF4 | R | — | [LLM] |
| this | 0x1CFC | R | — | [LLM] |
| this | 0x1D00 | RW | — | [LLM] |
| this | 0x1D04 | RW | — | [LLM] |
| this | 0x1E14 | R | — | [LLM] |
| this | 0x1E18 | R | — | [LLM] |
| this | 0x1E20 | R | — | [LLM] |
| this | 0x1E28 | R | — | [LLM] |
| this | 0x1E30 | R | — | [LLM] |
| this | 0x1E38 | RW | — | [LLM] |
| this | 0x1E3C | R | — | [LLM] |
| this | 0x1E50 | R | — | [LLM] |
| this | 0x1E54 | R | — | [LLM] |
| this | 0x1E58 | R | — | [LLM] |
| this | 0x1E68 | R | — | [LLM] |
| this | 0x1E6C | R | — | [LLM] |
| this | 0x1E70 | R | — | [LLM] |
| this | 0x1EA4 | R | — | [LLM] |
| this | 0x1EF0 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x141C) 0x14C: recalc every frame — external poke does NOT persist
- *(this+0x141C) 0x154: recalc every frame — external poke does NOT persist
- *(this+0x141C) 0x15C: recalc every frame — external poke does NOT persist
- *(this+0x15F0) 0x14C: recalc every frame — external poke does NOT persist
- *(this+0x15F0) 0x154: recalc every frame — external poke does NOT persist
- *(this+0x15F0) 0x15C: recalc every frame — external poke does NOT persist
- this 0x348: recalc every frame — external poke does NOT persist
- this 0x34C: recalc every frame — external poke does NOT persist
- this 0x660: recalc every frame — external poke does NOT persist
- this 0x664: recalc every frame — external poke does NOT persist
- this 0x1C5C: recalc every frame — external poke does NOT persist
- this 0x1C60: recalc every frame — external poke does NOT persist
- this 0x1D00: recalc every frame — external poke does NOT persist
- this 0x1D04: recalc every frame — external poke does NOT persist
- this 0x1E38: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059e900 | dbl_59E900 | R | Physics_Double_59E900 [DERIVED] |
| 0059eb50 | dbl_59EB50 | R | InputScaleFactor [DERIVED] |
| 0059ec10 | dbl_59EC10 | R | DoublePhysicsZero [DERIVED] |
| 0059ed08 | dbl_59ED08 | R | DissipationConstant [DERIVED] (also: ` — type 1 dissipation) |
| 0059ed10 | dbl_59ED10 | R | TimeStepScale [DERIVED] (also: time-step scaling factor) |
| 0059ed18 | flt_59ED18 | R | ForceReductionFactor [DERIVED] |
| 0059ed20 | dbl_59ED20 | R | EnergyDissipationMult [DERIVED] (also: ` — energy dissipation) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00435290 | FloatEpsilonCompare | [LLM] |
| 00438930 | ConstraintProjectGramSchmidt | [LLM] |
| 005677b0 | sub_5677B0 | [LLM] |
| 005895a2 | sub_5895A2 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
