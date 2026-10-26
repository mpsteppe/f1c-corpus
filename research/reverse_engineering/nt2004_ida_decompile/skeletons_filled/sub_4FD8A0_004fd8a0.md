## sub_4FD8A0_004fd8a0 — CreateTelemetryFile

**Summary:** Creates a telemetry/data recording file (.gdb format) for vehicle physics logging. Writes header with channel definitions for all vehicle sensors (position, speed, RPM, temperatures, tire data per wheel) and encodes identification data with XOR obfuscation.

**Called by:** sub_42F350 (0042f350), sub_4B9210 (004b9210)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | FILE* handle to open telemetry file |
| this | 0x4 | RW | 8 | Sample interval in frames (clamped 8-320, based on 40/session_length) |
| this | 0xC | RW | — | Obfuscated header value #1 (random byte sum + 18) |
| this | 0x10 | RW | — | Obfuscated header value #2 (random byte + 77) |
| this | 0x14 | RW | — | Obfuscated header value #3 (random byte sum + 15) |
| this | 0x18 | RW | 0 | Frame counter — initialized to 0 |

**Written-by note (persistence):**
- this 0x0: written once during telemetry file open; would survive until file closed
- this 0x4: written once; would survive
- this 0xC: written once; would survive
- this 0x10: written once; would survive
- this 0x14: written once; would survive
- this 0x18: written once; would survive until incremented during recording

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d5b14 | flt_5D5B14 | R | Constant 40.0 — used for sample rate calculation |
| 005fca60 | aWb | R | "wb" — file open mode (write binary) |
| 005fd340 | NumOfElements | R | Vehicle count — iterate to find first active vehicle |
| 005ff810 | aClutch | R | "Clutch" — channel name |
| 005ff8a0 | aBrake | R | "Brake" — channel name |
| 005ffc74 | dword_5FFC74 | R | Part of extension string suffix |
| 005ffc78 | byte_5FFC78 | R | Extension character suffix |
| 00601cd4 | aSteering | R | "Steering" — channel name |
| 00601d10 | aThrottle | R | "Throttle" — channel name |
| 00612338 | aOilTemperature | R | "Oil Temperature" — channel name |
| 00612348 | aWaterTemperatu | R | "Water Temperature" — channel name |
| 0061235c | aGear | R | "Gear" — channel name |
| 00612364 | aCornerWeight | R | "Corner Weight" — per-wheel channel |
| 00612374 | aTyreWear | R | "Tyre Wear" — per-wheel channel |
| 00612380 | aTyrePressureKp | R | "Tyre Pressure (kPa)" — per-wheel channel |
| 00612394 | aTyreRightTempK | R | "Tyre Right Temp" — per-wheel channel |
| 006123a8 | aTyreCenterTemp | R | "Tyre Center Temp" — per-wheel channel |
| 006123c0 | aTyreLeftTempK | R | "Tyre Left Temp" — per-wheel channel |
| 006123d4 | aUndertrayRideH | R | "Undertray Ride Height" — per-wheel channel |
| 006123f0 | aSuspensionDefl | R | "Suspension Deflection" — per-wheel channel |
| 0061240c | aWheelspinRadsS | R | "Wheelspin (rads/s)" — per-wheel channel |
| 00612420 | aRr | R | "RR" — rear-right wheel prefix |
| 00612424 | aRl | R | "RL" — rear-left wheel prefix |
| 00612428 | aFr | R | "FR" — front-right wheel prefix |
| 0061242c | aFl | R | "FL" — front-left wheel prefix |
| 00612430 | aUnfilteredClut | R | "Unfiltered Clutch" — channel |
| 00612444 | aUnfilteredStee | R | "Unfiltered Steering" — channel |
| 00612458 | aUnfilteredBrak | R | "Unfiltered Brake" — channel |
| 0061246c | aUnfilteredThro | R | "Unfiltered Throttle" — channel |
| 00612480 | aClutchRpm | R | "Clutch RPM" — channel |
| 0061248c | aEngineRpm | R | "Engine RPM" — channel |
| 00612498 | aLongAccelMS | R | "Long Accel (m/s)" — channel |
| 006124ac | aVertAccelMS | R | "Vert Accel (m/s)" — channel |
| 006124c0 | aLatAccelMS | R | "Lat Accel (m/s)" — channel |
| 006124d0 | aYawRads | R | "Yaw (rads)" — channel |
| 006124dc | aPosZM | R | "Pos Z (m)" — channel |
| 006124e8 | aPosYM | R | "Pos Y (m)" — channel |
| 006124f4 | aPosXM | R | "Pos X (m)" — channel |
| 00612500 | aElapsedTimeS | R | "Elapsed Time (s)" — channel |
| 00629120 | byte_629120 | R | Empty string fallback |
| 0062bf64 | unk_62BF64 | R | Unknown reference |
| 0075aad0 | dword_75AAD0 | R | Vehicle pointer array — indexed to find first active vehicle |
| 0075cbb0 | dword_75CBB0 | R | Game mode — if 7, extra check for dword_766B04 required |
| 0075cbc4 | dword_75CBC4 | R | Used in XOR computation with 0xABBA717E |
| 00760b10 | flt_760B10 | R | Float value XORed with 0x516141F2 for obfuscation |
| 00766578 | dword_766578 | R | Session file path string |
| 00766594 | dword_766594 | R | Session driver/player name string |
| 00766ae0 | dword_766AE0 | R | Session length in seconds — used for sample rate |
| 00766b04 | dword_766B04 | R | Extra flag for game mode 7 |
| 00766b44 | dword_766B44 | R | Telemetry output file path string |
| 007d3c50 | dword_7D3C50 | R | Scene/track data handle |
| 007d6a5c | dword_7D6A5C | R | Track name string array base |
| 007d6b50 | dword_7D6B50 | R | Track count |
| 007d6b58 | dword_7D6B58 | R | Track data array base |
| 007d73d0 | dword_7D73D0 | R | Unknown identifier |
| 007d741c | dword_7D741C | R | Used in XORed checksum computation |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042dba0 | sub_42DBA0 | Check if telemetry recording is enabled/active |
| 00430670 | ScoreSlotDeallocator [structural] | Free/deallocate score data |
| 00430bc0 | sub_430BC0 | Initialize data structure array |
| 004d1a80 | sub_4D1A80 | Get scene/track identifier value |
| 004f6a10 | sub_4F6A10 | Generate random session key into buffer |
| 004fe670 | ResourceDestroy [structural] | Clean up previous telemetry resources |
| 004fe920 | FileReadWithXORDecode [structural] | Write XOR-encoded track name to file |
| 004fea10 | sub_4FEA10 | Write data block to file |
| 005208c0 | sub_5208C0 | Get track/session metadata strings |
| 00521740 | sub_521740 | Process track name with mode parameter |
| 00578600 | StringCopyWithBufferRealloc [structural] | Copy string with buffer management |
| 0057b490 | UtilityFunction_8a60 [structural] | Hash/checksum string into output value |
| 005be8ae | sub_5BE8AE | Free allocated memory |
| 005bea90 | _fopen | Open file for writing |
| 005beab0 | _strncpy | Copy string with length limit |
| 005bf290 | __strcmpi | Case-insensitive compare — match track name |
| 005bf36d | _rand | Generate random bytes for header obfuscation |
| 005bf390 | __alloca_probe [exact] | Stack probe for large allocation |
| 005bf5a6 | sub_5BF5A6 | Write raw bytes to file (fwrite wrapper) |

**Guard conditions:** 
- sub_42DBA0 returns 0 → BLOCKED, return null (telemetry disabled)
- No active vehicle found (all dword_75AAD0 entries have +4146 == 0) → BLOCKED
- dword_766B44 path is empty OR dword_766AE0 <= 0 → BLOCKED (no output path or zero length)
- dword_75CBB0 == 7 and dword_766B04 == 0 → BLOCKED (mode 7 requires extra flag)
- fopen fails → BLOCKED, return null
- Vehicle pointer is null → empty string fallback used for name data

**String literals referenced (deterministic):**

- `Clutch`, `Brake`, `.gdb`, `Steering`, `Throttle`, `Oil Temperature`, `Water Temperature`, `Gear`, `Corner Weight`, `Tyre Wear`, `Tyre Pressure (kPa)`, `Tyre Right Temp`, `Tyre Center Temp`, `Tyre Left Temp`, `Undertray Ride Height`, `Suspension Deflection`, `Wheelspin (rads/s)`, `RR`, `RL`, `FR`, `FL`, `Unfiltered Clutch`, `Unfiltered Steering`, `Unfiltered Brake`, `Unfiltered Throttle`, `Clutch RPM`, `Engine RPM`, `Long Accel (m/s)`, `Vert Accel (m/s)`, `Lat Accel (m/s)`, `Yaw (rads)`, `Pos Z (m)`, `Pos Y (m)`, `Pos X (m)`, `Elapsed Time (s)`
