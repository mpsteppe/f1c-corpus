## PerWheelBrakeSuspensionDataLoader_004f2c60 — PerWheelBrakeSuspensionDataLoader

**Summary:** Parses per-wheel brake and suspension configuration data from a vehicle setup file line, populating a double array with spring rates, damper settings, camber, tire pressure, brake temperature/wear/torque parameters, and ride heights; converts brake optimum temperature from Celsius to Kelvin (+273.16).

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TheSvmHdvVehicleFileParser (004f4270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB8 | RW | — | Brake optimum temperature (Kelvin) — parsed from file in Celsius, then offset by +273.16 |

**Written-by note (persistence):**
- this 0xB8: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059eac8 | dbl_59EAC8 | R | ThermalTempOffset [DERIVED] (also: ` = 273.15 (C→K) |
| 005d502c | aBrakepadrange | R | aBrakePadRange [DERIVED] |
| 005d503c | aBrakepadsettin | R | String_BrakePadSetting [DERIVED] |
| 005d504c | aBrakediscrange | R | BrakeDiscRangeString [DERIVED] |
| 005d505c | aBrakediscsetti | R | BrakediscsettiString [DERIVED] |
| 005d5070 | aFastreboundran | R | FastReboundRangeString [DERIVED] |
| 005d5084 | aFastreboundset | R | String_FastReboundSetting [DERIVED] |
| 005d5098 | aSlowreboundran | R | SlowReboundRangeString [DERIVED] |
| 005d50ac | aSlowreboundset | R | SlowReboundSet [DERIVED] |
| 005d50c0 | aFastbumprange | R | FastBumpRangeField [DERIVED] |
| 005d50d0 | aFastbumpsettin | R | FastBumpSettingString [DERIVED] |
| 005d50e0 | aSlowbumprange | R | SlowbumprangeString [DERIVED] |
| 005d50f0 | aSlowbumpsettin | R | SlowbumpsettinString [DERIVED] |
| 005d5100 | aSpringrange | R | Str_Springrange [DERIVED] |
| 005d510c | aSpringsetting | R | StringSpringSetting [DERIVED] |
| 005d511c | aPackerrange | R | PackerRangeString [DERIVED] |
| 005d5128 | aPackersetting | R | PackerSettingString [DERIVED] |
| 005d5138 | aRideheightrang | R | RideheightrangeString [DERIVED] |
| 005d5148 | aRideheightsett | R | RideHeightSettingStr [DERIVED] |
| 005d515c | aPressurerange | R | PressureRangeString [DERIVED] |
| 005d516c | aPressuresettin | R | PressureSettingField [DERIVED] |
| 005d517c | aCamberrange | R | aCamberRange [DERIVED] |
| 005d5188 | aCambersetting | R | String_CamberSetting [DERIVED] |
| 005d5198 | aPushrodbody | R | PushrodBodyString [DERIVED] |
| 005d51a4 | aPushrodspindle | R | PushrodspindleString [DERIVED] |
| 005d51b4 | aCgoffsetx | R | CgOffsetXString [DERIVED] |
| 005d51c0 | aSpininertia | R | String_SpinInertia [DERIVED] |
| 005d51cc | aBrakeductcooli | R | BrakeDuctCoolingString [DERIVED] |
| 005d51e0 | aBrakecooling | R | BrakeCooling [DERIVED] |
| 005d51f0 | aBrakeheating | R | BrakeHeatingField [DERIVED] |
| 005d5200 | aBrakediscinert | R | BrakeDiscInertiaString [DERIVED] |
| 005d5214 | aBrakefaderange | R | BrakefaderangeString [DERIVED] |
| 005d5224 | aBrakeoptimumte | R | BrakeoptimumteString [DERIVED] |
| 005d5238 | aBrakefailure | R | Str_Brakefailure [DERIVED] |
| 005d5248 | aBrakewearrate | R | StringBrakeWearRate [DERIVED] |
| 005d5258 | aBraketorque | R | BrakeTorqueString [DERIVED] |
| 005d5264 | aFrictiontorque | R | FrictionTorqueString [DERIVED] |
| 005d5274 | aReboundstage2 | R | Reboundstage2String [DERIVED] |
| 005d5284 | aBumpstage2 | R | BumpStage2Str [DERIVED] |
| 005d5290 | aBumpstoprising_0 | R | BumpStopRisingString [DERIVED] |
| 005d52a8 | aBumpstopdamper | R | BumpStopDamperField [DERIVED] |
| 005d52b8 | aBumpstoprising | R | aBumpstopRising [DERIVED] |
| 005d52d0 | aBumpstopspring | R | String_BumpStopSpring [DERIVED] |
| 005d52e0 | aReboundtravel | R | ReboundTravelString [DERIVED] |
| 005d52f0 | aBumptravel | R | BumptravelString [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042e1f0 | CRTMathHelper_e1f0 | Parses range/setting string pair from input line, computes final double value with unit-conversion multiplier (deg→rad 0.01745, identity 1.0) |
| 005351d0 | LineInputReader | Reads next token/line from file handle 384; returns 0 when no more data available |
| 005651b0 | sub_5651B0 | Checks for section delimiter/EOF marker in vehicle data stream; returns 1=end-of-section, 0=continue parsing |
| 00565aa0 | sub_565AA0 | Parses a named suspension/brake parameter string from input, storing the matched value into the double array slot |

**Guard conditions:** Outer loop: `LineInputReader(384)` returns 0 → end of file, processing stops. Per-line: `sub_5651B0(a4)` returns 1 → end-of-section marker, breaks loop; returns 0 → valid data line, processes all suspension/brake fields. No guard on this 0xB8 — always written when `sub_565AA0` succeeds for brake optimum temperature, then offset by +273.16 unconditionally.
