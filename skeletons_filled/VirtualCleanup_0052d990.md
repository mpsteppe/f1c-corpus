## VirtualCleanup_0052d990 — VirtualObjectDestructorAndNull

**Summary:** Calls virtual destructor/deleter on an object through its vtable (first entry, called with arg 1 for operator delete), then zeroes the stored pointer. Guarded against null pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CameraViewStructInitializer (00405440), StructInitWithVTableDispatchAndZeroFill (00405630), ThreadedObjectCreatorWithSEH (0052d8d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x0 | R | — | vtable function pointer (virtual destructor) |
| obj | 0x0 | R | — | stored object pointer to destroy |
| this | 0x0 | RW | 0 | pointer slot cleared to NULL after destruction |

**Written-by note (persistence):**
- this 0x0: written to 0 after destroying object; external poke overwritten by NULL write

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** returns 0 immediately (no-op) if `*this` (stored object pointer) is NULL
