## ReleaseSceneNode_005437e0 — SceneNodeRelease

**Summary:** Releases a scene graph node by calling sub_53CAF0 on the child pointer stored at this[68] (offset 0x110), then calls EmptyStub_0170.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MutexSemaphoreCleanup (005461b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x110 | R | — | child scene node pointer to release |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053caf0 | sub_53CAF0 | release/dereference a scene node or resource |
| 005????? | EmptyStub_0170 | stub function (likely debug or placeholder) |

**Guard conditions:** No explicit guard — unconditional release call on this[68].
