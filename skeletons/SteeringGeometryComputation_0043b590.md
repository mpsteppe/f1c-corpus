## SteeringGeometryComputation_0043b590 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsInitializer (00439210)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1630) | 0x0 | R | — | [LLM] |
| *(this+0x1630) | 0x4 | R | — | [LLM] |
| *(this+0x1644) | 0x0 | R | — | [LLM] |
| *(this+0x1644) | 0x4 | R | — | [LLM] |
| this | 0x84 | RW | 0 | [LLM] |
| this | 0x88 | RW | 0 | [LLM] |
| this | 0x8C | RW | 0 | [LLM] |
| this | 0x90 | RW | 0 | [LLM] |
| this | 0x94 | RW | — | [LLM] |
| this | 0xA4 | RW | 0 | [LLM] |
| this | 0xA8 | RW | 0 | [LLM] |
| this | 0x3EC | R | — | [LLM] |
| this | 0x850 | R | — | [LLM] |
| this | 0x15F0 | R | — | [LLM] |
| this | 0x1630 | R | — | [LLM] |
| this | 0x1634 | RW | — | [LLM] |
| this | 0x1638 | RW | — | [LLM] |
| this | 0x163C | RW | — | [LLM] |
| this | 0x1644 | R | — | [LLM] |
| this | 0x1648 | RW | — | [LLM] |
| this | 0x164C | RW | — | [LLM] |
| this | 0x1650 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x84: recalc every frame — external poke does NOT persist
- this 0x88: recalc every frame — external poke does NOT persist
- this 0x8C: recalc every frame — external poke does NOT persist
- this 0x90: recalc every frame — external poke does NOT persist
- this 0x94: recalc every frame — external poke does NOT persist
- this 0xA4: recalc every frame — external poke does NOT persist
- this 0xA8: recalc every frame — external poke does NOT persist
- this 0x1634: recalc every frame — external poke does NOT persist
- this 0x1638: recalc every frame — external poke does NOT persist
- this 0x163C: recalc every frame — external poke does NOT persist
- this 0x1648: recalc every frame — external poke does NOT persist
- this 0x164C: recalc every frame — external poke does NOT persist
- this 0x1650: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e428 | dbl_59E428 | R | NaNInvalidSentinel [DERIVED] (also: NaN sentinel constant) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059ec10 | dbl_59EC10 | R | DoublePhysicsZero [DERIVED] |
| 005c41bc | aFrSteering | R | ParamName_FrSteering [DERIVED] |
| 005c41c8 | aFlSteering | R | StrFLSteering [DERIVED] |
| 005c42b4 | aFrForeLower | R | String_FrForeLower [DERIVED] |
| 005c42c4 | aFrForeUpper | R | FrForeUpperString [DERIVED] |
| 005c42d4 | aFlForeLower | R | FlForeLowerString [DERIVED] |
| 005c42e4 | aFlForeUpper | R | FlForeUpperString [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004361d0 | F_3DVectorTransformBy33Matrix | [LLM] |
| 0043af50 | SuspensionBarLookup | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
