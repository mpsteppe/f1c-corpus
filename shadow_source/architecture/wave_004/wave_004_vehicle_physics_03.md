# VehiclePhysicsSubsystem

Scope: `vehicle_physics`  
Trust: `DERIVED`

The vehicle_physics scope reconstructs 18 functions into a VehiclePhysicsSubsystem. CollisionObjectInsert manages four type-tagged collision sub-lists with free-list node reuse; BuildVehicleInstanceLists and SerializedStateExport maintain and serialize per-slot vehicle instance lists (104 slots, 18624-byte stride) and a range-sum section. A VehicleRegistry (basename lookup + random selection) and VehicleEntry deep-copy serve the vehicle configuration table. VehicleFrameUpdater runs the per-frame vehicle update (AI path, suspension, state machine, camera, climb adjust) and player-identity check via the global vehicle pointer table (dword_7C54F0 / dword_7C54E4). ParticleRenderObjectManager and WheelContactParticleSystem update wheel/particle render objects, friction, and contact particles gated by scoring time (dword_8AB6E4). OccupancyFlagBuilder reconciles a 52-entry flag array against live grid occupancy; LapStateWriter resolves and writes a lap/threshold value into a vehicle slot element. All roles are DERIVED/GUESS proposals; ownership is broadly UNKNOWN in the packet and several globals remain ungrounded.

## Function roles

- `0x004B48E0` **CollisionObjectManager** — Insert a collision object into one of four type-tagged sub-lists after guard/validation, reusing a free-list node or allocating a fresh 12-byte entry.
- `0x004B5C50` **VehicleInstanceListBuilder** — Iterate 104 per-slot vehicle entries and build/refresh per-slot tracked-instance lists with identity dedup and session-time stamping.
- `0x004B6A10` **SerializedStateExporter** — Serialize object/vehicle state into a conditional dispatch stream including 104 slot-list entries and a trailing range-sum section.
- `0x004B9820` **ForceFeedbackOwner** — Read the force/feedback dword at owner+0xF1C through the object handle at this+0.
- `0x004B9B80` **TimedAudioEventController** — Order and play a timed-audio event range, reset the audio ring buffer, scale endpoints into 40Hz buckets, and update vehicles on a bucket-boundary crossing.
- `0x004B9FB0` **VehicleDataTypeValidator** — Validate a vehicle-data accessor value in [6,8] when the type identifier is 2, else pass.
- `0x004C3FE0` **VehicleRegistry** — Look up a vehicle table entry by basename and cache the matched index (or 0) in dword_8AC38C.
- `0x004C45D0` **VehicleEntry** — Deep-copy vehicle configuration from a template entry into this entry (strings, identifier block, dwords, byte regions).
- `0x004C5070` **VehicleRegistry** — Select a random vehicle entry from a filtered candidate list using a 64-bit random state and bounds-checked indexing.
- `0x004C6B60` **VehicleFrameUpdater** — Per-frame vehicle update: substate reset, AI path tracking, suspension update, state-machine advance/clear, game-state branch, camera viewport/frustum, climb adjust.
- `0x004C7BD0` **VehicleFrameUpdater** — Return whether this vehicle is the player by comparing this+0x4894 with the current player vehicle's +18580 slot.
- `0x004CB860` **ParticleRenderObjectManager** — Per-frame update of wheel render objects: expiry, position interpolation, direction placement, visibility vs player/AI, color/texture flag writes.
- `0x004CCB30` **ParticleRenderObjectManager** — Per-frame particle physics: container init, lifetime selection, particle removal, velocity acceleration, AABB sliding collision, bounding-box render.
- `0x004CD6C0` **WheelContactParticleSystem** — Spawn a wheel contact particle slot (capacity gate, circular-buffer slot, lifetime seed, quad vertices, wet/smoke alpha variant).
- `0x004CE110` **WheelContactParticleSystem** — Compute wheel contact friction from the motion delta and spawn surface particles per contact slot with color/size packing.
- `0x004D1670` **OccupancyFlagBuilder** — Build a 52-entry vehicle occupancy bitmask from the live grid and reconcile a paired flag-field array against it.
- `0x004DAD30` **LapStateWriter** — Write this[9] (offset 0x24) into the caller-supplied destination at a2+16436 (0x4034).
- `0x004DAD50` **LapStateWriter** — Resolve an index from dword_8ACEE0 and apply the lap-state wrapper to the vehicle array element at 0x005EC6D8 + 18624*v2.

## Proposed classes

### CollisionObjectManager

Manages four type-tagged collision-object sub-lists (16-byte stride at this+0x70), a collision-node free list (dword_8AB700/dword_8AB708), and validated insertion of collision payloads.

Methods: `0x004B48E0`

- `this+0x00000000` `byte Enabled` (read, DERIVED)
- `this+0x00000070` `CollisionSubList[4] TypeSubLists` (read_write, GUESS)

### VehicleInstanceListBuilder

Builds per-slot lists of tracked vehicle instances, deduplicating by identity string, stamping session time onto new instances, and reusing entry nodes from a free list.

Methods: `0x004B5C50`

- `this+0x00000010` `void* EntryFreeListHead` (read, DERIVED)
- `this+0x00000018` `void* EntryTempPointer` (write, DERIVED)
- `this+0x00000044` `void* SlotListHead` (read_write, DERIVED)
- `this+0x00000048` `void* SlotListTail` (read_write, DERIVED)
- `this+0x0000004C` `int SlotListCount` (read_write, DERIVED)

### SerializedStateExporter

Serializes object/vehicle state into a conditional dispatch stream: headers, two path strings, two byte flags, expected count, 104 slot-list entry streams, a byte flag, a linked list, then a range-sum (count, sum, span) section.

Methods: `0x004B6A10`

- `this+0x00000048` `void* SlotListAnchor` (read, DERIVED)
- `this+0x000006C0` `void* LinkedHead` (read, DERIVED)
- `this+0x000006C8` `void* LinkedCurrent` (read_write, DERIVED)
- `this+0x000006CC` `byte LinkedFlag` (read, DERIVED)
- `this+0x00000714` `void* RangeListHead` (read, DERIVED)
- `this+0x0000071C` `void* RangeListCurrent` (read_write, DERIVED)
- `this+0x00000724` `char* PathA` (read, DERIVED)
- `this+0x0000072C` `char* PathB` (read, DERIVED)
- `this+0x00000F1C` `byte FlagF1C` (read, DERIVED)
- `this+0x00000F20` `byte FlagF20` (read, DERIVED)

### ForceFeedbackOwner

Read-only accessor into an owning object that carries a force/feedback dword at +0xF1C.

Methods: `0x004B9820`

- `this+0x00000000` `void* OwnerHandle` (read, DERIVED)
- `obj+0x00000F1C` `dword ForceFeedbackValue` (read, GUESS)

### TimedAudioEventController

Orders a timed-audio event range into ascending endpoints, plays events, resets the audio ring buffer, re-scales endpoints into 40Hz buckets, and updates all vehicles when a bucket boundary is crossed.

Methods: `0x004B9B80`

- `this+0x00000000` `void* OwnerHandle` (read, DERIVED)
- `obj+0x00000F3C` `float AudioRangeStart` (read, GUESS)

### VehicleDataTypeValidator

Validates a vehicle-data value: when the type identifier is 2, fails unless the VehicleDataAccessor value lies in [6, 8].

Methods: `0x004B9FB0`

- `this+0x00000000` `int TypeIdentifier` (read, DERIVED)

### VehicleRegistry

Vehicle registry table access: basename lookup with matched-index cache and random selection from a filtered candidate list over the global table.

Methods: `0x004C3FE0`, `0x004C5070`


### VehicleEntry

Destination vehicle configuration entry filled by a deep template-to-entry copy (seven null-safe strings, identifier block, 15 dwords, byte-block regions, two trailing dwords).

Methods: `0x004C45D0`

- `this+0x00000028` `byte[16] IdentifierBlock` (write, GUESS)
- `this+0x00000038` `dword ParameterDword0` (write, GUESS)
- `this+0x0000003C` `dword ParameterDword1` (write, GUESS)
- `this+0x00000040` `dword ParameterDword2` (write, GUESS)
- `this+0x00000044` `dword ParameterDword3` (write, GUESS)
- `this+0x00000048` `dword ParameterDword4` (write, GUESS)
- `this+0x0000004C` `dword ParameterDword5` (write, GUESS)
- `this+0x00000050` `dword ParameterDword6` (write, GUESS)
- `this+0x00000054` `dword ParameterDword7` (write, GUESS)
- `this+0x00000058` `dword ParameterDword8` (write, GUESS)
- `this+0x0000005C` `dword ParameterDword9` (write, GUESS)
- `this+0x00000060` `dword ParameterDword10` (write, GUESS)
- `this+0x00000064` `dword ParameterDword11` (write, GUESS)
- `this+0x00000068` `dword ParameterDword12` (write, GUESS)
- `this+0x0000006C` `dword ParameterDword13` (write, GUESS)
- `this+0x00000070` `dword ParameterDword14` (write, GUESS)
- `this+0x00000074` `byte[8] CopyRegion_74` (write, GUESS)
- `this+0x0000007C` `byte[64] CopyRegion_7C` (write, GUESS)
- `this+0x000000BC` `byte[64] CopyRegion_BC` (write, GUESS)
- `this+0x000000FC` `byte[64] CopyRegion_FC` (write, GUESS)
- `this+0x0000013C` `byte[64] CopyRegion_13C` (write, GUESS)
- `this+0x0000017C` `byte[64] CopyRegion_17C` (write, GUESS)
- `this+0x000001BC` `byte[256] CopyRegion_1BC` (write, GUESS)
- `this+0x000002BC` `byte[128] CopyRegion_2BC` (write, GUESS)
- `this+0x0000033C` `byte[16] CopyRegion_33C` (write, GUESS)
- `this+0x0000034C` `byte[64] CopyRegion_34C` (write, GUESS)
- `this+0x0000038C` `byte[16] CopyRegion_38C` (write, GUESS)
- `this+0x0000039C` `byte[16] CopyRegion_39C` (write, GUESS)
- `this+0x000003AC` `byte[16] CopyRegion_3AC` (write, GUESS)
- `this+0x000003BC` `byte[16] CopyRegion_3BC` (write, GUESS)
- `this+0x000003E0` `byte[64] CopyRegion_3E0` (write, GUESS)
- `this+0x000003D4` `dword TrailingDword3D4` (write, GUESS)
- `this+0x00000420` `dword TrailingDword420` (write, GUESS)

### VehicleFrameUpdater

Per-frame vehicle update (substate reset, AI path tracking, suspension, state-machine advance/clear, game-state branch, camera viewport/frustum, climb adjust) and player-vehicle identity comparison.

Methods: `0x004C6B60`, `0x004C7BD0`

- `this+0x00004894` `dword GridSlotIndex` (read, DERIVED)

### ParticleRenderObjectManager

Per-frame update of wheel render objects and particle effects: expiry, position interpolation, visibility/occlusion vs player or AI drivers, acceleration, AABB sliding collision, and color/texture flag writes.

Methods: `0x004CB860`, `0x004CCB30`

- `this+0x0000000C` `float WorldPositionX` (read, GUESS)
- `this+0x00000010` `float WorldPositionY` (read, GUESS)
- `this+0x00000014` `float WorldPositionZ` (read, GUESS)
- `this+0x00000018` `float DirectionX` (read, GUESS)
- `this+0x0000001C` `float DirectionY` (read, GUESS)
- `this+0x00000020` `float DirectionZ` (read, GUESS)
- `this+0x00000024` `float DirectionScaleX` (read, GUESS)
- `this+0x00000028` `float DirectionScaleY` (read, GUESS)
- `this+0x0000002C` `float DirectionScaleZ` (read, GUESS)
- `this+0x00000040` `float FrameTimeFactor` (read, DERIVED)
- `this+0x00000064` `int ObjectCount` (read, DERIVED)
- `this+0x00000068` `void** ObjectPointerArray` (read, DERIVED)

### WheelContactParticleSystem

Computes wheel contact friction from motion deltas and spawns surface particles (tire spray/smoke/dust) with per-surface color/size packing and alpha scaling.

Methods: `0x004CD6C0`, `0x004CE110`

- `this+0x00000004` `int SurfaceType` (read, DERIVED)
- `this+0x00000030` `float EmissionDuration` (read, GUESS)
- `this+0x00000040` `float AlphaScaling` (read, GUESS)
- `this+0x00000058` `int RemainingCapacity` (read, DERIVED)
- `this+0x0000003C` `int ContactSlotCount` (read, DERIVED)
- `this+0x00000040` `void** ContactSlotArray` (read, DERIVED)
- `*(this+0x40)+0x00000004` `int SlotSurfaceType` (read, GUESS)

### OccupancyFlagBuilder

Builds a 52-entry vehicle-type occupancy bitmask from the live grid and reconciles a 52-entry paired flag-field array against it.

Methods: `0x004D1670`

- `this+0x00000280` `FlagField[52] PairedFlagArray` (read_write, GUESS)

### LapStateWriter

Writes a lap/threshold value into a resolved vehicle-slot array element (18624-byte stride at 0x005EC6D8) via an index-resolver then a field store.

Methods: `0x004DAD30`, `0x004DAD50`

- `this+0x00000024` `int LapThresholdValue` (read, GUESS)

### SinglyLinkedNode

Generic singly-linked list node used by vehicle instance lists, serialization lists, and range-filtered lists: value pointer at +0, next at +4, optional 16-bit payload at +8.

Methods: 

- `*(this+0x44)+0x00000000` `void* NodeValue` (read_write, DERIVED)
- `*(this+0x44)+0x00000004` `void* Next` (read, DERIVED)
- `*(*(this+0x714)+0x0)+0x00000008` `uint16 Value16` (read, GUESS)

### TrackedVehicleInstance

Per-vehicle tracked instance entry with identity string and session-time stamp fields written during list building.

Methods: 

- `*(*(this+0x44)+0x0)+0x00000088` `float SessionTimeStamp` (write, GUESS)
- `*(this+0x10)+0x00000084` `float EntryTimeStamp` (write, GUESS)

## Compatibility contracts

- **VehicleSlotArrayLayout** — 104 per-slot vehicle entries each 18624 (0x48C0) bytes apart with array base 0x005EC6D8; per-slot instance lists are anchored at manager+0x44 and rebuilt by BuildVehicleInstanceLists.
- **ActiveVehiclePointerTable** — Global active-vehicle pointer array dword_7C54F0, current-vehicle index dword_7C54E4, vehicle count dword_5C329C, player proximity via dword_7C54E0/dword_7C54DC; slot identity compared at vehicle+0x4894.
- **VehicleRegistryTableLayout** — Vehicle registry: entry count dword_8AC390, base dword_8AC394, 1060-byte per-entry stride, matched-index cache dword_8AC38C; entries looked up by basename and randomly selected.
- **SerializedStateDispatchOrder** — SerializedStateExport writes: header dword off_5D2434, header float flt_5D2438, two path strings (null-fallback byte_5EA438), two byte flags, expected count, 104 slot-list entry streams, a byte flag, a linked list, then a range-sum (count, sum, span); success requires expected == serialized count.
- **CollisionSubListInsertionSemantics** — Collision objects insert into one of four type-tagged sub-lists (this+0x70, 16-byte stride) with node reuse from free lists dword_8AB700/dword_8AB708; 3-bit tag from header >> 29 mapped through the jump table at 0x004B4A10; returns 0 on disabled, validation-failure, or allocation failure.
- **WheelContactParticlePacking** — Wheel contact surface types gate color/size packing ((value << 24) + 0xFFFFFF) and particle spawning (WheelContactParticleSpawn quad vertices via 0x00558E10); surface type 8 selects the wet/smoke alpha variant, 6 the grass/dirt path.
- **PlayerVehicleIdentityComparison** — A vehicle is the player when its +0x4894 grid-slot equals the current player vehicle's +18580 slot dword (resolved via dword_7C54F0[dword_7C54E4]); relied on by AI damage, proximity-team recognition, and suspension force computation.

## Unresolved

- CollisionObjectInsert: the fifth/sixth argument semantics of the finalize call (ArithmeticComparison_47a0, 0x004B47A0) are uncertain because v8 (prior tail) is stale on the empty-list path; the a2 header/tag structure and the meaning of type tags 1..6 are not established.
- BuildVehicleInstanceLists: flt_5ACD10's proposed EntityActiveDefault role is unconfirmed; the 0x84 field (driver-name vs timestamp) is DERIVED, not proven; a concrete owning class is unknown.
- SerializedStateExport: the canonical name conflicts with the observed serialization behavior; the per-slot serializer sub_4B4FB0 and count producer sub_4B5E30 semantics are not visible here; the header values off_5D2434/flt_5D2438 are unconfirmed as version/format markers.
- WheelForceAccessor: the object type reached through this+0 and the meaning of the 0xF1C value are not evidenced beyond the single read; there is no null check on the dereferenced pointer.
- TimedAudioWithVehicleUpdateDispatch: purpose and argument semantics of the sub_5895A2 sync calls, the meaning of the +12 vehicle-pointer offset passed to sub_4EE2D0, and the a2 semantics for MultiObjectRemove (0x004E3A50) are unknown.
- VehicleTypeRangeValidator: the meaning of type identifier 2 and of the accessor value range [6, 8] are caller-domain; the VehicleDataAccessor contract and what this+2 indexes are unresolved.
- VehicleNameEnumeration: the string-table stride (1060 bytes) and entry layout at dword_8AC394 are not evidenced; sub_596C80's exact comparison semantics are unproven; the structural twin 0x004C3F80 is not independently verified.
- VehicleDataCopy: the semantic content of each byte-block region is not established from this packet; StringCopyWithBufferRealloc's exact signature/destination is not visible inside the function.
- RandomVehicleSelector: the register-return contract of BoundsCheckedIndexSetter_6760 (index/list-pointer) is inferred; the 64-bit random state layout and the low/high range check are unconfirmed.
- VehicleFrameUpdate: dword_8ACEE0 is listed as read but absent from the raw pseudocode (corpus labels it the force-feedback base); the this+3 and this+3251 substruct contents are undescribed; dword_7C56A4==7 and dword_7C56A8 3/4 are undefined; the 12-byte v9/v8 scratch layout is unknown.
- IsPlayerVehicle: the player-side +18580 comparison field has no dedicated evidence ref; the grid-vs-starting-slot equality interpretation is DERIVED.
- WheelRenderObjectPerFrameUpdate: flt_59E43C and flt_59E450 are ungrounded; the owner class of a1 is unknown; sub_5881F0's operation is unanalyzed.
- ParticleEffectPhysics: flt_59E46C and flt_59ED18 are ungrounded; the per-element particle layout is reachable only by relative byte offsets.
- WheelContactParticleSpawn: flt_59E43C/flt_59E440/flt_5ACEBC/flt_5ACEC0 are ungrounded; slot element indices (2/3/24/25) are DERIVED; the a3/a4 corner layout is inferred.
- WheelSurfaceContactFriction: the surface-type enum values (6/8) are labeled by prior analysis, not proven here; the (value << 24) + 0xFFFFFF color packing is used verbatim with unverified channel semantics; flt_59E43C/flt_59E920/flt_5ACEBC/flt_5ACEC4/flt_5ACEC8 cannot be grounded here; FAIL_4ce110 carries no semantic signal.
- VehicleOccupiedFlagBuilder: the field semantics of the 52 paired flag fields live in the consumer; the occupancy-bit to slot mapping is caller-visible; the four FlagFieldBitManipulation arguments are passed through verbatim.
- writeLapCountToVehicle: the destination structure at a2+16436 (0x4034) is caller-supplied; sub_4BC270's contract is inferred; the this[9] lap/threshold meaning is DERIVED.
- ApplyToResolvedVehicle: sub_4D1B50's contract (what dword_8ACEE0 holds and what v2 selects) is not visible; SingleFunctionCallWrapper_ad30's action on the resolved element is not visible.
- The floating-point globals 0x0059E43C/0x0059E440/0x0059E450/0x0059E46C/0x0059E86C/0x0059E920/0x0059ED18/0x005ACD04/0x005ACD10/0x005ACEBC/0x005ACEC0/0x005ACEC4/0x005ACEC8 and 0x008AB6F0 are attributed by static facts but absent from the raw source of their functions; roles are ungrounded.
- The obj-deref bases in WheelForceAccessor (obj+0xF1C) and TimedAudioWithVehicleUpdateDispatch (obj+0xF3C) may be the same vehicle/force owner struct, but the packet does not prove common ownership.
