## sub_4C5DE0_004c5de0 — Full filter properties structure cleanup

**Summary:** Calls resource list cleanup, then walks the linked list of filter property nodes freeing each node's data (with secondary pointer cleanup if flag set) and the node itself. Zeroes all list fields, then frees the base structure pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_47FB10 (0047fb10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0x4 | R | — | Secondary pointer in head node's filter data |
| this | 0x0 | R | — | Base structure pointer (freed at end if non-null) |
| this | 0x8 | RW | 0 | Head pointer of linked list; zeroed after cleanup |
| this | 0xC | RW | 0 | Tail pointer; zeroed |
| this | 0x10 | RW | 0 | Iterator/first-node pointer; zeroed |
| this | 0x14 | RW | 0 | Count of items; zeroed |

**Written-by note (persistence):**
- this 0x8: set to 0 unconditionally
- this 0xC: set to 0 unconditionally
- this 0x10: set to 0 unconditionally
- this 0x14: set to 0 unconditionally

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c62c0 | ResourceListCleanup_62c0 | Clean up inner resource list before freeing main list nodes |
| 00587bcf | FreeWrapper_7bcf | Free node data (filter property struct with optional secondary pointer) and node itself; also free base struct pointer |

**Guard conditions:** Iterates linked list until null. Frees `*this` if non-null at end. No early-return guards.
