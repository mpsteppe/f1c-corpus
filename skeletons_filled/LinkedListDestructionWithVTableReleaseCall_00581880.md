## LinkedListDestructionWithVTableReleaseCall_00581880 — Linked list destroy with vtable destructor on data

**Summary:** Destroys linked list: walks nodes calling first vtable entry (Release/Delete) on each node's data pointer with argument 1, then frees node wrapper via FreeWrapper_7bcf. Zeros all list structure fields after iteration. No handle close.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57BCE0 (0057bce0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x0)+0x0) | 0x0 | R | — | Vtable entry 0 (first destructor/release method) called on node's data |
| *(obj+0x0) | 0x0 | R | — | Node's data pointer (object whose vtable is dereferenced for destructor call) |
| *(obj+0x4) | 0x4 | R | — | Node next-link pointer used to walk the list |
| obj | 0x0 | R | — | Node data pointer (checked for null before vtable call) |
| obj | 0x8 | R | — | Byte flag: non-zero means vtable destructor should be invoked |
| this | 0x0 | RW | 0 | Linked list head pointer; zeroed after destruction |
| this | 0x4 | RW | 0 | Linked list tail pointer; zeroed after destruction |
| this | 0x8 | RW | 0 | Cursor/iterator pointer; zeroed after destruction |
| this | 0xC | RW | 0 | Element count; zeroed after destruction |

**Written-by note (persistence):**
- this 0x0: Zeroed at end of destruction. No longer valid after call.
- this 0x4: Zeroed at end of destruction. No longer valid after call.
- this 0x8: Zeroed at end of destruction. No longer valid after call.
- this 0xC: Zeroed at end of destruction. No longer valid after call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Free each node wrapper after vtable destructor call |

**Guard conditions:** For each node: checks byte at node+0x8 (destructor flag) AND data pointer at node+0x0 before calling vtable destructor. Both must be non-null/true to invoke the vtable release.
