## UIListNodeManager_0054bb40 — Create and append UI list node from template

**Summary:** Creates a new UI list node (40 bytes) from source template, initializes via sub_5510F0, and appends to linked list (head at this+0x214, next at node+0x24). Walks to tail if non-empty; sets head on first node. Configures item count (v8[5]), initializes sequential indices in item array (v8[6]), registers via EntityFlagSetSubInitChain, stores source pointer (v8[7]), and conditionally calls sub_559200. Part of UI scene node setup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneNode (0055a910)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x238)+0x24) | 0x24 | RW | — | Tail node's next pointer; linked to new UI list node |
| this | 0x214 | RW | 0 | Head of UI list node linked list |
| this | 0x218 | R | — | Counter/flag checked to conditionally call sub_559200 |
| this | 0x238 | R | — | Pointer to sub-structure containing list state |

**Written-by note (persistence):**
- *(*(this+0x238)+0x24) 0x24: written once per node creation when list is non-empty (old tail's next set to new node)
- this 0x214: written once on first node creation (set to new node); unchanged on subsequent appends

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f28 | dword_8B8F28 | R | UIRootContextPtr [DERIVED] — unknown context/state pointer used by callees |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | Stub called after UI list node setup |
| 005510f0 | sub_5510F0 | Initialize new UI list node from source template data |
| 00551440 | EntityFlagSetSubInitChain | Register/list node in entity flag initialization chain |
| 00557350 | sub_557350 | Query/collect rendering state into temp buffer v13 |
| 00559200 | sub_559200 | Initialize/configure rendering state for the list |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate 40 bytes for new UI list node |

**Guard conditions:** If `this[0x214]` (head) is null → allocate and set head. If non-null → walk to tail via node+0x24 next pointers. Allocation failure (OperatorNewNhMallocWrapper returns null) BLOCKS initialization — head set to 0. Node's item count (v8[5]) > 0 controls item array initialization loop. Conditional sub_559200 call BLOCKED if `this[0x218]` is non-null.
