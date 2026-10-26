# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Generic runtime object layer. UI components are constructed through a shared pattern (base init, vtable install at +0x0, per-component data-source pointer at +0x31C, state words at +0x324..0x330, component ID at +0x334, text-handle linked-list registration, optional post-init action-ID dispatch). A second constructor family initializes through sub_48C070 and writes a literal id at +0x31C plus a bound global pointer at +0x320. Screen setup methods bind a mode global and a list pointer into +0x320/+0x324 and commit formatted text to the UI edit buffer. Several functions verify names through the dword_7CD8C0 dispatch interface (vtable slot +28, object types 11/12/13/19/3). Scene/season name lists are walked to resolve the current scene and trigger its loader. A destructor frees owned buffers and paired allocations, and a parser rebuilds a coordinate linked list from a .rt track file. All structure is DERIVED/GUESS; common ownership of the +0x320/+0x324 pattern is not proven across members.

## Function roles

- `0x0046F490` **UnknownObject** — Builds a path string for the caller-supplied value via PathBuilderWithBackslash into a 256-byte buffer, then appends a new vehicle-config entry to the global linked list rooted at dword_7C73E8 via AddVehicleConfigEntryToLinkedList(&dword_7C73E8, buffer, 0, 1).
- `0x0046FDC0` **NameLookupComparator** — Dispatch-based name verification (flag 0): runs preliminary setup, clears a boolean flag, looks up or creates object type 12 through the dword_7CD8C0 interface (vtable slot +28), and compares the returned object's name with `this` when non-null; always returns 0.
- `0x0046FDF0` **NameLookupComparator** — Structural twin of 0x0046FDC0 with flag set to 1: runs preliminary setup, sets a boolean flag, looks up or creates object type 12 through the dword_7CD8C0 interface (slot +28), and compares the returned object's name with `this` when non-null; always returns 0.
- `0x0046FE20` **NameLookupComparator** — Structural twin of 0x0046FDC0 for object type 13: runs preliminary setup, clears a boolean flag, looks up or creates object type 13 through the dword_7CD8C0 interface (slot +28), and compares the returned object's name with `this` when non-null; always returns 0.
- `0x004707C0` **ScreenSetupMethod** — Race-mode screen parameter initializer: stores the mode global dword_7D0410 into this+0x324 and the address of the parameter float flt_7D122C into this+0x320, then formats the UI list item (index 0) or the float via the '%.1f' literal into the edit buffer; returns 0.
- `0x00470AF0` **PathInitializedUIObject** — UI-list-style object constructor: calls base initializer sub_48C070(this, 1), installs vtable off_5A0780 at +0x0, sets +0x31C to 407, appends two linked-list entries (off_5BE704, aOn) at index -1, and returns the constructed object.
- `0x00471440` **ScreenSetupMethod** — Mode-keyed screen setup: computes a 36-stride list pointer from dword_7D0410 plus base 8187528, stores it into this+0x320, formats the indexed entry into a stack buffer and commits it to the edit buffer; always returns 0.
- `0x00471650` **UIComponent** — UI component constructor (component ID 238): base init, vtable off_5A0FC0 at +0x0, data source dword_7CE7A8 bound at +0x31C, state words 1/0/1/1, component ID 238, two linked-list handles (off_5BE704, aOn), post-init action-ID dispatch.
- `0x004716D0` **UIComponent** — UI component constructor (component ID 239): binds data source dword_7CE910 at +0x31C, single-state configuration, vtable off_5A1080, two linked-list handles, post-init action-ID dispatch.
- `0x00471750` **UIComponent** — UI component constructor (component ID 240): binds dword_7CE718 at +0x31C, state words 2/0/1/1, vtable off_5A1140, three linked-list handles (off_5BE704, off_5C32A4, aHigh), post-init action-ID dispatch.
- `0x004717E0` **UIComponent** — UI component constructor (component ID 241): binds data source dword_7CE784 at +0x31C, single-state configuration, vtable off_5A1200, two linked-list handles, post-init action-ID dispatch.
- `0x00471860` **UIComponent** — UI component constructor (component ID 242): binds data source dword_7CE7CC at +0x31C, single-state configuration, vtable off_5A12C0, two linked-list handles, post-init action-ID dispatch.
- `0x00471A00` **UIComponent** — UI component constructor (component ID 245): binds data source dword_7CE6AC at +0x31C, state words 2/0/1/1, vtable off_5A1500, three linked-list handles (off_5BE704, off_5C32A4, aHigh), post-init action-ID dispatch.
- `0x00472400` **NameLookupComparator** — Formats a factory/virtual path: queries object type 19 through the dword_7CD8C0 dispatch interface (slot +28), compares the returned object's name with `this` when non-null, then formats dword_7D09D8 via the '%d' literal into a 32-byte stack buffer and commits it to the edit buffer; returns 0.
- `0x00472630` **ScreenSetupMethod** — Screen step-bound setup: stores mode dword_7D0410 into this+0x324 and &dword_7CFFA8 into this+0x320, formats the indexed list entry, calls sub_4AE9F0(byte_7CE498), and sets this+0x310 to 0 or 2 by comparing the step counter against dword_5EC4A8; commits to the edit buffer; returns 0.
- `0x00472930` **ScreenSetupMethod** — Car-part visibility screen setup: stores mode global into this+0x324 and &dword_7CFF60 into this+0x320, formats the indexed entry, drives CarPartVisibilityController(byte_7CE498), and commits to the edit buffer; always returns 0.
- `0x004734A0` **UIComponent** — UI element constructor (component ID 272): binds data source dword_7D00C8 at +0x31C, state words 1/0/1/1, vtable off_5A2940, two linked-list handles (off_5BE704, aOn); returns this.
- `0x00473B00` **PathInitializedUIObject** — UI element constructor: base init sub_48C070(this, 1), vtable off_5A2DC0 at +0x0, &byte_7D0474 at +0x320, literal 278 at +0x31C, two text-handle nodes (off_5C7084, off_5C7080); returns this.
- `0x00473B90` **PathInitializedUIObject** — Conditional init: dispatches through the dword_7CD8C0 interface (slot +28) with argument 11, compares the returned object's name with `this` when non-null, then stores &byte_7D0474 at +0x320 and literal 278 at +0x31C (same field writes as 0x00473B00); returns 0.
- `0x00474510` **ScreenSetupMethod** — Season display refresh: stores dword_7D0410 into this+0x320 and &dword_7CFDE8 into this+0x324 (role-reversed relative to other ScreenSetupMethod members), fetches the indexed value, formats it and commits to the edit buffer; returns 0.
- `0x00474BA0` **UIComponent** — UI element constructor (component ID 438): binds data source dword_7D0038 at +0x31C, state words 1/0/1/1, vtable off_5A3FC0, two linked-list handles (off_5BE704, aOn); returns this.
- `0x00475920` **SceneIndexListOwner** — Scene-name match: queries the current scene list through the dword_7CD8C0 interface (slot +28, argument 3), extracts the current scene filename, walks the this+0xE8 linked list comparing names, and stores the matching index into +0xFC; returns a residual comparison byte.
- `0x00476EC0` **SceneNameList** — Season-scene list search: resolves a path via ConditionalDispatch_40b0 (defaulting to byte_5EA438 when dword_7CE64C is null) and walks the this+0xF0 list comparing node names (node+4) against the dispatch result's name data (+124), storing the matched node index at this+0x174.
- `0x00477640` **SeasonSceneNameAccessor** — Copies season-scene name strings from a global linked-list element's embedded string table (entries 0 and 47) into managed buffers via StringCopyWithBufferRealloc; returns the second copy result.
- `0x00477BA0` **SceneNameList** — Scene list search by path: walks the this+0xF0 list comparing each node's sub-object path string (+0x104) against dword_7CE5EC (fallback byte_5EA438); on match stores the index at +0x174 and calls TrackSceneLoader with the node name; falls back to the first entry when no match is found.
- `0x00477EE0` **UnknownObject** — Destructor: frees the inner buffer at +0x158 when non-null, runs ConditionalDualCleanup on the paired sub-objects at +0x124 and +0xE0, runs base cleanup sub_485EB0, then frees the instance when flag bit 0 is set.
- `0x00479170` **CoordinateListParser** — Parses a .rt track data file into a coordinate linked list: frees the prior list, opens the file, reads lines, parses NumCoordinates/Coordinate tokens, allocates 12-byte coordinate records and nodes, and closes the file.

## Proposed classes

### UIComponent

UI menu component with per-component data-source binding, a state/value range, a component ID, and a linked list of text/state handles. Constructors share base init (0x00466D60), vtable install at +0x0, data-source pointer at +0x31C, state words at +0x324..0x330, component ID at +0x334, and post-init action-ID dispatch (0x004670E0).

Methods: `0x00471650`, `0x004716D0`, `0x00471750`, `0x004717E0`, `0x00471860`, `0x00471A00`, `0x004734A0`, `0x00474BA0`

- `this+0x00000000` `void** vtable_ptr` (write, DERIVED)
- `this+0x0000031C` `void* data_source_ptr` (read_write, DERIVED)
- `this+0x00000324` `int value_count` (read_write, DERIVED)
- `this+0x00000328` `int current_state` (read_write, DERIVED)
- `this+0x0000032C` `int min_state_or_enabled` (read_write, GUESS)
- `this+0x00000330` `int max_state_or_visibility` (read_write, GUESS)
- `this+0x00000334` `int component_id` (write, DERIVED)

### PathInitializedUIObject

UI-list-style object whose constructor runs base init sub_48C070(this, 1), installs a vtable at +0x0, writes a literal id/value at +0x31C, optionally binds a global pointer at +0x320, and registers text-handle nodes via LinkedListInsertWithNodeAllocation.

Methods: `0x00470AF0`, `0x00473B00`, `0x00473B90`

- `this+0x00000000` `void** vtable_ptr` (write, DERIVED)
- `this+0x0000031C` `int value_or_id` (read_write, GUESS)
- `this+0x00000320` `void* bound_global_ptr` (read_write, GUESS)

### NameLookupComparator

Verifies a name against an object obtained through the dispatch interface (dword_7CD8C0, slot +28): runs preliminary setup, toggles a boolean flag, performs the lookup, and compares names via ObjectNameComparison when non-null; returns 0.

Methods: `0x0046FDC0`, `0x0046FDF0`, `0x0046FE20`, `0x00472400`


### SceneNameList

Owner of a linked list of scene/season name entries used to resolve the current scene by name or path. Traverses nodes (value at +0, name at +4, sub-object pointer at +0x3C), records the matched index, and triggers the scene loader.

Methods: `0x00476EC0`, `0x00477BA0`

- `this+0x000000F0` `void* list_head` (read, GUESS)
- `this+0x000000F8` `void* traversal_cursor` (read, GUESS)
- `this+0x000000FC` `int list_count` (read, GUESS)
- `this+0x00000174` `int matched_index` (read_write, GUESS)

### SceneIndexListOwner

Owner of a linked list of scene filename entries used to match the current scene filename; stores the matching index. Distinct list layout from SceneNameList (head +0xE8, bound +0xF4, count +0xF8, match +0xFC).

Methods: `0x00475920`

- `this+0x000000E8` `void* list_head` (read, GUESS)
- `this+0x000000F4` `int bounds_count` (read, GUESS)
- `this+0x000000F8` `int list_count` (read, GUESS)
- `this+0x000000FC` `int matched_index` (read_write, GUESS)

### SeasonSceneNameAccessor

Copies season-scene name strings from a global linked-list element's embedded string table into managed buffers.

Methods: `0x00477640`


### CoordinateListParser

Parses a .rt track data file into a coordinate linked list; frees any prior list, reads lines, parses NumCoordinates/Coordinate tokens, allocates 12-byte records and nodes, and maintains list bookkeeping fields.

Methods: `0x00479170`

- `this+0x00000154` `int coord_count` (read_write, GUESS)
- `this+0x00000164` `void* list_head` (read_write, GUESS)
- `this+0x00000168` `void* list_tail` (read_write, GUESS)
- `this+0x0000016C` `void* insert_ptr` (read_write, GUESS)
- `this+0x00000170` `int node_count` (read_write, GUESS)

### ScreenSetupMethod

Initializes or refreshes a UI screen element's display string: binds a mode/step global and a list pointer into this+0x320/+0x324, fetches the indexed list value, formats it with an overflow check, and commits it to the UI edit buffer.

Methods: `0x004707C0`, `0x00471440`, `0x00472630`, `0x00472930`, `0x00474510`

- `this+0x00000310` `int step_flag` (read_write, GUESS)
- `this+0x00000320` `void* pointer_or_mode` (read_write, GUESS)
- `this+0x00000324` `int mode_or_pointer` (read_write, GUESS)

## Compatibility contracts

- **UIComponentConstructionLayout** — A replacement must preserve the UI component construction contract: install a per-class vtable at +0x0, bind a per-component data source pointer at +0x31C, configure the state/flag words at +0x324/+0x328/+0x32C/+0x330, and stamp the component ID at +0x334 before optional post-init dispatch (component IDs 238/239/240/241/242/245/272/438 are evidenced).
- **DispatchInterfaceLookup** — The global vtable interface at dword_7CD8C0 must expose a method at slot +28 that returns a non-null object for a numeric type id (evidenced arguments: 11, 12, 13, 19, 3), and that object must support name comparison via ObjectNameComparison.
- **SceneNameListContract** — Scene-name searches walk a linked list rooted at this+0xF0 with count at +0xFC and record the matched node index at +0x174; name strings default to byte_5EA438 when null; after a match the scene loader is invoked.
- **CoordinateFileParsing** — The coordinate parser must free any prior coordinate list, open the .rt file, parse NumCoordinates/Coordinate tokens, build 12-byte nodes (data at +0, next at +4, owned flag at +8), and keep list bookkeeping in this+0x154/+0x164/+0x168/+0x16C/+0x170.

## Unresolved

- Common ownership of the this+0x320/+0x324 fields across ScreenSetupMethod members is not proven; 0x00474510 stores the mode value into +0x320 and a pointer into +0x324, the reverse of the other members.
- dword_7CD8C0 vtable slot +28 lookup semantics and the object type IDs (12/13/19/11/3) are derived from usage, not independently grounded.
- Whether UIComponent (base init 0x00466D60) and PathInitializedUIObject (base init sub_48C070) share a base layout is not provable from this packet.
- Scene linked-list node layout is ambiguous: node+0x4 is read both as a name string (SceneNameList) and as a next pointer; the concrete node struct is unresolved.
- 0x00475920 uses a distinct scene-list field layout (head +0xE8, bound +0xF4, count +0xF8, match +0xFC) from SceneNameList (head +0xF0, match +0x174); the two are not merged.
- Meaning of the trailing constants (0, 1) passed to AddVehicleConfigEntryToLinkedList is unknown.
- The enclosing class of the coordinate list in CoordinateFileParser is unknown.
- Semantics of the paired-allocation sub-objects at this+0x124 and this+0xE0 freed by DestructorWithFreeCondition are not separately evidenced.
- Interpretation of the UIComponent state words at +0x324/+0x328/+0x32C/+0x330 (value-count/current-state/min/max) is inferred, not evidenced.
- The role-inverted write in 0x00474510 and the meaning of the this+0x310 values 0/2 in 0x00472630 are inferred, not confirmed.
