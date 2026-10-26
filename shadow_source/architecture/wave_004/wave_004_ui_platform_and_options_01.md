# UIPlatformAndOptions

Scope: `ui_platform_and_options`  
Trust: `DERIVED`

DERIVED architecture proposal for the ui_platform_and_options scope. The packet covers twenty-two functions grouped into five layers. (1) File/scene path layer: PlatformPathServices (0x0040DC00) builds a file path from a config/track base (dword_7CE5D0, falling back to byte_5EA438), strips any existing extension, appends a separator plus extension, and invokes an out-callback; SceneListBuilder (0x0046A2A0) clears and rebuilds the scene linked list from the global scene array (dword_8AC490 / count dword_8AC488), trimming each name to its final backslash component before load. (2) Session routing layer: SessionScreenRouter (0x0046FC30) routes the post-session state to a championship, multiplayer host/client grid, or main-menu screen based on the race-mode global dword_7D0410. (3) Constructor family: UIComponentBase groups the shared component-constructor layout (base init 0x00466D60, vtable install, data-source pointer at this+0x31C, value-count/current/range state block at this+0x324..0x330, component id at this+0x334) seen in 0x004711A0, 0x00471540, 0x004718E0, 0x00471970 and 0x004726C0; UIOptionsScreen (0x00476030) derives from the base UI object constructor 0x0048FC50; UIStyleControlBase (0x00485E30) is a shared seventeen-constructor initializer with zeroed general fields and five sentinel-guarded range pairs; UIBaseControlStruct (0x0048E9E0) initializes a base control struct with a vtable and -1 sentinel. (4) Menu/list widget layer: UIMenuListController groups the list widget operations (item creation 0x00489600, indexed item fetch 0x00489A10, search by name 0x00489A50, search-and-select 0x00489BA0, item text set 0x00489C10, filtered rebuild 0x0048A3C0) over a node list with next-link at node+0x8C and label at node+0xB0 (UIMenuItemNode); UIStringPropertyControl (0x00488B40) compares and replaces a stored string; UIMenuLayoutViewport (0x0047B850) computes the active menu item from margins, item height and scroll offset; SeasonResultsMenuBuilder (0x0047D800) descends the season data tree and creates paired driver/time menu items. (5) Layout/collision layer: UITileGrid (0x0048F870) computes and places tile screen positions from a cell/spacing grid; CollisionRegionBuilder (0x00491960) validates positive dimensions and forwards them to two collision-broadphase builder slots. Owner is UNKNOWN for most functions; UITileGrid and SessionScreenRouter owners are DERIVED from the packet. Class grouping is a GUESS-level interpretation of shared constructor patterns and linked-list layouts; equal byte offsets on different 'this' bases are kept as separate fields.

## Function roles

- `0x0040DC00` **PlatformPathServices** — Builds a file path string and invokes an out-callback with it. Selects the base path dword_7CE5D0 (falling back to byte_5EA438), concatenates it with the extension string off_5BEB4C into a heap buffer, truncates at the last '.' to strip an existing extension, appends the separator word_5BEB48 and extension off_5BEB4C, calls the callback 0x0040DBE0, frees the buffer, and returns the callback result (0 on allocation failure). Invoked by Steward_Restart (0x004D3CF0) as part of a track/configuration file path.
- `0x0046A2A0` **SceneListBuilder** — Clears and rebuilds the scene linked list from the global scene array: LinkedListDestructionWithVTableCall (0x0048D230) clears the old list, the loop reads the count from dword_8AC488 and iterates the array at dword_8AC490 (stride 396, name at entry+4), trims each name to the last backslash component, formats the filename via the format table off_5C6660, loads the scene object through 0x00497AD0 (falling back to off_5C665C), and appends the node with 0x0048D2B0.
- `0x0046FC30` **SessionScreenRouter** — Routes the post-session state to a UI screen based on the race-mode global dword_7D0410. Optionally stops the sound engine (dword_5EB10C vtable slot +12) and resets the buffer flt_5EA618; mode 4 (championship) calls 0x004A0760 then opens the post-race driver screen aChPostracedriv via GuardedFunctionDispatch (0x00486AA0); mode 5 (multiplayer) uses StateCheckWrapper (0x00461DC0) on dword_7CD25C to open the host grid aMphostgrid or client grid aMpclientgrid via LookupDispatch (0x00497940) on dword_7CD8C0; otherwise opens the main menu aMainMenu and sets the session-init global dword_5CC9E8 to 3.
- `0x004711A0` **UIComponentBase** — UI-mode object constructor: runs the base initializer 0x00466D60 with flag 1, installs the vtable off_5A0B40 at this+0x0, stores the address of dword_7D0A20 into this+0x31C, and writes the literal fields 99/2/1/1 at this+0x324/+0x328/+0x32C/+0x330. No guards; returns this.
- `0x00471540` **UIComponentBase** — UI component constructor (component ID 236): base init 0x00466D60 with 1, vtable off_5A0E40 at this+0x0, data-source interface dword_7CE73C bound at this+0x31C, state block this+0x324=2/+0x328=0/+0x32C=1/+0x330=1, component id 236 at this+0x334, then inserts the three handle globals off_5BE704/off_5C32A4/aHigh (0x005C32A8) via 0x00486F30 with index -1 and dispatches the post-construction virtual 0x004670E0.
- `0x004718E0` **UIComponentBase** — UI component constructor (component ID 243): identical sequence to 0x00471540 with vtable off_5A1380, data source dword_7CE760 at this+0x31C, state block 2/0/1/1, component id 243 at this+0x334, the same three handles inserted with index -1, and post-construction dispatch 0x004670E0.
- `0x00471970` **UIComponentBase** — UI component constructor (component ID 244): identical sequence to 0x00471540 with vtable off_5A1440, data source dword_7CE7F0 at this+0x31C, state block 2/0/1/1, component id 244 at this+0x334, the same three handles inserted with index -1, and post-construction dispatch 0x004670E0.
- `0x004726C0` **UIComponentBase** — UI options component constructor: base init 0x00466D60 with 1, vtable off_5A2040 at this+0x0, data-source interface dword_7CFF84 at this+0x31C, option count 3 at this+0x324, initial/current value 1 at this+0x328, boundary fields 1 at this+0x32C and this+0x330, component identifier 259 at this+0x334, and default-selection sentinel -1 at this+0x338.
- `0x00476030` **UIOptionsScreen** — Options-screen UI object constructor: calls the base UI object constructor 0x0048FC50 unconditionally, installs the options vtable off_5A4428 at this+0x0, zeroes the state/flag field at this+0x3C, and returns the object.
- `0x0047B850` **UIMenuLayoutViewport** — Menu item layout calculator: reads the item height at this+0xF4 (returns 0 if not positive), derives the usable width from the width argument minus margins this+0xF8/this+0xC, maps the height into a clamped line index over this+0xF0-1, then walks wrapped items from the scroll offset this+0xEC via MenuCursorNavigationHelper (0x0047B730) until the queried index is found, resolves a resource-path string through this+0xC8 (falling back to byte_5EA438, processed by 0x00498560), and renders through MenuItemRenderHelper (0x0047B910).
- `0x0047D800` **SeasonResultsMenuBuilder** — Season results/leaderboard menu builder: resets UI state (StateCleanupNotification 0x00489CB0), locates the season races section with 0x004C5840 rooted at unk_8AC368, descends the prevyear/grid/drivers+times keys with StringKeyedLinkedListSearch (0x005679C0), and when the driver and time list counts match (LinkedListCount 0x00567980) iterates both, pairs each driver name with its time via the byte_5EA438 separator using the format string at 0x005C6784, and creates one UI menu item per pair with UIMenuItemCreator (0x00489600).
- `0x00485E30` **UIStyleControlBase** — Shared UI-style component initializer used by seventeen UI-family constructors (0x0047A9E0, 0x00487220, 0x00487660, 0x00487ED0, 0x00488180, 0x00488B00, 0x00488F90, 0x004893C0, 0x0048B420, 0x0048D3A0, 0x0048E070, 0x0048E600, 0x0048EAA0, 0x0048FB70, 0x0048FE60, 0x00490250, 0x00493FC0): runs the base initializer 0x0049A930, zeros the general fields this+0x44..0x60 and this+0x70..0x7C, initializes five (min=0, max=-1) sentinel range pairs at this+0xA0/0xA4 .. 0xC0/0xC4, installs the vtable off_5AB8C0, and runs the final setup 0x00486010.
- `0x00488B40` **UIStringPropertyControl** — UI string compare-and-set: returns -1 when a2 is null; otherwise compares a2 against the stored string at this+0xB0 (falling back to byte_5EA438) and, when they differ, copies the new string via StringCopyWithBufferRealloc (0x00566650) and invokes the vtable slot at obj offset 0x2C with argument 1 to notify/reload. Returns 0 on the equal or updated path.
- `0x00489600` **UIMenuListController** — UI menu item creator: early-exits with -1 when the label a2 is null, allocates a 232-byte item block, initializes its vtable via 0x00488F90, copies the label and up to three further strings (fallback from a3, then this+0xB8, then byte_5EA438) with StringCopyWithBufferRealloc (0x00566650), registers the item into the list controller with 0x00486340, pops a list entry with 0x00489480, dispatches the controller vtable slots at obj offsets 0x2C and 0xAC, and returns 0.
- `0x00489A10` **UIMenuListController** — Linked-list item lookup by index (UI_List_Item_by_Index): returns null when a2 is negative or the head at this+0x90 is null, walks the next-node links at node+0x8C for a2 steps, returns the string at node+0xB0 of the target node (byte_5EA438 when null). Sole caller is 0x0046BA20.
- `0x00489A50` **UIMenuListController** — Linked-list search by name: returns 0 when a2 or the head at this+0x90 is null; walks nodes comparing each node string (node+176, byte_5EA438 when null) against a2 via 0x00588410, writes the match index to *a3 when found and returns 1, otherwise 0.
- `0x00489BA0` **UIMenuListController** — Linked-list search and select: walks the node list from this+0x90 comparing each label (node+0xB0, byte_5EA438 when null) against a2 via 0x00588410 and, on a match, calls UIListSelectionHandler (0x00489AB0) with this, the index and a3. Returns -1 on null inputs, a miss, or list exhaustion; 0 on a successful selection.
- `0x00489C10` **UIMenuListController** — UI list item text setter: bounds-checks the index against the count at this+0x94 (returns 0 out of range), walks the list head this+0x90 to the node at the index, then copies the caller string (byte_5EA438 when null) into the node text buffer via 0x00566650 and returns 1.
- `0x0048A3C0` **UIMenuListController** — Filtered linked-list rebuild: saves the selection index this+0x168 and count this+0x94, obtains reference text via 0x00489970/0x00489920, walks every item, compares each item's text against byte_5EA438 by the filter mode a2 (length or lexicographic via 0x00587ECE/0x00588410, switch table 0x0048A634), copies matches into a new node list via 0x00486400, tracks the new index of the previously selected item, installs the new list head at this+0x90 with the original count restored when the old head was null, and selects the tracked item with 0x00489AB0.
- `0x0048E9E0` **UIBaseControlStruct** — Base UI control struct initializer: installs the vtable off_5A443C at this+0x0, sets the -1 sentinel at this+0x8, zeroes this+0x4 and this+0xC..0x28, copies the default directory string byte_5EA438 via 0x00566650, and returns this.
- `0x0048F870` **UITileGrid** — Tile-grid layout engine (UITileGrid): reads two values through DualFieldRead (0x00498880), computes the column count that fits between this+0x120 and this+0x124 using cell width plus spacing (this+0x160 + this+0x150), clamps to this+0xFC, walks rows (this+0x158) and columns (this+0x15C), finds the tile node per linear index from the list seed this+0xF0 through each node's +4 next pointer (tile object at node+0), computes tile X from this+0x120 and column step (center/right alignment per this+0xE0, offset from this+0x168) and tile Y from this+0x140 and row step, places each tile with 0x0048EA20, then invokes the vtable slot at obj offset 44 with argument 1. Callers: 0x0048F1A0, 0x0048F640, 0x0048FAF0, 0x0048FB30.
- `0x00491960` **CollisionRegionBuilder** — Collision-region builder dispatch with dimension guard: rejects the call when a4 or a5 is not positive (returns 0), otherwise forwards a2/a3/a4/a5 to CollisionBroadphaseBuilder (0x00490EE0) twice, first with the builder pointer at this[0]+28 and then at this[0]+44, returning 1.

## Proposed classes

### PlatformPathServices

Builds a file path from a config/track base plus an extension, strips any prior extension, and hands the result to an out-callback for further processing.

Methods: `0x0040DC00`


### SceneListBuilder

Clears and rebuilds the global scene linked list from the scene array, trimming each scene name to its final path component before loading the scene object.

Methods: `0x0046A2A0`


### SessionScreenRouter

Routes the post-session state to a championship, multiplayer host/client grid, or main-menu screen based on the race-mode global, with an optional sound-engine stop and buffer reset first.

Methods: `0x0046FC30`


### UIComponentBase

Shared UI component constructor pattern: base initializer, vtable install, data-source interface bound at this+0x31C, a value-count/current/range state block at this+0x324..0x330, and a component id at this+0x334 (optionally a default-selection sentinel at this+0x338).

Methods: `0x004711A0`, `0x00471540`, `0x004718E0`, `0x00471970`, `0x004726C0`

- `this+0x00000000` `void* VTablePtr` (write, GUESS)
- `this+0x0000031C` `void* DataSourceInterfacePtr` (write, GUESS)
- `this+0x00000324` `int ValueCount` (write, GUESS)
- `this+0x00000328` `int CurrentValue` (write, GUESS)
- `this+0x0000032C` `int RangeLow` (write, GUESS)
- `this+0x00000330` `int RangeHigh` (write, GUESS)
- `this+0x00000334` `int ComponentId` (write, GUESS)
- `this+0x00000338` `int DefaultSelection` (write, GUESS)

### UIOptionsScreen

Options-screen UI object: derives from the base UI object constructor and installs the options vtable, with a state/flag field cleared at init.

Methods: `0x00476030`

- `this+0x00000000` `void* VTablePtr` (write, GUESS)
- `this+0x0000003C` `int OptionsStateFlag` (write, GUESS)

### UIMenuLayoutViewport

Computes the active menu item from the layout geometry (margins, item height, scroll offset, visible-item ceiling) and drives wrap navigation and rendering.

Methods: `0x0047B850`

- `this+0x00000004` `int TopMargin` (read, GUESS)
- `this+0x0000000C` `int LeftMargin` (read, GUESS)
- `this+0x000000C8` `void* ResourcePathHolder` (read, GUESS)
- `this+0x000000EC` `int ScrollOffset` (read, GUESS)
- `this+0x000000F0` `int MaxVisibleItems` (read, GUESS)
- `this+0x000000F4` `int ItemHeight` (read, GUESS)
- `this+0x000000F8` `int RightMargin` (read, GUESS)
- `this+0x000000FC` `int BottomMargin` (read, GUESS)
- `this+0x00000108` `char* ResourcePathStringPtr` (read, GUESS)

### SeasonResultsMenuBuilder

Descends the season data tree (prevyear/grid/drivers+times) and creates one UI menu item per paired driver/time entry.

Methods: `0x0047D800`


### UIStyleControlBase

Shared initializer for seventeen UI-family constructors: zeros the general-purpose fields, initializes five sentinel-guarded (min=0, max=-1) range pairs, installs a vtable and runs a final setup subroutine.

Methods: `0x00485E30`

- `this+0x00000000` `void* VTablePtr` (write, GUESS)
- `this+0x00000044` `dword GeneralField0` (write, GUESS)
- `this+0x00000048` `dword GeneralField1` (write, GUESS)
- `this+0x0000004C` `dword GeneralField2` (write, GUESS)
- `this+0x00000050` `dword GeneralField3` (write, GUESS)
- `this+0x00000054` `dword GeneralField4` (write, GUESS)
- `this+0x00000058` `dword GeneralField5` (write, GUESS)
- `this+0x0000005C` `dword GeneralField6` (write, GUESS)
- `this+0x00000060` `dword GeneralField7` (write, GUESS)
- `this+0x00000070` `dword GeneralField8` (write, GUESS)
- `this+0x00000074` `dword GeneralField9` (write, GUESS)
- `this+0x00000078` `dword GeneralField10` (write, GUESS)
- `this+0x0000007C` `dword GeneralField11` (write, GUESS)
- `this+0x000000A0` `int RangeMin0` (write, GUESS)
- `this+0x000000A4` `int RangeMax0` (write, GUESS)
- `this+0x000000A8` `int RangeMin1` (write, GUESS)
- `this+0x000000AC` `int RangeMax1` (write, GUESS)
- `this+0x000000B0` `int RangeMin2` (write, GUESS)
- `this+0x000000B4` `int RangeMax2` (write, GUESS)
- `this+0x000000B8` `int RangeMin3` (write, GUESS)
- `this+0x000000BC` `int RangeMax3` (write, GUESS)
- `this+0x000000C0` `int RangeMin4` (write, GUESS)
- `this+0x000000C4` `int RangeMax4` (write, GUESS)

### UIStringPropertyControl

A UI control holding one string that is compared against a caller-supplied value and replaced (with a vtable notification) when it differs.

Methods: `0x00488B40`

- `this+0x00000000` `void* VTablePtr` (read, GUESS)
- `this+0x000000B0` `char* StoredStringPtr` (read_write, GUESS)
- `obj+0x0000002C` `void* NotifyVtblSlot` (read, GUESS)

### UIMenuListController

Owns a linked list of menu item nodes (head at this+0x90, count at this+0x94, selection at this+0x168) and provides item creation, indexed fetch, search, select, text-set and filtered-rebuild operations over the node list.

Methods: `0x00489600`, `0x00489A10`, `0x00489A50`, `0x00489BA0`, `0x00489C10`, `0x0048A3C0`

- `this+0x00000000` `void* VTablePtr` (read, GUESS)
- `this+0x00000090` `void* NodeListHead` (read_write, GUESS)
- `this+0x00000094` `int ItemCount` (read_write, GUESS)
- `this+0x000000B8` `char* FallbackStringPtr` (read, GUESS)
- `this+0x00000168` `int SelectionIndex` (read_write, GUESS)
- `obj+0x0000002C` `void* NotifyVtblSlot` (read, GUESS)
- `obj+0x000000AC` `void* SetLabelVtblSlot` (read, GUESS)

### UIMenuItemNode

A linked-list node of a menu list: holds the next-node link and the label string used by indexed fetch, search, and text-set operations.

Methods: 

- `*(this+0x11C)+0x0000008C` `void* NextNodeLink` (read, GUESS)
- `*(this+0x11C)+0x000000B0` `char* LabelStringPtr` (read, GUESS)

### UIBaseControlStruct

Base control struct initialization: vtable install, -1 sentinel, zeroed rectangle-like field block, and a copied default directory string.

Methods: `0x0048E9E0`

- `this+0x00000000` `void* VTablePtr` (write, GUESS)
- `this+0x00000004` `dword InitField0` (write, GUESS)
- `this+0x00000008` `int UnsetIndexSentinel` (write, GUESS)
- `this+0x0000000C` `int RectField0` (write, GUESS)
- `this+0x00000010` `int RectField1` (write, GUESS)
- `this+0x00000014` `int RectField2` (write, GUESS)
- `this+0x00000018` `int RectField3` (write, GUESS)
- `this+0x0000001C` `int RectField4` (write, GUESS)
- `this+0x00000020` `int RectField5` (write, GUESS)
- `this+0x00000024` `int RectField6` (write, GUESS)
- `this+0x00000028` `int RectField7` (write, GUESS)

### UITileGrid

Computes and places screen positions for tiles in a grid layout from grid bounds, cell width/spacing, row and column counts, alignment mode and offset fields, then invokes a completion vtable slot.

Methods: `0x0048F870`

- `this+0x00000000` `void* VTablePtr` (read, GUESS)
- `this+0x000000E0` `int AlignmentMode` (read, GUESS)
- `this+0x000000F0` `void* TileListSeed` (read, GUESS)
- `this+0x000000F4` `void* TileListNodeBase` (read, GUESS)
- `this+0x000000FC` `int MaxColumnCount` (read, GUESS)
- `this+0x00000100` `int AlignmentSubtype` (read, GUESS)
- `this+0x00000120` `int GridStartX` (read, GUESS)
- `this+0x00000124` `int GridEndX` (read, GUESS)
- `this+0x00000140` `int GridStartY` (read, GUESS)
- `this+0x00000150` `int ColumnSpacing` (read, GUESS)
- `this+0x00000154` `int RowSpacing` (read, GUESS)
- `this+0x00000158` `int RowCount` (read, GUESS)
- `this+0x0000015C` `int ColumnCount` (read, GUESS)
- `this+0x00000160` `int CellWidth` (read, GUESS)
- `this+0x00000164` `int RowStep` (read, GUESS)
- `this+0x00000168` `int TileOffsetValue` (read, GUESS)
- `*(this+0xF4)+0x00000000` `void* TileObjectPtr` (read, GUESS)
- `*(this+0xF4)+0x00000004` `void* TileNodeNextLink` (read, GUESS)

### CollisionRegionBuilder

Validates positive region dimensions and forwards the coordinates to two collision-broadphase builder slots reachable through this[0].

Methods: `0x00491960`

- `this+0x00000000` `void* OwnerObjectPtr` (read, GUESS)

## Compatibility contracts

- **UIComponentStateBlockLayout** — Any replacement UI component constructor must preserve the field layout at this+0x31C (data-source pointer), this+0x324 (value count), this+0x328 (current value), this+0x32C/0x330 (range bounds), this+0x334 (component id) and this+0x338 (optional default-selection sentinel) so that other UI subsystems reading these offsets keep working.
- **MenuListNodeLayout** — Menu list nodes must expose the next-link at node+0x8C and the label string at node+0xB0, with the controller head at this+0x90 and the item count at this+0x94; indexed fetch, search, select and text-set all rely on this layout.
- **DefaultStringFallback** — UI subsystem functions fall back to the global byte_5EA438 string whenever a stored path/label pointer is null (path base, menu label default, list item fallback, separator source); the replacement must keep supplying a valid default string at this global.
- **ScenePathTrimBeforeLoad** — Scene list rebuild assumes scene names are file paths and trims each to the final backslash component before formatting and loading the scene object.

## Unresolved

- The identity and contract of the callback invoked by PlatformPathServices (0x0040DBE0) are unknown; the packet proves only that a constructed path string is passed to it and its return value is propagated.
- Whether dword_7CE5D0 (the base path selected by PlatformPathServices) is a track path or another configuration path is not proven.
- The exact contents of word_5BEB48 (path separator) and off_5BEB4C (extension string) are not evidenced in the packet.
- The caller that triggers the scene list rebuild at 0x0046A2A0 is not statically identified in this packet.
- The exact UI identities of the screen name strings aMainMenu/aChPostracedriv/aMphostgrid/aMpclientgrid are not independently verified beyond their use by the session router.
- The meaning of the session-init value 3 assigned to dword_5CC9E8 is not established.
- The role of the global at 0x007CE24C, listed in the packet facts for 0x0046FC30 but absent from its raw function text, is unknown.
- Roles of the literal constructor fields at this+0x324 (99), this+0x328 (2), this+0x32C (1), this+0x330 (1) in 0x004711A0 are not established; the semantics of the pointer field at this+0x31C receiving the address of dword_7D0A20 are inferred, not proven.
- The exact roles of the three inserted handle globals (off_5BE704, off_5C32A4, aHigh) and the meaning of the 2/0/1/1 state block are DERIVED interpretations, not proven by this packet.
- The identities and behaviors of the data-source objects bound by the constructors (dword_7CE73C, dword_7CE760, dword_7CE7F0, dword_7CFF84) are not documented in this packet.
- The vtable off_5A4428 layout of the options screen and the runtime meaning of its zeroed field at this+0x3C are not confirmed.
- The exact meaning of the wrap-navigation count (this+0xEC scroll offset) and the this+0xF0 ceiling in 0x0047B850 are DERIVED, not runtime-confirmed.
- The format table off_5C6660 and fallback string off_5C665C in the scene builder are only evidenced as format source and load fallback.
- The purpose of the extra zero arguments to UIMenuItemCreator in the season menu builder and the structural count-match requirement between drivers and times are inferred.
- unk_8AC368 as the season data root is DERIVED, not proven.
- The five (min=0, max=-1) sentinel range pairs in 0x00485E30 and the purpose of the final setup 0x00486010 are not confirmed from this packet.
- The destination object of the four StringCopyWithBufferRealloc calls in UIMenuItemCreator is not visible in the raw source; the binding to the newly created item is inferred.
- Semantics of the two vtable dispatches (obj offsets 0x2C and 0xAC) depend on the owning list-controller class, which is not identified; the same applies to the obj offset 0x2C completion slot of UITileGrid.
- The field at this+0x140, present in the packet facts for the menu-list search functions (0x00489A50, 0x00489BA0), does not appear in their raw function text; its role in the list family is unknown.
- FreeWrapper_7bcf appears in the callee list of 0x0048A3C0 but no call to it is visible in the raw source.
- Semantics of the string copied from byte_5EA438 in UIBaseControlStruct and of the zeroed rectangle-like field block are not determined.
- The exact meaning of the two values read by DualFieldRead in UITileGrid and the identity/semantics of the completion vtable slot at obj offset 44 are not established.
- The type and layout of the object referenced by this[0] in 0x00491960 are not established; the two builder pointers at +28 and +44 are read but their meaning is unknown, and the static call target 0x00490EE0 is identical for both calls.
- Whether a4/a5 in 0x00491960 are region dimensions and a2/a3 coordinates is not proven by this packet.
