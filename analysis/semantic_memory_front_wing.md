# Semantic-memory pilot: front-wing detachment

This report joins static and runtime evidence. It does not claim that a detachment writer has been found.

## Anchors

- `veh+0xCD4` `FrontWingRecordPtr` [CONFIRMED]; runtime kind `child_ptr`
  - OBSERVED child shape: `physics_float_buf`, 7 float-like / 4 pointer-like words
- `veh+0xD14` `FrontWingIntactFlag` [CONFIRMED]; runtime kind `static`

## Static configuration bridge

- `FrontWingDetach` → parser object 0x1C in `VehicleDamageModel` `0x004F24F0` (inline)
- `FrontWingRandom` → parser object 0x20 in `VehicleDamageModel` `0x004F24F0` (inline)
- `FrontWingPos` → parser object 0x24, 0x28, 0x2C in `VehicleDamageModel` `0x004F24F0` (inline)
- `FrontWingMassInertia` → parser object 0x30, 0x34, 0x38, 0x3C in `VehicleDamageModel` `0x004F24F0` (inline)
- `FrontWingCollParams` → parser object 0x40, 0x44, 0x48 in `VehicleDamageModel` `0x004F24F0` (inline)

## Static accessors

Readers: 10; writers: 0.

- `0x00429470` `AIAbility` base `obj` `R` identity `DERIVED`
- `0x0042A3D0` `PitStopDecisionTireCompound` base `obj` `R` identity `CONFIRMED`
- `0x0042A3D0` `PitStopDecisionTireCompound` base `obj` `R` identity `CONFIRMED`
- `0x004423B0` `sub_4423B0` base `*(this+0x1F00)` `R` identity `UNKNOWN`
- `0x004423B0` `sub_4423B0` base `*(this+0x1F00)` `R` identity `UNKNOWN`
- `0x004432F0` `DamperSpringForceComputationWithAntiRoll` base `*(this+0x1F00)` `R` identity `UNKNOWN`
- `0x004432F0` `DamperSpringForceComputationWithAntiRoll` base `*(this+0x1F00)` `R` identity `UNKNOWN`
- `0x004A6340` `PitStopOperationTimer` base `obj` `R` identity `CONFIRMED`
- `0x004E5F60` `SuspensionAndWheelPhysics` base `this` `R` identity `UNKNOWN`
- `0x004E5F60` `SuspensionAndWheelPhysics` base `this` `R` identity `UNKNOWN`

No direct static writer was extracted. This strongly suggests an indirect call, nested record write, or resource-operation boundary is the next target; it does not prove that no writer exists.

## Runtime event links

- `t2_slot6` moved `+0x0D14` [OBSERVED]

## Next discriminating experiment

Capture the same car immediately before and after a natural front-wing loss, with an ordinary driving control over the same duration. Correlate the two captures, then hook only the highest-ranked static accessors. The goal is to observe the game-owned call that changes the wing record—not to forge the flag.
