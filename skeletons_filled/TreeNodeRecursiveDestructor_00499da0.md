## TreeNodeRecursiveDestructor_00499da0 — TreeNodeRecursiveDestructor

**Summary:** Destructs a tree node by recursively processing children and freeing the node. If `a2` is NULL, reads the node pointer from `this+2` (offset 0x08). If the node pointer is non-NULL, recursively destructs its children at offsets 0x24 and 0x28, calls ConditionalDualCleanup on the node, then frees it. Finally clears the node pointer slot and sets `this[3]` to 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestructorWithMultipleConditionalFrees (00499ce0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 0 | pointer to node; read for destruction, written to 0 after |
| this | 0xC | RW | 0 | counter/flag cleared to 0 on completion |

**Written-by note (persistence):**
- this 0x8: cleared to 0 after node freed; external poke survives
- this 0xC: cleared to 0; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00499b50 | ConditionalDualCleanup | clean up two resources in the freed node |
| 00499da0 | TreeNodeRecursiveDestructor | recursive call on child nodes (at v4+10, v4+9) |
| 00587bcf | FreeWrapper_7bcf | free the node memory |

**Guard conditions:** a2 (second param) checked NULL — if NULL, uses address of this+2 as pointer source. *v2 (node pointer) checked non-NULL — if non-NULL, recursively destroys children, cleans up, and frees node. If NULL, skips destruction and only clears fields. Both `this[2]` and `this[3]` cleared unconditionally after.
