# Recovered Pit Subsystem

Generated orientation report. Names and graph edges are static-analysis
leads unless a row explicitly carries a reviewed object owner.

- Tagged functions: 92
- Reviewed owner methods: 17

## Reviewed object methods

- `0x0041A200` `AIPitStrategyState` — `F1CVehicle*` (CONFIRMED)
- `0x0042A110` `ForcePitExit` — `F1CVehicle*` (CONFIRMED)
- `0x0042A3D0` `PitStopDecisionTireCompound` — `F1CVehicle*` (CONFIRMED)
- `0x0042A6F0` `PostPitCleanup` — `F1CVehicle*` (CONFIRMED)
- `0x0042AEE0` `PitStopBlockingCondition` — `F1CVehicle*` (CONFIRMED)
- `0x004A5C40` `TeammatePartValueLookup` — `F1CPitMachine*` (CONFIRMED)
- `0x004A5C80` `StateChangeNotify` — `F1CPitMachine*` (CONFIRMED)
- `0x004A5D10` `AIStateMachineWithModeDispatch` — `F1CPitMachine*` (CONFIRMED)
- `0x004A5E10` `SessionTransitionDispatch` — `F1CPitMachine*` (CONFIRMED)
- `0x004A5E40` `StateConditionalAction` — `F1CPitMachine*` (CONFIRMED)
- `0x004A5EA0` `sub_4A5EA0` — `F1CPitMachine*` (CONFIRMED)
- `0x004A5F20` `sub_4A5F20` — `F1CPitMachine*` (CONFIRMED)
- `0x004A5FA0` `VehicleProximityCollisionDetection` — `F1CPitMachine*` (CONFIRMED)
- `0x004A6200` `PitStopReadyCheck` — `F1CPitMachine*` (CONFIRMED)
- `0x004A6340` `PitStopOperationTimer` — `F1CPitMachine*` (CONFIRMED)
- `0x004A68B0` `PitStopProgress` — `F1CPitMachine*` (CONFIRMED)
- `0x004A6E50` `PitStateUpdateMachine` — `F1CPitMachine*` (CONFIRMED)

## Highest-connectivity functions

- `0x004A2A90` `PitCrewAnimationLoader` — 1 callers, 27 callees; owner `unreviewed`
- `0x004D2E50` `PitTimer` — 1 callers, 21 callees; owner `unreviewed`
- `0x004D7150` `TireBrandFileParser` — 1 callers, 19 callees; owner `unreviewed`
- `0x004D7660` `TireBrandLoader` — 1 callers, 15 callees; owner `unreviewed`
- `0x004681B0` `VehicleSceneLoadAndPositionTires` — 0 callers, 14 callees; owner `unreviewed`
- `0x004A6340` `PitStopOperationTimer` — 1 callers, 13 callees; owner `F1CPitMachine`
- `0x0043E050` `TireModelInit` — 1 callers, 12 callees; owner `unreviewed`
- `0x004A2010` `PitCrewMeshLoader` — 2 callers, 11 callees; owner `unreviewed`
- `0x004A5C80` `StateChangeNotify` — 11 callers, 2 callees; owner `F1CPitMachine`
- `0x004D5F70` `TireSlipCurveBuilder` — 1 callers, 12 callees; owner `unreviewed`
- `0x0041B3C0` `PitSelectionStateMachine` — 2 callers, 10 callees; owner `unreviewed`
- `0x0042A3D0` `PitStopDecisionTireCompound` — 2 callers, 10 callees; owner `F1CVehicle`
- `0x004A3910` `PitCrewAnimationMASSetup` — 1 callers, 11 callees; owner `unreviewed`
- `0x004D7880` `TireBrandLookup` — 9 callers, 3 callees; owner `unreviewed`
- `0x004DDAD0` `PitCrewInstanceSetup` — 2 callers, 10 callees; owner `unreviewed`
- `0x004F34E0` `TireModelDataInit` — 6 callers, 6 callees; owner `unreviewed`
- `0x0043DA10` `TireCompoundPerWheelPhysicsApplication` — 2 callers, 9 callees; owner `unreviewed`
- `0x0049CA00` `CockpitDashboardLEDGaugeSetup` — 2 callers, 9 callees; owner `unreviewed`
- `0x004A68B0` `PitStopProgress` — 1 callers, 10 callees; owner `F1CPitMachine`
- `0x004A6E50` `PitStateUpdateMachine` — 1 callers, 10 callees; owner `F1CPitMachine`
- `0x004A5330` `PitPartStateCopy` — 1 callers, 9 callees; owner `unreviewed`
- `0x004A5D10` `AIStateMachineWithModeDispatch` — 2 callers, 8 callees; owner `F1CPitMachine`
- `0x004B7A90` `PitTimingUpdate` — 1 callers, 9 callees; owner `unreviewed`
- `0x004E8010` `TireBrushModelForceSolver` — 9 callers, 1 callees; owner `unreviewed`
- `0x004A3220` `PITANIMSMASAnimationFileLoader` — 1 callers, 8 callees; owner `unreviewed`
- `0x004D12C0` `PitStopOrderLoader` — 1 callers, 8 callees; owner `unreviewed`
- `0x004A5F20` `sub_4A5F20` — 3 callers, 5 callees; owner `F1CPitMachine`
- `0x004A6200` `PitStopReadyCheck` — 1 callers, 7 callees; owner `F1CPitMachine`
- `0x004C0B10` `PitStopMemoryCleanup` — 6 callers, 2 callees; owner `unreviewed`
- `0x004A4ED0` `TireWheelGraphicsMeshLoader` — 1 callers, 6 callees; owner `unreviewed`
- `0x004E4500` `PhysicsTireSystemConstructor` — 1 callers, 6 callees; owner `unreviewed`
- `0x00554D70` `UICleanupIterator` — 6 callers, 1 callees; owner `unreviewed`
- `0x004199E0` `AIRetirementVehicleFailureEvent` — 1 callers, 5 callees; owner `unreviewed`
- `0x0041BE60` `PitRaceStatusMessageDispatcher` — 1 callers, 5 callees; owner `unreviewed`
- `0x0042A110` `ForcePitExit` — 3 callers, 3 callees; owner `F1CVehicle`
- `0x004472B0` `TireSlipForceCalculation` — 1 callers, 5 callees; owner `unreviewed`
- `0x004A4830` `TireCompoundNameIDMapping` — 5 callers, 1 callees; owner `unreviewed`
- `0x004A5FA0` `VehicleProximityCollisionDetection` — 1 callers, 5 callees; owner `F1CPitMachine`
- `0x004B6940` `PitstopActionSet` — 2 callers, 4 callees; owner `unreviewed`
- `0x00500210` `AudioSamplePlaybackWithPitchModulationAndStereoP` — 3 callers, 3 callees; owner `unreviewed`

## Review policy

Use `tools/query_recovery_index.py <name> --depth 2` to inspect a
candidate. Promote object ownership only after caller/constructor or
direct-layout evidence; never apply DERIVED same-`this` proposals automatically.
