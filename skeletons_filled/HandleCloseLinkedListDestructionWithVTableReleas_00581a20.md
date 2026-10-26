## HandleCloseLinkedListDestructionWithVTableReleas_00581a20 — List destroy with handle close and vtable entry 1 destructor

**Summary:** Destroys linked list: optionally closes handle at this+0x10 if flag at this+0x18 is set. Walks list calling vtable entry 1 (offset +4, second destructor) on each node's data with argument 1 when node's flag is set. Frees all node wrappers via FreeWrapper_7bcf. Zeros all list structure fields.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x0)+0x0) | 0x4 | R | — | Vtable entry 1 (second destructor, offset +4) called on node's data object |
| *(obj+0x0) | 0x0 | R | — | Node's data pointer (object whose vtable is dereferenced) |
| *(obj+0x4) | 0x4 | R | — | Node next-link pointer; used to walk the list |
| obj | 0x0 | R | — | Node data pointer (checked for null before vtable call) |
| obj | 0x8 | R | — | Byte flag: non-zero means vtable destructor should be invoked |
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
| 00587bcf | FreeWrapper_7bcf | Free each node wrapper after vtable destructor call |

**Guard conditions:** Checks byte at this+0x18 (handle-close flag). If non-zero AND CloseHandle succeeds, handle at this+0x10 is zeroed. For each node: checks byte at node+0x8 (destructor flag) AND data pointer at node+0x0 before calling vtable entry 1 destructor.
