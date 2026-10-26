## LinkedListWalkWithInputDispatch_00585320 — LinkedListWalkAndDispatchOnMatch

**Summary:** Walks a linked list of nodes, calling a dispatch function (sub_5878A0) and setting a field to -1 for each node whose getter does not return -1. Iterates via a saved iterator pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57A730 (0057a730)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x11C | R | — | pointer to first linked list node (head) |
| this | 0x124 | RW | — | iterator pointer (advanced to next node each iteration) |
| this | 0x128 | R | — | unknown |
| this | 0x12C | R | — | unknown |

**Written-by note (persistence):**
- this 0x124: updated each iteration to point to next node; when NULL, loop exits

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587710 | FieldSetterAt0x410 | set field to -1 on matched nodes |
| 00587720 | StructFieldGetter_7720 | get field value from node for comparison |
| 005878a0 | sub_5878A0 | dispatch/callback with argument a2 |

**Guard conditions:** Head pointer (this+0x11C) must be non-NULL — BLOCKED (skip entire walk). Each iteration checks iterator pointer; NULL causes break.
