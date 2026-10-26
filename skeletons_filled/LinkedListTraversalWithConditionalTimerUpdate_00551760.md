## LinkedListTraversalWithConditionalTimerUpdate_00551760 — LinkedListNodeTimedUpdateWalk

**Summary:** Walks linked list of animation/entity nodes starting at this+0x13C, calling TimerBasedStateUpdateWithCap on each node that has a non-null time cap pointer at offset +28.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneNodeStateUpdateWithTransform (005569f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x160) | 0x1C | R | — | Time cap structure pointer within node (checked at node+28 for non-null) |
| *(this+0x160) | 0x24 | R | — | Linked-list next pointer at node+36 (0x24) for traversal |
| this | 0x13C | R | — | Linked-list head pointer (this[79]) — start of iteration |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005514c0 | TimerBasedStateUpdateWithCap | Update node state with timer, cap at max duration, dispatch cascade or sub-init |

**Guard conditions:** 
- node+28 (offset 0x1C) == 0: skip that node (no time cap configured). PASS when non-null.
- i == 0 (end of list): loop terminates. PASS when non-null (continue iteration).
