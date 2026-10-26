## RandomPhysicsParameterGenerator_00447b10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** Gearbox (00443b70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x19C | R | — | [LLM] |
| this | 0x1C59 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059eb38 | dbl_59EB38 | R | Physics_Double_59EB38 [DERIVED] |
| 0059eba0 | dbl_59EBA0 | R | EnergyToDamageScaleFactor [DERIVED] (also: ` — energy-to-damage conversion factor) |
| 0059eef8 | dbl_59EEF8 | R | OilTempBlendFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00447ab0 | TrigTableLookup | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
