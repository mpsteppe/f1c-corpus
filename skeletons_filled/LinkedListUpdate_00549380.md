## LinkedListUpdate_00549380 — Update linked list nodes with dictionary lookup results

**Summary:** Walks a linked list starting at this+0xF8, following next pointers at node+0x14. For each node, calls StringLookupInLinkedDictionary and stores the result at node+0x10. Part of audio engine initialization — resolves string names to dictionary IDs/pointers for each entry.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioEngineInitialization (00546010)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x10C) | 0x10 | RW | — | Dictionary lookup result stored per node |
| *(this+0x10C) | 0x14 | R | — | Next pointer in linked list (node linkage) |
| this | 0xF8 | R | — | Head of linked list of nodes to update |

**Written-by note (persistence):**
- *(this+0x10C) 0x10: written once per node during walk; overwritten each time the function runs (not persistent across calls)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054a2d0 | StringLookupInLinkedDictionary | Resolve string/name to dictionary entry; result stored in node |

**Guard conditions:** If `this[0xF8]` (head pointer) is null → loop body never executes, function is no-op. Non-null head PASSES: walk continues via node+0x14 next pointer until null. Each node must have null-terminated next pointer at offset 0x14.
