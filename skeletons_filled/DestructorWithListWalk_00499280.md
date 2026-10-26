## DestructorWithListWalk_00499280 — Destructor with linked-list cleanup

**Summary:** Destructor: walks a linked list at this+0x44 calling virtual destructor on each node, frees two optional buffers at this+0x58/0x60, then chains to base destructor. Part of UI element destruction.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalDestructor_9260 (00499260)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x44)+0x0) | 0x0 | R | — | vtable of list node; virtual destructor dispatched at slot 0 |
| *(this+0x44) | 0x0 | R | — | first field of list node (vtable pointer) |
| this | 0x0 | RW | off_5ACA74 | vtable pointer — set to UIElementVTable before list walk |
| this | 0x44 | RW | — | linked list head; updated per iteration as nodes are freed |
| this | 0x58 | R | — | buffer pointer — conditionally freed if non-null |
| this | 0x60 | R | — | buffer pointer — conditionally freed if non-null |

**Written-by note (persistence):**
- this 0x0: written once in destructor; vtable set to UIElementVTable before teardown
- this 0x44: updated destructively during loop (replaced with next each iteration)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005aca74 | off_5ACA74 | R | UIElementVTable [DERIVED] — vtable assigned in destructor |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486320 | StructFieldAccessor | returns next linked list node (traversal link) |
| 00587bcf | FreeWrapper_7bcf | frees heap memory block |

**Guard conditions:** Two conditional free guards: block at this+0x58 freed only when non-null; block at this+0x60 freed only when non-null. Linked-list walk is unconditional (guard check is `v4` being non-null after StructFieldAccessor, which is a loop condition, not a skip guard).
