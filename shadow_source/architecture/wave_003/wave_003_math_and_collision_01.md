# MathAndCollision

Scope: `math_and_collision`  
Trust: `DERIVED`

DERIVED proposal for the math_and_collision scope. The subsystem spans three loose groups evidenced only by the validated IR: (1) scene-graph geometry math - GlobalVectorOffsetUpdate shifts every scene-graph child's packed vertex array by a global offset vector and recomputes bounds; ComputeOBBAndBoundingSphere derives an OBB plus bounding sphere from mesh vertex covariance via QR decomposition; RaySphereIntersectionTest performs a pick-style ray/sphere test through an indirect D3D transform. (2) Collision data pipeline - LoadCollisionSceneData reads a collision scene file into a 92-byte-per-object buffer and a 16-byte-per-node array, counts/linearizes a BVH tree, and links contact pairs; BVHTreeNodeArrayInit resets node-array state; CollisionBroadcastLoop pushes per-entry collision events to the network; DispatchMessageToCollisionOrEventList classifies a command word and either runs a direct FloatComputation or queues a 432-byte payload into one of two doubly-linked lists. (3) Array/object lifecycle utilities with unknown owners - array destructors, zero-inits, searches, and resets. Only two owners are DERIVED (CollisionSceneDataLoader, SoundSourceArray); the rest are UnknownObject and their concrete class identity is deliberately left unresolved rather than guessed. All fields, callees, and globals are reported verbatim from the packet; none are invented.

## Function roles

- `0x0040E1F0` **UnknownObject** — Offsets every scene-graph child's packed vertex array by a 3-component offset vector (fields +0/+4/+8) and recomputes each child's bounding box; returns the last processed child index.
- `0x0040E770` **UnknownObject** — Per-frame scene/camera tick: toggles scene-node visibility, mixes audio physics for mode selector values 0-2, computes a dual-matrix transform into six locals, then dispatches on the mode selector (0-5) writing argument a2 into the scene child at +208 and invoking the child's virtual method; writes the six matrix components into child matrix storage and runs cleanup.
- `0x0041EF00` **UnknownObject** — Backward scan of a caller-owned dword window (starting at dword index v3+54) looking for the sentinel value 10, with the scan bound v3 read from a standings node reached via a global; returns 1 on match, else 0.
- `0x00421470` **UnknownObject** — Initializes the global season-directory path/flag array at 0x005EC3D0 with alternating 0/-1 dword pairs and registers it as directory paths via ConfigDirectoryPathRegistration; returns the array pointer.
- `0x0044BC50` **CollisionSceneDataLoader** — Loads collision geometry for a track scene file: verifies the file, reads version/header values via the conditional-dispatch parser, allocates a 92-byte-per-object buffer (this+0) and a 16-byte-per-node array (this+4), counts and linearizes the BVH/dynamics tree, links contact pairs, frees temporaries, and performs conditional file-handle/field cleanup.
- `0x0044F0A0` **UnknownObject** — Zero-initializes BVH tree node array state: node-count field at +0xC84, 256 dword entries at +0x87C plus a parallel byte array, and a 48-byte block at this+802.
- `0x004526C0` **UnknownObject** — Destroys an array of 10 vtable-backed objects: zeroes the count field at +0x414, then for each non-null slot in the +0x64 array invokes vtable slot +44 then vtable slot +8, and clears the slot to null; returns the last vtable slot +8 result.
- `0x0045C780` **UnknownObject** — Bounded byte-table accessor returning this[a2 + 852] when a2 is below 0x68, otherwise 0; used for per-index terrain surface sampling.
- `0x0045C850` **UnknownObject** — Resets one indexed element of a per-element array held in this: zeroes two dwords, two bytes, a 32-byte block and a 16-bit element, and stores a float sentinel (-1082130432) into one element; returns 0.
- `0x004613E0` **UnknownObject** — Broadcasts each collision entry's event over the network, skipping entries whose FlagBitTest(2) is non-zero; iteration count from +0x3E14, entry array base at +0x3C74; returns the count.
- `0x00465300` **UnknownObject** — Routes an input command word: collision-class commands ((word>>29)==1 with subtype 0 or 7) go to a direct FloatComputation when the low byte is below 0x68; all other commands allocate a 432-byte queued payload filled from the command and appended as a 12-byte node to one of two doubly-linked lists anchored at obj+0x6C or obj+0x7C.
- `0x0049B0A0` **UnknownObject** — Initializes four UI button widgets (vehicle display, network problem, next track, next session) from a season-directory resource container into the dword_7CE23C slot array, cleaning up a widget and clearing its slot when bitmap/surface creation fails.
- `0x004A3440` **UnknownObject** — Per-frame pit-crew array processor gated by the pending-flag bit 0 at this+0: iterates the 120-byte-stride array at this+0x10 setting bit 12 on each live entry, conditionally updates widget visibility when the detail-level global is >= 2 and this+0x14 is non-zero, then clears flag bits 0-1.
- `0x004A40F0` **UnknownObject** — Zero-initializes a full struct: memsets the first 0x1A0 bytes and writes DWORD 0 at the trailing field +0x1A0; returns 0. Called on game restart.
- `0x004CF010` **UnknownObject** — Searches a 0x6C-byte-stride element array (count at +0x10, base at +0x14) for an element whose second dword matches a2, calls the cleanup helper on the matched element and returns its result; returns the count when exhausted without a match.
- `0x004D0080` **SoundSourceArray** — Destructor for an array of 3D sound source objects: when the array pointer (this+4) and global dword_8AFE88 are both non-null, destroys each non-null 132-byte-stride entry via the 3D sound source destructor, runs a backwards internal-cleanup pass, frees the allocation block, and zeroes pointer and count fields.
- `0x004D1030` **UnknownObject** — Runs two parallel per-vehicle passes: over the AI/path data array (base 0x005F0F80, 4656-dword stride) computes a DistanceComparison into a results buffer and resets two sentinel dwords to -1; over the main vehicle array (base 0x005EC6D8, 18624-byte stride) runs RenderCallWithGuard and conditional AIVehiclePathPositionTracking; then delegates to a post-loop step.
- `0x004D7050` **UnknownObject** — Tears down a two-block dynamic array structure: clears counters at +0x8/+0x10, frees 24-byte entries of block 1 (+0xC, sub-pointers freed) and 680-byte entries of block 2 (+0x14, field groups passed to ShortComputation_4370), frees both block headers, zeroes the block pointers, and sets the +0x20 sentinel to -1.
- `0x004DC960` **UnknownObject** — Ray-sphere intersection test: retrieves a 3D vector from this+0/+4/+8, rejects when squared distance to point a2 exceeds radius squared, runs an indirect D3D-device-wrapper depth check, and on success writes distance to a4 and clamped position/delta to a3, returning 1.
- `0x00546370` **UnknownObject** — Cleans up an array block at +0xA8: for each of the +0xA4 elements frees element+76 and, when element+144 is non-null, runs EmptyStub_7470 then frees it; then frees the whole block including its count-header prefix and nulls +0xA8.
- `0x00549470` **BoundingVolumeGeometry** — Computes OBB and bounding sphere for a scene-graph mesh: pass 1 accumulates covariance over the mesh-entry linked list and factors it with QRDecomposition for orientation axes; pass 2 tracks per-axis extrema and writes 8 corners plus the center; pass 3 measures the bounding-sphere radius; a final loop builds 6 OBB face planes at +0x8C.
- `0x00550870` **UnknownObject** — Constructor/initializer: calls the shared zero-init helper, zeroes leading dwords and byte +0x1C, sets +0x4 to 1065353216 (1.0f) as a unit-vector component, zeroes trailing +0x2C/+0x30, and returns this.

## Proposed classes

### CollisionSceneDataLoader

Loads track collision geometry from a scene file into two buffers - a 92-byte-per-object collision object buffer at +0x0 and a 16-byte-per-node collision node array at +0x4 - reading the file through the conditional-dispatch parser and linking contact pairs.

Methods: `0x0044BC50`

- `this+0x00000000` `CollisionObject* collisionObjectBuffer` (write, DERIVED)
- `this+0x00000004` `void* collisionNodeArray` (write, DERIVED)

### SoundSourceArray

Owns an array of 3D sound source objects (132-byte stride, count field at +0x0, array pointer at +0x4) and destroys them in two teardown passes, frees the allocation block, and resets both fields.

Methods: `0x004D0080`

- `this+0x00000000` `int count` (read_write, DERIVED)
- `this+0x00000004` `SoundSource3D** arrayPtr` (read_write, DERIVED)

### BoundingVolumeGeometry

Computed bounding volume for a scene-graph mesh: bounding-sphere radius at +0x18, 8 OBB corners at +0x1C..+0x70, center at +0x7C..+0x84, and 6 OBB face planes at +0x8C; mesh node pointer at +0xEC. Produced by ComputeOBBAndBoundingSphere.

Methods: `0x00549470`

- `this+0x00000018` `float boundingSphereRadius` (write, DERIVED)
- `this+0x0000007C` `float centerX` (write, DERIVED)
- `this+0x00000080` `float centerY` (write, DERIVED)
- `this+0x00000084` `float centerZ` (write, DERIVED)
- `this+0x0000008C` `Plane[6] obbFacePlanes` (write, DERIVED)
- `this+0x00000090` `Plane obbFacePlanesNext` (write, DERIVED)
- `this+0x000000EC` `void* meshNodePtr` (read, DERIVED)

### SceneGraphMeshNode

Scene-graph node walked by the OBB computation: sibling chain next-pointer at +0x4C, transform-flag word at +0x3C, and mesh-entry linked-list head at +0x204. Class identity is GUESS; each field is evidenced by the walk.

Methods: 

- `*(this+0xEC)+0x0000003C` `uint32 transformFlags` (read, DERIVED)
- `*(this+0xEC)+0x0000004C` `SceneGraphMeshNode* nextSibling` (read, DERIVED)
- `*(this+0xEC)+0x00000204` `MeshEntry* meshEntryHead` (read, DERIVED)

### MeshEntry

Linked-list mesh entry holding vertex sub-buffers: list linkage at +0x10, sub-buffer count at +0x118, sub-buffer array at +0x11C, vertex count at +0x128 and vertex base at +0x12C per sub-buffer. Class identity is GUESS; each field is evidenced by the OBB geometry walk.

Methods: 

- `*(*(this+0xEC)+0x204)+0x00000010` `MeshEntry* nextEntry` (read, DERIVED)
- `*(*(this+0xEC)+0x204)+0x00000020` `unknown unresolvedField` (read, GUESS)
- `*(*(this+0xEC)+0x204)+0x00000118` `int subBufferCount` (read, DERIVED)
- `*(*(this+0xEC)+0x204)+0x0000011C` `void* subBufferArray` (read, DERIVED)
- `*(*(this+0xEC)+0x204)+0x00000128` `int vertexCount` (read, DERIVED)
- `*(*(this+0xEC)+0x204)+0x0000012C` `float* vertexBase` (read, DERIVED)

### EventCommandQueue

Container holding two doubly-linked command/event lists anchored at obj+0x6C (list 0 head/tail/count) and obj+0x7C (list 1), appended to by DispatchMessageToCollisionOrEventList on the queued command path. Struct identity is GUESS; the anchor fields are evidenced.

Methods: 

- `obj+0x0000006C` `void* list0Head` (write, DERIVED)
- `obj+0x00000070` `void* list0TailNext` (write, DERIVED)
- `obj+0x00000074` `void* list0Tail` (write, DERIVED)
- `obj+0x00000078` `int list0Count` (write, DERIVED)
- `obj+0x0000007C` `void* list1Head` (write, DERIVED)
- `obj+0x00000080` `void* list1TailNext` (write, DERIVED)
- `obj+0x00000084` `void* list1Tail` (write, DERIVED)
- `obj+0x00000088` `int list1Count` (write, DERIVED)

## Compatibility contracts

- **CollisionSceneFileLayout** — A replacement collision loader must preserve the scene-file read shape: a 46-byte version/header string, four 8-byte header values, a 4-byte object count, a 4-byte node count and a 4-byte dynamics/BVH node count, read through the conditional-dispatch parser (0x00566BD0) with the version constant at 0x005C445C.
- **CollisionNodeBufferLayout** — Collision loader output layout: a 92-byte-per-object collision object buffer stored at this+0 and a collision node array with a 4-byte count header and 16 bytes per node stored at this+4; per-object node initialization runs through 0x0044A430.
- **SceneGraphGeometryVertexLayout** — Scene-graph child geometry: packed vertices are 3-component records at +0/+4/+8, shifted by subtracting a global offset vector; after the shift the child flag word at +20 is cleared with mask 0xFEFFFFDF and the bounding box is recomputed.
- **BoundingVolumeOutputLayout** — Bounding-volume output layout produced by the OBB computation: bounding-sphere radius at +0x18, 8 OBB corners in +0x1C..+0x70, center at +0x7C..+0x84, and 6 OBB face planes beginning at +0x8C; mesh entries are 48-byte-stride vertices reached via node+0x204 list heads.
- **CollisionCommandClassification** — Input command dispatch must preserve the classification: commands with ((word >> 29) == 1) and subtype ((word >> 18) & 0x3F) equal to 0 or 7 go to the direct FloatComputation path when the low byte is below 0x68; all others are queued as a 432-byte payload in a 12-byte node appended to one of two doubly-linked lists anchored at obj+0x6C (flags with 0x8000000 set or tag != 0x20000000) or obj+0x7C.
- **SoundSourceArrayLayout** — 3D sound source array contract: count at this+0, array pointer at this+4, 132-byte entry stride, element-count header at array_ptr-4; each live entry is destroyed via 0x00545150 and the block freed via 0x00587BCF.

## Unresolved

- The concrete owning classes of the majority of functions (scene-graph geometry, collision network broadcast, command dispatch, terrain accessor, widget init, and the array-lifecycle utilities) are unknown; owners were left as UnknownObject rather than guessed.
- The two bits cleared by the 0xFEFFFFDF mask on the scene-child flag word at +20 in GlobalVectorOffsetUpdate are not interpreted (likely dirty/validity flags of the vertex data).
- The role of the unused first argument a1 of GlobalVectorOffsetUpdate (possibly a vestigial this/context pointer) is unknown.
- sub_54D080's argument-0 behavior, and the semantics of sub_40ED10 / sub_4BE010 in UpdateSceneVisibilityAndChildMatrix, are not documented by the packet.
- Global dword_8AB710 is read in UpdateSceneVisibilityAndChildMatrix but its feed point is not evidenced; its role is unknown.
- The write of a2 into child+208 in UpdateSceneVisibilityAndChildMatrix has no field evidence; the packet fields this+0x24/0x28/0x2C are recorded on the `this` base while the writes land on the child object, and the two bases may alias without proof.
- The relationship between the mode selector (0-5) and concrete camera/view modes is not established.
- In ArrayContainsValue10 the meaning of the literal 10 (sentinel/flag value), the owning class, and why the window starts at dword index v3+54 are not established.
- In InitSeasonParentPathArray the callee 0x00587B3E is listed in facts but not invoked, global 0x00421490 is the return address rather than a data global, and the exact element semantics of the alternating 0/-1 path/flag array are not stated.
- LoadCollisionSceneData dispatches on this byte offsets 8, 16, 24 and 32 with no packet field evidence; the roles of sub_566940's constant arguments, the 16-byte-per-object temporary v28, the v25 flag, and the float reinterpretation of the contact-pair-list pointer are unverified.
- The meaning of flag bit 2 in CollisionBroadcastLoop and the unused secondary pointer (this+229 stepped by 35 dwords) are unknown.
- In DispatchMessageToCollisionOrEventList the two linked lists are appended to but never consumed in scope; the semantic distinction between list 0 and list 1 is not established.
- Globals dword_8AFE64, dword_8AFE88 and flt_59E440 have roles not established by this packet (dword_8AFE88 gates the sound-source destructor; flt_59E440 may be a threshold used through an inlined path).
- The object at global dword_8B8F24 and the exact matrix semantics of its vtable-slot-4 indirect D3D transform calls are not established.
- In ComputeOBBAndBoundingSphere the mesh-entry field at +0x20 and the dereference at *(*(this+0xEC)+0x4C)+0x4C are listed by the deterministic extractor but have no matching direct read in the raw source.
- The +0x18 field of ArraySearchByIDWithCleanup is read-only per static facts but not referenced by the raw source; sub_4CB5E0's matched-element behavior is not visible.
- The block-header count-at-block-4 layout in ArrayBlockCleanup and ArrayCleanupWithDualFree, and the role of ShortComputation_4370 / EmptyStub_7470 during teardown, are inferred from raw arithmetic, not independently evidenced.
- In soundSourceArrayDestructor the 132-byte per-entry layout and the element-count header at array-4 are only described by the raw stride.
- In LoopOverTwoParallelArrays the byte buffers v8/v7 stack layout and the meaning of the DistanceComparison return and the two reset sentinels are only inferred from the guard pattern.
- In StructZeroInitWithUnitVector the field roles (why +0x4 receives 1.0f while all other listed fields are zeroed) and the byte-width write at +0x1C depend on the unknown owning-object layout.
- PerElementArrayReset's memset has no callee evidence reference; the per-element array layout, element count and owning class are unknown.
- In ReadTerrainArrayByte the meaning of the 852-byte base offset and the 0x68 element count, and whether the byte is roughness/height/other, are unproven.
