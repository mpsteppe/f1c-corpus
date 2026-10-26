## VtableSetSubCall_0046a970 — VTableSetAndChainCleanup

**Summary:** Sets vtable to off_59F9E8 and chains to FunctionCallWrapper_9440. Partial cleanup step called from parent destructor.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestructorWithConditionalFree_a950 (0046a950)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_59F9E8 |

**Written-by note (persistence):**
- this 0x0: set to vtable once; overwrites previous value

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f9e8 | off_59F9E8 | R | vtable for this object type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional.
