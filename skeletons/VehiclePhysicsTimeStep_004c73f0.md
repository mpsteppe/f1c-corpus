## VehiclePhysicsTimeStep_004c73f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TeamColorLoader (004f03e0), sub_4F0430 (004f0430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | RW | — | PhysX [FACT] |
| this | 0x20 | RW | — | PhysY [FACT] |
| this | 0x24 | RW | — | PhysZ [FACT] |
| this | 0x58 | RW | — | [LLM] |
| this | 0x5C | RW | — | [LLM] |
| this | 0x60 | RW | — | [LLM] |
| this | 0xA0 | RW | — | EngineAngVel [FACT] |
| this | 0xA4 | RW | — | [LLM] |
| this | 0x8C0 | R | — | [LLM] |
| this | 0x1040 | RW | — | [LLM] |
| this | 0x1044 | R | — | [LLM] |
| this | 0x1054 | R | — | [LLM] |
| this | 0x105D | RW | — | [LLM] |
| this | 0x1065 | RW | — | [LLM] |
| this | 0x1067 | RW | — | [LLM] |
| this | 0x1069 | RW | — | [LLM] |
| this | 0x32C8 | R | — | [LLM] |
| this | 0x344C | RW | — | [LLM] |
| this | 0x3580 | RW | — | [LLM] |
| this | 0x3584 | RW | 0 | BrakeFactor [CONFIRMED] |
| this | 0x35BC | RW | — | [LLM] |
| this | 0x4024 | RW | — | [LLM] |
| this | 0x4028 | RW | — | [LLM] |
| this | 0x48B0 | RW | — | [LLM] |
| this | 0x48B4 | RW | — | [LLM] |
| this | 0x48B8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x1C: recalc every frame — external poke does NOT persist
- this 0x20: recalc every frame — external poke does NOT persist
- this 0x24: recalc every frame — external poke does NOT persist
- this 0x58: recalc every frame — external poke does NOT persist
- this 0x5C: recalc every frame — external poke does NOT persist
- this 0x60: recalc every frame — external poke does NOT persist
- this 0xA0: recalc every frame — external poke does NOT persist
- this 0xA4: recalc every frame — external poke does NOT persist
- this 0x1040: recalc every frame — external poke does NOT persist
- this 0x105D: recalc every frame — external poke does NOT persist
- this 0x1065: recalc every frame — external poke does NOT persist
- this 0x1067: recalc every frame — external poke does NOT persist
- this 0x1069: recalc every frame — external poke does NOT persist
- this 0x344C: recalc every frame — external poke does NOT persist
- this 0x3580: recalc every frame — external poke does NOT persist
- this 0x3584: recalc every frame — external poke does NOT persist
- this 0x35BC: recalc every frame — external poke does NOT persist
- this 0x4024: recalc every frame — external poke does NOT persist
- this 0x4028: recalc every frame — external poke does NOT persist
- this 0x48B0: recalc every frame — external poke does NOT persist
- this 0x48B4: recalc every frame — external poke does NOT persist
- this 0x48B8: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |
| 0059e8d8 | flt_59E8D8 | R | BrakingSpeedThreshold3 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b2420 | ArithmeticComparison_2420 | [LLM] |
| 004b2580 | ShortVectorToFloatWithScale | [LLM] |
| 004b26d0 | FloatTruncation | [LLM] |
| 004b2800 | ShortToFloatVectorUnpack | [LLM] |
| 004b28f0 | sub_4B28F0 | [LLM] |
| 004b2980 | BitfieldExtractScale | [LLM] |
| 004b29f0 | ShortComputation_29f0 | [LLM] |
| 004b2a30 | BitfieldExtract | [LLM] |
| 004b2a80 | BitfieldToFloatConversion | [LLM] |
| 004b2ad0 | BitTest | [LLM] |
| 004e0ed0 | AudioSoundEffectController | [LLM] |
| 004e17c0 | SubsystemStateMachine | [LLM] |
| 004e2230 | VibrationStateMachine | [LLM] |
| 004e23d0 | F_3x3MatrixTransform | [LLM] |
| 004e24a0 | SuspensionParamUpdate | [LLM] |
| 004f1650 | VehicleSetupDataCopy | [LLM] |
| 004f17a0 | EffectParameterSetter | [LLM] |
| 004f17d0 | MatrixVectorSetup | [LLM] |
| 00566e40 | EulerToRotationMatrix | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
