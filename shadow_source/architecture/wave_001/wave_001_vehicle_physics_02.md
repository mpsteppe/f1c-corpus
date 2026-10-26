# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

Architecture proposal for the vehicle_physics scope. Collision handling is split between a spatial-grid feature normal solver (CollisionFeatureSolver at 0x0044C550) and a family of linked-list managers operating on 16-byte {head,tail,anchor,count} records: CollisionBroadphaseBuilder (0x00490EE0) for AABB subdivision, and CollisionObjectListManager (0x004B4B50/0x004B4E10/0x004B5630) for sorting, minimum-tolerance removal, draining to a global free pool and filtering. Per-frame control comes from VehicleInputController (0x00454DA0) whose accumulators feed the VehiclePhysicsIntegrator (0x00459AE0). TrackEnvironmentManager (0x004AF3A0) initializes clamped environment parameter profiles; CarPhysicsState (0x004B57F0) is the large per-car physics state constructor; F1CVehicle (0x004C6E80/0x004C79E0/0x004C7BF0) covers reset/clear/property-set; QualifyingTireUsageRecorder (0x004BC060) encodes qualifying tire-set events. All class identities are DERIVED/GUESS proposals on validated IR; owners are mostly UNKNOWN in the packet.

## Function roles

- `0x0044C550` **CollisionFeatureSolver** — Collision normal solver: queries the spatial grid for the feature at a2 and derives the oriented collision normal from the feature plane coefficients into a3; returns the grid query result.
- `0x00454DA0` **VehicleInputController** — Per-frame input processor: ramps throttle/brake/clutch/steering/handbrake accumulators (mode==2 passthrough), sign-aware steering return-to-center, and gear selection from the gear-flag ladder with neutral override.
- `0x00459AE0` **VehiclePhysicsIntegrator** — Per-frame velocity/angular-velocity integrator: branches on the contact count at +0x50, integrates physics state, composes transforms, renders the sprite grid, and exchanges remote-vehicle state through the network packet codecs.
- `0x00490EE0` **CollisionBroadphaseBuilder** — Broadphase collision list builder: allocates a pool AABB node, filters existing nodes, clips overlapping AABBs into subdivisions, re-links and partitions the list.
- `0x004AF3A0` **TrackEnvironmentManager** — Track-environment physics parameter initializer: dispatches on the track-type selector at +0x3B40 to one of four profiles and initializes a dense run of clamped parameter slots plus a per-wheel 2x8 array.
- `0x004B4B50` **CollisionObjectListManager** — Collision object-list processor: when enabled, re-sorts the four sub-lists, then removes every node within the +/-0.02 tolerance of the global minimum head value and dispatches the collected nodes.
- `0x004B4E10` **CollisionObjectListManager** — Collision list drainer: moves every sub-list node into the global free pool (dword_8AB700 head/tail/count), stores the session timestamp, resets per-sub-list metadata and re-arms the enable flag.
- `0x004B5630` **CollisionObjectListManager** — Collision list filter: walks the active list, keeps nodes passing the compare/tolerance tests, and unlinks/replaces culled nodes into the output list.
- `0x004B57F0` **CarPhysicsState** — Per-car physics state constructor: zeroes the leading and middle arrays, sets sentinel/default blocks, forwards to sub-initializers, and configures the QPC timer block.
- `0x004BC060` **QualifyingTireUsageRecorder** — Qualifying tire-usage event encoder: during a qualifying session advances the ring buffer and encodes tire set in-use/discard events with the session-time payload and tire-compound byte.
- `0x004C6E80` **F1CVehicle** — Vehicle reset for reinitialization: clears physics/UI/driver sub-structures, reassigns random AI drivers, invalidates the slot markers at +0x48A4/+0x48A8, and resets the force-feedback base.
- `0x004C79E0` **F1CVehicle** — Driver-info region clearer: zeroes the byte fields, writes -1 into six slot-marker dwords, and sets fixed sentinels (0x48B4 = -8388609, 0x48BC = 11).
- `0x004C7BF0` **F1CVehicle** — Vehicle property setter: stores the argument into this[4651] (+0x48AC) and returns the stored value.

## Proposed classes

### CollisionFeatureSolver

Resolves the oriented collision normal for a query position from the spatial-grid collision feature's plane coefficients, writing it into the caller's output vector.

Methods: `0x0044C550`


### LinkedList

Generic doubly-linked node list: {head, tail, anchor/current, count} at offsets 0x0/0x4/0x8/0xC. The broadphase builder and collision-list managers operate on such records.

Methods: 

- `this+0x00000000` `pointer Head` (read_write, DERIVED)
- `this+0x00000004` `pointer Tail` (read_write, DERIVED)
- `this+0x00000008` `pointer Anchor` (read_write, DERIVED)
- `this+0x0000000C` `int Count` (read_write, DERIVED)

### CollisionNode

Node object for collision lists: value at +0x0, next link at +0x4 (also used as a float sort key), flag byte at +0x8, an unread dword at +0xC, and a distance/tolerance field at +0x370.

Methods: 

- `*(this+0x20)+0x00000000` `int/pointer Value` (read, DERIVED)
- `*(this+0x20)+0x00000004` `pointer/float NextLink` (read, DERIVED)
- `*(this+0x20)+0x00000008` `byte FlagByte` (read, DERIVED)
- `*(this+0x20)+0x0000000C` `dword UnusedField` (read, UNKNOWN)
- `*(*(this+0x20)+0x0)+0x00000370` `float Distance` (read, DERIVED)

### CollisionBroadphaseBuilder

Builds/updates a broadphase AABB list: allocates a pool AABB node, clips overlapping AABBs into subdivisions via RectangleClipping, re-links and partitions the result list.

Methods: `0x00490EE0`


### CollisionObjectListManager

Manages the per-frame collision object lists: four 16-byte {head,tail,anchor,count} sub-list records at +0x70, an output list and an active list, a filter threshold, and the global free-pool protocol for recycled nodes.

Methods: `0x004B4B50`, `0x004B4E10`, `0x004B5630`

- `this+0x00000000` `int EnableFlag` (read_write, DERIVED)
- `this+0x00000010` `pointer OutputListHead` (read_write, DERIVED)
- `this+0x00000014` `pointer OutputAnchorA` (read_write, DERIVED)
- `this+0x00000018` `pointer OutputAnchorB` (read_write, DERIVED)
- `this+0x0000001C` `int OutputCount` (read_write, DERIVED)
- `this+0x00000020` `pointer ActiveListHead` (read_write, DERIVED)
- `this+0x00000024` `pointer ActiveListTail` (read_write, DERIVED)
- `this+0x00000028` `pointer ActiveListIterator` (read_write, DERIVED)
- `this+0x0000002C` `int ActiveListCount` (read_write, DERIVED)
- `this+0x00000030` `float FilterThreshold` (read, DERIVED)
- `this+0x00000035` `dword SubListMeta0` (read_write, UNKNOWN)
- `this+0x00000039` `dword SubListMeta1` (read_write, UNKNOWN)
- `this+0x0000003D` `dword SubListMeta2` (read_write, UNKNOWN)
- `this+0x00000041` `byte SubListMetaByte` (read_write, UNKNOWN)
- `this+0x0000006C` `double SessionTimestamp` (write, DERIVED)
- `this+0x00000070` `pointer SubList1Head` (read_write, DERIVED)
- `this+0x00000074` `pointer SubList1Tail` (read_write, DERIVED)
- `this+0x00000078` `pointer SubList1Anchor` (read_write, DERIVED)
- `this+0x0000007C` `int SubList1Count` (read_write, DERIVED)

### VehicleInputController

Per-frame vehicle input processor: ramps per-axis smoothed accumulators toward direct targets with mode==2 passthrough, sign-aware steering return-to-center, and gear selection from the gear-flag ladder with neutral overrides.

Methods: `0x00454DA0`

- `this+0x00001B20` `int ThrottleMode` (read, DERIVED)
- `this+0x00001B44` `int ThrottleInputActive` (read, DERIVED)
- `this+0x00001B48` `float ThrottleDirectTarget` (read, DERIVED)
- `this+0x00001B4C` `int BrakeMode` (read, DERIVED)
- `this+0x00001B70` `int BrakeInputActive` (read, DERIVED)
- `this+0x00001B74` `float BrakeDirectTarget` (read, DERIVED)
- `this+0x00001B78` `int SteeringMode` (read, DERIVED)
- `this+0x00001B9C` `int SteeringInputActive` (read, DERIVED)
- `this+0x00001BA0` `float SteeringSignValue` (read, DERIVED)
- `this+0x00001BA4` `int SteeringMode2` (read, DERIVED)
- `this+0x00001BC8` `int NeutralFlag` (read, DERIVED)
- `this+0x00001BCC` `float SteeringDirectTarget` (read, DERIVED)
- `this+0x00001C54` `int HandbrakeMode` (read, DERIVED)
- `this+0x00001C78` `int HandbrakeInputActive` (read, DERIVED)
- `this+0x00001C7C` `float HandbrakeDirectTarget` (read, DERIVED)
- `this+0x00001FBC` `int GearFlagReverse` (read, GUESS)
- `this+0x00001FE8` `int GearFlag1` (read, GUESS)
- `this+0x00002014` `int GearFlag2` (read, GUESS)
- `this+0x00002040` `int GearFlag3` (read, GUESS)
- `this+0x0000206C` `int GearFlag4` (read, GUESS)
- `this+0x00002098` `int GearFlag5` (read, GUESS)
- `this+0x000020C4` `int GearFlag6` (read, GUESS)
- `this+0x000020F0` `int NeutralOverride` (read, DERIVED)
- `this+0x000021D4` `int ClutchMode` (read, DERIVED)
- `this+0x000021F8` `int ClutchInputActive` (read, DERIVED)
- `this+0x000021FC` `float ClutchDirectTarget` (read, DERIVED)
- `this+0x00002410` `float ThrottleOutput` (write, DERIVED)
- `this+0x00002414` `float BrakeOutput` (write, DERIVED)
- `this+0x00002418` `float ClutchOutput` (write, DERIVED)
- `this+0x0000241C` `float SteeringOutput` (write, DERIVED)
- `this+0x00002420` `float HandbrakeOutput` (write, DERIVED)
- `this+0x00002424` `int GearOutput` (read_write, DERIVED)
- `this+0x00002428` `byte GearSelectEnable` (read, DERIVED)

### VehiclePhysicsIntegrator

Per-frame velocity/angular-velocity integrator: reads physics coefficients and position/orientation/rotation state, branches on the contact count, integrates the physics state, composes transforms, renders the sprite grid and exchanges remote-vehicle state via the network packet codecs.

Methods: `0x00459AE0`

- `this+0x00000000` `pointer VTable` (read, DERIVED)
- `this+0x00000028` `float VelocityDragCoefficient` (read, DERIVED)
- `this+0x00000030` `float GravityScale` (read, DERIVED)
- `this+0x00000038` `float LongitudinalForce` (read, DERIVED)
- `this+0x00000040` `float LateralForce` (read, DERIVED)
- `this+0x00000048` `float CollisionRestitution` (read, DERIVED)
- `this+0x00000050` `int ContactPointCount` (read, DERIVED)
- `this+0x00000054` `float PositionX` (read, DERIVED)
- `this+0x00000058` `float PositionY` (read, DERIVED)
- `this+0x0000005C` `float PositionZ` (read, DERIVED)
- `this+0x00000064` `float OrientationElement00` (read, DERIVED)
- `this+0x00000068` `float OrientationElement10` (read, DERIVED)
- `this+0x000000C0` `float AngularVelocityOutX` (write, DERIVED)
- `this+0x000000C4` `float AngularVelocityOutY` (write, DERIVED)
- `this+0x000000C8` `float AngularVelocityOutZ` (write, DERIVED)
- `this+0x000000CC` `float AngularVelocityInX` (read, DERIVED)
- `this+0x000000D0` `float AngularVelocityInY` (read, DERIVED)
- `this+0x000000D8` `float AngularVelocityInZ` (read, DERIVED)
- `this+0x000000E0` `float RotationData0` (read, DERIVED)
- `this+0x000000E8` `float RotationData1` (read, DERIVED)
- `this+0x000000F0` `float RotationData2` (read, DERIVED)
- `this+0x00000100` `float RotationData3` (read, DERIVED)
- `this+0x00000108` `float RotationData4` (read, DERIVED)
- `this+0x00000110` `float RotationData5` (read, DERIVED)
- `this+0x00000118` `float AttitudeState0` (read, DERIVED)
- `this+0x00000120` `float AttitudeState1` (read, DERIVED)
- `this+0x00000130` `float AttitudeState2` (read, DERIVED)
- `this+0x00000138` `float AttitudeState3` (read, DERIVED)
- `this+0x00000140` `float AttitudeState4` (read, DERIVED)
- `this+0x00000148` `float AttitudeState5` (read, DERIVED)
- `this+0x00000150` `float TransformColumn0` (read, DERIVED)
- `this+0x00000158` `float TransformColumn1` (read, DERIVED)
- `this+0x00000160` `float TransformColumn2` (read, DERIVED)
- `this+0x00000180` `float TransformColumn3` (read, DERIVED)
- `this+0x00000208` `float WorkBlock0` (write, DERIVED)
- `this+0x0000020C` `float WorkBlock1` (write, DERIVED)
- `this+0x00000210` `float WorkBlock2` (write, DERIVED)
- `this+0x00000214` `float WorkBlock3` (write, DERIVED)
- `this+0x00000218` `float WorkBlock4` (write, DERIVED)
- `this+0x0000021C` `float WorkBlock5` (write, DERIVED)
- `this+0x00000220` `float WorkBlock6` (write, DERIVED)
- `this+0x00000224` `float WorkBlock7` (write, DERIVED)
- `this+0x00000228` `float WorkBlock8` (write, DERIVED)
- `this+0x0000022C` `float WorkBlock9` (write, DERIVED)
- `this+0x00000230` `float WorkBlock10` (write, DERIVED)
- `this+0x00000234` `float WorkBlock11` (write, DERIVED)

### TrackEnvironmentManager

Track-environment physics parameter container: the track-type selector at +0x3B40 dispatches to one of four profiles that initialize a dense run of clamped float parameter slots and a nested per-wheel 2x8 array (36-byte stride).

Methods: `0x004AF3A0`

- `this+0x00003B40` `int TrackTypeSelector` (read, DERIVED)
- `this+0x00003BAC` `float ProfileParam00_Value` (write, DERIVED)
- `this+0x00003BB4` `float ProfileParam00_Lower` (read, DERIVED)
- `this+0x00003BB8` `float ProfileParam00_Upper` (read, DERIVED)
- `this+0x00003BD0` `float ProfileParam01_Value` (write, DERIVED)
- `this+0x00003BD8` `float ProfileParam01_Lower` (read, DERIVED)
- `this+0x00003BDC` `float ProfileParam01_Upper` (read, DERIVED)
- `this+0x00003BF4` `float ProfileParam02_Value` (write, DERIVED)
- `this+0x00003BFC` `float ProfileParam02_Lower` (read, DERIVED)
- `this+0x00003C00` `float ProfileParam02_Upper` (read, DERIVED)
- `this+0x00003C18` `float ProfileParam03_Value` (write, DERIVED)
- `this+0x00003C20` `float ProfileParam03_Lower` (read, DERIVED)
- `this+0x00003C24` `float ProfileParam03_Upper` (read, DERIVED)
- `this+0x00003C3C` `float ProfileParam04_Value` (write, DERIVED)
- `this+0x00003C44` `float ProfileParam04_Lower` (read, DERIVED)
- `this+0x00003C48` `float ProfileParam04_Upper` (read, DERIVED)
- `this+0x00003C60` `float ProfileParam05_Value` (write, DERIVED)
- `this+0x00003C68` `float ProfileParam05_Lower` (read, DERIVED)
- `this+0x00003C6C` `float ProfileParam05_Upper` (read, DERIVED)
- `this+0x00003C84` `float ProfileParam06_Value` (write, DERIVED)
- `this+0x00003C8C` `float ProfileParam06_Lower` (read, DERIVED)
- `this+0x00003C90` `float ProfileParam06_Upper` (read, DERIVED)
- `this+0x00003CA8` `float ProfileParam07_Value` (write, DERIVED)
- `this+0x00003CB0` `float ProfileParam07_Lower` (read, DERIVED)
- `this+0x00003CB4` `float ProfileParam07_Upper` (read, DERIVED)
- `this+0x00003CCC` `float ProfileParam08_Value` (write, DERIVED)
- `this+0x00003CD4` `float ProfileParam08_Lower` (read, DERIVED)
- `this+0x00003CD8` `float ProfileParam08_Upper` (read, DERIVED)
- `this+0x00003CF0` `float ProfileParam09_Value` (write, DERIVED)
- `this+0x00003CF8` `float ProfileParam09_Lower` (read, DERIVED)
- `this+0x00003CFC` `float ProfileParam09_Upper` (read, DERIVED)
- `this+0x00003D14` `float ProfileParam10_Value` (write, DERIVED)
- `this+0x00003D1C` `float ProfileParam10_Lower` (read, DERIVED)
- `this+0x00003D20` `float ProfileParam10_Upper` (read, DERIVED)
- `this+0x00003D38` `float ProfileParam11_Value` (write, DERIVED)
- `this+0x00003D40` `float ProfileParam11_Lower` (read, DERIVED)
- `this+0x00003D44` `float ProfileParam11_Upper` (read, DERIVED)
- `this+0x00003D5C` `float ProfileParam12_Value` (write, DERIVED)
- `this+0x00003D64` `float ProfileParam12_Lower` (read, DERIVED)
- `this+0x00003D68` `float ProfileParam12_Upper` (read, DERIVED)
- `this+0x00003D80` `float ProfileParam13_Value` (write, DERIVED)
- `this+0x00003D88` `float ProfileParam13_Lower` (read, DERIVED)
- `this+0x00003D8C` `float ProfileParam13_Upper` (read, DERIVED)
- `this+0x00003DA4` `float ProfileParam14_Value` (write, DERIVED)
- `this+0x00003DAC` `float ProfileParam14_Lower` (read, DERIVED)
- `this+0x00003DB0` `float ProfileParam14_Upper` (read, DERIVED)
- `this+0x00003DC8` `float ProfileParam15_Value` (write, DERIVED)
- `this+0x00003DD0` `float ProfileParam15_Lower` (read, DERIVED)
- `this+0x00003DD4` `float ProfileParam15_Upper` (read, DERIVED)
- `this+0x00003DEC` `float ProfileParam16_Value` (write, DERIVED)
- `this+0x00003DF4` `float ProfileParam16_Lower` (read, DERIVED)
- `this+0x00003DF8` `float ProfileParam16_Upper` (read, DERIVED)
- `this+0x00003E10` `float ProfileParam17_Value` (write, DERIVED)
- `this+0x00003E18` `float ProfileParam17_Lower` (read, DERIVED)
- `this+0x00003E1C` `float ProfileParam17_Upper` (read, DERIVED)
- `this+0x00003E34` `float ProfileParam18_Value` (write, DERIVED)
- `this+0x00003E3C` `float ProfileParam18_Lower` (read, DERIVED)
- `this+0x00003E40` `float ProfileParam18_Upper` (read, DERIVED)
- `this+0x00003E58` `float ProfileParam19_Value` (write, DERIVED)
- `this+0x00003E60` `float ProfileParam19_Lower` (read, DERIVED)
- `this+0x00003E64` `float ProfileParam19_Upper` (read, DERIVED)
- `this+0x00003E7C` `float ProfileParam20_Value` (write, DERIVED)
- `this+0x00003E84` `float ProfileParam20_Lower` (read, DERIVED)
- `this+0x00003E88` `float ProfileParam20_Upper` (read, DERIVED)
- `this+0x00003EA0` `float ProfileParam21_Value` (write, DERIVED)
- `this+0x00003EA8` `float ProfileParam21_Lower` (read, DERIVED)
- `this+0x00003EAC` `float ProfileParam21_Upper` (read, DERIVED)
- `this+0x00003EC4` `float ProfileParam22_Value` (write, DERIVED)
- `this+0x00003ECC` `float ProfileParam22_Lower` (read, DERIVED)
- `this+0x00003ED0` `float ProfileParam22_Upper` (read, DERIVED)
- `this+0x00003EE8` `float ProfileParam23_Value` (write, DERIVED)
- `this+0x00003EF0` `float ProfileParam23_Lower` (read, DERIVED)
- `this+0x00003EF4` `float ProfileParam23_Upper` (read, DERIVED)
- `this+0x00003F0C` `float ProfileParam24_Value` (write, DERIVED)
- `this+0x00003F14` `float ProfileParam24_Lower` (read, DERIVED)
- `this+0x00003F18` `float ProfileParam24_Upper` (read, DERIVED)
- `this+0x00003F30` `float ProfileParam25_Value` (write, DERIVED)
- `this+0x00003F38` `float ProfileParam25_Lower` (read, DERIVED)
- `this+0x00003F3C` `float ProfileParam25_Upper` (read, DERIVED)
- `this+0x00003F54` `float ProfileParam26_Value` (write, DERIVED)
- `this+0x00003F5C` `float ProfileParam26_Lower` (read, DERIVED)
- `this+0x00003F60` `float ProfileParam26_Upper` (read, DERIVED)
- `this+0x00003F78` `float ProfileParam27_Value` (write, DERIVED)
- `this+0x00003F80` `float ProfileParam27_Lower` (read, DERIVED)
- `this+0x00003F84` `float ProfileParam27_Upper` (read, DERIVED)
- `this+0x00003F9C` `float ProfileParam28_Value` (write, DERIVED)
- `this+0x00003FA4` `float ProfileParam28_Lower` (read, DERIVED)
- `this+0x00003FA8` `float ProfileParam28_Upper` (read, DERIVED)
- `this+0x00003FC0` `float ProfileParam29_Value` (write, DERIVED)
- `this+0x00003FC8` `float ProfileParam29_Lower` (read, DERIVED)
- `this+0x00003FCC` `float ProfileParam29_Upper` (read, DERIVED)
- `this+0x00003FE4` `float ProfileParam30_Value` (write, DERIVED)
- `this+0x00003FEC` `float ProfileParam30_Lower` (read, DERIVED)
- `this+0x00003FF0` `float ProfileParam30_Upper` (read, DERIVED)
- `this+0x00004008` `float ProfileParam31_Value` (write, DERIVED)
- `this+0x00004010` `float ProfileParam31_Lower` (read, DERIVED)
- `this+0x00004014` `float ProfileParam31_Upper` (read, DERIVED)
- `this+0x0000402C` `float WheelArrayElementA_Value` (write, DERIVED)
- `this+0x00004034` `float WheelArrayElementA_Lower` (read, DERIVED)
- `this+0x00004038` `float WheelArrayElementA_Upper` (read, DERIVED)
- `this+0x0000426C` `float WheelArrayElementB_Value` (write, DERIVED)
- `this+0x00004274` `float WheelArrayElementB_Lower` (read, DERIVED)
- `this+0x00004278` `float WheelArrayElementB_Upper` (read, DERIVED)
- `this+0x000044AC` `float WheelArrayElementC_Value` (write, DERIVED)
- `this+0x000044B4` `float WheelArrayElementC_Lower` (read, DERIVED)
- `this+0x000044B8` `float WheelArrayElementC_Upper` (read, DERIVED)
- `this+0x000046EC` `float WheelArrayElementD_Value` (write, DERIVED)
- `this+0x000046F4` `float WheelArrayElementD_Lower` (read, DERIVED)
- `this+0x000046F8` `float WheelArrayElementD_Upper` (read, DERIVED)

### CarPhysicsState

Large per-car physics state object (DWORD array up to this[998]): zeroed leading/middle arrays, sentinel and default blocks, sub-initializer forwards, and a QPC timer configuration block.

Methods: `0x004B57F0`

- `this+0x00000000` `dword StateWords0to3` (write, DERIVED)
- `this+0x00000010` `quad Quad0` (write, DERIVED)
- `this+0x00000020` `dword StateWords8to11` (write, DERIVED)
- `this+0x00000030` `quad Quad1` (write, DERIVED)
- `this+0x00000040` `dword ZeroLoopWord0` (write, DERIVED)
- `this+0x00000044` `dword ZeroLoopWord1` (write, DERIVED)
- `this+0x00000048` `dword ZeroLoopWord2` (write, DERIVED)
- `this+0x0000004C` `dword ZeroLoopWord3` (write, DERIVED)
- `this+0x000006C0` `dword StateWords432to435` (write, DERIVED)
- `this+0x000006D4` `dword StateWords437to440` (write, DERIVED)
- `this+0x00000700` `dword StateWord448` (write, DERIVED)
- `this+0x00000704` `dword SentinelBlock` (write, DERIVED)
- `this+0x000009A4` `dword ConfigBlock617to623` (write, GUESS)
- `this+0x00000D28` `dword StateWord842` (write, DERIVED)
- `this+0x00000D78` `dword StateWord862` (write, DERIVED)
- `this+0x00000F24` `dword StateWords969to973` (write, DERIVED)
- `this+0x00000F38` `dword StateWord974` (write, DERIVED)
- `this+0x00000F3C` `dword StateWord975` (write, DERIVED)
- `this+0x00000F40` `dword StateWord976` (write, DERIVED)
- `this+0x00000F44` `dword StateWords977to980` (write, DERIVED)
- `this+0x00000F64` `dword StateWords985to988` (write, DERIVED)
- `this+0x00000F74` `dword StateWord989` (write, DERIVED)
- `this+0x00000F78` `byte ByteFlag0` (write, DERIVED)
- `this+0x00000F79` `byte ByteFlag1` (write, DERIVED)
- `this+0x00000F7A` `byte ByteFlag2` (write, DERIVED)
- `this+0x00000F7C` `float FloatSlot` (write, DERIVED)
- `this+0x00000F81` `byte ByteFlag3` (write, DERIVED)
- `this+0x00000F8C` `dword StateWord995` (write, DERIVED)
- `this+0x00000F90` `dword StateWord996` (write, DERIVED)
- `this+0x00000F94` `dword StateWord997` (write, DERIVED)
- `this+0x00000F98` `dword StateWord998` (write, DERIVED)

### QualifyingTireUsageRecorder

Records qualifying tire-usage ring-buffer events: during a qualifying session advances the ring buffer and encodes tire set in-use/discard events with a session-time payload and the tire-compound byte.

Methods: `0x004BC060`

- `this+0x00000004` `int VehicleId` (read, DERIVED)
- `this+0x00000034` `byte TireCompound` (read, DERIVED)

### F1CVehicle

The per-vehicle object. Carries the driver-info region (bytes 0x4620..0x48BC) that is cleared and reset, the live AI-driver slots, and the recalculated property slot at +0x48AC.

Methods: `0x004C6E80`, `0x004C79E0`, `0x004C7BF0`

- `this+0x00004620` `char[8] DriverName` (write, DERIVED)
- `this+0x00004660` `byte NumberOfLaps` (write, GUESS)
- `this+0x00004678` `char CarName` (write, DERIVED)
- `this+0x000046B8` `byte UnknownByte0` (write, UNKNOWN)
- `this+0x000046F8` `byte UnknownByte1` (write, UNKNOWN)
- `this+0x00004708` `byte UnknownByte2` (write, UNKNOWN)
- `this+0x00004710` `dword DriverSlotMarker` (write, UNKNOWN)
- `this+0x00004714` `char VehiclePath` (write, DERIVED)
- `this+0x00004794` `char SaveFilePath` (write, DERIVED)
- `this+0x00004898` `dword SlotMarker0` (write, UNKNOWN)
- `this+0x0000489C` `dword DriverID` (write, GUESS)
- `this+0x000048A0` `dword SlotMarker1` (write, UNKNOWN)
- `this+0x000048A4` `dword PitTeamIndex` (write, GUESS)
- `this+0x000048A8` `dword SlotMarker2` (write, UNKNOWN)
- `this+0x000048AC` `dword PropertySlot` (read_write, GUESS)
- `this+0x000048B0` `word WordSlot` (write, UNKNOWN)
- `this+0x000048B4` `dword MaskSlot` (write, UNKNOWN)
- `this+0x000048B8` `dword DwordSlot0` (write, UNKNOWN)
- `this+0x000048BC` `dword DwordSlot1` (write, UNKNOWN)

## Compatibility contracts

- **CollisionNormalOutputConvention** — A replacement must write the normalized collision normal into the caller output vector a3 as { -(v8*v6), v8, -(v8*v7) } with v8 = 1/sqrt(v7*v7 + v6*v6 + 1.0) derived from the feature plane coefficients, and return the spatial-grid query result (feature pointer or NULL).
- **VehicleInputSmoothingOutputOrder** — A replacement must emit the smoothed control outputs through output pointers in the order a3=steering, a4=throttle, a5=brake, a6=clutch, a7=handbrake, a8=gear, with throttle/brake/clutch/handbrake clamped to the [0,1] float range and the gear output in {-2..7} with the neutral override honoring global byte_7D1370.
- **DriverInfoClearSentinels** — A replacement clearing the vehicle driver-info region must zero the byte fields at 0x4620/0x4660/0x4678/0x46B8/0x46F8/0x4708/0x4714/0x4794, write -1 into dwords 0x4710/0x4898/0x489C/0x48A0/0x48A4/0x48A8, 0 into 0x48AC/0x48B8, -8388609 into 0x48B4 and 11 into 0x48BC.
- **CollisionNodeFreePoolProtocol** — A replacement reusing collision nodes must push drained nodes onto the global free pool through dword_8AB700 (head), dword_8AB704 (tail), dword_8AB708 (used when the pool is empty) and increment dword_8AB70C (count).

## Unresolved

- The layout of the feature plane returned by SpatialGridQuery (result[0..4]) is not enumerated as packet fields (CollisionNormalFromFeature).
- dbl_59E420 is read by CollisionNormalFromFeature but does not appear by name in the decompiled arithmetic; the 1.0 normalization constant is the only plausible consumer -- unverified.
- The steering fallthrough ramp direction in VehicleInputSmoothingAndGearSelect is ambiguous: it is chosen by a decompiler FPU-status byte (v24 & 0x41) whose origin is unverifiable in the .c.
- Six read-only globals (0x0059E43C, 0x0059E440, 0x0059E478, 0x0059E5FC, 0x0059E670, 0x0059E8A4) are read by VehicleInputSmoothingAndGearSelect but folded into FPU instructions by Hex-Rays; no named reference exists in the .c.
- Gear-field semantics (which of +0x1FBC/+0x1FE8/+0x2014/+0x2040/+0x206C/+0x2098/+0x20C4 maps to which gear) come from DERIVED fill naming, not from the .c.
- The raw decompiled body of VehiclePhysicsVelocityAngularVelocityIntegrator is truncated in the packet; exact ordering and FPU/long-double comparison semantics are not recoverable.
- The branching meaning of the guard at +0x50 (contact-point count <= 1) versus the multi-vehicle network contact-force path is inferred from prior analysis.
- The roles of the integration constants dbl_59E420/59E430/59E880/59ED50/59F038/59F040/59F048/59F050/59F058 and dword_8AB710 in the integrator are not pinned down; the step-size parameter value is absent from the packet.
- The meaning of the collision node flags byte at obj+0x8 is unknown; no operation consumes it in CollisionBroadphaseBuilder.
- The semantics of the sub_490D00 partitioning step and the argument 0 to DoublyLinkedListAppend in CollisionBroadphaseBuilder are unknown.
- The concrete target offsets written by ClampedFloatSetter_1de0/ArithmeticComparison_20d0 in TrackPhysicsParameterInit profiles 2 and 3 are not evidenced (writes happen inside the callees).
- The per-wheel loop base this+0x4258 used by profiles 2 and 3 is not present in the packet field list, so its element offsets cannot be tied to evidence refs.
- The physical meaning of each TrackEnvironmentManager parameter slot (grip, wear, temperature, etc.) is not deterministically evidenced; only that they are clamped track-environment physics parameters.
- flt_5ACD0C and dword_8AB700 are read by ProcessCollisionObjectLists but absent from the raw source text; flt_5ACD0C may back the +/-0.02 tolerance literal but that link is unconfirmed.
- Only the first of the four 16-byte sub-list records (this+0x70/0x74/0x78/0x7C) has packet field evidence; records 2-4 are un-evidenced.
- The DrainCollisionListsToFreePool reset loop also zeroes a parallel per-sub-list metadata array with no packet field evidence.
- Collision node field +0xC is listed in the packet but never read by FilterCollisionListNodes; global dbl_5ACD30 is read but absent from the raw text (the 2.5 distance bound is a literal).
- The object type and semantic purpose of the sentinel 0/-1 blocks and the config block this[617..623] = 4/2/2/0/0/0/0 in CarPhysicsStateInitializer are not established by this packet.
- The sub-list allocated via ConditionalArrayAlloc/ListAppendWithSubListGeneration in CarPhysicsStateInitializer is not referenced again in that function; its disposition is unknown.
- The semantic labels for tire-usage event ids 26 (in use) vs 27 (discarded) come from existing-analysis prose, not from the raw source.
- The ABI lead name Vehicle_Audio_Event_Dispatch conflicts with the tire-usage interpretation of EncodeQualifyingTireUsage; the legacy lead is unconfirmed.
- The non-qualifying return path of EncodeQualifyingTireUsage reads an uninitialized register, so the returned value there is undefined.
- The +0x48A4/+0x48A8 slot markers and the -1 sentinel semantics (invalid/uninitialised) in ResetVehicleForReinit are DERIVED from the unconditional reset context.
- The final reset call on dword_8ACEE0 in ResetVehicleForReinit targets an address not present in the packet's callee list, so it is described without naming the target.
- The semantic meaning of the unnamed F1CVehicle driver-info fields (0x46B8, 0x46F8, 0x4708, 0x4710, 0x4898, 0x48A0, 0x48A8, 0x48AC, 0x48B0, 0x48B4, 0x48B8, 0x48BC) is not recoverable from this packet.
- The recalc writer of field 0x48AC (noted by existing analysis as recalculated every frame, so external pokes do not persist) is not evidenced by this packet.
- CarPhysicsState field at offset 0x000006E4 (SmallStruct) could not be carried as a class field: no allowed evidence ref field:<base>:0x000006E4 exists in the packet for this offset, so its presence is recorded only in this unresolved note.
- CarPhysicsState field at offset 0x00000D2C (TimerStruct) could not be carried as a class field: no allowed evidence ref field:<base>:0x00000D2C exists in the packet for this offset, so its presence is recorded only in this unresolved note.
- CarPhysicsState field at offset 0x00000D7C (TimerBlock) could not be carried as a class field: no allowed evidence ref field:<base>:0x00000D7C exists in the packet for this offset, so its presence is recorded only in this unresolved note.
- CarPhysicsState field at offset 0x00000F54 (Quad981) could not be carried as a class field: no allowed evidence ref field:<base>:0x00000F54 exists in the packet for this offset, so its presence is recorded only in this unresolved note.
