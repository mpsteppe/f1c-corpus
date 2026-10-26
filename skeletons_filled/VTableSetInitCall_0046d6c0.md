## VTableSetInitCall_0046d6c0 — VTable set with init call

**Summary:** Sets object vtable pointer to off_59FCB8, then delegates to InitWithVTableCleanup for further initialization. Returns result of init call.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SubCallConditionalFree (0046d6a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | off_59FCB8 | vtable pointer — set to off_59FCB8 before init call |

**Written-by note (persistence):**
- this 0x0: once — written by this function, persists until object destroyed or vtable swapped

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059fcb8 | off_59FCB8 | R | vtable reference assigned to object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guards. Always sets vtable and calls InitWithVTableCleanup.
