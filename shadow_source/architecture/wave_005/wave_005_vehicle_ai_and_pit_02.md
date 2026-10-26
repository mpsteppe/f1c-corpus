# VehicleAIAndPit

Scope: `vehicle_ai_and_pit`  
Trust: `DERIVED`

DERIVED architecture proposal for wave_005_vehicle_ai_and_pit_02 covering 27 validated function IR entries. Core vehicle AI/pit responsibilities: AIBehaviorInitialization (0x004BF0A0) sets up per-session timing and assigns randomized per-vehicle speed/top-speed biases over the active grid, then re-sorts AI drivers; TireLoadFactorSetter, TireContactForceComputation, WheelTireForceUpdate and the tire-name/slip-curve lookups implement the per-wheel tire physics and configuration; TireWearPropertyStore maintains the 45-entry tire-wear/grip tables. Supporting helpers in the packet (particle spawner, linked lists, socket init, audio, bit array) are grouped conservatively; several scope-external functions and all read-only constant globals are left unresolved rather than forced into the design.

## Function roles

- `0x004BF0A0` **AISessionTiming** — AISessionTiming::initialize - per-session AI performance timing setup: stores session-time base and identifier, wires vehicle behavior parameters, sets animation state, assigns randomized per-vehicle speed/top-speed biases over the active grid and re-sorts AI drivers.
- `0x004CBC50` **TrailParticleSpawner** — TrailParticleSpawner::spawnTrailParticle - allocates a circular-buffer particle slot and initializes it from collision data (position, velocity, noise-scaled magnitude, collision normal).
- `0x004D5EE0` **TireLoadFactorRecord** — TireLoadFactorRecord::setLoadFactors - writes the four tire-load-factor doubles: average, half-difference, incoming load and its reciprocal; gated debug log on non-positive load.
- `0x004D75D0` **TireSlipCurveTable** — TireSlipCurveTable::lookupByName - searches a 24-byte-stride tire slip-curve name table for a matching entry name; returns the entry address or 0.
- `0x004E3AA0` **TireContactSolver** — TireContactSolver::computeContactForce - per-tire contact force computation: collision normal query, penetration depth, spring/damper normal force, slip velocity projection and saturation, writes tire force terms.
- `0x004ED810` **TireThermalState** — WheelTireForceUpdate - per-frame tire temperature thermal update: two temperature integrations blended to ambient, then four-corner normalization into [0,1] through the wheel-base pointer.
- `0x004F1630` **TireSlipCurveTable** — TireSlipCurveTable::resolveTireName - resolves a tire name string from a compound index pair via CompoundIndexLookup; falls back to the default path string on lookup failure.
- `0x004F1C20` **AIReplayStatePredicate** — AIReplayStatePredicate::isActive - boolean predicate: TRUE only when the per-vehicle AI/replay state pointer is non-null and its active flag equals 1.
- `0x004F6B00` **TireWearPropertyStore** — TireWearPropertyStore::cleanupTable - teardown helper walking a fixed 45-entry, 20-byte-stride heap-pointer table, freeing each non-null entry; returns the last processed pointer.
- `0x004F6B40` **TireWearPropertyStore** — TireWearPropertyStore::initGripDataArray - initializes a 45-entry array of 5-dword tire-grip records with sentinel values, calling StringCopyWithBufferRealloc per record.
- `0x004F6B90` **TireWearPropertyStore** — TireWearPropertyStore::cleanupTableB - structural twin of 0x004F6B00: frees a second 45-entry, 20-byte-stride heap-pointer table; returns the last processed pointer.
- `0x004F7440` **TireWearPropertyStore** — TireWearPropertyStore::initSlot - initializes a tire-slot struct: seeds default path string, marks slot identifiers -1, clears active flag, returns -1.
- `0x004FAD80` **PhysicsDefaultsInitializer** — PhysicsDefaultsInitializer::initDefaults - constructor/initializer: zeroes 43 dword fields, sets gravity (-9.81), unity scalar (1.0) and four -1 sentinels; returns this.
- `0x00512093` **ObjectCleanupChain** — ObjectCleanupChain::cleanupThree - guarded three-object teardown: partially resets the first object via LargeStructPartialReset, delegates each non-null object and zeroes its slot.
- `0x005199C5` **SpriteFrameController** — SpriteFrameController::resetAndSelectFrame - resets the animation index dword to zero, then chains to the SpriteFrameSelector helper and returns its result.
- `0x0051CC8E` **WheelGeometryTableStore** — WheelGeometryTableStore::initGeometryTables - allocates four 1024-dword lookup tables via vtable-slot-0 dispatch and fills them with four arithmetic progressions.
- `0x005419D0` **LinkedListTailInsert** — LinkedListTailInsert::insertTail - unlinks node a2 from its list and appends it at this list's tail, rebinding a2's owner to this.
- `0x00542540` **PointerPairStore** — PointerPairStore::storePair - trivial setter storing two pointer arguments at this+0x1A4 and this+0x1A8, returning the first.
- `0x00545030` **DoublyLinkedListTailInsertion** — DoublyLinkedListTailInsertion::insertTail - inserts node a2 at the tail of a doubly linked list rooted at this[62], promoting a2 to head on the empty-list path.
- `0x00556700` **TimerSlotArray** — TimerSlotArray::boundsCheckAndReset - index bounds check against dword_8B8E48 + 32; in-range returns HighResolutionTimerReset on the 19-dword-stride slot array, otherwise the sentinel.
- `0x0055D4F0` **TextureCoordinatePropertyGroup** — TextureCoordinatePropertyGroup::setAndUpdate - stores three texture-coordinate parameters, calls DirectXVertexBufferTextureCoordinateSetup, sets the dirty bit 0x800 on the shared state dword.
- `0x00563020` **NetworkSocketManager** — NetworkSocketManager::initialize - multi-stage network-socket initialisation chain with error propagation and a conditional polling loop.
- `0x005649D0` **AIChainCallWrapper** — AIChainCallWrapper::dispatch - fastcall wrapper: dispatches an indirect function pointer, discards its result, returns AlignedMemoryCopyFromStructBuffer(a1, a2, a3).
- `0x0057B910` **NetworkSocketManager** — NetworkSocketManager::initSockAddrPair - initializes two AF_INET socket address structures (family 2, htons(0), htonl(0)) in network byte order.
- `0x00583360` **LinkedListDestructorChain** — LinkedListDestructorChain::destroy - destroys a linked list rooted at this+0x0: optional data-block callback under SEH, frees nodes/blocks, zeroes the four list dwords.
- `0x005840C6` **AudioGainControl** — AudioGainControl::incrementGain - increments a single byte field by a signed char, then calls MutexWaitWith1msTimeoutRelease and returns its result.
- `0x00595207` **BitArray** — BitArray::incrementCarryPropagate - increments a bit position in a 32-bit-word array with overflow carry propagation across preceding words.

## Proposed classes

### AISessionTiming

Per-session AI performance timing: holds the session-time base, caller-supplied session identifier, processed-count threshold and vehicle-behavior parameter pointer used when assigning randomized per-vehicle speed and top-speed biases over the active grid and re-sorting AI drivers.

Methods: `0x004BF0A0`

- `this+0x0000034C` `float speedBiasBase` (read_write, DERIVED)
- `this+0x00000354` `double sessionTimeBase` (read_write, DERIVED)
- `this+0x00000358` `int sessionIdentifier` (write, DERIVED)
- `this+0x0000035C` `int processedCountThreshold` (read, DERIVED)
- `this+0x00000360` `pointer vehicleBehaviorParams` (read, DERIVED)

### TrailParticleSpawner

Circular-buffer particle spawner: allocates a particle slot, seeds it from collision data (position, velocity, noise-scaled magnitude, collision normal) and sets texture-layer / array-element flags with bounds-checked array writes.

Methods: `0x004CBC50`

- `this+0x0000000C` `int textureLayerLow` (read, DERIVED)
- `this+0x00000010` `int textureLayerHigh` (read, DERIVED)
- `this+0x00000014` `int textureLayerStep` (read, DERIVED)
- `this+0x0000001C` `float surfaceOffsetFactor` (read, DERIVED)
- `this+0x00000058` `int bufferCapacity` (read, DERIVED)

### TireLoadFactorRecord

Per-wheel tire-load factor record: four consecutive doubles written each frame - average of two load inputs, half-difference, the incoming load and its reciprocal.

Methods: `0x004D5EE0`

- `this+0x00000000` `double loadAverage` (write, DERIVED)
- `this+0x00000008` `double loadHalfDifference` (write, DERIVED)
- `this+0x00000010` `double loadValue` (write, DERIVED)
- `this+0x00000018` `double loadReciprocal` (write, DERIVED)

### TireSlipCurveTable

Tire configuration name table: looks up a slip-curve name entry (24-byte stride) by name, and resolves a tire name from a compound index pair with a default-path fallback.

Methods: `0x004D75D0`, `0x004F1630`

- `this+0x00000008` `int entryCount` (read, DERIVED)
- `this+0x0000000C` `pointer entryArray` (read, DERIVED)
- `this+0x0000396C` `pointer tireNameIndexBase` (read, GUESS)
- `this+0x00003970` `int tireNameIndexSelector` (read, GUESS)

### TireContactSolver

Per-tire ground-contact force computation: queries the track-surface collision normal, computes penetration depth and spring/damper normal force, projects slip velocity onto the surface and lateral bases with a saturation guard, and writes the resulting force terms into the tire contact state.

Methods: `0x004E3AA0`

- `this+0x00000000` `float contactPositionX` (read, DERIVED)
- `this+0x00000004` `float contactPositionY` (read, DERIVED)
- `this+0x00000008` `float contactPositionZ` (read, DERIVED)
- `this+0x0000000C` `float slipComponentA` (read, DERIVED)
- `this+0x00000014` `float slipComponentB` (read, DERIVED)
- `this+0x00000018` `float lateralBasisX` (read, DERIVED)
- `this+0x0000001C` `float lateralBasisY` (read, DERIVED)
- `this+0x00000020` `float lateralBasisZ` (read, DERIVED)
- `this+0x00000034` `float normalForce` (read_write, DERIVED)
- `this+0x00000038` `float surfaceSlipX` (read_write, DERIVED)
- `this+0x0000003C` `float surfaceSlipY` (read_write, DERIVED)
- `this+0x00000040` `float surfaceSlipZ` (read_write, DERIVED)
- `this+0x00000044` `float tireForce` (read_write, DERIVED)
- `this+0x00000060` `float steepSlipYOffset` (read, DERIVED)
- `this+0x00000074` `float penetrationDepth` (read_write, DERIVED)
- `this+0x00000078` `float springStiffness` (read, DERIVED)
- `this+0x0000007C` `float slipSaturation` (read, DERIVED)
- `this+0x00000090` `float hubHeight` (read, DERIVED)
- `this+0x000000CC` `float slipDisplacementX` (write, DERIVED)
- `this+0x000000D0` `float slipDisplacementY` (write, DERIVED)
- `this+0x000000D4` `float slipDisplacementZ` (write, DERIVED)
- `this+0x000000E4` `float groundOffset` (read, DERIVED)
- `this+0x000000E8` `pointer collisionFeaturePtr` (read_write, DERIVED)
- `this+0x000000EC` `float frictionLoadTerm` (read, DERIVED)
- `this+0x000000F0` `float slipForceCoeff` (read, DERIVED)

### TireThermalState

Per-frame tire temperature model: two thermal integrations from absolute slip inputs and friction/convection coefficients blended toward an ambient reference, then four-corner temperature normalization into [0,1] stored through the wheel-base pointer.

Methods: `0x004ED810`

- `this+0x000008CC` `pointer wheelBasePtr` (read, DERIVED)
- `this+0x00003500` `float absSlipMagnitude` (read, DERIVED)
- `this+0x000035B0` `float slipA` (read, DERIVED)
- `this+0x000035D8` `float slipCoefA` (read, DERIVED)
- `this+0x000035DC` `float tempA` (read_write, DERIVED)
- `this+0x000036A8` `float slipB` (read, DERIVED)
- `this+0x000036D0` `float slipCoefB` (read, DERIVED)
- `this+0x000036D4` `float tempB` (read_write, DERIVED)
- `this+0x000037A0` `float slipC` (read, DERIVED)
- `this+0x000037C8` `float slipCoefC` (read, DERIVED)
- `this+0x000037CC` `float tempC` (read_write, DERIVED)
- `this+0x00003898` `float slipD` (read, DERIVED)
- `this+0x000038C0` `float slipCoefD` (read, DERIVED)
- `this+0x000038C4` `float tempD` (read_write, DERIVED)
- `this+0x00003A38` `float modelCoefA1` (read, DERIVED)
- `this+0x00003A3C` `float modelCoefA2` (read, DERIVED)
- `this+0x00003A40` `float modelCoefA3` (read, DERIVED)
- `this+0x00003A4C` `float modelCoefB1` (read, DERIVED)
- `this+0x00003A50` `float modelCoefB2` (read, DERIVED)
- `this+0x00003A54` `float modelCoefB3` (read, DERIVED)

### AIReplayStatePredicate

Boolean predicate over the per-vehicle AI/replay state object: returns TRUE only when the state pointer at this+0x3A9C is non-null and the dword at byte offset 300 of that object equals 1; gates overtaking logic.

Methods: `0x004F1C20`

- `this+0x00003A9C` `pointer aiReplayStatePtr` (read, DERIVED)
- `this+0x00003BC8` `int aiReplayActiveFlag` (read, GUESS)

### TireWearPropertyStore

Tire-wear / grip property tables: initializes the 45-entry 5-dword grip-data array and tire slot structs, and tears down the two 45-entry, 20-byte-stride heap-pointer tables.

Methods: `0x004F6B00`, `0x004F6B40`, `0x004F6B90`, `0x004F7440`


### PhysicsDefaultsInitializer

Constructor/initializer of an AI/physics-side object: zeroes 43 dword fields, sets the gravity constant (-9.81), a unity scalar (1.0) and four -1 sentinels; returns this unchanged.

Methods: `0x004FAD80`

- `this+0x0000007C` `float gravityY` (write, DERIVED)
- `this+0x00000084` `float unityScalar` (write, DERIVED)
- `this+0x00000120` `int sentinelSlot0` (write, DERIVED)
- `this+0x00000124` `int sentinelSlot1` (write, DERIVED)
- `this+0x00000128` `int sentinelSlot2` (write, DERIVED)
- `this+0x0000012C` `int sentinelSlot3` (write, DERIVED)

### ObjectCleanupChain

Guarded three-object teardown helper: reads up to three pointer slots, partially resets the first object via LargeStructPartialReset, then delegates each non-null object through GuardedDelegate and zeroes the corresponding slot.

Methods: `0x00512093`


### SpriteFrameController

Sprite/animation frame controller: resets the animation index field, then chains to the frame selector helper.

Methods: `0x005199C5`

- `this+0x00000080` `int animationIndex` (write, DERIVED)

### WheelGeometryTableStore

Wheel data sub-struct initializer: allocates four 1024-dword lookup tables through vtable-slot-0 dispatch into the sub-struct at this+0x19C and fills them with arithmetic progressions.

Methods: `0x0051CC8E`

- `this+0x00000004` `pointer vtablePtr` (read, GUESS)
- `this+0x0000019C` `pointer wheelDataSubStruct` (read, DERIVED)
- `*(this+0x19C)+0x00000010` `pointer lookupTable0` (write, DERIVED)
- `*(this+0x19C)+0x00000014` `pointer lookupTable1` (write, DERIVED)
- `*(this+0x19C)+0x00000018` `pointer lookupTable2` (write, DERIVED)
- `*(this+0x19C)+0x0000001C` `pointer lookupTable3` (write, DERIVED)

### LinkedListTailInsert

Doubly-linked-list tail insertion helper: unlinks a node from its current list and appends it at this list's tail, updating the global list tail and rebinding the node's owner.

Methods: `0x005419D0`

- `this+0x000001B0` `pointer listHead` (read, DERIVED)

### PointerPairStore

Trivial setter used by AI/graphics dispatch callers to record a pair of pointer values on the receiver.

Methods: `0x00542540`

- `this+0x000001A4` `pointer pointerSlot0` (write, GUESS)
- `this+0x000001A8` `pointer pointerSlot1` (write, GUESS)

### DoublyLinkedListTailInsertion

Doubly-linked-list tail insertion: walks next pointers from this[172] to the tail and links the node in, promoting it to head when the list rooted at this[62] is empty.

Methods: `0x00545030`

- `this+0x000000F8` `pointer listHead` (read_write, DERIVED)
- `this+0x000002B0` `pointer traversalCursor` (read, GUESS)

### TimerSlotArray

Index bounds check for a fixed-size slot array: computes the upper sentinel from dword_8B8E48 and addresses a 19-dword-stride slot in dword_8B6C28, resetting its high-resolution timer when in range.

Methods: `0x00556700`


### TextureCoordinatePropertyGroup

UI/graphics property group: stores three texture-coordinate parameters, wires the DirectX vertex-buffer texture-coordinate setup, and sets the shared dirty flag bit.

Methods: `0x0055D4F0`

- `this+0x00000004` `pointer vertexBufferHandle` (read, GUESS)
- `this+0x00000038` `int param0` (write, DERIVED)
- `this+0x0000003C` `int param1` (write, DERIVED)
- `this+0x00000040` `int param2` (write, DERIVED)

### NetworkSocketManager

Network-socket manager: multi-stage initialisation chain with error propagation over the socket array, a UDP broadcast socket and a follow-up setup stage, plus the socket-address (sockaddr) initialization for two AF_INET endpoints.

Methods: `0x00563020`, `0x0057B910`

- `this+0x00000000` `word sockAddrAFamily0` (write, DERIVED)
- `this+0x00000002` `word sockAddrPort0` (write, DERIVED)
- `this+0x00000004` `dword sockAddrIP0` (write, DERIVED)
- `this+0x00000010` `word sockAddrAFamily1` (write, DERIVED)
- `this+0x00000012` `word sockAddrPort1` (write, DERIVED)
- `this+0x00000014` `dword sockAddrIP1` (write, DERIVED)

### AIChainCallWrapper

Fastcall dispatch wrapper on the AI subsystem path: dispatches an indirect function pointer (result discarded) then returns the aligned memory-copy helper result.

Methods: `0x005649D0`


### LinkedListDestructorChain

Linked-list destructor: walks the node chain, optionally processes each node's data block via an SEH-guarded callback loop, frees all blocks/nodes, zeroes the four list fields and returns 0.

Methods: `0x00583360`

- `this+0x00000000` `pointer listHead` (read_write, DERIVED)
- `this+0x00000004` `pointer listNext` (read, GUESS)
- `this+0x00000008` `dword listFlags` (read_write, GUESS)
- `this+0x0000000C` `pointer listTail` (read_write, GUESS)

### AudioGainControl

Audio gain/volume accumulator: increments a single byte field by a signed char and follows with a mutex wait-with-timeout. Volume reading is inferred from the legacy ABI label only.

Methods: `0x005840C6`


### BitArray

Big bit-array word update: adds a single-bit mask into the addressed 32-bit word and propagates the carry across preceding words while the overflow-checked addition reports overflow.

Methods: `0x00595207`


## Compatibility contracts

- **TireLoadFactorRecordLayout** — The per-wheel tire-load record is four consecutive doubles at receiver offsets 0x0 (load average), 0x8 (half-difference), 0x10 (load value) and 0x18 (reciprocal); TireLoadFactorSetter writes all four per frame from TireCompoundPerWheelPhysicsApplication.
- **TireSlipCurveTableLayout** — The slip-curve name table exposes entry count at +0x8 and the entry array at +0xC with a 24-byte stride; each entry name lives at the entry base, a null name falls back to byte_5EA438, and a match is detected by sub_588410 returning 0.
- **AISessionTimingOffsets** — The AI session-timing object stores the session-time base at +0x354, caller-supplied session identifier at +0x358, processed-count threshold at +0x35C and vehicle-behavior parameter pointer at +0x360; per-vehicle speed-bias base sits at +0x34C. AIBehaviorInitialization is the session entry point called from AIOvertake.
- **TireTemperatureNormalizationRange** — Each frame the four corner temperatures are normalized into [0,1] (linear map clamped at both ends) and stored through the wheel-base pointer at +0x8CC; consumers of those normalized per-corner values must expect the same range.
- **TireWearTableTeardownContract** — Both teardown twins (0x004F6B00 and 0x004F6B90) walk a 45-entry, 20-byte-stride heap-pointer table, free each non-null entry through FreeWrapper_7bcf and return the last processed pointer; a replacement must preserve the table anchors (byte_8AFC74 / unk_8AF8EC) and stride.

## Unresolved

- function:0x004BF0A0: Globals flt_59E43C, flt_59E440, dword_5ACDB0 and flt_5ACDE0 are listed in the packet but not referenced by the raw body; roles unresolved.
- function:0x004BF0A0: a3 flag semantic (forces the reset path when set) is caller-specific.
- function:0x004BF0A0: Per-vehicle state offsets (13000, 16444, 16452, 16484, 16532, 16536, 16540, 16568) reference another object's layout not declared as fields here.
- function:0x004BF0A0: The v27 buffer and the this+4*i and this+4*i+416 arrays are per-slot scratch; the this+4*i+416 array byte range is not in the packet field list.
- function:0x004BF0A0: The literal values 1065353216 and 1110704128 are preserved as-is; their bit-level float decoding is not asserted.
- function:0x004CBC50: Global literals flt_59E450, flt_59E708, flt_59E7F8, flt_5ACEA8 are listed in the packet's globals table but do not appear in the raw source; their role here is unclear.
- function:0x004CBC50: Callers CollisionEffectDispatch (0x004CE3E0) and ParticleCollisionEffect (0x004CE930) invoke this on the frame path, but the owning class and the slot layout behind the circular buffer are unknown.
- function:0x004CBC50: The exact semantics of the a2/a3/a4/a6 parameter triple and the v22/v17 locals depend on the CollisionNormalFromFeature contract.
- function:0x004D5EE0: Three read-only double globals (dbl_59E420, dbl_59E430, dbl_59E880) are flagged by packet facts but appear nowhere in the raw decompiled source; the skeleton fill labels them as the 1.0/0.0/0.5 constant literals, which cannot be tied to a specific source line from this packet
- function:0x004D5EE0: The reciprocal division 1.0 / a4 has no zero-divisor guard in the raw source; a4 == 0.0 would produce a non-finite result whose handling is not visible
- function:0x004D75D0: sub_588410's exact comparison semantics (case sensitivity, path awareness) are visible only through its return-0-on-equality contract and are not established by the packet.
- function:0x004D75D0: byte_5EA438's role as a default/fallback name is inferred from its substitution when an entry name pointer is null.
- function:0x004D75D0: aDDevF119992002_4 is passed as a source-path argument to StringSplitLoop along with the literal 995, matching a debug-source validation pattern, but the exact role of the literal 995 is not established by the packet.
- function:0x004E3AA0: Local double v26 is read before initialization; the decompiler lost the true stack origin of the ground-plane term in the penetration expression.
- function:0x004E3AA0: Globals flt_59E440 (0x0059E440) and flt_5AD168 (0x005AD168) are flagged read-only by packet facts but appear nowhere in the raw decompiled source; the skeleton fill's claimed roles cannot be verified from this packet.
- function:0x004E3AA0: The packed integer literals v22..v25 written near v21 are never referenced by the visible body; their role in the collision query is unresolved.
- function:0x004ED810: The per-corner normalization write slots reached through the wheel base pointer at this+0x8CC are relative to that pointer; their absolute offsets from the wheel object are not in the packet field set.
- function:0x004ED810: Six read-only globals (flt_59E43C, flt_59E440, flt_59E450, dbl_59EEC0, dbl_59EEC8, flt_5ACAFC) are flagged by packet facts but appear nowhere in the raw decompiled source; their roles are unverifiable from this packet.
- function:0x004ED810: Which physical corners the two temperature-update groups and the four normalization slots map to is not determinable from this packet alone.
- function:0x004F1630: Semantic meaning of the compound index pair (this+0x396C, this+0x3970) is not established; only their role as CompoundIndexLookup arguments is known.
- function:0x004F1630: Content of the default string byte_5EA438 is unknown; it likely names a fallback path for an absent tire entry.
- function:0x004F1630: The owning tire/vehicle configuration object and the exact tire-name table are unresolved.
- function:0x004F1C20: Type of the object pointed at by this+0x3A9C and the meaning of the flag at byte offset 300 (value 1 = active) are inferred from the existing analysis only.
- function:0x004F1C20: Offset 0x3BC8 on this is the packet's representation of the dereferenced flag at pointer-offset 300; the exact relationship is not pinned.
- function:0x004F6B00: The layout and element type of the 45-entry, 20-byte-stride table anchored at byte_8AFC74 are unknown; only the end-anchor address is evidenced.
- function:0x004F6B00: The ABI label Tire_Wear_Property_Cleanup is legacy naming; the table's semantic role (tire-wear properties) is unproven by runtime evidence.
- function:0x004F6B90: The layout and element type of the 45-entry, 20-byte-stride table anchored at unk_8AF8EC are unknown; only the end-anchor address is evidenced.
- function:0x004F6B90: The ABI label Tire_Wear_Property_Cleanup_4f6b90 is legacy naming; the table's semantic role (tire-wear properties) is unproven by runtime evidence.
- function:0x004F6B90: Whether the 004f6b90 table overlaps or neighbors the one anchored at byte_8AFC74 used by twin 004f6b00 is unresolved.
- function:0x004F7440: The StringCopyWithBufferRealloc call does not explicitly pass a destination in the rendered source; the destination buffer is implied to be part of the this object (or its sub-buffer), which is not evidenced by the packet.
- function:0x004F7440: The exact layout of the tire-slot struct beyond offsets 0x8, 0xC and 0x10 is unknown.
- function:0x004F7440: The owner class is unknown; the single caller 0x004F70C0 is the only external relationship recorded.
- function:0x004F7440: Returning -1 appears to be a fixed convention of this initializer rather than a meaningful state value.
- function:0x004FAD80: Object identity/class is unknown; untouched fields between the listed ones keep their prior contents.
- function:0x004FAD80: The -9.81 gravity value and 1.0 scalar suggest a physics/vehicle-like object but this is not confirmable from this packet.
- function:0x00512093: Relationship between the three objects and the meaning of LargeStructPartialReset's three-argument shape is inferred from the structural twin, not proven.
- function:0x005199C5: SpriteFrameSelector has no packet callee address, so its identity and the meaning of its return value are unverified.
- function:0x005199C5: The receiver object type is unconfirmed; the field at 0x80 is only known to be zeroed by this routine.
- function:0x005199C5: Why the animation index reset is split from the frame-selection step is unknown.
- function:0x0051CC8E: The concrete allocator behind vtable slot 0 (this+0x4) is not resolved; no callee address is evidenced by the packet.
- function:0x0051CC8E: The semantic meaning of the four arithmetic-progression tables inside the sub-struct at 0x19C (labeled wheel geometry/suspension by existing analysis) is not established by the packet.
- function:0x0051CC8E: The role of unk_5B6900 and its decreasing-offset traversal are not established by the packet.
- function:0x005419D0: The packet fields express the global list object as *(this+0x368) while the raw source dereferences the global base dword_8B8F28 directly; the equivalence of the two bases is not fully reconciled.
- function:0x005419D0: Node layout semantics beyond bookkeeping (owner field a2[107], head field this[108]) are unverified.
- function:0x00542540: Role of the two stored pointers (e.g. callback/context pair) and the identity of the owning object are unknown here; only the callers reveal usage.
- function:0x00545030: The concrete owning class of this and of the linked nodes is unknown; the packet provides no owner evidence.
- function:0x00545030: The interpretation of +436/+440 as previous/next node pointers and of this[62] (offset 0xF8) as the list head comes from the linked-list structure of the raw code and from existing analysis (DERIVED), not from a proven field contract.
- function:0x00545030: Field base *(*(this+0x2B0)+0x1B8) renders the same tail next-pointer write as the raw +440 access; the two views were not independently corroborated against a struct definition.
- function:0x00556700: The semantics of dword_8B8E48 (slot count or end sentinel) and the +32 offsets are unknown; the +32 appears on both sides of the comparison and in the sentinel, suggesting an array-of-32-dword-slot layout or a stored byte-count conversion.
- function:0x00556700: The array dword_8B6C28 with a 19-dword stride and base element 608 has no established type; whether it holds timer/state records per slot a1 is unproven.
- function:0x00556700: The purpose of HighResolutionTimerReset on a per-slot address is unclear without the caller sub_4F9FC0 (0x004F9FC0) context.
- function:0x00556700: The AI subsystem tag and function name are legacy/semantic labels, not confirmed ownership.
- function:0x0055D4F0: dword_8B78A0 identity/role (sound manager per prior analysis) is not established by raw source.
- function:0x0055D4F0: Bit 0x800 at dword_8B8F28 + 236 marks a dirty/update state; the exact consumer of the flag is not evidenced here.
- function:0x0055D4F0: Mode 6 meaning for DirectXVertexBufferTextureCoordinateSetup is not defined by this packet.
- function:0x0055D4F0: The three stored values' consumer (vertex texture coordinates per prior analysis) is caller-dependent.
- function:0x00563020: Meaning of the early-return literal 4 and of a1[28]/a1[29] (state markers) is not resolved.
- function:0x00563020: Purpose of a2 (skips the polling loop when non-zero) is not established from this packet alone.
- function:0x00563020: sub_5630D0, SocketArrayCreate, CreateUdpBroadcastSocket and PollingLoopWithProcessCalls bodies are out of scope here.
- function:0x005649D0: The meaning of a3 (consumed by both helpers, likely a count or selector) is caller-supplied and not resolved here.
- function:0x005649D0: Why IndirectCallViaFunctionPointer's result is discarded while AlignedMemoryCopyFromStructBuffer's is returned is not established.
- function:0x0057B910: The owning object that holds the two sockaddr structures is not evidenced by the packet.
- function:0x0057B910: The layout gap between the first structure (0x0-0x8) and the second (0x10 onward) implies an intervening field that is not evidenced by the packet.
- function:0x00583360: The next-pointer field at node+4 is traversed but absent from the packet field table, so it has no evidence ref of its own.
- function:0x00583360: The semantics of NTimeCallbackLoopWithSEH's second argument 84 and the callback-header word at count-4 are preserved as literals but their meaning (entry stride / header layout) is not evidenced in this packet.
- function:0x00583360: The object type owning the list is unknown; node layout (data ptr +0, next +4, flag +8) is inferred from this single destructor and not cross-confirmed.
- function:0x00583360: The ABI name in the packet is marked LEGACY/FAIL; the object's true role in a subsystem is unconfirmed.
- function:0x005840C6: Identity of the object in a2 and of the byte at a2 + 46276; the volume-gain reading is inferred from the legacy ABI name only.
- function:0x005840C6: Semantics of MutexWaitWith1msTimeoutRelease (mutex acquisition, release, or a combined wait-with-timeout that returns a status).
- function:0x00595207: Direction of the carry semantics depends on whether OverflowCheckedUnsignedAddition returns nonzero on overflow or on success; the loop break condition implies nonzero means continue propagating.
- function:0x00595207: Whether the caller treats the array as a big bit string or as packed numeric words is not established by this function alone.
- The packet declares scope vehicle_ai_and_pit but bundles several functions whose subsystem placement is not established (network-socket init 0x00563020 / sockaddr init 0x0057B910, audio gain 0x005840C6, UI texture-coordinate group 0x0055D4F0, bit-array helper 0x00595207, linked-list helpers 0x005419D0 / 0x00545030 / 0x00583360, and generic initializers 0x004FAD80 / 0x0051CC8E). They are grouped conservatively by call relationship; their membership in this scope is not asserted.
- Common ownership across the three linked-list entry points (0x005419D0 this+0x1B0, 0x00545030 this+0xF8, 0x00583360 this+0x0) is not proven by the packet; they are kept as separate classes rather than merged.
