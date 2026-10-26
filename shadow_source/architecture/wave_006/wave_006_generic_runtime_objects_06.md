# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Derived architecture proposal for 36 validated functions in scope generic_runtime_objects. One DERIVED two-method class MenuOptionValueDisplay (0x004673B0 value formatter + 0x00467430 bounded string replace with vtable-slot-11 change signal) covers the menu-option text path; one GUESS two-method class MenuLayoutProcessor (0x00467DC0 layout calculator + 0x00467F90 HTML output section processor) shares the same this, a secondary list at 0x44..0x50 and a primary list at 0xF8..0x108; one GUESS MenuNavigationController (0x00470040) selects a UI list index from global mode dword_7D0410 and a session flag. Seven constructors/init functions called from SeasonDatabaseObjectFactory (0x0047F440) plus the season-database variant teardown pair 0x0046B5C0/0x0046B5E0 are grouped into a GUESS SeasonDatabaseObject class (distinct vtables 0x0059FA98/0x0059FE18/0x0059FED0/0x005A0250/0x005A4370/0x005A44A0; variants not merged). Single-function GUESS classes: HudTextNode (0x00476600 three-level vtable chain destructor), ControllerBindingSlot (0x0046A9C0 action pair + force-feedback table), InputBindingConfigurator (0x0046D270 sound refresh + binding factory at vtable slot 0x1C), DriverIndexTable (0x0046CB10 global table init), StateChangeMonitor (0x0046EFE0 cached-state diff), DebugRenderSystem (0x00475C80 red-line draw gate, packet-DERIVED owner). The remaining 18 UNKNOWN-owner constructors/destructors are grouped into a GUESS GenericRuntimeObject grab-bag that shares the base-init + vtable-install + conditional-free protocol but not a proven layout; per-function field offsets are NOT merged into that class and are carried in unresolved_evidence_refs instead. 0x00469872 is flagged unreliable (reported stack-pointer imbalance, uninitialized base). All class assignments are proposals, never CONFIRMED.

## Function roles

- `0x004673B0` **MenuOptionValueDisplay** — Menu-option value display formatter: seeds a 61-byte local buffer from byte_5EA438, dispatches on selection type this+0x32C (==4 to VehicleSetupValueFormatter(byte_7C56C0, this+0x324), else SetupValueFormatDispatcher(byte_7C56C0, this+0x32C, this+0x328)), formats the value string 30 bytes past this+0x320 into the buffer via StringFormatWithBufferOverflowCheck, then calls StringCompareAndConditionalReplace to replace the display only when changed
- `0x00467430` **MenuOptionValueDisplay** — Conditional string replace on the option-text buffer: returns -1 when the input is null or strcmp-equal to the buffer at this+0x2F0; otherwise bounded-copies (limit this+0x2F8 minus 1) via sub_587DD0, null-terminates, resets the position pointer this+0x2F4 and advances it to the null terminator, then signals the change through vtable slot 11 (vtable + 0x2C) with argument 1; returns 0 on replace
- `0x00467720` **GenericRuntimeObject** — Combined init + linked-list clear: installs vtable off_59F5B8 via InitWithVTableFlags(this,0,0), zeroes counters 0xE4..0xF0, walks the embedded singly-linked list from this+0xF8 (node layout data@+0, next@+4, flag@+8), frees each flagged payload chain and node through FreeWrapper_7bcf, then resets head/tail/count/capacity fields and the 0xF4/0xF5 flag bytes
- `0x00467DC0` **MenuLayoutProcessor** — Menu layout calculator: runs CreditsTxtParser (0x00467E40) then HTMLOutputSectionProcessor (0x00467F90) on this, computes the horizontal center this+0xEC as midpoint of bounds this+0x4 and this+0x8, then loads a resource via sub_497AD0(this+0x40, path=this+0xB8 or default byte_5EA438, key 0) storing the handle at this+0x108; returns 0
- `0x00467F90` **MenuLayoutProcessor** — HTML output-section processor: seeds traversal this+0x100 from the primary list head this+0xF8, destroys the secondary list anchored at this+0x44 (DestructorWithDoubleFreePattern per node) and clears its four fields, then walks the primary list comparing each node payload (defaulting to byte_5EA438 when null) against Header literal aHeader_0 via sub_588410; a Header match that is not aHeader2 is inserted with LinkedListInsertWithNodeAllocation(string,-1), non-matches advance to the next node
- `0x004685F0` **GenericRuntimeObject** — Scalar-deleting destructor: runs DestructorWithFree(this) (0x00468610) then, only when delete flag a2 bit 0 is set, releases the object via FreeWrapper_7bcf(this); returns this
- `0x00468610` **GenericRuntimeObject** — Object destructor: restores vtable off_59F718 at offset 0, conditionally frees the heap sub-object at this+0x174 via FreeWrapper_7bcf when non-null, then delegates to a cleanup wrapper and returns its result
- `0x00469872` **GenericRuntimeObject** — Unreliable reconstruction (reported stack-pointer imbalance, base v1 uninitialized, indirect call through (v1-117)): writes vtable off_59F7C8 and constants 0/-1/1 at ungrounded offsets v1+372..v1+388, calls sub_4893C0 and StringCopyWithBufferRealloc(0); nothing grounded beyond the raw text
- `0x004698C0` **GenericRuntimeObject** — Scalar-deleting destructor: frees the heap sub-object at this+0x180 via FreeWrapper_7bcf when non-null, runs FunctionCallWrapper_9440(this) (0x00489440) as cleanup, then frees this when delete flag a2 bit 0 is set; returns this
- `0x0046A950` **GenericRuntimeObject** — Scalar-deleting destructor: runs VtableSetSubCall() (0x0046A970) then frees this via FreeWrapper_7bcf when delete flag a2 bit 0 is set; returns this
- `0x0046A9C0` **ControllerBindingSlot** — Controller shifter/gear binding: clears the previous ID pair via IDPairMatchAndClear(this+128), writes the two-ID pair (this+0x200, this+0x204) at a stride-28 slot indexed by this+0x1F4 into dword_7D1B08/dword_7D1B0C, and when the first ID equals 1 switches on this+0x204 (jump table jpt_46AA0C) to seed a force-feedback value 1056964608 into dword_7D1490[216*result+27*v6] after a linear scan over dword_7D1B0C
- `0x0046B5C0` **SeasonDatabaseObject** — Scalar-deleting destructor for the season-database variant: runs VTableSetAndInit() (0x0046B5E0) then frees this via FreeWrapper_7bcf when delete flag a2 bit 0 is set; returns this
- `0x0046B5E0` **SeasonDatabaseObject** — Object init entry for the season-database variant: writes vtable off_59FA98 into this->vtable at offset 0x0 and delegates to FunctionCallWrapper_9440(this), returning its result
- `0x0046C6F0` **GenericRuntimeObject** — Constructor: runs base/sub-object initializer sub_4893C0(this), stores the byte parameter a2 at this+0x174, installs vtable off_59FB58 at offset 0x0, returns this
- `0x0046CB10` **DriverIndexTable** — Driver index lookup-table init: gates on GlobalSignCheck (0x0046CB00), then for i in 0..103 reads live driver identifier dword_7CD470[i]; when non-negative writes the loop counter i into the driver table dword_5F0730 at entry 4656*v1; returns 1 on success, 0 on gate failure
- `0x0046D270` **InputBindingConfigurator** — Input-binding dispatch: refreshes the sound system dword_5EB10C via vtable offset 12 when non-null, re-initializes input buffer flt_5EA618 with BufferInitWith10fDefaults, creates UI binding objects IDs 39 and 41 through the vtable factory at offset 0x1C on the object at this+0x40, activates 39 (sub_47C360 param 1) and deactivates 41 (param 0), then refreshes game state dword_5EB978; returns 0
- `0x0046D5F0` **GenericRuntimeObject** — Constructor: runs ConstructorWithByteParams(this,0,0) (0x00487220) then binds vtable off_59FC08 at offset 0x0; returns this
- `0x0046D680` **GenericRuntimeObject** — Constructor: runs ConstructorWithByteParams(this,0,0) (0x00487220) then sets vtable slot at offset 0x0 to off_59FCB8; returns this
- `0x0046D6C0` **GenericRuntimeObject** — Object init entry: writes vtable off_59FCB8 into this->vtable at offset 0x0 and delegates to InitWithVTableCleanup(this), returning its result; called from a SubCallConditionalFree destructor
- `0x0046E7D0` **SeasonDatabaseObject** — Constructor-style initializer (season-database factory step, caller 0x0047F440): runs base initializer sub_4893C0(this), installs vtable off_59FE18 at offset 0x0, zeroes the byte field at this+0x174; returns this
- `0x0046EEC0` **SeasonDatabaseObject** — Constructor (season-database factory init path, caller 0x0047F440): runs base initializer sub_4893C0(this), installs vtable off_59FED0 at offset 0x0, sets the signed dword at this+0x174 to -1 as an invalid-state sentinel; returns this
- `0x0046EFE0` **StateChangeMonitor** — State-change monitor with deferred update: reads current state via VtableGetterAtOffset0x1c (0x00432A60) on global dword_7C73E0, compares to cached this+0x174, and on any difference runs ExtensionStripperForAllListEntries(this) (0x0046F170) then re-caches the new value; always returns 0
- `0x0046F610` **GenericRuntimeObject** — Constructor: runs ConstructorWithByteParams(this,0,0) (0x00487220), stores integer parameter a2 at this+0xE4, assigns vtable off_59FF80 at offset 0x0; returns this
- `0x0046F890` **GenericRuntimeObject** — Constructor: runs ConstructorWithByteParams(this,0,0) (0x00487220), stores byte parameter a2 at this+0xE4, installs vtable off_5A0040 at offset 0x0; returns this
- `0x0046FCF9` **GenericRuntimeObject** — Object factory (userpurge signature, object in eax / interface in esi): invokes the interface callback at interface offset 0x6A, runs base constructor ConstructorWithByteParams with two byte parameters, stores input byte a2 at object offset 0xE4, installs vtable off_5A00F0 at the object head; returns the new object
- `0x0046FD30` **GenericRuntimeObject** — Scalar-deleting destructor: runs InitWithVTableCleanup() teardown (0x00487250) then frees this via FreeWrapper_7bcf when delete flag a2 bit 0 is set; returns this
- `0x00470040` **MenuNavigationController** — Menu navigation dispatch: returns early when the session-flag pointer this+0xE8 is null; otherwise selects UI list index 0/1 from the pointed-to flag when global dword_7D0410 equals 3 or 5, or fallback index 2 otherwise, stores the index at this+0xE0, copies the selected list entry string via UIListIndexedAccessor (0x00487010) + StringCopyWithBufferRealloc into this+0xEC, and dispatches navigation through vtable slot 0x40
- `0x00470230` **SeasonDatabaseObject** — Constructor (season-database factory, caller 0x0047F440): delegates to ConstructorWithStringCopy(this,0,0,0,0,1,0) (0x0048B420), then overwrites the vtable pointer at this+0x0 with off_5A0250; returns this
- `0x00470250` **GenericRuntimeObject** — Scalar-deleting destructor: runs VTableSetterSubCall_b4e0 (0x0048B4E0) on this then frees this via FreeWrapper_7bcf when delete flag a2 bit 0 is set; returns this
- `0x004702A0` **GenericRuntimeObject** — Constructor: delegates to ConstructorWithStringCopy(this,0,0,0,0,1,0) (0x0048B420), stores integer parameter a2 at this+0x304, assigns vtable off_5A0308 at offset 0x0; returns this
- `0x004713C0` **GenericRuntimeObject** — Scalar-deleting destructor: runs VTableInit (0x0048C0D0) on this then frees this via FreeWrapper_7bcf when delete flag a2 bit 0 is set; returns this
- `0x00474FF0` **GenericRuntimeObject** — UI-object constructor: delegates to ConstructorWithByteParams(this,0,0) (0x00487220), stores integer parameter a2 at this+0xE4, installs vtable off_5A42C0 at offset 0x0; returns this
- `0x004750F0` **SeasonDatabaseObject** — Season-database object init (factory context 0x0047F440): calls sub_4893C0 for generic setup, zeroes dwords at this+0x174 and this+0x178 and a byte at this+0x17C, installs vtable off_5A4370 at offset 0x0; returns this
- `0x00475C80` **DebugRenderSystem** — Debug red-line renderer (caller 0x00475A90): queries render-debug enable state via GlobalAccessor_5150 on unk_7CDE00; when enabled draws a red line (color 16711680) between the two 2D points a1 and a2 through FloatVectorWithConditionalTransform passing the enable result as the final argument; returns the enable result when disabled
- `0x00476600` **HudTextNode** — HUD text-node destructor: walks the base-class chain writing three successive vtable pointers to this+0x0 (off_5A448C, off_5A4450, off_5A443C), freeing a child object after each step (offsets 0x3C, 0x30, 0x4) when non-null; finally frees this when delete flag a2 bit 0 is set; returns this
- `0x004766F0` **SeasonDatabaseObject** — Constructor for an object holding a season/context identifier (caller 0x0047F440): calls LargeConstructor (0x0048EAA0), sets the vtable pointer at this+0x0 to off_5A44A0, stores parameter a2 at this+0x180, initializes this+0x184 and this+0x18C to -1 and this+0x188 to 0; returns this

## Proposed classes

### MenuOptionValueDisplay

Menu-option value display: formats the option value (selection-type dispatch at 0x32C, value block at 0x320) into a scratch buffer and replaces the held text string only when it changed. Owns the string buffer region 0x2F0..0x2F8 and the value/selection region 0x320..0x32C. The vtable slot-11 change signal (vtable + 0x2C, argument 1) is the observable external contract of the replace step.

Methods: `0x004673B0`, `0x00467430`

- `this+0x00000000` `void* vtablePointer` (read, GUESS)
- `this+0x000002F0` `char[] valueTextBuffer` (read_write, DERIVED)
- `this+0x000002F4` `char* valueTextPosition` (read_write, GUESS)
- `this+0x000002F5` `byte valueTextStatus` (read, UNKNOWN)
- `this+0x000002F8` `dword valueTextCapacity` (read, GUESS)
- `this+0x00000320` `void* optionValueBlock` (read, GUESS)
- `this+0x00000324` `const char* optionValueString` (read, GUESS)
- `this+0x00000328` `dword formatParameter` (read, GUESS)
- `this+0x0000032C` `dword selectionType` (read, GUESS)

### MenuLayoutProcessor

Menu layout/HTML-section processing over two embedded singly-linked lists: a secondary list at 0x44..0x50 destroyed per node, and a primary list at 0xF8..0x108 traversed while filtering Header literals. Computes the horizontal center from bounds 0x4/0x8 and loads a resource (path 0xB8, default global byte_5EA438, handle stored at 0x108).

Methods: `0x00467DC0`, `0x00467F90`

- `this+0x00000004` `float leftBound` (read, GUESS)
- `this+0x00000008` `float rightBound` (read, GUESS)
- `this+0x00000040` `void* resourceDataPointer` (read, GUESS)
- `this+0x00000044` `void* secondaryListHead` (read_write, GUESS)
- `this+0x00000048` `void* secondaryListTail` (read_write, GUESS)
- `this+0x0000004C` `dword secondaryListCount` (write, GUESS)
- `this+0x00000050` `dword secondaryListCapacity` (write, GUESS)
- `this+0x000000B8` `const char* pathStringPointer` (read, GUESS)
- `this+0x000000EC` `float centerX` (write, GUESS)
- `this+0x000000F8` `void* primaryListHead` (read, GUESS)
- `this+0x00000100` `void* traversalNodePointer` (read_write, GUESS)
- `this+0x00000104` `dword listCount` (read, UNKNOWN)
- `this+0x00000108` `dword loadedResourceHandle` (write, GUESS)
- `*(this+0xF8)+0x00000000` `void* headNodeData` (read, GUESS)
- `*(this+0x48)+0x00000004` `void* secondaryNodeNext` (read, GUESS)
- `*(this+0x100)+0x00000000` `void* traversalNodeData` (read, GUESS)

### MenuNavigationController

Menu navigation dispatch: selects a UI list index (0, 1, or 2) from the global mode dword_7D0410 and a pointed session flag, copies the selected list entry string, and dispatches navigation through vtable slot 0x40.

Methods: `0x00470040`

- `this+0x000000E0` `byte selectedIndex` (write, GUESS)
- `this+0x000000E8` `byte* sessionFlagPointer` (read, GUESS)
- `this+0x000000EC` `char[] navigationTextBuffer` (write, GUESS)

### SeasonDatabaseObject

Family of season-database objects constructed/initialized from SeasonDatabaseObjectFactory (0x0047F440) plus the season-database variant teardown pair 0x0046B5C0/0x0046B5E0. Holds a state/flag region at 0x174..0x17C, an identifier at 0x180, and -1/0 sentinel indices at 0x184..0x18C. Six distinct vtables (0x0059FA98, 0x0059FE18, 0x0059FED0, 0x005A0250, 0x005A4370, 0x005A44A0) mean sub-variants are plausible; the fields below are the union across members and do not claim one identical layout.

Methods: `0x0046B5C0`, `0x0046B5E0`, `0x0046E7D0`, `0x0046EEC0`, `0x00470230`, `0x004750F0`, `0x004766F0`

- `this+0x00000000` `void* vtablePointer` (write, GUESS)
- `this+0x00000174` `dword stateFlagOrSentinel` (read_write, GUESS)
- `this+0x00000178` `dword stateCounter` (write, GUESS)
- `this+0x0000017C` `byte stateByte` (write, GUESS)
- `this+0x00000180` `dword identifier` (write, GUESS)
- `this+0x00000184` `dword sentinelPrevious` (write, GUESS)
- `this+0x00000188` `dword counter` (write, GUESS)
- `this+0x0000018C` `dword sentinelNext` (write, GUESS)

### HudTextNode

UI text node whose destructor walks a three-level base-class chain (vtables 0x005A448C, 0x005A4450, 0x005A443C) freeing one child object per level (0x3C, 0x30, 0x4). Class hierarchy order is inferred from the vtable pointer sequence, not confirmed.

Methods: `0x00476600`

- `this+0x00000000` `void* vtablePointer` (write, GUESS)
- `this+0x00000004` `void* childBaseControl` (read_write, GUESS)
- `this+0x00000030` `void* childTextNode` (read_write, GUESS)
- `this+0x0000003C` `void* childExtension` (read_write, GUESS)

### ControllerBindingSlot

Controller shifter/gear binding slot: clears the prior ID pair, writes a two-ID pair at a stride-28 entry of the global action tables (dword_7D1B08/dword_7D1B0C) indexed by this+0x1F4, and, when the primary ID is a gear action, seeds a force-feedback table (dword_7D1490) through a jump-table switch on the secondary ID.

Methods: `0x0046A9C0`

- `this+0x000001F4` `dword bindSlotIndex` (read, GUESS)
- `this+0x00000200` `dword primaryActionId` (read, GUESS)
- `this+0x00000204` `dword secondaryActionId` (read, GUESS)

### InputBindingConfigurator

Input-binding dispatch: refreshes the sound system, re-initializes the input buffer, creates UI binding objects (IDs 39 and 41) through the vtable factory at offset 0x1C on the object stored at this+0x40, activates one and deactivates the other, then refreshes game state.

Methods: `0x0046D270`

- `this+0x00000040` `void* uiBindingFactory` (read, GUESS)
- `*(this+0x40)+0x0000001C` `vtable_method createBindingSlot` (read, GUESS)

### DriverIndexTable

Initializes the driver index lookup table: gates on GlobalSignCheck, reads live driver identifiers from dword_7CD470 (0..103) and writes the loop counter into the driver table dword_5F0730 at stride 4656 per driver. Operates on globals only; no instance fields.

Methods: `0x0046CB10`


### StateChangeMonitor

Cached-state change monitor: reads a module-callback state via vtable slot 0x1C on global dword_7C73E0, compares to the cached value at this+0x174, and on change runs ExtensionStripperForAllListEntries on itself then re-caches.

Methods: `0x0046EFE0`

- `this+0x00000174` `dword cachedState` (read_write, GUESS)

### DebugRenderSystem

Debug rendering helper: queries the render-debug enable state on global unk_7CDE00 and, when enabled, draws a red line between two 2D points through FloatVectorWithConditionalTransform. Packet owner trust DERIVED; operates on globals only, no instance fields.

Methods: `0x00475C80`


### GenericRuntimeObject

Grab-bag of 18 UNKNOWN-owner constructors/destructors/init entries sharing the object-lifecycle protocol (base initializer delegate + vtable install at offset 0 + conditional-free teardown) but not a proven shared layout. Per-function vtables differ (0x0059F5B8, 0x0059F718, 0x0059F7C8, 0x0059FB58, 0x0059FC08, 0x0059FCB8, 0x0059FF80, 0x005A0040, 0x005A00F0, 0x005A0308, 0x005A42C0), so each method likely belongs to a distinct class; only the vtable-at-0 convention is asserted here, all other per-function field offsets are carried in unresolved_evidence_refs rather than merged.

Methods: `0x00467720`, `0x004685F0`, `0x00468610`, `0x00469872`, `0x004698C0`, `0x0046A950`, `0x0046C6F0`, `0x0046D5F0`, `0x0046D680`, `0x0046D6C0`, `0x0046F610`, `0x0046F890`, `0x0046FCF9`, `0x0046FD30`, `0x00470250`, `0x004702A0`, `0x004713C0`, `0x00474FF0`

- `this+0x00000000` `void* vtablePointer` (write, GUESS)

## Compatibility contracts

- **MenuOptionTextBufferLayout** — StringCompareAndConditionalReplace (0x00467430) requires a char buffer at this+0x2F0, a position pointer at this+0x2F4, a status byte at this+0x2F5 and a size limit at this+0x2F8; replacement copies at most (limit - 1) bytes, null-terminates, resets and advances the position pointer, then invokes vtable slot 11 (vtable + 0x2C) with argument 1. A replacement executable must preserve this layout and the change-signal callback.
- **LinkedNodeContainerLayout** — Embedded singly-linked-list container at this+0xF8 (head), 0xFC (tail), 0x100 (count), 0x104 (capacity), 0x108 (extra), with flag bytes at 0xF4/0xF5; list node layout is data at node+0, next at node+4, one-byte flag at node+8. Used by objectInitAndClearLinkedList (0x00467720) and the menu primary list in ProcessHtmlOutputSection (0x00467F90).
- **MenuLayoutFieldLayout** — MenuLayoutCalculator (0x00467DC0) requires bounds at this+0x4 and this+0x8, a resource data pointer at this+0x40, a path string at this+0xB8 (defaulting to global byte_5EA438 when null), a computed center at this+0xEC and a loaded-resource handle at this+0x108. A replacement executable must preserve these offsets for menu layout.
- **SeasonDatabaseObjectStateLayout** — Season-database object family carries a state/flag dword at this+0x174 (zero, or -1 sentinel), zeroed counter fields at this+0x178 and this+0x17C, an identifier at this+0x180, and sentinel indices -1/-0/-1 at this+0x184/0x188/0x18C as written by 0x0046EEC0, 0x004750F0 and 0x004766F0. Six vtables are installed across the family (0x0059FA98, 0x0059FE18, 0x0059FED0, 0x005A0250, 0x005A4370, 0x005A44A0).
- **ScalarDeletingDestructorFlag** — The conditional destructors (0x004685F0, 0x0046A950, 0x0046B5C0, 0x0046FD30, 0x00470250, 0x004713C0) follow the MSVC scalar-deleting-destructor convention: run the teardown sub-call on this, then free this via FreeWrapper_7bcf only when the low bit of the second argument (a2 & 1) is set; return this in all paths. A replacement executable must honor the delete-flag argument convention.
- **DriverIndexTableStride** — DriverTableIndexInitialization (0x0046CB10) reads live driver identifiers from dword_7CD470 for i in 0..103 and, when an identifier v1 is non-negative, writes the loop counter i into the driver table dword_5F0730 at entry 4656*v1 (stride 4656 bytes per driver). A replacement executable must preserve this stride and the table addresses.
- **VtableFactorySlots** — Three observed vtable/interface dispatch offsets: vtable offset 0x1C is the binding-object factory on the object stored at this+0x40 (0x0046D270), vtable offset 0x40 is the navigation dispatch receiving the selected index (0x00470040), and interface offset 0x6A is the callback invoked by the object factory (0x0046FCF9).
- **InputActionBindingTables** — ControllerShifterMapping (0x0046A9C0) writes a two-ID pair into dword_7D1B08/dword_7D1B0C at a stride-28 slot indexed by this+0x1F4, scans dword_7D1B0C stepping 7 dwords up to dword_7D1FDC, and seeds a force-feedback value (float 0.001 precision literal 1056964608) into dword_7D1490[216*result + 27*v6]. A replacement executable must preserve these global table layouts.

## Unresolved

- Identity and role of byte_7C56C0 (session-name buffer versus file-loader flag in prior analysis) is not established from this packet; it is only observed as the formatting target of MenuOptionValueDisplay.
- byte_5EA438 is used in two ways across this packet: as the source of the first byte seeding the option format buffer (0x004673B0) and as a default directory/path string in the menu layout path (0x00467DC0, 0x00467F90). The relationship between these uses is unresolved.
- Why the option value string begins 30 bytes into the block pointed to by this+0x320 is not resolvable without the value-block layout.
- Semantics of the return value of StringCompareAndConditionalReplace (match indicator versus replace result) are not confirmed.
- The status byte at this+0x2F5 is flagged as read by static evidence but is not referenced in the visible decompilation; purpose unknown.
- The object type and the meaning of the slot-11 vtable callback's integer argument (1) invoked by StringCompareAndConditionalReplace are not established from this packet.
- GenericRuntimeObject is a GUESS grab-bag: the 18 UNKNOWN-owner constructors/destructors each install a different vtable (0x0059F5B8, 0x0059F718, 0x0059F7C8, 0x0059FB58, 0x0059FC08, 0x0059FCB8, 0x0059FF80, 0x005A0040, 0x005A00F0, 0x005A0308, 0x005A42C0), so they most likely belong to distinct classes; only the vtable-at-offset-0 convention is asserted here.
- Offset 0x174 collides across classes with unrelated meanings: freed sub-object pointer (0x00468610), stored byte parameter (0x0046C6F0), season-database state/flag (0x0046E7D0, 0x0046EEC0, 0x004750F0) and cached state dword (0x0046EFE0). The offsets are kept in their respective classes, not merged.
- Offset 0x180 collides across classes: freed sub-object pointer (0x004698C0) versus season-database identifier (0x004766F0); not merged.
- Offset 0xEC collides across classes: horizontal center in MenuLayoutProcessor (0x00467DC0) versus navigation text buffer in MenuNavigationController (0x00470040); not merged.
- Offset 0x108 collides across classes: loaded-resource handle in MenuLayoutProcessor (0x00467DC0) versus unknown list-container field cleared by 0x00467720; not merged.
- 0x00469872 is unreliable: the decompiler reports a stack-pointer imbalance at a call, the base v1 is uninitialized, and the written offsets v1+372..v1+388 cannot be grounded; no class fields were derived from it.
- FunctionCallWrapper_9440 (0x00489440) and InitWithVTableCleanup have no callee records for the functions that delegate to them (0x0046B5E0, 0x0046D6C0), so those wrapper targets are unresolved.
- The a2 & 1 delete-flag convention is DERIVED (standard MSVC scalar-deleting-destructor pattern), not confirmed by packet evidence.
- The SeasonDatabaseObject grouping is based on the caller name SeasonDatabaseObjectFactory (0x0047F440) and legacy analysis labels; the six distinct vtables mean sub-variants are plausible but not resolvable here.
- The meaning of the -1 sentinel and 0 initialization at 0x184..0x18C and of the stored identifier at this+0x180 in 0x004766F0 is not stated by the packet.
- The individual counter fields at 0xE4..0xF0 and flag bytes 0xF4/0xF5 cleared by 0x00467720 have unknown semantics.
- Field this+0x104 is extracted as read by ProcessHtmlOutputSection but no use is visible in the raw source.
- The exact meaning of the aHeader_0 (0x005C6720) / aHeader2 (0x005C6714) comparisons beyond Header detection is not established.
- The menu layout bounds this+0x4 / this+0x8 and the purpose of the this+0x40 pointer passed to sub_497AD0 are unknown beyond their call sites.
- ControllerShifterMapping writes literal 1056964608 into the force-feedback table; its float interpretation is not derived here.
- Whether dword_7D1B08/dword_7D1B0C and dword_7D1490 are per-bind arrays indexed by this+0x1F4 depends on caller conventions not present in the packet.
- The semantics of global dword_7D0410 values 3 and 5 (race/championship mode per legacy analysis) and of the pointed session flag at this+0xE8 in 0x00470040 are not resolved independently here.
- The vtable slot at offset 0x40 in 0x00470040 is assumed to be the navigation dispatch because it receives the selected index; that is inferred, not proven.
- The HUD text-node destructor (0x00476600) base-class chain order is inferred from the vtable pointer sequence; whether FreeWrapper_7bcf is a heap free or a virtual operator delete is unresolved.
- DrawRedLineIfEnabled's sixth argument to FloatVectorWithConditionalTransform (the enable result) and the second point a2's field evidence are unverified.
- Whether the force-feedback/action-binding tables are the only writers of dword_7D1B08/dword_7D1B0C is not established from this packet.
