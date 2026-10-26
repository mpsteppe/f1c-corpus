# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Conservative architecture for 40 validated runtime-object functions. Dominant patterns: (1) constructor helpers that seed range/limit fields through a shared base initializer (VtableSetWithInitCall at 0x00466980, InitVTableSet at 0x004668E0, UIConstructorWithVTableParams at 0x0048D3A0, ShortComputation_fb70 at 0x0048FB70) and then install a per-type vtable; each family groups multiple distinct vtables, so each method is a distinct subtype proposal (CParamRangeConstructor, CInitVTableConstructor, CUIComponent, CShortInitObject). (2) MSVC scalar-deleting destructors that run a teardown sub-call (ObjectInitWithVTableCleanup 0x0048D3E0 or sub_485EB0) and free the object via FreeWrapper_7bcf when the a2 bit-0 deletion flag is set (CScalarDeletingObject), with one constructor/destructor pair proven to share a single vtable (0x005A5E40). (3) two state-change monitors that cache a monitored value and dispatch a virtual notification on change (CStateChangeMonitor, CPollingStateMonitor). (4) two registry-dispatch mirrors that call vtable slot +0x1C on the dword_7CD8C0 interface with selectors 12/13 and compare returned object names (CResourceRegistryObject). (5) a menu scroll-list coupling a bounded counter update (0x0047BAE0) with scroll-jump handling (0x0047BB40) (CScrollListObject). (6) a season-database object family whose two methods are both called by SeasonDatabaseObjectFactory 0x0047F440 (CSeasonDatabaseObject). Most packet owners are UNKNOWN; class boundaries and field names are DERIVED/GUESS proposals only.

## Function roles

- `0x00477160` **CIndexedListDispatcher** — Indexed linked-list dispatch: resets state via StateResetConditionalVirtualCall, reads the target index at this+0x170 and the list count at this+0xFC, walks the list head at this+0xF0 by next pointers to the selected node, requires node data at node+0x30 and its sub-object to be non-null, bounds/position-checks via BoundsCheckWithPositionQuery, then dispatches the node data sub-object's virtual slot 0x90; returns 0 on any guard failure.
- `0x00477410` **CSeasonDatabaseObject** — Variant season-database object constructor: calls the base large constructor LargeConstructor (0x0048EAA0), stores the handle/ID parameter at this+0x180, sets index fields at this+0x184 and this+0x188 to the -1 sentinel, and installs vtable off_5A4600; called from SeasonDatabaseObjectFactory.
- `0x004775F0` **CStateChangeMonitor** — State-change monitor: resolves a tracked object via UtilityFunction_7810 (0x00477810), reads a dword from it, and when it differs from the cached copy at this+0x184 re-caches it and invokes the virtual notification at vtable slot 160; always returns 0.
- `0x00477FA0` **CPollingStateMonitor** — Dual-source polling state monitor: fetches the first monitored state object via virtual slot +0x1C of the this+0x40 sub-object (argument 3), extracts its value via GuardedAccessor (0x0048D360) and compares against the cache at this+0x11C; fetches the second via virtual slot +0x1C of the dword_7CD8C0 interface (command 18) and compares against the cache at this+0x120; on each change updates the cache and invokes the virtual notification at vtable slot 0xA0; always returns 0.
- `0x00478020` **CProfileIconLoader** — Default profile-icon BMP loader: reads the custom path override at this+0x158 (falling back to default directory byte_5EA438), loads via sub_497AD0 on the loader sub-object at this+0x40, retries with aProfileiconDft, stores the result through ObjectFieldInitWithIndirectLookup into the field at this+0x124, reports success (1) or failure (0) through the virtual notification at vtable offset 0x3C, and returns the field pointer on success or null on failure.
- `0x00478110` **CShortInitObject** — Object initializer: calls ShortComputation_fb70 (0x0048FB70), writes the counter at this+0xE8 to 0 and the limit at this+0xEC to -1, installs vtable off_5A4760, and returns this.
- `0x00478140` **CScalarDeletingObject** — Object cleanup/destructor-style routine: frees the child pointer at this+0xE8 via FreeWrapper_7bcf when non-null, runs the sub-cleanup sub_485EB0 on this, and frees the object itself when the a2 bit-0 flag is set; returns this.
- `0x004781E0` **CShortInitObject** — Object initializer: calls ShortComputation_fb70 (0x0048FB70), installs vtable off_5A4810, sets the field at this+0xE8 to -1 (all/unlimited sentinel), and returns this.
- `0x00478280` **CShortInitObject** — Object constructor: calls ShortComputation_fb70 (0x0048FB70), installs vtable off_5A48C0, sets the dword at this+0xE8 to -1, and returns this.
- `0x00478BC0` **C4970Object** — Constructor: calls sub-constructor Constructor_e070 (0x0048E070), writes this+0xF0 = 0, this+0xF4 = -1 (all-unlimited), this+0xF8 = 0, installs vtable off_5A4970, and returns this.
- `0x004795E0` **CUIComponent** — UI component constructor helper: forwards this, a2 and a3 to UIConstructorWithVTableParams (0x0048D3A0) as the base UI constructor, then installs vtable off_5A4AD8 and returns this; shared by UISliderConstructor (0x00479690), ObjectInit (0x004796C0) and sub_479700 (0x00479700).
- `0x00479600` **CValueBarFormatter** — Value-bar formatter: reads the current value through the virtual getter at vtable slot 0xB4, computes percentage = (value - min) * 100 / (max - min) from this+0xF4 (min) and this+0xF8 (max), formats "%d%%" via StringFormatWithBufferOverflowCheck and commits with StringCopyWithBufferRealloc; always returns 0.
- `0x004796C0` **CUIComponent** — UI object component constructor: calls VTableSetInit(this, 0, 1045220557) to initialize the base UI component, then installs vtable off_5A4C48 over the base vtable; returns this.
- `0x00479760` **CParamRangeConstructor** — Constructor with float range: calls VtableSetWithInitCall(this, 1056964608, 1065353216) (0.5f / 1.0f bit patterns), installs vtable off_5A4E70, and returns this.
- `0x00479790` **CParamRangeConstructor** — Constructor with symmetric range: calls VtableSetWithInitCall(this, -1082130432, 1065353216) (-1.0f / 1.0f bit patterns), installs vtable off_5A4F28, and returns this.
- `0x00479820` **CParamRangeConstructor** — Object constructor: calls VtableSetWithInitCall(this, -1073741824, 0x40000000), installs vtable off_5A5150, and returns this; straight-line initialization.
- `0x00479850` **CParamRangeConstructor** — Float-range constructor: calls VtableSetWithInitCall(this, -1082130432, 1065353216) (-1.0f / 1.0f bit patterns), installs vtable off_5A5208, and returns this.
- `0x004798B0` **CParamRangeConstructor** — Range-init constructor: calls VtableSetWithInitCall(this, -1082130432, 1065353216) (-1.0f / 1.0f bit patterns), installs vtable off_5A5378, and returns this.
- `0x004799A0` **CParamRangeConstructor** — Object constructor with float params: calls VtableSetWithInitCall(this, 1163575296, 1177792512), installs vtable off_5A5710, sets the enable/active flag byte at this+0xF0 to 1, and returns this.
- `0x004799E0` **CParamRangeConstructor** — Object constructor: calls VtableSetWithInitCall(this, 0, 1050253722), installs vtable off_5A57C8, and returns this; straight-line initialization.
- `0x00479A40` **CParamRangeConstructor** — Float-range constructor: calls VtableSetWithInitCall(this, -1082130432, 1065353216) (-1.0f..1.0f bit patterns), installs vtable off_5A5938, zeroes the dword at this+0x100, and returns this.
- `0x00479C00` **CParamRangeConstructor** — Object constructor: calls VtableSetWithInitCall(this, 1028443341, 1048576000), installs vtable off_5A5AA8, and returns this; straight-line initialization.
- `0x00479C30` **CUIComponent** — UI object constructor: calls UIConstructorWithVTableParams(this, 1116471296, 1123024896), installs vtable off_5A5B60, sets the enable flag byte at this+0xF0 to 1, and returns this.
- `0x00479CD0` **CUIComponent** — UI-object constructor with range init and flag: calls UIConstructorWithVTableParams(this, 1101004800, 1120403456), installs vtable off_5A5CD0, sets the byte enable flag at this+0xF0 to 1, and returns this.
- `0x00479E30` **CRangeInitObject5A5E40** — Object constructor: calls InitVTableSet(this, 0, 1065353216) (0.0f / 1.0f bit patterns), installs vtable off_5A5E40, zeroes the byte field at this+0x100, and returns this.
- `0x00479E50` **CRangeInitObject5A5E40** — Scalar-deleting destructor: resets the vtable to off_5A5E40 (the same vtable its constructor installs), runs ObjectInitWithVTableCleanup (0x0048D3E0) for teardown, frees the object via FreeWrapper_7bcf when the a2 bit-0 flag is set, and returns this.
- `0x00479E80` **CResourceRegistryObject** — Resource-check dispatcher: initializes this via F_5FieldInit (0x004883A0), calls vtable slot 28 of the object at global dword_7CD8C0 with selector 12, and if a non-null object is returned compares its name against this via ObjectNameComparison (0x00477280); always returns 0.
- `0x00479EB0` **CFlagObject** — Flag set initializer: calls the no-op stub Return0Stub (0x0047ABB0), sets the byte flag at this+0x100 to 1, and returns 0; straight-line initialization.
- `0x00479ED0` **CFlagObject** — Flag clear: calls Return0Stub (0x0047ABB0), clears the byte field at this+0x100 to 0, and returns 0; the inverse of FlagSetInit_00479eb0 per existing analysis prose.
- `0x0047A230` **CScalarDeletingObject** — Scalar-deleting destructor: resets the vtable to off_5A6068, runs ObjectInitWithVTableCleanup (0x0048D3E0) for teardown, frees the object via FreeWrapper_7bcf when the a2 bit-0 flag is set, and returns this.
- `0x0047A260` **CResourceRegistryObject** — Vtable dispatch mirror: initializes this via F_5FieldInit (0x004883A0), calls vtable slot 28 of the object at global dword_7CD8C0 with selector 13, and if a non-null object is returned compares its name against this via ObjectNameComparison (0x00477280); always returns 0.
- `0x0047A550` **CInitVTableConstructor** — Float-value constructor: calls InitVTableSet(this, 1036831949, 1065353216) (~0.05f / 1.0f bit patterns per skeleton prose), installs vtable off_5A61D8, and returns this.
- `0x0047A5B0` **CInitVTableConstructor** — Object constructor: calls InitVTableSet(this, 1036831949, 1065353216), installs vtable off_5A6348, and returns this.
- `0x0047A800` **CInitVTableConstructor** — Range-init constructor: calls InitVTableSet(this, 1028443341, 1065353216), installs vtable off_5A6570, and returns this.
- `0x0047AA80` **CScalarDeletingObject** — Scalar-deleting destructor: resets the vtable to off_5A66E0, runs sub_485EB0 for teardown, frees the object via FreeWrapper_7bcf when the a2 bit-0 flag is set, and returns this.
- `0x0047BAE0` **CScrollListObject** — Bounded counter update: adds the delta a2 to the counter at this+0xEC, clamps to the last valid index (MenuCursorCount_bc90 result minus one) on increment overflow and to zero on negative underflow, then calls UtilityFunction_bd90 (0x0047BD90) and returns its result on both paths.
- `0x0047BB40` **CScrollListObject** — Scroll-jump handler: reads the current scroll position via the virtual getter at vtable slot 28, computes the view center from this+0x110, this+0x118 and the scroll position, updates the bounded page counter via BoundedCounterUpdate (0x0047BAE0) when the target differs, then either returns the half-item-height fine delta or applies a clamped fine offset (this+0x110, bound this+0x114) and refreshes the display via sub_47BE00.
- `0x0047BE70` **CSeasonDatabaseObject** — Factory-init object construction: runs the base initializer sub_4893C0 (0x004893C0), installs vtable off_5A6788, zero-initializes the field at this+0x174, and returns this; called from SeasonDatabaseObjectFactory.
- `0x0047C0D0` **CTextDisplayComponent** — Text-display object constructor helper: delegates to UITextDisplayConstructor (0x00488180) for base initialization, installs vtable off_5A6838, and returns this; no static callers recorded.
- `0x0047C7F0` **CScalarDeletingObject** — Scalar-deleting destructor: runs ObjectInitWithVTableCleanup (0x0048D3E0) for teardown, frees the object via FreeWrapper_7bcf when the a2 bit-0 flag is set, and returns this.

## Proposed classes

### CIndexedListDispatcher

Walks an indexed linked list (head at this+0xF0, count at this+0xFC, target index at this+0x170) and dispatches a virtual call at vtable slot 0x90 of the selected node's data sub-object (node data at node+0x30); returns 0 on any guard failure.

Methods: `0x00477160`

- `this+0x00000000` `void** vtable` (read, UNKNOWN)
- `this+0x000000F0` `ListNode* listHead` (read, GUESS)
- `this+0x000000FC` `int listCount` (read, GUESS)
- `this+0x00000170` `int targetIndex` (read, GUESS)

### CSeasonDatabaseObject

Season-database object family constructed through SeasonDatabaseObjectFactory (0x0047F440): the variant constructor stores a handle at this+0x180 and -1 sentinel indices at 0x184/0x188 (vtable off_5A4600); the factory-init path runs sub_4893C0 and zeroes the field at 0x174 (vtable off_5A6788). The two distinct vtables may denote two types sharing the factory path; the naming derives from the factory caller.

Methods: `0x00477410`, `0x0047BE70`

- `this+0x00000000` `void** vtable` (read_write, UNKNOWN)
- `this+0x00000174` `int factoryInitField` (write, GUESS)
- `this+0x00000180` `int handleOrId` (write, GUESS)
- `this+0x00000184` `int sentinelIndexA` (write, GUESS)
- `this+0x00000188` `int sentinelIndexB` (write, GUESS)

### CStateChangeMonitor

Resolves a tracked object via UtilityFunction_7810 (0x00477810), reads a dword from it, caches it at this+0x184, and invokes the virtual notification at vtable slot 0xA0 (160) when the source value differs from the cache.

Methods: `0x004775F0`

- `this+0x00000000` `void** vtable` (read, UNKNOWN)
- `this+0x00000184` `dword cachedMonitoredValue` (read_write, GUESS)

### CPollingStateMonitor

Polls two monitored state sources and dispatches a virtual notification at vtable slot 0xA0 when either cached value changes: source 1 via virtual slot +0x1C of the this+0x40 sub-object extracted by GuardedAccessor (0x0048D360) against the cache at this+0x11C; source 2 via virtual slot +0x1C of the dword_7CD8C0 interface (command 18) against the cache at this+0x120.

Methods: `0x00477FA0`

- `this+0x00000000` `void** vtable` (read, UNKNOWN)
- `this+0x00000040` `void* sourceSubObject` (read, GUESS)
- `this+0x0000011C` `dword cachedStateA` (read_write, GUESS)
- `this+0x00000120` `dword cachedStateB` (read_write, GUESS)

### CProfileIconLoader

Loads the default profile-icon BMP through a loader sub-object at this+0x40 (sub_497AD0), preferring the path override at this+0x158 and falling back to the default directory byte_5EA438 / aProfileiconDft, stores the loaded object into the field at this+0x124, and signals success (1) or failure (0) via the virtual notification at vtable slot 0x3C.

Methods: `0x00478020`

- `this+0x00000000` `void** vtable` (read, UNKNOWN)
- `this+0x00000040` `void* loaderSubObject` (read, GUESS)
- `this+0x00000144` `dword loadResultHandle` (read, GUESS)
- `this+0x00000158` `char* iconPathOverride` (read, GUESS)

### CShortInitObject

Object family initialized via the shared base initializer ShortComputation_fb70 (0x0048FB70); each method installs a distinct vtable (off_5A4760 / off_5A4810 / off_5A48C0) and initializes the field at this+0xE8 (plus the limit at this+0xEC in one method) with 0 or the -1 all-unlimited sentinel. The inconsistent 0 vs -1 initial values at 0xE8 suggest distinct subtypes or a counter/limit role that is not proven.

Methods: `0x00478110`, `0x004781E0`, `0x00478280`

- `this+0x00000000` `void** vtable` (read_write, UNKNOWN)
- `this+0x000000E8` `int counterOrLimitField` (read_write, GUESS)
- `this+0x000000EC` `int limitField` (write, GUESS)

### CScalarDeletingObject

Scalar-deleting destructor family: runs a teardown sub-call (ObjectInitWithVTableCleanup 0x0048D3E0 or sub_485EB0) on this, frees the child pointer at this+0xE8 when non-null (0x00478140), optionally resets the type vtable, and frees the object via FreeWrapper_7bcf when the a2 bit-0 deletion flag is set; returns this. The distinct vtables (off_5A6068 / off_5A66E0) and teardown routines suggest multiple object types sharing the deletion idiom.

Methods: `0x00478140`, `0x0047A230`, `0x0047AA80`, `0x0047C7F0`

- `this+0x00000000` `void** vtable` (read_write, UNKNOWN)
- `this+0x000000E8` `void* ownedChildPointer` (read, GUESS)

### C4970Object

Object constructed via Constructor_e070 (0x0048E070) with fields this+0xF0 = 0, this+0xF4 = -1 (all-unlimited) and this+0xF8 = 0, and vtable off_5A4970. The -1 at 0xF4 is asserted by existing analysis as a max/limit marker; counter/limit roles are DERIVED prose.

Methods: `0x00478BC0`

- `this+0x00000000` `void** vtable` (write, UNKNOWN)
- `this+0x000000F0` `dword counterFieldA` (write, GUESS)
- `this+0x000000F4` `dword limitOrMaxMarker` (write, GUESS)
- `this+0x000000F8` `dword counterFieldB` (write, GUESS)

### CUIComponent

UI component construction family using UIConstructorWithVTableParams (0x0048D3A0) as the base UI constructor; VTableSetInit (0x004795E0, vtable off_5A4AD8) is shared by UISliderConstructor (0x00479690), ObjectInit (0x004796C0) and sub_479700 (0x00479700), and the other methods install distinct type vtables (off_5A4C48 / off_5A5B60 / off_5A5CD0) and set the enable flag byte at this+0xF0 to 1.

Methods: `0x004795E0`, `0x004796C0`, `0x00479C30`, `0x00479CD0`

- `this+0x00000000` `void** vtable` (read_write, UNKNOWN)
- `this+0x000000F0` `byte enableFlag` (read_write, GUESS)

### CValueBarFormatter

Formats the current value of a value-bar as a percentage string: reads the value through the virtual getter at vtable slot 0xB4 and uses this+0xF4 (min) and this+0xF8 (max) to compute percentage; formatting goes through StringFormatWithBufferOverflowCheck ("%d%%") and StringCopyWithBufferRealloc; always returns 0.

Methods: `0x00479600`

- `this+0x00000000` `void** vtable` (read, UNKNOWN)
- `this+0x000000F4` `float barMinValue` (read, GUESS)
- `this+0x000000F8` `float barMaxValue` (read, GUESS)

### CParamRangeConstructor

Constructor family that seeds range fields via VtableSetWithInitCall (0x00466980) with two literal parameters (float bit patterns such as 0.5/1.0, -1.0/1.0) and then installs a distinct per-type vtable (off_5A4E70 / off_5A4F28 / off_5A5150 / off_5A5208 / off_5A5378 / off_5A5710 / off_5A57C8 / off_5A5938 / off_5A5AA8); two methods additionally set the flag at this+0xF0 to 1 or zero the field at this+0x100. The distinct vtables likely denote distinct subtypes; the grouping is by the shared base-init callee, not proven inheritance.

Methods: `0x00479760`, `0x00479790`, `0x00479820`, `0x00479850`, `0x004798B0`, `0x004799A0`, `0x004799E0`, `0x00479A40`, `0x00479C00`

- `this+0x00000000` `void** vtable` (write, UNKNOWN)
- `this+0x000000F0` `byte enableFlag` (write, GUESS)
- `this+0x00000100` `dword zeroedInitField` (write, GUESS)

### CRangeInitObject5A5E40

Object whose constructor (0x00479E30) installs vtable off_5A5E40 and zeroes the field at this+0x100, and whose scalar-deleting destructor (0x00479E50) resets the same vtable before teardown; the constructor/destructor pair is evidenced by both referencing the shared global off_5A5E40.

Methods: `0x00479E30`, `0x00479E50`

- `this+0x00000000` `void** vtable` (read_write, DERIVED)
- `this+0x00000100` `byte zeroedInitField` (write, GUESS)

### CResourceRegistryObject

Registry client: initializes this via F_5FieldInit (0x004883A0), calls vtable slot +0x1C (28) of the object behind global dword_7CD8C0 with a selector (12 in 0x00479E80, 13 in 0x0047A260), and compares the returned object's name against this via ObjectNameComparison (0x00477280); always returns 0.

Methods: `0x00479E80`, `0x0047A260`

- `this+0x00000000` `void** vtable` (read, UNKNOWN)

### CFlagObject

Flag-management pair: 0x00479EB0 sets the byte at this+0x100 to 1 and 0x00479ED0 clears it to 0, both after calling Return0Stub (0x0047ABB0), and both return 0; the flag semantics are external to these functions.

Methods: `0x00479EB0`, `0x00479ED0`

- `this+0x00000100` `byte stateFlag` (read_write, GUESS)

### CInitVTableConstructor

Constructor family that seeds range fields via InitVTableSet (0x004668E0) with two literal parameters and then installs a distinct per-type vtable (off_5A61D8 / off_5A6348 / off_5A6570); the float-range reading of the integer literals is DERIVED prose, not deterministic packet evidence.

Methods: `0x0047A550`, `0x0047A5B0`, `0x0047A800`

- `this+0x00000000` `void** vtable` (write, UNKNOWN)

### CScrollListObject

Menu scroll-list coupling a bounded counter at this+0xEC (0x0047BAE0, clamped against the count from MenuCursorCount 0x0047BC90, followed by UtilityFunction_bd90 0x0047BD90) with scroll-jump handling (0x0047BB40) that reads the virtual scroll position (vtable slot 0x1C) and manages coarse/fine scroll fields at this+0xF0 (page), this+0x110 (offset), this+0x114 (bound) and this+0x118 (item height), refreshing via sub_47BE00.

Methods: `0x0047BAE0`, `0x0047BB40`

- `this+0x00000000` `void** vtable` (read, UNKNOWN)
- `this+0x000000EC` `int boundedCounter` (read_write, GUESS)
- `this+0x000000F0` `int pageCounterValue` (read, GUESS)
- `this+0x00000110` `float fineScrollOffset` (read_write, GUESS)
- `this+0x00000114` `float scrollMaxBound` (read, GUESS)
- `this+0x00000118` `float itemHeight` (read, GUESS)

### CTextDisplayComponent

Text-display component constructor: delegates base initialization to UITextDisplayConstructor (0x00488180) and installs vtable off_5A6838; no static callers are recorded, so the construction site is unknown.

Methods: `0x0047C0D0`

- `this+0x00000000` `void** vtable` (read_write, UNKNOWN)

## Compatibility contracts

- **IndexedListDispatchContract** — Indexed list dispatch must return 0 when the target index (this+0x170) is outside [0, listCount) (this+0xFC), when the selected node or its data pointer (node+0x30) or sub-object is null, or when the bounds/position check (0x004773A0) fails; otherwise it dispatches the node data sub-object's vtable slot 0x90 and returns its result. A replacement must preserve this guard-then-dispatch contract.
- **ScalarDeletingDestructorContract** — Scalar-deleting destructors run a teardown sub-call (ObjectInitWithVTableCleanup 0x0048D3E0 or sub_485EB0) on the object, optionally free an owned child pointer (this+0xE8, 0x00478140), and free the object itself via FreeWrapper_7bcf when the a2 bit-0 deletion flag is set; the destructor returns the object pointer. A replacement must call the same teardown and honor the bit-0 free flag.
- **StateChangeNotificationContract** — State monitors must re-cache the monitored source value and dispatch the virtual notification at vtable slot 0xA0 (160) whenever the source value differs from the cached copy (this+0x184 for the single-source monitor; this+0x11C / this+0x120 for the dual-source poller). A replacement must preserve change-detection-then-notify behavior.
- **FactorySelectorDispatchContract** — The dispatch interface behind global dword_7CD8C0 must accept selector commands at vtable slot +0x1C (12, 13, 18) and return an object; a null result is guarded before the returned object is compared by name via ObjectNameComparison (0x00477280). A replacement must preserve the slot, selector semantics and null-guard.
- **RangeInitConstructorPattern** — Constructors in this subsystem seed range/state fields through a shared base initializer (VtableSetWithInitCall 0x00466980, InitVTableSet 0x004668E0, UIConstructorWithVTableParams 0x0048D3A0) and then install a per-type vtable at this+0x0; some set the enable flag at this+0xF0 to 1 or zero the field at this+0x100. A replacement that preserves these construction entry points keeps the observed per-type initialization observable.

## Unresolved

- Most function owners are UNKNOWN in the packet; the class boundaries proposed here are inferred from shared callees, shared this-field offsets, shared vtables and shared factory callers, not proven. Per rule 8, equal offsets on different bases were not merged (e.g. field:this:0x000000F0 is read as a page counter in CScrollListObject but written as an enable flag in CParamRangeConstructor / CUIComponent).
- Offset disagreement on the monitored read in 0x004775F0: the raw source literal is v2 + 372 (0x174) while the packet's deterministic field facts declare the read at obj offset 0xA0; both are retained as evidence and need independent corroboration.
- this[62] (offset 0xF8) is flagged as read by packet facts in 0x00477160 but does not appear in the raw decompiled source.
- ValueBarFormatter globals flt_59E6F8 (0x0059E6F8) and aD (0x005C37CC) are flagged by packet facts but absent from the raw decompiled body; their roles are unverified.
- The float-range reading of constructor integer literals (e.g. 1056964608 as 0.5f, -1082130432 as -1.0f) is DERIVED prose, not deterministic packet evidence; the literals may be opaque command/selector values.
- The distinct vtables within CParamRangeConstructor, CInitVTableConstructor, CUIComponent and CShortInitObject likely denote distinct subtypes; each method is a separate subtype constructor, and subtype identity is unknown.
- The dispatch target's interface (virtual at vtable+0x90) and the node data type in 0x00477160 are unknown; the purpose of the position/bounds check relative to the dispatched call is undocumented.
- The meaning of the stored handle/ID at this+0x180 and the two -1 sentinel indices in CSeasonDatabaseObject, and whether its two vtables (0x005A4600 vs 0x005A6788) denote two types sharing SeasonDatabaseObjectFactory, are unresolved.
- The offset relationship in the scroll list is unresolved: BoundedCounterUpdate (0x0047BAE0) updates the counter at this+0xEC while HandleScrollJump (0x0047BB40) is described as updating a page counter at this+0xF0; the two offsets are not proven to be the same quantity.
- The mixed return contract of 0x0047BB40 (the half-item-height value this+0x118/2 on several paths versus the sub_47BE00 result on the clamped path) and the caller's use of it are unverified.
- The second monitored source read at offset 372 in 0x00477FA0 is not a named packet field; the identity of dword_7CD8C0 and the type returned by command 18 are unknown.
- The virtual notification slots (0xA0 / 0x3C) and the value-getter slot 0xB4 are unnamed; their concrete implementations depend on vtables not present in the packet.
- The a2 bit-0 deletion flag in the destructors follows the MSVC scalar-deleting-destructor convention, but the producer call sites are not in the packet, so that role is inference, not packet evidence.
- Return0Stub (0x0047ABB0) is reported as a no-op by the fill; its actual behavior is unverified, and the flag at this+0x100 in CFlagObject has no documented semantic.
- SeasonDatabaseObject naming and the profile-icon / text-display naming are DERIVED from caller relationships or existing analysis prose, not independently proven.
