## ResourceCleanupDestructionForDirectXObjects_00543bf0 — RenderResourceDestructor

**Summary:** Destroys and deallocates all DirectX and render-related resources, walking linked lists and arrays to call per-element destructors (scene graph nodes, 3D sound sources, mesh/compositor arrays, and various render object pools). Zeros out pointers after destruction to prevent dangling references.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MutexSemaphoreCleanup (005461b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal -> value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x148) | 0x2C | R | — | Scene graph node child-list next pointer: walks linked list of child scene nodes before destroying parent |
| *(this+0x154) | 0x48 | R | — | Render-object child-list next pointer: walks linked list at object+0x104 before destroying parent |
| *(this+0x18C) | 0x68 | R | — | Sound source child-list next pointer: walks linked list at element+0x4C before destroying parent |
| *(this+0x194) | 0x68 | R | — | Resource array element next pointer: walks linked list at element+0x6C for per-element cleanup |
| *(this+0x19C) | 0x68 | R | — | Second resource array element next pointer: same linked-list walk pattern |
| *(this+0x204) | 0x100 | R | — | Third resource array element next pointer: walks linked list at element+0x6C |
| *(this+0x2B0) | 0x1B4 | R | — | Compositor/mesh linked-list node next pointer: walks at node+0x30 before destroying parent |
| this | 0xF8 | RW | 0 | SceneGraphRoot: pointer to scene graph tree root; fully destroyed node-by-node then zeroed |
| this | 0x100 | RW | 0 | RenderObjectListHead: pointer to render object list; destroyed via DestroyFree then zeroed |
| this | 0x108 | RW | 0 | SoundSourceListHead: pointer to 3D sound source list; destroyed then zeroed |
| this | 0x110 | R | — | AudioNetworkStreamHandle: checked for cleanup via AudioNetworkStreamCleanup |
| this | 0x118 | RW | 0 | ResourceArray1Head: pointer to first resource array; element-by-element cleanup then zeroed |
| this | 0x120 | RW | 0 | ResourceArray2Head: pointer to second resource array; element-by-element cleanup then zeroed |
| this | 0x128 | RW | 0 | ResourceArray3Head: pointer to third resource array; element-by-element cleanup then zeroed |
| this | 0x130 | RW | 0 | Array528_1Head: pointer to array of 528-byte elements; each destroyed via CleanupFunction then array freed |
| this | 0x138 | R | — | Array528_2Head: pointer to second 528-byte array; same cleanup pattern |
| this | 0x140 | R | — | Array528_3Head: pointer to third 528-byte array; same cleanup pattern |
| this | 0x148 | R | — | Array528_4Head: pointer to fourth 528-byte array; same cleanup pattern |
| this | 0x150 | R | — | Array56Head: pointer to array of 56-byte elements; each destroyed via EmptyStub then array freed |
| this | 0x154 | R | — | Array24_1Head: pointer to array of 24-byte (triple-stride) elements; destroyed via EmptyStub then freed |
| this | 0x178 | R | — | ConditionalFreeFlag: checked by ConditionalFreeOfStructField at this[107] for selective cleanup |
| this | 0x18C | R | — | Array24_2Head: pointer to second 24-byte triple-stride array; destroyed via EmptyStub then freed |
| this | 0x194 | R | — | Array24_3Head: pointer to third 24-byte triple-stride array; destroyed via EmptyStub then freed |
| this | 0x19C | R | — | LinkedList70Head: pointer to linked list at this[70]; each node destroyed via DoublyLinkedListNodeRemoval then zeroed |
| this | 0x1AC | R | — | RenderResourceFlag: read from dword_8B8F2C; triggers sub_5593D0 if non-zero |
| this | 0x1B8 | R | — | Cleanup context: read during linked-list traversal for array size bounds |
| this | 0x1C0 | R | — | Array count context: read during 528-byte array iteration (element count from array header) |
| this | 0x1C8 | R | — | Array count context: read during 56-byte array iteration |
| this | 0x1D0 | R | — | Array count context: read during 24-byte array iteration |
| this | 0x204 | R | — | Compositor tree root: read during DoublyLinkedListNodeRemoval cleanup |
| this | 0x2B0 | R | — | Final cleanup context: read during last linked-list walk |

**Written-by note (persistence):**
- this 0xF8: zeroed after destruction; overwritten on next cleanup call
- this 0x100: zeroed after destruction; overwritten on next cleanup call
- this 0x108: zeroed after destruction; overwritten on next cleanup call
- this 0x118: zeroed after destruction; overwritten on next cleanup call
- this 0x120: zeroed after destruction; overwritten on next cleanup call
- this 0x128: zeroed after destruction; overwritten on next cleanup call
- this 0x130: freed (pointer invalidated); overwritten on next cleanup call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f2c | dword_8B8F2C | R | RenderResourceHandle2 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | Empty/no-op stub called during array element destruction (placeholder or null destructor for simple types) |
| 00544af0 | AudioNetworkStreamCleanup | Cleans up and releases audio network stream resources |
| 00544ef0 | SceneGraphTreeDestructor | Recursively destroys a scene graph tree node and all its children |
| 00545150 | F_3DSoundSourceDestructor | Destroys a 3D sound source object and releases its audio resources |
| 005454a0 | sub_5454A0 | Destroys a single resource array element (called per element before list head destruction) |
| 005487e0 | LinkedListWalkWithExitCheck | Walks a linked list with an exit condition check; returns non-zero to abort cleanup early |
| 0054a240 | DestroyFree | Destroys an object and frees its memory (used for render object list elements) |
| 005519e0 | DoublyLinkedListNodeRemoval_19e0 | Removes a node from a doubly-linked list and destroys its associated compositor data |
| 00557280 | CleanupFunction | Performs full cleanup/destruction on a 528-byte array element (compositor or mesh data) |
| 005593d0 | sub_5593D0 | Releases a global render resource identified by dword_8B8F2C |
| 00560b30 | ConditionalFreeOfStructField | Conditionally frees a struct field based on a flag check at this[107] |
| 00587bcf | FreeWrapper_7bcf | Frees a heap-allocated memory block (array base pointer, after all elements destroyed) |

**Guard conditions:** Null-pointer guards on every resource pointer: each block (scene graph, render objects, sound sources, arrays at [62], [64], [66], [72], [74], [76], [110], [112], [114], [116], [78], [84], [80], [94], [70]) is only processed if its pointer is non-null. LinkedListWalkWithExitCheck at this[68] may return -1 to abort the entire cleanup sequence early. ConditionalFreeOfStructField at this[107] performs cleanup only if an internal flag is set. The dword_8B8F2C global is checked for non-zero before calling sub_5593D0. All destroyed pointer fields are zeroed after cleanup to prevent double-free on subsequent calls.</content>
