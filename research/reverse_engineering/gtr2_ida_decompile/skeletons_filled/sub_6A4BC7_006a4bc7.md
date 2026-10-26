## sub_6A4BC7_006a4bc7 — BuildReverseOwnerLists

**Summary:** For each object in the a2 array (a3 entries) it first stamps the owner index (v4) onto each referenced element's +72 field, propagates the owner through parent links (+56), then for every object collects the distinct owner ids referenced by its elements, appends the object index to each owner via sub_6A4B6D, and stores the deduplicated id list (count +20, list pointer +24) into the object. Returns 0 on success, -2147024882 on allocation failure.

**Called by:** sub_6A6B86 (006a6b86)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | this[2]: count of entries in the this[5] array scanned by the parent-link propagation loop |
| this | 0x14 | R | — | this[5]: entry pointer array; entries carry +56 parent link, +72 owner id and the element list |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00681169 | sub_681169 | allocates the v13-dword buffer that receives the deduplicated owner list (null → -2147024882) |
| 006a4b6d | sub_6A4B6D | appends the current object index v25 to the dynamic array of owner object v15; negative result propagated |

**Guard conditions:** Null objects in the a2 array are skipped in both passes. a3 == 0 → return 0 immediately. In the propagation loop, entries with +56 == -1 are left untouched. In the collection loop: owner id +72 == -1 entries are ignored, duplicate ids are skipped (the m == v13 test only appends a newly seen id), and appending fails immediately (BLOCK, returns the code) if sub_6A4B6D returns negative. Allocation of the list buffer must succeed or the function BLOCKS with -2147024882. PASS: all a3 objects processed → return 0.
