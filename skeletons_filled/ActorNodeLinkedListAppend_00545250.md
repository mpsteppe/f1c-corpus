## ActorNodeLinkedListAppend_00545250 — Append actor node to scene tree linked list

**Summary:** Appends an actor node (`a2`) to a singly-linked list managed by `this`. Sets bit 3 at node offset 0x3C, clears forward link, registers with tree accumulator, then either appends to tail (non-empty list) or sets as new head (empty list).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitCrewMeshLoader (004a2010), PitCrewAnimationLoader (004a2a90), sub_4D0110 (004d0110), SceneNode (0055a910)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x154)+0x4C) | 0x4C | RW | — | Next-node pointer in linked list (forward link, written when appending to tail) |
| this | 0x108 | RW | — | Head pointer of linked list (first node) |
| this | 0x154 | R | — | Pointer to scene tree root used by TreeNodeAccumulator |

**Written-by note (persistence):**
- *(*(this+0x154)+0x4C) 0x4C: Once — set to new node `a2` when list was non-empty (append to tail of existing list)
- this 0x108: Once — set to `a2` when list was empty (first node); unchanged if list already had nodes

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00544c50 | TreeNodeAccumulator | Register/adopt node into scene tree accumulator hierarchy |

**Guard conditions:** No guard — unconditional append. Empty list vs non-empty list handled via `this[66]` (head) null check.
