# UiPlatformAndOptions

Scope: `ui_platform_and_options`  
Trust: `DERIVED`

The ui_platform_and_options packet spans 26 functions. The dominant cluster is the UI platform: vtable-installed UI object constructors and init helpers (UiObject base on off_59F140, UiObjectInit, UiSlider, per-type UiComponent inits, UiDatabaseObject, CircuitInfoPage, UiObjectWithFloatParam, UiLoadingPercentDisplay), a slider/list destructor (UiSliderList), widget state-change handlers (UiStateChangeHandler), and UI config-entry serialization plus layout initialization. Path-asset builders cover the driver asset file candidates (pws/tv x Fb/Fe/Sb/Se) and the commentary TB/TE path lookup, plus the profile-icon BMP path and the track-path display updater. Adjacent functions cover a driver-collision network broadcast triggered from a UI selection and the force-feedback output packet packing. Ownership is UNKNOWN for every packet function; every class proposed here is DERIVED or GUESS. No clean multi-state machine is evidenced in this packet.

## Function roles

- `0x00414600` **DriverAssetPathBuilder** — Builds candidate driver asset file paths for two name variants (pws and tv) across four suffixes (Fb, Fe, Sb, Se) via StringFormatWithBufferOverflowCheck, verifies each candidate with FilePathExtensionCheck against the per-variant/suffix string buffers, registers existing files via DriverNameIDLookup with this[2] as id, and returns 1 only when flag a2 is non-zero, no check failed, and TextFormatStructInitializer reset the format struct.
- `0x00414A90` **CommentaryAssetPathBuilder** — Builds and validates commentary file paths in pws and tv subdirectories: resolves the driver-name string from *this and the season globals (dword_5EC3D8/dword_5EC428 with byte_5EA438 fallback), formats a directory prefix, appends TB/TE tokens and the extension strings, checks each candidate via FilePathExtensionCheck against the this+3/+8/+13/+18 (pws) and this+23/+28/+33/+38 (tv) slots, and dispatches matching slots to the commentary lookups. Returns 0 unconditionally.
- `0x00466090` **UiObject** — Base UI object constructor: calls UIStructInit (0x0048E600) to initialize the shared UI sub-object, assigns the vtable pointer off_59F140, and presets the float/default fields at dword indices 60..73 (byte offsets +0xF0..+0x124) with defaults 5.0, 10.0, 1.0 and -1.0; returns this. Invoked by ShortComputation_8090 (0x00468090).
- `0x0046DD10` **UiObjectInit** — __thiscall constructor: calls ConstructorWithByteParams(this, 0, 0) to zero-initialize the object, installs the vtable off_59FD68 at offset 0x0, explicitly zeroes the dword field at offset 0xE4, and returns this. Legacy abi label is UI_Object_Init.
- `0x0046E1B0` **DriverCollisionBroadcastFromUi** — Multiplayer driver-selection collision handler: obtains UI element ID 31 through a virtual call on the object at this[16] (vtable+0x1C), guards on a trigger/state field at offset 376, reads its selected text via UIScreenTextAccessor_9950, converts it to a driver identifier with sub_587ECE, copies driver data from the session manager (dword_7CD25C) by ID, and on success broadcasts a collision event over the network. Always returns 0.
- `0x00473330` **UiElementWithLabelList** — UI-element constructor/initializer: runs the shared base initializer ShortComputation_6d60(this, 1), sets the vtable to off_5A2700 at this[0], stores a pointer to the global enable flag dword_7CF788 at this[199] (0x31C), writes literal flag fields at this[201..204] (1/0/1/1) and value 269 at this[205] (0x334), and registers two text-handle nodes (off_5BE704, aOn) into the linked list.
- `0x004733A0` **UiElementWithLabelList** — UI-element constructor/initializer: runs the shared base initializer ShortComputation_6d60(this, 1), sets the vtable to off_5A27C0 at this[0], stores a pointer to the global reference dword_7D02E4 at this[199] (0x31C), writes literal flag fields at this[201..204] (3/0/3/3) and value 270 at this[205] (0x334), and registers four text-handle nodes (off_5BE704 followed by three aOn copies) into the linked list.
- `0x004760D0` **UiDatabaseObject** — Constructor for a UI database object: calls the base UI object constructor UIObjectConstructor_fc50 (0x0048FC50), zeroes six fields at this+0x3C through this+0x50, sets this+0x54 to the sentinel value -1, assigns the vtable off_5A4464, and returns this.
- `0x00477F30` **ProfileIconPathBuilder** — Builds an absolute file path for the ProfileIcon.bmp asset: invokes the virtual method at vtable offset 60 (field obj+0x3C) with argument 0, fills a 128-byte stack buffer with the base directory via PathTruncationUtility, appends the 16-byte literal copied as four dword chunks, and stores the combined path via StringCopyWithBufferRealloc. Returns 0.
- `0x00478ED0` **TrackPathUiDisplay** — Updates the track-path display in the UI: resolves the stored path at this[87] (falling back to byte_5EA438), compares it with the current track path dword_7CE5D0 via sub_588410, and when null/empty/mismatched pushes the current path through the vtable +176 callback; when session mode dword_7C569C and dword_7D0410 both equal 5 (championship server) and this[84] is set, invokes the vtable +60 callback and raises byte_7CFF48. Ends with HitTest and returns 0.
- `0x00479690` **UiSlider** — UI slider component constructor: calls VTableSetInit(this, 0, 1061997773) to initialize the base UI component with default float 0.8, then installs the slider vtable pointer off_5A4B90 at this+0x0, overriding the base vtable. Returns this.
- `0x00479730` **UiComponentRangeInit** — UI component constructor: calls VtableSetWithInitCall(this, 0, 1045220557), then overwrites the vtable pointer with off_5A4DB8 and returns this.
- `0x00479BD0` **UiComponentRangeInit** — Straight-line __thiscall object constructor: calls VtableSetWithInitCall(this, 0, 1048576000), installs the vtable pointer off_5A59F0 into this[0] and returns this. No guards or branches.
- `0x00479C80` **UiComponentVTableSetInit** — Object constructor: calls InitVTableSet(this, 0, 1065353216), sets the vtable pointer at offset 0x0 to off_5A5C18, and returns this. Skeleton prose interprets the literals as a [0.0, 1.0] float range.
- `0x0047A620` **UiComponentVTableSetInit** — UI component object initializer (thiscall, no arguments): calls InitVTableSet (0x004668E0) with the integer literals 1028443341 and 1065353216, then overrides the vtable pointer at this+0x0 with off_5A64B8. Returns this.
- `0x0047BE00` **UiCursorScrollPosition** — Computes and clamps the scroll position of a cursor-based UI component: reads the total cursor item count via MenuCursorCount_bc90 and the scroll range at this+0x114; writes this+0xEC as ((count-1) * step + range/2) / range or 0 when the range is zero, clamping into [0, count-1]; when count-1 is below the range an auxiliary utility at 0x0047BD90 is invoked instead. Called by UIComponentScrollUpdate (0x0047B1E0) and sub_47BB40 (0x0047BB40).
- `0x0047C7C0` **UiObjectWithFloatParam** — UI-object constructor: delegates to UIConstructorWithVTableParams with this, integer 0, and constant 1065353216, stores the caller parameter a2 at offset 0xFC, and sets the vtable pointer at offset 0x0 to off_5A69B0. Returns this.
- `0x0047C860` **UiLoadingPercentDisplay** — Reads a loading-progress float via a vtable dispatch at offset 0xB4, converts it to a '%d%%' string in a stack buffer, and conditionally dispatches loading events based on the mode value at field 0xFC (230 = threshold-gated dispatch via ThresholdGatedVirtualDispatch with flt_5EA618, 232 = global dispatch via GlobalDispatchWithGuard). The formatted buffer is copied through StringCopyWithBufferRealloc. Returns 0.
- `0x0047E440` **CircuitInfoPage** — Constructor for a circuit-info page object: runs base-class initialization sub_4893C0, installs the vtable off_5A6BC8 at this+0, then inserts six category label strings (circuit name, location, first grand prix, circuit length, lap record, race laps 100%) into a linked list via LinkedListInsertWithNodeAllocation with tag -1. Returns this.
- `0x0047FB10` **UiSliderList** — Destructor for a UI slider/list manager: installs vtable off_5A7168, tears down the sub-object at this+96 via sub_4C5DE0, reinstalls vtable off_5A4550, walks the singly linked list from this[60] conditionally destroying each node's embedded object (vtable entry 0 with argument 1 when the node flag byte is non-zero and the data pointer is non-null), frees every node through FreeWrapper_7bcf, clears the four list state fields this[60..63], chains to the base destructor sub_485EB0, and frees the object itself when the delete flag a2 bit 0 is set.
- `0x00487460` **UiStateChangeHandler** — UI radio/check-button state change handler: when the enable flag at this+224 (0xE0) is set, snapshots the computed state via ShortComputation_7720, normalizes the first string field (this+160) through StringNormalizeLookup_a460, compares the normalized value against the second string field (this+168) via sub_588410, and records the comparison result into the validation state via sub_487260. If the recomputed state differs from the snapshot, dispatches a virtual notification through the vtable entry +44 with argument 1.
- `0x00487960` **UiStateChangeHandler** — UI-control state-change handler gated by the enable byte at this+0xE0: snapshots the state via ShortComputation_7720, normalizes a lookup string (this+0xA0, byte_5EA438 fallback) through StringNormalizeLookup_a460 using a context base 5772 bytes into the object at this+0x40, and on success compares it against a second string (this+0xA8) via sub_588410, dispatching StateDependentVTableDispatch_7760 with the comparison result. If a second snapshot differs, fires the virtual notification at vtable offset +44 with argument 1. Always returns 0. Invoked by InitDispatchWithVTableCheck (0x004879E0) and sub_487D50 (0x00487D50).
- `0x004B1FC0` **UiConfigEntryWriter** — Serializes one UI config entry into an output buffer a2: concatenates the value at this+0x14 (16-bit/wide-string source) into a 256-byte stack scratch buffer via AlignedStringConcat, writes the key prefix literal aSS_6, conditionally writes the key name from this+0xC (byte_5EA438 fallback) via aS_8, and terminates the entry with word_5C30B4. Returns constant 0.
- `0x004DB090` **UiClassDisposer** — Object lifecycle routine that installs the interface/vtable pointer off_5AD06C into the first DWORD of the object, then when parameter a2 bit 0 is set frees the object itself via FreeWrapper_7bcf. Returns this unchanged. Existing analysis names the object an audio filter, but that label is not independently confirmed.
- `0x004DB520` **UiLayoutInitializer** — Unconditional UI initialization sequence on a __thiscall object: invokes the virtual method at vtable+28 with argument 0, the virtual method at vtable+32 with argument 1000, then UILayoutDispatchWithDataPrep(640). Returns 0.
- `0x004E2760` **ForceFeedbackController** — Builds a force-feedback output packet at this+0x938: iterates 4 wheel blocks (stride 296 from this+0x108) clamping each wheel type, scaling wheel force/intensity by 7.0 and the force at this+0x1E8 by 15.0, and packing results into a dword at +0x938 and a word at +0x93C; packs steering/vibration bytes from this+0xC0/+0xAC/+0x98 scaled by 7.0/7.0/3.0 into +0x93E. When the FFB enable flag at +0x98C is set, iterates 17 channels from +0x9A8 setting bitmask +0x940, packing two 4-bit intensities into +0x93F, and clamping three force components to +/-511.98001 scaled by 64.0 (saturating to +/-32767) into words +0x944/+0x946/+0x948; otherwise zeroes those fields. Returns this+0x938.

## Proposed classes

### DriverAssetPathBuilder

Builds candidate driver asset file paths across two name variants (pws, tv) and four suffixes (Fb, Fe, Sb, Se) from a base directory and driver name, verifies each candidate with FilePathExtensionCheck, and registers existing files via DriverNameIDLookup.

Methods: `0x00414600`

- `this+0x00000000` `pointer to driver name string (byte_5EA438 fallback) driver_name_ptr` (read, DERIVED)
- `this+0x00000008` `u32 id passed to DriverNameIDLookup driver_id` (read, DERIVED)

### CommentaryAssetPathBuilder

Builds and validates commentary file paths in pws and tv subdirectories from a driver name and season globals, appending TB/TE tokens and extension strings, and dispatching matching slots to the commentary lookups.

Methods: `0x00414A90`

- `this+0x00000000` `pointer to driver name string (byte_5EA438 fallback) driver_name_ptr` (read, DERIVED)
- `this+0x00000008` `u32 index argument to the commentary lookups driver_id` (read, DERIVED)

### UiObject

Base UI object constructor: initializes the shared UI sub-object via UIStructInit, installs the vtable at off_59F140, and presets the float/default fields in the +0xF0..+0x124 range with 5.0/10.0/1.0/-1.0 defaults. The off_59F140 vtable is the same one assigned by the UIObject destructor in the wave_005 packet.

Methods: `0x00466090`

- `this+0x00000000` `pointer to off_59F140 vtable vtable_ptr` (write, DERIVED)
- `this+0x000000F0` `u32 zeroed state_field_0xF0` (write, GUESS)
- `this+0x000000F4` `byte zeroed flag_byte_0xF4` (write, GUESS)
- `this+0x000000F5` `byte zeroed flag_byte_0xF5` (write, GUESS)
- `this+0x000000F8` `float default 5.0f default_float_5_0` (write, DERIVED)
- `this+0x000000FC` `float default 10.0f default_float_10_0` (write, DERIVED)
- `this+0x00000100` `float default 5.0f default_float_5_0_b` (write, DERIVED)
- `this+0x00000104` `u32 zeroed state_field_0x104` (write, GUESS)
- `this+0x00000108` `u32 zeroed state_field_0x108` (write, GUESS)
- `this+0x0000010C` `u32 zeroed state_field_0x10C` (write, GUESS)
- `this+0x00000110` `float default 1.0f default_float_1_0` (write, DERIVED)
- `this+0x00000114` `u32 zeroed state_field_0x114` (write, GUESS)
- `this+0x00000118` `float default -1.0f default_float_neg1_0` (write, DERIVED)
- `this+0x0000011C` `u32 zeroed state_field_0x11C` (write, GUESS)
- `this+0x00000120` `u32 zeroed state_field_0x120` (write, GUESS)
- `this+0x00000124` `float default -1.0f default_float_neg1_0_b` (write, DERIVED)

### UiObjectInit

Zero-initialized UI object constructor: delegates to ConstructorWithByteParams, installs the off_59FD68 vtable, and explicitly zeroes the dword at +0xE4.

Methods: `0x0046DD10`

- `this+0x00000000` `pointer to off_59FD68 vtable vtable_ptr` (write, DERIVED)
- `this+0x000000E4` `u32 zeroed zeroed_field_0xE4` (write, GUESS)

### DriverCollisionBroadcastFromUi

Multiplayer driver-selection collision handler: reads the selected driver text from UI element ID 31, resolves a driver identifier, copies driver data from the session manager by ID, and broadcasts a collision event over the network.

Methods: `0x0046E1B0`

- `this+0x00000000` `pointer to object vtable vtable_ptr` (read, DERIVED)
- `this+0x00000040` `pointer to the UI screen object providing element ID 31 ui_screen_object_ptr` (read, DERIVED)
- `*(this+0x40)+0x0000001C` `vtable slot +0x1C (get/create UI element by id) get_ui_element_vtable_slot` (read, DERIVED)

### UiElementWithLabelList

UI element constructed by the shared ShortComputation_6d60 base initializer, storing a reference (global enable flag or global reference) at +0x31C, literal flag fields at +0x324..+0x330, a literal at +0x334, and one or more text-handle nodes inserted into a linked list. The two variants differ in vtable, reference global, and label-node count.

Methods: `0x00473330`, `0x004733A0`

- `this+0x00000000` `pointer to per-variant vtable (off_5A2700 / off_5A27C0) vtable_ptr` (write, DERIVED)
- `this+0x0000031C` `pointer to global enable flag (0x7CF788) or global reference (0x7D02E4) reference_ptr` (write, DERIVED)
- `this+0x00000324` `u32 literal (1 or 3) literal_a` (write, DERIVED)
- `this+0x00000328` `u32 literal 0 literal_b` (write, DERIVED)
- `this+0x0000032C` `u32 literal (1 or 3) literal_c` (write, DERIVED)
- `this+0x00000330` `u32 literal (1 or 3) literal_d` (write, DERIVED)
- `this+0x00000334` `u32 literal (269 or 270) literal_e` (write, DERIVED)

### UiDatabaseObject

UI database object constructor: delegates to the base UI object constructor UIObjectConstructor_fc50, zeroes six fields in +0x3C..+0x50, sets the -1 sentinel at +0x54, and installs the off_5A4464 vtable.

Methods: `0x004760D0`

- `this+0x00000000` `pointer to off_5A4464 vtable vtable_ptr` (write, DERIVED)
- `this+0x0000003C` `u32 zeroed cleared_field_0x3C` (write, GUESS)
- `this+0x00000040` `u32 zeroed cleared_field_0x40` (write, GUESS)
- `this+0x00000044` `u32 zeroed cleared_field_0x44` (write, GUESS)
- `this+0x00000048` `u32 zeroed cleared_field_0x48` (write, GUESS)
- `this+0x0000004C` `u32 zeroed cleared_field_0x4C` (write, GUESS)
- `this+0x00000050` `u32 zeroed cleared_field_0x50` (write, GUESS)
- `this+0x00000054` `u32 sentinel -1 (unset record marker) unset_record_sentinel` (write, DERIVED)

### ProfileIconPathBuilder

Builds the absolute ProfileIcon.bmp path by invoking a vtable+60 base-path provider, filling a stack buffer with the base directory, appending the 16-byte literal, and storing the combined path.

Methods: `0x00477F30`

- `this+0x00000000` `pointer to object vtable vtable_ptr` (read, DERIVED)
- `obj+0x0000003C` `vtable slot +60 (base directory/path provider) base_path_provider_slot` (read, GUESS)

### TrackPathUiDisplay

Updates the UI track-path display: compares the stored path against the current track path and pushes it through vtable callbacks, with a championship-server notification path raising byte_7CFF48, then runs the UI hit test.

Methods: `0x00478ED0`

- `this+0x00000000` `pointer to object vtable (callbacks at +60 and +176) vtable_ptr` (read, DERIVED)
- `this+0x00000150` `u32 flag (this[84]) checked under the championship-server condition championship_session_flag` (read, GUESS)
- `this+0x0000015C` `pointer to stored track path string (byte_5EA438 fallback) stored_track_path_ptr` (read, DERIVED)

### UiSlider

UI slider component constructor: initializes the base UI component via VTableSetInit with default float 0.8 and installs the slider vtable off_5A4B90.

Methods: `0x00479690`

- `this+0x00000000` `pointer to off_5A4B90 vtable vtable_ptr` (write, DERIVED)

### UiComponentRangeInit

UI component constructor variants that delegate range/field setup to VtableSetWithInitCall and install a per-type vtable (off_5A4DB8 or off_5A59F0).

Methods: `0x00479730`, `0x00479BD0`

- `this+0x00000000` `pointer to per-type vtable (off_5A4DB8 / off_5A59F0) vtable_ptr` (write, DERIVED)

### UiComponentVTableSetInit

UI component initializer variants that delegate field setup to InitVTableSet and install a per-type vtable (off_5A5C18 or off_5A64B8).

Methods: `0x00479C80`, `0x0047A620`

- `this+0x00000000` `pointer to per-type vtable (off_5A5C18 / off_5A64B8) vtable_ptr` (write, DERIVED)

### UiCursorScrollPosition

Computes and clamps the scroll position of a cursor-based UI component from the item count and the scroll range, with a division guard and a fallback utility when the content fits the viewport.

Methods: `0x0047BE00`

- `this+0x000000EC` `u32 scroll position (clamped to [0, count-1]) scroll_position` (read_write, DERIVED)
- `this+0x00000110` `u32 step size (weighted formula term) step_size` (read, GUESS)
- `this+0x00000114` `u32 scroll range (division guard when zero) scroll_range` (read, GUESS)

### UiObjectWithFloatParam

UI object constructor that delegates to UIConstructorWithVTableParams, stores a caller-provided parameter at +0xFC, and installs the off_5A69B0 vtable.

Methods: `0x0047C7C0`

- `this+0x00000000` `pointer to off_5A69B0 vtable vtable_ptr` (write, DERIVED)
- `this+0x000000FC` `u32 caller-provided parameter (stored at this[63]) caller_param_field` (write, GUESS)

### UiLoadingPercentDisplay

Reads a loading-progress float through a vtable+0xB4 accessor, formats it as a percentage string, and dispatches loading events according to the mode value at +0xFC (230 threshold-gated, 232 global).

Methods: `0x0047C860`

- `this+0x00000000` `pointer to object vtable (accessor slot +0xB4) vtable_ptr` (read, DERIVED)
- `obj+0x000000B4` `vtable slot +0xB4 returning a pointer to the loading progress float progress_accessor_slot` (read, GUESS)
- `this+0x000000FC` `u32 dispatch mode (230 threshold-gated / 232 global) dispatch_mode` (read, DERIVED)

### CircuitInfoPage

Circuit-info page object: constructor runs base initialization, installs the off_5A6BC8 vtable, and inserts six category label strings into a linked list.

Methods: `0x0047E440`

- `this+0x00000000` `pointer to off_5A6BC8 vtable vtable_ptr` (write, DERIVED)

### UiSliderList

UI slider/list manager whose destructor tears down a sub-object, walks a linked list of nodes freeing each (conditionally destroying the embedded child object through the node vtable), clears list state, delegates to a base destructor, and optionally frees itself.

Methods: `0x0047FB10`

- `this+0x00000000` `pointer to off_5A7168 / off_5A4550 vtable (reassigned during destructor) vtable_ptr` (write, DERIVED)
- `this+0x000000F0` `pointer to list head node (this[60]) list_head_ptr` (read, DERIVED)
- `this+0x000000F4` `pointer field (this[61]) list_next_field` (read, GUESS)
- `this+0x000000F8` `pointer field (this[62]) list_field_0xF8` (read, GUESS)
- `this+0x000000FC` `pointer field (this[63]) cleared to 0 at end of teardown list_sentinel` (read_write, GUESS)
- `*(this+0xF0)+0x00000000` `pointer to node data / child object node_value_ptr` (read, GUESS)
- `*(*(this+0xF0)+0x0)+0x00000000` `vtable slot 0 of the embedded child object (destructor entry) node_child_vtable` (read, GUESS)
- `*(this+0xF4)+0x00000004` `pointer to next node (node+4) node_next_ptr` (read, GUESS)

### UiStateChangeHandler

UI widget state-change handler: gated by the enable byte at +0xE0, normalizes and compares string fields at +0xA0/+0xA8 (with a context base at +0x40 in one variant), records validation state, dispatches a state-dependent virtual call, and fires a vtable +44 notification when the computed state changes.

Methods: `0x00487460`, `0x00487960`

- `this+0x00000000` `pointer to object vtable (notification slot +44) vtable_ptr` (read, DERIVED)
- `this+0x00000040` `pointer to context object 5772 bytes into the lookup (0x00487960 variant) lookup_context_base_ptr` (read, GUESS)
- `this+0x000000A0` `pointer to first/lookup string (byte_5EA438 fallback) lookup_string_ptr` (read, GUESS)
- `this+0x000000A8` `pointer to second/comparison string (byte_5EA438 fallback) comparison_string_ptr` (read, GUESS)
- `this+0x000000E0` `byte enable gate enable_flag` (read, DERIVED)
- `obj+0x0000002C` `byte/bool validation state written with the comparison result validation_state` (write, GUESS)

### UiConfigEntryWriter

Serializes one UI config entry into an output buffer: concatenates the value source, writes the key prefix literal, conditionally writes the key name, and terminates the entry.

Methods: `0x004B1FC0`

- `this+0x0000000C` `pointer to key name string (byte_5EA438 fallback) key_name_ptr` (read, DERIVED)

### UiClassDisposer

Object lifecycle routine that installs the off_5AD06C vtable/interface pointer and optionally frees the object itself when parameter a2 bit 0 is set.

Methods: `0x004DB090`

- `this+0x00000000` `pointer to off_5AD06C vtable/interface vtable_ptr` (write, DERIVED)

### UiLayoutInitializer

Unconditional UI initialization sequence that dispatches two virtual methods (vtable +28 with 0, +32 with 1000) and calls UILayoutDispatchWithDataPrep with 640.

Methods: `0x004DB520`

- `this+0x00000000` `pointer to object vtable (dispatch slots +28 and +32) vtable_ptr` (read, DERIVED)
- `obj+0x0000001C` `vtable slot +28 virtual method (called with argument 0) vtable_slot_28` (read, GUESS)
- `obj+0x00000020` `vtable slot +32 virtual method (called with argument 1000) vtable_slot_32` (read, GUESS)

### ForceFeedbackController

Builds the force-feedback output packet at +0x938 from four wheel blocks and seventeen channels, scaling/clamping force components, packing intensities, and zeroing the FFB fields when the enable flag is clear.

Methods: `0x004E2760`

- `this+0x00000098` `float vibration input scaled by 3.0 vibration_float_0x98` (read, GUESS)
- `this+0x000000AC` `float vibration input scaled by 7.0 vibration_float_0xAC` (read, GUESS)
- `this+0x000000C0` `float steering input scaled by 7.0 steering_float_0xC0` (read, GUESS)
- `this+0x00000108` `array of 4 wheel blocks, stride 296 bytes wheel_blocks` (read, DERIVED)
- `this+0x000001E8` `float wheel force scaled by 15.0 (first wheel at v3+224) wheel_force_15_0` (read, GUESS)
- `this+0x00000938` `u32 packed per-wheel output (start of FFB packet) output_packet_dword` (write, DERIVED)
- `this+0x0000093C` `u16 packed per-wheel output output_packet_word` (write, DERIVED)
- `this+0x0000093E` `byte packed steering/vibration output steering_vibration_byte` (write, DERIVED)
- `this+0x0000093F` `byte packing two 4-bit channel intensity fields channel_intensities` (write, DERIVED)
- `this+0x00000940` `u32 bitmask of active channels channel_bitmask` (write, DERIVED)
- `this+0x00000944` `i16 channel force component (clamped +/-32767) force_word_a` (write, DERIVED)
- `this+0x00000946` `i16 channel force component (clamped +/-32767) force_word_b` (write, DERIVED)
- `this+0x00000948` `i16 channel force component (clamped +/-32767) force_word_c` (write, DERIVED)
- `this+0x0000098C` `byte FFB enable flag (nonzero packs channels, zero clears FFB fields) ffb_enable_flag` (read, DERIVED)
- `this+0x000009A8` `array of 17 channels, stride 28 bytes channel_array` (read, DERIVED)

## Compatibility contracts

- **DriverAssetPathCandidateLayout** — DriverAssetPathBuilder produces candidate asset paths as a base directory prefix followed by a variant token ('pws' via aSpwsS or 'tv' via aStvS) and a suffix token (Fb, Fe, Sb, Se), then verifies each candidate with FilePathExtensionCheck and registers existing files via DriverNameIDLookup using the object id at this+0x8. The function returns 1 only when the a2 flag is set, no candidate check failed, and TextFormatStructInitializer succeeded. A replacement must reproduce this candidate filename layout and the register-if-exists behavior.
- **CommentaryPathCandidateLayout** — CommentaryAssetPathBuilder builds commentary paths as a season/driver directory prefix (globals dword_5EC3D8/dword_5EC428 with byte_5EA438 fallback) plus a subdirectory token (pws or tv) and a TB or TE token or a file-extension string; each candidate is verified with FilePathExtensionCheck against the pws (this+3/+8/+13/+18) and tv (this+23/+28/+33/+38) slots and matching slots are dispatched to the commentary lookups. A replacement must reproduce this directory layout and slot dispatch.
- **UiLabelElementListPopulation** — UiElementWithLabelList constructors run the shared ShortComputation_6d60 base initializer, install a per-variant vtable, store a reference (global enable flag or global reference) at this+0x31C, write the literal flag fields at +0x324..+0x330 and a literal at +0x334, and insert text-handle nodes (off_5BE704 and one or three aOn copies) into the linked list via LinkedListInsertWithNodeAllocation with tag -1. A replacement must reproduce the label-node list population and the stored-reference indirection.
- **UiLoadingPercentModeDispatch** — UiLoadingPercentDisplay reads the loading progress through the vtable +0xB4 accessor, formats it as a percent string, and dispatches according to the mode field at +0xFC: value 230 routes through ThresholdGatedVirtualDispatch with flt_5EA618, value 232 routes through GlobalDispatchWithGuard. A replacement must preserve this mode dispatch and the formatted percent output.
- **CircuitInfoPageLabelOrder** — CircuitInfoPage constructor inserts six category label strings into its linked list in a fixed order: circuit name, location, first grand prix, circuit length, lap record, race laps at 100%. A replacement circuit-info page must present this label set in this order.
- **UiStateChangeHandlerFlow** — UiStateChangeHandler runs only when the enable byte at this+0xE0 is set: it snapshots the computed state, normalizes the lookup string (this+0xA0) through StringNormalizeLookup_a460, compares it with the comparison string (this+0xA8) via sub_588410, records the validation outcome, and fires a virtual notification at vtable slot +44 with argument 1 only when the recomputed state differs from the snapshot. A replacement widget system must keep these gates, the string normalization/comparison, and the change-detection notification.
- **UiSliderListTeardown** — UiSliderList destructor installs vtable off_5A7168, tears down the sub-object at this+96, reinstalls off_5A4550, walks the singly linked list from this[60] freeing each node (conditionally destroying the embedded child object through the node vtable when the node flag and data pointer are set), clears the four list state fields, delegates to the base destructor sub_485EB0, and frees the object itself when the delete flag bit 0 is set. A replacement must preserve the linked-list teardown and the self-free convention.
- **ForceFeedbackOutputPacketLayout** — ForceFeedbackController packs an output packet starting at this+0x938: a dword at +0x938 and a word at +0x93C of per-wheel packed values, a steering/vibration byte at +0x93E, and (when the enable byte at +0x98C is set) a channel intensity byte at +0x93F, a channel bitmask at +0x940, and three clamped force words at +0x944/+0x946/+0x948. Wheel types clamp as value>>3 when below 24 else 3; forces saturate to +/-32767 after scaling. When disabled the FFB fields are zeroed. A replacement must reproduce this packet layout and clamping.
- **UiConfigEntryTextFormat** — UiConfigEntryWriter serializes one UI config entry into the output buffer: it writes the key prefix literal, conditionally writes the key name (this+0xC, byte_5EA438 fallback) when the name is non-empty, and terminates the entry with the word literal. A replacement must reproduce the emitted prefix/key/terminator sequence.

## Unresolved

- DriverAssetPathBuilder: the roles of globals aSS (0x005BE860) and dword_5EA5E8 (0x005EA5E8) are not readable from the raw source; the three DriverNameIDLookup flag arguments (variant pws/tv and suffix Fb/Fe/Sb/Se encoding) are not established; the string-buffer slots at this+4/+9/+14/+19 and this+24/+29/+34/+39 used by FilePathExtensionCheck are only partially evidenced; callers NamedEntryLookupInFormatList (0x00415230) and VehicleListBuilderFromGlobalArray (0x00415780) are named in the packet summary but are not allowed evidence refs.
- CommentaryAssetPathBuilder: the exact strings at off_5C23CC and off_5C23C8 (file extensions) are not recovered; whether the TB and TE tokens are commentary text blocks or file extensions is inferred from the fill naming, not packet-confirmed; dword_5EA5E8 is listed as a referenced global but never appears in the rendered raw source; the caller NameListBuilderFromVehicleArray (0x004159B0) is a caller evidence ref but its role is unestablished.
- UiObject: the concrete UI class behind the off_59F140 vtable is not identifiable from this function alone; the semantic roles of the byte flags at +0xF4/+0xF5 and of the grouped float defaults (5.0/10.0/1.0/-1.0) belong to the enclosing UI subsystem; UIStructInit (0x0048E600) internals are outside this packet.
- UiObjectInit: owning class unidentified; the purpose of the zeroed dword at +0xE4 is unknown; the UI_Object_Init abi label is LEGACY trust and is not independently corroborated; ConstructorWithByteParams (0x00487220) internals are outside this packet.
- DriverCollisionBroadcastFromUi: the trigger/state field at v1+376 (0x178) is inferred as a driver-data collision trigger; sub_587ECE is assumed to map UI text to a driver identifier but its return semantics are not verified; the object type behind this+0x40 and its vtable layout are unknown; no static callers are recorded in the packet.
- UiElementWithLabelList: the exact meaning of the flag fields at +0x324/+0x328/+0x32C/+0x330 (1/0/1/1 vs 3/0/3/3) and the literals 269/270 at +0x334 is unknown; the shared base init ShortComputation_6d60 (0x00466D60) semantics are not grounded; the text-handle list (off_5BE704, aOn) consumption is external; the differing reference globals (enable flag 0x7CF788 vs reference 0x7D02E4) suggest two concrete subclasses merged here.
- UiDatabaseObject: the meaning of the zeroed fields +0x3C..+0x50 and the -1 sentinel at +0x54 is inferred only from constructor shape; the UI database object type is not identified.
- ProfileIconPathBuilder: global byte_7CE498 is listed in the packet but absent from the raw source; the identity of the object providing the vtable+60 base-path virtual method is not established; the four dword loads of the ProfileIcon.bmp literal are a raw-source artifact of the 16-byte string layout, not four distinct semantic values.
- TrackPathUiDisplay: obj fields at +0x3C and +0xB0 are listed as read by this function in the deterministic facts but do not appear in the raw decompiled text; the vtable +176 and +60 callbacks and the meaning of dword_7D0410 == 5 are inherited from existing analysis, not independently verified here.
- UiSlider: the exact UI component class and the meaning of parameter 0 / default float 0.8 are owned by the base VTableSetInit (0x004795E0); no static callers are evidenced.
- UiComponentRangeInit: owner object types unknown (off_5A4DB8 / off_5A59F0); the literal values 1045220557 and 1048576000 passed to VtableSetWithInitCall (0x00466980) are not decoded by the raw source.
- UiComponentVTableSetInit: owner object types unknown (off_5A5C18 / off_5A64B8); the integer literals 1065353216 and 1028443341 passed to InitVTableSet (0x004668E0) are only interpreted as float 1.0 / 0.05 by existing analysis prose, not by packet evidence.
- UiCursorScrollPosition: the raw source calls the helper at 0x0047BD90 but that target is absent from the packet callee facts and therefore has no allowed evidence reference; the field roles +0x110 (step size) and +0x114 (scroll range) are DERIVED from prior naming; the weighted formula semantics are not proven.
- UiObjectWithFloatParam: the integer constant 1065353216 is not decoded by the raw source (existing DERIVED prose reads float 1.0); off_5A69B0 layout and the UI object type it describes are not established; the meaning of the caller-provided value stored at +0xFC is unknown.
- UiLoadingPercentDisplay: the exact object type and the vtable+0xB4 accessor are unknown; the dispatch-mode constants 230 and 232 at +0xFC are not further resolved; the per-compilation-unit globals 0x0059E450, 0x0059E6F8, 0x005C37CC and 0x008AC494 have no direct role in this function.
- CircuitInfoPage: sub_4893C0 (0x004893C0) call semantics (base-class constructor vs embedded list initializer) are defined by its own body, not this packet; the linked-list head/node layout is internal to LinkedListInsertWithNodeAllocation; the tag -1 role is undocumented; the six inserted strings as label rows of the circuit-info page is DERIVED only.
- UiSliderList: the concrete class owning this destructor is not evidenced by the packet; the node flag byte at node+12 appears in the raw source but has no dedicated field evidence reference (the packet-level guard this+0xFC == 0 is the closest deterministic match and is used for the conditional-destroy branch); sub_4C5DE0 (0x004C5DE0) teardown semantics are external.
- UiStateChangeHandler: the string fields +0xA0/+0xA8 and the validation field obj+0x2C roles are interpretations drawn from prior analysis; the 5772-byte context offset added to this+0x40 (0x00487960 variant) is unresolved without the lookup-context layout; the vtable slot +44 notification argument 1 semantics are unknown; callers 0x00487530, 0x00487640 and 0x00487E10 (for 0x00487460) are named in the packet but are not allowed evidence refs; the global byte_5EA438 default-string role (application directory vs empty string) is not proven.
- UiConfigEntryWriter: v5 is populated by AlignedStringConcat but its contents are never written to a2 in this function body - value emission must occur elsewhere or is omitted; the value field at this+0x14 (accessed as unsigned __int16) is not in the packet field list; the 16-bit access at +0x14 differs from other cluster functions that treat the same offset as a float, so the field width/type at +0x14 is not established; the string contents of aSS_6, aS_8, word_5C30B4 and byte_5EA438 are unknown.
- UiClassDisposer: the owning class is unknown (the audio-filter label from existing analysis is DERIVED and not independently confirmed); whether the routine is a constructor or a destructor-style disposer (vtable install followed by optional self-free on a2 bit 0) is ambiguous from the raw body.
- UiLayoutInitializer: the identity of the two virtual methods (vtable+28, vtable+32) is unknown; the reset/setup interpretation is a GUESS from the argument literals 0 and 1000; whether 640 is a pixel width or another layout parameter is unknown; the return value 0 contract is unknown.
- ForceFeedbackController: seven read-only globals (0x0059E450, 0x0059E478, 0x0059E708, 0x0059E70C, 0x0059E710, 0x0059E864, 0x0059E8D8) are reported referenced but do not appear in the inlined raw source; the per-channel sub-fields (flag at v13-24, intensity byte at v13-23, two force components at v13-2/v13-1) and the wheel force floats at v3-24/v3-20 have no field evidence refs; the exact bit-field semantics of the packed word at +0x93C and byte at +0x93E are not resolved; the single recorded caller sub_4EF2E0 (0x004EF2E0) call context and how the returned packet is consumed are unknown.
- No clean multi-state machine is evidenced in this packet: UiLoadingPercentDisplay's field-0xFC mode dispatch (230 threshold-gated vs 232 global) is a two-branch dispatch modeled as a class field, not a state machine; UiStateChangeHandler's enable gate and change detection are guard-driven flows, not states.
- field:this:0x00000040 is used as a child-object pointer in DriverCollisionBroadcastFromUi and as a context base in UiStateChangeHandler (0x00487960); equal offsets on unrelated this pointers are not proof the fields or classes are identical.
- Class ownership is UNKNOWN for every packet function; the class groupings proposed here are DERIVED/GUESS reconstruction artifacts, not recovered original class names.
- All helper/callee addresses (0x00414900, 0x004149A0, 0x00415D90, 0x00417640, 0x00417AF0, 0x00418970, 0x00461470, 0x00462460, 0x00462940, 0x004668E0, 0x00466980, 0x00466D60, 0x00479320, 0x004795E0, 0x0047BC90, 0x00485EB0, 0x00486F30, 0x00487220, 0x00487260, 0x00487720, 0x00487760, 0x004893C0, 0x00489950, 0x0048D3A0, 0x0048E600, 0x0048FC50, 0x0049A460, 0x004A1AC0, 0x004B0170, 0x004B0220, 0x004C5DE0, 0x004C8900, 0x004DB550, 0x00566650, 0x00566C30, 0x00587BCF, 0x00587BDC, 0x00587ECE, 0x0058815F, 0x00588410) are not functions in this packet (methods may only name packet functions); they remain recorded as callee evidence refs and in dependencies.
