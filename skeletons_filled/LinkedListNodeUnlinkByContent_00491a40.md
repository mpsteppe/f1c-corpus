## LinkedListNodeUnlinkByContent_00491a40 — UnlinkNodeByContentReparent

**Summary:** Reads reference node at struct offset 16, prepends its content to another list, then walks the list at offset 12 to find and unlink a matching node. Frees the unlinked node (and its value if flagged). Returns 1 on success.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_496E90 (00496e90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0xC)+0x4) | 0x0 | R | — | Value in second node of search list (node after head) |
| *(*(obj+0xC)+0x4) | 0x4 | R | — | Next pointer of second node in search list |
| *(*(obj+0xC)+0x4) | 0x8 | R | — | Flags byte of second node in search list |
| *(obj+0x10) | 0x0 | R | — | Value of node pointed to by tail pointer |
| *(obj+0xC) | 0x4 | RW | — | Next pointer of head node — written if unlinking by relinking predecessor |
| obj | 0xC | RW | — | List head pointer — written if unlinking first node |
| obj | 0x10 | RW | — | List tail pointer — written if unlinking last node |
| obj | 0x14 | RW | — | List current/tail marker — written if unlinking current node |
| obj | 0x18 | R | — | List node count (decremented on unlink) |
| this | 0x0 | R | — | Pointer to struct; *this has list at offset 12 and ref node at offset 16 |

**Written-by note (persistence):**
- *(obj+0xC) 0x4: written once during unlink if predecessor existed; persists until next mutation
- obj 0xC: written once if unlinking first node; persists until next mutation
- obj 0x10: written once if unlinking last node; persists until next mutation
- obj 0x14: written once if current marker was the unlinked node; persists until next mutation

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00490aa0 | LinkedListNodePrepend | Prepend the reference node's content to another list |
| 00587bcf | FreeWrapper_7bcf | Free unlinked node (and its value if flags byte is non-zero) |

**Guard conditions:** If reference node pointer at `*(*this + 16)` is null → return 0. If its value `**(*this + 16)` is null → return 0. Search list walk: if `*(*this + 12)` (head) is null → skip unlink, return 1. Walk exits with return 1 if matching node not found.
