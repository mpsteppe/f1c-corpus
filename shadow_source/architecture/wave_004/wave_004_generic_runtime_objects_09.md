# RuntimeObjectSystem

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Proposes a small number of defensible classes for the generic runtime object corpus: ScreenDataStruct (the large screen/UI data structure; construction, animation-slot compaction, crash-damage overlay update, scene-entity list teardown and the shared +0xC0 frame-delta getter), ScrollbarArea (packet-assigned), FontRegistry (shared +0x1514 counter and driver/font name handling), plus GUESS-level containers for bitmap-path registration, surface lookup and child-list append. All remaining functions expose insufficient ownership evidence and are left on UnknownObject with their field refs recorded as unresolved. Contradiction noted: offsets +0xF0..+0xFC are used both as BitmapPathRegistry list state and as a zeroed block in the large struct; common ownership is NOT proven.

## Function roles

- `0x00495190` **ScreenDataStruct** — Constructs and zero-initializes the large screen/UI data structure: writes the off_5AC998 vtable at +0x00, sets -1 sentinels at +0x40/+0x155C, zeroes large blocks, runs four 12-byte sub-object constructors at +0x15FC, and calls its sub-initializers.
- `0x00495890` **UnknownObject** — Resolves a formatted string into a hash/ID via the shared lookup ShortComputation_4fb0 using the %s global format buffer; returns the input string on success or NULL.
- `0x00495B60` **ScreenDataStruct** — Compacts the 4-slot 12-byte animation/entry array at +0x15FC, draining slots selected by FloatThresholdCheck, and decrements the shared +0xC0 float timer each iteration.
- `0x00496030` **ScreenDataStruct** — Advances the car-crash damage overlay per frame: randomizes impact type and origin on the first frame, decrements the +0xDC timer by the +0xC0 frame delta, renders damage rects, and clears the damage pointer when the timer expires.
- `0x004970E0` **RenderDispatcher** — Stores a parameter into render-target field +0x1918 and, when guard +0x30 is set, dispatches the render list and returns its result.
- `0x00497100` **ScreenDataStruct** — Tears down the two scene-entity linked lists rooted at +0x18BC/+0x18CC (virtual draw call per item, then conditional free of each node), zeroes the list-state block, and advances a ring buffer.
- `0x00497250` **UnknownObject** — Trivial byte-field setter: stores argument into byte field +0x25 and returns it; shared state/flag write path across seven callers.
- `0x00497260` **ScrollbarArea** — Scrollbar-area render helper (sole caller ScrollbarAreaRendering): draws a pattern rectangle and dispatches a box region with width/height derived from the input coordinates.
- `0x004975D0` **ChildListOwner** — Initializes a child element (backlink, cleared fields, optional string registration) and appends it to the owner's singly-linked child list rooted at +0x1C via next pointers at node +0x8C.
- `0x00497750` **UnknownObject** — Builds a stack rendering context, processes the instance into it, and searches its items by name (default string substituted for null names), returning the matching item.
- `0x00497890` **NestedListSearcher** — Searches an outer/inner linked-list structure for an item equal to a2 and processes each match via a vtable+0x2C virtual call, a setter call, an optional sub_4977E0 hook and a doubly-linked-list append.
- `0x004979D0` **UnknownObject** — Plain dword getter for field +0x20 consumed by UI/session and object-id lookup paths; no side effects.
- `0x004979F0` **BitmapPathRegistry** — Builds a full bitmap path from a base directory plus filename, validates it, and appends a 12-byte registry node into the loader's singly-linked list (head/tail/cursor/count at +0xF0..+0xFC).
- `0x00497E80` **SurfaceLoader** — Walks the loaded-surface list rooted at +0x10C comparing each node by name and returns the surface handle at node +0x50, or 0 when not found.
- `0x00497EC0` **FontRegistry** — Normalizes a driver/font name, rejects blacklist matches, resolves it through the registered-key lookup, and stores the extracted path component into the per-instance name array indexed by the +0x1514 counter.
- `0x00498440` **FontRegistry** — Selects the active font by name from the registered array at +0x114 (80-byte entries, count +0x1514), copying a match to the active-font buffer +0x166C or falling back to the first entry with an error MessageBox.
- `0x00498550` **UnknownObject** — Forwarding thunk: calls sub_498560 on the nested sub-object at this+5740 and returns its int result unchanged.
- `0x00498730` **ScreenDataStruct** — Leaf getter returning the float at +0xC0 (shared frame-delta / timer) widened to double; used by the damage update and slot compaction paths.
- `0x00498880` **UnknownObject** — Copies two adjacent dword fields at +0x5C and +0x60 into output parameters and returns the second value.
- `0x004988A0` **UnknownObject** — Stores an argument into field +0x58 and dispatches a cursor-selection call using global dword_7CB24C, returning its result.
- `0x004988D0` **UnknownObject** — Guarded contextual rendering setup: creates a rendering context from this and a non-empty string, then drives four virtual calls on it (init, Setter, two-field copy, finalize).
- `0x00498E40` **UnknownObject** — Leaf getter returning the dword at +0x50; no side effects.
- `0x00498FE0` **GuardedRenderDispatcher** — Guard-enabled render dispatcher: fills a rectangular region of a render surface, dispatches a secondary render list, walks a draw list invoking each node's vtable+0x44 virtual, and finalizes via vtable+0x2C; always returns 0.
- `0x00499A50` **UnknownObject** — Pure predicate returning TRUE when the float at +0x8 is greater than 0.0; used as the slot-retention test by the compaction path.
- `0x00499CE0` **RuntimeCompositeObject** — Object destructor: installs the off_5ACAAC vtable, recursively destroys a child tree node, frees a linked list at +0x6C, and conditionally frees each pointer field from +0x58 down to +0x10.
- `0x0049A210` **UnknownObject** — Walks a linked list whose head is stored at this+0x00, comparing node strings to a2, and returns the matching node or 0.
- `0x0049A270` **UnknownObject** — Frees three null-guarded pointer fields at +0x10, +0x08 and +0x00, returning the result of the last free that ran.
- `0x0049A2B0` **UnknownObject** — Null-safe dereference of a char** field at +0x00, returning the fallback global string byte_5EA438 when null.

## Proposed classes

### ScreenDataStruct

Large screen/UI overlay data structure (at least 0x18EC bytes). Constructed by LargeStructZeroInit (vtable off_5AC998 at +0x00, -1 sentinels, zeroed blocks, four 12-byte slot constructors at +0x15FC). Owns a four-slot 12-byte animation/entry array drained by AnimationSlotCompactAndProcess, a car-crash damage overlay (timer +0xDC, damage data pointer +0x157C, impact origin +0x1580/+0x1584), a shared +0xC0 frame-delta float, and two scene-entity linked lists rooted at +0x18BC/+0x18CC torn down by SceneEntityCleanup. Common ownership is DERIVED from shared field offsets (notably +0x15FC and +0xC0) and from this-passing call relationships between its methods; the C++ type is not identified.

Methods: `0x00495190`, `0x00495B60`, `0x00496030`, `0x00497100`, `0x00498730`

- `this+0x00000000` `void* vtable_ptr` (read_write, DERIVED)
- `this+0x00000004` `dword zeroed_dword_04` (write, GUESS)
- `this+0x00000008` `dword zeroed_dword_08` (write, GUESS)
- `this+0x0000000C` `dword zeroed_dword_0C` (write, GUESS)
- `this+0x00000010` `dword zeroed_dword_10` (write, GUESS)
- `this+0x0000003C` `dword zeroed_dword_3C` (write, GUESS)
- `this+0x00000040` `int uninitialized_sentinel` (write, DERIVED)
- `this+0x00000058` `dword[16] zeroed_block_58_94` (write, GUESS)
- `this+0x000000C0` `float frame_delta_timer` (read_write, DERIVED)
- `this+0x000000DC` `float crash_damage_timer` (read_write, DERIVED)
- `this+0x000000F0` `dword[4] zeroed_block_F0_FC` (write, GUESS)
- `this+0x00001558` `dword zeroed_dword_1558` (write, GUESS)
- `this+0x0000155C` `int uninitialized_sentinel_155C` (write, DERIVED)
- `this+0x00001578` `int impact_type` (read_write, DERIVED)
- `this+0x0000157C` `void* damage_data_ptr` (read_write, DERIVED)
- `this+0x00001580` `int impact_origin_x` (write, DERIVED)
- `this+0x00001584` `int impact_origin_y` (write, DERIVED)
- `this+0x000018AC` `dword[4] zeroed_block_18AC_B8` (write, GUESS)
- `this+0x000018BC` `scene_entity_node* scene_entity_list1_head` (read_write, DERIVED)
- `this+0x000018C0` `dword scene_entity_list1_state` (read_write, GUESS)
- `this+0x000018C4` `scene_entity_node* scene_entity_list1_cursor` (read_write, DERIVED)
- `this+0x000018C8` `dword scene_entity_list1_indicator` (read_write, GUESS)
- `this+0x000018CC` `scene_entity_node* scene_entity_list2_head` (read_write, DERIVED)
- `this+0x000018D0` `dword scene_entity_list2_state` (read_write, GUESS)
- `this+0x000018D4` `scene_entity_node* scene_entity_list2_cursor` (read_write, DERIVED)
- `this+0x000018D8` `dword scene_entity_list2_indicator` (read_write, GUESS)
- `this+0x000018DC` `dword[4] zeroed_block_18DC_E8` (write, GUESS)
- `this+0x000018EC` `byte damage_cleanup_flag` (write, GUESS)
- `this+0x000018F0` `dword damage_cleanup_dword` (write, GUESS)

### SceneEntityListNode

Twelve-byte linked-list node used by the two scene-entity lists of ScreenDataStruct (roots +0x18BC/+0x18CC): item pointer at node+0, next at node+4, and a byte active flag at node+12 (node+12 not carried as a field ref by the packet).

Methods: 

- `*(this+0x18BC)+0x00000000` `void* item_ptr` (read, DERIVED)
- `*(this+0x18C0)+0x00000004` `node* next` (read, DERIVED)

### SceneEntityItem

Polymorphic item referenced by SceneEntityListNode item pointers; exposes a vtable whose slot 0 and slot +0x44 (render/draw virtual) are invoked during scene-entity list traversal. GUESS: the item type itself is unidentified.

Methods: 

- `*(*(this+0x18BC)+0x0)+0x00000000` `void* vtable_ptr` (read, GUESS)
- `*(*(this+0x18BC)+0x0)+0x00000044` `fn_ptr render_virtual` (read, GUESS)

### ScrollbarArea

Scrollbar-area render helper (packet-assigned DERIVED owner). Sole caller is ScrollbarAreaRendering (0x004868C0). Draws a pattern rectangle and dispatches a box region; no this-field layout is evidenced in the packet.

Methods: `0x00497260`


### FontRegistry

Registry of driver/font name strings. Stores an array of 80-byte name entries at +0x114, a count/index counter at +0x1514, and the active-font buffer at +0x166C. DriverNameStringHandler normalizes and stores names (path component truncated at the separator word_5BEB48); ValidateAndSelectFontName searches the array and falls back to the first entry with an error MessageBox on failure. Common ownership proven by DriverNameStringHandler being called on the same this from ValidateAndSelectFontName and by the shared +0x1514 counter.

Methods: `0x00497EC0`, `0x00498440`

- `this+0x00000114` `char[80][] font_name_array` (read, DERIVED)
- `this+0x00001514` `int name_count` (read_write, DERIVED)
- `this+0x0000166C` `char[80] active_font_buffer` (write, DERIVED)

### BitmapPathRegistry

Loader-side registry of bitmap file paths. Owns a singly-linked list (head +0xF0, tail +0xF4, cursor +0xF8, count +0xFC) of 12-byte nodes (registry pointer at +0, next at +4, alive flag at +8). GUESS: single-function class, owner not otherwise identified. Contradiction flagged: offsets +0xF0..+0xFC are also zeroed as a block inside the large struct; equal offsets on different this pointers do not prove shared ownership.

Methods: `0x004979F0`

- `this+0x000000F0` `node* list_head` (read_write, GUESS)
- `this+0x000000F4` `node* list_tail` (read_write, GUESS)
- `this+0x000000F8` `node* list_cursor` (read_write, GUESS)
- `this+0x000000FC` `int list_count` (read_write, GUESS)

### SurfaceLoader

Loader of named surfaces. Owns a linked list of loaded surfaces rooted at +0x10C; FindSurfaceHandleByName resolves a surface handle by name. GUESS: single-function class, owner not otherwise identified.

Methods: `0x00497E80`

- `this+0x0000010C` `surface_node* surface_list_head` (read, GUESS)

### SurfaceListNode

Node of the loaded-surface list: surface handle at +0x50, next pointer at +0x54. GUESS: node layout rendered by the extractor under the base *(this+0x160); the raw source reaches nodes from the head at +0x10C.

Methods: 

- `*(this+0x160)+0x00000050` `dword surface_handle` (read, GUESS)
- `*(this+0x160)+0x00000054` `node* next` (read, GUESS)

### ChildListOwner

Owner of a singly-linked child-element list (head at +0x1C). InitializeAndAppendChildToList initializes a child element (backlink, cleared fields, optional string registration via sub_49AD50) and appends it at the tail using next pointers at node +0x8C. GUESS: single-function class.

Methods: `0x004975D0`

- `this+0x0000001C` `child_node* child_list_head` (read_write, GUESS)

### ChildListNode

Node of the child-element list with its next pointer at +0x8C. GUESS: next-link offset rendered by the extractor under the base *(this+0xA8), an artifact not present in the raw source, which walks nodes from the head at this+0x1C.

Methods: 

- `*(*(this+0xA8)+0x8C)+0x0000008C` `node* next` (read, GUESS)

### RenderDispatcher

Small render-dispatch helper: stores a parameter into target field +0x1918 and, when the enable guard +0x30 is non-zero, dispatches the render list via RenderDispatchWithIteration and returns its result. GUESS: single-function class.

Methods: `0x004970E0`

- `this+0x00000030` `dword render_enable_guard` (read, GUESS)
- `this+0x00001918` `dword render_target_field` (write, GUESS)

### GuardedRenderDispatcher

Guard-enabled render dispatcher: when the enable flag +0x60 is set, a vtable+0x28 predicate gates a rectangle fill of a render surface, a secondary render list at +0x50 is dispatched, a draw list rooted at +0x4C walks each node's vtable+0x44 virtual, and a vtable+0x2C finalize runs. Always returns 0. GUESS: owner class unknown; rect fields +0x4..+0x10 and list slots +0x4C/+0x50 partially understood.

Methods: `0x00498FE0`

- `this+0x00000000` `void* vtable_ptr` (read, GUESS)
- `this+0x00000004` `int fill_rect_left` (read, GUESS)
- `this+0x00000008` `int fill_rect_right` (read, GUESS)
- `this+0x0000000C` `int fill_rect_top` (read, GUESS)
- `this+0x00000010` `int fill_rect_bottom` (read, GUESS)
- `this+0x0000004C` `render_item_node* draw_list_head` (read, GUESS)
- `this+0x00000050` `void* secondary_render_list` (read, GUESS)
- `this+0x00000060` `dword render_enable_flag` (read, GUESS)

### RenderListItem

Node of the render draw list rooted at GuardedRenderDispatcher +0x4C; each node's vtable slot +0x44 is the draw virtual invoked during list walking. GUESS: node and item types unidentified.

Methods: 

- `*(*(this+0x4C)+0x0)+0x00000044` `fn_ptr draw_virtual` (read, GUESS)

### NestedListSearcher

Searches an outer doubly-linked list (head +0x4, cursor +0xC) and per-outer-node inner lists (next link +0x48) for an item equal to a2, processing each match via optional sub_4977E0 (gated by byte flag +0x1574), DoublyLinkedListAppend_5a80, a vtable+0x2C virtual on the outer node and SetterVirtualCall on the matched item. The dword guard +0x18 selects two list-iteration dispatch helpers. GUESS: single-function class.

Methods: `0x00497890`

- `this+0x00000004` `outer_list_node* outer_list_head` (read, GUESS)
- `this+0x0000000C` `outer_list_node* outer_list_cursor` (read_write, GUESS)
- `this+0x00000018` `dword iteration_guard` (read, GUESS)
- `this+0x00001574` `byte match_hook_flag` (read, GUESS)

### OuterListNode

Node of the outer linked list used by NestedListSearcher: node_object pointer at +0 and next-node link at +4 (the +0x48 inner-list link is read but not carried as a packet field ref). GUESS.

Methods: 

- `*(*(this+0xC)+0x4)+0x00000000` `void* node_object` (read, GUESS)

### OuterNodeObject

Object stored at OuterListNode +0; exposes a vtable whose slot 0 (vtable) and slot +0x2C (process virtual, invoked with argument 1 on a match) are used by NestedListSearcher. GUESS.

Methods: 

- `*(*(this+0x4)+0x0)+0x00000000` `void* vtable_ptr` (read, GUESS)
- `*(*(*(this+0x4)+0x0)+0x0)+0x0000002C` `fn_ptr process_virtual` (read, GUESS)

### DamageDataStruct

Car-crash damage data block referenced by ScreenDataStruct damage_data_ptr (+0x157C). Two of its fields (+4 and +12) act as screen-edge origin references used by the impact-direction random pick. GUESS: layout beyond +4/+12 unknown.

Methods: 

- `*(this+0x157C)+0x00000004` `int edge_ref_a` (read, GUESS)
- `*(this+0x157C)+0x0000000C` `int edge_ref_b` (read, GUESS)

### RuntimeCompositeObject

Object destroyed by DestructorWithMultipleConditionalFrees: installs the off_5ACAAC vtable, recursively destroys a child tree node, frees a linked list at +0x6C, and conditionally frees each pointer field from +0x58 down to +0x10 via FreeWrapper_7bcf. GUESS: type and the payload behind each pointer field unknown.

Methods: `0x00499CE0`

- `this+0x00000000` `void* vtable_ptr` (write, GUESS)
- `this+0x00000010` `void* freed_ptr_10` (read, GUESS)

## Compatibility contracts

- **ScreenDataStructLayoutAndSentinels** — The large screen/UI data structure stores a vtable pointer at +0x00 equal to global off_5AC998; after construction fields +0x40 and +0x155C hold -1 sentinels, the +0x15FC four-slot 12-byte array and the +0x18AC..+0x18E8 blocks are zeroed, and four sub-object constructors run over +0x15FC. A replacement using its own storage must reproduce this layout and sentinel protocol for any consumer of these fields.
- **SceneEntityListNodeLayout** — The two scene-entity lists rooted at ScreenDataStruct +0x18BC and +0x18CC use 12-byte nodes (item pointer at node+0, next at node+4, byte active flag at node+12) whose items expose a vtable with a +0x44 render method; teardown calls each item's vtable+0x44 method, then conditionally frees each node and its item through vtable slot 0. A replacement must preserve the traversal and free protocol.
- **CrashDamageAnimationContract** — The crash-damage overlay runs while the float timer at +0xDC is positive and the damage data pointer at +0x157C is non-null; on the first frame (timer dword equal to 1008981770, float 0.01) the impact type and origin are randomized once into +0x1578 and +0x1580/+0x1584; each call decrements the timer by the +0xC0 frame delta and, when the subtraction crosses zero, the pointer and timer are cleared and rendering stops.
- **FontRegistryLayout** — The font registry stores an array of 80-byte name entries at +0x114, a count at +0x1514, and the active-font buffer at +0x166C; name resolution defaults its result to -1 and falls back to copying the first array entry into the active-font buffer when no entry matches.

## Unresolved

- The concrete C++ type of the large screen/UI data structure (ScreenDataStruct) and most of its fields are unidentified; class ownership is DERIVED from shared field offsets and this-passing call relationships inside the packet, not from type information.
- The four 12-byte sub-objects at +0x15FC (5628) constructed by sub_4999E0 and drained by AnimationSlotCompactAndProcess are unidentified; the retention/expiration polarity of FloatThresholdCheck (retain on float > 0.0) is not deterministically proven.
- The -1 sentinels at +0x40 and +0x155C are uninterpreted; they plausibly mark uninitialized handles or indices.
- The vtable identities behind off_5AC998 (ScreenDataStruct) and off_5ACAAC (RuntimeCompositeObject) are unknown.
- The meaning of the two ints at damage-data +4/+12 (screen-edge origin references) and the purpose of the impact-type 0 vs 1 families (type 1 skips the shared direction table) are inferred, not proven.
- The cleanup fields this+0x18EC (byte) and this+0x18F0 (dword) written by CarCrashDamageProcessing are unnamed.
- SceneEntityCleanup's empty-indicator guards on +0x18C8/+0x18D8 (list empty vs fully drained) are DERIVED; the exact role of each of the eight list-state fields is not pinned.
- The render-list items of GuardedRenderDispatch (vtable slots +0x28 predicate, +0x2C finalize, +0x44 draw) and the meaning of argument a2 are unidentified.
- The byte flag at NestedListSearcher +0x1574 gating sub_4977E0, the a3 forwarded to it, and the target list of DoublyLinkedListAppend_5a80 are unknown.
- The list-head slot at this+0x00 of StringMatchedLinkedListSearch, the inner-list +0x48 next-link, and the traversal helpers sub_499E00 / StringPointerAccessor are not described by the packet.
- The +0xA8 base rendered by the extractor for child-list next pointers (field:*(this+0xA8)+0x8C) does not appear in the raw source, which reaches nodes from the head at this+0x1C; the +0xA8 dereference is an extractor artifact.
- Semantics of the font registry beyond name lookup (80-byte entries at +0x114, count at +0x1514, active buffer at +0x166C) are unconfirmed.
- The global format buffer unk_7CDE38 and the default string byte_5EA438 are shared across multiple functions; their full contents and roles are undocumented.
- Globals unk_7CDE00 and unk_8AFE18 are read along teardown/render paths but cannot be placed deterministically within a single function body.
- The constant 1 passed to ShortComputation_4fb0 and ShortComputation_7250 is undocumented (table index, mode, or size).
- The per-instance driver-name storage array addressed as this[20*index+69] has an unconfirmed fixed base and size; the register is the counter at +0x1514.
- The cursor-selection callee of FieldSetterCall (named CursorSelectorFromArray / FUN_0044f640) is not in the packet's callee list; its address and behavior are unconfirmed, as is the meaning of global dword_7CB24C.
- Whether the +0xF0..+0xFC list-state block of BitmapPathRegistry and the +0xF0..+0xFC zeroed block in the large struct belong to the same object is unproven; equal offsets on different this pointers do not prove shared ownership.
- The float constants flt_59E440/flt_59E6F8 (presumed 100.0 and related scales) are not read from the packet; flt_59E440's relation to FloatThresholdCheck's 0.0 comparison is unresolved.
- The 5740-byte nested sub-object advanced to by ShortComputationForwarder and the meaning of sub_498560's int result are unknown.
- The rendering-context stack buffer built by SearchRenderingContextByName (PassthroughWrapper + sub_4998E0, item name at +0x34) has no owner type evidence.
- The object type owning releaseTriplePointerList's three freed pointer fields is unknown; the pattern suggests a small dynamic container.
- ScreenDataStruct's +0xC0 float is exposed by FloatFieldAccessor to 13 callers; whether all callers operate on the same object type is unconfirmed.
- The exact comparison semantics of sub_588410 (0 = match) are inferred from loop-exit conditions across four functions, not independently proven.
- ContextRenderingSetup's sub-object at this[6] (+0x18) with validity field +80, the context vtable slots +140/+144, and the two dword fields copied by TwoFieldSetter_3050 are unidentified.
- The 'called by' relationships to functions outside the packet (ScreenDataStructInit 0x0047F370, sub_496E90, sub_4920B0, sub_492160, sub_492A40, sub_493060, sub_493480, sub_4F9480, and the UI-render callers) were not validated against their own function IR.
