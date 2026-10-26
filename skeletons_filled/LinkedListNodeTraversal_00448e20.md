## LinkedListNodeTraversal_00448e20 — Advance linked-list pointers through collision node slots

**Summary:** Advances up to 11 linked-list pointers stored at consecutive slots (starting at this+0x1C). Each slot's pointer is replaced by following a "next" link at offset 0x1C within the pointed-to object, walking each list forward one step.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DynamicsBVHNodeRecursiveTraversal (00448e50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x1C | R | — | "Next" link field within each linked-list node |
| this | 0x0 | RW | — | Base of pointer array being walked (result = this, then advances through slots) |
| this | 0x18 | R | — | Count of linked-list pointers to advance (clamped to max 11) |

**Written-by note (persistence):**
- this 0x0: Not written — pointer arithmetic on local copy only; the actual pointer slots at this+0x1C+ are overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** this[0x18] == 0 → skip entire traversal. If this[0x18] > 0xB, clamp to 11.
