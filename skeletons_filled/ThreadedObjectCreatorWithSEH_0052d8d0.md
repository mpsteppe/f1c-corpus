## ThreadedObjectCreatorWithSEH_0052d8d0 — RenderObjectCreatorWithCleanup

**Summary:** Allocates and constructs a RenderObject (11584 bytes) via operator new, calls constructor, then initializes via vtable dispatch (offset +4). On failure frees object via VirtualCleanup. Skips if pointer already non-null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** BinaryDataDeserialization (004054e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | output pointer to created RenderObject |

**Written-by note (persistence):**
- this 0x0: written once after construction if slot was NULL; external poke overwrites created pointer

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059c73b | SEH_52D8D0 | R | SEH handler registration for exception safety |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0052d990 | VirtualCleanup | destroy object via vtable and null pointer |
| 0052e170 | RenderObjectConstructor_e170 | construct RenderObject at allocated memory |
| 00587c03 | OperatorNewNhMallocWrapper | allocate 11584-byte heap block |

**Guard conditions:** skips allocation/construction if `*this` (pointer slot) is already non-NULL; returns 0 if allocation or init (vtable+4) fails
