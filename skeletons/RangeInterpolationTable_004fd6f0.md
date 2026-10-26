## RangeInterpolationTable_004fd6f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StructInitWithFloatDefaults (004fc9c0), sub_4FCC30 (004fcc30), AudioADSREnvelope (004fdeb0), CarPositionTargetCheck (004fe060)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x28 | R | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x64 | RW | — | [LLM] |
| this | 0x68 | RW | — | [LLM] |
| this | 0x6C | RW | — | [LLM] |
| this | 0x70 | RW | — | [LLM] |
| this | 0x74 | RW | — | [LLM] |
| this | 0x78 | RW | — | [LLM] |
| this | 0x7C | RW | — | [LLM] |
| this | 0x80 | RW | — | [LLM] |
| this | 0x84 | RW | — | [LLM] |
| this | 0x88 | RW | — | [LLM] |
| this | 0x8C | RW | — | [LLM] |
| this | 0x90 | RW | — | [LLM] |
| this | 0x94 | RW | — | [LLM] |
| this | 0x98 | RW | — | [LLM] |
| this | 0x9C | RW | — | [LLM] |
| this | 0xA0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x64: [LLM: once/conditional? does external poke survive?]
- this 0x68: [LLM: once/conditional? does external poke survive?]
- this 0x6C: [LLM: once/conditional? does external poke survive?]
- this 0x70: [LLM: once/conditional? does external poke survive?]
- this 0x74: [LLM: once/conditional? does external poke survive?]
- this 0x78: [LLM: once/conditional? does external poke survive?]
- this 0x7C: [LLM: once/conditional? does external poke survive?]
- this 0x80: [LLM: once/conditional? does external poke survive?]
- this 0x84: [LLM: once/conditional? does external poke survive?]
- this 0x88: [LLM: once/conditional? does external poke survive?]
- this 0x8C: [LLM: once/conditional? does external poke survive?]
- this 0x90: [LLM: once/conditional? does external poke survive?]
- this 0x94: [LLM: once/conditional? does external poke survive?]
- this 0x98: [LLM: once/conditional? does external poke survive?]
- this 0x9C: [LLM: once/conditional? does external poke survive?]
- this 0xA0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 0059e448 | flt_59E448 | R | TileSteppingMultiplier [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e454 | flt_59E454 | R | PhysicsConstant_59E454 [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059e7fc | flt_59E7FC | R | BumpDampingConstant [DERIVED] (also: ` — bump damping constants) |
| 005acd48 | flt_5ACD48 | R | TireGripThreshold [DERIVED] |
| 005acdc0 | flt_5ACDC0 | R | InterpFactor_5ACDC0 [DERIVED] |
| 005ad150 | flt_5AD150 | R | AITimerRandomScale [DERIVED] |
| 005ad2c0 | flt_5AD2C0 | R | InterpCoeff [DERIVED] |
| 005ad2c4 | flt_5AD2C4 | R | Flt_InterpolationCoeff [DERIVED] |
| 005ad2c8 | flt_5AD2C8 | R | CameraFOVCoeff [DERIVED] |
| 005ad2cc | flt_5AD2CC | R | WheelSpeedCoeff [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
