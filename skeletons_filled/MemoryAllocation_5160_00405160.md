## MemoryAllocation_5160_00405160 — ResourceBackedMemoryAllocation

**Summary:** Allocates/reallocates memory for a resource with mode-dependent sizing: looks up resource node for base size, falls back to linked-list search, then calls sub_58C724 with computed parameters.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404fe0 | OneTimeInitializationWithAtexitStyleRegistration | ensures static resource manager singleton is initialized |
| 00407e40 | ResourceNodeLookupByStringOrID | looks up resource node by string or numeric ID |
| 00407fb0 | LinkedListSearchByID | searches a linked-list for resource by ID |
| 00408050 | LinkedListNodeSearchByIDOperation | searches linked-list node for resource by ID with output parameters |
| 0058c724 | sub_58C724 | performs actual memory allocation with given parameters |

**Guard conditions:** Maps a3 mode parameter: 0->0, 1->1, 2->2 (v4). Mode 2 with a2 == 0 triggers specific allocation path using resource node size + offset. Mode 0 adds resource node size to a2. Mode 1 uses raw a2 as allocation size.
