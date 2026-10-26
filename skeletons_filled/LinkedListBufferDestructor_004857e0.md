## LinkedListBufferDestructor_004857e0 — LinkedListBufferDtor

**Summary:** Destructor for a linked list at offset 0xE8: walks nodes, conditionally frees embedded double-indirect data (if node flag at +12 set), frees each node, clears list fields, then calls InitWithVTableCleanup and optionally frees self.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xE8) | 0x0 | R | — | embedded data pointer inside a list node; freed if flag set |
| *(this+0xEC) | 0x4 | R | — | next pointer inside a list node; traversed during iteration |
| this | 0xE8 | RW | 0 | list head pointer; cleared after traversal |
| this | 0xEC | RW | 0 | list tail pointer or count; cleared after traversal |
| this | 0xF0 | RW | 0 | list state field; cleared after traversal |
| this | 0xF4 | RW | 0 | list state field; cleared after traversal |

**Written-by note (persistence):**
- this 0xE8: cleared to 0 after list traversal
- this 0xEC: cleared to 0 after list traversal
- this 0xF0: cleared to 0 after list traversal
- this 0xF4: cleared to 0 after list traversal

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00487250 | InitWithVTableCleanup | common destructor/cleanup dispatcher, resets vtable and frees sub-objects |
| 00587bcf | FreeWrapper_7bcf | memory deallocation wrapper |

**Guard conditions:** If list head (this[58] at offset 0xE8) is NULL, skip node traversal. Node flag byte at offset +12 controls whether embedded data is freed (non-zero = free double-indirect data and its inner pointer, zero = skip).
