# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Derived architecture proposal for 16 validated functions in scope generic_runtime_objects. Three packet-CONFIRMED owner functions form an F1CVehicle method set (0x00423E80 race-struct init, 0x00424B20 per-frame AI camera viewport/frustum + AI-state reset, 0x00429960 per-frame AI pit-stop strategy). Two packet-DERIVED owner functions form an AIDriver method set (0x00424080 per-driver AI ability config load, 0x00426100 per-frame steering-angle computation). The remaining eleven functions have packet-UNKNOWN owners and are grouped into a GUESS GenericRuntimeObject class (0x00403CD0 spline node lookup, 0x00407DD0 list traversal, 0x0040F1C0 scene-object loader state machine, 0x00415230 named format-entry list, 0x00423060 getter, 0x00423CA0/0x00423DB0 steering decomposition helpers, 0x00425660/0x004258C0 AI driver-state resets, 0x00429FD0 tire-tier selection, 0x0042A740 clamp). AIDriver and GenericRuntimeObject AI helpers both reach the vehicle through the this+0 indirection pointer and touch the same 0x44xx/0x45xx race-state region as F1CVehicle methods; a shared vehicle super-struct is plausible but not proven by this packet and is flagged in unresolved.

## Function roles

- `0x00403CD0` **GenericRuntimeObject** — Track spline node lookup returning position+orientation (7-float entries at this+0x150) with backwards-neighbour fallback, linear interpolation, and node-0 fallback
- `0x00407DD0` **GenericRuntimeObject** — Linked-list traversal: head->cursor save, per-node ConditionalMatchTrigger(value, a2) call, next-pointer advance until null
- `0x0040F1C0` **GenericRuntimeObject** — Seven-mode scene-object load/unload state machine: modes 0-5 branch on sub_45A8E0 into clear/keep paths; mode 6 gates vehicle physics, runs suspension update, copies sub-object position
- `0x00415230` **GenericRuntimeObject** — Named format-entry lookup (name + secondary key) over a singly-linked list; on miss allocates/initializes/appends a 176-byte entry and returns its index
- `0x00423060` **GenericRuntimeObject** — Trivial getter: returns the dword at this+0xC4 with no side effects
- `0x00423CA0` **GenericRuntimeObject** — Decompose target vehicle velocity into longitudinal (this[6]) and lateral (this[4]) components relative to a direction vector, called every frame from AISteering
- `0x00423DB0` **GenericRuntimeObject** — Decompose target vehicle position offset into longitudinal (this[3]) and lateral (this[1]) distance relative to a direction vector, called every frame from AISteering
- `0x00423E80` **F1CVehicle** — Vehicle race-struct constructor: tire-system and sub-object construction, AI state flag clear, ~50-field sentinel/zero initialization across 0x413C..0x461C
- `0x00424080` **AIDriver** — Per-driver AI ability config load via string-keyed config lookups, difficulty/grip scaling, start-performance assembly, and season-gated mechanical-failure scheduling
- `0x00424B20` **F1CVehicle** — Per-frame AI driver camera viewport/frustum and AI-state reset: sentinel writes, slot-array reset, distance accumulator, AI flag clear, command-queue flush, ring-buffer init
- `0x00425660` **GenericRuntimeObject** — Unconditional clear of the 4-byte field at this+0x4510 (driverStatus); called per-frame from AIMainUpdate
- `0x004258C0` **GenericRuntimeObject** — AI steering dynamics reset: zero accumulator at +0x4434, 1.0f multiplier at +0x4438, speed/threshold-gated driverStatus=2 write
- `0x00426100` **AIDriver** — Per-frame AI steering-angle computation toward the target waypoint with speed-dependent scale, reversing sign, 0.1/frame rate limit, and [-1,1] clamp
- `0x00429960` **F1CVehicle** — Per-frame AI pit-stop strategy init: tire-compound resolve, five-slot pit-schedule seed, fuel-adjusted lap targets, speed/lap-time factor, weighted tier selection tail path
- `0x00429FD0` **GenericRuntimeObject** — Tire-compound tier selection from grip level flt_8AFEE8 with randomized mid-range boundaries; maps tier to compound index by scanning the compound list
- `0x0042A740` **GenericRuntimeObject** — Clamp float at this+0x4484 into [5.0, a2]; lower bound 5.0 sourced from global flt_59E7EC

## Proposed classes

### F1CVehicle

Vehicle race-state holder: constructs the race struct and tire-system sub-object (0x00423E80), resets per-frame AI camera viewport/frustum and AI state (0x00424B20), and computes the per-frame AI pit-stop strategy (0x00429960). Owns the 0x41xx/0x44xx/0x45xx race-state and AI-viewport field regions.

Methods: `0x00423E80`, `0x00424B20`, `0x00429960`

- `this+0x00000000` `int postProcessInput` (write, DERIVED)
- `this+0x00000004` `int raceInt_04` (write, DERIVED)
- `this+0x00000008` `int raceInt_08` (write, DERIVED)
- `this+0x00003988` `float fuelLoad` (read, DERIVED)
- `this+0x00003990` `float fuelConsumptionFactor` (read, DERIVED)
- `this+0x0000413C` `int pitDecisionTimer` (write, DERIVED)
- `this+0x00004140` `byte raceByte_4140` (write, DERIVED)
- `this+0x0000416C` `int raceInt_416C` (write, DERIVED)
- `this+0x00004170` `int raceInt_4170` (write, DERIVED)
- `this+0x000041B4` `int proximitySlotId` (write, DERIVED)
- `this+0x000042CC` `int teamRecognitionFlag` (write, DERIVED)
- `this+0x000043F4` `int raceZero_043F4` (write, DERIVED)
- `this+0x000043F8` `int raceZero_043F8` (write, DERIVED)
- `this+0x000043FC` `int raceZero_043FC` (write, DERIVED)
- `this+0x00004400` `int raceZero_04400` (write, DERIVED)
- `this+0x00004404` `int raceZero_04404` (write, DERIVED)
- `this+0x00004408` `int raceZero_04408` (write, DERIVED)
- `this+0x0000440C` `int raceZero_0440C` (write, DERIVED)
- `this+0x00004414` `int raceZero_04414` (write, DERIVED)
- `this+0x00004418` `int raceZero_04418` (write, DERIVED)
- `this+0x0000441C` `int raceZero_0441C` (write, DERIVED)
- `this+0x00004420` `int raceZero_04420` (write, DERIVED)
- `this+0x00004424` `int raceZero_04424` (write, DERIVED)
- `this+0x00004428` `int raceZero_04428` (write, DERIVED)
- `this+0x0000442C` `int raceZero_0442C` (write, DERIVED)
- `this+0x00004430` `int raceZero_04430` (write, DERIVED)
- `this+0x00004434` `int raceZero_04434` (write, DERIVED)
- `this+0x00004410` `byte raceByte_4410` (write, DERIVED)
- `this+0x00004438` `float raceFloatOne_4438` (write, DERIVED)
- `this+0x0000443C` `float raceFloat_443C` (write, DERIVED)
- `this+0x00004440` `float speed` (write, DERIVED)
- `this+0x00004444` `float raceFloatOne_4444` (write, DERIVED)
- `this+0x00004448` `int raceZero_4448` (write, DERIVED)
- `this+0x0000444C` `int raceZero_444C` (write, DERIVED)
- `this+0x00004450` `int trackPartFromPitExit` (write, DERIVED)
- `this+0x00004454` `int raceZero_4454` (write, DERIVED)
- `this+0x00004458` `int raceZero_4458` (write, DERIVED)
- `this+0x0000445C` `byte raceByteOne_445C` (write, DERIVED)
- `this+0x00004468` `int raceZero_04468` (write, DERIVED)
- `this+0x0000446C` `int raceZero_0446C` (write, DERIVED)
- `this+0x00004470` `int raceZero_04470` (write, DERIVED)
- `this+0x00004474` `int raceZero_04474` (write, DERIVED)
- `this+0x00004478` `int raceZero_04478` (write, DERIVED)
- `this+0x0000447C` `int raceZero_0447C` (write, DERIVED)
- `this+0x00004480` `int raceZero_04480` (write, DERIVED)
- `this+0x00004484` `int raceSentinel_4484` (write, DERIVED)
- `this+0x00004488` `byte raceByteOne_4488` (write, DERIVED)
- `this+0x0000448C` `int raceZero_0448C` (write, DERIVED)
- `this+0x00004490` `int raceZero_04490` (write, DERIVED)
- `this+0x00004494` `int raceZero_04494` (write, DERIVED)
- `this+0x00004498` `int raceZero_04498` (write, DERIVED)
- `this+0x0000449C` `int raceZero_0449C` (write, DERIVED)
- `this+0x000044A0` `int raceZero_044A0` (write, DERIVED)
- `this+0x000044A4` `int raceZero_044A4` (write, DERIVED)
- `this+0x000044A8` `int raceZero_044A8` (write, DERIVED)
- `this+0x000044AC` `int raceZero_044AC` (write, DERIVED)
- `this+0x000044B0` `int raceIntMinusOne_44B0` (write, DERIVED)
- `this+0x00004460` `float viewportFarPlaneSentinel` (write, DERIVED)
- `this+0x00004464` `float viewportScalar_4464` (write, DERIVED)
- `this+0x00004454` `float distanceAccumulator` (write, DERIVED)
- `this+0x00004474` `float nearPlaneDistance` (write, DERIVED)
- `this+0x00004484` `float maxDistanceSentinel_4484` (write, DERIVED)
- `this+0x00004510` `int driverStatus` (write, DERIVED)
- `this+0x00004524` `int raceZero_4524` (write, DERIVED)
- `this+0x00004538` `float maxSpeedSentinel` (write, DERIVED)
- `this+0x00004540` `float viewportScalarSix_4540` (write, DERIVED)
- `this+0x00004544` `int viewportIntOne_4544` (write, DERIVED)
- `this+0x00004548` `int pitLaneRouteFlag` (write, DERIVED)
- `this+0x0000454C` `int callToBox` (write, DERIVED)
- `this+0x00004550` `int waypointSetSelector` (write, DERIVED)
- `this+0x00004554` `float viewportFloatOne_4554` (write, DERIVED)
- `this+0x00004558` `int viewportIntFifty_4558` (write, DERIVED)
- `this+0x00004560` `int viewportZero_4560` (write, DERIVED)
- `this+0x00004564` `int viewportZero_4564` (write, DERIVED)
- `this+0x00004584` `int viewportZero_4584` (write, DERIVED)
- `this+0x000045F4` `byte aiControlFlag` (write, DERIVED)
- `this+0x000045F8` `int raceZero_45F8` (write, DERIVED)
- `this+0x000045FC` `int raceZero_45FC` (write, DERIVED)
- `this+0x0000461C` `float raceFloat_461C` (write, DERIVED)
- `this+0x00004588` `int pitStopCount` (write, DERIVED)
- `this+0x0000458C` `int nextChosenTires` (write, DERIVED)
- `this+0x00004590` `int pitLapTarget_0` (read_write, DERIVED)
- `this+0x00004594` `int pitFuelSlot_1` (write, DERIVED)
- `this+0x00004598` `int pitScheduleAnchor` (write, DERIVED)
- `this+0x0000459C` `int pitCompoundSlot` (write, DERIVED)
- `this+0x000045A0` `int pitLapTarget_1` (read_write, DERIVED)
- `this+0x000045B0` `int pitLapTarget_2` (read_write, DERIVED)
- `this+0x000045C0` `int pitLapTarget_3` (read_write, DERIVED)
- `this+0x000045D0` `int pitLapTarget_4` (write, DERIVED)
- `this+0x000045E0` `int pitZero_45E0` (write, DERIVED)
- `this+0x000045E8` `float fuelAdjustedLapFactor` (read_write, DERIVED)
- `this+0x000045F0` `float speedLapTimeFactor` (read_write, DERIVED)
- `obj+0x000032C8` `int slotLiveFlag` (read, GUESS)

### AIDriver

Per-driver AI configuration and steering: loads per-driver ability values from a string-keyed config list (0x00424080) and computes the per-frame steering angle toward the target waypoint (0x00426100). Reaches the vehicle through the this+0 indirection pointer.

Methods: `0x00424080`, `0x00426100`

- `this+0x00000000` `pointer vehicleIndirectionPtr` (read, DERIVED)
- `this+0x000034E0` `float carPosX` (read, DERIVED)
- `this+0x000034E8` `float carPosY` (read, DERIVED)
- `this+0x00004144` `int mechanicalFailureLap` (write, DERIVED)
- `this+0x00004148` `int mechanicalFailureType` (write, DERIVED)
- `this+0x00004408` `float steeringPredictInput` (read, DERIVED)
- `this+0x0000442C` `float steeringOutput` (write, DERIVED)
- `this+0x00004468` `int waypointIndex` (read, DERIVED)
- `this+0x0000448C` `float headingCos` (read, DERIVED)
- `this+0x00004494` `float headingSin` (read, DERIVED)
- `this+0x00004498` `float targetPosX` (read, DERIVED)
- `this+0x000044A0` `float targetPosY` (read, DERIVED)
- `this+0x000044A4` `float distanceToTarget` (write, DERIVED)
- `this+0x000044B4` `float steeringSpeedDivisor` (read, DERIVED)
- `this+0x000044B8` `float startPerformance` (read_write, DERIVED)
- `this+0x000044BC` `float startStalls` (read_write, DERIVED)
- `this+0x000044C0` `float qualifyingAbility` (read_write, DERIVED)
- `this+0x000044C4` `float raceAbility` (read_write, DERIVED)
- `this+0x000044C8` `float rainAbility` (read_write, DERIVED)
- `this+0x000044CC` `float passingAbility` (read_write, DERIVED)
- `this+0x000044D0` `float crashProbability` (write, DERIVED)
- `this+0x000044D4` `float abilityDerived_44D4` (write, DERIVED)
- `this+0x000044D8` `float abilityDerived_44D8` (write, DERIVED)
- `this+0x000044DC` `float completedLaps` (write, DERIVED)
- `this+0x000044F4` `float raceGripDerived` (read_write, DERIVED)
- `this+0x000044F8` `float trackAggression` (read_write, DERIVED)
- `this+0x000044FC` `int startMode` (write, DERIVED)
- `this+0x00004500` `float corneringAdd` (write, DERIVED)
- `this+0x00004504` `float corneringMultiplier` (write, DERIVED)
- `this+0x00004510` `int driverStatus` (read, DERIVED)
- `this+0x0000457C` `float aiDifficultyScalar` (write, DERIVED)
- `this+0x00004580` `float rainGripModifier` (write, DERIVED)

### GenericRuntimeObject

GUESS grouping of runtime helper objects whose packet owners are UNKNOWN: track spline container lookup, generic linked-list traversal, scene-object loader state machine, named format-entry list, AI steering decomposition/state helpers, tire-tier selection, and single-field getters/clamps. Fields named conservatively; several helpers access vehicle AI state through a this+0 indirection.

Methods: `0x00403CD0`, `0x00407DD0`, `0x0040F1C0`, `0x00415230`, `0x00423060`, `0x00423CA0`, `0x00423DB0`, `0x00425660`, `0x004258C0`, `0x00429FD0`, `0x0042A740`

- `this+0x00000150` `pointer splineDataPtr` (read, GUESS)
- `this+0x00000154` `unknown splineMetadata_154` (read, GUESS)
- `this+0x00000158` `unknown splineMetadata_158` (read, GUESS)
- `this+0x0000015C` `unknown splineMetadata_15C` (read, GUESS)
- `this+0x00000160` `unknown splineMetadata_160` (read, GUESS)
- `this+0x00000164` `unknown splineMetadata_164` (read, GUESS)
- `this+0x00000018` `pointer listHead` (read, GUESS)
- `this+0x00000020` `pointer traversalCursor` (read_write, GUESS)
- `this+0x00000028` `unknown listField_28` (unknown, GUESS)
- `this+0x0000000C` `float positionX` (read_write, GUESS)
- `this+0x00000010` `float positionY` (read_write, GUESS)
- `this+0x00000014` `float positionZ` (read_write, GUESS)
- `this+0x0000001C` `int modeSelector` (read, GUESS)
- `this+0x00000020` `pointer subObjectPtr` (read, GUESS)
- `*(this+0x20)+0x000034D4` `float subObjectPosX` (read, GUESS)
- `*(this+0x20)+0x000034D8` `float subObjectPosY` (read, GUESS)
- `*(this+0x20)+0x000034DC` `float subObjectPosZ` (read, GUESS)
- `this+0x00000000` `pointer entryListHead` (read_write, GUESS)
- `this+0x00000004` `pointer entryListTail` (write, GUESS)
- `this+0x00000008` `pointer entryListFirstNode` (write, GUESS)
- `this+0x0000000C` `int entryCount` (read_write, GUESS)
- `obj+0x00000004` `pointer listNodeNextPtr` (read, GUESS)
- `obj+0x00000008` `byte listNodeActiveFlag` (unknown, GUESS)
- `this+0x000000C4` `int fieldC4` (read, GUESS)
- `this+0x00000000` `pointer vehicleIndirectionPtr` (read, GUESS)
- `this+0x00000010` `float lateralVelocityComponent` (write, GUESS)
- `this+0x00000018` `float longitudinalVelocityComponent` (write, GUESS)
- `this+0x00000004` `float lateralDistanceComponent` (write, GUESS)
- `this+0x0000000C` `float longitudinalDistanceComponent` (write, GUESS)
- `this+0x000037CC` `float steeringThreshold_37CC` (read, GUESS)
- `this+0x000038C4` `float steeringThreshold_38C4` (read, GUESS)
- `this+0x00004434` `int steeringAccumulator` (write, GUESS)
- `this+0x00004438` `float steeringMultiplier` (write, GUESS)
- `this+0x00004440` `float speed` (read, GUESS)
- `this+0x00004510` `int driverStatus` (write, GUESS)
- `this+0x00004510` `int driverStatus` (write, GUESS)
- `this+0x00003978` `pointer compoundListPtr` (read, GUESS)
- `this+0x00003988` `unknown tierField_3988` (read, GUESS)
- `this+0x0000458C` `int fallbackTier` (read, GUESS)
- `this+0x00004484` `float clampedFloat_4484` (read_write, GUESS)

## Compatibility contracts

- **TrackSplineEntryLayout** — InterpolateTrackSplineNode (0x00403CD0) requires a spline array at this+0x150 of 7-float (28-byte) entries per node: 3-float position, then 3 orientation dwords at entry+12; an all-zero entry denotes invalid and triggers a backwards-2-node search with linear interpolation at fractional step (a2-v6)/2, else node-0 fallback. A replacement executable must preserve this stride and zero-means-invalid convention.
- **PerDriverConfigKeyStrings** — initAIDriverConfig (0x00424080) reads per-driver abilities from a string-keyed config list using keys startsdry/startswet/startstalls/qualifyingabil/trackaggressio/rainability/raceability/passing/corneringadd/corneringmult/crash/completedlaps/script; the config list head is the AudioChannelStop return value. A replacement must keep these key spellings.
- **AICommandQueueFlushPerFrame** — The per-frame AI reset (0x00424B20) must flush the AI command-message queue via AICommandMessageQueueDispatcher(0,0) and initialize ring-buffer fields via AIRingBufferFieldInit before AI steering recomputation; AIClearStateFlags must run before per-frame AI recomputation.
- **PitScheduleStrideLayout** — AIPitstopStrategyInit (0x00429960) seeds a five-slot stride-4-dword pit schedule anchored near +0x4598 (lap targets at +0x4590/+0x45A0/+0x45B0/+0x45C0, compound slot +0x459C, stop count +0x4588) using dword_8ACF8C as the fill sentinel and 8 as the compound code; a replacement must preserve the 4-dword stride and these anchors.
- **SteeringOutputClampAndRateLimit** — computeSteeringAngle (0x00426100) writes the AI steering output at this+0x442C rate-limited to at most 0.1 per frame and clamped to [-1.0, 1.0]; reversing mode (driverStatus==6 at +0x4510) inverts the sign. A replacement must reproduce this clamp and limit for identical behavior.
- **NamedFormatEntryAllocation** — NamedEntryLookupInFormatList (0x00415230) allocates 176-byte entries (OperatorNewNhMallocWrapper) and 12-byte list nodes on lookup miss, initializes two 5-dword sub-structs at entry+16 and three element arrays (entry+56/+96/+136), and runs driver-file-path setup via sub_414600(entry,1) whose non-zero return destroys the partial entry and returns -1. A replacement must preserve entry size and init layout.

## Unresolved

- The 0x44xx/0x45xx race-state region is written by F1CVehicle methods (0x00424B20, 0x00429960), read/written by AIDriver methods (0x00424080, 0x00426100), and touched by GenericRuntimeObject AI helpers (0x00425660, 0x004258C0) — notably 0x4510 driverStatus, 0x442C steeringOutput, 0x4434/0x4438, 0x4440 speed. This is consistent with one shared vehicle struct hosting an embedded AIDriver sub-state, but the packet does not prove common ownership; the offsets are therefore mirrored across the two classes instead of merged.
- The this+0 indirection pointer dereferences to the vehicle (driver-name string at +17952=0x4620, slot-live flag at obj+0x32C8); the exact AIDriver-to-vehicle relationship (embedded sub-object vs. pointer member) is DERIVED/GUESS, not proven.
- Global flt_59E440 (0x0059E440) is listed as read by several functions (0x00403CD0, 0x00423CA0, 0x00423DB0, 0x00426100, 0x00429960) but never appears in any raw source body; the skeleton proposal of a zero-threshold role is DERIVED and unverifiable from this packet.
- Many 0x59E4xx/0x59E8xx float globals are flagged as read but absent from the raw .c bodies (0x0059E43C, 0x0059E444, 0x0059E450, 0x0059E46C, 0x0059E600, 0x0059E670, 0x0059E6F8, 0x0059E7E8, 0x0059E800, 0x0059E824, 0x0059E84C, 0x0059E850, 0x0059E854, 0x0059E858, 0x0059E85C, 0x0059E864, 0x0059E868, 0x0059E8BC, 0x0059E8CC, 0x0059E908, 0x0059E96C, 0x0059E970); presumed folded FPU literals or callee-consumed, ungrounded.
- The dword_8AC394 secondary-key table with 1060-byte stride (used by 0x00415230) and the dword_8ACF9C lap divisor (used by 0x00424080) are external to this packet; their layouts are unknown.
- Season-mode semantics of dword_7C56A4 == 7 and the dword_7CEA5C enum (<=2 random stall scheduling vs ==3 race-events list parsing) in 0x00424080/0x00429960 are GUESS-level.
- The 0x80000001 sign-mask idiom in 0x00429FD0's randomized 0.15..0.2 grip branch is a decompiler artifact; exact intended randomness unclear.
- Tier values 4/5/6 and the 0.15/0.2/0.5/0.55/0.8/0.85 grip thresholds in 0x00429FD0 are likely tire-compound tiers (hard/medium/soft) but unproven.
- Magic scaling constants in 0x00424080 (0.0099999998, 0.045454547, 0.67000002, 0.001, 0.89999998, base 22.0) and the 0.44B8 clamps (-1065353216 / 1082130432) and *0.1+1.0 reshape have no exposed meaning beyond arithmetic roles.
- The v36|v37 unsigned-byte flag condition that clamps startPerformance 0x44B8 to -1065353216 originates in c0/c2 status flags not visible in the decompiled source.
- The dword literals 1176256410 and 1176255488 (0x00429960) and 2139095039 sentinels (0x00423E80/0x00424B20) are kept as opaque dwords; no IEEE-754 interpretation is asserted.
- The mechanical-failure loop (0x00424080) writes this+0x4144/0x4148 with 8-byte stride; whether the random-stall and race-events paths can coexist is unknown.
- off_5C3188 string contents unknown; treated as a synonym of aStallDns only because both branches share value 5.
- The destination this+17632 (0x44E0, script path) written by 0x00424080 is referenced from raw source only and is not in the packet field list.
- The mapping of this[0..3] to head/tail/first-node/count in 0x00415230 is inferred from the field list, not stated in source.
- The 7-float spline node stride and the orientation interpretation (quaternion/Euler) in 0x00403CD0 are DERIVED from indexing arithmetic, not locked by the packet.
- The three extra dwords per spline node (spline+7n+3) are labeled orientation from caller names only (DERIVED).
- Semantics of the 0.9 thresholds (this+0x37CC/0x38C4) and driverStatus value 2 in 0x004258C0 are derived from surrounding context only.
- driverStatus naming for offset 0x4510 originates in skeleton prose (CONFIRMED there); this packet's raw source shows only unconditional writes.
- abi:lead LEGACY name Scene_Object_Loader_State_Machine is retained as a lead only; owner remains UnknownObject.
- field:obj:0x00000008 (per-node flag byte) is in the packet field list but is not read anywhere in the function source.
- Nested-base refs field:*(this+0x18):0x00000000, field:*(*(this+0x18)+0x0):0x00000000, field:*(this+0x20):0x00000000, field:*(*(this+0x20)+0x0):0x000048BC identify head-node/vtable members of sub-objects whose owning classes are not established; left unresolved.
- Jump-table global 0x0040F2D8 (jpt_40F1D0) and 0x00429EA0/0x00429EA8 (switch artifacts) are structural, not semantic, evidence.
