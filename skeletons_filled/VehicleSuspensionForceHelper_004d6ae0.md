## VehicleSuspensionForceHelper_004d6ae0 — SuspensionForceTemperatureScaler

**Summary:** Computes suspension force scaled by temperature: ((this[35] + 273.16) * a2 * 0.002778858444950814 * this[8]) + this[7]. Converts temperature from Celsius to Kelvin, multiplies by input factor, a position scaling constant, and an offset.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsInitializer (00439210), TireCompoundPerWheelPhysicsApplication (0043da10), SuspensionAndWheelPhysics (004e5f60), sub_4F18C0 (004f18c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x38 | R | — | temperature value (Celsius, offset 7 in double array) |
| this | 0x40 | R | — | position/scaling factor (offset 8 in double array) |
| this | 0x118 | R | — | additive offset term (offset 35 in double array) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059eac8 | dbl_59EAC8 | R | ThermalTempOffset [DERIVED] (also: ` = 273.15 (C→K) |
| 0059eb40 | dbl_59EB40 | R | PositionScalingConstant [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None; always computes result from inputs.
