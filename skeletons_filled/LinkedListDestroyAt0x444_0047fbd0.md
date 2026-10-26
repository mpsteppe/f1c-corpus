## LinkedListDestroyAt0x444_0047fbd0 — LinkedListDoublePtrDtor

**Summary:** Destructor for a linked list at offset 0x444: walks nodes, conditionally frees embedded double-indirect data (if node flag at +8 is set and inner pointer is non-null), frees each node, clears list fields, chains to LinkedListDestructor, and optionally frees self.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x444) | 0x0 | R | — | embedded data pointer inside a list node; freed if flag set |
| *(this+0x448) | 0x4 | R | — | next pointer inside a list node; traversed during iteration |
| this | 0x444 | RW | 0 | list head pointer; cleared after traversal |
| this | 0x448 | RW | 0 | list tail pointer or count; cleared after traversal |
| this | 0x44C | RW | 0 | list state field; cleared after traversal |
| this | 0x450 | RW | 0 | list state field; cleared after traversal |

**Written-by note (persistence):**
- this 0x444: cleared to 0 after list traversal (no dangling head pointer)
- this 0x448: cleared to 0 after list traversal
- this 0x44C: cleared to 0 after list traversal
- this 0x450: cleared to 0 after list traversal

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048ca50 | LinkedListDestructor | base linked list destructor |
| 00587bcf | FreeWrapper_7bcf | memory deallocation wrapper |

**Guard conditions:** If list head (this[273] at offset 0x444) is NULL, skip node traversal entirely. Node flag byte at offset +8 controls whether embedded data is freed (non-zero = free, zero = skip).
