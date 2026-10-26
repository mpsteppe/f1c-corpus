## DualVirtualDispatchWrapper_0057a660 — DualSequentialVTableDispatch

**Summary:** Makes two sequential virtual method calls on the object pointed to by *this. Calls vtable entry at offset 0x74 (entry 29) with no extra arguments, then vtable entry at offset 0x9C (entry 39) with two zero arguments. Returns 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetCommSessionMessageDispatcher (0045d890), ShortComputation_3140 (00463140)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x74 | R | — | vtable entry at offset 0x74 (first virtual function) |
| *(obj+0x0) | 0x9C | R | — | vtable entry at offset 0x9C (second virtual function) |
| obj | 0x0 | R | — | vtable pointer of target object |
| this | 0x0 | R | — | pointer slot containing object pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none.
