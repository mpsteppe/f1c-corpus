# RuntimeObjectCore

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

27 functions in the generic_runtime_objects scope. The strongest common-ownership signals form six DERIVED container/object classes: (1) SceneMeshContainer, four functions sharing the flags word at +0x14, sphere radius +0x18, AABB corner block +0x1C..+0x78, optional center +0xDC..+0xE4 and the mesh/triangle entry lists at +0x118/+0x11C and +0x120/+0x124; (2) StringListNodeContainer, two functions sharing list head this+0x28 and node next link +0x5C; (3) SoundBufferListContainer, two functions sharing head this+0x2C and node next link +0x14; (4) AudioNodeListContainer, two functions sharing head this+0x170 and node next link +0x18; (5) SceneTreeNode, two functions sharing child pointers this+0x44/+0x4C; (6) StateFlagObject, three functions sharing the flags dword this+0x3C (with two value slots +0x234/+0x238). Four GUESS single-method classes capture DoublyLinkedList (0x0054BAA0), ByteBufferList (0x00549250), NodeListContainer (0x0054ABE0) and MultiListContainer (0x00548EB0). Eight functions (0x00547100, 0x00547280, 0x00547400, 0x00548850, 0x0054A200, 0x0054B3F0, 0x0054F5C0, 0x0054FB70) operate on objects whose owner is unknown and whose field layouts share nothing with the grouped classes; they are left with owner UnknownObject and their fields documented only in function_roles. All owners are UNKNOWN in the packet; every class grouping is a DERIVED or GUESS proposal, never a confirmed fact.

## Function roles

- `0x00547100` **UnknownObject** — Conditional configuration setter: gates SimpleSetter_fc40(0x80000000) and FieldSetter_fca0(4) on a2 < this+0xA4 < 8; returns 0 on every path.
- `0x00547280` **UnknownObject** — Key-value field setter: key 0x1000 writes a2 to this+0x8C, key 0x2000 writes a2 to this+0x90; returns a2 on a key match else the original a3.
- `0x00547400` **UnknownObject** — Guarded post-init status wrapper: when a1 is non-null call sub_548620(a1) and return -1 on a non-zero callee result, otherwise return 0 (including the a1==null short-circuit).
- `0x00547860` **StringListNodeContainer** — Append a node to the list rooted at this+0x28: walk next links at node+0x5C to the tail (or install the new head on an empty list), initialize node prev(+0x58)/next(+0x5C), increment node count this+0xC; return the previous tail.
- `0x00547920` **StringListNodeContainer** — Search the string list rooted at this+0x28 for key a2: normalize the key via sub_589901 plus StringDotFinder when it carries a dot; walk next links at node+0x5C; compare single string at node+0x4 or iterate 96-byte sub-entries; return the matching node or 0.
- `0x00548850` **UnknownObject** — Indexed list lookup: return 0 when a2 >= element count this+0x10; walk the chain from head this+0x24 through next links at node+0xC0, counting from 0; return the node at index a2 or 0.
- `0x005489A0` **SoundBufferListContainer** — Allocate a 24-byte node via OperatorNewNhMallocWrapper, initialize it as a sound-buffer node via SoundBufferAllocator(node, 1024, a2), append to the list rooted at this+0x2C by walking next links at node+0x14; set the back slot at node+0x10; return the new node or 0 on allocation failure.
- `0x00548A00` **SoundBufferListContainer** — Search the list rooted at this+0x2C for the first node whose float field at node+0x8 equals a2, following next links at node+0x14; return the matching node or 0.
- `0x00548D40` **AudioNodeListContainer** — Lazy-allocating list append: if head this+0x170 is null allocate and install the head; otherwise walk next links at node+0x18 to the tail; allocate a 28-byte node via OperatorNewNhMallocWrapper, initialize it via ArithmeticComparison_8aa0, populate it via sub_548AD0(v6,a2,a3); return -1 on a non-zero populate result, else increment count this+0x16C and return 0.
- `0x00548DD0` **AudioNodeListContainer** — Iterate the list rooted at this+0x170, following next links at node+0x18, calling SceneRenderTransform(node, this, 0) on each node; return the last callee result.
- `0x00548EB0` **MultiListContainer** — Free five linked-list roots: lists at this+0xE8/+0xF0/+0xF8/+0xFC are traversed through next links at node+0x14 (the second at +0xF0 through node+0x34) and each node released via EmptyStub_0170 then FreeWrapper_7bcf; the list at this+0xEC is traversed through next links at node+0x4C and released via sub_549110; each root is zeroed after draining.
- `0x00549250` **ByteBufferList** — Insert a byte-buffer node into a doubly-linked list: select the head from *(*this + 0x128) or *a2 depending on bit 4 of a2's first byte; when the list is initialized (this+0xF4 non-null) walk next links at node+0x6C to the tail and append, otherwise install the head at this+0xF4; initialize node prev(+0x68)/next(+0x6C); return the head node.
- `0x0054A200` **UnknownObject** — Set or clear caller-supplied bits in the process-global flags word dword_8B8E34 (OR when a2 non-zero, AND-Not when a2 zero); return the resulting combined value.
- `0x0054ABE0` **NodeListContainer** — Append node a2 to the list rooted at this+0x204: walk next links at node+0x10 to the tail and link (or install a2 as the head on an empty list), set prev at a2+0x140 and clear next at a2+0x10; return the old head or the new node.
- `0x0054B3F0` **UnknownObject** — Offset-and-dispatch helper: add a2/a3/a4 onto the floats at this+0x20/+0x24/+0x28 and forward the sums to ThreeFieldSetterWithSubCall(this, v4, v5, v6).
- `0x0054BAA0` **DoublyLinkedList** — Doubly-linked-list node transplant: unlink node a2 via prev(+0x48)/next(+0x4C), advance the owning head this+0x44 past a2, append a2 to the global list rooted at dword_8B8F28+264, and when a2 carries a sublist (a2+0x230) reinsert it via DoublyLinkedNodeRemovalGlobalListReInsert; clear the container link a2+0x40.
- `0x0054BC60` **SceneTreeNode** — Depth-first search of the subtrees at this+0x44 then this+0x4C for a node whose base string equals a2 via strcmp; store the matching node into the found-flag pointer *a3 and short-circuit once found.
- `0x0054BCD0` **SceneTreeNode** — Recursive scene-graph traversal: recurse into the subtree at this+0x44, then the subtree at this+0x4C, then terminal dispatch - StateArrayWordSignExtension(a4) when a4 is non-null, else UIElementBitfieldStateSetter(a2, a3, 0).
- `0x0054C0B0` **StateFlagObject** — Conditional getter of two single-bit flags from the complement of the flags dword at this+0x3C: bit 1 into *a2 and bit 2 into *a3 (both null-safe); always return a3.
- `0x0054C150` **StateFlagObject** — Flag-gated field reader: in 0x800 mode (BYTE1(a3)&8 set and flags word this+0x3C bit 0x800 set) write this+0x234 into *a2; in 0x1000 mode (BYTE1(a3)&0x10 and flags word high-byte bit) write this+0x238 into *a2; otherwise return a3 unchanged.
- `0x0054C1A0` **StateFlagObject** — Set flag bits 1 and 2 (mask 6) in the state flags dword at this+0x3C by OR-accumulation; void with no guards or callees.
- `0x0054D080` **SceneMeshContainer** — Per-triangle bounds computation for a mesh: compute triangle centroid, bounding sphere radius (sqrt of max squared centroid-to-vertex distance), and a dominant normal axis code (0-5); select 64/48-byte vertex stride by the 0x800000 flag bit; write centroid to triangle entry +16/+20/+24, radius to +28, axis code to +6; return the triangle count.
- `0x0054D520` **SceneMeshContainer** — Compute the 3D axis-aligned bounding box from vertex buffers: scan the entry list at *(this+0x11C) (count this+0x118), select 12/16-byte vertex stride by the 0x800000 flag bit, write 24 box corners at this+0x1C..0x78, set/clear the has-3D-extents bit 0x10 of the flags word this+0x14, optionally write the center this+0xDC/+0xE0/+0xE4, store the bounding sphere radius at this+0x18; return the flags word.
- `0x0054E080` **SceneMeshContainer** — Flag propagation loop: call ValueGetter(dword_8B8F28) at entry, then iterate the triangle element array at this+0x124 (count this+0x120, 36-byte stride), dereference element+8 then +4 to reach an object whose flags word at +0x9C has bit 0x2 set, and OR bit 0x1 into that word; return the element count.
- `0x0054E270` **SceneMeshContainer** — Compute an oriented bounding box and bounding sphere from mesh vertex data: accumulate per-vertex statistics over the meshes at *(this+0x11C), run QRDecomposition for the OBB eigenvector axes, build a 4x4 D3D transform matrix, transform vertices through the device wrapper dword_8B8F24 (vtable slot +4), find the max squared distance from the center this+0xDC/+0xE0/+0xE4, and store its square root at this+0x18; return the mesh count.
- `0x0054F5C0` **UnknownObject** — Per-entity scene batch render/collision check: skip when entity flags (a2+60) have bit 1 set; return 1 when the global counter dword_8C5F40 reaches the threshold at *(this+0x1E0)+4; optionally prepare the render batch via sub_54B570(a2,0,*(a2+516)); test node visibility bit 0x40 at v6+20; compute squared camera-to-node distance from the camera float array at this+0x204; when inside the squared radius and proximity (a3&1), run contact detection (sub_54EED0 or CollisionContactDetection) and increment dword_8C5F40 by the hit count.
- `0x0054FB70` **UnknownObject** — Read the linked node pointer at this+0x204, mask the byte at node+0x14 with 0x40, and return bit 6 shifted down as a 0/1 boolean (node property flag query).

## Proposed classes

### SceneMeshContainer

Mesh/vertex-buffer container that owns the AABB corner block, bounding sphere radius, and the mesh-entry and triangle-entry arrays, and computes its own bounds on demand (AABB, sphere, OBB).

Methods: `0x0054D080`, `0x0054D520`, `0x0054E080`, `0x0054E270`

- `this+0x00000014` `dword flags` (read_write, DERIVED)
- `this+0x00000018` `float boundingSphereRadius` (write, DERIVED)
- `this+0x0000001C` `float boundingBoxCorner0` (write, GUESS)
- `this+0x00000020` `float boundingBoxCorner1` (write, GUESS)
- `this+0x00000024` `float boundingBoxCorner2` (write, GUESS)
- `this+0x00000028` `float boundingBoxCorner3` (write, GUESS)
- `this+0x0000002C` `float boundingBoxCorner4` (write, GUESS)
- `this+0x00000030` `float boundingBoxCorner5` (write, GUESS)
- `this+0x00000034` `float boundingBoxCorner6` (write, GUESS)
- `this+0x00000038` `float boundingBoxCorner7` (write, GUESS)
- `this+0x0000003C` `float boundingBoxCorner8` (write, GUESS)
- `this+0x00000040` `float boundingBoxCorner9` (write, GUESS)
- `this+0x00000044` `float boundingBoxCorner10` (write, GUESS)
- `this+0x00000048` `float boundingBoxCorner11` (write, GUESS)
- `this+0x0000004C` `float boundingBoxCorner12` (write, GUESS)
- `this+0x00000050` `float boundingBoxCorner13` (write, GUESS)
- `this+0x00000054` `float boundingBoxCorner14` (write, GUESS)
- `this+0x00000058` `float boundingBoxCorner15` (write, GUESS)
- `this+0x0000005C` `float boundingBoxCorner16` (write, GUESS)
- `this+0x00000060` `float boundingBoxCorner17` (write, GUESS)
- `this+0x00000064` `float boundingBoxCorner18` (write, GUESS)
- `this+0x00000068` `float boundingBoxCorner19` (write, GUESS)
- `this+0x0000006C` `float boundingBoxCorner20` (write, GUESS)
- `this+0x00000070` `float boundingBoxCorner21` (write, GUESS)
- `this+0x00000074` `float boundingBoxCorner22` (write, GUESS)
- `this+0x00000078` `float boundingBoxCorner23` (write, GUESS)
- `this+0x000000DC` `float boundingBoxCenterX` (write, DERIVED)
- `this+0x000000E0` `float boundingBoxCenterY` (write, DERIVED)
- `this+0x000000E4` `float boundingBoxCenterZ` (write, DERIVED)
- `this+0x00000118` `dword meshEntryCount` (read, DERIVED)
- `this+0x0000011C` `pointer meshEntryListPtr` (read, DERIVED)
- `this+0x00000120` `dword triangleEntryCount` (read, DERIVED)
- `this+0x00000124` `pointer triangleEntryArrayPtr` (read, DERIVED)
- `this+0x0000012C` `pointer normalArrayPtr` (read, DERIVED)
- `*(this+0x11C)+0x00000008` `dword vertexCount` (read, DERIVED)
- `*(this+0x11C)+0x0000000C` `pointer vertexDataPtr` (read, DERIVED)
- `*(this+0x11C)+0x00000010` `dword layoutField0` (read, GUESS)
- `*(this+0x11C)+0x00000014` `dword layoutField1` (read, GUESS)

### StringListNodeContainer

Linked-list container of string nodes: append at the tail, search by normalized string key (single or multi-entry nodes), track a node count.

Methods: `0x00547860`, `0x00547920`

- `this+0x0000000C` `dword nodeCount` (read_write, DERIVED)
- `this+0x00000028` `pointer headPtr` (read_write, DERIVED)
- `this+0x00000084` `pointer nodeLayoutBase` (read, UNKNOWN)
- `*(this+0x84)+0x00000004` `pointer stringPtr` (read, DERIVED)
- `*(this+0x84)+0x0000004C` `dword subEntryCount` (read, DERIVED)
- `*(this+0x84)+0x0000005C` `pointer nextLink` (read_write, DERIVED)

### SoundBufferListContainer

Linked-list container of sound-buffer nodes: allocate-and-append a 24-byte node, search nodes by a float key at node+0x8.

Methods: `0x005489A0`, `0x00548A00`

- `this+0x0000002C` `pointer headPtr` (read_write, DERIVED)
- `this+0x00000040` `pointer nodeLayoutBase` (read, UNKNOWN)
- `*(this+0x40)+0x00000008` `float floatKey` (read, DERIVED)
- `*(this+0x40)+0x00000014` `pointer nextLink` (read_write, DERIVED)

### AudioNodeListContainer

Linked-list container of audio/scene nodes: lazy-allocating append with node population, and an iterator that dispatches SceneRenderTransform on every node.

Methods: `0x00548D40`, `0x00548DD0`

- `this+0x0000016C` `dword nodeCount` (write, DERIVED)
- `this+0x00000170` `pointer headPtr` (read_write, DERIVED)
- `this+0x00000188` `pointer nodeLayoutBase` (read, UNKNOWN)
- `*(*(this+0x188)+0x18)+0x00000018` `pointer nextLink` (read_write, DERIVED)

### SceneTreeNode

Scene/UI tree node with two child pointers (this+0x44, this+0x4C) that supports depth-first string search and recursive traversal with terminal state/bitfield dispatch.

Methods: `0x0054BC60`, `0x0054BCD0`

- `this+0x00000044` `pointer childSubtreeA` (read, DERIVED)
- `this+0x0000004C` `pointer childSubtreeB` (read, DERIVED)

### StateFlagObject

Object exposing a state flags dword at this+0x3C (bits 1 and 2 set by Bit12FlagSet, read complemented by BitFlagReader) plus two flag-gated value slots at this+0x234 and this+0x238.

Methods: `0x0054C0B0`, `0x0054C150`, `0x0054C1A0`

- `this+0x0000003C` `dword stateFlags` (read_write, DERIVED)
- `this+0x00000234` `dword valueSlot800` (read, DERIVED)
- `this+0x00000238` `dword valueSlot1000` (read, DERIVED)

### DoublyLinkedList

Doubly-linked list whose head is tracked at this+0x44 and whose nodes (prev/next at +0x48/+0x4C, container link at +0x40, optional sublist at +0x230) can be transplanted into a global list rooted at dword_8B8F28+264.

Methods: `0x0054BAA0`

- `this+0x00000044` `pointer headPtr` (read_write, GUESS)

### ByteBufferList

Doubly-linked list of byte-buffer nodes whose head is reachable through *(*this + 0x128) or *a2, initialized when this+0xF4 becomes non-null; nodes carry prev/next links at +0x68/+0x6C.

Methods: `0x00549250`

- `this+0x00000000` `pointer owningObjectPtr` (read, GUESS)
- `obj+0x00000128` `pointer headPtr` (read, GUESS)
- `this+0x000000F4` `pointer listInitFlag` (read_write, GUESS)
- `*(obj+0x128)+0x0000006C` `pointer nextLink` (read_write, GUESS)

### NodeListContainer

Linked-list container with head at this+0x204 and a node next link at +0x10 (framed under the sub-structure pointer at this+0x214).

Methods: `0x0054ABE0`

- `this+0x00000204` `pointer headPtr` (read_write, GUESS)
- `this+0x00000214` `pointer nodeLayoutBase` (read, GUESS)
- `*(*(this+0x214)+0x10)+0x00000010` `pointer nextLink` (read_write, GUESS)

### MultiListContainer

Container owning five independent linked-list roots (this+0xE8/+0xF0/+0xF8/+0xFC via node next links at +0x14, and this+0xEC via node next links at +0x4C) that are drained and freed as a unit.

Methods: `0x00548EB0`

- `this+0x000000E8` `pointer listARoot` (read_write, DERIVED)
- `this+0x000000EC` `pointer listBRoot` (read_write, DERIVED)
- `this+0x000000F0` `pointer listCRoot` (read_write, DERIVED)
- `this+0x000000F8` `pointer listDRoot` (read_write, DERIVED)
- `this+0x000000FC` `pointer listERoot` (read_write, DERIVED)

## Compatibility contracts

- **GlobalFlagWordContract** — A process-global flags word at 0x008B8E34 is ORed (set) or AND-Noted (cleared) by GlobalFlagSetClear with caller-supplied bit masks; a replacement must preserve an equivalent globally-visible bitmask semantics.
- **DeviceTransformDispatchContract** — The object at 0x008B8F24 exposes a transform entry point at vtable slot +4 invoked for vertex/position transforms (mesh vertices and node position offsets); a replacement must keep an equivalent device-transform dispatch entry.
- **UiContextRootContract** — The process-global UI/context pointer 0x008B8F28 feeds ValueGetter (0x00545F40) and hosts a doubly-linked-list root at offset +264 used by DoublyLinkedListNodeTransplant; a replacement must keep a single process-global context root with that list slot.
- **CollisionCounterContract** — The global counter 0x008C5F40 accumulates collision contact hits and saturates against the threshold at *(this+0x1E0)+4; a replacement must preserve a global contact counter with the same saturation semantics.
- **MeshBoundsContract** — A mesh/vertex-buffer container must expose a flags dword at +0x14 (bit 0x10 = valid 3D extents, bit 0x800000 = vertex-stride select), a bounding sphere radius at +0x18, the 24 AABB corner floats at +0x1C..+0x78, optional center floats at +0xDC/+0xE0/+0xE4, and the mesh-entry count/list at +0x118/+0x11C and triangle count/array at +0x120/+0x124 so the four bounds methods interoperate.

## Unresolved

- All 27 owners are UNKNOWN in the packet; the six DERIVED classes are static-layout groupings, not proven types.
- StringListNodeContainer: the packet frames node layout under base *(this+0x84) while the raw source walks the node chain directly; the two views are not reconciled. Node field +0x58 (prev) is prose-only (source:raw) with no packet field evidence ref, so it was omitted from the class definition.
- StringListNodeContainer: the 96-byte sub-entry stride used by StringSearchInLinkedList is an in-source constant with no packet field evidence.
- StringListNodeContainer fields this+0x2C and this+0x74 are listed by the packet extractor but no explicit dereference appears in the raw body of 0x00547920.
- SoundBufferListContainer: node layout base *(this+0x40) is a packet framing, not proven; whether the +0x10 slot is a true backward link (doubly linked) or another field depends on SoundBufferAllocator and the list consumers. The +0x10 back-link slot is prose-only (source:raw) with no packet field evidence ref, so it was omitted from the class definition.
- AudioNodeListContainer: node layout base *(this+0x188) is a packet framing; the next-link at node+0x18 is framed under the dereferenced base *(*(this+0x188)+0x18) in the packet evidence. Interpreting sub_548AD0's non-zero return as failure (yielding -1) is DERIVED, not confirmed.
- AudioNodeListContainer field this+0x1A0 is flagged by packet facts but absent from the raw source of 0x00548DD0.
- MultiListContainer: the four lists released with EmptyStub_0170 + FreeWrapper_7bcf use node next offsets 20 and 52, while the fifth uses offset 76 and sub_549110; the allocation-scheme difference is unresolved. The purpose of the EmptyStub_0170 no-op before each free is unexplained.
- MultiListContainer read-only fields this+0x10C, +0x110, +0x124 and +0x138 are listed in the packet but never accessed by 0x00548EB0.
- DoublyLinkedList: identity and layout of the global list at dword_8B8F28+264 is not grounded in this packet; whether the tail walk and the sublist reinsert share the same global list is not provable. Node dword indices 16/17/18/19/140 (container link, list head, prev, next, sublist) are typed only by their linkage roles and have no packet node-base field evidence refs, so they were omitted from the class definition.
- ByteBufferList: the head source is selected by bit 4 of a2's first byte (*(*this+0x128) vs *a2); the meaning of that selection and the this+0x0 owning pointer are unknown. The node prev slot at +0x68 is prose-only (source:raw) with no packet field evidence ref, so it was omitted from the class definition.
- NodeListContainer: relationship between head this+0x204 and sub-structure this+0x214 is unresolved from raw source alone; the sole caller sub_54A870 was not analyzed. The node prev slot at +0x140 is prose-only (source:raw) with no packet field evidence ref, so it was omitted from the class definition.
- SceneMeshContainer: 0x0054D520 iterates the entry list at *(this+0x11C) with 16-byte descriptors while 0x0054E270 iterates 64-byte mesh elements at the same offsets; the two entry strides are not reconciled (same base, different element size).
- SceneMeshContainer: 0x0054E080's ValueGetter(dword_8B8F28) return value is unused; the semantics of flag bits 0x2 and 0x1 in the per-object flags word at +0x9C are unknown.
- SceneMeshContainer: the unused parameter a2 of 0x0054D080 and the exact classification meaning of the normal dot product are unknown.
- OffsetDispatch (0x0054B3F0) reads floats at this+0x20/+0x24/+0x28 which numerically overlap the SceneMeshContainer AABB corner block, but no common ownership is proven; the callers span vehicle tyre positioning and camera viewport render setup.
- field this+0x204 appears in three different functions with three different meanings (list head in 0x0054ABE0, camera position array in 0x0054F5C0, linked node pointer in 0x0054FB70); these are kept as separate objects, never merged.
- SceneBatchRenderCheck (0x0054F5C0): entity struct offsets (a2+60, a2+516) and node struct offsets (v6+20, v6+24, v6+220..240) are not covered by the packet field table; the identity of the indirect vtable slot +4 on dword_8B8F24 is unknown.
- SceneBatchRenderCheck: whether dword_8C5F40 is truly an audio-collision counter (fill claim) is not independently confirmed.
- GlobalFlagSetClear (0x0054A200): the global flag set represented by dword_8B8E34 is unidentified and the caller-specific meaning of the flag bits is not established.
- lookupIndexedNode (0x00548850): the node-to-container (this+0xE4) relationship for the +0xC0 next pointer is not proven; container owner unknown.
- Config setters 0x00547100, 0x00547280 and 0x00547400 each operate on distinct unknown objects with non-overlapping field layouts (+0xA4, +0x8C/+0x90, none); they are deliberately not grouped. The 0x80000000 literal in ConditionalCheckCall and the keys 0x1000/0x2000 in DualFieldSetterByKey are unexplained.
- SceneTreeNode: a2/a3 passed through RecursiveTraversal have unestablished roles; RecursiveTraversal's two recursive call sites are structurally identical so the child-node layout is not established.
- StateFlagObject: the meaning of flag bits 1/2 at +0x3C and the 0x800/0x1000 modes of FlagPropertyGetter depends on callers not analyzed in this packet.
- Sentinel float globals (0x0059E420, 0x0059E430, 0x0059E440, 0x0059E450, 0x0059E98C, 0x005B8984) are used only as float constants (1.0/count, zero, +/-1e12) in the bounds computations; no other semantics are grounded.
- ExtractLinkedNodeFlagBit (0x0054FB70): packet records a read of this+0x218, but the raw source performs no access at that offset.
