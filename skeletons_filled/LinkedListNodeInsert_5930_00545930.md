## LinkedListNodeInsert_5930_00545930 — Allocate 56-byte node, link into scene/list with optional parent

**Summary:** Allocates and initializes a 56-byte node with parameter linking, appends it to either a child list under parent `a3` or the manager's main linked list (head at 0x15C). Increments node counter at 0x158.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitCrewMeshLoader (004a2010), PitCrewAnimationLoader (004a2a90), sub_4D0110 (004d0110), SceneNode (0055a910)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x190)+0x34) | 0x34 | RW | — | Next-node pointer at tail (written when appending to tail of list) |
| this | 0x158 | R | — | Node counter/allocator ID (passed to ObjectInitWithParameterLinking, incremented) |
| this | 0x15C | RW | — | Head of main linked list |
| this | 0x190 | R | — | Intermediate for tail-walk access (derived from head offset 0x15C + 0x34) |

**Written-by note (persistence):**
- *(*(this+0x190)+0x34) 0x34: Once — set to `v5` when appending to non-empty list tail
- this 0x15C: Once — set to `v5` when list was empty; unchanged otherwise

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00560ba0 | ObjectInitWithParameterLinking | Initialize object with parameter linking and allocator ID |
| 00587c03 | OperatorNewNhMallocWrapper | Heap allocation of 56-byte node block |

**Guard conditions:** Allocation null check: PASSES (ObjectInitWithParameterLinking) when non-null; BLOCKED (v5=0) when null. `this[87]` head null check: BLOCKED (set as head) when null; PASSES (append to tail) when non-null. Parent path: `a3` && `*(a3+560)` both non-null -> use child list; else use main list. Child list head `*(v7+44)` null: set as child head; existing children: walk tail and append.
