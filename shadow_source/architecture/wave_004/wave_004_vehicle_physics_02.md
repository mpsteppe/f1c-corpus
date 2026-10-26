# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

DERIVED proposal for the vehicle_physics scope. Twenty-three functions grouped into nine evidence-linked classes. (1) CollisionSystem - recursive CollisionTreeTraversal walks a node chain (children at +0x4C, sibling at +0x5C) invoking ShadowVolumeExtrusion per node; CollisionContactBufferAllocator sizes a 32-byte-per-body AABB buffer (count +0x4, pointer +0x8) after PhysicsBufferFree; CollisionThresholdCheck compares a dereferenced +0x388 float against a state-selected threshold; dispatchCollisionParameters forwards the dbl_8AFEA0 parameter and a per-slot float to CollisionStateUpdate; WheelCollisionAndIntegrationDispatcher runs a per-wheel threshold test then dispatches PhysicsIntegrationStep_e620 and PhysicsFloatUpdateWithCompare; CollisionNoiseGenerator does LUT interpolation on an inline 16-entry table; RandomCollisionEvent branches an audio effect on dbl_8AFEA0; CollisionDamageDecayProcessor scans up to 8 damage slots and renders/decays them; CollisionNodeAllocator appends 12-byte nodes to the global list at dword_7CDDF0. (2) CollisionProxyListBuilder (the packet's single DERIVED owner) rebuilds a working list at header 0x1C from a ring-buffer slot and an embedded list, then partitions it. (3) CameraTransformNode - F_3DTransformObjectInit and F_3DTransformObjectInit_83b0 (which calls the former as its base init) fill vtable/flags/projection/scale fields with distinct vtables 0x0059EFEC/0x0059F00C. (4) CameraViewport - CameraViewSetupFromVehiclePosition derives half-extents and sets a 9-view array. (5) TwoDimensionalTransformStruct - a field-by-field 2D transform copy driven by getter helpers. (6) VehicleStateProxy - guarded state query at obj+0x1B79C, conditional delegation, name accessor at obj+0xBC, and an engine-rev read from dword_7C54E0+14844. (7) VehiclePhysicsScaleControl - clamped speed/flag-based scale, control-enable predicate over eight health indicators + control mode + force-feedback, and a 15-field snapshot copy into +0x496C. (8) VehicleAssistSteeringSelector - velocity/threshold/parity jump-table bitmask selection. (9) AnimationPhaseDistributor - distributes time phases to nested element arrays. All addresses, offsets, callers, callees and globals are reported verbatim from the packet; none are invented. Only CollisionProxyListBuilder and the CollisionSystem grouping are DERIVED owners; the remaining classes are GUESS groupings of packet functions with shared field evidence.

## Function roles

- `0x00448DA0` **CollisionSystem** — Recursive collision-tree traversal: for each node calls ShadowVolumeExtrusion (0x00448730), scans four consecutive child pointers at +0x4C and recurses into each non-null child, then follows the sibling link at +0x5C until null; returns the final sibling value. Invoked by CollisionContactResponse (0x00449700).
- `0x004492D0` **CollisionSystem** — AABB contact-buffer allocation: frees the previous buffer via PhysicsBufferFree (0x00449340), and when a2 > 0 stores the count at this+0x4, allocates 32*a2+4 bytes via OperatorNewNhMallocWrapper (0x00587C03), initializes each 32-byte body slot via AABBCollisionBodyInitializer (0x00448E90), and stores the buffer pointer at this+0x8.
- `0x004571E0` **CameraTransformNode** — 3D transform/camera object base initializer: stores the vtable pointer off_59EFEC at this[0], copies a base directory string into byte_5EA438 via StringCopyWithBufferRealloc (0x00566650), then fills projection/scale/range fields (FOV 60.0/45.0, zoom 0.5, far clip 500.0, scale 1.0, parameter 25.0) and zeroes state fields; returns this. Called as the base init by F_3DTransformObjectInit_83b0.
- `0x00457B60` **TwoDimensionalTransformStruct** — Field-by-field copy of a 2D transform/viewport struct: copies an embedded string (null-safe deref 0x00415C30 + buffer-realloc copy 0x00566650), two 3-float vectors (0x00456110/0x00456130), and destination fields from paired-field getter helpers (0x00456040/0x00456060/0x00456080/0x004560A0/0x004560C0/0x004560E0) plus direct copies; writes the square of the source value at byte offset 136 into destination offset 0x8C.
- `0x004583B0` **CameraTransformNode** — 3D camera/transform node initializer: calls base init F_3DTransformObjectInit (0x004571E0), zero-initializes a sub-struct at this+176 via StructFieldZeroInit (0x00457CD0), installs vtable off_59F00C, copies a resource path string into byte_5EA438, zeroes state fields, fills default float parameters, and sets the integer mode field at +0x70 to 2; returns this. Called by MainView (0x0040B850) and sub_4348B0 (0x004348B0).
- `0x0045AF50` **CameraViewport** — Camera/view geometry setup: computes a distance ratio from the double at +0x180 over the double at +0x28, computes a 6-float bounding box via BoundingBoxComputation (0x004DD550), stores half-width at +0x318 and half-height at +0x320, sets the view count at +0x50 to 9, stores the diagonal at +0xCC, zeroes nine 12-byte views at +0x5C, copies nine entries from the source array at +0x58 into a staging buffer, and allocates the vertex/particle buffer via VertexParticleBufferAllocator (0x0054F830).
- `0x0045B840` **CollisionSystem** — Collision damage decay processor: reads a rotating scan start index from +0x31C, clears the active-damage flag at +0x320, runs the init search (0x0045BB00) and cursor-rectangle render (0x0045B660), computes a text-line advance from the scaled screen width global dword_5D6D64, scans up to 8 slots (92-byte stride) for damage at slot+144, renders the damage text via TextRenderDispatcher (0x004DD030), subtracts the cooling rate dbl_8AFE90, and either sets the +0x320 flag or resets the channel via PerIndexStructFieldResetter (0x0045B430); repeats up to 4 passes.
- `0x00461FC0` **VehicleStateProxy** — State query: when the dword at (obj_base + 0x1B79C) is non-zero, where obj_base = *(int*)this, calls sub_563E70 (0x00563E70) and maps (result-1)==0 to 1 and result in {2,3} to 2; otherwise returns 0. Called by ConditionalVehicleStateDelegation (0x00461FF0) and sub_475150 (0x00475150).
- `0x00461FF0` **VehicleStateProxy** — Guarded state delegation: calls VehicleStateQueryAtLargeOffset (0x00461FC0) and returns 0 immediately when it is nonzero; otherwise loads the delegate pointer from *(this) + 0x1B79C and returns the result of the indirect SingleDelegationCall on it. Structural twin of ConditionalNetworkSystemDispatch (0x00461F90). Called by sub_475150 (0x00475150).
- `0x00462E00` **VehicleStateProxy** — String accessor: reads the char* at (obj_base + 0xBC), where obj_base = *(int*)this, and returns it when non-null; otherwise returns the fallback string at global byte_5EA438. Called by VehicleNameToMessageBuffer (0x0047F010) as the vehicle name/description source.
- `0x00462FF0` **VehiclePhysicsScaleControl** — Clamped physics-scale computation for a vehicle slot: picks the input a3 or a default base scale from pointee+4 through the primary pointer at this+0x0, applies a speed-based multiplier when the mph velocity magnitude of the vehicle array element (unk_5EC6D8 + 18624*a2) is below 25.0, multiplies by 4.0 when flag bit 2 at element+0x48BC is clear, and clamps the result to [0.0, 0.5].
- `0x004636A0` **CollisionSystem** — Collision threshold check: reads the float at (*(int*)this)+0x388 and compares it against a state-selected threshold - 20.0 when StateCheckWrapper (0x00461DC0) returns true, else 1.25 - returning true when the value is strictly greater.
- `0x00463D10` **CollisionSystem** — Collision parameter dispatch: loads dbl_8AFEA0, then calls CollisionStateUpdate (0x00500010) with that value, the opaque argument a2, and the float at the (unk_5F0708 + 4656*a1) vehicle-slot offset; always returns 1.
- `0x00463D50` **CollisionSystem** — Wheel collision and integration dispatch: reads a per-wheel threshold from the global float array (unk_5F0708 + 4656*a2), runs CollisionTestWithThreshold (0x00500560), and when the test succeeds dispatches PhysicsIntegrationStep_e620 (0x0045E620) on *this plus PhysicsFloatUpdateWithCompare (0x005000E0) on the wheel state; returns the collision-test result.
- `0x00491AD0` **CollisionProxyListBuilder** — Collision proxy-list rebuild: destroys the previous working list at header offset 0x1C (ListIteratorFullDestruction 0x004910D0), then in two passes copies each source node's four shorts through the pool allocator (0x00490940) into a 12-byte list node (OperatorNewNhMallocWrapper 0x00587C03) appended to the working list, from the ring-buffer slot selected by header 0x4 and the embedded list at header 0x2C; finally partitions the working list against the list at header 0xC via sub_490D00 and returns its result.
- `0x00494DE0` **CollisionSystem** — Collision node allocator: runs sub_53CFE0 (0x0053CFE0) as a duplicate/lookup guard and returns its result; only when it returns zero and the data pointer is non-null allocates a 12-byte node (data at +0, next at +4, flag byte at +8) via OperatorNewNhMallocWrapper (0x00587C03), appends it, and updates the global head/iterator/tail/counter (dword_7CDDF0/0x7CDDF4/0x7CDDF8/0x7CDDFC).
- `0x004962C0` **CollisionSystem** — Piecewise-linear LUT noise generator: maps the input to a table index via CRTFtol (0x00587BDC), issues an interrupt dispatch (0x0058957A), returns 1.0 out of the 16-entry table, otherwise linearly interpolates two adjacent samples from the inline table at float offset 0x162C, applying the per-sample transform sub_5881F0 (0x005881F0) when the blend parameter is >= 0. Invoked by sub_495DC0 (0x00495DC0) for the collision damage system.
- `0x0049B7A0` **VehicleAssistSteeringSelector** — Steering-assist strength bitmask selector (0, 1, 2, 4, 8, 15): above a velocity threshold (VelocityThresholdCheck 0x004F1AA0) picks the full mask 0xF on odd session-time parity else 0; when the current and teammate vehicles share the same team field and the teammate-race flag dword_7C9158 is set, selects a time-derived mask (1, 2, 4, 8) through the jump table at global 0x0049B8B0; else a performance ratio of two vehicle dynamics fields selects a mask through a threshold ladder.
- `0x0049B8F0` **VehicleStateProxy** — Engine-rev value accessor: loads the object pointer held in global dword_7C54E0, adds fixed offset 14844, and returns the 32-bit value stored there. No guards, no callees, no side effects beyond the read.
- `0x0049E520` **CollisionSystem** — Random collision audio event: dispatches an interrupt with dbl_8AFEA0 via InterruptDispatch (0x0058957A), then triggers AudioEffectTrigger (0x0049E4E0) with flag 0 on the low path (value <= 0.5) and flag 1 on the high path (value > 0.5). Invoked by sub_49D4C0 (0x0049D4C0).
- `0x004A3820` **AnimationPhaseDistributor** — Animation phase distributor: computes time-phase subdivisions (0.0, *a2-3.5999999, *a2*0.5, *a2*0.25, *a2*0.75) into a local array, walks this[3] elements (120-byte stride, base this+0x10), and for each 28-byte-stride sub-element reads a phase index at sub+24, computes target = sub[4]-sub[3]+phase[index], and calls RangeProportionInitializer (0x004A1FD0); returns the element count iterated.
- `0x004A6DB0` **VehiclePhysicsScaleControl** — Vehicle control-enable predicate: control is granted only when the session type global (0x007C56A4) is 0 or 7, all eight health/damage indicator fields on the vehicle object (obj+0x834/0x874/0x95C/0x99C/0xA84/0xAC4/0xBAC/0xBEC) are non-zero (or the bypass global dword_7CE814 is set), the control-mode field at obj+0x4064 is neither 1 nor 3, and the force-feedback state check sub_4D21D0 (0x004D21D0) on global 0x008ACEE0 succeeds.
- `0x004B0E30` **VehiclePhysicsScaleControl** — Vehicle data snapshot copy: copies 15 vehicle-state fields from scattered source offsets into a contiguous 60-byte destination block beginning at this+0x496C (14 dwords, one byte from 0xD44 into 0x4984, one float from 0x2390 into 0x4994); no branches, globals or callees; returns 1 unconditionally. Invoked by F_5StepInit (0x004B0720) and SettingsFileInit (0x004B0930).

## Proposed classes

### CollisionSystem

Collision subsystem methods over a shared collision-tree/contact-buffer object plus a global collision-node list: recursive tree traversal with per-node volume extrusion, 32-byte-slot AABB contact-buffer allocation, state-selected collision threshold checking, parameter/wheel-collision dispatch into the collision-state engine and wheel physics step, inline-table noise generation, audio-effect selection, per-frame damage-slot decay with UI text rendering, and appending nodes to the global list at dword_7CDDF0. Class identity of the shared 'this' is GUESS; the field evidence per method is DERIVED from the raw bodies.

Methods: `0x00448DA0`, `0x004492D0`, `0x004636A0`, `0x00463D10`, `0x00463D50`, `0x00494DE0`, `0x004962C0`, `0x0049E520`, `0x0045B840`

- `this+0x00000000` `void* objectChainPtr` (read, DERIVED)
- `this+0x0000004C` `void*[4] childSlotArray` (read, DERIVED)
- `this+0x0000005C` `void* siblingLink` (read, DERIVED)
- `this+0x00000004` `int contactBodyCount` (write, DERIVED)
- `this+0x00000008` `void* contactBodyArray` (write, DERIVED)
- `obj+0x00000388` `float thresholdValue` (read, GUESS)
- `this+0x0000031C` `int damageScanStartIndex` (read, DERIVED)
- `this+0x00000320` `byte activeDamageFlag` (read_write, DERIVED)

### CollisionProxyListBuilder

Rebuilds and partitions a collision proxy working list: destroys the previous working list, copies node payloads (four shorts per source node) from a ring-buffer slot and an embedded list through a pool allocator into 12-byte list nodes, and partitions the rebuilt list against a target list. Owner trust DERIVED (from the packet); class layout is inferred from the header fields.

Methods: `0x00491AD0`

- `this+0x00000000` `void* selfPointer` (read, DERIVED)
- `obj+0x00000004` `int ringBufferIndex` (read, DERIVED)
- `obj+0x00000008` `void* ringBufferBase` (read, DERIVED)
- `obj+0x0000001C` `void* workingList` (read_write, DERIVED)
- `obj+0x00000020` `void* workingListHead` (write, DERIVED)
- `obj+0x00000024` `void* workingListTail` (write, DERIVED)
- `obj+0x00000028` `int workingListCount` (write, DERIVED)
- `obj+0x0000002C` `void* embeddedListSentinel` (read, DERIVED)
- `obj+0x00000034` `void* sentinelCurrent` (read_write, DERIVED)
- `*(obj+0x2C)+0x00000000` `void* embeddedListHead` (read, DERIVED)
- `*(obj+0x34)+0x00000004` `void* currentNodeNext` (read, DERIVED)
- `*(*(obj+0x34)+0x4)+0x00000000` `void* nextNode` (read, GUESS)
- `*(*(obj+0x2C)+0x0)+0x00000000` `int16 sourceNodeShort0` (read, GUESS)
- `*(*(obj+0x2C)+0x0)+0x00000002` `int16 sourceNodeShort1` (read, GUESS)
- `*(*(obj+0x2C)+0x0)+0x00000004` `int16 sourceNodeShort2` (read, GUESS)
- `*(*(obj+0x2C)+0x0)+0x00000006` `int16 sourceNodeShort3` (read, GUESS)

### CameraTransformNode

3D camera/transform node: base initializer F_3DTransformObjectInit fills vtable, state, projection (FOV 60.0/45.0), zoom, far-clip and scale fields; the derived initializer F_3DTransformObjectInit_83b0 runs the base init, zero-initializes a sub-struct at +176, installs a second vtable (0x0059F00C) and sets the mode field at +0x70 to 2. Common ownership between the two is proven by the base-init call from 0x004583B0 to 0x004571E0.

Methods: `0x004571E0`, `0x004583B0`

- `this+0x00000000` `void* vtablePtr` (write, DERIVED)
- `this+0x00000004` `int stateDword0` (write, GUESS)
- `this+0x00000008` `int invalidHandleSentinel` (write, DERIVED)
- `this+0x0000000C` `int stateDword1` (write, GUESS)
- `this+0x00000010` `int stateDword2` (write, GUESS)
- `this+0x00000014` `int stateDword3` (write, GUESS)
- `this+0x00000018` `int stateDword4` (write, GUESS)
- `this+0x0000001C` `int stateDword5` (write, GUESS)
- `this+0x00000020` `int stateDword6` (write, GUESS)
- `this+0x00000024` `int stateDword7` (write, GUESS)
- `this+0x00000028` `int stateDword8` (write, GUESS)
- `this+0x0000002C` `int stateDword9` (write, GUESS)
- `this+0x00000030` `float fovMain` (write, DERIVED)
- `this+0x00000034` `float fovAux` (write, DERIVED)
- `this+0x00000038` `float fovMain2` (write, DERIVED)
- `this+0x0000003C` `float fovAux2` (write, DERIVED)
- `this+0x00000040` `float zoomScale` (write, DERIVED)
- `this+0x00000044` `float farClipRange` (write, DERIVED)
- `this+0x00000048` `float axisScale0` (write, DERIVED)
- `this+0x0000004C` `float axisScale1` (write, DERIVED)
- `this+0x00000050` `float axisScale2` (write, DERIVED)
- `this+0x00000054` `float dampingScale0` (write, GUESS)
- `this+0x00000058` `float dampingScale1` (write, GUESS)
- `this+0x0000005C` `int zeroedDwordA` (write, GUESS)
- `this+0x00000060` `byte zeroedByte` (write, GUESS)
- `this+0x00000064` `int zeroedDwordB` (write, GUESS)
- `this+0x00000068` `int zeroedDwordC` (write, GUESS)
- `this+0x0000006C` `int zeroedDwordD` (write, GUESS)
- `this+0x00000070` `int activeModeFlag` (write, DERIVED)
- `this+0x00000074` `int zeroedDwordE` (write, GUESS)
- `this+0x00000078` `int zeroedDwordF` (write, GUESS)
- `this+0x0000007C` `int zeroedDword10` (write, GUESS)
- `this+0x00000080` `int zeroedDword11` (write, GUESS)
- `this+0x00000084` `int zeroedDword12` (write, GUESS)
- `this+0x00000088` `float paramFloat` (write, DERIVED)
- `this+0x00000090` `int zeroedDword13` (write, GUESS)
- `this+0x00000094` `int zeroedDword14` (write, GUESS)
- `this+0x00000098` `int zeroedDword15` (write, GUESS)
- `this+0x0000009C` `byte zeroedByte1` (write, GUESS)
- `this+0x000000A0` `byte zeroedByte2` (write, GUESS)
- `this+0x000000A4` `int zeroedDword16` (write, GUESS)
- `this+0x000000A8` `int zeroedDword17` (write, GUESS)
- `this+0x000000AC` `float axisScale3` (write, GUESS)

### CameraViewport

Camera view geometry: derives a distance ratio from two doubles (+0x180/+0x28), computes a bounding box, stores half-width/half-height (+0x318/+0x320) and a diagonal (+0xCC), and configures a 9-view array (+0x50 count, +0x58 source array, +0x5C view array) feeding a vertex/particle buffer allocation. Struct identity is GUESS; the field evidence is DERIVED from the raw body.

Methods: `0x0045AF50`

- `this+0x00000028` `double ratioDivisor` (read, DERIVED)
- `this+0x00000050` `int viewCount` (write, DERIVED)
- `this+0x00000058` `void* viewSourceArray` (read, DERIVED)
- `this+0x0000005C` `void* viewArray` (write, DERIVED)
- `this+0x000000CC` `float viewDiagonal` (write, DERIVED)
- `this+0x00000180` `double ratioNumerator` (read, DERIVED)
- `this+0x00000318` `double halfWidth` (write, DERIVED)
- `this+0x00000320` `double halfHeight` (write, DERIVED)

### TwoDimensionalTransformStruct

2D transform/viewport struct copy: field-by-field copy of an embedded string and two 3-float vectors, with the remaining float/pair/int fields filled from source getter helpers and direct copies, and one squared-value write at +0x8C. Struct identity and the semantic role of each copied field are GUESS; the offsets are DERIVED from the raw body.

Methods: `0x00457B60`

- `this+0x00000030` `float fieldPairA0` (write, DERIVED)
- `this+0x00000034` `float fieldPairA1` (write, DERIVED)
- `this+0x00000038` `float fieldPairB0` (write, DERIVED)
- `this+0x0000003C` `float fieldPairB1` (write, DERIVED)
- `this+0x00000040` `float fieldPairC0` (write, DERIVED)
- `this+0x00000044` `float fieldPairC1` (write, DERIVED)
- `this+0x00000048` `float singleFloat0` (write, DERIVED)
- `this+0x0000004C` `float fieldPairD0` (write, DERIVED)
- `this+0x00000050` `float fieldPairD1` (write, DERIVED)
- `this+0x00000054` `float viewportDimension0` (write, GUESS)
- `this+0x00000058` `float viewportDimension1` (write, GUESS)
- `this+0x0000005C` `float singleFloat1` (write, DERIVED)
- `this+0x00000060` `byte singleByte` (write, DERIVED)
- `this+0x00000064` `float tripleField0` (write, DERIVED)
- `this+0x00000068` `float tripleField1` (write, DERIVED)
- `this+0x0000006C` `int tripleField2` (write, DERIVED)
- `this+0x00000070` `dword dwordBlock0` (write, DERIVED)
- `this+0x00000074` `dword dwordBlock1` (write, DERIVED)
- `this+0x00000078` `dword dwordBlock2` (write, DERIVED)
- `this+0x0000007C` `dword dwordBlock3` (write, DERIVED)
- `this+0x00000080` `dword dwordBlock4` (write, DERIVED)
- `this+0x00000084` `dword dwordBlock5` (write, DERIVED)
- `this+0x00000088` `float copiedFloat` (write, DERIVED)
- `this+0x0000008C` `float squaredFloat` (write, DERIVED)
- `this+0x00000090` `dword dwordTail0` (write, DERIVED)
- `this+0x00000094` `dword dwordTail1` (write, DERIVED)
- `this+0x00000098` `dword dwordTail2` (write, DERIVED)

### VehicleStateProxy

Vehicle-state access layer: guarded state query against the object chain (obj+0x1B79C), conditional delegation through a delegate pointer at that offset, a vehicle-name string accessor (obj+0xBC) with a global fallback, and a raw engine-rev read from dword_7C54E0+14844. Class identity is GUESS; field evidence is DERIVED from the raw bodies.

Methods: `0x00461FC0`, `0x00461FF0`, `0x00462E00`, `0x0049B8F0`

- `this+0x00000000` `void* objectBasePtr` (read, DERIVED)
- `obj+0x0001B79C` `void* stateQueryDelegate` (read, DERIVED)
- `obj+0x000000BC` `char* vehicleNameString` (read, DERIVED)

### VehiclePhysicsScaleControl

Vehicle-side physics scale and control gating: computes a clamped physics scale factor from a base scale, mph speed and a vehicle flag; predicates whether vehicle controls may be enabled from session type, eight health/damage indicators, a control-mode field and force-feedback state; and captures a 15-field vehicle-state snapshot into a contiguous +0x496C block. Class identity is GUESS; all offsets are DERIVED from the raw bodies.

Methods: `0x00462FF0`, `0x004A6DB0`, `0x004B0E30`

- `this+0x00000000` `void* objectBasePtr` (read, DERIVED)
- `obj+0x00000004` `float defaultBaseScale` (read, GUESS)
- `obj+0x00000834` `dword healthIndicator0` (read, DERIVED)
- `obj+0x00000874` `byte healthIndicator1` (read, DERIVED)
- `obj+0x0000095C` `dword healthIndicator2` (read, DERIVED)
- `obj+0x0000099C` `byte healthIndicator3` (read, DERIVED)
- `obj+0x00000A84` `dword healthIndicator4` (read, DERIVED)
- `obj+0x00000AC4` `byte healthIndicator5` (read, DERIVED)
- `obj+0x00000BAC` `dword healthIndicator6` (read, DERIVED)
- `obj+0x00000BEC` `byte healthIndicator7` (read, DERIVED)
- `obj+0x00004064` `int controlMode` (read, DERIVED)
- `this+0x00000654` `dword snapshotSource0` (read, DERIVED)
- `this+0x00000888` `dword snapshotSource1` (read, DERIVED)
- `this+0x00000984` `dword snapshotSource2` (read, DERIVED)
- `this+0x00000A80` `dword snapshotSource3` (read, DERIVED)
- `this+0x00000B7C` `dword snapshotSource4` (read, DERIVED)
- `this+0x00000C78` `dword snapshotSource5` (read, DERIVED)
- `this+0x00000D44` `byte snapshotSource6` (read, DERIVED)
- `this+0x0000209C` `dword snapshotSource7` (read, DERIVED)
- `this+0x00002198` `dword snapshotSource8` (read, DERIVED)
- `this+0x00002294` `dword snapshotSource9` (read, DERIVED)
- `this+0x00002390` `float snapshotSource10` (read, DERIVED)
- `this+0x0000248C` `dword snapshotSource11` (read, DERIVED)
- `this+0x00002588` `dword snapshotSource12` (read, DERIVED)
- `this+0x0000275C` `dword snapshotSource13` (read, DERIVED)
- `this+0x00002858` `dword snapshotSource14` (read, DERIVED)
- `this+0x0000496C` `dword snapshotDest0` (write, DERIVED)
- `this+0x00004970` `dword snapshotDest1` (write, DERIVED)
- `this+0x00004974` `dword snapshotDest2` (write, DERIVED)
- `this+0x00004978` `dword snapshotDest3` (write, DERIVED)
- `this+0x0000497C` `dword snapshotDest4` (write, DERIVED)
- `this+0x00004980` `dword snapshotDest5` (write, DERIVED)
- `this+0x00004984` `byte snapshotDest6` (write, DERIVED)
- `this+0x00004988` `dword snapshotDest7` (write, DERIVED)
- `this+0x0000498C` `dword snapshotDest8` (write, DERIVED)
- `this+0x00004990` `dword snapshotDest9` (write, DERIVED)
- `this+0x00004994` `float snapshotDest10` (write, DERIVED)
- `this+0x00004998` `dword snapshotDest11` (write, DERIVED)
- `this+0x0000499C` `dword snapshotDest12` (write, DERIVED)
- `this+0x000049A0` `dword snapshotDest13` (write, DERIVED)
- `this+0x000049A4` `dword snapshotDest14` (write, DERIVED)

### VehicleAssistSteeringSelector

Selects a steering-assist strength bitmask for a vehicle: velocity-threshold path, session-time parity path, teammate-race time-derived jump-table path, and a performance-ratio threshold ladder. No this-fields are evidenced; all inputs are globals (dword_7C54DC/E0/E4/F0, dword_7C9158, dbl_8AFEA0, jump table at 0x0049B8B0). Class identity is GUESS.

Methods: `0x0049B7A0`


### AnimationPhaseDistributor

Distributes time-phase subdivisions onto nested per-element structures: walks this[3] elements (base this+0x10, 120-byte stride), and for each 28-byte-stride sub-element computes a target range from a phase-indexed lookup and calls RangeProportionInitializer. Prior analysis ties this to PitStopOperationTimer-driven multi-channel animation timing. Class identity is GUESS.

Methods: `0x004A3820`

- `this+0x0000000C` `int elementCount` (read, DERIVED)
- `this+0x00000010` `void* elementArray` (read, DERIVED)

## Compatibility contracts

- **CollisionTreeLayoutContract** — A replacement collision tree must expose per node: four consecutive child pointers starting at offset 0x4C (0x4C..0x58) and a sibling/next link at offset 0x5C that terminates the walk when null. Traversal must invoke the per-node extrusion callback (0x00448730) and recurse into each non-null child slot, and must return the final sibling value.
- **AABBCollisionBodyBufferLayout** — A replacement collision contact buffer must preserve: body count at this+0x4, body-array pointer at this+0x8, per-body slot size 32 bytes, and a single allocation of 32*count+4 bytes whose header stores the count; each slot is initialized by AABBCollisionBodyInitializer (0x00448E90) and the previous buffer is freed via PhysicsBufferFree (0x00449340) before allocation.
- **CollisionThresholdDispatchContract** — A replacement collision dispatch must preserve the parameter flow: dispatchCollisionParameters forwards the dbl_8AFEA0 parameter, an opaque argument, and a per-vehicle-slot float (4656-byte stride over the unk_5F0708 array) to CollisionStateUpdate (0x00500010); WheelCollisionAndIntegrationDispatcher tests a per-wheel threshold via CollisionTestWithThreshold (0x00500560) and, on success, runs PhysicsIntegrationStep_e620 (0x0045E620) and PhysicsFloatUpdateWithCompare (0x005000E0); CollisionThresholdCheck compares the float at (*(int*)this)+0x388 against a threshold of 20.0 when StateCheckWrapper (0x00461DC0) is true else 1.25.
- **CollisionNodeListLayout** — A replacement collision node list must expose the global head/iterator/tail/counter at dword_7CDDF0/0x7CDDF4/0x7CDDF8/0x7CDDFC and append 12-byte nodes with a data pointer at +0, next pointer at +4 and flag byte at +8; allocation must be guarded by the sub_53CFE0 duplicate lookup (which returns non-zero when a duplicate exists) and by the data pointer being non-null.
- **CameraTransformInitProtocol** — A replacement 3D camera/transform object must reproduce the initializer field shape: vtable at +0x0 (off_59EFEC, then off_59F00C on the derived node), invalid-handle sentinel -1 at +0x8, FOV 60.0/45.0 at +0x30/+0x34/+0x38/+0x3C, zoom 0.5 at +0x40, far clip 500.0 at +0x44, axis scale 1.0 at +0x48/+0x4C/+0x50, damping 0.5 at +0x54/+0x58, active/mode flag at +0x70 (1 on base, 2 on derived), parameter 25.0 at +0x88, and the base-directory/resource-path string copy through StringCopyWithBufferRealloc into byte_5EA438.
- **VehicleStateAccessProtocol** — A replacement state-access layer must preserve: the guarded state query at obj+0x1B79C mapping sub_563E70 results to the codes 1 (state 1) and 2 (states 2/3) with 0 otherwise; the delegation through the object chain at *(this)+0x1B79C gated by that query; the vehicle-name read at obj+0xBC with fallback to byte_5EA438; and the engine-rev read at dword_7C54E0+14844.
- **VehicleControlEnableProtocol** — A replacement control-enable predicate must require: session type global 0x007C56A4 equal to 0 or 7; all eight health/damage indicator fields (obj+0x834/0x874/0x95C/0x99C/0xA84/0xAC4/0xBAC/0xBEC) non-zero unless the bypass global dword_7CE814 is set; the control-mode field at obj+0x4064 not equal to 1 or 3 (value 2 does not disable); and a non-zero result from the force-feedback state check sub_4D21D0 on global 0x008ACEE0.
- **VehicleDataSnapshotBlockLayout** — A replacement vehicle snapshot must copy exactly these 15 fields into the contiguous block at +0x496C..+0x49A4 (14 dwords, one byte from 0xD44 into 0x4984, one float from 0x2390 into 0x4994): sources 0x654, 0x888, 0x984, 0xA80, 0xB7C, 0xC78, 0xD44(byte), 0x209C, 0x2198, 0x2294, 0x2390(float), 0x248C, 0x2588, 0x275C, 0x2858 into destinations 0x496C, 0x4970, 0x4974, 0x4978, 0x497C, 0x4980, 0x4984(byte), 0x4988, 0x498C, 0x4990, 0x4994(float), 0x49A4, 0x4998, 0x499C, 0x49A0 respectively, returning 1 unconditionally.
- **CollisionDamageDecayProtocol** — A replacement damage-decay processor must scan up to 8 damage slots (92-byte stride over the owner object) starting from the rotating index at this+0x31C, stop at the first slot whose damage at slot+144 is greater than 0.0, render the damage text at slot+60 with the value at slot+140 via TextRenderDispatcher (0x004DD030), subtract the global cooling rate dbl_8AFE90 from the slot damage, set the active-damage flag at this+0x320 when damage remains, and otherwise reset the channel via PerIndexStructFieldResetter (0x0045B430); the pass repeats up to 4 times per frame.

## Unresolved

- The concrete owning classes of most functions are unknown; owners were left as UnknownObject at the packet level and every class here except CollisionSystem and CollisionProxyListBuilder is a GUESS grouping of packet functions with shared field evidence.
- CollisionTreeTraversal passes no explicit argument to its recursive self-call in the decompiled text; the node argument is presumably implicit. The four-slot child array at 0x4C..0x58 is DERIVED from the loop shape; only 0x4C and 0x5C are packet field refs.
- The owner object of CollisionContactBufferAllocator's this+0x4/this+0x8 is unidentified, and the meaning of its returned pointer for the caller (caller:0x0044B370, unresolved) is unknown.
- The exact semantic role of every copied field in F_2DTransformStructCopy (position vs scale vs viewport/clip vs transform parameters), the string at source+4, and the value at source+136 squared into destination+0x8C are unknown.
- F_3DTransformObjectInit_83b0 zero-initializes a sub-struct at this+176 via StructFieldZeroInit, but that offset is not a packet field ref and was not asserted as a field.
- The concrete object type behind CameraViewSetupFromVehiclePosition is unknown; the 9 view structures at +0x5C and the source array at +0x58 (frustum planes vs camera state) are not established by this packet, and no callers are recorded.
- For CameraViewSetupFromVehiclePosition the bounding-box vector layout (interleaved min/max pairs box[0]/box[3], box[1]/box[4], box[2]/box[5]) is inferred; global dbl_59E880 is recorded as read but does not appear literally in the raw body (presumed 0.5 half-extent constant, GUESS).
- The physical meaning of the damage-decay slot data (stride 92, damage at slot+144, text position at slot+60) is inferred, not runtime-proven; the exact text content and formatting arguments to TextRenderDispatcher are UI-determined.
- VehicleStateQueryAtLargeOffset: the meaning of the checked dword at obj+0x1B79C, the full return domain of sub_563E70, and the semantic meaning of return codes 1 and 2 are not confirmed.
- ConditionalVehicleStateDelegation's SingleDelegationCall appears in the raw source text but has no callee address in the packet; its target address is unknown.
- The string at obj+0xBC (vehicle name versus description) and the fallback content of byte_5EA438 are not confirmed.
- ClampedPhysicsScaleWithThreshold: the identity of the object whose primary pointer at +0x0 reaches a default base scale at pointee+4, the mapping of literals (2.2369363 mph factor, 25.0, 4.0, 0.5) to the flagged globals, and the role of flag bit 2 at vehicle element+0x48BC are unknown.
- CollisionThresholdCheck: the meaning of the compared value at +0x388 and which object state StateCheckWrapper tests are unknown.
- dispatchCollisionParameters: the array base unk_5F0708 is not an allowed packet ref, so the 4656-byte-stride vehicle-slot interpretation is a GUESS; dbl_8AFEA0 is typed double but consumed through LODWORD as a float.
- WheelCollisionAndIntegrationDispatcher: v6 (edx) is passed to PhysicsIntegrationStep_e620 without explicit initialization (register-derived), and the recorded caller label 'TeamColorLoader' (0x004F03E0) is not in the allowed caller refs and does not obviously match collision-dispatch behaviour.
- RebuildCollisionProxyList: the meaning of the four shorts read per source node (AABB box vs other payload) and the relationship between the ring-buffer source list and the embedded list at header 0x2C are inferred, not confirmed; the partition target at header 0xC and the meaning of sub_490D00's return are unknown.
- CollisionNodeAllocator: the roles of the global head/iterator/tail pointers are DERIVED names; the constant 67585 passed to sub_53CFE0 is an opaque lookup key; the owner of the dword_7CDDF0 global list is unknown.
- CollisionNoiseGenerator: the transform sub_5881F0 is called for its side effect; the inline 16-entry table at float offset 0x162C is set up elsewhere; four flagged globals (flt_59E43C, flt_59E440, flt_59EED0, dbl_5AC9D0) do not appear in the raw body.
- VehicleAssistSteeringBitmaskSelector: the float globals flt_59E478, flt_59E824, flt_5ACAE8, flt_5ACAEC, flt_5ACAF0 are flagged but appear nowhere in the raw source; the field at vehicle+18580 is interpreted as a team identifier and dword_7C9158 as a teammate-race flag from call-site context only; the ratio fields at dword_7C54E0+14752/+14756 and the ladder thresholds (0.9, 0.93, 0.96, 0.977) are inferred.
- EngineRevValueAccessor: the type of the object at dword_7C54E0 and the meaning of offset 14844 are not established; the engine-rev reading is a canonical-name lead, not packet evidence.
- RandomCollisionEvent: the 0.5 threshold and dbl_8AFEA0 are interpreted as session time by prior analysis (DERIVED); dbl_59E420 and dbl_59E880 are flagged but not verifiable here; the meaning of a1 (audio-source handle) is caller-supplied.
- AnimationPhaseDistributor: the 28-byte sub-element layout (float pair at 3/4, phase index at +24) is read via raw offsets and not defined; the 3.5999999 offset and the 0.25/0.5/0.75 proportions depend on the caller's animation model (prior analysis: PitStopOperationTimer); four flagged globals (flt_59E450, flt_59E7F8, flt_59E7FC, flt_5ACAF4) are unverifiable from this packet.
- VehicleControlEnabled: the exact physical meaning of the eight health/damage fields (which pair maps to which wheel or damage region), the role of dword_7CE814 as a qualifying/DSQ bypass, and the semantics of control-mode values at obj+0x4064 are not confirmed independently.
- VehicleDataFieldCopy: the field semantics of the 15 source offsets and the snapshot block are not documented; the snapshot's consumer is not established here.
- Several flagged-but-ungrounded globals (flt_59E43C, flt_59E440, flt_59E450, flt_59E46C, flt_59E478, flt_59E7F8, flt_59E7FC, flt_59E824, flt_59E860, flt_59E8A0, flt_59E8EC, flt_59EED0, flt_59F078, flt_59F124, flt_59F128, dbl_5AC9D0, flt_5ACAE8, flt_5ACAEC, flt_5ACAF0, flt_5ACAF4, dbl_59E420, dbl_59E880, dword_8AFE64) appear nowhere in the raw decompiled bodies; their roles are unknown or inherited from existing-analysis prose, so they are carried in unresolved_evidence_refs rather than asserted.
- The global fallback string byte_5EA438 (0x005EA438) is shared by F_3DTransformObjectInit, F_3DTransformObjectInit_83b0 and VehicleNameAccessor; whether the transform inits read it as a resource-path source and the name accessor reads it as a placeholder is inferred from call shapes, not proven.
- The 4656-byte stride over unk_5F0708 used by dispatchCollisionParameters and WheelCollisionAndIntegrationDispatcher is read from raw source only; the array base is not an allowed packet ref.
