## VtableFixupWithDestructor_00598775 — OStreamVTableWriteAndChain

**Summary:** Writes the std::ostream vftable pointer into a stream object at the offset derived from the vtable metadata (vtable[1]), then chains to the next initialization/construction step. Part of C++ standard library stream object destruction/cleanup path.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestructorTrampoline (0059925d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | vtable offset: byte offset from this to the vftable pointer slot |
| this | 0x0 | R | — | pointer to the virtual function table |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b9bac | ??_7?$basic_ostream@DU?$char_traits@D@std@@@std@@6B@ | R | MSVC_ostream_vtable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional vtable write and chain call.
