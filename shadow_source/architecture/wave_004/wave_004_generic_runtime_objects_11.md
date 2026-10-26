# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

This packet groups nineteen generic runtime-object functions into seventeen conservative class proposals. Strong structural clusters: the keyframe animation object (update 0x004A2840) used by the pit-animation controller (0x004A3390/0x004A34A0/0x004A35F0) which iterates a 120-byte element array and flips widget visibility bits; three clamped parameter-tuning clusters keyed by mode selectors (DrivingModeTuning 0x004ADF10, CarPartVisibilityTargets 0x004AE490, AIDifficultyParameterSet 0x004AE9F0) that share ClampByRange/FloatClamp/ArithmeticComparison helpers and callers into TrackEnvironmentSelect; and small single-purpose helpers (one-time init, cursor hide, list walk, fixed-capacity constructor, pointer releasers, pit part/menu lookups, path formatter, setup-default copier, session-phase gate). All owners are UNKNOWN in the IR; every class trust here is DERIVED or GUESS and no CONFIRMED fact is asserted.

## Function roles

- `0x004A0D10` **SessionMenuGlobalState** — One-time global state initializer for the session-menu path: reads byte_7CE269, and on first run marks it set and stores a constant in dword_7CE26C, returning the prior flag value.
- `0x004A0DC0` **CursorVisibilityManager** — Forced-hide OS mouse cursor: sets byte_7CE260 then re-issues ShowCursor(0) until the OS display counter reports negative, returning the final count.
- `0x004A1D10` **NodeListWalker** — Singly-linked-list walker: iterates from the head at this+0x0 through the node chain calling FileSettingsScanner per node and advancing the iterator at this+0x8; returns the final node pointer.
- `0x004A1FB0` **FixedCapacityBuffer** — Constructor/initializer: zeroes six dwords at +0x0..+0x14, stores literal 24 at +0x18, returns this.
- `0x004A2840` **KeyframeAnimation** — Piecewise-linear keyframe interpolation with change detection and listener fan-out to every callback target.
- `0x004A3390` **PitAnimationController** — Pit crew animation state processor: one-shot reset of child keyframe animations, widget visibility bit flips, animation-state resource cleanup, and conditional recursive UI widget update.
- `0x004A34A0` **PitAnimationController** — Per-element conditional bit-flag dispatcher over the 120-byte element array; clear-all mode clears every element flag.
- `0x004A3560` **PitStopParameterStore** — Stores a value at this+0x4 and ORs bit 1 into the flags word at this+0x0; returns the stored value.
- `0x004A35F0` **PitAnimationController** — Computes desired float targets from a phase-descriptor parameter struct and propagates them into 120-byte sub-elements via RangeProportionInitializer.
- `0x004A47E0` **PitMenuStringTable** — Pit/garage menu string lookup: maps type id 0-4 to StopGo/Fuel/Tyres/Wing/Damage string literals with an Error fallback.
- `0x004A5820` **PitPartAccessor** — Finds the Nth valid pit part through CompoundIndexLookup, applying an optional compound filter and a busy-part/session bypass; returns the part pointer or 0.
- `0x004AA170` **TriPointerReleaser** — Conditionally frees three pointer fields (+0x14, +0x0C, +0x04) via FreeWrapper, each null-guarded; returns the last free result.
- `0x004AA1B0` **DualPointerReleaser** — Conditionally frees two pointer fields (+0x0C, +0x04) via FreeWrapper; returns the second free result or the first when the second is null.
- `0x004ADF10` **DrivingModeTuning** — Driving-mode parameter seeding and clamping: dispatches on the mode selector at +0x1CC0 (cases 0-5) and clamps per-mode defaults into parameter slots.
- `0x004AE490` **CarPartVisibilityTargets** — Updates clamped car-part visibility slider targets by mode selector at +0x1AC8 (hide/show/secondary groups) and runs the helper sequence.
- `0x004AE9F0` **AIDifficultyParameterInit** — AI/track difficulty parameter seeding: dispatches on the difficulty selector at +0x1B10 (cases 1-4) and clamps per-difficulty targets into parameter slots; nested switch on dword_5EC4AC.
- `0x004B02B0` **PathFormatterObject** — Formats a '.bch' output path from a directory field + default, with buffer size checks, extension stripping, and a -1/empty-buffer fail path.
- `0x004B0C00` **VehicleSetupDefaults** — Copies fifteen default setup parameters from the source table and clamps each into its working slot; returns constant 1. Called once from F_5StepInit.
- `0x004B17B0` **SeasonDataGate** — Session-phase-gated season-data free: frees season data at half distance when session type is 5/7, phase reaches 4, and the half-distance flag is set.

## Proposed classes

### KeyframeAnimation

Piecewise-linear keyframe interpolator: holds a segment table (5 floats per 7-float stride), tracks the last emitted input value for change detection, and fans interpolated/clamped outputs to every entry of a listener callback array.

Methods: `0x004A2840`

- `this+0x00000044` `float last_value` (read_write, DERIVED)
- `this+0x00000068` `int listener_count` (read, DERIVED)
- `this+0x0000006C` `void** listener_array` (read, DERIVED)
- `this+0x00000070` `int segment_count` (read, DERIVED)
- `this+0x00000074` `float* segment_array` (read, DERIVED)
- `*(this+0x74)+0x00000000` `float segment_input_min` (read, DERIVED)
- `*(this+0x74)+0x00000004` `float segment_input_max` (read, DERIVED)
- `*(this+0x74)+0x00000008` `float segment_inverse_range` (read, DERIVED)
- `*(this+0x74)+0x0000000C` `float segment_output_min` (read, DERIVED)
- `*(this+0x74)+0x00000010` `float segment_output_max` (read, DERIVED)

### PitAnimationController

Pit-crew animation manager: iterates a 120-byte-stride child entry array (count at +0xC, base at +0x10), resets each entry's keyframe animation, flips widget visibility bits through the BitClear/Bit12FlagSet helpers, conditionally recurses the UI widget tree, and propagates computed animation targets into sub-elements. Frame-path calls come from PitStopOperationTimer.

Methods: `0x004A3390`, `0x004A34A0`, `0x004A35F0`

- `this+0x00000000` `unsigned int executed_flags` (read_write, DERIVED)
- `this+0x0000000C` `int element_count` (read, DERIVED)
- `this+0x00000010` `void* element_array` (read, DERIVED)
- `this+0x00000014` `int widget_update_guard` (read, DERIVED)

### PitStopParameterStore

Tiny store used by the pit-stop frame path: records a caller-supplied value at +0x4 and ORs bit 1 (value 2) into the flags word at +0x0 as a dirty/change marker, returning the stored value.

Methods: `0x004A3560`

- `this+0x00000000` `unsigned int flags` (read_write, DERIVED)
- `this+0x00000004` `int stored_value` (read_write, DERIVED)

### NodeListWalker

Singly-linked-list walker over a head pointer at +0x0 with an iterator at +0x8; processes each node through the file-settings scanner callback and advances through the node next pointer until the chain ends. Invoked during player-file initialization.

Methods: `0x004A1D10`

- `this+0x00000000` `void* list_head` (read, DERIVED)
- `this+0x00000008` `void* iterator` (read_write, DERIVED)
- `this+0x00000010` `unknown listed_unused` (read, GUESS)
- `*(obj+0x0)+0x00000000` `unknown node_value_slot` (read, DERIVED)
- `*(*(obj+0x0)+0x0)+0x00000000` `unknown node_next_field_table` (read, GUESS)

### FixedCapacityBuffer

Constructor-style initializer: zeroes six consecutive dwords at +0x0..+0x14 and stores the literal 24 at +0x18 (interpreted by role as a capacity/count, meaning unproven). Returns this.

Methods: `0x004A1FB0`

- `this+0x00000000` `dword slot_0` (write, DERIVED)
- `this+0x00000004` `dword slot_1` (write, DERIVED)
- `this+0x00000008` `dword slot_2` (write, DERIVED)
- `this+0x0000000C` `dword slot_3` (write, DERIVED)
- `this+0x00000010` `dword slot_4` (write, DERIVED)
- `this+0x00000014` `dword slot_5` (write, DERIVED)
- `this+0x00000018` `int size_or_capacity` (write, GUESS)

### PitPartAccessor

Pit-part lookup helper: resolves part indices to part objects through CompoundIndexLookup, applies an optional compound-type filter, and returns the Nth accepted part, skipping busy parts unless the session-type globals allow them.

Methods: `0x004A5820`

- `this+0x00000158` `void* part_list` (read, DERIVED)
- `this+0x0000015C` `int compound_filter_index` (read, DERIVED)
- `this+0x00000168` `unknown listed_unused` (read, GUESS)

### PitMenuStringTable

Static pit/garage menu string table: maps an integer type id 0-4 to a string literal (StopGo, Fuel, Tyres, Wing, Damage) via a jump table, with an Error fallback for any other id.

Methods: `0x004A47E0`


### CursorVisibilityManager

Forced OS mouse-cursor hide: sets the global cursor-hidden flag byte_7CE260 and repeats ShowCursor(0) until the OS display counter goes negative, returning the final ShowCursor result.

Methods: `0x004A0DC0`


### SessionMenuGlobalState

One-time global state initializer for the session-menu path: on first invocation sets byte_7CE269 and stores a constant into dword_7CE26C, returning the prior flag value to the caller.

Methods: `0x004A0D10`


### DrivingModeTuning

Driving-mode parameter cluster: dispatches on a mode selector at +0x1CC0 (cases 0-5 plus default) and seeds a set of int/float parameters, each stored as a value+min+max triple and clamped via ClampByRange/FloatClamp. Modes 3-5 write slots indirectly through the ArithmeticComparison_20d0 / ClampedFloatSetter_1de0 helpers.

Methods: `0x004ADF10`

- `this+0x00001CC0` `int mode_selector` (read, DERIVED)
- `this+0x00001CE4` `float float_param` (read_write, DERIVED)
- `this+0x00001CEC` `float float_param_min` (read, DERIVED)
- `this+0x00001CF0` `float float_param_max` (read, DERIVED)
- `this+0x00001D08` `int param_1D08` (read_write, DERIVED)
- `this+0x00001D10` `int param_1D08_min` (read, DERIVED)
- `this+0x00001D14` `int param_1D08_max` (read, DERIVED)
- `this+0x00000214` `int param_A` (read_write, DERIVED)
- `this+0x0000021C` `int param_A_min` (read, DERIVED)
- `this+0x00000220` `int param_A_max` (read, DERIVED)
- `this+0x0000025C` `int param_B` (read_write, DERIVED)
- `this+0x00000264` `int param_B_min` (read, DERIVED)
- `this+0x00000268` `int param_B_max` (read, DERIVED)
- `this+0x00000280` `int param_C` (read_write, DERIVED)
- `this+0x00000288` `int param_C_min` (read, DERIVED)
- `this+0x0000028C` `int param_C_max` (read, DERIVED)
- `this+0x000002A4` `int param_D` (read_write, DERIVED)
- `this+0x000002AC` `int param_D_min` (read, DERIVED)
- `this+0x000002B0` `int param_D_max` (read, DERIVED)
- `this+0x000002C8` `int param_E` (read_write, DERIVED)
- `this+0x000002D0` `int param_E_min` (read, DERIVED)
- `this+0x000002D4` `int param_E_max` (read, DERIVED)
- `this+0x000002EC` `int param_F` (read_write, DERIVED)
- `this+0x000002F4` `int param_F_min` (read, DERIVED)
- `this+0x000002F8` `int param_F_max` (read, DERIVED)
- `this+0x00000310` `int param_G` (read_write, DERIVED)
- `this+0x00000318` `int param_G_min` (read, DERIVED)
- `this+0x0000031C` `int param_G_max` (read, DERIVED)
- `this+0x00000334` `int param_H` (read_write, DERIVED)
- `this+0x0000033C` `int param_H_min` (read, DERIVED)
- `this+0x00000340` `int param_H_max` (read, DERIVED)
- `this+0x00000358` `int param_I` (read_write, DERIVED)
- `this+0x00000360` `int param_I_min` (read, DERIVED)
- `this+0x00000364` `int param_I_max` (read, DERIVED)
- `this+0x0000040C` `int param_J` (read_write, DERIVED)
- `this+0x00000414` `int param_J_min` (read, DERIVED)
- `this+0x00000418` `int param_J_max` (read, DERIVED)

### CarPartVisibilityTargets

Car-part visibility slider targets: mode 1 (hide) and mode 2 (show) write clamped int/float targets on primary part groups; any non-zero mode additionally drives six secondary part-group targets toward 1 and runs a ShortComputation/ArithmeticComparison helper sequence. Called by sub_472930 and TrackEnvironmentSelect.

Methods: `0x004AE490`

- `this+0x00001AC8` `int mode_selector` (read, DERIVED)
- `this+0x00000B10` `int slider_target_0` (read_write, DERIVED)
- `this+0x00000B18` `int slider_target_0_min` (read, DERIVED)
- `this+0x00000B1C` `int slider_target_0_max` (read, DERIVED)
- `this+0x00000B34` `int slider_target_1` (read_write, DERIVED)
- `this+0x00000B3C` `int slider_target_1_min` (read, DERIVED)
- `this+0x00000B40` `int slider_target_1_max` (read, DERIVED)
- `this+0x00000B58` `int slider_target_2` (read_write, DERIVED)
- `this+0x00000B60` `int slider_target_2_min` (read, DERIVED)
- `this+0x00000B64` `int slider_target_2_max` (read, DERIVED)
- `this+0x00001C30` `int slider_target_3` (read_write, DERIVED)
- `this+0x00001C38` `int slider_target_3_min` (read, DERIVED)
- `this+0x00001C3C` `int slider_target_3_max` (read, DERIVED)
- `this+0x00002348` `float float_slider_target_0` (read_write, DERIVED)
- `this+0x00002350` `float float_slider_target_0_min` (read, DERIVED)
- `this+0x00002354` `float float_slider_target_0_max` (read, DERIVED)
- `this+0x0000236C` `float float_slider_target_1` (read_write, DERIVED)
- `this+0x00002374` `float float_slider_target_1_min` (read, DERIVED)
- `this+0x00002378` `float float_slider_target_1_max` (read, DERIVED)
- `this+0x000026F0` `int secondary_target_0` (read_write, DERIVED)
- `this+0x000026F8` `int secondary_target_0_min` (read, DERIVED)
- `this+0x000026FC` `int secondary_target_0_max` (read, DERIVED)
- `this+0x00002714` `int secondary_target_1` (read_write, DERIVED)
- `this+0x0000271C` `int secondary_target_1_min` (read, DERIVED)
- `this+0x00002720` `int secondary_target_1_max` (read, DERIVED)
- `this+0x00002738` `int secondary_target_2` (read_write, DERIVED)
- `this+0x00002740` `int secondary_target_2_min` (read, DERIVED)
- `this+0x00002744` `int secondary_target_2_max` (read, DERIVED)
- `this+0x000027EC` `int secondary_target_3` (read_write, DERIVED)
- `this+0x000027F4` `int secondary_target_3_min` (read, DERIVED)
- `this+0x000027F8` `int secondary_target_3_max` (read, DERIVED)
- `this+0x00002810` `int secondary_target_4` (read_write, DERIVED)
- `this+0x00002818` `int secondary_target_4_min` (read, DERIVED)
- `this+0x0000281C` `int secondary_target_4_max` (read, DERIVED)
- `this+0x00002834` `int secondary_target_5` (read_write, DERIVED)
- `this+0x0000283C` `int secondary_target_5_min` (read, DERIVED)
- `this+0x00002840` `int secondary_target_5_max` (read, DERIVED)

### AIDifficultyParameterSet

AI/track difficulty parameter cluster: dispatches on a difficulty selector at +0x1B10 (cases 1-4 plus default) and seeds clamped parameter slots (value+min+max triples), conditionally writing a bounded slot when the flag byte at +0x1818 is set; modes 3/4 and the post-switch common sequence route through ArithmeticComparison_20d0 / ClampedFloatSetter_1de0, and a nested switch on global dword_5EC4AC dispatches a final helper call.

Methods: `0x004AE9F0`

- `this+0x00001B10` `int difficulty_selector` (read, DERIVED)
- `this+0x00001818` `byte conditional_flag_byte` (read, DERIVED)
- `this+0x000011E8` `int param_0` (read_write, DERIVED)
- `this+0x000011F0` `int param_0_min` (read, DERIVED)
- `this+0x000011F4` `int param_0_max` (read, DERIVED)
- `this+0x00001254` `int param_1` (read_write, DERIVED)
- `this+0x0000125C` `int param_1_min` (read, DERIVED)
- `this+0x00001260` `int param_1_max` (read, DERIVED)
- `this+0x0000135C` `int param_2` (read_write, DERIVED)
- `this+0x00001364` `int param_2_min` (read, DERIVED)
- `this+0x00001368` `int param_2_max` (read, DERIVED)
- `this+0x00001380` `int param_3` (read_write, DERIVED)
- `this+0x00001388` `int param_3_min` (read, DERIVED)
- `this+0x0000138C` `int param_3_max` (read, DERIVED)
- `this+0x000013A4` `float param_4` (read_write, DERIVED)
- `this+0x000013AC` `float param_4_min` (read, DERIVED)
- `this+0x000013B0` `float param_4_max` (read, DERIVED)
- `this+0x000013C8` `int param_5` (read_write, DERIVED)
- `this+0x000013D0` `int param_5_min` (read, DERIVED)
- `this+0x000013D4` `int param_5_max` (read, DERIVED)
- `this+0x000013EC` `int param_6` (read_write, DERIVED)
- `this+0x000013F4` `int param_6_min` (read, DERIVED)
- `this+0x000013F8` `int param_6_max` (read, DERIVED)
- `this+0x00001410` `int param_7` (read_write, DERIVED)
- `this+0x00001418` `int param_7_min` (read, DERIVED)
- `this+0x0000141C` `int param_7_max` (read, DERIVED)
- `this+0x000016F8` `int param_8` (read_write, DERIVED)
- `this+0x00001700` `int param_8_min` (read, DERIVED)
- `this+0x00001704` `int param_8_max` (read, DERIVED)
- `this+0x00001740` `int param_9` (read_write, DERIVED)
- `this+0x00001748` `int param_9_min` (read, DERIVED)
- `this+0x0000174C` `int param_9_max` (read, DERIVED)
- `this+0x000017AC` `int param_10` (read_write, DERIVED)
- `this+0x000017B4` `int param_10_min` (read, DERIVED)
- `this+0x000017B8` `int param_10_max` (read, DERIVED)
- `this+0x000017D0` `int param_11` (read_write, DERIVED)
- `this+0x000017D8` `int param_11_min` (read, DERIVED)
- `this+0x000017DC` `int param_11_max` (read, DERIVED)
- `this+0x000017F4` `int param_12` (read_write, DERIVED)
- `this+0x000017FC` `int param_12_min` (read, DERIVED)
- `this+0x00001800` `int param_12_max` (read, DERIVED)
- `this+0x00001878` `int param_13` (read_write, DERIVED)
- `this+0x00001880` `int param_13_min` (read, DERIVED)
- `this+0x00001884` `int param_13_max` (read, DERIVED)
- `this+0x0000189C` `int param_14` (read_write, DERIVED)
- `this+0x000018A4` `int param_14_min` (read, DERIVED)
- `this+0x000018A8` `int param_14_max` (read, DERIVED)
- `this+0x000018C0` `int param_15` (read_write, DERIVED)
- `this+0x000018C8` `int param_15_min` (read, DERIVED)
- `this+0x000018CC` `int param_15_max` (read, DERIVED)
- `this+0x000018E4` `int param_16` (read_write, DERIVED)
- `this+0x000018EC` `int param_16_min` (read, DERIVED)
- `this+0x000018F0` `int param_16_max` (read, DERIVED)
- `this+0x00001908` `int param_17` (read_write, DERIVED)
- `this+0x00001910` `int param_17_min` (read, DERIVED)
- `this+0x00001914` `int param_17_max` (read, DERIVED)
- `this+0x00001950` `int param_18` (read_write, DERIVED)
- `this+0x00001958` `int param_18_min` (read, DERIVED)
- `this+0x0000195C` `int param_18_max` (read, DERIVED)
- `this+0x00002DB8` `int param_19` (read_write, DERIVED)
- `this+0x00002DC0` `int param_19_min` (read, DERIVED)
- `this+0x00002DC4` `int param_19_max` (read, DERIVED)

### PathFormatterObject

Output-path formatter: builds a '.bch' file path from a directory field at +0x1F9C (or a default string), truncating to a buffer limit, stripping an existing extension, and appending the suffix; returns 0 on success and -1 on failure, emptying the buffer on the fail path.

Methods: `0x004B02B0`

- `this+0x00001F9C` `char* directory_path` (read, DERIVED)

### VehicleSetupDefaults

Vehicle setup default applier: copies fifteen default setup parameter values from a source table region (+0x496C..+0x49A4) into working slots and clamps each against its stored min/max bounds (via ClampByRange, FloatClamp, or ByteClamp, with the final three clamped inline). Returns constant 1. Invoked once from F_5StepInit.

Methods: `0x004B0C00`

- `this+0x0000496C` `int src_default_0` (read, DERIVED)
- `this+0x00004970` `int src_default_1` (read, DERIVED)
- `this+0x00004974` `int src_default_2` (read, DERIVED)
- `this+0x00004978` `int src_default_3` (read, DERIVED)
- `this+0x0000497C` `int src_default_4` (read, DERIVED)
- `this+0x00004980` `int src_default_5` (read, DERIVED)
- `this+0x00004984` `byte src_default_6` (read, DERIVED)
- `this+0x00004988` `int src_default_7` (read, DERIVED)
- `this+0x0000498C` `int src_default_8` (read, DERIVED)
- `this+0x00004990` `int src_default_9` (read, DERIVED)
- `this+0x00004994` `float src_default_10` (read, DERIVED)
- `this+0x00004998` `int src_default_11` (read, DERIVED)
- `this+0x0000499C` `int src_default_12` (read, DERIVED)
- `this+0x000049A0` `int src_default_13` (read, DERIVED)
- `this+0x000049A4` `int src_default_14` (read, DERIVED)
- `this+0x00000654` `int setup_param_0` (read_write, DERIVED)
- `this+0x0000065C` `int setup_param_0_min` (read, DERIVED)
- `this+0x00000660` `int setup_param_0_max` (read, DERIVED)
- `this+0x00000888` `int setup_param_1` (read_write, DERIVED)
- `this+0x00000890` `int setup_param_1_min` (read, DERIVED)
- `this+0x00000894` `int setup_param_1_max` (read, DERIVED)
- `this+0x00000984` `int setup_param_2` (read_write, DERIVED)
- `this+0x0000098C` `int setup_param_2_min` (read, DERIVED)
- `this+0x00000990` `int setup_param_2_max` (read, DERIVED)
- `this+0x00000A80` `int setup_param_3` (read_write, DERIVED)
- `this+0x00000A88` `int setup_param_3_min` (read, DERIVED)
- `this+0x00000A8C` `int setup_param_3_max` (read, DERIVED)
- `this+0x00000B7C` `int setup_param_4` (read_write, DERIVED)
- `this+0x00000B84` `int setup_param_4_min` (read, DERIVED)
- `this+0x00000B88` `int setup_param_4_max` (read, DERIVED)
- `this+0x00000C78` `int setup_param_5` (read_write, DERIVED)
- `this+0x00000C80` `int setup_param_5_min` (read, DERIVED)
- `this+0x00000C84` `int setup_param_5_max` (read, DERIVED)
- `this+0x00000D44` `byte setup_param_6` (read_write, DERIVED)
- `this+0x00000D46` `byte setup_param_6_min` (read, DERIVED)
- `this+0x00000D47` `byte setup_param_6_max` (read, DERIVED)
- `this+0x0000209C` `int setup_param_7` (read_write, DERIVED)
- `this+0x000020A4` `int setup_param_7_min` (read, DERIVED)
- `this+0x000020A8` `int setup_param_7_max` (read, DERIVED)
- `this+0x00002198` `int setup_param_8` (read_write, DERIVED)
- `this+0x000021A0` `int setup_param_8_min` (read, DERIVED)
- `this+0x000021A4` `int setup_param_8_max` (read, DERIVED)
- `this+0x00002294` `int setup_param_9` (read_write, DERIVED)
- `this+0x0000229C` `int setup_param_9_min` (read, DERIVED)
- `this+0x000022A0` `int setup_param_9_max` (read, DERIVED)
- `this+0x00002390` `float setup_param_10` (read_write, DERIVED)
- `this+0x00002398` `float setup_param_10_min` (read, DERIVED)
- `this+0x0000239C` `float setup_param_10_max` (read, DERIVED)
- `this+0x00002588` `int setup_param_11` (read_write, DERIVED)
- `this+0x00002590` `int setup_param_11_min` (read, DERIVED)
- `this+0x00002594` `int setup_param_11_max` (read, DERIVED)
- `this+0x0000275C` `int setup_param_12` (read_write, DERIVED)
- `this+0x00002764` `int setup_param_12_min` (read, DERIVED)
- `this+0x00002768` `int setup_param_12_max` (read, DERIVED)
- `this+0x00002858` `int setup_param_13` (read_write, DERIVED)
- `this+0x00002860` `int setup_param_13_min` (read, DERIVED)
- `this+0x00002864` `int setup_param_13_max` (read, DERIVED)
- `this+0x0000248C` `int setup_param_14` (read_write, DERIVED)
- `this+0x00002494` `int setup_param_14_min` (read, DERIVED)
- `this+0x00002498` `int setup_param_14_max` (read, DERIVED)

### SeasonDataGate

Session-phase-gated season-data free: when the global session type is 5 or 7 and the phase field at +0x1F78 transitions through 4 with the half-distance flag set, calls ConditionalSeasonDataFree(1); otherwise returns an accumulated phase/flag value.

Methods: `0x004B17B0`

- `this+0x00001F78` `int session_phase` (read, DERIVED)

### TriPointerReleaser

Conditionally frees three pointer fields (+0x14, +0x0C, +0x04) through FreeWrapper, each independently null-guarded, returning the last free result. Part of a static-init bulk teardown path.

Methods: `0x004AA170`

- `this+0x00000014` `void* pointer_third` (read, DERIVED)
- `this+0x0000000C` `void* pointer_second` (read, DERIVED)
- `this+0x00000004` `void* pointer_first` (read, DERIVED)

### DualPointerReleaser

Conditionally frees two pointer fields (+0x0C, +0x04) through FreeWrapper, each null-guarded, returning the last free result. Structural twin of DualConditionalFree (0x0049A5A0) per cluster prelabel; called by StaticInitBulk.

Methods: `0x004AA1B0`

- `this+0x0000000C` `void* pointer_first` (read, DERIVED)
- `this+0x00000004` `void* pointer_second` (read, DERIVED)

## Compatibility contracts

- **ShowCursorForcedHideLoop** — ForceHideMouseCursor re-issues ShowCursor(0) until the OS cursor display counter returns negative, preserving the standard forced-hide idiom; a replacement must reproduce the same OS cursor-counter driving contract and keep the byte_7CE260 hidden flag consistent.
- **OneTimeSessionMenuStateFlag** — byte_7CE269 transitions 0 to 1 on the first session-menu initialization; dword_7CE26C receives the constant 1084227584 on that first run; the initializer returns the prior flag value to SessionMenuModeSwitch.
- **KeyframeSegmentLayout** — Each keyframe segment occupies 7 consecutive floats (input-min, input-max, inverse-range, output-min, output-max); the segment array base is this+0x74 with count at this+0x70, and the listener array base is this+0x6C with count at this+0x68.
- **PitAnimationElementArray** — The pit animation controller iterates an element array at this+0x10 with count at this+0xC and a fixed 120-byte stride; each element carries an active-state byte, a widget pointer (near element+100), and per-entry flags. The exact per-element offsets are grounded only in raw source.
- **ClampedParameterSlotTriples** — Tuning clusters (DrivingModeTuning, CarPartVisibilityTargets, AIDifficultyParameterSet) store each parameter as a value/min/max triple (min at +0x8, max at +0xC of the value slot) and clamp every write through ClampByRange (int) or FloatClamp (float) helpers; modes 3-5 additionally route through ArithmeticComparison_20d0 / ClampedFloatSetter_1de0.
- **SessionPhaseSeasonDataFree** — Season data is freed at half distance only when the global session type is 5 or 7, the phase field at this+0x1F78 reaches 4, and the half-distance flag byte_8ACFA0 is set; the free runs as ConditionalSeasonDataFree(1) and its result is returned.
- **BchPathFormat** — Output '.bch' path = directory field this+0x1F9C (falling back to default string byte_5EA438) plus the input base with any existing extension stripped; failure (NULL/zero-size/too-small buffer) empties the buffer and returns -1, success returns 0.

## Unresolved

- The 120-byte pit element layout (offsets entry+2, +3, +72, +100, +112, +116 and the 28-byte sub-element stride) exists only in the raw source; no allowed field evidence refs cover those bases, so they are deliberately not promoted to class fields and stay GUESS-by-role.
- LinkedListWalker node next pointer is read at node+0x4 in the raw body while the field table labels node+0x0 as the next-node pointer; only the +0x4 access appears in the raw body (packet-noted inconsistency).
- All function owners are UNKNOWN in the source IR; the proposed classes are DERIVED or GUESS groupings, not claims about original source organization. In particular DrivingModeTuning, CarPartVisibilityTargets and AIDifficultyParameterSet likely belong to a common large track-environment object (shared callers TrackEnvironmentSelect / sub_472630 / sub_472930), but common ownership is not proven by this packet.
- Semantics of the literal constants are unknown: 1084227584 stored at dword_7CE26C, 1203982208 and 99999.0f sentinels in AnimationTargetPropagator, the 0.25/0.5 float patterns, and the fixed argument sequences passed to ArithmeticComparison_20d0 / ClampedFloatSetter_1de0.
- DrivingModeTuning modes 3-5 and AIDifficultyParameterSet modes 3/4 write slots indirectly through ArithmeticComparison_20d0/ClampedFloatSetter_1de0 (index/literal based, no this-field visible), so per-slot targets for those modes cannot be enumerated from this packet.
- The relationship between the literal 99999.0 and the read-only global flt_59E928 compared by PerElementConditionalActionDispatcher is not established.
- TriPointerReleaser and DualPointerReleaser free pointer fields at equal offsets (+0x04, +0x0C) but on separate `this` objects; whether they are one object family or two is unproven, so equal offsets are not merged across classes per the evidence rules.
- The meaning of the bit-1 dirty flag on PitStopParameterStore, the reader of byte_7CE260, and the phase values 3 vs 4 in SeasonDataGate session_phase are not established from this packet.
- The legacy ABI label 'HotlapRecordingCheck' (abi:lead) attached to 0x004B17B0 is inconsistent with the raw source, which frees season data at half distance; the SeasonDataGate naming follows the analysis fill at DERIVED trust.
