# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Reconstructs the generic runtime object layer from 29 validated functions. A DERIVED ConstraintForceAccumulator (0x0056EE40) accumulates angular momentum and force contributions from wheel, suspension and constraint body groups (counts this+0x8/0x10/0x18, arrays this+0xC/0x14/0x1C, shared state vector this+0x2C) via AccumulateAngularMomentum (0x00569AD0) and F_3DVectorSubtractWithCrossProduct (0x00569B70). A DERIVED NetworkConnectionManager (0x0057D8D0 packet send with query matching, 0x0057DD40 connection lookup and update) guards a connection list with mutex this+0xABC; connection nodes carry two address-family/port pairs (modelled as GUESS NetworkConnectionNode). A DERIVED NetworkSocket (0x0057E860 UDP bind, 0x0057E8D0 local IP query) persists a 16-byte socket-address context and dispatches between query-matching and direct bind paths. Two GUESS mutex-protected list structures share identical field layouts with the manager: MutexProtectedLinkedList (0x0057C950 index lookup with 16-byte copy, 0x0057E3A0 callback drain; head this+0xAC8, mutex this+0xAD8) and NetworkMessageQueue (0x0057EA30 keyed dequeue, 0x0057EAD0 packet aggregation; head this+0xB00, mutex this+0xB10). GUESS containers cover IntrusiveList (0x0057B050 node remove and free), IntSet (0x0057B230 deduplicating insert), DynamicSolverObject (0x0057AEF0 two-list cleanup with vtable swap), DynamicsObj (0x0057B780/0x0057B7D0/0x0057B7F0, all installing vtable off_5B8A64), PhysicsObject (0x0057A160, vtable off_5B8A00) and VTableOwnedObject (0x0057A4C0 destruct via vtable slots 0x44/0x4C). Eight functions stay unowned (0x0056F090, 0x0057A020, 0x0057A0F0, 0x0057A420, 0x0057B6C0, 0x0057B800, 0x0057B820, 0x0057BCC0, 0x0057D5D0, 0x0057EA10, 0x0057EC10, 0x0057EF20).

## Function roles

- `0x0056EE40` **ConstraintForceAccumulator** — Accumulates angular momentum and force contributions from constraint rows across three body groups (wheel array this+0xC, suspension array this+0x14, constraint array this+0x1C, each with its own count) by reading per-body state from the shared state vector this+0x2C and applying scaled 3D vectors into paired body force/impulse accumulator slots via AccumulateAngularMomentum and F_3DVectorSubtractWithCrossProduct. Returns the constraint count this+0x18.
- `0x0056F090` **UnknownObject** — Iterates the array of 580-byte-strided body records at this+0x4 under the count at this+0x0, evaluates sub_569DE0 for each body, and returns the minimum returned value, defaulting to 1.0 (double constant dbl_59E420) when the count is not positive.
- `0x0057A020` **UnknownObject** — Struct zero-initializer writing 0 to the dwords at this+0x0, this+0x4, this+0x8 and this+0xC, then zeroing the following 0x20-byte block starting at byte offset 0x10, and returning this. Used as an object init helper by sub_5837F0.
- `0x0057A0F0` **UnknownObject** — Offset-based self-copy of 48 bytes: computes the source address as this + (a2 - this) and copies bytes one at a time into this[0..15] and this[16..47], returning this. Called from AllocationWrapper (0x00585030). Canonical ABI label ByteAlignedMemoryCopyWithOffset.
- `0x0057A160` **PhysicsObject** — Constructor that installs the vtable pointer off_5B8A00 at this+0x0, then calls SmallStructFieldInit (0x0057A1E0) to initialize the remaining struct fields, and returns this. Existing analysis labels the vtable PhysicsVtable (DERIVED, not packet-confirmed).
- `0x0057A420` **UnknownObject** — Allocates and initializes a network socket object into the output slot *this with a caller-visible error flag *a3. Rejects (error=1, *this=0) when *a2 is greater than 1; otherwise allocates 3064 bytes via OperatorNewNhMallocWrapper and initializes through sub_57BA10. On init failure invokes the vtable destructor at object offset 68 and nulls *this.
- `0x0057A4C0` **VTableOwnedObject** — Vtable-scoped destruct and null: reads the object pointer stored at this+0x0 and, when non-null, calls the vtable entry at offset 0x4C (slot 76) to destruct the object, then calls the vtable entry at offset 0x44 (slot 68) with flag 1, nulls this+0x0, and returns the destructor result. Shared teardown helper for sub_57AA80, sub_57AB50 and sub_57ACB0.
- `0x0057AEF0` **DynamicSolverObject** — Cleanup of an object holding two embedded singly-linked lists: sets the vtable to off_5B8A1C, walks list A (head this+0x18) freeing each node and its data pointer when the node flag byte at node+8 is set, zeroes this[6..9], walks list B (head this+0x8) the same way, zeroes this[2..5], and sets the vtable to off_5B8A40. Single caller is FlaggedDestructor (0x00583150).
- `0x0057B050` **IntrusiveList** — Removes the first node whose stored data equals a2 from a singly-linked list (head this+0x8, tail this+0xC, secondary tail this+0x10, count this+0x14), unlinks it, decrements the count, and frees the node (and its data when the node flag byte at +0x8 is set) via FreeWrapper_7bcf. Returns 1 on success, 0 on null key, null head, or no match.
- `0x0057B230` **IntSet** — Set insertion with deduplication: linearly scans the integer set stored as a linked list rooted at this+0x18. When a2 is already present returns 1; otherwise allocates a 4-byte cell, stores a2, appends a node via LinkedListNodeAppend_6000 with flag 1, and returns 0.
- `0x0057B6C0` **UnknownObject** — Trivial thiscall setter storing a2 into the dword field at this+0x24 and returning a2. Field meaning unknown; callers are 0x0057DD40 and 0x00580DE0.
- `0x0057B780` **DynamicsObj** — Object initializer that delegates base vtable chain and initial field defaults to ObjectInitWithVTableSetup (0x00587030) with a2/a3/a4, installs the vtable pointer off_5B8A64 at this+0x0, and zeroes the dword at this+0x1C. Returns this.
- `0x0057B7D0` **DynamicsObj** — Copy-init with vtable setup: invokes ObjectCopyConstructFromSource (0x00587090) to copy-construct from a2, installs the vtable pointer off_5B8A64 at this+0x0, zeroes the dword at this+0x1C, and returns this. Called by sub_5813E0.
- `0x0057B7F0` **DynamicsObj** — Constructor tail (__thiscall) storing the address of global off_5B8A64 into this+0x0, then tail-calling a further init routine whose target address is absent from the packet callees. Existing analysis labels off_5B8A64 as the DynamicsObj vtable (DERIVED).
- `0x0057B800` **UnknownObject** — Initializer that delegates to CopyBufferHeaderFieldsCallInit(a2) (0x00587370) and then copies one dword from a2+28 into this+0x1C, returning this. Structurally a twin of FieldSetterTrigger (0x0049ED00) per the cluster prelabel.
- `0x0057B820` **UnknownObject** — Minimal init routine forwarding a2 unchanged to CopyBufferHeaderFieldsCallInit (0x00587370) and returning this without reading or writing any field. Called by sub_5813E0.
- `0x0057BCC0` **UnknownObject** — Deleting-destructor pattern: runs the object cleanup helper sub_57BCE0, then frees the object via FreeWrapper_7bcf when the low flag bit of a2 is set, and returns the object pointer.
- `0x0057C950` **MutexProtectedLinkedList** — Mutex-protected list lookup by index with a 16-byte data copy. With index pointer a4 non-null, acquires the mutex at this+0xAD8, bounds-checks against the count at this+0xAD4, walks the list from the head at *(this+0xAC8) to the index-th node, transforms the node data pointer at +0x1C via sub_4B3DB0, and copies the transformed structure's first 16 bytes into a2. With a4 null, copies the cached WORD at this+0x910 into a2+2 and writes -1 at a2+4.
- `0x0057D5D0` **UnknownObject** — Builds a structured packet in the output buffer: writes a header word (byte count computed as ceil(bits/8) from the bit count at source+0x24), a second header word via FieldAccessor, copies the payload from source+0x14, then appends a further copy using the adjusted pointer/size pair from BufferQueryReturnPtrSizeIfValid. Always returns 1.
- `0x0057D8D0` **NetworkConnectionManager** — Builds a structured packet for a2 via StructuredMemoryCopyWithHeaderPrepend into a 770-word buffer and computes length from the buffer header words. With a3 non-null, acquires the connection-list mutex this+0xABC, locates the node matching a3's query (exact field match or sub_57DB80 fallback), and send()s the packet to that node's socket. With a3 null, walks all connection nodes and send()s to each whose fields match the query list at a2+0x48.
- `0x0057DD40` **NetworkConnectionManager** — Acquires the mutex-protected connection list (mutex this+0xABC, timeout this+0xAC0), walks entries comparing two stored address-family/port pairs against the caller's a2 values, and on a match calls SetterAt0x24 (0x0057B6C0) to update the matched node and writes offset 28 of a caller-known target. Returns 1 on match/update, 0 otherwise, always releasing the mutex.
- `0x0057E3A0` **MutexProtectedLinkedList** — Mutex-guarded callback queue drain: acquires the mutex at this+0xAD8 (timeout this+0xADC), walks the callback list headed at this+0xAC8 invoking CounterIncrementDecrementByFlag(0) per entry with the cursor this+0xAD0, then releases the mutex. Called from sub_57E280.
- `0x0057E860` **NetworkSocket** — UDP socket bind entry point: builds a 16-byte sockaddr_in (AF_INET=2, INADDR_ANY, port 0), copies it into the persistent socket-address context via Copy4DwordsStructToStruct, then dispatches on sub_586CA0(a2): non-zero selects the query-matching bind path NetworkPacketSendWithQueryMatching(this, a2, v4), otherwise the direct bind path sub_57D6C0(this, a2, v4).
- `0x0057E8D0` **NetworkSocket** — Returns the local IP as a dotted-decimal string: initializes an in_addr via htonl(0), copies the 16-byte network context from this+673 into a local buffer, converts with inet_ntoa, copies the result into the output buffer through sub_587DD0 with limit a3-1, and null-terminates. Returns 1 on success, 0 if inet_ntoa fails.
- `0x0057EA10` **UnknownObject** — Audio subsystem update wrapper forwarding the per-frame float a2 to sub_57E0A0 and sub_57E280 on the same instance, then always returning 1. The wrapped callees carry the actual audio processing.
- `0x0057EA30` **NetworkMessageQueue** — Mutex-protected search of a singly linked message queue (head this+0xB00) for the first node whose data key equals htonl(0); on match copies the node data second dword to *a2 and returns 1, otherwise 0. The mutex at this+0xB10 is released on every path that acquired it.
- `0x0057EAD0` **NetworkMessageQueue** — Mutex-protected network packet aggregation/queueing: computes the key htonl(0), acquires the mutex at this+0xB10, searches the list at this+0xB00 for a matching data node and updates its latest-value field, or allocates a 16-byte data node and a 12-byte list node and links it at the tail (updating head/tail/cursor/count). Every call accumulates a2 into the data node sum field and increments its counter, then releases the mutex and returns 1.
- `0x0057EC10` **UnknownObject** — Two-phase mutex-protected lookup bridging two linked lists. Phase 1 walks the first list (head this+0xAC8) to index a2 under mutex this+0xAD8 and derives an id from the node data+0x1C via sub_4B3DB0. Phase 2 searches the second list (head this+0xB00) under mutex this+0xB10 for a node whose data[0] equals the id and stores data[1] into *a3. Returns 1 when a match is stored, otherwise 0.
- `0x0057EF20` **UnknownObject** — SEH-wrapped constructor allocating a 32-byte block via OperatorNewNhMallocWrapper and, on success, initializing it through ObjectInitWithVTableFieldSet(ptr, 0, 0, 0); returns the object or null on allocation failure.

## Proposed classes

### ConstraintForceAccumulator

Physics constraint force accumulator walking three body groups (wheel array this+0xC, suspension array this+0x14, constraint array this+0x1C) with per-group counts (this+0x8, this+0x10, this+0x18) and combining entries from the shared per-body state vector (this+0x2C) into paired body force/impulse accumulator slots via AccumulateAngularMomentum (0x00569AD0) and F_3DVectorSubtractWithCrossProduct (0x00569B70). The single method returns the constraint count.

Methods: `0x0056EE40`

- `this+0x00000008` `int wheel_body_count` (read, GUESS)
- `this+0x0000000C` `void* wheel_body_array` (read, GUESS)
- `this+0x00000010` `int suspension_body_count` (read, GUESS)
- `this+0x00000014` `void* suspension_body_array` (read, GUESS)
- `this+0x00000018` `int constraint_count` (read, GUESS)
- `this+0x0000001C` `void* constraint_array` (read, GUESS)
- `this+0x0000002C` `float* shared_state_vector` (read, GUESS)

### PhysicsObject

Object whose constructor (0x0057A160) installs the vtable off_5B8A00 at this+0x0 and delegates remaining field initialization to SmallStructFieldInit (0x0057A1E0). Existing analysis labels the vtable PhysicsVtable; that label is DERIVED, not packet-confirmed.

Methods: `0x0057A160`

- `this+0x00000000` `void* vtable` (write, GUESS)

### NetworkConnectionManager

Mutex-protected connection-list manager holding the list control block (this+0xAAC), traversal cursor (this+0xAB4), control block (this+0xAB8), list mutex (this+0xABC) and wait timeout (this+0xAC0). NetworkPacketSendWithQueryMatching (0x0057D8D0) builds a structured packet and send()s it to a matching node or broadcasts to all matching nodes; FindConnectionByAddressAndUpdate (0x0057DD40) locates a node by two stored address-family/port pairs and updates it. Connection node records are modelled separately (NetworkConnectionNode).

Methods: `0x0057D8D0`, `0x0057DD40`

- `this+0x00000AAC` `void* list_control_block_ptr` (read, GUESS)
- `this+0x00000AB4` `void* traversal_cursor` (read_write, GUESS)
- `this+0x00000AB8` `void* connection_list_control` (read, GUESS)
- `this+0x00000ABC` `void* list_mutex` (read, DERIVED)
- `this+0x00000AC0` `uint mutex_timeout` (read, DERIVED)
- `*(this+0xAAC)+0x00000000` `void* list_head` (read, DERIVED)
- `*(this+0xAB8)+0x00000002` `word aux_word_a` (read, GUESS)
- `*(this+0xAB8)+0x00000004` `dword aux_dword_a` (read, GUESS)
- `*(this+0xAB8)+0x00000012` `word aux_word_b` (read, GUESS)
- `*(this+0xAB8)+0x00000014` `dword aux_dword_b` (read, GUESS)

### NetworkConnectionNode

Data record for a network connection node as read through the manager list (base *(*(this+0xAAC)+0x0)): two stored address-family/port pairs at +2/+4 and +18/+20 used to match incoming queries. Layout inferred from comparison operands in the manager methods, not a named struct.

Methods: 

- `*(*(this+0xAAC)+0x0)+0x00000002` `word address_family_word` (read, GUESS)
- `*(*(this+0xAAC)+0x0)+0x00000004` `dword address_port_dword` (read, GUESS)
- `*(*(this+0xAAC)+0x0)+0x00000012` `word secondary_family_word` (read, GUESS)
- `*(*(this+0xAAC)+0x0)+0x00000014` `dword secondary_port_dword` (read, GUESS)

### NetworkSocket

Network socket wrapper around the UDP bind path. UDPSocketBind (0x0057E860) builds a 16-byte sockaddr_in (AF_INET, INADDR_ANY, port 0), persists it into the socket-address context, then dispatches to the query-matching bind (0x0057D8D0) or direct bind (sub_57D6C0) path. NetworkGetLocalIP (0x0057E8D0) reads the same 16-byte context (this+673) and returns the dotted-decimal local address; its membership here is inferred from that shared context (GUESS), as the packet owner for that function is UNKNOWN.

Methods: `0x0057E860`, `0x0057E8D0`


### MutexProtectedLinkedList

Mutex-guarded singly-linked list (head this+0xAC8, cursor this+0xAD0, count/current-node slot this+0xAD4, mutex this+0xAD8, timeout this+0xADC). LookupByIndexAndCopyData (0x0057C950) bounds-checks an index against the count and copies 16 bytes from the selected node's transformed data; MutexCallbackDispatch (0x0057E3A0) drains the list invoking a counter callback per entry. Node data id lives at node+0x1C; the node flag byte at node+8 is evidenced but not consumed by either method here.

Methods: `0x0057C950`, `0x0057E3A0`

- `this+0x00000AC8` `void* list_head_ptr` (read, DERIVED)
- `this+0x00000AD0` `void* traversal_cursor` (read_write, GUESS)
- `this+0x00000AD4` `void* count_or_current_node` (read, GUESS)
- `this+0x00000AD8` `void* list_mutex` (read, DERIVED)
- `this+0x00000ADC` `uint mutex_timeout` (read, DERIVED)
- `*(this+0xAC8)+0x00000000` `void* list_head` (read, DERIVED)
- `*(*(this+0xAC8)+0x0)+0x0000001C` `dword node_data_id` (read, GUESS)
- `*(this+0xAD4)+0x00000000` `dword node_data_dword` (read, GUESS)

### NetworkMessageQueue

Mutex-protected message queue (head this+0xB00, tail this+0xB04, cursor this+0xB08, count this+0xB0C, mutex this+0xB10, timeout this+0xB14). NetworkMessageQueueDequeue (0x0057EA30) searches for the first node whose data key equals the network-order zero key and returns its payload; QueueAggregatedNetworkPacket (0x0057EAD0) upserts a keyed data node and accumulates sum/counter fields. Keyed data node fields are read/written through base *(this+0xB04).

Methods: `0x0057EA30`, `0x0057EAD0`

- `this+0x00000B00` `void* queue_head_ptr` (read, DERIVED)
- `this+0x00000B04` `void* queue_tail_ptr` (read, DERIVED)
- `this+0x00000B08` `void* queue_cursor` (read, GUESS)
- `this+0x00000B0C` `uint node_count` (read, DERIVED)
- `this+0x00000B10` `void* queue_mutex` (read, DERIVED)
- `this+0x00000B14` `uint mutex_timeout` (read, DERIVED)
- `*(this+0xB04)+0x00000000` `dword data_key` (read, GUESS)
- `*(this+0xB04)+0x00000004` `dword data_latest_value` (read_write, GUESS)
- `*(this+0xB04)+0x00000008` `dword data_sum` (write, GUESS)
- `*(this+0xB04)+0x0000000C` `dword data_counter` (write, GUESS)

### IntrusiveList

Singly-linked intrusive list container rooted at this+0x8 (head), this+0xC (tail), this+0x10 (secondary tail/iterator) and this+0x14 (node count). LinkedListNodeRemoveAndFree (0x0057B050) unlinks the first node whose data pointer (+0x0) equals the key, rewires head/tail, decrements the count, and frees the node (and its data when the +0x8 flag byte is set). Node layout: data at +0x0, next at +0x4, flag byte at +0x8.

Methods: `0x0057B050`

- `this+0x00000008` `void* head` (read_write, GUESS)
- `this+0x0000000C` `void* tail` (read_write, GUESS)
- `this+0x00000010` `void* secondary_tail` (read_write, GUESS)
- `this+0x00000014` `uint node_count` (read_write, GUESS)
- `*(this+0xC)+0x00000000` `void* node_data_ptr` (read_write, DERIVED)
- `*(this+0xC)+0x00000004` `void* node_next` (read_write, DERIVED)
- `*(this+0xC)+0x00000008` `byte node_flag_byte` (read, GUESS)

### DynamicSolverObject

Object holding two embedded singly-linked lists and a swapping vtable. DynamicsSolverObjectCleanup (0x0057AEF0) sets the vtable to off_5B8A1C, frees list-A nodes (this+0x18..0x24, freeing node data when the flag byte is set), zeroes the list-A fields, frees list-B nodes (this+0x8..0x14) the same way, zeroes them, and sets the vtable to off_5B8A40. Single caller FlaggedDestructor (0x00583150).

Methods: `0x0057AEF0`

- `this+0x00000000` `void* vtable` (read_write, DERIVED)
- `this+0x00000008` `void* list_b_head` (read_write, GUESS)
- `this+0x0000000C` `void* list_b_tail` (write, GUESS)
- `this+0x00000010` `void* list_b_field3` (write, GUESS)
- `this+0x00000014` `void* list_b_field4` (write, GUESS)
- `this+0x00000018` `void* list_a_head` (read_write, GUESS)
- `this+0x0000001C` `void* list_a_tail` (write, GUESS)
- `this+0x00000020` `void* list_a_field3` (write, GUESS)
- `this+0x00000024` `void* list_a_field4` (write, GUESS)

### IntSet

Deduplicating integer set backed by a linked list rooted at this+0x18. IntSetInsert (0x0057B230) linearly scans nodes (value at +0x0, reached through this+0x1C) for the input value; if present returns 1, otherwise allocates a 4-byte cell, stores the value, appends a node via LinkedListNodeAppend_6000 with flag 1, and returns 0.

Methods: `0x0057B230`

- `this+0x00000018` `void* list_head` (read, DERIVED)
- `this+0x0000001C` `void* node_traversal_ptr` (read, GUESS)
- `this+0x00000020` `dword aux_unused` (read, GUESS)
- `*(this+0x1C)+0x00000000` `int node_value` (read_write, DERIVED)
- `*(this+0x1C)+0x00000004` `void* node_next` (read, GUESS)

### DynamicsObj

Object constructed with the vtable off_5B8A64 (labelled DynamicsObj by existing analysis) at this+0x0 and a dword field at this+0x1C zeroed after construction. ObjectInitWithVTableFieldSet (0x0057B780) delegates base setup to ObjectInitWithVTableSetup (0x00587030); CopyInitObjectWithVTable (0x0057B7D0) copy-constructs via ObjectCopyConstructFromSource (0x00587090); VTablePointerInit (0x0057B7F0) is the constructor tail storing the vtable and tail-calling a further init routine.

Methods: `0x0057B780`, `0x0057B7D0`, `0x0057B7F0`

- `this+0x00000000` `void* vtable` (write, DERIVED)
- `this+0x0000001C` `dword field_1c` (write, GUESS)

### VTableOwnedObject

Vtable-based ownership/teardown helper. DestroyObjectViaVtableAndNull (0x0057A4C0) loads the owned object pointer from this+0x0, calls the vtable destructor at slot 76 (obj+0x4C) and the operator-delete slot at slot 68 (obj+0x44) with flag 1 when still non-null, then nulls this+0x0. Shared teardown for callers sub_57AA80, sub_57AB50 and sub_57ACB0.

Methods: `0x0057A4C0`

- `this+0x00000000` `void* owned_ptr` (read_write, DERIVED)
- `obj+0x00000000` `void* vtable_ptr` (read, DERIVED)
- `*(obj+0x0)+0x00000044` `void* delete_slot` (read, GUESS)
- `*(obj+0x0)+0x0000004C` `void* destructor_slot` (read, GUESS)

## Compatibility contracts

- **ConstraintAccumulatorStateContract** — The force accumulator reads three body groups from the owning object: wheel bodies (count this+0x8, array this+0xC, 48-byte stride), suspension bodies (count this+0x10, array this+0x14, 48-byte stride) and constraints (count this+0x18, array this+0x1C, 72-byte stride), all against the shared per-body state vector at this+0x2C. Each body carries paired accumulator slots at body+24 and body+332; suspension rows read per-body coefficient offsets 72..112 and constraint rows use coefficient offsets 64/72/80. The function returns the constraint count.
- **NetworkConnectionMutexProtocol** — The connection list is guarded by the mutex at this+0xABC with the wait timeout at this+0xAC0; acquisition accepts WAIT_OBJECT_0 (0) or WAIT_ABANDONED (128) and the mutex is always released on paths that acquired it. Connection nodes are matched by two stored address-family/port pairs at node+2/+4 and node+18/+20. Outgoing structured packets carry header words such that the total length equals buf[1]+buf[0]+4 and are transmitted with send() to the matching socket.
- **MessageQueueAggregationLayout** — The message queue keeps head this+0xB00, tail this+0xB04, cursor this+0xB08, node count this+0xB0C, mutex this+0xB10 and timeout this+0xB14. Keyed data nodes are 16 bytes (key +0x0, latest value +0x4, accumulated sum +0x8, counter +0xC) linked by 12-byte list nodes; the queue key used is network-order zero (htonl(0)), consistent with address-like keys such as INADDR_ANY.
- **VtableSlotDestructorContract** — Objects in this scope carry a vtable pointer at +0 with a destructor slot at +0x4C (slot 76) and an operator-delete-style slot at +0x44 (slot 68) invoked with flag argument 1. The deleting-destructor pattern runs a cleanup helper then frees the object when the low bit of the flag argument is set. Teardown helpers null their stored pointer slot after destruction.
- **IntrusiveListNodeLayout** — Intrusive list nodes expose a data pointer at +0x0, a next link at +0x4, and a one-byte ownership flag at +0x8 that, when set, marks the node's data pointer as owned and freed alongside the node. Containers track head, tail, an optional secondary tail/iterator, and a node count.
- **SocketContextLayoutContract** — The network socket object persists a 16-byte socket-address context (this+0xA84, this+673 dwords) written through Copy4DwordsStructToStruct (0x0057B9F0). Bind constructs a sockaddr_in with AF_INET (2), INADDR_ANY and port 0, persists it, and dispatches to either the query-matching bind (0x0057D8D0) or the direct bind (sub_57D6C0) depending on sub_586CA0(a2).

## Unresolved

- Owner class names are worker-synthesized from packet DERIVED owner hints and shared field sets; none are CONFIRMED. The class groups DynamicsObj, PhysicsObject, IntrusiveList, IntSet, DynamicSolverObject, VTableOwnedObject, MutexProtectedLinkedList and NetworkMessageQueue are GUESS unions.
- Exact body struct layout in AccumulateConstraintImpulsesAndForces (body accumulator slots 24/332, suspension coefficient rows 72/80/88/96/104/112, constraint coefficient rows 64/72/80) comes from raw indexing; field semantics are DERIVED only.
- The semantic meaning of sub_569DE0's return value (penetration depth per the existing fill) is DERIVED prose, not deterministically established by this packet.
- The 580-byte-strided record element type in iterateAndFindMinimumValueFromFunction is unnamed; only the stride is evidenced. The double constant dbl_59E420 (1.0) beyond the initial values is not independently confirmed.
- The identity and owning class of the zeroed structure in ZeroInitStructFields (0x0057A020) are not evidenced; the purpose of the 0x20-byte trailing block is unknown.
- The ABI lead for SelfOffsetMemoryCopy48 records a FAIL legacy prototype; the real parameter convention (source pointer a2 vs absolute source) is not fully evidenced.
- The class identity behind vtable off_5B8A00 (labelled PhysicsVtable) and off_5B8A64 (labelled DynamicsObj) is DERIVED prose, not packet-confirmed.
- NetworkSocketObjectCreate (0x0057A420) object layout (vtable at 0, destructor slot at 68, 3064-byte body) is implied by the raw source; the concrete struct type is unknown.
- Whether the this+0x0 slot in DestroyObjectViaVtableAndNull is a unique-owned pointer or one member of a larger owner structure is unresolved; the semantics of the flag argument 1 passed to the vtable slot at offset 0x44 are not established.
- The offsets 0x8/0xC/0x10/0x14 at base this appear in both IntrusiveList and DynamicSolverObject; these are separate objects sharing list-layout conventions, not proven to be the same field. Rule: equal offsets on unrelated this pointers do not prove identical classes.
- Semantic roles of the zeroed dwords this[4]/this[5]/this[8]/this[9] in DynamicsSolverObjectCleanup and of the secondary tail/iterator at this+0x10 in LinkedListNodeRemoveAndFree are unknown.
- The purpose of the list-related field at this+0x20 in IntSetInsert is not expressed in the raw body; node bookkeeping (head/tail/count) is owned by LinkedListNodeAppend_6000 and not reconstructed here.
- The callback queue node layout (data dword at node+0x0, next link at node+0x4) in MutexCallbackDispatch is inferred from the traversal; the argument 0 passed to CounterIncrementDecrementByFlag and the role of each queued callback entry are not established.
- In LookupByIndexAndCopyData the raw body sets the list base to null when the mutex is absent or acquisition fails, yet the bounds check reads the count through that base; behavior when base is null is not resolvable from this function alone.
- In NetworkMessageQueueDequeue the ref at base *(this+0xB04) offset 4 is read as a list next-link while QueueAggregatedNetworkPacket writes it as a data-node latest-value field; the two node interpretations conflict and are unresolved.
- The connection node internal layout (next/tail pointers and the socket field located via OffsetGetter 0x0057B6B0) is inferred from list walks, not packet-confirmed; sub_57DB80 exact match criteria were not examined.
- The write to offset 28 after SetterAt0x24 in FindConnectionByAddressAndUpdate uses decompiler registers that are never assigned in this function; the concrete write target is unknown.
- The respective roles of the two address-family/port pairs (primary/secondary or IPv4/IPv6) and the selection criterion inside sub_586CA0 are not established.
- NetworkSocket membership of NetworkGetLocalIP (0x0057E8D0) is inferred from shared access to the socket-address context at this+673; the packet owner for that function is UNKNOWN.
- The persistent socket-address field this+0xA84 is not in the allowed evidence set and is therefore not modelled as a class field; whether it is consumed by later send/receive paths is unverified.
- The 16-byte context copied from this+673 in NetworkGetLocalIP, NetworkMessageQueueDequeue and QueueAggregatedNetworkPacket, and the output-buffer size semantics (copy limit a3-1), are not fully established.
- The packet flags globals byte_FF00000000005983, byte_FF00000000005990, SEH handler 0x0059C75B and SEH handler 0x0059CA1B as read, but they do not appear in the decompiled bodies; treated as exception-frame or decompiler artifacts.
- Queue ownership model and lifetime (who consumes or frees the queued nodes) and the meaning of the aggregated sum/counter fields as network statistics are inferred from the aggregation pattern, not independently evidenced.
- The tail-call target of VTablePointerInit (0x0057B7F0) has no address; the packet callees list is empty.
- The FieldSetterTrigger (0x0049ED00) structural-twin claim for ObjectInitWithFieldCopy (0x0057B800) is DERIVED cluster evidence, not independently confirmed here.
- lookupByIndexAcrossLists bridges two list types (this+0xAC8 and this+0xB00); the meaning of the derived id and the roles of data[0]/data[1] in the second list are not determined from this packet alone.
- Both linked-list node headers carry a one-byte flag at node+8 (evidenced for *(this+0xAC8)+8 and *(this+0xB00)+8); that byte is not read by lookupByIndexAcrossLists, so its role is unresolved.
- The second-list node fields evidenced only in lookupByIndexAcrossLists (head-node next link and data pairs) are not modelled as class fields; they are recorded in unresolved_evidence_refs because no owning class method in this packet consumes them directly.
- The cached WORD at this+0x910 used by the LookupByIndexAndCopyData fallback path has no documented meaning beyond the fallback value -1 written to a2+4.
- The exact semantics of the tail-call init after the vtable assignment in VTablePointerInit and the meaning of passed-through arguments a2/a3/a4 in ObjectInitWithVTableFieldSet are unknown.
- StructuredMemoryCopyWithHeaderPrepend callers (sub_57D6C0 and NetworkPacketSendWithQueryMatching) are recorded only as callee relationships from the calling side; the caller refs are not part of the allowed evidence set.
- The exact 16-byte output copy contract of sub_4B3DB0 (used by LookupByIndexAndCopyData and lookupByIndexAcrossLists) is outside this packet.
