# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Twenty-four functions reconstructed as fifteen worker-proposed classes and two interfaces, all with owner trust UNKNOWN in the packet. Coherent sub-clusters: (1) ParameterCurveRuntime - keyframe-curve evaluation with a threshold/status fallback; (2) RangeInterpolationCurve + CarPositionCheck - a 16-entry float interpolation table with a position-target check that populates it; (3) AudioEventRingBuffer - a 720-slot ADSR-driven audio event ring buffer with a linked event list that is merge-sorted and torn down; (4) CloudSceneNameState - matching/updating cloud-scene names and writing them to the progress-bar ring; (5) WeatherConditionMultipliers - static name-to-scalar lookup tables; (6) SessionGlobalCacheAccessors and SessionStateController - module-global accessors and session timing helpers over the 0x008AFE6x/0x008AFEAx region; plus singletons (RenderColorUpdateState, FloatColorToWordWriter, FloatDefaultsConfig, HUDConfigRandomSelector, PiecewiseResponseCurve, BlendFactorReciprocalSetter, AudioRangeClampSetter). Twenty-eight float-pool globals are flagged but unmapped in the raw source; no worker claim reaches CONFIRMED.

## Function roles

- `0x004F8A70` **HUDConfigRandomSelector** — Random parameter dispatch: draw one random value via the LCG, bucket it into parameter 20/19/18 using the 10922 and 21844 thresholds, and forward the selected bucket with fixed mode 2 and 1.0/1.0 to the HUD element config; returns the config result.
- `0x004F9160` **SessionGlobalCacheAccessors** — Bounded index/value setter over module globals: read the upper bound via the field getter from dword_8AFE64, guard the requested index below that bound, store the index to dword_8AFE6C and the indexed value to dword_8AFE68; returns the bound on guard failure, else the stored value.
- `0x004F91B0` **SessionGlobalCacheAccessors** — Feature-gated object field reader: when global dword_8AFE68 is non-zero, resolve the object for key a1 and copy fields dword[2]/[3]/[5]/[6] into the non-null output pointers a2..a5; no-op when the global guard is zero.
- `0x004F9230` **SessionGlobalCacheAccessors** — Zero-argument forwarder: read the global dword_5EC48C and pass it to the guarded field accessor, returning the callee result unchanged; used by the material/shader reaction effect parser.
- `0x004F9420` **SessionGlobalCacheAccessors** — Coordinate search result store: run the multi-table coordinate search; on a non-negative result store the input tuple and returned index into dword_5D6D60/64/68 and dword_8AFE74/78 and return 0, otherwise return 1 without storing.
- `0x004F9B30` **SessionStateController** — Session state-flag computation: base flag = 2 - sub_4F9B20, OR bit 4 when a1 is non-zero or the DisableHUD flag is set, dispatch the value through the call wrapper, and record a -2 result in the audio-init flag byte_8AFE72; returns the dispatch status.
- `0x004F9FC0` **SessionStateController** — Session time and timer reset: store the float argument into the session-time global dbl_8AFEA0, reset the high-precision timer on this, run two index/bounds checks against the table at 008b8e48, and store sub_556760(0) into dbl_8AFEA8.
- `0x004FC170` **RenderColorUpdateState** — Render color update: compute a 24-bit color pattern from the float alpha, store it at this+0x40 only when changed, collect up to 16 node pointers from this+0x0, this+0x10 and the arrays at this+0x4C/this+0x80, and OR the color into each packed-array entry's +24 field preserving the top byte, clearing a status bit in node+20.
- `0x004FC650` **CloudSceneNameState** — Progress-bar ring event writer: advance the ring cursor dword_8AAE64 by 432 (guarded by dword_83EE60 < 1023) and encode a progress-bar event carrying the two strings at this+0x50 and this+0x84 plus the session-time value.
- `0x004FC700` **CloudSceneNameState** — Cloud scene name match/update: gate on the multiplayer flag and scoring gate, compare the packet name strings against the stored buffers, copy both names on difference, then trigger cloud texture setup or store the extracted type code at this+0x44; refresh the stored code when names already match and it is not -1.
- `0x004FC870` **FloatColorToWordWriter** — Float color to 16-bit words: scale six this-floats (channels 0..3 by 65535.0, channels 4..5 by 128.0) and write the truncated values through the a2 word output; returns the truncated channel-4 value.
- `0x004FC9A0` **FloatDefaultsConfig** — Initialize four consecutive float fields on a thiscall object to the defaults 0.0f, 20.0f, 0.3f, 0.0f at offsets 0x0/0x4/0x8/0xC; returns the object pointer.
- `0x004FD6F0` **RangeInterpolationCurve** — Populate the 16-entry interpolation table at this[25..40] (byte offsets 0x64..0xA0) from the range this[10..11] (0x28..0x2C) using fixed interpolation fractions read from the data-segment float pool.
- `0x004FD7E0` **RangeInterpolationCurve** — 1D float table lookup with linear interpolation: return the this[40] high-bound sentinel when a2 >= 3.75, else scale a2 by 4.0, extract the integer table index, and lerp between entries this[idx+25] and this[idx+26] using the rounding remainder.
- `0x004FD840` **AudioEventRingBuffer** — Destroy two linked lists: walk the first list from this+0x3C (next at node+0xC) freeing nodes and clearing this+0x38; walk the second list from this+0x54 (sub-pointer at node+0, next at node+4, flag at node+8) freeing sub-pointers when flagged and every node, then clear tracking fields this+0x54..0x60.
- `0x004FDE00` **PiecewiseResponseCurve** — Piecewise envelope computation: below/at 0.60000002 zero both outputs at this+0x20/0x24; above it select between a linear ramp on this+0x20, a saturated-then-ramping pair on this+0x20/0x24, or a saturated state, using FPU compare flags whose exact predicate is ambiguous.
- `0x004FE060` **CarPositionCheck** — Car position target check: gate on the multiplayer flag / scoring gate, compute the target from this+0x20 via sub_4FC910, set the match flag this+0x4 to 2.0f when |this+0x8 - target| <= 0.5 else 0, then run the range-interpolation table population on this.
- `0x004FE0D0` **WeatherConditionMultipliers** — Weather-name wetness multiplier: return the fixed multiplier for an exact name match (Best 0.030000001, Nice 0.30000001, Clear 0.60000002, Overcast 0.64999998, Drizzle 0.73000002, Rain 0.85000002, Monsoon 0.96999997), else fall back to a continuous per-name value scaled by 0.0099999998 and clamped to [0,1].
- `0x004FE1E0` **WeatherConditionMultipliers** — Weather-severity grip multiplier: return 0.0/0.25/0.5/0.75/1.0 for base/Damp/intermediate/Soaked/Monsoon name matches, else scale the numeric severity from sub_58850F by 0.0099999998 and clamp to [0,1].
- `0x004FEAF0` **AudioEventRingBuffer** — Audio event ring-buffer processing: with a valid input event, seed the noise counter, run the 720-slot ADSR envelope pass, scan slot deltas for peaks, spawn sorted linked-list event nodes gated by noise/condition thresholds, then count, split and merge-sort the node list and rewrite the head/tail/root anchors.
- `0x004FEFC0` **BlendFactorReciprocalSetter** — Clamped blend-factor preparation: store a2 at this+0xA8, clamp to [0.01, 1.0], write 1.0/factor at this+0xAC and 1.0/(1.0-factor) at this+0xB0.
- `0x004FF040` **AudioRangeClampSetter** — Range clamp into two float fields: low (this+0xFC) = 1 - a2 clamped to [0,1]; high (this+0x100) = 1 - a3, forced >= low and <= 1.0.
- `0x004FF130` **ParameterCurveRuntime** — Parameter-curve evaluation: with a keyframe chain at this+0x38, interpolate the head and next keyframe values by the current session time, converting the result through the threshold-based return; without a curve, fall back to status codes 2-5 selected from this+0x20/this+0x24.
- `0x004FF1D0` **ParameterCurveRuntime** — Audio-filter parameter calculation: walk the keyframe chain at this+0x38 up to the session-time-based target horizon, track min/max of node values, return the threshold-converted average offset by this+0x104; without a curve fall back to status codes 2-5 from this+0x20/this+0x24.

## Proposed classes

### ParameterCurveRuntime

Runtime object that evaluates a time-parameter curve stored as a keyframe linked list hanging off this+0x38 (node layout: time at +0, value at +8, next at +0xC). When no curve is configured it falls back to integer status codes 2-5 selected from this+0x20 (fallback value) and this+0x24 (fallback threshold). Both methods convert their computed float to a status code through ThresholdBasedReturn (0x004FEAA0).

Methods: `0x004FF130`, `0x004FF1D0`

- `this+0x00000038` `KeyframeNode* (linked list) keyframe_list_head` (read, DERIVED)
- `this+0x00000020` `float fallback_value` (read, DERIVED)
- `this+0x00000024` `float fallback_threshold` (read, DERIVED)
- `this+0x00000104` `float filter_offset` (read, GUESS)
- `*(this+0x38)+0x00000000` `float/double keyframe_time` (read, DERIVED)
- `*(this+0x38)+0x00000008` `float/double keyframe_value` (read, DERIVED)
- `*(this+0x38)+0x0000000C` `KeyframeNode* keyframe_next` (read, DERIVED)
- `*(*(this+0x38)+0xC)+0x0000000C` `KeyframeNode* next_keyframe_next` (read, GUESS)

### RangeInterpolationCurve

Object holding a 16-entry float interpolation table at this[25..40] (byte offsets 0x64..0xA0) derived from the range minimum/maximum at this[10..11] (offsets 0x28..0x2C). PopulateRangeInterpolationTable fills the entries at hand-tuned fractions; F_1DTableLookupWithLerp reads them back with linear interpolation and a high clamp of 3.75. The 0xA0 entry doubles as the high-bound sentinel.

Methods: `0x004FD6F0`, `0x004FD7E0`

- `this+0x00000028` `float range_min` (read, DERIVED)
- `this+0x0000002C` `float range_max` (read, DERIVED)
- `this+0x00000064` `float table_entry_0` (read_write, GUESS)
- `this+0x00000068` `float table_entry_1` (read_write, GUESS)
- `this+0x0000006C` `float table_entry_2` (read_write, GUESS)
- `this+0x00000070` `float table_entry_3` (read_write, GUESS)
- `this+0x00000074` `float table_entry_4` (read_write, GUESS)
- `this+0x00000078` `float table_entry_5` (read_write, GUESS)
- `this+0x0000007C` `float table_entry_6` (read_write, GUESS)
- `this+0x00000080` `float table_entry_7` (read_write, GUESS)
- `this+0x00000084` `float table_entry_8` (read_write, GUESS)
- `this+0x00000088` `float table_entry_9` (read_write, GUESS)
- `this+0x0000008C` `float table_entry_10` (read_write, GUESS)
- `this+0x00000090` `float table_entry_11` (read_write, GUESS)
- `this+0x00000094` `float table_entry_12` (read_write, GUESS)
- `this+0x00000098` `float table_entry_13` (read_write, GUESS)
- `this+0x0000009C` `float table_entry_14` (read_write, GUESS)
- `this+0x000000A0` `float table_entry_15_high_sentinel` (read_write, GUESS)

### CarPositionCheck

Car position target check object: holds the current position at this+0x8 and the match flag at this+0x4 (2.0f on match within a 0.5 tolerance, else 0.0f). The check is gated by the multiplayer flag and scoring gate; on success it also populates the shared RangeInterpolationCurve table by calling it on this.

Methods: `0x004FE060`

- `this+0x00000004` `float match_flag` (read_write, GUESS)
- `this+0x00000008` `float current_position` (read, GUESS)

### AudioEventRingBuffer

Runtime audio-event ring buffer object. this+0x38/this+0x3C hold the ring head and current input event (event node: amplitude at +8, next at +0xC). this+0x54/0x58/0x5C/0x60 track a second linked list of audio event nodes (value at +0, next at +4, flag at +8) that is grown during processing, sorted by merge-sort and rewritten into the anchors, and torn down by DualLinkedListDestruction. 0x004FEAF0 drives a 720-slot ADSR envelope pass over this+0x24 against the base frequency at this+0x0.

Methods: `0x004FEAF0`, `0x004FD840`

- `this+0x00000000` `float base_frequency` (read, GUESS)
- `this+0x00000004` `int processing_counter` (read_write, GUESS)
- `this+0x00000024` `float slot_phase_float` (read, GUESS)
- `this+0x00000038` `EventNode* ring_head_event` (read_write, GUESS)
- `this+0x0000003C` `EventNode* input_event` (read_write, GUESS)
- `this+0x00000054` `WrapperNode* event_list_head` (read_write, DERIVED)
- `this+0x00000058` `WrapperNode* event_list_tail` (read_write, DERIVED)
- `this+0x0000005C` `WrapperNode* event_list_root` (read_write, DERIVED)
- `this+0x00000060` `int event_list_count` (read_write, DERIVED)
- `*(this+0x3C)+0x00000008` `float event_amplitude` (read, GUESS)
- `*(this+0x3C)+0x0000000C` `EventNode* event_next` (read, GUESS)
- `*(this+0x54)+0x00000000` `float node_value` (read, GUESS)
- `*(this+0x54)+0x00000004` `WrapperNode* node_next` (read_write, DERIVED)
- `*(this+0x54)+0x00000008` `byte node_flag` (read, GUESS)
- `*(this+0x58)+0x00000004` `WrapperNode* tail_next` (read, GUESS)
- `*(*(this+0x54)+0x4)+0x00000004` `WrapperNode* next_node_next` (read, GUESS)
- `*(*(*(this+0x54)+0x4)+0x4)+0x00000004` `WrapperNode* next_next_node_next` (read, GUESS)

### WeatherConditionMultipliers

Static helper set that maps a weather/severity name string to a scalar multiplier. Named conditions return fixed constants; unmatched names fall back to a numeric value resolved through sub_58850F scaled by 0.0099999998 and clamped to the unit interval. No instance state is evidenced.

Methods: `0x004FE0D0`, `0x004FE1E0`


### RenderColorUpdateState

Render-time color update object. Holds the last-applied color at this+0x40 (skip-guard), two direct node pointers at this+0x0 and this+0x10, and two pointer arrays at this+0x4C (count this+0x48) and this+0x80 (count this+0x7C). RenderColorUpdate propagates a 24-bit alpha-derived color into every packed-array entry of each collected node.

Methods: `0x004FC170`

- `this+0x00000000` `Node* first_node` (read, GUESS)
- `this+0x00000010` `Node* second_node` (read, GUESS)
- `this+0x00000040` `dword stored_color` (read_write, DERIVED)
- `this+0x00000048` `int node_array_a_count` (read, DERIVED)
- `this+0x0000004C` `Node** node_array_a` (read, DERIVED)
- `this+0x0000007C` `int node_array_b_count` (read, DERIVED)
- `this+0x00000080` `Node** node_array_b` (read, DERIVED)

### FloatColorToWordWriter

Small float container whose six consecutive floats (offsets 0x0, 0x4, 0x8, 0xC, 0x10, 0x14) are converted to 16-bit output words: the first four are scaled by 65535.0, the last two by 128.0. No packet evidence establishes the meaning of the six channels (RGBA vs intensity/extra); the channel naming is a worker guess.

Methods: `0x004FC870`

- `this+0x00000000` `float channel_0` (read, DERIVED)
- `this+0x00000004` `float channel_1` (read, DERIVED)
- `this+0x00000008` `float channel_2` (read, DERIVED)
- `this+0x0000000C` `float channel_3` (read, DERIVED)
- `this+0x00000010` `float channel_4` (read, DERIVED)
- `this+0x00000014` `float channel_5` (read, DERIVED)

### FloatDefaultsConfig

Four-float configuration object initialized to 0.0f, 20.0f, 0.3f, 0.0f at offsets 0x0/0x4/0x8/0xC by InitFourFloatDefaults, which returns the freshly initialized pointer. The meaning of the 20.0/0.3 defaults (a range/proportion pair) depends on the unknown owner.

Methods: `0x004FC9A0`

- `this+0x00000000` `float (0.0f) default_0` (write, DERIVED)
- `this+0x00000004` `float (20.0f) default_1` (write, DERIVED)
- `this+0x00000008` `float (0.3f) default_2` (write, DERIVED)
- `this+0x0000000C` `float (0.0f) default_3` (write, DERIVED)

### CloudSceneNameState

Object holding two 31-byte cloud-scene name buffers (first at this+0x50 terminated at this+0x6F, second at this+0x84 terminated at this+0xA3) and a scene type code at this+0x44. MatchAndUpdateCloudSceneNames compares and copies the packet names and triggers cloud texture setup or refreshes the type code; StringCopyWithRingBuffer reads the same two strings and encodes them into the 432-byte-stride progress-bar ring event. Shared-buffer offsets at +0x50/+0x84 are the evidence for grouping these two functions.

Methods: `0x004FC650`, `0x004FC700`

- `this+0x00000044` `dword (byte&7) scene_type_code` (read_write, GUESS)
- `this+0x0000006F` `char (NUL at end of +0x50 buffer) first_name_terminator` (write, GUESS)
- `this+0x000000A3` `char (NUL at end of +0x84 buffer) second_name_terminator` (write, GUESS)

### HUDConfigRandomSelector

Random selector that maps one LCG draw into one of three parameter buckets (20, 19, 18) using the 10922/21844 range split and forwards the bucket to HUDElementConfig with a fixed mode 2 and 1.0/1.0. No instance state evidenced; drives the HUD element config update dispatched from the element update path.

Methods: `0x004F8A70`


### SessionGlobalCacheAccessors

Module-level accessors over the 0x008AFE6x global session cache block plus coordinate-cache globals 0x005D6D60..68/0x008AFE74/78 and the guarded-field selector dword_5EC48C. Functions read/write the bound, current index and cached value, resolve objects by key, and store coordinate-search results. No instance state evidenced; grouped by shared global region and shared callees.

Methods: `0x004F9160`, `0x004F91B0`, `0x004F9230`, `0x004F9420`


### SessionStateController

Session timing/state helpers: resets the session-time global dbl_8AFEA0 together with the high-precision timer, runs table bounds checks and stores a derived value into dbl_8AFEA8; computes a session state flag (2 - sub_4F9B20, optional bit 4) that is dispatched through a call wrapper, recording a -2 outcome in byte_8AFE72. No instance state evidenced; grouped by the shared session-global region and session-lifecycle callers.

Methods: `0x004F9B30`, `0x004F9FC0`


### PiecewiseResponseCurve

Piecewise envelope response object with two scalar outputs at this+0x20 and this+0x24. Below/at a 0.60000002 threshold both outputs are zeroed; above it the response ramps field 0x20 with slope 20.000019, then ramps field 0x24 with slope 3.3333333, saturating both at the 1.0f bit pattern 1065353216. The exact segment predicate is ambiguous because the decompiled FPU-flag test is not explicit.

Methods: `0x004FDE00`

- `this+0x00000020` `float ramp_output` (read_write, DERIVED)
- `this+0x00000024` `float secondary_output` (read_write, DERIVED)

### BlendFactorReciprocalSetter

Small float helper that stores a clamped blend factor at this+0xA8 and precomputes 1.0/factor and 1.0/(1.0-factor) at this+0xAC and this+0xB0 for crossfade/interpolation use.

Methods: `0x004FEFC0`

- `this+0x000000A8` `float blend_factor` (read_write, DERIVED)
- `this+0x000000AC` `float reciprocal_factor` (write, DERIVED)
- `this+0x000000B0` `float reciprocal_complement` (write, DERIVED)

### AudioRangeClampSetter

Small float helper that writes a clamped [low, high] range into this+0xFC and this+0x100: low = 1 - a2 clamped to [0,1], high = 1 - a3 forced >= low and <= 1.0. The audio-parameter interpretation comes from existing analysis only.

Methods: `0x004FF040`

- `this+0x000000FC` `float range_low` (read_write, DERIVED)
- `this+0x00000100` `float range_high` (read_write, DERIVED)

## Compatibility contracts

- **RandomParameterThirdSplit** — One LCG draw (range not proven in the packet) is split into three parameter buckets by the thresholds 10922 and 21844: low third selects parameter 20, middle third 19, top third 18. The selected bucket is passed to HUDElementConfig(this, bucket, 2, 1.0, 1.0). A replacement must keep the threshold split and the fixed mode/float arguments.
- **WeatherWetnessMultiplierTable** — Weather name strings map to fixed wetness multipliers: Best 0.030000001, Nice 0.30000001, Clear 0.60000002, Overcast 0.64999998, Drizzle 0.73000002, Rain 0.85000002, Monsoon 0.96999997; any other name falls back to a continuous value scaled by 0.0099999998 and clamped to [0,1].
- **WeatherSeverityGripMultiplierTable** — Weather severity names map to fixed grip multipliers: base 0.0, Damp 0.25, intermediate 0.5, Soaked 0.75, Monsoon 1.0; any other name falls back to the numeric severity scaled by 0.0099999998 and clamped to [0,1].
- **RangeInterpolationTableClamp** — 1D interpolation table lookup clamps coordinates at 3.75 (returning the entry at index 40 / offset 0xA0 as the high sentinel) and scales coordinates by 4.0 to derive the table index, lerping between adjacent entries with the rounding remainder.
- **BlendFactorClampAndReciprocal** — Blend factor stored at this+0xA8 is clamped to [0.01, 1.0]; reciprocal 1.0/factor is written at this+0xAC and 1.0/(1.0-factor) at this+0xB0. A replacement must preserve the clamp bounds and the two reciprocal outputs.
- **PiecewiseResponseThresholds** — Piecewise envelope response: inputs at or below 0.60000002 zero both outputs; the 0.20 output ramps with slope 20.000019 from 0.60000002 and saturates at the 1.0f bit pattern 1065353216; the 0x24 output ramps with slope 3.3333333 from 0.69999999 and saturates at 1.0f when the input exceeds 1.0. The exact segment predicate from the FPU-flag test is ambiguous.
- **ProgressBarRingEventEncode** — Progress-bar ring events are written at a 432-byte stride behind the cursor dword_8AAE64, gated by the ring count dword_83EE60 staying below 1023, encoding two strings (this+0x50, this+0x84) and the session-time value through the encoder with the fixed arguments (2, 5, totalLength, 255, value, 1).
- **AudioEventRing720Pass** — Audio event ring processing runs a 720-slot ADSR envelope pass, advances the virtual event time by 2.0*noiseTable+2.0 while below 7200.0, clamps the slot-delta/distance ratio to at most 0.0049999999, gates event spawns on distance below 300.0 and on noise lookups against flt_7CF8CC / flt_7CF8F0, allocates 12-byte event nodes plus 12-byte wrapper nodes, and finally merge-sorts the node list (comparing the leading float) before rewriting the head/tail/root anchors.
- **FloatColorTo16BitScales** — Six float channels convert to 16-bit output words: channels 0..3 scaled by 65535.0, channels 4..5 scaled by 128.0, each truncated; the truncated channel-4 value is also the return value.
- **CloudSceneNameUpdate** — Cloud scene names update: gated by the multiplayer flag bit0 and the scoring gate (dword_8AB6E4 == 2 and packed flag on dword_8AB6EC unset); on name difference, 31 bytes of each packet name are copied into the buffers at this+0x50/this+0x84 with NUL terminators at this+0x6F/this+0xA3, followed by cloud-texture setup or a type-code store (byte(a2+3)&7) at this+0x44; the code refreshes unless the stored value is -1.
- **SessionTimingReset** — Session timing reset stores the float argument into the session-time global dbl_8AFEA0, resets the high-precision query-performance-counter timer, performs two bounds/index checks against the table at 008b8e48, and stores sub_556760(0) into dbl_8AFEA8; called by the session/collision/video restart paths.
- **KeyframeCurveStatusFallback** — Parameter curves are keyframe linked lists at this+0x38 with node layout time at +0, value at +8, next at +0xC, evaluated against session time; when no curve is configured both curve functions return the same fallback status codes: 2 when this+0x20 is 0.0, 3 when this+0x24 is 0.0, 5 when this+0x24 is >= 0.6, else 4.

## Unresolved

- All 24 packet functions carry owner trust UNKNOWN; every class in this proposal is a worker-proposed grouping (GUESS or DERIVED), never a recovered original source class.
- RangeInterpolationCurve and CarPositionCheck are grouped because CarPositionCheck calls RangeInterpolationCurve on its own this; the position fields at this+0x4/this+0x8/this+0x20 are not proven to share a struct with the interpolation table region.
- ParameterCurveRuntime groups 0x004FF130 and 0x004FF1D0 on shared this+0x38 keyframe-chain access and the identical this+0x20/this+0x24 fallback; the next-keyframe node reached via field +0xC is only partially evidenced.
- AudioEventRingBuffer groups 0x004FEAF0 and 0x004FD840 on shared linked-list anchors this+0x54..0x60 (node next at +4) and ring pointers this+0x38/0x3C (event next at +0xC); the node layouts (value at +0, flag at +8, sub-pointer at +0) are inferred from call sites and destruction behavior, not independently proven.
- CloudSceneNameState groups 0x004FC650 and 0x004FC700 on the string-buffer offsets +0x50/+0x84 evidenced via NUL terminators at +0x6F/+0xA3; the buffers themselves have no dedicated field refs.
- The exact meaning of dword_7C56A0 bit0 (multiplayer flag), the scoring gate on dword_8AB6E4/dword_8AB6EC, and the type code byte(a2+3)&7 relation to dword_7C56A4 are not established.
- Twenty-eight read-only float globals in the 0x0059Exxx/0x005ADxxx ranges are flagged by packet facts but never appear in the raw decompiled source of any function; their mapping to the float literals is unverified (see unresolved_evidence_refs).
- The FPU-flag segment test in 0x004FDE00 (v4|c3) is ambiguous; the literal 1065353216 as the 1.0f bit pattern is DERIVED interpretation, not a packet fact.
- InitFourFloatDefaults callers sub_4FCC30, sub_4FD8B0 and sub_4FE350 are known but not analyzed here; the meaning of the 20.0f/0.3f defaults depends on the unknown owner.
- sub_4FC550 as cloud-texture setup and the sort/sub-functions sub_4FDE00, sub_4FF2B0, sub_4FDEB0, sub_4FEAA0, sub_4FC910 are known only from call sites; their bodies were not part of this packet.
- The ring-buffer semantics (encode constants 2,5,255,1; ring step 432; cap 1023) and the sizes/layouts of the flt_8AAE74 / flt_8AB274 lookup tables are unknown.
- The fallback status codes 2-5 of the keyframe-curve path are unnamed; the caller PitRaceStatusMessageDispatcher may interpret them but that mapping is outside this packet.
- The object layouts behind the render color update (node fields +20/+24, linked-list fetch, packed-array entries) are not part of the packet.
- 0x008AFE64 is attributed to 0x004F9B30 and 0x004F9FC0 by packet facts but never referenced in their raw source text.
- The return value of 0x004FC650 is unassigned in the decompiled body; dbl_8AFEA0 is a double global aliased as a float load.
