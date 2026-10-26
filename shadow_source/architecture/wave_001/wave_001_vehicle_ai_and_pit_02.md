# VehicleAIAndPitOperations

Scope: `vehicle_ai_and_pit`  
Trust: `DERIVED`

The packet groups 18 validated functions into two well-bounded regions. (1) A pit-machine cluster (owner CONFIRMED F1CPitMachine for 0x004A5D10/0x004A5FA0/0x004A6200/0x004A68B0): a mode-byte dispatcher reading a vehicle sub-state at obj+0x32C8 and routing through optional delegate objects, a pit-box alignment projection test, a pit-stop readiness evaluation with a speed limiter and camera mode forcing, and a per-frame progress tick that ramps wheel forces, deactivates the limiter, clears AI reason code 9, and notifies state 4 on exit. (2) Tire-physics and vehicle-AI helpers sharing a large float-table-bearing object (mode selector this+0x39B4, contact-patch array this+0x39D0, force tables +0x3C40/+0x3C80, wear slots +0x3D64..0x3D70): grip coefficient, force solvers, wheel/suspension init, engine-wear simulation, racing-line path traversal and path-position tracking, plus a tire-brand table lookup and an AI opponent roster builder. Owners of the tire/physics functions are UNKNOWN in the packet; the shared-field class grouping is DERIVED. All trust is DERIVED/GUESS per worker policy; no new CONFIRMED facts are claimed.

## Function roles

- `0x004A5D10` **F1CPitMachine** — Pit-machine main AI state dispatcher: stores event mode/value, routes to pit strategy, crew, and delegate sub-objects on mode and vehicle sub-state.
- `0x004A5FA0` **F1CPitMachine** — Pit-box alignment readiness test: projection of the relative vehicle-to-target vector against the target rotation basis plus velocity/slip thresholds.
- `0x004A6200` **F1CPitMachine** — Pit-stop readiness evaluation: wheel-spin gate, camera mode 1, tire-compound decision, pit timer arming and player pit-mid arming.
- `0x004A68B0` **F1CPitMachine** — Per-frame pit-stop progress: wheel-force ramps and speed-limiter ramp while servicing, then pit-exit sequence (limiter deactivation, AI reason clear, state-4 notify, elapsed computation, audio, cleanup).
- `0x004BFA00` **AIOpponentSelector** — Builds a performance-ranked, deduplicated AI opponent list with float-key merge sort.
- `0x004D7880` **TireBrandTable** — Tire brand name lookup over a 36-byte-stride table, with gated not-found debug logging.
- `0x004E2540` **WheelSuspensionGeometry** — Per-wheel suspension/tire state initialization: wheel offset from chassis origin, suspension parameters, rotation matrix and Euler extraction.
- `0x004E4500` **F1CVehicleTireSystem** — Physics tire system constructor: sub-structure initializers, defaults (this+0x32BC = -1, this+0x39A4 = 0) and post-constructor finalization.
- `0x004E88B0` **F1CVehicleTireSystem** — Per-corner tire grip coefficient with anti-roll cross-coupling, mode-selected by this+0x39B4 and clamped to [0,1].
- `0x004E8CE0` **F1CVehicleTireSystem** — Bisection root solver for a tire contact-force function over sign-selected lookup tables.
- `0x004E9100` **F1CVehicleTireSystem** — Tire force via friction-circle model: sign-selected table interpolation, aero-drag term, clamp and slip-velocity drag return.
- `0x004E9300` **F1CVehicleTireSystem** — Lateral tire grip force with contact-patch capacity accumulation and aero table term.
- `0x004E9CA0` **F1CAIRacingLineTracker** — AI racing-line path traversal: node lookup and chain walk to the target node id, vehicle state copy, suspension/wheel-contact updates, display-node toggles.
- `0x004EE150` **F1CVehicleTireSystem** — Engine wear simulation: FLT_MAX wear-slot init and per-frame noise-driven recomputation gated by dword_7CEA5C in (0,2].
- `0x004EF7C0` **F1CAIRacingLineTracker** — AI vehicle path-position tracking: orientation copy, rotation matrix build, ride-height error accumulation, rigid-body constraint solve.
- `0x004EFAE0` **F1CVehicleTireSystem** — Conditional tire-scrub reset gated by wear mode; clamps scrub slot +0x3D64 or global dbl_7C91DC.
- `0x004F1510` **F1CVehicleTireSystem** — Audio pitch and wheel-RPM scaling by the speed ratio, flag-gated by byte_7D01C4, then tire brush model solve.
- `0x004F68B0` **F1CVehicleTireSystem** — Tire force/torque from a bias-scaled quadratic model gated by enable byte this+0x1EC.

## Proposed classes

### F1CPitMachine

Owns the pit-stop lifecycle: mode dispatch from event records, pit-box alignment checks, readiness evaluation, per-frame progress/servicing and pit-exit sequencing.

Methods: `0x004A5D10`, `0x004A5FA0`, `0x004A6200`, `0x004A68B0`

- `this+0x00000000` `F1CVehicle* VehiclePtr` (read, DERIVED)
- `this+0x00000004` `int VehicleIndex` (read, GUESS)
- `this+0x00000008` `void* PitCrewObject` (read, GUESS)
- `this+0x0000000C` `void* DelegateA` (read, GUESS)
- `this+0x00000010` `void* DelegateB` (read, GUESS)
- `this+0x00000184` `unsigned char Mode` (read_write, DERIVED)
- `this+0x00000188` `float ModeValue` (write, DERIVED)
- `this+0x00000190` `int PitReadyFlag` (read_write, DERIVED)
- `this+0x000001A0` `float PitEntryTime` (write, DERIVED)
- `this+0x000001A4` `float PitCompletionTime` (read, DERIVED)
- `this+0x000001A8` `float PitStopElapsed` (write, DERIVED)
- `this+0x000001AC` `int PitMidFlag` (read_write, DERIVED)
- `this+0x000001B0` `float LimiterBase` (read, DERIVED)
- `this+0x000001B4` `float LimiterPhaseOneTime` (read, DERIVED)
- `this+0x000001B8` `float LimiterCeiling` (read_write, DERIVED)
- `this+0x000001C0` `int LimiterEngaged` (read, DERIVED)
- `this+0x000001C4` `void* WheelForceParamBlock` (read, GUESS)
- `this+0x000001D0` `float WheelForceWindowBase` (read, DERIVED)
- `this+0x000001D4` `float WheelForceWindowEnd` (read, DERIVED)

### F1CVehicleTireSystem

Large float-table-bearing tire physics object: grip coefficient, force solvers, lateral force, force/torque model, wear slots, scrub reset and audio pitch scaling. Class grouping is DERIVED from strong field overlap (0x3A70/0x3514/0x3C40/0x3D64/0x32BC) plus the constructor that owns them.

Methods: `0x004E4500`, `0x004E88B0`, `0x004E8CE0`, `0x004E9100`, `0x004E9300`, `0x004EE150`, `0x004EFAE0`, `0x004F1510`, `0x004F68B0`

- `this+0x000001EC` `unsigned char EnableFlag` (read, DERIVED)
- `this+0x000001F8` `float TorqueConstantTerm` (read, GUESS)
- `this+0x00000200` `float TorqueLinearTerm` (read, GUESS)
- `this+0x00000208` `float TorqueQuadraticTerm` (read, GUESS)
- `this+0x00000210` `float TorqueBias` (read, GUESS)
- `this+0x00000218` `float TorqueLinearTerm2` (read, GUESS)
- `this+0x00000220` `float TorqueQuadraticTerm2` (read, GUESS)
- `this+0x00000228` `float TorqueScale` (read, GUESS)
- `this+0x00000250` `float ForceComponentAbsA` (read, GUESS)
- `this+0x00000288` `float ForceComponentAbsB` (read, GUESS)
- `this+0x000002E8` `float TorqueBias2` (read, GUESS)
- `this+0x000032BC` `void* RigidBodyConstraint` (read_write, DERIVED)
- `this+0x00003514` `float LateralSlipScale` (read, DERIVED)
- `this+0x00003518` `float ForceScale` (read, DERIVED)
- `this+0x000035CC` `float CornerGrip0A` (read, GUESS)
- `this+0x00003610` `float CornerGrip0B` (read, GUESS)
- `this+0x00003618` `float CornerGrip0C` (read, GUESS)
- `this+0x000036C4` `float CornerGrip1A` (read, GUESS)
- `this+0x00003708` `float CornerGrip1B` (read, GUESS)
- `this+0x00003710` `float CornerGrip1C` (read, GUESS)
- `this+0x000037BC` `float CornerGrip2A` (read, GUESS)
- `this+0x00003800` `float CornerGrip2B` (read, GUESS)
- `this+0x00003808` `float CornerGrip2C` (read, GUESS)
- `this+0x000038B4` `float CornerGrip3A` (read, GUESS)
- `this+0x000038F8` `float CornerGrip3B` (read, GUESS)
- `this+0x00003900` `float CornerGrip3C` (read, GUESS)
- `this+0x00003984` `float PitchScale` (read_write, DERIVED)
- `this+0x00003998` `float ContactPatchThreshold` (read, DERIVED)
- `this+0x000039A4` `float[8] ContactLerpTable` (read, DERIVED)
- `this+0x000039A8` `float AntiRollCoupling` (read, DERIVED)
- `this+0x000039B0` `int PitchArrayCount` (read, DERIVED)
- `this+0x000039B4` `int ForceModeSelector` (read, DERIVED)
- `this+0x000039C8` `float AntiRollCouplingSecondary` (read, DERIVED)
- `this+0x000039D0` `float[] ContactPatchArray` (read, DERIVED)
- `this+0x000039F8` `int ContactPatchCount` (read, DERIVED)
- `this+0x00003A70` `float SlipScale` (read, DERIVED)
- `this+0x00003BF4` `float PreviousSpeed` (read_write, DERIVED)
- `this+0x00003BFC` `float AeroTableScale` (read, GUESS)
- `this+0x00003C00` `float[14] AeroForceTable` (read, GUESS)
- `this+0x00003C3C` `float PositiveTableScale` (read, DERIVED)
- `this+0x00003C40` `float[14] PositiveForceTable` (read, DERIVED)
- `this+0x00003C7C` `float NegativeTableScale` (read, DERIVED)
- `this+0x00003C80` `float[14] NegativeForceTable` (read, DERIVED)
- `this+0x00003CBC` `float AeroTableScale2` (read, GUESS)
- `this+0x00003CC0` `float[14] AeroForceTable2` (read, GUESS)
- `this+0x00003CFC` `float BracketScale` (read, DERIVED)
- `this+0x00003D00` `float[14] BracketTable` (read, DERIVED)
- `this+0x00003D3C` `float ForceMax` (read, DERIVED)
- `this+0x00003D44` `float DragCoefficient` (read, DERIVED)
- `this+0x00003D64` `float WearSlot0` (read_write, DERIVED)
- `this+0x00003D68` `float WearSlot1` (read_write, DERIVED)
- `this+0x00003D6C` `float WearSlot2` (read_write, DERIVED)
- `this+0x00003D70` `float WearSlot3` (read_write, DERIVED)

### F1CAIRacingLineTracker

AI racing-line path following and per-frame path-position tracking: node chain traversal, target node resolution, orientation/position state, suspension and wheel-contact updates, rigid-body constraint solving.

Methods: `0x004E9CA0`, `0x004EF7C0`

- `this+0x00003440` `unsigned char PathMode` (read, DERIVED)
- `this+0x000034B0` `float RotationMatrix00` (write, DERIVED)
- `this+0x000034B4` `float RotationMatrix01` (write, DERIVED)
- `this+0x000034B8` `float RotationMatrix02` (write, DERIVED)
- `this+0x000034BC` `float RotationMatrix10` (write, DERIVED)
- `this+0x000034C0` `float RotationMatrix11` (write, DERIVED)
- `this+0x000034C4` `float RotationMatrix12` (write, DERIVED)
- `this+0x000034C8` `float RotationMatrix20` (write, DERIVED)
- `this+0x000034CC` `float RotationMatrix21` (write, DERIVED)
- `this+0x000034D0` `float RotationMatrix22` (write, DERIVED)
- `this+0x000034D4` `float TargetPosX` (read_write, DERIVED)
- `this+0x000034D8` `float TargetPosY` (read_write, DERIVED)
- `this+0x000034DC` `float TargetPosZ` (read_write, DERIVED)
- `this+0x000034E0` `float OrientationX` (read_write, DERIVED)
- `this+0x000034E4` `float OrientationY` (read_write, DERIVED)
- `this+0x000034E8` `float OrientationZ` (read_write, DERIVED)
- `this+0x00003A9C` `int ConstraintSolveCounter` (read_write, DERIVED)

### WheelSuspensionGeometry

Per-wheel suspension/tire state initialization against the chassis local origin. Owner is UNKNOWN in the packet; separated from F1CVehicleTireSystem because its wheel-state layout (74-float stride) and origin fields are distinct.

Methods: `0x004E2540`

- `this+0x00000048` `float ChassisOriginX` (read, DERIVED)
- `this+0x0000004C` `float ChassisOriginY` (read, DERIVED)
- `this+0x00000050` `float ChassisOriginZ` (read, DERIVED)

### AIOpponentSelector

Builds the performance-ranked, deduplicated AI opponent roster for path assignment. Owner UNKNOWN; class and list-field layout DERIVED from the single function's output-list writes.

Methods: `0x004BFA00`

- `this+0x00000000` `node* ListHead` (write, DERIVED)
- `this+0x00000004` `node* ListTail` (write, DERIVED)
- `this+0x00000008` `node* ListSecondary` (write, GUESS)
- `this+0x0000000C` `int ListCount` (write, DERIVED)

### TireBrandTable

Tire brand name catalog with 36-byte-stride entries and gated not-found debug reporting.

Methods: `0x004D7880`

- `this+0x00000000` `int EntryCount` (read, DERIVED)
- `this+0x00000004` `TireBrandEntry* BrandTable` (read, DERIVED)

### F1CVehicle

The base vehicle object referenced by the pit machine and the AI racing-line tracker (via this+0x0). Fields carry the AI/pit sub-state, target node id, finish state, AI reason code, velocity and wheel-spin vectors, pit-box index, and pit-crew flags. The 'obj' base is kept distinct from the 'this' bases per the no-merge rule; the class name is a proposal.

Methods: 

- `obj+0x00001054` `int DetailLevel` (read, GUESS)
- `obj+0x0000105C` `int PitCrewMeshFlag` (write, DERIVED)
- `obj+0x000032C8` `int AiPitSubState` (read, DERIVED)
- `obj+0x000034C4` `float VelocityX` (read, GUESS)
- `obj+0x000034D0` `float VelocityY` (read, GUESS)
- `obj+0x000034DC` `float VelocityZ` (read, GUESS)
- `obj+0x000034F8` `float WheelSpinX` (read, GUESS)
- `obj+0x000034FC` `float WheelSpinY` (read, GUESS)
- `obj+0x00003500` `float WheelSpinZ` (read, GUESS)
- `obj+0x00004040` `int TargetNodeId` (read, DERIVED)
- `obj+0x00004064` `int FinishState` (read, DERIVED)
- `obj+0x00004068` `int AiReasonCode` (read_write, DERIVED)
- `obj+0x00004094` `int StepFlag` (write, DERIVED)
- `obj+0x000048A4` `int PitBoxIndex` (read, DERIVED)

## Compatibility contracts

- **PitMachineStateDispatchContract** — A replacement must preserve mode-byte dispatch at this+0x184, vehicle sub-state gating at obj+0x32C8 (values 2/3), optional-delegate ordering via this+0x8/+0xC/+0x10, event-value storage at this+0x188, and StateChangeNotify(state 4) on pit exit.
- **PitStopTimingContract** — Pit stop timing and limiter-ramp fields must persist: entry this+0x1A0, completion this+0x1A4, elapsed this+0x1A8, mid flag this+0x1AC, limiter base/timestamp/ceiling this+0x1B0..0x1B8, engaged this+0x1C0, wheel-force windows this+0x1C4/0x1D0/0x1D4; limiter deactivation must write the ceiling and clear AI reason code 9 (obj+0x4068).
- **TireForceTableLayoutContract** — Sign-selected force tables (+0x3C40 positive scaled by +0x3C3C, +0x3C80 negative scaled by +0x3C7C), aero tables (+0x3C00 scaled by +0x3BFC, +0x3CC0 scaled by +0x3CBC), contact-patch array +0x39D0 with count +0x39F8 and lerp table +0x39A4, mode selector +0x39B4, and friction-circle slip fields +0x3A70/+0x3514/+0x3518 with a [0,1] clamp.
- **TireWearModeContract** — Four wear slots at +0x3D64..0x3D70 clamp to FLT_MAX; per-frame recompute gated by dword_7CEA5C in (0,2], noise seed dword_8AAE70, optional division by flt_8ACF9C when dword_7C56A4==7 and mode==2; TireScrubReset clamps slot +0x3D64 when the +0x32BC field is nonzero.
- **AudioPitchScaleContract** — Per-frame pitch ratio a2 / this+0x3BF4; flag-gated array scaling via byte_7D01C4 bits 0-2 (sub_5881F0 paths, pitch field +0x3984, 8-byte-strided +0x39A4 array, +0x39D0 array scaled by the reciprocal ratio), ending with the TireBrushModelForceSolver call.
- **OpponentRosterLayoutContract** — Output list fields head/tail/secondary/count at this+0x0/+0x4/+0x8/+0xC; float-pair nodes (8-byte allocation via OperatorNewNhMallocWrapper) merge-sorted by float key; roster size read at vehicle-setup +0x14; name dedup with the byte_5EA438 empty fallback.
- **TireBrandTableLayoutContract** — Brand table at this[1] (this+0x4) with a 36-byte stride; entry offset 0 is the brand-name pointer; count at this+0x0; miss path logs a non-existent-tire message gated by dword_7C569C != 5.

## Unresolved

- Globals 0x0059E43C, 0x0059E440, 0x0059E450, 0x0059E46C, 0x0059E6FC, 0x0059E7E0, 0x0059E7E8, 0x0059E7F8, 0x0059E800, 0x0059E8A0, 0x0059E8A4, 0x0059E8CC, 0x0059E908, 0x0059E96C, 0x0059EB50, 0x0059ED18, 0x0059F11C, 0x005ACB50, 0x005ACB60, 0x005ACB64, 0x005AD208, 0x005AD240, 0x005AD248, 0x005EB978, 0x008ACEE0, 0x008AD298, 0x008B8F24 are packet evidence (mostly read-only float/double constants) but do not appear in the rendered raw source; they cannot be attributed to any operation.
- Field this+0x4824 is listed as read by ScaleAudioPitch but is absent from the decompiled body; possibly consumed inside sub_5881F0 or a folded path.
- Callee sub_5895A2 (float-to-table-index conversion) is assumed from call shape; its behavior is not in this packet.
- The event record layout passed to AIStateMachineWithModeDispatch (mode byte at a2+8, value float at a2+4) is only partially evidenced.
- The v14/v13 buffers produced by ConditionalDelegateDispatch and consumed by sub_4A3320 have unknown contents.
- The meaning of the vehicle sub-state obj+0x32C8 (2/3) and the identification of sub_4A5EA0 as pits-under-red are DERIVED from existing analysis, not proven by this packet.
- Caller context of StateChangeNotify (0x004A5C80) and sub_4B3400 is not described by the packet raw source.
- Inline pit-box alignment thresholds (25.0, 1.5, -5.0, 0.85, 4.0, 0.04) have no explicit semantic evidence.
- The wheel-state layout written by WheelSuspensionTireStateInit (relative +140..+252, this[74*a2+82] and this[74*a2+105] bases) has no packet field evidence; parameter roles a4/a5/a6 (fill suggests camber/toe/caster) are not evidenced.
- Sub-structure roles in PhysicsTireSystemConstructor (force, dual-array, 5-loop, tire, tail zero-init) are descriptive only; the callees are unnamed helpers.
- The pit-exit audio dispatch routine (obj+0x1054 -> sound controller) has no callee entry in packet evidence.
- The two float values stored per opponent node (GuardedListAccessor value and sub_4BF6A0 parameter) and which one is the merge-sort key are unresolved; the 200-pass selection cap is unexplained.
- sub_588410 (name comparator) and sub_884ED (LCRNG) behaviors are assumed from context, not in this packet.
- Existing analysis calls dword_7CEA5C the engine wear mode with values 0/2/3, which conflicts with the raw source guard (0, 2]; raw source wins, exact mode semantics unverified.
- F_3x3MatrixTransformWithTranslation is called in AIVehiclePathPositionTracking with v11, never assigned earlier in the decompiled body.
- Scratch addresses this+0x4034 and this+0x34B0 used in raw source have no packet field entries.
- Global dbl_7C91DC (written by TireScrubReset) has no packet global entry; global dbl_7C7428 is read but its role is unclear.
- The 8-byte-stride +0x39A4 array and the special 918-element stride in ScaleAudioPitch are derived from raw arithmetic; the container layout is unknown.
- The sign-flag FP branches (positive vs negative force table) are compiler-captured comparisons whose deciding predicate is elided in several functions.
- Whether a2/a3/a4 in the tire force functions are speed/slip/load quantities is not established by the packet.
