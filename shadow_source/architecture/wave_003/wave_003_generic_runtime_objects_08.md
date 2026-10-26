# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Derived architecture proposal for 16 validated functions in scope generic_runtime_objects. All owners are UNKNOWN in the packet except 0x004562F0 (CameraViewSystem, DERIVED), so every class below is a GUESS grouping. One grouping is anchored on a shared this field layout evidenced across two packet methods: HelicopterAudioObject owns the scene handle at this+0x0, the audio/DSP object at this+0x4, a float at this+0x8, a scene reference at this+0xC and a linked state at this+0x10, shared by the one-shot init 0x00448140 and the per-frame update 0x00448330. SessionFlagState groups 0x0044F460 and 0x0044F4A0 on the shared this[a2+892] packed byte array plus the shared dword_5EA43C/dword_7C569C gating. The two camera parsers (0x004562F0, 0x004572B0) are kept as separate classes because they assign different meanings to the same this offsets (rule 8). Nested-base field refs (field:*(this+0x4):..., field:*(obj+0xD88):..., etc.) and the device-table/constant/string globals are evidence-linked but their owning classes are not established, so they are carried in unresolved_evidence_refs.

## Function roles

- `0x00447D00` **BrakeBiasControl** — Adjust the brake-bias index from a signed delta (a2): decrement and clamp at 0 for negative input, increment and clamp at max index (this+0x157C)-1 for positive input; recompute the bias value as index*step+base (this+0x1580 * this+0x1574 + this+0x156C) into this+0x1564, then format the localized 'BrakeBias' label plus fwd:rear percentages ('%s %4.1f:%4.1f') and render it; returns the render result. Vehicle setup/UI control path (caller sub_42C440).
- `0x00448140` **HelicopterAudioObject** — One-shot helicopter audio and scene init (Steward_Init path): store the top-level handle at this+0x0; when the audio device dword_8AC4C4 exists build the 'Ambient\helicopter.wav' path, create a playback object through the device vtable+92 into this+0x4 and program three DSP floats at *(this+0x4)+0x1C/0x20/0x24; walk the scene graph (LinkedListIndexedAccessor 0x0054C230), store the scene entity at this+0xC, copy a float into this+0x8 and dispatch per-child entity calls; look up the helicopter linked data by name into this+0x10 and return its scrolling offset.
- `0x00448330` **HelicopterAudioObject** — Per-frame audio DSP state update (driver sub_4D4580): when the float threshold at this+0x8 is positive, accumulate a2 into this+0x14, dispatch an interrupt, and walk scene-graph children dispatching each via the scene reference at this+0xC; always fetch a scene-node position and, when the DSP object at this+0x4 is non-null, call its vtable slot +4; advance the linked state at this+0x10 via ScrollingDataOffsetAcrossLinkedEntries when a2 equals this+0x18 else LinkedListAnimationTimerDecrement, store a2 back into this+0x18 and return.
- `0x0044B910` **AxisAlignedBoundingBox** — Scan triangle-strip vertex arrays from a2 to accumulate the X and Z extents; write the X center at this+0x8 and inverse half-extent scale at this+0x10 (zeroed via dwords this+0x10/this+0x14 on a degenerate range), the Z center at this+0x18 and scale at this+0x20 (dwords this+0x20/this+0x24).
- `0x0044C430` **SceneTrackTableInitializer** — Fill the global sine table flt_7CA384[0..6] with sin(index * 0.2243994752564138) (step constant from dbl_59EF50), write 1.0 into dword_7CA388[7], and return the final index 7; invoked from the scene-track-file loading path (caller 0x0044C0E0).
- `0x0044F150` **InputProxyStateManager** — Per-frame force-feedback/joystick input poll: null-guard on the device object at this+0x4 and the input-enabled byte byte_5CD08D; joystick path (device type != 2) polls 20-byte events via vtable slot 0x28 into a 1280-byte buffer and merges the pressed flag by slot id; keyboard path (type == 2) reads 256 bytes via vtable slot 0x24, reacquires via slot 0x1C on device-lost errors and retries; accumulate the frame delta into axis positions at this+0x480, transition per-proxy activation states against this+0x880 thresholds, register active proxies into the word list at this+0xC88 gated by ConditionalFlagReturn(dword_5EA43C), and toggle 0x8000 sign bits for the keyboard shift-key pattern.
- `0x0044F460` **SessionFlagState** — Packed flag bit reader (__thiscall): return bit 1 of this[a2 + 892] as 0/1, forced to 0 when ConditionalFlagReturn(dword_5EA43C) is true, dword_7C569C equals 5 and a2 != 1; queried by collision, state-trigger and unknown callers.
- `0x0044F4A0` **SessionFlagState** — Session/subsession flag guard (__thiscall): return whether the per-session flag byte this[a2 + 892] is non-zero, gated by the disjunction (flag latch clear OR dword_7C569C != 5 OR a2 == 1) AND the indexed byte being set.
- `0x0044F4E0` **CursorSystem** — Cursor subsystem init (from HWInput_Enter): configure the frustum viewport to the full screen using dword_8B8DD4/dword_8B8DD8, load the four cursor image files (aCursor00Cur..aCursor03Cur) via 0x0044F540, select cursor index 0 via CursorSelectorFromArray(0), and return 0.
- `0x0044F680` **FrustumViewport** — Configure a viewport rectangle: store top/left/right/bottom bounds into this+0x0/0x8/0xC/0x4, compute center X (this+0x10) and center Y (this+0x14), precompute reciprocal half-width (this+0x18) and reciprocal half-height (this+0x1C) for projection scaling, and return the width difference (right - left).
- `0x0044FCC0` **ForceFeedbackConstantProvider** — Per-frame force-feedback constant setup (driver sub_4537B0): when the DirectInput device at this+0x80 exists, poll via vtable slot 0x64, read 80 bytes of device state via slot 0x24, reacquire via slot 0x1C and retry on device-lost/not-acquired errors; copy the first 8 state dwords to axis floats this+0x398..0x3B4, transform each into smoothed/dead-zone-clamped output at this+0x3B8, write the constant 4-vector at this+0x3E8..0x3F4, and store 16 sign-flag bytes after the axes.
- `0x0044FF50` **AudioChannelManager** — Audio engine channel-routing init: enumerate up to three device entries and match each source against the primary/secondary device tables to assign a channel category id and direction flag; create a channel per index through the device virtual setup, mirroring the primary channel into secondary/tertiary slots and clamping mute-flag globals; re-create the primary channel in race mode (dword_7D1FD8 == 3); enumerate effect devices through the audio managers at obj+0xE08 and obj+0x1204, build up to nine effect channel descriptors gated on the quality level dword_7D1FFC and per-channel float parameters, submit each via the device virtual registration method, and store per-channel rate divisors from 2*PI*1e6.
- `0x004533A0` **GlobalStateConfigurator** — Configure global state: call ThunkToFUN004530a0 (0x00453370) with a fixed sequence of (state index, mode) pairs (states 3,2,0,1,4,5,6 mode 2; loop 26..33 mode 2 if byte_7D1370 == 1 else mode 0; then states 7,21,19,20 mode 2; 17,18 mode 1; 16,23 mode 0; 8 mode 1; 9 mode 0; 10..13 mode 1; remaining fixed pairs; finally state 43 mode 2) and return the final call result.
- `0x00455290` **InputActionStringRegistry** — Straight-line free function (from HWInput_Enter) registering 44 input-action display strings (steering/throttle/brake, gears, clutch, electronic aids, pit/limiter, camera/view, session, cockpit) by passing each through StringCopyWithBufferRealloc; returns the final call result.
- `0x004562F0` **CameraViewSystem** — Parse a camera view configuration (caller 0x00408E20): when ConditionalDispatchBasedOnFlag reports no config section, apply defaults from the in-memory setup block; otherwise iterate config tokens parsing float pairs (offset, clip planes, LOD multiplier, size, center, mipmap LOD bias, radius limits, orientation/position offsets), integer flags and a clear-enable string, then commit values into the camera view object this+0x30..0x78 (and radius/orientation/position offsets into this+0x80..0xAC); returns 1 for an explicit section, 0 for defaults.
- `0x004572B0` **StaticCameraDescriptor** — Parse a static camera/scene descriptor from config (called by StaticCameraSceneLoader 0x0040B030): accumulate key-value pairs (position, orientation, positional size, color, clip planes, LOD multiplier, size, center, mipmap LOD bias, flags, clear flag, activation location/radius) gated by ConditionalDispatchBasedOnFlag on a per-iteration flag buffer, then flush all values into the descriptor at this+0x30..0x98; returns 0 on flush and 1 when the scanner reports the stop code.

## Proposed classes

### BrakeBiasControl

Vehicle setup/UI control for the brake-bias adjustment: stores the current bias index at this+0x1580, its max at this+0x157C, the step at this+0x1574, the base at this+0x156C and the resulting value at this+0x1564; renders the localized label with front/rear percentages. Owner UNKNOWN in the packet; class is GUESS.

Methods: `0x00447D00`

- `this+0x00001564` `double currentBiasValue` (write, DERIVED)
- `this+0x0000156C` `double biasBase` (read, DERIVED)
- `this+0x00001574` `double biasStep` (read, DERIVED)
- `this+0x0000157C` `int maxIndex` (read, DERIVED)
- `this+0x00001580` `int currentIndex` (read_write, DERIVED)

### HelicopterAudioObject

Ambient helicopter audio object binding a scene entity to a looping helicopter.wav playback with per-frame DSP state: shared field layout (scene handle this+0x0, audio/DSP object this+0x4, float this+0x8, scene reference this+0xC, linked state this+0x10) evidenced by both the one-shot init 0x00448140 and the per-frame update 0x00448330; the per-frame update additionally keeps an accumulated time offset at this+0x14 and the previous value at this+0x18. Shared ownership is GUESS, not packet-proven.

Methods: `0x00448140`, `0x00448330`

- `this+0x00000000` `void* topLevelHandle` (read, DERIVED)
- `this+0x00000004` `void* audioDspObject` (read_write, DERIVED)
- `this+0x00000008` `float floatParam` (read, DERIVED)
- `this+0x0000000C` `void* sceneReference` (read_write, DERIVED)
- `this+0x00000010` `void* linkedState` (read_write, DERIVED)
- `this+0x00000014` `float timeOffset` (read, DERIVED)
- `this+0x00000018` `float previousValue` (read_write, DERIVED)

### AxisAlignedBoundingBox

Horizontal-plane (X/Z) bounding box computer: writes the X center at this+0x8 and inverse half-extent scale at this+0x10, the Z center at this+0x18 and scale at this+0x20, zeroing the scale dwords on a degenerate axis. Owner UNKNOWN; class is GUESS.

Methods: `0x0044B910`

- `this+0x00000008` `double xCenter` (write, DERIVED)
- `this+0x00000010` `dword xScaleLowDword` (write, DERIVED)
- `this+0x00000014` `dword xScaleHighDword` (write, DERIVED)
- `this+0x00000018` `double zCenter` (write, DERIVED)
- `this+0x00000020` `dword zScaleLowDword` (write, DERIVED)
- `this+0x00000024` `dword zScaleHighDword` (write, DERIVED)

### SceneTrackTableInitializer

Global lookup-table initializer for the scene-track rendering path: fills flt_7CA384[0..6] with sin(i * 0.2243994752564138) and writes 1.0 into dword_7CA388[7]. No this pointer; a behavioral grouping over the two global tables.

Methods: `0x0044C430`


### InputProxyStateManager

Per-frame input proxy state manager for the force-feedback/joystick path: holds the device type at this+0x0, the input device object at this+0x4, per-proxy axis positions at this+0x480, per-proxy activation limits at this+0x880, clamp thresholds at this+0xC7C/this+0xC80, the active-proxy count at this+0xC84 and the registered proxy word list at this+0xC88; the per-proxy activation byte at this+892 and the auxiliary state byte at this+636 are side tables in the raw source without packet field refs.

Methods: `0x0044F150`

- `this+0x00000000` `int deviceType` (read, DERIVED)
- `this+0x00000004` `void* deviceObject` (read, DERIVED)
- `this+0x00000480` `float[256] axisPositions` (read_write, DERIVED)
- `this+0x00000880` `float perSlotLimit` (read, DERIVED)
- `this+0x00000C7C` `float clampLow` (read, DERIVED)
- `this+0x00000C80` `float clampHigh` (read, DERIVED)
- `this+0x00000C84` `int activeProxyCount` (read_write, DERIVED)
- `this+0x00000C88` `word[?] proxyWordList` (read_write, DERIVED)

### SessionFlagState

Packed per-session flag byte-array owner: both PackedFlagRead (0x0044F460, bit 1) and SessionTypeFlagGuard (0x0044F4A0, byte truthiness) index this[a2 + 892] and are gated by ConditionalFlagReturn(dword_5EA43C) truthiness, session type dword_7C569C == 5 and index a2 == 1. The 892 (0x37C) array stride is evidenced only via source:raw, so it is documented here rather than as a class field.

Methods: `0x0044F460`, `0x0044F4A0`


### CursorSystem

Cursor subsystem initializer called from HWInput_Enter: configures the frustum viewport to the full screen, loads the four cursor image files through the image loader 0x0044F540 and selects cursor index 0 via 0x0044F640. Screen dimensions come from the globals dword_8B8DD4/dword_8B8DD8; no this field layout is evidenced.

Methods: `0x0044F4E0`


### FrustumViewport

Viewport/frustum rectangle object storing top/left/right/bottom bounds (this+0x0/0x8/0xC/0x4), centers (this+0x10/0x14) and reciprocal half-extents (this+0x18/0x1C); configured by 0x0044F680 and consumed by CursorSystemInitialize.

Methods: `0x0044F680`

- `this+0x00000000` `int top` (write, DERIVED)
- `this+0x00000004` `int bottom` (write, DERIVED)
- `this+0x00000008` `int left` (write, DERIVED)
- `this+0x0000000C` `int right` (write, DERIVED)
- `this+0x00000010` `int centerX` (write, DERIVED)
- `this+0x00000014` `int centerY` (write, DERIVED)
- `this+0x00000018` `float recipHalfWidth` (write, DERIVED)
- `this+0x0000001C` `float recipHalfHeight` (write, DERIVED)

### ForceFeedbackConstantProvider

Per-frame provider of force-feedback shader constants: holds the DirectInput device at this+0x80, the 8 axis input floats at this+0x398..0x3B4, the smoothed/clamped axis outputs at this+0x3B8, the constant 4-vector at this+0x3E8..0x3F4 and 16 sign-flag bytes at this+984 (0x3D8, source:raw only); shares the device read/reacquire/recovery pattern with InputProxyStateManager.

Methods: `0x0044FCC0`

- `this+0x00000080` `void* inputDevice` (read, DERIVED)
- `this+0x00000398` `float axisInput0` (read, DERIVED)
- `this+0x0000039C` `float axisInput1` (read, DERIVED)
- `this+0x000003A0` `float axisInput2` (read, DERIVED)
- `this+0x000003A4` `float axisInput3` (read, DERIVED)
- `this+0x000003A8` `float axisInput4` (read, DERIVED)
- `this+0x000003AC` `float axisInput5` (read, DERIVED)
- `this+0x000003B0` `float axisInput6` (read, DERIVED)
- `this+0x000003B4` `float axisInput7` (read, DERIVED)
- `this+0x000003B8` `float[8] axisOutput` (write, DERIVED)
- `this+0x000003E8` `dword constantVector0` (write, DERIVED)
- `this+0x000003EC` `dword constantVector1` (write, DERIVED)
- `this+0x000003F0` `dword constantVector2` (write, DERIVED)
- `this+0x000003F4` `dword constantVector3` (write, DERIVED)

### AudioChannelManager

Audio engine channel router (legacy ABI label 'Audio_Channel_Initialization'): holds the channel-created flag at this+0x414, per-channel envelope regions (this+0x41C..0x4BC), rate-divisor outputs (this+0x4C0..0x4CC), three channel slots (source this+0x4E8/0x4F0/0x4F4, category this+0x508/0x510/0x514, direction this+0x4F8/0x500/0x504), effect-channel counts/data (this+0x518/0x51C/0x520/0x540) and the race-mode flag byte this+0x2DC, plus obj-base device/manager members (primary source obj+0xD88, managers obj+0xE08/obj+0x1204, processing flags obj+0x1054/obj+0x1450). The relationship between the this and obj bases is not proven.

Methods: `0x0044FF50`

- `this+0x000002DC` `byte raceModeFlagByte` (read_write, DERIVED)
- `this+0x00000414` `byte channelCreatedFlag` (write, DERIVED)
- `this+0x00000418` `byte clearedByte` (write, DERIVED)
- `this+0x0000041C` `float channel0Envelope0` (write, DERIVED)
- `this+0x00000420` `float channel0Envelope1` (write, DERIVED)
- `this+0x00000424` `float channel0Envelope2` (write, DERIVED)
- `this+0x00000428` `float channel0Envelope3` (write, DERIVED)
- `this+0x0000042C` `int channel1Bound0` (write, DERIVED)
- `this+0x00000430` `int channel1Bound1` (write, DERIVED)
- `this+0x00000434` `int channel1Bound2` (write, DERIVED)
- `this+0x00000438` `int channel1Bound3` (write, DERIVED)
- `this+0x0000043C` `int channel1Bound4` (write, DERIVED)
- `this+0x00000440` `int channel1Bound5` (write, DERIVED)
- `this+0x00000444` `int channel2Bound0` (write, DERIVED)
- `this+0x00000448` `int channel2Bound1` (write, DERIVED)
- `this+0x0000044C` `int channel2Bound2` (write, DERIVED)
- `this+0x00000450` `int channel2Bound3` (write, DERIVED)
- `this+0x00000454` `int channel2Bound4` (write, DERIVED)
- `this+0x00000458` `int channel2Bound5` (write, DERIVED)
- `this+0x00000480` `byte[?] channelDescriptorRegion` (read_write, GUESS)
- `this+0x0000048C` `float channel5Envelope0` (write, DERIVED)
- `this+0x00000490` `float channel5Envelope1` (write, DERIVED)
- `this+0x00000494` `float channel5Envelope2` (write, DERIVED)
- `this+0x00000498` `float channel5Envelope3` (write, DERIVED)
- `this+0x0000049C` `float channel6Envelope0` (write, DERIVED)
- `this+0x000004A0` `float channel6Envelope1` (write, DERIVED)
- `this+0x000004A4` `float channel6Envelope2` (write, DERIVED)
- `this+0x000004A8` `float channel6Envelope3` (write, DERIVED)
- `this+0x000004AC` `float channel7EnvelopeStart` (write, DERIVED)
- `this+0x000004B0` `float channel8Envelope0` (write, DERIVED)
- `this+0x000004B4` `float channel8Envelope1` (write, DERIVED)
- `this+0x000004B8` `float channel8Envelope2` (write, DERIVED)
- `this+0x000004BC` `float channel8Envelope3` (write, DERIVED)
- `this+0x000004C0` `float rateDivisorOutput0` (write, DERIVED)
- `this+0x000004C4` `float rateDivisorOutput1` (write, DERIVED)
- `this+0x000004C8` `float rateDivisorOutput2` (write, DERIVED)
- `this+0x000004CC` `float rateDivisorOutput3` (write, DERIVED)
- `this+0x000004D0` `float clearedOutput0` (write, DERIVED)
- `this+0x000004D4` `float clearedOutput1` (write, DERIVED)
- `this+0x000004E8` `void* channelSourcePrimary` (read_write, DERIVED)
- `this+0x000004F0` `void* channelSourceSecondary` (read_write, DERIVED)
- `this+0x000004F4` `void* channelSourceTertiary` (read_write, DERIVED)
- `this+0x000004F8` `int channelDirectionPrimary` (read_write, DERIVED)
- `this+0x00000500` `int channelDirectionSecondary` (read_write, DERIVED)
- `this+0x00000504` `int channelDirectionTertiary` (read_write, DERIVED)
- `this+0x00000508` `int channelCategoryPrimary` (read_write, DERIVED)
- `this+0x00000510` `int channelCategorySecondary` (read_write, DERIVED)
- `this+0x00000514` `int channelCategoryTertiary` (read_write, DERIVED)
- `this+0x00000518` `int effectChannelCountPrimary` (write, DERIVED)
- `this+0x0000051C` `int effectChannelCountSecondary` (write, DERIVED)
- `this+0x00000520` `void* effectChannelDataPrimary` (write, DERIVED)
- `this+0x00000540` `void* effectChannelDataSecondary` (write, DERIVED)
- `obj+0x00000D88` `void* primaryDeviceSource` (read_write, DERIVED)
- `obj+0x00000E08` `void* primaryAudioManager` (read, DERIVED)
- `obj+0x00001054` `int primaryProcessingFlag` (read, DERIVED)
- `obj+0x00001204` `void* secondaryAudioManager` (read, DERIVED)
- `obj+0x00001450` `int secondaryProcessingFlag` (read, DERIVED)

### GlobalStateConfigurator

Behavioral grouping for the global-state initializer: drives a fixed sequence of (state index, mode) pairs through ThunkToFUN004530a0 (0x00453370), with the 26..33 loop gated on byte_7D1370. No this pointer; owner UNKNOWN.

Methods: `0x004533A0`


### InputActionStringRegistry

Behavioral grouping for the input-action display-string registration: a straight-line free function (from HWInput_Enter) pushing 44 global action-name strings through StringCopyWithBufferRealloc; the destination action-name table buffer is not visible in this packet.

Methods: `0x00455290`


### CameraViewSystem

Camera view configuration object (owner CameraViewSystem, DERIVED for 0x004562F0): parseCameraViewConfig commits offset/clip/LOD/size/center/mipmap-bias floats, a clear-enable byte, color and two flag ints into this+0x30..0x78, and radius/orientation/position offsets directly into this+0x80..0xAC (source:raw only beyond 0x78).

Methods: `0x004562F0`

- `this+0x00000030` `float offsetX` (write, DERIVED)
- `this+0x00000034` `float offsetY` (write, DERIVED)
- `this+0x00000038` `float clipNear` (write, DERIVED)
- `this+0x0000003C` `float clipFar` (write, DERIVED)
- `this+0x00000040` `float lodMultiplier` (write, DERIVED)
- `this+0x00000044` `float sizeX` (write, DERIVED)
- `this+0x00000048` `float sizeY` (write, DERIVED)
- `this+0x0000004C` `float centerX` (write, DERIVED)
- `this+0x00000050` `float centerY` (write, DERIVED)
- `this+0x00000054` `float mipmapLodBias` (write, DERIVED)
- `this+0x00000058` `float extraFloatA` (write, GUESS)
- `this+0x0000005C` `float extraFloatB` (write, GUESS)
- `this+0x00000060` `byte clearEnabled` (write, DERIVED)
- `this+0x00000064` `int colorRed` (write, DERIVED)
- `this+0x00000068` `int colorGreen` (write, DERIVED)
- `this+0x0000006C` `int colorBlue` (write, DERIVED)
- `this+0x00000070` `int zeroDword` (write, GUESS)
- `this+0x00000074` `int flags1` (write, DERIVED)
- `this+0x00000078` `int flags2` (write, DERIVED)

### StaticCameraDescriptor

Static camera/scene descriptor parsed by ParseStaticCameraConfig (caller StaticCameraSceneLoader 0x0040B030): flush writes clip planes, positional size, LOD, size, center, mipmap bias, clear flag, color, flags and the position vector into this+0x30..0x98, plus activation location/radius into this+124..136 (source:raw only); the enabled flag at this+0x84 and the flag words at this+0x7C are source:raw-only and not class fields.

Methods: `0x004572B0`

- `this+0x00000030` `float clipNear` (write, DERIVED)
- `this+0x00000034` `float clipFar` (write, DERIVED)
- `this+0x00000038` `float positionalSizeX` (write, GUESS)
- `this+0x0000003C` `float positionalSizeY` (write, GUESS)
- `this+0x00000040` `float clipNearDup` (write, GUESS)
- `this+0x00000044` `float clipFarDup` (write, GUESS)
- `this+0x00000048` `float positionalSizeDupX` (write, GUESS)
- `this+0x0000004C` `float positionalSizeDupY` (write, GUESS)
- `this+0x00000050` `float clipLod` (write, GUESS)
- `this+0x00000054` `float sizeX` (write, DERIVED)
- `this+0x00000058` `float sizeY` (write, DERIVED)
- `this+0x0000005C` `float centerX` (write, DERIVED)
- `this+0x00000060` `float centerY` (write, DERIVED)
- `this+0x00000064` `float mipmapLodBias` (write, DERIVED)
- `this+0x00000068` `byte clearFlag` (write, DERIVED)
- `this+0x0000006C` `int zeroDword` (write, GUESS)
- `this+0x00000070` `int colorRed` (write, GUESS)
- `this+0x00000074` `int colorGreen` (write, GUESS)
- `this+0x00000078` `int colorBlue` (write, GUESS)
- `this+0x00000080` `int flags2` (write, GUESS)
- `this+0x00000090` `float positionX` (write, DERIVED)
- `this+0x00000094` `float positionY` (write, DERIVED)
- `this+0x00000098` `float positionZ` (write, DERIVED)

## Compatibility contracts

- **DirectInputDeviceReadRecovery** — Both InputProxyStateManager (device object at this+0x4) and ForceFeedbackConstantProvider (device object at this+0x80) read device state through the device object's vtable slot 0x24 and, on error -2147024884 or -2147024866, reacquire through vtable slot 0x1C and retry the read once before failing; a replacement must preserve the two error codes and the acquire-and-retry ordering.
- **SessionFlagByteArray** — A per-session packed flag byte array is indexed as this[a2 + 892]; PackedFlagRead reads bit 1 and SessionTypeFlagGuard reads the byte's truthiness, both gated by ConditionalFlagReturn(dword_5EA43C) truthiness, session type dword_7C569C == 5 and index a2 == 1. The 892-byte stride is evidenced only via source:raw.
- **BrakeBiasValueAndDisplay** — BrakeBiasControl recomputes the bias value as index * step + base (this+0x1580 * this+0x1574 + this+0x156C) with the index clamped to [0, this+0x157C - 1], stores it at this+0x1564, and formats the display as '<localized BrakeBias text> %4.1f:%4.1f' with front/rear percentages 100.0 - v*100.0 and v*100.0; a replacement must preserve the clamp bounds, the value formula and the display format literal.
- **AudioChannelSlotLayout** — The audio channel router maintains three channel slots with source pointers at this+0x4E8/0x4F0/0x4F4, category ids at this+0x508/0x510/0x514 and direction flags at this+0x4F8/0x500/0x504, with the primary device source at obj+0xD88 and effect-device managers at obj+0xE08 and obj+0x1204; mute/volume behavior keys off globals dword_7D2044/dword_7D2068 and race mode dword_7D1FD8 == 3. A replacement must preserve the slot layout and the mute-flag globals.
- **SceneGraphWalkContract** — HelicopterAudioObject init and update walk the scene-graph entity list through LinkedListIndexedAccessor (0x0054C230) with the child count from SceneGraphChildCount (0x0054C210) on the top-level handle at this+0x0 and the stored scene reference at this+0xC; per-child dispatch differs between init (ConditionalEntityCallOnNonNull 0x00551800) and update (ConditionalDispatchByFlag 0x00551810). A replacement must preserve the list-accessor usage and the init/update dispatch split.

## Unresolved

- PackedFlagRead and SessionTypeFlagGuard index a per-session flag byte array at this[a2 + 892] (0x37C); the array stride is evidenced only via source:raw, so it is documented in the SessionFlagState responsibility rather than as a class field.
- SessionFlagState groups 0x0044F460 and 0x0044F4A0 on the shared this layout and the shared dword_5EA43C / dword_7C569C gating; the class is GUESS, not packet-proven. The meaning of the dword_7C569C == 5 session-type comparison and why index a2 == 1 is excluded are unknown.
- HelicopterAudioObject groups the one-shot init 0x00448140 and the per-frame update 0x00448330 on the shared field layout this+0x0/0x4/0x8/0xC/0x10; the shared ownership is GUESS. The semantics of the three DSP parameters at *(this+0x4)+0x1C/0x20/0x24 as engine-RPM tuning are not deterministically provable from this packet.
- CameraViewSystem (0x004562F0) and StaticCameraDescriptor (0x004572B0) both parse camera configs into this+0x30..0x78 but assign different meanings at the same offsets (e.g. this+0x30 is offset X in the view parser and near clip in the static parser); per rule 8 they are kept as separate classes.
- CameraViewSystem writes radius limits, orientation rate/offset, position offset and radius directly at this+0x80..0xAC; StaticCameraDescriptor writes activation location/radius at this+124..136, the flag words at this+0x7C and the enabled flag at this+0x84. None of these offsets have field evidence refs in the packet and are documented from source:raw only.
- The exact split of the color aggregate and the two flag words across StaticCameraDescriptor this+0x64..0x78 is inferred from the flush sequence, not independently verified.
- AudioChannelManager mixes this-base channel slots and obj-base device/manager members (obj+0xD88/0xE08/0x1054/0x1204/0x1450); the relationship between the 'this' and 'obj' bases (same object vs sub-object) is not proven by the packet.
- The nested-base field refs (field:*(obj+0xD88):0x00000080, field:*(obj+0xE08):0x00000000, field:*(obj+0xE08):0x00000038, field:*(*(obj+0xE08)+0x0):0x00000010, field:*(*(obj+0xE08)+0x0):0x00000038, field:*(*(obj+0x1204)+0x0):0x00000010, field:*(*(obj+0xD88)+0x80):0x00000000, field:*(*(*(obj+0xD88)+0x80)+0x0):0x00000018/1C/20/48, field:*(this+0x4):0x00000000/1C/20/24/28, field:*(*(this+0x4)+0x0):0x00000004, field:*(this+0x80):0x00000000, field:*(*(this+0x80)+0x0):0x0000001C/24/64) describe vtable slots and sub-object members whose owning classes are not established; left unresolved.
- The device-match-table globals (primary: 0x007CA490, 0x007CCA44, 0x007CA3E8, 0x007CA470, 0x007CD198, 0x007CA3C8, 0x007CCBB0, 0x007CCFB0, 0x007CCA6C, 0x007CCF80, 0x007CCCB0, 0x007CCA7C; secondary: 0x007CA3B8, 0x007CC9BC, 0x007CD158, 0x007CA50C, 0x007CD0F8, 0x007CA438, 0x007CA448, 0x007CCBF4, 0x007CA3A8, 0x007CA480, 0x007CC9EC, 0x007CA3D8) assign channel category ids 0/4/8/12/16/20 and direction flags; the exact table semantics beyond those ids are unknown.
- The read-only dword table 0x005AD360..0x005AD3EC and the constant float globals 0x0059E43C/0x0059E440/0x0059E450/0x0059E420/0x0059E430/0x0059E880/0x0059EA20/0x0059EE68/0x0059EF30/0x0059EF48/0x0059EF50/0x0059EF58 appear in the packet facts but not (or not provably) in the raw decompiled bodies; their roles are unverifiable from this packet.
- Render-literal meanings are unknown: TextLineWrappingAndRendering mode 3 and color/coordinate 16909060; the DSP vtable slot +4 update literal 1065353216 (= 1.0f bit pattern); the force-feedback device vtable slots 0x64/0x24/0x1C semantics are inferred from behavior, not named.
- The sub_5651B0 scanner return codes (2 = no section / finished with defaults, 4 = finished with explicit section) and the ConditionalDispatchBasedOnFlag 384-byte gating buffer are inferred from the branch structure of both camera parsers, not proven.
- ForceFeedbackConstantProvider's 16 sign-flag bytes at this+984 (0x3D8) and the per-axis dead-zone/clamp/smoothing parameters before the output array, plus InputProxyStateManager's per-proxy activation byte at this+892 and auxiliary state byte at this+636, appear in the raw source but have no field evidence refs in the packet.
- The final sign-bit toggle pass in 0x0044F150 (keyboard bit v19[58], 0x8000 toggling over the jump-table case range 0x10..0x19/0x1E..0x26/0x2C..0x32 via jpt_44F3EE) has DERIVED structure but unknown gameplay meaning; byte_44F434 (0x0044F434) is in the packet global list but not in the raw body.
- SinTableInit's angle step 0.2243994752564138 and the trailing dword_7CA388[7] = 1.0 write have unknown angular-range meaning; the consumer of the sine-table globals flt_7CA384/dword_7CA388 in the scene-track renderer is not in this packet.
- GlobalStateInitializerWithEnumValues state indices 0..43 and mode values 0/1/2 are not confirmed as enums; callee 0x00453370 (ThunkToFUN004530a0) semantics are not established.
- registerInputActionStrings writes through StringCopyWithBufferRealloc into a destination action-name table that is not visible in this packet; the caller HWInput_Enter (0x00455BF0) suggests the keybinding-display table, and the owner (no this pointer) is unknown.
- AudioChannelInitialization's legacy ABI label is 'Audio_Channel_Initialization'; field-level semantics were not independently verified. The descriptor layout constants (type 56, dimensions 17/18, rate divisor 10000) are observed but their field meaning is not confirmed.
- BrakeBiasAdjustmentControl's a2 signed-delta semantics and the exact caller sub_42C440 context are not part of this packet.
- parseCameraViewConfig (0x004562F0) declares a2 in its signature but never references it in the decompiled body; its role is unknown.
- The scene-entity float copy (root+316, sub-object +28 -> +8 float) in 0x00448140 is structural; the meaning of the copied float is not established.
- The two camera parsers are invoked from 0x00408E20 and StaticCameraSceneLoader 0x0040B030; the caller frame frequency and config-file context are outside this packet.
