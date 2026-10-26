# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

DERIVED proposal for the vehicle_physics scope. The subsystem is evidenced by the validated IR as several loose groups with mostly unknown owners. (1) Collision contact manager: CollisionContactBufferTimestepUpdate accumulates the timestep into this+0x0, and on overflow past the flt_59E43C threshold normalizes the this+0x4/this+0x8 impulse accumulators into the this+0xC/this+0x10 outputs and resets all three; CollisionContactSolver consumes per-slot accumulated floats and global counters at this+0x4/this+0x8, recording impacts into per-slot ring buffers and clamping penetration against dbl_8AFEA0/flt_7D108C. (2) Vehicle state integration: VehicleOrientationFromAngularVelocityIntegration integrates angular velocity doubles at this+0xD8/0xE0/0xE8 from axis-input doubles at this+0x138/0x140/0x148 and a second scaled vector at this+0x150/0x158/0x160, then extracts Euler angles from a rotation matrix and forwards to sub_54B4D0; PhysicsIntegrationStep_e620 clamps the fixed timestep from dbl_8AFE98 and runs a semi-implicit Euler suspension integration gated on terrain sampling. (3) Session-gated collision orchestration: RunCollisionDetectionLoop runs a QPC-timed loop gated on this+0x3FC4==3, CollisionEventNetworkBroadcast sends a COM-buffer progress-bar event when the session-state field is 1 or 2, CollisionSpatialQuery invokes a vtable method at 0x6C on the sub-object at obj+0x3FB8 and arms retry state. (4) Vehicle array iteration: CollisionContactIteration walks the 104-slot array (base 0x005EC6D8, stride 0x48C0) and toggles AI control/driver visibility by penetration ratio. (5) Vehicle UI/audio/debug: tire-compound screen setup, engine-temperature display, vehicle-name message buffer, nationality matcher, per-state audio dispatch, and display-node/texture creation. Owners beyond a small set of GUESS classes are deliberately left UnknownObject; all fields, callees, and globals are reported verbatim from the packet, and no evidence reference is invented.

## Function roles

- `0x00455E50` **UnknownObject** — Thin caller: loads the global double dbl_8AFE90 into a local, forwards it with the this object into sub_4537B0 (return discarded), then returns the char result of ShortComputation_5bd0; suggested as a per-frame or state-triggered update broadcast by its named callers.
- `0x0045AE00` **UnknownObject** — Integrates vehicle angular velocity over an elapsed time step into orientation: guard on this+0xD0, delta against timestamp this+0x24, accumulates scaled axis inputs (this+0x138/0x140/0x148) onto angular-velocity doubles (this+0xD8/0xE0/0xE8), computes a second scaled vector (this+0x150/0x158/0x160), post-processes it via sub_56C020, extracts Euler angles (gimbal-lock branch on dbl_59E420 vs general branch) from a rotation matrix, and forwards body-state to sub_54B4D0; returns the guard value when the guard is clear.
- `0x0045BE00` **UnknownObject** — Scales a collision penalty value: dereferences the float threshold array from this+0x0, finds its boundary via FloatArrayThresholdSearch, clamps a2 upward to that boundary, then returns a2 scaled by 0.035 (flt_59F078) as a double.
- `0x0045C7E0` **CollisionContactManager** — Advances a collision contact buffer by timestep a2: accumulates into contact-time this+0x0; when it exceeds flt_59E43C, normalizes impulse accumulators this+0x4/this+0x8 by the reciprocal into outputs this+0xC/this+0x10 and resets all three; then a 104-iteration loop adds a2 to each contact-pair timer entry; returns a pointer past the timer block.
- `0x0045C8F0` **CollisionContactManager** — Processes a single collision contact selected by the low byte of the first a2 dword: for slot index below 0x68 reads the per-slot accumulated float this[v4+109] and clears this[v4+5]; on exceedance of 0.5 records an impact (marker this[v4+1097]=-1082130432, ring-buffer short via FloatToShortViaFtol, counters at this+v4+852 and ring offsets at this+v4+956), corrects v3[1] via ShortArrayLookupAndZeroCheck, clamps v3[1] into [dbl_8AFEA0 - flt_7D108C, dbl_8AFEA0]; unconditionally accumulates this[1]+=v11 and increments this[2], returning the counter.
- `0x0045E620` **UnknownObject** — Per-axle physics integration for one wheel slot: clamps the fixed timestep from dbl_8AFE98 to a maximum of 0.033333335 (negative to 0.0), resolves wheel state arrays (base a1+112544, 56-byte stride) from the a3 wheel index, computes the wheel velocity delta, scales it by the inverse timestep via Vector3ScalarMultiply, samples terrain height/roughness via TerrainSurfaceRoughnessHeightSampling, and when the contact gate passes integrates suspension velocity/displacement semi-implicitly under clamping; writes the velocity back to a3 and the wheel state; a fallback stores current values without integrating.
- `0x0045F2A0` **UnknownObject** — Writes the multiplicative inverse of a2 (1.0/a2) into the float field at this+0x4; called by SessionTypeSetter.
- `0x0045F390` **SessionCollisionController** — Runs a timed collision-detection loop gated on session phase this+0x3FC4==3: initializes a QPC timer, loops while AnimationValueFetchWithTiming yields values (refreshing animation timing via AnimationTimingUpdateWithParamSet on this+0x3FB8 with a 4.0 budget), accumulating the high-resolution timer delta until the 60.0-second timeout (EmptyStub_0170, return 0); on completion processes the value via sub_4F9FC0, converts with TimerConversionWithSin, places the multiplayer vehicle via MultiplayerVehiclePlacement, resets the collision array via ArrayInitializationLoop, and returns 1.
- `0x00460DD0` **UnknownObject** — Iterates the 104-slot vehicle array (base unk_5EC6D8, stride 0x48C0, ending at byte_7C54D8) and for each vehicle whose live-state int32 at +0x32C8 equals 2 computes a penetration ratio (per-vehicle float at a1+0x1A3D4 divided by flt_7D108C) and consults ShortArrayLookupAndZeroCheck; on severe contact (ratio>2.0 or contact flag) releases AI control via VehicleAIControlFlag(0) and toggles driver visibility (hidden when ratio>8.0 or |contact|>0.75, else shown); otherwise retains AI control via VehicleAIControlFlag(1) and shows the driver.
- `0x00462940` **SessionCollisionController** — Broadcasts a collision event over the network when the owning-object state at +0x3FC4 is 1 or 2: reads session time dbl_8AFEA0, encodes a progress-bar event via ProgressBarEventEncode, obtains a buffer from the COM object at +0x3FB8 via COMVTableCallVia0x60, sets the flag byte at buffer+4 to 1, dispatches through NetworkSendDispatch, and releases the buffer via VirtualMethodDispatch; returns the send-success flag.
- `0x00462CE0` **SessionCollisionController** — Issues a spatial/collision query on the sub-object stored at obj+0x3FB8 (obj = *(this+0)) by invoking its vtable method at offset 0x6c via VTableCallViaOffset0x6c with a2/a3; returns 0 when the call returns non-zero; on success arms retry state (byte obj+41=1, float obj+16=5.0, dword obj+16324=4) and returns 1.
- `0x00466300` **UnknownObject** — Post-initialization pass after a vehicle scene load: resets field 0x124 to the -1.0f sentinel bit pattern, calls CUBESceneLoaderEntry() and FieldSetterCall(2), runs update helpers sub_466350 and sub_466650 on this, then conditionally calls sub_541CA0(1) when the flag at field 0xEC is non-zero; always returns 0.
- `0x00470400` **VehicleUiScreenState** — Conditional debug display updater: when the type selector at this+0x304 equals 435 and the session-state check on dword_7CD25C passes, seeds a local path buffer from byte_5EA438, composes a debug string via sub_4B0B20/StringFormatWrapper, and calls BoundedFieldSetter(159 - strlen) to update a bounded field.
- `0x00472510` **VehicleUiScreenState** — Unconditional UI screen-setup for tire compound selection: stores race mode dword_7D0410 into this+0x324, binds the tire compound data pointer dword_7CFFCC into this+0x320, fetches the indexed list entry via UIListIndexedAccessor, formats it via StringFormatWithBufferOverflowCheck, clamps the compound config byte_7CE498 via TireCompoundClamp, updates the edit buffer via EditBufferStringUpdate; returns 0.
- `0x0047F010` **UnknownObject** — Reads the current vehicle name via VehicleNameAccessor(dword_7CD25C), validates it against the string table (byte_5EC4C0/byte_5EC4CC), copies it into the message buffer byte_5EC4CC, and drives the UI text update via UIStringComparison; falls back to the default path string byte_5EA438 when the name is null or empty; returns 0 on both paths.
- `0x0047F230` **UnknownObject** — Iterates season entries in SeasonScoringDB (dword_7D2E48, stride 18624, sub-offset 18196) matching each against all vehicle files, calling NationalityDriverInfoLoader(0) when all vehicle files match a season or when a season has no vehicle files; guarded on VehicleArray (dword_8AC394) being non-null and VehicleCount (dword_5C329C) / VehicleFileCount (dword_8AC390) positive.
- `0x0048C170` **VehicleUiScreenState** — Advances a collision/animation timer accumulator at this+0x318; returns -1 early when ByteFieldGetterAt100 reports a block flag or the enable byte at this+0x304 is zero; otherwise adds the external float at this+0x40 onto the accumulator, dampens it toward 0.75, converts via CRTFtol, and when ShortComputation_6720 returns a positive count dispatches that many calls through a __stdcall function pointer at receiver offset 184 with the boolean (result==4); returns 0 on completion.
- `0x00494E60` **UnknownObject** — Frees a global collision-geometry linked list: first walks it with StringCompareLinkedListSearch on each node's data pointer (node+0), advancing via next pointers (node+4); then walks again freeing every node with FreeWrapper_7bcf, additionally freeing the data payload (EmptyStub_7470 then FreeWrapper_7bcf) when the ownership byte at node+8 is non-zero and data is non-null; finally zeroes dword_7CDDF0/7CDDF4/7CDDF8/7CDDFC; returns early when the list head is null.
- `0x00498720` **UnknownObject** — Unconditional collision/physics parameter setter: stores the global double dbl_8AFE90 into the float field at this+0xC0 on every call; no guards, no callees.
- `0x004987B0` **UnknownObject** — Collision response-type classifier: accumulates FloatFieldAccessor into a running float at byte offset 200, then selects a small integer response code (1..13) from flag checks on dword fields at byte offsets 100/104/108/112 and companion flags at 132/136/140; some branches overwrite the offset-200 accumulator with 0 or the literal 1059481191; the offset-112 field yields 12/13 when set.
- `0x0049C0B0` **UnknownObject** — Formats a vehicle debug string: copies asc_5CCE54 into the caller buffer, selects a vehicle struct either by a sub_4D1B50 index lookup into the array base unk_5EC6D8 or directly from dword_7C54E0 (guarded by bit 0 of byte_7CFFF0), and when the selected pointer is non-null and a float field at offset 16552 (indexed by a value at dword_7C54E0+16448) is greater than 0.0, formats a string from offset 18168 via off_5C3730/StringFormatWithBufferOverflowCheck and outputs it through sub_589901; returns 0 on every path.
- `0x0049CD80` **VehicleDisplayNodeFactory** — Builds a candidate vehicle file path (filter path, source at ConditionalDispatch result +32, an extension of dword_5CCEBC plus byte_5CCEC0, and a season directory), registers it via StringRegistry, searches a linked list for a matching node, writes it into *a2, reads dimensions from a chained object, creates a vehicle display node (VehicleNodeCreation), renders a 2D rectangle, creates an audio sound handle, computes scaled rectangle values, and stores parameters a6/a7 into this+0x14/this+0x18; temporary lists are cleaned up with PhysicsObjectLinkedListRemoval; entire body is guarded by dword_8AFE88/ValueGetter.
- `0x0049D4C0` **UnknownObject** — Per-state audio dispatch for a vehicle: reads seven audio-source handles from this[12]..this[18] and, depending on collision check (sub_49B9A0), two state reads (sub_49BA30), the fuel check (sub_49BA50), the disqualification/pit checks (sub_49BAB0/sub_49BA90), and two flag checks (sub_49BAD0/sub_49BB20), triggers AudioEffectTrigger or fires a random collision event via RandomCollisionEvent; returns the final AudioEffectTrigger result.
- `0x0049E930` **VehicleDisplayNodeFactory** — Allocates a 96-byte node via the Nh-malloc wrapper, zero-fills it, and stores the pointer at this+0x8; sets flag bit 0 at node+68, then attempts D3D texture creation with (a2, 0, 2052); on success the node is cleaned up (EmptyStub_7470) and freed (FreeWrapper_7bcf) and this+0x8 is cleared; on failure the node pointer is retained in this+0x8 for retry; returns this+0x8.

## Proposed classes

### CollisionContactManager

Holds the shared collision-contact bookkeeping state: accumulated contact time at +0x0, two impulse accumulators at +0x4/+0x8 normalized into outputs at +0xC/+0x10 on overflow, and the global contact counter pair at +0x4/+0x8 consumed by the per-slot solver. Class identity is GUESS; field access is evidenced across both methods.

Methods: `0x0045C7E0`, `0x0045C8F0`

- `this+0x00000000` `float contactTimeAccumulator` (read_write, DERIVED)
- `this+0x00000004` `float impulseAccumulatorA` (read_write, DERIVED)
- `this+0x00000008` `float impulseAccumulatorB` (read_write, DERIVED)
- `this+0x0000000C` `float normalizedOutputA` (write, DERIVED)
- `this+0x00000010` `float normalizedOutputB` (write, DERIVED)

### VehicleOrientationIntegrator

Vehicle body-orientation state integrated by VehicleOrientationFromAngularVelocityIntegration: a stored timestamp at +0x24, an enable/guard slot at +0xD0, angular-velocity doubles at +0xD8/+0xE0/+0xE8, axis-input doubles at +0x138/+0x140/+0x148 and a second scaled rotation-vector triple at +0x150/+0x158/+0x160. Class identity is GUESS; each field is evidenced by the integration.

Methods: `0x0045AE00`

- `this+0x00000024` `float lastTimestamp` (read, DERIVED)
- `this+0x000000D0` `void* integrationGuard` (read, DERIVED)
- `this+0x000000D8` `double angularVelocityX` (read_write, DERIVED)
- `this+0x000000E0` `double angularVelocityY` (read_write, DERIVED)
- `this+0x000000E8` `double angularVelocityZ` (read_write, DERIVED)
- `this+0x00000138` `double axisInputX` (read, DERIVED)
- `this+0x00000140` `double axisInputY` (read, DERIVED)
- `this+0x00000148` `double axisInputZ` (read, DERIVED)
- `this+0x00000150` `double rotationVectorX` (read, DERIVED)
- `this+0x00000158` `double rotationVectorY` (read, DERIVED)
- `this+0x00000160` `double rotationVectorZ` (read, DERIVED)

### SessionCollisionController

Session-gated collision orchestration object: a session-phase int at +0x3FC4 (==3 runs the timed collision loop, 1/2 allow network broadcast, 4 armed as retry state), a parameter/COM sub-object pointer at +0x3FB8, a state byte at +0x29 and a timeout float at +0x10 for the armed retry. Class identity is GUESS; the fields are evidenced on the obj base by the two sub-object-reaching functions.

Methods: `0x0045F390`, `0x00462940`, `0x00462CE0`

- `obj+0x00000010` `float retryTimeout` (write, DERIVED)
- `obj+0x00000029` `uint8 retryStateByte` (write, DERIVED)
- `obj+0x00003FB8` `void* parameterSubObject` (read, DERIVED)
- `obj+0x00003FC4` `int sessionPhase` (read_write, DERIVED)

### VehicleUiScreenState

Vehicle-facing UI screen state shared by the temperature-display, tire-compound, and animation-timer updaters: a type/enable selector at +0x304, a timer accumulator at +0x318, bound data pointer at +0x320, race-mode value at +0x324, and an external float source at +0x40. Class identity is GUESS; each field is evidenced at the this base by one or more of the three methods.

Methods: `0x00470400`, `0x00472510`, `0x0048C170`

- `this+0x00000040` `float* externalFloatSource` (read, DERIVED)
- `this+0x00000304` `int typeSelector` (read, DERIVED)
- `this+0x00000318` `float timerAccumulator` (read_write, DERIVED)
- `this+0x00000320` `void* boundDataPointer` (write, DERIVED)
- `this+0x00000324` `int raceMode` (write, DERIVED)

### VehicleDisplayNodeFactory

Creates and manages a vehicle display/texture node: this+0x8 holds the node slot (stored, retained for retry, or cleared on texture-creation success), this+0x14 and this+0x18 receive caller-supplied parameters during node creation. VehicleNodeCreateWithAudioVisual calls the node creator (0x0049E930). Class identity is GUESS; fields are evidenced per base.

Methods: `0x0049CD80`, `0x0049E930`

- `this+0x00000008` `void* textureNodeSlot` (read_write, DERIVED)
- `this+0x00000014` `void* storedParamA` (write, DERIVED)
- `this+0x00000018` `void* storedParamB` (write, DERIVED)

## Compatibility contracts

- **VehicleArrayLayout** — Vehicle array contract: base 0x005EC6D8, 104 slots at stride 0x48C0 (18624 bytes) ending at 0x007C54D8; per-slot live-state int32 at +0x32C8 equal to 2 selects collision-contact response; per-vehicle penetration float at a1+0x1A3D4.
- **CollisionContactBufferLayout** — Per-buffer collision contact layout: accumulated contact time at +0x0, two impulse accumulators at +0x4/+0x8, normalized outputs at +0xC/+0x10, overflow normalization against the flt_59E43C threshold, and a 104-entry contact-pair timer block (two floats per pair) advanced each step.
- **ContactSlotRingBufferLayout** — Per-slot contact-ring layout in the collision solver: slot index cap 0x68, per-slot accumulated float at this[v4+109] cleared on impact, impact threshold 0.5, impact marker this[v4+1097], short ring buffer via this[8*v4+265] advanced by the ring byte at this+v4+956 (mod 0xF), impact counter at this+v4+852 (cap 0x10), and penetration clamp into [dbl_8AFEA0 - flt_7D108C, dbl_8AFEA0].
- **FixedTimestepPhysicsBehavior** — Per-axle integration timestep contract: the fixed timestep from dbl_8AFE98 is clamped to a maximum of 0.033333335 (one thirtieth) and negative values to 0.0; integration is gated on terrain sampling succeeding, the sampled height exceeding dword_7D1158, and the penetration limit flt_7D108C minus dword_7D1158 being positive; wheel slots are 56-byte state records at base a1+112544.
- **OrientationIntegrationLayout** — Vehicle orientation state layout used by the integrator: guard at +0xD0, stored float timestamp at +0x24, angular-velocity doubles at +0xD8/+0xE0/+0xE8, axis-input doubles at +0x138/+0x140/+0x148, second scaled rotation-vector doubles at +0x150/+0x158/+0x160, and a 72-byte rotation matrix copied from offset 240 for Euler extraction (gimbal-lock sentinels at 0x0059E420/0x0059E430); body state forwarded to sub_54B4D0.
- **SessionPhaseGateContract** — Session-phase gating on the +0x3FC4 field: value 3 runs the timed collision-detection loop, values 1 or 2 permit the collision network broadcast, and a write of 4 arms spatial-query retry state together with state byte at +0x29 and timeout float at +0x10; the parameter/COM sub-object lives at +0x3FB8.

## Unresolved

- The concrete owning classes of most functions are unknown; owners were left as UnknownObject rather than guessed. Only CollisionContactManager, VehicleOrientationIntegrator, SessionCollisionController, VehicleUiScreenState, and VehicleDisplayNodeFactory carry GUESS identities based on shared field bases or caller/callee links.
- In CollisionContactManager, the +0x4/+0x8 fields are both impulse accumulators (0x45C7E0) and global contact counters (0x45C8F0); the packet does not prove these two 'this' pointers alias the same object, so the shared-field reading is DERIVED inference, not confirmed ownership.
- SessionCollisionController's session-phase field is accessed as this+0x3FC4 by 0x45F390 and as obj+0x3FC4 (obj=*(this+0)) by 0x462940/0x462CE0; equal offsets on different bases are not proven to be the same field.
- ShortComputation_5bd0 (callee of 0x455E50) appears only in raw source text with no packet callee evidence reference; its identity and signature rest on the source alone.
- The semantics of sub_4537B0, sub_56C020, sub_54B4D0, and whether sub_54B4D0 writes orientation back to the same object, are not established by this packet.
- The 1.0/0.0 constants at dbl_59E420/dbl_59E430 are interpreted as gimbal-lock sentinels by reconstruction, not by direct evidence.
- The rotation matrix copied from offset 240 has no packet field evidence ref; it is treated as part of the object's rotation state.
- The exact layout of the 56-byte wheel slot and the two axle state arrays (base a1+112544) in PhysicsIntegrationStep_e620 is not defined by the packet.
- In CollisionContactSolver the dynamic-indexed state arrays (per-slot floats at this[v4+109], impact markers at this[v4+1097], counters at this+v4+852, ring buffers at this[8*v4+265], ring offsets at this+v4+956) are not packet fields; the meaning of the 0x68 slot count and the -1082130432 literal are not established.
- The numeric value of the flt_59E43C overflow threshold is not present in the packet.
- The value fetched by AnimationValueFetchWithTiming (v7/v8/v9 triple) and its 4.0 budget / 60.0 timeout units are taken from call order only; why this+0x3FC4 must equal 3 is unresolved.
- The collision array reset target this+26864 in RunCollisionDetectionLoop has no named counterpart in the packet.
- CollisionEventNetworkBroadcast's a2 collision-event structure, the packet buffer layout, the purpose of the flag byte at buffer+4, and whether VirtualMethodDispatch releases or re-uses the buffer are unconfirmed.
- The identity and purpose of the vtable method at offset 0x6C on the sub-object at obj+0x3FB8 are unknown.
- The meaning of the flag at field 0xEC gating sub_541CA0(1) in VehicleScenePostInit is not established.
- In EngineTemperatureDebugDisplay the type-selector value 435 and the semantics of BoundedFieldSetter's argument are not documented.
- How UIListIndexedAccessor selects its index and how dword_7CFFCC relates to the tire compound list are not visible in TireCompoundScreenSetup.
- In VehicleNameToMessageBuffer, whether the strcpy guarded by the string-table search is duplicate-suppression or an index update is not visible in the raw source.
- The exact return convention of sub_588410 (match vs mismatch) is inferred from its call sites; the semantics of the 18196 sub-offset within each SeasonScoringDB row are not defined.
- The indirect __stdcall target loaded from receiver offset 184 in CollisionAnimationTimerUpdate is unknown; no static callers are recorded.
- Global flt_59E450 is listed in the packet for several functions but does not appear in their raw bodies; its role is unknown.
- CollisionGeometryFreeList globals 0x007CDDF4 and 0x007CDDFC are only written (zeroed) here; their wider roles are unresolved.
- CollisionResponseTypeClassification's mapping of returned codes (1..13) to collision response types is unconfirmed; the decompiler shows v1 (ecx) uninitialized, so the v1+offset accesses are treated as this-object accesses without independent verification.
- In FormatVehicleDebugString the identity of the float field at offset 16552 and the string at offset 18168 is only DERIVED from the fill; argument a2 is unused.
- In VehicleNodeCreateWithAudioVisual the a6/a7 parameters stored at this+0x14/+0x18 and the v21/v22 scaled values are unidentified; whether sub_588410 is a file-existence check is GUESS.
- In VehicleStateAudioDispatch the legacy ABI lead (State_Batched_UI_Element_Update) is not corroborated by this packet.
- In CreateVehicleNodeWithTexture the 2052 literal, the meaning of flag bit 0 at node+68, and the node struct layout beyond offset 68 are unproven.
- Numerous globals (0x0059E440, 0x0059E4DC, 0x0059E800, 0x0059EA60, 0x0059E7FC, 0x0059E908, 0x0059F0A0, 0x0059F118, 0x005EC6D0, 0x008AFE18, 0x008AFE64, 0x008AC388, 0x008ACEE0, 0x007CE234, 0x007CD204, 0x007CE498) are listed in the packet facts but do not appear in the corresponding raw function bodies; their roles are unresolved.
