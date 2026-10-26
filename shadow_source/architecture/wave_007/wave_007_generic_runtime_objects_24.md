# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

This packet collects 43 generic runtime object helpers whose owning classes are all UNKNOWN. Defensible groupings (all DERIVED/GUESS, none CONFIRMED): (1) a large family of argumentless ref-count decrement wrappers forwarding to shared RefCountDecrementWithCheck/WithCleanup helpers and routing read-only global refcount bytes (0x008D3BFx/0x008D3C1x/0x008D3E2x); (2) buffer cursor copy helpers with the cursor at this+0 (0x0057A180 write-side, 0x0057A1B0 read-side) used by (3) a structural-twin struct-field codec pair 0x0057A270/0x0057A330 that serialize this+4/8/40..44 and a variable tail this+45 whose byte count lives at this+0x2C; (4) a bytewise-OR copy cluster 0x0057A070 + fluent pass-through 0x0057A040; (5) a mutex-guarded accessor pair 0x0057A810/0x0057A820 with a context mutex at +0x640 and timeout at +0x644; (6) global module-init-list management (head 0x008D3BFC, re-entry flag 0x008D3BFB, trailing state 0x008D3C00/04/08) with guarded and unconditional teardown plus a reset routine; (7) callback-registration probes that reduce a function address or helper boolean to an int via the shared BooleanToIntConversion (0x00587B3E); (8) vtable-aware lifetime helpers and a conditional-free descriptor family (block at +0, ownership flag at +8); (9) linked-list containers; (10) a clamped session-config store; (11) a counter incrementer; (12) a bitmap-region occupancy tester; and (13) two small network accessors (host-order port at this+0x12C, connection-node matcher on +0x2/+0x4). The single non-wrapper with real control structure is the module-list teardown walk. Every class grouping is inferred from shared call shape and fields, never from proven ownership.

## Function roles

- `0x0057A010` **RefCountedObjectManager** — Argumentless ref-count decrement wrapper that tail-forwards to RefCountDecrementWithCheck and returns its result unchanged; reads no packet field locally.
- `0x0057A040` **ByteTransformCopyHelper** — Fluent pass-through wrapper: forwards a2, a3, a4 plus literal 0 to the bytewise-OR copy routine and returns this unchanged.
- `0x0057A070` **ByteTransformCopyHelper** — Bytewise-OR cluster copy: copies 9 bytes from a2 into this buffer, ORs the first four bytes with a source derived from the a4 argument, then copies 4 bytes into this+16 via sub_587DD0.
- `0x0057A180` **SerializationBuffer** — Write-cursor buffer copy: copies a3 bytes into the destination whose cursor is stored at this+0, advances that cursor by a3, returns the original this pointer.
- `0x0057A1B0` **SerializationBuffer** — Read-cursor buffer copy: copies a3 bytes from the chunk pointed to by *a1 into a2, advances the stored cursor *a1 by a3, returns the descriptor a1.
- `0x0057A260` **ByteConfigOffsets** — Byte-config offset getter: returns the byte at field offset 0x2C plus 41; supplies a serialized field offset to the network offset helper.
- `0x0057A270` **SerializedStructCodec** — Struct-field serializer: copies this+4 (4), this+8 (32), five single bytes this+40..44, and a variable tail this+45 (count = byte at this+44) into an advancing output buffer via DwordAlignedMemoryCopy; writes total bytes to *a4.
- `0x0057A330` **SerializedStructCodec** — Structural twin of the serializer using MemcpyWithAdvancePointer instead of DwordAlignedMemoryCopy; identical field layout (this+4/8/40..44, var tail from this+44 count); writes total bytes to *a3.
- `0x0057A750` **SessionConfigClampWriter** — Clamped value store: dereferences context a1, computes a reference via sub_587890(base+300, a2), stores min(a3, reference) at obj+128, returns the computed reference.
- `0x0057A810` **MutexGuardedAccessor** — Mutex-guarded read wrapper: reads the dword field at offset 0x0 of this and forwards it to ThreadSafeIntReadWithMutex, returning that result.
- `0x0057A820` **MutexGuardedAccessor** — Mutex-guarded computation: dereferences *this to the owning context, acquires the mutex at context+0x640 with timeout at context+0x644 via WaitForSingleObject, runs ShortComputation_7210 on the sub-struct at context+0x624 (or with null), then re-reads and releases the handle with ReleaseMutex when non-null.
- `0x0057A960` **RefCountedObjectManager** — Thin ref-count decrement+cleanup tail-call wrapper with no local state or branching.
- `0x0057A9A0` **RefCountedObjectManager** — Callback-style ref-count decrement+check wrapper; also performs a read of global unk_8D3BF4 whose role is not visible in the raw wrapper source.
- `0x0057A9B0` **ObjectLifetimeHelpers** — Scalar deleting destructor: installs vtable off_5B8A00 at *this, frees the object through FreeWrapper_7bcf when flag byte a2 bit 0 is set, returns this.
- `0x0057AA10` **ModuleListManager** — Returns the address of global unk_8D3BFA via pass-through sub_4B3DB0 which returns its pointer argument.
- `0x0057AA20` **CallbackRegistry** — Callback-registration probe: passes the address of sub_57AA30 through BooleanToIntConversion and returns the conversion result.
- `0x0057AA30` **ModuleListManager** — Invokes module-list cleanup: calls sub_57AB50 with the address of global unk_8D3BFA and returns its int result.
- `0x0057AA50` **ModuleListManager** — Straight-line reset routine: writes 0 to globals 0x008D3BFC, 0x008D3C00, 0x008D3C04, 0x008D3C08 and returns 0; no branches or calls.
- `0x0057AA80` **ModuleListManager** — Guarded module-list teardown: re-entry flag at byte_8D3BFB bit 0 skips cleanup; otherwise walks the list head 0x008D3BFC via node+4 next, destroys flagged nodes through their vtable via VTableDestructorThenNullPointer, frees sub-objects and nodes via FreeWrapper_7bcf, resets the four list globals to 0, returns 1 on both paths.
- `0x0057AB50` **ModuleListManager** — Unconditional module-list teardown: walks the same list from head 0x008D3BFC, destroys flagged node objects via VTableDestructorThenNullPointer and frees them, resets all four list globals to 0, returns the last FreeWrapper_7bcf result.
- `0x0057ADC0` **CallbackRegistry** — Callback-registration probe: passes the address of sub_57ADD0 through BooleanToIntConversion and returns the conversion result.
- `0x0057ADD0` **RefCountedObjectManager** — Thin ref-count decrement+cleanup tail-call wrapper with no local state or branching.
- `0x0057AE00` **CallbackRegistry** — Callback-registration probe: converts the address of callback routine sub_57AE10 through BooleanToIntConversion into 1 (non-null) or 0.
- `0x0057AE10` **RefCountedObjectManager** — Thin ref-count decrement+check tail-call wrapper forwarding a char* result.
- `0x0057AE40` **CallbackRegistry** — Stub variant callback-registration probe: converts the address of callback routine sub_57AE50 through BooleanToIntConversion into 1 (non-null) or 0.
- `0x0057AE50` **RefCountedObjectManager** — Thin ref-count decrement+cleanup tail-call wrapper with no local state or branching.
- `0x0057AE90` **RefCountedObjectManager** — Argumentless ref-count decrement+check forwarding wrapper returning the callee result unchanged.
- `0x0057B0D0` **IndexedLinkedList** — Indexed linked-list node getter: bounds-checks index a2 against the counter at this+0x14, walks from head this+0x8 via node+1 next pointers, returns the node payload or 0 on failure.
- `0x0057B7B0` **ObjectLifetimeHelpers** — Vtable-init then conditional free: re-initializes the vtable pointer via VTablePointerInit, releases the object through FreeWrapper_7bcf only when flag byte a2 bit 0 is set, returns this.
- `0x0057BCA0` **ByteConfigOffsets** — Network offset helper: calls ByteFieldOffsetGetter(this) and returns that byte-field offset plus a fixed 6.
- `0x0057BCB0` **NetworkEndpoint** — Network port getter: reads the u_short port at this+0x12C and converts it from network to host byte order via ntohs.
- `0x0057DB80` **NetworkConnectionNode** — Connection-node match predicate: returns TRUE only when the DWORD at this+0x4 equals a3 and the WORD at this+0x2 equals HIWORD(a2); pure boolean, no side effects.
- `0x0057EF80` **ObjectLifetimeHelpers** — Null-safe virtual destructor delete: when a1 is non-null reads the vtable at a1+0 and calls slot 0 as __thiscall(a1, 1); returns the destructor result or 0 for a null pointer.
- `0x00581780` **LinkedListCursor** — List cursor advance: reads the current node from this+0x8, advances it through the link field at node+0x4, reloads, and returns the node's data value or 0 when exhausted.
- `0x00582290` **ConditionalFreeDescriptor** — Conditional teardown: when the flag byte at this+8 is nonzero, frees the heap block at this+0 via FreeWrapper_7bcf and returns the flag result; otherwise returns 0 without freeing.
- `0x00582340` **ConditionalFreeDescriptor** — Conditional vtable-entry-1 call: when the flag byte at this+8 and the object at this+0 are both non-null, calls vtable entry 1 (obj+0 then +4) as __thiscall(obj, 1); returns the call result or the flag byte when skipped.
- `0x00585E20` **CallbackRegistry** — Call-through probe: evaluates sub_585E30 for a boolean and converts it to an int via BooleanToIntConversion.
- `0x00585E30` **RefCountedObjectManager** — Trivial ref-count decrement+cleanup forwarding wrapper; static facts record a read of global 0x008D3E2D attributed to the delegated routine.
- `0x00585E70` **RefCountedObjectManager** — Trivial ref-count decrement+check forwarding wrapper; static facts record a read of global 0x008D3E2C attributed to the delegated routine.
- `0x00586C90` **CounterIncrementer** — Counter increment with cap check: increments the 32-bit counter at this+0, persists it, and returns a boolean from the sign/overflow idiom (inverts at counter value 6 for ordinary ranges).
- `0x00586D70` **BitmapRegionTest** — Bitmap region occupancy tester: reads descriptor index this+0x38, descriptor table this+0x1C, bitmap base this+0x14, and accumulates result |= (1<<k) for set bits in the selected range.
- `0x00586EE0` **CallbackRegistry** — Callback-registration probe: passes the address of sub_586EF0 through BooleanToIntConversion and returns the result.
- `0x00586EF0` **RefCountedObjectManager** — Trivial ref-count decrement+cleanup forwarding wrapper returning the delegated routine's int result; static facts record a read of global 0x008D3E31 attributed to the delegated routine.

## Proposed classes

### RefCountedObjectManager

Family of argumentless wrapper routines that forward to shared RefCountDecrementWithCheck/WithCleanup helpers; several route or are adjacent to read-only global refcount-state bytes. Owners of the counted objects are unknown.

Methods: `0x0057A010`, `0x0057A960`, `0x0057A9A0`, `0x0057ADD0`, `0x0057AE10`, `0x0057AE50`, `0x0057AE90`, `0x00585E30`, `0x00585E70`, `0x00586EF0`


### SerializationBuffer

Buffer cursor copy helpers; both place the advancing byte cursor at this+0. 0x0057A180 is the write-side (destination cursor filled and advanced), 0x0057A1B0 the read-side (source cursor consumed and advanced).

Methods: `0x0057A180`, `0x0057A1B0`

- `this+0x00000000` `char * cursor` (read_write, DERIVED)

### SerializedStructCodec

Structural-twin struct-field codec pair. Both serialize this+4 (4 bytes), this+8 (32 bytes), five single bytes this+40..44, and a variable-length tail from this+45 whose byte count is the field at this+0x2C, writing total bytes to the size out-param. 0x0057A270 uses DwordAlignedMemoryCopy, 0x0057A330 uses MemcpyWithAdvancePointer.

Methods: `0x0057A270`, `0x0057A330`

- `this+0x0000002C` `unsigned char tailLengthByte` (read, DERIVED)

### ByteTransformCopyHelper

Bytewise-OR string copy cluster: 0x0057A070 copies 9 bytes into this buffer, ORs the first four bytes with a byte sourced from an address derived from a4, then copies 4 bytes into this+16; 0x0057A040 is the fluent pass-through caller.

Methods: `0x0057A040`, `0x0057A070`

- `this+0x00000000` `void * destinationBuffer` (read_write, GUESS)

### MutexGuardedAccessor

Mutex-guarded access to object state. 0x0057A810 forwards the leading int field (this+0) to a thread-safe read under a mutex; 0x0057A820 acquires the mutex handle at context+0x640 with timeout at context+0x644, runs ShortComputation_7210 on the guarded sub-struct, then re-reads and releases the handle. Grouping is inferred; the two patterns are distinct and the owning context is unknown.

Methods: `0x0057A810`, `0x0057A820`

- `this+0x00000000` `int sharedInt` (read, GUESS)
- `obj+0x00000640` `HANDLE mutexHandle` (read_write, DERIVED)
- `obj+0x00000644` `unsigned long waitTimeout` (read, DERIVED)

### ModuleListManager

Global module-init-list management: list head at 0x008D3BFC, re-entry flag byte at 0x008D3BFB bit 0, trailing state dwords 0x008D3C00/0x008D3C04/0x008D3C08. Guards and performs node teardown (0x0057AA80 guarded, 0x0057AB50 unconditional), resets the globals (0x0057AA50), fetches the list address (0x0057AA10), and wires the cleanup invocation (0x0057AA30).

Methods: `0x0057AA10`, `0x0057AA30`, `0x0057AA50`, `0x0057AA80`, `0x0057AB50`


### CallbackRegistry

Registration probes that reduce a function address or a helper's boolean result to an int through the shared BooleanToIntConversion (0x00587B3E). The 'registration' interpretation derives from corpus names and is not independently proven.

Methods: `0x0057AA20`, `0x0057ADC0`, `0x0057AE00`, `0x0057AE40`, `0x00585E20`, `0x00586EE0`


### ObjectLifetimeHelpers

Vtable-aware object destruction and conditional free helpers: scalar deleting destructor installing vtable off_5B8A00 (0x0057A9B0), null-safe virtual destructor delete via vtable slot 0 (0x0057EF80), and vtable-init-then-conditional-free (0x0057B7B0).

Methods: `0x0057A9B0`, `0x0057B7B0`, `0x0057EF80`

- `this+0x00000000` `void ** vtablePointer` (read_write, DERIVED)
- `obj+0x00000000` `void ** vtablePointer` (read, DERIVED)

### ConditionalFreeDescriptor

Small owner/descriptor records holding an owned block pointer at +0 and an ownership flag byte at +8, with two guarded teardown routines: free the block when the flag is set (0x00582290) or conditionally call vtable entry 1 on the object (0x00582340). Used by physics shutdown, visibility-grid, collision-list and network-list manager paths.

Methods: `0x00582290`, `0x00582340`

- `this+0x00000000` `void * ownedBlock` (read, DERIVED)
- `this+0x00000008` `unsigned char ownershipFlag` (read, DERIVED)
- `obj+0x00000000` `void * targetObject` (read, GUESS)
- `*(obj+0x0)+0x00000004` `void (*)(void *, int) slot1` (read, GUESS)

### ByteConfigOffsets

Byte-config-driven offset derivation: 0x0057A260 returns the config byte at this+0x2C plus 41; 0x0057BCA0 adds a fixed 6 to that result for network serialization offset math.

Methods: `0x0057A260`, `0x0057BCA0`

- `this+0x0000002C` `unsigned char configByte` (read, DERIVED)

### IndexedLinkedList

Singly linked list with head node at +0x8 and a stored count at +0x14; provides an indexed node accessor with bounds check (0x0057B0D0). Fields at +0xC and +0x10 are present in the layout but not read by the accessor.

Methods: `0x0057B0D0`

- `this+0x00000008` `void * headNode` (read, DERIVED)
- `this+0x00000014` `int nodeCount` (read, DERIVED)
- `this+0x0000000C` `unknown unusedField0C` (unknown, GUESS)
- `this+0x00000010` `unknown unusedField10` (unknown, GUESS)

### LinkedListCursor

Iteration cursor over a linked list: current node stored at +0x8, next link advanced through the node link field (mapped to +0xC in the evidence model). 0x00581780 advances the cursor and returns the node data or 0 when the list is exhausted.

Methods: `0x00581780`

- `this+0x00000008` `void * currentNode` (read_write, DERIVED)
- `this+0x0000000C` `void * nextNodeLink` (write, GUESS)

### NetworkEndpoint

Network endpoint object holding a host-order network port at this+0x12C; the getter converts the stored port through ntohs (0x0057BCB0).

Methods: `0x0057BCB0`

- `this+0x0000012C` `unsigned short port` (read, DERIVED)

### NetworkConnectionNode

Connection record matched against connection-ID queries: a WORD tag at this+0x2 matched against HIWORD(query) and a DWORD id at this+0x4 matched against the full query dword. 0x0057DB80 is a pure boolean predicate.

Methods: `0x0057DB80`

- `this+0x00000002` `unsigned short queryTagWord` (read, DERIVED)
- `this+0x00000004` `unsigned int connectionId` (read, DERIVED)

### SessionConfigClampWriter

Writes a clamped value into a session/config object: computes a reference through sub_587890 and stores min(requested, reference) at obj+128. Called from SessionTypeSetter (0x00463F70). The owning object is unknown.

Methods: `0x0057A750`

- `obj+0x00000000` `void * objectBase` (read, GUESS)
- `obj+0x00000080` `float clampedConfigValue` (write, GUESS)

### CounterIncrementer

Post-increment 32-bit counter with a cap-boundary boolean result (inverts at value 6 for ordinary ranges). 0x00586C90 increments this+0 and returns the sign/overflow idiom result.

Methods: `0x00586C90`

- `this+0x00000000` `unsigned int counter` (read_write, DERIVED)

### BitmapRegionTest

Bitmap region occupancy tester: reads a descriptor index at this+0x38, a range descriptor table at this+0x1C (start/count WORD pairs), and a bitmap base at this+0x14, then accumulates an occupancy bitmask for the selected region.

Methods: `0x00586D70`

- `this+0x00000014` `const unsigned char * bitmapBase` (read, DERIVED)
- `this+0x0000001C` `const unsigned short (*)[2] rangeDescriptorTable` (read, DERIVED)
- `this+0x00000038` `int descriptorIndex` (read, DERIVED)

## Compatibility contracts

- **RefCountDecrementForwarding** — Argumentless ref-count decrement wrappers must forward to the shared check/cleanup routine and return its result unchanged; a replacement may collapse each wrapper into a direct call to the shared routine without changing observable behavior.
- **CursorBufferCopyContract** — Copy helpers read a byte cursor from field this+0, copy a3 bytes, and write back cursor + a3. Byte counts must be preserved exactly: 9 and 4 in the OR-transform cluster (0x0057A070), and 4, 32, five x 1, and the variable tail (count = byte at this+0x2C) in the two codecs (0x0057A270, 0x0057A330).
- **ModuleInitListStateContract** — The module-init list is anchored by global head 0x008D3BFC with per-node next at +4, flag byte at +12, and object pointer at +0. Teardown must honor the re-entry flag at 0x008D3BFB bit 0, destroy flagged node objects through their vtable, free nodes, null the head, and reset 0x008D3C00/0x008D3C04/0x008D3C08 to zero.
- **VtableDestructorSlotZero** — Object deletion helpers call vtable slot 0 as __thiscall(this, 1); the scalar-deleting destructor must sit on slot 0 and its flag semantics (bit 0 = release the allocation) must be preserved. The vtable install at *this for the off_5B8A00 class must remain the first write of the destructor path.
- **MutexGuardContract** — 0x0057A820 acquires the handle at context+0x640 with the timeout at context+0x644 via WaitForSingleObject, runs the guarded computation only on WAIT_OBJECT_0/WAIT_ABANDONED, and re-reads and releases the same handle with ReleaseMutex when non-null. The acquire/compute/release pairing must be preserved.
- **NetworkPortByteOrder** — The network port at this+0x12C is stored in network byte order and must be converted via ntohs before use; the receiver object must keep the port at byte offset 0x12C.
- **ConditionalFreeDescriptorContract** — The conditional-free descriptor holds an owned block pointer at +0 and an ownership flag byte at +8; teardown must free the block (or invoke the vtable entry) only when the flag is non-zero, and return the flag-derived result. Used by physics shutdown, visibility-grid, collision-list and network-list manager paths.

## Unresolved

- Owner identity of every function and every class grouping in this packet is UNKNOWN; all groupings are inferred from shared call shape, fields, and corpus names, never from proven ownership.
- RefCountDecrementWithCheck and RefCountDecrementWithCleanup have no addresses or callee entries in the packet; the read-only globals 0x008D3BF0/0x008D3BF4/0x008D3BF5/0x008D3BF8/0x008D3BF9/0x008D3C18/0x008D3C19/0x008D3E2C/0x008D3E2D/0x008D3E31 are absent from the wrapper bodies and are attributed to the delegated helpers; those relationships are unproven.
- BooleanToIntConversion (0x00587B3E) semantics are unknown; the 'registration' interpretation of the probe wrappers is inferred from corpus names and not independently verified.
- Semantics of the copy primitive sub_587DD0 (called with lengths 9 and 4) and of the clamp reference helper sub_587890 are unknown.
- SerializedStructCodec fields at this+4, this+8, this+40..44 and the variable tail base this+45 are used in the raw source but are not declared packet fields; the struct layout is not established.
- The two codecs 0x0057A270 and 0x0057A330 share the byte count field at this+0x2C but the packet does not prove they serialize the same struct; the structural-twin relationship is DERIVED from a cluster prelabel.
- The roles of the trailing module-list globals 0x008D3C00/0x008D3C04/0x008D3C08 (tail/counter labels) are DERIVED prior-analysis names not grounded in this packet.
- The constants 41 (in 0x0057A260) and 6 (in 0x0057BCA0) have no attested meaning; they are treated as opaque offsets.
- The counter cap constants 5 and 6 in 0x00586C90 are compiler-generated sign/overflow idiom literals; their domain significance and the caller-facing meaning of the returned boolean are unknown.
- The byte at field offset 0x2C appears as this-relative in two different classes (SerializedStructCodec, ByteConfigOffsets) and at +0x44 in function prose; equal byte offsets on different object bases do not prove common ownership.
- IndexedLinkedList fields at +0xC and +0x10 exist in the layout but are not read by the accessor; their purpose is unevidenced.
- sub_4B3DB0 (pass-through for 0x0057AA10) and sub_57AB50 (callee of 0x0057AA30) are referenced by name only; their bodies are outside this packet.
- The returned value of 0x0057AB50 is the last FreeWrapper_7bcf result and is uninitialized when the list head is null; the caller's use of it is unknown.
- The vtable entry at +4 called by 0x00582340 is speculatively a destructor in prior analysis but no independent evidence in this packet supports that reading; the meaning of the literal argument 1 is unevidenced.
- The bitmap result bit ordering (result bit k corresponds to bitmap bit end-k, i.e. reversed) is inferred from the loop structure and not confirmed by any caller; no callers of 0x00586D70 are recorded.
