## ConstructorWithVTableFixup_00598731 — IStreamVTableInit

**Summary:** Initializes an std::istream object by writing the vftable pointer at the location derived from the vtable offset (vtable[1]) and chains to the next constructor step. Part of C++ standard library stream object construction.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MemoryDeallocationWrapperWithOffsetHeader (00599298)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | vtable offset field: offset from this to vftable pointer slot (vtable[1]) |
| this | 0x0 | R | — | pointer to the virtual function table of the class |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b9ba4 | ??_7?$basic_istream@DU?$char_traits@D@std@@@std@@6B@ | R | IStreamVtablePtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional vtable write and chain call.
