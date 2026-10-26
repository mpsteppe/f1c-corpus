## ObjectRegistration_00499360 — Object registration into parent linked list

**Summary:** Appends an object (a2) to a linked list at this+0x44, updates a counter at this+0x54, and calls dispatch with coordinates. Part of UI/object hierarchy management.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DualFieldSetterProcessCall (00497590)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | coordinate X offset passed to dispatch |
| this | 0xC | R | — | coordinate Y offset passed to dispatch |
| this | 0x44 | RW | — | linked list head pointer; set to new object when list empty, else walked to tail |
| this | 0x54 | RW | — | registration counter; incremented on each insert |

**Written-by note (persistence):**
- this 0x44: written only when list was empty (first registration); otherwise list head unchanged
- this 0x54: incremented unconditionally each call; persists as child count

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486320 | StructFieldAccessor | returns next linked list node (traversal to find tail) |
| 00486330 | FieldSetterAt0x8c | sets field at offset 0x8c on tail node to link in new object |
| 004869e0 | MultiRegionOffsetAccumulationWithVTableDispatch | dispatches with parent offsets (position/region) |

**Guard conditions:** Branch on `this+0x44`: NULL (empty list) → set head to a2; non-NULL → walk to tail via StructFieldAccessor, append via FieldSetterAt0x8c, increment counter.
