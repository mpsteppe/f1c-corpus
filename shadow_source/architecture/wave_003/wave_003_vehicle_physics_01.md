# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

The vehicle_physics scope in this packet spans nine loosely coupled clusters with no proven common owner. (1) Wheel contact-height probing (0x00402220) computes the contact patch and suspension compression via terrain-height queries (SpatialGridQuery 0x0044C4C0); (2) a time-sliced wheel phase machine (0x00404460) runs at most 20 wheels per frame through friction/suspension/proximity phases against a per-run target grip; (3) collision-shape data (0x0040E990, 0x00412C30, 0x004139C0) carries a discriminator, subtype constant, pass-through and a secondary output, seeded via CollisionInvMassStore and F_6FieldBulkSetter; (4) per-vehicle camera/physics update iteration (0x004109D0) applies wheel contact transforms or dispatches render physics and camera-shake writes; (5) session retirement commentary (0x0041B250, owner SessionState) builds sentinel-initialized driver-table entries (event IDs 117-119 player, 235-238 AI) and inserts them into the session event table; (6) the global active-vehicle pointer array service (0x0042BBD0, 0x0042BC40, 0x0042BC80) builds the 104-entry dword_7C54F0 array and records player/vehicle indices; (7) the setup formatter (0x0042F470) and stats estimator (0x00430F00) render setup parameter and performance estimates into display buffers with metric/imperial unit selection and localized labels; (8) physics object lifecycle thunks (0x00433090, 0x00433E60 destructor/teardown, 0x00433870, 0x00434450, 0x00438CA0 init/step, 0x00431BD0 registration) with unproven owners; and (9) brake/tire thermal and wear integration (0x00438130, owner F1CVehicle DERIVED) that clamps integrated temperature, triggers a blowout-style degradation transition and dispatches pit/AI phase callbacks by slip classification. Most class boundaries and all field semantics are GUESS/DERIVED; the twenty-four dbl_59E* read-only globals and the string globals backing the setup formatter are recorded but not tied to literals by this packet.

## Function roles

- `0x00402220` **WheelContactProbe** — Wheel contact-height probe: computes the contact patch position from wheel geometry (origin, scale selector, direction), queries terrain height at the contact center and both side probes via SpatialGridQuery, resolves side-height disagreement beyond a 0.35 threshold, and writes compressed suspension height (center-average + 0.06) and lateral tilt (half the side-height difference) into the output.
- `0x00404460` **WheelProcessingStateMachine** — Time-sliced three-phase wheel processing state machine: computes a per-run target grip from two global grip terms, and when the stored target differs beyond tolerance or the machine is mid-run, processes at most 20 wheels per call through phase 0 friction (sub_4FB260), phase 1 suspension (sub_4FAF60) and phase 2 proximity (VehicleProximity), advancing the phase selector and index, returning to idle with index -1 when a full batch completes.
- `0x0040E990` **CollisionShapeData** — Collision-shape type-1 initializer: writes the 16-bit discriminator into this+8, subtype constant 1 into this+28, stores the pass-through argument at this+32, seeds collision mass/inverse-mass bulk data via CollisionInvMassStore with a constant float array, bulk-sets six collision fields via F_6FieldBulkSetter, and continues into ShortComputation_e770 when the fourth argument is non-zero.
- `0x004109D0` **CameraPhysicsUpdateReceiver** — Per-frame per-vehicle camera/physics update tick: when the scoring gate is in direct-contact mode walks the global vehicle array applying wheel contact transforms (sub_4F0430 then WheelContactTransform 0x004EF180 per slot); otherwise iterates the receiver's camera-element array dispatching mode-ordered render physics (0x0040F300) and, on a coarse shake timer, writes camera-shake data for eligible elements (0x0040F600).
- `0x00412C30` **CollisionShapeData** — Collision-shape-to-bone mapping: dispatches on a shape identifier (1-12, 15, 20, 25, 30, 35, 40, 50) via the jump-table/case globals and computes a bone index (153-189) by subtracting a boolean flag from a shape-specific base; on success writes the bone index to this+8, the sub_414180(0) result to this+0xC, and returns 1 (or -1 when the argument flags or shape are invalid).
- `0x004139C0` **CollisionShapeData** — Collision-shape size classification: promotes the size argument to double and walks an ascending chain of threshold doubles (dbl_59E788..dbl_59E7E0, 1.0..52.5) with the upper tail split by integer bounds 75/110/999, writing the class index to this+8 and the sub_414180(0) result to this+0xC; runs only under the a2==0 && a4==0 guard, otherwise returns -1. Called by SoundEventDispatcher.
- `0x0041B250` **SessionState** — Retirement/failure commentary handler: gated by race-active, track-state, session-type (7), race-phase (!=8) and championship-mode (!=5) flags. Sentinel-initializes a driver-table entry; for the player vehicle (field +0x4894 match) maps reason code to event IDs 119/118/117; for AI vehicles derives a context index (FloatRangeIndexLookup on field +0x4044, default 3) and maps the reason code to event IDs 235/238/236/237 with field +0x489C as context; inserts the entry via InsertDriverTableEntry only when the built entry is not the -1 sentinel.
- `0x0042BBD0` **VehiclePointerArrayRegistry** — Player-vehicle selector: computes the player vehicle pointer as vehicle-array base plus 18624 * slot index, stores it in dword_7C54E0, scans the 104-entry dword_7C54F0 pointer array for a match, records the matching index in dword_7C54DC and returns it (or 104 when absent).
- `0x0042BC40` **VehiclePointerArrayRegistry** — Alternate player-vehicle selector: computes the player vehicle pointer (base plus 18624 * slot) into dword_7C54E8, scans dword_7C54F0 for a match, records the index in dword_7C54E4 and returns it (or 104 when absent).
- `0x0042BC80` **VehiclePointerArrayRegistry** — Builds the global 104-entry active-vehicle pointer array: scans vehicle slots for live entries (dword at index 3250 != -1), zero-fills the unused tail, backfills remaining slots with not-yet-listed live vehicles, then records the array indices of the two reference vehicle pointers into dword_7C54DC (CurrentPlayerIndex) and dword_7C54E4 (CurrentVehicleIndex); returns the active vehicle count.
- `0x0042F470` **SetupValueFormatter** — Vehicle-setup parameter value formatter for the garage/setup menu: the option index selects a 64-byte per-option slot and dispatches through a large switch (50+ cases) to the correct format specifier and unit conversion (metric/imperial from this+0x4; cm-to-inch 0.3937007874015748, radian-to-degree 57.29577951308232, liter-to-gallon 0.2641720372841846, RPM 9.549296585513721), with localized labels via BinarySearchInStringTable into byte_5EC4CC; several cases delegate to SetupValueFormatDS/1fS/WithOffset. Called only from MenuOptionValueDisplay.
- `0x00430F00` **VehicleStatsEstimator** — Vehicle performance-estimate formatter: computes acceleration and top-speed estimates with a numeric-integration loop over BrakeTemperatureFadeModel (0x00430A50) and a cornering estimate via sub_430750, selecting metric (150 km/h bound) or imperial (100 mph bound) presentation from byte_7D0474, resolving every label through BinarySearchInStringTable into the shared byte_5EC4CC scratch buffer, and writing the three estimation lines into this display buffers.
- `0x00431BD0` **UnknownObject** — Static-data registration thunk: passes the address of sub_431BE0 (coerced to int) to BooleanToIntConversion (0x00587B3E) and returns the boolean-to-int result; reports the presence of a function pointer rather than executing it.
- `0x00433090` **PhysicsObjectConfig** — Physics-config object destructor: first reinitializes the object via SessionConfigDefaultInit (0x00432CC0), then frees up to three owned heap pointer fields (offsets 0x14, 0x8, 0x0) via FreeWrapper_7bcf under individual non-null guards, returning the last free result (or the saved field 0x8 value when that field was null). Called by AutoLoadEntryListLoader.
- `0x00433870` **UnknownObject** — Unconditional vehicle-subsystem step: indexes the read-only global array dword_5F0F6C at element 4656 * a2 and passes the object plus the selected element to the AI driver-name loader, returning its result. Reached via NetCommPlayerSlotSync; the loader target has no recorded address.
- `0x00433E60` **PhysicsObjectConfig** — Object teardown helper (structural twin of PhysicsObjectDestructor): default-initializes the object via SessionConfigDefaultInit, conditionally frees the three owned sub-buffers at offsets 0, 8 and 20 via FreeWrapper_7bcf, frees the object itself when the low bit of the flags argument is set, and returns the object pointer.
- `0x00434450` **UnknownObject** — Physics-config initialization thunk: forwards its this pointer unchanged to ConstraintSolverParamInit (referenced only by name in the source text; no callee address recorded) and returns the callee's result. Called from sub_40DE60.
- `0x00438130` **F1CVehicle** — Per-frame brake/tire thermal integration and wear simulation on the live vehicle: converts brake force, slip and angular velocity into per-wheel heat, integrates temperatures toward ambient Kelvin offsets (flt_8AFEF0/flt_8AFEF4 + 273.16) with frame-time weighting and a drain term, clamps the integrated temperature, computes a wear/degradation term from torque and slip ratio, triggers a blowout-style transition that scales down brake/tire force fields on extreme slip, and dispatches pit-state or AI-phase transitions (AISessionPhaseCounter / PitStateSlotActivation) based on slip classification. Called by the vehicle physics integration step (0x00441650).
- `0x00438CA0` **UnknownObject** — Physics subsystem initializer: initializes wheel dynamics via WheelDynamicsInit (0x0043E230), dispatches initialization of a physics subsystem object at this + 5548 via PhysicsSubsystemInitDispatcher (0x0056D410), and returns the result of clearing a physics buffer at this + 492.

## Proposed classes

### WheelContactProbe

Computes a wheel's contact patch position and terrain penetration: reads wheel geometry and a half-extent scalar (this+0 / this+4), queries the spatial terrain grid at the contact center and both side probes, and produces the compressed suspension height and lateral tilt.

Methods: `0x00402220`

- `this+0x00000000` `float halfExtentScalar` (read, GUESS)
- `this+0x00000004` `float halfExtentScalarAlt` (read, GUESS)

### WheelProcessingStateMachine

Drives time-sliced processing of the vehicle wheel array (base this+0x134, stride 316, count this+0x130): three phases (friction, suspension, proximity) selected by this+0x16C, a per-run target grip float at this+0x170, and a phase/wheel index at this+0x174 with -1 as the idle sentinel.

Methods: `0x00404460`

- `this+0x00000130` `int wheelCount` (read, GUESS)
- `this+0x00000134` `void* wheelArrayBase` (read, GUESS)
- `this+0x0000016C` `int phaseSelector` (read_write, DERIVED)
- `this+0x00000170` `float targetGrip` (read_write, GUESS)
- `this+0x00000174` `int phaseIndex` (read_write, DERIVED)

### CollisionShapeData

Collision collision-shape data record: carries a 16-bit discriminator / output dword at this+8, a secondary output at this+0xC (bone index or size class per the mapping/classifying methods), a subtype constant at this+28, and a pass-through value at this+32; seeded with collision mass data by the type-1 initializer.

Methods: `0x0040E990`, `0x00412C30`, `0x004139C0`

- `this+0x00000008` `dword discriminatorOrOutput` (write, GUESS)
- `this+0x0000000C` `dword secondaryOutput` (write, GUESS)
- `this+0x0000001C` `dword subtype` (write, DERIVED)
- `this+0x00000020` `dword passThrough` (write, GUESS)

### SessionState

Live session/race state used for commentary and event handling: identifies the retiring vehicle (field +0x4894), the retirement reason code (field +0x4068), the AI context float (field +0x4044) and the driver context index (field +0x489C).

Methods: `0x0041B250`

- `this+0x00004044` `float aiContextFloat` (read, GUESS)
- `this+0x00004068` `int reasonCode` (read, GUESS)
- `this+0x00004894` `int vehicleIdentity` (read, GUESS)
- `this+0x0000489C` `int driverContextIndex` (read, GUESS)

### VehiclePointerArrayRegistry

Manages the global 104-entry active-vehicle pointer array (dword_7C54F0) and its reference indices: builds the array from live vehicle slots (0x0042BC80), selects the player vehicle into the reference slots dword_7C54E0 / dword_7C54E8, and records the matched indices in dword_7C54DC / dword_7C54E4.

Methods: `0x0042BBD0`, `0x0042BC40`, `0x0042BC80`


### SetupValueFormatter

Renders vehicle-setup parameter values to display strings: option-index switch (entry 0x0042F470) selects format specifier, unit conversion (metric/imperial from this+0x4), localized labels, and per-option slot data; shared helpers (0x0042F180 DS, 0x0042F1E0 1fS, 0x0042F260 with-offset) cover delegated layouts.

Methods: `0x0042F470`

- `this+0x00000004` `int unitFlag` (read, GUESS)
- `this+0x00001644` `int gearCount` (read, GUESS)
- `this+0x00001884` `int fuelLapsCounter` (read, GUESS)
- `this+0x00001980` `float gearRatioValue` (read, GUESS)
- `this+0x00001984` `float gearRatioValue2` (read, GUESS)
- `this+0x00001989` `byte rideHeightOverride` (read, GUESS)
- `this+0x0000198C` `dword formatFlags` (read, GUESS)
- `this+0x00001994` `float lapFactor` (read, GUESS)

### VehicleStatsEstimator

Computes and formats vehicle performance estimates (acceleration, top speed, cornering G) into setup display buffers, using numeric integration over the brake-temperature fade model and unit selection from byte_7D0474.

Methods: `0x00430F00`


### PhysicsObjectConfig

Physics/session-config style object with up to three owned heap allocations (offsets 0x0, 0x8, 0x14) torn down by SessionConfigDefaultInit then FreeWrapper_7bcf; the destructor (0x00433090) and its structural-twin teardown helper (0x00433E60) share the layout. Packet evidence does not prove these two receivers are the same type; the grouping is a proposal.

Methods: `0x00433090`, `0x00433E60`

- `this+0x00000000` `void* ownedBuffer0` (read_write, GUESS)
- `this+0x00000008` `void* ownedBuffer1` (read_write, GUESS)
- `this+0x00000014` `void* ownedBuffer2` (read_write, GUESS)

### CameraPhysicsUpdateReceiver

Per-frame camera/physics update receiver: holds an element count (this+0) and element array pointer (this+8) over which mode-ordered render physics and camera-shake writes are dispatched, and a coarse shake timestamp (this+0x6C).

Methods: `0x004109D0`

- `this+0x00000000` `int elementCount` (read, GUESS)
- `this+0x00000008` `void* elementArray` (read, GUESS)
- `this+0x0000006C` `int shakeTimestamp` (read_write, GUESS)

### F1CVehicle

Live vehicle object (per the corpus SDK naming) whose brake/tire thermal, slip and degradation state is integrated per frame by 0x00438130: brake-force and thermal inputs, a dynamics sub-object (this+0x15C) with angular-velocity doubles, the three-element temperature array (this+0x34C) integrated into this+0x364, slip-state classification (this+0x394) dispatching pit/AI callbacks, and blowout/lock transition scaling. Ownership is DERIVED from the calling context (vehicle physics integration step 0x00441650), not independently proven.

Methods: `0x00438130`

- `this+0x00000078` `int pitSlotIndex` (read, GUESS)
- `this+0x000000BC` `float brakeForce` (read, GUESS)
- `this+0x0000014C` `float brakeDistribution` (read, GUESS)
- `this+0x0000015C` `void* dynamicsSubObject` (read, DERIVED)
- `*(this+0x15C)+0x00000064` `double angularVelocityX` (read, GUESS)
- `*(this+0x15C)+0x0000006C` `double angularVelocityY` (read, GUESS)
- `*(this+0x15C)+0x00000074` `double angularVelocityZ` (read, GUESS)
- `this+0x00000234` `float tireForceScale` (read_write, GUESS)
- `this+0x00000268` `float brakeThermalCoeff` (read, GUESS)
- `this+0x00000270` `float thermalBlendTerm` (read, GUESS)
- `this+0x00000278` `float tireForceScale2` (read_write, GUESS)
- `this+0x00000288` `float tireForceScale3` (read_write, GUESS)
- `this+0x00000314` `float speedMetersPerSec` (read, GUESS)
- `this+0x0000031C` `float brakeThermalGate` (read, GUESS)
- `this+0x00000324` `float brakeHeatGate` (read, GUESS)
- `this+0x00000334` `float referenceTorque` (read, GUESS)
- `this+0x0000033C` `float slipOffset` (read, GUESS)
- `this+0x00000344` `float slipCoeff` (read, GUESS)
- `this+0x0000034C` `void* temperatureArrayBase` (read, GUESS)
- `this+0x00000354` `float wheelTorque0` (read, GUESS)
- `this+0x0000035C` `float wheelTorque1` (read, GUESS)
- `this+0x00000364` `float integratedTemperature` (read_write, DERIVED)
- `this+0x00000368` `dword temperatureClampFlag` (write, GUESS)
- `this+0x0000036C` `float blowoutTimer` (write, GUESS)
- `this+0x00000374` `float slipReference` (read, GUESS)
- `this+0x0000037C` `float slipDrainScale` (read, GUESS)
- `this+0x00000384` `float brakeForceScale` (read_write, GUESS)
- `this+0x00000394` `float slipState` (read_write, DERIVED)
- `this+0x00000398` `float slipStatePayload` (write, GUESS)
- `this+0x0000039C` `float slipAdjustedGrip` (write, GUESS)
- `this+0x000003A4` `float brakeHeatCoeff` (read, GUESS)
- `this+0x000003AC` `float brakeThermalProduct` (read, GUESS)
- `this+0x000003B4` `float convectionCoeff` (read, GUESS)
- `this+0x000003BC` `float angularSpeedOffset` (read, GUESS)
- `this+0x000003C4` `float angularSpeedScale` (read, GUESS)
- `this+0x000003CC` `float wearCoeff` (read, GUESS)
- `this+0x0000044C` `float blowoutForceScale` (read_write, GUESS)
- `this+0x00000454` `float blowoutForceScale2` (read_write, GUESS)

## Compatibility contracts

- **ActiveVehiclePointerArray** — dword_7C54F0 must remain a 104-entry array of pointers to live vehicle slots; BuildActiveVehiclePointerArray appends each live slot (dword at index 3250 != -1), zero-fills and backfills the tail, and records the indices of the reference pointers dword_7C54E0 / dword_7C54E8 into dword_7C54DC / dword_7C54E4. SetPlayerVehicleIndex stores the computed player pointer (base 0x5EC6D8 + 18624 * slot) and returns the matching array index, or 104 when absent. A replacement executable must maintain the same array capacity, live-slot test and index-record semantics.
- **SessionEventTableInsertion** — Retirement/failure commentary must build a sentinel-initialized driver-table entry and insert it into the session event table referenced by flt_5EA618 only when the built entry's first word is not the -1 sentinel. Player vehicles map reason code to event IDs 119 (=1), 118 (=7) or 117 (other); AI vehicles derive a context index (FloatRangeIndexLookup on field +0x4044, default 3) and map reason code to event IDs 235 (=1), 238 (=4), 236 (=9) or 237 (other) using field +0x489C as context.
- **WheelProcessingTimeSlicing** — Wheel dynamics processing is time-sliced across frames: at most 20 wheels per call, three phases (friction sub_4FB260, suspension sub_4FAF60, proximity sub_4FB2E0) selected by this+0x16C over the wheel array at this+0x134 (stride 316, count this+0x130). The machine re-enters idle (phase selector 0, index -1) after a full batch, and re-initializes when the stored target grip at this+0x170 diverges from 1.0 - (flt_8AFEE8 + flt_8AFEEC) * 0.5 by more than 0.05.
- **VehicleSetupValueDisplay** — Setup value formatting must honor the unit flag (this+0x4, metric vs imperial) and the documented conversion factors (cm-to-inch 0.3937007874015748, radian-to-degree 57.29577951308232, liter-to-gallon 0.2641720372841846, RPM 9.549296585513721), resolve localized labels through BinarySearchInStringTable into the shared byte_5EC4CC scratch buffer, and produce per-option output through the 64-byte slot layout (2992/3000/3012/3020/3022 literals) with StringFormat-style buffer-overflow-checked writes.
- **BrakeTireThermalIntegration** — Per-frame brake/tire thermal integration on the vehicle must accumulate per-wheel heat from brake force, slip and angular velocity toward ambient Kelvin targets (flt_8AFEF0/flt_8AFEF4 + 273.16), clamp the integrated temperature at this+0x364 (273.16 / 546.32 bounds), compute the wear term from torque and slip ratio, and on extreme slip trigger the blowout transition that zeroes this+0x394, writes this+0x398, scales this+0x384 by 0.18, this+0x234 by 4.0 and this+0x44C/0x278/0x454/0x288 by 0.7. Slip classification (this+0x394 vs 0.75) dispatches PitStateSlotActivation or AISessionPhaseCounter per slot this+0x78.

## Unresolved

- Exact mapping of the four read-only globals used by 0x00402220 (0x0059E450, 0x0059E454, 0x0059E458, 0x007C9360) to the float literals in the raw source (0.5, 0.34999999, 0.059999999) is not established; the existing analysis labels (DegreesToRadians / PhysicsConstant_59E454 / ConstraintForceEpsilon / Unknown_Struct_7C9360) are DERIVED and not adopted here.
- The legacy ABI label 'Ray_Sphere_Intersection' (abi:lead) attached to 0x00402220 is inconsistent with the raw source, which performs terrain-height queries; the proposed name follows the existing analysis fill (VehicleWheelContactHeightCheck).
- The exact meanings of the wheel-geometry fields (a2 origin/spring length/scale/direction) and of this[0]/this[1] (a vehicle half-height scalar) used by 0x00402220 are interpretations from the fill, not independently evidenced.
- The float at this+0x170 in 0x00404460 is written with the computed target grip and compared with a 0.05 tolerance, but its exact meaning (a per-run target grip from flt_8AFEE8 + flt_8AFEEC) is not confirmed; existing analysis prose called 0x170 an index, which conflicts with the raw float access.
- The wheel array element type at base this+0x134 (stride 316) is not confirmed; the friction/suspension/proximity callee names (sub_4FB260, sub_4FAF60, sub_4FB2E0) are DERIVED from existing analysis - only their addresses are FACT.
- Globals flt_59E43C, flt_59E450 and dbl_59E480 are listed in the 0x00404460 packet globals but are not referenced by its raw source text; their role is unclear.
- The v6 bit patterns and F_6FieldBulkSetter arguments in 0x0040E990 are float bit fields; their decoded float values are deliberately not asserted (no IEEE-754 synthesis per rules). Whether the constant 1 at this+28 is a physics shape 'type' enum is a prose proposal, not a confirmed enum value; the concrete semantics of CollisionInvMassStore (0x00459950) and F_6FieldBulkSetter (0x00459990) are not confirmed from this packet.
- Per-element camera struct fields at byte offsets +28 (state tag, value 6 excluded) and +10 (flag byte) touched by 0x004109D0 are not in the packet field set; the purpose of the float-parameter sub-call sub_4F0430 is caller-context dependent and unresolved.
- Semantics of sub_414180(0) and the secondary value written to this+0xC by 0x00412C30 and 0x004139C0 are unknown; the shared receiver layout (this+8 / this+0xC) across the three CollisionShapeData methods is assumed from naming and identical offsets, not proven common ownership.
- The exact association of each dbl_59E788..dbl_59E7E0 global to a specific threshold literal (1.0..52.5) in 0x004139C0 is not determinable from the packet; only inline decimal constants appear in the raw source.
- flt_59E440 (read by 0x0041B250 per packet facts) and dword_8AD264 (prior-analysis penalty-message queue) never appear in the decompiled source text; no grounded operation could be derived for them.
- The inner `else if (dword_7C56A8 != 8)` on the AI path of 0x0041B250 duplicates the outer phase guard and has no distinct behavior in the raw text; reason-code value 7 (event 118) and the semantics of event IDs 117-119/235-238 come from the prior-analysis fill, not the raw decompile. The exact interpretation of field +0x489C (retired driver index vs grid position) is not established.
- Semantics of dword_7C54E0 (fill prose: postProcessInput) and dword_7C54DC (fill prose: CurrentPlayerIndex) in 0x0042BBD0, and of the 104 not-found return for callers, come from higher-tier analysis; only the writes are grounded here.
- dword_7C54E4 (CurrentVehicleIndex) is written but never read inside 0x0042BC40; downstream consumers are not visible. No branch verifies a1 is a valid slot index before computing the pointer.
- Semantic names of the reference pointers dword_7C54E0 / dword_7C54E8 and their outputs dword_7C54DC / dword_7C54E4 in 0x0042BC80 come from existing-analysis labels, not this function's code; byte_7C5690 is used purely as the end-of-array sentinel here although the corpus label is InitStateFlag; the backfill loop's null check appears unreachable within the loop bounds.
- The jump-table global jpt_42F49D (0x42FC74) backs the 0x0042F470 switch but never appears in the decompiled text; string globals aS_4, aD_1, a1fS, aDS, a3fS, a2f2f, a2d2d3f, a2f1, a2d2dS2d2d, aD03d, aD, aDSS, a41fSS, aDS_0, a1S, aS, a41f41f, a2fS and byte_42FCC4 are flagged by packet facts but never named in the text; double globals dbl_59E430, dbl_59EA18, dbl_59EA20, dbl_59EA30, dbl_59EA38, dbl_59EA40 may back the inline conversion constants but that mapping is unverified.
- The per-option slot layout in 0x0042F470 (64-byte stride; double at +0, double at +8, int at +20, byte at +28, string at +30) is visible only through raw-source literals 2992/3000/3012/3020/3022 with no dedicated packet field evidence; return-value semantics are ambiguous (format arms return the output buffer pointer, the default arm returns the option index).
- The read-only globals aSS (0x005BE860), aDS (0x005C3778), a2fS (0x005C3820), aS0DSS (0x005C3F48) and the dbl_59E430 / dbl_59EA68 / dbl_59EA88 / dbl_59EA90 / dbl_59EA98 / dbl_59EAA0 / dbl_59EAA8 doubles are recorded as read by 0x00430F00 but do not appear in its raw body; they are likely consumed inside the estimation routines (BrakeTemperatureFadeModel, sub_430750).
- The meaning of the bound constants v8/v45 (150 or 100) and the 41.6666/44.704 doubles in 0x00430F00, and the this-relative display offsets (+6566, +6694, +6822, +6950, +7078, +7206), are DERIVED from the existing analysis; those display offsets are not flagged packet fields.
- Why the address of sub_431BE0 is coerced to int and converted to boolean in 0x00431BD0, and its caller, are not visible; registration context is unknown.
- The concrete object type owned by PhysicsObjectConfig (0x00433090 / 0x00433E60) is unknown; whether SessionConfigDefaultInit is a plain field reset or performs additional allocation is outside this packet's evidence. The leading default-init on the teardown path is unusual and unresolved.
- LoadAIDriverNamesFromConfig called by 0x00433870 has no address in the packet callee facts; the record type behind the 4656-element stride of dword_5F0F6C is not evidenced and left uninterpreted.
- ConstraintSolverParamInit (0x00434450) is referenced only by name in the source text; its address, prototype and the parameter object type are absent from the packet.
- The buffer-clear callee in 0x00438CA0 is not among the packet callees; the layout and purpose of the subsystems at this + 5548 and this + 492 are unknown.
- Twenty-four dbl_59E* globals (0x0059E420-0x0059EB90) are listed as read by 0x00438130 but do not appear in the rendered decompiled source; the average-torque read *v21 has no explicit packet field evidence.
- The owner of 0x004109D0 (CameraPhysicsUpdateReceiver) and of the four thunk functions (0x00431BD0, 0x00433870, 0x00434450, 0x00438CA0) is unknown; they are recorded with owner UnknownObject rather than forcing a design.
