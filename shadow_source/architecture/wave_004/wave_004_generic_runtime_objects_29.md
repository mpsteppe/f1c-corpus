# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Twenty-nine functions reconstructed as runtime object services with eight worker-proposed classes. A directory-entry linked list cluster (comparator 0x00565BB0, head-data peek 0x00565ED0, recursive merge sort 0x005664A0) sorts entries by name or file time selected by a type-object sort-mode field. A recursive tree container (0x00567A90, 0x00567CC0) frees tree nodes through null-check, dual-pointer-cleanup and free-wrapper calls, and 0x00568320 inserts string-hashed nodes into bucket trees. A physics joint-system context (0x00568E30, 0x00568E60, 0x0056D3E0, 0x005697F0, 0x00569860) zero-initializes, allocates three 56/132/88-stride element-group buffers at +0x230/+0x238/+0x240, and appends body-frame position-delta entries into the first buffer; the inertia-tensor parameter object (0x00568E70) stores name, scalar and per-component reciprocals; the rigid-body pair constraint (0x0056D2D0) transforms local anchor offsets through both bodies' rotations and normalizes the anchor separation. Quaternion math (0x00567010, 0x00567030, 0x00567580) converts quaternion/euler forms and performs spherical interpolation. A high-resolution timer (0x00568CB0, 0x00568CF0) conditionally reads QPC through a global API pointer and computes scaled deltas. Remaining functions (indirect dispatch, batch teardown, RC4 key schedule, file-attribute repair, flag dispatch, Gauss-Jordan solver, string utilities, selector lookup, one-time global init, 16-byte compare) are treated as unowned free services.

## Function roles

- `0x00564780` **UnknownObject** — Indirect dispatch wrapper: calls the handler selected by the function pointer at a1+12 with (a2, dword at a1+4), resolves the target buffer index via BufferIndexComputation on the dword at a1+16, takes the single-entry fallback path through *(*(dword)a1 + 4*v4) when the index is -1, otherwise forwards the index to CallChainWrapper; reached from four infrastructure/audio-mixer paths.
- `0x00564860` **UnknownObject** — Batch teardown of a counted array: loop from i=0 over the count at this+0x0 calling IndirectCallViaFunctionPointer(lpMem, i) per element, free the sub-resource at this+0x14 via the deallocation wrapper, then free the container itself and return that wrapper's result; invoked by network, display-mode and audio-array teardown paths.
- `0x00565080` **UnknownObject** — RC4-style key-schedule init: clear the 256-dword state with memset (writing a3[325]=0 first), run four outer passes each doing two 256-step keyed permutation swaps over the key bytes with the key-byte index wrapping at the key length, XOR each state dword with its own index, then forward the finished state to sub_564DD0 and return its result.
- `0x00565BB0` **DirectoryEntry** — Sort comparator for two directory entries: selects the comparison by the sort-mode dword at [*this]+0x220; mode 1 returns strcmp(this+48, a2+48) > 0, mode 2 returns CompareFileTime(this+24, a2+24) > 0, mode 3 returns the inverse file-time comparison, default returns strcmp(this+48, a2+48) < 0; used to order directory entries by the two sort routines.
- `0x00565ED0` **DirectoryEntryLinkedList** — Peek accessor on a linked-list head: reads the first node pointer stored at (*this + 8), then returns a pointer to that node's data payload (first 4-byte field plus 4) when both the node pointer and its data pointer are non-null, otherwise returns 0; used by file/directory enumeration.
- `0x005664A0` **DirectoryEntryLinkedList** — Recursive merge sort of a singly-linked list whose next pointer lives at node offset +4: count the nodes, return early for fewer than 2 nodes, split at the midpoint by clearing the midpoint next pointer, recurse on both halves, then merge with the data comparator sub_565BB0 and return the sorted head; called by sub_566380.
- `0x005668F0` **UnknownObject** — File attribute check-and-fix sequence: start result=1; when the attribute check with flag 0 does not return -1 and the flag-6 check reports the attribute present, toggle the read-only attribute with value 128 through the Win32 helper and recheck with flag 6, returning 0 on the still-present failure path and the preserved result (1) otherwise; invoked by the attribute-repair callers.
- `0x00566DF0` **UnknownObject** — Conditional dispatch helper: reads the flag at this+0x10 and the object pointer at this+0x0, forwards the second argument a2 (with constant third argument 1) to AudioStreamBufferRead when the flag is set or to sub_587F64 otherwise, and returns the chosen callee's result.
- `0x00567010` **QuaternionMath** — Quaternion-to-Euler wrapper: builds a 3x3 rotation matrix from the quaternion via the matrix-from-quaternion routine, converts the matrix to Euler angles via the matrix-to-euler routine, and returns the result; reused by the collision-response filter and the audio-sample crossfade path.
- `0x00567030` **QuaternionMath** — Euler-to-quaternion conversion using half-angle trigonometry: computes cos/sin of each half angle, forms the four cross products, and composes the w/x/y/z quaternion components into the output buffer; clustered with the EulerAnglesToQuaternion structural twin.
- `0x00567580` **QuaternionMath** — Four-component spherical interpolation: dot the two inputs, negate the stored dot and the second input on the negative-dot shortest-arc path, blend with sin-weighted factors, and select the direct-lerp fallback through the x87 passthrough helper when 1.0 - dot is within the 0.02 tolerance; reused by the collision-response filter and the audio crossfade path.
- `0x005677B0` **UnknownObject** — In-place Gauss-Jordan solver with partial pivoting for an a2 x (a2+1) augmented double matrix given as an array of row pointers: normalize each pivot row, eliminate the pivot column from every other row, and when the pivot is zero search lower rows for a non-zero replacement and swap the row in; returns 0 on completion and -1 for a singular system; used by five physics/geometry solvers.
- `0x00567A90` **RuntimeTreeContainer** — Recursive tree free: validate the root with the null-check wrapper, walk the child/sibling list through each node's second dword, recurse on every node, derive a secondary sub-object and recurse on it when present, then run the dual-pointer cleanup and release the root through the free wrapper.
- `0x00567CC0` **RuntimeTreeContainer** — Recursive destructor for a tree-like node: returns immediately on a null node (recursion terminator), otherwise recurses into the three child pointers at +0x4/+0x8/+0xC, runs the dual-pointer cleanup, deallocates through the free wrapper and returns its result; called by F_9PointerArrayCleanup.
- `0x00568320` **RuntimeTreeContainer** — Hash-bucket tree insertion keyed by a string: hashes the key obtained from the string-pointer accessor into the bucket array this, selects one of the container's node pointers based on the sub-check and container flags, inserts it as the bucket root or relinks it into the existing bucket tree at node offsets +4/+8/+12/+36/+40, then frees the source container via the recursive tree free and returns 0.
- `0x00568560` **UnknownObject** — In-place string sanitizer: first pass replaces path separators ('.', '/', '\') with underscore, second pass replaces any character accepted by the prefix-pattern check with hyphen; both passes skip null strings; used by profile/path handling to sanitize file/directory names.
- `0x00568910` **UnknownObject** — String decoder that expands '+~XX' hex-escape sequences while copying all other characters verbatim into a length-capped output buffer: returns 0 on null input or overflow, parses the two hex digits via the format wrapper after the hex-digit predicate accepts them, appends each decoded or verbatim byte through an overflow guard, and returns 1 on full decode.
- `0x00568CB0` **HighResolutionTimer** — Conditional high-resolution counter read: when the timer marker at this+0x0 is non-zero and bit 0 of the flags at this+0x48 is set, call QueryPerformanceCounter through the API pointer at global 0x0059E23C and store HighPart/LowPart into the two output pointers; always returns 0.
- `0x00568CF0` **HighResolutionTimer** — Timestamp-delta computation: captures the previous timestamp at this+0x20/+0x24, reads the current timestamp through the QPC wrapper, computes the 64-bit delta, stores the new timestamp back, scales the delta by the per-instance fields and returns it as a double.
- `0x00568E30` **PhysicsJointSystemContext** — Initialization routine: zeros the four dword fields at +0x0, +0x230, +0x238 and +0x240, invokes the multi-field pointer cleanup, and returns this.
- `0x00568E60` **PhysicsJointSystemContext** — Delegating destructor thunk: forwards this unchanged to the multi-field pointer cleanup (null-guarded release of the object's owned pointer fields) and returns its result; reached from the array-of-objects destructor and sub_56E970.
- `0x00568E70` **InertiaTensorParameters** — Inertia-tensor parameter init: allocates and copies the name string into this+0x0, stores the scalar a3 and its reciprocal at +0xAC/+0xB4, copies the 3-component inertia vector into +0xBC..+0xCC, stores per-component reciprocals at +0xD4/+0xDC/+0xE4, then delegates to the world-space transform routine and returns its result.
- `0x005697F0` **PhysicsJointSystemContext** — Allocates three element-group buffers for the constraint/joint system: 56*this[139] bytes into this[140], 132*this[141] bytes into this[142], 88*this[143] bytes into this[144], resetting each element-count field immediately after its allocation; returns the last buffer pointer.
- `0x00569860` **PhysicsJointSystemContext** — Appends a 56-byte entry holding a body-frame transformed world-position delta plus metadata to the ring buffer at this+0x230 with the element count at this+0x22C: computes the body-frame delta from the position at +0x4/+0xC/+0x14 and the rotation rows spanning +0x1C..+0x5C, stores metadata at entry offsets 48/52, and returns the appended entry.
- `0x0056D2D0` **RigidBodyPairConstraint** — Constraint anchor computation: rotates each body's local anchor offset through its rotation matrix, adds the body position to obtain the world anchor, subtracts the two world anchors, normalizes the difference, and writes the unit-length separation direction back into both body anchor buffers; on the physics frame path from four callers.
- `0x0056D3E0` **PhysicsJointSystemContext** — Constructor-style initializer: zero-fills four consecutive dwords starting at dword index 13 via the zero-init helper, then zeroes the eight fields at byte offsets +0x4/+0xC/+0x14/+0x1C/+0x24/+0x28/+0x2C/+0x30, calls sub_56E970 and returns this; called by the dynamics-object initialization path.
- `0x00579F89` **UnknownObject** — Selector lookup: selector 0 returns the static object at 0x008D3984, selector 1 returns the static object at 0x008D3980, and any other value returns 0; used by the vehicle physics joint-system loader as a per-type static configuration selector.
- `0x00579FB0` **UnknownObject** — CRT-style guarded one-time initializer: installs an SEH handler table on a global region, uses a reference-count guard global so the global-object constructor chain runs only on the first entry, constructs and cross-links the global objects into each other's vtable slots, and returns the caller's saved value.
- `0x0057A0C0` **UnknownObject** — Fixed-size 16-byte equality comparison: walks this against the 16 bytes at a2 (relative displacement v4 = a2 - this) while the bytes match, returning 1 when all 16 bytes match and 0 at the first mismatch.

## Proposed classes

### HighResolutionTimer

Per-instance high-resolution timer facade: conditionally reads QueryPerformanceCounter through a global API pointer when the timer is initialized and the enable flag is set, stores the timestamp pair, and computes scaled 64-bit deltas between consecutive reads.

Methods: `0x00568CB0`, `0x00568CF0`

- `this+0x00000000` `int timer_marker_or_frequency` (read, GUESS)
- `this+0x00000004` `int delta_scale_multiplier` (read, GUESS)
- `this+0x00000008` `int unresolved_read_only_field` (read, UNKNOWN)
- `this+0x00000020` `dword last_timestamp_low` (read_write, DERIVED)
- `this+0x00000024` `dword last_timestamp_high` (read_write, DERIVED)
- `this+0x00000048` `int qpc_enable_flag` (read, GUESS)

### DirectoryEntry

A single directory-entry object exposing a name string at +0x30 and a file time at +0x18; its comparator selects alphabetical vs file-time ordering from the sort-mode dword on the type object at [*this]+0x220.

Methods: `0x00565BB0`

- `this+0x00000030` `char* name` (read, DERIVED)
- `obj+0x00000220` `int sort_mode` (read, DERIVED)

### DirectoryEntryLinkedList

Intrusive singly-linked list of directory entries: a list head whose first-node pointer lives at +8, nodes carrying a data pointer in their first 4 bytes, and a recursive merge sort that relinks nodes through the next pointer at +4 using the entry comparator.

Methods: `0x00565ED0`, `0x005664A0`

- `obj+0x00000008` `ListNode* first_node` (read, DERIVED)
- `*(obj+0x8)+0x00000000` `void* node_data_ptr` (read, GUESS)
- `*(this+0x4)+0x00000004` `ListNode* next_link` (read_write, GUESS)

### QuaternionMath

Quaternion rotation math conversions: quaternion-to-euler via a matrix intermediate, euler-to-quaternion via half-angle trigonometry, and four-component spherical interpolation with shortest-arc and near-identity fallbacks; reused by collision-response and audio-crossfade paths.

Methods: `0x00567010`, `0x00567030`, `0x00567580`

- `this+0x00000000` `float component_w` (read_write, DERIVED)
- `this+0x00000004` `float component_x` (read_write, DERIVED)
- `this+0x00000008` `float component_y` (read_write, DERIVED)
- `this+0x0000000C` `float component_z` (read_write, DERIVED)

### RuntimeTreeContainer

Tree/graph runtime container: recursive node free that validates the root, walks the child/sibling list, frees a secondary sub-object, runs dual-pointer cleanup and releases through the free wrapper, plus a hash-bucket tree insertion keyed by string that relinks nodes at +4/+8/+12/+36/+40.

Methods: `0x00567A90`, `0x00567CC0`, `0x00568320`

- `this+0x00000004` `Node* first_child_or_sibling` (read_write, GUESS)
- `this+0x00000008` `Node* second_child` (read_write, GUESS)
- `this+0x0000000C` `Node* third_child` (read_write, GUESS)
- `this+0x00000024` `Node* tree_link_high1` (read_write, GUESS)
- `this+0x00000028` `Node* tree_link_high2` (read_write, GUESS)

### PhysicsJointSystemContext

Physics joint-system context object carrying a head field, a body transform (position + 3x3 rotation), three element-group buffers at +0x230/+0x238/+0x240 with counts at +0x22C/+0x234/+0x23C, a zero-init constructor path, a multi-field pointer cleanup/destructor, and an appender that writes body-frame position-delta entries into the first buffer.

Methods: `0x00568E30`, `0x00568E60`, `0x0056D3E0`, `0x005697F0`, `0x00569860`

- `this+0x00000000` `void* head_field` (read_write, GUESS)
- `this+0x00000004` `double world_pos_x` (read_write, DERIVED)
- `this+0x0000000C` `double world_pos_y` (read_write, DERIVED)
- `this+0x00000014` `double world_pos_z` (read_write, DERIVED)
- `this+0x0000001C` `double[9] rotation_matrix` (read_write, DERIVED)
- `this+0x00000024` `double rotation_element` (read_write, GUESS)
- `this+0x00000028` `double rotation_element` (read_write, GUESS)
- `this+0x0000002C` `double rotation_element` (read_write, GUESS)
- `this+0x00000030` `double rotation_element` (read_write, GUESS)
- `this+0x00000034` `double rotation_element` (read, GUESS)
- `this+0x0000003C` `double rotation_element` (read, GUESS)
- `this+0x00000044` `double rotation_element` (read, GUESS)
- `this+0x0000004C` `double rotation_element` (read, GUESS)
- `this+0x00000054` `double rotation_element` (read, GUESS)
- `this+0x0000005C` `double rotation_element` (read, GUESS)
- `this+0x0000022C` `int group1_count` (read_write, DERIVED)
- `this+0x00000230` `void* group1_buffer` (read_write, DERIVED)
- `this+0x00000234` `int group2_count` (read_write, DERIVED)
- `this+0x00000238` `void* group2_buffer` (read_write, DERIVED)
- `this+0x0000023C` `int group3_count` (read_write, DERIVED)
- `this+0x00000240` `void* group3_buffer` (read_write, DERIVED)

### InertiaTensorParameters

Inertia-tensor parameter object: holds an allocated name string at +0x0, a scalar (mass/moment) at +0xAC with its reciprocal at +0xB4, a 3-component inertia vector at +0xBC/+0xC4/+0xCC and per-component reciprocals at +0xD4/+0xDC/+0xE4, finishing by computing the world-space transform.

Methods: `0x00568E70`

- `this+0x00000000` `char* name` (read_write, DERIVED)
- `this+0x000000AC` `double scalar` (write, DERIVED)
- `this+0x000000B4` `double scalar_reciprocal` (write, DERIVED)
- `this+0x000000BC` `double inertia_x` (write, DERIVED)
- `this+0x000000C4` `double inertia_y` (write, DERIVED)
- `this+0x000000CC` `double inertia_z` (write, DERIVED)
- `this+0x000000D4` `double inertia_x_reciprocal` (write, DERIVED)
- `this+0x000000DC` `double inertia_y_reciprocal` (write, DERIVED)
- `this+0x000000E4` `double inertia_z_reciprocal` (write, DERIVED)

### RigidBodyPairConstraint

Constraint record holding pointers to two rigid bodies and their local anchor vectors; computes world anchors by rotating each local anchor through the body rotation, normalizes the anchor-separation direction and writes it back into both bodies.

Methods: `0x0056D2D0`

- `this+0x00000004` `RigidBody* body_a` (read, DERIVED)
- `this+0x00000008` `Vec3* body_a_local_anchor` (read, DERIVED)
- `this+0x0000000C` `RigidBody* body_b` (read, DERIVED)
- `this+0x00000010` `Vec3* body_b_local_anchor` (read, DERIVED)
- `*(this+0x4)+0x00000004` `double body_a_pos_x` (read, DERIVED)
- `*(this+0x4)+0x0000000C` `double body_a_pos_y` (read, DERIVED)
- `*(this+0x4)+0x00000014` `double body_a_pos_z` (read, DERIVED)
- `*(this+0x8)+0x00000018` `double body_a_anchor_x` (read_write, DERIVED)
- `*(this+0x8)+0x00000020` `double body_a_anchor_y` (read_write, DERIVED)
- `*(this+0x8)+0x00000028` `double body_a_anchor_z` (read_write, DERIVED)
- `*(this+0xC)+0x00000004` `double body_b_pos_x` (read, DERIVED)
- `*(this+0xC)+0x0000000C` `double body_b_pos_y` (read, DERIVED)
- `*(this+0xC)+0x00000014` `double body_b_pos_z` (read, DERIVED)
- `*(this+0x10)+0x00000018` `double body_b_anchor_x` (read_write, DERIVED)
- `*(this+0x10)+0x00000020` `double body_b_anchor_y` (read_write, DERIVED)
- `*(this+0x10)+0x00000028` `double body_b_anchor_z` (read_write, DERIVED)

## Compatibility contracts

- **ShortestArcQuaternionSlerp** — Spherical interpolation of four components: a negative dot product negates the stored dot and the second input (shortest arc), and when 1.0 - dot is within the 0.02 tolerance the direct-lerp fallback through the x87 passthrough helper is used instead of the sin-weighted branch. A replacement must reproduce the sign handling and the near-identity threshold.
- **RC4KeyScheduleStateShape** — Key-schedule initialization builds a 256-dword permutation state from key material a1 of length a2: four outer passes, each with two 256-step keyed swaps with the key index wrapping at a2, followed by XOR of each state dword with its index; the finished state is forwarded to sub_564DD0. A replacement must preserve the state shape and pass order.
- **GaussJordanPartialPivotContract** — In-place Gauss-Jordan elimination with partial pivoting solves an a2 x (a2+1) augmented double matrix: normalize pivot rows, eliminate the pivot column from every other row, search lower rows and swap for a non-zero pivot when the diagonal is zero, return 0 on completion and -1 when a column has no non-zero pivot.
- **DirectorySortModeSelection** — The directory-entry comparator selects its ordering from the sort-mode dword on the type object at [*this]+0x220: mode 1 compares names ascending by strcmp, mode 2 compares file times descending, mode 3 compares file times ascending, default compares names descending. A replacement must preserve the mode-to-comparison mapping.
- **TreeRecursiveFreeOrdering** — Recursive tree free validates the root, walks the child/sibling list through the node second dword, recurses on every node and on a derived secondary sub-object, then runs dual-pointer cleanup and releases the root through the free wrapper. A replacement must free children before the dual-pointer cleanup of the parent.
- **ElementGroupBufferSizing** — Three element-group buffers are allocated with strides 56, 132 and 88 bytes per element, sized from the counts at +0x22C/+0x234/+0x23C and stored at +0x230/+0x238/+0x240; each count field is reset to 0 immediately after its buffer is allocated.
- **QPCDeltaScaling** — High-resolution time reads QueryPerformanceCounter through the API pointer at global 0x0059E23C only when the timer marker at +0x0 is non-zero and bit 0 of the flags at +0x48 is set; deltas are computed between the stored timestamps at +0x20/+0x24 and scaled by the per-instance fields.
- **FileReadOnlyAttributeRepair** — The attribute-repair sequence checks with flag 0 and flag 6; when the flag-6 check reports the attribute present the read-only attribute is toggled with value 128, and a flag-6 recheck that still reports the attribute yields failure (0) while the normal path preserves success (1).
- **PlusTildeHexEscapeDecode** — String decoding expands '+~XX' hex-escape sequences (43, 126, two hex digits) while copying all other characters verbatim into a buffer capped at limit a3; returns 1 on full decode, 0 on null input or overflow. A replacement must reproduce the escape shape and the append overflow guard.

## Unresolved

- sub_58AA6F is treated as a memory-deallocation wrapper from prior analysis (DERIVED); this packet only shows it called on the sub-resource and the container.
- The object type behind a1 in FunctionPointerCallWithErrorHandling and the meaning of its a1+4 and a1+16 slots are not established.
- sub_564DD0 (post-process of the RC4 state), sub_587F64 (flag-dispatch branch), sub_563E70 (tree-insertion branch check), sub_49ADB0 (secondary sub-object derivation), sub_56E970 (sub-init) and sub_569410 (world-space inertia transform) are callees whose purpose is not evidenced in this packet.
- The a3[325] write in the RC4 key schedule lies outside the 256-dword region rebuilt by the permutation passes; its role is not established.
- The directory sort-mode direction labels (mode 1 greater-than, default less-than) are inferred from the predicate math (DERIVED); the ascending/descending meaning is not proven.
- The exact pairing of the three slerp float globals (0x0059E43C / 0x0059E440 / 0x0059E6EC) to the 0.0 / 0.02 / 1.0 constants is not determinable from the packet alone.
- Euler angle ordering/convention in the quaternion conversions is inferred from the half-angle construction only.
- The two read-only double globals dbl_59E420 and dbl_59E430 used by the Gauss-Jordan solver do not appear as named operands in the decompiled text; their exact role is not pinned.
- Whether the recursive-free and hash-bucket insertion functions share one tree node layout is inferred from the shared offsets (+4/+8/+C) and common cleanup-wrapper calls, not independently confirmed.
- The QPC timer guard semantics (non-zero +0x0 marker, bit 0 of +0x48) are inferred from the guards, not proven; the flagged high global's byte is unknown.
- GlobalObjectsInitWithRefcountGuard's constructed global objects, vtable tables and cleanup callbacks are named only in the packet prose and are not separately evidenced.
- Equal byte offsets across different classes (for example +0x4, +0x8, +0xC on this) do not prove shared ownership; each class is an independent worker proposal and the dereferenced-body fields are scoped to the RigidBodyPairConstraint bases.
- Worker class names (HighResolutionTimer, DirectoryEntry, DirectoryEntryLinkedList, QuaternionMath, RuntimeTreeContainer, PhysicsJointSystemContext, InertiaTensorParameters, RigidBodyPairConstraint) are proposed identifiers, not recovered original source names.
