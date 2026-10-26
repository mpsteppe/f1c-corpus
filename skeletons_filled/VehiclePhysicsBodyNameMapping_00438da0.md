## VehiclePhysicsBodyNameMapping_00438da0 — VehiclePhysicsBodyIndexInit

**Summary:** Initializes the vehicle physics body/joint name-to-index mapping by searching the joint system for named bodies (wheels, spindles, axles, steering arms, fuel tank, driver head, body) and storing their array indices for fast lookup during simulation. Part of the tire model initialization pipeline.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TireModelInit (0043e050)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1D4 | RW | — | fuelTankIndex — array index of the fuel tank physics body |
| this | 0x1E8 | RW | — | driverHeadIndex — array index of the driver head physics body |
| this | 0x3E8 | RW | — | flWheelIndex — array index of the front-left wheel body |
| this | 0x3EC | RW | — | flSpindleIndex — array index of the front-left spindle/upright body |
| this | 0x84C | RW | — | frWheelIndex — array index of the front-right wheel body |
| this | 0x850 | RW | — | frSpindleIndex — array index of the front-right spindle/upright body |
| this | 0xCB0 | RW | — | rlWheelIndex — array index of the rear-left wheel body |
| this | 0xCB4 | RW | — | rlSpindleIndex — array index of the rear-left spindle/upright body |
| this | 0x1114 | RW | — | rrWheelIndex — array index of the rear-right wheel body |
| this | 0x1118 | RW | — | rrSpindleIndex — array index of the rear-right spindle/upright body |
| this | 0x141C | RW | — | rearAxleIndex — array index of the rear axle / differential body |
| this | 0x15AC | R | — | bodyCount — total number of physics bodies in the joint system |
| this | 0x15F0 | RW | — | bodyIndex — array index of the main vehicle body ("Body") |
| this | 0x162C | RW | — | jointDataArray — allocated array of joint data entries (48*bodyCount bytes) |
| this | 0x1630 | RW | — | flSteeringIndex — array index of the front-left steering arm body |
| this | 0x1644 | RW | — | frSteeringIndex — array index of the front-right steering arm body |

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
| 0056d930 | VehiclePhysicsJointSystemLoader | loads and initializes the vehicle physics joint/body system from config data |
| 0056ead0 | LinearSearchWithLargeStructStride | linearly searches an array of large structs for a matching string name, returns index |
| 0056eb30 | LinearSearchInStructArrayByString | linearly searches a struct array by string key, returns pointer to the found node |
| 00587c03 | OperatorNewNhMallocWrapper | operator new with no-throw — allocates the joint data array (48 * bodyCount bytes) |

**Guard conditions:** No guard conditions — the function always executes its full body without branching on field values. The only conditional logic is the FL/FR steering index resolution: if the search result's second field equals the bodyIndex, the third field is used; otherwise the fifth field is used — this handles two possible struct layouts for the steering linkage entry.

(End of file - total 76 lines)
