## BrakeTemperatureFadeModel_00430a50 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleStatsEstimationDisplay (00430f00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xBC4 | R | — | [LLM] |
| this | 0xC30 | R | — | [LLM] |
| this | 0xC38 | R | — | [LLM] |
| this | 0xC44 | R | — | [LLM] |
| this | 0xCB0 | R | — | [LLM] |
| this | 0xCB8 | R | — | [LLM] |
| this | 0xCC4 | R | — | [LLM] |
| this | 0x1570 | R | — | [LLM] |
| this | 0x1578 | R | — | [LLM] |
| this | 0x1584 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059ea58 | dbl_59EA58 | R | TireFormulaConstant [DERIVED] (also: /60/50/48 � Tire formula constants) |
| 0059ea60 | dbl_59EA60 | R | DampingFactorB [DERIVED] (also: ` — angular threshold for partial response) |
| 0059ea68 | dbl_59EA68 | R | WheelSpeedFactor [DERIVED] |
| 0059ea70 | dbl_59EA70 | R | SuspForceConst [DERIVED] |
| 0059ea78 | dbl_59EA78 | R | DamperMultiplier [DERIVED] |
| 0059ea80 | dbl_59EA80 | R | AeroBalanceMult [DERIVED] |
| 008ad254 | dword_8AD254 | R | StateFlagPair [DERIVED] |
| 008adb00 | dword_8ADB00 | R | TireModelConstants [DERIVED] (also: /40/60 � Tire model constants (camber, friction, etc.) |
| 008adb40 | dbl_8ADB40 | R | Dbl_TireRoadMu_ADB40 [DERIVED] |
| 008adb88 | unk_8ADB88 | R | TireDatasetHandle [DERIVED] |
| 008ae194 | dbl_8AE194 | R | Double_Unknown_Physics [DERIVED] |
| 008aeec0 | dword_8AEEC0 | R | AeroSuspensionModeSelector [DERIVED] (also: ` — aero/suspension mode selector (0=fixed, 1=blended, 2=fixed-alt) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ed00 | SessionStateIndexedLookup | [LLM] |
| 00430600 | WheelForceAggregate | [LLM] |
| 004d5c70 | QuaternionTransformComputation | [LLM] |
| 004d7570 | CompoundIndexLookup | [LLM] |
| 004d7880 | TireBrandLookup | [LLM] |
| 004f6720 | ParameterizedCurveInterpolation | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
