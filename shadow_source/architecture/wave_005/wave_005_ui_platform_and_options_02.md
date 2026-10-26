# UiPlatformAndOptions

Scope: `ui_platform_and_options`  
Trust: `DERIVED`

Reconstructs the UI platform/options widget layer from 23 validated functions. One DERIVED class UIScrollList (0x0048A8D0) runs the per-frame scroll-list update (animation counter at 0x148, pixel-scroll clamp at 0x150 bounded by vtable dimension getters, forward/backward navigation dispatch via the 0x144/0x145 flag bytes). A GUESS class UIScrollWidget groups the shared scroll-input/update helpers that all dispatch the same vtable-slot family (position/bounds getters at +24/+28/+32/+36, notify at +44, state-set at +64, finalize at +152) and share the 0x144/0x145/0x146 byte flags and the 0x148 counter: 0x00488A30 (scroll-widget update), 0x0048A650 (scrollbar thumb drag handler), 0x00489530 (navigation advance), 0x0048A8A0 (widget state reset). A GUESS UITextWidget covers the text-display constructor 0x00488180, the linked-list text accessor 0x00489950 and the path-suffix format helper 0x00489970 (shared this+0xE1 output buffer and byte_5EA438 fallback). A GUESS UIActiveWidgetController covers visibility/active toggling (0x0048B91A, 0x0048BBE0) through FieldGetter_79d0/SimpleSetter_79e0 and the vtable+44 notification. Remaining GUESS classes are one-class units: UIScreenSelectionHandler (0x0048D6B0), UIWidgetDragController (0x0048DF40), UiBaseObject (base-initializer constructors 0x0048E600/0x0048FB70/0x0048D3A0 sharing ShortComputation_5e30 and the 0xE4 no-selection sentinel), MenuItem (0x0048D660), UITileGridController (0x0048F1A0), UIWidgetChildrenProcessor (0x00490450), UiSurfaceBlockParser (0x00493990), UiElement (0x004991E0), UICommandDispatcher (0x0049A5D0), UISparkleEffect (0x0049ED30), DirectoryPathBuilder (0x004B0180). No state machine is proposed: the drag/scroll state values (0, 3, 6, 7, 8, 9) and the tile-grid interaction states (2, 3, 4) are evidenced only as literals, with transition semantics not established in this packet. Class ownership of every function except UIScrollList is GUESS; only the scroll-list update carries a DERIVED owner from the packet ABI lead.

## Function roles

- `0x00488180` **UITextWidget** — UITextDisplayConstructor: constructs a UI text display object. Runs base setup ShortComputation_5e30, initializes the sub-object at this+0xE0 via sub_499B10, installs the text-display vtable off_5ABB78 at this+0x0, sets the enable/visible flag byte at this+0x114 to 1 and returns this.
- `0x00488A30` **UIScrollWidget** — UIScrollWidgetUpdate: per-frame update of a UI scroll widget. Guarded by the enable flag at this+0xEC; reads the input delta pair via DualFieldRead, dispatches virtual calls for the current position (vtable+24) and lower/upper scroll bounds (vtable+28/+36), sets the in-range flag at this+0xED when the delta lies inside the bounds, runs DeltaBasedUpdate, and when the widget is not hidden (vtable+152) dispatches the notify virtual (vtable+44, arg 1) and runs the extra widget update sub_486600.
- `0x00489530` **UIScrollWidget** — UINavigationAdvanceHandler: UI navigation-advance handler. Dispatches a virtual call through vtable entry 11 (offset 0x2C on obj) with argument 1, increments the counter at this+0x14C, then calls sub_489D00 and FloatToIntConversion. Linear, always returns 0.
- `0x00489950` **UITextWidget** — UIScreenTextAccessor_9950: screen text accessor. Traverses a linked list via LinkedListTraversalByIndex, then returns the text pointer stored at the node offset +168 when present, otherwise falls back to the global byte_5EA438; returns null when traversal yields no node.
- `0x00489970` **UITextWidget** — UITextFormatHelper: reads the text of a UI screen widget via UIScreenTextAccessor, locates the last path-delimiter (word_5C692C) occurrence in a copy of the text, skips a2 delimiter-separated components by repeatedly locating the preceding delimiter, and copies the suffix from the final delimiter position into the this+0xE1 output buffer; returns a pointer to that buffer, or 0 when the widget has no text or no delimiter is found.
- `0x0048A650` **UIScrollWidget** — UIScrollbarThumbDragHandler: scrollbar input handler. Reads the two-axis cursor position via DualFieldRead, clears the scroll-up/scroll-down/thumb-drag flags at 0x144/0x145/0x146, classifies the cursor against the scrollbar track and arrow-zone boundaries obtained through virtual getters (vtable+24/+28/+32/+36), dispatching UINavigationAdvanceHandler / StateUpdateWithDecrement / sub_4895B0 / DecrementCounterVirtualCall per zone. Outside the track, when content navigation is enabled (this+0xE0 and this+0x158), computes a target content index via sub_489F40, walks the content item linked list at this+0x90, updates displayed strings via StringReverseCopyLookup and a content-update virtual, then dispatches the state-set virtual (vtable+64) and finalize virtual (vtable+152).
- `0x0048A8A0` **UIScrollWidget** — UIWidgetStateReset: resets widget UI state. Zeros the three byte flags at this+0x144, this+0x145, this+0x146 and the dword state field this+0x148, calls the vtable method at obj+0x40 (offset 64) with argument 0 (stdcall) and the vtable method at obj+0x9C (offset 156) on this (thiscall), returning that call's result.
- `0x0048A8D0` **UIScrollList** — UIScrollListUpdate: per-frame update of a UI scroll list. Reads two fields via DualFieldRead, recomputes the animation counter at this+0x148 from the value behind this+0x40 through FunctionCallWrapper_8940, invokes the vtable refresh method at obj+0x2C with argument 1. When the byte flag at this+0x146 is set and this+0x160 > 0, clamps the pixel scroll position at this+0x150 into the range bounded by the vtable dimension getters (obj+0x1C lower, obj+0x24 upper) and this+0x15C, then calls ShortComputation_9ee0. When this+0x148 exceeds 0.25 (redundant 0.2 compare also present; flt_59E7E8/flt_59E7F8 plausibly the constant pool), dispatches DecrementCounterVirtualCall when this+0x144 is set, else UINavigationAdvanceHandler when this+0x145 is set, otherwise returns 0.
- `0x0048B91A` **UIActiveWidgetController** — UIWidgetVisibilityToggle: toggles a widget's visibility byte at a3+224 (0xE0) to a2 and asks the owning object a1 for a callback result via the function pointer at a1+44. On the show path (a2 != 0) returns that callback result directly. On the hide path it clears the active-widget reference when FieldGetter_79d0(*(a3+64)) equals a3 (via SimpleSetter_79e0), invokes the thiscall vtable method at vtable offset 176 on a3, and returns its result.
- `0x0048BBE0` **UIActiveWidgetController** — UIActiveStateToggle: toggles the active/focused state of a text-edit widget. Compares this against FieldGetter_79d0 applied to the object pointer at this+0x40. If this is the active widget and it needs activation (flag byte at this+0xE0 clear or cursor flag at this+0xE1 clear), calls SetterVTableIDCheck(this, 1) and emits a change notification via virtual slot +44 with argument 1. If this is not the active widget but both flags are set, deactivates with SetterVTableIDCheck(this, 0) and emits the same notification. Returns the widget flag byte when no state change occurs.
- `0x0048D3A0` **UiBaseObject** — UIObjectConstructorWithStoredParams: UI widget constructor. Runs base initialization (ShortComputation_5e30) and field initialization (F_5FieldInit) on the object, stores two integer parameters (a2 at this+0xF4, a3 at this+0xF8), clears the byte flags at this+0xF0 and this+0xF1, writes the vtable pointer off_5AC118 into this+0x0, and returns this.
- `0x0048D660` **MenuItem** — MenuItemConstructor: constructs a menu item. Calls the base initializer ConstructorInitVTable with literal type 1 and depth -1, installs the menu-item vtable pointer off_5AC280 into this+0x0, then calls SimpleSetter_8bc0(this, 2) to set a configuration field. Returns this.
- `0x0048D6B0` **UIScreenSelectionHandler** — UIScreenSelectionHandler: handles a UI screen selection. Retrieves the selected screen object via FieldGetterAt0x1570 applied to the object pointer at this+0x40 and caches it at this+0xEC. If non-null, reads the screen's path string (screen+192, fallback byte_5EA438), compares it through UIStringComparison, and emits a content-changed notification via virtual slot +44 with argument 1. Returns 0.
- `0x0048DF40` **UIWidgetDragController** — UIWidgetDragHandler: handles drag state transitions for a UI scroll region. Reads cursor position (x, y) via DualFieldRead and the current scroll state via ShortComputation_6720. When the cursor is inside the region bounded by this+0x10C..0x110 (x) and this+0x11C..0x120 (y): if the state is 0, 6 or 7 it invokes the vtable method at obj+0x40 (offset 64) with argument 3 (interpreted as start-drag), and if the state is 3, 8 or 9 with argument 0 (interpreted as stop-drag). Returns 0.
- `0x0048E600` **UiBaseObject** — initUiBaseStruct: initializes the base UI object. Runs the shared base initializer ShortComputation_5e30, sets the vtable pointer off_5AC540 at this+0x0, stores the no-selection sentinel -1 at this+0xE4, zeroes the dwords at 0xE0, 0xE8 and 0xEC, and copies the default directory string byte_5EA438 through StringCopyWithBufferRealloc. Returns this.
- `0x0048F1A0` **UITileGridController** — UITileGridCursorInputHandler: tile-grid cursor input handler. Skips all processing when ByteFieldGetterAt100 is non-zero. Otherwise reads the two-axis cursor position via DualFieldRead from the sub-object at this+0x40, flags the cursor acknowledged (this+0x17D), and records whether it is inside an outer pass-through rectangle (0x128..0x12C x, 0x148..0x14C y -> this+0x17E). When the interaction state at this+0x104 is not the disabled value 4, tests two hover regions (states 2 and 3, dispatching DecrementCounterWithClamp / sub_48FB30 with -1 and resetting the sub-index at 0x10C), refreshes the grid via UITileGrid, then on activation-region hit (0x120..0x124 x, 0x140..0x144 y) with a non-negative activation index this[92] stores it into this[93] and dispatches the vtable+44 virtual with argument 1. Ends by dispatching the state virtual (vtable+64) and finalize virtual (vtable+152), returning 0.
- `0x0048FB70` **UiBaseObject** — UIObjectVariantStructInit: UI-object variant initialization. Calls ShortComputation_5e30 for the base struct init, installs the off_5AC5F0 vtable pointer into this+0x0, zeroes the counter/resource field at this+0xE0, and sets the no-selection sentinel -1 at this+0xE4. Returns this.
- `0x00490450` **UIWidgetChildrenProcessor** — UIWidgetProcessChildren: processes child widgets of a UI widget. Reads the input/cursor position pair via DualFieldRead, dispatches on the state returned by ShortComputation_6720 through the jump table at 0x00490538. For states 0-2 it dispatches vtable+64 with argument 0 and runs VTableDispatchListIteration. For states 3-5 it also dispatches vtable+64 with argument 0, then, if the child count at this+0xEC is positive, walks the child linked list from the head at this+0xE0 following next pointers at node+4, and for the child whose rectangle (RectangleBoundsCheck) contains the input position dispatches vtable+64 with argument 4 (hit notification). Returns 0.
- `0x00493990` **UiSurfaceBlockParser** — ParseUiSurfaceBlock: parses one UI surface definition block from a text stream. Reads 'location' and 'poswh' tokens as integer coordinate pairs via sub_565870/CRTFtol, reads the 'surface' name token, and reads animation tokens ('animdelta' as float via sub_58850F, 'animrule' as int via sub_587ECE, 'subanimframe' as a recursive nested block). Once surface name and coordinates are present it creates the surface object through sub_499F70, then applies the parsed animation delta/rule to the created object. Tracks block nesting with the depth counter at this+0x194 (incremented on entry, decremented on exit).
- `0x004991E0` **UiElement** — UiElementConstructor: constructor for a UI element object. Runs the shared base initializer ConstructorWith1Sentinels, zeroes the index/count dword slots this[16..18] (0x40/0x44/0x48) and this[20..22]/this[24] (0x50/0x54/0x58/0x60), sets the sentinel slots this[23] and this[25] (0x5C/0x64) to -1, installs the vtable pointer off_5ACA74 at this+0x0, then registers/passes the object through sub_4992E0(a2, 1) and returns this.
- `0x0049A5D0` **UICommandDispatcher** — UICommandDispatch: dispatches UI commands on an object at a2 (whose +64 slot holds a UI/manager object). The command ID at this+0x00 selects a handler: cases 1-2 search a list by name (StringNormalizeLookup_a460 against the lookup map at object+64+5772, defaulting null strings to byte_5EA438) and apply a selection action via UtilityFunction_7890 with parameter 0 or -1; cases 3-6 do the same but apply TwoFieldSetter for this+0x14 and UtilityFunction_7890 with index 1..4; case 7 searches list items via UIListItemSearchByName and runs LinkedListSearchWithAction; case 9 copies a string pair; case 0xA runs a polling loop; case 0xB sets the global session state dword_5CC9E8 to -1 (shutdown); case 0xC builds a rendering context via RenderingContextSetup and drives vtable methods on it. Cases that name a current page write it back through StringReverseCopyLookup against the 'CurrentPage' string slot.
- `0x0049ED30` **UISparkleEffect** — UISparkleEffect: renders a 4-point sparkle/star graphic. Guards on the enabled flag at this+0x04. Reads the rotation mode (this+0x10) and current angle (this+0x14), steps the angle toward the target (this+0x18) by the speed ratio (this+0x1C)/(this+0x20) with 360-degree wraparound, converts to radians (angle * 0.01745433), computes the sparkle extent from this+0x44 and this+0x48, derives four vertex positions around the center (this+0x3C, this+0x40), and draws each vertex with sub_553650 using color-coded parameters, returning the last draw result.
- `0x004B0180` **DirectoryPathBuilder** — BuildDirectoryPath: builds a directory path string into output buffer a2 by formatting '%s%s\' with a directory prefix and input name a1. The directory prefix is dword_5EC440 when non-null, otherwise the byte_5EA438 default. Always returns 0.

## Proposed classes

### UIScrollList

Per-frame update of a UI scroll list (0x0048A8D0). Recomputes the animation counter at this+0x148 from the value behind this+0x40 via FunctionCallWrapper_8940, refreshes through the vtable+2C slot, clamps the pixel scroll position at this+0x150 into the range bounded by the vtable dimension getters and this+0x15C, then dispatches backward/forward navigation (DecrementCounterVirtualCall / UINavigationAdvanceHandler) when the counter exceeds the 0.25/0.2 threshold. Owner derived from the packet ABI lead UI_Scroll_List_Update.

Methods: `0x0048A8D0`

- `this+0x00000040` `void* scroll_timer_input` (read, GUESS)
- `this+0x00000148` `float animation_counter` (read_write, DERIVED)
- `this+0x00000146` `byte thumb_drag_flag` (read, DERIVED)
- `this+0x00000160` `dword content_size` (read, GUESS)
- `this+0x00000150` `dword pixel_scroll_position` (read_write, DERIVED)
- `this+0x0000015C` `dword thumb_size` (read, GUESS)
- `this+0x00000144` `byte scroll_up_flag` (read, DERIVED)
- `this+0x00000145` `byte scroll_down_flag` (read, DERIVED)

### UIScrollWidget

Shared scroll widget input/update cluster: per-frame update (0x00488A30), scrollbar thumb drag classification (0x0048A650), navigation advance (0x00489530) and state reset (0x0048A8A0). All four read the two-axis cursor/input pair through DualFieldRead, dispatch the scroll vtable-slot family (position/bounds getters at +24/+28/+32/+36, notify at +44, state-set at +64, finalize at +152), and manipulate the shared byte flags at 0x144/0x145/0x146 and the counter dwords at 0x148/0x14C. The thumb geometry lives at this+0x150 (thumb top) and this+0x15C (thumb size).

Methods: `0x00488A30`, `0x0048A650`, `0x00489530`, `0x0048A8A0`

- `this+0x000000EC` `byte enable_flag` (read, DERIVED)
- `this+0x000000ED` `byte in_range_flag` (read_write, DERIVED)
- `this+0x00000144` `byte scroll_up_flag` (read_write, DERIVED)
- `this+0x00000145` `byte scroll_down_flag` (read_write, DERIVED)
- `this+0x00000146` `byte thumb_drag_flag` (read_write, DERIVED)
- `this+0x00000148` `dword state_or_counter_dword` (read_write, GUESS)
- `this+0x0000014C` `dword advance_counter` (read_write, GUESS)
- `this+0x00000150` `dword thumb_top` (read, GUESS)
- `this+0x0000015C` `dword thumb_size` (read, GUESS)
- `this+0x00000010` `dword track_end_fallback` (read, GUESS)
- `this+0x00000090` `void* content_list_head` (read, GUESS)
- `this+0x000000A0` `void* content_string_slot` (read, GUESS)
- `this+0x000000E0` `byte content_navigation_enable` (read, GUESS)
- `this+0x00000158` `dword content_count` (read, GUESS)

### UITextWidget

Text display/access widget: constructor 0x00488180 (text-display vtable off_5ABB78, enable/visible flag at 0x114), linked-list text accessor 0x00489950 (node text at +168, byte_5EA438 fallback) and path-suffix format helper 0x00489970 (this+0xE1 output buffer, delimiter word_5C692C). The this+0xE1 buffer is shared between the accessor caller and the format helper output.

Methods: `0x00488180`, `0x00489950`, `0x00489970`

- `this+0x00000114` `byte enable_visible_flag` (write, DERIVED)
- `this+0x000000E1` `char[1] text_output_buffer` (read_write, GUESS)

### UIActiveWidgetController

Active/visibility state controller for widgets: visibility toggle 0x0048B91A (writes the byte at a3+224, clears the active-widget reference via FieldGetter_79d0/SimpleSetter_79e0 when it points at the widget, dispatches vtable offset 176) and active-state toggle 0x0048BBE0 (activates/deactivates a text-edit widget via SetterVTableIDCheck and the vtable+44 notification). Both consult the owning-object pointer at this+0x40.

Methods: `0x0048B91A`, `0x0048BBE0`

- `this+0x000000E0` `byte visibility_flag` (read_write, DERIVED)
- `this+0x000000E1` `byte cursor_flag` (read, GUESS)
- `this+0x00000040` `void* owner_object_ptr` (read, GUESS)
- `this+0x0000002C` `void* callback_slot` (read, GUESS)

### UIScreenSelectionHandler

UI screen-selection handling (0x0048D6B0): fetches the selected screen object via FieldGetterAt0x1570 from the owner pointer at this+0x40, caches it at this+0xEC, compares the screen path string (screen+192, byte_5EA438 fallback) through UIStringComparison, and emits the vtable+44 content-changed notification.

Methods: `0x0048D6B0`

- `this+0x00000040` `void* owner_object_ptr` (read, GUESS)
- `this+0x000000EC` `void* selected_screen_cache` (write, GUESS)

### UIWidgetDragController

Drag state transition handler for a UI scroll region (0x0048DF40): reads the cursor position via DualFieldRead and the scroll state via ShortComputation_6720, and against the region bounded by this+0x10C..0x110 (x) and this+0x11C..0x120 (y) dispatches the vtable+64 method with argument 3 (start-drag, states 0/6/7) or 0 (stop-drag, states 3/8/9).

Methods: `0x0048DF40`

- `this+0x0000010C` `dword region_x_min` (read, GUESS)
- `this+0x00000110` `dword region_x_max` (read, GUESS)
- `this+0x0000011C` `dword region_y_min` (read, GUESS)
- `this+0x00000120` `dword region_y_max` (read, GUESS)

### UiBaseObject

Base UI object construction cluster sharing the base initializer ShortComputation_5e30, the no-selection sentinel -1 at this+0xE4, and zeroed/counter dwords in the 0xE0..0xF8 region: initUiBaseStruct 0x0048E600 (vtable off_5AC540, default directory copy), UIObjectVariantStructInit 0x0048FB70 (vtable off_5AC5F0), UIObjectConstructorWithStoredParams 0x0048D3A0 (vtable off_5AC118, stored params at 0xF4/0xF8, flags at 0xF0/0xF1). Distinct vtable pointers indicate distinct concrete variants sharing a common base-layout pattern.

Methods: `0x0048E600`, `0x0048FB70`, `0x0048D3A0`

- `this+0x000000E0` `dword zeroed_or_counter` (read_write, GUESS)
- `this+0x000000E4` `dword no_selection_sentinel` (read_write, DERIVED)
- `this+0x000000E8` `dword zeroed_dword` (write, GUESS)
- `this+0x000000EC` `dword zeroed_dword_2` (write, GUESS)
- `this+0x000000F0` `byte flag_f0` (write, GUESS)
- `this+0x000000F1` `byte flag_f1` (write, GUESS)
- `this+0x000000F4` `dword stored_param_a2` (write, GUESS)
- `this+0x000000F8` `dword stored_param_a3` (write, GUESS)

### MenuItem

Menu item construction (0x0048D660): base init via ConstructorInitVTable(this, 1, -1), installs the menu-item vtable off_5AC280, and sets a configuration field to literal 2 via SimpleSetter_8bc0. Only caller evidenced is sub_493FC0.

Methods: `0x0048D660`


### UITileGridController

Tile-grid cursor input handler (0x0048F1A0): skips input when the byte getter ByteFieldGetterAt100 is non-zero; reads the cursor via DualFieldRead, flags acknowledgement (0x17D) and outer pass-through rect (0x128..0x12C x, 0x148..0x14C y -> 0x17E). Unless the interaction state at 0x104 is the disabled value 4, tests two hover regions (states 2 and 3, dispatching DecrementCounterWithClamp / sub_48FB30 with -1 and resetting the sub-index at 0x10C), refreshes the grid via UITileGrid, and on activation-region hit (0x120..0x124 x, 0x140..0x144 y) with a non-negative activation index this[92] stores it into this[93] and dispatches the vtable+44 virtual.

Methods: `0x0048F1A0`

- `this+0x00000104` `dword interaction_state` (read_write, DERIVED)
- `this+0x0000010C` `dword hover_sub_index` (read_write, GUESS)
- `this+0x00000170` `dword activation_index` (read, GUESS)
- `this+0x00000174` `dword selected_index` (write, GUESS)
- `this+0x0000017D` `byte input_acknowledged` (write, GUESS)
- `this+0x0000017E` `byte inside_outer_rect` (read_write, GUESS)

### UIWidgetChildrenProcessor

Child-widget processing (0x00490450): reads the input position via DualFieldRead, dispatches on the state from ShortComputation_6720 via the jump table at 0x00490538. States 0-2 dispatch vtable+64 with argument 0 and run VTableDispatchListIteration; states 3-5 additionally walk the child list (head at this+0xE0, next pointer at node+4) up to the child count at this+0xEC and dispatch vtable+64 with argument 4 when RectangleBoundsCheck reports a hit.

Methods: `0x00490450`

- `this+0x000000EC` `dword child_count` (read, DERIVED)
- `this+0x000000E0` `void* child_list_head` (read, DERIVED)
- `this+0x000000E4` `void* child_list_owner_ptr` (read, GUESS)
- `*(this+0xE4)+0x00000004` `void* child_next_ptr` (read, GUESS)

### UiSurfaceBlockParser

UI surface definition block parser (0x00493990): tokenizes 'location'/'poswh' coordinate pairs (sub_565870/CRTFtol), the 'surface' name, and animation tokens ('animdelta' float, 'animrule' int, 'subanimframe' recursive nested block), creates the surface object via sub_499F70 once name and coordinates are present, and applies the parsed animation delta/rule to it. Block nesting is tracked by the depth counter at this+0x194.

Methods: `0x00493990`

- `this+0x00000194` `dword block_nesting_depth` (read_write, DERIVED)

### UiElement

UI element construction (0x004991E0): runs ConstructorWith1Sentinels, zeroes the index/count slots at 0x40/0x44/0x48/0x50/0x54/0x58/0x60, sets the sentinel slots at 0x5C/0x64 to -1, installs the off_5ACA74 vtable, and registers the object via sub_4992E0(a2, 1).

Methods: `0x004991E0`

- `this+0x00000040` `dword slot_16_index` (write, GUESS)
- `this+0x00000044` `dword slot_17_index` (write, GUESS)
- `this+0x00000048` `dword slot_18_index` (write, GUESS)
- `this+0x00000050` `dword slot_20` (write, GUESS)
- `this+0x00000054` `dword slot_21` (write, GUESS)
- `this+0x00000058` `dword slot_22` (write, GUESS)
- `this+0x0000005C` `dword sentinel_23` (write, GUESS)
- `this+0x00000060` `dword slot_24` (write, GUESS)
- `this+0x00000064` `dword sentinel_25` (write, GUESS)

### UICommandDispatcher

UI command dispatch (0x0049A5D0): switch on the command ID at this+0x00. Cases 1-6 normalize a name at this+0x04 and search the UI list by name (UIListSearchByName_76c0), applying a selection action via UtilityFunction_7890 (parameter 0/-1 for cases 1-2, index 1..4 plus TwoFieldSetter on this+0x14 for cases 3-6); case 7 searches list items (UIListItemSearchByName, LinkedListSearchWithAction); case 9 copies a string pair; case 0xA polls; case 0xB sets dword_5CC9E8 to -1 (shutdown); case 0xC builds a rendering context via RenderingContextSetup and drives its vtable methods. Current-page names are written back via StringReverseCopyLookup against the 'CurrentPage' slot.

Methods: `0x0049A5D0`

- `this+0x00000000` `dword command_id` (read, DERIVED)
- `this+0x00000004` `char* name_param` (read, GUESS)
- `this+0x0000000C` `char* string_source_param` (read, GUESS)
- `this+0x00000014` `dword action_param` (read, GUESS)

### UISparkleEffect

4-point sparkle/star graphic renderer (0x0049ED30): guarded by the enabled flag at this+0x04, steps the angle this+0x14 toward the target this+0x18 by the speed ratio (this+0x1C)/(this+0x20) in clockwise (this+0x10 == 0) or counterclockwise mode with 360-degree wraparound, converts to radians, computes the sparkle extent from this+0x44/this+0x48, derives four vertex positions around the center (this+0x3C, this+0x40), and draws each with sub_553650.

Methods: `0x0049ED30`

- `this+0x00000004` `byte enabled_flag` (read, DERIVED)
- `this+0x00000010` `dword rotation_mode` (read, GUESS)
- `this+0x00000014` `float current_angle` (read_write, GUESS)
- `this+0x00000018` `float target_angle` (read, GUESS)
- `this+0x0000001C` `float speed_numerator` (read, GUESS)
- `this+0x00000020` `float speed_denominator` (read, GUESS)
- `this+0x0000003C` `dword center_x` (read, GUESS)
- `this+0x00000040` `dword center_y` (read, GUESS)
- `this+0x00000044` `float extent_dim_a` (read, GUESS)
- `this+0x00000048` `float extent_dim_b` (read, GUESS)

### DirectoryPathBuilder

Directory path builder (0x004B0180): formats '%s%s\' into output buffer a2 with the directory prefix dword_5EC440 (fallback byte_5EA438 when null) and input name a1. Always returns 0.

Methods: `0x004B0180`


## Compatibility contracts

- **UIScrollWidgetVtableSlots** — Scroll widgets dispatch a fixed vtable-slot family: position update at +24, scroll-bound getters at +28/+36, track-end getter at +32, notify at +44 (argument 1), state-set at +64 (argument 0, 1, 2 or 4), and finalize at +152 (also used as the hidden query). A replacement executable must keep these slot indices stable for the scroll widget family.
- **UiSurfaceBlockSyntax** — UI surface definition blocks are parsed token-by-token: 'location' and 'poswh' carry integer coordinate pairs (poswh combines two float pairs), 'surface' names the surface, 'animdelta' is a float, 'animrule' an int, and 'subanimframe' opens a recursively parsed nested block. Block nesting depth is tracked at this+0x194 and the open/close delimiters asc_5CC4F4/asc_5CC4F8 drive the depth counter. A replacement executable must preserve this token vocabulary and nesting rule.
- **DefaultDirectoryFallback** — Null string pointers default to the shared global byte_5EA438 across the text accessor (0x00489950), the format helper (0x00489970), the screen-selection handler (0x0048D6B0), the command dispatcher (0x0049A5D0) and the directory path builder (0x004B0180). A replacement executable should preserve this null-string fallback convention.
- **UIScrollInputFlags** — Scroll widgets carry byte flags at this+0x144 (scroll-up), 0x145 (scroll-down), 0x146 (thumb-drag) and a dword state/counter at 0x148, with an advance counter at 0x14C. The scrollbar drag classification in 0x0048A650 and the navigation dispatch in 0x0048A8D0 both depend on these offsets.
- **UICommandProtocol** — UI commands are dispatched by the ID at this+0x00: cases 1-2 select a named list entry (UtilityFunction_7890 with parameter 0/-1), cases 3-6 apply an indexed action (1..4) with TwoFieldSetter on this+0x14, case 7 searches list items, case 9 copies a string pair, case 0xA runs a polling loop, case 0xB sets dword_5CC9E8 to -1 (shutdown) and case 0xC builds a rendering context. Named current pages are written back to the 'CurrentPage' string slot.

## Unresolved

- UIScrollWidget: the concrete class identity behind the scroll vtable is not established; the grouping of 0x00488A30, 0x0048A650, 0x00489530 and 0x0048A8A0 rests on the shared vtable-slot family and the 0x144/0x145/0x146 flags plus the 0x148/0x14C counters, not on packet proof of a single class.
- UIScrollList: the mapping of the globals flt_59E7E8 / flt_59E7F8 to the inline literals 0.25 and 0.2 is inferred, not proven; the roles of the DualFieldRead outputs and this+0x40 are DERIVED from surrounding arithmetic.
- UIScrollbarThumbDragHandler (0x0048A650): sub-object fields at obj+0x40 and obj+0x98 and this offsets 0x130, 0x138, 0x140, 0x148 and 0x1A8 are listed by the extraction but not read by the raw body; their purposes are unknown.
- UIScrollWidgetUpdate (0x00488A30): the concrete implementations behind vtable slots +24/+28/+36/+44/+152 and the layout of the DualFieldRead delta pair at obj+0x2C are outside this function.
- UITextWidget: byte_5EA438 is addressed as a byte but returned as a char* text pointer; the identity/content of the fallback text is not established. The node element layout beyond offset +168 depends on the LinkedListTraversalByIndex contract.
- UITextFormatHelper (0x00489970): sub_5897CA is only identified as a delimiter locator; its behavior when its first argument is 0 (used in the skip loop) is inferred, not proven. The meaning of the this+0xE1 output buffer depends on the caller UIListManagementHandler (0x0048A3C0).
- UIActiveWidgetController: the target of the vtable +44 dispatch and the vtable offset 176 slot are indirect calls with unknown concrete targets; FieldGetter_79d0/SimpleSetter_79e0 semantics are taken from their names, not packet call contracts.
- UIWidgetVisibilityToggle (0x0048B91A): the accesses at a3+224, a3+64 and the vtable slot at *(a3)+176 appear only in the raw source with no dedicated field evidence refs (the packet lists only field:this:0x0000002C).
- UIWidgetDragController (0x0048DF40): the semantics of the state values (0, 3, 6, 7, 8, 9) and of the vtable-argument literals 3 and 0 are not established; start-drag/stop-drag is a DERIVED interpretation.
- UiBaseObject: the three constructors carry distinct vtable pointers (off_5AC540, off_5AC5F0, off_5AC118), so they are at best variants of a shared base layout, not one proven class; the meaning of the -1 sentinel at this+0xE4 and the stored parameters at 0xF4/0xF8 is unknown.
- MenuItem (0x0048D660): the meaning of the type 1 and depth -1 parameters passed to ConstructorInitVTable and the configuration field written by SimpleSetter_8bc0(this, 2) are not established.
- UITileGridController: the byte read by ByteFieldGetterAt100 has no packet field evidence ref; the meaning of the interaction states 2, 3 and 4 and of the counter operations in DecrementCounterWithClamp / sub_48FB30 is unresolved; the hover/activation region bounds (0x110..0x134, 0x118..0x13C, 0x120..0x144) are evidenced but their semantics are inferred.
- UIWidgetProcessChildren (0x00490450): vtable entry 16 (obj+0x40) is dispatched with argument 0 for non-hit paths and argument 4 for the hit notification; the concrete target and semantics live outside this function. RectangleBoundsCheck defines the meaning of the DualFieldRead position pair.
- UiSurfaceBlockParser (0x00493990): the globals flt_59E440 and unk_7CD9D8 are listed as read but do not appear in the raw body; the object created by sub_499F70 receives writes at +24 (animdelta) and +28 (animrule) that belong to the created surface object, not to this.
- UiElement (0x004991E0): the role of argument a2 passed to sub_4992E0 and what sub_4992E0 registers (element list, callback, or handle) are outside this function's evidence.
- UICommandDispatcher (0x0049A5D0): the semantic roles of TwoFieldSetter (cases 3-6), the polling loop (case 0xA) and the vtable-driven rendering-context methods (case 0xC) are caller/driver-specific; the item layout at item+52 and the lookup-map offset 5772 on ui+64 are DERIVED from this function only.
- UISparkleEffect (0x0049ED30): the globals flt_59E65C and flt_5ACB0C are recorded as referenced but do not appear in the decompiled body; the 360-degree wraparound direction is chosen by implicit float-compare flags; the exact drawing behavior of sub_553650 (quad vs line, color semantics) is unresolved.
- BuildDirectoryPath (0x004B0180): the semantic role of dword_5EC440 (settings directory) and byte_5EA438 (default directory) is DERIVED in existing analysis, not packet-confirmed; the capacity/null-termination convention of output buffer a2 is not evidenced.
- No state machine is proposed: the drag/scroll state literals (0, 3, 6, 7, 8, 9) and the tile-grid interaction states (2, 3, 4) are evidenced only as switch/comparison values; transition semantics are not established by this packet.
