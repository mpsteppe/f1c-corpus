## AudioNodeIterator_00548dd0 — AudioNodeListIterator

**Summary:** Walks a linked list of nodes from this[0x170], calling SceneRenderTransform on each node with this as context and 0 as the third argument. Returns the last SceneRenderTransform result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_557120 (00557120)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x170 | R | — | Head pointer to linked list of audio/scene nodes |
| this | 0x1A0 | R | — | unknown |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00548c20 | SceneRenderTransform | SceneOrientationAndTransformUpdate — processes orientation, wheel forces, camera, and state traversal for each node |

**Guard conditions:** this[0x170] (head pointer) must be non-null for loop body to execute. Loop terminates when next pointer at i[6] (offset 0x18) is NULL. Each node's SceneRenderTransform result overwrites the previous iteration's result; only the last result is returned.
