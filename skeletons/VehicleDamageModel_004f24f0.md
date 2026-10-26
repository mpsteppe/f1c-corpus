## VehicleDamageModel_004f24f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TheSvmHdvVehicleFileParser (004f4270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c316c | aEngine | R | ComponentNameEngine [DERIVED] |
| 005d4e90 | aPartDcollparam | R | PartDCollParamString [DERIVED] |
| 005d4ea4 | aPartDmassinert | R | String_PartDMassInert [DERIVED] |
| 005d4eb8 | aPartDpos | R | PartDPosString [DERIVED] |
| 005d4ec4 | aPartDrandom | R | PartDRandom [DERIVED] |
| 005d4ed4 | aPartDdetach | R | PartDDetachField [DERIVED] |
| 005d4ee4 | aWheelDcollpara | R | WheelCollParamString [DERIVED] |
| 005d4ef8 | aWheelDmassiner | R | WheelDmassinerString [DERIVED] |
| 005d4f0c | aWheelrandom | R | WheelrandomString [DERIVED] |
| 005d4f18 | aWheeldetach | R | Str_Wheeldetach [DERIVED] |
| 005d4f24 | aWheelbend | R | StringWheelBend [DERIVED] |
| 005d4f30 | aRearwingcollpa | R | RearWingCollPanelString [DERIVED] |
| 005d4f44 | aRearwingmassin | R | RearWingMassString [DERIVED] |
| 005d4f58 | aRearwingpos | R | RearwingposString [DERIVED] |
| 005d4f64 | aRearwingrandom | R | RearWingRandomStr [DERIVED] |
| 005d4f74 | aRearwingdetach | R | RearWingDetachString [DERIVED] |
| 005d4f84 | aFrontwingcollp | R | FrontWingCollpField [DERIVED] |
| 005d4f98 | aFrontwingmassi | R | aFrontWingMass [DERIVED] |
| 005d4fb0 | aFrontwingpos | R | String_FrontWingPos [DERIVED] |
| 005d4fc0 | aFrontwingrando | R | FrontWingRandomString [DERIVED] |
| 005d4fd0 | aFrontwingdetac | R | FrontwingdetacString [DERIVED] |
| 005d4fe0 | aVertmult | R | VertMultString [DERIVED] |
| 005d4fec | aAeromin | R | String_AeroMin [DERIVED] |
| 005d4ff4 | aAerodiv | R | AeroDivString [DERIVED] |
| 005d4ffc | aRadiusmax | R | RadiusMax [DERIVED] |
| 005d5008 | aRadiusmult | R | RadiusMultField [DERIVED] |
| 005d5014 | aRadiusadd | R | RadiusAddString [DERIVED] |
| 005d5020 | aPhysical | R | PhysicalString [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005651b0 | sub_5651B0 | [LLM] |
| 00565870 | sub_565870 | [LLM] |
| 005668b0 | ZeroInitSmallStruct | [LLM] |
| 005668d0 | SubCallWithConditionalFieldFree | [LLM] |
| 00566b20 | AudioStreamOpen | [LLM] |
| 00566b90 | ConditionalFileHandleCloseWithFlagDispatch | [LLM] |
| 00566cc0 | ConditionalDispatchBasedOnFlag | [LLM] |
| 00587c20 | sub_587C20 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
