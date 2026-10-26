# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Runtime object infrastructure for the F1C engine: (1) a two-head scene-node list container (heads this+0x100 / this+0x108) supporting append, node counting, indexed lookup, recursive string property search, and flag-driven per-frame updates; (2) a reference-counted D3D texture/resource object (refcounts +0x84/+0x88, flags +0x9C, 148-byte element slots at +0xA4/+0xA8, float-key node +0xB0/+0xB4) that materializes texture sets and releases sub-resources; (3) a string-keyed resource registry (list heads +0x24/+0x2C) used for name-based resource lookup and cleanup; (4) node allocator and constructor helpers (56-byte nodes, multi-field zero-init objects); and (5) teardown wrappers (ReleaseLinkedResource, DestroyFree), an audio-engine startup dispatch walk, and free helpers (string copy, key generation, global stream-cursor reader). Function owners are UNKNOWN in the packet except loadTextureSet (DERIVED TextureResourceLoader), findNodeByNameCaseInsensitive (DERIVED NamedStringList), and recursiveNodeFree (DERIVED SceneGraphNode); the class groupings below are DERIVED/GUESS synthesis over the evidenced field bases.

## Function roles

- `0x005450E0` **MeshResourceObject** — Mesh-resource factory: allocates a 572-byte heap block, constructs the mesh-resource object (sub_54A600), stores the caller-supplied ID at dword index 15, copies the name string (sub_54A730); returns 0 on success writing the pointer through a1, -1 after teardown+free on string-copy failure.
- `0x00545250` **SceneNodeListContainer** — Appends an actor node to the singly-linked scene-node list: sets flag bit 3 at node+0x3C, clears node forward link +0x4C, registers the node with the tree accumulator (sub_544C50), then appends to the tail (head at this+0x108) or promotes the node to head; writes the +0x48 backward link.
- `0x005452F0` **SceneNodeListContainer** — Counts nodes across the two scene-node chains: first chain rooted at this+0x100 (forward link node+0x104) contributes every node of its per-node sub-chain (head node+0xEC, links +0x4C); second chain rooted at this+0x108 (forward link +0x4C) is counted directly; returns the total.
- `0x00545340` **SceneNodeListContainer** — Indexed node lookup across the two hierarchical lists: when the first-list head at this+0x100 is non-null, walks each first-list node (next +260) descending its sub-list (head +236, links +76); falls back to the second list at this+0x108 (+76 links); returns the node at index a2 or 0 when exhausted.
- `0x005453A0` **SceneNodeListContainer** — Scene-node property evaluation: when flag a3 is non-zero searches the supplied tree a2 directly via RecursiveTreeStringSearch (sub_54BC60); otherwise walks the first chain (head this+0x100, sub-node at element+236, forward link element+260), falling back to the second chain at this+0x108; returns the first matched value or 0.
- `0x005454A0` **ResourceDestructor** — Resource teardown: unlinks the object from its doubly linked list (sub_5455F0), clears a byte flag (sub_55D2E0), and when non-null runs the empty stub (sub_557470) and frees the block (sub_587BCF); always returns 0. Invoked by ResourceCleanupDestructionForDirectXObjects.
- `0x00545930` **NodeListAllocator** — Node allocator/insert: allocates a 56-byte node (sub_587C03), initializes it with parameter a2 and the counter at this+0x158 (sub_560BA0), then appends it to the parent's child list (head +44) when parent a3 carries a non-null child container at a3+560, otherwise to the main list at this+0x15C; writes +48/+52 links, increments this+0x158, returns 0.
- `0x00545D00` **SceneNodeListContainer** — Flag-driven scene update: zeroes this+0x1B0 on a2 bit 0x20, ORs this+0xEC with 0x800 on a3 bit 0x20, walks the node list at this+0x100 (and the node at this+0x108) calling RecursiveTraversal (sub_54BCD0), propagates 0x40/0x80/0xC0 flag bits through the chain rooted at *(this+0x110)+36, then clears per-element flags selected by the a3&0x1800 mask across the four (count, array) pairs at this+0x1B4..0x1D0 (jump table at 0x545F24).
- `0x00546330` **FreeFunction** — Free helper: copies source string a2 into the caller buffer via strcpy, passes the buffer to the normalize helper sub_589901, stores integer a3 at DWORD index 46 of the buffer, and returns a3 unchanged. Used by resource-loading paths ResourceObjectCreationWithConfig and DirectXMeshVertexBufferParsingAndLoading.
- `0x00546450` **D3DResourceObject** — Texture-set materialization: iterates this-owned 148-byte element descriptors (base this+0xA8, bound this+0xA4), builds per-frame file paths, allocates zero-filled 96-byte frame blocks, creates D3D textures (sub_550080), registers/reuses nodes in the string-keyed list, maintains the float-key node at this+0xB4, and cleans up the global stream handles dword_8B8DBC/dword_8B8DC0 on the audio-flag path; returns 0 or -1. Owner DERIVED TextureResourceLoader.
- `0x005469C0` **D3DResourceObject** — Reference-counted resource release: returns -2 while the release-blocking flag bit at this+0x9C is set; otherwise decrements refcounts at this+0x84 and this+0x88 and returns -2 while this+0x88 stays non-zero; when the count reaches zero it frees each sub-resource slot (this+0xA8, count this+0xA4) by decrementing its list node refcount (node at *(this+0xA8)+0x8C), destructing per-element data when the node count at +0x4C reaches zero (sub_5502C0), removing the node (sub_5478B0) and zeroing the slot; finally ORs this+0x9C with 3 and returns 0.
- `0x005471C0` **D3DResourceObject** — Unconditional field setter: stores the second parameter into this+0xB0 and returns it unchanged. Called from DirectXMeshVertexBufferParsingAndLoading and D3DTextureResourceCreation.
- `0x00547240` **D3DResourceObject** — Dimension setter: stores WORD a2 at this+0xAC and WORD a3 at this+0xAE, each only when in [1,8]; sets flag bit 5 (0x20) at this+0x9C unless the pair is exactly (2,1); returns a3. Called by DirectXMeshVertexBufferParsingAndLoading, D3DTextureResourceCreation and sub_557CE0.
- `0x005473C0` **D3DResourceObject** — Increments two adjacent dword counters on the owner: this+0x88 first, then this+0x84; no other side effects. Runs on the per-frame path from TreeNodeAccumulator and two other callers.
- `0x005473D0` **ZeroInitializedObject** — Constructor/initializer: runs GlobalZeroInit_c2a0 (sub_53C2A0) then explicitly zeroes ten dword fields at offsets 0x8 through 0x2C; returns this.
- `0x00547420` **StringKeyedResourceList** — Bulk cleanup of two owned linked lists: the first (root this+0x24) is walked via node index 48, freeing each node's +0xBC payload (ArrayCleanupWithDualFree, EmptyStub_7470, FreeWrapper_7bcf) and the trailing node; the second (root this+0x2C) is walked via +20 links, freeing each node's +16 payload (SingleFieldFree) and the trailing node; returns 0.
- `0x005477F0` **StringKeyedResourceList** — String search of the string-keyed resource list: reads the head at this+0x24; when non-null walks nodes comparing each node's string against a2 with strcmp and following the next pointer at node+192 (0xC0) until a match or the end; returns the matched node or 0. Used for name-based resource lookup by mesh and texture loading paths.
- `0x00548620` **FreeFunction** — Material-library lookup and texture creation: tries direct open of a2, then the registered entry path array byte_8B5A3C (stride 132, count dword_8B8E30), then a linked list from head dword_8B8F14 (nodes tested with sub_560230); for each located file runs D3DTextureResourceCreation and closes the handle; returns -1 with an 'Unable to locate material lib' report (sub_53C590) when nothing is found, 0 otherwise.
- `0x00548890` **StringKeyedResourceList** — Case-insensitive name lookup over the string-keyed list: normalizes the needle via sub_589901, reads the head at this+0x24, and walks nodes (next at node+0xC0) comparing each node's name, where the per-node flag at +0x9C bit 0x200 selects wide vs narrow string layout; returns the matching node or 0. Owner DERIVED NamedStringList.
- `0x00548A30` **FreeFunction** — Free helper generating a 4-character NUL-terminated printable key: seeds the TLS random context with a1 modulo 42330 (sub_5884E0), folds a pseudo-random value (v3 << 17) | v3 (sub_5884ED), maps four successive low bytes into the 48..126 range via modulo 78, and returns the last computed quotient.
- `0x00548E00` **ZeroInitializedObject** — Constructor/initializer: bulk zero-initializes the object via GlobalZeroInit_c2a0 (sub_53C2A0), then explicitly clears the byte at offset 0x0 and the dwords at offsets 0x10 and 0x14; returns this.
- `0x00549110` **SceneGraphNode** — Recursive node free: recurses into the child at +0x44 when non-null, and into the child at +0x4C when both the guard at +0x40 and the pointer are non-null; returns -1 when the SceneGraph check (sub_54A770) fails, otherwise runs the TwoFunctionCallChain teardown (sub_54A710) and frees the node (sub_587BCF), returning 0. Owner DERIVED SceneGraphNode.
- `0x005492B0` **AudioEngineSetup** — Audio-engine startup dispatch: walks the linked list headed at this+0xF0 (next at node+0x34), reads the string at each node's data base plus 88 bytes, looks it up via sub_5456B0 on the manager context this[0], and for a match removes the entry from the source doubly linked list (sub_5455F0) and inserts it into the byte buffer (sub_549250).
- `0x0054A240` **ResourceDestructor** — Destroy-and-free wrapper for a multi-list container: unconditionally releases the list contents via MultiListFreeWithTraversal (sub_548EB0); when the object pointer is non-null, finalizes it with the empty stub (sub_557470) and frees the block (sub_587BCF); returns 0. Invoked by ResourceCleanupDestructionForDirectXObjects.
- `0x0054A5C0` **GlobalStreamReader** — Global stream-cursor reader: copies a3 bytes from (a2 + dword_8B8F3C) into the destination buffer a1, advances dword_8B8F3C by a3, and returns the copied byte count a3. Called by rendering/resource loaders (DirectXMeshVertexBufferParsingAndLoading, D3DTextureResourceCreation, sub_54AC70, MeshVertexIndexBufferLoader).

## Proposed classes

### MeshResourceObject

572-byte mesh-resource object: stores a caller-supplied resource ID (dword index 15) and a copied name string; constructed via the sub_54A600 constructor and cleaned up through the TwoFunctionCallChain teardown sub_54A710. The stored ID and name string are described in the packet but have no packet-allowed field evidence refs, so they are documented in unresolved rather than declared as fields.

Methods: `0x005450E0`


### SceneNodeListContainer

Container of two singly-linked scene-node lists (heads +0x100 and +0x108) with per-node sub-lists and a flag-propagation chain; supports node append, node counting, indexed lookup, recursive string-property search, and flag-driven per-frame update.

Methods: `0x00545250`, `0x005452F0`, `0x00545340`, `0x005453A0`, `0x00545D00`

- `this+0x00000100` `void* first_list_head` (read_write, DERIVED)
- `this+0x00000108` `void* second_list_head` (read_write, DERIVED)
- `this+0x00000154` `void* tail_walk_base` (read, DERIVED)
- `this+0x000001EC` `void* sub_list_base` (read, GUESS)
- `this+0x000000EC` `uint32 element_flag_dword` (read_write, DERIVED)
- `this+0x00000110` `void* flag_chain_root_ptr` (read, DERIVED)
- `this+0x00000134` `void* flag_chain_base` (read, GUESS)
- `this+0x000001B0` `uint32 cleared_dword` (write, DERIVED)
- `this+0x000001B4` `int element_count_0` (read, DERIVED)
- `this+0x000001B8` `void* element_array_0` (read, DERIVED)
- `this+0x000001BC` `int element_count_1` (read, DERIVED)
- `this+0x000001C0` `void* element_array_1` (read, DERIVED)
- `this+0x000001C4` `int element_count_2` (read, DERIVED)
- `this+0x000001C8` `void* element_array_2` (read, DERIVED)
- `this+0x000001CC` `int element_count_3` (read, DERIVED)
- `this+0x000001D0` `void* element_array_3` (read, DERIVED)
- `this+0x000001F4` `uint32 element_gate` (read, GUESS)
- `this+0x000001F8` `uint32 element_gate_aux` (read, GUESS)
- `this+0x00000200` `uint32 element_gate_aux2` (read, GUESS)

### D3DResourceObject

Reference-counted D3D texture/resource object: refcounts at +0x84/+0x88, a flags dword at +0x9C, a 148-byte element-slot array (count +0xA4, base +0xA8), WORD dimensions +0xAC/+0xAE, a float key at +0xB0 with a cached float-key node at +0xB4, and a linked sub-resource list head at +0xB8. Materializes texture sets and releases sub-resources on the count reaching zero.

Methods: `0x00546450`, `0x005469C0`, `0x005471C0`, `0x00547240`, `0x005473C0`

- `this+0x00000084` `int refcount_a` (read_write, DERIVED)
- `this+0x00000088` `int refcount_b` (read_write, DERIVED)
- `this+0x0000009C` `uint32 flags` (read_write, DERIVED)
- `this+0x000000A4` `int element_slot_count` (read, DERIVED)
- `this+0x000000A8` `void* element_slot_array` (read, DERIVED)
- `this+0x000000AC` `uint16 dim_word_a` (write, DERIVED)
- `this+0x000000AE` `uint16 dim_word_b` (write, DERIVED)
- `this+0x000000B0` `float float_key` (read_write, DERIVED)
- `this+0x000000B4` `void* float_key_node` (write, DERIVED)
- `this+0x000000B8` `void* subresource_list_head` (read, DERIVED)

### StringKeyedResourceList

Registry of name-keyed resource nodes with two list heads (+0x24 and +0x2C); nodes carry a next pointer at +0xC0 (packet base *(this+0xE4)); supports case-sensitive string lookup, normalized (case-insensitive) name lookup, and bulk two-list cleanup.

Methods: `0x00547420`, `0x005477F0`, `0x00548890`

- `this+0x00000024` `void* list_head` (read_write, DERIVED)
- `this+0x0000002C` `void* list_head_secondary` (read, DERIVED)
- `this+0x000000E4` `void* traversal_node_base` (read, GUESS)

### ZeroInitializedObject

Object family constructed by a bulk zero-init (GlobalZeroInit_c2a0) plus explicit field clears; the two constructors clear byte 0x0 / dwords 0x8..0x2C (MultiFieldZeroInitConstructor) and byte 0x0 / dwords +0x10/+0x14 (objectZeroInitConstructor).

Methods: `0x005473D0`, `0x00548E00`

- `this+0x00000000` `uint8 first_byte` (write, DERIVED)
- `this+0x00000008` `uint32 zeroed_dword_08` (write, DERIVED)
- `this+0x0000000C` `uint32 zeroed_dword_0C` (write, DERIVED)
- `this+0x00000010` `uint32 zeroed_dword_10` (write, DERIVED)
- `this+0x00000014` `uint32 zeroed_dword_14` (write, DERIVED)
- `this+0x00000018` `uint32 zeroed_dword_18` (write, DERIVED)
- `this+0x0000001C` `uint32 zeroed_dword_1C` (write, DERIVED)
- `this+0x00000020` `uint32 zeroed_dword_20` (write, DERIVED)
- `this+0x00000024` `uint32 zeroed_dword_24` (write, DERIVED)
- `this+0x00000028` `uint32 zeroed_dword_28` (write, DERIVED)
- `this+0x0000002C` `uint32 zeroed_dword_2C` (write, DERIVED)

### SceneGraphNode

Scene-graph node freed recursively: child pointers at +0x44 (unconditional) and +0x4C (gated on the +0x40 guard); freeing aborts (returns -1) when the SceneGraph check at 0x0054A770 reports failure.

Methods: `0x00549110`

- `this+0x00000040` `uint32 second_child_guard` (read, DERIVED)
- `this+0x00000044` `void* first_child` (read, DERIVED)
- `this+0x0000004C` `void* second_child` (read, DERIVED)

### NodeListAllocator

Allocates and inserts 56-byte nodes into a main list (head +0x15C, first link +0x190) or a parent's child list; owns the node counter at +0x158.

Methods: `0x00545930`

- `this+0x00000158` `int node_counter` (read_write, DERIVED)
- `this+0x0000015C` `void* main_list_head` (read, DERIVED)
- `this+0x00000190` `void* main_list_first_link` (read, DERIVED)

### AudioEngineSetup

Audio-engine startup dispatch: walks a list of named entries (head +0xF0), looks each name up through the manager context this[0], and relocates matched entries from the source doubly linked list into the byte buffer.

Methods: `0x005492B0`

- `this+0x00000000` `void* manager_context` (read, DERIVED)
- `this+0x000000F0` `void* entry_list_head` (read, DERIVED)

### ResourceDestructor

Teardown wrappers that unlink objects from lists, run stub finalizers, and free heap blocks during resource teardown (ReleaseLinkedResource for singly-owned resources, DestroyFree for multi-list containers).

Methods: `0x005454A0`, `0x0054A240`


### GlobalStreamReader

Reads bytes from the global stream-buffer cursor dword_8B8F3C at a caller-supplied offset and advances the cursor by the copied length.

Methods: `0x0054A5C0`


### SceneListNode

Node of the scene-node lists: carries a forward link at +0x4C (tail-walk base *(this+0x154)) and a backward link at +0x48.

Methods: 

- `*(this+0x154)+0x0000004C` `void* forward_link` (read_write, DERIVED)

### FirstListNode

Node of the first scene-node chain (base *(this+0x204)): holds a sub-list head at +0xEC and the next first-list link at +0x104.

Methods: 

- `*(this+0x204)+0x000000EC` `void* sub_list_head` (read, DERIVED)
- `*(this+0x204)+0x00000104` `void* next_link` (read, DERIVED)

### SubListNode

Node of a per-first-node sub-list (reached via base *(*(this+0x204)+0xEC)): next link at +0x4C. The packet field evidence spells the base as *(*(*(this+0x204)+0xEC)+0x4C), which is used verbatim for the field declaration.

Methods: 

- `*(*(*(this+0x204)+0xEC)+0x4C)+0x0000004C` `void* next_link` (read, DERIVED)

### SubListWalkNode

Node of a sub-list walked during indexed lookup (base *(*(this+0x1EC)+0x4C)): next link at +0x4C.

Methods: 

- `*(*(this+0x1EC)+0x4C)+0x0000004C` `void* next_link` (read, DERIVED)

### FlagChainNode

Node of the flag-propagation chain (base *(this+0x134)): flag dword at +0x9C, next link at +0xC0. The packet field evidence spells the next-link base as *(*(this+0x134)+0xC0), which is used verbatim for the field declaration.

Methods: 

- `*(this+0x134)+0x0000009C` `uint32 flag_dword` (read_write, DERIVED)
- `*(*(this+0x134)+0xC0)+0x000000C0` `void* next_link` (read, DERIVED)

### NamedNode

Node of the string-keyed resource list (base *(this+0xE4)): next link at +0xC0. A per-node name-layout flag at +0x9C (bit 0x200 selects wide-character names) is described in the packet but has no packet-allowed field evidence ref, so it is documented in unresolved rather than declared as a field.

Methods: 

- `*(this+0xE4)+0x000000C0` `void* next_link` (read, DERIVED)

### AllocListNode

Node of the node-allocator main list (base *(this+0x190)): next link at +0x34 (52). The packet field evidence spells the next-link base as *(*(this+0x190)+0x34), which is used verbatim for the field declaration; the node also carries +48/+52 links per the raw source.

Methods: 

- `*(*(this+0x190)+0x34)+0x00000034` `void* next_link` (read_write, DERIVED)

### SubresourceSlot

Element of the D3D resource slot array (base *(this+0xA8), 148-byte stride): stores the node pointer at +0x8C.

Methods: 

- `*(this+0xA8)+0x0000008C` `void* node_ptr` (read_write, DERIVED)

### SubresourceNode

Node referenced by a sub-resource slot (base *(*(this+0xA8)+0x8C)): refcount at +0x0 and element count at +0x4C.

Methods: 

- `*(*(this+0xA8)+0x8C)+0x00000000` `int refcount` (read_write, DERIVED)
- `*(*(this+0xA8)+0x8C)+0x0000004C` `int element_count` (read, DERIVED)

### ListContainerHead

Indirection stub of the sub-resource list (base *(this+0xB8)): list head at +0x28, from which nodes are walked via dword index 23.

Methods: 

- `*(this+0xB8)+0x00000028` `void* head` (read, DERIVED)

## Compatibility contracts

- **TwoHeadSceneListLayout** — The scene-node container keeps two singly-linked node lists at +0x100 and +0x108. Append (0x00545250) sets flag bit 3 at node+0x3C, clears the node forward link (+0x4C), registers the node with the tree accumulator (sub_544C50), and maintains +0x48 backward links. Counting and indexed lookup descend per-node sub-lists (head at node+0xEC). A replacement must preserve the two-head traversal order and the +0x4C/+0x104 forward-link semantics.
- **TextureResourceRefcountRelease** — ReferenceCountedResourceRelease (0x005469C0) decrements refcounts at +0x84/+0x88. It returns -2 while the release-blocking flag at +0x9C bit 1 is set or while +0x88 stays non-zero, and returns 0 only after sub-resource nodes are freed and +0x9C is ORed with 3. Callers sub_547710 and LinkedListWalkWithExitCheck depend on this -2 vs 0 signalling.
- **TextureSetElementDescriptor** — Texture-set loading (0x00546450) iterates 148-byte element descriptors (array base +0xA8, bound +0xA4). A dword at element+96 equal to the 0x8000000 sentinel selects the single-object path with a 20-byte struct at element+144; otherwise the frame-count path allocates 96-byte zero-filled frame blocks (count recorded via sub_550300) and creates D3D textures. Element layout observed at offsets +0, +64, +68, +72, +96, +128, +140, +144.
- **StringKeyedResourceRegistry** — The resource registry roots lists at +0x24 and +0x2C. Nodes carry a next pointer at +0xC0 and, for the normalized lookup, a name-layout flag at node+0x9C (bit 0x200 selects wide-character names). Name lookups apply the same normalization (sub_589901) to the needle before comparing, and a two-list bulk cleanup (0x00547420) frees per-node payloads.
- **GlobalStreamCursorRead** — CopyFromGlobalBufferAndAdvance (0x0054A5C0) reads from the global buffer cursor dword_8B8F3C at a caller-supplied offset and advances the cursor by the copied length, returning the byte count. Callers pass offsets with no bounds check; a replacement must mirror the single-cursor advance-by-read semantics exactly.
- **RecursiveNodeFreeGuard** — recursiveNodeFree (0x00549110) recurses into the +0x44 child unconditionally when non-null but only into the +0x4C child when the guard at +0x40 is non-null, and aborts the entire free (returning -1) when the SceneGraph check (0x0054A770) reports failure. This ordering and the guard must be preserved.

## Unresolved

- All packet function owners are UNKNOWN except loadTextureSet (DERIVED TextureResourceLoader), findNodeByNameCaseInsensitive (DERIVED NamedStringList), and recursiveNodeFree (DERIVED SceneGraphNode); the class groupings (MeshResourceObject, SceneNodeListContainer, D3DResourceObject, StringKeyedResourceList, ZeroInitializedObject, NodeListAllocator, AudioEngineSetup, ResourceDestructor, GlobalStreamReader) are worker synthesis at DERIVED/GUESS, not packet evidence. Equal byte offsets on distinct this-bases (e.g. this+0x40 on SceneGraphNode vs StringKeyedResourceList cleanup, +0x4C node links across SceneListNode/SubListNode/SubresourceNode, +0x9C flags on D3DResourceObject vs FlagChainNode/NamedNode) are NOT merged; common ownership is unproven.
- applyFlagDrivenTraversal (0x00545D00) roots its flag-propagation chain at *(this+0x134) per the deterministic facts (fields *(this+0x134):0x9C and *(*(this+0x134)+0xC0):0xC0) but the Hex-Rays rendering roots it at *(this+0x110)+36; the two bases cannot be reconciled from this packet alone.
- The node-list fields of applyFlagDrivenTraversal are attributed to base *(this+0x204) (offsets 0xEC, 0x104) by the facts while the source renders them relative to list nodes reached from this+0x100; base mapping unresolved. The +0x1EC sub-list base has no counterpart in the raw source text.
- field:this:0x00000000 is tri-ambiguous: the MeshResourceAllocator output pointer a1, the manager context this[0] of LinkedListWalkWithDispatch, and the cleared first byte of objectZeroInitConstructor. It is placed on ZeroInitializedObject and AudioEngineSetup separately, with no cross-ownership claim.
- field:this:0x000000C0 (findNodeByNameCaseInsensitive node next pointer) is labeled with a this-base by the packet while the traversal base *(this+0xE4):0xC0 is used elsewhere; the two are treated as the same +0xC0 node link but the base spelling is not reconciled.
- ZeroInitializedObject offsets +0x24/+0x2C coincide with StringKeyedResourceList list roots and +0x10/+0x14 coincide with D3DResourceObject elements; the constructors (callers sub_53CAC0/sub_54AC70 and sub_53CAC0) may construct a shared object family, but common ownership is not proven.
- field:this:0x00000025, field:this:0x00000040, field:this:0x00000124, field:this:0x000001A0, field:*(this+0x40):0x00000010 and field:*(*(this+0xB8)+0x28):0x000000B8 appear in packet evidence but have no grounded operation in the raw source text; their roles (possibly decomposition artifacts or unread element/version gates) are unproven.
- The this+0x9C flag bits (release-block bit 1, dimension-flag bit 5, loader bits 0/1/0x40/0x400) and the element+64/element+96 mask literals (0x20, 0x100, 0x1800, 0x800, 0x1000, 0x8000000, 0x00800000, 0x4000, 0x400000) are observed literals only; their consumers and meanings are not established here.
- The 148-byte element-slot stride and the 24-byte sub-resource element stride are inferred from loop increments and have no named struct backing; the sub-resource list head at this+0xB8 and its +0x28 indirection are read as two distinct fields whose object roles are not established.
- ReferenceCountedResourceRelease returning -2 vs 0 to callers sub_547710 and LinkedListWalkWithExitCheck is not semantically established by this packet.
- MeshResourceObject's resource ID at dword index 15 (derived from the packet summary, GUESS) has no packet-allowed field evidence ref: field:this:0x0000003C is outside the packet's allowed evidence refs, so it is documented here rather than declared as a field; the 572-byte block layout and name-string offset are not evidenced.
- LoadMaterialLibrary's entry-path array byte_8B5A3C stride 132, the dword_8B8F14 linked-list 304-byte stride, and the count comparison against dword_8B6AC0 (a mismatch returning success 0) are observed from the raw walk only.
- The mapping of rodata format-string globals 0x005BE860/0x005DBE48/0x005DBE54 to the inline format literals in loadTextureSet is inferred, not evidenced; global dword_8B8F28 (0x008B8F28) has no visible role in the decompiled text.
- GenerateRandomPasswordKey: the semantic role of a1 (seed or key index), the 42330 modulus, and whether RandLCGRandomNumberGenerator's raw-register argument is meaningful are unresolved.
- Free functions SelfCopyStringToBuffer (0x00546330), LoadMaterialLibrary (0x00548620), GenerateRandomPasswordKey (0x00548A30) have no defensible class owner and are kept unassigned.
- EmptyStub_7470 (0x00557470) and TwoFunctionCallChain (0x0054A710) labels are taken from existing analysis, not independently verified; their real cleanup behavior is unknown.
