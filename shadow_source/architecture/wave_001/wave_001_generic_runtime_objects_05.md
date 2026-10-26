# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

DERIVED-source architecture proposal for a grab-bag of generic runtime objects. SceneRenderUpdate (0x004C6D90, VehicleObject, DERIVED) is the per-frame entry point; it drives a starting-grid data-dispatch chain (0x004D10E0/0x004D1100/0x004D1140) backed by the grid-slot allocator 0x004C6F10, all reading the setup-scene array dword_5EA2C0. TelemetrySession (0x004D4A80, DERIVED) writes a CSV-style session file with a fixed header, checksums and XOR-decoded driver data. Steward_Post (0x004D4600) tears down audio/comparison/camera state and resets every vehicle substate. UpdateRenderState (0x004E0ED0, VehicleRenderStateController, DERIVED) drives HUD widget visibility by render mode 0-3. A cluster of physics helpers (0x004E87E0, 0x004E8B80, 0x004E9630) reads a shared this+0x34xx..0x3Dxx region. VibrationStateMachine (0x004E2230) is an OFF/LOW/HIGH magnitude-gated force-feedback machine. SplitPathAndWriteDebugLog + DebugLogWrite (0x004D7A50/0x004D7AA0) form a level-gated debug log service. Most owners are UNKNOWN in the packet and are grouped into GUESS classes on shared-field evidence only.

## Function roles

- `0x004C6D90` **VehicleObject** — Per-vehicle scene render update on the frame path: resets respawn state, applies large physics-config constants, delegates to a global-instance callback, dispatches grid-position and render data through the grid dispatch chain, initializes the AI driver struct, runs the vehicle frame update, clears render-flag bit 23 at +0x48B4, updates force feedback on the global base, and runs a collision wrapper when the session-time threshold is not positive.
- `0x004C6F10` **VehicleGridPositionManager** — Starting-grid slot allocator: seeds the slot index from this+0x48A4 = this+0x4894 modulo 52, scans up to 52 slots for an unoccupied one, derives a column-order permutation from this+0x4710, copies the slot position from the setup scene, checks the live vehicle array for a peer occupant of the same slot/column pair, falls back to a rescan, and writes -1 to both indices on failure.
- `0x004D10E0` **VehicleGridPositionManager** — Thin grid-data dispatch: reads the dword at this+0x4058, decrements it by 1, and forwards it as the index argument to the setup-scene array accessor along with dword_5EA2C0 and two passthrough pointers; returns that callee's result unchanged.
- `0x004D1100` **VehicleGridPositionManager** — Conditional grid-position sync: when the signed grid index at this+0x48A4 is negative (unallocated) it recalculates via 0x004C6F10, then copies grid-slot data from the setup-scene array via ArrayOfStructIndexedFieldCopy and returns that copy's result.
- `0x004D1140` **VehicleGridPositionManager** — Guarded render-data read: when the grid index at this+0x48A4 is negative it allocates a grid position via 0x004C6F10, then reads indexed struct data from the setup scene via IndexedStructDataRead(dword_5EA2C0, this+0x48A4, this+0x48A8, a2, a3) and returns its result.
- `0x004D1CF0` **UnknownObject** — Ring-buffer element accessor: truncates a float index scaled by this+0x108, wraps a negative index by adding the buffer size at this+0x10C, clamps into [0, size-1], and returns the first DWORD of the 8-byte-stride element at this+0x110.
- `0x004D4600` **Steward** — Steward post-race cleanup: logs entry, frees the D3D audio state pointer at +0xA8, resets comparison/camera-director state, frees state arrays at +0x110/+0x114, conditionally refreshes season scoring, resets every vehicle substate, frees the counted array at +0x1AC, and zeroes 52 dword-pairs at +0x1B0/+0x280.
- `0x004D4A80` **TelemetrySession** — Telemetry session start and header write: tears down previous telemetry state, gates on the scoring check, scans the live vehicle array for the player slot, opens the output stream, computes a 1-40 Hz sampling rate, writes the CSV-style column headers (base, per-wheel and tail channels), embeds XML scene config and integrity checksums, XOR-decodes driver data, and frees scratch allocations.
- `0x004D7570` **UnknownObject** — Compound index lookup: validates a2 against the range [0, this+0x10), returns a pointer to the a2-th compound entry at this+0x14 + 680*a2, and on out-of-range index conditionally logs a tire-brand error and returns 0.
- `0x004D7A50` **DebugLogWriter** — Level-gated debug log helper: returns 0 when the severity dword at this+0x0 is below the a2 threshold; otherwise walks a backslash-delimited path via sub_587C20 and emits a formatted debug log entry via DebugLogWrite, returning 1.
- `0x004D7AA0` **DebugLogWriter** — Formatted debug log writer: writes the message through the file handle at this+0x4 via FileWriteWrapperWithLock, then flushes/synchronizes via LockCallUnlockWrapper on the same handle and returns its result.
- `0x004DD7C0` **UnknownObject** — Scene-graph vertex finder: computes a LOD threshold, iterates the node's children, filters each child by its LOD level, scans the child's packed vertex array, keeps the vertex whose dot product with the direction vector is maximal, writes its coordinates to a3, and returns the child count.
- `0x004E0ED0` **VehicleRenderStateController** — Per-car render/UI-widget visibility update: resolves the effective render mode (default 3, overridden by a2 when the obj+0x48BC flags word has bit 1 set) and stores it to this+0x964; computes a HUD gate from byte_7CE254/dword_7D0410; switches on the mode to show or hide a large widget-flag set, performs player-only session-phase audio transitions, and runs an 8-entry per-widget loop.
- `0x004E17C0` **SubsystemSlotLifecycle** — Subsystem slot lifecycle dispatcher: switches on slot id a2 (0-13); array-backed slots 0-3 route to SubslotCleanup on activation or ArrayEntryCleanup on deactivation, while pointer-backed slots 4-13 route to LazyInitCallback on activation or ConditionalResourceRelease on deactivation.
- `0x004E2230` **ForceFeedbackController** — Vibration/force-feedback state machine: maps |a3| below 16.0 to OFF (0), 16.0-64.0 to LOW (1), and 64.0+ to HIGH (2); on a state change stores the new state at this[74*a2+123], updates the primary slot via sub_5506A0, and iterates the sound-effect slot array applying sub_5506A0 to each non-zero entry.
- `0x004E87E0` **VehiclePhysicsState** — Brake thermal model: computes a normalized brake thermal factor clamped to [0,1] from a squared suspension-displacement residual, two thermal conversion factors, a heat-capacity term, an offset and a range denominator; returns 0.0 when either divisor is zero.
- `0x004E8B80` **VehiclePhysicsState** — Aerodynamic force calculation: computes a force from squared speed with a gravity weight-compensation term, a 14-entry linearly-interpolated table lookup, a drag cross-term, and a quadratic-form correction branch; invokes sub_5895A2 on the intermediate force with the result discarded.
- `0x004E9630` **VehiclePhysicsState** — Position-change monitor: conditionally registers the current position triplet (this+0x34D4..0x34DC) with the tracking service via sub_403640, saves the previous position into the history slots this+0x3AA0..0x3AA8, and returns the tracking handle at this+0x3A9C.
- `0x004EF930` **UnknownObject** — Race-start countdown advance: clears the in-progress flag each frame, resets phase/timer/step when a2 is zero, otherwise triggers the countdown sound effect, reloads the timer from step-interval fields, records telemetry on the green-light step, and performs the final-step phase transition.
- `0x004EFAC0` **UnknownObject** — Conditional reset: when the value at this+0x32BC is non-zero, clears the field at this+0x3994; otherwise writes 0 to the global byte_7C9081; returns the read value. On the per-frame AI path.

## Proposed classes

### VehicleObject

Per-vehicle per-frame scene/render orchestration: respawn reset, physics-config application, grid-data dispatch, AI driver init, vehicle frame update, render-flag maintenance, force-feedback and collision wrapper invocation.

Methods: `0x004C6D90`

- `this+0x000048B4` `dword bitmask renderFlagBitmask` (write, DERIVED)

### VehicleGridPositionManager

Starting-grid slot allocation and dispatch of grid-slot data from the setup-scene array dword_5EA2C0; tracks each vehicle's grid slot index, team-column index and column-order permutation.

Methods: `0x004C6F10`, `0x004D10E0`, `0x004D1100`, `0x004D1140`

- `this+0x000048A4` `signed dword gridSlotIndex` (read_write, DERIVED)
- `this+0x000048A8` `signed dword gridColumnIndex` (read_write, DERIVED)
- `this+0x00004894` `dword gridSeedValue` (read, GUESS)
- `this+0x00004058` `dword gridArrayIndexMinusOne` (read, GUESS)
- `this+0x00004710` `dword columnOrderPermutation` (read, GUESS)

### TelemetrySession

Telemetry output session: opens and owns the output stream, computes the sampling rate, writes the CSV-style header, integrity checksums and XOR-decoded driver data, and frees its scratch state.

Methods: `0x004D4A80`

- `this+0x00000000` `pointer outputHandle` (write, DERIVED)
- `this+0x00000004` `dword samplingRateHz` (write, DERIVED)
- `this+0x0000000C` `dword headerByteOffsetA` (write, GUESS)
- `this+0x00000010` `dword headerByteOffsetB` (write, GUESS)
- `this+0x00000014` `dword headerByteOffsetC` (write, GUESS)
- `this+0x00000018` `dword headerByteOffsetD` (write, GUESS)

### Steward

Steward post-race cleanup: release audio/comparison/camera-director state, refresh season scoring, reset every vehicle substate, and free counted containers.

Methods: `0x004D4600`

- `this+0x000000A8` `pointer audioStatePtr` (read_write, GUESS)
- `this+0x0000010C` `dword resetCounterField` (write, GUESS)
- `this+0x00000110` `pointer stateArrayPtr` (read_write, GUESS)
- `this+0x00000114` `pointer stateArrayPtr2` (read_write, GUESS)
- `this+0x000001A8` `dword countedArrayCount` (write, GUESS)
- `this+0x000001AC` `pointer countedArrayPtr` (read_write, GUESS)

### VehicleRenderStateController

Per-car render/UI-widget visibility: resolves the render mode, toggles the HUD widget flag set, and manages player-only session-phase audio state on the frame path.

Methods: `0x004E0ED0`

- `this+0x00000964` `dword enum renderMode` (write, DERIVED)
- `this+0x0000096C` `byte hudMasterFlag` (read, DERIVED)
- `this+0x0000096D` `byte driverModelVisibleFlag` (read, DERIVED)
- `this+0x00000004` `dword flag activeWidgetFlag` (read, DERIVED)
- `this+0x0000088C` `dword flag cockpitWidgetFlag` (write, GUESS)
- `this+0x00000890` `dword flag suspensionWidgetFlag` (write, GUESS)
- `this+0x00000894` `dword flag helmetWidgetFlag` (write, GUESS)
- `this+0x00000898` `dword flag armsWidgetFlag` (write, GUESS)
- `this+0x0000089C` `dword flag bodyWidgetFlag` (write, GUESS)
- `this+0x000008A0` `dword flag wheelWidgetFlag` (write, GUESS)
- `this+0x0000066C` `array[8] of 17-dword entries widgetEntryArray` (read_write, GUESS)
- `this+0x00000144` `dword flags (0x144/0x188/0x26C/0x2B0/0x394/0x4BC/0x5E4/0x628) widgetGroupFlags` (write, GUESS)

### SubsystemSlotLifecycle

Lifecycle dispatch over 14 subsystem slots: array-backed slots 0-3 and pointer-backed slots 4-13 with lazy-init and conditional-release transitions.

Methods: `0x004E17C0`

- `this+0x00000628` `pointer or dword flag slotPointerOrInitFlag` (read, GUESS)
- `this+0x00000668` `byte slotInitFlagByte` (read, GUESS)

### ForceFeedbackController

Vibration/force-feedback magnitude state machine and per-slot vibration application.

Methods: `0x004E2230`

- `this+0x00000B6C` `dword/float vibrationIntensity` (read, GUESS)

### DebugLogWriter

Level-gated formatted debug log emission: severity gate, backslash path walk, formatted write and handle flush.

Methods: `0x004D7A50`, `0x004D7AA0`

- `this+0x00000000` `dword severityLevel` (read, GUESS)
- `this+0x00000004` `handle/pointer logFileHandle` (read, GUESS)

### VehiclePhysicsState

Shared vehicle physics/suspension substruct region: brake thermal, aerodynamic force and position-tracking helpers reading the this+0x34xx..0x3Dxx offset range.

Methods: `0x004E87E0`, `0x004E8B80`, `0x004E9630`

- `this+0x000039C8` `float thermalCapacityDivisor` (read, DERIVED)
- `this+0x000039AC` `float thermalRangeDenominator` (read, DERIVED)
- `this+0x000039A8` `float thermalOffset` (read, GUESS)
- `this+0x00003D40` `float thermalConversionFactorA` (read, GUESS)
- `this+0x00003D44` `float thermalConversionFactorB` (read, GUESS)
- `this+0x00003500` `float suspensionDisplacement` (read, GUESS)
- `this+0x000034B8` `float triplet (0x34B8/0x34C4/0x34D0) rotationMatrixRow` (read, GUESS)
- `this+0x00003A58` `float triplet (0x3A58/0x3A5C/0x3A60) localAnchorPoint` (read, GUESS)
- `this+0x00003A70` `float aeroCoefficient` (read, GUESS)
- `this+0x00003514` `float sprungMassFactor` (read, GUESS)
- `this+0x00003518` `float forceFactor` (read, GUESS)
- `this+0x00003BFC` `float forceScaleFactor` (read, GUESS)
- `this+0x00003C00` `float[14] aeroLookupTable` (read, GUESS)
- `this+0x00003D3C` `float maxForceCap` (read, GUESS)
- `this+0x000034D4` `float triplet (0x34D4/0x34D8/0x34DC) currentPosition` (read, GUESS)
- `this+0x00003A9C` `pointer trackingHandle` (read_write, GUESS)
- `this+0x00003AA0` `float triplet (0x3AA0/0x3AA4/0x3AA8) previousPosition` (write, GUESS)

## Compatibility contracts

- **TelemetryFileFormat** — Telemetry session output file layout: stream opened via sub_587DB0; 4 random seed bytes written first; header byte offsets derived from the seed bytes at this+0xC/+0x10/+0x14/+0x18; magic header integer 1028443341 written via sub_4D5BE0; player vehicle name/description strings and scene path; field-delimiter byte 4; NUL-terminated column-name headers (ElapsedTime, PosX, PosY, PosZ, Yaw, LatAccel, VertAccel, LongAccel, EngineRPM, ClutchRPM, UnfilteredThrottle, Throttle, UnfilteredBrake, Brake, UnfilteredSteering, Steering, UnfilteredClutch, Clutch; per-wheel WheelspinRadsS, SuspensionDefl, UndertrayRideH, TyreLeftTempK, TyreCenterTemp, TyreRightTempK, TyrePressureKpa, TyreWear, CornerWeight; then Gear, WaterTemperatu, OilTemperature); embedded XML scene configuration; integrity checksums (deterministic pseudo-random values, XOR/arithmetic-obfuscated vehicle/tyre/session values); XOR-decoded driver telemetry data appended. Sampling rate computed as 10 * trunc(40.0 / dword_7CE9D0 + 0.5) then clamped to 1..40.
- **GridSlotAllocationContract** — Each vehicle's starting-grid slot is identified by a signed index at +0x48A4 and a team-column index at +0x48A8; a negative +0x48A4 means unallocated and triggers recalculation via 0x004C6F10; the grid has 52 slots (index seeded as this+0x48A4 = this+0x4894 modulo 52); slot occupancy is determined by copying the slot position from the setup-scene array (dword_5EA2C0) and testing for a near-zero vector; allocation failure is signalled by writing -1 to both +0x48A4 and +0x48A8.
- **VehicleArrayLayout** — Live vehicle pointer array dword_7C54F0 holds dword_5C329C entries; the player slot is identified by scanning for the first entry whose int32 at +13000 equals 0; each vehicle carries a substruct at +0x4034 (16436) that is reset via 0x004BB950; peer slot/column fields are read at +18596 and +18600.
- **DebugLogHandleProtocol** — Debug log context object holds a severity level at +0x0 and a file handle at +0x4; the level-gated path walker (0x004D7A50) emits entries only when the severity is at or above the caller threshold; formatted writes go through FileWriteWrapperWithLock (0x0058A163) followed by LockCallUnlockWrapper (0x00589FFD) on the same handle; the shared log context global is dword_8AD25C.

## Unresolved

- Exact meaning of the a2 flag (SLOBYTE in the respawn reset, LOBYTE in the two guards) in SceneRenderUpdate is not confirmed by the packet.
- Purposes of sub_4BB810, sub_4C6B60, sub_4D1180, sub_4D1670, LargeConfigFunctionWithPhysicsConstants (0x004E45B0) and CollisionWrapperWithLock (0x004E4910) are described from the corpus fill; the packet does not define their behavior.
- Layout of the 12-byte v4/v3 buffers consumed by the SingleFunctionDispatch_10e0 / ConditionalDelegateDispatch / RenderCallWithGuard chain is unknown.
- The this+3 (byte offset 12) and this+4109 (byte offset 16436 = 0x4034) substructs used by SceneRenderUpdate have no packet evidence refs of their own; their contents are not described.
- The owner of the grid-position functions (0x004C6F10, 0x004D10E0, 0x004D1100, 0x004D1140) is UNKNOWN in the packet; the shared base+offsets 0x48A4/0x48A8 across 0x004C6F10/0x004D1100/0x004D1140 make a common owner likely but unproven, so VehicleGridPositionManager is only a GUESS.
- The parity test ((v4 & 1) != v4 < 13) on this+0x4710 is a grid-layout heuristic whose exact semantics (DERIVED forward/reverse column order) are unproven.
- abi:lead LEGACY name AssignDriverGridPosition conflicts with the GridPositionAllocation interpretation; owner remains UnknownObject.
- Vehicle slot/column fields on peer vehicles at +18596 and +18600 are read as raw offsets, not packet field references.
- Purpose and semantics of the unnamed callee of 0x004D10E0 (forwarding the decremented this+0x4058 index into dword_5EA2C0) are unknown; why the index is decremented by 1 is not fully understood.
- The a2/a3 output parameters of IndexedStructDataRead (0x00403FC0) are not documented in the packet evidence.
- Ring buffer (0x004D1CF0): elements are 8-byte stride but only the first DWORD at +0 is returned; the second word at +4 is ignored. this+0x108 scaling and this+0x10C size semantics are inferred from the ring-buffer role; no structural confirmation.
- Steward_Post frees this+0x110 twice (two identical guard/free blocks); may be dead code or an intentional second pass.
- The counted-array header layout (count at ptr-4, elements at 8-byte stride) in Steward_Post is inferred from indexing, not from a named struct.
- Telemetry (0x004D4A80): globals flt_59E450, flt_59E86C, unk_5EC6D0, dword_8ACEA0 and callee 0x005881C0 are listed as read but absent from the decompiled body; their roles are unconfirmed. The final return path returns FreeWrapper_7bcf(v55[0]) directly, so its meaning as a success/failure indicator is ambiguous. Owner identity is DERIVED from the canonical name TelemetryDataDump and the LEGACY ABI lead; no confirmed class symbol is present in the packet.
- CompoundIndexLookup (0x004D7570): meanings of this[4] (compound count) and this[5] (base pointer, 680-byte stride) are DERIVED from existing-analysis prose; the raw source shows only the arithmetic. The purpose of the 954 source-line argument to the gating check is not confirmed.
- SplitPathAndWriteDebugLog (0x004D7A50): exact semantics of sub_587C20's return value and the identity of the walked string (a3) are DERIVED; the raw source does not name the string type. The format-string content a1212s5d (0x005D4A38) is not available in the packet.
- DebugLogWrite (0x004D7AA0): owner object type holding the file handle at +0x4 is unknown; the destination file is not evidenced.
- SceneGraphMaxDotProductFinder (0x004DD7C0): semantics of the child-node LOD flags (0x2000000, 0x40) and of the zero-compare at child+244 are unknown; values are preserved from raw source only.
- UpdateRenderState (0x004E0ED0): exact HUD-widget identities behind the numeric widget-flag slots are DERIVED from usage; the packet does not name them. dword_7CF860 is treated as a same-team/AI-team-count threshold but its precise semantics are unconfirmed. The audio playback byte obj+0xC4 and the audio-device state at dword_5EA528+52 are referenced through dereferenced globals whose owning structures are not evidenced. The LEGACY ABI name Audio_Sound_Effect_Controller is contradicted by the live-corrected analysis.
- subsystemSlotLifecycleDispatch (0x004E17C0): exact role of the byte data at 0x004E18B0 in the dispatch is unknown; the a3 activate/deactivate semantics rest on the existing-analysis label; the meaning of the returned value (slot id vs computed slot pointer) is unknown.
- VibrationStateMachine (0x004E2230): the pairing of threshold literals 16.0/64.0 with globals flt_59E708 / flt_59EED0 is not proven; the state slot this[74*a2+123] is an indexed array slot (stride 74 entries) whose meaning is unverified; unk_8AD3F8 as the iteration end bound has unknown type; sub_5506A0 semantics are DERIVED from existing analysis, not proven here.
- BrakeThermalModel (0x004E87E0): globals flt_59E43C / flt_59E440 are referenced in existing analysis as physics constants but have no usage site in the raw source; the rotation-row read order and anchor-point pairing are inferred from the skeleton; the exact meaning of the thermal factors 0x3D40/0x3D44 and the offset/denominator pair is unconfirmed.
- AerodynamicForceCalc (0x004E8B80): physics globals flt_59E43C, flt_59E440, flt_59E46C, flt_59E99C, flt_5ACEB8 have no usage site grounded in the raw source; sub_5895A2 semantics are unknown (argument is the intermediate force, return discarded); the physical meaning of the quadratic branch is unconfirmed.
- PositionChangeMonitor (0x004E9630): flt_59E9E0 appears in the packet globals but is not referenced by the raw source; the guard reads decompiler condition-code flags v4 (c0) and v5 (c3), whose original flag source is not recoverable; sub_403640 registration semantics and the returned handle meaning are outside this packet.
- RaceStartCountdownStateUpdate (0x004EF930): sound-trigger calls pass the object base this+8 as their argument, but no evidence_ref exists for field:this:0x00000008 in the packet; globals flt_59E440 and flt_59E450 appear in the globals list but are absent from the raw source text.
- ConditionalGate (0x004EFAC0): global dbl_7C7428 is listed as read but does not appear in the raw source; global byte_7C9081 (written on the false branch) has no packet field/global entry; the interpretation of this+0x32BC as a rigid-body constraint pointer and the reset as vehicle state management is DERIVED from existing analysis, not proven by the packet.
