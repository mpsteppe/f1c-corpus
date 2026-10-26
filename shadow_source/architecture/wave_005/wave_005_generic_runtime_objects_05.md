# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

This packet groups 29 generic runtime-object functions. The strongest evidence clusters are: (1) a ServerSessionManager whose single method appends formatted server open/close notifications to an embedded debug-log linked list; (2) a network-session client that starts internet/LAN updates, forwards a network-system pointer at obj+0x1B79C, and sends host join requests; (3) a per-frame GameObject with timer-driven expiry and two flag-gated physics sub-updates; (4) an AnimationFrameTimer accumulator; (5) a UIElement constructor family sharing the sub_48C070 base initializer and the +0x31C/+0x320 data-table fields; (6) a UIMenuScreen family that cleans UI state and rebuilds menu items, including from the module callback table dword_7C73E0; (7) a LinkedListContainer with an embedded singly linked list; (8) a SeasonDatabaseObject constructor family produced by SeasonDatabaseObjectFactory (0x0047F440); (9) a ProfileListManager checking profile-name uniqueness; (10) a UIScreenTextBinding pair reaching screen text through vtable slot +0x1C; and (11) a UIRenderNode destructor. Most class owners are UNKNOWN in the packet; grouping is a GUESS-level proposal grounded in shared base initializers, shared vtables, shared field access at identical base+offset, and shared callees.

## Function roles

- `0x00461190` **ServerSessionManager** — Server track open/close notification: selects opened/closed verb, stores session state, and appends a formatted message to the embedded debug-log linked list
- `0x00461DE0` **NetworkSessionClient** — Network session startup dispatcher: capability query, display-mode init, then internet (mode 1) or LAN port-range init with dev-log messages
- `0x00461F70` **NetworkSessionClient** — Conditional forwarding of the network-system pointer at obj+0x1B79C to sub_563410 when non-null, else pass-through
- `0x00462140` **UnknownObject** — Test-and-clear of the global refresh flag byte_7CD2A0; each set flag consumed exactly once by the poller
- `0x00462C00` **NetworkSessionClient** — Send multiplayer join request: bounds-checked session entry lookup, host:port formatting, dev-log, join-flag reset, delegate send
- `0x00463DC0` **UnknownObject** — Strided element pointer validity probe: computes base + 872*a2 + 16768, checks via FloatComparisonCheck, returns element data pointer or null
- `0x00464B10` **UnknownObject** — Apply SaturatedByteAdd to all 104 byte elements of the this array, returning the last result
- `0x004661B0` **GameObject** — Per-frame game-object update: tracking-list registration, timer countdown with expiry transition and vtable callback, two physics sub-updates, two trailing vtable callbacks
- `0x00466250` **GameObject** — Unconditional setter: FieldSetterCall(sub-object, 3) and flag byte this+0xF4 = 1
- `0x00466270` **GameObject** — Unconditional setter: FieldSetterCall(sub-object, 3) and flag byte this+0xF5 = 1
- `0x00466290` **GameObject** — Clear both flag bytes this+0xF4 and this+0xF5 and run FieldSetterCall(sub-object, 2)
- `0x00467260` **UIElement** — Constructor: base init, install vtable off_59F4F8, store index +0x324, derive 64-byte-strided data-table pointer +0x320, init +0x31C/+0x328/+0x32C, clear +0x305
- `0x004672C0` **UIElement** — Constructor: base init, install vtable off_59F4F8, derive grid-indexed data-table pointer +0x320 (a3 + 11*a2 cells), store grid coordinates, init +0x324 to 55
- `0x004674E0` **UIMenuScreen** — Menu command dispatcher: after state cleanup, switch on command id at +0x174 (446-458) building formatted or message menu items, or jumping through a static jump table
- `0x004677E0` **LinkedListContainer** — Destructor: walk and free the embedded singly linked list (two-level node data), clear head/tail/count/capacity, vtable cleanup, optional self-free
- `0x004685B0` **SeasonDatabaseObject** — Constructor: base init sub_4893C0, zero command/state +0x174, -1 sentinel at +0x178, install vtable off_59F718, reset byte via ByteSetterAt0xe0
- `0x00469550` **ProfileListManager** — Profile-name uniqueness check: iterate profile filename linked list, compare against candidate, special-case the PlayerNameNever string
- `0x00469DD0` **AnimationFrameTimer** — Accumulate per-frame delta time and advance an animation frame counter by 2 on the 2.0 threshold, wrapping at dword_7D2DCC, then fire a vtable callback
- `0x0046A220` **SeasonDatabaseObject** — Constructor: shared base init sub_48C9F0, zero +0x344/+0x348, -1 sentinel at +0x34C, install vtable off_59F878
- `0x0046A4E0` **SeasonDatabaseObject** — Constructor: base init sub_4893C0, zero +0x174, -1 sentinel at +0x178, install vtable off_59F938, clear byte at +0xE0 via ByteSetterAt0xe0
- `0x0046A900` **SeasonDatabaseObject** — Constructor: base init sub_4893C0, zero fields +0x1F4/+0x1F8/+0x1FC/+0x200/+0x208 and byte +0x174, set +0x204 to 89, install vtable off_59F9E8
- `0x0046B580` **SeasonDatabaseObject** — Constructor: base init sub_4893C0, install vtable off_59FA98, store parameter a3 via ByteSetterAt0xe0, set +0x174 to 0, +0x178 to -1, +0x17C to parameter a2
- `0x0046E6F0` **UIScreenTextBinding** — UI element creation via vtable slot +0x1C of this+0x40 with id 44, then text-chained stack-buffer initialization via InitWithStackBuffer
- `0x0046EE60` **UIMenuScreen** — Build season-output HTML/list UI: state cleanup, path-separator menu item, then one menu item per entry of the module callback table dword_7C73E0
- `0x0046F170` **UIMenuScreen** — Rebuild UI menu items from all module callback table entries, stripping file extensions, with fallback string and per-buffer free
- `0x0046F4D0` **UIScreenTextBinding** — Input-binding dispatch: create UI element via vtable slot +0x1C of this+0x40 with id 44, then clear its screen-text buffer
- `0x00472D00` **UIElement** — Constructor: base init sub_48C070(this, 2), install vtable off_5A2400, zero dword at +0x31C
- `0x00474440` **UIElement** — Constructor: base init sub_48C070(this, 1), install vtable off_5A3A80, store literal 395 at +0x31C, register three text-handle nodes, then sub_474510
- `0x00476080` **UIRenderNode** — Destructor for a render/HUD node: switch to child vtable, free child node +0x30, switch back to base vtable, free owned resource +0x4, optional self-free

## Proposed classes

### ServerSessionManager

Tracks server track open/close session state and owns an embedded debug-log linked list that accumulates formatted notifications, rendered to the UI resource and optionally written to the engine debug log.

Methods: `0x00461190`

- `this+0x00000029` `byte session_open_flag` (read_write, DERIVED)
- `this+0x0000002C` `float track_state_timer` (read_write, DERIVED)
- `this+0x0001B770` `node* debug_log_head` (read_write, DERIVED)
- `this+0x0001B774` `node* debug_log_tail` (read_write, DERIVED)
- `this+0x0001B778` `node* debug_log_first` (read_write, DERIVED)
- `this+0x0001B77C` `int debug_log_count` (read_write, DERIVED)
- `*(this+0x1B774)+0x00000004` `node* debug_log_tail_next` (write, DERIVED)

### NetworkSessionClient

Manages a multiplayer network session: starts internet or LAN update paths, forwards the network-system pointer at obj+0x1B79C, and sends host join requests with a reset join flag.

Methods: `0x00461DE0`, `0x00461F70`, `0x00462C00`

- `this+0x00000000` `void* session_object_ptr` (read, GUESS)
- `obj+0x0001B79C` `void* network_system_ptr` (read, DERIVED)
- `obj+0x00000378` `int join_flag` (write, DERIVED)

### GameObject

Per-frame updated game object with an optional tracking-list registration, a timer that drives an expiry state transition plus vtable callback, and two flag-gated physics sub-updates; the two active flags are set/cleared by dedicated helpers.

Methods: `0x004661B0`, `0x00466250`, `0x00466270`, `0x00466290`

- `this+0x00000000` `void** vtable` (read, DERIVED)
- `this+0x00000040` `void* sub_object_ptr` (read, DERIVED)
- `this+0x000000E8` `dword tracking_registration_flag` (read, DERIVED)
- `this+0x00000124` `float expiry_timer` (read_write, DERIVED)
- `this+0x000000F4` `byte primary_subupdate_flag` (read_write, DERIVED)
- `this+0x000000F5` `byte secondary_subupdate_flag` (read_write, DERIVED)
- `obj+0x0000002C` `float subobject_delta_field` (read, DERIVED)
- `obj+0x000000A8` `void* subobject_list_node_left` (read_write, DERIVED)
- `obj+0x000000AC` `void* subobject_list_node_right` (read_write, DERIVED)

### AnimationFrameTimer

Accumulates per-frame delta time read from a sub-object and advances a 2-frame animation counter when the accumulation exceeds the 2.0 threshold, wrapping at a global limit and firing a vtable callback.

Methods: `0x00469DD0`

- `this+0x00000040` `void* delta_source_ptr` (read, DERIVED)
- `this+0x00000174` `float accumulated_time` (read_write, DERIVED)
- `this+0x00000178` `float animation_frame_counter` (read_write, DERIVED)

### UIElement

UI menu element constructed through the shared sub_48C070 base initializer with a stored 64-byte-strided or grid-indexed data-table pointer at +0x320, coordinate/index fields at +0x324/+0x328/+0x32C, and a per-type vtable.

Methods: `0x00467260`, `0x004672C0`, `0x00472D00`, `0x00474440`

- `this+0x00000000` `void** vtable` (write, DERIVED)
- `this+0x00000305` `byte byte_flag_305` (write, GUESS)
- `this+0x0000031C` `int data_count_param` (read_write, DERIVED)
- `this+0x00000320` `void* data_table_ptr` (write, DERIVED)
- `this+0x00000324` `int index_or_literal` (read_write, DERIVED)
- `this+0x00000328` `int grid_value_a` (read_write, GUESS)
- `this+0x0000032C` `int grid_value_b` (read_write, GUESS)

### UIMenuScreen

Menu screen object that cleans up UI state via StateCleanupNotification and rebuilds menu items through UIMenuItemCreator, either dispatching a stored command id at +0x174 through formatter paths or iterating the module callback table dword_7C73E0 (including extension-stripped entry names).

Methods: `0x004674E0`, `0x0046EE60`, `0x0046F170`

- `this+0x00000174` `int menu_command_id` (read, DERIVED)
- `this+0x00000178` `int menu_subtype` (read, DERIVED)

### LinkedListContainer

Container holding an embedded singly linked list with head/tail/count/capacity and two-level node allocations; the destructor walks and frees every node's inner and outer data blocks, then the node struct.

Methods: `0x004677E0`

- `this+0x000000F8` `node* list_head` (read_write, DERIVED)
- `this+0x000000FC` `node* list_tail` (read_write, DERIVED)
- `this+0x00000100` `int list_count` (read_write, DERIVED)
- `this+0x00000104` `int list_capacity` (read_write, DERIVED)
- `*(this+0xF8)+0x00000000` `void* node_data_block` (read, DERIVED)
- `*(this+0xFC)+0x00000004` `node* node_next` (read, DERIVED)

### SeasonDatabaseObject

Family of season-database objects constructed by SeasonDatabaseObjectFactory (0x0047F440). Constructors run a shared base/sub-object initializer (sub_4893C0, or sub_48C9F0 for one variant), zero a command/state field at +0x174, set a -1 sentinel at +0x178, optionally write a parameter at +0x17C, and install per-variant vtables.

Methods: `0x004685B0`, `0x0046A220`, `0x0046A4E0`, `0x0046A900`, `0x0046B580`

- `this+0x00000000` `void** vtable` (write, DERIVED)
- `this+0x00000174` `int command_state` (read_write, DERIVED)
- `this+0x00000178` `int subtype_sentinel` (read_write, DERIVED)
- `this+0x0000017C` `int season_parameter` (read_write, GUESS)
- `this+0x000001F4` `int zero_field_1F4` (write, GUESS)
- `this+0x000001F8` `int zero_field_1F8` (write, GUESS)
- `this+0x000001FC` `int zero_field_1FC` (write, GUESS)
- `this+0x00000200` `int zero_field_200` (write, GUESS)
- `this+0x00000204` `int constant_89_field` (write, GUESS)
- `this+0x00000208` `int zero_field_208` (write, GUESS)
- `this+0x00000344` `int zero_field_344` (write, GUESS)
- `this+0x00000348` `int zero_field_348` (write, GUESS)
- `this+0x0000034C` `int minus1_sentinel_34C` (write, GUESS)

### ProfileListManager

Manages a receiver's linked list of profile filenames and validates that a candidate profile name does not collide with an existing entry (with a special case for the PlayerNameNever string).

Methods: `0x00469550`

- `this+0x00000450` `int profile_entry_count` (read, DERIVED)

### UIScreenTextBinding

UI binding object that creates or retrieves a screen element through vtable slot +0x1C of the sub-object at this+0x40 (called with element id 44) and then reads or clears its text buffer via UIScreenTextAccessor.

Methods: `0x0046E6F0`, `0x0046F4D0`

- `this+0x00000040` `void* ui_factory_obj_ptr` (read, DERIVED)
- `*(this+0x40)+0x0000001C` `void** (vtable slot 28) ui_element_factory_slot` (read, DERIVED)

### UIRenderNode

Render/HUD node whose destructor switches between child/base vtables, frees the child node at +0x30 and the owned resource at +0x4, and self-frees when the scalar-deleting flag bit 0 is set.

Methods: `0x00476080`

- `this+0x00000000` `void** vtable` (read_write, DERIVED)
- `this+0x00000004` `void* owned_resource` (read, DERIVED)
- `this+0x00000030` `void* child_node` (read, DERIVED)

## Compatibility contracts

- **session_debug_log_append** — ServerSessionManager owns an embedded debug-log linked list at this+0x1B770 (head) / +0x1B774 (tail) / +0x1B778 (first) / +0x1B77C (count). Each entry is a 12-byte node {buffer-wrapper, next, flag byte}; appends allocate the node and a two-word wrapper via OperatorNewNhMallocWrapper and render the message via TextLineWrappingAndRendering on dword_7CD204.
- **network_system_pointer_contract** — The session object behind this+0x0 holds a network-system pointer at +0x1B79C and a join flag at +0x378. A non-null +0x1B79C enables network initialisation (internet mode 1, or LAN across the port range word_7D0FE8..word_7D0FE8+99) and forwarding; the session-entry array at the same offset is indexed bounds-checked when sending join requests.
- **refresh_flag_consume_once** — Global byte_7CD2A0 is a set-once refresh flag: consumeRefreshFlag, called from ConditionalChain, consumes each set exactly once, clearing it and returning non-zero only on the first read after it was set.
- **debug_log_verbosity_gate** — Dev-log writes are gated by StringSplitLoop(1, aDDevF119992002_1, selector) against buffer dword_8AD25C and suppressed for session type dword_7C569C == 5 (server session).
- **ui_element_factory_slot** — UI bindings reach a screen element through vtable slot +0x1C of the sub-object at this+0x40 with argument 44; the returned object exposes its text via UIScreenTextAccessor (0x00489920), which is then initialized or cleared.
- **season_database_factory_contract** — SeasonDatabaseObjectFactory (0x0047F440) constructs season-database variants whose constructors zero the +0x174 command/state field, set a -1 sentinel at +0x178, optionally write a parameter at +0x17C, and install per-variant vtables.

## Unresolved

- ServerSessionManager is a DERIVED proposal (ABI lead 'Server_Opened_Closed_Notification' + sole caller ConditionalStateDispatch 0x00463760); no CONFIRMED static type exists for it.
- The debug-log block at this+0x1B770..0x1B77C is adjacent to the network-system pointer at obj+0x1B79C, but common ownership of the two regions is NOT proven; ServerSessionManager and NetworkSessionClient may or may not be the same session object.
- Semantics of ServerSessionManager +0x2C (1084227584 on opened, -1.0f on closed) and +0x29 are inferred as track open/close progress/flag state from surrounding code; not independently confirmed.
- Globals flt_59F0B4 (0x0059F0B4) and unk_8AC368 (0x008AC368) are listed for ServerOpenedClosedNotification but do not appear in the raw Hex-Rays body; role unknown.
- Which subsystem sets the refresh flag byte_7CD2A0 and what re-evaluation it requests is not established; the single known consumer is ConditionalChain (0x00475570).
- ConsumeRefreshFlag, ConditionalStridePointerComputation, and addSaturatedToAllBytes are left ownerless (UnknownObject): no shared-object evidence links them to a class.
- ConditionalStridePointerComputation: owner class and the meaning of the stride-872 element array are unknown; whether a2 is an element index or a raw byte multiplier is caller-defined.
- addSaturatedToAllBytes iterates 104 elements, matching the engine vehicle slot count, but no packet evidence links the byte array to the vehicle grid.
- GameObjectUpdateFrame vtable callbacks at offsets 44, 168 and 172, and the AnimationFrameTimer vtable callback at offset 0xA0, are not resolved to concrete functions in this packet.
- Global flt_59E440 is listed for GameObjectUpdateFrame but not referenced in the raw source; its zero-threshold role is unverified.
- Global flt_59E800 is listed for AnimationFrameTimer but not referenced in the raw source; the threshold literal 2.0 is raw-source only.
- UIElement constructors install distinct vtables (off_59F4F8, off_5A2400, off_5A3A80); whether this is one class with overridden vtables or several classes sharing the sub_48C070 base layout is unresolved.
- MenuCommandDispatcher JUMPOUT(0x4675E5) target for cases 451-454 is not statically resolved; the jump table contents at jpt_467506 (0x00467674) and byte_467684 are unknown.
- UIMenuScreen grouping is behavioral (shared StateCleanupNotification + UIMenuItemCreator), not a proven shared object layout; MenuCommandDispatcher's +0x174/+0x178 fields are not shown to belong to the same class as the table-iterating builders.
- SeasonDatabaseObject constructors install distinct vtables (off_59F718/59F878/59F938/59F9E8/59FA98); the family may represent several concrete subclasses of one base, or a single class with overridden vtables.
- Semantics of SeasonDatabaseObject literal values 11/4/55/89, the -1 sentinels at +0x178/+0x34C, and the zeroed +0x344/+0x348/+0x1F4..0x208 block are unknown.
- Meaning of dword_7C569C==5 (session type 5) is not defined within this packet; constants 5776/5765 passed to StringSplitLoop are opaque verbosity/guard selectors.
- PlayerNameNeverUsedProfileNameUniquenessCheck: sub_568910 and sub_588410 are unnamed; the break-on-match path returns a special-case boolean involving aPlayernameneve (0x005C6970) and byte_7D2E41 rather than an immediate false; exact semantics ambiguous.
- Global aSD_2 (0x005C6214) is flagged for SendJoinRequest but does not appear in the raw decompiled source; role unknown.
- The object type at obj+0x1B79C and the concrete class behind the off_59FA98 / off_5A2400 / off_5A3A80 vtables are not identified by the packet.
- UIRenderNode: concrete class identities behind off_5A4450/off_5A443C and the purposes of the owned resource at +0x4 and child node at +0x30 are not evidenced.
- RenderObjectDestructor is the only evidenced UIRenderNode method; no constructor or update method appears in this packet to constrain the class further.
- The AnimationFrameTimer vtable-callback evidence field:obj:0x000000A0 is ambiguous (could be a this-object vtable slot or a sub-object field) and is left in unresolved_evidence_refs.
- The byte_5EA438 fallback string is referenced by several functions as a default when a formatted buffer is empty; its content/role beyond that is not evidenced in this packet.
- The word_7D0FE8 session port base semantics (dword_7D0FE8+99 range) are inferred from the skeleton, not proven by this packet.
