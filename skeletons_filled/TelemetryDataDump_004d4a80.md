## TelemetryDataDump_004d4a80 — Telemetry Session Initialization & Header Write

**Summary:** Initializes a telemetry output session — destroys previous telemetry state, checks scoring gate, finds active player vehicle, opens output file, computes sampling rate (1-40 Hz), writes CSV-style header with all telemetry channel names, embeds XML scene config, and writes integrity checksums (CRC, vehicle hash, scene hash, session seed) into the file.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4A00A0 (004a00a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | file handle / output stream pointer (from sub_587DB0 directory open) |
| this | 0x4 | RW | 1 | telemetry sampling rate (integer, clamped to 1-40, computed as 10 * round(40/freq + 0.5)) |
| this | 0xC | RW | — | byte offset / size field (computed from random seed bytes) |
| this | 0x10 | RW | — | byte offset / size field (computed from random seed bytes) |
| this | 0x14 | RW | — | byte offset / size field (computed from random seed bytes) |
| this | 0x18 | RW | 0 | counter / state field (zeroed) |

**Written-by note (persistence):**
- this 0x0: init once per telemetry session start — external poke persists until next init
- this 0x4: init once per telemetry session start — external poke persists until next init
- this 0xC: init once per telemetry session start — external poke persists until next init
- this 0x10: init once per telemetry session start — external poke persists until next init
- this 0x14: init once per telemetry session start — external poke persists until next init
- this 0x18: init once per telemetry session start — external poke persists until next init

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e86c | flt_59E86C | R | FloatToInt64Scale [DERIVED] |
| 005c2ab0 | unk_5C2AB0 | R | config directory path (passed to sub_587DB0 for output directory creation) | ConfigDirectoryPath [DERIVED] |
| 005c329c | dword_5C329C | R | vehicle count (upper bound for active-vehicle search loop) | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005c55cc | aClutch | R | telemetry channel name: "Clutch" | sClutch [DERIVED] |
| 005c565c | aBrake | R | telemetry channel name: "Brake" | ComponentNameBrake [DERIVED] |
| 005c5d24 | dword_5C5D24 | R | season races suffix part 1 (appended to track path) | SeasonRacesSuffix1 [DERIVED] |
| 005c5d28 | byte_5C5D28 | R | season races suffix part 2 (appended to track path) | SeasonRacesSuffix2 [DERIVED] |
| 005c6f30 | aSteering | R | telemetry channel name: "Steering" | SteeringString [DERIVED] |
| 005c6f6c | aThrottle | R | telemetry channel name: "Throttle" | String_Throttle [DERIVED] |
| 005d43dc | aOilTemperature | R | telemetry channel name: "OilTemperature" | String_OilTemperature [DERIVED] |
| 005d43ec | aWaterTemperatu | R | telemetry channel name: "WaterTemperature" | WaterTemperature [DERIVED] |
| 005d4400 | aGear | R | telemetry channel name: "Gear" | Gear [DERIVED] |
| 005d4408 | aCornerWeight | R | telemetry channel name: "CornerWeight" (per-wheel) | CornerWeightField [DERIVED] |
| 005d4418 | aTyreWear | R | telemetry channel name: "TyreWear" (per-wheel) | TyreWearString [DERIVED] |
| 005d4424 | aTyrePressureKp | R | telemetry channel name: "TyrePressureKpa" | TyrePressureKpString [DERIVED] |
| 005d4438 | aTyreRightTempK | R | telemetry channel name: "TyreRightTempK" | TyreRightTempKString [DERIVED] |
| 005d444c | aTyreCenterTemp | R | telemetry channel name: "TyreCenterTempK" | Str_TyreCenterTemp [DERIVED] |
| 005d4464 | aTyreLeftTempK | R | telemetry channel name: "TyreLeftTempK" | StringTyreLeftTempK [DERIVED] |
| 005d4478 | aUndertrayRideH | R | telemetry channel name: "UndertrayRideHeight" | UndertrayRideHeightString [DERIVED] |
| 005d4494 | aSuspensionDefl | R | telemetry channel name: "SuspensionDeflection" | SuspensionDeflString [DERIVED] |
| 005d44b0 | aWheelspinRadsS | R | telemetry channel name: "WheelspinRads" | WheelspinRadsString [DERIVED] |
| 005d44c4 | aRr | R | corner label: "RR" (rear right) | RrStr [DERIVED] |
| 005d44c8 | aRl | R | corner label: "RL" (rear left) | RLString [DERIVED] |
| 005d44cc | aFr | R | corner label: "FR" (front right) | FrField [DERIVED] |
| 005d44d0 | aFl | R | corner label: "FL" (front left) | aFl [DERIVED] |
| 005d44d4 | aUnfilteredClut | R | telemetry channel name: "UnfilteredClutch" | String_UnfilteredClut [DERIVED] |
| 005d44e8 | aUnfilteredStee | R | telemetry channel name: "UnfilteredSteering" | UnfilteredSteeString [DERIVED] |
| 005d44fc | aUnfilteredBrak | R | telemetry channel name: "UnfilteredBrake" | UnfilteredBrakeString [DERIVED] |
| 005d4510 | aUnfilteredThro | R | telemetry channel name: "UnfilteredThrottle" | UnfilteredThrottle [DERIVED] |
| 005d4524 | aClutchRpm | R | telemetry channel name: "ClutchRpm" | ClutchRpm [DERIVED] |
| 005d4530 | aEngineRpm | R | telemetry channel name: "EngineRpm" | EngineRpmField [DERIVED] |
| 005d453c | aLongAccelMS | R | telemetry channel name: "LongAccelMS" | LongAccelMSString [DERIVED] |
| 005d4550 | aVertAccelMS | R | telemetry channel name: "VertAccelMS" | VertAccelMSString [DERIVED] |
| 005d4564 | aLatAccelMS | R | telemetry channel name: "LatAccelMS" | LatAccelMSString [DERIVED] |
| 005d4574 | aYawRads | R | telemetry channel name: "YawRads" | Str_YawRads [DERIVED] |
| 005d4580 | aPosZM | R | telemetry channel name: "PosZM" | StringPosZM [DERIVED] |
| 005d458c | aPosYM | R | telemetry channel name: "PosYM" | PosYMFormat [DERIVED] |
| 005d4598 | aPosXM | R | telemetry channel name: "PosXM" | PosXMString [DERIVED] |
| 005d45a4 | aElapsedTimeS | R | telemetry channel name: "ElapsedTimeS" | ElapsedTimeString [DERIVED] |
| 005ea438 | byte_5EA438 | R | default application directory (fallback for null path pointers) | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec6d0 | unk_5EC6D0 | R | unused in this function |
| 007c54f0 | dword_7C54F0 | R | vehicle pointer array (indexed to find active player vehicle) | VehiclePtrArray [FACT] |
| 007c56a4 | dword_7C56A4 | R | session type (7 = race; telemetry gate depends on this) | SessionType [FACT] |
| 007c56b8 | dword_7C56B8 | R | session hash seed (used in telemetry checksum computation) | SessionHashSeed [DERIVED] |
| 007c935c | flt_7C935C | R | telemetry brake float (XOR-obfuscated into file checksum) | TelemetryBrakeFloat [DERIVED] |
| 007ce5d0 | dword_7CE5D0 | R | current track path string (used to build track filename) | CurrentTrackPath [DERIVED] |
| 007ce5ec | dword_7CE5EC | R | settings file path (hashed and written to telemetry file) | SettingsFilePath [DERIVED] |
| 007ce9d0 | dword_7CE9D0 | R | telemetry enable flag (>0 = telemetry active) | Unknown_Int_7CE9D0 [DERIVED] (also: ` — telemetry enable flag) |
| 007ce9f4 | dword_7CE9F4 | R | pit crew anim state (telemetry gate for race sessions: must be set) | PitCrewAnimState [DERIVED] (also: ` — telemetry gate flag) |
| 007cea34 | dword_7CEA34 | R | telemetry output directory path (fallback to default app dir) | PitCrewLHSFlag [DERIVED] |
| 008aae70 | dword_8AAE70 | R | ring buffer counter (seed for deterministic hash generator) | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008ac394 | dword_8AC394 | R | vehicle class array (stride 1060, used to get class name for telemetry) | VehicleArray (stride 0x424) [DERIVED] |
| 008ac488 | dword_8AC488 | R | scene file count (loop bound for scene hash search) | SceneFileCount [DERIVED] |
| 008ac490 | dword_8AC490 | R | scene array (stride 396, searched for matching scene file) | SceneArray (stride 0x18c) [DERIVED] |
| 008acea0 | dword_8ACEA0 | R | scoring grid base (unused in this function) | ScoringGridBase [DERIVED] |
| 008aced8 | dword_8ACED8 | R | terrain INI CRC offset (used in checksum computation) | TerrainINICRCOffset [DERIVED] (also: ` — CRC offset constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042bc10 | ScoringGateCheck | checks whether scoring/telemetry gate is active (must return true) |
| 0042ddd0 | ScoreSlotDeallocator | deallocates score slot resources after telemetry init |
| 0042e320 | SessionStructInit | initializes session struct for HDV vehicle file parsing |
| 004b3c60 | DeterministicHashPseudoRandomGenerator | generates deterministic pseudo-random hash from ring buffer seed |
| 004ceef0 | sub_4CEEF0 | generates a random/nonce string into buffer |
| 004d5840 | ResourceDestroy | destroys previous telemetry resource state |
| 004d5af0 | FileReadWithXORDecode | reads and XOR-decodes a file (scene XML config) |
| 004d5be0 | sub_4D5BE0 | writes data block to telemetry output file (hash/checksum accumulator) |
| 004f34e0 | TireModelDataInit | initializes tire model data structure |
| 004f4270 | TheSvmHdvVehicleFileParser | parses HDV vehicle physics file for telemetry metadata |
| 00566650 | StringCopyWithBufferRealloc | copies track path string into buffer |
| 00568a60 | UtilityFunction_8a60 | obfuscation/checksum utility (applies transformation to 32-bit value) |
| 00587bcf | FreeWrapper_7bcf | frees allocated memory |
| 00587bdc | CRTFtol | converts float to integer with rounding |
| 00587db0 | sub_587DB0 | opens/creates telemetry output directory, returns file handle |
| 00587dd0 | sub_587DD0 | copies/sanitizes path string into buffer |
| 005881c0 | __alloca_probe | stack probe for large alloca allocation |
| 00588410 | sub_588410 | string comparison (checks if scene path matches) |
| 005884ed | RandLCGRandomNumberGenerator | linear congruential random number generator |
| 00588678 | FileReadWrapperWithLock | reads bytes from file with synchronization lock |

**Guard conditions:** Multiple gates control execution: (1) ScoringGateCheck must return true (line 68). (2) Must find an active vehicle where `*(vehicle + 13000) == 0` within vehicle count (lines 72-79). (3) Telemetry output directory path length must be > 0 (line 86). (4) `dword_7CE9D0 > 0` (telemetry enable flag, line 86). (5) If session type == 7 (race), `dword_7CE9F4` (pit crew anim state) must be non-zero as additional gate (line 86). If any gate fails, function returns early without writing telemetry header. Sampling rate computation (line 96-106): 10 * round(40.0 / telemetry_freq + 0.5), clamped to [1, 40]. The telemetry header includes: CRC seed, hashed vehicle fields (name, class, setup), settings path hash, 57 telemetry channel names (position, acceleration, RPM, controls, per-corner tire/suspension data), session hash seed, tire model checksum, terrain CRC, and scene file XOR-encoded XML config.
