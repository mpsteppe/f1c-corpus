## sub_4CB5E0_004cb5e0 — ArrayClearAll

**Summary:** Clears all elements from a flat pointer array by popping the last element in a loop, marking each as invalid (-1), and releasing its resource handle via sub_558B30. Decrements count to 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4CD8D0 (004cd8d0), ArraySearchByIDWithCleanup (004cf010), RepeatedCallLoop_f040 (004cf040)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x64 | RW | — | Element count in flat array; decremented per element until 0 |
| this | 0x68 | R | — | Array base pointer; last element read each iteration |

**Written-by note (persistence):**
- this 0x64: Set to 0 at end (all elements popped). Survives until new elements added.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00558b30 | sub_558B30 | Releases/deletes the resource handle associated with each array element |

**Guard conditions:** Checks count at this+0x64 > 0. Once count reaches 0, loop exits.
