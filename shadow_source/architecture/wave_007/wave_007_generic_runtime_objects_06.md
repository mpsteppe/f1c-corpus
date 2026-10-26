# RuntimeObjectSystem

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Reconstructs a family of generic runtime/UI objects. A large cluster of methods dispatch integer selectors through a global command-dispatch interface (dword_7CD8C0, vtable slot 28) and either cache the returned object at this+0xE0 or compare it with this via ObjectNameComparison. Two state monitors (0x00478220, 0x004782C0) and one resource monitor (0x00478350) poll an external value, cache it, and notify via this's vtable slot 44. The menu cursor widget group (0x0047BC30, 0x0047BC90, 0x0047BCF0, 0x0047BD90) shares one this object and performs cursor-count, scroll-offset, and scroll-bar-thumb computation over a text source. Sixteen constructors install distinct vtables after calling a shared base initializer (InitVTableSet 0x004668E0 / VtableSetWithInitCall 0x00466980) with two scalar/float range arguments. Remaining functions are assorted virtual-dispatch entries, a conditional string-copy wrapper, and a run-and-maybe-release helper. Owner object types are overwhelmingly UNKNOWN; all groupings are DERIVED or GUESS proposals on top of the function IR.

## Function roles

- `0x00478090` **DispatchCacheOwner** — Dispatch selector 20 through ICommandDispatcher (vtable slot 28 on dword_7CD8C0) and cache the returned object pointer at this+0xE0; returns 0.
- `0x004780D0` **DispatchCacheOwner** — Read session state via SessionStateCheck (0x00461CD0) on global 0x007CD25C; dispatch selector 23 (state == 3) or 21 (otherwise) through ICommandDispatcher and cache the result at this+0xE0; returns 0.
- `0x00478180` **DispatchCacheOwner** — Dispatch selector 17 through ICommandDispatcher and cache the returned object pointer at this+0xE0; returns 0.
- `0x004781A0` **DispatchCacheOwner** — Read session state via SessionStateCheck (0x00461CD0); dispatch selector 24 (state == 3) or 17 (otherwise) through ICommandDispatcher and cache the result at this+0xE0; returns 0.
- `0x00478200` **DispatchCacheOwner** — Dispatch selector 22 through ICommandDispatcher and cache the returned object pointer at this+0xE0; returns 0.
- `0x00478220` **SelectionStateMonitor** — Poll current selection via ICommandDispatcher selector 22; if the returned object is non-null, compare its state field against cached this+0xE8 and, on change, update the cache and notify via this's vtable slot 44 with argument 1; returns 0.
- `0x004782A0` **DispatchCacheOwner** — Dispatch selector 16 through ICommandDispatcher and cache the returned object pointer at this+0xE0; returns 0.
- `0x004782C0` **SelectionStateMonitor** — Poll state via ICommandDispatcher selector 16; if the returned object is non-null, read its dword at +0x174, compare against cached this+0xE8 and, on change, update the cache and notify via this's vtable slot 44 with argument 1; returns 0.
- `0x00478350` **ResourceStateMonitor** — Monitor a resource referenced by the handle at this+0xE0: read its state at resource+0x2C, compare against cached this+0xE4 and, on change, update the cache, call ProfileIconPathSetter (0x00478390) and notify via this's vtable slot 44 with argument 1; returns 0.
- `0x00478690` **SubObjectSelector** — Select the sub-object pointer at this+0x118 based on the flag at this+0x138, calling vtable slot 0x3C on this with argument 1 (enabled) or 0 (disabled); returns the sub-object pointer or null.
- `0x00478EC9` **SubObjectSelector** — Trivial getter returning this+0x118 with no side effects.
- `0x004797C0` **ParameterizedRuntimeObject** — Constructor: base-init VtableSetWithInitCall(this, 0.5f, 1.0f), then install vtable off_5A4FE0 at this+0x0; returns this.
- `0x004797F0` **ParameterizedRuntimeObject** — Constructor: base-init VtableSetWithInitCall(this, 0, 1051931443), then install vtable off_5A5098 at this+0x0; returns this.
- `0x00479880` **ParameterizedRuntimeObject** — Constructor: base-init VtableSetWithInitCall(this, -1082130432, 1065353216), then install vtable off_5A52C0 at this+0x0; returns this.
- `0x004798E0` **ParameterizedRuntimeObject** — Constructor: base-init VtableSetWithInitCall(this, -1082130432, 1065353216), then install vtable off_5A5430 at this+0x0; returns this.
- `0x00479910` **ParameterizedRuntimeObject** — Constructor: base-init VtableSetWithInitCall(this, 0, 0.5f), then install vtable off_5A54E8 at this+0x0; returns this.
- `0x00479940` **ParameterizedRuntimeObject** — Constructor: base-init VtableSetWithInitCall(this, 0, 1.0f), install vtable off_5A55A0 at this+0x0, and set the enable byte at this+0xF0 to 1; returns this.
- `0x00479970` **ParameterizedRuntimeObject** — Constructor: base-init VtableSetWithInitCall(this, 0.5f, 2.0f), then install vtable off_5A5658 at this+0x0; returns this.
- `0x00479A10` **ParameterizedRuntimeObject** — Constructor: base-init VtableSetWithInitCall(this, 0.5f, 1.0f), then install vtable off_5A5880 at this+0x0; returns this.
- `0x00479CA0` **NameComparisonDispatch** — Dispatch selector 14 through ICommandDispatcher; if non-null, pass the result to ObjectNameComparison (0x00477280) with this; returns 0.
- `0x00479D00` **NameComparisonDispatch** — Dispatch selectors 14 then 15 through ICommandDispatcher; pass each non-null result to ObjectNameComparison (0x00477280) with this; returns 0.
- `0x00479DB0` **ParameterizedRuntimeObject** — Constructor: base-init InitVTableSet(this, 0, 1.0f), install vtable off_5A5D88 at this+0x0, and zero the byte at this+0x104; returns this.
- `0x0047A000` **ParameterizedRuntimeObject** — Constructor: base-init InitVTableSet(this, 0, 1.0f), install vtable off_5A5EF8 at this+0x0, and zero the byte at this+0x104; returns this.
- `0x0047A190` **ParameterizedRuntimeObject** — Constructor: base-init InitVTableSet(this, 0, 1.0f), install vtable off_5A5FB0 at this+0x0, and zero the byte at this+0x104; returns this.
- `0x0047A210` **ParameterizedRuntimeObject** — Constructor: base-init InitVTableSet(this, 0, 1.0f), override vtable at this+0x0 to off_5A6068, and zero the byte at this+0x100; returns this.
- `0x0047A3A0` **ParameterizedRuntimeObject** — Constructor: base-init InitVTableSet(this, 0, 1.0f), override vtable at this+0x0 to off_5A6120, and zero the byte at this+0x104; returns this.
- `0x0047A580` **ParameterizedRuntimeObject** — Constructor: base-init InitVTableSet(this, 1036831949, 1065353216), then install vtable off_5A6290 at this+0x0; returns this.
- `0x0047A5E0` **ParameterizedRuntimeObject** — Constructor: base-init InitVTableSet(this, 1036831949, 1065353216), then install vtable off_5A6400 at this+0x0; returns this.
- `0x0047A640` **NameComparisonDispatch** — Dispatch selector 19 through ICommandDispatcher; if non-null, pass the result to ObjectNameComparison (0x00477280) with this; returns 0.
- `0x0047A8F0` **ParameterizedRuntimeObject** — Constructor: base-init InitVTableSet(this, 1028443341, 1065353216), then install vtable off_5A6628 at this+0x0; returns this.
- `0x0047B1B0` **DispatchSequenceObject** — Zero the dword at this+0x104, dispatch vtable slot 0x40 on this with argument 0 and vtable slot 0x2C with (this, 1), then return the result of vtable slot 0x9C on this.
- `0x0047BC30` **MenuCursorWidget** — Count wrapped text items up to the cursor: navigate from index 0 via MenuCursorNavigationHelper (0x0047B730) over the text at this+0xE0 (fallback global 0x005EA438) until the cursor limit at this+0xE4, the end delimiter (0xFF), or no-movement; returns the count.
- `0x0047BC90` **MenuCursorWidget** — Count reachable cursor positions over the text at this+0xE0 (fallback global 0x005EA438), advancing via MenuCursorNavigationHelper (0x0047B730) until no movement or the final terminator; returns the total count. Callers include 0x0047BAE0, 0x0047BCF0, 0x0047BD90 and 0x0047BE00.
- `0x0047BCF0` **MenuCursorWidget** — Adjust the scroll offset at this+0xEC so the cursor stays inside the visible window: query wrapped-line count via 0x0047BC30 and scrollable-item count via 0x0047BC90, shift or clamp this+0xEC using the visible limit at this+0xF0, then tail-call UtilityFunction_bd90 (address unevidenced in packet) and return its result.
- `0x0047BD90` **MenuCursorWidget** — Compute the scroll-bar thumb position at this+0x110 from scroll offset this+0xEC over track this+0x114 using the item count from 0x0047BC90 (integer rounding via +count/2); clamp this+0x110 into [0, this+0x114] and return the pre-clamp value.
- `0x0047BE90` **ManagedReleaseObject** — Invoke 0x00489440 on this, then release via 0x00587BCF when flag bit 0 of the second argument is set; returns this unchanged.
- `0x0047D060` **SessionContextVirtualEntry** — Call VehicleStatsEstimationDisplay (0x00430F00) with the global byte_7C56C0 buffer, then dispatch vtable slot 0xA4 on this and return its result.
- `0x0047E680` **NameComparisonDispatch** — Dispatch selectors 25 then 26 through ICommandDispatcher; pass each non-null result to ObjectNameComparison (0x00477280) with this; returns 0.
- `0x0047E940` **RuntimeObjectSystem** — Conditional passthrough: call StringCopyWithBufferRealloc(a1) when a1 is non-zero and return its result; when a1 is zero, return it unchanged. Called from 0x0047EE5C and 0x0047EF3C.

## Proposed classes

### DispatchCacheOwner

Methods that dispatch an integer selector through ICommandDispatcher (vtable slot 28 on dword_7CD8C0) and cache the returned object pointer at this+0xE0; all return 0. Each method dispatches a different selector; two (0x004780D0, 0x004781A0) select between two selectors based on session state. Grouping is a structural GUESS; the packet does not prove these six share one concrete type.

Methods: `0x00478090`, `0x004780D0`, `0x00478180`, `0x004781A0`, `0x00478200`, `0x004782A0`

- `this+0x000000E0` `void* cached_dispatch_result` (write, GUESS)

### SelectionStateMonitor

Methods that poll an external selection/state value through ICommandDispatcher (slot 28), compare it against the cached value at this+0xE8 and, when changed, update the cache and notify via this's vtable slot 44 with argument 1; both return 0. Field layout (only +0xE8) is shared, but common concrete ownership between the two is a GUESS.

Methods: `0x00478220`, `0x004782C0`

- `this+0x00000000` `void** vtable` (read, GUESS)
- `this+0x000000E8` `int cached_selection_state` (read_write, GUESS)

### ResourceStateMonitor

Monitors a resource referenced by the handle at this+0xE0: reads the resource state at resource+0x2C, compares against the cached value at this+0xE4 and, on change, updates the cache, calls ProfileIconPathSetter (0x00478390) and notifies via this's vtable slot 44 with argument 1; returns 0. The +0x254 read is evidenced but its role is unknown.

Methods: `0x00478350`

- `this+0x00000000` `void** vtable` (read, GUESS)
- `this+0x000000E0` `void* resource_handle` (read, GUESS)
- `this+0x000000E4` `int cached_resource_state` (read_write, GUESS)
- `this+0x00000254` `unknown unknown_read_0x254` (read, UNKNOWN)

### NameComparisonDispatch

Methods that dispatch one or two integer selectors through ICommandDispatcher (slot 28 on dword_7CD8C0) and pass each non-null returned object to ObjectNameComparison (0x00477280) with this; the comparison result is discarded and the methods return 0. No this-field access is evidenced, so no fields are declared.

Methods: `0x00479CA0`, `0x00479D00`, `0x0047A640`, `0x0047E680`


### MenuCursorWidget

Menu cursor/scroll widget: counts wrapped text items and reachable cursor positions over the text pointer at this+0xE0 (fallback global 0x005EA438) using MenuCursorNavigationHelper (0x0047B730), adjusts the scroll offset at this+0xEC within the visible window at this+0xF0, and computes the scroll-bar thumb position at this+0x110 over the track size at this+0x114. Common ownership is strongly evidenced: 0x0047BCF0 calls both 0x0047BC30 and 0x0047BC90 on the same this.

Methods: `0x0047BC30`, `0x0047BC90`, `0x0047BCF0`, `0x0047BD90`

- `this+0x000000E0` `const char** text_source` (read, GUESS)
- `this+0x000000E4` `int cursor_limit` (read, GUESS)
- `this+0x000000EC` `int scroll_offset` (read_write, GUESS)
- `this+0x000000F0` `int visible_item_count` (read, GUESS)
- `this+0x00000110` `int scrollbar_thumb_position` (write, GUESS)
- `this+0x00000114` `int scrollbar_track_size` (read, GUESS)

### ParameterizedRuntimeObject

Family of constructors that call a shared base initializer (InitVTableSet 0x004668E0 or VtableSetWithInitCall 0x00466980) with two scalar/float range arguments, install a distinct vtable global, and optionally clear an init/state byte or set an enable byte. Each method installs its own vtable (off_5A4FE0 through off_5A6628), so the concrete types are likely distinct classes; treating them as one family is a GUESS.

Methods: `0x004797C0`, `0x004797F0`, `0x00479880`, `0x004798E0`, `0x00479910`, `0x00479940`, `0x00479970`, `0x00479A10`, `0x00479DB0`, `0x0047A000`, `0x0047A190`, `0x0047A210`, `0x0047A3A0`, `0x0047A580`, `0x0047A5E0`, `0x0047A8F0`

- `this+0x00000000` `void** vtable` (write, DERIVED)
- `this+0x000000F0` `byte enable_flag` (write, GUESS)
- `this+0x00000100` `byte init_state_byte` (write, GUESS)
- `this+0x00000104` `byte init_state_byte_0x104` (write, GUESS)

### SubObjectSelector

Selects a sub-object pointer at this+0x118 based on a boolean flag at this+0x138, toggling vtable slot 0x3C on this with argument 1 or 0 and returning the sub-object pointer or null; 0x00478EC9 is a trivial getter of the same field. Common ownership between the two is a GUESS.

Methods: `0x00478690`, `0x00478EC9`

- `this+0x00000000` `void** vtable` (read, GUESS)
- `this+0x00000118` `void* sub_object_ptr` (read, GUESS)
- `this+0x00000138` `int enable_flag` (read, GUESS)

### DispatchSequenceObject

Entry that clears the dword at this+0x104, dispatches vtable slot 0x40 with argument 0 and vtable slot 0x2C with (this, 1), then returns the result of vtable slot 0x9C. All three dispatch targets are indirect and unresolved.

Methods: `0x0047B1B0`

- `this+0x00000000` `void** vtable` (read, GUESS)
- `this+0x00000104` `dword state_flag` (write, GUESS)

### ManagedReleaseObject

Member helper: invokes 0x00489440 on this, then releases via 0x00587BCF when flag bit 0 of the second argument is set; returns this unchanged. Receiver object and the two wrapper callees are unidentified.

Methods: `0x0047BE90`


### SessionContextVirtualEntry

Stateless __thiscall entry: calls VehicleStatsEstimationDisplay (0x00430F00) with the global byte_7C56C0 buffer as session context, then dispatches vtable slot 0xA4 on this and returns its result. Both the receiver object and the dispatched method are unidentified.

Methods: `0x0047D060`

- `this+0x00000000` `void** vtable` (read, GUESS)

## Compatibility contracts

- **command_dispatcher_global** — Global 0x007CD8C0 must remain a pointer to an object whose vtable slot 28 (offset 0x1C) accepts an integer selector and returns a nullable object pointer; thirteen functions in this subsystem dispatch through it with selectors 14-26.
- **session_state_selector** — Session state at global 0x007CD25C must remain readable via SessionStateCheck (0x00461CD0); state value 3 selects the in-game dispatch opcodes in 0x004780D0 (23) and 0x004781A0 (24).
- **widget_change_notification** — Runtime/UI objects in this subsystem must expose a vtable slot at offset 44 (0x2C) callable as (this, 1) to signal an externally observed state change; four functions (0x00478220, 0x004782C0, 0x00478350, 0x0047B1B0) rely on it.
- **menu_default_text_global** — Menu cursor widgets must fall back to the default text source at global 0x005EA438 when the text pointer field at this+0xE0 is null.

## Unresolved

- Identity of the object behind global dword_7CD8C0 and the semantics of its integer selectors (14, 15, 16, 17, 19, 20, 21, 22, 23, 24, 25, 26) are unresolved; only the vtable-slot-28 dispatch pattern is evidenced.
- All indirect dispatch targets (vtable slot 28 on dword_7CD8C0; slots 44/0x2C, 0x3C, 0x40, 0x9C, 0xA4 on this) are resolved to no static callee; every virtual call is open.
- In 0x00478220 the packet raw source reads the dispatch result at offset +0x174 while the packet field evidence labels the result-object field at obj+0x2C; the two mappings conflict and need deterministic reconciliation before use.
- The sixteen constructors each install a distinct vtable global (off_5A4FE0 through off_5A6628); whether they are sixteen distinct classes or variants of one family is unresolved, and the ParameterizedRuntimeObject grouping is a GUESS.
- The scalar/float range arguments forwarded to InitVTableSet (0x004668E0) and VtableSetWithInitCall (0x00466980) have semantics owned by those base initializers, outside this packet.
- Semantics of the +0x100 and +0x104 flag bytes (enabled vs init state) and of the +0x254 read in 0x00478350 are unknown.
- MenuCursorNavigationHelper (0x0047B730) boundary behavior decides whether the cursor/item counts include the final position; that logic is outside this packet.
- The UtilityFunction_bd90 tail-call target from 0x0047BCF0 is unevidenced (no callee address in the packet), and the callers of 0x0047BC30/0x0047BCF0 outside the menu path are unknown.
- 0x0047D060 pairs a VehicleStatsEstimationDisplay call (with global byte_7C56C0) with a vtable+0xA4 dispatch whose receiver and method are both unidentified.
- ObjectNameComparison (0x00477280) internals and why its result is discarded by NameComparisonDispatch are unresolved.
- StringCopyWithBufferRealloc has no address or callee entry in the packet; its location and exact semantics cannot be grounded here.
- 0x0047E940 is treated as a free function (no this, plain argument a1); its owner class, if any, is unknown.
