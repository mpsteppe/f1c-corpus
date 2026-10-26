# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Twenty-eight generic runtime objects and helpers. ServerCloseTrackSignal (0x00461020) encodes a progress-bar event, dispatches a network message through the +0x3FB8 interface, clears the session open flag at +0x29 and appends a debug-log node to the list at +0x1B770..+0x1B77C gated on logging global 0x007D0398; DispatchServerTrackSignal (0x00463760) gates that dispatch on a state check. NetworkReplayBufferInit (0x0045D260) seeds a replay buffer control object with the session port, XOR-decodes an obfuscation key and allocates a network memory object. A COM-style transport interface at obj+0x3FB8 is shared across 0x0045E570, 0x00461020, 0x00462760, 0x00462A00 and 0x00463140 (GUESS). PositionUpdateWithHeadingAndVelocity (0x00466350) and SteeringOrRotationUpdate (0x00466650) are per-frame position/heading updates sharing a field layout (+0x40 sub-object, +0x104/+0x108 saved position, flag +0xF4, closing vtable+44 call) and are grouped as CameraYawZoomController (GUESS). InitDefaults (0x00461560) and BitFlagTestAt0x6E (0x004615F0) share the +0x6E byte region and are grouped as ScenarioValidationBuffer. HTMLResultsStatsPageWorldChampionships (0x00468910) rebuilds a stat-entry linked list (node data+0/next+4), FTIMTimerBitmapSelector (0x0046B5F0) builds an FTIM overlay string, SessionStateHandler (0x0046DC60) and MultiplayerPasswordValidation (0x0046DD30) share a UI factory at +0x40 (vtable+0x1C). The remaining functions are isolated flag/pointer/list helpers. All packet owners are UnknownObject; every class here is DERIVED/GUESS synthesis.

## Function roles

- `0x0045CE30` **AppendDelimitedSegments** — String assembly helper (__fastcall)
- `0x0045D240` **ResetFlagWithCleanup** — Conditional cleanup on a single-byte flag: if the byte at this+0 is nonzero, calls SingleFunctionCallWrapper_1f60(0) and SocketCloseAndCleanup(0), then clears the flag to 0
- `0x0045D260` **NetworkReplayBufferInit** — Initializer for a replay/network buffer-control object
- `0x0045E570` **ConditionalAnimationTimingUpdate** — Reads the byte flag at this+0x20
- `0x0045E590` **BufferFillWith0xFFFFFFFF** — Buffer initializer (__thiscall): fills a 0x1A0-byte region at this+468 with 0xFF bytes (i
- `0x00461020` **ServerCloseTrackSignal** — Sends the network "closing track" signal for the server session: encodes a progress-bar event, allocates and flags a network message object, dispatches it, clears the session open flag at this+0x29, builds a log-string node, and either appends it to the debug-log linked list at this+0x1B770
- `0x004614F0` **SetOrClearBitsAt0x88** — Sets or clears bits in a byte bitfield at this+0x88 based on a boolean control argument
- `0x00461560` **InitDefaults** — Constructor/initializer: writes fixed literal defaults into 22 byte-aligned fields of a small object without reading any existing state
- `0x004615F0` **BitFlagTestAt0x6E** — __thiscall getter: returns whether bit a2 of the byte field at this[110] (offset 0x6E) is set
- `0x00462160` **NetworkFilterSort** — Server-list sort/filter entry point
- `0x00462370` **DriverCountRead** — Dereferences the this pointer and returns the DWORD field at object offset 0x3E14
- `0x004623E0` **VTableBoolCheckNegated** — Thin wrapper that calls VTableBoolCheck(a1, 140, &a1) and returns true only when the vtable-dispatched boolean test yields zero (negated boolean result)
- `0x00462760` **BufferSendWithLocks** — Sends a caller buffer through a COM-style temporary object
- `0x00462A00` **SingleFunctionCallWrapper_2a00** — Accessor that follows a multi-level pointer chain (this vtable pointer at +0x0, intermediate sub-object pointer at obj+0x3FB8, its first pointer slot at +0x0) and returns the byte at offset 0x5D of the final object
- `0x00463140` **DispatchAndResetStateField** — Unconditional dual virtual dispatch on a sub-object, followed by a state reset
- `0x00463710` **StringCopyToStructField** — Copies the source string a2 into a fixed 32-byte buffer at obj+0x1B0, where obj is the target pointer held at this[0] (offset 0x0) plus 432
- `0x00463760` **DispatchServerTrackSignal** — Server track-state signal dispatch
- `0x00463C60` **GetNonEmptyStringPointer** — Getter with a string guard: loads the object pointer from this+0, forms the string pointer at object+364, and returns it only when strlen reports a non-empty string; otherwise returns null (0)
- `0x004646F0` **ConditionalFreeObject** — Destructor-like conditional free: if the flag byte at this+0x8 is nonzero, frees the embedded pointer stored at this+0
- `0x004647D0` **LinkedListMergeSort** — Recursive merge sort for a singly-linked list
- `0x00464EF0` **FloatFractionFromInt** — Accumulator fraction processing
- `0x004662E0` **StateResetWithZero** — State-reset helper for an unknown object
- `0x00466350` **PositionUpdateWithHeadingAndVelocity** — Per-frame position/heading update guarded by a flag at this+0xEC
- `0x00466650` **SteeringOrRotationUpdate** — Per-frame update of a steering/rotation damping state
- `0x00468910` **HTMLResultsStatsPageWorldChampionships** — Career-mode World Championships results page reset: walks and frees the existing linked list of stat-entry strings held on the page object, clears the list bookkeeping fields (head, tail, count, capacity), then repopulates the list with ten career stat label strings (experience laps, starts, average starting/finish position, average race length, average opponent strength, pole positions, points, wins, world champions), each inserted with key -1, before chaining to a continuation at loc_468640 and returning 0
- `0x0046B5F0` **FTIMTimerBitmapSelector** — Builds the composite display string for an FTIM timer overlay entry for one vehicle
- `0x0046DC60` **SessionStateHandler** — Session/game-mode initialization handler with two branches
- `0x0046DD30` **MultiplayerPasswordValidation** — Multiplayer password/entrant validation for the session join flow

## Proposed classes

### DelimitedStringAssembler

Appends two input strings through a shared transform (ShortComputation_cf30) into a caller buffer, separated by the read-only 16-bit global word_5C2AAC, returning the appended length.

Methods: `0x0045CE30`


### FlaggedSocketCleanupController

Conditional one-byte flag reset that runs two cleanup wrappers (single-call wrapper and socket close) only while the flag at this+0 is set, then clears it.

Methods: `0x0045D240`

- `this+0x00000000` `byte cleanup_flag` (read_write, DERIVED)

### NetworkReplayBufferController

Initializes a replay/network buffer-control object: stores the session port twice, clears an active flag, zeroes and XOR-decodes an obfuscation key, then allocates a network memory object via MemoryObjectAllocator with a callback and stores its handle.

Methods: `0x0045D260`

- `this+0x00000000` `byte active_flag` (read_write, DERIVED)
- `this+0x00000004` `word session_port_low` (write, DERIVED)
- `this+0x00000008` `word session_port_high` (write, DERIVED)
- `this+0x0000000C` `void* memory_object_handle` (write, DERIVED)

### ConditionalAnimationController

Flag-gated animation timing update: when the byte at this+0x20 is clear, forwards the parameter-set pointer at this+0x3FB8 to the shared animation timing update and returns its result, else returns the flag value.

Methods: `0x0045E570`

- `this+0x00000020` `byte gate_flag` (read, DERIVED)
- `this+0x00003FB8` `void* param_set` (read, DERIVED)

### SentinelBufferInitializer

Fills a 0x1A0-byte buffer at this+0x1D4 with 0xFF bytes (every word becomes 0xFFFFFFFF / -1) and always returns -1; used on setup paths to pre-fill per-object slot/ID buffers with unset values.

Methods: `0x0045E590`


### ServerTrackSignalObject

Server session track-signal sink: encodes a progress-bar event, allocates/dispatches a network message through the interface at +0x3FB8, clears the open flag at +0x29, and appends a debug-log node to the list at +0x1B770..+0x1B77C gated on the logging global, else frees it.

Methods: `0x00461020`

- `this+0x00000029` `byte session_open_flag` (read_write, DERIVED)
- `this+0x00003FB8` `void* com_interface` (read, DERIVED)
- `this+0x0001B770` `void* log_list_head` (read_write, DERIVED)
- `this+0x0001B774` `void* log_list_tail` (read_write, DERIVED)
- `this+0x0001B778` `void* log_list_secondary` (read_write, DERIVED)
- `this+0x0001B77C` `int log_node_count` (read_write, DERIVED)
- `*(this+0x1B774)+0x00000004` `void* tail_next` (read_write, GUESS)

### ServerTrackSignalDispatcher

State-gated dispatch of the server track signal: runs a state check on the wrapper, forwards the dereferenced this+0 target to ServerOpenedClosedNotification on failure, or to ServerOpenTrackSignal / ServerCloseTrackSignal based on a2.

Methods: `0x00463760`

- `this+0x00000000` `void* target` (read, DERIVED)

### BitFieldFlagController

Sets or clears a caller-selected bit mask in the byte bitfield at this+0x88, returning the mask on the set path and the updated field on the clear path.

Methods: `0x004614F0`

- `this+0x00000088` `byte flag_bitfield` (read_write, DERIVED)

### ScenarioValidationBuffer

Small control/flag object written by InitDefaults and queried by BitFlagTestAt0x6E: a set of zeroed bytes/words, a cluster of non-zero control defaults (+0x66..+0x6A), a 16-bit limit at +0x7C and a per-bit flag byte at +0x6E.

Methods: `0x00461560`, `0x004615F0`

- `this+0x00000000` `byte zeroed_byte_0` (write, DERIVED)
- `this+0x00000020` `byte zeroed_byte_1` (write, DERIVED)
- `this+0x00000040` `byte zeroed_byte_2` (write, DERIVED)
- `this+0x00000060` `int zeroed_dword` (write, DERIVED)
- `this+0x00000064` `byte zeroed_byte_3` (write, DERIVED)
- `this+0x00000065` `byte zeroed_byte_4` (write, DERIVED)
- `this+0x00000066` `byte control_default_a` (write, GUESS)
- `this+0x00000067` `byte control_default_b` (write, GUESS)
- `this+0x00000068` `byte control_default_c` (write, GUESS)
- `this+0x00000069` `byte control_default_d` (write, GUESS)
- `this+0x0000006A` `byte control_default_e` (write, GUESS)
- `this+0x0000006B` `byte zeroed_byte_5` (write, DERIVED)
- `this+0x0000006C` `byte zeroed_byte_6` (write, DERIVED)
- `this+0x0000006D` `byte zeroed_byte_7` (write, DERIVED)
- `this+0x0000006E` `byte flag_bitfield` (read_write, DERIVED)
- `this+0x00000070` `word zeroed_word_0` (write, DERIVED)
- `this+0x00000072` `word zeroed_word_1` (write, DERIVED)
- `this+0x00000074` `word zeroed_word_2` (write, DERIVED)
- `this+0x00000076` `word zeroed_word_3` (write, DERIVED)
- `this+0x00000078` `word zeroed_word_4` (write, DERIVED)
- `this+0x0000007A` `word zeroed_word_5` (write, DERIVED)
- `this+0x0000007C` `word limit_word` (write, GUESS)

### ServerListController

Server-list sort/filter entry point: dereferences the server-list object, guards on a network-system pointer, marks sort-as-changed, clamps and stores the requested sort index into globals, and dispatches a sort-key string while raising a refresh flag.

Methods: `0x00462160`

- `this+0x00000000` `void* server_list_ptr` (read, DERIVED)
- `obj+0x000000C4` `int sort_changed_flag` (read_write, DERIVED)
- `obj+0x0001B79C` `void* network_system_ptr` (read, DERIVED)

### EntrantCountReader

Dereferences this+0 and returns the DWORD field at obj+0x3E14, interpreted as the driver/entrant count by network and session scoring paths (DERIVED label; raw source proves only the read).

Methods: `0x00462370`

- `this+0x00000000` `void* target_ptr` (read, DERIVED)
- `obj+0x00003E14` `int driver_count` (read, DERIVED)

### VTableBoolCheckNegated

Thin wrapper returning the negation of a vtable-dispatched boolean test (VTableBoolCheck with selector literal 140), returning true only when the dispatched test yields zero.

Methods: `0x004623E0`


### BufferSendWithLocks

Sends a 128-byte caller buffer through a COM-style temporary object: query, lock (vtable+0xc4), copy, unlock (virtual dispatch), release (vtable+0x7c), always returning 1.

Methods: `0x00462760`

- `this+0x00000000` `void* target_ptr` (read, DERIVED)
- `obj+0x00003FB8` `void* com_interface` (read, DERIVED)

### ChainedFlagReader

Accessor following a multi-level pointer chain (this+0 vtable, obj+0x3FB8 intermediate, its first slot) to return the byte at offset 0x5D of the final object; no guard.

Methods: `0x00462A00`

- `this+0x00000000` `void* vtable` (read, DERIVED)
- `obj+0x00003FB8` `void* intermediate` (read, DERIVED)
- `*(obj+0x3FB8)+0x00000000` `void* first_slot` (read, GUESS)
- `*(*(obj+0x3FB8)+0x0)+0x0000005D` `byte flag_byte` (read, GUESS)

### VirtualDispatchStateController

Unconditional dual virtual dispatch on a sub-object at obj+0x3FB8, then writes 0 to the state field at obj+0x3FC4 and returns the dispatch result.

Methods: `0x00463140`

- `this+0x00000000` `void* primary_ptr` (read, DERIVED)
- `obj+0x00003FB8` `void* sub_object` (read, DERIVED)
- `obj+0x00003FC4` `int state_field` (write, DERIVED)

### TargetStringFieldWriter

Copies a caller string into a fixed 32-byte buffer at obj+0x1B0 of the target object held at this+0 (bound 31 chars, forced NUL at +0x1CF), or writes an empty string when the source is null.

Methods: `0x00463710`

- `this+0x00000000` `void* target_ptr` (read, DERIVED)
- `obj+0x000001B0` `char[32] name_buffer` (write, GUESS)
- `obj+0x000001CF` `byte name_buffer_terminator` (write, GUESS)

### NonEmptyStringAccessor

Getter that returns the string pointer at obj+364 (obj from this+0) only when strlen reports a non-empty string, else null.

Methods: `0x00463C60`

- `this+0x00000000` `void* target_ptr` (read, DERIVED)

### FlaggedPointerOwner

Destructor-like conditional free: frees the embedded pointer at this+0 when the flag at this+0x8 is set, and frees the object itself when parameter bit 0 is set; returns this unchanged.

Methods: `0x004646F0`

- `this+0x00000000` `void* owned_pointer` (read, DERIVED)
- `this+0x00000008` `byte owns_pointer_flag` (read, DERIVED)

### LinkedListMergeSorter

Recursive merge sort for a singly-linked list whose nodes link via the next pointer at +4: counts nodes, splits at the midpoint, recurses, then merges by comparing a sort key at each node's record (+8, falling back to +0 when the key is -1).

Methods: `0x004647D0`

- `*(this+0x4)+0x00000004` `void* node_next` (read_write, DERIVED)

### FractionalAccumulatorDistributor

Accumulates a float input at this+0x68, converts to the integer part, iterates 104 records (560-byte stride from this+35) calling sub_464B10 with it, then stores the fractional remainder back.

Methods: `0x00464EF0`

- `this+0x00000068` `float accumulator` (read_write, DERIVED)

### StateResetHelper

State-reset helper that releases attached resources via ResourceCleanup, zeroes the dword at this+0xF0, and returns 1 as a success indicator.

Methods: `0x004662E0`

- `this+0x000000F0` `int state_dword` (write, DERIVED)

### CameraYawZoomController

Per-frame position/heading update controller with two variants: guarded by a dword at +0xEC/+0xF0, reads saved-position components through a sub-object at +0x40, computes deltas, applies flag-based speed/brake and heading-angle branches (clamped/wrapped under the photo/free-camera global), resolves velocity from heading/speed and ends with a vtable+44 virtual call; the brake/reset variant additionally accumulates elapsed time at +0x10C and a correction term at +0x110.

Methods: `0x00466350`, `0x00466650`

- `this+0x00000000` `void* vtable` (read, DERIVED)
- `this+0x00000040` `void* sub_object` (read, DERIVED)
- `this+0x000000EC` `byte update_guard_flag` (read, DERIVED)
- `this+0x000000F0` `int state_dword` (read, DERIVED)
- `this+0x000000F4` `byte branch_flag` (read, DERIVED)
- `this+0x000000F5` `byte speed_branch_flag` (read, DERIVED)
- `this+0x000000F8` `float speed_field` (read_write, DERIVED)
- `this+0x000000FC` `float speed_clamp_high` (read, DERIVED)
- `this+0x00000100` `float speed_clamp_low` (read, DERIVED)
- `this+0x00000104` `float saved_position_x` (read_write, DERIVED)
- `this+0x00000108` `float saved_position_y` (read_write, DERIVED)
- `this+0x0000010C` `float accumulated_time` (read_write, DERIVED)
- `this+0x00000110` `float correction_term` (read_write, DERIVED)
- `this+0x00000114` `float accumulated_correction` (write, DERIVED)
- `this+0x00000118` `float velocity_x` (read_write, DERIVED)
- `this+0x0000011C` `float velocity_y` (read_write, DERIVED)
- `this+0x00000120` `float heading` (read_write, DERIVED)

### HTMLResultsStatsPage

Career-mode World Championships results page reset: walks and frees the stat-entry linked list (head +0x44, tail +0x48, count +0x4C, capacity +0x50), clears the list bookkeeping, then repopulates it with ten career stat label strings inserted with key -1.

Methods: `0x00468910`

- `this+0x00000044` `void* list_head` (read_write, DERIVED)
- `this+0x00000048` `void* list_tail` (read_write, DERIVED)
- `this+0x0000004C` `int list_count` (read_write, DERIVED)
- `this+0x00000050` `int list_capacity` (read_write, DERIVED)

### StatListNode

Referenced node layout of the stat-entry linked list held by HTMLResultsStatsPage: a data pointer at +0 and a next pointer at +4, with a presence flag byte at +8 (prose-only, not a promoted field).

Methods: 

- `*(this+0x44)+0x00000000` `void* data` (read_write, DERIVED)
- `*(this+0x48)+0x00000004` `void* next` (read_write, DERIVED)

### FTIMTimerDisplayStringBuilder

Builds the composite display string for an FTIM timer overlay entry: fetches the active vehicle pointer by index, formats lap count and total/current lap pair with session-type awareness, copies driver/vehicle name strings, selects an outline color string, and concatenates up to six component buffers separated by a delimiter, filtered by this+0x17C.

Methods: `0x0046B5F0`

- `this+0x0000017C` `int component_filter` (read, DERIVED)

### SessionUIScreenController

Session/game-mode initialization and multiplayer join handling sharing a UI-object factory interface at this+0x40 (vtable+0x1C element creation): initializes the session-type flag, performs formation-lap UI/force-feedback setup and validation, and drives the multiplayer password/join flow with a 4.0f result timer at this+0xE4.

Methods: `0x0046DC60`, `0x0046DD30`

- `this+0x00000040` `void* ui_factory_interface` (read, DERIVED)
- `*(this+0x40)+0x00000000` `void* vtable` (read, GUESS)
- `*(this+0x40)+0x0000001C` `void* vtable_ui_create` (read, GUESS)
- `*(*(this+0x40)+0x0)+0x0000001C` `void* element_create` (read, GUESS)
- `this+0x000000E4` `float password_join_timer` (write, DERIVED)

## Compatibility contracts

- **ServerTrackSignalContract** — The server session must preserve the observable close-track signal behavior of 0x00461020: a progress-bar event is encoded (ProgressBarEventEncode(4, 37, 0, 255, low dword of dbl_8AFEA0, 1)), a network message object is allocated and flagged active through the +0x3FB8 interface, dispatched via NetworkSendDispatch, committed through the COM virtual method, and the session open/close flag at +0x29 is cleared.
- **DebugLogListHeaderContract** — The debug-log linked list held by the server session object uses a four-slot header at +0x1B770 (head), +0x1B774 (tail), +0x1B778 (secondary) and +0x1B77C (node count); the previous tail's +4 slot is linked to each appended node, and the append is gated on the logging-enabled global 0x007D0398 (non-zero appends, zero frees the node and its string buffer).
- **ComInterfaceAt3FB8Contract** — Several runtime objects locate a COM-style interface pointer at byte offset 0x3FB8 (this or obj base): 0x0045E570 forwards it as a parameter set, 0x00461020 allocates/dispatches network messages through it, 0x00462760 queries a temporary object from it and locks/copies/unlocks/releases via vtable offsets 0xc4/0x7c, 0x00462A00 walks its pointer chain, and 0x00463140 dispatches through it and resets a state field at +0x3FC4. Whether all five share one interface type is unresolved.
- **CameraControllerFieldContract** — The two per-frame update variants (0x00466350, 0x00466650) share a field layout: a sub-object pointer at +0x40 read through FloatFieldAccessor/DualFieldRead, saved-position components at +0x104/+0x108, a branch flag at +0xF4, a guard dword at +0xEC/+0xF0, and a closing virtual call through vtable+44 on the vtable pointer at +0x0. Common class ownership is GUESS.
- **StatListLayoutContract** — The career stat-entry list managed by 0x00468910 uses page bookkeeping at +0x44 (head), +0x48 (tail), +0x4C (count) and +0x50 (capacity) over nodes with a data pointer at +0 and a next pointer at +4; nodes and their data buffers are freed through FreeWrapper_7bcf and ten labels are inserted with key -1 via 0x00486F30.
- **SessionUIFactoryContract** — The session object exposes a UI-object factory at this+0x40 whose vtable slot +0x1C creates UI elements by id: 30 (formation-lap race setup in 0x0046DC60) and 34 (multiplayer password entry in 0x0046DD30). The factory object's vtable sits at +0x0 of the +0x40 pointer. Shared ownership is GUESS.

## Unresolved

- Every packet owner is UnknownObject/UNKNOWN. All class groupings here (DelimitedStringAssembler, FlaggedSocketCleanupController, NetworkReplayBufferController, ConditionalAnimationController, SentinelBufferInitializer, ServerTrackSignalObject, ServerTrackSignalDispatcher, BitFieldFlagController, ScenarioValidationBuffer, ServerListController, EntrantCountReader, VTableBoolCheckNegated, BufferSendWithLocks, ChainedFlagReader, VirtualDispatchStateController, TargetStringFieldWriter, NonEmptyStringAccessor, FlaggedPointerOwner, LinkedListMergeSorter, FractionalAccumulatorDistributor, StateResetHelper, CameraYawZoomController, HTMLResultsStatsPage, StatListNode, FTIMTimerDisplayStringBuilder, SessionUIScreenController) are worker synthesis at DERIVED/GUESS, not packet evidence.
- word_5C2AAC is a read-only 16-bit global inserted between appended segments in 0x0045CE30; whether it is a visible delimiter or a record marker is not evidenced.
- The transformation performed by ShortComputation_cf30 (0x0045CF30) is opaque from this packet; both appended segments pass through it.
- The message object v2 layout (only byte +4 is set) and the ((v9[0]>>8)&0x3FF)+8 length derivation used by NetworkSendDispatch are network-protocol contracts not resolved in this packet.
- byte_5EA438 is treated as a fallback log-path string but its content is unknown from this packet; its precise role in ServerCloseTrackSignal is unresolved.
- The session-type role of dword_7C569C (value 5 excluding dev logging) is DERIVED from prior analysis, not proven here.
- The precise semantics of StateCheckWrapper's return (0x00461DC0) in 0x00463760 (which state count qualifies as open vs blocked) are not documented in this packet.
- Whether the dereferenced this+0 in ServerTrackSignalDispatcher is an object pointer, opaque token, or vtable is unresolved from this function alone.
- The meaning of the individual bit flags at this+0x88 (0x004614F0) and at this+0x6E (0x004615F0) is unresolved; callers NetComm_SetSelfAsReady and ConditionalRenderStateUpdate suggest a network-readiness or render-state bitfield role, but this is not evidenced.
- The meaning of the non-zero InitDefaults values (+0x66 = 16, +0x67 = 1, +0x68 = 1, +0x69 = 100, +0x6A = 1, +0x7C = 200) is unknown; no consuming code is visible in this packet.
- In 0x004623E0 the meaning of the selector literal 140 and of the third pointer argument (&a1) passed to VTableBoolCheck is unknown.
- In 0x00462760 the identity of the COM temporary object and the interfaces behind vtable offsets 0xc4 and 0x7c, and the destination/semantics of the 128-byte copy, are unverified.
- The entrant-validation call target loc_462010 in 0x0046DD30 is a thiscall function pointer inside the function present in the raw source but absent from the packet callee list; its identity is unresolved.
- The 4.0f value written to this+0xE4 and the exact role of byte_7CD850 (password buffer) in 0x0046DD30 are not proven.
- In 0x00462A00 the semantic role of the returned byte (0x5D) and the class owning the pointer chain are unknown; the decoded offsets match the chain only.
- The purpose of the dispatched sub-object at +0x3FB8 and the reset state field at +0x3FC4 in 0x00463140 is not established, and the relation of this reset to the caller SessionStateByte7CE25FSetter (0x00464600) is not confirmed.
- In 0x00463710, sub_587DD0's exact contract (strncpy-like bounded copy returning the destination) is inferred from the 31-char bound; the target object type and the purpose of the +0x1B0 string field are unidentified.
- In 0x00463C60 the purpose of the string stored at object+364 and why a non-empty string pointer is guarded while an empty one yields null are unresolved; caller sub_463BC0 has not been analyzed.
- The LinkedListMergeSort node layout is only partially covered: the next pointer at +4 is evidence-backed, while the sort-key reads at record+0x8 and the -1 fallback to record+0x0 appear in raw source only and have no packet field evidence_ref.
- The 104 records of 560 bytes starting at this+35 in 0x00464EF0 form an array of unknown element type; the accumulator and 0.0049999999 scaling semantics are guessed, not confirmed.
- In 0x004662E0, ResourceCleanup (0x0048E890) is called without an explicit receiver in the raw source; its exact side effects are outside this function.
- The flag semantics at 0xF4/0xF5 and the exact owning class of 0x00466350/0x00466650 are not confirmed; the legacy ABI label names a camera yaw/zoom controller while the skeleton fill treats it as a generic position/heading update. The two-function grouping as CameraYawZoomController is GUESS (shared layout is suggestive, common ownership unproven).
- The semantics of the two saved-position deltas and the OffsetDispatch 0.0074999998 scale factor in 0x00466350 are not established.
- In 0x00466650 the meaning of the flag byte at +0xF4 (brake/reset vs smooth) and of the vtable+44 virtual method argument 1 is not confirmed; field:obj:0x2C is not directly referenced in the raw source.
- In 0x00468910 the identity/behavior of the continuation at loc_468640 is not in this packet; the global stat-entry list used by LinkedListInsertWithNodeAllocation is not named here; the insert key -1 meaning is undefined. The node presence flag byte at node+8 is prose-only and not promoted to a field.
- In 0x0046B5F0 the exact use of globals aD_1 (0x005C3280), aDS_4 (0x005C6A70) and unk_5EC6D0 is not visible in the rendered Hex-Rays body; sub_42BDD0's return semantics (red/green/grey mapping) are defined outside this packet.
- In 0x0046DC60 the identity of the indirect __thiscall state check on dword_7CD25C is not resolved to a named callee; the meaning of the a2 parameter (forwarded to sub_46BF10) is unknown; session state values (5, 1, 0) and dword_5CC9E8 = 4 come from the existing fill, not proven here.
- In 0x0045D570 argument a2 is declared in the signature but never referenced in the function body.
- Several read-only float globals (flt_59E84C, flt_59E87C, flt_59E888, flt_59F1F0..flt_59F1FC, flt_59F200, flt_59E43C..flt_59E450, flt_59E478, flt_59E8EC, flt_59E98C, flt_59F204..flt_59F20C) are flagged by packet facts but never appear in the raw decompiled source; their role (likely scaling/tuning constants consumed by helper callees) is unverifiable from this packet.
- In 0x0045D260, global off_5C5B68 is listed as a read global but never referenced by the raw source; in 0x00464EF0, flt_59F138 has the same read-but-absent status. Their roles are unestablished.
- In 0x00462160 the object type of *this (the server-list object) is unnamed; dword_7D1028/dword_7D102C bound the sort range but their writers are not established here; the refresh flag byte_7CD2A0 consumer is not visible.
