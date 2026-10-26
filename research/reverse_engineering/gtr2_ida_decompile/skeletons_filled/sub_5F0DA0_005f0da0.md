## sub_5F0DA0_005f0da0 — Refcounted release for cached resource

**Summary:** Decrements the refcount at object+0x18B8; when it drops to zero (pre-decrement value 1) it tears the object down via sub_5F0BF0 and removes it from the global cache list dword_FB287C via sub_5F06E0 with delete flag 1, returning that removal result. Companion to the get-or-load path (sub_5F0C30).

**Called by:** sub_4E2110 (004e2110), sub_4E5B70 (004e5b70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18B8 | R | — | Refcount of the cached resource object; decremented, and destruction runs when it reaches zero |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00fb287c | dword_FB287C | R | Global cache list anchor — passed to sub_5F06E0 to remove the object's node from the resource registry |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005f06e0 | sub_5F06E0 | Linked-list node remover — called with (&dword_FB287C, object, 1) to unlink the object from the cache and free its node (and payload, per the node's owned flag) |
| 005f0bf0 | sub_5F0BF0 | Object teardown dispatcher — runs the mode-dependent cleanup and the resource release helper before removal |

**Guard conditions:** `if (a1)`: a null object pointer skips everything (BLOCKED). `(*(a1 + 6328))-- == 1`: the decrement result is tested — only when the pre-decrement refcount was 1 (new value 0) do the teardown and cache removal run (PASS); while the old count is greater than 1 the function returns without further action. When it runs, sub_5F0BF0(object) performs the teardown and sub_5F06E0(&dword_FB287C, object, 1) supplies the return value (1 if the node was removed, 0 if not found in the list).
