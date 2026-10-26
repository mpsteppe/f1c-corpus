# WORKER T — F1C Struct Confidence Audit

You are auditing struct field definitions in docs/13-struct-offsets.md against
actual Ghidra decompilation source files.
Worker T of 20.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — audit target
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\` — source .c files

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_T.md

## YOUR STRUCT SECTIONS (14)

--- Section 272: BitStreamWriter (param_1 — bit stream encoder) (5 offsets) ---
## BitStreamWriter (param_1 — bit stream encoder)

Based on FUN_00539690, FUN_00537f30, FUN_00539720. Confidence: **high**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x008 | byte* | OutputBufferPtr | FUN_00537f30, FUN_00539720 | Destination buffer |
| +0x014 | int | BufferPosition / WritePosition | FUN_00539690, FUN_00537f30, FUN_00539720 | Current write offset |
| +0x16ab | ushort | BitAccumLow / BitAccumulator / CharBuffer[0] | FUN_00539690, FUN_00537f30, FUN_00539720 | Pending bits / char byte |
| +0x16ac | byte | BitAccumHigh / CharBuffer[1] | FUN_00539690, FUN_00537f30, FUN_00539720 | Pending high bits |
| +0x16ad | int | BitCount / BitsRemaining / Accumulator | FUN_00539690, FUN_00537f30, FUN_00539720 | Valid bits count |

---



--- Section 273: Source: docs/01-engine-architecture.md (0 offsets) ---
## Source: docs/01-engine-architecture.md

Source: `docs/01-engine-architecture.md` (778 entries, 593 offset observations)

Total extracted observations: 523



--- Section 274: 20. Unmatched / Single-Observation Offsets (523 offsets) ---
## 20. Unmatched / Single-Observation Offsets

Offsets appearing once or without clear struct identity.

| Offset | Type | Field | Function | Line |
|--------|------|-------|----------|------|
| +0x1C | int | int | FUN_00405630 — - Struct Init with VTable Dispatch and Zero Fill | 7042 |
| +0x34 | int | int* | FUN_00405630 — - Struct Init with VTable Dispatch and Zero Fill | 7044 |
| +0x18 | ptr | int* | FUN_00408050 — - Linked List Node Search by ID + Operation | 7068 |
| +0x20 | ptr | int* | FUN_00408050 — - Linked List Node Search by ID + Operation | 7069 |
| +0x1A0 | int | int* | FUN_00418df0 — - Linked List Destructor with Conditional Cleanup | 7169 |
| +0x1A4 | int | int | FUN_00418df0 — - Linked List Destructor with Conditional Cleanup | 7170 |
| +0x1A8 | int | int | FUN_00418df0 — - Linked List Destructor with Conditional Cleanup | 7171 |
| +0x1AC | int | int | FUN_00418df0 — - Linked List Destructor with Conditional Cleanup | 7172 |
| +0x20 | ptr | ModuleObject | FUN_00465300 — Message Dispatch Node Allocator | 880 |
| +0x00 | int | ActiveFlag | FUN_00465300 — Message Dispatch Node Allocator | 944 |
| +0x48 | int | TimerModeFlags | FUN_00465300 — Message Dispatch Node Allocator | 945 |
| +0x00 | ptr | HeadPtr | FUN_00465300 — Message Dispatch Node Allocator | 1081 |
| +0x04 | ptr | TailPtr | FUN_00465300 — Message Dispatch Node Allocator | 1082 |
| +0x08 | int | Count | FUN_00465300 — Message Dispatch Node Allocator | 1083 |
| +0x0C | int | Capacity | FUN_00465300 — Message Dispatch Node Allocator | 1084 |
| +0xEC | int | SharedValue | FUN_00465300 — Message Dispatch Node Allocator | 1111 |
| +0xF0 | HANDLE | MutexHandle | FUN_00465300 — Message Dispatch Node Allocator | 1112 |
| +0xF4 | DWORD | WaitTimeout | FUN_00465300 — Message Dispatch Node Allocator | 1113 |
| +0x54 | HANDLE | MutexHandle | FUN_00465300 — Message Dispatch Node Allocator | 1141 |
| +0x5C | byte | MutexValidFlag | FUN_00465300 — Message Dispatch Node Allocator | 1142 |
| +0x1065 | byte | BoolFlag | FUN_00465300 — Message Dispatch Node Allocator | 1485 |
| +0x3584 | float | FloatParam | FUN_00465300 — Message Dispatch Node Allocator | 1486 |
| +0x00 | int32 | Frequency | FUN_00465300 — Message Dispatch Node Allocator | 1567 |
| +0x08 | double | ScaleFactor | FUN_00465300 — Message Dispatch Node Allocator | 1568 |
| +0x20 | int32 | TimestampLow | FUN_00465300 — Message Dispatch Node Allocator | 1569 |
| +0x24 | int32 | TimestampHigh | FUN_00465300 — Message Dispatch Node Allocator | 1570 |
| +0x2C | int32 | SlotCount | FUN_00465300 — Message Dispatch Node Allocator | 1595 |
| +0x34 | int32 | SlotArray | FUN_00465300 — Message Dispatch Node Allocator | 1596 |
| +0x04 | int32 | ElementCount | FUN_00465300 — Message Dispatch Node Allocator | 1621 |
| +0x08 | int32 | PointerArray[0] | FUN_00465300 — Message Dispatch Node Allocator | 1622 |
| +0x00 | int32 | Enabled | FUN_00465300 — Message Dispatch Node Allocator | 1674 |
| +0x48 | byte | FlagByte | FUN_00465300 — Message Dispatch Node Allocator | 1675 |
| +0x18 | int32 | CurrentLow | FUN_00465300 — Message Dispatch Node Allocator | 1676 |
| +0x1C | int32 | CurrentHigh | FUN_00465300 — Message Dispatch Node Allocator | 1677 |
| +0x20 | int32 | LastLow | FUN_00465300 — Message Dispatch Node Allocator | 1678 |
| +0x24 | int32 | LastHigh | FUN_00465300 — Message Dispatch Node Allocator | 1679 |
| +0x28 | int32 | AccumLow | FUN_00465300 — Message Dispatch Node Allocator | 1680 |
| +0x2C | int32 | AccumHigh | FUN_00465300 — Message Dispatch Node Allocator | 1681 |
| +0x10 | int32 | OtherAccum0 | FUN_00465300 — Message Dispatch Node Allocator | 1682 |
| +0x14 | int32 | OtherAccum1 | FUN_00465300 — Message Dispatch Node Allocator | 1683 |
| +0x00 | ptr | ObjectPtr | FUN_00465300 — Message Dispatch Node Allocator | 1727 |
| +0x00 | ptr | ListHead | FUN_00465300 — Message Dispatch Node Allocator | 1768 |
| +0x10 | HANDLE | Handle | FUN_00465300 — Message Dispatch Node Allocator | 1769 |
| +0x18 | byte | HandleFla
[...39241 chars truncated]

--- Section 275: PhysicsConfigStruct (from FUN_00434450) (16 offsets) ---
## PhysicsConfigStruct (from FUN_00434450)

Default physics config values.

Based on 2 function observations. Confidence: medium.

| Offset | Type | Default | Field |
|--------|------|---------|-------|
| +0x00 | byte | 0 | Flag0 |
| +0x01 | byte | 1 | Enabled |
| +0x02 | byte | 0 | Flag2 |
| +0x04 | int | 0 | ParamI0 |
| +0x08 | int | 0 | ParamI1 |
| +0x0c | int | 0 | ParamI2 |
| +0x10 | float | 90.0 | AngleLimit1 |
| +0x14 | float | 75.0 | AngleLimit2 |
| +0x18 | int | -1 | Sentinel |
| +0x1c | int | 0 | ParamI3 |
| +0x20 | int | 0 | ParamI4 |
| +0x24 | float | 2.0 | MaxForce |
| +0x28 | int | 0 | ParamI5 |
| +0x2c | int | 0 | ParamI6 |
| +0x30 | float | 3.25 | FrictionCoeff |
| +0x34 | int | 0 | ParamI7 |

---



--- Section 276: BarStruct (inferred) (9 offsets) ---
## BarStruct (inferred)

Inside BarArray (stride 0x48) from FUN_0056d930. Extends JointHingeBarStruct with spring/damper params.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | char* | NameString | FUN_0056d930 | Same header as joint/hinge |
| +0x04 | (ptr) | NegBodyPtr | FUN_0056d930 | |
| +0x08 | double | DerivedSpring1 | FUN_0056d930 | |
| +0x0c | (ptr) | PosBodyPtr | FUN_0056d930 | |
| +0x10 | double | DerivedSpring2 | FUN_0056d930 | |
| +0x14 | double[6] | PositionOrientation | FUN_0056d930 | |
| +0x2c | int | LinkCounter | FUN_0056d930 | |
| +0x30 | (extra) | SpringDamperParams | FUN_0056d930 | Additional 0x18 bytes of spring/damper data |
| +0x48 | - | StructStride | FUN_0056d930 | 0x48 |

---



--- Section 277: Player Career Stats / Game Options Struct (28 offsets) ---
## Player Career Stats / Game Options Struct

Based on 2 function observations (FUN_004c18b0 reader, FUN_004c1e80 writer). Confidence: high — identical struct used by reader and writer. Byte-indexed.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x08 | int | ABORTEDSEASONS | FUN_004c18b0 | |
| +0x09 | int | TOTALLAPS | FUN_004c18b0 | |
| +0x0a | int | TOTALRACES | FUN_004c18b0 | |
| +0x0b | int | TOTALRACESWITHAI | FUN_004c18b0 | |
| +0x0c | int | TOTALPOINTSSCORED | FUN_004c18b0 | |
| +0x0d | int | TOTALCHAMPIONSHIPS | FUN_004c18b0 | |
| +0x0e | int | TOTALWINS | FUN_004c18b0 | |
| +0x0f | int | TOTALPOLES | FUN_004c18b0 | |
| +0x10 | int | TOTALLAPRECORDS | FUN_004c18b0 | |
| +0x11 | float→int | AVGSTARTPOSITION | FUN_004c18b0 | stored as float, cast to int |
| +0x12 | int | AVGFINISHPOSITION | FUN_004c18b0 | |
| +0x13 | int | AVGRACEDISTANCE | FUN_004c18b0 | |
| +0x14 | int | AVGOPPONENTSTRENGTH | FUN_004c18b0 | |
| +0x15 | int | MECHFAIL_rate | FUN_004c18b0 | |
| +0x16 | int | RACECOND_reconnaissance | FUN_004c18b0 | |
| +0x17 | int | RACECOND_walkthrough | FUN_004c18b0 | |
| +0x18 | int | RACECOND_formation | FUN_004c18b0 | |
| +0x19 | int | RACECOND_flag_rules | FUN_004c18b0 | |
| +0x1a | int | RACECOND_weather | FUN_004c18b0 | |
| +0x1b | bool | RACECOND_timescaled_weather | FUN_004c18b0 | |
| +0x1c | int | GAMEOPT_qualify_laps | FUN_004c18b0 | |
| +0x1d | int | GAMEOPT_race_laps | FUN_004c18b0 | |
| +0x1e | int | GAMEOPT_race_time | FUN_004c18b0 | |
| +0x1f | int | GAMEOPT_race_length | FUN_004c18b0 | |
| +0x20 | int | GAMEOPT_opponents | FUN_004c18b0 | |
| +0x21 | int | GAMEOPT_fuel_mult | FUN_004c18b0 | |
| +0x22 | int | GAMEOPT_tire_mult | FUN_004c18b0 | |
| +0x23 | int | GAMEOPT_speed_comp | FUN_004c18b0 | |

Note: Offsets are packed (consecutive bytes). This is a dense byte-indexed struct, not int-indexed. Total size: at least 0x24 bytes.

---



--- Section 278: Buffered I/O Init Struct (2 offsets) ---
## Buffered I/O Init Struct

Based on 1 function observation (FUN_005876f0). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x410 | int | sentinel | FUN_005876f0 | set to -1 (end marker) |
| +0x414 | int | cursor | FUN_005876f0 | zeroed (counter) |

---



--- Section 279: Spatial/BSP Node (stride 0x20) (inferred) (9 offsets) ---
## Spatial/BSP Node (stride 0x20) (inferred)

Used by FUN_0051d57f. Recursive spatial subdivision node with
bounding box and span data.

Based on 1 function observation. Confidence: high.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | minX | FUN_0051d57f | Bounding box min X |
| +0x04 | int | maxX | FUN_0051d57f | Bounding box max X |
| +0x08 | int | minY | FUN_0051d57f | Bounding box min Y |
| +0x0c | int | maxY | FUN_0051d57f | Bounding box max Y |
| +0x10 | int | minZ | FUN_0051d57f | Bounding box min Z |
| +0x14 | int | maxZ | FUN_0051d57f | Bounding box max Z |
| +0x18 | int | spanX | FUN_0051d57f | X span (maxX-minX) |
| +0x1c | int | spanY | FUN_0051d57f | Y span (maxY-minY) |
| +0x20 | int | spanZ | FUN_0051d57f | Z span (maxZ-minZ) |



--- Section 280: Source: docs/17-physics-collision.md (0 offsets) ---
## Source: docs/17-physics-collision.md

Source file: `docs/17-physics-collision.md` (5,822 lines, ~343 function entries)
Extracted: **41 struct offset tables**, 100+ offset observations

---



--- Section 281: CollisionElementArray (inferred — param_1 in FUN_004046b0) (6 offsets) ---
## CollisionElementArray (inferred — param_1 in FUN_004046b0)

Based on FUN_004046b0. Confidence: **low** (single function).

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x10 | int | Threshold | Comparison threshold |
| +0x130 | int | ElementCount | Array length |
| +0x134 | int* | ElementArray | Array base (stride 0x13C) |

Elements have stride 0x13C with known sub-fields:
| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x04C | float | AccumValue | Accumulated value within element |
| +0x10C | int* | NextLink | Linked list link |
| +0x110 | int* | NextSibling | Linked list sibling |
| +300 (0x12C) | int | TypeFilter | Type/classification field |

---



--- Section 282: GaugeDisplaySubStruct (referenced via pointer at +0x1d4) (2 offsets) ---
## GaugeDisplaySubStruct (referenced via pointer at +0x1d4)

Based on 1 function observation (FUN_0043ef20). Confidence: **low**.

This is pointed to by the vehicle struct at offset +0x1d4. Only 2 offsets observed:

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0xac | double? | GaugeDisplay | FUN_0043ef20 | display value updated from RPM |
| +0xb4 | double? | GaugeRecip | FUN_0043ef20 | reciprocal for gauge computation |

---



--- Section 283: NetworkManagerStruct (inferred, size ~0xbf8) (52 offsets) ---
## NetworkManagerStruct (inferred, size ~0xbf8)

Based on 10+ function observations. Confidence: high.

The 0xbf8-byte network manager struct allocated by FUN_0057a420. Contains socket state, mutexes, connection lists, and send/receive queues.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x000 | int | ConnectionState | FUN_00563260 | 0=initial, 1+=connected |
| +0x004 | byte | ActiveFlag | FUN_0057afa0 | Packet queue activity flag |
| +0x008 | void* | ClientArray | FUN_00563260 | Client data array ptr (stride 0x1c) |
| +0x008 | int* | HeadPtr | FUN_0057afa0 | Packet queue linked list head |
| +0x00c | int* | CurrentPtr | FUN_0057afa0 | Packet queue insertion point |
| +0x010 | int* | TailPtr | FUN_0057afa0 | Packet queue tail |
| +0x014 | uint | PacketCounter | FUN_0057afa0 | Total packet count |
| +0x01c | int32* | MessageList | FUN_0057b840 | Pointer to message comparison slots |
| +0x070 | int | MaxClientCount | FUN_00563260 | param_1[0x1c] |
| +0x074 | int | ConnAttemptCounter | FUN_00563260 | param_1[0x1d] |
| +0x088 | SOCKET | SocketHandle | FUN_00563080 | UDP broadcast socket |
| +0x098 | int | ReconnRetryCounter | FUN_00563260 | param_1[0x26] |
| +0x244 | short | Port | FUN_005804a0 | Network port |
| +0x24e | int | AltPort | FUN_005804a0 | Alternate port |
| +0x24f | int | SocketFD | FUN_005804a0 | Socket descriptor |
| +0x252 | char[31] | Name | FUN_005804a0 | Connection name |
| +0x25a | byte | Flag1 | FUN_005804a0 | Set to 1 on success |
| +0x29d | byte | CleanupFlag | FUN_0057fbe0 | If set, calls WSACleanup |
| +0x2b6 | HANDLE | MutexH | FUN_00580de0, FUN_0057fbe0 | Win32 mutex |
| +0x2b7 | DWORD | MutexTimeoutH | FUN_00580de0 | Wait timeout in ms |
| +0x2bd | HANDLE | MutexI | FUN_0057fbe0 | Win32 mutex |
| +0x2c4 | HANDLE | MutexJ | FUN_0057bce0 | Win32 mutex |
| +0x2cb | HANDLE | MutexK | FUN_0057bce0 | Win32 mutex |
| +0x2cf | HANDLE | MutexL | FUN_0057bce0 | Win32 mutex |
| +0x2da | HANDLE | MutexM | FUN_0057bce0 | Win32 mutex |
| +0x2e5 | HANDLE | MutexN | FUN_0057bce0 | Win32 mutex |
| +0x2f0 | HANDLE | MutexO | FUN_0057bce0 | Win32 mutex |
| +0x640 | HANDLE | MutexC | FUN_00580c10 | Win32 mutex |
| +0x6c | int | SocketCount | FUN_00563dc0 | Number of open sockets |
| +0x778 | WSADATA | WsaData | FUN_0057fb90 | Winsock startup data |
| +0x88 | SOCKET | UdpSocket | FUN_00563080 | UDP broadcast socket handle |
| +0x938 | SOCKET | ListenSocket | FUN_00580190 | Listening socket |
| +0x93c | SOCKET | CheckSocket | FUN_00580190 | Secondary socket for cancellation |
| +0x967 | byte | NameTerminator | FUN_005804a0 | Null terminator for Name |
| +0x96a | byte | Flag2 | FUN_005804a0 | Set to 1 on success |
| +0x96b | byte | Param3 | FUN_005804a0 | Stored from input |
| +0xa74 | byte | WinsockInitFlag | FUN_0057fb90 | 1 = WSAStartup done |
| +0xaac | int* | SendQueuePtr | FUN_0057d8d0 | Head of send queue linked list |
| +0xabc | HANDLE | SendMutex | FUN_0057d8d0 | Send queue sync |
| +0xac0 | DWORD | SendMutexTimeout | FUN_0057d8d0 | Send mutex wait timeout |
| +0xac8 | int* | ConnectionList | FUN_005813e0, FUN_0057e3a0 | Linked list of connections |
| +0xacc | int* | ConnectionPrev | FUN_005813e0 | Previous pointer |
| +0xad0 | int* | ConnectionCurrent | FUN_005813e0 | Current iterator |
| +0xad4 | int | ConnectionCount | FUN_005813e0 | Total connections |
| +0xad8 | HANDLE | ConnMutex | FUN_005813e0, FUN_0057e3a0, FUN_00580c10 | Win32 mutex |
| +0xadc | DWORD | ConnMutexTimeout | FUN_005813e0, FUN_0057e3a0 | Wait timeout in ms |
| +0xb00 | int* | ConnListHead | FUN_0057edd0 | Head of network thread connection list |
| +0xb10 | HANDLE | ListMutex | FUN_0057edd0 | Mutex for connection list |
| +0xb14 | DWORD | ListMutexTimeout | FUN_0057edd0 | Wait timeout |
| +0xb38 | int | PacketIDCounter | FUN_00580c10 | Shared packet ID counter |
| +0xb3c | HANDLE | PacketMutex | FUN_00580c10 | Mutex for packet ID |
| +0xbec | HANDLE | AcceptMutex | FUN_00580190 | M
[...446 chars truncated]

--- Section 284: Struct 1: Vehicle / AI Driver Struct (param_1) (97 offsets) ---
## Struct 1: Vehicle / AI Driver Struct (param_1)

Based on 50+ function observations across AI ability processing, pit logic, overtaking, and steering. Confidence: **high**.

This is the main per-vehicle struct (stride ~0x48C0). AI-specific fields occupy the range +0x112e–+0x117f (AI abilities and behavior state) and +0x32c8–+0x48a8 (session, identity, path tracking).

### AI Ability & Behavior Region (+0x112e–+0x117f)

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x112e | float | TireStartTempMult | FUN_00424080 (AI profile loader) | clamp(blend × 0.1 + 1.0, 0.60, 1.40). StartsDry/StartsWet blend + ±1.0 random |
| +0x1130 | int/float | QualifyingAbility (stored) | FUN_00424080, FUN_004bf790 | Stored as `(int)((1.0 - QA) × scale)`. Inverted from .rcd. Larger QA → smaller stored → faster synthetic laps |
| +0x1131 | float | RaceAbility scaled (slowness) | FUN_00424080, FUN_0042af70 | `raw_delta = (22 - RA) / 22`. 0 = ideal, 1 = worst. Quadratic slider scaling applied |
| +0x1132 | float | RainSensitivity | FUN_00424080, FUN_0042a180 | `RainAbility × 0.01 × global_rain_scale`. Used in wet speed mult |
| +0x1133 | float | Passing (overtake effort) | FUN_00424080 | `Passing × 0.001 + 0.9`, capped 1.0. Maps [0,100] → [0.90, 1.0] |
| +0x1135 | float | PushLapProbRef | FUN_00424080, FUN_00429470 | `(22 - RA × 0.67) × (1/22)`. Push lap probability threshold |
| +0x1136 | float | SpeedVarWindow | FUN_00424080, FUN_00429470 | `(1 - 0x113d) × 0.67`. Variation window above base speed target |
| +0x113d | float | BaseSpeedTarget | FUN_00424080, FUN_00429470 | `(1 - RA × 0.01) × DAT_005ea3d8`. Session-scaled base speed ratio |
| +0x113e | float | TrackAggression scaled | FUN_00424080 | `TrackAggression × DAT_007d017c`. Minimum clamp 0.01 |
| +0x1140 | float | CorneringAdd | FUN_00424080 | From .rcd. Default 1.5. Modulates AI cornering speed |
| +0x1141 | float | CorneringMult | FUN_00424080 | From .rcd. Default ≈ 0.967. Modulates AI cornering speed |
| +0x1142 | byte | LapTypeFlag | FUN_00429470, FUN_0042a180 | 0 = conservative lap, nonzero = push lap |
| +0x1143 | byte | PushLapCounter | FUN_00429470, FUN_0042af70 | Consecutive push laps. Subtracts 0.5 from push prob each lap |
| +0x1144 | int | AIBehaviorState | FUN_00424e70 | 4/5 = pit window, 0/6 = follow, 1 = pursuit, 3 = pit entry, 2 = pit in, 7 = overtake |
| +0x114f | float | LiveLapRatio | FUN_00424080, FUN_00429470, FUN_0042a180 | Live lap target ratio. Init 1.0. ±0.01 per lap adjustment. Caps at BaseSpeedTarget or (BaseSpeedTarget + SpeedVarWindow) |
| +0x1152 | byte/flag | SteeringOverwriteFlag | FUN_004270a0 | When set, uses raw 0x1108 steering (no correction) |
| +0x1153 | byte/flag | PushActiveFlag | FUN_0042a180 | Push lap active flag |
| +0x1157 | float? | BrakeAccumulator | FUN_004270a0 | Incremented each frame brakes active |
| +0x115b | byte | FlagByte | FUN_004270a0 | Input gate flag |
| +0x115c | float? | BrakeTimerLeft | FUN_004270a0 | Per-side brake timer |
| +0x115d | float? | BrakeTimerRight | FUN_004270a0 | Per-side brake timer |
| +0x1160 | float | WetSpeedMult | FUN_00424080 (calc), FUN_0042a180 | `1.0 - wetness × 0x1132`. Clamped minimum 0.5 |
| +0x1167 | byte | PitBlockingFlags | FUN_0042aee0, FUN_0042a3d0 | Bit 3 = pit block flag (non-race). Bitmask of pit-related flags |
| +0x1178 | uint/bitmask | PlannedStopsBitmask | FUN_0042a3d0 | Bitmask of planned pit stops |
| +0x117f | byte | OvertakeTargetDirection | FUN_0042af70 | Steering direction: 2 = right, else = left |

### Steering & Racing Line Region (+0x105d–+0x1110)

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1102 | float | FilteredSteering | FUN_004270a0 | Filtered/clamped copy of steering |
| +0x1103 | float | SteeringOutput | FUN_004270a0 | Final steering angle output |
| +0x1105 | float | SteeringLimitLeft | FUN_004270a0 | Left steering limit from track-speed |
| +0x1106
[...6718 chars truncated]

--- Section 285: Cross-Function Conflict Summary (0 offsets) ---
## Cross-Function Conflict Summary

| Offset | Conflicting Observations | Resolution |
|--------|------------------------|------------|
| (none) | — | No conflicts found across functions in this doc |

All observations are consistent across functions that access the same struct.
No type conflicts detected.



## TASK
For each struct section:
1. Extract all offset rows from the section (lines with `| +0x`)
2. For each offset: grep analyzed/ for files containing that offset pattern
   e.g. `grep -rl "+ 0x1330" analysis_pipeline/analyzed/`
3. Read matched .c files and verify: does the dereference type match docs/13?
   - `*(double *)(param + 0xXXX)` → double
   - `*(float *)(param + 0xXXX)` → float
   - `*(int *)(param + 0xXXX)` → int/dword
   - `param_1[0x4a]` → int-indexed, byte offset = 0x4a × 4
4. Grade confidence: HIGH (3+ agree), MEDIUM (1-2 agree), LOW (no .c evidence)
5. Flag CONFLICTS: same offset claimed as different types

## OUTPUT FORMAT

```
=== AUDIT RESULTS ===
## StructName

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x0000 | int | field_name | HIGH | 5 files agree | none |
| +0x1330 | double | ??? | LOW | 0 files | FUN_X says float |

=== NEW OFFSETS DISCOVERED ===
| Struct | Offset | Type | Found In | Notes |
|--------|--------|------|----------|-------|
```

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_T.md.
1. Process ALL sections. For every offset in each section, run the grep.
2. Flag EVERY conflict — do not silently pick a winner.
3. New offsets: only report if seen in 2+ .c files.
4. Write to disk after each struct section.
