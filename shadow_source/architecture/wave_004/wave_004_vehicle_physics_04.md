# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

Vehicle physics subsystem proposal over 17 functions. A VehiclePhysics core (five methods sharing a this layout of orientation/position/mode-selector/wheel data) covers brake+suspension integration, per-vehicle and per-frame collision contact, telemetry accumulation and mode-dispatched grid-collision. VehicleDashboardHUD drives per-frame dashboard/cue presentation. Supporting types: VehicleRenderObject element iterators, VehicleViewObject + VehicleReflectionMapView (view construction and parameter forwarding), VehicleCollisionSampleState (contact/audio records), PhysicsInterfaceDispatcher thunks, and WheelForceTransformer (chassis-frame force transform). Free helpers: TireTemperatureLookup (category->value mapping) and DualMatrixTransformMultiply (transform composition). Two fixed contracts (tire temperature mapping, reflection-map entry requirements) are directly evidenced; physics-mode and collision-slot dispatch contracts are DERIVED from control flow. 26 global float constants remain semantically unresolved.

## Function roles

- `0x004E19D0` **VehicleDashboardHUD** — Per-frame vehicle dashboard/HUD update: transform propagation, wheel pose/colour, component cue dispatch, low-grip/gear/byte-flag change detection, gauge scaling.
- `0x004E3940` **VehicleRenderObject** — Iterates the object's 748-byte element records, dispatching a reference-position offset vector to each via 0x004DEF70; returns the element count.
- `0x004E3A10` **VehicleRenderObject** — Per-vehicle wheel render iteration over stride-0xBB0 sub-objects, calling ConditionalRenderCall on each; re-reads the count from this[746] each pass.
- `0x004E5AE0` **VehiclePhysics** — Per-frame wheel/brake/suspension dynamics: timestep-scaled torque rotation into chassis frame, gyroscopic terms, per-wheel sub-update, brake-pressure state machine.
- `0x004EA040` **VehiclePhysics** — Per-vehicle collision contact: local transform of contact point, AABB overlap test, packed geometry closest-vertex search, contact normal/depth, response buffer write and proximity/projection refinement.
- `0x004EA970` **VehiclePhysics** — Per-frame collision detection/response over 13 contact slots: packet read, world transform, opponent grid lookup, impulse/severity response, collision result-list report.
- `0x004EC080` **VehiclePhysics** — Accumulates velocity-scaled deltas into position, transforms them by the 3x3 rotation matrix, then dispatches by update-mode selector (0 rigid-body / 2 stride-resolved target).
- `0x004EE2D0` **VehiclePhysics** — Per-frame physics dispatch on this+0x32BC: mode 0 tire slip-force, mode 1 per-wheel suspension contact + throttle/brake override, modes 2/3 spatial-grid collision with particle/spark effects; common tail commits aggregate contact.
- `0x004FE2B0` **UnknownObject** — Maps a tire temperature category name to a numeric value via cascading string compares (first category 32.5, Warm 26.25, Medium 20.0, Cool 13.75, Cold via 0x0058850F, default 7.5).
- `0x00500010` **VehicleCollisionSampleState** — Stores collision surface contact value/type with a [current-5.0,current] tolerance band; descriptor flag bits (0xFC0000) select Euler-to-orientation (0x004B2DD0/0x004B32A0) vs arithmetic-comparison (0x004B3A90) update.
- `0x00500560` **VehicleCollisionSampleState** — Threshold-guarded collision audio sample handler: clamps delta to [0.001,0.5], interpolates audio parameters and cross-fades the collision sample, then copies arithmetic state to the output buffer.
- `0x00503659` **PhysicsInterfaceDispatcher** — Trivial indirect-dispatch thunk: calls the function pointer at off_5D76C0 with no arguments and returns its result.
- `0x005038EF` **PhysicsInterfaceDispatcher** — Trivial indirect-forwarding thunk: calls the function pointer at off_5D76C4 with no arguments and returns its result.
- `0x00541A70` **WheelForceTransformer** — Transforms per-wheel suspension forces into the chassis frame via a device-wrapper vtable at 0x008B8F24, iterating 6 wheel entries and accumulating the chassis position offset.
- `0x00542560` **VehicleViewObject** — Stores a caller-supplied parameter at +0x19C and forwards four view fields (+0x54/+0x58/+0x64/+0x68) plus flag 1 to 0x00542200; returns 0 when the parameter is zero.
- `0x00548AD0` **VehicleReflectionMapView** — Reflection-map view initializer: entry scan (stride 148, +96 bit 0x800000, +64 bit 2), error logging, child VehicleViewObject construction and parameter/sound/colour setup.
- `0x0054B530` **UnknownObject** — Two-stage transform composition over six dword operands via 0x0054B4A0 then 0x0054B420; sits on the scene-render transform chain (callers include SceneRenderTransform 0x00548C20).

## Proposed classes

### VehiclePhysics

Per-frame vehicle dynamics and collision core: wheel torque/suspension/brake integration (0x004E5AE0), per-vehicle collision contact (0x004EA040), per-frame collision detection over 13 contact slots (0x004EA970), telemetry position accumulation (0x004EC080), and the physics-mode dispatch that selects slip-force, suspension-contact or grid-collision handlers (0x004EE2D0). Only 0x004EE2D0 carries a packet DERIVED owner; the shared this layout (orientation at +0x34B0, position at +0x34D4, mode selector at +0x32BC, wheel data at +0x3590) is the grouping basis and remains a proposal.

Methods: `0x004E5AE0`, `0x004EA040`, `0x004EA970`, `0x004EC080`, `0x004EE2D0`

- `this+0x00000000` `dword vehicleId` (read, GUESS)
- `this+0x00000004` `dword objectId` (read, GUESS)
- `this+0x0000004C` `float fallbackNormalX` (read, GUESS)
- `this+0x00000050` `float fallbackNormalY` (read, GUESS)
- `this+0x00000054` `float fallbackNormalZ` (read, GUESS)
- `this+0x000000A4` `float impactRatio` (read_write, GUESS)
- `this+0x000000A8` `float impactSeverity` (read_write, GUESS)
- `this+0x000000AC` `float impactOffsetX` (read_write, GUESS)
- `this+0x000000B0` `float impactOffsetY` (read_write, GUESS)
- `this+0x000000B4` `float impactOffsetZ` (read_write, GUESS)
- `this+0x0000072C` `float aabbMinX` (read, GUESS)
- `this+0x00000730` `float aabbMinY` (read, GUESS)
- `this+0x00000734` `float aabbMinZ` (read, GUESS)
- `this+0x00000738` `float framePosX` (read, GUESS)
- `this+0x0000073C` `float framePosY` (read, GUESS)
- `this+0x00000740` `float framePosZ` (read, GUESS)
- `this+0x00000744` `float aabbMaxX` (read, GUESS)
- `this+0x00000748` `float aabbMaxY` (read, GUESS)
- `this+0x0000074C` `float aabbMaxZ` (read, GUESS)
- `this+0x00000750` `float aabbHalfX` (read, GUESS)
- `this+0x00000754` `float aabbHalfY` (read, GUESS)
- `this+0x00000758` `float aabbHalfZ` (read, GUESS)
- `this+0x0000077C` `dword contactBlock` (read, GUESS)
- `this+0x00000790` `dword contactStateA` (read_write, GUESS)
- `this+0x000007A4` `dword contactStateB` (read_write, GUESS)
- `this+0x000007D4` `float wheelContactX0` (write, GUESS)
- `this+0x000007D8` `float wheelContactY0` (write, GUESS)
- `this+0x000007DC` `float wheelContactRatio` (write, GUESS)
- `this+0x000007E0` `float wheelContactX1` (write, GUESS)
- `this+0x000007E4` `float wheelContactY1` (write, GUESS)
- `this+0x000007E8` `float wheelContactHeat` (write, GUESS)
- `this+0x000007EC` `dword wheelContactLifespan` (write, GUESS)
- `this+0x000008CC` `float colorHeatA` (write, GUESS)
- `this+0x000009F4` `float colorHeatB` (write, GUESS)
- `this+0x00000B1C` `float colorHeatC` (write, GUESS)
- `this+0x00000C44` `float colorHeatD` (write, GUESS)
- `this+0x00000C74` `float collisionEffectAccX` (write, GUESS)
- `this+0x00000C78` `float collisionEffectAccY` (write, GUESS)
- `this+0x00000C7C` `float collisionEffectAccZ` (write, GUESS)
- `this+0x00000C80` `float collisionEffectAccW` (write, GUESS)
- `this+0x00000C84` `float collisionEffectAcc5` (write, GUESS)
- `this+0x00000C88` `float gripMagnitude` (write, GUESS)
- `this+0x00000D0C` `dword slotEnableA` (read, GUESS)
- `this+0x00000D4C` `dword slotEnableB` (read, GUESS)
- `this+0x0000101C` `dword packedContact0` (read, GUESS)
- `this+0x00001020` `dword packedContact1` (read, GUESS)
- `this+0x00001024` `dword packedContact2` (read, GUESS)
- `this+0x00001028` `dword packedContact3` (read, GUESS)
- `this+0x0000102C` `word packedContactWord` (read, GUESS)
- `this+0x00001070` `dword effectFlag` (read, GUESS)
- `this+0x00001078` `dword particleEffect0` (read, GUESS)
- `this+0x0000107C` `dword particleEffect1` (read, GUESS)
- `this+0x00001080` `dword particleEffect2` (read, GUESS)
- `this+0x000032BC` `dword physicsModeSelector` (read, GUESS)
- `this+0x000034A8` `float timestep` (read, GUESS)
- `this+0x000034AC` `float contactField` (read, GUESS)
- `this+0x000034B0` `float orientationR0C0` (read, GUESS)
- `this+0x000034B4` `float orientationR0C1` (read, GUESS)
- `this+0x000034B8` `float orientationR0C2` (read, GUESS)
- `this+0x000034BC` `float orientationR1C0` (read, GUESS)
- `this+0x000034C0` `float orientationR1C1` (read, GUESS)
- `this+0x000034C4` `float orientationR1C2` (read, GUESS)
- `this+0x000034C8` `float orientationR2C0` (read, GUESS)
- `this+0x000034CC` `float orientationR2C1` (read, GUESS)
- `this+0x000034D0` `float orientationR2C2` (read, GUESS)
- `this+0x000034D4` `float positionX` (read_write, GUESS)
- `this+0x000034D8` `float positionY` (read_write, GUESS)
- `this+0x000034DC` `float positionZ` (read_write, GUESS)
- `this+0x000034EC` `float torqueAccX` (read, GUESS)
- `this+0x000034F0` `float torqueAccY` (read, GUESS)
- `this+0x000034F4` `float torqueAccZ` (read, GUESS)
- `this+0x000034F8` `float worldTorqueX` (write, GUESS)
- `this+0x000034FC` `float worldTorqueY` (write, GUESS)
- `this+0x00003500` `float worldTorqueZ` (write, GUESS)
- `this+0x00003504` `float dtTorqueX` (write, GUESS)
- `this+0x00003508` `float dtTorqueY` (write, GUESS)
- `this+0x0000350C` `float dtTorqueZ` (write, GUESS)
- `this+0x00003534` `float rotatedVecX` (write, GUESS)
- `this+0x00003538` `float rotatedVecY` (write, GUESS)
- `this+0x0000353C` `float rotatedVecZ` (write, GUESS)
- `this+0x00003540` `float transformVecX` (write, GUESS)
- `this+0x00003544` `float transformVecY` (write, GUESS)
- `this+0x00003548` `float transformVecZ` (write, GUESS)
- `this+0x00003528` `float gyroTermA` (read, GUESS)
- `this+0x0000352C` `float gyroTermB` (read, GUESS)
- `this+0x00003530` `float gyroTermC` (read, GUESS)
- `this+0x00003558` `float gyroTermD` (read, GUESS)
- `this+0x0000355C` `float gyroTermE` (read, GUESS)
- `this+0x00003560` `float gyroTermF` (read, GUESS)
- `this+0x00003564` `float gyroTermG` (read, GUESS)
- `this+0x00003568` `float gyroTermH` (read, GUESS)
- `this+0x0000356C` `float gyroTermI` (read, GUESS)
- `this+0x0000354C` `float torqueDirX` (read, GUESS)
- `this+0x00003550` `float torqueDirY` (read, GUESS)
- `this+0x00003554` `float torqueDirZ` (read, GUESS)
- `this+0x00003518` `float torqueMagnitude` (read, GUESS)
- `this+0x00003570` `float brakeSlope` (read, GUESS)
- `this+0x00003590` `dword wheelBasePtr` (read, GUESS)
- `this+0x00003594` `dword wheelBasePtr2` (read, GUESS)
- `this+0x000035B0` `float wheelSuspA` (read, GUESS)
- `this+0x000035CC` `float wheelTravel` (read, GUESS)
- `this+0x000035D0` `float wheelDamping` (read, GUESS)
- `this+0x00003610` `dword unknown3610` (unknown, GUESS)
- `this+0x00003668` `dword wheelContactRef` (read, GUESS)
- `this+0x000036A8` `float wheelSuspB` (read, GUESS)
- `this+0x000036C4` `dword contactCounter` (read, GUESS)
- `this+0x00003760` `dword contactCounter2` (read, GUESS)
- `this+0x000037A0` `float wheelSuspC` (read, GUESS)
- `this+0x00003898` `float wheelSuspD` (read, GUESS)
- `this+0x00003964` `float brakeTorqueTarget` (read_write, GUESS)
- `this+0x00003978` `dword brakeInputState` (read, GUESS)
- `this+0x0000398C` `float brakePressureParam` (read, GUESS)
- `this+0x00003990` `float brakePressureBlend` (read_write, GUESS)
- `this+0x00003994` `float brakePressure` (read_write, GUESS)
- `this+0x00003998` `float brakePressureMin` (read, GUESS)
- `this+0x0000399C` `float brakePressureMax` (read, GUESS)
- `this+0x000039A0` `float brakeBias` (read, GUESS)
- `this+0x000039B4` `dword brakeModelSelector` (read, GUESS)
- `this+0x000039C8` `float brakeInput` (read, GUESS)
- `this+0x000039EC` `byte brakeFlagByte` (read, GUESS)
- `this+0x000039F0` `dword brakeMode` (read, GUESS)
- `this+0x00003ABC` `float slotOffsetX` (read, GUESS)
- `this+0x00003AC0` `float slotOffsetY` (read, GUESS)
- `this+0x00003B70` `float penetrationDepth` (read, GUESS)
- `this+0x00003B74` `dword slotEnable` (read, GUESS)
- `this+0x00003BE8` `float velocityX` (read, GUESS)
- `this+0x00003BEC` `float velocityY` (read, GUESS)
- `this+0x00003BF0` `float velocityZ` (read, GUESS)
- `this+0x00003D54` `float altVelocityX` (read, GUESS)
- `this+0x00003D58` `float altVelocityY` (read, GUESS)
- `this+0x00003D5C` `float altVelocityZ` (read, GUESS)
- `obj+0x00004894` `dword vehicleIdentity` (read, GUESS)

### VehicleDashboardHUD

Per-frame vehicle dashboard/HUD: propagates the vehicle transform and wheel poses, drives per-component cue slots, detects low-grip/gear/byte-flag state changes and dispatches sound/visual cues via 0x005506A0, and scales the speedometer/gauge readout (2.0943952 rad rotation, flt_7CF740 gauge scaling).

Methods: `0x004E19D0`

- `this+0x00000000` `dword externalObjectPtr` (read, GUESS)
- `this+0x00000008` `float transformPosX` (read, GUESS)
- `this+0x0000000C` `float transformPosY` (read, GUESS)
- `this+0x00000010` `float transformPosZ` (read, GUESS)
- `this+0x00000014` `float transformRotX` (read, GUESS)
- `this+0x00000018` `float transformRotY` (read, GUESS)
- `this+0x0000001C` `float transformRotZ` (read, GUESS)
- `this+0x000001C8` `dword wheelSubObjectsPtr` (read, GUESS)
- `this+0x000001E0` `dword wheelColorValue0` (read, GUESS)
- `this+0x000001E4` `dword wheelColorValue1` (read, GUESS)
- `this+0x000001E8` `dword wheelAlphaValue0` (read, GUESS)
- `this+0x00002BD0` `dword componentCount` (read, GUESS)
- `this+0x00002BD4` `dword componentArrayPtr` (read, GUESS)
- `this+0x00000B6C` `dword cueHandle` (read, GUESS)
- `this+0x00000898` `dword cueSlotDispatch` (read, GUESS)
- `this+0x000008A0` `dword speedometerSlotActive` (read, GUESS)
- `this+0x000008A4` `dword lowGripCueSlot` (read, GUESS)
- `this+0x000008A8` `dword gearChangeCueSlot` (read, GUESS)
- `this+0x000008AC` `dword byteFlagCueSlot` (read, GUESS)
- `this+0x000008B0` `dword gaugeCueSlot` (read, GUESS)
- `this+0x000008B4` `dword gaugePairCount` (read, GUESS)
- `this+0x000008B8` `dword gaugePairArrayA` (read, GUESS)
- `this+0x000008C4` `dword gaugePairArrayB` (read, GUESS)
- `this+0x0000094C` `float gripThreshold` (read, GUESS)
- `this+0x00000950` `float speedometerScale` (read, GUESS)
- `this+0x00000958` `float rotationScaleA` (read, GUESS)
- `this+0x0000095C` `float rotationScaleB` (read, GUESS)
- `this+0x00000960` `float rotationScaleC` (read, GUESS)
- `this+0x00000964` `dword modeCounter` (read, GUESS)
- `this+0x0000096D` `dword flagByte` (read, GUESS)
- `this+0x00000974` `byte lowGripStateStored` (read_write, GUESS)
- `this+0x00000975` `byte gearCurrent` (read, GUESS)
- `this+0x00000976` `byte gearStored` (read_write, GUESS)
- `this+0x00000977` `byte flagCurrent` (read, GUESS)
- `this+0x00000978` `byte flagStored` (read_write, GUESS)
- `this+0x00000979` `byte lowGripFlag` (read, GUESS)
- `this+0x00000980` `float gaugeValueStored` (read_write, GUESS)
- `this+0x00000984` `float gaugeValueCurrent` (read, GUESS)
- `this+0x00000988` `float gaugeWindowMax` (read, GUESS)

### VehicleRenderObject

Per-vehicle render/visual element container: iterates an array of stride-0xBB0 wheel sub-objects (0x004E3A10, called from 0x004B3400) and an array of 748-byte element records, dispatching a reference-position offset transform to each via 0x004DEF70 (0x004E3940). Element count held at this+0xBA8.

Methods: `0x004E3940`, `0x004E3A10`

- `this+0x00000048` `float refPositionX` (read, GUESS)
- `this+0x0000004C` `float refPositionY` (read, GUESS)
- `this+0x00000050` `float refPositionZ` (read, GUESS)
- `this+0x00000BA8` `dword elementCount` (read, GUESS)

### VehicleViewObject

Suspension/view parameter object: stores a caller-supplied parameter at +0x19C and forwards four float/double fields (+0x54/+0x58/+0x64/+0x68) plus a literal flag into 0x00542200 (0x00542560). Set up by VehicleReflectionMapInit on a freshly constructed 444-byte child object.

Methods: `0x00542560`

- `this+0x00000054` `float viewParamA` (read, GUESS)
- `this+0x00000058` `double viewParamB` (read, GUESS)
- `this+0x00000064` `float viewParamC` (read, GUESS)
- `this+0x00000068` `float viewParamD` (read, GUESS)
- `this+0x0000019C` `dword storedParameter` (read_write, GUESS)

### VehicleReflectionMapView

Reflection-map view initializer: scans the render-entry array for an entry with +96 bit 0x800000 and +64 bit 2 set, logs 'No Reflection Map'/'Reflection Map' errors on failure, and on the full-init path (a2==2) constructs a 444-byte VehicleViewObject child with sound instance, colour, scale and suspension parameters.

Methods: `0x00548AD0`

- `this+0x00000000` `dword childViewObject` (write, GUESS)
- `this+0x00000004` `dword sourceDataPtr` (write, GUESS)
- `this+0x0000000C` `dword viewFlag` (write, GUESS)
- `this+0x00000014` `dword passFlagA` (write, GUESS)
- `this+0x00000018` `dword passFlagB` (write, GUESS)

### VehicleCollisionSampleState

Small collision-contact/audio state record: tolerance-filtered contact value and 3-bit type storage (0x00500010) and a threshold-guarded collision audio sample handler with parameter interpolation and cross-fade (0x00500560). Shares FloatComparisonCheck (0x005001F0) and arithmetic-state copy (0x004B3A90).

Methods: `0x00500010`, `0x00500560`

- `this+0x00000000` `float contactValue` (read_write, GUESS)
- `this+0x00000004` `dword contactType` (read_write, GUESS)
- `this+0x00000008` `dword audioParams` (read_write, GUESS)
- `this+0x000001BC` `float thresholdValue` (read, GUESS)

### PhysicsInterfaceDispatcher

Indirect dispatch thunks over two adjacent function-pointer slots (off_5D76C0 / off_5D76C4): 0x00503659 and 0x005038EF dereference the stored pointer, call it with no arguments and return its result. Invoked per-interface from COMInterfaceVectorProcessingMethod (0x00504B37).

Methods: `0x00503659`, `0x005038EF`


### WheelForceTransformer

Transforms per-wheel suspension forces from wheel frame into chassis frame: copies a 4x4 matrix from +0x15C, iterates 6 wheel entries (16 bytes each from +0x104) through a device-wrapper vtable at global 0x008B8F24, and accumulates chassis offset (+0x24/+0x28/+0x2C).

Methods: `0x00541A70`

- `this+0x00000024` `float chassisOffsetX` (read, GUESS)
- `this+0x00000028` `float chassisOffsetY` (read, GUESS)
- `this+0x0000002C` `float chassisOffsetZ` (read, GUESS)
- `this+0x00000104` `dword wheelEntriesPtr` (read, GUESS)
- `this+0x0000015C` `dword matrix4x4` (read, GUESS)

## Compatibility contracts

- **PhysicsModeSelectorContract** — A replacement must preserve the physics-mode dispatch on this+0x32BC: 0 = tire slip-force (0x004472B0), 1 = per-wheel suspension contact + throttle/brake override (0x004EE230), 2/3 = spatial-grid collision with particle/spark effects; jump table global 0x004EF168.
- **CollisionSlotContract** — A replacement must process 13 collision contact slots per frame, read each event packet (0x0054FA90), gate slots 10-11 on this+0x3B74 and this+0xD0C/this+0xD4C, and report impulses to the collision result list via 0x0041AD80(dword_5EB978, vehicleId, matchedVehicle, impulse).
- **TireTemperatureMappingContract** — A replacement must map tire temperature category names to the same numeric values: first category 32.5, Warm 26.25, Medium 20.0, Cool 13.75, Cold computed via 0x0058850F, default 7.5.
- **DashboardCueDispatchContract** — A replacement must dispatch dashboard cues only when the corresponding slot at this+0x898..0x8B0 is active, emit state-change cues via 0x005506A0 for low-grip/gear/byte-flag/gauge changes, and scale the speedometer rotation by 2.0943952 and the gauge by flt_7CF740.
- **ReflectionMapEntryContract** — A replacement must require a render entry whose +96 dword has bit 0x800000 set and whose +64 byte has bit 2 set for reflection-map construction; failure logs 'No Reflection Map'/'Reflection Map' and returns -1.

## Unresolved

- Many read-only float globals (0x59E420, 0x59E43C..0x59EAE0, 0x5AC108, 0x5AC988, 0x5AD1DC, 0x5AD328..0x5AD358) are recorded as read by the skeleton facts but do not appear as named references in the decompiled bodies; they are likely physics tuning/ramp constants folded into arithmetic (rotation scale, brake/travel ramps, 4-bit contact scaling). Exact mapping unverified.
- The shared this layout used to group the five VehiclePhysics methods (orientation at +0x34B0, position at +0x34D4, mode selector at +0x32BC, wheel blocks at +0x3590/+0x3580) is proposal-level: only 0x004EE2D0 carries a packet DERIVED owner; equal offsets on unrelated this pointers do not prove identical classes.
- Semantics and side effects of VirtualDispatchHelper (0x0040C870), InterruptDispatch (0x0058957A) and Delegation (0x004B9CE0) on global session state are not resolved from this packet.
- Meaning of the bit flags produced by the VirtualDispatchHelper call in 0x004E19D0 is unclear.
- Gauge value semantics (lap segment versus speed readout) and the sub_58850F computation for the Cold tire category are not determinable from this packet alone.
- Field this+0x3610 is listed in the deterministic field list but does not appear in the decompilation; role unknown. Global unk_8AFEC0 is a read-only object referenced per the fact table but not visible in decompiled immediates.
- Exact structure of the collision event packet buffers returned by ArithmeticComparison_a010 (0x004EA010) and the packed collision-geometry list behind LinkedListIndexedAccessor_c230/PackedArrayIndexLookup are inferred from usage, not an independent source.
- The indirect targets behind off_5D76C0/off_5D76C4 and the device wrapper at global 0x008B8F24 are resolved at runtime; their classes and exact math are not statically bound here. 0x00503888 and 0x005038C0 are related dispatch-path functions not directly reached by 0x00503659/0x005038EF.
- Purpose of FieldReadDelegate (0x004E16C0) on the matrix region and which object the obj+0x4894 field selects in the stride-based lookup of 0x004EC080 are unknown; dbl_7C7428 as a race-time scalar is DERIVED from the fill, not independently confirmed.
- The a2/a4 argument semantics and the a3 descriptor layout in 0x00500010, plus sub_588410 return convention (0 == match) in 0x004FE2B0, are inferred from usage patterns.
- The 4x4 matrix copy in 0x00541A70 is described as a rotation matrix only from existing analysis (DERIVED); the packet shows a raw 16-dword copy. Wheel stride (16 bytes) and pivot-float meanings are DERIVED from indexing arithmetic.
- The viewport-dimension interpretation of the four fields forwarded by 0x00542560 to 0x00542200 is existing-analysis prose (DERIVED), not verifiable from the raw source.
- The two string globals aReflectionMapp/aRefview/aNoReflectionMa (0x5DBEC8/0x5DBEC0/0x5DBE94) contents are not shown; their exact text is unverified.
- Composition role of 0x0054B530 (DualMatrixTransformMultiply) and its six dword operands is unknown; callers pass different operand groupings and the owning object is unresolved.
