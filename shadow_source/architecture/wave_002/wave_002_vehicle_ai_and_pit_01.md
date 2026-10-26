# VehicleAIAndPitSubsystem

Scope: `vehicle_ai_and_pit`  
Trust: `DERIVED`

DERIVED proposal for the vehicle_ai_and_pit scope from 18 validated functions. Core AI session events (0x004193A0, 0x0041A2B0, 0x0041A8C0, 0x0041AA10) share the race-active/track/phase guards (dword_7D0308, flt_7CF3C8, dword_7C56A8), the player-identity compare (dword_7C54E8) and the session event table at flt_5EA618, and are grouped as a GUESS class AISessionEventHandler. The main loop (0x0042D8A0) and process entry (0x0045B200) form the lifecycle spine; 0x0045B200 carries the only DERIVED class-level owner (GameMainEntry). AI settings installation (0x004333E0, 0x004336F0, 0x00433890) resolves .svm paths from globals and stores them into vehicle slots. Terrain/vehicle-scene loaders (0x0044BE70, 0x0045CA20, 0x00460A10, 0x004681B0) and session setup (0x0046D060, 0x004A0630) plus the pit-state read (0x0049BA90) are kept as separate GUESS classes or free functions because no common ownership is proven. All class owner assignments except GameMainEntry and ConstraintSolverParams are GUESS; function_roles carries the evidence for every required function exactly once.

## Function roles

- `0x004024F0` **AIWaypointPathRenderer** — AI waypoint-path debug renderer: loads the waypoint list head at this+0x134, walks +272 next pointers with a 12000-iteration cycle cap, and renders per-edge colored contact patches (batch 9) and white wireframe edges (batch 10) through sub_402220 and sub_4CEFA0; logs an incomplete-waypoint error when the chain is null.
- `0x004193A0` **AISessionEventHandler** — AI session mode transition: resolves a three-way session mode (explicit argument or FloatRangeIndexLookup on the vehicle float at 16456, normalized by ThreeWayEnumConverter), and when ScoringGateSelector(v5) == 2 and the mode is not yet transitioned, fills an 8-dword event entry and inserts it into the session event table, marking this[v5+316] = 2.
- `0x0041A2B0` **AISessionEventHandler** — AI session phase change: for non-player vehicles inserts a phase-change event (id 21/22 for race, 178/179 for practice/qualifying) using the incremented phase counter from a2+16444; always delegates race sessions to AIPositionChangeEvent even for the player vehicle.
- `0x0041A8C0` **AISessionEventHandler** — Lap-completion audio event: when the passing entrant shares the player's team/constructor ID (field +0x4894), fires audio message 55 through the driver data table and inserts it into the session event table.
- `0x0041AA10` **AISessionEventHandler** — Per-driver session-phase completion tracker: sets the completion flag this+0xA44 + 4*a2, counts the four phase flags, and emits either an individual phase event (id 95/97/99/101 via jump table jpt_41AA9C) or the combined event (id 105) into the session event table.
- `0x0042D8A0` **GamePostMainLoop** — Per-frame main game loop: opens a conditional block, dispatches the conditional/session/scoring/collision update pipeline, iterates vehicles, runs weather-only or full camera/render/telemetry updates, and exits through the restart gate (v1 == 4/6 or NextState log path).
- `0x004333E0` **VehicleAISettingsManager** — Per-vehicle AI settings (.svm) file installer: iterates active vehicle slots and stores the first opening candidate path into each vehicle at +18324 (clearing flag byte +18579); in default mode copies the globally resolved default path instead.
- `0x004336F0` **AutoLoadConfig** — Auto-load config driver-name loader: computes a vehicle index range, skips vehicles that already have AI settings (copying the resolved path into +18324), then loads the first settings-less vehicle by name from the auto-load config (byte_7CE498), removing it from the linked list or validating its configuration file.
- `0x00433890` **VehicleAISettingsManager** — AI settings file-path resolver: selects the base directory (dword_7CE5EC or byte_5EA438), validates it, locates a settings data entry from lookup tables off_5C3FA8/off_5C3FB0 (plus off_5C3FAC when the session iteration count is 5), and writes the concatenated path into the caller buffer, returning 0 on success.
- `0x00434860` **ConstraintSolverParams** — Constraint-solver parameter block initializer: tears down prior vtable state, then writes control bytes, float limits (90.0/75.0/2.0/3.25), an invalid handle (-1) and zeroed counters; returns 0.
- `0x0044BE70` **HTreeTerrainData** — Terrain H-tree file loader: validates the 46-byte version string, reads header blocks and counts, allocates the collision data buffer and object array, deserializes the collision tree, and returns 0 on success or -1 after cleanup on any failure.
- `0x0045B200` **GameMainEntry** — Main game entry (WinMain equivalent): initializes session globals, parses config and networking command line, and drives the lifecycle Game_Enter/Setup/Init, the per-frame GamePostMainLoop restart loop, Game_Post re-setup, and GameExit.
- `0x0045CA20` **TerrainSurfaceSampler** — Terrain surface roughness/height sampler: returns a fallback height when the surface-type lookup rejects the index, computes a weighted average over a clamped sample window of packed height data, caches the result for surface type 16, and stores penetration compensation at this+4804.
- `0x00460A10` **TerrainSetup** — Terrain INI configuration validator: resets five match flags at this+0x1B76A..0x1B76E and evaluates five session descriptors (checksum, scene name, terrain.ini, season-path filename, season-directory path), returning the AND of all matches.
- `0x004681B0` **VehicleSceneModel** — Vehicle visual-scene loader and tire repositioner: builds and writes a temporary view scene, initializes state, evaluates cockpit/mirror node properties, finds the four tire nodes, averages their positions, and repositions the scene-root child chain around the computed center.
- `0x0046D060` **UnknownObject** — Season data-file setup chain: initializes a stack session structure, writes the vehicle setup file for the current track, triggers auto-load config processing at byte_7CE498, deallocates the score-slot array, and frees a scratch buffer.
- `0x0049BA90` **PitStateAccessor** — Pit-state flag check: reads the signed dword at dword_7C54E0 + 16496 and returns whether it is greater than zero; read-only, no side effects.
- `0x004A0630` **UnknownObject** — Session-scene initialization chain: places multiplayer vehicles, allocates the race-standings node list, loads the track scene from the resolved settings path, resets the sound interface, seeds buffer defaults, and runs the session-scene sub-initializer.

## Proposed classes

### GameMainEntry

Top-level process entry: initializes session globals, parses config/net command line, and drives the game session lifecycle through Game_Enter/Setup/Init and the per-frame restart loop.

Methods: `0x0045B200`


### GamePostMainLoop

Per-frame main loop: dispatches the conditional/session/scoring/collision update pipeline, iterates vehicles, and selects the weather-only or full camera/render/telemetry path before exiting via the restart gate.

Methods: `0x0042D8A0`

- `this+0x00000000` `DWORD loopPhaseCounter` (write, GUESS)

### AISessionEventHandler

Per-vehicle AI session event emission (mode transitions, phase changes, phase completion, teammate lap audio) gated by race-active/track/phase guards and written into the shared session event table.

Methods: `0x004193A0`, `0x0041A2B0`, `0x0041A8C0`, `0x0041AA10`

- `this+0x00000A44` `DWORD[4] phaseCompletionFlags` (read_write, GUESS)
- `this+0x00004894` `DWORD teamConstructorId` (read, GUESS)

### VehicleAISettingsManager

Resolves the AI settings (.svm) file path from configuration globals and installs it per vehicle slot, with per-vehicle qual/race segment selection and a default-path fallback mode.

Methods: `0x004333E0`, `0x00433890`


### AutoLoadConfig

Auto-load configuration entry used to load a driver name and validate its configuration file for the first vehicle lacking AI settings.

Methods: `0x004336F0`

- `this+0x00000000` `char* driverName` (read, GUESS)
- `this+0x00000010` `char* vehicleName` (read, GUESS)

### ConstraintSolverParams

AI constraint-solver parameter block; constructor-style initializer writes control bytes, float limits, an invalid handle and zeroed counters.

Methods: `0x00434860`

- `this+0x00000000` `BYTE flagsByte0` (write, GUESS)
- `this+0x00000001` `BYTE activeFlag` (write, GUESS)
- `this+0x00000002` `BYTE flagsByte2` (write, GUESS)
- `this+0x00000004` `DWORD counter0` (write, GUESS)
- `this+0x00000008` `DWORD counter1` (write, GUESS)
- `this+0x0000000C` `DWORD counter2` (write, GUESS)
- `this+0x00000010` `FLOAT limitFloat0` (write, GUESS)
- `this+0x00000014` `FLOAT limitFloat1` (write, GUESS)
- `this+0x00000018` `DWORD invalidHandle` (write, GUESS)
- `this+0x0000001C` `DWORD counter3` (write, GUESS)
- `this+0x00000020` `DWORD counter4` (write, GUESS)
- `this+0x00000024` `FLOAT limitFloat2` (write, GUESS)
- `this+0x00000028` `DWORD counter5` (write, GUESS)
- `this+0x0000002C` `DWORD counter6` (write, GUESS)
- `this+0x00000030` `FLOAT limitFloat3` (write, GUESS)
- `this+0x00000034` `DWORD counter7` (write, GUESS)

### HTreeTerrainData

Loaded terrain H-tree collision data: version-validated header, collision data buffer and collision-object array deserialized from the terrain file.

Methods: `0x0044BE70`

- `this+0x00000000` `void* collisionDataBuffer` (write, GUESS)
- `this+0x00000004` `void* collisionObjectArray` (write, GUESS)

### TerrainSurfaceSampler

Terrain surface roughness/height sampling with a weighted-average decode of packed height data and penetration-compensation output.

Methods: `0x0045CA20`


### TerrainSetup

Terrain INI configuration validation: matches five session descriptors against season/race index bytes and records five match flags whose AND is returned.

Methods: `0x00460A10`

- `this+0x0001B754` `BYTE seasonIndexByte` (read, GUESS)
- `this+0x0001B755` `BYTE raceIndexByte` (read, GUESS)
- `this+0x0001B76A` `BYTE matchFlagChecksum` (read_write, GUESS)
- `this+0x0001B76B` `BYTE matchFlagSceneName` (read_write, GUESS)
- `this+0x0001B76C` `BYTE matchFlagTerrainIni` (read_write, GUESS)
- `this+0x0001B76D` `BYTE matchFlagSeasonPath` (read_write, GUESS)
- `this+0x0001B76E` `BYTE matchFlagSeasonDir` (read_write, GUESS)

### VehicleSceneModel

Vehicle visual-scene loading and tire-node repositioning: builds a temporary view scene, finds the four tire nodes, and repositions the scene-root child chain around the average tire center.

Methods: `0x004681B0`

- `this+0x000000E8` `void* sceneStatePtrA` (read_write, GUESS)
- `this+0x000000EC` `void* sceneStatePtrB` (read, GUESS)
- `this+0x000000F0` `void* sceneRootPtr` (read, GUESS)
- `this+0x00000128` `DWORD sceneActiveGuard` (read, GUESS)

### AIWaypointPathRenderer

AI waypoint-path debug renderer that walks the waypoint node list and emits colored contact patches and white wireframe edges per node pair.

Methods: `0x004024F0`

- `this+0x00000134` `void* waypointListHead` (read, GUESS)

### PitStateAccessor

Read-only pit-subsystem flag accessor: returns whether the signed dword at dword_7C54E0 + 16496 is greater than zero.

Methods: `0x0049BA90`


## Compatibility contracts

- **SessionStateGlobals** — A replacement executable must maintain the runtime globals that gate the AI event pipeline: race-active flag dword_7D0308, track-condition float flt_7CF3C8, race phase dword_7C56A8 (value 8 is a post/phase-excluded state), session type dword_7C56A4 (5 = race, 6..7 = practice/qualifying), and the player-vehicle identity global dword_7C54E8.
- **SessionEventTableContract** — The session event table anchored at flt_5EA618 holds 8-dword entries initialized with sentinel values (default index -1, time -2.0) by StructInitWithSentinelValues, filled by DriverDataTableLookupAndTimeConversion with mode/phase-specific event ids, and appended by InsertDriverTableEntry.
- **VehicleAISettingsInstallContract** — Per-vehicle AI settings: a non-zero dword at vehicle+13000 marks the vehicle as already having AI settings; the resolved settings file path is stored at vehicle+18324 and the flag byte at vehicle+18579 is cleared after installation. Per-vehicle mode is selected by byte_7D03E0.
- **PitStateFlagContract** — Pit-subsystem state is readable as a signed dword at dword_7C54E0 + 16496; PitStateFlagCheck exposes whether it is greater than zero and is consumed by session-state and HUD flag renderer paths.

## Unresolved

- Class owners are mostly GUESS: only GameMainEntry (gameMainEntry 0x0045B200) and ConstraintSolverParams (ConstraintSolverParamInit 0x00434860) have DERIVED owner evidence in the packet; every other function keeps owner UNKNOWN in the packet and is grouped here only on shared responsibility.
- The per-mode transition marker this[v5+316] (0x004193A0) has no field evidence ref in the packet; the owning session handler class is unknown.
- Vehicle-struct offsets (+13000 AI-settings flag, +18324 settings path string, +18579 cleared flag byte, +16496 pit dword, +16444 phase counter byte, +16480 / +18588 dwords) are inferred from usage only; no vehicle-base field refs exist in the packet.
- flt_59E440 appears in packet globals but not as a named operand in the raw decompiled text for several functions; its zero-threshold role is inferred (DERIVED at best), not verified.
- Orphan globals flagged by the packet but absent from raw decompiled bodies: flt_59E45C, dword_8ACEA0, dword_8B8F24 (0x004024F0); dword_8ACEE0, dword_8AD264 (0x004193A0); flt_59E43C, flt_59E7F8, flt_59F0C0 (0x0045CA20); unk_8AC368 (0x00433890, 0x004A0630); dword_5C6784, dword_7CFE0C (0x004681B0).
- Nested pointer-chain fields rooted at this+0x134 (offsets 0x110/0x118, and *(this+0x134)+0x4C) come from IDB struct annotation, not the decompiled body; their roles are unverified.
- PitStateFlagCheck callers (0x0049D4C0, 0x004D82D0, 0x004DBAC3) and ABI lead name are recorded but not structurally placed; frame-path membership is NOT_FOUND.
- callee 0x005881C0 (__alloca_probe) is compiler-emitted stack probing and carries no call-site semantics.
- The rendering role of sub_402220 / sub_4CEFA0 and the meaning of the 2.3509886e-38 alpha sentinel in 0x004024F0 are not established.
- The concrete semantics of sub_463CA0, sub_4D4580, sub_4FA7E0, sub_4FCEE0 and sub_4A1830 inside the main loop are inferred from their loop position, not confirmed by the packet.
- TerrainIniParser's SceneFileMatchByName base pointer ((_DWORD*)this + 28117) may alias the index-byte region this+0x1B754; unclear whether it is a string table or a coincidence.
- The CRC adjustment dword_8ACED8 - 1413405834 and the 5-byte track suffix built from dword_5C5D24/byte_5C5D28 have unknown textual meaning.
- In 0x0045CA20 the index v6 in this[4*v6+4388] / this[32*v6+1060] is never written in the reconstruction (decompiler artifact); the surface-type 16 cache and the 9.9989996 sentinel height semantics are unstated by the packet.
- 0x0046D060's stack scratch slot v3 is read before write in the decompiled body; uninitialized-scratch artifact.
- The session-state constant 1065571320 stored in dword_7C56B0 is not named by the packet.
