# VehicleAIAndPitSubsystem

Scope: `vehicle_ai_and_pit`  
Trust: `DERIVED`

DERIVED proposal for the vehicle_ai_and_pit scope from 21 validated functions. The AI core groups as GUESS class VehicleAIController: AICollision (0x004BEF60) gates on the session-type global dword_7C56A4 (7 = race), verifies four 296-byte wheel-contact entries at a2+2100, resolves engine-wear mode 3 (dword_7CEA5C) through DriverSetupParamLookupByID and otherwise applies two probability checks against the flt_8AAE74 noise table; AIDriverSorting (0x004BF390) walks the dword_7C54F0 vehicle array comparing lap count (+0x403C), total time (+0x4098) and best lap (+0x409C) and swaps positions through ConditionalFieldSetter; AITickUpdate (0x004BF4F0) is the per-frame tick that advances the per-vehicle lap counter, clamps race time into vehicle +16536, forces vehicle state and re-sorts via AIDriverSorting, then resets the scoring ring-buffer globals (83EE54..83EE60, 8AAE64..8AAE6C, 7D2E50/7D2E54); VehicleAIControlFlag (0x004C7A70) toggles bit 0 of the AI flag at this+0x48BC from CollisionContactIteration. Pit support: PitStopPhaseAdvance (0x004C15A0) advances a phase counter at this+0xB14C through a jump table and calls RaceStandingsRankingsComputation and TimerCountdownWithStateTransition in phase 7; PitTimerStateInit (0x004D23D0) copies the pit-timer fields (0xB0/0xB4/0xB8/0xC1/0xC2/0xD8), dispatches sub_42D140(&dword_7C569C, 4) and broadcasts the timestamp via sub_4BC2D0; PitCloseTeamReadyCheck (0x004D2210) sweeps vehicles with state <= 1 calling sub_4BC9B0(vehicle+0x4034, 1, 0). Physics/wear: TireBrushModelForceSolver (0x004E8010) iterates 15 slip samples accumulating brush-model forces over the four wheel records and runs a bisection solve via sub_5895A2; FuelConsumptionAndWear (0x004ED960) consumes fuel by RPM/throttle, recomputes mass, decays tire wear, reseeds weather grip noise, and drives the per-wheel random failure switch (jpt_4EDBA3, engine/gearbox/puncture/random wear) gated on sub_4D21D0; SteeringForceWithRandom (0x004F0DD0) blends a speed-squared noise term with random sign toward the force-feedback base and feeds the UI timer tween. Generic runtime objects complete the set: DirectXTextureCreationWithMipmapChain (0x00507496), PitCrewAnimationOffsetUpdate (0x0054BF60), EntityFlagSetSubInitChain (0x00551440), FloatToIntConversionChain (0x00553A20), AppendNodeToDoublyLinkedListTail (0x00560EB0), DestroyAudioArrayFreeElementsThenContainer (0x00564740), FloatToIntConversionWithRemainder (0x005676C0), FloatToIntTruncateWithRemainder (0x00567700) and RingBufferHeadTailReset (0x0057B530). All class owners except the packet's DERIVED Vehicle owner for AIDriverSorting are GUESS because the packet keeps every other function owner UNKNOWN.

## Function roles

- `0x004BEF60` **VehicleAIController** — AI collision-state check. Returns 0 immediately when the session type global dword_7C56A4 is not 7; verifies four consecutive wheel-contact entries (stride 296 from a2+2100, first dword non-null and byte at +64 set); returns 2 when the vehicle state at a2+15724 is 2; in engine-wear mode 3 (dword_7CEA5C) resolves the outcome through DriverSetupParamLookupByID on a2+16444; otherwise applies two probability checks gated by byte flags this+0x340/this+0x341 using divider this+0x35C and multiplier this+0x344, drawing samples from the flt_8AAE74 table via the incrementing byte counter dword_8AAE70. Invoked from EngineFailureCheck (0x004BEC55).
- `0x004BF390` **VehicleAIController** — AI driver position sorting. Iterates position slots 1..vehicle count over the dword_7C54F0 pointer array; finds the vehicle whose position field (+0x4060) matches the slot; decides whether the driver a1 should pass based on lap count (+0x403C) then finish-line total time (+0x4098) in a race session (dword_7C56A4 == 7) or on best lap (+0x409C) otherwise; on a pass, swaps positions through ConditionalFieldSetter (0x004BC2F0) and stops further swaps for the call. Returns the session type.
- `0x004BF4F0` **VehicleAIController** — Per-frame AI timing update over the live vehicle array: sets the half-distance flag byte_8ACFA0, skips vehicles in states 3 or 2, advances a per-vehicle lap counter at +16444, writes the clamped race time into +16536, writes the offset-adjusted race delta into +16568 using the field at this+0x354 and flt_8ACF90, forces vehicle state to 1, and re-sorts the grid via AIDriverSorting (0x004BF390). Idle vehicles (state 0) are set to state 1. Ends by resetting the scoring ring-buffer globals (83EE54/58/5C to &unk_7D2E54, 8AAE64/68/6C to &unk_83EE64, 7D2E50 and 83EE60 zeroed) and returns &unk_83EE64.
- `0x004C15A0` **PitStopPhaseController** — Advances a session/pit-stop phase counter at this+0xB14C. Cases 1-6 increment the phase (1->2 .. 6->7) and zero byte 0xB150; case 7 calls RaceStandingsRankingsComputation (0x004C1660) and then TimerCountdownWithStateTransition (0x004C1670) whose low byte becomes the function result, falling through to the shared tail that zeros byte 0xB150. Unhandled phase values also hit the shared tail. The switch dispatches through the jump table at 0x004C1644. Invoked from sub_4A0590 and sub_4A0760.
- `0x004C29D0` **DelegationChain** — Thin delegation chain: calls sub_4C2990(this) to obtain an integer, then invokes ConditionalCallWrapper_29b0(this, result) and returns its result. The bodies of both callees are outside this packet, so the meaning of the intermediate value (condition, selector or payload) is unresolved.
- `0x004C7A70` **VehicleAIController** — Read-modify-write of the AI control flag bitset at this+0x48BC: nonzero a2 sets bit 0 (value OR 1, AI-controlled), zero a2 clears bit 0 (value AND 0xFFFFFFFE, AI released); stores the result back and returns it. Called by CollisionContactIteration (0x00460DD0) during collision contact response.
- `0x004D2210` **PitTimer** — Iterates the active-vehicle array dword_7C54F0 over dword_5C329C entries; for each vehicle whose dword at offset 13000 (0x32C8) is <= 1, calls sub_4BC9B0 on the field at vehicle + 16436 (0x4034) with arguments (1, 0). Returns the active-vehicle count. Invoked from the pit-timer path consistent with a pit-close/team-ready state sweep.
- `0x004D23D0` **PitTimer** — Initializes the pit-timer struct: clears flag bytes 0xC1 and 0xC2, copies the stored value at a2+8 into 0xD8 and the timestamp at a2+12 into 0xB0, computes 0xB4 = timestamp + stored offset at 0xB8, dispatches registration via sub_42D140(&dword_7C569C, 4), then broadcasts the timestamp at 0xB0 to every active vehicle via sub_4BC2D0(vehicle+16436, this+0xB0). Returns the vehicle count.
- `0x004D7E00` **VTableDispatchObject** — Two-stage vtable dispatch on a thiscall object: dispatches the check method at vtable+0x18 (slot 6) and, when non-zero, invokes sub_4D7FE0(this); independently, when the byte flag at this+0x8 is set, invokes PhaseBasedAudioParticleEnvelope (0x004D7FF0); finally dispatches the method at vtable+0x4 (slot 1) and returns its result. The concrete class is unknown.
- `0x004E8010` **TireBrushModelSolver** — Per-frame tire brush-model force solver: iterates 15 normalized slip-ratio samples and accumulates longitudinal/lateral force contributions over the four per-wheel records (stride 248 from base 13868) with load-transfer sign patterns, derives a corner-weight/average-load value from the load-transfer mode field at 14772, normalizes per-wheel vertical loads, applies wet/dry grip scaling (flag a2) to the 15-entry lookup tables at 15424/15488, and runs a 15-iteration bisection solve inverting a slope lookup via sub_5895A2 with linear interpolation into the output array at 15616.
- `0x004ED960` **VehicleFuelAndWear** — Per-frame vehicle update consuming fuel by RPM/power/throttle/dt, clamping at zero and writing error code 9 to the register at obj+0x4068 when empty; recomputes total mass and inverse mass; sums per-tire wear, applies grip decay and decrements per-wheel tire wear; interpolates tire friction by track grip; re-seeds weather-driven grip noise about every 5.5 seconds and recomputes tire brush forces via TireBrushModelForceSolver (0x004E8010); when sub_4D21D0 reports the race in progress, drives the per-wheel failure countdowns (this[3929+i]) through the switch jump table at 0x004EE134 dispatching engine (error 1), gearbox (error 5), puncture (error 2) and random wear (error 4) failures, posting events via sub_41AC50 and setting failure mode state this[0x3D60]=2. Called every frame from MainGameTickUpdate.
- `0x004F0DD0` **SteeringForceFeedback** — Computes a steering force-feedback value with randomized sign noise: reads the base force from the object field at offset 0x1058 via the pointer in *this, builds a speed-squared noise term from the velocity vector this[3387..3389] (this+0x34EC/0x34F0/0x34F4) scaled through mph conversion, randomizes its sign through RandLCGRandomNumberGenerator (0x005884ED), blends toward the base force using dbl_8AFE98, clamps the result to [-0.3, 0.3] and feeds it into the UI timer tween (0x004E0C90). Enable condition uses byte_7C56AC and dword_8AB6E4. Called from the steering path sub_4F0430.
- `0x00507496` **DirectXTextureSurface** — Object constructor for a DirectX texture/surface from a source descriptor: stores the vtable off_5ADB80, constructs the embedded 256-element (16 bytes each) sub-object array at this+0x30 via sub_5008C2 with sub_5007EC as element constructor, copies format metadata and the 6-dword dimension header into bytes 0x1030-0x1044, selects a render-temp data pointer (unk_5D7748 or unk_5D76C8), stores the mip stride (a3 >> 3) at 0x1068 and the mip-level flag at 0xC, converts the packed ARGB color at 0x10 to normalized RGBA floats, and for indexed formats (IDs 40 and 41) fills the 256-entry palette from source data or opaque white; computes dimension deltas (0x1058-0x1064) and, when the mip flag is set, advances the mip-origin accumulator. Returns this.
- `0x0054BF60` **PitCrewAnimationController** — Walks a linked list of animation elements (head at this+0x204, next pointer at node+0x10) and, for each entry matching the type id a2, adds the (a4, a5) offset to the X/Y position components of every vertex in the entry's vertex array using a 48-byte stride; the vertex component base is a3-selectable (data+32/+36 for a3==0, data+40/+44 for a3==1). Each updated entry has dirty bit 0x800 set at entry+0x30. Part of the pit crew animation update path invoked by CameraViewportRenderSetup (0x004FBD70).
- `0x00551440` **EntityInitChain** — Entity init chain: sets flag bit 0x2000 in the flags word at this+0x4, copies parameter-table data into per-entity data block 0 via PerEntityDataBlockCopyFromParameterTable (0x00551390), starts and resets the high-resolution timer via TimerStartViaQueryPerformanceCounter (0x005563E0) and HighResolutionTimerReset (0x00556440), and zeroes the timer accumulator at this+0x10. Returns the reset call's value.
- `0x00553A20` **FloatConversionUtility** — Two-path float-array processing gated by flag bit 0x40000 in this+0x18: when set, calls sub_55C860(this, a2, a2+3, a3) and clears bit 0x400; when clear, converts a2[4], a2[3], a2[1], a2[0] to ints via CRTFtol (0x00587BDC), dispatches the converted ints to sub_553AA0(v5, v6, a3, this), and clears bit 0x400. Returns the updated flags in both paths. Invoked from FloatVectorWithConditionalTransform (0x00494C20), F_2DTextRenderingWithScissorRectangle (0x0049B370) and sub_49F1C0 (0x0049F1C0).
- `0x00560EB0` **DoublyLinkedListContainer** — Appends a node to the tail of a doubly linked list. First unlinks the incoming node from any existing list (redirecting its previous node's next pointer around it and its next node's previous pointer back); then, if the list head this[11] (offset 0x2C) is set, walks the next-pointer chain (+52/0x34) to the tail and writes the new node there, otherwise the head becomes the new node; finally sets the node's previous pointer to the old tail, clears its next pointer, and sets bit 2 (value 4) in the node's flags dword (+36). Returns the updated flags value. Reached from DoublyLinkedListNodeMover (0x0054BA00).
- `0x00564740` **PointerArrayContainer** — Destroys a pointer-array container: iterates the element buffer (this+0x0) for lpMem[1] (this+0x4) entries calling BatchLoopWithMemoryCleanup (0x00564860) on each element, then frees the buffer and the container struct via sub_58AA6F (0x0058AA6F). Callers include NetworkCleanup (0x00562C50), DirectDrawDisplayModeInit (0x00563E00) and sub_5640F0 (0x005640F0).
- `0x005676C0` **FloatConversionUtility** — Splits a float seconds value a3 into whole minutes and a seconds remainder: multiplies by 0.016666668 (flt_59E9C0, ~1/60), truncates with CRTFtol (0x00587BDC), stores the integer minutes into *a1 (this+0x0), stores a3 - minutes * 60.0 (flt_59F118) into *a2, and returns the minute count. Timing/time-display helper; called by 0x004D24D0 and FloatToIntTruncateWithRemainder (0x00567700).
- `0x00567700` **FloatConversionUtility** — Converts an input value into whole seconds and a remainder: v8 = CRTFtol(a3 * 0.00027777778) is the truncated whole seconds written to *a1; the residual v7 = a3 - v8 * 3600.0 is decomposed by FloatToIntConversionWithRemainder (0x005676C0) into the a2/a4 outputs, whose return value is propagated.
- `0x0057B530` **RingBuffer** — Resets a ring buffer's head and tail WORD indices (this+0x1000 and this+0x1002) to 0, marking the buffer empty, and returns 0. Unconditional; no early return. Called from AI/session paths (sub_57DE30, sub_57E570, SocketAddressInit).

## Proposed classes

### VehicleAIController

Per-frame AI driver simulation: collision-state check with probabilistic wheel/missing and wear-based outcomes, grid position sorting by lap/time fields, the per-frame tick that updates lap/time/state and re-sorts the grid, and the AI-control flag toggle used during collision contact.

Methods: `0x004BEF60`, `0x004BF390`, `0x004BF4F0`, `0x004C7A70`

- `this+0x00000340` `BYTE collisionCheckFlagA` (read, GUESS)
- `this+0x00000341` `BYTE collisionCheckFlagB` (read, GUESS)
- `this+0x00000344` `FLOAT collisionProbabilityMultiplier` (read, GUESS)
- `this+0x0000035C` `FLOAT collisionProbabilityDivider` (read, GUESS)
- `this+0x00000354` `FLOAT raceTimeOffset` (read, GUESS)
- `this+0x0000403C` `DWORD lapCount` (read, GUESS)
- `this+0x00004060` `DWORD gridPosition` (read, GUESS)
- `this+0x00004098` `FLOAT totalTimeOnFinishLine` (read, GUESS)
- `this+0x0000409C` `FLOAT bestLap` (read, GUESS)
- `this+0x000048BC` `DWORD aiControlFlag` (read_write, GUESS)

### PitStopPhaseController

Advances a session/pit-stop phase counter (1..7) and triggers race-standings computation and the timer countdown transition at phase 7.

Methods: `0x004C15A0`

- `this+0x0000B14C` `DWORD phaseCounter` (read_write, GUESS)
- `this+0x0000B150` `BYTE phaseTransitionFlagByte` (write, GUESS)

### DelegationChain

Thin delegation wrapper that forwards the object through a helper and a conditional call wrapper whose semantics live outside this packet.

Methods: `0x004C29D0`


### PitTimer

Pit-timer session state: initialization from a source struct (stored value, timestamp and computed time, two flag bytes) with registration dispatch and per-vehicle timestamp broadcast, plus the pit-close/team-ready sweep over active vehicles.

Methods: `0x004D23D0`, `0x004D2210`

- `this+0x000000B0` `FLOAT timestampFloat` (read, GUESS)
- `this+0x000000B4` `FLOAT computedTime` (write, GUESS)
- `this+0x000000B8` `FLOAT storedTimeOffset` (read, GUESS)
- `this+0x000000C1` `BYTE flagByteA` (write, GUESS)
- `this+0x000000C2` `BYTE flagByteB` (write, GUESS)
- `this+0x000000D8` `DWORD storedValue` (write, GUESS)

### VTableDispatchObject

Thiscall object whose update dispatches a gated check method, a flag-gated audio/particle envelope, and a final unconditional vtable slot; the concrete class is unknown.

Methods: `0x004D7E00`

- `this+0x00000000` `void** vtablePtr` (read, GUESS)
- `this+0x00000008` `BYTE envelopeFlagByte` (read, GUESS)
- `obj+0x00000004` `void* finalDispatchMethodSlot` (read, GUESS)
- `obj+0x00000018` `void* checkMethodSlot` (read, GUESS)

### TireBrushModelSolver

Per-frame tire brush-model force solver: slip-sample accumulation over four wheel records, load-transfer corner-weight derivation, vertical-load normalization, wet/dry grip table scaling, and the bisection slope-inversion solve.

Methods: `0x004E8010`

- `this+0x00003514` `FLOAT gravityField` (read, GUESS)
- `this+0x00003518` `FLOAT loadScalarField` (read, GUESS)
- `this+0x0000358C` `FLOAT cornerWeightFLB` (read, GUESS)
- `this+0x00003594` `FLOAT cornerWeightFRB` (read, GUESS)
- `this+0x00003610` `FLOAT* wheelArrayBase` (read, GUESS)
- `this+0x0000362C` `FLOAT wheelSlipInput` (read, GUESS)
- `this+0x00003638` `FLOAT wheelLoadField` (read, GUESS)
- `this+0x00003674` `FLOAT wheelSlipCap` (read, GUESS)
- `this+0x00003684` `FLOAT cornerWeightFRC` (read, GUESS)
- `this+0x0000368C` `FLOAT cornerWeightFLC` (read, GUESS)
- `this+0x00003708` `FLOAT quarterWeightFL` (read, GUESS)
- `this+0x0000377C` `FLOAT cornerWeightRLC` (read, GUESS)
- `this+0x00003784` `FLOAT cornerWeightRLC2` (read, GUESS)
- `this+0x00003800` `FLOAT rearAxleWeight` (read, GUESS)
- `this+0x00003874` `FLOAT cornerWeightRRC` (read, GUESS)
- `this+0x0000387C` `FLOAT cornerWeightRRC2` (read, GUESS)
- `this+0x000038F8` `FLOAT frontAxleWeight` (read, GUESS)
- `this+0x000039B4` `DWORD loadTransferMode` (read, GUESS)
- `this+0x00003A30` `FLOAT frontWeightField` (read, GUESS)
- `this+0x00003A44` `FLOAT rearWeightField` (read, GUESS)
- `this+0x00003A6C` `FLOAT loadFactorField` (read, GUESS)
- `this+0x00003A70` `FLOAT loadField` (read, GUESS)
- `this+0x00003BF4` `FLOAT tableScaleField` (read, GUESS)
- `this+0x00003BFC` `FLOAT inverseSlipFactorFL` (write, GUESS)
- `this+0x00003C3C` `FLOAT inverseSlipFactorFR` (write, GUESS)
- `this+0x00003C40` `FLOAT* lookupTableBase` (read, GUESS)
- `this+0x00003C7C` `FLOAT inverseSlipFactorRL` (write, GUESS)
- `this+0x00003C80` `FLOAT* forceOutputArrayBaseA` (write, GUESS)
- `this+0x00003CBC` `FLOAT inverseSlipFactorRR` (write, GUESS)
- `this+0x00003CC0` `FLOAT* forceOutputArrayBaseB` (write, GUESS)
- `this+0x00003CFC` `FLOAT relatedInverseSlipValue` (write, GUESS)
- `this+0x00003D3C` `FLOAT cornerWeightResult` (write, GUESS)
- `this+0x00003D40` `FLOAT averageLoadField` (write, GUESS)
- `this+0x00003D44` `FLOAT blendedVerticalLoad` (write, GUESS)
- `this+0x00004024` `FLOAT wheelForceFactor` (read, GUESS)

### VehicleFuelAndWear

Per-frame fuel consumption, mass recomputation, tire wear and friction, weather grip-noise reseeding, and the random per-wheel failure engine (engine/gearbox/puncture/random wear) gated on the race being in progress.

Methods: `0x004ED960`

- `this+0x00000000` `void* objectPtr` (read, GUESS)
- `obj+0x00004068` `DWORD errorRegister` (write, GUESS)
- `this+0x00003510` `FLOAT baseMass` (read, GUESS)
- `this+0x00003514` `FLOAT inverseTotalMass` (write, GUESS)
- `this+0x00003518` `FLOAT totalMass` (write, GUESS)
- `this+0x00003570` `FLOAT throttle` (read, GUESS)
- `this+0x00003578` `FLOAT gearboxHealthThreshold` (read, GUESS)
- `this+0x000035D0` `FLOAT tireWearAccumulator` (read, GUESS)
- `this+0x00003624` `FLOAT tireFriction` (write, GUESS)
- `this+0x00003630` `FLOAT tireWearLevel` (read_write, GUESS)
- `this+0x00003634` `FLOAT tireWearRate` (read, GUESS)
- `this+0x00003978` `FLOAT fuelLevel` (read_write, GUESS)
- `this+0x00003984` `FLOAT enginePowerFactor` (read, GUESS)
- `this+0x00003994` `FLOAT engineRPM` (read, GUESS)
- `this+0x00003998` `FLOAT rpmLimit` (read, GUESS)
- `this+0x000039A4` `void* enginePowerTablePtr` (read_write, GUESS)
- `this+0x000039B0` `DWORD enginePowerTableCount` (read, GUESS)
- `this+0x000039EE` `BYTE punctureFlagByte` (write, GUESS)
- `this+0x00003A30` `FLOAT gearboxWearFactorA` (read_write, GUESS)
- `this+0x00003A44` `FLOAT gearboxWearFactorB` (read_write, GUESS)
- `this+0x00003BF4` `FLOAT frictionMultiplier` (read, GUESS)
- `this+0x00003BF8` `FLOAT lastWeatherNoiseUpdate` (read_write, GUESS)
- `this+0x00003D48` `FLOAT enginePowerFactorA` (read_write, GUESS)
- `this+0x00003D4C` `FLOAT enginePowerFactorB` (read_write, GUESS)
- `this+0x00003D50` `FLOAT enginePowerFactorC` (read_write, GUESS)
- `this+0x00003D60` `DWORD failureModeState` (write, GUESS)

### SteeringForceFeedback

Force-feedback steering value with randomized sign noise, blended toward the force-feedback base and clamped into the UI timer tween.

Methods: `0x004F0DD0`

- `this+0x00000000` `void* objectPtr` (read, GUESS)
- `obj+0x00001058` `FLOAT forceFeedbackBase` (read, GUESS)
- `this+0x000034EC` `FLOAT velocityX` (read, GUESS)
- `this+0x000034F0` `FLOAT velocityY` (read, GUESS)
- `this+0x000034F4` `FLOAT velocityZ` (read, GUESS)
- `this+0x00003540` `FLOAT steeringValue` (read, GUESS)

### DirectXTextureSurface

DirectX texture/surface object construction: vtable install, 256-entry sub-object palette array, format/dimension header copy, mip stride and level flag, packed-color to float RGBA conversion, and indexed-palette initialization for formats 40/41.

Methods: `0x00507496`

- `this+0x00000000` `void** vtablePtr` (write, GUESS)
- `this+0x00000004` `DWORD formatTypeID` (write, GUESS)
- `this+0x00000008` `DWORD storedParameterA4` (write, GUESS)
- `this+0x0000000C` `DWORD mipLevelFlag` (write, GUESS)
- `this+0x00000010` `DWORD packedColor` (write, GUESS)
- `this+0x00000014` `DWORD paletteFormatFlag` (write, GUESS)
- `this+0x00000018` `DWORD mipOriginAccumulator` (write, GUESS)
- `this+0x0000001C` `FLOAT colorR` (write, GUESS)
- `this+0x00000020` `FLOAT colorG` (write, GUESS)
- `this+0x00000024` `FLOAT colorB` (write, GUESS)
- `this+0x00000028` `FLOAT colorA` (write, GUESS)
- `this+0x0000002C` `void* renderTempDataPtr` (write, GUESS)
- `this+0x00000034` `FLOAT paletteEntry0G` (write, GUESS)
- `this+0x00000038` `FLOAT paletteEntry0B` (write, GUESS)
- `this+0x0000003C` `FLOAT paletteEntry0A` (write, GUESS)
- `this+0x00001030` `DWORD dimHeader0` (write, GUESS)
- `this+0x00001034` `DWORD dimHeader1` (write, GUESS)
- `this+0x00001038` `DWORD dimHeader2` (write, GUESS)
- `this+0x0000103C` `DWORD dimHeader3` (write, GUESS)
- `this+0x00001040` `DWORD dimHeader4` (write, GUESS)
- `this+0x00001044` `DWORD dimHeader5` (write, GUESS)
- `this+0x00001048` `DWORD mipAccumulatorA` (write, GUESS)
- `this+0x0000104C` `DWORD mipAccumulatorB` (write, GUESS)
- `this+0x00001050` `DWORD copiedScalarC` (write, GUESS)
- `this+0x00001054` `DWORD copiedScalarD` (write, GUESS)
- `this+0x00001058` `DWORD dimDeltaX` (write, GUESS)
- `this+0x0000105C` `DWORD dimDeltaY` (write, GUESS)
- `this+0x00001060` `DWORD dimDeltaZ` (write, GUESS)
- `this+0x00001064` `DWORD mipOriginAdvance` (write, GUESS)
- `this+0x00001068` `DWORD mipStride` (write, GUESS)

### PitCrewAnimationController

Pit-crew animation element list traversal that applies per-entry vertex offset updates (a3-selectable component bases) and marks the entries dirty, invoked during camera/viewport render setup.

Methods: `0x0054BF60`

- `this+0x00000204` `void* animationListHead` (read, GUESS)
- `this+0x0000032C` `DWORD entryCount` (read, GUESS)
- `this+0x00000330` `DWORD entryTypeID` (read, GUESS)
- `this+0x00000338` `DWORD vertexCount` (read, GUESS)
- `this+0x0000033C` `void* vertexDataPtr` (read, GUESS)
- `this+0x00000368` `DWORD entryDirtyFlag` (write, GUESS)

### EntityInitChain

Entity initialization chain that sets a flag bit, copies parameter-table data into a per-entity data block, and starts/resets a high-resolution timer while zeroing the accumulator.

Methods: `0x00551440`

- `this+0x00000000` `void* timerHandle` (read, GUESS)
- `this+0x00000004` `DWORD flagsWord` (read_write, GUESS)
- `this+0x00000010` `DWORD timerAccumulator` (write, GUESS)

### FloatConversionUtility

Float-to-integer conversion and time-formatting helpers: the flag-gated float-array conversion chain, and the seconds-to-minutes/remainder and seconds-with-remainder decomposition helpers.

Methods: `0x00553A20`, `0x005676C0`, `0x00567700`

- `this+0x00000000` `DWORD* minuteOutput` (write, GUESS)
- `this+0x00000018` `DWORD flagsWord` (read_write, GUESS)

### DoublyLinkedListContainer

Doubly linked list container that appends nodes at the tail, unlinking the incoming node from any prior list first and marking it in-list.

Methods: `0x00560EB0`

- `this+0x0000002C` `void* listHead` (read, GUESS)
- `*(*(this+0x60)+0x34)+0x00000034` `void* tailNextLink` (write, GUESS)

### PointerArrayContainer

Pointer-array container teardown: per-element cleanup followed by buffer and container deallocation.

Methods: `0x00564740`

- `this+0x00000000` `void** elementBuffer` (read, GUESS)
- `this+0x00000004` `DWORD elementCount` (read, GUESS)

### RingBuffer

Ring buffer with WORD head/tail indices at the top of the object, reset to the empty state.

Methods: `0x0057B530`

- `this+0x00001000` `WORD headIndex` (write, GUESS)
- `this+0x00001002` `WORD tailIndex` (write, GUESS)

## Compatibility contracts

- **VehicleArrayAndSessionGlobalsContract** — A replacement executable must preserve the globals gating the AI and pit logic: the vehicle pointer array dword_7C54F0 with active count dword_5C329C, the session type global dword_7C56A4 (value 7 = race/qualifying session, the AICollision gate), the wear-mode global dword_7CEA5C (value 3 selects the engine-wear outcome paths), and the shared session/registration word dword_7C569C written through sub_42D140.
- **VehicleSortingFieldContract** — Grid sorting reads the driver position at vehicle +0x4060 (compared against the slot), the lap count at +0x403C, the finish-line total time at +0x4098 and the best lap at +0x409C; swapped positions are written through ConditionalFieldSetter to vehicle +0x4034 (0x4034 = 16436), while the value read for comparisons lives at +0x4060. The AI control flag lives at vehicle +0x48BC (bit 0).
- **ScoringRingBufferContract** — AITickUpdate resets the scoring ring-buffer globals each tick: dword_83EE54/83EE58/83EE5C are set to &unk_7D2E54, dword_83EE60 is zeroed, dword_8AAE64/8AAE68/8AAE6C are set to &unk_83EE64, dword_7D2E50 is zeroed, and the tick returns &unk_83EE64; the byte half-distance flag 0x008ACFA0 is set at tick start and the race-time offset global flt_8ACF90 (0x008ACF90) is read for the per-vehicle delta.
- **PitTimerStateContract** — The pit-timer object holds a stored value at this+0xD8, a timestamp float at this+0xB0, a computed time at this+0xB4, a stored time offset at this+0xB8 and two flag bytes at 0xC1/0xC2; initialization dispatches sub_42D140(&dword_7C569C, 4) and broadcasts the timestamp to every active vehicle receiver at vehicle+16436 via sub_4BC2D0. The pit-close/team-ready sweep calls sub_4BC9B0(vehicle+0x4034, 1, 0) for vehicles whose dword at +0x32C8 is <= 1.
- **PitStopPhaseEnumContract** — The phase counter at this+0xB14C runs 1..7; phases 1-6 advance to the next phase and zero byte 0xB150, and phase 7 triggers RaceStandingsRankingsComputation (0x004C1660) followed by TimerCountdownWithStateTransition (0x004C1670); the shared tail zeroes byte 0xB150 on every path.
- **WheelContactTableContract** — The AI collision check reads four consecutive wheel-contact entries at vehicle + 2100 with stride 296; each entry's first dword must be non-null and its byte at +64 set, otherwise the outcome is collision (1); the fixed severity outcome 2 is keyed on the vehicle state at a2+15724.
- **VehicleFailureErrorCodeContract** — The failure engine writes first-write-wins error codes into the register at obj+0x4068 (reached through the object pointer at this+0): 9 for out-of-fuel, 1 for engine, 5 for gearbox, 2 for puncture, 4 for random wear; the completed-failure state is written to this[0x3D60] (value 2) and each failure posts an event through sub_41AC50(object, type).
- **DirectXTextureLayoutContract** — The constructed texture/surface installs vtable off_5ADB80 at +0, format/type ID at +4, mip-level flag at +0xC, packed ARGB color at +0x10, a 256-entry 16-byte sub-object palette array at +0x30 (palette channels at +0x34/0x38/0x3C for entry 0), a 6-dword dimension header at +0x1030..0x1044, mip accumulator at +0x1048/0x104C, scalar copies at +0x1050/0x1054, dimension deltas at +0x1058..0x1064 and the mip stride at +0x1068; formats 40/41 are treated as indexed/palette.
- **PitCrewAnimationListContract** — The pit-crew animation controller walks a linked list from the head at this+0x204 (next at node+0x10); each node carries an entry count at this+0x32C and entry records with type id at this+0x330, vertex count at this+0x338 and vertex data pointer at this+0x33C; matched entries get their 48-byte-stride vertex X/Y components offset by (a4, a5) at the a3-selected bases (data+32/+36 or data+40/+44) and the entry's dirty bit 0x800 is set at entry+0x30.
- **DoublyLinkedListNodeContract** — Doubly linked list nodes link through previous at node+48 and next at node+52 (the tail-walk reads +52), carry a flags dword at node+36 whose bit 2 (value 4) marks the node in-list, and the list head lives at this+0x2C; appending unlinks the node from any prior list before relinking.
- **PointerArrayContainerContract** — The pointer-array container stores the element buffer at this+0x0 and the element count at this+0x4; teardown calls the per-element cleanup (0x00564860) for each element and frees both the buffer and the container through sub_58AA6F.
- **RingBufferIndexContract** — The ring buffer exposes its head and tail as WORD indices at this+0x1000 and this+0x1002; resetting both to 0 marks the buffer empty and returns 0.

## Unresolved

- Class owners are all GUESS except the packet's DERIVED Vehicle owner for AIDriverSorting (0x004BF390): the packet keeps every other function owner UNKNOWN, so VehicleAIController, PitStopPhaseController, DelegationChain, PitTimer, VTableDispatchObject, TireBrushModelSolver, VehicleFuelAndWear, SteeringForceFeedback, DirectXTextureSurface, PitCrewAnimationController, EntityInitChain, FloatConversionUtility, DoublyLinkedListContainer, PointerArrayContainer and RingBuffer are grouped on shared responsibility only.
- TireBrushModelSolver and VehicleFuelAndWear share offsets 0x3A30/0x3A44/0x3BF4/0x3514/0x3518 on the same this base with different proposed meanings (front/rear weight and gearbox wear factors; friction multiplier; gravity/load fields); per the equal-offset rule these are kept as separate class fields and their common ownership is not proven by the packet.
- The vehicle-struct byte offsets used by AITickUpdate (16484 state, 16444 lap counter, 16536 race time, 16568 offset delta, per-vehicle accumulator slots at array-relative 8148208/8148624) and by AICollision (a2+2100 wheel-contact base, a2+15724 state, a2+16444 setup parameter, a2+17616/17628 speed and wear floats) have no field evidence references in this packet; the existing fill's names are DERIVED and not adopted here.
- The large set of float constants read per static facts but absent from the raw decompiled bodies (0x0059E420, 0x0059E438, 0x0059E43C, 0x0059E440, 0x0059E444, 0x0059E448, 0x0059E450, 0x0059E460, 0x0059E4E8, 0x0059E670, 0x0059E6F8, 0x0059E7E8, 0x0059E7F8, 0x0059E7FC, 0x0059E800, 0x0059E824, 0x0059E828, 0x0059E84C, 0x0059E874, 0x0059E8B4, 0x0059E8C8, 0x0059E8CC, 0x0059E8F8, 0x0059E918, 0x0059E93C, 0x0059E99C, 0x0059E9B8, 0x0059E9BC, 0x0059EA60, 0x0059ED18, 0x0059F128, 0x005ACB44, 0x005ACD3C, 0x005ACDC4, 0x005ACEB8, 0x005ACEE8, 0x005AD1B0, 0x005AD1B4, 0x005AD1B8, 0x005AD1BC, 0x005AD1C0, 0x005AD1F8, 0x005AD200, 0x005AD22C, 0x005EB978, 0x008ACEE0, 0x008B78A0) are believed to back folded FPU literals (0.01, 0.071428575, 0.275, 0.225, 0.92, 0.84, 0.97, 1/60, 1/3600, 60.0, 2.2369363, 0.0049999999) but mapping each to a specific constant is not established.
- flt_59E440 (0x0059E440) is packet-listed as a read in AICollision, AIDriverSorting, AITickUpdate, FuelConsumptionAndWear and SteeringForceWithRandom but does not appear by name in the raw bodies; it is assumed to back a zero/epsilon threshold but that mapping is not proven.
- The pit-close/team-ready state at vehicle +13000 (0x32C8) and the exact pit/team-ready effect of sub_4BC9B0(field, 1, 0) are unconfirmed; why PitCloseTeamReadyCheck re-reads dword_5C329C every iteration is unclear.
- The AITickUpdate ring-buffer globals (83EE54..83EE60, 8AAE64..8AAE6C, 7D2E50, 7D2E54) and byte_8ACFA0 (existing fill: HalfDistanceFlag) are mapped as scoring/session structures at DERIVED trust only; the contents of unk_7D2E54 and unk_83EE64 are not established.
- In PitStopPhaseAdvance case 7 the byte at 0xB150 is zeroed twice (once logically by the case-7 goto path and once at the shared tail); the phase enum's concrete session stages are unknown, consumed by sub_4A0590 and sub_4A0760.
- The semantics of sub_4C2990 and ConditionalCallWrapper_29b0 (whether the intermediate value is a condition, selector or payload) are unknown; their bodies are outside this packet.
- The concrete class behind VTableDispatchObject's vtable is unknown; the check method (+0x18), conditional sub_4D7FE0 and final method (+0x4) semantics and who sets the flag at this+0x8 are outside this packet.
- The 18 module float constants of TireBrushModelForceSolver, the per-wheel record stride interpretation (62 dwords, slip cap/grip/weight), the physical meaning of the bisection output, and the identity of the 15-entry lookup tables at 15424/15488 are all DERIVED from arithmetic shape, not proven.
- The per-wheel failure countdown timers (this[3929+i]) and per-wheel wear sources have no packet field evidence references; sub_41AC50's second argument encoding the failure type (0 engine, 1 gearbox, 2 puncture, 3 random wear) is inferred from dispatch order, not evidenced.
- The speed-squared noise term in SteeringForceWithRandom: the random sign distribution via zero-ness of (rand & 0x80000001) is unusual and the physical units implied by 2.2369363 / 0.0049999999 are plausible but not independently confirmed.
- Format IDs 40 and 41 are treated as indexed/palette formats but their concrete enum meaning in the render system is not established; the 256 x 16-byte sub-object array at this+0x30 may be pure palette storage or a mip-chain sub-object list.
- The packet field table for PitCrewAnimationOffsetUpdate expresses node/entry accesses as this-relative offsets while the raw source accesses them relative to the node pointer i and entry pointer v7; the field:this:0x00000224 read reported by the packet is not visible as a distinct access in the raw source.
- In AppendNodeToDoublyLinkedListTail the field evidence field:this:0x00000060 (a list-descriptor pointer) has no explicit access in the raw source shown; node offsets +48/+52 and the flags dword +36 have no separate packet field evidence entries.
- The two float globals 0x0059E9B8 and 0x0059E9BC read by FloatToIntTruncateWithRemainder are not visible as named operands in the inlined raw source; they may hold 0.00027777778 and 3600.0 but that mapping is unconfirmed.
- DestroyAudioArrayFreeElementsThenContainer's sub_58AA6F and BatchLoopWithMemoryCleanup (0x00564860) cleanup semantics are not independently verified; container layout beyond this+0x0/this+0x4 is unknown.
- RingBufferHeadTailReset's owner and buffer size are unknown; the relationship to the calling socket/AI session structures is unproven.
- The legacy ABI label on AITickUpdate (AI_Tick_Update_Ring_Buffer_Reset) is narrower than the tick body; the canonical name AITickUpdate is kept.
- The globals dword_8B78A0 (0x008B78A0) and the module float constants listed for 0x00553A20 are not referenced by the raw source; their roles are unclear.
