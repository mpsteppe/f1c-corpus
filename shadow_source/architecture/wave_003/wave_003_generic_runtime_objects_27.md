# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Reconstructs 16 generic runtime functions of the F1 Challenge engine as five candidate classes plus free helpers. The frame-rate HUD widget (0x004F8D70/0x004F8EA0/0x004F8F10/0x004F8F50) shares one this-layout and the FTFrameRate registry entry. The VidMan lifecycle (0x004FA000/0x004FA320/0x004FA640) drives directory validation and relaunch, rendering-mode/audio-engine init, and session-type display flags. A per-frame telemetry tick (0x004EF4F0) writes ProgressBarEvent records into a bounded ring buffer fed by the global time accumulators (0x004F9AD0). A multi-object array remover (0x004E3A50), a dual-table state-handler dispatcher (0x004F7010), the loading-transition renderer (0x004F9480), the Bink loading sequence (0x004F9B70) and the one-time-init flag pair (0x004F9F00/0x004F9F30) plus global float setter (0x004F9F70) complete the set. All ownership and field semantics are DERIVED/GUESS; no CONFIRMED claim is made.

## Function roles

- `0x004E3A50` **MultiObjectContainer** — Removes every element of an owned object array: the count at this+0xBA8 drives a loop that calls sub_4DF110(element, a2, -1) per element over a 748-byte stride and returns the final count. Structural twin of UIElementMultiDispatch.
- `0x004EF4F0` **TelemetryEventRecorder** — Per-frame telemetry tick: appends an encoded ProgressBarEvent record into a bounded ring buffer (1023 slots, 432-byte stride) gated on the session time at dbl_8AFEA0 exceeding the last-recorded timestamp at this+0x4014 by 4.5.
- `0x004F7010` **StateHandlerTableDispatcher** — State-handler dispatch: selects handler table A (this+0x694) or B (this+0x6D8) from the flag byte at this+0xB0, iterates up to 45 entries invoking each non-null handler's vtable+8 virtual, then stores a2 into the flag byte.
- `0x004F8D70` **FrameRateHudWidget** — Initializes the frame-rate HUD widget: writes display-state and position fields, allocates and constructs the 76-byte backing sub-object, computes screen layout from the resolution globals, registers the font path, loads Font.MAS and FTFRAMERATE.BMP, and activates the widget only when both loads succeed.
- `0x004F8EA0` **FrameRateHudWidget** — Resets the frame-rate counter/timer object: conditionally frees the object at this+0x18, searches the wide-string linked list for the FTFrameRate entry and compares its match, then zeroes every counter/timer field (this+0x0..this+0x2C) and the byte flag at this+0x6C.
- `0x004F8F10` **FrameRateHudWidget** — Gated timer/counter reinitializer for the frame-rate HUD: when the guard at this+0x0 is non-null, stores the counter parameter a2 into this+0x4, resets the high-resolution timer from this+0x18 and zeroes this+0xC; when a2 is zero it additionally looks up FTFrameRate in the wide-string list and dispatches cleanup.
- `0x004F8F50` **FrameRateHudWidget** — Frame-rate/performance monitor and overlay renderer: increments the frame counter and dispatches on the sub-mode at this+4 (case 0 elapsed-time min/max, case 1 instantaneous rate, case 2 frame-count output, case 3 override ratio), then drives the shared text-overlay renderer through sub_53D2E0.
- `0x004F9480` **UnknownObject** — Renders the loading transition screen: builds and loads the track-preview LOD and logo bitmaps from the current track path, draws the track-name title (aFtim28wht at y=117) and sub-title (aFtim18wht at y=515) right-aligned against x=780, renders the progress bar while the progress value stays below the vehicle-count-derived threshold, then frees the bitmaps and hands off on completion.
- `0x004F9AD0` **UnknownObject** — Accumulates the shared per-frame delta: reads sub_556730(0) into dbl_8AFE90, copies it into dbl_8AFE98 and accumulates it into dbl_8AFEA0 and dbl_8AFEA8; returns the low DWORD of the delta.
- `0x004F9B70` **UnknownObject** — Loads a file/object with a path-prefix replacement retry on first failure, then presents a Bink video loading sequence (spinning until a frame renders, or until the input-device count dword_7CB218 becomes positive when the wait flag is set); returns 1 only if both load attempts fail.
- `0x004F9F00` **UnknownObject** — Conditional one-time initialization gated by byte_8AFE71: only when StructFieldGetter(&dword_8B78A0) is non-zero and the flag is clear does it set the flag to 1 and run the follow-up dispatch; the flag records that initialization has already run.
- `0x004F9F30` **UnknownObject** — Conditional reset of the one-time-init flag byte_8AFE71, counterpart of ConditionalInit: when the flag is set it is cleared to 0 and the follow-up dispatch runs so the next ConditionalInit call re-runs its setup.
- `0x004F9F70` **UnknownObject** — Selects and stores one of three constants (1.0, 30.0, 0.119999997317791) into the global double at 0x5D6D70 based on argument a1 (0, 1 or 2); returns the decremented argument as a side result.
- `0x004FA000` **VidMan** — Video manager entry point: debug-initializes command-line splitting, starts the QPC timer and the system allocator, resolves and compares the player-file directory against the configured game directory; on match initializes display/window/graphics sub-modules, on mismatch relaunches the game executable via CreateProcessA and returns 1.
- `0x004FA320` **VidMan** — Initializes the video/visual manager subsystem: mirrors rendering/audio config globals, selects the rendering mode via a switch on dword_7CFB90, loads the track scene, registers the season path strings, registers the render-init callback sub_4F9480, and initializes the audio engine against the track geometry; returns 1 on audio engine initialization failure.
- `0x004FA640` **VidMan** — Resets video-manager state on game restart: logs entry, clears the session-type state, switches on the session type to set/clear display flags 64/128/256, re-arms session state for session type 7 under guards, then resets renderer state (sub_4F9FC0), zeroes the input-axis dead zone and race-dynamics globals, and returns GlobalFloatSetter(0).

## Proposed classes

### FrameRateHudWidget

Frame-rate counter/HUD display widget. initFrameRateHudWidget writes the display-state and position layout, allocates and constructs the backing sub-object, and loads Font.MAS plus FTFRAMERATE.BMP; FrameRateCounterInitReset frees the backing object and zeroes every counter field; ConditionalInitBranch reinitializes the high-resolution timer when the widget is active; FrameRateMonitorAndOverlayRenderer tracks and renders the rate/text overlay every frame.

Methods: `0x004F8D70`, `0x004F8EA0`, `0x004F8F10`, `0x004F8F50`

- `this+0x00000000` `int mode_active_flag` (read_write, DERIVED)
- `this+0x00000004` `int submode_or_type` (read_write, DERIVED)
- `this+0x00000008` `int output_value` (read_write, DERIVED)
- `this+0x0000000C` `int frame_counter` (read_write, DERIVED)
- `this+0x00000010` `float tracked_minimum` (read_write, DERIVED)
- `this+0x00000014` `float tracked_maximum` (read_write, DERIVED)
- `this+0x00000018` `pointer timer_or_subobject_pointer` (read, DERIVED)
- `this+0x0000001C` `int display_duration_or_position` (read_write, DERIVED)
- `this+0x00000020` `int font_size_or_extra_param` (read_write, DERIVED)
- `this+0x00000024` `int y_screen_offset` (write, GUESS)
- `this+0x00000028` `int line_height` (write, GUESS)
- `this+0x0000002C` `byte ready_flag` (read_write, DERIVED)
- `this+0x0000006C` `byte secondary_byte_flag` (write, GUESS)

### VidMan

Video manager lifecycle. VidMan_Enter validates the configured game directory and either initializes the display/graphics pipeline or relaunches the executable; VidMan_Init selects the rendering mode, loads the track scene, registers season paths and initializes the audio engine; VidMan_Restart reconfigures session display flags and resets renderer state on restart. Packet uses the alias VideoManager for the same subsystem in 0x004FA320.

Methods: `0x004FA000`, `0x004FA320`, `0x004FA640`


### TelemetryEventRecorder

Per-frame telemetry/event recorder. Appends ProgressBarEvent-encoded records into a bounded ring buffer (1023 slots, 432-byte stride) gated on the session-time accumulator; payload fields at this+0x4 and this+0x34AC feed the encoder.

Methods: `0x004EF4F0`

- `this+0x00000004` `int telemetry_payload_field` (read, GUESS)
- `this+0x000034AC` `float telemetry_payload_float` (read, GUESS)
- `this+0x00004014` `double last_recorded_session_time` (read_write, GUESS)

### MultiObjectContainer

Container owning an array of sub-objects (748-byte stride) with an element count at this+0xBA8; MultiObjectRemove releases every element through sub_4DF110. Structural twin of UIElementMultiDispatch.

Methods: `0x004E3A50`

- `this+0x00000BA8` `int element_count` (read_write, GUESS)

### StateHandlerTableDispatcher

Object dispatching into one of two handler tables (this+0x694 / this+0x6D8, 45 entries at a 4-byte stride) by the flag byte at this+0xB0, invoking each non-null handler's vtable+8 virtual.

Methods: `0x004F7010`

- `this+0x000000B0` `byte table_select_flag` (read_write, GUESS)
- `this+0x00000694` `pointer handler_table_a` (read, GUESS)
- `this+0x000006D8` `pointer handler_table_b` (read, GUESS)

## Compatibility contracts

- **TelemetryRingBufferFormat** — Telemetry/event records appended at the write pointer dword_8AAE64 use a 432-byte stride with a 1023-slot ceiling and a record count at dword_83EE60; each record is encoded via ProgressBarEventEncode with the argument tuple (2, 0, 0, value at this+0x4, value at this+0x34AC, 0). A replacement must preserve this layout to interoperate with the ProgressBarEvent reader.
- **FrameRateHudInitContract** — initFrameRateHudWidget allocates a 76-byte backing sub-object constructed by sub_556220, registers the resolved font path, and loads Font.MAS plus FTFRAMERATE.BMP; the widget is only marked active (this+0x0 = 2) when the font lookup and the bitmap surface load both succeed.
- **FrameRateHudResetContract** — FrameRateCounterInitReset releases the heap object held at this+0x18 (through the empty stub and free wrapper), searches the wide-string linked list for the FTFrameRate entry, then zeroes the counter fields this+0x0 through this+0x2C and the byte flag at this+0x6C.
- **VideoManagerDirectoryRelaunch** — VidMan_Enter compares the player-file directory (dword_5EC488 entry + 8, or a built-in default) against the configured game directory (dword_5EC480, fallback byte_5EA438); when they differ it relaunches the game executable via CreateProcessA in the configured directory (dword_5EC3D0) and returns 1. A replacement must reproduce this relaunch gate for multi-directory installs.
- **VideoManagerSessionDisplayFlags** — VidMan_Restart configures display flags 64/128/256 from the session type at dword_7C56A4 (cases 0-4 windowed-style, case 5, cases 6-7, default clear); session type 7 additionally re-arms session state via sub_42D210 when the scoring gate (dword_8AB6E4), setup-dir flag, HUD-disabled byte and session-state checks permit.
- **LoadingScreenRenderContract** — The loading transition screen draws the track-name title with aFtim28wht at y=117 and the sub-title with aFtim18wht at y=515, both right-aligned against x=780; the progress-bar fill width is CRTFtol(a2*800/threshold) with threshold = dword_5C329C*1.5+113.0, and a redraw is gated on the fill advancing at least 3 px past the watermark at dword_8AFEBC.
- **BinkLoadingSequence** — FileLoadWithRetryLoop first attempts object creation from the original path with rollback; on failure it replaces the path prefix using the season parent path dword_5EC3D0 and retries. It then presents Bink frames, spinning until a frame renders or, when the wait flag is set, until the input-device count dword_7CB218 becomes positive. It returns 1 only if both load attempts fail.
- **ConditionalInitGateContract** — ConditionalInit and ConditionalStateReset maintain the one-time-init flag byte_8AFE71 gated on a non-zero StructFieldGetter(&dword_8B78A0) result: ConditionalInit sets the flag and runs its dispatch, ConditionalStateReset clears it so the next ConditionalInit re-runs setup. Used by the frame path, 2D screen-quad render, options setup and video-manager enter.
- **StateHandlerDispatchContract** — StateHandlerDispatch selects handler table A at this+0x694 or table B at this+0x6D8 from the flag byte at this+0xB0, iterates up to 45 entries at a 4-byte stride over offsets 0..176, invoking the vtable+8 virtual on each non-null entry, then stores a2 into the flag byte and returns the selected table pointer.
- **MultiObjectRemoveContract** — MultiObjectRemove removes every element of an object array (stride 748 bytes / 187 floats) starting at this+747 (float), calling sub_4DF110(element, a2, -1) per element while the re-read count at this+0xBA8 exceeds the loop counter, and returns the final count.

## Unresolved

- The FrameRateHudWidget field at this+0x18 is written by initFrameRateHudWidget as a constructed 76-byte sub-object pointer but read by the monitor and the conditional re-init as a high-precision timer handle; the packet does not prove these refer to the same object.
- Field this+0x1C is interpreted as an X screen-position offset by initFrameRateHudWidget (900) and as a display duration by FrameRateMonitorAndOverlayRenderer (900/992); the semantic conflict is unresolved.
- The packet uses two owner labels for the video manager: VidMan for 0x004FA000 and VideoManager for 0x004FA320. This proposal groups both with VidMan_Restart (packet owner UnknownObject) into class VidMan based on the VidMan_* function names and lifecycle callers only.
- Telemetry ring-buffer capacity/reuse semantics (1023-slot ceiling, 432-byte stride, count at dword_83EE60, write pointer at dword_8AAE64) and the ProgressBarEventEncode argument tuple (2, 0, 0, payload0, payload1, 0) are not independently evidenced.
- sub_53D2E0 is inferred to be the shared text-overlay renderer from packet prose; its body is not in this packet.
- VidMan object layout is not evidenced: VidMan_Restart delegates state reset to sub_4F9FC0 (outside this packet), and sub_4F9420 and sub_4F9310 called by VidMan_Enter are opaque.
- Several packet-flagged globals (for example dword_8AFE64) are reported read or written by deterministic facts but never appear in the raw decompiled text; they cannot be verified here and are listed in unresolved_evidence_refs.
- byte_8AFE94 and byte_8AFE9C overlap the storage of the adjacent doubles dbl_8AFE90 and dbl_8AFE98; their independent role is not evidenced.
- The purpose of sub_556260(1), the one-argument companion call in initFrameRateHudWidget, is unresolved.
- The display-duration literals 900 and 992 and the clamp at 999 in FrameRateMonitorAndOverlayRenderer lack independent game-semantic evidence.
- sub_556730(0) is used both as a per-frame delta (AdvanceTimeAccumulatorGlobals) and as a sound volume source (RenderLoadingTransitionScreen); whether it returns a frame delta or an absolute value is unknown.
- GlobalFloatSetter constants 1.0/30.0/0.119999997317791 written to the double at 0x5D6D70 have no documented meaning for the video-manager callers.
- The identity of the vtable+8 virtual invoked by StateHandlerDispatch and of the handler object type are unknown.
