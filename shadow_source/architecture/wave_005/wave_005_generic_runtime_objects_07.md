# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Reconstructs a UI-widget and container runtime layer from 30 validated functions. All constructed objects share the base initializer ShortComputation_5e30 (0x00485E30) and a common low field region (0xE0..0x1xx) of byte flags and dwords whose exact meanings are mostly unknown. A DERIVED UIObject class (0x00487ED0, 0x004883A0, 0x00488F90, 0x0048AA40, 0x00488900) and a GUESS UIWidgetBase (0x00487220) capture the constructor/field-init family; a GUESS UIStateDispatchWidget (0x00487260, 0x00487330, 0x00487760, 0x00487830, 0x00487900, 0x0048C940) models the repeated mode-selector/switch/vtable-slot dispatch pattern with subscriber notification (0x00487900). Scroll behavior splits into GUESS UIScrollList (0x00489500, 0x00489560, 0x004895B0), GUESS UIScrollArea (0x0048D740, 0x0048D850) and GUESS UIScrollCenteringList (0x0048D0D0). Linked-list ownership is captured by DERIVED UIMenuItemList (0x00489450, 0x00489480) and GUESS LinkedListPool (0x0048AAA0) and LinkedListBase (0x0048CA50), both freeing nodes through FreeWrapper_7bcf. DERIVED EditBoxWidget (0x0048B420) and GUESS NetCommObject (0x004893C0) round out the owned objects. Seven functions keep UNKNOWN owners (0x00486AA0, 0x00487200, 0x00487210, 0x00487E70, 0x00489940, 0x0048D740 is grouped, 0x0048E070). One mode-dispatch state machine and two vtable-slot interfaces are proposed as GUESS. Field semantics are poorly evidenced; most named fields are identified only by write/read pattern, not meaning.

## Function roles

- `0x00486AA0` **UnknownObject** — Guard-gated dispatch accessor: when the guard flag at this+0x40 is non-zero, forwards argument a2 to LookupDispatch (0x00497940) with sentinel -1 and returns its result; otherwise returns -1 immediately. Callers GameMode (0x0046D6D0) and sub_46FC30 supply the guarded object and key; the caller-side semantic of the guard flag is unestablished.
- `0x00487200` **UnknownObject** — __thiscall forwarding thunk: delegates to sub_4870E0(this, 0) and returns its result unchanged; constant second argument selects index 0 in the shared lookup routine.
- `0x00487210` **UnknownObject** — __thiscall forwarding thunk: delegates to sub_4870E0(this, 1) and returns its result unchanged; constant second argument selects index 1 in the shared lookup routine.
- `0x00487220` **UIWidgetBase** — Widget-base constructor: runs base setup ShortComputation_5e30, stores byte parameters a2 and a3 at this+0xE0 and this+0xE1, installs the WidgetBase vtable off_5AB968 at this+0x0, returns this. Called by eleven construction sites (0x0046D5F0, 0x0046D680, 0x0046DD10, 0x0046F610, 0x0046F890, 0x0046FCF9, 0x00474FF0, 0x0047F440, 0x0048D740, 0x0048E300, 0x00493FC0).
- `0x00487260` **UIStateDispatchWidget** — State-dependent dispatcher: computes a mode via ShortComputation_6720 and switches on it (jump table jpt_48726F, global 0x00487310). Each case conditionally forwards boolean a2 through vtable slot +0x40 with a literal parameter (1/0/3/2 for cases 0-3); case 4 gates on ByteFieldGetterAt100 and a RangeCheck branch selecting parameter (a2!=0) or (a2!=0)+2. Default returns the selector unchanged. Callers 0x00487460, 0x00487530, 0x00487D70, 0x00487E10.
- `0x00487330` **UIStateDispatchWidget** — State-dependent vtable dispatch for a UI widget: reads a mode 0-4 via ShortComputation_6720 and maps boolean a2 to an argument (2/3/0/1 for cases 0-3, guarded on a2 set/clear) for a virtual method at vtable offset 64; case 4 gates on ByteFieldGetterAt100 and selects argument via ShortComputation_7720. Default returns the mode unchanged. Called by UIWidgetPropagateState (0x0048741B).
- `0x00487760` **UIStateDispatchWidget** — State-dependent vtable dispatch for a UI control: reads a mode 0-4 via ShortComputation_6720 and maps boolean a2 to an argument (1/0/3/2 for cases 0-3) for a virtual method at offset 64; case 4 gates on ByteFieldGetterAt100 and selects argument 0/1 or 2/3 based on RangeCheck. Default returns the mode unchanged. Callers UIControlStateChangeHandler (0x00487960) and InitDispatchWithVTableCheck (0x004879E0).
- `0x00487830` **UIStateDispatchWidget** — State-machine dispatch with boolean input: computes a state 0-4 via ShortComputation_6720 and switches (jump table jpt_48783E, global 0x004878E0). States 0-1 fire a vtable+64 __thiscall with argument 2/3 only when a2 is non-zero; states 2-3 fire with argument 0/1 only when a2 is zero. Case 4 guards on ByteFieldGetterAt100 and uses ShortComputation_7720 to pick between two vtable+64 argument mappings. Default returns the raw state without a virtual call.
- `0x00487900` **UIStateDispatchWidget** — UI state-change handler with subscriber notification: compares incoming state byte a2 against the current UI state via ByteFieldGetterAt100 (state byte at obj+0x2C); when different, fires a vtable+44 notification with argument 1. Unconditionally dispatches StateChangeNotification (0x00486660), then activates (vtable+64 with 4) when a2 is non-zero, or deactivates via RangeCheck (0x00487740) + ConditionalStateMachineDispatch (0x00487830) when zero. Finally walks a subscriber linked list headed at this+0x90, invoking each node's vtable+56 with a2 and advancing via StructFieldAccessor (node +0x38).
- `0x00487E70` **UnknownObject** — Multi-stage validated vtable dispatch: reads two DWORD values via DualFieldRead (0x00498880) from the object pointer at this+0x40. Requires UIValueValidator (0x004874E0) non-zero, a vtable offset 48 __thiscall returning non-zero, and a vtable offset 156 __thiscall returning zero. On any failure returns -1; on success calls LinkedListTraversalWithCallback (0x00486630) and returns 0.
- `0x00487ED0` **UIObject** — UI-object style initializer: calls ShortComputation_5e30, stores byte flags a2/a3 at this+0xE0/0xE1, installs the UIObject vtable off_5ABAC8 at this+0x0, zeroes the dword at this+0x84, returns this. Callers 0x00467720 and 0x00493FC0.
- `0x004883A0` **UIObject** — Field initializer on an unknown UI-related object: zeroes three dwords at 0xE0/0xE4/0xE8, sets the byte at 0xEC to 1 and the byte at 0xED to 0, returns 0. No calls or globals. Called from UI construction/dispatch paths (0x0048D3A0, 0x0047A260).
- `0x00488900` **UIObject** — Delta-based update of a widget-like object: reads a two-field input via DualFieldRead, samples the current value through vtable method +24, then when the flag byte at this+0xED is set computes the delta between the DualFieldRead value and the sampled value, compares it against the stored delta at this+0xE0, and on change stores it, recomputes layout via ShortComputation_8970 (0x00488970) and notifies via vtable method +44 with argument 1. Vtable slots +28 and +36 are invoked with results ignored.
- `0x00488F90` **UIObject** — Thiscall constructor fragment: calls the shared zero-initialization helper ShortComputation_5e30, stores global off_5ABCD0 into the vtable pointer at this+0x0, sets the byte flag at this+0xE4 to 1, returns this. Called by UIMenuItemCreator.
- `0x004893C0` **NetCommObject** — Object constructor/initializer for a network-communication object: runs ShortComputation_5e30, zeroes a block of state fields (bytes +0x144..0x146, dwords +0x134..0x13C, +0x148, +0x158, +0x160..0x16C), installs vtable off_5ABD78 at +0, then sets +0x131=1 and +0xE0=1 (enabled flags), +0x140=5 (config value), +0x168=-1 and +0x170=-1 (invalid sentinels). Returns this.
- `0x00489450` **UIMenuItemList** — Returns the node at index this+0x168 of a linked list whose head is at this+0x90, following each node's next pointer at +0x8C (head-view field at this+0x11C). Negative index returns null immediately; index past the end returns null. Callers UIScreenTextAccessor (0x00489920) and UIScreenTextAccessor_9950 (0x00489950).
- `0x00489480` **UIMenuItemList** — Pops entries from the front of a linked list (head at this+0x90, count at this+0x94): removes count - index items (index read from this+0x170), advancing the head to each node's next pointer (node + 0x8C, the head-view field at this+0x11C) and invoking each removed node's destructor through its vtable at node+0x0. Skips entirely when index < 0 or count <= index. Called by UIMenuItemCreator (0x00489600).
- `0x00489500` **UIScrollList** — UI scroll/selection index decrement: dispatches the virtual notification slot at vtable offset 0x2C with argument 1, decrements the selection counter at this+0x14C, refreshes list state via sub_489D00 and converts the internal float position via FloatToIntConversion (0x00489E90). Always returns 0. Called by UIScrollbarThumbDragHandler (0x0048A650) and UIScrollListUpdate (0x0048A8D0).
- `0x00489560` **UIScrollList** — State update with decrement: invokes the virtual notification callback at obj+0x2C (vtable slot +44) with argument 1, decrements the counter at this+0x14C by the step at this+0x164, clamps it to a minimum of 0, then refreshes via sub_489D00 and FloatToIntConversion. Always returns 0. Called by UIScrollbarThumbDragHandler (0x0048A650).
- `0x004895B0` **UIScrollList** — Selection index add with clamp: increments the counter at this+0x14C by the step at this+0x164, clamps it to the ceiling at this+0x160, emits a change notification through virtual slot +44 with argument 1, then refreshes via sub_489D00 and FloatToIntConversion. Returns 0. Called by UIScrollbarThumbDragHandler (0x0048A650).
- `0x00489940` **UnknownObject** — Field getter: returns the dword at offset 0x168 of the __thiscall receiver with no side effects. Callers are UI and multiplayer/session handlers (0x0046B0C0 key binding UI, 0x0046DD30 password validation, 0x0046DE10 session join); the read field is likely a per-session or per-UI flag/value but its meaning is unknown here.
- `0x0048AA40` **UIObject** — Object constructor: delegates to ConstructorInitVTable (0x00488B00) with parameters 1 and -1, zeroes eight consecutive DWORD fields at 0xEC..0x108 and the two byte flags at 0x10C/0x10D, then installs the final vtable off_5ABE28 at offset 0x0. Returns this. Called by sub_493FC0.
- `0x0048AAA0` **LinkedListPool** — __thiscall destructor for a pooled linked-list object: walks the node chain from the pool head at 0xEC, and for each node frees its data pointer (and, when the node flag byte at node+8 is set, the inner data chain via the node data first field) before freeing the node struct via FreeWrapper_7bcf. Afterwards zeroes pool fields 0xEC/0xF0/0xF4/0xF8 and reinitializes the object via ConstructorWithVTableSet (0x00488B30). Frees the object itself when flag a2 bit 0 is set.
- `0x0048B420` **EditBoxWidget** — Edit-box widget constructor: calls the base widget initializer (ShortComputation_5e30), assigns the edit-box vtable off_5ABED0, selects a string buffer (external a2 or inline fallback at this+0xE6), stores the buffer pointer at this+0x2F0, runs sub_48B4F0, optionally applies a length bound via BoundedFieldSetter (0x0048B8F0), zeroes a counter at this+0x2FC, copies initial text a3 into the selected buffer and a second buffer at this+0x1E7 when it fits, and stores option flags a5/a7 at this+0xE2/0xE5 and the bound a6 at this+0x2E8. Returns this.
- `0x0048C940` **UIStateDispatchWidget** — State-dependent dispatch: if ByteFieldGetterAt100 returns non-zero, calls vtable entry 16 (offset 0x40) with argument 5; otherwise, if ShortComputation_6720 returns 5, calls vtable entry 16 with argument 0. Vtable entry 43 (offset 0xAC) is always called afterward on both paths. Returns 0 on both paths.
- `0x0048CA50` **LinkedListBase** — Linked-list teardown: swaps in the temporary vtable off_5AC048, walks the node list whose head is this+0x31C calling each non-terminal node's vtable destructor (node active-flag byte at +0xC non-zero and node vtable non-null), frees every node with FreeWrapper_7bcf, zeroes the four list bookkeeping fields at this+0x31C/0x320/0x324/0x328, and finishes by re-running VTableInit on this. Callers LinkedListDestroyAt0x444 (0x0047FBD0) and DestructorWithConditionalFree_ca30 (0x0048CA30).
- `0x0048D0D0` **UIScrollCenteringList** — Computes the list item index that should be centered in the visible area: visible range from vtable slots 6 and 8 (obj+0x18/obj+0x20), center as range midpoint plus start bound, DualFieldRead reads a position pair from the pointer at this+0x40, scroll target is the wrapped/accumulated position at this+0x334 divided by the per-item step this+0x328, clamped to [0, this+0x32C-1]. Steps one-by-one toward the target via vtable slot 46 (obj+0xB8) until this+0x338 is reached. Returns 0.
- `0x0048D740` **UIScrollArea** — Constructor for a UI object (likely a scroll area): delegates base initialization to ConstructorWithByteParams(this, 0, 0), zeroes sixteen consecutive dword fields this+0xE8..this+0x124, installs the vtable off_5AC328 at offset 0x0, returns this.
- `0x0048D850` **UIScrollArea** — Per-frame update of a UI scroll area's auto-scroll behavior: reads the current scroll state enum via ShortComputation_6720 and the cursor position via DualFieldRead, then dispatches a scroll command through the vtable scroll-command slot (obj+0x40) based on which region the cursor occupies. Up-scroll states (0/6/7) and down-scroll states (3/8/9) use opposing threshold sets (this+0x108/0x10C/0x110/0x118/0x11C/0x120); states 4 and 5 drive an auto-scroll counter (this+0x100, against this+0xF8 size and geometry via ShortComputation_adb0 on this+0xC8). Every path ends by invoking the vtable refresh slot (obj+0xA8) and returning 0. Jump tables at 0x0048D9B8/0x0048D9C4.
- `0x0048E070` **UnknownObject** — Constructor-style initializer: runs the shared base initializer ShortComputation_5e30, sets the vtable pointer at offset 0 to off_5AC3E0, zeroes the dwords at 0xE0/0xE4/0xE8, sets a -1 sentinel at 0xEC, and calls StringCopyWithBufferRealloc (0x00566650) with a null argument (string reset). Returns this. Callers FunctionCallWrapper_8bc0 (0x00478BC0) and sub_493FC0.

## Proposed classes

### UIObject

Base UI object family sharing the constructor/field-init pattern: base setup via ShortComputation_5e30, vtable installed at 0x0, byte flags at 0xE0/0xE1/0xE4, dwords at 0xE8..0x108 and byte flags at 0x10C/0x10D, with a delta/flag region at 0xE0/0xED used by the delta-based update. Different instances install different vtables (off_5ABAC8, off_5ABCD0, off_5ABE28), so this likely spans several closely related widget classes with a shared field region. Method 0x004883A0 is DERIVED-owned UIObject in the packet; the other four methods are grouped on matching layout.

Methods: `0x00487ED0`, `0x004883A0`, `0x00488F90`, `0x0048AA40`, `0x00488900`

- `this+0x00000000` `void* vtable_ptr` (read_write, GUESS)
- `this+0x00000084` `dword zeroed_dword_84` (write, GUESS)
- `this+0x000000E0` `byte byte_param_e0` (read_write, GUESS)
- `this+0x000000E1` `byte byte_param_e1` (read_write, GUESS)
- `this+0x000000E4` `byte byte_flag_e4` (read_write, GUESS)
- `this+0x000000E8` `dword dword_e8` (read_write, GUESS)
- `this+0x000000EC` `dword dword_ec` (read_write, GUESS)
- `this+0x000000ED` `byte byte_flag_ed` (read, GUESS)
- `this+0x000000F0` `dword zeroed_region_f0` (write, GUESS)
- `this+0x000000F4` `dword zeroed_region_f4` (write, GUESS)
- `this+0x000000F8` `dword zeroed_region_f8` (write, GUESS)
- `this+0x000000FC` `dword zeroed_region_fc` (write, GUESS)
- `this+0x00000100` `dword zeroed_region_100` (write, GUESS)
- `this+0x00000104` `dword zeroed_region_104` (write, GUESS)
- `this+0x00000108` `dword zeroed_region_108` (write, GUESS)
- `this+0x0000010C` `byte byte_flag_10c` (write, GUESS)
- `this+0x0000010D` `byte byte_flag_10d` (write, GUESS)
- `obj+0x00000018` `void* vtable_get_value_slot` (read, GUESS)
- `obj+0x0000001C` `void* vtable_slot_28` (read, GUESS)
- `obj+0x00000024` `void* vtable_slot_36` (read, GUESS)
- `obj+0x0000002C` `void* vtable_notify_slot` (read, GUESS)

### UIWidgetBase

Base widget constructor (0x00487220): runs ShortComputation_5e30, stores two byte parameters at 0xE0/0xE1, installs the WidgetBase vtable off_5AB968. Shared by eleven construction sites across the UI layer.

Methods: `0x00487220`

- `this+0x00000000` `void* vtable_ptr` (read_write, GUESS)
- `this+0x000000E0` `byte byte_param_e0` (write, GUESS)
- `this+0x000000E1` `byte byte_param_e1` (write, GUESS)

### UIStateDispatchWidget

State-dependent vtable dispatch widget/control family: computes a mode 0-4 via ShortComputation_6720, switches via a per-function jump table, and conditionally dispatches a virtual method at vtable offset 64 (obj+0x40) with a small argument chosen from the boolean input a2; case 4 gates on ByteFieldGetterAt100 and a secondary RangeCheck/ShortComputation_7720 branch. One method (0x00487900) additionally notifies a subscriber linked list at this+0x90. Mode-to-argument mapping differs slightly per method (widget vs control vs radio variants), so this may be a family of near-identical classes rather than one class.

Methods: `0x00487260`, `0x00487330`, `0x00487760`, `0x00487830`, `0x00487900`, `0x0048C940`

- `this+0x00000000` `void* vtable_ptr` (read_write, GUESS)
- `this+0x00000090` `void* subscriber_list_head` (read, GUESS)
- `*(this+0x90)+0x00000000` `void* subscriber_node_vtable` (read, GUESS)
- `*(*(this+0x90)+0x0)+0x00000038` `void* subscriber_node_next` (read, GUESS)
- `obj+0x0000002C` `void* vtable_notify_slot` (read, GUESS)
- `obj+0x00000040` `void* vtable_state_dispatch_slot` (read, GUESS)
- `obj+0x000000AC` `void* vtable_query_slot` (read, GUESS)

### UIScrollList

Scroll-list selection object: selection counter at 0x14C adjusted by the step at 0x164 (and ceiling at 0x160), each change dispatched through vtable notify slot +44 with argument 1, followed by sub_489D00 refresh and FloatToIntConversion. Methods 0x00489500, 0x00489560, 0x004895B0 implement decrement/decrement-with-clamp/add-with-clamp; all return 0.

Methods: `0x00489500`, `0x00489560`, `0x004895B0`

- `this+0x00000000` `void* vtable_ptr` (read, GUESS)
- `this+0x0000014C` `dword selection_counter` (read_write, GUESS)
- `this+0x00000160` `dword selection_ceiling` (read, GUESS)
- `this+0x00000164` `dword selection_step` (read, GUESS)
- `obj+0x0000002C` `void* vtable_notify_slot` (read, GUESS)

### UIScrollArea

UI scroll-area object: constructor 0x0048D740 zeros the 0xE8..0x124 dword region and installs vtable off_5AC328 via the WidgetBase constructor; per-frame auto-scroll 0x0048D850 reads the scroll state enum and cursor position, dispatches scroll commands through the vtable scroll-command slot (obj+0x40), drives an auto-scroll counter at 0x100 against the area size at 0xF8 and geometry computed from 0xC8, using threshold fields at 0x108..0x120. Refresh goes through the vtable refresh slot (obj+0xA8).

Methods: `0x0048D740`, `0x0048D850`

- `this+0x00000000` `void* vtable_ptr` (read_write, GUESS)
- `this+0x000000C8` `dword geometry_source` (read, GUESS)
- `this+0x000000F8` `dword scroll_area_size` (read, GUESS)
- `this+0x00000100` `dword auto_scroll_counter` (read_write, GUESS)
- `this+0x00000108` `dword scroll_region_108` (read, GUESS)
- `this+0x0000010C` `dword scroll_region_10c` (read, GUESS)
- `this+0x00000110` `dword scroll_region_110` (read, GUESS)
- `this+0x00000118` `dword scroll_inner_top` (read, GUESS)
- `this+0x0000011C` `dword scroll_inner_bottom` (read, GUESS)
- `this+0x00000120` `dword scroll_outer_limit` (read, GUESS)
- `obj+0x00000040` `void* vtable_scroll_command_slot` (read, GUESS)
- `obj+0x000000A8` `void* vtable_refresh_slot` (read, GUESS)

### UIScrollCenteringList

Scrollable list centering logic (0x0048D0D0): computes the item index to center from visible-range vtable slots 6/8, a DualFieldRead position pair at this+0x40, the accumulated scroll position at 0x334, per-item step at 0x328 and item count at 0x32C, then steps toward the target via vtable slot 46 until the current index at 0x338 matches.

Methods: `0x0048D0D0`

- `this+0x00000000` `void* vtable_ptr` (read, GUESS)
- `this+0x00000040` `void* position_source_ptr` (read, GUESS)
- `this+0x00000328` `dword item_step` (read, GUESS)
- `this+0x0000032C` `dword item_count` (read, GUESS)
- `this+0x00000334` `dword scroll_position` (read_write, GUESS)
- `this+0x00000338` `dword current_index` (read_write, GUESS)
- `obj+0x00000018` `void* vtable_start_bound_slot` (read, GUESS)
- `obj+0x00000020` `void* vtable_end_bound_slot` (read, GUESS)
- `obj+0x000000B8` `void* vtable_step_callback_slot` (read, GUESS)

### UIMenuItemList

Menu-item linked list: head at 0x90, count at 0x94, keep-indexes at 0x168/0x170, head-view node-next field at 0x11C. Method 0x00489480 pops count-index entries from the front (invoking each node's vtable destructor) and is DERIVED-owned UIMenuItemList in the packet; 0x00489450 walks the same layout to return the node at index 0x168.

Methods: `0x00489450`, `0x00489480`

- `this+0x00000090` `void* list_head` (read_write, GUESS)
- `this+0x00000094` `dword list_count` (read_write, GUESS)
- `this+0x00000168` `dword index_168` (read, GUESS)
- `this+0x00000170` `dword index_170` (read, GUESS)
- `this+0x0000011C` `void* head_view_node_next` (read, GUESS)
- `*(this+0x90)+0x00000000` `void* node_vtable` (read, GUESS)
- `*(this+0x11C)+0x0000008C` `void* node_next` (read, GUESS)

### LinkedListPool

Pooled linked-list object: pool head at 0xEC, bookkeeping at 0xF0/0xF4/0xF8, nodes with data pointer at node+0, next pointer at node+4 (unevidenced in the field set), deep-free flag byte at node+8, and inner data first field at data+0. Destructor 0x0048AAA0 frees each node chain through FreeWrapper_7bcf then reinitializes via ConstructorWithVTableSet.

Methods: `0x0048AAA0`

- `this+0x000000EC` `void* pool_head` (read_write, GUESS)
- `this+0x000000F0` `dword pool_bookkeeping_f0` (write, GUESS)
- `this+0x000000F4` `dword pool_bookkeeping_f4` (write, GUESS)
- `this+0x000000F8` `dword pool_bookkeeping_f8` (write, GUESS)
- `*(this+0xEC)+0x00000000` `void* node_data_ptr` (read, GUESS)
- `*(this+0xEC)+0x00000008` `byte node_deep_free_flag` (read, GUESS)
- `*(*(this+0xEC)+0x0)+0x00000000` `void* node_data_first_field` (read, GUESS)
- `*(*(this+0xEC)+0x4)+0x00000004` `void* node_data_plus_4` (read, GUESS)

### LinkedListBase

Generic linked-list object: list head at 0x31C with three bookkeeping dwords at 0x320/0x324/0x328. Nodes carry a vtable pointer at +0, next pointer at +4, and an active-flag byte at +0xC; the node vtable's first entry is the destructor. Destructor 0x0048CA50 swaps in a temporary vtable, walks and frees the chain through FreeWrapper_7bcf, zeroes bookkeeping, and restores the vtable via VTableInit.

Methods: `0x0048CA50`

- `this+0x00000000` `void* vtable_ptr` (read_write, GUESS)
- `this+0x0000031C` `void* list_head` (read_write, GUESS)
- `this+0x00000320` `dword list_bookkeeping_320` (write, GUESS)
- `this+0x00000324` `dword list_bookkeeping_324` (write, GUESS)
- `this+0x00000328` `dword list_bookkeeping_328` (write, GUESS)
- `*(this+0x31C)+0x00000000` `void* node_vtable_ptr` (read, GUESS)
- `*(this+0x31C)+0x0000000C` `byte node_active_flag` (read, GUESS)
- `*(*(this+0x31C)+0x4)+0x00000004` `void* node_next` (read, GUESS)
- `*(*(this+0x31C)+0x0)+0x00000000` `void* node_vtable_destructor_slot` (read, GUESS)
- `*(*(*(this+0x31C)+0x0)+0x0)+0x00000000` `void* node_destructor_entry` (read, GUESS)

### EditBoxWidget

Edit-box widget (DERIVED from the packet): constructor 0x0048B420 installs vtable off_5ABED0, selects an external or inline string buffer, applies an optional length bound, zeroes a counter at 0x2FC, copies the initial text into two buffers, and stores option flags at 0xE2/0xE5 and the bound value at 0x2E8.

Methods: `0x0048B420`

- `this+0x00000000` `void* vtable_ptr` (read_write, GUESS)
- `this+0x000000E2` `byte option_flag_e2` (write, GUESS)
- `this+0x000000E5` `byte option_flag_e5` (write, GUESS)
- `this+0x000002E8` `dword bound_value` (write, GUESS)
- `this+0x000002F0` `char* string_buffer_ptr` (read_write, GUESS)
- `this+0x000002FC` `dword counter_2fc` (write, GUESS)

### NetCommObject

Network-communication object (GUESS): constructor/initializer 0x004893C0 installs vtable off_5ABD78, zeroes a state block (bytes 0x144..0x146, dwords 0x134..0x13C, 0x148, 0x158, 0x160..0x16C), sets enabled flags at 0xE0/0x131, config value 5 at 0x140, and invalid sentinels -1 at 0x168/0x170. Semantic roles are unproven.

Methods: `0x004893C0`

- `this+0x00000000` `void* vtable_ptr` (read_write, GUESS)
- `this+0x000000E0` `byte enabled_flag_e0` (write, GUESS)
- `this+0x00000131` `byte enabled_flag_131` (write, GUESS)
- `this+0x00000134` `dword state_134` (write, GUESS)
- `this+0x00000138` `dword state_138` (write, GUESS)
- `this+0x0000013C` `dword state_13c` (write, GUESS)
- `this+0x00000140` `dword config_value_140` (write, GUESS)
- `this+0x00000144` `byte byte_144` (write, GUESS)
- `this+0x00000145` `byte byte_145` (write, GUESS)
- `this+0x00000146` `byte byte_146` (write, GUESS)
- `this+0x00000148` `dword state_148` (write, GUESS)
- `this+0x00000158` `dword state_158` (write, GUESS)
- `this+0x00000160` `dword state_160` (write, GUESS)
- `this+0x00000164` `dword state_164` (write, GUESS)
- `this+0x00000168` `dword sentinel_168` (write, GUESS)
- `this+0x0000016C` `dword state_16c` (write, GUESS)
- `this+0x00000170` `dword sentinel_170` (write, GUESS)

## Compatibility contracts

- **SharedBaseObjectInit** — Objects built in this layer run the shared base initializer ShortComputation_5e30(this) first, then install a vtable at +0 and initialize the low field region (byte flags at 0xE0/0xE1/0xE4, dwords from 0xE8 upward, flags at 0xEC/0xED/0x10C/0x10D). A replacement executable must reproduce this init order and the common field region layout across the widget hierarchy.
- **VtableSlot44ChangeNotification** — Across the UI family, vtable slot +44 (obj+0x2C) is invoked as a change/notification callback with a small integer argument (typically 1) after a state or counter change. A replacement must keep a callable slot at vtable offset 0x2C accepting an integer argument.
- **VtableSlot64CheckedStateMapping** — Vtable slot +64 (obj+0x40) receives a small integer argument (0-3, or 4/5 in specific handlers) encoding a checked/unchecked state mapping chosen from a boolean input; the mode dispatchers compute the argument per switch case. A replacement must expose a slot at vtable offset 0x40 callable with such integer arguments.
- **ScalarDeletingDestructorFlagBit0** — Linked-list/pool destructors interpret the low bit of the deleting argument: when set, the object memory is freed through FreeWrapper_7bcf after the destructor body runs. Observed in LinkedListPool (0x0048AAA0) and LinkedListBase (0x0048CA50).
- **ListItemDestructorViaVtable** — Linked-list nodes in this layer expose their destructor as the first vtable entry (node+0), and teardown walks the chain freeing each node through the shared free wrapper. The menu-item list removes count-index entries from the head when index >= 0. A replacement must preserve node destructor dispatch through the node vtable first entry.

## Unresolved

- Owners of 0x00486AA0, 0x00487200, 0x00487210, 0x00487E70, 0x00489940 and 0x0048E070 are not established; they are kept unowned (UnknownObject).
- The vtable slot +64 and +44 targets and the semantics of their integer arguments (0-3, 4, 5) are not identified; the mode-to-argument mapping differs slightly per dispatcher, suggesting a family of near-identical classes rather than one.
- The mode selector ShortComputation_6720 and state-byte reader ByteFieldGetterAt100 are external helpers; the effective input of ShortComputation_6720 in 0x0048C940 is an uninitialized decompiler variable.
- Subscriber node structure at this+0x90 (0x00487900): node field +0 doubles as vtable/header and traversal advances via +0x38; node type unknown.
- DualFieldRead (0x00498880) contract (what the two returned values mean) is not established; its call sites pass the pointer at this+0x40.
- The zeroed field regions (0xE8..0x124 in the scroll area, 0xEC..0x10D in the UIObject ctor, 0x134..0x16C in NetCommObject) have unknown semantic roles.
- Scroll command values 0/3/6/7/8/9 encode direction and speed but their exact visual effects are unverified.
- VTableInit called at the end of 0x0048CA50 has no target address in the packet; the temporary teardown vtable off_5AC048 and the restored vtable class are inferred only.
- Pool node next-pointer field at node+4 is not present in the packet field evidence set; the walk advances via that offset on source:raw evidence only.
- The doubled write of the four list bookkeeping fields in 0x0048CA50 is unexplained.
- Semantics of the two byte parameters (0xE0/0xE1) and option flags (0xE2/0xE5) stored by the constructors are unknown.
- NetCommObject field roles and the identity of vtable off_5ABD78 are DERIVED from skeleton analysis, not packet-confirmed.
- Purpose of the string buffer duplication at this+0x1E7 in the edit-box constructor and the second DualFieldRead output in delta-based updates are unknown.
