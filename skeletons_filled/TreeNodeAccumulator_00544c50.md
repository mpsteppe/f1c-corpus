## TreeNodeAccumulator_00544c50 — Recursive tree-node accumulation

**Summary:** Recursively traverses a tree (scene graph or actor hierarchy) starting at node `a2`, accumulating values from child-linked lists into counters at offsets 0x34, 0x38, 0x3C, and 0x64. Zeroes WORD fields, folds DWORD bits, and calls TwoCounterIncrements per child entry.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ActorNodeLinkedListAppend (00545250), DoublyLinkedListNodeMover (0054ba00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34 | RW | — | Child counter (incremented per child node processed) |
| this | 0x38 | RW | — | Accumulated value (sum of child field at v5[72]) |
| this | 0x3C | RW | — | Per-entry accumulator (sum of v5[71]+8 values across children, branch dependent) |
| this | 0x64 | R | — | Node visitation counter (incremented per tree node visited) |

**Written-by note (persistence):**
- this 0x34: recalc every frame — external poke does NOT persist
- this 0x38: recalc every frame — external poke does NOT persist
- this 0x3C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00544c50 | TreeNodeAccumulator | Recursive self-call to process child subtrees |
| 005473c0 | TwoCounterIncrements | Increments two counters based on child entry data |

**Guard conditions:** If `node+68` (first child pointer) is null, skips recursive descent for that subtree. Loop terminates when no more siblings at `node+76`. Child-linked list at `node+516` processed while non-null.
