# UiPlatformAndOptions

Scope: `ui_platform_and_options`  
Trust: `DERIVED`

A conservative, evidence-linked reconstruction of the ui_platform_and_options scope from 20 validated functions. The strongest grouping is ConstraintSolverState (GUESS), binding three per-frame physics constraint-solver functions (0x0056A390, 0x0056A840, 0x0056AA60) to one solver object through the shared constraint arrays at this+0x230/0x238/0x240, the force buffer at this+0x224, the matrix row table at this+0x228 and the shared body-state and traction-constant fields. A second shared layout, the mutex-protected linked list at this+0xAC8..0xADC, connects the network connection thread (0x0057FC80) and the thread-pool dequeue (0x005816B0) and is captured as the GUESS interface IMutexProtectedList. A third cluster groups the three DEFLATE/inflate Huffman builders (0x0052A4A5, 0x00539F70, 0x0053A4D0) as InflateHuffmanTableBuilder (GUESS) around a shared context-object layout (error string at +24, allocator at +32, free at +36, handle at +40) and the shared callee sub_53A020. The two SIMD rotation-matrix builders (0x00522C2D, 0x00524553) share the eight-slot __m64 output shape and the packed 1.0 constant global 0x005AF900 and are tied through the GUESS interface IFourByFourM64Matrix. A single state machine (UiScreenStateMachine, GUESS) is proposed from the state values 1 and 2 and the transition IDs 34 and 58 evidenced in UiScreenStateTick (0x00515DF2). The remaining functions are one-class GUESS units (DDSSurfaceBuilder, SurfaceReader, SockAddrBuilder, DeviceSessionInitializer, AsyncSocketWindowManager, LockAcquirer, WindowsPlatformCheck, UInt96Arithmetic). Ownership of every function stays LOW; no class reaches CONFIRMED.

## Function roles

- `0x005026A4` **DDSSurfaceBuilder** — DdsSurfaceHierarchyBuild: parses a DDS buffer (magic 542327876, header-length guards, pixel-format flags masked by 0xFC00 selecting 64512 for 6 faces or 0 for 1 face) and builds a linked-list surface hierarchy. Copies the header into the root fields at this+0xC/0x10/0x14, sets the type field at this+0x44 via IDToStructTableLookup (0x00500680), then for each face and mip level allocates an 84-byte surface sub-object (OperatorNewNhMallocWrapper 0x00587C03, initialized by 0x00500F3C) computing row stride and size from the pixel-format table rooted at 0x005D71F8. Returns 0 on success, -2147467259 on format/length failure and -2147024882 on allocation failure.
- `0x0050AF57` **SurfaceReader** — SurfaceRegionRead: reads a texture/surface region into a caller buffer. Acquires the region at coordinates (this+0x1034 + a2, this+0x1040 + a3) through sub_50AB51 (0x0050AB51, mode 1); on success copies 16 * this+0x1058 bytes from this+0x106C + 16 * (this+0x1030 - this+0x1070) into a4 and, when the flag at this+0x10 is set, runs ContactManifoldCleanup (0x00507845) over the copied buffer.
- `0x00510D60` **Mp3HuffmanDecoder** — Mp3HuffmanTableBuild: MP3 Huffman table builder. Reads stream bytes through the stream-state struct at this+0x14 (byte pointer at field 0, remaining count at field 1, refill callback at index 3), decodes per-entry control bytes (low nibble table index written to obj+0x18, high nibble value flag written to obj+0x1C, state word obj+0x14 set to 80 with dispatch through the obj vtable slot at +0), lazily allocates table slots at this+36+index via VTableAllocNullTerminate (0x00516974), fills each selected table from the position table 0x005AF778..0x005AF878 with 1- or 2-byte big-endian values, and when the batch count at obj+0x68 is >= 2 emits 64 WORDs into the obj+0x18..0x34 batch fields (state word 92, dispatch obj vtable slot +4 with argument 2). Persists the stream pointer/count on exit and returns 1.
- `0x00515DF2` **UiScreenState** — UiScreenStateTick: ticks the UI screen state machine. Returns state code 2 early when the exiting flag at this+0x19D is set; otherwise fetches the state code through the dispatch struct at this+0x190 (getter pointer at this+0x194). State 1 runs TextureSurfaceValidator (0x005159F5) and clears the pending flag at this+0x1A0, or, when the gate flag at this+0x19C is clear, writes transition ID 34 to obj+0x14 and invokes the screen vtable method at obj+0x0, then VtableDelegateDispatch (0x00515DB8). State 2 sets the exiting flag at this+0x19D and either clamps the target at this+0x84 down to the selection at this+0x7C or, when the dispatch byte at this+0x1E1 is set, writes transition ID 58 to obj+0x14 and invokes the screen vtable method. Returns the fetched state code.
- `0x00522C2D` **RotationMatrixBuilder** — FourByFourRotationMatrixBuild: builds a 4x4 rotation matrix in output a1 from the two packed-float rows of input a2 using 3DNow! intrinsics (pfadd, pfmul, pswapd, pfpnacc, pfacc, pfsubr, punpck) and the packed identity constant 0x3F8000003F800000 (global 0x005AF900). Writes all eight __m64 output slots including a1[6] = 0 and the homogeneous row a1[7] = {0, 1.0f}; emits _m_femms and returns the output pointer.
- `0x00524553` **QuaternionRotationMatrixBuilder** — QuaternionRotationMatrixBuild: builds a 4x4 rotation matrix from a quaternion pair (a2) and an angle scalar (a3) using 3DNow! intrinsics. Normalizes the quaternion in place via sub_5262C2 (0x005262C2), feeds the angle through PackedFloatingPointMath (0x005295E0), and writes all eight __m64 output slots using the packed 1.0 constant (global 0x005AF900); emits _m_femms and returns the output pointer.
- `0x0052A4A5` **InflateHuffmanTableBuilder** — InflateHuffmanTreeBuild: builds the DEFLATE literal/length and distance Huffman tables. Allocates a 288-entry work table through the allocator at context offset +32, runs HuffmanCodingFrequencyTable (0x0052A0A1) once per code class using the static base/extra-bit tables (0x005B0878/0x005B08F8 for literal/length, 0x005B0978/0x005B09F0 for distance), and installs DEFLATE error strings (globals 0x005B0AB4..0x005B0B38) into the context error slot at +24 for oversubscribed, incomplete or empty code sets. Returns 0 on success, -4 on allocation failure and -3 on tree build errors.
- `0x00539F70` **InflateHuffmanTableBuilder** — HuffmanCodeLenTableBuild: builds a Huffman decode table for the 19-element code-length alphabet of DEFLATE dynamic blocks. Allocates a 19-entry table through the context vtable allocator at +32, calls sub_53A020 (0x0053A020) to construct the table from the code lengths, and reports oversubscribed (global 0x005DBAC4) or incomplete (global 0x005DBAA0) code sets by writing the error string to context +24 and returning -3; returns -4 when allocation fails.
- `0x0053A4D0` **InflateHuffmanTableBuilder** — HuffmanLiteralDistTableBuild: builds the literal/length and distance Huffman decode tables used by DEFLATE-style decompression. Allocates a 288-entry table through the context vtable allocator at +32, invokes sub_53A020 (0x0053A020) for literal/length codes capped at 0x101 symbols (metadata 0x005B8718/0x005B8798) and for distance codes (0x005B8818/0x005B8890), and maps every failure code to an error string stored on the context at offset 24 (globals 0x005DBAEC..0x005DBB70). Returns 0 on success or a negative error code.
- `0x00562010` **SockAddrBuilder** — SockAddrBuild: builds a sockaddr_in structure in the caller buffer a3 from a host string and a port. Writes family 2 (AF_INET), the port in network byte order via htons (0x0059866C) and the binary address (offset 4) via inet_addr (0x00598666), falling back to gethostbyname (0x00598660) unless the host is the broadcast literal 255.255.255.255 (global 0x005E4E80). Optionally reports the resolved result through output pointer a4. Returns 1 on success, 0 only when gethostbyname fails.
- `0x00562C90` **DeviceSessionInitializer** — DeviceSessionInitialize: initializes a device/session object through a staged sequence. Returns 4 immediately when the first dword at this+0x0 is nonzero; otherwise stores the state code at dword index 36 (0x90), runs sub_562D90 (0x00562D90) and sub_562E30 (0x00562E30), and when those succeed and the state is 6 or 7 or SocketArrayCreate (0x00562D20) succeeds, zeroes dword indices 28/29 (0x70/0x74), stores SingleDelegationCall (0x00563EB0) at index 38 (0x98), sets index 343 (0x55C) to -1, and when a2 is zero enters PollingLoopWithProcessCalls (0x00563000). Returns 0 on success or the failing sub-call result. Invoked by InitWrapper (0x00562C80).
- `0x0056A390` **ConstraintSolverState** — ConstraintForceBufferBuild: iterates the first-array constraint entries (base this+0x230, count this+0x22C, stride 56) and accumulates computed constraint-space force components into the force buffer at this+0x224 indexed by each entry id at +48. Each component combines cross-product terms of the entry row vector with the body angular velocity (this+0x7C/0x84/0x8C), position (this+0x4/0xC/0x14), linear velocity (this+0x64/0x6C/0x74) and the traction constants (globals 0x005E5238/0x005E5240); the entry type byte at +52 selects subtract vs add. Returns the number of entries processed.
- `0x0056A840` **ConstraintSolverState** — ContactConstraintScalarBuild: iterates the contact-constraint array (base this+0x240, count this+0x23C, stride 88) and accumulates a scalar constraint value into the force buffer at this+0x224 indexed by each entry id at +48. The scalar combines cross-product terms of the entry row vector with the body angular velocity (this+0x7C/0x84/0x8C), position (this+0x4/0xC/0x14), linear velocity (this+0x64/0x6C/0x74), the a2/a3 dot products, the traction constants (globals 0x005E5238/0x005E5240) and entry-local +56/+64/+72/+80 factors; the entry type byte at +52 selects subtract vs add. Returns the number of entries processed.
- `0x0056AA60` **ConstraintSolverState** — ConstraintStiffnessMatrixAssembly: assembles the constraint stiffness block matrix for the constraint solver. For each first-array entry it computes nine cross-product terms against the world-space inverse inertia tensor rows (this+0xEC..0x12C), accumulates the diagonal 3x3 block and the off-diagonal 3x3 blocks for every later first-array entry (upper triangle), then cross 3x3 blocks with every joint and contact constraint, into the sparse matrix row-pointer table at this+0x228. Sign is selected by per-entry type-byte equality; this+0xB4 is added as an offset term. Runs on the per-frame physics tick, invoked by InertialTensorVectorTransform (0x0056A240).
- `0x0057E480` **AsyncSocketWindowManager** — AsyncSocketWindowCreate: lazily creates the hidden window used for async socket message dispatch. Returns true when the cached handle global 0x008D3E28 is already set; otherwise zero-fills a WNDCLASSA, registers a class whose window procedure is WindowProcIgnore6666 (global 0x0057AEA0) with the hInstance from this+0x774, calls CreateWindowExA (global 0x0059E290) to build an off-screen 1x1 window (style 0x8000000, position 0x80000000) and stores the resulting handle in global 0x008D3E28. Returns whether the handle is nonzero. Invoked by sub_57BA10.
- `0x0057FC80` **NetworkConnectionManager** — NetworkConnectionThreadEntry: network connection thread entry. Dispatches the virtual thread-init callback through the vtable at this+0x00 (entry at +76), initializes Winsock (0x0057FB90), drains and destroys the pending-object linked list under the mutex at this+0xAD8 (head 0xAC8, tail 0xACC, cursor 0xAD0, count 0xAD4; each node carries a flag byte at +8 and a data object reached through the node first dword), signals the readiness flag at this+0xB38 under a second mutex (0xB3C/0xB40), creates the UDP (this+0x93C) and TCP (this+0x938) sockets, configures both via TCPSocketInit (0x0057C860), marks the thread ready (this+0xA75 = 1) and runs sub_585470 (0x00585470). Returns 0 on success, otherwise 6.
- `0x005816B0` **ThreadPoolQueue** — ThreadPoolJobDequeueByType: dequeues the first node of the mutex-protected list (head this+0xAC8, mutex this+0xAD8, timeout this+0xADC) whose type field (read via ReadFieldAtOffset0x14, 0x005871F0) equals a2. Acquires the mutex via WaitForSingleObject (global 0x0059E1A0) accepting results 0 and 128, walks the list through each node next link, copies the matched node payload into the output a3 via sub_57B800 (0x0057B800), releases the mutex via ReleaseMutex (global 0x0059E1A4) when the handle is non-null and returns 1 if found, else 0.
- `0x00589D6B` **LockAcquirer** — AcquireLockByIndex: trivial forwarder that acquires a synchronization lock by calling CriticalSectionLazyInitEnter (0x0058DFEA) with lock slot index 13 and returns its result unchanged. Callers are sub_587AC0 and sub_589CC6.
- `0x005904C1` **WindowsPlatformCheck** — WindowsNtCheck: fills an OSVERSIONINFOA struct (dwOSVersionInfoSize = 148), calls the GetVersionExA import (global 0x0059E198), and returns TRUE only when the call succeeds and dwPlatformId equals 2 (Windows NT family). Used as a startup OS capability gate by sub_58FD90.
- `0x00597568` **UInt96Arithmetic** — UInt96Add: adds two 96-bit unsigned integers (limbs at this+0x0 low, +0x4 mid, +0x8 high) in place with carry propagation via OverflowCheckedUnsignedAddition (0x00597547). The low-limb add additionally folds a carry-into-mid step when both the low and mid additions overflow; the final high-limb add returns its overflow flag. Matches the CRT __add_12 pattern; called by sub_597621 and sub_5976E8.

## Proposed classes

### DDSSurfaceBuilder

Parses a DDS buffer and builds a linked-list surface hierarchy (0x005026A4). Validates the DDS magic and header, copies header fields into the root object (dim fields at 0xC/0x10, mip count at 0x14, type at 0x44), resolves the pixel format through the table rooted at 0x005D71F8 and allocates per-face/per-mip 84-byte surface sub-objects. Root and sub-objects appear to share a layout, but that is not independently evidenced.

Methods: `0x005026A4`

- `this+0x0000000C` `dword root_dim_c` (write, GUESS)
- `this+0x00000010` `dword root_dim_10` (write, GUESS)
- `this+0x00000014` `dword mip_count` (read_write, DERIVED)
- `this+0x00000044` `dword format_type` (write, GUESS)

### SurfaceReader

Reads a texture/surface region into a caller buffer (0x0050AF57): acquires the region at the cursor offset (this+0x1034/0x1040) through sub_50AB51, copies 16-byte rows from the region base (this+0x106C) sized by the count at this+0x1058, and runs ContactManifoldCleanup over the copy when the flag at this+0x10 is set.

Methods: `0x0050AF57`

- `this+0x00000010` `byte post_process_flag` (read, GUESS)
- `this+0x00001030` `dword cursor_start_offset` (read, GUESS)
- `this+0x00001034` `dword cursor_x` (read, GUESS)
- `this+0x00001040` `dword cursor_y` (read, GUESS)
- `this+0x00001058` `dword row_count` (read, GUESS)
- `this+0x0000106C` `dword region_base` (read, GUESS)
- `this+0x00001070` `dword region_start_offset` (read, GUESS)

### Mp3HuffmanDecoder

MP3 Huffman table builder (0x00510D60): reads stream bytes through the stream-state struct at this+0x14, decodes per-entry control bytes (table index at obj+0x18, value flag at obj+0x1C, state word at obj+0x14), lazily allocates table slots at this+36+index via VTableAllocNullTerminate, fills them from the position table 0x005AF778..0x005AF878, and emits 64-WORD batches into the obj+0x18..0x34 fields when the batch count at obj+0x68 is >= 2. Dispatches through the obj vtable slots at +0 and +4 with state words 80, 30 and 92.

Methods: `0x00510D60`

- `obj+0x00000000` `void* dispatcher_vtable_slot_0` (read, GUESS)
- `obj+0x00000004` `void* dispatcher_vtable_slot_4` (read, GUESS)
- `obj+0x00000014` `word state_word` (read_write, DERIVED)
- `obj+0x00000018` `byte table_index` (read_write, GUESS)
- `obj+0x0000001C` `byte value_flag` (read_write, GUESS)
- `obj+0x00000020` `word batch_word_0` (write, GUESS)
- `obj+0x00000024` `word batch_word_1` (write, GUESS)
- `obj+0x00000028` `word batch_word_2` (write, GUESS)
- `obj+0x0000002C` `word batch_word_3` (write, GUESS)
- `obj+0x00000030` `word batch_word_4` (write, GUESS)
- `obj+0x00000034` `word batch_word_5` (write, GUESS)
- `obj+0x00000068` `dword batch_count` (read, GUESS)
- `this+0x00000000` `void* dispatcher_obj_ptr` (read, GUESS)
- `this+0x00000014` `void* stream_state_ptr` (read, GUESS)
- `*(this+0x14)+0x00000000` `byte* stream_byte_ptr` (read_write, GUESS)

### UiScreenState

UI screen state machine object (0x00515DF2): reads the current state through the dispatch struct at this+0x190 (getter at this+0x194), tracks the exiting and pending flags at this+0x19D/0x1A0, runs TextureSurfaceValidator on the pending path, and issues screen transitions by writing the transition ID to obj+0x14 and invoking the screen vtable method at obj+0x0. Dispatch is finished through VtableDelegateDispatch.

Methods: `0x00515DF2`

- `this+0x0000007C` `dword selection` (read, GUESS)
- `this+0x00000084` `dword selection_target` (read, GUESS)
- `this+0x0000018C` `void* state_flags_base` (read, DERIVED)
- `this+0x00000190` `void* dispatch_struct` (read, GUESS)
- `this+0x00000194` `void* state_getter_ptr` (read, GUESS)
- `this+0x0000019C` `byte not_ready_flag` (read, GUESS)
- `this+0x0000019D` `byte exiting_flag` (read_write, DERIVED)
- `this+0x000001A0` `byte pending_flag` (read_write, DERIVED)
- `this+0x000001E1` `byte dispatch_special_byte` (read, GUESS)
- `obj+0x00000000` `void* screen_vtable_method` (read, GUESS)
- `obj+0x00000014` `dword screen_transition_id` (write, GUESS)

### RotationMatrixBuilder

Builds a 4x4 rotation matrix (0x00522C2D) from two packed-float rows using 3DNow! intrinsics, writing all eight __m64 output slots (rotation rows, zero row, homogeneous row {0, 1.0f}) against the packed 1.0 constant at global 0x005AF900. Emits _m_femms on exit.

Methods: `0x00522C2D`

- `this+0x00000000` `__m64 m64_row_0` (write, GUESS)
- `this+0x00000008` `__m64 m64_row_1` (write, GUESS)
- `this+0x00000010` `__m64 m64_row_2` (write, GUESS)
- `this+0x00000018` `__m64 m64_row_3` (write, GUESS)
- `this+0x00000020` `__m64 m64_row_4` (write, GUESS)
- `this+0x00000028` `__m64 m64_row_5` (write, GUESS)
- `this+0x00000030` `__m64 m64_row_6` (write, GUESS)
- `this+0x00000038` `__m64 m64_row_7` (write, GUESS)

### QuaternionRotationMatrixBuilder

Builds a 4x4 rotation matrix (0x00524553) from a quaternion pair and an angle scalar using 3DNow! intrinsics, normalizing the quaternion via sub_5262C2 and computing the angle terms via PackedFloatingPointMath; writes all eight __m64 output slots against the packed 1.0 constant at global 0x005AF900 and emits _m_femms on exit.

Methods: `0x00524553`

- `this+0x00000000` `__m64 m64_row_0` (write, GUESS)
- `this+0x00000008` `__m64 m64_row_1` (write, GUESS)
- `this+0x00000010` `__m64 m64_row_2` (write, GUESS)
- `this+0x00000018` `__m64 m64_row_3` (write, GUESS)
- `this+0x00000020` `__m64 m64_row_4` (write, GUESS)
- `this+0x00000028` `__m64 m64_row_5` (write, GUESS)
- `this+0x00000030` `__m64 m64_row_6` (write, GUESS)
- `this+0x00000038` `__m64 m64_row_7` (write, GUESS)

### InflateHuffmanTableBuilder

DEFLATE/inflate Huffman table construction cluster: literal/length and distance trees (0x0052A4A5), the 19-symbol code-length alphabet (0x00539F70) and the combined literal/distance builder (0x0053A4D0). The three share a context-object layout (error string at +24, allocator at +32, free at +36, pool/owner handle at +40) and, between the two sub_53A020 users, a shared callee; the DEFLATE error strings are the globals 0x005B0AB4..0x005B0B38 and 0x005DBAA0..0x005DBB70. Grouped as one GUESS class on that shared context shape, not on packet proof of a single type.

Methods: `0x0052A4A5`, `0x00539F70`, `0x0053A4D0`


### SockAddrBuilder

Builds a sockaddr_in structure (0x00562010) in a caller buffer: family 2 (AF_INET), port in network byte order via htons, and a binary address resolved through inet_addr with a gethostbyname DNS fallback unless the host is the broadcast literal 255.255.255.255 (global 0x005E4E80).

Methods: `0x00562010`


### DeviceSessionInitializer

Initializes a device/session object (0x00562C90) through a staged sequence: the already-initialized guard on this+0x0, the stored state code, two staging sub-calls (sub_562D90, sub_562E30), the socket-array fallback (SocketArrayCreate), the stored delegation result and sentinel, and the optional blocking polling loop (PollingLoopWithProcessCalls).

Methods: `0x00562C90`

- `this+0x00000000` `dword init_marker` (read, GUESS)

### ConstraintSolverState

Vehicle constraint-solver state: the first/joint/contact constraint arrays (this+0x230/0x238/0x240 with counts at 0x22C/0x234/0x23C), the force buffer at this+0x224 and the matrix row-pointer table at this+0x228, the body state (position 0x4/0xC/0x14, linear velocity 0x64/0x6C/0x74, angular velocity 0x7C/0x84/0x8C, inverse inertia 0xEC..0x12C, offset term 0xB4) and the traction constants (globals 0x005E5238/0x005E5240). Three per-frame passes operate on this state: force-buffer build (0x0056A390), contact scalar build (0x0056A840) and stiffness block-matrix assembly (0x0056AA60), the latter invoked by InertialTensorVectorTransform.

Methods: `0x0056A390`, `0x0056A840`, `0x0056AA60`

- `this+0x00000004` `double body_position_x` (read, GUESS)
- `this+0x0000000C` `double body_position_y` (read, GUESS)
- `this+0x00000014` `double body_position_z` (read, GUESS)
- `this+0x00000064` `double body_linear_velocity_x` (read, GUESS)
- `this+0x0000006C` `double body_linear_velocity_y` (read, GUESS)
- `this+0x00000074` `double body_linear_velocity_z` (read, GUESS)
- `this+0x0000007C` `double body_angular_velocity_x` (read, GUESS)
- `this+0x00000084` `double body_angular_velocity_y` (read, GUESS)
- `this+0x0000008C` `double body_angular_velocity_z` (read, GUESS)
- `this+0x000000B4` `double inertia_offset_term` (read, GUESS)
- `this+0x000000EC` `double inverse_inertia_00` (read, GUESS)
- `this+0x000000F4` `double inverse_inertia_01` (read, GUESS)
- `this+0x000000FC` `double inverse_inertia_02` (read, GUESS)
- `this+0x00000104` `double inverse_inertia_10` (read, GUESS)
- `this+0x0000010C` `double inverse_inertia_11` (read, GUESS)
- `this+0x00000114` `double inverse_inertia_12` (read, GUESS)
- `this+0x0000011C` `double inverse_inertia_20` (read, GUESS)
- `this+0x00000124` `double inverse_inertia_21` (read, GUESS)
- `this+0x0000012C` `double inverse_inertia_22` (read, GUESS)
- `this+0x00000224` `void* force_buffer` (read_write, DERIVED)
- `this+0x00000228` `void* matrix_row_table` (read_write, DERIVED)
- `this+0x0000022C` `dword first_constraint_count` (read, DERIVED)
- `this+0x00000230` `void* first_constraint_array` (read, DERIVED)
- `this+0x00000234` `dword joint_constraint_count` (read, GUESS)
- `this+0x00000238` `void* joint_constraint_array` (read, GUESS)
- `this+0x0000023C` `dword contact_constraint_count` (read, DERIVED)
- `this+0x00000240` `void* contact_constraint_array` (read, DERIVED)

### AsyncSocketWindowManager

Lazily creates and caches the hidden window used for async socket message dispatch (0x0057E480): returns the cached handle global 0x008D3E28 when present, otherwise registers a WNDCLASSA whose window procedure is WindowProcIgnore6666 with the hInstance from this+0x774 and creates an off-screen 1x1 window (style 0x8000000, position 0x80000000).

Methods: `0x0057E480`

- `this+0x00000774` `void* instance_handle` (read, GUESS)

### NetworkConnectionManager

Network connection thread context (0x0057FC80): the TCP/UDP socket handles at this+0x938/0x93C, the ready byte at this+0xA75, the pending-object mutex-protected list at this+0xAC8..0xAD4 (mutex 0xAD8, timeout 0xADC), the readiness flag under the second mutex at this+0xB38/0xB3C/0xB40, and the vtable at this+0x00 through which the thread-init callback (entry at +76) is dispatched. Winsock init, socket creation and final post-init processing run through sub_57FB90, sub_57C860 and sub_585470.

Methods: `0x0057FC80`

- `this+0x00000000` `void* vtable_ptr` (read, GUESS)
- `this+0x00000938` `dword tcp_socket` (write, GUESS)
- `this+0x0000093C` `dword udp_socket` (write, GUESS)
- `this+0x00000A75` `byte ready_byte` (write, GUESS)
- `this+0x00000AC8` `void* list_head` (read_write, GUESS)
- `this+0x00000ACC` `void* list_tail` (write, GUESS)
- `this+0x00000AD0` `void* list_cursor` (read_write, GUESS)
- `this+0x00000AD4` `dword list_count` (write, GUESS)
- `this+0x00000AD8` `void* list_mutex` (read, GUESS)
- `this+0x00000ADC` `dword list_timeout` (read, GUESS)
- `this+0x00000B38` `byte readiness_flag` (write, GUESS)
- `this+0x00000B3C` `void* second_mutex` (read, GUESS)
- `this+0x00000B40` `dword second_timeout` (read, GUESS)
- `obj+0x0000004C` `void* thread_init_vtable_entry` (read, GUESS)
- `*(this+0xAC8)+0x00000000` `void* first_node_ptr` (read, GUESS)
- `*(this+0xAC8)+0x00000008` `byte node_flag_byte` (read, GUESS)
- `*(*(this+0xAC8)+0x0)+0x00000000` `void* node_data_object_ptr` (read, GUESS)
- `*(*(*(this+0xAC8)+0x0)+0x0)+0x00000000` `void* data_vtable_method` (read, GUESS)

### ThreadPoolQueue

Mutex-protected job queue (0x005816B0): dequeues the first node whose type field (ReadFieldAtOffset0x14) matches the requested type, walking the list from the head at this+0xAC8 under the mutex at this+0xAD8 with timeout this+0xADC and copying the matched payload through sub_57B800.

Methods: `0x005816B0`

- `this+0x00000AC8` `void* list_head` (read, GUESS)
- `this+0x00000AD0` `void* list_walk_cursor` (read_write, GUESS)
- `this+0x00000AD4` `dword list_count` (read, GUESS)
- `this+0x00000AD8` `void* list_mutex` (read, GUESS)
- `this+0x00000ADC` `dword list_timeout` (read, GUESS)
- `*(this+0xAC8)+0x00000000` `void* first_node_ptr` (read, GUESS)

### LockAcquirer

Trivial forwarder (0x00589D6B) that acquires a synchronization lock by calling CriticalSectionLazyInitEnter with lock slot index 13 and returning its result unchanged; callers are sub_587AC0 and sub_589CC6.

Methods: `0x00589D6B`


### WindowsPlatformCheck

Windows platform gate (0x005904C1): fills an OSVERSIONINFOA struct (dwOSVersionInfoSize = 148), calls GetVersionExA (global 0x0059E198) and returns TRUE only when the call succeeds and dwPlatformId equals 2 (Windows NT family).

Methods: `0x005904C1`


### UInt96Arithmetic

96-bit unsigned integer addition (0x00597568): adds three-limb values in place (this+0x0 low, +0x4 mid, +0x8 high) with full carry propagation through OverflowCheckedUnsignedAddition, matching the CRT __add_12 pattern; called by sub_597621 and sub_5976E8.

Methods: `0x00597568`

- `this+0x00000000` `dword limb_low` (read_write, GUESS)
- `this+0x00000004` `dword limb_mid` (read_write, GUESS)
- `this+0x00000008` `dword limb_high` (read_write, GUESS)

## Compatibility contracts

- **DdsSurfaceHeaderContract** — DDS parsing contract: the buffer starts with the DDS magic 542327876, a remaining header length of at least 0x7C after the magic dword, pixel-format flags at buffer offset 112 masked by 0xFC00 selecting 64512 (6 cubemap faces) or 0 (1 face), mip count at offset 28 (default 1), and an optional data region at offset 1152 reached only when at least 0x400 bytes remain. Surface sub-objects are 84 bytes; format/length failure returns -2147467259 and allocation failure returns -2147024882.
- **Mp3HuffmanDecoderAbi** — MP3 Huffman table builder contract: the stream-state struct at this+0x14 holds the byte pointer at field 0, the remaining count at field 1 and the refill callback at index 3; the dispatcher object carries the state word at obj+0x14 with the evidenced state values 80, 30 and 92, the table index at obj+0x18, the value flag at obj+0x1C, the lazy table slots at this+36+index (allocated via VTableAllocNullTerminate) and the batch-count field at obj+0x68 which triggers a 64-WORD batch output when >= 2. Table data is drawn from the position table global 0x005AF778..0x005AF878.
- **DeflateHuffmanErrorContract** — DEFLATE inflate Huffman-build error contract: the context object stores a descriptive error string at offset +24 and returns -3 (oversubscribed/incomplete tree), -4 (allocation failure) or -5 (incomplete). The literal/length and distance metadata arrays live at globals 0x005B0878..0x005B09F0 (HuffmanCodingFrequencyTable path) and 0x005B8718..0x005B8890 (sub_53A020 path); the error strings are the globals 0x005B0AB4..0x005B0B38 and 0x005DBAA0..0x005DBB70.
- **ConstraintSolverArrayLayout** — Vehicle constraint-solver arrays: first constraints at this+0x230 (count 0x22C, stride 56, entry id at +48, type byte at +52), joint constraints at this+0x238 (count 0x234, stride 132, joint id at +124, type byte at +128, axis pairs at +72/+80/+88 and +96/+104/+112), contact constraints at this+0x240 (count 0x23C, stride 88, contact id at +48, type byte at +52, axis pairs at +24/+32/+40 and +64/+72/+80). Force components accumulate into the buffer at this+0x224 indexed by entry id; the matrix row-pointer table sits at this+0x228. The add-vs-subtract sign is selected by type-byte equality.
- **SockAddrBuildProtocol** — sockaddr_in construction in the caller buffer: family 2 (AF_INET) at offset 0, port at offset 2 in network byte order via htons, binary address at offset 4 resolved through inet_addr with a gethostbyname fallback unless the host is the broadcast literal 255.255.255.255 (global 0x005E4E80). Returns 1 on success and 0 only when gethostbyname fails.
- **AsyncSocketWindowContract** — The async-socket message window is created once and cached in global 0x008D3E28. It registers a WNDCLASSA whose window procedure is WindowProcIgnore6666 (global 0x0057AEA0) with the hInstance from this+0x774, and creates an off-screen 1x1 window with style 0x8000000 at position 0x80000000 via CreateWindowExA (global 0x0059E290) after RegisterClassA (global 0x0059E29C).
- **MutexProtectedListContract** — Mutex-protected linked-list contract shared by the network connection thread and the thread-pool dequeue: list head at this+0xAC8, tail 0xACC, cursor 0xAD0, count 0xAD4, mutex handle 0xAD8 and timeout 0xADC; acquisition via WaitForSingleObject (global 0x0059E1A0) treats results 0 and 128 as acquired, and release via ReleaseMutex (global 0x0059E1A4) is conditional on a non-null handle.
- **WindowsNtPlatformGate** — Startup OS capability gate: fills an OSVERSIONINFOA struct (dwOSVersionInfoSize = 148), calls GetVersionExA (global 0x0059E198) and returns TRUE only when the call succeeds and dwPlatformId equals 2 (Windows NT family).

## Unresolved

- Mixed-scope packet: the 20 functions span DDS texture parsing, UI screen state, MP3 and inflate Huffman decoding, SIMD matrix math, networking (sockaddr build, async window, connection thread, thread pool, lock acquisition), vehicle constraint-solver assembly, Windows platform gating and CRT 96-bit arithmetic. The UiPlatformAndOptions subsystem label follows the packet scope; the functions do not share one coherent class family.
- DDSSurfaceBuilder: the root header copy writes buffer offset 16 into this+0xC and offset 12 into this+0x10, yet the mip loop treats this+0xC as width and this+0x10 as height; the exact DDS field-to-semantic mapping is unresolved. Root and per-level surface sub-objects appear to share a layout (sub-object offsets 0, 4, 8, 12, 16, 20, 48, 52, 56, 60), but that shared-layout claim is not independently evidenced, so the sub-object fields are not proposed as class fields.
- DDSSurfaceBuilder: the concrete format ids (for example 827611204, 844388420, 844715353, 861165636, 877942852, 894720068, 1498831189) and their block-size semantics are inferred from the stride arithmetic, not confirmed; the pixel-format table walk termination (a zero sentinel at the first dword of each 9-dword entry) is also inferred.
- SurfaceReader: sub_50AB51 semantics (surface lock vs read) and its constant argument 1 are DERIVED, not packet facts; the copy treats the source as a run of 16-byte rows and whether this+0x1058 is a row count or a byte quantity is not independently verified.
- Mp3HuffmanDecoder: the dispatcher vtable targets behind obj (slots +0 and +4) and the stream-state refill callback at index 3 are indirect calls whose concrete implementations are unknown. The fields this+0x18 and this+0x20 are flagged by the packet but absent from the raw body and are left unresolved. The caller CommandDispatchStateMachine (0x0051126A) drives this function through a state machine whose transition contract is not visible here.
- UiScreenState: the state enum returned by the getter at this+0x194 is only evidenced as values 1 and 2; the screen object behind obj and the semantics of the transition IDs 34 and 58 are unidentified; the gate flag at this+0x19C and the dispatch byte at this+0x1E1 are inferred from control flow, not packet facts.
- RotationMatrixBuilder: the read-only global qword_5AF900 is flagged as read but the raw source renders the constants inline (0x3F8000003F800000 and 1065353216); the global-to-constant mapping is not established. The cluster prelabel calling this a structural twin of 0x00522B5B is unverified because the pfpnacc/pswapd lane reductions differ.
- QuaternionRotationMatrixBuilder: the exact contract of sub_5262C2 (normalization vs reduction) and PackedFloatingPointMath (sin/cos approximation precision) is unconfirmed; the field R/W annotations mark this+0x0 as RW and the remaining output slots as read while the raw source writes all eight slots, a discrepancy left unresolved.
- InflateHuffmanTableBuilder: the three functions are grouped into one GUESS class on the shared context-object layout (error string at +24, allocator at +32, free at +36, pool/owner handle at +40) and, for the two sub_53A020 users, a shared callee; the underlying context object type is not identified, and the a5 base in HuffmanCodeLenTableBuild is a different register than the a9 bases, so single-class ownership is not proven. The 0x101 literal/length symbol cap and the sub_53A020 table layout are unspecified.
- SockAddrBuilder: the value stored through a4 is the sockaddr buffer address when inet_addr succeeds but the hostent pointer when DNS resolution is used; the two types are inconsistent and the caller's expectation is unknown. The a3 buffer is written without length validation and the triple dereference at hostent +12 is assumed to be h_addr_list[0].
- DeviceSessionInitializer: the roles of sub_562D90 and sub_562E30 are undocumented (each returns zero on success); the semantics of the stored state at dword indices 28, 29, 36, 38 and 343 are not derivable from this packet; the cluster-copy twin at 0x00405160 is not analyzed.
- ConstraintSolverState: the identity of the owning object is not established; the vehicle constraint-solver interpretation comes from the existing analysis fill and the caller InertialTensorVectorTransform, not from packet proof. The type-byte add/subtract enum values, the exact meaning of this+0xB4 (inverse mass is an inference) and the entry strides 56/132/88 are read directly from the raw source and are not independently confirmed.
- ConstraintSolverState: the global 0x005E523C (byte_5E523C, JointStiffnessDouble per prior analysis) is not read in either the force-buffer or the contact-scalar builder's raw source; its role is unresolved.
- AsyncSocketWindowManager: five write-only globals at 0xFF00000000005445/05446/05449/0544D/0544E are flagged by packet facts but absent from the raw source; their addresses look like malformed 64-bit artifacts and are unverifiable from this packet. The handling of message 0x6666 inside WindowProcIgnore6666 is external to this function.
- NetworkConnectionManager: class ownership is unknown and lpParameter is an opaque thread-context object; the drained list at this+0xAC8 holds objects whose vtable invocation semantics (method index, argument 1) are not resolved; sub_585470's role as final thread processing is undocumented.
- ThreadPoolQueue: field this+0xAD4 is recorded as read in packet facts but the raw body never references it (possibly an element-count field used by a sibling queue path). When the mutex is not acquired the decompiled flow would dereference a null walk pointer; likely an IDA artifact of a guarded abort path rather than reachable code.
- LockAcquirer: the subsystem owning critical-section slot 13 is unknown; why callers sub_587AC0 and sub_589CC6 route lock acquisition through this indirection instead of calling CriticalSectionLazyInitEnter directly is unresolved.
- WindowsPlatformCheck: the globals 0xFF00000000005370 and 0xFF00000000005374 carry sign-extended stack-frame addresses (the leading run of F digits indicates 32-bit sign extension into a 64-bit IDA name); they are treated as the version-info struct stack slots (write dwOSVersionInfoSize, read dwPlatformId) rather than true data globals.
- UInt96Arithmetic: the higher-level 96-bit value this add operates on (timer, counter, or checksum) is not resolvable from this packet; the carry-into-mid folding only when the low add also overflows is compiler-produced control flow and the exact source structure is not recoverable.
- No state machine is proposed for the constraint solver, the network connection thread or the MP3 decoder: the states evidenced there (thread ready byte, list drain) lack transition semantics. The only proposed state machine is UiScreenStateMachine (GUESS), built from the control flow of UiScreenStateTick.
