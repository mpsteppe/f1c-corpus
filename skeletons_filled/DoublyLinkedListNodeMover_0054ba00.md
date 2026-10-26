## DoublyLinkedListNodeMover_0054ba00 — Doubly-linked list node move to tail

**Summary:** Unlinks node `a2` from its current doubly-linked list, optionally processes its subtree via TreeNodeAccumulator, then appends it to the tail of `this` list. Handles sublist merging when both source and destination have sublists.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitCrewMeshLoader (004a2010), LazyInitCallback (004e0d00), SceneNode (0055a910)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x90)+0x4C) | 0x4C | RW | — | Next pointer of list head's tail node (patched during unlink) |
| *(this+0x90) | 0x4C | R | — | Next pointer of list container (for head update check) |
| this | 0x44 | RW | — | List head/tail pointer (updated when appending) |
| this | 0x230 | R | — | Sublist container pointer (for sublist merge) |

**Written-by note (persistence):**
- *(*(this+0x90)+0x4C) 0x4C: recalc every frame — external poke does NOT persist
- this 0x44: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f28 | dword_8B8F28 | R | UIRootContextPtr [DERIVED] (also: ` — unknown context/state pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00544c50 | TreeNodeAccumulator | Recursive tree node traversal (called on a2 when a3 is non-zero) |
| 00560eb0 | AppendNodeToDoublyLinkedListTail | Appends a node's sublist to another list's tail |

**Guard conditions:** Null-checks on `a2[18]` (prev) and `a2[19]` (next) during unlink — null means end of list, skip pointer patching. If `a3` is 0 → skip TreeNodeAccumulator. If `this[17]` (list head) is null → set head = a2 instead of appending. If `a2[140]` or `this[140]` is null → skip sublist append.
