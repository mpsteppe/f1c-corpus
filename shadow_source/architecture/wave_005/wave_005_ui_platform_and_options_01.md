# UiPlatformAndOptions

Scope: `ui_platform_and_options`  
Trust: `DERIVED`

The ui_platform_and_options packet spans 26 functions. The dominant cluster is the UI platform: vtable-installed UI object constructors and destructors (UiComponent variants on sub_48C070, UiTextDisplay-derived objects on UITextDisplayConstructor, RenderUiObject, UiElementList, ListBoxNode, ReplayControlsMenu), widget state handling (UIStateChangeDispatcher, UIWidgetPropagateState, UIValueValidator, UIStateReset), the key-binding UI (a three-state press-a-key state machine plus click/mouse handlers editing binding arrays), text-field initialization, and camera shader-config serialization. Adjacent functions cover audio resource handling (RIFF/WAVE header writing, MP3 track filename building), a device/config object selector against 36 registered globals, and a collision-mesh triangle adjacency builder. Ownership is mostly UNKNOWN in the packet; only three DERIVED owners (TriangleMeshAdjacencyBuilder, UIObject, ReplayControlsMenu) are asserted, and every class proposed here is DERIVED or GUESS.

## Function roles

- `0x004056A0` **WavHeaderWriter** — Builds a RIFF/WAVE header (RIFF, WAVE, fmt, data chunks) at buffer offset this+68 via repeated sub_405670 appends, selecting the data size from the audio header by flag bits (0x20/4) and returning the buffer position after the final 'data' size field.
- `0x004069F0` **MusicTrackSlot** — Builds the MP3 track filename for a music slot: frees the previous slot resource via sub_406A70 when the slot handle (this+0x5C) is active, formats a string handle, forwards to sub_58C724, formats '%s%d,%d.mp3' from this+0x5C and this+0x1C, and copies the buffer; returns whether the slot handle is active.
- `0x004493A0` **TriangleMeshAdjacencyBuilder** — Appends one triangle to a collision mesh adjacency builder: grows the 32-byte body buffer, reinitializes and migrates bodies, frees both lazy BVH trees, computes edge midpoints, inserts vertices and edge midpoints into the two trees, links shared edges to neighbors, and optionally copies per-edge flags from a6.
- `0x00452810` **DeviceConfigSelector** — Device/config object selector: matches the input integer against the stored values of 36 pre-registered global config objects and, on a match, stores the matched global address into this+0x20; sets this[0] to 2 or 0, reinitializes the this+1 sub-structure via SwapAndReinit, clears this+0x1C, and returns 0 on a match or -1 otherwise.
- `0x00456670` **CameraShaderConfigWriter** — Serializes the local-camera shader state into a formatted key-value string block via the getter group (DualFieldGetter, MultiFieldGetter, ShortComputation_6080, DualFieldGetter_60a0, RectViewportDimensionGetter), two direct field copies (this+0x48, this+0x5C), and BufferWriteWithStringLengthCheck emissions; returns 0.
- `0x00457670` **CameraShaderConfigWriter** — Serializes the static-camera shader state into a formatted key-value string block via the getter group, six direct field copies (this+0xC..+0x98) plus this+0x48 and this+0x5C, and BufferWriteWithStringLengthCheck emissions; returns 0.
- `0x0045B360` **RenderUiObject** — Constructor-style initializer for a render/UI object: installs the RenderUIObject vtable (off_59F080), initializes a sub-object at byte offset 4 via ShortComputation_cb70 and sub_4DCF80, fills eight 92-byte viewport blocks starting at 0x3C with defaults (0, -1, -1.0f, 3), clears the entry cursor at 0x31C, resets all eight indexed entries, and clears tail state (0x320, 0x324, 0x328).
- `0x00466140` **UIObject** — Destructor-style cleanup: reassigns this+0x0 to the off_59F140 vtable, resets object state via StateResetWithZero, then tail-returns Destructor_e670(this).
- `0x004662C0` **UiStateObject** — Resets part of a UI state object: calls FieldSetterCall on the object referenced by this+0x40 with value 0, zeroes the byte flags at this+0xF4 and this+0xF5, and returns 0.
- `0x0046B070` **KeyBindingUi** — Key-binding screen click handler: resets the screen-mode setting dword_7CFF84 to 0, reads a dual-field value, validates it against two bounds obtained through vtable slots +24 and +32, and opens the key/controller binding UI via KeyBindingUIPressKeyOrController(1, 1); always returns 0.
- `0x0046B0C0` **KeyBindingUi** — Three-state key-binding UI machine: (1) prompt state shows the popup, loads the 'Press Key or Controller' prompt and entry name into this+0x174, moves to state 2; (2) input-capture state reads a raw parameter, maps it with default 89, rejects reserved keys, stores raw value at this+0x200 and mapped ID at this+0x204, moves to state 3; (3) finalize state commits the binding via ControllerShifterMapping, restores the child panel visibility byte, and resets state to 0.
- `0x0046C8B0` **KeyBindingUi** — Mouse click handler for the key binding UI: reads dual-field values from the structure at this+0x40, looks up a binding index, removes the previous binding through an indirect remove/shift function, and inserts the new binding into the array selected by the byte at this+0x174; returns 0.
- `0x00470300` **UiTextField** — Type-selected UI text field initializer: switches on the type selector at this+0x304 (cases 0x1AF..0x1B5), clears and binds per-type global buffers via UtilityFunction_b7e0, sets the mode field this+0x2E8 (0 or 2), and for password-mask types sets the placeholder pointer this+0x2FC; case 0x1B3 uses BoundedFieldSetter instead; always returns 0.
- `0x00472340` **UiComponent** — Constructor for a UI component: runs the shared initializer sub_48C070 with literal 1, installs the type vtable off_5A1E00 at this+0x0, then invokes VirtualFactoryPathFormat to format a factory path; returns this.
- `0x00473BD0` **UiComponent** — Minimal UI element constructor: calls the base initialization helper sub_48C070(this, 0), then assigns the vtable pointer off_5A2E80 to this[0]; returns this.
- `0x00474A10` **UiComponent** — Constructor for a UI list element: runs base initializer sub_48C070 with argument 1, installs the vtable off_5A3E40 at offset 0, stores literal 400 at this+0x31C, then calls sub_474AB0 for extra list-element initialization; returns this.
- `0x00477440` **UiElementList** — Destructor for a UI element list: resets the vtable to off_5A4550, walks the linked list rooted at this+0xF0 freeing each node (conditionally destroying its child object through the node vtable), zeroes list state this+0xF0..+0xFC, invokes the base destructor sub_485EB0, and frees self when bit 0 of the destruction flag is set.
- `0x00477EA0` **UiTextObject** — Constructor for a UI text-display derived class: calls the base UITextDisplayConstructor, initializes a sub-object at this+0x124 via sub_499B10, sets sentinel -1 index fields (0x11C, 0x120, 0x15C) and a zero counter (0x158), assigns the vtable off_5A46B0, and returns this.
- `0x00478E10` **UiTextObject** — Constructor for a UI text object: initializes the text-display sub-object at the base via UITextDisplayConstructor, initializes a sub-struct at this[71] (0x11C) via sub_499B10, zeroes state this+0x150..+0x170, sets this+0x160 to -1, assigns the vtable off_5A4A20, and writes the line/text capacity 148 to this+0x118.
- `0x0047C0A0` **UiScreenText** — UI text getter: fetches the UI screen text pointer via UIScreenTextAccessor, copies it into the global buffer byte_7CD880 when non-null, and returns the text pointer.
- `0x0047C6E0` **UiComponent** — UI component initializer: calls sub_48C070 on this with argument 1, then writes the vtable pointer off_5A68F0 to offset 0 and returns this.
- `0x0047DAF0` **ReplayControlsMenu** — Replay/VCR playback-controls menu constructor: runs base initialization ConstructorInitVTable, installs the vtable off_5A6B20, stores the mode selector at this+0xEC, and when the mode is 480 populates a linked list with playback command entries (Begin, play, stop, forward/reverse scan, play back, bookmarks); returns this.
- `0x00487400` **UiWidget** — UI state-change dispatcher with change detection: reads the current state byte via ByteFieldGetterAt100, and when the incoming state a2 differs invokes a virtual notification through the object vtable (offset 44), then returns the result of UIWidgetPropagateState(a2).
- `0x0048741B` **UiWidget** — Propagates a boolean state through a UI widget: notifies via StateChangeNotification, dispatches the state (direct vtable slot 64 when set, otherwise RangeCheck + StateDependentVTableDispatch), then walks the linked list rooted at a3+144 invoking the vtable method at offset 56 on each node; returns the last call result.
- `0x004874E0` **UiWidget** — UI value validator with early-exit guards: returns 0 when ByteFieldGetterAt100 is nonzero or the normalized string is empty, and returns 1 when the flag at v1+225 is clear or the string at v1+160 (falling back to byte_5EA438) normalizes to non-empty.
- `0x00487660` **ListBoxNode** — UI list-box node initializer: calls base setup ShortComputation_5e30, stores the two byte parameters a2 and a3 at this+0xE0 and this+0xE1, installs the ListBoxNode vtable off_5ABA18 at this+0x0, and returns this.

## Proposed classes

### TriangleMeshAdjacencyBuilder

Appends triangles to a growing collision-mesh adjacency structure, maintaining a reallocatable 32-byte body buffer and two lazy BVH trees that link shared edges to neighbouring triangles.

Methods: `0x004493A0`

- `this+0x00000000` `u32 count triangle_count` (read_write, DERIVED)
- `this+0x00000004` `u32 capacity / end marker capacity_end_ptr` (read, DERIVED)
- `this+0x00000008` `pointer to 32-byte AABB body buffer body_buffer` (read_write, DERIVED)
- `this+0x0000000C` `pointer (lazy BVH tree) bvh_vertex_tree` (read_write, DERIVED)
- `this+0x00000010` `pointer (lazy BVH tree) bvh_edge_midpoint_tree` (read_write, DERIVED)

### DeviceConfigSelector

Matches an input integer against the stored values of 36 pre-registered global config objects and records the matched object pointer, acting as the entry point of a device/config selection flow.

Methods: `0x00452810`

- `this+0x00000000` `u32 (2 matched / 0 no match) match_status` (read_write, DERIVED)
- `this+0x0000001C` `u32 cleared_field` (write, GUESS)
- `this+0x00000020` `pointer to matched global config object matched_global_ptr` (read_write, DERIVED)

### CameraShaderConfigWriter

Serializes a camera's shader-state fields into a formatted key=value string block (local-camera and static-camera variants), reading camera and viewport fields directly and through a shared getter group.

Methods: `0x00456670`, `0x00457670`

- `this+0x0000000C` `float shader parameter input camera_field_0x0C` (read, GUESS)
- `this+0x00000010` `float shader parameter input camera_field_0x10` (read, GUESS)
- `this+0x00000014` `float shader parameter input camera_field_0x14` (read, GUESS)
- `this+0x00000048` `shader parameter input (this[18]) camera_field_0x48` (read, GUESS)
- `this+0x0000005C` `shader parameter input (this[23]) camera_field_0x5C` (read, GUESS)
- `this+0x00000090` `shader parameter input (this[36]) camera_field_0x90` (read, GUESS)
- `this+0x00000094` `shader parameter input (this[37]) camera_field_0x94` (read, GUESS)
- `this+0x00000098` `shader parameter input (this[38]) camera_field_0x98` (read, GUESS)

### RenderUiObject

Render/UI object whose initializer installs a vtable, initializes a sub-object, fills eight fixed-size viewport blocks with default values, and resets indexed entries and tail state.

Methods: `0x0045B360`

- `this+0x00000000` `pointer to off_59F080 vtable vtable_ptr` (write, DERIVED)
- `this+0x00000004` `nested object at byte offset 4 sub_object` (read_write, GUESS)
- `this+0x0000002C` `u32 sub_object_field_0x2C` (write, GUESS)
- `this+0x00000030` `u32 set to -1 sub_object_field_0x30` (write, GUESS)
- `this+0x0000003C` `array of 8 viewport blocks, 92-byte stride viewport_blocks` (write, GUESS)
- `this+0x0000008C` `u32 set to -1 viewport_block_field_0x8C` (write, GUESS)
- `this+0x00000090` `float set to -1.0f viewport_block_field_0x90` (write, GUESS)
- `this+0x00000094` `u32 set to 3 viewport_block_field_0x94` (write, GUESS)
- `this+0x0000031C` `u32 cursor indexed_entry_cursor` (write, GUESS)
- `this+0x00000320` `byte tail_state_byte` (write, GUESS)
- `this+0x00000324` `u32 tail_state_0x324` (write, GUESS)
- `this+0x00000328` `u32 tail_state_0x328` (write, GUESS)

### UIObject

Base UI object: vtable-installed object whose destructor reassigns the vtable (off_59F140), resets state, and delegates to a base destructor.

Methods: `0x00466140`

- `this+0x00000000` `pointer to off_59F140 vtable vtable_ptr` (read_write, DERIVED)

### UiStateObject

UI state reset object: clears the object referenced by a pointer field and two byte flags.

Methods: `0x004662C0`

- `this+0x00000040` `pointer to target object target_object_ptr` (read, GUESS)
- `this+0x000000F4` `byte flag flag_byte_a` (read_write, GUESS)
- `this+0x000000F5` `byte flag flag_byte_b` (write, GUESS)

### KeyBindingUi

Key/controller binding UI screen: click handler, press-a-key state machine, and mouse handler that edit key-binding arrays.

Methods: `0x0046B070`, `0x0046B0C0`, `0x0046C8B0`

- `this+0x00000000` `pointer to object vtable (dispatch slots +24/+32) vtable_ptr` (read, DERIVED)
- `this+0x00000040` `pointer to child panel object child_panel_ptr` (read, GUESS)
- `*(this+0x40)+0x00001589` `byte visibility flag child_panel_visibility_byte` (read_write, DERIVED)
- `this+0x00000174` `byte array selector (read as byte) / key-name string buffer (written) array_selector_or_key_name_buffer` (read_write, GUESS)
- `this+0x000001F4` `u32 entry index selected_entry_index` (write, GUESS)
- `this+0x000001F8` `sprite handle from BitmapSpriteAccessor child_panel_sprite_handle` (read_write, GUESS)
- `this+0x000001FC` `u32 state (0 idle, 1 prompt, 2 capture, 3 finalize) binding_state` (read_write, DERIVED)
- `this+0x00000200` `u32 raw key/controller value captured_raw_value` (write, GUESS)
- `this+0x00000204` `u32 mapped binding ID mapped_id` (write, GUESS)
- `this+0x00000208` `u32 accumulator lookup_accumulator` (read_write, GUESS)
- `obj+0x00000018` `vtable slot +24 bound getter bound_getter_a` (read, GUESS)
- `obj+0x00000020` `vtable slot +32 bound getter bound_getter_b` (read, GUESS)

### UiTextField

Type-selected UI text field that binds per-type global buffers, sets the input mode, and configures a placeholder/mask string.

Methods: `0x00470300`

- `this+0x00000304` `u32 type selector (cases 0x1AF..0x1B5 via jump table) text_field_type_selector` (read, DERIVED)
- `this+0x000002E8` `u32 mode (0 or 2) input_mode` (write, DERIVED)
- `this+0x000002FC` `pointer to mask/placeholder string placeholder_ptr` (write, DERIVED)
- `this+0x000000E5` `byte flag flag_byte` (write, GUESS)

### UiComponent

Base UI component initialized by sub_48C070 and then assigned a per-type vtable; the four constructor variants in this packet differ only in vtable and extra init.

Methods: `0x00472340`, `0x00473BD0`, `0x00474A10`, `0x0047C6E0`

- `this+0x00000000` `pointer to per-type vtable (off_5A1E00/5A2E80/5A3E40/5A68F0) vtable_ptr` (write, DERIVED)
- `this+0x0000031C` `u32 value/counter preset (literal 400) literal_400_preset` (write, GUESS)

### UiElementList

UI element list (slider-list shaped) whose destructor walks a linked list of nodes, conditionally destroys child objects through node vtables, frees nodes, zeroes list state, and delegates to a base destructor.

Methods: `0x00477440`

- `this+0x00000000` `pointer to off_5A4550 vtable vtable_ptr` (write, DERIVED)
- `this+0x000000F0` `pointer to list head node list_head_ptr` (read, GUESS)
- `this+0x000000F4` `pointer (this+0xF4) list_next_ptr` (read, GUESS)
- `this+0x000000F8` `pointer list_field_0xF8` (read, GUESS)
- `this+0x000000FC` `pointer sentinel (== 0 terminates walk) list_sentinel` (read_write, GUESS)
- `*(this+0xF0)+0x00000000` `pointer to child object node_value_ptr` (read, GUESS)
- `*(this+0xF4)+0x00000004` `pointer to next node node_next_ptr` (read, GUESS)

### UiTextObject

Text-display-derived UI object constructed with sub-object initialization, sentinel index fields, capacity presets, and a per-type vtable; two constructor variants share UITextDisplayConstructor.

Methods: `0x00477EA0`, `0x00478E10`

- `this+0x00000000` `pointer to per-type vtable (off_5A46B0 / off_5A4A20) vtable_ptr` (write, DERIVED)
- `this+0x00000118` `u32 capacity (literal 148) line_text_capacity` (write, GUESS)
- `this+0x0000011C` `sub-struct (init via sub_499B10) or sentinel -1 sub_struct_or_sentinel` (read_write, GUESS)
- `this+0x00000120` `u32 sentinel -1 sentinel_index_0x120` (write, GUESS)
- `this+0x00000150` `u32 state field state_field_0x150` (write, GUESS)
- `this+0x00000158` `u32 counter (zeroed) counter_0x158` (write, GUESS)
- `this+0x0000015C` `u32 sentinel -1 / zeroed state sentinel_index_0x15C` (read_write, GUESS)
- `this+0x00000160` `u32 set to -1 (reported as unsigned 18446744073709551615) max_marker_0x160` (write, GUESS)
- `this+0x00000164` `u32 state field state_field_0x164` (write, GUESS)
- `this+0x00000168` `u32 state field state_field_0x168` (write, GUESS)
- `this+0x0000016C` `u32 state field state_field_0x16C` (write, GUESS)
- `this+0x00000170` `u32 state field state_field_0x170` (write, GUESS)

### UiScreenText

UI screen text getter that copies the screen's current text into a global buffer via the UIScreenTextAccessor.

Methods: `0x0047C0A0`


### ReplayControlsMenu

Replay/VCR playback-controls menu object: constructor installs the menu vtable, stores a mode selector, and for mode 480 populates a linked list of playback command entries.

Methods: `0x0047DAF0`

- `this+0x00000000` `pointer to off_5A6B20 vtable vtable_ptr` (write, DERIVED)
- `this+0x000000EC` `u32 mode selector (480 populates command list) mode_selector` (read_write, DERIVED)

### UiWidget

UI widget state handling: dispatches state changes with change detection, propagates boolean state to linked widget nodes, and validates widget values.

Methods: `0x00487400`, `0x0048741B`, `0x004874E0`

- `obj+0x0000002C` `byte UI state current_state_byte` (read, DERIVED)
- `this+0x00000000` `pointer to object vtable (dispatch slots 44/56/64) vtable_ptr` (read, GUESS)

### ListBoxNode

UI list-box node: runs base setup, stores two byte state flags, and installs the ListBoxNode vtable.

Methods: `0x00487660`

- `this+0x00000000` `pointer to off_5ABA18 vtable vtable_ptr` (write, DERIVED)
- `this+0x000000E0` `byte state/enable flag byte_state_flag_a` (write, GUESS)
- `this+0x000000E1` `byte state flag byte_state_flag_b` (write, GUESS)

### MusicTrackSlot

Music track slot manager: builds an MP3 track filename for a slot, freeing the previous slot resource before overwriting.

Methods: `0x004069F0`

- `this+0x0000001C` `u32 track index track_index` (read, DERIVED)
- `this+0x0000005C` `string resource handle (slot active when != -1) slot_handle` (read_write, DERIVED)

### WavHeaderWriter

Writes a RIFF/WAVE header (RIFF/WAVE/fmt/data chunks) at a buffer offset from the owning object, parameterized by an audio header struct.

Methods: `0x004056A0`


## Compatibility contracts

- **WaveHeaderLayout** — WavHeaderBuilder emits a RIFF/WAVE header whose byte layout is fixed: 'RIFF' + (selected data size + 36) + 'WAVE' + 'fmt ' + 16-byte format descriptor (PCM tag, channels from flag bit 1, sample rate, byte rate, block align, bits) + 'data' + payload size. A replacement must reproduce this exact byte layout and the flag-bit (0x20/4) selection of the data-size source.
- **Mp3TrackFilenamePattern** — Mp3TrackFilenameBuilder formats track filenames as '%s%d,%d.mp3' from a slot handle and a track index, frees the previous slot resource before overwrite, and reports slot activity as handle != -1. A replacement music system must preserve this naming pattern and the free-before-overwrite slot semantics.
- **KeyBindingCommitFlow** — The key-binding UI moves through prompt -> input-capture -> finalize states stored at object+0x1FC; committed bindings store the raw captured value (0x200) plus mapped ID (0x204) with default mapping 89, reserved keys are rejected and re-prompted, and the child panel visibility byte at child+0x1589 is cleared during the prompt and restored on commit. A replacement must reproduce this observable flow.
- **ReplayCommandMenuMode480** — ReplayControlsMenu for mode 480 populates a linked command list with the playback entries Begin, play, stop, forward/reverse scan (and fast variants), play back, and drop/remove bookmark. A replacement replay-controls menu must present this command set for mode 480.
- **UiStatePropagation** — UI widget state propagation reads the state byte at object+0x2C, notifies change through vtable slot 44, dispatches via StateDependentVTableDispatch or direct vtable slot 64, and walks a linked node list invoking vtable slot 56 on each node. A replacement widget system must keep these virtual dispatch points and the linked-node walk.

## Unresolved

- WavHeaderWriter: the owning object type and the buffer at this+68 are UNKNOWN; only the caller BinaryDataDeserialization (0x004054E0, named in the packet summary, not a packet evidence ref) is known.
- MusicTrackSlot: the meaning of the format parameters 0x8000/256 passed to StringFormatWith0x40Size and the purpose of the a3 argument forwarded to sub_58C724 are unknown; global aSDDMp3 (0x005BE854) is adjacent to the format-string constant but not referenced by the function.
- TriangleMeshAdjacencyBuilder: exact layout of the BVH node/body structures beyond +24/+28 is unconfirmed; the semantic difference between the two BVH trees and the a6 edge-flag meaning depend on collision consumers not in this packet; callers 0x0044AAE0 and 0x0044B370 are recorded but their role is unestablished.
- DeviceConfigSelector: the semantic role of each of the 36/38 global config objects and the meaning of the SwapAndReinit size argument 89 are undocumented.
- CameraShaderConfigWriter: the getter group writes concrete shader parameter values whose field offsets are not visible in the raw source; aFalse/aTrue globals (0x005C596C, 0x005C5798) and byte_5EA438 are data-xref listed but not referenced in the decompiled bodies; field semantics at 0xC..0x98 are GUESS.
- RenderUiObject: identity of the owning class, the semantics of the eight 92-byte viewport blocks and their defaults (0, -1, -1.0f, 3), and the purpose of the sub-object at byte offset 4 are unknown; the single static caller is ShortComputation_bb40 (0x0045BB40).
- UIObject: identity of the UI class and the object lifetime contract (Destructor_e670 has no packet callee evidence ref and may or may not free memory) are unverified; what StateResetWithZero clears beyond the state field is unknown.
- UiStateObject: the object type behind the pointer at this+0x40 and FieldSetterCall's contract are not evidenced; the two byte flags at this+0xF4/+0xF5 may be one wider flag; no callers are recorded.
- KeyBindingUi: v6 (second dual-field value) is read but unused in UIClickHandlerWithBoundsCheck; the vtable bound getters (slots +24/+32) semantics are DERIVED; this+0x174 serves both as a key-name string buffer (KeyBindingUIPressKeyOrController) and as an array-selector byte (UIMouseClickHandler) - whether these are the same field or overlapping uses is unresolved; the indirect remove/shift target (KeyBindingArrayRemoveShift + 1) is not in the packet callee list; the semantics of the 89 default and the reserved-key mapping chain are unknown.
- UiTextField: the type-selector enum values 0x1AF..0x1B5 have no confirmed semantic mapping; what UtilityFunction_b7e0 does and why case 0x1B3 uses the distinct BoundedFieldSetter path are unresolved; the global buffers (byte_7CD818/7CD834/7CD850/7CD860/7CD880) appear to be track/multiplayer-input buffers but are not proven.
- UiComponent: the base-init contract of sub_48C070 and the meaning of its boolean argument are undocumented; the four vtable variants (off_5A1E00/5A2E80/5A3E40/5A68F0) suggest distinct concrete types that are merged here for simplicity; the semantic role of the literal 400 at this+0x31C is unknown.
- UiElementList: the deterministic guard records this+0xFC==0 as the walk terminator while the raw source keys the loop on the head pointer this+0xF0; the child-destroy virtual call target is unresolvable; the node layout is only partially evidenced; a sibling destructor frees a main buffer before the walk but this variant has no equivalent stage, so the two objects are not proven the same type.
- UiTextObject: UITextDisplayConstructor's own field writes are not visible in this packet; the -1 at this+0x160 is reported as unsigned 18446744073709551615 (signed sentinel vs unsigned max not resolvable); the sub-struct at this+0x11C and sub-object at this+0x124 have no field layout.
- UiScreenText: the packet flags global 0x007CD880 access as read-only although the raw source strcpy-writes to it; UIScreenTextAccessor is invoked twice and the two results are assumed equal; the byte_7CD880 buffer size/type is unknown.
- ReplayControlsMenu: the mode literal 480 is caller-defined; off_5C7364 is a non-string data pointer inserted into the same command list; the exact menu framework consuming the constructed list is unknown.
- UiWidget: UIWidgetPropagateState's second argument v8 to StateChangeNotification is an uninitialized stack slot; whether a1 and a3 are the same object is unproven; the linked-list node type and the virtual methods at offsets 44/56/64 are unknown; UIStateChangeDispatcher's UIWidgetPropagateState target has no callee evidence ref; UIValueValidator fields at v1+225 and v1+160 are not modeled as field evidence and the exact 0/1 valid/invalid mapping is unestablished.
- ListBoxNode: the class identity and the meaning of the two byte parameters are not established; the role of ShortComputation_5e30 is not grounded; invoked by sub_493FC0 (0x00493FC0).
- TriangleMeshAdjacencyBuilder: helper/callee addresses 0x00448480, 0x00448510, 0x004485D0, 0x00448E50, 0x00448E90, 0x00448EC0, 0x00587BCF, 0x00587C03 were removed from the class method list because they are not functions in this packet (methods may only name packet functions); they remain recorded as callee evidence refs and in dependencies.
- TriangleMeshAdjacencyBuilder.neighbor_count (base body offset 0x00000018): dropped as a modeled field because the packet has no allowed evidence ref for field:body:0x00000018; the semantic note is preserved in the class responsibility/unresolved text.
- TriangleMeshAdjacencyBuilder.neighbor_ptr_list (base body offset 0x0000001C): dropped as a modeled field because the packet has no allowed evidence ref for field:body:0x0000001C; the semantic note is preserved in the class responsibility/unresolved text.
- DeviceConfigSelector: helper/callee addresses 0x00452740 were removed from the class method list because they are not functions in this packet (methods may only name packet functions); they remain recorded as callee evidence refs and in dependencies.
- CameraShaderConfigWriter: helper/callee addresses 0x00456060, 0x00456080, 0x004560A0, 0x004560C0, 0x004560E0, 0x00566C30 were removed from the class method list because they are not functions in this packet (methods may only name packet functions); they remain recorded as callee evidence refs and in dependencies.
- RenderUiObject: helper/callee addresses 0x004DCB70, 0x004DCF80, 0x0045B430 were removed from the class method list because they are not functions in this packet (methods may only name packet functions); they remain recorded as callee evidence refs and in dependencies.
- UIObject: helper/callee addresses 0x004662E0 were removed from the class method list because they are not functions in this packet (methods may only name packet functions); they remain recorded as callee evidence refs and in dependencies.
- UiStateObject: helper/callee addresses 0x004988A0 were removed from the class method list because they are not functions in this packet (methods may only name packet functions); they remain recorded as callee evidence refs and in dependencies.
- KeyBindingUi: helper/callee addresses 0x0046C7B0, 0x00454D30, 0x00454C20, 0x00455560, 0x00423A00, 0x0046A9C0, 0x00497940, 0x00497980, 0x00489940, 0x00498950, 0x004988C0 were removed from the class method list because they are not functions in this packet (methods may only name packet functions); they remain recorded as callee evidence refs and in dependencies.
- UiTextField: helper/callee addresses 0x0048B7E0, 0x0048B8F0 were removed from the class method list because they are not functions in this packet (methods may only name packet functions); they remain recorded as callee evidence refs and in dependencies.
- UiComponent: helper/callee addresses 0x0048C070, 0x00472400, 0x00474AB0 were removed from the class method list because they are not functions in this packet (methods may only name packet functions); they remain recorded as callee evidence refs and in dependencies.
- UiElementList: helper/callee addresses 0x00485EB0 were removed from the class method list because they are not functions in this packet (methods may only name packet functions); they remain recorded as callee evidence refs and in dependencies.
- UiElementList.node_child_flag (base node offset 0x0000000C): dropped as a modeled field because the packet has no allowed evidence ref for field:node:0x0000000C; the semantic note is preserved in the class responsibility/unresolved text.
- UiTextDisplay: helper/callee addresses 0x00488180 were removed from the class method list because they are not functions in this packet (methods may only name packet functions); they remain recorded as callee evidence refs and in dependencies.
- UiTextObject: helper/callee addresses 0x00499B10 were removed from the class method list because they are not functions in this packet (methods may only name packet functions); they remain recorded as callee evidence refs and in dependencies.
- UiTextObject.sub_object_0x124 (base this offset 0x00000124): dropped as a modeled field because the packet has no allowed evidence ref for field:this:0x00000124; the semantic note is preserved in the class responsibility/unresolved text.
- UiScreenText: helper/callee addresses 0x00489920 were removed from the class method list because they are not functions in this packet (methods may only name packet functions); they remain recorded as callee evidence refs and in dependencies.
- ReplayControlsMenu: helper/callee addresses 0x00488B00, 0x00486F30 were removed from the class method list because they are not functions in this packet (methods may only name packet functions); they remain recorded as callee evidence refs and in dependencies.
- UiWidget: helper/callee addresses 0x00486710, 0x00487330, 0x00487740, 0x00486660, 0x00486320, 0x0049A460 were removed from the class method list because they are not functions in this packet (methods may only name packet functions); they remain recorded as callee evidence refs and in dependencies.
- ListBoxNode: helper/callee addresses 0x00485E30 were removed from the class method list because they are not functions in this packet (methods may only name packet functions); they remain recorded as callee evidence refs and in dependencies.
- MusicTrackSlot: helper/callee addresses 0x00406A70, 0x00595AE2, 0x0058815F, 0x0058C724 were removed from the class method list because they are not functions in this packet (methods may only name packet functions); they remain recorded as callee evidence refs and in dependencies.
- WavHeaderWriter: helper/callee addresses 0x00405670 were removed from the class method list because they are not functions in this packet (methods may only name packet functions); they remain recorded as callee evidence refs and in dependencies.
- WavHeaderWriter.output_buffer (base this offset 0x00000044): dropped as a modeled field because the packet has no allowed evidence ref for field:this:0x00000044; the semantic note is preserved in the class responsibility/unresolved text.
- WavHeaderWriter.alternate_data_size (base a2 offset 0x00000004): dropped as a modeled field because the packet has no allowed evidence ref for field:a2:0x00000004; the semantic note is preserved in the class responsibility/unresolved text.
- WavHeaderWriter.sample_rate (base a2 offset 0x00000018): dropped as a modeled field because the packet has no allowed evidence ref for field:a2:0x00000018; the semantic note is preserved in the class responsibility/unresolved text.
- WavHeaderWriter.bits_per_sample (base a2 offset 0x0000001A): dropped as a modeled field because the packet has no allowed evidence ref for field:a2:0x0000001A; the semantic note is preserved in the class responsibility/unresolved text.
- WavHeaderWriter.format_flags (base a2 offset 0x0000001B): dropped as a modeled field because the packet has no allowed evidence ref for field:a2:0x0000001B; the semantic note is preserved in the class responsibility/unresolved text.
- WavHeaderWriter.primary_data_size (base a2 offset 0x00000020): dropped as a modeled field because the packet has no allowed evidence ref for field:a2:0x00000020; the semantic note is preserved in the class responsibility/unresolved text.
- UiTextDisplay base-class abstraction was dropped: its only candidate method (0x00488180) is a callee, not a packet function. The shared base-constructor relationship (UITextDisplayConstructor 0x00488180) remains documented in UiTextObject's evidence refs and in the dependencies.
