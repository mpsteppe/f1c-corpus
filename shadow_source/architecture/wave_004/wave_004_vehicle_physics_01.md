# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

Sixteen validated vehicle-physics functions reconstructed as ten worker-proposed classes. The dominant object is VehiclePhysicsSimulation, a single large per-vehicle state carrying engine durability/thermal data, collision-damage accumulation, suspension/wheel solver state, tire-force inputs, the physics-body name mapping and the active/contact/vibration flags. Two collision-shape initializers share a discriminator + data-pointer layout; a wheel-group dispatcher owns six-group slot decoding and the typed 3/4/5 state update, both resolving sentinel slots through the repair-state owner arrays. Audio and selection helpers are thin wrappers over scene and game-state dispatch helpers. All IR owners are UNKNOWN; the proposed owners are DERIVED/GUESS and several offset conflicts are recorded in unresolved rather than forced into a clean design.

## Function roles

- `0x0040D2CA` **VehicleSelectionController** — Cyclically shifts the player selection index (dword_7C54DC +/- 1, wrapped against the vehicle count dword_5C329C), dispatches game state for the newly selected vehicle via GameStateDispatchChain, refreshes every vehicle visual entry via sub_4F0D20, and returns the count.
- `0x0040D340` **VehicleSelectionController** — Thin camera/game-state wrapper: reads the tracked-vehicle index dword_7C54E4, indexes the vehicle pointer array dword_7C54F0, and dispatches a game-state change for the tracked vehicle via GameStateDispatchChain.
- `0x0040E2B0` **AudioPhysicsMixer** — Computes the averaged position of a packed array, lerps it with the bounding-box center using a mode-selected blend factor (0.35 for mode 2, else 0.70), adds a queried three-field offset, writes it back, and applies the offset vector to the object via GlobalVectorOffsetUpdate.
- `0x0040EA30` **PhysicsCollisionShape** — Initializes a physics collision shape: writes discriminator this+8, subtype constant 2 at this+1C and the data pointer at this+20, derives scaled distance-squared values from the bounding box, stores them via CollisionInvMassStore, bulk-writes six constant fields, writes four shape constants into the sub-struct at this+20, and honors an a4 override through ShortComputation_e770.
- `0x0040EBD0` **PhysicsCollisionShape** — Initializes a physics collision shape: writes discriminator this+8, subtype constant 4 at this+1C and the external data pointer at this+20, stores inverse-mass 10.0 and six float constants via CollisionInvMassStore/F_6FieldBulkSetter, and honors an a4 override through ShortComputation_e770. Invoked by sub_40FE50.
- `0x00410BC0` **WheelGroupDispatcher** — Decodes a packed 36-byte wheel input record into 13 scaled floats and a 6-bit group selector, dispatches on the selector (jump table) into six wheel groups, validates each wheel index against a per-group count, resolves sentinel (-1) slots in groups 3-5 via the 4656-stride repair-state owner arrays through ShortComputation_e770 and RepairServiceStateDispatcher, and converts the slot physics state via PhysicsStateVectorConversion.
- `0x00411330` **WheelGroupDispatcher** — Dispatches a physics state update on operation type 3/4/5, each mapping to a distinct per-type array base (this+4C/+58/+64) and per-type global owner table; writes a float slot, runs ShortComputation_e770, SwitchBasedFloatProcessing and PhysicsStateVectorConversion, marks the element active at +10, and returns the conversion result.
- `0x00430750` **VehiclePhysicsSimulation** — Per-wheel tire contact-patch force computation: guards on tire-brand and compound lookups, combines two suspension/load force terms, aggregates wheel forces, applies a tire-model polynomial over clamped deflection inputs, runs quaternion transforms on compound data, and returns the summed force normalized by the total load term.
- `0x00438690` **VehiclePhysicsSimulation** — Per-frame collision damage accumulation with DNF detection: integrates impact-energy and thermal damage terms into the accumulator; on overflow marks the first non-DNF grid vehicle as DNF (state 5) and resets the damage state; otherwise applies a cosine-modulated damage response and writes a reciprocal damage output.
- `0x00438DA0` **VehiclePhysicsSimulation** — Initializes the vehicle physics body name-to-index mapping: loads the joint system, allocates a per-body joint data array (48 bytes per body), and resolves named physics bodies (body, steering arms, wheels, spindles, rear axle, fuel tank, driver head) via linear search. Called from TireModelInit.
- `0x0043E770` **VehiclePhysicsSimulation** — Sets collision contact flags for one wheel (281-DWORD per-wheel stride): always marks the per-wheel contact flag; when in contact ORs flag bit 1 into matching body-pair contact entries; otherwise scans the two wheel-body contact lists and ORs flag bit 1 into matching entries. Invoked by RepairServiceStateDispatcher.
- `0x0043EF20` **VehiclePhysicsSimulation** — Per-frame engine durability, thermal and component-failure simulation: applies RPM/load durability damage and flags durability-exhausted state (code 9), runs coupled coolant and oil temperature dynamics, and drives a random component-failure/repair state machine over the component health block. Called per frame from VehiclePhysicsIntegrationStep.
- `0x0043F7F0` **VehiclePhysicsSimulation** — Core per-frame suspension and wheel dynamics solver: per-wheel constraint projection, tire spring/damper curves, slip-force target, then a time-stepped LCP solve over a 6x7 constraint matrix; applies resolved impulses to the chassis and wheel body force accumulators. Called from WheelDataCopy and PhysicsStepFrame.
- `0x00447160` **VehiclePhysicsSimulation** — Boolean vehicle-active check: returns 0 when the thresholds at this+1DB4 or this+19C are <= 0.0 or the active flag at this+1C59 is zero; returns 1 when the override flag at this+1D0C is set; otherwise combines the secondary-state byte at *(this+1F00)+344C with prior condition-code flags.
- `0x004471F0` **VehiclePhysicsSimulation** — Updates suspension-vibration state: always sets the active flag this+1C59; when the accumulator is below the threshold, either copies source values into accumulator/rate (trigger mode) or computes a noise-based vibration output from the flt_8AB274 table.
- `0x00448570` **PhysicsSubComponentOwner** — Destroys and frees up to five physics sub-component pointers (four-slot loop at this+4C, tail at this+5C), recursively destroying non-null sub-components, freeing them via FreeWrapper_7bcf and clearing the slots.

## Proposed classes

### VehiclePhysicsSimulation

Per-vehicle physics simulation state: tire-force computation, collision-damage accumulation with DNF detection, physics-body name-to-index mapping, wheel collision contact flagging, engine durability/thermal and component-failure simulation, the suspension/wheel LCP solver, the vehicle-active gate, and suspension-vibration state. The dominant object of the packet; 8 of the 16 functions operate on it.

Methods: `0x00430750`, `0x00438690`, `0x00438DA0`, `0x0043E770`, `0x0043EF20`, `0x0043F7F0`, `0x00447160`, `0x004471F0`

- `this+0x00000018` `float brakeScaleTermA` (read, GUESS)
- `this+0x00000020` `float brakeScaleTermB` (read, GUESS)
- `this+0x000000BC` `float impactMagnitude` (read, GUESS)
- `this+0x000000CC` `float damageSourceA` (read, GUESS)
- `this+0x000000D4` `float reciprocalDamageOutput` (write, DERIVED)
- `this+0x0000015C` `pointer damageSourceBlockPtr` (read, DERIVED)
- `this+0x0000019C` `float engineDurability` (read_write, DERIVED)
- `this+0x000001A0` `float engineDurabilityAccumulator` (write, GUESS)
- `this+0x000001AC` `float engineDamageExcitationScale` (read, GUESS)
- `this+0x000001B4` `float engineDurabilityLossScale` (read, GUESS)
- `this+0x000001D4` `pointer enginePowerSubStructPtr` (read, DERIVED)
- `this+0x000001E8` `int driverHeadIndex` (write, DERIVED)
- `this+0x00000348` `uint32_t wheelVelocityLow` (read_write, GUESS)
- `this+0x0000034C` `uint32_t wheelVelocityHigh` (read_write, GUESS)
- `this+0x00000360` `uint32_t wheelSpringConstantLow` (read, GUESS)
- `this+0x00000364` `uint32_t wheelSpringConstantHigh` (read, GUESS)
- `this+0x00000368` `uint32_t wheelVelocitySourceLow` (read, GUESS)
- `this+0x000003D4` `float impactScaleA` (read, GUESS)
- `this+0x000003E4` `float damageOutput` (read_write, DERIVED)
- `this+0x000003E8` `int flWheelIndex` (write, DERIVED)
- `this+0x000003EC` `int flSpindleIndex` (write, DERIVED)
- `this+0x000003F4` `float thermalTolerance` (read, GUESS)
- `this+0x000003FC` `float cosineFrequency` (read, GUESS)
- `this+0x00000404` `uint32_t thermalTemperatureLow` (read_write, GUESS)
- `this+0x0000040C` `float thermalReference` (read, GUESS)
- `this+0x00000414` `float impactScaleB` (read, GUESS)
- `this+0x0000041C` `float thermalConductance` (read, GUESS)
- `this+0x00000424` `float thermalConductanceZ` (read, GUESS)
- `this+0x0000042C` `float damageAccumulator` (read_write, DERIVED)
- `this+0x00000430` `float damageAccumulatorReset` (write, GUESS)
- `this+0x00000434` `float damageMultiplier` (read, GUESS)
- `this+0x0000043C` `float damageDecayScale` (read, GUESS)
- `this+0x00000444` `float damageThreshold` (read, DERIVED)
- `this+0x00000660` `uint32_t wheelSlipLow` (read_write, GUESS)
- `this+0x00000664` `uint32_t wheelSlipHigh` (read_write, GUESS)
- `this+0x00000668` `uint32_t wheelFrictionLimitLow` (read, GUESS)
- `this+0x000007AC` `float wheelVelocitySumA` (read, GUESS)
- `this+0x000007C4` `float springConstantWheel` (read, GUESS)
- `this+0x0000084C` `int frWheelIndex` (write, DERIVED)
- `this+0x00000850` `int frSpindleIndex` (write, DERIVED)
- `this+0x00000BC4` `int tireCompoundIndex` (read, DERIVED)
- `this+0x00000C10` `float wheelVelocitySumB` (read, GUESS)
- `this+0x00000C28` `float wheel2SpringConstant` (read, GUESS)
- `this+0x00000C2C` `uint32_t wheel2SpringConstantHigh` (read, GUESS)
- `this+0x00000C30` `double tireLoadBiasA` (read, GUESS)
- `this+0x00000C38` `double tireLoadScaleA` (read, GUESS)
- `this+0x00000C44` `int tireLoadGain` (read, GUESS)
- `this+0x00000CB0` `int rlWheelIndex` (write, DERIVED)
- `this+0x00000CB4` `int rlSpindleIndex` (write, DERIVED)
- `this+0x00000CB8` `double tireLoadScaleB` (read, GUESS)
- `this+0x00000CC4` `int tireLoadGainB` (read, GUESS)
- `this+0x00001074` `float wheelVelocitySumC` (read, GUESS)
- `this+0x0000108C` `float wheel3SpringConstant` (read, GUESS)
- `this+0x00001114` `int rrWheelIndex` (write, DERIVED)
- `this+0x00001118` `int rrSpindleIndex` (write, DERIVED)
- `this+0x0000141C` `int rearAxleIndex` (write, DERIVED)
- `this+0x000015AC` `int bodyCount` (read, DERIVED)
- `this+0x000015B4` `int wheelBodyContactCount1` (read, DERIVED)
- `this+0x000015B8` `pointer wheelBodyContactList1Ptr` (read, DERIVED)
- `this+0x000015BC` `int wheelBodyContactCount2` (read, DERIVED)
- `this+0x000015C0` `pointer wheelBodyContactList2Ptr` (read, DERIVED)
- `this+0x000015C4` `int bodyPairContactCount` (read, DERIVED)
- `this+0x000015C8` `pointer bodyPairContactListPtr` (read, DERIVED)
- `this+0x000015F0` `int mainBodyIndex` (read_write, DERIVED)
- `this+0x0000162C` `pointer jointDataArrayPtr` (write, DERIVED)
- `this+0x00001630` `int flSteeringIndex` (write, DERIVED)
- `this+0x00001644` `int frSteeringIndex` (write, DERIVED)
- `this+0x00001C59` `uint8 activeFlag` (read, DERIVED)
- `this+0x00001C5C` `float vibrationAccumulator` (read_write, DERIVED)
- `this+0x00001C60` `float vibrationRate` (read_write, DERIVED)
- `this+0x00001C74` `float forceOutputScale` (read, GUESS)
- `this+0x00001C84` `float vibrationThreshold` (read, DERIVED)
- `this+0x00001C88` `float vibrationSourceValue` (read, DERIVED)
- `this+0x00001CF4` `float curveThreshold` (read, GUESS)
- `this+0x00001CFC` `pointer tireCurveTablePtr` (read, DERIVED)
- `this+0x00001D00` `float tireCurveForceA` (write, GUESS)
- `this+0x00001D04` `float tireCurveForceB` (write, GUESS)
- `this+0x00001D08` `int componentTimeArrayCount` (read, GUESS)
- `this+0x00001D0C` `uint8 activeOverrideFlag` (read, DERIVED)
- `this+0x00001D10` `float vibrationOutput` (write, DERIVED)
- `this+0x00001D18` `float vibrationOffsetA` (read, GUESS)
- `this+0x00001D20` `float vibrationNoiseGain` (read, GUESS)
- `this+0x00001D28` `float vibrationOffsetB` (read, GUESS)
- `this+0x00001D4C` `uint32_t coolantTemperatureLow` (read_write, GUESS)
- `this+0x00001D50` `uint32_t coolantTemperatureHigh` (read_write, GUESS)
- `this+0x00001D54` `float coolantTemperatureCap` (read, DERIVED)
- `this+0x00001D5C` `float coolantRateDamageTerm` (read, GUESS)
- `this+0x00001D64` `float coolantRateExcitationTerm` (read, GUESS)
- `this+0x00001D6C` `float coolantRateAmbientTerm` (read, GUESS)
- `this+0x00001D74` `float smoothedCoolantOutput` (read_write, DERIVED)
- `this+0x00001D7C` `float heatSinkBase` (read, GUESS)
- `this+0x00001D84` `float heatSinkBoost` (read, GUESS)
- `this+0x00001D8C` `uint32_t oilTemperatureLow` (read_write, GUESS)
- `this+0x00001D94` `float oilHeatSource` (read, GUESS)
- `this+0x00001D9C` `float oilHeatGain` (read, GUESS)
- `this+0x00001DA4` `float oilOverheatDamping` (read_write, DERIVED)
- `this+0x00001DAC` `uint32_t componentTimeAccumulatorLow` (read_write, GUESS)
- `this+0x00001DB0` `uint32_t componentTimeAccumulatorHigh` (read_write, GUESS)
- `this+0x00001DB4` `uint32_t failureCountdownLow` (read_write, DERIVED)
- `this+0x00001DB8` `uint32_t failureCountdownHigh` (read_write, GUESS)
- `this+0x00001DE4` `float componentHealthA` (read_write, DERIVED)
- `this+0x00001DE8` `uint32_t componentHealthAHigh` (read_write, GUESS)
- `this+0x00001DEC` `float componentHealthB` (read_write, DERIVED)
- `this+0x00001DF0` `uint32_t componentHealthBHigh` (read_write, GUESS)
- `this+0x00001DF4` `float componentHealthC` (read_write, DERIVED)
- `this+0x00001DF8` `uint32_t componentHealthCHigh` (read_write, GUESS)
- `this+0x00001E14` `int brakeMode` (read, DERIVED)
- `this+0x00001E18` `float dampingOffsetA` (read, GUESS)
- `this+0x00001E20` `float dampingOffsetB` (read, GUESS)
- `this+0x00001E28` `float dampingOffsetC` (read, GUESS)
- `this+0x00001E30` `float dampingOffsetD` (read, GUESS)
- `this+0x00001E38` `uint32_t slipVelocityLow` (read_write, DERIVED)
- `this+0x00001E3C` `uint32_t slipVelocityHigh` (read_write, GUESS)
- `this+0x00001E50` `float brakeJacobianCoeff` (read, GUESS)
- `this+0x00001E54` `float brakeJacobianOffset` (read, GUESS)
- `this+0x00001E58` `float brakeScaleCoefficient` (read, DERIVED)
- `this+0x00001E68` `uint32_t slipCoefficientLow` (read, DERIVED)
- `this+0x00001E6C` `uint32_t slipCoefficientHigh` (read, GUESS)
- `this+0x00001E70` `float brakeThreshold` (read, GUESS)
- `this+0x00001EA4` `float torqueFactor` (read, DERIVED)
- `this+0x00001EF0` `int velocityTableIndex` (read, GUESS)
- `this+0x00001F00` `pointer failureStatePtr` (read, DERIVED)

### PhysicsCollisionShape

Physics collision-shape initializer: writes the discriminator word at this+8, the subtype constant at this+1C (2 or 4), and the external data pointer at this+20, stores inverse mass and six constant fields via CollisionInvMassStore/F_6FieldBulkSetter, and for type 2 writes four shape constants into the sub-struct at this+20. Honors an a4 override through ShortComputation_e770.

Methods: `0x0040EA30`, `0x0040EBD0`

- `this+0x00000008` `uint16 typeDiscriminator` (write, DERIVED)
- `this+0x0000001C` `uint32 subtypeConstant` (write, DERIVED)
- `this+0x00000020` `pointer shapeDataPtr` (write, DERIVED)
- `*(this+0x20)+0x00000040` `float shapeConstantA` (write, DERIVED)
- `*(this+0x20)+0x00000044` `float shapeConstantB` (write, DERIVED)
- `*(this+0x20)+0x00000048` `float shapeConstantC` (write, DERIVED)
- `*(this+0x20)+0x0000004C` `float shapeConstantD` (write, DERIVED)

### WheelGroupDispatcher

Wheel input record dispatch and typed physics-state update. Decodes a packed 36-byte wheel record into a 6-bit group selector and 13 scaled floats, validates per-group wheel indices against the count/base pointer pairs (this+24/28, +30/34, +3C/40, +48/4C, +54/58, +60/64), resolves sentinel (-1) slots through the 4656-stride repair-state owner arrays (dword_5ECF0C / dword_5ED3AC / dword_5ED3F0 / dword_5ED434) via ShortComputation_e770 and RepairServiceStateDispatcher, and converts the slot physics state. The typed update (types 3/4/5) reuses the same group-3/4/5 bases and owner arrays.

Methods: `0x00410BC0`, `0x00411330`

- `this+0x00000024` `int group0Count` (read, DERIVED)
- `this+0x00000028` `pointer group0BasePtr` (read, DERIVED)
- `this+0x00000030` `int group1Count` (read, DERIVED)
- `this+0x00000034` `pointer group1BasePtr` (read, DERIVED)
- `this+0x0000003C` `int group2Count` (read, DERIVED)
- `this+0x00000040` `pointer group2BasePtr` (read, DERIVED)
- `this+0x00000048` `int group3Count` (read, DERIVED)
- `this+0x0000004C` `pointer group3BasePtr` (read, DERIVED)
- `this+0x00000054` `int group4Count` (read, DERIVED)
- `this+0x00000058` `pointer group4BasePtr` (read, DERIVED)
- `this+0x00000060` `int group5Count` (read, DERIVED)
- `this+0x00000064` `pointer group5BasePtr` (read, DERIVED)

### VehicleSelectionController

Vehicle selection and camera-target glue over the global vehicle pointer array (dword_7C54F0) and the player/tracked indices (dword_7C54DC / dword_7C54E4). Routes game-state changes through GameStateDispatchChain and refreshes vehicle visual entries.

Methods: `0x0040D2CA`, `0x0040D340`


### AudioPhysicsMixer

Averages a packed array of elements, lerps the average with the object bounding-box center using a mode-selected blend factor, combines a queried three-field offset, writes it back, and applies the offset vector to the object. Used on the frame path by audio and vehicle subsystems.

Methods: `0x0040E2B0`


### ChassisBodyObject

Layout-only GUESS type for the physics body objects reached through this+0x15F0 and this+0x141C: three read axes, three torque-moment reads (body A), and a three-component force accumulator written by the suspension solver. No member function in this packet; identity unproven.

Methods: 

- `*(this+0x15F0)+0x0000002C` `double bodyAaxisX` (read, GUESS)
- `*(this+0x15F0)+0x00000044` `double bodyAaxisY` (read, GUESS)
- `*(this+0x15F0)+0x0000005C` `double bodyAaxisZ` (read, GUESS)
- `*(this+0x15F0)+0x0000014C` `double bodyAforceAccumX` (write, GUESS)
- `*(this+0x15F0)+0x00000154` `double bodyAforceAccumY` (write, GUESS)
- `*(this+0x15F0)+0x0000015C` `double bodyAforceAccumZ` (write, GUESS)
- `*(this+0x141C)+0x0000002C` `double bodyBaxisX` (read, GUESS)
- `*(this+0x141C)+0x00000044` `double bodyBaxisY` (read, GUESS)
- `*(this+0x141C)+0x0000005C` `double bodyBaxisZ` (read, GUESS)
- `*(this+0x141C)+0x0000014C` `double bodyBforceAccumX` (write, GUESS)
- `*(this+0x141C)+0x00000154` `double bodyBforceAccumY` (write, GUESS)
- `*(this+0x141C)+0x0000015C` `double bodyBforceAccumZ` (write, GUESS)
- `*(this+0x15F0)+0x00000064` `double bodyAmomentX` (read, GUESS)
- `*(this+0x15F0)+0x0000006C` `double bodyAmomentY` (read, GUESS)
- `*(this+0x15F0)+0x00000074` `double bodyAmomentZ` (read, GUESS)

### WheelBodyObject

Layout-only GUESS type for the four chassis-body pointer objects at this+0x3E8, this+0x84C, this+0xCB0 and this+0x1114, each exposing three body rows at +0x1C/+0x34/+0x4C read by the suspension solver. No member function in this packet; identity unproven.

Methods: 

- `*(this+0x3E8)+0x0000001C` `double wheelrowA` (read, GUESS)
- `*(this+0x3E8)+0x00000034` `double wheelrowB` (read, GUESS)
- `*(this+0x3E8)+0x0000004C` `double wheelrowC` (read, GUESS)
- `*(this+0x84C)+0x0000001C` `double wheelrowA` (read, GUESS)
- `*(this+0x84C)+0x00000034` `double wheelrowB` (read, GUESS)
- `*(this+0x84C)+0x0000004C` `double wheelrowC` (read, GUESS)
- `*(this+0xCB0)+0x0000001C` `double wheelrowA` (read, GUESS)
- `*(this+0xCB0)+0x00000034` `double wheelrowB` (read, GUESS)
- `*(this+0xCB0)+0x0000004C` `double wheelrowC` (read, GUESS)
- `*(this+0x1114)+0x0000001C` `double wheelrowA` (read, GUESS)
- `*(this+0x1114)+0x00000034` `double wheelrowB` (read, GUESS)
- `*(this+0x1114)+0x0000004C` `double wheelrowC` (read, GUESS)

### PhysicsSubComponentOwner

Container of up to five physics sub-component pointers: a four-slot loop over dwords at this+4C and a tail pointer at this+5C, each recursively destroyed, freed via FreeWrapper_7bcf and cleared. Owner class of the recursive destroyer at 0x00448570; identity unproven.

Methods: `0x00448570`

- `this+0x0000004C` `pointer subComponentA` (read_write, GUESS)
- `this+0x00000054` `pointer subComponentB` (read_write, GUESS)
- `this+0x00000058` `pointer subComponentC` (read_write, GUESS)
- `this+0x0000005C` `pointer tailSubComponent` (read_write, GUESS)

### EnginePowerSubStruct

Layout-only GUESS type for the engine-power sub-struct reached through this+0x1D4: a power scale factor and its reciprocal written on the surviving durability path. No member function in this packet.

Methods: 

- `*(this+0x1D4)+0x000000AC` `float powerScaleFactor` (write, GUESS)
- `*(this+0x1D4)+0x000000B4` `float powerReciprocal` (write, GUESS)

### SecondaryStateObject

Layout-only GUESS type for the secondary/failure state object reached through this+0x1F00: a secondary-state byte at +0x344C consumed by the vehicle-active gate and the failure-state slot at +0x4068 written by engine durability (code 9) and component-failure (code 1) paths.

Methods: 

- `*(this+0x1F00)+0x0000344C` `uint8 secondaryStateByte` (read, DERIVED)
- `*(this+0x1F00)+0x00004068` `uint32 failureStateSlot` (read_write, DERIVED)

## Compatibility contracts

- **VehicleActiveGateContract** — A replacement executable must reproduce the vehicle-active gate: the vehicle is inactive when the doubles at this+1DB4 or this+19C are <= 0.0 or the byte at this+1C59 is zero; it is active when the byte at this+1D0C is non-zero; otherwise the result combines the secondary-state byte at *(this+1F00)+344C with the preceding comparison flags.
- **DnfMarkingContract** — When the collision damage accumulator overflows, the first grid vehicle (dword_7C54F0 over dword_5C329C entries) whose DNF flag is unset must be marked DNF (state 5) and the damage state reset.
- **EngineFailureStateContract** — Exhausting engine durability writes failure code 9 and a component failure writes code 1 into the failure-state slot at *(this+1F00)+4068 when that slot is clear.
- **RepairSlotOwnershipContract** — Wheel slots holding the sentinel -1 must be resolved through the 4656-stride repair-state owner arrays (dword_5ECF0C / dword_5ED3AC / dword_5ED3F0 / dword_5ED434) and initialized via ShortComputation_e770 and RepairServiceStateDispatcher before physics-state conversion.
- **WheelContactFlagContract** — Per-wheel contact flags (this[281*a2+276] and this[281*a2+291]) and the flag-bit-1 ORs into body-pair and wheel-body contact entries must be reproduced for collision-driven behavior.

## Unresolved

- Contradiction: this+3E8 is written as the front-left wheel index by VehiclePhysicsBodyNameMapping, is zeroed in the collision-damage DNF reset, and is dereferenced as a chassis-body pointer by SolveSuspensionWheelDynamics; the packet does not reconcile these three uses.
- Contradiction: this+15B4 is read as a wheel-body contact-list count by WheelCollisionContactFlagSetter, but the analysis fill labels it the wheel contact state; the raw source reads the contact state from the per-wheel offset this[281*a2+251].
- Contradiction: this+8 is read as an RPM-like excitation term by EngineStressSimulation and as the timestep by SolveSuspensionWheelDynamics; same offset, two semantic roles within the same proposed owner object.
- Offset reuse across proposed owner types with no proven common ownership: this+4C and this+58 are wheel-group slot bases in WheelGroupDispatcher and also sub-component pointers in PhysicsSubComponentOwner; this+1CFC is both the tire-curve table pointer and the component-time array pointer; this+C30 is both a tire load bias and an LCP coefficient.
- The object identities behind this+15F0, this+141C, this+1D4, this+1F00 and the four wheel bodies (this+3E8/84C/CB0/1114) are unknown; ChassisBodyObject, WheelBodyObject, EnginePowerSubStruct and SecondaryStateObject are layout-only GUESS types with no member functions in this packet.
- The per-wheel 281-DWORD stride and the contact-record entry offsets (+4 body A id, +12 body B id, +44 wheel-contact flag, +68 body-pair contact flag) are decompiler-derived and have no field evidence refs.
- The read-only global float pool (0x0059E420..0x0059ED20 plus 0x005EB978) is rendered as immediates in the raw source; the mapping between globals and constants is not independently established.
- The a4 continuation argument of the shape initializers, the a2 blend-mode of AudioPhysicsMixWithLerp, and the tracked-vehicle index dword_7C54E4 are caller-defined and not grounded in this packet.
- The repair-state owner arrays (dword_5ECF0C / dword_5ED3AC / dword_5ED3F0 / dword_5ED434) use a 4656-byte stride with 74*v30 / 17*v35 sub-indexing; the meaning of the sub-indexing is not decoded.
- sub_5677B0 (6x6 LCP solve), ConstraintProjectGramSchmidt, sub_5881F0 and sub_41AC50 are opaque callees whose bodies fall outside this packet's evidence.
