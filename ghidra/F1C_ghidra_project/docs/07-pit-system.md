# Pit System - Strategy, Crew, Order

## PitStop Strategy Format â€” Confirmed

Source: `FUN_00429960` @ `0x00429960` (`garage.cpp` / pit strategy reader)

Format: `N,lap1[,lap2[,lap3[,lap4]]]`

- N = number of stops (1â€“4)
- Following integers = lap numbers for each stop
- Maximum 4 stops supported
- Last stop lap defaults to `DAT_008acf8c` (total race laps constant) if not specified

This is exactly the format mods write to `.svm` files. Confirmed correct.

---


## FUN_004a2a90 - Pit Crew Animation Loader
### FUN_004a2a90 â€” Pit Crew Animation Loader

Source: pitcrew.cpp [ida:fact]. Loads `.mts` (pit crew model/animation) file. Parses ACTOR,
DETAIL, MESH, POSITION, MOVE, ROTATE directives. Maps wheel mesh names
(LFWHEELOFF/ON, RFWHEELOFF/ON, LRWHEELOFF/ON, RRWHEELOFF/ON) to wheel indices 0â€“3.

Pit crew actor struct: stride 0x78, allocated as array. Fields:
- +0x03: lollipop flag (1 if actor name == "LOLLIPOP")
- +0x00: detail level (uint16)
- +0x26â€“0x2a: POSITION (x, y, z floats)
- +0x2câ€“0x30: ROTATE (quaternion or euler, Ã— _DAT_0059e65c conversion)

**Not moddable.** Pit crew animation/scene only.

---

## pitcrew.cpp - Pit Crew Scene (3 new functions)
### pitcrew.cpp â€” Pit Crew Scene (3 new functions)

#### FUN_004a2010 â€” Pitcrew Mesh Loader

Loads mesh via FUN_005450e0. Checks `DAT_007cf884` (detail level â€” if â‰¤1, load).
Sets up LOD array via FUN_0054c210/230. Error: "CUBE error loading pitcrew mesh".

#### FUN_004a22d0 â€” Pitcrew Animation Loader

Loads `.anm` animation files. Allocates animation array (stride 0x1c, extends
existing array by 1 entry each call). Error: "CUBE error loading animation file".

#### FUN_004a4900 â€” Pitcrew Scene File Loader

Loads MAS archives and scene files for pit crew:
- `CMAPS.MAS` â€” circuit maps
- `CDB.MAS` â€” circuit database
- `TEAM.MAS` â€” team-specific textures
- `PITS.MAS` â€” pit area textures

Scene files loaded based on `DAT_005ea3ec` (left-hand pit flag):
- Normal: `PITS\NORMAL\PITCREW.SCR`
- Left: `PITS\LEFT\PITCREW.SCR`
- 10sec: `PITS\10SEC\PITCREW.SCR`

Creates 3 pit crew instances: PITCREWNORMAL, PITCREW10SEC, PITDIRECTOR
(indexed by vehicle struct +0x4894 = team/pit index).

**Globals:**
- `DAT_007cf884` â€” detail level (â‰¤1 = load pitcrew meshes)
- `DAT_005ea3ec` â€” left-hand pit flag
- `DAT_007c54e8` â€” player vehicle ID

Not moddable â€” graphics/scene only.

---

## FUN_004d12c0 - Pit Stop Order Loader
### FUN_004d12c0 â€” Pit Stop Order Loader

Reads `PITORDER` section from file. Stores array of pit crew names.

**Pit order struct (param_1):**
| Offset | Field |
|--------|-------|
| +0x1a8 | pit order count |
| +0x1ac | pit order array (stride 8, string pointers) |

Reads `ReversePitOrder` config (True/False). If True, reverses the pit order
array. Each entry is a string pointer to a pit crew role name.

---

## FUN_004ddad0 - Pit Crew Instance Setup
### FUN_004ddad0 â€” Pit Crew Instance Setup

Loads `TEAM.MAS`, resolves `TrackName`, finds livery in vehicle's TrackLivery
linked list (param_1[0xf5]). Sets up pit crew actors.

9 pit crew roles: refueler, wcrefueler (Ã—3), lollipop, wclollipop (Ã—3+1).
Resolves role names from TrackLivery data.

**Vehicle struct offsets:**
| Offset | Field |
|--------|-------|
| +0xf3 | livery name |
| +0xf5 | TrackLivery linked list |
| +0xf6 | pit crew livery |

---

## FUN_004a3910 — Pit Crew Animation/MAS Setup

Source: pitcrew.cpp. Loads pit crew animation MAS archives and MTS model files.

Load chain:
1. `PITGUYC.MTS` — pit crew guy model (via FUN_004a21d0, gated by DAT_007cf884 detail level)
2. Builds path: `{season_path}\{track_dir}\PITS\{Normal|Left}\`
3. Loads `PITANIMS.MAS` from that path
4. Loads animation from F0PEWAAA (unknown anim) via FUN_004a22d0
5. Loads animation from F0PEHAAA (unknown anim) via FUN_004a22d0
6. Sets up animation blend states (FUN_004a1fd0 for keyframes 0 and 1)

Uses DAT_005ea3ec (left-hand pit flag) to select Normal or Left pit layout.

**Globals:**
- `DAT_007cf884` — detail level (0=load detailed pit crew meshes)
- `DAT_005ea3ec` — left-hand pit flag
- `DAT_005ec3d8` — season path
- `DAT_005ec420` — track directory

Not moddable — pit crew animation setup only.

---

## FUN_004a3220 — PITANIMS.MAS Animation File Loader

Source: `pitcrew.cpp`. Opens and loads the `PITANIMS.MAS` archive file containing pit crew animations. Wrapper around the already-documented FUN_004a2a90 (pit crew animation loader).

**Key logic:**
- Resolves directory path from param_1, truncates to parent directory
- Opens the directory via FUN_0053c800 (path set) and FUN_0053cbc0 (MAS open for `PITANIMS.MAS`)
- Calls FUN_004a2a90 (pit crew anim loader) with param_1, param_2, param_3
- Closes MAS archive via FUN_0053ce40
- Restores search path via FUN_0053c900

**Calls:** FUN_004a29a0 (search path init), FUN_00566650 (name set), FUN_0053c800 (path push), FUN_0053cbc0 (MAS open), FUN_004a2a90 (anim loader), FUN_0053ce40 (MAS close), FUN_0053c900 (path pop), FUN_00587bcf (free)

**Moddability:** No — pit crew animation loading only.

---

## FUN_004a58b0 — Pit Repair Status Display

Source: pit/garage UI. Formats and displays per-part repair status (part name, wear, repair cost, repair decision). Used in the pit stop menu to show which parts need repair and at what cost.

**Key logic:**
- Reads part wear index from param_1[0x1b] and wear coefficients from param_1[0x16] (double) and param_1[0x18] (double)
- If param_1[0x5f] (current lap wear) == 0: clears wear percentage display
- Otherwise: formats `"%s/%d"` style with computed wear percentage
- If `DAT_007d0450 == 1`: formats cost with `"%4.1f/%s"` using `(wear_index * coeff_a + coeff_b) * _DAT_0059ea40`
- Otherwise: formats as integer with default format
- Gets part name via FUN_004a5820(param_1[0x2b]) and copies to MessageBuffer
- Formats part name + status string at param_1 + 0xb6
- Computes repair delta: param_1[0x3b] (current wear) vs param_1[0x3c] (target wear)
  - If equal: `"%d"` (no change)
  - If target < current: `"%d (-%d)"` (reduced = repaired)
  - If target > current: `"%d (+%d)"` (increased = more worn)
- If param_1[0x4a] == 1 (automatic repair): displays blank (no user choice)
- Otherwise: checks param_1[0x4b] flag; if 0 → `"Do Not Repair"`, if 1 → `"Repair"`
- Formats repair decision at param_1 + 0x136
- If param_1[10] != 1 (manual repair entry): formats cost `"%s: %d"` with part cost from param_1[0x4074] via `*param_1`
- Otherwise: shows blank header (no manual cost)

**Struct offsets (param_1):**
| Offset | Field |
|--------|-------|
| +0x6c (0x1b) | Part wear index (int) |
| +0x58 (0x16) | Wear scale A (double) |
| +0x60 (0x18) | Wear scale B (double) |
| +0x17c (0x5f) | Current lap wear flag (float) |
| +0x76 | Wear percentage display buffer |
| +0xb6 | Part name + status display buffer |
| +0xec (0x3b) | Current wear value |
| +0xf0 (0x3c) | Target wear value |
| +0xf6 | Repair delta display buffer |
| +0x128 (0x4a) | Auto repair flag (1=automatic) |
| +0x12c (0x4b) | Do Not Repair flag (0=don't repair) |
| +0x136 | Repair decision display buffer |
| +0x28 (10) | Manual entry flag (1=auto) |
| +0x36 | Part cost display buffer |

**Globals used:**
- `DAT_007d0450` — display mode flag
- `DAT_005ec4cc` — MessageBuffer

**Calls:** FUN_004a5820 (part name lookup), FUN_00423a00 (string copy), FUN_0058815f (format/print)

**Moddability:** No — pit UI display only, no file fields.

---

## FUN_004d2e50 — Pit Timer / Race Phase State Machine

Source: race/session module. Drives pit stop timing, race phase transitions, and time-remaining display. Acts as a per-vehicle state machine indexed by `DAT_007c56a8` (RacePhase) and `DAT_007c56a4` (SessionType).

**Key logic by race phase:**

**Phase 0 (Session 7, pre-race):** Checks if race time remaining > threshold, transitions to phase 1.

**Phase 1 (Race start):** Manages countdown sequence:
- Computes time-to-start (`param_1[0x2d] - threshold`)
- If 5+ seconds: normal countdown
- 4s: phase 4, 3s: phase 3, 2s: phase 2, 1s: phase 1
- When countdown reaches 0: calls FUN_004d0ec0(2) for session start
- Tracks pit close time: `(pit_open_time + session_lap_time) - race_time`
- Displays "Time until pit closes:" via FUN_004d11d0
- If pit closes early (too soon): calls FUN_0045bdf0 (penalty?)

**Phase 2 (Formation lap):**
- Sets param_1+0xc2 flag for formation lap
- Waits for race time to reach 0
- Transitions to phase 3 (full course yellow) or phase 4 (green)

**Phase 3 (Formation lap / grid):** Calls penalty check (FUN_004bc9b0), resets pit timer, transitions to race running.

**Phase 4 (Green flag / race running):**
- Countdown-based pit window tracking with 5-tier display (FUN_004d1cd0):
  - 0 = pit closed, 1 = opening, 2–4 = closing soon, 5 = open
- Displays "00:01" warning via FUN_0045bde0
- When time runs out: calls FUN_004d2210 (pit close), transitions to phase 5

**Phase 5 (Race finish):**
- If leader finished (`param_1[0x3d] == 2`): checks all vehicles for DNF, calls FUN_004d0ec0(1)
- Periodic "Time Remaining:" display every `DAT_007cebf4` ticks
- Formats `"%s %d:%02d:%02d"` for HUD via FUN_0045bd10

**Phase 7 (Post-race, session 1-6):** Adds pit closure offset to lap time.

**Default (non-race sessions):** Calls FUN_0041a500 with remaining time.

**Struct offsets (param_1 — per-vehicle session data):**
| Offset | Field |
|--------|-------|
| +0xb4 (0x2d) | Race time remaining (int) |
| +0xb0 (0x2c) | Lap time remaining (int) |
| +0xd8 (0x36) | Pit window open time (int) |
| +0xc2 | Formation lap flag (byte) |
| +0xf4 (0x3d) | Finish state (2=finished) |
| +0x104 (0x41) | Processed flag (byte) |

**Globals used:**
- `DAT_007c56a4` — SessionType
- `DAT_007c56a8` — RacePhase (0–7)
- `DAT_008afe98` — (pit closure offset)
- `DAT_008afea0` — lap/race time threshold (float/double)
- `DAT_007ced8c` — (flag: pit procedure active)
- `DAT_007cec30` — pit open time
- `DAT_007cec78` — (flag: show pit timer)
- `DAT_007cee88` — (flag: formation lap abort)
- `DAT_007cebf4` — time-remaining display interval
- `DAT_005ec4cc` — MessageBuffer
- `DAT_007c54e8` — PlayerVehiclePtr
- `DAT_005c329c` — VehicleCount
- `DAT_007cebf4` — timer update interval

**Calls:** FUN_0041a500 (session timer), FUN_0042d140 (race phase set), FUN_004d0ec0 (session state), FUN_0041a6b0 (time update), FUN_004d1cd0 (pit state display), FUN_004d2e20 (pit countdown), FUN_00423a00 (string copy), FUN_004d11d0 (time format display), FUN_0045bdf0 (early pit penalty?), FUN_0040cde0 (camera/session), FUN_0040dd80/FUN_0040de60 (pit anim), FUN_0040e170 (session end), FUN_004bc9b0 (jump start penalty), FUN_00461db0 (sound check), FUN_004d2210 (pit close), FUN_0045bd10 (HUD write), FUN_0058957a (random/check)

**Moddability:** No — runtime session state machine, no file fields.

---

## FUN_0041ab30 — Pit State Slot Activation / Commentary

Source: pit/session. Activates pit slot and dispatches commentary.

**Key logic:**
- Sets slot param_1+0xa44+param_2*4 = 2
- Counts active slots: if <3 per-slot commentary IDs, if >=3 ID 0x68

**Calls:** FUN_004144d0, FUN_004144f0, FUN_00418560

**Moddability:** hardcoded

---

## FUN_0041b3c0 — Pit Selection State Machine

Source: pit. Manages tire/strategy slot selection with commentary.

**Key logic:**
- Clamps param_4, random float, position buckets
- Case 0: select top, check flags, commentary IDs by bucket
- Case 2: mid/deselect, queue flag clears
- Case 3: ID 0x83. Case 5: player pit confirmed IDs 0x7b-0x7d

**Calls:** FUN_004144d0, FUN_004f0050, FUN_004d7c10, FUN_004d1ad0, FUN_004189b0, FUN_004189f0, FUN_00418a20, FUN_004144f0, FUN_00418560

**Moddability:** hardcoded

---

## FUN_0041b910 — Clear Pit Selection Flags

Source: pit. Clears all three pit selection flags.

**Key logic:**
- Calls FUN_00418a20 with 0x7b, 0x7c, 0x7d (clear three stages)

**Calls:** FUN_00418a20

**Moddability:** hardcoded

---

## FUN_0041c0f0 — Pit Exit / Release Order Commentary

Source: pit/session. Determines pit exit commentary based on race context.

**Key logic:**
- Searches DAT_005f0738 array for entry matching param_2
- State 1 (entering): IDs 0x204-0x207 by ratio/count thresholds
- State 2 (in pit): IDs 0x209-0x20d by position/gap
- State 3 (exiting, RaceMode 4): IDs 0x210-0x217 with random 50% flip

**Calls:** FUN_004144d0, _rand, FUN_004144f0, FUN_00418560

**Moddability:** hardcoded

---

## FUN_004a5330 — Pit Part State Copy

Source: game_logic. Copies part setup from source to destination.

**Key logic:**
- Copies data blocks, part name, status
- Gets part handle, resolves part ID
- Initializes repair display, cost offsets
- Clears decision flags

**Calls:** FUN_004d7880, FUN_004d7570, FUN_004a57f0, FUN_004a5820, FUN_004a5660, FUN_004a56b0, FUN_004a3440

**Moddability:** no — init function

---

## FUN_004a5820 — Nth Valid Part Lookup

Source: game_logic. Returns Nth active part from vehicle part list.

**Key logic:**
- If param_2 > 0: iterate parts list, skip worn parts unless low session type
- Decrement counter on match, return part ID when 0

**Calls:** FUN_004d7570

**Moddability:** no — lookup utility

---

## FUN_004a5c40 — Teammate Part Value Lookup

Source: game_logic. Finds vehicle with same TeamID.

**Key logic:**
- Iterates VehiclePtrArray comparing +0x48a4 TeamID
- If match: return other vehicle's +0x3450 value

**Moddability:** no — lookup utility

---

## FUN_004a6200 — Pit Stop Ready Check

Source: game_logic. Checks if vehicle ready for pit stop.

**Key logic:**
- Sets ready flag, checks position distance vs threshold
- Calls FUN_004f1b50 (pit animation), FUN_004ef930 (pit lane init)
- If ready: store operation type, compute return time

**Calls:** FUN_004f1b50, FUN_004ef930, FUN_0042a3d0, FUN_004a6340, FUN_004efb20, FUN_004a3320, FUN_0040d3c0

**Moddability:** yes — distance threshold DAT_005acb50

---

## FUN_004a6340 — Pit Stop Operation Timer

Source: game_logic. Computes pit stop return time.

**Key logic:**
- Accumulates phase durations: wheel change, repair, refuel
- Wheel change: 4 random cubic durations via ring buffer
- Repair: add repair time
- Refuel: increment global counter, add fuel time with variance
- If disqualified: penalty time

**Calls:** FUN_004f1890, FUN_004a5820, FUN_004d7570, FUN_004f1a60, FUN_004f1860, FUN_004b33b0, FUN_004a35f0, FUN_004a3560, FUN_004a34a0, FUN_004bbf20, FUN_0042aee0

**Moddability:** yes — timing constants tunable

---

## FUN_004a68b0 — Pit Stop Progress / Completion Handler

Source: game_logic. Drives pit stop animation progression.

**Key logic:**
- Operation in progress: interpolated speed, wheel animation, left/right blend
- Operation complete: clear pit state, stop animations, cleanup
- If same team as player: trigger event

**Calls:** FUN_0040d410, FUN_004f1890, FUN_004f1ba0, FUN_004a5c80, FUN_004d8760, FUN_0042a6f0, FUN_00424cd0, FUN_004f1b50, FUN_004a34a0, FUN_004e0ed0

**Moddability:** yes — animation blend thresholds

---

## FUN_004a6e50 — Pit State Update Machine

Source: pit_system. Main pit state machine — entering/in-pits/exiting/collision avoidance.

**Key logic:**
- State 1 (entering): timer check, transition to 0
- State 2 (in pits): check work complete, clear flag, resume
- State 3 (exiting): normal or emergency exit
- State 4: collision avoidance check via FUN_004a6b80

**Struct offsets:** +0x60 (flag), +0x61 (PitState), +0x62 (PitEntryTimer)

**Calls:** FUN_004a6b80, FUN_004a6db0, FUN_004a5fa0, FUN_004a5c80, FUN_004d8840, FUN_004a6200, FUN_004a68b0, FUN_004a5f20, FUN_004e9630, FUN_0040d410

**Moddability:** high — central pit state machine

---

## FUN_004b7a90 — Pit Timing Update

Source: pit_system. Updates elapsed time for vehicles in pit.

**Key logic:**
- If paused flag set: skip
- If param_3 != 0: setup pit stop for vehicle
- Loop vehicles: add elapsed time to pit timer, check threshold
- Process pending pit commands from linked list

**Calls:** FUN_004b5c50, FUN_00568d90, FUN_004c71c0, FUN_004b5da0, FUN_004b6190, FUN_004b3b30, FUN_004b3af0, FUN_004b6940

**Moddability:** high — timer thresholds, ring buffer size

---

## FUN_004d1bc0 — Pit Stop Order Rank

Source: steward. Returns pit priority rank for a team.

**Key logic:**
- Non-race: count vehicles with different TeamID compared unfavorably
- Race: read from precomputed table DAT_005f0738

**Calls:** FUN_004d0c20

**Moddability:** no

---

## FUN_004d2210 — Pit Close: Team Ready Check

Source: steward. Notifies teams pit window closed.

**Key logic:**
- Iterates vehicles: if +13000 is 0 or 1 (old tires/waiting): calls FUN_004bc9b0(1,0)

**Calls:** FUN_004bc9b0

**Moddability:** no

---

## FUN_004d23d0 — Pit Timer State Init

Source: steward. Initializes pit timer when window opens.

**Key logic:**
- Clears penalty flag, copies pit window time
- Sets race time remaining, calls FUN_0042d140(4) (set green)
- Broadcasts time to all vehicles

**Struct offsets:** +0xb0 (lap time), +0xb4 (race time), +0xb8 (offset), +0xc1 (penalty), +0xc2 (formation flag), +0xd8 (pit window open)

**Calls:** FUN_0042d140, FUN_004bc2d0

**Moddability:** no

---

## FUN_0041be60 — Pit/Race Status Message Dispatcher

Source: hud_messages.cpp. Dispatches pit/race status messages based on session state (FUN_004ff130) and vehicle mode (FUN_004ff1d0). Handles cases 2-5: pit entry, pit exit, race start, formation lap. Formats messages with driver count and time thresholds.

**Key logic:**
- Gets session type (2=quali, 3=race, 4=warmup, 5=practice)
- Gets vehicle mode for driver
- Case 2 (practice/quali): messages 0x1fa-0x200 depending on mode match
- Case 3 (race): message 0x1fd/0x1fe/0x200
- Case 4 (warmup): message 0x1fe/0x200
- Case 5 (practice): message 0x1ff/0x200
- Checks time threshold for additional message 0x201

**Globals:** DAT_007d0308, DAT_007cf3c8, _DAT_008afef0, _DAT_008afee8, _DAT_008afeec, _DAT_0059e450, _DAT_0059e468, _DAT_0059e830

**Calls:** FUN_004144d0, FUN_004ff130, FUN_004ff1d0, FUN_004144f0, FUN_00418560

---



