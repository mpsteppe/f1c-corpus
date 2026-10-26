# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

DERIVED reconstruction of generic runtime objects around the 0x0048E000-0x00498000 range. Clusters are grounded in the packet's field evidence and callee/caller links: (1) a font-resource widget (0x0048E300) with string buffer, its scalar deleting destructor (0x0048E650) wrapping the real destructor 0x0048E670, and a conditional geometry display update (0x0048E5C0) that reads a source rect at 0xE8..0xF4; (2) a scrollable tile grid (0x0048FAF0, 0x0048FB30) sharing the scroll offset 0x168 and default increment 0x178 and always re-invoking UITileGrid (0x0048F870); (3) a child-widget list container (0x00490250, 0x004902C0, 0x00490550) that installs the off_5AC760 vtable, walks a child list at this+0xE0 (count at 0xEC), dispatches vtable notifications and hit-tests with DualFieldRead input; (4) a global linked-list manager (0x00490AA0, 0x004910D0, 0x004917C0, 0x00491DB0) sharing the 12-byte {+0 value, +4 next, +8 flag} node layout, FreeWrapper_7bcf and the reparent primitive 0x00490AA0, with a ring-buffer eviction that also uses the node+8 byte as an age counter (max 3); (5) an OSC script-parser state initializer (0x00493F50) installing default log paths; (6) allocation helpers (0x00494FB0, 0x00494FE0) over the 0x53CBxx family; (7) a string-normalizing hash lookup (0x00495810); (8) two different doubly-linked-list containers (0x00495A80 with node links at +0x64/+0x68, 0x00497510 with {+0 data,+4 next,+8 prev,+12 flag}) and object-registration helpers (0x00497590, 0x004975B0) that both store the receiver at target+0x40; (9) a large float-backed state-struct default initializer (0x00496560) and rectangle-render (0x004972B0) and state-mode configuration (0x004977E0) helpers. All owner identities remain UNKNOWN in the packet; class grouping is structural and must not be promoted to CONFIRMED.

## Function roles

- `0x0048E300` **FontResourceObject** — Font resource constructor: base-init via ConstructorWithByteParams (0x00487220), zero fields 0xE4 and 0xFC, set 0x100 to -1, install vtable off_5AC490 at 0x0, reset string buffer via StringCopyWithBufferRealloc (0x00566650), return this.
- `0x0048E5C0` **GeometryResourceDisplayUpdater** — Conditional geometry display update: query reload via virtual vtable+0xA0; when no reload needed, read source rect 0xE8..0xF4, obtain render surface via Accessor (0x00490920), copy region via RenderSurfaceFillCopy (0x004918D0), return query result.
- `0x0048E650` **FontResourceObject** — Scalar deleting destructor: unconditionally run real destructor 0x0048E670, then FreeWrapper_7bcf(this) when deleting-flag bit 0 of a2 is set, return this.
- `0x0048EA20` **TileRecordFieldSetter** — Trivial pair setter: store argument a2 at this+0x14 and a3 at this+0x18, return a2; used by UITileGrid (0x0048F870).
- `0x0048EAA0` **RangeSliderObject** — Large constructor: base-init via ShortComputation_5e30 (0x00485E30), zero blocks 0xE0..0xFC and 0x10C..0x16C plus 0x174 and bytes 0x17D..0x17F, install vtable off_5A4550 at 0x0, set range defaults 0x100=1, 0x104=4, 0x108=0.5f, 0x170=-1, 0x178=10, byte 0x17C=1, return this.
- `0x0048FAF0` **ScrollableTileGrid** — Decrement counter 0x168 by a2, or by fallback this+0x178 when a2 is negative; clamp counter to 0 if negative, call UITileGrid (0x0048F870), return its result.
- `0x0048FB30` **ScrollableTileGrid** — Increment scroll offset 0x168 by a2, or by default increment this+0x178 when a2 is negative; clamp to maximum this+0x16C, call UITileGrid (0x0048F870), return its result.
- `0x004900A0` **InputRegionStateToggle** — Input-region state toggle: read input position via DualFieldRead (0x00498880), bound via sub_487060 (0x00487060) and sub_4870E0 (0x004870E0); toggle state flag 0xE0 (0->1, 1->0, 2->2, other->1; miss sets 1); dispatch state via vtable+0x40 then vtable+0x98, return 0.
- `0x00490250` **WidgetListContainer** — Widget-list initializer: base-init via ShortComputation_5e30 (0x00485E30), zero dwords 0xE0..0xF0, install vtable off_5AC760 at 0x0, return this; called during UI widget-list construction.
- `0x004902C0` **WidgetListContainer** — Widget-list destructor: install vtable off_5AC760 at 0x0, walk child list from head this+0xE0 via node next +4; for each node with flag byte node+0xC set and first dword non-zero dispatch sub-object vtable entry 0 with argument 1; free every node via FreeWrapper_7bcf; zero 0xE0..0xEC and chain to base destructor.
- `0x00490550` **WidgetListContainer** — Panel mouse handler: state selector via ShortComputation_6720 (0x00486720) gates the interaction block to states 3-5; read position via DualFieldRead (0x00498880), vtable hit-test at +48 (obj+0x30), on miss dispatch vtable+0x40 with argument 0, walk child list head this+0xE0 (count 0xEC, node next +4) with RectangleBoundsCheck (0x0048EA60) and dispatch vtable+0x40 with argument 4 on first hit; always run VTableDispatchListIteration (0x00490660), return 0.
- `0x00490AA0` **GlobalLinkedListManager** — Global list prepend: get manager via GlobalDataRead (0x00490930), zero payload via ShortArrayZeroInit (0x00491330), allocate 12-byte node via OperatorNewNhMallocWrapper (0x00587C03) holding {+0 payload, +4 next, +8 flag}; prepend to manager head v2[4], update tail/head aliases v2[5]/v2[6] and count v2[7]; return node or 0 on failure.
- `0x004910D0` **GlobalLinkedListManager** — List detach-and-free-all: reparent node values via LinkedListNodePrepend (0x00490AA0) advancing cursor this+0x8; second walk frees nodes (EmptyStub_0170 (0x004B0170) on flagged values, FreeWrapper_7bcf on value and node); zero sentinel fields 0x0/0x4/0x8/0xC, return 1.
- `0x004917C0` **GlobalLinkedListManager** — Ring-buffer advance: when sub_4F9B20(&unk_8AFE18) permits, advance ring index (header+4 mod header+0); destroy two embedded list iterators via ListIteratorFullDestruction (0x004910D0); walk current ring slot nodes (age at node+8, max 3), evict aged nodes (unlink, free via FreeWrapper_7bcf, prepend via LinkedListNodePrepend (0x00490AA0)); return 1.
- `0x00491DB0` **GlobalLinkedListManager** — List destructor: iterate nodes from head this+0x0 via node next +4; free node data when flag byte node+0x8 set and data node+0 non-null; free every node via FreeWrapper_7bcf; zero header fields this+0x0/0x4/0x8/0xC; return last free result.
- `0x00493F50` **OscScriptParser** — OSC script-parser state initializer: zero state dwords 0x0/0x4/0x8 and byte 0xC, copy default log paths (global 0x005AC80C at this+140, global 0x005AC820 at this+268), zero counters 0x18C/0x190/0x194/0x19C and flag bytes 0x198/0x199/0x19A, return this.
- `0x00494FB0` **MemoryAllocationHelper** — Allocation forwarding wrapper (stdcall): call MemoryAllocation_cb20 (0x0053CB20) with (a1, a2, 0, a3), return callee result; called by HashTableIDResolution (0x00495890) and ResourceFileLoader (0x004F9D60).
- `0x00494FE0` **MemoryAllocationHelper** — Conditional field clear: call sub_53CBC0 (0x0053CBC0) with output dword pointer a2; when result is non-zero clear *a2, return callee result; called by BitmapLoader (0x004979F0).
- `0x00495810` **HashTableStringResolver** — String-normalize hash lookup: normalize string copy via sub_589901 (0x00589901), test hash-table membership via sub_587C20 (0x00587C20) against dword_5CC79C; on miss extend key with raw dword_5CC79C plus byte_5CC7A0; pass result to CollisionNodeAllocator (0x00494DE0).
- `0x00495A80` **DoublyLinkedListTailAppender** — Doubly-linked tail append: unlink a2 via DoublyLinkedListNodeUnlink (0x00495A20), zero a2's links, walk head this+0x14 to tail via node next +0x64, splice at tail this+0x18 with a2 prev +0x68; empty list sets head and tail to a2.
- `0x00496560` **LargeStateStructInitializer** — Large state-struct default initializer: clear a broad spread of float fields, set scalar constants (0.5/0.25/2.5/-1.0 sentinel), zero byte flags, write unk_888888 (0x00888888) into dword slots 0xB4/0xB8, clear 64 records of 20 bytes at base 0x114, seed via FloatArrayInitWithRandom; called by LargeStructZeroInit (0x00495190).
- `0x004972B0` **RectangleRenderer** — Outlined-rectangle renderer: get global rendering context via GlobalAccessor_5150 (0x00495150), initial border draw via DelegationWrapper (0x00494BF0), then loop drawing four edges via FloatVectorWithConditionalTransform (0x00494C20) with alternating color masks (a1&0xFF000000|a2&0xFFFFFF and a1&0xFF000000|~a2&0xFFFFFF), shrinking 1px per side.
- `0x004974A0` **SearchableListDispatch** — Searchable list dispatch: copy head this+0x4 into cursor this+0xC, walk node next +4; on key match run action chain SimpleSetter_fc40 (0x0054FC40), FieldGetter_8e30 (0x00498E30), SetterVirtualCall (0x00498F40); always finish with ShortComputation_7250 (0x00497250), return 0.
- `0x00497510` **DoublyLinkedListNodeContainer** — Doubly-linked insert: increment op counter this+0x2C, run SimpleSetter_fdf0 (0x0054FDF0) and SimpleSetter_fc40 (0x0054FC40); allocate 16-byte node via OperatorNewNhMallocWrapper (0x00587C03) {+0 data, +4 next, +8 prev, +12 flag}; empty list sets head/tail/secondary 0x4/0x8/0xC, else append at tail 0x8; increment count 0x10; return a2.
- `0x00497590` **ObjectRegistrationHelper** — Object-registration setup: store receiver this into a2+0x40 and argument a3 into a2+0x98, call ObjectRegistration (0x00499360), return its result.
- `0x004975B0` **ObjectRegistrationHelper** — Init registration: store receiver this into a2+64, append a2 via LinkedListAppend_8eb0 (0x00498EB0), return that call's result; called from sub_492460 to register an object about to be initialized.
- `0x004977E0` **StateModeConfigurator** — State+threshold configuration: guard a3==-1 skips everything; store a2 at this+0x157C, call sub_496E90 (0x00496E90) twice; jump-table dispatch via jpt_497810 (0x0049787C): cases 0-3 write mode at 0x1578 and 0.01f at 0xDC, case 4 writes float only, default returns without writes.

## Proposed classes

### FontResourceObject

UI widget/font resource with a string buffer. The constructor (0x0048E300) runs the base widget initializer ConstructorWithByteParams (0x00487220), zeroes fields 0xE4 and 0xFC, sets 0x100 to -1, installs the off_5AC490 vtable and resets the string buffer via StringCopyWithBufferRealloc (0x00566650). The scalar deleting destructor (0x0048E650) runs the real destructor 0x0048E670 unconditionally and frees storage via FreeWrapper_7bcf only when the deleting-flag bit 0 is set. Field semantics and the real destructor's own class identity are not established in this packet.

Methods: `0x0048E300`, `0x0048E650`

- `this+0x00000000` `ptr vtable_ptr` (write, GUESS)
- `this+0x000000E4` `dword field_0xE4` (write, GUESS)
- `this+0x000000FC` `dword field_0xFC` (write, GUESS)
- `this+0x00000100` `int invalid_id_marker` (write, GUESS)

### GeometryResourceDisplayUpdater

Conditional display/geometry update (0x0048E5C0): queries whether a video/geometry resource needs a reload through the virtual method at vtable+0xA0; when no reload is needed it reads a source rectangle at this+0xE8..0xF4, obtains the render surface via Accessor (0x00490920) and copies the region with RenderSurfaceFillCopy (0x004918D0). Whether the copy targets the display or another destination surface is not established.

Methods: `0x0048E5C0`

- `this+0x00000000` `ptr vtable_ptr` (read, GUESS)
- `obj+0x000000A0` `fn_ptr reload_query_slot` (read, GUESS)
- `this+0x000000E8` `int src_rect_x` (read, GUESS)
- `this+0x000000EC` `int src_rect_y` (read, GUESS)
- `this+0x000000F0` `int src_rect_width` (read, GUESS)
- `this+0x000000F4` `int src_rect_height` (read, GUESS)

### ScrollableTileGrid

Scrollable UI tile-grid container holding a scroll offset at this+0x168, a maximum bound at this+0x16C and a default increment at this+0x178. Both methods adjust the offset by a caller argument (or the stored default when the argument is negative) and clamp it, then recompute tile positions by calling UITileGrid (0x0048F870) and return its result.

Methods: `0x0048FAF0`, `0x0048FB30`

- `this+0x00000168` `int scroll_offset` (read_write, DERIVED)
- `this+0x0000016C` `int max_offset` (read_write, DERIVED)
- `this+0x00000178` `int default_increment` (read, DERIVED)

### TileRecordFieldSetter

Trivial two-field setter (0x0048EA20): stores integer arguments into this+0x14 and this+0x18 and returns the first argument unchanged. Caller UITileGrid (0x0048F870) suggests the pair is a position or size tuple for a tile record, but the semantic role is inferred only from the caller.

Methods: `0x0048EA20`

- `this+0x00000014` `int pair_value_a` (write, GUESS)
- `this+0x00000018` `int pair_value_b` (write, GUESS)

### RangeSliderObject

Widget-style object whose constructor (0x0048EAA0) runs the shared base initializer ShortComputation_5e30 (0x00485E30), zeroes a wide field block, installs the off_5A4550 vtable and sets range-like defaults (0x100=1, 0x104=4, 0x108=0.5f, 0x170=-1, 0x178=10, byte 0x17C=1). Existing analysis proposes a UI slider range with 10 steps; the semantics of the range fields and the class implied by the vtable are not statically confirmed. It shares the base initializer 0x00485E30 with WidgetListContainer (0x00490250), which may indicate a common base class but is not proven.

Methods: `0x0048EAA0`

- `this+0x00000000` `ptr vtable_ptr` (write, GUESS)
- `this+0x00000100` `int range_min` (write, GUESS)
- `this+0x00000104` `int range_max` (write, GUESS)
- `this+0x00000108` `float range_value` (write, GUESS)
- `this+0x00000170` `int unset_id_marker` (write, GUESS)
- `this+0x00000178` `int step_count` (write, GUESS)
- `this+0x0000017C` `byte enabled_flag` (write, GUESS)

### InputRegionStateToggle

Input-region interaction widget (0x004900A0): reads a cursor/input position via DualFieldRead (0x00498880), computes bounding boundaries with sub_487060 (0x00487060) and sub_4870E0 (0x004870E0), and toggles the state flag at this+0xE0 (0->1, 1->0, 2 unchanged, other->1; miss sets 1). The new state is dispatched through the vtable+0x40 method and followed by the vtable+0x98 method. The coordinate space and the dispatched targets are unknown.

Methods: `0x004900A0`

- `this+0x00000000` `ptr vtable_ptr` (read, GUESS)
- `this+0x000000E0` `byte state_flag` (read_write, DERIVED)
- `obj+0x00000040` `fn_ptr state_dispatch_slot` (read, GUESS)
- `obj+0x00000098` `fn_ptr post_dispatch_slot` (read, GUESS)

### WidgetListContainer

UI container managing a child-widget linked list. The initializer (0x00490250) runs the shared base initializer ShortComputation_5e30 (0x00485E30), zeroes 0xE0..0xF0 and installs the off_5AC760 vtable. The destructor (0x004902C0) reinstalls the same vtable, walks the list rooted at this+0xE0 (node next at +4, notify-flag byte at node+0xC), dispatches sub-object vtable entry 0 with argument 1 for flagged nodes, frees nodes via FreeWrapper_7bcf, zeroes 0xE0..0xEC and chains to a base destructor. The mouse handler (0x00490550) gates on state 3-5 from ShortComputation_6720, reads input via DualFieldRead, hit-tests at vtable+0x30, dispatches vtable+0x40 with 0/4 and walks the child list (count at 0xEC) with RectangleBoundsCheck, then runs VTableDispatchListIteration (0x00490660).

Methods: `0x00490250`, `0x004902C0`, `0x00490550`

- `this+0x00000000` `ptr vtable_ptr` (read_write, GUESS)
- `this+0x000000E0` `ptr child_list_head` (read_write, DERIVED)
- `this+0x000000E4` `dword child_list_field_0xE4` (read_write, GUESS)
- `this+0x000000E8` `dword child_list_field_0xE8` (read_write, GUESS)
- `this+0x000000EC` `int child_count` (read_write, DERIVED)
- `this+0x000000F0` `dword field_0xF0` (write, GUESS)
- `obj+0x00000030` `fn_ptr hit_test_slot` (read, GUESS)
- `obj+0x00000040` `fn_ptr dispatch_slot` (read, GUESS)
- `*(*(this+0xE0)+0x4)+0x00000004` `ptr node_next` (read, DERIVED)
- `*(this+0xE0)+0x0000000C` `byte notify_flag` (read, GUESS)
- `*(this+0xE4)+0x00000004` `ptr child_node_next` (read, DERIVED)

### GlobalLinkedListManager

Generic embedded linked-list manager with 12-byte nodes {+0 value, +4 next, +8 ownership/state flag}. 0x00490AA0 allocates the node via OperatorNewNhMallocWrapper (0x00587C03), zeroes the payload via ShortArrayZeroInit (0x00491330) and prepends to the manager object obtained from GlobalDataRead (0x00490930), tracking head v2[4], tail/head aliases v2[5]/v2[6] and count v2[7]. 0x004910D0 detaches and frees every node of a 4-dword sentinel (reparenting values via 0x00490AA0, invoking EmptyStub_0170 (0x004B0170) on flagged values, freeing via FreeWrapper_7bcf). 0x004917C0 advances a circular ring buffer and evicts aged nodes (node+8 used as age counter, max 3) into an external list. 0x00491DB0 frees a simple {value,next,flag} list and its data. The node+8 byte serves both as ownership flag and age counter, which is a contradiction to reconcile.

Methods: `0x00490AA0`, `0x004910D0`, `0x004917C0`, `0x00491DB0`

- `this+0x00000000` `ptr list_head` (read_write, DERIVED)
- `this+0x00000004` `dword list_field_0x4` (read_write, GUESS)
- `this+0x00000008` `ptr cursor` (read_write, DERIVED)
- `this+0x0000000C` `dword list_field_0xC` (read_write, GUESS)
- `obj+0x00000000` `ptr node_value` (read_write, DERIVED)
- `obj+0x00000004` `ptr node_next` (read_write, DERIVED)
- `obj+0x00000008` `byte node_flag_age` (read_write, GUESS)

### OscScriptParser

OSC script-parser state structure. The initializer (0x00493F50) zeroes the leading dwords 0x0/0x4/0x8 and byte 0xC, installs the default log path strings (global aLogOscInformat 0x005AC80C at this+140 and aLogOscErr 0x005AC820 at this+268), zeroes the counter/token dwords near 0x18C and the trailing flag bytes 0x198/0x199/0x19A. Concrete field meanings (file handles, stream pointers, token counters) are labeled from the apparent OSC-parser role and are not individually named by the packet.

Methods: `0x00493F50`

- `this+0x00000000` `dword state_dword_0` (write, GUESS)
- `this+0x00000004` `dword state_dword_1` (write, GUESS)
- `this+0x00000008` `dword state_dword_2` (write, GUESS)
- `this+0x0000000C` `byte state_byte` (write, GUESS)
- `this+0x0000018C` `int parser_counter_a` (write, GUESS)
- `this+0x00000190` `int parser_counter_b` (write, GUESS)
- `this+0x00000194` `int parser_counter_c` (write, GUESS)
- `this+0x0000019C` `int parser_counter_d` (write, GUESS)
- `this+0x00000198` `byte flag_byte_0x198` (write, GUESS)
- `this+0x00000199` `byte flag_byte_0x199` (write, GUESS)
- `this+0x0000019A` `byte flag_byte_0x19A` (write, GUESS)

### MemoryAllocationHelper

Thin helpers over the 0x53CBxx memory-allocation family used during resource loading. 0x00494FB0 is a stdcall wrapper forwarding (a1, a2, 0, a3) to MemoryAllocation_cb20 (0x0053CB20), called by HashTableIDResolution (0x00495890) and ResourceFileLoader (0x004F9D60). 0x00494FE0 evaluates sub_53CBC0 (0x0053CBC0) with an output dword pointer and clears the pointed-to dword when the callee returns non-zero, called by BitmapLoader (0x004979F0). Both read the flagged global dword_8AFE64 per packet facts but it never appears in their raw bodies.

Methods: `0x00494FB0`, `0x00494FE0`


### HashTableStringResolver

String-lookup helper (0x00495810) that normalizes a copy of an input string via sub_589901 (0x00589901), tests hash-table membership through sub_587C20 (0x00587C20) against the head dword_5CC79C, and on a miss builds a compound key by appending the raw dword_5CC79C value and the single byte_5CC7A0 at the terminator, then hands the string to CollisionNodeAllocator (0x00494DE0). NULL input returns -1. Caller context (driver/name resolution) is external to this function.

Methods: `0x00495810`


### DoublyLinkedListTailAppender

Doubly-linked-list tail append (0x00495A80). First unlinks the incoming node a2 via DoublyLinkedListNodeUnlink (0x00495A20) and zeroes its link slots, then walks the list from head this+0x14 following each node's next pointer at +0x64, and splices a2 at the tail this+0x18 (a2 prev at +0x68). An empty list sets both head and tail to a2. The node link offsets come only from the raw literals 100/104; the corpus field this+0x78 (cached traversal start) does not appear in the raw body.

Methods: `0x00495A80`

- `this+0x00000014` `ptr list_head` (read_write, DERIVED)
- `this+0x00000018` `ptr list_tail` (read_write, DERIVED)
- `*(*(this+0x78)+0x64)+0x00000064` `ptr node_next` (read, DERIVED)

### DoublyLinkedListNodeContainer

Doubly-linked-list node container (0x00497510) with head at this+0x4, tail at this+0x8, a secondary pointer at this+0xC (set to head on first insert but never consulted here) and a node count at this+0x10; an operation counter lives at this+0x2C. Insert increments the counter, runs two simple setters (0x0054FDF0, 0x0054FC40), allocates a 16-byte node {+0 data, +4 next, +8 prev, +12 flag} via OperatorNewNhMallocWrapper (0x00587C03), links it as head/tail/secondary on an empty list or after the tail otherwise, and increments the count. Called by sub_492460 (0x00492460) as the list insertion primitive.

Methods: `0x00497510`

- `this+0x00000004` `ptr list_head` (read_write, DERIVED)
- `this+0x00000008` `ptr list_tail` (read_write, DERIVED)
- `this+0x0000000C` `ptr secondary_ptr` (read_write, GUESS)
- `this+0x00000010` `int node_count` (read_write, DERIVED)
- `this+0x0000002C` `int op_counter` (read_write, DERIVED)

### ObjectRegistrationHelper

Object-registration setup helpers that both store the caller's receiver pointer into the target object at offset 0x40 before handing the object to a registration/append call. 0x00497590 additionally stores argument a3 at target+0x98 and calls ObjectRegistration (0x00499360); 0x004975B0 appends the target via LinkedListAppend_8eb0 (0x00498EB0). The shared receiver-back-reference field at target+0x40 is the common-ownership evidence for this grouping.

Methods: `0x00497590`, `0x004975B0`

- `obj+0x00000040` `ptr receiver_backref` (write, DERIVED)
- `obj+0x00000098` `dword registered_payload` (write, GUESS)

### SearchableListDispatch

Singly-linked-list traversal and dispatch (0x004974A0): copies head this+0x4 into the current-node cursor this+0xC, walks node next pointers at +4, and on a match against key a2 runs an action chain (SimpleSetter_fc40 (0x0054FC40), FieldGetter_8e30 (0x00498E30), SetterVirtualCall (0x00498F40)); always finishes with ShortComputation_7250 (0x00497250) writing a byte 1 to a field whose offset is not evidenced in this packet (prior analysis suggests this+0x25). Owner class and the meaning of the cursor field are unknown.

Methods: `0x004974A0`

- `this+0x00000004` `ptr list_head` (read, DERIVED)
- `this+0x0000000C` `ptr cursor` (read_write, DERIVED)
- `*(this+0x4)+0x00000000` `dword head_item` (read, GUESS)
- `*(this+0xC)+0x00000004` `ptr node_next` (read, DERIVED)

### LargeStateStructInitializer

One-time default initializer for a large float-backed aggregate (vehicle or pit-crew state, unnamed): clears a broad spread of float fields, sets scalar constants (0.5 at 0xD0, 0.25 at 0xD4, 2.5 at 0xD8, -1.0 sentinel at 0x44), zeroes byte flags, writes the unk_888888 bit pattern into dword slots 0xB4/0xB8 (overlapping float slots 45/46), clears a 64-entry array of 20-byte records at base 0x114, and seeds the structure via FloatArrayInitWithRandom. Linear and branch-free; invoked by LargeStructZeroInit (0x00495190). The owning class is unknown.

Methods: `0x00496560`

- `this+0x000000B4` `dword_or_float unk_slot_a` (write, GUESS)
- `this+0x000000B8` `dword_or_float unk_slot_b` (write, GUESS)
- `this+0x00000028` `dword count_flag` (write, GUESS)
- `this+0x000018F5` `byte enabled_byte` (write, GUESS)
- `this+0x00001574` `byte flag_byte_0x1574` (write, GUESS)
- `this+0x00001588` `byte flag_byte_0x1588` (write, GUESS)
- `this+0x00001589` `byte flag_byte_0x1589` (write, GUESS)

### RectangleRenderer

Rendering helper (0x004972B0) that draws an outlined rectangle: obtains the global rendering context via GlobalAccessor_5150 (0x00495150), issues an initial border draw through DelegationWrapper (0x00494BF0), then repeatedly draws the four edges via FloatVectorWithConditionalTransform (0x00494C20) with two alternating color masks (a1&0xFF000000|a2&0xFFFFFF and a1&0xFF000000|~a2&0xFFFFFF), shrinking the rectangle by 1px per side. The color/pattern parameter semantics and the relationship between the initial border draw and the per-edge loop are not fully specified.

Methods: `0x004972B0`


### StateModeConfigurator

Configures a state field at this+0x1578 and a float threshold at this+0xDC from a caller-supplied value and mode (0x004977E0). When the mode argument is not -1 it stores the value at this+0x157C, runs sub_496E90 (0x00496E90) twice, and dispatches on the mode through the jump table jpt_497810 (0x0049787C): cases 0-3 write the mode at 0x1578 and 0.01f at 0xDC, case 4 writes only the float, the default case writes nothing. The purpose of the mode field, the 0.01f threshold and the double sub_496E90 call are unknown.

Methods: `0x004977E0`

- `this+0x00001578` `int mode_field` (write, DERIVED)
- `this+0x0000157C` `int value_field` (write, DERIVED)
- `this+0x000000DC` `float threshold_float` (write, DERIVED)

## Compatibility contracts

- **GlobalListNodeLayout** — The global linked list uses 12-byte nodes {+0 value, +4 next, +8 ownership/state flag} allocated via OperatorNewNhMallocWrapper (0x00587C03); the list-manager object obtained from GlobalDataRead (0x00490930) tracks head at v2[4], tail/head aliases at v2[5]/v2[6] and count at v2[7]. A replacement must preserve this node and manager layout.
- **WidgetChildListLayout** — The widget-list container keeps its child list head at this+0xE0 and child count at this+0xEC; nodes link through +4 and carry a notify-flag byte at node+0xC (sub-object vtable at node+0). Destruction reinstalls the off_5AC760 vtable before teardown. A replacement UI container must preserve this layout.
- **ScalarDeletingDestructorFlag** — The scalar deleting destructor 0x0048E650 runs the real destructor 0x0048E670 unconditionally and then releases the object via FreeWrapper_7bcf only when the deleting-destructor argument's bit 0 is set; a2=0 means placement destruction. A replacement destructor must honor the same flag contract.
- **ScrollOffsetClampContract** — The scrollable tile grid stores its offset at this+0x168, a maximum at this+0x16C and a default increment at this+0x178; adjustment uses the caller argument unless it is negative (then the default), clamps the result, and always recomputes tile positions via UITileGrid (0x0048F870).
- **RingBufferEvictionContract** — The ring buffer header stores capacity at header+0 and the ring index at header+4; slots are 16 bytes apart. Nodes carry an age/state byte at +8 (max 3); aged-out nodes are unlinked, freed (value and node) via FreeWrapper_7bcf and reparented through LinkedListNodePrepend (0x00490AA0). A replacement must preserve the slot stride and eviction ordering.
- **OscParserLogPaths** — The OSC script-parser state structure initializes default log path strings "Log\osc.information" (global 0x005AC80C) at this+140 and "Log\osc.err" (global 0x005AC820) at this+268, alongside zeroed parser state. A replacement parser must keep the same log-path defaults.
- **RangeSliderDefaults** — The RangeSliderObject constructor sets range-like defaults after zeroing its body: 0x100=1 (min), 0x104=4 (max), 0x108=0.5f (value), 0x170=-1 (unset id), 0x178=10 (step count) and byte 0x17C=1 (enabled). The semantic reading is DERIVED from existing analysis, not statically confirmed.

## Unresolved

- All function owners are UNKNOWN in the packet; every class name here is a DERIVED or GUESS grouping proposal, not an identified type.
- FontResourceObject (0x0048E300, 0x0048E650): semantics of fields 0xE4/0xFC/0x100 and the identity of vtable off_5AC490 are unknown; the real destructor 0x0048E670's class identity and its vtable are not established in this packet, so the constructor/destructor grouping is structural.
- GeometryResourceDisplayUpdater (0x0048E5C0): the identity and semantics of the vtable+0xA0 reload query are unknown; whether RenderSurfaceFillCopy blits to the display or to a different destination surface is not established.
- TileRecordFieldSetter (0x0048EA20): the semantic meaning of the two stored values (x/y position or size pair) is inferred only from the caller UITileGrid (0x0048F870); why the first argument is returned while the second is not is unresolved.
- RangeSliderObject (0x0048EAA0): the semantics of the range-like fields 0x100/0x104/0x108/0x178 are inferred (UI slider proposal) but not statically confirmed; vtable off_5A4550 and the base initializer 0x00485E30 class identities are unknown. Both this constructor and WidgetListContainer (0x00490250) call the same base initializer 0x00485E30, suggesting a shared base class, but that is not proven.
- ScrollableTileGrid (0x0048FAF0, 0x0048FB30): the meaning of the fallback/default increment at this+0x178 is not evidenced; UITileGrid semantics (tile-position recomputation) are unverified beyond the update-after-change pattern; caller 0x0048F1A0 is unresolved.
- InputRegionStateToggle (0x004900A0): the meaning of the sub_487060 / sub_4870E0 bounding boundaries and the DualFieldRead input coordinate space are not established; the vtable+0x40 and vtable+0x98 dispatch targets are unknown.
- WidgetListContainer (0x004902C0): the base-class destructor target is not exposed as a callee evidence entry so its address is not recorded; the notify-suppression role of the node flag byte at node+0xC is inferred only from the guard.
- GlobalLinkedListManager (0x00490AA0/0x004910D0/0x004917C0/0x00491DB0): the list-manager object layout (head v2[4], aliases v2[5]/v2[6], count v2[7]) is inferred without packet field evidence; the node+8 byte serves as an ownership flag in some functions and as an age counter (max 3) in 0x004917C0, a contradiction to reconcile; the destination list receiving reparented values via LinkedListNodePrepend is opaque; the sentinel layout this+0/4/8/C is shared structurally but ownership of the fields is unnamed.
- OscScriptParser (0x00493F50): concrete field meanings (file handles, stream pointers, token counters) are labeled from the apparent OSC-parser role and are not named individually; whether this+0xC is a flag or a packed short is not decidable from initialization alone.
- MemoryAllocationHelper (0x00494FB0, 0x00494FE0): global dword_8AFE64 is flagged as read by packet facts but never appears in either raw body; the legacy ABI label Short_Computation_Surface_Font_Push_Wrapper contradicts the allocator-callee behavior and is presumed stale; the meaning of the constant-zero third argument passed to MemoryAllocation_cb20 is unknown.
- HashTableStringResolver (0x00495810): the exact normalization performed by sub_589901 is not defined here; the compound-key layout (raw 4-byte dword_5CC79C plus extension byte_5CC7A0) is DERIVED from the raw write pattern; the sub_587C20 return contract (non-zero meaning present) is DERIVED from the branch structure; global 0x007CDE00 is flagged but never appears in the raw body.
- DoublyLinkedListTailAppender (0x00495A80): the corpus field this+0x78 (cached/sentinel traversal start) is not directly dereferenced in the raw body, which starts the tail walk from the head at this+0x14; the node link offsets (+0x64 next, +0x68 prev) are identified only from the raw literals 100 and 104; the list that a2 is appended into is not visible in this function.
- LargeStateStructInitializer (0x00496560): global dword_5AC98C is flagged as read but never appears in the raw body; unk_888888 is treated by the raw source as an address literal written into dword slots 45/46, which overlap float slots 45/46, so the intended type (pointer vs float bit pattern) is ambiguous; the owning aggregate class is unknown.
- RectangleRenderer (0x004972B0): global unk_7CDE00 is read (R) but never appears in the raw body and is likely the object GlobalAccessor_5150 returns, unproven; the exact meaning of a1 (color/pattern word) and a2 is not evidenced beyond the two color-mask expressions; the relationship between the initial DelegationWrapper border draw and the four per-iteration edge draws is not fully specified.
- SearchableListDispatch (0x004974A0): the owner class and the meaning of this+0x4 (list head) and this+0xC (current-node cursor, rewritten each call) are unknown; the byte 1 written by ShortComputation_7250 lands in a field whose offset is not evidenced in this packet (prior analysis suggests this+0x25, DERIVED); what SetterVirtualCall configures on the matched node depends on the caller.
- DoublyLinkedListNodeContainer (0x00497510): the side effects of SimpleSetter_fdf0 and SimpleSetter_fc40 are opaque; the node-internal offsets (data+0, next+4, prev+8, flag+12) appear only in the raw source with no separate field evidence; the role of the secondary pointer this+0xC (set with head on first insert but never consulted here) is unresolved.
- ObjectRegistrationHelper (0x00497590, 0x004975B0): the object layout of the target (fields at 0x40 and 0x98) and the meaning of the stored values are not known; the semantics of ObjectRegistration (0x00499360) and the identity of the registered object type are caller-context only; a4 in 0x00497590 and a3 in 0x004975B0 are unused in their raw bodies.
- StateModeConfigurator (0x004977E0): the purpose and side effects of sub_496E90 (called twice with the same argument 1) are unknown, including whether the double call is deliberate or redundant; what the mode value at this+0x1578 selects and what the 0.01f threshold at this+0xDC governs is not visible in this function.
- The two doubly-linked-list containers (0x00495A80 head this+0x14/node links +0x64/+0x68 vs 0x00497510 head this+0x4/node links +4/+8) use different layouts and are not merged; any common base is unproven.
