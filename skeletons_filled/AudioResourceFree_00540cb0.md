## AudioResourceFree_00540cb0 — Audio resource conditional free

**Summary:** Frees audio sub-resources (buffers at a2+28 and a2+36) based on state flag at this+0x13DC. If flag set → direct FreeWrapper_7bcf. If clear → ObjectResetWithVirtualRelease + DrainingLoopFinalizer for proper teardown.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** QueueResourceCleanup (0054c410), SceneNodeChildrenClear (0054d030), sub_5574B0 (005574b0), sub_557670 (00557670)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x13DC | R | — | state flag — selects direct vs virtual release path |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00540eb0 | ObjectResetWithVirtualRelease | proper virtual release for audio object |
| 00541040 | DrainingLoopFinalizer | drains/finalizes audio resource list |
| 00587bcf | FreeWrapper_7bcf | frees allocated memory |

**Guard conditions:** this+0x13DC != 0 → direct free path (FreeWrapper_7bcf on both buffers, zeros pointers). If 0 → uses ObjectResetWithVirtualRelease + DrainingLoopFinalizer then FreeWrapper_7bcf.
