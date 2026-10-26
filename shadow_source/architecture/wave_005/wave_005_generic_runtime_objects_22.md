# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Twenty-nine functions covering seven defensible object groupings plus a set of standalone helpers. (1) SessionReinitContainer: 0x563E00 tears down and rebuilds the session container's batch sub-struct and audio array (guard flag +0x0, batch +0x4, audio array +0x94, counter +0x98), called from StartNetworkUpdate. (2) NetworkTokenDispatcher / CallbackContextDispatcher: 0x564110 tokenizes a server path and routes 'ip'/'other' entries, 0x563EC0 selects a callback via a type switch and publishes the context to global 0x8D46B4, 0x564270/0x564390/0x5644F0 resolve/chain values through stored callback slots (+16 check, +12 dispatch) with error handling. (3) GrowableStructBuffer: 0x5648D0/0x564930/0x564A20 implement push/grow/index-search on a buffer with count/capacity/stride/growth-increment/base layout; 0x5648C0 is a thin forwarder to the push, 0x564890 is a per-item dispatch tail used by batch iteration. (4) Cleanup helpers with distinct layouts: 0x567940 (dual pointer), 0x568F20 (multi-field with companion dword zeroing), 0x56CF10 (quad pointer). (5) LinkedListContainer 0x567980 (node count walk) and LinearSearchContainer 0x56EAD0 (580-byte stride string search). (6) RigidBodyState 0x569C10: one a2-scaled Euler integration step with inertia-tensor transform. (7) ModuleRegistryList: 0x57ABB0 creates/registers a network-socket module node into the global doubly-linked list, 0x57ACB0 finds/removes it. Standalone: 0x563E70 field-0 getter, 0x5644A0 word getter, 0x579FF0 once-guarded static locale init, 0x57A1E0 small-struct initializer, 0x57A200 size-tagged buffer copy, 0x57A660/0x57A850/0x57A8C0 COM-style vtable-slot dispatchers (0x74/0x9C/0xA0/0xC0), 0x57A760 SEH-protected bounded copy. All owner identities are UNKNOWN at packet level; every class is a DERIVED or GUESS grouping and the callback/vtable slot semantics are inferred from dispatch patterns.

## Function roles

- `0x00563E00` **SessionReinitContainer** — Session reinitialization: if the initialized flag at this+0x0 is non-zero return 4 early; otherwise tear down the batch at this+0x4 via BatchLoopWithMemoryCleanup (0x564860), allocate a new 0x18-byte sub-struct whose inner-buffer callback is sub_5640F0 via 0x564810, destroy the audio array at this+0x94 via 0x564740, allocate a fresh typed array via 0x5646D0(4, 0x5645A0, 0x564600, 0x564630), reset this+0x98 to 0 and return 0. Called by StartNetworkUpdate (0x461DE0).
- `0x00563E70` **FieldZeroAccessor** — Trivial thiscall getter returning the 32-bit value at field 0x0 of this; no side effects. Called from twelve sites concentrated in network/system dispatch paths (StartNetworkUpdate 0x461DE0, ConditionalNetworkSystemDispatch 0x461F90, VehicleStateQueryAtLargeOffset 0x461FC0, NetworkConnection 0x563260 and related), suggesting a lightweight object state/identity query.
- `0x00563EC0` **NetworkTokenDispatcher** — Parameter-store and callback dispatch: select a callback via the jump table jpt_563EC9 on the type parameter a4 (case 0 selects 0x563F20, case 1 0x563F70, case 2 0x564000, default 0x564090), store a1[32]=a3 and a1[33]=a2, publish the context pointer a1 to global dword_8D46B4, dispatch through 0x564A00 with a1[1] as the callback-specific argument, and return the dispatch result.
- `0x005640F0` **AudioContainerSubStruct** — Unconditional teardown of a container/sub-struct: read the container pointer v1 = *(void**)this from this+0x0, free the audio array held at sub-struct offset +0xC via 0x564740, then free the container/sub-struct itself via sub_58AA6F.
- `0x00564110` **NetworkTokenDispatcher** — Tokenized server-entry parsing: allocate a target struct via StructAllocInitWithSwitchBasedType (0x5642F0, a4, a5), tokenize the path a3 on backslash via StringTokenizer (0x564220, a3+1, '\'); then iterate a2 entries against the lookup array a1: 'ip' entries (global 0x5E5050) parse the token as a network address via NetworkAddressParser (0x5642B0), a4==6 'other' entries (global 0x5E5048) rewrite 0x01 bytes to backslashes and run AudioMixerPollingUpdateLoop (0x564390), otherwise two singleton values are fetched via 0x564270 and dispatched through the function pointer at v6+12 via 0x564780; a null token falls back to byte_5EA438. Returns the allocated target struct v6.
- `0x00564270` **CallbackContextDispatcher** — Singleton/global accessor with heap-allocation fallback: save a2 into the byref slot v7, ask the callback stored at a1+16 via CallbackCheck (0x5647D0) whether a cached value exists; if so return *(v3); otherwise heap-copy the value with StringMallocCopy (0x564690), re-read the callback at a1+16 and install it through FunctionPointerCallWithErrorHandling (0x564780), returning the resulting value. Invoked by 0x564110 and 0x564390.
- `0x00564390` **CallbackContextDispatcher** — Settings-style string parser: tokenize a2+1 on delimiter 92 via StringTokenizer (0x564220); for each accepted token i (gated by 0x564410) read the following token (falling back to byte_5EA438 when absent), resolve both values through 0x564270 on a1, then dispatch a two-argument call through the function pointer at a1+12 via 0x564780. Shared helper of 0x563AB0 and 0x564110.
- `0x005644A0` **WordFieldAccessor** — Thiscall getter reading the 16-bit word at offset 0x4 of this (this[2]); pure read, no side effects. Called from 0x5631D0 and 0x563AB0 in audio-parameter search/dispatch paths.
- `0x005644F0` **CallbackContextDispatcher** — Indirect callback chain: run the callback stored at a1+16 via CallbackCheck (0x5647D0) with a local copy of a2; when it returns a non-null pointer, dereference that result into a local and run the callback stored at a1+12 via 0x5647D0, returning its result; otherwise return the first call's null result. Used by 0x5644B0, 0x564530 and 0x564580.
- `0x00564890` **BatchIterationController** — Indirect dispatch helper (fastcall): load the dword function pointer at a1+0x10; when non-zero compute v4 = LinearInterpolation(a1, a2) via 0x5648B0 and invoke the pointer as a __thiscall with v4 as its argument, returning that call's result; a null pointer returns null unchanged. Used as the per-item tail dispatch of BatchLoopWithMemoryCleanup (0x564860) and CallChainWrapper (0x5649D0).
- `0x005648C0` **BufferPushForwarder** — Trivial forwarding wrapper: dereference the first DWORD of the object at offset 0x0 and pass it as the this pointer to AudioStackPushWithOverflowRealloc (0x5648D0), returning that call's result unchanged.
- `0x005648D0` **GrowableStructBuffer** — Push element a2 onto a growable stack buffer: when the count (this+0x0) equals the capacity (this+0x4) grow the buffer via 0x564930; increment the count; when a2 is below the new top, shift trailing elements up one slot (byte count = this+0x8 stride * (new_top - a2 - 1)) using 0x5648B0 offset math and the 0x58B130 memory move; copy the new element via 0x564960.
- `0x00564930` **GrowableStructBuffer** — Buffer growth: compute the new capacity = this[3] (growth increment at +0xC) + this[1] (current capacity at +0x4), store it back at +0x4, reallocate via 0x58B5D4 with the old buffer pointer this[5] (at +0x14) and byte size new_capacity * this[2] (element stride at +0x8), store the result at this+0x14 and return it.
- `0x00564A20` **GrowableStructBuffer** — Element index search: return -1 on null this or an element count of 0 at this+0x0; dispatch on a4 to a binary-search path (0x564B10) or a linear stride-search path (0x564AB0), both primed by LinearInterpolation (0x5648B0) on (this, a3) with the stride at this+0x8; when a match pointer v6 is returned with the found-flag still set, return (v6 - this[5] base at +0x14) / stride at +0x8; otherwise -1.
- `0x00567940` **DualPointerCleanupObject** — Dual-pointer cleanup: free the pointer at this+0x18 (if non-null) via 0x587BCF, then the pointer at this+0x10 (if non-null) via 0x587BCF, returning the last free result (0 when offset 0x18 was null). Used as a node/tree cleanup helper by 0x567A90 and 0x567CC0.
- `0x00567980` **LinkedListContainer** — Count the nodes of a singly-linked list: walk from the head/cursor pointer at this+0x8 through each node's next pointer at node+4 until null, returning the number of visited nodes (0 when the head is null). No fields are written. Invoked by 0x47D800 and 0x4C5940 on the list-owner object.
- `0x00568F20` **MultiFieldCleanupObject** — Destructor-style cleanup: free up to four owned pointers (this+0x0, +0x230, +0x238, +0x240) via 0x587BCF when non-null and null them; unconditionally zero the companion dwords +0x224, +0x228, +0x22C, +0x234, +0x23C; return the nulled pointer formerly at this+0x240. Invoked from 0x568E30 on the frame path.
- `0x00569C10` **RigidBodyState** — One rigid-body integration step on the vehicle physics tick: advance linear position (+0x4/+0xC/+0x14) by an a2-scaled velocity Euler step with staging copies to offsets 356/380/452/476/500/524, advance linear velocity (+0x64/+0x6C/+0x74) using the a2-scaled factor at +0xB4 times +0x134/+0x13C/+0x144, scale angular momentum (+0x7C/+0x84/+0x8C) into a vector passed to sub_56C020, advance angular momentum (+0x94/+0x9C/+0xA4) using +0x14C/+0x154/+0x15C, run the F_3x3InertiaTensorTransform (0x5692A0) and write the inertia-transformed result back to angular velocity (+0x7C/+0x84/+0x8C); return the transform's integer result.
- `0x0056CF10` **QuadPointerOwner** — Release the four pointer slots of this (+0x0, +0x4, +0x8, +0xC): free each non-null slot via 0x587BCF and clear it to 0; save, free and clear the slot at +0xC last, and return its saved pointer (the free result when non-null). Called from 0x56C830.
- `0x0056EAD0` **LinearSearchContainer** — Linear search over an array of 580-byte elements: return 0 when the element count at this+0 is <= 0; otherwise iterate from the base pointer at this+4 with stride 580, comparing each element's first dword as a string pointer via 0x588410; return this+4 + 580*index on a match, or 0 when the count is exhausted without a match.
- `0x00579FF0` **StaticInitGuardObject** — Once-guarded static-initialization wrapper: install an SEH/exception-handler record at unk_8D3BF0, run frame enter/leave helpers, and use the global guard counter so the construction block runs only on the first call; the block constructs static locale objects with vtable setup and links CEH exception-handling frames into a chain. Returns the saved incoming ECX value.
- `0x0057A1E0` **SmallStructInitializer** — Constructor/initializer of a small structure: set the dword at this+0x4 to 0, the byte at +0x8 to 0, the byte at +0x28 to 1 (the only non-zero write), and the bytes at +0x29/+0x2A/+0x2B/+0x2C to 0; return 0. No reads, no globals, no calls; called from construction-time helpers.
- `0x0057A200` **SizeTaggedBuffer** — Size-tagged buffer copy (thiscall): copy a3 bytes from a2 into the payload area at this+0x2D via qmemcpy and record the byte count (truncated to a byte) at this+0x2C, returning the receiver pointer. Called by DriverEntrantSetupEntry (0x462550) and BufferSendWithLocks (0x462760) to build a size-prefixed byte buffer.
- `0x0057A660` **ComStyleHandleDispatcher** — Read the object pointer stored at this+0x0 and perform two sequential virtual calls through that object's vtable: slot at byte offset 0x74 (vtable+116) with no extra arguments, then slot at byte offset 0x9C (vtable+156) with two zero arguments; return constant 1. Invoked by NetCommSessionMessageDispatcher (0x45D890) and 0x463140.
- `0x0057A760` **SEHGuardedCopyHandler** — SEH-protected, bounded data copy with a validation gate: initialize the SEH scope (dispatch table at 0x59C778) via 0x586700, read the context value at this+0, gate on 0x5853B0(v6, v10); on validation, copy bounded data via 0x586A10(a2, *a3, &v9), store the resulting size into *a3 and the state dword v10[1] into *a4, finalize the scope via 0x5867B0 and return 0; on validation failure skip the copy and return 11.
- `0x0057A850` **ComStyleHandleDispatcher** — Virtual predicate through a COM-style pointer-to-pointer handle: dereference this+0x0 to the object, read the vtable pointer at obj+0x0, fetch the method at vtable offset 0xA0, and call it with (*this, a2, a3, a4); return TRUE when the method returns 0, FALSE otherwise. Called by 0x4623E0.
- `0x0057A8C0` **ComStyleHandleDispatcher** — COM-style virtual dispatch wrapper: dereference the interface handle *this, load the virtual method pointer at vtable offset 0xC0, invoke it thiscall with the interface pointer and the argument a2; always return 0. Called by BufferSendWithLocks (0x462760).
- `0x0057ABB0` **ModuleRegistryList** — Create a network socket object from 12 parameter DWORDs and an output pointer, validate it, then register it as the data pointer of a 16-byte node (data +0, next +4, prev +8, owned-flag byte +12) inserted into the global doubly-linked module list (head 0x8D3BFC, tail 0x8D3C00/0x8D3C04, count 0x8D3C08). Allocates socket (4 bytes) and node (16 bytes) via 0x587C03, creates the socket via 0x57A420, runs a sub-object vtable call via 0x585CC0 plus the 0x4B0170 stub, and increments the pool counter. Returns 0 on success, 1 on allocation or validation failure.
- `0x0057ACB0` **ModuleRegistryList** — Find and remove the node whose data pointer equals a1 from the global module list (head 0x8D3BFC, tail 0x8D3C00/0x8D3C04, count 0x8D3C08): run a sub-object vtable call via 0x585CC0 plus the 0x4B0170 stub, walk the next chain comparing each node's data pointer, unlink the match updating head/tail globals, decrement the counter, destroy the owned data via 0x57A4C0 when the node's flag byte at +12 is set, and free node and owned data via 0x587BCF. Returns 0 on removal, 1 on empty list or not-found.

## Proposed classes

### SessionReinitContainer

Session-level container reinitialized on StartNetworkUpdate: initialized flag at +0x0, a batch sub-struct at +0x4 whose inner-buffer callback is sub_5640F0, an audio array at +0x94 and a counter at +0x98. Owner identity is UNKNOWN at packet level.

Methods: `0x00563E00`

- `this+0x00000000` `int init_flag` (read, DERIVED)
- `this+0x00000004` `void* batch_sub_struct_ptr` (read_write, GUESS)
- `this+0x00000094` `void* audio_array_ptr` (read_write, GUESS)
- `this+0x00000098` `int audio_array_count` (write, GUESS)

### AudioContainerSubStruct

Container/sub-struct holding an audio array: the wrapper object's +0x0 points to the sub-struct and +0xC of the sub-struct is the audio array. 0x5640F0 is the unconditional teardown (destroy the array via 0x564740, free the sub-struct via 0x58AA6F). The relationship to the batch sub-struct at SessionReinitContainer+0x4 is inferred (0x5640F0 is that sub-struct's inner-buffer callback per 0x563E00) but not proven.

Methods: `0x005640F0`

- `this+0x00000000` `void* container_ptr` (read, GUESS)
- `obj+0x0000000C` `void* audio_array_ptr` (read, GUESS)

### FieldZeroAccessor

Minimal thiscall accessor exposing field 0x0 as a 32-bit value; consumed across network/system dispatch paths (StartNetworkUpdate, ConditionalNetworkSystemDispatch, VehicleStateQueryAtLargeOffset, NetworkConnection). Field 0x0 semantics and the owning object type are unknown.

Methods: `0x00563E70`

- `this+0x00000000` `int state_or_identity` (read, GUESS)

### NetworkTokenDispatcher

Network/server-entry token dispatch. 0x564110 tokenizes a server path on backslash and routes 'ip'/'other' entries to address parsing (0x5642B0) or 0x564390, or fetches singletons via the callback context and dispatches through a stored function pointer at v6+12. 0x563EC0 selects a callback via a type switch, stores parameters into context slots a1[32]/a1[33], publishes the context to global 0x8D46B4 and dispatches through 0x564A00. The two are grouped by the shared network-dispatch theme and the call edge 0x564110 -> 0x564390; the concrete context layout (a1 slots) is unknown.

Methods: `0x00563EC0`, `0x00564110`


### CallbackContextDispatcher

Object exposing stored callback slots (a dispatch callback near +12, a callback-check slot at +16). 0x564270 queries/installs a cached singleton through the +16 callback with a heap-copy fallback; 0x564390 parses settings-style tokens and dispatches value pairs through the +12 callback; 0x5644F0 chains the two callbacks, feeding the first result into the second. Mutual calls are proven (0x564110 -> 0x564390 -> 0x564270); the slot layout is raw-source evidence only and is not formalized as fields.

Methods: `0x00564270`, `0x00564390`, `0x005644F0`


### WordFieldAccessor

Small thiscall getter exposing the unsigned 16-bit word at offset 0x4 of this. Callers (0x5631D0, 0x563AB0) sit in audio-parameter search/dispatch paths, but the audio attribution is inherited from caller names and not evidenced inside the function.

Methods: `0x005644A0`

- `this+0x00000004` `unsigned short word_at_4` (read, DERIVED)

### BatchIterationController

Per-item dispatch tail used by batch/chain iteration: 0x564890 loads a function pointer at a1+0x10, guards it, computes a LinearInterpolation-derived argument (0x5648B0) and dispatches it __thiscall. Callers BatchLoopWithMemoryCleanup (0x564860) and CallChainWrapper (0x5649D0) operate on a batch/chain object; the receiver type and the +0x10 slot meaning are unknown.

Methods: `0x00564890`


### BufferPushForwarder

Thin wrapper whose +0x0 holds a pointer to the growable buffer; dereferences it and forwards as the this pointer to the push operation 0x5648D0. Distinct receiver from GrowableStructBuffer because its +0x0 is a pointer rather than the count.

Methods: `0x005648C0`

- `this+0x00000000` `void* target_buffer_ptr` (read, GUESS)

### GrowableStructBuffer

Growable element buffer with a proven shared layout across 0x5648D0/0x564930/0x564A20: element count at +0x0, capacity at +0x4, element stride at +0x8, growth increment at +0xC and the buffer base pointer at +0x14. Push grows the buffer when full and shift-inserts; growth reallocates via 0x58B5D4; index search returns (match - base)/stride via binary (0x564B10) or linear (0x564AB0) paths.

Methods: `0x005648D0`, `0x00564930`, `0x00564A20`

- `this+0x00000000` `int element_count` (read_write, DERIVED)
- `this+0x00000004` `int capacity` (read_write, DERIVED)
- `this+0x00000008` `int element_stride` (read, DERIVED)
- `this+0x0000000C` `int growth_increment` (read, DERIVED)
- `this+0x00000014` `void* buffer_base_ptr` (read_write, DERIVED)

### DualPointerCleanupObject

Node/tree cleanup object holding two owned pointers at +0x18 and +0x10; 0x567940 frees both (null-guarded) and returns the last free result. The meaning of the two pointer members (child/sub-object pairs) is caller-specific and unresolved.

Methods: `0x00567940`

- `this+0x00000018` `void* pointer_a` (read, GUESS)
- `this+0x00000010` `void* pointer_b` (read, GUESS)

### LinkedListContainer

Container of a singly-linked list: the head/cursor pointer is at this+0x8 and each node carries its next pointer at node+4. 0x567980 counts nodes by walking the next chain; the node payload beyond the next pointer is undefined.

Methods: `0x00567980`

- `this+0x00000008` `void* head_ptr` (read, DERIVED)
- `*(this+0xC)+0x00000004` `void* next_ptr` (read, DERIVED)

### MultiFieldCleanupObject

Destructor-style cleanup object: frees up to four owned pointers (this+0x0, +0x230, +0x238, +0x240) when non-null and nulls them, and unconditionally zeroes the companion dwords +0x224, +0x228, +0x22C, +0x234, +0x23C. The pointer/dword pairing suggests handle/count records, but the owning class is not established. The packet's DERIVED prelabel 'ctor_init' is contradicted by the raw source (this cleans up, it does not construct).

Methods: `0x00568F20`

- `this+0x00000000` `void* primary_ptr` (read_write, GUESS)
- `this+0x00000224` `int companion_dword_a` (write, GUESS)
- `this+0x00000228` `int companion_dword_b` (write, GUESS)
- `this+0x0000022C` `int companion_dword_c` (write, GUESS)
- `this+0x00000230` `void* ptr_b` (read_write, GUESS)
- `this+0x00000234` `int companion_dword_d` (write, GUESS)
- `this+0x00000238` `void* ptr_c` (read_write, GUESS)
- `this+0x0000023C` `int companion_dword_e` (write, GUESS)
- `this+0x00000240` `void* ptr_d` (read_write, GUESS)

### RigidBodyState

Rigid-body state record integrated once per physics tick by 0x569C10: linear position at +0x4/+0xC/+0x14, linear velocity at +0x64/+0x6C/+0x74, angular velocity at +0x7C/+0x84/+0x8C, angular momentum at +0x94/+0x9C/+0xA4, a scale factor at +0xB4, velocity/momentum addends at +0x134..+0x15C and the 3x3 inertia tensor at +0xEC..+0x12C. Staging copies to offsets 356/380/452/476/500/524 preserve previous state blocks but those offsets are absent from the packet field table.

Methods: `0x00569C10`

- `this+0x00000004` `float position_x` (write, DERIVED)
- `this+0x0000000C` `float position_y` (write, DERIVED)
- `this+0x00000014` `float position_z` (write, DERIVED)
- `this+0x00000064` `float velocity_x` (read_write, DERIVED)
- `this+0x0000006C` `float velocity_y` (read_write, DERIVED)
- `this+0x00000074` `float velocity_z` (read_write, DERIVED)
- `this+0x0000007C` `float angular_velocity_x` (read_write, DERIVED)
- `this+0x00000084` `float angular_velocity_y` (read_write, DERIVED)
- `this+0x0000008C` `float angular_velocity_z` (read_write, DERIVED)
- `this+0x00000094` `float angular_momentum_x` (read_write, DERIVED)
- `this+0x0000009C` `float angular_momentum_y` (read_write, DERIVED)
- `this+0x000000A4` `float angular_momentum_z` (read_write, DERIVED)
- `this+0x000000B4` `float velocity_scale_factor` (read, DERIVED)
- `this+0x00000134` `float velocity_addend_x` (read, DERIVED)
- `this+0x0000013C` `float velocity_addend_y` (read, DERIVED)
- `this+0x00000144` `float velocity_addend_z` (read, DERIVED)
- `this+0x0000014C` `float momentum_addend_x` (read, DERIVED)
- `this+0x00000154` `float momentum_addend_y` (read, DERIVED)
- `this+0x0000015C` `float momentum_addend_z` (read, DERIVED)
- `this+0x000000EC` `float inertia_tensor_m00` (read, DERIVED)
- `this+0x000000F4` `float inertia_tensor_m01` (read, DERIVED)
- `this+0x000000FC` `float inertia_tensor_m02` (read, DERIVED)
- `this+0x00000104` `float inertia_tensor_m10` (read, DERIVED)
- `this+0x0000010C` `float inertia_tensor_m11` (read, DERIVED)
- `this+0x00000114` `float inertia_tensor_m12` (read, DERIVED)
- `this+0x0000011C` `float inertia_tensor_m20` (read, DERIVED)
- `this+0x00000124` `float inertia_tensor_m21` (read, DERIVED)
- `this+0x0000012C` `float inertia_tensor_m22` (read, DERIVED)

### QuadPointerOwner

Object owning four contiguous pointer slots at +0x0/+0x4/+0x8/+0xC; 0x56CF10 frees and clears each non-null slot and returns the pointer formerly at +0xC. The meaning of each slot and the owning object are not established.

Methods: `0x0056CF10`

- `this+0x00000000` `void* slot_0` (read_write, GUESS)
- `this+0x00000004` `void* slot_1` (read_write, GUESS)
- `this+0x00000008` `void* slot_2` (read_write, GUESS)
- `this+0x0000000C` `void* slot_3` (read_write, GUESS)

### LinearSearchContainer

Container of an array of 580-byte elements with the element count at +0x0 and the array base at +0x4; 0x56EAD0 linearly searches by comparing each element's first dword (a string pointer) via 0x588410 and returns the matching element pointer. The concrete element/container type is unverified.

Methods: `0x0056EAD0`

- `this+0x00000000` `int element_count` (read, DERIVED)
- `this+0x00000004` `void* array_base_ptr` (read, DERIVED)

### StaticInitGuardObject

Once-guarded static-initialization wrapper: 0x579FF0 installs an SEH handler record at unk_8D3BF0 and uses a global guard counter so a static locale-object construction block runs only on the first call, linking CEH exception frames. The static buffers/vtables touched in the one-time block and the initial guard-counter value are not in the packet's evidence list.

Methods: `0x00579FF0`


### SmallStructInitializer

Small construction-time sub-structure: 0x57A1E0 writes dword +0x4 to 0, byte +0x8 to 0, byte +0x28 to 1 (the only non-zero initialization) and bytes +0x29..+0x2C to 0, returning 0. Called from construction-time helpers; the meaning of the +0x28 flag is unknown.

Methods: `0x0057A1E0`

- `this+0x00000004` `int dword_zeroed` (write, DERIVED)
- `this+0x00000008` `byte byte_zeroed` (write, DERIVED)
- `this+0x00000028` `byte flag_byte_one` (write, GUESS)
- `this+0x00000029` `byte zero_byte_29` (write, GUESS)
- `this+0x0000002A` `byte zero_byte_2A` (write, GUESS)
- `this+0x0000002B` `byte zero_byte_2B` (write, GUESS)
- `this+0x0000002C` `byte zero_byte_2C` (write, GUESS)

### SizeTaggedBuffer

Size-prefixed byte buffer: the size byte sits at +0x2C and the payload begins at +0x2D; 0x57A200 copies a3 bytes from a2 into the payload and records the (truncated) byte count at +0x2C, returning the receiver. Callers (0x462550, 0x462760) build size-tagged buffers on the receiver. The receiver identity and the reason the payload offset +0x2D is not in the packet field list are unresolved.

Methods: `0x0057A200`

- `this+0x0000002C` `byte size_prefix` (write, DERIVED)

### ComStyleHandleDispatcher

COM-style pointer-to-pointer handle wrapper: the handle object's +0x0 holds the interface pointer; 0x57A660 performs two sequential virtual calls at vtable slots 0x74 and 0x9C, 0x57A850 invokes the predicate at vtable slot 0xA0 and 0x57A8C0 the method at vtable slot 0xC0. The interface identity behind the handle and the slot semantics are unknown.

Methods: `0x0057A660`, `0x0057A850`, `0x0057A8C0`

- `this+0x00000000` `void* interface_ptr` (read, DERIVED)

### SEHGuardedCopyHandler

SEH-protected, bounded copy handler: 0x57A760 reads a context value at this+0, gates the copy on 0x5853B0 validation, copies via 0x586A10, stores the size and a state dword to outputs, and returns 0 on the validated path or 11 on validation failure. The semantics of the validation and the return code 11 are not grounded as named constants.

Methods: `0x0057A760`

- `this+0x00000000` `unsigned int context_value` (read, DERIVED)

### ModuleRegistryList

Process-global network-module registry implemented as a doubly-linked list: head global 0x8D3BFC, tail globals 0x8D3C00/0x8D3C04 and a pool counter 0x8D3C08. Nodes are 16 bytes (data pointer at +0, next at +4, prev at +8, owned-data flag byte at +12). 0x57ABB0 creates a socket object and inserts a node; 0x57ACB0 finds and removes a node, freeing the node and, when owned, the data. Node offsets are raw-source evidence only.

Methods: `0x0057ABB0`, `0x0057ACB0`


## Compatibility contracts

- **GrowableStructBufferLayout** — A growable element buffer with count at +0x0, capacity at +0x4, element stride at +0x8, growth increment at +0xC and base pointer at +0x14. Push (0x5648D0) grows the buffer when count == capacity and shift-inserts by one slot; growth (0x564930) reallocates to (capacity + increment) * stride via 0x58B5D4 and stores the new base at +0x14; index search (0x564A20) returns (match - base)/stride via binary (0x564B10) or linear (0x564AB0) paths, -1 on no match.
- **ModuleRegistryListContract** — A process-global doubly-linked module registry: head 0x8D3BFC, tail 0x8D3C00/0x8D3C04 and pool counter 0x8D3C08. Nodes are 16 bytes with data at +0, next at +4, prev at +8 and an owned-data flag byte at +12. 0x57ABB0 inserts a validated socket node (first-insert vs append, incrementing the counter); 0x57ACB0 walks the next chain, unlinks the match, updates head/tail, decrements the counter and frees the node (and the owned data when the flag is set).
- **RigidBodyIntegrationContract** — One rigid-body integration step per physics tick (callers 0x459AE0, 0x56F020): linear position (+0x4/+0xC/+0x14) advances by the a2-scaled velocity (+0x64/+0x6C/+0x74), linear velocity advances using the a2-scaled factor at +0xB4 against addends +0x134..+0x144, angular momentum (+0x94/+0x9C/+0xA4) advances using addends +0x14C..+0x15C, and the 3x3 inertia tensor (+0xEC..+0x12C) is transformed to write angular velocity (+0x7C/+0x84/+0x8C); six staging copies to offsets 356/380/452/476/500/524 preserve previous state blocks. A replacement must keep the tick-scaled Euler step and the tensor transform.
- **VTableDispatchSlotContract** — Handle-based virtual dispatch through a pointer-to-pointer: the handle's +0x0 is the interface pointer and the vtable is at obj+0x0. Dispatched slots are 0x74 and 0x9C (two-call sequence returning constant 1), 0xA0 (byte-returning predicate, TRUE when it returns 0) and 0xC0 (returns constant 0). The first argument of each virtual call is the interface pointer itself.
- **CallbackSingletonAccessorContract** — A context object carries a callback-check slot at +16 and a dispatch-callback slot near +12. 0x564270 queries the +16 callback for a cached singleton and, when absent, heap-copies the key via 0x564690 and installs it through 0x564780; 0x564390 resolves token pairs through the accessor and dispatches them through the +12 callback; 0x5644F0 chains both slots. The slot layout is raw-source evidence only.
- **AudioArrayContainerContract** — The session container keeps a batch sub-struct at +0x4 (inner-buffer callback sub_5640F0, audio array at sub-struct +0xC) and a separate audio array at +0x94 with a counter at +0x98. Reinitialization (0x563E00) tears down both via 0x564860/0x564740 and rebuilds them; the sub-struct teardown (0x5640F0) destroys the +0xC array via 0x564740 and frees the sub-struct via 0x58AA6F.

## Unresolved

- All owner identities are UNKNOWN at packet level; every class is a DERIVED or GUESS grouping. Owner resolution needs independent evidence (runtime/vtable inspection or cross-references outside this packet).
- The relationship between the AudioContainerSubStruct (0x5640F0) and the batch sub-struct at SessionReinitContainer+0x4 is inferred from 0x563E00 passing sub_5640F0 as the inner-buffer callback; the packet does not prove that 0x5640F0's wrapper object is that same sub-struct.
- The CallbackContextDispatcher callback slots (+12 dispatch, +16 check) and the +0x10 function-pointer slot used by 0x564890 are dereferenced directly but are not declared packet fields; the slot interpretation is DERIVED from the CallbackCheck call shape.
- 0x564890's grouping is uncertain: it could be the batch/chain per-item tail (its callers 0x564860/0x5649D0) or part of the growable-buffer machinery; the +0x10 slot meaning and what LinearInterpolation computes for it are unresolved.
- The NetworkTokenDispatcher grouping (0x563EC0 + 0x564110) rests on the network-dispatch theme and the call edge 0x564110 -> 0x564390; the a1 context layout (slots a1[1], a1[32], a1[33], function pointer at v6+12) is not formalized.
- Semantics of the a4 type selector in 0x564110 (especially the value 6) and of sub_564410's acceptance test in 0x564390 are unknown; the character identity of delimiter 92 and the meaning of the default string byte_5EA438 are not confirmed.
- The four jump-table callback targets of 0x563EC0 (0x563F20, 0x563F70, 0x564000, 0x564090), the dispatch contract of 0x564A00, and the readers of global 0x8D46B4 are unproven.
- The 'ip'/'other' string literal identities (globals 0x5E5050/0x5E5048) are inferred from symbol names, not verified, and why the 'other' branch rewrites 0x01 bytes to backslashes is unknown.
- The six staging copies in 0x569C10 target byte offsets (356, 380, 452, 476, 500, 524) that are absent from the packet field table; sub_56C020's vector input contract is not defined by the packet.
- The 580-byte element stride of 0x56EAD0 and the concrete element/container type are unverified; sub_588410 is treated as a string comparison returning 0 on match but its exact contract is outside the packet.
- The once-guarded static init 0x579FF0 references many static addresses (locale objects, CEH frames, vtables) and a guard counter that are absent from the packet evidence list; the initial guard value and the helper/constructor callees are unknown.
- The cleanup helper classes (DualPointerCleanupObject, MultiFieldCleanupObject, QuadPointerOwner) share no common layout; equal offsets on different this bases are kept separate per the field-identity rule. The prelabel 'ctor_init' on 0x568F20 contradicts its cleanup body.
- The vtable-slot semantics behind the ComStyleHandleDispatcher (0x74/0x9C/0xA0/0xC0) and the sub-object vtable methods consulted by 0x57ABB0/0x57ACB0 (via FieldGetter_5cc0) and the socket vtable method at offset 72 are inferred from dispatch patterns only; no named callee is statically known.
- Return codes 4 (0x563E00 early exit) and 11 (0x57A760 validation failure) are not grounded as named status constants beyond their literal use.
- The SEH registration global 0x59C79B for 0x57ABB0 and the SEH dispatch table 0x59C778 for 0x57A760 are external to the packet; their exact handlers are not evidenced.
- The AudioStackPushWithOverflowRealloc persistence note: this+0x0 is unconditionally incremented each push, so an external poke of the count can be corrupted on the next push.
