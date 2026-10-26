# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Proposal for the generic_runtime_objects scope: 30 functions clustered by shared this-field usage, shared callees and shared callers. Two remove-by-value list functions (0x004BA7A0, 0x004BAE20) share the {head +0, tail/current +4/+8, count +0xC} container layout and 12-byte {value +0, next +4, free-flag +8} node layout and both feed NetworkMessageDispatch (0x004B54E0), forming ValueNodeList. Two recursive merge sorts (0x004BAB20, 0x004BB2E0) form MergeSortListSorter. Four functions sweep an 8x8 grid at a 9-dword cell stride with a trailing cell at +576 (0x004BDDE0 cleanup via StructCleanup 0x004BD800, 0x004BDE20 cell-index push via DynamicArrayPush 0x004BD860, 0x004BDF90 per-cell comparison 0x004BD8C0, 0x004BE180 per-cell remove 0x004BD970) and share grid origin/scale fields at 0x924-0x930, forming ObjectGrid8x8; the per-cell dynamic array is the single-function DynamicIntArray (0x004BD860). Two StructCleanup wrappers (0x004BD7D0, 0x004BD7F0) form OwnerPointerStruct; two resource-list-using functions (0x004C5DB0, 0x004C5DE0) form FilterPropertyList; three vtable-slot functions over this+0x20/0x24/0x28 (0x004C91D0, 0x004C9310, 0x004C9790) form TripleSubObjectHolder. The remaining 13 functions are single-method classes with UNKNOWN owners in the IR. All class boundaries are GUESS synthesis; every named field is a DERIVED reading of an evidenced offset.

## Function roles

- `0x004BA7A0` **ValueNodeList** — Remove-by-value from a list container {head +0x0, tracked nodes +0x4/+0x8, count +0xC}: guards on null value and empty head, walks next pointers (+0x4) comparing node value (+0x0) against a2, unlinks the match (repointing predecessor next or head), repoints the tracked node slots when they referenced the removed node, decrements count, clears the free-data flag byte (+0x8) unless a3 is set, conditionally frees the node data via EmptyStub_0170 then FreeWrapper_7bcf, always frees the node, returns 1 (0 on all failure guards). Called by NetworkMessageDispatch (0x004B54E0).
- `0x004BA820` **QuadZeroInitializer** — Constructor-style initializer zeroing the first four DWORD fields (this+0x0, +0x4, +0x8, +0xC) and returning this. Structural twin of sub_4A1F60. Called by CarPhysicsStateInitializer (0x004B57F0) and sub_5837F0.
- `0x004BAB20` **MergeSortListSorter** — Recursive merge sort (stdcall) of a singly linked list keyed by the float at each node's payload record +4: counts nodes, splits at the midpoint by severing the middle next-link, recurses on both halves, merges ascending by the float key, returns the new head (or the original head for null/singleton lists). Structural twin of MergeSortOnLinkedList (00465c70) per cluster evidence. Feeds a collision-object list via CollisionObjectListManagement (0x004B4B50).
- `0x004BAE20` **ValueNodeList** — Singly-linked-list remove-by-value on a container {head +0, tail +4, current +8, count +0xC}: captures the head node's data, clears the head node's free-flag byte (+8), walks next (+4) for the node whose data (+0) equals the captured value, unlinks it, updates head/tail/current/count, conditionally frees data (path normally suppressed) and always frees the node via FreeWrapper_7bcf, returns the removed node's data pointer (0 on empty/not-found). Called by NetworkMessageDispatch (0x004B54E0).
- `0x004BB2E0` **MergeSortListSorter** — Recursive merge sort of a singly linked list by a float key (descending, >= keeps the right half's node on ties) read at the node's data pointer (+0): counts via next (+4), splits at the midpoint, recurses on both halves, merges by relinking next pointers, returns the new head. Returns input unchanged for null/singleton lists. Caller: SortedLinkedListInsert (0x004B81A0).
- `0x004BD760` **SentinelSlotBuffer** — Scans the fixed 10-dword slot array at this+0xE0 for the first slot holding sentinel -1, stores the value read from this+0x8 into it, returns the slot index (or 10 when the array is full). Called per-frame by PostPitCleanup (0x0042A6F0).
- `0x004BD7D0` **OwnerPointerStruct** — Init/teardown helper: zeros three fields at 0x8, 0x14 and 0x20, then invokes StructCleanup (0x004BD800) which frees the owned pointers formerly held at this[2]/this[5]/this[8] and clears the surrounding pointer fields, then returns this. Unconditional sequence; called from AudioMixerChannelInit (0x004BDB90).
- `0x004BD7F0` **OwnerPointerStruct** — Thunk wrapper (__thiscall) forwarding the `this` pointer unchanged to StructCleanup and returning its result. No own logic, fields, globals or guards; the delegated StructCleanup target is not evidenced in this packet.
- `0x004BD860` **DynamicIntArray** — Dynamic int-array push-back: when count (+0x4) equals capacity (+0x0) grows capacity by 8 (allocate 4-byte-per-element buffer via OperatorNewNhMallocWrapper 0x00587C03, copy existing elements, free old buffer via FreeWrapper_7bcf), appends a2 at data[count] (+0x8), increments count, returns the previous count.
- `0x004BDDE0` **ObjectGrid8x8** — Runs StructCleanup (0x004BD800) over an 8x8 grid of element pointers with a 9-slot stride, then a final StructCleanup on the base advanced by 576 slots; both loop counters hardcoded to 8. Caller Game_Post (0x0042DA30) supplies the grid base.
- `0x004BDE20` **ObjectGrid8x8** — Computes four clamped 0..7 cell indices from the extents of float argument a2 using grid origin/scale fields at this+0x924/0x928/0x92C/0x930 (via CRTFtol 0x00587BDC), pushes a2 into every overlapping cell's object list via DynamicArrayPush (0x004BD860); the sentinel flag set unconditionally after coordinate computation also routes a2 into the aggregate list at this+576, whose push result is returned.
- `0x004BDF90` **ObjectGrid8x8** — Iterates the 8x8 grid of 9-dword records calling ArithmeticComparison_d8c0 (0x004BD8C0) on every element, then a final call on this+576, returning its result. Called by ConditionalCleanupChain (0x0040F100) and StateDependentUpdateDispatch (0x0040F130).
- `0x004BE180` **ObjectGrid8x8** — Sweeps the 8x8 grid (9-dword stride) calling ArrayRemoveByValue (0x004BD970) on each cell for value a2, then a final ArrayRemoveByValue(this + 576, a2) just past the grid, returning its result. Invoked on the frame path by ShortComputation_f0d0 (0x0040F0D0) and StateDependentUpdateDispatch (0x0040F130).
- `0x004BE6F0` **PerformanceSetupDelegate** — Thin __thiscall delegation: invokes PerformanceSetupStructInitializer (0x004BE700) with no explicit arguments and returns the `this` pointer unchanged; the callee performs the actual initialization.
- `0x004BE9E0` **AnimationParameterSetter** — Animation/behavior parameter setter: writes two byte flags (this+0x340, this+0x341) and two DWORDs (this+0x344, this+0x350) from arguments, returning the third argument a4 unchanged. Called by AIBehaviorInitialization (0x004BF0A0) during behavior setup.
- `0x004C5830` **SceneIndexSetter** — Stores its argument into the global scene-index dword dword_8AC48C and returns the argument unchanged.
- `0x004C5DB0` **FilterPropertyList** — Object initializer reached from the season database factory: writes literals 0, -1, 0, 0, 0, 0 into the first six dword fields (this+0x0..+0x14), then invokes ResourceListCleanup_62c0 (0x004C62C0) on this and returns the this pointer.
- `0x004C5DE0` **FilterPropertyList** — Full teardown of a filter-property structure: cleans the inner resource list via ResourceListCleanup (0x004C62C0), walks the linked list of nodes (head at this+0x8, next at node+4) freeing each node's data block (secondary pointer at data+4 first, then data at +0) when the ownership flag byte at node+8 is set, frees the node, zeroes the four list fields (0x8/0xC/0x10/0x14), then frees the base structure pointer at this+0x0 when present. Called by sub_47FB10 (0x0047FB10).
- `0x004C6780` **RandomSceneEntryPicker** — Random scene-entry selection: generates a random index from the 64-bit random state at this+0x14 (via ReadFieldAtOffset0x14 0x005871F0), bounds-checks the candidate via BoundsCheckedIndexSetter_6760 (0x004C6760) against the list count at this+20, walks the linked list from this+8, and returns the scene entry at dword_8AC490 + 396*index when the node's scene index lies in [0, dword_8AC488); returns 0 on any guard failure.
- `0x004C7F28` **FieldZeroInitializer** — Trivial __thiscall initializer writing 0 into the member at this+0x4 (this[1]). Structural twin of FieldZero4 per the cluster_copy prelabel (cluster_rep 004c7dd0).
- `0x004C8EE0` **SingletonRNGGuard** — Singleton initializer guarded by flag byte_8AC4DC bit 0: on the already-initialized fast path increments the reference counter dword_8AC4D8 and returns 1; otherwise sets the flag, calls RandLCGRandomNumberGenerator (0x005884ED) to seed the generator, resets the counter to 1, and returns 1.
- `0x004C91D0` **TripleSubObjectHolder** — Releases up to three vtable-based sub-objects at this+0x20, this+0x24 and this+0x28: for each non-null slot calls vtable[0] with flag 1 (final release) then nulls the slot; returns the result of the last executed release (never written when all three slots are null). Called by sub_4C9060 (0x004C9060).
- `0x004C9280` **StateIndexEqualityCheck** — State-equality check: returns 0 unless a2 equals the state index at this+0x1C; on match calls StateIndexedFieldGetter (0x004C9260) to obtain an indexed field object, returns 0 if it is null or its vtable+28 virtual call returns 2, otherwise 1.
- `0x004C9310` **TripleSubObjectHolder** — Dispatches the vtable+8 (third-slot) method on up to three sub-objects at this+0x20, this+0x24 and this+0x28 in order; the third dispatch's result is returned directly, otherwise the last executed result. Unlike a destructor it never nulls or frees the slot pointers.
- `0x004C9360` **VTableSwitchDestructor** — Deleting-style destructor with vtable switching: writes the destructor-phase vtable off_5ACE4C into this[0], calls the destructor body sub_4C94D0 (0x004C94D0), restores the base vtable off_5ACE2C, and when a2 & 1 is set (deleting flag) frees the object's own heap block via FreeWrapper_7bcf (0x00587BCF). Returns this unchanged.
- `0x004C9790` **TripleSubObjectHolder** — Releases a single sub-object at this+0x20 by dispatching its vtable slot 0 with final flag 1, then nulls the slot (skip when already null); returns the call's result. Minimal destructor body; called by VTableSwitchDtor (0x004C9600).
- `0x004C9840` **AmbientSoundLoader** — Loads and starts the ambient sound 'ambient\pithorn.wav' through the global sound manager dword_8AC4C4: builds the full path via StringFormatWithBufferOverflowCheck (0x0058815F) and StringCopyWithBufferRealloc (0x00566650), creates a stream via the manager's vtable offset 92, stores the handle at this+0x1C; if already playing it stops and clears the handle, otherwise writes volume/pan/fade parameters at this+0x38/0x3C/0x40; frees the path buffer and returns 0.
- `0x004C9980` **RenderObjectPositioner** — Positions a render object: loads the render-object pointer this[7] (this+0x1C) and, when non-null, zeroes a 12-byte local buffer and makes a virtual call through the object's vtable slot +4 with arguments (v1, 2, this+2, zeroed buffer, LODWORD(flt_7CF2CC), 1065353216 as float 1.0, 1). Always returns 0.
- `0x004C99D0` **RenderStatusUpdateDispatch** — Gated per-frame update on the global init-status object dword_8AC4C4: when non-null invokes its vtable slot 36 as a __thiscall status query with three out-buffers, and when the sampled carry/parity flags indicate a pending state invokes vtable slot 40 with arguments 1, 1065353216, 1051931443. Always returns 0.
- `0x004C9A50` **ParticleEmitterFactory** — Particle-emitter factory selected by the integer type id in `this`: types 1, 2, 5, 6, 7 each allocate a distinct heap block (44/40/28/36/32 bytes) via OperatorNewNhMallocWrapper (0x00587C03), initialize it through ParticleEmitterInit (0x004C8F10) with a per-type lifetime parameter, install a type-specific vtable pointer, and return the emitter; types 3, 4 and the default return null. Every allocation is null-checked. Called by NetworkMessageReceiveAndDispatch (0x004C7CA0).

## Proposed classes

### ValueNodeList

Singly-linked list container {head +0, tail/current +4/+8, count +0xC} holding 12-byte nodes {value/data +0, next +4, free-data flag byte +8}; removes a node by value, repointing head/tail/current as needed, decrementing the count, conditionally freeing node data (EmptyStub_0170 then FreeWrapper_7bcf) when the flag is set, and always freeing the node. Both methods are reachable from NetworkMessageDispatch (0x004B54E0).

Methods: `0x004BA7A0`, `0x004BAE20`

- `this+0x00000000` `void* head` (read_write, DERIVED)
- `this+0x00000004` `void* tail` (read_write, GUESS)
- `this+0x00000008` `void* current` (read_write, GUESS)
- `this+0x0000000C` `int count` (read_write, DERIVED)
- `obj+0x00000000` `void* nodeValue` (read_write, DERIVED)
- `obj+0x00000004` `void* nodeNext` (read_write, DERIVED)
- `obj+0x00000008` `byte nodeFreeDataFlag` (read_write, DERIVED)

### MergeSortListSorter

Recursive merge sorts of singly linked lists by float sort keys. 0x004BAB20 keys on the float at the node payload record +4 (ascending) for the collision-object list; 0x004BB2E0 keys on the float at the node's data pointer +0 (descending, >= tie-break) for a sorted-insert list. Node next links live at +4 in both variants; the key conventions differ between the two methods.

Methods: `0x004BAB20`, `0x004BB2E0`

- `obj+0x00000004` `void* nodeNext` (read_write, DERIVED)
- `obj+0x00000000` `void* nodeKeyReference` (read, GUESS)

### ObjectGrid8x8

Spatial object grid: 8x8 cells at a 9-dword stride with a trailing element just past the grid (this + 576 dwords). Grid origin/scale-inverse fields at this+0x924/0x928 (X) and this+0x92C/0x930 (Y) map extents to clamped 0..7 cell indices. Insert pushes into every overlapping cell (DynamicArrayPush 0x004BD860), removal sweeps all cells (ArrayRemoveByValue 0x004BD970), per-frame comparison visits all cells (ArithmeticComparison_d8c0 0x004BD8C0), teardown runs StructCleanup (0x004BD800) per element.

Methods: `0x004BDDE0`, `0x004BDE20`, `0x004BDF90`, `0x004BE180`

- `this+0x00000924` `float gridOriginX` (read, GUESS)
- `this+0x00000928` `float gridScaleInvX` (read, GUESS)
- `this+0x0000092C` `float gridOriginY` (read, GUESS)
- `this+0x00000930` `float gridScaleInvY` (read, GUESS)

### DynamicIntArray

Growable array of 4-byte elements: capacity at +0x0, element count at +0x4, data buffer pointer at +0x8. pushBack appends a value, growing capacity by 8 (allocate/copy/free-old) when full, and returns the previous count. Also serves as the per-cell object list of ObjectGrid8x8.

Methods: `0x004BD860`

- `this+0x00000000` `int capacity` (read_write, DERIVED)
- `this+0x00000004` `int count` (read_write, DERIVED)
- `this+0x00000008` `void* data` (read_write, DERIVED)

### OwnerPointerStruct

Small struct cleaned through the shared StructCleanup helper (0x004BD800, which frees owned pointers at this[2]/this[5]/this[8] and clears the pointer fields). 0x004BD7D0 zeroes those three slots then runs the cleanup; 0x004BD7F0 is a __thiscall thunk forwarding this to the same cleanup.

Methods: `0x004BD7D0`, `0x004BD7F0`

- `this+0x00000008` `void* ownedPtrA` (read_write, DERIVED)
- `this+0x00000014` `void* ownedPtrB` (read_write, DERIVED)
- `this+0x00000020` `void* ownedPtrC` (read_write, DERIVED)

### FilterPropertyList

Filter-property structure: base pointer at +0x0, literal -1 at +0x4, and a linked node list with head/tail/iterator/count at 0x8/0xC/0x10/0x14. 0x004C5DB0 is the constructor-style initializer (writes 0,-1,0,0,0,0 and cleans the inner resource list); 0x004C5DE0 is the full teardown (resource-list cleanup, per-node data+secondary-pointer free via FreeWrapper when the owned-flag byte at node+8 is set, node free, list fields zeroed, base pointer freed).

Methods: `0x004C5DB0`, `0x004C5DE0`

- `this+0x00000000` `void* baseStructPtr` (read_write, DERIVED)
- `this+0x00000004` `int sentinelMinusOne` (read_write, GUESS)
- `this+0x00000008` `void* listHead` (read_write, DERIVED)
- `this+0x0000000C` `void* listTail` (read_write, GUESS)
- `this+0x00000010` `void* listIterator` (read_write, GUESS)
- `this+0x00000014` `int listCount` (read_write, DERIVED)
- `obj+0x00000000` `void* nodeData` (read, DERIVED)
- `obj+0x00000008` `byte nodeOwnedFlag` (read, GUESS)

### TripleSubObjectHolder

Holder of up to three vtable-based sub-objects at this+0x20/0x24/0x28. 0x004C91D0 is a release-style destructor dispatching vtable[0] with flag 1 then nulling each slot; 0x004C9310 dispatches the vtable+8 (third-slot) method on each without nulling; 0x004C9790 releases a single sub-object at this+0x20 (vtable[0] flag 1, then nulls the slot).

Methods: `0x004C91D0`, `0x004C9310`, `0x004C9790`

- `this+0x00000020` `void* subObjectA` (read_write, DERIVED)
- `this+0x00000024` `void* subObjectB` (read_write, DERIVED)
- `this+0x00000028` `void* subObjectC` (read_write, DERIVED)

### SentinelSlotBuffer

Fixed 10-slot dword array at this+0xE0 holding sentinel -1 slots; inserts the value at this+0x8 into the first free slot and returns its index (10 when full). Called per-frame by PostPitCleanup.

Methods: `0x004BD760`

- `this+0x00000008` `int storedValue` (read, DERIVED)
- `this+0x000000E0` `int[10] slotArray` (read_write, DERIVED)

### PerformanceSetupDelegate

Thin __thiscall delegation that invokes PerformanceSetupStructInitializer (0x004BE700) with no explicit arguments and returns this unchanged; the callee does the actual initialization.

Methods: `0x004BE6F0`


### AnimationParameterSetter

Behavior/animation parameter setter writing two byte flags (this+0x340/+0x341) and two DWORDs (this+0x344/+0x350) from arguments and returning the third argument. Called by AIBehaviorInitialization during behavior setup.

Methods: `0x004BE9E0`

- `this+0x00000340` `byte flagByteA` (write, DERIVED)
- `this+0x00000341` `byte flagByteB` (write, DERIVED)
- `this+0x00000344` `int valueDwordA` (write, DERIVED)
- `this+0x00000350` `int valueDwordB` (write, DERIVED)

### SceneIndexSetter

Writes its argument into the global scene-index dword dword_8AC48C and returns the argument unchanged.

Methods: `0x004C5830`


### RandomSceneEntryPicker

Randomly selects a scene entry: reads the 64-bit random state at this+0x14, bounds-checks a derived candidate against the list count, walks the linked list from this+8, and returns the entry at dword_8AC490 + 396*index when the node's scene index is within [0, dword_8AC488).

Methods: `0x004C6780`

- `this+0x00000008` `void* listHead` (read, DERIVED)
- `this+0x00000014` `uint64 randomState` (read, GUESS)

### FieldZeroInitializer

Trivial initializer writing 0 into the member at this+0x4.

Methods: `0x004C7F28`

- `this+0x00000004` `int zeroedField` (write, DERIVED)

### SingletonRNGGuard

Singleton initializer guarded by the global flag byte_8AC4DC bit 0 with a reference counter at dword_8AC4D8: already-initialized calls increment the counter, first calls set the flag, seed the RNG via RandLCGRandomNumberGenerator and reset the counter to 1.

Methods: `0x004C8EE0`


### StateIndexEqualityCheck

State-equality predicate: matches argument a2 against the state index at this+0x1C, fetches an indexed field object via StateIndexedFieldGetter (0x004C9260), and returns 1 only when the object is present and its vtable+28 call does not return 2.

Methods: `0x004C9280`

- `this+0x0000001C` `int stateIndex` (read, DERIVED)

### VTableSwitchDestructor

Deleting-style destructor with vtable switching: this[0] is switched to the destructor-phase vtable off_5ACE4C while the destructor body sub_4C94D0 runs, then restored to the base vtable off_5ACE2C; the object's heap block is freed via FreeWrapper when the a2 & 1 deleting flag is set. Returns this.

Methods: `0x004C9360`

- `this+0x00000000` `void* vtablePtr` (read_write, DERIVED)

### AmbientSoundLoader

Loads and starts the ambient sound file 'ambient\pithorn.wav' through the global sound manager dword_8AC4C4, storing the sound handle at this+0x1C and writing volume/pan/fade parameters at this+0x38/0x3C/0x40; already-playing sounds are stopped and the handle cleared. Always returns 0.

Methods: `0x004C9840`

- `this+0x0000001C` `void* soundHandle` (read_write, DERIVED)
- `this+0x00000038` `float volumeParam` (write, GUESS)
- `this+0x0000003C` `float panParam` (write, GUESS)
- `this+0x00000040` `float fadeParam` (write, GUESS)

### RenderObjectPositioner

Sets a render object's transform/position: reads the render-object pointer at this+0x1C and, when non-null, makes a virtual call through its vtable slot +4 with position/parameter arguments. Always returns 0.

Methods: `0x004C9980`

- `this+0x0000001C` `void* renderObjectPtr` (read, DERIVED)

### RenderStatusUpdateDispatch

Gated per-frame update on the global init-status object dword_8AC4C4: queries its vtable slot 36 with three out-buffers and, when the sampled flags indicate a pending state, triggers vtable slot 40 with constant arguments. Always returns 0.

Methods: `0x004C99D0`


### ParticleEmitterFactory

Factory that allocates and initializes a particle emitter selected by the integer type id in `this`: types 1/2/5/6/7 allocate per-type heap blocks, initialize via ParticleEmitterInit with per-type lifetime, and install type-specific vtable pointers; types 3/4/default return null. Allocations are null-checked.

Methods: `0x004C9A50`


### QuadZeroInitializer

Constructor-style initializer zeroing the first four DWORD fields (offsets 0x0, 0x4, 0x8, 0xC) and returning the object pointer. Structural twin of sub_4A1F60; called by CarPhysicsStateInitializer (0x004B57F0) and sub_5837F0.

Methods: `0x004BA820`

- `this+0x00000000` `int fieldA` (write, DERIVED)
- `this+0x00000004` `int fieldB` (write, DERIVED)
- `this+0x00000008` `int fieldC` (write, DERIVED)
- `this+0x0000000C` `int fieldD` (write, DERIVED)

## Compatibility contracts

- **ValueNodeListLayout** — The remove-by-value list container keeps head at +0x0, tail at +0x4, current at +0x8 and count at +0xC; nodes are 12 bytes {value +0, next +4, free-data flag byte +8}. Removal unlinks the matched node, repoints head/tail/current, decrements the count, releases the node data only when the flag is set (EmptyStub_0170 then FreeWrapper_7bcf), always frees the node, and returns the removed data pointer (or 1/0 by variant).
- **ObjectGrid8x8Layout** — The spatial grid is 8x8 cells at a 9-dword stride with a trailing element at this + 576 dwords (64 cells * 9). Grid origin/scale-inverse fields sit at this+0x924/0x928 (X) and this+0x92C/0x930 (Y) and map argument extents to clamped 0..7 cell indices. Cells accept push (DynamicArrayPush 0x004BD860), remove-by-value (ArrayRemoveByValue 0x004BD970) and per-element comparison (ArithmeticComparison_d8c0 0x004BD8C0); teardown runs StructCleanup (0x004BD800) on every element.
- **DynamicIntArrayLayout** — The dynamic int array stores capacity at +0x0, element count at +0x4 and the data buffer pointer at +0x8; pushBack grows capacity by 8 when full (allocate 4-byte-per-element buffer, copy, free old), appends at data[count], increments the count and returns the previous count.
- **FilterPropertyListLayout** — The filter-property structure holds a base pointer at +0x0, a literal -1 at +0x4, and a linked node list with head/tail/iterator/count at 0x8/0xC/0x10/0x14. Nodes are {data pointer +0, next +4, owned-flag byte +8}; the data block holds a primary pointer at +0 and an optional secondary pointer at +4. The constructor writes 0,-1,0,0,0,0 and cleans the inner resource list (0x004C62C0); teardown frees each node's data and secondary pointer when the owned flag is set, frees the node, zeroes the four list fields, and frees the base pointer.
- **TripleSubObjectSlots** — The holder stores up to three vtable-based sub-object pointers at this+0x20, this+0x24 and this+0x28. Release dispatch calls vtable slot 0 with flag 1 (final release) and nulls the slot afterwards; the vtable+8 (third-slot) entry is dispatched without nulling. Both slots are indirect calls resolved at runtime.
- **SceneGlobalsContract** — The scene registry is exposed through globals: dword_8AC48C is the current scene index (written by 0x004C5830), dword_8AC488 is the scene-count bound, and dword_8AC490 is the base of a scene-entry array with a 396-byte stride, indexed by the node's scene index when it lies in [0, dword_8AC488).
- **SingletonGuardGlobals** — The singleton guard uses flag byte_8AC4DC bit 0 and reference counter dword_8AC4D8: already-initialized calls increment the counter; first calls set the flag, seed the RNG via RandLCGRandomNumberGenerator (0x005884ED) and reset the counter to 1.
- **VTableSwitchDestructorContract** — The deleting destructor switches this[0] to the destructor-phase vtable off_5ACE4C before running the body sub_4C94D0 and restores the base vtable off_5ACE2C afterwards; the object's heap block is freed via FreeWrapper_7bcf when the a2 & 1 deleting flag is set. Returns this unchanged.
- **AmbientSoundParameterSlots** — The ambient sound object stores its sound handle at this+0x1C and volume/pan/fade parameters at this+0x38/0x3C/0x40; the sound is created through the global manager dword_8AC4C4's vtable offset 92, and an already-playing sound is stopped and its handle cleared before the parameters are written. Returns 0.

## Unresolved

- All function owners are UnknownObject in the validated IR; every class boundary, method-to-class assignment and class name in this proposal is GUESS synthesis over shared this-field usage, shared callees and shared callers.
- Merging 0x004BA7A0 and 0x004BAE20 into ValueNodeList relies on the identical {head +0, tail +4, current +8, count +0xC} container layout and identical 12-byte node layout; for 0x004BA7A0 the roles of the two tracked node pointers (+0x4/+0x8) are not independently distinguishable, and only forward links appear in its source (the 'doubly linked' part of the canonical name is unsupported).
- The node field obj+0xC is referenced by packet facts (init literal 0) but never appears in the decompiled logic of 0x004BA7A0, 0x004BAB20 or 0x004BAE20; its meaning is unknown and it is carried here only as an unresolved evidence ref.
- The two MergeSortListSorter methods use different key conventions (float at payload+4 for 0x004BAB20 vs float at the node data pointer +0 for 0x004BB2E0) and different sort directions (ascending vs descending with >= tie-break); treating them as one class is a deliberate simplification.
- The 0x004BAB20 sort-key field annotations are inconsistent in the packet (field obj+0x4 and field *(this+0x8)+0x4); the base-pointer convention for the payload record is not settled.
- The grid cell array base within ObjectGrid8x8 is not evidenced by any this-offset field; the cell stride (9 dwords/9 slots) and the trailing element at +576 are the only structural facts, and whether the grid is an array of structs or of pointers is not resolvable from these functions alone.
- Grid origin/scale semantics for this+0x924..0x930 are DERIVED from the coordinate arithmetic in 0x004BDE20, not named by the packet.
- The sentinel flag v16 in 0x004BDE20 is assigned 1 unconditionally after each coordinate computation, so the this+576 aggregate push effectively always runs; the earlier claim that it flags out-of-range clamping is not supported by the raw source.
- 0x004BD7F0 is a thunk forwarding this to StructCleanup, but the packet carries no callee evidence for it; the actual cleanup target (assumed to be the shared 0x004BD800) is unresolved.
- The four zeroed/freed fields of OwnerPointerStruct (0x8/0x14/0x20) are owned-pointer slots per StructCleanup's own IR (DERIVED), but the struct type and the meaning of the fields are unknown.
- The purpose of the -1 literal at FilterPropertyList this+0x4 is unknown; the resource-list cleanup helper 0x004C62C0 is not in this packet.
- The exact layout of the per-node filter-property data block (primary pointer +0, secondary +4) and the meaning of the owned-flag byte at node+8 are inferred from the guard/free pattern, not proven.
- The singleton identity, the purpose of the reference counter dword_8AC4D8, and whether RandLCGRandomNumberGenerator receives a meaningful seed through `this` are unresolved; no static callers of 0x004C8EE0 are known.
- The 396-byte scene-array stride and the names dword_8AC488/dword_8AC48C/dword_8AC490 are DERIVED labels, not proven field names.
- The concrete vtable[0]/vtable+8 targets of TripleSubObjectHolder sub-objects are indirect calls resolved at runtime; the flag-1 release semantics and the 'result read uninitialized when all slots are null' path are inferred from the destructor context.
- The vtable+28 result == 2 check in 0x004C9280 is treated as an equality-marker test only; its semantic meaning is unknown.
- The exact per-type emitter classes behind ParticleEmitterFactory's vtable pointers are unresolved; RandLCGRandomNumberGenerator appears in the raw source of type 6 but has no packet callee entry; the flt_5ACE18 to type-5 lifetime linkage is DERIVED from existing analysis only.
- The this parameter of 0x004C9A50 doubles as the type selector, which is unusual for a factory; types 3 and 4 return null with no allocation.
- 0x004C9840 and 0x004C9980 both use this+0x1C but interpret it differently (sound object handle vs render-object pointer); whether this is the same object type or a conflict is unresolved.
- Global dword_8AC4C4 is used as a sound manager by 0x004C9840 and as an init-status object by 0x004C99D0; the two roles may be the same system manager or distinct globals sharing an address in the reading.
- Globals flt_59E43C/flt_59E440 (0x0059E43C/0x0059E440) and flt_5ACE20/dword_5ACE24/dword_5ACE28 (0x005ACE20/0x005ACE24/0x005ACE28) are flagged by packet facts but absent from the raw decompiled bodies of 0x004C9840 and 0x004C99D0 respectively; likely inlined constants, carried as unresolved evidence.
- The sound/render vtable offsets (20 = is-playing test, 0 = stop/release, 4 = transform, 36/40 = status/trigger, 92 = stream-create) are inferred from call shapes, not named members; the flag argument 1 to vtable[0] is assumed to be a final-release flag.
- Whether `this` is passed implicitly to 0x004BE700 by 0x004BE6F0 through a shared global or a member pointer is unknown.
- The purpose of the 10-slot sentinel array (0x004BD760) and its stored value at this+0x8 are caller-dependent; PostPitCleanup (0x0042A6F0) is the only known caller.
- 0x004BA820 zeroes four DWORDs whose semantic meaning is unknown; callers indicate a car-physics-related context.
