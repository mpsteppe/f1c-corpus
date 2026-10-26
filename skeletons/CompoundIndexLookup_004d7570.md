## CompoundIndexLookup_004d7570 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** RandomWeightedTierSelection (00429fd0), VehicleSetupValueFormatter (0042f470), sub_430750 (00430750), BrakeTemperatureFadeModel (00430a50), TireSuspensionForceComputation (00431850), VehiclePhysicsInitializer (00439210), TireCompoundPerWheelPhysicsApplication (0043da10), PitPartStateCopy (004a5330), NthValidPartLookup (004a5820), PitStopOperationTimer (004a6340), SuspensionAndWheelPhysics (004e5f60), TireNameAccessor (004f1630), sub_4F18C0 (004f18c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d45e4 | aDDevF119992002_4 | R | SourcePath_F1_1999_2002_4 [DERIVED] |
| 005d4950 | aTireBrandDoesn | R | StringTireBrandDoesn [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
