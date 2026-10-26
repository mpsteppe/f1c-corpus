# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Proposal for the generic_runtime_objects slice of Wave 4. The functions cluster into: a packed parameter-stream handler (0x4D1A50 decode, 0x4D22C0 record-update-and-dispatch) invoked from sub_4B3400; a driver/entry identity lookup (0x4D1B50) over the active-vehicle pointer array (dword_7C54F0, count dword_5C329C) with a 4656-byte-stride occupancy table; a steward-owned lazily allocated 8-byte sub-object (alloc 0x4D2DD0, release 0x4D2E20, comparison forwarder 0x4D1CD0) shared by PitTimer/Steward_Restart/Steward_Post; a ref-counted COM-like container release (0x4D4860); a debug/telemetry byte-stream writer family (0x4D5900 XOR-encoded record, 0x4D5960 debug-log init, 0x4D59B0 option-flag bitfield packer) all emitting through sub_4D5BE0; a float-pair ratio helper (0x4D5EA0); a struct-entry cleanup (0x4D6800); two table interpolators (cubic Hermite 0x4D6830, wrapped-range linear 0x4D7CF0 with element read 0x4D7C00); a vtable state-reset dispatch wrapper (0x4D7E30); the OnScreen/race-struct init-teardown family (0x4D8220 init, 0x4D8720 audio teardown, 0x4D8FB0 four-handle resource release); car-selection/iterator support (0x4D8860 flag dispatch, 0x4D8880 validated index setter, 0x4D88B0 iterator advance); small value helpers (0x4D91E0 ID-to-value mapper, 0x4D9280 return-0 stub); the starting-grid marker renderer (0x4D95D0); the race-finish session state machine (0x4DA840); texture/UI render objects (0x4DC600 surface-size query, 0x4DC660 scaled texture render); and render-path dispatchers (0x4DCD60 guarded device dispatch, 0x4DCD80 two-field setter update). Ownership is largely UNKNOWN at the function-IR level, so most classes are GUESS proposals, not confirmed identities.

## Function roles

- `0x004D1A50` **ParameterStreamHandler** — Decodes a packed parameter-update stream: a header DWORD masked with 0xFC0000 equal to 2621440 triggers a reset pass clearing every 8-byte entry of the state array (count this+0x10C, base this+0x110) via ShortComputation_0f00(entry, 0); a non-zero update count ((*a2 >> 9) & 0x1FF) then decodes packed 16-bit update words (index = word >> 6, value = word & 0x3F) and applies each via ShortComputation_0f00(base + 8*index, value). Returns the last ShortComputation result, the entry count when only the reset ran, or the masked header value when neither branch executed.
- `0x004D1B50` **DriverEntryLookup** — Resolves a driver ID for an entry index: reads the byte-slot table at this+296; a 255 marker or an occupied vehicle slot (dword_5EF9A0, 4656-byte stride, entry != -1) short-circuits to the default player value or the table byte; otherwise scans active-vehicle pointers dword_7C54F0[0..dword_5C329C) for an object whose +16480 field equals a2+2 and returns its +16440 field, falling back to *(dword_7C54F0[0]+16).
- `0x004D1CD0` **StewardSessionObject** — Forwarding wrapper over a comparison helper: computes a pointer 55 dwords past this, forces argument a2 to zero when global dword_8AB6E4 equals 2, and tail-delegates to the comparison helper with the adjusted arguments, returning its result.
- `0x004D22C0` **ParameterStreamHandler** — Field-update then dispatch: unconditionally zeroes the byte flag at this+0xC1, stores the float read from global dbl_8AFEA0 into this+0xB0, copies the dword at source a2+12 into this+0xB4, then calls sub_42D140(&dword_7C569C, dword at a2+8) and returns its result.
- `0x004D2DD0` **StewardSessionObject** — Lazily allocates and zero-initializes an 8-byte sub-structure: when this+0xA4 is null, allocates 8 bytes via OperatorNewNhMallocWrapper (0x587C03), zero-initializes via ZeroInitSubCall (0x4D0060), stores the pointer at this+0xA4, and passes it to a follow-up init sub-call (address absent from callee evidence); on allocation failure stores 0. Subsequent calls return the cached pointer.
- `0x004D2E20` **StewardSessionObject** — Teardown-and-release twin of the lazy allocator: when the pointer at this+0xA4 is non-null, passes it to sub_4D0080 (teardown/destructor step), frees it via FreeWrapper_7bcf (0x587BCF), and clears the slot back to 0; returns the free result (or the uninitialized result variable when the slot was already null).
- `0x004D4860` **RefCountedContainer** — Decrements a COM-like container reference count (this+0x8); when it reaches zero, invokes destructor callback off_5D43C8 on the inner object at this+0x4, frees the secondary resource at this+0xC via FreeWrapper_7bcf, and clears both pointers. Sets the vtable pointer at this+0x0 to off_5ACF08 on entry.
- `0x004D5900` **DebugDataWriter** — Encodes and writes a small event record to a byte stream: maps a type selector (0->3, 1->1, 2->2, else 0xFF) to a 1-byte tag written via sub_4D5BE0, then XORs the 4-byte payload with the key at this+0x8 and writes the result via sub_4D5BE0. Called by LapSplitTimeEvent to encode split-event data.
- `0x004D5960` **DebugDataWriter** — Initializes the debug logging subsystem: writes a single null byte via sub_4D5BE0, conditionally sets two global debug-mode constants when the runtime check dword_5C753C() is non-zero, processes a double constant via sub_447F30 into a local float array, stores the first element into this[2] (offset +0x8), writes the 228-byte array via sub_4D5BE0, and returns its result. Called from MainGameTickUpdate.
- `0x004D59B0` **DebugDataWriter** — Packs eleven per-car option flags from byte_7C749A into a bitfield at two bits per flag (forcing index 5 to 1 when dword_7CEA5C is zero), appends dword_7CE6D0, dword_7CE958, a conditional bit from player vehicle object dword_7C54E8 + field offset 4180, and byte_7CE88C / byte_7CE874, then writes the header byte 4, the packed dword, and five float physics values (two with a 273.16 Celsius-to-Kelvin offset) through sub_4D5BE0.
- `0x004D5EA0` **FloatPairRatio** — Computes the ratio (a2 - 1.0) / divisor for a two-float result pair: clamps a non-positive divisor (a3 <= 0.0) to FLT_MAX (3.4028235e38), stores the effective divisor at this+0x04 and the ratio at this+0x00. Called per-frame by sub_4F18C0.
- `0x004D6800` **StructEntryRecord** — Cleans up a struct entry: reinitializes the global string buffer byte_5EA438 via StringCopyWithBufferRealloc, zeros the dwords at this+0x8 / this+0xC / this+0x10, then conditionally frees the heap buffer at this+0x14 via FreeWrapper_7bcf and zeroes it. Returns the result of the conditional free. Called by ArrayBlockCleanup for per-entry teardown.
- `0x004D6830` **CubicHermiteTable** — 1D cubic Hermite interpolation over a 32-byte-stride coefficient table: computes the normalized parameter (a3/a2) * *(double*)(this+8), derives an integer index, clamps it to the entry count at this+16 (minus one), and evaluates ((c3*t+c2)*t+c1)*t+c0 from four double coefficients per entry at the table pointer this+20. Called by CollisionContactGenerationAndFrictionResponse and TireCompoundPerWheelPhysicsApplication on the per-frame physics path.
- `0x004D7C00` **RangeLookupTable** — Trivial offset-indexed dword read: returns the array element this[a2 + 3] (a dword 12 bytes beyond the a2-selected element). No guards, globals, fields or callees. Called by ScoringGateSelector on the frame path; the LEGACY ABI lead names the 0xC displacement with element index 4.
- `0x004D7CF0` **RangeLookupTable** — Wraps float a2 into [0, this[9]) (the wrap period stored at field offset 0x24), locates the containing segment via FloatRangeIndexLookup (0x4D7C10), computes the linear interpolation factor (a2 - this[v6+6]) / (this[v6+9] - this[v6+6]), and optionally writes the segment index to *a3.
- `0x004D7E30` **VTableStateResetter** — State-reset virtual dispatch wrapper: reads the vtable pointer from this+0x0, clears the state/flag dword at this+0xC, dispatches the function pointer at vtable+0x10 (4th slot) with no arguments, and returns its result. No guards; always clears then dispatches.
- `0x004D8220` **OnScreenRaceController** — Unconditional race-struct initialization: calls the general struct utility (0x4D8720), stores two normalized values (this[57] = dword_5D6D60 * 0.00078125001 at offset 0xE4, this[58] = dword_5D6D64 * 0.0009765625 at offset 0xE8), runs the sub-component init (0x4D8AB0), five per-index batch inits (0x4D8CF0 for indices 1..5), an audio/timer init (0x4D88D0), and returns the result of the finalization step sub_4D8760(-1, 0). No branches; called only from OnScreen_Init (0049efa0).
- `0x004D8720` **OnScreenRaceController** — Teardown helper on the race/session path: calls sub_4D8FB0 (pre-reset), releases audio resources for types 1 through 5 via AudioResourceReleaseByType (0x4D9030), and returns the result of a thiscall dispatch/cleanup on this (callee address absent from packet evidence).
- `0x004D8860` **CarSelectionSupport** — Flag dispatcher on the frame path (per-frame tick): when a2 (the flag) is non-zero, returns IndexValidationSetter(0); when a2 is zero, resets this[2] (dword field at byte offset 0x8) to -1 and returns 0.
- `0x004D8880` **CarSelectionSupport** — Validated selection-index setter on this: a2 == -1 unconditionally clears this[2] (offset 0x8) to -1; otherwise the index is stored into this[2] only when the entry flag this[a2+3] is non-zero and the enable gate global dword_7CF788 is non-zero. Always returns the original a2.
- `0x004D88B0` **CarSelectionSupport** — Advances a sequential iterator: reads the current index from this[0]; if not -1, resolves the entry object at this[this[0]+4] and calls its vtable slot +0x14 (offset 20) advance/done-check method; when that returns 1 the index is reset to -1 (iteration complete). Returns the advance result, or the raw -1 sentinel when no iteration is active.
- `0x004D8FB0` **OnScreenRaceController** — Releases up to four global resource handles: dword_8AD388, dword_8AD38C and dword_8AD390 are each independently guarded, released via StringCompareLinkedListSearch (0x53D130), and nulled; dword_8AD394 is pre-read, then released and nulled when non-null. Returns the last release result (or the pre-read dword_8AD394 value when it was null).
- `0x004D91E0` **IDValueMapper** — Pure integer ID-to-value lookup via a switch dispatch (jump table at 0x4D921C): 0 -> 100, {1,3,4,5,6,9,10,11,12,14,15,16,18,20,21,22,23,24} -> 50, {2,13} -> 49, {7,8,19} -> 51, 17 -> 52, and 0 for any other value. No side effects.
- `0x004D9280` **ZeroReturnStub** — Constant-return stub: always returns char 0 and ignores its single integer parameter. No guards, globals, fields or callees. Invoked by sub_4D8760; the LEGACY ABI lead names it a return-0 stub.
- `0x004D95D0` **StartingGridUI** — Scans the live vehicle pointer array (dword_7C54F0, count dword_5C329C) for up to two vehicle ids (a1 primary, a2 secondary) each read from vehicle+16480; draws a primary marker via sub_4D9690 at (a3, a4+160.0) and a secondary marker at (a3+64.0, a4-32.0). Returns 0 on every exit path. Called from StartingGridUIDraw (004d9420), consistent with a starting-grid position-marker renderer.
- `0x004DA840` **RaceFinishStateHandler** — Race-finish state machine tick on this+0x10: state 0 (init) resolves the player slot via DriverIDLookup (sub_4D1B50(dword_8ACEE0, 0)) and primes a 2.0 countdown timer at this+0x18; state 1 holds until the timer expires then moves to state 2; state 2 lazily caches the finished lap (this+0x24 from dword_5F0714[slot]), runs the finish helpers sub_4DAD80 / sub_4DA990 / sub_4DAE00, and when the player's finish-state cell dword_5F073C[slot] is exactly 1 and the player vehicle is present, transitions the session to results via SessionStateTransition (0x4EF5A0), GameActionStateMachine (0x40CDE0), GameStateDispatchChain (0x40D240) and sub_4D8760(&dword_8AD298, 17, 0), returning 0; otherwise returns 1.
- `0x004DC600` **TextureRenderObject** — Looks up a wide-string key in a linked list via WideStringLinkedListSearch (0x53D1F0) and, when found, writes surface dimensions into a3/a4 scaled by per-entry factors (v8+92, v8+96) and caller-supplied float factors a5/a6 via CRTFtol (0x587BDC); outputs are zeroed when the key is not found. Callers: TextRenderDispatcher (0x4DD030) and TwoOutputPassthrough (0x4DD3A0).
- `0x004DC660` **TextureRenderObject** — Renders a scaled texture: looks up the texture object by name via WideStringLinkedListSearch (0x53D1F0), temporarily scales its stored factors at +92/+96 by the incoming parameters, sets a field at offset 0x48 via FieldSetterAt0x48, computes an aligned screen position from the target object's alignment dimensions, renders through sub_553070 with the resolved device (a9 or the fallback dword_8B8DC8), then restores the original scale factors and color value.
- `0x004DCB70` **TenFieldStateObject** — Constructor/initializer on an unknown __thiscall object: zero-fills the first eight dwords (offsets 0x0 through 0x1C), writes 1065353216 (single-precision 1.0) into offsets 0x20 and 0x24, and returns 1065353216. No reads and no globals.
- `0x004DCD60` **RenderPathDispatcher** — Guard-enabled dispatch: when this[0] (offset 0x0) is non-null, resolves a dispatch pointer from argument a2 (substituting the global dword_8B8DC8 when a2 is null) and calls sub_553700 with it. No-op when this[0] is null. Callers are render-path functions (0x45B660, 0x49B370, 0x49F070).
- `0x004DCD80` **RenderPathDispatcher** — Sets two dword fields at this+0x14 and this+0x18 from a2 and a3, then calls sub_4DCA80(this) (per the skeleton, the four-corner rectangle render using the updated fields) and returns its result. Unconditional __thiscall used as an update entry point by callers that re-render after changing position/size fields.

## Proposed classes

### ParameterStreamHandler

Object behind the sub_4B3400 invocation that consumes a packed parameter-update stream. Holds a state array (count this+0x10C, base this+0x110, 8 bytes per entry) cleared and updated through ShortComputation_0f00, and a record-update path that stamps session time and a source dword then dispatches through sub_42D140. The two methods touch different field ranges, so the object identity is a GUESS.

Methods: `0x004D1A50`, `0x004D22C0`

- `this+0x0000010C` `int state_entry_count` (read, GUESS)
- `this+0x00000110` `pointer state_entry_base` (read, GUESS)
- `this+0x000000B0` `float session_time` (write, GUESS)
- `this+0x000000B4` `int source_dword` (write, GUESS)
- `this+0x000000C1` `byte flag_byte` (write, GUESS)

### DriverEntryLookup

Resolves an entry/grid index to a driver ID. Reads a byte-slot table on the owning object and the active-vehicle pointer array (dword_7C54F0, count dword_5C329C), using the 4656-byte-stride occupancy table dword_5EF9A0 and the player default *(dword_7C54F0[0]+16). The table field at this+296 has no packet field evidence and the +16440/+16480 vehicle-field roles are unknown.

Methods: `0x004D1B50`


### StewardSessionObject

Object owned by the Steward/PitTimer session-lifecycle cluster. Holds a lazily allocated 8-byte sub-structure at this+0xA4 (alloc+zero-init in 0x4D2DD0, teardown+free in 0x4D2E20) and a conditional comparison forwarder gated on dword_8AB6E4 == 2. Boundaries between the comparison path and the sub-object slot are not proven.

Methods: `0x004D1CD0`, `0x004D2DD0`, `0x004D2E20`

- `this+0x000000A4` `pointer sub_object_ptr` (read_write, GUESS)

### RefCountedContainer

COM-like reference-counted container. Layout: vtable at this+0x0 (set to off_5ACF08 on release), inner object pointer at this+0x4, reference count at this+0x8, secondary resource pointer at this+0xC. On last release it runs the destructor callback off_5D43C8, frees the secondary resource and clears both pointers. Element-type and ownership semantics depend on the unseen constructor.

Methods: `0x004D4860`

- `this+0x00000000` `pointer vtable` (write, GUESS)
- `this+0x00000004` `pointer inner_object` (read_write, GUESS)
- `this+0x00000008` `int ref_count` (read_write, GUESS)
- `this+0x0000000C` `pointer secondary_resource` (read_write, GUESS)

### DebugDataWriter

Debug/telemetry byte-stream encoder family. All three methods emit records through the shared sub_4D5BE0 writer: an XOR-encoded event record keyed by the dword at this+0x8, a debug-log initialization that also stores a processed element into this+0x8, and an option-flag bitfield packer reading global per-car option state. The this+0x8 dword is used as both an XOR key and a store slot across methods; equal offsets on the same this are GUESS-only evidence of a shared field.

Methods: `0x004D5900`, `0x004D5960`, `0x004D59B0`

- `this+0x00000008` `int state_dword` (read_write, GUESS)

### FloatPairRatio

Small two-float out-struct helper: stores the (possibly clamped) divisor at this+0x04 and the ratio (a2 - 1.0) / divisor at this+0x00. Likely a scratch output struct, not a real class.

Methods: `0x004D5EA0`

- `this+0x00000000` `float ratio` (write, GUESS)
- `this+0x00000004` `float clamped_divisor` (write, GUESS)

### StructEntryRecord

Per-entry struct with three zeroed dwords (this+0x8/0xC/0x10) and an owned heap buffer at this+0x14. Cleanup reinitializes the global string buffer byte_5EA438, zeros the three dwords, then frees and nulls the heap buffer. The struct identity and the buffer meaning are unknown; only caller is ArrayBlockCleanup.

Methods: `0x004D6800`

- `this+0x00000008` `int field_a` (write, GUESS)
- `this+0x0000000C` `int field_b` (write, GUESS)
- `this+0x00000010` `int field_c` (write, GUESS)
- `this+0x00000014` `pointer heap_buffer` (read_write, GUESS)

### CubicHermiteTable

1D cubic Hermite interpolator over a 32-byte-stride table of double coefficients. Layout: double scale factor at this+0x8, entry count at this+0x10, table base pointer at this+0x14. Used by the collision and tire physics paths per-frame; coefficient ordering and owning object are unconfirmed.

Methods: `0x004D6830`

- `this+0x00000008` `double scale_factor` (read, GUESS)
- `this+0x00000010` `int entry_count` (read, GUESS)
- `this+0x00000014` `pointer coefficient_table` (read, GUESS)

### RangeLookupTable

Wrapped-range lookup/interpolation object. Wraps an input into [0, period-at-0x24), locates the containing segment via FloatRangeIndexLookup and computes a linear factor; a sibling element accessor returns this[a2+3]. The element-reader and wrap-interpolator are grouped by address proximity and table domain; common ownership is not proven.

Methods: `0x004D7C00`, `0x004D7CF0`

- `this+0x00000024` `float wrap_period` (read, GUESS)

### VTableStateResetter

Shared state-reset virtual dispatch wrapper. Reads the vtable at this+0x0, clears the state/flag dword at this+0xC, and dispatches vtable slot +0x10 with no arguments. The cleared field is recalculated every frame per prior analysis, so the clear is a state-reset signal rather than a persistent value; the slot target is unknown.

Methods: `0x004D7E30`

- `this+0x00000000` `pointer vtable` (read, GUESS)
- `this+0x0000000C` `int state_flag` (write, GUESS)
- `obj+0x00000010` `pointer vtable_slot_4` (read, GUESS)

### OnScreenRaceController

Race/OnScreen struct init-teardown controller. Init (0x4D8220) runs the general utility, stores two normalized screen-dimension values (offsets 0xE4/0xE8), and calls the sub-component inits (0x4D8AB0, per-index 0x4D8CF0, audio/timer 0x4D88D0) plus the 0x4D8760 finalizer; teardown (0x4D8720) releases audio resource types 1..5 and the four global handles (0x4D8FB0). Normalized-dimension semantics and the sub-component boundaries are DERIVED at best.

Methods: `0x004D8220`, `0x004D8720`, `0x004D8FB0`

- `this+0x000000E4` `float normalized_dim_a` (write, GUESS)
- `this+0x000000E8` `float normalized_dim_b` (write, GUESS)

### CarSelectionSupport

Support functions for the car-selection state machine (caller 0x434460). Holds a selection index at this[2] (offset 0x8) gated by the entry-flag array this[a2+3] and the enable global dword_7CF788, a flag dispatch (0x4D8860) that resets the selection to -1 or delegates to the setter, and a sequential iterator (0x4D88B0) over entry objects that resets to -1 when the entry's vtable slot +0x14 reports completion.

Methods: `0x004D8860`, `0x004D8880`, `0x004D88B0`

- `this+0x00000000` `int iterator_index` (read_write, GUESS)
- `this+0x00000008` `int selection_index` (read_write, GUESS)

### IDValueMapper

Pure ID-to-value lookup table dispatching through the read-only jump table at 0x4D921C. The meaning of the input ID and the returned values (49/50/51/52/100) is caller-dependent and unknown here.

Methods: `0x004D91E0`


### ZeroReturnStub

Trivial constant-return stub: returns 0 and ignores its parameter. Invoked by sub_4D8760; whether the 0 means success, failure or a boolean false depends on the unknown caller contract.

Methods: `0x004D9280`


### StartingGridUI

Starting-grid position-marker renderer. Scans the active-vehicle pointer array for up to two vehicle ids (read from vehicle+16480) and draws primary/secondary markers via sub_4D9690 at fixed screen offsets. The +16480 id field meaning (car id vs driver id) is not established.

Methods: `0x004D95D0`


### RaceFinishStateHandler

Race-finish session state machine tick. Holds the state dword at this+0x10, a primary countdown timer at this+0x18, a secondary timer at this+0x1C, a finish-calc result at this+0x20, and a lazily cached finished-lap value at this+0x24. On the finish transition it drives the session to results via SessionStateTransition, GameActionStateMachine and GameStateDispatchChain. The legacy ABI name 'Pit_Grid_Position_State_Machine' conflicts with the race-finish reading.

Methods: `0x004DA840`

- `this+0x00000010` `int state` (read_write, GUESS)
- `this+0x00000018` `float primary_timer` (read_write, GUESS)
- `this+0x0000001C` `float secondary_timer` (write, GUESS)
- `this+0x00000020` `int finish_result` (write, GUESS)
- `this+0x00000024` `int cached_finished_lap` (read_write, GUESS)

### TextureRenderObject

Texture/UI render objects that look up string-keyed texture objects through the wide-string linked list (0x53D1F0), query per-node scale factors (+92/+96) and base surface dimensions, and render through the device (0x553070). Includes a surface-size query and a scaled-texture renderer that temporarily mutates and restores the texture node's scale/color fields.

Methods: `0x004DC600`, `0x004DC660`


### TenFieldStateObject

Ten-dword state object initialized by a write-only constructor: eight zeroed dwords (0x0..0x1C) and two fields initialized to single-precision 1.0 at 0x20 and 0x24. The purpose of the fields and the returned 1065353216 are unknown; the return is likely a decompiler artifact of the last write.

Methods: `0x004DCB70`

- `this+0x00000000` `int dword_0` (write, GUESS)
- `this+0x00000004` `int dword_1` (write, GUESS)
- `this+0x00000008` `int dword_2` (write, GUESS)
- `this+0x0000000C` `int dword_3` (write, GUESS)
- `this+0x00000010` `int dword_4` (write, GUESS)
- `this+0x00000014` `int dword_5` (write, GUESS)
- `this+0x00000018` `int dword_6` (write, GUESS)
- `this+0x0000001C` `int dword_7` (write, GUESS)
- `this+0x00000020` `float one_point_0_a` (write, GUESS)
- `this+0x00000024` `float one_point_0_b` (write, GUESS)

### RenderPathDispatcher

Render-path dispatch helpers: a guard-enabled dispatcher (0x4DCD60) that forwards a device pointer (or the dword_8B8DC8 fallback) to sub_553700 when this[0] is set, and a two-field setter (0x4DCD80) that writes this+0x14 / this+0x18 and triggers the four-corner rectangle render (0x4DCA80). Grouped by shared render-path callers (0x49B370, 0x49F070) and adjacent addresses; common ownership is not proven.

Methods: `0x004DCD60`, `0x004DCD80`

- `this+0x00000000` `pointer enable_ptr` (read, GUESS)
- `this+0x00000014` `int field_a` (write, GUESS)
- `this+0x00000018` `int field_b` (write, GUESS)

## Compatibility contracts

- **ParameterStreamWireFormat** — Packed parameter-update stream: the header DWORD masked with 0xFC0000 equal to 2621440 is a reset command that clears every 8-byte state entry (count at this+0x10C, base at this+0x110) to zero; otherwise a count ((*a2 >> 9) & 0x1FF) of 16-bit update words follows at a2+2, each decoding as index = word >> 6 and value = word & 0x3F applied to base + 8*index. A replacement decoder must reproduce this bit-level encoding.
- **DebugTelemetryStreamFormat** — Records emitted through sub_4D5BE0(data, size): an XOR-encoded event record (1-byte type tag from the 0->3, 1->1, 2->2, else 0xFF map, then a 4-byte payload XORed with the key at this+0x8); a debug-log header null byte followed by a 228-byte processed array; and an option telemetry record starting with header byte 4, an 11-flag two-bit bitfield with two appended option dwords and two appended bits, then five floats, two of which carry a 273.16 Celsius-to-Kelvin offset.
- **ActiveVehicleGridContract** — The live vehicle grid is addressed through dword_7C54F0 (active-vehicle pointer array, valid indices [0, dword_5C329C)); each vehicle carries an id dword at +16480 and a driver/entry dword at +16440; dword_5EF9A0 is an occupancy table indexed by a 4656-byte vehicle stride (entry != -1 means the slot is occupied). DriverIDLookup's fallback player value is *(dword_7C54F0[0]+16).
- **VehicleFinishStateTablesContract** — Race-finish bookkeeping uses per-slot arrays indexed by the 4656-byte vehicle stride: dword_5F073C holds the finish-state cell (== 1 means finished) and dword_5F0714 holds the finished-lap table; the player slot resolves through DriverIDLookup(dword_8ACEE0, 0). The player vehicle object is dword_7C54E8, with a presence flag at +16484 and an option bit at field offset 4180 (0x1054).
- **SessionStateTransitionContract** — On race-finish the session is moved to results through SessionStateTransition (0x4EF5A0) applied to dword_7C54E8+12 with (1, 0), then GameActionStateMachine(&dword_5EA510, 5, 1) and GameStateDispatchChain(&dword_5EA510, driverId), then sub_4D8760(&dword_8AD298, 17, 0). Global dword_7C569C (session type, 5 = server per existing_analysis, DERIVED) is passed by address from the record-dispatch path.
- **DriverIDLookupSemanticsContract** — DriverIDLookup(index) resolves an entry index to a driver ID: a byte table byte of 255 (empty marker) yields the default player value; an occupied vehicle slot (dword_5EF9A0[slot] != -1) yields the table byte directly; otherwise the active-vehicle array is scanned for an object whose +16480 field equals index+2 and its +16440 field is returned.

## Unresolved

- Owners of most functions are UNKNOWN at the function-IR level; the class grouping above is a GUESS/DERIVED proposal, not a confirmed identity.
- The comparison helper delegated by 0x4D1CD0 (named ArithmeticComparison_0ec0 in the raw source) has no callee evidence reference in the packet; its address and contract are unresolved. The dword_8AB6E4 == 2 suppression semantics are unknown.
- 0x4D22C0 dispatches to sub_42D140, absent from the packet callee list; the dbl_8AFEA0 (session time) and dword_7C569C (SessionType) labels are DERIVED from existing_analysis and not confirmable from this packet.
- The reset-command encoding of the 2621440 header marker (mask 0xFC0000) in 0x4D1A50 is taken from existing_analysis; the update loop's WORD cursor v7 = (v8 + 2) over an uninitialized register is a Hex-Rays artifact of a 2-byte pointer increment.
- The follow-up initialization sub-call in 0x4D2DD0's first-call path is absent from the callee evidence; the 8-byte sub-structure's purpose and type are DERIVED from Steward_Restart context only.
- sub_4D0080's exact role in 0x4D2E20 (teardown vs destructor) is unresolvable from this packet; the uninitialized result path when this+0xA4 is already null mirrors the twin's decompiler shape.
- The indirect destructor callback off_5D43C8 in 0x4D4860 resolves to the packet-listed callee candidates 0x4D4780/0x4D4790 only through the indirect call; off_5D43C4 is read in the surrounding object but not referenced in this function body. Element-type and ownership semantics depend on the unseen constructor.
- The destination stream of sub_4D5BE0 (the output buffer or object it writes into) is not resolved; the origin and lifetime of the XOR key at this+0x8 in 0x4D5900 are not established. In 0x4D5960 the this+0x8 slot receives the first processed array element, so equal offsets are only GUESS evidence of a shared field.
- dword_5C753C in 0x4D5960 is referenced as a function call in the raw source but is absent from the packet callee list; globals dword_7C8314, dword_7C8310 and dbl_7C7428 appear in the raw source but are absent from the packet globals; the literals 1072168960 and 0 in the debug-mode branch are unexplained.
- The per-option 2-bit flag codes packed by 0x4D59B0 are not derivable from this function alone; the player-vehicle field at dword_7C54E8 + 4180 is read but its meaning is unknown. flt_5ACAFC is packet-listed as a global but never read in the raw source.
- Read-only globals flt_59E43C, flt_59E440 and flt_59EAE0 are flagged by the packet facts for 0x4D5EA0 but none appears in the raw decompiled source (which uses the FLT_MAX literal directly); the owning object and the meaning of the 1.0 offset in the numerator are unknown.
- The role of the global string buffer byte_5EA438 in the 0x4D6800 cleanup path is not evidenced; the struct identity behind this+0x8..0x14 is unknown.
- sub_5895A2 in 0x4D6830 has no confirmed purpose (a double-to-float narrowing is suggested); the denominator a2 has no zero guard; the coefficient ordering (c0..c3) is unconfirmed.
- The 3-element (0xC displacement) offset selected by 0x4D7C00 depends on the unknown owning object's layout; the owner class is unidentified.
- flt_59E440 is packet-listed as a referenced global for 0x4D7CF0 but does not appear in the raw decompilation; the segment-boundary layout (this[v6+6], this[v6+9]) is inferred from the interpolation arithmetic.
- The owner class and the semantics of the cleared field at this+0xC in 0x4D7E30 are unknown (prior analysis notes it is recalculated every frame, so external pokes do not persist); the target of vtable slot +0x10 is unknown, and the '4th vtable entry / state reset' interpretation is DERIVED.
- The scaled values at offsets 0xE4/0xE8 in 0x4D8220 (normalized screen dimensions, DERIVED; 0.00078125001 ~ 1/1280, 0.0009765625 ~ 1/1024) are not proven; globals flt_5ACF38 and flt_5ACF3C are packet-listed but absent from the decompiled text; the sub_4D8760(-1, 0) argument semantics are unknown.
- The final thiscall dispatch/cleanup target in 0x4D8720 is absent from the callee evidence; the purpose of sub_4D8FB0 and the exact audio resource type meaning (1..5) are not established.
- IndexValidationSetter's address in 0x4D8860 is absent from the packet's callee list, so its behavior and return value are not verifiable from this packet.
- The entry-flag array this[a2+3] in 0x4D8880 and the identity/lifecycle of the enable gate dword_7CF788 are unknown.
- The vtable slot +0x14 method and entry-object type behind this[this[0]+4] in 0x4D88B0 are unknown; the relationship between this[0] and the this[0]+4 element index is inferred from the raw source; the only known caller is CarSelectionStateMachine (0x434460).
- global:0x008AFE64 (dword_8AFE64) is packet-listed as a read-only global for 0x4D8FB0 but never appears in the raw source; StringCompareLinkedListSearch-as-resource-release is a DERIVED reading; the resource type behind the four handles is not established from this packet alone.
- The semantic meaning of the input ID and the returned values (49/50/51/52/100) of 0x4D91E0 is caller-dependent and unknown here.
- Whether the constant 0 returned by 0x4D9280 means success, failure or a boolean false depends on the unknown sub_4D8760 caller contract.
- The vehicle-id dword at +16480 read by 0x4D95D0 is not established (car id vs driver id); globals flt_59E708, flt_59EC20 and flt_5ACF68 are packet-listed but absent from the raw source; if multiple vehicles shared the secondary id each would be drawn, and whether duplicate ids occur is unknown.
- The legacy ABI name 'Pit_Grid_Position_State_Machine' for 0x4DA840 conflicts with the race-finish reading of the control flow; the identities of dword_5F073C / dword_5F0714 / dword_7C54E8 fields and the 4656-byte stride are from the corpus facts / existing analysis (DERIVED) and not independently proven here; flt_59E440 is cited as the zero threshold but its value is not shown in the packet.
- The per-node scale factors at v8+92 / v8+96 in 0x4DC600 and 0x4DC660 have no field evidence; the restored field at +72 in 0x4DC660 (called a color value in prior analysis) is not proven; the sub_5531F0 fourth argument 0 is unexplained; dword_8AFE64 is packet-listed for 0x4DC660 but absent from the raw source.
- The object type behind 0x4DCB70 is unidentified; the write-only pattern is consistent with a constructor/initializer but no owner identity is evidenced; the returned 1065353216 may be a decompiler artifact of the last write.
- sub_553700 in 0x4DCD60 is absent from the packet's static callee list; the semantics of this[0] and dword_8B8DC8 (device pointer) are DERIVED from usage; the render callers are 0x45B660, 0x49B370, 0x49F070.
- The object type in 0x4DCD80 is unknown; the semantics of +0x14 and +0x18 (position, size or other per-render fields) depend on the calling context.
- The DriverIDLookup byte-slot table at this+296 (0x128) has no packet field evidence and the +16440/+16480 vehicle-field roles are unknown.
- Equal offsets on different 'this' objects across this packet (for example this+0x8 as XOR key, store slot, ref count and iterator/selection index) are not proof that the fields or classes are identical; each is labeled GUESS.
