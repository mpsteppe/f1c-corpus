## sub_55DCF0_0055dcf0 — Telemetry log writer (header + channel list)

**Summary:** Telemetry file writer: closes/patch-writes any previous output file, then, when recording is enabled and a vehicle record exists, opens the output path in "wb" mode and writes the whole telemetry header — sample period, randomized id fields, track/session/vehicle name strings, the per-channel name table (time, position, yaw, accelerations, RPM, throttle/brake/steering/clutch, the four wheel channels, gear, temperatures, fuel), obfuscated checksum fields and the track code derived from the track list.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0055ed30 | jpt_55DDB2 | R | Jump table of the switch on dword_B6FC88 (sample rate) |
| 0055ed38 | byte_55ED38 | R | Byte table belonging to the same switch dispatch |
| 006e9bb1 | byte_6E9BB1 | R | Unknown — not referenced in the visible decompiled body |
| 006f16bc | WindowName | R | Fallback name/path string used wherever the configured string is null |
| 006f23f0 | flt_6F23F0 | R | Unknown — not referenced in the visible decompiled body |
| 006f2598 | aWb | R | File mode string "wb" for fopen |
| 006f3634 | aGear | R | Channel name "Gear" written into the header |
| 006f561c | aClutch | R | Channel name "Clutch" |
| 006f56ac | aBrake | R | Channel name "Brake" |
| 006f671c | dword_6F671C | R | Unknown — not referenced in the visible decompiled body |
| 006f6720 | byte_6F6720 | R | Unknown — not referenced in the visible decompiled body |
| 006fdd44 | aSteering_0 | R | Channel name "Steering" |
| 006fded4 | aThrottle_0 | R | Channel name "Throttle" |
| 0071fbbc | aOilTemperature | R | Channel name "Oil Temperature" |
| 00720050 | aGroundSpeed | R | Channel name "Ground Speed" |
| 007200e8 | aEngineRpm | R | Channel name "Engine RPM" |
| 00720370 | aFuelRemaining | R | Channel name "Fuel Remaining" |
| 00720380 | aWaterTemperatu | R | Channel name "Water Temperature" |
| 00720394 | aCornerWeight | R | Per-wheel channel name "Corner Weight" |
| 007203a4 | aTyreWear | R | Per-wheel channel name "Tyre Wear" |
| 007203b0 | aTyrePressureKp | R | Per-wheel channel name "Tyre Pressure (kPa)" |
| 007203c4 | aTyreRightTempK | R | Per-wheel channel name "Tyre Right Temp (K)" |
| 007203d8 | aTyreCenterTemp | R | Per-wheel channel name "Tyre Center Temp (K)" |
| 007203f0 | aTyreLeftTempK | R | Per-wheel channel name "Tyre Left Temp (K)" |
| 00720404 | aUndertrayRideH | R | Per-wheel channel name "Undertray Ride Height (m)" |
| 00720420 | aSuspensionSpee | R | Per-wheel channel name "Suspension Speed (m/s)" |
| 00720438 | aSuspensionDefl | R | Per-wheel channel name "Suspension Deflection (m)" |
| 00720454 | aWheelspeedMS | R | Per-wheel channel name "Wheelspeed (m/s)" |
| 00720468 | aRr | R | Wheel prefix "RR " |
| 0072046c | aRl | R | Wheel prefix "RL " |
| 00720470 | aFr_0 | R | Wheel prefix "FR " |
| 00720474 | aFl | R | Wheel prefix "FL " |
| 00720478 | aUnfilteredClut | R | Channel name "Unfiltered Clutch" |
| 0072048c | aUnfilteredStee | R | Channel name "Unfiltered Steering" |
| 007204a0 | aUnfilteredBrak | R | Channel name "Unfiltered Brake" |
| 007204b4 | aUnfilteredThro | R | Channel name "Unfiltered Throttle" |
| 007204c8 | aClutchRpm | R | Channel name "Clutch RPM" |
| 007204d4 | aLongAccelMS | R | Channel name "Long Accel (m/s)" |
| 007204e8 | aVertAccelMS | R | Channel name "Vert Accel (m/s)" |
| 007204fc | aLatAccelMS | R | Channel name "Lat Accel (m/s)" |
| 0072050c | aYawRads | R | Channel name "Yaw (rads)" |
| 00720518 | aPosZM | R | Channel name "Pos Z (m)" |
| 00720524 | aPosYM | R | Channel name "Pos Y (m)" |
| 00720530 | aPosXM | R | Channel name "Pos X (m)" |
| 0072053c | aElapsedTimeS | R | Channel name "Elapsed Time (s)" |
| 00757c1c | dword_757C1C | R | Flag (read as byte) gating the whole recording block |
| 0091e084 | dword_91E084 | R | Current vehicle record; +21568/+21808/+22084/+22212/+22472 supply the strings and index written to the file |
| 00b12003 | unk_B12003 | R | Address used as a value in the obfuscated checksum math |
| 00b640c8 | dword_B640C8 | R | Game mode; equal to 6 blocks recording unless dword_B6FCAC is set |
| 00b64148 | dword_B64148 | R | Value used in the obfuscated checksum math |
| 00b68528 | dword_B68528 | R | Value used in the obfuscated checksum math |
| 00b6f68c | dword_B6F68C | R | Source (with WindowName fallback) of the output file name string |
| 00b6f6a8 | dword_B6F6A8 | R | Name string written directly into the header |
| 00b6fc74 | dword_B6FC74 | R | Object updated via sub_4762A0 when the sample rate is non-standard |
| 00b6fc88 | dword_B6FC88 | R | Sample-rate/period divisor; drives the switch and the header block size |
| 00b6fcac | dword_B6FCAC | R | Override allowing recording while the game mode is 6 |
| 00b6fcec | dword_B6FCEC | R | Output file path (WindowName when null) |
| 00be08a0 | dword_BE08A0 | R | Unknown — not referenced in the visible decompiled body |
| 00be1bd8 | dword_BE1BD8 | R | Base of a setup/vehicle record array (stride 2824) indexed by the record's +22472 |
| 00be1cd0 | dword_BE1CD0 | R | Count of track records (stride 396) scanned for the track code |
| 00be1cd8 | dword_BE1CD8 | R | Base of the track records (name at +4, code at +392) |
| 00be2728 | unk_BE2728 | R | Unknown — not referenced in the visible decompiled body |
| 00be27ac | dword_BE27AC | R | Value used in the obfuscated checksum math |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004015c0 | sub_4015C0 | Rounds/truncates the 40.0/rate value used for the header block size |
| 00431a70 | sub_431A70 | Cleanup/destructor call on a stack structure before exit |
| 00435800 | sub_435800 | Builds session data into the local block (a1, &vars0) |
| 004762a0 | sub_4762A0 | Forces the sample rate value to 10 when it is non-standard |
| 0051c780 | sub_51C780 | Returns a value (time/session id) folded into the checksum |
| 00546b80 | sub_546B80 | Call made after the name strings are copied |
| 00557190 | sub_557190 | Appends bytes to the output file (the main write primitive) |
| 005575e0 | sub_5575E0 | Finalizes/flushes the output file |
| 005875f0 | sub_5875F0 | Initializes a stack structure for the session block |
| 005886a0 | sub_5886A0 | Session-block setup call (with argument 2) |
| 00615860 | StringCopyWithBufferRealloc [structural] | Copies the output name into the String1 buffer |
| 00617bd0 | sub_617BD0 | Reads a value by index used to build the obfuscated checksum fields |
| 006308d8 | j_j__free | Frees the temporary blocks |
| 00630fe0 | sub_630FE0 | Bounded string copy (file-name buffer, 511) |
| 00631710 | _fclose | Closes the previous output file after patching |
| 0063197d | _fseek | Rewinds the previous output file before patching |
| 00631a22 | _fopen | Opens the output file in "wb" mode |
| 00631ba8 | _rand | Generates the randomized id bytes |
| 00631bd0 | sub_631BD0 | Initialization call before any file work |
| 00631c0d | __stricmp | Compares the file name with each track record's name |
| 00631e50 | sub_631E50 | fwrite-style raw writer used for the id fields and the final patch |

**Guard conditions:** If a previous file is open (*v11 non-zero) it is rewound, a 4-byte patch value from v12+71 is written and the file is closed. The recording block runs only when the byte of dword_757C1C is non-zero AND dword_91E084 (the vehicle record) is non-zero AND the path length is non-zero AND dword_B6FC88 > 0. The switch accepts sample rates 1, 2, 5, 10, 20, 50 and 100; any other value is replaced by 10 through sub_4762A0. The file is opened only when the game mode (*dword_B640C8) differs from 6 OR dword_B6FCAC is set; inside, everything depends on fopen succeeding. The computed block size is clamped to the range [10, 400]. The four wheel channels are emitted in a fixed 4-iteration loop with prefixes FL/FR/RL/RR. The final track-code search runs only while dword_BE1CD0 > 0 and matches the name against each 396-byte record (code field at +392); all the temp-block frees and the last cleanup calls run unconditionally at the end of the block.

**String literals referenced (deterministic):**

- `Gear`
- `Gear`
- `Clutch`
- `Clutch`
- `Brake`
- `Brake`
- `.gdb`
- `Steering`
- `Steering`
- `Throttle`
- `Throttle`
- `Oil Temperature`
- `Oil Temperature`
- `Ground Speed`
- `Ground Speed`
- `Engine RPM`
- `Engine RPM`
- `Water Temperature`
- `Water Temperature`
- `Corner Weight`
- … +49 more
