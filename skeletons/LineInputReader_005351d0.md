## LineInputReader_005351d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_423890 (00423890), sub_491FB0 (00491fb0), SceneFileTEAMDIRVEHDIRNOTSPINWriter (004ddf90), PerWheelBrakeSuspensionDataLoader (004f2c60), FenderAeroSetupSectionReader (004f3090), TheSvmHdvVehicleFileParser (004f4270), ConditionalDispatchBasedOnFlag (00566cc0), VehiclePhysicsJointSystemLoader (0056d930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00534f90 | BufferedFileReader | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
