# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Derived architecture proposal for 22 validated functions in scope generic_runtime_objects. All packet owners are UNKNOWN, so every class is a proposal: FrontendScreen (DERIVED) owns the global screen object at dword_7CD8C0 via full init 0x00485B90 and teardown 0x00485DF0 and drives the dword_5CC9E8 session-init state machine. UIWidget (GUESS) groups the field/text-box renderer 0x00487F70 and 0x004883D0 with their helpers (0x00487060, 0x004871E0, 0x00486720, 0x00486460) and the UI element constructor 0x004742A0. UIListController (GUESS) groups the list/screen builders 0x00477830 (Game Filter track list), 0x00477CB0 (profile-icon bitmap list), 0x00489CB0 (list teardown), 0x00486F30 (string-list insert/replace) and 0x00477280 (object-name compare / viewport node alloc). UIListNode (GUESS) captures the shared list-node layout (+0 vtable, +4 next, +0x30 data, +0x8C alternate next). ProfileIconResolver (DERIVED) pairs 0x00478320/0x00478390 through the shared this+0xE0 resource-list slot. GenericRuntimeObject (GUESS) is the residual set (0x00472BC0, 0x00474C80, 0x00476250, 0x004767C0, 0x00477680, 0x004793EC). A CommandDispatchInterface (GUESS) captures repeated vtable-slot-28 dispatch on dword_7CD8C0 with integer IDs (18/19/21) and slot-0 release on shutdown. Several this offsets carry conflicting semantics across functions (+0x9C, +0x31C, +0x40, +0xC8, +0xE0, +0x168); these contradictions are recorded in unresolved.

## Function roles

- `0x00472BC0` **GenericRuntimeObject** — Conditional scene-graph window-control query: runs WindowControlTypeDetection, resolves a control object from the global dispatch root dword_7CD8C0 via vtable slot +28 with type 19, then calls ObjectNameComparison on the resolved object when non-null; returns 0
- `0x004742A0` **UIWidget** — UI element constructor: pre-init helper, installs vtable off_5A3840, stores camera pointer at +0x31C, writes config literal run (+0x324..+0x334) and 392 at +0x334, registers two text-handle nodes via LinkedListInsertWithNodeAllocation (off_5BE704 and aOn), then triggers virtual action-ID dispatch
- `0x00474C80` **GenericRuntimeObject** — Element/track ID to power-of-two bitmask mapping: switches on this[199] (+0x31C); 0x1A2..0x1AC map to 1..1024 and return 1, any other value writes -1 and returns 0; jump table at 0x00474DA4
- `0x00476250` **GenericRuntimeObject** — Frontend loading display/audio handler: obtains scene list element, resolves scene object via container at this+0x40 (vtable +28, id 1), copies scene name, builds audio path from season dir, loads/decodes audio, dispatches game filter command and triggers +160 virtual play/show calls; returns 0
- `0x004767C0` **GenericRuntimeObject** — Renderer state counter reset: zeroes this+0x168 (dword index 90) then returns UITileGrid() result (UI tile-grid redraw)
- `0x00477280` **UIListController** — Object-name compare against a viewport-node doubly linked list: compares name pointers at this+0x9C and a2+156; on match scans the list (head +0xF0, count +0xFC) for a node whose +0x30 data equals a2 and runs ViewportRectSizeCalc; on miss allocates/constructs a 52-byte node, runs viewport calc and vtable+16, appends it, returns UIViewportLayoutCalculator(this)
- `0x00477680` **GenericRuntimeObject** — Track-scene configuration loader: gates on config list element + pointer table at byte 60, reads config value 1 into a 512-byte buffer, resolves season scene by name, updates font handle dword_8AC38C from dword_8AC36C, retrieves current vehicle table (unk_8AC388) and copies vehicle name and entry-name (index 47) strings
- `0x00477830` **UIListController** — Game Filter screen builder: captures UI dimensions, tears down widget lists (virtual destructor + free per node, zeroes +0xF0..+0xFC), cleans resource list at +0x180, rebuilds track filter, iterates track list allocating one widget per track (car-icon handle + track name), appends each, finalizes viewport layout; returns 0
- `0x00477CB0` **UIListController** — Profile-icon bitmap list rebuild: frees existing list items (optional first vtable method), zeroes list/layout state, enumerates BMP files in the profile icon directory, loads each bitmap, allocates UI widget, copies path and extension-less base name, appends; default-icon fallback; recalculates viewport layout; returns 0
- `0x00478320` **ProfileIconResolver** — Resource query and stored setup: dispatches on global dword_7CD8C0 vtable slot +28 with resource ID 18, stores the non-null result at this+0xE0 and runs ProfileIconPathSetter; returns 0
- `0x00478390` **ProfileIconResolver** — Profile-icon path setter: resolves a resource node from the list at this+0xE0, reads its path string at node offset 48 (fallback byte_5EA438) and writes it to global lpExistingFileName; silent return when a link is null
- `0x004793EC` **GenericRuntimeObject** — File-path resolver with extension append: extracts basename, assembles two extension suffixes from globals (0x005C71C0/0x005C71C4/0x005C71C8 and 0x005C7190/0x005C7194/0x005C7196), strips trailing backslashes in byte_7CD718, resolves via sub_497AD0, copies resolved path (or byte_5EA438 fallback) to caller buffer, hands path to sub_479170
- `0x00485B90` **FrontendScreen** — Top-level menu init and game state machine: sets session init state dword_5CC9E8 = 5, branches on whether the screen interface dword_7CD8C0 exists (re-entry vs full init of the 8612-byte screen struct plus renderer, profile, UI tree, audio mixer, multiplayer auto-join), then dispatches on dword_5CC9E8 (-1 shutdown, 2 host setup, 1 game start, 5->0) and handles the add-profile popup flag
- `0x00485DF0` **FrontendScreen** — Global manager shutdown sequence: calls sub_4963D0 with dword_7CD8C0, dispatches the object's vtable slot 0 with argument 1 when non-null, nulls the global, returns sub_4B0770(1)
- `0x00486460` **UIWidget** — Indexed list-node lookup: loads sub-object from this[50] (+0xC8), returns 0 if null, reads its list head (+8) and bound (+12), walks a2 steps along +36 next pointers and returns the reached node
- `0x00486720` **UIWidget** — Read-only accessor returning the dword at this+0x84 (index 33) unchanged; wide caller set across UI/state-machine/media/vertex paths
- `0x00486F30` **UIListController** — String-list insert/replace: when a3 <= 0 allocates an 8-byte string node and a 12-byte list node and prepends to the list (+0x44 head, +0x48 tail, +0x4C cursor, +0x50 count); when a3 > 0 seeks to the index and replaces the selected node's string via StringCopyWithBufferRealloc
- `0x00487060` **UIWidget** — Y-offset linked lookup with guard: reads base Y-offset from this[3] (+0xC), computes a boundary, and reads a short via LinkedListIndexedFieldReader; when a2 is at/above the boundary the guard flag this[50] (+0xC8) must be set; returns v3 + value or -1
- `0x004871E0` **UIWidget** — Thin forwarding wrapper: calls sub_487060(this, 0) and returns its result unchanged
- `0x00487F70` **UIWidget** — UI field render with text and optional centered bitmap: validates label (+0xB0) and visibility (+0xC8), selects context via accessors, binds render base (+0x40), measures and centers label using bounds +0x4..+0x10 and layout substructs +0x98/+0x9C, renders via BitmapDraw_81f0, writes output rectangle; 0 on success, -1 without label/layout
- `0x004883D0` **UIWidget** — Scrollable UI text-box render with optional scrollbar: acquires content sub-object via ConditionalDelegation (+0x64 60), computes scroll thumb geometry from +0xE0 and virtual bounds, draws content surface, handles optional scrollbar sub-object (+0xE4/+0xE8/+0xEC), draws header (+0xB0) and body (+0xB8) text, writes enclosing output rectangle; returns 0
- `0x00489CB0` **UIListController** — State-cleanup notification: destroys every node of the list (head +0x90) via its vtable destructor, advancing via the +0x8C next link, resets head/count/selection (+0x90, +0x94, +0x168 = -1), then invokes vtable slot +0x2C with argument 1 and returns its result

## Proposed classes

### FrontendScreen

Global frontend screen/manager object rooted at dword_7CD8C0: full initialization (allocate 8612-byte screen struct, renderer viewport 800x600, player profile, UI element tree, audio mixer, multiplayer auto-join) in 0x00485B90 and the matching shutdown sequence in 0x00485DF0 (vtable slot 0 release + global null). Owns the dword_5CC9E8 session-init state machine.

Methods: `0x00485B90`, `0x00485DF0`


### UIWidget

Generic UI field/text-box widget: constructor writes vtable, camera pointer and a config literal run (0x004742A0); renders a text field with optional centered bitmap (0x00487F70); renders a scrollable text box with optional scrollbar (0x004883D0); Y-offset guarded lookup (0x00487060) and its zero-selector wrapper (0x004871E0); dword accessor at +0x84 (0x00486720); indexed sub-object list lookup (0x00486460). Owns label/body strings, visibility flag, bounds, render base, scroll and scrollbar geometry.

Methods: `0x004742A0`, `0x00486460`, `0x00486720`, `0x00487060`, `0x004871E0`, `0x00487F70`, `0x004883D0`

- `this+0x00000000` `pointer vtablePtr` (read, GUESS)
- `this+0x00000004` `int leftBound` (read, GUESS)
- `this+0x00000008` `int topBound` (read, GUESS)
- `this+0x0000000C` `int widthBound` (read, GUESS)
- `this+0x00000010` `int heightBound` (read, GUESS)
- `this+0x00000040` `pointer renderBase` (read, GUESS)
- `this+0x00000084` `dword accessorDword_84` (read, GUESS)
- `this+0x00000098` `pointer altLayoutSubStruct` (read, GUESS)
- `this+0x0000009C` `pointer layoutSubStruct` (read, GUESS)
- `this+0x000000B0` `pointer labelString` (read, GUESS)
- `this+0x000000B8` `pointer bodyString` (read, GUESS)
- `this+0x000000C8` `dword visibilityOrGuardFlag` (read_write, GUESS)
- `this+0x000000E0` `int scrollPosition` (read, GUESS)
- `this+0x000000E4` `int scrollbarWidth` (write, GUESS)
- `this+0x000000E8` `int scrollbarHeight` (write, GUESS)
- `this+0x000000EC` `byte scrollbarEnabled` (read, GUESS)
- `this+0x0000031C` `pointer cameraPointerOrElementId` (write, GUESS)
- `this+0x00000324` `int configFlag_324` (write, GUESS)
- `this+0x00000328` `int configFlag_328` (write, GUESS)
- `this+0x0000032C` `int configFlag_32C` (write, GUESS)
- `this+0x00000330` `int configFlag_330` (write, GUESS)
- `this+0x00000334` `int configLiteral_334` (write, GUESS)
- `*(this+0x98)+0x00000004` `int altLayoutField_4` (read, GUESS)
- `*(this+0x98)+0x0000000C` `int altLayoutField_C` (read, GUESS)
- `*(this+0x9C)+0x00000004` `int layoutField_4` (read, GUESS)
- `*(this+0x9C)+0x0000000C` `int layoutField_C` (read, GUESS)

### UIListController

UI list/screen builder: rebuilds the Game Filter track list (0x00477830), rebuilds a scrollable profile-icon bitmap list (0x00477CB0), destroys all nodes of a widget list and resets list state (0x00489CB0), inserts/replaces string nodes in a string list (0x00486F30), and matches object names against a viewport-node list, allocating a 52-byte node when absent (0x00477280). Holds the string-list (+0x44..+0x50), node-list (+0x90/+0x94) and widget-list (+0xF0..+0xFC) heads plus selection/layout state.

Methods: `0x00477280`, `0x00477830`, `0x00477CB0`, `0x00486F30`, `0x00489CB0`

- `this+0x00000044` `pointer stringListHead` (read_write, GUESS)
- `this+0x00000048` `pointer stringListTail` (write, GUESS)
- `this+0x0000004C` `pointer stringListCursor` (read_write, GUESS)
- `this+0x00000050` `int stringListCount` (read_write, GUESS)
- `this+0x00000090` `pointer nodeListHead` (read_write, GUESS)
- `this+0x00000094` `int nodeListCount` (write, GUESS)
- `this+0x000000F0` `pointer widgetListHead` (read_write, GUESS)
- `this+0x000000F4` `pointer widgetListLink2` (write, GUESS)
- `this+0x000000F8` `pointer widgetListLink3` (write, GUESS)
- `this+0x000000FC` `int widgetListCount` (read_write, GUESS)
- `this+0x00000168` `int selection` (read_write, GUESS)
- `this+0x00000174` `dword layoutFlag` (write, GUESS)

### UIListNode

Linked-list node shared by the UI widget/string lists: first dword is the vtable/destructor pointer, +4 is the next-node link, +0x30 is the payload data pointer for viewport nodes, and +0x8C is an alternate next link on the list-controller walk in 0x00489CB0.

Methods: 

- `*(this+0xF0)+0x00000000` `pointer vtable` (read, GUESS)
- `*(this+0xF0)+0x00000030` `pointer data` (read, GUESS)
- `*(this+0xF4)+0x00000004` `pointer next` (read, GUESS)
- `*(*(this+0xF0)+0x0)+0x00000000` `pointer vtableSlot0Destructor` (read, GUESS)
- `*(this+0x90)+0x00000000` `pointer nodeVtable` (read, GUESS)
- `*(this+0x11C)+0x0000008C` `pointer nextLink8C` (read, GUESS)

### ProfileIconResolver

Profile-icon resource resolution: queries the global command-dispatch interface (dword_7CD8C0) for resource ID 18, stores the returned list at this+0xE0 (0x00478320), and resolves the profile-icon path from that list into global lpExistingFileName (0x00478390).

Methods: `0x00478320`, `0x00478390`

- `this+0x000000E0` `pointer resourceListPointer` (read_write, DERIVED)

### GenericRuntimeObject

Residual runtime helpers with no provable common owner: conditional scene-graph window-control query through the global dispatch root (0x00472BC0), track/element-ID to bitmask mapping (0x00474C80), frontend loading display/audio handler (0x00476250), renderer state counter reset before the UI tile-grid draw (0x004767C0), track-scene configuration loader (0x00477680), and file-path resolver with extension append (0x004793EC).

Methods: `0x00472BC0`, `0x00474C80`, `0x00476250`, `0x004767C0`, `0x00477680`, `0x004793EC`


## Compatibility contracts

- **CommandDispatchSlot28Contract** — The global command/resource dispatch interface at dword_7CD8C0 must expose a vtable whose slot +28 resolves a sub-object given an integer resource/type ID (18 profile-icon resource, 19 window-control object, 21 loading-scene object), and whose slot 0 releases the object during the global shutdown sequence (0x00485DF0).
- **SessionInitStateProtocol** — dword_5CC9E8 drives the frontend session-init state machine: 5 menu/init entry (reset to 0), 2 session-host setup, 1 game-start, -1 shutdown; an a2 non-zero argument forces -1. A replacement must preserve this state protocol and the dword_5CC9E4 menu-state mirror.
- **ProfileIconPathOutputContract** — Profile-icon path resolution writes the resulting path string into global lpExistingFileName (0x005C6658); the profile icon directory is read from dword_5EC3F8 with a byte_5EA438 fallback. A replacement must honor this global output convention.
- **FrontendScreenAllocationContract** — Full frontend init allocates an 8612-byte screen struct (0x00485B90), initializes it via ScreenDataStructInit and installs it at dword_7CD8C0; the shutdown sequence releases it through vtable slot 0 and nulls the global (0x00485DF0).
- **TrackConfigLoadSequenceContract** — Track-scene config load (0x00477680) requires a non-null config element and its pointer table at byte offset 60; it reads config value 1, resolves the season scene by name, updates font handle dword_8AC38C from the dword_8AC36C list, and copies the current vehicle name (index 0) plus entry-name (index 47). Called during CopyProfileIconBMP and GameMode setup.

## Unresolved

- Several this+ offsets carry CONFLICTING semantics across functions and therefore likely belong to distinct object types that this packet cannot separate: +0x31C (camera pointer write in 0x004742A0 vs element/track ID read in 0x00474C80), +0x40 (render base in UIWidget vs a container object with vtable+28 dispatch in 0x00476250), +0x9C (layout substruct in 0x00487F70 vs name-object pointer in 0x00477280), +0xC8 (visibility/guard flag in 0x00487F70 and 0x00487060 vs sub-object pointer in 0x00486460), +0xE0 (scroll position in 0x004883D0 vs resource-list pointer in 0x00478320/0x00478390), +0x168 (renderer counter reset in 0x004767C0 vs list selection reset to -1 in 0x00489CB0). The UIWidget/UIListController/GenericRuntimeObject groupings are provisional merges.
- obj-based fields (field:obj:0x00000018/0x1C/0x20/0x24/0x2C/0xAC) have an unresolved base-object identity; the context-slot and surface-extent semantics in RenderField/RenderScrollableTextBox are inferred only.
- The exact object type and full vtable of the global at dword_7CD8C0 (screen struct vs dispatch interface) is not resolvable from this packet; slot +28, slot 0 and +160 play/show semantics are all unproven.
- Globals flagged by packet facts but absent from the decompiled bodies: byte_7CE498/dword_7CE64C/dword_7CE668 (0x00477680), dbl_59E420/flt_59E450 (0x004883D0), unk_8AC368/dword_8AD3B4 (0x00477830). None are verifiable from this packet.
- guard:0 in 0x00477CB0 may encode a list-initialized flag convention enforced elsewhere; the node byte at +12 and the first vtable method invoked with argument 1 are unexplained.
- 0x00477280 viewport-node handling: the 52-byte node layout, the list-search pointer chase (node +0x30 data vs per-index walk) and the roles of this+0xD0 and this+0xF8 are unresolved.
- The +160 virtual play/show calls in 0x00476250 and the unconditional vtable slot +0xAC dispatch in 0x004883D0 have unproven semantics.
- The session/network sub-struct at unk_7CE24C and the multiplayer auto-join state at dword_7CD25C are not modeled beyond the call order in 0x00485B90.
- 0x00486F30 may have a latent bug: on the prepend path a failed list-node allocation still advances tail (+0x48) and count (+0x50) when the node is null.
- The two extension literal groups (0x005C71C0/0x005C71C4/0x005C71C8 and 0x005C7190/0x005C7194/0x005C7196) and sub_587DD0 copy semantics are not defined by this packet.
- Callers of 0x00485B90 (caller:0x004A0EB0, caller:0x004A0FD0) and of 0x00486720 (broad UI/state-machine/media/vertex set) are outside this reconstruction and their invocation context is not modeled.
