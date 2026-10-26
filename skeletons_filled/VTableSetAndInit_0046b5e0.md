## VTableSetAndInit_0046b5e0 — VTableSetAndChainCleanup

**Summary:** Sets vtable to off_59FA98 and chains to FunctionCallWrapper_9440. Partial cleanup/destructor step called from parent destructor for the season database variant type.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestructorWithConditionalFree_b5c0 (0046b5c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_59FA98 |

**Written-by note (persistence):**
- this 0x0: set to vtable once; overwrites previous value

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059fa98 | off_59FA98 | R | VTable_59FA98 [DERIVED] — vtable for this variant |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional.
