## LinkedListDestructionWithRefCountLoop_004bb4f0 — List destructor with refcount element cleanup

**Summary:** Walks linked list freeing nodes. For flagged nodes with data, iterates over refcounted 884-byte elements (calling EmptyStub per element), then frees the refcounted block, data pointer, and node. Zeroes all list fields.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestroyUIWidgetHierarchy (004b5a30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x0 | R | — | Refcount block first DWORD (refcount value) |
| *(obj+0x4) | 0x4 | R | — | Element within refcounted array (884-byte stride) |
| obj | 0x0 | R | — | Node data pointer (outer allocation) |
| obj | 0x8 | R | — | Node free-data flag (non-zero = process data) |
| this | 0x0 | RW | 0 | List head pointer (zeroed after) |
| this | 0x4 | RW | 0 | List tail pointer (zeroed after) |
| this | 0x8 | RW | 0 | List current pointer (zeroed after) |
| this | 0xC | RW | 0 | List node count (zeroed after) |

**Written-by note (persistence):**
- this 0x0-0xC: all zeroed after destruction; list becomes empty

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | Empty stub called per refcounted element |
| 00587bcf | FreeWrapper_7bcf | Memory deallocation (refcount block, data, node) |

**Guard conditions:** Node data freed only if node+0x8 flag is non-zero, data pointer non-null, and data[0] non-null. Refcounted elements processed only if refcount > 0.
