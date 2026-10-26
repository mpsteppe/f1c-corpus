## ObjectSearchWithDoubleIteration_00495980 — ObjectSearchTwoPass

**Summary:** Two-pass object search: iterates a primary list (from SimpleFieldGetter), calling a virtual match function (vtable slot 12) against criteria at offsets 0x5C and 0x60. If no match found, falls back to a secondary list (from sub_498E40 + offset 68). Returns first matching object or NULL. Part of the UI/widget object lookup system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UILargeRender (00496930), sub_4973D0 (004973d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5C | R | — | First search criterion/parameter (passed to virtual match function) |
| this | 0x60 | R | — | Second search criterion/parameter (passed to virtual match function) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486320 | StructFieldAccessor | Get next element in linked list (sibling/next pointer) for iteration |
| 00495970 | SimpleFieldGetter | Retrieve primary list/collection root pointer from this |
| 00498e40 | sub_498E40 | Retrieve secondary container from the primary list — provides fallback search list |
| 00498f60 | ShortComputation_8f60 | Get first element of the primary iteration list |

**Guard conditions:** SimpleFieldGetter returns NULL → return 0 immediately (BLOCKED). Virtual match returns non-zero → accept as found (PASS). Second-pass only runs if primary pass found no match AND sub_498E40 returns non-NULL.
