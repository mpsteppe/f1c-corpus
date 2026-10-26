# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Architecture proposal for a cluster of runtime object handlers. Weather/environment state is split between a parameter block (0x004FCAA0, built at Game_Init, writes color/blend/range constants) and a race-state block (0x004FCC30, rebuilt at Game_Restart with teardown-first semantics, allocates a 4-float parameter array, processes an audio ring buffer and seeds per-race words). Cloud/skybox rendering is owned by a CloudSkyboxState object (0x004FBA10, resolves scene nodes, allocates cloud/rain handle arrays, computes opacities/speeds and a bounding box) plus a CloudSceneObjectRegistry (0x004FC550 loads the logomap.mas resource and registers wcclouds/wccloudr texture variants; 0x004FC2F0 randomly selects 31-byte cloud object templates into this+80/this+132). The video-manager pair (0x004FAC00/0x004FAD00) performs post/exit teardown and active-scene directory registration. CameraViewportRenderer (0x004FBD70) re-centers viewports, scales pit-crew animation offsets, and packs per-element alpha from a gradient. HudScoringElement (0x004FCEE0) encodes progress events into a 432-byte ring buffer and blends alpha/color. AudioADSREnvelope (0x004FDEB0) advances a keyframe-node envelope; SessionWeatherData (0x004FE350) builds a time-keyed weather snapshot linked list; WeatherAudioChannelLoader (0x004FE7C0) loads/stops the weather audio channel and drives 0x004FE350. Ownership of most objects is UNKNOWN in the packet; classes here are DERIVED groupings from call relationships and shared this-slots.

## Function roles

- `0x004FAC00` **VideoManager** — VidMan post-processing entry: optional entry log, frame-rate counter reset, mutex/semaphore handle release and clear, SingleGlobalSetter(0), then active-scene path extraction (scene table base dword_8AC490 indexed by dword_8AC48C at stride 396, path string at +4) and directory registration via StringMatchWithFlagSet.
- `0x004FAD00` **VideoManager** — VidMan exit handler: optional exit log, collision system shutdown, race-time-delta handle dispatch, two unnamed cleanup subroutines (sub_4A1830 before and after sub_4A14E0), and TestAndFreeWrapper free of dword_8AFE64 with clear to 0.
- `0x004FB910` **SessionWeatherSchedule** — Session duration computation: jump-table dispatch (jpt_4FB921) maps the session index to a (days, hours) pair, a Monaco track-path match (against aMonaco via sub_566810) on session types 1/2 decrements the day count, and the result is days*86400 + hours*3600 seconds.
- `0x004FBA10` **CloudSkyboxState** — CloudSkyboxState initializer: resolves the SkyboxI scene node and three cloud-layer nodes (Clouds/Cloudsny/Cloudrny), scans the audio network for snowy/rainy node handles, allocates the cloud and rain handle arrays, computes layer opacity (sub_548890) and noise-driven animation speeds scaled by flt_7CF914, and computes the skybox bounding box.
- `0x004FBD70` **CameraViewportRenderer** — Camera viewport render setup: session-type change detection and handler sub_4FC550, per-frame global refresh plus three camera field pulls, primary and sub-viewport re-centering, fade-state change tracking, pit-crew animation offset scaling by dbl_8AFE98, and per-element alpha packing from the gradient range with OffsetDispatch flush.
- `0x004FC2F0` **CloudSceneObjectRegistry** — Random cloud scene object selection: iterates a2's object list (256-byte stride), partitions candidates by 6-character name match against aClouds/aCloudr, randomly selects one from each non-empty group via the LCG, and copies 31 bytes (from +20 of the pick) into this+80 and this+132, clearing the 0x6F/0xA3 flag bytes after each copy.
- `0x004FC550` **CloudSceneObjectRegistry** — Logo-map resource load plus cloud texture setup: builds the season/track/common/logomap.mas path (season dword_5EC3D8, track dword_5EC420, fallback byte_5EA438), loads it via sub_53CBC0, optionally randomizes cloud scene objects through 0x004FC2F0, registers wcclouds/wccloudr texture variants at this+80/this+132 via sub_4FC400, removes the resource from the physics linked list, and frees the path buffer.
- `0x004FCAA0` **WeatherParameterState** — Weather parameter block initializer: optional weather.txt generation (guarded on dword_7CF080), sentinel resets, packed-short color scaling (/255), weather timing factor from field +224, blend/half factors, range/default constants, and cloud/skybox setup delegation to sub_4FBA10 on the block at this+264.
- `0x004FCC30` **WeatherRaceState** — Weather race-state re-initializer on game restart: tears down prior list state, early-outs when the display-mode guard is unset or dword_8AB6E4 is 2, selects a weather parameter mode (season entry, weather.txt parse, or built-in switch on dword_7CF080), allocates the 4-float parameter array, processes the audio ring buffer, initializes per-race flags/words, seeds this+0x104 from the rotation table, and conditionally resets the name at this+0x1C4 and calls sub_4FC550.
- `0x004FCEE0` **HudScoringElement** — Per-frame HUD scoring/progress-bar update: decrements the countdown timer, encodes expired scoring events into the 432-byte ring buffer at dword_8AAE64, advances a linked event list, interpolates display alpha toward its target, applies time-of-day dimming and the nightlight toggle, computes an interpolated RGB color ramp, updates audio pan / bounded float setter / UI position, and swaps idle/active state ids (6<->7, 21<->22) in the global element array.
- `0x004FDEB0` **AudioADSREnvelope** — Audio ADSR envelope advance: walks the keyframe-node chain from this+0x38, interpolates the two node parameters (table base this+0x44) for the phase input, applies per-sample decay with floor clamp to the two internal envelope states, calls RangeInterpolationTable, and writes a sample-rate-smoothed output at this+0x34.
- `0x004FE350` **SessionWeatherData** — Per-session weather data initializer: resolves session-name candidates via SessionTypeNameLookup on dword_7C56A4, finds the best data entry by minutes/tick count, reads conditions / on-path and off-path wetness / ambient and track temperature entries, clamps off-path wetness to at least on-path, and builds a time-keyed linked list of weather snapshots (timestamp, ambient temp, wetness multiplier) from the minute entries. Returns -1 when no entry matches, 0 on success.
- `0x004FE7C0` **WeatherAudioChannelLoader** — Weather audio load and channel stop: zero-initializes a 56-byte local struct, decodes the audio file for resource id a2, stops the weather audio channel referenced by aWeather_1, processes the stopped channel handle through sub_4FE350 into the caller's buffer, frees the local linked-list buffer on every path, and returns the sub_4FE350 result (or -1 when the channel stop returned NULL).

## Proposed classes

### VideoManager

Video-manager lifecycle teardown and scene-path registration: post-processing entry (0x004FAC00) resets frame-rate state, releases the global mutex/semaphore handle, clears a global flag, and registers the active scene directory path; exit handler (0x004FAD00) shuts down the collision system, dispatches and frees the race-time-delta global.

Methods: `0x004FAC00`, `0x004FAD00`


### CloudSkyboxState

Cloud/skybox rendering state: resolves the skybox and three cloud-layer scene nodes, builds cloud and rain node-handle arrays from the audio network, holds per-layer opacity and animation speeds, and keeps the skybox bounding box.

Methods: `0x004FBA10`

- `this+0x00000000` `ptr skyboxNodeHandle` (read_write, DERIVED)
- `this+0x00000010` `ptr normalCloudLayerHandle` (write, GUESS)
- `this+0x00000020` `ptr snowyCloudLayerHandle` (read_write, DERIVED)
- `this+0x00000030` `ptr rainyCloudLayerHandle` (read_write, DERIVED)
- `this+0x00000040` `float cloudLayerArraySentinel` (write, DERIVED)
- `this+0x00000048` `int32 cloudNodeCount` (read_write, DERIVED)
- `this+0x0000004C` `ptr cloudHandleArray` (write, DERIVED)
- `this+0x00000070` `float cloudLayerOpacity` (read_write, DERIVED)
- `this+0x00000074` `float cloudSpeedA` (write, DERIVED)
- `this+0x00000078` `float cloudSpeedB` (write, DERIVED)
- `this+0x0000007C` `int32 rainNodeCount` (read_write, DERIVED)
- `this+0x00000080` `ptr rainHandleArray` (write, DERIVED)
- `this+0x000000A4` `float rainLayerOpacity` (read_write, DERIVED)
- `this+0x000000A8` `float rainSpeedA` (write, DERIVED)
- `this+0x000000AC` `float rainSpeedB` (write, DERIVED)
- `this+0x000000B0` `float boundingBoxMin` (read_write, DERIVED)
- `this+0x000000B4` `float boundingBoxMax` (read_write, DERIVED)
- `this+0x000000B8` `float boundingBoxSentinel` (write, DERIVED)

### CameraViewportRenderer

Camera viewport render configuration: detects session-type changes, re-centers the primary and three sub-viewports, tracks fade-state changes, scales pit-crew animation offsets, and packs per-element alpha into the render-state list from a gradient range.

Methods: `0x004FBD70`

- `this+0x00000000` `int32 primaryViewportActive` (read, DERIVED)
- `this+0x00000004` `float primaryPositionX` (read_write, DERIVED)
- `this+0x00000008` `float primaryPositionY` (read_write, DERIVED)
- `this+0x0000000C` `float primaryPositionZ` (read_write, DERIVED)
- `this+0x00000018` `float subViewportOffset` (read_write, DERIVED)
- `this+0x0000001C` `float subViewportNeighbor` (read_write, DERIVED)
- `this+0x00000044` `int32 cachedSessionId` (read_write, DERIVED)
- `this+0x00000048` `int32 primaryViewportCount` (read, DERIVED)
- `this+0x00000070` `ptr pitCrewAnimationHandlePrimary` (read, DERIVED)
- `this+0x00000074` `float pitCrewOffsetXPrimary` (read, DERIVED)
- `this+0x00000078` `float pitCrewOffsetZPrimary` (read, DERIVED)
- `this+0x0000007C` `int32 secondaryViewportCount` (read, DERIVED)
- `this+0x000000A4` `ptr pitCrewAnimationHandleSecondary` (read, DERIVED)
- `this+0x000000A8` `float pitCrewOffsetXSecondary` (read, DERIVED)
- `this+0x000000AC` `float pitCrewOffsetZSecondary` (read, DERIVED)
- `this+0x000000B0` `float gradientUpperBound` (read, DERIVED)
- `this+0x000000B4` `float gradientLowerBound` (read, DERIVED)
- `this+0x000000B8` `float cachedFadeValue` (read_write, DERIVED)

### CloudSceneObjectRegistry

Cloud texture/object registry: loads the common logo-map resource and registers the wcclouds/wccloudr cloud texture variants at this+80/this+132 (0x004FC550), and randomly selects 31-byte cloud object templates into the same slots from the scene object list (0x004FC2F0). Common ownership of the this object between the two methods is evidenced by 0x004FC550 calling 0x004FC2F0 with its own this.

Methods: `0x004FC2F0`, `0x004FC550`

- `this+0x0000006F` `byte firstCloudSelectionFlag` (write, DERIVED)
- `this+0x00000080` `byte[31] firstCloudTextureVariant` (write, DERIVED)
- `this+0x000000A3` `byte secondCloudSelectionFlag` (write, DERIVED)

### WeatherParameterState

Weather parameter block: holds the color scaling, blend/half factors, range and default constants, and the weather timing factor used by the environment; initialized at Game_Init and embeds a cloud/skybox block at this+264.

Methods: `0x004FCAA0`

- `this+0x0000000C` `float timeOfDayStart` (write, DERIVED)
- `this+0x00000010` `int32 dayOfYearSentinel` (write, DERIVED)
- `this+0x00000018` `float invalidFloatSentinel` (write, DERIVED)
- `this+0x000000A4` `float secondInvalidSentinel` (write, DERIVED)
- `this+0x000000B4` `float skyColorRed` (write, DERIVED)
- `this+0x000000B8` `float skyColorGreen` (write, DERIVED)
- `this+0x000000BC` `float skyColorBlue` (write, DERIVED)
- `this+0x000000C0` `float blendFactorRed` (write, DERIVED)
- `this+0x000000C4` `float blendFactorGreen` (write, DERIVED)
- `this+0x000000C8` `float blendFactorBlue` (write, DERIVED)
- `this+0x000000CC` `float halfFactorRed` (write, DERIVED)
- `this+0x000000D0` `float halfFactorGreen` (write, DERIVED)
- `this+0x000000D4` `float halfFactorBlue` (write, DERIVED)
- `this+0x000000E0` `float weatherTimingInput` (read, DERIVED)
- `this+0x000000E4` `float rangeDefaultA` (write, DERIVED)
- `this+0x000000E8` `float rangeDefaultB` (write, DERIVED)
- `this+0x000000EC` `float weatherTimingFactor` (write, DERIVED)
- `this+0x000000F0` `float rangeLimitLower` (write, DERIVED)
- `this+0x000000F4` `float rangeLimitUpper` (write, DERIVED)
- `this+0x000000F8` `float rangeStep` (write, DERIVED)
- `this+0x000001C4` `byte initStatusByte` (write, DERIVED)

### WeatherRaceState

Per-race weather state: holds the initial weather float, the 4-float parameter array pointer, wetness/temperature slots, per-race flags/words, an audio ring-buffer region, the rotation-table seed at +0x104, and the weather name at +0x1C4; rebuilt with teardown-first semantics at game restart.

Methods: `0x004FCC30`

- `this+0x00000000` `float initialWeatherFloat` (write, DERIVED)
- `this+0x00000004` `int32 resetDword` (write, DERIVED)
- `this+0x00000008` `float audioBackupFloat` (write, DERIVED)
- `this+0x00000014` `int32 weatherEnabledFlag` (write, DERIVED)
- `this+0x0000001C` `int32 stateFlagDword` (write, DERIVED)
- `this+0x00000020` `byte[24] audioRingBufferRegion` (read_write, DERIVED)
- `this+0x00000024` `float conditionsFloat` (write, DERIVED)
- `this+0x00000028` `float trackWetnessA` (write, DERIVED)
- `this+0x0000002C` `float trackWetnessB` (read_write, DERIVED)
- `this+0x00000030` `float parameterArrayValueA` (write, DERIVED)
- `this+0x00000034` `float parameterArrayValueB` (write, DERIVED)
- `this+0x00000038` `ptr parameterArrayPtrBackup` (write, DERIVED)
- `this+0x0000003C` `ptr parameterArrayPtr` (write, DERIVED)
- `this+0x00000040` `byte initCompleteFlag` (write, DERIVED)
- `this+0x00000044` `int32 eventMaskDword` (write, DERIVED)
- `this+0x00000048` `word wordBlock0` (write, DERIVED)
- `this+0x0000004A` `word wordBlock1` (write, DERIVED)
- `this+0x0000004C` `word wordBlock2` (write, DERIVED)
- `this+0x0000004E` `word wordBlock3` (write, DERIVED)
- `this+0x00000050` `word wordBlock4` (write, DERIVED)
- `this+0x00000052` `word wordBlock5` (write, DERIVED)
- `this+0x00000104` `float rotationScaledValue` (write, DERIVED)
- `this+0x000001C4` `char[11] weatherName` (read_write, DERIVED)
- `this+0x000001CF` `byte weatherNameTerminator` (write, DERIVED)

### HudScoringElement

Per-frame HUD scoring/progress-bar element: countdown, event ring-buffer encoding, alpha smoothing, time-of-day dimming, nightlight toggle, color-ramp interpolation, and audio/position/UI output, plus idle/active state-id swapping in the global element array.

Methods: `0x004FCEE0`

- `this+0x00000000` `float valueSource` (read, DERIVED)
- `this+0x00000004` `float countdownTimer` (read_write, DERIVED)
- `this+0x00000008` `float smoothedAlpha` (read_write, DERIVED)
- `this+0x0000000C` `float displayedAlpha` (read_write, DERIVED)
- `this+0x00000010` `int32 nightlightFlag` (read_write, DERIVED)
- `this+0x00000014` `int32 activeFlag` (write, DERIVED)
- `this+0x00000018` `float smoothedPositionState` (read, DERIVED)
- `this+0x0000001C` `float oneShotBlendFactor` (read_write, DERIVED)
- `this+0x00000020` `float targetAlpha` (read, DERIVED)
- `this+0x00000024` `float scoreBlendWeight` (read, DERIVED)
- `this+0x00000028` `float scoreLower` (read, DERIVED)
- `this+0x0000002C` `float scoreUpper` (read_write, DERIVED)
- `this+0x00000040` `byte oneShotByte` (read_write, DERIVED)
- `this+0x00000044` `float cachedEmitValue` (read_write, DERIVED)
- `this+0x00000048` `float cachedColorRed` (read_write, DERIVED)
- `this+0x0000004C` `float cachedColorGreen` (read_write, DERIVED)
- `this+0x00000050` `float cachedColorBlue` (read_write, DERIVED)
- `this+0x0000005C` `ptr eventListHead` (read_write, DERIVED)
- `*(this+0x5C)+0x00000000` `float headEventTimestamp` (read, GUESS)
- `*(this+0x5C)+0x00000004` `ptr headEventNext` (read, GUESS)
- `*(*(this+0x5C)+0x0)+0x00000000` `float eventNodeTimestamp` (read, GUESS)
- `*(*(this+0x5C)+0x0)+0x00000004` `int32 eventNodeSelector` (read, GUESS)
- `*(*(this+0x5C)+0x0)+0x00000008` `float eventNodeValue` (read, GUESS)
- `this+0x000000A4` `float smoothedPositionOutput` (read_write, DERIVED)
- `this+0x000000A8` `float colorRampSwitch` (read, DERIVED)
- `this+0x000000AC` `float lowGradientScale` (read, DERIVED)
- `this+0x000000B0` `float highGradientScale` (read, DERIVED)
- `this+0x000000B4` `float lowColorRed` (read, DERIVED)
- `this+0x000000B8` `float lowColorGreen` (read, DERIVED)
- `this+0x000000BC` `float lowColorBlue` (read, DERIVED)
- `this+0x000000C0` `float baseColorRed` (read, DERIVED)
- `this+0x000000C4` `float baseColorGreen` (read, DERIVED)
- `this+0x000000C8` `float baseColorBlue` (read, DERIVED)
- `this+0x000000CC` `float highColorRed` (read, DERIVED)
- `this+0x000000D0` `float highColorGreen` (read, DERIVED)
- `this+0x000000D4` `float highColorBlue` (read, DERIVED)
- `this+0x000000D8` `float midLowColorRed` (read, DERIVED)
- `this+0x000000DC` `float midLowColorGreen` (read, DERIVED)
- `this+0x000000E0` `float midLowColorBlue` (read, DERIVED)
- `this+0x000000E4` `float midColorRed` (read, DERIVED)
- `this+0x000000E8` `float midColorGreen` (read, DERIVED)
- `this+0x000000EC` `float midColorBlue` (read, DERIVED)
- `this+0x000000F0` `float topColorRed` (read, DERIVED)
- `this+0x000000F4` `float topColorGreen` (read, DERIVED)
- `this+0x000000F8` `float topColorBlue` (read, DERIVED)
- `this+0x000000FC` `float dimFactorLow` (read, DERIVED)
- `this+0x00000100` `float dimFactorHigh` (read, DERIVED)

### AudioADSREnvelope

Audio ADSR envelope: walks a keyframe-node chain, interpolates node parameters, applies per-sample decay with a floor clamp, and produces a sample-rate-smoothed output value.

Methods: `0x004FDEB0`

- `this+0x00000024` `float floorValue` (read, DERIVED)
- `this+0x00000028` `float envelopeStateA` (read_write, DERIVED)
- `this+0x0000002C` `float envelopeStateB` (read_write, DERIVED)
- `this+0x00000030` `float parameterSlot` (write, DERIVED)
- `this+0x00000034` `float outputValue` (read_write, DERIVED)
- `this+0x00000038` `ptr currentNodePtr` (read_write, DERIVED)
- `this+0x0000003C` `float currentNodeThreshold` (read, DERIVED)
- `this+0x00000040` `float nextNodeThreshold` (read, DERIVED)
- `this+0x00000044` `ptr keyframeTableBase` (read, DERIVED)
- `*(this+0x44)+0x00000000` `float keyframeThreshold` (read, GUESS)
- `*(this+0x44)+0x00000004` `float keyframeParameterA` (read, GUESS)
- `*(this+0x44)+0x00000008` `float keyframeParameterB` (read, GUESS)

### SessionWeatherData

Per-session weather data: holds on-path/off-path wetness, ambient and track temperature, and a time-keyed linked list of weather snapshots (head at this+0x38, first node at this+0x3C); built from session data-entry lists at race start.

Methods: `0x004FE350`

- `this+0x00000020` `float wetnessSlotA` (read_write, DERIVED)
- `this+0x00000024` `float wetnessSlotB` (read_write, DERIVED)
- `this+0x00000028` `float onPathWetness` (read_write, DERIVED)
- `this+0x0000002C` `float offPathWetness` (read_write, DERIVED)
- `this+0x00000030` `float ambientTemperature` (read_write, DERIVED)
- `this+0x00000034` `float trackTemperature` (read_write, DERIVED)
- `this+0x00000038` `ptr snapshotHeadPtr` (read_write, DERIVED)
- `this+0x0000003C` `ptr snapshotFirstPtr` (write, DERIVED)
- `*(this+0x38)+0x00000004` `float headNodeAmbient` (read, GUESS)
- `*(this+0x38)+0x00000008` `float headNodeWetness` (read, GUESS)
- `*(this+0x38)+0x0000000C` `ptr headNodeNext` (read, GUESS)
- `*(this+0x3C)+0x00000004` `float firstNodeAmbient` (read, GUESS)
- `*(this+0x3C)+0x00000008` `float firstNodeWetness` (read, GUESS)
- `*(*(this+0x38)+0xC)+0x00000000` `float snapshotNodeTime` (read, GUESS)
- `*(*(this+0x38)+0xC)+0x00000004` `float snapshotNodeAmbient` (read, GUESS)
- `*(*(this+0x38)+0xC)+0x00000008` `float snapshotNodeWetness` (read, GUESS)

### SessionWeatherSchedule

Session-to-duration mapping helper: converts a session index and the current track path into a session length in seconds (days and hours). No object state; grouped as a helper of the weather/environment subsystem.

Methods: `0x004FB910`


### WeatherAudioChannelLoader

Weather audio channel loader: decodes the weather audio resource, stops the weather channel, and feeds the stopped channel data through the session-weather initializer. No object state in the packet.

Methods: `0x004FE7C0`


## Compatibility contracts

- **WeatherRestartReinitialization** — Weather race-state re-initialization must fully tear down prior list state (DualLinkedListDestruction at entry) before rebuilding: allocate a 4-float parameter array [0, 1101004800, modeValue, 0], restore this+0x20 from its saved copy, and seed per-race words (0, -1, -1, 0, 0x7FFF, 0x8000) at +0x48..+0x52.
- **VidManExitTeardown** — VidMan exit must shut down the collision system (CollisionSystemShutdownCleanup), dispatch the race-time-delta handle (GlobalDispatch), run sub_4A1830 before and after sub_4A14E0, and free dword_8AFE64 via TestAndFreeWrapper when non-null, clearing the global to 0.
- **SceneDirectoryRegistration** — VidMan post-processing must resolve the active scene struct (base dword_8AC490 indexed by dword_8AC48C at stride 396), copy its path string from scene+4, trim trailing backslash segments (value 92), and register the resulting directory via StringMatchWithFlagSet; the null-scene path must return 0.
- **CloudLayerArrayOwnership** — CloudSkyboxState allocates the cloud and rain handle arrays via nhMalloc with sizes 4*count and keeps count/pointer pairs in sync (+0x48 count with +0x4C pointer, +0x7C count with +0x80 pointer); a replacement must preserve the pairs for later free/iteration.
- **WeatherSnapshotChainLayout** — SessionWeatherData builds a time-keyed linked list of 16-byte weather snapshot nodes (time, ambient temperature, wetness multiplier, next link); the head/cursor lives at this+0x38 with the first node at this+0x3C, and traversal follows the next link at node+0xC. Consumers of the chain must observe this layout.

## Unresolved

- The two functions named with a VidMan prefix (0x004FAC00, 0x004FAD00) are grouped as VideoManager on naming only; their this-object identity and any shared state are not proven by the packet.
- Grouping 0x004FC2F0 and 0x004FC550 as one CloudSceneObjectRegistry object rests on 0x004FC550 calling 0x004FC2F0 with its own this (caller:0x004FC550); both write the this+80/this+132 texture slots and clear the 0x6F/0xA3 flags.
- 0x004FCAA0 (WeatherParameterState) and 0x004FCC30 (WeatherRaceState) both act on 'weather' objects but are kept as separate classes; both reach object state near offset 0x108 (sub_4FBA10 on this+264 in 0x004FCAA0, sub_4FC550 on this+264 in 0x004FCC30), so the two object types may overlap at runtime.
- The float-constant clusters 0x0059E43C..0x0059FEC8 and 0x005ACCB0..0x005AD318 are packet-flagged as read xrefs of many functions but never appear in the raw bodies; they are presumed consumed inside callees.
- The sub-viewport entry walk in 0x004FBD70 reads enable and argument words adjacent to the recorded fields this+0x18/0x1C; those neighbor offsets are not in the packet field set.
- The 0x6F/0xA3 flag bytes on the cloud texture registry have no established meaning beyond 'cleared after selection'.
- The LCG (0x005884ED) in 0x004FC2F0 is invoked with an uninitialized-looking argument register; its exact signature is unproven.
- The a2 container identity and the 256-byte child-object stride in 0x004FC2F0 are unknown.
- sub_4A1830 and sub_4A14E0 (VidMan exit) are unnamed; their exact cleanup roles are unknown.
- off_5C330C is the weather snapshot-chain terminator string; its exact semantics are unknown.
- sub_4FDE00's transformation of the base wetness value is not documented in the packet.
- The weather-name field at this+0x1C4 (compared against byte_8ACFA3) records a weather/season identifier string; its meaning is UNKNOWN.
- Branch polarity of sub_53CBC0 in 0x004FC550 (zero selects the cloud setup body) is unresolved.
- dword_8AFE88 is a shared global with conflicting roles (mutex/semaphore handle in 0x004FAC00, audio-network pointer in 0x004FBA10, read-only xref elsewhere); the dual use is not reconciled.
- The 0x10000000 bit at packed list +20 and the (1,1,1,0)/(0,0,1,0) flag calls in 0x004FBD70 are only resolved at the callee level.
- AudioADSREnvelope fields this+0x3C/0x40 are read but their relationship to the current-node pointer at this+0x38 and the table base at this+0x44 is ambiguous against the raw node-walk code.
- The event object behind HudScoringElement this+0x5C is unknown; node fields +0/+4/+8 are timestamp/selector/value only by inference.
- Day/night time boundaries (14400/19800/64800/66600/72000) and the nightlight-group iteration semantics in 0x004FCEE0 are inferred from branch constants.
