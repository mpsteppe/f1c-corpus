## LinkedListDestroyCloseHandle_00581820 — Linked list destroy with handle close and data free

**Summary:** Destroys linked list: optionally closes handle at this+0x10 if flag at this+0x18 is set. Walks list from head freeing each node's data via FreeWrapper_7bcf when node's free-flag (node+0x8) is set and data pointer (node+0x0) is non-null. Frees all node wrappers. Zeros all list structure fields.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x4) | 0x4 | R | — | Node next-link pointer used to walk the list |
| obj | 0x0 | R | — | Data pointer stored in node; conditionally freed |
| obj | 0x8 | R | — | Byte flag: non-zero means data pointer should be freed |
| this | 0x0 | RW | 0 | Linked list head pointer; zeroed after destruction |
| this | 0x4 | RW | 0 | Linked list tail pointer; zeroed after destruction |
| this | 0x8 | RW | 0 | Cursor/iterator pointer; zeroed after destruction |
| this | 0xC | RW | 0 | Element count; zeroed after destruction |
| this | 0x10 | RW | 0 | Handle field; closed via CloseHandle then zeroed |
| this | 0x18 | R | — | Byte flag controlling whether handle at +0x10 is closed |

**Written-by note (persistence):**
- this 0x0: Zeroed at end of destruction. No longer valid after call.
- this 0x4: Zeroed at end of destruction. No longer valid after call.
- this 0x8: Zeroed at end of destruction. No longer valid after call.
- this 0xC: Zeroed at end of destruction. No longer valid after call.
- this 0x10: Zeroed after successful CloseHandle. Survives unchanged if no handle close.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a8 | CloseHandle | R | Close handle at this+0x10 if flag at this+0x18 is true |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Free node's data (conditionally) and node wrapper itself |

**Guard conditions:** Checks byte at this+0x18 (handle-close flag). If non-zero AND CloseHandle succeeds, handle at this+0x10 is zeroed. For each node: checks byte at node+0x8 (free-data flag) AND data pointer at node+0x0 before freeing data.
