# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

Proposes seventeen classes over the twenty-one validated functions. VehicleObject (0x004C6920) is the only packet-derived owner class and covers construction. PackedOrientationCodec (0x004B2DD0, 0x004B32A0) groups the structural twin sharing the unpack/bitfield tail (0.000030517578 scale, FloatToBitfieldPack / BitfieldInsert / saturated int16 pack). CollisionParticleEffectManager (0x004CB620, 0x004CE3E0, 0x004CE930) groups the collision spark/trail emitters that share the slot pointers this+0x20/0x24/0x28, the effect slot array this+0x3C/0x40, the throttle globals (dword_7CF8A8, dword_8AB6E4, dword_7C5698) and the flt_8AB274 / dword_8AAE70 jitter source. RaceCompletionMonitor (0x004DA990, 0x004DAD80) groups the progress-count and finished-check pair. The remaining roles are singletons proposed as GUESS owners: SuspensionTelemetryGauge, VehicleProximityScanner, VehicleCollisionAvoidanceController, VehicleIdentityComparer, VehicleLifetimeStateAccessor, WheelContactParticleLookup, ParticleWorldTransform, VehicleSlotActivator, TransformMatrixComposer, VehicleLapGapStateTracker, PhysicsConstantSeed, CameraTransform (packet-derived), and SuspensionGeometryInitializer. Three interfaces expose the shared services: VehicleArrayService, CollisionEmitterService and PackedOrientationCodecHelpers. Ownership beyond VehicleObject and CameraTransform is unresolved and must not be treated as CONFIRMED.

## Function roles

- `0x0049E570` **SuspensionTelemetryGauge** — Render one corner's suspension/temperature gauge into draw surface a2. Gate the active branch on the per-corner input state at dword_7C54E0 + 296*a1 (non-zero dword at +2100 and non-zero byte at +2164); inactive corners blink red on parity CRTFtol(dbl_8AFEA0) % 2. When the per-car dword at +18580 of the car selected by dword_7C54DC equals that of the car selected by dword_7C54E4, draw three color-encoded segments built from the corner temperature table at 8157696 (Kelvin minus 273.16 through FloatToColorEncoding) via RenderDrawOperationWithClipping; otherwise draw the whole bar in fixed green (-16711936) and return the draw result.
- `0x004A4710` **VehicleProximityScanner** — Scan the active-vehicle pointer array dword_7C54F0 (end sentinel byte_7C5690) for the candidate whose speed/distance delta from the target vehicle (slot index a2) is the smallest positive value. Live candidates go through AIDelegateCall (0x0042ADD0) then SpeedDeltaComputation (0x00426CC0); null slots whose base state at +13000 != 1 fall back to the base vehicle value at +15016 through SpeedDeltaComputation. Positive-delta clamp from flt_59E440. Returns the winning vehicle pointer, or 0 when the target slot is null. Called by OpponentProximityScanTeamRecognition (0x0042A7D0).
- `0x004A6B80` **VehicleCollisionAvoidanceController** — Per-frame collision-avoidance state machine. With the avoidance sub-object at this+0x14 present, read the movement-threshold flag at *this + 0x39A0, obtain the position-change monitor (0x004E9630) on the object base + 12, compute the normalized movement delta between predicted and current position, and for every active vehicle (count dword_5C329C, array dword_7C54F0, activity byte at +13388) test the approach-time ratio 0 < t < 5.5 via dot products with the own direction at obj+0x34E0/0x34E4/0x34E8 and the other vehicle's direction at +13560/+13564/+13568. On predicted collision the collision flag is cleared; otherwise the state transitions 1 -> 2 and optionally raises a flag-field bit (FlagFieldBitManipulation when sub-object flag index [25] is set), and a collision detected while in state 2 invokes the utility handler on the sub-object. Returns the current state value.
- `0x004B2DD0` **PackedOrientationCodec** — Convert packed Euler/orientation data from the fixed-point struct this into a float triple at a2+8/+12/+16 plus two bitfield-packed values, storing a3 at a2+4 and returning it. Scale int16 at this+9/+11/+13 by 0.015625, round-trip through UtilityFunction_2480 (0x004B2480), FloatToFixedConversionWithClamp (0x004B25D0) and FloatToShortClampedConversion (0x004B2750); when the direction vector is non-zero build an orthonormal basis: unpack this+0/+2/+4/+8 scaled by 0.000030517578, derive a normal via CollisionNormalFromFeature (0x0044C550, global 0x007C9360) with a default-axis fallback, extract Euler angles via atan2 with gimbal handling (FloatConvertWrapper 0x00588570), pack via FloatToInt16SaturationPack (0x004B31A0), and write the bitfield parameters through TernarySelectByBitfield (0x004B2BF0)/BitfieldInsert (0x004B29B0) and sub_4B2C50 (0x004B2C50)/FloatToBitfieldPack (0x004B2930). Called by FloatComputation (0x00464B40) and CollisionStateUpdate (0x00500010).
- `0x004B32A0` **PackedOrientationCodec** — Pack a fixed-point triple from struct this into floats and through the bitfield pipeline at output a2. Round-trip a2+8 through UtilityFunction_2480 (0x004B2480), FloatToFixedConversionWithClamp (0x004B25D0) and FloatToShortClampedConversion (0x004B2750); unpack this+0/+2/+4/+8 scaled by 0.000030517578 into v12/v13/v14; process via sub_4B2310 (0x004B2310); pack two bitfield parameters via TernarySelectByBitfield/BitfieldInsert (0x004B2BF0/0x004B29B0) and sub_4B2C50/FloatToBitfieldPack (0x004B2C50/0x004B2930). Writes a3 to a2+4 and returns the bitfield-pack result. Called by CollisionStateUpdate (0x00500010) during collision geometry setup.
- `0x004B5120` **VehicleIdentityComparer** — Thiscall identity/path comparison on two strings: find the null terminator of the path string at a2+18196, scan back for the last backslash (92), compare the trailing filename with the string at this+65 and the string at this+1 with the string at a2+17952; returns true when both match (whole-path compare when no backslash is present). Invoked by VehicleInstanceListBuilder (0x004B5C50).
- `0x004B9CB0` **VehicleLifetimeStateAccessor** — Minimal accessor: dereference this to obtain the target object stored at this+0x0, load the float at object+0xF30, and return it. No branches, guards, globals or callees. Callers 0x0047C940, 0x0047C960, 0x0047DBE0.
- `0x004C6920` **VehicleObject** — Vehicle-object constructor: RaceStructInit (0x00423E80) zero-initialises the struct, write this[4645] (offset 0x4894) = -1 (all bits set) to mark the handle/ID unset, VehicleDriverInfoClear (0x004C79E0) clears the driver-info substructure, and LargeStructFieldSetterWithStoredReference (0x00424040) stores a persistent self-reference; returns this. Called by RepeatedCallLoop (0x0042BB50).
- `0x004CB620` **CollisionParticleEffectManager** — Spawn a spark particle at a collision contact point. Compute the contact magnitude from the direction vector a4; when magnitude >= 1.0 and the slot counter at this+0x58 is positive, allocate a slot from the circular buffer owned by this (0x004CB540), size the spark from the 256-entry trig table (globals 0x008AAE70/0x008AAE74) scaled by a5, compute a collision normal via CollisionNormalFromFeature (0x0044C550, global 0x007C9360) with a fallback, write position/velocity/magnitude into the slot, and publish through the array/flag helpers 0x00558C60/0x00558CB0/0x00558CF0 using this+0xC/+0x10/+0x14 parameters. Called by the collision effect dispatch (0x004CE3E0).
- `0x004CE3E0` **CollisionParticleEffectManager** — Per-frame collision contact effect dispatch. Gate on ArithmeticComparison_9fb0 (0x004B9FB0) of the dword_8AB6E4 scoring/effects gate; iterate the effect slot array at this+0x40 over the this+0x3C slot count, switching on each slot's type id at slot+4. The spark type id spawns via ParticleCollisionSpark (0x004CB620); trail types spawn via ParticleTrailEmitter (0x004CBC50) with positions jittered from flt_8AB274 through the dword_8AAE70 ring counter. Emission is throttled on dword_7CF8A8 / dword_8AB6E4 / dword_7C5698 (every 20 ticks), deduplicated by the last contact position (a2+56..64) and speed (a2+68), and the byte_7CF9D4 / byte_7CF9EC weather-render flags select the trail magnitude/persistence variant. Callers 0x004472B0 and 0x004EE2D0.
- `0x004CE930` **CollisionParticleEffectManager** — Spawn trail particles from three collision-effect slots (this+0x20/0x24/0x28) when the collision point has moved enough since the last frame. The emitter-mode argument a6 is derived from byte_7CF9BC/byte_7CF9EC (104 when both set, -1 when both clear, otherwise incoming a6); per-slot emission is gated by the collision strength in a2, the slot pointer and the throttle counters (dword_7CF8A8, dword_8AB6E4, dword_7C5698 % 20 == 0). Movement windows: vertical delta beyond 0.15000001 / squared horizontal distance beyond 1.0 (slots 8 and 9), 0.059999999 / 0.16000001 (slot 10). Jittered spawn positions from flt_8AB274 via the dword_8AAE70 ring counter, a5 velocity scaled by 0.1, emitted through ParticleTrailEmitter (0x004CBC50); slot 10 additionally spawns a secondary offset trail (0.0125 backward offset) at high render-throttle detail. Called from 0x004472B0 and 0x004EE2D0.
- `0x004CEFA0` **WheelContactParticleLookup** — Search the strided array owned by this (element count this+0x10, first element this+0x14, 108-byte stride) for the first entry whose +4 field equals a3, then spawn a wheel contact particle at that entry via WheelContactParticle (0x004CD6C0). Returns the matched 0-based entry index, the element count when the search exhausts, or 0 for an empty array. Called by AIWaypointPathCheckerRenderer (0x004024F0).
- `0x004D2450` **VehicleSlotActivator** — Scan the active-vehicle pointer table dword_7C54F0 over dword_5C329C slots for the first slot whose in-use flag at +0x4064 (16484) is zero, set it to 1 (unless the current value is the sentinel 3), and return the slot base plus 0x4034 (16436); return the slot count when no free slot is found. Matches the ABI lead Set_First_Uninitialized_Vehicle_Active. Called by DispatchChainWithVTableCalls (0x0046DA20) and sub_46DC60 (0x0046DC60).
- `0x004D5C70` **TransformMatrixComposer** — Build four 4x4 transform matrices on the stack from a2 (negated when positive, against the zero sentinel dbl_59E430), a3 (clamped to [0,1] with bounds dbl_59E420=1.0 and dbl_59E430=0.0) and a4 (scalar power/twist base, stored as a double at this+0x20), combine them via sub_5677B0 (0x005677B0, count 4, coefficient 3.0 from dbl_59E7E0), and write the combined result as eight dwords into this[0x0..0x1C]. On failure zero the eight dwords and set this+0x1C to 1.0f (1072693248). Callers sub_430750, BrakeTemperatureFadeModel (0x00430A50), TireCompoundPerWheelPhysicsApplication (0x0043DA10).
- `0x004D9FE0` **VehicleLapGapStateTracker** — Update a per-vehicle lap-gap state object. Read one of two time values through the player vehicle pointer dword_7C54E0 at offsets 16592/16596, record the chosen source as a byte flag at this+0x18 and the chosen value at this+0x1C, and call LapTimeGapCalculation (0x0049B6D0) to write the gap float at this+0x14. A non-zero gap-calculation return, a gap <= 0.0, or a non-zero gap flag each dispatch VTableDispatchWithFieldClear (0x004D7E30) on this; otherwise fall through returning the gap flag. Invoked from sub_4D9F80 (0x004D9F80).
- `0x004DA990` **RaceCompletionMonitor** — Count vehicles whose per-vehicle progress field (vehicle_ptr + 16444) meets or exceeds the threshold read from this+0x24. Iterate all vehicles in the global pointer array dword_7C54F0 over indices 0..dword_5C329C-1, incrementing the match count for each progress value >= threshold; returns 0 when dword_5C329C is not positive.
- `0x004DAD80` **RaceCompletionMonitor** — Return whether race completion is confirmed. The result flag starts false and is set true when the race-end condition from ArithmeticComparison_ae80 (0x004DAE80) holds or this+0x20 equals the tally dword_5C329C. When the finished count from CountVehiclesAtOrBeyondLap (0x004DA990) equals the tracked count read from the player vehicle pointer dword_7C54E8 at +16480 and that tracked count has not reached the tally, scan the trailing vehicles (via sub_4D1B50 over dword_8ACEE0 indexing dword_5F073C at stride 4656) under the one-shot flag this+0x28, clearing the result flag if the scan reaches the grid end; write 1 to this+0x28 to mark the check done.
- `0x004DB130` **PhysicsConstantSeed** — Minimal thiscall constant initializer (structural twin of ConstantReturnSetter 0x004DB100): store the literal 1082130432 (4.0f) into the dword at this+0x10 and return the same literal. Likely seeds a per-object physics/scalar field. Global dword_5ACF5C is recorded as read by facts but does not surface in the raw body.
- `0x004E16F0` **ParticleWorldTransform** — Transform up to 17 particle-emitter positions from local to world space and spawn particles. Guard on the global particle-system pointer dword_8ACEB8; iterate the emitter array of 17 slots at this+0x998 (7 floats / 28 bytes per slot), and for each slot whose active-flag byte is non-zero rotate the slot position by the 3x3 rotation matrix a2, add the translation a3, and call ParticleSpawnFunction (0x004CCE90) with the global system, world position, slot data and the a4 parameter. Called by sub_4EE2D0 (0x004EE2D0).
- `0x004E1FD0` **CameraTransform** — Pure 3D math helper with no callees, globals or guards: multiply the 3x3 rotation matrix at this+0x20..0x40 by the vector at this+0x8E8/0x8EC/0x8F0, add a translation offset read just before the matrix (this+0x08/0x0C/0x10 in the raw source), write the result to output a2, and copy this+0x14/0x18/0x1C into output a3; returns a3. Callers 0x00409A00, 0x0040B710, 0x00434D60.
- `0x004E2610` **SuspensionGeometryInitializer** — Initialize suspension geometry for a single wheel slot: compute the wheel offset vector by subtracting the chassis local origin (this+0x48/0x4C/0x50) from the input position a3, copy the suspension orientation matrix (0x24 bytes from a4) and the upright orientation matrix (0x24 bytes from a5) into per-wheel geometry storage, and extract Euler angles from both matrices with gimbal-lock handling (fabs of a matrix element equals 1.0 against global 0x0059E420; FloatConvertWrapper 0x00588570; alternate atan2 branch forcing the second angle to 0).

## Proposed classes

### VehicleObject

Vehicle object construction. The only class whose owner type (VehicleObject) is packet-derived. The constructor zero-initialises the struct (RaceStructInit 0x00423E80), marks the handle/ID at +0x4894 unset (-1), clears the driver-info substructure (VehicleDriverInfoClear 0x004C79E0), and stores a persistent self-reference (LargeStructFieldSetterWithStoredReference 0x00424040).

Methods: `0x004C6920`

- `this+0x00004894` `uint64 handle_or_id` (write, DERIVED)

### SuspensionTelemetryGauge

HUD gauge rendering for one corner's suspension/temperature state. Reads the per-corner input state object via dword_7C54E0 at a 296-byte stride; inactive corners blink red on parity of the CRTFtol(dbl_8AFEA0) value, active corners draw three color-encoded segments from the corner temperature table or a plain green bar depending on a per-car +18580 comparison. No this-relative fields are evidenced; the object consumed is a global-indexed state block.

Methods: `0x0049E570`


### VehicleProximityScanner

Finds the nearest (smallest positive delta) candidate vehicle to a target slot by scanning the dword_7C54F0 pointer array. Live candidates evaluate through AIDelegateCall and SpeedDeltaComputation; null slots fall back to the base vehicle data at +15016. No this-relative fields are evidenced.

Methods: `0x004A4710`


### VehicleCollisionAvoidanceController

Per-frame collision-avoidance state machine over an avoidance sub-object. Gates on the sub-object pointer at this+0x14, reads the movement-threshold flag on the dereferenced object (+0x39A0) and the position-change monitor, computes the normalized movement delta, and tests every other active vehicle's direction for an approaching path (0 < t < 5.5). Owns the avoidance state field at this+0x8C and a related flag at this+0x78.

Methods: `0x004A6B80`

- `this+0x00000000` `void* object_ptr` (read, DERIVED)
- `this+0x00000004` `int32 own_vehicle_index` (read, DERIVED)
- `this+0x00000014` `void* avoidance_sub_object` (read, DERIVED)
- `this+0x00000078` `uint32 avoidance_flag_field` (read, GUESS)
- `this+0x0000008C` `int32 avoidance_state` (read, DERIVED)
- `obj+0x000039A0` `float movement_threshold_flag` (read, DERIVED)
- `obj+0x000034E0` `float own_direction_x` (read, GUESS)
- `obj+0x000034E4` `float own_direction_y` (read, GUESS)
- `obj+0x000034E8` `float own_direction_z` (read, GUESS)

### PackedOrientationCodec

Packed fixed-point orientation codec pair sharing an identical unpack/bitfield tail. 0x004B2DD0 converts packed int16 Euler components (this+9/+11/+13, scale 0.015625) and packed dwords (this+0/+2/+4/+8, scale 0.000030517578) into a float triple plus two bitfield parameters with an orthonormal-basis / Euler extraction pipeline; 0x004B32A0 runs the same tail to pack a fixed-point triple into a collision vertex output. Common ownership is structurally clear but the shared owning object is unknown.

Methods: `0x004B2DD0`, `0x004B32A0`

- `this+0x00000000` `uint32 packed_word_0` (read, DERIVED)
- `this+0x00000002` `uint16 packed_word_1` (read, DERIVED)
- `this+0x00000004` `uint32 packed_dword` (read, DERIVED)
- `this+0x00000008` `uint8 packed_byte` (read, DERIVED)
- `this+0x00000009` `int16 orientation_int16_0` (read, DERIVED)
- `this+0x0000000B` `int16 orientation_int16_1` (read, DERIVED)
- `this+0x0000000D` `int16 orientation_int16_2` (read, DERIVED)

### VehicleIdentityComparer

Thiscall identity/path comparison used by the vehicle instance list builder to match a vehicle's identity strings against a path-derived name. Compares the trailing filename of the path at a2+18196 with this+65 and the string at this+1 with a2+17952. The compared strings at this+1 and this+65 are caller-defined and have no packet field evidence.

Methods: `0x004B5120`


### VehicleLifetimeStateAccessor

Single-pointer-hop accessor: reads the float at object+0xF30 through the object pointer stored at this+0x0 and returns it. The 'lifetime average' meaning is a DERIVED label from existing analysis and the ABI legacy name; the field could be any scalar quantity. The raw source declares a double return while a 32-bit float is loaded (unreconciled in this packet).

Methods: `0x004B9CB0`

- `this+0x00000000` `void* target_object` (read, DERIVED)
- `obj+0x00000F30` `float lifetime_average` (read, DERIVED)

### CollisionParticleEffectManager

Collision-contact particle emitter group. 0x004CB620 spawns spark particles from the circular buffer with trig-table sizing and array/flag publishing; 0x004CE3E0 dispatches per frame over the effect slot array (this+0x3C count, this+0x40 array, type id at slot+4) with throttling and weather-flag selection; 0x004CE930 emits trail particles from three slot pointers (this+0x20/0x24/0x28) under movement and throttle gates. All three share the dword_7CF8A8 / dword_8AB6E4 / dword_7C5698 throttle globals and the flt_8AB274 / dword_8AAE70 jitter source.

Methods: `0x004CB620`, `0x004CE3E0`, `0x004CE930`

- `this+0x0000000C` `int32 array_flag_param_0` (read, GUESS)
- `this+0x00000010` `int32 array_flag_param_1` (read, GUESS)
- `this+0x00000014` `int32 array_flag_param_2` (read, GUESS)
- `this+0x00000020` `void* trail_slot_ptr_0` (read, DERIVED)
- `this+0x00000024` `void* trail_slot_ptr_1` (read, DERIVED)
- `this+0x00000028` `void* trail_slot_ptr_2` (read, DERIVED)
- `this+0x0000003C` `int32 effect_slot_count` (read, DERIVED)
- `this+0x00000040` `void* effect_slot_array` (read, DERIVED)
- `*(this+0x40)+0x00000004` `int32 effect_slot_type_id` (read, DERIVED)
- `this+0x00000048` `float spark_size_threshold` (read, GUESS)
- `this+0x0000004C` `float contact_point_scale` (read, GUESS)
- `this+0x00000058` `int32 slot_counter` (read, DERIVED)

### WheelContactParticleLookup

Searches a strided array (count this+0x10, first element this+0x14, 108-byte stride) for the first entry whose +4 field equals a3 and spawns a wheel contact particle via WheelContactParticle (0x004CD6C0). Element layout beyond the +4 matching slot is unknown.

Methods: `0x004CEFA0`

- `this+0x00000010` `int32 element_count` (read, DERIVED)
- `this+0x00000014` `void* element_array` (read, DERIVED)
- `*(this+0x14)+0x00000004` `int32 match_slot_id` (read, DERIVED)

### ParticleWorldTransform

Transforms up to 17 particle-emitter positions (this+0x998, 7 floats per slot) from local to world space through the a2 rotation matrix and a3 translation, then spawns via ParticleSpawnFunction (0x004CCE90). Gated on the global particle-system pointer dword_8ACEB8.

Methods: `0x004E16F0`

- `this+0x00000998` `float[119] emitter_slots` (read, DERIVED)
- `this+0x0000099C` `float emitter_slot_component` (read, DERIVED)

### VehicleSlotActivator

Claims the first inactive vehicle slot by scanning the dword_7C54F0 pointer table over dword_5C329C slots for an in-use flag at +0x4064 (16484) equal to zero, setting it to 1 (unless the sentinel 3), and returning slot base + 0x4034 (16436). No this-relative fields are evidenced.

Methods: `0x004D2450`


### TransformMatrixComposer

Builds four 4x4 transform matrices on the stack from a2 (negated when positive), a3 (clamped to [0,1]) and a4 (scalar power/twist base), combines them through sub_5677B0 (0x005677B0), and writes the combined eight-dword result into this+0x0..0x1C (identity on failure). Stores the input scalar a4 as a double at this+0x20. Callers include a brake-temperature fade model and a tire-compound physics application.

Methods: `0x004D5C70`

- `this+0x00000000` `float transform_dword_0` (write, DERIVED)
- `this+0x00000004` `float transform_dword_1` (write, DERIVED)
- `this+0x00000008` `float transform_dword_2` (write, DERIVED)
- `this+0x0000000C` `float transform_dword_3` (write, DERIVED)
- `this+0x00000010` `float transform_dword_4` (write, DERIVED)
- `this+0x00000014` `float transform_dword_5` (write, DERIVED)
- `this+0x00000018` `float transform_dword_6` (write, DERIVED)
- `this+0x0000001C` `float transform_dword_7` (write, DERIVED)
- `this+0x00000020` `double input_scalar` (write, DERIVED)

### VehicleLapGapStateTracker

Updates a per-vehicle lap-gap state object: selects one of two time sources on the player vehicle pointer dword_7C54E0 (offsets 16592/16596), records the source byte flag at +0x18 and the value at +0x1C, computes the gap into +0x14 via LapTimeGapCalculation (0x0049B6D0), and dispatches VTableDispatchWithFieldClear (0x004D7E30) on zero/negative gap or non-zero returns.

Methods: `0x004D9FE0`

- `this+0x00000014` `float gap` (read_write, DERIVED)
- `this+0x00000018` `uint8 comparison_source_flag` (write, DERIVED)
- `this+0x0000001C` `float comparison_value` (write, DERIVED)

### RaceCompletionMonitor

Race-progress counting and completion checks over the active-vehicle array. 0x004DA990 counts vehicles whose progress field (vehicle_ptr + 16444) meets the threshold at this+0x24; 0x004DAD80 combines the race-end condition, the stored count at this+0x20 and a one-shot trailing-vehicle walk (flag this+0x28) to confirm race completion. Shares the dword_7C54F0 / dword_5C329C array and count globals.

Methods: `0x004DA990`, `0x004DAD80`

- `this+0x00000020` `int32 stored_count` (read, DERIVED)
- `this+0x00000024` `int32 progress_threshold` (read, DERIVED)
- `this+0x00000028` `uint8 one_shot_check_flag` (read_write, DERIVED)

### PhysicsConstantSeed

Minimal thiscall constant initializer: stores 1082130432 (4.0f) into the dword at this+0x10 and returns it. Structural twin of ConstantReturnSetter (0x004DB100); likely seeds a per-object physics/scalar field. The object identity is unconfirmed and the global dword_5ACF5C may or may not source the constant.

Methods: `0x004DB130`

- `this+0x00000010` `float seeded_constant` (write, DERIVED)

### CameraTransform

Packet-derived CameraTransform owner. Pure 3D math helper: multiplies the 3x3 rotation matrix at this+0x20..0x40 by the point at this+0x8E8/0x8EC/0x8F0, adds a translation offset (read just before the matrix in the raw source), writes the result to output a2, and copies this+0x14/0x18/0x1C into output a3. The translation addend offsets this+0x08/0x0C/0x10 have no packet field evidence.

Methods: `0x004E1FD0`

- `this+0x00000014` `float copy_vector_x` (read, GUESS)
- `this+0x00000018` `float copy_vector_y` (read, GUESS)
- `this+0x0000001C` `float copy_vector_z` (read, GUESS)
- `this+0x00000020` `float rotation_00` (read, DERIVED)
- `this+0x00000024` `float rotation_01` (read, DERIVED)
- `this+0x00000028` `float rotation_02` (read, DERIVED)
- `this+0x0000002C` `float rotation_10` (read, DERIVED)
- `this+0x00000030` `float rotation_11` (read, DERIVED)
- `this+0x00000034` `float rotation_12` (read, DERIVED)
- `this+0x00000038` `float rotation_20` (read, DERIVED)
- `this+0x0000003C` `float rotation_21` (read, DERIVED)
- `this+0x00000040` `float rotation_22` (read, DERIVED)
- `this+0x000008E8` `float point_x` (read, DERIVED)
- `this+0x000008EC` `float point_y` (read, DERIVED)
- `this+0x000008F0` `float point_z` (read, DERIVED)

### SuspensionGeometryInitializer

Initializes suspension geometry for a single wheel slot: computes the wheel offset vector from the chassis local origin (this+0x48/0x4C/0x50), copies the suspension and upright orientation matrices into per-wheel geometry storage, and extracts Euler angles with gimbal-lock handling.

Methods: `0x004E2610`

- `this+0x00000048` `float chassis_origin_x` (read, DERIVED)
- `this+0x0000004C` `float chassis_origin_y` (read, DERIVED)
- `this+0x00000050` `float chassis_origin_z` (read, DERIVED)

## Compatibility contracts

- **ActiveVehicleArrayContract** — The active-vehicle pointer array at dword_7C54F0 (slot count dword_5C329C, end sentinel byte_7C5690, player pointer dword_7C54E0 / dword_7C54E8) must remain walkable by index over the slot count, and per-slot offsets +0x403C (progress), +0x4064 (in-use flag) and +16480 (tracked count) must keep their meanings. A replacement must preserve the array base, the count global, and the sentinel terminator semantics.
- **VehicleSlotActivationContract** — Claiming the first inactive vehicle slot requires scanning the dword_7C54F0 table over dword_5C329C slots, reading the in-use flag at slot+0x4064 (16484), never overwriting the sentinel value 3, writing 1 for a free slot, and returning slot base + 0x4034 (16436), or the slot count when no slot is free.
- **LapGapStateUpdateContract** — The lap-gap state object reads one of two time values from the player vehicle pointer dword_7C54E0 at offsets 16592/16596, records the chosen source byte at +0x18 and the value at +0x1C, computes the gap into +0x14 via LapTimeGapCalculation (0x0049B6D0), and dispatches VTableDispatchWithFieldClear (0x004D7E30) on a zero/negative gap or a non-zero gap-calculation return.
- **RaceCompletionContract** — Race completion is confirmed when the race-end condition (ArithmeticComparison_ae80) holds or the stored count at this+0x20 equals the tally; the finished count derives from the per-vehicle progress at vehicle_ptr + 16444 (0x403C) compared with the threshold at this+0x24, and the one-shot trailing-vehicle walk (flag this+0x28) resolves indices through sub_4D1B50 over dword_8ACEE0 indexing dword_5F073C at stride 4656.
- **CollisionAvoidanceContract** — The per-frame avoidance check must gate on the avoidance sub-object at this+0x14, read the movement-threshold flag on the dereferenced object (+0x39A0), test approach time 0 < t < 5.5 against other active vehicles (activity byte at +13388, direction at +13560/+13564/+13568), clear the collision flag on predicted collision, transition avoidance state 1 -> 2 (optionally raising the flag-field bit), invoke the utility handler when a collision is predicted while in state 2, and return the current state.
- **PackedOrientationContract** — Packed orientation structs must decode the int16 components at this+9/+11/+13 scaled by 0.015625 and the packed dwords at this+0/+2/+4/+8 scaled by 0.000030517578 into a float triple at output a2+8/+12/+16, producing an orthonormal basis with Euler angles (gimbal fallback) and two bitfield parameters, with a3 stored at a2+4.
- **ParticleEmitterWorldTransformContract** — The emitter must guard on the global particle-system pointer dword_8ACEB8, walk the 17-slot emitter array at this+0x998 (7 floats per slot), rotate each active slot position by the a2 matrix, add the a3 translation, and spawn through ParticleSpawnFunction (0x004CCE90).

## Unresolved

- 0x0049E570: dword_7C54DC, dword_7C54E4, dbl_8AFEA0, the temperature table base 8157696, FloatToColorEncoding, RenderDrawOperationWithClipping and CRTFtol appear in the raw source but have no packet-level evidence entries; the meaning of the +18580 comparison and the physical meaning of the temperature table are not evidenced; the 296-byte corner stride and the +2100/+2164 gate offsets are read from the raw source arithmetic with unknown field names.
- 0x004A4710: flt_59E440's exact zero-threshold value is DERIVED not confirmed; AIDelegateCall's return semantics and the +13000/+15016 base-data meanings are unknown; the stride/type of the this[4*a2] target-slot table and whether a2 indexes slots or grid positions is unresolved.
- 0x004A6B80: the owner type and identity of the avoidance sub-object and the enclosing object are unknown; the deterministic fields at this+0x8C/0x78 and the raw sub-object dword indices [30]/[25] do not bind consistently; globals flt_59E43C, flt_59E440 and flt_59E918 are listed by the global table but absent from the raw text; FlagFieldBitManipulation and UtilityFunction_4000 have no addresses; the 5.5 approach window and the +13560/+13564/+13568 direction offsets are verbatim raw-source literals.
- 0x004B2DD0: globals dbl_59E420, flt_59E43C, flt_59E440, flt_59E670, flt_59E778 and flt_59E780 are recorded as read but folded out of the decompiled text (likely scale/threshold constants); the packed-struct field meanings (Euler angles, orientation basis, bitfield parameters) are inferred; the sign/negation sequence around FloatConvertWrapper is not established.
- 0x004B32A0: global flt_59E780 is likely the folded 0.000030517578 scale; the semantic meaning of the two bitfield parameters is not established; the shared owning object with the sibling 0x004B2DD0 is structurally clear but unknown.
- 0x004B5120: the type of object a2 (owner of offsets 18196 and 17952) and the meanings of the identity strings at this+1 and this+65 are caller-defined; the unsigned pointer-boundary comparison when the path contains no backslash is inferred from the fall-through return.
- 0x004B9CB0: the owning class of both this and the dereferenced object is unknown; the float at object+0xF30 is a DERIVED 'lifetime average' label; the raw source declares a double return while a 32-bit float is loaded (unreconciled).
- 0x004C6920: the semantic purpose of the handle/ID at +0x4894 beyond 'default-initialised to unset' is not established; construction context from caller RepeatedCallLoop (0x0042BB50) is unresolved.
- 0x004CB620: globals flt_59E43C, flt_59E708, flt_59E7F8, flt_59E84C and flt_5ACEA8 are listed but absent from the raw text; the meaning of slot[7]'s prior value, the constants 64.0/190.0/0.25/0.1 and the packed stack dwords, and the slot[12] fallback value are unexplained; the owner class is unknown.
- 0x004CE3E0: globals flt_59E43C, flt_59E440, flt_59E7F8, flt_59E84C and flt_59E868 are listed but absent from the raw text; owner object, parameter semantics and the exact type-id enumeration are not evidenced; the byte_7CF9D4/byte_7CF9EC to emitter-persistence mapping (1, -1, 104) is reconstructed, not confirmed.
- 0x004CE930: the emitter-mode magic values 104 and -1 (a6) are unexplained; the slot thresholds and scaling factors (0.15000001/0.059999999/1.0/0.16000001, 0.25/0.1/0.0125) are inlined literals whose binding to the float globals (flt_59E43C, flt_59E440, flt_59E454, flt_59E7F8, flt_59E84C, flt_59E868, flt_5ACECC, flt_5ACED0) is not evidenced; the a2 state layout is used via raw pointer arithmetic.
- 0x004CEFA0: the element layout beyond the +4 matching slot is unknown; the 108-byte stride structure is not described by the packet; the semantics of a2/a4/a5 passed to WheelContactParticle depend on that callee's signature.
- 0x004D2450: the meaning of the flag sentinel value 3 (player-owned or permanently-active slot) is unknown; the slot stride is not established here.
- 0x004D5C70: the semantics of sub_5677B0's matrix combination are not established by this packet; the interpretation of the eight-dword output as quaternion versus 4x4 transform, and which callers consume it, is unconfirmed; the equality of dbl_59E7E0 to the literal 3.0 is inferred.
- 0x004D9FE0: the dword_7C54E0 offsets 16592/16596 (the two comparison time sources) are not named; flt_59E440 and unk_7CE234 are listed but absent from the raw text; the polarity of the byte flag at +0x18 and the purpose of the v6 gap flag are understood only structurally.
- 0x004DA990: the per-vehicle field at byte offset 16444 (0x403C) is a DERIVED 'lap progress' label; the fill's prose cites 0x406C which does not match the deterministic displacement 16444 = 0x403C; the threshold field this+0x24 meaning is DERIVED.
- 0x004DAD80: the meaning of this+0x20 and how it is populated is not established; the interpretation of dword_5F073C entries and the 4656 stride depend on the vehicle array layout; the exact condition evaluated by ArithmeticComparison_ae80 is not visible here.
- 0x004DB130: facts record a read of global dword_5ACF5C but the raw body emits only the immediate 1082130432; whether that global is the constant's source or an unrelated read is unresolved; the object this refers to is unconfirmed.
- 0x004E16F0: dword_8ACEB8 (particle-system pointer), the a2 rotation matrix and a3 translation are only named as data locations; the emitter slot stride of 7 floats and the active-flag/extra-byte/trailing-slot layout are inferred from the raw layout.
- 0x004E1FD0: the translation addend is read at this+0x08/0x0C/0x10 in the raw source but those offsets have no packet evidence reference; the existing-analysis labels (quaternion vs matrix row) disagree with the raw access pattern; the role of the a3 copy is uncharacterized.
- 0x004E2610: FloatConvertWrapper (0x00588570) semantics, the atan2 argument order / Euler rotation convention, the row vs column-major layout of the 0x24-byte matrices, and the role of the negated field at v5+128 are not confirmed.
- Whether the gauge, particle, race-state and transform functions all belong to the vehicle-physics subsystem is manifest-scope derived, not evidence-proven from the packet alone.
