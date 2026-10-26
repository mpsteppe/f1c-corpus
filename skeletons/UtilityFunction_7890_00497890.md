## UtilityFunction_7890_00497890 — SearchNestedListAndProcessMatch

**Summary:** Searches outer-linked-list (head at this+0x4) with inner lists via FieldGetter_8e30. For each inner item matching `a2`: conditionally calls sub_4977E0 (if byte at 0x1574 set), appends outer node via DoublyLinkedListAppend_5a80, calls virtual method (vtable+0x2C), and calls SetterVirtualCall. Guards: field at 0x18 triggers ListIterationWithVTableDispatch before and LinkedListIterationVirtualCall after.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_492160 (00492160), LookupDispatch (00497940), sub_49A5D0 (0049a5d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x4)+0x0)+0x0) | 0x2C | R | — | Virtual method at vtable+0x2C called on outer node on match |
| *(*(this+0x4)+0x0) | 0x0 | R | — | Outer node's first field (item data pointer) |
| *(*(this+0xC)+0x4) | 0x0 | R | — | Next node's first field (item data pointer) |
| *(this+0x4) | 0x0 | R | — | Head node's first field |
| *(this+0xC) | 0x4 | R | — | Current node's next pointer (link offset 4) |
| this | 0x4 | R | — | Outer linked list head pointer |
| this | 0xC | RW | — | Current node pointer during traversal |
| this | 0x18 | R | — | Guard flag — triggers list iteration calls before and after |
| this | 0x1574 | R | — | Byte flag — when set enables sub_4977E0 call on match |

**Written-by note (persistence):**
- this 0xC: Written at entry and each iteration. External poke does not survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00495a80 | DoublyLinkedListAppend_5a80 | Appends outer node to another list on match |
| 004977e0 | sub_4977E0 | Configures state with mode params on match (gated by 0x1574) |
| 00498e30 | FieldGetter_8e30 | Retrieves inner list head from outer node |
| 00498f40 | SetterVirtualCall | Calls setter virtual on matched inner item |
| 00498f80 | LinkedListIterationVirtualCall | Post-traversal list iteration (if 0x18 set) |
| 00498fb0 | ListIterationWithVTableDispatch | Pre-traversal list iteration (if 0x18 set) |

**Guard conditions:** Field at this+0x18 triggers pre/post list calls if non-null. Head at this+0x4 must be non-null to enter traversal — null skips. First outer node's data must be non-null — null skips entire do-while. Inner list iterates via offset 0x48 next pointer; null breaks inner loop. Outer loop checks current pointer at this+0xC and next pointer for null before advancing — null breaks.
