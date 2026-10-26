# MathAndCollision

Scope: `math_and_collision`  
Trust: `DERIVED`

Proposal for the math_and_collision slice of Wave 5. The functions fall into three groups. (1) Pure math utilities: vector3 add/subtract (0x4EA930, 0x4ED710), 3x3 matrix-vector multiply (0x4ED7B0), vector3 dot product (0x4EFEE0), an SSE constant matrix init (0x52087E) and a 3DNow translation-matrix constructor (0x52273B). (2) A particle-system orientation-axis updater (0x4CC840) that walks a 10-float strided axis array, a vector-field presence test (0x4CE8F0), and a scene-relative direction-vector computation feeding a DirectX vertex buffer (0x55D5C0, 0x55D460). (3) Array containers and their operations: teardown loops (0x4DD470, 0x4DED20), a sorted LRU array with eviction and reporting (0x4DEDB0, 0x4DF030), lazy-init entry cleanup (0x4E0E20), respawn-state array reset (0x4E3890), bounded index reads and lookups (0x54E240, 0x5504D0, 0x558CB0, 0x55BFD0, 0x55BFF0), batch walkers (0x53C190, 0x54C270), a socket array create/search pair sharing a count-at-0x6C base-at-0x8 layout (0x562D20, 0x563230), an int-array allocator (0x560B60), a five-dword allocation descriptor (0x5646D0), and a network record array with linear-interpolation addressing and shift-removal (0x5648B0, 0x564990). Almost every owner is UNKNOWN; the groupings below are DERIVED/GUESS proposals, not confirmed identities.

## Function roles

- `0x004CC840` **ParticleMatrixRotationUpdater** — Recalculates a strided array of particle orientation axes: obtains a source direction (and a Y component) from an object reached through VirtualDispatchHelper(&dword_5EA510) at offset +36, scales X and Z by -0.03125, walks 10-float entries from unk_8AC840 to the end marker flt_8ACAC0, writes each entry's direction, computes the cross product of the two direction rows, stores it as the entry axis, and normalizes the axis to length this[4]/2 (default X-axis of that length when magnitude is zero).
- `0x004CE8F0` **VectorFieldPresenceStruct** — Pure presence check over three float channels of the input struct: returns TRUE when the float at offset 0x00 is non-zero OR the float at offset 0x14 is non-zero OR the float at offset 0x28 is non-zero; otherwise FALSE. No side effects; frame-path helper called by 0x004EE2D0.
- `0x004DD470` **SingleResourceArrayOwner** — Cleanup helper: frees a single resource pointer at offset 8 via FreeWrapper_7bcf when non-null, then when the array pointer at offset 16 is non-null reads the element count from the length header 4 bytes before the array pointer, iterates backward over 24-byte elements calling ShortComputation_d4d0 on each, and frees the allocation (starting at the length header) via FreeWrapper_7bcf; returns the single-free result when no array is present.
- `0x004DED20` **DualArrayOwner** — Destructor for an object holding two heap arrays whose element counts live in the allocation header 4 bytes before each block: zeroes head fields at offsets 0x4/0x8, tears down the first array (pointer at 0xC, 12-byte elements, per-element teardown sub_4DD4C0) from last to first, frees the block via FreeWrapper_7bcf, zeroes 0xC/0x10, tears down the second array (pointer at 0x14, 24-byte elements, per-element ShortComputation_d4d0), frees it, zeroes 0x14/0x18, and returns 0.
- `0x004DEDB0` **SortedLRUArray** — Inserts a 9-float (36-byte) entry into a fixed-capacity sorted array (max 20 entries, stride 9 floats, count at this+0x18, entries from this+0x20): rejects exact duplicates with a -1 index report via sub_4DF110, evicts a minimum-score LRU candidate when full by shifting entries left, finds the sorted insertion position by key a2[1], shifts entries right to make room, copies the entry, increments the count, and returns the sub_4DF110 report of the inserted key and index.
- `0x004DF030` **SortedLRUArray** — Builds a 9-float stack entry (type marker 1 in slot 0, value a2 in slot 1, slots 2-8 zeroed) and inserts it into the sorted LRU array via SortedArrayInsertWithLRUEviction only when the dword flag at this+0x18 is nonzero; returns the flag value when the insertion is skipped, else the insertion result.
- `0x004E0E20` **ArrayEntryLazyInitSubsystem** — Per-entry lazy-cleanup within an array owned by a subsystem object: selects an array entry by scaling the a2 index by 74 dwords, runs one-time lazy initialization (0x4E0D00) on a sub-block 81 dwords into the entry, advances 98 dwords, runs lazy initialization on the second sub-block, then if that sub-block's first dword is nonzero flags a state condition through FlagFieldBitManipulation(1, 1, 0, 0); otherwise returns the initialization result.
- `0x004E3890` **VehicleRespawnState** — Resets an array of per-vehicle respawn state entries: reads the entry count at this+0xBA8, and when it is greater than zero iterates entries with a 187-float (748-byte) stride starting at this+747 floats, calling sub_4DF110(current_entry, 0.0, -1) on each and clearing the entry's sixth float at this+0xBC4 to 0.0; returns the last-read count. Called by VehicleRespawnReset (0x004E0800).
- `0x004EA930` **Vector3** — Per-component 3-float vector subtraction: writes a3[0..2] = a1[0..2] - a2[0..2] and returns the output pointer a3. Invoked from 3D collision, vehicle contact force and vehicle geometry proximity paths.
- `0x004ED710` **Vector3** — Per-component 3-float vector addition: writes a3[0..2] = a1[0..2] + a2[0..2] and returns the output pointer a3. Invoked from vehicle geometry proximity and ray/triangle intersection paths.
- `0x004ED7B0` **Matrix33VectorMultiplyHelper** — Multiplies a 3x3 matrix (nine floats at offsets 0x0..0x20) by a three-component vector a2 and stores the result in a3; each output component is the dot of one matrix row with a2. Returns the original input vector pointer a2. Used for rigid-body transforms; called by VehicleGeometryProximityTest (0x004ED420) and RayTriangleIntersectionWithBarycentricCoordinate (0x004EFBD0).
- `0x004EFEE0` **Vector3DotProductHelper** — __fastcall 3-component dot product over two float vectors a1 and a2: returns a1[0]*a2[0] + a1[1]*a2[1] + a1[2]*a2[2] as double. No branches, globals or callees. Single static caller: RayTriangleIntersectionWithBarycentricCoordinate (0x004EFBD0).
- `0x0052087E` **SSE52ByteMatrixInitializer** — Initializes a 52-byte matrix/struct at a1 from SSE constants and the __m128 result of EmptyStub_8bd0: row 0 is the fixed constant xmmword_8D61D0, the low dword of xmmword_8D61C0 lands at +0x10 and +0x2C, the full vector at +0x30, and partial stores from the EmptyStub result plus an XOR of its shuffled value with xmmword_8D61B0 fill +0x14/+0x1C/+0x24. Returns a1.
- `0x0052273B` **ThreeDNowTransformBuilder** — Builds a 4x4 transformation matrix stored as 8 __m64 slots in a1: enters 3DNow mode, seeds identity-like constants (1.0f at this+0x0 and this+0x28, packed 1.0f pair at this+0x10), packs the three float parameters a2, a3, a4 into the last two rows (this+0x30 = punpckldq(a2, a3), this+0x38 = punpckldq(a4, 1.0f)), exits 3DNow mode and returns a1.
- `0x0052DA10` **ConditionalSizedBufferZeroer** — Zero-initializes a per-object buffer at this+4 whose element count depends on global dword_8B0108: 576 elements by default, 1152 when the flag is clear; memset clears 4 * v2 bytes (4-byte cells). Returns 0 unconditionally. Called from CMpegBase_Open (0x0052E090) and CMpegFilePlayer_Open (0x0052E1D0), i.e. MPEG open paths.
- `0x0053C190` **IterateStructArray42Helper** — Fixed-count batch walk over 42 contiguous elements starting at dword_8B6C28 with a 76-byte stride, calling sub_556220 on each element; returns the result of the last call.
- `0x0054BF10` **UiSceneStateWordNormalizer** — Walks a linked list of UI nodes (head at this[129], next pointer at node+0x10); for each node iterates its state-word array (count at node+0x118, base at node+0x11C) and sign-extends each state word by replicating the signed upper 16 bits into the low 16 bits. Called by RecursiveTraversal (0x0054BCD0) as part of UI scene-node state normalization.
- `0x0054C270` **FloatStructArray256Initializer** — Fixed-count batch initialization of a 256-element array of 104-byte float-bearing structs at unk_8B8F40 (stride 26 dwords), calling F_10FloatStructInitializer (0x0053B130) on each element; returns the last initializer result.
- `0x0054E240` **IndexedElementArray** — Bounds-checked indexed read: when a2 is below the element count at this+0x120, computes an element entry address from the base pointer at this+0x124 with stride 36 (36*a2+8), dereferences it to a target pointer, and returns the DWORD at target+4; returns 0 when a2 is out of range.
- `0x005504D0` **BinkFrameLookupArray** — Bounds-checked lookup into a frame array: index a3 validated against the count at this+0xA4; entry base is this+0xA8 + 148*a3. For terminal frames (entry field 18 <= 1), optionally resets the Bink video decoder via BinkVideoFrameDecoder when entry field 36 and global dword_8B6AC4 are both non-zero, clearing bit 0x400 on the decoder buffer, then returns the frame pointer at entry field 35. For non-terminal frames, a2 == -1 returns the frame pointer directly; otherwise a sub-indexed lookup against the list at entry field 19 (offset by entry field 20) yields a frame offset of 96 times the selected list entry.
- `0x00558CB0` **ParticleElementArray** — Bounds-checked array element flag setter: when index a2 is below the element count at this[0x2C], calls sub_53B330 on the element entry at array base + a2*128 + 16 with three caller arguments, then sets flag 0x4000 on the element base dword at array base + a2*128; returns the element base pointer on success, or the raw index a2 when out of bounds. Per-frame path called by ParticleCollisionSpark (0x004CB620), WheelRenderObjectPerFrameUpdate (0x004CB860), ParticleTrailEmitter (0x004CBC50) and ParticleInstanceUpdate (0x004CC1D0).
- `0x0055BFD0` **CountedDwordArray** — Bounded array accessor: returns element a2 of a dword array that follows a count field; when a2 is >= the count at this+0x4 the accessor fails closed and returns 0, otherwise returns the dword at this + 8 + 4*a2. Used by UtilityFunction_9160 (0x004F9160) and sub_55F0D0 (0x0055F0D0).
- `0x0055BFF0` **SlotArrayDelegator** — Slot-indexed conditional delegator: loads the element pointer at this dword index a2+2, returns -1 when null, forwards a3..a7 to sub_55BD20, returns -1 when that sub-call fails, otherwise stores the slot index a2 back into this[0] and returns the sub-call result.
- `0x0055D460` **DxVertexBufferVectorStore** — Stores a 3-component vector (a2, a3, a4) at this+0x44/+0x48/+0x4C, normalizes all three to unit length when the vector length is non-zero, then calls DirectXVertexBufferTextureCoordinateSetup with global dword_8B78A0, this and its handle at this+0x4 under mode 5, and finally ORs dirty flag 0x800 into dword_8B8F28+236; returns dword_8B8F28. Invoked by sub_55A500 on a DirectX vertex-buffer normal/vector update path.
- `0x0055D5C0` **SceneRelativeDirectionComputer** — Computes and stores a normalized direction vector on a scene-node object: sets dirty flag 0x40000 at this+0x14, walks a context node list rooted at dword_8B8F28 to find a target entry, obtains a scene position (the object's stored position at this+0xE8..0xF0 or SceneNodePositionGetter result depending on the bit-0x10 flag at the node reached through this+0x138 at byte +0x3C), combines it with the caller offset a2[9..11], and stores a twice-normalized delta direction at this+0x100/0x104/0x108.
- `0x00560B60` **IntArrayContainer** — Initializes an integer-array container object: zeroes the element-count word at this+0x0, allocates backing storage for a2 integers via OperatorNewNhMallocWrapper(4 * a2), stores the pointer at this+0x4, and returns this as the initialized container.
- `0x00562D20` **SocketArrayContainer** — Creates a pre-allocated array of sockets: guarded by the count at this+0x6C (returns 0 when not > 0); loops over 28-byte entries off the array base pointer at this+0x8 calling socket(2, 2, 17) and storing the handle at entry+0 with entry+4 and entry+8 zeroed; on a socket() == -1 break returns 1 when no sockets were created, otherwise truncates this+0x6C to the created count and returns 0; returns 0 when the full count is reached. Called by DeviceInitializationWithStateSetup (0x00562C90), MultiStageInitializationChainWithErrorChecking (0x00563020) and NetworkConnection (0x00563260).
- `0x00563230` **SocketArrayContainer** — Searches a container's array of 7-dword-stride elements for an ID value equal to a2 and returns the zero-based element index, or -1 when no element matches; the element count is read from the container at offset 108 (0x6C) and the array base pointer at offset 8 (elements examined starting 4 bytes into that array). Called by NetworkConnection.
- `0x005646D0` **ArrayDescriptorFactory** — Allocates a five-dword descriptor and a backing array of a2 element slots, then fills every slot with a distinct heap object built by Malloc0x18ByteStructWithInnerBuffer(a6): descriptor index 0 holds the element array pointer, index 1 the element count a2, index 2 the factory parameter a6, indices 3 and 4 the caller-supplied values a4 and a5. Returns the descriptor pointer. Shared by MemoryObjectAllocator (0x00562B50), DirectDrawDisplayModeInit (0x00563E00) and StructAllocInitWithSwitchBasedType (0x005642F0).
- `0x005648B0` **NetworkRecordArray** — Straight-line arithmetic helper matching the ABI label Linear_Interpolation: reads a 32-bit value at object offset +20 as a base and one at offset +8 as a delta, returns base + a2 * delta (a2 acts as the interpolation factor). No branches, calls or side effects.
- `0x00564990` **NetworkRecordArray** — Removes the element at index a2 from a packed record array rooted at a1: when a2 is not the final element it shifts the array tail down one record by copying a1[2] * (count - a2 - 1) bytes from element a2 + 1 onto element a2 via sub_58B130 (element addresses resolved through LinearInterpolation), then decrements the stored count at a1[0] and returns the new count. The single caller NetworkConnection suggests a connection/record list that shrinks when an entry is dropped.

## Proposed classes

### Vector3

Three-component float vector container used by the arithmetic helpers: per-component add (0x4ED710) and subtract (0x4EA930) write a caller output pointer from two input vectors. The this-relative reads at 0x0/0x4/0x8 record the first input vector's components.

Methods: `0x004EA930`, `0x004ED710`

- `this+0x00000000` `float x` (read, DERIVED)
- `this+0x00000004` `float y` (read, DERIVED)
- `this+0x00000008` `float z` (read, DERIVED)

### Matrix33VectorMultiplyHelper

Row-major 3x3 float matrix (nine floats at 0x0..0x20) multiplied by a three-component vector; used as a rigid-body transform primitive by vehicle-geometry proximity and ray/triangle intersection paths.

Methods: `0x004ED7B0`

- `this+0x00000000` `float m00` (read, DERIVED)
- `this+0x00000004` `float m01` (read, DERIVED)
- `this+0x00000008` `float m02` (read, DERIVED)
- `this+0x0000000C` `float m10` (read, DERIVED)
- `this+0x00000010` `float m11` (read, DERIVED)
- `this+0x00000014` `float m12` (read, DERIVED)
- `this+0x00000018` `float m20` (read, DERIVED)
- `this+0x0000001C` `float m21` (read, DERIVED)
- `this+0x00000020` `float m22` (read, DERIVED)

### Vector3DotProductHelper

3-component float dot product returning a double; single consumer is the ray/triangle intersection query (0x004EFBD0). Structural twin of the 0045eb00 cluster whose packet name (Vector3ScalarMultiply) is not confirmed by this packet.

Methods: `0x004EFEE0`

- `this+0x00000000` `float vx` (read, DERIVED)
- `this+0x00000004` `float vy` (read, DERIVED)
- `this+0x00000008` `float vz` (read, DERIVED)

### ParticleMatrixRotationUpdater

Particle-system orientation-axis updater: reads a source direction through a virtual dispatch and rewrites a strided (10-float) array of particle axis rows between unk_8AC840 and the end marker flt_8ACAC0, normalizing each axis to a target half-length stored at this+0x10.

Methods: `0x004CC840`

- `this+0x00000010` `float axis_half_length` (read, DERIVED)

### VectorFieldPresenceStruct

Struct with three float channels at 0x0/0x14/0x28 whose non-zero presence is tested as a frame-path helper; the channel semantics (velocity/magnitude) are not evidenced by the raw source.

Methods: `0x004CE8F0`

- `this+0x00000000` `float channel0` (read, DERIVED)
- `this+0x00000014` `float channel1` (read, DERIVED)
- `this+0x00000028` `float channel2` (read, DERIVED)

### SingleResourceArrayOwner

Object holding one scalar resource pointer at offset 8 and one heap array pointer at offset 16; teardown frees the resource and runs per-element destructors (24-byte elements) before freeing the array allocation at its count-header base.

Methods: `0x004DD470`

- `this+0x00000008` `pointer resource_ptr` (read, DERIVED)
- `this+0x00000010` `pointer array_ptr` (read, DERIVED)

### DualArrayOwner

Object holding two heap arrays (12-byte and 24-byte elements) whose counts live in each allocation's header; the destructor clears head fields 0x4/0x8, tears each array down element-by-element, frees each block at its header base, and zeroes the pointer/companion pairs 0xC/0x10 and 0x14/0x18.

Methods: `0x004DED20`

- `this+0x00000004` `int head0` (write, GUESS)
- `this+0x00000008` `int head1` (write, GUESS)
- `this+0x0000000C` `pointer array1_ptr` (read_write, DERIVED)
- `this+0x00000010` `int array1_companion` (write, GUESS)
- `this+0x00000014` `pointer array2_ptr` (read_write, DERIVED)
- `this+0x00000018` `int array2_companion` (write, GUESS)

### SortedLRUArray

Fixed-capacity (20-entry) sorted array of 36-byte records ordered by key at entry[1], with duplicate rejection, minimum-score LRU eviction (scored against globals flt_59E670/flt_5AD140), right-shift insertion, and a reporting callback (0x4DF110). The typed insert (0x4DF030) gates insertion on the flag at this+0x18 and stamps entry slot 0 with a type marker.

Methods: `0x004DEDB0`, `0x004DF030`

- `this+0x00000018` `int entry_count` (read, DERIVED)
- `this+0x0000001C` `int tail_slot` (read, GUESS)
- `this+0x00000020` `pointer entries` (read, DERIVED)
- `this+0x00000024` `float first_entry_component_1` (read, GUESS)
- `this+0x0000003C` `float first_entry_component_7` (read, GUESS)

### ArrayEntryLazyInitSubsystem

Array of entries (74-dword stride) whose per-entry lazy initialization runs on two sub-blocks (81 and 98 dwords into the entry) via a lazy-init callback (0x4E0D00), with a flag-state path through FlagFieldBitManipulation (0x54C030) when the second sub-block is non-empty. Layout is grounded only in raw addressing.

Methods: `0x004E0E20`


### VehicleRespawnState

Per-vehicle respawn state array: entry count at this+0xBA8, entries at a 748-byte stride starting at this+747 floats, per-entry state reset through sub_4DF110(entry, 0.0, -1) plus clearing the entry sixth float at this+0xBC4. Reset invoked by VehicleRespawnReset (0x004E0800).

Methods: `0x004E3890`

- `this+0x00000BA8` `int entry_count` (read, DERIVED)
- `this+0x00000BC4` `float entry_state_float` (read_write, DERIVED)

### SSE52ByteMatrixInitializer

Initializes a 52-byte matrix/struct from SSE constants (xmmword_8D61D0/8D61C0/8D61B0) and the __m128 result of EmptyStub_8bd0; stores row 0 at +0, low dwords at +0x10/+0x2C, partial SSE results at +0x14/+0x1C/+0x24, and the full vector at +0x30. The output class is not identified.

Methods: `0x0052087E`

- `this+0x00000000` `__m128 row0` (write, GUESS)
- `this+0x00000010` `float component_0x10` (write, GUESS)
- `this+0x0000002C` `float component_0x2C` (write, GUESS)
- `this+0x00000030` `__m128 row3` (write, GUESS)

### ThreeDNowTransformBuilder

Builds a 4x4 transformation matrix as 8 __m64 slots using 3DNow instructions: identity-like seed constants in slots 0..5, the translation pair (a2, a3) packed at +0x30, and (a4, 1.0f) at +0x38 forming the translation-plus-homogeneous row.

Methods: `0x0052273B`

- `this+0x00000000` `__m64 cell0` (write, DERIVED)
- `this+0x00000008` `__m64 cell1` (write, DERIVED)
- `this+0x00000010` `__m64 cell2` (write, DERIVED)
- `this+0x00000018` `__m64 cell3` (write, DERIVED)
- `this+0x00000020` `__m64 cell4` (write, DERIVED)
- `this+0x00000028` `__m64 cell5` (write, DERIVED)
- `this+0x00000030` `__m64 translation_xy_row` (write, DERIVED)
- `this+0x00000038` `__m64 z_homogeneous_row` (write, DERIVED)

### ConditionalSizedBufferZeroer

Zero-initializes a per-object buffer at this+4 whose element count is 576 by default or 1152 when global dword_8B0108 is clear (4-byte cells); used on MPEG open paths (CMpegBase_Open 0x0052E090, CMpegFilePlayer_Open 0x0052E1D0).

Methods: `0x0052DA10`

- `this+0x00000004` `byte_buffer buffer` (write, GUESS)

### IterateStructArray42Helper

Fixed-count batch walk over a 42-element global array at dword_8B6C28 with a 76-byte stride, invoking a per-element action (0x00556220); the element type and action semantics are outside this packet.

Methods: `0x0053C190`


### UiSceneStateWordNormalizer

Walks a UI element linked list (head at this+0x204, next at node+0x10) and sign-extends each node's state words (count at node+0x118, array at node+0x11C) by replicating the signed upper 16 bits into the low 16 bits. Called by RecursiveTraversal (0x0054BCD0).

Methods: `0x0054BF10`

- `this+0x00000204` `pointer list_head` (read, DERIVED)
- `this+0x00000224` `pointer next_node` (read, GUESS)
- `this+0x0000032C` `int state_count` (read, GUESS)
- `this+0x00000330` `int state_word` (read_write, GUESS)
- `this+0x00000332` `short state_word_high` (read, GUESS)

### FloatStructArray256Initializer

Fixed-count batch initialization of a 256-element array of 104-byte float-bearing structs at unk_8B8F40, invoking a per-element initializer (0x0053B130); element layout is outside this packet.

Methods: `0x0054C270`


### IndexedElementArray

Array container with element count at this+0x120 and base pointer at this+0x124; elements are packed structs of stride 36 whose entry at offset 8 holds a target pointer, and the accessor returns the DWORD at target+4.

Methods: `0x0054E240`

- `this+0x00000120` `int element_count` (read, DERIVED)
- `this+0x00000124` `pointer element_base` (read, DERIVED)

### BinkFrameLookupArray

Frame array with count at this+0xA4 and base at this+0xA8; entries are 148-byte structs whose terminal/sub-index layout drives Bink video-frame selection and an optional decoder reset (0x00551DD0) gated by entry field 36 and global dword_8B6AC4.

Methods: `0x005504D0`

- `this+0x000000A4` `int frame_count` (read, DERIVED)
- `this+0x000000A8` `pointer frame_base` (read, DERIVED)

### ParticleElementArray

Particle element array with count at this[0x2C] and base pointer at this[0x34]; 128-byte elements, per-frame element update through sub_53B330 at entry+16 and a 0x4000 dirty flag on the element base dword. Called per frame by particle collision/spark, wheel-render, trail-emitter and instance-update paths.

Methods: `0x00558CB0`

- `this+0x0000002C` `int element_count` (read, DERIVED)
- `this+0x00000034` `pointer element_base` (read, DERIVED)

### CountedDwordArray

Simple dword array that begins right after a count field: the count at this+0x4 bounds the index and the element at index a2 lives at this + 8 + 4*a2; out-of-range access fails closed with 0.

Methods: `0x0055BFD0`

- `this+0x00000004` `int element_count` (read, DERIVED)

### SlotArrayDelegator

Slot-indexed delegator over an element-pointer array starting at this dword index 2: loads the element for index a2, returns -1 when the slot is null or the delegated call (0x0055BD20) fails, otherwise records the slot index at this[0] and returns the delegated result.

Methods: `0x0055BFF0`

- `this+0x00000000` `int last_slot` (write, GUESS)

### DxVertexBufferVectorStore

Stores and unit-normalizes a 3-component vector at this+0x44/0x48/0x4C, pushes it into a DirectX vertex buffer via DirectXVertexBufferTextureCoordinateSetup (0x005416A0, mode 5) using the handle at this+0x4 and global dword_8B78A0, and flags buffer dirtiness at dword_8B8F28+236.

Methods: `0x0055D460`

- `this+0x00000004` `pointer handle` (read, DERIVED)
- `this+0x00000044` `float vector_x` (read_write, DERIVED)
- `this+0x00000048` `float vector_y` (read_write, DERIVED)
- `this+0x0000004C` `float vector_z` (read_write, DERIVED)

### SceneRelativeDirectionComputer

Scene-node object computing a normalized direction vector: sets dirty flag 0x40000 at this+0x14, walks a context node list rooted at dword_8B8F28, picks a scene position (stored at this+0xE8..0xF0 or via SceneNodePositionGetter 0x0054B950 depending on the node flag at *(this+0x138)+0x3C bit 0x10), and stores a twice-normalized delta direction at this+0x100/0x104/0x108.

Methods: `0x0055D5C0`

- `this+0x00000014` `int dirty_flags` (write, DERIVED)
- `this+0x00000138` `pointer scene_node` (read, DERIVED)
- `*(this+0x138)+0x0000003C` `int node_flags` (read, GUESS)
- `this+0x000000E8` `float stored_pos_x` (read, DERIVED)
- `this+0x000000EC` `float stored_pos_y` (read, DERIVED)
- `this+0x000000F0` `float stored_pos_z` (read, DERIVED)
- `this+0x00000100` `float direction_x` (write, DERIVED)
- `this+0x00000104` `float direction_y` (write, DERIVED)
- `this+0x00000108` `float direction_z` (write, DERIVED)

### IntArrayContainer

Integer-array container with an element-count word at this+0x0 and a backing allocation at this+0x4; construction zeroes the count and allocates 4*a2 bytes for a2 ints.

Methods: `0x00560B60`

- `this+0x00000000` `int element_count` (write, DERIVED)
- `this+0x00000004` `pointer buffer` (write, DERIVED)

### SocketArrayContainer

Array of socket records with count at this+0x6C and base pointer at this+0x8; entries are 28 bytes (7 dwords) with the socket handle/ID at entry+0. Creation (0x562D20) calls socket(2, 2, 17) per entry and zeroes entry+4/+8; search (0x563230) scans entries by their first-dword ID. Both are exercised on NetworkConnection paths.

Methods: `0x00562D20`, `0x00563230`

- `this+0x0000006C` `int socket_count` (read_write, DERIVED)
- `this+0x00000008` `pointer socket_base` (read, DERIVED)

### ArrayDescriptorFactory

Allocates a five-dword descriptor plus a backing array of a2 element slots, each filled with a distinct heap object built by Malloc0x18ByteStructWithInnerBuffer(a6): descriptor holds {element_array, count, factory_param, caller_value_a, caller_value_b}. Shared allocation contract for three caller paths.

Methods: `0x005646D0`

- `this+0x00000000` `pointer buffer` (write, GUESS)
- `this+0x00000004` `int count` (write, GUESS)
- `this+0x00000008` `int factory_param` (write, GUESS)
- `this+0x0000000C` `int caller_value_a` (write, GUESS)
- `this+0x00000010` `int caller_value_b` (write, GUESS)

### NetworkRecordArray

Packed record array over network connections: count at offset 0, per-record byte stride at offset 8, element base at offset 14 (20). LinearInterpolation (0x5648B0) resolves element addresses as base + index * stride, and removal (0x564990) shifts the tail down over the removed slot via sub_58B130 and decrements the count. Caller NetworkConnection (0x00563260) is the primary consumer.

Methods: `0x005648B0`, `0x00564990`

- `this+0x00000000` `int record_count` (read, DERIVED)
- `this+0x00000008` `int record_stride` (read, GUESS)
- `this+0x00000014` `pointer element_base` (read, GUESS)

## Compatibility contracts

- **ParticleAxisStridedArrayContract** — The particle orientation updater (0x004CC840) walks a strided array of 10-float entries between unk_8AC840 and the end marker flt_8ACAC0; each entry receives a direction vector and a cross-product axis normalized to length this[4] * 0.5. A replacement must preserve the 10-float stride, the -0.03125 X/Z scaling of the source direction, and the this+0x10 half-length field.
- **VectorFieldChannelPresenceContract** — The vector-field presence helper (0x004CE8F0) returns TRUE iff any of the three float channels at offsets 0x00, 0x14, 0x28 is non-zero; a replacement must preserve the three dword float offsets and the logical OR of the three non-zero tests.
- **DualArrayTeardownContract** — The dual-array destructor (0x004DED20) zeroes head fields 0x4/0x8, tears down the 12-byte-element array at 0xC (per-element 0x4DD4C0) and the 24-byte-element array at 0x14 (per-element 0x4DD4D0), frees both allocations at their count-header bases through 0x587BCF, and zeroes the pointer/companion pairs 0xC/0x10 and 0x14/0x18. The count-header (block-4) convention must be preserved.
- **SortedLRUArrayContract** — The sorted LRU array holds count at this+0x18, a maximum of 20 entries of 36 bytes starting at this+0x20, ordered by the float key at entry[1]. Duplicate entries are rejected with a -1 report through sub_4DF110; full arrays evict a minimum-score candidate (scored against flt_59E670/flt_5AD140) by left shift. A replacement must preserve the entry stride, key slot, duplicate rejection and the 0x18 count field.
- **VehicleRespawnStateEntryLayoutContract** — Vehicle respawn state keeps entry count at this+0xBA8 and 748-byte-stride entries starting at this+747 floats; reset (0x004E3890) calls sub_4DF110(entry, 0.0, -1) per entry and clears the entry sixth float at this+0xBC4. A replacement must keep the count field, the 748-byte stride and the reset call shape.
- **BinkFrameLookupContract** — The frame lookup (0x005504D0) uses count at this+0xA4 and base at this+0xA8 with 148-byte entries: entry field 18 <= 1 marks a terminal frame, entry field 35 holds the frame pointer, field 36 gates the Bink decoder reset (0x00551DD0 with arguments (0, 0, 32) and a 0x400 bit clear) together with global dword_8B6AC4, and non-terminal sub-indexing scales the entry-field-19 list value by 96. a2 == -1 selects the base frame pointer.
- **ParticleElementArrayContract** — The particle element array (0x00558CB0) keeps count at this[0x2C] and base at this[0x34] with 128-byte elements; the per-frame update calls sub_53B330 at element base + 16 and sets flag 0x4000 on the element base dword. A replacement must preserve the stride, the two header offsets and the 0x4000 flag semantics.
- **SocketArrayLayoutContract** — The socket array (0x00562D20, 0x00563230) keeps count at this+0x6C and base at this+0x8 with 28-byte entries whose first dword is the socket handle/ID; creation calls socket(2, 2, 17), zeroes entry+4/+8, and truncates the count on partial failure; search returns the index of the matching first dword or -1. Caller NetworkConnection depends on this layout.
- **SceneNodeDirectionVectorContract** — SceneRelativeDirectionVectorCompute (0x0055D5C0) sets dirty flag 0x40000 at this+0x14, obtains a scene position from this+0xE8..0xF0 or via SceneNodePositionGetter (0x0054B950), and stores a twice-normalized delta direction at this+0x100/0x104/0x108. A replacement must preserve the three direction float offsets and the 0x40000 dirty flag.
- **DirectXVectorStoreContract** — NormalizeAndStoreVectorWithDXUpdate (0x0055D460) writes a unit-normalized 3-float vector at this+0x44/0x48/0x4C, pushes it through DirectXVertexBufferTextureCoordinateSetup (0x005416A0, mode 5) using the handle at this+0x4 and global dword_8B78A0, and ORs dirty bit 0x800 into dword_8B8F28+236. A replacement must preserve the vector offsets, mode 5, and the 0x800 dirty bit.
- **RecordArrayAddressingContract** — Network record array addressing: element index a2 resolves as base(offset 20) + a2 * stride(offset 8) through LinearInterpolation (0x5648B0); removal (0x564990) shifts the tail down by stride * (count - index - 1) bytes and decrements count at offset 0. A replacement must preserve the base/stride/count offsets and the address formula.

## Unresolved

- Ownership is UNKNOWN for nearly every function in the packet; the class groupings are DERIVED/GUESS proposals, not confirmed identities, and no RTTI or vtable evidence appears in the packet.
- The object behind VirtualDispatchHelper(&dword_5EA510) and the meaning of its +36 field are unknown (0x004CC840).
- The 10-float entry layout of the particle axis array (unk_8AC840) and the meaning of each axis row are inferred from the arithmetic only; flt_8ACAC0 as an array terminator is DERIVED.
- Globals flt_59E450, flt_59ED18 and dword_5ACEAC are flagged by packet facts for 0x004CC840 but are not consumed by its visible raw source.
- The three-channel struct tested by 0x004CE8F0 (velocity/magnitude semantics) is inference; the raw source only grounds three non-zero float tests on an unnamed struct, and flt_59E440's role as a zero threshold is not evidenced in the raw source.
- The exact destructor contract of ShortComputation_d4d0 / sub_4DD4C0 and what classes they destroy are not documented; the relation between the single resource pointer (0x8) and the array (0x10) in 0x004DD470 is not established.
- The owner class of 0x004DED20 is unidentified; companion fields 0x10/0x18 are zeroed but never read, head fields 0x4/0x8 are never read or written elsewhere in the function, and the block-4 count-header convention is inferred.
- The eviction cost model of SortedLRUArray (which combination of state flag and score yields eviction) and the role of flt_59E670/flt_5AD140 are inferred; sub_4DF110 reporting semantics are inferred from two call sites; the meaning of the this+0x1C slot is undetermined.
- The ArrayEntryCleanup 74-dword entry stride and the 81/98-dword sub-block offsets are grounded only in raw addressing; FlagFieldBitManipulation(1, 1, 0, 0) constants and the *v3 nonzero branch meaning (initialized vs error) are unknown.
- sub_4DF110 is named 'ContactConstraintSolverUpdate' by existing analysis in the StateArrayReset path; that name is unverified, and the 187-float stride / this+747-float base are derived addressing.
- Vector3 helpers take three separate float pointers; the containing object identity of a1/a2/a3 is unconfirmed, and the structural-twin cluster addresses are outside the packet.
- Row-major layout of the 3x3 matrix in 0x004ED7B0 is inferred; whether it is an orientation-only rotation or an upper-left sub-block of a 4x4 transform depends on the callers.
- The 0045eb00 cluster name (Vector3ScalarMultiply) for 0x004EFEE0 is not confirmed by this packet; a2 is read at the same offsets as a1 but is not separately listed as field evidence.
- SSEVectorMatrixInit passes four arguments read from an uninitialized-looking stack window to EmptyStub_8bd0; stores at +0x14/+0x1C/+0x24 have no packet field refs, parameter a2 is unused, and the 52-byte output class is unproven.
- ThreeDNowMatrixConstructor: the association of each SIMD constant global (qword_5AF9C0/qword_5AF9C8) to specific literals is not evidenced (constants are inlined), and the float meaning of a2/a3/a4 (translation vs orientation) is inferred from the homogeneous row layout.
- The semantic of dword_8B0108 (576 vs 1152 element selection) and the element type of the cleared this+4 buffer in 0x0052DA10 are unidentified.
- sub_556220's semantics and the 76-byte element type of the 42-element array at dword_8B6C28 are not evidenced; the array is read-only from this function's perspective.
- In 0x0054BF10 the a2 argument is unused; the raw source shows the inner loop does not advance v3 between iterations (same state word rewritten), which is either a decompiler artifact or genuine behavior; the node layout is expressed this-relative without an established this/node relationship.
- F_10FloatStructInitializer (0x0053B130) semantics and the 104-byte element type of the unk_8B8F40 array are not evidenced.
- In 0x0054E240 the target pointer loaded from the element entry and the value at target+4 have no named meaning; the 36-byte element struct layout is unknown.
- In 0x005504D0 the frame entry fields (18/19/20/35/36 of the 148-byte entry) are not in the packet field list; the constants 32 (decoder argument) and 96 (sub-index scale) and the 0x400 bit are unexplained.
- In 0x00558CB0 the roles of forwarded arguments a3/a4/a5 and the meaning of flag bit 0x4000 are unknown; the writers of element_count (0x2C) and array base (0x34) are elsewhere.
- The dword element semantics of 0x0055BFD0 are unknown; whether callers 0x004F9160 and 0x0055F0D0 share the object layout is not established.
- The semantics of sub_55BD20 and the type of the slot array starting at this dword index 2 in 0x0055BFF0 are unidentified; the relation between slot index a2 and forwarded args a3..a7 is unknown.
- Globals dbl_59E430 and flt_59E43C are flagged by packet facts for 0x0055D460 but appear nowhere in its raw source; the meaning of mode 5 and the 0x800 dirty flag at dword_8B8F28+236 is not documented.
- In 0x0055D5C0 caller argument a3 is unused; the exact zero-threshold role of flt_59E43C/flt_59E440/flt_59E670 is inferred from the constant pool, and the semantic identity of the node-list walk rooted at dword_8B8F28 depends on context.
- In 0x00560B60 whether a2 is a fixed capacity or an initial count is not observable, and no deallocation or resize path is visible.
- The socket-array buffer allocation site and the meaning of entry+4/entry+8 of each 28-byte entry are not evidenced; the constants 2/2/17 as AF_INET/SOCK_DGRAM/IPPROTO_UDP are a Winsock interpretation of raw-source literals.
- ArrayOfStructStrideSearchByID and SocketArrayCreate share offsets 0x8 and 0x6C and both appear on NetworkConnection paths, but common ownership is a GUESS, not proven (equal offsets on different this bases are not identity).
- The a4 and a5 descriptor fields of 0x005646D0 depend on each caller's use; the owning allocator subsystem is not established by this packet.
- LinearInterpolation offsets +8 and +20 have no named field evidence, and the meaning of the interpolation factor a2 (time fraction, weighting, arbitrary scale) is not established.
- In 0x00564990 v4 is uninitialized in the decompiled listing and is interpreted as the ecx this pointer equal to a1 (a DERIVED assumption); sub_58B130 is presumed to be a byte block copy/move and a1[2] is assumed to be the per-record stride.
- The semantic meaning of the dword flag at this+24 in TypedLRUArrayInsert and the exact array element layout consumed by SortedArrayInsertWithLRUEviction are not established by the packet alone.
