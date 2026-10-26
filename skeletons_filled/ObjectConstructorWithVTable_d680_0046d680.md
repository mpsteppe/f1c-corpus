## ObjectConstructorWithVTable_d680_0046d680 — Object constructor with vtable assignment

**Summary:** Calls ConstructorWithByteParams(this, 0, 0) to zero-initialize object, then sets vtable pointer to off_59FCB8. Returns constructed object pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | off_59FCB8 | vtable pointer — set to off_59FCB8 after base initialization |

**Written-by note (persistence):**
- this 0x0: once — written by this function, persists until object destroyed or vtable swapped

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059fcb8 | off_59FCB8 | R | vtable reference assigned to object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00487220 | ConstructorWithByteParams | base initializer: zeroes object fields with two byte parameters |

**Guard conditions:** No guards. Always executes ConstructorWithByteParams, sets vtable, returns this.
