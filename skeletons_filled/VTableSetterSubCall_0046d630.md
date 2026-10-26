## VTableSetterSubCall_0046d630 — VTable setter with init call

**Summary:** Sets object vtable pointer to off_59FC08, then delegates to InitWithVTableCleanup for further initialization. Returns result of init call.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_d610 (0046d610)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | off_59FC08 | vtable pointer — set to off_59FC08 before init call |

**Written-by note (persistence):**
- this 0x0: once — written by this function, persists until object destroyed or vtable swapped

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059fc08 | off_59FC08 | R | vtable reference assigned to object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guards. Always sets vtable and calls InitWithVTableCleanup.
