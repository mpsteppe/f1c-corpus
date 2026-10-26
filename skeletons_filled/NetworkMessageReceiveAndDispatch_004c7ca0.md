## NetworkMessageReceiveAndDispatch_004c7ca0 — Network message receive and dispatch to list

**Summary:** Receives and dispatches network messages from audio network nodes. Iterates over connected nodes, checks render flags, allocates message entries, and builds a linked list of pending messages on this object's list head at +0xC. Uses vtable dispatch for message processing.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | — | linked list head pointer for pending messages (node list) |
| this | 0x10 | RW | — | linked list tail pointer for pending messages |
| this | 0x14 | RW | — | linked list cursor/current pointer |
| this | 0x18 | R | — | linked list item count |

**Written-by note (persistence):**
- this 0xC: set to newly allocated list head; persists as message queue head
- this 0x10: updated as list tail; persists
- this 0x14: updated as current pointer; persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008acfcc | dword_8ACFCC | R | ComparisonValue (sentinel) [DERIVED] |
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c8f80 | VTableDispatchWithNegation | dispatch message via vtable call with negation check |
| 004c9a50 | MemoryAllocation_9a50 | allocate memory for message vtable entry |
| 005452f0 | AudioNetworkNodeCount | get total number of audio network nodes |
| 00545340 | LinkedListNodeFinder | find linked list node by index |
| 0054c110 | RenderFlagSetter | set render flag (value 7, mask 4096) |
| 0054c150 | FlagPropertyGetter | get flag property from network node |
| 00587c03 | OperatorNewNhMallocWrapper | allocate memory for message list entry (16 bytes) |

**Guard conditions:** Guard: dword_8ACFCC must be non-zero to set render flags. dword_8AFE88 must be non-zero to process nodes. Each node must pass FlagPropertyGetter check (v8[0] non-zero). If vtable dispatch succeeds (returns non-zero), skip message list allocation and jump to error handling (LABEL_22).
