# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

This scope mixes a single vehicle-physics update with the collision geometry machinery it hands off to. SuspensionForceUpdate (0x00447780) copies the 24-byte input state into every physics sub-object block, computes a per-wheel suspension force from the shared state at this+0x15F0, averages it by the mode at this+0x1E14, applies a clamped damper scaling and a wheel-weight minimum selection, records the force into the output slots at this+0x1C5C and duplicates at 0x1C64/0x1C68 and 0x1E38..0x1E44, feeds SuspensionVibration, then runs a two-pass sub-object integration (array at this+0x3EC, stride 1124) that re-applies the shared transform and inertia blocks into each active sub-object. The collision layer is the bulk of the scope: CollisionShapeInit/PhysicsBufferFree (0x004492B0/0x00449340) manage a shape whose buffer at +0x8 is freed through a 4-byte allocation header and whose sub-components at +0xC/+0x10 are destroyed and freed; CollisionContactResponse (0x00449700) blends pair masses with the 0.5 factor from global 0x0059E880 and interpolates contact vertices; CollisionTreeNodeDeserializer (0x0044A700) and CollisionTreeNodeCleanup (0x0044C470) load and release tree nodes; CollisionGridRaycast32x32 (0x0044BA40) rasterizes a grid into a 32x32 cell query array; CollisionGeometryOperationSelector (0x0044BB60) dispatches a pipeline (animation, contact response, bezier tessellation, sweep-and-prune) over the global handle 0x008AFE88. CollisionInitDelegate (0x0044C5F0) invokes the init routine at 0x0044C600. A family of 30 registration thunks (0x00449A00 plus 0x0044C650..0x0044D5B0) each read a stored null-subroutine global and route it through BooleanToIntConversion (0x00587B3E), returning the integer result; the packet's own operations disagree on whether that helper registers the pointer (0/-1 status) or merely normalizes it. No receiver class identity is proven for any function; every owner is UnknownObject in the source packet and all class names here are DERIVED/GUESS groupings of shared offset and call patterns.

## Function roles

- `0x00447780` **VehicleSuspension** — update - per-frame suspension force update: copy the 24-byte input state into every sub-object block (count at this+0x15AC, array at this+0x15B0, stride 580, per-block offset +100) via Copy6DwordsToStructCall; compute the raw force from the shared state at this+0x15F0 (weight rows at +0x5C/+0x40/+0x16); write the four per-wheel pair results (this+0x348/0x7AC/0xC10/0x1074); select the averaging mode at this+0x1E14; derive the clamped damper factor; write the mode-selected force into this+0x1C5C with wheel-weight selection via selector this+0x1EAC and threshold this+0x1CDC; clamp against this+0x1C84/0x1C88 reporting via PositionLapStateUpdate; propagate the force dwords into this+0x1C64/0x1C68 and this+0x1E38..0x1E44; feed SuspensionVibration; reset the sub-object active flag at this+0xD0; run the two-pass sub-object integration (array at this+0x3EC, stride 1124: zero via sub_56BDE0, copy transform/inertia blocks, transform via F_3x3InertiaTensorTransform / InertiaTensorWorldSpaceTransform, release via PhysicsSubObjectFree); returns the loop decrement (1 after the two-pass loop)
- `0x004492B0` **CollisionShape** — init - collision-shape initializer: zero the fields at this+0x8, this+0xC and this+0x10, call PhysicsBufferFree (0x00449340) to reset the shape's physics buffer, and return the this pointer; invoked by BezierPatchTessellation (0x0044B370), CollisionGeometryOperationSelector (0x0044BB60) and SceneTrackFileLoader (0x0044C0E0) while preparing collision shapes
- `0x00449340` **CollisionShape** — teardown - physics-buffer free: save this+0x8, zero this+0x0 and this+0x4, free the this+0x8 buffer through its allocation header (result-4) via FreeWrapper_7bcf, then conditionally destroy and free the sub-components at this+0xC and this+0x10 via PhysicsSubComponentDestroy / FreeWrapper_7bcf and zero them; returns the last free result
- `0x00449700` **CollisionContactContainer** — update - contact-pair processing after broad-phase: traverse the two collision tree roots at this+0xC and this+0x10 via CollisionTreeTraversal, then over the 32-byte contact pair array at this+0x8 (pair count at this+0x0, guarded >0) blend each pair node's mass using the 0.5 factor from global 0x0059E880, propagate the blended masses via PhysicsTreeMassPropagation on the second tree root, and apply WeightedAverageInterpolation on each pair's node triples; returns the pair count
- `0x00449A00` **CollisionRegistrationHooks** — registration - pass the stored function address at global 0x00449A10 to BooleanToIntConversion (0x00587B3E) and return its integer result; reports the registered slot rather than executing it
- `0x0044A430` **CollisionObject** — init - constructor-style collision-object initializer: zero this+0x0, this+0x4 and this+0xC, write the 16-bit sentinels -3 at this+0x8 and -1 at this+0xA, return this; invoked from 0x0044BC50 and HTreeTerrainFileFormatLoader (0x0044BE70)
- `0x0044A700` **CollisionTreeNode** — deserialize - recursively read one collision-tree node from the file stream via FileWriteWithBackendDispatch: header reads, node-type word at this+0x8 (reject outside -2..1), for internal nodes a subtype byte at this+0xA and a child-slot arena pointer at this+0xC (base + 16*index) with recursion into two children, for leaf nodes a 92-byte vertex region at this+0xC (base + 92*index) filled via IndexedVertexLookupFromStream; returns 0 on success and -1 on any failure
- `0x0044BA40` **CollisionGrid** — query - rasterize the collision grid into a 32x32 cell query array: null-guard the grid data at this+0x4, compute X/Z cell strides as reciprocals of the scales at this+0x10 and this+0x20 (0.0-guard via globals 0x0059E420/0x0059E430), build per-cell world bounding boxes from the grid center at this+0x8 (X) and this+0x18 (Z) with the 0.5 constant from global 0x0059E880, query each cell via sub_44A880 and store the returned pointer into the flat output array at this+40; returns the last query result
- `0x0044BB60` **CollisionGeometryPipeline** — dispatch - collision-geometry pipeline dispatcher over the global geometry handle 0x008AFE88 and operation id a2: null handle runs only the final SweepAndPruneAABBOverlapDetection on a3; a2==0 runs animation playback on a3; a2==1 runs AnimationPlaybackSequence, CollisionContactResponse and sweep on a3; a2==2 runs CollisionShapeInit, AnimationPlaybackSequence, CollisionContactResponse, BezierPatchTessellation, PhysicsBufferFree and sweep on a3; every path returns the sweep-and-prune overlap result
- `0x0044C470` **CollisionTreeNode** — cleanup - collision-tree node teardown: free the two owned allocations at this+0x0 and this+0x4 (the second freed through a 4-byte header at ptr-4) via FreeWrapper_7bcf, zero the six scalar fields at this+0x8..0x1C, memset the trailing 0x1000-byte block at this+0x28, return 0; recorded callers: SceneTrackFileLoader (0x0044C0E0) and SpecialFX_Post (0x004CFED0)
- `0x0044C5F0` **CollisionInitDelegate** — delegate - invoke the collision initialization routine at global 0x0044C600 and convert its boolean result to an integer via BooleanToIntConversion (0x00587B3E), returning that integer; used to start collision-system initialization
- `0x0044C650` **CollisionRegistrationHooks** — registration - read the stored null-subroutine pointer at global 0x0044C660 (nullsub_23), cast it to int and pass it to BooleanToIntConversion (0x00587B3E), returning the integer result; the stub target has no body so the intended init behavior is unrecoverable
- `0x0044C6B0` **CollisionRegistrationHooks** — registration - pass the address of nullsub_24 (global 0x0044C6C0) to BooleanToIntConversion (0x00587B3E) and return the boolean-to-int result; reports the no-op stub's presence rather than executing teardown
- `0x0044C770` **CollisionRegistrationHooks** — registration - read the nullsub_26 stub pointer (global 0x0044C780), cast it to int and forward it to BooleanToIntConversion (0x00587B3E), returning the conversion result; reports a non-zero registered status for the placeholder stub
- `0x0044C830` **CollisionRegistrationHooks** — registration - read the nullsub_30 function pointer (global 0x0044C840), cast it to int and pass it to BooleanToIntConversion (0x00587B3E), returning the integer result; the abi name suggests a collision-init thunk (variant A) but the stub has no body
- `0x0044C890` **CollisionRegistrationHooks** — registration - read the nullsub_32 function pointer (global 0x0044C8A0), cast it to int and pass it to BooleanToIntConversion (0x00587B3E), returning the integer result; the abi name suggests a collision-init wrapper but the stub has no body
- `0x0044C950` **CollisionRegistrationHooks** — registration - pass the address of nullsub_35 (global 0x0044C960) to BooleanToIntConversion (0x00587B3E) and return the integer result; the no-op suggests a collision-sound unregister hook that currently performs no work
- `0x0044CA10` **CollisionRegistrationHooks** — registration - read the nullsub_37 stub pointer (global 0x0044CA20), cast it to int and forward it to BooleanToIntConversion (0x00587B3E), returning the conversion result; reports the placeholder's registered status
- `0x0044CB30` **CollisionRegistrationHooks** — registration - pass the address of nullsub_42 (global 0x0044CB40) to BooleanToIntConversion (0x00587B3E) and return the integer result; the no-op suggests a collision-grid free path that currently performs no work
- `0x0044CB90` **CollisionRegistrationHooks** — registration - read the nullsub_44 stub pointer (global 0x0044CBA0), cast it to int and forward it to BooleanToIntConversion (0x00587B3E), returning the conversion result; reports the placeholder's registered status
- `0x0044CBF0` **CollisionRegistrationHooks** — registration - read the stored null-subroutine address at global 0x0044CC00 (nullsub_46), pass it through BooleanToIntConversion (0x00587B3E) and return the integer result; the global has no static writers so the callback is installed at runtime
- `0x0044CC50` **CollisionRegistrationHooks** — registration - pass the address of nullsub_48 (global 0x0044CC60) cast to int to BooleanToIntConversion (0x00587B3E) and return the integer result; the abi name suggests collision resource release but the stub is empty
- `0x0044CCB0` **CollisionRegistrationHooks** — registration - read the stored null-subroutine address at global 0x0044CCC0 (nullsub_49), pass it through BooleanToIntConversion (0x00587B3E) and return the integer result; the global has no static writers so the callback is installed at runtime
- `0x0044CD10` **CollisionRegistrationHooks** — registration - pass the address of nullsub_50 (global 0x0044CD20) cast to int to BooleanToIntConversion (0x00587B3E) and return the integer result; the abi name implies a constructor delegation but the stub has no body
- `0x0044CD70` **CollisionRegistrationHooks** — registration - pass the address of nullsub_51 (global 0x0044CD80) cast to int to BooleanToIntConversion (0x00587B3E) and return the integer result; the abi name implies an initialization delegation but the stub has no body
- `0x0044CDD0` **CollisionRegistrationHooks** — registration - load the no-op callback pointer nullsub_52 (global 0x0044CDE0) and pass it to BooleanToIntConversion (0x00587B3E); per the corpus callee this registers the pointer into a global critical-section-guarded registration list returning 0 on success or -1 on failure, and this function returns that result unchanged
- `0x0044CE30` **CollisionRegistrationHooks** — registration - read the stored null-subroutine address at global 0x0044CE40 (nullsub_53), pass it through BooleanToIntConversion (0x00587B3E) and return the integer result; the global has no static writers so the callback is installed at runtime
- `0x0044CEF0` **CollisionRegistrationHooks** — registration - read the nullsub_55 stub pointer (global 0x0044CF00), cast it to int and forward it to BooleanToIntConversion (0x00587B3E), returning the conversion result; the non-null placeholder reports a registered status
- `0x0044CFB0` **CollisionRegistrationHooks** — registration - load the no-op callback pointer nullsub_57 (global 0x0044CFC0) and pass it to BooleanToIntConversion (0x00587B3E); per the corpus callee this registers the pointer into a global critical-section-guarded registration list returning 0 on success or -1 on failure, and this function returns that result unchanged
- `0x0044D010` **CollisionRegistrationHooks** — registration - load the no-op callback pointer nullsub_58 (global 0x0044D020) and pass it to BooleanToIntConversion (0x00587B3E); per the corpus callee this registers the pointer into a global critical-section-guarded registration list returning 0 on success or -1 on failure, and this function returns that result unchanged
- `0x0044D0D0` **CollisionRegistrationHooks** — registration - read the nullsub_61 function pointer (global 0x0044D0E0), cast it to int and pass it to BooleanToIntConversion (0x00587B3E), returning the integer result; the abi name suggests a collision-sound unregister wrapper but the stub has no body
- `0x0044D190` **CollisionRegistrationHooks** — registration - read the nullsub_64 stub pointer (global 0x0044D1A0), cast it to int and forward it to BooleanToIntConversion (0x00587B3E), returning the conversion result; the non-null placeholder reports a registered status
- `0x0044D2B0` **CollisionRegistrationHooks** — registration - read the nullsub_68 function pointer (global 0x0044D2C0), cast it to int and pass it to BooleanToIntConversion (0x00587B3E), returning the integer result; the abi name suggests a collision-grid free wrapper but the stub has no body
- `0x0044D310` **CollisionRegistrationHooks** — registration - read the nullsub_69 stub pointer (global 0x0044D320), cast it to int and forward it to BooleanToIntConversion (0x00587B3E), returning the conversion result; the non-null placeholder reports a registered status
- `0x0044D370` **CollisionRegistrationHooks** — registration - pass the address of nullsub_70 (global 0x0044D380) cast to int to BooleanToIntConversion (0x00587B3E) and return the boolean-to-int result; reports the no-op stub's presence rather than executing data registration
- `0x0044D430` **CollisionRegistrationHooks** — registration - call BooleanToIntConversion (0x00587B3E) with the global nullsub_73 (0x0044D440) cast to int and return the resulting integer; the legacy collision-resource-release name is unverified
- `0x0044D490` **CollisionRegistrationHooks** — registration - pass the address of nullsub_75 (global 0x0044D4A0) cast to int to BooleanToIntConversion (0x00587B3E) and return the boolean-to-int result; reports the no-op stub's presence rather than executing callback registration
- `0x0044D4F0` **CollisionRegistrationHooks** — registration - call BooleanToIntConversion (0x00587B3E) with the global nullsub_77 (0x0044D500) cast to int and return the resulting integer; the legacy constructor-thunk name is unverified
- `0x0044D550` **CollisionRegistrationHooks** — registration - call BooleanToIntConversion (0x00587B3E) with the global nullsub_79 (0x0044D560) cast to int and return the resulting integer; the legacy init-delegator name is unverified
- `0x0044D5B0` **CollisionRegistrationHooks** — registration - zero-argument registration stub: read the address of the placeholder nullsub_81 (global 0x0044D5C0) and return the result of BooleanToIntConversion applied to that function pointer; the consumer of the returned integer is not identified

## Proposed classes

### VehicleSuspension

Receiver of SuspensionForceUpdate (0x00447780). Holds the sub-object count at +0x15AC and array at +0x15B0 (stride 580, 24-byte input copied to each block's +100), a second sub-object integration array at +0x3EC (stride 1124) with an active flag at +0xD0, a shared physics-state block pointer at +0x15F0, a four-slot wheel-geometry cursor array at +0x348/+0x7AC/+0xC10/+0x1074, the suspension force output double at +0x1C5C (high dword +0x1C60) with duplicated slots at +0x1C64/+0x1C68 and +0x1E38..+0x1E44, the lower bound at +0x1C84/+0x1C88, the clamp threshold scalar at +0x1CDC, the averaging-mode selector at +0x1E14 and the wheel-weight walk selector at +0x1EAC.

Methods: `0x00447780`

- `this+0x000000D0` `uint32 subObjectActiveFlag` (write, DERIVED)
- `this+0x00000348` `double wheelGeometrySlotA` (read_write, GUESS)
- `this+0x000003EC` `PhysicsSubObject* subObjectIntegrationArray` (read, DERIVED)
- `this+0x000007AC` `double wheelGeometrySlotB` (read_write, GUESS)
- `this+0x00000C10` `double wheelGeometrySlotC` (read_write, GUESS)
- `this+0x00001074` `double wheelGeometrySlotD` (read_write, GUESS)
- `this+0x000015AC` `int32 subObjectCount` (read, DERIVED)
- `this+0x000015B0` `void** subObjectArray` (read, DERIVED)
- `this+0x000015F0` `PhysicsSharedState* physicsSharedState` (read, DERIVED)
- `this+0x00001C5C` `double suspensionForce` (read_write, DERIVED)
- `this+0x00001C60` `uint32 suspensionForceHighDword` (read_write, GUESS)
- `this+0x00001C64` `uint32 forceCopySlotA` (write, DERIVED)
- `this+0x00001C68` `uint32 forceCopySlotB` (write, DERIVED)
- `this+0x00001C84` `uint32 suspensionForceLowerBound` (read, DERIVED)
- `this+0x00001C88` `uint32 suspensionForceLowerBoundHigh` (read, GUESS)
- `this+0x00001CDC` `double clampThresholdScaler` (read, GUESS)
- `this+0x00001E14` `int32 averagingMode` (read, DERIVED)
- `this+0x00001E38` `uint32 outputCopySlot0` (write, DERIVED)
- `this+0x00001E3C` `uint32 outputCopySlot1` (write, DERIVED)
- `this+0x00001E40` `uint32 outputCopySlot2` (write, DERIVED)
- `this+0x00001E44` `uint32 outputCopySlot3` (write, DERIVED)
- `this+0x00001EAC` `int32 wheelWeightWalkSelector` (read, DERIVED)

### PhysicsSharedState

Shared physics-state block owned through the VehicleSuspension pointer at +0x15F0. Carries a 0x48-byte transform region (evidence points at +0x2C and +0x44) and the suspension weight double at +0x5C. The block is copied wholesale into each active sub-object during the two-pass integration.

Methods: 

- `*(this+0x15F0)+0x0000002C` `float[3] transformBlockPart0` (read, DERIVED)
- `*(this+0x15F0)+0x00000044` `float[3] transformBlockPart1` (read, DERIVED)
- `*(this+0x15F0)+0x0000005C` `double suspensionWeight` (read, DERIVED)

### CollisionShape

Collision shape container shared by CollisionShapeInit (0x004492B0) and PhysicsBufferFree (0x00449340). Zeroed dwords at +0x0 and +0x4, a physics buffer pointer at +0x8 freed through a 4-byte allocation header, and two optional physics sub-component pointers at +0xC and +0x10 that are destroyed and freed. Constructed from BezierPatchTessellation, CollisionGeometryOperationSelector and SceneTrackFileLoader paths.

Methods: `0x004492B0`, `0x00449340`

- `this+0x00000000` `uint32 state0` (read_write, DERIVED)
- `this+0x00000004` `uint32 state4` (read_write, DERIVED)
- `this+0x00000008` `void* bufferPtr` (read_write, DERIVED)
- `this+0x0000000C` `void* subComponentPtr` (read_write, DERIVED)
- `this+0x00000010` `void* subComponentPtr2` (read_write, DERIVED)

### CollisionContactContainer

Receiver of CollisionContactResponse (0x00449700). Contact pair count at +0x0, the 32-byte-stride contact pair array at +0x8, and two collision tree roots at +0xC and +0x10. The response blends pair node masses with the 0.5 factor from global 0x0059E880, propagates the blended masses through the second tree, and interpolates each pair's vertex triples.

Methods: `0x00449700`

- `this+0x00000000` `int32 pairCount` (read, DERIVED)
- `this+0x00000008` `void* contactPairArray` (read, DERIVED)
- `this+0x0000000C` `CollisionTreeNode* collisionTreeRootA` (read, GUESS)
- `this+0x00000010` `CollisionTreeNode* collisionTreeRootB` (read, GUESS)

### CollisionObject

Collision object initialized by CollisionObjectInit (0x0044A430). Zeroed dwords at +0x0, +0x4 and +0xC with 16-bit sentinel words -3 at +0x8 and -1 at +0xA. Constructed from 0x0044BC50 and HTreeTerrainFileFormatLoader (0x0044BE70).

Methods: `0x0044A430`

- `this+0x00000000` `uint32 field0` (write, DERIVED)
- `this+0x00000004` `uint32 field4` (write, DERIVED)
- `this+0x00000008` `int16 sentinelWordA` (write, DERIVED)
- `this+0x0000000A` `int16 sentinelWordB` (write, DERIVED)
- `this+0x0000000C` `uint32 fieldC` (write, DERIVED)

### CollisionTreeNode

Collision-tree node receiver shared by CollisionTreeNodeDeserializer (0x0044A700) and CollisionTreeNodeCleanup (0x0044C470). Two owned allocations at +0x0 and +0x4 (the second carries a 4-byte header before the stored pointer), a node-type word at +0x8, a subtype byte at +0xA, a child-slot/vertex arena pointer at +0xC, six scalar fields at +0x10..+0x1C, and a trailing 0x1000-byte block at +0x28.

Methods: `0x0044A700`, `0x0044C470`

- `this+0x00000000` `void* allocationPtr` (read_write, DERIVED)
- `this+0x00000004` `void* allocationHeaderPtr` (read_write, DERIVED)
- `this+0x00000008` `int16 nodeType` (read_write, DERIVED)
- `this+0x0000000A` `uint8 subtypeByte` (read_write, DERIVED)
- `this+0x0000000C` `void* childSlotOrVertexArena` (read_write, DERIVED)
- `this+0x00000010` `uint32 scalarField10` (write, DERIVED)
- `this+0x00000014` `uint32 scalarField14` (write, DERIVED)
- `this+0x00000018` `uint32 scalarField18` (write, DERIVED)
- `this+0x0000001C` `uint32 scalarField1C` (write, DERIVED)

### CollisionGrid

Collision grid description receiver of CollisionGridRaycast32x32 (0x0044BA40). Grid data pointer at +0x4, world center X at +0x8 and Z at +0x18, axis scales at +0x10 (X) and +0x20 (Z). The query rasterizes the grid into a 32x32 cell array whose output pointers are stored at this+40.

Methods: `0x0044BA40`

- `this+0x00000004` `void* gridDataPtr` (read, DERIVED)
- `this+0x00000008` `float centerX` (read, DERIVED)
- `this+0x00000010` `float scaleX` (read, DERIVED)
- `this+0x00000018` `float centerZ` (read, DERIVED)
- `this+0x00000020` `float scaleZ` (read, DERIVED)

### CollisionGeometryPipeline

Pipeline dispatcher CollisionGeometryOperationSelector (0x0044BB60) over the global collision-geometry handle 0x008AFE88. Selects among animation-only, animation+contact+sweep, and full bezier-tessellation pipelines on the operation id; every path converges on SweepAndPruneAABBOverlapDetection over the a3 output pointer. No receiver fields are evidenced on this object.

Methods: `0x0044BB60`


### CollisionInitDelegate

Collision-system initialization delegate CollisionInitDelegator (0x0044C5F0): invokes the init routine at global 0x0044C600 and normalizes its boolean result through BooleanToIntConversion. Distinct from the nullsub-based registration hooks because it actually invokes its target.

Methods: `0x0044C5F0`


### CollisionRegistrationHooks

Synthetic grouping (GUESS) of the 30 registration thunks that share an identical body: read a stored null-subroutine global, cast it to int, pass it to BooleanToIntConversion (0x00587B3E) and return the integer result. Each global has no static writers, so the real handlers are installed at runtime. Whether these are methods of one class or 30 independent global hooks is unknown; the grouping captures the shared pattern only.

Methods: `0x00449A00`, `0x0044C650`, `0x0044C6B0`, `0x0044C770`, `0x0044C830`, `0x0044C890`, `0x0044C950`, `0x0044CA10`, `0x0044CB30`, `0x0044CB90`, `0x0044CBF0`, `0x0044CC50`, `0x0044CCB0`, `0x0044CD10`, `0x0044CD70`, `0x0044CDD0`, `0x0044CE30`, `0x0044CEF0`, `0x0044CFB0`, `0x0044D010`, `0x0044D0D0`, `0x0044D190`, `0x0044D2B0`, `0x0044D310`, `0x0044D370`, `0x0044D430`, `0x0044D490`, `0x0044D4F0`, `0x0044D550`, `0x0044D5B0`


## Compatibility contracts

- **SuspensionSubObjectLayout** — VehicleSuspension holds the sub-object count at +0x15AC, the input-propagation array at +0x15B0 (stride 580, 24-byte input copied into each block's +100) and the integration array at +0x3EC (stride 1124). The active flag at +0xD0 is reset to 0 before the integration pass. A replacement must preserve these counts, strides and per-block offsets.
- **SuspensionForceOutputLayout** — The finalized suspension force double lives at +0x1C5C/+0x1C60 and is mirrored into +0x1C64/+0x1C68 and +0x1E38..+0x1E44. The lower bound is read from +0x1C84/+0x1C88, the clamp threshold scalar from +0x1CDC, the averaging-mode selector from +0x1E14 and the wheel-weight walk selector from +0x1EAC. Any consumer of the suspension output reads these slots.
- **PhysicsSharedStateBlock** — The shared physics state at this+0x15F0 contains a 0x48-byte transform region (evidence points at +0x2C and +0x44) and the suspension weight double at +0x5C. The transform and 24-byte inertia block are propagated into each active sub-object during integration; a replacement must reproduce the block contents that the sub-object nodes consume.
- **CollisionShapeLayout** — CollisionShape: zeroed dwords at +0x0 and +0x4, physics buffer pointer at +0x8 freed through a 4-byte allocation header, and optional sub-component pointers at +0xC and +0x10 destroyed via PhysicsSubComponentDestroy and freed. Init clears +0x8/+0xC/+0x10; teardown frees and nulls all buffer slots.
- **CollisionContactContainerLayout** — CollisionContactContainer: contact pair count at +0x0, 32-byte-stride pair array at +0x8, two collision tree roots at +0xC and +0x10. The response traverses both roots, blends pair masses with the 0.5 factor from global 0x0059E880, propagates via the second tree root and interpolates each pair's node triples.
- **CollisionObjectLayout** — CollisionObject initializer writes zeroed dwords at +0x0, +0x4 and +0xC and the 16-bit sentinels -3 at +0x8 and -1 at +0xA. A replacement collision object must start in this state.
- **CollisionTreeNodeLayout** — CollisionTreeNode: owned allocations at +0x0 and +0x4 (the second freed through a 4-byte header at ptr-4), node-type word at +0x8, subtype byte at +0xA, child-slot/vertex arena pointer at +0xC, six scalar fields at +0x10..+0x1C, and a trailing 0x1000-byte block at +0x28. Cleanup frees both allocations, zeroes +0x8..+0x1C and memsets the trailing block.
- **CollisionGridLayout** — CollisionGrid: grid data pointer at +0x4, world center X at +0x8 and Z at +0x18, axis scales at +0x10 (X) and +0x20 (Z). The raycast produces a flat 32x32 output pointer array at this+40; each entry is the per-cell query result of sub_44A880.
- **CollisionGeometryPipelineDispatch** — CollisionGeometryOperationSelector dispatches on the global geometry handle 0x008AFE88 and the operation id a2: null handle runs only the final sweep-and-prune on a3; a2==0 runs animation playback only; a2==1 runs animation, contact response and sweep; a2==2 runs shape init, animation, contact response, bezier tessellation, buffer free and sweep. Every path returns the sweep-and-prune result on a3.
- **RegistrationHookStatus** — The 30 registration thunks and the init delegate all return the integer produced by BooleanToIntConversion (0x00587B3E) over a stored function-pointer global. Whether that integer is a registered/not-registered status (0/-1) or a boolean normalization is contested inside the packet's own operations and left unresolved; the uniform call shape is the only hard requirement.

## Unresolved

- No receiver class identity is proven for any function; every owner is UnknownObject in the source packet and every class name here is a DERIVED/GUESS grouping of shared offset and call patterns.
- CollisionRegistrationHooks groups 30 functions with an identical body into one class, but whether they are methods of a single class or 30 independent global hooks is unknown; the grouping captures the shared BooleanToIntConversion(global) pattern only.
- The packet's own operations disagree on BooleanToIntConversion (0x00587B3E) semantics: 0x0044CDD0, 0x0044CFB0 and 0x0044D010 describe a critical-section-guarded global registration list returning 0 on success / -1 on failure, while 0x0044CEF0, 0x0044D190 and 0x0044D310 describe boolean-to-int normalization; 0x0044C950, 0x0044CB30, 0x0044CC50 and 0x0044CD10 further note that whether the helper invokes the pointer or merely converts its value is unevidenced.
- All nullsub globals (0x00449A10..0x0044D5C0) have no static writers; their real callback handlers are installed at runtime by registration code outside this scope.
- SuspensionForceUpdate: six double globals (0x0059E430, 0x0059E880, 0x0059EB28, 0x0059EB50, 0x0059EC70, 0x0059EEF0) are flagged read but appear nowhere as named symbols in the body; they are presumably consumed inside inlined arithmetic or a callee, and their exact read site is unresolved.
- SuspensionForceUpdate field this+0x450 is flagged read but no visible access appears in the decompiled body.
- The wheel-weight array base at this+7856 (0x1EB0) is read by SuspensionForceUpdate but is not present in the packet field list, so no field entry could be produced for it.
- SuspensionForceUpdate sub-object internal layout (24-byte input copied to block +100 at stride 580; node offsets +28/+124 at stride 1124) is DERIVED from operation text and has no field evidence refs.
- The SuspensionForceUpdate return value is the loop decrement (v32 - 1, i.e. 1 after the two-pass loop), so it is a constant rather than a meaningful status.
- CollisionShapeInit: the exact roles of the cleared fields at 0x8, 0xC and 0x10 (buffer pointer, bounds, flags) are DERIVED prose, not packet evidence; PhysicsBufferFree is called with no explicit argument, so its association with this shape object's buffer is unproven.
- PhysicsBufferFree: why the +0x8 buffer is freed through an allocation header (result-4) while the +0xC and +0x10 buffers are freed directly is unexplained; whether the sub-component buffers are separately allocated or owned inside the +0x8 allocation is unknown.
- CollisionContactResponse: exact meaning of the +16/+4 double offsets on the per-node objects depends on the unknown collision/physics node layout; the unit of the 0.5 blend constant from global 0x0059E880 (mass vs other scalar) is not determinable here.
- PhysicsDataRegistrationBlock (0x00449A00): why the address of sub_449A10 is coerced to int and converted to boolean is not visible; sub_449A10's own behavior is out of packet scope and no callers are recorded.
- CollisionObjectInit: the meaning of the -3/-1 word sentinels at +0x8/+0xA is not interpreted.
- CollisionTreeNodeDeserializer: the a2 arena cursor block layout (indices 7, 9, 10, 12) and the exact meaning of the offset-8 type byte are imposed by the terrain-file format owned by the caller; the relationship between the 92-byte leaf stride and the 16-byte internal child stride is presumed from offsets and unconfirmed; the (int)a2 vertex-count path for negative types other than -1/-2 is decompiler-derived.
- CollisionGridRaycast32x32: the layout and semantics of the structure sub_44A880 returns per cell are unknown; global constant roles (0x0059E420, 0x0059E430, 0x0059E880 as 1.0/0.0/0.5) are inferred from source literals and not independently verified; the output array at this+40 has no field evidence ref.
- CollisionGeometryOperationSelector: the nature of the a3 pointer is not established; the semantic meaning of operation ids 0/1/2 comes from existing analysis prose and is not independently provable; the v6 shape-buffer element layout passed to CollisionShapeInit/PhysicsBufferFree is not described.
- CollisionTreeNodeCleanup: the free of v2 - 4 implies the allocation at this+0x4 carries a 4-byte header whose layout is not visible; the element type and purpose of the trailing 0x1000-byte block at this+0x28 are unknown; the template prelabel ctor_init conflicts with the observed free/zero cleanup shape.
- CollisionInitDelegator (0x0044C5F0): whether sub_44C600 is a direct function address or an indirect call target is unresolved; the calling context that triggers collision initialization is not visible.
- Registration stubs (CollisionInitRegistration, ThunkCollisionInitA/B, CollisionInitWrapper, CollisionSoundUnregister, CollisionStaticDataRegistration, CollisionGridFreeA/B, CollisionModuleRegisterA/B, CollisionDataRegistrationBlock1/2, CollisionCallbackRegistration, CollisionResourceRelease, CollisionConstructorThunk, CollisionInitDelegator variants): each wrapped nullsub is an empty stub with no body, so the intended behavior is unrecoverable from this packet; the init/teardown/register intent is carried only by the canonical/abi names (LEGACY trust).
- CollisionDataTeardown (0x0044C6B0) and CollisionDataTeardown2 (0x0044CE30): whether the wrapped no-op intentionally performs no teardown or is an unimplemented stub cannot be decided from this packet.
- Several duplicate-named thunks (two CollisionInitRegistration, two CollisionCallbackRegistration, two CollisionStaticDataRegistration, two CollisionResourceRelease, two CollisionConstructorThunk) likely represent the same registration slots reached from different call sites, but no packet evidence proves they are the same hook or separate hooks.
- The registration thunks 0x0044D430, 0x0044D4F0 and 0x0044D550 carry legacy names (CollisionResourceRelease30, CollisionConstructorThunk_d4f0, CollisionInitDelegator_d550) that the packet flags as unverified.
