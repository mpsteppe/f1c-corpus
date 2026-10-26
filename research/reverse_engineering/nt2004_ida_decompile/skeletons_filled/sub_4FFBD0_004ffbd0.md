## sub_4FFBD0_004ffbd0 — ParseTireConfig

**Summary:** Parses tire configuration data from a text file: identifies tire position (front-left, rear-right, etc.), reads ~40+ tire physics parameters (grip curves, wear rates, pressure tables, etc.), and computes aggregate grip multipliers and a clamped wear/life rating.

**Called by:** sub_5005A0 (005005a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 1065353216 → 1.0f | Grip multiplier result — computed as average of 8 dry-grip values from different tire positions, scaled by 0.125 |
| this | 0xC | RW | 1065353216 → 1.0f | Grip multiplier result — computed as average of 8 wet-grip values from different tire positions, scaled by 0.125 |
| this | 0x10 | RW | 15 | Wear/life rating — computed from 4 values averaged, multiplied by 0.25*15, then subtracted from 22.5, clamped to [7, 15] |
| this | 0x14 | RW | 0 | Wet weather flag — set to 1 if "WetWeather" key found and parsed value is non-zero |
| this | 0x18 | R | — | Input parameter a2 — passed through to sub_4FFAA0 |
| this | 0x20 | R | — | Part of input structure v7 — passed to sub_4FFAA0 |
| this | 0x28 | R | — | Part of input structure v7 |
| this | 0x30 | R | — | Part of input structure v7 |
| this | 0x150 | R | — | Part of input structure v7 |
| this | 0x218 | R | — | Part of input structure v7 |
| this | 0x220 | R | — | Part of input structure v7 |
| this | 0x228 | R | — | Part of input structure v7 |
| this | 0x230 | R | — | Part of input structure v7 |
| this | 0x350 | R | — | Part of input structure v7 |
| this | 0x418 | R | — | Part of input structure v7 |
| this | 0x420 | R | — | Part of input structure v7 |
| this | 0x428 | R | — | Part of input structure v7 |
| this | 0x430 | R | — | Part of input structure v7 |
| this | 0x550 | R | — | Part of input structure v7 |
| this | 0x618 | R | — | Dry grip value from position 0 — summed into this+0x8 average |
| this | 0x620 | R | — | Dry grip value from position 8 — summed into this+0x8 average |
| this | 0x628 | R | — | Dry grip value from position 16 — summed into this+0x8 average |
| this | 0x630 | R | — | Dry grip value from position 24 — summed into this+0x8 average |
| this | 0x750 | R | — | Wear value from position ? — summed into this+0x10 computation |

**Written-by note (persistence):**
- this 0x8: written once at end — computed from field averages; external poke overwritten on next call
- this 0xC: written once at end — computed from field averages; external poke overwritten on next call
- this 0x10: written once at end — computed and clamped; external poke overwritten on next call
- this 0x14: written conditionally during parse loop (when "WetWeather" found); may survive if loop doesn't encounter that key

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d5d40 | dbl_5D5D40 | R | unknown |
| 005d5e48 | dbl_5D5E48 | R | unknown |
| 005d5f10 | dbl_5D5F10 | R | unknown |
| 005ea898 | dbl_5EA898 | R | unknown |
| 005ea8a0 | dbl_5EA8A0 | R | unknown |
| 005ea8a8 | dbl_5EA8A8 | R | unknown |
| 005ea8b0 | dbl_5EA8B0 | R | unknown |
| 005fc214 | aName_1 | R | String "Name" — key used with sub_577E50 to extract tire name into Source buffer |
| 0061267c | aTractivecurve | R | String "TractiveCurve" — key to extract traction curve filename |
| 0061268c | aBrakingcurve | R | String "BrakingCurve" — key to extract braking curve filename |
| 0061269c | aLatcurve | R | String "LatCurve" — key to extract lateral curve filename |
| 006126a8 | aGriptemppress | R | String "GripTempPress" — key for grip vs temperature/pressure table |
| 006126b8 | aTempandpressgr | R | String "TempAndPressGrip" — key for temperature/pressure grip data |
| 006126cc | aOptimumpressur_1 | R | String "OptimumPressureMult" — key for optimum pressure multiplier |
| 006126e0 | aOptimumpressur_0 | R | String "OptimumPressureBase" — key for optimum pressure base |
| 006126f4 | aOptimumpressur | R | String "OptimumPressure" — key for optimum pressure data |
| 00612704 | aTemperatures | R | String "Temperatures" — key for temperature range data |
| 00612714 | aOptimumtemp | R | String "OptimumTemp" — key for optimum temperature value |
| 00612720 | aAiwear | R | String "AIWear" — key for AI wear rate |
| 00612728 | aAipeakslip | R | String "AIPeakSlip" — key for AI peak slip angle |
| 00612734 | aAigripmult | R | String "AIGripMult" — key for AI grip multiplier |
| 00612740 | aAisens | R | String "AISens" — key for AI sensitivity parameters |
| 00612748 | aSoftness | R | String "Softness" — key for tire softness |
| 00612754 | aWearrate | R | String "WearRate" — key for wear rate |
| 00612760 | aAirtreadrate | R | String "AirTreadRate" — key for air/tread rate |
| 00612770 | aHeatdistrib | R | String "HeatDistrib" — key for heat distribution (converted from degrees to radians: *0.01745) |
| 0061277c | aTransfer | R | String "Transfer" — key for heat transfer parameters |
| 00612788 | aHeating | R | String "Heating" — key for heating parameters |
| 00612790 | aRollingresista | R | String "RollingResista" — key for rolling resistance |
| 006127a4 | aCamberlatlong | R | String "CamberLatLong" — key for camber lateral/longitudinal (converted deg→rad) |
| 006127b4 | aLongpeak | R | String "LongPeak" — key for longitudinal peak grip |
| 006127c0 | aLatpeak | R | String "LatPeak" — key for lateral peak grip |
| 006127c8 | aLoadsens | R | String "LoadSens" — key for load sensitivity |
| 006127d4 | aSpeedeffects | R | String "SpeedEffects" — key for speed-dependent effects |
| 006127e4 | aLobesperrev | R | String "LobesPerRev" — key for tread lobes per revolution |
| 006127f0 | aLobezeroliftrp | R | String "LobeZeroLiftRP" — key for lobe zero lift (converted to rad/s: *0.1047) |
| 00612800 | aLobedwell | R | String "LobeDwell" — key for lobe dwell angle (converted deg→rad: *0.01745) |
| 0061280c | aLobepeak | R | String "LobePeak" — key for lobe peak value |
| 00612818 | aLobelift | R | String "LobeLift" — key for lobe lift value |
| 00612824 | aDamper_0 | R | String "Damper" — key for damper rate |
| 0061282c | aSpringkpa | R | String "SpringkPa" — key for spring rate in kPa |
| 00612838 | aSpringbase | R | String "SpringBase" — key for spring base height |
| 00612844 | aWidth | R | String "Width" — key for tire width |
| 0061284c | aRadiusrpm | R | String "RadiusRPM" — key for radius vs RPM (converted: *9.5493 to rad/s) |
| 00612858 | aRadius | R | String "Radius" — key for tire radius |
| 00612860 | aWetlatlong | R | String "WetLatLong" — key for wet lateral/longitudinal grip |
| 0061286c | aDrylatlong | R | String "DryLatLong" — key for dry lateral/longitudinal grip |
| 00612878 | aAll | R | String "All" — tire position: all tires (passes index 9 to sub_4FFAA0) |
| 00612880 | aRight | R | String "Right" — tire position: right side (passes index 8) |
| 00612888 | aLeft | R | String "Left" — tire position: left side (passes index 7) |
| 00612890 | aRear | R | String "Rear" — tire position: rear axle (passes index 6) |
| 00612898 | aFront | R | String "Front" — tire position: front axle (passes index 5) |
| 006128a0 | aRearright_0 | R | String "RearRight" — tire position: rear-right (passes index 4) |
| 006128ac | aRearleft_0 | R | String "RearLeft" — tire position: rear-left (passes index 3) |
| 006128b8 | aFrontright_0 | R | String "FrontRight" — tire position: front-right (passes index 2) |
| 006128c4 | aFrontleft_0 | R | String "FrontLeft" — tire position: front-left (passes index 1) |
| 006128d0 | aNone_2 | R | String "None" — tire position: none (passes index 0 to sub_4FFAA0) |
| 006128d8 | aWetweather | R | String "WetWeather" — key for wet weather flag; parsed value sets this+0x14 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ff780 | sub_4FF780 | Initializes the output parameter structure v7 (large float/double array for tire data) |
| 004ffaa0 | sub_4FFAA0 | Applies parsed tire data to a specific tire position slot — called with position index (0-9) |
| 00577b60 | sub_577B60 | Returns parse context type: 0=section data, 1=section start, 4=EOF/section end |
| 00577e50 | sub_577E50 | Key-value extraction from current line — looks up key (e.g. "Name") and writes value to buffer |
| 00578110 | sub_578110 | Key-value extraction variant — used specifically for "WetWeather" boolean parse |
| 00578450 | sub_578450 | Key-value extraction for numeric (double) values — reads 1-3 doubles from a named key |
| 00578600 | StringCopyWithBufferRealloc [structural] | Copies/manages the tire name string from Source buffer |
| 0057a490 | sub_57A490 | Reads next line from the tire config file into Str buffer (384 bytes) |
| 005be8bc | __ftol | Float/double to integer conversion — used in final clamp computation |
| 005be900 | _strstr | Substring search — used to match tire position strings ("FrontLeft", "Rear", etc.) in the config section header |
| 005beab0 | _strncpy | Copies curve filenames (LatCurve, BrakingCurve, TractiveCurve) into fixed 32-byte buffers |

**Guard conditions:** No early-return guard — function always executes fully. The while loop terminates when sub_57A490 returns 0 (end of file) or parse type is 1 or 4 (section boundary).

**String literals referenced (deterministic):**

- `Name`
- `TractiveCurve`
- `BrakingCurve`
- `LatCurve`
- `GripTempPress`
- `TempAndPressGrip`
- `OptimumPressureMult`
- `OptimumPressureBase`
- `OptimumPressure`
- `Temperatures`
- `OptimumTemp`
- `AIWear`
- `AIPeakSlip`
- `AIGripMult`
- `AISens`
- `Softness`
- `WearRate`
- `AirTreadRate`
- `HeatDistrib`
- `Transfer`
- … +31 more
