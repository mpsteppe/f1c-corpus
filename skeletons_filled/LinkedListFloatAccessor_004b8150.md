## LinkedListFloatAccessor_004b8150 — LinkedListFloatIndexAccessor

**Summary:** Returns the float value at a given index from a linked list, traversing nodes by walking next pointers. Returns -1.0f for out-of-bounds or null node.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Passthrough (004b9d90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x6C0) | 0x0 | R | — | float data at current list node |
| this | 0x6C0 | R | — | linked list head pointer |
| this | 0x6C8 | R | — | list tail/end pointer (unused in this function) |
| this | 0x6CC | R | — | list element count |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If index a2 < 0 or a2 >= this[435] (element count), returns -1.0f. If any node pointer in traversal is null, returns -1.0f.
