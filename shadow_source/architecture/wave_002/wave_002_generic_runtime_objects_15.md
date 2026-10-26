# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Reconstructs the generic runtime object layer from twenty validated functions. Three DERIVED classes carry the strongest evidence: SceneGraphRenderResourceManager (0x00543FA0) for draw-element/bucket allocation and scene-graph/audio walks, ResourceObject (0x00546250, 0x00546F30, 0x00546F70, 0x00547040, 0x005470A0) for the 196-byte resource object and its range-gated setter family, and AudioNetworkStreamManager (0x00544AF0) for audio stream/sub-stream teardown against two tree lists and stream-handle globals. One GUESS class ResourceManager merges the resource registry list operations (0x005474D0 create/reuse, 0x00547670 append, 0x00547710 remove, 0x005487A0/0x005487E0 walks) on shared +0x24 head / +0xC0 next / counter offsets. GUESS classes MeshResourceManager, TextureResourceManager, SceneGraphNode, AudioNetworkNode and SoundSource cover the loaders and node/destructor types. Three functions (0x00545F40 getter, 0x00545F50 audio load-ratio callback, 0x005461B0 mutex cleanup) stay unowned. One GUESS interface IResourceConfigurator groups the gated setter family; one GUESS state machine models the dword_8B8EF8 audio buffer load-state dispatch. Four DERIVED compatibility contracts capture resource construction, list counters, audio teardown and vertex-buffer bucket rebuild. Field semantics and several owner identities remain unresolved.

## Function roles

- `0x00543FA0` **SceneGraphRenderResourceManager** — Vertex-buffer resource (re)allocation for scene rendering: frees the existing 24-byte draw-element array (count +0x14C, ptr +0x150), reallocates it sized by the +0x64 element count, walks the scene-graph list (+0x100) and audio list (+0x108) with SceneGraphRenderWalk (0x0054BD30), runs the audio-list walk with AudioNetworkTreeWalker (0x00544D30), and, when master flags (+0xEC) bit 0x4 is clear, runs the UI/list cleanup chain (0x005487A0, 0x00548810, 0x00544740, 0x00545A10, 0x00545A40, 0x00545BB0). Re-allocates four 528-byte bucket arrays (+0x1B8/+0x1C0/+0x1C8/+0x1D0) from counts mirrored at +0x1B4..+0x1CC/+0x44..+0x50, classifies draw elements by flag bits 0x20/0x100 via 0x00548850, and builds the vertex-format descriptor from element flags and per-material data (pointer sentinels 0x00800000/0x00804000, material-type switch) with 0x005414E0 gating on 0x008B78A0. Returns 0 on success, -1 on walk failures.
- `0x00544AF0` **AudioNetworkStreamManager** — Audio network stream teardown: when owner flags (+0xEC) have bit 0x100000 set, destroys the sub-stream array (count +0x160, stride 96, 0x005502C0), unlinks it (0x005478B0), zeroes +0x160/+0x164, frees the shared audio buffer global 0x008B78A0 (0x00541420), and clears the 0x100000 flag. Destroys the stream-handle globals 0x008B8DBC/0x008B8DC0 (0x00542E50, 0x00557470, 0x00587BCF). Walks the +0x100 and +0x108 tree lists with TreeActiveCheck (0x00544E20), returning -1 while any active tree remains; otherwise runs TextureFlagTestWithDispatch (0x00557630) over the +0x148 texture list, finishes with 0x00540760(0x008B78A0) and returns 0.
- `0x00544D30` **AudioNetworkNode** — Recursive audio-network tree walk: reads two child pointers a2[17] and a2[19], recurses on each (depth flag 1), aborting with -1 if a subtree reports busy/failure; then walks the linked chain at a2[129] following next pointers at offset 16 while the node is not transform-ready (VertexBufferTransform of flags +0xEC bit 4, 0x0054C6C0). Returns -1 when a ready chain node is found, 0 when the chain terminates.
- `0x00544EF0` **SceneGraphNode** — Recursive scene-graph tree destructor: recurses into child +0x1B0 unconditionally and into child +0x1B8 only when both +0x1AC and +0x1B8 are non-null, removes the node from its doubly linked list (0x00545090), runs the EmptyStub_0170 (0x004B0170) and EmptyStub_7470 (0x00557470) cleanup stubs, and frees the node (0x00587BCF). Invoked by ResourceCleanupDestructionForDirectXObjects (0x00543BF0) during render-side teardown.
- `0x00545150` **SoundSource** — 3D sound-source destructor owned by an audio manager: recursively destroys sub-sources a2[17] and a2[19] (gated on a2[16]), aborts with -1 while the object is still attached via SceneGraph (0x0054A770), tears down the optional buffer resource at +0x230 (0x00560E50/0x00560F10/0x005459D0/0x00560C00/0x00587BCF), nulls the matching entry in the manager registration array (base this+0x150, count this+0x14C, stride 24), detaches via LinkedListRemove (0x005452B0), runs the destructor chain (0x0054A710) and frees the object.
- `0x00545F40` **UnknownObject** — Pure thiscall getter returning this[68], the dword field at +0x110. No side effects. Its caller set spans rendering, cockpit/gauge setup, vehicle-graphics scene loading, render-target cleanup, queue resource cleanup and flag-set rendering, indicating a widely shared field on a graphics/resource object.
- `0x00545F50` **UnknownObject** — Audio buffer load-ratio computation driving a stored callback: returns 0 immediately when callback global 0x008B8F00 is null; otherwise dispatches on buffer-state global 0x008B8EF8 via jump table jpt_545F6C (0x00545FF8). Case 1 computes (1 - dword_8B8EE8/dword_8B8EF0)*20.0, case 2 computes (1 - Addend(0x008B8EEC)/dword_8B8EF4)*80.0 + 20.0; both clamp to no-op below 0.25 and otherwise invoke the callback with the float; case 3 invokes the callback with literal 1120403456; default returns 0.
- `0x005461B0` **UnknownObject** — Mutex/semaphore-style object cleanup: aborts with -1 when ResourceCleanupDestructionForDirectXObjects (0x00543BF0) fails, unlinks the object (0x0053C630), releases its scene node (0x005437E0) and frees it (0x00587BCF), clears global 0x008B8F28 to 0 and returns 0.
- `0x00546250` **ResourceObject** — Resource-object constructor/initializer: zero-initializes via GlobalZeroInit (0x0053C2A0), memsets the first 0x40 bytes, writes literal defaults at +0x84..+0xC0 (float 294912.0625 at +0x9C, all-bits-set sentinel at +0xA0, 65538 at +0xAC, float 1.0 at +0xB0, zeros elsewhere), and configures four control channels via IndexedFieldCopy (0x00547140, channels 1-4 with 0xFFFFFF/0) and SwitchBasedFloatSetter (0x005471D0). Returns this.
- `0x00546F30` **ResourceObject** — Range-gated configuration trigger: reads the bound at this+0xA4; when a2 < bound and bound < 8 calls SimpleSetter_fc40 (0x0054FC40) with literal 0x100000; otherwise does nothing. Always returns 0.
- `0x00546F70` **ResourceObject** — Range-gated resource-object configuration: when a2 < this+0xA4 < 8 runs four setters (SimpleSetter_fc40(&unk_800000), DualFieldSetter(0,0) 0x0054FC80, ShortComputation_fd30(1.0,1.0) 0x0054FD30, FieldSetter_fca0(2) 0x0054FCA0) and ORs bit 0x80 into the flags at +0x9C. Returns 0 on both paths.
- `0x00547040` **ResourceObject** — Conditional render-state setup on the D3D texture-resource path: when a2 < this+0xA4 < 8 applies SimpleSetter_fc40(0x1000000), DualFieldSetter(0,0), ShortComputation_fd30(1.0,1.0) and FieldSetter_fca0(5). Always returns 0. Structurally a twin of sub_546FE0 per cluster analysis.
- `0x005470A0` **ResourceObject** — Guarded render-state set: when the incoming argument is below this+0xA4 and that bound is below 8 applies SimpleSetter_fc40(0x8000000), DualFieldSetter(0,0), ShortComputation_fd30(1.0,1.0) and FieldSetter_fca0(4); always returns 0. Structural twin of sub_546FE0. Called by DirectXMeshVertexBufferParsingAndLoading (0x00547B40) and D3DTextureResourceCreation (0x00548190).
- `0x005474D0` **ResourceManager** — Resource-manager entry point that reuses or allocates a resource: looks up by name (0x00548890) and, when found with a4 flag bit 0x100 clear, bumps the reference count at +136 and returns 0; otherwise allocates a 196-byte object (0x00587C03), initializes it (0x00546250), copies the name (0x00546330), allocates the 148-byte sub-resource array (0x0054FB90), runs conditional validators (0x00546F30, 0x00547100, 0x00546F70), stores config, links the node (0x00547670) and returns 0 (-1 on validator failure).
- `0x00547670` **ResourceManager** — Appends resource node a2 to the singly linked list rooted at this+0x24 (walking to the tail via each node's next pointer at +0xC0, or making a2 the head on an empty list; sets prev/next links), then increments the total counter this+0x10 and one of four bucket counters (this+0x14/+0x18/+0x1C/+0x20) selected by flag bits 0x20/0x100 of a2[39] (+0x9C). Returns the new total count.
- `0x00547710` **ResourceManager** — Resource-manager node removal: decrements the node reference count (0x005469C0) and only when it reaches 0 continues: formats an already-deleted message (0x0058815F, global 0x005DBE60) when the state word is -1, decrements one of the four category counters (+0x14..+0x20) selected by bits 0x20/0x100, splices the node out of the doubly linked list (relinking a2[47]/a2[48] neighbor pointers), advances the list head +0x24 if needed, frees internal arrays (0x00546370), runs the stub (0x00557470), frees the node (0x00587BCF), and decrements the total count +0x10.
- `0x00547B40` **MeshResourceManager** — Mesh/vertex-buffer resource loading: reads a stream in fixed chunks (4 and 32 bytes) via ArithmeticComparison_a5c0 (0x0054A5C0), and per entry allocates a 196-byte resource object (0x00587C03), initializes it (0x00546250), copies its name (0x00546330), applies conditional setters (0x00546F30/0x00546F70), render-state and dimension config (0x005470A0/0x005471C0/0x00547240), a default/field-config group (0x0054FB90, 0x0054FC10, 0x0054FC70, 0x0054FC80, 0x0054FCB0, 0x0054FCC0, 0x0054FD30, 0x0054FD50, 0x0054FDA0, 0x0054FDF0, 0x0054FE00, 0x00552FC0), deduplicates by name (0x005477F0, 0x00546370), generates a random password key for tagged textures (0x00548A30), and appends to the resource list (0x00547670). Reads global 0x008B8F30.
- `0x00548190` **TextureResourceManager** — Texture resource loading from a stream: reads an entry count (0x0054A5C0) and per entry allocates and initializes a 196-byte resource object (0x00587C03, 0x00546250), configures flags/dimensions/simple field (0x00547240, 0x005471C0), allocates the 148-byte sub-resource array (0x0054FB90), optionally generates a random name suffix (0x00548A30, 0x00587DD0), deduplicates by name (0x005477F0) or appends (0x00547670), then iterates sub-resources reading render-state tokens and dispatching on element field [24] values (0x00800000 -> 0x00546F70, 0x100000 -> 0x00546F30, 0x400000 -> 0x00546FE0, 0x1000000 -> 0x00547040, 0x8000000 -> 0x005470A0) plus element flags (0x0054FC50, 0x0054FCB0, 0x0054FCC0, 0x0054FD50). Returns 0 when all entries are processed, -1 on render-state setter failure.
- `0x005487A0` **ResourceManager** — Walks the linked list rooted at the head in this[9] (this+0x24) following node next pointers at +0xC0; for each node calls 0x00546450(node, -1) and returns -1 immediately on a non-zero match; otherwise atomically decrements the Addend global (InterlockedDecrement at 0x0059E234/0x008B8EEC) and runs AudioVolumeLoadComputation(0) (0x00545F50), then advances. Returns 0 when the list is empty or the chain ends without a match.
- `0x005487E0` **ResourceManager** — Walks the chain of reference-counted resources rooted at the head in this[9] (this+0x24), releasing each node via ReferenceCountedResourceRelease (0x005469C0) and advancing through each node's next pointer at +0xC0. Returns 0 when the list is empty or the chain ends normally, and -1 when a release returns -1.

## Proposed classes

### SceneGraphRenderResourceManager

Scene/render resource management object holding draw-element arrays, the scene-graph and audio lists, and four per-bucket vertex-draw arrays; allocation/rebuild is performed by 0x00543FA0.

Methods: `0x00543FA0`

- `this+0x00000044` `dword mirror_bucket_count_0` (write, GUESS)
- `this+0x00000048` `dword mirror_bucket_count_1` (write, GUESS)
- `this+0x0000004C` `dword mirror_bucket_count_2` (write, GUESS)
- `this+0x00000050` `dword mirror_bucket_count_3` (write, GUESS)
- `this+0x00000064` `dword element_count` (read, GUESS)
- `this+0x000000EC` `dword master_flags` (read, GUESS)
- `this+0x00000100` `void* scene_graph_list_head` (read, GUESS)
- `this+0x00000108` `void* audio_list_head` (read, GUESS)
- `this+0x00000110` `void* sub_struct_ptr` (read, GUESS)
- `this+0x0000014C` `dword draw_element_count` (read, GUESS)
- `this+0x00000150` `void* draw_element_ptr` (read_write, GUESS)
- `this+0x000001B4` `dword bucket_count_0` (write, GUESS)
- `this+0x000001B8` `void* bucket_ptr_0` (read_write, GUESS)
- `this+0x000001BC` `dword bucket_count_1` (write, GUESS)
- `this+0x000001C0` `void* bucket_ptr_1` (read_write, GUESS)
- `this+0x000001C4` `dword bucket_count_2` (write, GUESS)
- `this+0x000001C8` `void* bucket_ptr_2` (read_write, GUESS)
- `this+0x000001CC` `dword bucket_count_3` (write, GUESS)
- `this+0x000001D0` `void* bucket_ptr_3` (read_write, GUESS)

### AudioNetworkStreamManager

Audio network stream subsystem owner: sub-stream array (count +0x160, ptr +0x164), two tree lists (+0x100/+0x108), a texture list (+0x148), and flags (+0xEC); teardown performed by 0x00544AF0, also consuming the shared audio buffer and stream-handle globals.

Methods: `0x00544AF0`

- `this+0x000000EC` `dword owner_flags` (read_write, GUESS)
- `this+0x00000100` `void* tree_list_head` (read, GUESS)
- `this+0x00000108` `void* tree_list_second` (read, GUESS)
- `this+0x00000148` `void* texture_list_head` (read, GUESS)
- `this+0x00000160` `dword sub_stream_count` (read_write, GUESS)
- `this+0x00000164` `void* sub_stream_array` (read_write, GUESS)
- `this+0x000001EC` `void* tree_child_node_ptr` (read, GUESS)

### ResourceObject

196-byte resource object: control-channel state (+0x84..+0xC0), flags (+0x9C), config bound (+0xA4) and sentinel defaults (+0xA0 = -1, +0xAC = 65538, +0xB0 = 1.0); constructed by 0x00546250 and configured by the range-gated setter family 0x00546F30/0x00546F70/0x00547040/0x005470A0, each gated on a2 < this+0xA4 < 8.

Methods: `0x00546250`, `0x00546F30`, `0x00546F70`, `0x00547040`, `0x005470A0`

- `this+0x00000084` `dword field_zero_a` (write, GUESS)
- `this+0x00000088` `dword field_zero_b` (write, GUESS)
- `this+0x00000094` `dword field_zero_c` (write, GUESS)
- `this+0x00000098` `dword field_zero_d` (write, GUESS)
- `this+0x0000009C` `dword config_flags` (read_write, GUESS)
- `this+0x000000A0` `dword no_entry_sentinel` (write, GUESS)
- `this+0x000000A4` `dword config_bound` (read, GUESS)
- `this+0x000000A8` `dword field_zero_e` (write, GUESS)
- `this+0x000000AC` `dword packed_state_literal` (write, GUESS)
- `this+0x000000B0` `float default_scale` (write, GUESS)
- `this+0x000000B4` `dword field_zero_f` (write, GUESS)
- `this+0x000000B8` `dword field_zero_g` (write, GUESS)
- `this+0x000000BC` `dword field_zero_h` (write, GUESS)
- `this+0x000000C0` `dword field_zero_i` (write, GUESS)

### ResourceManager

Resource registry / linked-list manager: singly linked list rooted at +0x24 (node next at +0xC0, list base +0xE4), total count +0x10, and four flag-classified bucket counters +0x14..+0x20; node create/reuse (0x005474D0), append (0x00547670), refcounted remove (0x00547710), and list walks (0x005487A0, 0x005487E0).

Methods: `0x005474D0`, `0x00547670`, `0x00547710`, `0x005487A0`, `0x005487E0`

- `this+0x00000010` `dword total_count` (read_write, GUESS)
- `this+0x00000014` `dword bucket_counter_100` (read_write, GUESS)
- `this+0x00000018` `dword bucket_counter_none` (read_write, GUESS)
- `this+0x0000001C` `dword bucket_counter_20_100` (read_write, GUESS)
- `this+0x00000020` `dword bucket_counter_20` (read_write, GUESS)
- `this+0x00000024` `void* list_head` (read_write, GUESS)
- `this+0x000000E4` `void* list_node_base_ptr` (read, GUESS)
- `*(this+0xE4)+0x000000C0` `void* node_next` (read, GUESS)

### MeshResourceManager

Mesh/vertex-buffer resource loader (0x00547B40): stream-parses 196-byte resource entries (0x0054A5C0), configures them, deduplicates by name, and appends them to the resource list.

Methods: `0x00547B40`


### TextureResourceManager

Texture resource loader (0x00548190): stream-parses texture entries with 148-byte sub-resource arrays, random-name suffixing, dedupe, and per-sub-resource render-state dispatch on element field [24] tokens.

Methods: `0x00548190`


### SceneGraphNode

Scene-graph tree node with two child slots (+0x1B0 unconditional, +0x1B8 gated by +0x1AC), doubly linked; recursively destroyed by 0x00544EF0.

Methods: `0x00544EF0`

- `this+0x000001AC` `dword child2_guard` (read, GUESS)
- `this+0x000001B0` `void* child1` (read, GUESS)
- `this+0x000001B8` `void* child2` (read, GUESS)

### AudioNetworkNode

Audio network tree node: two child slots (a2[17], a2[19]) and a linked chain at a2[129] with next at offset 16; recursively walked by 0x00544D30. Node layout not evidenced as field refs.

Methods: `0x00544D30`


### SoundSource

3D sound-source object owned by an audio manager: sub-source slots a2[16]/a2[17]/a2[19] and an optional buffer resource at +0x230; destroyed by 0x00545150, which also nulls the entry in the manager registration array.

Methods: `0x00545150`


## Compatibility contracts

- **ResourceObjectConstructionAndConfiguration** — Constructing a 196-byte resource object must zero-initialize (0x0053C2A0) and memset the first 0x40 bytes, write sentinel defaults at +0x84..+0xC0 (float 294912.0625 at +0x9C, all-bits-set sentinel at +0xA0, 65538 at +0xAC, float 1.0 at +0xB0), and configure four control channels via IndexedFieldCopy/SwitchBasedFloatSetter; the range-gated setter family (0x00546F30/0x00546F70/0x00547040/0x005470A0) must only fire when the incoming argument is below the bound at +0xA4 and that bound is below 8, and must OR the appropriate flag into +0x9C.
- **ResourceListCounters** — The resource manager must keep its singly linked list rooted at +0x24 (node next at +0xC0), a total counter at +0x10, and four bucket counters at +0x14/+0x18/+0x1C/+0x20 selected by node flag bits 0x20/0x100; append (0x00547670) must walk to the tail and link, and removal (0x00547710) must decrement the reference count and only splice/free when it reaches 0, decrementing the same counters.
- **AudioNetworkTeardown** — Audio network teardown (0x00544AF0) must, when owner flags at +0xEC have bit 0x100000 set, destroy the sub-stream array (count +0x160, stride 96, 0x005502C0), unlink it (0x005478B0), free the shared audio buffer global 0x008B78A0 (0x00541420), clear the flag, destroy the stream-handle globals 0x008B8DBC/0x008B8DC0, and refuse finalization (return -1) while any active tree remains in the +0x100/+0x108 tree lists.
- **VertexBufferBucketRebuild** — Vertex-buffer resource allocation (0x00543FA0) must free and reallocate the 24-byte draw-element array (count +0x14C, ptr +0x150) and the four 528-byte bucket arrays (+0x1B8/+0x1C0/+0x1C8/+0x1D0) sized from counts mirrored at +0x44..+0x50/+0x1B4..+0x1CC, classify elements by flag bits 0x20/0x100 into buckets, and return -1 when any scene/audio walk fails.

## Unresolved

- Owner identity remains UNKNOWN for 0x00545F40, 0x00545F50 and 0x005461B0; they operate on module globals or a single +0x110 getter with no class evidence in the packet.
- Equal offsets on distinct this objects are kept in separate classes: +0xEC flags and +0x100/+0x108 list heads appear on both SceneGraphRenderResourceManager and AudioNetworkStreamManager, but common ownership is not proven, so they are not merged.
- Fields +0x124/+0x128/+0x12C/+0x130 and *(this+0x154)+0x4C and *(this+0x204)+0xEC/0x104 are listed in the packet for 0x00543FA0/0x00544AF0 but never referenced in the raw source; they are presumably consumed inside the cleanup/walk helpers (0x00544740, 0x00545A10, 0x00545A40, 0x00545BB0, 0x00548850) and cannot be mapped here.
- Global jpt_5445A4 (0x00544720, jump table at 0x00544720) is read per the packet but has no reference in the raw source; placement unknown. AudioVolumeLoadComputation globals flt_59E43C/59E7F8/59E8EC/59E990 are listed as reads but are absent from the decompiled source (likely folded/optimized).
- ResourceManager (0x005474D0/0x00547670/0x00547710/0x005487A0/0x005487E0) is a DERIVED merge based on identical +0x24 head / +0xC0 next / +0x10..+0x20 counter offsets and the packet's own resource-manager language; shared ownership is not CONFIRMED. Field evidence base "*(this+0xE4)+0xC0" disagrees with the source walk head at this[9]/+0x24; the +0xC0 next-pointer association is the shared fact.
- AudioNetworkNode and SoundSource node layouts (a2[16]/a2[17]/a2[19]/a2[140], chain next at offset 16, buffer resource at +0x230) are not evidenced as field refs in the packet and remain unresolved; the -1 early-return meaning ('active tree still in use') is inferred from branch structure, not externally confirmed.
- MeshResourceManager (named GUESS by the packet for 0x00547B40) and TextureResourceManager (proposed here for 0x00548190, whose owner is UNKNOWN in the packet) are separate loaders; a shared resource-manager base is possible but not evidenced.
- Semantics of the sentinel literals (float 294912.0625 at +0x9C, 65538 at +0xAC, -1 at +0xA0) and of flag bits 0x20/0x100/0x80/0x4/0x100000 across ResourceObject and the two managers are unknown.
- For 0x00547B40 the raw source text is truncated; EmptyStub_7470 (0x00557470) and FreeWrapper_7bcf (0x00587BCF) appear in the callee table with no visible call site, and global 0x008B8F30 (temp-file read buffer, DERIVED prelabel) is read without a visible use.
- sub_546450's match condition (drives 0x005487A0's -1 exit), sub_547670's link semantics, and the meaning of the 0x1000000/0x8000000 render-state constants are not resolvable from this packet.
