# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Derived architecture proposal for 15 validated functions in scope generic_runtime_objects. All 15 functions carry packet-UNKNOWN owners, so they are grouped into nine GUESS classes by functional cluster: SoundRuntime (0x004C8560 lazy audio resource init, 0x004C8A20 sound-system entry, 0x004C8DE0 sound-effect load/play, 0x004D9030 audio resource release by type), RendererRuntime (0x004C8B70 per-frame render tick, 0x004C97B0 scene-node render update), VehicleGenerationSceneLoader (0x004C6C40 vehgen.scn loader writing team-id scene flags and driver identity on a vehicle-style object at this+0x32C8..0x48A8), NetworkMessageQueue (0x004C7CA0 audio-node message dispatch into a head/tail/cursor/count list at this+0xC..0x18), SpecialEffectsSystem (0x004CF070 special-effects/particle init and 0x004CD980 particle bar renderer), GridSceneInitializer (0x004D0110 grid-girl/sign decoration build), Steward (0x004D4580 race-phase dispatch state machine), TraceLogger (0x004D7960 trace.txt stream init), and HUDTextOverlay (0x004DBAC3 flag indicator composer, 0x004DBC90 six-layer text renderer). Shared evidence: the audio cluster is wired through the dword_8AC4C4 init-status object (vtable slot +96 lazy-create) and the dword_8AC4D0 manager (slots +28/+4), the render cluster reads byte_7CE254/byte_7CF2B4 gates and dword_8AC4C4, and the scene loaders share dword_5EC438/byte_5EA438 path fallbacks plus dbl_7C9360 track-geometry access. The class boundaries are functional-cluster guesses, not packet-proven common ownership; several this fields (this+0x32CC, this+0x4034, this+0x4660) are read/written in raw source but absent from the packet field list and are flagged in unresolved.

## Function roles

- `0x004C6C40` **VehicleGenerationSceneLoader** — Vehicle-generation scene loader: allocates a 128-byte scratch buffer, builds the load path from dword_5EC438 (fallback byte_5EA438), establishes the vehgen.scn file name, writes the TEAMDIR/VEHDIR/NOTSPIN scene flag from the team id at this+0x4894, drives vehicle-graphics scene loading and teardown, resets this+0x48A4/0x48A8 to -1, and (when this+0x32C8 is zero) fills the driver-name buffer, sets driver name/number, copies the nationality path to this+0x4660, and frees the scratch buffer
- `0x004C7CA0` **NetworkMessageQueue** — Network message receive/dispatch: iterates audio network nodes from dword_8AFE88, checks the 4096 flag property, allocates a message vtable entry, dispatches it on the node, and either releases it via an indirect vtable call or enqueues it as a 12-byte node on the list headed at this+0xC (tail this+0x10, cursor this+0x14, count this+0x18); optionally sets a render flag when global dword_8ACFCC is set
- `0x004C8560` **SoundRuntime** — Lazy audio resource init: when the interface pointer global dword_8AC4C4 is set and the cached result dword_8AC4CC is zero, calls the object's vtable method at +96 bytes and memoizes its return in dword_8AC4CC; runs once per process lifetime; invoked by Sound_Enter
- `0x004C8A20` **SoundRuntime** — Sound-system entry: optionally logs the 'entered sound env' message, lazily initializes the sound system (InitWithStatusCheck with sub_4C82F0 fallback) and its context via sub_4C83B0, calls LazyAudioResourceInit, dispatches a guarded global event with the fade-alpha float, lazily checks the renderer audio component, and queries scene-graph node types 0 and 1
- `0x004C8B70` **RendererRuntime** — Per-frame render tick: computes active/render flag pair from scoring state (dword_8AB6E4 and VehicleDataAccessor on dword_8AB6EC); when byte_7CE254, byte_7CF2B4 and the dword_8AC4C4 init object allow, issues a guarded render call with the player vehicle pointer, inverts a view angle, and makes an indirect __thiscall at vtable+28; then iterates the dword_5C329C vehicles calling suspension-force computation on each (dword_7C54F0[i]+20), makes an indirect __thiscall at vtable+8, sets a render-state flag, clears the camera param buffer, displays the text overlay timer, and dispatches either the guarded global or the sound scene path
- `0x004C8DE0` **SoundRuntime** — Sound-effect load/play by index a1 (valid when a1 < 8): lazily creates the dword_8AC4D0 audio manager from the dword_8AC4C4 init-status object via vtable slot +96, composes the sound path from the base directory (dword_5EC3E0, fallback byte_5EA438) and the per-sound name entry off_5D3234[a1], hands it to manager vtable slots +28 and +4, and frees any returned buffer
- `0x004C97B0` **RendererRuntime** — Scene-node render update: enters only when VirtualStateCheckViaIndex returns 0, resets this+0x1C to 0, and when the sub-object at this+0x20 is present and the race-phase global dword_7C56A8 is not 2, zeroes a 12-byte scratch array and dispatches the sub-object's vtable entry at +4 with a transform and the fixed literals (1065353216, 1); always returns 0
- `0x004CD980` **SpecialEffectsSystem** — Telemetry bar-indicator particle renderer: obtains the reference time via Delegation when dword_8AB6E4 == 2 else the session-time global dbl_8AFEA0; iterates the particle array at this+0x68 (count at this+0x64), computes two fade values from each particle's lifetime fields scaled by this+0x40, writes four pixel attributes to the particle texture, and removes out-of-window particles via ArrayElementRemoval
- `0x004CF070` **SpecialEffectsSystem** — Special-effects/particle/track-surface material init: parses the special-effects config (sections trackvars/feedback/loose/reaction) building a name=value list and per-track flags, allocates the 108-byte-element arrays at this+0xC (count this+0x8) and this+0x14 (count this+0x10), builds the cmaps.mas search path, re-parses to instantiate reaction effects per track, dispatches per-type enablement, fills the type-slot pointers at this+0x18..0x28, loads the scene track, runs a spatial grid query to seed dry/wet grip at this+0x30/0x34 (overridable from aidrygrip/aiwetgrip), and allocates the particle-collision array at this+0x4 (count this+0x0); invoked once from Game_Init
- `0x004D0110` **GridSceneInitializer** — Grid/track-side scene initializer: allocates the 132-byte-per-entry decoration array sized from dword_5C329C at this+0x4 (count this+0x0), flags entries from the active vehicle table dword_7C54F0, loads up to three track path config objects, and for each vehicle builds a grid-girl/sign model (random material pick, noise-table placement, ground alignment via bounding-box/spatial-grid query, mesh and texture allocation, final per-entry dispatch)
- `0x004D4580` **Steward** — Main race-system dispatch and race-phase state machine: accumulates 3D distance checks when this+0xA4 is set, drives the audio DSP when this+0xA8 is set, runs the pit timer, and dispatches a session-phase-7 machine (dword_7C56A8 switch over cases 0/1 registration, 2 racing-start, 3/4 shared path, 5-8 looped cases) that sets per-phase flags at this+0xC0/0xC1 and routes on the FLT_MAX sentinel at this+0xD8; delegates scoring via the dword_8AB6E4==2 path
- `0x004D7960` **TraceLogger** — Trace-log init: gates on this+0x0 (level), clamps non-zero levels to 2, writes the trace-level header if a stream exists at this+0x4, else ensures the target directory, builds '%strace.txt' under dword_5EC438 (fallback byte_5EA438), opens it in mode 'w', stores the stream in this+0x4, and resets the level to 0 on open failure; invoked by sub_4D7A00
- `0x004D9030` **SoundRuntime** — Audio resource release by type: a jump-table switch on a1 (1-5) selects handle slots dword_8AD398/8AD39C/8AD3A0/8AD3A4/flt_8AD3A8; a non-null handle is released via ResourceCascadeCleanup and nulled; type 3 additionally destroys dword_8AD3AC through DestructorWithConditionalFreeFlagClear, EmptyStub_7470 and FreeWrapper_7bcf; values outside 1-5 are a no-op
- `0x004DBAC3` **HUDTextOverlay** — HUD flag/status indicator composer: appends one-character indicators '>' (a1 flag), 'A' (VehicleFlagCheck), 'f' (PitStateFlagCheck), '?' (DisqualificationCheck) and 'B' (race-phase dword_7C56A8==8) to a stack buffer, renders it with UITextRenderWithScale at scale 2.0 if any was appended, else returns the DisqualificationCheck result
- `0x004DBC90` **HUDTextOverlay** — Six-layer text overlay renderer: each layer fills a shared 64-byte stack buffer via a distinct string-builder (sub_49C6D0, sub_49BB40, sub_49BBB0, sub_49BCD0, sub_49BD40, sub_49C0B0) and renders it with UITextRenderWithScale at a1-relative positions alternating white/red; returns the final render result; structural twin of DrawDebugTextOverlay

## Proposed classes

### SoundRuntime

Audio subsystem runtime helper: lazily initializes audio resources through the dword_8AC4C4 init-status object's vtable (LazyAudioResourceInit), initializes the sound context and dispatches a guarded global event (Sound_Enter), loads and plays sound effects by index through the dword_8AC4D0 audio manager (SoundEffectLoadPlay), and releases audio resources by type from the dword_8AD398..8AD3AC handle array (AudioResourceReleaseByType). Globals-only: no this-based field evidence exists in the packet.

Methods: `0x004C8560`, `0x004C8A20`, `0x004C8DE0`, `0x004D9030`


### RendererRuntime

Per-frame render system: computes the active/render flag pair from scoring state and drives the guarded render call with the player vehicle pointer (RenderTickUpdate), and updates a scene-node sub-object's render state and dispatches its vtable entry 4 method (RendererSceneNodeUpdate). The scene-node object holds its render state at this+0x1C and a sub-object pointer at this+0x20.

Methods: `0x004C8B70`, `0x004C97B0`

- `this+0x0000001C` `int stateField` (write, GUESS)
- `this+0x00000020` `pointer renderSubObjectPtr` (read, GUESS)
- `*(this+0x20)+0x00000000` `pointer subObjectVTable` (read, GUESS)
- `*(*(this+0x20)+0x0)+0x00000004` `unknown subObjectVtblEntry4` (read, GUESS)

### VehicleGenerationSceneLoader

Loads the vehgen.scn vehicle-generation scene: builds the scene file path, writes the TEAMDIR/VEHDIR/NOTSPIN scene flag from the team id at this+0x4894, drives vehicle-graphics scene loading, and (when this+0x32C8 is zero) sets the driver name and nationality path fields on the vehicle-style object. Resets this+0x48A4/0x48A8 to -1. Offsets in the 0x46xx/0x48xx range suggest the target object is the vehicle race struct, but the packet does not prove it.

Methods: `0x004C6C40`

- `this+0x000032C8` `int slotLiveGuard` (read, GUESS)
- `this+0x00004894` `int teamId` (read, GUESS)
- `this+0x000048A4` `int sceneResetA4` (write, GUESS)
- `this+0x000048A8` `int sceneResetA8` (write, GUESS)
- `this+0x00004677` `byte nationalityPathTerminator` (write, GUESS)

### NetworkMessageQueue

Receives and dispatches messages from audio network nodes into a linked-list queue: iterates nodes from dword_8AFE88, filters on the 4096 flag property, allocates a message vtable entry, dispatches it on the node, and enqueues a 12-byte node on the list headed at this+0xC (tail this+0x10, cursor this+0x14, count this+0x18); rejected or un-queuable entries are released via an indirect vtable call.

Methods: `0x004C7CA0`

- `this+0x0000000C` `pointer listHead` (read_write, GUESS)
- `this+0x00000010` `pointer listTail` (read_write, GUESS)
- `this+0x00000014` `pointer listCursor` (read_write, GUESS)
- `this+0x00000018` `int itemCount` (write, GUESS)

### SpecialEffectsSystem

Special-effects, particle and track-surface material subsystem: parses the special-effects config into track-feedback and material-reaction arrays (counts at this+0x8/0x10, arrays at this+0xC/0x14), fills per-type slots at this+0x18..0x28, seeds dry/wet grip at this+0x30/0x34, allocates the particle-collision array (count this+0x0, array this+0x4), and renders telemetry bar indicators from the particle array at this+0x68 (count this+0x64). The 0x004CD980 particle renderer is grouped here on particle-domain affinity; common ownership with 0x004CF070 is not packet-proven.

Methods: `0x004CF070`, `0x004CD980`

- `this+0x00000000` `int collisionNodeCount` (write, GUESS)
- `this+0x00000004` `pointer collisionNodeArray` (write, GUESS)
- `this+0x00000008` `int feedbackEffectCount` (read_write, GUESS)
- `this+0x0000000C` `pointer trackFeedbackArray` (write, GUESS)
- `this+0x00000010` `int reactionEffectCount` (read_write, GUESS)
- `this+0x00000014` `pointer materialReactionArray` (write, GUESS)
- `*(this+0x14)+0x00000004` `int reactionElementType` (read, GUESS)
- `this+0x00000018` `pointer typeSlotType4` (write, GUESS)
- `this+0x0000001C` `pointer typeSlotType3` (write, GUESS)
- `this+0x00000020` `pointer typeSlotType1` (write, GUESS)
- `this+0x00000024` `pointer typeSlotType12` (write, GUESS)
- `this+0x00000028` `pointer typeSlotType13` (write, GUESS)
- `this+0x0000002C` `pointer collisionNodePtr` (write, GUESS)
- `this+0x00000030` `float dryGripFloat` (read_write, GUESS)
- `this+0x00000034` `float wetGripFloat` (read_write, GUESS)
- `this+0x00000040` `float particleFadeScale` (read, GUESS)
- `this+0x00000064` `int particleCount` (read, GUESS)
- `this+0x00000068` `pointer particleArrayPtr` (read, GUESS)

### GridSceneInitializer

Builds the grid-side decoration scene: allocates the per-vehicle 132-byte decoration array (count at this+0x0, array at this+0x4) sized from dword_5C329C, loads up to three track path config objects, and constructs grid-girl/sign models per active vehicle with random material/placement and ground alignment.

Methods: `0x004D0110`

- `this+0x00000000` `int vehicleCount` (read_write, GUESS)
- `this+0x00000004` `pointer decorationArray` (write, GUESS)

### Steward

Main race-system dispatcher: accumulates 3D distance checks, drives the audio DSP, runs the pit timer, and runs the session-phase-7 race-phase state machine dispatching on dword_7C56A8, setting per-phase flags at this+0xC0/0xC1 and routing on the FLT_MAX sentinel at this+0xD8. Name comes from the ABI lead only; packet owner is UNKNOWN.

Methods: `0x004D4580`

- `this+0x00000098` `float racingStartThreshold` (read, GUESS)
- `this+0x000000A4` `pointer distanceCheckSourcePtr` (read, GUESS)
- `this+0x000000A8` `pointer audioContextPtr` (read, GUESS)
- `this+0x000000B0` `float phaseTimeLow` (read, GUESS)
- `this+0x000000B4` `float phaseTimeHigh` (read, GUESS)
- `this+0x000000C0` `byte phaseControlFlag` (write, GUESS)
- `this+0x000000C1` `byte sessionPhaseFlag` (write, GUESS)
- `this+0x000000D8` `float progressBarSentinel` (read, GUESS)

### TraceLogger

Trace logging initializer: gates on the trace level at this+0x0, clamps it to 2, opens '%strace.txt' under the game directory, stores the stream at this+0x4, and writes the trace-level header; on open failure the level is reset to 0.

Methods: `0x004D7960`

- `this+0x00000000` `int traceLevel` (read_write, GUESS)
- `this+0x00000004` `pointer traceStreamPtr` (read_write, GUESS)

### HUDTextOverlay

HUD text overlay renderers: composes one-character status indicators ('>', 'A', 'f', '?', 'B') and renders them with UITextRenderWithScale (HUDFlagRendererSecondary), and renders a six-layer text block where each layer is built by a distinct string-builder sub-function (MultiLayerTextStringRenderer). Globals-only and locals-only: no this-based field evidence exists in the packet.

Methods: `0x004DBAC3`, `0x004DBC90`


## Compatibility contracts

- **AudioInitStatusVtable** — The dword_8AC4C4 init-status object must expose a callable entry at vtable offset +96 (bytes 0x60): LazyAudioResourceInit calls it once and memoizes the result in dword_8AC4CC, and SoundEffectLoadPlay uses the same slot to create the dword_8AC4D0 audio manager, retrying until it exists.
- **SoundManagerVtable** — The dword_8AC4D0 audio manager exposes load/play entry points at vtable offsets +28 and +4: the sound path is composed as '%s%s' from the base directory and the per-sound name entry off_5D3234[a1], then handed to slot +28 (with parameter a2) and slot +4; any returned buffer is freed via FreeWrapper_7bcf.
- **AudioResourceHandleSlots** — AudioResourceReleaseByType selects one of five contiguous handle slots (dword_8AD398, dword_8AD39C, dword_8AD3A0, dword_8AD3A4, flt_8AD3A8) by index 1-5, releases it via ResourceCascadeCleanup and nulls it; type 3 additionally destroys dword_8AD3AC via DestructorWithConditionalFreeFlagClear + EmptyStub_7470 + FreeWrapper_7bcf and nulls it. Values outside 1-5 are a no-op.
- **NetworkMessageQueueLayout** — The message queue list lives at this+0xC (head), this+0x10 (tail), this+0x14 (cursor) and this+0x18 (count); entries are 12-byte nodes ([0]=message vtable entry, [4]=next, byte [8]=1) enqueued from audio network nodes filtered on flag bit 4096, and rejected entries are released via an indirect vtable call.
- **SpecialEffectsConfigFormat** — The special-effects config file is tokenized by the section keywords trackvars / feedback / loose / reaction: trackvars parses name=value float pairs into a linked list, feedback and loose sections evaluate include/exclude track filters and count aReaction occurrences, and a second pass instantiates per-track reaction effects (108-byte elements at this+0x14, count this+0x10). The dry/wet grip floats at this+0x30/0x34 are overridable from the config tokens aidrygrip/aiwetgrip.
- **TrackSurfaceGripQuery** — After loading the scene/track via SceneTrackFileLoader(dbl_7C9360, 2), a SpatialGridQuery on dbl_7C9360 locates the collision-geometry node under the camera point; the node's fields at +8 and +12 seed the dry/wet grip floats at this+0x30/0x34.
- **RacePhaseGlobalContract** — The race-phase dispatcher relies on the globals dword_7C56A0 (bit 0 multiplayer gate), dword_7C56A4 (phase counter >= 0, cited in raw source only), dword_7C56A8 (phase selector, values 0-8 with case 2 gating scene-node render updates at dword_7C56A8 != 2) and dword_7C56AC (global enable: when set, pit timer and phase machine are skipped). The FLT_MAX sentinel 0x7F7FFFFF at this+0xD8 routes the case-4 progress-bar path.
- **TraceLogPathFormat** — Trace logging writes the header via StringFormatWithNestedIO(this+0x4, aTraceLevelD) to a stream opened in mode 'w' at the path '%strace.txt' formatted from dword_5EC438 (or byte_5EA438 fallback), after CreateDirectoryAWrapper ensures the directory exists.
- **HUDStatusIndicatorCharacters** — The HUD flag composer appends one-character status indicators '>' (0x3E, caller flag), 'A' (0x41, VehicleFlagCheck), 'f' (0x66, PitStateFlagCheck), '?' (0x3F, DisqualificationCheck) and 'B' (0x42, race phase dword_7C56A8==8), null-terminates and renders with UITextRenderWithScale at scale 2.0; a replacement must reproduce these indicator codes for identical HUD output.

## Unresolved

- All 15 functions carry packet-UNKNOWN owners; the nine GUESS class boundaries (SoundRuntime, RendererRuntime, VehicleGenerationSceneLoader, NetworkMessageQueue, SpecialEffectsSystem, GridSceneInitializer, Steward, TraceLogger, HUDTextOverlay) are functional-cluster groupings, not packet-proven common ownership. In particular, SpecialEffectsSystem merges 0x004CF070 (this+0x0..0x34) with 0x004CD980 (this+0x40/0x64/0x68) on particle-domain affinity only; the packet does not prove they share an object.
- VehgenScnFileLoader fields this+0x32CC, this+0x4034 and this+0x4660 are read/written in the raw source but have no packet field entries; this+0x4660 (nationality data path) and its null terminator this+0x4677 sit inside a 23-char copy, and the this+0x32CC scene-path field is passed to sub_4A4900.
- The TEAMDIR/VEHDIR/NOTSPIN scene flag writer (SceneFileTEAMDIRVEHDIRNOTSPINWriter, 0x004DDF90) and the team id at this+0x4894 semantics are derived from surrounding context only; the exact flag encoding is not evidenced.
- The two indirect __thiscall dispatches on the dword_8AC4C4 object in RenderTickUpdate (vtable slots +28 and +8) have no named targets in the packet.
- The purpose of the vtable method at +96 on the dword_8AC4C4 object (used by LazyAudioResourceInit and SoundEffectLoadPlay) and the meaning of its integer return value are undocumented.
- NetworkMessageReceiveAndDispatch: exact semantics of VTableDispatchWithNegation return (rejected vs consumed) and of the indirect vtable call (**v3)(v3, 1) (likely an object release/decrement) are unproven; the relationship between the dword_8AFE88 handle and the indices passed to LinkedListNodeFinder is unverified.
- RendererSceneNodeUpdate: meaning of race-phase value 2 for dword_7C56A8 and the object type behind the sub-object vtable at this+0x20 are unknown; the fixed literals 1065353216 and 1 passed to the vtable method are not asserted.
- TelemetryBarIndicatorRenderer: the per-particle fields (p[2], p[3], p[24], p[25]) have no packet field evidence; the pixel-attribute semantics of the four PixelAttributeWriteToTexture writes are inferred from the call name.
- SpecialFX_Init: the exact semantics of sub_4CEEF0, sub_4CA280, sub_4CAED0, sub_4CEF30, sub_5651B0/565520/566810 and the sub_4CB120 per-group enable are inferred from call-site context; numeric constants 396/2908/2928/61 and the 108/60 element strides come from the raw source only.
- SpecialFX_Init type-to-slot mapping (type 12->this+0x24, 13->this+0x28, 1->this+0x20, 3->this+0x1C, 4->this+0x18) is DERIVED from switch-case assignments; the float literals at this+0x30/0x34 after the grid query are not individually evidenced.
- GridStartingSceneInitialization: the 132-byte decoration entry layout is implied by relative offsets only; entry+104/+116/+120/+124/+128 fields are semantic guesses from usage context; the purpose of the entry flag word (entry+4) is not evidenced.
- StewardUpdateMainDispatch: the phase machine also invokes PackedFlagRead, CollisionProxyUnregister, ShortComputation_bde0, ProgressBarDataStore, ModeValidationCheck, TickUpdateDispatch, SessionStateCheckWrapper, SessionStateCheck, GlobalFlagSetter, ProgressBarEventEncode, sub_4D1D80 and sub_4D2170, none of which carry packet evidence refs; many phase-machine globals read by the raw source are not in the packet globals list.
- TraceLogInit: the stream stored at this+0x4 is shown only as an integer result of sub_587DB0; whether it is a FILE*, a handle, or an object pointer is unverified; the inner clamp against 2 is reconstructed from raw source text.
- AudioResourceReleaseByType: dword_8AFE64 is listed as a read global but never appears in the raw source (likely consumed inside ResourceCascadeCleanup / destructor path); the concrete resource types behind slots 1-5 and the type-3 extra struct are not established.
- HUDTextOverlay: the seven sub_49XXXX callees build strings into the shared buffer; their text content and purpose are not exposed by these functions.
- Globals flagged by packet facts but absent from raw source bodies: 0x0059E43C, 0x0059E440, 0x0059E660, 0x0059E7E8, 0x0059E7F8, 0x0059E84C, 0x0059F124, 0x005ACEC4, 0x005ACEDC, 0x005ACEE0, 0x005ACF48, 0x005ACF4C, 0x007CE234, 0x008AC368, 0x008ACEE0, 0x008AFE64; their exact use sites could not be tied to single source operations and they are treated as read references.
