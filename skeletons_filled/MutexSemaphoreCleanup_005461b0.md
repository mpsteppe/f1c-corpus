## MutexSemaphoreCleanup_005461b0 — Mutex/semaphore object cleanup with DirectX resource release

**Summary:** Cleans up a mutex/semaphore object: releases DirectX resources, unlinks from doubly linked list, releases scene node, frees memory, and clears global UI root context pointer. Aborts with -1 if DirectX cleanup fails.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ResourceCleanup (0048e890), VidMan_Post (004fac00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f28 | dword_8B8F28 | W | UI root context pointer (cleared to 0 on cleanup) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053c630 | DoublyLinkedListUnlink | Remove object from doubly linked list |
| 005437e0 | ReleaseSceneNode | Release scene node reference count |
| 00543bf0 | ResourceCleanupDestructionForDirectXObjects | Release DirectX resources held by object |
| 00587bcf | FreeWrapper_7bcf | Free heap memory |

**Guard conditions:** `ResourceCleanupDestructionForDirectXObjects` return: BLOCKED (return -1) when non-zero (cleanup failure); PASSES (continue unlinking, freeing, clearing global) when zero.
