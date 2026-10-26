## CameraShake_0040adb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e65c | flt_59E65C | R | CameraShakeMultiplier [DERIVED] (also: ` — camera shake multiplier / conversion factor (docs/09, 19) |
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |
| 0059e6a0 | flt_59E6A0 | R | CollisionProximityScale [DERIVED] |
| 0059e6a4 | flt_59E6A4 | R | MIN_VELOCITY_THRESHOLD [DERIVED] |
| 0059e6a8 | flt_59E6A8 | R | ProximityThresholdSq [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004084a0 | ShortComputation_84a0 | [LLM] |
| 0040c780 | ScoringGateConditionCheck | [LLM] |
| 00456060 | DualFieldGetter | [LLM] |
| 00456080 | ShortComputation_6080 | [LLM] |
| 00457a00 | CollisionResponseWithRandomPerturbation | [LLM] |
| 00457b00 | StateActivatedPositionSaveRestore | [LLM] |
| 00541cd0 | UtilityFunction_1cd0 | [LLM] |
| 00542050 | sub_542050 | [LLM] |
| 005423c0 | TwoFieldSetterCall | [LLM] |
| 00542680 | ConditionalFloatSetter | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
