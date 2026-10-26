# VehiclePhysicsSubsystem

Scope: `vehicle_physics`  
Trust: `DERIVED`

DERIVED proposal for the vehicle_physics scope from 20 validated functions. The active-vehicle per-frame drivers (0x004B3BA0 IterateVehicles and 0x004B3DC0 VehicleVisibilityCulling) both iterate the live vehicle pointer array dword_7C54F0 gated by vehicle count dword_5C329C, so they are grouped as a GUESS class VehicleFrameScheduler; IterateVehicles advances per-vehicle tire temperature via 0x004C77D0 while VehicleVisibilityCulling runs camera-space culling through the session interface (dword_5EA510), the camera object (dword_7C54E0), EulerToRotationMatrix (0x00566E40) and a distance sort (0x005890AA) before driving audio/flag/UI transitions. The vehicle-file registry core is grouped as VehicleFileRegistry (GUESS) over the dword_8AC394/dword_8AC390/dword_8AC38C globals: VehicleLookupByName (0x004C3F80), CurrentVehicleAccessor (0x004C4080), VehicleDataLoader (0x004C4240, a string-key selection sort) and VehicleNameEnumerationThenNationalityLoad (0x004C7B20). Two distinct this-objects append vehicle indices to per-object linked lists with different field layouts, so they are kept separate: VehicleIndexListAccessor (0x004BFCD0, head at this+0x0, cursor this+0x8, count this+0xC, node data at *(this+0x8)) and VehicleSelectionListBuilder (0x004C4990, 0x004C4AA0, head/tail/first/count at this+0x8/+0xC/+0x10/+0x14). ResetVehicleDataStruct (0x004C3050) is the 1060-byte vehicle-file-entry initializer (VehicleFileEntry, GUESS). The vehicle physics body is split by ownership-uncertainty into separate GUESS classes: WheelContactUpdater (0x004EF180, rotation matrix 0x704..0x724, contact-normal array 0x3668), TireCompoundPhysicsApplier (0x004F18C0, per-wheel slots 13840..13880 + stride 248, fields 0x32BC/0x396C/0x3970/0x3BF4), TireBrandDefinition (0x004D6B00, front/rear tire blocks at +0x18/+0x160 with grip/wear/averaging), ParticleCollisionEmitter (0x004C9FB0, noise-table spread 0x18..0x38 + filtered record buffer), VehicleMeshLoadHandler (0x004A51C0, detail-level LOD mesh/audio load), VehicleTransformEmitter (0x004A27D0, guarded 6-parameter transform dispatch to 0x0054B4D0), VehicleScalarSampler (0x004B9E30, double-indirect read of vehicle+0xF8C), VehicleDebugOverlayRenderer (0x004DA0D0, two-column HUD text) and VehicleGeometryRecenteringHelper (0x004E2AD0, box-midpoint recenter of two scene objects). VehicleSetupDriverNumber (0x004C7B50) is the packet-labelled F1CVehicle (CONFIRMED) driver-number setup method and is kept as the single method of a GUESS F1CVehicle class because worker output cannot exceed GUESS. All class owners are GUESS except that packet labels the 0x004C7B50 owner CONFIRMED; function_roles carries evidence for every required function exactly once.

## Function roles

- `0x004A27D0` **VehicleTransformEmitter** — Conditional transform/position forwarder: when the DWORD at this+0x64 is non-zero, dispatches this+0x4C/0x50/0x54 (DWORDs) and this+0x58/0x5C/0x60 (floats) to sub_54B4D0; otherwise returns this unchanged.
- `0x004A51C0` **VehicleMeshLoadHandler** — Tire/wheel graphics mesh loader: opens the tire-sound audio stream for handle a2, maps the global detail level dword_7CF884 through jump table jpt_4A5216 to an LOD scale (3.0/2.0/1.0/0.0), iterates file entries via ConditionalDispatchBasedOnFlag, resolves each name through the global instance table at dword_5CD620, hands entries to TireWheelGraphicsMeshLoader (0x004A4ED0), then conditionally cleans up the file handle; invoked by sub_4A4900.
- `0x004B3BA0` **VehicleFrameScheduler** — Per-frame tire-temperature driver: iterates i from 0 while i < dword_5C329C (vehicle count), calls TireTemperatureSimStep (0x004C77D0) with dword_7C54F0[i], then returns the vehicle count; called from GamePostMainLoop (0x0042D8A0).
- `0x004B3DC0` **VehicleFrameScheduler** — Per-frame vehicle visibility culling: resolves the session interface via VirtualDispatchHelper on dword_5EA510, skips the pass when the interface flag at +112 or the count bound dword_7CFC8C applies, else builds camera space from the camera object dword_7C54E0 and interface Euler angles via EulerToRotationMatrix (0x00566E40), sorts vehicles by planar distance with sub_5890AA, marks the nearest dword_7CFC8C visible, and on transitions starts/stops engine sound (0x004E0ED0), clears flags/UI (0x0054C030, 0x0054C1B0); called by RenderScreenSave (0x004B40A0).
- `0x004B9E30` **VehicleScalarSampler** — Double-indirection vehicle scalar accessor: reads the vehicle pointer at this+0x0 and returns the DWORD at vehicle+0xF8C; sampled per frame by telemetry, render, particle and weather systems.
- `0x004BFCD0` **VehicleIndexListAccessor** — Indexed lookup into the global vehicle-file entry array: walks a singly-linked list from *this for a2 steps (next pointer at node+4), caches the current node in this+0x8, reads the vehicle-file index from *(this+0x8), and when below dword_8AC390 returns dword_8AC394 + 1060 * index (stride 0x424); returns 0 on any out-of-range path; called by GameFilterDataLoader (0x004C0DB0).
- `0x004C3050` **VehicleFileEntry** — Vehicle-file entry initializer: zeroes alternating 0/-1 sentinel pairs this+0x00..0x24 and this+0x3CC..0x3DC, clears the dword block this+0x38..0x6C, sets this+0x70 to 1.0f, and clears scattered byte/dword flags (0x74, 0x7C, 0xBC..0x420); no reads, no calls; called by VehicleFileLoader (0x004C3D80) and VehicleDataLoader (0x004C4240).
- `0x004C3F80` **VehicleFileRegistry** — Vehicle-file lookup by name: iterates entries at stride 1060 from dword_8AC394, compares each entry name pointer (defaulting to byte_5EA438 when null) against the search name via sub_588410 (0 return = match), and stores the matching index into dword_8AC38C; no write when the name, count dword_8AC390 or match is absent.
- `0x004C4080` **VehicleFileRegistry** — Bounds-checked index accessor: returns dword_8AC394 + 1060 * dword_8AC38C when the index is within [0, dword_8AC390), else 0.
- `0x004C4240` **VehicleFileRegistry** — Vehicle-file selection sort: initializes a temp buffer with 0x004C3050, and for each 1060-byte position at dword_8AC394 finds the best remaining entry via CompositeStringCompare (0x004C3890), then swaps it into place by copying string fields (realloc via 0x00566650 with 0x00415C30 null-safe dereference), dword blocks and byte blocks through VehicleDataCopy (0x004C45D0); runs only when dword_8AC390 > 0 and finishes with MultiFieldCleanup (0x004C3130).
- `0x004C4990` **VehicleSelectionListBuilder** — Vehicle filtering by criteria list: when the first criteria word, the criteria count a3 and dword_8AC390 are all positive, iterates the vehicle array, skips slots already in the exclusion list (LinkedListKeySearch 0x004C4CB0) or null, requires every criteria value a2[v7] to compare equal at vehicle field byte offset 444 via sub_566810, and appends a 12-byte node (value pointer, next, flag byte at +8 = 1) with an allocated 4-byte index cell to the this-object list (head/tail/first/count at this+0x8/+0xC/+0x10/+0x14); returns the number appended.
- `0x004C4AA0` **VehicleSelectionListBuilder** — Vehicle grid selection: scans the dword_8AC394 grid (dword_8AC390 slots, stride 1060), skips slots already registered (LinkedListKeySearch 0x004C4CB0) or null, matches the per-slot field at byte offset 444 against every value in a2[0..a3-1] via sub_566810, and appends an allocated 12-byte link (index-cell pointer, next, flag byte at +8 = 1) to the this-object list (head/tail/first/count at this+0x8/+0xC/+0x10/+0x14); returns the number of slots appended.
- `0x004C7B20` **VehicleFileRegistry** — Two-step vehicle/driver delegation: calls VehicleNameEnumeration (0x004C3FE0) with the config path a2, then NationalityDriverInfoLoader (0x004C78F0) with this and the enumerated index dword_8AC38C, returning its result; used by NetCommPlayerSlotSync (0x0045FC50), LoadVehicleEntries (0x004B70B0) and ProcessDriverEntries (0x004B8DA0).
- `0x004C7B50` **F1CVehicle** — Vehicle setup step from VehgenScnFileLoader (0x004C6C40): looks up the driver number via NamedEntryLookupInFormatList (0x00415230) on the dword_5EA5E8 format list using a name at this+17952 and a list at this+18196, storing into this+0x489C; on a negative result falls back to a vehicle-array entry (dword_8AC394 + 1060 * field 0x4898) with byte_5EA438 default name; then scans the same format list with LinkedListIndexScannerWithValidation (0x00415550) on the long-description string at this+18104 and returns the stored index at this+0x48A0.
- `0x004C9FB0` **ParticleCollisionEmitter** — Particle collision spawn handler: with a collision source a2 and a live render list (0x0054C230), stores the source at this+0x0, computes the bounding box via 0x004DD550, re-centers this+0x4/+0x8/+0xC on the box midpoint, stores the half-extent at this+0x10, and when the vertical extent is positive seeds spread from the noise table flt_8AB274 with byte-wrapped index dword_8AAE70 into this+0x18..0x30, counts elements above the collision height into this+0x34, and fills a 20-byte-record buffer at this+0x38; called from SpecialFX_Init (0x004CF070).
- `0x004D6B00` **TireBrandDefinition** — Tire-brand definition parser: initializes grip/wear defaults (this+8/0xC = 1.0f, this+0x10 = 10, this+0x14 = 0), reads tokens via ConditionalDispatchBasedOnFlag (0x00566CC0) and sub_5651B0, selects the front (this+0x18) or rear (this+0x160) tire sub-block via sub_587C20, fills grip lat/long curves, radius/width/spring/damper/load-sensitivity/camber/rolling-resistance/heating/wear/AI tuning and optimum temperature/pressure fields through sub_565AA0 with the radius*RPM factor 9.549296585513721 and camber factor 0.0174532925199433, reads curve-name strings, averages the four dry-grip doubles into this+8 and four wet-grip doubles into this+0xC, computes and clamps the wear rating into this+0x10 via CRTFtol (0x00587BDC); invoked by TireBrandFileParser (0x004D7150).
- `0x004DA0D0` **VehicleDebugOverlayRenderer** — Two-column vehicle debug/HUD overlay: a byte flag at this+0x18 selects which of this+0x1C and the camera global dword_7C54E0 supplies the left entity, and for each non-null entity renders a gear/position '%c' character (*(entity+0x4060)-1 plus byte_5D4AE8), the name string at *(entity+0x46F8) normalized via sub_589901, indexed single-character entries from dword_5D4AF4 with base bytes byte_5D4AF0/byte_5D4AF1, and the speed of this+0x14 as '%6.3f'; all drawn via UITextRenderWithScale (0x004D7E40) with the format helper 0x0058815F; called by sub_4D9F80.
- `0x004E2AD0` **VehicleGeometryRecenteringHelper** — Physics/audio geometry recentering: computes the primary object's bounding box via 0x004DD550, derives its midpoint, and for each of two scene objects offsets the object position (via 0x0054B420/0x0054B3B0) and every packed vertex (0x0054E100/0x0054E120) by the midpoint, clears per-child flags, and rebuilds each child's bounding box (0x0054D520/0x0054E270/0x0054D080); called from the vehicle graphics scene loader.
- `0x004EF180` **WheelContactUpdater** — Wheel-contact transform: for each of four wheel-corner vectors (advancing 74 floats / 62 pointer slots per step to 296 floats), rotates the per-corner offset (this[523..525]) by the 3x3 rotation matrix at this+0x704..0x724, adds the world-origin offset this[443] via F_3DVectorAddition (0x004EC020), queries the collision normal from feature data dbl_7C9360 via CollisionNormalFromFeature (0x0044C550), stores it into the contact-normal pointer array at this+0x3668 with a 0.050000001 depth adjustment, and updates wheel-surface friction via WheelSurfaceContactFriction (0x004CE110); runs once per frame tick.
- `0x004F18C0` **TireCompoundPhysicsApplier** — Tire-compound setup for one wheel index: stores the compound index a3 at this+0x3970, resolves the compound entry via CompoundIndexLookup (0x004D7570) from the table at this+0x396C, maps the name (byte_5EA438 fallback) through TireCompoundNameIDMapping (0x004A4830) and MultiplayerSessionType (0x004E2370), selects front (entry+6) or rear (entry+88) data, computes per-wheel force/spring/load/grip values at this+13840..13880 (plus 248 * a2) using VehicleSuspensionForceHelper (0x004D6AE0), the load scale at this+0x3BF4 and DivisionWithThreshold (0x004D5EA0), optionally runs TireBrushModelForceSolver (0x004E8010), and when no rigid body is attached (this+0x32BC == 0) records the index in dword_7C8884 and applies via TireCompoundPerWheelPhysicsApplication (0x0043DA10) on dbl_7C7428.

## Proposed classes

### F1CVehicle

The packet labels VehicleSetupDriverNumber as a F1CVehicle (CONFIRMED) method; this class keeps the single evidenced driver-number setup step and the three vehicle identity fields it reads/writes. Worker trust is capped at GUESS.

Methods: `0x004C7B50`

- `this+0x00004898` `DWORD vehicleArrayEntryIndex` (read, GUESS)
- `this+0x0000489C` `DWORD driverNumberId` (read_write, GUESS)
- `this+0x000048A0` `DWORD longDescriptionListIndex` (read_write, GUESS)

### VehicleFileRegistry

Free-function group over the global vehicle-file entry array (dword_8AC394, 1060-byte stride, count dword_8AC390, current index dword_8AC38C): name lookup, bounds-checked index access, string-key selection sort and the enumerate-then-load-nationality delegation.

Methods: `0x004C3F80`, `0x004C4080`, `0x004C4240`, `0x004C7B20`


### VehicleIndexListAccessor

This-object owning a singly-linked list of vehicle-file indices (head at this+0x0, iteration cursor this+0x8, count this+0xC; node data pointer at *(this+0x8)); resolves a2-th entry to a dword_8AC394 element or 0.

Methods: `0x004BFCD0`

- `this+0x00000000` `void* listHead` (read, GUESS)
- `this+0x00000008` `void* iterationCursor` (read_write, GUESS)
- `this+0x0000000C` `DWORD listCount` (read, GUESS)
- `*(this+0x8)+0x00000000` `void* nodeDataPtr` (read, GUESS)

### VehicleSelectionListBuilder

This-object owning a linked list of selected vehicle indices (head this+0x8, tail this+0xC, first this+0x10, count this+0x14) that both filter and grid-selection functions append to; nodes are 12-byte allocations with a value pointer, next pointer and flag byte at +8.

Methods: `0x004C4990`, `0x004C4AA0`

- `this+0x00000008` `void* headNode` (read_write, GUESS)
- `this+0x0000000C` `void* tailNode` (read_write, GUESS)
- `this+0x00000010` `void* firstNode` (write, GUESS)
- `this+0x00000014` `DWORD matchCount` (read_write, GUESS)

### VehicleFileEntry

The 1060-byte vehicle-file entry initializer: sentinel pair groups, cleared dword/byte flags, a 1.0f field at +0x70; used as both the real entry init and the temp-buffer init for the registry sort.

Methods: `0x004C3050`

- `this+0x00000000` `DWORD sentinelPair0Value` (write, GUESS)
- `this+0x00000004` `DWORD sentinelPair0Id` (write, GUESS)
- `this+0x00000008` `DWORD sentinelPair1Value` (write, GUESS)
- `this+0x0000000C` `DWORD sentinelPair1Id` (write, GUESS)
- `this+0x00000010` `DWORD sentinelPair2Value` (write, GUESS)
- `this+0x00000014` `DWORD sentinelPair2Id` (write, GUESS)
- `this+0x00000018` `DWORD sentinelPair3Value` (write, GUESS)
- `this+0x0000001C` `DWORD sentinelPair3Id` (write, GUESS)
- `this+0x00000020` `DWORD sentinelPair4Value` (write, GUESS)
- `this+0x00000024` `DWORD sentinelPair4Id` (write, GUESS)
- `this+0x00000028` `BYTE clearByteFlag0` (write, GUESS)
- `this+0x00000038` `BYTE[0x38] zeroBlockStart` (write, GUESS)
- `this+0x00000070` `FLOAT onePointZeroField` (write, GUESS)
- `this+0x000000BC` `BYTE clearByteFlag1` (write, GUESS)
- `this+0x000003CC` `DWORD sentinelPair5Value` (write, GUESS)
- `this+0x000003D0` `DWORD sentinelPair5Id` (write, GUESS)
- `this+0x000003D8` `DWORD sentinelPair6Value` (write, GUESS)
- `this+0x000003DC` `DWORD sentinelPair6Id` (write, GUESS)
- `this+0x00000420` `DWORD tailClearDword` (write, GUESS)

### VehicleFrameScheduler

Per-frame active-vehicle pass drivers sharing the dword_7C54F0 vehicle pointer array and dword_5C329C count: tire-temperature stepping and camera-space visibility culling with audio/flag/UI transitions.

Methods: `0x004B3BA0`, `0x004B3DC0`


### VehicleTransformEmitter

Object that conditionally forwards six transform/position parameters to the shared scene transform setter sub_54B4D0 when the guard at this+0x64 is active.

Methods: `0x004A27D0`

- `this+0x0000004C` `DWORD transformParam0` (read, GUESS)
- `this+0x00000050` `DWORD transformParam1` (read, GUESS)
- `this+0x00000054` `DWORD transformParam2` (read, GUESS)
- `this+0x00000058` `FLOAT positionX` (read, GUESS)
- `this+0x0000005C` `FLOAT positionY` (read, GUESS)
- `this+0x00000060` `FLOAT positionZ` (read, GUESS)
- `this+0x00000064` `DWORD dispatchEnableFlag` (read, GUESS)

### VehicleMeshLoadHandler

Vehicle tire/wheel graphics mesh loading: audio-stream open for the tire sound handle, detail-level LOD scale selection from dword_7CF884, file-entry iteration, name resolution against the global instance table and per-entry mesh loader handoff.

Methods: `0x004A51C0`


### VehicleScalarSampler

Double-indirection sampler returning the DWORD vehicle scalar at vehicle+0xF8C through the vehicle pointer stored at this+0x0; consumed by telemetry, render, particle and weather per-frame paths.

Methods: `0x004B9E30`

- `this+0x00000000` `void* vehicleObjectPtr` (read, GUESS)
- `obj+0x00000F8C` `DWORD sampledScalar` (read, GUESS)

### ParticleCollisionEmitter

Collision-driven particle spawn: stores the collision source, computes a bounding-box midpoint and half-extent, seeds spread direction/magnitude from the flt_8AB274 noise table (byte-wrapped dword_8AAE70 index), counts elements above the collision height and fills a 20-byte-record filtered buffer at this+0x38.

Methods: `0x004C9FB0`

- `this+0x00000000` `void* collisionSourcePtr` (write, GUESS)
- `this+0x00000004` `FLOAT centerX` (read_write, GUESS)
- `this+0x00000008` `FLOAT centerY` (read_write, GUESS)
- `this+0x0000000C` `FLOAT centerZ` (read_write, GUESS)
- `this+0x00000010` `FLOAT halfExtentRadius` (write, GUESS)
- `this+0x00000018` `FLOAT particleScale` (write, GUESS)
- `this+0x0000001C` `FLOAT particleLifetime` (write, GUESS)
- `this+0x00000020` `FLOAT angularSpreadRate` (write, GUESS)
- `this+0x00000024` `FLOAT directionCosine` (write, GUESS)
- `this+0x00000028` `FLOAT directionSine` (write, GUESS)
- `this+0x0000002C` `FLOAT weightX` (write, GUESS)
- `this+0x00000030` `FLOAT weightY` (write, GUESS)
- `this+0x00000034` `DWORD countAboveCollisionHeight` (write, GUESS)
- `this+0x00000038` `void* filteredRecordBuffer` (write, GUESS)

### TireBrandDefinition

One tire-brand definition: front tire block at this+0x18 and rear block at this+0x160 with grip lat/long curves, geometry, suspension, camber, thermal/wear and AI-tuning doubles, plus averaged grip multipliers at this+8/this+0xC and a clamped wear rating at this+0x10.

Methods: `0x004D6B00`

- `this+0x00000008` `FLOAT dryGripAverageMultiplier` (write, GUESS)
- `this+0x0000000C` `FLOAT wetGripAverageMultiplier` (write, GUESS)
- `this+0x00000010` `DWORD wearRating` (write, GUESS)
- `this+0x00000014` `BYTE wetWeatherFlag` (write, GUESS)
- `this+0x00000018` `BYTE[0x148] frontTireBlock` (write, GUESS)
- `this+0x00000100` `DOUBLE frontSoftness` (write, GUESS)
- `this+0x00000160` `BYTE[0x148] rearTireBlock` (write, GUESS)
- `this+0x00000188` `DOUBLE rearRadiusRpm` (write, GUESS)
- `this+0x000001F8` `DOUBLE rearCamberLatLong` (write, GUESS)
- `this+0x00000248` `DOUBLE rearSoftness` (write, GUESS)

### VehicleDebugOverlayRenderer

Two-column HUD/debug text overlay for two entities: gear/position character, normalized name, indexed single-character entries and a '%6.3f' speed readout rendered with UITextRenderWithScale.

Methods: `0x004DA0D0`

- `this+0x00000014` `FLOAT speedValue` (read, GUESS)
- `this+0x00000018` `BYTE leftEntitySelectionFlag` (read, GUESS)
- `this+0x0000001C` `void* leftEntityPtr` (read, GUESS)
- `*(this+0x1C)+0x00004060` `DWORD entityGearOrPosition` (read, GUESS)
- `*(this+0x1C)+0x000046F8` `void* entityNamePtr` (read, GUESS)

### VehicleGeometryRecenteringHelper

Recenters two scene objects and all their packed vertices onto a computed bounding-box midpoint, clears per-child flags and rebuilds child bounding boxes.

Methods: `0x004E2AD0`


### WheelContactUpdater

Transforms the four wheel-contact corner vectors by a 3x3 rotation matrix, adds the world origin, queries and stores collision normals per corner and updates wheel-surface friction.

Methods: `0x004EF180`

- `this+0x00000704` `FLOAT rotationMatrixElement0` (read, GUESS)
- `this+0x00000708` `FLOAT rotationMatrixElement1` (read, GUESS)
- `this+0x0000070C` `FLOAT rotationMatrixElement2` (read, GUESS)
- `this+0x00000710` `FLOAT rotationMatrixElement3` (read, GUESS)
- `this+0x00000714` `FLOAT rotationMatrixElement4` (read, GUESS)
- `this+0x00000718` `FLOAT rotationMatrixElement5` (read, GUESS)
- `this+0x0000071C` `FLOAT rotationMatrixElement6` (read, GUESS)
- `this+0x00000720` `FLOAT rotationMatrixElement7` (read, GUESS)
- `this+0x00000724` `FLOAT rotationMatrixElement8` (read, GUESS)
- `this+0x00003668` `void*[4] contactNormalPtrArray` (write, GUESS)

### TireCompoundPhysicsApplier

Per-wheel tire-compound setup: resolves the compound by index/name, selects front or rear compound data, computes per-wheel force/spring/load/grip values in the 248-byte wheel slot at this+13840..13880, optionally runs the brush-model solver, and applies the compound through the physics application when no rigid body is attached.

Methods: `0x004F18C0`

- `this+0x000032BC` `DWORD rigidBodyConstraintGuard` (read, GUESS)
- `this+0x0000396C` `void* compoundTablePtr` (read, GUESS)
- `this+0x00003970` `DWORD compoundIndex` (write, GUESS)
- `this+0x00003BF4` `FLOAT loadScaleMultiplier` (read, GUESS)

## Compatibility contracts

- **VehicleFileRegistryContract** — A replacement executable must keep the global vehicle-file entry array dword_8AC394 (1060-byte stride, element fields read up to 0x424) with entry count dword_8AC390, current-index global dword_8AC38C, adjacent dword_8AC388, and the default-name string byte_5EA438; per-slot selection compares the field at byte offset 444.
- **ActiveVehicleGridContract** — The per-frame vehicle passes depend on the live vehicle pointer array dword_7C54F0 with count dword_5C329C, the camera/track object dword_7C54E0 (camera position at +13536/+13540/+13544), the session interface dword_5EA510 (flag at +112, Euler angles at +24) and the visible-vehicle bound dword_7CFC8C.
- **TireBrandDefinitionContract** — Tire-brand objects must carry a front tire block at this+0x18 and a rear tire block at this+0x160 with grip-curve doubles, a wet flag at this+0x14, averaged dry/wet grip multipliers at this+8/this+0xC and a wear rating clamped to [7,15] at this+0x10; the parser applies radius*RPM factor 9.549296585513721 and camber degrees-to-radians factor 0.0174532925199433.
- **TireCompoundWheelContract** — Per-wheel compound setup writes a 248-byte wheel slot at this+13840..13880, gated by the rigid-body guard this+0x32BC, reading the compound table at this+0x396C, the index at this+0x3970 and the load scale at this+0x3BF4; when no rigid body is attached it records the index in dword_7C8884 and applies via TireCompoundPerWheelPhysicsApplication on dbl_7C7428.
- **WheelContactContract** — The wheel-contact transform reads a 3x3 rotation matrix at this+0x704..0x724, a world-origin offset at this[443], feature data at dbl_7C9360 and writes the four-corner contact-normal pointer array at this+0x3668, updating wheel-surface friction per contact.
- **DetailLevelLodContract** — The tire/wheel mesh loader maps the global detail level dword_7CF884 (values 0..3) through jump table jpt_4A5216 (0x004A5314) to LOD scale factors 3.0/2.0/1.0/0.0, resolving entry names against the global instance table at dword_5CD620.
- **ParticleNoiseTableContract** — Particle collision emission samples the flt_8AB274 noise table using the byte-wrapped post-increment index dword_8AAE70 to seed scale/lifetime/angular-rate/direction fields, and fills a 20-byte-per-record filtered buffer at this+0x38.
- **VehicleDebugOverlayContract** — The vehicle debug overlay reads entity gear/position at *(entity+0x4060) and the entity name pointer at *(entity+0x46F8), renders '%c' (global aC at 0x005CCEF0) and '%6.3f' (global a63f at 0x005D4B40) literals in the default color flt_5ACF60, and appends indexed single-character entries from dword_5D4AF4 with base bytes byte_5D4AF0/byte_5D4AF1.

## Unresolved

- Class owners are all GUESS: every packet owner is UNKNOWN except VehicleSetupDriverNumber (0x004C7B50), which the packet labels F1CVehicle CONFIRMED; worker output is capped at GUESS, so F1CVehicle remains a GUESS class here.
- Equal offsets on distinct this pointers are not treated as identical fields: WheelContactUpdater (this+0x704..0x724), TireCompoundPhysicsApplier (this+0x32BC/0x396C/0x3970/0x3BF4) and F1CVehicle (this+0x4898..0x48A0) are kept as separate classes because the packet does not prove common ownership.
- The flt_59E4xx / flt_59E6xx / flt_59E7xx / flt_59E8xx / dbl_59E9xx / dbl_59EAxx / dbl_59EBxx / dbl_59ECxx / dbl_59EDxx / flt_5ACExx / dbl_5ADxxx globals listed by packet facts never appear as named operands in the raw decompiled bodies; they are carried in unresolved_evidence_refs, not located.
- sub_54B4D0's six parameters (3D position/transform semantics) and the this+0x64 guard type are DERIVED from existing analysis, not evidenced by this packet (0x004A27D0).
- TireWheelMeshLoadLoop argument roles a2/a3 and the v5 entry-handle value are unaccounted; locals v10..v14 are initialized but unused; sub_5651B0's zero-return gate may be negative logic; dword_7CF884 detail-level semantics (pitcrew vs car meshes) are not in the packet.
- dword_5C329C has no recorded writers in the packet; dword_7C54F0 length is unbounded; TireTemperatureSimStep's thermal model is not described (0x004B3BA0).
- VehicleVisibilityCulling's v30 byte-buffer layout (new/previous flags, distance slots) and the unnamed camera offsets +13536/+13540/+13544 and vehicle offsets +3384/+3388/+3392 are inferred from index arithmetic; flt_59E440/flt_59E660/flt_59E8C8 are absent from the raw source.
- The vehicle scalar at vehicle+0xF8C has no documented meaning; the owner type behind this+0x0 is unlabeled (0x004B9E30).
- VehicleArrayIndexAccessor's linked-list node layout is implied only by the raw walk; the 0x424 stride semantics of dword_8AC394 are DERIVED; a null node data pointer is dereferenced without a v6 guard (0x004BFCD0).
- ResetVehicleDataStruct's alternating 0/-1 sentinel pairs suggest {value,id} slots or a list-head pattern whose precise role is unresolved; the 'State_Struct_Multi_Field_Init' packet abi label is generic (0x004C3050).
- VehicleLookupByName's sub_588410 comparison semantics (case, partial/full), the 1060-byte entry layout beyond the name pointer, and the byte_5EA438 default-string role are unresolved (0x004C3F80).
- CurrentVehicleAccessor's 1060-byte element type is unconfirmed and distinct from the known 0x48C0 vehicle-struct stride (0x004C4080).
- VehicleDataLoader's selection-sort reading is grounded in the compare + conditional-swap pattern, but the composite key semantics and VehicleDataCopy's source/destination direction are not verified from this packet alone (0x004C4240).
- The node flag byte at +8 (initialized to 1), the sub_566810 comparison contract, the first-vs-head relationship at this+0x10/this+0x8, and the caller sub_4C4D50 (0x004C4D50) are unresolved for both VehicleFilteringSelection and VehicleGridSelection.
- VehicleNameEnumerationThenNationalityLoad reads dword_8AC38C without seeing its producer, and unk_8AC388 is flagged but absent from the raw source (0x004C7B20).
- The identity of the strings at this+17952/+18196/+18104 and the meaning of the 0x48A0 long-description index are unresolved (0x004C7B50).
- ParticleCollisionEmitter's noise-table length and byte-wrapped aliasing, the bounding-box axis correspondence, and the missing cos/sin/sqrt callees are unresolved; ten read-only flt/dbl globals are absent from the raw body.
- ParseTireBrandData token statuses 1 and 4 from sub_5651B0 and the front/rear block layout (DERIVED from raw offsets) are not independently evidenced; six double-constant globals are absent from the raw source.
- renderVehicleDebugOverlay: the this+0x18 flag's two data sources are not proven the same type, sub_589901's normalize transform is unknown, the byte_5D4AF0/byte_5D4AF1 bases and byte_5EA438 prefix are not evidenced in meaning, and the '%c'/'%6.3f'/color global ties are DERIVED.
- VehicleGeometryRecenteringHelper: the per-child flag bits, sub_54D080 semantics and whether the two objects are distinct or aliased are unresolved; global 0x0059E450 is absent from the raw body.
- WheelContactTransform: the dbl_7C9360 structure is unnamed, the four constant dwords (v12..v15) in the query payload are unexplained, the 0x704..0x724 frame naming is unverified, and global 0x0059E448 is absent from the raw body.
- TireCompoundSetupWheel: the 248-byte per-wheel slot layout and compound data element meanings (indices 0..34) are inferred only from consuming formulas; five read-only globals are absent from the raw body.
