## EngineMapSetupFieldDefinitions_004f3c10 — engine map range/setting field definitions

**Summary:** Registers three engine parameter range/setting pairs (rev limit, engine map, engine braking multiplier) with CRTMathHelper for vehicle file parsing. Applies scale factor for RPM conversion.

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
| 0042e1f0 | CRTMathHelper_e1f0 | registers or computes range/setting pair with scale factor (0.10472 = PI/30 for RPM) |

**Guard conditions:** None — always executes all three registration calls unconditionally.
