## ShortComputation_d5f0_0046d5f0 — Constructor with vtable assignment

**Summary:** Calls ConstructorWithByteParams(this, 0, 0) to initialize object, then sets object's vtable pointer to off_59FC08. Returns constructed object pointer. Object initializer with vtable binding.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | off_59FC08 | vtable pointer — set to off_59FC08 after base initialization |

**Written-by note (persistence):**
- this 0x0: once — written by this function, persists until object destroyed or vtable swapped

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059fc08 | off_59FC08 | R | vtable reference assigned to object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00487220 | ConstructorWithByteParams | base initializer: zeroes object fields with two byte parameters |

**Guard conditions:** No guards. Always executes ConstructorWithByteParams, sets vtable, returns this.
