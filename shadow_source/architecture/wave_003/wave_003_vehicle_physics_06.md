# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

DERIVED proposal for the vehicle_physics scope. Eight functions split into four evidence-linked groups: (1) suspension simulation - computeSuspensionForces transforms body-space corner offsets through the vehicle rotation matrix, computes a clamped feedback factor from the volume-coefficient globals (dword_5D6798..dword_5D67AC, flt_7CF2F0/7CF338/7CF35C), and dispatches each active corner through the handler table at this+0x6D8 (virtual slots +4/+8); (2) vehicle physics configuration parsing - loadVehicleSoundConfig reads the audio config file (VS_INSIDE/VS_OUTSIDE sections, 46 sound-sample keys, EngineRPMSound ranges, 15 float parameters) and publishes volume coefficients, while VehiclePhysicsJointSystemLoader two-pass-parses the Body/Joint/Hinge/Bar joint-system file and sizes/initialises a linear solver whose matrix/row-pointer/solution buffers live on the container; (3) vehicle scene-node rendering - SceneRenderTransform and BuildSceneNodeTransformMatrix update the scene node orientation/camera and build its 4x4 world transform under the flag protocol at this+0x3C, and VertexBufferTransform pushes vertex-buffer data through the D3D device (dword_8B8F24) guarded by the 0x4000000 done flag; (4) vehicle-driven display/camera state - GraphicsDisplayStateSyncWithVehicle pushes the vehicle dashboard state to the D3D device through vtable slot 0xC8 (mode map 0x20000->3, 0x40000->1, 0x80000->2), and WheelShadowCameraUpdate recursively updates the wheel shadow-map camera from the wheel angle. Only three owners are DERIVED (VehicleSoundConfigLoader, VehicleSuspensionForces, VehicleJointSystem); the remaining owners are UnknownObject and their concrete class identity is deliberately left as GUESS groupings rather than asserted. All fields, callees, globals, and callers are reported verbatim from the packet; none are invented.

## Function roles

- `0x004F7460` **UnknownObject** — Parses the vehicle audio configuration file: opens the stream (AudioStreamOpen 0x00566B20), reads lines via ConditionalDispatchBasedOnFlag (0x00566CC0), skips lines flagged by sub_5651B0, and switches the parse cursor on VS_INSIDE/VS_OUTSIDE section markers (0x00588640). Inside the sections it matches 46 KEY=%s sound-sample patterns (0x005887ED) and stores matched file paths via StringCopyWithBufferRealloc (0x00566650); outside, EngineRPMSound keywords (0x00565760) load RPM-range sound profiles into the owner object via ResourceLookupDispatcher/RPMRangeLoader (0x00566E20, 0x004F6BF0), else 15 named float parameters are read through sub_565870 into locals and the dword_5D67B0..flt_5D67D0 globals. After the loop it closes the stream (0x00566B90) and, when each player/non-player volume triple sums to 1.0, stores the coefficients into dword_5D6798..dword_5D67AC. Returns 1 on stream-open failure, else the parse flag (0).
- `0x004F8440` **UnknownObject** — Per-corner suspension force computation: transforms three body-space corner offsets through the 3x3 rotation matrix (this+0x14..0x40) plus world offset (this+0x8/0xC/0x10) into contact point v17; when the float at this+0x9C is non-zero pushes an indexed field via PerIndexStructFieldSetter (0x004F8850). Gated by bit 2 of the vehicle physics flags dword (obj+0x48BC via *this). Selects the per-corner data bank (this+405 vs this+422 by the byte at this+0xB0), computes a clamped feedback factor v14 from this+0x84/0x88/0x8C/0x90 and the dword_5D6798..5D67AC / flt_7CF2F0/7CF338/7CF35C globals under the formula chosen by sub_4C7BD0, feeds ParametricInterpolationBlending (0x004F6D90), then loops i=5..44 dispatching each active corner's force handler through the table at this+0x6D8 (virtual slot +4), clearing the corner active flag; the +8 virtual slot runs when the handler sub-type equals 1. Returns the carried byte.
- `0x00548C20` **UnknownObject** — Scene-node transform update: when the dual-matrix trigger at this+0x8 is non-null resolves a transform via DualMatrixTransformMultiply (0x0054B530), negates the outputs with a 1.5 Y-offset, updates the orientation rotation matrix (0x00541D10) and applies a pi/2 Euler rotation (0x00541DB0). When the scene entry a2 reports a positive count at a2+372 it runs the pre-step sub_5572B0, TransformWheelForcesToChassis (0x00541A70), CameraProjectionUpdate with parameter 14 (0x00541B70), a recursive child traversal loop (0x00556930, 24-byte stride) and delegates to sub_5550E0(a2, *this). Otherwise returns the count at a2+372.
- `0x0054B570` **UnknownObject** — Builds the 4x4 world transform for a scene node: clears/checks flag bits 0x2100/0x40 on the transform flags at this+0x3C (BitmaskClear 0x0054B330), applies optional Euler sign adjustments (0x2000/0x100) into the 0x2C/0x30/0x34 fields, rebuilds the rotation matrix at this+0x6C from the 0x60/0x64/0x68 Euler fields when dirty bit 0x20 is set (EulerAngleToRotationMatrix 0x0053B240, MultiFieldSetter 0x0053B200), fills the selected buffer (scratch/alternate-at-0x40/primary) from sin/cos of the 0x2C/0x30/0x34 angles and the translation at 0x20/0x24/0x28, sets bit 0x40, updates through TransformationMatrixUpdate (0x0054B770), copies the matrix to the 0x114..0x150/0x154 slots, and clears dirty bits on caller a3. Returns 1 when freshly computed, else 0.
- `0x0054C6C0` **UnknownObject** — Transforms vertex-buffer data through the D3D device (global dword_8B8F24) using the object's position (this+0x100..0x108) and Euler inputs (this+0x10C..0x114), guarded by the 0x4000000 done flag at this+0x14. Per element (count this+0x118, base this+0x11C, 64-byte stride) it branches on flags bit 0x800000 (mask global 0x00800000) between 16-DWORD and 12-DWORD vertex strides, dispatches two indirect D3D transforms into a scratch buffer, and writes position/normal back when bit 0x10 at *(this+0x138)+0x3C is clear; resets each element control entry; then recomputes the bounding box (0x0054D520, 0x0054E270), runs sub_54D080/FlagSetLoop (0x0054D080/0x0054E080), clears the six transform inputs, allocates a 452-byte block into this+0x110 (8 sub-structs, 14-dword stride), and ORs the done flag. Returns 0.
- `0x00556040` **UnknownObject** — Synchronizes vehicle-derived dashboard display state onto the D3D device at this+0x1100 through its vtable slot 0xC8. When the vehicle state flags at a2+412 have no display bit ((flags & 0xE0000) == 0) it disables the display (this+0x14F0=0, setter param 28/arg 0); otherwise it enables and lazily pushes a packed 16-bit dashboard combination (a2+392/394/396, param 34), three floats (a2+404/408/400, params 36/37/38) and a mode value mapped from a2+412 (0x20000->3, 0x40000->1, 0x80000->2, else the raw vehicle pointer) via param 35 when capability bit 0x4000 at this+0x13A8 is set, param 140 when bit 0x8000 is set, else disables again. All pushed values are cached at this+0x14F4..0x1504 to skip redundant calls. Returns 0.
- `0x00560FE0` **UnknownObject** — Recursive shadow-map camera update for a vehicle wheel node: dereferences the wheel list head from this+0xC, selects a wheel slot (96-byte stride, indexed through the nested wheel-data chain) based on StructFieldGetter(dword_8B78A0), pushes suspension parameters (0x00542560), bails to -2 when the suspension state pointer at *(this+0xC)+0x19C is null or its +24 flags lack the suspension flag, branches on render/camera state, computes a frustum half-angle (2*fabs(atan2(wheelAngle*1.2, flt_5DD848))), traverses the wheel list (0x005457C0/0x0055D590), issues sub_542050 / TwoFieldSetterCall (0x00542050/0x005423C0), reads the scene node position (0x0054B950/0x0054B420), and runs the orientation/projection/chassis updates (0x00541D10/0x00541B70/0x00541A70), dispatches sub_55C070(dword_8B78A0, this), records a flag on this+0x24, then recurses into sibling wheel nodes at this+0x2C / this+0x34. Returns -2 on bail/cleanup paths, else 0.
- `0x0056D930` **UnknownObject** — Two-pass parser and solver initializer for the vehicle physics joint-system configuration file. Pass one counts Body/Joint/Hinge/Bar/AJointHinge keyword records (0x00587C20) so the per-entity arrays can be sized; pass two parses each record's name/mass/inertia/transform groups (0x00565520/0x00565AA0), resolves copy/positive/negative body names (0x00588410) emitting error strings to a buffer, and links joints/hinges/bars to bodies. It then allocates the solver matrix (8*N*N) and row-pointer array (4*N), zero-fills and runs the default init routine (0x0056D880), negotiates with solver instances via sub_579F89, falls back to a default solver (0x0056C830), links every body entry to the solver buffers, and finalises the stream (0x005355A0). Returns 0 on success, -1 on any parse error.

## Proposed classes

### VehicleSoundConfigLoader

Loads the vehicle audio configuration file: opens the stream, switches parse cursor on VS_INSIDE/VS_OUTSIDE section markers, extracts 46 sound-sample path keys, loads EngineRPMSound ranges and 15 named float parameters, and publishes normalized player/non-player volume coefficients to the dword_5D6798..dword_5D67AC globals and sound paths to the 0x5D67FB..0x5D6D03 globals. No this-fields are evidenced (the RPM-range arrays live at float element indices 405/422 on an unknown owner object).

Methods: `0x004F7460`


### VehicleSuspensionForces

Computes per-corner suspension forces for a vehicle: transforms body-space corner offsets through the rotation matrix at +0x14..+0x40 plus the world offset at +0x8/+0xC/+0x10, selects a per-corner data bank by the byte at +0xB0, derives a clamped brake/steering feedback factor from +0x84/+0x88/+0x8C/+0x90 and the volume-coefficient globals, and dispatches each active corner through the handler table at +0x6D8.

Methods: `0x004F8440`

- `this+0x00000008` `float worldOffsetX` (read, DERIVED)
- `this+0x0000000C` `float worldOffsetY` (read, DERIVED)
- `this+0x00000010` `float worldOffsetZ` (read, DERIVED)
- `this+0x00000014` `float[12] bodyRotationMatrix` (read, DERIVED)
- `this+0x00000084` `float feedbackBlendMin` (read, GUESS)
- `this+0x00000088` `float feedbackBlendParam` (read, GUESS)
- `this+0x0000008C` `float feedbackBlendScale` (read, GUESS)
- `this+0x00000090` `float feedbackPedalInput` (read, GUESS)
- `this+0x0000009C` `float indexedFieldValue` (read, GUESS)
- `this+0x000000A0` `float indexedFieldValue2` (read, GUESS)
- `this+0x000000B0` `byte cornerBankSelector` (read, GUESS)
- `this+0x000006D8` `void** cornerHandlerTable` (read, DERIVED)

### VehiclePhysicsObject

Object pointed to by this+0x0 of the suspension simulation; carries the vehicle physics flags dword at obj+0x48BC whose bit 2 enables the per-corner suspension force loop. Struct identity is GUESS; the single field is evidenced by the suspension function's guard.

Methods: 

- `obj+0x000048BC` `uint32 physicsFlags` (read, DERIVED)

### SceneNodeTransform

Scene-node transform object: dual-matrix trigger at +0x8, translation at +0x20/+0x24/+0x28, Euler angles at +0x2C/+0x30/+0x34, transform flags at +0x3C (bits 0x2100/0x2000/0x100/0x20/0x40), alternate buffer pointer at +0x40, Euler/matrix rebuild inputs at +0x54..+0x68, and two 4x4 matrix slots at +0x114..+0x150 and +0x154. Worked by SceneRenderTransform (orientation/camera update) and BuildSceneNodeTransformMatrix (world-matrix build).

Methods: `0x00548C20`, `0x0054B570`

- `this+0x00000008` `void* dualMatrixTrigger` (read, DERIVED)
- `this+0x00000020` `float translationX` (read, DERIVED)
- `this+0x00000024` `float translationY` (read, DERIVED)
- `this+0x00000028` `float translationZ` (read, DERIVED)
- `this+0x0000002C` `float eulerAngleX` (read_write, DERIVED)
- `this+0x00000030` `float eulerAngleY` (read_write, DERIVED)
- `this+0x00000034` `float eulerAngleZ` (read_write, DERIVED)
- `this+0x0000003C` `uint32 transformFlags` (read_write, DERIVED)
- `this+0x00000040` `void* alternateBuffer` (read, GUESS)
- `this+0x00000054` `float matrixSourceA` (read, GUESS)
- `this+0x00000058` `float matrixSourceB` (read, GUESS)
- `this+0x0000005C` `float matrixSourceC` (read, GUESS)
- `this+0x00000060` `float rebuildEulerX` (read, DERIVED)
- `this+0x00000064` `float rebuildEulerY` (read, DERIVED)
- `this+0x00000068` `float rebuildEulerZ` (read, DERIVED)
- `this+0x00000114` `float[16] matrixSlot1Start` (write, DERIVED)
- `this+0x00000154` `float[16] matrixSlot2` (write, DERIVED)

### VertexBufferNode

Scene-graph vertex-buffer node transformed through the D3D device: flags word at +0x14 (0x4000000 done bit, 0x800000 stride bit), position at +0x100..+0x108, Euler inputs at +0x10C..+0x114 (0x110 reused as the output pointer slot), element count at +0x118, vertex array at +0x11C (64-byte stride), and a sub-object at +0x138 whose +0x3C flags gate the write-back. Class identity is GUESS.

Methods: `0x0054C6C0`

- `this+0x00000014` `uint32 flagsWord` (read_write, DERIVED)
- `this+0x00000100` `float positionX` (read, DERIVED)
- `this+0x00000104` `float positionY` (read, DERIVED)
- `this+0x00000108` `float positionZ` (read, DERIVED)
- `this+0x0000010C` `float eulerInputX` (read, DERIVED)
- `this+0x00000110` `float eulerInputY` (read, GUESS)
- `this+0x00000114` `float eulerInputZ` (read, DERIVED)
- `this+0x00000118` `int vertexElementCount` (read, DERIVED)
- `this+0x0000011C` `void* vertexArray` (read, DERIVED)
- `this+0x00000138` `void* subObject` (read, GUESS)

### VehicleDashboardDisplaySync

Synchronizes vehicle-derived dashboard display state onto the D3D device at this+0x1100 through its vtable slot 0xC8: display-enabled flag at +0x14F0, capability bits at +0x13A8 (0x4000/0x8000), and the push caches at +0x14F4..+0x1504. Class identity is GUESS.

Methods: `0x00556040`

- `this+0x00001100` `void* d3dDevicePtr` (read, DERIVED)
- `*(this+0x1100)+0x000000C8` `void* d3dStateSetterVtbl` (read, DERIVED)
- `this+0x000013A8` `uint32 capabilityFlags` (read, GUESS)
- `this+0x000014F0` `int displayEnabled` (read_write, DERIVED)
- `this+0x000014F4` `int cachedPackedCombination` (read_write, DERIVED)
- `this+0x000014F8` `float cachedFloat0` (read_write, DERIVED)
- `this+0x000014FC` `float cachedFloat1` (read_write, DERIVED)
- `this+0x00001500` `float cachedFloat2` (read_write, DERIVED)
- `this+0x00001504` `int cachedMode` (read_write, DERIVED)

### WheelShadowCameraNode

Recursive shadow-map camera node for a vehicle wheel: vehicle physics pointer at +0xC, selected wheel slot at +0x10, wheel node pointer at +0x18, flag word at +0x24, and sibling wheel-node pointers at +0x2C and +0x34. Class identity is GUESS.

Methods: `0x00560FE0`

- `this+0x0000000C` `void* vehiclePhysicsPtr` (read, DERIVED)
- `this+0x00000010` `void* selectedWheelSlot` (read, DERIVED)
- `this+0x00000018` `void* wheelNode` (read, DERIVED)
- `this+0x00000024` `uint32 shadowUpdateFlags` (read_write, GUESS)
- `this+0x0000002C` `void* nextSiblingWheelA` (read, GUESS)
- `this+0x00000034` `void* nextSiblingWheelB` (read, GUESS)

### VehicleJointSystem

Container and solver owner for the vehicle physics joint system: counts and arrays for bodies (+0x0/+0x4), joints (+0x8/+0xC), hinges (+0x10/+0x14) and bars (+0x18/+0x1C), total entity/DOF count at +0x20, solver matrix buffer at +0x24 (8*N*N), row-pointer array at +0x28 (4*N), default solution vector at +0x2C, and the negotiated solver instance at +0x30. Populated by the two-pass VehiclePhysicsJointSystemLoader.

Methods: `0x0056D930`

- `this+0x00000000` `int bodyCount` (read_write, DERIVED)
- `this+0x00000004` `void* bodyArray` (read_write, DERIVED)
- `this+0x00000008` `int jointCount` (read_write, DERIVED)
- `this+0x0000000C` `void* jointArray` (read_write, DERIVED)
- `this+0x00000010` `int hingeCount` (read_write, DERIVED)
- `this+0x00000014` `void* hingeArray` (read_write, DERIVED)
- `this+0x00000018` `int barCount` (read_write, DERIVED)
- `this+0x0000001C` `void* barArray` (read_write, DERIVED)
- `this+0x00000020` `int entityDofCount` (read_write, DERIVED)
- `this+0x00000024` `double* solverMatrix` (write, DERIVED)
- `this+0x00000028` `double** solverRowPointers` (write, DERIVED)
- `this+0x0000002C` `double* solverSolutionVector` (write, DERIVED)
- `this+0x00000030` `void* solverInstance` (write, DERIVED)

## Compatibility contracts

- **VehicleSoundConfigFileFormat** — A replacement sound-config loader must preserve the line-oriented file shape: lines are read through the conditional-dispatch parser (0x00566CC0) into a 384-byte buffer; VS_INSIDE/VS_OUTSIDE section markers (globals 0x005D6770/0x005D677C) switch between 46 'KEY=%s' sound-sample patterns and the EngineRPMSound keyword set; outside sections 15 named float parameters (engine/shift/other range/shape/ambient and player/non-player volumes) are read through sub_565870; player and non-player volume triples are only published to dword_5D6798..dword_5D67AC when each sums to 1.0.
- **SuspensionForceDispatchContract** — A replacement suspension step must preserve the per-corner dispatch: contact points are the body-space corner offsets transformed by the rotation matrix at this+0x14..+0x40 plus the world offset at +0x8/+0xC/+0x10; the force loop runs only while bit 2 of the physics flags dword (obj+0x48BC) is set; corners iterate i=5..44 through the handler table at this+0x6D8; the active corner handler is called through vtable slot +4 with the corner transform and damping, the active flag at corner+180 is cleared afterwards, and the +8 slot runs as a fallback when the handler sub-type equals 1.
- **JointSystemFileFormat** — A replacement joint-system loader must parse the same record vocabulary: Body/Joint/Hinge/Bar/AJointHinge keyword lines (0x00587C20), per-body Name/Mass/Inertia and transform groups (0x00565520/0x00565AA0, keyword globals 0x005E5308..0x005E5328), and per-joint Name/Posbody/Negbody/Axis/Copybody groups (0x005E52EC..0x005E5314); names must be unique and referenced bodies must resolve, with the error messages formatted into a buffer through 0x0058815F and cleanup via sub_56D8F0 returning -1.
- **JointSystemMemoryLayout** — A replacement container must expose the same layout: body count/array at +0x0/+0x4 (580-byte entries), joint count/array at +0x8/+0xC (48-byte entries), hinge count/array at +0x10/+0x14 (48-byte), bar count/array at +0x18/+0x1C (72-byte), entity/DOF count at +0x20, solver matrix buffer at +0x24 (8*N*N bytes), row-pointer array at +0x28 (4*N), solution vector at +0x2C, solver instance at +0x30; each body entry is linked to the solver buffers at entry+548 and entry+552.
- **SceneNodeTransformFlagsContract** — A replacement scene-node transform must preserve the flag semantics at this+0x3C: bits 0x2100 are cleared on entry, bit 0x40 marks the transform already computed (return 0), bit 0x20 marks the rotation matrix dirty (rebuild from the +0x60/+0x64/+0x68 Euler fields), bit 0x2000 selects the PI-minus-Y-angle sign adjustment and bit 0x100 the negated X/Z angle adjustment; the primary 4x4 result occupies +0x114..+0x150 and is mirrored to +0x154.
- **VehicleDashboardStateProtocol** — A replacement display sync must preserve the D3D setter call pattern through vtable offset 0xC8 of the device at this+0x1100: parameter 28 enables/disables the display, 34 pushes the packed 16-bit dashboard combination (vehicle a2+392/394/396), 36/37/38 push the floats at a2+404/408/400, and 35 (capability bit 0x4000 at this+0x13A8) or 140 (bit 0x8000) push the mode mapped from a2+412: 0x20000->3, 0x40000->1, 0x80000->2; every pushed value is cached at this+0x14F4..+0x1504 to skip redundant calls.

## Unresolved

- The concrete owning classes of most functions (scene transform, vertex buffer, dashboard display sync, wheel shadow camera) are unknown; owners were left as UnknownObject rather than guessed, and each class here is a GUESS grouping of packet functions with shared field evidence.
- For loadVehicleSoundConfig the RPM-range arrays live at float element indices 405/422 of an unknown owner object; those offsets are not packet field refs and were not asserted as fields.
- Return semantics of loadVehicleSoundConfig are inverted-looking (1 on stream-open failure, 0 on the parse path) and are treated verbatim from raw evidence.
- The per-corner suspension handlers are dispatched indirectly through the table at this+0x6D8 using virtual slots +4 and +8; the concrete implementations live outside the packet.
- The buffer this+17 passed to ParametricInterpolationBlending and to each corner handler is an output transform whose full layout is inferred from usage, not stated by the packet.
- Read-only globals flt_59E43C and flt_59E440 are recorded for computeSuspensionForces but do not appear in the raw decompiled body; their role is unknown (possible extraction artifact or an access the decompiler collapsed).
- Read-only globals flt_59E8A4 and dword_8B78A0 are recorded for SceneRenderTransform but do not appear in the raw decompiled body; dword_8B78A0 is genuinely read by WheelShadowCameraUpdate, so its presence here may be an artifact of the shared IR build.
- Globals flt_59E43C and flt_5AD260 are recorded for loadVehicleSoundConfig but not referenced by name in the raw body; they are likely consumed inside sub_565870 / RPMRangeLoader.
- dbl_5B8998 is recorded as a read global of WheelShadowCameraUpdate but does not appear in the decompiled body; the identities of the high suspension flags and the flag bit set on this+24 are unknown.
- The read global aR (0x005C36F0) of VehiclePhysicsJointSystemLoader is not visible in the raw body; sub_588410 polarity (non-zero when names differ) and sub_56D430's exact count meaning are inferred from call-site shapes, not proven by this packet.
- Body-entry offsets +548/+552/+556/+564/+572 are read from raw source but are not flagged as packet fields; their meanings are DERIVED from the existing analysis.
- The semantics of flag bits 0x2100/0x2000/0x100 and of the buffer-selection state (scratch vs alternate vs primary) in BuildSceneNodeTransformMatrix are inferred from raw source only.
- Field 0x40 in BuildSceneNodeTransformMatrix is read only as a non-null selector; the alternate matrix at +0xD4..+0x104 is not otherwise described by the packet.
- The post-write-back component swap on vertex elements, the element-control array layout beyond this+0x118/0x11C, and the role of the 8-element structure allocated into this+0x110 are unknown.
- The vtable index 0xC8 is treated as a generic D3D state setter; the specific render-state semantics of parameters 28/34/35/36/37/38/140 are not evidenced in GraphicsDisplayStateSyncWithVehicle, and the mode-switch default assigning the raw a2 pointer to the mode value appears to be a decompiler artifact.
- The vehicle-side dashboard fields at a2+392..+412 are referenced through a2 without packet field refs; their dashboard meaning is inherited from the fill prose only.
- The 96-byte wheel stride, the 1.2 angle multiplier, and the semantics of arguments a2/a3 of the recursive WheelShadowCameraUpdate self-call are inferred from numeric literals, not independently evidenced.
- The precise file-stream and allocation wrappers (AudioStreamOpen, OperatorNewNhMallocWrapper, ResourceLookupDispatcher, etc.) are named from their call sites only; their contracts are not documented by this packet.
- sub_565870, sub_55C070, sub_542050, TwoFieldSetterCall, and the getter/query pairs in WheelShadowCameraUpdate are inferred from their call-site shapes only.
