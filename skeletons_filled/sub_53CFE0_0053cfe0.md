## sub_53CFE0_0053cfe0 — ResourceCacheLookupOrAllocInit

**Summary:** Searches a resource registry linked list by filename (extension stripped). Returns existing entry if found. If not found, allocates 2164-byte entry, attempts registration; on registration success frees the object (return -1), on failure appends to list (return 0).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionNodeAllocator (00494de0), CockpitDashboardLEDGaugeSetup (0049ca00), sub_4D8AB0 (004d8ab0), sub_4F8D70 (004f8d70), SceneFileTopLevelParser (0055b200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output pointer for found/allocated registry entry |

**Written-by note (persistence):**
- this 0x0: conditional — written if a1 non-null and function succeeds; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8e20 | dword_8B8E20 | R | EntryRegistryHead [DERIVED] (also: ` â€” global linked list head (entry registry) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053d340 | LinkedListAppend_d340 | Appends allocated node to registry linked list |
| 005523e0 | HashTable | Initializes hash table data for new entry |
| 00552470 | sub_552470 | Registration/validation check for resource |
| 00557470 | EmptyStub_7470 | Empty stub (debug/logging hook) |
| 00587bcf | FreeWrapper_7bcf | Heap free wrapper |
| 00587c03 | OperatorNewNhMallocWrapper | Heap allocation wrapper for 2164-byte object |
| 00589901 | sub_589901 | String transformation before comparison |

**Guard conditions:** Strips file extension: checks strlen > 0 and scans for '.' character; if no '.' found, proceeds with full string. Checks list head (dword_8B8E20) non-null before traversal; each node's next pointer (offset 0x870) checked during walk. If registration call (sub_552470) returns non-zero (success), allocated object is freed and function returns -1.
