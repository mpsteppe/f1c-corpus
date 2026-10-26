## ShortComputation_a530_0046a530 — SeasonDatabaseCleanup

**Summary:** Cleanup/destructor for season database object. Sets vtable to off_59F938, conditionally frees sub-object at offset 0x174 if non-null, then chains to FunctionCallWrapper_9440.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_a510 (0046a510)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer |
| this | 0x174 | R | — | pointer to sub-object to free if non-null |

**Written-by note (persistence):**
- this 0x0: set to vtable once; overwrites previous value

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f938 | off_59F938 | R | vtable for this object type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | frees the sub-object at this[93] if non-null |

**Guard conditions:** this[93] (offset 0x174) checked against 0. PASSES if non-null → calls FreeWrapper_7bcf. BLOCKED if null → skips free.
