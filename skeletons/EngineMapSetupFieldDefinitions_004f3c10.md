## EngineMapSetupFieldDefinitions_004f3c10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** EngineSectionParser (004f3c80), TheSvmHdvVehicleFileParser (004f4270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54b4 | aEnginebrakingm_0 | R | EngineBrakingMultString [DERIVED] |
| 005d54cc | aEnginebrakingm | R | EnginebrakingmString [DERIVED] |
| 005d54e4 | aEnginemaprange | R | EngineMapRangeString [DERIVED] |
| 005d54f4 | aEnginemapsetti | R | String_EngineMapSetting [DERIVED] |
| 005d5508 | aRevlimitrange | R | RevLimitRangeString [DERIVED] |
| 005d5518 | aRevlimitsettin | R | RevLimitSetting [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042e1f0 | CRTMathHelper_e1f0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
