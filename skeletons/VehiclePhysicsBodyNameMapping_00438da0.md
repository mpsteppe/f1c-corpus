## VehiclePhysicsBodyNameMapping_00438da0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TireModelInit (0043e050)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1D4 | RW | — | [LLM] |
| this | 0x1E8 | RW | — | [LLM] |
| this | 0x3E8 | RW | — | [LLM] |
| this | 0x3EC | RW | — | [LLM] |
| this | 0x84C | RW | — | [LLM] |
| this | 0x850 | RW | — | [LLM] |
| this | 0xCB0 | RW | — | [LLM] |
| this | 0xCB4 | RW | — | [LLM] |
| this | 0x1114 | RW | — | [LLM] |
| this | 0x1118 | RW | — | [LLM] |
| this | 0x141C | RW | — | [LLM] |
| this | 0x15AC | R | — | [LLM] |
| this | 0x15F0 | RW | — | [LLM] |
| this | 0x162C | RW | — | [LLM] |
| this | 0x1630 | RW | — | [LLM] |
| this | 0x1644 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x1D4: recalc every frame — external poke does NOT persist
- this 0x1E8: recalc every frame — external poke does NOT persist
- this 0x3E8: recalc every frame — external poke does NOT persist
- this 0x3EC: recalc every frame — external poke does NOT persist
- this 0x84C: recalc every frame — external poke does NOT persist
- this 0x850: recalc every frame — external poke does NOT persist
- this 0xCB0: recalc every frame — external poke does NOT persist
- this 0xCB4: recalc every frame — external poke does NOT persist
- this 0x1114: recalc every frame — external poke does NOT persist
- this 0x1118: recalc every frame — external poke does NOT persist
- this 0x141C: recalc every frame — external poke does NOT persist
- this 0x15F0: recalc every frame — external poke does NOT persist
- this 0x162C: recalc every frame — external poke does NOT persist
- this 0x1630: recalc every frame — external poke does NOT persist
- this 0x1644: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c4138 | aDriverHead | R | String_DriverHead [DERIVED] |
| 005c4144 | aFuelTank | R | FuelTankString [DERIVED] |
| 005c4150 | aRearAxle | R | RearAxleString [DERIVED] |
| 005c415c | aRrSpindle | R | RrSpindleString [DERIVED] |
| 005c4168 | aRrWheel | R | String_RrWheel [DERIVED] |
| 005c4174 | aRlSpindle | R | s_SuspensionRLSpindle [DERIVED] |
| 005c4180 | aRlWheel | R | RLWheel [DERIVED] |
| 005c418c | aFrSpindle | R | FrSpindleField [DERIVED] |
| 005c4198 | aFrWheel | R | FrWheelString [DERIVED] |
| 005c41a4 | aFlSpindle | R | FlSpindleString [DERIVED] |
| 005c41b0 | aFlWheel | R | FlWheelString [DERIVED] |
| 005c41bc | aFrSteering | R | ParamName_FrSteering [DERIVED] |
| 005c41c8 | aFlSteering | R | StrFLSteering [DERIVED] |
| 005c41d4 | aBody_0 | R | Str_Body [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0056d930 | VehiclePhysicsJointSystemLoader | [LLM] |
| 0056ead0 | LinearSearchWithLargeStructStride | [LLM] |
| 0056eb30 | LinearSearchInStructArrayByString | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
