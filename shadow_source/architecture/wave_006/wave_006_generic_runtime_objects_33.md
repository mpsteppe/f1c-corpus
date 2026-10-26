# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Reconstruction of generic runtime objects from 36 validated function IR records. Two DERIVED owners come from the packet (EventTimerManager = 0x00583F50 timer tick walk, MutexObject = 0x00586500); all other owners are UNKNOWN and proposed here at GUESS level. 0x00585F60 (wait), 0x00585F90 (release) and 0x005862C0 (create-or-replace) share the same this+0x50 mutex handle slot with ready-flag at +0x58 and timeout at +0x54, and all three are called by 0x005837F0, so they are grouped as MutexSynchronizationObject. 0x00586070 and 0x00586670 both operate on nodes with data at +0, next at +4 and an ownership flag byte at +8 and both free node payloads via EmptyStub_0170 + FreeWrapper_7bcf; they are linked through LinkedNodeRecord, with the container roots at this+0x0/0x4/0x8/0xC kept as LinkedNodeContainer (0x00586670) and the double-list drainer as DoubleListOwner (0x00586070). 0x005876F0/0x00587880/0x005879F0 share the buffer-state field block this+0x400..0x414 and the BufferedCharIOInit->FieldConstantsInitialization call edge, proposed as BufferedIOObject. The three 0xFF00000000005450..52 global writes are decompiler byte-aliases of the DWORD handle writes and are parked unresolved. Remaining functions stay under UnknownObject with their semantics captured in the role text.

## Function roles

- `0x00583A80` **UnknownObject** — MSVC scalar deleting destructor on an unknown object: runs the real destructor sub_583AE0 on this, then, when the low bit of the delete flag a2 is set, releases this through FreeWrapper_7bcf; returns this.
- `0x00583D40` **UnknownObject** — Reads a mutex-protected byte from a 40-byte slot record at a1 + 40*a2 (byte at +12, mutex handle at +16, wait timeout ms at +20): WaitForSingleObject with the per-slot timeout, authorizes the read when the wait returns 0 or 128, reloads the handle from +16 and releases it; returns the byte. Called by StartAddress (0x00583D90).
- `0x00583F50` **EventTimerManager** — EventTimerManager tick: walks two timer-node lists (controls at this+0x57C and this+0x598), decrementing each node deadline at node+0x4C by CRTFtol(a2*1000+0.5); nodes that reach zero are unlinked (head/tail/count at control +0/+4/+8), cleaned by ConditionalListNodeCleanup, freed via FreeWrapper_7bcf and appended to a free list under the append mutex this+0x570 with a 1 ms wait; each list walk is guarded by the per-list mutex this+0x58C / timeout this+0x590.
- `0x00584110` **UnknownObject** — Trivial thiscall accumulator: adds float a2 into the 8-byte field at offset 0xE0 (this[28] on a double-typed pointer) in place. Single caller is StartAddress (0x00583D90).
- `0x00584DD0` **UnknownObject** — Thread-safe list insertion on an unknown object: if the mutex handle at this+0x570 is non-null, waits on it with the timeout at this+0x574, appends node a2 via LinkedListNodeAppend_6000, records success and releases the mutex; returns a boolean success flag. The this+0x570/0x574 mutex-guard layout matches the EventTimerManager append-mutex fields but common ownership is not proven.
- `0x00584F30` **UnknownObject** — Mutex-gated linked-list append on an unknown object: waits on the handle at this+0x5A8 with the timeout at this+0x5AC, appends the caller node via LinkedListNodeAppend_6000 when the wait returns 0 or 128, releases the mutex, and returns 1 on success else 0.
- `0x00585CC0` **UnknownObject** — Pure getter: returns the dword at this+0x78 (this[30]). No calls, guards or side effects; field meaning unknown (trigger iteration paths are among the callers).
- `0x00585F60` **MutexSynchronizationObject** — Mutex waiter on the mutex-synchronization layout: reads the handle at this+0x50 and timeout at this+0x54, calls WaitForSingleObject when the handle is non-null, and returns this when the result is 0 or 128, else 0. Called by sub_5837F0 (0x005837F0).
- `0x00585F90` **MutexSynchronizationObject** — Thin ReleaseMutex wrapper: when the handle at this+0x50 is non-null, calls ReleaseMutex and propagates its BOOL result, else returns FALSE. Sole recorded caller is sub_5837F0 (0x005837F0).
- `0x00586070` **DoubleListOwner** — Destroys two linked lists rooted at this+0x10 and this+0x0. Per node with the flag byte at node+0x8 set and data at node+0x0 non-null, runs EmptyStub_0170 then frees the data and the node via FreeWrapper_7bcf. The second list additionally drives an SEH-registered callback loop (NTimeCallbackLoopWithSEH, size 1048, handler table 0x0059D120) on an inner object before freeing inner/data allocations and the node. After each list is drained, the four root fields (this+0x10/0x14/0x18/0x1C and this+0x0/0x4/0x8/0xC) are zeroed. Returns 0.
- `0x005862C0` **MutexSynchronizationObject** — Creates or replaces the unnamed mutex of the mutex-synchronization layout: when the ready flag byte at this+0x58 is set and CloseHandle on the handle at this+0x50 succeeds the handle slot is cleared; a fresh unnamed mutex is created via CreateMutexA (SECURITY_ATTRIBUTES nLength=12, no descriptor, inheritable) into this+0x50 and the ready flag is set to 1 on success; returns the flag. Invoked by sub_5837F0 (0x005837F0).
- `0x00586500` **MutexObject** — MutexObject create-or-recreate: when the byte flag at this+0xC is set and CloseHandle on the handle at this+0x4 succeeds, clears the handle; a fresh unnamed mutex is created via CreateMutexA (SECURITY_ATTRIBUTES nLength=12, no descriptor, inherit=1) into this+0x4 and the flag at this+0xC is set to 1 on success; returns the flag value.
- `0x00586560` **UnknownObject** — Create-or-replace mutex wrapper on an unknown object: when the byte flag at this+0x5C is set and CloseHandle on the handle at this+0x54 succeeds the handle is cleared; CreateMutexA builds an unnamed mutex stored at this+0x54, and the flag at this+0x5C is set to 1 when the handle is non-null; returns the flag. Called by sub_5837F0 (0x005837F0); structurally a sibling of 0x005865C0 with different offsets.
- `0x005865C0` **UnknownObject** — Create-or-replace mutex wrapper on an unknown object: when the byte flag at this+0x24 is set and CloseHandle on the handle at this+0x1C succeeds the handle is cleared; CreateMutexA builds an unnamed mutex stored at this+0x1C, and the flag at this+0x24 is set to 1 when the handle is non-null; returns the flag. Called by sub_5837F0 (0x005837F0); structurally identical to a sibling wrapper with different offsets.
- `0x00586670` **LinkedNodeContainer** — Removes the first node whose data pointer matches a2 from a singly-linked container (head this+0x0, tail this+0x4, cursor this+0x8, count this+0xC): unlinks the node, advances the cursor when needed, optionally releases the payload (flag byte at obj+0x8 and data at obj+0x0) via EmptyStub_0170 + FreeWrapper_7bcf, frees the node, and returns 1; returns 0 for a null target or empty list.
- `0x00586A80` **UnknownObject** — Thin thiscall wrapper that invokes FieldAccessor (0x0053D880) with a pointer to the dword at index 2 of this and returns its result unchanged. Callers 0x00584230 and 0x00587730 are outside this packet.
- `0x00586A90` **UnknownObject** — Trivial __thiscall forwarder: passes (this + 8) to callee sub_563E70 and returns its result unchanged; reads no fields itself. Callers sub_584230 and sub_587730 are outside this packet.
- `0x00586D00` **UnknownObject** — Tests range occupancy in a packed bitmap: reads a range descriptor (start WORD + count WORD) from the array at this+0x1C indexed by this+0x34, then for each of count positions tests bits in the bitmap at this+0x14 and builds an occupancy bitmask; returns 0 for a zero count. Invoked by VTableDispatchWithConditionalBranch (0x00585400).
- `0x00586E50` **UnknownObject** — Partial struct copy from a2 to this: copies the leading DWORDs at offsets 0x0/0x4 and trailing DWORDs at 0x4C/0x50, and between them runs BufferWriteWithParams (0x00587620) on the buffer sub-struct at a2+2 and sub_59B3B0 on the sub-struct at a2+5; returns this. Invoked by sub_5853B0 (0x005853B0).
- `0x00587070` **UnknownObject** — Scalar-deleting-destructor-style routine on an unknown object: re-installs the object vtable and runs an init step via SetVtablePointerAndCallInit (0x005870D0), then frees the object via FreeWrapper_7bcf only when the low bit of the destructor flag a2 is set; returns the object pointer unchanged.
- `0x00587100` **UnknownObject** — Negated-predicate wrapper: calls MemcpyLikeWithRealloc(a1, a2), truncates its result to an unsigned byte and returns TRUE when the byte is zero. Called by NetworkFileTransferAcceptHandler (0x0058119A) as a condition on the network file-transfer accept path.
- `0x00587120` **UnknownObject** — Buffer-copy helper on a __thiscall object: reads the requested size from *a3, requires FieldAccessor(this+1) to exceed it, then uses BufferQueryReturnPtrSizeIfValid(&v7, &a3) to obtain a source pointer and available size; copies min(*a3, available) bytes into *a2 on success (storing the copied size back) and returns 0, else nulls *a2/*a3 and returns 1.
- `0x005871C0` **UnknownObject** — Queries two values derived from the object at this+1 and stores them into two output pointers: the element count from sub_563E70 into *a2 and the field value from FieldAccessor into *a3; always returns 0. Sole recorded caller is IterateTriggersViaVtableCallHandlersPerTick (0x00585BF0).
- `0x00587200` **UnknownObject** — Trivial thiscall byte setter: stores char a2 into the byte field at offset 0x18 of this and returns a2 unchanged. Single caller sub_580DE0 (0x00580DE0).
- `0x00587220` **UnknownObject** — Pure getter: returns the dword at this+0x10 (this[4]). No calls, guards or side effects; one caller is on the trigger iteration path but the field role is not established.
- `0x00587310` **UnknownObject** — Parses a binary packet whose leading WORD encodes the payload size minus 11: on non-zero size the payload is copied through MemcpyLikeWithRealloc, then two DWORDs and one BYTE are read from the payload tail and stored into this+0x10, this+0x14 and this+0x18; returns 1 on success, 0 on an empty packet or failed copy.
- `0x00587490` **UnknownObject** — Zero-initializes the leading three dwords of the struct (this+0x0/0x4/0x8), then optionally copies a validated source buffer into the object via MemcpyLikeWithRealloc when BufferQueryReturnPtrSizeIfValid reports the buffer valid; returns this. Used as a copy-construct/parse step by ObjectCopyConstructFromSource (0x00587090).
- `0x00587620` **UnknownObject** — Buffer write helper: copies the payload described by parameter object a2 (source pointer at a2+0, byte count at a2+8) into destination buffer this via MemcpyLikeWithRealloc, growing/reallocating as needed; returns this. Callers are NetworkBufferSearch (0x00581600), ShortComputation_6e50 (0x00586E50) and CopyBufferHeaderFieldsCallInit (0x00587370).
- `0x005876F0` **BufferedIOObject** — BufferedIOObject initializer: sets the dword field at this+0x410 to the sentinel -1 and the dword at this+0x414 to 0, then calls FieldConstantsInitialization (0x005879F0) to seed the buffer constant fields; returns this. Invoked from sub_5837F0 (0x005837F0).
- `0x00587880` **BufferedIOObject** — Trivial __thiscall getter: reads and returns the dword at this+0x400 (this[256]); no side effects. Called by sub_587730 (0x00587730) and sub_5878A0 (0x005878A0) to read the BufferedIOObject state field.
- `0x005879F0` **BufferedIOObject** — Straight-line initializer that resets the BufferedIOObject buffer-state fields: zeroes this+0x400, this+0x404 and this+0x408, writes the constant 500 to this+0x40C, and returns 0. Called by BufferedCharIOInit (0x005876F0) and sub_5878A0 (0x005878A0).
- `0x00587B7F` **UnknownObject** — CRT initialization stub with three unconditional subroutine calls: runs InitCRTFloatConversionFunctionPointers (0x00587B97), stores the return of sub_58BCA6 into global dword_8D3E44, runs TwoArgCallWrapper (0x0058BC56), clears pending x87 FPU exception flags with fnclex, and returns the TwoArgCallWrapper result.
- `0x00587B96` **UnknownObject** — Empty no-op stub (nullsub): the body is empty, so it performs no work and has no observable effect; it exists only as a referenced placeholder. Callers TwoIterationCleanup (0x00516853) and RenderVTableObjectInit (0x00516883) are outside this packet.
- `0x00588212` **UnknownObject** — Floating-point exponentiation (x87 FYL2X based) with IEEE 754 edge cases: validates an argument marker, special-cases NaN/infinity and zero operands, dispatches the finite case to sub_58DE2C under fsave/frstor, runs X87FPExponentiation (0x0058DCA0) for the general case, and reports math errors through the handler at 0x005E63B8 or the default wrapper (0x0058DC40) when the flag dword_8D3E40 is clear; zero/infinity results come from the 80-bit constants at 0x005E6BF0 and 0x005E6C50.
- `0x005883E5` **UnknownObject** — Double-precision roundedness check on an x87 stack value (a1 in st0): preserves it to _ST6, rounds in place with frndint, and when the rounded value equals the original (a1 is already an integer) scales by the global double at 0x005E63B0 and rounds again; the result stays in x87 state. Called on the frame path by sub_588212 (0x00588212).
- `0x00589C77` **UnknownObject** — Module-level initializer called by sub_58A19E: calls the function pointer at off_5E63A4 when non-null, then runs UtilityFunction_9d7d (0x00589D7D) twice over two adjacent data ranges (unk_5BE3C0..unk_5BE3D8 and unk_5BE000..unk_5BE3BC) and returns the second range call's result. Callee 0x00587B7F is in the packet callee list but has no call site in the body.

## Proposed classes

### EventTimerManager

Timer-list manager with two timer-node list controls (this+0x57C and a second at this+0x598) whose node deadlines (node+0x4C) are decremented each tick by a millisecond budget; expired nodes are unlinked, cleaned, freed and appended to a free list. Per-list walk mutexes (this+0x58C / timeout this+0x590) and an append mutex at this+0x570 guard the structure.

Methods: `0x00583F50`

- `this+0x00000570` `pointer append_mutex` (read_write, DERIVED)
- `this+0x0000057C` `pointer timer_list_control_1` (read_write, DERIVED)
- `this+0x0000058C` `pointer list_walk_mutex` (read_write, DERIVED)
- `this+0x00000590` `unsigned int list_walk_timeout_ms` (read, DERIVED)

### TimerListControl

Timer list control block at this+0x57C: head at +0, tail at +4 and iterator/count at +8, with each linked node carrying its deadline ticks at +0x4C. GUESS record; the second list control at this+0x598 and its related fields are not in the packet evidence set.

Methods: 

- `*(this+0x57C)+0x00000000` `pointer list_head` (read_write, GUESS)
- `*(this+0x57C)+0x00000004` `pointer list_tail` (read_write, GUESS)
- `*(this+0x57C)+0x00000008` `int list_count` (read_write, GUESS)
- `*(*(this+0x57C)+0x0)+0x0000004C` `int deadline_ticks` (read_write, GUESS)

### MutexObject

Mutex wrapper object holding an unnamed Win32 mutex handle at this+0x4 and a byte validity flag at this+0xC. The single packet method conditionally closes the old handle and creates a fresh unnamed mutex via CreateMutexA, setting the flag on success.

Methods: `0x00586500`

- `this+0x00000004` `pointer mutex_handle` (read_write, DERIVED)
- `this+0x0000000C` `byte valid_flag` (read_write, DERIVED)

### MutexSynchronizationObject

Mutex synchronization object whose layout keeps the OS mutex handle at this+0x50, the wait timeout at this+0x54 and a ready flag byte at this+0x58. The three packet methods create-or-replace the mutex (0x005862C0), wait on it (0x00585F60) and release it (0x00585F90), all invoked by the same owner routine 0x005837F0. GUESS merge: the packet labels these owners UNKNOWN but the shared handle offset and the common caller are the grouping evidence.

Methods: `0x00585F60`, `0x00585F90`, `0x005862C0`

- `this+0x00000050` `pointer mutex_handle` (read_write, GUESS)
- `this+0x00000054` `unsigned int wait_timeout_ms` (read, GUESS)
- `this+0x00000058` `byte ready_flag` (read_write, GUESS)

### LinkedNodeRecord

12-byte linked-list node record used by the teardown/removal paths: data pointer at +0, next pointer at +4 and an ownership flag byte at +8. Layout established by 0x00586670 (explicit node record) and confirmed by the identical node shape drained by 0x00586070.

Methods: 

- `obj+0x00000000` `pointer data_ptr` (read_write, GUESS)
- `obj+0x00000004` `pointer next_ptr` (read_write, GUESS)
- `obj+0x00000008` `byte ownership_flag` (read_write, GUESS)

### LinkedNodeContainer

Singly-linked container with head at this+0x0, tail at this+0x4, traversal cursor at this+0x8 and node count at this+0xC, storing 12-byte LinkedNodeRecord nodes. The single packet method removes a node by its data pointer and conditionally releases the payload.

Methods: `0x00586670`

- `this+0x00000000` `pointer list_head` (read_write, GUESS)
- `this+0x00000004` `pointer list_tail` (read_write, GUESS)
- `this+0x00000008` `pointer current_cursor` (read_write, GUESS)
- `this+0x0000000C` `int node_count` (read_write, GUESS)

### DoubleListOwner

Object owning two linked lists rooted at this+0x10 (first) and this+0x0 (second), each with four root fields zeroed on drain. The destructor walks 12-byte LinkedNodeRecord nodes, frees payloads when the ownership flag byte is set, and drives an SEH-protected callback loop (NTimeCallbackLoopWithSEH with the handler table at 0x0059D120) on the second list's inner objects. The second list root layout matches LinkedNodeContainer but common ownership is not proven.

Methods: `0x00586070`

- `this+0x00000000` `pointer second_list_head` (read_write, GUESS)
- `this+0x00000004` `pointer second_list_field` (read_write, GUESS)
- `this+0x00000008` `pointer second_list_field` (read_write, GUESS)
- `this+0x0000000C` `pointer second_list_field` (read_write, GUESS)
- `this+0x00000010` `pointer first_list_head` (read_write, GUESS)
- `this+0x00000014` `pointer first_list_field` (read_write, GUESS)
- `this+0x00000018` `pointer first_list_field` (read_write, GUESS)
- `this+0x0000001C` `pointer first_list_field` (read_write, GUESS)

### BufferedIOObject

Buffered char-IO object whose state block spans this+0x400..0x414: three zeroed state dwords at +0x400/0x404/0x408, a default capacity constant 500 at +0x40C, and a tail marker pair at +0x410 (-1 sentinel) / +0x414 (0). The initializer (0x005876F0) seeds the tail fields and delegates constant seeding to FieldConstantsInitialization (0x005879F0), which is shared with sub_5878A0; the getter 0x00587880 reads the +0x400 state dword. GUESS merge: the packet keeps these owners UNKNOWN; grouping is the shared field block and the 0x005876F0 -> 0x005879F0 call edge.

Methods: `0x005876F0`, `0x00587880`, `0x005879F0`

- `this+0x00000400` `int state_dword_0` (read_write, GUESS)
- `this+0x00000404` `int state_dword_1` (write, GUESS)
- `this+0x00000408` `int state_dword_2` (write, GUESS)
- `this+0x0000040C` `int default_capacity` (write, GUESS)
- `this+0x00000410` `int tail_marker` (write, GUESS)
- `this+0x00000414` `int tail_position` (write, GUESS)

## Compatibility contracts

- **MutexProtectedSlotRecordContract** — The 40-byte slot record read path must keep the protected byte at +12, the mutex handle at +16 and the wait timeout (ms) at +20; a read acquires the per-slot mutex via WaitForSingleObject with that timeout, authorizes the read for wait results 0 or 128, re-reads the handle from +16 and releases it via ReleaseMutex, and returns the protected byte.
- **TimerListContract** — The EventTimerManager tick must walk two timer-node lists (controls at this+0x57C and this+0x598) with per-list mutexes (this+0x58C, timeout this+0x590), decrement each node deadline at node+0x4C by CRTFtol(a2*1000+0.5), and on expiry unlink the node (updating head/tail/count at control +0/+4/+8), clean it via ConditionalListNodeCleanup, free it via FreeWrapper_7bcf, and append it to a free list under the append mutex this+0x570 with a 1 ms wait.
- **MutexHandleLifecycleContract** — Mutex wrapper objects pair a handle slot with a byte ready flag. Create-or-replace (0x005862C0, 0x00586500, 0x00586560, 0x005865C0) conditionally CloseHandle's the old handle when the flag is set and the slot is cleared, then creates an unnamed mutex via CreateMutexA with a SECURITY_ATTRIBUTES block (nLength=12, no descriptor, inheritable), stores the handle, sets the flag on a non-null result and returns the flag. Waiters (0x00585F60) and releasers (0x00585F90) must not touch a null handle, and ReleaseMutex is only called for a non-null handle.
- **NodeTeardownContract** — Linked-list nodes store their data pointer at +0, next pointer at +4 and an ownership flag byte at +8. Teardown (0x00586070, 0x00586670) must free the payload only when the flag is set and the data pointer is non-null, running EmptyStub_0170 before the payload free and then freeing the node itself via FreeWrapper_7bcf; after a list is drained its root fields (head/tail/count) are zeroed.
- **ReallocatingBufferCopyContract** — Buffer copies must preserve the destination-grows semantics of MemcpyLikeWithRealloc (0x00587510): the buffer write helper copies source pointer (a2+0) and byte count (a2+8) into the destination and returns it; BufferQueryReturnPtrSizeIfValid (0x00587580) validates a source buffer before the struct-init and buffer-copy paths proceed; the copy amount is the smaller of the requested and available sizes.
- **BinaryPacketTailFieldContract** — A binary packet whose leading WORD encodes the payload size minus 11 must, on a non-zero size, have its payload copied through MemcpyLikeWithRealloc; the three tail fields (two DWORDs and one BYTE) are then read from the payload region and stored into this+0x10, this+0x14 and this+0x18 respectively, returning 1 on success and 0 for an empty packet or failed copy.
- **BitmapRangeOccupancyContract** — Range occupancy queries must read a range descriptor (start WORD + count WORD) from the array at this+0x1C indexed by this+0x34, test each position of the range against the packed bitmap at this+0x14 (bit index ((end-pos) & 7) within byte ((end-pos) >> 3) at this[5]), accumulate a per-position bitmask, and return 0 when the count WORD is zero.

## Unresolved

- 0x00583D40 (MutexProtectedDataReadWithTimedWait): when the mutex handle is null or the wait fails, the read pointer is null yet the decompiled body reads through it; the original guard avoiding that path is not visible. The packet labels wait result 128 'WAIT_TIMEOUT' here but 'WAIT_ABANDONED' in 0x00584DD0/0x00584F30/0x00585F60; the constant name is inconsistent across the packet and the consumer contract for a timed-out read is unknown.
- 0x00583F50 (LinkedListTimerTickWithExpiryCheck): the second timer-list control at this+0x598 and its append mutex at this+0x544 are used in the body but absent from the packet field evidence; this+0x580/0x584/0x588 and the dereferenced fields of *(this+0x584) are reported by deterministic facts but not visible in the decompiled body; the free-list target and the second argument 0 of LinkedListNodeAppend_6000 are unconfirmed.
- 0x00584DD0 (MutexGuardedListAppend): the this+0x570/0x574 mutex-guard pair matches the EventTimerManager append-mutex fields, but common ownership is not proven by the packet, so 0x00584DD0 is not merged into EventTimerManager.
- 0x00584F30 (AppendToMutexGuardedListWithWait): the same handle is waited on and released as a mutex while the append operates on the adjacent list object; the owner relationship between this+0x5A8 and the list is not evidenced; the append flag third argument to LinkedListNodeAppend_6000 is unexplained.
- 0x00586070 (DestroyDoubleLinkedListWithSEHCleanup): the first list's nodes are freed after an EmptyStub_0170 call while the second list's nodes wrap an inner object drained by NTimeCallbackLoopWithSEH (size 1048, SEH handler table 0x0059D120); the element semantics of the two lists are inferred from the differing teardown paths; the next-node link is read from the node's second dword, which the packet does not list as a tracked field; the second-list root layout matches LinkedNodeContainer but 0x00586070 is kept as DoubleListOwner because common ownership is unproven.
- 0x005862C0 / 0x00586500 / 0x00586560 / 0x005865C0: the byte globals 0xFF00000000005450..452 are decompiler byte-aliases of the DWORD handle writes (per the packet's own unresolved notes for 0x00586560/0x005865C0) and carry no independent meaning; 0x00586560 and 0x005865C0 are structurally identical create-or-replace wrappers with different offsets and are left under UnknownObject because a shared class would require merging unequal layouts.
- 0x00586670 (RemoveListNodeByData): the data pointer is stored at node offset 0 but the packet provides no field evidence ref for obj+0x0 (referenced through source:raw only); the purpose of the container cursor this+0x8 (advanced to the matched node's successor) is unknown; EmptyStub_0170 is called with no observable arguments; node field obj+0xC is never accessed in the raw source.
- 0x00586D00 (BitmapRangeOccupancyTestViaBitOps): the semantics of the range descriptor and bitmap are caller-defined; the identity of the owning object and the type of the descriptor table at this+0x1C are unknown.
- 0x00587620 (BufferWriteWithParams): the parameter object layout (source pointer at +0, byte count at +8) is evident only from the single dereference; the exact realloc trigger and source ownership of MemcpyLikeWithRealloc are not in this packet.
- 0x005876F0 / 0x00587880 / 0x005879F0 (BufferedIOObject GUESS merge): the packet keeps these owners UNKNOWN; grouping rests on the shared this+0x400..0x414 field block and the 0x005876F0 -> 0x005879F0 call edge; the exact roles of the tail fields at 0x410/0x414 are not defined; FieldConstantsInitialization is invoked without visible arguments in the raw source.
- 0x00587B7F (InitWrapperCalling3Subroutines): the consumer of dword_8D3E44 is not in the packet; why fnclex is issued and what x87 exception state is cleared is undocumented; TwoArgCallWrapper's role is CRT-defined.
- 0x00588212 (FPUExponentiationWithEdgeCases): sub_58DD89 (the math-error reporter taking the handler at 0x005E63B8) is not in the packet callee list and is only visible in raw source; several decompiler flags (v10, v12, v17/v18, v13/v14) are uninitialized register reads making some branch semantics uncertain; the argument marker 639 and the negative-base rounding behavior are not established.
- 0x00589C77 (InitializeDataRanges): callee 0x00587B7F appears in the packet callee list but has no call site in the body (parked in unresolved_evidence_refs); the role of the off_5E63A4 callback and the exact semantics of UtilityFunction_9d7d over the two global data ranges are not proven.
- 0x00583A80 / 0x00587070 (scalar deleting destructors): the concrete type of this is unknown; whether the real destructors (sub_583AE0, SetVtablePointerAndCallInit 0x005870D0) perform additional teardown is unproven.
- General: no evidence in this packet establishes runtime truth; every class other than the two DERIVED owners (EventTimerManager, MutexObject) is a GUESS proposal, and equal byte offsets on unrelated this pointers are not treated as proof of identical classes.
- General: the Win32 IAT slot addresses (0x0059E1A0 WaitForSingleObject, 0x0059E1A4 ReleaseMutex, 0x0059E1A8 CloseHandle, 0x0059E1AC CreateMutexA) are used as globals per the packet's own evidence; the kernel API names are descriptive only.
